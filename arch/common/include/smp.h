/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		extern void smp_init_cpu(int cpu);
		extern void smp_cpu_start(int cpu);
	}
}
