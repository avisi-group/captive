/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/common.h>
#include <dbt/el/value.h>
#include <dbt/el/context.h>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace el {
				class Context;
				class Block;
				class Value;
				class Type;

				enum class TraceEvent {
					INSTRUCTION_START,
					INSTRUCTION_END,

					LOAD_MEMORY,
					STORE_MEMORY,

					LOAD_REGISTER,
					STORE_REGISTER,

					LOAD_DEVICE,
					STORE_DEVICE,

					NOT_TAKEN,
					EXCEPTION,
				};

				class Emitter {
				public:

					Emitter(Context& context, Block *current_block) : _context(context), _current_block(current_block)
					{
					}
					virtual ~Emitter();

					Context& context() const
					{
						return _context;
					}

					void set_current_block(Block *block)
					{
						_current_block = block;
					}

					Block *get_current_block() const
					{
						return _current_block;
					}

					virtual Value *constant(dbt_u64 value, const Type& type) = 0;
					virtual Value *constant(dbt_f32 value, const Type& type) = 0;
					virtual Value *constant(dbt_f64 value, const Type& type) = 0;

					virtual Value *constant_vector_splat(dbt_u64 value, const Type& type) = 0;
					virtual Value *constant_vector_splat_f(dbt_f32 value, const Type& type) = 0;
					virtual Value *constant_vector_splat_f(dbt_f64 value, const Type& type) = 0;

					/*template<class T>
					inline Value *const_vector(std::initializer_list<T> elements, const Type& type)
					{
						return constant_vector_splat(0, type);
					}*/

					inline Value *const_u8(dbt_u8 value)
					{
						return constant((dbt_u64) value, _context.types().u8());
					}

					inline Value *const_u16(dbt_u16 value)
					{
						return constant((dbt_u64) value, _context.types().u16());
					}

					inline Value *const_u32(dbt_u32 value)
					{
						return constant((dbt_u64) value, _context.types().u32());
					}

					inline Value *const_u64(dbt_u64 value)
					{
						return constant((dbt_u64) value, _context.types().u64());
					}

					inline Value *const_s8(dbt_s8 value)
					{
						return constant((dbt_u64) value, _context.types().s8());
					}

					inline Value *const_s16(dbt_s16 value)
					{
						return constant((dbt_u64) value, _context.types().s16());
					}

					inline Value *const_s32(dbt_s32 value)
					{
						return constant((dbt_u64) value, _context.types().s32());
					}

					inline Value *const_s64(dbt_s64 value)
					{
						return constant((dbt_u64) value, _context.types().s64());
					}

					inline Value *const_f32(dbt_f32 value)
					{
						return constant(value, _context.types().f32());
					}

					inline Value *const_f64(dbt_f64 value)
					{
						return constant(value, _context.types().f64());
					}

					void mark_used_feature(dbt_u32 feature);

					virtual Value *alloc_local(const Type& type, bool is_global) = 0;
					virtual Value *load_local(Value *ptr, const Type& type) = 0;
					virtual void store_local(Value *ptr, Value *value) = 0;

					virtual Value *load_register(Value *offset, const Type& type) = 0;
					virtual void store_register(Value *offset, Value *value) = 0;

					virtual Value *load_pc() = 0;
					virtual void store_pc(Value *value) = 0;
					virtual void inc_pc(Value *amount) = 0;

					virtual Value *load_memory(Value *addr, const Type& type) = 0;
					virtual void store_memory(Value *addr, Value *value) = 0;

					virtual Value *load_device(Value *id, Value *offset, const Type& type) = 0;
					virtual void store_device(Value *id, Value *offset, Value *value) = 0;

					virtual Value *add(Value *lhs, Value *rhs) = 0;
					virtual Value *adc(Value *lhs, Value *rhs, Value *carry) = 0;
					virtual Value *adcf(Value *lhs, Value *rhs, Value *carry) = 0;
					virtual Value *sub(Value *lhs, Value *rhs) = 0;
					virtual Value *sbc(Value *lhs, Value *rhs, Value *carry) = 0;
					virtual Value *sbcf(Value *lhs, Value *rhs, Value *carry) = 0;
					virtual Value *mul(Value *lhs, Value *rhs) = 0;
					virtual Value *div(Value *lhs, Value *rhs) = 0;
					virtual Value *mod(Value *lhs, Value *rhs) = 0;
					virtual Value *smull(Value *lhs, Value *rhs) = 0;
					virtual Value *smulh(Value *lhs, Value *rhs) = 0;
					virtual Value *umull(Value *lhs, Value *rhs) = 0;
					virtual Value *umulh(Value *lhs, Value *rhs) = 0;
					virtual Value *neg(Value *v) = 0;
					virtual Value *sqrt(Value *v) = 0;

					virtual void set_zn(Value *v) = 0;

					virtual Value *shl(Value *v, Value *amt) = 0;
					virtual Value *shr(Value *v, Value *amt) = 0;
					virtual Value *sar(Value *v, Value *amt) = 0;
					virtual Value *rol(Value *v, Value *amt) = 0;
					virtual Value *ror(Value *v, Value *amt) = 0;

					virtual Value *clz(Value *v) = 0;

					virtual Value *bitwise_and(Value *lhs, Value *rhs) = 0;
					virtual Value *bitwise_or(Value *lhs, Value *rhs) = 0;
					virtual Value *bitwise_xor(Value *lhs, Value *rhs) = 0;
					virtual Value *bitwise_not(Value *v) = 0;
					virtual Value *bswap(Value *v) = 0;

					virtual Value *cmp_eq(Value *lhs, Value *rhs) = 0;
					virtual Value *cmp_ne(Value *lhs, Value *rhs) = 0;
					virtual Value *cmp_lt(Value *lhs, Value *rhs) = 0;
					virtual Value *cmp_le(Value *lhs, Value *rhs) = 0;
					virtual Value *cmp_gt(Value *lhs, Value *rhs) = 0;
					virtual Value *cmp_ge(Value *lhs, Value *rhs) = 0;

					virtual Value *truncate(Value *val, const Type& type) = 0;
					virtual Value *zx(Value *val, const Type& type) = 0;
					virtual Value *sx(Value *val, const Type& type) = 0;
					virtual Value *reinterpret(Value *val, const Type& type) = 0;
					virtual Value *convert(Value *val, const Type& type) = 0;
					virtual Value *splat(Value *val, const Type& type) = 0;

					virtual void set_feature(dbt_u32 feature, Value *value) = 0;

					virtual Value *select(Value *cond, Value *tv, Value *fv) = 0;
					virtual void jump(Block *target) = 0;
					virtual void branch(Value *predicate, Block *true_target, Block *false_target) = 0;
					virtual void chain(dbt_u64 target, dbt_u64 fallthrough, void *target_ptr, void *ft_ptr) = 0;
					virtual void super_chain_direct(dbt_u64 target, void *default_target) = 0;
					virtual void super_chain_direct_predicated(dbt_u64 target, dbt_u64 fallthrough, void *default_target, void *default_fallthrough) = 0;
					virtual void leave(Value *value = nullptr) = 0;
					virtual void raise(Value *value = nullptr) = 0;
					virtual Value *call(void *fnp, Value *o0 = nullptr, Value *o1 = nullptr, Value *o2 = nullptr, Value *o3 = nullptr) = 0;

					virtual void enter_kernel_mode() = 0;
					virtual void enter_user_mode() = 0;

					virtual void block_start(dbt_u64 addr, dbt_u32 feature_set) = 0;
					virtual void block_end(dbt_u32 feature_set) = 0;
					virtual void instruction_start(dbt_u64 addr) = 0;
					virtual void instruction_end(dbt_u64 addr, bool end_of_block) = 0;
					virtual void trace(TraceEvent event, Value *o0 = nullptr, Value *o1 = nullptr, Value *o2 = nullptr, Value *o3 = nullptr) = 0;

					virtual Value *vector_extract(Value *vct, Value *index) = 0;
					virtual Value *vector_insert(Value *vct, Value *index, Value *value) = 0;

				private:
					Context& _context;
					Block *_current_block;
				};
			}
		}
	}
}
