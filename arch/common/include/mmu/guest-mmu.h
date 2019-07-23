/* SPDX-License-Identifier: MIT */
#pragma once

#include <mmu/aarch64-mmu.h>

namespace captive {
	namespace arch {
		namespace mmu {
			using GuestMMUType = AArch64MMU;
			extern GuestMMUType guest_mmu;
		}
	}
}
