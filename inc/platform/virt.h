/* SPDX-License-Identifier: MIT */
#pragma once

#include <platform/platform.h>
#include <hypervisor/config.h>
#include <string>
#include <list>

namespace captive {
	namespace devices {
		namespace arm {
			class PL011;
		}
		namespace net {
			class NetworkInterface;
		}
	}
	namespace platform {

		class Virtual : public Platform {
		public:
			Virtual(const util::config::Configuration& cfg, devices::timers::TimerManager& timer_manager);
			virtual ~Virtual();

			const hypervisor::GuestConfiguration& config() const override
			{
				return cfg;
			}

			bool start() override;
			bool stop() override;

			void dump() const override;

		private:
			hypervisor::GuestConfiguration cfg;

			devices::arm::PL011 *uart0;
			devices::net::NetworkInterface *net_iface;
		};
	}
}
