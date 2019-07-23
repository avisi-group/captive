/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>

namespace captive {
	namespace devices {
		namespace arm {

			class SBCON : public Device {
			public:
				SBCON();
				virtual ~SBCON();

				virtual bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				virtual bool write(uint64_t off, uint8_t len, uint64_t data) override;

				virtual uint32_t size() const
				{
					return 0x1000;
				}

			private:
				uint32_t in, out;
			};
		}
	}
}
