/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/el/emitter.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/vreg-allocator.h>
#include <dbt/x86/x86-value.h>
#include <map>

namespace captive {
	namespace arch {
		namespace jit {
			namespace x86 {
				class X86Context;
				class X86Block;
				class X86Value;
				class X86LocalVariable;
				class X86Constant;
				class X86UnaryOperation;
				class X86BinaryOperation;
				class X86ComparisonOperation;
				class X86GuestRegister;
				class X86GuestMemory;
				class X86Cast;
				class X86VectorInsert;
				class X86VectorExtract;

				struct ArchData {
					unsigned int ZERO_DISPLACEMENT, NEGATIVE_DISPLACEMENT, CARRY_DISPLACEMENT, OVERFLOW_DISPLACEMENT;
				};

				struct X86EmitterOptions {
					X86EmitterOptions()
						: no_mmu(false),
						kernel_mode(false),
						perf_kernel_icount(false),
						perf_kernel_brcount(false),
						perf_user_icount(false),
						perf_user_brcount(false) { }

					bool no_mmu;
					bool kernel_mode;
					bool perf_kernel_icount;
					bool perf_kernel_brcount;
					bool perf_user_icount;
					bool perf_user_brcount;
				};

				class X86Emitter : public dbt::el::Emitter {
					friend class X86Constant;
					friend class X86UnaryOperation;
					friend class X86BinaryOperation;
					friend class X86ComparisonOperation;
					friend class X86GuestRegister;
					friend class X86GuestMemory;
					friend class X86Cast;
					friend class X86Value;
					friend class X86VectorInsert;
					friend class X86VectorExtract;

				public:
					X86Emitter(const ArchData& arch_data, dbt::el::Context& context, dbt::el::Block *current_block, const X86EmitterOptions& options);
					virtual ~X86Emitter();

