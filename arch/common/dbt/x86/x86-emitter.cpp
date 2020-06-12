/* SPDX-License-Identifier: MIT */

#include <mmu/host-mmu.h>
#include <mmu/strategy/strategy.h>
#include <dbt/x86/x86-emitter.h>
#include <dbt/x86/x86-context.h>
#include <dbt/x86/x86-block.h>
#include <dbt/x86/x86-value.h>
#include <dbt/dbt.h>
#include <dbt/el/context.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/formatter.h>
#include <printf.h>

#include "cpu.h"

#define UNIMPLEMENTED                                               \
	do                                                              \
	{                                                               \
		dump();                                                     \
		fatal("*** UNIMPLEMENTED %s:%d ***\n", __func__, __LINE__); \
	} while (0)

//#define PDEBUG
//#define CACHED_LOCAL_VARS
//#define CHAINING
//#define CACHED_GREGS

#ifdef PDEBUG
#define DEBUG_EMIT(a...) debug_print(a);
#define DEBUG_EMIT_B(a...) debug_print_b(a);
#else
#define DEBUG_EMIT(a...)
#define DEBUG_EMIT_B(a...)
#endif

using namespace captive::arch::jit;
using namespace captive::arch::jit::x86;
using namespace captive::arch::dbt::el;
using namespace captive::arch::dbt::mc::x86;

extern "C" void cpu_read_device(void *cpu, uint32_t devid, uint32_t reg, uint32_t &val);
extern "C" void cpu_write_device(void *cpu, uint32_t devid, uint32_t reg, uint64_t val);
extern "C" void jit_trace(void *cpu, uint64_t opcode, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4);

extern "C" char block_trampoline_epilogue_normal;
extern "C" char block_trampoline_epilogue_direct_fail;
extern "C" char block_trampoline_epilogue_direct_pred_target_fail;
extern "C" char block_trampoline_epilogue_direct_pred_fallthrough_fail;

#ifdef CONFIG_FORCED_ICACHE_INVALIDATIONS

static void __invalidate_translation(uint64_t addr)
{
	printf("YYY\n");
	captive::arch::CPU::get_active_cpu()->invalidate_translation_phys(addr);

	//printf("INVALIDATE %p\n", addr);
	//fatal("INVALIDATE");
}

static void __invalidate_translations()
{
	printf("XXX\n");
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
}
#endif

enum class fpcls
{
	unclassified,
	zero,
	normal,
	inf,
	qnan,
	snan,
};

static uint64_t extract64(uint64_t raw, int start, int len)
{
	return (raw >> start) & ((1ull << len) - 1ull);
}

struct fpfmt
{
	int exp_size;
	int exp_bias;
	int exp_max;
	int frac_size;
	int frac_shift;
	uint64_t frac_lsb;
	uint64_t frac_lsbm1;
	uint64_t round_mask;
	uint64_t roundeven_mask;
	bool arm_althp;
};

#define DECOMPOSED_BINARY_POINT (64 - 2)
#define DECOMPOSED_IMPLICIT_BIT (1ull << DECOMPOSED_BINARY_POINT)
#define DECOMPOSED_OVERFLOW_BIT (DECOMPOSED_IMPLICIT_BIT << 1)

#define F_EXP 11
#define F_EXP_BIAS (((1 << F_EXP) - 1) >> 1)
#define F_EXP_MAX ((1 << F_EXP) - 1)
#define F_FRAC 52
#define F_FRAC_SHIFT (DECOMPOSED_BINARY_POINT - F_FRAC)

static int clz64(uint64_t a)
{
	if (a)
	{
		return __builtin_clzll(a);
	}
	else
	{
		return 64;
	}
}

struct fprep
{
	uint64_t frac;
	int32_t exp;
	fpcls cls;
	bool sign;

	fprep(uint64_t bits) : frac(extract64(bits, 0, F_FRAC)), exp(extract64(bits, F_FRAC, F_EXP)), cls(fpcls::unclassified), sign(extract64(bits, F_FRAC + F_EXP, 1))
	{
		canonicalize();
	}

	uint64_t raw() const
	{
		return 0;
	}

private:
	void canonicalize()
	{
		if (exp == F_EXP_MAX)
		{
			if (frac == 0)
			{
				cls = fpcls::inf;
			}
			else
			{
				frac <<= F_FRAC_SHIFT;
				cls = fpcls::qnan;
			}
		}
		else if (exp == 0)
		{
			if (likely(frac == 0))
			{
				cls = fpcls::zero;
				/*} else if (status->flush_inputs_to_zero) {
					float_raise(float_flag_input_denormal, status);
					cls = float_class_zero;
					frac = 0;*/
			}
			else
			{
				int shift = clz64(frac) - 1;
				cls = fpcls::normal;
				exp = F_FRAC_SHIFT - F_EXP_BIAS - shift + 1;
				frac <<= shift;
			}
		}
		else
		{
			cls = fpcls::normal;
			exp -= F_EXP_BIAS;
			frac = DECOMPOSED_IMPLICIT_BIT + (frac << F_FRAC_SHIFT);
		}
	}
};

enum class fpr
{
	round_down
};

enum class fpx
{
	invalid = 1
};

struct fpstat
{
	signed char float_detect_tininess;
	fpr float_rounding_mode;
	fpx float_exception_flags;
	signed char floatx80_rounding_precision;
	/* should denormalised results go to zero and set the inexact flag? */
	bool flush_to_zero;
	/* should denormalised inputs go to zero and set the input_denormal flag? */
	bool flush_inputs_to_zero;
	bool default_nan_mode;
	/* not always used -- see snan_bit_is_one() in softfloat-specialize.h */
	bool snan_bit_is_one;
};

static inline bool is_nan(fpcls c)
{
	return c >= fpcls::qnan;
}

static inline bool is_snan(fpcls c)
{
	return c == fpcls::snan;
}

static inline bool is_qnan(fpcls c)
{
	return c == fpcls::qnan;
}

static inline void shift64RightJamming(uint64_t a, int count, uint64_t *zPtr)
{
	uint64_t z;

	if (count == 0)
	{
		z = a;
	}
	else if (count < 64)
	{
		z = (a >> count) | ((a << ((-count) & 63)) != 0);
	}
	else
	{
		z = (a != 0);
	}
	*zPtr = z;
}

static fprep pick_nan(fprep a, fprep b, fpstat *s)
{
	if (is_snan(a.cls) || is_snan(b.cls))
	{
		s->float_exception_flags = (fpx)((int)s->float_exception_flags | (int)fpx::invalid);
	}

	return a;
}

static fprep _sfp_add64(fprep a, fprep b, fpstat *s)
{
	return a;

	bool a_sign = a.sign;
	bool b_sign = b.sign ^ false;

	if (a_sign != b_sign)
	{
		/* Subtraction */

		if (a.cls == fpcls::normal && b.cls == fpcls::normal)
		{
			if (a.exp > b.exp || (a.exp == b.exp && a.frac >= b.frac))
			{
				shift64RightJamming(b.frac, a.exp - b.exp, &b.frac);
				a.frac = a.frac - b.frac;
			}
			else
			{
				shift64RightJamming(a.frac, b.exp - a.exp, &a.frac);
				a.frac = b.frac - a.frac;
				a.exp = b.exp;
				a_sign ^= 1;
			}

			if (a.frac == 0)
			{
				a.cls = fpcls::zero;
				a.sign = s->float_rounding_mode == fpr::round_down;
			}
			else
			{
				int shift = clz64(a.frac) - 1;
				a.frac = a.frac << shift;
				a.exp = a.exp - shift;
				a.sign = a_sign;
			}
			return a;
		}
		if (is_nan(a.cls) || is_nan(b.cls))
		{
			return pick_nan(a, b, s);
		}
		if (a.cls == fpcls::inf)
		{
			if (b.cls == fpcls::inf)
			{
				/*float_raise(float_flag_invalid, s);
				return parts_default_nan(s);*/
			}
			return a;
		}
		if (a.cls == fpcls::zero && b.cls == fpcls::zero)
		{
			a.sign = s->float_rounding_mode == fpr::round_down;
			return a;
		}
		if (a.cls == fpcls::zero || b.cls == fpcls::inf)
		{
			b.sign = a_sign ^ 1;
			return b;
		}
		if (b.cls == fpcls::zero)
		{
			return a;
		}
	}
	else
	{
		/* Addition */
		if (a.cls == fpcls::normal && b.cls == fpcls::normal)
		{
			if (a.exp > b.exp)
			{
				shift64RightJamming(b.frac, a.exp - b.exp, &b.frac);
			}
			else if (a.exp < b.exp)
			{
				shift64RightJamming(a.frac, b.exp - a.exp, &a.frac);
				a.exp = b.exp;
			}
			a.frac += b.frac;
			if (a.frac & DECOMPOSED_OVERFLOW_BIT)
			{
				a.frac >>= 1;
				a.exp += 1;
			}
			return a;
		}
		if (is_nan(a.cls) || is_nan(b.cls))
		{
			return pick_nan(a, b, s);
		}
		if (a.cls == fpcls::inf || b.cls == fpcls::zero)
		{
			return a;
		}
		if (b.cls == fpcls::inf || a.cls == fpcls::zero)
		{
			b.sign = b_sign;
			return b;
		}
	}
}

static uint64_t sfp_add64(uint64_t a_, uint64_t b_)
{
	fpstat s;
	return _sfp_add64(fprep(a_), fprep(b_), &s).raw();
}

X86Emitter::X86Emitter(const ArchData &arch_data, Context &context, Block *current_block, bool no_mmu, bool kernel_mode, bool count_kernel_instructions, bool count_user_instructions) : Emitter(context, current_block), _arch_data(arch_data), _no_mmu(no_mmu), _kernel_mode(kernel_mode), _count_kernel_instructions(count_kernel_instructions), _count_user_instructions(count_user_instructions), _x86_context((X86Context &)context), _used_features(0)
{
}

X86Emitter::~X86Emitter()
{
}

void X86Emitter::debug_print(const char *op, Value *o0_, Value *o1_, Value *o2_, Value *o3_)
{
	auto o0 = (X86Value *)o0_;
	auto o1 = (X86Value *)o1_;
	auto o2 = (X86Value *)o2_;
	auto o3 = (X86Value *)o3_;

	printf("[%p] %s ", get_current_block(), op);

	if (o0)
	{
		debug_print_operand(o0);
	}
	if (o1)
	{
		debug_print_operand(o1);
	}
	if (o2)
	{
		debug_print_operand(o2);
	}
	if (o3)
	{
		debug_print_operand(o3);
	}
	printf("\n");
}

void X86Emitter::debug_print_operand(X86Value *op)
{
	switch (op->kind())
	{
	case X86ValueKind::BINARY_OPERATION:
		switch (((X86BinaryOperation *)op)->kind())
		{
		case X86BinaryOperationKind::ADD:
			printf("+ ");
			break;
		default:
			printf("? ");
			break;
		}
		break;

	case X86ValueKind::CAST:
	{
		switch (((X86Cast *)op)->kind())
		{
		case X86CastKind::SX:
			printf("sx ");
			break;
		case X86CastKind::ZX:
			printf("zx ");
			break;
		case X86CastKind::TRUNCATE:
			printf("tr ");
			break;
		case X86CastKind::REINTERPRET:
			printf("ri ");
			break;
		case X86CastKind::CONVERT:
			printf("cvt ");
			break;
		}

		break;
	}

	case X86ValueKind::CONSTANT:
		printf("%lx:%u ", ((X86Constant *)op)->value(), ((X86Constant *)op)->width_in_bits());
		break;
	case X86ValueKind::GUEST_REGISTER:
		printf("greg(%lx) ", ((X86GuestRegister *)op)->offset());
		break;
	case X86ValueKind::LOCAL_VARIABLE:
		printf("%%%s%u ", ((X86LocalVariable *)op)->reg().name(), ((X86LocalVariable *)op)->reg().unique_index());
		break;
	case X86ValueKind::PC_REGISTER:
		printf("pc ");
		break;
	case X86ValueKind::UNARY_OPERATION:
		printf("unop ");
		break;
	case X86ValueKind::UNKNOWN:
		printf("<unknown> ");
		break;
	default:
		break;
	}
}

