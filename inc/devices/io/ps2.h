/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/keyboard.h>
#include <devices/io/mouse.h>
#include <devices/irq/irq-line.h>
#include <captive.h>

#include <queue>
#include <mutex>

namespace captive {
	namespace devices {
		namespace io {

			class PS2Device {
			public:
				PS2Device(irq::IRQLineBase& irq);

				enum device_type {
					PS2_KEYBOARD,
					PS2_MOUSE
				};

				inline uint32_t read() const
				{
					std::unique_lock<std::mutex> l(process_lock);

					uint32_t v = data_queue.front();
					data_queue.pop();
					if (data_queue.empty()) {
						_irq.rescind();
					}

					//fprintf(stderr, "**** RSP: %08x\n", v);
					return v;
				}

				inline bool data_pending() const
				{
					return data_queue.size() > 0;
				}

				virtual void send_command(uint32_t command) = 0;
				virtual device_type type() const = 0;

				inline void enable_irq()
				{
					irq_enabled = true;
				}

				inline void disable_irq()
				{
					irq_enabled = false;
				}

			protected:

				void clear_queue()
				{
					_irq.rescind();

					while (!data_queue.empty()) {
						data_queue.pop();
					}
				}

				inline void queue_data(uint32_t data)
				{
					data_queue.push(data);
					if (irq_enabled) {
						_irq.raise();
					}
				}

				mutable std::mutex process_lock;

			private:
				irq::IRQLineBase& _irq;
				bool irq_enabled;
				mutable std::queue<uint32_t> data_queue;
			};

			class PS2KeyboardDevice : public PS2Device, public Keyboard {
			public:
				PS2KeyboardDevice(irq::IRQLineBase& irq);

				void send_command(uint32_t command) override;

				device_type type() const override
				{
					return PS2_KEYBOARD;
				}

				void key_down(uint32_t keycode) override;
				void key_up(uint32_t keycode) override;

			private:
				uint32_t last_command;
			};

			class PS2MouseDevice : public PS2Device, public Mouse {
			public:
				PS2MouseDevice(irq::IRQLineBase& irq);

				void send_command(uint32_t command) override;

				device_type type() const override
				{
					return PS2_MOUSE;
				}

				void button_down(uint32_t button_index) override;
				void button_up(uint32_t button_index) override;
				void mouse_move(uint32_t x, uint32_t y) override;

			private:
				void send_update();

				uint32_t last_command;

				uint32_t status, resolution, sample_rate;

				uint32_t last_x, last_y;
				uint32_t button_state;

				int32_t dx, dy;

				bool wrapping_mode;
			};
		}
	}
}
