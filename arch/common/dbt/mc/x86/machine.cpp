/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/machine.h>

using namespace captive::arch::dbt::mc::x86;

// REPRESENTATIONS OF x86 PHYSICAL REGISTERS
const X86PhysicalRegister X86PhysicalRegisters::A(X86RegisterClasses::GENERAL_PURPOSE, 0, 0, "A");
const X86PhysicalRegister X86PhysicalRegisters::C(X86RegisterClasses::GENERAL_PURPOSE, 1, 1, "C");
const X86PhysicalRegister X86PhysicalRegisters::D(X86RegisterClasses::GENERAL_PURPOSE, 2, 2, "D");
const X86PhysicalRegister X86PhysicalRegisters::B(X86RegisterClasses::GENERAL_PURPOSE, 3, 3, "B");
const X86PhysicalRegister X86PhysicalRegisters::SP(X86RegisterClasses::GENERAL_PURPOSE, 4, 4, "SP");
const X86PhysicalRegister X86PhysicalRegisters::BP(X86RegisterClasses::GENERAL_PURPOSE, 5, 5, "BP");
const X86PhysicalRegister X86PhysicalRegisters::SI(X86RegisterClasses::GENERAL_PURPOSE, 6, 6, "SI");
const X86PhysicalRegister X86PhysicalRegisters::DI(X86RegisterClasses::GENERAL_PURPOSE, 7, 7, "DI");
const X86PhysicalRegister X86PhysicalRegisters::R8(X86RegisterClasses::GENERAL_PURPOSE, 8, 0, "R8", true);
const X86PhysicalRegister X86PhysicalRegisters::R9(X86RegisterClasses::GENERAL_PURPOSE, 9, 1, "R9", true);
const X86PhysicalRegister X86PhysicalRegisters::R10(X86RegisterClasses::GENERAL_PURPOSE, 10, 2, "R10", true);
const X86PhysicalRegister X86PhysicalRegisters::R11(X86RegisterClasses::GENERAL_PURPOSE, 11, 3, "R11", true);
const X86PhysicalRegister X86PhysicalRegisters::R12(X86RegisterClasses::GENERAL_PURPOSE, 12, 4, "R12", true);
const X86PhysicalRegister X86PhysicalRegisters::R13(X86RegisterClasses::GENERAL_PURPOSE, 13, 5, "R13", true);
const X86PhysicalRegister X86PhysicalRegisters::R14(X86RegisterClasses::GENERAL_PURPOSE, 14, 6, "R14", true);
const X86PhysicalRegister X86PhysicalRegisters::R15(X86RegisterClasses::GENERAL_PURPOSE, 15, 7, "R15", true);

const X86PhysicalRegister X86PhysicalRegisters::XMM0(X86RegisterClasses::SSE, 16, 0, "XMM0");
const X86PhysicalRegister X86PhysicalRegisters::XMM1(X86RegisterClasses::SSE, 17, 1, "XMM1");
const X86PhysicalRegister X86PhysicalRegisters::XMM2(X86RegisterClasses::SSE, 18, 2, "XMM2");
const X86PhysicalRegister X86PhysicalRegisters::XMM3(X86RegisterClasses::SSE, 19, 3, "XMM3");
const X86PhysicalRegister X86PhysicalRegisters::XMM4(X86RegisterClasses::SSE, 20, 4, "XMM4");
const X86PhysicalRegister X86PhysicalRegisters::XMM5(X86RegisterClasses::SSE, 21, 5, "XMM5");
const X86PhysicalRegister X86PhysicalRegisters::XMM6(X86RegisterClasses::SSE, 22, 6, "XMM6");
const X86PhysicalRegister X86PhysicalRegisters::XMM7(X86RegisterClasses::SSE, 23, 7, "XMM7");
const X86PhysicalRegister X86PhysicalRegisters::XMM8(X86RegisterClasses::SSE, 24, 0, "XMM8", true);
const X86PhysicalRegister X86PhysicalRegisters::XMM9(X86RegisterClasses::SSE, 25, 1, "XMM9", true);
const X86PhysicalRegister X86PhysicalRegisters::XMM10(X86RegisterClasses::SSE, 26, 2, "XMM10", true);
const X86PhysicalRegister X86PhysicalRegisters::XMM11(X86RegisterClasses::SSE, 27, 3, "XMM11", true);
const X86PhysicalRegister X86PhysicalRegisters::XMM12(X86RegisterClasses::SSE, 28, 4, "XMM12", true);
const X86PhysicalRegister X86PhysicalRegisters::XMM13(X86RegisterClasses::SSE, 29, 5, "XMM13", true);
const X86PhysicalRegister X86PhysicalRegisters::XMM14(X86RegisterClasses::SSE, 30, 6, "XMM14", true);
const X86PhysicalRegister X86PhysicalRegisters::XMM15(X86RegisterClasses::SSE, 31, 7, "XMM15", true);

