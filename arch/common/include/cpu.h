/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <trace.h>
#include <shmem.h>
#include <priv.h>
#include <disasm.h>
#include <txln-cache.h>
#include <dbt/translation-manager.h>
#include <dbt/feature-manager.h>
#include <map>
#include <mmu/address-translation-context.h>

typedef __int128 uint128_t;

extern "C" {
	void tail_call_ret0_only();
}

namespace captive {
	namespace arch {
		namespace dbt {
			namespace el {
				class Emitter;
			}
		}

		namespace jit {
			class DBT;
		}

		class Environment;
		class JumpInfo;

		class CPU {
			friend class jit::FeatureManager;

		public:

			struct TaggedRegisters {
				void *base;
				uint64_t *PC, *SP;
				uint8_t *C, *Z, *N, *V, *Q, *I, *ISA;
			};

			CPU(Environment& env, PerCPUData *per_cpu_data);
			virtual ~CPU();

			virtual bool init() = 0;
			bool run();

			inline jit::DBT& dbt() const
			{
				if (unlikely(_trace->enabled())) return *_tracing_dbt;
				else return *_dbt;
			}

			inline Environment& env() const
			{
				return _env;
			}

			inline Trace& trace() const
			{
				return *_trace;
			}

			inline PerCPUData& cpu_data() const
			{
				return *_per_cpu_data;
			}

			inline uint64_t performance_counter_a() const
			{
				return jit_state.perf_cnt_a;
			}

			inline void performance_counter_a(uint64_t v)
			{
				jit_state.perf_cnt_a = v;
			}

			inline void inc_performance_counter_a()
			{
				jit_state.perf_cnt_a++;
			}

			inline uint64_t performance_counter_b() const
			{
				return jit_state.perf_cnt_b;
			}

			inline const uint64_t *performance_data() const
			{
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"
				return &jit_state.data[0];
#pragma GCC diagnostic warning "-Waddress-of-packed-member"
			}

			const char *disassemble_address(uint8_t isa, gva_t va);

			virtual void dump_state(bool dump_hidden = false) const = 0;

			inline uint64_t get_insns_executed() const
			{
				return cpu_data().insns_executed;
			}

			inline bool executing_translation() const
			{
				return _exec_txl;
			}

			static inline CPU *get_active_cpu()
			{
				return current_cpu;
			}

			static inline void set_active_cpu(CPU* cpu)
			{
				current_cpu = cpu;
			}

			static inline PerCPUData *get_active_cpu_data()
			{
				return current_cpu->_per_cpu_data;
			}

			inline void *reg_state() const
			{
				return _reg_state;
			}

			inline TaggedRegisters& tagged_registers()
			{
				return tagged_reg_offsets;
			}

			void invalidate_virtual_mappings_all();
			void invalidate_virtual_mappings_current();
			void invalidate_virtual_mapping_current(gva_t va);
			void invalidate_virtual_mappings(int context);
			void invalidate_virtual_mapping(int context, gva_t va);
			void invalidate_translations();

			void switch_virtual_mappings(int context);

			void invalidate_translation_virt(gva_t virt_page_base_addr);
			void invalidate_translation_phys(gpa_t phys_page_base_addr);

			void handle_irq_raised();

			// Behaviours
			virtual bool handle_irq(uint32_t isr) = 0;

			virtual bool handle_mmu_fault(gva_t va, const captive::arch::mmu::AddressTranslationContext& ctx) = 0;

			virtual bool handle_single_step() = 0;

			virtual void handle_undefined_instruction() = 0;

			const char *get_reg_name(uint32_t offset)
			{
				if (_reg_names[offset] == nullptr) return "???";
				else return _reg_names[offset];
			}

			jit::FeatureManager& feature_manager()
			{
				return _fm;
			}

			const jit::FeatureManager& feature_manager() const
			{
				return _fm;
			}

			virtual uint64_t get_page_table_base(int index) const = 0;

		protected:
			jit::DBT *_dbt, *_tracing_dbt;
			std::map<uint32_t, const char *> _reg_names;
			void *_reg_state;

			/*virtual bool decode_instruction_virt(uint8_t isa, gva_t addr, Decode *insn) = 0;
			virtual bool decode_instruction_phys(uint8_t isa, gpa_t addr, Decode *insn) = 0;
			virtual JumpInfo get_instruction_jump_info(const Decode *insn) = 0;*/

			virtual bool interrupts_enabled(uint8_t irq_line) const = 0;

			inline void trigger_irq()
			{
				jit_state.exit_chain = 1;
			}

			inline void inc_insns_executed()
			{
				cpu_data().insns_executed++;
			}

			inline void add_reg_name(uint32_t offset, const char *name)
			{
				_reg_names[offset] = name;
			}

			Trace *_trace;
			TaggedRegisters tagged_reg_offsets;

			struct {
				uint32_t last_exception_action;
			} local_state;

			struct block_chain_cache_entry {
				uint64_t tag;
				void *fn;

				inline void invalidate()
				{
					tag = 1;
				}
			} packed;

			struct region_chain_cache_entry {
				void *fn;

				inline void invalidate()
				{
					fn = (void *) &tail_call_ret0_only;
				}
			} packed;

			struct {
				void *cpu; // 0			00
				void *registers; // 8			08
				uint64_t registers_size; // 16			10
				uint64_t execution_mode; // 24			18
				const struct block_chain_cache_entry *block_txln_cache; // 32			20
				void *trace_buffer; // 40			28
				uint64_t exit_chain; // 48			30

				uint64_t perf_cnt_a; // 56			38
				uint64_t perf_cnt_b; // 64			40

				void *per_cpu_data; // 72			48
				uint64_t mmu_monitor; // 80			50
				uint64_t entry_address; // 88			58
				uint64_t active_features; // 96			60
				uint64_t virtual_memory_mode; // 104			68
				uint64_t virtual_memory_mode_table[5]; // 112			70

				uint64_t call_gate_tmp; // 152			98
				uint64_t call_gate_segment; // 160			a0

				uint64_t mem_call_gate; // 168			a8
				uint64_t mem_call_gate_segment; // 176			b0

				uint64_t scratch; // 184			b8

				uint64_t data[16]; // 192			c0
			} packed jit_state;

			inline void trap()
			{
				fatal("it's a trap!\n");
			}

			inline void pend_interrupt()
			{
			}

		private:
			static CPU *current_cpu;

			Environment& _env;
			jit::FeatureManager _fm;
			PerCPUData *_per_cpu_data;
			jit::TranslationManager<> _txln_mgr;

			typedef Cache<struct block_chain_cache_entry, 0x2000> block_txln_cache_t;
			block_txln_cache_t block_txln_cache;

			bool _exec_txl;

			bool run_block_jit();
			bool run_block_jit_safepoint();
			bool run_test();

			bool handle_pending_action(uint32_t action);

			jit::Translation *compile_block(uint8_t isa_mode, gpa_t pa);
			bool emit_block(uint8_t isa_mode, gpa_t pa, dbt::el::Emitter& emitter);
		};
	}
}
