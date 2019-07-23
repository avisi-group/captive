/* SPDX-License-Identifier: MIT */

.text

.align 16
.globl __fast_zero_page
__fast_zero_page:
	xor %eax, %eax
	mov $0x200, %ecx
	cld
	rep stosq %rax, %es:(%rdi)
	ret

.align 16
.globl memset
memset:
	test %rsi, %rsi
	jz 1f

	cld
	mov %esi, %eax
	mov %rdx, %rcx
	jmp 2f

1:
	mov %rdx, %rsi

.align 16
.globl bzero
bzero:
	cld

	mov %rsi, %rcx
	shr $3, %rcx

	xor %eax, %eax
	
	rep stosq %rax, %es:(%rdi)

	movq %rsi, %rcx
	and $3, %rcx

.align 16
2:
	rep stosb %al, %es:(%rdi)

	mov %rdi, %rax
	ret

.align 16
.globl memcpy
memcpy:
	// Copy the destination pointer into RAX
	mov %rdi, %rax

	// Clear the direction flag
	cld

	// Copy the size into RCX, and divide by eight.
	mov %rdx, %rcx
	shr $3, %rcx
	
	// Perform 8-byte wide memory moves to get the bulk of the data moved.
	rep movsq %ds:(%rsi), %es:(%rdi)

	// Copy the size into ECX, and mask it by 7, to get the amount of data
	// left to copy.
	mov %edx, %ecx
	and $7, %ecx

	// Perform 1-byte wide memory moves to get the rest of the data moved.
	rep movsb %ds:(%rsi), %es:(%rdi)
	
	// Finished.
	ret
