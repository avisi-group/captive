/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/support.h>
#include <dbt/mc/x86/machine.h>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace mc {
				namespace x86 {

					class VirtualRegisterAllocator {
					public:

						VirtualRegisterAllocator() : _next_index(48)
						{
						}

						X86PhysicalRegister alloc_vreg(X86RegisterClasses::X86RegisterClasses regclass)
						{
							dbt_u64 vreg_index = _next_index;
							_next_index++;

							return X86PhysicalRegisters::create_virtual(regclass, vreg_index);
						}

						dbt_u64 next_index() const
						{
							return _next_index;
						}

					private:
						dbt_u64 _next_index;
					};
				}
			}
		}
	}
}
