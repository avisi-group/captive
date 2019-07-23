/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>
#include <chrono>

namespace captive {
	namespace devices {
		namespace timers {
			class TimerManager;
		}

		namespace arm {
			namespace realview {

				class SystemStatusAndControl : public Device {
				public:
					SystemStatusAndControl(timers::TimerManager& timer_manager);
					~SystemStatusAndControl();

					std::string name() const override
					{
						return "sysctl";
					}

					uint32_t size() const override
					{
						return 0x1000;
					}

					bool read(uint64_t off, uint8_t len, uint64_t& data) override;
					bool write(uint64_t off, uint8_t len, uint64_t data) override;

				private:
					typedef std::chrono::high_resolution_clock clock_t;
					typedef std::chrono::duration<uint32_t, std::ratio<1, 24000000> > tick_24MHz_t;
					typedef std::chrono::duration<uint32_t, std::ratio<1, 100> > tick_100Hz_t;

					timers::TimerManager& _timer_manager;
					uint64_t _start_time;

					uint32_t osc[5];

					uint32_t colour_mode, lockval, leds, flags;
				};
			}
		}
	}
}
