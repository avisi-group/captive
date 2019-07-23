/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/net/network-interface.h>

#include <thread>

namespace captive {
	namespace devices {
		namespace net {
			namespace tap {

				class TapInterface : public NetworkInterface {
				public:
					TapInterface(std::string tap_device);
					virtual ~TapInterface();

					bool start() override;
					void stop() override;

				private:
					std::string _tap_device;
					int _tap_fd;

					bool transmit_packet(const uint8_t* buffer, uint32_t length) override;

					volatile bool _terminate;
					std::thread *_receive_thread;
					static void receive_thread_trampoline(TapInterface *obj);
					void receive_thread_proc();
				};
			}
		}
	}
}
