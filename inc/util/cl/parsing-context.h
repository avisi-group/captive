/* SPDX-License-Identifier: MIT */
#pragma once

#include <string>
#include <list>
#include <util/maybe.h>

namespace captive {
	namespace util {
		namespace config {
			class Configuration;
		}

		class CommandLine;

		namespace cl {

			class ParsingContext {
				friend class util::CommandLine;

			public:
				ParsingContext(util::config::Configuration& cfg, int nr_args, const char **args);

				inline util::config::Configuration& config() const
				{
					return _config;
				}

				const std::string key() const
				{
					return peek_token();
				}
				bool value(std::string& v);
				bool value(maybe<std::string>& v);

			private:
				util::config::Configuration& _config;

				void load_tokens(int nr_args, const char **args);

				inline bool have_tokens() const
				{
					return _tokens.size() > 0;
				}

				inline std::string peek_token() const
				{
					if (!have_tokens()) return std::string();
					return _tokens.front();
				}

				inline std::string consume_token()
				{
					if (!have_tokens()) return std::string();

					std::string token = _tokens.front();
					_tokens.pop_front();
					return token;
				}

				std::list<std::string> _tokens;
			};
		}
	}
}
