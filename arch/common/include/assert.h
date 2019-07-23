/* SPDX-License-Identifier: MIT */
#pragma once

struct mcontext;

extern void __assertion_failure(const char *filename, int lineno, const char *expression) __attribute__((noreturn));

extern void dump_code(unsigned long int rip);
extern void dump_stack(void);
extern void dump_mcontext(const struct mcontext *mctx);
extern void dump_sse();

#ifdef NDEBUG
#define assert(_expr) (void)0
#else
#define assert(_expr) do { if (!(_expr)) { __assertion_failure(__FILE__, __LINE__, #_expr); __builtin_unreachable(); } } while(0)
#endif
