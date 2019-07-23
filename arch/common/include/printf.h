/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <stdarg.h>

extern void printf_init(uintptr_t base_address, size_t size);

extern int printf(const char *fmt, ...);
extern int fatal(const char *fmt, ...) __attribute__((noreturn));
extern void dump_instruction_at(gva_t va);
extern void dump_current_instruction();
extern int sprintf(char *buffer, const char *fmt, ...);
extern int scatf(char *buffer, const char *fmt, ...);
extern int snprintf(char *buffer, int size, const char *fmt, ...);
extern int vsnprintf(char *buffer, int size, const char *fmt, va_list args);
