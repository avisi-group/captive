/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/reverse-allocator.h>
#include <dbt/mc/x86/formatter.h>
#include <dbt/util/list.h>

//#define PDEBUG
#define VERIFY
#define SUPPORT_VOLATILE
#define CLEVER_ALLOCATION_STRATEGY

using namespace captive::arch::dbt::mc::x86;
using namespace captive::arch::dbt::util;

#define MAX_PHYS_REGISTERS 24

template<typename UnderlyingType = dbt_u64, int NrBits = sizeof(UnderlyingType) * 8 >
struct BitSet {
	static_assert(NrBits <= sizeof(UnderlyingType) * 8, "NrBits does not fit within underlying data type");

	typedef BitSet<UnderlyingType, NrBits> Self;

	typedef int IndexType;

	BitSet() : state(0)
	{
	}

	BitSet(const BitSet& _o) : state(_o.state)
	{
	}

	inline operator UnderlyingType() const
	{
		return state;
	}

	inline void wipe()
	{
		state = 0;
	}

	inline void set(IndexType i)
	{
		state |= ((UnderlyingType) 1u << i);
	}

	inline void clear(IndexType i)
	{
		state &= ~((UnderlyingType) 1u << i);
	}

	inline bool is_set(IndexType i) const
	{
		return !!(state & ((UnderlyingType) 1u << i));
	}

	inline bool is_clear(IndexType i) const
	{
		return !(state & ((UnderlyingType) 1u << i));
	}

	inline IndexType find_first_set() const
	{
		if (state == 0) return -1;
		return __builtin_ffsll(state) - 1;
	}

	inline IndexType find_first_clear() const
	{
		if (~state == 0) return -1;
		return __builtin_ffsll(~state) - 1;
	}

	inline IndexType find_first_set_via_mask(UnderlyingType mask) const
	{
		if (state & mask == 0) return -1;
		return __builtin_ffsll(state & mask) - 1;
	}

	inline IndexType find_first_clear_via_mask(UnderlyingType mask) const
	{
		if (((~state) & mask) == 0) return -1;
		return __builtin_ffsll((~state) & mask) - 1;
	}

	friend Self operator|(const Self& lhs, const Self& rhs)
	{
		Self r;
		r.state = lhs.state | rhs.state;

		return r;
	}

	void operator|=(const Self& other)
	{
		state |= other.state;
	}

private:
	UnderlyingType state;
};

struct VirtualRegister {
	Instruction *first_def, *last_use;
	dbt_u64 physical_register_index;
	BitSet<> interference;
	int last_control_flow_count;
};

bool ReverseAllocator::allocate(Instruction* head)
{
	const X86PhysicalRegister& invalid_reg = X86PhysicalRegisters::RIZ;

	if (!number_and_legalise_instructions(head)) return false;

	// Allocate the dense vreg map.
	dbt_u64 nr_vregs = _vreg_allocator.next_index();

	if (nr_vregs > 20000) {
		_support.debug_printf("there are too many vregs: %lu\n", nr_vregs);
		_support.assertion_fail("too many vregs");
		return false;
	}

	VirtualRegister *vregs = (VirtualRegister *) _support.alloc(sizeof(VirtualRegister) * nr_vregs, AllocClass::DATA);
	if (!vregs) return false;

	// Initialise the vreg map.
	for (unsigned int i = 0; i < nr_vregs; i++) {
		vregs[i].first_def = nullptr;
		vregs[i].last_use = nullptr;
		vregs[i].physical_register_index = invalid_reg.unique_index();
		vregs[i].last_control_flow_count = 0;
	}

	// Calculate VREG live ranges
	if (!calculate_vreg_live_ranges(vregs, head)) {
		_support.free(vregs, AllocClass::DATA);
		return false;
	}

	// Make fake uses for volatile memory accesses
#ifdef SUPPORT_VOLATILE
	for (unsigned int i = 0; i < nr_vregs; i++) {
		if (vregs[i].first_def != nullptr && vregs[i].last_use == nullptr) {
#ifdef PDEBUG
			_support.debug_printf("dead live range for vreg %lu\n", i);
#endif

			Instruction *insn = vregs[i].first_def;
			if (insn->is_volatile()) {
#ifdef PDEBUG
				_support.debug_printf("volatile instruction, so creating fake use for vreg %lu\n", i);
				Formatter __fmt;
				_support.debug_printf("[%u] %s\n", insn->nr, __fmt.format_instruction(insn));
#endif

				if (insn->kind() != InstructionKind::MOV) {
					_support.assertion_fail("fake use: not a mov");
				}

				auto vreg_operand = insn->get_operand(1);
				if (!vreg_operand.is_reg() || !vreg_operand.reg.reg.is_virtual()) {
					_support.assertion_fail("fake use: not a vreg operand");
				}

				insn->set_operand(1, Operand::make_register(X86PhysicalRegisters::R14, vreg_operand.reg.width));
			}
		}
	}
#endif

	// Perform allocation
	if (!do_allocate(vregs, head)) {
		_support.free(vregs, AllocClass::DATA);
		return false;
	}

	if (!commit(head, vregs)) {
		_support.free(vregs, AllocClass::DATA);
		return false;
	}

#ifdef VERIFY
	if (!verify(head)) {
		_support.free(vregs, AllocClass::DATA);
		return false;
	}
#endif

	if (!fixup_calls(head)) {
		_support.free(vregs, AllocClass::DATA);
	}

	_support.free(vregs, AllocClass::DATA);
	return true;
}

