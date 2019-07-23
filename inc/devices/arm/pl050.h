/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>

namespace captive {
	namespace devices {
		namespace io {
			class PS2Device;
		}

		namespace arm {

			class PL050 : public Primecell {
			public:
				PL050(io::PS2Device& ps2);
				virtual ~PL050();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				virtual std::string name() const
				{
					return "pl050";
				}

			private:
				io::PS2Device& _ps2;
				uint32_t cr, clkdiv;
				uint32_t last;
			};
		}
	}
}
