/* SPDX-License-Identifier: MIT */

#include <smc/tvas.h>
#include <mmu/strategy/strategy.h>
#include <printf.h>
#include <cpu.h>

using namespace captive::arch::smc;

bool TVAS::initialise()
{
	return true;
}

void TVAS::mark_page_translated(gpa_t page)
{
#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_TVAS
	if (captive::arch::mmu::strategy::mmu_strategy.enabled()) {
		//captive::arch::mmu::strategy::mmu_strategy.writeprotect_segments();
	}
#endif
}

void TVAS::handle_page_fault(mmu::PageFaultContext& ctx)
{
	fatal("NOPE\n");
}