void X86Emitter::debug_print_b(const char *op, Value *o0, dbt::el::Block *t0, dbt::el::Block *t1)
{
	printf("[%p] %s ", get_current_block(), op);

	if (o0)
	{
		debug_print_operand((X86Value *)o0);
	}

	if (t0)
	{
		printf("%p ", t0);
	}

	if (t1)
	{
		printf("%p ", t1);
	}

	printf("\n");
}

Value *X86Emitter::adc(Value *lhs, Value *rhs, Value *carry)
{
	DEBUG_EMIT("adc", lhs, rhs, carry);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::ADC, (X86Value *)lhs, (X86Value *)rhs, (X86Value *)carry);
}

Value *X86Emitter::adcf(Value *lhs, Value *rhs, Value *carry)
{
	DEBUG_EMIT("adcf", lhs, rhs, carry);
	auto operation = _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::ADCF, (X86Value *)lhs, (X86Value *)rhs, (X86Value *)carry);
	auto operand = operation->as_operand(*this);

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, operation->type(), operand);
}

Value *X86Emitter::add(Value *lhs_, Value *rhs_)
{
	DEBUG_EMIT("add", lhs_, rhs_);

	auto lhs = (X86Value *)lhs_;
	auto rhs = (X86Value *)rhs_;

	if (lhs->kind() == X86ValueKind::CONSTANT && ((X86Constant *)lhs)->value() == 0)
	{
		return rhs;
	}
	else if (rhs->kind() == X86ValueKind::CONSTANT && ((X86Constant *)rhs)->value() == 0)
	{
		return lhs;
	}

	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::ADD, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::alloc_local(const dbt::el::Type &type, bool is_global)
{
	DEBUG_EMIT("alloc-local");

	auto vreg = _vreg_allocator.alloc_vreg(type.is_vector() || type.is_floating() ? X86RegisterClasses::SSE : X86RegisterClasses::GENERAL_PURPOSE);
	return _x86_context.support().alloc_obj<X86LocalVariable>(_x86_context, type, vreg, is_global);
}

Value *X86Emitter::bitwise_and(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("and", lhs, rhs);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::AND, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::bitwise_not(Value *v)
{
	DEBUG_EMIT("not", v);
	return _x86_context.support().alloc_obj<X86UnaryOperation>(_x86_context, X86UnaryOperationKind::NOT, (X86Value *)v);
}

Value *X86Emitter::bitwise_or(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("or", lhs, rhs);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::OR, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::bitwise_xor(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("xor", lhs, rhs);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::XOR, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::neg(Value *v)
{
	DEBUG_EMIT("neg", v);
	return _x86_context.support().alloc_obj<X86UnaryOperation>(_x86_context, X86UnaryOperationKind::NEG, (X86Value *)v);
}

extern "C" void __invalidate_block_because_of_features();

void X86Emitter::block_start(dbt_u64 addr, dbt_u32 feature_set)
{
	DEBUG_EMIT("block-start");

	auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant(addr, 64), Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::MOV, Operand::make_register(tmp, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x58));

	add_mov_auto(Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x60), Operand::make_register(tmp, 32));

	_feature_mask_and = add_instruction(InstructionKind::AND, Operand::make_constant(0, 32), Operand::make_register(tmp, 32));
	_feature_set_cmp = add_instruction(InstructionKind::CMP, Operand::make_constant(0, 32), Operand::make_register(tmp, 32));
	auto jmp_over_invalidate = add_instruction(InstructionKind::JE);

	//printf("XXX BLOCK START addr=%p\n", addr);
	add_instruction(InstructionKind::INT, Operand::make_constant(0x83, 8));

	auto continue_exec = add_instruction(InstructionKind::LABEL);
	jmp_over_invalidate->set_operand(0, Operand::make_label(continue_exec));
}

void X86Emitter::block_end(dbt_u32 feature_set)
{
	uint32_t feature_mask = (1u << 30) | 0x7; //_used_features;

	if (_kernel_mode) {
		feature_mask |= 0x40;
	} else {
		feature_mask |= 0x80;
	}

	feature_set &= feature_mask;

	//printf("XXX BLOCK END set=%x, mask=%x, used=%x\n", feature_set, feature_mask, _used_features);

	_feature_mask_and->set_operand(0, Operand::make_constant(feature_mask, 32));
	_feature_set_cmp->set_operand(0, Operand::make_constant(feature_set, 32));
}

Value *X86Emitter::select(Value *cond, Value *tv, Value *fv)
{
	assert(false);
	return nullptr;
}

void X86Emitter::branch(Value *predicate_, dbt::el::Block *true_target, dbt::el::Block *false_target)
{
	DEBUG_EMIT_B("branch", predicate_, true_target, false_target);

	auto predicate = (X86Value *)predicate_;

	if (predicate->kind() == X86ValueKind::CONSTANT)
	{
		if (((X86Constant *)predicate)->value() == 0)
		{
			// false
			add_instruction(InstructionKind::JMP, Operand::make_label(((X86Block *)false_target)->head()));
			((X86Block *)get_current_block())->next0 = (X86Block *)false_target;
		}
		else
		{
			// true
			add_instruction(InstructionKind::JMP, Operand::make_label(((X86Block *)true_target)->head()));
			((X86Block *)get_current_block())->next0 = (X86Block *)true_target;
		}

		return;
	}

	auto predicate_operand = predicate->as_operand(*this);

	if (predicate_operand.is_mem())
	{
		assert(false && "XXXXX");
	}
	else if (predicate_operand.is_const())
	{
		assert(false && "XXXXX");
	}

	add_instruction(InstructionKind::TEST, predicate_operand, predicate_operand);
	add_instruction(InstructionKind::JNZ, Operand::make_label(((X86Block *)true_target)->head()));
	add_instruction(InstructionKind::JMP, Operand::make_label(((X86Block *)false_target)->head()));

	((X86Block *)get_current_block())->next0 = (X86Block *)true_target;
	((X86Block *)get_current_block())->next1 = (X86Block *)false_target;
}

Value *X86Emitter::bswap(Value *v)
{
	DEBUG_EMIT("bswap", v);
	return _x86_context.support().alloc_obj<X86UnaryOperation>(_x86_context, X86UnaryOperationKind::BSWAP, (X86Value *)v);
}

Value *X86Emitter::call(void *fnp, Value *o0, Value *o1, Value *o2, Value *o3)
{
	DEBUG_EMIT("call", o0, o1, o2, o3);
	//printf("FNP=%p\n", fnp);

	if (fnp == __captive___builtin_adc || fnp == __captive___builtin_adc64)
	{
		return adc(o0, o1, o2);
	}
	else if (fnp == __captive___builtin_sbc || fnp == __captive___builtin_sbc64)
	{
		return sbc(o0, o1, o2);
	}
	else if (fnp == __captive___builtin_adc_flags || fnp == __captive___builtin_adc64_flags)
	{
		return adcf(o0, o1, o2);
	}
	else if (fnp == __captive___builtin_sbc_flags || fnp == __captive___builtin_sbc64_flags)
	{
		return sbcf(o0, o1, o2);
	}
	else if (fnp == __captive___builtin_smulh)
	{
		return smulh(o0, o1);
	}
	else if (fnp == __captive___builtin_umulh)
	{
		return umulh(o0, o1);
	}
	else if (fnp == __captive___builtin_update_zn_flags || fnp == __captive___builtin_update_zn_flags64)
	{
		set_zn(o0);
		return nullptr;
	}
	else if (fnp == __captive_mmu_flush_all || fnp == __captive_mmu_flush_va)
	{
		mmu_flush<captive::arch::mmu::strategy::MMUStrategyType>((X86Value *)o0);
		return nullptr;
	}
	else if (fnp == __captive_mmu_notify_pgt_change)
	{
		mmu_pgt_change<captive::arch::mmu::strategy::MMUStrategyType>();
		return nullptr;
	}
	else if (fnp == __captive_mmu_notify_asid_change)
	{
		mmu_asid_change<captive::arch::mmu::strategy::MMUStrategyType>((X86Value *)o0);
		return nullptr;
	}
	else if (fnp == __captive_trigger_irq)
	{
		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_constant(1, 32), Operand::make_register(tmp, 32));

		add_instruction(InstructionKind::MOV, Operand::make_register(tmp, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 48));
	}
	else if (fnp == __captive___builtin_set_fp_rounding)
	{
		//add_instruction(InstructionKind::STMXCSR, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x98));
		//add_instruction(InstructionKind::LDMXCSR, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x98));

		auto o0v = (X86Value *)o0;
		add_instruction(InstructionKind::MOV, o0v->as_operand(*this), Operand::make_register(X86PhysicalRegisters::R14, 32));

		add_instruction(InstructionKind::MOV, Operand::make_constant(12, 32), Operand::make_register(X86PhysicalRegisters::C, 32));
		add_instruction(InstructionKind::LCALL, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x98));
	}
	else if (fnp == __captive___builtin_get_fp_rounding)
	{
		return _x86_context.support().alloc_obj<X86Constant>(_x86_context, _x86_context.types().u8(), (uint64_t)3, 8);
	}
	else if (fnp == __captive_single_step)
	{
		add_instruction(InstructionKind::INT, Operand::make_constant(0x91, 8));
	}
	else if (fnp == __captive___builtin_fma32 || fnp == __captive___builtin_fma64)
	{
#if 1
		auto mult1 = (X86Value *)o0;
		auto mult2 = (X86Value *)o1;
		auto add = (X86Value *)o2;

		auto tmpreg = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto tmp = Operand::make_register(tmpreg, 128);

		add_mov_auto(add->as_operand(*this), tmp);

		auto mult1o = mult1->as_operand(*this);
		auto mult2o = mult2->as_operand(*this);

		if (!mult1o.is_reg())
		{
			auto mtmpreg = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
			auto mtmp = Operand::make_register(mtmpreg, 128);
			add_mov_auto(mult1o, mtmp);
			mult1o = mtmp;
		}

		if (!mult2o.is_reg())
		{
			auto mtmpreg = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
			auto mtmp = Operand::make_register(mtmpreg, 128);
			add_mov_auto(mult2o, mtmp);
			mult2o = mtmp;
		}

		if (fnp == __captive___builtin_fma32)
		{
			add_instruction(InstructionKind::VFMADD231SS, mult1o, mult2o, tmp);
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().f32(), tmp);
		}
		else if (fnp == __captive___builtin_fma64)
		{
			add_instruction(InstructionKind::VFMADD231SD, mult1o, mult2o, tmp);
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().f64(), tmp);
		}
		else
		{
			UNIMPLEMENTED;
		}
#else
		auto multiplicanderson = _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::MUL, (X86Value *)o0, (X86Value *)o1);
		return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::ADD, multiplicanderson, (X86Value *)o2);
