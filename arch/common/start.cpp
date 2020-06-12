/* SPDX-License-Identifier: MIT */

#include <printf.h>
#include <mm.h>
#include <env.h>
#include <cpu.h>
#include <dbt/dbt.h>
#include <smp.h>
#include <debug.h>
#include <device.h>
#include <malloc/malloc.h>
#include <malloc/page-allocator.h>
#include <mmu/host-mmu.h>
#include <mmu/strategy/strategy.h>
#include <smc/core-smc.h>
#include <smc/strategy.h>
#include <x86/lapic.h>
#include <x86/lapic-timer.h>
#include <x86/rdtsc-timer.h>
#include <x86/pit.h>
#include <x86/fpu.h>
#include <x86/cpuid.h>
#include <pump-timer.h>

extern captive::arch::Environment *create_environment_arm(captive::PerGuestData *per_guest_data);
extern captive::arch::Environment *create_environment_arm64(captive::PerGuestData *per_guest_data);
extern captive::arch::Environment *create_environment_um(captive::PerGuestData *per_guest_data);

//#define lprintf(a...) printf(a)
#define lprintf(a...)

extern void (*__init_array_start []) (void);
extern void (*__init_array_end []) (void);

volatile uint64_t *captive::arch::PumpTimer::value_ptr_;

namespace captive {
	namespace arch {
		void dump_host_info();
	}
}

static void call_static_constructors()
{
	size_t size = __init_array_end - __init_array_start;

	for (unsigned int i = 0; i < size; i++) {
		(*__init_array_start[i])();
	}
}

extern void foo(void);

namespace captive {
	namespace arch {
		extern int do_device_read(struct mcontext *);
		extern int do_device_write(struct mcontext *);
	}
}

bool __want_trace;

