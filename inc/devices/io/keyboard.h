/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace devices {
		namespace io {

			class Keyboard {
			public:
				virtual void key_down(uint32_t keycode) = 0;
				virtual void key_up(uint32_t keycode) = 0;
			};
		}
	}
}
