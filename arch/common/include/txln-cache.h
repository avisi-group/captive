/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <bitset>

namespace captive {
	namespace arch {

		template<typename inner_type_t, uint64_t cache_size>
		class Cache {
		public:

			Cache()
			{
				invalidate_all();
			}

			inline inner_type_t *ptr()
			{
				return entries;
			}

			inline inner_type_t *entry_ptr(uint64_t entry_idx)
			{
				dirty_pages.set((entry_idx % cache_size) >> cache_bits);
				return &entries[entry_idx % cache_size];
			}

			void invalidate_all()
			{
				for (uint64_t i = 0; i < cache_size; ++i) {
					entry_ptr_clean(i)->invalidate();
				}

				dirty_pages.reset();
			}

			void invalidate_dirty()
			{
				if (dirty_pages.none()) return;

				for (uint32_t i = 0; i < dirty_pages.size(); ++i) {
					if (dirty_pages.test(i)) {
						for (uint64_t entry = i * cache_entry_count; entry < (i + 1) * cache_entry_count; ++entry) {
							entry_ptr_clean(entry)->invalidate();
						}
					}
				}

				dirty_pages.reset();
			}

			void invalidate_entry(uint64_t entry_idx)
			{
				entry_ptr_clean(entry_idx)->invalidate();
			}

		private:
			static constexpr uint32_t cache_bits = 12;
			static constexpr uint32_t cache_page_count = cache_size >> cache_bits;
			static constexpr uint32_t cache_entry_count = 1 << cache_bits;

			inner_type_t entries[cache_size];
			std::bitset<cache_page_count> dirty_pages;

			inline inner_type_t *entry_ptr_clean(uint64_t entry_idx)
			{
				return &entries[entry_idx % cache_size];
			}
		};
	}
}
