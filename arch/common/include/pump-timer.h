/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {

		class PumpTimer {
		public:

			static void initialise(volatile uint64_t *value_ptr)
			{
				value_ptr_ = value_ptr;
			}

			static uint64_t read()
			{
				return *value_ptr_;
			}

		private:
			static volatile uint64_t *value_ptr_;
		};
	}
}
