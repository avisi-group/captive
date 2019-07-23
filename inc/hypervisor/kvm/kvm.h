/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

#include <vector>

#include <captive.h>
#include <hypervisor/hypervisor.h>
#include <hypervisor/guest.h>

namespace captive {
	namespace hypervisor {
		namespace kvm {
			class KVMGuest;
			class KVMCpu;

			class KVM : public Hypervisor {
				friend class KVMGuest;
				friend class KVMCpu;

			public:
				explicit KVM(Debugger *debugger);
				virtual ~KVM();

				bool init() override;
				Guest *create_guest(engine::Engine& engine, platform::Platform& platform) override;

				int version() const;

				inline bool initialised() const
				{
					return _initialised;
				}

				static bool supported();

			private:
				bool _initialised;
				int kvm_fd;
				std::vector<Guest *> known_guests;

				bool validate_configuration(const GuestConfiguration& config) const;

				int check_extension(int extension) const;

				KVM(const KVM&) = delete;
				KVM& operator=(const KVM&) = delete;
			};
		}
	}
}
