/* SPDX-License-Identifier: MIT */
#pragma once

#include <loader/loader.h>

namespace captive {
	namespace loader {

		class InitRDLoader : public FileBasedLoader {
		public:
			InitRDLoader(std::string filename, uint32_t base_address);

			bool install(uint8_t* gpm) override;

			gpa_t base_address() const override
			{
				return _base_address;
			}

		private:
			gpa_t _base_address;
		};
	}
}
