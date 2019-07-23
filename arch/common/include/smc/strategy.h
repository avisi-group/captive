/* SPDX-License-Identifier: MIT */
#pragma once

#include <smc/noop.h>
#include <smc/via-virt-mapping.h>
#include <smc/tvas.h>
#include <mmu/strategy/strategy.h>

namespace captive {
	namespace arch {
		namespace smc {
			using SMCStrategyType = captive::arch::mmu::strategy::MMUStrategyType::SMCStrategyType;
			extern SMCStrategyType smc_strategy;
		}
	}
}