#endif
	}
	else if (fnp == __captive___builtin_cmpf32_flags || fnp == __captive___builtin_cmpf64_flags || fnp == __captive___builtin_cmpf32e_flags || fnp == __captive___builtin_cmpf64e_flags)
	{
		auto o0v = (X86Value *)o0;
		auto o1v = (X86Value *)o1;

		auto o0op = o0v->as_operand(*this);
		auto o1op = o1v->as_operand(*this);

		if (o0op.is_mem())
		{
			auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
			add_mov_auto(o0op, Operand::make_register(tmp, 128));
			o0op = Operand::make_register(tmp, 128);
		}

		assert(!o1op.is_const());

		if (fnp == __captive___builtin_cmpf32_flags)
			add_instruction(InstructionKind::UCOMISS, o1op, o0op);
		else if (fnp == __captive___builtin_cmpf32e_flags)
			add_instruction(InstructionKind::COMISS, o1op, o0op);
		else if (fnp == __captive___builtin_cmpf64_flags)
			add_instruction(InstructionKind::UCOMISD, o1op, o0op);
		else if (fnp == __captive___builtin_cmpf64e_flags)
			add_instruction(InstructionKind::COMISD, o1op, o0op);

		// V = P
		add_instruction(InstructionKind::SETP, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.OVERFLOW_DISPLACEMENT));

		auto jp_nan = add_instruction(InstructionKind::JP);

		// N = C
		add_instruction(InstructionKind::SETC, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.NEGATIVE_DISPLACEMENT));

		// Z = Z
		add_instruction(InstructionKind::SETZ, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.ZERO_DISPLACEMENT));

		// C = ¬C
		add_instruction(InstructionKind::SETNC, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.CARRY_DISPLACEMENT));

		auto jmp_done = add_instruction(InstructionKind::JMP);

		// NaN Handler
		auto nan_label = add_instruction(InstructionKind::LABEL);
		jp_nan->set_operand(0, Operand::make_label(nan_label));

		add_instruction(InstructionKind::MOV, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.NEGATIVE_DISPLACEMENT));
		add_instruction(InstructionKind::MOV, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.ZERO_DISPLACEMENT));
		add_instruction(InstructionKind::MOV, Operand::make_constant(1, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.CARRY_DISPLACEMENT));

		auto done_label = add_instruction(InstructionKind::LABEL);
		jmp_done->set_operand(0, Operand::make_label(done_label));
	}
	else if (fnp == __captive_float_abs)
	{
		auto tmpg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		auto tmpf = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);

		add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffff, 32), Operand::make_register(tmpg, 32));
		add_instruction(InstructionKind::MOVD, Operand::make_register(tmpg, 32), Operand::make_register(tmpf, 128));

		auto dst = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto o0v = (X86Value *)o0;
		add_mov_auto(o0v->as_operand(*this), Operand::make_register(dst, 128));

		add_instruction(InstructionKind::PAND, Operand::make_register(tmpf, 128), Operand::make_register(dst, 128));
		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().f32(), Operand::make_register(dst, 128));
	}
	else if (fnp == __captive_double_abs)
	{
		auto tmpg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		auto tmpf = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);

		add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffffffff, 64), Operand::make_register(tmpg, 64));
		add_instruction(InstructionKind::MOVQ, Operand::make_register(tmpg, 64), Operand::make_register(tmpf, 128));

		auto dst = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto o0v = (X86Value *)o0;
		add_mov_auto(o0v->as_operand(*this), Operand::make_register(dst, 128));

		add_instruction(InstructionKind::PAND, Operand::make_register(tmpf, 128), Operand::make_register(dst, 128));
		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().f64(), Operand::make_register(dst, 128));
	}
	else if (fnp == __captive_float_sqrt || fnp == __captive_double_sqrt)
	{
		return sqrt(o0);
	}
	else if (fnp == __captive___builtin_popcount32)
	{
		auto dst = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

		auto o0v = (X86Value *)o0;
		add_instruction(InstructionKind::POPCNT, o0v->as_operand(*this), Operand::make_register(dst, 32));

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().u32(), Operand::make_register(dst, 32));
	}
	else if (fnp == __captive___builtin_f32_round || fnp == __captive___builtin_f64_round)
	{
		auto o0v = (X86Value *)o0;
		assert(o0v->kind() != X86ValueKind::CONSTANT);

		auto o1v = (X86Value *)o1;

		auto dst = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto dstreg = Operand::make_register(dst, 128);

		assert(o0v->type().is_floating());
		if (fnp == __captive___builtin_f32_round)
		{
			add_instruction(InstructionKind::ROUNDSS, Operand::make_constant(0, 8), o0v->as_operand(*this), dstreg);
		}
		else if (fnp == __captive___builtin_f64_round)
		{
			add_instruction(InstructionKind::ROUNDSD, Operand::make_constant(0, 8), o0v->as_operand(*this), dstreg);
		}
		else
		{
			assert(false);
		}

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, o0v->type(), dstreg);
	}
	else if (fnp == __captive___builtin_fcvt_f32_s32 || fnp == __captive___builtin_fcvt_f64_s32)
	{
		auto value_to_round = (X86Value *)o0;
		assert(value_to_round->kind() != X86ValueKind::CONSTANT);

		int rmode;
		assert(((X86Value *)o1)->kind() == X86ValueKind::CONSTANT);
		switch (((X86Constant *)o1)->value())
		{
		case 0:
			rmode = 0;
			break; // TIE EVEN
		case 1:
			rmode = 2;
			break; // POS-INF
		case 2:
			rmode = 1;
			break; // NEG-INF
		case 3:
			rmode = 3;
			break; // ZERO
		default:
			rmode = 3;
			break;
		}

		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto tmpreg = Operand::make_register(tmp, 128);

		assert(value_to_round->type().is_floating());

		if (value_to_round->type().size_in_bits() == 32)
		{
			add_instruction(InstructionKind::ROUNDSS, Operand::make_constant(rmode, 8), value_to_round->as_operand(*this), tmpreg);
		}
		else if (value_to_round->type().size_in_bits() == 64)
		{
			add_instruction(InstructionKind::ROUNDSD, Operand::make_constant(rmode, 8), value_to_round->as_operand(*this), tmpreg);
		}
		else
		{
			assert(false);
		}

		return _x86_context.support().alloc_obj<X86Cast>(
			_x86_context,
			X86CastKind::CONVERT,
			_x86_context.support().alloc_obj<X86Operand>(_x86_context, value_to_round->type(), tmpreg),
			_x86_context.types().s32());
	}
	else if (fnp == __captive___builtin_fcvt_f32_s64 || fnp == __captive___builtin_fcvt_f64_s64)
	{
		auto value_to_round = (X86Value *)o0;
		assert(value_to_round->kind() != X86ValueKind::CONSTANT);

		int rmode;
		assert(((X86Value *)o1)->kind() == X86ValueKind::CONSTANT);
		switch (((X86Constant *)o1)->value())
		{
		case 0:
			rmode = 0;
			break;
		case 1:
			rmode = 2;
			break;
		case 2:
			rmode = 1;
			break;
		case 3:
			rmode = 3;
			break;
		default:
			rmode = 3;
			break;
		}

		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto tmpreg = Operand::make_register(tmp, 128);

		assert(value_to_round->type().is_floating());

		if (value_to_round->type().size_in_bits() == 32)
		{
			add_instruction(InstructionKind::ROUNDSS, Operand::make_constant(rmode, 8), value_to_round->as_operand(*this), tmpreg);
		}
		else if (value_to_round->type().size_in_bits() == 64)
		{
			add_instruction(InstructionKind::ROUNDSD, Operand::make_constant(rmode, 8), value_to_round->as_operand(*this), tmpreg);
		}
		else
		{
			assert(false);
		}

		return _x86_context.support().alloc_obj<X86Cast>(
			_x86_context,
			X86CastKind::CONVERT,
			_x86_context.support().alloc_obj<X86Operand>(_x86_context, value_to_round->type(), tmpreg),
			_x86_context.types().s64());
	}
	else if (fnp == __captive___builtin_fcvt_f32_u32 || fnp == __captive___builtin_fcvt_f64_u32)
	{
		auto value_to_round = (X86Value *)o0;
		assert(value_to_round->kind() != X86ValueKind::CONSTANT);

		int rmode;
		assert(((X86Value *)o1)->kind() == X86ValueKind::CONSTANT);
		switch (((X86Constant *)o1)->value())
		{
		case 0:
			rmode = 0;
			break;
		case 1:
			rmode = 2;
			break;
		case 2:
			rmode = 1;
			break;
		case 3:
			rmode = 3;
			break;
		default:
			rmode = 3;
			break;
		}

		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto tmpreg = Operand::make_register(tmp, 128);

		assert(value_to_round->type().is_floating());

		if (value_to_round->type().size_in_bits() == 32)
		{
			add_instruction(InstructionKind::ROUNDSS, Operand::make_constant(rmode, 8), value_to_round->as_operand(*this), tmpreg);
		}
		else if (value_to_round->type().size_in_bits() == 64)
		{
			add_instruction(InstructionKind::ROUNDSD, Operand::make_constant(rmode, 8), value_to_round->as_operand(*this), tmpreg);
		}
		else
		{
			assert(false);
		}

		return _x86_context.support().alloc_obj<X86Cast>(
			_x86_context,
			X86CastKind::CONVERT,
			_x86_context.support().alloc_obj<X86Operand>(_x86_context, value_to_round->type(), tmpreg),
			_x86_context.types().u32());
	}
	else if (fnp == __captive___builtin_fcvt_f32_u64 || fnp == __captive___builtin_fcvt_f64_u64)
	{
		auto value_to_round = (X86Value *)o0;
		assert(value_to_round->kind() != X86ValueKind::CONSTANT);

		int rmode;
		assert(((X86Value *)o1)->kind() == X86ValueKind::CONSTANT);
		switch (((X86Constant *)o1)->value())
		{
		case 0:
			rmode = 0;
			break;
		case 1:
			rmode = 2;
			break;
		case 2:
			rmode = 1;
			break;
		case 3:
			rmode = 3;
			break;
		default:
			rmode = 3;
			break;
		}

		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto tmpreg = Operand::make_register(tmp, 128);

		assert(value_to_round->type().is_floating());

		if (value_to_round->type().size_in_bits() == 32)
		{
			add_instruction(InstructionKind::ROUNDSS, Operand::make_constant(rmode, 8), value_to_round->as_operand(*this), tmpreg);
		}
		else if (value_to_round->type().size_in_bits() == 64)
		{
			add_instruction(InstructionKind::ROUNDSD, Operand::make_constant(rmode, 8), value_to_round->as_operand(*this), tmpreg);
		}
		else
		{
			assert(false);
		}

		return _x86_context.support().alloc_obj<X86Cast>(
			_x86_context,
			X86CastKind::CONVERT,
			_x86_context.support().alloc_obj<X86Operand>(_x86_context, value_to_round->type(), tmpreg),
			_x86_context.types().u64());
	}
	else if (fnp == __captive___builtin_clear_fpex)
	{
		auto tmp_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::STMXCSR, Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0xb8));
		add_instruction(InstructionKind::AND, Operand::make_constant(~0x3fu, 32), Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0xb8));
		add_instruction(InstructionKind::LDMXCSR, Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0xb8));
	}
	else if (fnp == __captive___builtin_fpex_invalid || fnp == __captive___builtin_fpex_overflow || fnp == __captive___builtin_fpex_underflow)
	{
		add_instruction(InstructionKind::STMXCSR, Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0xb8));

		auto mxcsr_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

		add_instruction(InstructionKind::MOV, Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0xb8), Operand::make_register(mxcsr_reg, 32));

		if (fnp == __captive___builtin_fpex_overflow)
		{
			add_instruction(InstructionKind::SHR, Operand::make_constant(3, 8), Operand::make_register(mxcsr_reg, 8));
		}
		else if (fnp == __captive___builtin_fpex_underflow)
		{
			add_instruction(InstructionKind::SHR, Operand::make_constant(4, 8), Operand::make_register(mxcsr_reg, 8));
		}

		add_instruction(InstructionKind::AND, Operand::make_constant(1, 8), Operand::make_register(mxcsr_reg, 8));
		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().u8(), Operand::make_register(mxcsr_reg, 8));
	}
	else if (fnp == __captive___builtin_polymul8)
	{
		auto mult1 = (X86Value *)o0;
		auto mult2 = (X86Value *)o1;

		auto mult1o = mult1->as_operand(*this);
		auto mult2o = mult2->as_operand(*this);

		auto mult1t = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto mult1to = Operand::make_register(mult1t, 128);

		auto mult2t = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto mult2to = Operand::make_register(mult2t, 128);

		add_mov_auto(mult1o, mult1to);
		add_mov_auto(mult2o, mult2to);

		add_instruction(InstructionKind::PCLMULQDQ, mult1to, mult2to, Operand::make_constant(0, 8));

		auto retreg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		auto ret = Operand::make_register(retreg, 16);

		add_mov_auto(mult2to, Operand::make_register(retreg, 32));

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().u16(), ret);
	}
	else if (fnp == __captive___builtin_polymul64)
	{
		auto mult1 = (X86Value *)o0;
		auto mult2 = (X86Value *)o1;

		auto mult1o = mult1->as_operand(*this);
		auto mult2o = mult2->as_operand(*this);

		auto mult1t = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto mult1to = Operand::make_register(mult1t, 128);

		auto mult2t = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto mult2to = Operand::make_register(mult2t, 128);

		add_mov_auto(mult1o, mult1to);
		add_mov_auto(mult2o, mult2to);

		add_instruction(InstructionKind::PCLMULQDQ, mult1to, mult2to, Operand::make_constant(0, 8));

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().u128(), mult2to);
	}
	else if (fnp == __captive___builtin_jit_invalidate_txln)
	{
#ifdef CONFIG_FORCED_ICACHE_INVALIDATIONS
		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)__invalidate_translation, 64), Operand::make_register(tmp, 64));

		add_mov_auto(((X86Value *)o0)->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));
		add_instruction(InstructionKind::CALL, Operand::make_register(tmp, 64));
