/* SPDX-License-Identifier: MIT */
#pragma once

#include <mutex>
#include <condition_variable>

namespace captive {
	namespace util {

		template<typename retval_t>
		class Completion {
		public:

			Completion() : _complete(false)
			{
			}

			inline void signal(retval_t result)
			{
				std::unique_lock<std::mutex> lock(_m);

				if (_complete) return;

				_result = result;
				_complete = true;

				_cv.notify_all();
			}

			inline retval_t wait()
			{
				std::unique_lock<std::mutex> lock(_m);

				if (_complete) return _result;

				while (!_complete) _cv.wait(lock);

				return _result;
			}

		private:
			bool _complete;
			retval_t _result;
			std::mutex _m;
			std::condition_variable _cv;
		};
	}
}