extern "C" {

	void __attribute__((noreturn)) start_run_core(captive::PerCPUData *cpu_data)
	{
		printf("run core waiting...\n");
		for (;;);
	}

	/*static void dump_cpuid_v(uint32_t category, uint32_t feature)
	{
		uint32_t eax, ebx, ecx, edx;
		eax = category;
		ecx = feature;
		
		asm volatile("cpuid" : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) : "a"(eax), "c"(ecx));
		
		printf("cpuid: %u.%u: EAX=%x, EBX=%x, ECX=%x, EDX=%x\n", category, feature, eax, ebx, ecx, edx);
	}
	
	static void dump_cpuid()
	{
		dump_cpuid_v(1, 0);
		dump_cpuid_v(7, 0);
		dump_cpuid_v(0xd, 0);
		dump_cpuid_v(0xd, 1);
		dump_cpuid_v(0x50000000, 0);
	}*/

	void __attribute__((noreturn)) start_boot_core(captive::PerCPUData *cpu_data)
	{
		// Run the static constructors.
		lprintf("calling static constructors...\n");
		call_static_constructors();

		// Initialise IRQs.
		lprintf("initialising lapic...\n");
		if (!captive::arch::x86::lapic.init()) {
			fatal("unable to initialise lapic\n");
		}

		captive::arch::x86::dump_cpu_features();

		captive::arch::x86::lapic.set_timer_irq(0x20);

		lprintf("initialising fpu...\n");
		if (!captive::arch::x86::FPU::init()) {
			fatal("unable to initialise fpu\n");
		}

		lprintf("initialising lapic timer...\n");
		if (!captive::arch::x86::lapic_timer.init()) {
			fatal("unable to initialise lapic timer\n");
		}

		lprintf("initialising rdtsc timer...\n");
		if (!captive::arch::x86::rdtsc_timer.init()) {
			fatal("unable to initialise rdtsc timer\n");
		}

		lprintf("initialising pump timer...\n");
		captive::arch::PumpTimer::initialise(&cpu_data->guest_data->jiffies);

		// Initialise the printf() system.
		lprintf("initialising printf @ %p\n", cpu_data->guest_data->printf_buffer);
		printf_init(cpu_data->guest_data->printf_buffer, 0x1000);

		// Initialise the malloc() memory allocation system.
		lprintf("initialising malloc @ pa=%p, va=%p, size=%lx\n", cpu_data->guest_data->heap_phys_base, cpu_data->guest_data->heap_virt_base, cpu_data->guest_data->heap_size);
		captive::arch::malloc::page_alloc.init(cpu_data->guest_data->heap_virt_base, cpu_data->guest_data->heap_phys_base, cpu_data->guest_data->heap_size);

		// Initialise the memory manager.
		lprintf("initialising mmu...\n");
		if (!captive::arch::mmu::host_mmu.initialise()) {
			fatal("unable to initialise mmu\n");
		}

		lprintf("initialising mmu strategy...\n");
		if (!captive::arch::mmu::strategy::mmu_strategy.initialise()) {
			fatal("unable to initialise mmu strategy\n");
		}

		lprintf("initialising core smc detection...\n");
		if (!captive::arch::smc::core_smc.initialise()) {
			fatal("unable to initialise smc strategy\n");
		}

		lprintf("initialising smc strategy...\n");
		if (!captive::arch::smc::smc_strategy.initialise()) {
			fatal("unable to initialise smc strategy\n");
		}

		// Dump host information
		captive::arch::dump_host_info();

		// Initialise other CPUs
		/*printf("initialising cpu 1...\n");
		captive::arch::smp_init_cpu(1);
		captive::arch::smp_cpu_start(1);*/

		// ---------------------------------
		//captive::arch::add_memory_watchpoint(0x0000000008b88580, 8, captive::arch::WatchpointTrigger::DATA_READ_WRITE);
		//captive::arch::add_memory_watchpoint((hva_t)guest_phys_to_vm_virt(0xbffffa40), 4, captive::arch::WatchpointTrigger::DATA_READ_WRITE);
		// ---------------------------------

		captive::arch::x86::lapic_timer.init_periodic((captive::arch::x86::lapic_timer.frequency() >> 4) / LAPIC_TIMER_FREQUENCY);
		lprintf("msec-per-jiffy: %lu\n", 1e3 / LAPIC_TIMER_FREQUENCY);
		captive::arch::x86::lapic_timer.start();

		lprintf("enabled events: %08x\n", cpu_data->guest_data->simulation_events);

		lprintf("creating arm64 environment...\n");
		captive::arch::Environment *env = create_environment_arm64(cpu_data->guest_data);

		if (!env) {
			printf("error: unable to create environment\n");
		} else {
			if (!env->init()) {
				printf("error: unable to initialise environment\n");
			} else if (!env->run(cpu_data)) {
				printf("error: unable to launch environment\n");
			}

			delete env;
		}
#ifdef INTERNAL_PERF
		captive::arch::x86::lapic.timer_stop();
#endif

		printf("done\n");
		abort();
	}

	void __attribute__((noreturn)) start_environment(captive::PerCPUData *cpu_data, int id)
	{
		lprintf("--------------------------------------------------------------------\n");
		lprintf("*** VCPU %d starting... (per_cpu_data=%p)\n", id, cpu_data);

		if (id == 0) start_boot_core(cpu_data);
		else start_run_core(cpu_data);
	}

	void handle_trap_unk(struct mcontext *mctx)
	{
		printf("unhandled exception: rip=0x%016lx v-pc=%016lx\n", mctx->rip, read_pc());
		dump_current_instruction();
		printf("\n");

		dump_mcontext(mctx);
		dump_code(mctx->rip);
		abort();
	}

	void handle_trap_simd(struct mcontext *mctx)
	{
		uint32_t mxcsr;
		asm volatile("stmxcsr %0" : "=m"(mxcsr));

		printf("simd exception: rip=0x%016lx v-pc=%016lx mxcsr=%08x excpt=%d\n", mctx->rip, read_pc(), mxcsr, mxcsr & 0x3f);
		dump_current_instruction();
		printf("\n");

		dump_mcontext(mctx);
		dump_code(mctx->rip);
		abort();
	}

	void handle_trap_unk_arg(struct mcontext *mctx)
	{
		printf("unhandled exception: rip=0x%lx, code=0x%lx\n", mctx->rip, mctx->extra);
		abort();
	}

	void handle_trap_gpf(struct mcontext *mctx)
	{
		captive::arch::CPU *cpu = captive::arch::CPU::get_active_cpu();

		if (cpu) {
			if (cpu->trace().enabled()) {
				cpu->trace().end_record();
			}
		}

		printf("general protection fault: rip=0x%lx, code=0x%lx, pc=0x%016lx\n", mctx->rip, mctx->extra, read_pc());
		dump_mcontext(mctx);
		dump_code(mctx->rip);

		dump_stack();
		fatal("END");
	}

	void handle_trap_irq0(struct mcontext *mctx)
	{
		captive::arch::x86::lapic.eoi();

		/*printf("irq0 @ rip=%p, pc=%p\n", mctx->rip, read_pc());
		dump_code(mctx->rip-16);
		
		dump_current_instruction();*/

		captive::arch::CPU *cpu = captive::arch::CPU::get_active_cpu();

		//printf("A = %lu %016lx\n", cpu->performance_counter_a(), cpu->performance_counter_a());
		//printf("B = %lu %016lx\n", cpu->performance_counter_b(), cpu->performance_counter_b());

		//cpu->cpu_data().guest_data->dump_code = !(cpu->cpu_data().guest_data->dump_code);*/

#if 1
		//__want_trace = !__want_trace;

		cpu->invalidate_translations();

		if (cpu->trace().enabled()) {
			cpu->trace().disable();
		} else {
			cpu->trace().enable();
		}

		printf("*** ENABLE TRACE, RIP=%p, PC=%p\n", mctx->rip, read_pc());
		return;

		printf("irq0 @ rip=%p\n", mctx->rip);
		dump_code(mctx->rip - 16);

		switch (cpu->cpu_data().signal_code) {
		case 2:
			cpu->dump_state();
			break;

		case 3:
			break;

		default:
			captive::arch::CPU::get_active_cpu()->handle_irq_raised();
			break;
		}
#endif
	}

	void handle_trap_irq1(struct mcontext *mctx)
	{
		captive::arch::x86::lapic.eoi();
		captive::arch::CPU::get_active_cpu()->handle_irq_raised();
	}

	static int handle_illegal(struct mcontext *mctx)
	{
		switch (*(uint8_t *) (mctx->rip + 1)) {
		case 0: mctx->rip += 2;
			return 0;
		default: fatal("unhandled illegal instruction @ %p\n", mctx->rip);
		}
	}

	int handle_trap_illegal(struct mcontext *mctx)
	{
		switch (*(uint8_t *) mctx->rip) {
		case 0xc4: return handle_illegal(mctx);
		default: dump_code(mctx->rip - 20);
			fatal("illegal instruction @ %p\n", mctx->rip);
		}
	}

	void handle_signal(struct mcontext *mctx)
	{
		printf("signal %d\n", captive::arch::CPU::get_active_cpu()->cpu_data().signal_code);
	}

	void handle_debug(struct mcontext *mctx)
	{
		//fatal("unhandled debug\n");

		//dump_current_instruction();

		//captive::arch::CPU::get_active_cpu()->dump_state(false);

		dump_mcontext(mctx);
		dump_sse();
		fatal("DEBUG\n");

		//fatal("DEBUG\n");
		//fatal("XXX mode=%u", captive::arch::CPU::get_active_cpu()->mmu().mode());
	}

	void handle_trap_dbz(struct mcontext *mctx)
	{
		dump_mcontext(mctx);
		dump_code(mctx->rip);
		fatal("DIVIDE BY ZERO %p PC=%016lx\n", mctx->rip, read_pc());
	}

	void handle_trap_breakpoint(struct mcontext *mctx)
	{
		printf("BREAKPOINT @ RIP=%p, PC=%016lx\n", mctx->rip, read_pc());

		dump_current_instruction();

		dump_mcontext(mctx);

		uint64_t *gpr = (uint64_t *) (uintptr_t) mctx->rbp;
		for (int i = 0; i < 31; i++) {
			printf("gpr %u = %016lx\n", i, gpr[i]);
		}

		uint64_t *fpr = (uint64_t *) (uintptr_t) (mctx->rbp + 0x100);
		for (int i = 0; i < 32; i++) {
			uint64_t fprlow = *fpr++;
			uint64_t fprhigh = *fpr++;

			printf("fpr %u = %016lx %016lx\n", i, fprhigh, fprlow);
		}

		//captive::arch::CPU::get_active_cpu()->dump_state(true);

		//fatal("NO DEBUGGER\n");
	}
}
