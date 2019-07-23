/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>
#include <devices/irq/irq-controller.h>
#include <atomic>

namespace captive {
	namespace devices {
		namespace arm {

			class VersatileSIC : public Device, public irq::IRQController<irq::IRQLineBase, 32u> {
			public:
				VersatileSIC(irq::IRQLineBase& irq);
				virtual ~VersatileSIC();

				virtual bool read(uint64_t off, uint8_t len, uint64_t& data);
				virtual bool write(uint64_t off, uint8_t len, uint64_t data);

				virtual uint32_t size() const
				{
					return 0x1000;
				}

				virtual std::string name() const
				{
					return "sic";
				}

				void irq_raised(irq::IRQLineBase& line) override;
				void irq_rescinded(irq::IRQLineBase& line) override;

			private:
				irq::IRQLineBase& _irq;

				std::atomic<uint32_t> status;
				uint32_t enable_mask;
			};
		}
	}
}
