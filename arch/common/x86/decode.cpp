/* SPDX-License-Identifier: MIT */

#include <x86/decode.h>
#include <printf.h>

using namespace captive::arch::x86;

const char *captive::arch::x86::x86_register_names[] = {
	"rax", // 0
	"rbx",
	"rcx",
	"rdx",
	"rsp",
	"rbp",
	"rsi",
	"rdi",

	"eax", // 8
	"ebx",
	"ecx",
	"edx",
	"esp",
	"ebp",
	"esi",
	"edi",

	"ax", // 16
	"bx",
	"cx",
	"dx",
	"sp",
	"bp",
	"si",
	"di",

	"ah", // 24
	"bh",
	"ch",
	"dh",
	"al",
	"bl",
	"cl",
	"dl",

	"spl", // 32
	"bpl",
	"sil",
	"dil",

	"r8b", // 36
	"r9b",
	"r10b",
	"r11b",
	"r12b",
	"r13b",
	"r14b",
	"r15b",

	"r8w", // 44
	"r9w",
	"r10w",
	"r11w",
	"r12w",
	"r13w",
	"r14w",
	"r15w",

	"r8d", // 52
	"r9d",
	"r10d",
	"r11d",
	"r12d",
	"r13d",
	"r14d",
	"r15d",

	"r8", // 60
	"r9",
	"r10",
	"r11",
	"r12",
	"r13",
	"r14",
	"r15",

	"riz"
};

enum X86InstructionPrefixes {
	NONE = 0x00,

	ADDRESS_SIZE_OVERRIDE = 0x01,
	OPERAND_SIZE_OVERRIDE = 0x02,

	REX = 0x3c,

	REX_W = 0x04,
	REX_R = 0x08,
	REX_X = 0x10,
	REX_B = 0x20,
};

enum X86OperandTypes {
	O_R8,
	O_R16_32_64,

	O_R_M16_32_64,

	O_R_M8,
	O_R_M16,

	O_IMM16_32,
};

static X86InstructionPrefixes read_prefixes(const uint8_t **code)
{
	X86InstructionPrefixes p = NONE;

	bool prefixes_complete = false;
	while (!prefixes_complete) {
		switch (**code) {
		case 0x67: p = (X86InstructionPrefixes) (p | ADDRESS_SIZE_OVERRIDE);
			break;
		case 0x66: p = (X86InstructionPrefixes) (p | OPERAND_SIZE_OVERRIDE);
			break;

		case 0x40: p = (X86InstructionPrefixes) (p | REX);
			break;
		case 0x41: p = (X86InstructionPrefixes) (p | REX | REX_B);
			break;
		case 0x42: p = (X86InstructionPrefixes) (p | REX | REX_X);
			break;
		case 0x43: p = (X86InstructionPrefixes) (p | REX | REX_X | REX_B);
			break;
		case 0x44: p = (X86InstructionPrefixes) (p | REX | REX_R);
			break;
		case 0x45: p = (X86InstructionPrefixes) (p | REX | REX_R | REX_B);
			break;
		case 0x46: p = (X86InstructionPrefixes) (p | REX | REX_R | REX_X);
			break;
		case 0x47: p = (X86InstructionPrefixes) (p | REX | REX_R | REX_X | REX_B);
			break;
		case 0x48: p = (X86InstructionPrefixes) (p | REX | REX_W);
			break;
		case 0x49: p = (X86InstructionPrefixes) (p | REX | REX_W | REX_B);
			break;
		case 0x4a: p = (X86InstructionPrefixes) (p | REX | REX_W | REX_X);
			break;
		case 0x4b: p = (X86InstructionPrefixes) (p | REX | REX_W | REX_X | REX_B);
			break;
		case 0x4c: p = (X86InstructionPrefixes) (p | REX | REX_W | REX_R);
			break;
		case 0x4d: p = (X86InstructionPrefixes) (p | REX | REX_W | REX_R | REX_B);
			break;
		case 0x4e: p = (X86InstructionPrefixes) (p | REX | REX_W | REX_R | REX_X);
			break;
		case 0x4f: p = (X86InstructionPrefixes) (p | REX | REX_W | REX_R | REX_X | REX_B);
			break;

		case 0xc4: case 0xc5: p = (X86InstructionPrefixes) (p | ADDRESS_SIZE_OVERRIDE);
			break;

		default: prefixes_complete = true;
			continue;
		}

		(*code)++;
	}

	return p;
}

