/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/support.h>
#include <dbt/util/list.h>
#include <dbt/util/map.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/machine.h>

#include "vreg-allocator.h"

struct VirtualRegister;

namespace captive {
	namespace arch {

		namespace dbt {
			namespace mc {
				namespace x86 {
					class Instruction;
					class VirtualRegisterAllocator;

					class ReverseAllocator {
					public:

						ReverseAllocator(Support& support, VirtualRegisterAllocator& vra) : _support(support), _vreg_allocator(vra)
						{
						}

						bool allocate(Instruction *head);

					private:
						bool number_and_legalise_instructions(Instruction *head);
						bool calculate_vreg_live_ranges(VirtualRegister *vregs, Instruction *head);
						bool do_allocate(VirtualRegister *vregs, Instruction *head);

						bool commit(Instruction *head, const VirtualRegister *vreg_to_preg);
						bool verify(const Instruction *head);
						bool verify_instruction(const Instruction *insn);
						bool decorate_call(Instruction *head, int nr_args);
						bool fixup_calls(Instruction *head);

						Support& _support;
						VirtualRegisterAllocator& _vreg_allocator;
					};
				}
			}
		}
	}
}
