/* SPDX-License-Identifier: MIT */

#include <smc/via-virt-mapping.h>
#include <mmu/strategy/strategy.h>
#include <printf.h>
#include <cpu.h>

using namespace captive::arch::smc;

bool ViaVirtMapping::initialise()
{
	return true;
}

void ViaVirtMapping::mark_page_translated(gpa_t page)
{
}

void ViaVirtMapping::handle_page_fault(mmu::PageFaultContext& ctx)
{
	fatal("NOPE\n");
}

void ViaVirtMapping::notify_all_invalidated()
{
}

void ViaVirtMapping::notify_page_invalidated(gpa_t page)
{
}

void ViaVirtMapping::notify_page_written(gpa_t page)
{
	captive::arch::CPU::get_active_cpu()->invalidate_translation_phys(page);
}
