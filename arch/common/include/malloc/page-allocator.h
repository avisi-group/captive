/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace malloc {

#define MAX_ORDER 17

			class PageAllocator {
			public:
				PageAllocator();

				void init(uintptr_t virt_base, uintptr_t phys_base, size_t zone_size);

				inline void *alloc_page()
				{
					return alloc_pages(1);
				}
				void *alloc_pages(int nr_pages);
				void free_pages(void *p, int nr_pages);

			private:
				void *_zone;
				void *_zone_phys;
				size_t _zone_size;
				uint32_t _zone_pages;

				struct FreeArea {
					FreeArea *next;

					inline void push(FreeArea *area)
					{
						area->next = next;
						next = area;
					}

					inline FreeArea *pop()
					{
						FreeArea *tmp = next;
						next = tmp->next;
						return tmp;
					}
				};

				FreeArea _free_areas[MAX_ORDER];

				void split_order(int order);
				void dump();
			};

			extern PageAllocator page_alloc;
		}
	}
}
