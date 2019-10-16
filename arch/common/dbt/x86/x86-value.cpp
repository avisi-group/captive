/* SPDX-License-Identifier: MIT */

#include <dbt/x86/x86-value.h>
#include <dbt/x86/x86-emitter.h>
#include <dbt/mc/x86/machine.h>

using namespace captive::arch::jit::x86;
using namespace captive::arch::dbt::mc::x86;

Operand X86Value::as_operand(X86Emitter& emitter)
{
	emitter._x86_context.support().assertion_fail("cannot generate value operand");
	return Operand::make_invalid();
}

Operand X86Constant::as_operand(X86Emitter& emitter)
{
	if (type().is_vector()) {
		if (type().is_floating()) {
			if (_width == 32) {
				if (_value.f32 == 0) {
					auto zero_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
					auto zero_operand = Operand::make_register(zero_reg, 128);

					emitter.add_instruction(InstructionKind::PXOR, zero_operand, zero_operand);

					return zero_operand;
				} else {
					assert(false);
				}
			} else if (_width == 64) {
				if (_value.f64 == 0) {
					auto zero_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
					auto zero_operand = Operand::make_register(zero_reg, 128);

					emitter.add_instruction(InstructionKind::PXOR, zero_operand, zero_operand);

					return zero_operand;
				} else {
					assert(false);
				}
			} else {
				printf("XXX %u\n", _width);
				assert(false);
			}
		} else {
			if (_value.u64 == 0) {
				auto zero_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				auto zero_operand = Operand::make_register(zero_reg, 128);

				emitter.add_instruction(InstructionKind::PXOR, zero_operand, zero_operand);

				return zero_operand;
			} else {
				assert(false);
			}
		}
	} else if (type().is_floating()) {
		if ((_width == 32 && _value.f32 == 0) || (_width == 64 && _value.f64 == 0)) {
			auto reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			emitter.add_instruction(InstructionKind::PXOR, Operand::make_register(reg, 128), Operand::make_register(reg, 128));
			return Operand::make_register(reg, 128);
		} else {
			if (_width == 32) {
				auto temp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(_value.u64, 32), Operand::make_register(temp_reg, 32));

				auto reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				emitter.add_instruction(InstructionKind::MOVD, Operand::make_register(temp_reg, 32), Operand::make_register(reg, 128));

				return Operand::make_register(reg, 128);
			} else if (_width == 64) {
				auto temp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(_value.u64, 64), Operand::make_register(temp_reg, 64));

				auto reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(temp_reg, 64), Operand::make_register(reg, 128));

				return Operand::make_register(reg, 128);
			} else {
				assert(false);
			}
		}
	} else {
		assert(type().is_integer());

		if (_width == 128) {
			assert(_value.u64 == 0);

			auto reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			emitter.add_instruction(InstructionKind::PXOR, Operand::make_register(reg, 128), Operand::make_register(reg, 128));

			return Operand::make_register(reg, 128);
		} else if (_width == 64) {
			// If we have a 64-bit constant value, then there are some restrictions on how it can be represented.
			if (_value.u64 < 0x80000000ull) {
				// If the 64-bit value contains a number less than the maximum signed 32-bit value, it can be represented
				// as a 32-bit constant.
				return Operand::make_constant(_value.u64, 32);
			} else if ((_value.u64 >> 31) == 0x1ffffffff) {
				// If the 64-bit value contains a value that can be represented by a sign-extended 32-bit value, return
				// it directly as a 64-bit constant.
				return Operand::make_constant(_value.u64, 64);
			} else {
				// Otherwise, this constant value must be placed in a register to be used as an operand by instructions.
				auto reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(_value.u64, 64), Operand::make_register(reg, 64));
				return Operand::make_register(reg, 64);
			}
		}

		// Anything else and we're golden.
		return Operand::make_constant(_value.u64, _width);
	}
}

Operand X86UnaryOperation::as_operand(X86Emitter& emitter)
{
	if (_has_operand) return _operand;

	auto dst = emitter.vreg_allocator().alloc_vreg((type().is_floating() || type().is_vector()) ? X86RegisterClasses::SSE : X86RegisterClasses::GENERAL_PURPOSE);
	_operand = Operand::make_register(dst, (type().is_floating() || type().is_vector()) ? 128 : type().size_in_bits());
	_has_operand = true;

	switch (_kind) {
	case X86UnaryOperationKind::NOT:
		if (_value->type().is_vector()) {
			auto all_the_ones = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto all_the_ones_op = Operand::make_register(all_the_ones, 128);

			emitter.add_instruction(InstructionKind::PCMPEQD, all_the_ones_op, Operand::make_register(all_the_ones, 128));

			emitter.add_mov_auto(_value->as_operand(emitter), _operand);
			emitter.add_instruction(InstructionKind::PXOR, all_the_ones_op, _operand);
		} else {
			emitter.add_mov_auto(_value->as_operand(emitter), _operand);
			emitter.add_instruction(InstructionKind::NOT, _operand);
		}
		break;

	case X86UnaryOperationKind::CLZ:
		emitter.add_instruction(InstructionKind::BSR, _value->as_operand(emitter), Operand::make_register(dst, _value->type().size_in_bits()));

		if (_value->type().size_in_bits() == 64) {
			emitter.add_instruction(InstructionKind::XOR, Operand::make_constant(0x3f, 64), _operand);
		} else if (_value->type().size_in_bits() == 32) {
			emitter.add_instruction(InstructionKind::XOR, Operand::make_constant(0x1f, 32), _operand);
		} else {
			return Operand::make_invalid();
		}
		break;

	case X86UnaryOperationKind::BSWAP:
		emitter.add_mov_auto(_value->as_operand(emitter), _operand);
		emitter.add_instruction(InstructionKind::BSWAP, _operand);
		break;

	case X86UnaryOperationKind::NEG:
	{
		if (_value->type().is_vector()) {
			emitter.add_instruction(InstructionKind::PXOR, _operand, _operand);

			auto tmps = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);

			emitter.add_mov_auto(_value->as_operand(emitter), Operand::make_register(tmps, 128));

			switch (_value->type().vector_element_size_in_bits()) {
			case 8:
				emitter.add_instruction(InstructionKind::PSUBB, Operand::make_register(tmps, 128), _operand);
				break;
			case 16:
				emitter.add_instruction(InstructionKind::PSUBW, Operand::make_register(tmps, 128), _operand);
				break;
			case 32:
				emitter.add_instruction(InstructionKind::PSUBD, Operand::make_register(tmps, 128), _operand);
				break;
			case 64:
				emitter.add_instruction(InstructionKind::PSUBQ, Operand::make_register(tmps, 128), _operand);
				break;
			}
		} else if (_value->type().is_floating()) {
			auto tmps = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto tmpr = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

			emitter.add_mov_auto(_value->as_operand(emitter), _operand);

			if (_value->type().size_in_bits() == 32) {
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x80000000u, 32), Operand::make_register(tmpr, 32));
				emitter.add_mov_auto(Operand::make_register(tmpr, 32), Operand::make_register(tmps, 128));
			} else {
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8000000000000000ull, 64), Operand::make_register(tmpr, 64));
				emitter.add_mov_auto(Operand::make_register(tmpr, 64), Operand::make_register(tmps, 128));
			}

			emitter.add_instruction(InstructionKind::XORPS, Operand::make_register(tmps, 128), _operand);
		} else if (_value->type().is_integer()) {
			emitter.add_mov_auto(_value->as_operand(emitter), _operand);
			emitter.add_instruction(InstructionKind::NEG, _operand);
		} else {
			emitter._x86_context.support().assertion_fail("invalid operand type for neg");
			return Operand::make_invalid();
		}

		break;
	}

	case X86UnaryOperationKind::SQRT:
	{
		if (_value->type().is_floating()) {
			if (_value->type().size_in_bits() == 32) {
				emitter.add_instruction(InstructionKind::SQRTSS, _value->as_operand(emitter), _operand);
				emitter.add_instruction(InstructionKind::PSLLD, Operand::make_constant(1, 8), _operand);
				emitter.add_instruction(InstructionKind::PSRLD, Operand::make_constant(1, 8), _operand);
			} else {
				emitter.add_instruction(InstructionKind::SQRTSD, _value->as_operand(emitter), _operand);
				emitter.add_instruction(InstructionKind::PSLLQ, Operand::make_constant(1, 8), _operand);
				emitter.add_instruction(InstructionKind::PSRLQ, Operand::make_constant(1, 8), _operand);
			}
		} else {
			emitter._x86_context.support().assertion_fail("invalid operand type for sqrt");
			return Operand::make_invalid();
		}

		break;
	}

	default:
		emitter._x86_context.support().assertion_fail("unsupported unary operation kind");
		return Operand::make_invalid();
	}

	return _operand;
}

const Type& X86UnaryOperation::resolve_type(X86Context& ctx, X86UnaryOperationKind::X86UnaryOperationKind kind, X86Value* value)
{
	return value->type();
}

const Type& X86BinaryOperation::resolve_type(X86Context& ctx, X86BinaryOperationKind::X86BinaryOperationKind kind, X86Value* lhs, X86Value* rhs)
{
	return lhs->type();
}

Operand X86BinaryOperation::as_operand(X86Emitter& emitter)
{
	if (_emitted) {
		return _operand;
	}

	_emitted = true;

	if (_lhs->type().is_vector() || _rhs->type().is_vector()) {
		if ((_kind == X86BinaryOperationKind::SHL || _kind == X86BinaryOperationKind::SHR || _kind == X86BinaryOperationKind::SAR) && _lhs->type().is_vector() && _rhs->kind() == X86ValueKind::CONSTANT && ((X86Value *) _rhs)->type().is_vector()) {
			_operand = vector_shift_as_operand(emitter);
		} else {
			_operand = vector_arithmetic_as_operand(emitter);
		}

		return _operand;
	}

	if (_lhs->type().is_floating() || _rhs->type().is_floating()) {
		assert(_lhs->type().is_floating() && _rhs->type().is_floating());
		_operand = fp_arithmetic_as_operand(emitter);
		return _operand;
	}

	switch (_kind) {
	case X86BinaryOperationKind::SMULH:
	case X86BinaryOperationKind::SMULL:
	case X86BinaryOperationKind::UMULH:
	case X86BinaryOperationKind::UMULL:
		_operand = long_arithmetic_as_operand(emitter);
		break;

	case X86BinaryOperationKind::SHL:
	case X86BinaryOperationKind::SHR:
	case X86BinaryOperationKind::SAR:
	case X86BinaryOperationKind::ROL:
	case X86BinaryOperationKind::ROR:
		_operand = shift_as_operand(emitter);
		break;

	default:
		_operand = arithmetic_as_operand(emitter);
		break;
	}

	return _operand;
}

