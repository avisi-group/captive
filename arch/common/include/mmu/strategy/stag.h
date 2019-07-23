/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <smc/noop.h>

namespace captive {
	namespace arch {
		namespace mmu {
			struct AddressTranslationContext;
			struct PageFaultContext;
			struct x86_pte;

			namespace strategy {

				class STagStrategy {
				public:
					typedef smc::NoOp SMCStrategyType;

					bool initialise();

					template<bool PRIVILEGED = true >
					void invalidate();

					template<bool PRIVILEGED = true >
					void invalidate_gva(gva_t);

					void handle_page_fault(PageFaultContext& context);

					void enable();
					void disable();

					bool enabled() const
					{
						return _enabled;
					}

					bool translate(gva_t va, AddressTranslationContext& ctx);

				private:
					x86_pte *get_or_create_pte(uint64_t page_table, uint64_t address);
					hpa_t allocate_page_table();
					bool _enabled;
				};
			}
		}
	}
}
