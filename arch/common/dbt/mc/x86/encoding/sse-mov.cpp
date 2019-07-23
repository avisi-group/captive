/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_movd(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_REG:
		assert_true(src.reg.width == 128, "movd: src reg must be 128 bits", insn);
		assert_true(dst.reg.width == 32, "movd: dst reg must be 32 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x17e, src, dst);

	case InstructionMatch::REG_FREG:
		assert_true(src.reg.width == 32, "movd: src reg must be 32 bits", insn);
		assert_true(dst.reg.width == 128, "movd: dst reg must be 128 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x16e, dst, src);

	case InstructionMatch::FREG_MEM:
		assert_true(src.reg.width == 128, "movd: src reg must be 128 bits", insn);
		assert_true(dst.mem.access_width == 32, "movd: dst mem operand must be 32 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x17e, src, dst);

	case InstructionMatch::MEM_FREG:
		assert_true(src.mem.access_width == 32, "movd: src mem operand must be 32 bits", insn);
		assert_true(dst.reg.width == 128, "movd: dst reg must be 128 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x16e, dst, src);
	default:
		return false;
	}
}

bool Encoder::encode_movq(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "movq: src and dst regs must be the same width", insn);
		assert_true(src.reg.width == 128, "movq: src reg must be 128 bits", insn);

		if (src.reg.width == 64) {
			return encode_sse_opcode_modrm(tcb, 0x16f, dst, src);
		} else {
			return encode_sse_opcode_modrm(tcb, 0x17e, dst, src);
		}

	case InstructionMatch::FREG_REG:
		assert_true(src.reg.width == 128, "movq: src reg must be 128 bits", insn);
		assert_true(dst.reg.width == 64, "movq: dst reg must be 64 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x17e, src, dst);

	case InstructionMatch::REG_FREG:
		assert_true(src.reg.width == 64, "movq: src reg must be 64 bits", insn);
		assert_true(dst.reg.width == 128, "movq: dst reg must be 128 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x16e, dst, src);

	case InstructionMatch::FREG_MEM:
		assert_true(src.reg.width == 128, "movq: src reg must be 128 bits", insn);
		assert_true(dst.mem.access_width == 64, "movq: dst mem operand must be 64 bits", insn);

		if (src.reg.width == 64) {
			tcb.emit8(0x48);
			return encode_sse_opcode_modrm(tcb, 0x17e, src, dst);
		} else {
			return encode_sse_opcode_modrm(tcb, 0x1d6, src, dst);
		}

	case InstructionMatch::MEM_FREG:
		assert_true(src.mem.access_width == 64, "movq: src mem operand must be 64 bits", insn);
		assert_true(dst.reg.width == 128, "movq: dst reg must be 128 bits", insn);

		if (dst.reg.width == 64) {
			tcb.emit8(0x48);
			return encode_sse_opcode_modrm(tcb, 0x16e, dst, src);
		} else {
			return encode_sse_opcode_modrm(tcb, 0x17e, dst, src);
		}

	default:
		return false;
	}
}

bool Encoder::encode_movdq(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "movdqa: src and dst regs must be the same width", insn);
		assert_true(src.reg.width == 128, "movdqa: src reg must be 128 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x16f, dst, src);

	case InstructionMatch::FREG_MEM:
		assert_true(src.reg.width == 128, "movdqa: src reg must be 128 bits", insn);
		assert_true(dst.mem.access_width == 128, "movdqa: dst mem operand must be 128 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x17f, src, dst);

	case InstructionMatch::MEM_FREG:
		assert_true(src.mem.access_width == 128, "movdqa: src mem operand must be 128 bits", insn);
		assert_true(dst.reg.width == 128, "movdqa: dst reg must be 128 bits", insn);

		return encode_sse_opcode_modrm(tcb, 0x16f, dst, src);

	default:
		return false;
	}
}

bool Encoder::encode_movss(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "movsf: src and dst regs must be the same width", insn);
		assert_true(src.reg.width == 128, "movsf: src reg must be 128 bits", insn);

		tcb.emit8(0xf3);
		return encode_sse_opcode_modrm(tcb, 0x110, dst, src, true);

	case InstructionMatch::FREG_MEM:
		assert_true(src.reg.width == 128, "movsf: src reg must be 128 bits", insn);
		assert_true(dst.mem.access_width == 32, "movsf: dst mem operand must be 32 bits", insn);

		tcb.emit8(0xf3);
		return encode_sse_opcode_modrm(tcb, 0x111, src, dst, true);

	case InstructionMatch::MEM_FREG:
		assert_true(src.mem.access_width == 32, "movsf: src mem operand must be 32 bits", insn);
		assert_true(dst.reg.width == 128, "movsf: dst reg must be 128 bits", insn);

		tcb.emit8(0xf3);
		return encode_sse_opcode_modrm(tcb, 0x110, dst, src, true);

	default:
		return false;
	}
}

bool Encoder::encode_movsd(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "movsf: src and dst regs must be the same width", insn);
		assert_true(src.reg.width == 128, "movsf: src reg must be 128 bits", insn);

		tcb.emit8(0xf2);
		return encode_sse_opcode_modrm(tcb, 0x110, dst, src, true);

	case InstructionMatch::FREG_MEM:
		assert_true(src.reg.width == 128, "movsf: src reg must be 128 bits", insn);
		assert_true(dst.mem.access_width == 64, "movsf: dst mem operand must be 64 bits", insn);

		tcb.emit8(0xf2);
		return encode_sse_opcode_modrm(tcb, 0x111, src, dst, true);

	case InstructionMatch::MEM_FREG:
		assert_true(src.mem.access_width == 64, "movsf: src mem operand must be 64 bits", insn);
		assert_true(dst.reg.width == 128, "movsf: dst reg must be 128 bits", insn);

		tcb.emit8(0xf2);
		return encode_sse_opcode_modrm(tcb, 0x110, dst, src, true);

	default:
		return false;
	}
}

