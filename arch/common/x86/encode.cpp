/* SPDX-License-Identifier: MIT */

#include <x86/encode.h>
#include <printf.h>

using namespace captive::arch::x86;

namespace captive {
	namespace arch {
		namespace x86 {
			X86Register REG_RAX("rax", 8, 0), REG_EAX("eax", 4, 0), REG_AX("ax", 2, 0), REG_AL("al", 1, 0), REG_AH("ah", 1, 4);
			X86Register REG_RCX("rcx", 8, 1), REG_ECX("ecx", 4, 1), REG_CX("cx", 2, 1), REG_CL("cl", 1, 1), REG_CH("ch", 1, 5);
			X86Register REG_RDX("rdx", 8, 2), REG_EDX("edx", 4, 2), REG_DX("dx", 2, 2), REG_DL("dl", 1, 2), REG_DH("dh", 1, 6);
			X86Register REG_RBX("rbx", 8, 3), REG_EBX("ebx", 4, 3), REG_BX("bx", 2, 3), REG_BL("bl", 1, 3), REG_BH("bh", 1, 7);
			X86Register REG_RSP("rsp", 8, 4), REG_ESP("esp", 4, 4), REG_SP("sp", 2, 4), REG_SPL("spl", 1, 4, false, true);
			X86Register REG_RBP("rbp", 8, 5), REG_EBP("ebp", 4, 5), REG_BP("bp", 2, 5), REG_BPL("bpl", 1, 5, false, true);
			X86Register REG_RSI("rsi", 8, 6), REG_ESI("esi", 4, 6), REG_SI("si", 2, 6), REG_SIL("sil", 1, 6, false, true);
			X86Register REG_RDI("rdi", 8, 7), REG_EDI("edi", 4, 7), REG_DI("di", 2, 7), REG_DIL("dil", 1, 7, false, true);

			X86Register REG_R8("r8", 8, 0, true), REG_R8D("r8d", 4, 0, true), REG_R8W("r8w", 2, 0, true), REG_R8B("r8b", 1, 0, true);
			X86Register REG_R9("r9", 8, 1, true), REG_R9D("r9d", 4, 1, true), REG_R9W("r9w", 2, 1, true), REG_R9B("r9b", 1, 1, true);
			X86Register REG_R10("r10", 8, 2, true), REG_R10D("r10d", 4, 2, true), REG_R10W("r10w", 2, 2, true), REG_R10B("r10b", 1, 2, true);
			X86Register REG_R11("r11", 8, 3, true), REG_R11D("r11d", 4, 3, true), REG_R11W("r11w", 2, 3, true), REG_R11B("r11b", 1, 3, true);
			X86Register REG_R12("r12", 8, 4, true), REG_R12D("r12d", 4, 4, true), REG_R12W("r12w", 2, 4, true), REG_R12B("r12b", 1, 4, true);
			X86Register REG_R13("r13", 8, 5, true), REG_R13D("r13d", 4, 5, true), REG_R13W("r13w", 2, 5, true), REG_R13B("r13b", 1, 5, true);
			X86Register REG_R14("r14", 8, 6, true), REG_R14D("r14d", 4, 6, true), REG_R14W("r14w", 2, 6, true), REG_R14B("r14b", 1, 6, true);
			X86Register REG_R15("r15", 8, 7, true), REG_R15D("r15d", 4, 7, true), REG_R15W("r15w", 2, 7, true), REG_R15B("r15b", 1, 7, true);

			X86Register REG_RIZ("riz", 0, 8);
			X86Register REG_RIP("rip", 0, 9);

			X86VectorRegister REG_XMM0("xmm0", 16, 0, 0);
			X86VectorRegister REG_XMM1("xmm1", 16, 1, 0);
			X86VectorRegister REG_XMM2("xmm2", 16, 2, 0);
			X86VectorRegister REG_XMM3("xmm3", 16, 3, 0);
			X86VectorRegister REG_XMM4("xmm4", 16, 4, 0);
			X86VectorRegister REG_XMM5("xmm5", 16, 5, 0);
			X86VectorRegister REG_XMM6("xmm6", 16, 6, 0);
			X86VectorRegister REG_XMM7("xmm7", 16, 7, 0);
			X86VectorRegister REG_XMM8("xmm8", 16, 0, 1);
			X86VectorRegister REG_XMM9("xmm9", 16, 1, 1);
			X86VectorRegister REG_XMM10("xmm10", 16, 2, 1);
			X86VectorRegister REG_XMM11("xmm11", 16, 3, 1);
			X86VectorRegister REG_XMM12("xmm12", 16, 4, 1);
			X86VectorRegister REG_XMM13("xmm13", 16, 5, 1);
			X86VectorRegister REG_XMM14("xmm14", 16, 6, 1);
			X86VectorRegister REG_XMM15("xmm15", 16, 7, 1);

			X86SegmentRegister REG_CS("cs", 1), REG_DS("ds", 3), REG_ES("es", 0), REG_FS("fs", 4), REG_GS("gs", 5), REG_SS("ss", 2);
		}
	}
}

#define REX 0x40
#define REX_B 0x41
#define REX_X 0x42
#define REX_R 0x44
#define REX_W 0x48

#define SEG_OVERRIDE_FS  0x64
#define SEG_OVERRIDE_GS  0x65
#define OPER_SIZE_OVERRIDE 0x66
#define ADDR_SIZE_OVERRIDE 0x67

X86Encoder::X86Encoder(malloc::Allocator& allocator) : allocator(allocator), _buffer(NULL), _buffer_size(0), _write_offset(0)
{
}

void X86Encoder::patch8(uint32_t offset, uint8_t val)
{
	uint8_t *ptr = (uint8_t *) & _buffer[offset];
	*ptr = val;
}

void X86Encoder::patch16(uint32_t offset, uint16_t val)
{
	uint16_t *ptr = (uint16_t *) & _buffer[offset];
	*ptr = val;
}

