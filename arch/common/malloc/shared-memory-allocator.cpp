/* SPDX-License-Identifier: MIT */

#include <malloc/shared-memory-allocator.h>

using namespace captive::arch::malloc;

void *SharedMemoryAllocator::alloc(size_t size)
{
	uint64_t addr;
	asm volatile ("out %2, $0xff" : "=a"(addr) : "D"(size), "a"(10));

	return(void *) addr;
}

void *SharedMemoryAllocator::realloc(void *p, size_t new_size)
{
	uint64_t addr;
	asm volatile ("out %3, $0xff" : "=a"(addr) : "D"(p), "S"(new_size), "a"(11));
	return(void *) addr;
}

void SharedMemoryAllocator::free(void *p)
{
	asm volatile ("out %1, $0xff" : : "D"(p), "a"(12));
}

namespace captive {
	namespace arch {
		namespace malloc {
			SharedMemoryAllocator shmem_alloc;
		}
	}
}
