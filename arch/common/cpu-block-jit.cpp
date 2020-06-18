/* SPDX-License-Identifier: MIT */

#include <cpu.h>
#include <decode.h>
#include <disasm.h>
#include <safepoint.h>
#include <dbt/dbt.h>
#include <dbt/translation-manager.h>
#include <dbt/translation.h>
#include <dbt/x86/x86-context.h>
#include <dbt/x86/x86-emitter.h>
#include <dbt/x86/x86-dag-emitter.h>
#include <dbt/support.h>
#include <dbt/el/block.h>
#include <dbt/mc/x86/encoder.h>
#include <dbt/mc/x86/printer.h>
#include <dbt/mc/x86/formatter.h>
#include <dbt/mc/x86/allocator.h>
#include <dbt/mc/x86/reverse-allocator.h>
#include <x86/rdtsc-timer.h>
#include <pump-timer.h>
#include <mmu/strategy/strategy.h>
#include <smc/core-smc.h>
#include <malloc/page-allocator.h>

#include <set>
#include <map>
#include <list>
#include <vector>

#include "../arm64/include/arm64-decode.h"

//#define REG_STATE_PROTECTION
// #define DEBUG_TRANSLATION
//#define QEMU_STYLE
//#define PDAG

//#define MODE_TRACKING

extern safepoint_t cpu_safepoint;

using namespace captive::arch;
using namespace captive::arch::jit;
using namespace captive::arch::jit::x86;
using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;
using namespace captive::arch::smc;

static uint64_t __runtime_start;

extern uint64_t *__profile;

bool CPU::run_block_jit()
{
	//CPU::get_active_cpu_data()->guest_data->some_sort_of_pointer = (uint64_t)__profile;

	_per_cpu_data->guest_data->some_sort_of_pointer = (uint64_t)__profile;

	printf("cpu: starting block-jit cpu execution, PC=%016x\n", read_pc());
	printf("--------------------------------------------------------------------\n");

	__runtime_start = captive::arch::x86::rdtsc_timer.count();

	if (_per_cpu_data->guest_data->tracing)
	{
		trace().enable();
	}

	// Create a safepoint for returning from a memory access fault
	int rc = record_safepoint(&cpu_safepoint);
	if (rc > 0)
	{
		if (rc == 0x10)
		{
			uint64_t addr = jit_state.entry_address;
			//printf("FEATURE CHANGE INVALIDATION @ %p pc=%016x features=%x\n", addr, read_pc(), feature_manager().active_features());
			invalidate_translation_phys(addr);
		}

		// We're no longer executing a translation
		_exec_txl = false;

		// Make sure interrupts are enabled.
		__local_irq_enable();
	}

	/*uint16_t cs;
	asm volatile("mov %%cs, %0" : "=r"(cs));
	if (feature_manager().get_feature(0)) {
		// Switch to KERNEL mode
		if ((cs & 3) != 0) {
			asm volatile("int $0x80");
		}
	} else {
		// Switch to USER mode
		if ((cs & 3) != 3) {
			asm volatile("int $0x81");
		}
	}*/

	bool result = run_block_jit_safepoint();
	printf("--------------------------------------------------------------------\n");
	printf("cpu: ending block-jit cpu execution, PC=%016x\n", read_pc());

	return result;
}

extern bool __want_trace;

