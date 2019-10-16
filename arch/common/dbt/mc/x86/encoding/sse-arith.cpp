/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_padd(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "padd: src width must equal dst width", insn);
		assert_true(src.reg.width == 128, "padd: src width must be 128 bits", insn);

		switch (insn->kind()) {
		case InstructionKind::PADDB: return encode_sse_opcode_modrm(tcb, 0x1fc, dst, src);
		case InstructionKind::PADDW: return encode_sse_opcode_modrm(tcb, 0x1fd, dst, src);
		case InstructionKind::PADDD: return encode_sse_opcode_modrm(tcb, 0x1fe, dst, src);
		case InstructionKind::PADDQ: return encode_sse_opcode_modrm(tcb, 0x1d4, dst, src);
		default: return false;
		}

	case InstructionMatch::MEM_FREG:
		assert_true(src.mem.access_width == dst.reg.width, "padd: src mem access width must equal dst width", insn);
		assert_true(dst.reg.width == 128, "padd: dst width must be 128 bits", insn);

		switch (insn->kind()) {
		case InstructionKind::PADDB: return encode_sse_opcode_modrm(tcb, 0x1fc, dst, src);
		case InstructionKind::PADDW: return encode_sse_opcode_modrm(tcb, 0x1fd, dst, src);
		case InstructionKind::PADDD: return encode_sse_opcode_modrm(tcb, 0x1fe, dst, src);
		case InstructionKind::PADDQ: return encode_sse_opcode_modrm(tcb, 0x1d4, dst, src);
		default: return false;
		}
	default: return false;
	}
}

bool Encoder::encode_psub(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "psub: src width must equal dst width", insn);
		assert_true(src.reg.width == 128, "psub: src width must be 128 bits", insn);

		switch (insn->kind()) {
		case InstructionKind::PSUBB: return encode_sse_opcode_modrm(tcb, 0x1f8, dst, src);
		case InstructionKind::PSUBW: return encode_sse_opcode_modrm(tcb, 0x1f9, dst, src);
		case InstructionKind::PSUBD: return encode_sse_opcode_modrm(tcb, 0x1fa, dst, src);
		case InstructionKind::PSUBQ: return encode_sse_opcode_modrm(tcb, 0x1fb, dst, src);
		default: return false;
		}

	case InstructionMatch::MEM_FREG:
		assert_true(src.mem.access_width == dst.reg.width, "psub: src mem access width must equal dst width", insn);
		assert_true(dst.reg.width == 128, "psub: dst width must be 128 bits", insn);

		switch (insn->kind()) {
		case InstructionKind::PSUBB: return encode_sse_opcode_modrm(tcb, 0x1f8, dst, src);
		case InstructionKind::PSUBW: return encode_sse_opcode_modrm(tcb, 0x1f9, dst, src);
		case InstructionKind::PSUBD: return encode_sse_opcode_modrm(tcb, 0x1fa, dst, src);
		case InstructionKind::PSUBQ: return encode_sse_opcode_modrm(tcb, 0x1fb, dst, src);
		default: return false;
		}
	default: return false;
	}
}

bool Encoder::encode_p_bitwise(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
		assert_true(src.reg.width == dst.reg.width, "p{and,or,xor.andn}: src width must equal dst width", insn);
		assert_true(src.reg.width == 128, "p{and,or,xor,andn}: src width must be 128 bits", insn);

		switch (insn->kind()) {
		case InstructionKind::PAND: return encode_sse_opcode_modrm(tcb, 0x1db, dst, src);
		case InstructionKind::POR: return encode_sse_opcode_modrm(tcb, 0x1eb, dst, src);
		case InstructionKind::PXOR: return encode_sse_opcode_modrm(tcb, 0x1ef, dst, src);
		case InstructionKind::PANDN: return encode_sse_opcode_modrm(tcb, 0x1df, dst, src);
		default: return false;
		}

	case InstructionMatch::MEM_FREG:
		assert_true(src.mem.access_width == 128 || src.mem.access_width == 64, "p{and,or,xor,andn}: src mem access width must be 128 bits", insn);
		assert_true(dst.reg.width == 128, "p{and,or,xor,andn}: dst width must be 128 bits", insn);

		switch (insn->kind()) {
		case InstructionKind::PAND: return encode_sse_opcode_modrm(tcb, 0x1db, dst, src);
		case InstructionKind::POR: return encode_sse_opcode_modrm(tcb, 0x1eb, dst, src);
		case InstructionKind::PXOR: return encode_sse_opcode_modrm(tcb, 0x1ef, dst, src);
		case InstructionKind::PANDN: return encode_sse_opcode_modrm(tcb, 0x1df, dst, src);
		default: return false;
		}
	default: return false;
	}
}

bool Encoder::encode_fp_adds(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	if (insn->kind() == InstructionKind::ADDSS || insn->kind() == InstructionKind::ADDSD) {
		return encode_fp_arith(tcb, insn, 0x158, insn->kind() == InstructionKind::ADDSD, false);
	} else {
		return encode_fp_arith(tcb, insn, 0x158, insn->kind() == InstructionKind::ADDPD, true);
	}
}

bool Encoder::encode_fp_subs(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	if (insn->kind() == InstructionKind::SUBSS || insn->kind() == InstructionKind::SUBSD) {
		return encode_fp_arith(tcb, insn, 0x15c, insn->kind() == InstructionKind::SUBSD, false);
	} else {
		return encode_fp_arith(tcb, insn, 0x15c, insn->kind() == InstructionKind::SUBPD, true);
	}
}

bool Encoder::encode_fp_muls(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	if (insn->kind() == InstructionKind::MULSS || insn->kind() == InstructionKind::MULSD) {
		return encode_fp_arith(tcb, insn, 0x159, insn->kind() == InstructionKind::MULSD, false);
	} else {
		return encode_fp_arith(tcb, insn, 0x159, insn->kind() == InstructionKind::MULPD, true);
	}
}

bool Encoder::encode_fp_divs(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	if (insn->kind() == InstructionKind::DIVSS || insn->kind() == InstructionKind::DIVSD) {
		return encode_fp_arith(tcb, insn, 0x15e, insn->kind() == InstructionKind::DIVSD, false);
	} else {
		return encode_fp_arith(tcb, insn, 0x15e, insn->kind() == InstructionKind::DIVPD, true);
	}
}

bool Encoder::encode_fp_sqrts(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return encode_fp_arith(tcb, insn, 0x151, insn->kind() == InstructionKind::SQRTSD, false);
}

bool Encoder::encode_fp_arith(TranslatedCodeBuffer& tcb, const Instruction* insn, dbt_u16 opcode, bool dbl, bool packed)
{
	const auto& src = insn->get_operand(0);
	const auto& dst = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::FREG_FREG:
	case InstructionMatch::MEM_FREG:
		if (src.is_reg()) {
			assert_true(src.reg.width == 128, "fp arith: src reg must be 128-bits", insn);
		} else if (src.is_mem()) {
			if (packed) {
				assert_true(src.mem.access_width == 128, "fp arith: src mem must be 128-bits", insn);
			} else {
				assert_true(dbl ? (src.mem.access_width == 64) : (src.mem.access_width == 32), "fp arith: src mem must be 32/64-bits", insn);
			}
		}

		assert_true(dst.reg.width == 128, "dst reg must be 128-bits", insn);

		if (dbl) {
			if (packed) {
				tcb.emit8(0x66);
			} else {
				tcb.emit8(0xf2);
			}
		} else if (!packed) {
			tcb.emit8(0xf3);
		}

		return encode_sse_opcode_modrm(tcb, opcode, dst, src, true);
	default:
		return false;
	}
}