static inline void read_modrm(const uint8_t **code, uint8_t& mod, uint8_t& reg, uint8_t& rm)
{
	uint8_t val = **code;

	mod = (val >> 6) & 3;
	reg = (val >> 3) & 7;
	rm = (val >> 0) & 7;

	(*code)++;
}

static bool decode_reg(X86InstructionPrefixes pfx, Operand& oper, uint8_t& size, uint8_t reg, X86OperandTypes type)
{
	oper.type = Operand::TYPE_REGISTER;

	switch (type) {
	case O_R8:
		if (pfx & REX_R) {
			switch (reg) {
			case 0: oper.reg = Operand::R_R8B;
				break;
			case 1: oper.reg = Operand::R_R9B;
				break;
			case 2: oper.reg = Operand::R_R10B;
				break;
			case 3: oper.reg = Operand::R_R11B;
				break;
			case 4: oper.reg = Operand::R_R12B;
				break;
			case 5: oper.reg = Operand::R_R13B;
				break;
			case 6: oper.reg = Operand::R_R14B;
				break;
			case 7: oper.reg = Operand::R_R15B;
				break;
			default: return false;
			}
		} else {
			switch (reg) {
			case 0: oper.reg = Operand::R_AL;
				break;
			case 1: oper.reg = Operand::R_CL;
				break;
			case 2: oper.reg = Operand::R_DL;
				break;
			case 3: oper.reg = Operand::R_BL;
				break;
			case 4: if (pfx & REX) oper.reg = Operand::R_SPL;
				else oper.reg = Operand::R_AH;
				break;
			case 5: if (pfx & REX) oper.reg = Operand::R_BPL;
				else oper.reg = Operand::R_CH;
				break;
			case 6: if (pfx & REX) oper.reg = Operand::R_SIL;
				else oper.reg = Operand::R_DH;
				break;
			case 7: if (pfx & REX) oper.reg = Operand::R_DIL;
				else oper.reg = Operand::R_BH;
				break;
			default: return false;
			}
		}
		break;

	case O_R16_32_64:
		if (pfx & REX_R) {
			switch (reg) {
			case 0: if (pfx & REX_W) oper.reg = Operand::R_R8;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_R8W;
				else oper.reg = Operand::R_R8D;
				break;
			case 1: if (pfx & REX_W) oper.reg = Operand::R_R9;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_R9W;
				else oper.reg = Operand::R_R9D;
				break;
			case 2: if (pfx & REX_W) oper.reg = Operand::R_R10;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_R10W;
				else oper.reg = Operand::R_R10D;
				break;
			case 3: if (pfx & REX_W) oper.reg = Operand::R_R11;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_R11W;
				else oper.reg = Operand::R_R11D;
				break;
			case 4: if (pfx & REX_W) oper.reg = Operand::R_R12;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_R12W;
				else oper.reg = Operand::R_R12D;
				break;
			case 5: if (pfx & REX_W) oper.reg = Operand::R_R13;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_R13W;
				else oper.reg = Operand::R_R13D;
				break;
			case 6: if (pfx & REX_W) oper.reg = Operand::R_R14;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_R14W;
				else oper.reg = Operand::R_R14D;
				break;
			case 7: if (pfx & REX_W) oper.reg = Operand::R_R15;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_R15W;
				else oper.reg = Operand::R_R15D;
				break;
			default: return false;
			}
		} else {
			switch (reg) {
			case 0: if (pfx & REX_W) oper.reg = Operand::R_RAX;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_AX;
				else oper.reg = Operand::R_EAX;
				break;
			case 1: if (pfx & REX_W) oper.reg = Operand::R_RCX;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_CX;
				else oper.reg = Operand::R_ECX;
				break;
			case 2: if (pfx & REX_W) oper.reg = Operand::R_RDX;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_DX;
				else oper.reg = Operand::R_EDX;
				break;
			case 3: if (pfx & REX_W) oper.reg = Operand::R_RBX;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_BX;
				else oper.reg = Operand::R_EBX;
				break;
			case 4: if (pfx & REX_W) oper.reg = Operand::R_RSP;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_SP;
				else oper.reg = Operand::R_ESP;
				break;
			case 5: if (pfx & REX_W) oper.reg = Operand::R_RBP;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_BP;
				else oper.reg = Operand::R_EBP;
				break;
			case 6: if (pfx & REX_W) oper.reg = Operand::R_RSI;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_SI;
				else oper.reg = Operand::R_ESI;
				break;
			case 7: if (pfx & REX_W) oper.reg = Operand::R_RDI;
				else if (pfx & OPERAND_SIZE_OVERRIDE) oper.reg = Operand::R_DI;
				else oper.reg = Operand::R_EDI;
				break;
			default: return false;
			}
		}

		break;

	default:
		return false;
	}

	switch (oper.reg) {
	case Operand::R_RAX:
	case Operand::R_RBX:
	case Operand::R_RCX:
	case Operand::R_RDX:
	case Operand::R_RSP:
	case Operand::R_RBP:
	case Operand::R_RSI:
	case Operand::R_RDI:
	case Operand::R_R8:
	case Operand::R_R9:
	case Operand::R_R10:
	case Operand::R_R11:
	case Operand::R_R12:
	case Operand::R_R13:
	case Operand::R_R14:
	case Operand::R_R15:
		size = 8;
		break;

	case Operand::R_EAX:
	case Operand::R_EBX:
	case Operand::R_ECX:
	case Operand::R_EDX:
	case Operand::R_ESP:
	case Operand::R_EBP:
	case Operand::R_ESI:
	case Operand::R_EDI:
	case Operand::R_R8D:
	case Operand::R_R9D:
	case Operand::R_R10D:
	case Operand::R_R11D:
	case Operand::R_R12D:
	case Operand::R_R13D:
	case Operand::R_R14D:
	case Operand::R_R15D:
		size = 4;
		break;

	case Operand::R_AX:
	case Operand::R_BX:
	case Operand::R_CX:
	case Operand::R_DX:
	case Operand::R_SP:
	case Operand::R_BP:
	case Operand::R_SI:
	case Operand::R_DI:
	case Operand::R_R8W:
	case Operand::R_R9W:
	case Operand::R_R10W:
	case Operand::R_R11W:
	case Operand::R_R12W:
	case Operand::R_R13W:
	case Operand::R_R14W:
	case Operand::R_R15W:
		size = 2;
		break;

	case Operand::R_AL:
	case Operand::R_BL:
	case Operand::R_CL:
	case Operand::R_DL:
	case Operand::R_AH:
	case Operand::R_BH:
	case Operand::R_CH:
	case Operand::R_DH:
	case Operand::R_SPL:
	case Operand::R_BPL:
	case Operand::R_SIL:
	case Operand::R_DIL:
	case Operand::R_R8B:
	case Operand::R_R9B:
	case Operand::R_R10B:
	case Operand::R_R11B:
	case Operand::R_R12B:
	case Operand::R_R13B:
	case Operand::R_R14B:
	case Operand::R_R15B:
		size = 1;
		break;

	case Operand::R_Z:
		return false;
	}

	return true;
}