Operand X86BinaryOperation::long_arithmetic_as_operand(X86Emitter& emitter)
{
	auto lhs = _lhs->as_operand(emitter);
	auto rhs = _rhs->as_operand(emitter);

	emitter.add_mov_auto(lhs, Operand::make_register(X86PhysicalRegisters::A, _lhs->type().size_in_bits()));

	if (type().is_signed()) {
		switch (type().size_in_bits()) {
		case 64: emitter.add_instruction(InstructionKind::CQTO);
			break;
		case 32: emitter.add_instruction(InstructionKind::CLTD);
			break;
		case 16: emitter.add_instruction(InstructionKind::CWTD);
			break;
		default: return Operand::make_invalid();
		}
	}

	switch (_kind) {
	case X86BinaryOperationKind::SMULL:
	case X86BinaryOperationKind::SMULH:
		emitter.add_instruction(InstructionKind::IMUL, rhs);
		break;
	case X86BinaryOperationKind::UMULL:
	case X86BinaryOperationKind::UMULH:
		emitter.add_instruction(InstructionKind::MUL, rhs);
		break;
	default:
		return Operand::make_invalid();
	}

	switch (_kind) {
	case X86BinaryOperationKind::SMULL:
	case X86BinaryOperationKind::UMULL:
		return Operand::make_register(X86PhysicalRegisters::A, type().size_in_bits());
	case X86BinaryOperationKind::SMULH:
	case X86BinaryOperationKind::UMULH:
		return Operand::make_register(X86PhysicalRegisters::D, type().size_in_bits());
	default:
		return Operand::make_invalid();
	}
}

Operand X86BinaryOperation::fp_arithmetic_as_operand(X86Emitter& emitter)
{
	auto lhs = _lhs->as_operand(emitter);
	auto rhs = _rhs->as_operand(emitter);

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	auto dst = Operand::make_register(dst_reg, 128);

	emitter.add_mov_auto(lhs, dst);

	switch (_kind) {
	case X86BinaryOperationKind::ADD:
		if (type().size_in_bits() == 32) {
			emitter.add_instruction(InstructionKind::ADDSS, rhs, dst);
		} else if (type().size_in_bits() == 64) {
			emitter.add_instruction(InstructionKind::ADDSD, rhs, dst);
		} else {
			assert(false);
		}

		return dst; //Operand::make_register(dst_reg, type().size_in_bits());

	case X86BinaryOperationKind::SUB:
		if (type().size_in_bits() == 32) {
			emitter.add_instruction(InstructionKind::SUBSS, rhs, dst);
		} else if (type().size_in_bits() == 64) {
			emitter.add_instruction(InstructionKind::SUBSD, rhs, dst);
		} else {
			assert(false);
		}

		return dst; //Operand::make_register(dst_reg, type().size_in_bits());

	case X86BinaryOperationKind::MUL:
		if (type().size_in_bits() == 32) {
			emitter.add_instruction(InstructionKind::MULSS, rhs, dst);
		} else if (type().size_in_bits() == 64) {
			emitter.add_instruction(InstructionKind::MULSD, rhs, dst);
		} else {
			assert(false);
		}

		return dst; //Operand::make_register(dst_reg, type().size_in_bits());

	case X86BinaryOperationKind::DIV:
		if (type().size_in_bits() == 32) {
			emitter.add_instruction(InstructionKind::DIVSS, rhs, dst);
		} else if (type().size_in_bits() == 64) {
			emitter.add_instruction(InstructionKind::DIVSD, rhs, dst);
		} else {
			assert(false);
		}

		return dst; // Operand::make_register(dst_reg, type().size_in_bits());

	default:
		emitter._x86_context.support().assertion_fail("unsupported fp binary operation");
		return Operand::make_invalid();
	}
}

Operand X86BinaryOperation::arithmetic_as_operand(X86Emitter& emitter)
{
	if (_lhs->kind() == X86ValueKind::PC_REGISTER && _rhs->kind() == X86ValueKind::CONSTANT && _kind == X86BinaryOperationKind::ADD) {
		uint64_t offset = ((X86Constant *) _rhs)->value();

		if (offset < 0x80000000) {
			auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			auto dst = Operand::make_register(dst_reg, type().size_in_bits());

			emitter.add_instruction(InstructionKind::LEA, Operand::make_mem(64, 64, X86PhysicalRegisters::R15, offset), dst);

			_operand = dst;
			return _operand;
		}
	}

	auto lhs = _lhs->as_operand(emitter);
	auto rhs = _rhs->as_operand(emitter);

	if (_kind == X86BinaryOperationKind::DIV || _kind == X86BinaryOperationKind::MUL) {
		emitter.add_mov_auto(lhs, Operand::make_register(X86PhysicalRegisters::A, _lhs->type().size_in_bits()));

		if (type().is_signed()) {
			switch (type().size_in_bits()) {
			case 64: emitter.add_instruction(InstructionKind::CQTO);
				break;
			case 32: emitter.add_instruction(InstructionKind::CLTD);
				break;
			case 16: emitter.add_instruction(InstructionKind::CWTD);
				break;
			default: return Operand::make_invalid();
			}

			if (_kind == X86BinaryOperationKind::DIV)
				emitter.add_instruction(InstructionKind::IDIV, rhs);
			else
				emitter.add_instruction(InstructionKind::IMUL, rhs);
		} else {
			emitter.add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::D, 32), Operand::make_register(X86PhysicalRegisters::D, 32));
			if (_kind == X86BinaryOperationKind::DIV)
				emitter.add_instruction(InstructionKind::DIV, rhs);
			else
				emitter.add_instruction(InstructionKind::MUL, rhs);
		}

		return Operand::make_register(X86PhysicalRegisters::A, type().size_in_bits());
	}

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto dst = Operand::make_register(dst_reg, type().size_in_bits());
	emitter.add_mov_auto(lhs, dst);

	switch (_kind) {
	case X86BinaryOperationKind::ADD:
	case X86BinaryOperationKind::ADDF:
	case X86BinaryOperationKind::SUB:
	case X86BinaryOperationKind::SUBF:
	case X86BinaryOperationKind::ADC:
	case X86BinaryOperationKind::ADCF:
	case X86BinaryOperationKind::SBB:
	case X86BinaryOperationKind::SBBF:
	{
		InstructionKind::InstructionKind arith_kind;
		switch (_kind) {
		case X86BinaryOperationKind::ADD: arith_kind = InstructionKind::ADD;
			break;
		case X86BinaryOperationKind::ADDF: arith_kind = InstructionKind::ADD;
			break;
		case X86BinaryOperationKind::ADC: arith_kind = InstructionKind::ADC;
			break;
		case X86BinaryOperationKind::ADCF: arith_kind = InstructionKind::ADC;
			break;
		case X86BinaryOperationKind::SUB: arith_kind = InstructionKind::SUB;
			break;
		case X86BinaryOperationKind::SUBF: arith_kind = InstructionKind::SUB;
			break;
		case X86BinaryOperationKind::SBB: arith_kind = InstructionKind::SBB;
			break;
		case X86BinaryOperationKind::SBBF: arith_kind = InstructionKind::SBB;
			break;
		default: break;
		}

		switch (_kind) {
		case X86BinaryOperationKind::ADC:
		case X86BinaryOperationKind::ADCF:
		case X86BinaryOperationKind::SBB:
		case X86BinaryOperationKind::SBBF:
		{
			auto carry = _carry->as_operand(emitter);
			if (carry.is_const()) {
				// TODO: set/clear/update carry flag

				if (_kind == X86BinaryOperationKind::SBB || _kind == X86BinaryOperationKind::SBBF) {
					if (carry.constant.value == 1) {
						emitter.add_instruction(InstructionKind::STC);
					} else {
						arith_kind = InstructionKind::SUB;
					}
				} else {
					if (carry.constant.value == 0) {
						arith_kind = InstructionKind::ADD;
					} else {
						emitter.add_instruction(InstructionKind::STC);
					}
				}
			} else if (carry.is_reg()) {
				auto tmpreg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
				auto tmpop = Operand::make_register(tmpreg, 8);

				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xff, 8), tmpop);
				emitter.add_instruction(InstructionKind::ADD, carry, tmpop);
			} else if (carry.is_mem()) {
				auto tmpreg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
				auto tmpop = Operand::make_register(tmpreg, 8);

				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xff, 8), tmpop);
				emitter.add_instruction(InstructionKind::ADD, carry, tmpop);
			} else {
				emitter._x86_context.support().assertion_fail("unsupported carry-based operand");
				return Operand::make_invalid();
			}

			break;
		}
		default:
			break;
		}

		emitter.add_instruction(arith_kind, rhs, dst);

		switch (_kind) {
		case X86BinaryOperationKind::ADDF:
		case X86BinaryOperationKind::ADCF:
		case X86BinaryOperationKind::SUBF:
		case X86BinaryOperationKind::SBBF:
		{
			const auto& ad = emitter._arch_data;
			emitter.add_instruction(InstructionKind::SETZ, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, ad.ZERO_DISPLACEMENT));
			emitter.add_instruction(InstructionKind::SETS, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, ad.NEGATIVE_DISPLACEMENT));

			if (_kind == X86BinaryOperationKind::SUBF || _kind == X86BinaryOperationKind::SBBF) {
				emitter.add_instruction(InstructionKind::SETNC, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, ad.CARRY_DISPLACEMENT));
			} else {
				emitter.add_instruction(InstructionKind::SETC, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, ad.CARRY_DISPLACEMENT));
			}
			emitter.add_instruction(InstructionKind::SETO, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, ad.OVERFLOW_DISPLACEMENT));
			break;
		}
		default:
			break;
		}

		break;
	}

	case X86BinaryOperationKind::AND:
	{
		emitter.add_instruction(InstructionKind::AND, rhs, dst);
		break;
	}

	case X86BinaryOperationKind::OR:
	{
		emitter.add_instruction(InstructionKind::OR, rhs, dst);
		break;
	}

	case X86BinaryOperationKind::XOR:
	{
		emitter.add_instruction(InstructionKind::XOR, rhs, dst);
		break;
	}

	default:
		emitter._x86_context.support().debug_printf("XXX BINOP = %u", _kind);
		emitter._x86_context.support().assertion_fail("BINARY OPERATION NOT IMPLEMENTED");
		return Operand::make_invalid();
	}

	_operand = dst;
	return _operand;
}

