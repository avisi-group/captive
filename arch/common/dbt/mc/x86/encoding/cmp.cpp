/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_cmp(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& o1 = insn->get_operand(0);
	const auto& o2 = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
		assert_true(o1.reg.width == o2.reg.width, "register sizes must be equal in cmp", insn);

		if (o1.reg.width == 8) {
			return encode_opcode_modrm(tcb, 0x38, o2, o1);
		} else {
			return encode_opcode_modrm(tcb, 0x39, o2, o1);
		}

	case InstructionMatch::MEM_REG:
		if (o2.reg.width == 8) {
			return encode_opcode_modrm(tcb, 0x3a, o2, o1);
		} else {
			return encode_opcode_modrm(tcb, 0x3b, o2, o1);
		}

	case InstructionMatch::CONST_REG:
		return encode_arithmetic_immediate(tcb, 7, insn);

	case InstructionMatch::CONST_MEM:
		switch (o1.constant.width) {
		case 8: return encode_arithmetic_immediate(tcb, 7, insn);
		case 16: return false;
		case 32: return encode_arithmetic_immediate(tcb, 7, insn);
		case 64: return false;
		}
		return false;

	case InstructionMatch::REG_MEM:
		if (o1.reg.width == 8) {
			return encode_opcode_modrm(tcb, 0x38, o1, o2);
		} else {
			return encode_opcode_modrm(tcb, 0x39, o1, o2);
		}

	default:
		return false;
	}
}

bool Encoder::encode_test(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& o1 = insn->get_operand(0);
	const auto& o2 = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
		assert_true(o1.reg.width == o2.reg.width, "register sizes must be equal in test", insn);

		if (o1.reg.width == 8) {
			encode_opcode_modrm(tcb, 0x84, o1, o2);
		} else {
			encode_opcode_modrm(tcb, 0x85, o1, o2);
		}

		return true;

	default:
		return false;
	}
}

bool Encoder::encode_cset(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& dst = insn->get_operand(0);

	unsigned int cc_type;
	switch (insn->kind()) {
	case InstructionKind::SETO: cc_type = 0;
		break;
	case InstructionKind::SETNO: cc_type = 1;
		break;
	case InstructionKind::SETB: case InstructionKind::SETNAE: case InstructionKind::SETC: cc_type = 2;
		break;
	case InstructionKind::SETNB: case InstructionKind::SETAE: case InstructionKind::SETNC: cc_type = 3;
		break;
	case InstructionKind::SETZ: case InstructionKind::SETE: cc_type = 4;
		break;
	case InstructionKind::SETNZ: case InstructionKind::SETNE: cc_type = 5;
		break;
	case InstructionKind::SETBE: case InstructionKind::SETNA: cc_type = 6;
		break;
	case InstructionKind::SETNBE: case InstructionKind::SETA: cc_type = 7;
		break;
	case InstructionKind::SETS: cc_type = 8;
		break;
	case InstructionKind::SETNS: cc_type = 9;
		break;
	case InstructionKind::SETP: case InstructionKind::SETPE: cc_type = 10;
		break;
	case InstructionKind::SETNP: case InstructionKind::SETPO: cc_type = 11;
		break;
	case InstructionKind::SETL: case InstructionKind::SETNGE: cc_type = 12;
		break;
	case InstructionKind::SETNL: case InstructionKind::SETGE: cc_type = 13;
		break;
	case InstructionKind::SETLE: case InstructionKind::SETNG: cc_type = 14;
		break;
	case InstructionKind::SETNLE: case InstructionKind::SETG: cc_type = 15;
		break;
	default: assert_true(false, "cjmp: invalid conditional set type", insn);
		return false;
	}

	switch (insn->match1()) {
	case InstructionMatch::REG:
		assert_true(dst.reg.width == 8, "setcc must use 8-bit register", insn);

		if (requires_rex(dst)) {
			tcb.emit8(0x40);
		} else if (dst.reg.reg.needs_extension()) {
			tcb.emit8(0x41);
		}

		tcb.emit8(0x0f);
		tcb.emit8(0x90 | (cc_type & 0xf));

		return encode_mod_reg_rm_oper(tcb, 0, dst);

	case InstructionMatch::MEM:
		tcb.emit8(0x0f);
		tcb.emit8(0x90 | (cc_type & 0xf));
		return encode_mod_reg_rm_oper(tcb, 0, dst);

	default:
		return false;
	}
}
