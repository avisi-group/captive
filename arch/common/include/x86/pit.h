/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

#define PIT_PORT 0x61

namespace captive {
	namespace arch {
		namespace x86 {

			class PIT {
			public:
				void initialise_oneshot(uint16_t ticks);

				void start();
				void stop();

				inline unsigned int expired() const
				{
					uint8_t expired;
					asm volatile("inb $0x61, %0" : "=a"(expired));

					return !(expired & 0x20);
				}
			};

			extern PIT pit;
		}
	}
}