static bool decode_rm(const uint8_t **code, X86InstructionPrefixes pfx, Operand& oper, uint8_t mod, uint8_t rm, X86OperandTypes type)
{
	switch (mod) {
	case 0:
		oper.type = Operand::TYPE_MEMORY;
		oper.mem.displacement = 0;
		oper.mem.index_reg_idx = Operand::R_Z;
		oper.mem.scale = 0;

		if (pfx & REX_B) {
			switch (rm) {
			case 0: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R8D;
				else oper.mem.base_reg_idx = Operand::R_R8;
				break;
			case 1: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R9D;
				else oper.mem.base_reg_idx = Operand::R_R9;
				break;
			case 2: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R10D;
				else oper.mem.base_reg_idx = Operand::R_R10;
				break;
			case 3: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R11D;
				else oper.mem.base_reg_idx = Operand::R_R11;
				break;
			case 4: return false;
			case 5: return false;
			case 6: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R14D;
				else oper.mem.base_reg_idx = Operand::R_R14;
				break;
			case 7: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R15D;
				else oper.mem.base_reg_idx = Operand::R_R15;
				break;
			}
		} else {
			switch (rm) {
			case 0: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EAX;
				else oper.mem.base_reg_idx = Operand::R_RAX;
				break;
			case 1: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_ECX;
				else oper.mem.base_reg_idx = Operand::R_RCX;
				break;
			case 2: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EDX;
				else oper.mem.base_reg_idx = Operand::R_RDX;
				break;
			case 3: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EBX;
				else oper.mem.base_reg_idx = Operand::R_RBX;
				break;
			case 4: return false;
			case 5: return false;
			case 6: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_ESI;
				else oper.mem.base_reg_idx = Operand::R_RSI;
				break;
			case 7: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EDI;
				else oper.mem.base_reg_idx = Operand::R_RDI;
				break;
			}
		}

		break;

	case 1:
		oper.type = Operand::TYPE_MEMORY;
		oper.mem.displacement = **code;
		oper.mem.index_reg_idx = Operand::R_Z;
		oper.mem.scale = 0;

		(*code)++;

		if (pfx & REX_B) {
			switch (rm) {
			case 0: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R8D;
				else oper.mem.base_reg_idx = Operand::R_R8;
				break;
			case 1: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R9D;
				else oper.mem.base_reg_idx = Operand::R_R9;
				break;
			case 2: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R10D;
				else oper.mem.base_reg_idx = Operand::R_R10;
				break;
			case 3: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R11D;
				else oper.mem.base_reg_idx = Operand::R_R11;
				break;
			case 4: return false;
			case 5: return false;
			case 6: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R14D;
				else oper.mem.base_reg_idx = Operand::R_R14;
				break;
			case 7: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R15D;
				else oper.mem.base_reg_idx = Operand::R_R15;
				break;
			}
		} else {
			switch (rm) {
			case 0: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EAX;
				else oper.mem.base_reg_idx = Operand::R_RAX;
				break;
			case 1: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_ECX;
				else oper.mem.base_reg_idx = Operand::R_RCX;
				break;
			case 2: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EDX;
				else oper.mem.base_reg_idx = Operand::R_RDX;
				break;
			case 3: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EBX;
				else oper.mem.base_reg_idx = Operand::R_RBX;
				break;
			case 4: return false;
			case 5: return false;
			case 6: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_ESI;
				else oper.mem.base_reg_idx = Operand::R_RSI;
				break;
			case 7: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EDI;
				else oper.mem.base_reg_idx = Operand::R_RDI;
				break;
			}
		}

		break;

	case 2:
		oper.type = Operand::TYPE_MEMORY;

		oper.mem.displacement = *(const int32_t *) (*code);
		oper.mem.index_reg_idx = Operand::R_Z;
		oper.mem.scale = 0;

		*code = *code + 4;

		if (pfx & REX_B) {
			switch (rm) {
			case 0: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R8D;
				else oper.mem.base_reg_idx = Operand::R_R8;
				break;
			case 1: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R9D;
				else oper.mem.base_reg_idx = Operand::R_R9;
				break;
			case 2: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R10D;
				else oper.mem.base_reg_idx = Operand::R_R10;
				break;
			case 3: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R11D;
				else oper.mem.base_reg_idx = Operand::R_R11;
				break;
			case 4: return false;
			case 5: return false;
			case 6: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R14D;
				else oper.mem.base_reg_idx = Operand::R_R14;
				break;
			case 7: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_R15D;
				else oper.mem.base_reg_idx = Operand::R_R15;
				break;
			}
		} else {
			switch (rm) {
			case 0: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EAX;
				else oper.mem.base_reg_idx = Operand::R_RAX;
				break;
			case 1: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_ECX;
				else oper.mem.base_reg_idx = Operand::R_RCX;
				break;
			case 2: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EDX;
				else oper.mem.base_reg_idx = Operand::R_RDX;
				break;
			case 3: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EBX;
				else oper.mem.base_reg_idx = Operand::R_RBX;
				break;
			case 4: return false;
			case 5: return false;
			case 6: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_ESI;
				else oper.mem.base_reg_idx = Operand::R_RSI;
				break;
			case 7: if (pfx & ADDRESS_SIZE_OVERRIDE) oper.mem.base_reg_idx = Operand::R_EDI;
				else oper.mem.base_reg_idx = Operand::R_RDI;
				break;
			}
		}

		break;

	default: return false;
	}

	return true;
}

