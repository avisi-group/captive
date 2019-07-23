/* SPDX-License-Identifier: MIT */
#pragma once

#include <hypervisor/guest.h>
#include <hypervisor/debugging.h>

namespace captive {
	namespace engine {
		class Engine;
	}

	namespace platform {
		class Platform;
	}

	namespace hypervisor {
		class Guest;

		class Hypervisor {
		public:
			Hypervisor(Debugger *debugger);
			virtual ~Hypervisor();

			virtual bool init();
			virtual Guest *create_guest(engine::Engine& engine, platform::Platform& platform) = 0;

			Debugger *debugger() const
			{
				return _debugger;
			}

		private:
			Debugger *_debugger;
		};
	}
}
