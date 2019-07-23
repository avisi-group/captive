/* SPDX-License-Identifier: MIT */
#pragma once

#include <platform/platform.h>
#include <hypervisor/config.h>
#include <string>
#include <list>

namespace captive {
	namespace loader {
		class Loader;
	}

	namespace platform {

		class UserPlatform : public Platform {
		public:
			UserPlatform(const util::config::Configuration& cfg, devices::timers::TimerManager& timer_manager, const loader::Loader *kernel);
			virtual ~UserPlatform();

			const hypervisor::GuestConfiguration& config() const override
			{
				return cfg;
			}

			bool start() override;
			bool stop() override;

			void dump() const override;

			bool prepare_guest_memory(void* ptr) override;
			gpa_t stackpointer() const override;

		private:
			const loader::Loader *_kernel;
			hypervisor::GuestConfiguration cfg;
			gpa_t _initial_stackpointer;
		};
	}
}
