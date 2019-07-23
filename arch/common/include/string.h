/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

extern "C" void *memset(void *, int, size_t);
extern "C" void *memcpy(void *, const void *, size_t);
extern void *memmove(void *, const void *, size_t);
extern int memcmp(const void *, const void *, size_t);
extern "C" void *bzero(void *, size_t);

extern int strlen(const char *);
extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, int n);
extern char *strcat(char *, const char *);
extern char *strncat(char *, const char *, int n);

extern int strcmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t n);

extern char *strdup(const char *str);

extern "C" void __fast_zero_page(void *);
