/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/net/network-interface.h>
#include <string>

namespace captive {
	namespace devices {
		namespace net {
			namespace priv {

				class PrivateInterface : public NetworkInterface {
				public:
					PrivateInterface();
					virtual ~PrivateInterface();

					bool open(std::string socket);

				private:
					bool transmit_packet(const uint8_t* buffer, uint32_t length) override;
				};
			}
		}
	}
}
