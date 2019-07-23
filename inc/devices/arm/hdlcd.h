/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>

namespace captive {
	namespace devices {
		namespace gfx {
			class VirtualScreen;
		}

		namespace irq {
			class IRQLineBase;
		}

		namespace arm {

			class HDLCD : public Device {
			public:
				HDLCD(gfx::VirtualScreen& screen, irq::IRQLineBase& irq);
				virtual ~HDLCD();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				uint32_t size() const override
				{
					return 0x1000;
				}

				inline gfx::VirtualScreen& screen() const
				{
					return _screen;
				}

				virtual std::string name() const
				{
					return "hdlcd";
				}

			private:
				gfx::VirtualScreen& _screen;
				irq::IRQLineBase& _irq;
			};
		}
	}
}
