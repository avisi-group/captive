/* SPDX-License-Identifier: MIT */
#pragma once

#include <hypervisor/semihosting-context.h>

namespace captive {
	namespace util {
		namespace config {
			class Configuration;
		}
	}

	namespace hypervisor {

		class AngelSemihostingContext : public SemihostingContext {
		public:
			AngelSemihostingContext(Guest& guest, const util::config::Configuration& cfg);

			bool init() override;
			bool handle_semihosting_call(SemihostingCallData& data) override;

		private:
			const util::config::Configuration& _cfg;
		};
	}
}