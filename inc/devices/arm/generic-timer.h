/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>
#include <devices/irq/irq-line.h>
#include <devices/timers/timer-manager.h>

namespace captive {
	namespace devices {
		namespace arm {

			class GenericTimer {
			public:
				GenericTimer(timers::TimerManager& timer_manager, irq::IRQLineBase& irq);
				virtual ~GenericTimer();

				Device& control_region()
				{
					return Control;
				}

			private:
				timers::TimerManager& timer_manager;
				irq::IRQLineBase& irq;

				class _Control : public Device {
				public:

					_Control(GenericTimer& owner) : _owner(owner)
					{
					}

					std::string name() const override
					{
						return "generic-timer-control";
					}

					uint32_t size() const override
					{
						return 0x1000;
					}

					bool read(uint64_t off, uint8_t len, uint64_t& data) override;
					bool write(uint64_t off, uint8_t len, uint64_t data) override;

				private:
					GenericTimer& _owner;
				} Control;
			};
		}
	}
}
