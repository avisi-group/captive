/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/el/emitter.h>

namespace captive {
	namespace arch {
		namespace jit {
			using namespace dbt::el;

			class MonitorEmitter : public Emitter {
			public:

				MonitorEmitter(Emitter& other) : Emitter(other.context(), other.get_current_block()), _other(other)
				{
				}

				virtual ~MonitorEmitter()
				{
				}

				Value* adc(Value* lhs, Value* rhs, Value* carry) override;
				Value* adcf(Value* lhs, Value* rhs, Value* carry) override;
				Value* add(Value* lhs, Value* rhs) override;
				Value* alloc_local(const Type& type, bool is_global) override;
				Value* bitwise_and(Value* lhs, Value* rhs) override;

				Value* bitwise_not(Value* v) override;
				Value* bitwise_or(Value* lhs, Value* rhs) override;
				Value* bitwise_xor(Value* lhs, Value* rhs) override;
				void block_end(dbt_u32 feature_set) override;
				void block_start(dbt_u64 addr, dbt_u32 feature_set) override;
				void branch(Value* predicate, Block* true_target, Block* false_target) override;
				Value* bswap(Value* v) override;
				Value* call(void* fnp, Value* o0, Value* o1, Value* o2, Value* o3) override;
				void chain(dbt_u64 target, dbt_u64 fallthrough, void* target_ptr, void* ft_ptr) override;
				Value* clz(Value* v) override;
				Value* cmp_eq(Value* lhs, Value* rhs) override;
				Value* cmp_ge(Value* lhs, Value* rhs) override;
				Value* cmp_gt(Value* lhs, Value* rhs) override;
				Value* cmp_le(Value* lhs, Value* rhs) override;
				Value* cmp_lt(Value* lhs, Value* rhs) override;
				Value* cmp_ne(Value* lhs, Value* rhs) override;
				Value* constant(dbt_f64 value, const Type& type) override;
				Value* constant(dbt_u64 value, const Type& type) override;
				Value* constant(dbt_f32 value, const Type& type) override;
				Value* constant_vector_splat(dbt_u64 value, const Type& type) override;
				Value* convert(Value* val, const Type& type) override;
				Value* div(Value* lhs, Value* rhs) override;
				void enter_kernel_mode() override;
				void enter_user_mode() override;
				void inc_pc(Value* amount) override;
				void instruction_end(dbt_u64 addr, bool end_of_block) override;
				void instruction_start(dbt_u64 addr) override;
				void jump(Block* target) override;
				void leave(Value* value) override;
				Value* load_device(Value* id, Value* offset, const Type& type) override;
				Value* load_local(Value* ptr, const Type& type) override;
				Value* load_memory(Value* addr, const Type& type) override;
				Value* load_pc() override;
				Value* load_register(Value* offset, const Type& type) override;
				Value* mod(Value* lhs, Value* rhs) override;
				Value* mul(Value* lhs, Value* rhs) override;
				Value* neg(Value* v) override;
				void raise(Value* value) override;
				Value* reinterpret(Value* val, const Type& type) override;
				Value* rol(Value* v, Value* amt) override;
				Value* ror(Value* v, Value* amt) override;
				Value* sar(Value* v, Value* amt) override;
				Value* sbc(Value* lhs, Value* rhs, Value* carry) override;
				Value* sbcf(Value* lhs, Value* rhs, Value* carry) override;
				void set_feature(dbt_u32 feature, Value* value) override;
				void set_zn(Value* v) override;
				Value* shl(Value* v, Value* amt) override;
				Value* shr(Value* v, Value* amt) override;
				Value* smulh(Value* lhs, Value* rhs) override;
				Value* smull(Value* lhs, Value* rhs) override;
				Value* sqrt(Value* v) override;
				void store_device(Value* id, Value* offset, Value* value) override;
				void store_local(Value* ptr, Value* value) override;
				void store_memory(Value* addr, Value* value) override;
				void store_pc(Value* value) override;
				void store_register(Value* offset, Value* value) override;
				Value* sub(Value* lhs, Value* rhs) override;
				Value* sx(Value* val, const Type& type) override;
				void trace(TraceEvent event, Value* o0, Value* o1, Value* o2, Value* o3) override;
				Value* truncate(Value* val, const Type& type) override;
				Value* umulh(Value* lhs, Value* rhs) override;
				Value* umull(Value* lhs, Value* rhs) override;
				Value* vector_extract(Value* vct, Value* index) override;
				Value* vector_insert(Value* vct, Value* index, Value* value) override;
				Value* zx(Value* val, const Type& type) override;

			private:
				Emitter& _other;

				//void track(const char *node, Value *ret, Value *op0, Value *op0, Value *op0, Value *op0);
			};
		}
	}
}
