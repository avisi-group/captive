/* SPDX-License-Identifier: MIT */

#pragma once

typedef unsigned char dbt_u8;
typedef unsigned short dbt_u16;
typedef unsigned int dbt_u32;
typedef unsigned long int dbt_u64;
typedef unsigned __int128 dbt_u128;
typedef signed char dbt_s8;
typedef signed short dbt_s16;
typedef signed int dbt_s32;
typedef signed long int dbt_s64;
typedef signed __int128 dbt_s128;

typedef float dbt_f32;
typedef double dbt_f64;

typedef unsigned long dbt_size_t;
typedef unsigned long dbt_off_t;

template<typename ElementType, int Width>
struct dbt_vector {
	ElementType lanes[Width];
};

#define __DBT_ARRAY_SIZE(_n) (sizeof((_n)) / sizeof((_n)[0]))
