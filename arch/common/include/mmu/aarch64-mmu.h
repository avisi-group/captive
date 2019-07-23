/* SPDX-License-Identifier: MIT */
#pragma once

#include <mmu/address-translation-context.h>

namespace captive {
	namespace arch {
		namespace mmu {

			class AArch64MMU {
			public:
				bool translate(gva_t va, AddressTranslationContext& ctx);
			};
		}
	}
}
