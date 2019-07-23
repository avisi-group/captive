/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>

namespace captive {
	namespace devices {
		namespace net {
			class NetworkInterface;

			class NetworkDevice : public Device {
			public:

				NetworkDevice() : attached_iface(NULL)
				{
				}

				virtual ~NetworkDevice()
				{
				}

				virtual bool receive_packet(const uint8_t *buffer, uint32_t length) = 0;

			protected:

				NetworkInterface *interface() const
				{
					return attached_iface;
				}

			private:
				friend class NetworkInterface;

				NetworkInterface *attached_iface;

				inline void attach_interface(NetworkInterface *iface)
				{
					attached_iface = iface;
				}
			};
		}
	}
}
