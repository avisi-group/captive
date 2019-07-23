/* SPDX-License-Identifier: MIT */
#pragma once

namespace captive {
	namespace arch {
		namespace x86 {

			enum class feature_requirement {
				optional,
				required,
				forbidden
			};

			struct cpuid_feature {
				int function, index, part, bit;
				const char *name;
				feature_requirement rq;
			};

			extern void dump_cpu_features();
		}
	}
}
