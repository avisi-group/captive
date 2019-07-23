/* SPDX-License-Identifier: MIT */

#include <smc/core-smc.h>
#include <mmu/strategy/strategy.h>
#include <smc/strategy.h>
#include <mmu/host-mmu.h>
#include <mmu/host-vma.h>
#include <mmu/x86-mmu-structures.h>
#include <set>
#include <printf.h>
#include <cpu.h>

using namespace captive::arch::smc;
using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

bool CoreSMC::initialise()
{
	return true;
}

void CoreSMC::mark_page_translated(gpa_t page)
{
	hva_t corresponding_page = (hva_t) guest_phys_to_vm_virt(page);
	MappingTarget tgt;

	if (!host_mmu.current_vma().get_mapping(corresponding_page, tgt)) {
		printf("va=%p\n", corresponding_page);
		fatal("xx get mapping failed\n");
	}

	tgt.allow_write = false;

	if (!host_mmu.current_vma().update_mapping(corresponding_page, tgt)) {
		fatal("update mapping failed\n");
	}

	host_mmu.current_vma().flush(corresponding_page);
	smc_strategy.mark_page_translated(page);
}

void CoreSMC::handle_page_fault(mmu::PageFaultContext& ctx)
{
	hva_t corresponding_page = ctx.va;

	if (corresponding_page < (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE) || corresponding_page > (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE + 0x1000000000lu)) {
		return;
	}

	MappingTarget tgt;
	if (!host_mmu.current_vma().get_mapping(corresponding_page, tgt)) {
		printf("va=%p\n", corresponding_page);
		ctx.result = PageFaultResult::ABORT;
		return;
	}

	tgt.allow_write = true;

	if (!host_mmu.current_vma().update_mapping(corresponding_page, tgt)) {
		fatal("update mapping failed\n");
	}

	host_mmu.current_vma().flush(corresponding_page);

	captive::arch::CPU::get_active_cpu()->invalidate_translation_phys(tgt.pa - VM_PHYS_GPM_BASE);

	ctx.result = mmu::PageFaultResult::CONTINUE;
}
