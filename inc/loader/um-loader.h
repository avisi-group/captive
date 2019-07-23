/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <loader/loader.h>
#include <loader/kernel-loader.h>

namespace captive {
	namespace loader {

		class UMLoader : public FileBasedLoader, public KernelLoader {
		public:
			UMLoader(const std::string& filename);

			bool install(uint8_t* gpm) override;

			gpa_t entrypoint() const override
			{
				return 0;
			}

			bool requires_device_tree() const override
			{
				return false;
			}

			gpa_t base_address() const override
			{
				return 0;
			}
		};
	}
}