bool CPU::run_block_jit_safepoint()
{
	bool step_ok = true;

	uint64_t region_virt_base = 1;
	uint64_t region_phys_base = 1;

	do
	{
		_txln_mgr.collect_garbage();

		// Check the ISR to determine if there is an interrupt pending,
		// and if there is, instruct the interpreter to handle it.
		if (unlikely(cpu_data().isr))
		{
			// TODO: Edge?
			handle_irq(cpu_data().isr);
		}

		// Check to see if there are any pending actions coming in from
		// the hypervisor.
		if (unlikely(cpu_data().async_action))
		{
			bool result = handle_pending_action(cpu_data().async_action);
			cpu_data().async_action = 0;
			step_ok = !cpu_data().halt;

			if (!result)
				continue;
		}

		/*if (!feature_manager().get_feature(0) && !trace().enabled() && __want_trace) {
			trace().enable();
			invalidate_translations();
		} else if (feature_manager().get_feature(0) && trace().enabled()) {
			trace().disable();
			invalidate_translations();
		}*/

		gva_t virt_pc = (gva_t)read_pc();
		assert((virt_pc & 3) == 0);

		/*if (virt_pc == 0xffff000008150da0) {
			assert(false);
		}*/

		/*if (__force_trace) {
			if (!trace().enabled()) {
				trace().enable();
				invalidate_translations();
			}
		}*/

		//if (virt_pc == 0x4dae68) {
		//	intercept(0);
		//}

		//printf("EXECUTE %p\n", read_pc());

		// Check to see if we've changed page.
		if (PAGE_ADDRESS_OF(virt_pc) != region_virt_base)
		{
			AddressTranslationContext atc;
			atc.privilege = feature_manager().get_feature(0) ? AddressTranslationPrivilege::SUPERVISOR : AddressTranslationPrivilege::USER;
			atc.type = AddressTranslationType::FETCH;

			if (!mmu_strategy.translate(virt_pc, atc))
			{
				printf("PC=%p\n", virt_pc);
				fatal("FETCH FAILED\n");
			}
			else if (atc.result != AddressTranslationResult::OK)
			{
				if (!handle_mmu_fault(virt_pc, atc))
					return false;
				continue;
			}

			region_virt_base = PAGE_ADDRESS_OF(virt_pc);
			region_phys_base = PAGE_ADDRESS_OF(atc.pa);
		}

		gpa_t phys_pc = (gpa_t)(region_phys_base | PAGE_OFFSET_OF(virt_pc));

		/*if (phys_pc == 0x403a78) {
			if (!trace().enabled()) {
				trace().enable();
				invalidate_translations();
			}
		}*/

#ifdef MODE_TRACKING
		assert_privilege_mode();
#endif

		Translation *txln = _txln_mgr.lookup_translation(phys_pc);
		if (!txln)
		{
#ifdef CONFIG_TIME_COMPILATION
			uint64_t compile_start = captive::arch::x86::rdtsc_timer.count();
#endif

#if defined(CONFIG_TIME_COMPILATION) || defined(CONFIG_PROFILE_HOST_PER_GUEST)
			printf("BLOCK\t%p\t", phys_pc);
#endif

			txln = compile_block(*tagged_registers().ISA, phys_pc);
#ifdef CONFIG_PROFILE_HOST_PER_GUEST
			printf("\n");
#endif
#ifdef CONFIG_TIME_COMPILATION
			uint64_t compile_end = captive::arch::x86::rdtsc_timer.count();

			uint64_t nsecs_for_block = captive::arch::x86::rdtsc_timer.ticks_to_nsec(compile_end - compile_start);

			printf("%lu\n", nsecs_for_block);

			cpu_data().compilation_time += nsecs_for_block;
#endif

			assert(txln);

			_txln_mgr.register_translation(phys_pc, txln);
			core_smc.mark_page_translated(phys_pc);
		}

		block_chain_cache_entry *ptr = block_txln_cache.entry_ptr(virt_pc >> 2);
		ptr->tag = virt_pc;
		ptr->fn = txln->raw_code();

#if defined(CONFIG_TIME_EXECUTION) || defined(CONFIG_AGGREGATE_BLOCK_EXECUTION)
		uint64_t start = captive::arch::x86::rdtsc_timer.count();
#endif
		_exec_txl = true;
		uint32_t return_code = txln->invoke();
		_exec_txl = false;
#if defined(CONFIG_TIME_EXECUTION) || defined(CONFIG_AGGREGATE_BLOCK_EXECUTION)
		uint64_t end = captive::arch::x86::rdtsc_timer.count();

		uint64_t nsecs_for_block = captive::arch::x86::rdtsc_timer.ticks_to_nsec(end - start);
		//printf("%p %lu %lu\n", virt_pc, nsecs_for_block, end);

#ifdef CONFIG_TIME_EXECUTION
		cpu_data().execution_time += nsecs_for_block;
#endif
#ifdef CONFIG_AGGREGATE_BLOCK_EXECUTION
		printf("BLOCK\t%p\t%lu\n", virt_pc, nsecs_for_block);
		//(*__block_execution_times)[virt_pc] += nsecs_for_block;
		//xxx += nsecs_for_block;
#endif
#endif

#ifdef CONFIG_BLOCK_CHAINING
		if (return_code > 0)
		{
			gva_t next_pc = read_pc();
			if (PAGE_ADDRESS_OF(next_pc) == region_virt_base)
			{
				gpa_t next_phys_pc = (gpa_t)(region_phys_base | PAGE_OFFSET_OF(next_pc));

				Translation *next_txln = _txln_mgr.lookup_translation(next_phys_pc);
				if (next_txln != nullptr)
				{
					Translation *prev_txln = _txln_mgr.lookup_translation(jit_state.entry_address);

					if (prev_txln != nullptr)
					{
						switch (return_code)
						{
						case 1:
							prev_txln->set_direct_jump_target((uint64_t)next_txln->raw_code());
							break;
						case 2:
							prev_txln->set_predicated_direct_jump_target((uint64_t)next_txln->raw_code());
							break;
						case 3:
							prev_txln->set_predicated_direct_jump_fallthrough((uint64_t)next_txln->raw_code());
							break;
						default:
							assert(false);
						}
					}
				}
			}
		}
#endif
	} while (step_ok);

	if (!step_ok)
		printf("step was not okay\n");

	return true;
}

