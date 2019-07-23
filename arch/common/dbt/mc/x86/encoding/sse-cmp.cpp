/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_pcmpeq(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "pcmpeq: src width must equal dst width", insn);
		/* Fall through */
	case InstructionMatch::MEM_FREG:
		assert_true(dst.reg.width == 128, "pcmpeq: dst width must be 128 bits", insn);

		switch (insn->kind()) {
		case InstructionKind::PCMPEQB: return encode_sse_opcode_modrm(tcb, 0x174, dst, src);
		case InstructionKind::PCMPEQW: return encode_sse_opcode_modrm(tcb, 0x175, dst, src);
		case InstructionKind::PCMPEQD: return encode_sse_opcode_modrm(tcb, 0x176, dst, src);
		case InstructionKind::PCMPEQQ: return encode_sse_opcode_modrm(tcb, 0x229, dst, src);
		default: return false;
		}
	default: return false;
	}
}

bool Encoder::encode_pcmpgt(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "pcmpgt: src width must equal dst width", insn);
		/* Fall through */
	case InstructionMatch::MEM_FREG:
		assert_true(dst.reg.width == 128, "pcmpgt: dst width must be 128 bits", insn);

		switch (insn->kind()) {
		case InstructionKind::PCMPGTB: return encode_sse_opcode_modrm(tcb, 0x164, dst, src);
		case InstructionKind::PCMPGTW: return encode_sse_opcode_modrm(tcb, 0x165, dst, src);
		case InstructionKind::PCMPGTD: return encode_sse_opcode_modrm(tcb, 0x166, dst, src);
		case InstructionKind::PCMPGTQ: return encode_sse_opcode_modrm(tcb, 0x237, dst, src);
		default: return false;
		}
	default: return false;
	}
}

bool Encoder::encode_ucomis(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& a = insn->get_operand(0);
	const auto& b = insn->get_operand(1);

	dbt_u16 opcode;
	switch (insn->kind()) {
	case InstructionKind::UCOMISD:
	case InstructionKind::UCOMISS:
		opcode = 0x12e;
		break;
	case InstructionKind::COMISD:
	case InstructionKind::COMISS:
		opcode = 0x12f;
		break;
	default:
		return false;
	}

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(a.reg.width == b.reg.width, "[u]comis{s,d}: a width must equal b width", insn);

	case InstructionMatch::MEM_FREG:
		assert_true(b.reg.width == 128, "[u]comis{s,d}: a width must equal b width", insn);

		if (insn->kind() == InstructionKind::UCOMISD || insn->kind() == InstructionKind::COMISD) {
			tcb.emit8(0x66);
		}

		return encode_sse_opcode_modrm(tcb, opcode, b, a, true);

	default: return false;
	}
}
