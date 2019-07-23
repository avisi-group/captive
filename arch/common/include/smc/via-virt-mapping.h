/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace mmu {
			struct PageFaultContext;
		}

		namespace smc {

			class ViaVirtMapping {
			public:
				bool initialise();
				void mark_page_translated(gpa_t page);
				void notify_all_invalidated();
				void notify_page_invalidated(gpa_t page);
				void notify_page_written(gpa_t page);
				void handle_page_fault(mmu::PageFaultContext& ctx);
			};
		}
	}
}
