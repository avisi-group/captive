/* SPDX-License-Identifier: MIT */
#pragma once

#include <malloc/allocator.h>

namespace captive {
	namespace arch {
		namespace malloc {

			class SharedMemoryAllocator : public Allocator {
			public:
				void *alloc(size_t size) override;
				void *realloc(void *p, size_t new_size) override;
				void free(void *p) override;

				uint64_t used() const override
				{
					return 0;
				}
			};
		}
	}
}
