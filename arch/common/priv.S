/* SPDX-License-Identifier: MIT */

.code64
.text

.align 16

// Switch to KERNEL MODE
.globl int80_handler
int80_handler:
//	push %rcx
//	mov %fs:0x50, %rcx		// Load pointer to _kernel_mode
//	movb $1, (%rcx)			// Store 1
//        orl $0x40000000, %fs:0x60
//	pop %rcx

	movq $0x08,  8(%rsp)	// CS
	movq $0x10, 32(%rsp)	// SS

	iretq

.align 16

// Switch to USER MODE
.globl int81_handler
int81_handler:
	//push %rcx
	//mov %fs:0x50, %rcx		// Load pointer to _kernel_mode
	//movb $0, (%rcx)			// Store 0
        //andl $0xbfffffff, %fs:0x60
	//pop %rcx

	movq $0x1b,  8(%rsp)	// CS
	movq $0x23, 32(%rsp)	// SS

	iretq

.align 16

// Flushing the TLB
.globl int82_handler
int82_handler:
	push %rax
	//mov %cr3, %rax
	//mov %rax, %cr3
        mov $3, %eax
        invpcid __invpcid_tmp, %rax
	pop %rax

	iretq

.align 16
__invpcid_tmp:
.quad 0
.quad 0

.align 16

// Invalidate Translation
.globl int83_handler
.extern interrupt_restore_safepoint
.extern cpu_safepoint
int83_handler:
	mov $0x10, %eax
	leaq cpu_safepoint, %rdi
	jmp interrupt_restore_safepoint

.align 16

.globl syscall_handler
syscall_handler:
	jmp *%rcx
