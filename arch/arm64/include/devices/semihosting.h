/* SPDX-License-Identifier: MIT */
#pragma once

#include <device.h>

namespace captive {
	namespace arch {
		namespace arm64 {
			class arm64_environment;

			namespace devices {

				class SemihostingHandler : public CoreDevice {
				public:
					SemihostingHandler(arm64_environment& env);

					bool read(CPU& cpu, uint32_t reg, uint64_t& data) override;
					bool write(CPU& cpu, uint32_t reg, uint64_t data) override;
				};
			}
		}
	}
}
