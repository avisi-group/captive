/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_and(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return encode_arithmetic_reg_reg(tcb, 0x20, insn);
}

bool Encoder::encode_or(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return encode_arithmetic_reg_reg(tcb, 0x08, insn);
}

bool Encoder::encode_xor(TranslatedCodeBuffer& tcb, const Instruction *insn)
{
	return encode_arithmetic_reg_reg(tcb, 0x30, insn);
}

bool Encoder::encode_not(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& operand = insn->get_operand(0);

	switch (insn->match1()) {
	case InstructionMatch::REG:
		if (operand.reg.width == 8) {
			encode_opcode_modrm_oper(tcb, 0xf6, 2, operand);
		} else {
			encode_opcode_modrm_oper(tcb, 0xf7, 2, operand);
		}

		return true;

	default:
		return false;
	}
}

bool Encoder::encode_neg(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& operand = insn->get_operand(0);

	switch (insn->match1()) {
	case InstructionMatch::REG:
		if (operand.reg.width == 8) {
			encode_opcode_modrm_oper(tcb, 0xf6, 3, operand);
		} else {
			encode_opcode_modrm_oper(tcb, 0xf7, 3, operand);
		}

		return true;

	default:
		return false;
	}
}

bool Encoder::encode_bsr(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& src = insn->get_operand(0);
	const Operand& dest = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
		assert_true(src.reg.width == dest.reg.width, "src and dst regs must be the same width", insn);
		return encode_opcode_modrm(tcb, 0x1bd, dest, src);
	default:
		return false;
	}
}

bool Encoder::encode_bswap(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& operand = insn->get_operand(0);

	switch (insn->match1()) {
	case InstructionMatch::REG:
		if (operand.reg.width == 32 || operand.reg.width == 64) {
			if (operand.reg.reg.needs_extension() || operand.reg.width == 64) {
				dbt_u8 rex = 0x40;

				if (operand.reg.reg.needs_extension()) {
					rex |= 0x41;
				}

				if (operand.reg.width == 64) {
					rex |= 0x48;
				}

				tcb.emit8(rex);
			}

			tcb.emit8(0x0f);
			tcb.emit8(0xc8 + operand.reg.reg.raw_index());
			return true;
		} else {
			return false;
		}

	default:
		return false;
	}
}

