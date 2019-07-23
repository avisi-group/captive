/* SPDX-License-Identifier: MIT */

#include <debug.h>
#include <printf.h>
#include <cpu.h>
#include <mmu.h>

using namespace captive::arch;

static inline uint64_t __read_dr7()
{
	uint64_t dr7;
	asm volatile("mov %%dr7, %0" : "=r"(dr7) ::"memory");
	return dr7;
}

static inline void __write_dr7(uint64_t dr7)
{
	asm volatile("mov %0, %%dr7" ::"r"(dr7) : "memory");
}

static inline uint8_t watchpoint_trigger_to_dr(WatchpointTrigger::WatchpointTrigger trigger)
{
	switch (trigger) {
	case WatchpointTrigger::EXECUTION: return 0;
	case WatchpointTrigger::DATA_WRITE: return 1;
	case WatchpointTrigger::DATA_READ_WRITE: return 3;
	default: assert(false);
	}
}

static inline uint8_t watchpoint_size_to_dr(uint8_t size)
{
	switch (size) {
	case 1: return 0;
	case 2: return 1;
	case 4: return 3;
	case 8: return 2;
	default: assert(false);
	}
}

struct watchpoint {
	unsigned int debug_register;
	bool valid;
	hva_t addr;
	uint8_t size;
	WatchpointTrigger::WatchpointTrigger trigger;
};

#define NR_WATCHPOINTS 4
static watchpoint watchpoints[NR_WATCHPOINTS];

static void disable_watchpoint(const watchpoint& wp)
{
	uint64_t dr7 = __read_dr7();

	switch (wp.debug_register) {
	case 0:
		dr7 = dr7 & ~0x00000003ull;
		break;
	case 1:
		dr7 = dr7 & ~0x0000000cull;
		break;
	case 2:
		dr7 = dr7 & ~0x00000030ull;
		break;
	case 3:
		dr7 = dr7 & ~0x000000c0ull;
		break;
	default: assert(false);
	}

	__write_dr7(dr7);
}

static void enable_watchpoint(const watchpoint& wp)
{
	uint64_t dr7 = __read_dr7();

	switch (wp.debug_register) {
	case 0:
		dr7 = dr7 & ~0x00000003ull;
		dr7 |= 0x3 << 0;
		break;
	case 1:
		dr7 = dr7 & ~0x0000000cull;
		dr7 |= 0x3 << 2;
		break;
	case 2:
		dr7 = dr7 & ~0x00000030ull;
		dr7 |= 0x3 << 4;
		break;
	case 3:
		dr7 = dr7 & ~0x000000c0ull;
		dr7 |= 0x3 << 6;
		break;
	default: assert(false);
	}

	__write_dr7(dr7);
}

static void sync_watchpoint(const watchpoint& wp)
{
	if (wp.valid) {
		uint64_t dr7 = __read_dr7();

		switch (wp.debug_register) {
		case 0:
			dr7 = dr7 & ~0x000f0003ull;
			dr7 |= 0x3 << 0;
			dr7 |= watchpoint_trigger_to_dr(wp.trigger) << 16;
			dr7 |= watchpoint_size_to_dr(wp.size) << 18;

			asm volatile("mov %0, %%dr0" ::"r"(wp.addr));
			break;
		case 1:
			dr7 = dr7 & ~0x00f0000cull;
			dr7 |= 0x3 << 2;
			dr7 |= watchpoint_trigger_to_dr(wp.trigger) << 20;
			dr7 |= watchpoint_size_to_dr(wp.size) << 22;

			asm volatile("mov %0, %%dr1" ::"r"(wp.addr));
			break;
		case 2:
			dr7 = dr7 & ~0x0f000030ull;
			dr7 |= 0x3 << 4;
			dr7 |= watchpoint_trigger_to_dr(wp.trigger) << 24;
			dr7 |= watchpoint_size_to_dr(wp.size) << 26;

			asm volatile("mov %0, %%dr2" ::"r"(wp.addr));
			break;
		case 3:
			dr7 = dr7 & ~0xf00000c0ull;
			dr7 |= 0x3 << 6;
			dr7 |= watchpoint_trigger_to_dr(wp.trigger) << 28;
			dr7 |= watchpoint_size_to_dr(wp.size) << 30;

			asm volatile("mov %0, %%dr3" ::"r"(wp.addr));
			break;
		default: assert(false);
		}

		__write_dr7(dr7);
	} else {
		uint64_t dr7 = __read_dr7();

		switch (wp.debug_register) {
		case 0:
			dr7 = dr7 & ~0x000f0003ull;
			break;
		case 1:
			dr7 = dr7 & ~0x00f0000cull;
			break;
		case 2:
			dr7 = dr7 & ~0x0f000030ull;
			break;
		case 3:
			dr7 = dr7 & ~0xf00000c0ull;
			break;
		default: assert(false);
		}

		__write_dr7(dr7);
	}
}