#endif
	}
	else if (fnp == __captive___builtin_jit_invalidate_txln_all)
	{
#ifdef CONFIG_FORCED_ICACHE_INVALIDATIONS
		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)__invalidate_translations, 64), Operand::make_register(tmp, 64));
		add_instruction(InstructionKind::CALL, Operand::make_register(tmp, 64));
#endif
	}
	else if (fnp == __captive___builtin_abs32 || fnp == __captive___builtin_abs64)
	{
		add_mov_auto(((X86Value *)o0)->as_operand(*this), Operand::make_register(X86PhysicalRegisters::A, 64));
		add_instruction(InstructionKind::CQTO);
		add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::D, 64), Operand::make_register(X86PhysicalRegisters::A, 64));
		add_instruction(InstructionKind::SUB, Operand::make_register(X86PhysicalRegisters::D, 64), Operand::make_register(X86PhysicalRegisters::A, 64));

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().u64(), Operand::make_register(X86PhysicalRegisters::A, 64));
	}
	else if (fnp == __captive___softfp_add64)
	{
		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)sfp_add64, 64), Operand::make_register(tmp, 64));

		add_mov_auto(((X86Value *)o0)->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));
		add_mov_auto(((X86Value *)o1)->as_operand(*this), Operand::make_register(X86PhysicalRegisters::SI, 64));
		add_instruction(InstructionKind::CALL, Operand::make_register(tmp, 64));

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().u64(), Operand::make_register(X86PhysicalRegisters::A, 64));
	}
	else if (fnp == __captive_mem_monitor_acquire)
	{
		mmu_monitor_acquire<captive::arch::mmu::strategy::MMUStrategyType>((X86Value *)o1);
		return nullptr;
	}
	else if (fnp == __captive_mem_monitor_release)
	{
		return mmu_monitor_release<captive::arch::mmu::strategy::MMUStrategyType>((X86Value *)o1);
	}
	else if (fnp == __captive_mem_monitor_release_all)
	{
		mmu_monitor_release_all<captive::arch::mmu::strategy::MMUStrategyType>();
		return nullptr;
	}
	else
	{
		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)fnp, 64), Operand::make_register(tmp, 64));

		add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0), Operand::make_register(X86Registers::RDI));
		add_instruction(InstructionKind::CALL, Operand::make_register(tmp, 64));
	}

	return nullptr;
}

Value *X86Emitter::clz(Value *v)
{
	DEBUG_EMIT("clz", v);
	return _x86_context.support().alloc_obj<X86UnaryOperation>(_x86_context, X86UnaryOperationKind::CLZ, (X86Value *)v);
}

Value *X86Emitter::cmp_eq(Value *lhs_, Value *rhs_)
{
	DEBUG_EMIT("cmp-eq", lhs_, rhs_);

	auto lhs = (X86Value *)lhs_;
	auto rhs = (X86Value *)rhs_;

	if (lhs->kind() == X86ValueKind::CONSTANT && rhs->kind() == X86ValueKind::CONSTANT)
	{
		auto lhsv = (X86Constant *)lhs;
		auto rhsv = (X86Constant *)rhs;

		return _x86_context.support().alloc_obj<X86Constant>(_x86_context, _x86_context.types().u8(), (uint64_t)(lhsv->value() == rhsv->value()), 8);
	}

	return _x86_context.support().alloc_obj<X86ComparisonOperation>(_x86_context, X86ComparisonOperationKind::EQ, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::cmp_ge(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("cmp-ge", lhs, rhs);
	return _x86_context.support().alloc_obj<X86ComparisonOperation>(_x86_context, X86ComparisonOperationKind::GE, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::cmp_gt(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("cmp-gt", lhs, rhs);
	return _x86_context.support().alloc_obj<X86ComparisonOperation>(_x86_context, X86ComparisonOperationKind::GT, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::cmp_le(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("cmp-le", lhs, rhs);
	return _x86_context.support().alloc_obj<X86ComparisonOperation>(_x86_context, X86ComparisonOperationKind::LE, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::cmp_lt(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("cmp-lt", lhs, rhs);
	return _x86_context.support().alloc_obj<X86ComparisonOperation>(_x86_context, X86ComparisonOperationKind::LT, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::cmp_ne(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("cmp-ne", lhs, rhs);
	return _x86_context.support().alloc_obj<X86ComparisonOperation>(_x86_context, X86ComparisonOperationKind::NE, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::constant(dbt_u64 value, const dbt::el::Type &type)
{
	assert(type.is_integer());

#ifdef PDEBUG
	printf("[%p] constant 0x%lx:%u\n", get_current_block(), value, type.size_in_bits());
#endif

	return _x86_context.support().alloc_obj<X86Constant>(_x86_context, type, (uint64_t)value, type.size_in_bits());
}

Value *X86Emitter::constant(dbt_f32 value, const dbt::el::Type &type)
{
	assert(type.is_floating());

#ifdef PDEBUG
	printf("[%p] constant 0x%lx:%u\n", get_current_block(), value, type.size_in_bits());
#endif

	return _x86_context.support().alloc_obj<X86Constant>(_x86_context, type, value, type.size_in_bits());
}

Value *X86Emitter::constant(dbt_f64 value, const dbt::el::Type &type)
{
	assert(type.is_floating());

#ifdef PDEBUG
	printf("[%p] constant 0x%lx:%u\n", get_current_block(), value, type.size_in_bits());
#endif

	return _x86_context.support().alloc_obj<X86Constant>(_x86_context, type, value, type.size_in_bits());
}

Value *X86Emitter::constant_vector_splat(dbt_u64 value, const dbt::el::Type &type)
{
	assert(!type.is_floating());

	return _x86_context.support().alloc_obj<X86Constant>(_x86_context, type, value, type.size_in_bits());
}

Value *X86Emitter::constant_vector_splat_f(dbt_f32 value, const dbt::el::Type &type)
{
	assert(type.is_floating());
	return _x86_context.support().alloc_obj<X86Constant>(_x86_context, type, value, 32);
}

Value *X86Emitter::constant_vector_splat_f(dbt_f64 value, const dbt::el::Type &type)
{
	assert(type.is_floating());
	return _x86_context.support().alloc_obj<X86Constant>(_x86_context, type, value, 64);
}

Value *X86Emitter::div(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("div", lhs, rhs);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::DIV, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::sqrt(Value *value)
{
	DEBUG_EMIT("sqrt", value);
	return _x86_context.support().alloc_obj<X86UnaryOperation>(_x86_context, X86UnaryOperationKind::SQRT, (X86Value *)value);
}

void X86Emitter::enter_kernel_mode()
{
	DEBUG_EMIT("enter-kernel-mode");
	fatal("XXX");
}

void X86Emitter::enter_user_mode()
{
	DEBUG_EMIT("enter-user-mode");
	fatal("XXX");
}

void X86Emitter::inc_pc(Value *amount_)
{
	DEBUG_EMIT("inc-pc", amount_);

	X86Value *amount = (X86Value *)amount_;
	if (amount->kind() == X86ValueKind::CONSTANT)
	{
		//add_instruction(InstructionKind::LEA, Operand::make_mem(64, X86Registers::R15, ((X86Constant *) amount)->value()), Operand::make_register(X86Registers::R15));
		add_instruction(InstructionKind::ADD, Operand::make_constant(4, 64), Operand::make_register(X86PhysicalRegisters::R15, 64));
	}
	else
	{
		add_instruction(InstructionKind::ADD, amount->as_operand(*this), Operand::make_register(X86Registers::R15));
	}
}

void X86Emitter::instruction_start(dbt_u64 addr)
{
	add_instruction(InstructionKind::NOP, Operand::make_mem(64, 64, X86PhysicalRegisters::A, (dbt_s32)addr));

#ifdef CONFIG_COUNT_INSTRUCTIONS
	add_instruction(InstructionKind::ADD, Operand::make_constant(1, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x38));
#endif
}

void X86Emitter::instruction_end(dbt_u64 addr)
{
	//auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	//add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x48), Operand::make_register(tmp, 64));
	//add_instruction(InstructionKind::ADD, Operand::make_constant(1, 64), Operand::make_mem(64, 64, tmp, 40));
	//increment_pca();

	if (_kernel_mode && _count_kernel_instructions)
	{
		increment_icount();
	}
	else if (!_kernel_mode && _count_user_instructions)
	{
		increment_icount();
	}
}

void X86Emitter::jump(dbt::el::Block *target)
{
	DEBUG_EMIT_B("jump", nullptr, target);

	add_instruction(InstructionKind::JMP, Operand::make_label(((X86Block *)target)->head()));

	((X86Block *)get_current_block())->next0 = (X86Block *)target;
}

void X86Emitter::leave(Value *value)
{
	DEBUG_EMIT("leave", value);

	// TODO: Quick Jump
	// add_instruction(InstructionKind::JMP, Operand::make_register(X86PhysicalRegisters::R15, 64));

#ifdef CONFIG_BLOCK_DISPATCHING
	// Check to see if we need to stop chaining (e.g. an interrupt)
	add_instruction(InstructionKind::CMP, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));
	auto jmp_to_exit = add_instruction(InstructionKind::JNZ);

	// Each chaining table entry is 16 bytes, arranged
	// 0	tag (8 bytes)
	// 8	pointer (8 bytes)

	// Load the cache base address
	auto cache_base = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x20), Operand::make_register(cache_base, 64));

	// Mask the PC
	auto pc_tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::R15, 32), Operand::make_register(pc_tmp, 32));
	add_instruction(InstructionKind::AND, Operand::make_constant(0x7ffc, 32), Operand::make_register(pc_tmp, 32));

	add_instruction(InstructionKind::CMP,
					Operand::make_register(X86PhysicalRegisters::R15, 64),
					Operand::make_mem(64, 64, cache_base, pc_tmp, MemoryScale::S4, 0));

	auto jne_to_exit = add_instruction(InstructionKind::JNE);
	add_instruction(InstructionKind::JMP, Operand::make_mem(64, 64, cache_base, pc_tmp, MemoryScale::S4, 8));

	auto exit_label = add_instruction(InstructionKind::LABEL);
	jmp_to_exit->set_operand(0, Operand::make_label(exit_label));
	jne_to_exit->set_operand(0, Operand::make_label(exit_label));

	add_instruction(InstructionKind::MOV, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));
#endif

	add_instruction(InstructionKind::MOV, Operand::make_constant((dbt_u64)&block_trampoline_epilogue_normal, 64), Operand::make_register(X86PhysicalRegisters::C, 64));
	add_instruction(InstructionKind::JMP, Operand::make_register(X86PhysicalRegisters::C, 64));
}

void X86Emitter::chain(dbt_u64 target, dbt_u64 fallthrough, void *target_ptr, void *ft_ptr)
{
	DEBUG_EMIT("chain");

#ifdef CONFIG_BLOCK_CHAINING
	// Check to see if we need to stop chaining (e.g. an interrupt)
	add_instruction(InstructionKind::CMP, Operand::make_constant(0, 32), Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));
	auto jmp_to_exit = add_instruction(InstructionKind::JNZ);

	auto pc_tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::R15, 64), Operand::make_register(pc_tmp, 64));
	add_instruction(InstructionKind::AND, Operand::make_constant(0xfff, 32), Operand::make_register(pc_tmp, 32));
	add_instruction(InstructionKind::CMP, Operand::make_constant(target, 32), Operand::make_register(pc_tmp, 32));

	Instruction *miss_no_fallthrough = nullptr;
	if (ft_ptr == nullptr)
	{
		miss_no_fallthrough = add_instruction(InstructionKind::JNE);

		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)target_ptr, 64), Operand::make_register(pc_tmp, 64));
		add_instruction(InstructionKind::JMP, Operand::make_register(pc_tmp, 64));
	}
	else
	{
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)ft_ptr, 64), Operand::make_register(pc_tmp, 64));

		auto target_tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)target_ptr, 64), Operand::make_register(target_tmp, 64));

		add_instruction(InstructionKind::CMOVE, Operand::make_register(target_tmp, 64), Operand::make_register(pc_tmp, 64));
		add_instruction(InstructionKind::JMP, Operand::make_register(pc_tmp, 64));
	}

	// Clear the pending flag
	auto exit_label = add_instruction(InstructionKind::LABEL);
	jmp_to_exit->set_operand(0, Operand::make_label(exit_label));

	if (miss_no_fallthrough)
	{
		miss_no_fallthrough->set_operand(0, Operand::make_label(exit_label));
	}

	add_instruction(InstructionKind::MOV, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));

	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::A, 32), Operand::make_register(X86PhysicalRegisters::A, 32));
	add_instruction(InstructionKind::MOV, Operand::make_constant((dbt_u64)&block_trampoline_epilogue_normal, 64), Operand::make_register(X86PhysicalRegisters::C, 64));
	add_instruction(InstructionKind::JMP, Operand::make_register(X86PhysicalRegisters::C, 64));

	//add_instruction(InstructionKind::XOR, Operand::make_register(X86Registers::EAX), Operand::make_register(X86Registers::EAX));
	//add_instruction(InstructionKind::RET);
