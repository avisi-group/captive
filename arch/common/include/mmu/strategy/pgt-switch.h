/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <smc/noop.h>

namespace captive {
	namespace arch {
		namespace mmu {
			struct AddressTranslationContext;
			struct PageFaultContext;

			namespace strategy {

				template<bool PCID>
				class PageTableSwitchStrategy {
				public:
					typedef captive::arch::smc::NoOp SMCStrategyType;

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

					void invalidate_page(gpa_t page);
					void invalidate_context_id(int context_id);
					void set_context_id(int context_id);

					HostVMA *get_zone(int zone) const;
					hpa_t get_pml4_for_zone(int zone) const;

				private:
					bool _enabled;
					HostVMA *_zones[4];
					HostVMA *_disabled_zone;

					hpa_t allocate_page_table();
				};
			}
		}
	}
}
