/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_packed_shift(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& amt = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->kind()) {
	case InstructionKind::PSLLW:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x71);

		encode_mod_reg_rm_oper(tcb, 6, dst);
		tcb.emit8(amt.constant.value);

		return true;

	case InstructionKind::PSLLD:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x72);

		encode_mod_reg_rm_oper(tcb, 6, dst);
		tcb.emit8(amt.constant.value);

		return true;

	case InstructionKind::PSLLQ:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x73);

		encode_mod_reg_rm_oper(tcb, 6, dst);
		tcb.emit8(amt.constant.value);

		return true;

	case InstructionKind::PSRLW:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x71);

		encode_mod_reg_rm_oper(tcb, 2, dst);
		tcb.emit8(amt.constant.value);

		return true;

	case InstructionKind::PSRLD:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x72);

		encode_mod_reg_rm_oper(tcb, 2, dst);
		tcb.emit8(amt.constant.value);

		return true;

	case InstructionKind::PSRLQ:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x73);

		encode_mod_reg_rm_oper(tcb, 2, dst);
		tcb.emit8(amt.constant.value);

		return true;

	case InstructionKind::PSRAW:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x71);

		encode_mod_reg_rm_oper(tcb, 4, dst);
		tcb.emit8(amt.constant.value);

		return true;

	case InstructionKind::PSRAD:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x72);

		encode_mod_reg_rm_oper(tcb, 4, dst);
		tcb.emit8(amt.constant.value);

		return true;

	default:
		return false;
	}
}
