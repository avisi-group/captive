/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>

namespace captive {
	namespace devices {
		namespace gfx {
			class VirtualScreen;
		}

		namespace irq {
			class IRQLineBase;
		}

		namespace arm {

			class PL110 : public Primecell {
			public:

				enum DeviceVariant {
					V_PL110,
					V_PL111,
				};

				PL110(gfx::VirtualScreen& screen, irq::IRQLineBase& irq, DeviceVariant v = V_PL110);
				virtual ~PL110();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				inline gfx::VirtualScreen& screen() const
				{
					return _screen;
				}

				virtual std::string name() const
				{
					return "pl110";
				}

			private:
				void update_control();
				void update_irq();

				gfx::VirtualScreen& _screen;
				irq::IRQLineBase& _irq;

				union {
					uint32_t data;

					struct {
						uint8_t en : 1;
						uint8_t bpp : 3;
						uint8_t bw : 1;
						uint8_t tft : 1;
						uint8_t mono8 : 1;
						uint8_t dual : 1;
						uint8_t bgr : 1;
						uint8_t bebo : 1;
						uint8_t bepo : 1;
						uint8_t lcd_pwr : 1;
						uint8_t lcd_vcomp : 2;
						uint8_t rsvd1 : 2;
						uint8_t watermark : 1;
						uint32_t rsvd0 : 15;
					} __packed fields;
				} control;

				uint32_t lcd_timing[4];

				uint32_t upper_fbbase, lower_fbbase;
				uint32_t isr, irq_mask;

				uint32_t palette[128];
			};
		}
	}
}
