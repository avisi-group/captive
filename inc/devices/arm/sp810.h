/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>
#include <chrono>

namespace captive {
	namespace devices {
		namespace timers {
			class TimerManager;
		}

		namespace arm {
			class SP810 : public Primecell
			{
			public:
				SP810(timers::TimerManager& timer_manager);
				virtual ~SP810();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				std::string name() const { return "sp810"; }

			private:
				typedef std::chrono::high_resolution_clock clock_t;
				typedef std::chrono::duration<uint32_t, std::ratio<1, 24000000> > tick_24MHz_t;
				typedef std::chrono::duration<uint32_t, std::ratio<1, 100> > tick_100Hz_t;

				timers::TimerManager& _timer_manager;

				uint32_t leds, lockval, colour_mode;
				uint32_t cfgdata1, cfgdata2;
			};
		}
	}
}