const X86PhysicalRegister X86PhysicalRegisters::RIZ(X86RegisterClasses::ZERO, 32, 5, "RIZ");
const X86PhysicalRegister X86PhysicalRegisters::RIP(X86RegisterClasses::PC, 33, 5, "RIP");
const X86PhysicalRegister X86PhysicalRegisters::RFLAGS(X86RegisterClasses::FLAGS, 34, 0, "RFLAGS");

const X86PhysicalRegister X86PhysicalRegisters::ES(X86RegisterClasses::SEGMENT, 35, 0, "ES");
const X86PhysicalRegister X86PhysicalRegisters::CS(X86RegisterClasses::SEGMENT, 36, 1, "CS");
const X86PhysicalRegister X86PhysicalRegisters::SS(X86RegisterClasses::SEGMENT, 37, 2, "SS");
const X86PhysicalRegister X86PhysicalRegisters::DS(X86RegisterClasses::SEGMENT, 38, 3, "DS");
const X86PhysicalRegister X86PhysicalRegisters::FS(X86RegisterClasses::SEGMENT, 39, 4, "FS");
const X86PhysicalRegister X86PhysicalRegisters::GS(X86RegisterClasses::SEGMENT, 40, 5, "GS");

const X86PhysicalRegister X86PhysicalRegisters::CR3(X86RegisterClasses::CONTROL, 41, 3, "CR3");

// ALIASES FOR THE PHYSICAL REGISTERS

const X86Register X86Registers::AL(X86PhysicalRegisters::A, 8, "al");
const X86Register X86Registers::AX(X86PhysicalRegisters::A, 16, "ax");
const X86Register X86Registers::EAX(X86PhysicalRegisters::A, 32, "eax");
const X86Register X86Registers::RAX(X86PhysicalRegisters::A, 64, "rax");

const X86Register X86Registers::BL(X86PhysicalRegisters::B, 8, "bl");
const X86Register X86Registers::BX(X86PhysicalRegisters::B, 16, "bx");
const X86Register X86Registers::EBX(X86PhysicalRegisters::B, 32, "ebx");
const X86Register X86Registers::RBX(X86PhysicalRegisters::B, 64, "rbx");

const X86Register X86Registers::CL(X86PhysicalRegisters::C, 8, "cl");
const X86Register X86Registers::CX(X86PhysicalRegisters::C, 16, "cx");
const X86Register X86Registers::ECX(X86PhysicalRegisters::C, 32, "ecx");
const X86Register X86Registers::RCX(X86PhysicalRegisters::C, 64, "rcx");

const X86Register X86Registers::DL(X86PhysicalRegisters::D, 8, "dl");
const X86Register X86Registers::DX(X86PhysicalRegisters::D, 16, "dx");
const X86Register X86Registers::EDX(X86PhysicalRegisters::D, 32, "edx");
const X86Register X86Registers::RDX(X86PhysicalRegisters::D, 64, "rdx");

const X86Register X86Registers::SPL(X86PhysicalRegisters::SP, 8, "spl");
const X86Register X86Registers::SP(X86PhysicalRegisters::SP, 16, "sp");
const X86Register X86Registers::ESP(X86PhysicalRegisters::SP, 32, "esp");
const X86Register X86Registers::RSP(X86PhysicalRegisters::SP, 64, "rsp");

const X86Register X86Registers::BPL(X86PhysicalRegisters::BP, 8, "bpl");
const X86Register X86Registers::BP(X86PhysicalRegisters::BP, 16, "bp");
const X86Register X86Registers::EBP(X86PhysicalRegisters::BP, 32, "ebp");
const X86Register X86Registers::RBP(X86PhysicalRegisters::BP, 64, "rbp");

const X86Register X86Registers::SIL(X86PhysicalRegisters::SI, 8, "sil");
const X86Register X86Registers::SI(X86PhysicalRegisters::SI, 16, "si");
const X86Register X86Registers::ESI(X86PhysicalRegisters::SI, 32, "esi");
const X86Register X86Registers::RSI(X86PhysicalRegisters::SI, 64, "rsi");

const X86Register X86Registers::DIL(X86PhysicalRegisters::DI, 8, "dil");
const X86Register X86Registers::DI(X86PhysicalRegisters::DI, 16, "di");
const X86Register X86Registers::EDI(X86PhysicalRegisters::DI, 32, "edi");
const X86Register X86Registers::RDI(X86PhysicalRegisters::DI, 64, "rdi");

