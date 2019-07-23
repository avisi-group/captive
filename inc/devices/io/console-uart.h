/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/fd-uart.h>
#include <termios.h>

namespace captive {
	namespace devices {
		namespace io {

			class ConsoleUART : public FDUART {
			public:
				ConsoleUART();
				virtual ~ConsoleUART();

				bool open() override;
				bool close() override;

			private:
				struct termios orig_settings;
			};
		}
	}
}
