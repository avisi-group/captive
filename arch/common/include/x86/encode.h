/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <malloc/malloc.h>
#include <x86/defs.h>

namespace captive {
	namespace arch {
		namespace x86 {

			struct X86Register {

				X86Register(const char *name, uint8_t size, uint8_t raw_index, bool hi = false, bool nw = false) : name(name), size(size), raw_index(raw_index), hireg(hi), newreg(nw)
				{
				}
				const char *name;
				uint8_t size;
				uint8_t raw_index;
				bool hireg;
				bool newreg;

				inline bool operator==(const X86Register& other) const
				{
					return other.size == size && other.raw_index == raw_index && other.hireg == hireg && other.newreg == newreg;
				}

				inline bool operator!=(const X86Register& other) const
				{
					return !(other.size == size && other.raw_index == raw_index && other.hireg == hireg && other.newreg == newreg);
				}
			};

			extern X86Register REG_RAX, REG_EAX, REG_AX, REG_AL, REG_AH;
			extern X86Register REG_RCX, REG_ECX, REG_CX, REG_CL, REG_CH;
			extern X86Register REG_RDX, REG_EDX, REG_DX, REG_DL, REG_DH;
			extern X86Register REG_RBX, REG_EBX, REG_BX, REG_BL, REG_BH;
			extern X86Register REG_RSP, REG_ESP, REG_SP, REG_SIL;
			extern X86Register REG_RBP, REG_EBP, REG_BP, REG_BPL;
			extern X86Register REG_RSI, REG_ESI, REG_SI, REG_SIL;
			extern X86Register REG_RDI, REG_EDI, REG_DI, REG_DIL;
			extern X86Register REG_R8, REG_R8D, REG_R8W, REG_R8B;
			extern X86Register REG_R9, REG_R9D, REG_R9W, REG_R9B;
			extern X86Register REG_R10, REG_R10D, REG_R10W, REG_R10B;
			extern X86Register REG_R11, REG_R11D, REG_R11W, REG_R11B;
			extern X86Register REG_R12, REG_R12D, REG_R12W, REG_R12B;
			extern X86Register REG_R13, REG_R13D, REG_R13W, REG_R13B;
			extern X86Register REG_R14, REG_R14D, REG_R14W, REG_R14B;
			extern X86Register REG_R15, REG_R15D, REG_R15W, REG_R15B;
			extern X86Register REG_RIZ, REG_RIP;

			struct X86VectorRegister {

				X86VectorRegister(const char *name, uint8_t size, uint8_t raw_index, bool hireg) : name(name), size(size), raw_index(raw_index), hireg(hireg)
				{
				}
				const char *name;
				uint8_t size;
				uint8_t raw_index;
				bool hireg;
			};

			extern X86VectorRegister REG_XMM0, REG_XMM1, REG_XMM2, REG_XMM3, REG_XMM4, REG_XMM5, REG_XMM6, REG_XMM7;
			extern X86VectorRegister REG_XMM8, REG_XMM9, REG_XMM10, REG_XMM11, REG_XMM12, REG_XMM13, REG_XMM14, REG_XMM15;

			struct X86SegmentRegister {

				X86SegmentRegister(const char *name, uint8_t raw_index) : name(name), raw_index(raw_index)
				{
				}
				const char *name;
				uint8_t raw_index;

				inline bool operator==(const X86SegmentRegister& other) const
				{
					return other.raw_index == raw_index;
				}

				inline bool operator!=(const X86SegmentRegister& other) const
				{
					return other.raw_index != raw_index;
				}
			};

			extern X86SegmentRegister REG_CS, REG_DS, REG_ES, REG_FS, REG_GS, REG_SS;

			struct X86Memory {
				const X86SegmentRegister& segment;
				const X86Register& index;
				const X86Register& base;
				int32_t displacement;
				uint8_t scale;

				X86Memory(const X86Register& _base) : segment(REG_DS), index(REG_RIZ), base(_base), displacement(0), scale(0)
				{
				}

				X86Memory(const X86Register& _base, int32_t disp) : segment(REG_DS), index(REG_RIZ), base(_base), displacement(disp), scale(0)
				{
				}

				X86Memory(const X86Register& _base, const X86Register& _index, uint8_t _scale) : segment(REG_DS), index(_index), base(_base), displacement(0), scale(_scale)
				{
				}

				X86Memory(const X86Register& _base, int32_t _disp, const X86Register& _index, uint8_t _scale) : segment(REG_DS), index(_index), base(_base), displacement(_disp), scale(_scale)
				{
				}

