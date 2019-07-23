/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>

namespace captive {
	namespace devices {
		namespace arm {

			class SnoopControlUnit : public Device {
			public:
				SnoopControlUnit();
				virtual ~SnoopControlUnit();

				std::string name() const
				{
					return "scu";
				}

				uint32_t size() const
				{
					return 0x100;
				}

				bool read(uint64_t off, uint8_t len, uint64_t& data);
				bool write(uint64_t off, uint8_t len, uint64_t data);

			private:
				uint32_t control;
			};
		}
	}
}
