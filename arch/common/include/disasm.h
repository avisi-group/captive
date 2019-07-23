/* SPDX-License-Identifier: MIT */
#pragma once

#include <string.h>
#include <printf.h>

namespace captive {
	namespace arch {

		class Disasm {
		public:
			virtual const char *disassemble(uint64_t pc, const uint8_t *data) = 0;

		protected:

			inline void append_str(const char *str)
			{
				strcat(_buffer, str);
			}

			inline void append_dec(uint64_t val)
			{
				char tmp[12];
				tmp[0] = 0;
				sprintf(tmp, "%d", val);

				strcat(_buffer, tmp);
			}

			inline void append_hex(uint32_t val)
			{
				char tmp[20];
				tmp[0] = 0;
				sprintf(tmp, "0x%x", val);

				strcat(_buffer, tmp);
			}

			inline void append_hex(uint64_t val)
			{
				char tmp[20];
				tmp[0] = 0;
				sprintf(tmp, "0x%lx", val);

				strcat(_buffer, tmp);
			}

			inline const char *buffer() const
			{
				return _buffer;
			}

			inline void clear()
			{
				_buffer[0] = 0;
			}

		private:
			char _buffer[64];
		};
	}
}
