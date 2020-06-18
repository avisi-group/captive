/* SPDX-License-Identifier: MIT */

#include <arm64-cpu.h>
#include <arm64-env.h>
#include <devices/system-registers.h>
#include <devices/sysreg-helper.h>
#include <printf.h>
#include <x86/fpu.h>
#include <mmu/strategy/strategy.h>

using namespace captive::arch::arm64::devices;

SystemRegisters::SystemRegisters(Environment &env)
	: CoreDevice(env),
	CPACR(0),
	MAIR(0),
	SCTLR(0),
	TCR(0),
	TPIDR_EL0(0),
	TPIDR_EL1(0),
	OSLAR_EL1(0),
	CSSELR(0)
{
}

SystemRegisters::~SystemRegisters()
{
}

bool SystemRegisters::read(CPU &cpu, uint32_t reg, uint64_t &data)
{
	register_access ra = decode_access(reg);
	//printf("sys-reg: read:  [%08x] op0=%d, op1=%d, rn=%d, rm=%d, op2=%d\n", reg, ra.op0, ra.op1, ra.crn, ra.crm, ra.op2);

	arm64_cpu &a64core = (arm64_cpu &)cpu;
	switch (EXTRACT_SYSREG(reg))
	{
		HANDLE_SYSREG(3, 3, 0, 0, 1) : data = 0x0444c004;
		return true; // CTR_EL0
		HANDLE_SYSREG(3, 0, 1, 0, 0) : data = SCTLR;
		return true; // SCTLR
		HANDLE_SYSREG(3, 0, 1, 0, 2) : data = CPACR;
		return true; // CPACR
		HANDLE_SYSREG(3, 0, 10, 2, 0) : data = MAIR;
		return true; // MAIR
		HANDLE_SYSREG(3, 0, 2, 0, 2) : data = TCR;
		return true; // TCR

	REG_TPIDR_EL0:
		data = TPIDR_EL0;
		return true;
	/*REG_TPIDRRO_EL0:
		data = TPIDRRO_EL0;
		return true;*/
	REG_TPIDR_EL1:
		data = TPIDR_EL1;
		return true;

	REG_MIDR_EL1:
		data = 0x410F0000;
		return true;
	REG_CLIDR_EL1:
		data = 4;
		return true;
	REG_CSSELR_EL1:
		data = CSSELR;
		return true;
	REG_CCSIDR_EL1:
		data = 0x4000;
		return true;

	REG_MPIDR_EL1:
		data = 0x40000000;
		return true;
	REG_DCZID_EL0:
		data = 0x00000011;
		return true;

	REG_ESR_EL1:
		data = a64core.reg_offsets.ESR_EL1[0];
		return true;
	REG_FAR_EL1:
		data = a64core.reg_offsets.FAR_EL1[0];
		return true;

	REG_REVIDR_EL1:
		data = 0;
		return true;

	REG_ID_AA64_PFR0_EL1:
		data = 0x00000011;
		return true;
	REG_ID_AA64_PFR1_EL1:
		data = 0;
		return true;
	REG_ID_AA64_DFR0_EL1:
		data = 0x10101606;
		return true;
	REG_ID_AA64_DFR1_EL1:
		data = 0;
		return true;
	REG_ID_AA64_ZFR0_EL1:
		data = 0;
		return true;
	REG_ID_AA64_ISAR0_EL1:
		data = 0;
		return true;
	REG_ID_AA64_ISAR1_EL1:
		data = 0;
		return true;
	REG_ID_AA64_MMFR0_EL1:
		data = 0x0f100000;
		return true;
	REG_ID_AA64_MMFR1_EL1:
		data = 0x00000000;
		return true;
	REG_ID_AA64_MMFR2_EL1:
		data = 0x00000000;
		return true;

	REG_OSLSR_EL1:
		data = OSLAR_EL1;
		return true;

	REG_DBGBVR0_EL1:
	REG_DBGBVR1_EL1:
	REG_DBGBCR0_EL1:
	REG_DBGBCR1_EL1:
	REG_DBGWVR0_EL1:
	REG_DBGWVR1_EL1:
	REG_DBGWCR0_EL1:
	REG_DBGWCR1_EL1:
		data = 0;
		return true;

	REG_PMCCFILTR_EL0:
	REG_PMCCNTR_EL0:
	REG_PMCEID0_EL0:
	REG_PMCEID1_EL0:
	REG_PMCNTENCLR_EL0:
	REG_PMCNTENSET_EL0:
	REG_PMCR_EL0:
	REG_PMINTENCLR_EL1:
	REG_PMINTENSET_EL1:
	REG_PMMIR_EL1:
	REG_PMOVSCLR_EL0:
	REG_PMOVSSET_EL0:
	REG_PMSELR_EL0:
	REG_PMSWINC_EL0:
	REG_PMUSERENR_EL0:
	REG_PMXEVCNTR_EL0:
	REG_PMXEVTYPER_EL0:
		return env().read_core_device(cpu, 20, reg, data);

	REG_VBAR_EL1:
		data = a64core.reg_offsets.VBAR[0];
		return true;

	REG_CNTKCTL_EL1:
	REG_CNTFRQ_EL0:
	REG_CNTPCT_EL0:
	REG_CNTVCT_EL0:
	REG_CNTP_TVAL_EL0:
	REG_CNTP_CTL_EL0:
	REG_CNTP_CVAL_EL0:
	REG_CNTVOFF_EL2:
	REG_CNTPS_TVAL_EL1:
	REG_CNTPS_CTL_EL1:
	REG_CNTPS_CVAL_EL1:
	REG_CNTV_TVAL_EL0:
	REG_CNTV_CTL_EL0:
	REG_CNTV_CVAL_EL0:
		return env().read_core_device(cpu, 18, reg, data);

	FPSR:
	{
		auto exp = x86::FPU::current_exceptions();

		data = 0;
		if (((int)exp & (int)x86::FloatingPointExceptions::DenormalOperation))
		{
			data |= 0x80;
		}
		if (((int)exp & (int)x86::FloatingPointExceptions::DivideByZero))
		{
			data |= 0x02;
		}
		if (((int)exp & (int)x86::FloatingPointExceptions::InvalidOperation))
		{
			data |= 0x01;
		}
		if (((int)exp & (int)x86::FloatingPointExceptions::Overflow))
		{
			data |= 0x04;
		}
		if (((int)exp & (int)x86::FloatingPointExceptions::Precision))
		{
			data |= 0x10;
		}
		if (((int)exp & (int)x86::FloatingPointExceptions::Underflow))
		{
			data |= 0x08;
		}

		return true;
	}

	default:
		printf("sys-reg: read:  [%08x] op0=%d, op1=%d, rn=%d, rm=%d, op2=%d\n", reg, ra.op0, ra.op1, ra.crn, ra.crm, ra.op2);
		printf("!!! NOW IM STUCK !!!\n");
		for (;;)
			asm volatile("nop");
	}

	data = 0;
	return false;
}

