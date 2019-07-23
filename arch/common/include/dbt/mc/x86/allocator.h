/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/support.h>
#include <dbt/util/list.h>
#include <dbt/util/map.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/machine.h>

#include "vreg-allocator.h"

class LiveRange;

namespace captive {
	namespace arch {
		namespace dbt {
			namespace mc {
				namespace x86 {
					class Instruction;
					class VirtualRegisterAllocator;

					class Allocator {
					public:

						Allocator(Support& support, VirtualRegisterAllocator& vra) : _support(support), _vreg_allocator(vra)
						{
						}

						bool allocate(Instruction *head);

					private:
						bool perform_allocation(Instruction *head);

						bool number_and_legalise_instructions(Instruction *head);
						bool compute_live_ranges(Instruction *head, LiveRange *live_ranges, dbt_u64 nr_live_ranges, dbt_u64& nr_active_ranges);
						bool commit_allocation(Instruction *head, const LiveRange *live_ranges, dbt_u64 nr_live_ranges);
						bool fixup_calls(Instruction *head, const LiveRange *live_ranges, dbt_u64 nr_live_ranges);
						bool verify(const Instruction *head);
						bool verify_instruction(const Instruction *head);

						X86Register allocated_register_from_range(const LiveRange *range, const X86Register& virt) const;

						Support& _support;
						VirtualRegisterAllocator& _vreg_allocator;
					};
				}
			}
		}
	}
}