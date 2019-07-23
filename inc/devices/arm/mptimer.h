/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>
#include <devices/timers/timer-manager.h>

namespace captive {
	namespace devices {
		namespace irq {
			class IRQLineBase;
		}

		namespace arm {

			class MPTimer : public Device, public timers::TimerSink {
			public:
				MPTimer(timers::TimerManager& timer_manager, irq::IRQLineBase& irq);
				virtual ~MPTimer();

				std::string name() const override
				{
					return "mptimer";
				}

				uint32_t size() const override
				{
					return 0x100;
				}

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				void timer_expired(uint64_t ticks) override;

			private:
				timers::TimerManager& timer_manager;
				irq::IRQLineBase& irq;

				bool enabled, auto_reload, irq_enabled;
				uint8_t prescale;
				uint32_t load, val, isr;
				uint64_t start;

				void update_irq();
			};
		}
	}
}
