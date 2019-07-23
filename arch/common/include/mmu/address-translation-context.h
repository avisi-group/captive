/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace mmu {

			enum class AddressTranslationPrivilege {
				USER, SUPERVISOR
			};

			enum class AddressTranslationType {
				READ, WRITE, FETCH
			};

			enum class AddressTranslationResult {
				FAULT,
				OK
			};

			struct AddressTranslationContext {
				AddressTranslationPrivilege privilege;
				AddressTranslationType type;
				AddressTranslationResult result;
				gpa_t pa;
				uint64_t private_data;
			};
		}
	}
}
