/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <x86/defs.h>

namespace captive {
	namespace arch {
		namespace x86 {
			extern const char *x86_register_names[];

			struct MemoryInstruction {
				uint8_t length;
				uint8_t data_size;

				enum {
					I_MOV,
					I_MOVZX,
				} type;

				struct Operand Source;
				struct Operand Dest;

				void dump();
			};

			bool decode_memory_instruction(const uint8_t *code, MemoryInstruction& inst);
		}
	}
}
