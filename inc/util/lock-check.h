/* SPDX-License-Identifier: MIT */
#pragma once

#include <mutex>

namespace captive {
	namespace util {

		class checked_mutex {
		public:

			inline void lock()
			{
				mtx.lock();
			}

			inline void unlock()
			{
				mtx.unlock();
			}

		private:
			std::mutex mtx;
		};
	}
}