bool ReverseAllocator::calculate_vreg_live_ranges(VirtualRegister *vregs, Instruction *head)
{
#ifdef PDEBUG
	VirtualRegister *last_vreg = nullptr;
#endif

	int cur_control_flow_count = 0;

	Instruction *current = head;
	do {
		if (current->is_control_flow()) {
			cur_control_flow_count++;
		}

		Instruction::UseDefList usedeflist;
		current->get_usedefs(usedeflist);

		for (unsigned int use_def_index = 0; use_def_index < usedeflist.next; use_def_index++) {
			const auto& usedef = usedeflist.get(use_def_index);
			if (!usedef.is_valid()) continue; // Skip invalid usedefs
			if (!usedef.is_def()) continue; // Skip non-def usedefs
			if (!usedef.reg.is_virtual()) continue; // Skip non-virtual registers

			VirtualRegister *vreg = &vregs[usedef.reg.unique_index()];
#ifdef PDEBUG
			if (vreg > last_vreg) {
				last_vreg = vreg;
			}
#endif

			if (vreg->first_def == nullptr) {
#ifdef PDEBUG
				_support.debug_printf("new definition of vreg %u\n", usedef.reg.unique_index());
#endif
				vreg->first_def = current;
				vreg->last_control_flow_count = cur_control_flow_count;
			} else if (vreg->last_use == nullptr && !usedef.is_usedef()) {
#ifdef PDEBUG
				_support.debug_printf("definition of vreg %u, without use (and not a usedef) lcfc=%u, ccfc=%u\n", usedef.reg.unique_index(), vreg->last_control_flow_count, cur_control_flow_count);
#endif

#if 1

				// Was there any intermediate controlflow/uses?
				if (vreg->last_control_flow_count == cur_control_flow_count) {
#ifdef PDEBUG
					_support.debug_printf("  no control flow! killing %u\n", vregs[usedef.reg.unique_index()].first_def->nr);
#endif

					vreg->first_def->change_kind(InstructionKind::DEAD);
					vreg->first_def = current;
				}
#endif
			}
		}

		for (unsigned int use_def_index = 0; use_def_index < usedeflist.next; use_def_index++) {
			const auto& usedef = usedeflist.get(use_def_index);
			if (!usedef.is_valid()) continue; // Skip invalid usedefs
			if (!usedef.is_use()) continue; // Skip non-use usedefs
			if (!usedef.reg.is_virtual()) continue; // Skip non-virtual registers

			VirtualRegister *vreg = &vregs[usedef.reg.unique_index()];
#ifdef PDEBUG
			if (vreg > last_vreg) {
				last_vreg = vreg;
			}
#endif

			vreg->last_use = current;
		}

		current = current->next();
	} while (current != head);

#ifdef PDEBUG
	if (last_vreg != nullptr) {
		for (VirtualRegister *vreg = vregs; vreg != last_vreg + 1; vreg++) {
			if (vreg->first_def == nullptr && vreg->last_use == nullptr) continue;

			dbt_u64 fd = -1, lu = -1;

			if (vreg->first_def != nullptr) {
				fd = vreg->first_def->nr;
			}

			if (vreg->last_use != nullptr) {
				lu = vreg->last_use->nr;
			}

			_support.debug_printf("vreg %lu: start:%lu, end:%lu\n", (vreg - vregs), fd, lu);
		}
	}
#endif

	return true;
}

