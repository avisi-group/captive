/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>

namespace captive {
	namespace devices {
		namespace pci {

			class PCIDevice : public Device {
			public:
				PCIDevice(uint32_t class_code);

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				uint32_t size() const override
				{
					return 0x1000;
				}

			private:
				uint32_t _class_code;
			};
		}
	}
}