static void *pool;

class CaptiveSupport : public captive::arch::dbt::Support
{
	static constexpr unsigned int slab_pages = 4096;

public:
	CaptiveSupport()
	{
		if (pool == nullptr)
		{
			pool = malloc::page_alloc.alloc_pages(slab_pages);
		}

		_current_slab_ptr = pool;
		_current_slab_end = (void *)((uintptr_t)pool + (0x1000 * slab_pages));
		//new_slab();
	}

	~CaptiveSupport()
	{
		//for (auto slab : _slabs) {
		//malloc::page_alloc.free_pages(slab, slab_pages);
		//}
	}

	void *alloc(dbt_size_t size, captive::arch::dbt::AllocClass cls) override
	{
		if (cls == captive::arch::dbt::AllocClass::TRANSLATED_CODE)
		{
			return malloc::code_alloc.alloc(size);
		}
		else
		{
			// Align size to 16 bytes
			if (size % 16 != 0)
				size += 16 - (size % 16);

			if (size > (size_t)_current_slab_end - (size_t)_current_slab_ptr)
			{
				printf("SIZE=%u, ptr=%p end=%p\n", size, _current_slab_ptr, _current_slab_end);
				fatal("ERROR\n");
			}

			void *ptr = _current_slab_ptr;
			_current_slab_ptr = (void *)((uintptr_t)_current_slab_ptr + size);

			return ptr;

			/*if (((uintptr_t)_current_slab_ptr + size) < (uintptr_t)_current_slab_end) {
				void *ptr = _current_slab_ptr;
				_current_slab_ptr = (void *)((uintptr_t)_current_slab_ptr + size);

				return ptr;
			} else {
				assert(size < (slab_pages * 0x1000));

				void *ptr = new_slab();
				_current_slab_ptr = (void *)((uintptr_t)_current_slab_ptr + size);

				return ptr;
			}*/
		}
	}

	void *realloc(void *ptr, dbt_size_t new_size, captive::arch::dbt::AllocClass cls) override
	{
		if (cls == captive::arch::dbt::AllocClass::TRANSLATED_CODE)
		{
			return malloc::code_alloc.realloc(ptr, new_size);
		}
		else
		{
			fatal("UNABLE TO REALLOC POOLED CHUNK\n");
		}
	}

	void free(void *ptr, captive::arch::dbt::AllocClass cls) override
	{
		if (cls == captive::arch::dbt::AllocClass::TRANSLATED_CODE)
		{
			malloc::code_alloc.free(ptr);
		}
	}

