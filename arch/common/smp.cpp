/* SPDX-License-Identifier: MIT */

#include <smp.h>
#include <printf.h>

namespace captive {
	namespace arch {

		void smp_init_cpu(int tgt)
		{
			/*apic_write(ICRHI, (tgt & 0xf) << 24);
			apic_write(ICRLO, 0x4500);*/
		}

		void smp_cpu_start(int tgt)
		{
			/*apic_write(ICRHI, (tgt & 0xf) << 24);
			apic_write(ICRLO, 0x4600 | 0);*/
		}
	}
}
