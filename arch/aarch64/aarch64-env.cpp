/* SPDX-License-Identifier: MIT */

#include <aarch64-env.h>
#include <aarch64-cpu.h>
#include <devices/system-registers.h>
#include <devices/psci.h>
#include <devices/generic-timer.h>
#include <devices/semihosting.h>

#include <printf.h>

using namespace captive;
using namespace captive::arch;
using namespace captive::arch::aarch64;
using namespace captive::arch::aarch64::devices;

Environment *create_environment_aarch64(PerGuestData *per_guest_data)
{
	return new aarch64_environment(aarch64_environment::CortexA72, per_guest_data);
}

aarch64_environment::aarch64_environment(enum core_variant _core_variant, PerGuestData *per_guest_data) : Environment(per_guest_data), _core_variant(_core_variant)
{
	install_core_device(16, new SystemRegisters(*this));
	install_core_device(17, new PSCI(*this));
#ifndef CONFIG_USER_MODE
	install_core_device(18, new GenericTimer(*this));
#endif
	install_core_device(19, new SemihostingHandler(*this));
}

aarch64_environment::~aarch64_environment()
{

}

CPU *aarch64_environment::create_cpu(PerCPUData *per_cpu_data)
{
	return new aarch64_cpu(*this, per_cpu_data);
}

bool aarch64_environment::prepare_boot_cpu(CPU* core)
{
	aarch64_cpu *arm_core = (aarch64_cpu *) core;

	arm_core->reg_offsets.RBX[0] = 0x80010000;
	arm_core->reg_offsets.RBX[1] = 0x0;
	arm_core->reg_offsets.RBX[2] = 0x0;
	arm_core->reg_offsets.RBX[3] = 0x0;
	arm_core->feature_manager().set_feature((uint32_t) A64_EL, 1);
	arm_core->feature_manager().set_feature((uint32_t) A64_SPSEL, 1);
	arm_core->feature_manager().set_feature((uint32_t) A64_SS, 0);

#ifdef CONFIG_USER_MODE
	arm_core->feature_manager().set_feature((uint32_t) EMULATE_LINUX, 1);
#else
	arm_core->feature_manager().set_feature((uint32_t) EMULATE_LINUX, 0);
#endif

	arm_core->reg_offsets.D[0] = 1;
	arm_core->reg_offsets.A[0] = 1;
	arm_core->reg_offsets.I[0] = 1;
	arm_core->reg_offsets.F[0] = 1;

	arm_core->reg_offsets.SP_EL0[0] = 0;
	arm_core->reg_offsets.SP_EL1[0] = core->cpu_data().guest_data->initial_sp;

	write_pc(core->cpu_data().guest_data->entrypoint);

	return true;
}

bool aarch64_environment::prepare_bootloader()
{
	return true;
}
