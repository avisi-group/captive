/* SPDX-License-Identifier: MIT */
#pragma once

#include <util/maybe.h>
#include <vector>

namespace captive {
	namespace util {
		namespace config {

			class Configuration {
			public:

				Configuration() : print_usage(false), insn_count(false), cache_simulation(false), tracing(false), dump_code(false), debugging(false), debug_port(10000), mpk(false), universal_machine(false)
				{
				}

				bool print_usage;

				std::string arch_module;
				std::string platform;
				std::string guest_kernel;

				maybe<std::string> block_device_file;
				maybe<std::string> device_tree;

				maybe<std::string> net_mac_addr;
				maybe<std::string> net_tap_device;
				std::vector<std::string> cmdline;

				maybe<std::string> semihosting;

				bool insn_count;
				bool cache_simulation;
				bool tracing;
				bool dump_code;
				bool debugging;
				int debug_port;
				bool mpk, universal_machine;
			};
		}
	}
}