Operand X86BinaryOperation::shift_as_operand(X86Emitter& emitter)
{
	auto value = _lhs->as_operand(emitter);

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto dst = Operand::make_register(dst_reg, type().size_in_bits());
	emitter.add_mov_auto(value, dst);

	// Any shift with a constant amount of zero is a noop.
	auto amount = _rhs->as_operand(emitter);
	if (amount.kind == OperandKind::CONSTANT && amount.constant.value == 0) {
		return dst;
	}

	switch (_kind) {
	case X86BinaryOperationKind::SHR:
	case X86BinaryOperationKind::SAR:
	case X86BinaryOperationKind::SHL:
	case X86BinaryOperationKind::ROL:
	case X86BinaryOperationKind::ROR:
	{
		// LHS is VALUE
		// RHS is AMOUNT

		if (amount.is_reg()) {
			emitter.add_instruction(InstructionKind::MOV, amount, Operand::make_register(X86PhysicalRegisters::C, amount.reg.width));
		} else if (amount.is_mem()) {
			emitter.add_instruction(InstructionKind::MOV, amount, Operand::make_register(X86Registers::CL));
		}

		InstructionKind::InstructionKind shift_kind;
		if (_kind == X86BinaryOperationKind::SHR) {
			shift_kind = InstructionKind::SHR;
		} else if (_kind == X86BinaryOperationKind::SHL) {
			shift_kind = InstructionKind::SHL;
		} else if (_kind == X86BinaryOperationKind::SAR) {
			shift_kind = InstructionKind::SAR;
		} else if (_kind == X86BinaryOperationKind::ROL) {
			shift_kind = InstructionKind::ROL;
		} else if (_kind == X86BinaryOperationKind::ROR) {
			shift_kind = InstructionKind::ROR;
		} else {
			return Operand::make_invalid();
		}

		if (amount.is_const()) {
			emitter.add_instruction(shift_kind, Operand::make_constant(amount.constant.value, 8), dst);
		} else {
			emitter.add_instruction(shift_kind, Operand::make_register(X86Registers::CL), dst);
		}
		return dst;
	}
	default:
		return Operand::make_invalid();
	}
}

Operand X86BinaryOperation::vector_shift_as_operand(X86Emitter& emitter)
{
	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	auto dst = Operand::make_register(dst_reg, 128);

	uint8_t shift_amount = ((X86Constant *) _rhs)->value();

	auto lhs = _lhs->as_operand(emitter);

	emitter.add_mov_auto(lhs, dst);

	if (shift_amount == 0) {
		return dst;
	}

	auto rhs = Operand::make_constant(shift_amount, 8);
	switch (_kind) {
	case X86BinaryOperationKind::SHL:
		switch (type().vector_element_size_in_bits()) {
		case 8:
		{
			if (shift_amount < 8) {
				for (int i = 0; i < shift_amount; i++) {
					emitter.add_instruction(InstructionKind::PADDB, dst, dst);
				}
			} else {
				emitter._x86_context.support().assertion_fail("unsupported vector element width in shl8");
			}
			break;
		}
		case 16: emitter.add_instruction(InstructionKind::PSLLW, rhs, dst);
			break;
		case 32: emitter.add_instruction(InstructionKind::PSLLD, rhs, dst);
			break;
		case 64: emitter.add_instruction(InstructionKind::PSLLQ, rhs, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported vector element width in shl");
			break;
		}

		return dst;

	case X86BinaryOperationKind::SHR:
		switch (type().vector_element_size_in_bits()) {
		case 8:
		{
			//emitter._x86_context.support().assertion_fail("unsupported vector element width in shr8");

			auto zero_tmp = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto zero_op = Operand::make_register(zero_tmp, 128);

			emitter.add_instruction(InstructionKind::PXOR, zero_op, zero_op);

			auto upper_tmp = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto upper_op = Operand::make_register(upper_tmp, 128);

			auto lower_tmp = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto lower_op = Operand::make_register(lower_tmp, 128);

			emitter.add_mov_auto(dst, upper_op);
			emitter.add_mov_auto(dst, lower_op);

			emitter.add_instruction(InstructionKind::PUNPCKHBW, zero_op, upper_op);
			emitter.add_instruction(InstructionKind::PUNPCKLBW, zero_op, lower_op);

			emitter.add_instruction(InstructionKind::PSRLW, rhs, upper_op);
			emitter.add_instruction(InstructionKind::PSRLW, rhs, lower_op);

			auto mask_g_tmp = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x00ff00ff, 32), Operand::make_register(mask_g_tmp, 32));
			emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(mask_g_tmp, 64), zero_op);
			emitter.add_instruction(InstructionKind::PSHUFD, Operand::make_constant(0x0, 8), zero_op, zero_op);

			emitter.add_instruction(InstructionKind::PAND, zero_op, upper_op);
			emitter.add_instruction(InstructionKind::PAND, zero_op, lower_op);

			emitter.add_instruction(InstructionKind::PACKUSWB, upper_op, lower_op);

			emitter.add_mov_auto(lower_op, dst);

			break;
		}
		case 16: emitter.add_instruction(InstructionKind::PSRLW, rhs, dst);
			break;
		case 32: emitter.add_instruction(InstructionKind::PSRLD, rhs, dst);
			break;
		case 64: emitter.add_instruction(InstructionKind::PSRLQ, rhs, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported vector element width in shr");
			break;
		}

		return dst;

	case X86BinaryOperationKind::SAR:
		switch (type().vector_element_size_in_bits()) {
		case 8:
		case 64:
			emitter._x86_context.support().assertion_fail("unsupported vector element width in sar8/64");
			break;
		case 16: emitter.add_instruction(InstructionKind::PSRAW, rhs, dst);
			break;
		case 32: emitter.add_instruction(InstructionKind::PSRAD, rhs, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported vector element width in sar");
			break;
		}

		return dst;

	default:
		emitter._x86_context.support().assertion_fail("unsupported vector shift");
		return Operand::make_invalid();
	}

	return Operand::make_invalid();
}

Operand X86BinaryOperation::vector_arithmetic_as_operand(X86Emitter& emitter)
{
	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	auto dst = Operand::make_register(dst_reg, 128);

	auto lhs = _lhs->as_operand(emitter);

	if (_kind == X86BinaryOperationKind::AND && _rhs->kind() == X86ValueKind::UNARY_OPERATION && ((X86UnaryOperation *) _rhs)->kind() == X86UnaryOperationKind::NOT) {
		auto rhsv = ((X86UnaryOperation *) _rhs)->value()->as_operand(emitter);
		if (lhs.is_reg()) {
			assert(lhs.reg.reg.is_sse());
			lhs.reg.width = 128;
		} else if (lhs.is_mem()) {
			lhs.mem.access_width = 128;
		} else {
			assert(false);
		}

		emitter.add_mov_auto(rhsv, dst);
		emitter.add_instruction(InstructionKind::PANDN, lhs, dst);
		return Operand::make_register(dst_reg, type().size_in_bits());
	}

	auto rhs = _rhs->as_operand(emitter);

	if (rhs.is_reg()) {
		assert(rhs.reg.reg.is_sse());
		rhs.reg.width = 128;
	} else if (rhs.is_mem()) {
		rhs.mem.access_width = 128;
	} else {
		assert(false);
	}

	switch (_kind) {
	case X86BinaryOperationKind::ADD:
		emitter.add_mov_auto(lhs, dst);

		switch (type().vector_element_size_in_bits()) {
		case 8: emitter.add_instruction(InstructionKind::PADDB, rhs, dst);
			break;
		case 16: emitter.add_instruction(InstructionKind::PADDW, rhs, dst);
			break;
		case 32: emitter.add_instruction(InstructionKind::PADDD, rhs, dst);
			break;
		case 64: emitter.add_instruction(InstructionKind::PADDQ, rhs, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported vector element width in add");
			break;
		}

		return Operand::make_register(dst_reg, type().size_in_bits());

	case X86BinaryOperationKind::SUB:
		emitter.add_mov_auto(lhs, dst);

		if (type().is_floating()) {
			switch (type().vector_element_size_in_bits()) {
			case 32: emitter.add_instruction(InstructionKind::SUBPS, rhs, dst);
				break;
			case 64: emitter.add_instruction(InstructionKind::SUBPD, rhs, dst);
				break;
			default: emitter._x86_context.support().assertion_fail("unsupported fp vector element width in sub");
				break;
			}
		} else {
			switch (type().vector_element_size_in_bits()) {
			case 8: emitter.add_instruction(InstructionKind::PSUBB, rhs, dst);
				break;
			case 16: emitter.add_instruction(InstructionKind::PSUBW, rhs, dst);
				break;
			case 32: emitter.add_instruction(InstructionKind::PSUBD, rhs, dst);
				break;
			case 64: emitter.add_instruction(InstructionKind::PSUBQ, rhs, dst);
				break;
			default: emitter._x86_context.support().assertion_fail("unsupported vector element width in sub");
				break;
			}
		}

		return Operand::make_register(dst_reg, type().size_in_bits());

	case X86BinaryOperationKind::AND:
		emitter.add_mov_auto(lhs, dst);
		emitter.add_instruction(InstructionKind::PAND, rhs, dst);
		return Operand::make_register(dst_reg, type().size_in_bits());

	case X86BinaryOperationKind::OR:
		emitter.add_mov_auto(lhs, dst);
		emitter.add_instruction(InstructionKind::POR, rhs, dst);
		return Operand::make_register(dst_reg, type().size_in_bits());

	case X86BinaryOperationKind::XOR:
		emitter.add_mov_auto(lhs, dst);
		emitter.add_instruction(InstructionKind::PXOR, rhs, dst);
		return Operand::make_register(dst_reg, type().size_in_bits());

	case X86BinaryOperationKind::MUL:
		if (type().is_floating()) {
			emitter.add_mov_auto(lhs, dst);
			if (type().vector_element_size_in_bits() == 32) {
				emitter.add_instruction(InstructionKind::MULPS, rhs, dst);
			} else {
				emitter.add_instruction(InstructionKind::MULPD, rhs, dst);
			}
			return Operand::make_register(dst_reg, type().size_in_bits());
		} else {

			switch (type().vector_element_size_in_bits()) {
			case 8:
			{
				auto t1 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				auto t1r = Operand::make_register(t1, 128);
				auto t2 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				auto t2r = Operand::make_register(t2, 128);
				auto t3 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				auto t3r = Operand::make_register(t3, 128);
				auto t4 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				auto t4r = Operand::make_register(t4, 128);

				emitter.add_mov_auto(lhs, t1r);
				emitter.add_mov_auto(rhs, t2r);
				emitter.add_mov_auto(t1r, t3r);
				emitter.add_mov_auto(t2r, t4r);

				// xmm0 = t1r
				// xmm1 = t3r
				// xmm2 = t2r
				// xmm4 = t4r

				emitter.add_instruction(InstructionKind::PUNPCKLBW, t1r, t3r);
				emitter.add_instruction(InstructionKind::PUNPCKLBW, t2r, t4r);
				emitter.add_instruction(InstructionKind::PUNPCKHBW, t1r, t1r);
				emitter.add_instruction(InstructionKind::PUNPCKHBW, t2r, t2r);

				emitter.add_instruction(InstructionKind::PMULLW, t4r, t3r);
				emitter.add_instruction(InstructionKind::PMULLW, t2r, t1r);

				auto z = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				auto zr = Operand::make_register(z, 128);

				auto tz = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
				auto tzr = Operand::make_register(tz, 64);

				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x00ff00ff00ff00ffull, 64), tzr);
				emitter.add_mov_auto(tzr, zr);
				emitter.add_instruction(InstructionKind::PUNPCKLQDQ, zr, zr);

				emitter.add_instruction(InstructionKind::PAND, zr, t3r);
				emitter.add_instruction(InstructionKind::PAND, zr, t1r);

				emitter.add_mov_auto(t3r, dst);
				emitter.add_instruction(InstructionKind::PACKUSWB, t1r, dst);
				return Operand::make_register(dst_reg, type().size_in_bits());
			}


			case 16:
				emitter.add_mov_auto(lhs, dst);
				emitter.add_instruction(InstructionKind::PMULLW, rhs, dst);
				return Operand::make_register(dst_reg, type().size_in_bits());

			case 32:
				emitter.add_mov_auto(lhs, dst);
				emitter.add_instruction(InstructionKind::PMULLD, rhs, dst);
				return Operand::make_register(dst_reg, type().size_in_bits());

				/*{
					auto t1 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
					auto t1r = Operand::make_register(t1, 128);
					auto t2 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
					auto t2r = Operand::make_register(t2, 128);
					auto t3 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
					auto t3r = Operand::make_register(t3, 128);
					auto t4 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
					auto t4r = Operand::make_register(t4, 128);

					emitter.add_mov_auto(lhs, t1r);
					emitter.add_mov_auto(rhs, t2r);
					emitter.add_mov_auto(t1r, t3r);
					emitter.add_mov_auto(t2r, t4r);

					// xmm0 = t2r
					// xmm1 = t4r
					// xmm2 = t1r
					// xmm3 = t3r

					emitter.add_instruction(InstructionKind::PSRLQ, Operand::make_constant(32, 8), t2r);
					emitter.add_instruction(InstructionKind::PSRLQ, Operand::make_constant(32, 8), t1r);

					emitter.add_instruction(InstructionKind::PMULUDQ, t3r, t4r);
					emitter.add_instruction(InstructionKind::PMULUDQ, t1r, t2r);

					emitter.add_instruction(InstructionKind::PSHUFD, Operand::make_constant(8, 8), t4r, t4r);
					emitter.add_instruction(InstructionKind::PSHUFD, Operand::make_constant(8, 8), t2r, t2r);

					emitter.add_instruction(InstructionKind::PUNPCKLDQ, t2r, t4r);
					emitter.add_mov_auto(t4r, dst);

					return Operand::make_register(dst_reg, type().size_in_bits());
				}*/

			case 64:
				emitter._x86_context.support().assertion_fail("unsupported vector multiply bit size");
				return Operand::make_invalid();
			}
		}

	case X86BinaryOperationKind::DIV:
		if (type().is_floating()) {
			emitter.add_mov_auto(lhs, dst);
			if (type().vector_element_size_in_bits() == 32) {
				emitter.add_instruction(InstructionKind::DIVPS, rhs, dst);
			} else {
				emitter.add_instruction(InstructionKind::DIVPD, rhs, dst);
			}
			return Operand::make_register(dst_reg, type().size_in_bits());
		} else {
			emitter._x86_context.support().assertion_fail("unsupported vector division");
			return Operand::make_invalid();
		}
		
	default:
		emitter._x86_context.support().assertion_fail("unsupported vector binary arithmetic");
		return Operand::make_invalid();
	}

	return Operand::make_invalid();
}