void X86Encoder::patch32(uint32_t offset, uint32_t val)
{
	uint32_t *ptr = (uint32_t *) & _buffer[offset];
	*ptr = val;
}

void X86Encoder::patch64(uint32_t offset, uint64_t val)
{
	uint64_t *ptr = (uint64_t *) & _buffer[offset];
	*ptr = val;
}

void X86Encoder::incq(const X86Memory& loc)
{
	encode_opcode_mod_rm(0xff, 0, 8, loc);
}

void X86Encoder::incb(const X86Memory& loc)
{
	encode_opcode_mod_rm(0xfe, 0, 1, loc);
}

void X86Encoder::incw(const X86Memory& loc)
{
	encode_opcode_mod_rm(0xff, 0, 2, loc);
}

void X86Encoder::push(const X86Register& reg)
{
	if (reg.size == 2 || reg.size == 8) {
		if (reg.size == 16) {
			emit8(0x66);
		}

		if (reg.hireg) {
			encode_rex_prefix(true, false, false, false);
		}

		emit8(0x50 + reg.raw_index);
	} else {
		assert(false);
	}
}

void X86Encoder::pushf()
{
	emit8(0x9c);
}

void X86Encoder::popf()
{
	emit8(0x9d);
}

void X86Encoder::push(uint32_t imm)
{
	emit8(0x68);
	emit32(imm);
}

void X86Encoder::pop(const X86Register& reg)
{
	if (reg.size == 2 || reg.size == 8) {
		if (reg.size == 2) {
			emit8(0x66);
		}

		if (reg.hireg) {
			encode_rex_prefix(true, false, false, false);
		}

		emit8(0x58 + reg.raw_index);
	} else {
		printf("*** pop of wrong size for reg %s\n", reg.name);
		assert(false);
	}
}

void X86Encoder::wbinvd()
{
	emit8(0x0f);
	emit8(0x09);
}

void X86Encoder::invlpg(const X86Memory& addr)
{
	encode_opcode_mod_rm(0x101, 7, 8, addr);
}

void X86Encoder::lea(const X86Memory& addr, const X86Register& dst)
{
	encode_opcode_mod_rm(0x8d, dst, addr);
}

void X86Encoder::mov(const X86SegmentRegister& src, const X86Register& dst)
{
	encode_opcode_mod_rm(0x8c, src.raw_index, dst);
}

void X86Encoder::mov(const X86Register& src, const X86Register& dst)
{
	assert(src.size == dst.size);

	if (src.size == 1) {
		encode_opcode_mod_rm(0x88, src, dst);
	} else {
		encode_opcode_mod_rm(0x89, src, dst);
	}
}

void X86Encoder::mov(const X86Memory& src, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0x8a, dst, src);
	} else {
		encode_opcode_mod_rm(0x8b, dst, src);
	}
}

void X86Encoder::mov(const X86Register& src, const X86Memory& dst)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x88, src, dst);
	} else {
		encode_opcode_mod_rm(0x89, src, dst);
	}
}

void X86Encoder::mov(uint64_t src, const X86Register& dst)
{
	if (dst.size == 1) {
		uint8_t rex = 0;

		if (dst.newreg) {
			rex |= REX;
		} else if (dst.hireg) {
			rex |= REX_B;
		}

		if (rex) emit8(rex);

		emit8(0xb0 + dst.raw_index);
		emit8(src);
	} else {
		uint8_t rex = 0;

		uint8_t size = dst.size;
		if (size == 8 && src < 0x80000000) size = 4;

		if (dst.hireg) {
			rex |= REX_B;
		}

		if (size == 8) {
			rex |= REX_W;
		}

		if (size == 2) {
			emit8(OPER_SIZE_OVERRIDE);
		}

		if (rex) emit8(rex);

		emit8(0xb8 + dst.raw_index);


		switch (size) {
		case 8: emit64(src);
			break;
		case 4: emit32(src);
			break;
		case 2: emit16(src);
			break;
		}
	}
}

void X86Encoder::mov8(uint64_t src, const X86Memory& dst)
{
	assert(false);
}

void X86Encoder::mov4(uint32_t src, const X86Memory& dst)
{
	encode_opcode_mod_rm(0xc7, 0, 4, dst);
	emit32(src);
}

void X86Encoder::mov2(uint16_t src, const X86Memory& dst)
{
	encode_opcode_mod_rm(0xc7, 0, 2, dst);
	emit16(src);
}

void X86Encoder::mov1(uint8_t src, const X86Memory& dst)
{
	encode_opcode_mod_rm(0xc6, 0, 1, dst);
	emit8(src);
}

void X86Encoder::movzx(const X86Register& src, const X86Register& dst)
{
	assert(src.size < dst.size);
	assert(src.size == 1 || src.size == 2);
	assert(dst.size == 2 || dst.size == 4 || dst.size == 8);

	if (src.size == 1) {
		encode_opcode_mod_rm(0x1b6, dst, src);
	} else if (src.size == 2) {
		encode_opcode_mod_rm(0x1b7, dst, src);
	}
}

void X86Encoder::movsx(const X86Register& src, const X86Register& dst)
{
	assert(src.size < dst.size);
	assert(src.size == 1 || src.size == 2 || src.size == 4);
	assert(dst.size == 2 || dst.size == 4 || dst.size == 8);

	if (src.size == 1) {
		encode_opcode_mod_rm(0x1be, dst, src);
	} else if (src.size == 2) {
		encode_opcode_mod_rm(0x1bf, dst, src);
	} else if (src.size == 4) {
		assert(dst.size == 8);
		encode_opcode_mod_rm(0x63, dst, src);
	}
}

void X86Encoder::movq(const X86Register &src, const X86VectorRegister &dst)
{

	//Only support moving quad to quad at the moment
	assert(src.size == 8);

	if (dst.size == 16) {
		emit8(0x66);
	}

	uint8_t rex = 0x48;
	// Emit REX byte ourselves here
	if (src.hireg) rex |= 1;
	if (dst.hireg) rex |= 4;

	emit8(rex);
	emit8(0x0f);
	emit8(0x6e);

	encode_mod_reg_rm(dst.raw_index, src);

}

