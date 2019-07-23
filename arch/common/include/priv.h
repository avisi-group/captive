/* SPDX-License-Identifier: MIT */
#pragma once

static inline bool in_kernel_mode()
{
	unsigned short cs;
	asm volatile("mov %%cs, %0" : "=r"(cs));
	return(cs & 3) == 0;
}

static inline bool in_user_mode()
{
	unsigned short cs;
	asm volatile("mov %%cs, %0" : "=r"(cs));
	return(cs & 3) == 3;
}

static inline void switch_to_kernel_mode(void)
{
	asm volatile("int $0x80\n" :: : "rcx");
}

static inline void switch_to_user_mode(void)
{
	asm volatile("int $0x81\n" :: : "rcx");
}
