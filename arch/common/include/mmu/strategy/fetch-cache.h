/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace mmu {
			namespace strategy {

				template<int CACHE_SIZE = 8192 >
				class FetchCache {
				private:

					struct fetch_cache_entry {
						uint64_t tag, val;
					} packed;

				public:

					void invalidate()
					{
						for (unsigned long i = 0; i < CACHE_SIZE; i++) {
							_cache[i].tag = 0xf0f0f0f0f0f0f0f0;
						}
					}

					void invalidate_gva(gva_t virtual_address)
					{
						uint64_t page_index = virtual_address >> 12;

						fetch_cache_entry ce = get_cache_entry(page_index);
						if (ce.tag == page_index >> 12) {
							ce.tag = 0xf0f0f0f0f0f0f0f0;
						}
					}

					bool translate(uint64_t virtual_address, uint64_t& physical_address)
					{
						uint64_t page_index = virtual_address >> 12;

						const fetch_cache_entry& ce = get_cache_entry(page_index);
						if (ce.tag == page_index >> 12) {
							physical_address = ce.val | (virtual_address & 0xfffull);
							return true;
						}

						return false;
					}

					void update(uint64_t virtual_address, uint64_t physical_address)
					{
						uint64_t page_index = virtual_address >> 12;

						fetch_cache_entry& ce = get_cache_entry(page_index);
						ce.tag = page_index;
						ce.val = physical_address & ~0xfffull;
					}

				private:

					const fetch_cache_entry& get_cache_entry(uint64_t page_index) const
					{
						uint64_t cache_idx = page_index % CACHE_SIZE;
						return _cache[cache_idx];
					}

					fetch_cache_entry& get_cache_entry(uint64_t page_index)
					{
						uint64_t cache_idx = page_index % CACHE_SIZE;
						return _cache[cache_idx];
					}

					fetch_cache_entry _cache[CACHE_SIZE];
				};

				extern FetchCache fetch_cache;
			}
		}
	}
}