void X86Encoder::movq(const X86VectorRegister &src, const X86Register &dst)
{
	//Only support moving quad to quad at the moment
	assert(dst.size == 8);

	if (src.size == 16) {
		emit8(0x66);
	}

	uint8_t rex = 0x48;
	// Emit REX byte ourselves here
	if (dst.hireg) rex |= 1;
	if (src.hireg) rex |= 4;

	emit8(rex);
	emit8(0x0f);
	emit8(0x7e);
	encode_mod_reg_rm(src.raw_index, dst);
}

void X86Encoder::xchg(const X86Register& a, const X86Register& b)
{
	assert(a.size == b.size);

	if (a.size == 1) {
		encode_opcode_mod_rm(0x86, a, b);
	} else {
		encode_opcode_mod_rm(0x87, a, b);
	}
}

void X86Encoder::xchg(const X86Memory& a, const X86Register& b)
{
	if (b.size == 1) {
		encode_opcode_mod_rm(0x86, b, a);
	} else {
		encode_opcode_mod_rm(0x87, b, a);
	}
}

void X86Encoder::cmpxchg(const X86Register& src, const X86Memory& dst)
{
	emit8(0xf0);

	if (src.size == 1) {
		encode_opcode_mod_rm(0x1b0, src, dst);
	} else {
		encode_opcode_mod_rm(0x1b1, src, dst);
	}
}

void X86Encoder::cbtw()
{
	emit8(0x66);
	emit8(0x98);
}

void X86Encoder::cwtl()
{
	emit8(0x98);
}

void X86Encoder::cltq()
{
	emit8(0x48);
	emit8(0x98);
}

void X86Encoder::cltd()
{
	emit8(0x99);
}

void X86Encoder::cqto()
{
	emit8(0x48);
	emit8(0x99);
}

void X86Encoder::nott(const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0xf6, 2, dst);
	} else {
		encode_opcode_mod_rm(0xf7, 2, dst);
	}
}

void X86Encoder::nott(const X86Memory& dst)
{
	assert(false);
}

void X86Encoder::andd(uint32_t val, uint8_t size, const X86Memory& dst)
{
	encode_arithmetic(4, val, size, dst);
}

void X86Encoder::andd(uint32_t val, const X86Register& dst)
{
	encode_arithmetic(4, val, dst);
}

void X86Encoder::andd(const X86Register& src, const X86Register& dest)
{
	assert(src.size == dest.size);

	if (src.size == 1) {
		encode_opcode_mod_rm(0x20, src, dest);
	} else {
		encode_opcode_mod_rm(0x21, src, dest);
	}
}

void X86Encoder::andd(const X86Register& src, const X86Memory& dest)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x20, src, dest);
	} else {
		encode_opcode_mod_rm(0x21, src, dest);
	}
}

void X86Encoder::andd(const X86Memory& src, const X86Register& dest)
{
	if (dest.size == 1) {
		encode_opcode_mod_rm(0x22, dest, src);
	} else {
		encode_opcode_mod_rm(0x23, dest, src);
	}
}

void X86Encoder::orr(uint32_t val, uint8_t size, const X86Memory& dst)
{
	encode_arithmetic(1, val, size, dst);
}

void X86Encoder::orr(uint32_t val, const X86Register& dst)
{
	encode_arithmetic(1, val, dst);
}

void X86Encoder::orr(const X86Register& src, const X86Register& dest)
{
	assert(src.size == dest.size);

	if (src.size == 1) {
		encode_opcode_mod_rm(0x08, src, dest);
	} else {
		encode_opcode_mod_rm(0x09, src, dest);
	}
}

void X86Encoder::orr(const X86Register& src, const X86Memory& dest)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x08, src, dest);
	} else {
		encode_opcode_mod_rm(0x09, src, dest);
	}
}

void X86Encoder::orr(const X86Memory& src, const X86Register& dest)
{
	if (dest.size == 1) {
		encode_opcode_mod_rm(0x0a, dest, src);
	} else {
		encode_opcode_mod_rm(0x0b, dest, src);
	}
}

void X86Encoder::xorr(uint32_t val, uint8_t size, const X86Memory& dst)
{
	encode_arithmetic(6, val, size, dst);
}

void X86Encoder::xorr(uint32_t val, const X86Register& dst)
{
	if (dst.raw_index == 0 && !dst.hireg) {
		if (dst.size == 1) {
			emit8(0x34);
			emit8(val);
		} else {
			emit8(0x35);
			emit32(val);
		}
	} else {
		encode_arithmetic(6, val, dst);
	}
}

void X86Encoder::xorr(const X86Register& src, const X86Register& dest)
{
	assert(src.size == dest.size);

	if (src.size == 1) {
		encode_opcode_mod_rm(0x30, src, dest);
	} else {
		encode_opcode_mod_rm(0x31, src, dest);
	}
}

void X86Encoder::xorr(const X86Register& src, const X86Memory& dest)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x30, src, dest);
	} else {
		encode_opcode_mod_rm(0x31, src, dest);
	}
}

void X86Encoder::xorr(const X86Memory& src, const X86Register& dest)
{
	if (dest.size == 1) {
		encode_opcode_mod_rm(0x32, dest, src);
	} else {
		encode_opcode_mod_rm(0x33, dest, src);
	}
}

void X86Encoder::shl(uint8_t amount, uint8_t dstsize, const X86Memory& dst)
{
	if (dstsize == 1) {
		encode_opcode_mod_rm(0xc0, 4, dstsize, dst);
		emit8(amount);
	} else {
		encode_opcode_mod_rm(0xc1, 4, dstsize, dst);
		emit8(amount);
	}
}

