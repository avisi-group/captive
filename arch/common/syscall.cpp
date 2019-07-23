/* SPDX-License-Identifier: MIT */

#include <syscall.h>
#include <printf.h>
#include <cpu.h>
#include <priv.h>
#include <x86/fpu.h>
#include <mmu/strategy/strategy.h>

//#define DEBUG_SYSCALLS

extern "C" {

	void do_fast_syscall(struct mcontext *mctx, uint64_t arg, uint64_t __unused, uint64_t syscall_nr)
	{
		switch (syscall_nr) {
		case 12:
		{
			captive::arch::x86::RoundingMode mode;
			captive::arch::x86::FPU::rounding_mode(captive::arch::x86::RoundingMode::RoundToZero);
			break;
		}
		case 13:
		{
			captive::arch::x86::RoundingMode mode = captive::arch::x86::FPU::rounding_mode();
			break;
		}
		default:
			printf("*** %u\n", syscall_nr);
			fatal("SYSCALLS DEPRECATED\n");
		}

	}
}
