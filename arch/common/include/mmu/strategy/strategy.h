/* SPDX-License-Identifier: MIT */
#pragma once

#include <mmu/address-translation-context.h>
#include <mmu/strategy/softmmu.h>
#include <mmu/strategy/guestmmu.h>
#include <mmu/strategy/pgt-switch.h>
#include <mmu/strategy/tvas.h>
#include <mmu/strategy/mpk.h>
#include <mmu/strategy/stag.h>

namespace captive {
	namespace arch {
		namespace mmu {
			namespace strategy {
#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_GUEST
				using MMUStrategyType = GuestMMUStrategy;
#elif CONFIG_MMU_STRATEGY == MMU_STRATEGY_SOFT
				using MMUStrategyType = SoftMMUStrategy;
#elif CONFIG_MMU_STRATEGY == MMU_STRATEGY_TVAS
				using MMUStrategyType = TVAS;
#elif CONFIG_MMU_STRATEGY == MMU_STRATEGY_PGTSW
				using MMUStrategyType = PageTableSwitchStrategy<true>;
#elif CONFIG_MMU_STRATEGY == MMU_STRATEGY_MPK
				using MMUStrategyType = MPKStrategy;
#elif CONFIG_MMU_STRATEGY == MMU_STRATEGY_STAG
				using MMUStrategyType = STagStrategy;
#else
#error "Unsupported MMU strategy"
#endif

				extern MMUStrategyType mmu_strategy;
			}
		}
	}
}
