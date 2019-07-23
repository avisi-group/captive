/* SPDX-License-Identifier: MIT */

#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		class CPU;

		namespace jit {

			class FeatureManager {
			public:
				FeatureManager(CPU& cpu);

				uint32_t active_features() const;
				uint32_t get_feature(uint32_t feature) const;
				void set_feature(uint32_t feature, uint32_t value);

			private:
				CPU& _cpu;
			};
		}
	}
}
