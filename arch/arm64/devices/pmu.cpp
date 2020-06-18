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
        break;

    REG_PMUSERENR_EL0:
        data = PMUSERENR;
        break;

    REG_PMCEID0_EL0:
        data = 0x00001101u; // PC-WRITE, INST RETIRED, PC SWINC
        break;

    REG_PMCEID1_EL0:
        data = 0;
        break;

    REG_PMXEVCNTR_EL0:
        if ((PMXEVTYPER[PMSELR] & 0xffff) == 0x8)
        {
            data = cpu.jit_state.perf_icount;
        }
        else if ((PMXEVTYPER[PMSELR] & 0xffff) == 0xc)
        {
            data = cpu.jit_state.perf_brcount;
        }
        else
        {
            data = PMXEVCNTR[PMSELR];
        }
        break;

    REG_PMXEVTYPER_EL0:
        data = PMXEVTYPER[PMSELR];
        break;

    default:
        printf("pmu: unhandled read reg=%x\n", reg);
        abort();
        return false;
    }

    // printf("pmu: read %08x = %lx @ %p\n", reg, data, read_pc());
    return true;
}

bool PMU::write(CPU &cpu, uint32_t reg, uint64_t data)
{
    //printf("pmu: write %08x = %lx\n", reg, data);

    switch (EXTRACT_SYSREG(reg))
    {
    REG_PMCR_EL0:
        PMCR = (PMCR & ~0xe9) | (data & 0xe9);

        if (data & 2)
        {
            reset_counters(cpu);
        }

        update_counters(cpu);
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
        //printf("pmu: setting value of %u to %08x\n", PMSELR, data);
        if ((PMXEVTYPER[PMSELR] & 0xffff) == 0x8)
        {
            cpu.jit_state.perf_icount = data;
        }
        else if ((PMXEVTYPER[PMSELR] & 0xffff) == 0xc)
        {
            cpu.jit_state.perf_brcount = data;
        }
        else
        {
            PMXEVCNTR[PMSELR] = data;
        }

        return true;

    REG_PMXEVTYPER_EL0:
        //printf("pmu: setting type of %u to %08x\n", PMSELR, data);
        PMXEVTYPER[PMSELR] = data;
        /*if ((data & 0xffff) == 0x8)
        {
            cpu.jit_state.perf_icount = PMXEVCNTR[PMSELR];
        }
        else if ((data & 0xffff) == 0xc)
        {
            cpu.jit_state.perf_brcount = PMXEVCNTR[PMSELR];
        }
*/
        return true;

    default:
        printf("pmu: unhandled write reg=%x data=%lx @ %p\n", reg, data, read_pc());
        abort();
        return false;
    }

    return true;
}

void PMU::update_counters(CPU &cpu)
{
    cpu.feature_manager().set_feature(6, 0);
    cpu.feature_manager().set_feature(7, 0);
    cpu.feature_manager().set_feature(8, 0);
    cpu.feature_manager().set_feature(9, 0);

    // Don't do anything if the PMU is not enabled
    if (!(PMCR & 1))
    {
        return;
    }

    for (int i = 0; i < 32; i++)
    {
        // Ignore disabled counters
        if (!(PMCNTEN & (1 << i)))
        {
            continue;
        }

        switch ((PMXEVTYPER[i] & 0xffff))
        {
        case 0x08:                                   // Instruction retired
            cpu.feature_manager().set_feature(8, 1); // user-icount
            break;
        case 0x0c:                                   // PC-write retired
            cpu.feature_manager().set_feature(9, 1); // user-brcount
            break;
        }
    }
}

void PMU::reset_counters(CPU &cpu)
{
    for (int i = 0; i < 32; i++)
    {
        PMXEVCNTR[i] = 0;
    }

    cpu.jit_state.perf_icount = 0;
    cpu.jit_state.perf_brcount = 0;
}