#else
	leave(nullptr);
#endif
}

Value *X86Emitter::load_device(Value *id_, Value *offset_, const dbt::el::Type &type)
{
	DEBUG_EMIT("load-device", id_, offset_);

	X86Value *id = (X86Value *)id_;
	X86Value *offset = (X86Value *)offset_;

	auto fnp_tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)&cpu_read_device, 64), Operand::make_register(fnp_tmp, 64));

	add_instruction(InstructionKind::SUB, Operand::make_constant(8, 8), Operand::make_register(X86Registers::RSP));

	add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0), Operand::make_register(X86Registers::RDI));

	add_mov_auto(id->as_operand(*this), Operand::make_register(X86Registers::RSI));
	add_mov_auto(offset->as_operand(*this), Operand::make_register(X86Registers::RDX));
	add_instruction(InstructionKind::MOV, Operand::make_register(X86Registers::RSP), Operand::make_register(X86Registers::RCX));
	add_instruction(InstructionKind::CALL, Operand::make_register(fnp_tmp, 64));

	auto result_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::POP, Operand::make_register(result_reg, 64));

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(result_reg, type.size_in_bits()));
}

Value *X86Emitter::load_local(Value *ptr_, const dbt::el::Type &type)
{
	DEBUG_EMIT("load-local", ptr_);

	X86LocalVariable *ptr = (X86LocalVariable *)ptr_;

	if (ptr->is_global())
	{
		return ptr;
	}
	else
	{
		if (ptr->current_value() == nullptr)
		{
			context().support().assertion_fail("LOAD OF UNASSIGNED LOCAL VARIABLE");
		}

		return ptr->current_value();
	}
}

Value *X86Emitter::load_memory(Value *addr_, const dbt::el::Type &type)
{
	DEBUG_EMIT("load-mem", addr_);

	X86Value *addr = (X86Value *)addr_;

	if (_no_mmu)
	{
		auto address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

		// Mask and Add to VM_VIRT_SPLIT
		add_instruction(InstructionKind::MOV, Operand::make_constant(VM_PHYS_GPM_BASE + VM_VIRT_SPLIT, 64), Operand::make_register(address, 64));
		add_instruction(InstructionKind::ADD, addr->as_operand(*this), Operand::make_register(address, 64));

		auto value = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_mem(type.size_in_bits(), 64, address, 0), Operand::make_register(value, type.size_in_bits()))->make_volatile();

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(value, type.size_in_bits()));
	}
	else
	{
		return mmu_load_memory<captive::arch::mmu::strategy::MMUStrategyType>((X86Value *)addr_, type);
	}
}

Value *X86Emitter::load_pc()
{
	DEBUG_EMIT("load-pc");
	return _x86_context.support().alloc_obj<X86PCRegister>(_x86_context);
}

Value *X86Emitter::load_register(Value *offset, const dbt::el::Type &type)
{
	DEBUG_EMIT("load-register", offset);
	if (((X86Value *)offset)->kind() == X86ValueKind::CONSTANT)
	{
#ifdef CACHED_GREGS
		auto fgro = _guest_register_objects.find(((X86Constant *)offset)->value());

		X86GuestRegister *gro;
		if (fgro == _guest_register_objects.end())
		{
			gro = _x86_context.support().alloc_obj<X86GuestRegister>(_x86_context, type, ((X86Constant *)offset)->value());
		}
		else
		{
			gro = fgro->second;
		}

		return gro;
#else
		return _x86_context.support().alloc_obj<X86GuestRegister>(_x86_context, type, ((X86Constant *)offset)->value());
#endif
	}
	else
	{
		auto offsetop = ((X86Value *)offset)->as_operand(*this);

		assert(offsetop.is_reg());

		if (offsetop.reg.width == 8)
		{
			add_instruction(InstructionKind::AND, Operand::make_constant(0xff, 32), Operand::make_register(offsetop.reg.reg, 32));
		}
		else if (offsetop.reg.width == 16)
		{
			add_instruction(InstructionKind::AND, Operand::make_constant(0xffff, 32), Operand::make_register(offsetop.reg.reg, 32));
		}
		else if (offsetop.reg.width == 32)
		{
			add_instruction(InstructionKind::MOV, Operand::make_register(offsetop.reg.reg, 32), Operand::make_register(offsetop.reg.reg, 32));
		}

		auto result = Operand::make_mem(type.size_in_bits(), 64, X86PhysicalRegisters::BP, offsetop.reg.reg, MemoryScale::S1, 0);
		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, result);
	}
}

Value *X86Emitter::mod(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("mod", lhs, rhs);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::MOD, (X86Value *)lhs, (X86Value *)rhs);
}

template <typename T>
static inline bool is_power_of_two(T v)
{
	return (v & (v - 1)) == 0;
}

template <typename T>
static inline T ilog2(T v)
{
	T r;
	asm("\tbsr %1, %0\n"
		: "=r"(r)
		: "r"(v));
	return r;
}

Value *X86Emitter::mul(Value *lhs_, Value *rhs_)
{
	DEBUG_EMIT("mul", lhs_, rhs_);

	auto rhs = (X86Value *)rhs_;
	auto lhs = (X86Value *)lhs_;

	if (rhs->kind() == X86ValueKind::CONSTANT)
	{
		auto rhsv = (X86Constant *)rhs;
		if (rhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (rhsv->value() == 1)
		{
			return lhs_;
		}
		else if (is_power_of_two(rhsv->value()))
		{
			auto shift_amount = _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), ilog2(rhsv->value()), lhs_->type().size_in_bits());
			return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SHL, lhs, shift_amount);
		}
	}
	else if (lhs->kind() == X86ValueKind::CONSTANT)
	{
		auto lhsv = (X86Constant *)lhs;
		if (lhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (lhsv->value() == 1)
		{
			return rhs_;
		}
		else if (is_power_of_two(lhsv->value()))
		{
			auto shift_amount = _x86_context.support().alloc_obj<X86Constant>(_x86_context, rhs_->type(), ilog2(lhsv->value()), rhs_->type().size_in_bits());
			return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SHL, rhs, shift_amount);
		}
	}

	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::MUL, lhs, rhs);
}

void X86Emitter::raise(Value *value)
{
	DEBUG_EMIT("raise", value);

	add_instruction(InstructionKind::INT, Operand::make_constant(3, 8));
}

Value *X86Emitter::rol(Value *v, Value *amt)
{
	DEBUG_EMIT("rol", v, amt);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::ROL, (X86Value *)v, (X86Value *)amt);
}

Value *X86Emitter::ror(Value *v, Value *amt)
{
	DEBUG_EMIT("ror", v, amt);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::ROR, (X86Value *)v, (X86Value *)amt);
}

Value *X86Emitter::sar(Value *v, Value *amt)
{
	DEBUG_EMIT("sar", v, amt);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SAR, (X86Value *)v, (X86Value *)amt);
}

Value *X86Emitter::sbc(Value *lhs, Value *rhs, Value *carry)
{
	DEBUG_EMIT("sbc", lhs, rhs, carry);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SBB, (X86Value *)lhs, (X86Value *)rhs, (X86Value *)carry);
}

Value *X86Emitter::sbcf(Value *lhs, Value *rhs, Value *carry)
{
	DEBUG_EMIT("sbcf", lhs, rhs, carry);
	auto operation = _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SBBF, (X86Value *)lhs, (X86Value *)rhs, (X86Value *)carry);
	auto operand = operation->as_operand(*this);

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, operation->type(), operand);
}

void X86Emitter::set_zn(Value *v_)
{
	DEBUG_EMIT("set-zn", v_);

	X86Value *value = (X86Value *)v_;

	auto value_operand = value->as_operand(*this);
	if (value_operand.is_mem())
	{
		// TODO: Candidate for removal
		auto value_operand_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

		dbt_u8 width = value->type().size_in_bits();
		add_mov_auto(value_operand, Operand::make_register(value_operand_reg, width));
		add_instruction(InstructionKind::TEST, Operand::make_register(value_operand_reg, width), Operand::make_register(value_operand_reg, width));
	}
	else
	{
		add_instruction(InstructionKind::TEST, value_operand, value_operand);
	}

	add_instruction(InstructionKind::SETZ, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.ZERO_DISPLACEMENT));
	add_instruction(InstructionKind::SETS, Operand::make_mem(8, 64, X86PhysicalRegisters::BP, _arch_data.NEGATIVE_DISPLACEMENT));
}

Value *X86Emitter::shl(Value *v, Value *amt)
{
	DEBUG_EMIT("shl", v, amt);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SHL, (X86Value *)v, (X86Value *)amt);
}

Value *X86Emitter::shr(Value *v, Value *amt)
{
	DEBUG_EMIT("shr", v, amt);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SHR, (X86Value *)v, (X86Value *)amt);
}

Value *X86Emitter::smulh(Value *lhs_, Value *rhs_)
{
	DEBUG_EMIT("smulh", lhs_, rhs_);

	auto rhs = (X86Value *)rhs_;
	auto lhs = (X86Value *)lhs_;

	if (rhs->kind() == X86ValueKind::CONSTANT)
	{
		auto rhsv = (X86Constant *)rhs;
		if (rhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (rhsv->value() == 1)
		{
			return lhs_;
		}
	}
	else if (lhs->kind() == X86ValueKind::CONSTANT)
	{
		auto lhsv = (X86Constant *)rhs;
		if (lhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (lhsv->value() == 1)
		{
			return rhs_;
		}
	}

	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SMULH, lhs, rhs);
}

Value *X86Emitter::smull(Value *lhs_, Value *rhs_)
{
	DEBUG_EMIT("smull", lhs_, rhs_);

	auto rhs = (X86Value *)rhs_;
	auto lhs = (X86Value *)lhs_;

	if (rhs->kind() == X86ValueKind::CONSTANT)
	{
		auto rhsv = (X86Constant *)rhs;
		if (rhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (rhsv->value() == 1)
		{
			return lhs_;
		}
	}
	else if (lhs->kind() == X86ValueKind::CONSTANT)
	{
		auto lhsv = (X86Constant *)rhs;
		if (lhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (lhsv->value() == 1)
		{
			return rhs_;
		}
	}

	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SMULL, lhs, rhs);
}

void X86Emitter::store_device(Value *id_, Value *offset_, Value *value_)
{
	DEBUG_EMIT("store-device", id_, offset_, value_);

	X86Value *id = (X86Value *)id_;
	X86Value *offset = (X86Value *)offset_;
	X86Value *value = (X86Value *)value_;

	auto fnp_tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)&cpu_write_device, 64), Operand::make_register(fnp_tmp, 64));

	add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0), Operand::make_register(X86Registers::RDI));
	add_mov_auto(id->as_operand(*this), Operand::make_register(X86PhysicalRegisters::SI, 64));
	add_mov_auto(offset->as_operand(*this), Operand::make_register(X86PhysicalRegisters::D, 64));
	add_mov_auto(value->as_operand(*this), Operand::make_register(X86PhysicalRegisters::C, value->type().size_in_bits()));
	add_instruction(InstructionKind::CALL, Operand::make_register(fnp_tmp, 64));
}

