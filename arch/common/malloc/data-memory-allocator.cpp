/* SPDX-License-Identifier: MIT */

#include <malloc/data-memory-allocator.h>

extern "C" {
	void *dlmalloc(size_t);
	void *dlrealloc(void *, size_t);
	void dlfree(void *);

	struct mallinfo {
		size_t arena; /* non-mmapped space allocated from system */
		size_t ordblks; /* number of free chunks */
		size_t smblks; /* always 0 */
		size_t hblks; /* always 0 */
		size_t hblkhd; /* space in mmapped regions */
		size_t usmblks; /* maximum total allocated space */
		size_t fsmblks; /* always 0 */
		size_t uordblks; /* total allocated space */
		size_t fordblks; /* total free space */
		size_t keepcost; /* releasable (via malloc_trim) space */
	};

	struct mallinfo dlmallinfo(void);
}

using namespace captive::arch::malloc;

void *DataMemoryAllocator::alloc(size_t size)
{
	return dlmalloc(size);
}

void *DataMemoryAllocator::realloc(void *p, size_t new_size)
{
	return dlrealloc(p, new_size);
}

void DataMemoryAllocator::free(void *p)
{
	dlfree(p);
}

uint64_t DataMemoryAllocator::used() const
{
	return dlmallinfo().uordblks;
}

namespace captive {
	namespace arch {
		namespace malloc {
			DataMemoryAllocator data_alloc;
		}
	}
}