const Type& X86ComparisonOperation::resolve_type(X86Context& ctx, X86ComparisonOperationKind::X86ComparisonOperationKind kind, X86Value* v1, X86Value* v2)
{
	if (v1->type().is_vector()) {
		return v1->type();
	} else {
		return ctx.types().u8();
	}
}

Operand X86ComparisonOperation::as_operand(X86Emitter& emitter)
{
	if (_emitted) {
		return _operand;
	}

	if (_v1->type().is_vector() && ((_v2->type().is_vector() && _v1->type() == _v2->type()) || (!_v2->type().is_vector()))) {
		_operand = vector_comparison(emitter);
	} else if (!_v1->type().is_vector() && !_v2->type().is_vector()) {
		if (_v1->type().is_floating() && _v2->type().is_floating()) {
			_operand = fp_comparison(emitter);
		} else if (_v1->type().is_integer() && _v2->type().is_integer()) {
			_operand = std_comparison(emitter);
		} else {
			emitter._x86_context.support().assertion_fail("unsupported comparison between fp-int types");
			return Operand::make_invalid();
		}
	} else {
		emitter._x86_context.support().assertion_fail("unsupported comparison between types");
		return Operand::make_invalid();
	}

	_emitted = true;
	return _operand;
}

Operand X86ComparisonOperation::fp_comparison(X86Emitter& emitter)
{
	auto op1 = _v1->as_operand(emitter);
	auto op2 = _v2->as_operand(emitter);

	if (op1.is_const()) {
		if (op1.constant.value == 0) {
			auto tmp = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			emitter.add_instruction(InstructionKind::PXOR, Operand::make_register(tmp, 128), Operand::make_register(tmp, 128));
			op1 = Operand::make_register(tmp, 128);
		} else {
			assert(false);
		}
	}

	if (_v1->type().size_in_bits() == 32) {
		emitter.add_instruction(InstructionKind::UCOMISS, op1, op2);
	} else if (_v1->type().size_in_bits() == 64) {
		emitter.add_instruction(InstructionKind::UCOMISD, op1, op2);
	} else {
		emitter._x86_context.support().assertion_fail("unsupported comparison between floating-point sizes");
		return Operand::make_invalid();
	}

	//emitter.add_instruction(InstructionKind::INT, Operand::make_constant(0x90, 8));

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto dst = Operand::make_register(dst_reg, type().size_in_bits());

	bool invert_inequality = true;
	switch (_kind) {
	case X86ComparisonOperationKind::EQ: emitter.add_instruction(InstructionKind::SETE, dst);
		break;
	case X86ComparisonOperationKind::NE: emitter.add_instruction(InstructionKind::SETNE, dst);
		break;
	case X86ComparisonOperationKind::GT: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETA, dst);
		else emitter.add_instruction(InstructionKind::SETNA, dst);
		break;
	case X86ComparisonOperationKind::GE: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETAE, dst);
		else emitter.add_instruction(InstructionKind::SETNAE, dst);
		break;
	case X86ComparisonOperationKind::LT: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETB, dst);
		else emitter.add_instruction(InstructionKind::SETNB, dst);
		break;
	case X86ComparisonOperationKind::LE: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETBE, dst);
		else emitter.add_instruction(InstructionKind::SETNBE, dst);
		break;
	default: emitter._x86_context.support().assertion_fail("unsupported comparison type");
		return Operand::make_invalid();
	}

	return dst;
}

Operand X86ComparisonOperation::std_comparison(X86Emitter& emitter)
{
	auto op1 = _v1->as_operand(emitter);
	auto op2 = _v2->as_operand(emitter);

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto dst = Operand::make_register(dst_reg, type().size_in_bits());

	bool invert_inequality = false;
	switch (op1.kind) {
	case OperandKind::REGISTER:
		switch (op2.kind) {
		case OperandKind::REGISTER:
			// cmp reg, reg
			emitter.add_instruction(InstructionKind::CMP, op1, op2);
			break;

		case OperandKind::MEMORY:
			// cmp reg, mem
			emitter.add_instruction(InstructionKind::CMP, op1, op2);
			break;

		case OperandKind::CONSTANT:
			// cmp reg, const
			emitter.add_instruction(InstructionKind::CMP, op2, op1);
			//invert_inequality = true;
			break;

		default:
			emitter._x86_context.support().assertion_fail("comparison reg -- ???");
			return Operand::make_invalid();
		}
		break;

	case OperandKind::CONSTANT:
		switch (op2.kind) {
		case OperandKind::REGISTER:
			// cmp const, reg
			assert(false);
			emitter.add_instruction(InstructionKind::CMP, op1, op2);
			invert_inequality = true;
			break;
		case OperandKind::MEMORY:
			// cmp const, mem
			assert(false);
			emitter.add_instruction(InstructionKind::CMP, op1, op2);
			break;
		case OperandKind::CONSTANT:
			// cmp const, const
			emitter._x86_context.support().assertion_fail("comparison const -- const");
			return Operand::make_invalid();
		default:
			emitter._x86_context.support().assertion_fail("comparison const -- ???");
			return Operand::make_invalid();
		}
		break;

	case OperandKind::MEMORY:
		switch (op2.kind) {
		case OperandKind::REGISTER:
			// cmp mem, reg
			emitter.add_instruction(InstructionKind::CMP, op1, op2);
			break;

		case OperandKind::CONSTANT:
			// cmp mem, const
			emitter.add_instruction(InstructionKind::CMP, op2, op1);
			invert_inequality = true;
			break;

		case OperandKind::MEMORY:
			// cmp mem, mem
			emitter.add_mov_auto(op1, Operand::make_register(dst.reg.reg, op1.mem.access_width));
			emitter.add_instruction(InstructionKind::CMP, op2, Operand::make_register(dst.reg.reg, op1.mem.access_width));
			break;

		default:
			emitter._x86_context.support().assertion_fail("comparison mem -- ???");
			return Operand::make_invalid();
		}
		break;

	default:
		emitter._x86_context.support().assertion_fail("comparison ??? -- ???");
		return Operand::make_invalid();
	}

	if (_v1->type().is_signed()) {
		switch (_kind) {
		case X86ComparisonOperationKind::EQ: emitter.add_instruction(InstructionKind::SETE, dst);
			break;
		case X86ComparisonOperationKind::NE: emitter.add_instruction(InstructionKind::SETNE, dst);
			break;
		case X86ComparisonOperationKind::GT: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETG, dst);
			else emitter.add_instruction(InstructionKind::SETNG, dst);
			break;
		case X86ComparisonOperationKind::GE: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETGE, dst);
			else emitter.add_instruction(InstructionKind::SETNGE, dst);
			break;
		case X86ComparisonOperationKind::LT: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETL, dst);
			else emitter.add_instruction(InstructionKind::SETNL, dst);
			break;
		case X86ComparisonOperationKind::LE: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETLE, dst);
			else emitter.add_instruction(InstructionKind::SETNLE, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported comparison type");
			return Operand::make_invalid();
		}
	} else {
		switch (_kind) {
		case X86ComparisonOperationKind::EQ: emitter.add_instruction(InstructionKind::SETE, dst);
			break;
		case X86ComparisonOperationKind::NE: emitter.add_instruction(InstructionKind::SETNE, dst);
			break;
		case X86ComparisonOperationKind::GT: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETA, dst);
			else emitter.add_instruction(InstructionKind::SETNA, dst);
			break;
		case X86ComparisonOperationKind::GE: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETAE, dst);
			else emitter.add_instruction(InstructionKind::SETNAE, dst);
			break;
		case X86ComparisonOperationKind::LT: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETB, dst);
			else emitter.add_instruction(InstructionKind::SETNB, dst);
			break;
		case X86ComparisonOperationKind::LE: if (!invert_inequality) emitter.add_instruction(InstructionKind::SETBE, dst);
			else emitter.add_instruction(InstructionKind::SETNBE, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported comparison type");
			return Operand::make_invalid();
		}
	}

	return dst;
}

