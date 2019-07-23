/* SPDX-License-Identifier: MIT */

#include <cpu.h>
#include <barrier.h>
#include <decode.h>
#include <disasm.h>
#include <string.h>
#include <safepoint.h>
#include <priv.h>
#include <jit.h>
#include <malloc/page-allocator.h>
#include <smc/strategy.h>
#include <mmu/strategy/strategy.h>
#include <mmu/guest-mmu.h>

#include "../aarch64/include/aarch64-decode.h"

using namespace captive::arch;
using namespace captive::arch::jit;
using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

safepoint_t cpu_safepoint;

#ifndef NDEBUG
extern uint64_t page_faults;
extern uint64_t page_fault_reasons[8];
#endif

CPU *CPU::current_cpu;

CPU::CPU(Environment& env, PerCPUData *per_cpu_data)
: _env(env),
_fm(*this),
_per_cpu_data(per_cpu_data),
_exec_txl(false)
{
	// Allocate the register state, and make sure it is aligned.
	_reg_state = malloc::page_alloc.alloc_pages(2);
	assert(((uintptr_t) _reg_state & 0xfff) == 0);

	// Zero out the local state.
	bzero(&local_state, sizeof(local_state));
	bzero(&jit_state, sizeof(jit_state));
	bzero(&tagged_reg_offsets, sizeof(tagged_reg_offsets));

	jit_state.cpu = this;
	jit_state.per_cpu_data = per_cpu_data;
	jit_state.execution_mode = 0;
	jit_state.active_features = (1u << 30);
	jit_state.registers = _reg_state;
	jit_state.call_gate_tmp = 0x123456789abcdef0;
	jit_state.call_gate_segment = 0x38;
	jit_state.mem_call_gate = 0x123456789abcdef0;
	jit_state.mem_call_gate_segment = 0x48;

	jit_state.block_txln_cache = block_txln_cache.ptr();
	printf("block-txln-cache: %p\n", jit_state.block_txln_cache);

	jit_state.trace_buffer = (void *) per_cpu_data->guest_data->trace_buffer;
	jit_state.exit_chain = 0;

	jit_state.virtual_memory_mode = (uint64_t) - 1;
	jit_state.virtual_memory_mode_table[0] = 0;
	jit_state.virtual_memory_mode_table[1] = 0;
	jit_state.virtual_memory_mode_table[2] = 0;
	jit_state.virtual_memory_mode_table[3] = 0;
	jit_state.virtual_memory_mode_table[4] = 0;

	per_cpu_data->interrupt_pending = (uint8_t *) & jit_state.exit_chain;

	// Populate the FS register with the address of the JIT state structure.
	__wrmsr(0xc0000100, (uint64_t) & jit_state);

	invalidate_virtual_mappings_all();
}

CPU::~CPU()
{
}

bool __do_dump_code;

bool CPU::handle_pending_action(uint32_t action)
{
	switch (action) {
	case 1:
		/*#ifndef NDEBUG
				printf("page faults: %lu, [0]:%lu, [1]:%lu, [2]:%lu, [3]:%lu, [4]:%lu, [5]:%lu, [6]:%lu, [7]:%lu\n",
						page_faults,
						page_fault_reasons[0],
						page_fault_reasons[1],
						page_fault_reasons[2],
						page_fault_reasons[3],
						page_fault_reasons[4],
						page_fault_reasons[5],
						page_fault_reasons[6],
						page_fault_reasons[7]);
		#endif*/
		printf("*** PERFORMANCE COUNTERS ***\n");
		printf("A=%lu (%016x)\n", performance_counter_a(), performance_counter_a());
		printf("B=%lu (%016x)\n", performance_counter_b(), performance_counter_b());
		return false;

	case 2:
		dump_state();
		return true;

	case 3:
		trace().enable();
		invalidate_translations();
		return true;

	case 4:
		printf("*** interrupt debug ***\n");
		printf("ISR=%u\n", cpu_data().isr);
		return true;

	case 5:
	{
		printf("*** PERFORMANCE COUNTERS ***\n");
		printf("A=%lu (%016x)\n", performance_counter_a(), performance_counter_a());
		printf("B=%lu (%016x)\n", performance_counter_b(), performance_counter_b());

		const uint64_t *pdata = performance_data();
		for (int i = 0; i < 16; i++) {
			printf("DATA[%u]=%lu (%016x)\n", i, pdata[i], pdata[i]);
		}
		printf("****************************\n");
		return true;
	}

	case 6:
		__do_dump_code = !__do_dump_code;
		printf("code dumping: %u\n", __do_dump_code);
		return true;
	}

	return false;
}

bool CPU::run()
{
	return run_block_jit();
}

bool CPU::run_test()
{
	volatile uint32_t *v1 = (volatile uint32_t *)0x1000;
	volatile uint32_t *v2 = (volatile uint32_t *)0x100001000;

	*v1;
	*v2;

	//printf("dirty: map0=%d map1=%d val0=%d val1=%d\n", mmu().is_page_dirty((hva_t)v1), mmu().is_page_dirty((hva_t)v2), *v1, *v2);
	*v1 = 1;
	//printf("dirty: map0=%d map1=%d val0=%d val1=%d\n", mmu().is_page_dirty((hva_t)v1), mmu().is_page_dirty((hva_t)v2), *v1, *v2);


	return true;
}

void CPU::invalidate_translations()
{
	_txln_mgr.invalidate_all();
	invalidate_virtual_mappings_all();
}

void CPU::invalidate_translation_phys(gpa_t phys_addr)
{
	_txln_mgr.invalidate_region(phys_addr);
	invalidate_virtual_mappings_all();
}

void CPU::invalidate_translation_virt(gva_t virt_addr)
{
	_txln_mgr.invalidate_all();
	invalidate_virtual_mappings_current();
}

void CPU::invalidate_virtual_mappings_all()
{
	block_txln_cache.invalidate_dirty();
}

void CPU::invalidate_virtual_mappings(int context)
{
	block_txln_cache.invalidate_dirty();
}

void CPU::invalidate_virtual_mappings_current()
{
	block_txln_cache.invalidate_dirty();
}

void CPU::invalidate_virtual_mapping(int context, gva_t va)
{
	block_txln_cache.invalidate_entry(va >> 2);
}

void CPU::invalidate_virtual_mapping_current(gva_t va)
{
	block_txln_cache.invalidate_entry(va >> 2);
}

void CPU::switch_virtual_mappings(int context)
{
	jit_state.block_txln_cache = block_txln_cache.ptr();
}

void CPU::handle_irq_raised()
{
	jit_state.exit_chain = 1;
}

const char* CPU::disassemble_address(uint8_t isa, gva_t va)
{
	static char decode_data[128];
	Decode *decode = new (decode_data) aarch64::aarch64_decode();

	AddressTranslationContext atc;

	if (mmu_strategy.enabled()) {
		atc.privilege = AddressTranslationPrivilege::SUPERVISOR;
		atc.type = AddressTranslationType::FETCH;

		if (!guest_mmu.translate(va, atc)) {
			return "<txln fail>";
		}

		if (atc.result != AddressTranslationResult::OK) {
			printf("XXX %p\n", va);
			return "<txln fault>";
		}
	} else {
		atc.pa = va;
	}

	//decode_instruction_phys(isa, atc.pa, (Decode *) decode_data);

	decode->decode(isa, atc.pa, (uint8_t *) guest_phys_to_vm_virt(atc.pa));

	return trace().disasm().disassemble(va, (const uint8_t *) decode_data);
	//return "???";
}
