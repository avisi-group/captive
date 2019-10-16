/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/instruction.h>

using namespace captive::arch::dbt::mc::x86;

bool Operand::matches(OperandMatch match) const
{
	switch (match) {
		// Immediate constraints
	case OperandMatch::imm8: return is_const() && constant.width == 8;
	case OperandMatch::imm16: return is_const() && constant.width == 16;
	case OperandMatch::imm32: return is_const() && constant.width == 32;
	case OperandMatch::imm64: return is_const() && constant.width == 64;
	case OperandMatch::imm16_32: return matches(OperandMatch::imm16) || matches(OperandMatch::imm32);
	case OperandMatch::imm16_32_64: return matches(OperandMatch::imm16) || matches(OperandMatch::imm32) || matches(OperandMatch::imm64);

	case OperandMatch::r8: return is_reg() && reg.width == 8;
	case OperandMatch::r_m8: return matches(OperandMatch::r8) || (is_mem() && mem.access_width == 8);
	case OperandMatch::r16_32_64: return is_reg() && (reg.width == 16 || reg.width == 32 || reg.width == 64);
	case OperandMatch::r_m16_32_64: return matches(OperandMatch::r16_32_64) || (is_mem() && (mem.access_width == 16 || mem.access_width == 32 || mem.access_width == 64));
	}

	return false;
}