#define GPR_MASK 0x0000FFFF
#define SSE_MASK 0xFFFF0000

bool ReverseAllocator::do_allocate(VirtualRegister* vregs, Instruction* head)
{
	dbt_u64 phys_reg_tracking[MAX_PHYS_REGISTERS];
	BitSet<> live_phys_regs;

	// HACK
	live_phys_regs.set(X86PhysicalRegisters::R15.unique_index());
	live_phys_regs.set(X86PhysicalRegisters::BP.unique_index());
	live_phys_regs.set(X86PhysicalRegisters::SP.unique_index());

	phys_reg_tracking[X86PhysicalRegisters::R15.unique_index()] = X86PhysicalRegisters::R15.unique_index();
	phys_reg_tracking[X86PhysicalRegisters::BP.unique_index()] = X86PhysicalRegisters::BP.unique_index();
	phys_reg_tracking[X86PhysicalRegisters::SP.unique_index()] = X86PhysicalRegisters::SP.unique_index();

	Instruction *last = head->prev();

	Instruction *current = last;
	do {
#ifdef PDEBUG
		{
			Formatter __debug_formatter;
			_support.debug_printf("@ %lu = %s\n", current->nr, __debug_formatter.format_instruction(current));
		}
#endif

		Instruction::UseDefList usedeflist;
		current->get_usedefs(usedeflist);

		bool skip = false;
		for (unsigned int use_def_index = 0; use_def_index < usedeflist.next; use_def_index++) {
			const auto& usedef = usedeflist.get(use_def_index);
			if (!usedef.is_valid()) continue; // Skip invalid usedefs
			if (!usedef.is_def()) continue; // Skip non-def usedefs

			dbt_u64 register_index = usedef.reg.unique_index();

			if (usedef.reg.is_virtual()) {
				// Definition of VREG
				VirtualRegister *vreg = &vregs[register_index];

				if (vreg->first_def == current) {
					if (vreg->last_use == nullptr) {
#ifdef PDEBUG
						_support.debug_printf("def of unused vreg %u\n", register_index);
#endif
						skip = true;
						break;
					} else {
						// If this is the first def, then release the allocated vreg
						live_phys_regs.clear(vreg->physical_register_index);

#ifdef PDEBUG
						_support.debug_printf("ending live-range of vreg %u in preg %u\n", register_index, vreg->physical_register_index);
#endif
					}
				}

			} else {
				if (register_index > MAX_PHYS_REGISTERS) {
					_support.assertion_fail("definition of invalid preg");
					return false;
				}

				// Definition of PREG
				if (live_phys_regs.is_set(register_index)) {
					live_phys_regs.clear(register_index);

					if (phys_reg_tracking[register_index] > MAX_PHYS_REGISTERS) {
						dbt_u64 conflicting_vreg_index = phys_reg_tracking[register_index];
						VirtualRegister *conflicting_vreg = &vregs[conflicting_vreg_index];

#ifdef PDEBUG
						_support.debug_printf("def of preg %u, but it's tracking vreg %u!\n", register_index, conflicting_vreg_index);
#endif

						// Find a new preg for the vreg
						dbt_u64 mask = usedef.reg.is_sse() ? SSE_MASK : GPR_MASK;
						dbt_u64 new_preg = conflicting_vreg->interference.find_first_clear_via_mask(mask);

						if (new_preg == (dbt_u64) - 1) {
#ifdef PDEBUG
							_support.debug_printf("vreg %u interference=%08x\n", conflicting_vreg_index, (dbt_u64) conflicting_vreg->interference);
#endif
							_support.assertion_fail("out of registers in re-assignment");
						}

#ifdef PDEBUG
						_support.debug_printf("re-assigning vreg %u to preg %u (%08x)\n", conflicting_vreg_index, new_preg, (dbt_u64) conflicting_vreg->interference);
#endif
						conflicting_vreg->physical_register_index = new_preg;
						phys_reg_tracking[conflicting_vreg->physical_register_index] = conflicting_vreg_index;
						live_phys_regs.set(conflicting_vreg->physical_register_index);
						vregs[conflicting_vreg_index].interference = live_phys_regs;

						// Update ALL vreg interferences
						for (int i = 0; i < MAX_PHYS_REGISTERS; i++) {
							if (live_phys_regs.is_set(i)) {
#ifdef PDEBUG
								_support.debug_printf(" updating preg=%u, vreg=%u, prev=%08x, cur=%08x\n", i, phys_reg_tracking[i], (dbt_u64) vregs[phys_reg_tracking[i]].interference, (dbt_u64) live_phys_regs);
#endif
								vregs[phys_reg_tracking[i]].interference |= live_phys_regs;
							}
						}
					}

#ifdef PDEBUG
					_support.debug_printf("ending live-range of preg %u, tracking %u\n", register_index, phys_reg_tracking[register_index]);
#endif
				}
			}
		}

		if (!skip) {

			for (unsigned int use_def_index = 0; use_def_index < usedeflist.next; use_def_index++) {
				const auto& usedef = usedeflist.get(use_def_index);
				if (!usedef.is_valid()) continue; // Skip invalid usedefs
				if (!usedef.is_use()) continue; // Skip non-use usedefs

				dbt_u64 register_index = usedef.reg.unique_index();

				if (usedef.reg.is_virtual()) {
					// Use of VREG

					VirtualRegister *vreg = &vregs[register_index];
					if (vreg->last_use == current || vreg->physical_register_index == 32) {
						// If this is the last use, then allocate a register to start tracking this vreg
#ifdef PDEBUG
						dbt_u64 xxx = (dbt_u64) live_phys_regs;
#endif

						// Now, hold the phone.  We need to find a register of the correct class.
						dbt_u64 mask = usedef.reg.is_sse() ? SSE_MASK : GPR_MASK;

#ifdef CLEVER_ALLOCATION_STRATEGY
						// Try to be smart about this
						if (current->kind() == InstructionKind::MOV || current->kind() == InstructionKind::MOVZX) {
							auto& srcop = current->get_operand(0);
							auto& dstop = current->get_operand(1);

							if (srcop.is_reg() && srcop.reg.reg.is_virtual() && dstop.is_reg() && !dstop.reg.reg.is_special()) {
								if (dstop.reg.reg.is_virtual()) {
#ifdef PDEBUG
									_support.debug_printf(" selecting register for mov vreg->vreg instruction\n");
#endif       
									vreg->physical_register_index = live_phys_regs.find_first_clear_via_mask(mask);
								} else {
#ifdef PDEBUG
									_support.debug_printf(" selecting register for mov vreg->preg instruction - want preg=%u\n", dstop.reg.reg.unique_index());
#endif       
									if (live_phys_regs.is_clear(dstop.reg.reg.unique_index())) {
#ifdef PDEBUG
										_support.debug_printf(" available!\n", dstop.reg.reg.unique_index());
#endif       
										vreg->physical_register_index = dstop.reg.reg.unique_index();
									} else {
#ifdef PDEBUG
										_support.debug_printf(" not available!\n", dstop.reg.reg.unique_index());
#endif       
										vreg->physical_register_index = live_phys_regs.find_first_clear_via_mask(mask);
									}
								}
							} else {
								vreg->physical_register_index = live_phys_regs.find_first_clear_via_mask(mask);
							}
						} else {
#endif
							vreg->physical_register_index = live_phys_regs.find_first_clear_via_mask(mask);
#ifdef CLEVER_ALLOCATION_STRATEGY
						}
#endif    
						if (vreg->physical_register_index < 0) {
							_support.assertion_fail("out of registers in allocation");
						}

						phys_reg_tracking[vreg->physical_register_index] = register_index;
						live_phys_regs.set(vreg->physical_register_index);
						vregs[register_index].interference = live_phys_regs;

						// TODO: Update ALL vreg interferences
						for (int i = 0; i < MAX_PHYS_REGISTERS; i++) {
							if (live_phys_regs.is_set(i)) {
#ifdef PDEBUG
								_support.debug_printf(" updating preg=%u, vreg=%u, prev=%08x, cur=%08x\n", i, phys_reg_tracking[i], (dbt_u64) vregs[phys_reg_tracking[i]].interference, (dbt_u64) live_phys_regs);
#endif

								vregs[phys_reg_tracking[i]].interference |= live_phys_regs;
							}
						}

#ifdef PDEBUG
						_support.debug_printf("starting live-range of vreg %u, allocated to preg %u (%08x, %08x)\n", register_index, vreg->physical_register_index, xxx, (dbt_u64) live_phys_regs);
#endif
					}
				} else {
					if (register_index > 32) {
						_support.assertion_fail("use of invalid preg");
						return false;
					}

					// Use of PREG
					if (live_phys_regs.is_set(register_index) && phys_reg_tracking[register_index] != register_index) {
						dbt_u64 conflicting_vreg_index = phys_reg_tracking[register_index];
						VirtualRegister *conflicting_vreg = &vregs[conflicting_vreg_index];

#ifdef PDEBUG
						_support.debug_printf("conflicting use of preg %u, currently tracking %u\n", register_index, conflicting_vreg_index);
#endif

						// Find a new preg for the vreg
						dbt_u64 mask = usedef.reg.is_sse() ? SSE_MASK : GPR_MASK;
						dbt_u64 new_preg = conflicting_vreg->interference.find_first_clear_via_mask(mask);

						if (new_preg == (dbt_u64) - 1) {
#ifdef PDEBUG
							_support.debug_printf("vreg %u interference=%08x\n", conflicting_vreg_index, (dbt_u64) conflicting_vreg->interference);
#endif
							_support.assertion_fail("out of registers in re-assignment");
						}

#ifdef PDEBUG
						_support.debug_printf("re-assigning vreg %u to preg %u (%08x)\n", conflicting_vreg_index, new_preg, (dbt_u64) conflicting_vreg->interference);
#endif
						conflicting_vreg->physical_register_index = new_preg;
						phys_reg_tracking[conflicting_vreg->physical_register_index] = conflicting_vreg_index;
						live_phys_regs.set(conflicting_vreg->physical_register_index);
						vregs[conflicting_vreg_index].interference = live_phys_regs;

						// Update ALL vreg interferences
						for (int i = 0; i < MAX_PHYS_REGISTERS; i++) {
							if (live_phys_regs.is_set(i)) {
#ifdef PDEBUG
								_support.debug_printf(" updating preg=%u, vreg=%u, prev=%08x, cur=%08x\n", i, phys_reg_tracking[i], (dbt_u64) vregs[phys_reg_tracking[i]].interference, (dbt_u64) live_phys_regs);
#endif
								vregs[phys_reg_tracking[i]].interference |= live_phys_regs;
							}
						}

						phys_reg_tracking[register_index] = register_index;
					} else {
						phys_reg_tracking[register_index] = register_index;
						live_phys_regs.set(register_index);
						vregs[register_index].interference = live_phys_regs;

						// Update ALL vreg interferences
						for (int i = 0; i < MAX_PHYS_REGISTERS; i++) {
							if (live_phys_regs.is_set(i)) {
#ifdef PDEBUG
								_support.debug_printf(" updating preg=%u, vreg=%u, prev=%08x, cur=%08x\n", i, phys_reg_tracking[i], (dbt_u64) vregs[phys_reg_tracking[i]].interference, (dbt_u64) live_phys_regs);
#endif

								vregs[phys_reg_tracking[i]].interference |= live_phys_regs;
							}
						}
#ifdef PDEBUG
						_support.debug_printf("starting live-range of preg %u (%08x)\n", register_index, (dbt_u64) live_phys_regs);
#endif
					}
				}
			}

		}

		current = current->prev();
	} while (current != last);

	return true;
}

