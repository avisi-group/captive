/* SPDX-License-Identifier: MIT */

#include <malloc/page-allocator.h>
#include <printf.h>
#include <string.h>

namespace captive {
	namespace arch {
		namespace malloc {
			PageAllocator page_alloc;
		}
	}
}

static inline int log2_floor(int v)
{
	uint32_t r;
	asm("\tbsr %1, %0\n" : "=r"(r) : "r"(v));
	return r;
}

static inline int log2_ceil(int v)
{
	uint32_t r;
	asm("\tbsr %1, %0\n" : "=r"(r) : "r"(v));

	return r + (v & (v - 1) ? 1 : 0);
}

using namespace captive::arch::malloc;

PageAllocator::PageAllocator() : _zone(NULL), _zone_size(0)
{
	for (int i = 0; i < MAX_ORDER; i++) {
		_free_areas[i].next = NULL;
	}
}

void PageAllocator::init(uintptr_t virt_base, uintptr_t phys_base, size_t zone_size)
{
	_zone = (void *) virt_base;
	_zone_phys = (void *) phys_base;
	_zone_size = zone_size;

	FreeArea *current_block = &_free_areas[MAX_ORDER - 1];

	uint32_t block_size = (1 << (MAX_ORDER - 1)) * 4096;

	printf("page-allocator: init: va=%p, pa=%p, zone_size=%lx, block_size=%x\n", virt_base, phys_base, zone_size, block_size);

	for (int i = 0; i < zone_size / block_size; i++) {
		current_block->next = (FreeArea *) (virt_base + (i * block_size));
		current_block = current_block->next;
	}

	current_block->next = NULL;
}

void *PageAllocator::alloc_pages(int nr_pages)
{
	if (!_zone) return NULL;

	int requested_order = log2_ceil(nr_pages);
	int next_avail_order;
	for (next_avail_order = requested_order; next_avail_order < MAX_ORDER; next_avail_order++) {
		if (_free_areas[next_avail_order].next != NULL) {
			break;
		}
	}

	if (next_avail_order == MAX_ORDER) fatal("out of memory");

	for (int i = next_avail_order; i > requested_order; i--) {
		split_order(i);
	}

	return _free_areas[requested_order].pop();
}

void PageAllocator::free_pages(void *p, int nr_pages)
{
	int max_order = log2_floor(nr_pages);
	int remaining = nr_pages - (1 << max_order);

	assert(max_order < MAX_ORDER);

	FreeArea *area = (FreeArea *) p;
	_free_areas[max_order].push(area);

	int max_order_block_size = 4096 * (1 << max_order);

	FreeArea *remaining_area = (FreeArea *) ((uint64_t) p + max_order_block_size);
	for (int i = 0; i < remaining; i++) {
		_free_areas[0].push(remaining_area);

		remaining_area = (FreeArea *) ((uint64_t) remaining_area + 4096);
	}
}

void PageAllocator::split_order(int order)
{
	assert(order > 0);

	// Set up some useful variables.
	FreeArea *order_to_split = &_free_areas[order];
	FreeArea *order_to_receive = &_free_areas[order - 1];

	assert(order_to_split->next);

	uint64_t order_to_split_block_size = 4096 * (1 << order);
	uint64_t order_to_receive_block_size = 4096 * (1 << (order - 1));

	// Grab hold of the area we are going to split, and work out it's new buddy.
	FreeArea *area_to_split = order_to_split->pop();
	FreeArea *buddy = (FreeArea *) ((uint64_t) area_to_split + order_to_receive_block_size);

	order_to_receive->push(area_to_split);
	order_to_receive->push(buddy);
}

void PageAllocator::dump()
{
	for (int i = 0; i < MAX_ORDER; i++) {
		printf("order %u:", i);

		FreeArea *area = _free_areas[i].next;
		while (area) {
			printf("  %p ", area);
			area = area->next;
		}
		printf("\n");
	}
}
