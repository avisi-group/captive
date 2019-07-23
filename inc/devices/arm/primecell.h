/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>

namespace captive {
	namespace devices {
		namespace arm {

			class Primecell : public Device {
			public:
				Primecell(uint32_t peripheral_id, uint32_t size = 0x1000);
				virtual ~Primecell();

				virtual bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				virtual bool write(uint64_t off, uint8_t len, uint64_t data) override;

				virtual uint32_t size() const
				{
					return _size;
				}

			private:
				uint32_t peripheral_id;
				uint32_t primecell_id;
				uint32_t _size;
			};
		}
	}
}