				X86Memory(const X86SegmentRegister& _segment, const X86Register& _base) : segment(_segment), index(REG_RIZ), base(_base), displacement(0), scale(0)
				{
				}

				X86Memory(const X86SegmentRegister& _segment, int32_t _disp) : segment(_segment), index(REG_RIZ), base(REG_RIZ), displacement(_disp), scale(0)
				{
				}

				static X86Memory get(const X86Register& base)
				{
					return X86Memory(base);
				}

				static X86Memory get(const X86Register& base, const X86Register& index, int scale)
				{
					return X86Memory(base, index, scale);
				}

				static X86Memory get(const X86Register& base, int32_t disp, const X86Register& index, int scale)
				{
					return X86Memory(base, disp, index, scale);
				}

				static X86Memory get(const X86Register& base, int32_t disp)
				{
					return X86Memory(base, disp);
				}

				static X86Memory get(const X86SegmentRegister& segment, const X86Register& base)
				{
					return X86Memory(segment, base);
				}

				static X86Memory get(const X86SegmentRegister& segment, int32_t disp)
				{
					return X86Memory(segment, disp);
				}
			};

			class X86Encoder {
			public:
				X86Encoder(malloc::Allocator& allocator);

				inline uint8_t *get_buffer()
				{
					return _buffer;
				}

				inline uint32_t get_buffer_size()
				{
					return _write_offset;
				}

				inline void finalise()
				{
				}

				inline void destroy_buffer()
				{
					if (_buffer) allocator.free(_buffer);
					_buffer = NULL;
				}

				void call(const X86Register& reg);
				void lcall(const X86Memory& mem);

				void push(const X86Register& reg);
				void pop(const X86Register& reg);

				void push(uint32_t imm);
				void pushf();
				void popf();

				void wbinvd();
				void invlpg(const X86Memory& addr);
				void lea(const X86Memory& addr, const X86Register& dst);

				void movzx(const X86Register& src, const X86Register& dst);
				void movsx(const X86Register& src, const X86Register& dst);

				void movq(const X86Register &src, const X86VectorRegister &dst);
				void movq(const X86VectorRegister &src, const X86Register &dst);

				void incq(const X86Memory& loc);
				void incl(const X86Memory& loc);
				void incw(const X86Memory& loc);
				void incb(const X86Memory& loc);

				void movcs(const X86Register& dst);
				void mov(const X86SegmentRegister& src, const X86Register& dst);
				void mov(const X86Register& src, const X86Register& dst);
				void mov(const X86Memory& src, const X86Register& dst);
				void mov(const X86Register& src, const X86Memory& dst);
				void mov(uint64_t src, const X86Register& dst);

				void mov8(uint64_t imm, const X86Memory& dst);
				void mov4(uint32_t imm, const X86Memory& dst);
				void mov2(uint16_t imm, const X86Memory& dst);
				void mov1(uint8_t imm, const X86Memory& dst);

				void xchg(const X86Register& a, const X86Register& b);
				void xchg(const X86Memory& a, const X86Register& b);

				void cmpxchg(const X86Register& src, const X86Memory& dst);

				void cbtw();
				void cwtl();
				void cltq();

				void cltd();
				void cqto();

				void andd(uint64_t val, const X86Register& dst);
				void andd(uint64_t val, uint8_t size, const X86Memory& dst);
				void orr(uint64_t val, const X86Register& dst);
				void orr(uint64_t val, uint8_t size, const X86Memory& dst);
				void xorr(uint64_t val, const X86Register& dst);
				void xorr(uint64_t val, uint8_t size, const X86Memory& dst);

				void andd(uint32_t val, const X86Register& dst);
				void andd(uint32_t val, uint8_t size, const X86Memory& dst);
				void orr(uint32_t val, const X86Register& dst);
				void orr(uint32_t val, uint8_t size, const X86Memory& dst);
				void xorr(uint32_t val, const X86Register& dst);
				void xorr(uint32_t val, uint8_t size, const X86Memory& dst);

				void nott(const X86Register& dst);
				void nott(const X86Memory& dst);

				void andd(const X86Register& src, const X86Register& dest);
				void andd(const X86Register& src, const X86Memory& dest);
				void andd(const X86Memory& src, const X86Register& dest);
				void orr(const X86Register& src, const X86Register& dest);
				void orr(const X86Register& src, const X86Memory& dest);
				void orr(const X86Memory& src, const X86Register& dest);
				void xorr(const X86Register& src, const X86Register& dest);
				void xorr(const X86Register& src, const X86Memory& dest);
				void xorr(const X86Memory& src, const X86Register& dest);