void Instruction::get_usedefs(UseDefList& list) const
{
	switch (kind()) {
	case InstructionKind::OUT:
		usedef_for_operand<true, false>(list, get_operand(0));
		break;

	case InstructionKind::CMOV:
	case InstructionKind::MOV:
	case InstructionKind::MOVZX:
	case InstructionKind::MOVSX:
	case InstructionKind::LEA:
	case InstructionKind::BSR:
	case InstructionKind::MOVD:
	case InstructionKind::MOVQ:
	case InstructionKind::MOVDQA:
	case InstructionKind::MOVSS:
	case InstructionKind::MOVSD:
	case InstructionKind::POPCNT:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<false, true>(list, get_operand(1));
		break;

	case InstructionKind::CMPXCHG:
		list.add(UseDef::make_use(X86PhysicalRegisters::A));
		list.add(UseDef::make_def(X86PhysicalRegisters::A));

		usedef_for_operand<true, true>(list, get_operand(0));
		usedef_for_operand<true, true>(list, get_operand(1));
		break;

	case InstructionKind::ADC:
	case InstructionKind::ADD:
	case InstructionKind::SUB:
	case InstructionKind::SBB:
	case InstructionKind::AND:
	case InstructionKind::OR:
	case InstructionKind::SHL:
	case InstructionKind::SHR:
	case InstructionKind::SAR:
	case InstructionKind::ROL:
	case InstructionKind::ROR:
	case InstructionKind::PADDB: case InstructionKind::PADDW: case InstructionKind::PADDD: case InstructionKind::PADDQ:
	case InstructionKind::PSUBB: case InstructionKind::PSUBW: case InstructionKind::PSUBD: case InstructionKind::PSUBQ:
	case InstructionKind::PCMPEQB: case InstructionKind::PCMPEQW: case InstructionKind::PCMPEQD: case InstructionKind::PCMPEQQ:
	case InstructionKind::PCMPGTB: case InstructionKind::PCMPGTW: case InstructionKind::PCMPGTD: case InstructionKind::PCMPGTQ:
	case InstructionKind::PAND:
	case InstructionKind::PANDN:
	case InstructionKind::POR:
	case InstructionKind::PUNPCKHBW:
	case InstructionKind::PUNPCKLBW:
	case InstructionKind::PUNPCKLWD:
	case InstructionKind::PUNPCKLDQ:
	case InstructionKind::PUNPCKLQDQ:
	case InstructionKind::PACKUSWB:
	case InstructionKind::ADDSS: case InstructionKind::ADDSD: case InstructionKind::ADDPS: case InstructionKind::ADDPD:
	case InstructionKind::SUBSS: case InstructionKind::SUBSD: case InstructionKind::SUBPS: case InstructionKind::SUBPD:
	case InstructionKind::MULSS: case InstructionKind::MULSD:
	case InstructionKind::DIVSS: case InstructionKind::DIVSD:
	case InstructionKind::PMULLD: case InstructionKind::PMULLW: case InstructionKind::PMULUDQ:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<true, true>(list, get_operand(1));
		break;

	case InstructionKind::PSHUFLW:
	case InstructionKind::PSHUFHW:
	case InstructionKind::PSHUFD:
		usedef_for_operand<true, false>(list, get_operand(1));
		usedef_for_operand<false, true>(list, get_operand(2));
		break;

	case InstructionKind::PXOR:
	case InstructionKind::XOR:
		if (get_operand(0) == get_operand(1)) {
			usedef_for_operand<false, true>(list, get_operand(0));
		} else {
			usedef_for_operand<true, false>(list, get_operand(0));
			usedef_for_operand<true, true>(list, get_operand(1));
		}
		break;

	case InstructionKind::SQRTSS:
	case InstructionKind::SQRTSD:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<true, false>(list, get_operand(1));
		break;

	case InstructionKind::PSLLW:
	case InstructionKind::PSLLD:
	case InstructionKind::PSLLQ:
	case InstructionKind::PSRLW:
	case InstructionKind::PSRLD:
	case InstructionKind::PSRLQ:
	case InstructionKind::PSRAW:
	case InstructionKind::PSRAD:
		usedef_for_operand<true, true>(list, get_operand(1));
		break;

	case InstructionKind::NEG:
	case InstructionKind::NOT:
	case InstructionKind::BSWAP:
		usedef_for_operand<true, true>(list, get_operand(0));
		break;

	case InstructionKind::INC:
	case InstructionKind::DEC:
		usedef_for_operand<true, true>(list, get_operand(0));
		break;

	case InstructionKind::CBTW:
	case InstructionKind::CWTL:
	case InstructionKind::CLTQ:
		list.add(UseDef::make_usedef(X86PhysicalRegisters::A));
		break;

	case InstructionKind::CWTD:
	case InstructionKind::CLTD:
	case InstructionKind::CQTO:
		list.add(UseDef::make_use(X86PhysicalRegisters::A));
		list.add(UseDef::make_def(X86PhysicalRegisters::D));
		break;

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
		usedef_for_operand<false, true>(list, get_operand(0));
		break;

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
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<true, true>(list, get_operand(1));
		break;

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
	case InstructionKind::JMP:
		usedef_for_operand<true, false>(list, get_operand(0));
		break;

	case InstructionKind::TEST:
	case InstructionKind::CMP:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<true, false>(list, get_operand(1));
		break;

	case InstructionKind::CALL:
	case InstructionKind::LCALL:
	case InstructionKind::QCALL:
		usedef_for_operand<true, false>(list, get_operand(0));
		list.add(UseDef::make_use(X86PhysicalRegisters::DI));
		list.add(UseDef::make_use(X86PhysicalRegisters::SI));
		list.add(UseDef::make_use(X86PhysicalRegisters::D));
		list.add(UseDef::make_use(X86PhysicalRegisters::C));
		list.add(UseDef::make_use(X86PhysicalRegisters::R8));
		break;

	case InstructionKind::CALL0:
		usedef_for_operand<true, false>(list, get_operand(0));
		break;

	case InstructionKind::CALL1:
		usedef_for_operand<true, false>(list, get_operand(0));
		list.add(UseDef::make_use(X86PhysicalRegisters::DI));
		break;

	case InstructionKind::CALL2:
		usedef_for_operand<true, false>(list, get_operand(0));
		list.add(UseDef::make_use(X86PhysicalRegisters::DI));
		list.add(UseDef::make_use(X86PhysicalRegisters::SI));
		break;

	case InstructionKind::CALL3:
		usedef_for_operand<true, false>(list, get_operand(0));
		list.add(UseDef::make_use(X86PhysicalRegisters::DI));
		list.add(UseDef::make_use(X86PhysicalRegisters::SI));
		list.add(UseDef::make_use(X86PhysicalRegisters::D));
		break;

	case InstructionKind::CALL4:
		usedef_for_operand<true, false>(list, get_operand(0));
		list.add(UseDef::make_use(X86PhysicalRegisters::DI));
		list.add(UseDef::make_use(X86PhysicalRegisters::SI));
		list.add(UseDef::make_use(X86PhysicalRegisters::D));
		list.add(UseDef::make_use(X86PhysicalRegisters::C));
		break;

	case InstructionKind::CALL5:
		usedef_for_operand<true, false>(list, get_operand(0));
		list.add(UseDef::make_use(X86PhysicalRegisters::DI));
		list.add(UseDef::make_use(X86PhysicalRegisters::SI));
		list.add(UseDef::make_use(X86PhysicalRegisters::D));
		list.add(UseDef::make_use(X86PhysicalRegisters::C));
		list.add(UseDef::make_use(X86PhysicalRegisters::R8));
		break;

	case InstructionKind::CALL6:
		usedef_for_operand<true, false>(list, get_operand(0));
		list.add(UseDef::make_use(X86PhysicalRegisters::DI));
		list.add(UseDef::make_use(X86PhysicalRegisters::SI));
		list.add(UseDef::make_use(X86PhysicalRegisters::D));
		list.add(UseDef::make_use(X86PhysicalRegisters::C));
		list.add(UseDef::make_use(X86PhysicalRegisters::R8));
		list.add(UseDef::make_use(X86PhysicalRegisters::R9));
		break;

	case InstructionKind::PUSH:
		usedef_for_operand<true, false>(list, get_operand(0));
		list.add(UseDef::make_usedef(X86PhysicalRegisters::SP));
		break;

	case InstructionKind::POP:
		usedef_for_operand<false, true>(list, get_operand(0));
		list.add(UseDef::make_usedef(X86PhysicalRegisters::SP));
		break;

	case InstructionKind::REP_STOSQ:
		list.add(UseDef::make_use(X86PhysicalRegisters::A));
		list.add(UseDef::make_use(X86PhysicalRegisters::DI));
		break;

	case InstructionKind::RET:
		list.add(UseDef::make_usedef(X86PhysicalRegisters::SP));
		list.add(UseDef::make_usedef(X86PhysicalRegisters::BP));
		list.add(UseDef::make_usedef(X86PhysicalRegisters::A));
		break;

	case InstructionKind::CLC:
	case InstructionKind::STC:
	case InstructionKind::CMC:
	case InstructionKind::CLD:
		break;

	case InstructionKind::INT:
		break;

	case InstructionKind::DIV:
	case InstructionKind::IDIV:
	case InstructionKind::MUL:
	case InstructionKind::IMUL:
		list.add(UseDef::make_usedef(X86PhysicalRegisters::D));
		list.add(UseDef::make_usedef(X86PhysicalRegisters::A));
		usedef_for_operand<true, false>(list, get_operand(0));
		break;

	case InstructionKind::PEXTRB:
	case InstructionKind::PEXTRW:
	case InstructionKind::PEXTRD:
	case InstructionKind::PEXTRQ:
		usedef_for_operand<true, false>(list, get_operand(1));
		usedef_for_operand<false, true>(list, get_operand(2));
		break;

	case InstructionKind::PINSRB:
	case InstructionKind::PINSRW:
	case InstructionKind::PINSRD:
	case InstructionKind::PINSRQ:
		usedef_for_operand<true, false>(list, get_operand(1));
		usedef_for_operand<true, true>(list, get_operand(2));
		break;

	case InstructionKind::CVTSI2SS:
	case InstructionKind::CVTSI2SD:
	case InstructionKind::CVTTSS2SI:
	case InstructionKind::CVTTSD2SI:
	case InstructionKind::CVTSS2SD:
	case InstructionKind::CVTSD2SS:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<false, true>(list, get_operand(1));
		break;

	case InstructionKind::UCOMISS:
	case InstructionKind::UCOMISD:
	case InstructionKind::COMISS:
	case InstructionKind::COMISD:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<true, false>(list, get_operand(1));
		break;

	case InstructionKind::ROUNDSS:
	case InstructionKind::ROUNDSD:
		usedef_for_operand<true, false>(list, get_operand(1));
		usedef_for_operand<false, true>(list, get_operand(2));
		break;

	case InstructionKind::FLD:
	case InstructionKind::FSTP:
		usedef_for_operand<false, true>(list, get_operand(0));
		break;

	case InstructionKind::SYSCALL:
		list.add(UseDef::make_def(X86PhysicalRegisters::C));
		list.add(UseDef::make_def(X86PhysicalRegisters::R11));
		break;

	case InstructionKind::FADDP:
	case InstructionKind::FMULP:
		break;

	case InstructionKind::DEAD:
	case InstructionKind::LABEL:
	case InstructionKind::NOP:
	case InstructionKind::LITERAL:
		break;

	case InstructionKind::LDMXCSR:
		usedef_for_operand<true, false>(list, get_operand(0));
		break;

	case InstructionKind::STMXCSR:
		usedef_for_operand<false, true>(list, get_operand(0));
		break;

	case InstructionKind::RDPKU:
		list.add(UseDef::make_use(X86PhysicalRegisters::C));
		list.add(UseDef::make_def(X86PhysicalRegisters::D));
		list.add(UseDef::make_def(X86PhysicalRegisters::A));
		break;

	case InstructionKind::WRPKU:
		list.add(UseDef::make_use(X86PhysicalRegisters::C));
		list.add(UseDef::make_use(X86PhysicalRegisters::D));
		list.add(UseDef::make_use(X86PhysicalRegisters::A));
		break;

	case InstructionKind::RDFSBASE:
	case InstructionKind::RDGSBASE:
		usedef_for_operand<false, true>(list, get_operand(0));
		break;

	case InstructionKind::VFMADD132SS:
	case InstructionKind::VFMADD132SD:
	case InstructionKind::VFMADD213SS:
	case InstructionKind::VFMADD213SD:
	case InstructionKind::VFMADD231SS:
	case InstructionKind::VFMADD231SD:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<true, false>(list, get_operand(1));
		usedef_for_operand<true, true>(list, get_operand(2));
		break;

	case InstructionKind::PCLMULQDQ:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<true, true>(list, get_operand(1));
		break;

	case InstructionKind::XORPS:
	case InstructionKind::XORPD:
		usedef_for_operand<true, false>(list, get_operand(0));
		usedef_for_operand<true, true>(list, get_operand(1));
		break;

	default:
		break;
	}
}

