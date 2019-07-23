/* SPDX-License-Identifier: MIT */
#pragma once

#include <list>
#include <map>
#include <util/maybe.h>

namespace captive {
	namespace util {
		namespace config {
			class Configuration;
		}

		class CommandLine {
		public:
			static bool parse(int argc, const char **argv, config::Configuration& cfg);
			static void print_usage();

		private:
			CommandLine();
		};
	}
}