	void memcpy(void *dest, const void *src, dbt_size_t size) override
	{
		::memcpy(dest, src, size);
	}

	void assertion_fail(const char *msg) override
	{
		printf("PC = %016x\n", read_pc());
		fatal("DBT: %s\n", msg);
	}

	void debug_printf(const char *fmt, ...) override
	{
		char buffer[0x1000];
		va_list args;

		va_start(args, fmt);
		int rc = vsnprintf(buffer, 0x1000, fmt, args);
		va_end(args);

		buffer[rc] = 0;

		printf("%s", buffer);
	}

	void debug_dump_mem() override
	{
		debug_printf("MEM USED: %lu\n", malloc::code_alloc.used());
	}

	dbt_u64 ticks() const override
	{
		return (dbt_u64)__rdtsc();
	}

private:
	void *_current_slab_ptr, *_current_slab_end;

	/*std::vector<void *> _slabs;

	void *new_slab() {
		_current_slab_ptr = malloc::page_alloc.alloc_pages(slab_pages);
		_current_slab_end = (void *)((uintptr_t)_current_slab_ptr + (slab_pages * 0x1000));
		_slabs.push_back(_current_slab_ptr);

		return _current_slab_ptr;
	}*/
};

//#define MEM_TRACE
//#define TIME_TRACE
//#define GUEST_CODE_DUMP

#define MEM_TRACE_POINT(n)                                                                                    \
	do                                                                                                        \
	{                                                                                                         \
		int64_t __current = malloc::code_alloc.used();                                                        \
		int64_t __net = __current - __prev;                                                                   \
		__cumul += __net;                                                                                     \
		printf(n ": current = %ld, prev = %ld, net = %ld, cumul = %ld\n", __current, __prev, __net, __cumul); \
		__prev = __current;                                                                                   \
	} while (0)

#define TIME_TRACE_POINT(n)                                                                                   \
	do                                                                                                        \
	{                                                                                                         \
		int64_t __current = captive::arch::x86::rdtsc_timer.count();                                          \
		int64_t __net = __current - __prev;                                                                   \
		__cumul += __net;                                                                                     \
		printf(n ": current = %ld, prev = %ld, net = %ld, cumul = %ld\n", __current, __prev, __net, __cumul); \
		__prev = captive::arch::x86::rdtsc_timer.count();                                                     \
	} while (0)

#ifdef MEM_TRACE
#define TRACE_POINT MEM_TRACE_POINT
#endif

#ifdef TIME_TRACE
#define TRACE_POINT TIME_TRACE_POINT
#endif

#if !defined(MEM_TRACE) && !defined(TIME_TRACE)
#define TRACE_POINT(n)
#endif

#ifdef GUEST_CODE_DUMP
static unsigned long __block_idx;
#endif

struct measure
{

	measure()
	{
		start_time_ = captive::arch::x86::rdtsc_timer.count();
	}

	~measure()
	{
		uint64_t delta = captive::arch::x86::rdtsc_timer.count() - start_time_;
		printf("%lu\t", captive::arch::x86::rdtsc_timer.ticks_to_nsec(delta));
	}

private:
	uint64_t start_time_;
};