bool Encoder::encode_pextr(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& idx = insn->get_operand(0);
	const auto& src = insn->get_operand(1);
	const auto& dst = insn->get_operand(2);

	assert_true(idx.is_const() && idx.constant.width == 8, "index must be constant-8", insn);
	assert_true(src.is_reg() && src.reg.reg.is_sse(), "source must be sse register", insn);
	assert_true(src.reg.width == 128, "source must be 128 bits", insn);
	assert_true(dst.is_reg() && dst.reg.reg.is_gpr(), "dest must be gp register", insn);

	switch (insn->kind()) {
	case InstructionKind::PEXTRB:
		assert_true(dst.reg.width == 32, "dest must be 32 bits", insn);
		if (!encode_sse_opcode_modrm(tcb, 0x314, src, dst)) {
			return false;
		}
		break;

	case InstructionKind::PEXTRW:
		assert_true(dst.reg.width == 32, "dest must be 32 bits", insn);
		if (!encode_sse_opcode_modrm(tcb, 0x315, src, dst)) {
			return false;
		}
		break;

	case InstructionKind::PEXTRD:
		assert_true(dst.reg.width == 32, "dest must be 32 bits", insn);
		if (!encode_sse_opcode_modrm(tcb, 0x316, src, dst)) {
			return false;
		}
		break;

	case InstructionKind::PEXTRQ:
		assert_true(dst.reg.width == 64, "dest must be 64 bits", insn);
		if (!encode_sse_opcode_modrm(tcb, 0x316, src, dst)) {
			return false;
		}
		break;

	default: return false;
	}

	tcb.emit8(idx.constant.value);
	return true;
}