template<bool I, bool O>
void Instruction::usedef_for_operand(UseDefList& list, const Operand& op)
{
	if (op.is_reg() && op.reg.reg == X86PhysicalRegisters::RIZ) return;
	if (op.is_reg() && op.reg.reg == X86PhysicalRegisters::CR3) return;

	if (I && O) {
		if (op.is_reg()) {
			list.add(UseDef::make_usedef(op.reg.reg));
		} else if (op.is_mem()) {
			if (op.mem.base_register != X86PhysicalRegisters::RIZ) {
				list.add(UseDef::make_use(op.mem.base_register));
			}

			if (op.mem.index_register != X86PhysicalRegisters::RIZ) {
				list.add(UseDef::make_use(op.mem.index_register));
			}
		}
	} else if (I) {
		if (op.is_reg()) {
			list.add(UseDef::make_use(op.reg.reg));
		} else if (op.is_mem()) {
			if (op.mem.base_register != X86PhysicalRegisters::RIZ) {
				list.add(UseDef::make_use(op.mem.base_register));
			}

			if (op.mem.index_register != X86PhysicalRegisters::RIZ) {
				list.add(UseDef::make_use(op.mem.index_register));
			}
		}
	} else if (O) {
		if (op.is_reg()) {
			list.add(UseDef::make_def(op.reg.reg));
		} else if (op.is_mem()) {
			if (op.mem.base_register != X86PhysicalRegisters::RIZ) {
				list.add(UseDef::make_use(op.mem.base_register));
			}

			if (op.mem.index_register != X86PhysicalRegisters::RIZ) {
				list.add(UseDef::make_use(op.mem.index_register));
			}
		}
	}
}

