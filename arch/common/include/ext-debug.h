/* SPDX-License-Identifier: MIT */
#pragma once

namespace captive {
	namespace arch {

		enum class ExternalDebugMode {
			None,
			JIT,
			Guest,
			Both
		};

		class ExternalDebugger {
		public:

			ExternalDebugMode mode() const
			{
				return mode_;
			}

		private:
			ExternalDebugMode mode_;
		};
	}
}