extern bool __want_trace;

bool SystemRegisters::write(CPU &cpu, uint32_t reg, uint64_t data)
{
	register_access ra = decode_access(reg);
	//printf("sys-reg: write: [%08x] op0=%d, op1=%d, rn=%d, rm=%d, op2=%d, data=%016lx\n", reg, ra.op0, ra.op1, ra.crn, ra.crm, ra.op2, data);

	arm64_cpu &a64core = (arm64_cpu &)cpu;
	switch (EXTRACT_SYSREG(reg))
	{
		HANDLE_SYSREG(3, 0, 1, 0, 0) : SCTLR = data;
		update_sctlr(a64core);
		return true; // SCTLR
		HANDLE_SYSREG(3, 0, 1, 0, 2) : CPACR = data;
		return true; // CPACR
		HANDLE_SYSREG(3, 0, 10, 2, 0) : MAIR = data;
		return true; // MAIR
		HANDLE_SYSREG(3, 0, 2, 0, 2) : TCR = data;
		printf("TCR=%p\n", TCR);
		return true; // TCR

	REG_TPIDR_EL0:
		TPIDR_EL0 = data;
		return true;
	/*REG_TPIDRRO_EL0:
		TPIDRRO_EL0 = data;
		return true;*/
	REG_TPIDR_EL1:
		printf("XXXXX THREAD WRITE %p %p\n", data, read_pc());
		TPIDR_EL1 = data;
		return true;

	REG_VBAR_EL1:
		a64core.reg_offsets.VBAR[0] = data;
		return true;

	REG_OSLAR_EL1:
		OSLAR_EL1 = data & 1;
		return true;
	REG_OSDLR_EL1:
		return true;

	REG_CSSELR_EL1:
		CSSELR = data;
		return true;

	REG_DBGBVR0_EL1:
	REG_DBGBVR1_EL1:
	REG_DBGBCR0_EL1:
	REG_DBGBCR1_EL1:
	REG_DBGWVR0_EL1:
	REG_DBGWVR1_EL1:
	REG_DBGWCR0_EL1:
	REG_DBGWCR1_EL1:
		printf("sys-reg: want to update debug register: %x with %lx\n", reg, data);
		return true;

	REG_PMCCFILTR_EL0:
	REG_PMCCNTR_EL0:
	REG_PMCEID0_EL0:
	REG_PMCEID1_EL0:
	REG_PMCNTENCLR_EL0:
	REG_PMCNTENSET_EL0:
	REG_PMCR_EL0:
	REG_PMINTENCLR_EL1:
	REG_PMINTENSET_EL1:
	REG_PMMIR_EL1:
	REG_PMOVSCLR_EL0:
	REG_PMOVSSET_EL0:
	REG_PMSELR_EL0:
	REG_PMSWINC_EL0:
	REG_PMUSERENR_EL0:
	REG_PMXEVCNTR_EL0:
	REG_PMXEVTYPER_EL0:
		return env().write_core_device(cpu, 20, reg, data);

	REG_CNTKCTL_EL1:
	REG_CNTFRQ_EL0:
	REG_CNTPCT_EL0:
	REG_CNTVCT_EL0:
	REG_CNTP_TVAL_EL0:
	REG_CNTP_CTL_EL0:
	REG_CNTP_CVAL_EL0:
	REG_CNTVOFF_EL2:
	REG_CNTPS_TVAL_EL1:
	REG_CNTPS_CTL_EL1:
	REG_CNTPS_CVAL_EL1:
	REG_CNTV_TVAL_EL0:
	REG_CNTV_CTL_EL0:
	REG_CNTV_CVAL_EL0:
		return env().write_core_device(cpu, 18, reg, data);

	REG_FAR_EL1:
		a64core.reg_offsets.FAR_EL1[0] = data;
		return true;

	FPSR:
	{
		typedef x86::FloatingPointExceptions FPEs;

		FPEs exp = (FPEs)0;

		if (!(data & 0x80))
			exp = (FPEs)((int)exp | (int)FPEs::DenormalOperation);
		if (!(data & 0x02))
			exp = (FPEs)((int)exp | (int)FPEs::DivideByZero);
		if (!(data & 0x01))
			exp = (FPEs)((int)exp | (int)FPEs::InvalidOperation);
		if (!(data & 0x04))
			exp = (FPEs)((int)exp | (int)FPEs::Overflow);
		if (!(data & 0x10))
			exp = (FPEs)((int)exp | (int)FPEs::Precision);
		if (!(data & 0x08))
			exp = (FPEs)((int)exp | (int)FPEs::Underflow);

		x86::FPU::clear_exceptions(exp);

		return true;
	}

	REG_TRACECTL:
		switch (data)
		{
		case 0:
			printf("TRACING DEACTIVATED\n");
			__want_trace = false;
			cpu.invalidate_translations();
			break;

		case 1:
			printf("TRACING ACTIVATED\n");
			__want_trace = true;
			cpu.invalidate_translations();
			break;

		case 2:
			printf("PROFILING ACTIVATED\n");
			asm volatile("out %0, $0xfb\n" ::"a"(1));
			break;

		case 3:
			printf("PROFILING DEACTIVATED\n");
			asm volatile("out %0, $0xfb\n" ::"a"(0));
			break;

		default:
			printf("UNHANDLED TRACECTL OPERATION %lu\n", data);
			break;
		}

		return true;

	default:
		printf("sys-reg: write: [%08x] op0=%d, op1=%d, rn=%d, rm=%d, op2=%d, data=%016lx\n", reg, ra.op0, ra.op1, ra.crn, ra.crm, ra.op2, data);
		for (;;)
			asm volatile("nop");
	}

	return false;
}

SystemRegisters::register_access SystemRegisters::decode_access(uint32_t ir)
{
	register_access ra;

	ra.crm = (ir >> 8) & 0xf;
	ra.crn = (ir >> 12) & 0xf;
	ra.op0 = (ir >> 19) & 0x3;
	ra.op1 = (ir >> 16) & 0x7;
	ra.op2 = (ir >> 5) & 0x7;

	return ra;
}

void SystemRegisters::update_sctlr(arm64_cpu &cpu)
{
	if (SCTLR & 1)
	{
		captive::arch::mmu::strategy::mmu_strategy.enable();
	}
	else
	{
		captive::arch::mmu::strategy::mmu_strategy.disable();
	}
}
