/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>

namespace captive {
	namespace devices {
		namespace arm {

			class SMMU : public Device {
			public:
				SMMU();
				virtual ~SMMU();

				std::string name() const override
				{
					return "smmu";
				}

				uint32_t size() const override
				{
					return 0x1000;
				}

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;
			};
		}
	}
}
