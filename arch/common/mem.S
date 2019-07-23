/* SPDX-License-Identifier: MIT */

.code64
.text

.align 16
.globl int60_handler
int60_handler:
	// AL = MODE

        //incq %fs:0x40
        //incq %fs:0xc0(,%rcx,8)

	// Update JIT state mode
	mov %al, %fs:0x68
	mov %fs:0x70(,%rax,8), %rax
	mov %rax, %cr3
	iretq

.align 16
.globl int61_handler
int61_handler:
	mov %rdi, %cr3
	iretq

.align 16
.globl int62_handler
int62_handler:
        //mov $3, %edi

        //push $0
        //push $0
        //invpcid (%rsp), %rdi
        //add $16, %rsp

	mov %cr3, %rdi
	mov %rdi, %cr3
	iretq

.align 16
.globl memory_access_handler
memory_access_handler:
	// CL = MODE

	// Update JIT state mode
	mov %al, %fs:0x68
	mov %fs:0x70(,%rax,8), %rax
	mov %rax, %cr3
        lretq

.align 16
.globl syscall_memory_access_handler
syscall_memory_access_handler:
    mov %al, %fs:0x68
    mov %fs:0x70(,%rax,8), %rax
    mov %rax, %cr3
    sysretq
