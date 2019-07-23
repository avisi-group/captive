/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/gfx/virtual-screen.h>

namespace captive {
	namespace devices {
		namespace gfx {

			class NullVirtualScreen : public VirtualScreen {
			public:
				NullVirtualScreen();
				virtual ~NullVirtualScreen();

				virtual bool initialise();
				virtual bool activate_configuration(const VirtualScreenConfiguration& cfg);
				virtual bool reset_configuration();
			};
		}
	}
}
