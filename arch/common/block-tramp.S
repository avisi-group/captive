/* SPDX-License-Identifier: MIT */

.text
.align 16
.globl block_trampoline
.type block_trampoline,%function
block_trampoline:		// RDI = ?, RSI = code
    //pushf
    //orq $0x100, (%rsp)
    //popf

    push %r14
    push %r13
    push %r12
    push %rbx
    push %rbp

    // Store the stack pointer in a temporary location
    movq %rsp, (stack_temp)

    // Load the register file base address
    mov %fs:0x8, %rbp

    // Run the native code
#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_MPK
    int $0x81
#endif

    jmpq *%rsi

.globl block_trampoline_epilogue_normal
.type block_trampoline_epilogue_normal,%function
block_trampoline_epilogue_normal:
#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_MPK
    int $0x80
#endif

    // Restore the stack pointer from the temporary location
    movq (stack_temp), %rsp
    pop %rbp
    pop %rbx
    pop %r12
    pop %r13
    pop %r14

    xor %eax, %eax
    retq
.size block_trampoline_epilogue_normal, .-block_trampoline_epilogue_normal

.globl block_trampoline_epilogue_direct_fail
.type block_trampoline_epilogue_direct_fail,%function
block_trampoline_epilogue_direct_fail:
#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_MPK
    int $0x80
#endif

    // Restore the stack pointer from the temporary location
    movq (stack_temp), %rsp
    pop %rbp
    pop %rbx
    pop %r12
    pop %r13
    pop %r14

    mov $1, %eax
    retq
.size block_trampoline_epilogue_direct_fail, .-block_trampoline_epilogue_direct_fail

.globl block_trampoline_epilogue_direct_pred_target_fail
.type block_trampoline_epilogue_direct_pred_target_fail,%function
block_trampoline_epilogue_direct_pred_target_fail:
#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_MPK
    int $0x80
#endif

    // Restore the stack pointer from the temporary location
    movq (stack_temp), %rsp
    pop %rbp
    pop %rbx
    pop %r12
    pop %r13
    pop %r14

    mov $2, %eax
    retq
.size block_trampoline_epilogue_direct_pred_target_fail, .-block_trampoline_epilogue_direct_pred_target_fail

.globl block_trampoline_epilogue_direct_pred_fallthrough_fail
.type block_trampoline_epilogue_direct_pred_fallthrough_fail,%function
block_trampoline_epilogue_direct_pred_fallthrough_fail:
#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_MPK
    int $0x80
#endif

    // Restore the stack pointer from the temporary location
    movq (stack_temp), %rsp
    pop %rbp
    pop %rbx
    pop %r12
    pop %r13
    pop %r14

    mov $3, %eax
    retq
.size block_trampoline_epilogue_direct_pred_fallthrough_fail, .-block_trampoline_epilogue_direct_pred_fallthrough_fail



.data
.align 16
stack_temp: .quad 0