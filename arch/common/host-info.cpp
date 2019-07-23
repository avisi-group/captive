/* SPDX-License-Identifier: MIT */

#include <printf.h>

namespace captive {
	namespace arch {
		void dump_host_info();
	}
}

struct X86_CR0 {

	union {
		uint64_t value;

		struct {
		};
	};
};

struct X86_CR4 {

	union {
		uint64_t value;

		struct {
		};
	};
};

using namespace captive::arch;

void captive::arch::dump_host_info()
{
	X86_CR0 cr0;
	X86_CR4 cr4;

	asm volatile("mov %%cr0, %0" : "=r"(cr0.value));
	asm volatile("mov %%cr4, %0" : "=r"(cr4.value));

	printf("*** HOST STARTUP INFORMATION\n");
	printf("cr0=%08x\n", cr0.value);
	printf("cr4=%08x\n", cr4.value);
}