				void shl(uint8_t amount, uint8_t dstsize, const X86Memory& dst);
				void shr(uint8_t amount, uint8_t dstsize, const X86Memory& dst);
				void sar(uint8_t amount, uint8_t dstsize, const X86Memory& dst);
				void rol(uint8_t amount, uint8_t dstsize, const X86Memory& dst);
				void ror(uint8_t amount, uint8_t dstsize, const X86Memory& dst);
				void shl(uint8_t amount, const X86Register& dst);
				void shr(uint8_t amount, const X86Register& dst);
				void sar(uint8_t amount, const X86Register& dst);
				void rol(uint8_t amount, const X86Register& dst);
				void ror(uint8_t amount, const X86Register& dst);
				void shl(const X86Register& amount, const X86Register& dst);
				void shr(const X86Register& amount, const X86Register& dst);
				void sar(const X86Register& amount, const X86Register& dst);
				void rol(const X86Register& amount, const X86Register& dst);
				void ror(const X86Register& amount, const X86Register& dst);

				void bswap(const X86Register& reg);

				void adc(uint64_t src, const X86Register& dst);
				void adc(uint32_t src, const X86Register& dst);
				void adc(const X86Memory& src, const X86Register& dst);
				void adc(const X86Register& src, const X86Memory& dst);
				void adc(const X86Register& src, const X86Register& dst);
				void sbb(uint64_t src, const X86Register& dst);
				void sbb(uint32_t src, const X86Register& dst);
				void sbb(const X86Memory& src, const X86Register& dst);
				void sbb(const X86Register& src, const X86Memory& dst);
				void sbb(const X86Register& src, const X86Register& dst);

				void add(const X86Register& src, const X86Register& dst);
				void add(const X86Memory& src, const X86Register& dst);
				void add(uint32_t val, const X86Register& dst);
				void add(uint32_t val, uint8_t size, const X86Memory& dst);
				void add(const X86Register& src, const X86Memory& dst);
				void add1(uint8_t val, const X86Memory& dst);
				void add2(uint16_t val, const X86Memory& dst);
				void add4(uint32_t val, const X86Memory& dst);
				void add8(uint32_t val, const X86Memory& dst);
				void add8(uint64_t val, const X86Memory& dst);

				void sub(const X86Register& src, const X86Register& dst);
				void sub(const X86Memory& src, const X86Register& dst);
				void sub(const X86Register& src, const X86Memory& dst);
				void sub(uint32_t val, const X86Register& dst);
				void sub(uint32_t val, uint8_t size, const X86Memory& dst);

				void mul(const X86Register& src, const X86Register& dst);
				void mul(const X86Register& multiplier);
				void imul(const X86Register& multiplier);
				void div(const X86Register& divisor);
				void idiv(const X86Register& divisor);

				void cmp(const X86Register& src, const X86Register& dst);
				void cmp(const X86Register& src, const X86Memory& dst);
				void cmp(const X86Memory& src, const X86Register& dst);
				void cmp(uint32_t val, const X86Register& dst);
				void cmp1(uint8_t val, const X86Memory& dst);
				void cmp1(uint8_t val, const X86Register& dst);
				void cmp2(uint16_t val, const X86Memory& dst);
				void cmp4(uint32_t val, const X86Memory& dst);
				void cmp8(uint32_t val, const X86Memory& dst);

				void test(uint64_t val, const X86Register& op2);
				void test(const X86Register& op1, const X86Register& op2);
				void test(const X86Register& op1, const X86Memory& op2);

				void patch8(uint32_t offset, uint8_t val);
				void patch16(uint32_t offset, uint16_t val);
				void patch32(uint32_t offset, uint32_t val);
				void patch64(uint32_t offset, uint64_t val);

				void jmp(const X86Register& tgt);
				void jmp(const X86Memory& tgt);
				void jmp_offset(int32_t off);
				void jmp_reloc(uint32_t& reloc_offset);

				void jcc_reloc(uint8_t v, uint32_t& reloc_offset);

				inline void jo_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(0, reloc_offset);
				}

				inline void jno_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(1, reloc_offset);
				}

				inline void jb_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(2, reloc_offset);
				}