static bool decode_mov(X86InstructionPrefixes pfx, const uint8_t **code, MemoryInstruction& inst, X86OperandTypes source, X86OperandTypes dest)
{
	inst.type = MemoryInstruction::I_MOV;

	uint8_t mod, reg, rm;
	read_modrm(code, mod, reg, rm);

	switch (source) {
	case O_R16_32_64:
	case O_R8:
		if (!decode_reg(pfx, inst.Source, inst.data_size, reg, source)) return false;
		if (!decode_rm(code, pfx, inst.Dest, mod, rm, dest)) return false;
		return true;

	case O_R_M8:
	case O_R_M16:
	case O_R_M16_32_64:
		if (!decode_reg(pfx, inst.Dest, inst.data_size, reg, dest)) return false;
		if (!decode_rm(code, pfx, inst.Source, mod, rm, source)) return false;
		return true;

	case O_IMM16_32:
		printf("unsupported immediate operand\n");
		return false;

	default:
		return false;
	}
}

static bool decode_movzx_modrm(X86InstructionPrefixes pfx, const uint8_t **code, MemoryInstruction& inst, X86OperandTypes source, X86OperandTypes dest)
{
	inst.type = MemoryInstruction::I_MOVZX;

	uint8_t mod, reg, rm;
	read_modrm(code, mod, reg, rm);

	switch (source) {
	case O_R_M8:
		if (!decode_reg(pfx, inst.Dest, inst.data_size, reg, dest)) return false;
		if (!decode_rm(code, pfx, inst.Source, mod, rm, source)) return false;
		inst.data_size = 1;
		return true;

	case O_R_M16:
		if (!decode_reg(pfx, inst.Dest, inst.data_size, reg, dest)) return false;
		if (!decode_rm(code, pfx, inst.Source, mod, rm, source)) return false;
		inst.data_size = 2;
		return true;

	default:
		return false;
	}
}

