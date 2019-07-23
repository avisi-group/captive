/* SPDX-License-Identifier: MIT */
#pragma once

namespace captive {
	namespace util {
		namespace fd {
			namespace net {

				enum class AddressFamily {
					Unix = 1,
					IPv4 = 2,
					IPv6 = 10,
					None = 255
				};

				enum class SocketType {
					Stream = 1,
					Datagram = 2,
					Raw = 3,
				};

				enum class ProtocolType {
					None = 0,
					TCP = 6,
				};
			}
		}
	}
}

