/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>
#include <devices/irq/irq-controller.h>
#include <atomic>

namespace captive {
	namespace devices {
		namespace arm {

			class PL390 : public Primecell, public irq::IRQController<irq::IRQLineBase, 32u> {
			public:
				PL390(irq::IRQLineBase& irq, irq::IRQLineBase& fiq);
				virtual ~PL390();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				virtual std::string name() const
				{
					return "pl390";
				}

			protected:
				void irq_raised(irq::IRQLineBase& line) override;
				void irq_rescinded(irq::IRQLineBase& line) override;

			private:
				irq::IRQLineBase& irq;
				irq::IRQLineBase& fiq;
			};
		}
	}
}
