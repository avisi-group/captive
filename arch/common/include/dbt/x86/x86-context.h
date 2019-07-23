/* SPDX-License-Identifier: MIT */

#pragma once

#include <define.h>
#include <dbt/el/context.h>
#include <list>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace mc {
				namespace x86 {
					class Instruction;
				}
			}
		}

		namespace jit {
			namespace x86 {
				class X86Emitter;
				class X86Value;
				class X86Block;

				class X86Context : public dbt::el::Context {
					friend class X86Emitter;
					friend class X86Value;
					friend class X86Block;

				public:
					X86Context(dbt::Support& support);
					virtual ~X86Context();

					dbt::el::Block* create_block() override;

					dbt::el::Block* entry_block() const override
					{
						return _entry_block;
					}

					dbt::mc::x86::Instruction* start_instruction() const;

					bool link();
					bool link_visit(X86Block *block, std::list<X86Block *>& sorted_list);
					bool optimise_control_flow();

				private:
					dbt::el::Block *_entry_block;
				};
			}
		}
	}
}
