/* SPDX-License-Identifier: MIT */

#include <mmu/strategy/mpk.h>
#include <mmu/strategy/strategy.h>
#include <mmu/strategy/fetch-cache.h>
#include <mmu/host-mmu.h>
#include <mmu/host-vma.h>
#include <mmu/guest-mmu.h>
#include <mmu.h>
#include <cpu.h>
#include <printf.h>
#include <safepoint.h>
#include <mmu/x86-mmu-structures.h>

extern safepoint_t cpu_safepoint;

using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

static inline void __wrpkru(uint32_t pk)
{
	asm volatile("wrpkru" ::"a"(pk), "c"((uint32_t) 0), "d"((uint32_t) 0) : "memory");
}

bool MPKStrategy::initialise()
{
	printf("initialising mpk strategy...\n");

	__wrmsr(0xc0000101, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE));
	__wrmsr(0xc0000102, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE)); // Kernel GS Base

	// Disable all protection keys, except zero.
	__wrpkru(~3u);

	return true;
}

void MPKStrategy::enable()
{
	// Populate protection key bit patterns
	asm volatile("movq %0, %%fs:0x70" ::"i"(0xfffffff0));
	asm volatile("movq %0, %%fs:0x78" ::"i"(0xffffffcc));
	asm volatile("movq %0, %%fs:0x80" ::"i"(0xffffff3c));
	asm volatile("movq %0, %%fs:0x88" ::"i"(0xfffffcfc));

	/*asm volatile("movq %0, %%fs:0x70" :: "i"(0xfffffff0));
	asm volatile("movq %0, %%fs:0x78" :: "i"(0xfffffff0));
	asm volatile("movq %0, %%fs:0x80" :: "i"(0xfffffff0));
	asm volatile("movq %0, %%fs:0x88" :: "i"(0xfffffff0));*/

	_enabled = true;
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate();
}

void MPKStrategy::disable()
{
	_enabled = false;
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate();
}

template<bool PRIVILEGED>
void MPKStrategy::invalidate()
{
	printf("INVALIDATE\n");
	x86_pml4e *base = (x86_pml4e *) vm_phys_to_virt(host_mmu.current_vma().get_pml4()); //_zones[zoneIndex]->get_pml4());
	for (int tableEntryIndex = 0; tableEntryIndex < 0x100; tableEntryIndex++) {
		base[tableEntryIndex].not_present.present = 0;
	}

	fetch_cache.invalidate();
	host_mmu.flush_all<false>();
	captive::arch::CPU::get_active_cpu()->invalidate_virtual_mappings_all();
}

template void MPKStrategy::invalidate<true>();

template<bool PRIVILEGED>
void MPKStrategy::invalidate_gva(gva_t)
{
	invalidate();
}

bool MPKStrategy::translate(gva_t va, AddressTranslationContext& ctx)
{
	if (!enabled()) {
		ctx.pa = va;
		ctx.result = AddressTranslationResult::OK;
		return true;
	}

	if (ctx.type == AddressTranslationType::FETCH) {
		if (fetch_cache.translate(va, ctx.pa)) {
			ctx.result = AddressTranslationResult::OK;
			return true;
		}
	}

	if (!guest_mmu.translate(va, ctx)) {
		fatal("MPKStrategy: TRANSLATE FAILED\n");
	}

	if (ctx.type == AddressTranslationType::FETCH && ctx.result == AddressTranslationResult::OK) {
		fetch_cache.update(va, ctx.pa);
	}

	return true;
}

x86_pte *MPKStrategy::get_or_create_pte(uint64_t page_table, uint64_t address)
{
	x86_pml4e *pml4e = &((x86_pml4e *) vm_phys_to_virt(page_table))[(address >> 39) & 0x1ff];
	if (!pml4e->not_present.present) {
		if (!pml4e->page_directory_ptr.base_address) {
			pml4e->value = 0;

			pml4e->page_directory_ptr.actual_base_address(allocate_page_table());
			pml4e->page_directory_ptr.present = 1;
			pml4e->page_directory_ptr.writable = 1;
			pml4e->page_directory_ptr.user = 1;
		} else {
			pml4e->page_directory_ptr.present = 1;

			x86_pdpte *pdp_table = ((x86_pdpte *) vm_phys_to_virt(pml4e->page_directory_ptr.actual_base_address()));
			for (int i = 0; i < 0x200; i++) {
				pdp_table[i].not_present.present = 0;
			}
		}
	}

	x86_pdpte *pdpte = &((x86_pdpte *) vm_phys_to_virt(pml4e->page_directory_ptr.actual_base_address()))[(address >> 30) & 0x1ff];
	if (!pdpte->not_present.present) {
		if (!pdpte->page_directory.base_address) {
			pdpte->value = 0;

			pdpte->page_directory.actual_base_address(allocate_page_table());
			pdpte->page_directory.present = 1;
			pdpte->page_directory.writable = 1;
			pdpte->page_directory.user = 1;
		} else {
			pdpte->page_directory.present = 1;

			x86_pde *pd_table = ((x86_pde *) vm_phys_to_virt(pdpte->page_directory.actual_base_address()));
			for (int i = 0; i < 0x200; i++) {
				pd_table[i].not_present.present = 0;
			}
		}
	}

	x86_pde *pde = &((x86_pde *) vm_phys_to_virt(pdpte->page_directory.actual_base_address()))[(address >> 21) & 0x1ff];
	if (!pde->not_present.present) {
		if (!pde->page_table.base_address) {
			pde->value = 0;

			pde->page_table.actual_base_address(allocate_page_table());
			pde->page_table.present = 1;
			pde->page_table.writable = 1;
			pde->page_table.user = 1;
		} else {
			pde->page_table.present = 1;

			x86_pte *pt_table = ((x86_pte *) vm_phys_to_virt(pde->page_table.actual_base_address()));
			for (int i = 0; i < 0x200; i++) {
				pt_table[i].not_present.present = 0;
			}
		}
	}

	return &((x86_pte *) vm_phys_to_virt(pde->page_table.actual_base_address()))[(address >> 12) & 0x1ff];
}

