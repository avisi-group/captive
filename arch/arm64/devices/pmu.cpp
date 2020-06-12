/* SPDX-License-Identifier: MIT */

#include <devices/pmu.h>
#include <arm64-env.h>
#include <printf.h>
#include <devices/sysreg-helper.h>
#include <cpu.h>
#include <dbt/feature-manager.h>

using namespace captive::arch::arm64::devices;

PMU::PMU(arm64_environment &env) : CoreDevice(env), PMCR(0x41023000), PMUSERENR(0), PMCNTEN(0), PMINTEN(0), PMOVS(0), PMXEVTYPER{0}, PMXEVCNTR{0}
{
}

bool PMU::read(CPU &cpu, uint32_t reg, uint64_t &data)
{
    switch (EXTRACT_SYSREG(reg))
    {
    REG_PMCR_EL0:
        data = PMCR;
        return true;

    REG_PMUSERENR_EL0:
        data = PMUSERENR;
        return true;

    REG_PMCEID0_EL0:
        data = 0xd01;
        return true;

    REG_PMCEID1_EL0:
        data = 0;
        return true;

    REG_PMXEVCNTR_EL0:
        if ((PMXEVTYPER[PMSELR] & 0xffff) == 8) {
            data = cpu.performance_counter_a();
        } else {
            data = PMXEVCNTR[PMSELR];
        }

        return true;

    REG_PMXEVTYPER_EL0:
        data = PMXEVTYPER[PMSELR];
        return true;

    default:
        printf("pmu: unhandled read reg=%x\n", reg);
        abort();
        return false;
    }

    return true;
}

bool PMU::write(CPU &cpu, uint32_t reg, uint64_t data)
{
    switch (EXTRACT_SYSREG(reg))
    {
    REG_PMCR_EL0:
        PMCR = (PMCR & ~0x7f) | (data & 0x7f);
        return true;

    REG_PMUSERENR_EL0:
        PMUSERENR = data & 0xf;
        return true;

    REG_PMCNTENCLR_EL0:
        PMCNTEN = PMCNTEN & ~data;
        update_counters(cpu);
        return true;

    REG_PMCNTENSET_EL0:
        PMCNTEN = PMCNTEN | data;
        update_counters(cpu);
        return true;

    REG_PMINTENCLR_EL1:
        PMINTEN = PMINTEN & ~data;
        return true;

    REG_PMINTENSET_EL1:
        PMINTEN = PMINTEN | data;
        return true;

    REG_PMOVSCLR_EL0:
        PMOVS = PMOVS & ~data;
        return true;

    REG_PMOVSSET_EL0:
        PMOVS = PMOVS | data;
        return true;

    REG_PMSELR_EL0:
        PMSELR = data & 0x1f;
        return true;

    REG_PMXEVCNTR_EL0:
        if ((PMXEVTYPER[PMSELR] & 0xffff) == 8) {
            cpu.performance_counter_a(data);
        } else {
            PMXEVCNTR[PMSELR] = data;
        }

        return true;

    REG_PMXEVTYPER_EL0:
        printf("pmu: setting type of %u to %08x\n", PMSELR, data);
        PMXEVTYPER[PMSELR] = data;
        return true;

    default:
        printf("pmu: unhandled write reg=%x data=%lx\n", reg, data);
        abort();
        return false;
    }

    return true;
}

void PMU::update_counters(CPU& cpu)
{
    bool count_kernel_instructions = false;
    bool count_user_instructions = false;

    for (int i = 0; i < 32; i++) {
        if ((PMXEVTYPER[i] & 0xffff) == 8) {
            // Instruction Retired
            if (PMCNTEN & (1 << i)) {
                // Enabled
                count_kernel_instructions = false;
                count_user_instructions = true;
            }
        }
    }

    if (count_kernel_instructions) {
        cpu.feature_manager().set_feature(6, 1);
    } else {
        cpu.feature_manager().set_feature(6, 0);
    }

    if (count_user_instructions) {
        cpu.feature_manager().set_feature(7, 1);
    } else {
        cpu.feature_manager().set_feature(7, 0);
    }

    //cpu.invalidate_translations();
}

/*
REG_PMCEID0_EL0:
	REG_PMCEID1_EL0:
		data = 0x7fff0f3f; // a72
		//data = 0xd01;
		return true;

        REG_PMCR_EL0:
		printf("sys-reg: pmcr: old=%lx new=%lx\n", PMCR, data);
		PMCR = (PMCR & ~0x7f) | (data & 0x7f);
		return true;

	REG_PMCNTENCLR_EL0:
	REG_PMINTENCLR_EL1:
	REG_PMOVSCLR_EL0:
		return true;
        */