void X86Encoder::shr(uint8_t amount, uint8_t dstsize, const X86Memory& dst)
{
	if (dstsize == 1) {
		encode_opcode_mod_rm(0xc0, 5, dstsize, dst);
		emit8(amount);
	} else {
		encode_opcode_mod_rm(0xc1, 5, dstsize, dst);
		emit8(amount);
	}
}

void X86Encoder::sar(uint8_t amount, uint8_t dstsize, const X86Memory& dst)
{
	if (dstsize == 1) {
		encode_opcode_mod_rm(0xc0, 7, dstsize, dst);
		emit8(amount);
	} else {
		encode_opcode_mod_rm(0xc1, 7, dstsize, dst);
		emit8(amount);
	}
}

void X86Encoder::rol(uint8_t amount, uint8_t dstsize, const X86Memory& dst)
{
	if (dstsize == 1) {
		encode_opcode_mod_rm(0xc0, 0, dstsize, dst);
		emit8(amount);
	} else {
		encode_opcode_mod_rm(0xc1, 0, dstsize, dst);
		emit8(amount);
	}
}

void X86Encoder::ror(uint8_t amount, uint8_t dstsize, const X86Memory& dst)
{
	if (dstsize == 1) {
		encode_opcode_mod_rm(0xc0, 1, dstsize, dst);
		emit8(amount);
	} else {
		encode_opcode_mod_rm(0xc1, 1, dstsize, dst);
		emit8(amount);
	}
}

void X86Encoder::shl(uint8_t amount, const X86Register& dst)
{
	if (dst.size == 1) {
		if (amount == 1) {
			encode_opcode_mod_rm(0xd0, 4, dst);
		} else {
			encode_opcode_mod_rm(0xc0, 4, dst);
			emit8(amount);
		}
	} else {
		if (amount == 1) {
			encode_opcode_mod_rm(0xd1, 4, dst);
		} else {
			encode_opcode_mod_rm(0xc1, 4, dst);
			emit8(amount);
		}
	}
}

void X86Encoder::shr(uint8_t amount, const X86Register& dst)
{
	if (dst.size == 1) {
		if (amount == 1) {
			encode_opcode_mod_rm(0xd0, 5, dst);
		} else {
			encode_opcode_mod_rm(0xc0, 5, dst);
			emit8(amount);
		}
	} else {
		if (amount == 1) {
			encode_opcode_mod_rm(0xd1, 5, dst);
		} else {
			encode_opcode_mod_rm(0xc1, 5, dst);
			emit8(amount);
		}
	}
}

void X86Encoder::sar(uint8_t amount, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0xc0, 7, dst);
		emit8(amount);
	} else {
		encode_opcode_mod_rm(0xc1, 7, dst);
		emit8(amount);
	}
}

void X86Encoder::rol(uint8_t amount, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0xc0, 0, dst);
		emit8(amount);
	} else {
		encode_opcode_mod_rm(0xc1, 0, dst);
		emit8(amount);
	}
}

void X86Encoder::ror(uint8_t amount, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0xc0, 1, dst);
		emit8(amount);
	} else {
		encode_opcode_mod_rm(0xc1, 1, dst);
		emit8(amount);
	}
}

void X86Encoder::shl(const X86Register& amount, const X86Register& dst)
{
	assert(amount == REG_CL);

	if (dst.size == 1) {
		encode_opcode_mod_rm(0xd2, 4, dst);
	} else {
		encode_opcode_mod_rm(0xd3, 4, dst);
	}
}

void X86Encoder::shr(const X86Register& amount, const X86Register& dst)
{
	assert(amount == REG_CL);

	if (dst.size == 1) {
		encode_opcode_mod_rm(0xd2, 5, dst);
	} else {
		encode_opcode_mod_rm(0xd3, 5, dst);
	}
}

void X86Encoder::sar(const X86Register& amount, const X86Register& dst)
{
	assert(amount == REG_CL);

	if (dst.size == 1) {
		encode_opcode_mod_rm(0xd2, 7, dst);
	} else {
		encode_opcode_mod_rm(0xd3, 7, dst);
	}
}

void X86Encoder::rol(const X86Register& amount, const X86Register& dst)
{
	assert(amount == REG_CL);

	if (dst.size == 1) {
		encode_opcode_mod_rm(0xd2, 0, dst);
	} else {
		encode_opcode_mod_rm(0xd3, 0, dst);
	}
}

void X86Encoder::ror(const X86Register& amount, const X86Register& dst)
{
	assert(amount == REG_CL);

	if (dst.size == 1) {
		encode_opcode_mod_rm(0xd2, 1, dst);
	} else {
		encode_opcode_mod_rm(0xd3, 1, dst);
	}
}

void X86Encoder::bswap(const X86Register& reg)
{
	if (reg.size == 4 || reg.size == 8) {
		if (reg.hireg || reg.size == 8) {
			encode_rex_prefix(reg.hireg, false, false, reg.size == 8);
		}

		emit8(0x0f);
		emit8(0xc8 + reg.raw_index);
	} else {
		assert(false);
	}
}

void X86Encoder::adc(uint32_t src, const X86Register& dst)
{
	encode_arithmetic(2, src, dst);
}

void X86Encoder::adc(const X86Memory &src, const X86Register &dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0x12, dst, src);
	} else {
		encode_opcode_mod_rm(0x13, dst, src);
	}
}

void X86Encoder::adc(const X86Register &src, const X86Memory &dst)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x10, src, dst);
	} else {
		encode_opcode_mod_rm(0x11, src, dst);
	}
}

void X86Encoder::adc(const X86Register& src, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0x10, src, dst);
	} else {
		encode_opcode_mod_rm(0x11, src, dst);
	}
}

void X86Encoder::sbb(uint32_t src, const X86Register& dst)
{
	encode_arithmetic(3, src, dst);
}

void X86Encoder::sbb(const X86Memory &src, const X86Register &dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0x1a, dst, src);
	} else {
		encode_opcode_mod_rm(0x1b, dst, src);
	}
}

