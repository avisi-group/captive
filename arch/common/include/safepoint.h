/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

typedef struct safepoint {
	uint64_t rbx, rsp, rbp, r12, r13, r14, r15, rip, rflags;
} safepoint_t;

extern "C" int record_safepoint(safepoint_t *sp);
extern "C" int restore_safepoint(safepoint_t *sp, int v);
extern "C" int interrupt_restore_safepoint(safepoint_t *sp, int v);
