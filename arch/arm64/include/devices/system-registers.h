/* SPDX-License-Identifier: MIT */
#pragma once

#include <device.h>

namespace captive::arch::arm64
{
	class arm64_cpu;

	namespace devices
	{
		class SystemRegisters : public CoreDevice
		{
		public:
			SystemRegisters(Environment &env);
			virtual ~SystemRegisters();

			bool read(CPU &cpu, uint32_t reg, uint64_t &data) override;
			bool write(CPU &cpu, uint32_t reg, uint64_t data) override;

		private:
			struct register_access
			{
				uint8_t op0, op1, op2;
				uint8_t crn, crm;
			};

			register_access decode_access(uint32_t ir);

			uint64_t CPACR, MAIR, SCTLR, TCR;
			uint64_t TPIDR_EL0, TPIDR_EL1;
			uint64_t OSLAR_EL1;

			uint64_t CSSELR;

			void update_sctlr(arm64_cpu &cpu);
		};
	} // namespace devices
} // namespace captive::arch::arm64
