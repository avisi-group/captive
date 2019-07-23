/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_clmul(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);
	const auto& gf = insn->get_operand(2);

	if (insn->match3() != InstructionMatch::FREG_FREG_IMM) return false;

	switch (insn->kind()) {
	case InstructionKind::PCLMULQDQ:
		if (!encode_sse_opcode_modrm(tcb, 0x344, dst, src, false)) {
			return false;
		}

		tcb.emit8(gf.constant.value);
		return true;

	default:
		return false;
	}

	return false;
}
