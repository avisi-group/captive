/* SPDX-License-Identifier: MIT */

#include <dbt/dbt.h>
#include <cpu.h>

using namespace captive::arch;
using namespace captive::arch::jit;

void *__captive_single_step = &__captive_single_step;

void *__captive_mmu_flush_all = &__captive_mmu_flush_all;
void *__captive_mmu_flush_va = &__captive_mmu_flush_va;
void *__captive_mmu_notify_pgt_change = &__captive_mmu_notify_pgt_change;
void *__captive_mmu_notify_asid_change = &__captive_mmu_notify_asid_change;

void *__captive_trigger_irq = &__captive_trigger_irq;
void *__captive___builtin_set_fp_rounding = &__captive___builtin_set_fp_rounding;
void *__captive___builtin_get_fp_rounding = &__captive___builtin_get_fp_rounding;
void *__captive___builtin_fma32 = &__captive___builtin_fma32;
void *__captive___builtin_fma64 = &__captive___builtin_fma64;

void *__captive___builtin_adc = &__captive___builtin_adc;
void *__captive___builtin_adc_flags = &__captive___builtin_adc_flags;
void *__captive___builtin_adc64 = &__captive___builtin_adc64;
void *__captive___builtin_adc64_flags = &__captive___builtin_adc64_flags;
void *__captive___builtin_sbc = &__captive___builtin_sbc;
void *__captive___builtin_sbc_flags = &__captive___builtin_sbc_flags;
void *__captive___builtin_sbc64 = &__captive___builtin_sbc64;
void *__captive___builtin_sbc64_flags = &__captive___builtin_sbc64_flags;

void *__captive___builtin_update_zn_flags = &__captive___builtin_update_zn_flags;
void *__captive___builtin_update_zn_flags64 = &__captive___builtin_update_zn_flags64;

void *__captive___builtin_smulh = &__captive___builtin_smulh;
void *__captive___builtin_umulh = &__captive___builtin_umulh;

void *__captive___builtin_f32_round = &__captive___builtin_f32_round;
void *__captive___builtin_f64_round = &__captive___builtin_f64_round;

void *__captive___builtin_fcvt_f32_s32 = &__captive___builtin_fcvt_f32_s32;
void *__captive___builtin_fcvt_f32_s64 = &__captive___builtin_fcvt_f32_s64;
void *__captive___builtin_fcvt_f64_s32 = &__captive___builtin_fcvt_f64_s32;
void *__captive___builtin_fcvt_f64_s64 = &__captive___builtin_fcvt_f64_s64;
void *__captive___builtin_fcvt_f32_u32 = &__captive___builtin_fcvt_f32_u32;
void *__captive___builtin_fcvt_f32_u64 = &__captive___builtin_fcvt_f32_u64;
void *__captive___builtin_fcvt_f64_u32 = &__captive___builtin_fcvt_f64_u32;
void *__captive___builtin_fcvt_f64_u64 = &__captive___builtin_fcvt_f64_u64;

void *__captive___builtin_cmpf32_flags = &__captive___builtin_cmpf32_flags;
void *__captive___builtin_cmpf32e_flags = &__captive___builtin_cmpf32e_flags;
void *__captive___builtin_cmpf64_flags = &__captive___builtin_cmpf64_flags;
void *__captive___builtin_cmpf64e_flags = &__captive___builtin_cmpf64e_flags;

void *__captive_float_abs = &__captive_float_abs;
void *__captive_double_abs = &__captive_double_abs;
void *__captive_float_sqrt = &__captive_float_sqrt;
void *__captive_double_sqrt = &__captive_double_sqrt;

void *__captive___builtin_popcount32 = &__captive___builtin_popcount32;
void *__captive___builtin_clear_fpex = &__captive___builtin_clear_fpex;
void *__captive___builtin_fpex_invalid = &__captive___builtin_fpex_invalid;
void *__captive___builtin_fpex_underflow = &__captive___builtin_fpex_underflow;
void *__captive___builtin_fpex_overflow = &__captive___builtin_fpex_overflow;

void *__captive___builtin_polymul8 = &__captive___builtin_polymul8;
void *__captive___builtin_polymul64 = &__captive___builtin_polymul64;

void *__captive___builtin_abs32 = &__captive___builtin_abs32;
void *__captive___builtin_abs64 = &__captive___builtin_abs64;

void *__captive___builtin_jit_invalidate_txln_all = &__captive___builtin_jit_invalidate_txln_all;
void *__captive___builtin_jit_invalidate_txln = &__captive___builtin_jit_invalidate_txln;

void *__captive_mem_monitor_acquire = &__captive_mem_monitor_acquire;
void *__captive_mem_monitor_release = &__captive_mem_monitor_release;
void *__captive_mem_monitor_release_all = &__captive_mem_monitor_release_all;

void *__captive___softfp_add64 = &__captive___softfp_add64;

uint32_t DBT::__get_feature(uint32_t feature)
{
	return CPU::get_active_cpu()->feature_manager().get_feature(feature);
}
