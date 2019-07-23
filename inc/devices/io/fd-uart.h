/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/uart.h>

namespace captive {
	namespace devices {
		namespace io {

			class FDUART : public UART {
			public:
				FDUART(int infd, int outfd);
				virtual ~FDUART();

				bool open() override;
				bool close() override;

				bool read_char(uint8_t& ch) override;
				bool write_char(uint8_t ch) override;

			private:
				int infd, outfd;
			};
		}
	}
}