Translation *CPU::compile_block(uint8_t isa_mode, gpa_t pa)
{
	void *fn;
	dbt_size_t size;

#ifdef MEM_TRACE
	int64_t __cumul = 0, __prev = malloc::code_alloc.used();
#endif

#ifdef TIME_TRACE
	int64_t __start = captive::arch::x86::rdtsc_timer.count();
	int64_t __cumul = 0, __prev = __start;
#endif

#ifdef GUEST_CODE_DUMP
	printf(".section \".block_%p_%lx\", \"ax\"\n", pa, __block_idx);
	printf("BLOCK_%p_%lx:\n", pa, __block_idx++);
#endif

	CaptiveSupport DefaultSupport;

	ArchData ad;
	ad.NEGATIVE_DISPLACEMENT = (uint64_t)tagged_registers().N - (uint64_t)tagged_registers().base;
	ad.ZERO_DISPLACEMENT = (uint64_t)tagged_registers().Z - (uint64_t)tagged_registers().base;
	ad.CARRY_DISPLACEMENT = (uint64_t)tagged_registers().C - (uint64_t)tagged_registers().base;
	ad.OVERFLOW_DISPLACEMENT = (uint64_t)tagged_registers().V - (uint64_t)tagged_registers().base;

	X86Context ctx(DefaultSupport);
#ifdef PDAG
	X86DAGEmitter dag_emitter(ctx, ctx.entry_block());
	// Emit Block

	printf("digraph a {\n");
	if (!emit_block(isa_mode, pa, dag_emitter))
	{
		fatal("TRANSLATION FAILED @ EMISSION pa=%p\n", pa);
	}
	printf("}\n");
#endif

	// --- EMIT ---

	X86EmitterOptions options;
	options.no_mmu = !mmu_strategy.enabled();
	options.kernel_mode = feature_manager().get_feature(0);
	options.perf_kernel_icount = feature_manager().get_feature(6);
	options.perf_kernel_brcount = feature_manager().get_feature(7);
	options.perf_user_icount = feature_manager().get_feature(8);
	options.perf_user_brcount = feature_manager().get_feature(9);

	X86Emitter emitter(ad, ctx, ctx.entry_block(), options);

#ifdef CONFIG_COMPILATION_DRILLDOWN
	{
		measure m;
#endif

		uint32_t feature_set = feature_manager().active_features();
		emitter.block_start(pa, feature_set);

		// Emit Block
		if (!emit_block(isa_mode, pa, emitter))
		{
			fatal("TRANSLATION FAILED @ EMISSION pa=%p\n", pa);
		}

		emitter.block_end(feature_set);

#ifdef CONFIG_COMPILATION_DRILLDOWN
	}
#endif

	if (!ctx.link())
	{
		fatal("TRANSLATION FAILED @ LINKAGE pa=%p\n", pa);
	}

	// --- ALLOCATE ---

#ifdef CONFIG_COMPILATION_DRILLDOWN
	{
		measure m;
#endif

		dbt::mc::x86::ReverseAllocator allocator(DefaultSupport, emitter.vreg_allocator());
		if (!allocator.allocate(ctx.start_instruction()))
		{
			//printer.print(ctx.start_instruction());
			fatal("TRANSLATION FAILED @ ALLOCATION pa=%p\n", pa);
		}

#ifdef CONFIG_COMPILATION_DRILLDOWN
	}
#endif

	// --- ENCODE ---

#ifdef CONFIG_PROFILE_HOST_PER_GUEST
	uint64_t host_count = 0;

	dbt::mc::x86::Instruction *current_counter = ctx.start_instruction();
	do
	{
		if (current_counter->kind() == InstructionKind::DEAD || current_counter->kind() == InstructionKind::LABEL)
		{
		}
		else
		{
			host_count++;
		}

		current_counter = current_counter->next();
	} while (current_counter != ctx.start_instruction());

	printf("%lu\t", host_count);
#endif

#ifdef CONFIG_COMPILATION_DRILLDOWN
	{
		measure m;
#endif
		dbt::mc::x86::Encoder encoder(DefaultSupport);
		fn = encoder.encode(ctx.start_instruction(), size);

#ifdef CONFIG_COMPILATION_DRILLDOWN
	}
#endif

#ifdef CONFIG_PROFILE_HOST_PER_GUEST
	printf("%lu\t", size);
#endif

	if (!fn)
	{
		fatal("TRANSLATION FAILED @ ENCODING pa=%p\n", pa);
	}

	//printf("BLOCK %p = %p\n", pa, fn);

	if (_per_cpu_data->guest_data->dump_code)
	{
		asm volatile("out %0, $0xff\n" ::"a"(15), "D"(vm_virt_to_phys((void *)fn)), "S"(size), "d"(pa));
	}

	return new Translation(fn, size);
}

extern "C" char block_trampoline_epilogue_normal;
extern "C" char block_trampoline_epilogue_direct_fail;
extern "C" char block_trampoline_epilogue_direct_pred_target_fail;
extern "C" char block_trampoline_epilogue_direct_pred_fallthrough_fail;

