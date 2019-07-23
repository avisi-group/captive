/* SPDX-License-Identifier: MIT */
#pragma once

#include <list>
#include <devices/timers/timer-manager.h>

namespace captive {
	namespace hypervisor {
		class GuestConfiguration;
	}

	namespace devices {
		namespace timers {
			class TimerManager;
		}
	}

	namespace util {
		namespace config {
			class Configuration;
		}
	}

	namespace platform {

		class Platform {
		public:
			Platform(const util::config::Configuration& cfg, devices::timers::TimerManager& timer_manager);
			virtual ~Platform();

			virtual const hypervisor::GuestConfiguration& config() const = 0;

			virtual bool start() = 0;
			virtual bool stop() = 0;

			const util::config::Configuration& host_configuration() const
			{
				return _cfg;
			}

			devices::timers::TimerManager& timer_manager() const
			{
				return _timer_manager;
			}

			virtual void dump() const;

			virtual gpa_t stackpointer() const;
			virtual bool prepare_guest_memory(void *ptr);

		private:
			const util::config::Configuration& _cfg;
			devices::timers::TimerManager& _timer_manager;
		};
	}
}