void X86Encoder::sbb(const X86Register &src, const X86Memory &dst)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x18, src, dst);
	} else {
		encode_opcode_mod_rm(0x19, src, dst);
	}
}

void X86Encoder::sbb(const X86Register& src, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0x18, src, dst);
	} else {
		encode_opcode_mod_rm(0x19, src, dst);
	}
}

void X86Encoder::add(const X86Register& src, const X86Register& dst)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x0, src, dst);
	} else {
		encode_opcode_mod_rm(0x1, src, dst);
	}
}

void X86Encoder::add(const X86Memory& src, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0x2, dst, src);
	} else {
		encode_opcode_mod_rm(0x3, dst, src);
	}
}

void X86Encoder::add(uint32_t val, const X86Register& dst)
{
	encode_arithmetic(0, val, dst);
}

void X86Encoder::add(const X86Register& src, const X86Memory& dst)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x0, src, dst);
	} else {
		encode_opcode_mod_rm(0x1, src, dst);
	}
}

void X86Encoder::add(uint32_t val, uint8_t size, const X86Memory& dst)
{
	if (val < 127) {
		encode_opcode_mod_rm(0x83, 0, size, dst);
		emit8(val);
	} else {
		encode_opcode_mod_rm(0x81, 0, size, dst);
		emit32(val);
	}
}

void X86Encoder::add1(uint8_t val, const X86Memory& dst)
{
	encode_opcode_mod_rm(0x80, 0, 4, dst);
	emit8(val);
}

void X86Encoder::add2(uint16_t val, const X86Memory& dst)
{
	emit8(0x66);

	if (val < 127) {
		encode_opcode_mod_rm(0x83, 0, 4, dst);
		emit8(val);
	} else {
		encode_opcode_mod_rm(0x81, 0, 4, dst);
		emit32(val);
	}
}

void X86Encoder::add4(uint32_t val, const X86Memory& dst)
{
	if (val < 127) {
		encode_opcode_mod_rm(0x83, 0, 4, dst);
		emit8(val);
	} else {
		encode_opcode_mod_rm(0x81, 0, 4, dst);
		emit32(val);
	}
}

void X86Encoder::add8(uint32_t val, const X86Memory& dst)
{
	if (val < 127) {
		encode_opcode_mod_rm(0x83, 0, 8, dst);
		emit8(val);
	} else {
		encode_opcode_mod_rm(0x81, 0, 8, dst);
		emit32(val);
	}
}

void X86Encoder::sub(const X86Register& src, const X86Register& dst)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x28, src, dst);
	} else {
		encode_opcode_mod_rm(0x29, src, dst);
	}
}

void X86Encoder::sub(const X86Memory& src, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0x2a, dst, src);
	} else {
		encode_opcode_mod_rm(0x2b, dst, src);
	}
}

void X86Encoder::sub(const X86Register& src, const X86Memory& dst)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x28, src, dst);
	} else {
		encode_opcode_mod_rm(0x29, src, dst);
	}
}

void X86Encoder::sub(uint32_t val, const X86Register& dst)
{
	encode_arithmetic(5, val, dst);
}

void X86Encoder::sub(uint32_t val, uint8_t size, const X86Memory& dst)
{
	if (val < 127) {
		encode_opcode_mod_rm(0x83, 5, size, dst);
		emit8(val);
	} else {
		encode_opcode_mod_rm(0x81, 5, size, dst);
		emit32(val);
	}
}

void X86Encoder::mul(const X86Register& src, const X86Register& dst)
{
	assert(src.size == dst.size);

	encode_opcode_mod_rm(0x1af, dst, src);
}

void X86Encoder::imul(const X86Register& multiplier)
{
	assert(multiplier.size != 1);

	encode_opcode_mod_rm(0xf7, 5, multiplier);
}

void X86Encoder::mul(const X86Register& multiplier)
{
	assert(multiplier.size != 1);

	encode_opcode_mod_rm(0xf7, 4, multiplier);
}

void X86Encoder::div(const X86Register& divisor)
{
	assert(divisor.size != 1);

	encode_opcode_mod_rm(0xf7, 6, divisor);
}

void X86Encoder::idiv(const X86Register& divisor)
{
	assert(divisor.size != 1);

	encode_opcode_mod_rm(0xf7, 7, divisor);
}

void X86Encoder::cmp(const X86Register& src, const X86Register& dst)
{
	assert(src.size == dst.size);

	if (src.size == 1) {
		encode_opcode_mod_rm(0x38, src, dst);
	} else {
		encode_opcode_mod_rm(0x39, src, dst);
	}
}

void X86Encoder::cmp(const X86Register& src, const X86Memory& dst)
{
	if (src.size == 1) {
		encode_opcode_mod_rm(0x38, src, dst);
	} else {
		encode_opcode_mod_rm(0x39, src, dst);
	}
}

void X86Encoder::cmp(uint32_t val, const X86Register& dst)
{
	if (val == 0) {
		if (dst.size == 1) {
			encode_opcode_mod_rm(0x84, dst, dst);
		} else {
			encode_opcode_mod_rm(0x85, dst, dst);
		}
	} else {
		encode_arithmetic(7, val, dst);
	}
}

void X86Encoder::cmp1(uint8_t val, const X86Memory& dst)
{
	encode_arithmetic(7, val, 1, dst);
}

void X86Encoder::cmp2(uint16_t val, const X86Memory& dst)
{
	assert(false);
}

void X86Encoder::cmp4(uint32_t val, const X86Memory& dst)
{
	encode_arithmetic(7, val, 4, dst);
}

void X86Encoder::cmp8(uint32_t val, const X86Memory& dst)
{
	if (val < 0x80) {
		encode_opcode_mod_rm(0x83, 7, 8, dst);
		emit8(val & 0xff);
	} else {
		assert(false);
	}
}