InstructionMatch::InstructionMatch1 Instruction::match1() const
{
	const Operand& o0 = get_operand(0);

	switch (o0.kind) {
	case OperandKind::REGISTER:
		if (o0.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE)
			return InstructionMatch::REG;
		else if (o0.reg.reg.regclass() == X86RegisterClasses::SSE)
			return InstructionMatch::FREG;
		else
			return InstructionMatch::INVALID1;
	case OperandKind::MEMORY: return InstructionMatch::MEM;
	default: return InstructionMatch::INVALID1;
	}
}

InstructionMatch::InstructionMatch2 Instruction::match2() const
{
	const Operand& o0 = get_operand(0);
	const Operand& o1 = get_operand(1);

	switch (o0.kind) {
	case OperandKind::REGISTER:
		switch (o1.kind) {
		case OperandKind::REGISTER:
			if (o0.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE && o1.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE)
				return InstructionMatch::REG_REG;
			else if (o0.reg.reg.regclass() == X86RegisterClasses::SSE && o1.reg.reg.regclass() == X86RegisterClasses::SSE)
				return InstructionMatch::FREG_FREG;
			else if (o0.reg.reg.regclass() == X86RegisterClasses::SSE && o1.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE)
				return InstructionMatch::FREG_REG;
			else if (o0.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE && o1.reg.reg.regclass() == X86RegisterClasses::SSE)
				return InstructionMatch::REG_FREG;
			else if (o0.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE && o1.reg.reg.regclass() == X86RegisterClasses::SEGMENT)
				return InstructionMatch::REG_SREG;
			else if (o0.reg.reg.regclass() == X86RegisterClasses::SEGMENT && o1.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE)
				return InstructionMatch::SREG_REG;
			else if (o0.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE && o1.reg.reg.regclass() == X86RegisterClasses::CONTROL)
				return InstructionMatch::REG_CREG;
			else if (o0.reg.reg.regclass() == X86RegisterClasses::CONTROL && o1.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE)
				return InstructionMatch::CREG_REG;
			else
				return InstructionMatch::INVALID2;
		case OperandKind::MEMORY:
			if (o0.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE)
				return InstructionMatch::REG_MEM;
			else if (o0.reg.reg.regclass() == X86RegisterClasses::SSE)
				return InstructionMatch::FREG_MEM;
			else
				return InstructionMatch::INVALID2;
		default:
			return InstructionMatch::INVALID2;
		}

	case OperandKind::MEMORY:
		switch (o1.kind) {
		case OperandKind::REGISTER:
			if (o1.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE)
				return InstructionMatch::MEM_REG;
			else if (o1.reg.reg.regclass() == X86RegisterClasses::SSE)
				return InstructionMatch::MEM_FREG;
			else
				return InstructionMatch::INVALID2;
		case OperandKind::MEMORY:
			return InstructionMatch::MEM_MEM;
		default:
			return InstructionMatch::INVALID2;
		}

	case OperandKind::CONSTANT:
		switch (o1.kind) {
		case OperandKind::REGISTER:
			if (o1.reg.reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE)
				return InstructionMatch::CONST_REG;
			else
				return InstructionMatch::INVALID2;
		case OperandKind::MEMORY:
			return InstructionMatch::CONST_MEM;
		default:
			return InstructionMatch::INVALID2;
		}

	default:
		return InstructionMatch::INVALID2;
	}
}

