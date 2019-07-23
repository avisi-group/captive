/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace WatchpointTrigger {

			enum WatchpointTrigger {
				EXECUTION,
				DATA_WRITE,
				DATA_READ_WRITE
			};
		}

		extern void init_memory_watchpoints();
		extern void add_memory_watchpoint(hva_t va, uint8_t size, WatchpointTrigger::WatchpointTrigger trigger);
		extern void remove_memory_watchpoint(hva_t va);

		extern void watchpoints_enable();
		extern void watchpoints_disable();
	}
}