/* SPDX-License-Identifier: MIT */

#pragma once

#include <define.h>
#include <lib/map.h>

namespace captive {
	namespace arch {
		namespace jit {
			class Translation;

			template<unsigned int RegionBits = 12, unsigned int AlignmentBits = 2 >
			class TranslationManager {
			public:
				TranslationManager();
				~TranslationManager();

				void register_translation(gpa_t pa, Translation *txln);
				Translation *lookup_translation(gpa_t pa);

				bool invalidate_all();
				bool invalidate_region(gpa_t pa);

				void collect_garbage();
			private:
				void add_garbage(Translation *txln);

				constexpr uint64_t pa_to_region_base(gpa_t pa) const
				{
					return(uint64_t) pa >> RegionBits;
				}

				class RegionContainer {
				public:
					static constexpr uint64_t ENTRIES_IN_REGION = (1 << RegionBits) >> AlignmentBits;
					static constexpr uint64_t CACHE_LINE_BYTES = 64;
					static constexpr uint64_t ENTRIES_IN_CACHE_LINE = CACHE_LINE_BYTES / 8;
					static constexpr uint64_t BITMAP_WORDS = (ENTRIES_IN_REGION / ENTRIES_IN_CACHE_LINE) / 64;

					RegionContainer(TranslationManager& parent);
					~RegionContainer();

					void register_translation(gpa_t pa, Translation *txln)
					{
						translation_map_[pa_to_region_offset(pa) >> AlignmentBits] = txln;
					}

					Translation *lookup_translation(gpa_t pa) const
					{
						return translation_map_[pa_to_region_offset(pa) >> AlignmentBits];
					}

					bool invalidate_all();
				private:
					TranslationManager& _parent;

					constexpr uint64_t pa_to_region_offset(gpa_t pa) const
					{
						return(uint64_t) pa & ((1ull << RegionBits) - 1);
					}

					/*constexpr uint64_t pa_to_bitmap_word(gpa_t pa) const
					{
						return 0;
					}*/

					__attribute__((aligned(64))) Translation *translation_map_[ENTRIES_IN_REGION];
					//uint64_t translation_bitmap_[BITMAP_WORDS];
				};

				lib::Map<uint64_t, RegionContainer *> _region_map;
				lib::List<Translation *> _destruction_queue;
			};
		}
	}
}
