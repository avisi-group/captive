/* SPDX-License-Identifier: MIT */
#pragma once

#include <loader/loader.h>

namespace captive {
	namespace loader {
		class InitRDLoader;

		class ATAGsLoader : public Loader {
		public:
			ATAGsLoader();
			ATAGsLoader(InitRDLoader& initrd);

			bool install(uint8_t* gpm) override;

			gpa_t base_address() const override
			{
				return 0x100;
			}

		private:
			InitRDLoader *_initrd;
		};
	}
}
