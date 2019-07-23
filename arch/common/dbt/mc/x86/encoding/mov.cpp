/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>
#include <dbt/mc/x86/formatter.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_mov(TranslatedCodeBuffer& tcb, const Instruction *insn)
{
	const Operand& src = insn->get_operand(0);
	const Operand& dest = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
		assert_true(src.reg.width == dest.reg.width, "register sizes must be equal in mov reg -> reg", insn);

		if (src.reg.width == 8) {
			return encode_opcode_modrm(tcb, 0x88, src, dest);
		} else {
			return encode_opcode_modrm(tcb, 0x89, src, dest);
		}

	case InstructionMatch::SREG_REG:
		return encode_opcode_modrm(tcb, 0x8c, src, dest);

	case InstructionMatch::REG_MEM:
		if (src.reg.width == 8) {
			return encode_opcode_modrm(tcb, 0x88, src, dest);
		} else {
			return encode_opcode_modrm(tcb, 0x89, src, dest);
		}

	case InstructionMatch::MEM_REG:
		if (dest.reg.width == 8) {
			return encode_opcode_modrm(tcb, 0x8a, dest, src);
		} else {
			return encode_opcode_modrm(tcb, 0x8b, dest, src);
		}

	case InstructionMatch::CONST_REG:
		if (dest.reg.width == 8) {
			dbt_u8 rex = 0;

			if (requires_rex(dest)) {
				rex |= 0x40;
			} else if (dest.reg.reg.needs_extension()) {
				rex |= 0x41;
			}

			if (rex) tcb.emit8(rex);

			tcb.emit8(0xb0 + dest.reg.reg.raw_index());
			tcb.emit8(src.constant.value);
		} else {
			dbt_u8 rex = 0;

			dbt_u8 size = dest.reg.width;
			if (size == 64 && src.constant.value < 0x80000000) size = 32;

			if (dest.reg.reg.needs_extension()) {
				rex |= 0x41;
			}

			if (size == 64) {
				rex |= 0x48;
			}

			if (size == 16) {
				tcb.emit8(0x66);
			}

			if (rex) tcb.emit8(rex);

			tcb.emit8(0xb8 + dest.reg.reg.raw_index());

			switch (size) {
			case 64: tcb.emit64(src.constant.value);
				break;
			case 32: tcb.emit32(src.constant.value);
				break;
			case 16: tcb.emit16(src.constant.value);
				break;
			}
		}

		return true;

	case InstructionMatch::CONST_MEM:
		switch (dest.mem.access_width) {
		case 8:
			encode_opcode_modrm(tcb, 0xc6, Operand::make_register(X86Registers::AL), dest);
			tcb.emit8(src.constant.value);
			return true;
		case 16:
			encode_opcode_modrm(tcb, 0xc7, Operand::make_register(X86Registers::AX), dest);
			tcb.emit16(src.constant.value);
			return true;
		case 32:
			encode_opcode_modrm(tcb, 0xc7, Operand::make_register(X86Registers::EAX), dest);
			tcb.emit32(src.constant.value);
			return true;
		case 64:
			// RUH ROH
			encode_opcode_modrm(tcb, 0xc7, Operand::make_register(X86Registers::RAX), dest);
			tcb.emit32(src.constant.value);
			return true;
		default:
			assert_true(false, "unsupported constant size for mov->mem", insn);
			return false;
		}

	case InstructionMatch::CREG_REG:
		assert_true(src.reg.width == 64 && dest.reg.width == 64, "move from control register must have 64-bit operands", insn);
		return encode_opcode_modrm(tcb, 0x120, src, dest, true);

	case InstructionMatch::REG_CREG:
		assert_true(src.reg.width == 64 && dest.reg.width == 64, "move to control register must have 64-bit operands", insn);
		return encode_opcode_modrm(tcb, 0x122, dest, src, true);

	default:
		Formatter fmt;
		_support.debug_printf("XX: %s\n", fmt.format_instruction(insn));
		assert_true(false, "unsupported encoding for mov", insn);
		return false;
	}
}

bool Encoder::encode_cmov(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& src = insn->get_operand(0);
	const Operand& dest = insn->get_operand(1);

	unsigned int cond;
	switch (insn->kind()) {
	case InstructionKind::CMOVO: cond = 0;
		break;
	case InstructionKind::CMOVNO: cond = 1;
		break;
	case InstructionKind::CMOVB: case InstructionKind::CMOVNAE: case InstructionKind::CMOVC: cond = 2;
		break;
	case InstructionKind::CMOVNB: case InstructionKind::CMOVAE: case InstructionKind::CMOVNC: cond = 3;
		break;
	case InstructionKind::CMOVZ: case InstructionKind::CMOVE: cond = 4;
		break;
	case InstructionKind::CMOVNZ: case InstructionKind::CMOVNE: cond = 5;
		break;
	case InstructionKind::CMOVBE: case InstructionKind::CMOVNA: cond = 6;
		break;
	case InstructionKind::CMOVNBE: case InstructionKind::CMOVA: cond = 7;
		break;
	case InstructionKind::CMOVS: cond = 8;
		break;
	case InstructionKind::CMOVNS: cond = 9;
		break;
	case InstructionKind::CMOVP: case InstructionKind::CMOVPE: cond = 10;
		break;
	case InstructionKind::CMOVNP: case InstructionKind::CMOVPO: cond = 11;
		break;
	case InstructionKind::CMOVL: case InstructionKind::CMOVNGE: cond = 12;
		break;
	case InstructionKind::CMOVNL: case InstructionKind::CMOVGE: cond = 13;
		break;
	case InstructionKind::CMOVLE: case InstructionKind::CMOVNG: cond = 14;
		break;
	case InstructionKind::CMOVNLE: case InstructionKind::CMOVG: cond = 15;
		break;
	default: assert_true(false, "cjmp: invalid conditional move type", insn);
		return false;
	}

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
	case InstructionMatch::MEM_REG:
		return encode_opcode_modrm(tcb, 0x140 + cond, dest, src);

	default:
		return false;
	}
}

