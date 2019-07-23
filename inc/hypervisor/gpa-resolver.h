/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace hypervisor {

		class GPAResolver {
		public:
			bool resolve_gpa(gpa_t addr, void *& out_addr) const;
		};
	}
}
