/* SPDX-License-Identifier: MIT */

#include <arm64-cpu.h>
#include <devices/psci.h>
#include <jit.h>
#include <printf.h>

#define PSCI_FN_BASE (0x84000000)
#define PSCI_FN64_BASE (PSCI_FN_BASE + 0x40000000)

#define PSCI_FN(_V)  (PSCI_FN_BASE + (_V))
#define PSCI_FN64(_V) (PSCI_FN64_BASE + (_V))

#define PSCI_FN_VERSION   PSCI_FN(0)
#define PSCI_FN_CPU_SUSPEND  PSCI_FN(1)
#define PSCI_FN_CPU_OFF   PSCI_FN(2)
#define PSCI_FN_CPU_ON   PSCI_FN(3)
#define PSCI_FN64_CPU_SUSPEND PSCI_FN64(1)
#define PSCI_FN64_CPU_OFF  PSCI_FN64(2)
#define PSCI_FN64_CPU_ON  PSCI_FN64(3)
#define PSCI_MIGRATE_INFO_TYPE PSCI_FN(6)

using namespace captive::arch::arm64::devices;

PSCI::PSCI(Environment& env) : CoreDevice(env)
{

}

PSCI::~PSCI()
{

}

bool PSCI::read(CPU& cpu, uint32_t reg, uint64_t& data)
{
	return false;
}

bool PSCI::write(CPU& cpu, uint32_t reg, uint64_t data)
{
	assert(reg == 0);

	arm64_cpu& core = (arm64_cpu&) cpu;

	uint64_t psci_reg = core.reg_offsets.RBX[0];
	uint64_t psci_data = 0;

	printf("PSCI ACCESS %lx\n", psci_reg);

	/*if (psci_reg == 0xc4000003) {
		core.invalidate_translations();

		core.trace().enable();
		core.jit().trace(true);
	}*/

	switch (psci_reg) {
	case PSCI_FN_VERSION:
		psci_data = 2;
		break;

	case PSCI_MIGRATE_INFO_TYPE:
		psci_data = 2;
		break;

	case PSCI_FN64_CPU_ON:
		psci_data = -2;
		break;

	case PSCI_FN64_CPU_SUSPEND:
		psci_data = -3;
		break;

	default:
		fatal("PSCI: UNHANDLED PSCI ACCESS: %lx pc=%p\n", psci_reg, read_pc());
	}


	//core.jit().trace(true);

	core.reg_offsets.RBX[0] = psci_data;
	return true;
}
