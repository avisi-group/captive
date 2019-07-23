/* SPDX-License-Identifier: MIT */

#include <util/cl/parsing-context.h>

using namespace captive::util::cl;

ParsingContext::ParsingContext(util::config::Configuration& cfg, int nr_args, const char** args)
	: _config(cfg)
{
	load_tokens(nr_args, args);
}

void ParsingContext::load_tokens(int nr_args, const char** args)
{
	for (int i = 0; i < nr_args; i++) {
		_tokens.push_back(std::string(args[i]));
	}
}

bool ParsingContext::value(std::string& v)
{
	if (peek_token().compare(0, 2, "--") == 0)
		return false;
	
	v = consume_token();
	return true;
}

bool ParsingContext::value(maybe<std::string>& v)
{
	if (peek_token().compare(0, 2, "--") == 0) {
		v = maybe<std::string>();
		return false;
	}
	
	v = maybe<std::string>(consume_token());
	return true;
}