void X86Encoder::encode_arithmetic(uint8_t oper, uint32_t imm, const X86Register& dst)
{
	if (dst.size == 1) {
		encode_opcode_mod_rm(0x80, oper, dst);
		emit8(imm);
	} else {
		if (imm < 128) {
			encode_opcode_mod_rm(0x83, oper, dst);
			emit8(imm);
		} else if (((int32_t) imm < 0) && ((int32_t) imm > -127)) {
			encode_opcode_mod_rm(0x83, oper, dst);
			emit8(imm & 0xff);
		} else {
			encode_opcode_mod_rm(0x81, oper, dst);

			if (dst.size == 4 || dst.size == 8) {
				emit32(imm);
			} else if (dst.size == 2) {
				emit16(imm);
			}
		}
	}
}

void X86Encoder::encode_arithmetic(uint8_t oper, uint32_t imm, uint8_t size, const X86Memory& dst)
{
	if (size == 1) {
		encode_opcode_mod_rm(0x80, oper, size, dst);
		emit8(imm);
	} else {
		if (imm < 128) {
			encode_opcode_mod_rm(0x83, oper, size, dst);
			emit8(imm);
		} else {
			encode_opcode_mod_rm(0x81, oper, size, dst);

			if (size == 4 || size == 8) {
				emit32(imm);
			} else if (size == 2) {
				emit16(imm);
			}
		}
	}
}

void X86Encoder::test(uint64_t v, const X86Register& op)
{
	if (op.size == 1) {
		encode_opcode_mod_rm(0xf6, 0, op);
	} else {
		encode_opcode_mod_rm(0xf7, 0, op);
	}

	switch (op.size) {
	case 1: emit8(v);
		break;
	case 2: emit16(v);
		break;
	case 4: emit32(v);
		break;
	case 8: emit64(v);
		break;
	default: assert(false);
	}
}

void X86Encoder::test(const X86Register& op1, const X86Register& op2)
{
	assert(op1.size == op2.size);

	if (op1.size == 1) {
		encode_opcode_mod_rm(0x84, op2, op1);
	} else {
		encode_opcode_mod_rm(0x85, op2, op1);
	}
}

void X86Encoder::test(const X86Register& op1, const X86Memory& op2)
{
	if (op1.size == 1) {
		encode_opcode_mod_rm(0x84, op1, op2);
	} else {
		encode_opcode_mod_rm(0x85, op1, op2);
	}
}

void X86Encoder::call(const X86Register& reg)
{
	if (reg.hireg) {
		emit8(0x41);
	}

	emit8(0xff);
	encode_mod_reg_rm(REG_RDX, reg);
}

void X86Encoder::lcall(const X86Memory& mem)
{
	encode_opcode_mod_rm(0xff, 3, 8, mem);
}

void X86Encoder::jmp(const X86Register& tgt)
{
	emit8(0xff);
	encode_mod_reg_rm(4, tgt);
}

void X86Encoder::jmp(const X86Memory& tgt)
{
	emit8(0xff);
	encode_mod_reg_rm(4, tgt);
}

void X86Encoder::jmp_offset(int32_t offset)
{
	emit8(0xe9);
	emit32(offset);
}

void X86Encoder::jmp_reloc(uint32_t& reloc_offset)
{
	emit8(0xe9);
	reloc_offset = _write_offset;
	emit32(0);
}

void X86Encoder::jcc_reloc(uint8_t v, uint32_t& reloc_offset)
{
	emit8(0x0f);
	emit8(0x80 | (v & 0xf));
	reloc_offset = _write_offset;
	emit32(0);
}

void X86Encoder::jcc(uint8_t v, int8_t off)
{
	emit8(0x70 | (v & 0xf));
	emit8(off);
}

void X86Encoder::jcc(uint8_t v, int32_t off)
{
	emit8(0x0f);
	emit8(0x80 | (v & 0xf));
	emit32(off);
}

void X86Encoder::setcc(uint8_t v, const X86Register& dst)
{
	assert(dst.size == 1);

	if (dst.newreg) emit8(REX);
	else if (dst.hireg) emit8(REX_B);

	emit8(0x0f);
	emit8(0x90 | (v & 0xf));
	encode_mod_reg_rm(0, dst);
}

void X86Encoder::setcc(uint8_t v, const X86Memory& dst)
{
	emit8(0x0f);
	emit8(0x90 | (v & 0xf));
	encode_mod_reg_rm(0, dst);
}

void X86Encoder::cmov(uint8_t code, const X86Register &src, const X86Register &dst)
{
	encode_opcode_mod_rm(0x140 | code, dst, src);
}

void X86Encoder::lahf()
{
	emit8(0x9f);
}

void X86Encoder::stc()
{
	emit8(0xf9);
}

void X86Encoder::clc()
{
	emit8(0xf8);
}

void X86Encoder::cmc()
{
	emit8(0xf5);
}

void X86Encoder::cli()
{
	emit8(0xfa);
}

void X86Encoder::sti()
{
	emit8(0xfb);
}

void X86Encoder::bsr(const X86Register& src, const X86Register& dst)
{
	assert(src.size == dst.size);
	encode_opcode_mod_rm(0x1bd, dst, src);
}

void X86Encoder::ret()
{
	emit8(0xc3);
}

void X86Encoder::movcs(const X86Register& dst)
{
	assert(dst.size == 2);

	emit8(0x66);
	emit8(0x8c);
	encode_mod_reg_rm(1, dst);
}

void X86Encoder::sysenter()
{
	emit8(0x0f);
	emit8(0x34);
}

void X86Encoder::syscall()
{
	emit8(0x0f);
	emit8(0x05);
}

void X86Encoder::sysret()
{
	emit8(0x0f);
	emit8(0x07);
}

void X86Encoder::sysretq()
{
	emit8(0x48);
	emit8(0x0f);
	emit8(0x07);
}

void X86Encoder::int3()
{
	emit8(0xcc);
}

void X86Encoder::intt(uint8_t irq)
{
	emit8(0xcd);
	emit8(irq);
}

