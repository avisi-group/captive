/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {

		struct Page {
			uintptr_t phys_addr;
			uint64_t flags;
			uint64_t pad0, pad1;

			inline void *data() const
			{
				return vm_phys_to_virt(phys_addr);
			}
		} packed;
	}
}
