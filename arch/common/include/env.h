/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <shmem.h>
#include <printf.h>

namespace captive {
	namespace arch {
		class CPU;
		class CoreDevice;

		class Environment {
		public:
			Environment(PerGuestData *per_guest_data);
			virtual ~Environment();

			virtual bool init();
			bool run(PerCPUData *per_cpu_data);

			virtual CPU *create_cpu(PerCPUData *per_cpu_data) = 0;

			bool write_core_device(CPU& cpu, uint32_t id, uint32_t reg, uint64_t data);
			bool read_core_device(CPU& cpu, uint32_t id, uint32_t reg, uint64_t& data);

			inline bool install_core_device(uint32_t id, CoreDevice *device)
			{
				if (id > 23) {
					return false;
				}

				//printf("registering core device %d @ %p\n", id, device);

				if (devices[id])
					return false;

				devices[id] = device;
				return true;
			}

			inline CoreDevice *lookup_core_device(uint32_t id)
			{
				if (id > 23) {
					return NULL;
				}

				return devices[id];
			}

		protected:
			virtual bool prepare_boot_cpu(CPU *core) = 0;
			virtual bool prepare_bootloader() = 0;

		private:
			CoreDevice *devices[24];

			void install_idt();
			void install_syscall();
			void prepare_fast_syscall();
			void setup_interrupts();

		protected:
			PerGuestData *per_guest_data;
		};
	}
}
