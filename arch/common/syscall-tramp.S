/* SPDX-License-Identifier: MIT */

.code64
.text

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

.align 16
.globl call_gate_tramp
call_gate_tramp:
	push_regs

	mov %rsp, %rdi
	mov %r14, %rsi
	call do_fast_syscall

	pop_regs
	#addq $10, (%rsp)
	lretq

.align 16
.globl tail_call_ret0_only
tail_call_ret0_only:
	xor %eax, %eax
	ret
