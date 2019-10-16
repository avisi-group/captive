/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_fp_packed_xor(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->kind()) {
	case InstructionKind::XORPS:
		return encode_sse_opcode_modrm(tcb, 0x157, dst, src, true);
	default:
		return false;
	}

	return false;
}

bool Encoder::encode_pmul(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->kind()) {
	case InstructionKind::PMULLD:
		return encode_sse_opcode_modrm(tcb, 0x240, dst, src);
	case InstructionKind::PMULLW:
		return encode_sse_opcode_modrm(tcb, 0x1d5, dst, src);
	case InstructionKind::PMULUDQ:
		return encode_sse_opcode_modrm(tcb, 0x1f4, dst, src);
	default:
		return false;
	}
}
