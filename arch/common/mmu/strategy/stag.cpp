/* SPDX-License-Identifier: MIT */

#include <mmu/strategy/stag.h>
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

bool STagStrategy::initialise()
{
	printf("initialising stag strategy...\n");

	__wrmsr(0xc0000101, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE));
	__wrmsr(0xc0000102, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE)); // Kernel GS Base

	return true;
}

void STagStrategy::enable()
{
	_enabled = true;
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate();
}

void STagStrategy::disable()
{
	_enabled = false;
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate();
}

template<bool PRIVILEGED>
void STagStrategy::invalidate()
{
	fetch_cache.invalidate();
	host_mmu.flush_all<false>();
	captive::arch::CPU::get_active_cpu()->invalidate_virtual_mappings_all();
}

template void STagStrategy::invalidate<true>();

template<bool PRIVILEGED>
void STagStrategy::invalidate_gva(gva_t)
{
	invalidate();
}

bool STagStrategy::translate(gva_t va, AddressTranslationContext& ctx)
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

x86_pte *STagStrategy::get_or_create_pte(uint64_t page_table, uint64_t address)
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

void STagStrategy::handle_page_fault(PageFaultContext& context)
{
	fatal("XXX\n");
}

hpa_t STagStrategy::allocate_page_table()
{
	void *page_table_virt = captive::arch::malloc::page_alloc.alloc_page();
	if (page_table_virt == nullptr) {
		fatal("unable to allocate page table");
	}

	__fast_zero_page(page_table_virt);
	return vm_virt_to_phys(page_table_virt);
}
