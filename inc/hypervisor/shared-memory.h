/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace hypervisor {

		class SharedMemory {
		public:
			virtual void *allocate(size_t size) = 0;
			virtual void *reallocate(void *p, size_t size) = 0;
			virtual void free(void *p) = 0;
		};
	}
}