bool CPU::emit_block(uint8_t isa_mode, gpa_t pa, dbt::el::Emitter &emitter)
{
	std::set<gpa_t> seen_pcs;
	seen_pcs.insert(pa);

	static uint8_t decode_data[256];
	Decode *insn = new (decode_data) arm64::arm64_decode();

#ifdef QEMU_STYLE
	uint64_t vpc = read_pc();

	printf("\n----------------\n");
	printf("IN:\n");
#endif

	int insn_count = 0;

#ifdef CONFIG_TIME_COMPILATION
	uint64_t decode_time = 0;
#endif

	gpa_t pc = pa;
	gpa_t page = PAGE_ADDRESS_OF(pc);
	do
	{
		// Attempt to decode the current instruction.

		//if (!decode_instruction_phys(isa_mode, pc, insn)) {

#ifdef CONFIG_TIME_COMPILATION
		uint64_t decode_start = captive::arch::x86::rdtsc_timer.count();
#endif

		if (!insn->decode(isa_mode, pc, (const uint8_t *)guest_phys_to_vm_virt(pc)))
		{
			printf("jit: unhandled decode fault @ isa=%d %016x (%08x)\n", isa_mode, pc, read_gp_u32(insn->pc));
			return false;
		}

#ifdef CONFIG_TIME_COMPILATION
		decode_time += captive::arch::x86::rdtsc_timer.count() - decode_start;
#endif

#ifdef DEBUG_TRANSLATION
		printf("jit: translating insn @ [%016x] (%08x) %s\n", insn->pc, *(uint32_t *)guest_phys_to_vm_virt(insn->pc), trace().disasm().disassemble(insn->pc, (const uint8_t *)insn));
#endif

#ifdef QEMU_STYLE
		printf("0x%016lx:  %08x      %s\n", vpc, *(uint32_t *)guest_phys_to_vm_virt(insn->pc), trace().disasm().disassemble(insn->pc, (const uint8_t *)insn));
#endif

#ifdef GUEST_CODE_DUMP
		printf(".word 0x%08x\n", *(uint32_t *)guest_phys_to_vm_virt(insn->pc));
#endif

		emitter.instruction_start(insn->pc);

		// Translate this instruction into the context.
		if (unlikely(trace().enabled()))
		{
			emitter.trace(dbt::el::TraceEvent::INSTRUCTION_START);
		}

#ifdef TIME_COMPILE
		__block_icount++;
#endif

		if (!dbt().translate(insn, emitter))
		{
			printf("dbt: instruction translation failed: ir=%08x %s\n", *(uint32_t *)(insn->pc), trace().disasm().disassemble(insn->pc, (const uint8_t *)insn));
			return false;
		}

		if (unlikely(trace().enabled()))
		{
			emitter.trace(dbt::el::TraceEvent::INSTRUCTION_END);
		}

#ifdef QEMU_STYLE
		vpc += insn->length;
#endif

		emitter.instruction_end(insn->pc, insn->end_of_block);

		pc += insn->length;
		insn_count++;

		if (unlikely(feature_manager().get_feature(2)))
		{
			emitter.call(__captive_single_step);
			emitter.leave();
			return true;
		}

#ifdef QEMU_STYLE
		if (insn->end_of_block)
			break;
#endif

		if (insn->end_of_block)
		{
#ifdef CONFIG_TRACE_BASED
			//JumpInfo ji = get_instruction_jump_info(insn);
			const JumpInfo ji = insn->get_jump_info();
			if (!insn->is_predicated && ji.type == JumpInfo::DIRECT && !seen_pcs.count(ji.target))
			{
				pc = ji.target;
				seen_pcs.insert(ji.target);
				continue;
			}
#endif

			break;
		}
	} while (PAGE_ADDRESS_OF(pc) == page && insn_count < 200);

#ifdef CONFIG_TIME_COMPILATION
	printf("%u\t%lu\t", insn_count, captive::arch::x86::rdtsc_timer.ticks_to_nsec(decode_time));
#endif

#ifdef CONFIG_PROFILE_HOST_PER_GUEST
	printf("%u\t", insn_count);
#endif

#if 0
	bool can_dispatch = false;
	gpa_t target_pc = 0, fallthrough_pc = 0;

	if (insn->end_of_block) {
		JumpInfo ji = get_instruction_jump_info(insn);

		if (ji.type == JumpInfo::DIRECT || ji.type == JumpInfo::DIRECT_PREDICATED) {
			target_pc = ji.target;

			fallthrough_pc = insn->pc + insn->length;

			uint64_t target_page = target_pc & ~0xfffULL;
			uint64_t ft_page = fallthrough_pc & ~0xfffULL;

			// Can only dispatch if both jump targets land on the same page as the jump source.
			if ((target_page == page) && (ft_page == page)) {
				can_dispatch = true;
			}

			if (ji.type == JumpInfo::DIRECT) {
				if ((target_page == page)) can_dispatch = true;
				fallthrough_pc = 0;
			}
		}
	}

	if (can_dispatch) {
		gpa_t target_phys_pc = page | PAGE_OFFSET_OF(target_pc);
		gpa_t ft_phys_pc = page | PAGE_OFFSET_OF(fallthrough_pc);

		void *target_block = nullptr, *ft_block = nullptr;

		if (target_pc) {
			const Translation *target_txln = _txln_mgr.lookup_translation(target_phys_pc);
			target_block = target_txln ? target_txln->raw_code() : nullptr;
		}

		if (fallthrough_pc) {
			const Translation *ft_txln = _txln_mgr.lookup_translation(ft_phys_pc);
			ft_block = ft_txln ? ft_txln->raw_code() : nullptr;
		}

		if (target_pc == pa) {
			//ctx.add_instruction(IRInstruction::loop());
			emitter.leave();
		} else {
			if (target_block) {
				emitter.chain(target_pc & 0xfff, fallthrough_pc & 0xfff, target_block, ft_block);
			} else {
				emitter.leave();
			}
		}
	} else {
		emitter.leave();
	}
#else
#ifdef CONFIG_BLOCK_CHAINING
	if (insn->end_of_block)
	{
		//JumpInfo ji = get_instruction_jump_info(insn);
		const JumpInfo ji = insn->get_jump_info();

		if (ji.type == JumpInfo::INDIRECT)
		{
			emitter.leave();
		}
		else if (ji.type == JumpInfo::DIRECT)
		{
			gpa_t target_pc = ji.target;
			uint64_t target_page = target_pc & ~0xfffULL;

			if (target_page != page)
			{
				emitter.leave();
			}
			else
			{
				Translation *target_txln = _txln_mgr.lookup_translation(target_pc);

				if (target_txln != nullptr)
				{
					emitter.super_chain_direct(target_pc, target_txln->raw_code());
				}
				else
				{
					emitter.super_chain_direct(target_pc, &block_trampoline_epilogue_direct_fail);
				}
			}
		}
		else if (ji.type == JumpInfo::DIRECT_PREDICATED)
		{
			gpa_t target_pc = ji.target;
			gpa_t fallthrough_pc = insn->pc + insn->length;

			uint64_t target_page = target_pc & ~0xfffULL;
			uint64_t fallthrough_page = fallthrough_pc & ~0xfffULL;

			if (target_page != page || fallthrough_page != page)
			{
				emitter.leave();
			}
			else
			{
				Translation *target_txln = _txln_mgr.lookup_translation(target_pc);
				Translation *fallthrough_txln = _txln_mgr.lookup_translation(fallthrough_pc);

				emitter.super_chain_direct_predicated(
					target_pc,
					fallthrough_pc,
					target_txln == nullptr ? &block_trampoline_epilogue_direct_pred_target_fail : target_txln->raw_code(),
					fallthrough_txln == nullptr ? &block_trampoline_epilogue_direct_pred_fallthrough_fail : fallthrough_txln->raw_code());
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		emitter.leave();
	}
#else
	emitter.leave();
#endif
#endif

	return true;
}
