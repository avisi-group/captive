/* SPDX-License-Identifier: MIT */
#pragma once

#include <device.h>

namespace captive {
	namespace arch {
		namespace aarch64 {
			class aarch64_cpu;
			namespace devices {

				class PSCI : public CoreDevice {
				public:
					PSCI(Environment& env);
					virtual ~PSCI();

					bool read(CPU& cpu, uint32_t reg, uint64_t& data) override;
					bool write(CPU& cpu, uint32_t reg, uint64_t data) override;
				};
			}
		}
	}
}
