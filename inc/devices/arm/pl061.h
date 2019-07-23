/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>

namespace captive {
	namespace devices {
		namespace irq {
			class IRQLineBase;
		}

		namespace arm {

			class PL061 : public Primecell {
			public:
				PL061(irq::IRQLineBase& irq);
				virtual ~PL061();

				virtual bool read(uint64_t off, uint8_t len, uint64_t& data);
				virtual bool write(uint64_t off, uint8_t len, uint64_t data);

				virtual std::string name() const
				{
					return "pl061";
				}

			private:
				irq::IRQLineBase& _irq;

				uint32_t direction, sense, edges, event, mask, mode, evt;
			};
		}
	}
}
