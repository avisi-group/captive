/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {

		class Barrier {
		public:
			Barrier() : _ctr(0), _b{0, 0}, _interrupt(0)
			{
			}

			inline void wait(uint32_t my_tid)
			{
				assert(my_tid == 0 || my_tid == 1);

				int ctr = _ctr;
				int val = !ctr;

				_b[my_tid] = val;
				while (_b[!my_tid] != val && !_interrupt) asm("pause");

				_ctr = !ctr;

			}

			inline void interrupt()
			{
				_interrupt = true;
			}

		private:
			uint32_t _ctr;
			volatile bool _b[2];
			volatile bool _interrupt;
		};

		static_assert(sizeof(Barrier) < 32, "Barrier class is oversized");
	}
}