void X86Encoder::out(const X86Register& val, const X86Register& port)
{
	assert(port == REG_DX && ((val == REG_AL) || (val == REG_AX) || (val == REG_EAX)));

	if (val == REG_AL) {
		emit8(0xee);
	} else if (val == REG_AX) {
		emit8(0x66);
		emit8(0xef);
	} else {
		emit8(0xef);
	}
}

void X86Encoder::out(const X86Register& val, uint8_t port)
{
	assert((val == REG_AL) || (val == REG_AX) || (val == REG_EAX));

	if (val == REG_AL) {
		emit8(0xe6);
	} else if (val == REG_AX) {
		emit8(0x66);
		emit8(0xe7);
	} else {
		emit8(0xe7);
	}

	emit8(port);
}

void X86Encoder::leave()
{
	emit8(0xc9);
}

void X86Encoder::hlt()
{
	emit8(0xf4);
}

void X86Encoder::nop()
{
	emit8(0x90);
}

void X86Encoder::nop(uint8_t bytes)
{
	while (bytes >= 7) {
		// 1 byte address override, 2 byte opcode, 4 byte immediate
		lea(X86Memory(REG_EAX, 0x80808080), REG_EAX);
		bytes -= 7;
	}

	while (bytes >= 6) {
		// 2 byte opcode, 4 byte immediate
		lea(X86Memory(REG_RAX, 0x80808080), REG_EAX);
		bytes -= 6;
	}

	while (bytes >= 3) {
		// 1 byte address override, 2 byte opcode
		lea(X86Memory(REG_EAX), REG_EAX);
		bytes -= 3;
	}

	while (bytes >= 2) {
		// 1 byte override, 1 byte opcode
		emit8(0x66);
		emit8(0x90);
		bytes -= 2;
	}

	while (bytes) {
		nop();
		bytes--;
	}
}

void X86Encoder::align_up(uint8_t amount)
{
	if ((_write_offset & (amount - 1)) == 0) return;
	uint32_t align_end = (_write_offset + amount) & ~(amount - 1);
	nop(align_end - _write_offset);
}

void X86Encoder::nop(const X86Memory& mem)
{
	emit8(0x0f);
	emit8(0x1f);
	encode_mod_reg_rm(0, mem);
}

void X86Encoder::encode_rex_prefix(bool b, bool x, bool r, bool w)
{
	uint8_t rex = 0x40;

	if (b) rex |= 1;
	if (x) rex |= 2;
	if (r) rex |= 4;
	if (w) rex |= 8;

	emit8(rex);
}

void X86Encoder::encode_mod_reg_rm(uint8_t mreg, const X86Register& rm)
{
	uint8_t mod, mrm;

	mod = 3;
	mrm = rm.raw_index;

	uint8_t byte = (mod & 3) << 6 | (mreg & 7) << 3 | (mrm & 7);
	emit8(byte);
}

void X86Encoder::encode_mod_reg_rm(const X86Register& reg, const X86Register& rm)
{
	encode_mod_reg_rm(reg.raw_index, rm);
}

void X86Encoder::encode_mod_reg_rm(uint8_t mreg, const X86Memory& rm)
{
	uint8_t mod, mrm;

	if (rm.displacement == 0 || (rm.base == REG_RIZ && rm.index == REG_RIZ) || (rm.base == REG_RIP)) {
		mod = 0;
	} else if (rm.displacement < 128 && rm.displacement > -127) {
		mod = 1;
	} else {
		mod = 2;
	}

	if (rm.base == REG_RSP) {
		mrm = 4; // Need a SIB byte
	} else if (rm.base == REG_R12 || rm.base == REG_R12D) {
		mrm = 4; // Need a SIB byte
	} else if (rm.base == REG_RIP) {
		mrm = 5;
	} else if (rm.base == REG_RIZ) {
		mrm = 4; // Need a SIB byte
	} else if (rm.scale != 0) {
		mrm = 4; // Need a SIB byte
	} else {
		mrm = rm.base.raw_index;
	}

	if (mod == 0 && (rm.base == REG_RBP || rm.base == REG_EBP)) {
		mod = 1;
	} else if (mod == 0 && (rm.base == REG_R13 || rm.base == REG_R13D)) {
		mod = 1;
	}

	// Emit the MODRM byte
	emit8((mod & 3) << 6 | (mreg & 7) << 3 | (mrm & 7));

	// Determine if we need to emit a SIB byte (mod cannot be 3 here)
	if (mrm == 4) {
		uint8_t s, i, b;

		if (rm.scale == 0) {
			if (rm.base == REG_RIZ) {
				s = 0;
				i = 4;
				b = 5;
			} else if (rm.base.raw_index == 5) {
				fatal("invalid encoding\n");
			} else {
				s = 0;
				i = 4;
				b = rm.base.raw_index;
			}
		} else {
			switch (rm.scale) {
			case 1: s = 0;
				break;
			case 2: s = 1;
				break;
			case 4: s = 2;
				break;
			case 8: s = 3;
				break;
			default: assert(false);
			}

			if (rm.index == REG_RIZ) {
				i = 4;
			} else {
				i = rm.index.raw_index;
			}

			if (rm.base == REG_RIZ) {
				b = 5;
			} else if (rm.base.raw_index == 5) {
				printf("********\n");
				fatal("unsupported encoding\n");
			} else {
				b = rm.base.raw_index;
			}
		}

		emit8((s & 3) << 6 | (i & 7) << 3 | (b & 7));
	}

	if (mod == 0 && (rm.base == REG_RBP || rm.base == REG_R13)) {
		fatal("XXX");
	}

	if (mod == 1) {
		emit8(rm.displacement);
	} else if (mod == 2 || (rm.base == REG_RIZ && rm.index == REG_RIZ) || (rm.base == REG_RIP)) {
		emit32(rm.displacement);
	}
}

void X86Encoder::encode_mod_reg_rm(const X86Register& reg, const X86Memory& rm)
{
	encode_mod_reg_rm(reg.raw_index, rm);
}

