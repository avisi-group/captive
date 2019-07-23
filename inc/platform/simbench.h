/* SPDX-License-Identifier: MIT */
#pragma once

#include <platform/platform.h>
#include <hypervisor/config.h>
#include <string>
#include <list>

namespace captive {
	namespace platform {

		class Simbench : public Platform {
		public:
			Simbench(const util::config::Configuration& cfg, devices::timers::TimerManager& timer_manager);
			virtual ~Simbench();

			const hypervisor::GuestConfiguration& config() const override
			{
				return cfg;
			}

			bool start() override;
			bool stop() override;

			void dump() const override;

		private:
			hypervisor::GuestConfiguration cfg;
		};
	}
}
