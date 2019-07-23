/* SPDX-License-Identifier: MIT */

.code64
.text

.globl start
.extern start_environment
start:
	// Disable interrupts
	cli

	// Disable the PIC (we're using the IOAPIC/LAPIC)
	mov $0xff, %eax
	out %al, $0xa1
	out %al, $0x21

	// Load the task register
	mov $0x2b, %eax
	ltr %ax

	// Stack canary
	movq $0xdeadbabecafef00d, %rax
	push %rax

	// Enable IO ports in R3
	pushf
	orl $0x3000, (%rsp)
	popf

	// Go!
	jmp start_environment

.macro push_regs
	pushf
	push %rax
	push %rbx
	push %rcx
	push %rdx
	push %rdi
	push %rsi
	push %rbp
	push %r8
	push %r9
	push %r10
	push %r11
	push %r12
	push %r13
	push %r14
	push %r15
.endm

.macro pop_regs
	add $8, %rsp	// Skip restoring R15
	pop %r14
	pop %r13
	pop %r12
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rbp
	pop %rsi
	pop %rdi
	pop %rdx
	pop %rcx
	pop %rbx
	pop %rax
	popf
.endm

.macro enter_intr,has_arg
.if ! \has_arg
	push $0
.endif
	push_regs

	mov %rsp, %rdi
.endm

.macro exit_intr
	pop_regs
	add $8, %rsp
	iretq
.endm

.macro trap_macro name,has_arg
.extern handle_trap_\name
.globl trap_\name
trap_\name:
	enter_intr \has_arg
	call handle_trap_\name
	exit_intr
.endm

trap_macro unk,0
trap_macro unk_arg,1
trap_macro gpf,1
trap_macro simd,0
trap_macro dbz,0
trap_macro debug,0
trap_macro breakpoint,0
trap_macro timer,0
trap_macro irq0,0
trap_macro irq1,0

.global trap_illegal
.extern interrupt_restore_safepoint
.extern cpu_safepoint
.extern handle_pagefault

.align 16
.global trap_pf
trap_pf:
	enter_intr 1

        swapgs
	mov %cr2, %rsi
	call handle_pagefault
        swapgs

	test %eax, %eax
	jnz 1f
	exit_intr

1:
	leaq cpu_safepoint, %rdi
	jmp interrupt_restore_safepoint
.size trap_pf,.-trap_pf

trap_illegal:
	enter_intr 0

	call handle_trap_illegal

	test %rax, %rax
	jnz 1f
	exit_intr

1:
	leaq cpu_safepoint, %rdi
	jmp interrupt_restore_safepoint

.globl trap_signal
.extern handle_signal
trap_signal:
	enter_intr 0
	call handle_signal
	exit_intr

.globl int90_handler
int90_handler:
	enter_intr 0
	mov %rsp, %rdi
	call handle_debug
	exit_intr

.globl int91_handler
int91_handler:
	enter_intr 0
	mov %rsp, %rdi
	call handle_single_step
	exit_intr
