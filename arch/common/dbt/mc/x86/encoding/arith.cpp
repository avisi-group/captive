/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_add(TranslatedCodeBuffer& tcb, const Instruction *insn)
{
	return encode_arithmetic_reg_reg(tcb, 0, insn);
}

bool Encoder::encode_adc(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return encode_arithmetic_reg_reg(tcb, 0x10, insn);
}

bool Encoder::encode_sub(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return encode_arithmetic_reg_reg(tcb, 0x28, insn);
}

bool Encoder::encode_sbb(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return encode_arithmetic_reg_reg(tcb, 0x18, insn);
}

bool Encoder::encode_mul_div(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& divisor = insn->get_operand(0);

	int operation;
	switch (insn->kind()) {
	case InstructionKind::MUL: operation = 4;
		break;
	case InstructionKind::IMUL: operation = 5;
		break;
	case InstructionKind::DIV: operation = 6;
		break;
	case InstructionKind::IDIV: operation = 7;
		break;
	default: return false;
	}

	switch (insn->match1()) {
	case InstructionMatch::REG:
		if (divisor.reg.width == 8) {
			return encode_opcode_modrm_oper(tcb, 0xf6, operation, divisor);
		} else {
			return encode_opcode_modrm_oper(tcb, 0xf7, operation, divisor);
		}

	case InstructionMatch::MEM:
		if (divisor.mem.access_width == 8) {
			return encode_opcode_modrm_oper(tcb, 0xf6, operation, divisor);
		} else {
			return encode_opcode_modrm_oper(tcb, 0xf7, operation, divisor);
		}

	default:
		return false;
	}

	return false;
}

bool Encoder::encode_inc_dec(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& incremand = insn->get_operand(0);

	int operation;
	switch (insn->kind()) {
	case InstructionKind::INC: operation = 0;
		break;
	case InstructionKind::DEC: operation = 1;
		break;
	default: return false;
	}

	switch (insn->match1()) {
	case InstructionMatch::REG:
		if (incremand.reg.width == 8) {
			return encode_opcode_modrm_oper(tcb, 0xfe, operation, incremand);
		} else {
			return encode_opcode_modrm_oper(tcb, 0xff, operation, incremand);
		}

	case InstructionMatch::MEM:
		if (incremand.mem.access_width == 8) {
			return encode_opcode_modrm_oper(tcb, 0xfe, operation, incremand);
		} else {
			return encode_opcode_modrm_oper(tcb, 0xff, operation, incremand);
		}

	default:
		return false;
	}

	return false;
}

bool Encoder::encode_arithmetic_reg_reg(TranslatedCodeBuffer& tcb, dbt_u16 opcode, const Instruction* insn)
{
	const Operand& src = insn->get_operand(0);
	const Operand& dest = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
		assert_true(src.reg.width == dest.reg.width, "register sizes must be equal", insn);

		if (src.reg.width == 8) {
			return encode_opcode_modrm(tcb, opcode, src, dest);
		} else {
			return encode_opcode_modrm(tcb, opcode + 1, src, dest);
		}

	case InstructionMatch::REG_MEM:
		if (src.reg.width == 8) {
			return encode_opcode_modrm(tcb, opcode, src, dest);
		} else {
			return encode_opcode_modrm(tcb, opcode + 1, src, dest);
		}

	case InstructionMatch::MEM_REG:
		if (dest.reg.width == 8) {
			return encode_opcode_modrm(tcb, opcode + 2, dest, src);
		} else {
			return encode_opcode_modrm(tcb, opcode + 3, dest, src);
		}

	case InstructionMatch::CONST_REG:
		return encode_arithmetic_immediate(tcb, opcode >> 3, insn);

	case InstructionMatch::CONST_MEM:
		return encode_arithmetic_immediate(tcb, opcode >> 3, insn);

	default:
		assert_true(false, "unsupported encoding for arithmetic operation", insn);
		return false;
	}
}

bool Encoder::encode_arithmetic_immediate(TranslatedCodeBuffer& tcb, dbt_u8 oper, const Instruction* insn)
{
	const Operand& src = insn->get_operand(0);
	const Operand& dest = insn->get_operand(1);

	if (src.constant.width > 32) {
		if ((src.constant.value >> 32) == 0 || (src.constant.value >> 32) == 0xffffffff) {
			if (((src.constant.value >> 31) & 1) != ((src.constant.value >> 32) & 1)) {
				return false;
			}
		} else {
			return false;
		}

		//assert_true(src.constant.width <= 32, "immediate operand too wide");
	} else if (src.constant.width == 32 && (src.constant.value & 0x80000000)) {
		// Prevent sign-extension problems with constants
		if (dest.is_reg() && dest.reg.width > src.constant.width) {
			return false;
		} else if (dest.is_mem() && dest.mem.access_width > src.constant.width) {
			return false;
		}
	}

	if (dest.is_reg()) {
		if (dest.reg.width == 8) {
			if (!encode_opcode_modrm_oper(tcb, 0x80, oper, dest)) return false;
			tcb.emit8(src.constant.value);
		} else {
			if (src.constant.value < 128) {
				if (!encode_opcode_modrm_oper(tcb, 0x83, oper, dest)) return false;
				tcb.emit8(src.constant.value);
			} else if (((dbt_s32) src.constant.value < 0) && ((dbt_s32) src.constant.value > -127)) {
				encode_opcode_modrm_oper(tcb, 0x83, oper, dest);
				tcb.emit8(src.constant.value & 0xff);
			} else {
				encode_opcode_modrm_oper(tcb, 0x81, oper, dest);

				if (dest.reg.width == 32 || dest.reg.width == 64) {
					tcb.emit32(src.constant.value);
				} else if (dest.reg.width == 16) {
					tcb.emit16(src.constant.value);
				}
			}
		}

		return true;
	} else if (dest.is_mem()) {
		if (src.constant.width == 8) {
			encode_opcode_modrm_oper(tcb, 0x80, oper, dest);
			tcb.emit8(src.constant.value);
			return true;
		} else {
			if (src.constant.value < 128) {
				encode_opcode_modrm_oper(tcb, 0x83, oper, dest);
				tcb.emit8(src.constant.value);
				return true;
			} else {
				encode_opcode_modrm_oper(tcb, 0x81, oper, dest);

				if (src.constant.width == 32 || src.constant.width == 64) {
					tcb.emit32(src.constant.value);
					return true;
				} else {
					return false;
				}
			}
		}

		assert_true(false, "arith: unsupported encoding (arith const, mem)", insn);
		return false;
	} else {
		assert_true(false, "arith: unsupported encoding", insn);
		return false;
	}
}
