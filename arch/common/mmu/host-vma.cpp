/* SPDX-License-Identifier: MIT */

#include <mmu/host-vma.h>
#include <mmu/x86-mmu-structures.h>
#include <malloc/page-allocator.h>
#include <printf.h>
#include <string.h>

using namespace captive::arch::mmu;
using namespace captive::arch::malloc;

HostVMA::HostVMA() : pml4(alloc_page_table())
{

}

HostVMA* HostVMA::shallow_clone() const
{
	auto new_vma = new HostVMA();

	x86_pml4e *from = (x86_pml4e *) vm_phys_to_virt(get_pml4());
	x86_pml4e *to = (x86_pml4e *) vm_phys_to_virt(new_vma->get_pml4());
	for (unsigned int idx = 0; idx < 0x200; idx++) {
		to[idx].value = from[idx].value;
	}

	return new_vma;
}

void HostVMA::insert_mapping(hva_t va, const MappingTarget& target)
{
	x86_pte *pte;
	if (get_pte<true>(va, &pte)) {
		if (pte->not_present.present) {
			//printf("%p %p %p\n", va, pte, pte->value);
			//fatal("replace");
			return;
		}

		pte->value = 0;
		pte->page.present = 1;
		pte->page.user = target.allow_user;
		pte->page.writable = target.allow_write;
		pte->page.execute_disable = target.deny_exec;
		pte->page.actual_base_address(target.pa);
	} else {
		fatal("NOPE");
	}
}

void HostVMA::remove_mapping(hva_t va)
{
	x86_pte *pte;
	if (get_pte<false>(va, &pte)) {
		pte->not_present.present = 0;
	}
}

bool HostVMA::get_mapping(hva_t va, MappingTarget& target)
{
	x86_pml4e *pml4e = &((x86_pml4e *) vm_phys_to_virt(pml4))[(va >> 39) & 0x1ff];
	if (!pml4e->not_present.present) {
		printf("4 NP\n");
		return false;
	}

	x86_pdpte *pdpte = &((x86_pdpte *) vm_phys_to_virt(pml4e->page_directory_ptr.actual_base_address()))[(va >> 30) & 0x1ff];
	if (!pdpte->not_present.present) {
		printf("3 NP\n");
		return false;
	}

	if (pdpte->page1gb.size) {
		target.pa = pdpte->page1gb.actual_base_address();
		target.granularity = MappingTargetGranularity::Granularity1G;
		target.allow_write = pdpte->page1gb.writable;
		target.allow_user = pdpte->page1gb.user;
		return true;
	}

	x86_pde *pdte = &((x86_pde *) vm_phys_to_virt(pdpte->page_directory.actual_base_address()))[(va >> 21) & 0x1ff];
	if (!pdte->not_present.present) {
		printf("2 NP\n");
		return false;
	}

	if (pdte->page2mb.size) {
		target.pa = pdte->page2mb.actual_base_address();
		target.granularity = MappingTargetGranularity::Granularity2M;
		target.allow_write = pdte->page2mb.writable;
		target.allow_user = pdte->page2mb.user;
		return true;
	}

	x86_pte *pte = &((x86_pte *) vm_phys_to_virt(pdte->page_table.actual_base_address()))[(va >> 12) & 0x1ff];

	if (!pte->not_present.present) {
		printf("1 NP\n");
		return false;
	}

	target.pa = pte->page.actual_base_address();
	target.granularity = MappingTargetGranularity::Granularity4K;
	target.allow_write = pte->page.writable;
	target.allow_user = pte->page.user;
	target.deny_exec = pte->page.execute_disable;
	target.user_flags[0] = !!(pte->page.ignored1 & 1);
	target.user_flags[1] = !!(pte->page.ignored1 & 2);
	target.user_flags[2] = !!(pte->page.ignored1 & 4);

	return true;
}

