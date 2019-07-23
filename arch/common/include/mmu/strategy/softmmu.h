/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <smc/noop.h>

#define SOFTMMU_CACHE_PAGES     8ull
#define SOFTMMU_CACHE_BYTES     (SOFTMMU_CACHE_PAGES * 4096ull)
#define SOFTMMU_CACHE_ENTRIES   (SOFTMMU_CACHE_BYTES / 16)
#define SOFTMMU_NR_CACHES       4ull

#define SOFTMMU_OFFSET_TAG      0ull
#define SOFTMMU_OFFSET_VAL      8ull

#define SOFTMMU_KR_INDEX        0ull
#define SOFTMMU_KW_INDEX        1ull
#define SOFTMMU_UR_INDEX        2ull
#define SOFTMMU_UW_INDEX        3ull

#define SOFTMMU_KR_OFFSET_BASE  (SOFTMMU_CACHE_BYTES * SOFTMMU_KR_INDEX)
#define SOFTMMU_KW_OFFSET_BASE  (SOFTMMU_CACHE_BYTES * SOFTMMU_KW_INDEX)
#define SOFTMMU_UR_OFFSET_BASE  (SOFTMMU_CACHE_BYTES * SOFTMMU_UR_INDEX)
#define SOFTMMU_UW_OFFSET_BASE  (SOFTMMU_CACHE_BYTES * SOFTMMU_UW_INDEX)

#define SOFTMMU_KR_OFFSET_TAG   (SOFTMMU_KR_OFFSET_BASE + SOFTMMU_OFFSET_TAG)
#define SOFTMMU_KR_OFFSET_VAL   (SOFTMMU_KR_OFFSET_BASE + SOFTMMU_OFFSET_VAL)
#define SOFTMMU_KW_OFFSET_TAG   (SOFTMMU_KW_OFFSET_BASE + SOFTMMU_OFFSET_TAG)
#define SOFTMMU_KW_OFFSET_VAL   (SOFTMMU_KW_OFFSET_BASE + SOFTMMU_OFFSET_VAL)
#define SOFTMMU_UR_OFFSET_TAG   (SOFTMMU_UR_OFFSET_BASE + SOFTMMU_OFFSET_TAG)
#define SOFTMMU_UR_OFFSET_VAL   (SOFTMMU_UR_OFFSET_BASE + SOFTMMU_OFFSET_VAL)
#define SOFTMMU_UW_OFFSET_TAG   (SOFTMMU_UW_OFFSET_BASE + SOFTMMU_OFFSET_TAG)
#define SOFTMMU_UW_OFFSET_VAL   (SOFTMMU_UW_OFFSET_BASE + SOFTMMU_OFFSET_VAL)

#define VIA_GS

namespace captive {
	namespace arch {
		namespace mmu {
			struct AddressTranslationContext;
			struct PageFaultContext;

			class HostVMA;

			namespace strategy {

				struct softmmu_cache_entry {
					//uint64_t a, b;
					uint64_t tag;
					uint64_t value;
				} packed;

				class SoftMMUStrategy {
				public:
					typedef smc::NoOp SMCStrategyType;

					SoftMMUStrategy() : _cache(nullptr)
					{
					}

					bool initialise();

					template<bool PRIVILEGED = true >
					void invalidate();

					template<bool PRIVILEGED = true >
					void invalidate_gva(gva_t va);

					void handle_page_fault(const PageFaultContext& context);

					void enable()
					{
						_enabled = true;
						invalidate();
						set_gs_cache();
					}

					void disable()
					{
						_enabled = false;
						invalidate();
						set_gs_gpm();
					}

					bool enabled() const
					{
						return _enabled;
					}

					bool translate(gva_t va, AddressTranslationContext& ctx);

				private:
					void set_gs_cache();
					void set_gs_gpm();

					bool _enabled;

					softmmu_cache_entry *_cache;
				};
			}
		}
	}
}
