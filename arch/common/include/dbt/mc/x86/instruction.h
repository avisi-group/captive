/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/common.h>
#include <dbt/util/linked-instruction.h>
#include <dbt/mc/x86/machine.h>
#include <dbt/util/list.h>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace mc {
				namespace x86 {

					enum class OperandKind {
						INVALID,
						CONSTANT,
						REGISTER,
						MEMORY,
						LABEL,
						LITERAL
					};

					enum class MemoryScale {
						S1, S2, S4, S8
					};

					class Instruction;

					class UseDef {
					public:

						UseDef() : reg(X86PhysicalRegisters::RIZ), _valid(false)
						{
						}

						UseDef(const UseDef& other) : reg(other.reg), _valid(other._valid), _use(other._use), _def(other._def)
						{
						}

						inline bool is_valid() const
						{
							return _valid;
						}

						inline bool is_use() const
						{
							if (!_valid) return false;
							else return _use;
						}

						inline bool is_def() const
						{
							if (!_valid) return false;
							else return _def;
						}

						inline bool is_usedef() const
						{
							return is_use() && is_def();
						}

						X86PhysicalRegister reg;

						static UseDef make_use(const X86PhysicalRegister& reg)
						{
							return UseDef(reg, true, false);
						}

						static UseDef make_def(const X86PhysicalRegister& reg)
						{
							return UseDef(reg, false, true);
						}

						static UseDef make_usedef(const X86PhysicalRegister& reg)
						{
							return UseDef(reg, true, true);
						}

						static UseDef make_invalid()
						{
							return UseDef();
						}

					private:

						UseDef(X86PhysicalRegister reg, bool use, bool def) : reg(reg), _valid(true), _use(use), _def(def)
						{
						}

						bool _valid;
						bool _use, _def;
					};

					enum class OperandMatch {
						imm8,
						imm16,
						imm32,
						imm64,

						imm16_32,
						imm16_32_64,

						r8,
						r_m8,
						r16_32_64,
						r_m16_32_64,
					};

					class Operand {
					public:

						Operand() : kind(OperandKind::INVALID)
						{
						}

						OperandKind kind;

						inline bool is_reg() const
						{
							return kind == OperandKind::REGISTER;
						}

						inline bool is_mem() const
						{
							return kind == OperandKind::MEMORY;
						}

						inline bool is_const() const
						{
							return kind == OperandKind::CONSTANT;
						}

						inline bool is_invalid() const
						{
							return kind == OperandKind::INVALID;
						}

						inline bool is_literal() const
						{
							return kind == OperandKind::LITERAL;
						}

						bool matches(OperandMatch match) const;

						union {

							struct {
								dbt_u64 value;
								dbt_u8 width;
							} constant;

							struct {
								dbt_u64 value;
								dbt_u8 width;
							} literal;

							struct {
								X86PhysicalRegister reg;
								dbt_u8 width;
							} reg;

							struct {
								dbt_u8 access_width;

								X86PhysicalRegister base_register;
								X86PhysicalRegister index_register;
								dbt_u8 address_width;

								X86PhysicalRegister segment_override;

								dbt_s32 displacement;

								MemoryScale scale;
							} mem;

							struct {
								const Instruction *target;
							} label;
						};

						bool operator==(const Operand& other) const
						{
							if (kind != other.kind) return false;

							switch (kind) {
							case OperandKind::CONSTANT:
								return constant.value == other.constant.value && constant.width == other.constant.width;
							case OperandKind::LITERAL:
								return literal.value == other.literal.value && literal.width == other.literal.width;
							case OperandKind::INVALID:
								return false;
							case OperandKind::LABEL:
								return label.target == other.label.target;
								//case OperandKind::MEMORY:
								//	return mem == other.mem;
							case OperandKind::REGISTER:
								return reg.reg == other.reg.reg && reg.width == other.reg.width;
							default:
								return false;
							}
						}

						static const Operand make_invalid()
						{
							Operand op;
							op.kind = OperandKind::INVALID;

							return op;
						}

						static const Operand make_constant(dbt_u64 value, dbt_u8 size_in_bits)
						{
							Operand op;
							op.kind = OperandKind::CONSTANT;
							op.constant.value = value;
							op.constant.width = size_in_bits;

							return op;
						}

						static const Operand make_register(const X86Register& reg)
						{
							return make_register(reg.physical_register(), reg.width_in_bits());
						}

						static const Operand make_register(const X86PhysicalRegister& reg, dbt_u8 width)
						{
							Operand op;
							op.kind = OperandKind::REGISTER;
							op.reg.reg = reg;
							op.reg.width = width;

							return op;
						}

						static const Operand make_mem(dbt_u8 access_width_in_bits, const X86Register& base, dbt_s32 displ)
						{
							return make_mem(access_width_in_bits, base.width_in_bits(), base.physical_register(), displ);
						}

						static const Operand make_mem(dbt_u8 access_width_in_bits, dbt_u8 address_width_in_bits, const X86PhysicalRegister& base, dbt_s32 displ)
						{
							Operand op;
							op.kind = OperandKind::MEMORY;
							op.mem.access_width = access_width_in_bits;

							op.mem.base_register = base;
							op.mem.index_register = X86PhysicalRegisters::RIZ;
							op.mem.address_width = address_width_in_bits;

							op.mem.segment_override = X86PhysicalRegisters::DS;

							op.mem.displacement = displ;
							op.mem.scale = MemoryScale::S1;

							return op;
						}

						static const Operand make_mem(dbt_u8 access_width_in_bits, dbt_u8 address_width_in_bits, const X86PhysicalRegister& seg_override, const X86PhysicalRegister& base, dbt_s32 displ)
						{
							Operand op;
							op.kind = OperandKind::MEMORY;
							op.mem.access_width = access_width_in_bits;

							op.mem.base_register = base;
							op.mem.index_register = X86PhysicalRegisters::RIZ;
							op.mem.address_width = address_width_in_bits;

							op.mem.segment_override = seg_override;

							op.mem.displacement = displ;
							op.mem.scale = MemoryScale::S1;

							return op;
						}

						static const Operand make_mem(dbt_u8 access_width_in_bits, dbt_u8 address_width_in_bits, const X86PhysicalRegister& base, const X86PhysicalRegister& index, MemoryScale scale, dbt_s32 displ)
						{
							Operand op;
							op.kind = OperandKind::MEMORY;
							op.mem.access_width = access_width_in_bits;

							op.mem.base_register = base;
							op.mem.index_register = index;
							op.mem.address_width = address_width_in_bits;

							op.mem.segment_override = X86PhysicalRegisters::DS;

							op.mem.displacement = displ;
							op.mem.scale = scale;

							return op;
						}

						static const Operand make_mem(dbt_u8 access_width_in_bits, dbt_u8 address_width_in_bits, const X86PhysicalRegister& segoverride, const X86PhysicalRegister& base, const X86PhysicalRegister& index, MemoryScale scale, dbt_s32 displ)
						{
							Operand op;
							op.kind = OperandKind::MEMORY;
							op.mem.access_width = access_width_in_bits;

							op.mem.base_register = base;
							op.mem.index_register = index;
							op.mem.address_width = address_width_in_bits;

							op.mem.segment_override = segoverride;

							op.mem.displacement = displ;
							op.mem.scale = scale;

							return op;
						}

						static const Operand make_label(const Instruction *target)
						{
							Operand op;
							op.kind = OperandKind::LABEL;
							op.label.target = target;

							return op;
						}

						static const Operand make_literal(dbt_u64 value, dbt_u8 width)
						{
							Operand op;
							op.kind = OperandKind::LITERAL;
							op.literal.value = value;
							op.literal.width = width;

							return op;
						}
					};

					namespace InstructionKind {

						enum InstructionKind {
							LABEL, LITERAL, DEAD, FAKE_USE,
							NOP,

							MOV, MOVZX, MOVSX, LEA, XCHG, CMOV,
							CBTW, CWTL, CLTQ, // A -> A
							CWTD, CLTD, CQTO, // A -> D
							ADD, ADC, SUB, SBB,
							IMUL, MUL, IDIV, DIV,
							NEG,
							INC, DEC,
							SHR, SAR, SHL, ROR, ROL,
							AND, OR, XOR, NOT,
							BSR, BSWAP,
							TEST, CMP,
							POPCNT,
							CMPXCHG,

							// PUSH=37
							PUSH, POP, PUSHF, POPF,
							LAHF, CLC, STC, CMC,
							CLD,

							JO,
							JNO,
							JB, JNAE, JC,
							JNB, JAE, JNC,
							JZ, JE,
							JNZ, JNE,
							JBE, JNA,
							JNBE, JA,
							JS,
							JNS,
							JP, JPE,
							JNP, JPO,
							JL, JNGE,
							JNL, JGE,
							JLE, JNG,
							JNLE, JG,

							//70
							SETO,
							SETNO,
							SETB, SETNAE, SETC,
							SETNB, SETAE, SETNC,
							SETZ, SETE,
							SETNZ, SETNE,
							SETBE, SETNA,
							SETNBE, SETA,
							SETS,
							SETNS,
							SETP, SETPE,
							SETNP, SETPO,
							SETL, SETNGE,
							SETNL, SETGE,
							SETLE, SETNG,
							SETNLE, SETG,

							CMOVO,
							CMOVNO,
							CMOVB, CMOVNAE, CMOVC,
							CMOVNB, CMOVAE, CMOVNC,
							CMOVZ, CMOVE,
							CMOVNZ, CMOVNE,
							CMOVBE, CMOVNA,
							CMOVNBE, CMOVA,
							CMOVS,
							CMOVNS,
							CMOVP, CMOVPE,
							CMOVNP, CMOVPO,
							CMOVL, CMOVNGE,
							CMOVNL, CMOVGE,
							CMOVLE, CMOVNG,
							CMOVNLE, CMOVG,

							REP_STOSQ,

							JMP, RET,
							CALL, CALL0, CALL1, CALL2, CALL3, CALL4, CALL5, CALL6, QCALL,
							LCALL, LEAVE,

							SYSENTER, SYSCALL, SYSRET,
							WBINVD, INVLPG, CLI, STI, INT, IN, OUT, HLT,
							LDMXCSR, STMXCSR,
							RDPKU, WRPKU,
							RDFSBASE, RDGSBASE,

							MOVD, MOVQ, MOVDQA, MOVSS, MOVSD,
							PADDB, PADDW, PADDD, PADDQ,
							PSUBB, PSUBW, PSUBD, PSUBQ,
							PAND, POR, PXOR, PANDN,
							PMULLD, PMULLW, PMULUDQ,
							PCMPEQB, PCMPEQW, PCMPEQD, PCMPEQQ,
							PCMPGTB, PCMPGTW, PCMPGTD, PCMPGTQ,
							PEXTRB, PEXTRW, PEXTRD, PEXTRQ,
							PINSRB, PINSRW, PINSRD, PINSRQ,
							PUNPCKHBW, PUNPCKLBW, PUNPCKLWD, PACKUSWB,
							PUNPCKLDQ, PUNPCKLQDQ,
							PSHUFLW, PSHUFHW, PSHUFD,
							CVTSI2SS, CVTSI2SD,
							CVTTSS2SI, CVTTSD2SI,
							CVTSS2SD, CVTSD2SS,
							ADDSS, ADDSD,
							SUBSS, SUBSD, SUBPS, SUBPD,
							MULSS, MULSD,
							MULPS, MULPD,
							DIVSS, DIVSD,
							COMISS, COMISD,
							UCOMISS, UCOMISD,
							ROUNDSS, ROUNDSD,
							SQRTSS, SQRTSD,

							XORPS,

							PSLLW, PSLLD, PSLLQ,
							PSRLW, PSRLD, PSRLQ,
							PSRAW, PSRAD,

							FLD, FSTP,
							FADDP, FMULP,

							VFMADD132SS, VFMADD132SD,
							VFMADD213SS, VFMADD213SD,
							VFMADD231SS, VFMADD231SD,

							PCLMULQDQ,
						};
					}

					namespace InstructionMatch {

						enum InstructionMatch1 {
							REG,
							FREG,
							SREG,
							MEM,
							CONST,
							INVALID1
						};

						enum InstructionMatch2 {
							REG_REG,
							SREG_REG,
							REG_SREG,
							REG_MEM,
							MEM_REG,
							MEM_MEM,
							CONST_REG,
							CONST_MEM,

							FREG_FREG,
							FREG_REG,
							REG_FREG,
							MEM_FREG,
							FREG_MEM,

							CREG_REG,
							REG_CREG,

							INVALID2
						};

						enum InstructionMatch3 {
							FREG_FREG_FREG,
							FREG_FREG_IMM,
							INVALID3
						};
					}

					class Instruction : public dbt::util::LinkedInstruction<Instruction, InstructionKind::InstructionKind, Operand, 3> {
					public:

						struct UseDefList {
							static constexpr const int MAX_ENTRIES = 6;

							UseDefList() : next(0)
							{
							}

							//UseDef usedefs[MAX_ENTRIES];

							unsigned int next;
							char usedefdata[sizeof(UseDef) * MAX_ENTRIES];

							inline UseDef& get(int index)
							{
								return *((UseDef *) & usedefdata[index * sizeof(UseDef)]);
							}

							inline const UseDef& get(int index) const
							{
								return *((const UseDef *) &usedefdata[index * sizeof(UseDef)]);
							}

							inline void add(const UseDef& ud)
							{
								for (unsigned i = 0; i < next; i++) {
									const UseDef *usedef = (const UseDef *) &usedefdata[i * sizeof(UseDef)];
									if (usedef->is_valid() && usedef->reg == ud.reg) return;

									//if (usedefs[i].is_valid() && usedefs[i].reg == ud.reg) return;
								}

								if (ud.is_valid()) {
									UseDef *usedef = (UseDef *) & usedefdata[next++ * sizeof(UseDef)];
									*usedef = ud;

									//usedefs[next++] = ud;
								}
							}
						};

						Instruction(InstructionKind::InstructionKind kind) : LinkedInstruction(kind)
						{
						}

						dbt_u64 nr;

						InstructionMatch::InstructionMatch1 match1() const;
						InstructionMatch::InstructionMatch2 match2() const;
						InstructionMatch::InstructionMatch3 match3() const;

						void get_usedefs(UseDefList& list) const;

						bool is_control_flow() const;

					private:
						template<bool I, bool O>
						static void usedef_for_operand(UseDefList& list, const Operand& op);
					};
				}
			}
		}
	}
}
