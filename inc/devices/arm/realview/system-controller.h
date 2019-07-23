/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>
#include <chrono>

namespace captive {
	namespace devices {
		namespace timers {
			class TickSource;
		}

		namespace arm {
			namespace realview {

				class SystemController : public Primecell {
				public:

					enum ControllerIndex {
						SYS_CTRL0,
						SYS_CTRL1
					};

					SystemController(ControllerIndex index);

					std::string name() const override
					{
						return "system-controller";
					}

					bool read(uint64_t off, uint8_t len, uint64_t& data) override;
					bool write(uint64_t off, uint8_t len, uint64_t data) override;

				private:
					ControllerIndex index;
					uint32_t cr;
				};
			}
		}
	}
}
