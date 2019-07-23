/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>
#include <devices/timers/timer-manager.h>

#include <mutex>
#include <shared_mutex>
#include <atomic>

namespace captive {
	namespace devices {
		namespace irq {
			class IRQLineBase;
		}

		namespace arm {

			class SP804 : public Primecell, public timers::TimerSink {
			public:
				SP804(timers::TimerManager& timer_manager, irq::IRQLineBase& irq);
				virtual ~SP804();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				void timer_expired(uint64_t ticks) override;

				std::string name() const override
				{
					return "sp804";
				}

			private:
				void update_irq();

				class SP804Timer {
				public:
					SP804Timer();

					bool read(uint64_t off, uint8_t len, uint64_t& data);
					bool write(uint64_t off, uint8_t len, uint64_t data);

					inline void owner(SP804& sp804)
					{
						_owner = &sp804;
					}

					inline bool enabled() const
					{
						return _enabled;
					}

					inline bool irq_enabled() const
					{
						return control_reg.bits.int_en;
					}

					inline uint32_t isr() const
					{
						return _isr;
					}

					void tick(uint64_t delta);
				private:
					std::shared_timed_mutex lock;

					SP804 *_owner;
					bool _enabled;

					uint32_t load_value;
					std::atomic<uint32_t> current_value;
					std::atomic<uint32_t> _isr;

					union {
						uint32_t value;

						struct {
							uint8_t one_shot : 1;
							uint8_t size : 1;
							uint8_t prescale : 2;
							uint8_t rsvd : 1;
							uint8_t int_en : 1;
							uint8_t mode : 1;
							uint8_t enable : 1;
						} __packed bits;
					} control_reg;

					void update();
					void init_period();
				};

				SP804Timer timers[2];
				irq::IRQLineBase& irq;
			};
		}
	}
}

