/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace malloc {

			class Allocator {
			public:
				virtual void *alloc(size_t size) = 0;
				virtual void *calloc(size_t nmemb, size_t elemsize);
				virtual void *realloc(void *p, size_t new_size) = 0;
				virtual void free(void *p) = 0;
				virtual uint64_t used() const = 0;
			};
		}
	}
}