				inline void jnae_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(2, reloc_offset);
				}

				inline void jc_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(2, reloc_offset);
				}

				inline void jnb_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(3, reloc_offset);
				}

				inline void jae_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(3, reloc_offset);
				}

				inline void jnc_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(3, reloc_offset);
				}

				inline void jz_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(4, reloc_offset);
				}

				inline void je_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(4, reloc_offset);
				}

				inline void jnz_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(5, reloc_offset);
				}

				inline void jne_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(5, reloc_offset);
				}

				inline void jbe_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(6, reloc_offset);
				}

				inline void jna_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(6, reloc_offset);
				}

				inline void jnbe_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(7, reloc_offset);
				}

				inline void ja_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(7, reloc_offset);
				}

				inline void js_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(8, reloc_offset);
				}

				inline void jns_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(9, reloc_offset);
				}

				inline void jp_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(10, reloc_offset);
				}

				inline void jpe_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(10, reloc_offset);
				}

				inline void jnp_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(11, reloc_offset);
				}

				inline void jpo_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(11, reloc_offset);
				}

				inline void jl_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(12, reloc_offset);
				}

				inline void jnge_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(12, reloc_offset);
				}

				inline void jnl_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(13, reloc_offset);
				}

				inline void jge_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(13, reloc_offset);
				}

				inline void jle_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(14, reloc_offset);
				}

				inline void jng_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(14, reloc_offset);
				}

				inline void jnle_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(15, reloc_offset);
				}

				inline void jg_reloc(uint32_t& reloc_offset)
				{
					jcc_reloc(15, reloc_offset);
				}

				void jcc(uint8_t v, int32_t off);
				void jcc(uint8_t v, int8_t off);

				inline void jno(int8_t off)
				{
					jcc(1, off);
				}

				inline void je(int32_t off)
				{
					jcc(4, off);
				}

				inline void je(int8_t off)
				{
					jcc(4, off);
				}

				inline void jz(int32_t off)
				{
					jcc(4, off);
				}

				inline void jz(int8_t off)
				{
					jcc(4, off);
				}

				inline void jnz(int32_t off)
				{
					jcc(5, off);
				}

				inline void jnz(int8_t off)
				{
					jcc(5, off);
				}

				inline void jne(int32_t off)
				{
					jcc(5, off);
				}

				inline void jne(int8_t off)
				{
					jcc(5, off);
				}

				inline void jnc(int8_t off)
				{
					jcc(3, off);
				}

				inline void jl(int8_t off)
				{
					jcc(12, off);
				}

				inline void jnge(int8_t off)
				{
					jcc(12, off);
				}

				inline void jle(int8_t off)
				{
					jcc(14, off);
				}

				inline void jng(int8_t off)
				{
					jcc(14, off);
				}

				void cmov(uint8_t code, const X86Register &src, const X86Register &dst);

				inline void cmove(const X86Register &src, const X86Register &dst)
				{
					cmov(4, src, dst);
				}

				void lahf();
				void clc();
				void stc();
				void cmc();
				void cli();
				void sti();

				void setcc(uint8_t v, const X86Register& dst);
				void setcc(uint8_t v, const X86Memory& dst);

				inline void seto(const X86Register& dst)
				{
					setcc(0x00, dst);
				}

				inline void seto(const X86Memory& dst)
				{
					setcc(0x00, dst);
				}

				inline void setno(const X86Register& dst)
				{
					setcc(0x01, dst);
				}

				inline void setb(const X86Register& dst)
				{
					setcc(0x02, dst);
				}

				inline void setnae(const X86Register& dst)
				{
					setb(dst);
				}

				inline void setc(const X86Register& dst)
				{
					setb(dst);
				}

				inline void setc(const X86Memory& dst)
				{
					setcc(0x02, dst);
				}

				inline void setnb(const X86Register& dst)
				{
					setcc(0x03, dst);
				}

				inline void setae(const X86Register& dst)
				{
					setnb(dst);
				}

				inline void setnc(const X86Register& dst)
				{
					setnb(dst);
				}

				inline void setnc(const X86Memory& dst)
				{
					setcc(0x03, dst);
				}

				inline void setz(const X86Register& dst)
				{
					setcc(0x04, dst);
				}

				inline void setz(const X86Memory& dst)
				{
					setcc(0x04, dst);
				}

				inline void sete(const X86Register& dst)
				{
					setz(dst);
				}

				inline void setnz(const X86Register& dst)
				{
					setcc(0x05, dst);
				}

				inline void setne(const X86Register& dst)
				{
					setnz(dst);
				}

				inline void setbe(const X86Register& dst)
				{
					setcc(0x06, dst);
				}

				inline void setna(const X86Register& dst)
				{
					setbe(dst);
				}

				inline void setnbe(const X86Register& dst)
				{
					setcc(0x07, dst);
				}

				inline void seta(const X86Register& dst)
				{
					setnbe(dst);
				}

				inline void sets(const X86Register& dst)
				{
					setcc(0x08, dst);
				}

				inline void sets(const X86Memory& dst)
				{
					setcc(0x08, dst);
				}

				inline void setns(const X86Register& dst)
				{
					setcc(0x09, dst);
				}

				inline void setp(const X86Register& dst)
				{
					setcc(0x0a, dst);
				}

				inline void setpe(const X86Register& dst)
				{
					setp(dst);
				}

				inline void setnp(const X86Register& dst)
				{
					setcc(0x0b, dst);
				}

				inline void setpo(const X86Register& dst)
				{
					setnp(dst);
				}

				inline void setl(const X86Register& dst)
				{
					setcc(0x0c, dst);
				}

				inline void setnge(const X86Register& dst)
				{
					setl(dst);
				}

				inline void setnl(const X86Register& dst)
				{
					setcc(0x0d, dst);
				}

				inline void setge(const X86Register& dst)
				{
					setnl(dst);
				}

				inline void setle(const X86Register& dst)
				{
					setcc(0x0e, dst);
				}

				inline void setng(const X86Register& dst)
				{
					setle(dst);
				}

				inline void setnle(const X86Register& dst)
				{
					setcc(0x0f, dst);
				}

				inline void setg(const X86Register& dst)
				{
					setnle(dst);
				}

				void bsr(const X86Register& src, const X86Register& dst);

				void sysenter();
				void syscall();
				void sysret();
				void sysretq();
				void int3();
				void intt(uint8_t irq);

				void out(const X86Register& val, const X86Register& port);
				void out(const X86Register& val, uint8_t port);

				void leave();
				void ret();
				void hlt();
				void nop();
				void nop(uint8_t bytes);
				void nop(const X86Memory& mem);

				void align_up(uint8_t amount_to_align);

				uint32_t current_offset() const
				{
					return _write_offset;
				}

				inline void emit8(uint8_t b)
				{
					ensure_buffer(1);
					_buffer[_write_offset++] = b;
				}

				inline void emit16(uint16_t v)
				{
					ensure_buffer(2);

					*(uint16_t*) (&_buffer[_write_offset]) = v;
					_write_offset += 2;
				}

				inline void emit32(uint32_t v)
				{
					ensure_buffer(4);

					*(uint32_t*) (&_buffer[_write_offset]) = v;
					_write_offset += 4;
				}

				inline void emit64(uint64_t v)
				{
					ensure_buffer(8);

					*(uint64_t*) (&_buffer[_write_offset]) = v;
					_write_offset += 8;
				}

				inline void ensure_extra_buffer(int extra)
				{
					ensure_buffer(extra);
				}
			private:
				malloc::Allocator& allocator;
				uint8_t *_buffer;
				uint32_t _buffer_size;
				uint32_t _write_offset;

				inline void ensure_buffer(int extra = 0)
				{
					if ((_write_offset + extra) >= _buffer_size) {
						_buffer_size += 128;
						_buffer = (uint8_t *) allocator.realloc(_buffer, _buffer_size);
					}
				}




				void encode_arithmetic(uint8_t oper, uint32_t imm, const X86Register& dst);
				void encode_arithmetic(uint8_t oper, uint32_t imm, uint8_t size, const X86Memory& dst);

				void encode_mod_reg_rm(uint8_t mreg, const X86Register& rm);
				void encode_mod_reg_rm(const X86Register& reg, const X86Register& rm);
				void encode_mod_reg_rm(uint8_t mreg, const X86Memory& rm);
				void encode_mod_reg_rm(const X86Register& reg, const X86Memory& rm);

				void encode_rex_prefix(bool b, bool x, bool r, bool w);

				void encode_opcode_mod_rm(uint16_t opcode, const X86Register& reg, const X86Memory& rm);
				void encode_opcode_mod_rm(uint16_t opcode, const X86Register& reg, const X86Register& rm);
				void encode_opcode_mod_rm(uint16_t opcode, uint8_t oper, const X86Register& rm);
				void encode_opcode_mod_rm(uint16_t opcode, uint8_t oper, uint8_t size, const X86Memory& rm);
			};
		}
	}
}
