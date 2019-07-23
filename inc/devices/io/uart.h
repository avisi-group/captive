/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace devices {
		namespace io {

			class UART {
			public:
				UART();
				virtual ~UART();

				virtual bool open() = 0;
				virtual bool close() = 0;

				virtual bool read_char(uint8_t& ch) = 0;
				virtual bool write_char(uint8_t ch) = 0;
			};
		}
	}
}
