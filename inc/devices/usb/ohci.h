/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/pci/pci-device.h>

namespace captive {
	namespace devices {
		namespace usb {

			class OHCI : public pci::PCIDevice {
			public:
				OHCI();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				std::string name() const override
				{
					return "ohci";
				}
			};
		}
	}
}