Operand X86ComparisonOperation::vector_comparison(X86Emitter& emitter)
{
	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	auto dst = Operand::make_register(dst_reg, 128);

	auto v1 = _v1->as_operand(emitter);
	auto v2 = _v2->as_operand(emitter);

	if (v2.kind == OperandKind::REGISTER) {
		v2.reg.width = 128;
	}

	if (v1.kind == OperandKind::REGISTER) {
		v1.reg.width = 128;
	}

	/*if (v2.is_const()) {
		if (v2.constant.value == 0) {
			emitter.add_instruction(InstructionKind::PXOR, dst, dst);
		} else {
			emitter._x86_context.support().assertion_fail("unsupported vector comparison with constant"); 
			return Operand::make_invalid();
		}
	} else {
		emitter.add_mov_auto(v2, dst);
	}*/



	switch (_kind) {
	case X86ComparisonOperationKind::EQ:
		emitter.add_mov_auto(v1, dst);
		switch (type().vector_element_size_in_bits()) {
		case 8: emitter.add_instruction(InstructionKind::PCMPEQB, v2, dst);
			break;
		case 16: emitter.add_instruction(InstructionKind::PCMPEQW, v2, dst);
			break;
		case 32: emitter.add_instruction(InstructionKind::PCMPEQD, v2, dst);
			break;
		case 64: emitter.add_instruction(InstructionKind::PCMPEQQ, v2, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported vector element width in cmpeq");
			return Operand::make_invalid();
		}
		break;

	case X86ComparisonOperationKind::NE:
	{
		emitter.add_mov_auto(v1, dst);
		switch (type().vector_element_size_in_bits()) {
		case 8: emitter.add_instruction(InstructionKind::PCMPEQB, v2, dst);
			break;
		case 16: emitter.add_instruction(InstructionKind::PCMPEQW, v2, dst);
			break;
		case 32: emitter.add_instruction(InstructionKind::PCMPEQD, v2, dst);
			break;
		case 64: emitter.add_instruction(InstructionKind::PCMPEQQ, v2, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported vector element width in cmpeq");
			return Operand::make_invalid();
		}

		auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
		auto tmp = Operand::make_register(tmp_reg, 128);

		emitter.add_instruction(InstructionKind::PCMPEQD, tmp, tmp);
		emitter.add_instruction(InstructionKind::PXOR, tmp, dst);
		break;
	}

	case X86ComparisonOperationKind::GE:
	case X86ComparisonOperationKind::LT:
	{
		auto t = v1;
		v1 = v2;
		v2 = t;
	}
	case X86ComparisonOperationKind::LE:
	case X86ComparisonOperationKind::GT:
		emitter.add_mov_auto(v1, dst);

		if (!type().element_type().is_signed()) {
			// splat p into vector

			auto const_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			auto const_num = Operand::make_register(const_reg, 64);

			auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto tmp = Operand::make_register(tmp_reg, 128);

			switch (type().vector_element_size_in_bits()) {
			case 8:
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8080808080808080ull, 64), const_num);
				break;

			case 16:
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8000800080008000ull, 64), const_num);
				break;

			case 32:
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8000000080000000ull, 64), const_num);
				break;

			case 64:
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8000000000000000ull, 64), const_num);
				break;

			default: emitter._x86_context.support().assertion_fail("unsupported vector element width in cmpgt");
				return Operand::make_invalid();
			}

			emitter.add_mov_auto(const_num, tmp);
			emitter.add_instruction(InstructionKind::PUNPCKLQDQ, tmp, tmp);

			auto tmp2_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto tmp2 = Operand::make_register(tmp2_reg, 128);

			emitter.add_mov_auto(v2, tmp2);

			emitter.add_instruction(InstructionKind::PXOR, tmp, tmp2);
			emitter.add_instruction(InstructionKind::PXOR, tmp, dst);

			v2 = tmp2;
		}

		switch (type().vector_element_size_in_bits()) {
		case 8: emitter.add_instruction(InstructionKind::PCMPGTB, v2, dst);
			break;
		case 16: emitter.add_instruction(InstructionKind::PCMPGTW, v2, dst);
			break;
		case 32: emitter.add_instruction(InstructionKind::PCMPGTD, v2, dst);
			break;
		case 64: emitter.add_instruction(InstructionKind::PCMPGTQ, v2, dst);
			break;
		default: emitter._x86_context.support().assertion_fail("unsupported vector element width in cmpgt");
			return Operand::make_invalid();
		}

		switch (_kind) {
		case X86ComparisonOperationKind::GE:
		case X86ComparisonOperationKind::LE:
		{
			auto const_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto const_num = Operand::make_register(const_reg, 128);
			emitter.add_instruction(InstructionKind::PCMPEQD, const_num, const_num);
			emitter.add_instruction(InstructionKind::PXOR, const_num, dst);

			break;
		}
		}

		//emitter.dump();
		break;

	default:
		emitter._x86_context.support().assertion_fail("unsupported vector comparison kind");
		return Operand::make_invalid();
	}

	return Operand::make_register(dst_reg, type().size_in_bits());
}

Operand X86PCRegister::as_operand(X86Emitter& emitter)
{
	return Operand::make_register(X86Registers::R15);
}

Operand X86LocalVariable::as_operand(X86Emitter& emitter)
{
	if (_reg.is_sse()) {
		return Operand::make_register(_reg, 128);
	} else {
		return Operand::make_register(_reg, type().size_in_bits());
	}
}

Operand X86GuestRegister::as_operand(X86Emitter& emitter)
{
#ifdef CACHED_GREGS
	if (_cached) {
		return _cached_operand;
	}

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(type().is_floating() || type().is_vector() ? X86RegisterClasses::SSE : X86RegisterClasses::GENERAL_PURPOSE);
	_cached_operand = Operand::make_register(dst_reg, type().is_floating() || type().is_vector() ? 128 : type().size_in_bits());

	emitter.add_mov_auto(Operand::make_mem(type().size_in_bits(), 64, X86PhysicalRegisters::BP, _offset), _cached_operand);
	_cached = true;

	return _cached_operand;
#else
	return Operand::make_mem(type().size_in_bits(), 64, X86PhysicalRegisters::BP, _offset);
#endif
}

Operand X86Cast::as_operand(X86Emitter& emitter)
{
	if (!_emitted) {
		_operand = generate(emitter);
		_emitted = true;
	}

	return _operand;
}