bool Encoder::encode_mov_x(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& src = insn->get_operand(0);
	const Operand& dest = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
		if (dest.reg.width > src.reg.width) {
			if (src.reg.width == 8) {
				if (insn->kind() == InstructionKind::MOVZX) {
					return encode_opcode_modrm(tcb, 0x1b6, dest, src);
				} else if (insn->kind() == InstructionKind::MOVSX) {
					return encode_opcode_modrm(tcb, 0x1be, dest, src);
				} else {
					assert_true(false, "movx reg-reg must be ZX or SX", insn);
					return false;
				}
			} else if (src.reg.width == 16) {
				if (insn->kind() == InstructionKind::MOVZX) {
					return encode_opcode_modrm(tcb, 0x1b7, dest, src);
				} else if (insn->kind() == InstructionKind::MOVSX) {
					return encode_opcode_modrm(tcb, 0x1bf, dest, src, false, true);
				} else {
					assert_true(false, "movx reg-reg must be ZX or SX", insn);
					return false;
				}
			} else if (src.reg.width == 32) {
				if (insn->kind() == InstructionKind::MOVSX) {
					return encode_opcode_modrm(tcb, 0x63, dest, src);
				} else {
					return encode_opcode_modrm(tcb, 0x8b, Operand::make_register(dest.reg.reg, 32), src);
				}
			} else {
				return false;
			}
		} else {
			assert_true(false, "mov-ext: dest must be strictly bigger than src", insn);
			return false;
		}

	case InstructionMatch::MEM_REG:
		if (dest.reg.width > src.mem.access_width) {
			if (src.mem.access_width == 8) {
				if (insn->kind() == InstructionKind::MOVZX) {
					return encode_opcode_modrm(tcb, 0x1b6, dest, src);
				} else if (insn->kind() == InstructionKind::MOVSX) {
					return encode_opcode_modrm(tcb, 0x1be, dest, src);
				} else {
					assert_true(false, "movx mem-reg must be ZX or SX", insn);
					return false;
				}
			} else if (src.mem.access_width == 16) {
				if (insn->kind() == InstructionKind::MOVZX) {
					return encode_opcode_modrm(tcb, 0x1b7, dest, src);
				} else if (insn->kind() == InstructionKind::MOVSX) {
					return encode_opcode_modrm(tcb, 0x1bf, dest, src);
				} else {
					assert_true(false, "movx mem-reg must be ZX or SX", insn);
					return false;
				}
			} else if (src.mem.access_width == 32) {
				if (insn->kind() == InstructionKind::MOVZX) {
					return encode_opcode_modrm(tcb, 0x8b, Operand::make_register(dest.reg.reg, 32), src);
				} else {
					return encode_opcode_modrm(tcb, 0x63, dest, src);
				}
			} else {
				return false;
			}
		} else {
			assert_true(false, "mov-ext: dest must be strictly bigger than src", insn);
			return false;
		}

	default:
		assert_true(false, "unsupported encoding for mov-ext", insn);
		return false;
	}
}

bool Encoder::encode_lea(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& src = insn->get_operand(0);
	const Operand& dest = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::MEM_REG:
		if (dest.reg.width == 8) {
			return false;
		} else {
			return encode_opcode_modrm(tcb, 0x8d, dest, src);
		}

	default:
		assert_true(false, "unsupported encoding for lea", insn);
		return false;
	}
}

bool Encoder::encode_xchg(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return false;
}

bool Encoder::encode_cmpxchg(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& src = insn->get_operand(0);
	const Operand& dest = insn->get_operand(1);

	switch (insn->match2()) {
	case InstructionMatch::REG_REG:
	case InstructionMatch::REG_MEM:
		if (src.reg.width == 8) {
			return encode_opcode_modrm(tcb, 0x1b0, src, dest);
		} else {
			return encode_opcode_modrm(tcb, 0x1b1, src, dest);
		}
	default:
		return false;
	}
}

bool Encoder::encode_cvt(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	switch (insn->kind()) {
	case InstructionKind::CBTW:
		tcb.emit8(0x66);
		tcb.emit8(0x98);
		return true;

	case InstructionKind::CWTL:
		tcb.emit8(0x98);
		return true;

	case InstructionKind::CLTQ:
		tcb.emit8(0x48);
		tcb.emit8(0x98);
		return true;

	case InstructionKind::CWTD:
		tcb.emit8(0x66);
		tcb.emit8(0x99);
		return true;

	case InstructionKind::CLTD:
		tcb.emit8(0x99);
		return true;

	case InstructionKind::CQTO:
		tcb.emit8(0x48);
		tcb.emit8(0x99);
		return true;

	default:
		return false;
	}
}

bool Encoder::encode_rep_stos(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	switch (insn->kind()) {
	case InstructionKind::REP_STOSQ:
		tcb.emit8(0xf3);
		tcb.emit8(0x48);
		tcb.emit8(0xab);
		return true;
	default:
		return false;
	}
}