InstructionMatch::InstructionMatch3 Instruction::match3() const
{
	const Operand& o0 = get_operand(0);
	const Operand& o1 = get_operand(1);
	const Operand& o2 = get_operand(2);

	if ((o0.is_reg() && o0.reg.reg.is_sse()) && (o1.is_reg() && o1.reg.reg.is_sse()) && (o2.is_reg() && o2.reg.reg.is_sse())) {
		return InstructionMatch::FREG_FREG_FREG;
	} else if ((o0.is_reg() && o0.reg.reg.is_sse()) && (o1.is_reg() && o1.reg.reg.is_sse()) && (o2.is_const())) {
		return InstructionMatch::FREG_FREG_IMM;
	}

	return InstructionMatch::INVALID3;
}

bool Instruction::is_control_flow() const
{
	switch (kind()) {
	case InstructionKind::JMP:
	case InstructionKind::JO:
	case InstructionKind::JNO:
	case InstructionKind::JB:
	case InstructionKind::JNAE:
	case InstructionKind::JC:
	case InstructionKind::JNB:
	case InstructionKind::JAE:
	case InstructionKind::JNC:
	case InstructionKind::JZ:
	case InstructionKind::JE:
	case InstructionKind::JNZ:
	case InstructionKind::JNE:
	case InstructionKind::JBE:
	case InstructionKind::JNA:
	case InstructionKind::JNBE:
	case InstructionKind::JA:
	case InstructionKind::JS:
	case InstructionKind::JNS:
	case InstructionKind::JP:
	case InstructionKind::JPE:
	case InstructionKind::JNP:
	case InstructionKind::JPO:
	case InstructionKind::JL:
	case InstructionKind::JNGE:
	case InstructionKind::JNL:
	case InstructionKind::JGE:
	case InstructionKind::JLE:
	case InstructionKind::JNG:
	case InstructionKind::JNLE:
	case InstructionKind::JG:
		return true;

	default:
		return false;
	}
}
