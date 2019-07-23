/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/el/block.h>

namespace captive {
	namespace arch {
		namespace jit {
			namespace x86 {
				using namespace dbt::el;
				using namespace dbt::mc::x86;

				class X86Block : public Block {
				public:

					enum MarkType {
						NO_MARK,
						PERMANENT_MARK,
						TEMPORARY_MARK
					};

					X86Block(Context& ctx);

					Instruction *head() const
					{
						return _head;
					}

					X86Block *next0, *next1;
					bool linked;
					MarkType mark_type;

				private:
					Instruction *_head;
				};
			}
		}
	}
}
