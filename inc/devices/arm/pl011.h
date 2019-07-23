/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>
#include <deque>
#include <atomic>
#include <thread>
#include <mutex>

#define IRQ_TXINTR (1 << 5)
#define IRQ_RXINTR (1 << 4)

namespace captive {
	namespace devices {
		namespace irq {
			class IRQLineBase;
		}

		namespace io {
			class UART;
		}

		namespace arm {

			class PL011 : public Primecell {
			public:
				PL011(irq::IRQLineBase& irq, io::UART& uart);
				virtual ~PL011();

				void start_reading();
				void stop_reading();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				virtual std::string name() const
				{
					return "pl011";
				}

				void enqueue(uint8_t ch);

			private:
				irq::IRQLineBase& _irq;
				io::UART& _uart;

				uint32_t control_word;
				uint32_t baud_rate, fractional_baud, line_control;
				uint32_t irq_mask;

				std::atomic<uint32_t> irq_status;

				uint32_t flag_register;
				uint32_t rsr, ifl;

				std::deque<uint32_t> fifo;
				std::mutex fifo_lock;

				bool terminate_read_thread;
				std::thread *read_thread;

				void update_irq();

				inline void raise_tx_irq()
				{
					irq_status |= IRQ_TXINTR;
					update_irq();
				}

				inline void raise_rx_irq()
				{
					irq_status |= IRQ_RXINTR;
					update_irq();
				}

				static void read_thread_proc(PL011 *obj);
			};
		}
	}
}
