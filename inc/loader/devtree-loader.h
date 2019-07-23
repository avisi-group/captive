/* SPDX-License-Identifier: MIT */
#pragma once

#include <loader/loader.h>

namespace captive {
	namespace loader {

		class DeviceTreeLoader : public FileBasedLoader {
		public:
			DeviceTreeLoader(std::string filename, uint32_t base_address);

			virtual bool install(uint8_t* gpm) override;

			gpa_t base_address() const override
			{
				return _base_address;
			}

		private:
			gpa_t _base_address;
		};
	}
}
