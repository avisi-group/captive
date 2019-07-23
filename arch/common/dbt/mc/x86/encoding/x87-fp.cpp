/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_x87_fld(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);

	switch (insn->match1()) {
	case InstructionMatch::MEM:
		switch (src.mem.access_width) {
		case 32: return encode_opcode_modrm_oper(tcb, 0xd9, 0, src);
		case 64: return encode_opcode_modrm_oper(tcb, 0xdd, 0, src);
		case 80: return encode_opcode_modrm_oper(tcb, 0xdb, 0, src);
		default: return false;
		}
		break;
	default:
		return false;
	}
}

bool Encoder::encode_x87_fstp(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& dst = insn->get_operand(0);

	switch (insn->match1()) {
	case InstructionMatch::MEM:
		switch (dst.mem.access_width) {
		case 32: return encode_opcode_modrm_oper(tcb, 0xd9, 3, dst);
		case 64: return encode_opcode_modrm_oper(tcb, 0xdd, 3, dst);
		case 80: return encode_opcode_modrm_oper(tcb, 0xdb, 7, dst);
		default: return false;
		}
		break;
	default:
		return false;
	}
}

bool Encoder::encode_x87_faddp(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	tcb.emit8(0xde);
	tcb.emit8(0xc1);

	return true;
}

bool Encoder::encode_x87_fmulp(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	tcb.emit8(0xde);
	tcb.emit8(0xc9);

	return true;
}
