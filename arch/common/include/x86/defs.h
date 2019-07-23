/* SPDX-License-Identifier: MIT */
#pragma once

namespace captive {
	namespace arch {
		namespace x86 {

			struct Operand {

				enum {
					TYPE_IMMEDIATE,
					TYPE_REGISTER,
					TYPE_MEMORY
				} type;

				enum reg_idx {
					R_RAX, // 0
					R_RBX,
					R_RCX,
					R_RDX,
					R_RSP,
					R_RBP,
					R_RSI,
					R_RDI,

					R_EAX, // 8
					R_EBX,
					R_ECX,
					R_EDX,
					R_ESP,
					R_EBP,
					R_ESI,
					R_EDI,

					R_AX, // 16
					R_BX,
					R_CX,
					R_DX,
					R_SP,
					R_BP,
					R_SI,
					R_DI,

					R_AH, // 24
					R_BH,
					R_CH,
					R_DH,
					R_AL,
					R_BL,
					R_CL,
					R_DL,

					R_SPL, // 32
					R_BPL,
					R_SIL,
					R_DIL,

					R_R8B, // 36
					R_R9B,
					R_R10B,
					R_R11B,
					R_R12B,
					R_R13B,
					R_R14B,
					R_R15B,

					R_R8W, // 44
					R_R9W,
					R_R10W,
					R_R11W,
					R_R12W,
					R_R13W,
					R_R14W,
					R_R15W,

					R_R8D, // 52
					R_R9D,
					R_R10D,
					R_R11D,
					R_R12D,
					R_R13D,
					R_R14D,
					R_R15D,

					R_R8, // 60
					R_R9,
					R_R10,
					R_R11,
					R_R12,
					R_R13,
					R_R14,
					R_R15,

					R_Z,
				};

				union {
					uint64_t immed_val;
					reg_idx reg;

					struct {
						reg_idx base_reg_idx;
						reg_idx index_reg_idx;
						uint8_t scale;
						int32_t displacement;
					} mem;
				};

				void dump();
			};
		}
	}
}
