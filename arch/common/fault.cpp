/* SPDX-License-Identifier: MIT */

#include <printf.h>
#include <mm.h>
#include <env.h>
#include <cpu.h>
#include <mmu.h>
#include <device.h>
#include <x86/decode.h>

using namespace captive::arch;

namespace captive {
	namespace arch {
		extern uint64_t __page_faults;
	}
}


#define PF_PRESENT  (1 << 0)
#define PF_WRITE  (1 << 1)
#define PF_USER_MODE (1 << 2)

#ifndef NDEBUG
uint64_t page_faults;
uint64_t page_fault_reasons[8];
#endif

#if 0

extern "C" int xx_handle_pagefault(struct mcontext *mctx, uint64_t va)
{
	uint64_t code = mctx->extra;
	uint64_t rip = mctx->rip;

	if (rip < VM_VIRT_SPLIT) {
		dump_mcontext(mctx);
		dump_stack();
		fatal("page fault handler with return address in guest vm arena");
	}

	if (va < VM_VIRT_SPLIT) {
		captive::arch::CPU *core = captive::arch::CPU::get_active_cpu();

		//printf("fault %p\n", va);

		// Turn the faulting VA into a real GVA, based on the current mode.

		gva_t real_gva;
		switch (core->mmu().mode()) {
		case MMUMode::LOW_VM_0: real_gva = va;
			break;
		case MMUMode::HIGH_VM_0: real_gva = va + 0x0000800000000000ULL;
			break;
		case MMUMode::LOW_VM_1: real_gva = va + 0xffff000000000000ULL;
			break;
		case MMUMode::HIGH_VM_1: real_gva = va + 0xffff800000000000ULL;
			break;
		case MMUMode::ONE_TO_ONE: real_gva = va;
			break;
		default:
			printf("fatal: guest memory fault in invalid mode: va=%p mode=%u code=%u\n", va, core->mmu().mode(), code);
			abort();
		}

		MMU::resolution_context ctx(real_gva);

		ctx.emulate_user = false;
		bool user_mode = !!(code & PF_USER_MODE);

		if (ctx.va == read_pc() && !(code & PF_WRITE)) {
			// Detect a fetch
			ctx.requested_permissions = user_mode ? MMU::USER_FETCH : MMU::KERNEL_FETCH;
		} else {
			// Detect a READ/WRITE
			if (code & PF_WRITE) {
				ctx.requested_permissions = user_mode ? MMU::USER_WRITE : MMU::KERNEL_WRITE;
			} else {
				ctx.requested_permissions = user_mode ? MMU::USER_READ : MMU::KERNEL_READ;
			}
		}

		if (core->mmu().handle_fault(ctx)) {
			if (ctx.fault == MMU::DEVICE_FAULT) {
				handle_device_fault(core, mctx, ctx.pa);
				return 0;
			} else if (ctx.fault == MMU::SMC_FAULT) {
				return 2;
			} else if (ctx.fault == MMU::NONE) {
				//printf("mmu: va=%p pa=%p\n", ctx.va, ctx.pa);
				return 0;
			} else {
				// Invoke the target platform behaviour for the memory fault
				// Return TRUE if we need to return to the safe-point, i.e. to do a side
				// exit from the currently executing guest instruction.

				//printf("faulty mcfault fake-va=%p real-va=%p pc=%p rip=%p\n", va, real_gva, read_pc(), mctx->rip);

				if (core->trace().enabled()) {
					printf("<MEMORY FAULT>\n");
				}

				if (!core->handle_mmu_fault(ctx)) {
					printf("mmu: failed to handle fault\n");
					abort();
				}

				return 1;
			}
		} else {
			printf("fatal: unhandled page-fault @ va=%p, pc=%p", ctx.va, read_pc());
			abort();
		}
	} else {
		// This page-fault happened elsewhere - we can't do anything about it.
		printf("fatal: internal page-fault: rip=%lx va=%lx, code=%x, pc=%08x\n", rip, va, code, read_pc());

		printf("  type:   %s\n", (code & PF_WRITE) ? "write" : "read");
		printf("  mode:   %s\n", (code & PF_USER_MODE) ? "user" : "kernel");
		printf("  reason: %s\n", (code & PF_PRESENT) ? "permission" : "not present");

		dump_mcontext(mctx);
		dump_stack();

		abort();
	}

	/*// If the virtual address is in the lower 4GB, then is is a guest
	// instruction (or decode) taking a memory fault.
	
#ifndef NDEBUG
	page_faults++;
	
	if (code & PF_PRESENT) {
		if (code & PF_WRITE) {
			// Protection Violation + Write
			
			if (code & PF_USER_MODE) {
				// Protection Violation + Write + User Mode
				page_fault_reasons[0]++;
			} else {
				// Protection Violation + Write + Kernel Mode
				page_fault_reasons[1]++;
			}
		} else {
			// Protection Violation + Read
			
			if (code & PF_USER_MODE) {
				// Protection Violation + Read + User Mode
				page_fault_reasons[2]++;
			} else {
				// Protection Violation + Read + Kernel Mode
				page_fault_reasons[3]++;
			}
		}		
	} else {
		if (code & PF_WRITE) {
			// Not Present + Write
			
			if (code & PF_USER_MODE) {
				// Not Present + Write + User Mode
				page_fault_reasons[4]++;
			} else {
				// Not Present + Write + Kernel Mode
				page_fault_reasons[5]++;
			}
		} else {
			// Not Present + Read
			
			if (code & PF_USER_MODE) {
				// Not Present + Read + User Mode
				page_fault_reasons[6]++;
			} else {
				// Not Present + Read + Kernel Mode
				page_fault_reasons[7]++;
			}
		}	
	}
#endif
	
	if (va < VM_VIRT_SPLIT) {
		bool emulate_user = false;
		
		//printf("mmu")
		
		// Obtain the core that is currently active.
		captive::arch::CPU *core = captive::arch::CPU::get_active_cpu();
		
		if (core) {
			MMU::resolution_context rc(va);
			
			bool user_mode = false;
			
			// Prepare an access_info structure to describe the memory access
			// to the MMU.
			if (emulate_user) {
				rc.emulate_user = true;
				user_mode = true;
			} else {
				rc.emulate_user = false;
				user_mode = !!(code & PF_USER_MODE);
			}

			if ((uint32_t)va == read_pc() && !(code & PF_WRITE)) {
				// Detect a fetch
				rc.requested_permissions = user_mode ? MMU::USER_FETCH : MMU::KERNEL_FETCH;
			} else {
				// Detect a READ/WRITE
				if (code & PF_WRITE) {
					rc.requested_permissions = user_mode ? MMU::USER_WRITE : MMU::KERNEL_WRITE;
				} else {
					rc.requested_permissions = user_mode ? MMU::USER_READ : MMU::KERNEL_READ;
				}
			}

			// Get the core's MMU to handle the fault.
			if (core->mmu().handle_fault(rc)) {
				// If we got this far, then the fault was handled by the core's logic.
				printf("mmu: handled page-fault: va=%lx, pa=%lx, ctxid=%lx, rperms=%x, aperms=%x, fault=%x\n", 
						rc.va, 
						rc.pa, 
						core->mmu().context_id(), 
						rc.requested_permissions, 
						rc.allowed_permissions, 
						rc.fault);

				if (rc.fault == MMU::DEVICE_FAULT) {
					handle_device_fault(core, mctx, rc.pa);
					return 0;
				} else if (rc.fault == MMU::SMC_FAULT) {
					return 2;
				} else if (rc.fault == MMU::NONE) {
					return 0;
				} else {
					// Invoke the target platform behaviour for the memory fault
					// Return TRUE if we need to return to the safe-point, i.e. to do a side
					// exit from the currently executing guest instruction.
					core->handle_mmu_fault(rc.fault);
					return 1;
				}
			} else {
				// If the core couldn't handle the fault, then we've got a serious problem.
				fatal("unhandled page-fault: va=%lx, code=%x, pc=%lx, rip=%lx\n", va, code, read_pc(), mctx->rip);
			}
		} else {
			// We can't handle this page fault if we haven't got an active core.
			fatal("unhandled page-fault: va=%lx, code=%x, (no cpu)\n", va, code);
		}
	} else {
		// This page-fault happened elsewhere - we can't do anything about it.
		printf("fatal: internal page-fault: rip=%lx va=%lx, code=%x, pc=%08x\n", rip, va, code, read_pc());

		printf("  type:   %s\n", (code & PF_WRITE) ? "write" : "read");
		printf("  mode:   %s\n", (code & PF_USER_MODE) ? "user" : "kernel");
		printf("  reason: %s\n", (code & PF_PRESENT) ? "permission" : "not present");
		
		dump_mcontext(mctx);
		dump_stack();

		abort();
	}

	unreachable();*/
}
#endif
