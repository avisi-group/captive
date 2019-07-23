/* SPDX-License-Identifier: MIT */

#include <util/command-line.h>
#include <util/cl/option-handler.h>
#include <util/cl/parsing-context.h>

#include <map>

#include "util/config/config.h"

using namespace captive::util;
using namespace captive::util::cl;

std::map<std::string, OptionHandler *> registered_option_handlers __attribute__((init_priority(500)));

bool CommandLine::parse(int argc, const char **argv, config::Configuration& cfg)
{
	if (argc < 1) return false;
	
	ParsingContext context(cfg, argc-1, argv+1);
	bool success = true;
	
	while (context.have_tokens()) {
		std::string token = context.consume_token();
		
		if (token.compare(0, 2, "--") == 0) {
			if (token == "--") break;
			
			auto ihandler = registered_option_handlers.find(token.substr(2));
			if (ihandler == registered_option_handlers.end()) {
				fprintf(stderr, "error: unrecognised command-line option '%s'\n", token.c_str());
				success = false;
			} else {
				auto handler = ihandler->second;
				
				std::string value;
				
				if (handler->value_requirement() == ValueRequirement::None) {
					value = "";
				} else if (handler->value_requirement() == ValueRequirement::Optional) {
					if (context.have_tokens() && context.peek_token().compare(0, 2, "--") != 0) {
						value = context.consume_token();
					}
				} else if (handler->value_requirement() == ValueRequirement::Required) {
					if (context.have_tokens() && context.peek_token().compare(0, 2, "--") != 0) {
						value = context.consume_token();
					} else {
						fprintf(stderr, "error: command-line option '%s' requires a value.\n", token.c_str());
						return false;
					}
				}
				
				if (handler->visited() && handler->option_requirement() == OptionRequirement::Once) {
					fprintf(stderr, "error: command-line option '%s' may only be specified once.\n", token.c_str());
					return false;
				} else {
					handler->visit();
					
					auto result = handler->handle(cfg, value);
					switch (result) {
					case cl::HandleResult::InvalidArgument:
						success = false;
						fprintf(stderr, "error: argument to command-line option '%s' is invalid\n", token.c_str());
						break;
					default:
						break;
					}
				}
			}
		} else {
			fprintf(stderr, "error: unhandled command-line argument '%s'\n", token.c_str());
			success = false;
		}
	}
	
	while (context.have_tokens()) {
		cfg.cmdline.push_back(context.consume_token());
	}
	
	for (auto handler : registered_option_handlers) {
		if (handler.second->option_requirement() == OptionRequirement::Once && !handler.second->visited()) {
			fprintf(stderr, "error: command-line argument '--%s' must be specified\n", handler.first.c_str());
			success = false;
		}
	}
	
	return success;
}

void CommandLine::print_usage()
{
	fprintf(stderr, "command-line options:\n");
	
	for (auto handler : registered_option_handlers) {
		fprintf(stderr, "  --%s", handler.first.c_str());
		
		if (handler.second->value_requirement() == ValueRequirement::Optional) {
			fprintf(stderr, " [value]");
		} else if (handler.second->value_requirement() == ValueRequirement::Required) {
			fprintf(stderr, " <value>");
		}
		
		if (handler.second->option_requirement() != OptionRequirement::None) {
			fprintf(stderr, " (required)");
		}
		
		fprintf(stderr, "\n");
	}
}
