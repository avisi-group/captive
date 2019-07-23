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

				class GuestMMUStrategy {
				public:
					typedef smc::NoOp SMCStrategyType;

					bool initialise();

					template<bool PRIVILEGED = true >
					void invalidate();

					template<bool PRIVILEGED = true >
					void invalidate_gva(gva_t);

					void handle_page_fault(const PageFaultContext& context);

					void enable();
					void disable();

					bool enabled() const
					{
						return _enabled;
					}

					bool translate(gva_t va, AddressTranslationContext& ctx);

				private:
					bool _enabled;
				};
			}
		}
	}
}
