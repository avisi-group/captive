/* SPDX-License-Identifier: MIT */

.text

//#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_TVAS

#if 0

.extern __tvas_invalidate_segment_priv
.extern __tvas_invalidate_segment_nonpriv

.align 16
.globl ___tvas_invalidate_segment_priv
___tvas_invalidate_segment_priv:
    push %rax
    push %rbx
    push %rcx
    push %rdx
    push %r8
    push %r9
    push %r10
    push %r11
    push %r12
    push %r13
    push %r14
    call __tvas_invalidate_segment_priv
    pop %r14
    pop %r13
    pop %r12
    pop %r11
    pop %r10
    pop %r9
    pop %r8
    pop %rdx
    pop %rcx
    pop %rbx
    pop %rax
    ret

.align 16
.globl ___tvas_invalidate_segment_nonpriv
___tvas_invalidate_segment_nonpriv:
    push %rax
    push %rbx
    push %rcx
    push %rdx
    push %r8
    push %r9
    push %r10
    push %r11
    push %r12
    push %r13
    push %r14
    call __tvas_invalidate_segment_nonpriv
    pop %r14
    pop %r13
    pop %r12
    pop %r11
    pop %r10
    pop %r9
    pop %r8
    pop %rdx
    pop %rcx
    pop %rbx
    pop %rax
    ret

#endif