bool Encoder::encode_pinsr(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& idx = insn->get_operand(0);
	const auto& src = insn->get_operand(1);
	const auto& dst = insn->get_operand(2);

	assert_true(idx.is_const() && idx.constant.width == 8, "index must be constant-8", insn);
	assert_true(src.is_reg() && src.reg.reg.is_gpr() || src.is_mem(), "src must be gp register", insn);
	assert_true(dst.is_reg() && dst.reg.reg.is_sse(), "dest must be sse register", insn);
	assert_true(dst.reg.width == 128, "dest must be 128 bits", insn);

	switch (insn->kind()) {
	case InstructionKind::PINSRB:
		assert_true((src.is_reg() && src.reg.width == 32) || (src.is_mem() && src.mem.access_width == 32), "src must be 32 bits", insn);
		if (!encode_sse_opcode_modrm(tcb, 0x320, dst, src)) {
			return false;
		}
		break;

	case InstructionKind::PINSRW:
		assert_true((src.is_reg() && src.reg.width == 32) || (src.is_mem() && src.mem.access_width == 32), "src must be 32 bits", insn);
		if (!encode_sse_opcode_modrm(tcb, 0x1c4, dst, src)) {
			return false;
		}
		break;

	case InstructionKind::PINSRD:
		assert_true((src.is_reg() && src.reg.width == 32) || (src.is_mem() && src.mem.access_width == 32), "src must be 32 bits", insn);
		if (!encode_sse_opcode_modrm(tcb, 0x322, dst, src)) {
			return false;
		}
		break;

	case InstructionKind::PINSRQ:
		assert_true((src.is_reg() && src.reg.width == 64) || (src.is_mem() && src.mem.access_width == 64), "src must be 64 bits", insn);
		if (!encode_sse_opcode_modrm(tcb, 0x322, dst, src)) {
			return false;
		}
		break;

	default: return false;
	}

	tcb.emit8(idx.constant.value);
	return true;
}

bool Encoder::encode_cvtsi(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	assert_true(dst.is_reg(), "dst must be register", insn);
	assert_true(dst.reg.width == 128, "dst must be 128 bits", insn);

	if (src.is_mem()) {
		assert_true(src.mem.access_width == 32, "cvtsi: src mem must be 32 bits", insn);
	} else if (src.is_reg()) {
		assert_true(src.reg.width == 32 || src.reg.width == 64, "cvtsi: src reg must be 32/64 bits", insn);
	}

	switch (insn->kind()) {
	case InstructionKind::CVTSI2SS:
		tcb.emit8(0xf3);
		return encode_sse_opcode_modrm(tcb, 0x12a, dst, src, true);
	case InstructionKind::CVTSI2SD:
		tcb.emit8(0xf2);
		return encode_sse_opcode_modrm(tcb, 0x12a, dst, src, true);
	default:
		return false;
	}
}

bool Encoder::encode_cvtts(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	assert_true(dst.is_reg(), "dst must be register", insn);
	assert_true(dst.reg.width == 32 || dst.reg.width == 64, "dst must be 32/64 bits", insn);

	if (src.is_mem()) {
		if (insn->kind() == InstructionKind::CVTTSS2SI) {
			assert_true(src.mem.access_width == 32, "cvttss2si: src mem must be 32 bits", insn);
		} else if (insn->kind() == InstructionKind::CVTTSD2SI) {
			assert_true(src.mem.access_width == 64, "cvttsd2si: src mem must be 64 bits", insn);
		}
	} else if (src.is_reg()) {
		assert_true(src.reg.width == 128, "cvtts: src reg must be 128 bits", insn);
	}

	switch (insn->kind()) {
	case InstructionKind::CVTTSS2SI:
		tcb.emit8(0xf3);
		return encode_sse_opcode_modrm(tcb, 0x12c, dst, src, true);
	case InstructionKind::CVTTSD2SI:
		tcb.emit8(0xf2);
		return encode_sse_opcode_modrm(tcb, 0x12c, dst, src, true);
	default:
		return false;
	}
}

bool Encoder::encode_cvts(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	assert_true(dst.is_reg(), "dst must be register", insn);
	assert_true(dst.reg.width == 128, "dst must be 128 bits", insn);

	if (src.is_mem()) {
		if (insn->kind() == InstructionKind::CVTSS2SD) {
			assert_true(src.mem.access_width == 32, "cvtss2sd: src mem must be 32 bits", insn);
		} else if (insn->kind() == InstructionKind::CVTSD2SS) {
			assert_true(src.mem.access_width == 64, "cvtsd2ss: src mem must be 64 bits", insn);
		}
	} else if (src.is_reg()) {
		assert_true(src.reg.width == 128, "cvts: src reg must be 128 bits", insn);
	}

	switch (insn->kind()) {
	case InstructionKind::CVTSS2SD:
		tcb.emit8(0xf3);
		return encode_sse_opcode_modrm(tcb, 0x15a, dst, src, true);
	case InstructionKind::CVTSD2SS:
		tcb.emit8(0xf2);
		return encode_sse_opcode_modrm(tcb, 0x15a, dst, src, true);
	default:
		return false;
	}
}