bool ReverseAllocator::commit(Instruction* head, const VirtualRegister* vreg_to_preg)
{
	static const X86PhysicalRegister * assignments[] = {
		&X86PhysicalRegisters::A,
		&X86PhysicalRegisters::C,
		&X86PhysicalRegisters::D,
		&X86PhysicalRegisters::B,
		&X86PhysicalRegisters::RIZ,
		&X86PhysicalRegisters::RIZ,
		&X86PhysicalRegisters::SI,
		&X86PhysicalRegisters::DI,
		&X86PhysicalRegisters::R8,
		&X86PhysicalRegisters::R9,
		&X86PhysicalRegisters::R10,
		&X86PhysicalRegisters::R11,
		&X86PhysicalRegisters::R12,
		&X86PhysicalRegisters::R13,
		&X86PhysicalRegisters::R14,
		&X86PhysicalRegisters::R15,
		&X86PhysicalRegisters::XMM0,
		&X86PhysicalRegisters::XMM1,
		&X86PhysicalRegisters::XMM2,
		&X86PhysicalRegisters::XMM3,
		&X86PhysicalRegisters::XMM4,
		&X86PhysicalRegisters::XMM5,
		&X86PhysicalRegisters::XMM6,
		&X86PhysicalRegisters::XMM7,
	};

	Instruction *current = head;
	do {
		if (current->kind() != InstructionKind::DEAD) {
			for (unsigned int i = 0; i < Instruction::NR_OPERANDS; i++) {
				const auto& operand = current->get_operand(i);
				if (operand.is_reg()) {
					if (operand.reg.reg.is_virtual()) {
						dbt_u64 preg_index = vreg_to_preg[operand.reg.reg.unique_index()].physical_register_index;
						if (preg_index == X86PhysicalRegisters::RIZ.unique_index()) {
							current->change_kind(InstructionKind::DEAD);
							break;
						}

						if (preg_index >= (sizeof(assignments) / sizeof(assignments[0]))) {
#ifdef PDEBUG
							_support.debug_printf("illegal vreg %u to preg %u @ %u (reg operand)\n", operand.reg.reg.unique_index(), preg_index, current->nr);
#endif
							_support.assertion_fail("assignment of preg out of range");
						}

#ifdef PDEBUG
						_support.debug_printf("committing vreg %u to preg %u @ %u (reg operand)\n", operand.reg.reg.unique_index(), preg_index, current->nr);
#endif

						current->get_operand_nc(i).reg.reg = *assignments[preg_index];
					}
				} else if (operand.is_mem()) {
					if (operand.mem.base_register.is_virtual()) {
						dbt_u64 preg_index = vreg_to_preg[operand.mem.base_register.unique_index()].physical_register_index;

						if (preg_index >= (sizeof(assignments) / sizeof(assignments[0]))) {
							_support.assertion_fail("assignment of preg out of range");
						}

#ifdef PDEBUG
						_support.debug_printf("committing vreg %u to preg %u @ %u (mem base operand)\n", operand.reg.reg.unique_index(), preg_index, current->nr);
#endif

						current->get_operand_nc(i).mem.base_register = *assignments[preg_index];
					}

					if (operand.mem.index_register.is_virtual()) {
						dbt_u64 preg_index = vreg_to_preg[operand.mem.index_register.unique_index()].physical_register_index;

						if (preg_index >= (sizeof(assignments) / sizeof(assignments[0]))) {
							_support.assertion_fail("assignment of preg out of range");
						}

#ifdef PDEBUG
						_support.debug_printf("committing vreg %u to preg %u @ %u (mem idx operand)\n", operand.reg.reg.unique_index(), preg_index, current->nr);
#endif

						current->get_operand_nc(i).mem.index_register = *assignments[preg_index];
					}
				}
			}
		}

		switch (current->kind()) {
		case InstructionKind::MOV:
		case InstructionKind::MOVQ:
		case InstructionKind::MOVDQA:
			if (current->get_operand(0) == current->get_operand(1)) {
				current->change_kind(InstructionKind::DEAD);
			}
			break;

		default:
			break;
		}

		current = current->next();
	} while (current != head);

	return true;
}

