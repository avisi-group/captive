/* SPDX-License-Identifier: MIT */
#pragma once
#include <atomic>

namespace captive {
	namespace devices {
		namespace irq {
			class IRQControllerBase;

			class IRQLineBase {
			public:

				IRQLineBase() : _raised(false), _index(0), _controller(NULL)
				{
				}

				void raise();
				void rescind();
				void acknowledge();

				inline bool raised() const
				{
					return _raised;
				}

				inline uint32_t index() const
				{
					return _index;
				}

				inline void attach(IRQControllerBase& controller, uint32_t index)
				{
					_controller = &controller;
					_index = index;
				}

			private:
				std::atomic<bool> _raised;
				uint32_t _index;
				IRQControllerBase *_controller;
			};
		}
	}
}
