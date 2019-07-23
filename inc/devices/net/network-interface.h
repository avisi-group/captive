/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace devices {
		namespace net {
			class NetworkDevice;

			class NetworkInterfaceReceiveCallback {
			public:
				virtual void receive_packet(const uint8_t *buffer, uint32_t length) = 0;
			};

			class NetworkInterface {
			public:

				NetworkInterface() : _receive_callback(NULL)
				{
				}

				virtual ~NetworkInterface()
				{
				}

				void attach(NetworkInterfaceReceiveCallback& callback)
				{
					_receive_callback = &callback;
				}

				virtual bool transmit_packet(const uint8_t *buffer, uint32_t length) = 0;

				virtual bool start() = 0;
				virtual void stop() = 0;

			protected:
				void invoke_receive(const uint8_t *buffer, uint32_t length);

			private:
				NetworkInterfaceReceiveCallback *_receive_callback;
			};
		}
	}
}
