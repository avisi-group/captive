/* SPDX-License-Identifier: MIT */

.globl __cyg_profile_func_enter
.globl __cyg_profile_func_exit

__cyg_profile_func_enter:
	outl %eax, $0xf1
	ret

__cyg_profile_func_exit:
	outl %eax, $0xf2
	ret
