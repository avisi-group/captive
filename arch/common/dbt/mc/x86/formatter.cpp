/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/formatter.h>
#include <dbt/mc/x86/instruction.h>

using namespace captive::arch::dbt::mc::x86;

const char* Formatter::format_instruction(const Instruction* insn)
{
	cur = 0;
	buffer[0] = 0;

	if (insn->kind() != InstructionKind::LABEL) append("  ");

	switch (insn->kind()) {
	case InstructionKind::DEAD: append("<dead>");
		break;
	case InstructionKind::NOP: append("nop");
		break;
	case InstructionKind::OUT: append("out");
		break;

	case InstructionKind::INC: append("inc");
		break;
	case InstructionKind::DEC: append("dec");
		break;

	case InstructionKind::ADD: append("add");
		break;
	case InstructionKind::SUB: append("sub");
		break;
	case InstructionKind::ADC: append("adc");
		break;
	case InstructionKind::SBB: append("sbb");
		break;

	case InstructionKind::AND: append("and");
		break;
	case InstructionKind::OR: append("or");
		break;
	case InstructionKind::XOR: append("xor");
		break;

	case InstructionKind::MUL: append("mul");
		break;
	case InstructionKind::IMUL: append("imul");
		break;
	case InstructionKind::DIV: append("div");
		break;
	case InstructionKind::IDIV: append("idiv");
		break;

	case InstructionKind::POPCNT: append("popcnt");
		break;

	case InstructionKind::MOV: append("mov");
		break;
	case InstructionKind::LEA: append("lea");
		break;
	case InstructionKind::MOVZX: append("movz");
		break;
	case InstructionKind::MOVSX: append("movs");
		break;
	case InstructionKind::CMPXCHG: append("cmpxchg");
		break;

	case InstructionKind::CBTW: append("cbtw");
		break;
	case InstructionKind::CWTL: append("cwtl");
		break;
	case InstructionKind::CLTQ: append("cltq");
		break;
	case InstructionKind::CWTD: append("cwtd");
		break;
	case InstructionKind::CLTD: append("cltd");
		break;
	case InstructionKind::CQTO: append("cqto");
		break;

	case InstructionKind::RET: append("ret");
		break;
	case InstructionKind::JMP: append("jmp");
		break;
	case InstructionKind::LEAVE: append("leave");
		break;
	case InstructionKind::INT: append("int");
		break;

	case InstructionKind::SAR: append("sar");
		break;
	case InstructionKind::SHR: append("shr");
		break;
	case InstructionKind::SHL: append("shl");
		break;

	case InstructionKind::NOT: append("not");
		break;
	case InstructionKind::NEG: append("neg");
		break;

	case InstructionKind::TEST: append("test");
		break;
	case InstructionKind::CMP: append("cmp");
		break;
	case InstructionKind::STC: append("stc");
		break;
	case InstructionKind::CLC: append("clc");
		break;

	case InstructionKind::CALL:
	case InstructionKind::CALL0:
	case InstructionKind::CALL1:
	case InstructionKind::CALL2:
	case InstructionKind::CALL3:
	case InstructionKind::CALL4:
	case InstructionKind::CALL5:
	case InstructionKind::CALL6:
		append("call");
		break;

	case InstructionKind::PUSH: append("push");
		break;
	case InstructionKind::POP: append("pop");
		break;

	case InstructionKind::SETO: append("seto");
		break;
	case InstructionKind::SETNO: append("setno");
		break;
	case InstructionKind::SETB: append("setb");
		break;
	case InstructionKind::SETNAE: append("setnae");
		break;
	case InstructionKind::SETC: append("setc");
		break;
	case InstructionKind::SETNB: append("setnb");
		break;
	case InstructionKind::SETAE: append("setae");
		break;
	case InstructionKind::SETNC: append("setnc");
		break;
	case InstructionKind::SETZ: append("setz");
		break;
	case InstructionKind::SETE: append("sete");
		break;
	case InstructionKind::SETNZ: append("setnz");
		break;
	case InstructionKind::SETNE: append("setne");
		break;
	case InstructionKind::SETBE: append("setbe");
		break;
	case InstructionKind::SETNA: append("setna");
		break;
	case InstructionKind::SETNBE: append("setnbe");
		break;
	case InstructionKind::SETA: append("seta");
		break;
	case InstructionKind::SETS: append("sets");
		break;
	case InstructionKind::SETNS: append("setns");
		break;
	case InstructionKind::SETP: append("setp");
		break;
	case InstructionKind::SETPE: append("setpe");
		break;
	case InstructionKind::SETNP: append("setnp");
		break;
	case InstructionKind::SETPO: append("setpo");
		break;
	case InstructionKind::SETL: append("setl");
		break;
	case InstructionKind::SETNGE: append("setnge");
		break;
	case InstructionKind::SETNL: append("setnl");
		break;
	case InstructionKind::SETGE: append("setge");
		break;
	case InstructionKind::SETLE: append("setle");
		break;
	case InstructionKind::SETNG: append("setng");
		break;
	case InstructionKind::SETNLE: append("setnle");
		break;
	case InstructionKind::SETG: append("setg");
		break;

	case InstructionKind::JO: append("jo");
		break;
	case InstructionKind::JNO: append("jno");
		break;
	case InstructionKind::JB: append("jb");
		break;
	case InstructionKind::JNAE: append("jnae");
		break;
	case InstructionKind::JC: append("jc");
		break;
	case InstructionKind::JNB: append("jnb");
		break;
	case InstructionKind::JAE: append("jae");
		break;
	case InstructionKind::JNC: append("jnc");
		break;
	case InstructionKind::JZ: append("jz");
		break;
	case InstructionKind::JE: append("je");
		break;
	case InstructionKind::JNZ: append("jnz");
		break;
	case InstructionKind::JNE: append("jne");
		break;
	case InstructionKind::JBE: append("jbe");
		break;
	case InstructionKind::JNA: append("jna");
		break;
	case InstructionKind::JNBE: append("jnbe");
		break;
	case InstructionKind::JA: append("ja");
		break;
	case InstructionKind::JS: append("js");
		break;
	case InstructionKind::JNS: append("jns");
		break;
	case InstructionKind::JP: append("jp");
		break;
	case InstructionKind::JPE: append("jpe");
		break;
	case InstructionKind::JNP: append("jnp");
		break;
	case InstructionKind::JPO: append("jpo");
		break;
	case InstructionKind::JL: append("jl");
		break;
	case InstructionKind::JNGE: append("jnge");
		break;
	case InstructionKind::JNL: append("jnl");
		break;
	case InstructionKind::JGE: append("jge");
		break;
	case InstructionKind::JLE: append("jle");
		break;
	case InstructionKind::JNG: append("jng");
		break;
	case InstructionKind::JNLE: append("jnle");
		break;
	case InstructionKind::JG: append("jg");
		break;

	case InstructionKind::CMOVO: append("cmovo");
		break;
	case InstructionKind::CMOVNO: append("cmovno");
		break;
	case InstructionKind::CMOVB: append("cmovb");
		break;
	case InstructionKind::CMOVNAE: append("cmovnae");
		break;
	case InstructionKind::CMOVC: append("cmovc");
		break;
	case InstructionKind::CMOVNB: append("cmovnb");
		break;
	case InstructionKind::CMOVAE: append("cmovae");
		break;
	case InstructionKind::CMOVNC: append("cmovnc");
		break;
	case InstructionKind::CMOVZ: append("cmovz");
		break;
	case InstructionKind::CMOVE: append("cmove");
		break;
	case InstructionKind::CMOVNZ: append("cmovnz");
		break;
	case InstructionKind::CMOVNE: append("cmovne");
		break;
	case InstructionKind::CMOVBE: append("cmovbe");
		break;
	case InstructionKind::CMOVNA: append("cmovna");
		break;
	case InstructionKind::CMOVNBE: append("cmovnbe");
		break;
	case InstructionKind::CMOVA: append("cmova");
		break;
	case InstructionKind::CMOVS: append("cmovs");
		break;
	case InstructionKind::CMOVNS: append("cmovns");
		break;
	case InstructionKind::CMOVP: append("cmovp");
		break;
	case InstructionKind::CMOVPE: append("cmovpe");
		break;
	case InstructionKind::CMOVNP: append("cmovnp");
		break;
	case InstructionKind::CMOVPO: append("cmovpo");
		break;
	case InstructionKind::CMOVL: append("cmovl");
		break;
	case InstructionKind::CMOVNGE: append("cmovnge");
		break;
	case InstructionKind::CMOVNL: append("cmovnl");
		break;
	case InstructionKind::CMOVGE: append("cmovge");
		break;
	case InstructionKind::CMOVLE: append("cmovle");
		break;
	case InstructionKind::CMOVNG: append("cmovng");
		break;
	case InstructionKind::CMOVNLE: append("cmovnle");
		break;
	case InstructionKind::CMOVG: append("cmovg");
		break;

	case InstructionKind::BSR: append("bsr");
		break;
	case InstructionKind::BSWAP: append("bswap");
		break;

	case InstructionKind::MOVD: append("movd");
		break;
	case InstructionKind::MOVQ: append("movq");
		break;
	case InstructionKind::MOVDQA: append("movdqa");
		break;
	case InstructionKind::MOVSS: append("movss");
		break;
	case InstructionKind::MOVSD: append("movsd");
		break;
	case InstructionKind::PADDB: append("paddb");
		break;
	case InstructionKind::PADDW: append("paddw");
		break;
	case InstructionKind::PADDD: append("paddd");
		break;
	case InstructionKind::PADDQ: append("paddq");
		break;
	case InstructionKind::PSUBB: append("psubb");
		break;
	case InstructionKind::PSUBW: append("psubw");
		break;
	case InstructionKind::PSUBD: append("psubd");
		break;
	case InstructionKind::PSUBQ: append("psubq");
		break;
	case InstructionKind::PCMPEQB: append("pcmpeqb");
		break;
	case InstructionKind::PCMPEQW: append("pcmpeqw");
		break;
	case InstructionKind::PCMPEQD: append("pcmpeqd");
		break;
	case InstructionKind::PCMPEQQ: append("pcmpeqq");
		break;
	case InstructionKind::PCMPGTB: append("pcmpgtb");
		break;
	case InstructionKind::PCMPGTW: append("pcmpgtw");
		break;
	case InstructionKind::PCMPGTD: append("pcmpgtd");
		break;
	case InstructionKind::PCMPGTQ: append("pcmpgtq");
		break;
	case InstructionKind::PAND: append("pand");
		break;
	case InstructionKind::PANDN: append("pandn");
		break;
	case InstructionKind::POR: append("por");
		break;
	case InstructionKind::PXOR: append("pxor");
		break;
	case InstructionKind::PEXTRB: append("pextrb");
		break;
	case InstructionKind::PEXTRW: append("pextrw");
		break;
	case InstructionKind::PEXTRD: append("pextrd");
		break;
	case InstructionKind::PEXTRQ: append("pextrq");
		break;
	case InstructionKind::PINSRB: append("pinsrb");
		break;
	case InstructionKind::PINSRW: append("pinsrw");
		break;
	case InstructionKind::PINSRD: append("pinsrd");
		break;
	case InstructionKind::PINSRQ: append("pinsrq");
		break;

	case InstructionKind::PMULLW: append("pmullw");
		break;

	case InstructionKind::CVTSI2SS: append("cvtsi2ss");
		break;
	case InstructionKind::CVTSI2SD: append("cvtsi2sd");
		break;
	case InstructionKind::CVTTSS2SI: append("cvttss2si");
		break;
	case InstructionKind::CVTTSD2SI: append("cvttsd2si");
		break;
	case InstructionKind::CVTSS2SD: append("cvtss2sd");
		break;
	case InstructionKind::CVTSD2SS: append("cvtsd2ss");
		break;

	case InstructionKind::ADDSS: append("addss");
		break;
	case InstructionKind::ADDSD: append("addsd");
		break;
	case InstructionKind::SUBSS: append("subss");
		break;
	case InstructionKind::SUBSD: append("subsd");
		break;
	case InstructionKind::SUBPS: append("subps");
		break;
	case InstructionKind::SUBPD: append("subpd");
		break;
	case InstructionKind::MULSS: append("mulss");
		break;
	case InstructionKind::MULSD: append("mulsd");
		break;
	case InstructionKind::DIVSS: append("divss");
		break;
	case InstructionKind::DIVSD: append("divsd");
		break;
	case InstructionKind::SQRTSS: append("sqrtss");
		break;
	case InstructionKind::SQRTSD: append("sqrtsd");
		break;

	case InstructionKind::ROUNDSS: append("roundss");
		break;
	case InstructionKind::ROUNDSD: append("roundsd");
		break;

	case InstructionKind::PSLLD: append("pslld");
		break;
	case InstructionKind::PSLLQ: append("psllq");
		break;
	case InstructionKind::PSRLD: append("psrld");
		break;
	case InstructionKind::PSRLQ: append("psrlq");
		break;

	case InstructionKind::UCOMISS: append("ucomiss");
		break;
	case InstructionKind::UCOMISD: append("ucomisd");
		break;
	case InstructionKind::COMISS: append("comiss");
		break;
	case InstructionKind::COMISD: append("comisd");
		break;

	case InstructionKind::FLD: append("fld");
		break;
	case InstructionKind::FSTP: append("fstp");
		break;
	case InstructionKind::FADDP: append("faddp");
		break;
	case InstructionKind::FMULP: append("fmulp");
		break;

	case InstructionKind::LDMXCSR: append("ldmxcsr");
		break;
	case InstructionKind::STMXCSR: append("stmxcsr");
		break;

	case InstructionKind::SYSCALL: append("syscall");
		break;

	case InstructionKind::VFMADD132SD: append("vfmadd132sd");
		break;
	case InstructionKind::VFMADD132SS: append("vfmadd132ss");
		break;
	case InstructionKind::VFMADD213SD: append("vfmadd213sd");
		break;
	case InstructionKind::VFMADD213SS: append("vfmadd213ss");
		break;
	case InstructionKind::VFMADD231SD: append("vfmadd231sd");
		break;
	case InstructionKind::VFMADD231SS: append("vfmadd231ss");
		break;

	case InstructionKind::RDFSBASE: append("rdfsbase");
		break;
	case InstructionKind::RDGSBASE: append("rdgsbase");
		break;

	case InstructionKind::PCLMULQDQ: append("pclmulqdq");
		break;

	case InstructionKind::XORPS: append("xorps");
		break;

	case InstructionKind::LABEL: append("B_");
		append_hex((dbt_u64) insn);
		append(":");
		break;

	case InstructionKind::LITERAL:
		append(".");
		switch (insn->get_operand(0).literal.width) {
		case 8: append("byte ");
			break;
		case 16: append("word ");
			break;
		case 32: append("long ");
			break;
		case 64: append("quad ");
			break;
		}
		break;

	default:
		append("??? (");
		append_dec((dbt_u64) insn->kind());
		append(")");
		break;
	}

	for (int i = 0; i < Instruction::NR_OPERANDS; i++) {
		const auto& operand = insn->get_operand(i);

		if (operand.kind == OperandKind::INVALID) continue;

		if (i > 0) {
			append(", ");
		} else {
			append(" ");
		}

		append_operand(operand);
	}

	return buffer;
}

