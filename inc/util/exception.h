/* SPDX-License-Identifier: MIT */
#pragma once

#include <string>

namespace captive {
	namespace util {

		class Exception {
		public:

			Exception(const std::string& message) : _message(message)
			{
			}

			const std::string& message() const
			{
				return _message;
			}

		private:
			const std::string _message;
		};

		class NotImplementedException : public Exception {
		public:

			NotImplementedException() : Exception("not implemented")
			{
			}
		};

	}
}
