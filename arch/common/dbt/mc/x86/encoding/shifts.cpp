/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_shift(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& amount = insn->get_operand(0);
	const auto& value = insn->get_operand(1);

	unsigned int shift_kind = 0;
	switch (insn->kind()) {
	case InstructionKind::SHL: shift_kind = 4;
		break;
	case InstructionKind::SHR: shift_kind = 5;
		break;
	case InstructionKind::SAR: shift_kind = 7;
		break;
	case InstructionKind::ROL: shift_kind = 0;
		break;
	case InstructionKind::ROR: shift_kind = 1;
		break;
	default: return false;
	}

	switch (amount.kind) {
	case OperandKind::REGISTER:
		if (amount.reg.reg != X86PhysicalRegisters::C && amount.reg.width != 8) {
			assert_true(false, "shift by register must use %cl", insn);
			return false;
		}

		switch (value.kind) {
		case OperandKind::REGISTER:
			if (value.reg.width == 8) {
				return encode_opcode_modrm_oper(tcb, 0xd2, shift_kind, value);
			} else {
				return encode_opcode_modrm_oper(tcb, 0xd3, shift_kind, value);
			}

		default:
			return false;
		}

	case OperandKind::CONSTANT:
		assert_true(amount.constant.width == 8, "constant shift must be imm8", insn);

		switch (value.kind) {
		case OperandKind::REGISTER:
			if (value.reg.width == 8) {
				if (amount.constant.value == 1) {
					return encode_opcode_modrm_oper(tcb, 0xd0, shift_kind, value);
				} else {
					if (!encode_opcode_modrm_oper(tcb, 0xc0, shift_kind, value)) return false;
					tcb.emit8(amount.constant.value);
				}
			} else {
				if (amount.constant.value == 1) {
					return encode_opcode_modrm_oper(tcb, 0xd1, shift_kind, value);
				} else {
					if (!encode_opcode_modrm_oper(tcb, 0xc1, shift_kind, value)) return false;
					tcb.emit8(amount.constant.value);
				}
			}
			break;

		default:
			return false;
		}

		return true;

	default:
		assert_true(false, "unsupported encoding for shift", insn);
		return false;
	}
}