void X86Emitter::store_local(Value *ptr_, Value *value_)
{
	DEBUG_EMIT("store-local", ptr_, value_);

	X86LocalVariable *ptr = (X86LocalVariable *)ptr_;
	X86Value *value = (X86Value *)value_;

	if (ptr->is_global())
	{
		add_mov_auto(value->as_operand(*this), ptr->as_operand(*this));
	}
	else
	{
		if (ptr->current_value() && ptr->current_value()->type() != value->type())
		{
			context().support().assertion_fail("attempted to store static local with different type");
		}
		ptr->current_value(value);
	}

#ifdef CACHED_LOCAL_VARS
	_local_variable_state[ptr] = value;

#ifdef PDEBUG
	printf("caching %p into %p\n", value, ptr);
#endif
#else

#endif
}

void X86Emitter::emit_rdpku_dummy(Value *addr_)
{
	X86Value *addr = (X86Value *)addr_;
	auto addr_operand = addr->as_operand(*this);

	auto mode_tmp_reg = X86PhysicalRegisters::C;
	auto mask_tmp_reg = X86PhysicalRegisters::A;

	add_mov_auto(addr_operand, Operand::make_register(mode_tmp_reg, addr->type().size_in_bits()));

	add_instruction(InstructionKind::MOV, Operand::make_constant(0x3, 32), Operand::make_register(mask_tmp_reg, 32));
	add_instruction(InstructionKind::SHR, Operand::make_constant(0x2f, 8), Operand::make_register(mode_tmp_reg, 64));
	add_instruction(InstructionKind::ADD, Operand::make_register(mode_tmp_reg, 32), Operand::make_register(mode_tmp_reg, 32));
	add_instruction(InstructionKind::SHL, Operand::make_register(mode_tmp_reg, 8), Operand::make_register(mask_tmp_reg, 64));
	add_instruction(InstructionKind::NOT, Operand::make_register(mask_tmp_reg, 64));

	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::C, 32), Operand::make_register(X86PhysicalRegisters::C, 32));
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::D, 32), Operand::make_register(X86PhysicalRegisters::D, 32));
	add_instruction(InstructionKind::WRPKU);
}

void X86Emitter::store_memory(Value *addr_, Value *value_)
{
	DEBUG_EMIT("store-mem", addr_, value_);

	X86Value *addr = (X86Value *)addr_;
	X86Value *value = (X86Value *)value_;

	if (_no_mmu)
	{
		auto address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

		// Mask and Add to VM_VIRT_SPLIT
		add_instruction(InstructionKind::MOV, Operand::make_constant(VM_PHYS_GPM_BASE + VM_VIRT_SPLIT, 64), Operand::make_register(address, 64));
		add_instruction(InstructionKind::ADD, addr->as_operand(*this), Operand::make_register(address, 64));

		add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_mem(value->type().size_in_bits(), 64, address, 0))->make_volatile();
	}
	else
	{
		mmu_store_memory<captive::arch::mmu::strategy::MMUStrategyType>((X86Value *)addr_, (X86Value *)value_);
	}
}

void X86Emitter::store_pc(Value *value_)
{
	DEBUG_EMIT("store-pc", value_);

	X86Value *value = (X86Value *)value_;
	// TODO: fix this for signed-y stuff
	/*if (value->kind() == X86ValueKind::BINARY_OPERATION) {
		auto binop = (X86BinaryOperation *)value;
		if (binop->kind() == X86BinaryOperationKind::ADD) {
			if (binop->lhs()->kind() == X86ValueKind::CONSTANT && binop->rhs()->kind() == X86ValueKind::PC_REGISTER) {
				add_instruction(InstructionKind::LEA, Operand::make_mem(64, X86Registers::R15, ((X86Constant *)binop->lhs())->value()), Operand::make_register(X86Registers::R15));
				return;
			} else if (binop->rhs()->kind() == X86ValueKind::CONSTANT && binop->lhs()->kind() == X86ValueKind::PC_REGISTER) {
				add_instruction(InstructionKind::LEA, Operand::make_mem(64, X86Registers::R15, ((X86Constant *)binop->rhs())->value()), Operand::make_register(X86Registers::R15));
				return;
			}
		}
	}*/

	add_mov_auto(value->as_operand(*this), Operand::make_register(X86Registers::R15));
}

void X86Emitter::store_register(Value *offset_, Value *value_)
{
	DEBUG_EMIT("store-register", offset_, value_);

	X86Value *offset_value = (X86Value *)offset_;
	X86Value *value = (X86Value *)value_;

	if (offset_value->kind() == X86ValueKind::CONSTANT)
	{
		X86Constant *offset = (X86Constant *)offset_value;

#ifdef CONFIG_FANCY_VECTOR
		if (value->kind() == X86ValueKind::VECTOR_INSERT)
		{
			X86VectorInsert *value_vi = (X86VectorInsert *)value;

			if (value_vi->vector()->kind() == X86ValueKind::GUEST_REGISTER && value_vi->index()->kind() == X86ValueKind::CONSTANT)
			{
				X86GuestRegister *value_source_register = (X86GuestRegister *)value_vi->vector();
				X86Constant *index = (X86Constant *)value_vi->index();

				if (value_source_register->offset() == offset->value())
				{
					// YEY

					// mov[bwl] #VALUE#, offset + element * element_size (rbp)

					int32_t register_offset = offset->value();

					register_offset += index->value() * (value_vi->value()->type().size_in_bits() / 8);

					auto value_source_operand = value_vi->value()->as_operand(*this);
					add_mov_auto(value_source_operand, Operand::make_mem(value_vi->value()->type().size_in_bits(), 64, X86PhysicalRegisters::BP, register_offset));
					return;
				}
			}
		}
#endif

		auto value_operand = value->as_operand(*this);
		add_mov_auto(value_operand, Operand::make_mem(value->type().size_in_bits(), X86Registers::RBP, offset->value()));

#ifdef CACHED_GREGS
		auto fgro = _guest_register_objects.find(((X86Constant *)offset)->value());

		if (fgro != _guest_register_objects.end())
		{
			fgro->second->invalidate();
		}
#endif
	}
	else
	{
		auto offsetop = ((X86Value *)offset_)->as_operand(*this);

		assert(offsetop.is_reg());

		if (offsetop.reg.width == 8)
		{
			add_instruction(InstructionKind::AND, Operand::make_constant(0xff, 32), Operand::make_register(offsetop.reg.reg, 32));
		}
		else if (offsetop.reg.width == 16)
		{
			add_instruction(InstructionKind::AND, Operand::make_constant(0xffff, 32), Operand::make_register(offsetop.reg.reg, 32));
		}
		else if (offsetop.reg.width == 32)
		{
			add_instruction(InstructionKind::MOV, Operand::make_register(offsetop.reg.reg, 32), Operand::make_register(offsetop.reg.reg, 32));
		}

		auto value_operand = value->as_operand(*this);
		add_mov_auto(value_operand, Operand::make_mem(value->type().size_in_bits(), 64, X86PhysicalRegisters::BP, offsetop.reg.reg, MemoryScale::S1, 0));
	}
}

Value *X86Emitter::sub(Value *lhs, Value *rhs)
{
	DEBUG_EMIT("sub", lhs, rhs);
	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::SUB, (X86Value *)lhs, (X86Value *)rhs);
}

Value *X86Emitter::reinterpret(Value *value_, const dbt::el::Type &type)
{
	DEBUG_EMIT("reinterpret", value_);
	auto value = (X86Value *)value_;

	if (value->kind() == X86ValueKind::CONSTANT)
	{
		assert(value->type().size_in_bits() == type.size_in_bits());
		return _x86_context.support().alloc_obj<X86Constant>(_x86_context, type, ((X86Constant *)value)->value(), type.size_in_bits());
	}

	return _x86_context.support().alloc_obj<X86Cast>(_x86_context, X86CastKind::REINTERPRET, value, type);
}

Value *X86Emitter::convert(Value *value_, const dbt::el::Type &type)
{
	DEBUG_EMIT("convert", value_);

	auto value = (X86Value *)value_;
	assert(value->kind() != X86ValueKind::CONSTANT);

	return _x86_context.support().alloc_obj<X86Cast>(_x86_context, X86CastKind::CONVERT, value, type);
}

Value *X86Emitter::splat(Value *value_, const dbt::el::Type &type)
{
	DEBUG_EMIT("splat", value_);

	auto value = (X86Value *)value_;

	return _x86_context.support().alloc_obj<X86Cast>(_x86_context, X86CastKind::SPLAT, value, type);
}

Value *X86Emitter::sx(Value *value_, const dbt::el::Type &type)
{
	DEBUG_EMIT("sx", value_);

	auto value = (X86Value *)value_;
	assert(value->kind() != X86ValueKind::CONSTANT);

	return _x86_context.support().alloc_obj<X86Cast>(_x86_context, X86CastKind::SX, value, type);
}

void X86Emitter::trace(dbt::el::TraceEvent event, Value *o0_, Value *o1_, Value *o2_, Value *o3_)
{
	// jit_trace(captive::arch::CPU *cpu, uint64_t opcode, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4)

	auto o0 = (X86Value *)o0_;
	auto o1 = (X86Value *)o1_;
	auto o2 = (X86Value *)o2_;
	auto o3 = (X86Value *)o3_;

#if 0
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::A, 32), Operand::make_register(X86PhysicalRegisters::A, 32));
	switch (event) {
	case TraceEvent::INSTRUCTION_START:
		add_instruction(InstructionKind::OUT, Operand::make_register(X86PhysicalRegisters::A, 32), Operand::make_constant(0x30, 8));
		break;

	case TraceEvent::LOAD_REGISTER:
		add_instruction(InstructionKind::OUT, Operand::make_register(X86PhysicalRegisters::A, 32), Operand::make_constant(0x31, 8));
		break;

	case TraceEvent::STORE_REGISTER:
		add_instruction(InstructionKind::OUT, Operand::make_register(X86PhysicalRegisters::A, 32), Operand::make_constant(0x32, 8));
		break;

	case TraceEvent::LOAD_MEMORY:
		add_instruction(InstructionKind::OUT, Operand::make_register(X86PhysicalRegisters::A, 32), Operand::make_constant(0x33, 8));
		break;

	case TraceEvent::STORE_MEMORY:
		add_instruction(InstructionKind::OUT, Operand::make_register(X86PhysicalRegisters::A, 32), Operand::make_constant(0x34, 8));
		break;

	default:
		DEBUG_EMIT("trace ???", o0, o1, o2, o3);
		break;
	}
#endif

#if 1

#if 1
	add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0), Operand::make_register(X86Registers::RDI));
	add_instruction(InstructionKind::MOV, Operand::make_constant((int)event, 32), Operand::make_register(X86Registers::ESI));

	if (o0)
	{
		int size = o0->type().size_in_bits();
		if (size > 64)
			size = 64;

		auto o0o = o0->as_operand(*this);
		if (o0o.is_mem() && o0o.mem.access_width == 128)
		{
			o0o.mem.access_width = 64;
		}

		add_mov_auto(o0o, Operand::make_register(X86PhysicalRegisters::D, size));
	}

	if (o1)
	{
		int size = o1->type().size_in_bits();
		if (size > 64)
			size = 64;

		auto o1o = o1->as_operand(*this);
		if (o1o.is_mem() && o1o.mem.access_width == 128)
		{
			o1o.mem.access_width = 64;
		}

		add_mov_auto(o1o, Operand::make_register(X86PhysicalRegisters::C, size));
	}

	if (o2)
	{
		int size = o2->type().size_in_bits();
		if (size > 64)
			size = 64;

		auto o2o = o2->as_operand(*this);
		if (o2o.is_mem() && o2o.mem.access_width == 128)
		{
			o2o.mem.access_width = 64;
		}

		add_mov_auto(o2o, Operand::make_register(X86PhysicalRegisters::R8, size));
	}

	switch (event)
	{
	case TraceEvent::INSTRUCTION_START:
		DEBUG_EMIT("trace start", o0, o1, o2, o3);
		break;

	case TraceEvent::LOAD_REGISTER:
		DEBUG_EMIT("trace ldreg", o0, o1, o2, o3);
		break;

	case TraceEvent::STORE_REGISTER:
		DEBUG_EMIT("trace streg", o0, o1, o2, o3);
		break;

	case TraceEvent::LOAD_MEMORY:
		DEBUG_EMIT("trace ldmem", o0, o1, o2, o3);
		break;

	case TraceEvent::STORE_MEMORY:
		DEBUG_EMIT("trace stmem", o0, o1, o2, o3);
		break;

	default:
		DEBUG_EMIT("trace ???", o0, o1, o2, o3);
		break;
	}

	auto fnp_tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)&jit_trace, 64), Operand::make_register(fnp_tmp, 64));
	add_instruction(InstructionKind::CALL, Operand::make_register(fnp_tmp, 64));
