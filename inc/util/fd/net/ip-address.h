/* SPDX-License-Identifier: MIT */
#pragma once

#include <string>
#include <cstdint>

namespace captive {
	namespace util {
		namespace fd {
			namespace net {

				class IPAddress {
				public:

					IPAddress(uint32_t address) : _address(address)
					{
					}

					uint32_t address() const
					{
						return _address;
					}

					inline void to_octets(uint8_t& a, uint8_t& b, uint8_t& c, uint8_t& d) const
					{
						a = (_address >> 24) & 0xff;
						b = (_address >> 16) & 0xff;
						c = (_address >> 8) & 0xff;
						d = (_address >> 0) & 0xff;
					}

					std::string to_string() const
					{
						uint8_t a, b, c, d;
						to_octets(a, b, c, d);

						return std::to_string(a) + "." + std::to_string(b) + "." + std::to_string(c) + "." + std::to_string(d);
					}

					static inline IPAddress from_octets(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
					{
						return IPAddress((uint32_t) a << 24 | (uint32_t) b << 16 | (uint32_t) c << 8 | (uint32_t) d);
					}

					static inline IPAddress any()
					{
						return IPAddress(0);
					}

					static inline IPAddress localhost()
					{
						return from_octets(127, 0, 0, 1);
					}

				private:
					uint32_t _address;
				};
			}
		}
	}
}