bool HostVMA::update_mapping(hva_t va, const MappingTarget& target)
{
	x86_pml4e *pml4e = &((x86_pml4e *) vm_phys_to_virt(pml4))[(va >> 39) & 0x1ff];
	if (!pml4e->not_present.present) {
		return false;
	}

	x86_pdpte *pdpte = &((x86_pdpte *) vm_phys_to_virt(pml4e->page_directory_ptr.actual_base_address()))[(va >> 30) & 0x1ff];
	if (!pdpte->not_present.present) {
		return false;
	}

	if (pdpte->page1gb.size) {
		if (target.granularity != MappingTargetGranularity::Granularity1G) {
			return false;
		}

		pdpte->page1gb.actual_base_address(target.pa);
		pdpte->page1gb.writable = target.allow_write;
		pdpte->page1gb.user = target.allow_user;
		return true;
	}

	x86_pde *pdte = &((x86_pde *) vm_phys_to_virt(pdpte->page_directory.actual_base_address()))[(va >> 21) & 0x1ff];
	if (!pdte->not_present.present) {
		return false;
	}

	if (pdte->page2mb.size) {
		if (target.granularity != MappingTargetGranularity::Granularity2M) {
			return false;
		}

		pdte->page2mb.actual_base_address(target.pa);
		pdte->page2mb.writable = target.allow_write;
		pdte->page2mb.user = target.allow_user;
		return true;
	}

	x86_pte *pte = &((x86_pte *) vm_phys_to_virt(pdte->page_table.actual_base_address()))[(va >> 12) & 0x1ff];

	if (target.granularity != MappingTargetGranularity::Granularity4K) {
		return false;
	}

	pte->page.actual_base_address(target.pa);
	pte->page.writable = target.allow_write;
	pte->page.user = target.allow_user;
	return true;
}

gpa_t HostVMA::alloc_page_table()
{
	void *page_table_virt = page_alloc.alloc_page();
	if (page_table_virt == nullptr) {
		fatal("unable to allocate page table");
	}

	__fast_zero_page(page_table_virt);
	return vm_virt_to_phys(page_table_virt);
}

template<bool CREATE>
bool HostVMA::get_pte(hva_t va, x86_pte **pte)
{
	x86_pml4e *pml4e = &((x86_pml4e *) vm_phys_to_virt(pml4))[(va >> 39) & 0x1ff];
	if (!pml4e->not_present.present) {
		if (CREATE) {
			gpa_t new_pdpt = alloc_page_table();
			pml4e->value = 0;

			pml4e->page_directory_ptr.base_address = new_pdpt >> 12;
			pml4e->page_directory_ptr.present = 1;
			pml4e->page_directory_ptr.user = 1;
			pml4e->page_directory_ptr.writable = 1;
		} else {
			return false;
		}
	}

	x86_pdpte *pdpte = &((x86_pdpte *) vm_phys_to_virt(pml4e->page_directory_ptr.actual_base_address()))[(va >> 30) & 0x1ff];
	if (!pdpte->not_present.present) {
		if (CREATE) {
			pdpte->value = 0;

			gpa_t new_pdt = alloc_page_table();
			pdpte->page_directory.base_address = new_pdt >> 12;
			pdpte->page_directory.present = 1;
			pdpte->page_directory.user = 1;
			pdpte->page_directory.writable = 1;
		} else {
			return false;
		}
	}

	if (pdpte->page1gb.size) {
		return false;
	}

	x86_pde *pdte = &((x86_pde *) vm_phys_to_virt(pdpte->page_directory.actual_base_address()))[(va >> 21) & 0x1ff];
	if (!pdte->not_present.present) {
		if (CREATE) {
			gpa_t new_pt = alloc_page_table();
			pdte->value = 0;

			pdte->page_table.base_address = new_pt >> 12;
			pdte->page_table.present = 1;
			pdte->page_table.user = 1;
			pdte->page_table.writable = 1;
		} else {
			return false;
		}
	}

	if (pdte->page2mb.size) {
		return false;
	}

	*pte = &((x86_pte *) vm_phys_to_virt(pdte->page_table.actual_base_address()))[(va >> 12) & 0x1ff];
	return true;
}
