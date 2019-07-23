/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>

namespace captive {
	namespace devices {
		namespace arm {

			class MHU : public Device {
			public:
				MHU();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				uint32_t size() const override
				{
					return 0x1000;
				}

				std::string name() const override
				{
					return "mhu";
				}
			};
		}
	}
}