Operand X86Cast::generate(X86Emitter& emitter)
{
	switch (_kind) {
	case X86CastKind::ZX:
	{
		auto src = _value->as_operand(emitter);
		auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		auto dst = Operand::make_register(dst_reg, type().size_in_bits());

		if (src.kind == OperandKind::REGISTER) {
			emitter.add_instruction(InstructionKind::MOVZX, src, dst);
			return dst;
		} else if (src.kind == OperandKind::MEMORY) {
			if (src.mem.access_width > 32) {
				emitter._x86_context.support().assertion_fail("zx from memory invalid size");
				return Operand::make_invalid();
			} else {
				emitter.add_instruction(InstructionKind::MOVZX, src, dst);
				return dst;
			}
		} else {
			emitter.add_instruction(InstructionKind::MOVZX, src, dst);
			return dst;
		}
	}

	case X86CastKind::SX:
	{
		auto src = _value->as_operand(emitter);
		auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		auto dst = Operand::make_register(dst_reg, type().size_in_bits());

		emitter.add_instruction(InstructionKind::MOVSX, src, dst);
		return dst;
	}

	case X86CastKind::TRUNCATE:
	case X86CastKind::REINTERPRET:
	{
		auto value_operand = _value->as_operand(emitter);
		auto dst_reg = emitter.vreg_allocator().alloc_vreg(type().is_vector() ? X86RegisterClasses::SSE : X86RegisterClasses::GENERAL_PURPOSE);
		auto dst = Operand::make_register(dst_reg, type().size_in_bits());

		// TODO: Think about this -- can we get away with simply returning the appropriately sized register?

		if (_value->type().is_vector() && type().is_vector() && _kind == X86CastKind::TRUNCATE && _value->type().vector_element_size_in_bits() > type().vector_element_size_in_bits()) {
			/*// Vector narrowing operation
			
			auto zero_tmp = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto zero_op = Operand::make_register(zero_tmp, 128);
			
			emitter.add_instruction(InstructionKind::PXOR, zero_op, zero_op);
			
			switch (_value->type().vector_element_size_in_bits()) {
			case 32:
			{
				assert(_type().vector_element_size_in_bits() == 16);
				// packssdw
				break;
			}
			
			case 16:
			{
				assert(_type().vector_element_size_in_bits() == 8);
				// packsswb
				break;
			}
			
			default: assert(false);
			}*/
		} else {
			if (value_operand.is_reg()) {
				if (_kind == X86CastKind::TRUNCATE) {
					emitter.add_mov_auto(value_operand, Operand::make_register(dst_reg, _value->type().size_in_bits()));
				} else if (_kind == X86CastKind::REINTERPRET) {
					if (_value->type().is_vector() && type().is_vector()) {
						emitter.add_mov_auto(Operand::make_register(value_operand.reg.reg, 128), Operand::make_register(dst_reg, 128));
					} else {
						if (value_operand.reg.width != dst.reg.width) {
							assert(false);
							emitter._x86_context.support().assertion_fail("reinterpret cast with different operand widths");
							return Operand::make_invalid();
						}

						emitter.add_mov_auto(value_operand, dst);
					}
				} else {
					emitter._x86_context.support().assertion_fail("unsupported cast type");
					return Operand::make_invalid();
				}
			} else if (value_operand.is_const() && dst_reg.regclass() != X86RegisterClasses::SSE) {
				emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(value_operand.constant.value, dst.reg.width), dst);
			} else if (value_operand.is_mem() && dst_reg.regclass() != X86RegisterClasses::SSE) {
				Operand mem = value_operand;
				mem.mem.access_width = type().size_in_bits();
				emitter.add_instruction(InstructionKind::MOV, mem, dst);
			} else if (value_operand.is_mem() && dst_reg.regclass() == X86RegisterClasses::SSE) {
				// Reinterpret MEM -> SSE
				Operand mem = value_operand;
				mem.mem.access_width = type().size_in_bits();
				emitter.add_mov_auto(mem, dst);
			} else {
				emitter._x86_context.support().assertion_fail("truncate/reinterpret of unsupported operand");
				return Operand::make_invalid();
			}
		}

		return dst;
	}

	case X86CastKind::CONVERT:
		if (_value->type().is_vector() || type().is_vector()) {
			emitter._x86_context.support().assertion_fail("vector conversions not supported");
			return Operand::make_invalid();
		} else if (_value->type().is_floating() && type().is_integer()) {
			// Float -> Int
			return convert_float_to_int(emitter);
		} else if (_value->type().is_integer() && type().is_floating()) {
			// Int -> Float

			auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto dst = Operand::make_register(dst_reg, 128);

			emitter.add_instruction(InstructionKind::PXOR, dst, dst);

			if (_value->type().is_signed()) {
				// Signed Int -> Float
				switch (type().size_in_bits()) {
				case 32:
					switch (_value->type().size_in_bits()) {
					case 32:
					case 64:
						// s32 -> f32
						// s64 -> f32

						emitter.add_instruction(InstructionKind::CVTSI2SS, _value->as_operand(emitter), dst);
						return dst;

					default:
						emitter._x86_context.support().assertion_fail("unsupported int size in signed int->float");
						return Operand::make_invalid();
					}

				case 64:
					switch (_value->type().size_in_bits()) {
					case 32:
					case 64:
						// s32 -> f64
						// s64 -> f64
						emitter.add_instruction(InstructionKind::CVTSI2SD, _value->as_operand(emitter), dst);
						return dst;

					default:
						emitter._x86_context.support().assertion_fail("unsupported int size in signed int->float");
						return Operand::make_invalid();
					}

				default:
					emitter._x86_context.support().assertion_fail("unsupported float size in signed int->float");
					return Operand::make_invalid();
				}
			} else {
				// Unsigned Int -> Float
				switch (type().size_in_bits()) {
				case 32:
					switch (_value->type().size_in_bits()) {
					case 32:
						// u32 -> f32
					{
						auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
						emitter.add_mov_auto(_value->as_operand(emitter), Operand::make_register(tmp_reg, 32));
						emitter.add_instruction(InstructionKind::CVTSI2SS, Operand::make_register(tmp_reg, 64), dst);

						return dst;
					}

					case 64:
						// u64 -> f32
						/* test     %rdi,%rdi
						   js       1f
						   pxor     %xmm0,%xmm0
						   cvtsi2ss %rdi,%xmm0
						   jmp      2f   
						1: mov      %rdi,%rax
						   pxor     %xmm0,%xmm0
						   shr      %rax
						   and      $0x1,%edi
						   or       %rdi,%rax
						   cvtsi2ss %rax,%xmm0
						   addss    %xmm0,%xmm0
						 2:
						 */

					{
						auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
						auto tmp64 = Operand::make_register(tmp_reg, 64);

						emitter.add_mov_auto(_value->as_operand(emitter), tmp64);
						emitter.add_instruction(InstructionKind::TEST, tmp64, tmp64);
						auto js = emitter.add_instruction(InstructionKind::JS);
						emitter.add_instruction(InstructionKind::CVTSI2SS, tmp64, dst);
						auto jmp = emitter.add_instruction(InstructionKind::JMP);

						auto sgn = emitter.add_instruction(InstructionKind::LABEL);
						js->set_operand(0, Operand::make_label(sgn));

						auto tmp_reg2 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
						auto tmp32 = Operand::make_register(tmp_reg, 32);
						auto tmp64_2 = Operand::make_register(tmp_reg2, 64);

						emitter.add_instruction(InstructionKind::MOV, tmp64, tmp64_2);
						emitter.add_instruction(InstructionKind::SHR, Operand::make_constant(1, 8), tmp64_2);
						emitter.add_instruction(InstructionKind::AND, Operand::make_constant(1, 32), tmp32);
						emitter.add_instruction(InstructionKind::OR, tmp64, tmp64_2);
						emitter.add_instruction(InstructionKind::CVTSI2SS, tmp64_2, dst);
						emitter.add_instruction(InstructionKind::ADDSS, dst, dst);

						auto finish = emitter.add_instruction(InstructionKind::LABEL);
						jmp->set_operand(0, Operand::make_label(finish));

						return dst;
					}

					default:
						emitter._x86_context.support().assertion_fail("unsupported int size in unsigned int->float");
						return Operand::make_invalid();
					}

				case 64:
					switch (_value->type().size_in_bits()) {
					case 32:
						// u32 -> f64
					{
						auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
						emitter.add_mov_auto(_value->as_operand(emitter), Operand::make_register(tmp_reg, 32));
						emitter.add_instruction(InstructionKind::CVTSI2SD, Operand::make_register(tmp_reg, 64), dst);

						return dst;
					}

					case 64:
					{
						// u64 -> f64

						/* test   %rdi,%rdi
						   js     80 <cvt_u64_f64+0x10>
						   pxor   %xmm0,%xmm0
						   cvtsi2sd %rdi,%xmm0
						   retq   
						   nop
						   mov    %rdi,%rax
						   pxor   %xmm0,%xmm0
						   shr    %rax
						   and    $0x1,%edi
						   or     %rdi,%rax
						   cvtsi2sd %rax,%xmm0
						   addsd  %xmm0,%xmm0
						   retq   
						   nopw   0x0(%rax,%rax,1)
						 */

						auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
						auto tmp64 = Operand::make_register(tmp_reg, 64);

						emitter.add_mov_auto(_value->as_operand(emitter), tmp64);
						emitter.add_instruction(InstructionKind::TEST, tmp64, tmp64);
						auto js = emitter.add_instruction(InstructionKind::JS);
						emitter.add_instruction(InstructionKind::CVTSI2SD, tmp64, dst);
						auto jmp = emitter.add_instruction(InstructionKind::JMP);

						auto sgn = emitter.add_instruction(InstructionKind::LABEL);
						js->set_operand(0, Operand::make_label(sgn));

						auto tmp_reg2 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
						auto tmp32 = Operand::make_register(tmp_reg, 32);
						auto tmp64_2 = Operand::make_register(tmp_reg2, 64);

						emitter.add_instruction(InstructionKind::MOV, tmp64, tmp64_2);
						emitter.add_instruction(InstructionKind::SHR, Operand::make_constant(1, 8), tmp64_2);
						emitter.add_instruction(InstructionKind::AND, Operand::make_constant(1, 32), tmp32);
						emitter.add_instruction(InstructionKind::OR, tmp64, tmp64_2);
						emitter.add_instruction(InstructionKind::CVTSI2SD, tmp64_2, dst);
						emitter.add_instruction(InstructionKind::ADDSD, dst, dst);

						auto finish = emitter.add_instruction(InstructionKind::LABEL);
						jmp->set_operand(0, Operand::make_label(finish));

						return dst;
					}

					default:
						emitter._x86_context.support().assertion_fail("unsupported int size in unsigned int->float");
						return Operand::make_invalid();
					}

				default:
					emitter._x86_context.support().assertion_fail("unsupported float size in unsigned int->float");
					return Operand::make_invalid();
				}
			}
		} else if (_value->type().is_floating() && type().is_floating()) {
			auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto dst = Operand::make_register(dst_reg, 128);

			emitter.add_instruction(InstructionKind::PXOR, dst, dst);

			switch (_value->type().size_in_bits()) {
			case 32:
				switch (type().size_in_bits()) {
				case 64:
					// f32 -> f64
					emitter.add_instruction(InstructionKind::CVTSS2SD, _value->as_operand(emitter), dst);
					return dst;

				case 128:
				{
					// f32 -> f80		
					/*auto scratch32 = Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x108);
					auto scratch80 = Operand::make_mem(80, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x108);
								
					emitter.add_mov_auto(_value->as_operand(emitter), scratch32);
					emitter.add_instruction(InstructionKind::FLD, scratch32);
					emitter.add_instruction(InstructionKind::FSTP, scratch80);
					emitter.add_mov_auto(scratch80, dst);
					
					return dst;*/
					emitter._x86_context.support().assertion_fail("unsupported f32 -> f80 precision cast");
					return Operand::make_invalid();
				}

				default:
					emitter._x86_context.support().assertion_fail("unsupported f32 precision cast");
					return Operand::make_invalid();
				}

			case 64:
				switch (type().size_in_bits()) {
				case 32:
					// f64 -> f32
					emitter.add_instruction(InstructionKind::CVTSD2SS, _value->as_operand(emitter), dst);
					return dst;

				case 128:
					// f64 -> f80
					emitter._x86_context.support().assertion_fail("unsupported f64 -> f80 precision cast");
					return Operand::make_invalid();

				default:
					emitter._x86_context.support().assertion_fail("unsupported f64 precision cast");
					return Operand::make_invalid();
				}

			case 128:
				switch (type().size_in_bits()) {
				case 32:
					// f80 -> f32
					emitter._x86_context.support().assertion_fail("unsupported f80 -> f32 precision cast");
					return Operand::make_invalid();
					break;

				case 64:
					// f80 -> f64
					emitter._x86_context.support().assertion_fail("unsupported f80 -> f64 precision cast");
					return Operand::make_invalid();

				default:
					emitter._x86_context.support().assertion_fail("unsupported f80 precision cast");
					return Operand::make_invalid();
				}

			default:
				emitter._x86_context.support().assertion_fail("unsupported precision cast");
				return Operand::make_invalid();
			}
		} else {
			emitter._x86_context.support().assertion_fail("unsupported conversion cast");
			return Operand::make_invalid();
		}

	case X86CastKind::SPLAT:
	{
		assert(type().is_vector());

		switch (type().vector_element_size_in_bits()) {
		case 8:
		{
			auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto dst = Operand::make_register(dst_reg, 128);

			emitter.add_mov_auto(_value->as_operand(emitter), dst);
			emitter.add_instruction(InstructionKind::PUNPCKLBW, dst, dst);
			emitter.add_instruction(InstructionKind::PUNPCKLWD, dst, dst);
			emitter.add_instruction(InstructionKind::PSHUFD, Operand::make_constant(0, 8), dst, dst);

			return dst;
		}

		case 16:
		{
			auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto dst = Operand::make_register(dst_reg, 128);

			emitter.add_mov_auto(_value->as_operand(emitter), dst);
			emitter.add_instruction(InstructionKind::PUNPCKLWD, dst, dst);
			emitter.add_instruction(InstructionKind::PSHUFD, Operand::make_constant(0, 8), dst, dst);

			return dst;
		}

		case 32:
		{
			auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto dst = Operand::make_register(dst_reg, 128);

			emitter.add_mov_auto(_value->as_operand(emitter), dst);
			emitter.add_instruction(InstructionKind::PSHUFD, Operand::make_constant(0, 8), dst, dst);

			return dst;
		}

		case 64:
		{
			auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
			auto dst = Operand::make_register(dst_reg, 128);

			emitter.add_mov_auto(_value->as_operand(emitter), dst);
			emitter.add_instruction(InstructionKind::PUNPCKLQDQ, dst, dst);

			return dst;
		}

		default:
			emitter._x86_context.support().assertion_fail("unsupported splat size");
			return Operand::make_invalid();
		}

		/*auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
		auto tmp = Operand::make_register(tmp_reg, 128);

		auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
		auto dst = Operand::make_register(dst_reg, 128);

		emitter.add_mov_auto(_value->as_operand(emitter), dst);
		emitter.add_instruction(InstructionKind::PSHUFD)

		return dst;*/
	}

	default:
		emitter._x86_context.support().assertion_fail("unsupported cast kind");
		return Operand::make_invalid();
	}
}

