/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace mmu {
			struct PageFaultContext;
		}

		namespace smc {

			class CoreSMC {
			public:
				bool initialise();

				void mark_page_translated(gpa_t page);
				void handle_page_fault(mmu::PageFaultContext& ctx);
			};

			extern CoreSMC core_smc;
		}
	}
}
