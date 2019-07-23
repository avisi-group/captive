/* SPDX-License-Identifier: MIT */

#include <malloc/allocator.h>
#include <string.h>

using namespace captive::arch::malloc;

void *Allocator::calloc(size_t nmemb, size_t elemsize)
{
	void *p = alloc(nmemb * elemsize);
	if (!p) return NULL;

	bzero(p, nmemb * elemsize);
	return p;
}