Operand X86Operand::as_operand(X86Emitter& emitter)
{
	return _operand;
}

Operand X86Cast::convert_float_to_int(X86Emitter& emitter)
{
	// f{32,64} -> {u,s}{32,64}

	Operand incoming_value_operand = _value->as_operand(emitter);

	auto value_tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	Operand value_operand = Operand::make_register(value_tmp_reg, 128);
	emitter.add_mov_auto(incoming_value_operand, value_operand);

	emitter.add_instruction(InstructionKind::UCOMISS, value_operand, value_operand);
	auto jnp_if_not_nan = emitter.add_instruction(InstructionKind::JNP); // Jump if NaN

	auto clear_reg = emitter.add_instruction(InstructionKind::XOR);
	auto jmp_to_done = emitter.add_instruction(InstructionKind::JMP);

	auto not_a_nan = emitter.add_instruction(InstructionKind::LABEL); // Not a NaN
	jnp_if_not_nan->set_operand(0, Operand::make_label(not_a_nan));

	Operand ret;
	switch (value()->type().size_in_bits()) {
	case 32:
		ret = convert_float32_to_int(emitter, value_operand);
		break;
	case 64:
		ret = convert_float64_to_int(emitter, value_operand);
		break;
	default:
		emitter._x86_context.support().assertion_fail("unsupported float size in float -> int");
		return Operand::make_invalid();
	}

	auto done = emitter.add_instruction(InstructionKind::LABEL); // Done
	jmp_to_done->set_operand(0, Operand::make_label(done));

	clear_reg->set_operand(0, ret);
	clear_reg->set_operand(1, ret);

	return ret;
}

Operand X86Cast::convert_float32_to_int(X86Emitter& emitter, const Operand& value)
{
	// f32 -> {u,s}{32,64}

	if (type().is_signed()) {
		return convert_float32_to_signed_int(emitter, value);
	} else {
		return convert_float32_to_unsigned_int(emitter, value);
	}
}

Operand X86Cast::convert_float32_to_signed_int(X86Emitter& emitter, const Operand& value)
{
	// f32 -> s{32,64}

	auto tmp_greg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto tmp_sreg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	auto tmp_sreg2 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto dst = Operand::make_register(dst_reg, type().size_in_bits());

	switch (type().size_in_bits()) {
	case 32:
	{
		// f32 -> s32
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x4f000000, 32), Operand::make_register(tmp_greg, 32));
		emitter.add_instruction(InstructionKind::MOVD, Operand::make_register(tmp_greg, 32), Operand::make_register(tmp_sreg, 128));
		emitter.add_instruction(InstructionKind::UCOMISS, Operand::make_register(tmp_sreg, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffff, 32), Operand::make_register(dst_reg, 32));
		auto ja_to_done = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xcf000000, 32), Operand::make_register(tmp_greg, 32));
		emitter.add_instruction(InstructionKind::MOVD, Operand::make_register(tmp_greg, 32), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::UCOMISS, value, Operand::make_register(tmp_sreg2, 128));
		auto ja_to_underflow = emitter.add_instruction(InstructionKind::JA); // Jump to underflow

		emitter.add_instruction(InstructionKind::CVTTSS2SI, value, dst);
		auto jmp_to_done = emitter.add_instruction(InstructionKind::JMP); // Jump to done

		auto underflow_label = emitter.add_instruction(InstructionKind::LABEL); // UNDERFLOW
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x80000000, 32), Operand::make_register(dst_reg, 32));
		auto done_label = emitter.add_instruction(InstructionKind::LABEL); // UNDERFLOW

		ja_to_done->set_operand(0, Operand::make_label(done_label));
		ja_to_underflow->set_operand(0, Operand::make_label(underflow_label));
		jmp_to_done->set_operand(0, Operand::make_label(done_label));

		break;
	}
	case 64:
	{
		// f32 -> s64
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x5f000000, 32), Operand::make_register(tmp_greg, 32));
		emitter.add_instruction(InstructionKind::MOVD, Operand::make_register(tmp_greg, 32), Operand::make_register(tmp_sreg, 128));
		emitter.add_instruction(InstructionKind::UCOMISS, Operand::make_register(tmp_sreg, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffffffff, 64), Operand::make_register(dst_reg, 64));
		auto ja_to_done = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xdf000000, 32), Operand::make_register(tmp_greg, 32));
		emitter.add_instruction(InstructionKind::MOVD, Operand::make_register(tmp_greg, 32), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::UCOMISS, value, Operand::make_register(tmp_sreg2, 128));
		auto ja_to_underflow = emitter.add_instruction(InstructionKind::JA); // Jump to underflow

		emitter.add_instruction(InstructionKind::CVTTSS2SI, value, dst);
		auto jmp_to_done = emitter.add_instruction(InstructionKind::JMP); // Jump to done

		auto underflow_label = emitter.add_instruction(InstructionKind::LABEL); // UNDERFLOW
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8000000000000000, 64), Operand::make_register(dst_reg, 64));
		auto done_label = emitter.add_instruction(InstructionKind::LABEL); // UNDERFLOW

		ja_to_done->set_operand(0, Operand::make_label(done_label));
		ja_to_underflow->set_operand(0, Operand::make_label(underflow_label));
		jmp_to_done->set_operand(0, Operand::make_label(done_label));

		break;
	}
	default:
		emitter._x86_context.support().assertion_fail("unsupported int size in f32 -> sint");
		return Operand::make_invalid();
	}

	return dst;
}

Operand X86Cast::convert_float32_to_unsigned_int(X86Emitter& emitter, const Operand& value)
{
	// f32 -> u{32,64}

	auto tmp_greg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto tmp_sreg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	auto tmp_sreg2 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto dst = Operand::make_register(dst_reg, type().size_in_bits());

	switch (type().size_in_bits()) {
	case 32:
	{
		// f32 -> u32
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x4f800000, 32), Operand::make_register(tmp_greg, 32));
		emitter.add_instruction(InstructionKind::MOVD, Operand::make_register(tmp_greg, 32), Operand::make_register(tmp_sreg, 128));
		emitter.add_instruction(InstructionKind::UCOMISS, Operand::make_register(tmp_sreg, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xffffffff, 32), Operand::make_register(dst_reg, 32));
		auto ja_to_done1 = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::PXOR, Operand::make_register(tmp_sreg2, 128), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::XOR, Operand::make_register(dst_reg, 32), Operand::make_register(dst_reg, 32));
		emitter.add_instruction(InstructionKind::UCOMISS, value, Operand::make_register(tmp_sreg2, 128));
		auto ja_to_done2 = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::CVTTSS2SI, value, Operand::make_register(dst_reg, 64));

		auto done_label = emitter.add_instruction(InstructionKind::LABEL); // DONE

		ja_to_done1->set_operand(0, Operand::make_label(done_label));
		ja_to_done2->set_operand(0, Operand::make_label(done_label));

		break;
	}
	case 64:
	{
		// f32 -> u64
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x5f800000, 32), Operand::make_register(tmp_greg, 32));
		emitter.add_instruction(InstructionKind::MOVD, Operand::make_register(tmp_greg, 32), Operand::make_register(tmp_sreg, 128));
		emitter.add_instruction(InstructionKind::UCOMISS, Operand::make_register(tmp_sreg, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xffffffffffffffff, 64), Operand::make_register(dst_reg, 64));
		auto ja_to_done1 = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::PXOR, Operand::make_register(tmp_sreg2, 128), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::XOR, Operand::make_register(dst_reg, 32), Operand::make_register(dst_reg, 32));
		emitter.add_instruction(InstructionKind::UCOMISS, value, Operand::make_register(tmp_sreg2, 128));
		auto ja_to_done2 = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x5f000000, 32), Operand::make_register(tmp_greg, 32));
		emitter.add_instruction(InstructionKind::MOVD, Operand::make_register(tmp_greg, 32), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::UCOMISS, Operand::make_register(tmp_sreg2, 128), value);
		auto jae_to_fixup = emitter.add_instruction(InstructionKind::JAE); // Jump to fixup

		emitter.add_instruction(InstructionKind::CVTTSS2SI, value, Operand::make_register(dst_reg, 64));
		auto jmp_to_done = emitter.add_instruction(InstructionKind::JMP); // Jump to done

		auto fixup_label = emitter.add_instruction(InstructionKind::LABEL);
		emitter.add_instruction(InstructionKind::SUBSS, Operand::make_register(tmp_sreg2, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8000000000000000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::CVTTSS2SI, value, Operand::make_register(dst_reg, 64));
		emitter.add_instruction(InstructionKind::XOR, Operand::make_register(tmp_greg, 64), Operand::make_register(dst_reg, 64));

		auto done_label = emitter.add_instruction(InstructionKind::LABEL); // DONE

		ja_to_done1->set_operand(0, Operand::make_label(done_label));
		ja_to_done2->set_operand(0, Operand::make_label(done_label));
		jmp_to_done->set_operand(0, Operand::make_label(done_label));
		jae_to_fixup->set_operand(0, Operand::make_label(fixup_label));

		break;
	}
	default:
		emitter._x86_context.support().assertion_fail("unsupported int size in f32 -> uint");
		return Operand::make_invalid();
	}

	return dst;
}

Operand X86Cast::convert_float64_to_int(X86Emitter& emitter, const Operand& value)
{
	if (type().is_signed()) {
		return convert_float64_to_signed_int(emitter, value);
	} else {
		return convert_float64_to_unsigned_int(emitter, value);
	}
}

