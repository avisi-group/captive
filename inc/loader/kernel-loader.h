/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <loader/loader.h>
#include <util/config/config.h>

namespace captive {
	namespace loader {

		class KernelLoader : public Loader {
		public:
			virtual gpa_t entrypoint() const = 0;
			virtual bool requires_device_tree() const = 0;

			static KernelLoader *create_from_file(const util::config::Configuration& cfg);
		};
	}
}