bool Encoder::encode_fp_rounds(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& rmode = insn->get_operand(0);
	const auto& src = insn->get_operand(1);
	const auto& dst = insn->get_operand(2);

	assert_true(dst.is_reg(), "dst must be register", insn);
	assert_true(dst.reg.width == 128, "dst must be 128 bits", insn);
	assert_true(rmode.is_const(), "rmode must be constant", insn);
	assert_true(rmode.constant.width == 8, "rmode must be 8-bits", insn);

	if (src.is_mem()) {
		if (insn->kind() == InstructionKind::ROUNDSS) {
			assert_true(src.mem.access_width == 32, "roundss: src mem must be 32 bits", insn);
		} else if (insn->kind() == InstructionKind::ROUNDSD) {
			assert_true(src.mem.access_width == 64, "roundsd: src mem must be 64 bits", insn);
		}
	} else if (src.is_reg()) {
		assert_true(src.reg.width == 128, "rounds: src reg must be 128 bits", insn);
	}

	tcb.emit8(0x66);
	switch (insn->kind()) {
	case InstructionKind::ROUNDSS:
		if (!encode_sse_opcode_modrm(tcb, 0x30a, dst, src, true)) {
			return false;
		}
		break;
	case InstructionKind::ROUNDSD:
		if (!encode_sse_opcode_modrm(tcb, 0x30b, dst, src, true)) {
			return false;
		}
		break;
	default:
		return false;
	}

	tcb.emit8(rmode.constant.value);
	return true;
}

bool Encoder::encode_punpck(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->kind()) {
	case InstructionKind::PUNPCKLBW:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x60);

		encode_mod_reg_rm(tcb, dst, src);

		return true;

	case InstructionKind::PUNPCKHBW:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x68);

		encode_mod_reg_rm(tcb, dst, src);

		return true;

	case InstructionKind::PUNPCKLWD:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x61);

		encode_mod_reg_rm(tcb, dst, src);

		return true;

	case InstructionKind::PUNPCKLDQ:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x62);

		encode_mod_reg_rm(tcb, dst, src);

		return true;

	case InstructionKind::PUNPCKLQDQ:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x6c);

		encode_mod_reg_rm(tcb, dst, src);

		return true;

	default:
		return false;
	}
}

bool Encoder::encode_pack(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->kind()) {
	case InstructionKind::PACKUSWB:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x67);

		encode_mod_reg_rm(tcb, dst, src);

		return true;
	default:
		return false;
	}
}

bool Encoder::encode_pshuf(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& order = insn->get_operand(0);
	const auto& src = insn->get_operand(1);
	const auto& dst = insn->get_operand(2);

	switch (insn->kind()) {
	case InstructionKind::PSHUFLW:
		tcb.emit8(0xf2);
		tcb.emit8(0x0f);
		tcb.emit8(0x70);

		encode_mod_reg_rm(tcb, dst, src);
		tcb.emit8(order.constant.value);

		return true;

	case InstructionKind::PSHUFHW:
		tcb.emit8(0xf3);
		tcb.emit8(0x0f);
		tcb.emit8(0x70);

		encode_mod_reg_rm(tcb, dst, src);
		tcb.emit8(order.constant.value);

		return true;

	case InstructionKind::PSHUFD:
		tcb.emit8(0x66);
		tcb.emit8(0x0f);
		tcb.emit8(0x70);

		encode_mod_reg_rm(tcb, dst, src);
		tcb.emit8(order.constant.value);

		return true;
	default:
		return false;
	}
}
