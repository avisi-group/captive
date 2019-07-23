/* SPDX-License-Identifier: MIT */

#pragma once

#include <env.h>

namespace captive {
	namespace arch {
		namespace aarch64 {

			class aarch64_environment : public Environment {
			public:

				enum core_variant {
					CortexA72,
				};

				aarch64_environment(core_variant core_variant, captive::PerGuestData *per_guest_data);
				virtual ~aarch64_environment();

				CPU *create_cpu(captive::PerCPUData *per_cpu_data) override;

				inline core_variant core_variant() const
				{
					return _core_variant;
				}

			protected:
				bool prepare_boot_cpu(CPU *core) override;
				bool prepare_bootloader() override;

			private:
				enum core_variant _core_variant;
			};
		}
	}
}
