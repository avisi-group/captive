/* SPDX-License-Identifier: MIT */

#include <util/cl/option-handler.h>
#include <util/cl/parsing-context.h>
#include <util/config/config.h>

#include <map>

using namespace captive::util;
using namespace captive::util::cl;

extern std::map<std::string, OptionHandler *> registered_option_handlers;

OptionHandlerRegistration::OptionHandlerRegistration(std::string tag, OptionHandler& handler) 
	: _tag(tag), _handler(handler)
{
	registered_option_handlers[tag] = &handler;
}

// -------------------------------------------------------------------------------------------------------------------

DEFINE_OPTION_HANDLER("engine", Engine, OptionRequirement::Once, ValueRequirement::Required) {
	config.arch_module = arg;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("kernel", Kernel, OptionRequirement::Once, ValueRequirement::Required) {
	config.guest_kernel = arg;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("block-dev-file", BlockDevFile, OptionRequirement::Once, ValueRequirement::Required) {
	config.block_device_file = arg;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("tap-device", TAPDevice, OptionRequirement::None, ValueRequirement::Required) {
	config.net_tap_device = arg;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("mac-address", MACAddress, OptionRequirement::None, ValueRequirement::Required) {
	config.net_mac_addr = arg;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("help", Help, OptionRequirement::None, ValueRequirement::None) {
	config.print_usage = true;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("cache-sim", CacheSimulation, OptionRequirement::None, ValueRequirement::None) {
	config.cache_simulation = true;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("icount", CountInstructions, OptionRequirement::None, ValueRequirement::None) {
	config.insn_count = true;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("platform", Platform, OptionRequirement::Once, ValueRequirement::Required) {
	config.platform = arg;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("device-tree", DeviceTree, OptionRequirement::None, ValueRequirement::Required) {
	config.device_tree = arg;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("semihosting", Semihosting, OptionRequirement::None, ValueRequirement::Required) {
	config.semihosting = arg;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("tracing", Tracing, OptionRequirement::None, ValueRequirement::None) {
	config.tracing = true;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("dump-code", DumpCode, OptionRequirement::None, ValueRequirement::None) {
	config.dump_code = true;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("debugging", Debugging, OptionRequirement::None, ValueRequirement::Optional) {
	config.debugging = true;
	
	//if (arg.h)
	
	return HandleResult::OK;
}

/*DEFINE_OPTION_HANDLER("command-line", CommandLine, OptionRequirement::None, ValueRequirement::Required) {
	config.cmdline = arg;
	return HandleResult::OK;
}*/

DEFINE_OPTION_HANDLER("mpk", MPK, OptionRequirement::None, ValueRequirement::None) {
	config.mpk = true;
	return HandleResult::OK;
}

DEFINE_OPTION_HANDLER("universal-machine", UM, OptionRequirement::None, ValueRequirement::None) {
	config.universal_machine = true;
	return HandleResult::OK;
}
