/* SPDX-License-Identifier: MIT */
#pragma once

#include <malloc/code-memory-allocator.h>
#include <malloc/data-memory-allocator.h>
#include <malloc/shared-memory-allocator.h>

namespace captive {
	namespace arch {
		namespace malloc {
			extern DataMemoryAllocator data_alloc;
			extern CodeMemoryAllocator code_alloc;
			extern SharedMemoryAllocator shmem_alloc;
		}
	}
}
