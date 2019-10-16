/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/common.h>
#include <dbt/support.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/machine.h>
#include <dbt/util/map.h>

namespace captive {
	namespace arch {
		namespace dbt {
			class Support;

			namespace mc {
				namespace x86 {
					class Instruction;
					class Operand;

					class TranslatedCodeBuffer {
					public:

						TranslatedCodeBuffer(Support& support) : _support(support), _buffer(nullptr), _capacity(0), _current(nullptr)
						{
						}

						~TranslatedCodeBuffer()
						{
							if (_buffer) _support.free(_buffer, AllocClass::TRANSLATED_CODE);
						}

						Support& support() const
						{
							return _support;
						}

						dbt_off_t offset() const
						{
							return(dbt_off_t) ((dbt_off_t) _current - (dbt_off_t) _buffer);
						}

						dbt_size_t size() const
						{
							return offset();
						}

						const void *buffer() const
						{
							return _buffer;
						}

						inline dbt_off_t emit8(dbt_u8 v)
						{
							*((dbt_u8 *) _current) = v;
							_current = (void *) ((dbt_off_t) _current + 1);

							return offset() - 1;
						}

						inline dbt_off_t emit16(dbt_u16 v)
						{
							*((dbt_u16 *) _current) = v;
							_current = (void *) ((dbt_off_t) _current + 2);

							return offset() - 2;
						}

						inline dbt_off_t emit32(dbt_u32 v)
						{
							*((dbt_u32 *) _current) = v;
							_current = (void *) ((dbt_off_t) _current + 4);

							return offset() - 4;
						}

						inline dbt_off_t emit64(dbt_u64 v)
						{
							*((dbt_u64 *) _current) = v;
							_current = (void *) ((dbt_off_t) _current + 8);

							return offset() - 8;
						}

						inline void write8(dbt_off_t offset, dbt_u8 v)
						{
							*((dbt_u8 *) ptr_to(offset)) = v;
						}

						inline void write16(dbt_off_t offset, dbt_u16 v)
						{
							*((dbt_u16 *) ptr_to(offset)) = v;
						}

						inline void write32(dbt_off_t offset, dbt_u32 v)
						{
							*((dbt_u32 *) ptr_to(offset)) = v;
						}

						inline void write64(dbt_off_t offset, dbt_u64 v)
						{
							*((dbt_u64 *) ptr_to(offset)) = v;
						}

						inline void begin_instruction()
						{
							ensure_capacity(16);
						}

					private:

						inline void *ptr_to(dbt_off_t offset)
						{
							if (offset > size()) {
								return nullptr;
							}
							return(void *) (&((dbt_u8 *) _buffer)[offset]);
						}

						void ensure_capacity(dbt_size_t amount)
						{
							if ((size() + amount) > _capacity) {
								dbt_off_t current_offset = offset();

								_capacity += 0x100;
								_buffer = _support.realloc(_buffer, _capacity, AllocClass::TRANSLATED_CODE);
								if (!_buffer) {
									_support.assertion_fail("tcb: out of memory");
								}

								_current = (void *) ((dbt_off_t) _buffer + current_offset);
							}
						}

						Support& _support;
						void *_buffer;
						dbt_size_t _capacity;
						void *_current;
					};

					class Encoder {
					public:

						Encoder(Support& support) : _support(support), _labels(support), _relocations(support), _current(nullptr)
						{
						}

						void *encode(Instruction *head, dbt_size_t& size);

					private:
						bool encode_instruction(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_mov(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cmov(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_mov_x(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_lea(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_xchg(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cmpxchg(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cvt(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_add(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_adc(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_sub(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_sbb(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_mul_div(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_inc_dec(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_shift(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_and(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_or(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_xor(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_not(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_neg(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_bsr(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_bswap(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_test(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cmp(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_popcnt(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_stack(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_stack_f(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_lahf(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_carry_flag(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_dir_flag(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_jmp(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cset(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cjmp(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_ret(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_call(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_lcall(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_syscall(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_sysenter(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_sysret(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_int(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_out(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_nop(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_movd(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_movq(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_movdq(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_movss(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_movsd(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_padd(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_psub(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_packed_shift(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_p_bitwise(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_pcmpeq(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_pcmpgt(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_pextr(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_pinsr(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_punpck(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_pshuf(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_pack(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_pmul(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cvtsi(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cvtts(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_cvts(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_adds(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_subs(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_muls(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_divs(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_sqrts(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_rounds(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_arith(TranslatedCodeBuffer& tcb, const Instruction *insn, dbt_u16 opcode, bool dbl, bool ipacked);

						bool encode_ucomis(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_x87_fld(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_x87_fstp(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_x87_faddp(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_x87_fmulp(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_mxcsr(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_pku(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_rd_sr_base(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_rep_stos(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_vfmadd(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_fp_packed_xor(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_packed_mul(TranslatedCodeBuffer& tcb, const Instruction *insn);
						bool encode_fp_packed_div(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_clmul(TranslatedCodeBuffer& tcb, const Instruction *insn);

						bool encode_arithmetic_reg_reg(TranslatedCodeBuffer& tcb, dbt_u16 opcode, const Instruction *insn);
						bool encode_arithmetic_immediate(TranslatedCodeBuffer& tcb, dbt_u8 op, const Instruction *insn);

						bool encode_opcode_modrm_oper(TranslatedCodeBuffer& tcb, dbt_u16 opcode, dbt_u8 oper, const Operand& rm, bool omit_operand_override = false);
						bool encode_opcode_modrm(TranslatedCodeBuffer& tcb, dbt_u16 opcode, const Operand& reg, const Operand& rm, bool omit_operand_size_override = false, bool inhibit_66 = false);
						bool encode_sse_opcode_modrm(TranslatedCodeBuffer& tcb, dbt_u16 opcode, const Operand& reg, const Operand& rm, bool no_operand_prefix = false);
						bool encode_mod_reg_rm(TranslatedCodeBuffer& tcb, const Operand& reg, const Operand& rm);
						bool encode_mod_reg_rm_oper(TranslatedCodeBuffer& tcb, dbt_u8 oper, const Operand& rm);

						bool requires_rex(const Operand& reg) const;

						void assert_true(bool cond, const char *msg, const Instruction *insn);

						void register_label(dbt_off_t offset, const Instruction *label);
						void register_relocation(dbt_off_t offset, dbt_u8 width_in_bits, const Instruction *target);
						void perform_relocations(TranslatedCodeBuffer& tcb);

						Support& _support;
						dbt::util::Map<const Instruction *, dbt_off_t> _labels;
						dbt::util::Map<dbt_off_t, const Instruction *> _relocations;

						const Instruction *_current;
					};
				}
			}
		}
	}
}
