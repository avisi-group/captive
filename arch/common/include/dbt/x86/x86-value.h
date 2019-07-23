/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/el/value.h>
#include <dbt/mc/x86/machine.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/x86/x86-context.h>

namespace captive {
	namespace arch {
		namespace jit {
			namespace x86 {
				using namespace dbt::el;
				using namespace dbt::mc::x86;

				enum class X86ValueKind {
					UNKNOWN,
					CONSTANT,
					LOCAL_VARIABLE,
					GUEST_REGISTER,
					PC_REGISTER,
					UNARY_OPERATION,
					BINARY_OPERATION,
					COMPARISON_OPERATION,
					CAST,
					OPERAND,
					VECTOR_EXTRACT,
					VECTOR_INSERT
				};

				class X86Emitter;

				class X86Value : public Value {
				public:

					X86Value(X86Context& context, const Type& type, X86ValueKind kind) : _context(context), _type(type), _kind(kind)
					{

					}

					virtual ~X86Value()
					{
					}

					const Type& type() const override
					{
						return _type;
					}

					X86ValueKind kind() const
					{
						return _kind;
					}

					virtual Operand as_operand(X86Emitter& emitter);

				private:
					X86Context& _context;
					Type _type;
					X86ValueKind _kind;
				};

				class X86Constant : public X86Value {
				public:

					X86Constant(X86Context& context, const Type& type, uint64_t value, uint8_t width_in_bits) : X86Value(context, type, X86ValueKind::CONSTANT), _value(value), _width(width_in_bits)
					{
					}

					X86Constant(X86Context& context, const Type& type, float value, uint8_t width_in_bits) : X86Value(context, type, X86ValueKind::CONSTANT), _value(value), _width(width_in_bits)
					{
					}

					X86Constant(X86Context& context, const Type& type, double value, uint8_t width_in_bits) : X86Value(context, type, X86ValueKind::CONSTANT), _value(value), _width(width_in_bits)
					{
					}

					uint64_t value() const
					{
						return _value.u64;
					}

					uint8_t width_in_bits() const
					{
						return _width;
					}

					Operand as_operand(X86Emitter& emitter) override;

				private:

					union __value {

						__value(uint64_t v) : u64(v)
						{
						}

						__value(float v) : f32(v)
						{
						}

						__value(double v) : f64(v)
						{
						}

						uint64_t u64;
						float f32;
						double f64;
					} _value;

					uint8_t _width;
				};

				class X86GuestRegister : public X86Value {
				public:

					X86GuestRegister(X86Context& context, const Type& type, uint64_t offset) : X86Value(context, type, X86ValueKind::GUEST_REGISTER), _offset(offset), _cached(false), _cached_operand(Operand::make_invalid())
					{
					}

					uint64_t offset() const
					{
						return _offset;
					}

					Operand as_operand(X86Emitter& emitter) override;

					void invalidate()
					{
						_cached = false;
					}

				private:
					uint64_t _offset;
					bool _cached;
					Operand _cached_operand;
				};

				class X86PCRegister : public X86Value {
				public:

					X86PCRegister(X86Context& context) : X86Value(context, context.types().u64(), X86ValueKind::PC_REGISTER)
					{
					}

					Operand as_operand(X86Emitter& emitter) override;
				};

				class X86LocalVariable : public X86Value {
				public:

					X86LocalVariable(X86Context& context, const Type& type, const X86PhysicalRegister& reg, bool global) : X86Value(context, type, X86ValueKind::LOCAL_VARIABLE), _reg(reg), _global(global), _value(nullptr)
					{
					}

					const X86PhysicalRegister& reg() const
					{
						return _reg;
					}

					bool is_global() const
					{
						return _global;
					}

					Operand as_operand(X86Emitter& emitter) override;

					X86Value *current_value() const
					{
						return _value;
					}

					void current_value(X86Value *v)
					{
						_value = v;
					}

				private:
					X86PhysicalRegister _reg;
					bool _global;
					X86Value *_value;
				};

				class X86Operand : public X86Value {
				public:

					X86Operand(X86Context& context, const Type& type, const Operand& op) : X86Value(context, type, X86ValueKind::OPERAND), _operand(op)
					{
					}

