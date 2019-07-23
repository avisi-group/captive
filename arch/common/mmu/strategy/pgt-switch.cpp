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

extern safepoint_t cpu_safepoint;

using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

template<bool PCID>
bool PageTableSwitchStrategy<PCID>::initialise()
{
	printf("mmu: initialising page table switch strategy...\n");

	__wrmsr(0xc0000101, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE));
	__wrmsr(0xc0000102, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE)); // Kernel GS Base

	_disabled_zone = host_mmu.current_vma().shallow_clone();
	_zones[0] = host_mmu.current_vma().shallow_clone();
	_zones[1] = host_mmu.current_vma().shallow_clone();
	_zones[2] = host_mmu.current_vma().shallow_clone();
	_zones[3] = host_mmu.current_vma().shallow_clone();

	printf("zones:\n");
	for (int i = 0; i < 4; i++) {
		printf("  zone %u: %p\n", i, _zones[i]->get_pml4());
	}

	host_mmu.activate_vma(*_disabled_zone);
	return true;
}

template<bool PCID>
static inline uint64_t cr3_value(uint64_t pml4, int zone)
{
	return pml4 | 0x8000000000000000ull | (unsigned long long) zone;
	//return pml4;
}

template<bool PCID>
void PageTableSwitchStrategy<PCID>::enable()
{
	_enabled = true;
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate();

	asm volatile("movq %0, %%fs:0x70" ::"r"(cr3_value<PCID>((uint64_t) _zones[0]->get_pml4(), 0)));
	asm volatile("movq %0, %%fs:0x78" ::"r"(cr3_value<PCID>((uint64_t) _zones[1]->get_pml4(), 1)));
	asm volatile("movq %0, %%fs:0x80" ::"r"(cr3_value<PCID>((uint64_t) _zones[2]->get_pml4(), 2)));
	asm volatile("movq %0, %%fs:0x88" ::"r"(cr3_value<PCID>((uint64_t) _zones[3]->get_pml4(), 3)));

	host_mmu.activate_vma(*_zones[0]);
	host_mmu.flush_all();
	asm volatile("movb %0, %%fs:0x68" ::"r"((uint8_t) 0));
}

template<bool PCID>
void PageTableSwitchStrategy<PCID>::disable()
{
	_enabled = false;
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate();
}

template<bool PCID>
template<bool PRIVILEGED>
void PageTableSwitchStrategy<PCID>::invalidate()
{
	for (int zoneIndex = 0; zoneIndex < 4; zoneIndex++) {
		x86_pml4e *base = (x86_pml4e *) vm_phys_to_virt(_zones[zoneIndex]->get_pml4());

		for (int tableEntryIndex = 0; tableEntryIndex < 0x100; tableEntryIndex++) {
			base[tableEntryIndex].not_present.present = 0;
		}
	}

	fetch_cache.invalidate();
	host_mmu.flush_all<PRIVILEGED>();
	captive::arch::CPU::get_active_cpu()->invalidate_virtual_mappings_all();
}

template void PageTableSwitchStrategy<false>::invalidate<true>();
template void PageTableSwitchStrategy<false>::invalidate<false>();

template<bool PCID>
template<bool PRIVILEGED>
void PageTableSwitchStrategy<PCID>::invalidate_gva(gva_t va)
{
	for (int zoneIndex = 0; zoneIndex < 4; zoneIndex++) {
		x86_pml4e *base = (x86_pml4e *) vm_phys_to_virt(_zones[zoneIndex]->get_pml4());

		for (int tableEntryIndex = 0; tableEntryIndex < 0x100; tableEntryIndex++) {
			base[tableEntryIndex].not_present.present = 0;
		}
	}

	fetch_cache.invalidate();
	host_mmu.flush_all<PRIVILEGED>();
	captive::arch::CPU::get_active_cpu()->invalidate_virtual_mappings_all();
}

template void PageTableSwitchStrategy<false>::invalidate_gva<true>(gva_t);
template void PageTableSwitchStrategy<false>::invalidate_gva<false>(gva_t);
template void PageTableSwitchStrategy<true>::invalidate_gva<true>(gva_t);
template void PageTableSwitchStrategy<true>::invalidate_gva<false>(gva_t);