void Formatter::append_operand(const Operand& operand)
{
	switch (operand.kind) {
	case OperandKind::LITERAL:
		append("0x");
		append_hex(operand.constant.value);
		break;

	case OperandKind::CONSTANT:
		append("$");
		append_hex(operand.constant.value);
		append(":");
		append_dec(operand.constant.width);
		break;
	case OperandKind::REGISTER:
		append_reg(operand.reg.reg, operand.reg.width);
		break;
	case OperandKind::MEMORY:
		if (operand.mem.segment_override != X86PhysicalRegisters::DS) {
			append_reg(operand.mem.segment_override, 64);
			append(":");
		}

		if (operand.mem.displacement || operand.mem.base_register == X86PhysicalRegisters::RIZ) append_hex(operand.mem.displacement);

		if (operand.mem.base_register != X86PhysicalRegisters::RIZ) {
			append("(");
			append_reg(operand.mem.base_register, operand.mem.address_width);

			if (operand.mem.index_register != X86PhysicalRegisters::RIZ) {
				append(",");
				append_reg(operand.mem.index_register, operand.mem.address_width);
				switch (operand.mem.scale) {
				case MemoryScale::S2: append(",2");
					break;
				case MemoryScale::S4: append(",4");
					break;
				case MemoryScale::S8: append(",8");
					break;
				default: break;
				}
			}

			append("):");
			append_dec(operand.mem.access_width);
		} else if (operand.mem.index_register != X86PhysicalRegisters::RIZ) {
			append("(%riz,");
			append_reg(operand.mem.index_register, operand.mem.address_width);
			switch (operand.mem.scale) {
			case MemoryScale::S2: append(",2");
				break;
			case MemoryScale::S4: append(",4");
				break;
			case MemoryScale::S8: append(",8");
				break;
			default: break;
			}
			append(")");
		}

		break;
	case OperandKind::LABEL:
		append("B_");
		append_hex((dbt_u64) operand.label.target);
		break;

	case OperandKind::INVALID:
		append("<invalid>");
		break;

	default:
		append("<???>");
		break;
	}
}