					const Operand& operand() const
					{
						return _operand;
					}

					Operand as_operand(X86Emitter& emitter) override;

				private:
					Operand _operand;
				};

				namespace X86UnaryOperationKind {

					enum X86UnaryOperationKind {
						NOT,
						BSWAP,
						CLZ,
						NEG,
						SQRT
					};
				}

				class X86UnaryOperation : public X86Value {
				public:

					X86UnaryOperation(X86Context& context, X86UnaryOperationKind::X86UnaryOperationKind kind, X86Value *value) : X86Value(context, resolve_type(context, kind, value), X86ValueKind::UNARY_OPERATION), _kind(kind), _value(value), _has_operand(false)
					{
					}

					X86UnaryOperationKind::X86UnaryOperationKind kind() const
					{
						return _kind;
					}

					X86Value *value() const
					{
						return _value;
					}

					Operand as_operand(X86Emitter& emitter) override;

				private:
					static const Type& resolve_type(X86Context& ctx, X86UnaryOperationKind::X86UnaryOperationKind kind, X86Value *value);

					X86UnaryOperationKind::X86UnaryOperationKind _kind;
					X86Value *_value;

					Operand _operand;
					bool _has_operand;
				};

				namespace X86BinaryOperationKind {

					enum X86BinaryOperationKind {
						ADD,
						ADDF,
						ADC,
						ADCF,
						SUB,
						SUBF,
						SBB,
						SBBF,

						MUL,
						DIV,
						MOD,

						SMULL,
						SMULH,
						UMULL,
						UMULH,

						AND,
						OR,
						XOR,

						SHR,
						SHL,
						SAR,
						ROL,
						ROR,
					};
				}

				class X86BinaryOperation : public X86Value {
				public:

					X86BinaryOperation(X86Context& context, X86BinaryOperationKind::X86BinaryOperationKind kind, X86Value *lhs, X86Value *rhs)
					: X86Value(context, resolve_type(context, kind, lhs, rhs), X86ValueKind::BINARY_OPERATION),
					_kind(kind),
					_lhs(lhs),
					_rhs(rhs),
					_carry(nullptr),
					_emitted(false),
					_operand(Operand::make_invalid())
					{
					}

					X86BinaryOperation(X86Context& context, X86BinaryOperationKind::X86BinaryOperationKind kind, X86Value *lhs, X86Value *rhs, X86Value *carry)
					: X86Value(context, resolve_type(context, kind, lhs, rhs), X86ValueKind::BINARY_OPERATION),
					_kind(kind),
					_lhs(lhs),
					_rhs(rhs),
					_carry(carry),
					_emitted(false),
					_operand(Operand::make_invalid())
					{
					}

					X86BinaryOperationKind::X86BinaryOperationKind kind() const
					{
						return _kind;
					}

					X86Value *lhs() const
					{
						return _lhs;
					}

					X86Value *rhs() const
					{
						return _rhs;
					}

					X86Value *carry() const
					{
						return _carry;
					}

					Operand as_operand(X86Emitter& emitter) override;

				private:
					static const Type& resolve_type(X86Context& ctx, X86BinaryOperationKind::X86BinaryOperationKind kind, X86Value *lhs, X86Value *rhs);

					Operand shift_as_operand(X86Emitter& emitter);
					Operand arithmetic_as_operand(X86Emitter& emitter);
					Operand vector_arithmetic_as_operand(X86Emitter& emitter);
					Operand vector_shift_as_operand(X86Emitter& emitter);
					Operand long_arithmetic_as_operand(X86Emitter& emitter);
					Operand fp_arithmetic_as_operand(X86Emitter& emitter);

					X86BinaryOperationKind::X86BinaryOperationKind _kind;
					X86Value *_lhs, *_rhs, *_carry;

					bool _emitted;
					Operand _operand;
				};

				namespace X86ComparisonOperationKind {

					enum X86ComparisonOperationKind {
						EQ,
						NE,
						LT,
						LE,
						GT,
						GE
					};
				}

				class X86ComparisonOperation : public X86Value {
				public:

