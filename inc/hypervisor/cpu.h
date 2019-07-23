/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <shmem.h>

namespace captive {
	namespace hypervisor {
		class Guest;
		class GuestCPUConfiguration;

		class CPU {
		public:
			CPU(int id, Guest& owner, const GuestCPUConfiguration& config, PerCPUData *per_cpu_data);
			virtual ~CPU();

			int id() const
			{
				return _id;
			}

			virtual bool init();
			virtual bool run() = 0;
			virtual void stop() = 0;

			inline Guest& owner() const
			{
				return _owner;
			}

			inline const GuestCPUConfiguration& config() const
			{
				return _config;
			}

			inline PerCPUData& per_cpu_data() const
			{
				return *_per_cpu_data;
			}

			virtual void interrupt(uint32_t code) = 0;
			virtual void raise_guest_interrupt(uint8_t irq) = 0;
			virtual void rescind_guest_interrupt(uint8_t irq) = 0;
			virtual void acknowledge_guest_interrupt(uint8_t irq) = 0;

			void instrument_dump();

		protected:
			void instrument_fn_enter(uint64_t fnptr, uint64_t callsite);
			void instrument_fn_exit(uint64_t fnptr, uint64_t callsite);

		private:
			int _id;
			Guest& _owner;
			const GuestCPUConfiguration& _config;
			PerCPUData *_per_cpu_data;
		};
	}
}
