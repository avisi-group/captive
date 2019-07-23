/* SPDX-License-Identifier: MIT */

#include <mmu/strategy/strategy.h>
#include <mmu/strategy/fetch-cache.h>
#include <mmu/host-mmu.h>
#include <mmu/host-vma.h>
#include <mmu/guest-mmu.h>
#include <mmu/x86-mmu-structures.h>
#include <mmu.h>
#include <cpu.h>
#include <printf.h>
#include <safepoint.h>
#include <malloc/page-allocator.h>
#include <x86/rdtsc-timer.h>

extern safepoint_t cpu_safepoint;

using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

bool TVAS::initialise()
{
	printf("mmu: initialising tvas strategy...\n");

	_cache = (uint64_t *) captive::arch::malloc::page_alloc.alloc_pages(TVAS_CACHE_PAGES);

	_hvma = host_mmu.current_vma().shallow_clone();
	host_mmu.activate_vma(*_hvma);

	__wrmsr(0xc0000101, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE));
	__wrmsr(0xc0000102, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE)); // Kernel GS Base

	for (unsigned long i = 0; i < TVAS_NR_CACHE_ENTRIES; i++) {
		_cache[i] = 0xf0f0f0f0f0f0f0f0;
	}

	return true;
}

void TVAS::enable()
{
	//printf("TVAS ENABLE\n");
	_enabled = true;

	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate<true>();

	__wrmsr(0xc0000101, (uint64_t) (_cache));
	__wrmsr(0xc0000102, (uint64_t) (_cache));
}

void TVAS::disable()
{
	//printf("TVAS DISABLE\n");
	_enabled = false;

	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate<true>();

	__wrmsr(0xc0000101, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE));
	__wrmsr(0xc0000102, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE)); // Kernel GS Base
}

template<bool PRIVILEGED>
void TVAS::invalidate()
{
	//printf("INVALIDATE\n");

	for (unsigned long i = 0; i < TVAS_NR_CACHE_ENTRIES; i++) {
		_cache[i] = 0xf0f0f0f0f0f0f0f0;
	}

	x86_pml4e *base = (x86_pml4e *) vm_phys_to_virt(_hvma->get_pml4());
	for (int tableEntryIndex = 0; tableEntryIndex < 0x100; tableEntryIndex++) {
		base[tableEntryIndex].not_present.present = 0;
	}

	fetch_cache.invalidate();
	host_mmu.flush_all<PRIVILEGED>();
	captive::arch::CPU::get_active_cpu()->invalidate_virtual_mappings_all();
}

template void TVAS::invalidate<true>();
template void TVAS::invalidate<false>();

template<bool PRIVILEGED>
void TVAS::invalidate_gva(gva_t va)
{
	//printf("TVAS INV GVA\n");
	invalidate<PRIVILEGED>();
}

bool TVAS::translate(gva_t va, AddressTranslationContext& ctx)
{
	if (!_enabled) {
		ctx.pa = va;
		ctx.result = AddressTranslationResult::OK;
		return true;
	} else {
		assert(ctx.type == AddressTranslationType::FETCH);

		if (!fetch_cache.translate(va, ctx.pa)) {
			if (!guest_mmu.translate(va, ctx)) {
				fatal("RESOLVE GPA FAILED\n");
			} else {
				if (ctx.result == AddressTranslationResult::OK) {
					fetch_cache.update(va, ctx.pa);
				}
			}
		} else {
			ctx.result = AddressTranslationResult::OK;
		}

		return true;
	}
}