void X86Encoder::encode_opcode_mod_rm(uint16_t opcode, const X86Register& reg, const X86Memory& rm)
{
	assert(reg.size == 1 || reg.size == 2 || reg.size == 4 || reg.size == 8);
	assert(rm.base.size == 4 || rm.base.size == 8 || rm.base == REG_RIZ || rm.base == REG_RIP);

	// Figure out what prefixes are needed (if any)

	// Determine if there are any segment override prefixes
	if (rm.segment == REG_FS) {
		emit8(SEG_OVERRIDE_FS);
	} else if (rm.segment == REG_GS) {
		emit8(SEG_OVERRIDE_GS);
	}

	// Emit an operand-size override if the reg operand is 16-bits
	if (reg.size == 2) {
		emit8(OPER_SIZE_OVERRIDE);
	}

	// Emit an address-size override if the memory base is 32-bits
	if (rm.base.size == 4) {
		emit8(ADDR_SIZE_OVERRIDE);
	}

	uint8_t rex = 0;

	// Any REX prefix will do to access the new registers
	if (reg.newreg) {
		rex |= REX;
	}

	// If the reg operand is 64-bits, emit a REX_W
	if (reg.size == 8) {
		rex |= REX_W;
	}

	// If the reg operand is a high register, emit a REX_R
	if (reg.hireg) {
		rex |= REX_R;
	}

	// If the base operand is a high register, emit a REX_B
	if (rm.base.hireg) {
		rex |= REX_B;
	}

	// If the index operand is a high register, emit a REX_X
	if (rm.index.hireg) {
		rex |= REX_X;
	}

	// If we are to emit a REX prefix, do that now.
	if (rex) {
		emit8(rex);
	}

	// Emit the opcode
	if (opcode > 0x100) {
		emit8(0x0f);
	}

	emit8(opcode & 0xff);

	// Emit the modrm
	encode_mod_reg_rm(reg, rm);
}

void X86Encoder::encode_opcode_mod_rm(uint16_t opcode, const X86Register& reg, const X86Register& rm)
{
	// Register sizes MUST match
	// TODO: Think about this
	//assert(reg.size == rm.size);

	// Figure out what prefixes are needed (if any)

	// Emit an operand-size override if the reg operand is 16-bits
	if (reg.size == 2) {
		emit8(OPER_SIZE_OVERRIDE);
	}

	uint8_t rex = 0;

	// Any REX prefix will do to access the new registers
	if (reg.newreg || rm.newreg) {
		rex |= REX;
	}

	// If the reg or rm operand is 64-bits, emit a REX_W
	if (reg.size == 8) {
		rex |= REX_W;
	}

	// If the reg operand is a high register, emit a REX_R
	if (reg.hireg) {
		rex |= REX_R;
	}

	// If the rm operand is a high register, emit a REX_B
	if (rm.hireg) {
		rex |= REX_B;
	}

	// If we are to emit a REX prefix, do that now.
	if (rex) {
		emit8(rex);
	}

	// Emit the opcode
	if (opcode > 0x100) {
		emit8(0x0f);
	}

	emit8(opcode & 0xff);

	// Emit the modrm
	encode_mod_reg_rm(reg, rm);
}

void X86Encoder::encode_opcode_mod_rm(uint16_t opcode, uint8_t oper, const X86Register& rm)
{
	// Figure out what prefixes are needed (if any)

	// Emit an operand-size override if the reg operand is 16-bits
	if (rm.size == 2) {
		emit8(OPER_SIZE_OVERRIDE);
	}

	uint8_t rex = 0;

	// Any REX prefix will do to access the new registers
	if (rm.newreg) {
		rex |= REX;
	}

	// If the rm operand is 64-bits, emit a REX_W
	if (rm.size == 8) {
		rex |= REX_W;
	}

	// If the rm operand is a high register, emit a REX_B
	if (rm.hireg) {
		rex |= REX_B;
	}

	// If we are to emit a REX prefix, do that now.
	if (rex) {
		emit8(rex);
	}

	// Emit the opcode
	if (opcode > 0x100) {
		emit8(0x0f);
	}

	emit8(opcode & 0xff);

	// Emit the modrm
	encode_mod_reg_rm(oper, rm);
}

void X86Encoder::encode_opcode_mod_rm(uint16_t opcode, uint8_t oper, uint8_t size, const X86Memory& rm)
{
	assert(size == 1 || size == 2 || size == 4 || size == 8);
	assert(rm.base.size == 4 || rm.base.size == 8 || rm.base == REG_RIP || rm.base == REG_RIZ);

	// Figure out what prefixes are needed (if any)

	// Determine if there are any segment override prefixes
	if (rm.segment == REG_FS) {
		emit8(SEG_OVERRIDE_FS);
	} else if (rm.segment == REG_GS) {
		emit8(SEG_OVERRIDE_GS);
	}

	// Emit an operand-size override if the reg operand is 16-bits
	if (size == 2) {
		emit8(OPER_SIZE_OVERRIDE);
	}

	// Emit an address-size override if the memory base is 32-bits
	if (rm.base.size == 4) {
		emit8(ADDR_SIZE_OVERRIDE);
	}

	uint8_t rex = 0;

	// If the reg operand is 64-bits, emit a REX_W
	if (size == 8) {
		rex |= REX_W;
	}

	// If the base operand is a high register, emit a REX_B
	if (rm.base.hireg) {
		rex |= REX_B;
	}

	// If the index operand is a high register, emit a REX_X
	if (rm.index.hireg) {
		rex |= REX_X;
	}

	// If we are to emit a REX prefix, do that now.
	if (rex) {
		emit8(rex);
	}

	// Emit the opcode
	if (opcode > 0x100) {
		emit8(0x0f);
	}

	emit8(opcode & 0xff);

	// Emit the modrm
	encode_mod_reg_rm(oper, rm);
}
