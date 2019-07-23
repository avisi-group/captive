/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <smc/tvas.h>

namespace captive {
	namespace arch {
		namespace mmu {
			struct AddressTranslationContext;
			struct PageFaultContext;

#define TVAS_SEGMENT_BITS       31ull
#define TVAS_SEGMENT_MASK       ((1ull << TVAS_SEGMENT_BITS) - 1ull)
#define TVAS_SEGMENT_BYTES      (1ull << TVAS_SEGMENT_BITS)
			//#define TVAS_SEGMENT_PAGES      (TVAS_SEGMENT_PAGES / 4096ull)
#define TVAS_CACHE_PAGES        32ull
#define TVAS_NR_CACHE_ENTRIES   ((TVAS_CACHE_PAGES * 4096ull) / 8ull)

			namespace strategy {

				class TVAS {
				public:
					typedef captive::arch::smc::TVAS SMCStrategyType;

					bool initialise();

					template<bool PRIVILEGED = true >
					void invalidate();

					template<bool PRIVILEGED = true >
					void invalidate_gva(gva_t va);

					void handle_page_fault(PageFaultContext& context);

					void enable();
					void disable();

					bool enabled() const
					{
						return _enabled;
					}

					bool translate(gva_t va, AddressTranslationContext& ctx);

					template<bool PRIVILEGED>
					void invalidate_segment(uint64_t segment_index);

					void writeprotect_segments();

				private:
					hpa_t allocate_page_table();

					bool _enabled;
					uint64_t *_cache;
					HostVMA *_hvma;
				};
			}
		}
	}
}
