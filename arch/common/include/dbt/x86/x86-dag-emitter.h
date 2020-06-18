/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/el/emitter.h>
#include <map>
#include <string>

namespace captive {
	namespace arch {
		namespace jit {
			namespace x86 {

				class X86DAGEmitter : public dbt::el::Emitter {
				public:

					X86DAGEmitter(dbt::el::Context& context, dbt::el::Block *current_block) : dbt::el::Emitter(context, current_block), _last_sequence_point(nullptr)
					{
					}

					virtual ~X86DAGEmitter()
					{
					}

					dbt::el::Value* adc(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry) override;
					dbt::el::Value* adcf(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry) override;
					dbt::el::Value* add(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* alloc_local(const dbt::el::Type& type, bool is_global) override;
					dbt::el::Value* bitwise_and(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* bitwise_not(dbt::el::Value* v) override;
					dbt::el::Value* bitwise_or(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* bitwise_xor(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					void block_start(dbt_u64 addr, dbt_u32 feature_set) override;
					void block_end(dbt_u32 feature_set) override;
					dbt::el::Value* bswap(dbt::el::Value* v) override;
					void branch(dbt::el::Value* predicate, dbt::el::Block* true_target, dbt::el::Block* false_target) override;
					dbt::el::Value *call(void* fnp, dbt::el::Value* o0, dbt::el::Value* o1, dbt::el::Value* o2, dbt::el::Value* o3) override;
					dbt::el::Value* clz(dbt::el::Value* v) override;
					dbt::el::Value* cmp_eq(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* cmp_ge(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* cmp_gt(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* cmp_le(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* cmp_lt(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* cmp_ne(dbt::el::Value* lhs, dbt::el::Value* rhs) override;

					void chain(dbt_u64 target, dbt_u64 fallthrough, void *target_ptr, void *ft_ptr) override;

					dbt::el::Value* constant(dbt_u64 value, const dbt::el::Type& type) override;
					dbt::el::Value* constant(dbt_f32 value, const dbt::el::Type& type) override;
					dbt::el::Value* constant(dbt_f64 value, const dbt::el::Type& type) override;

					dbt::el::Value* convert(dbt::el::Value* value, const dbt::el::Type& type) override;

					dbt::el::Value* div(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* sqrt(dbt::el::Value* value) override;

					void enter_kernel_mode() override;
					void enter_user_mode() override;

					void inc_pc(dbt::el::Value* amount) override;
					void instruction_start(dbt_u64 addr) override;
					void instruction_end(dbt_u64 addr, bool end_of_block) override;

					void jump(dbt::el::Block* target) override;
					void leave(dbt::el::Value* value = nullptr) override;
					dbt::el::Value* load_device(dbt::el::Value* id, dbt::el::Value* offset, const dbt::el::Type& type) override;
					dbt::el::Value* load_local(dbt::el::Value* ptr, const dbt::el::Type& type) override;
					dbt::el::Value* load_memory(dbt::el::Value* addr, const dbt::el::Type& type) override;
					dbt::el::Value* load_pc() override;
					dbt::el::Value* load_register(dbt::el::Value* offset, const dbt::el::Type& type) override;
					dbt::el::Value* mod(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* mul(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* neg(dbt::el::Value* v) override;

					void raise(dbt::el::Value* value) override;
					dbt::el::Value* reinterpret(dbt::el::Value* val, const dbt::el::Type& type) override;
					dbt::el::Value* rol(dbt::el::Value* v, dbt::el::Value* amt) override;
					dbt::el::Value* ror(dbt::el::Value* v, dbt::el::Value* amt) override;
					dbt::el::Value* sar(dbt::el::Value* v, dbt::el::Value* amt) override;
					dbt::el::Value* sbc(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry) override;
					dbt::el::Value* sbcf(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry) override;
					void set_feature(dbt_u32 feature, dbt::el::Value* value) override;
					dbt::el::Value* shl(dbt::el::Value* v, dbt::el::Value* amt) override;
					dbt::el::Value* shr(dbt::el::Value* v, dbt::el::Value* amt) override;
					void store_device(dbt::el::Value* id, dbt::el::Value* offset, dbt::el::Value* value) override;
					void store_local(dbt::el::Value* ptr, dbt::el::Value* value) override;
					void store_memory(dbt::el::Value* addr, dbt::el::Value* value) override;
					void store_pc(dbt::el::Value* value) override;
					void store_register(dbt::el::Value* offset, dbt::el::Value* value) override;
					void set_zn(dbt::el::Value* v) override;
					dbt::el::Value* smulh(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* smull(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* sub(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* sx(dbt::el::Value* val, const dbt::el::Type& type) override;
					void trace(dbt::el::TraceEvent event, dbt::el::Value* o0, dbt::el::Value* o1, dbt::el::Value* o2, dbt::el::Value* o3) override;
					dbt::el::Value* truncate(dbt::el::Value* val, const dbt::el::Type& type) override;
					dbt::el::Value* umulh(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* umull(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* vector_extract(dbt::el::Value* vct, dbt::el::Value* idx) override;
					dbt::el::Value* vector_insert(dbt::el::Value* vct, dbt::el::Value* idx, dbt::el::Value* value) override;

					dbt::el::Value* zx(dbt::el::Value* val, const dbt::el::Type& type) override;

				private:
					dbt::el::Value *add_node(const std::string& name, const std::string& meta = "");
					void add_data_edge(dbt::el::Value *from, dbt::el::Value *to);
					void add_flow_edge(dbt::el::Value *from, dbt::el::Value *to);
					void sequence_point(dbt::el::Value *node);

					dbt::el::Value *_last_sequence_point;
				};
			}
		}
	}
}