bool ReverseAllocator::verify(const Instruction* head)
{
	const Instruction *current = head;
	do {
#ifndef PDEBUG
		if (!verify_instruction(current)) {
#endif
			Formatter __fmt;
			_support.debug_printf("[%u] %s\n", current->nr, __fmt.format_instruction(current));

#ifndef PDEBUG
			return false;
		}
#endif

		current = current->next();
	} while (current != head);

	return true;
}

bool ReverseAllocator::verify_instruction(const Instruction* insn)
{
	if (insn->kind() == InstructionKind::DEAD) return true;

	for (int i = 0; i < Instruction::NR_OPERANDS; i++) {
		auto op = insn->get_operand(0);

		if (op.is_reg()) {
			if (op.reg.reg.is_virtual()) {
				_support.debug_printf("verification failed: instruction has virtual register operand\n");
				return false;
			}
		} else if (op.is_mem()) {
			if (op.mem.base_register.is_virtual()) {
				_support.debug_printf("verification failed: instruction has virtual base register operand\n");
				return false;
			}

			if (op.mem.index_register.is_virtual()) {
				_support.debug_printf("verification failed: instruction has virtual index register operand\n");
				return false;
			}
		}
	}

	return true;
}

bool ReverseAllocator::decorate_call(Instruction *call_instruction, int nr_args)
{
	static const X86PhysicalRegister * caller_saved[] = {
		// Caller Saved
		&X86PhysicalRegisters::A,
		&X86PhysicalRegisters::R10,
		&X86PhysicalRegisters::R11,

		// Function Arguments
		&X86PhysicalRegisters::R9,
		&X86PhysicalRegisters::R8,
		&X86PhysicalRegisters::C,
		&X86PhysicalRegisters::D,
		&X86PhysicalRegisters::SI,
		&X86PhysicalRegisters::DI
	};

	for (int i = 0; i < (3 + (6 - nr_args)); i++) {
		auto reg = caller_saved[i];

		auto push = _support.alloc_obj<Instruction>(InstructionKind::PUSH);
		auto pop = _support.alloc_obj<Instruction>(InstructionKind::POP);

		push->set_operand(0, Operand::make_register(*reg, 64));
		pop->set_operand(0, Operand::make_register(*reg, 64));

		call_instruction->prev()->insert_after(push);
		call_instruction->insert_after(pop);
	}

	return true;
}

