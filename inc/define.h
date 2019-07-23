/* SPDX-License-Identifier: MIT */
#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

typedef uint64_t gpa_t;
typedef uint64_t gva_t;

#define __packed __attribute__((packed))

#define __barrier() asm volatile("": : :"memory")

#include <clever-endian.h>