const X86Register X86Registers::R8B(X86PhysicalRegisters::R8, 8, "r8b");
const X86Register X86Registers::R8W(X86PhysicalRegisters::R8, 16, "r8w");
const X86Register X86Registers::R8D(X86PhysicalRegisters::R8, 32, "r8d");
const X86Register X86Registers::R8(X86PhysicalRegisters::R8, 64, "r8");
const X86Register X86Registers::R9B(X86PhysicalRegisters::R9, 8, "r9b");
const X86Register X86Registers::R9W(X86PhysicalRegisters::R9, 16, "r9w");
const X86Register X86Registers::R9D(X86PhysicalRegisters::R9, 32, "r9d");
const X86Register X86Registers::R9(X86PhysicalRegisters::R9, 64, "r9");
const X86Register X86Registers::R10B(X86PhysicalRegisters::R10, 8, "r10b");
const X86Register X86Registers::R10W(X86PhysicalRegisters::R10, 16, "r10w");
const X86Register X86Registers::R10D(X86PhysicalRegisters::R10, 32, "r10d");
const X86Register X86Registers::R10(X86PhysicalRegisters::R10, 64, "r10");
const X86Register X86Registers::R11B(X86PhysicalRegisters::R11, 8, "r11b");
const X86Register X86Registers::R11W(X86PhysicalRegisters::R11, 16, "r11w");
const X86Register X86Registers::R11D(X86PhysicalRegisters::R11, 32, "r11d");
const X86Register X86Registers::R11(X86PhysicalRegisters::R11, 64, "r11");
const X86Register X86Registers::R12B(X86PhysicalRegisters::R12, 8, "r12b");
const X86Register X86Registers::R12W(X86PhysicalRegisters::R12, 16, "r12w");
const X86Register X86Registers::R12D(X86PhysicalRegisters::R12, 32, "r12d");
const X86Register X86Registers::R12(X86PhysicalRegisters::R12, 64, "r12");
const X86Register X86Registers::R13B(X86PhysicalRegisters::R13, 8, "r13b");
const X86Register X86Registers::R13W(X86PhysicalRegisters::R13, 16, "r13w");
const X86Register X86Registers::R13D(X86PhysicalRegisters::R13, 32, "r13d");
const X86Register X86Registers::R13(X86PhysicalRegisters::R13, 64, "r13");
const X86Register X86Registers::R14B(X86PhysicalRegisters::R14, 8, "r14b");
const X86Register X86Registers::R14W(X86PhysicalRegisters::R14, 16, "r14w");
const X86Register X86Registers::R14D(X86PhysicalRegisters::R14, 32, "r14d");
const X86Register X86Registers::R14(X86PhysicalRegisters::R14, 64, "r14");
const X86Register X86Registers::R15B(X86PhysicalRegisters::R15, 8, "r15b");
const X86Register X86Registers::R15W(X86PhysicalRegisters::R15, 16, "r15w");
const X86Register X86Registers::R15D(X86PhysicalRegisters::R15, 32, "r15d");
const X86Register X86Registers::R15(X86PhysicalRegisters::R15, 64, "r15");

const X86PhysicalRegister& X86PhysicalRegisters::get_by_unique_index(dbt_u64 unique_index)
{
	switch (unique_index) {
	case 0: return X86PhysicalRegisters::A;
	case 1: return X86PhysicalRegisters::C;
	case 2: return X86PhysicalRegisters::D;
	case 3: return X86PhysicalRegisters::B;
	case 4: return X86PhysicalRegisters::SP;
	case 5: return X86PhysicalRegisters::BP;
	case 6: return X86PhysicalRegisters::SI;
	case 7: return X86PhysicalRegisters::DI;
	case 8: return X86PhysicalRegisters::R8;
	case 9: return X86PhysicalRegisters::R9;
	case 10: return X86PhysicalRegisters::R10;
	case 11: return X86PhysicalRegisters::R11;
	case 12: return X86PhysicalRegisters::R12;
	case 13: return X86PhysicalRegisters::R13;
	case 14: return X86PhysicalRegisters::R14;
	case 15: return X86PhysicalRegisters::R15;

	case 16: return X86PhysicalRegisters::XMM0;
	case 17: return X86PhysicalRegisters::XMM1;
	case 18: return X86PhysicalRegisters::XMM2;
	case 19: return X86PhysicalRegisters::XMM3;
	case 20: return X86PhysicalRegisters::XMM4;
	case 21: return X86PhysicalRegisters::XMM5;
	case 22: return X86PhysicalRegisters::XMM6;
	case 23: return X86PhysicalRegisters::XMM7;
	case 24: return X86PhysicalRegisters::XMM8;
	case 25: return X86PhysicalRegisters::XMM9;
	case 26: return X86PhysicalRegisters::XMM10;
	case 27: return X86PhysicalRegisters::XMM11;
	case 28: return X86PhysicalRegisters::XMM12;
	case 29: return X86PhysicalRegisters::XMM13;
	case 30: return X86PhysicalRegisters::XMM14;
	case 31: return X86PhysicalRegisters::XMM15;

	default: return X86PhysicalRegisters::RIZ;
	}
}

X86PhysicalRegister X86PhysicalRegisters::create_virtual(X86RegisterClasses::X86RegisterClasses regclass, dbt_u32 virtual_id)
{
	return X86PhysicalRegister(regclass, virtual_id, 0, "V", false, true);
}