void TVAS::handle_page_fault(PageFaultContext& context)
{
	if (!enabled()) {
		printf("va=%p\n", context.va);
		fatal("PAGE FAULT WHEN MMU NOT ENABLED");
	}

	// Recreate the faulting guest virtual address
	gva_t guest_va = context.va;

	uint64_t cache_tag;
	asm volatile ("movq %%gs:(,%1,8), %0" : "=r"(cache_tag) : "r"((context.va >> TVAS_SEGMENT_BITS)));
	guest_va |= cache_tag << TVAS_SEGMENT_BITS;

	x86_pml4e *pml4e = &((x86_pml4e *) vm_phys_to_virt(context.cr3 & ~0xfffull))[(context.va >> 39) & 0x1ff];
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

	if (!pml4e->page_directory_ptr.writable) {
		pml4e->page_directory_ptr.writable = 1;

		x86_pdpte *pdp_table = ((x86_pdpte *) vm_phys_to_virt(pml4e->page_directory_ptr.actual_base_address()));
		for (int i = 0; i < 0x200; i++) {
			pdp_table[i].page_directory.writable = 0;
		}
	}

	x86_pdpte *pdpte = &((x86_pdpte *) vm_phys_to_virt(pml4e->page_directory_ptr.actual_base_address()))[(context.va >> 30) & 0x1ff];
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

	if (!pdpte->page_directory.writable) {
		pdpte->page_directory.writable = 1;

		x86_pde *pd_table = ((x86_pde *) vm_phys_to_virt(pdpte->page_directory.actual_base_address()));
		for (int i = 0; i < 0x200; i++) {
			pd_table[i].page_table.writable = 0;
		}
	}

	x86_pde *pde = &((x86_pde *) vm_phys_to_virt(pdpte->page_directory.actual_base_address()))[(context.va >> 21) & 0x1ff];
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

	if (!pde->page_table.writable) {
		pde->page_table.writable = 1;

		x86_pte *pt_table = ((x86_pte *) vm_phys_to_virt(pde->page_table.actual_base_address()));
		for (int i = 0; i < 0x200; i++) {
			pt_table[i].page.writable = 0;
		}
	}

	x86_pte *pte = &((x86_pte *) vm_phys_to_virt(pde->page_table.actual_base_address()))[(context.va >> 12) & 0x1ff];

	AddressTranslationContext atc;
	atc.privilege = (context.type == PageFaultAccessType::USER_READ || context.type == PageFaultAccessType::USER_WRITE) ? AddressTranslationPrivilege::USER : AddressTranslationPrivilege::SUPERVISOR;
	atc.type = (context.type == PageFaultAccessType::KERNEL_READ || context.type == PageFaultAccessType::USER_READ) ? AddressTranslationType::READ : AddressTranslationType::WRITE;

	if (!guest_mmu.translate(guest_va, atc)) {
		fatal("PageTableSwitchStrategy: TRANSLATION FAILED\n");
	}

	if (atc.result == AddressTranslationResult::FAULT) {
		pte->not_present.present = 0;
		asm volatile("invlpg %0" ::"m"(context.va));

		if (!captive::arch::CPU::get_active_cpu()->handle_mmu_fault(guest_va, atc)) {
			fatal("PageTableSwitchStrategy: GUEST MMU HANDLE FAILED\n");
		}

		context.result = PageFaultResult::RESET;

		return;
	}

#if 0
	if (is_device(atc.pa)) {
		pte->not_present.present = 0;
		fatal("DEVICE ACCESS @ %p", atc.pa);
	} else {
#endif

		uint64_t oldpte = pte->value;

		if (!pte->not_present.present) {
			pte->page.actual_base_address(VM_PHYS_GPM_BASE + atc.pa);
			pte->page.present = 1;
		}

		pte->page.writable = atc.type == AddressTranslationType::WRITE;
		pte->page.user = atc.privilege == AddressTranslationPrivilege::USER;
		pte->page.execute_disable = 1;
#if 0
	}
#endif

	if (atc.type == AddressTranslationType::WRITE) {
		if ((guest_va & ~0xfffull) == (read_pc() & ~0xfffull)) {
			printf("*** WRITE TO PAGE WE'RE EXECUTING ***\n\r");
		}
		captive::arch::CPU::get_active_cpu()->invalidate_translation_phys(atc.pa);
	}

	context.result = PageFaultResult::CONTINUE;

	if (oldpte != pte->value) {
		asm volatile("invlpg %0" ::"m"(context.va));
	}
}

template<bool PRIVILEGED>
void TVAS::invalidate_segment(uint64_t segment_index)
{
	//printf("INVALIDATE SEGMENT %lu\n", segment_index);

	uint64_t segment_va = segment_index << TVAS_SEGMENT_BITS;

	x86_pml4e *pml4e = &((x86_pml4e *) vm_phys_to_virt(_hvma->get_pml4()))[(segment_va >> 39) & 0x1ff];
	if (!pml4e->not_present.present) {
		return;
	}

	x86_pdpte *pdpte = &((x86_pdpte *) vm_phys_to_virt(pml4e->page_directory_ptr.actual_base_address()))[(segment_va >> 30) & 0x1ff];
	if (pdpte->not_present.present) {
		pdpte->not_present.present = 0;

		host_mmu.flush_range<PRIVILEGED>(segment_va, segment_va + TVAS_SEGMENT_BYTES);
	}
}

void TVAS::writeprotect_segments()
{
	x86_pml4e *base = (x86_pml4e *) vm_phys_to_virt(_hvma->get_pml4());
	for (int tableEntryIndex = 0; tableEntryIndex < 0x100; tableEntryIndex++) {
		base[tableEntryIndex].page_directory_ptr.writable = 0;
	}

	host_mmu.flush_all();
}

template void TVAS::invalidate_segment<true>(uint64_t);
template void TVAS::invalidate_segment<false>(uint64_t);

hpa_t TVAS::allocate_page_table()
{
	void *page_table_virt = captive::arch::malloc::page_alloc.alloc_page();
	if (page_table_virt == nullptr) {
		fatal("unable to allocate page table");
	}

	__fast_zero_page(page_table_virt);
	return vm_virt_to_phys(page_table_virt);
}