static void sync_watchpoints()
{
	for (unsigned int i = 0; i < NR_WATCHPOINTS; i++) {
		sync_watchpoint(watchpoints[i]);
	}
}

void captive::arch::init_memory_watchpoints()
{
	for (unsigned int i = 0; i < NR_WATCHPOINTS; i++) {
		watchpoints[i].debug_register = i;
		watchpoints[i].valid = false;
	}

	sync_watchpoints();
}

void captive::arch::add_memory_watchpoint(hva_t va, uint8_t size, WatchpointTrigger::WatchpointTrigger trigger)
{
	for (unsigned int i = 0; i < NR_WATCHPOINTS; i++) {
		if (watchpoints[i].valid && watchpoints[i].addr == va) return;
	}

	for (unsigned int i = 0; i < NR_WATCHPOINTS; i++) {
		if (!watchpoints[i].valid) {
			watchpoints[i].addr = va;
			watchpoints[i].size = size;
			watchpoints[i].trigger = trigger;
			watchpoints[i].valid = true;

			sync_watchpoint(watchpoints[i]);
			return;
		}
	}
}

void captive::arch::remove_memory_watchpoint(hva_t va)
{
	for (unsigned int i = 0; i < NR_WATCHPOINTS; i++) {
		if (watchpoints[i].valid && watchpoints[i].addr == va) {
			watchpoints[i].valid = false;
			sync_watchpoint(watchpoints[i]);
			return;
		}
	}
}

void captive::arch::watchpoints_enable()
{
}

void captive::arch::watchpoints_disable()
{
}

static const watchpoint& get_watchpoint_from_dr6()
{
	uint64_t dr6;
	asm volatile("mov %%dr6, %0" : "=r"(dr6));

	switch (dr6 & 0xf) {
	case 1: return watchpoints[0];
	case 2: return watchpoints[1];
	case 4: return watchpoints[2];
	case 8: return watchpoints[3];
	default: printf("multiple breakpoints asserted\n");
		assert(false);
	}
}

static void reset_dr6()
{
	asm volatile("mov %0, %%dr6" ::"r"((uint64_t) 0));
}

extern "C" void handle_trap_debug()
{
	const watchpoint& wp = get_watchpoint_from_dr6();
	reset_dr6();
	if (!wp.valid) return;

	auto cpu = CPU::get_active_cpu();
	if (!cpu) return;

	//fatal("NOT IMPLEMENTED");

	disable_watchpoint(wp);
	printf("*** WATCHPOINT PC=%p, hva=%p value=%016x!!!\n", read_pc(), wp.addr, *(uint64_t *) wp.addr);
	enable_watchpoint(wp);

#if 0
	uintptr_t fake_hva = (uintptr_t) wp.addr;
	uintptr_t real_gva;

	switch (cpu->mmu().mode()) {
	case MMUMode::LOW_VM_0: real_gva = fake_hva;
		break;
	case MMUMode::HIGH_VM_0: assert(false);
		break;
	case MMUMode::LOW_VM_1: real_gva = fake_hva + 0xffff000000000000ULL;
		break;
	case MMUMode::HIGH_VM_1: real_gva = fake_hva + 0xffff800000000000ULL;
		break;
	case MMUMode::ONE_TO_ONE: real_gva = fake_hva;
		break;
	default: abort();
	}

	disable_watchpoint(wp);
	printf("*** WATCHPOINT PC=%p, hva=%p, gva=%p, value=%lx!!!\n", read_pc(), fake_hva, real_gva, *(uint64_t *) fake_hva);
	enable_watchpoint(wp);
#endif
}

extern "C" void handle_single_step()
{
	auto cpu = CPU::get_active_cpu();
	if (!cpu) fatal("SINGLE STEP\n");

	cpu->handle_single_step();
}
