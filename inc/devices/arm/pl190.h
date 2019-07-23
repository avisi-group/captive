/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>
#include <devices/irq/irq-controller.h>
#include <atomic>

namespace captive {
	namespace devices {
		namespace arm {

			class PL190 : public Primecell, public irq::IRQController<irq::IRQLineBase, 32u> {
			public:
				PL190(irq::IRQLineBase& irq, irq::IRQLineBase& fiq);
				virtual ~PL190();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				virtual std::string name() const
				{
					return "pl190";
				}

			protected:
				void irq_raised(irq::IRQLineBase& line) override;
				void irq_rescinded(irq::IRQLineBase& line) override;

			private:
				irq::IRQLineBase& irq;
				irq::IRQLineBase& fiq;

				std::atomic<uint32_t> irq_status, soft_status;
				uint32_t mask, fiq_select;
				uint32_t default_vector_address;

				uint32_t priority, prev_priority[17], prio_mask[18];
				uint32_t vector_addrs[16];
				uint8_t vector_ctrls[16];

				inline uint32_t get_irq_status() const
				{
					return(irq_status | soft_status) & mask & ~fiq_select;
				}

				inline uint32_t get_fiq_status() const
				{
					return(irq_status | soft_status) & mask & fiq_select;
				}

				uint32_t read_var();
				void write_var();

				void update_vectors();
				void update_lines();
			};
		}
	}
}