					X86ComparisonOperation(X86Context& context, X86ComparisonOperationKind::X86ComparisonOperationKind kind, X86Value *v1, X86Value *v2)
					: X86Value(context, resolve_type(context, kind, v1, v2), X86ValueKind::COMPARISON_OPERATION),
					_kind(kind),
					_v1(v1),
					_v2(v2),
					_operand(Operand::make_invalid()),
					_emitted(false)
					{

					}

					X86ComparisonOperationKind::X86ComparisonOperationKind kind() const
					{
						return _kind;
					}

					X86Value *v1() const
					{
						return _v1;
					}

					X86Value *v2() const
					{
						return _v2;
					}

					Operand as_operand(X86Emitter& emitter) override;

				private:
					static const Type& resolve_type(X86Context& ctx, X86ComparisonOperationKind::X86ComparisonOperationKind kind, X86Value *v1, X86Value *v2);

					Operand fp_comparison(X86Emitter& emitter);
					Operand std_comparison(X86Emitter& emitter);
					Operand vector_comparison(X86Emitter& emitter);

					X86ComparisonOperationKind::X86ComparisonOperationKind _kind;
					X86Value *_v1, *_v2;
					Operand _operand;
					bool _emitted;
				};

				namespace X86CastKind {

					enum X86CastKind {
						TRUNCATE,
						SX,
						ZX,
						REINTERPRET,
						CONVERT,
						SPLAT
					};
				}

				class X86Cast : public X86Value {
				public:

					X86Cast(X86Context& context, X86CastKind::X86CastKind kind, X86Value *value, const Type& to) : X86Value(context, to, X86ValueKind::CAST), _kind(kind), _value(value), _operand(Operand::make_invalid()), _emitted(false)
					{
					}

					X86CastKind::X86CastKind kind() const
					{
						return _kind;
					}

					X86Value *value() const
					{
						return _value;
					}

					Operand as_operand(X86Emitter& emitter) override;

				private:
					Operand generate(X86Emitter& emitter);

					Operand convert_float_to_int(X86Emitter& emitter);
					Operand convert_float32_to_int(X86Emitter& emitter, const Operand& value);
					Operand convert_float32_to_signed_int(X86Emitter& emitter, const Operand& value);
					Operand convert_float32_to_unsigned_int(X86Emitter& emitter, const Operand& value);
					Operand convert_float64_to_int(X86Emitter& emitter, const Operand& value);
					Operand convert_float64_to_signed_int(X86Emitter& emitter, const Operand& value);
					Operand convert_float64_to_unsigned_int(X86Emitter& emitter, const Operand& value);

					X86CastKind::X86CastKind _kind;
					X86Value *_value;

					Operand _operand;
					bool _emitted;
				};

				class X86VectorExtract : public X86Value {
				public:

					X86VectorExtract(X86Context& context, X86Value *vector, X86Value *index) : X86Value(context, vector->type().element_type(), X86ValueKind::VECTOR_EXTRACT), _vector(vector), _index(index), _operand(Operand::make_invalid()), _emitted(false)
					{
					}

					X86Value *vector() const
					{
						return _vector;
					}

					X86Value *index() const
					{
						return _index;
					}

					Operand as_operand(X86Emitter& emitter) override;

				private:
					Operand generate(X86Emitter& emitter);

					X86Value *_vector, *_index;

					Operand _operand;
					bool _emitted;
				};

				class X86VectorInsert : public X86Value {
				public:

					X86VectorInsert(X86Context& context, X86Value *vector, X86Value *index, X86Value *value) : X86Value(context, vector->type(), X86ValueKind::VECTOR_INSERT), _vector(vector), _index(index), _value(value), _operand(Operand::make_invalid()), _emitted(false)
					{
					}

					X86Value *vector() const
					{
						return _vector;
					}

					X86Value *index() const
					{
						return _index;
					}

					X86Value *value() const
					{
						return _value;
					}

					Operand as_operand(X86Emitter& emitter) override;

				private:
					Operand generate(X86Emitter& emitter);

					X86Value *_vector, *_index, *_value;

					Operand _operand;
					bool _emitted;
				};
			}
		}
	}
}
