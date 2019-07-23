/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_lahf(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return false;
}

bool Encoder::encode_popcnt(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	tcb.emit8(0xf3);

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
	case InstructionMatch::MEM_REG:
		return encode_opcode_modrm(tcb, 0x1b8, insn->get_operand(0), insn->get_operand(1));
	default:
		return false;
	}
}

bool Encoder::encode_carry_flag(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	switch (insn->kind()) {
	case InstructionKind::STC:
		tcb.emit8(0xf9);
		return true;
	case InstructionKind::CLC:
		tcb.emit8(0xf8);
		return true;
	case InstructionKind::CMC:
		tcb.emit8(0xf5);
		return true;

	default:
		return false;
	}
}

bool Encoder::encode_dir_flag(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	switch (insn->kind()) {
	case InstructionKind::CLD:
		tcb.emit8(0xfc);
		return true;
	default:
		return false;
	}
}

bool Encoder::encode_stack(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& operand = insn->get_operand(0);

	switch (insn->kind()) {
	case InstructionKind::PUSH:
		if (operand.kind == OperandKind::REGISTER) {
			if (operand.reg.width == 16 || operand.reg.width == 64) {
				if (operand.reg.width == 16) {
					tcb.emit8(0x66);
				}

				if (operand.reg.reg.needs_extension()) {
					tcb.emit8(0x41);
				}

				tcb.emit8(0x50 + operand.reg.reg.raw_index());
			} else {
				assert_true(false, "pop: invalid size for register operand", insn);
				return false;
			}
		}
		return true;

	case InstructionKind::POP:
		if (operand.kind == OperandKind::REGISTER) {
			if (operand.reg.width == 16 || operand.reg.width == 64) {
				if (operand.reg.width == 16) {
					tcb.emit8(0x66);
				}

				if (operand.reg.reg.needs_extension()) {
					tcb.emit8(0x41);
				}

				tcb.emit8(0x58 + operand.reg.reg.raw_index());
			} else {
				assert_true(false, "pop: invalid size for register operand", insn);
				return false;
			}
		}
		return true;

	default:
		assert_true(false, "unsupported stack operation", insn);
		return false;
	}

	return false;
}

bool Encoder::encode_stack_f(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return false;
}
