/* SPDX-License-Identifier: MIT */

#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_GUEST

#include <mmu/strategy/strategy.h>
#include <mmu/guest-mmu.h>
#include <smc/strategy.h>
#include <dbt/x86/x86-emitter.h>
#include <dbt/x86/x86-context.h>
#include <dbt/x86/x86-block.h>
#include <dbt/x86/x86-value.h>
#include <dbt/dbt.h>
#include <dbt/el/context.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/formatter.h>
#include <printf.h>
#include <mmu.h>
#include <cpu.h>
#include <safepoint.h>

extern safepoint_t cpu_safepoint;

using namespace captive::arch::jit::x86;
using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

uint64_t invalidated_counter;

static void __guestmmu_flush()
{
	mmu_strategy.invalidate();
}

template<>
void X86Emitter::mmu_flush<captive::arch::mmu::strategy::GuestMMUStrategy>(X86Value *addr)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_flush, 64), Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
}

template<>
void X86Emitter::mmu_pgt_change<captive::arch::mmu::strategy::GuestMMUStrategy>()
{
	//auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	//add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)__invalidate_translations, 64), Operand::make_register(tmp, 64));
	//add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
}

template<>
void X86Emitter::mmu_asid_change<captive::arch::mmu::strategy::GuestMMUStrategy>(X86Value *asid)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_flush, 64), Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
}

static __attribute__((noreturn)) void deal_with_fault(gva_t va, const AddressTranslationContext& atc)
{
	if (!captive::arch::CPU::get_active_cpu()->handle_mmu_fault(va, atc)) {
		fatal("guest machine failed to handle mmu fault\n");
	}

	restore_safepoint(&cpu_safepoint, 1);
	__builtin_unreachable();
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
void __guestmmu_load(uint64_t address, uint64_t *value)
{
	if (((address & 0xfff) + (SIZE_IN_BITS / 8)) > 0x1000) {
		if (SIZE_IN_BITS == 8) fatal("RUH-ROH");
		for (int i = 0; i < (SIZE_IN_BITS / 8); i++) {
			uint64_t tmp;
			__guestmmu_load<PRIVILEGED, 8>(address + i, &tmp);

			((uint8_t *) value)[i] = (uint8_t) tmp;
		}
	} else {
		AddressTranslationContext atc;
		atc.privilege = PRIVILEGED ? AddressTranslationPrivilege::SUPERVISOR : AddressTranslationPrivilege::USER;
		atc.type = AddressTranslationType::READ;

		if (!guest_mmu.translate(address, atc)) {
			fatal("LOAD TXLN FAILED\n");
		}

		if (atc.result != AddressTranslationResult::OK) {
			deal_with_fault(address, atc);
		} else {
			uint64_t offset = VM_PHYS_GPM_BASE + VM_VIRT_SPLIT + atc.pa;
			switch (SIZE_IN_BITS) {
			case 8: *value = (uint64_t)*((uint8_t *) (offset));
				break;
			case 16: *value = (uint64_t)*((uint16_t *) (offset));
				break;
			case 32: *value = (uint64_t)*((uint32_t *) (offset));
				break;
			case 64: *value = (uint64_t)*((uint64_t *) (offset));
				break;
			}
		}
	}
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
static void __guestmmu_store(uint64_t address, uint64_t value)
{
	if (((address & 0xfff) + (SIZE_IN_BITS / 8)) > 0x1000) {
		if (SIZE_IN_BITS == 8) fatal("RUH-ROH");
		for (int i = 0; i < (SIZE_IN_BITS / 8); i++) {
			__guestmmu_store<PRIVILEGED, 8>(address + i, value);
			value >>= 8;
		}
	} else {
		AddressTranslationContext atc;
		atc.privilege = PRIVILEGED ? AddressTranslationPrivilege::SUPERVISOR : AddressTranslationPrivilege::USER;
		atc.type = AddressTranslationType::WRITE;

		if (!guest_mmu.translate(address, atc)) {
			fatal("STORE TXLN FAILED\n");
		}

		if (atc.result != AddressTranslationResult::OK) {
			deal_with_fault(address, atc);
		} else {
			uint64_t offset = VM_PHYS_GPM_BASE + VM_VIRT_SPLIT + atc.pa;
			switch (SIZE_IN_BITS) {
			case 8: *((uint8_t *) (offset)) = (uint8_t) value;
				break;
			case 16: *((uint16_t *) (offset)) = (uint16_t) value;
				break;
			case 32: *((uint32_t *) (offset)) = (uint32_t) value;
				break;
			case 64: *((uint64_t *) (offset)) = (uint64_t) value;
				break;
			}
		}
	}
}

template<>
void X86Emitter::mmu_store_memory<captive::arch::mmu::strategy::GuestMMUStrategy>(X86Value *addr, X86Value *value)
{
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));
	add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_register(X86PhysicalRegisters::SI, value->type().size_in_bits()));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_store<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_store<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_store<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_store<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_store<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_store<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_store<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_store<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));
}

template<>
dbt::el::Value* X86Emitter::mmu_load_memory<captive::arch::mmu::strategy::GuestMMUStrategy>(X86Value *addr, const dbt::el::Type& type)
{
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_load<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_load<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_load<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_load<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_load<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_load<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_load<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __guestmmu_load<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	add_instruction(InstructionKind::SUB, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::SP, 64), Operand::make_register(X86PhysicalRegisters::SI, 64));

	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));

	auto val = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::POP, Operand::make_register(val, 64));

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(val, type.size_in_bits()));
}

#endif
