/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <map>

using namespace captive;
using namespace captive::logging;

static std::map<std::string, LogContext *> registered_logging_contexts __attribute__((init_priority(200)));

void captive::logging::register_logging_context(LogContext& ctx)
{
	registered_logging_contexts[ctx.name()] = &ctx;
}

void captive::logging::configure_logging_contexts()
{
	// Fix-up each logging context's parent pointer.
	for (auto context : registered_logging_contexts) {
		if (context.second->parent_name() != "") {
			auto found_parent = registered_logging_contexts.find(context.second->parent_name());
			if (found_parent == registered_logging_contexts.end()) {
				WARNING << "Unable to find parent logging context '" << context.second->parent_name() << "' for '" << context.second->name() << "'";
			} else {
				context.second->_parent = found_parent->second;
			}
		} else {
			context.second->_parent = NULL;
		}
	}

	//registered_logging_contexts.find("VirtIO")->second->enable();
	//registered_logging_contexts.find("VirtIONetworkDevice")->second->enable();
	//registered_logging_contexts.find("VirtIOBlockDevice")->second->enable();
}
