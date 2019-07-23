/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/common.h>
#include <dbt/mc/x86/instruction.h>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace mc {
				namespace x86 {
					class Instruction;
					class Operand;

					class Formatter {
					public:
						const char *format_instruction(const Instruction *insn);

					private:
						void append_operand(const Operand& operand);

						void append_hex(dbt_u64 v)
						{
							append("0x");
							append_num(v, 16);
						}

						void append_dec(dbt_u64 v)
						{
							append_num(v, 10);
						}
						void append_num(dbt_u64 v, dbt_u8 base);
						void append(const char *str);
						void append_char(char ch);
						void append_reg(const X86PhysicalRegister& reg, dbt_u8 width_in_bits);

						int cur;
						char buffer[512];
					};
				}
			}
		}
	}
}