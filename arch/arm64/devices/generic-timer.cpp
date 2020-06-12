/* SPDX-License-Identifier: MIT */

#include <devices/generic-timer.h>
#include <arm64-env.h>
#include <printf.h>
#include <x86/lapic-timer.h>

#define EXTRACT_SYSREG(v) (v & 0x001fffe0)
#define HANDLE_SYSREG(op0,op1,crn,crm,op2) case (op0 << 19 | op1 << 16 | crn << 12 | crm << 8 | op2 << 5)

#define REG_CNTKCTL_EL1   HANDLE_SYSREG(3,0,14,1,0)

#define REG_CNTFRQ_EL0   HANDLE_SYSREG(3,3,14,0,0)
#define REG_CNTPCT_EL0   HANDLE_SYSREG(3,3,14,0,1)
#define REG_CNTVCT_EL0   HANDLE_SYSREG(3,3,14,0,2)

#define REG_CNTP_TVAL_EL0  HANDLE_SYSREG(3,3,14,2,0)
#define REG_CNTP_CTL_EL0  HANDLE_SYSREG(3,3,14,2,1)
#define REG_CNTP_CVAL_EL0  HANDLE_SYSREG(3,3,14,2,2)

#define REG_CNTVOFF_EL2   HANDLE_SYSREG(3,4,14,0,3)

#define REG_CNTPS_TVAL_EL1  HANDLE_SYSREG(3,7,14,2,0)
#define REG_CNTPS_CTL_EL1  HANDLE_SYSREG(3,7,14,2,1)
#define REG_CNTPS_CVAL_EL1  HANDLE_SYSREG(3,7,14,2,2)

#define REG_CNTV_TVAL_EL0  HANDLE_SYSREG(3,3,14,3,0)
#define REG_CNTV_CTL_EL0  HANDLE_SYSREG(3,3,14,3,1)
#define REG_CNTV_CVAL_EL0  HANDLE_SYSREG(3,3,14,3,2)

using namespace captive::arch::arm64::devices;

GenericTimer::GenericTimer(arm64_environment& env) : CoreDevice(env), PT(false), VT(true)
{
	CNTKCTL.bits = 0;

	captive::arch::x86::lapic_timer.callback(tick_callback, this);
}

void GenericTimer::tick_callback(void* ptr, uint64_t ticks)
{
	((GenericTimer *) ptr)->tick(ticks);
}

void GenericTimer::tick(uint64_t ticks)
{
	PT.tick(ticks);
	VT.tick(ticks);
}

void GenericTimer::GenericTimerImpl::tick(uint64_t ticks)
{
	COUNTER += ticks;
	update();
}

#define LWL

#ifdef LWL
static bool last_write;
#endif

void GenericTimer::GenericTimerImpl::update()
{
	//printf("gt: CTR: %lu %lu %lx\n", COUNTER, CVAL, CTL.bits);

	if (CTL.enable) {
		bool intr = (((int64_t) COUNTER - (int64_t) OFF) - (int64_t) CVAL) >= (int64_t) 0; //((CVAL - (COUNTER - OFF) - OFF)) >= CVAL;

		CTL.istatus = !!intr;
	} else {
		CTL.istatus = 0;
	}

	if (CTL.istatus && !CTL.imask) {
#ifdef LWL
		if (!last_write) {
#endif
			*(volatile uint8_t *)guest_phys_to_vm_virt(0x08030fff) = 1;
#ifdef LWL
			last_write = true;
		}
#endif
	} else {
#ifdef LWL
		if (last_write) {
#endif
			*(volatile uint8_t *)guest_phys_to_vm_virt(0x08030fff) = 0;
#ifdef LWL
			last_write = false;
		}
#endif
	}
}

bool GenericTimer::read(CPU& cpu, uint32_t reg, uint64_t& data)
{
	//printf("gt: read %x\n", reg);

	switch (EXTRACT_SYSREG(reg)) {
REG_CNTFRQ_EL0:
		data = 10000000ull;
		break;

REG_CNTV_CTL_EL0:
		data = VT.CTL.bits;
		break;

REG_CNTKCTL_EL1:
		data = CNTKCTL.bits;
		break;

REG_CNTVCT_EL0:
		data = VT.COUNTER - VT.OFF;
		break;

	default:
		printf("gt: unhandled read reg=%x\n", reg);
		abort();
		return false;
	}

	return true;
}

bool GenericTimer::write(CPU& cpu, uint32_t reg, uint64_t data)
{
	//printf("gt: write %x %lu\n", reg, data);

	switch (EXTRACT_SYSREG(reg)) {
REG_CNTV_CTL_EL0:
		VT.CTL.bits = data;
		VT.update();

		break;

REG_CNTV_TVAL_EL0:
		VT.tval(data);
		VT.update();

		break;

REG_CNTKCTL_EL1:
		CNTKCTL.bits = data;
		break;

	default:
		printf("gt: unhandled write reg=%x data=%lx\n", reg, data);
		abort();
		return false;
	}

	return true;
}
