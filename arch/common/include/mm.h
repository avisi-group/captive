/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <printf.h>

#include <priv.h>

#define packed __attribute__((packed))

namespace captive {
	namespace arch {
		class MMU;

		class Memory {
			friend class MMU;

		public:
			static void init();

		private:
			Memory();
		};
	}
}