static const char *insn_mnemonics[] = {
	"mov",
	"movzx",
};

static const char *reg_names[] = {
	"%rax",
	"%rbx",
	"%rcx",
	"%rdx",
	"%rsp",
	"%rbp",
	"%rsi",
	"%rdi",

	"%eax",
	"%ebx",
	"%ecx",
	"%edx",
	"%esp",
	"%ebp",
	"%esi",
	"%edi",

	"%ax",
	"%bx",
	"%cx",
	"%dx",
	"%sp",
	"%bp",
	"%si",
	"%di",

	"%ah",
	"%bh",
	"%ch",
	"%dh",
	"%al",
	"%bl",
	"%cl",
	"%dl",
	"%spl",
	"%bpl",
	"%sil",
	"%dil",
};

static void print_operand(Operand& oper)
{
	switch (oper.type) {
	case Operand::TYPE_REGISTER:
		printf("%s", reg_names[oper.reg]);
		break;

	case Operand::TYPE_MEMORY:
		if (oper.mem.displacement != 0) {
			printf("%d", oper.mem.displacement);
		}
		printf("(%s)", reg_names[oper.mem.base_reg_idx]);
		break;

	case Operand::TYPE_IMMEDIATE:
		printf("%d", oper.immed_val);
		break;
	}
}

bool captive::arch::x86::decode_memory_instruction(const uint8_t *code, MemoryInstruction& inst)
{
	const uint8_t *base = code;

	// Read Prefixes
	X86InstructionPrefixes p = read_prefixes(&code);

	// Read Opcode
	uint16_t opcode = 0;
	if (*code == 0x0f) {
		opcode |= 0x100;
		code++;
	}

	opcode |= *code++;

	//printf("insn: prefixes = %d, opcode = %d\n", p, opcode);

	switch (opcode) {
	case 0x88: if (!decode_mov(p, &code, inst, O_R8, O_R_M8)) return false;
		else break;
	case 0x89: if (!decode_mov(p, &code, inst, O_R16_32_64, O_R_M16_32_64)) return false;
		else break;
	case 0x8a: if (!decode_mov(p, &code, inst, O_R_M8, O_R8)) return false;
		else break;
	case 0x8b: if (!decode_mov(p, &code, inst, O_R_M16_32_64, O_R16_32_64)) return false;
		else break;
	case 0xc7: if (!decode_mov(p, &code, inst, O_IMM16_32, O_R_M16_32_64)) return false;
		else break;
	case 0x1b6: if (!decode_movzx_modrm(p, &code, inst, O_R_M8, O_R16_32_64)) return false;
		else break;
	case 0x1b7: if (!decode_movzx_modrm(p, &code, inst, O_R_M16, O_R16_32_64)) return false;
		else break;
	default: printf("x86: unsupported opcode %x\n", opcode);
		return false;
	}

	inst.length = (code - base);

	/*printf("*** length=%d: ", inst.length);
	printf("%s ", insn_mnemonics[inst.type]);
	print_operand(inst.Source);
	printf(", ");
	print_operand(inst.Dest);
	printf("\n");*/

	return true;
}

void MemoryInstruction::dump()
{
	switch (type) {
	case I_MOV: printf("mov ");
		break;
	case I_MOVZX: printf("movzx ");
		break;
	default: printf("???");
		break;
	}

	Source.dump();
	printf(", ");
	Dest.dump();

	printf("\n");
}

void Operand::dump()
{
	switch (type) {
	case TYPE_IMMEDIATE: printf("$0x%x", immed_val);
		break;
	case TYPE_REGISTER: printf("%s", reg_names[reg]);
		break;
	case TYPE_MEMORY:
		if (mem.displacement)
			printf("%d", mem.displacement);
		printf("(%s)", reg_names[mem.base_reg_idx]);
		break;
	}
}
