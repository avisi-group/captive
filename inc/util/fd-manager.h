/* SPDX-License-Identifier: MIT */
#pragma once

namespace captive {
	namespace util {

		class FDManager {
		public:
			void start();
			void stop();

		private:
			int _stop_event;
		};
	}
}
