/* SPDX-License-Identifier: MIT */

#include <malloc/code-memory-allocator.h>
#include <malloc/data-memory-allocator.h>
#include <malloc/page-allocator.h>
#include <printf.h>

using namespace captive::arch::malloc;

namespace captive {
	namespace arch {
		namespace malloc {
			CodeMemoryAllocator code_alloc;
			extern DataMemoryAllocator data_alloc;
		}
	}
}

void *CodeMemoryAllocator::alloc(size_t size)
{
	return data_alloc.alloc(size);
}

void *CodeMemoryAllocator::realloc(void *p, size_t new_size)
{
	return data_alloc.realloc(p, ALIGN(new_size, 16));
}

void CodeMemoryAllocator::free(void *p)
{
	return data_alloc.free(p);
}

uint64_t CodeMemoryAllocator::used() const
{
	return data_alloc.used();
}