template<bool PCID>
bool PageTableSwitchStrategy<PCID>::translate(gva_t va, AddressTranslationContext& ctx)
{
	if (!_enabled) {
		ctx.pa = va;
		ctx.result = AddressTranslationResult::OK;
		return true;
	} else {
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

template<bool PCID>
void PageTableSwitchStrategy<PCID>::handle_page_fault(PageFaultContext& context)
{
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

	x86_pte *pte = &((x86_pte *) vm_phys_to_virt(pde->page_table.actual_base_address()))[(context.va >> 12) & 0x1ff];

	// The PTE is now ready to be used.

	// Recreate the faulting guest virtual address

	uint8_t zone;
	asm volatile("movb %%fs:0x68, %0" : "=r"(zone));

	gva_t guest_va = context.va;
	switch (zone) {
	case 0: break;
	case 1: guest_va += 0x0000800000000000ull;
		break;
	case 2: guest_va += 0xffff000000000000ull;
		break;
	case 3: guest_va += 0xffff800000000000ull;
		break;
	case 255: if (_enabled) fatal("WUH-WAH");
		break;
	default: printf("zone=%u\n", zone);
		fatal("invalid zone");
	}

	//printf("FAULT: PC=%lx, HVA=%p, GVA=%p, ZONE=%u, PML4=%p (reason=%x, pte=%lx @ %p)\n", read_pc(), context.va, guest_va, zone, context.vma->get_pml4(), context.reason, pte->value, pte);

	AddressTranslationContext ctx;
	ctx.privilege = (context.type == PageFaultAccessType::USER_READ || context.type == PageFaultAccessType::USER_WRITE) ? AddressTranslationPrivilege::USER : AddressTranslationPrivilege::SUPERVISOR;
	ctx.type = (context.type == PageFaultAccessType::KERNEL_READ || context.type == PageFaultAccessType::USER_READ) ? AddressTranslationType::READ : AddressTranslationType::WRITE;

	if (!guest_mmu.translate(guest_va, ctx)) {
		fatal("PageTableSwitchStrategy: TRANSLATION FAILED\n");
	}

	if (ctx.result == AddressTranslationResult::FAULT) {
		pte->not_present.present = 0;
		asm volatile("invlpg %0" ::"m"(context.va));

		if (!captive::arch::CPU::get_active_cpu()->handle_mmu_fault(guest_va, ctx)) {
			fatal("PageTableSwitchStrategy: GUEST MMU HANDLE FAILED\n");
		}

		context.result = PageFaultResult::RESET;
		return;
	}

	if (!pte->not_present.present) {
		pte->page.actual_base_address(VM_PHYS_GPM_BASE + ctx.pa);
		pte->page.present = 1;
	}

	pte->page.writable = ctx.type == AddressTranslationType::WRITE;
	pte->page.user = ctx.privilege == AddressTranslationPrivilege::USER;
	pte->page.execute_disable = 1;

	//printf("PA=%lx, PTE=%lx\n", ctx.pa, pte->value);

	//context.vma->flush(context.va);
	asm volatile("invlpg %0" ::"m"(context.va));

	context.result = PageFaultResult::CONTINUE;
}

template<bool PCID>
void PageTableSwitchStrategy<PCID>::invalidate_context_id(int context_id)
{
	fatal("X");
}

template<bool PCID>
void PageTableSwitchStrategy<PCID>::invalidate_page(gpa_t page)
{
	fatal("X");
}

template<bool PCID>
void PageTableSwitchStrategy<PCID>::set_context_id(int context_id)
{
	fatal("X");
}

template<bool PCID>
HostVMA* PageTableSwitchStrategy<PCID>::get_zone(int zone) const
{
	if (zone < 0 || zone > 3) {
		fatal("invalid zone");
	}

	return _zones[zone];
}

template<bool PCID>
hpa_t PageTableSwitchStrategy<PCID>::get_pml4_for_zone(int zone) const
{
	if (zone < 0 || zone > 3) {
		fatal("invalid zone");
	}

	return _zones[zone]->get_pml4();
}

template<bool PCID>
hpa_t PageTableSwitchStrategy<PCID>::allocate_page_table()
{
	void *page_table_virt = captive::arch::malloc::page_alloc.alloc_page();
	if (page_table_virt == nullptr) {
		fatal("unable to allocate page table");
	}

	__fast_zero_page(page_table_virt);
	return vm_virt_to_phys(page_table_virt);
}

template class PageTableSwitchStrategy<false>;
template class PageTableSwitchStrategy<true>;