#else
	auto buffer_base = X86PhysicalRegisters::create_virtual(X86RegisterClasses::GENERAL_PURPOSE, _x86_context.alloc_vreg());
	add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 40), Operand::make_register(buffer_base, 64));

	auto tail = X86PhysicalRegisters::create_virtual(X86RegisterClasses::GENERAL_PURPOSE, _x86_context.alloc_vreg());
	add_instruction(InstructionKind::MOVZX, Operand::make_mem(8, 64, buffer_base, 1), Operand::make_register(tail, 32));

	int amount = 1;
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)event, 64), Operand::make_mem(64, 64, buffer_base, tail, MemoryScale::S8, 0));

	if (o0)
	{
		add_instruction(InstructionKind::MOV, o0->as_operand(*this), Operand::make_mem(64, 64, buffer_base, tail, MemoryScale::S8, 8));
		amount++;
	}

	if (o1)
	{
		add_instruction(InstructionKind::MOV, o1->as_operand(*this), Operand::make_mem(64, 64, buffer_base, tail, MemoryScale::S8, 16));
		amount++;
	}

	if (o2)
	{
		add_instruction(InstructionKind::MOV, o2->as_operand(*this), Operand::make_mem(64, 64, buffer_base, tail, MemoryScale::S8, 32));
		amount++;
	}

	// increment tail
	add_instruction(InstructionKind::ADD, Operand::make_constant(amount, 8), Operand::make_register(tail, 8));
	add_instruction(InstructionKind::MOV, Operand::make_register(tail, 8), Operand::make_mem(8, 64, buffer_base, 1));
#endif
#endif
}

Value *X86Emitter::truncate(Value *val, const dbt::el::Type &type)
{
	DEBUG_EMIT("trunc", val);
	return _x86_context.support().alloc_obj<X86Cast>(_x86_context, X86CastKind::TRUNCATE, (X86Value *)val, type);
}

Value *X86Emitter::umulh(Value *lhs_, Value *rhs_)
{
	DEBUG_EMIT("umulh", lhs_, rhs_);

	auto rhs = (X86Value *)rhs_;
	auto lhs = (X86Value *)lhs_;

	if (rhs->kind() == X86ValueKind::CONSTANT)
	{
		auto rhsv = (X86Constant *)rhs;
		if (rhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (rhsv->value() == 1)
		{
			return lhs_;
		}
	}
	else if (lhs->kind() == X86ValueKind::CONSTANT)
	{
		auto lhsv = (X86Constant *)rhs;
		if (lhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (lhsv->value() == 1)
		{
			return rhs_;
		}
	}

	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::UMULH, lhs, rhs);
}

Value *X86Emitter::umull(Value *lhs_, Value *rhs_)
{
	DEBUG_EMIT("umull", lhs_, rhs_);

	auto rhs = (X86Value *)rhs_;
	auto lhs = (X86Value *)lhs_;

	if (rhs->kind() == X86ValueKind::CONSTANT)
	{
		auto rhsv = (X86Constant *)rhs;
		if (rhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (rhsv->value() == 1)
		{
			return lhs_;
		}
	}
	else if (lhs->kind() == X86ValueKind::CONSTANT)
	{
		auto lhsv = (X86Constant *)rhs;
		if (lhsv->value() == 0)
		{
			return _x86_context.support().alloc_obj<X86Constant>(_x86_context, lhs_->type(), (uint64_t)0, lhs_->type().size_in_bits());
		}
		else if (lhsv->value() == 1)
		{
			return rhs_;
		}
	}

	return _x86_context.support().alloc_obj<X86BinaryOperation>(_x86_context, X86BinaryOperationKind::UMULL, lhs, rhs);
}

Value *X86Emitter::zx(Value *value_, const dbt::el::Type &type)
{
	DEBUG_EMIT("zx", value_);

	auto value = (X86Value *)value_;
	if (value->kind() == X86ValueKind::CONSTANT)
	{
		auto const_val = (X86Constant *)value;
		return _x86_context.support().alloc_obj<X86Constant>(_x86_context, type, const_val->value(), type.size_in_bits());
	}
	else
	{
		return _x86_context.support().alloc_obj<X86Cast>(_x86_context, X86CastKind::ZX, value, type);
	}
}

void X86Emitter::set_feature(dbt_u32 feature, Value *value_)
{
	DEBUG_EMIT("set-feature");

	uint64_t feature_bit = (1ull << (uint64_t)feature);
	_used_features |= feature_bit;

	auto value = (X86Value *)value_;

	if (value->kind() == X86ValueKind::CONSTANT)
	{
		if (((X86Constant *)value)->value() == 0)
		{
			add_instruction(InstructionKind::AND, Operand::make_constant(~feature_bit, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x60));
		}
		else
		{
			add_instruction(InstructionKind::OR, Operand::make_constant(feature_bit, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x60));
		}
	}
	else
	{
		auto tmp = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		auto bku = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x60), Operand::make_register(tmp, 64));
		add_instruction(InstructionKind::MOV, Operand::make_register(tmp, 64), Operand::make_register(bku, 64));
		add_instruction(InstructionKind::AND, Operand::make_constant(~feature_bit, 64), Operand::make_register(tmp, 64));
		add_instruction(InstructionKind::OR, Operand::make_constant(feature_bit, 64), Operand::make_register(bku, 64));

		auto value_operand = value->as_operand(*this);
		add_instruction(InstructionKind::TEST, value_operand, value_operand);
		add_instruction(InstructionKind::CMOVNE, Operand::make_register(bku, 64), Operand::make_register(tmp, 64));
		add_instruction(InstructionKind::MOV, Operand::make_register(tmp, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x60));
	}
}

Value *X86Emitter::vector_extract(Value *vct_, Value *idx_)
{
	DEBUG_EMIT("vector-extract", vct_, idx_);

#ifdef CONFIG_FANCY_VECTOR
	return _x86_context.support().alloc_obj<X86VectorExtract>(_x86_context, (X86Value *)vct_, (X86Value *)idx_);
#else
	auto vector = (X86Value *)vct_;
	auto index = (X86Value *)idx_;

	assert(vector->type().is_vector());

	if (index->kind() == X86ValueKind::CONSTANT)
	{
		auto element_index = ((X86Constant *)index)->value();

#if 1
		if (vector->kind() == X86ValueKind::GUEST_REGISTER)
		{
			uint64_t offset = ((X86GuestRegister *)vector)->offset() + (element_index * (vector->type().vector_element_size_in_bits() / 8));
			return _x86_context.support().alloc_obj<X86GuestRegister>(_x86_context, vector->type().element_type(), offset);

			/*switch (vector->type().vector_element_size_in_bits()) {
			case 8:
				return _x86_context.support().alloc_obj<X86GuestRegister>(_x86_context, is_signed ? _x86_context.types().s8() : _x86_context.types().u8(), offset);

			case 16:
				return _x86_context.support().alloc_obj<X86GuestRegister>(_x86_context, is_signed ? _x86_context.types().s16() : _x86_context.types().u16(), offset);

			case 32:
				return _x86_context.support().alloc_obj<X86GuestRegister>(_x86_context, is_signed ? _x86_context.types().s32() : _x86_context.types().u32(), offset);

			case 64:
				return _x86_context.support().alloc_obj<X86GuestRegister>(_x86_context, is_signed ? _x86_context.types().s64() : _x86_context.types().u64(), offset);

			default:
				UNIMPLEMENTED;
			}*/
		}
#endif

		auto tmp_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		auto tmp = Operand::make_register(tmp_reg, vector->type().vector_element_size_in_bits());

		auto vector_operand = vector->as_operand(*this);

		if (vector_operand.is_mem())
		{
			auto vtmp_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
			add_mov_auto(vector_operand, Operand::make_register(vtmp_reg, 128));
			vector_operand = Operand::make_register(vtmp_reg, 128);
		}

		assert(vector_operand.is_reg());

		vector_operand.reg.width = 128;

		switch (vector->type().vector_element_size_in_bits())
		{
		case 8:
			add_instruction(InstructionKind::PEXTRB, Operand::make_constant(element_index, 8), vector_operand, Operand::make_register(tmp_reg, 32));
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, vector->type().element_type(), tmp);

		case 16:
			add_instruction(InstructionKind::PEXTRW, Operand::make_constant(element_index, 8), vector_operand, Operand::make_register(tmp_reg, 32));
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, vector->type().element_type(), tmp);

		case 32:
			add_instruction(InstructionKind::PEXTRD, Operand::make_constant(element_index, 8), vector_operand, Operand::make_register(tmp_reg, 32));
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, vector->type().element_type(), tmp);

		case 64:
			add_instruction(InstructionKind::PEXTRQ, Operand::make_constant(element_index, 8), vector_operand, Operand::make_register(tmp_reg, 64));
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, vector->type().element_type(), tmp);

		default:
			UNIMPLEMENTED;
		}
	}
	else
	{
		UNIMPLEMENTED;
	}
#endif
}

Value *X86Emitter::vector_insert(Value *vct_, Value *idx_, Value *val_)
{
	DEBUG_EMIT("vector-insert", vct_, idx_, val_);

#ifdef CONFIG_FANCY_VECTOR
	return _x86_context.support().alloc_obj<X86VectorInsert>(_x86_context, (X86Value *)vct_, (X86Value *)idx_, (X86Value *)val_);
#else
	auto vector = (X86Value *)vct_;
	auto index = (X86Value *)idx_;
	auto value = (X86Value *)val_;

	assert(vector->type().is_vector());

	if (index->kind() == X86ValueKind::CONSTANT)
	{
		auto tmp_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
		auto tmp = Operand::make_register(tmp_reg, 128);

		auto element_index = ((X86Constant *)index)->value();
		auto value_operand = value->as_operand(*this);

		/*if (value_operand.is_mem()) {
			auto tmp_reg2 = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
			auto tmp2 = Operand::make_register(tmp_reg2, 128);

			add_mov_auto(value_operand, tmp2);
			value_operand = tmp2;
		}*/

		assert(value_operand.is_reg() || value_operand.is_mem() || value_operand.is_const());

		if (value_operand.is_reg())
		{
			if (value->type().is_floating())
			{
				auto tmp_reg2 = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
				auto tmp2 = Operand::make_register(tmp_reg2, vector->type().vector_element_size_in_bits() == 64 ? 64 : 32);

				add_mov_auto(value_operand, tmp2);
				value_operand = tmp2;
			}
			else
			{
				value_operand.reg.width = vector->type().vector_element_size_in_bits() == 64 ? 64 : 32;
			}
		}
		else if (value_operand.is_mem())
		{
			value_operand.mem.access_width = vector->type().vector_element_size_in_bits() == 64 ? 64 : 32;
		}
		else if (value_operand.is_const())
		{
			auto tmp_reg2 = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			auto tmp2 = Operand::make_register(tmp_reg2, vector->type().vector_element_size_in_bits() == 64 ? 64 : 32);

			add_mov_auto(value_operand, tmp2);
			value_operand = tmp2;
		}

		add_mov_auto(vector->as_operand(*this), tmp);
		switch (vector->type().vector_element_size_in_bits())
		{
		case 8:
			add_instruction(InstructionKind::PINSRB, Operand::make_constant(element_index, 8), value_operand, Operand::make_register(tmp_reg, 128));
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, vector->type(), tmp);

		case 16:
			add_instruction(InstructionKind::PINSRW, Operand::make_constant(element_index, 8), value_operand, Operand::make_register(tmp_reg, 128));
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, vector->type(), tmp);

		case 32:
			add_instruction(InstructionKind::PINSRD, Operand::make_constant(element_index, 8), value_operand, Operand::make_register(tmp_reg, 128));
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, vector->type(), tmp);

		case 64:
			add_instruction(InstructionKind::PINSRQ, Operand::make_constant(element_index, 8), value_operand, Operand::make_register(tmp_reg, 128));
			return _x86_context.support().alloc_obj<X86Operand>(_x86_context, vector->type(), tmp);

		default:
			UNIMPLEMENTED;
		}
	}
	else
	{
		UNIMPLEMENTED;
	}
