/* SPDX-License-Identifier: MIT */
#pragma once

#include <string>
#include <util/maybe.h>

namespace captive {
	namespace util {
		class CommandLine;

		namespace config {
			class Configuration;
		}

		namespace cl {
			class ParsingContext;

			namespace OptionRequirement {

				enum OptionRequirement {
					None,
					Once,
					PermitMultiple,
				};
			}

			namespace ValueRequirement {

				enum ValueRequirement {
					None,
					Optional,
					Required,
				};
			}

			namespace HandleResult {

				enum HandleResult {
					OK,
					InvalidArgument
				};
			}

			class OptionHandler {
				friend class util::CommandLine;

			public:

				OptionHandler(OptionRequirement::OptionRequirement option_requirement, ValueRequirement::ValueRequirement value_requirement)
				: _option_requirement(option_requirement),
				_value_requirement(value_requirement),
				_visited(0)
				{
				}

				virtual ~OptionHandler()
				{
				}

				virtual HandleResult::HandleResult handle(util::config::Configuration& config, std::string arg) const = 0;

			protected:

				OptionRequirement::OptionRequirement option_requirement() const
				{
					return _option_requirement;
				}

				ValueRequirement::ValueRequirement value_requirement() const
				{
					return _value_requirement;
				}

				int visited() const
				{
					return _visited;
				}

				void visit()
				{
					_visited++;
				}

			private:
				const OptionRequirement::OptionRequirement _option_requirement;
				const ValueRequirement::ValueRequirement _value_requirement;
				int _visited;
			};

			class OptionHandlerRegistration {
			public:
				OptionHandlerRegistration(std::string tag, OptionHandler& handler);

			private:
				std::string _tag;
				const OptionHandler& _handler;
			};
		}
	}
}

#define DEFINE_OPTION_HANDLER(__tag, __name, __oreq, __vreq) class __name##OptionHandler : public OptionHandler \
{ \
public: \
	__name##OptionHandler(OptionRequirement::OptionRequirement oreq, ValueRequirement::ValueRequirement vreq) : OptionHandler(oreq, vreq) { } \
	virtual HandleResult::HandleResult handle(captive::util::config::Configuration& config, std::string arg) const override; \
}; \
namespace registrations { \
static __name##OptionHandler __option_handler_##__name __attribute__((init_priority(600))) (__oreq, __vreq); \
static OptionHandlerRegistration __option_handler__reg__##__name __attribute__((init_priority(700))) (__tag, __option_handler_##__name); \
} \
HandleResult::HandleResult __name##OptionHandler::handle(captive::util::config::Configuration& config, std::string arg) const