Operand X86Cast::convert_float64_to_signed_int(X86Emitter& emitter, const Operand& value)
{
	// f64 -> s{32,64}

	auto tmp_greg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto tmp_sreg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	auto tmp_sreg2 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto dst = Operand::make_register(dst_reg, type().size_in_bits());

	switch (type().size_in_bits()) {
	case 32:
	{
		// f64 -> s32
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x41dfffffffc00000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(tmp_greg, 64), Operand::make_register(tmp_sreg, 128));
		emitter.add_instruction(InstructionKind::UCOMISD, Operand::make_register(tmp_sreg, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffff, 32), Operand::make_register(dst_reg, 32));
		auto ja_to_done = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xc1e0000000000000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(tmp_greg, 64), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::UCOMISD, value, Operand::make_register(tmp_sreg2, 128));
		auto ja_to_underflow = emitter.add_instruction(InstructionKind::JA); // Jump to underflow

		emitter.add_instruction(InstructionKind::CVTTSD2SI, value, dst);
		auto jmp_to_done = emitter.add_instruction(InstructionKind::JMP); // Jump to done

		auto underflow_label = emitter.add_instruction(InstructionKind::LABEL); // UNDERFLOW
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x80000000, 32), Operand::make_register(dst_reg, 32));
		auto done_label = emitter.add_instruction(InstructionKind::LABEL); // UNDERFLOW

		ja_to_done->set_operand(0, Operand::make_label(done_label));
		ja_to_underflow->set_operand(0, Operand::make_label(underflow_label));
		jmp_to_done->set_operand(0, Operand::make_label(done_label));

		break;
	}
	case 64:
	{
		// f64 -> s64
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x43e0000000000000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(tmp_greg, 64), Operand::make_register(tmp_sreg, 128));
		emitter.add_instruction(InstructionKind::UCOMISD, Operand::make_register(tmp_sreg, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffffffff, 64), Operand::make_register(dst_reg, 64));
		auto ja_to_done = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xc3e0000000000000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(tmp_greg, 64), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::UCOMISD, value, Operand::make_register(tmp_sreg2, 128));
		auto ja_to_underflow = emitter.add_instruction(InstructionKind::JA); // Jump to underflow

		emitter.add_instruction(InstructionKind::CVTTSD2SI, value, dst);
		auto jmp_to_done = emitter.add_instruction(InstructionKind::JMP); // Jump to done

		auto underflow_label = emitter.add_instruction(InstructionKind::LABEL); // UNDERFLOW
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8000000000000000, 64), Operand::make_register(dst_reg, 64));
		auto done_label = emitter.add_instruction(InstructionKind::LABEL); // UNDERFLOW

		ja_to_done->set_operand(0, Operand::make_label(done_label));
		ja_to_underflow->set_operand(0, Operand::make_label(underflow_label));
		jmp_to_done->set_operand(0, Operand::make_label(done_label));

		break;
	}
	default:
		emitter._x86_context.support().assertion_fail("unsupported int size in f32 -> sint");
		return Operand::make_invalid();
	}

	return dst;
}

Operand X86Cast::convert_float64_to_unsigned_int(X86Emitter& emitter, const Operand& value)
{
	// f64 -> u{32,64}

	auto tmp_greg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto tmp_sreg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
	auto tmp_sreg2 = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);

	auto dst_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto dst = Operand::make_register(dst_reg, type().size_in_bits());

	switch (type().size_in_bits()) {
	case 32:
	{
		// f64 -> u32
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x41efffffffe00000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(tmp_greg, 64), Operand::make_register(tmp_sreg, 128));
		emitter.add_instruction(InstructionKind::UCOMISD, Operand::make_register(tmp_sreg, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xffffffff, 32), Operand::make_register(dst_reg, 32));
		auto ja_to_done1 = emitter.add_instruction(InstructionKind::JA); // Jump to done, if value is above max u32

		emitter.add_instruction(InstructionKind::PXOR, Operand::make_register(tmp_sreg2, 128), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::XOR, Operand::make_register(dst_reg, 32), Operand::make_register(dst_reg, 32));
		emitter.add_instruction(InstructionKind::UCOMISD, value, Operand::make_register(tmp_sreg2, 128));
		auto ja_to_cvt = emitter.add_instruction(InstructionKind::JNA); // Jump to convert, if zero is NOT above value

		// TODO: READ MXCSR, OR 1, WRITE MXCSR ------ ALSO DO THIS FOR OTHER UNSIGNED CONVERSIONS!!!!

		emitter.add_instruction(InstructionKind::SUB, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));
		emitter.add_instruction(InstructionKind::STMXCSR, Operand::make_mem(64, 64, X86PhysicalRegisters::SP, 0));
		emitter.add_instruction(InstructionKind::OR, Operand::make_constant(1, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::SP, 0));
		emitter.add_instruction(InstructionKind::LDMXCSR, Operand::make_mem(64, 64, X86PhysicalRegisters::SP, 0));
		emitter.add_instruction(InstructionKind::ADD, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));

		auto jmp_to_done = emitter.add_instruction(InstructionKind::JMP);

		auto cvt_label = emitter.add_instruction(InstructionKind::LABEL); // DO CONVERT
		ja_to_cvt->set_operand(0, Operand::make_label(cvt_label));

		emitter.add_instruction(InstructionKind::CVTTSD2SI, value, Operand::make_register(dst_reg, 64));

		auto done_label = emitter.add_instruction(InstructionKind::LABEL); // DONE

		ja_to_done1->set_operand(0, Operand::make_label(done_label));
		jmp_to_done->set_operand(0, Operand::make_label(done_label));

		break;
	}
	case 64:
	{
		// f64 -> u64
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x43f0000000000000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(tmp_greg, 64), Operand::make_register(tmp_sreg, 128));
		emitter.add_instruction(InstructionKind::UCOMISD, Operand::make_register(tmp_sreg, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0xffffffffffffffff, 64), Operand::make_register(dst_reg, 64));
		auto ja_to_done1 = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::PXOR, Operand::make_register(tmp_sreg2, 128), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::XOR, Operand::make_register(dst_reg, 32), Operand::make_register(dst_reg, 32));
		emitter.add_instruction(InstructionKind::UCOMISD, value, Operand::make_register(tmp_sreg2, 128));
		auto ja_to_done2 = emitter.add_instruction(InstructionKind::JA); // Jump to done

		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x43e0000000000000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::MOVQ, Operand::make_register(tmp_greg, 64), Operand::make_register(tmp_sreg2, 128));
		emitter.add_instruction(InstructionKind::UCOMISD, Operand::make_register(tmp_sreg2, 128), value);
		auto jae_to_fixup = emitter.add_instruction(InstructionKind::JAE); // Jump to fixup

		emitter.add_instruction(InstructionKind::CVTTSD2SI, value, Operand::make_register(dst_reg, 64));
		auto jmp_to_done = emitter.add_instruction(InstructionKind::JMP); // Jump to done

		auto fixup_label = emitter.add_instruction(InstructionKind::LABEL);
		emitter.add_instruction(InstructionKind::SUBSD, Operand::make_register(tmp_sreg2, 128), value);
		emitter.add_instruction(InstructionKind::MOV, Operand::make_constant(0x8000000000000000, 64), Operand::make_register(tmp_greg, 64));
		emitter.add_instruction(InstructionKind::CVTTSD2SI, value, Operand::make_register(dst_reg, 64));
		emitter.add_instruction(InstructionKind::XOR, Operand::make_register(tmp_greg, 64), Operand::make_register(dst_reg, 64));

		auto done_label = emitter.add_instruction(InstructionKind::LABEL); // DONE

		ja_to_done1->set_operand(0, Operand::make_label(done_label));
		ja_to_done2->set_operand(0, Operand::make_label(done_label));
		jmp_to_done->set_operand(0, Operand::make_label(done_label));
		jae_to_fixup->set_operand(0, Operand::make_label(fixup_label));

		break;
	}
	default:
		emitter._x86_context.support().assertion_fail("unsupported int size in f32 -> sint");
		return Operand::make_invalid();
	}

	return dst;
}

Operand X86VectorExtract::as_operand(X86Emitter& emitter)
{
	if (_emitted) return _operand;
	_operand = generate(emitter);
	_emitted = true;

	return _operand;
}

Operand X86VectorExtract::generate(X86Emitter& emitter)
{
	assert(vector()->type().is_vector());

	if (index()->kind() == X86ValueKind::CONSTANT) {
		auto element_index = ((X86Constant *) index())->value();

		if (vector()->kind() == X86ValueKind::GUEST_REGISTER) {
			X86GuestRegister *vector_source = (X86GuestRegister *) vector();

			auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			auto tmp = Operand::make_register(tmp_reg, vector()->type().vector_element_size_in_bits());

			int32_t element_offset = vector_source->offset();
			element_offset += element_index * type().size_in_bits();

			emitter.add_mov_auto(Operand::make_mem(vector()->type().vector_element_size_in_bits(), 64, X86PhysicalRegisters::BP, element_offset), tmp);

			return tmp;
		} else {
			auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			auto tmp = Operand::make_register(tmp_reg, vector()->type().vector_element_size_in_bits());

			auto vector_operand = vector()->as_operand(emitter);

			if (vector_operand.is_mem()) {
				auto vtmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
				emitter.add_mov_auto(vector_operand, Operand::make_register(vtmp_reg, 128));
				vector_operand = Operand::make_register(vtmp_reg, 128);
			}

			assert(vector_operand.is_reg());

			vector_operand.reg.width = 128;

			switch (vector()->type().vector_element_size_in_bits()) {
			case 8:
				emitter.add_instruction(InstructionKind::PEXTRB, Operand::make_constant(element_index, 8), vector_operand, Operand::make_register(tmp_reg, 32));
				break;

			case 16:
				emitter.add_instruction(InstructionKind::PEXTRW, Operand::make_constant(element_index, 8), vector_operand, Operand::make_register(tmp_reg, 32));
				break;

			case 32:
				emitter.add_instruction(InstructionKind::PEXTRD, Operand::make_constant(element_index, 8), vector_operand, Operand::make_register(tmp_reg, 32));
				break;

			case 64:
				emitter.add_instruction(InstructionKind::PEXTRQ, Operand::make_constant(element_index, 8), vector_operand, Operand::make_register(tmp_reg, 64));
				break;

			default:
				assert(false);
			}

			return tmp;
		}
	} else {
		assert(false);
	}
}

Operand X86VectorInsert::as_operand(X86Emitter& emitter)
{
	if (_emitted) return _operand;
	_operand = generate(emitter);
	_emitted = true;

	return _operand;
}

Operand X86VectorInsert::generate(X86Emitter& emitter)
{
	assert(vector()->type().is_vector());

	if (index()->kind() == X86ValueKind::CONSTANT) {
		auto tmp_reg = emitter.vreg_allocator().alloc_vreg(X86RegisterClasses::SSE);
		auto tmp = Operand::make_register(tmp_reg, 128);

		auto element_index = ((X86Constant *) index())->value();
		auto value_operand = value()->as_operand(emitter);

		assert(value_operand.is_reg());

		emitter.add_mov_auto(vector()->as_operand(emitter), tmp);
		switch (vector()->type().vector_element_size_in_bits()) {
		case 8:
			emitter.add_instruction(InstructionKind::PINSRB, Operand::make_constant(element_index, 8), Operand::make_register(value_operand.reg.reg, 32), Operand::make_register(tmp_reg, 128));
			break;

		case 16:
			emitter.add_instruction(InstructionKind::PINSRW, Operand::make_constant(element_index, 8), Operand::make_register(value_operand.reg.reg, 32), Operand::make_register(tmp_reg, 128));
			break;

		case 32:
			emitter.add_instruction(InstructionKind::PINSRD, Operand::make_constant(element_index, 8), Operand::make_register(value_operand.reg.reg, 32), Operand::make_register(tmp_reg, 128));
			break;

		case 64:
			emitter.add_instruction(InstructionKind::PINSRQ, Operand::make_constant(element_index, 8), Operand::make_register(value_operand.reg.reg, 64), Operand::make_register(tmp_reg, 128));
			break;

		default:
			assert(false);
		}

		return tmp;
	} else {
		assert(false);
	}
}