#endif
}

void X86Emitter::append_instruction(dbt::mc::x86::Instruction *insn)
{
	X86Block *block = (X86Block *)get_current_block();
	block->head()->prev()->insert_after(insn);
}

captive::arch::dbt::mc::x86::Instruction *X86Emitter::add_mov_auto(const captive::arch::dbt::mc::x86::Operand &src, const captive::arch::dbt::mc::x86::Operand &dst)
{
	auto msrc = src;
	auto mdst = dst;

	InstructionKind::InstructionKind mov_kind;

	if (src.is_reg() && dst.is_reg())
	{
		// REG -> REG

		if (src.reg.reg.is_gpr() && dst.reg.reg.is_gpr())
		{
			// GPR -> GPR
			assert(src.reg.width == dst.reg.width);
			mov_kind = InstructionKind::MOV;
		}
		else if (src.reg.reg.is_gpr() && dst.reg.reg.is_sse())
		{
			// GPR -> SSE
			assert(src.reg.width == 8 || src.reg.width == 16 || src.reg.width == 32 || src.reg.width == 64);
			assert(dst.reg.width == 128);

			if (src.reg.width == 8)
			{
				add_instruction(InstructionKind::MOVZX, Operand::make_register(src.reg.reg, 8), Operand::make_register(src.reg.reg, 32));
				msrc.reg.width = 32;
				mov_kind = InstructionKind::MOVD;
			}
			else if (src.reg.width == 16)
			{
				add_instruction(InstructionKind::MOVZX, Operand::make_register(src.reg.reg, 16), Operand::make_register(src.reg.reg, 32));
				msrc.reg.width = 32;
				mov_kind = InstructionKind::MOVD;
			}
			else if (src.reg.width == 32)
			{
				mov_kind = InstructionKind::MOVD;
			}
			else if (src.reg.width == 64)
			{
				mov_kind = InstructionKind::MOVQ;
			}
			else
			{
				UNIMPLEMENTED;
			}
		}
		else if (src.reg.reg.is_sse() && dst.reg.reg.is_gpr())
		{
			// SSE -> GPR
			assert(src.reg.width == 128);
			assert(dst.reg.width == 32 || dst.reg.width == 64);

			if (dst.reg.width == 32)
			{
				mov_kind = InstructionKind::MOVD;
			}
			else if (dst.reg.width == 64)
			{
				mov_kind = InstructionKind::MOVQ;
			}
			else
			{
				UNIMPLEMENTED;
			}
		}
		else if (src.reg.reg.is_sse() && dst.reg.reg.is_sse())
		{
			// SSE -> SSE
			//assert(src.reg.width == dst.reg.width);
			//assert(src.reg.width == 128);

			if (src.reg.width == 32)
			{
				mov_kind = InstructionKind::MOVQ;
				msrc.reg.width = 128;
				mdst.reg.width = 128;
			}
			else if (src.reg.width == 64)
			{
				mov_kind = InstructionKind::MOVQ;
				msrc.reg.width = 128;
				mdst.reg.width = 128;
			}
			else if (src.reg.width == 128)
			{
				mov_kind = InstructionKind::MOVDQA;
			}
			else
			{
				UNIMPLEMENTED;
			}
		}
		else
		{
			UNIMPLEMENTED;
		}
	}
	else if (src.is_reg() && dst.is_mem())
	{
		// REG -> MEM
		if (src.reg.reg.is_gpr())
		{
			// GPR -> MEM
			assert(src.reg.width == dst.mem.access_width);
			mov_kind = InstructionKind::MOV;
		}
		else if (src.reg.reg.is_sse())
		{
			// SSE -> MEM
			// assert(src.reg.width == 128);
			assert(dst.mem.access_width == 32 || dst.mem.access_width == 64 || dst.mem.access_width == 128);
			switch (dst.mem.access_width)
			{
			case 32:
				mov_kind = InstructionKind::MOVD;
				msrc.reg.width = 128;
				break;
			case 64:
				mov_kind = InstructionKind::MOVQ;
				msrc.reg.width = 128;
				break;
			case 128:
				assert(src.reg.width == 128);
				mov_kind = InstructionKind::MOVDQA;
				break;
			default:
				UNIMPLEMENTED;
			}
		}
		else
		{
			UNIMPLEMENTED;
		}
	}
	else if (src.is_mem() && dst.is_reg())
	{
		// MEM -> REG
		if (dst.reg.reg.is_gpr())
		{
			// MEM -> GPR
			assert(src.mem.access_width == dst.reg.width);
			mov_kind = InstructionKind::MOV;
		}
		else if (dst.reg.reg.is_sse())
		{
			// MEM -> SSE
			assert(src.mem.access_width == 8 || src.mem.access_width == 16 || src.mem.access_width == 32 || src.mem.access_width == 64 || src.mem.access_width == 128);
			//assert(dst.reg.width == 128);

			switch (src.mem.access_width)
			{
			case 8:
			{
				auto tmp_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

				add_instruction(InstructionKind::MOVZX, src, Operand::make_register(tmp_reg, 32));

				msrc = Operand::make_register(tmp_reg, 32);
				mov_kind = InstructionKind::MOVD;
				mdst.reg.width = 128;
				break;
			}

			case 16:
			{
				auto tmp_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

				add_instruction(InstructionKind::MOVZX, src, Operand::make_register(tmp_reg, 32));

				msrc = Operand::make_register(tmp_reg, 32);
				mov_kind = InstructionKind::MOVD;
				mdst.reg.width = 128;
				break;
			}

			case 32:
				mov_kind = InstructionKind::MOVD;
				mdst.reg.width = 128;
				break;
			case 64:
				mov_kind = InstructionKind::MOVQ;
				mdst.reg.width = 128;
				break;
			case 128:
				assert(dst.reg.width == 128);
				mov_kind = InstructionKind::MOVDQA;
				break;
			default:
				UNIMPLEMENTED;
			}
		}
		else
		{
			UNIMPLEMENTED;
		}
	}
	else if (src.is_mem() && dst.is_mem())
	{
		// MEM -> MEM

		assert(src.mem.access_width == dst.mem.access_width);

		if (src.mem.access_width == 128)
		{
			auto tmp_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::SSE);
			add_instruction(InstructionKind::MOVDQA, src, Operand::make_register(tmp_reg, 128));
			mov_kind = InstructionKind::MOVDQA;
			msrc = Operand::make_register(tmp_reg, 128);
		}
		else
		{
			auto tmp_reg = _vreg_allocator.alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			add_instruction(InstructionKind::MOV, src, Operand::make_register(tmp_reg, src.mem.access_width));
			mov_kind = InstructionKind::MOV;
			msrc = Operand::make_register(tmp_reg, src.mem.access_width);
		}
	}
	else if (src.is_const() && dst.is_reg())
	{
		// assert(src.constant.width == dst.reg.width);

		// CONST -> REG
		if (dst.reg.reg.is_gpr())
		{
			// CONST -> GPR
			mov_kind = InstructionKind::MOV;
		}
		else if (dst.reg.reg.is_sse())
		{
			// CONST -> SSE
			if (src.constant.value == 0)
			{
				return add_instruction(InstructionKind::PXOR, dst, dst);
			}
			else
			{
				UNIMPLEMENTED;
			}
		}
		else
		{
			UNIMPLEMENTED;
		}
	}
	else if (src.is_const() && dst.is_mem())
	{
		// assert(src.constant.width == dst.mem.access_width);

		// CONST -> MEM
		mov_kind = InstructionKind::MOV;
	}
	else if (src.is_invalid() || dst.is_invalid())
	{
		assert(false && "invalid operands");
	}
	else
	{
		printf("src:%d, dst:%d\n", src.kind, dst.kind);
		UNIMPLEMENTED;
	}

	return add_instruction(mov_kind, msrc, mdst);
}

void X86Emitter::dump() const
{
	printf("*** DUMP ***\n");

	Formatter fmt;
	Instruction *current = ((X86Block *)get_current_block())->head();
	do
	{
		printf("%s\n", fmt.format_instruction(current));
		current = current->next();
	} while (current != ((X86Block *)get_current_block())->head());
}

void X86Emitter::increment_pca()
{
	add_instruction(InstructionKind::ADD, Operand::make_constant(1, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x38));
}

void X86Emitter::increment_pcb()
{
	add_instruction(InstructionKind::ADD, Operand::make_constant(1, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x40));
}

void X86Emitter::increment_icount()
{
	add_instruction(InstructionKind::ADD, Operand::make_constant(1, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x38));
}

void X86Emitter::super_chain_direct(dbt_u64 target, void *default_target)
{
	// Interrupt Check
	add_instruction(InstructionKind::CMP, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));
	auto jmp_to_exit = add_instruction(InstructionKind::JNZ);

	// Chain Exit
	add_instruction(InstructionKind::MOV, Operand::make_constant((dbt_u64)default_target, 64), Operand::make_register(X86PhysicalRegisters::A, 64));
	add_instruction(InstructionKind::JMP, Operand::make_register(X86PhysicalRegisters::A, 64));

	// Interrupt Exit
	auto exit_label = add_instruction(InstructionKind::LABEL);
	jmp_to_exit->set_operand(0, Operand::make_label(exit_label));
	add_instruction(InstructionKind::MOV, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));
	add_instruction(InstructionKind::MOV, Operand::make_constant((dbt_u64)&block_trampoline_epilogue_normal, 64), Operand::make_register(X86PhysicalRegisters::A, 64));
	add_instruction(InstructionKind::JMP, Operand::make_register(X86PhysicalRegisters::A, 64));
}

void X86Emitter::super_chain_direct_predicated(dbt_u64 target, dbt_u64 fallthrough, void *default_target, void *default_fallthrough)
{
	// Interrupt Check
	add_instruction(InstructionKind::CMP, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));
	auto jmp_to_exit = add_instruction(InstructionKind::JNZ);

	// Chain Exit
	add_instruction(InstructionKind::MOV, Operand::make_constant((dbt_u64)default_target, 64), Operand::make_register(X86PhysicalRegisters::A, 64));
	add_instruction(InstructionKind::MOV, Operand::make_constant((dbt_u64)default_fallthrough, 64), Operand::make_register(X86PhysicalRegisters::C, 64));

	add_instruction(InstructionKind::MOV, Operand::make_constant(target & 0xfffull, 32), Operand::make_register(X86PhysicalRegisters::D, 32));
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::R15, 32), Operand::make_register(X86PhysicalRegisters::B, 32));
	add_instruction(InstructionKind::AND, Operand::make_constant(0xfff, 32), Operand::make_register(X86PhysicalRegisters::B, 32));
	add_instruction(InstructionKind::CMP, Operand::make_register(X86PhysicalRegisters::B, 32), Operand::make_register(X86PhysicalRegisters::D, 32));
	add_instruction(InstructionKind::CMOVNE, Operand::make_register(X86PhysicalRegisters::C, 64), Operand::make_register(X86PhysicalRegisters::A, 64));

	add_instruction(InstructionKind::JMP, Operand::make_register(X86PhysicalRegisters::A, 64));

	// Interrupt Exit
	auto exit_label = add_instruction(InstructionKind::LABEL);
	jmp_to_exit->set_operand(0, Operand::make_label(exit_label));
	add_instruction(InstructionKind::MOV, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));
	add_instruction(InstructionKind::MOV, Operand::make_constant((dbt_u64)&block_trampoline_epilogue_normal, 64), Operand::make_register(X86PhysicalRegisters::A, 64));
	add_instruction(InstructionKind::JMP, Operand::make_register(X86PhysicalRegisters::A, 64));
}

//add_instruction(InstructionKind::CMP, Operand::make_constant(0, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x30));
//auto jmp_to_exit = add_instruction(InstructionKind::JNZ);
