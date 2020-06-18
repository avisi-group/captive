/* SPDX-License-Identifier: MIT */

#pragma once

#include <define.h>

extern void *__captive___branch_taken;
extern void *__captive___branch_not_taken;

extern void *__captive_mmu_flush_va;
extern void *__captive_mmu_flush_all;
extern void *__captive_mmu_notify_pgt_change;
extern void *__captive_mmu_notify_asid_change;

extern void *__captive_single_step;
extern void *__captive_trigger_irq;
extern void *__captive___builtin_set_fp_rounding;
extern void *__captive___builtin_get_fp_rounding;
extern void *__captive___builtin_fma32;
extern void *__captive___builtin_fma64;

extern void *__captive___builtin_update_zn_flags;
extern void *__captive___builtin_update_zn_flags64;

extern void *__captive___builtin_adc;
extern void *__captive___builtin_adc_flags;
extern void *__captive___builtin_adc64;
extern void *__captive___builtin_adc64_flags;
extern void *__captive___builtin_sbc;
extern void *__captive___builtin_sbc_flags;
extern void *__captive___builtin_sbc64;
extern void *__captive___builtin_sbc64_flags;

extern void *__captive___builtin_smulh;
extern void *__captive___builtin_umulh;

extern void *__captive___builtin_f32_round;
extern void *__captive___builtin_f64_round;

extern void *__captive___builtin_fcvt_f32_s32;
extern void *__captive___builtin_fcvt_f32_s64;
extern void *__captive___builtin_fcvt_f64_s32;
extern void *__captive___builtin_fcvt_f64_s64;
extern void *__captive___builtin_fcvt_f32_u32;
extern void *__captive___builtin_fcvt_f32_u64;
extern void *__captive___builtin_fcvt_f64_u32;
extern void *__captive___builtin_fcvt_f64_u64;

extern void *__captive___builtin_cmpf32_flags;
extern void *__captive___builtin_cmpf32e_flags;
extern void *__captive___builtin_cmpf64_flags;
extern void *__captive___builtin_cmpf64e_flags;
extern void *__captive_float_abs;
extern void *__captive_double_abs;
extern void *__captive_float_sqrt;
extern void *__captive_double_sqrt;
extern void *__captive___builtin_popcount32;
extern void *__captive___builtin_clear_fpex;
extern void *__captive___builtin_fpex_invalid;
extern void *__captive___builtin_fpex_underflow;
extern void *__captive___builtin_fpex_overflow;
extern void *__captive___builtin_polymul8;
extern void *__captive___builtin_polymul64;
extern void *__captive___builtin_abs32;
extern void *__captive___builtin_abs64;

extern void *__captive___builtin_jit_invalidate_txln_all;
extern void *__captive___builtin_jit_invalidate_txln;

extern void *__captive___softfp_add64;

extern void *__captive_mem_monitor_acquire;
extern void *__captive_mem_monitor_release;
extern void *__captive_mem_monitor_release_all;

namespace captive {
	namespace arch {
		namespace dbt {
			namespace el {
				class Emitter;
			}
		}


		class Decode;

		namespace jit {

			class DBT {
			public:

				DBT()
				{
				}

				virtual ~DBT()
				{
				}

				virtual bool translate(const Decode *decode_obj, dbt::el::Emitter& emitter) = 0;

			protected:
				uint32_t __get_feature(uint32_t feature);
			};
		}
	}
}