					dbt::el::Value* adc(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry) override;
					dbt::el::Value* adcf(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry) override;
					dbt::el::Value* add(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* div(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* mod(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* mul(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* neg(dbt::el::Value* v) override;
					dbt::el::Value* sbc(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry) override;
					dbt::el::Value* sbcf(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry) override;
					dbt::el::Value* smulh(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* smull(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* sub(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* umulh(dbt::el::Value* lhs, dbt::el::Value* rhs) override;
					dbt::el::Value* umull(dbt::el::Value* lhs, dbt::el::Value* rhs) override;

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
					void super_chain_direct(dbt_u64 target, void *default_target) override;
					void super_chain_direct_predicated(dbt_u64 target, dbt_u64 fallthrough, void *default_target, void *default_fallthrough) override;

					dbt::el::Value* constant(dbt_u64 value, const dbt::el::Type& type) override;
					dbt::el::Value* constant(dbt_f32 value, const dbt::el::Type& type) override;
					dbt::el::Value* constant(dbt_f64 value, const dbt::el::Type& type) override;
					dbt::el::Value* constant_vector_splat(dbt_u64 value, const dbt::el::Type& type) override;
					dbt::el::Value* constant_vector_splat_f(dbt_f32 value, const dbt::el::Type& type) override;
					dbt::el::Value* constant_vector_splat_f(dbt_f64 value, const dbt::el::Type& type) override;

					dbt::el::Value* convert(dbt::el::Value* value, const dbt::el::Type& type) override;
					dbt::el::Value* splat(dbt::el::Value* value, const dbt::el::Type& type) override;

					dbt::el::Value* sqrt(dbt::el::Value* value) override;

					void enter_kernel_mode() override;
					void enter_user_mode() override;

					void inc_pc(dbt::el::Value* amount) override;
					void instruction_start(dbt_u64 addr) override;
					void instruction_end(dbt_u64 addr, bool end_of_block) override;

					dbt::el::Value* select(dbt::el::Value* cond, dbt::el::Value* tv, dbt::el::Value *fv) override;
					void jump(dbt::el::Block* target) override;
					void leave(dbt::el::Value* value = nullptr) override;
					dbt::el::Value* load_device(dbt::el::Value* id, dbt::el::Value* offset, const dbt::el::Type& type) override;
					dbt::el::Value* load_local(dbt::el::Value* ptr, const dbt::el::Type& type) override;
					dbt::el::Value* load_memory(dbt::el::Value* addr, const dbt::el::Type& type) override;
					dbt::el::Value* load_pc() override;
					dbt::el::Value* load_register(dbt::el::Value* offset, const dbt::el::Type& type) override;

					void raise(dbt::el::Value* value) override;
					dbt::el::Value* reinterpret(dbt::el::Value* val, const dbt::el::Type& type) override;
					dbt::el::Value* rol(dbt::el::Value* v, dbt::el::Value* amt) override;
					dbt::el::Value* ror(dbt::el::Value* v, dbt::el::Value* amt) override;
					dbt::el::Value* sar(dbt::el::Value* v, dbt::el::Value* amt) override;
					void set_feature(dbt_u32 feature, dbt::el::Value* value) override;
					dbt::el::Value* shl(dbt::el::Value* v, dbt::el::Value* amt) override;
					dbt::el::Value* shr(dbt::el::Value* v, dbt::el::Value* amt) override;
					void store_device(dbt::el::Value* id, dbt::el::Value* offset, dbt::el::Value* value) override;
					void store_local(dbt::el::Value* ptr, dbt::el::Value* value) override;
					void store_memory(dbt::el::Value* addr, dbt::el::Value* value) override;
					void store_pc(dbt::el::Value* value) override;
					void store_register(dbt::el::Value* offset, dbt::el::Value* value) override;
					void set_zn(dbt::el::Value* v) override;
					dbt::el::Value* sx(dbt::el::Value* val, const dbt::el::Type& type) override;
					void trace(dbt::el::TraceEvent event, dbt::el::Value* o0, dbt::el::Value* o1, dbt::el::Value* o2, dbt::el::Value* o3) override;
					dbt::el::Value* truncate(dbt::el::Value* val, const dbt::el::Type& type) override;
					dbt::el::Value* vector_extract(dbt::el::Value* vct, dbt::el::Value* idx) override;
					dbt::el::Value* vector_insert(dbt::el::Value* vct, dbt::el::Value* idx, dbt::el::Value* value) override;

					dbt::el::Value* zx(dbt::el::Value* val, const dbt::el::Type& type) override;

					dbt::mc::x86::VirtualRegisterAllocator& vreg_allocator()
					{
						return _vreg_allocator;
					}

				private:
					const ArchData& _arch_data;
					const X86EmitterOptions options_;

					inline dbt::mc::x86::Instruction *alloc_instruction(dbt::mc::x86::InstructionKind::InstructionKind kind)
					{
						return _x86_context.support().alloc_obj<Instruction>(kind);
					}

					void append_instruction(dbt::mc::x86::Instruction *insn);

					Instruction *add_instruction(InstructionKind::InstructionKind kind, const Operand& o0, const Operand& o1, const Operand& o2)
					{
						auto insn = alloc_instruction(kind);
						insn->set_operand(0, o0);
						insn->set_operand(1, o1);
						insn->set_operand(2, o2);

						append_instruction(insn);
						return insn;
					}

					Instruction *add_instruction(InstructionKind::InstructionKind kind, const Operand& o0, const Operand& o1)
					{
						auto insn = alloc_instruction(kind);
						insn->set_operand(0, o0);
						insn->set_operand(1, o1);

						append_instruction(insn);
						return insn;
					}

					Instruction *add_instruction(InstructionKind::InstructionKind kind, const Operand& o0)
					{
						auto insn = alloc_instruction(kind);
						insn->set_operand(0, o0);

						append_instruction(insn);
						return insn;
					}

					Instruction *add_instruction(InstructionKind::InstructionKind kind)
					{
						auto insn = alloc_instruction(kind);
						append_instruction(insn);
						return insn;
					}

					dbt::mc::x86::Instruction *add_mov_auto(const dbt::mc::x86::Operand& src, const dbt::mc::x86::Operand& dst);

					void dump() const;
					void debug_print(const char *op, dbt::el::Value *o0 = nullptr, dbt::el::Value *o1 = nullptr, dbt::el::Value *o2 = nullptr, dbt::el::Value *o3 = nullptr);
					void debug_print_b(const char *op, dbt::el::Value *o0 = nullptr, dbt::el::Block *t0 = nullptr, dbt::el::Block *t1 = nullptr);
					void debug_print_operand(X86Value *op);

					void increment_pca();
					void increment_pcb();
					void increment_icount();
					void increment_brcount();

					std::map<uint64_t, X86GuestRegister *> _guest_register_objects;

					X86Context& _x86_context;
					dbt::mc::x86::VirtualRegisterAllocator _vreg_allocator;

					uint32_t _used_features;
					dbt::mc::x86::Instruction *_feature_mask_and, *_feature_set_cmp;

					dbt::el::Value* load_memory_inline(dbt::el::Value* addr, const dbt::el::Type& type);
					dbt::el::Value* load_memory_no_mmu(dbt::el::Value* addr, const dbt::el::Type& type);
					dbt::el::Value* load_memory_kernel_mode(dbt::el::Value* addr, const dbt::el::Type& type);
					dbt::el::Value* load_memory_default(dbt::el::Value* addr, const dbt::el::Type& type);
					dbt::el::Value* load_memory_mpk(dbt::el::Value* addr, const dbt::el::Type& type);

					void store_memory_no_mmu(dbt::el::Value* addr, dbt::el::Value* value);
					void store_memory_inline(dbt::el::Value* addr, dbt::el::Value* value);
					void store_memory_default(dbt::el::Value* addr, dbt::el::Value* value);
					void store_memory_mpk(dbt::el::Value* addr, dbt::el::Value* value);

					void emit_rdpku_dummy(dbt::el::Value* addr);

					template<typename MMUStrategyType>
					void mmu_store_memory(X86Value* addr, X86Value* value);

					template<typename MMUStrategyType>
					dbt::el::Value* mmu_load_memory(X86Value* addr, const dbt::el::Type& type);

					template<typename MMUStrategyType>
					void mmu_monitor_acquire(X86Value* addr);

					template<typename MMUStrategyType>
					dbt::el::Value* mmu_monitor_release(X86Value* addr);

					template<typename MMUStrategyType>
					void mmu_monitor_release_all();

					template<typename MMUStrategyType>
					void mmu_flush(X86Value* addr);

					template<typename MMUStrategyType>
					void mmu_pgt_change();

					template<typename MMUStrategyType>
					void mmu_asid_change(X86Value *asid);

					X86PhysicalRegister tvas_compute_host_ptr(X86Value *addr);
				};
			}
		}
	}
}
