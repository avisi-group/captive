/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/net/network-interface.h>

namespace captive {
	namespace devices {
		namespace net {
			namespace user {

				class UserInterface : public NetworkInterface {
				public:
					UserInterface();
					virtual ~UserInterface();

					virtual bool start() override;
					virtual void stop() override;

				private:
					bool transmit_packet(const uint8_t* buffer, uint32_t length) override;
				};
			}
		}
	}
}
