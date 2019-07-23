/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace x86 {

			class RDTSCTimer {
			public:
				RDTSCTimer();

				bool init();

				uint64_t count();

				uint64_t ticks_to_nsec(uint64_t ticks);

			private:
				uint64_t _frequency;
				bool calibrate();
			};

			extern RDTSCTimer rdtsc_timer;
		}
	}
}