bool ReverseAllocator::fixup_calls(Instruction *head)
{
	Instruction *current = head;
	do {
		switch (current->kind()) {
		case InstructionKind::CALL:
		case InstructionKind::CALL0:
		case InstructionKind::CALL1:
		case InstructionKind::CALL2:
		case InstructionKind::CALL3:
		case InstructionKind::CALL4:
		case InstructionKind::CALL5:
		case InstructionKind::CALL6:
			if (!decorate_call(current, 0)) {
				return false;
			}

			break;

		default: break;
		}

		current = current->next();
	} while (current != head);

	return true;
}

bool ReverseAllocator::number_and_legalise_instructions(Instruction *head)
{
	dbt_u64 idx = 0;

	Instruction *current = head;
	do {
		// Number the instruction.
		current->nr = idx++;

		// Any mem -> mem instructions must be performed via a temporary register
		if (current->match2() == InstructionMatch::MEM_MEM) {
			auto op0 = current->get_operand(0);
			// auto op1 = current->get_operand(1);

			auto tmp = Operand::make_register(_vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE), op0.mem.access_width);

			auto mov_to_tmp = _support.alloc_obj<Instruction>(InstructionKind::MOV);
			mov_to_tmp->set_operand(0, op0);
			mov_to_tmp->set_operand(1, tmp);

			current->prev()->insert_after(mov_to_tmp);
			current->set_operand(0, tmp);

			mov_to_tmp->nr = current->nr;
			current->nr = idx++;
		} else if (current->kind() == InstructionKind::JMP) {
			if (current->get_operand(0).label.target == current->next()) {
				current->change_kind(InstructionKind::DEAD);
			}
		}

#ifdef PDEBUG
		{
			Formatter __fmt;
			_support.debug_printf("[%u] %s\n", current->nr, __fmt.format_instruction(current));
		}
#endif

		current = current->next();
	} while (current != head);

	return true;
}