static inline uint32_t __rdpkru()
{
	uint32_t pk, edx;
	asm volatile("rdpkru" : "=a"(pk), "=d"(edx) : "c"((uint32_t) 0));

	return pk;
}

static uint32_t __last;

void MPKStrategy::handle_page_fault(PageFaultContext& context)
{
	//printf("MPK PAGE FAULT @ %p: %p (%x, %08x): ", context.rip, context.va, context.reason, __rdpkru());

	if (context.reason == PageFaultReason::NOT_PRESENT) {
		//printf("NOT PRESENT\n");
	} else if (context.reason == PageFaultReason::READ_ONLY) {
		//printf("WRITE TO READ-ONLY\n");
	} else if (context.reason == PageFaultReason::PKEY) {
		printf("PKEY VIOLATION\n");
	}

	x86_pte *pte = get_or_create_pte(context.cr3 & ~0xfffull, context.va);
	//printf("PTE @ %p=%016lx\n", pte, pte->value);

	gva_t guest_va = context.va;

	uint32_t normalised_pkru = ~__rdpkru();
	uint32_t lz = __builtin_clz(normalised_pkru);
	//printf("NPKRU = %08x, LZ=%u\n", normalised_pkru, lz);

	if (lz != __last) {
		__last = lz;
		//printf("WOO %u\n", lz);
	}

	bool usermode = false;
	uint32_t segment;
	switch (lz) {
		// KERNEL
	case 28: segment = 0;
		break;
	case 26: segment = 1;
		break;
	case 24: segment = 2;
		break;
	case 22: segment = 3;
		break;
		// USER
	case 20: segment = 0;
		usermode = true;
		break;
	case 18: segment = 1;
		usermode = true;
		break;
	case 16: segment = 2;
		usermode = true;
		break;
	case 14: segment = 3;
		usermode = true;
		break;
	default: printf("NPKRU=%08x\n", normalised_pkru);
		fatal("MPK: INVALID PKRU");
	}

	switch (segment) {
	case 0: break;
	case 1: guest_va += 0x0000800000000000ull;
		break;
	case 2: guest_va += 0xffff000000000000ull;
		break;
	case 3: guest_va += 0xffff800000000000ull;
		break;
	default: printf("segment=%u\n", segment);
		fatal("MPK: INVALID SEGMENT");
	}

	/*printf("SEG=%u, GVA=%p == %p\n", segment, guest_va, context.r14);*/

	AddressTranslationContext ctx;
	ctx.privilege = usermode ? AddressTranslationPrivilege::USER : AddressTranslationPrivilege::SUPERVISOR;
	ctx.type = (context.type == PageFaultAccessType::KERNEL_READ || context.type == PageFaultAccessType::USER_READ) ? AddressTranslationType::READ : AddressTranslationType::WRITE;

	if (!guest_mmu.translate(guest_va, ctx)) {
		fatal("MPKStrategy: TRANSLATION FAILED\n");
	}

	if (ctx.result == AddressTranslationResult::FAULT) {
		printf("GUEST FAULT @ PC=%p\n", read_pc());
		pte->not_present.present = 0;
		asm volatile("invlpg %0" ::"m"(context.va));

		if (!captive::arch::CPU::get_active_cpu()->handle_mmu_fault(guest_va, ctx)) {
			fatal("MPKStrategy: GUEST MMU HANDLE FAILED\n");
		}

		context.result = PageFaultResult::RESET;
		return;
	}

	//printf("GPA=%p\n", ctx.pa);

	if (!pte->not_present.present) {
		pte->page.actual_base_address(VM_PHYS_GPM_BASE + ctx.pa);
		pte->page.present = 1;
	}

	pte->page.writable = ctx.type == AddressTranslationType::WRITE;
	pte->page.user = 1; // ctx.privilege == AddressTranslationPrivilege::USER;
	pte->page.execute_disable = 1;
	pte->page.prot_key = segment + (usermode ? 5u : 1u);

	asm volatile("invlpg %0" ::"m"(context.va));

	//printf("PTE @ %p=%016lx\n", pte, pte->value);

	context.result = PageFaultResult::CONTINUE;
}

hpa_t MPKStrategy::allocate_page_table()
{
	void *page_table_virt = captive::arch::malloc::page_alloc.alloc_page();
	if (page_table_virt == nullptr) {
		fatal("unable to allocate page table");
	}

	__fast_zero_page(page_table_virt);
	return vm_virt_to_phys(page_table_virt);
}
