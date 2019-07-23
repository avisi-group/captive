/* SPDX-License-Identifier: MIT */

#include <mmu/host-mmu.h>
#include <mmu/host-vma.h>
#include <mmu/x86-mmu-structures.h>
#include <mmu/strategy/strategy.h>
#include <smc/core-smc.h>
#include <printf.h>
#include <assert.h>
#include <x86/rdtsc-timer.h>

#include "cpu.h"

using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;
using namespace captive::arch::smc;

HostMMU captive::arch::mmu::host_mmu;

bool HostMMU::initialise()
{
	_initial_vma = new HostVMA();

	x86_pml4e *template_pml4 = (x86_pml4e *) vm_phys_to_virt(VM_PHYS_PML4_0);
	x86_pml4e *target_pml4 = (x86_pml4e *) vm_phys_to_virt(_initial_vma->get_pml4());

	// Initialise the upper mappings for the initial VMA
	for (unsigned int entry_index = 0x100; entry_index < 0x200; entry_index++) {
		target_pml4[entry_index].value = template_pml4[entry_index].value;
	}

	// Populate GPM mapping
	MappingTarget tgt;
	tgt.granularity = MappingTargetGranularity::Granularity4K;
	tgt.allow_user = true;
	tgt.allow_write = true;
	tgt.deny_exec = true;

	printf("populating gpm mapping...\n");
	for (uint64_t page = 0; page < (40ull * 1024ull * 1024ull * 1024ull); page += 0x1000ull) {
		tgt.pa = VM_PHYS_GPM_BASE + page;
		_initial_vma->insert_mapping(VM_VIRT_SPLIT + tgt.pa, tgt);
	}

	activate_vma(*_initial_vma);
	_initial_vma->flush_all();

	return true;
}

template<bool PRIVILEGED>
void HostMMU::activate_vma(const HostVMA& vma)
{
	if (PRIVILEGED) {
		asm volatile("mov %0, %%cr3" ::"r"(vma.get_pml4()) : "memory");
	} else {
		asm volatile("int $0x61" ::"D"(vma.get_pml4()));
	}

	_current_vma = (HostVMA *) & vma;
}

template void HostMMU::activate_vma<true>(const HostVMA& vma);
template void HostMMU::activate_vma<false>(const HostVMA& vma);

#define PF_PRESENT  (1u << 0)
#define PF_WRITE  (1u << 1)
#define PF_USER_MODE (1u << 2)
#define PF_FETCH  (1u << 4)
#define PF_PKEY   (1u << 5)

extern "C" int handle_pagefault(struct mcontext *mctx, uint64_t va)
{
	//uint64_t start = captive::arch::x86::rdtsc_timer.count();

	//captive::arch::CPU::get_active_cpu()->inc_performance_counter_a();

	PageFaultContext ctx;
	ctx.va = va;
	ctx.result = PageFaultResult::ABORT;
	ctx.rip = mctx->rip;

	// TEMP HACK
	//ctx.r14 = mctx->r14;

	asm volatile("mov %%cr3, %0" : "=r"(ctx.cr3));

	//printf("MMU FAULT %08x %p\n", mctx->extra, va);

	if (mctx->extra & PF_PKEY) {
		fatal("PING PONG");
	}

	if (mctx->extra & PF_WRITE) {
		ctx.type = (mctx->extra & PF_USER_MODE) ? PageFaultAccessType::USER_WRITE : PageFaultAccessType::KERNEL_WRITE;
	} else {
		ctx.type = (mctx->extra & PF_USER_MODE) ? PageFaultAccessType::USER_READ : PageFaultAccessType::KERNEL_READ;
	}

	if (!(mctx->extra & PF_PRESENT)) {
		ctx.reason = PageFaultReason::NOT_PRESENT;
	} else if (mctx->extra & PF_PKEY) {
		ctx.reason = PageFaultReason::PKEY;
	} else if (mctx->extra & PF_FETCH) {
		ctx.reason = PageFaultReason::NO_EXECUTE;
	} else if (mctx->extra & PF_WRITE) {
		ctx.reason = PageFaultReason::READ_ONLY;
	} else if (mctx->extra & PF_USER_MODE) {
		ctx.reason = PageFaultReason::SUPERVISOR_ONLY;
	} else {
		ctx.reason = PageFaultReason::UNKNOWN;
	}

	// Work out which region the fault occurred in
	if (va < VM_VIRT_SPLIT) {
		// This faulted in the lower half of the address space, so let's dispatch
		// the fault to the appropriate MMU strategy.

		// Invoke the MMU strategy to handle the fault.
		mmu_strategy.handle_page_fault(ctx);
	} else {
		// This faulted in the upper half of the address space, so notify the
		// self-modifying code detector.
		core_smc.handle_page_fault(ctx);
	}

	/*uint64_t end = captive::arch::x86::rdtsc_timer.count();
	
	captive::arch::CPU::get_active_cpu()->cpu_data().insns_executed += captive::arch::x86::rdtsc_timer.ticks_to_nsec(end - start);*/

	// Work out what to do with the result of the fault.
	switch (ctx.result) {
	case PageFaultResult::ABORT:
		// The page fault could not be handled.
		printf("page fault va=%p\n", va);
		dump_mcontext(mctx);
		fatal("page fault could not be resolved\n");

	case PageFaultResult::CONTINUE:
		// Execution should continue from the point of fault.
		return 0;

	case PageFaultResult::RESET:
		// Execution should continue from the safe point.
		return 1;

	default:
		// Unhandled response code.
		printf("page fault va=%p\n", va);
		fatal("unhandled page fault result\n");
	}
}