void Formatter::append(const char* str)
{
	while (*str) {
		buffer[cur++] = *str++;
	}

	buffer[cur] = 0;
}

void Formatter::append_char(char ch)
{
	buffer[cur++] = ch;
	buffer[cur] = 0;
}

void Formatter::append_num(dbt_u64 v, dbt_u8 base)
{
	if (v == 0) {
		append("0");
		return;
	}

	char local_buffer[16];
	int i = 14;

	local_buffer[15] = 0;

	dbt_u64 value = v;
	while (value > 0) {
		dbt_u8 digit = value % base;

		if (digit < 10) local_buffer[i--] = ('0' + digit);
		else local_buffer[i--] = ('a' + (digit - 10));

		value = value / base;
	}

	append(&local_buffer[i + 1]);
}

void Formatter::append_reg(const X86PhysicalRegister& reg, dbt_u8 width_in_bits)
{
	append("%");

	switch (reg.unique_index()) {
	case 0: switch (width_in_bits) {
			case 8: append("al");
			return;
			case 16: append("ax");
			return;
			case 32: append("eax");
			return;
			case 64: append("rax");
			return;
		}
		break;
	case 1: switch (width_in_bits) {
			case 8: append("cl");
			return;
			case 16: append("cx");
			return;
			case 32: append("ecx");
			return;
			case 64: append("rcx");
			return;
		}
		break;
	case 2: switch (width_in_bits) {
			case 8: append("dl");
			return;
			case 16: append("dx");
			return;
			case 32: append("edx");
			return;
			case 64: append("rdx");
			return;
		}
		break;
	case 3: switch (width_in_bits) {
			case 8: append("bl");
			return;
			case 16: append("bx");
			return;
			case 32: append("ebx");
			return;
			case 64: append("rbx");
			return;
		}
		break;
	case 4: switch (width_in_bits) {
			case 8: append("spl");
			return;
			case 16: append("sp");
			return;
			case 32: append("esp");
			return;
			case 64: append("rsp");
			return;
		}
		break;
	case 5: switch (width_in_bits) {
			case 8: append("bpl");
			return;
			case 16: append("bp");
			return;
			case 32: append("ebp");
			return;
			case 64: append("rbp");
			return;
		}
		break;
	case 6: switch (width_in_bits) {
			case 8: append("sil");
			return;
			case 16: append("si");
			return;
			case 32: append("esi");
			return;
			case 64: append("rsi");
			return;
		}
		break;
	case 7: switch (width_in_bits) {
			case 8: append("dil");
			return;
			case 16: append("di");
			return;
			case 32: append("edi");
			return;
			case 64: append("rdi");
			return;
		}
		break;

	case 8: switch (width_in_bits) {
			case 8: append("r8b");
			return;
			case 16: append("r8w");
			return;
			case 32: append("r8d");
			return;
			case 64: append("r8");
			return;
		}
		break;
	case 9: switch (width_in_bits) {
			case 8: append("r9b");
			return;
			case 16: append("r9w");
			return;
			case 32: append("r9d");
			return;
			case 64: append("r9");
			return;
		}
		break;
	case 10: switch (width_in_bits) {
			case 8: append("r10b");
			return;
			case 16: append("r10w");
			return;
			case 32: append("r10d");
			return;
			case 64: append("r10");
			return;
		}
		break;
	case 11: switch (width_in_bits) {
			case 8: append("r11b");
			return;
			case 16: append("r11w");
			return;
			case 32: append("r11d");
			return;
			case 64: append("r11");
			return;
		}
		break;
	case 12: switch (width_in_bits) {
			case 8: append("r12b");
			return;
			case 16: append("r12w");
			return;
			case 32: append("r12d");
			return;
			case 64: append("r12");
			return;
		}
		break;
	case 13: switch (width_in_bits) {
			case 8: append("r13b");
			return;
			case 16: append("r13w");
			return;
			case 32: append("r13d");
			return;
			case 64: append("r13");
			return;
		}
		break;
	case 14: switch (width_in_bits) {
			case 8: append("r14b");
			return;
			case 16: append("r14w");
			return;
			case 32: append("r14d");
			return;
			case 64: append("r14");
			return;
		}
		break;
	case 15: switch (width_in_bits) {
			case 8: append("r15b");
			return;
			case 16: append("r15w");
			return;
			case 32: append("r15d");
			return;
			case 64: append("r15");
			return;
		}
		break;

	case 16: append("xmm0");
		return;
	case 17: append("xmm1");
		return;
	case 18: append("xmm2");
		return;
	case 19: append("xmm3");
		return;
	case 20: append("xmm4");
		return;
	case 21: append("xmm5");
		return;
	case 22: append("xmm6");
		return;
	case 23: append("xmm7");
		return;
	case 24: append("xmm8");
		return;
	case 25: append("xmm9");
		return;
	case 26: append("xmm10");
		return;
	case 27: append("xmm11");
		return;
	case 28: append("xmm12");
		return;
	case 29: append("xmm13");
		return;
	case 30: append("xmm14");
		return;
	case 31: append("xmm15");
		return;

	case 32: append("riz");
		return;
	case 33: append("rip");
		return;
	case 34: append("rflags");
		return;

	case 35: append("es");
		return;
	case 36: append("cs");
		return;
	case 37: append("ss");
		return;
	case 38: append("ds");
		return;
	case 39: append("fs");
		return;
	case 40: append("gs");
		return;

	case 41: append("cr3");
		return;

	default: append("[");
		append(reg.name());
		break;
	}

	if (reg.is_virtual()) {
		if (reg.regclass() == X86RegisterClasses::GENERAL_PURPOSE) {
			append("G");
		} else if (reg.regclass() == X86RegisterClasses::SSE) {
			append("S");
		}
		append_dec(reg.unique_index());
	}

	append(":");
	append_dec(width_in_bits);
	append("]");
}
