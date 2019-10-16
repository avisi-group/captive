/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/formatter.h>

using namespace captive::arch::dbt::mc::x86;

void *Encoder::encode(Instruction* head, dbt_size_t& size)
{
	TranslatedCodeBuffer tcb(_support);

	Instruction *current = head;
	do {
		tcb.begin_instruction();
		if (!encode_instruction(tcb, current)) {
			Formatter fmt;
			_support.debug_printf("encoding fail @ %p : %s\n", current, fmt.format_instruction(current));
			return nullptr;
		}

		current = current->next();
	} while (current != head);

	if (tcb.size() == 0) return nullptr;

	perform_relocations(tcb);

	void *code = _support.alloc(tcb.size(), AllocClass::TRANSLATED_CODE);
	if (!code) {
		return nullptr;
	}

	size = tcb.size();
	_support.memcpy(code, tcb.buffer(), tcb.size());

	return(void *) code;
}

bool Encoder::encode_instruction(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	_current = insn;

	switch (insn->kind()) {
	case InstructionKind::LABEL: register_label(tcb.offset(), insn);
		return true;
	case InstructionKind::LITERAL:
	{
		auto op = insn->get_operand(0);

		assert_true(op.is_literal(), "literal instruction must have literal operand", insn);
		switch (op.literal.width) {
		case 8: tcb.emit8(op.literal.value);
			break;
		case 16: tcb.emit16(op.literal.value);
			break;
		case 32: tcb.emit32(op.literal.value);
			break;
		case 64: tcb.emit64(op.literal.value);
			break;
		}

		return true;
	}
	case InstructionKind::DEAD: return true;

	case InstructionKind::NOP: return encode_nop(tcb, insn);

	case InstructionKind::MOV: return encode_mov(tcb, insn);
	case InstructionKind::MOVZX:
	case InstructionKind::MOVSX: return encode_mov_x(tcb, insn);
	case InstructionKind::LEA: return encode_lea(tcb, insn);
	case InstructionKind::XCHG: return encode_xchg(tcb, insn);
	case InstructionKind::CMOV: return encode_cmov(tcb, insn);
	case InstructionKind::POPCNT: return encode_popcnt(tcb, insn);
	case InstructionKind::REP_STOSQ: return encode_rep_stos(tcb, insn);
	case InstructionKind::CMPXCHG: return encode_cmpxchg(tcb, insn);

	case InstructionKind::CBTW: return encode_cvt(tcb, insn);
	case InstructionKind::CWTL: return encode_cvt(tcb, insn);
	case InstructionKind::CLTQ: return encode_cvt(tcb, insn);
	case InstructionKind::CWTD: return encode_cvt(tcb, insn);
	case InstructionKind::CLTD: return encode_cvt(tcb, insn);
	case InstructionKind::CQTO: return encode_cvt(tcb, insn);

	case InstructionKind::ADD: return encode_add(tcb, insn);
	case InstructionKind::ADC: return encode_adc(tcb, insn);
	case InstructionKind::SUB: return encode_sub(tcb, insn);
	case InstructionKind::SBB: return encode_sbb(tcb, insn);
	case InstructionKind::IMUL: return encode_mul_div(tcb, insn);
	case InstructionKind::MUL: return encode_mul_div(tcb, insn);
	case InstructionKind::IDIV: return encode_mul_div(tcb, insn);
	case InstructionKind::DIV: return encode_mul_div(tcb, insn);
	case InstructionKind::NEG: return encode_neg(tcb, insn);

	case InstructionKind::INC: return encode_inc_dec(tcb, insn);
	case InstructionKind::DEC: return encode_inc_dec(tcb, insn);

	case InstructionKind::SHR: return encode_shift(tcb, insn);
	case InstructionKind::SAR: return encode_shift(tcb, insn);
	case InstructionKind::SHL: return encode_shift(tcb, insn);
	case InstructionKind::ROR: return encode_shift(tcb, insn);
	case InstructionKind::ROL: return encode_shift(tcb, insn);

	case InstructionKind::AND: return encode_and(tcb, insn);
	case InstructionKind::OR: return encode_or(tcb, insn);
	case InstructionKind::XOR: return encode_xor(tcb, insn);
	case InstructionKind::NOT: return encode_not(tcb, insn);

	case InstructionKind::BSR: return encode_bsr(tcb, insn);
	case InstructionKind::BSWAP: return encode_bswap(tcb, insn);
	case InstructionKind::TEST: return encode_test(tcb, insn);
	case InstructionKind::CMP: return encode_cmp(tcb, insn);

	case InstructionKind::PUSH: return encode_stack(tcb, insn);
	case InstructionKind::PUSHF: return encode_stack_f(tcb, insn);
	case InstructionKind::POP: return encode_stack(tcb, insn);
	case InstructionKind::POPF: return encode_stack_f(tcb, insn);

	case InstructionKind::LAHF: return encode_lahf(tcb, insn);
	case InstructionKind::CLC: return encode_carry_flag(tcb, insn);
	case InstructionKind::STC: return encode_carry_flag(tcb, insn);
	case InstructionKind::CMC: return encode_carry_flag(tcb, insn);
	case InstructionKind::CLD: return encode_dir_flag(tcb, insn);

	case InstructionKind::JO:
	case InstructionKind::JNO:
	case InstructionKind::JB: case InstructionKind::JNAE: case InstructionKind::JC:
	case InstructionKind::JNB: case InstructionKind::JAE: case InstructionKind::JNC:
	case InstructionKind::JZ: case InstructionKind::JE:
	case InstructionKind::JNZ: case InstructionKind::JNE:
	case InstructionKind::JBE: case InstructionKind::JNA:
	case InstructionKind::JNBE: case InstructionKind::JA:
	case InstructionKind::JS:
	case InstructionKind::JNS:
	case InstructionKind::JP: case InstructionKind::JPE:
	case InstructionKind::JNP: case InstructionKind::JPO:
	case InstructionKind::JL: case InstructionKind::JNGE:
	case InstructionKind::JNL: case InstructionKind::JGE:
	case InstructionKind::JLE: case InstructionKind::JNG:
	case InstructionKind::JNLE: case InstructionKind::JG:
		return encode_cjmp(tcb, insn);

	case InstructionKind::SETO:
	case InstructionKind::SETNO:
	case InstructionKind::SETB: case InstructionKind::SETNAE: case InstructionKind::SETC:
	case InstructionKind::SETNB: case InstructionKind::SETAE: case InstructionKind::SETNC:
	case InstructionKind::SETZ: case InstructionKind::SETE:
	case InstructionKind::SETNZ: case InstructionKind::SETNE:
	case InstructionKind::SETBE: case InstructionKind::SETNA:
	case InstructionKind::SETNBE: case InstructionKind::SETA:
	case InstructionKind::SETS:
	case InstructionKind::SETNS:
	case InstructionKind::SETP: case InstructionKind::SETPE:
	case InstructionKind::SETNP: case InstructionKind::SETPO:
	case InstructionKind::SETL: case InstructionKind::SETNGE:
	case InstructionKind::SETNL: case InstructionKind::SETGE:
	case InstructionKind::SETLE: case InstructionKind::SETNG:
	case InstructionKind::SETNLE: case InstructionKind::SETG:
		return encode_cset(tcb, insn);

	case InstructionKind::CMOVO:
	case InstructionKind::CMOVNO:
	case InstructionKind::CMOVB: case InstructionKind::CMOVNAE: case InstructionKind::CMOVC:
	case InstructionKind::CMOVNB: case InstructionKind::CMOVAE: case InstructionKind::CMOVNC:
	case InstructionKind::CMOVZ: case InstructionKind::CMOVE:
	case InstructionKind::CMOVNZ: case InstructionKind::CMOVNE:
	case InstructionKind::CMOVBE: case InstructionKind::CMOVNA:
	case InstructionKind::CMOVNBE: case InstructionKind::CMOVA:
	case InstructionKind::CMOVS:
	case InstructionKind::CMOVNS:
	case InstructionKind::CMOVP: case InstructionKind::CMOVPE:
	case InstructionKind::CMOVNP: case InstructionKind::CMOVPO:
	case InstructionKind::CMOVL: case InstructionKind::CMOVNGE:
	case InstructionKind::CMOVNL: case InstructionKind::CMOVGE:
	case InstructionKind::CMOVLE: case InstructionKind::CMOVNG:
	case InstructionKind::CMOVNLE: case InstructionKind::CMOVG:
		return encode_cmov(tcb, insn);

	case InstructionKind::JMP: return encode_jmp(tcb, insn);
	case InstructionKind::LCALL: return encode_lcall(tcb, insn);
	case InstructionKind::RET: return encode_ret(tcb, insn);

	case InstructionKind::CALL:
	case InstructionKind::QCALL:
	case InstructionKind::CALL0:
	case InstructionKind::CALL1:
	case InstructionKind::CALL2:
	case InstructionKind::CALL3:
	case InstructionKind::CALL4:
	case InstructionKind::CALL5:
	case InstructionKind::CALL6:
		return encode_call(tcb, insn);

	case InstructionKind::SYSENTER: return encode_sysenter(tcb, insn);
	case InstructionKind::SYSCALL: return encode_syscall(tcb, insn);
	case InstructionKind::SYSRET: return encode_sysret(tcb, insn);
	case InstructionKind::INT: return encode_int(tcb, insn);

	case InstructionKind::OUT: return encode_out(tcb, insn);

	case InstructionKind::MOVD: return encode_movd(tcb, insn);
	case InstructionKind::MOVQ: return encode_movq(tcb, insn);
	case InstructionKind::MOVDQA: return encode_movdq(tcb, insn);
	case InstructionKind::MOVSS: return encode_movss(tcb, insn);
	case InstructionKind::MOVSD: return encode_movsd(tcb, insn);
	case InstructionKind::PADDB: return encode_padd(tcb, insn);
	case InstructionKind::PADDW: return encode_padd(tcb, insn);
	case InstructionKind::PADDD: return encode_padd(tcb, insn);
	case InstructionKind::PADDQ: return encode_padd(tcb, insn);
	case InstructionKind::PSUBB: return encode_psub(tcb, insn);
	case InstructionKind::PSUBW: return encode_psub(tcb, insn);
	case InstructionKind::PSUBD: return encode_psub(tcb, insn);
	case InstructionKind::PSUBQ: return encode_psub(tcb, insn);
	case InstructionKind::PCMPEQB: return encode_pcmpeq(tcb, insn);
	case InstructionKind::PCMPEQW: return encode_pcmpeq(tcb, insn);
	case InstructionKind::PCMPEQD: return encode_pcmpeq(tcb, insn);
	case InstructionKind::PCMPEQQ: return encode_pcmpeq(tcb, insn);
	case InstructionKind::PCMPGTB: return encode_pcmpgt(tcb, insn);
	case InstructionKind::PCMPGTW: return encode_pcmpgt(tcb, insn);
	case InstructionKind::PCMPGTD: return encode_pcmpgt(tcb, insn);
	case InstructionKind::PCMPGTQ: return encode_pcmpgt(tcb, insn);
	case InstructionKind::PAND: return encode_p_bitwise(tcb, insn);
	case InstructionKind::PANDN: return encode_p_bitwise(tcb, insn);
	case InstructionKind::POR: return encode_p_bitwise(tcb, insn);
	case InstructionKind::PXOR: return encode_p_bitwise(tcb, insn);
	case InstructionKind::PMULLD: return encode_pmul(tcb, insn);
	case InstructionKind::PMULLW: return encode_pmul(tcb, insn);
	case InstructionKind::PMULUDQ: return encode_pmul(tcb, insn);
	case InstructionKind::PEXTRB: return encode_pextr(tcb, insn);
	case InstructionKind::PEXTRW: return encode_pextr(tcb, insn);
	case InstructionKind::PEXTRD: return encode_pextr(tcb, insn);
	case InstructionKind::PEXTRQ: return encode_pextr(tcb, insn);
	case InstructionKind::PINSRB: return encode_pinsr(tcb, insn);
	case InstructionKind::PINSRW: return encode_pinsr(tcb, insn);
	case InstructionKind::PINSRD: return encode_pinsr(tcb, insn);
	case InstructionKind::PINSRQ: return encode_pinsr(tcb, insn);
	case InstructionKind::PUNPCKHBW: return encode_punpck(tcb, insn);
	case InstructionKind::PUNPCKLBW: return encode_punpck(tcb, insn);
	case InstructionKind::PUNPCKLWD: return encode_punpck(tcb, insn);
	case InstructionKind::PUNPCKLDQ: return encode_punpck(tcb, insn);
	case InstructionKind::PUNPCKLQDQ: return encode_punpck(tcb, insn);
	case InstructionKind::PACKUSWB: return encode_pack(tcb, insn);
	case InstructionKind::PSHUFLW: return encode_pshuf(tcb, insn);
	case InstructionKind::PSHUFHW: return encode_pshuf(tcb, insn);
	case InstructionKind::PSHUFD: return encode_pshuf(tcb, insn);

	case InstructionKind::CVTSI2SS: return encode_cvtsi(tcb, insn);
	case InstructionKind::CVTSI2SD: return encode_cvtsi(tcb, insn);
	case InstructionKind::CVTTSS2SI: return encode_cvtts(tcb, insn);
	case InstructionKind::CVTTSD2SI: return encode_cvtts(tcb, insn);
	case InstructionKind::CVTSS2SD: return encode_cvts(tcb, insn);
	case InstructionKind::CVTSD2SS: return encode_cvts(tcb, insn);

	case InstructionKind::ADDSS: return encode_fp_adds(tcb, insn);
	case InstructionKind::ADDSD: return encode_fp_adds(tcb, insn);
	case InstructionKind::ADDPS: return encode_fp_adds(tcb, insn);
	case InstructionKind::ADDPD: return encode_fp_adds(tcb, insn);
	case InstructionKind::SUBSS: return encode_fp_subs(tcb, insn);
	case InstructionKind::SUBSD: return encode_fp_subs(tcb, insn);
	case InstructionKind::SUBPS: return encode_fp_subs(tcb, insn);
	case InstructionKind::SUBPD: return encode_fp_subs(tcb, insn);
	case InstructionKind::MULSS: return encode_fp_muls(tcb, insn);
	case InstructionKind::MULSD: return encode_fp_muls(tcb, insn);
	case InstructionKind::MULPS: return encode_fp_muls(tcb, insn);
	case InstructionKind::MULPD: return encode_fp_muls(tcb, insn);
	case InstructionKind::DIVSS: return encode_fp_divs(tcb, insn);
	case InstructionKind::DIVSD: return encode_fp_divs(tcb, insn);
	case InstructionKind::DIVPS: return encode_fp_divs(tcb, insn);
	case InstructionKind::DIVPD: return encode_fp_divs(tcb, insn);
	case InstructionKind::SQRTSS: return encode_fp_sqrts(tcb, insn);
	case InstructionKind::SQRTSD: return encode_fp_sqrts(tcb, insn);

	case InstructionKind::PSLLW: return encode_packed_shift(tcb, insn);
	case InstructionKind::PSLLD: return encode_packed_shift(tcb, insn);
	case InstructionKind::PSLLQ: return encode_packed_shift(tcb, insn);
	case InstructionKind::PSRLW: return encode_packed_shift(tcb, insn);
	case InstructionKind::PSRLD: return encode_packed_shift(tcb, insn);
	case InstructionKind::PSRLQ: return encode_packed_shift(tcb, insn);
	case InstructionKind::PSRAW: return encode_packed_shift(tcb, insn);
	case InstructionKind::PSRAD: return encode_packed_shift(tcb, insn);

	case InstructionKind::ROUNDSS: return encode_fp_rounds(tcb, insn);
	case InstructionKind::ROUNDSD: return encode_fp_rounds(tcb, insn);

	case InstructionKind::UCOMISS: return encode_ucomis(tcb, insn);
	case InstructionKind::UCOMISD: return encode_ucomis(tcb, insn);
	case InstructionKind::COMISS: return encode_ucomis(tcb, insn);
	case InstructionKind::COMISD: return encode_ucomis(tcb, insn);

	case InstructionKind::FLD: return encode_x87_fld(tcb, insn);
	case InstructionKind::FSTP: return encode_x87_fstp(tcb, insn);
	case InstructionKind::FADDP: return encode_x87_faddp(tcb, insn);
	case InstructionKind::FMULP: return encode_x87_fmulp(tcb, insn);

	case InstructionKind::LDMXCSR: return encode_mxcsr(tcb, insn);
	case InstructionKind::STMXCSR: return encode_mxcsr(tcb, insn);

	case InstructionKind::RDPKU: return encode_pku(tcb, insn);
	case InstructionKind::WRPKU: return encode_pku(tcb, insn);
	case InstructionKind::RDFSBASE: return encode_rd_sr_base(tcb, insn);
	case InstructionKind::RDGSBASE: return encode_rd_sr_base(tcb, insn);

	case InstructionKind::VFMADD132SD:
	case InstructionKind::VFMADD132SS:
	case InstructionKind::VFMADD213SD:
	case InstructionKind::VFMADD213SS:
	case InstructionKind::VFMADD231SD:
	case InstructionKind::VFMADD231SS:
		return encode_vfmadd(tcb, insn);

	case InstructionKind::XORPS:
		return encode_fp_packed_xor(tcb, insn);

	case InstructionKind::PCLMULQDQ:
		return encode_clmul(tcb, insn);

	default: return false;
	}
}

void Encoder::assert_true(bool cond, const char* msg, const Instruction *insn)
{
	if (!cond) {
		if (insn != nullptr) {
			Formatter fmt;
			_support.debug_printf("FAILING INSTRUCTION: %s\n", fmt.format_instruction(insn));
		}

		_support.assertion_fail(msg);
	}
}
