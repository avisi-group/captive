/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/uart.h>

namespace captive {
	namespace devices {
		namespace io {

			class NullUART : public UART {
			public:
				NullUART();
				virtual ~NullUART();

				bool open() override;
				bool close() override;

				bool read_char(uint8_t& ch) override;
				bool write_char(uint8_t ch) override;
			};
		}
	}
}
