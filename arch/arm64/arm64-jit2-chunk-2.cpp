#include <arm64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::arm64;
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_add_ereg(const arm64_decode_a64_ADD_SUB_EREG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_48733_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48799_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48562_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48578_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_48664_1__R_s_b_14_17;
  auto DV_sym_48664_1__R_s_b_14_17 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48526_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_48878_1_temporary_value;
  auto DV_sym_48878_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_48906_1_temporary_value;
  auto DV_sym_48906_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_48695_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48848_1__R_s_b_44_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48399_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3329_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3315_0_rn = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48418_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1931 [F] s_b_0_0=sym_3310_3_parameter_inst.sf (const) */
    /* execute.a64:2792 [F] s_b_0_1: If s_b_0_0: Jump b_6 else b_7 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_34,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1935 [F] s_b_1_0=sym_3310_3_parameter_inst.sf (const) */
    /* execute.a64:1935 [F] s_b_1_1: If s_b_1_0: Jump b_4 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_5, b_14, b_35, b_36, b_37, b_38, b_39,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_34,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1941 [F] s_b_3_0=sym_3310_3_parameter_inst.sf (const) */
    /* execute.a64:1941 [D] s_b_3_1 = sym_3315_0_rn uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_3315_0_rn, emitter.context().types().u64());
    /* execute.a64:1941 [D] s_b_3_2 = sym_3329_0_rm uint64_t */
    auto s_b_3_2 = emitter.load_local(DV_sym_3329_0_rm, emitter.context().types().u64());
    /* execute.a64:1941 [D] s_b_3_3 = s_b_3_1+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_1, s_b_3_2);
    /* execute.a64:1941 [D] s_b_3_4: sym_48418_3_parameter_value = s_b_3_3, dominates: s_b_11_0 s_b_13_0 s_b_14_1  */
    emitter.store_local(DV_sym_48418_3_parameter_value, s_b_3_3);
    /* execute.a64:2809 [F] s_b_3_5 = !s_b_3_0 (const) */
    uint8_t s_b_3_5 = !insn.sf;
    /* execute.a64:2809 [F] s_b_3_6: If s_b_3_5: Jump b_11 else b_12 (const) */
    if (s_b_3_5) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1936 [D] s_b_4_0 = sym_3315_0_rn uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_3315_0_rn, emitter.context().types().u64());
    /* execute.a64:1936 [D] s_b_4_1 = sym_3329_0_rm uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_3329_0_rm, emitter.context().types().u64());
    /* execute.a64:1936 [F] s_b_4_2 = constant u8 0 (const) */
    /* execute.a64:1936 [D] s_b_4_3 = __builtin_adc64_flags */
    auto s_b_4_3 = emitter.adcf(s_b_4_0, s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2754 [F] s_b_4_4=sym_3310_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_4_5: sym_48733_3_parameter_value = s_b_4_3, dominates: s_b_38_1  */
    emitter.store_local(DV_sym_48733_3_parameter_value, s_b_4_3);
    /* execute.a64:2745 [F] s_b_4_6 = (u32)s_b_4_4 (const) */
    /* execute.a64:2745 [F] s_b_4_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_4_8 = s_b_4_6==s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_4_9: If s_b_4_8: Jump b_2 else b_38 (const) */
    if (s_b_4_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_38;
    }
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1938 [D] s_b_5_0 = sym_3315_0_rn uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_3315_0_rn, emitter.context().types().u64());
    /* execute.a64:1938 [D] s_b_5_1 = (u32)s_b_5_0 */
    auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().u32());
    /* execute.a64:1938 [D] s_b_5_2 = sym_3329_0_rm uint64_t */
    auto s_b_5_2 = emitter.load_local(DV_sym_3329_0_rm, emitter.context().types().u64());
    /* execute.a64:1938 [D] s_b_5_3 = (u32)s_b_5_2 */
    auto s_b_5_3 = emitter.truncate(s_b_5_2, emitter.context().types().u32());
    /* execute.a64:1938 [F] s_b_5_4 = constant u8 0 (const) */
    /* execute.a64:1938 [D] s_b_5_5 = __builtin_adc32_flags */
    auto s_b_5_5 = emitter.adcf(s_b_5_1, s_b_5_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:1938 [D] s_b_5_6 = (u64)s_b_5_5 */
    auto s_b_5_6 = emitter.zx(s_b_5_5, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_5_7=sym_3310_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_5_8 = (u32)s_b_5_6 */
    auto s_b_5_8 = emitter.truncate(s_b_5_6, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_5_9 = (u64)s_b_5_8 */
    auto s_b_5_9 = emitter.zx(s_b_5_8, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_5_10: sym_48799_3_parameter_value = s_b_5_9, dominates: s_b_39_1  */
    emitter.store_local(DV_sym_48799_3_parameter_value, s_b_5_9);
    /* execute.a64:2745 [F] s_b_5_11 = (u32)s_b_5_7 (const) */
    /* execute.a64:2745 [F] s_b_5_12 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_5_13 = s_b_5_11==s_b_5_12 (const) */
    uint8_t s_b_5_13 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_5_14: If s_b_5_13: Jump b_2 else b_39 (const) */
    if (s_b_5_13) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_39;
    }
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2793 [F] s_b_6_0=sym_3310_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2793 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_6_4: If s_b_6_3: Jump b_15 else b_8 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2799 [F] s_b_7_0=sym_3310_3_parameter_inst.rn (const) */
    /* execute.a64:2799 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2799 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2799 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2799 [F] s_b_7_4: If s_b_7_3: Jump b_20 else b_9 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2796 [F] s_b_8_0=sym_3310_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_8_2: sym_48399_1__R_s_b_0_4 = s_b_8_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_48399_1__R_s_b_0_4, s_b_8_1);
    /* execute.a64:2796 [F] s_b_8_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2802 [F] s_b_9_0=sym_3310_3_parameter_inst.rn (const) */
    /* execute.a64:2802 [D] s_b_9_1 = ReadRegBank 1:s_b_9_0 (u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(4));
    }
    /* execute.a64:2802 [D] s_b_9_2 = (u64)s_b_9_1 */
    auto s_b_9_2 = emitter.zx(s_b_9_1, emitter.context().types().u64());
    /* execute.a64:2802 [D] s_b_9_3: sym_48399_1__R_s_b_0_4 = s_b_9_2, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_48399_1__R_s_b_0_4, s_b_9_2);
    /* execute.a64:2802 [F] s_b_9_4: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_8, b_9, b_19, b_24,  */
  fixed_block_b_10: 
  {
    /* execute.a64:1931 [D] s_b_10_0 = sym_48399_1__R_s_b_0_4 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_48399_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:1931 [D] s_b_10_1: sym_3315_0_rn = s_b_10_0, dominates: s_b_4_0 s_b_5_0 s_b_3_1  */
    emitter.store_local(DV_sym_3315_0_rn, s_b_10_0);
    /* execute.a64:1932 [F] s_b_10_2=sym_3310_3_parameter_inst.option (const) */
    /* execute.a64:1932 [F] s_b_10_3 = (u32)s_b_10_2 (const) */
    /* execute.a64:1932 [F] s_b_10_4 = constant u32 3 (const) */
    /* execute.a64:1932 [F] s_b_10_5 = s_b_10_3&s_b_10_4 (const) */
    uint32_t s_b_10_5 = ((uint32_t)(((uint32_t)insn.option) & (uint32_t)3ULL));
    /* execute.a64:1932 [F] s_b_10_6 = constant u32 3 (const) */
    /* execute.a64:1932 [F] s_b_10_7 = s_b_10_5==s_b_10_6 (const) */
    uint8_t s_b_10_7 = ((uint8_t)(s_b_10_5 == (uint32_t)3ULL));
    /* execute.a64:2719 [F] s_b_10_8: If s_b_10_7: Jump b_42 else b_43 (const) */
    if (s_b_10_7) 
    {
      goto fixed_block_b_42;
    }
    else 
    {
      goto fixed_block_b_43;
    }
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2810 [D] s_b_11_0 = sym_48418_3_parameter_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_48418_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_11_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_11_2 = s_b_11_0&s_b_11_1 */
    auto s_b_11_2 = emitter.bitwise_and(s_b_11_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_11_3: sym_48418_3_parameter_value = s_b_11_2, dominates: s_b_13_0 s_b_14_1  */
    emitter.store_local(DV_sym_48418_3_parameter_value, s_b_11_2);
    /* execute.a64:2810 [F] s_b_11_4: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_3, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2813 [F] s_b_12_0=sym_3310_3_parameter_inst.rd (const) */
    /* execute.a64:2813 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.a64:2813 [F] s_b_12_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_12_4: If s_b_12_3: Jump b_13 else b_14 (const) */
    if (s_b_12_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_12,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2814 [D] s_b_13_0 = sym_48418_3_parameter_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_48418_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_13_1: sym_48695_3_parameter_value = s_b_13_0, dominates: s_b_35_0 s_b_36_0 s_b_37_0  */
    emitter.store_local(DV_sym_48695_3_parameter_value, s_b_13_0);
    /* execute.a64:2777 [F] s_b_13_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_13_3 = __builtin_get_feature */
    uint32_t s_b_13_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
    uint8_t s_b_13_5 = ((uint8_t)(s_b_13_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_13_6: If s_b_13_5: Jump b_35 else b_45 (const) */
    if (s_b_13_5) 
    {
      goto fixed_block_b_35;
    }
    else 
    {
      goto fixed_block_b_45;
    }
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2816 [F] s_b_14_0=sym_3310_3_parameter_inst.rd (const) */
    /* execute.a64:2816 [D] s_b_14_1 = sym_48418_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_48418_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1);
    /* execute.a64:2816 [F] s_b_14_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2764 [F] s_b_15_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_15_1 = __builtin_get_feature */
    uint32_t s_b_15_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_15_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(s_b_15_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_15_4: If s_b_15_3: Jump b_16 else b_40 (const) */
    if (s_b_15_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_40;
    }
  }
  /* b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2765 [D] s_b_16_0 = ReadReg 21 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_16_1: sym_48526_1__R_s_b_10_0 = s_b_16_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_48526_1__R_s_b_10_0, s_b_16_0);
    /* execute.a64:2765 [F] s_b_16_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_40,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2768 [D] s_b_17_0 = ReadReg 21 (u64) */
    auto s_b_17_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_17_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_17_1: sym_48526_1__R_s_b_10_0 = s_b_17_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_48526_1__R_s_b_10_0, s_b_17_0);
    /* execute.a64:2768 [F] s_b_17_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_40,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2770 [D] s_b_18_0 = ReadReg 22 (u64) */
    auto s_b_18_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_18_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_18_1: sym_48526_1__R_s_b_10_0 = s_b_18_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_48526_1__R_s_b_10_0, s_b_18_0);
    /* execute.a64:2770 [F] s_b_18_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_16, b_17, b_18,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2794 [D] s_b_19_0 = sym_48526_1__R_s_b_10_0 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_48526_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_19_1: sym_48399_1__R_s_b_0_4 = s_b_19_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_48399_1__R_s_b_0_4, s_b_19_0);
    /* execute.a64:2794 [F] s_b_19_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2764 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_20_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_20_4: If s_b_20_3: Jump b_21 else b_41 (const) */
    if (s_b_20_3) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_41;
    }
  }
  /* b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2765 [D] s_b_21_0 = ReadReg 21 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_21_1: sym_48562_1__R_s_b_12_0 = s_b_21_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_48562_1__R_s_b_12_0, s_b_21_0);
    /* execute.a64:2765 [F] s_b_21_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_41,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2768 [D] s_b_22_0 = ReadReg 21 (u64) */
    auto s_b_22_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_22_1: sym_48562_1__R_s_b_12_0 = s_b_22_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_48562_1__R_s_b_12_0, s_b_22_0);
    /* execute.a64:2768 [F] s_b_22_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_41,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2770 [D] s_b_23_0 = ReadReg 22 (u64) */
    auto s_b_23_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_23_1: sym_48562_1__R_s_b_12_0 = s_b_23_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_48562_1__R_s_b_12_0, s_b_23_0);
    /* execute.a64:2770 [F] s_b_23_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2800 [D] s_b_24_0 = sym_48562_1__R_s_b_12_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_48562_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2800 [D] s_b_24_1 = (u32)s_b_24_0 */
    auto s_b_24_1 = emitter.truncate(s_b_24_0, emitter.context().types().u32());
    /* execute.a64:2800 [D] s_b_24_2 = (u64)s_b_24_1 */
    auto s_b_24_2 = emitter.zx(s_b_24_1, emitter.context().types().u64());
    /* execute.a64:2800 [D] s_b_24_3: sym_48399_1__R_s_b_0_4 = s_b_24_2, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_48399_1__R_s_b_0_4, s_b_24_2);
    /* execute.a64:2800 [F] s_b_24_4: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_44,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2703 [D] s_b_25_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2704 [F] s_b_25_1 = constant u64 0 (const) */
    /* execute.a64:2704 [F] s_b_25_2: sym_48664_1__R_s_b_14_17 = s_b_25_1 (const), dominates: s_b_34_0  */
    CV_sym_48664_1__R_s_b_14_17 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2704 [F] s_b_25_3: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_44,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2687 [D] s_b_26_0 = sym_48578_0_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_48578_0_value, emitter.context().types().u64());
    /* execute.a64:2687 [D] s_b_26_1 = (s8)s_b_26_0 */
    auto s_b_26_1 = emitter.truncate(s_b_26_0, emitter.context().types().s8());
    /* execute.a64:2687 [D] s_b_26_2 = (s64)s_b_26_1 */
    auto s_b_26_2 = emitter.sx(s_b_26_1, emitter.context().types().s64());
    /* execute.a64:2687 [D] s_b_26_3 = (u64)s_b_26_2 */
    auto s_b_26_3 = emitter.reinterpret(s_b_26_2, emitter.context().types().u64());
    /* execute.a64:2687 [F] s_b_26_4=sym_3310_3_parameter_inst.imm3 (const) */
    /* execute.a64:2687 [F] s_b_26_5 = (u64)s_b_26_4 (const) */
    /* execute.a64:2687 [D] s_b_26_6 = s_b_26_3<<s_b_26_5 */
    auto s_b_26_6 = emitter.shl(s_b_26_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* execute.a64:2687 [D] s_b_26_7: sym_48664_1__R_s_b_14_17 = s_b_26_6, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, s_b_26_6);
    /* execute.a64:2687 [F] s_b_26_8: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_44,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2679 [D] s_b_27_0 = sym_48578_0_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_48578_0_value, emitter.context().types().u64());
    /* execute.a64:2679 [D] s_b_27_1 = (u32)s_b_27_0 */
    auto s_b_27_1 = emitter.truncate(s_b_27_0, emitter.context().types().u32());
    /* execute.a64:2679 [D] s_b_27_2 = (u64)s_b_27_1 */
    auto s_b_27_2 = emitter.zx(s_b_27_1, emitter.context().types().u64());
    /* execute.a64:2679 [F] s_b_27_3=sym_3310_3_parameter_inst.imm3 (const) */
    /* execute.a64:2679 [F] s_b_27_4 = (u64)s_b_27_3 (const) */
    /* execute.a64:2679 [D] s_b_27_5 = s_b_27_2<<s_b_27_4 */
    auto s_b_27_5 = emitter.shl(s_b_27_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* execute.a64:2679 [D] s_b_27_6: sym_48664_1__R_s_b_14_17 = s_b_27_5, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, s_b_27_5);
    /* execute.a64:2679 [F] s_b_27_7: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_44,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2683 [D] s_b_28_0 = sym_48578_0_value uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_48578_0_value, emitter.context().types().u64());
    /* execute.a64:2683 [F] s_b_28_1=sym_3310_3_parameter_inst.imm3 (const) */
    /* execute.a64:2683 [F] s_b_28_2 = (u64)s_b_28_1 (const) */
    /* execute.a64:2683 [D] s_b_28_3 = s_b_28_0<<s_b_28_2 */
    auto s_b_28_3 = emitter.shl(s_b_28_0, emitter.const_u64(((uint64_t)insn.imm3)));
    /* execute.a64:2683 [D] s_b_28_4: sym_48664_1__R_s_b_14_17 = s_b_28_3, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, s_b_28_3);
    /* execute.a64:2683 [F] s_b_28_5: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_44,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2671 [D] s_b_29_0 = sym_48578_0_value uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_48578_0_value, emitter.context().types().u64());
    /* execute.a64:2671 [D] s_b_29_1 = (u8)s_b_29_0 */
    auto s_b_29_1 = emitter.truncate(s_b_29_0, emitter.context().types().u8());
    /* execute.a64:2671 [D] s_b_29_2 = (u64)s_b_29_1 */
    auto s_b_29_2 = emitter.zx(s_b_29_1, emitter.context().types().u64());
    /* execute.a64:2671 [F] s_b_29_3=sym_3310_3_parameter_inst.imm3 (const) */
    /* execute.a64:2671 [F] s_b_29_4 = (u64)s_b_29_3 (const) */
    /* execute.a64:2671 [D] s_b_29_5 = s_b_29_2<<s_b_29_4 */
    auto s_b_29_5 = emitter.shl(s_b_29_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* execute.a64:2671 [D] s_b_29_6: sym_48664_1__R_s_b_14_17 = s_b_29_5, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, s_b_29_5);
    /* execute.a64:2671 [F] s_b_29_7: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_44,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2699 [D] s_b_30_0 = sym_48578_0_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_48578_0_value, emitter.context().types().u64());
    /* execute.a64:2699 [F] s_b_30_1=sym_3310_3_parameter_inst.imm3 (const) */
    /* execute.a64:2699 [F] s_b_30_2 = (u64)s_b_30_1 (const) */
    /* execute.a64:2699 [D] s_b_30_3 = s_b_30_0<<s_b_30_2 */
    auto s_b_30_3 = emitter.shl(s_b_30_0, emitter.const_u64(((uint64_t)insn.imm3)));
    /* execute.a64:2699 [D] s_b_30_4: sym_48664_1__R_s_b_14_17 = s_b_30_3, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, s_b_30_3);
    /* execute.a64:2699 [F] s_b_30_5: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_44,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2695 [D] s_b_31_0 = sym_48578_0_value uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_48578_0_value, emitter.context().types().u64());
    /* execute.a64:2695 [D] s_b_31_1 = (s32)s_b_31_0 */
    auto s_b_31_1 = emitter.truncate(s_b_31_0, emitter.context().types().s32());
    /* execute.a64:2695 [D] s_b_31_2 = (s64)s_b_31_1 */
    auto s_b_31_2 = emitter.sx(s_b_31_1, emitter.context().types().s64());
    /* execute.a64:2695 [D] s_b_31_3 = (u64)s_b_31_2 */
    auto s_b_31_3 = emitter.reinterpret(s_b_31_2, emitter.context().types().u64());
    /* execute.a64:2695 [F] s_b_31_4=sym_3310_3_parameter_inst.imm3 (const) */
    /* execute.a64:2695 [F] s_b_31_5 = (u64)s_b_31_4 (const) */
    /* execute.a64:2695 [D] s_b_31_6 = s_b_31_3<<s_b_31_5 */
    auto s_b_31_6 = emitter.shl(s_b_31_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* execute.a64:2695 [D] s_b_31_7: sym_48664_1__R_s_b_14_17 = s_b_31_6, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, s_b_31_6);
    /* execute.a64:2695 [F] s_b_31_8: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_44,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2691 [D] s_b_32_0 = sym_48578_0_value uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_48578_0_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_32_1 = (s16)s_b_32_0 */
    auto s_b_32_1 = emitter.truncate(s_b_32_0, emitter.context().types().s16());
    /* execute.a64:2691 [D] s_b_32_2 = (s64)s_b_32_1 */
    auto s_b_32_2 = emitter.sx(s_b_32_1, emitter.context().types().s64());
    /* execute.a64:2691 [D] s_b_32_3 = (u64)s_b_32_2 */
    auto s_b_32_3 = emitter.reinterpret(s_b_32_2, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_32_4=sym_3310_3_parameter_inst.imm3 (const) */
    /* execute.a64:2691 [F] s_b_32_5 = (u64)s_b_32_4 (const) */
    /* execute.a64:2691 [D] s_b_32_6 = s_b_32_3<<s_b_32_5 */
    auto s_b_32_6 = emitter.shl(s_b_32_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* execute.a64:2691 [D] s_b_32_7: sym_48664_1__R_s_b_14_17 = s_b_32_6, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, s_b_32_6);
    /* execute.a64:2691 [F] s_b_32_8: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_44,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2675 [D] s_b_33_0 = sym_48578_0_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_48578_0_value, emitter.context().types().u64());
    /* execute.a64:2675 [D] s_b_33_1 = (u16)s_b_33_0 */
    auto s_b_33_1 = emitter.truncate(s_b_33_0, emitter.context().types().u16());
    /* execute.a64:2675 [D] s_b_33_2 = (u64)s_b_33_1 */
    auto s_b_33_2 = emitter.zx(s_b_33_1, emitter.context().types().u64());
    /* execute.a64:2675 [F] s_b_33_3=sym_3310_3_parameter_inst.imm3 (const) */
    /* execute.a64:2675 [F] s_b_33_4 = (u64)s_b_33_3 (const) */
    /* execute.a64:2675 [D] s_b_33_5 = s_b_33_2<<s_b_33_4 */
    auto s_b_33_5 = emitter.shl(s_b_33_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* execute.a64:2675 [D] s_b_33_6: sym_48664_1__R_s_b_14_17 = s_b_33_5, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_48664_1__R_s_b_14_17, s_b_33_5);
    /* execute.a64:2675 [F] s_b_33_7: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_25, b_26, b_27, b_28, b_29, b_30, b_31, b_32, b_33,  */
  fixed_block_b_34: 
  {
    /* execute.a64:1932 [D] s_b_34_0 = sym_48664_1__R_s_b_14_17 uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_48664_1__R_s_b_14_17, emitter.context().types().u64());
    /* execute.a64:1932 [D] s_b_34_1: sym_3329_0_rm = s_b_34_0, dominates: s_b_4_1 s_b_5_2 s_b_3_2  */
    emitter.store_local(DV_sym_3329_0_rm, s_b_34_0);
    /* execute.a64:1934 [F] s_b_34_2=sym_3310_3_parameter_inst.S (const) */
    /* execute.a64:1934 [F] s_b_34_3: If s_b_34_2: Jump b_1 else b_3 (const) */
    if (insn.S) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_13,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2778 [D] s_b_35_0 = sym_48695_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_48695_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_35_1: WriteReg 21 = s_b_35_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_35_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_35_0);
    /* execute.a64:2778 [F] s_b_35_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_45,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2781 [D] s_b_36_0 = sym_48695_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_48695_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_36_1: WriteReg 21 = s_b_36_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_36_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_36_0);
    /* execute.a64:2781 [F] s_b_36_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_45,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2783 [D] s_b_37_0 = sym_48695_3_parameter_value uint64_t */
    auto s_b_37_0 = emitter.load_local(DV_sym_48695_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_37_1: WriteReg 22 = s_b_37_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_37_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_37_0);
    /* execute.a64:2783 [F] s_b_37_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2747 [F] s_b_38_0=sym_3310_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_38_1 = sym_48733_3_parameter_value uint64_t */
    auto s_b_38_1 = emitter.load_local(DV_sym_48733_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_38_2: WriteRegBank 0:s_b_38_0 = s_b_38_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_38_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_38_1);
    /* execute.a64:0 [F] s_b_38_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2747 [F] s_b_39_0=sym_3310_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_39_1 = sym_48799_3_parameter_value uint64_t */
    auto s_b_39_1 = emitter.load_local(DV_sym_48799_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_39_2: WriteRegBank 0:s_b_39_0 = s_b_39_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_39_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_39_1);
    /* execute.a64:0 [F] s_b_39_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_40: 
  {
    /* execute.a64:3075 [F] s_b_40_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_40_1 = __builtin_get_feature */
    uint32_t s_b_40_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_40_2 = (u8)s_b_40_1 (const) */
    /* execute.a64:2767 [F] s_b_40_3 = (u32)s_b_40_2 (const) */
    /* execute.a64:2767 [F] s_b_40_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_40_5 = s_b_40_3==s_b_40_4 (const) */
    uint8_t s_b_40_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_40_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_40_6: If s_b_40_5: Jump b_17 else b_18 (const) */
    if (s_b_40_5) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_20,  */
  fixed_block_b_41: 
  {
    /* execute.a64:3075 [F] s_b_41_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_41_1 = __builtin_get_feature */
    uint32_t s_b_41_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_41_2 = (u8)s_b_41_1 (const) */
    /* execute.a64:2767 [F] s_b_41_3 = (u32)s_b_41_2 (const) */
    /* execute.a64:2767 [F] s_b_41_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_41_5 = s_b_41_3==s_b_41_4 (const) */
    uint8_t s_b_41_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_41_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_41_6: If s_b_41_5: Jump b_22 else b_23 (const) */
    if (s_b_41_5) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_10,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2720 [F] s_b_42_0=sym_3310_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_42_1 = (u32)s_b_42_0 (const) */
    /* execute.a64:2714 [F] s_b_42_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_42_3 = s_b_42_1==s_b_42_2 (const) */
    uint8_t s_b_42_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_42_4: If s_b_42_3: Jump b_46 else b_47 (const) */
    if (s_b_42_3) 
    {
      goto fixed_block_b_46;
    }
    else 
    {
      goto fixed_block_b_47;
    }
  }
  /* b_10,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2722 [F] s_b_43_0=sym_3310_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_43_1 = (u32)s_b_43_0 (const) */
    /* execute.a64:2709 [F] s_b_43_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_43_3 = s_b_43_1==s_b_43_2 (const) */
    uint8_t s_b_43_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_43_4: If s_b_43_3: Jump b_49 else b_50 (const) */
    if (s_b_43_3) 
    {
      goto fixed_block_b_49;
    }
    else 
    {
      goto fixed_block_b_50;
    }
  }
  /* b_48, b_51,  */
  fixed_block_b_44: 
  {
    /* execute.a64:2666 [D] s_b_44_0 = sym_48848_1__R_s_b_44_4 uint64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_48848_1__R_s_b_44_4, emitter.context().types().u64());
    /* execute.a64:2666 [D] s_b_44_1: sym_48578_0_value = s_b_44_0, dominates: s_b_26_0 s_b_27_0 s_b_28_0 s_b_29_0 s_b_30_0 s_b_31_0 s_b_32_0 s_b_33_0  */
    emitter.store_local(DV_sym_48578_0_value, s_b_44_0);
    /* execute.a64:2668 [F] s_b_44_2=sym_3310_3_parameter_inst.option (const) */
    /* execute.a64:2669 [F] s_b_44_3 = constant s32 0 (const) */
    /* execute.a64:2673 [F] s_b_44_4 = constant s32 1 (const) */
    /* execute.a64:2677 [F] s_b_44_5 = constant s32 2 (const) */
    /* execute.a64:2681 [F] s_b_44_6 = constant s32 3 (const) */
    /* execute.a64:2685 [F] s_b_44_7 = constant s32 4 (const) */
    /* execute.a64:2689 [F] s_b_44_8 = constant s32 5 (const) */
    /* execute.a64:2693 [F] s_b_44_9 = constant s32 6 (const) */
    /* execute.a64:2697 [F] s_b_44_10 = constant s32 7 (const) */
    /* execute.a64:2668 [F] s_b_44_11: Switch s_b_44_2: < <todo> > def b_25 (const) -> b_25, b_26, b_27, b_28, b_29, b_30, b_31, b_32, b_33,  */
    switch (insn.option) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_29;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_33;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_27;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_28;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_26;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_32;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_31;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_30;
      break;
    default:
      goto fixed_block_b_25;
    }
  }
  /* b_13,  */
  fixed_block_b_45: 
  {
    /* execute.a64:3075 [F] s_b_45_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_45_1 = __builtin_get_feature */
    uint32_t s_b_45_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_45_2 = (u8)s_b_45_1 (const) */
    /* execute.a64:2780 [F] s_b_45_3 = (u32)s_b_45_2 (const) */
    /* execute.a64:2780 [F] s_b_45_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_45_5 = s_b_45_3==s_b_45_4 (const) */
    uint8_t s_b_45_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_45_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_45_6: If s_b_45_5: Jump b_36 else b_37 (const) */
    if (s_b_45_5) 
    {
      goto fixed_block_b_36;
    }
    else 
    {
      goto fixed_block_b_37;
    }
  }
  /* b_42,  */
  fixed_block_b_46: 
  {
    /* execute.a64:2714 [F] s_b_46_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_46_1: sym_48878_1_temporary_value = s_b_46_0 (const), dominates: s_b_48_0  */
    CV_sym_48878_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_48878_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_46_2: Jump b_48 (const) */
    goto fixed_block_b_48;
  }
  /* b_42,  */
  fixed_block_b_47: 
  {
    /* execute.a64:2714 [F] s_b_47_0=sym_3310_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_47_1 = ReadRegBank 0:s_b_47_0 (u64) */
    auto s_b_47_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_47_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_47_2: sym_48878_1_temporary_value = s_b_47_1, dominates: s_b_48_0  */
    emitter.store_local(DV_sym_48878_1_temporary_value, s_b_47_1);
    /* execute.a64:2714 [F] s_b_47_3: Jump b_48 (const) */
    goto fixed_block_b_48;
  }
  /* b_46, b_47,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2714 [D] s_b_48_0 = sym_48878_1_temporary_value uint64_t */
    auto s_b_48_0 = emitter.load_local(DV_sym_48878_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_48_1: sym_48848_1__R_s_b_44_4 = s_b_48_0, dominates: s_b_44_0  */
    emitter.store_local(DV_sym_48848_1__R_s_b_44_4, s_b_48_0);
    /* execute.a64:2720 [F] s_b_48_2: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_43,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2709 [F] s_b_49_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_49_1: sym_48906_1_temporary_value = s_b_49_0 (const), dominates: s_b_51_0  */
    CV_sym_48906_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_48906_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_49_2: Jump b_51 (const) */
    goto fixed_block_b_51;
  }
  /* b_43,  */
  fixed_block_b_50: 
  {
    /* execute.a64:2709 [F] s_b_50_0=sym_3310_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_50_1 = ReadRegBank 1:s_b_50_0 (u32) */
    auto s_b_50_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_50_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_50_2: sym_48906_1_temporary_value = s_b_50_1, dominates: s_b_51_0  */
    emitter.store_local(DV_sym_48906_1_temporary_value, s_b_50_1);
    /* execute.a64:2709 [F] s_b_50_3: Jump b_51 (const) */
    goto fixed_block_b_51;
  }
  /* b_49, b_50,  */
  fixed_block_b_51: 
  {
    /* execute.a64:2709 [D] s_b_51_0 = sym_48906_1_temporary_value uint32_t */
    auto s_b_51_0 = emitter.load_local(DV_sym_48906_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_51_1 = (u64)s_b_51_0 */
    auto s_b_51_1 = emitter.zx(s_b_51_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_51_2: sym_48848_1__R_s_b_44_4 = s_b_51_1, dominates: s_b_44_0  */
    emitter.store_local(DV_sym_48848_1__R_s_b_44_4, s_b_51_1);
    /* execute.a64:2722 [F] s_b_51_3: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_and_vector(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1129 [F] s_b_0_0=sym_5740_3_parameter_inst.Q (const) */
    /* execute.simd:1129 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:1129 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:1129 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:1129 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:1130 [F] s_b_1_0=sym_5740_3_parameter_inst.rd (const) */
    /* execute.simd:1130 [F] s_b_1_1=sym_5740_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:1130 [F] s_b_1_3=sym_5740_3_parameter_inst.rm (const) */
    /* execute.simd:6355 [D] s_b_1_4 = ReadRegBank 7:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:1130 [D] s_b_1_5 = s_b_1_2&s_b_1_4 */
    auto s_b_1_5 = emitter.bitwise_and(s_b_1_2, s_b_1_4);
    /* execute.simd:6326 [D] s_b_1_6: WriteRegBank 2:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6327 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_8: WriteRegBank 3:s_b_1_0 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1137 [F] s_b_3_0=sym_5740_3_parameter_inst.rn (const) */
    /* execute.simd:6360 [D] s_b_3_1 = ReadRegBank 2:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_3_2 = ReadRegBank 3:s_b_3_0 (u64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:1138 [F] s_b_3_3=sym_5740_3_parameter_inst.rm (const) */
    /* execute.simd:6360 [D] s_b_3_4 = ReadRegBank 2:s_b_3_3 (u64) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_3_5 = ReadRegBank 3:s_b_3_3 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:1140 [F] s_b_3_6=sym_5740_3_parameter_inst.rd (const) */
    /* execute.simd:1140 [D] s_b_3_7 = s_b_3_1&s_b_3_4 */
    auto s_b_3_7 = emitter.bitwise_and(s_b_3_1, s_b_3_4);
    /* execute.simd:1140 [D] s_b_3_8 = s_b_3_2&s_b_3_5 */
    auto s_b_3_8 = emitter.bitwise_and(s_b_3_2, s_b_3_5);
    /* execute.simd:6333 [D] s_b_3_9: WriteRegBank 2:s_b_3_6 = s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7);
    /* execute.simd:6334 [D] s_b_3_10: WriteRegBank 3:s_b_3_6 = s_b_3_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_8,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_8);
    /* execute.simd:0 [F] s_b_3_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_bic_vector(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1197 [F] s_b_0_0=sym_6168_3_parameter_inst.Q (const) */
    /* execute.simd:1197 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:1197 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:1197 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:1197 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:1198 [F] s_b_1_0=sym_6168_3_parameter_inst.rd (const) */
    /* execute.simd:1198 [F] s_b_1_1=sym_6168_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:1198 [F] s_b_1_3=sym_6168_3_parameter_inst.rm (const) */
    /* execute.simd:6355 [D] s_b_1_4 = ReadRegBank 7:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:1198 [D] s_b_1_5 = ~s_b_1_4 */
    auto s_b_1_5 = emitter.bitwise_not(s_b_1_4);
    /* execute.simd:1198 [D] s_b_1_6 = s_b_1_2&s_b_1_5 */
    auto s_b_1_6 = emitter.bitwise_and(s_b_1_2, s_b_1_5);
    /* execute.simd:6326 [D] s_b_1_7: WriteRegBank 2:s_b_1_0 = s_b_1_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_6);
    /* execute.simd:6327 [F] s_b_1_8 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_9: WriteRegBank 3:s_b_1_0 = s_b_1_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1205 [F] s_b_3_0=sym_6168_3_parameter_inst.rn (const) */
    /* execute.simd:6360 [D] s_b_3_1 = ReadRegBank 2:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_3_2 = ReadRegBank 3:s_b_3_0 (u64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:1206 [F] s_b_3_3=sym_6168_3_parameter_inst.rm (const) */
    /* execute.simd:6360 [D] s_b_3_4 = ReadRegBank 2:s_b_3_3 (u64) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_3_5 = ReadRegBank 3:s_b_3_3 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:1208 [F] s_b_3_6=sym_6168_3_parameter_inst.rd (const) */
    /* execute.simd:1208 [D] s_b_3_7 = ~s_b_3_4 */
    auto s_b_3_7 = emitter.bitwise_not(s_b_3_4);
    /* execute.simd:1208 [D] s_b_3_8 = s_b_3_1&s_b_3_7 */
    auto s_b_3_8 = emitter.bitwise_and(s_b_3_1, s_b_3_7);
    /* execute.simd:1208 [D] s_b_3_9 = ~s_b_3_5 */
    auto s_b_3_9 = emitter.bitwise_not(s_b_3_5);
    /* execute.simd:1208 [D] s_b_3_10 = s_b_3_2&s_b_3_9 */
    auto s_b_3_10 = emitter.bitwise_and(s_b_3_2, s_b_3_9);
    /* execute.simd:6333 [D] s_b_3_11: WriteRegBank 2:s_b_3_6 = s_b_3_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_8,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_8);
    /* execute.simd:6334 [D] s_b_3_12: WriteRegBank 3:s_b_3_6 = s_b_3_10 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_10,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_10);
    /* execute.simd:0 [F] s_b_3_13: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ccmni(const arm64_decode_a64_COND_CMP_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_18 = emitter.context().create_block();
  auto block_b_19 = emitter.context().create_block();
  auto block_b_20 = emitter.context().create_block();
  auto block_b_21 = emitter.context().create_block();
  auto block_b_22 = emitter.context().create_block();
  auto block_b_23 = emitter.context().create_block();
  auto block_b_24 = emitter.context().create_block();
  auto block_b_25 = emitter.context().create_block();
  auto block_b_26 = emitter.context().create_block();
  auto DV_sym_55329_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_55257_1__R_s_b_0_2 = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_55169_0_state;
  auto DV_sym_55169_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55301_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_6586_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55282_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2103 [F] s_b_0_0=sym_6568_3_parameter_inst.cond (const) */
    /* execute.a64:2854 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2854 [F] s_b_0_2: sym_55169_0_state = s_b_0_1 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_55169_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_55169_0_state, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2856 [F] s_b_0_3 = (u32)s_b_0_0 (const) */
    /* execute.a64:2856 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:2856 [F] s_b_0_5 = s_b_0_3>>s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(((uint32_t)insn.cond) >> (uint32_t)1ULL));
    /* execute.a64:2857 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.a64:2861 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.a64:2865 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.a64:2869 [F] s_b_0_9 = constant s32 3 (const) */
    /* execute.a64:2873 [F] s_b_0_10 = constant s32 4 (const) */
    /* execute.a64:2877 [F] s_b_0_11 = constant s32 5 (const) */
    /* execute.a64:2881 [F] s_b_0_12 = constant s32 6 (const) */
    /* execute.a64:2885 [F] s_b_0_13 = constant s32 7 (const) */
    /* execute.a64:2856 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_9, b_8, b_7, b_13, b_12, b_10, b_6, b_14, b_11,  */
    switch (s_b_0_5) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_11;
      break;
    default:
      goto fixed_block_b_6;
    }
  }
  // BLOCK b_1 not fully fixed
  // BLOCK b_2 not fully fixed
  // BLOCK b_3 not fully fixed
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  /* b_0, b_7, b_8, b_9, b_10, b_11, b_12, b_13, b_14,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2891 [F] s_b_6_0=sym_6568_3_parameter_inst.cond (const) */
    /* execute.a64:2891 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2891 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.a64:2891 [F] s_b_6_3 = s_b_6_1&s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2891 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:2891 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:2891 [F] s_b_6_6=sym_6568_3_parameter_inst.cond (const) */
    /* execute.a64:2891 [F] s_b_6_7 = (u32)s_b_6_6 (const) */
    /* execute.a64:2891 [F] s_b_6_8 = constant u32 f (const) */
    /* execute.a64:2891 [F] s_b_6_9 = s_b_6_7!=s_b_6_8 (const) */
    uint8_t s_b_6_9 = ((uint8_t)(((uint32_t)insn.cond) != (uint32_t)15ULL));
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_6_11 = s_b_6_5!=s_b_6_10 (const) */
    uint8_t s_b_6_11 = ((uint8_t)(s_b_6_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_12 = s_b_6_9!=s_b_6_10 (const) */
    uint8_t s_b_6_12 = ((uint8_t)(s_b_6_9 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_13 = s_b_6_11&s_b_6_12 (const) */
    uint8_t s_b_6_13 = ((uint8_t)(s_b_6_11 & s_b_6_12));
    /* execute.a64:2891 [F] s_b_6_14: If s_b_6_13: Jump b_15 else b_16 (const) */
    if (s_b_6_13) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2878 [D] s_b_7_0 = ReadReg 1 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_7_1 = ReadReg 4 (u8) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_7_1, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_7_2 = s_b_7_0==s_b_7_1 */
    auto s_b_7_2 = emitter.cmp_eq(s_b_7_0, s_b_7_1);
    /* execute.a64:2878 [D] s_b_7_3: sym_55169_0_state = s_b_7_2, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55169_0_state, s_b_7_2);
    /* execute.a64:0 [F] s_b_7_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2874 [D] s_b_8_0 = ReadReg 3 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2874 [D] s_b_8_1 = ReadReg 2 (u8) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_8_1, emitter.const_u8(1));
    }
    /* execute.a64:2874 [D] s_b_8_2 = !s_b_8_1 */
    auto s_b_8_2 = emitter.cmp_eq(s_b_8_1, emitter.const_u8(0));
    /* execute.a64:2874 [D] s_b_8_3 = s_b_8_0&s_b_8_2 */
    auto s_b_8_3 = emitter.bitwise_and(s_b_8_0, s_b_8_2);
    /* execute.a64:2874 [D] s_b_8_4: sym_55169_0_state = s_b_8_3, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55169_0_state, s_b_8_3);
    /* execute.a64:0 [F] s_b_8_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2870 [D] s_b_9_0 = ReadReg 4 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2870 [D] s_b_9_1: sym_55169_0_state = s_b_9_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55169_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2866 [D] s_b_10_0 = ReadReg 1 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2866 [D] s_b_10_1: sym_55169_0_state = s_b_10_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55169_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2862 [D] s_b_11_0 = ReadReg 3 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2862 [D] s_b_11_1: sym_55169_0_state = s_b_11_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55169_0_state, s_b_11_0);
    /* execute.a64:0 [F] s_b_11_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2858 [D] s_b_12_0 = ReadReg 2 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2858 [D] s_b_12_1: sym_55169_0_state = s_b_12_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55169_0_state, s_b_12_0);
    /* execute.a64:0 [F] s_b_12_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2882 [D] s_b_13_0 = ReadReg 1 (u8) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_13_1 = ReadReg 4 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_13_1, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_13_2 = s_b_13_0==s_b_13_1 */
    auto s_b_13_2 = emitter.cmp_eq(s_b_13_0, s_b_13_1);
    /* execute.a64:2882 [D] s_b_13_3 = ReadReg 2 (u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_13_3, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_13_4 = !s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_eq(s_b_13_3, emitter.const_u8(0));
    /* execute.a64:2882 [D] s_b_13_5 = s_b_13_2&s_b_13_4 */
    auto s_b_13_5 = emitter.bitwise_and(s_b_13_2, s_b_13_4);
    /* execute.a64:2882 [D] s_b_13_6: sym_55169_0_state = s_b_13_5, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55169_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2886 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2886 [F] s_b_14_1: sym_55169_0_state = s_b_14_0 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_55169_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_55169_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2892 [D] s_b_15_0 = sym_55169_0_state uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_55169_0_state, emitter.context().types().u8());
    /* execute.a64:2892 [D] s_b_15_1 = !s_b_15_0 */
    auto s_b_15_1 = emitter.cmp_eq(s_b_15_0, emitter.const_u8(0));
    /* execute.a64:2892 [D] s_b_15_2: sym_55257_1__R_s_b_0_2 = s_b_15_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_55257_1__R_s_b_0_2, s_b_15_1);
    /* execute.a64:2892 [F] s_b_15_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2894 [D] s_b_16_0 = sym_55169_0_state uint8_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_55169_0_state, emitter.context().types().u8());
    /* execute.a64:2894 [D] s_b_16_1: sym_55257_1__R_s_b_0_2 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_55257_1__R_s_b_0_2, s_b_16_0);
    /* execute.a64:2894 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2103 [D] s_b_17_0 = sym_55257_1__R_s_b_0_2 uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_55257_1__R_s_b_0_2, emitter.context().types().u8());
    /* execute.a64:2105 [D] s_b_17_1 = (u32)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u32());
    /* execute.a64:2105 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.a64:2105 [D] s_b_17_3 = s_b_17_1!=s_b_17_2 */
    auto s_b_17_3 = emitter.cmp_ne(s_b_17_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2105 [D] s_b_17_4: If s_b_17_3: Jump b_1 else b_3 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_1;
        dynamic_block_queue.push(block_b_1);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_3;
        dynamic_block_queue.push(block_b_3);
        false_target = block;
      }
      emitter.branch(s_b_17_3, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_18 not fully fixed
  // BLOCK b_19 not fully fixed
  // BLOCK b_20 not fully fixed
  // BLOCK b_21 not fully fixed
  // BLOCK b_22 not fully fixed
  // BLOCK b_23 not fully fixed
  // BLOCK b_24 not fully fixed
  // BLOCK b_25 not fully fixed
  // BLOCK b_26 not fully fixed
  fixed_done:
  if (dynamic_block_queue.size() > 0) 
  {
    std::set<captive::arch::dbt::el::Block *> emitted_blocks;
    while (dynamic_block_queue.size() > 0) 
    {
      captive::arch::dbt::el::Block *block_index = dynamic_block_queue.front();
      dynamic_block_queue.pop();
      if (emitted_blocks.count(block_index)) continue;
      emitted_blocks.insert(block_index);
      if (block_index == block_b_1) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_1);
        /* execute.a64:2106 [F] s_b_1_0=sym_6568_3_parameter_inst.sf (const) */
        /* execute.a64:2719 [F] s_b_1_1: If s_b_1_0: Jump b_18 else b_19 (const) */
        if (insn.sf) 
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_2) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_2);
        /* ???:4294967295 [F] s_b_2_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_3) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_3);
        /* execute.a64:2114 [F] s_b_3_0=sym_6568_3_parameter_inst.nzcv (const) */
        /* execute.a64:2114 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.a64:2114 [F] s_b_3_2 = constant u32 8 (const) */
        /* execute.a64:2114 [F] s_b_3_3 = s_b_3_1&s_b_3_2 (const) */
        uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)8ULL));
        /* execute.a64:2114 [F] s_b_3_4 = constant u32 8 (const) */
        /* execute.a64:2114 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
        uint8_t s_b_3_5 = ((uint8_t)(s_b_3_3 == (uint32_t)8ULL));
        /* execute.a64:2114 [F] s_b_3_6: WriteReg 1 = s_b_3_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), emitter.const_u8(s_b_3_5), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1296), emitter.const_u8(s_b_3_5));
        /* execute.a64:2115 [F] s_b_3_7=sym_6568_3_parameter_inst.nzcv (const) */
        /* execute.a64:2115 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
        /* execute.a64:2115 [F] s_b_3_9 = constant u32 4 (const) */
        /* execute.a64:2115 [F] s_b_3_10 = s_b_3_8&s_b_3_9 (const) */
        uint32_t s_b_3_10 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)4ULL));
        /* execute.a64:2115 [F] s_b_3_11 = constant u32 4 (const) */
        /* execute.a64:2115 [F] s_b_3_12 = s_b_3_10==s_b_3_11 (const) */
        uint8_t s_b_3_12 = ((uint8_t)(s_b_3_10 == (uint32_t)4ULL));
        /* execute.a64:2115 [F] s_b_3_13: WriteReg 2 = s_b_3_12 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), emitter.const_u8(s_b_3_12), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1297), emitter.const_u8(s_b_3_12));
        /* execute.a64:2116 [F] s_b_3_14=sym_6568_3_parameter_inst.nzcv (const) */
        /* execute.a64:2116 [F] s_b_3_15 = (u32)s_b_3_14 (const) */
        /* execute.a64:2116 [F] s_b_3_16 = constant u32 2 (const) */
        /* execute.a64:2116 [F] s_b_3_17 = s_b_3_15&s_b_3_16 (const) */
        uint32_t s_b_3_17 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)2ULL));
        /* execute.a64:2116 [F] s_b_3_18 = constant u32 2 (const) */
        /* execute.a64:2116 [F] s_b_3_19 = s_b_3_17==s_b_3_18 (const) */
        uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 == (uint32_t)2ULL));
        /* execute.a64:2116 [F] s_b_3_20: WriteReg 3 = s_b_3_19 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8(s_b_3_19), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1298), emitter.const_u8(s_b_3_19));
        /* execute.a64:2117 [F] s_b_3_21=sym_6568_3_parameter_inst.nzcv (const) */
        /* execute.a64:2117 [F] s_b_3_22 = (u32)s_b_3_21 (const) */
        /* execute.a64:2117 [F] s_b_3_23 = constant u32 1 (const) */
        /* execute.a64:2117 [F] s_b_3_24 = s_b_3_22&s_b_3_23 (const) */
        uint32_t s_b_3_24 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)1ULL));
        /* execute.a64:2117 [F] s_b_3_25 = constant u32 1 (const) */
        /* execute.a64:2117 [F] s_b_3_26 = s_b_3_24==s_b_3_25 (const) */
        uint8_t s_b_3_26 = ((uint8_t)(s_b_3_24 == (uint32_t)1ULL));
        /* execute.a64:2117 [F] s_b_3_27: WriteReg 4 = s_b_3_26 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8(s_b_3_26), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1299), emitter.const_u8(s_b_3_26));
        /* execute.a64:2114 [F] s_b_3_28: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.a64:2109 [D] s_b_4_0 = sym_6586_0_rn uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_6586_0_rn, emitter.context().types().u64());
        /* execute.a64:2109 [D] s_b_4_1 = (u32)s_b_4_0 */
        auto s_b_4_1 = emitter.truncate(s_b_4_0, emitter.context().types().u32());
        /* execute.a64:2109 [F] s_b_4_2=sym_6568_3_parameter_inst.imm5 (const) */
        /* execute.a64:2109 [F] s_b_4_3 = (u32)s_b_4_2 (const) */
        /* execute.a64:2109 [F] s_b_4_4 = constant u8 0 (const) */
        /* execute.a64:2109 [D] s_b_4_5 = __builtin_adc32_flags */
        auto s_b_4_5 = emitter.adcf(s_b_4_1, emitter.const_u32(((uint32_t)insn.imm5)), emitter.const_u8((uint8_t)0ULL));
        /* execute.a64:2109 [F] s_b_4_6: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2111 [D] s_b_5_0 = sym_6586_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_6586_0_rn, emitter.context().types().u64());
        /* execute.a64:2111 [F] s_b_5_1=sym_6568_3_parameter_inst.imm5 (const) */
        /* execute.a64:2111 [F] s_b_5_2 = (u64)s_b_5_1 (const) */
        /* execute.a64:2111 [F] s_b_5_3 = constant u8 0 (const) */
        /* execute.a64:2111 [D] s_b_5_4 = __builtin_adc64_flags */
        auto s_b_5_4 = emitter.adcf(s_b_5_0, emitter.const_u64(((uint64_t)insn.imm5)), emitter.const_u8((uint8_t)0ULL));
        /* execute.a64:2111 [F] s_b_5_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2720 [F] s_b_18_0=sym_6568_3_parameter_inst.rn (const) */
        /* execute.a64:2714 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
        /* execute.a64:2714 [F] s_b_18_2 = constant u32 1f (const) */
        /* execute.a64:2714 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
        uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2714 [F] s_b_18_4: If s_b_18_3: Jump b_21 else b_22 (const) */
        if (s_b_18_3) 
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_22;
          dynamic_block_queue.push(block_b_22);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.a64:2722 [F] s_b_19_0=sym_6568_3_parameter_inst.rn (const) */
        /* execute.a64:2709 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.a64:2709 [F] s_b_19_2 = constant u32 1f (const) */
        /* execute.a64:2709 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
        uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2709 [F] s_b_19_4: If s_b_19_3: Jump b_24 else b_25 (const) */
        if (s_b_19_3) 
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.a64:2106 [D] s_b_20_0 = sym_55282_1__R_s_b_1_4 uint64_t */
        auto s_b_20_0 = emitter.load_local(DV_sym_55282_1__R_s_b_1_4, emitter.context().types().u64());
        /* execute.a64:2106 [D] s_b_20_1: sym_6586_0_rn = s_b_20_0, dominates: s_b_4_0 s_b_5_0  */
        emitter.store_local(DV_sym_6586_0_rn, s_b_20_0);
        /* execute.a64:2108 [F] s_b_20_2=sym_6568_3_parameter_inst.sf (const) */
        /* execute.a64:2108 [F] s_b_20_3 = (u32)s_b_20_2 (const) */
        /* execute.a64:2108 [F] s_b_20_4 = constant u32 0 (const) */
        /* execute.a64:2108 [F] s_b_20_5 = s_b_20_3==s_b_20_4 (const) */
        uint8_t s_b_20_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
        /* execute.a64:2108 [F] s_b_20_6: If s_b_20_5: Jump b_4 else b_5 (const) */
        if (s_b_20_5) 
        {
          auto block = block_b_4;
          dynamic_block_queue.push(block_b_4);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_5;
          dynamic_block_queue.push(block_b_5);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.a64:2714 [F] s_b_21_0 = constant u64 0 (const) */
        /* execute.a64:2714 [D] s_b_21_1: sym_55301_1_temporary_value = s_b_21_0, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_55301_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2714 [F] s_b_21_2: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.a64:2714 [F] s_b_22_0=sym_6568_3_parameter_inst.rn (const) */
        /* execute.a64:2714 [D] s_b_22_1 = ReadRegBank 0:s_b_22_0 (u64) */
        auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_22_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_22_2: sym_55301_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_55301_1_temporary_value, s_b_22_1);
        /* execute.a64:2714 [F] s_b_22_3: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.a64:2714 [D] s_b_23_0 = sym_55301_1_temporary_value uint64_t */
        auto s_b_23_0 = emitter.load_local(DV_sym_55301_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_23_1: sym_55282_1__R_s_b_1_4 = s_b_23_0, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_55282_1__R_s_b_1_4, s_b_23_0);
        /* execute.a64:2720 [F] s_b_23_2: Jump b_20 (const) */
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.a64:2709 [F] s_b_24_0 = constant u32 0 (const) */
        /* execute.a64:2709 [D] s_b_24_1: sym_55329_1_temporary_value = s_b_24_0, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_55329_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2709 [F] s_b_24_2: Jump b_26 (const) */
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.a64:2709 [F] s_b_25_0=sym_6568_3_parameter_inst.rn (const) */
        /* execute.a64:2709 [D] s_b_25_1 = ReadRegBank 1:s_b_25_0 (u32) */
        auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_25_2: sym_55329_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_55329_1_temporary_value, s_b_25_1);
        /* execute.a64:2709 [F] s_b_25_3: Jump b_26 (const) */
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.a64:2709 [D] s_b_26_0 = sym_55329_1_temporary_value uint32_t */
        auto s_b_26_0 = emitter.load_local(DV_sym_55329_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_26_1 = (u64)s_b_26_0 */
        auto s_b_26_1 = emitter.zx(s_b_26_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_26_2: sym_55282_1__R_s_b_1_4 = s_b_26_1, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_55282_1__R_s_b_1_4, s_b_26_1);
        /* execute.a64:2722 [F] s_b_26_3: Jump b_20 (const) */
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
    }
  }
  else 
  {
    emitter.jump(__exit_block);
  }
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_cmeq_zero(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1823 [F] s_b_0_0=sym_7259_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1823 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
    if (insn.SCALAR) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:1824 [F] s_b_1_0=sym_7259_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:1826 [F] s_b_1_2 = constant u64 0 (const) */
    /* execute.simd:1826 [D] s_b_1_3 = s_b_1_1==s_b_1_2 */
    auto s_b_1_3 = emitter.cmp_eq(s_b_1_1, emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:1826 [D] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_4;
        dynamic_block_queue.push(block_b_4);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_5;
        dynamic_block_queue.push(block_b_5);
        false_target = block;
      }
      emitter.branch(s_b_1_3, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1832 [F] s_b_3_0=sym_7259_3_parameter_inst.arrangement (const) */
    /* execute.simd:1833 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:1842 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:1850 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:1859 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:1867 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:1876 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:1884 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:1832 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_13 (const) -> b_13, b_12, b_11, b_10, b_9, b_8, b_7, b_6,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_6;
      break;
    default:
      goto fixed_block_b_13;
    }
  }
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:1834 [F] s_b_6_0=sym_7259_3_parameter_inst.rn (const) */
    /* execute.simd:1834 [D] s_b_6_1 = ReadRegBank 15:s_b_6_0 (v8u8) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v8u8 
    {
    }
    (const) */
    /* execute.simd:1836 [D] s_b_6_3 = s_b_6_1==s_b_6_2 */
    auto s_b_6_3 = emitter.cmp_eq(s_b_6_1, emitter.constant_vector_splat(wutils::Vector<uint8_t, 8>(0)[0], emitter.context().types().v8u8()));
    /* execute.simd:1837 [F] s_b_6_4=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1837 [D] s_b_6_5: WriteRegBank 15:s_b_6_4 = s_b_6_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_3);
    /* execute.simd:1838 [F] s_b_6_6=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1838 [F] s_b_6_7 = constant u64 0 (const) */
    /* execute.simd:1838 [F] s_b_6_8: WriteRegBank 3:s_b_6_6 = s_b_6_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_9: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:1843 [F] s_b_7_0=sym_7259_3_parameter_inst.rn (const) */
    /* execute.simd:1843 [D] s_b_7_1 = ReadRegBank 16:s_b_7_0 (v16u8) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_2 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:1845 [D] s_b_7_3 = s_b_7_1==s_b_7_2 */
    auto s_b_7_3 = emitter.cmp_eq(s_b_7_1, emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()));
    /* execute.simd:1846 [F] s_b_7_4=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1846 [D] s_b_7_5: WriteRegBank 16:s_b_7_4 = s_b_7_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3);
    /* execute.simd:0 [F] s_b_7_6: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:1851 [F] s_b_8_0=sym_7259_3_parameter_inst.rn (const) */
    /* execute.simd:1851 [D] s_b_8_1 = ReadRegBank 17:s_b_8_0 (v4u16) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_8_2 = constant v4u16 
    {
    }
    (const) */
    /* execute.simd:1853 [D] s_b_8_3 = s_b_8_1==s_b_8_2 */
    auto s_b_8_3 = emitter.cmp_eq(s_b_8_1, emitter.constant_vector_splat(wutils::Vector<uint16_t, 4>(0)[0], emitter.context().types().v4u16()));
    /* execute.simd:1854 [F] s_b_8_4=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1854 [D] s_b_8_5: WriteRegBank 17:s_b_8_4 = s_b_8_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_3);
    /* execute.simd:1855 [F] s_b_8_6=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1855 [F] s_b_8_7 = constant u64 0 (const) */
    /* execute.simd:1855 [F] s_b_8_8: WriteRegBank 3:s_b_8_6 = s_b_8_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_9: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:1860 [F] s_b_9_0=sym_7259_3_parameter_inst.rn (const) */
    /* execute.simd:1860 [D] s_b_9_1 = ReadRegBank 18:s_b_9_0 (v8u16) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_9_2 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:1862 [D] s_b_9_3 = s_b_9_1==s_b_9_2 */
    auto s_b_9_3 = emitter.cmp_eq(s_b_9_1, emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()));
    /* execute.simd:1864 [F] s_b_9_4=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1864 [D] s_b_9_5: WriteRegBank 18:s_b_9_4 = s_b_9_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_3,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_3);
    /* execute.simd:0 [F] s_b_9_6: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:1868 [F] s_b_10_0=sym_7259_3_parameter_inst.rn (const) */
    /* execute.simd:1868 [D] s_b_10_1 = ReadRegBank 19:s_b_10_0 (v2u32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_10_2 = constant v2u32 
    {
    }
    (const) */
    /* execute.simd:1870 [D] s_b_10_3 = s_b_10_1==s_b_10_2 */
    auto s_b_10_3 = emitter.cmp_eq(s_b_10_1, emitter.constant_vector_splat(wutils::Vector<uint32_t, 2>(0)[0], emitter.context().types().v2u32()));
    /* execute.simd:1871 [F] s_b_10_4=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1871 [D] s_b_10_5: WriteRegBank 19:s_b_10_4 = s_b_10_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_3);
    /* execute.simd:1872 [F] s_b_10_6=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1872 [F] s_b_10_7 = constant u64 0 (const) */
    /* execute.simd:1872 [F] s_b_10_8: WriteRegBank 3:s_b_10_6 = s_b_10_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_10_9: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:1877 [F] s_b_11_0=sym_7259_3_parameter_inst.rn (const) */
    /* execute.simd:1877 [D] s_b_11_1 = ReadRegBank 20:s_b_11_0 (v4u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_11_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_11_2 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:1879 [D] s_b_11_3 = s_b_11_1==s_b_11_2 */
    auto s_b_11_3 = emitter.cmp_eq(s_b_11_1, emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()));
    /* execute.simd:1881 [F] s_b_11_4=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1881 [D] s_b_11_5: WriteRegBank 20:s_b_11_4 = s_b_11_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_3,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_3);
    /* execute.simd:0 [F] s_b_11_6: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_12: 
  {
    /* execute.simd:1885 [F] s_b_12_0=sym_7259_3_parameter_inst.rn (const) */
    /* execute.simd:1885 [D] s_b_12_1 = ReadRegBank 21:s_b_12_0 (v2u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_12_2 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:1887 [D] s_b_12_3 = s_b_12_1==s_b_12_2 */
    auto s_b_12_3 = emitter.cmp_eq(s_b_12_1, emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()));
    /* execute.simd:1889 [F] s_b_12_4=sym_7259_3_parameter_inst.rd (const) */
    /* execute.simd:1889 [D] s_b_12_5: WriteRegBank 21:s_b_12_4 = s_b_12_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_3,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_3);
    /* execute.simd:0 [F] s_b_12_6: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_13: 
  {
    /* execute.simd:1893 [D] s_b_13_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_13_1: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  fixed_done:
  if (dynamic_block_queue.size() > 0) 
  {
    std::set<captive::arch::dbt::el::Block *> emitted_blocks;
    while (dynamic_block_queue.size() > 0) 
    {
      captive::arch::dbt::el::Block *block_index = dynamic_block_queue.front();
      dynamic_block_queue.pop();
      if (emitted_blocks.count(block_index)) continue;
      emitted_blocks.insert(block_index);
      if (block_index == block_b_2) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_2);
        /* ???:4294967295 [F] s_b_2_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.simd:1827 [F] s_b_4_0=sym_7259_3_parameter_inst.rd (const) */
        /* execute.simd:1827 [F] s_b_4_1 = constant u64 ffffffff (const) */
        /* execute.simd:6326 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)4294967295ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)4294967295ULL));
        /* execute.simd:6327 [F] s_b_4_3 = constant u64 0 (const) */
        /* execute.simd:6327 [F] s_b_4_4: WriteRegBank 3:s_b_4_0 = s_b_4_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_4_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:1829 [F] s_b_5_0=sym_7259_3_parameter_inst.rd (const) */
        /* execute.simd:1829 [F] s_b_5_1 = constant u64 0 (const) */
        /* execute.simd:6326 [F] s_b_5_2: WriteRegBank 2:s_b_5_0 = s_b_5_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6327 [F] s_b_5_3 = constant u64 0 (const) */
        /* execute.simd:6327 [F] s_b_5_4: WriteRegBank 3:s_b_5_0 = s_b_5_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_5_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
    }
  }
  else 
  {
    emitter.jump(__exit_block);
  }
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_crc32c(const arm64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:3097 [D] s_b_0_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* ???:4294967295 [F] s_b_0_1: Return */
    goto fixed_done;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_eor_vector(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1163 [F] s_b_0_0=sym_10083_3_parameter_inst.Q (const) */
    /* execute.simd:1163 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:1163 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:1163 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:1163 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:1164 [F] s_b_1_0=sym_10083_3_parameter_inst.rd (const) */
    /* execute.simd:1164 [F] s_b_1_1=sym_10083_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:1164 [F] s_b_1_3=sym_10083_3_parameter_inst.rm (const) */
    /* execute.simd:6355 [D] s_b_1_4 = ReadRegBank 7:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:1164 [D] s_b_1_5 = s_b_1_2^s_b_1_4 */
    auto s_b_1_5 = emitter.bitwise_xor(s_b_1_2, s_b_1_4);
    /* execute.simd:6326 [D] s_b_1_6: WriteRegBank 2:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6327 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_8: WriteRegBank 3:s_b_1_0 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1171 [F] s_b_3_0=sym_10083_3_parameter_inst.rn (const) */
    /* execute.simd:6360 [D] s_b_3_1 = ReadRegBank 2:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_3_2 = ReadRegBank 3:s_b_3_0 (u64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:1172 [F] s_b_3_3=sym_10083_3_parameter_inst.rm (const) */
    /* execute.simd:6360 [D] s_b_3_4 = ReadRegBank 2:s_b_3_3 (u64) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_3_5 = ReadRegBank 3:s_b_3_3 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:1174 [F] s_b_3_6=sym_10083_3_parameter_inst.rd (const) */
    /* execute.simd:1174 [D] s_b_3_7 = s_b_3_1^s_b_3_4 */
    auto s_b_3_7 = emitter.bitwise_xor(s_b_3_1, s_b_3_4);
    /* execute.simd:1174 [D] s_b_3_8 = s_b_3_2^s_b_3_5 */
    auto s_b_3_8 = emitter.bitwise_xor(s_b_3_2, s_b_3_5);
    /* execute.simd:6333 [D] s_b_3_9: WriteRegBank 2:s_b_3_6 = s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7);
    /* execute.simd:6334 [D] s_b_3_10: WriteRegBank 3:s_b_3_6 = s_b_3_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_8,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_8);
    /* execute.simd:0 [F] s_b_3_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fabs(const arm64_decode_a64_FP_DP_1&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4766 [F] s_b_0_0=sym_10557_3_parameter_inst.type (const) */
    /* execute.simd:4766 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4766 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4766 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4766 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:4767 [F] s_b_1_0=sym_10557_3_parameter_inst.rd (const) */
    /* execute.simd:4767 [F] s_b_1_1=sym_10557_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_1_2 = ReadRegBank 9:s_b_1_1 (f32) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(4));
    }
    /* execute.simd:4767 [D] s_b_1_3 = float_abs */
    auto s_b_1_3 = emitter.call(__captive_float_abs, s_b_1_2);
    /* execute.simd:6290 [D] s_b_1_4: WriteRegBank 9:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3);
    /* execute.simd:6291 [F] s_b_1_5 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_1_6: WriteRegBank 10:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_1_8: WriteRegBank 3:s_b_1_0 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4769 [F] s_b_3_0=sym_10557_3_parameter_inst.rd (const) */
    /* execute.simd:4769 [F] s_b_3_1=sym_10557_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_3_2 = ReadRegBank 11:s_b_3_1 (f64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:4769 [D] s_b_3_3 = double_abs */
    auto s_b_3_3 = emitter.call(__captive_double_abs, s_b_3_2);
    /* execute.simd:6298 [D] s_b_3_4: WriteRegBank 11:s_b_3_0 = s_b_3_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3);
    /* execute.simd:6299 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_3_6: WriteRegBank 3:s_b_3_0 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_3_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fcvti(const arm64_decode_a64_CVT_FP_I&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_63086_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_62928_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_62951_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_62974_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63064_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_62996_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63018_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_63041_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4489 [F] s_b_0_0=sym_11053_3_parameter_inst.opcode (const) */
    /* execute.simd:4489 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4489 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4489 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)0ULL));
    /* execute.simd:4489 [F] s_b_0_4=sym_11053_3_parameter_inst.opcode (const) */
    /* execute.simd:4489 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.simd:4489 [F] s_b_0_6 = constant u32 4 (const) */
    /* execute.simd:4489 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9|s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 | s_b_0_10));
    /* execute.simd:4489 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
    if (s_b_0_11) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:4491 [F] s_b_1_0=sym_11053_3_parameter_inst.sf (const) */
    /* execute.simd:4491 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4491 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4491 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4491 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_6, b_7, b_8, b_9, b_11, b_14, b_15, b_16, b_17, b_18, b_19, b_20, b_21, b_22, b_23, b_24, b_25,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4508 [F] s_b_3_0=sym_11053_3_parameter_inst.opcode (const) */
    /* execute.simd:4508 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4508 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4508 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)1ULL));
    /* execute.simd:4508 [F] s_b_3_4=sym_11053_3_parameter_inst.opcode (const) */
    /* execute.simd:4508 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4508 [F] s_b_3_6 = constant u32 5 (const) */
    /* execute.simd:4508 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)5ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9|s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 | s_b_3_10));
    /* execute.simd:4508 [F] s_b_3_12: If s_b_3_11: Jump b_10 else b_11 (const) */
    if (s_b_3_11) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4492 [F] s_b_4_0=sym_11053_3_parameter_inst.type (const) */
    /* execute.simd:4492 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4492 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.simd:4492 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4492 [F] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4500 [F] s_b_5_0=sym_11053_3_parameter_inst.type (const) */
    /* execute.simd:4500 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4500 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.simd:4500 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4500 [F] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4494 [F] s_b_6_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.simd:4494 [F] s_b_6_1=sym_11053_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_6_2 = ReadRegBank 9:s_b_6_1 (f32) */
    auto s_b_6_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_2,emitter.const_u8(4));
    }
    /* execute.simd:4494 [F] s_b_6_3=sym_11053_3_parameter_inst.rmode (const) */
    /* execute.simd:4494 [D] s_b_6_4 = __builtin_fcvt_f32_s32 */
    auto s_b_6_4 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_6_2, emitter.const_u8(insn.rmode));
    /* execute.simd:4494 [D] s_b_6_5 = (u32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().u32());
    /* execute.simd:4494 [D] s_b_6_6: sym_62928_3_parameter_value = s_b_6_5, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_62928_3_parameter_value, s_b_6_5);
    /* execute.a64:2737 [F] s_b_6_7 = (u32)s_b_6_0 (const) */
    /* execute.a64:2737 [F] s_b_6_8 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_6_9 = s_b_6_7==s_b_6_8 (const) */
    uint8_t s_b_6_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_6_10: If s_b_6_9: Jump b_2 else b_18 (const) */
    if (s_b_6_9) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4497 [F] s_b_7_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.simd:4497 [F] s_b_7_1=sym_11053_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_7_2 = ReadRegBank 11:s_b_7_1 (f64) */
    auto s_b_7_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_2,emitter.const_u8(8));
    }
    /* execute.simd:4497 [F] s_b_7_3=sym_11053_3_parameter_inst.rmode (const) */
    /* execute.simd:4497 [D] s_b_7_4 = __builtin_fcvt_f64_s32 */
    auto s_b_7_4 = emitter.call(__captive___builtin_fcvt_f64_s32, s_b_7_2, emitter.const_u8(insn.rmode));
    /* execute.simd:4497 [D] s_b_7_5 = (u32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().u32());
    /* execute.simd:4497 [D] s_b_7_6: sym_62951_3_parameter_value = s_b_7_5, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_62951_3_parameter_value, s_b_7_5);
    /* execute.a64:2737 [F] s_b_7_7 = (u32)s_b_7_0 (const) */
    /* execute.a64:2737 [F] s_b_7_8 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_7_9 = s_b_7_7==s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_7_10: If s_b_7_9: Jump b_2 else b_19 (const) */
    if (s_b_7_9) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4502 [F] s_b_8_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.simd:4502 [F] s_b_8_1=sym_11053_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_8_2 = ReadRegBank 9:s_b_8_1 (f32) */
    auto s_b_8_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_2,emitter.const_u8(4));
    }
    /* execute.simd:4502 [F] s_b_8_3=sym_11053_3_parameter_inst.rmode (const) */
    /* execute.simd:4502 [D] s_b_8_4 = __builtin_fcvt_f32_s64 */
    auto s_b_8_4 = emitter.call(__captive___builtin_fcvt_f32_s64, s_b_8_2, emitter.const_u8(insn.rmode));
    /* execute.simd:4502 [D] s_b_8_5 = (u64)s_b_8_4 */
    auto s_b_8_5 = emitter.reinterpret(s_b_8_4, emitter.context().types().u64());
    /* execute.simd:4502 [D] s_b_8_6: sym_62974_3_parameter_value = s_b_8_5, dominates: s_b_20_1  */
    emitter.store_local(DV_sym_62974_3_parameter_value, s_b_8_5);
    /* execute.a64:2745 [F] s_b_8_7 = (u32)s_b_8_0 (const) */
    /* execute.a64:2745 [F] s_b_8_8 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_8_9 = s_b_8_7==s_b_8_8 (const) */
    uint8_t s_b_8_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_8_10: If s_b_8_9: Jump b_2 else b_20 (const) */
    if (s_b_8_9) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4505 [F] s_b_9_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.simd:4505 [F] s_b_9_1=sym_11053_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_9_2 = ReadRegBank 11:s_b_9_1 (f64) */
    auto s_b_9_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_2,emitter.const_u8(8));
    }
    /* execute.simd:4505 [F] s_b_9_3=sym_11053_3_parameter_inst.rmode (const) */
    /* execute.simd:4505 [D] s_b_9_4 = __builtin_fcvt_f64_s64 */
    auto s_b_9_4 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_9_2, emitter.const_u8(insn.rmode));
    /* execute.simd:4505 [D] s_b_9_5 = (u64)s_b_9_4 */
    auto s_b_9_5 = emitter.reinterpret(s_b_9_4, emitter.context().types().u64());
    /* execute.simd:4505 [D] s_b_9_6: sym_62996_3_parameter_value = s_b_9_5, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_62996_3_parameter_value, s_b_9_5);
    /* execute.a64:2745 [F] s_b_9_7 = (u32)s_b_9_0 (const) */
    /* execute.a64:2745 [F] s_b_9_8 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_9_9 = s_b_9_7==s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_9_10: If s_b_9_9: Jump b_2 else b_21 (const) */
    if (s_b_9_9) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4510 [F] s_b_10_0=sym_11053_3_parameter_inst.sf (const) */
    /* execute.simd:4510 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4510 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.simd:4510 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4510 [F] s_b_10_4: If s_b_10_3: Jump b_12 else b_13 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4528 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4528 [F] s_b_11_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_10,  */
  fixed_block_b_12: 
  {
    /* execute.simd:4511 [F] s_b_12_0=sym_11053_3_parameter_inst.type (const) */
    /* execute.simd:4511 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.simd:4511 [F] s_b_12_2 = constant u32 0 (const) */
    /* execute.simd:4511 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4511 [F] s_b_12_4: If s_b_12_3: Jump b_14 else b_15 (const) */
    if (s_b_12_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4519 [F] s_b_13_0=sym_11053_3_parameter_inst.type (const) */
    /* execute.simd:4519 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.simd:4519 [F] s_b_13_2 = constant u32 0 (const) */
    /* execute.simd:4519 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4519 [F] s_b_13_4: If s_b_13_3: Jump b_16 else b_17 (const) */
    if (s_b_13_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.simd:4513 [F] s_b_14_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.simd:4513 [F] s_b_14_1=sym_11053_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_14_2 = ReadRegBank 9:s_b_14_1 (f32) */
    auto s_b_14_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_2,emitter.const_u8(4));
    }
    /* execute.simd:4513 [F] s_b_14_3=sym_11053_3_parameter_inst.rmode (const) */
    /* execute.simd:4513 [D] s_b_14_4 = __builtin_fcvt_f32_u32 */
    auto s_b_14_4 = emitter.call(__captive___builtin_fcvt_f32_u32, s_b_14_2, emitter.const_u8(insn.rmode));
    /* execute.simd:4513 [D] s_b_14_5: sym_63018_3_parameter_value = s_b_14_4, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_63018_3_parameter_value, s_b_14_4);
    /* execute.a64:2737 [F] s_b_14_6 = (u32)s_b_14_0 (const) */
    /* execute.a64:2737 [F] s_b_14_7 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_14_8 = s_b_14_6==s_b_14_7 (const) */
    uint8_t s_b_14_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_14_9: If s_b_14_8: Jump b_2 else b_22 (const) */
    if (s_b_14_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_12,  */
  fixed_block_b_15: 
  {
    /* execute.simd:4516 [F] s_b_15_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.simd:4516 [F] s_b_15_1=sym_11053_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_15_2 = ReadRegBank 11:s_b_15_1 (f64) */
    auto s_b_15_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_15_2,emitter.const_u8(8));
    }
    /* execute.simd:4516 [F] s_b_15_3=sym_11053_3_parameter_inst.rmode (const) */
    /* execute.simd:4516 [D] s_b_15_4 = __builtin_fcvt_f64_u32 */
    auto s_b_15_4 = emitter.call(__captive___builtin_fcvt_f64_u32, s_b_15_2, emitter.const_u8(insn.rmode));
    /* execute.simd:4516 [D] s_b_15_5: sym_63041_3_parameter_value = s_b_15_4, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_63041_3_parameter_value, s_b_15_4);
    /* execute.a64:2737 [F] s_b_15_6 = (u32)s_b_15_0 (const) */
    /* execute.a64:2737 [F] s_b_15_7 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_15_8 = s_b_15_6==s_b_15_7 (const) */
    uint8_t s_b_15_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_15_9: If s_b_15_8: Jump b_2 else b_23 (const) */
    if (s_b_15_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_13,  */
  fixed_block_b_16: 
  {
    /* execute.simd:4521 [F] s_b_16_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.simd:4521 [F] s_b_16_1=sym_11053_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_16_2 = ReadRegBank 9:s_b_16_1 (f32) */
    auto s_b_16_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_16_2,emitter.const_u8(4));
    }
    /* execute.simd:4521 [F] s_b_16_3=sym_11053_3_parameter_inst.rmode (const) */
    /* execute.simd:4521 [D] s_b_16_4 = __builtin_fcvt_f32_u64 */
    auto s_b_16_4 = emitter.call(__captive___builtin_fcvt_f32_u64, s_b_16_2, emitter.const_u8(insn.rmode));
    /* execute.simd:4521 [D] s_b_16_5: sym_63064_3_parameter_value = s_b_16_4, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_63064_3_parameter_value, s_b_16_4);
    /* execute.a64:2745 [F] s_b_16_6 = (u32)s_b_16_0 (const) */
    /* execute.a64:2745 [F] s_b_16_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_16_8 = s_b_16_6==s_b_16_7 (const) */
    uint8_t s_b_16_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_16_9: If s_b_16_8: Jump b_2 else b_24 (const) */
    if (s_b_16_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_13,  */
  fixed_block_b_17: 
  {
    /* execute.simd:4524 [F] s_b_17_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.simd:4524 [F] s_b_17_1=sym_11053_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_17_2 = ReadRegBank 11:s_b_17_1 (f64) */
    auto s_b_17_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_2,emitter.const_u8(8));
    }
    /* execute.simd:4524 [F] s_b_17_3=sym_11053_3_parameter_inst.rmode (const) */
    /* execute.simd:4524 [D] s_b_17_4 = __builtin_fcvt_f64_u64 */
    auto s_b_17_4 = emitter.call(__captive___builtin_fcvt_f64_u64, s_b_17_2, emitter.const_u8(insn.rmode));
    /* execute.simd:4524 [D] s_b_17_5: sym_63086_3_parameter_value = s_b_17_4, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_63086_3_parameter_value, s_b_17_4);
    /* execute.a64:2745 [F] s_b_17_6 = (u32)s_b_17_0 (const) */
    /* execute.a64:2745 [F] s_b_17_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_17_8 = s_b_17_6==s_b_17_7 (const) */
    uint8_t s_b_17_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_17_9: If s_b_17_8: Jump b_2 else b_25 (const) */
    if (s_b_17_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_6,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2739 [F] s_b_18_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_18_1 = sym_62928_3_parameter_value uint32_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_62928_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_18_2 = (u64)s_b_18_1 */
    auto s_b_18_2 = emitter.zx(s_b_18_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_18_3: WriteRegBank 0:s_b_18_0 = s_b_18_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_18_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_18_2);
    /* execute.a64:0 [F] s_b_18_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2739 [F] s_b_19_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_19_1 = sym_62951_3_parameter_value uint32_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_62951_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_19_2 = (u64)s_b_19_1 */
    auto s_b_19_2 = emitter.zx(s_b_19_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_19_3: WriteRegBank 0:s_b_19_0 = s_b_19_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_19_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_19_2);
    /* execute.a64:0 [F] s_b_19_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2747 [F] s_b_20_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_20_1 = sym_62974_3_parameter_value uint64_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_62974_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_20_2: WriteRegBank 0:s_b_20_0 = s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_1);
    /* execute.a64:0 [F] s_b_20_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2747 [F] s_b_21_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_21_1 = sym_62996_3_parameter_value uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_62996_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_21_2: WriteRegBank 0:s_b_21_0 = s_b_21_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_21_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_21_1);
    /* execute.a64:0 [F] s_b_21_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_14,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2739 [F] s_b_22_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_22_1 = sym_63018_3_parameter_value uint32_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_63018_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_22_2 = (u64)s_b_22_1 */
    auto s_b_22_2 = emitter.zx(s_b_22_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_22_3: WriteRegBank 0:s_b_22_0 = s_b_22_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_22_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_22_2);
    /* execute.a64:0 [F] s_b_22_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2739 [F] s_b_23_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_23_1 = sym_63041_3_parameter_value uint32_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_63041_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_23_2 = (u64)s_b_23_1 */
    auto s_b_23_2 = emitter.zx(s_b_23_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_23_3: WriteRegBank 0:s_b_23_0 = s_b_23_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_2);
    /* execute.a64:0 [F] s_b_23_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_16,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2747 [F] s_b_24_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_24_1 = sym_63064_3_parameter_value uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_63064_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_24_2: WriteRegBank 0:s_b_24_0 = s_b_24_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_24_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_24_1);
    /* execute.a64:0 [F] s_b_24_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_17,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2747 [F] s_b_25_0=sym_11053_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_25_1 = sym_63086_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_63086_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1);
    /* execute.a64:0 [F] s_b_25_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fminnmv(const arm64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:3097 [D] s_b_0_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* ???:4294967295 [F] s_b_0_1: Return */
    goto fixed_done;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fneg(const arm64_decode_a64_FP_DP_1&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4116 [F] s_b_0_0=sym_12426_3_parameter_inst.type (const) */
    /* execute.simd:4116 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4116 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4116 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4116 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:4117 [F] s_b_1_0=sym_12426_3_parameter_inst.rd (const) */
    /* execute.simd:4117 [F] s_b_1_1=sym_12426_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_1_2 = ReadRegBank 9:s_b_1_1 (f32) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(4));
    }
    /* execute.simd:4117 [D] s_b_1_3 = -s_b_1_2 */
    auto s_b_1_3 = emitter.neg(s_b_1_2);
    /* execute.simd:6290 [D] s_b_1_4: WriteRegBank 9:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3);
    /* execute.simd:6291 [F] s_b_1_5 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_1_6: WriteRegBank 10:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_1_8: WriteRegBank 3:s_b_1_0 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4119 [F] s_b_3_0=sym_12426_3_parameter_inst.rd (const) */
    /* execute.simd:4119 [F] s_b_3_1=sym_12426_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_3_2 = ReadRegBank 11:s_b_3_1 (f64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:4119 [D] s_b_3_3 = -s_b_3_2 */
    auto s_b_3_3 = emitter.neg(s_b_3_2);
    /* execute.simd:6298 [D] s_b_3_4: WriteRegBank 11:s_b_3_0 = s_b_3_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3);
    /* execute.simd:6299 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_3_6: WriteRegBank 3:s_b_3_0 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_3_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ins_elem(const arm64_decode_a64_SIMD_COPY&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:589 [F] s_b_0_0=sym_12847_3_parameter_inst.size (const) */
    /* execute.simd:590 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:599 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:608 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:617 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:589 [F] s_b_0_5: Switch s_b_0_0: < <todo> > def b_6 (const) -> b_6, b_5, b_4, b_3, b_2,  */
    switch (insn.size) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    default:
      goto fixed_block_b_6;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:591 [F] s_b_2_0=sym_12847_3_parameter_inst.rn (const) */
    /* execute.simd:591 [D] s_b_2_1 = ReadRegBank 16:s_b_2_0 (v16u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(16));
    }
    /* execute.simd:592 [F] s_b_2_2=sym_12847_3_parameter_inst.rd (const) */
    /* execute.simd:592 [D] s_b_2_3 = ReadRegBank 16:s_b_2_2 (v16u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_3,emitter.const_u8(16));
    }
    /* execute.simd:594 [F] s_b_2_4=sym_12847_3_parameter_inst.eindex2 (const) */
    /* execute.simd:594 [D] s_b_2_1[s_b_2_4] */
    auto s_b_2_5 = emitter.vector_extract(s_b_2_1, emitter.const_u8(insn.eindex2));
    /* execute.simd:594 [F] s_b_2_6=sym_12847_3_parameter_inst.eindex (const) */
    /* execute.simd:594 [F] s_b_2_7 = (s32)s_b_2_6 (const) */
    /* execute.simd:594 [D] s_b_2_8 = s_b_2_3[s_b_2_7] <= s_b_2_5 */
    auto s_b_2_8 = emitter.vector_insert(s_b_2_3, emitter.const_s32(((int32_t)insn.eindex)), s_b_2_5);
    /* execute.simd:596 [F] s_b_2_9=sym_12847_3_parameter_inst.rd (const) */
    /* execute.simd:596 [D] s_b_2_10: WriteRegBank 16:s_b_2_9 = s_b_2_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_8,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_8);
    /* execute.simd:0 [F] s_b_2_11: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:600 [F] s_b_3_0=sym_12847_3_parameter_inst.rn (const) */
    /* execute.simd:600 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:601 [F] s_b_3_2=sym_12847_3_parameter_inst.rd (const) */
    /* execute.simd:601 [D] s_b_3_3 = ReadRegBank 18:s_b_3_2 (v8u16) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:603 [F] s_b_3_4=sym_12847_3_parameter_inst.eindex2 (const) */
    /* execute.simd:603 [D] s_b_3_1[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_1, emitter.const_u8(insn.eindex2));
    /* execute.simd:603 [F] s_b_3_6=sym_12847_3_parameter_inst.eindex (const) */
    /* execute.simd:603 [F] s_b_3_7 = (s32)s_b_3_6 (const) */
    /* execute.simd:603 [D] s_b_3_8 = s_b_3_3[s_b_3_7] <= s_b_3_5 */
    auto s_b_3_8 = emitter.vector_insert(s_b_3_3, emitter.const_s32(((int32_t)insn.eindex)), s_b_3_5);
    /* execute.simd:605 [F] s_b_3_9=sym_12847_3_parameter_inst.rd (const) */
    /* execute.simd:605 [D] s_b_3_10: WriteRegBank 18:s_b_3_9 = s_b_3_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_8,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_8);
    /* execute.simd:0 [F] s_b_3_11: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:609 [F] s_b_4_0=sym_12847_3_parameter_inst.rn (const) */
    /* execute.simd:609 [D] s_b_4_1 = ReadRegBank 20:s_b_4_0 (v4u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:610 [F] s_b_4_2=sym_12847_3_parameter_inst.rd (const) */
    /* execute.simd:610 [D] s_b_4_3 = ReadRegBank 20:s_b_4_2 (v4u32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_3,emitter.const_u8(16));
    }
    /* execute.simd:612 [F] s_b_4_4=sym_12847_3_parameter_inst.eindex2 (const) */
    /* execute.simd:612 [D] s_b_4_1[s_b_4_4] */
    auto s_b_4_5 = emitter.vector_extract(s_b_4_1, emitter.const_u8(insn.eindex2));
    /* execute.simd:612 [F] s_b_4_6=sym_12847_3_parameter_inst.eindex (const) */
    /* execute.simd:612 [F] s_b_4_7 = (s32)s_b_4_6 (const) */
    /* execute.simd:612 [D] s_b_4_8 = s_b_4_3[s_b_4_7] <= s_b_4_5 */
    auto s_b_4_8 = emitter.vector_insert(s_b_4_3, emitter.const_s32(((int32_t)insn.eindex)), s_b_4_5);
    /* execute.simd:614 [F] s_b_4_9=sym_12847_3_parameter_inst.rd (const) */
    /* execute.simd:614 [D] s_b_4_10: WriteRegBank 20:s_b_4_9 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_8,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_8);
    /* execute.simd:0 [F] s_b_4_11: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:618 [F] s_b_5_0=sym_12847_3_parameter_inst.rn (const) */
    /* execute.simd:618 [D] s_b_5_1 = ReadRegBank 21:s_b_5_0 (v2u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:619 [F] s_b_5_2=sym_12847_3_parameter_inst.rd (const) */
    /* execute.simd:619 [D] s_b_5_3 = ReadRegBank 21:s_b_5_2 (v2u64) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:621 [F] s_b_5_4=sym_12847_3_parameter_inst.eindex2 (const) */
    /* execute.simd:621 [D] s_b_5_1[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_1, emitter.const_u8(insn.eindex2));
    /* execute.simd:621 [F] s_b_5_6=sym_12847_3_parameter_inst.eindex (const) */
    /* execute.simd:621 [F] s_b_5_7 = (s32)s_b_5_6 (const) */
    /* execute.simd:621 [D] s_b_5_8 = s_b_5_3[s_b_5_7] <= s_b_5_5 */
    auto s_b_5_8 = emitter.vector_insert(s_b_5_3, emitter.const_s32(((int32_t)insn.eindex)), s_b_5_5);
    /* execute.simd:623 [F] s_b_5_9=sym_12847_3_parameter_inst.rd (const) */
    /* execute.simd:623 [D] s_b_5_10: WriteRegBank 21:s_b_5_9 = s_b_5_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_8,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_8);
    /* execute.simd:0 [F] s_b_5_11: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:627 [D] s_b_6_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_6_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ld3(const arm64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_68436_1_tmp_s_b_5_2;
  auto DV_sym_68411_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_68272_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_68394_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_68305_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_68377_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_68309_3_parameter_rt;
  auto DV_sym_68468_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_68360_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_68307_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_68343_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  uint8_t CV_sym_13717_0_rt;
  uint8_t CV_sym_13705_0_lane;
  auto DV_sym_13671_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_68326_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_68439_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_68315_3_parameter_lane;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_13665_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_18 else b_7 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_6, b_8,  */
  fixed_block_b_1: 
  {
    /* execute.simd:2499 [F] s_b_1_0 = sym_13705_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13705_0_lane;
    /* execute.simd:2499 [F] s_b_1_1=sym_13665_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2499 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2499 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
    if (s_b_1_2) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_1,  */
  fixed_block_b_2: 
  {
    /* execute.simd:2500 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2500 [F] s_b_2_1: sym_13717_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13717_0_rt = (uint8_t)0ULL;
    /* execute.simd:2500 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [F] s_b_3_0: Return */
    goto fixed_done;
  }
  /* b_2, b_17,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2500 [F] s_b_4_0 = sym_13717_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13717_0_rt;
    /* execute.simd:2500 [F] s_b_4_1=sym_13665_3_parameter_inst.regcnt (const) */
    /* execute.simd:2500 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2500 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
    if (s_b_4_2) 
    {
      goto fixed_block_b_5;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_4,  */
  fixed_block_b_5: 
  {
    /* execute.simd:2501 [F] s_b_5_0=sym_13665_3_parameter_inst.arrangement (const) */
    /* execute.simd:2501 [F] s_b_5_1=sym_13665_3_parameter_inst.rt (const) */
    /* execute.simd:2501 [F] s_b_5_2 = sym_13717_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13717_0_rt;
    /* execute.simd:2501 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2501 [F] s_b_5_4 = sym_13705_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13705_0_lane;
    /* execute.simd:2501 [D] s_b_5_5 = sym_13671_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13671_0_address, emitter.context().types().u64());
    /* execute.simd:2501 [F] s_b_5_6: sym_68309_3_parameter_rt = s_b_5_3 (const), dominates: s_b_10_2 s_b_11_2 s_b_16_2 s_b_15_2 s_b_14_2 s_b_13_2 s_b_12_2  */
    CV_sym_68309_3_parameter_rt = s_b_5_3;
    /* execute.simd:2501 [F] s_b_5_7: sym_68315_3_parameter_lane = s_b_5_4 (const), dominates: s_b_10_5 s_b_11_5 s_b_16_5 s_b_15_5 s_b_14_5 s_b_13_5 s_b_12_5  */
    CV_sym_68315_3_parameter_lane = s_b_5_4;
    /* execute.simd:2501 [D] s_b_5_8: sym_68305_3_parameter_addr = s_b_5_5, dominates: s_b_10_0 s_b_11_0 s_b_16_0 s_b_15_0 s_b_14_0 s_b_13_0 s_b_12_0  */
    emitter.store_local(DV_sym_68305_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_68436_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_17_1  */
    CV_sym_68436_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_68439_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_68439_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3857 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3866 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3875 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3884 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3893 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3902 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3911 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3856 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_9 (const) -> b_9, b_10, b_11, b_16, b_15, b_14, b_13, b_12,  */
    switch (insn.arrangement) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_13;
      break;
    default:
      goto fixed_block_b_9;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2499 [F] s_b_6_0 = sym_13705_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13705_0_lane;
    /* execute.simd:2499 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2499 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2499 [F] s_b_6_3: sym_13705_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13705_0_lane = s_b_6_2;
    /* execute.simd:2499 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2796 [F] s_b_7_0=sym_13665_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_7_1 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_7_2: sym_68272_1__R_s_b_0_5 = s_b_7_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_68272_1__R_s_b_0_5, s_b_7_1);
    /* execute.a64:2796 [F] s_b_7_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_22,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2493 [D] s_b_8_0 = sym_68272_1__R_s_b_0_5 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_68272_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2493 [D] s_b_8_1: sym_13671_0_address = s_b_8_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13671_0_address, s_b_8_0);
    /* execute.simd:2495 [F] s_b_8_2=sym_13665_3_parameter_inst.rt (const) */
    /* execute.simd:2495 [F] s_b_8_3 = constant u64 0 (const) */
    /* execute.simd:2495 [F] s_b_8_4 = constant u64 0 (const) */
    /* execute.simd:6333 [F] s_b_8_5: WriteRegBank 2:s_b_8_2 = s_b_8_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6334 [F] s_b_8_6: WriteRegBank 3:s_b_8_2 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2496 [F] s_b_8_7=sym_13665_3_parameter_inst.rt (const) */
    /* execute.simd:2496 [F] s_b_8_8 = (u32)s_b_8_7 (const) */
    /* execute.simd:2496 [F] s_b_8_9 = constant u32 1 (const) */
    /* execute.simd:2496 [F] s_b_8_10 = s_b_8_8+s_b_8_9 (const) */
    uint32_t s_b_8_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2496 [F] s_b_8_11 = (u8)s_b_8_10 (const) */
    /* execute.simd:2496 [F] s_b_8_12 = constant u64 0 (const) */
    /* execute.simd:2496 [F] s_b_8_13 = constant u64 0 (const) */
    /* execute.simd:6333 [F] s_b_8_14: WriteRegBank 2:s_b_8_11 = s_b_8_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6334 [F] s_b_8_15: WriteRegBank 3:s_b_8_11 = s_b_8_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2497 [F] s_b_8_16=sym_13665_3_parameter_inst.rt (const) */
    /* execute.simd:2497 [F] s_b_8_17 = (u32)s_b_8_16 (const) */
    /* execute.simd:2497 [F] s_b_8_18 = constant u32 2 (const) */
    /* execute.simd:2497 [F] s_b_8_19 = s_b_8_17+s_b_8_18 (const) */
    uint32_t s_b_8_19 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)2ULL));
    /* execute.simd:2497 [F] s_b_8_20 = (u8)s_b_8_19 (const) */
    /* execute.simd:2497 [F] s_b_8_21 = constant u64 0 (const) */
    /* execute.simd:2497 [F] s_b_8_22 = constant u64 0 (const) */
    /* execute.simd:6333 [F] s_b_8_23: WriteRegBank 2:s_b_8_20 = s_b_8_21 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6334 [F] s_b_8_24: WriteRegBank 3:s_b_8_20 = s_b_8_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2499 [F] s_b_8_25 = constant u8 0 (const) */
    /* execute.simd:2499 [F] s_b_8_26: sym_13705_0_lane = s_b_8_25 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13705_0_lane = (uint8_t)0ULL;
    /* execute.simd:2499 [F] s_b_8_27: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3921 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3859 [D] s_b_10_0 = sym_68305_3_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_68305_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 1 s_b_10_0 => sym_68307_0_mem_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_68307_0_mem_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(1));
    }
    /* execute.simd:3861 [F] s_b_10_2 = sym_68309_3_parameter_rt (const) uint8_t */
    uint8_t s_b_10_2 = CV_sym_68309_3_parameter_rt;
    /* execute.simd:3861 [D] s_b_10_3 = ReadRegBank 15:s_b_10_2 (v8u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:3862 [D] s_b_10_4 = sym_68307_0_mem_value uint8_t */
    auto s_b_10_4 = emitter.load_local(DV_sym_68307_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3862 [F] s_b_10_5 = sym_68315_3_parameter_lane (const) uint8_t */
    uint8_t s_b_10_5 = CV_sym_68315_3_parameter_lane;
    /* execute.simd:3862 [F] s_b_10_6 = (s32)s_b_10_5 (const) */
    /* execute.simd:3862 [D] s_b_10_7 = s_b_10_3[s_b_10_6] <= s_b_10_4 */
    auto s_b_10_7 = emitter.vector_insert(s_b_10_3, emitter.const_s32(((int32_t)s_b_10_5)), s_b_10_4);
    /* execute.simd:3863 [D] s_b_10_8: WriteRegBank 15:s_b_10_2 = s_b_10_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_7);
    /* execute.simd:0 [F] s_b_10_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3868 [D] s_b_11_0 = sym_68305_3_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_68305_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 1 s_b_11_0 => sym_68326_0_mem_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_68326_0_mem_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(1));
    }
    /* execute.simd:3870 [F] s_b_11_2 = sym_68309_3_parameter_rt (const) uint8_t */
    uint8_t s_b_11_2 = CV_sym_68309_3_parameter_rt;
    /* execute.simd:3870 [D] s_b_11_3 = ReadRegBank 16:s_b_11_2 (v16u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:3871 [D] s_b_11_4 = sym_68326_0_mem_value uint8_t */
    auto s_b_11_4 = emitter.load_local(DV_sym_68326_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3871 [F] s_b_11_5 = sym_68315_3_parameter_lane (const) uint8_t */
    uint8_t s_b_11_5 = CV_sym_68315_3_parameter_lane;
    /* execute.simd:3871 [F] s_b_11_6 = (s32)s_b_11_5 (const) */
    /* execute.simd:3871 [D] s_b_11_7 = s_b_11_3[s_b_11_6] <= s_b_11_4 */
    auto s_b_11_7 = emitter.vector_insert(s_b_11_3, emitter.const_s32(((int32_t)s_b_11_5)), s_b_11_4);
    /* execute.simd:3872 [D] s_b_11_8: WriteRegBank 16:s_b_11_2 = s_b_11_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_7);
    /* execute.simd:0 [F] s_b_11_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3877 [D] s_b_12_0 = sym_68305_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_68305_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_68343_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_68343_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3879 [F] s_b_12_2 = sym_68309_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_68309_3_parameter_rt;
    /* execute.simd:3879 [D] s_b_12_3 = ReadRegBank 17:s_b_12_2 (v4u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3880 [D] s_b_12_4 = sym_68343_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_68343_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3880 [F] s_b_12_5 = sym_68315_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_68315_3_parameter_lane;
    /* execute.simd:3880 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3880 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3881 [D] s_b_12_8: WriteRegBank 17:s_b_12_2 = s_b_12_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7);
    /* execute.simd:0 [F] s_b_12_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3886 [D] s_b_13_0 = sym_68305_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_68305_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 2 s_b_13_0 => sym_68360_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_68360_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(2));
    }
    /* execute.simd:3888 [F] s_b_13_2 = sym_68309_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_68309_3_parameter_rt;
    /* execute.simd:3888 [D] s_b_13_3 = ReadRegBank 18:s_b_13_2 (v8u16) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3889 [D] s_b_13_4 = sym_68360_0_mem_value uint16_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_68360_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3889 [F] s_b_13_5 = sym_68315_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_68315_3_parameter_lane;
    /* execute.simd:3889 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3889 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3890 [D] s_b_13_8: WriteRegBank 18:s_b_13_2 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7);
    /* execute.simd:0 [F] s_b_13_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_14: 
  {
    /* execute.simd:3895 [D] s_b_14_0 = sym_68305_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_68305_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_68377_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_68377_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.simd:3897 [F] s_b_14_2 = sym_68309_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_68309_3_parameter_rt;
    /* execute.simd:3897 [D] s_b_14_3 = ReadRegBank 19:s_b_14_2 (v2u32) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3898 [D] s_b_14_4 = sym_68377_0_mem_value uint32_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_68377_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3898 [F] s_b_14_5 = sym_68315_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_68315_3_parameter_lane;
    /* execute.simd:3898 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3898 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3899 [D] s_b_14_8: WriteRegBank 19:s_b_14_2 = s_b_14_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7);
    /* execute.simd:0 [F] s_b_14_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3904 [D] s_b_15_0 = sym_68305_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_68305_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 4 s_b_15_0 => sym_68394_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_68394_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(4));
    }
    /* execute.simd:3906 [F] s_b_15_2 = sym_68309_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_68309_3_parameter_rt;
    /* execute.simd:3906 [D] s_b_15_3 = ReadRegBank 20:s_b_15_2 (v4u32) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3907 [D] s_b_15_4 = sym_68394_0_mem_value uint32_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_68394_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3907 [F] s_b_15_5 = sym_68315_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_68315_3_parameter_lane;
    /* execute.simd:3907 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3907 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3908 [D] s_b_15_8: WriteRegBank 20:s_b_15_2 = s_b_15_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7);
    /* execute.simd:0 [F] s_b_15_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3913 [D] s_b_16_0 = sym_68305_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_68305_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_68411_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_68411_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.simd:3915 [F] s_b_16_2 = sym_68309_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_68309_3_parameter_rt;
    /* execute.simd:3915 [D] s_b_16_3 = ReadRegBank 21:s_b_16_2 (v2u64) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3916 [D] s_b_16_4 = sym_68411_0_mem_value uint64_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_68411_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3916 [F] s_b_16_5 = sym_68315_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_68315_3_parameter_lane;
    /* execute.simd:3916 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3916 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3917 [D] s_b_16_8: WriteRegBank 21:s_b_16_2 = s_b_16_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7);
    /* execute.simd:0 [F] s_b_16_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_9, b_10, b_11, b_12, b_13, b_14, b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* ???:4294967295 [D] s_b_17_0 = sym_68439_1_tmp_s_b_5_5 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_68439_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1 = sym_68436_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_17_1 = CV_sym_68436_1_tmp_s_b_5_2;
    /* execute.simd:2502 [F] s_b_17_2=sym_13665_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* ???:4294967295 [D] s_b_17_4 = s_b_17_0+s_b_17_3 */
    auto s_b_17_4 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2502 [D] s_b_17_5: sym_13671_0_address = s_b_17_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13671_0_address, s_b_17_4);
    /* execute.simd:2500 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:2500 [F] s_b_17_7 = s_b_17_1+s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(s_b_17_1 + (uint8_t)1ULL));
    /* execute.simd:2500 [F] s_b_17_8: sym_13717_0_rt = s_b_17_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13717_0_rt = s_b_17_7;
    /* execute.simd:2500 [F] s_b_17_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2764 [F] s_b_18_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_18_1 = __builtin_get_feature */
    uint32_t s_b_18_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_18_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(s_b_18_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_18_4: If s_b_18_3: Jump b_19 else b_23 (const) */
    if (s_b_18_3) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_18,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2765 [D] s_b_19_0 = ReadReg 21 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_19_1: sym_68468_1__R_s_b_10_0 = s_b_19_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_68468_1__R_s_b_10_0, s_b_19_0);
    /* execute.a64:2765 [F] s_b_19_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_23,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2768 [D] s_b_20_0 = ReadReg 21 (u64) */
    auto s_b_20_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_20_1: sym_68468_1__R_s_b_10_0 = s_b_20_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_68468_1__R_s_b_10_0, s_b_20_0);
    /* execute.a64:2768 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_23,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2770 [D] s_b_21_0 = ReadReg 22 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_21_1: sym_68468_1__R_s_b_10_0 = s_b_21_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_68468_1__R_s_b_10_0, s_b_21_0);
    /* execute.a64:2770 [F] s_b_21_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19, b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2794 [D] s_b_22_0 = sym_68468_1__R_s_b_10_0 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_68468_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_22_1: sym_68272_1__R_s_b_0_5 = s_b_22_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_68272_1__R_s_b_0_5, s_b_22_0);
    /* execute.a64:2794 [F] s_b_22_2: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_18,  */
  fixed_block_b_23: 
  {
    /* execute.a64:3075 [F] s_b_23_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_23_1 = __builtin_get_feature */
    uint32_t s_b_23_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_23_2 = (u8)s_b_23_1 (const) */
    /* execute.a64:2767 [F] s_b_23_3 = (u32)s_b_23_2 (const) */
    /* execute.a64:2767 [F] s_b_23_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_23_5 = s_b_23_3==s_b_23_4 (const) */
    uint8_t s_b_23_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_23_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_23_6: If s_b_23_5: Jump b_20 else b_21 (const) */
    if (s_b_23_5) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldaxr(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14229_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_79925_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_79705_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_79734_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_80053_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_79837_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_80125_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_81169_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_81191_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14223_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_4 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_5,  */
  fixed_block_b_1: 
  {
    /* execute.a64:870 [D] s_b_1_0 = sym_14229_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14229_0_address, emitter.context().types().u64());
    /* execute.a64:870 [D] s_b_1_1: sym_79734_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_79734_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2 = Load 4 s_b_1_0 => sym_79837_0_data32 */
    auto s_b_1_2 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_79837_0_data32, s_b_1_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_2, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_1_3 = sym_79837_0_data32 uint32_t */
    auto s_b_1_3 = emitter.load_local(DV_sym_79837_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_5=sym_14223_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_6 = (u32)s_b_1_4 */
    auto s_b_1_6 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_8: sym_81169_3_parameter_value = s_b_1_7, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_81169_3_parameter_value, s_b_1_7);
    /* execute.a64:2745 [F] s_b_1_9 = (u32)s_b_1_5 (const) */
    /* execute.a64:2745 [F] s_b_1_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_1_11 = s_b_1_9==s_b_1_10 (const) */
    uint8_t s_b_1_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_1_12: If s_b_1_11: Jump b_6 else b_14 (const) */
    if (s_b_1_11) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_6, b_7,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_5,  */
  fixed_block_b_3: 
  {
    /* execute.a64:872 [D] s_b_3_0 = sym_14229_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14229_0_address, emitter.context().types().u64());
    /* execute.a64:872 [D] s_b_3_1: sym_79925_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_79925_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2 = Load 8 s_b_3_0 => sym_80053_0_data64 */
    auto s_b_3_2 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_80053_0_data64, s_b_3_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_3_3 = sym_80053_0_data64 uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_80053_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_3_4=sym_14223_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_3_5: sym_81191_3_parameter_value = s_b_3_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_81191_3_parameter_value, s_b_3_3);
    /* execute.a64:2745 [F] s_b_3_6 = (u32)s_b_3_4 (const) */
    /* execute.a64:2745 [F] s_b_3_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_3_8 = s_b_3_6==s_b_3_7 (const) */
    uint8_t s_b_3_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_3_9: If s_b_3_8: Jump b_7 else b_15 (const) */
    if (s_b_3_8) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2796 [F] s_b_4_0=sym_14223_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_4_2: sym_79705_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_79705_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2796 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:867 [D] s_b_5_0 = sym_79705_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_79705_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:867 [D] s_b_5_1: sym_14229_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14229_0_address, s_b_5_0);
    /* execute.a64:869 [F] s_b_5_2=sym_14223_3_parameter_inst.size (const) */
    /* execute.a64:869 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:869 [F] s_b_5_4 = constant u32 2 (const) */
    /* execute.a64:869 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:869 [F] s_b_5_6: If s_b_5_5: Jump b_1 else b_3 (const) */
    if (s_b_5_5) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_1, b_14,  */
  fixed_block_b_6: 
  {
    /* execute.a64:1786 [F] s_b_6_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_6_1 = sym_79734_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_79734_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* execute.a64:0 [F] s_b_6_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3, b_15,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1786 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_7_1 = sym_79925_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_79925_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* execute.a64:0 [F] s_b_7_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2764 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_8_4: If s_b_8_3: Jump b_9 else b_13 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2765 [D] s_b_9_0 = ReadReg 21 (u64) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_9_1: sym_80125_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_80125_1__R_s_b_7_0, s_b_9_0);
    /* execute.a64:2765 [F] s_b_9_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2768 [D] s_b_10_0 = ReadReg 21 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_10_1: sym_80125_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_80125_1__R_s_b_7_0, s_b_10_0);
    /* execute.a64:2768 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2770 [D] s_b_11_0 = ReadReg 22 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_11_1: sym_80125_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_80125_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2794 [D] s_b_12_0 = sym_80125_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_80125_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_12_1: sym_79705_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_79705_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2794 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_8,  */
  fixed_block_b_13: 
  {
    /* execute.a64:3075 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_13_2 = (u8)s_b_13_1 (const) */
    /* execute.a64:2767 [F] s_b_13_3 = (u32)s_b_13_2 (const) */
    /* execute.a64:2767 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
    uint8_t s_b_13_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_13_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_13_6: If s_b_13_5: Jump b_10 else b_11 (const) */
    if (s_b_13_5) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_1,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2747 [F] s_b_14_0=sym_14223_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_14_1 = sym_81169_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_81169_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2747 [F] s_b_15_0=sym_14223_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_15_1 = sym_81191_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_81191_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_15_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_15_1);
    /* execute.a64:0 [F] s_b_15_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldpsw(const arm64_decode_a64_LS_REG_PAIR_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14660_0_data1 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_14666_0_data2 = emitter.alloc_local(emitter.context().types().u32(), false);
  int64_t CV_sym_91122_1_tmp_s_b_10_5;
  auto DV_sym_91110_1__R_s_b_10_11 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91327_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91151_1__R_s_b_14_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91257_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1606 [F] s_b_0_0=sym_14620_3_parameter_inst.opc (const) */
    /* execute.a64:1606 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1606 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.a64:1606 [F] s_b_0_3 = s_b_0_1>>s_b_0_2 (const) */
    uint32_t s_b_0_3 = ((uint32_t)(((uint32_t)insn.opc) >> (uint32_t)1ULL));
    /* execute.a64:1606 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:1606 [F] s_b_0_5 = s_b_0_3&s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(s_b_0_3 & (uint32_t)1ULL));
    /* execute.a64:1606 [F] s_b_0_6 = constant u32 2 (const) */
    /* execute.a64:1606 [F] s_b_0_7 = s_b_0_6+s_b_0_5 (const) */
    uint32_t s_b_0_7 = ((uint32_t)((uint32_t)2ULL + s_b_0_5));
    /* execute.a64:1606 [F] s_b_0_8 = (u8)s_b_0_7 (const) */
    /* execute.a64:1607 [F] s_b_0_9=sym_14620_3_parameter_inst.imm7 (const) */
    /* execute.a64:1607 [F] s_b_0_10 = (u64)s_b_0_9 (const) */
    /* execute.a64:2848 [F] s_b_0_11 = (s64)s_b_0_10 (const) */
    /* execute.a64:2848 [F] s_b_0_12 = constant s64 39 (const) */
    /* execute.a64:2848 [F] s_b_0_13 = s_b_0_11<<s_b_0_12 (const) */
    int64_t s_b_0_13 = ((int64_t)(((int64_t)((uint64_t)insn.imm7)) << (int64_t)57ULL));
    /* execute.a64:2848 [F] s_b_0_14 = (s64)s_b_0_13 (const) */
    /* execute.a64:2848 [F] s_b_0_15 = constant s64 39 (const) */
    /* execute.a64:2848 [F] s_b_0_16 = s_b_0_14->>s_b_0_15 (const) */
    int64_t s_b_0_16 = ((int64_t)(((int64_t)s_b_0_13) >> (int64_t)57ULL));
    /* execute.a64:1607 [F] s_b_0_17 = (u64)s_b_0_16 (const) */
    /* execute.a64:1607 [F] s_b_0_18 = (u64)s_b_0_8 (const) */
    /* execute.a64:1607 [F] s_b_0_19 = s_b_0_17<<s_b_0_18 (const) */
    uint64_t s_b_0_19 = ((uint64_t)(((uint64_t)s_b_0_16) << ((uint64_t)((uint8_t)s_b_0_7))));
    /* execute.a64:1607 [F] s_b_0_20 = (s64)s_b_0_19 (const) */
    /* ???:4294967295 [F] s_b_0_21: sym_91122_1_tmp_s_b_10_5 = s_b_0_20 (const), dominates: s_b_2_0  */
    CV_sym_91122_1_tmp_s_b_10_5 = ((int64_t)s_b_0_19);
    /* execute.a64:2793 [F] s_b_0_22=sym_14620_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_23 = (u32)s_b_0_22 (const) */
    /* execute.a64:2793 [F] s_b_0_24 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_25 = s_b_0_23==s_b_0_24 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_26: If s_b_0_25: Jump b_3 else b_1 (const) */
    if (s_b_0_25) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_1;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2796 [F] s_b_1_0=sym_14620_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_1_2: sym_91110_1__R_s_b_10_11 = s_b_1_1, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_91110_1__R_s_b_10_11, s_b_1_1);
    /* execute.a64:2796 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0 = sym_91122_1_tmp_s_b_10_5 (const) int64_t */
    int64_t s_b_2_0 = CV_sym_91122_1_tmp_s_b_10_5;
    /* execute.a64:1609 [D] s_b_2_1 = sym_91110_1__R_s_b_10_11 uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_91110_1__R_s_b_10_11, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_2_2 = (u64)s_b_2_0 (const) */
    /* ???:4294967295 [D] s_b_2_3 = s_b_2_1+s_b_2_2 */
    auto s_b_2_3 = emitter.add(s_b_2_1, emitter.const_u64(((uint64_t)s_b_2_0)));
    /* ???:4294967295 [D] s_b_2_4 = Load 4 s_b_2_3 => sym_14660_0_data1 */
    auto s_b_2_4 = emitter.load_memory(s_b_2_3, emitter.context().types().u32());
    emitter.store_local(DV_sym_14660_0_data1, s_b_2_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_3, s_b_2_4, emitter.const_u8(4));
    }
    /* execute.a64:1615 [F] s_b_2_5 = constant u64 4 (const) */
    /* execute.a64:1615 [D] s_b_2_6 = s_b_2_3+s_b_2_5 */
    auto s_b_2_6 = emitter.add(s_b_2_3, emitter.const_u64((uint64_t)4ULL));
    /* ???:4294967295 [D] s_b_2_7 = Load 4 s_b_2_6 => sym_14666_0_data2 */
    auto s_b_2_7 = emitter.load_memory(s_b_2_6, emitter.context().types().u32());
    emitter.store_local(DV_sym_14666_0_data2, s_b_2_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_6, s_b_2_7, emitter.const_u8(4));
    }
    /* execute.a64:1617 [D] s_b_2_8 = sym_14660_0_data1 uint32_t */
    auto s_b_2_8 = emitter.load_local(DV_sym_14660_0_data1, emitter.context().types().u32());
    /* execute.a64:1617 [D] s_b_2_9 = (s32)s_b_2_8 */
    auto s_b_2_9 = emitter.reinterpret(s_b_2_8, emitter.context().types().s32());
    /* execute.a64:1617 [D] s_b_2_10 = (s64)s_b_2_9 */
    auto s_b_2_10 = emitter.sx(s_b_2_9, emitter.context().types().s64());
    /* execute.a64:1617 [D] s_b_2_11 = (u64)s_b_2_10 */
    auto s_b_2_11 = emitter.reinterpret(s_b_2_10, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_2_12=sym_14620_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_2_13: sym_91257_3_parameter_value = s_b_2_11, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_91257_3_parameter_value, s_b_2_11);
    /* execute.a64:2745 [F] s_b_2_14 = (u32)s_b_2_12 (const) */
    /* execute.a64:2745 [F] s_b_2_15 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_2_16 = s_b_2_14==s_b_2_15 (const) */
    uint8_t s_b_2_16 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_2_17: If s_b_2_16: Jump b_8 else b_10 (const) */
    if (s_b_2_16) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2764 [F] s_b_3_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_3_1 = __builtin_get_feature */
    uint32_t s_b_3_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(s_b_3_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_9 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2765 [D] s_b_4_0 = ReadReg 21 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_4_1: sym_91151_1__R_s_b_14_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_91151_1__R_s_b_14_0, s_b_4_0);
    /* execute.a64:2765 [F] s_b_4_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2768 [D] s_b_5_0 = ReadReg 21 (u64) */
    auto s_b_5_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_5_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_5_1: sym_91151_1__R_s_b_14_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_91151_1__R_s_b_14_0, s_b_5_0);
    /* execute.a64:2768 [F] s_b_5_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2770 [D] s_b_6_0 = ReadReg 22 (u64) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_6_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_6_1: sym_91151_1__R_s_b_14_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_91151_1__R_s_b_14_0, s_b_6_0);
    /* execute.a64:2770 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2794 [D] s_b_7_0 = sym_91151_1__R_s_b_14_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_91151_1__R_s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_7_1: sym_91110_1__R_s_b_10_11 = s_b_7_0, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_91110_1__R_s_b_10_11, s_b_7_0);
    /* execute.a64:2794 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1618 [D] s_b_8_0 = sym_14666_0_data2 uint32_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_14666_0_data2, emitter.context().types().u32());
    /* execute.a64:1618 [D] s_b_8_1 = (s32)s_b_8_0 */
    auto s_b_8_1 = emitter.reinterpret(s_b_8_0, emitter.context().types().s32());
    /* execute.a64:1618 [D] s_b_8_2 = (s64)s_b_8_1 */
    auto s_b_8_2 = emitter.sx(s_b_8_1, emitter.context().types().s64());
    /* execute.a64:1618 [D] s_b_8_3 = (u64)s_b_8_2 */
    auto s_b_8_3 = emitter.reinterpret(s_b_8_2, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_8_4=sym_14620_3_parameter_inst.rt2 (const) */
    /* execute.a64:2754 [D] s_b_8_5: sym_91327_3_parameter_value = s_b_8_3, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_91327_3_parameter_value, s_b_8_3);
    /* execute.a64:2745 [F] s_b_8_6 = (u32)s_b_8_4 (const) */
    /* execute.a64:2745 [F] s_b_8_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_8_8 = s_b_8_6==s_b_8_7 (const) */
    uint8_t s_b_8_8 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_8_9: If s_b_8_8: Jump b_11 else b_12 (const) */
    if (s_b_8_8) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:3075 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_9_2 = (u8)s_b_9_1 (const) */
    /* execute.a64:2767 [F] s_b_9_3 = (u32)s_b_9_2 (const) */
    /* execute.a64:2767 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_9_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_9_6: If s_b_9_5: Jump b_5 else b_6 (const) */
    if (s_b_9_5) 
    {
      goto fixed_block_b_5;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_2,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2747 [F] s_b_10_0=sym_14620_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_10_1 = sym_91257_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_91257_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1);
    /* execute.a64:0 [F] s_b_10_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_8, b_12,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [F] s_b_11_0: Return */
    goto fixed_done;
  }
  /* b_8,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2747 [F] s_b_12_0=sym_14620_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_12_1 = sym_91327_3_parameter_value uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_91327_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_12_2: WriteRegBank 0:s_b_12_0 = s_b_12_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_12_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_12_1);
    /* execute.a64:0 [F] s_b_12_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldrb_reg(const arm64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_15526_0_rm;
  auto DV_sym_15526_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_15627_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint32_t CV_sym_104056_1_temporary_value;
  auto DV_sym_104056_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_104750_1__R_s_b_43_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_104830_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_104136_1__R_s_b_2_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_104852_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_104277_1_temporary_value;
  auto DV_sym_104277_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_104918_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_104597_1_temporary_value;
  auto DV_sym_104597_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_104431_1_temporary_value;
  auto DV_sym_104431_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1140 [F] s_b_0_0=sym_15499_3_parameter_inst.option0 (const) */
    /* execute.a64:1140 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1140 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1140 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1140 [F] s_b_0_4=sym_15499_3_parameter_inst.option21 (const) */
    /* execute.a64:1140 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:1140 [F] s_b_0_6 = constant u32 1 (const) */
    /* execute.a64:1140 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:1140 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
    if (s_b_0_11) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1141 [F] s_b_1_0=sym_15499_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2709 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_1_4: If s_b_1_3: Jump b_15 else b_16 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_9, b_17, b_22, b_25, b_28,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2793 [F] s_b_2_0=sym_15499_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2793 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_2_4: If s_b_2_3: Jump b_29 else b_18 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1142 [F] s_b_3_0=sym_15499_3_parameter_inst.option0 (const) */
    /* execute.a64:1142 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1142 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1142 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1142 [F] s_b_3_4=sym_15499_3_parameter_inst.option21 (const) */
    /* execute.a64:1142 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:1142 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.a64:1142 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:1142 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
    if (s_b_3_11) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1143 [F] s_b_4_0=sym_15499_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2709 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_4_4: If s_b_4_3: Jump b_20 else b_21 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1144 [F] s_b_5_0=sym_15499_3_parameter_inst.option0 (const) */
    /* execute.a64:1144 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1144 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1144 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1144 [F] s_b_5_4=sym_15499_3_parameter_inst.option21 (const) */
    /* execute.a64:1144 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1144 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:1144 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1144 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
    if (s_b_5_11) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:1145 [F] s_b_6_0=sym_15499_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2714 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_6_4: If s_b_6_3: Jump b_23 else b_24 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1146 [F] s_b_7_0=sym_15499_3_parameter_inst.option0 (const) */
    /* execute.a64:1146 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1146 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1146 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1146 [F] s_b_7_4=sym_15499_3_parameter_inst.option21 (const) */
    /* execute.a64:1146 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:1146 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.a64:1146 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:1146 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
    if (s_b_7_11) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1147 [F] s_b_8_0=sym_15499_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2714 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_8_4: If s_b_8_3: Jump b_26 else b_27 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1149 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:1149 [F] s_b_9_1: sym_15526_0_rm = s_b_9_0 (const), dominates: s_b_19_1  */
    CV_sym_15526_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_15526_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1150 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1149 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_19,  */
  fixed_block_b_10: 
  {
    /* execute.a64:1159 [F] s_b_10_0=sym_15499_3_parameter_inst.L (const) */
    /* execute.a64:1159 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:1159 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:1159 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.L) == (uint32_t)0ULL));
    /* execute.a64:1159 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_12, b_13, b_14, b_34, b_35, b_36,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [F] s_b_11_0: Return */
    goto fixed_done;
  }
  /* b_19,  */
  fixed_block_b_12: 
  {
    /* execute.a64:1165 [D] s_b_12_0 = sym_15627_0_value uint8_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_15627_0_value, emitter.context().types().u8());
    /* execute.a64:1165 [D] s_b_12_1 = (u64)s_b_12_0 */
    auto s_b_12_1 = emitter.zx(s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_12_2=sym_15499_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_12_3 = (u32)s_b_12_1 */
    auto s_b_12_3 = emitter.truncate(s_b_12_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_12_4 = (u64)s_b_12_3 */
    auto s_b_12_4 = emitter.zx(s_b_12_3, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_12_5: sym_104830_3_parameter_value = s_b_12_4, dominates: s_b_34_1  */
    emitter.store_local(DV_sym_104830_3_parameter_value, s_b_12_4);
    /* execute.a64:2745 [F] s_b_12_6 = (u32)s_b_12_2 (const) */
    /* execute.a64:2745 [F] s_b_12_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_12_8 = s_b_12_6==s_b_12_7 (const) */
    uint8_t s_b_12_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_12_9: If s_b_12_8: Jump b_11 else b_34 (const) */
    if (s_b_12_8) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_34;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1160 [D] s_b_13_0 = sym_15627_0_value uint8_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_15627_0_value, emitter.context().types().u8());
    /* execute.a64:1160 [D] s_b_13_1 = (s8)s_b_13_0 */
    auto s_b_13_1 = emitter.reinterpret(s_b_13_0, emitter.context().types().s8());
    /* execute.a64:1160 [D] s_b_13_2 = (s64)s_b_13_1 */
    auto s_b_13_2 = emitter.sx(s_b_13_1, emitter.context().types().s64());
    /* execute.a64:1160 [D] s_b_13_3 = (u64)s_b_13_2 */
    auto s_b_13_3 = emitter.reinterpret(s_b_13_2, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_13_4=sym_15499_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_13_5: sym_104852_3_parameter_value = s_b_13_3, dominates: s_b_35_1  */
    emitter.store_local(DV_sym_104852_3_parameter_value, s_b_13_3);
    /* execute.a64:2745 [F] s_b_13_6 = (u32)s_b_13_4 (const) */
    /* execute.a64:2745 [F] s_b_13_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_13_8 = s_b_13_6==s_b_13_7 (const) */
    uint8_t s_b_13_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_13_9: If s_b_13_8: Jump b_11 else b_35 (const) */
    if (s_b_13_8) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1162 [D] s_b_14_0 = sym_15627_0_value uint8_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_15627_0_value, emitter.context().types().u8());
    /* execute.a64:1162 [D] s_b_14_1 = (s8)s_b_14_0 */
    auto s_b_14_1 = emitter.reinterpret(s_b_14_0, emitter.context().types().s8());
    /* execute.a64:1162 [D] s_b_14_2 = (s64)s_b_14_1 */
    auto s_b_14_2 = emitter.sx(s_b_14_1, emitter.context().types().s64());
    /* execute.a64:1162 [D] s_b_14_3 = (u64)s_b_14_2 */
    auto s_b_14_3 = emitter.reinterpret(s_b_14_2, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_14_4=sym_15499_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_14_5 = (u32)s_b_14_3 */
    auto s_b_14_5 = emitter.truncate(s_b_14_3, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_14_6 = (u64)s_b_14_5 */
    auto s_b_14_6 = emitter.zx(s_b_14_5, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_14_7: sym_104918_3_parameter_value = s_b_14_6, dominates: s_b_36_1  */
    emitter.store_local(DV_sym_104918_3_parameter_value, s_b_14_6);
    /* execute.a64:2745 [F] s_b_14_8 = (u32)s_b_14_4 (const) */
    /* execute.a64:2745 [F] s_b_14_9 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_14_10 = s_b_14_8==s_b_14_9 (const) */
    uint8_t s_b_14_10 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_14_11: If s_b_14_10: Jump b_11 else b_36 (const) */
    if (s_b_14_10) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_36;
    }
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2709 [F] s_b_15_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_15_1: sym_104056_1_temporary_value = s_b_15_0 (const), dominates: s_b_17_0  */
    CV_sym_104056_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_104056_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_1,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [F] s_b_16_0=sym_15499_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_16_1 = ReadRegBank 1:s_b_16_0 (u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_16_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_16_2: sym_104056_1_temporary_value = s_b_16_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_104056_1_temporary_value, s_b_16_1);
    /* execute.a64:2709 [F] s_b_16_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2709 [D] s_b_17_0 = sym_104056_1_temporary_value uint32_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_104056_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_17_1 = (u64)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u64());
    /* execute.a64:2679 [D] s_b_17_2 = (u32)s_b_17_1 */
    auto s_b_17_2 = emitter.truncate(s_b_17_1, emitter.context().types().u32());
    /* execute.a64:2679 [D] s_b_17_3 = (u64)s_b_17_2 */
    auto s_b_17_3 = emitter.zx(s_b_17_2, emitter.context().types().u64());
    /* execute.a64:2679 [F] s_b_17_4=sym_15499_3_parameter_inst.S (const) */
    /* execute.a64:2679 [F] s_b_17_5 = (u64)s_b_17_4 (const) */
    /* execute.a64:2679 [D] s_b_17_6 = s_b_17_3<<s_b_17_5 */
    auto s_b_17_6 = emitter.shl(s_b_17_3, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1141 [D] s_b_17_7: sym_15526_0_rm = s_b_17_6, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_15526_0_rm, s_b_17_6);
    /* execute.a64:1141 [F] s_b_17_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2796 [F] s_b_18_0=sym_15499_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_18_2: sym_104136_1__R_s_b_2_5 = s_b_18_1, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_104136_1__R_s_b_2_5, s_b_18_1);
    /* execute.a64:2796 [F] s_b_18_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_18, b_33,  */
  fixed_block_b_19: 
  {
    /* execute.a64:1153 [D] s_b_19_0 = sym_104136_1__R_s_b_2_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_104136_1__R_s_b_2_5, emitter.context().types().u64());
    /* execute.a64:1153 [D] s_b_19_1 = sym_15526_0_rm uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_15526_0_rm, emitter.context().types().u64());
    /* execute.a64:1153 [D] s_b_19_2 = s_b_19_0+s_b_19_1 */
    auto s_b_19_2 = emitter.add(s_b_19_0, s_b_19_1);
    /* ???:4294967295 [D] s_b_19_3 = Load 1 s_b_19_2 => sym_15627_0_value */
    auto s_b_19_3 = emitter.load_memory(s_b_19_2, emitter.context().types().u8());
    emitter.store_local(DV_sym_15627_0_value, s_b_19_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_19_2, s_b_19_3, emitter.const_u8(1));
    }
    /* execute.a64:1158 [F] s_b_19_4=sym_15499_3_parameter_inst.X (const) */
    /* execute.a64:1158 [F] s_b_19_5: If s_b_19_4: Jump b_10 else b_12 (const) */
    if (insn.X) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_4,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2709 [F] s_b_20_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_20_1: sym_104277_1_temporary_value = s_b_20_0 (const), dominates: s_b_22_0  */
    CV_sym_104277_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_104277_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_4,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2709 [F] s_b_21_0=sym_15499_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_21_1 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_21_2: sym_104277_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_104277_1_temporary_value, s_b_21_1);
    /* execute.a64:2709 [F] s_b_21_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2709 [D] s_b_22_0 = sym_104277_1_temporary_value uint32_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_104277_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_22_1 = (u64)s_b_22_0 */
    auto s_b_22_1 = emitter.zx(s_b_22_0, emitter.context().types().u64());
    /* execute.a64:2695 [D] s_b_22_2 = (s32)s_b_22_1 */
    auto s_b_22_2 = emitter.truncate(s_b_22_1, emitter.context().types().s32());
    /* execute.a64:2695 [D] s_b_22_3 = (s64)s_b_22_2 */
    auto s_b_22_3 = emitter.sx(s_b_22_2, emitter.context().types().s64());
    /* execute.a64:2695 [D] s_b_22_4 = (u64)s_b_22_3 */
    auto s_b_22_4 = emitter.reinterpret(s_b_22_3, emitter.context().types().u64());
    /* execute.a64:2695 [F] s_b_22_5=sym_15499_3_parameter_inst.S (const) */
    /* execute.a64:2695 [F] s_b_22_6 = (u64)s_b_22_5 (const) */
    /* execute.a64:2695 [D] s_b_22_7 = s_b_22_4<<s_b_22_6 */
    auto s_b_22_7 = emitter.shl(s_b_22_4, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1143 [D] s_b_22_8: sym_15526_0_rm = s_b_22_7, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_15526_0_rm, s_b_22_7);
    /* execute.a64:1143 [F] s_b_22_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [F] s_b_23_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_23_1: sym_104431_1_temporary_value = s_b_23_0 (const), dominates: s_b_25_0  */
    CV_sym_104431_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_104431_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_23_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_6,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [F] s_b_24_0=sym_15499_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_24_1 = ReadRegBank 0:s_b_24_0 (u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_24_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_24_2: sym_104431_1_temporary_value = s_b_24_1, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_104431_1_temporary_value, s_b_24_1);
    /* execute.a64:2714 [F] s_b_24_3: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_23, b_24,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2714 [D] s_b_25_0 = sym_104431_1_temporary_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_104431_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2683 [F] s_b_25_1=sym_15499_3_parameter_inst.S (const) */
    /* execute.a64:2683 [F] s_b_25_2 = (u64)s_b_25_1 (const) */
    /* execute.a64:2683 [D] s_b_25_3 = s_b_25_0<<s_b_25_2 */
    auto s_b_25_3 = emitter.shl(s_b_25_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1145 [D] s_b_25_4: sym_15526_0_rm = s_b_25_3, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_15526_0_rm, s_b_25_3);
    /* execute.a64:1145 [F] s_b_25_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2714 [F] s_b_26_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_26_1: sym_104597_1_temporary_value = s_b_26_0 (const), dominates: s_b_28_0  */
    CV_sym_104597_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_104597_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_26_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_8,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2714 [F] s_b_27_0=sym_15499_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_27_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_27_2: sym_104597_1_temporary_value = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_104597_1_temporary_value, s_b_27_1);
    /* execute.a64:2714 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_26, b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2714 [D] s_b_28_0 = sym_104597_1_temporary_value uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_104597_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2699 [F] s_b_28_1=sym_15499_3_parameter_inst.S (const) */
    /* execute.a64:2699 [F] s_b_28_2 = (u64)s_b_28_1 (const) */
    /* execute.a64:2699 [D] s_b_28_3 = s_b_28_0<<s_b_28_2 */
    auto s_b_28_3 = emitter.shl(s_b_28_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1147 [D] s_b_28_4: sym_15526_0_rm = s_b_28_3, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_15526_0_rm, s_b_28_3);
    /* execute.a64:1147 [F] s_b_28_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2764 [F] s_b_29_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_29_1 = __builtin_get_feature */
    uint32_t s_b_29_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_29_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(s_b_29_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_29_4: If s_b_29_3: Jump b_30 else b_37 (const) */
    if (s_b_29_3) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_37;
    }
  }
  /* b_29,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2765 [D] s_b_30_0 = ReadReg 21 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_30_1: sym_104750_1__R_s_b_43_0 = s_b_30_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_104750_1__R_s_b_43_0, s_b_30_0);
    /* execute.a64:2765 [F] s_b_30_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_37,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2768 [D] s_b_31_0 = ReadReg 21 (u64) */
    auto s_b_31_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_31_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_31_1: sym_104750_1__R_s_b_43_0 = s_b_31_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_104750_1__R_s_b_43_0, s_b_31_0);
    /* execute.a64:2768 [F] s_b_31_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_37,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2770 [D] s_b_32_0 = ReadReg 22 (u64) */
    auto s_b_32_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_32_1: sym_104750_1__R_s_b_43_0 = s_b_32_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_104750_1__R_s_b_43_0, s_b_32_0);
    /* execute.a64:2770 [F] s_b_32_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_30, b_31, b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2794 [D] s_b_33_0 = sym_104750_1__R_s_b_43_0 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_104750_1__R_s_b_43_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_33_1: sym_104136_1__R_s_b_2_5 = s_b_33_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_104136_1__R_s_b_2_5, s_b_33_0);
    /* execute.a64:2794 [F] s_b_33_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_12,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2747 [F] s_b_34_0=sym_15499_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_34_1 = sym_104830_3_parameter_value uint64_t */
    auto s_b_34_1 = emitter.load_local(DV_sym_104830_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_34_2: WriteRegBank 0:s_b_34_0 = s_b_34_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_34_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_34_1);
    /* execute.a64:0 [F] s_b_34_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_13,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2747 [F] s_b_35_0=sym_15499_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_35_1 = sym_104852_3_parameter_value uint64_t */
    auto s_b_35_1 = emitter.load_local(DV_sym_104852_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_35_2: WriteRegBank 0:s_b_35_0 = s_b_35_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_35_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_35_1);
    /* execute.a64:0 [F] s_b_35_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_14,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2747 [F] s_b_36_0=sym_15499_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_36_1 = sym_104918_3_parameter_value uint64_t */
    auto s_b_36_1 = emitter.load_local(DV_sym_104918_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_36_2: WriteRegBank 0:s_b_36_0 = s_b_36_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_36_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_36_1);
    /* execute.a64:0 [F] s_b_36_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_29,  */
  fixed_block_b_37: 
  {
    /* execute.a64:3075 [F] s_b_37_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_37_1 = __builtin_get_feature */
    uint32_t s_b_37_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_37_2 = (u8)s_b_37_1 (const) */
    /* execute.a64:2767 [F] s_b_37_3 = (u32)s_b_37_2 (const) */
    /* execute.a64:2767 [F] s_b_37_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_37_5 = s_b_37_3==s_b_37_4 (const) */
    uint8_t s_b_37_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_37_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_37_6: If s_b_37_5: Jump b_31 else b_32 (const) */
    if (s_b_37_5) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldrswi(const arm64_decode_a64_LS_REG_UIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_112073_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16186_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_112111_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112217_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_16175_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_3 else b_1 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_1;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2796 [F] s_b_1_0=sym_16175_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_1_2: sym_112073_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_112073_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2796 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1541 [D] s_b_2_0 = sym_112073_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_112073_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1541 [F] s_b_2_1=sym_16175_3_parameter_inst.immu64 (const) */
    /* execute.a64:1541 [D] s_b_2_2 = s_b_2_0+s_b_2_1 */
    auto s_b_2_2 = emitter.add(s_b_2_0, emitter.const_u64(insn.immu64));
    /* ???:4294967295 [D] s_b_2_3 = Load 4 s_b_2_2 => sym_16186_0_value */
    auto s_b_2_3 = emitter.load_memory(s_b_2_2, emitter.context().types().u32());
    emitter.store_local(DV_sym_16186_0_value, s_b_2_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_2, s_b_2_3, emitter.const_u8(4));
    }
    /* execute.a64:1546 [D] s_b_2_4 = sym_16186_0_value uint32_t */
    auto s_b_2_4 = emitter.load_local(DV_sym_16186_0_value, emitter.context().types().u32());
    /* execute.a64:1546 [D] s_b_2_5 = (s32)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().s32());
    /* execute.a64:1546 [D] s_b_2_6 = (s64)s_b_2_5 */
    auto s_b_2_6 = emitter.sx(s_b_2_5, emitter.context().types().s64());
    /* execute.a64:1546 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.reinterpret(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_2_8=sym_16175_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_2_9: sym_112217_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_112217_3_parameter_value, s_b_2_7);
    /* execute.a64:2745 [F] s_b_2_10 = (u32)s_b_2_8 (const) */
    /* execute.a64:2745 [F] s_b_2_11 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_2_12 = s_b_2_10==s_b_2_11 (const) */
    uint8_t s_b_2_12 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_2_13: If s_b_2_12: Jump b_8 else b_10 (const) */
    if (s_b_2_12) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2764 [F] s_b_3_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_3_1 = __builtin_get_feature */
    uint32_t s_b_3_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(s_b_3_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_9 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2765 [D] s_b_4_0 = ReadReg 21 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_4_1: sym_112111_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_112111_1__R_s_b_4_0, s_b_4_0);
    /* execute.a64:2765 [F] s_b_4_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2768 [D] s_b_5_0 = ReadReg 21 (u64) */
    auto s_b_5_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_5_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_5_1: sym_112111_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_112111_1__R_s_b_4_0, s_b_5_0);
    /* execute.a64:2768 [F] s_b_5_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2770 [D] s_b_6_0 = ReadReg 22 (u64) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_6_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_6_1: sym_112111_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_112111_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2770 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2794 [D] s_b_7_0 = sym_112111_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_112111_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_7_1: sym_112073_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_112073_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2794 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* ???:4294967295 [F] s_b_8_0: Return */
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:3075 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_9_2 = (u8)s_b_9_1 (const) */
    /* execute.a64:2767 [F] s_b_9_3 = (u32)s_b_9_2 (const) */
    /* execute.a64:2767 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_9_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_9_6: If s_b_9_5: Jump b_5 else b_6 (const) */
    if (s_b_9_5) 
    {
      goto fixed_block_b_5;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_2,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2747 [F] s_b_10_0=sym_16175_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_10_1 = sym_112217_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_112217_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1);
    /* execute.a64:0 [F] s_b_10_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldursw(const arm64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_16423_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_113409_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_113515_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_113371_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_16409_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_3 else b_1 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_1;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2796 [F] s_b_1_0=sym_16409_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_1_2: sym_113371_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_113371_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2796 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1442 [D] s_b_2_0 = sym_113371_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_113371_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1443 [F] s_b_2_1=sym_16409_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_2_2 = (u64)s_b_2_1 (const) */
    /* ???:4294967295 [D] s_b_2_3 = s_b_2_0+s_b_2_2 */
    auto s_b_2_3 = emitter.add(s_b_2_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* ???:4294967295 [D] s_b_2_4 = Load 4 s_b_2_3 => sym_16423_0_value */
    auto s_b_2_4 = emitter.load_memory(s_b_2_3, emitter.context().types().u32());
    emitter.store_local(DV_sym_16423_0_value, s_b_2_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_3, s_b_2_4, emitter.const_u8(4));
    }
    /* execute.a64:1448 [D] s_b_2_5 = sym_16423_0_value uint32_t */
    auto s_b_2_5 = emitter.load_local(DV_sym_16423_0_value, emitter.context().types().u32());
    /* execute.a64:1448 [D] s_b_2_6 = (s32)s_b_2_5 */
    auto s_b_2_6 = emitter.reinterpret(s_b_2_5, emitter.context().types().s32());
    /* execute.a64:1448 [D] s_b_2_7 = (s64)s_b_2_6 */
    auto s_b_2_7 = emitter.sx(s_b_2_6, emitter.context().types().s64());
    /* execute.a64:1448 [D] s_b_2_8 = (u64)s_b_2_7 */
    auto s_b_2_8 = emitter.reinterpret(s_b_2_7, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_2_9=sym_16409_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_2_10: sym_113515_3_parameter_value = s_b_2_8, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_113515_3_parameter_value, s_b_2_8);
    /* execute.a64:2745 [F] s_b_2_11 = (u32)s_b_2_9 (const) */
    /* execute.a64:2745 [F] s_b_2_12 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_2_13 = s_b_2_11==s_b_2_12 (const) */
    uint8_t s_b_2_13 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_2_14: If s_b_2_13: Jump b_8 else b_10 (const) */
    if (s_b_2_13) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2764 [F] s_b_3_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_3_1 = __builtin_get_feature */
    uint32_t s_b_3_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(s_b_3_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_9 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2765 [D] s_b_4_0 = ReadReg 21 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_4_1: sym_113409_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_113409_1__R_s_b_4_0, s_b_4_0);
    /* execute.a64:2765 [F] s_b_4_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2768 [D] s_b_5_0 = ReadReg 21 (u64) */
    auto s_b_5_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_5_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_5_1: sym_113409_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_113409_1__R_s_b_4_0, s_b_5_0);
    /* execute.a64:2768 [F] s_b_5_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2770 [D] s_b_6_0 = ReadReg 22 (u64) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_6_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_6_1: sym_113409_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_113409_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2770 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2794 [D] s_b_7_0 = sym_113409_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_113409_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_7_1: sym_113371_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_113371_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2794 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* ???:4294967295 [F] s_b_8_0: Return */
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:3075 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_9_2 = (u8)s_b_9_1 (const) */
    /* execute.a64:2767 [F] s_b_9_3 = (u32)s_b_9_2 (const) */
    /* execute.a64:2767 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_9_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_9_6: If s_b_9_5: Jump b_5 else b_6 (const) */
    if (s_b_9_5) 
    {
      goto fixed_block_b_5;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_2,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2747 [F] s_b_10_0=sym_16409_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_10_1 = sym_113515_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_113515_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1);
    /* execute.a64:0 [F] s_b_10_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_mla_vector(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1271 [F] s_b_0_0=sym_16684_3_parameter_inst.arrangement (const) */
    /* execute.simd:1272 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:1283 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:1293 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:1304 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:1314 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:1325 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:1271 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4, b_5, b_6, b_7,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_0, b_2, b_3, b_4, b_5, b_6, b_7,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:1273 [F] s_b_2_0=sym_16684_3_parameter_inst.rn (const) */
    /* execute.simd:1273 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1274 [F] s_b_2_2=sym_16684_3_parameter_inst.rm (const) */
    /* execute.simd:1274 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* execute.simd:1275 [F] s_b_2_4=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1275 [D] s_b_2_5 = ReadRegBank 15:s_b_2_4 (v8u8) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_5,emitter.const_u8(8));
    }
    /* execute.simd:1277 [D] s_b_2_6 = s_b_2_1*s_b_2_3 */
    auto s_b_2_6 = emitter.mul(s_b_2_1, s_b_2_3);
    /* ???:4294967295 [D] s_b_2_7 = s_b_2_5+s_b_2_6 */
    auto s_b_2_7 = emitter.add(s_b_2_5, s_b_2_6);
    /* execute.simd:1279 [F] s_b_2_8=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1279 [D] s_b_2_9: WriteRegBank 15:s_b_2_8 = s_b_2_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_7);
    /* execute.simd:1280 [F] s_b_2_10=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1280 [F] s_b_2_11 = constant u64 0 (const) */
    /* execute.simd:1280 [F] s_b_2_12: WriteRegBank 3:s_b_2_10 = s_b_2_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_13: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1284 [F] s_b_3_0=sym_16684_3_parameter_inst.rn (const) */
    /* execute.simd:1284 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:1285 [F] s_b_3_2=sym_16684_3_parameter_inst.rm (const) */
    /* execute.simd:1285 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:1286 [F] s_b_3_4=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1286 [D] s_b_3_5 = ReadRegBank 16:s_b_3_4 (v16u8) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_5,emitter.const_u8(16));
    }
    /* execute.simd:1288 [D] s_b_3_6 = s_b_3_1*s_b_3_3 */
    auto s_b_3_6 = emitter.mul(s_b_3_1, s_b_3_3);
    /* ???:4294967295 [D] s_b_3_7 = s_b_3_5+s_b_3_6 */
    auto s_b_3_7 = emitter.add(s_b_3_5, s_b_3_6);
    /* execute.simd:1290 [F] s_b_3_8=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1290 [D] s_b_3_9: WriteRegBank 16:s_b_3_8 = s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7);
    /* execute.simd:0 [F] s_b_3_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1294 [F] s_b_4_0=sym_16684_3_parameter_inst.rn (const) */
    /* execute.simd:1294 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:1295 [F] s_b_4_2=sym_16684_3_parameter_inst.rm (const) */
    /* execute.simd:1295 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* execute.simd:1296 [F] s_b_4_4=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1296 [D] s_b_4_5 = ReadRegBank 17:s_b_4_4 (v4u16) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_5,emitter.const_u8(8));
    }
    /* execute.simd:1298 [D] s_b_4_6 = s_b_4_1*s_b_4_3 */
    auto s_b_4_6 = emitter.mul(s_b_4_1, s_b_4_3);
    /* ???:4294967295 [D] s_b_4_7 = s_b_4_5+s_b_4_6 */
    auto s_b_4_7 = emitter.add(s_b_4_5, s_b_4_6);
    /* execute.simd:1300 [F] s_b_4_8=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1300 [D] s_b_4_9: WriteRegBank 17:s_b_4_8 = s_b_4_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_7);
    /* execute.simd:1301 [F] s_b_4_10=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1301 [F] s_b_4_11 = constant u64 0 (const) */
    /* execute.simd:1301 [F] s_b_4_12: WriteRegBank 3:s_b_4_10 = s_b_4_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_13: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:1305 [F] s_b_5_0=sym_16684_3_parameter_inst.rn (const) */
    /* execute.simd:1305 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1306 [F] s_b_5_2=sym_16684_3_parameter_inst.rm (const) */
    /* execute.simd:1306 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1307 [F] s_b_5_4=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1307 [D] s_b_5_5 = ReadRegBank 18:s_b_5_4 (v8u16) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5,emitter.const_u8(16));
    }
    /* execute.simd:1309 [D] s_b_5_6 = s_b_5_1*s_b_5_3 */
    auto s_b_5_6 = emitter.mul(s_b_5_1, s_b_5_3);
    /* ???:4294967295 [D] s_b_5_7 = s_b_5_5+s_b_5_6 */
    auto s_b_5_7 = emitter.add(s_b_5_5, s_b_5_6);
    /* execute.simd:1311 [F] s_b_5_8=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1311 [D] s_b_5_9: WriteRegBank 18:s_b_5_8 = s_b_5_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_7);
    /* execute.simd:0 [F] s_b_5_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:1315 [F] s_b_6_0=sym_16684_3_parameter_inst.rn (const) */
    /* execute.simd:1315 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1316 [F] s_b_6_2=sym_16684_3_parameter_inst.rm (const) */
    /* execute.simd:1316 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1317 [F] s_b_6_4=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1317 [D] s_b_6_5 = ReadRegBank 19:s_b_6_4 (v2u32) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_5,emitter.const_u8(8));
    }
    /* execute.simd:1319 [D] s_b_6_6 = s_b_6_1*s_b_6_3 */
    auto s_b_6_6 = emitter.mul(s_b_6_1, s_b_6_3);
    /* ???:4294967295 [D] s_b_6_7 = s_b_6_5+s_b_6_6 */
    auto s_b_6_7 = emitter.add(s_b_6_5, s_b_6_6);
    /* execute.simd:1321 [F] s_b_6_8=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1321 [D] s_b_6_9: WriteRegBank 19:s_b_6_8 = s_b_6_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_7);
    /* execute.simd:1322 [F] s_b_6_10=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1322 [F] s_b_6_11 = constant u64 0 (const) */
    /* execute.simd:1322 [F] s_b_6_12: WriteRegBank 3:s_b_6_10 = s_b_6_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_13: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:1326 [F] s_b_7_0=sym_16684_3_parameter_inst.rn (const) */
    /* execute.simd:1326 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:1327 [F] s_b_7_2=sym_16684_3_parameter_inst.rm (const) */
    /* execute.simd:1327 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:1328 [F] s_b_7_4=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1328 [D] s_b_7_5 = ReadRegBank 20:s_b_7_4 (v4u32) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5,emitter.const_u8(16));
    }
    /* execute.simd:1330 [D] s_b_7_6 = s_b_7_1*s_b_7_3 */
    auto s_b_7_6 = emitter.mul(s_b_7_1, s_b_7_3);
    /* ???:4294967295 [D] s_b_7_7 = s_b_7_5+s_b_7_6 */
    auto s_b_7_7 = emitter.add(s_b_7_5, s_b_7_6);
    /* execute.simd:1332 [F] s_b_7_8=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:1332 [D] s_b_7_9: WriteRegBank 20:s_b_7_8 = s_b_7_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_7);
    /* execute.simd:0 [F] s_b_7_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_msr_reg(const arm64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(1);
  emitter.mark_used_feature(2);
  emitter.mark_used_feature(3);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_126677_1_temporary_value;
  auto DV_sym_126677_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_18182_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:401 [F] s_b_0_0=sym_18178_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2714 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_0_4: If s_b_0_3: Jump b_38 else b_39 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_38;
    }
    else 
    {
      goto fixed_block_b_39;
    }
  }
  /* b_40,  */
  fixed_block_b_1: 
  {
    /* execute.a64:404 [D] s_b_1_0 = sym_18182_0_value uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:404 [D] s_b_1_1: WriteReg 10 = s_b_1_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1312), s_b_1_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1312), s_b_1_0);
    /* execute.a64:406 [F] s_b_1_2 = constant u32 3 (const) */
    /* execute.a64:406 [F] s_b_1_3 = __builtin_get_feature */
    uint32_t s_b_1_3 = __get_feature((uint32_t)3ULL);
    /* execute.a64:406 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.a64:406 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
    uint8_t s_b_1_5 = ((uint8_t)(s_b_1_3 == (uint32_t)0ULL));
    /* execute.a64:406 [F] s_b_1_6: If s_b_1_5: Jump b_4 else b_5 (const) */
    if (s_b_1_5) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_5, b_9, b_10, b_12, b_14, b_16, b_18, b_20, b_22, b_24, b_26, b_28, b_30, b_32, b_34, b_36, b_37,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_40,  */
  fixed_block_b_3: 
  {
    /* execute.a64:411 [F] s_b_3_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:411 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:411 [F] s_b_3_2 = constant u32 3 (const) */
    /* execute.a64:411 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:411 [F] s_b_3_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:411 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:411 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.a64:411 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:411 [F] s_b_3_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:411 [F] s_b_3_13 = (u32)s_b_3_12 (const) */
    /* execute.a64:411 [F] s_b_3_14 = constant u32 2 (const) */
    /* execute.a64:411 [F] s_b_3_15 = s_b_3_13==s_b_3_14 (const) */
    uint8_t s_b_3_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_3_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_17 = s_b_3_11!=s_b_3_16 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(s_b_3_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_18 = s_b_3_15!=s_b_3_16 (const) */
    uint8_t s_b_3_18 = ((uint8_t)(s_b_3_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_19 = s_b_3_17&s_b_3_18 (const) */
    uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 & s_b_3_18));
    /* execute.a64:411 [F] s_b_3_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:411 [F] s_b_3_21 = (u32)s_b_3_20 (const) */
    /* execute.a64:411 [F] s_b_3_22 = constant u32 0 (const) */
    /* execute.a64:411 [F] s_b_3_23 = s_b_3_21==s_b_3_22 (const) */
    uint8_t s_b_3_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_25 = s_b_3_19!=s_b_3_24 (const) */
    uint8_t s_b_3_25 = ((uint8_t)(s_b_3_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_26 = s_b_3_23!=s_b_3_24 (const) */
    uint8_t s_b_3_26 = ((uint8_t)(s_b_3_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_27 = s_b_3_25&s_b_3_26 (const) */
    uint8_t s_b_3_27 = ((uint8_t)(s_b_3_25 & s_b_3_26));
    /* execute.a64:411 [F] s_b_3_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:411 [F] s_b_3_29 = (u32)s_b_3_28 (const) */
    /* execute.a64:411 [F] s_b_3_30 = constant u32 1 (const) */
    /* execute.a64:411 [F] s_b_3_31 = s_b_3_29==s_b_3_30 (const) */
    uint8_t s_b_3_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_3_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_33 = s_b_3_27!=s_b_3_32 (const) */
    uint8_t s_b_3_33 = ((uint8_t)(s_b_3_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_34 = s_b_3_31!=s_b_3_32 (const) */
    uint8_t s_b_3_34 = ((uint8_t)(s_b_3_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_35 = s_b_3_33&s_b_3_34 (const) */
    uint8_t s_b_3_35 = ((uint8_t)(s_b_3_33 & s_b_3_34));
    /* execute.a64:411 [F] s_b_3_36: If s_b_3_35: Jump b_6 else b_7 (const) */
    if (s_b_3_35) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:407 [D] s_b_4_0 = sym_18182_0_value uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:407 [F] s_b_4_1 = constant u64 30 (const) */
    /* execute.a64:407 [D] s_b_4_2 = s_b_4_0>>s_b_4_1 */
    auto s_b_4_2 = emitter.shr(s_b_4_0, emitter.const_u64((uint64_t)48ULL));
    /* execute.a64:407 [D] s_b_4_3 = (u32)s_b_4_2 */
    auto s_b_4_3 = emitter.truncate(s_b_4_2, emitter.context().types().u32());
    /* execute.a64:407 [D] s_b_4_4 = mmu_notify_asid_change */
    emitter.call(__captive_mmu_notify_asid_change, s_b_4_3);
    /* execute.a64:407 [F] s_b_4_5: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_1, b_4,  */
  fixed_block_b_5: 
  {
    /* execute.a64:410 [D] s_b_5_0 = mmu_notify_pgt_change */
    emitter.call(__captive_mmu_notify_pgt_change);
    /* execute.a64:404 [F] s_b_5_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.a64:412 [D] s_b_6_0 = sym_18182_0_value uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:412 [D] s_b_6_1: WriteReg 11 = s_b_6_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1320), s_b_6_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1320), s_b_6_0);
    /* execute.a64:414 [F] s_b_6_2 = constant u32 3 (const) */
    /* execute.a64:414 [F] s_b_6_3 = __builtin_get_feature */
    uint32_t s_b_6_3 = __get_feature((uint32_t)3ULL);
    /* execute.a64:414 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:414 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:414 [F] s_b_6_6: If s_b_6_5: Jump b_8 else b_9 (const) */
    if (s_b_6_5) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:419 [F] s_b_7_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:419 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:419 [F] s_b_7_2 = constant u32 3 (const) */
    /* execute.a64:419 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:419 [F] s_b_7_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:419 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:419 [F] s_b_7_6 = constant u32 0 (const) */
    /* execute.a64:419 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:419 [F] s_b_7_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:419 [F] s_b_7_13 = (u32)s_b_7_12 (const) */
    /* execute.a64:419 [F] s_b_7_14 = constant u32 4 (const) */
    /* execute.a64:419 [F] s_b_7_15 = s_b_7_13==s_b_7_14 (const) */
    uint8_t s_b_7_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_7_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_17 = s_b_7_11!=s_b_7_16 (const) */
    uint8_t s_b_7_17 = ((uint8_t)(s_b_7_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_18 = s_b_7_15!=s_b_7_16 (const) */
    uint8_t s_b_7_18 = ((uint8_t)(s_b_7_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_19 = s_b_7_17&s_b_7_18 (const) */
    uint8_t s_b_7_19 = ((uint8_t)(s_b_7_17 & s_b_7_18));
    /* execute.a64:419 [F] s_b_7_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:419 [F] s_b_7_21 = (u32)s_b_7_20 (const) */
    /* execute.a64:419 [F] s_b_7_22 = constant u32 2 (const) */
    /* execute.a64:419 [F] s_b_7_23 = s_b_7_21==s_b_7_22 (const) */
    uint8_t s_b_7_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_7_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_25 = s_b_7_19!=s_b_7_24 (const) */
    uint8_t s_b_7_25 = ((uint8_t)(s_b_7_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_26 = s_b_7_23!=s_b_7_24 (const) */
    uint8_t s_b_7_26 = ((uint8_t)(s_b_7_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_27 = s_b_7_25&s_b_7_26 (const) */
    uint8_t s_b_7_27 = ((uint8_t)(s_b_7_25 & s_b_7_26));
    /* execute.a64:419 [F] s_b_7_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:419 [F] s_b_7_29 = (u32)s_b_7_28 (const) */
    /* execute.a64:419 [F] s_b_7_30 = constant u32 0 (const) */
    /* execute.a64:419 [F] s_b_7_31 = s_b_7_29==s_b_7_30 (const) */
    uint8_t s_b_7_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_7_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_33 = s_b_7_27!=s_b_7_32 (const) */
    uint8_t s_b_7_33 = ((uint8_t)(s_b_7_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_34 = s_b_7_31!=s_b_7_32 (const) */
    uint8_t s_b_7_34 = ((uint8_t)(s_b_7_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_35 = s_b_7_33&s_b_7_34 (const) */
    uint8_t s_b_7_35 = ((uint8_t)(s_b_7_33 & s_b_7_34));
    /* execute.a64:419 [F] s_b_7_36: If s_b_7_35: Jump b_10 else b_11 (const) */
    if (s_b_7_35) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:415 [D] s_b_8_0 = sym_18182_0_value uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:415 [F] s_b_8_1 = constant u64 30 (const) */
    /* execute.a64:415 [D] s_b_8_2 = s_b_8_0>>s_b_8_1 */
    auto s_b_8_2 = emitter.shr(s_b_8_0, emitter.const_u64((uint64_t)48ULL));
    /* execute.a64:415 [D] s_b_8_3 = (u32)s_b_8_2 */
    auto s_b_8_3 = emitter.truncate(s_b_8_2, emitter.context().types().u32());
    /* execute.a64:415 [D] s_b_8_4 = mmu_notify_asid_change */
    emitter.call(__captive_mmu_notify_asid_change, s_b_8_3);
    /* execute.a64:415 [F] s_b_8_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:418 [D] s_b_9_0 = mmu_notify_pgt_change */
    emitter.call(__captive_mmu_notify_pgt_change);
    /* execute.a64:412 [F] s_b_9_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:420 [D] s_b_10_0 = sym_18182_0_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:420 [D] s_b_10_1 = (u8)s_b_10_0 */
    auto s_b_10_1 = emitter.truncate(s_b_10_0, emitter.context().types().u8());
    /* execute.a64:3016 [F] s_b_10_2 = constant u32 1 (const) */
    /* execute.a64:3016 [D] s_b_10_3 = (u32)s_b_10_1 */
    auto s_b_10_3 = emitter.zx(s_b_10_1, emitter.context().types().u32());
    /* execute.a64:3016 [D] s_b_10_4 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, s_b_10_3);
    /* execute.a64:0 [F] s_b_10_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_11: 
  {
    /* execute.a64:421 [F] s_b_11_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:421 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:421 [F] s_b_11_2 = constant u32 3 (const) */
    /* execute.a64:421 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:421 [F] s_b_11_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:421 [F] s_b_11_5 = (u32)s_b_11_4 (const) */
    /* execute.a64:421 [F] s_b_11_6 = constant u32 0 (const) */
    /* execute.a64:421 [F] s_b_11_7 = s_b_11_5==s_b_11_6 (const) */
    uint8_t s_b_11_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_11_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_9 = s_b_11_3!=s_b_11_8 (const) */
    uint8_t s_b_11_9 = ((uint8_t)(s_b_11_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_10 = s_b_11_7!=s_b_11_8 (const) */
    uint8_t s_b_11_10 = ((uint8_t)(s_b_11_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_11 = s_b_11_9&s_b_11_10 (const) */
    uint8_t s_b_11_11 = ((uint8_t)(s_b_11_9 & s_b_11_10));
    /* execute.a64:421 [F] s_b_11_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:421 [F] s_b_11_13 = (u32)s_b_11_12 (const) */
    /* execute.a64:421 [F] s_b_11_14 = constant u32 4 (const) */
    /* execute.a64:421 [F] s_b_11_15 = s_b_11_13==s_b_11_14 (const) */
    uint8_t s_b_11_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_11_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_17 = s_b_11_11!=s_b_11_16 (const) */
    uint8_t s_b_11_17 = ((uint8_t)(s_b_11_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_18 = s_b_11_15!=s_b_11_16 (const) */
    uint8_t s_b_11_18 = ((uint8_t)(s_b_11_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_19 = s_b_11_17&s_b_11_18 (const) */
    uint8_t s_b_11_19 = ((uint8_t)(s_b_11_17 & s_b_11_18));
    /* execute.a64:421 [F] s_b_11_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:421 [F] s_b_11_21 = (u32)s_b_11_20 (const) */
    /* execute.a64:421 [F] s_b_11_22 = constant u32 1 (const) */
    /* execute.a64:421 [F] s_b_11_23 = s_b_11_21==s_b_11_22 (const) */
    uint8_t s_b_11_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_11_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_25 = s_b_11_19!=s_b_11_24 (const) */
    uint8_t s_b_11_25 = ((uint8_t)(s_b_11_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_26 = s_b_11_23!=s_b_11_24 (const) */
    uint8_t s_b_11_26 = ((uint8_t)(s_b_11_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_27 = s_b_11_25&s_b_11_26 (const) */
    uint8_t s_b_11_27 = ((uint8_t)(s_b_11_25 & s_b_11_26));
    /* execute.a64:421 [F] s_b_11_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:421 [F] s_b_11_29 = (u32)s_b_11_28 (const) */
    /* execute.a64:421 [F] s_b_11_30 = constant u32 0 (const) */
    /* execute.a64:421 [F] s_b_11_31 = s_b_11_29==s_b_11_30 (const) */
    uint8_t s_b_11_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_11_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_33 = s_b_11_27!=s_b_11_32 (const) */
    uint8_t s_b_11_33 = ((uint8_t)(s_b_11_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_34 = s_b_11_31!=s_b_11_32 (const) */
    uint8_t s_b_11_34 = ((uint8_t)(s_b_11_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_35 = s_b_11_33&s_b_11_34 (const) */
    uint8_t s_b_11_35 = ((uint8_t)(s_b_11_33 & s_b_11_34));
    /* execute.a64:421 [F] s_b_11_36: If s_b_11_35: Jump b_12 else b_13 (const) */
    if (s_b_11_35) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:422 [D] s_b_12_0 = sym_18182_0_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:422 [D] s_b_12_1: WriteReg 21 = s_b_12_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_12_0);
    /* execute.a64:422 [F] s_b_12_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:423 [F] s_b_13_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:423 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:423 [F] s_b_13_2 = constant u32 3 (const) */
    /* execute.a64:423 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:423 [F] s_b_13_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:423 [F] s_b_13_5 = (u32)s_b_13_4 (const) */
    /* execute.a64:423 [F] s_b_13_6 = constant u32 4 (const) */
    /* execute.a64:423 [F] s_b_13_7 = s_b_13_5==s_b_13_6 (const) */
    uint8_t s_b_13_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_13_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_13_9 = s_b_13_3!=s_b_13_8 (const) */
    uint8_t s_b_13_9 = ((uint8_t)(s_b_13_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_13_10 = s_b_13_7!=s_b_13_8 (const) */
    uint8_t s_b_13_10 = ((uint8_t)(s_b_13_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_13_11 = s_b_13_9&s_b_13_10 (const) */
    uint8_t s_b_13_11 = ((uint8_t)(s_b_13_9 & s_b_13_10));
    /* execute.a64:423 [F] s_b_13_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:423 [F] s_b_13_13 = (u32)s_b_13_12 (const) */
    /* execute.a64:423 [F] s_b_13_14 = constant u32 4 (const) */
    /* execute.a64:423 [F] s_b_13_15 = s_b_13_13==s_b_13_14 (const) */
    uint8_t s_b_13_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_13_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_13_17 = s_b_13_11!=s_b_13_16 (const) */
    uint8_t s_b_13_17 = ((uint8_t)(s_b_13_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_13_18 = s_b_13_15!=s_b_13_16 (const) */
    uint8_t s_b_13_18 = ((uint8_t)(s_b_13_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_13_19 = s_b_13_17&s_b_13_18 (const) */
    uint8_t s_b_13_19 = ((uint8_t)(s_b_13_17 & s_b_13_18));
    /* execute.a64:423 [F] s_b_13_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:423 [F] s_b_13_21 = (u32)s_b_13_20 (const) */
    /* execute.a64:423 [F] s_b_13_22 = constant u32 1 (const) */
    /* execute.a64:423 [F] s_b_13_23 = s_b_13_21==s_b_13_22 (const) */
    uint8_t s_b_13_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_13_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_13_25 = s_b_13_19!=s_b_13_24 (const) */
    uint8_t s_b_13_25 = ((uint8_t)(s_b_13_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_13_26 = s_b_13_23!=s_b_13_24 (const) */
    uint8_t s_b_13_26 = ((uint8_t)(s_b_13_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_13_27 = s_b_13_25&s_b_13_26 (const) */
    uint8_t s_b_13_27 = ((uint8_t)(s_b_13_25 & s_b_13_26));
    /* execute.a64:423 [F] s_b_13_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:423 [F] s_b_13_29 = (u32)s_b_13_28 (const) */
    /* execute.a64:423 [F] s_b_13_30 = constant u32 0 (const) */
    /* execute.a64:423 [F] s_b_13_31 = s_b_13_29==s_b_13_30 (const) */
    uint8_t s_b_13_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_13_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_13_33 = s_b_13_27!=s_b_13_32 (const) */
    uint8_t s_b_13_33 = ((uint8_t)(s_b_13_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_13_34 = s_b_13_31!=s_b_13_32 (const) */
    uint8_t s_b_13_34 = ((uint8_t)(s_b_13_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_13_35 = s_b_13_33&s_b_13_34 (const) */
    uint8_t s_b_13_35 = ((uint8_t)(s_b_13_33 & s_b_13_34));
    /* execute.a64:423 [F] s_b_13_36: If s_b_13_35: Jump b_14 else b_15 (const) */
    if (s_b_13_35) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:424 [D] s_b_14_0 = sym_18182_0_value uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:424 [D] s_b_14_1: WriteReg 22 = s_b_14_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_14_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_14_0);
    /* execute.a64:424 [F] s_b_14_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_13,  */
  fixed_block_b_15: 
  {
    /* execute.a64:425 [F] s_b_15_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:425 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.a64:425 [F] s_b_15_2 = constant u32 3 (const) */
    /* execute.a64:425 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:425 [F] s_b_15_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:425 [F] s_b_15_5 = (u32)s_b_15_4 (const) */
    /* execute.a64:425 [F] s_b_15_6 = constant u32 0 (const) */
    /* execute.a64:425 [F] s_b_15_7 = s_b_15_5==s_b_15_6 (const) */
    uint8_t s_b_15_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_15_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_15_9 = s_b_15_3!=s_b_15_8 (const) */
    uint8_t s_b_15_9 = ((uint8_t)(s_b_15_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_15_10 = s_b_15_7!=s_b_15_8 (const) */
    uint8_t s_b_15_10 = ((uint8_t)(s_b_15_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_15_11 = s_b_15_9&s_b_15_10 (const) */
    uint8_t s_b_15_11 = ((uint8_t)(s_b_15_9 & s_b_15_10));
    /* execute.a64:425 [F] s_b_15_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:425 [F] s_b_15_13 = (u32)s_b_15_12 (const) */
    /* execute.a64:425 [F] s_b_15_14 = constant u32 4 (const) */
    /* execute.a64:425 [F] s_b_15_15 = s_b_15_13==s_b_15_14 (const) */
    uint8_t s_b_15_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_15_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_15_17 = s_b_15_11!=s_b_15_16 (const) */
    uint8_t s_b_15_17 = ((uint8_t)(s_b_15_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_15_18 = s_b_15_15!=s_b_15_16 (const) */
    uint8_t s_b_15_18 = ((uint8_t)(s_b_15_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_15_19 = s_b_15_17&s_b_15_18 (const) */
    uint8_t s_b_15_19 = ((uint8_t)(s_b_15_17 & s_b_15_18));
    /* execute.a64:425 [F] s_b_15_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:425 [F] s_b_15_21 = (u32)s_b_15_20 (const) */
    /* execute.a64:425 [F] s_b_15_22 = constant u32 0 (const) */
    /* execute.a64:425 [F] s_b_15_23 = s_b_15_21==s_b_15_22 (const) */
    uint8_t s_b_15_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_15_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_15_25 = s_b_15_19!=s_b_15_24 (const) */
    uint8_t s_b_15_25 = ((uint8_t)(s_b_15_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_15_26 = s_b_15_23!=s_b_15_24 (const) */
    uint8_t s_b_15_26 = ((uint8_t)(s_b_15_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_15_27 = s_b_15_25&s_b_15_26 (const) */
    uint8_t s_b_15_27 = ((uint8_t)(s_b_15_25 & s_b_15_26));
    /* execute.a64:425 [F] s_b_15_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:425 [F] s_b_15_29 = (u32)s_b_15_28 (const) */
    /* execute.a64:425 [F] s_b_15_30 = constant u32 0 (const) */
    /* execute.a64:425 [F] s_b_15_31 = s_b_15_29==s_b_15_30 (const) */
    uint8_t s_b_15_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_15_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_15_33 = s_b_15_27!=s_b_15_32 (const) */
    uint8_t s_b_15_33 = ((uint8_t)(s_b_15_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_15_34 = s_b_15_31!=s_b_15_32 (const) */
    uint8_t s_b_15_34 = ((uint8_t)(s_b_15_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_15_35 = s_b_15_33&s_b_15_34 (const) */
    uint8_t s_b_15_35 = ((uint8_t)(s_b_15_33 & s_b_15_34));
    /* execute.a64:425 [F] s_b_15_36: If s_b_15_35: Jump b_16 else b_17 (const) */
    if (s_b_15_35) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:426 [D] s_b_16_0 = sym_18182_0_value uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:426 [D] s_b_16_1 = (u32)s_b_16_0 */
    auto s_b_16_1 = emitter.truncate(s_b_16_0, emitter.context().types().u32());
    /* execute.a64:426 [D] s_b_16_2: WriteReg 18 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_16_1, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_16_1);
    /* execute.a64:426 [F] s_b_16_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_17: 
  {
    /* execute.a64:427 [F] s_b_17_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:427 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
    /* execute.a64:427 [F] s_b_17_2 = constant u32 3 (const) */
    /* execute.a64:427 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:427 [F] s_b_17_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:427 [F] s_b_17_5 = (u32)s_b_17_4 (const) */
    /* execute.a64:427 [F] s_b_17_6 = constant u32 0 (const) */
    /* execute.a64:427 [F] s_b_17_7 = s_b_17_5==s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_17_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_17_9 = s_b_17_3!=s_b_17_8 (const) */
    uint8_t s_b_17_9 = ((uint8_t)(s_b_17_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_17_10 = s_b_17_7!=s_b_17_8 (const) */
    uint8_t s_b_17_10 = ((uint8_t)(s_b_17_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_17_11 = s_b_17_9&s_b_17_10 (const) */
    uint8_t s_b_17_11 = ((uint8_t)(s_b_17_9 & s_b_17_10));
    /* execute.a64:427 [F] s_b_17_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:427 [F] s_b_17_13 = (u32)s_b_17_12 (const) */
    /* execute.a64:427 [F] s_b_17_14 = constant u32 4 (const) */
    /* execute.a64:427 [F] s_b_17_15 = s_b_17_13==s_b_17_14 (const) */
    uint8_t s_b_17_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_17_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_17_17 = s_b_17_11!=s_b_17_16 (const) */
    uint8_t s_b_17_17 = ((uint8_t)(s_b_17_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_17_18 = s_b_17_15!=s_b_17_16 (const) */
    uint8_t s_b_17_18 = ((uint8_t)(s_b_17_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_17_19 = s_b_17_17&s_b_17_18 (const) */
    uint8_t s_b_17_19 = ((uint8_t)(s_b_17_17 & s_b_17_18));
    /* execute.a64:427 [F] s_b_17_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:427 [F] s_b_17_21 = (u32)s_b_17_20 (const) */
    /* execute.a64:427 [F] s_b_17_22 = constant u32 0 (const) */
    /* execute.a64:427 [F] s_b_17_23 = s_b_17_21==s_b_17_22 (const) */
    uint8_t s_b_17_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_17_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_17_25 = s_b_17_19!=s_b_17_24 (const) */
    uint8_t s_b_17_25 = ((uint8_t)(s_b_17_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_17_26 = s_b_17_23!=s_b_17_24 (const) */
    uint8_t s_b_17_26 = ((uint8_t)(s_b_17_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_17_27 = s_b_17_25&s_b_17_26 (const) */
    uint8_t s_b_17_27 = ((uint8_t)(s_b_17_25 & s_b_17_26));
    /* execute.a64:427 [F] s_b_17_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:427 [F] s_b_17_29 = (u32)s_b_17_28 (const) */
    /* execute.a64:427 [F] s_b_17_30 = constant u32 1 (const) */
    /* execute.a64:427 [F] s_b_17_31 = s_b_17_29==s_b_17_30 (const) */
    uint8_t s_b_17_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_17_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_17_33 = s_b_17_27!=s_b_17_32 (const) */
    uint8_t s_b_17_33 = ((uint8_t)(s_b_17_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_17_34 = s_b_17_31!=s_b_17_32 (const) */
    uint8_t s_b_17_34 = ((uint8_t)(s_b_17_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_17_35 = s_b_17_33&s_b_17_34 (const) */
    uint8_t s_b_17_35 = ((uint8_t)(s_b_17_33 & s_b_17_34));
    /* execute.a64:427 [F] s_b_17_36: If s_b_17_35: Jump b_18 else b_19 (const) */
    if (s_b_17_35) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:428 [D] s_b_18_0 = sym_18182_0_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:428 [D] s_b_18_1: WriteReg 17 = s_b_18_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_18_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_18_0);
    /* execute.a64:428 [F] s_b_18_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_17,  */
  fixed_block_b_19: 
  {
    /* execute.a64:429 [F] s_b_19_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:429 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:429 [F] s_b_19_2 = constant u32 2 (const) */
    /* execute.a64:429 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)2ULL));
    /* execute.a64:429 [F] s_b_19_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:429 [F] s_b_19_5 = (u32)s_b_19_4 (const) */
    /* execute.a64:429 [F] s_b_19_6 = constant u32 0 (const) */
    /* execute.a64:429 [F] s_b_19_7 = s_b_19_5==s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_19_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_19_9 = s_b_19_3!=s_b_19_8 (const) */
    uint8_t s_b_19_9 = ((uint8_t)(s_b_19_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_19_10 = s_b_19_7!=s_b_19_8 (const) */
    uint8_t s_b_19_10 = ((uint8_t)(s_b_19_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_19_11 = s_b_19_9&s_b_19_10 (const) */
    uint8_t s_b_19_11 = ((uint8_t)(s_b_19_9 & s_b_19_10));
    /* execute.a64:429 [F] s_b_19_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:429 [F] s_b_19_13 = (u32)s_b_19_12 (const) */
    /* execute.a64:429 [F] s_b_19_14 = constant u32 0 (const) */
    /* execute.a64:429 [F] s_b_19_15 = s_b_19_13==s_b_19_14 (const) */
    uint8_t s_b_19_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_19_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_19_17 = s_b_19_11!=s_b_19_16 (const) */
    uint8_t s_b_19_17 = ((uint8_t)(s_b_19_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_19_18 = s_b_19_15!=s_b_19_16 (const) */
    uint8_t s_b_19_18 = ((uint8_t)(s_b_19_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_19_19 = s_b_19_17&s_b_19_18 (const) */
    uint8_t s_b_19_19 = ((uint8_t)(s_b_19_17 & s_b_19_18));
    /* execute.a64:429 [F] s_b_19_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:429 [F] s_b_19_21 = (u32)s_b_19_20 (const) */
    /* execute.a64:429 [F] s_b_19_22 = constant u32 2 (const) */
    /* execute.a64:429 [F] s_b_19_23 = s_b_19_21==s_b_19_22 (const) */
    uint8_t s_b_19_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_19_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_19_25 = s_b_19_19!=s_b_19_24 (const) */
    uint8_t s_b_19_25 = ((uint8_t)(s_b_19_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_19_26 = s_b_19_23!=s_b_19_24 (const) */
    uint8_t s_b_19_26 = ((uint8_t)(s_b_19_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_19_27 = s_b_19_25&s_b_19_26 (const) */
    uint8_t s_b_19_27 = ((uint8_t)(s_b_19_25 & s_b_19_26));
    /* execute.a64:429 [F] s_b_19_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:429 [F] s_b_19_29 = (u32)s_b_19_28 (const) */
    /* execute.a64:429 [F] s_b_19_30 = constant u32 2 (const) */
    /* execute.a64:429 [F] s_b_19_31 = s_b_19_29==s_b_19_30 (const) */
    uint8_t s_b_19_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_19_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_19_33 = s_b_19_27!=s_b_19_32 (const) */
    uint8_t s_b_19_33 = ((uint8_t)(s_b_19_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_19_34 = s_b_19_31!=s_b_19_32 (const) */
    uint8_t s_b_19_34 = ((uint8_t)(s_b_19_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_19_35 = s_b_19_33&s_b_19_34 (const) */
    uint8_t s_b_19_35 = ((uint8_t)(s_b_19_33 & s_b_19_34));
    /* execute.a64:429 [F] s_b_19_36: If s_b_19_35: Jump b_20 else b_21 (const) */
    if (s_b_19_35) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_19,  */
  fixed_block_b_20: 
  {
    /* execute.a64:430 [D] s_b_20_0 = sym_18182_0_value uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:430 [D] s_b_20_1 = (u32)s_b_20_0 */
    auto s_b_20_1 = emitter.truncate(s_b_20_0, emitter.context().types().u32());
    /* execute.a64:430 [D] s_b_20_2: WriteReg 24 = s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1428), s_b_20_1, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1428), s_b_20_1);
    /* execute.a64:431 [F] s_b_20_3 = constant u32 2 (const) */
    /* execute.a64:431 [F] s_b_20_4 = constant u64 1 (const) */
    /* execute.a64:431 [D] s_b_20_5 = s_b_20_0&s_b_20_4 */
    auto s_b_20_5 = emitter.bitwise_and(s_b_20_0, emitter.const_u64((uint64_t)1ULL));
    /* execute.a64:431 [D] s_b_20_6 = (u32)s_b_20_5 */
    auto s_b_20_6 = emitter.truncate(s_b_20_5, emitter.context().types().u32());
    /* execute.a64:431 [D] s_b_20_7 = __builtin_set_feature */
    emitter.set_feature((uint32_t)2ULL, s_b_20_6);
    /* execute.a64:430 [F] s_b_20_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_19,  */
  fixed_block_b_21: 
  {
    /* execute.a64:432 [F] s_b_21_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:432 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:432 [F] s_b_21_2 = constant u32 3 (const) */
    /* execute.a64:432 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:432 [F] s_b_21_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:432 [F] s_b_21_5 = (u32)s_b_21_4 (const) */
    /* execute.a64:432 [F] s_b_21_6 = constant u32 0 (const) */
    /* execute.a64:432 [F] s_b_21_7 = s_b_21_5==s_b_21_6 (const) */
    uint8_t s_b_21_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_21_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_21_9 = s_b_21_3!=s_b_21_8 (const) */
    uint8_t s_b_21_9 = ((uint8_t)(s_b_21_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_21_10 = s_b_21_7!=s_b_21_8 (const) */
    uint8_t s_b_21_10 = ((uint8_t)(s_b_21_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_21_11 = s_b_21_9&s_b_21_10 (const) */
    uint8_t s_b_21_11 = ((uint8_t)(s_b_21_9 & s_b_21_10));
    /* execute.a64:432 [F] s_b_21_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:432 [F] s_b_21_13 = (u32)s_b_21_12 (const) */
    /* execute.a64:432 [F] s_b_21_14 = constant u32 2 (const) */
    /* execute.a64:432 [F] s_b_21_15 = s_b_21_13==s_b_21_14 (const) */
    uint8_t s_b_21_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_21_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_21_17 = s_b_21_11!=s_b_21_16 (const) */
    uint8_t s_b_21_17 = ((uint8_t)(s_b_21_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_21_18 = s_b_21_15!=s_b_21_16 (const) */
    uint8_t s_b_21_18 = ((uint8_t)(s_b_21_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_21_19 = s_b_21_17&s_b_21_18 (const) */
    uint8_t s_b_21_19 = ((uint8_t)(s_b_21_17 & s_b_21_18));
    /* execute.a64:432 [F] s_b_21_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:432 [F] s_b_21_21 = (u32)s_b_21_20 (const) */
    /* execute.a64:432 [F] s_b_21_22 = constant u32 0 (const) */
    /* execute.a64:432 [F] s_b_21_23 = s_b_21_21==s_b_21_22 (const) */
    uint8_t s_b_21_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_21_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_21_25 = s_b_21_19!=s_b_21_24 (const) */
    uint8_t s_b_21_25 = ((uint8_t)(s_b_21_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_21_26 = s_b_21_23!=s_b_21_24 (const) */
    uint8_t s_b_21_26 = ((uint8_t)(s_b_21_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_21_27 = s_b_21_25&s_b_21_26 (const) */
    uint8_t s_b_21_27 = ((uint8_t)(s_b_21_25 & s_b_21_26));
    /* execute.a64:432 [F] s_b_21_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:432 [F] s_b_21_29 = (u32)s_b_21_28 (const) */
    /* execute.a64:432 [F] s_b_21_30 = constant u32 2 (const) */
    /* execute.a64:432 [F] s_b_21_31 = s_b_21_29==s_b_21_30 (const) */
    uint8_t s_b_21_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_21_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_21_33 = s_b_21_27!=s_b_21_32 (const) */
    uint8_t s_b_21_33 = ((uint8_t)(s_b_21_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_21_34 = s_b_21_31!=s_b_21_32 (const) */
    uint8_t s_b_21_34 = ((uint8_t)(s_b_21_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_21_35 = s_b_21_33&s_b_21_34 (const) */
    uint8_t s_b_21_35 = ((uint8_t)(s_b_21_33 & s_b_21_34));
    /* execute.a64:432 [F] s_b_21_36: If s_b_21_35: Jump b_22 else b_23 (const) */
    if (s_b_21_35) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:433 [D] s_b_22_0 = sym_18182_0_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:433 [D] s_b_22_1: WriteReg 12 = s_b_22_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1328), s_b_22_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1328), s_b_22_0);
    /* execute.a64:434 [F] s_b_22_2 = constant u32 3 (const) */
    /* execute.a64:434 [F] s_b_22_3 = constant u64 16 (const) */
    /* execute.a64:434 [D] s_b_22_4 = s_b_22_0>>s_b_22_3 */
    auto s_b_22_4 = emitter.shr(s_b_22_0, emitter.const_u64((uint64_t)22ULL));
    /* execute.a64:434 [F] s_b_22_5 = constant u64 1 (const) */
    /* execute.a64:434 [D] s_b_22_6 = s_b_22_4&s_b_22_5 */
    auto s_b_22_6 = emitter.bitwise_and(s_b_22_4, emitter.const_u64((uint64_t)1ULL));
    /* execute.a64:434 [D] s_b_22_7 = (u32)s_b_22_6 */
    auto s_b_22_7 = emitter.truncate(s_b_22_6, emitter.context().types().u32());
    /* execute.a64:434 [D] s_b_22_8 = __builtin_set_feature */
    emitter.set_feature((uint32_t)3ULL, s_b_22_7);
    /* execute.a64:433 [F] s_b_22_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_21,  */
  fixed_block_b_23: 
  {
    /* execute.a64:435 [F] s_b_23_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:435 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:435 [F] s_b_23_2 = constant u32 3 (const) */
    /* execute.a64:435 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:435 [F] s_b_23_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:435 [F] s_b_23_5 = (u32)s_b_23_4 (const) */
    /* execute.a64:435 [F] s_b_23_6 = constant u32 0 (const) */
    /* execute.a64:435 [F] s_b_23_7 = s_b_23_5==s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_23_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_23_9 = s_b_23_3!=s_b_23_8 (const) */
    uint8_t s_b_23_9 = ((uint8_t)(s_b_23_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_23_10 = s_b_23_7!=s_b_23_8 (const) */
    uint8_t s_b_23_10 = ((uint8_t)(s_b_23_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_23_11 = s_b_23_9&s_b_23_10 (const) */
    uint8_t s_b_23_11 = ((uint8_t)(s_b_23_9 & s_b_23_10));
    /* execute.a64:435 [F] s_b_23_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:435 [F] s_b_23_13 = (u32)s_b_23_12 (const) */
    /* execute.a64:435 [F] s_b_23_14 = constant u32 d (const) */
    /* execute.a64:435 [F] s_b_23_15 = s_b_23_13==s_b_23_14 (const) */
    uint8_t s_b_23_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)13ULL));
    /* ???:4294967295 [F] s_b_23_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_23_17 = s_b_23_11!=s_b_23_16 (const) */
    uint8_t s_b_23_17 = ((uint8_t)(s_b_23_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_23_18 = s_b_23_15!=s_b_23_16 (const) */
    uint8_t s_b_23_18 = ((uint8_t)(s_b_23_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_23_19 = s_b_23_17&s_b_23_18 (const) */
    uint8_t s_b_23_19 = ((uint8_t)(s_b_23_17 & s_b_23_18));
    /* execute.a64:435 [F] s_b_23_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:435 [F] s_b_23_21 = (u32)s_b_23_20 (const) */
    /* execute.a64:435 [F] s_b_23_22 = constant u32 0 (const) */
    /* execute.a64:435 [F] s_b_23_23 = s_b_23_21==s_b_23_22 (const) */
    uint8_t s_b_23_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_23_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_23_25 = s_b_23_19!=s_b_23_24 (const) */
    uint8_t s_b_23_25 = ((uint8_t)(s_b_23_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_23_26 = s_b_23_23!=s_b_23_24 (const) */
    uint8_t s_b_23_26 = ((uint8_t)(s_b_23_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_23_27 = s_b_23_25&s_b_23_26 (const) */
    uint8_t s_b_23_27 = ((uint8_t)(s_b_23_25 & s_b_23_26));
    /* execute.a64:435 [F] s_b_23_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:435 [F] s_b_23_29 = (u32)s_b_23_28 (const) */
    /* execute.a64:435 [F] s_b_23_30 = constant u32 1 (const) */
    /* execute.a64:435 [F] s_b_23_31 = s_b_23_29==s_b_23_30 (const) */
    uint8_t s_b_23_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_23_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_23_33 = s_b_23_27!=s_b_23_32 (const) */
    uint8_t s_b_23_33 = ((uint8_t)(s_b_23_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_23_34 = s_b_23_31!=s_b_23_32 (const) */
    uint8_t s_b_23_34 = ((uint8_t)(s_b_23_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_23_35 = s_b_23_33&s_b_23_34 (const) */
    uint8_t s_b_23_35 = ((uint8_t)(s_b_23_33 & s_b_23_34));
    /* execute.a64:435 [F] s_b_23_36: If s_b_23_35: Jump b_24 else b_25 (const) */
    if (s_b_23_35) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:436 [D] s_b_24_0 = sym_18182_0_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:436 [D] s_b_24_1 = (u32)s_b_24_0 */
    auto s_b_24_1 = emitter.truncate(s_b_24_0, emitter.context().types().u32());
    /* execute.a64:436 [D] s_b_24_2: WriteReg 25 = s_b_24_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1432), s_b_24_1, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1432), s_b_24_1);
    /* execute.a64:436 [F] s_b_24_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_23,  */
  fixed_block_b_25: 
  {
    /* execute.a64:437 [F] s_b_25_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:437 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:437 [F] s_b_25_2 = constant u32 3 (const) */
    /* execute.a64:437 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:437 [F] s_b_25_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:437 [F] s_b_25_5 = (u32)s_b_25_4 (const) */
    /* execute.a64:437 [F] s_b_25_6 = constant u32 3 (const) */
    /* execute.a64:437 [F] s_b_25_7 = s_b_25_5==s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_25_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_25_9 = s_b_25_3!=s_b_25_8 (const) */
    uint8_t s_b_25_9 = ((uint8_t)(s_b_25_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_25_10 = s_b_25_7!=s_b_25_8 (const) */
    uint8_t s_b_25_10 = ((uint8_t)(s_b_25_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_25_11 = s_b_25_9&s_b_25_10 (const) */
    uint8_t s_b_25_11 = ((uint8_t)(s_b_25_9 & s_b_25_10));
    /* execute.a64:437 [F] s_b_25_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:437 [F] s_b_25_13 = (u32)s_b_25_12 (const) */
    /* execute.a64:437 [F] s_b_25_14 = constant u32 d (const) */
    /* execute.a64:437 [F] s_b_25_15 = s_b_25_13==s_b_25_14 (const) */
    uint8_t s_b_25_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)13ULL));
    /* ???:4294967295 [F] s_b_25_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_25_17 = s_b_25_11!=s_b_25_16 (const) */
    uint8_t s_b_25_17 = ((uint8_t)(s_b_25_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_25_18 = s_b_25_15!=s_b_25_16 (const) */
    uint8_t s_b_25_18 = ((uint8_t)(s_b_25_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_25_19 = s_b_25_17&s_b_25_18 (const) */
    uint8_t s_b_25_19 = ((uint8_t)(s_b_25_17 & s_b_25_18));
    /* execute.a64:437 [F] s_b_25_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:437 [F] s_b_25_21 = (u32)s_b_25_20 (const) */
    /* execute.a64:437 [F] s_b_25_22 = constant u32 0 (const) */
    /* execute.a64:437 [F] s_b_25_23 = s_b_25_21==s_b_25_22 (const) */
    uint8_t s_b_25_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_25_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_25_25 = s_b_25_19!=s_b_25_24 (const) */
    uint8_t s_b_25_25 = ((uint8_t)(s_b_25_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_25_26 = s_b_25_23!=s_b_25_24 (const) */
    uint8_t s_b_25_26 = ((uint8_t)(s_b_25_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_25_27 = s_b_25_25&s_b_25_26 (const) */
    uint8_t s_b_25_27 = ((uint8_t)(s_b_25_25 & s_b_25_26));
    /* execute.a64:437 [F] s_b_25_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:437 [F] s_b_25_29 = (u32)s_b_25_28 (const) */
    /* execute.a64:437 [F] s_b_25_30 = constant u32 2 (const) */
    /* execute.a64:437 [F] s_b_25_31 = s_b_25_29==s_b_25_30 (const) */
    uint8_t s_b_25_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_25_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_25_33 = s_b_25_27!=s_b_25_32 (const) */
    uint8_t s_b_25_33 = ((uint8_t)(s_b_25_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_25_34 = s_b_25_31!=s_b_25_32 (const) */
    uint8_t s_b_25_34 = ((uint8_t)(s_b_25_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_25_35 = s_b_25_33&s_b_25_34 (const) */
    uint8_t s_b_25_35 = ((uint8_t)(s_b_25_33 & s_b_25_34));
    /* execute.a64:437 [F] s_b_25_36: If s_b_25_35: Jump b_26 else b_27 (const) */
    if (s_b_25_35) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:438 [D] s_b_26_0 = sym_18182_0_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:438 [D] s_b_26_1: WriteReg 14 = s_b_26_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1344), s_b_26_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1344), s_b_26_0);
    /* execute.a64:438 [F] s_b_26_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_25,  */
  fixed_block_b_27: 
  {
    /* execute.a64:439 [F] s_b_27_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:439 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
    /* execute.a64:439 [F] s_b_27_2 = constant u32 3 (const) */
    /* execute.a64:439 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:439 [F] s_b_27_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:439 [F] s_b_27_5 = (u32)s_b_27_4 (const) */
    /* execute.a64:439 [F] s_b_27_6 = constant u32 0 (const) */
    /* execute.a64:439 [F] s_b_27_7 = s_b_27_5==s_b_27_6 (const) */
    uint8_t s_b_27_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_27_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_27_9 = s_b_27_3!=s_b_27_8 (const) */
    uint8_t s_b_27_9 = ((uint8_t)(s_b_27_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_27_10 = s_b_27_7!=s_b_27_8 (const) */
    uint8_t s_b_27_10 = ((uint8_t)(s_b_27_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_27_11 = s_b_27_9&s_b_27_10 (const) */
    uint8_t s_b_27_11 = ((uint8_t)(s_b_27_9 & s_b_27_10));
    /* execute.a64:439 [F] s_b_27_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:439 [F] s_b_27_13 = (u32)s_b_27_12 (const) */
    /* execute.a64:439 [F] s_b_27_14 = constant u32 d (const) */
    /* execute.a64:439 [F] s_b_27_15 = s_b_27_13==s_b_27_14 (const) */
    uint8_t s_b_27_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)13ULL));
    /* ???:4294967295 [F] s_b_27_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_27_17 = s_b_27_11!=s_b_27_16 (const) */
    uint8_t s_b_27_17 = ((uint8_t)(s_b_27_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_27_18 = s_b_27_15!=s_b_27_16 (const) */
    uint8_t s_b_27_18 = ((uint8_t)(s_b_27_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_27_19 = s_b_27_17&s_b_27_18 (const) */
    uint8_t s_b_27_19 = ((uint8_t)(s_b_27_17 & s_b_27_18));
    /* execute.a64:439 [F] s_b_27_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:439 [F] s_b_27_21 = (u32)s_b_27_20 (const) */
    /* execute.a64:439 [F] s_b_27_22 = constant u32 0 (const) */
    /* execute.a64:439 [F] s_b_27_23 = s_b_27_21==s_b_27_22 (const) */
    uint8_t s_b_27_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_27_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_27_25 = s_b_27_19!=s_b_27_24 (const) */
    uint8_t s_b_27_25 = ((uint8_t)(s_b_27_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_27_26 = s_b_27_23!=s_b_27_24 (const) */
    uint8_t s_b_27_26 = ((uint8_t)(s_b_27_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_27_27 = s_b_27_25&s_b_27_26 (const) */
    uint8_t s_b_27_27 = ((uint8_t)(s_b_27_25 & s_b_27_26));
    /* execute.a64:439 [F] s_b_27_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:439 [F] s_b_27_29 = (u32)s_b_27_28 (const) */
    /* execute.a64:439 [F] s_b_27_30 = constant u32 4 (const) */
    /* execute.a64:439 [F] s_b_27_31 = s_b_27_29==s_b_27_30 (const) */
    uint8_t s_b_27_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_27_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_27_33 = s_b_27_27!=s_b_27_32 (const) */
    uint8_t s_b_27_33 = ((uint8_t)(s_b_27_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_27_34 = s_b_27_31!=s_b_27_32 (const) */
    uint8_t s_b_27_34 = ((uint8_t)(s_b_27_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_27_35 = s_b_27_33&s_b_27_34 (const) */
    uint8_t s_b_27_35 = ((uint8_t)(s_b_27_33 & s_b_27_34));
    /* execute.a64:439 [F] s_b_27_36: If s_b_27_35: Jump b_28 else b_29 (const) */
    if (s_b_27_35) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:440 [D] s_b_28_0 = sym_18182_0_value uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:440 [D] s_b_28_1: WriteReg 15 = s_b_28_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1352), s_b_28_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1352), s_b_28_0);
    /* execute.a64:440 [F] s_b_28_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_27,  */
  fixed_block_b_29: 
  {
    /* execute.a64:441 [F] s_b_29_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:441 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
    /* execute.a64:441 [F] s_b_29_2 = constant u32 3 (const) */
    /* execute.a64:441 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:441 [F] s_b_29_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:441 [F] s_b_29_5 = (u32)s_b_29_4 (const) */
    /* execute.a64:441 [F] s_b_29_6 = constant u32 3 (const) */
    /* execute.a64:441 [F] s_b_29_7 = s_b_29_5==s_b_29_6 (const) */
    uint8_t s_b_29_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_29_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_29_9 = s_b_29_3!=s_b_29_8 (const) */
    uint8_t s_b_29_9 = ((uint8_t)(s_b_29_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_29_10 = s_b_29_7!=s_b_29_8 (const) */
    uint8_t s_b_29_10 = ((uint8_t)(s_b_29_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_29_11 = s_b_29_9&s_b_29_10 (const) */
    uint8_t s_b_29_11 = ((uint8_t)(s_b_29_9 & s_b_29_10));
    /* execute.a64:441 [F] s_b_29_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:441 [F] s_b_29_13 = (u32)s_b_29_12 (const) */
    /* execute.a64:441 [F] s_b_29_14 = constant u32 d (const) */
    /* execute.a64:441 [F] s_b_29_15 = s_b_29_13==s_b_29_14 (const) */
    uint8_t s_b_29_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)13ULL));
    /* ???:4294967295 [F] s_b_29_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_29_17 = s_b_29_11!=s_b_29_16 (const) */
    uint8_t s_b_29_17 = ((uint8_t)(s_b_29_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_29_18 = s_b_29_15!=s_b_29_16 (const) */
    uint8_t s_b_29_18 = ((uint8_t)(s_b_29_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_29_19 = s_b_29_17&s_b_29_18 (const) */
    uint8_t s_b_29_19 = ((uint8_t)(s_b_29_17 & s_b_29_18));
    /* execute.a64:441 [F] s_b_29_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:441 [F] s_b_29_21 = (u32)s_b_29_20 (const) */
    /* execute.a64:441 [F] s_b_29_22 = constant u32 0 (const) */
    /* execute.a64:441 [F] s_b_29_23 = s_b_29_21==s_b_29_22 (const) */
    uint8_t s_b_29_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_29_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_29_25 = s_b_29_19!=s_b_29_24 (const) */
    uint8_t s_b_29_25 = ((uint8_t)(s_b_29_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_29_26 = s_b_29_23!=s_b_29_24 (const) */
    uint8_t s_b_29_26 = ((uint8_t)(s_b_29_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_29_27 = s_b_29_25&s_b_29_26 (const) */
    uint8_t s_b_29_27 = ((uint8_t)(s_b_29_25 & s_b_29_26));
    /* execute.a64:441 [F] s_b_29_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:441 [F] s_b_29_29 = (u32)s_b_29_28 (const) */
    /* execute.a64:441 [F] s_b_29_30 = constant u32 3 (const) */
    /* execute.a64:441 [F] s_b_29_31 = s_b_29_29==s_b_29_30 (const) */
    uint8_t s_b_29_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_29_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_29_33 = s_b_29_27!=s_b_29_32 (const) */
    uint8_t s_b_29_33 = ((uint8_t)(s_b_29_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_29_34 = s_b_29_31!=s_b_29_32 (const) */
    uint8_t s_b_29_34 = ((uint8_t)(s_b_29_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_29_35 = s_b_29_33&s_b_29_34 (const) */
    uint8_t s_b_29_35 = ((uint8_t)(s_b_29_33 & s_b_29_34));
    /* execute.a64:441 [F] s_b_29_36: If s_b_29_35: Jump b_30 else b_31 (const) */
    if (s_b_29_35) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_29,  */
  fixed_block_b_30: 
  {
    /* execute.a64:442 [D] s_b_30_0 = sym_18182_0_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:442 [D] s_b_30_1: WriteReg 16 = s_b_30_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1360), s_b_30_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1360), s_b_30_0);
    /* execute.a64:442 [F] s_b_30_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_29,  */
  fixed_block_b_31: 
  {
    /* execute.a64:443 [F] s_b_31_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:443 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
    /* execute.a64:443 [F] s_b_31_2 = constant u32 3 (const) */
    /* execute.a64:443 [F] s_b_31_3 = s_b_31_1==s_b_31_2 (const) */
    uint8_t s_b_31_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:443 [F] s_b_31_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:443 [F] s_b_31_5 = (u32)s_b_31_4 (const) */
    /* execute.a64:443 [F] s_b_31_6 = constant u32 3 (const) */
    /* execute.a64:443 [F] s_b_31_7 = s_b_31_5==s_b_31_6 (const) */
    uint8_t s_b_31_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_31_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_31_9 = s_b_31_3!=s_b_31_8 (const) */
    uint8_t s_b_31_9 = ((uint8_t)(s_b_31_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_31_10 = s_b_31_7!=s_b_31_8 (const) */
    uint8_t s_b_31_10 = ((uint8_t)(s_b_31_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_31_11 = s_b_31_9&s_b_31_10 (const) */
    uint8_t s_b_31_11 = ((uint8_t)(s_b_31_9 & s_b_31_10));
    /* execute.a64:443 [F] s_b_31_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:443 [F] s_b_31_13 = (u32)s_b_31_12 (const) */
    /* execute.a64:443 [F] s_b_31_14 = constant u32 4 (const) */
    /* execute.a64:443 [F] s_b_31_15 = s_b_31_13==s_b_31_14 (const) */
    uint8_t s_b_31_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_31_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_31_17 = s_b_31_11!=s_b_31_16 (const) */
    uint8_t s_b_31_17 = ((uint8_t)(s_b_31_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_31_18 = s_b_31_15!=s_b_31_16 (const) */
    uint8_t s_b_31_18 = ((uint8_t)(s_b_31_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_31_19 = s_b_31_17&s_b_31_18 (const) */
    uint8_t s_b_31_19 = ((uint8_t)(s_b_31_17 & s_b_31_18));
    /* execute.a64:443 [F] s_b_31_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:443 [F] s_b_31_21 = (u32)s_b_31_20 (const) */
    /* execute.a64:443 [F] s_b_31_22 = constant u32 2 (const) */
    /* execute.a64:443 [F] s_b_31_23 = s_b_31_21==s_b_31_22 (const) */
    uint8_t s_b_31_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_31_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_31_25 = s_b_31_19!=s_b_31_24 (const) */
    uint8_t s_b_31_25 = ((uint8_t)(s_b_31_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_31_26 = s_b_31_23!=s_b_31_24 (const) */
    uint8_t s_b_31_26 = ((uint8_t)(s_b_31_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_31_27 = s_b_31_25&s_b_31_26 (const) */
    uint8_t s_b_31_27 = ((uint8_t)(s_b_31_25 & s_b_31_26));
    /* execute.a64:443 [F] s_b_31_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:443 [F] s_b_31_29 = (u32)s_b_31_28 (const) */
    /* execute.a64:443 [F] s_b_31_30 = constant u32 0 (const) */
    /* execute.a64:443 [F] s_b_31_31 = s_b_31_29==s_b_31_30 (const) */
    uint8_t s_b_31_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_31_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_31_33 = s_b_31_27!=s_b_31_32 (const) */
    uint8_t s_b_31_33 = ((uint8_t)(s_b_31_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_31_34 = s_b_31_31!=s_b_31_32 (const) */
    uint8_t s_b_31_34 = ((uint8_t)(s_b_31_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_31_35 = s_b_31_33&s_b_31_34 (const) */
    uint8_t s_b_31_35 = ((uint8_t)(s_b_31_33 & s_b_31_34));
    /* execute.a64:443 [F] s_b_31_36: If s_b_31_35: Jump b_32 else b_33 (const) */
    if (s_b_31_35) 
    {
      goto fixed_block_b_32;
    }
    else 
    {
      goto fixed_block_b_33;
    }
  }
  /* b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:446 [D] s_b_32_0 = sym_18182_0_value uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:446 [D] s_b_32_1 = (u32)s_b_32_0 */
    auto s_b_32_1 = emitter.truncate(s_b_32_0, emitter.context().types().u32());
    /* execute.a64:446 [F] s_b_32_2 = constant u32 80000000 (const) */
    /* execute.a64:446 [D] s_b_32_3 = s_b_32_1&s_b_32_2 */
    auto s_b_32_3 = emitter.bitwise_and(s_b_32_1, emitter.const_u32((uint32_t)2147483648ULL));
    /* execute.a64:446 [F] s_b_32_4 = constant u32 80000000 (const) */
    /* execute.a64:446 [D] s_b_32_5 = s_b_32_3==s_b_32_4 */
    auto s_b_32_5 = emitter.cmp_eq(s_b_32_3, emitter.const_u32((uint32_t)2147483648ULL));
    /* execute.a64:446 [D] s_b_32_6: WriteReg 1 = s_b_32_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), s_b_32_5, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1296), s_b_32_5);
    /* execute.a64:447 [D] s_b_32_7 = (u32)s_b_32_0 */
    auto s_b_32_7 = emitter.truncate(s_b_32_0, emitter.context().types().u32());
    /* execute.a64:447 [F] s_b_32_8 = constant u32 40000000 (const) */
    /* execute.a64:447 [D] s_b_32_9 = s_b_32_7&s_b_32_8 */
    auto s_b_32_9 = emitter.bitwise_and(s_b_32_7, emitter.const_u32((uint32_t)1073741824ULL));
    /* execute.a64:447 [F] s_b_32_10 = constant u32 40000000 (const) */
    /* execute.a64:447 [D] s_b_32_11 = s_b_32_9==s_b_32_10 */
    auto s_b_32_11 = emitter.cmp_eq(s_b_32_9, emitter.const_u32((uint32_t)1073741824ULL));
    /* execute.a64:447 [D] s_b_32_12: WriteReg 2 = s_b_32_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), s_b_32_11, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1297), s_b_32_11);
    /* execute.a64:448 [D] s_b_32_13 = (u32)s_b_32_0 */
    auto s_b_32_13 = emitter.truncate(s_b_32_0, emitter.context().types().u32());
    /* execute.a64:448 [F] s_b_32_14 = constant u32 20000000 (const) */
    /* execute.a64:448 [D] s_b_32_15 = s_b_32_13&s_b_32_14 */
    auto s_b_32_15 = emitter.bitwise_and(s_b_32_13, emitter.const_u32((uint32_t)536870912ULL));
    /* execute.a64:448 [F] s_b_32_16 = constant u32 20000000 (const) */
    /* execute.a64:448 [D] s_b_32_17 = s_b_32_15==s_b_32_16 */
    auto s_b_32_17 = emitter.cmp_eq(s_b_32_15, emitter.const_u32((uint32_t)536870912ULL));
    /* execute.a64:448 [D] s_b_32_18: WriteReg 3 = s_b_32_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), s_b_32_17, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), s_b_32_17);
    /* execute.a64:449 [D] s_b_32_19 = (u32)s_b_32_0 */
    auto s_b_32_19 = emitter.truncate(s_b_32_0, emitter.context().types().u32());
    /* execute.a64:449 [F] s_b_32_20 = constant u32 10000000 (const) */
    /* execute.a64:449 [D] s_b_32_21 = s_b_32_19&s_b_32_20 */
    auto s_b_32_21 = emitter.bitwise_and(s_b_32_19, emitter.const_u32((uint32_t)268435456ULL));
    /* execute.a64:449 [F] s_b_32_22 = constant u32 10000000 (const) */
    /* execute.a64:449 [D] s_b_32_23 = s_b_32_21==s_b_32_22 */
    auto s_b_32_23 = emitter.cmp_eq(s_b_32_21, emitter.const_u32((uint32_t)268435456ULL));
    /* execute.a64:449 [D] s_b_32_24: WriteReg 4 = s_b_32_23 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), s_b_32_23, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), s_b_32_23);
    /* execute.a64:446 [F] s_b_32_25: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_31,  */
  fixed_block_b_33: 
  {
    /* execute.a64:450 [F] s_b_33_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:450 [F] s_b_33_1 = (u32)s_b_33_0 (const) */
    /* execute.a64:450 [F] s_b_33_2 = constant u32 3 (const) */
    /* execute.a64:450 [F] s_b_33_3 = s_b_33_1==s_b_33_2 (const) */
    uint8_t s_b_33_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:450 [F] s_b_33_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:450 [F] s_b_33_5 = (u32)s_b_33_4 (const) */
    /* execute.a64:450 [F] s_b_33_6 = constant u32 3 (const) */
    /* execute.a64:450 [F] s_b_33_7 = s_b_33_5==s_b_33_6 (const) */
    uint8_t s_b_33_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_33_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_33_9 = s_b_33_3!=s_b_33_8 (const) */
    uint8_t s_b_33_9 = ((uint8_t)(s_b_33_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_33_10 = s_b_33_7!=s_b_33_8 (const) */
    uint8_t s_b_33_10 = ((uint8_t)(s_b_33_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_33_11 = s_b_33_9&s_b_33_10 (const) */
    uint8_t s_b_33_11 = ((uint8_t)(s_b_33_9 & s_b_33_10));
    /* execute.a64:450 [F] s_b_33_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:450 [F] s_b_33_13 = (u32)s_b_33_12 (const) */
    /* execute.a64:450 [F] s_b_33_14 = constant u32 4 (const) */
    /* execute.a64:450 [F] s_b_33_15 = s_b_33_13==s_b_33_14 (const) */
    uint8_t s_b_33_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_33_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_33_17 = s_b_33_11!=s_b_33_16 (const) */
    uint8_t s_b_33_17 = ((uint8_t)(s_b_33_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_33_18 = s_b_33_15!=s_b_33_16 (const) */
    uint8_t s_b_33_18 = ((uint8_t)(s_b_33_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_33_19 = s_b_33_17&s_b_33_18 (const) */
    uint8_t s_b_33_19 = ((uint8_t)(s_b_33_17 & s_b_33_18));
    /* execute.a64:450 [F] s_b_33_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:450 [F] s_b_33_21 = (u32)s_b_33_20 (const) */
    /* execute.a64:450 [F] s_b_33_22 = constant u32 2 (const) */
    /* execute.a64:450 [F] s_b_33_23 = s_b_33_21==s_b_33_22 (const) */
    uint8_t s_b_33_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_33_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_33_25 = s_b_33_19!=s_b_33_24 (const) */
    uint8_t s_b_33_25 = ((uint8_t)(s_b_33_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_33_26 = s_b_33_23!=s_b_33_24 (const) */
    uint8_t s_b_33_26 = ((uint8_t)(s_b_33_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_33_27 = s_b_33_25&s_b_33_26 (const) */
    uint8_t s_b_33_27 = ((uint8_t)(s_b_33_25 & s_b_33_26));
    /* execute.a64:450 [F] s_b_33_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:450 [F] s_b_33_29 = (u32)s_b_33_28 (const) */
    /* execute.a64:450 [F] s_b_33_30 = constant u32 1 (const) */
    /* execute.a64:450 [F] s_b_33_31 = s_b_33_29==s_b_33_30 (const) */
    uint8_t s_b_33_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_33_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_33_33 = s_b_33_27!=s_b_33_32 (const) */
    uint8_t s_b_33_33 = ((uint8_t)(s_b_33_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_33_34 = s_b_33_31!=s_b_33_32 (const) */
    uint8_t s_b_33_34 = ((uint8_t)(s_b_33_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_33_35 = s_b_33_33&s_b_33_34 (const) */
    uint8_t s_b_33_35 = ((uint8_t)(s_b_33_33 & s_b_33_34));
    /* execute.a64:450 [F] s_b_33_36: If s_b_33_35: Jump b_34 else b_35 (const) */
    if (s_b_33_35) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_33,  */
  fixed_block_b_34: 
  {
    /* execute.a64:453 [D] s_b_34_0 = sym_18182_0_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:453 [D] s_b_34_1 = (u32)s_b_34_0 */
    auto s_b_34_1 = emitter.truncate(s_b_34_0, emitter.context().types().u32());
    /* execute.a64:453 [F] s_b_34_2 = constant u32 200 (const) */
    /* execute.a64:453 [D] s_b_34_3 = s_b_34_1&s_b_34_2 */
    auto s_b_34_3 = emitter.bitwise_and(s_b_34_1, emitter.const_u32((uint32_t)512ULL));
    /* execute.a64:453 [F] s_b_34_4 = constant u32 200 (const) */
    /* execute.a64:453 [D] s_b_34_5 = s_b_34_3==s_b_34_4 */
    auto s_b_34_5 = emitter.cmp_eq(s_b_34_3, emitter.const_u32((uint32_t)512ULL));
    /* execute.a64:453 [D] s_b_34_6: WriteReg 5 = s_b_34_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), s_b_34_5, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), s_b_34_5);
    /* execute.a64:454 [D] s_b_34_7 = (u32)s_b_34_0 */
    auto s_b_34_7 = emitter.truncate(s_b_34_0, emitter.context().types().u32());
    /* execute.a64:454 [F] s_b_34_8 = constant u32 100 (const) */
    /* execute.a64:454 [D] s_b_34_9 = s_b_34_7&s_b_34_8 */
    auto s_b_34_9 = emitter.bitwise_and(s_b_34_7, emitter.const_u32((uint32_t)256ULL));
    /* execute.a64:454 [F] s_b_34_10 = constant u32 100 (const) */
    /* execute.a64:454 [D] s_b_34_11 = s_b_34_9==s_b_34_10 */
    auto s_b_34_11 = emitter.cmp_eq(s_b_34_9, emitter.const_u32((uint32_t)256ULL));
    /* execute.a64:454 [D] s_b_34_12: WriteReg 6 = s_b_34_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), s_b_34_11, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), s_b_34_11);
    /* execute.a64:455 [D] s_b_34_13 = (u32)s_b_34_0 */
    auto s_b_34_13 = emitter.truncate(s_b_34_0, emitter.context().types().u32());
    /* execute.a64:455 [F] s_b_34_14 = constant u32 80 (const) */
    /* execute.a64:455 [D] s_b_34_15 = s_b_34_13&s_b_34_14 */
    auto s_b_34_15 = emitter.bitwise_and(s_b_34_13, emitter.const_u32((uint32_t)128ULL));
    /* execute.a64:455 [F] s_b_34_16 = constant u32 80 (const) */
    /* execute.a64:455 [D] s_b_34_17 = s_b_34_15==s_b_34_16 */
    auto s_b_34_17 = emitter.cmp_eq(s_b_34_15, emitter.const_u32((uint32_t)128ULL));
    /* execute.a64:455 [D] s_b_34_18: WriteReg 7 = s_b_34_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), s_b_34_17, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), s_b_34_17);
    /* execute.a64:456 [D] s_b_34_19 = (u32)s_b_34_0 */
    auto s_b_34_19 = emitter.truncate(s_b_34_0, emitter.context().types().u32());
    /* execute.a64:456 [F] s_b_34_20 = constant u32 40 (const) */
    /* execute.a64:456 [D] s_b_34_21 = s_b_34_19&s_b_34_20 */
    auto s_b_34_21 = emitter.bitwise_and(s_b_34_19, emitter.const_u32((uint32_t)64ULL));
    /* execute.a64:456 [F] s_b_34_22 = constant u32 40 (const) */
    /* execute.a64:456 [D] s_b_34_23 = s_b_34_21==s_b_34_22 */
    auto s_b_34_23 = emitter.cmp_eq(s_b_34_21, emitter.const_u32((uint32_t)64ULL));
    /* execute.a64:456 [D] s_b_34_24: WriteReg 8 = s_b_34_23 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), s_b_34_23, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), s_b_34_23);
    /* execute.a64:457 [D] s_b_34_25 = trigger_irq */
    emitter.call(__captive_trigger_irq);
    /* execute.a64:453 [F] s_b_34_26: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_33,  */
  fixed_block_b_35: 
  {
    /* execute.a64:458 [F] s_b_35_0=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:458 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
    /* execute.a64:458 [F] s_b_35_2 = constant u32 3 (const) */
    /* execute.a64:458 [F] s_b_35_3 = s_b_35_1==s_b_35_2 (const) */
    uint8_t s_b_35_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:458 [F] s_b_35_4=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:458 [F] s_b_35_5 = (u32)s_b_35_4 (const) */
    /* execute.a64:458 [F] s_b_35_6 = constant u32 3 (const) */
    /* execute.a64:458 [F] s_b_35_7 = s_b_35_5==s_b_35_6 (const) */
    uint8_t s_b_35_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_35_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_35_9 = s_b_35_3!=s_b_35_8 (const) */
    uint8_t s_b_35_9 = ((uint8_t)(s_b_35_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_35_10 = s_b_35_7!=s_b_35_8 (const) */
    uint8_t s_b_35_10 = ((uint8_t)(s_b_35_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_35_11 = s_b_35_9&s_b_35_10 (const) */
    uint8_t s_b_35_11 = ((uint8_t)(s_b_35_9 & s_b_35_10));
    /* execute.a64:458 [F] s_b_35_12=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:458 [F] s_b_35_13 = (u32)s_b_35_12 (const) */
    /* execute.a64:458 [F] s_b_35_14 = constant u32 4 (const) */
    /* execute.a64:458 [F] s_b_35_15 = s_b_35_13==s_b_35_14 (const) */
    uint8_t s_b_35_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_35_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_35_17 = s_b_35_11!=s_b_35_16 (const) */
    uint8_t s_b_35_17 = ((uint8_t)(s_b_35_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_35_18 = s_b_35_15!=s_b_35_16 (const) */
    uint8_t s_b_35_18 = ((uint8_t)(s_b_35_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_35_19 = s_b_35_17&s_b_35_18 (const) */
    uint8_t s_b_35_19 = ((uint8_t)(s_b_35_17 & s_b_35_18));
    /* execute.a64:458 [F] s_b_35_20=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:458 [F] s_b_35_21 = (u32)s_b_35_20 (const) */
    /* execute.a64:458 [F] s_b_35_22 = constant u32 4 (const) */
    /* execute.a64:458 [F] s_b_35_23 = s_b_35_21==s_b_35_22 (const) */
    uint8_t s_b_35_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_35_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_35_25 = s_b_35_19!=s_b_35_24 (const) */
    uint8_t s_b_35_25 = ((uint8_t)(s_b_35_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_35_26 = s_b_35_23!=s_b_35_24 (const) */
    uint8_t s_b_35_26 = ((uint8_t)(s_b_35_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_35_27 = s_b_35_25&s_b_35_26 (const) */
    uint8_t s_b_35_27 = ((uint8_t)(s_b_35_25 & s_b_35_26));
    /* execute.a64:458 [F] s_b_35_28=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:458 [F] s_b_35_29 = (u32)s_b_35_28 (const) */
    /* execute.a64:458 [F] s_b_35_30 = constant u32 0 (const) */
    /* execute.a64:458 [F] s_b_35_31 = s_b_35_29==s_b_35_30 (const) */
    uint8_t s_b_35_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_35_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_35_33 = s_b_35_27!=s_b_35_32 (const) */
    uint8_t s_b_35_33 = ((uint8_t)(s_b_35_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_35_34 = s_b_35_31!=s_b_35_32 (const) */
    uint8_t s_b_35_34 = ((uint8_t)(s_b_35_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_35_35 = s_b_35_33&s_b_35_34 (const) */
    uint8_t s_b_35_35 = ((uint8_t)(s_b_35_33 & s_b_35_34));
    /* execute.a64:458 [F] s_b_35_36: If s_b_35_35: Jump b_36 else b_37 (const) */
    if (s_b_35_35) 
    {
      goto fixed_block_b_36;
    }
    else 
    {
      goto fixed_block_b_37;
    }
  }
  /* b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:459 [D] s_b_36_0 = sym_18182_0_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:459 [D] s_b_36_1 = (u32)s_b_36_0 */
    auto s_b_36_1 = emitter.truncate(s_b_36_0, emitter.context().types().u32());
    /* execute.a64:459 [D] s_b_36_2: WriteReg 23 = s_b_36_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1424), s_b_36_1, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1424), s_b_36_1);
    /* execute.a64:461 [F] s_b_36_3 = constant u64 16 (const) */
    /* execute.a64:461 [D] s_b_36_4 = s_b_36_0>>s_b_36_3 */
    auto s_b_36_4 = emitter.shr(s_b_36_0, emitter.const_u64((uint64_t)22ULL));
    /* execute.a64:461 [F] s_b_36_5 = constant u64 3 (const) */
    /* execute.a64:461 [D] s_b_36_6 = s_b_36_4&s_b_36_5 */
    auto s_b_36_6 = emitter.bitwise_and(s_b_36_4, emitter.const_u64((uint64_t)3ULL));
    /* execute.a64:461 [D] s_b_36_7 = (u8)s_b_36_6 */
    auto s_b_36_7 = emitter.truncate(s_b_36_6, emitter.context().types().u8());
    /* execute.a64:462 [D] s_b_36_8 = (u32)s_b_36_7 */
    auto s_b_36_8 = emitter.zx(s_b_36_7, emitter.context().types().u32());
    /* execute.a64:462 [D] s_b_36_9 = __builtin_set_fp_rounding */
    emitter.call(__captive___builtin_set_fp_rounding, s_b_36_8);
    /* execute.a64:459 [F] s_b_36_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_35,  */
  fixed_block_b_37: 
  {
    /* execute.a64:464 [F] s_b_37_0=sym_18178_3_parameter_inst.ir (const) */
    /* execute.a64:464 [D] s_b_37_1 = sym_18182_0_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_18182_0_value, emitter.context().types().u64());
    /* execute.a64:464 [F] s_b_37_2 = constant u32 10 (const) */
    /* ???:4294967295 [D] s_b_37_3 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)16ULL), emitter.const_u32(insn.ir), s_b_37_1);
    }
    emitter.store_device(emitter.const_u32((uint32_t)16ULL), emitter.const_u32(insn.ir), s_b_37_1);
    /* execute.a64:464 [F] s_b_37_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2714 [F] s_b_38_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_38_1: sym_126677_1_temporary_value = s_b_38_0 (const), dominates: s_b_40_0  */
    CV_sym_126677_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_126677_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_38_2: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_0,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2714 [F] s_b_39_0=sym_18178_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_39_1 = ReadRegBank 0:s_b_39_0 (u64) */
    auto s_b_39_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_39_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_39_2: sym_126677_1_temporary_value = s_b_39_1, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_126677_1_temporary_value, s_b_39_1);
    /* execute.a64:2714 [F] s_b_39_3: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_38, b_39,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2714 [D] s_b_40_0 = sym_126677_1_temporary_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_126677_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:401 [D] s_b_40_1: sym_18182_0_value = s_b_40_0, dominates: s_b_1_0 s_b_4_0 s_b_6_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0 s_b_18_0 s_b_20_0 s_b_22_0 s_b_24_0 s_b_26_0 s_b_28_0 s_b_30_0 s_b_32_0 s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_18182_0_value, s_b_40_0);
    /* execute.a64:403 [F] s_b_40_2=sym_18178_3_parameter_inst.op0 (const) */
    /* execute.a64:403 [F] s_b_40_3 = (u32)s_b_40_2 (const) */
    /* execute.a64:403 [F] s_b_40_4 = constant u32 3 (const) */
    /* execute.a64:403 [F] s_b_40_5 = s_b_40_3==s_b_40_4 (const) */
    uint8_t s_b_40_5 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:403 [F] s_b_40_6=sym_18178_3_parameter_inst.op1 (const) */
    /* execute.a64:403 [F] s_b_40_7 = (u32)s_b_40_6 (const) */
    /* execute.a64:403 [F] s_b_40_8 = constant u32 0 (const) */
    /* execute.a64:403 [F] s_b_40_9 = s_b_40_7==s_b_40_8 (const) */
    uint8_t s_b_40_9 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_40_10 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_40_11 = s_b_40_5!=s_b_40_10 (const) */
    uint8_t s_b_40_11 = ((uint8_t)(s_b_40_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_40_12 = s_b_40_9!=s_b_40_10 (const) */
    uint8_t s_b_40_12 = ((uint8_t)(s_b_40_9 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_40_13 = s_b_40_11&s_b_40_12 (const) */
    uint8_t s_b_40_13 = ((uint8_t)(s_b_40_11 & s_b_40_12));
    /* execute.a64:403 [F] s_b_40_14=sym_18178_3_parameter_inst.crn (const) */
    /* execute.a64:403 [F] s_b_40_15 = (u32)s_b_40_14 (const) */
    /* execute.a64:403 [F] s_b_40_16 = constant u32 2 (const) */
    /* execute.a64:403 [F] s_b_40_17 = s_b_40_15==s_b_40_16 (const) */
    uint8_t s_b_40_17 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_40_18 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_40_19 = s_b_40_13!=s_b_40_18 (const) */
    uint8_t s_b_40_19 = ((uint8_t)(s_b_40_13 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_40_20 = s_b_40_17!=s_b_40_18 (const) */
    uint8_t s_b_40_20 = ((uint8_t)(s_b_40_17 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_40_21 = s_b_40_19&s_b_40_20 (const) */
    uint8_t s_b_40_21 = ((uint8_t)(s_b_40_19 & s_b_40_20));
    /* execute.a64:403 [F] s_b_40_22=sym_18178_3_parameter_inst.crm (const) */
    /* execute.a64:403 [F] s_b_40_23 = (u32)s_b_40_22 (const) */
    /* execute.a64:403 [F] s_b_40_24 = constant u32 0 (const) */
    /* execute.a64:403 [F] s_b_40_25 = s_b_40_23==s_b_40_24 (const) */
    uint8_t s_b_40_25 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_40_26 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_40_27 = s_b_40_21!=s_b_40_26 (const) */
    uint8_t s_b_40_27 = ((uint8_t)(s_b_40_21 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_40_28 = s_b_40_25!=s_b_40_26 (const) */
    uint8_t s_b_40_28 = ((uint8_t)(s_b_40_25 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_40_29 = s_b_40_27&s_b_40_28 (const) */
    uint8_t s_b_40_29 = ((uint8_t)(s_b_40_27 & s_b_40_28));
    /* execute.a64:403 [F] s_b_40_30=sym_18178_3_parameter_inst.op2 (const) */
    /* execute.a64:403 [F] s_b_40_31 = (u32)s_b_40_30 (const) */
    /* execute.a64:403 [F] s_b_40_32 = constant u32 0 (const) */
    /* execute.a64:403 [F] s_b_40_33 = s_b_40_31==s_b_40_32 (const) */
    uint8_t s_b_40_33 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_40_34 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_40_35 = s_b_40_29!=s_b_40_34 (const) */
    uint8_t s_b_40_35 = ((uint8_t)(s_b_40_29 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_40_36 = s_b_40_33!=s_b_40_34 (const) */
    uint8_t s_b_40_36 = ((uint8_t)(s_b_40_33 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_40_37 = s_b_40_35&s_b_40_36 (const) */
    uint8_t s_b_40_37 = ((uint8_t)(s_b_40_35 & s_b_40_36));
    /* execute.a64:403 [F] s_b_40_38: If s_b_40_37: Jump b_1 else b_3 (const) */
    if (s_b_40_37) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_orn_vector(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1180 [F] s_b_0_0=sym_19557_3_parameter_inst.Q (const) */
    /* execute.simd:1180 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:1180 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:1180 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:1180 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:1181 [F] s_b_1_0=sym_19557_3_parameter_inst.rd (const) */
    /* execute.simd:1181 [F] s_b_1_1=sym_19557_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:1181 [F] s_b_1_3=sym_19557_3_parameter_inst.rm (const) */
    /* execute.simd:6355 [D] s_b_1_4 = ReadRegBank 7:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:1181 [D] s_b_1_5 = ~s_b_1_4 */
    auto s_b_1_5 = emitter.bitwise_not(s_b_1_4);
    /* execute.simd:1181 [D] s_b_1_6 = s_b_1_2|s_b_1_5 */
    auto s_b_1_6 = emitter.bitwise_or(s_b_1_2, s_b_1_5);
    /* execute.simd:6326 [D] s_b_1_7: WriteRegBank 2:s_b_1_0 = s_b_1_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_6);
    /* execute.simd:6327 [F] s_b_1_8 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_9: WriteRegBank 3:s_b_1_0 = s_b_1_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1188 [F] s_b_3_0=sym_19557_3_parameter_inst.rn (const) */
    /* execute.simd:6360 [D] s_b_3_1 = ReadRegBank 2:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_3_2 = ReadRegBank 3:s_b_3_0 (u64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:1189 [F] s_b_3_3=sym_19557_3_parameter_inst.rm (const) */
    /* execute.simd:6360 [D] s_b_3_4 = ReadRegBank 2:s_b_3_3 (u64) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_3_5 = ReadRegBank 3:s_b_3_3 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:1191 [F] s_b_3_6=sym_19557_3_parameter_inst.rd (const) */
    /* execute.simd:1191 [D] s_b_3_7 = ~s_b_3_4 */
    auto s_b_3_7 = emitter.bitwise_not(s_b_3_4);
    /* execute.simd:1191 [D] s_b_3_8 = s_b_3_1|s_b_3_7 */
    auto s_b_3_8 = emitter.bitwise_or(s_b_3_1, s_b_3_7);
    /* execute.simd:1191 [D] s_b_3_9 = ~s_b_3_5 */
    auto s_b_3_9 = emitter.bitwise_not(s_b_3_5);
    /* execute.simd:1191 [D] s_b_3_10 = s_b_3_2|s_b_3_9 */
    auto s_b_3_10 = emitter.bitwise_or(s_b_3_2, s_b_3_9);
    /* execute.simd:6333 [D] s_b_3_11: WriteRegBank 2:s_b_3_6 = s_b_3_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_8,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_8);
    /* execute.simd:6334 [D] s_b_3_12: WriteRegBank 3:s_b_3_6 = s_b_3_10 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_10,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_10);
    /* execute.simd:0 [F] s_b_3_13: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_prfmi(const arm64_decode_a64_LS_REG_UIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* ???:4294967295 [F] s_b_0_0: Return */
    goto fixed_done;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_rev64_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:687 [F] s_b_0_0=sym_20477_3_parameter_inst.arrangement (const) */
    /* execute.simd:688 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:696 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:704 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:717 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:733 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:744 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:687 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
      break;
    default:
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:689 [F] s_b_2_0=sym_20477_3_parameter_inst.rn (const) */
    /* execute.simd:689 [D] s_b_2_1 = ReadRegBank 2:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:690 [D] s_b_2_2 = __builtin_bswap64 */
    auto s_b_2_2 = emitter.bswap(s_b_2_1);
    /* execute.simd:692 [F] s_b_2_3=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:692 [D] s_b_2_4: WriteRegBank 2:s_b_2_3 = s_b_2_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_2);
    /* execute.simd:693 [F] s_b_2_5=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:693 [F] s_b_2_6 = constant u64 0 (const) */
    /* execute.simd:693 [F] s_b_2_7: WriteRegBank 3:s_b_2_5 = s_b_2_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_8: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:697 [F] s_b_3_0=sym_20477_3_parameter_inst.rn (const) */
    /* execute.simd:697 [D] s_b_3_1 = ReadRegBank 21:s_b_3_0 (v2u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:698 [F] s_b_3_2 = constant s32 0 (const) */
    /* execute.simd:698 [D] s_b_3_1[s_b_3_2] */
    auto s_b_3_3 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:698 [D] s_b_3_4 = __builtin_bswap64 */
    auto s_b_3_4 = emitter.bswap(s_b_3_3);
    /* execute.simd:698 [F] s_b_3_5 = constant s32 0 (const) */
    /* execute.simd:698 [D] s_b_3_6 = s_b_3_1[s_b_3_5] <= s_b_3_4 */
    auto s_b_3_6 = emitter.vector_insert(s_b_3_1, emitter.const_s32((int32_t)0ULL), s_b_3_4);
    /* execute.simd:699 [F] s_b_3_7 = constant s32 1 (const) */
    /* execute.simd:699 [D] s_b_3_6[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_6, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:699 [D] s_b_3_9 = __builtin_bswap64 */
    auto s_b_3_9 = emitter.bswap(s_b_3_8);
    /* execute.simd:699 [F] s_b_3_10 = constant s32 1 (const) */
    /* execute.simd:699 [D] s_b_3_11 = s_b_3_6[s_b_3_10] <= s_b_3_9 */
    auto s_b_3_11 = emitter.vector_insert(s_b_3_6, emitter.const_s32((int32_t)1ULL), s_b_3_9);
    /* execute.simd:701 [F] s_b_3_12=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:701 [D] s_b_3_13: WriteRegBank 21:s_b_3_12 = s_b_3_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_11,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_11);
    /* execute.simd:0 [F] s_b_3_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:705 [F] s_b_4_0=sym_20477_3_parameter_inst.rn (const) */
    /* execute.simd:705 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_2 = constant v4u16 
    {
    }
    (const) */
    /* execute.simd:708 [F] s_b_4_3 = constant s32 3 (const) */
    /* execute.simd:708 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:708 [F] s_b_4_5 = constant s32 0 (const) */
    /* execute.simd:708 [D] s_b_4_6 = s_b_4_2[s_b_4_5] <= s_b_4_4 */
    auto s_b_4_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 4>(0)[0], emitter.context().types().v4u16()), emitter.const_s32((int32_t)0ULL), s_b_4_4);
    /* execute.simd:709 [F] s_b_4_7 = constant s32 2 (const) */
    /* execute.simd:709 [D] s_b_4_1[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:709 [F] s_b_4_9 = constant s32 1 (const) */
    /* execute.simd:709 [D] s_b_4_10 = s_b_4_6[s_b_4_9] <= s_b_4_8 */
    auto s_b_4_10 = emitter.vector_insert(s_b_4_6, emitter.const_s32((int32_t)1ULL), s_b_4_8);
    /* execute.simd:710 [F] s_b_4_11 = constant s32 1 (const) */
    /* execute.simd:710 [D] s_b_4_1[s_b_4_11] */
    auto s_b_4_12 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:710 [F] s_b_4_13 = constant s32 2 (const) */
    /* execute.simd:710 [D] s_b_4_14 = s_b_4_10[s_b_4_13] <= s_b_4_12 */
    auto s_b_4_14 = emitter.vector_insert(s_b_4_10, emitter.const_s32((int32_t)2ULL), s_b_4_12);
    /* execute.simd:711 [F] s_b_4_15 = constant s32 0 (const) */
    /* execute.simd:711 [D] s_b_4_1[s_b_4_15] */
    auto s_b_4_16 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:711 [F] s_b_4_17 = constant s32 3 (const) */
    /* execute.simd:711 [D] s_b_4_18 = s_b_4_14[s_b_4_17] <= s_b_4_16 */
    auto s_b_4_18 = emitter.vector_insert(s_b_4_14, emitter.const_s32((int32_t)3ULL), s_b_4_16);
    /* execute.simd:713 [F] s_b_4_19=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:713 [D] s_b_4_20: WriteRegBank 17:s_b_4_19 = s_b_4_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_18,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_18);
    /* execute.simd:714 [F] s_b_4_21=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:714 [F] s_b_4_22 = constant u64 0 (const) */
    /* execute.simd:714 [F] s_b_4_23: WriteRegBank 3:s_b_4_21 = s_b_4_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_24: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:718 [F] s_b_5_0=sym_20477_3_parameter_inst.rn (const) */
    /* execute.simd:718 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_2 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:721 [F] s_b_5_3 = constant s32 3 (const) */
    /* execute.simd:721 [D] s_b_5_1[s_b_5_3] */
    auto s_b_5_4 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:721 [F] s_b_5_5 = constant s32 0 (const) */
    /* execute.simd:721 [D] s_b_5_6 = s_b_5_2[s_b_5_5] <= s_b_5_4 */
    auto s_b_5_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_5_4);
    /* execute.simd:722 [F] s_b_5_7 = constant s32 2 (const) */
    /* execute.simd:722 [D] s_b_5_1[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:722 [F] s_b_5_9 = constant s32 1 (const) */
    /* execute.simd:722 [D] s_b_5_10 = s_b_5_6[s_b_5_9] <= s_b_5_8 */
    auto s_b_5_10 = emitter.vector_insert(s_b_5_6, emitter.const_s32((int32_t)1ULL), s_b_5_8);
    /* execute.simd:723 [F] s_b_5_11 = constant s32 1 (const) */
    /* execute.simd:723 [D] s_b_5_1[s_b_5_11] */
    auto s_b_5_12 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:723 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:723 [D] s_b_5_14 = s_b_5_10[s_b_5_13] <= s_b_5_12 */
    auto s_b_5_14 = emitter.vector_insert(s_b_5_10, emitter.const_s32((int32_t)2ULL), s_b_5_12);
    /* execute.simd:724 [F] s_b_5_15 = constant s32 0 (const) */
    /* execute.simd:724 [D] s_b_5_1[s_b_5_15] */
    auto s_b_5_16 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:724 [F] s_b_5_17 = constant s32 3 (const) */
    /* execute.simd:724 [D] s_b_5_18 = s_b_5_14[s_b_5_17] <= s_b_5_16 */
    auto s_b_5_18 = emitter.vector_insert(s_b_5_14, emitter.const_s32((int32_t)3ULL), s_b_5_16);
    /* execute.simd:725 [F] s_b_5_19 = constant s32 7 (const) */
    /* execute.simd:725 [D] s_b_5_1[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:725 [F] s_b_5_21 = constant s32 4 (const) */
    /* execute.simd:725 [D] s_b_5_22 = s_b_5_18[s_b_5_21] <= s_b_5_20 */
    auto s_b_5_22 = emitter.vector_insert(s_b_5_18, emitter.const_s32((int32_t)4ULL), s_b_5_20);
    /* execute.simd:726 [F] s_b_5_23 = constant s32 6 (const) */
    /* execute.simd:726 [D] s_b_5_1[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:726 [F] s_b_5_25 = constant s32 5 (const) */
    /* execute.simd:726 [D] s_b_5_26 = s_b_5_22[s_b_5_25] <= s_b_5_24 */
    auto s_b_5_26 = emitter.vector_insert(s_b_5_22, emitter.const_s32((int32_t)5ULL), s_b_5_24);
    /* execute.simd:727 [F] s_b_5_27 = constant s32 5 (const) */
    /* execute.simd:727 [D] s_b_5_1[s_b_5_27] */
    auto s_b_5_28 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:727 [F] s_b_5_29 = constant s32 6 (const) */
    /* execute.simd:727 [D] s_b_5_30 = s_b_5_26[s_b_5_29] <= s_b_5_28 */
    auto s_b_5_30 = emitter.vector_insert(s_b_5_26, emitter.const_s32((int32_t)6ULL), s_b_5_28);
    /* execute.simd:728 [F] s_b_5_31 = constant s32 4 (const) */
    /* execute.simd:728 [D] s_b_5_1[s_b_5_31] */
    auto s_b_5_32 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:728 [F] s_b_5_33 = constant s32 7 (const) */
    /* execute.simd:728 [D] s_b_5_34 = s_b_5_30[s_b_5_33] <= s_b_5_32 */
    auto s_b_5_34 = emitter.vector_insert(s_b_5_30, emitter.const_s32((int32_t)7ULL), s_b_5_32);
    /* execute.simd:730 [F] s_b_5_35=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:730 [D] s_b_5_36: WriteRegBank 18:s_b_5_35 = s_b_5_34 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_34,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_34);
    /* execute.simd:0 [F] s_b_5_37: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:734 [F] s_b_6_0=sym_20477_3_parameter_inst.rn (const) */
    /* execute.simd:734 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v2u32 
    {
    }
    (const) */
    /* execute.simd:737 [F] s_b_6_3 = constant s32 1 (const) */
    /* execute.simd:737 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:737 [F] s_b_6_5 = constant s32 0 (const) */
    /* execute.simd:737 [D] s_b_6_6 = s_b_6_2[s_b_6_5] <= s_b_6_4 */
    auto s_b_6_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 2>(0)[0], emitter.context().types().v2u32()), emitter.const_s32((int32_t)0ULL), s_b_6_4);
    /* execute.simd:738 [F] s_b_6_7 = constant s32 0 (const) */
    /* execute.simd:738 [D] s_b_6_1[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:738 [F] s_b_6_9 = constant s32 1 (const) */
    /* execute.simd:738 [D] s_b_6_10 = s_b_6_6[s_b_6_9] <= s_b_6_8 */
    auto s_b_6_10 = emitter.vector_insert(s_b_6_6, emitter.const_s32((int32_t)1ULL), s_b_6_8);
    /* execute.simd:740 [F] s_b_6_11=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:740 [D] s_b_6_12: WriteRegBank 19:s_b_6_11 = s_b_6_10 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_10,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_10);
    /* execute.simd:741 [F] s_b_6_13=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:741 [F] s_b_6_14 = constant u64 0 (const) */
    /* execute.simd:741 [F] s_b_6_15: WriteRegBank 3:s_b_6_13 = s_b_6_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_16: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:745 [F] s_b_7_0=sym_20477_3_parameter_inst.rn (const) */
    /* execute.simd:745 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_2 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:748 [F] s_b_7_3 = constant s32 1 (const) */
    /* execute.simd:748 [D] s_b_7_1[s_b_7_3] */
    auto s_b_7_4 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:748 [F] s_b_7_5 = constant s32 0 (const) */
    /* execute.simd:748 [D] s_b_7_6 = s_b_7_2[s_b_7_5] <= s_b_7_4 */
    auto s_b_7_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_7_4);
    /* execute.simd:749 [F] s_b_7_7 = constant s32 0 (const) */
    /* execute.simd:749 [D] s_b_7_1[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:749 [F] s_b_7_9 = constant s32 1 (const) */
    /* execute.simd:749 [D] s_b_7_10 = s_b_7_6[s_b_7_9] <= s_b_7_8 */
    auto s_b_7_10 = emitter.vector_insert(s_b_7_6, emitter.const_s32((int32_t)1ULL), s_b_7_8);
    /* execute.simd:750 [F] s_b_7_11 = constant s32 3 (const) */
    /* execute.simd:750 [D] s_b_7_1[s_b_7_11] */
    auto s_b_7_12 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:750 [F] s_b_7_13 = constant s32 2 (const) */
    /* execute.simd:750 [D] s_b_7_14 = s_b_7_10[s_b_7_13] <= s_b_7_12 */
    auto s_b_7_14 = emitter.vector_insert(s_b_7_10, emitter.const_s32((int32_t)2ULL), s_b_7_12);
    /* execute.simd:751 [F] s_b_7_15 = constant s32 2 (const) */
    /* execute.simd:751 [D] s_b_7_1[s_b_7_15] */
    auto s_b_7_16 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:751 [F] s_b_7_17 = constant s32 3 (const) */
    /* execute.simd:751 [D] s_b_7_18 = s_b_7_14[s_b_7_17] <= s_b_7_16 */
    auto s_b_7_18 = emitter.vector_insert(s_b_7_14, emitter.const_s32((int32_t)3ULL), s_b_7_16);
    /* execute.simd:753 [F] s_b_7_19=sym_20477_3_parameter_inst.rd (const) */
    /* execute.simd:753 [D] s_b_7_20: WriteRegBank 20:s_b_7_19 = s_b_7_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_18,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_18);
    /* execute.simd:0 [F] s_b_7_21: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:757 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_8_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_scvtf_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4337 [F] s_b_0_0=sym_22658_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4337 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
    if (insn.SCALAR) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.simd:4338 [F] s_b_1_0=sym_22658_3_parameter_inst.size (const) */
    /* execute.simd:4338 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4338 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4338 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4338 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_5, b_6, b_8, b_10, b_11,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4346 [F] s_b_3_0=sym_22658_3_parameter_inst.size (const) */
    /* execute.simd:4346 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4346 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4346 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4346 [F] s_b_3_4=sym_22658_3_parameter_inst.Q (const) */
    /* execute.simd:4346 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4346 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:4346 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4346 [F] s_b_3_12: If s_b_3_11: Jump b_6 else b_7 (const) */
    if (s_b_3_11) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4340 [F] s_b_4_0=sym_22658_3_parameter_inst.rd (const) */
    /* execute.simd:4340 [F] s_b_4_1=sym_22658_3_parameter_inst.rn (const) */
    /* execute.simd:6350 [D] s_b_4_2 = ReadRegBank 6:s_b_4_1 (u32) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_2,emitter.const_u8(4));
    }
    /* execute.simd:4340 [D] s_b_4_3 = (s32)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().s32());
    /* execute.simd:4340 [D] s_b_4_4 = (f32)s_b_4_3 */
    auto s_b_4_4 = emitter.convert(s_b_4_3, emitter.context().types().f32());
    /* execute.simd:6290 [D] s_b_4_5: WriteRegBank 9:s_b_4_0 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:6291 [F] s_b_4_6 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_4_7: WriteRegBank 10:s_b_4_0 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_4_9: WriteRegBank 3:s_b_4_0 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4343 [F] s_b_5_0=sym_22658_3_parameter_inst.rd (const) */
    /* execute.simd:4343 [F] s_b_5_1=sym_22658_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_5_2 = ReadRegBank 7:s_b_5_1 (u64) */
    auto s_b_5_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_2,emitter.const_u8(8));
    }
    /* execute.simd:4343 [D] s_b_5_3 = (s64)s_b_5_2 */
    auto s_b_5_3 = emitter.reinterpret(s_b_5_2, emitter.context().types().s64());
    /* execute.simd:4343 [D] s_b_5_4 = (f64)s_b_5_3 */
    auto s_b_5_4 = emitter.convert(s_b_5_3, emitter.context().types().f64());
    /* execute.simd:6298 [D] s_b_5_5: WriteRegBank 11:s_b_5_0 = s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4);
    /* execute.simd:6299 [F] s_b_5_6 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_5_7: WriteRegBank 3:s_b_5_0 = s_b_5_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_5_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4347 [F] s_b_6_0=sym_22658_3_parameter_inst.rn (const) */
    /* execute.simd:4347 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:4347 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_3 = constant v2f32 
    {
    }
    (const) */
    /* execute.simd:4350 [F] s_b_6_4 = constant s32 0 (const) */
    /* execute.simd:4350 [D] s_b_6_2[s_b_6_4] */
    auto s_b_6_5 = emitter.vector_extract(s_b_6_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4350 [D] s_b_6_6 = (f32)s_b_6_5 */
    auto s_b_6_6 = emitter.convert(s_b_6_5, emitter.context().types().f32());
    /* execute.simd:4350 [F] s_b_6_7 = constant s32 0 (const) */
    /* execute.simd:4350 [D] s_b_6_8 = s_b_6_3[s_b_6_7] <= s_b_6_6 */
    auto s_b_6_8 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<float, 2>(0.000000)[0], emitter.context().types().v2f32()), emitter.const_s32((int32_t)0ULL), s_b_6_6);
    /* execute.simd:4351 [F] s_b_6_9 = constant s32 1 (const) */
    /* execute.simd:4351 [D] s_b_6_2[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_2, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4351 [D] s_b_6_11 = (f32)s_b_6_10 */
    auto s_b_6_11 = emitter.convert(s_b_6_10, emitter.context().types().f32());
    /* execute.simd:4351 [F] s_b_6_12 = constant s32 1 (const) */
    /* execute.simd:4351 [D] s_b_6_13 = s_b_6_8[s_b_6_12] <= s_b_6_11 */
    auto s_b_6_13 = emitter.vector_insert(s_b_6_8, emitter.const_s32((int32_t)1ULL), s_b_6_11);
    /* execute.simd:4353 [F] s_b_6_14=sym_22658_3_parameter_inst.rd (const) */
    /* execute.simd:4353 [D] s_b_6_15: WriteRegBank 12:s_b_6_14 = s_b_6_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_13);
    /* execute.simd:4354 [F] s_b_6_16=sym_22658_3_parameter_inst.rd (const) */
    /* execute.simd:4354 [F] s_b_6_17 = constant u64 0 (const) */
    /* execute.simd:4354 [F] s_b_6_18: WriteRegBank 3:s_b_6_16 = s_b_6_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4347 [F] s_b_6_19: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4355 [F] s_b_7_0=sym_22658_3_parameter_inst.size (const) */
    /* execute.simd:4355 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4355 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4355 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4355 [F] s_b_7_4=sym_22658_3_parameter_inst.Q (const) */
    /* execute.simd:4355 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4355 [F] s_b_7_6 = constant u32 1 (const) */
    /* execute.simd:4355 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:4355 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
    if (s_b_7_11) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_7,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4356 [F] s_b_8_0=sym_22658_3_parameter_inst.rn (const) */
    /* execute.simd:4356 [D] s_b_8_1 = ReadRegBank 20:s_b_8_0 (v4u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* execute.simd:4356 [D] s_b_8_2 = (v4s32)s_b_8_1 */
    auto s_b_8_2 = emitter.reinterpret(s_b_8_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_8_3 = constant v4f32 
    {
    }
    (const) */
    /* execute.simd:4359 [F] s_b_8_4 = constant s32 0 (const) */
    /* execute.simd:4359 [D] s_b_8_2[s_b_8_4] */
    auto s_b_8_5 = emitter.vector_extract(s_b_8_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4359 [D] s_b_8_6 = (f32)s_b_8_5 */
    auto s_b_8_6 = emitter.convert(s_b_8_5, emitter.context().types().f32());
    /* execute.simd:4359 [F] s_b_8_7 = constant s32 0 (const) */
    /* execute.simd:4359 [D] s_b_8_8 = s_b_8_3[s_b_8_7] <= s_b_8_6 */
    auto s_b_8_8 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<float, 4>(0.000000)[0], emitter.context().types().v4f32()), emitter.const_s32((int32_t)0ULL), s_b_8_6);
    /* execute.simd:4360 [F] s_b_8_9 = constant s32 1 (const) */
    /* execute.simd:4360 [D] s_b_8_2[s_b_8_9] */
    auto s_b_8_10 = emitter.vector_extract(s_b_8_2, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4360 [D] s_b_8_11 = (f32)s_b_8_10 */
    auto s_b_8_11 = emitter.convert(s_b_8_10, emitter.context().types().f32());
    /* execute.simd:4360 [F] s_b_8_12 = constant s32 1 (const) */
    /* execute.simd:4360 [D] s_b_8_13 = s_b_8_8[s_b_8_12] <= s_b_8_11 */
    auto s_b_8_13 = emitter.vector_insert(s_b_8_8, emitter.const_s32((int32_t)1ULL), s_b_8_11);
    /* execute.simd:4361 [F] s_b_8_14 = constant s32 2 (const) */
    /* execute.simd:4361 [D] s_b_8_2[s_b_8_14] */
    auto s_b_8_15 = emitter.vector_extract(s_b_8_2, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4361 [D] s_b_8_16 = (f32)s_b_8_15 */
    auto s_b_8_16 = emitter.convert(s_b_8_15, emitter.context().types().f32());
    /* execute.simd:4361 [F] s_b_8_17 = constant s32 2 (const) */
    /* execute.simd:4361 [D] s_b_8_18 = s_b_8_13[s_b_8_17] <= s_b_8_16 */
    auto s_b_8_18 = emitter.vector_insert(s_b_8_13, emitter.const_s32((int32_t)2ULL), s_b_8_16);
    /* execute.simd:4362 [F] s_b_8_19 = constant s32 3 (const) */
    /* execute.simd:4362 [D] s_b_8_2[s_b_8_19] */
    auto s_b_8_20 = emitter.vector_extract(s_b_8_2, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4362 [D] s_b_8_21 = (f32)s_b_8_20 */
    auto s_b_8_21 = emitter.convert(s_b_8_20, emitter.context().types().f32());
    /* execute.simd:4362 [F] s_b_8_22 = constant s32 3 (const) */
    /* execute.simd:4362 [D] s_b_8_23 = s_b_8_18[s_b_8_22] <= s_b_8_21 */
    auto s_b_8_23 = emitter.vector_insert(s_b_8_18, emitter.const_s32((int32_t)3ULL), s_b_8_21);
    /* execute.simd:4364 [F] s_b_8_24=sym_22658_3_parameter_inst.rd (const) */
    /* execute.simd:4364 [D] s_b_8_25: WriteRegBank 13:s_b_8_24 = s_b_8_23 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_23,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_23);
    /* execute.simd:4356 [F] s_b_8_26: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4365 [F] s_b_9_0=sym_22658_3_parameter_inst.size (const) */
    /* execute.simd:4365 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4365 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4365 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:4365 [F] s_b_9_4=sym_22658_3_parameter_inst.Q (const) */
    /* execute.simd:4365 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4365 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.simd:4365 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.simd:4365 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
    if (s_b_9_11) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_9,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4366 [F] s_b_10_0=sym_22658_3_parameter_inst.rn (const) */
    /* execute.simd:4366 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:4366 [D] s_b_10_2 = (v2s64)s_b_10_1 */
    auto s_b_10_2 = emitter.reinterpret(s_b_10_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_10_3 = constant v2f64 
    {
    }
    (const) */
    /* execute.simd:4369 [F] s_b_10_4 = constant s32 0 (const) */
    /* execute.simd:4369 [D] s_b_10_2[s_b_10_4] */
    auto s_b_10_5 = emitter.vector_extract(s_b_10_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4369 [D] s_b_10_6 = (f64)s_b_10_5 */
    auto s_b_10_6 = emitter.convert(s_b_10_5, emitter.context().types().f64());
    /* execute.simd:4369 [F] s_b_10_7 = constant s32 0 (const) */
    /* execute.simd:4369 [D] s_b_10_8 = s_b_10_3[s_b_10_7] <= s_b_10_6 */
    auto s_b_10_8 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<double, 2>(0.000000)[0], emitter.context().types().v2f64()), emitter.const_s32((int32_t)0ULL), s_b_10_6);
    /* execute.simd:4370 [F] s_b_10_9 = constant s32 1 (const) */
    /* execute.simd:4370 [D] s_b_10_2[s_b_10_9] */
    auto s_b_10_10 = emitter.vector_extract(s_b_10_2, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4370 [D] s_b_10_11 = (f64)s_b_10_10 */
    auto s_b_10_11 = emitter.convert(s_b_10_10, emitter.context().types().f64());
    /* execute.simd:4370 [F] s_b_10_12 = constant s32 1 (const) */
    /* execute.simd:4370 [D] s_b_10_13 = s_b_10_8[s_b_10_12] <= s_b_10_11 */
    auto s_b_10_13 = emitter.vector_insert(s_b_10_8, emitter.const_s32((int32_t)1ULL), s_b_10_11);
    /* execute.simd:4372 [F] s_b_10_14=sym_22658_3_parameter_inst.rd (const) */
    /* execute.simd:4372 [D] s_b_10_15: WriteRegBank 14:s_b_10_14 = s_b_10_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_13,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_13);
    /* execute.simd:4366 [F] s_b_10_16: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4374 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4374 [F] s_b_11_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sminv(const arm64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_8 = emitter.context().create_block();
  auto block_b_9 = emitter.context().create_block();
  auto block_b_10 = emitter.context().create_block();
  auto block_b_11 = emitter.context().create_block();
  auto block_b_12 = emitter.context().create_block();
  auto block_b_13 = emitter.context().create_block();
  auto block_b_14 = emitter.context().create_block();
  auto block_b_15 = emitter.context().create_block();
  auto block_b_16 = emitter.context().create_block();
  auto block_b_18 = emitter.context().create_block();
  auto block_b_19 = emitter.context().create_block();
  auto block_b_20 = emitter.context().create_block();
  auto block_b_21 = emitter.context().create_block();
  auto block_b_22 = emitter.context().create_block();
  auto block_b_23 = emitter.context().create_block();
  auto block_b_24 = emitter.context().create_block();
  auto block_b_25 = emitter.context().create_block();
  auto block_b_26 = emitter.context().create_block();
  auto block_b_27 = emitter.context().create_block();
  auto block_b_28 = emitter.context().create_block();
  auto block_b_29 = emitter.context().create_block();
  auto block_b_30 = emitter.context().create_block();
  auto block_b_31 = emitter.context().create_block();
  auto block_b_32 = emitter.context().create_block();
  auto block_b_33 = emitter.context().create_block();
  auto block_b_34 = emitter.context().create_block();
  auto block_b_35 = emitter.context().create_block();
  auto block_b_36 = emitter.context().create_block();
  auto block_b_37 = emitter.context().create_block();
  auto block_b_38 = emitter.context().create_block();
  auto block_b_39 = emitter.context().create_block();
  auto block_b_40 = emitter.context().create_block();
  auto block_b_41 = emitter.context().create_block();
  auto block_b_42 = emitter.context().create_block();
  auto block_b_43 = emitter.context().create_block();
  auto block_b_44 = emitter.context().create_block();
  auto block_b_45 = emitter.context().create_block();
  auto block_b_46 = emitter.context().create_block();
  auto block_b_47 = emitter.context().create_block();
  auto block_b_49 = emitter.context().create_block();
  auto block_b_50 = emitter.context().create_block();
  auto block_b_51 = emitter.context().create_block();
  auto block_b_52 = emitter.context().create_block();
  auto block_b_53 = emitter.context().create_block();
  auto block_b_54 = emitter.context().create_block();
  auto block_b_56 = emitter.context().create_block();
  auto block_b_57 = emitter.context().create_block();
  auto block_b_58 = emitter.context().create_block();
  auto block_b_59 = emitter.context().create_block();
  auto block_b_60 = emitter.context().create_block();
  auto block_b_61 = emitter.context().create_block();
  auto block_b_62 = emitter.context().create_block();
  auto block_b_63 = emitter.context().create_block();
  auto block_b_64 = emitter.context().create_block();
  auto block_b_65 = emitter.context().create_block();
  auto block_b_66 = emitter.context().create_block();
  auto block_b_67 = emitter.context().create_block();
  auto block_b_68 = emitter.context().create_block();
  auto block_b_69 = emitter.context().create_block();
  auto block_b_71 = emitter.context().create_block();
  auto block_b_72 = emitter.context().create_block();
  auto block_b_73 = emitter.context().create_block();
  auto block_b_74 = emitter.context().create_block();
  auto block_b_75 = emitter.context().create_block();
  auto block_b_76 = emitter.context().create_block();
  auto DV_sym_24213_0_rn = emitter.alloc_local(emitter.context().types().v8s8(), true);
  auto DV_sym_24219_0_min = emitter.alloc_local(emitter.context().types().s8(), true);
  auto DV_sym_24352_0_rn = emitter.alloc_local(emitter.context().types().v16s8(), true);
  auto DV_sym_24358_0_min = emitter.alloc_local(emitter.context().types().s8(), true);
  auto DV_sym_24627_0_rn = emitter.alloc_local(emitter.context().types().v4s16(), true);
  auto DV_sym_24633_0_min = emitter.alloc_local(emitter.context().types().s16(), true);
  auto DV_sym_24698_0_rn = emitter.alloc_local(emitter.context().types().v8s16(), true);
  auto DV_sym_24704_0_min = emitter.alloc_local(emitter.context().types().s16(), true);
  auto DV_sym_24837_0_rn = emitter.alloc_local(emitter.context().types().v4s32(), true);
  auto DV_sym_24843_0_min = emitter.alloc_local(emitter.context().types().s32(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:12 [F] s_b_0_0=sym_24205_3_parameter_inst.arrangement (const) */
    /* execute.simd:13 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:26 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:39 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:52 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:65 [F] s_b_0_5 = constant s32 5 (const) */
    /* execute.simd:12 [F] s_b_0_6: Switch s_b_0_0: < <todo> > def b_77 (const) -> b_2, b_17, b_48, b_55, b_70, b_77,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_48;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_55;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_70;
      break;
    default:
      goto fixed_block_b_77;
    }
  }
  // BLOCK b_1 not fully fixed
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:14 [F] s_b_2_0=sym_24205_3_parameter_inst.rn (const) */
    /* execute.simd:14 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:14 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:14 [D] s_b_2_3: sym_24213_0_rn = s_b_2_2, dominates: s_b_3_0 s_b_4_0 s_b_5_0 s_b_6_0 s_b_7_0 s_b_8_0 s_b_9_0 s_b_10_0 s_b_11_0 s_b_12_0 s_b_13_0 s_b_14_0 s_b_15_0  */
    emitter.store_local(DV_sym_24213_0_rn, s_b_2_2);
    /* execute.simd:16 [F] s_b_2_4 = constant s32 0 (const) */
    /* execute.simd:16 [D] s_b_2_2[s_b_2_4] */
    auto s_b_2_5 = emitter.vector_extract(s_b_2_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:16 [D] s_b_2_6: sym_24219_0_min = s_b_2_5, dominates: s_b_4_3 s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
    emitter.store_local(DV_sym_24219_0_min, s_b_2_5);
    /* ???:4294967295 [F] s_b_2_7 = constant u8 1 (const) */
    /* execute.simd:18 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:18 [D] s_b_2_9 = s_b_2_8<s_b_2_5 */
    auto s_b_2_9 = emitter.cmp_lt(s_b_2_8, s_b_2_5);
    /* execute.simd:18 [D] s_b_2_10: If s_b_2_9: Jump b_3 else b_4 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_3;
        dynamic_block_queue.push(block_b_3);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_4;
        dynamic_block_queue.push(block_b_4);
        false_target = block;
      }
      emitter.branch(s_b_2_9, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_3 not fully fixed
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  // BLOCK b_6 not fully fixed
  // BLOCK b_7 not fully fixed
  // BLOCK b_8 not fully fixed
  // BLOCK b_9 not fully fixed
  // BLOCK b_10 not fully fixed
  // BLOCK b_11 not fully fixed
  // BLOCK b_12 not fully fixed
  // BLOCK b_13 not fully fixed
  // BLOCK b_14 not fully fixed
  // BLOCK b_15 not fully fixed
  // BLOCK b_16 not fully fixed
  /* b_0,  */
  fixed_block_b_17: 
  {
    /* execute.simd:27 [F] s_b_17_0=sym_24205_3_parameter_inst.rn (const) */
    /* execute.simd:27 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:27 [D] s_b_17_2 = (v16s8)s_b_17_1 */
    auto s_b_17_2 = emitter.reinterpret(s_b_17_1, emitter.context().types().v16s8());
    /* execute.simd:27 [D] s_b_17_3: sym_24352_0_rn = s_b_17_2, dominates: s_b_18_0 s_b_19_0 s_b_20_0 s_b_21_0 s_b_22_0 s_b_23_0 s_b_24_0 s_b_25_0 s_b_26_0 s_b_27_0 s_b_28_0 s_b_29_0 s_b_30_0 s_b_31_0 s_b_32_0 s_b_33_0 s_b_34_0 s_b_35_0 s_b_36_0 s_b_37_0 s_b_38_0 s_b_39_0 s_b_40_0 s_b_41_0 s_b_42_0 s_b_43_0 s_b_44_0 s_b_45_0 s_b_46_0  */
    emitter.store_local(DV_sym_24352_0_rn, s_b_17_2);
    /* execute.simd:29 [F] s_b_17_4 = constant s32 0 (const) */
    /* execute.simd:29 [D] s_b_17_2[s_b_17_4] */
    auto s_b_17_5 = emitter.vector_extract(s_b_17_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:29 [D] s_b_17_6: sym_24358_0_min = s_b_17_5, dominates: s_b_19_3 s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
    emitter.store_local(DV_sym_24358_0_min, s_b_17_5);
    /* ???:4294967295 [F] s_b_17_7 = constant u8 1 (const) */
    /* execute.simd:31 [D] s_b_17_2[s_b_17_7] */
    auto s_b_17_8 = emitter.vector_extract(s_b_17_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:31 [D] s_b_17_9 = s_b_17_8<s_b_17_5 */
    auto s_b_17_9 = emitter.cmp_lt(s_b_17_8, s_b_17_5);
    /* execute.simd:31 [D] s_b_17_10: If s_b_17_9: Jump b_18 else b_19 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_18;
        dynamic_block_queue.push(block_b_18);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_19;
        dynamic_block_queue.push(block_b_19);
        false_target = block;
      }
      emitter.branch(s_b_17_9, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_18 not fully fixed
  // BLOCK b_19 not fully fixed
  // BLOCK b_20 not fully fixed
  // BLOCK b_21 not fully fixed
  // BLOCK b_22 not fully fixed
  // BLOCK b_23 not fully fixed
  // BLOCK b_24 not fully fixed
  // BLOCK b_25 not fully fixed
  // BLOCK b_26 not fully fixed
  // BLOCK b_27 not fully fixed
  // BLOCK b_28 not fully fixed
  // BLOCK b_29 not fully fixed
  // BLOCK b_30 not fully fixed
  // BLOCK b_31 not fully fixed
  // BLOCK b_32 not fully fixed
  // BLOCK b_33 not fully fixed
  // BLOCK b_34 not fully fixed
  // BLOCK b_35 not fully fixed
  // BLOCK b_36 not fully fixed
  // BLOCK b_37 not fully fixed
  // BLOCK b_38 not fully fixed
  // BLOCK b_39 not fully fixed
  // BLOCK b_40 not fully fixed
  // BLOCK b_41 not fully fixed
  // BLOCK b_42 not fully fixed
  // BLOCK b_43 not fully fixed
  // BLOCK b_44 not fully fixed
  // BLOCK b_45 not fully fixed
  // BLOCK b_46 not fully fixed
  // BLOCK b_47 not fully fixed
  /* b_0,  */
  fixed_block_b_48: 
  {
    /* execute.simd:40 [F] s_b_48_0=sym_24205_3_parameter_inst.rn (const) */
    /* execute.simd:40 [D] s_b_48_1 = ReadRegBank 17:s_b_48_0 (v4u16) */
    auto s_b_48_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_48_1,emitter.const_u8(8));
    }
    /* execute.simd:40 [D] s_b_48_2 = (v4s16)s_b_48_1 */
    auto s_b_48_2 = emitter.reinterpret(s_b_48_1, emitter.context().types().v4s16());
    /* execute.simd:40 [D] s_b_48_3: sym_24627_0_rn = s_b_48_2, dominates: s_b_49_0 s_b_50_0 s_b_51_0 s_b_52_0 s_b_53_0  */
    emitter.store_local(DV_sym_24627_0_rn, s_b_48_2);
    /* execute.simd:42 [F] s_b_48_4 = constant s32 0 (const) */
    /* execute.simd:42 [D] s_b_48_2[s_b_48_4] */
    auto s_b_48_5 = emitter.vector_extract(s_b_48_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:42 [D] s_b_48_6: sym_24633_0_min = s_b_48_5, dominates: s_b_50_3 s_b_52_3 s_b_54_1  */
    emitter.store_local(DV_sym_24633_0_min, s_b_48_5);
    /* ???:4294967295 [F] s_b_48_7 = constant u8 1 (const) */
    /* execute.simd:44 [D] s_b_48_2[s_b_48_7] */
    auto s_b_48_8 = emitter.vector_extract(s_b_48_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:44 [D] s_b_48_9 = s_b_48_8<s_b_48_5 */
    auto s_b_48_9 = emitter.cmp_lt(s_b_48_8, s_b_48_5);
    /* execute.simd:44 [D] s_b_48_10: If s_b_48_9: Jump b_49 else b_50 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_49;
        dynamic_block_queue.push(block_b_49);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_50;
        dynamic_block_queue.push(block_b_50);
        false_target = block;
      }
      emitter.branch(s_b_48_9, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_49 not fully fixed
  // BLOCK b_50 not fully fixed
  // BLOCK b_51 not fully fixed
  // BLOCK b_52 not fully fixed
  // BLOCK b_53 not fully fixed
  // BLOCK b_54 not fully fixed
  /* b_0,  */
  fixed_block_b_55: 
  {
    /* execute.simd:53 [F] s_b_55_0=sym_24205_3_parameter_inst.rn (const) */
    /* execute.simd:53 [D] s_b_55_1 = ReadRegBank 18:s_b_55_0 (v8u16) */
    auto s_b_55_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_55_1,emitter.const_u8(16));
    }
    /* execute.simd:53 [D] s_b_55_2 = (v8s16)s_b_55_1 */
    auto s_b_55_2 = emitter.reinterpret(s_b_55_1, emitter.context().types().v8s16());
    /* execute.simd:53 [D] s_b_55_3: sym_24698_0_rn = s_b_55_2, dominates: s_b_56_0 s_b_57_0 s_b_58_0 s_b_59_0 s_b_60_0 s_b_61_0 s_b_62_0 s_b_63_0 s_b_64_0 s_b_65_0 s_b_66_0 s_b_67_0 s_b_68_0  */
    emitter.store_local(DV_sym_24698_0_rn, s_b_55_2);
    /* execute.simd:55 [F] s_b_55_4 = constant s32 0 (const) */
    /* execute.simd:55 [D] s_b_55_2[s_b_55_4] */
    auto s_b_55_5 = emitter.vector_extract(s_b_55_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:55 [D] s_b_55_6: sym_24704_0_min = s_b_55_5, dominates: s_b_57_3 s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
    emitter.store_local(DV_sym_24704_0_min, s_b_55_5);
    /* ???:4294967295 [F] s_b_55_7 = constant u8 1 (const) */
    /* execute.simd:57 [D] s_b_55_2[s_b_55_7] */
    auto s_b_55_8 = emitter.vector_extract(s_b_55_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:57 [D] s_b_55_9 = s_b_55_8<s_b_55_5 */
    auto s_b_55_9 = emitter.cmp_lt(s_b_55_8, s_b_55_5);
    /* execute.simd:57 [D] s_b_55_10: If s_b_55_9: Jump b_56 else b_57 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_56;
        dynamic_block_queue.push(block_b_56);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_57;
        dynamic_block_queue.push(block_b_57);
        false_target = block;
      }
      emitter.branch(s_b_55_9, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_56 not fully fixed
  // BLOCK b_57 not fully fixed
  // BLOCK b_58 not fully fixed
  // BLOCK b_59 not fully fixed
  // BLOCK b_60 not fully fixed
  // BLOCK b_61 not fully fixed
  // BLOCK b_62 not fully fixed
  // BLOCK b_63 not fully fixed
  // BLOCK b_64 not fully fixed
  // BLOCK b_65 not fully fixed
  // BLOCK b_66 not fully fixed
  // BLOCK b_67 not fully fixed
  // BLOCK b_68 not fully fixed
  // BLOCK b_69 not fully fixed
  /* b_0,  */
  fixed_block_b_70: 
  {
    /* execute.simd:66 [F] s_b_70_0=sym_24205_3_parameter_inst.rn (const) */
    /* execute.simd:66 [D] s_b_70_1 = ReadRegBank 20:s_b_70_0 (v4u32) */
    auto s_b_70_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_70_1,emitter.const_u8(16));
    }
    /* execute.simd:66 [D] s_b_70_2 = (v4s32)s_b_70_1 */
    auto s_b_70_2 = emitter.reinterpret(s_b_70_1, emitter.context().types().v4s32());
    /* execute.simd:66 [D] s_b_70_3: sym_24837_0_rn = s_b_70_2, dominates: s_b_71_0 s_b_72_0 s_b_73_0 s_b_74_0 s_b_75_0  */
    emitter.store_local(DV_sym_24837_0_rn, s_b_70_2);
    /* execute.simd:68 [F] s_b_70_4 = constant s32 0 (const) */
    /* execute.simd:68 [D] s_b_70_2[s_b_70_4] */
    auto s_b_70_5 = emitter.vector_extract(s_b_70_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:68 [D] s_b_70_6: sym_24843_0_min = s_b_70_5, dominates: s_b_72_3 s_b_74_3 s_b_76_1  */
    emitter.store_local(DV_sym_24843_0_min, s_b_70_5);
    /* ???:4294967295 [F] s_b_70_7 = constant u8 1 (const) */
    /* execute.simd:70 [D] s_b_70_2[s_b_70_7] */
    auto s_b_70_8 = emitter.vector_extract(s_b_70_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:70 [D] s_b_70_9 = s_b_70_8<s_b_70_5 */
    auto s_b_70_9 = emitter.cmp_lt(s_b_70_8, s_b_70_5);
    /* execute.simd:70 [D] s_b_70_10: If s_b_70_9: Jump b_71 else b_72 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_71;
        dynamic_block_queue.push(block_b_71);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_72;
        dynamic_block_queue.push(block_b_72);
        false_target = block;
      }
      emitter.branch(s_b_70_9, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_71 not fully fixed
  // BLOCK b_72 not fully fixed
  // BLOCK b_73 not fully fixed
  // BLOCK b_74 not fully fixed
  // BLOCK b_75 not fully fixed
  // BLOCK b_76 not fully fixed
  /* b_0,  */
  fixed_block_b_77: 
  {
    /* execute.simd:79 [D] s_b_77_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_77_1: Jump b_1 (const) */
    {
      auto block = block_b_1;
      dynamic_block_queue.push(block_b_1);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  fixed_done:
  if (dynamic_block_queue.size() > 0) 
  {
    std::set<captive::arch::dbt::el::Block *> emitted_blocks;
    while (dynamic_block_queue.size() > 0) 
    {
      captive::arch::dbt::el::Block *block_index = dynamic_block_queue.front();
      dynamic_block_queue.pop();
      if (emitted_blocks.count(block_index)) continue;
      emitted_blocks.insert(block_index);
      if (block_index == block_b_1) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_1);
        /* ???:4294967295 [F] s_b_1_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_3) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_3);
        /* execute.simd:19 [D] s_b_3_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_3_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_3_1 = constant u8 1 (const) */
        /* execute.simd:19 [D] s_b_3_0[s_b_3_1] */
        auto s_b_3_2 = emitter.vector_extract(s_b_3_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:19 [D] s_b_3_3: sym_24219_0_min = s_b_3_2, dominates: s_b_4_3 s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_24219_0_min, s_b_3_2);
        /* execute.simd:19 [F] s_b_3_4: Jump b_4 (const) */
        {
          auto block = block_b_4;
          dynamic_block_queue.push(block_b_4);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.simd:18 [D] s_b_4_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_4_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_4_1 = constant u8 2 (const) */
        /* execute.simd:18 [D] s_b_4_0[s_b_4_1] */
        auto s_b_4_2 = emitter.vector_extract(s_b_4_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:18 [D] s_b_4_3 = sym_24219_0_min int8_t */
        auto s_b_4_3 = emitter.load_local(DV_sym_24219_0_min, emitter.context().types().s8());
        /* execute.simd:18 [D] s_b_4_4 = s_b_4_2<s_b_4_3 */
        auto s_b_4_4 = emitter.cmp_lt(s_b_4_2, s_b_4_3);
        /* execute.simd:18 [D] s_b_4_5: If s_b_4_4: Jump b_5 else b_6 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_5;
            dynamic_block_queue.push(block_b_5);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_6;
            dynamic_block_queue.push(block_b_6);
            false_target = block;
          }
          emitter.branch(s_b_4_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:19 [D] s_b_5_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_5_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_5_1 = constant u8 2 (const) */
        /* execute.simd:19 [D] s_b_5_0[s_b_5_1] */
        auto s_b_5_2 = emitter.vector_extract(s_b_5_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:19 [D] s_b_5_3: sym_24219_0_min = s_b_5_2, dominates: s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_24219_0_min, s_b_5_2);
        /* execute.simd:19 [F] s_b_5_4: Jump b_6 (const) */
        {
          auto block = block_b_6;
          dynamic_block_queue.push(block_b_6);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:18 [D] s_b_6_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_6_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_6_1 = constant u8 3 (const) */
        /* execute.simd:18 [D] s_b_6_0[s_b_6_1] */
        auto s_b_6_2 = emitter.vector_extract(s_b_6_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:18 [D] s_b_6_3 = sym_24219_0_min int8_t */
        auto s_b_6_3 = emitter.load_local(DV_sym_24219_0_min, emitter.context().types().s8());
        /* execute.simd:18 [D] s_b_6_4 = s_b_6_2<s_b_6_3 */
        auto s_b_6_4 = emitter.cmp_lt(s_b_6_2, s_b_6_3);
        /* execute.simd:18 [D] s_b_6_5: If s_b_6_4: Jump b_7 else b_8 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_7;
            dynamic_block_queue.push(block_b_7);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_8;
            dynamic_block_queue.push(block_b_8);
            false_target = block;
          }
          emitter.branch(s_b_6_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.simd:19 [D] s_b_7_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_7_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_7_1 = constant u8 3 (const) */
        /* execute.simd:19 [D] s_b_7_0[s_b_7_1] */
        auto s_b_7_2 = emitter.vector_extract(s_b_7_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:19 [D] s_b_7_3: sym_24219_0_min = s_b_7_2, dominates: s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_24219_0_min, s_b_7_2);
        /* execute.simd:19 [F] s_b_7_4: Jump b_8 (const) */
        {
          auto block = block_b_8;
          dynamic_block_queue.push(block_b_8);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.simd:18 [D] s_b_8_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_8_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_8_1 = constant u8 4 (const) */
        /* execute.simd:18 [D] s_b_8_0[s_b_8_1] */
        auto s_b_8_2 = emitter.vector_extract(s_b_8_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:18 [D] s_b_8_3 = sym_24219_0_min int8_t */
        auto s_b_8_3 = emitter.load_local(DV_sym_24219_0_min, emitter.context().types().s8());
        /* execute.simd:18 [D] s_b_8_4 = s_b_8_2<s_b_8_3 */
        auto s_b_8_4 = emitter.cmp_lt(s_b_8_2, s_b_8_3);
        /* execute.simd:18 [D] s_b_8_5: If s_b_8_4: Jump b_9 else b_10 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_9;
            dynamic_block_queue.push(block_b_9);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_10;
            dynamic_block_queue.push(block_b_10);
            false_target = block;
          }
          emitter.branch(s_b_8_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.simd:19 [D] s_b_9_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_9_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_9_1 = constant u8 4 (const) */
        /* execute.simd:19 [D] s_b_9_0[s_b_9_1] */
        auto s_b_9_2 = emitter.vector_extract(s_b_9_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:19 [D] s_b_9_3: sym_24219_0_min = s_b_9_2, dominates: s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_24219_0_min, s_b_9_2);
        /* execute.simd:19 [F] s_b_9_4: Jump b_10 (const) */
        {
          auto block = block_b_10;
          dynamic_block_queue.push(block_b_10);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.simd:18 [D] s_b_10_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_10_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_10_1 = constant u8 5 (const) */
        /* execute.simd:18 [D] s_b_10_0[s_b_10_1] */
        auto s_b_10_2 = emitter.vector_extract(s_b_10_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:18 [D] s_b_10_3 = sym_24219_0_min int8_t */
        auto s_b_10_3 = emitter.load_local(DV_sym_24219_0_min, emitter.context().types().s8());
        /* execute.simd:18 [D] s_b_10_4 = s_b_10_2<s_b_10_3 */
        auto s_b_10_4 = emitter.cmp_lt(s_b_10_2, s_b_10_3);
        /* execute.simd:18 [D] s_b_10_5: If s_b_10_4: Jump b_11 else b_12 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_11;
            dynamic_block_queue.push(block_b_11);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_12;
            dynamic_block_queue.push(block_b_12);
            false_target = block;
          }
          emitter.branch(s_b_10_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* execute.simd:19 [D] s_b_11_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_11_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_11_1 = constant u8 5 (const) */
        /* execute.simd:19 [D] s_b_11_0[s_b_11_1] */
        auto s_b_11_2 = emitter.vector_extract(s_b_11_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:19 [D] s_b_11_3: sym_24219_0_min = s_b_11_2, dominates: s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_24219_0_min, s_b_11_2);
        /* execute.simd:19 [F] s_b_11_4: Jump b_12 (const) */
        {
          auto block = block_b_12;
          dynamic_block_queue.push(block_b_12);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.simd:18 [D] s_b_12_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_12_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_12_1 = constant u8 6 (const) */
        /* execute.simd:18 [D] s_b_12_0[s_b_12_1] */
        auto s_b_12_2 = emitter.vector_extract(s_b_12_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:18 [D] s_b_12_3 = sym_24219_0_min int8_t */
        auto s_b_12_3 = emitter.load_local(DV_sym_24219_0_min, emitter.context().types().s8());
        /* execute.simd:18 [D] s_b_12_4 = s_b_12_2<s_b_12_3 */
        auto s_b_12_4 = emitter.cmp_lt(s_b_12_2, s_b_12_3);
        /* execute.simd:18 [D] s_b_12_5: If s_b_12_4: Jump b_13 else b_14 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_13;
            dynamic_block_queue.push(block_b_13);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_14;
            dynamic_block_queue.push(block_b_14);
            false_target = block;
          }
          emitter.branch(s_b_12_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.simd:19 [D] s_b_13_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_13_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_13_1 = constant u8 6 (const) */
        /* execute.simd:19 [D] s_b_13_0[s_b_13_1] */
        auto s_b_13_2 = emitter.vector_extract(s_b_13_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:19 [D] s_b_13_3: sym_24219_0_min = s_b_13_2, dominates: s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_24219_0_min, s_b_13_2);
        /* execute.simd:19 [F] s_b_13_4: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.simd:18 [D] s_b_14_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_14_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_14_1 = constant u8 7 (const) */
        /* execute.simd:18 [D] s_b_14_0[s_b_14_1] */
        auto s_b_14_2 = emitter.vector_extract(s_b_14_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:18 [D] s_b_14_3 = sym_24219_0_min int8_t */
        auto s_b_14_3 = emitter.load_local(DV_sym_24219_0_min, emitter.context().types().s8());
        /* execute.simd:18 [D] s_b_14_4 = s_b_14_2<s_b_14_3 */
        auto s_b_14_4 = emitter.cmp_lt(s_b_14_2, s_b_14_3);
        /* execute.simd:18 [D] s_b_14_5: If s_b_14_4: Jump b_15 else b_16 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_15;
            dynamic_block_queue.push(block_b_15);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_16;
            dynamic_block_queue.push(block_b_16);
            false_target = block;
          }
          emitter.branch(s_b_14_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.simd:19 [D] s_b_15_0 = sym_24213_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_15_0 = emitter.load_local(DV_sym_24213_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_15_1 = constant u8 7 (const) */
        /* execute.simd:19 [D] s_b_15_0[s_b_15_1] */
        auto s_b_15_2 = emitter.vector_extract(s_b_15_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:19 [D] s_b_15_3: sym_24219_0_min = s_b_15_2, dominates: s_b_16_1  */
        emitter.store_local(DV_sym_24219_0_min, s_b_15_2);
        /* execute.simd:19 [F] s_b_15_4: Jump b_16 (const) */
        {
          auto block = block_b_16;
          dynamic_block_queue.push(block_b_16);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.simd:23 [F] s_b_16_0=sym_24205_3_parameter_inst.rd (const) */
        /* execute.simd:23 [D] s_b_16_1 = sym_24219_0_min int8_t */
        auto s_b_16_1 = emitter.load_local(DV_sym_24219_0_min, emitter.context().types().s8());
        /* execute.simd:23 [D] s_b_16_2 = (u8)s_b_16_1 */
        auto s_b_16_2 = emitter.reinterpret(s_b_16_1, emitter.context().types().u8());
        /* execute.simd:6305 [D] s_b_16_3 = (u64)s_b_16_2 */
        auto s_b_16_3 = emitter.zx(s_b_16_2, emitter.context().types().u64());
        /* execute.simd:6305 [D] s_b_16_4: WriteRegBank 2:s_b_16_0 = s_b_16_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_3);
        /* execute.simd:6306 [F] s_b_16_5 = constant u64 0 (const) */
        /* execute.simd:6306 [F] s_b_16_6: WriteRegBank 3:s_b_16_0 = s_b_16_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_16_7: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.simd:32 [D] s_b_18_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_18_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_18_1 = constant u8 1 (const) */
        /* execute.simd:32 [D] s_b_18_0[s_b_18_1] */
        auto s_b_18_2 = emitter.vector_extract(s_b_18_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:32 [D] s_b_18_3: sym_24358_0_min = s_b_18_2, dominates: s_b_19_3 s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_18_2);
        /* execute.simd:32 [F] s_b_18_4: Jump b_19 (const) */
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.simd:31 [D] s_b_19_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_19_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_19_1 = constant u8 2 (const) */
        /* execute.simd:31 [D] s_b_19_0[s_b_19_1] */
        auto s_b_19_2 = emitter.vector_extract(s_b_19_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:31 [D] s_b_19_3 = sym_24358_0_min int8_t */
        auto s_b_19_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_19_4 = s_b_19_2<s_b_19_3 */
        auto s_b_19_4 = emitter.cmp_lt(s_b_19_2, s_b_19_3);
        /* execute.simd:31 [D] s_b_19_5: If s_b_19_4: Jump b_20 else b_21 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_20;
            dynamic_block_queue.push(block_b_20);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_21;
            dynamic_block_queue.push(block_b_21);
            false_target = block;
          }
          emitter.branch(s_b_19_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.simd:32 [D] s_b_20_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_20_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_20_1 = constant u8 2 (const) */
        /* execute.simd:32 [D] s_b_20_0[s_b_20_1] */
        auto s_b_20_2 = emitter.vector_extract(s_b_20_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:32 [D] s_b_20_3: sym_24358_0_min = s_b_20_2, dominates: s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_20_2);
        /* execute.simd:32 [F] s_b_20_4: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.simd:31 [D] s_b_21_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_21_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_21_1 = constant u8 3 (const) */
        /* execute.simd:31 [D] s_b_21_0[s_b_21_1] */
        auto s_b_21_2 = emitter.vector_extract(s_b_21_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:31 [D] s_b_21_3 = sym_24358_0_min int8_t */
        auto s_b_21_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_21_4 = s_b_21_2<s_b_21_3 */
        auto s_b_21_4 = emitter.cmp_lt(s_b_21_2, s_b_21_3);
        /* execute.simd:31 [D] s_b_21_5: If s_b_21_4: Jump b_22 else b_23 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_22;
            dynamic_block_queue.push(block_b_22);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_23;
            dynamic_block_queue.push(block_b_23);
            false_target = block;
          }
          emitter.branch(s_b_21_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.simd:32 [D] s_b_22_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_22_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_22_1 = constant u8 3 (const) */
        /* execute.simd:32 [D] s_b_22_0[s_b_22_1] */
        auto s_b_22_2 = emitter.vector_extract(s_b_22_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:32 [D] s_b_22_3: sym_24358_0_min = s_b_22_2, dominates: s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_22_2);
        /* execute.simd:32 [F] s_b_22_4: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.simd:31 [D] s_b_23_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_23_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_23_1 = constant u8 4 (const) */
        /* execute.simd:31 [D] s_b_23_0[s_b_23_1] */
        auto s_b_23_2 = emitter.vector_extract(s_b_23_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:31 [D] s_b_23_3 = sym_24358_0_min int8_t */
        auto s_b_23_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_23_4 = s_b_23_2<s_b_23_3 */
        auto s_b_23_4 = emitter.cmp_lt(s_b_23_2, s_b_23_3);
        /* execute.simd:31 [D] s_b_23_5: If s_b_23_4: Jump b_24 else b_25 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_24;
            dynamic_block_queue.push(block_b_24);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_25;
            dynamic_block_queue.push(block_b_25);
            false_target = block;
          }
          emitter.branch(s_b_23_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.simd:32 [D] s_b_24_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_24_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_24_1 = constant u8 4 (const) */
        /* execute.simd:32 [D] s_b_24_0[s_b_24_1] */
        auto s_b_24_2 = emitter.vector_extract(s_b_24_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:32 [D] s_b_24_3: sym_24358_0_min = s_b_24_2, dominates: s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_24_2);
        /* execute.simd:32 [F] s_b_24_4: Jump b_25 (const) */
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.simd:31 [D] s_b_25_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_25_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_25_1 = constant u8 5 (const) */
        /* execute.simd:31 [D] s_b_25_0[s_b_25_1] */
        auto s_b_25_2 = emitter.vector_extract(s_b_25_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:31 [D] s_b_25_3 = sym_24358_0_min int8_t */
        auto s_b_25_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_25_4 = s_b_25_2<s_b_25_3 */
        auto s_b_25_4 = emitter.cmp_lt(s_b_25_2, s_b_25_3);
        /* execute.simd:31 [D] s_b_25_5: If s_b_25_4: Jump b_26 else b_27 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_26;
            dynamic_block_queue.push(block_b_26);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_27;
            dynamic_block_queue.push(block_b_27);
            false_target = block;
          }
          emitter.branch(s_b_25_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.simd:32 [D] s_b_26_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_26_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_26_1 = constant u8 5 (const) */
        /* execute.simd:32 [D] s_b_26_0[s_b_26_1] */
        auto s_b_26_2 = emitter.vector_extract(s_b_26_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:32 [D] s_b_26_3: sym_24358_0_min = s_b_26_2, dominates: s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_26_2);
        /* execute.simd:32 [F] s_b_26_4: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.simd:31 [D] s_b_27_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_27_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_27_1 = constant u8 6 (const) */
        /* execute.simd:31 [D] s_b_27_0[s_b_27_1] */
        auto s_b_27_2 = emitter.vector_extract(s_b_27_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:31 [D] s_b_27_3 = sym_24358_0_min int8_t */
        auto s_b_27_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_27_4 = s_b_27_2<s_b_27_3 */
        auto s_b_27_4 = emitter.cmp_lt(s_b_27_2, s_b_27_3);
        /* execute.simd:31 [D] s_b_27_5: If s_b_27_4: Jump b_28 else b_29 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_28;
            dynamic_block_queue.push(block_b_28);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_29;
            dynamic_block_queue.push(block_b_29);
            false_target = block;
          }
          emitter.branch(s_b_27_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.simd:32 [D] s_b_28_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_28_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_28_1 = constant u8 6 (const) */
        /* execute.simd:32 [D] s_b_28_0[s_b_28_1] */
        auto s_b_28_2 = emitter.vector_extract(s_b_28_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:32 [D] s_b_28_3: sym_24358_0_min = s_b_28_2, dominates: s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_28_2);
        /* execute.simd:32 [F] s_b_28_4: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.simd:31 [D] s_b_29_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_29_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_29_1 = constant u8 7 (const) */
        /* execute.simd:31 [D] s_b_29_0[s_b_29_1] */
        auto s_b_29_2 = emitter.vector_extract(s_b_29_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:31 [D] s_b_29_3 = sym_24358_0_min int8_t */
        auto s_b_29_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_29_4 = s_b_29_2<s_b_29_3 */
        auto s_b_29_4 = emitter.cmp_lt(s_b_29_2, s_b_29_3);
        /* execute.simd:31 [D] s_b_29_5: If s_b_29_4: Jump b_30 else b_31 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_30;
            dynamic_block_queue.push(block_b_30);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_31;
            dynamic_block_queue.push(block_b_31);
            false_target = block;
          }
          emitter.branch(s_b_29_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.simd:32 [D] s_b_30_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_30_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_30_1 = constant u8 7 (const) */
        /* execute.simd:32 [D] s_b_30_0[s_b_30_1] */
        auto s_b_30_2 = emitter.vector_extract(s_b_30_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:32 [D] s_b_30_3: sym_24358_0_min = s_b_30_2, dominates: s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_30_2);
        /* execute.simd:32 [F] s_b_30_4: Jump b_31 (const) */
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.simd:31 [D] s_b_31_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_31_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_31_1 = constant u8 8 (const) */
        /* execute.simd:31 [D] s_b_31_0[s_b_31_1] */
        auto s_b_31_2 = emitter.vector_extract(s_b_31_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:31 [D] s_b_31_3 = sym_24358_0_min int8_t */
        auto s_b_31_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_31_4 = s_b_31_2<s_b_31_3 */
        auto s_b_31_4 = emitter.cmp_lt(s_b_31_2, s_b_31_3);
        /* execute.simd:31 [D] s_b_31_5: If s_b_31_4: Jump b_32 else b_33 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_32;
            dynamic_block_queue.push(block_b_32);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_33;
            dynamic_block_queue.push(block_b_33);
            false_target = block;
          }
          emitter.branch(s_b_31_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.simd:32 [D] s_b_32_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_32_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_32_1 = constant u8 8 (const) */
        /* execute.simd:32 [D] s_b_32_0[s_b_32_1] */
        auto s_b_32_2 = emitter.vector_extract(s_b_32_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:32 [D] s_b_32_3: sym_24358_0_min = s_b_32_2, dominates: s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_32_2);
        /* execute.simd:32 [F] s_b_32_4: Jump b_33 (const) */
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.simd:31 [D] s_b_33_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_33_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_33_1 = constant u8 9 (const) */
        /* execute.simd:31 [D] s_b_33_0[s_b_33_1] */
        auto s_b_33_2 = emitter.vector_extract(s_b_33_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:31 [D] s_b_33_3 = sym_24358_0_min int8_t */
        auto s_b_33_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_33_4 = s_b_33_2<s_b_33_3 */
        auto s_b_33_4 = emitter.cmp_lt(s_b_33_2, s_b_33_3);
        /* execute.simd:31 [D] s_b_33_5: If s_b_33_4: Jump b_34 else b_35 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_34;
            dynamic_block_queue.push(block_b_34);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_35;
            dynamic_block_queue.push(block_b_35);
            false_target = block;
          }
          emitter.branch(s_b_33_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.simd:32 [D] s_b_34_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_34_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_34_1 = constant u8 9 (const) */
        /* execute.simd:32 [D] s_b_34_0[s_b_34_1] */
        auto s_b_34_2 = emitter.vector_extract(s_b_34_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:32 [D] s_b_34_3: sym_24358_0_min = s_b_34_2, dominates: s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_34_2);
        /* execute.simd:32 [F] s_b_34_4: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.simd:31 [D] s_b_35_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_35_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_35_1 = constant u8 a (const) */
        /* execute.simd:31 [D] s_b_35_0[s_b_35_1] */
        auto s_b_35_2 = emitter.vector_extract(s_b_35_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:31 [D] s_b_35_3 = sym_24358_0_min int8_t */
        auto s_b_35_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_35_4 = s_b_35_2<s_b_35_3 */
        auto s_b_35_4 = emitter.cmp_lt(s_b_35_2, s_b_35_3);
        /* execute.simd:31 [D] s_b_35_5: If s_b_35_4: Jump b_36 else b_37 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_36;
            dynamic_block_queue.push(block_b_36);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_37;
            dynamic_block_queue.push(block_b_37);
            false_target = block;
          }
          emitter.branch(s_b_35_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_36) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_36);
        /* execute.simd:32 [D] s_b_36_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_36_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_36_1 = constant u8 a (const) */
        /* execute.simd:32 [D] s_b_36_0[s_b_36_1] */
        auto s_b_36_2 = emitter.vector_extract(s_b_36_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:32 [D] s_b_36_3: sym_24358_0_min = s_b_36_2, dominates: s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_36_2);
        /* execute.simd:32 [F] s_b_36_4: Jump b_37 (const) */
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.simd:31 [D] s_b_37_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_37_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_37_1 = constant u8 b (const) */
        /* execute.simd:31 [D] s_b_37_0[s_b_37_1] */
        auto s_b_37_2 = emitter.vector_extract(s_b_37_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:31 [D] s_b_37_3 = sym_24358_0_min int8_t */
        auto s_b_37_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_37_4 = s_b_37_2<s_b_37_3 */
        auto s_b_37_4 = emitter.cmp_lt(s_b_37_2, s_b_37_3);
        /* execute.simd:31 [D] s_b_37_5: If s_b_37_4: Jump b_38 else b_39 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_38;
            dynamic_block_queue.push(block_b_38);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_39;
            dynamic_block_queue.push(block_b_39);
            false_target = block;
          }
          emitter.branch(s_b_37_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_38) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_38);
        /* execute.simd:32 [D] s_b_38_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_38_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_38_1 = constant u8 b (const) */
        /* execute.simd:32 [D] s_b_38_0[s_b_38_1] */
        auto s_b_38_2 = emitter.vector_extract(s_b_38_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:32 [D] s_b_38_3: sym_24358_0_min = s_b_38_2, dominates: s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_38_2);
        /* execute.simd:32 [F] s_b_38_4: Jump b_39 (const) */
        {
          auto block = block_b_39;
          dynamic_block_queue.push(block_b_39);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.simd:31 [D] s_b_39_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_39_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_39_1 = constant u8 c (const) */
        /* execute.simd:31 [D] s_b_39_0[s_b_39_1] */
        auto s_b_39_2 = emitter.vector_extract(s_b_39_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:31 [D] s_b_39_3 = sym_24358_0_min int8_t */
        auto s_b_39_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_39_4 = s_b_39_2<s_b_39_3 */
        auto s_b_39_4 = emitter.cmp_lt(s_b_39_2, s_b_39_3);
        /* execute.simd:31 [D] s_b_39_5: If s_b_39_4: Jump b_40 else b_41 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_40;
            dynamic_block_queue.push(block_b_40);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_41;
            dynamic_block_queue.push(block_b_41);
            false_target = block;
          }
          emitter.branch(s_b_39_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_40) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_40);
        /* execute.simd:32 [D] s_b_40_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_40_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_40_1 = constant u8 c (const) */
        /* execute.simd:32 [D] s_b_40_0[s_b_40_1] */
        auto s_b_40_2 = emitter.vector_extract(s_b_40_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:32 [D] s_b_40_3: sym_24358_0_min = s_b_40_2, dominates: s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_40_2);
        /* execute.simd:32 [F] s_b_40_4: Jump b_41 (const) */
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.simd:31 [D] s_b_41_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_41_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_41_1 = constant u8 d (const) */
        /* execute.simd:31 [D] s_b_41_0[s_b_41_1] */
        auto s_b_41_2 = emitter.vector_extract(s_b_41_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:31 [D] s_b_41_3 = sym_24358_0_min int8_t */
        auto s_b_41_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_41_4 = s_b_41_2<s_b_41_3 */
        auto s_b_41_4 = emitter.cmp_lt(s_b_41_2, s_b_41_3);
        /* execute.simd:31 [D] s_b_41_5: If s_b_41_4: Jump b_42 else b_43 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_42;
            dynamic_block_queue.push(block_b_42);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_43;
            dynamic_block_queue.push(block_b_43);
            false_target = block;
          }
          emitter.branch(s_b_41_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_42) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_42);
        /* execute.simd:32 [D] s_b_42_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_42_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_42_1 = constant u8 d (const) */
        /* execute.simd:32 [D] s_b_42_0[s_b_42_1] */
        auto s_b_42_2 = emitter.vector_extract(s_b_42_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:32 [D] s_b_42_3: sym_24358_0_min = s_b_42_2, dominates: s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_42_2);
        /* execute.simd:32 [F] s_b_42_4: Jump b_43 (const) */
        {
          auto block = block_b_43;
          dynamic_block_queue.push(block_b_43);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_43) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_43);
        /* execute.simd:31 [D] s_b_43_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_43_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_43_1 = constant u8 e (const) */
        /* execute.simd:31 [D] s_b_43_0[s_b_43_1] */
        auto s_b_43_2 = emitter.vector_extract(s_b_43_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:31 [D] s_b_43_3 = sym_24358_0_min int8_t */
        auto s_b_43_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_43_4 = s_b_43_2<s_b_43_3 */
        auto s_b_43_4 = emitter.cmp_lt(s_b_43_2, s_b_43_3);
        /* execute.simd:31 [D] s_b_43_5: If s_b_43_4: Jump b_44 else b_45 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_44;
            dynamic_block_queue.push(block_b_44);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_45;
            dynamic_block_queue.push(block_b_45);
            false_target = block;
          }
          emitter.branch(s_b_43_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_44) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_44);
        /* execute.simd:32 [D] s_b_44_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_44_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_44_1 = constant u8 e (const) */
        /* execute.simd:32 [D] s_b_44_0[s_b_44_1] */
        auto s_b_44_2 = emitter.vector_extract(s_b_44_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:32 [D] s_b_44_3: sym_24358_0_min = s_b_44_2, dominates: s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_44_2);
        /* execute.simd:32 [F] s_b_44_4: Jump b_45 (const) */
        {
          auto block = block_b_45;
          dynamic_block_queue.push(block_b_45);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_45) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_45);
        /* execute.simd:31 [D] s_b_45_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_45_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_45_1 = constant u8 f (const) */
        /* execute.simd:31 [D] s_b_45_0[s_b_45_1] */
        auto s_b_45_2 = emitter.vector_extract(s_b_45_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:31 [D] s_b_45_3 = sym_24358_0_min int8_t */
        auto s_b_45_3 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:31 [D] s_b_45_4 = s_b_45_2<s_b_45_3 */
        auto s_b_45_4 = emitter.cmp_lt(s_b_45_2, s_b_45_3);
        /* execute.simd:31 [D] s_b_45_5: If s_b_45_4: Jump b_46 else b_47 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_46;
            dynamic_block_queue.push(block_b_46);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_47;
            dynamic_block_queue.push(block_b_47);
            false_target = block;
          }
          emitter.branch(s_b_45_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_46) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_46);
        /* execute.simd:32 [D] s_b_46_0 = sym_24352_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_46_0 = emitter.load_local(DV_sym_24352_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_46_1 = constant u8 f (const) */
        /* execute.simd:32 [D] s_b_46_0[s_b_46_1] */
        auto s_b_46_2 = emitter.vector_extract(s_b_46_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:32 [D] s_b_46_3: sym_24358_0_min = s_b_46_2, dominates: s_b_47_1  */
        emitter.store_local(DV_sym_24358_0_min, s_b_46_2);
        /* execute.simd:32 [F] s_b_46_4: Jump b_47 (const) */
        {
          auto block = block_b_47;
          dynamic_block_queue.push(block_b_47);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_47) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_47);
        /* execute.simd:36 [F] s_b_47_0=sym_24205_3_parameter_inst.rd (const) */
        /* execute.simd:36 [D] s_b_47_1 = sym_24358_0_min int8_t */
        auto s_b_47_1 = emitter.load_local(DV_sym_24358_0_min, emitter.context().types().s8());
        /* execute.simd:36 [D] s_b_47_2 = (u8)s_b_47_1 */
        auto s_b_47_2 = emitter.reinterpret(s_b_47_1, emitter.context().types().u8());
        /* execute.simd:6305 [D] s_b_47_3 = (u64)s_b_47_2 */
        auto s_b_47_3 = emitter.zx(s_b_47_2, emitter.context().types().u64());
        /* execute.simd:6305 [D] s_b_47_4: WriteRegBank 2:s_b_47_0 = s_b_47_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_47_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_47_3);
        /* execute.simd:6306 [F] s_b_47_5 = constant u64 0 (const) */
        /* execute.simd:6306 [F] s_b_47_6: WriteRegBank 3:s_b_47_0 = s_b_47_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_47_7: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_49) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_49);
        /* execute.simd:45 [D] s_b_49_0 = sym_24627_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_49_0 = emitter.load_local(DV_sym_24627_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_49_1 = constant u8 1 (const) */
        /* execute.simd:45 [D] s_b_49_0[s_b_49_1] */
        auto s_b_49_2 = emitter.vector_extract(s_b_49_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:45 [D] s_b_49_3: sym_24633_0_min = s_b_49_2, dominates: s_b_50_3 s_b_52_3 s_b_54_1  */
        emitter.store_local(DV_sym_24633_0_min, s_b_49_2);
        /* execute.simd:45 [F] s_b_49_4: Jump b_50 (const) */
        {
          auto block = block_b_50;
          dynamic_block_queue.push(block_b_50);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_50) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_50);
        /* execute.simd:44 [D] s_b_50_0 = sym_24627_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_50_0 = emitter.load_local(DV_sym_24627_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_50_1 = constant u8 2 (const) */
        /* execute.simd:44 [D] s_b_50_0[s_b_50_1] */
        auto s_b_50_2 = emitter.vector_extract(s_b_50_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:44 [D] s_b_50_3 = sym_24633_0_min int16_t */
        auto s_b_50_3 = emitter.load_local(DV_sym_24633_0_min, emitter.context().types().s16());
        /* execute.simd:44 [D] s_b_50_4 = s_b_50_2<s_b_50_3 */
        auto s_b_50_4 = emitter.cmp_lt(s_b_50_2, s_b_50_3);
        /* execute.simd:44 [D] s_b_50_5: If s_b_50_4: Jump b_51 else b_52 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_51;
            dynamic_block_queue.push(block_b_51);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_52;
            dynamic_block_queue.push(block_b_52);
            false_target = block;
          }
          emitter.branch(s_b_50_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_51) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_51);
        /* execute.simd:45 [D] s_b_51_0 = sym_24627_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_51_0 = emitter.load_local(DV_sym_24627_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_51_1 = constant u8 2 (const) */
        /* execute.simd:45 [D] s_b_51_0[s_b_51_1] */
        auto s_b_51_2 = emitter.vector_extract(s_b_51_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:45 [D] s_b_51_3: sym_24633_0_min = s_b_51_2, dominates: s_b_52_3 s_b_54_1  */
        emitter.store_local(DV_sym_24633_0_min, s_b_51_2);
        /* execute.simd:45 [F] s_b_51_4: Jump b_52 (const) */
        {
          auto block = block_b_52;
          dynamic_block_queue.push(block_b_52);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_52) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_52);
        /* execute.simd:44 [D] s_b_52_0 = sym_24627_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_52_0 = emitter.load_local(DV_sym_24627_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_52_1 = constant u8 3 (const) */
        /* execute.simd:44 [D] s_b_52_0[s_b_52_1] */
        auto s_b_52_2 = emitter.vector_extract(s_b_52_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:44 [D] s_b_52_3 = sym_24633_0_min int16_t */
        auto s_b_52_3 = emitter.load_local(DV_sym_24633_0_min, emitter.context().types().s16());
        /* execute.simd:44 [D] s_b_52_4 = s_b_52_2<s_b_52_3 */
        auto s_b_52_4 = emitter.cmp_lt(s_b_52_2, s_b_52_3);
        /* execute.simd:44 [D] s_b_52_5: If s_b_52_4: Jump b_53 else b_54 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_53;
            dynamic_block_queue.push(block_b_53);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_54;
            dynamic_block_queue.push(block_b_54);
            false_target = block;
          }
          emitter.branch(s_b_52_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_53) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_53);
        /* execute.simd:45 [D] s_b_53_0 = sym_24627_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_53_0 = emitter.load_local(DV_sym_24627_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_53_1 = constant u8 3 (const) */
        /* execute.simd:45 [D] s_b_53_0[s_b_53_1] */
        auto s_b_53_2 = emitter.vector_extract(s_b_53_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:45 [D] s_b_53_3: sym_24633_0_min = s_b_53_2, dominates: s_b_54_1  */
        emitter.store_local(DV_sym_24633_0_min, s_b_53_2);
        /* execute.simd:45 [F] s_b_53_4: Jump b_54 (const) */
        {
          auto block = block_b_54;
          dynamic_block_queue.push(block_b_54);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_54) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_54);
        /* execute.simd:49 [F] s_b_54_0=sym_24205_3_parameter_inst.rd (const) */
        /* execute.simd:49 [D] s_b_54_1 = sym_24633_0_min int16_t */
        auto s_b_54_1 = emitter.load_local(DV_sym_24633_0_min, emitter.context().types().s16());
        /* execute.simd:49 [D] s_b_54_2 = (u16)s_b_54_1 */
        auto s_b_54_2 = emitter.reinterpret(s_b_54_1, emitter.context().types().u16());
        /* execute.simd:6312 [D] s_b_54_3 = (u64)s_b_54_2 */
        auto s_b_54_3 = emitter.zx(s_b_54_2, emitter.context().types().u64());
        /* execute.simd:6312 [D] s_b_54_4: WriteRegBank 2:s_b_54_0 = s_b_54_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_54_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_54_3);
        /* execute.simd:6313 [F] s_b_54_5 = constant u64 0 (const) */
        /* execute.simd:6313 [F] s_b_54_6: WriteRegBank 3:s_b_54_0 = s_b_54_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_54_7: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_56) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_56);
        /* execute.simd:58 [D] s_b_56_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_56_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_56_1 = constant u8 1 (const) */
        /* execute.simd:58 [D] s_b_56_0[s_b_56_1] */
        auto s_b_56_2 = emitter.vector_extract(s_b_56_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:58 [D] s_b_56_3: sym_24704_0_min = s_b_56_2, dominates: s_b_57_3 s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_24704_0_min, s_b_56_2);
        /* execute.simd:58 [F] s_b_56_4: Jump b_57 (const) */
        {
          auto block = block_b_57;
          dynamic_block_queue.push(block_b_57);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_57) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_57);
        /* execute.simd:57 [D] s_b_57_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_57_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_57_1 = constant u8 2 (const) */
        /* execute.simd:57 [D] s_b_57_0[s_b_57_1] */
        auto s_b_57_2 = emitter.vector_extract(s_b_57_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:57 [D] s_b_57_3 = sym_24704_0_min int16_t */
        auto s_b_57_3 = emitter.load_local(DV_sym_24704_0_min, emitter.context().types().s16());
        /* execute.simd:57 [D] s_b_57_4 = s_b_57_2<s_b_57_3 */
        auto s_b_57_4 = emitter.cmp_lt(s_b_57_2, s_b_57_3);
        /* execute.simd:57 [D] s_b_57_5: If s_b_57_4: Jump b_58 else b_59 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_58;
            dynamic_block_queue.push(block_b_58);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_59;
            dynamic_block_queue.push(block_b_59);
            false_target = block;
          }
          emitter.branch(s_b_57_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_58) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_58);
        /* execute.simd:58 [D] s_b_58_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_58_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_58_1 = constant u8 2 (const) */
        /* execute.simd:58 [D] s_b_58_0[s_b_58_1] */
        auto s_b_58_2 = emitter.vector_extract(s_b_58_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:58 [D] s_b_58_3: sym_24704_0_min = s_b_58_2, dominates: s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_24704_0_min, s_b_58_2);
        /* execute.simd:58 [F] s_b_58_4: Jump b_59 (const) */
        {
          auto block = block_b_59;
          dynamic_block_queue.push(block_b_59);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_59) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_59);
        /* execute.simd:57 [D] s_b_59_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_59_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_59_1 = constant u8 3 (const) */
        /* execute.simd:57 [D] s_b_59_0[s_b_59_1] */
        auto s_b_59_2 = emitter.vector_extract(s_b_59_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:57 [D] s_b_59_3 = sym_24704_0_min int16_t */
        auto s_b_59_3 = emitter.load_local(DV_sym_24704_0_min, emitter.context().types().s16());
        /* execute.simd:57 [D] s_b_59_4 = s_b_59_2<s_b_59_3 */
        auto s_b_59_4 = emitter.cmp_lt(s_b_59_2, s_b_59_3);
        /* execute.simd:57 [D] s_b_59_5: If s_b_59_4: Jump b_60 else b_61 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_60;
            dynamic_block_queue.push(block_b_60);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_61;
            dynamic_block_queue.push(block_b_61);
            false_target = block;
          }
          emitter.branch(s_b_59_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_60) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_60);
        /* execute.simd:58 [D] s_b_60_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_60_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_60_1 = constant u8 3 (const) */
        /* execute.simd:58 [D] s_b_60_0[s_b_60_1] */
        auto s_b_60_2 = emitter.vector_extract(s_b_60_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:58 [D] s_b_60_3: sym_24704_0_min = s_b_60_2, dominates: s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_24704_0_min, s_b_60_2);
        /* execute.simd:58 [F] s_b_60_4: Jump b_61 (const) */
        {
          auto block = block_b_61;
          dynamic_block_queue.push(block_b_61);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_61) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_61);
        /* execute.simd:57 [D] s_b_61_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_61_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_61_1 = constant u8 4 (const) */
        /* execute.simd:57 [D] s_b_61_0[s_b_61_1] */
        auto s_b_61_2 = emitter.vector_extract(s_b_61_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:57 [D] s_b_61_3 = sym_24704_0_min int16_t */
        auto s_b_61_3 = emitter.load_local(DV_sym_24704_0_min, emitter.context().types().s16());
        /* execute.simd:57 [D] s_b_61_4 = s_b_61_2<s_b_61_3 */
        auto s_b_61_4 = emitter.cmp_lt(s_b_61_2, s_b_61_3);
        /* execute.simd:57 [D] s_b_61_5: If s_b_61_4: Jump b_62 else b_63 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_62;
            dynamic_block_queue.push(block_b_62);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_63;
            dynamic_block_queue.push(block_b_63);
            false_target = block;
          }
          emitter.branch(s_b_61_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_62) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_62);
        /* execute.simd:58 [D] s_b_62_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_62_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_62_1 = constant u8 4 (const) */
        /* execute.simd:58 [D] s_b_62_0[s_b_62_1] */
        auto s_b_62_2 = emitter.vector_extract(s_b_62_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:58 [D] s_b_62_3: sym_24704_0_min = s_b_62_2, dominates: s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_24704_0_min, s_b_62_2);
        /* execute.simd:58 [F] s_b_62_4: Jump b_63 (const) */
        {
          auto block = block_b_63;
          dynamic_block_queue.push(block_b_63);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_63) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_63);
        /* execute.simd:57 [D] s_b_63_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_63_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_63_1 = constant u8 5 (const) */
        /* execute.simd:57 [D] s_b_63_0[s_b_63_1] */
        auto s_b_63_2 = emitter.vector_extract(s_b_63_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:57 [D] s_b_63_3 = sym_24704_0_min int16_t */
        auto s_b_63_3 = emitter.load_local(DV_sym_24704_0_min, emitter.context().types().s16());
        /* execute.simd:57 [D] s_b_63_4 = s_b_63_2<s_b_63_3 */
        auto s_b_63_4 = emitter.cmp_lt(s_b_63_2, s_b_63_3);
        /* execute.simd:57 [D] s_b_63_5: If s_b_63_4: Jump b_64 else b_65 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_64;
            dynamic_block_queue.push(block_b_64);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_65;
            dynamic_block_queue.push(block_b_65);
            false_target = block;
          }
          emitter.branch(s_b_63_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_64) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_64);
        /* execute.simd:58 [D] s_b_64_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_64_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_64_1 = constant u8 5 (const) */
        /* execute.simd:58 [D] s_b_64_0[s_b_64_1] */
        auto s_b_64_2 = emitter.vector_extract(s_b_64_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:58 [D] s_b_64_3: sym_24704_0_min = s_b_64_2, dominates: s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_24704_0_min, s_b_64_2);
        /* execute.simd:58 [F] s_b_64_4: Jump b_65 (const) */
        {
          auto block = block_b_65;
          dynamic_block_queue.push(block_b_65);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_65) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_65);
        /* execute.simd:57 [D] s_b_65_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_65_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_65_1 = constant u8 6 (const) */
        /* execute.simd:57 [D] s_b_65_0[s_b_65_1] */
        auto s_b_65_2 = emitter.vector_extract(s_b_65_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:57 [D] s_b_65_3 = sym_24704_0_min int16_t */
        auto s_b_65_3 = emitter.load_local(DV_sym_24704_0_min, emitter.context().types().s16());
        /* execute.simd:57 [D] s_b_65_4 = s_b_65_2<s_b_65_3 */
        auto s_b_65_4 = emitter.cmp_lt(s_b_65_2, s_b_65_3);
        /* execute.simd:57 [D] s_b_65_5: If s_b_65_4: Jump b_66 else b_67 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_66;
            dynamic_block_queue.push(block_b_66);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_67;
            dynamic_block_queue.push(block_b_67);
            false_target = block;
          }
          emitter.branch(s_b_65_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_66) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_66);
        /* execute.simd:58 [D] s_b_66_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_66_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_66_1 = constant u8 6 (const) */
        /* execute.simd:58 [D] s_b_66_0[s_b_66_1] */
        auto s_b_66_2 = emitter.vector_extract(s_b_66_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:58 [D] s_b_66_3: sym_24704_0_min = s_b_66_2, dominates: s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_24704_0_min, s_b_66_2);
        /* execute.simd:58 [F] s_b_66_4: Jump b_67 (const) */
        {
          auto block = block_b_67;
          dynamic_block_queue.push(block_b_67);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_67) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_67);
        /* execute.simd:57 [D] s_b_67_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_67_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_67_1 = constant u8 7 (const) */
        /* execute.simd:57 [D] s_b_67_0[s_b_67_1] */
        auto s_b_67_2 = emitter.vector_extract(s_b_67_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:57 [D] s_b_67_3 = sym_24704_0_min int16_t */
        auto s_b_67_3 = emitter.load_local(DV_sym_24704_0_min, emitter.context().types().s16());
        /* execute.simd:57 [D] s_b_67_4 = s_b_67_2<s_b_67_3 */
        auto s_b_67_4 = emitter.cmp_lt(s_b_67_2, s_b_67_3);
        /* execute.simd:57 [D] s_b_67_5: If s_b_67_4: Jump b_68 else b_69 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_68;
            dynamic_block_queue.push(block_b_68);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_69;
            dynamic_block_queue.push(block_b_69);
            false_target = block;
          }
          emitter.branch(s_b_67_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_68) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_68);
        /* execute.simd:58 [D] s_b_68_0 = sym_24698_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_68_0 = emitter.load_local(DV_sym_24698_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_68_1 = constant u8 7 (const) */
        /* execute.simd:58 [D] s_b_68_0[s_b_68_1] */
        auto s_b_68_2 = emitter.vector_extract(s_b_68_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:58 [D] s_b_68_3: sym_24704_0_min = s_b_68_2, dominates: s_b_69_1  */
        emitter.store_local(DV_sym_24704_0_min, s_b_68_2);
        /* execute.simd:58 [F] s_b_68_4: Jump b_69 (const) */
        {
          auto block = block_b_69;
          dynamic_block_queue.push(block_b_69);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_69) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_69);
        /* execute.simd:62 [F] s_b_69_0=sym_24205_3_parameter_inst.rd (const) */
        /* execute.simd:62 [D] s_b_69_1 = sym_24704_0_min int16_t */
        auto s_b_69_1 = emitter.load_local(DV_sym_24704_0_min, emitter.context().types().s16());
        /* execute.simd:62 [D] s_b_69_2 = (u16)s_b_69_1 */
        auto s_b_69_2 = emitter.reinterpret(s_b_69_1, emitter.context().types().u16());
        /* execute.simd:6312 [D] s_b_69_3 = (u64)s_b_69_2 */
        auto s_b_69_3 = emitter.zx(s_b_69_2, emitter.context().types().u64());
        /* execute.simd:6312 [D] s_b_69_4: WriteRegBank 2:s_b_69_0 = s_b_69_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_69_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_69_3);
        /* execute.simd:6313 [F] s_b_69_5 = constant u64 0 (const) */
        /* execute.simd:6313 [F] s_b_69_6: WriteRegBank 3:s_b_69_0 = s_b_69_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_69_7: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_71) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_71);
        /* execute.simd:71 [D] s_b_71_0 = sym_24837_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_71_0 = emitter.load_local(DV_sym_24837_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_71_1 = constant u8 1 (const) */
        /* execute.simd:71 [D] s_b_71_0[s_b_71_1] */
        auto s_b_71_2 = emitter.vector_extract(s_b_71_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:71 [D] s_b_71_3: sym_24843_0_min = s_b_71_2, dominates: s_b_72_3 s_b_74_3 s_b_76_1  */
        emitter.store_local(DV_sym_24843_0_min, s_b_71_2);
        /* execute.simd:71 [F] s_b_71_4: Jump b_72 (const) */
        {
          auto block = block_b_72;
          dynamic_block_queue.push(block_b_72);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_72) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_72);
        /* execute.simd:70 [D] s_b_72_0 = sym_24837_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_72_0 = emitter.load_local(DV_sym_24837_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_72_1 = constant u8 2 (const) */
        /* execute.simd:70 [D] s_b_72_0[s_b_72_1] */
        auto s_b_72_2 = emitter.vector_extract(s_b_72_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:70 [D] s_b_72_3 = sym_24843_0_min int32_t */
        auto s_b_72_3 = emitter.load_local(DV_sym_24843_0_min, emitter.context().types().s32());
        /* execute.simd:70 [D] s_b_72_4 = s_b_72_2<s_b_72_3 */
        auto s_b_72_4 = emitter.cmp_lt(s_b_72_2, s_b_72_3);
        /* execute.simd:70 [D] s_b_72_5: If s_b_72_4: Jump b_73 else b_74 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_73;
            dynamic_block_queue.push(block_b_73);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_74;
            dynamic_block_queue.push(block_b_74);
            false_target = block;
          }
          emitter.branch(s_b_72_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_73) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_73);
        /* execute.simd:71 [D] s_b_73_0 = sym_24837_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_73_0 = emitter.load_local(DV_sym_24837_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_73_1 = constant u8 2 (const) */
        /* execute.simd:71 [D] s_b_73_0[s_b_73_1] */
        auto s_b_73_2 = emitter.vector_extract(s_b_73_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:71 [D] s_b_73_3: sym_24843_0_min = s_b_73_2, dominates: s_b_74_3 s_b_76_1  */
        emitter.store_local(DV_sym_24843_0_min, s_b_73_2);
        /* execute.simd:71 [F] s_b_73_4: Jump b_74 (const) */
        {
          auto block = block_b_74;
          dynamic_block_queue.push(block_b_74);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_74) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_74);
        /* execute.simd:70 [D] s_b_74_0 = sym_24837_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_74_0 = emitter.load_local(DV_sym_24837_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_74_1 = constant u8 3 (const) */
        /* execute.simd:70 [D] s_b_74_0[s_b_74_1] */
        auto s_b_74_2 = emitter.vector_extract(s_b_74_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:70 [D] s_b_74_3 = sym_24843_0_min int32_t */
        auto s_b_74_3 = emitter.load_local(DV_sym_24843_0_min, emitter.context().types().s32());
        /* execute.simd:70 [D] s_b_74_4 = s_b_74_2<s_b_74_3 */
        auto s_b_74_4 = emitter.cmp_lt(s_b_74_2, s_b_74_3);
        /* execute.simd:70 [D] s_b_74_5: If s_b_74_4: Jump b_75 else b_76 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_75;
            dynamic_block_queue.push(block_b_75);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_76;
            dynamic_block_queue.push(block_b_76);
            false_target = block;
          }
          emitter.branch(s_b_74_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_75) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_75);
        /* execute.simd:71 [D] s_b_75_0 = sym_24837_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_75_0 = emitter.load_local(DV_sym_24837_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_75_1 = constant u8 3 (const) */
        /* execute.simd:71 [D] s_b_75_0[s_b_75_1] */
        auto s_b_75_2 = emitter.vector_extract(s_b_75_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:71 [D] s_b_75_3: sym_24843_0_min = s_b_75_2, dominates: s_b_76_1  */
        emitter.store_local(DV_sym_24843_0_min, s_b_75_2);
        /* execute.simd:71 [F] s_b_75_4: Jump b_76 (const) */
        {
          auto block = block_b_76;
          dynamic_block_queue.push(block_b_76);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_76) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_76);
        /* execute.simd:75 [F] s_b_76_0=sym_24205_3_parameter_inst.rd (const) */
        /* execute.simd:75 [D] s_b_76_1 = sym_24843_0_min int32_t */
        auto s_b_76_1 = emitter.load_local(DV_sym_24843_0_min, emitter.context().types().s32());
        /* execute.simd:75 [D] s_b_76_2 = (u32)s_b_76_1 */
        auto s_b_76_2 = emitter.reinterpret(s_b_76_1, emitter.context().types().u32());
        /* execute.simd:6319 [D] s_b_76_3 = (u64)s_b_76_2 */
        auto s_b_76_3 = emitter.zx(s_b_76_2, emitter.context().types().u64());
        /* execute.simd:6319 [D] s_b_76_4: WriteRegBank 2:s_b_76_0 = s_b_76_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_76_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_76_3);
        /* execute.simd:6320 [F] s_b_76_5 = constant u64 0 (const) */
        /* execute.simd:6320 [F] s_b_76_6: WriteRegBank 3:s_b_76_0 = s_b_76_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_76_7: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
    }
  }
  else 
  {
    emitter.jump(__exit_block);
  }
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ssubl(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5861 [F] s_b_0_0=sym_29030_3_parameter_inst.tb (const) */
    /* execute.simd:5862 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5874 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5886 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5898 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5910 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5922 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5861 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
    switch (insn.tb) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
      break;
    default:
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:5863 [F] s_b_2_0=sym_29030_3_parameter_inst.rn (const) */
    /* execute.simd:5863 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5863 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:5864 [F] s_b_2_3=sym_29030_3_parameter_inst.rm (const) */
    /* execute.simd:5864 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5864 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5868 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5868 [D] s_b_2_9 = (s16)s_b_2_8 */
    auto s_b_2_9 = emitter.sx(s_b_2_8, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5868 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5868 [D] s_b_2_12 = (s16)s_b_2_11 */
    auto s_b_2_12 = emitter.sx(s_b_2_11, emitter.context().types().s16());
    /* execute.simd:5868 [D] s_b_2_13 = s_b_2_9-s_b_2_12 */
    auto s_b_2_13 = emitter.sub(s_b_2_9, s_b_2_12);
    /* execute.simd:5868 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5868 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5868 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5868 [D] s_b_2_18 = (s16)s_b_2_17 */
    auto s_b_2_18 = emitter.sx(s_b_2_17, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5868 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5868 [D] s_b_2_21 = (s16)s_b_2_20 */
    auto s_b_2_21 = emitter.sx(s_b_2_20, emitter.context().types().s16());
    /* execute.simd:5868 [D] s_b_2_22 = s_b_2_18-s_b_2_21 */
    auto s_b_2_22 = emitter.sub(s_b_2_18, s_b_2_21);
    /* execute.simd:5868 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5868 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5868 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5868 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5868 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5868 [D] s_b_2_30 = (s16)s_b_2_29 */
    auto s_b_2_30 = emitter.sx(s_b_2_29, emitter.context().types().s16());
    /* execute.simd:5868 [D] s_b_2_31 = s_b_2_27-s_b_2_30 */
    auto s_b_2_31 = emitter.sub(s_b_2_27, s_b_2_30);
    /* execute.simd:5868 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5868 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5868 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5868 [D] s_b_2_36 = (s16)s_b_2_35 */
    auto s_b_2_36 = emitter.sx(s_b_2_35, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5868 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5868 [D] s_b_2_39 = (s16)s_b_2_38 */
    auto s_b_2_39 = emitter.sx(s_b_2_38, emitter.context().types().s16());
    /* execute.simd:5868 [D] s_b_2_40 = s_b_2_36-s_b_2_39 */
    auto s_b_2_40 = emitter.sub(s_b_2_36, s_b_2_39);
    /* execute.simd:5868 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5868 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5868 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5868 [D] s_b_2_45 = (s16)s_b_2_44 */
    auto s_b_2_45 = emitter.sx(s_b_2_44, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5868 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5868 [D] s_b_2_48 = (s16)s_b_2_47 */
    auto s_b_2_48 = emitter.sx(s_b_2_47, emitter.context().types().s16());
    /* execute.simd:5868 [D] s_b_2_49 = s_b_2_45-s_b_2_48 */
    auto s_b_2_49 = emitter.sub(s_b_2_45, s_b_2_48);
    /* execute.simd:5868 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5868 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5868 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5868 [D] s_b_2_54 = (s16)s_b_2_53 */
    auto s_b_2_54 = emitter.sx(s_b_2_53, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5868 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5868 [D] s_b_2_57 = (s16)s_b_2_56 */
    auto s_b_2_57 = emitter.sx(s_b_2_56, emitter.context().types().s16());
    /* execute.simd:5868 [D] s_b_2_58 = s_b_2_54-s_b_2_57 */
    auto s_b_2_58 = emitter.sub(s_b_2_54, s_b_2_57);
    /* execute.simd:5868 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5868 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5868 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5868 [D] s_b_2_63 = (s16)s_b_2_62 */
    auto s_b_2_63 = emitter.sx(s_b_2_62, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5868 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5868 [D] s_b_2_66 = (s16)s_b_2_65 */
    auto s_b_2_66 = emitter.sx(s_b_2_65, emitter.context().types().s16());
    /* execute.simd:5868 [D] s_b_2_67 = s_b_2_63-s_b_2_66 */
    auto s_b_2_67 = emitter.sub(s_b_2_63, s_b_2_66);
    /* execute.simd:5868 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5868 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5868 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5868 [D] s_b_2_72 = (s16)s_b_2_71 */
    auto s_b_2_72 = emitter.sx(s_b_2_71, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5868 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5868 [D] s_b_2_75 = (s16)s_b_2_74 */
    auto s_b_2_75 = emitter.sx(s_b_2_74, emitter.context().types().s16());
    /* execute.simd:5868 [D] s_b_2_76 = s_b_2_72-s_b_2_75 */
    auto s_b_2_76 = emitter.sub(s_b_2_72, s_b_2_75);
    /* execute.simd:5868 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5868 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5871 [F] s_b_2_79=sym_29030_3_parameter_inst.rd (const) */
    /* execute.simd:5871 [D] s_b_2_80 = (v8u16)s_b_2_78 */
    auto s_b_2_80 = emitter.reinterpret(s_b_2_78, emitter.context().types().v8u16());
    /* execute.simd:5871 [D] s_b_2_81: WriteRegBank 18:s_b_2_79 = s_b_2_80 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_80,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_80);
    /* execute.simd:0 [F] s_b_2_82: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5875 [F] s_b_3_0=sym_29030_3_parameter_inst.rn (const) */
    /* execute.simd:5875 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5875 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:5876 [F] s_b_3_3=sym_29030_3_parameter_inst.rm (const) */
    /* execute.simd:5876 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5876 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:5880 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5880 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5880 [D] s_b_3_9 = (s16)s_b_3_8 */
    auto s_b_3_9 = emitter.sx(s_b_3_8, emitter.context().types().s16());
    /* execute.simd:5880 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5880 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5880 [D] s_b_3_12 = (s16)s_b_3_11 */
    auto s_b_3_12 = emitter.sx(s_b_3_11, emitter.context().types().s16());
    /* execute.simd:5880 [D] s_b_3_13 = s_b_3_9-s_b_3_12 */
    auto s_b_3_13 = emitter.sub(s_b_3_9, s_b_3_12);
    /* execute.simd:5880 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5880 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5880 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5880 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5880 [D] s_b_3_18 = (s16)s_b_3_17 */
    auto s_b_3_18 = emitter.sx(s_b_3_17, emitter.context().types().s16());
    /* execute.simd:5880 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5880 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5880 [D] s_b_3_21 = (s16)s_b_3_20 */
    auto s_b_3_21 = emitter.sx(s_b_3_20, emitter.context().types().s16());
    /* execute.simd:5880 [D] s_b_3_22 = s_b_3_18-s_b_3_21 */
    auto s_b_3_22 = emitter.sub(s_b_3_18, s_b_3_21);
    /* execute.simd:5880 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5880 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5880 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5880 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5880 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5880 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5880 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5880 [D] s_b_3_30 = (s16)s_b_3_29 */
    auto s_b_3_30 = emitter.sx(s_b_3_29, emitter.context().types().s16());
    /* execute.simd:5880 [D] s_b_3_31 = s_b_3_27-s_b_3_30 */
    auto s_b_3_31 = emitter.sub(s_b_3_27, s_b_3_30);
    /* execute.simd:5880 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5880 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5880 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5880 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5880 [D] s_b_3_36 = (s16)s_b_3_35 */
    auto s_b_3_36 = emitter.sx(s_b_3_35, emitter.context().types().s16());
    /* execute.simd:5880 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5880 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5880 [D] s_b_3_39 = (s16)s_b_3_38 */
    auto s_b_3_39 = emitter.sx(s_b_3_38, emitter.context().types().s16());
    /* execute.simd:5880 [D] s_b_3_40 = s_b_3_36-s_b_3_39 */
    auto s_b_3_40 = emitter.sub(s_b_3_36, s_b_3_39);
    /* execute.simd:5880 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5880 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5880 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5880 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5880 [D] s_b_3_45 = (s16)s_b_3_44 */
    auto s_b_3_45 = emitter.sx(s_b_3_44, emitter.context().types().s16());
    /* execute.simd:5880 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5880 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5880 [D] s_b_3_48 = (s16)s_b_3_47 */
    auto s_b_3_48 = emitter.sx(s_b_3_47, emitter.context().types().s16());
    /* execute.simd:5880 [D] s_b_3_49 = s_b_3_45-s_b_3_48 */
    auto s_b_3_49 = emitter.sub(s_b_3_45, s_b_3_48);
    /* execute.simd:5880 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5880 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5880 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5880 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5880 [D] s_b_3_54 = (s16)s_b_3_53 */
    auto s_b_3_54 = emitter.sx(s_b_3_53, emitter.context().types().s16());
    /* execute.simd:5880 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5880 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5880 [D] s_b_3_57 = (s16)s_b_3_56 */
    auto s_b_3_57 = emitter.sx(s_b_3_56, emitter.context().types().s16());
    /* execute.simd:5880 [D] s_b_3_58 = s_b_3_54-s_b_3_57 */
    auto s_b_3_58 = emitter.sub(s_b_3_54, s_b_3_57);
    /* execute.simd:5880 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5880 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5880 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5880 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5880 [D] s_b_3_63 = (s16)s_b_3_62 */
    auto s_b_3_63 = emitter.sx(s_b_3_62, emitter.context().types().s16());
    /* execute.simd:5880 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5880 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5880 [D] s_b_3_66 = (s16)s_b_3_65 */
    auto s_b_3_66 = emitter.sx(s_b_3_65, emitter.context().types().s16());
    /* execute.simd:5880 [D] s_b_3_67 = s_b_3_63-s_b_3_66 */
    auto s_b_3_67 = emitter.sub(s_b_3_63, s_b_3_66);
    /* execute.simd:5880 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5880 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5880 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5880 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5880 [D] s_b_3_72 = (s16)s_b_3_71 */
    auto s_b_3_72 = emitter.sx(s_b_3_71, emitter.context().types().s16());
    /* execute.simd:5880 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5880 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5880 [D] s_b_3_75 = (s16)s_b_3_74 */
    auto s_b_3_75 = emitter.sx(s_b_3_74, emitter.context().types().s16());
    /* execute.simd:5880 [D] s_b_3_76 = s_b_3_72-s_b_3_75 */
    auto s_b_3_76 = emitter.sub(s_b_3_72, s_b_3_75);
    /* execute.simd:5880 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5880 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5883 [F] s_b_3_79=sym_29030_3_parameter_inst.rd (const) */
    /* execute.simd:5883 [D] s_b_3_80 = (v8u16)s_b_3_78 */
    auto s_b_3_80 = emitter.reinterpret(s_b_3_78, emitter.context().types().v8u16());
    /* execute.simd:5883 [D] s_b_3_81: WriteRegBank 18:s_b_3_79 = s_b_3_80 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_80,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_80);
    /* execute.simd:0 [F] s_b_3_82: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5887 [F] s_b_4_0=sym_29030_3_parameter_inst.rn (const) */
    /* execute.simd:5887 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5887 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:5888 [F] s_b_4_3=sym_29030_3_parameter_inst.rm (const) */
    /* execute.simd:5888 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5888 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5892 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5892 [D] s_b_4_9 = (s32)s_b_4_8 */
    auto s_b_4_9 = emitter.sx(s_b_4_8, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5892 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5892 [D] s_b_4_12 = (s32)s_b_4_11 */
    auto s_b_4_12 = emitter.sx(s_b_4_11, emitter.context().types().s32());
    /* execute.simd:5892 [D] s_b_4_13 = s_b_4_9-s_b_4_12 */
    auto s_b_4_13 = emitter.sub(s_b_4_9, s_b_4_12);
    /* execute.simd:5892 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5892 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5892 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5892 [D] s_b_4_18 = (s32)s_b_4_17 */
    auto s_b_4_18 = emitter.sx(s_b_4_17, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5892 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5892 [D] s_b_4_21 = (s32)s_b_4_20 */
    auto s_b_4_21 = emitter.sx(s_b_4_20, emitter.context().types().s32());
    /* execute.simd:5892 [D] s_b_4_22 = s_b_4_18-s_b_4_21 */
    auto s_b_4_22 = emitter.sub(s_b_4_18, s_b_4_21);
    /* execute.simd:5892 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5892 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5892 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5892 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5892 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5892 [D] s_b_4_30 = (s32)s_b_4_29 */
    auto s_b_4_30 = emitter.sx(s_b_4_29, emitter.context().types().s32());
    /* execute.simd:5892 [D] s_b_4_31 = s_b_4_27-s_b_4_30 */
    auto s_b_4_31 = emitter.sub(s_b_4_27, s_b_4_30);
    /* execute.simd:5892 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5892 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5892 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5892 [D] s_b_4_36 = (s32)s_b_4_35 */
    auto s_b_4_36 = emitter.sx(s_b_4_35, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5892 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5892 [D] s_b_4_39 = (s32)s_b_4_38 */
    auto s_b_4_39 = emitter.sx(s_b_4_38, emitter.context().types().s32());
    /* execute.simd:5892 [D] s_b_4_40 = s_b_4_36-s_b_4_39 */
    auto s_b_4_40 = emitter.sub(s_b_4_36, s_b_4_39);
    /* execute.simd:5892 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5892 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5895 [F] s_b_4_43=sym_29030_3_parameter_inst.rd (const) */
    /* execute.simd:5895 [D] s_b_4_44 = (v4u32)s_b_4_42 */
    auto s_b_4_44 = emitter.reinterpret(s_b_4_42, emitter.context().types().v4u32());
    /* execute.simd:5895 [D] s_b_4_45: WriteRegBank 20:s_b_4_43 = s_b_4_44 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_44,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_44);
    /* execute.simd:0 [F] s_b_4_46: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5899 [F] s_b_5_0=sym_29030_3_parameter_inst.rn (const) */
    /* execute.simd:5899 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5899 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:5900 [F] s_b_5_3=sym_29030_3_parameter_inst.rm (const) */
    /* execute.simd:5900 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5900 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:5904 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5904 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5904 [D] s_b_5_9 = (s32)s_b_5_8 */
    auto s_b_5_9 = emitter.sx(s_b_5_8, emitter.context().types().s32());
    /* execute.simd:5904 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5904 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5904 [D] s_b_5_12 = (s32)s_b_5_11 */
    auto s_b_5_12 = emitter.sx(s_b_5_11, emitter.context().types().s32());
    /* execute.simd:5904 [D] s_b_5_13 = s_b_5_9-s_b_5_12 */
    auto s_b_5_13 = emitter.sub(s_b_5_9, s_b_5_12);
    /* execute.simd:5904 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5904 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5904 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5904 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5904 [D] s_b_5_18 = (s32)s_b_5_17 */
    auto s_b_5_18 = emitter.sx(s_b_5_17, emitter.context().types().s32());
    /* execute.simd:5904 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5904 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5904 [D] s_b_5_21 = (s32)s_b_5_20 */
    auto s_b_5_21 = emitter.sx(s_b_5_20, emitter.context().types().s32());
    /* execute.simd:5904 [D] s_b_5_22 = s_b_5_18-s_b_5_21 */
    auto s_b_5_22 = emitter.sub(s_b_5_18, s_b_5_21);
    /* execute.simd:5904 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5904 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5904 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5904 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5904 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5904 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5904 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5904 [D] s_b_5_30 = (s32)s_b_5_29 */
    auto s_b_5_30 = emitter.sx(s_b_5_29, emitter.context().types().s32());
    /* execute.simd:5904 [D] s_b_5_31 = s_b_5_27-s_b_5_30 */
    auto s_b_5_31 = emitter.sub(s_b_5_27, s_b_5_30);
    /* execute.simd:5904 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5904 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5904 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5904 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5904 [D] s_b_5_36 = (s32)s_b_5_35 */
    auto s_b_5_36 = emitter.sx(s_b_5_35, emitter.context().types().s32());
    /* execute.simd:5904 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5904 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5904 [D] s_b_5_39 = (s32)s_b_5_38 */
    auto s_b_5_39 = emitter.sx(s_b_5_38, emitter.context().types().s32());
    /* execute.simd:5904 [D] s_b_5_40 = s_b_5_36-s_b_5_39 */
    auto s_b_5_40 = emitter.sub(s_b_5_36, s_b_5_39);
    /* execute.simd:5904 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5904 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5907 [F] s_b_5_43=sym_29030_3_parameter_inst.rd (const) */
    /* execute.simd:5907 [D] s_b_5_44 = (v4u32)s_b_5_42 */
    auto s_b_5_44 = emitter.reinterpret(s_b_5_42, emitter.context().types().v4u32());
    /* execute.simd:5907 [D] s_b_5_45: WriteRegBank 20:s_b_5_43 = s_b_5_44 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_44,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_44);
    /* execute.simd:0 [F] s_b_5_46: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5911 [F] s_b_6_0=sym_29030_3_parameter_inst.rn (const) */
    /* execute.simd:5911 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5911 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:5912 [F] s_b_6_3=sym_29030_3_parameter_inst.rm (const) */
    /* execute.simd:5912 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5912 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5916 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5916 [D] s_b_6_9 = (s64)s_b_6_8 */
    auto s_b_6_9 = emitter.sx(s_b_6_8, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5916 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5916 [D] s_b_6_12 = (s64)s_b_6_11 */
    auto s_b_6_12 = emitter.sx(s_b_6_11, emitter.context().types().s64());
    /* execute.simd:5916 [D] s_b_6_13 = s_b_6_9-s_b_6_12 */
    auto s_b_6_13 = emitter.sub(s_b_6_9, s_b_6_12);
    /* execute.simd:5916 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5916 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5916 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5916 [D] s_b_6_18 = (s64)s_b_6_17 */
    auto s_b_6_18 = emitter.sx(s_b_6_17, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5916 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5916 [D] s_b_6_21 = (s64)s_b_6_20 */
    auto s_b_6_21 = emitter.sx(s_b_6_20, emitter.context().types().s64());
    /* execute.simd:5916 [D] s_b_6_22 = s_b_6_18-s_b_6_21 */
    auto s_b_6_22 = emitter.sub(s_b_6_18, s_b_6_21);
    /* execute.simd:5916 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5916 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:5919 [F] s_b_6_25=sym_29030_3_parameter_inst.rd (const) */
    /* execute.simd:5919 [D] s_b_6_26 = (v2u64)s_b_6_24 */
    auto s_b_6_26 = emitter.reinterpret(s_b_6_24, emitter.context().types().v2u64());
    /* execute.simd:5919 [D] s_b_6_27: WriteRegBank 21:s_b_6_25 = s_b_6_26 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_26,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_26);
    /* execute.simd:0 [F] s_b_6_28: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:5923 [F] s_b_7_0=sym_29030_3_parameter_inst.rn (const) */
    /* execute.simd:5923 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5923 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:5924 [F] s_b_7_3=sym_29030_3_parameter_inst.rm (const) */
    /* execute.simd:5924 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5924 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:5928 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:5928 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5928 [D] s_b_7_9 = (s64)s_b_7_8 */
    auto s_b_7_9 = emitter.sx(s_b_7_8, emitter.context().types().s64());
    /* execute.simd:5928 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:5928 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5928 [D] s_b_7_12 = (s64)s_b_7_11 */
    auto s_b_7_12 = emitter.sx(s_b_7_11, emitter.context().types().s64());
    /* execute.simd:5928 [D] s_b_7_13 = s_b_7_9-s_b_7_12 */
    auto s_b_7_13 = emitter.sub(s_b_7_9, s_b_7_12);
    /* execute.simd:5928 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:5928 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:5928 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:5928 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5928 [D] s_b_7_18 = (s64)s_b_7_17 */
    auto s_b_7_18 = emitter.sx(s_b_7_17, emitter.context().types().s64());
    /* execute.simd:5928 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:5928 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5928 [D] s_b_7_21 = (s64)s_b_7_20 */
    auto s_b_7_21 = emitter.sx(s_b_7_20, emitter.context().types().s64());
    /* execute.simd:5928 [D] s_b_7_22 = s_b_7_18-s_b_7_21 */
    auto s_b_7_22 = emitter.sub(s_b_7_18, s_b_7_21);
    /* execute.simd:5928 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:5928 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:5931 [F] s_b_7_25=sym_29030_3_parameter_inst.rd (const) */
    /* execute.simd:5931 [D] s_b_7_26 = (v2u64)s_b_7_24 */
    auto s_b_7_26 = emitter.reinterpret(s_b_7_24, emitter.context().types().v2u64());
    /* execute.simd:5931 [D] s_b_7_27: WriteRegBank 21:s_b_7_25 = s_b_7_26 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_26,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_26);
    /* execute.simd:0 [F] s_b_7_28: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:5935 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5861 [F] s_b_8_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_st3(const arm64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_136508_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_136699_1_tmp_s_b_5_2;
  auto DV_sym_136702_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_136625_3_parameter_lane;
  uint8_t CV_sym_136617_3_parameter_rt;
  auto DV_sym_136622_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_136525_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31014_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_31020_0_lane;
  uint8_t CV_sym_31032_0_rt;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2550 [F] s_b_0_0=sym_31008_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_7 else b_8 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_6, b_9,  */
  fixed_block_b_1: 
  {
    /* execute.simd:2552 [F] s_b_1_0 = sym_31020_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_31020_0_lane;
    /* execute.simd:2552 [F] s_b_1_1=sym_31008_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2552 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2552 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
    if (s_b_1_2) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_1,  */
  fixed_block_b_2: 
  {
    /* execute.simd:2553 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2553 [F] s_b_2_1: sym_31032_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_31032_0_rt = (uint8_t)0ULL;
    /* execute.simd:2553 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [F] s_b_3_0: Return */
    goto fixed_done;
  }
  /* b_2, b_23,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2553 [F] s_b_4_0 = sym_31032_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_31032_0_rt;
    /* execute.simd:2553 [F] s_b_4_1=sym_31008_3_parameter_inst.regcnt (const) */
    /* execute.simd:2553 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2553 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
    if (s_b_4_2) 
    {
      goto fixed_block_b_5;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_4,  */
  fixed_block_b_5: 
  {
    /* execute.simd:2554 [F] s_b_5_0=sym_31008_3_parameter_inst.arrangement (const) */
    /* execute.simd:2554 [F] s_b_5_1=sym_31008_3_parameter_inst.rt (const) */
    /* execute.simd:2554 [F] s_b_5_2 = sym_31032_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_31032_0_rt;
    /* execute.simd:2554 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2554 [F] s_b_5_4 = sym_31020_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_31020_0_lane;
    /* execute.simd:2554 [D] s_b_5_5 = sym_31014_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_31014_0_address, emitter.context().types().u64());
    /* execute.simd:2554 [F] s_b_5_6: sym_136617_3_parameter_rt = s_b_5_3 (const), dominates: s_b_19_0 s_b_22_0 s_b_20_0 s_b_21_0 s_b_16_0 s_b_17_0 s_b_18_0  */
    CV_sym_136617_3_parameter_rt = s_b_5_3;
    /* execute.simd:2554 [F] s_b_5_7: sym_136625_3_parameter_lane = s_b_5_4 (const), dominates: s_b_19_3 s_b_22_3 s_b_20_3 s_b_21_3 s_b_16_3 s_b_17_3 s_b_18_3  */
    CV_sym_136625_3_parameter_lane = s_b_5_4;
    /* execute.simd:2554 [D] s_b_5_8: sym_136622_3_parameter_addr = s_b_5_5, dominates: s_b_19_2 s_b_22_2 s_b_20_2 s_b_21_2 s_b_16_2 s_b_17_2 s_b_18_2  */
    emitter.store_local(DV_sym_136622_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_136699_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_23_1  */
    CV_sym_136699_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_136702_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_136702_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3931 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3936 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3941 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3946 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3951 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3956 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3961 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3930 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_15 (const) -> b_19, b_22, b_20, b_21, b_15, b_16, b_17, b_18,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_20;
      break;
    default:
      goto fixed_block_b_15;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2552 [F] s_b_6_0 = sym_31020_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_31020_0_lane;
    /* execute.simd:2552 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2552 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2552 [F] s_b_6_3: sym_31020_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_31020_0_lane = s_b_6_2;
    /* execute.simd:2552 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2764 [F] s_b_7_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_7_1 = __builtin_get_feature */
    uint32_t s_b_7_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(s_b_7_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_7_4: If s_b_7_3: Jump b_10 else b_11 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2796 [F] s_b_8_0=sym_31008_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_136508_0_return_symbol = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_136508_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_12,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_136508_0_return_symbol uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_136508_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2550 [D] s_b_9_1: sym_31014_0_address = s_b_9_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_31014_0_address, s_b_9_0);
    /* execute.simd:2552 [F] s_b_9_2 = constant u8 0 (const) */
    /* execute.simd:2552 [F] s_b_9_3: sym_31020_0_lane = s_b_9_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_31020_0_lane = (uint8_t)0ULL;
    /* execute.simd:2552 [F] s_b_9_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2765 [D] s_b_10_0 = ReadReg 21 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_10_1: sym_136525_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_136525_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2765 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_7,  */
  fixed_block_b_11: 
  {
    /* execute.a64:3075 [F] s_b_11_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_11_1 = __builtin_get_feature */
    uint32_t s_b_11_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_11_2 = (u8)s_b_11_1 (const) */
    /* execute.a64:2767 [F] s_b_11_3 = (u32)s_b_11_2 (const) */
    /* execute.a64:2767 [F] s_b_11_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_11_5 = s_b_11_3==s_b_11_4 (const) */
    uint8_t s_b_11_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_11_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_11_6: If s_b_11_5: Jump b_13 else b_14 (const) */
    if (s_b_11_5) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_10, b_13, b_14,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2794 [D] s_b_12_0 = sym_136525_1__R_s_b_3_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_136525_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1: sym_136508_0_return_symbol = s_b_12_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_136508_0_return_symbol, s_b_12_0);
    /* ???:4294967295 [F] s_b_12_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2768 [D] s_b_13_0 = ReadReg 21 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_13_1: sym_136525_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_136525_1__R_s_b_3_0, s_b_13_0);
    /* execute.a64:2768 [F] s_b_13_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2770 [D] s_b_14_0 = ReadReg 22 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_14_1: sym_136525_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_136525_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2770 [F] s_b_14_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3967 [D] s_b_15_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_15_1: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3932 [F] s_b_16_0 = sym_136617_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_0 = CV_sym_136617_3_parameter_rt;
    /* execute.simd:3932 [D] s_b_16_1 = ReadRegBank 15:s_b_16_0 (v8u8) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:3933 [D] s_b_16_2 = sym_136622_3_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_136622_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3933 [F] s_b_16_3 = sym_136625_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_3 = CV_sym_136625_3_parameter_lane;
    /* execute.simd:3933 [D] s_b_16_1[s_b_16_3] */
    auto s_b_16_4 = emitter.vector_extract(s_b_16_1, emitter.const_u8(s_b_16_3));
    /* ???:4294967295 [D] s_b_16_5: Store 1 s_b_16_2 <= s_b_16_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_16_2, s_b_16_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_16_2, s_b_16_4);
    /* execute.simd:0 [F] s_b_16_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3937 [F] s_b_17_0 = sym_136617_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_0 = CV_sym_136617_3_parameter_rt;
    /* execute.simd:3937 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:3938 [D] s_b_17_2 = sym_136622_3_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_136622_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3938 [F] s_b_17_3 = sym_136625_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_3 = CV_sym_136625_3_parameter_lane;
    /* execute.simd:3938 [D] s_b_17_1[s_b_17_3] */
    auto s_b_17_4 = emitter.vector_extract(s_b_17_1, emitter.const_u8(s_b_17_3));
    /* ???:4294967295 [D] s_b_17_5: Store 1 s_b_17_2 <= s_b_17_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_17_2, s_b_17_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_17_2, s_b_17_4);
    /* execute.simd:0 [F] s_b_17_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3942 [F] s_b_18_0 = sym_136617_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_136617_3_parameter_rt;
    /* execute.simd:3942 [D] s_b_18_1 = ReadRegBank 17:s_b_18_0 (v4u16) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3943 [D] s_b_18_2 = sym_136622_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_136622_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3943 [F] s_b_18_3 = sym_136625_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_136625_3_parameter_lane;
    /* execute.simd:3943 [D] s_b_18_1[s_b_18_3] */
    auto s_b_18_4 = emitter.vector_extract(s_b_18_1, emitter.const_u8(s_b_18_3));
    /* ???:4294967295 [D] s_b_18_5: Store 2 s_b_18_2 <= s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_18_2, s_b_18_4);
    /* execute.simd:0 [F] s_b_18_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3947 [F] s_b_19_0 = sym_136617_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_136617_3_parameter_rt;
    /* execute.simd:3947 [D] s_b_19_1 = ReadRegBank 18:s_b_19_0 (v8u16) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3948 [D] s_b_19_2 = sym_136622_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_136622_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3948 [F] s_b_19_3 = sym_136625_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_136625_3_parameter_lane;
    /* execute.simd:3948 [D] s_b_19_1[s_b_19_3] */
    auto s_b_19_4 = emitter.vector_extract(s_b_19_1, emitter.const_u8(s_b_19_3));
    /* ???:4294967295 [D] s_b_19_5: Store 2 s_b_19_2 <= s_b_19_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_19_2, s_b_19_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_19_2, s_b_19_4);
    /* execute.simd:0 [F] s_b_19_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3952 [F] s_b_20_0 = sym_136617_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_136617_3_parameter_rt;
    /* execute.simd:3952 [D] s_b_20_1 = ReadRegBank 19:s_b_20_0 (v2u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3953 [D] s_b_20_2 = sym_136622_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_136622_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3953 [F] s_b_20_3 = sym_136625_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_136625_3_parameter_lane;
    /* execute.simd:3953 [D] s_b_20_1[s_b_20_3] */
    auto s_b_20_4 = emitter.vector_extract(s_b_20_1, emitter.const_u8(s_b_20_3));
    /* ???:4294967295 [D] s_b_20_5: Store 4 s_b_20_2 <= s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_20_2, s_b_20_4);
    /* execute.simd:0 [F] s_b_20_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3957 [F] s_b_21_0 = sym_136617_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_136617_3_parameter_rt;
    /* execute.simd:3957 [D] s_b_21_1 = ReadRegBank 20:s_b_21_0 (v4u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3958 [D] s_b_21_2 = sym_136622_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_136622_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3958 [F] s_b_21_3 = sym_136625_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_136625_3_parameter_lane;
    /* execute.simd:3958 [D] s_b_21_1[s_b_21_3] */
    auto s_b_21_4 = emitter.vector_extract(s_b_21_1, emitter.const_u8(s_b_21_3));
    /* ???:4294967295 [D] s_b_21_5: Store 4 s_b_21_2 <= s_b_21_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_21_2, s_b_21_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_21_2, s_b_21_4);
    /* execute.simd:0 [F] s_b_21_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3962 [F] s_b_22_0 = sym_136617_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_136617_3_parameter_rt;
    /* execute.simd:3962 [D] s_b_22_1 = ReadRegBank 21:s_b_22_0 (v2u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3963 [D] s_b_22_2 = sym_136622_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_136622_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3963 [F] s_b_22_3 = sym_136625_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_136625_3_parameter_lane;
    /* execute.simd:3963 [D] s_b_22_1[s_b_22_3] */
    auto s_b_22_4 = emitter.vector_extract(s_b_22_1, emitter.const_u8(s_b_22_3));
    /* ???:4294967295 [D] s_b_22_5: Store 8 s_b_22_2 <= s_b_22_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_22_2, s_b_22_4);
    /* execute.simd:0 [F] s_b_22_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_15, b_16, b_17, b_18, b_19, b_20, b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* ???:4294967295 [D] s_b_23_0 = sym_136702_1_tmp_s_b_5_5 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_136702_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1 = sym_136699_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_23_1 = CV_sym_136699_1_tmp_s_b_5_2;
    /* execute.simd:2555 [F] s_b_23_2=sym_31008_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* ???:4294967295 [D] s_b_23_4 = s_b_23_0+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2555 [D] s_b_23_5: sym_31014_0_address = s_b_23_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_31014_0_address, s_b_23_4);
    /* execute.simd:2553 [F] s_b_23_6 = constant u8 1 (const) */
    /* execute.simd:2553 [F] s_b_23_7 = s_b_23_1+s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(s_b_23_1 + (uint8_t)1ULL));
    /* execute.simd:2553 [F] s_b_23_8: sym_31032_0_rt = s_b_23_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_31032_0_rt = s_b_23_7;
    /* execute.simd:2553 [F] s_b_23_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stlxr(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_16 = emitter.context().create_block();
  auto block_b_17 = emitter.context().create_block();
  auto block_b_18 = emitter.context().create_block();
  auto block_b_19 = emitter.context().create_block();
  auto block_b_20 = emitter.context().create_block();
  auto block_b_21 = emitter.context().create_block();
  auto block_b_22 = emitter.context().create_block();
  auto block_b_23 = emitter.context().create_block();
  auto block_b_24 = emitter.context().create_block();
  auto block_b_25 = emitter.context().create_block();
  auto DV_sym_140061_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_140182_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_140078_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_140254_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_140491_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_31456_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_140417_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:789 [F] s_b_0_0=sym_31450_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_9 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_10,  */
  fixed_block_b_1: 
  {
    /* execute.a64:792 [F] s_b_1_0 = constant u32 0 (const) */
    /* execute.a64:792 [D] s_b_1_1 = sym_31456_0_address uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_31456_0_address, emitter.context().types().u64());
    /* execute.a64:792 [D] s_b_1_2 = mem_monitor_release */
    auto s_b_1_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_1_1);
    /* execute.a64:792 [D] s_b_1_3: If s_b_1_2: Jump b_4 else b_5 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_4;
        dynamic_block_queue.push(block_b_4);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_5;
        dynamic_block_queue.push(block_b_5);
        false_target = block;
      }
      emitter.branch(s_b_1_2, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_10,  */
  fixed_block_b_3: 
  {
    /* execute.a64:799 [F] s_b_3_0 = constant u32 0 (const) */
    /* execute.a64:799 [D] s_b_3_1 = sym_31456_0_address uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_31456_0_address, emitter.context().types().u64());
    /* execute.a64:799 [D] s_b_3_2 = mem_monitor_release */
    auto s_b_3_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_3_1);
    /* execute.a64:799 [D] s_b_3_3: If s_b_3_2: Jump b_6 else b_7 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_6;
        dynamic_block_queue.push(block_b_6);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_7;
        dynamic_block_queue.push(block_b_7);
        false_target = block;
      }
      emitter.branch(s_b_3_2, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  // BLOCK b_6 not fully fixed
  // BLOCK b_7 not fully fixed
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2764 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_8_4: If s_b_8_3: Jump b_11 else b_12 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2796 [F] s_b_9_0=sym_31450_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_140061_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_140061_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_140061_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_140061_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:789 [D] s_b_10_1: sym_31456_0_address = s_b_10_0, dominates: s_b_1_1 s_b_4_0 s_b_3_1 s_b_6_0  */
    emitter.store_local(DV_sym_31456_0_address, s_b_10_0);
    /* execute.a64:791 [F] s_b_10_2=sym_31450_3_parameter_inst.size (const) */
    /* execute.a64:791 [F] s_b_10_3 = (u32)s_b_10_2 (const) */
    /* execute.a64:791 [F] s_b_10_4 = constant u32 2 (const) */
    /* execute.a64:791 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:791 [F] s_b_10_6: If s_b_10_5: Jump b_1 else b_3 (const) */
    if (s_b_10_5) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2765 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_11_1: sym_140078_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_140078_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2765 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_8,  */
  fixed_block_b_12: 
  {
    /* execute.a64:3075 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_12_1 = __builtin_get_feature */
    uint32_t s_b_12_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_12_2 = (u8)s_b_12_1 (const) */
    /* execute.a64:2767 [F] s_b_12_3 = (u32)s_b_12_2 (const) */
    /* execute.a64:2767 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_12_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_12_6: If s_b_12_5: Jump b_14 else b_15 (const) */
    if (s_b_12_5) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_11, b_14, b_15,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2794 [D] s_b_13_0 = sym_140078_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_140078_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_140061_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_140061_0_return_symbol, s_b_13_0);
    /* ???:4294967295 [F] s_b_13_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2768 [D] s_b_14_0 = ReadReg 21 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_14_1: sym_140078_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_140078_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2768 [F] s_b_14_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_12,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2770 [D] s_b_15_0 = ReadReg 22 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_15_1: sym_140078_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_140078_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2770 [F] s_b_15_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  // BLOCK b_16 not fully fixed
  // BLOCK b_17 not fully fixed
  // BLOCK b_18 not fully fixed
  // BLOCK b_19 not fully fixed
  // BLOCK b_20 not fully fixed
  // BLOCK b_21 not fully fixed
  // BLOCK b_22 not fully fixed
  // BLOCK b_23 not fully fixed
  // BLOCK b_24 not fully fixed
  // BLOCK b_25 not fully fixed
  fixed_done:
  if (dynamic_block_queue.size() > 0) 
  {
    std::set<captive::arch::dbt::el::Block *> emitted_blocks;
    while (dynamic_block_queue.size() > 0) 
    {
      captive::arch::dbt::el::Block *block_index = dynamic_block_queue.front();
      dynamic_block_queue.pop();
      if (emitted_blocks.count(block_index)) continue;
      emitted_blocks.insert(block_index);
      if (block_index == block_b_2) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_2);
        /* ???:4294967295 [F] s_b_2_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.a64:793 [D] s_b_4_0 = sym_31456_0_address uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_31456_0_address, emitter.context().types().u64());
        /* execute.a64:793 [F] s_b_4_1=sym_31450_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_4_2: sym_140182_1_tmp_s_b_4_0 = s_b_4_0, dominates: s_b_18_2  */
        emitter.store_local(DV_sym_140182_1_tmp_s_b_4_0, s_b_4_0);
        /* execute.a64:2709 [F] s_b_4_3 = (u32)s_b_4_1 (const) */
        /* execute.a64:2709 [F] s_b_4_4 = constant u32 1f (const) */
        /* execute.a64:2709 [F] s_b_4_5 = s_b_4_3==s_b_4_4 (const) */
        uint8_t s_b_4_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2709 [F] s_b_4_6: If s_b_4_5: Jump b_16 else b_17 (const) */
        if (s_b_4_5) 
        {
          auto block = block_b_16;
          dynamic_block_queue.push(block_b_16);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_17;
          dynamic_block_queue.push(block_b_17);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:796 [F] s_b_5_0=sym_31450_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
        /* execute.a64:2737 [F] s_b_5_2 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
        uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_5_4: If s_b_5_3: Jump b_2 else b_19 (const) */
        if (s_b_5_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.a64:800 [D] s_b_6_0 = sym_31456_0_address uint64_t */
        auto s_b_6_0 = emitter.load_local(DV_sym_31456_0_address, emitter.context().types().u64());
        /* execute.a64:800 [F] s_b_6_1=sym_31450_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_6_2: sym_140417_1_tmp_s_b_5_0 = s_b_6_0, dominates: s_b_22_1  */
        emitter.store_local(DV_sym_140417_1_tmp_s_b_5_0, s_b_6_0);
        /* execute.a64:2714 [F] s_b_6_3 = (u32)s_b_6_1 (const) */
        /* execute.a64:2714 [F] s_b_6_4 = constant u32 1f (const) */
        /* execute.a64:2714 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
        uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2714 [F] s_b_6_6: If s_b_6_5: Jump b_20 else b_21 (const) */
        if (s_b_6_5) 
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.a64:803 [F] s_b_7_0=sym_31450_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
        /* execute.a64:2737 [F] s_b_7_2 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
        uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_7_4: If s_b_7_3: Jump b_2 else b_23 (const) */
        if (s_b_7_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.a64:2709 [F] s_b_16_0 = constant u32 0 (const) */
        /* execute.a64:2709 [D] s_b_16_1: sym_140254_1_temporary_value = s_b_16_0, dominates: s_b_18_0  */
        emitter.store_local(DV_sym_140254_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2709 [F] s_b_16_2: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.a64:2709 [F] s_b_17_0=sym_31450_3_parameter_inst.rt (const) */
        /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
        auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_17_2: sym_140254_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
        emitter.store_local(DV_sym_140254_1_temporary_value, s_b_17_1);
        /* execute.a64:2709 [F] s_b_17_3: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2709 [D] s_b_18_0 = sym_140254_1_temporary_value uint32_t */
        auto s_b_18_0 = emitter.load_local(DV_sym_140254_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
        auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_18_2 = sym_140182_1_tmp_s_b_4_0 uint64_t */
        auto s_b_18_2 = emitter.load_local(DV_sym_140182_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:1855 [D] s_b_18_3 = (u32)s_b_18_1 */
        auto s_b_18_3 = emitter.truncate(s_b_18_1, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_18_4: Store 4 s_b_18_2 <= s_b_18_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_3, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_18_2, s_b_18_3);
        /* execute.a64:794 [F] s_b_18_5=sym_31450_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_18_6 = (u32)s_b_18_5 (const) */
        /* execute.a64:2737 [F] s_b_18_7 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_18_8 = s_b_18_6==s_b_18_7 (const) */
        uint8_t s_b_18_8 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_18_9: If s_b_18_8: Jump b_2 else b_24 (const) */
        if (s_b_18_8) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.a64:2739 [F] s_b_19_0=sym_31450_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_19_1 = constant u64 1 (const) */
        /* execute.a64:2739 [F] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:0 [F] s_b_19_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.a64:2714 [F] s_b_20_0 = constant u64 0 (const) */
        /* execute.a64:2714 [D] s_b_20_1: sym_140491_1_temporary_value = s_b_20_0, dominates: s_b_22_0  */
        emitter.store_local(DV_sym_140491_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2714 [F] s_b_20_2: Jump b_22 (const) */
        {
          auto block = block_b_22;
          dynamic_block_queue.push(block_b_22);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.a64:2714 [F] s_b_21_0=sym_31450_3_parameter_inst.rt (const) */
        /* execute.a64:2714 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
        auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_21_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_21_2: sym_140491_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
        emitter.store_local(DV_sym_140491_1_temporary_value, s_b_21_1);
        /* execute.a64:2714 [F] s_b_21_3: Jump b_22 (const) */
        {
          auto block = block_b_22;
          dynamic_block_queue.push(block_b_22);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.a64:2714 [D] s_b_22_0 = sym_140491_1_temporary_value uint64_t */
        auto s_b_22_0 = emitter.load_local(DV_sym_140491_1_temporary_value, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_22_1 = sym_140417_1_tmp_s_b_5_0 uint64_t */
        auto s_b_22_1 = emitter.load_local(DV_sym_140417_1_tmp_s_b_5_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_22_2: Store 8 s_b_22_1 <= s_b_22_0 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_1, s_b_22_0, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_22_1, s_b_22_0);
        /* execute.a64:801 [F] s_b_22_3=sym_31450_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_22_4 = (u32)s_b_22_3 (const) */
        /* execute.a64:2737 [F] s_b_22_5 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_22_6 = s_b_22_4==s_b_22_5 (const) */
        uint8_t s_b_22_6 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_22_7: If s_b_22_6: Jump b_2 else b_25 (const) */
        if (s_b_22_6) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.a64:2739 [F] s_b_23_0=sym_31450_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_23_1 = constant u64 1 (const) */
        /* execute.a64:2739 [F] s_b_23_2: WriteRegBank 0:s_b_23_0 = s_b_23_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:0 [F] s_b_23_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.a64:2739 [F] s_b_24_0=sym_31450_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_24_1 = constant u64 0 (const) */
        /* execute.a64:2739 [F] s_b_24_2: WriteRegBank 0:s_b_24_0 = s_b_24_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_24_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.a64:2739 [F] s_b_25_0=sym_31450_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_25_1 = constant u64 0 (const) */
        /* execute.a64:2739 [F] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_25_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
    }
  }
  else 
  {
    emitter.jump(__exit_block);
  }
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_str(const arm64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_144752_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_144031_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31918_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_144713_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_144243_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_144317_1_temporary_value;
  auto DV_sym_144317_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_144103_1_temporary_value;
  auto DV_sym_144103_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_143910_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143927_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1096 [F] s_b_0_0=sym_31912_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_19 else b_20 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_21,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1099 [D] s_b_1_0 = sym_31918_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1099 [F] s_b_1_1=sym_31912_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1099 [D] s_b_1_4: sym_31918_0_address = s_b_1_3, dominates: s_b_6_0 s_b_17_0 s_b_18_1 s_b_7_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_31918_0_address, s_b_1_3);
    /* execute.a64:1099 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_21,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1102 [F] s_b_2_0=sym_31912_3_parameter_inst.V (const) */
    /* execute.a64:1102 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:1102 [F] s_b_2_2 = constant u32 0 (const) */
    /* execute.a64:1102 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.V) == (uint32_t)0ULL));
    /* execute.a64:1102 [F] s_b_2_4: If s_b_2_3: Jump b_3 else b_5 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1103 [F] s_b_3_0=sym_31912_3_parameter_inst.size (const) */
    /* execute.a64:1103 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1103 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1103 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:1103 [F] s_b_3_4: If s_b_3_3: Jump b_6 else b_7 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_8, b_10, b_12, b_14, b_15, b_16, b_29, b_32,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1122 [F] s_b_4_0=sym_31912_3_parameter_inst.P (const) */
    /* execute.a64:1122 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:1122 [F] s_b_4_2: If s_b_4_1: Jump b_17 else b_18 (const) */
    if (s_b_4_1) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_2,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1109 [F] s_b_5_0=sym_31912_3_parameter_inst.size (const) */
    /* execute.a64:1109 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1109 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:1109 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.a64:1109 [F] s_b_5_4=sym_31912_3_parameter_inst.X (const) */
    /* execute.a64:1109 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1109 [F] s_b_5_6 = constant u32 0 (const) */
    /* execute.a64:1109 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1109 [F] s_b_5_12: If s_b_5_11: Jump b_8 else b_9 (const) */
    if (s_b_5_11) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.a64:1104 [D] s_b_6_0 = sym_31918_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1104 [F] s_b_6_1=sym_31912_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_6_2: sym_144031_1_tmp_s_b_4_0 = s_b_6_0, dominates: s_b_29_2  */
    emitter.store_local(DV_sym_144031_1_tmp_s_b_4_0, s_b_6_0);
    /* execute.a64:2709 [F] s_b_6_3 = (u32)s_b_6_1 (const) */
    /* execute.a64:2709 [F] s_b_6_4 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_6_6: If s_b_6_5: Jump b_27 else b_28 (const) */
    if (s_b_6_5) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_28;
    }
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1106 [D] s_b_7_0 = sym_31918_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1106 [F] s_b_7_1=sym_31912_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_7_2: sym_144243_1_tmp_s_b_5_0 = s_b_7_0, dominates: s_b_32_1  */
    emitter.store_local(DV_sym_144243_1_tmp_s_b_5_0, s_b_7_0);
    /* execute.a64:2714 [F] s_b_7_3 = (u32)s_b_7_1 (const) */
    /* execute.a64:2714 [F] s_b_7_4 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_7_5 = s_b_7_3==s_b_7_4 (const) */
    uint8_t s_b_7_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_7_6: If s_b_7_5: Jump b_30 else b_31 (const) */
    if (s_b_7_5) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1110 [D] s_b_8_0 = sym_31918_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1110 [F] s_b_8_1=sym_31912_3_parameter_inst.rt (const) */
    /* execute.simd:6340 [D] s_b_8_2 = ReadRegBank 4:s_b_8_1 (u8) */
    auto s_b_8_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_8_2,emitter.const_u8(1));
    }
    /* ???:4294967295 [D] s_b_8_3: Store 1 s_b_8_0 <= s_b_8_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_8_0, s_b_8_2, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_8_0, s_b_8_2);
    /* execute.a64:0 [F] s_b_8_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1111 [F] s_b_9_0=sym_31912_3_parameter_inst.size (const) */
    /* execute.a64:1111 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:1111 [F] s_b_9_2 = constant u32 0 (const) */
    /* execute.a64:1111 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.a64:1111 [F] s_b_9_4=sym_31912_3_parameter_inst.X (const) */
    /* execute.a64:1111 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.a64:1111 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.a64:1111 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.a64:1111 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
    if (s_b_9_11) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_9,  */
  fixed_block_b_10: 
  {
    /* execute.a64:1112 [D] s_b_10_0 = sym_31918_0_address uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1112 [F] s_b_10_1=sym_31912_3_parameter_inst.rt (const) */
    /* execute.simd:6360 [D] s_b_10_2 = ReadRegBank 2:s_b_10_1 (u64) */
    auto s_b_10_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_2,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_10_3 = ReadRegBank 3:s_b_10_1 (u64) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_10_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_4: Store 8 s_b_10_0 <= s_b_10_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_10_0, s_b_10_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_10_0, s_b_10_2);
    /* execute.a64:1909 [F] s_b_10_5 = constant u64 8 (const) */
    /* execute.a64:1909 [D] s_b_10_6 = s_b_10_0+s_b_10_5 */
    auto s_b_10_6 = emitter.add(s_b_10_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_10_7: Store 8 s_b_10_6 <= s_b_10_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_10_6, s_b_10_3, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_10_6, s_b_10_3);
    /* execute.a64:0 [F] s_b_10_8: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:1113 [F] s_b_11_0=sym_31912_3_parameter_inst.size (const) */
    /* execute.a64:1113 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:1113 [F] s_b_11_2 = constant u32 1 (const) */
    /* execute.a64:1113 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.a64:1113 [F] s_b_11_4: If s_b_11_3: Jump b_12 else b_13 (const) */
    if (s_b_11_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:1114 [D] s_b_12_0 = sym_31918_0_address uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1114 [F] s_b_12_1=sym_31912_3_parameter_inst.rt (const) */
    /* execute.simd:6345 [D] s_b_12_2 = ReadRegBank 5:s_b_12_1 (u16) */
    auto s_b_12_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_2,emitter.const_u8(2));
    }
    /* ???:4294967295 [D] s_b_12_3: Store 2 s_b_12_0 <= s_b_12_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_12_0, s_b_12_2, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_12_0, s_b_12_2);
    /* execute.a64:0 [F] s_b_12_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1115 [F] s_b_13_0=sym_31912_3_parameter_inst.size (const) */
    /* execute.a64:1115 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:1115 [F] s_b_13_2 = constant u32 2 (const) */
    /* execute.a64:1115 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:1115 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_15 (const) */
    if (s_b_13_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1116 [D] s_b_14_0 = sym_31918_0_address uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1116 [F] s_b_14_1=sym_31912_3_parameter_inst.rt (const) */
    /* execute.simd:6350 [D] s_b_14_2 = ReadRegBank 6:s_b_14_1 (u32) */
    auto s_b_14_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_2,emitter.const_u8(4));
    }
    /* ???:4294967295 [D] s_b_14_3: Store 4 s_b_14_0 <= s_b_14_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_14_0, s_b_14_2, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_14_0, s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_13,  */
  fixed_block_b_15: 
  {
    /* execute.a64:1117 [F] s_b_15_0=sym_31912_3_parameter_inst.size (const) */
    /* execute.a64:1117 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.a64:1117 [F] s_b_15_2 = constant u32 3 (const) */
    /* execute.a64:1117 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.a64:1117 [F] s_b_15_4: If s_b_15_3: Jump b_16 else b_4 (const) */
    if (s_b_15_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:1118 [D] s_b_16_0 = sym_31918_0_address uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1118 [F] s_b_16_1=sym_31912_3_parameter_inst.rt (const) */
    /* execute.simd:6355 [D] s_b_16_2 = ReadRegBank 7:s_b_16_1 (u64) */
    auto s_b_16_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_2,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_16_3: Store 8 s_b_16_0 <= s_b_16_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_16_0, s_b_16_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_16_0, s_b_16_2);
    /* execute.a64:0 [F] s_b_16_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_4,  */
  fixed_block_b_17: 
  {
    /* execute.a64:1123 [D] s_b_17_0 = sym_31918_0_address uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1123 [F] s_b_17_1=sym_31912_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_17_2 = (u64)s_b_17_1 (const) */
    /* ???:4294967295 [D] s_b_17_3 = s_b_17_0+s_b_17_2 */
    auto s_b_17_3 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1123 [D] s_b_17_4: sym_31918_0_address = s_b_17_3, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_31918_0_address, s_b_17_3);
    /* execute.a64:1123 [F] s_b_17_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:1126 [F] s_b_18_0 = constant u8 1 (const) */
    /* execute.a64:1126 [D] s_b_18_1 = sym_31918_0_address uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_31918_0_address, emitter.context().types().u64());
    /* execute.a64:1126 [D] s_b_18_2: sym_144713_3_parameter_value = s_b_18_1, dominates: s_b_33_0 s_b_35_0 s_b_36_1  */
    emitter.store_local(DV_sym_144713_3_parameter_value, s_b_18_1);
    /* execute.a64:2809 [F] s_b_18_3 = !s_b_18_0 (const) */
    uint8_t s_b_18_3 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_18_4: If s_b_18_3: Jump b_33 else b_34 (const) */
    if (s_b_18_3) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_34;
    }
  }
  /* b_0,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2764 [F] s_b_19_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_19_1 = __builtin_get_feature */
    uint32_t s_b_19_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_19_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(s_b_19_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_19_4: If s_b_19_3: Jump b_22 else b_23 (const) */
    if (s_b_19_3) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_0,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2796 [F] s_b_20_0=sym_31912_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_20_2: sym_143910_0_return_symbol = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_143910_0_return_symbol, s_b_20_1);
    /* ???:4294967295 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_24,  */
  fixed_block_b_21: 
  {
    /* ???:4294967295 [D] s_b_21_0 = sym_143910_0_return_symbol uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_143910_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1096 [D] s_b_21_1: sym_31918_0_address = s_b_21_0, dominates: s_b_1_0 s_b_6_0 s_b_17_0 s_b_18_1 s_b_7_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_31918_0_address, s_b_21_0);
    /* execute.a64:1098 [F] s_b_21_2=sym_31912_3_parameter_inst.P (const) */
    /* execute.a64:1098 [F] s_b_21_3: If s_b_21_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_19,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2765 [D] s_b_22_0 = ReadReg 21 (u64) */
    auto s_b_22_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_22_1: sym_143927_1__R_s_b_3_0 = s_b_22_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_143927_1__R_s_b_3_0, s_b_22_0);
    /* execute.a64:2765 [F] s_b_22_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_23: 
  {
    /* execute.a64:3075 [F] s_b_23_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_23_1 = __builtin_get_feature */
    uint32_t s_b_23_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_23_2 = (u8)s_b_23_1 (const) */
    /* execute.a64:2767 [F] s_b_23_3 = (u32)s_b_23_2 (const) */
    /* execute.a64:2767 [F] s_b_23_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_23_5 = s_b_23_3==s_b_23_4 (const) */
    uint8_t s_b_23_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_23_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_23_6: If s_b_23_5: Jump b_25 else b_26 (const) */
    if (s_b_23_5) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_22, b_25, b_26,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2794 [D] s_b_24_0 = sym_143927_1__R_s_b_3_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_143927_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_24_1: sym_143910_0_return_symbol = s_b_24_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_143910_0_return_symbol, s_b_24_0);
    /* ???:4294967295 [F] s_b_24_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_23,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2768 [D] s_b_25_0 = ReadReg 21 (u64) */
    auto s_b_25_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_25_1: sym_143927_1__R_s_b_3_0 = s_b_25_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_143927_1__R_s_b_3_0, s_b_25_0);
    /* execute.a64:2768 [F] s_b_25_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2770 [D] s_b_26_0 = ReadReg 22 (u64) */
    auto s_b_26_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_26_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_26_1: sym_143927_1__R_s_b_3_0 = s_b_26_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_143927_1__R_s_b_3_0, s_b_26_0);
    /* execute.a64:2770 [F] s_b_26_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_6,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2709 [F] s_b_27_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_27_1: sym_144103_1_temporary_value = s_b_27_0 (const), dominates: s_b_29_0  */
    CV_sym_144103_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_144103_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_27_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_6,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2709 [F] s_b_28_0=sym_31912_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_28_1 = ReadRegBank 1:s_b_28_0 (u32) */
    auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_28_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_28_2: sym_144103_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_144103_1_temporary_value, s_b_28_1);
    /* execute.a64:2709 [F] s_b_28_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2709 [D] s_b_29_0 = sym_144103_1_temporary_value uint32_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_144103_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_29_1 = (u64)s_b_29_0 */
    auto s_b_29_1 = emitter.zx(s_b_29_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_29_2 = sym_144031_1_tmp_s_b_4_0 uint64_t */
    auto s_b_29_2 = emitter.load_local(DV_sym_144031_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:1855 [D] s_b_29_3 = (u32)s_b_29_1 */
    auto s_b_29_3 = emitter.truncate(s_b_29_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_29_4: Store 4 s_b_29_2 <= s_b_29_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_29_2, s_b_29_3, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_29_2, s_b_29_3);
    /* execute.a64:0 [F] s_b_29_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2714 [F] s_b_30_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_30_1: sym_144317_1_temporary_value = s_b_30_0 (const), dominates: s_b_32_0  */
    CV_sym_144317_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_144317_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_30_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_7,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2714 [F] s_b_31_0=sym_31912_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_31_1 = ReadRegBank 0:s_b_31_0 (u64) */
    auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_31_2: sym_144317_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_144317_1_temporary_value, s_b_31_1);
    /* execute.a64:2714 [F] s_b_31_3: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2714 [D] s_b_32_0 = sym_144317_1_temporary_value uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_144317_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_1 = sym_144243_1_tmp_s_b_5_0 uint64_t */
    auto s_b_32_1 = emitter.load_local(DV_sym_144243_1_tmp_s_b_5_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_2: Store 8 s_b_32_1 <= s_b_32_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_32_1, s_b_32_0, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_32_1, s_b_32_0);
    /* execute.a64:0 [F] s_b_32_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_18,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2810 [D] s_b_33_0 = sym_144713_3_parameter_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_144713_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_33_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_33_2 = s_b_33_0&s_b_33_1 */
    auto s_b_33_2 = emitter.bitwise_and(s_b_33_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_33_3: sym_144713_3_parameter_value = s_b_33_2, dominates: s_b_35_0 s_b_36_1  */
    emitter.store_local(DV_sym_144713_3_parameter_value, s_b_33_2);
    /* execute.a64:2810 [F] s_b_33_4: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_18, b_33,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2813 [F] s_b_34_0=sym_31912_3_parameter_inst.rn (const) */
    /* execute.a64:2813 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
    /* execute.a64:2813 [F] s_b_34_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_34_3 = s_b_34_1==s_b_34_2 (const) */
    uint8_t s_b_34_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_34_4: If s_b_34_3: Jump b_35 else b_36 (const) */
    if (s_b_34_3) 
    {
      goto fixed_block_b_35;
    }
    else 
    {
      goto fixed_block_b_36;
    }
  }
  /* b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2814 [D] s_b_35_0 = sym_144713_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_144713_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_35_1: sym_144752_3_parameter_value = s_b_35_0, dominates: s_b_38_0 s_b_39_0 s_b_40_0  */
    emitter.store_local(DV_sym_144752_3_parameter_value, s_b_35_0);
    /* execute.a64:2777 [F] s_b_35_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_35_3 = __builtin_get_feature */
    uint32_t s_b_35_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_35_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_35_5 = s_b_35_3==s_b_35_4 (const) */
    uint8_t s_b_35_5 = ((uint8_t)(s_b_35_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_35_6: If s_b_35_5: Jump b_38 else b_41 (const) */
    if (s_b_35_5) 
    {
      goto fixed_block_b_38;
    }
    else 
    {
      goto fixed_block_b_41;
    }
  }
  /* b_34,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2816 [F] s_b_36_0=sym_31912_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_36_1 = sym_144713_3_parameter_value uint64_t */
    auto s_b_36_1 = emitter.load_local(DV_sym_144713_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_36_2: WriteRegBank 0:s_b_36_0 = s_b_36_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_36_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_36_1);
    /* execute.a64:2816 [F] s_b_36_3: Jump b_37 (const) */
    goto fixed_block_b_37;
  }
  /* b_36, b_38, b_39, b_40,  */
  fixed_block_b_37: 
  {
    /* ???:4294967295 [F] s_b_37_0: Return */
    goto fixed_done;
  }
  /* b_35,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2778 [D] s_b_38_0 = sym_144752_3_parameter_value uint64_t */
    auto s_b_38_0 = emitter.load_local(DV_sym_144752_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_38_1: WriteReg 21 = s_b_38_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_38_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_38_0);
    /* execute.a64:2778 [F] s_b_38_2: Jump b_37 (const) */
    goto fixed_block_b_37;
  }
  /* b_41,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2781 [D] s_b_39_0 = sym_144752_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_144752_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_39_1: WriteReg 21 = s_b_39_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_39_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_39_0);
    /* execute.a64:2781 [F] s_b_39_2: Jump b_37 (const) */
    goto fixed_block_b_37;
  }
  /* b_41,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2783 [D] s_b_40_0 = sym_144752_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_144752_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_40_1: WriteReg 22 = s_b_40_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_40_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_40_0);
    /* execute.a64:2783 [F] s_b_40_2: Jump b_37 (const) */
    goto fixed_block_b_37;
  }
  /* b_35,  */
  fixed_block_b_41: 
  {
    /* execute.a64:3075 [F] s_b_41_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_41_1 = __builtin_get_feature */
    uint32_t s_b_41_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_41_2 = (u8)s_b_41_1 (const) */
    /* execute.a64:2780 [F] s_b_41_3 = (u32)s_b_41_2 (const) */
    /* execute.a64:2780 [F] s_b_41_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_41_5 = s_b_41_3==s_b_41_4 (const) */
    uint8_t s_b_41_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_41_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_41_6: If s_b_41_5: Jump b_39 else b_40 (const) */
    if (s_b_41_5) 
    {
      goto fixed_block_b_39;
    }
    else 
    {
      goto fixed_block_b_40;
    }
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_strhi(const arm64_decode_a64_LS_REG_UIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_149483_1_temporary_value;
  auto DV_sym_149483_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_149359_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_149376_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_149512_1_tmp_s_b_19_2 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1483 [F] s_b_0_0=sym_32862_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_2 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2764 [F] s_b_1_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_1_1 = __builtin_get_feature */
    uint32_t s_b_1_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(s_b_1_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2796 [F] s_b_2_0=sym_32862_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_149359_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_149359_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_149359_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_149359_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1483 [F] s_b_3_1=sym_32862_3_parameter_inst.immu64 (const) */
    /* execute.a64:1483 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.a64:1485 [F] s_b_3_3=sym_32862_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_3_4: sym_149512_1_tmp_s_b_19_2 = s_b_3_2, dominates: s_b_11_2  */
    emitter.store_local(DV_sym_149512_1_tmp_s_b_19_2, s_b_3_2);
    /* execute.a64:2709 [F] s_b_3_5 = (u32)s_b_3_3 (const) */
    /* execute.a64:2709 [F] s_b_3_6 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_3_8: If s_b_3_7: Jump b_9 else b_10 (const) */
    if (s_b_3_7) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2765 [D] s_b_4_0 = ReadReg 21 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_4_1: sym_149376_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_149376_1__R_s_b_3_0, s_b_4_0);
    /* execute.a64:2765 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:3075 [F] s_b_5_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_5_1 = __builtin_get_feature */
    uint32_t s_b_5_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_5_2 = (u8)s_b_5_1 (const) */
    /* execute.a64:2767 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:2767 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_5_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_5_6: If s_b_5_5: Jump b_7 else b_8 (const) */
    if (s_b_5_5) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_4, b_7, b_8,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2794 [D] s_b_6_0 = sym_149376_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_149376_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_149359_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_149359_0_return_symbol, s_b_6_0);
    /* ???:4294967295 [F] s_b_6_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2768 [D] s_b_7_0 = ReadReg 21 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_7_1: sym_149376_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_149376_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2768 [F] s_b_7_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2770 [D] s_b_8_0 = ReadReg 22 (u64) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_8_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_8_1: sym_149376_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_149376_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2770 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2709 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_9_1: sym_149483_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_149483_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_149483_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2709 [F] s_b_10_0=sym_32862_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_10_1 = ReadRegBank 1:s_b_10_0 (u32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_10_2: sym_149483_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_149483_1_temporary_value, s_b_10_1);
    /* execute.a64:2709 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [D] s_b_11_0 = sym_149483_1_temporary_value uint32_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_149483_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_11_1 = (u64)s_b_11_0 */
    auto s_b_11_1 = emitter.zx(s_b_11_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_2 = sym_149512_1_tmp_s_b_19_2 uint64_t */
    auto s_b_11_2 = emitter.load_local(DV_sym_149512_1_tmp_s_b_19_2, emitter.context().types().u64());
    /* execute.a64:1486 [D] s_b_11_3 = (u16)s_b_11_1 */
    auto s_b_11_3 = emitter.truncate(s_b_11_1, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_11_4: Store 2 s_b_11_2 <= s_b_11_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_11_2, s_b_11_3, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_11_2, s_b_11_3);
    /* ???:4294967295 [F] s_b_11_5: Return */
    goto fixed_done;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stxp(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_16 = emitter.context().create_block();
  auto block_b_17 = emitter.context().create_block();
  auto block_b_18 = emitter.context().create_block();
  auto block_b_19 = emitter.context().create_block();
  auto block_b_20 = emitter.context().create_block();
  auto block_b_21 = emitter.context().create_block();
  auto block_b_22 = emitter.context().create_block();
  auto block_b_23 = emitter.context().create_block();
  auto block_b_24 = emitter.context().create_block();
  auto block_b_25 = emitter.context().create_block();
  auto block_b_26 = emitter.context().create_block();
  auto block_b_27 = emitter.context().create_block();
  auto block_b_28 = emitter.context().create_block();
  auto block_b_29 = emitter.context().create_block();
  auto block_b_30 = emitter.context().create_block();
  auto block_b_31 = emitter.context().create_block();
  auto DV_sym_150318_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_33039_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_151084_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_150494_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_150660_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_150872_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_150944_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_150301_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_151158_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_150588_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_150813_1_tmp_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_150734_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_150422_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:810 [F] s_b_0_0=sym_33033_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_9 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_10,  */
  fixed_block_b_1: 
  {
    /* execute.a64:813 [F] s_b_1_0 = constant u32 0 (const) */
    /* execute.a64:813 [D] s_b_1_1 = sym_33039_0_address uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_33039_0_address, emitter.context().types().u64());
    /* execute.a64:813 [D] s_b_1_2 = mem_monitor_release */
    auto s_b_1_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_1_1);
    /* execute.a64:813 [D] s_b_1_3: If s_b_1_2: Jump b_4 else b_5 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_4;
        dynamic_block_queue.push(block_b_4);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_5;
        dynamic_block_queue.push(block_b_5);
        false_target = block;
      }
      emitter.branch(s_b_1_2, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_10,  */
  fixed_block_b_3: 
  {
    /* execute.a64:821 [F] s_b_3_0 = constant u32 0 (const) */
    /* execute.a64:821 [D] s_b_3_1 = sym_33039_0_address uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_33039_0_address, emitter.context().types().u64());
    /* execute.a64:821 [D] s_b_3_2 = mem_monitor_release */
    auto s_b_3_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_3_1);
    /* execute.a64:821 [D] s_b_3_3: If s_b_3_2: Jump b_6 else b_7 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_6;
        dynamic_block_queue.push(block_b_6);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_7;
        dynamic_block_queue.push(block_b_7);
        false_target = block;
      }
      emitter.branch(s_b_3_2, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  // BLOCK b_6 not fully fixed
  // BLOCK b_7 not fully fixed
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2764 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_8_4: If s_b_8_3: Jump b_11 else b_12 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2796 [F] s_b_9_0=sym_33033_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_150301_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_150301_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_150301_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_150301_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:810 [D] s_b_10_1: sym_33039_0_address = s_b_10_0, dominates: s_b_1_1 s_b_4_0 s_b_3_1 s_b_6_0  */
    emitter.store_local(DV_sym_33039_0_address, s_b_10_0);
    /* execute.a64:812 [F] s_b_10_2=sym_33033_3_parameter_inst.size (const) */
    /* execute.a64:812 [F] s_b_10_3 = (u32)s_b_10_2 (const) */
    /* execute.a64:812 [F] s_b_10_4 = constant u32 2 (const) */
    /* execute.a64:812 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:812 [F] s_b_10_6: If s_b_10_5: Jump b_1 else b_3 (const) */
    if (s_b_10_5) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2765 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_11_1: sym_150318_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_150318_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2765 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_8,  */
  fixed_block_b_12: 
  {
    /* execute.a64:3075 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_12_1 = __builtin_get_feature */
    uint32_t s_b_12_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_12_2 = (u8)s_b_12_1 (const) */
    /* execute.a64:2767 [F] s_b_12_3 = (u32)s_b_12_2 (const) */
    /* execute.a64:2767 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_12_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_12_6: If s_b_12_5: Jump b_14 else b_15 (const) */
    if (s_b_12_5) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_11, b_14, b_15,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2794 [D] s_b_13_0 = sym_150318_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_150318_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_150301_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_150301_0_return_symbol, s_b_13_0);
    /* ???:4294967295 [F] s_b_13_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2768 [D] s_b_14_0 = ReadReg 21 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_14_1: sym_150318_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_150318_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2768 [F] s_b_14_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_12,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2770 [D] s_b_15_0 = ReadReg 22 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_15_1: sym_150318_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_150318_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2770 [F] s_b_15_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  // BLOCK b_16 not fully fixed
  // BLOCK b_17 not fully fixed
  // BLOCK b_18 not fully fixed
  // BLOCK b_19 not fully fixed
  // BLOCK b_20 not fully fixed
  // BLOCK b_21 not fully fixed
  // BLOCK b_22 not fully fixed
  // BLOCK b_23 not fully fixed
  // BLOCK b_24 not fully fixed
  // BLOCK b_25 not fully fixed
  // BLOCK b_26 not fully fixed
  // BLOCK b_27 not fully fixed
  // BLOCK b_28 not fully fixed
  // BLOCK b_29 not fully fixed
  // BLOCK b_30 not fully fixed
  // BLOCK b_31 not fully fixed
  fixed_done:
  if (dynamic_block_queue.size() > 0) 
  {
    std::set<captive::arch::dbt::el::Block *> emitted_blocks;
    while (dynamic_block_queue.size() > 0) 
    {
      captive::arch::dbt::el::Block *block_index = dynamic_block_queue.front();
      dynamic_block_queue.pop();
      if (emitted_blocks.count(block_index)) continue;
      emitted_blocks.insert(block_index);
      if (block_index == block_b_2) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_2);
        /* ???:4294967295 [F] s_b_2_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.a64:814 [D] s_b_4_0 = sym_33039_0_address uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_33039_0_address, emitter.context().types().u64());
        /* execute.a64:814 [F] s_b_4_1=sym_33033_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_4_2: sym_150588_1_tmp_s_b_4_0 = s_b_4_0, dominates: s_b_18_5  */
        emitter.store_local(DV_sym_150588_1_tmp_s_b_4_0, s_b_4_0);
        /* ???:4294967295 [D] s_b_4_3: sym_150422_1_tmp_s_b_4_0 = s_b_4_0, dominates: s_b_18_2  */
        emitter.store_local(DV_sym_150422_1_tmp_s_b_4_0, s_b_4_0);
        /* execute.a64:2709 [F] s_b_4_4 = (u32)s_b_4_1 (const) */
        /* execute.a64:2709 [F] s_b_4_5 = constant u32 1f (const) */
        /* execute.a64:2709 [F] s_b_4_6 = s_b_4_4==s_b_4_5 (const) */
        uint8_t s_b_4_6 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2709 [F] s_b_4_7: If s_b_4_6: Jump b_16 else b_17 (const) */
        if (s_b_4_6) 
        {
          auto block = block_b_16;
          dynamic_block_queue.push(block_b_16);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_17;
          dynamic_block_queue.push(block_b_17);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:818 [F] s_b_5_0=sym_33033_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
        /* execute.a64:2737 [F] s_b_5_2 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
        uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_5_4: If s_b_5_3: Jump b_2 else b_19 (const) */
        if (s_b_5_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.a64:822 [D] s_b_6_0 = sym_33039_0_address uint64_t */
        auto s_b_6_0 = emitter.load_local(DV_sym_33039_0_address, emitter.context().types().u64());
        /* execute.a64:822 [F] s_b_6_1=sym_33033_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_6_2: sym_150813_1_tmp_s_b_7_0 = s_b_6_0, dominates: s_b_22_3  */
        emitter.store_local(DV_sym_150813_1_tmp_s_b_7_0, s_b_6_0);
        /* ???:4294967295 [D] s_b_6_3: sym_150660_1_tmp_s_b_5_0 = s_b_6_0, dominates: s_b_22_1  */
        emitter.store_local(DV_sym_150660_1_tmp_s_b_5_0, s_b_6_0);
        /* execute.a64:2714 [F] s_b_6_4 = (u32)s_b_6_1 (const) */
        /* execute.a64:2714 [F] s_b_6_5 = constant u32 1f (const) */
        /* execute.a64:2714 [F] s_b_6_6 = s_b_6_4==s_b_6_5 (const) */
        uint8_t s_b_6_6 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2714 [F] s_b_6_7: If s_b_6_6: Jump b_20 else b_21 (const) */
        if (s_b_6_6) 
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.a64:826 [F] s_b_7_0=sym_33033_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
        /* execute.a64:2737 [F] s_b_7_2 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
        uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_7_4: If s_b_7_3: Jump b_2 else b_23 (const) */
        if (s_b_7_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.a64:2709 [F] s_b_16_0 = constant u32 0 (const) */
        /* execute.a64:2709 [D] s_b_16_1: sym_150494_1_temporary_value = s_b_16_0, dominates: s_b_18_0  */
        emitter.store_local(DV_sym_150494_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2709 [F] s_b_16_2: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.a64:2709 [F] s_b_17_0=sym_33033_3_parameter_inst.rt (const) */
        /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
        auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_17_2: sym_150494_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
        emitter.store_local(DV_sym_150494_1_temporary_value, s_b_17_1);
        /* execute.a64:2709 [F] s_b_17_3: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2709 [D] s_b_18_0 = sym_150494_1_temporary_value uint32_t */
        auto s_b_18_0 = emitter.load_local(DV_sym_150494_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
        auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_18_2 = sym_150422_1_tmp_s_b_4_0 uint64_t */
        auto s_b_18_2 = emitter.load_local(DV_sym_150422_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:1855 [D] s_b_18_3 = (u32)s_b_18_1 */
        auto s_b_18_3 = emitter.truncate(s_b_18_1, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_18_4: Store 4 s_b_18_2 <= s_b_18_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_3, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_18_2, s_b_18_3);
        /* ???:4294967295 [D] s_b_18_5 = sym_150588_1_tmp_s_b_4_0 uint64_t */
        auto s_b_18_5 = emitter.load_local(DV_sym_150588_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:815 [F] s_b_18_6 = constant u64 4 (const) */
        /* execute.a64:815 [D] s_b_18_7 = s_b_18_5+s_b_18_6 */
        auto s_b_18_7 = emitter.add(s_b_18_5, emitter.const_u64((uint64_t)4ULL));
        /* execute.a64:815 [F] s_b_18_8=sym_33033_3_parameter_inst.rt2 (const) */
        /* ???:4294967295 [D] s_b_18_9: sym_150872_1_tmp_s_b_4_0 = s_b_18_7, dominates: s_b_26_2  */
        emitter.store_local(DV_sym_150872_1_tmp_s_b_4_0, s_b_18_7);
        /* execute.a64:2709 [F] s_b_18_10 = (u32)s_b_18_8 (const) */
        /* execute.a64:2709 [F] s_b_18_11 = constant u32 1f (const) */
        /* execute.a64:2709 [F] s_b_18_12 = s_b_18_10==s_b_18_11 (const) */
        uint8_t s_b_18_12 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
        /* execute.a64:2709 [F] s_b_18_13: If s_b_18_12: Jump b_24 else b_25 (const) */
        if (s_b_18_12) 
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.a64:2739 [F] s_b_19_0=sym_33033_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_19_1 = constant u64 1 (const) */
        /* execute.a64:2739 [F] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:0 [F] s_b_19_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.a64:2714 [F] s_b_20_0 = constant u64 0 (const) */
        /* execute.a64:2714 [D] s_b_20_1: sym_150734_1_temporary_value = s_b_20_0, dominates: s_b_22_0  */
        emitter.store_local(DV_sym_150734_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2714 [F] s_b_20_2: Jump b_22 (const) */
        {
          auto block = block_b_22;
          dynamic_block_queue.push(block_b_22);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.a64:2714 [F] s_b_21_0=sym_33033_3_parameter_inst.rt (const) */
        /* execute.a64:2714 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
        auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_21_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_21_2: sym_150734_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
        emitter.store_local(DV_sym_150734_1_temporary_value, s_b_21_1);
        /* execute.a64:2714 [F] s_b_21_3: Jump b_22 (const) */
        {
          auto block = block_b_22;
          dynamic_block_queue.push(block_b_22);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.a64:2714 [D] s_b_22_0 = sym_150734_1_temporary_value uint64_t */
        auto s_b_22_0 = emitter.load_local(DV_sym_150734_1_temporary_value, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_22_1 = sym_150660_1_tmp_s_b_5_0 uint64_t */
        auto s_b_22_1 = emitter.load_local(DV_sym_150660_1_tmp_s_b_5_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_22_2: Store 8 s_b_22_1 <= s_b_22_0 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_1, s_b_22_0, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_22_1, s_b_22_0);
        /* ???:4294967295 [D] s_b_22_3 = sym_150813_1_tmp_s_b_7_0 uint64_t */
        auto s_b_22_3 = emitter.load_local(DV_sym_150813_1_tmp_s_b_7_0, emitter.context().types().u64());
        /* execute.a64:823 [F] s_b_22_4 = constant u64 8 (const) */
        /* execute.a64:823 [D] s_b_22_5 = s_b_22_3+s_b_22_4 */
        auto s_b_22_5 = emitter.add(s_b_22_3, emitter.const_u64((uint64_t)8ULL));
        /* execute.a64:823 [F] s_b_22_6=sym_33033_3_parameter_inst.rt2 (const) */
        /* ???:4294967295 [D] s_b_22_7: sym_151084_1_tmp_s_b_5_0 = s_b_22_5, dominates: s_b_29_1  */
        emitter.store_local(DV_sym_151084_1_tmp_s_b_5_0, s_b_22_5);
        /* execute.a64:2714 [F] s_b_22_8 = (u32)s_b_22_6 (const) */
        /* execute.a64:2714 [F] s_b_22_9 = constant u32 1f (const) */
        /* execute.a64:2714 [F] s_b_22_10 = s_b_22_8==s_b_22_9 (const) */
        uint8_t s_b_22_10 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
        /* execute.a64:2714 [F] s_b_22_11: If s_b_22_10: Jump b_27 else b_28 (const) */
        if (s_b_22_10) 
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_28;
          dynamic_block_queue.push(block_b_28);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.a64:2739 [F] s_b_23_0=sym_33033_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_23_1 = constant u64 1 (const) */
        /* execute.a64:2739 [F] s_b_23_2: WriteRegBank 0:s_b_23_0 = s_b_23_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:0 [F] s_b_23_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.a64:2709 [F] s_b_24_0 = constant u32 0 (const) */
        /* execute.a64:2709 [D] s_b_24_1: sym_150944_1_temporary_value = s_b_24_0, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_150944_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2709 [F] s_b_24_2: Jump b_26 (const) */
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.a64:2709 [F] s_b_25_0=sym_33033_3_parameter_inst.rt2 (const) */
        /* execute.a64:2709 [D] s_b_25_1 = ReadRegBank 1:s_b_25_0 (u32) */
        auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_25_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_25_2: sym_150944_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_150944_1_temporary_value, s_b_25_1);
        /* execute.a64:2709 [F] s_b_25_3: Jump b_26 (const) */
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.a64:2709 [D] s_b_26_0 = sym_150944_1_temporary_value uint32_t */
        auto s_b_26_0 = emitter.load_local(DV_sym_150944_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_26_1 = (u64)s_b_26_0 */
        auto s_b_26_1 = emitter.zx(s_b_26_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_26_2 = sym_150872_1_tmp_s_b_4_0 uint64_t */
        auto s_b_26_2 = emitter.load_local(DV_sym_150872_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:1855 [D] s_b_26_3 = (u32)s_b_26_1 */
        auto s_b_26_3 = emitter.truncate(s_b_26_1, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_26_4: Store 4 s_b_26_2 <= s_b_26_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_26_2, s_b_26_3, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_26_2, s_b_26_3);
        /* execute.a64:816 [F] s_b_26_5=sym_33033_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_26_6 = (u32)s_b_26_5 (const) */
        /* execute.a64:2737 [F] s_b_26_7 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_26_8 = s_b_26_6==s_b_26_7 (const) */
        uint8_t s_b_26_8 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_26_9: If s_b_26_8: Jump b_2 else b_30 (const) */
        if (s_b_26_8) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_30;
          dynamic_block_queue.push(block_b_30);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.a64:2714 [F] s_b_27_0 = constant u64 0 (const) */
        /* execute.a64:2714 [D] s_b_27_1: sym_151158_1_temporary_value = s_b_27_0, dominates: s_b_29_0  */
        emitter.store_local(DV_sym_151158_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2714 [F] s_b_27_2: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.a64:2714 [F] s_b_28_0=sym_33033_3_parameter_inst.rt2 (const) */
        /* execute.a64:2714 [D] s_b_28_1 = ReadRegBank 0:s_b_28_0 (u64) */
        auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_28_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_28_2: sym_151158_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
        emitter.store_local(DV_sym_151158_1_temporary_value, s_b_28_1);
        /* execute.a64:2714 [F] s_b_28_3: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.a64:2714 [D] s_b_29_0 = sym_151158_1_temporary_value uint64_t */
        auto s_b_29_0 = emitter.load_local(DV_sym_151158_1_temporary_value, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_29_1 = sym_151084_1_tmp_s_b_5_0 uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_151084_1_tmp_s_b_5_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_29_2: Store 8 s_b_29_1 <= s_b_29_0 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_29_1, s_b_29_0, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_29_1, s_b_29_0);
        /* execute.a64:824 [F] s_b_29_3=sym_33033_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_29_4 = (u32)s_b_29_3 (const) */
        /* execute.a64:2737 [F] s_b_29_5 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_29_6 = s_b_29_4==s_b_29_5 (const) */
        uint8_t s_b_29_6 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_29_7: If s_b_29_6: Jump b_2 else b_31 (const) */
        if (s_b_29_6) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.a64:2739 [F] s_b_30_0=sym_33033_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_30_1 = constant u64 0 (const) */
        /* execute.a64:2739 [F] s_b_30_2: WriteRegBank 0:s_b_30_0 = s_b_30_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_30_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.a64:2739 [F] s_b_31_0=sym_33033_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_31_1 = constant u64 0 (const) */
        /* execute.a64:2739 [F] s_b_31_2: WriteRegBank 0:s_b_31_0 = s_b_31_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_31_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
    }
  }
  else 
  {
    emitter.jump(__exit_block);
  }
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sys(const arm64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_154114_1_temporary_value;
  auto DV_sym_154114_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_154143_1_temporary_value;
  auto DV_sym_154143_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_154172_1_temporary_value;
  auto DV_sym_154172_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:540 [F] s_b_0_0=sym_33639_3_parameter_inst.crn (const) */
    /* execute.a64:540 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:540 [F] s_b_0_2 = constant u32 7 (const) */
    /* execute.a64:540 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)7ULL));
    /* execute.a64:540 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_1: 
  {
    /* execute.a64:541 [F] s_b_1_0=sym_33639_3_parameter_inst.op1 (const) */
    /* execute.a64:541 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:541 [F] s_b_1_2 = constant u32 3 (const) */
    /* execute.a64:541 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* execute.a64:541 [F] s_b_1_4=sym_33639_3_parameter_inst.crm (const) */
    /* execute.a64:541 [F] s_b_1_5 = (u32)s_b_1_4 (const) */
    /* execute.a64:541 [F] s_b_1_6 = constant u32 4 (const) */
    /* execute.a64:541 [F] s_b_1_7 = s_b_1_5==s_b_1_6 (const) */
    uint8_t s_b_1_7 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_1_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_1_9 = s_b_1_3!=s_b_1_8 (const) */
    uint8_t s_b_1_9 = ((uint8_t)(s_b_1_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_10 = s_b_1_7!=s_b_1_8 (const) */
    uint8_t s_b_1_10 = ((uint8_t)(s_b_1_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_11 = s_b_1_9&s_b_1_10 (const) */
    uint8_t s_b_1_11 = ((uint8_t)(s_b_1_9 & s_b_1_10));
    /* execute.a64:541 [F] s_b_1_12=sym_33639_3_parameter_inst.op2 (const) */
    /* execute.a64:541 [F] s_b_1_13 = (u32)s_b_1_12 (const) */
    /* execute.a64:541 [F] s_b_1_14 = constant u32 1 (const) */
    /* execute.a64:541 [F] s_b_1_15 = s_b_1_13==s_b_1_14 (const) */
    uint8_t s_b_1_15 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_1_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_1_17 = s_b_1_11!=s_b_1_16 (const) */
    uint8_t s_b_1_17 = ((uint8_t)(s_b_1_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_18 = s_b_1_15!=s_b_1_16 (const) */
    uint8_t s_b_1_18 = ((uint8_t)(s_b_1_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_19 = s_b_1_17&s_b_1_18 (const) */
    uint8_t s_b_1_19 = ((uint8_t)(s_b_1_17 & s_b_1_18));
    /* execute.a64:541 [F] s_b_1_20: If s_b_1_19: Jump b_4 else b_5 (const) */
    if (s_b_1_19) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_3, b_6, b_7, b_11, b_13, b_16, b_19,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:551 [F] s_b_3_0=sym_33639_3_parameter_inst.crn (const) */
    /* execute.a64:551 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:551 [F] s_b_3_2 = constant u32 8 (const) */
    /* execute.a64:551 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)8ULL));
    /* execute.a64:551 [F] s_b_3_4: If s_b_3_3: Jump b_9 else b_2 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:544 [F] s_b_4_0=sym_33639_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2714 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_4_4: If s_b_4_3: Jump b_12 else b_14 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:546 [F] s_b_5_0=sym_33639_3_parameter_inst.op1 (const) */
    /* execute.a64:546 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:546 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:546 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* execute.a64:546 [F] s_b_5_4=sym_33639_3_parameter_inst.crm (const) */
    /* execute.a64:546 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:546 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:546 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)1ULL));
    /* execute.a64:546 [F] s_b_5_8=sym_33639_3_parameter_inst.crm (const) */
    /* execute.a64:546 [F] s_b_5_9 = (u32)s_b_5_8 (const) */
    /* execute.a64:546 [F] s_b_5_10 = constant u32 5 (const) */
    /* execute.a64:546 [F] s_b_5_11 = s_b_5_9==s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)5ULL));
    /* ???:4294967295 [F] s_b_5_12 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_13 = s_b_5_7!=s_b_5_12 (const) */
    uint8_t s_b_5_13 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_14 = s_b_5_11!=s_b_5_12 (const) */
    uint8_t s_b_5_14 = ((uint8_t)(s_b_5_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_15 = s_b_5_13|s_b_5_14 (const) */
    uint8_t s_b_5_15 = ((uint8_t)(s_b_5_13 | s_b_5_14));
    /* ???:4294967295 [F] s_b_5_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_17 = s_b_5_3!=s_b_5_16 (const) */
    uint8_t s_b_5_17 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_18 = s_b_5_15!=s_b_5_16 (const) */
    uint8_t s_b_5_18 = ((uint8_t)(s_b_5_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_19 = s_b_5_17&s_b_5_18 (const) */
    uint8_t s_b_5_19 = ((uint8_t)(s_b_5_17 & s_b_5_18));
    /* execute.a64:546 [F] s_b_5_20=sym_33639_3_parameter_inst.op2 (const) */
    /* execute.a64:546 [F] s_b_5_21 = (u32)s_b_5_20 (const) */
    /* execute.a64:546 [F] s_b_5_22 = constant u32 0 (const) */
    /* execute.a64:546 [F] s_b_5_23 = s_b_5_21==s_b_5_22 (const) */
    uint8_t s_b_5_23 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_25 = s_b_5_19!=s_b_5_24 (const) */
    uint8_t s_b_5_25 = ((uint8_t)(s_b_5_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_26 = s_b_5_23!=s_b_5_24 (const) */
    uint8_t s_b_5_26 = ((uint8_t)(s_b_5_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_27 = s_b_5_25&s_b_5_26 (const) */
    uint8_t s_b_5_27 = ((uint8_t)(s_b_5_25 & s_b_5_26));
    /* execute.a64:546 [F] s_b_5_28: If s_b_5_27: Jump b_6 else b_7 (const) */
    if (s_b_5_27) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:547 [D] s_b_6_0 = __builtin_jit_invalidate_txln_all */
    emitter.call(__captive___builtin_jit_invalidate_txln_all);
    /* execute.a64:547 [F] s_b_6_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:548 [F] s_b_7_0=sym_33639_3_parameter_inst.op1 (const) */
    /* execute.a64:548 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:548 [F] s_b_7_2 = constant u32 3 (const) */
    /* execute.a64:548 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* execute.a64:548 [F] s_b_7_4=sym_33639_3_parameter_inst.crm (const) */
    /* execute.a64:548 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:548 [F] s_b_7_6 = constant u32 5 (const) */
    /* execute.a64:548 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)5ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:548 [F] s_b_7_12=sym_33639_3_parameter_inst.op2 (const) */
    /* execute.a64:548 [F] s_b_7_13 = (u32)s_b_7_12 (const) */
    /* execute.a64:548 [F] s_b_7_14 = constant u32 1 (const) */
    /* execute.a64:548 [F] s_b_7_15 = s_b_7_13==s_b_7_14 (const) */
    uint8_t s_b_7_15 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_7_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_17 = s_b_7_11!=s_b_7_16 (const) */
    uint8_t s_b_7_17 = ((uint8_t)(s_b_7_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_18 = s_b_7_15!=s_b_7_16 (const) */
    uint8_t s_b_7_18 = ((uint8_t)(s_b_7_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_19 = s_b_7_17&s_b_7_18 (const) */
    uint8_t s_b_7_19 = ((uint8_t)(s_b_7_17 & s_b_7_18));
    /* execute.a64:548 [F] s_b_7_20: If s_b_7_19: Jump b_8 else b_2 (const) */
    if (s_b_7_19) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:549 [F] s_b_8_0=sym_33639_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2714 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_8_4: If s_b_8_3: Jump b_15 else b_17 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:554 [F] s_b_9_0=sym_33639_3_parameter_inst.op2 (const) */
    /* execute.a64:554 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:554 [F] s_b_9_2 = constant u32 3 (const) */
    /* execute.a64:554 [F] s_b_9_3 = s_b_9_1&s_b_9_2 (const) */
    uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.op2) & (uint32_t)3ULL));
    /* execute.a64:554 [F] s_b_9_4 = constant u32 1 (const) */
    /* execute.a64:554 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(s_b_9_3 == (uint32_t)1ULL));
    /* execute.a64:554 [F] s_b_9_6: If s_b_9_5: Jump b_10 else b_11 (const) */
    if (s_b_9_5) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_9,  */
  fixed_block_b_10: 
  {
    /* execute.a64:555 [F] s_b_10_0=sym_33639_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2714 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_10_4: If s_b_10_3: Jump b_18 else b_20 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:557 [D] s_b_11_0 = mmu_flush_all */
    emitter.call(__captive_mmu_flush_all);
    /* execute.a64:557 [F] s_b_11_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2714 [F] s_b_12_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_12_1: sym_154114_1_temporary_value = s_b_12_0 (const), dominates: s_b_13_0  */
    CV_sym_154114_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_154114_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_12_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_12, b_14,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2714 [D] s_b_13_0 = sym_154114_1_temporary_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_154114_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:545 [F] s_b_13_1 = constant u64 0 (const) */
    /* ???:4294967295 [D] s_b_13_2: Store 8 s_b_13_0 <= s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_13_0, emitter.const_u64((uint64_t)0ULL), emitter.const_u8(8));
    }
    emitter.store_memory(s_b_13_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:544 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2714 [F] s_b_14_0=sym_33639_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_14_2: sym_154114_1_temporary_value = s_b_14_1, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_154114_1_temporary_value, s_b_14_1);
    /* execute.a64:2714 [F] s_b_14_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_8,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2714 [F] s_b_15_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_15_1: sym_154143_1_temporary_value = s_b_15_0 (const), dominates: s_b_16_0  */
    CV_sym_154143_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_154143_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_15_2: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_15, b_17,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2714 [D] s_b_16_0 = sym_154143_1_temporary_value uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_154143_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:549 [D] s_b_16_1 = __builtin_jit_invalidate_txln */
    emitter.call(__captive___builtin_jit_invalidate_txln, s_b_16_0);
    /* execute.a64:549 [F] s_b_16_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2714 [F] s_b_17_0=sym_33639_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_17_1 = ReadRegBank 0:s_b_17_0 (u64) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_17_2: sym_154143_1_temporary_value = s_b_17_1, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_154143_1_temporary_value, s_b_17_1);
    /* execute.a64:2714 [F] s_b_17_3: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_10,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2714 [F] s_b_18_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_18_1: sym_154172_1_temporary_value = s_b_18_0 (const), dominates: s_b_19_0  */
    CV_sym_154172_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_154172_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_18_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_18, b_20,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2714 [D] s_b_19_0 = sym_154172_1_temporary_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_154172_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:555 [D] s_b_19_1 = mmu_flush_va */
    emitter.call(__captive_mmu_flush_va, s_b_19_0);
    /* execute.a64:555 [F] s_b_19_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_10,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2714 [F] s_b_20_0=sym_33639_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_20_2: sym_154172_1_temporary_value = s_b_20_1, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_154172_1_temporary_value, s_b_20_1);
    /* execute.a64:2714 [F] s_b_20_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_uaddw(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5774 [F] s_b_0_0=sym_38755_3_parameter_inst.tb (const) */
    /* execute.simd:5775 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5788 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5801 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5814 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5827 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5840 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5774 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
    switch (insn.tb) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
      break;
    default:
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:5776 [F] s_b_2_0=sym_38755_3_parameter_inst.rn (const) */
    /* execute.simd:5776 [D] s_b_2_1 = ReadRegBank 18:s_b_2_0 (v8u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(16));
    }
    /* execute.simd:5776 [D] s_b_2_2 = (v8u16)s_b_2_1 */
    auto s_b_2_2 = (captive::arch::dbt::el::Value *)s_b_2_1;
    /* execute.simd:5777 [F] s_b_2_3=sym_38755_3_parameter_inst.rm (const) */
    /* execute.simd:5777 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5777 [D] s_b_2_5 = (v8u8)s_b_2_4 */
    auto s_b_2_5 = (captive::arch::dbt::el::Value *)s_b_2_4;
    /* ???:4294967295 [F] s_b_2_6 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5782 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_2_9 = constant u8 0 (const) */
    /* execute.simd:5782 [D] s_b_2_5[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5782 [D] s_b_2_11 = (u16)s_b_2_10 */
    auto s_b_2_11 = emitter.zx(s_b_2_10, emitter.context().types().u16());
    /* execute.simd:5782 [D] s_b_2_12 = s_b_2_8+s_b_2_11 */
    auto s_b_2_12 = emitter.add(s_b_2_8, s_b_2_11);
    /* execute.simd:5782 [F] s_b_2_13 = constant s32 0 (const) */
    /* execute.simd:5782 [D] s_b_2_14 = s_b_2_6[s_b_2_13] <= s_b_2_12 */
    auto s_b_2_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_12);
    /* ???:4294967295 [F] s_b_2_15 = constant u8 1 (const) */
    /* execute.simd:5782 [D] s_b_2_2[s_b_2_15] */
    auto s_b_2_16 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_2_17 = constant u8 1 (const) */
    /* execute.simd:5782 [D] s_b_2_5[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5782 [D] s_b_2_19 = (u16)s_b_2_18 */
    auto s_b_2_19 = emitter.zx(s_b_2_18, emitter.context().types().u16());
    /* execute.simd:5782 [D] s_b_2_20 = s_b_2_16+s_b_2_19 */
    auto s_b_2_20 = emitter.add(s_b_2_16, s_b_2_19);
    /* execute.simd:5782 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:5782 [D] s_b_2_22 = s_b_2_14[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_14, emitter.const_s32((int32_t)1ULL), s_b_2_20);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 2 (const) */
    /* execute.simd:5782 [D] s_b_2_2[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5782 [D] s_b_2_5[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5782 [D] s_b_2_27 = (u16)s_b_2_26 */
    auto s_b_2_27 = emitter.zx(s_b_2_26, emitter.context().types().u16());
    /* execute.simd:5782 [D] s_b_2_28 = s_b_2_24+s_b_2_27 */
    auto s_b_2_28 = emitter.add(s_b_2_24, s_b_2_27);
    /* execute.simd:5782 [F] s_b_2_29 = constant s32 2 (const) */
    /* execute.simd:5782 [D] s_b_2_30 = s_b_2_22[s_b_2_29] <= s_b_2_28 */
    auto s_b_2_30 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)2ULL), s_b_2_28);
    /* ???:4294967295 [F] s_b_2_31 = constant u8 3 (const) */
    /* execute.simd:5782 [D] s_b_2_2[s_b_2_31] */
    auto s_b_2_32 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_2_33 = constant u8 3 (const) */
    /* execute.simd:5782 [D] s_b_2_5[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5782 [D] s_b_2_35 = (u16)s_b_2_34 */
    auto s_b_2_35 = emitter.zx(s_b_2_34, emitter.context().types().u16());
    /* execute.simd:5782 [D] s_b_2_36 = s_b_2_32+s_b_2_35 */
    auto s_b_2_36 = emitter.add(s_b_2_32, s_b_2_35);
    /* execute.simd:5782 [F] s_b_2_37 = constant s32 3 (const) */
    /* execute.simd:5782 [D] s_b_2_38 = s_b_2_30[s_b_2_37] <= s_b_2_36 */
    auto s_b_2_38 = emitter.vector_insert(s_b_2_30, emitter.const_s32((int32_t)3ULL), s_b_2_36);
    /* ???:4294967295 [F] s_b_2_39 = constant u8 4 (const) */
    /* execute.simd:5782 [D] s_b_2_2[s_b_2_39] */
    auto s_b_2_40 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [F] s_b_2_41 = constant u8 4 (const) */
    /* execute.simd:5782 [D] s_b_2_5[s_b_2_41] */
    auto s_b_2_42 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5782 [D] s_b_2_43 = (u16)s_b_2_42 */
    auto s_b_2_43 = emitter.zx(s_b_2_42, emitter.context().types().u16());
    /* execute.simd:5782 [D] s_b_2_44 = s_b_2_40+s_b_2_43 */
    auto s_b_2_44 = emitter.add(s_b_2_40, s_b_2_43);
    /* execute.simd:5782 [F] s_b_2_45 = constant s32 4 (const) */
    /* execute.simd:5782 [D] s_b_2_46 = s_b_2_38[s_b_2_45] <= s_b_2_44 */
    auto s_b_2_46 = emitter.vector_insert(s_b_2_38, emitter.const_s32((int32_t)4ULL), s_b_2_44);
    /* ???:4294967295 [F] s_b_2_47 = constant u8 5 (const) */
    /* execute.simd:5782 [D] s_b_2_2[s_b_2_47] */
    auto s_b_2_48 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [F] s_b_2_49 = constant u8 5 (const) */
    /* execute.simd:5782 [D] s_b_2_5[s_b_2_49] */
    auto s_b_2_50 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5782 [D] s_b_2_51 = (u16)s_b_2_50 */
    auto s_b_2_51 = emitter.zx(s_b_2_50, emitter.context().types().u16());
    /* execute.simd:5782 [D] s_b_2_52 = s_b_2_48+s_b_2_51 */
    auto s_b_2_52 = emitter.add(s_b_2_48, s_b_2_51);
    /* execute.simd:5782 [F] s_b_2_53 = constant s32 5 (const) */
    /* execute.simd:5782 [D] s_b_2_54 = s_b_2_46[s_b_2_53] <= s_b_2_52 */
    auto s_b_2_54 = emitter.vector_insert(s_b_2_46, emitter.const_s32((int32_t)5ULL), s_b_2_52);
    /* ???:4294967295 [F] s_b_2_55 = constant u8 6 (const) */
    /* execute.simd:5782 [D] s_b_2_2[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [F] s_b_2_57 = constant u8 6 (const) */
    /* execute.simd:5782 [D] s_b_2_5[s_b_2_57] */
    auto s_b_2_58 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5782 [D] s_b_2_59 = (u16)s_b_2_58 */
    auto s_b_2_59 = emitter.zx(s_b_2_58, emitter.context().types().u16());
    /* execute.simd:5782 [D] s_b_2_60 = s_b_2_56+s_b_2_59 */
    auto s_b_2_60 = emitter.add(s_b_2_56, s_b_2_59);
    /* execute.simd:5782 [F] s_b_2_61 = constant s32 6 (const) */
    /* execute.simd:5782 [D] s_b_2_62 = s_b_2_54[s_b_2_61] <= s_b_2_60 */
    auto s_b_2_62 = emitter.vector_insert(s_b_2_54, emitter.const_s32((int32_t)6ULL), s_b_2_60);
    /* ???:4294967295 [F] s_b_2_63 = constant u8 7 (const) */
    /* execute.simd:5782 [D] s_b_2_2[s_b_2_63] */
    auto s_b_2_64 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [F] s_b_2_65 = constant u8 7 (const) */
    /* execute.simd:5782 [D] s_b_2_5[s_b_2_65] */
    auto s_b_2_66 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5782 [D] s_b_2_67 = (u16)s_b_2_66 */
    auto s_b_2_67 = emitter.zx(s_b_2_66, emitter.context().types().u16());
    /* execute.simd:5782 [D] s_b_2_68 = s_b_2_64+s_b_2_67 */
    auto s_b_2_68 = emitter.add(s_b_2_64, s_b_2_67);
    /* execute.simd:5782 [F] s_b_2_69 = constant s32 7 (const) */
    /* execute.simd:5782 [D] s_b_2_70 = s_b_2_62[s_b_2_69] <= s_b_2_68 */
    auto s_b_2_70 = emitter.vector_insert(s_b_2_62, emitter.const_s32((int32_t)7ULL), s_b_2_68);
    /* execute.simd:5785 [F] s_b_2_71=sym_38755_3_parameter_inst.rd (const) */
    /* execute.simd:5785 [D] s_b_2_72: WriteRegBank 18:s_b_2_71 = s_b_2_70 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_70,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_70);
    /* execute.simd:0 [F] s_b_2_73: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5789 [F] s_b_3_0=sym_38755_3_parameter_inst.rn (const) */
    /* execute.simd:5789 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5789 [D] s_b_3_2 = (v8u16)s_b_3_1 */
    auto s_b_3_2 = (captive::arch::dbt::el::Value *)s_b_3_1;
    /* execute.simd:5790 [F] s_b_3_3=sym_38755_3_parameter_inst.rm (const) */
    /* execute.simd:5790 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5790 [D] s_b_3_5 = (v16u8)s_b_3_4 */
    auto s_b_3_5 = (captive::arch::dbt::el::Value *)s_b_3_4;
    /* ???:4294967295 [F] s_b_3_6 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_3_7 = constant u8 0 (const) */
    /* execute.simd:5795 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5795 [F] s_b_3_9 = constant u32 8 (const) */
    /* execute.simd:5795 [D] s_b_3_5[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5795 [D] s_b_3_11 = (u16)s_b_3_10 */
    auto s_b_3_11 = emitter.zx(s_b_3_10, emitter.context().types().u16());
    /* execute.simd:5795 [D] s_b_3_12 = s_b_3_8+s_b_3_11 */
    auto s_b_3_12 = emitter.add(s_b_3_8, s_b_3_11);
    /* execute.simd:5795 [F] s_b_3_13 = constant s32 0 (const) */
    /* execute.simd:5795 [D] s_b_3_14 = s_b_3_6[s_b_3_13] <= s_b_3_12 */
    auto s_b_3_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_12);
    /* ???:4294967295 [F] s_b_3_15 = constant u8 1 (const) */
    /* execute.simd:5795 [D] s_b_3_2[s_b_3_15] */
    auto s_b_3_16 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5795 [F] s_b_3_17 = constant u32 9 (const) */
    /* execute.simd:5795 [D] s_b_3_5[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5795 [D] s_b_3_19 = (u16)s_b_3_18 */
    auto s_b_3_19 = emitter.zx(s_b_3_18, emitter.context().types().u16());
    /* execute.simd:5795 [D] s_b_3_20 = s_b_3_16+s_b_3_19 */
    auto s_b_3_20 = emitter.add(s_b_3_16, s_b_3_19);
    /* execute.simd:5795 [F] s_b_3_21 = constant s32 1 (const) */
    /* execute.simd:5795 [D] s_b_3_22 = s_b_3_14[s_b_3_21] <= s_b_3_20 */
    auto s_b_3_22 = emitter.vector_insert(s_b_3_14, emitter.const_s32((int32_t)1ULL), s_b_3_20);
    /* ???:4294967295 [F] s_b_3_23 = constant u8 2 (const) */
    /* execute.simd:5795 [D] s_b_3_2[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5795 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5795 [D] s_b_3_5[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5795 [D] s_b_3_27 = (u16)s_b_3_26 */
    auto s_b_3_27 = emitter.zx(s_b_3_26, emitter.context().types().u16());
    /* execute.simd:5795 [D] s_b_3_28 = s_b_3_24+s_b_3_27 */
    auto s_b_3_28 = emitter.add(s_b_3_24, s_b_3_27);
    /* execute.simd:5795 [F] s_b_3_29 = constant s32 2 (const) */
    /* execute.simd:5795 [D] s_b_3_30 = s_b_3_22[s_b_3_29] <= s_b_3_28 */
    auto s_b_3_30 = emitter.vector_insert(s_b_3_22, emitter.const_s32((int32_t)2ULL), s_b_3_28);
    /* ???:4294967295 [F] s_b_3_31 = constant u8 3 (const) */
    /* execute.simd:5795 [D] s_b_3_2[s_b_3_31] */
    auto s_b_3_32 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5795 [F] s_b_3_33 = constant u32 b (const) */
    /* execute.simd:5795 [D] s_b_3_5[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5795 [D] s_b_3_35 = (u16)s_b_3_34 */
    auto s_b_3_35 = emitter.zx(s_b_3_34, emitter.context().types().u16());
    /* execute.simd:5795 [D] s_b_3_36 = s_b_3_32+s_b_3_35 */
    auto s_b_3_36 = emitter.add(s_b_3_32, s_b_3_35);
    /* execute.simd:5795 [F] s_b_3_37 = constant s32 3 (const) */
    /* execute.simd:5795 [D] s_b_3_38 = s_b_3_30[s_b_3_37] <= s_b_3_36 */
    auto s_b_3_38 = emitter.vector_insert(s_b_3_30, emitter.const_s32((int32_t)3ULL), s_b_3_36);
    /* ???:4294967295 [F] s_b_3_39 = constant u8 4 (const) */
    /* execute.simd:5795 [D] s_b_3_2[s_b_3_39] */
    auto s_b_3_40 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5795 [F] s_b_3_41 = constant u32 c (const) */
    /* execute.simd:5795 [D] s_b_3_5[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5795 [D] s_b_3_43 = (u16)s_b_3_42 */
    auto s_b_3_43 = emitter.zx(s_b_3_42, emitter.context().types().u16());
    /* execute.simd:5795 [D] s_b_3_44 = s_b_3_40+s_b_3_43 */
    auto s_b_3_44 = emitter.add(s_b_3_40, s_b_3_43);
    /* execute.simd:5795 [F] s_b_3_45 = constant s32 4 (const) */
    /* execute.simd:5795 [D] s_b_3_46 = s_b_3_38[s_b_3_45] <= s_b_3_44 */
    auto s_b_3_46 = emitter.vector_insert(s_b_3_38, emitter.const_s32((int32_t)4ULL), s_b_3_44);
    /* ???:4294967295 [F] s_b_3_47 = constant u8 5 (const) */
    /* execute.simd:5795 [D] s_b_3_2[s_b_3_47] */
    auto s_b_3_48 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5795 [F] s_b_3_49 = constant u32 d (const) */
    /* execute.simd:5795 [D] s_b_3_5[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5795 [D] s_b_3_51 = (u16)s_b_3_50 */
    auto s_b_3_51 = emitter.zx(s_b_3_50, emitter.context().types().u16());
    /* execute.simd:5795 [D] s_b_3_52 = s_b_3_48+s_b_3_51 */
    auto s_b_3_52 = emitter.add(s_b_3_48, s_b_3_51);
    /* execute.simd:5795 [F] s_b_3_53 = constant s32 5 (const) */
    /* execute.simd:5795 [D] s_b_3_54 = s_b_3_46[s_b_3_53] <= s_b_3_52 */
    auto s_b_3_54 = emitter.vector_insert(s_b_3_46, emitter.const_s32((int32_t)5ULL), s_b_3_52);
    /* ???:4294967295 [F] s_b_3_55 = constant u8 6 (const) */
    /* execute.simd:5795 [D] s_b_3_2[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5795 [F] s_b_3_57 = constant u32 e (const) */
    /* execute.simd:5795 [D] s_b_3_5[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5795 [D] s_b_3_59 = (u16)s_b_3_58 */
    auto s_b_3_59 = emitter.zx(s_b_3_58, emitter.context().types().u16());
    /* execute.simd:5795 [D] s_b_3_60 = s_b_3_56+s_b_3_59 */
    auto s_b_3_60 = emitter.add(s_b_3_56, s_b_3_59);
    /* execute.simd:5795 [F] s_b_3_61 = constant s32 6 (const) */
    /* execute.simd:5795 [D] s_b_3_62 = s_b_3_54[s_b_3_61] <= s_b_3_60 */
    auto s_b_3_62 = emitter.vector_insert(s_b_3_54, emitter.const_s32((int32_t)6ULL), s_b_3_60);
    /* ???:4294967295 [F] s_b_3_63 = constant u8 7 (const) */
    /* execute.simd:5795 [D] s_b_3_2[s_b_3_63] */
    auto s_b_3_64 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5795 [F] s_b_3_65 = constant u32 f (const) */
    /* execute.simd:5795 [D] s_b_3_5[s_b_3_65] */
    auto s_b_3_66 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5795 [D] s_b_3_67 = (u16)s_b_3_66 */
    auto s_b_3_67 = emitter.zx(s_b_3_66, emitter.context().types().u16());
    /* execute.simd:5795 [D] s_b_3_68 = s_b_3_64+s_b_3_67 */
    auto s_b_3_68 = emitter.add(s_b_3_64, s_b_3_67);
    /* execute.simd:5795 [F] s_b_3_69 = constant s32 7 (const) */
    /* execute.simd:5795 [D] s_b_3_70 = s_b_3_62[s_b_3_69] <= s_b_3_68 */
    auto s_b_3_70 = emitter.vector_insert(s_b_3_62, emitter.const_s32((int32_t)7ULL), s_b_3_68);
    /* execute.simd:5798 [F] s_b_3_71=sym_38755_3_parameter_inst.rd (const) */
    /* execute.simd:5798 [D] s_b_3_72: WriteRegBank 18:s_b_3_71 = s_b_3_70 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_70,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_70);
    /* execute.simd:0 [F] s_b_3_73: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5802 [F] s_b_4_0=sym_38755_3_parameter_inst.rn (const) */
    /* execute.simd:5802 [D] s_b_4_1 = ReadRegBank 20:s_b_4_0 (v4u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:5802 [D] s_b_4_2 = (v4u32)s_b_4_1 */
    auto s_b_4_2 = (captive::arch::dbt::el::Value *)s_b_4_1;
    /* execute.simd:5803 [F] s_b_4_3=sym_38755_3_parameter_inst.rm (const) */
    /* execute.simd:5803 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5803 [D] s_b_4_5 = (v4u16)s_b_4_4 */
    auto s_b_4_5 = (captive::arch::dbt::el::Value *)s_b_4_4;
    /* ???:4294967295 [F] s_b_4_6 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5808 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_9 = constant u8 0 (const) */
    /* execute.simd:5808 [D] s_b_4_5[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5808 [D] s_b_4_11 = (u32)s_b_4_10 */
    auto s_b_4_11 = emitter.zx(s_b_4_10, emitter.context().types().u32());
    /* execute.simd:5808 [D] s_b_4_12 = s_b_4_8+s_b_4_11 */
    auto s_b_4_12 = emitter.add(s_b_4_8, s_b_4_11);
    /* execute.simd:5808 [F] s_b_4_13 = constant s32 0 (const) */
    /* execute.simd:5808 [D] s_b_4_14 = s_b_4_6[s_b_4_13] <= s_b_4_12 */
    auto s_b_4_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_4_12);
    /* ???:4294967295 [F] s_b_4_15 = constant u8 1 (const) */
    /* execute.simd:5808 [D] s_b_4_2[s_b_4_15] */
    auto s_b_4_16 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_4_17 = constant u8 1 (const) */
    /* execute.simd:5808 [D] s_b_4_5[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5808 [D] s_b_4_19 = (u32)s_b_4_18 */
    auto s_b_4_19 = emitter.zx(s_b_4_18, emitter.context().types().u32());
    /* execute.simd:5808 [D] s_b_4_20 = s_b_4_16+s_b_4_19 */
    auto s_b_4_20 = emitter.add(s_b_4_16, s_b_4_19);
    /* execute.simd:5808 [F] s_b_4_21 = constant s32 1 (const) */
    /* execute.simd:5808 [D] s_b_4_22 = s_b_4_14[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_14, emitter.const_s32((int32_t)1ULL), s_b_4_20);
    /* ???:4294967295 [F] s_b_4_23 = constant u8 2 (const) */
    /* execute.simd:5808 [D] s_b_4_2[s_b_4_23] */
    auto s_b_4_24 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5808 [D] s_b_4_5[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5808 [D] s_b_4_27 = (u32)s_b_4_26 */
    auto s_b_4_27 = emitter.zx(s_b_4_26, emitter.context().types().u32());
    /* execute.simd:5808 [D] s_b_4_28 = s_b_4_24+s_b_4_27 */
    auto s_b_4_28 = emitter.add(s_b_4_24, s_b_4_27);
    /* execute.simd:5808 [F] s_b_4_29 = constant s32 2 (const) */
    /* execute.simd:5808 [D] s_b_4_30 = s_b_4_22[s_b_4_29] <= s_b_4_28 */
    auto s_b_4_30 = emitter.vector_insert(s_b_4_22, emitter.const_s32((int32_t)2ULL), s_b_4_28);
    /* ???:4294967295 [F] s_b_4_31 = constant u8 3 (const) */
    /* execute.simd:5808 [D] s_b_4_2[s_b_4_31] */
    auto s_b_4_32 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_4_33 = constant u8 3 (const) */
    /* execute.simd:5808 [D] s_b_4_5[s_b_4_33] */
    auto s_b_4_34 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5808 [D] s_b_4_35 = (u32)s_b_4_34 */
    auto s_b_4_35 = emitter.zx(s_b_4_34, emitter.context().types().u32());
    /* execute.simd:5808 [D] s_b_4_36 = s_b_4_32+s_b_4_35 */
    auto s_b_4_36 = emitter.add(s_b_4_32, s_b_4_35);
    /* execute.simd:5808 [F] s_b_4_37 = constant s32 3 (const) */
    /* execute.simd:5808 [D] s_b_4_38 = s_b_4_30[s_b_4_37] <= s_b_4_36 */
    auto s_b_4_38 = emitter.vector_insert(s_b_4_30, emitter.const_s32((int32_t)3ULL), s_b_4_36);
    /* execute.simd:5811 [F] s_b_4_39=sym_38755_3_parameter_inst.rd (const) */
    /* execute.simd:5811 [D] s_b_4_40: WriteRegBank 20:s_b_4_39 = s_b_4_38 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_38,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_38);
    /* execute.simd:0 [F] s_b_4_41: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5815 [F] s_b_5_0=sym_38755_3_parameter_inst.rn (const) */
    /* execute.simd:5815 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5815 [D] s_b_5_2 = (v4u32)s_b_5_1 */
    auto s_b_5_2 = (captive::arch::dbt::el::Value *)s_b_5_1;
    /* execute.simd:5816 [F] s_b_5_3=sym_38755_3_parameter_inst.rm (const) */
    /* execute.simd:5816 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5816 [D] s_b_5_5 = (v8u16)s_b_5_4 */
    auto s_b_5_5 = (captive::arch::dbt::el::Value *)s_b_5_4;
    /* ???:4294967295 [F] s_b_5_6 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_5_7 = constant u8 0 (const) */
    /* execute.simd:5821 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5821 [F] s_b_5_9 = constant u32 4 (const) */
    /* execute.simd:5821 [D] s_b_5_5[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5821 [D] s_b_5_11 = (u32)s_b_5_10 */
    auto s_b_5_11 = emitter.zx(s_b_5_10, emitter.context().types().u32());
    /* execute.simd:5821 [D] s_b_5_12 = s_b_5_8+s_b_5_11 */
    auto s_b_5_12 = emitter.add(s_b_5_8, s_b_5_11);
    /* execute.simd:5821 [F] s_b_5_13 = constant s32 0 (const) */
    /* execute.simd:5821 [D] s_b_5_14 = s_b_5_6[s_b_5_13] <= s_b_5_12 */
    auto s_b_5_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_5_12);
    /* ???:4294967295 [F] s_b_5_15 = constant u8 1 (const) */
    /* execute.simd:5821 [D] s_b_5_2[s_b_5_15] */
    auto s_b_5_16 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5821 [F] s_b_5_17 = constant u32 5 (const) */
    /* execute.simd:5821 [D] s_b_5_5[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5821 [D] s_b_5_19 = (u32)s_b_5_18 */
    auto s_b_5_19 = emitter.zx(s_b_5_18, emitter.context().types().u32());
    /* execute.simd:5821 [D] s_b_5_20 = s_b_5_16+s_b_5_19 */
    auto s_b_5_20 = emitter.add(s_b_5_16, s_b_5_19);
    /* execute.simd:5821 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5821 [D] s_b_5_22 = s_b_5_14[s_b_5_21] <= s_b_5_20 */
    auto s_b_5_22 = emitter.vector_insert(s_b_5_14, emitter.const_s32((int32_t)1ULL), s_b_5_20);
    /* ???:4294967295 [F] s_b_5_23 = constant u8 2 (const) */
    /* execute.simd:5821 [D] s_b_5_2[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5821 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5821 [D] s_b_5_5[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5821 [D] s_b_5_27 = (u32)s_b_5_26 */
    auto s_b_5_27 = emitter.zx(s_b_5_26, emitter.context().types().u32());
    /* execute.simd:5821 [D] s_b_5_28 = s_b_5_24+s_b_5_27 */
    auto s_b_5_28 = emitter.add(s_b_5_24, s_b_5_27);
    /* execute.simd:5821 [F] s_b_5_29 = constant s32 2 (const) */
    /* execute.simd:5821 [D] s_b_5_30 = s_b_5_22[s_b_5_29] <= s_b_5_28 */
    auto s_b_5_30 = emitter.vector_insert(s_b_5_22, emitter.const_s32((int32_t)2ULL), s_b_5_28);
    /* ???:4294967295 [F] s_b_5_31 = constant u8 3 (const) */
    /* execute.simd:5821 [D] s_b_5_2[s_b_5_31] */
    auto s_b_5_32 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5821 [F] s_b_5_33 = constant u32 7 (const) */
    /* execute.simd:5821 [D] s_b_5_5[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5821 [D] s_b_5_35 = (u32)s_b_5_34 */
    auto s_b_5_35 = emitter.zx(s_b_5_34, emitter.context().types().u32());
    /* execute.simd:5821 [D] s_b_5_36 = s_b_5_32+s_b_5_35 */
    auto s_b_5_36 = emitter.add(s_b_5_32, s_b_5_35);
    /* execute.simd:5821 [F] s_b_5_37 = constant s32 3 (const) */
    /* execute.simd:5821 [D] s_b_5_38 = s_b_5_30[s_b_5_37] <= s_b_5_36 */
    auto s_b_5_38 = emitter.vector_insert(s_b_5_30, emitter.const_s32((int32_t)3ULL), s_b_5_36);
    /* execute.simd:5824 [F] s_b_5_39=sym_38755_3_parameter_inst.rd (const) */
    /* execute.simd:5824 [D] s_b_5_40: WriteRegBank 20:s_b_5_39 = s_b_5_38 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_38,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_38);
    /* execute.simd:0 [F] s_b_5_41: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5828 [F] s_b_6_0=sym_38755_3_parameter_inst.rn (const) */
    /* execute.simd:5828 [D] s_b_6_1 = ReadRegBank 21:s_b_6_0 (v2u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(16));
    }
    /* execute.simd:5828 [D] s_b_6_2 = (v2u64)s_b_6_1 */
    auto s_b_6_2 = (captive::arch::dbt::el::Value *)s_b_6_1;
    /* execute.simd:5829 [F] s_b_6_3=sym_38755_3_parameter_inst.rm (const) */
    /* execute.simd:5829 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5829 [D] s_b_6_5 = (v2u32)s_b_6_4 */
    auto s_b_6_5 = (captive::arch::dbt::el::Value *)s_b_6_4;
    /* ???:4294967295 [F] s_b_6_6 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5834 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_9 = constant u8 0 (const) */
    /* execute.simd:5834 [D] s_b_6_5[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5834 [D] s_b_6_11 = (u64)s_b_6_10 */
    auto s_b_6_11 = emitter.zx(s_b_6_10, emitter.context().types().u64());
    /* execute.simd:5834 [D] s_b_6_12 = s_b_6_8+s_b_6_11 */
    auto s_b_6_12 = emitter.add(s_b_6_8, s_b_6_11);
    /* execute.simd:5834 [F] s_b_6_13 = constant s32 0 (const) */
    /* execute.simd:5834 [D] s_b_6_14 = s_b_6_6[s_b_6_13] <= s_b_6_12 */
    auto s_b_6_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_6_12);
    /* ???:4294967295 [F] s_b_6_15 = constant u8 1 (const) */
    /* execute.simd:5834 [D] s_b_6_2[s_b_6_15] */
    auto s_b_6_16 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_6_17 = constant u8 1 (const) */
    /* execute.simd:5834 [D] s_b_6_5[s_b_6_17] */
    auto s_b_6_18 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5834 [D] s_b_6_19 = (u64)s_b_6_18 */
    auto s_b_6_19 = emitter.zx(s_b_6_18, emitter.context().types().u64());
    /* execute.simd:5834 [D] s_b_6_20 = s_b_6_16+s_b_6_19 */
    auto s_b_6_20 = emitter.add(s_b_6_16, s_b_6_19);
    /* execute.simd:5834 [F] s_b_6_21 = constant s32 1 (const) */
    /* execute.simd:5834 [D] s_b_6_22 = s_b_6_14[s_b_6_21] <= s_b_6_20 */
    auto s_b_6_22 = emitter.vector_insert(s_b_6_14, emitter.const_s32((int32_t)1ULL), s_b_6_20);
    /* execute.simd:5837 [F] s_b_6_23=sym_38755_3_parameter_inst.rd (const) */
    /* execute.simd:5837 [D] s_b_6_24: WriteRegBank 21:s_b_6_23 = s_b_6_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_22,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_22);
    /* execute.simd:0 [F] s_b_6_25: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:5841 [F] s_b_7_0=sym_38755_3_parameter_inst.rn (const) */
    /* execute.simd:5841 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5841 [D] s_b_7_2 = (v2u64)s_b_7_1 */
    auto s_b_7_2 = (captive::arch::dbt::el::Value *)s_b_7_1;
    /* execute.simd:5842 [F] s_b_7_3=sym_38755_3_parameter_inst.rm (const) */
    /* execute.simd:5842 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5842 [D] s_b_7_5 = (v4u32)s_b_7_4 */
    auto s_b_7_5 = (captive::arch::dbt::el::Value *)s_b_7_4;
    /* ???:4294967295 [F] s_b_7_6 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_7_7 = constant u8 0 (const) */
    /* execute.simd:5847 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5847 [F] s_b_7_9 = constant u32 2 (const) */
    /* execute.simd:5847 [D] s_b_7_5[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5847 [D] s_b_7_11 = (u64)s_b_7_10 */
    auto s_b_7_11 = emitter.zx(s_b_7_10, emitter.context().types().u64());
    /* execute.simd:5847 [D] s_b_7_12 = s_b_7_8+s_b_7_11 */
    auto s_b_7_12 = emitter.add(s_b_7_8, s_b_7_11);
    /* execute.simd:5847 [F] s_b_7_13 = constant s32 0 (const) */
    /* execute.simd:5847 [D] s_b_7_14 = s_b_7_6[s_b_7_13] <= s_b_7_12 */
    auto s_b_7_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_7_12);
    /* ???:4294967295 [F] s_b_7_15 = constant u8 1 (const) */
    /* execute.simd:5847 [D] s_b_7_2[s_b_7_15] */
    auto s_b_7_16 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5847 [F] s_b_7_17 = constant u32 3 (const) */
    /* execute.simd:5847 [D] s_b_7_5[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5847 [D] s_b_7_19 = (u64)s_b_7_18 */
    auto s_b_7_19 = emitter.zx(s_b_7_18, emitter.context().types().u64());
    /* execute.simd:5847 [D] s_b_7_20 = s_b_7_16+s_b_7_19 */
    auto s_b_7_20 = emitter.add(s_b_7_16, s_b_7_19);
    /* execute.simd:5847 [F] s_b_7_21 = constant s32 1 (const) */
    /* execute.simd:5847 [D] s_b_7_22 = s_b_7_14[s_b_7_21] <= s_b_7_20 */
    auto s_b_7_22 = emitter.vector_insert(s_b_7_14, emitter.const_s32((int32_t)1ULL), s_b_7_20);
    /* execute.simd:5850 [F] s_b_7_23=sym_38755_3_parameter_inst.rd (const) */
    /* execute.simd:5850 [D] s_b_7_24: WriteRegBank 21:s_b_7_23 = s_b_7_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_22,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_22);
    /* execute.simd:0 [F] s_b_7_25: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:5854 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5774 [F] s_b_8_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_uminv(const arm64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_8 = emitter.context().create_block();
  auto block_b_9 = emitter.context().create_block();
  auto block_b_10 = emitter.context().create_block();
  auto block_b_11 = emitter.context().create_block();
  auto block_b_12 = emitter.context().create_block();
  auto block_b_13 = emitter.context().create_block();
  auto block_b_14 = emitter.context().create_block();
  auto block_b_15 = emitter.context().create_block();
  auto block_b_16 = emitter.context().create_block();
  auto block_b_18 = emitter.context().create_block();
  auto block_b_19 = emitter.context().create_block();
  auto block_b_20 = emitter.context().create_block();
  auto block_b_21 = emitter.context().create_block();
  auto block_b_22 = emitter.context().create_block();
  auto block_b_23 = emitter.context().create_block();
  auto block_b_24 = emitter.context().create_block();
  auto block_b_25 = emitter.context().create_block();
  auto block_b_26 = emitter.context().create_block();
  auto block_b_27 = emitter.context().create_block();
  auto block_b_28 = emitter.context().create_block();
  auto block_b_29 = emitter.context().create_block();
  auto block_b_30 = emitter.context().create_block();
  auto block_b_31 = emitter.context().create_block();
  auto block_b_32 = emitter.context().create_block();
  auto block_b_33 = emitter.context().create_block();
  auto block_b_34 = emitter.context().create_block();
  auto block_b_35 = emitter.context().create_block();
  auto block_b_36 = emitter.context().create_block();
  auto block_b_37 = emitter.context().create_block();
  auto block_b_38 = emitter.context().create_block();
  auto block_b_39 = emitter.context().create_block();
  auto block_b_40 = emitter.context().create_block();
  auto block_b_41 = emitter.context().create_block();
  auto block_b_42 = emitter.context().create_block();
  auto block_b_43 = emitter.context().create_block();
  auto block_b_44 = emitter.context().create_block();
  auto block_b_45 = emitter.context().create_block();
  auto block_b_46 = emitter.context().create_block();
  auto block_b_47 = emitter.context().create_block();
  auto block_b_49 = emitter.context().create_block();
  auto block_b_50 = emitter.context().create_block();
  auto block_b_51 = emitter.context().create_block();
  auto block_b_52 = emitter.context().create_block();
  auto block_b_53 = emitter.context().create_block();
  auto block_b_54 = emitter.context().create_block();
  auto block_b_56 = emitter.context().create_block();
  auto block_b_57 = emitter.context().create_block();
  auto block_b_58 = emitter.context().create_block();
  auto block_b_59 = emitter.context().create_block();
  auto block_b_60 = emitter.context().create_block();
  auto block_b_61 = emitter.context().create_block();
  auto block_b_62 = emitter.context().create_block();
  auto block_b_63 = emitter.context().create_block();
  auto block_b_64 = emitter.context().create_block();
  auto block_b_65 = emitter.context().create_block();
  auto block_b_66 = emitter.context().create_block();
  auto block_b_67 = emitter.context().create_block();
  auto block_b_68 = emitter.context().create_block();
  auto block_b_69 = emitter.context().create_block();
  auto block_b_71 = emitter.context().create_block();
  auto block_b_72 = emitter.context().create_block();
  auto block_b_73 = emitter.context().create_block();
  auto block_b_74 = emitter.context().create_block();
  auto block_b_75 = emitter.context().create_block();
  auto block_b_76 = emitter.context().create_block();
  auto DV_sym_40225_0_rn = emitter.alloc_local(emitter.context().types().v8u8(), true);
  auto DV_sym_40230_0_min = emitter.alloc_local(emitter.context().types().u8(), true);
  auto DV_sym_40362_0_rn = emitter.alloc_local(emitter.context().types().v16u8(), true);
  auto DV_sym_40367_0_min = emitter.alloc_local(emitter.context().types().u8(), true);
  auto DV_sym_40635_0_rn = emitter.alloc_local(emitter.context().types().v4u16(), true);
  auto DV_sym_40640_0_min = emitter.alloc_local(emitter.context().types().u16(), true);
  auto DV_sym_40704_0_rn = emitter.alloc_local(emitter.context().types().v8u16(), true);
  auto DV_sym_40709_0_min = emitter.alloc_local(emitter.context().types().u16(), true);
  auto DV_sym_40841_0_rn = emitter.alloc_local(emitter.context().types().v4u32(), true);
  auto DV_sym_40846_0_min = emitter.alloc_local(emitter.context().types().u32(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:251 [F] s_b_0_0=sym_40217_3_parameter_inst.arrangement (const) */
    /* execute.simd:252 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:265 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:278 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:291 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:304 [F] s_b_0_5 = constant s32 5 (const) */
    /* execute.simd:251 [F] s_b_0_6: Switch s_b_0_0: < <todo> > def b_77 (const) -> b_2, b_17, b_48, b_55, b_70, b_77,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_48;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_55;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_70;
      break;
    default:
      goto fixed_block_b_77;
    }
  }
  // BLOCK b_1 not fully fixed
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:253 [F] s_b_2_0=sym_40217_3_parameter_inst.rn (const) */
    /* execute.simd:253 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:253 [D] s_b_2_2: sym_40225_0_rn = s_b_2_1, dominates: s_b_3_0 s_b_4_0 s_b_5_0 s_b_6_0 s_b_7_0 s_b_8_0 s_b_9_0 s_b_10_0 s_b_11_0 s_b_12_0 s_b_13_0 s_b_14_0 s_b_15_0  */
    emitter.store_local(DV_sym_40225_0_rn, s_b_2_1);
    /* execute.simd:255 [F] s_b_2_3 = constant s32 0 (const) */
    /* execute.simd:255 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:255 [D] s_b_2_5: sym_40230_0_min = s_b_2_4, dominates: s_b_4_3 s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
    emitter.store_local(DV_sym_40230_0_min, s_b_2_4);
    /* ???:4294967295 [F] s_b_2_6 = constant u8 1 (const) */
    /* execute.simd:257 [D] s_b_2_1[s_b_2_6] */
    auto s_b_2_7 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:257 [D] s_b_2_8 = s_b_2_7<s_b_2_4 */
    auto s_b_2_8 = emitter.cmp_lt(s_b_2_7, s_b_2_4);
    /* execute.simd:257 [D] s_b_2_9: If s_b_2_8: Jump b_3 else b_4 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_3;
        dynamic_block_queue.push(block_b_3);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_4;
        dynamic_block_queue.push(block_b_4);
        false_target = block;
      }
      emitter.branch(s_b_2_8, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_3 not fully fixed
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  // BLOCK b_6 not fully fixed
  // BLOCK b_7 not fully fixed
  // BLOCK b_8 not fully fixed
  // BLOCK b_9 not fully fixed
  // BLOCK b_10 not fully fixed
  // BLOCK b_11 not fully fixed
  // BLOCK b_12 not fully fixed
  // BLOCK b_13 not fully fixed
  // BLOCK b_14 not fully fixed
  // BLOCK b_15 not fully fixed
  // BLOCK b_16 not fully fixed
  /* b_0,  */
  fixed_block_b_17: 
  {
    /* execute.simd:266 [F] s_b_17_0=sym_40217_3_parameter_inst.rn (const) */
    /* execute.simd:266 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:266 [D] s_b_17_2: sym_40362_0_rn = s_b_17_1, dominates: s_b_18_0 s_b_19_0 s_b_20_0 s_b_21_0 s_b_22_0 s_b_23_0 s_b_24_0 s_b_25_0 s_b_26_0 s_b_27_0 s_b_28_0 s_b_29_0 s_b_30_0 s_b_31_0 s_b_32_0 s_b_33_0 s_b_34_0 s_b_35_0 s_b_36_0 s_b_37_0 s_b_38_0 s_b_39_0 s_b_40_0 s_b_41_0 s_b_42_0 s_b_43_0 s_b_44_0 s_b_45_0 s_b_46_0  */
    emitter.store_local(DV_sym_40362_0_rn, s_b_17_1);
    /* execute.simd:268 [F] s_b_17_3 = constant s32 0 (const) */
    /* execute.simd:268 [D] s_b_17_1[s_b_17_3] */
    auto s_b_17_4 = emitter.vector_extract(s_b_17_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:268 [D] s_b_17_5: sym_40367_0_min = s_b_17_4, dominates: s_b_19_3 s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
    emitter.store_local(DV_sym_40367_0_min, s_b_17_4);
    /* ???:4294967295 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:270 [D] s_b_17_1[s_b_17_6] */
    auto s_b_17_7 = emitter.vector_extract(s_b_17_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:270 [D] s_b_17_8 = s_b_17_7<s_b_17_4 */
    auto s_b_17_8 = emitter.cmp_lt(s_b_17_7, s_b_17_4);
    /* execute.simd:270 [D] s_b_17_9: If s_b_17_8: Jump b_18 else b_19 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_18;
        dynamic_block_queue.push(block_b_18);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_19;
        dynamic_block_queue.push(block_b_19);
        false_target = block;
      }
      emitter.branch(s_b_17_8, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_18 not fully fixed
  // BLOCK b_19 not fully fixed
  // BLOCK b_20 not fully fixed
  // BLOCK b_21 not fully fixed
  // BLOCK b_22 not fully fixed
  // BLOCK b_23 not fully fixed
  // BLOCK b_24 not fully fixed
  // BLOCK b_25 not fully fixed
  // BLOCK b_26 not fully fixed
  // BLOCK b_27 not fully fixed
  // BLOCK b_28 not fully fixed
  // BLOCK b_29 not fully fixed
  // BLOCK b_30 not fully fixed
  // BLOCK b_31 not fully fixed
  // BLOCK b_32 not fully fixed
  // BLOCK b_33 not fully fixed
  // BLOCK b_34 not fully fixed
  // BLOCK b_35 not fully fixed
  // BLOCK b_36 not fully fixed
  // BLOCK b_37 not fully fixed
  // BLOCK b_38 not fully fixed
  // BLOCK b_39 not fully fixed
  // BLOCK b_40 not fully fixed
  // BLOCK b_41 not fully fixed
  // BLOCK b_42 not fully fixed
  // BLOCK b_43 not fully fixed
  // BLOCK b_44 not fully fixed
  // BLOCK b_45 not fully fixed
  // BLOCK b_46 not fully fixed
  // BLOCK b_47 not fully fixed
  /* b_0,  */
  fixed_block_b_48: 
  {
    /* execute.simd:279 [F] s_b_48_0=sym_40217_3_parameter_inst.rn (const) */
    /* execute.simd:279 [D] s_b_48_1 = ReadRegBank 17:s_b_48_0 (v4u16) */
    auto s_b_48_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_48_1,emitter.const_u8(8));
    }
    /* execute.simd:279 [D] s_b_48_2: sym_40635_0_rn = s_b_48_1, dominates: s_b_49_0 s_b_50_0 s_b_51_0 s_b_52_0 s_b_53_0  */
    emitter.store_local(DV_sym_40635_0_rn, s_b_48_1);
    /* execute.simd:281 [F] s_b_48_3 = constant s32 0 (const) */
    /* execute.simd:281 [D] s_b_48_1[s_b_48_3] */
    auto s_b_48_4 = emitter.vector_extract(s_b_48_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:281 [D] s_b_48_5: sym_40640_0_min = s_b_48_4, dominates: s_b_50_3 s_b_52_3 s_b_54_1  */
    emitter.store_local(DV_sym_40640_0_min, s_b_48_4);
    /* ???:4294967295 [F] s_b_48_6 = constant u8 1 (const) */
    /* execute.simd:283 [D] s_b_48_1[s_b_48_6] */
    auto s_b_48_7 = emitter.vector_extract(s_b_48_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:283 [D] s_b_48_8 = s_b_48_7<s_b_48_4 */
    auto s_b_48_8 = emitter.cmp_lt(s_b_48_7, s_b_48_4);
    /* execute.simd:283 [D] s_b_48_9: If s_b_48_8: Jump b_49 else b_50 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_49;
        dynamic_block_queue.push(block_b_49);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_50;
        dynamic_block_queue.push(block_b_50);
        false_target = block;
      }
      emitter.branch(s_b_48_8, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_49 not fully fixed
  // BLOCK b_50 not fully fixed
  // BLOCK b_51 not fully fixed
  // BLOCK b_52 not fully fixed
  // BLOCK b_53 not fully fixed
  // BLOCK b_54 not fully fixed
  /* b_0,  */
  fixed_block_b_55: 
  {
    /* execute.simd:292 [F] s_b_55_0=sym_40217_3_parameter_inst.rn (const) */
    /* execute.simd:292 [D] s_b_55_1 = ReadRegBank 18:s_b_55_0 (v8u16) */
    auto s_b_55_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_55_1,emitter.const_u8(16));
    }
    /* execute.simd:292 [D] s_b_55_2: sym_40704_0_rn = s_b_55_1, dominates: s_b_56_0 s_b_57_0 s_b_58_0 s_b_59_0 s_b_60_0 s_b_61_0 s_b_62_0 s_b_63_0 s_b_64_0 s_b_65_0 s_b_66_0 s_b_67_0 s_b_68_0  */
    emitter.store_local(DV_sym_40704_0_rn, s_b_55_1);
    /* execute.simd:294 [F] s_b_55_3 = constant s32 0 (const) */
    /* execute.simd:294 [D] s_b_55_1[s_b_55_3] */
    auto s_b_55_4 = emitter.vector_extract(s_b_55_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:294 [D] s_b_55_5: sym_40709_0_min = s_b_55_4, dominates: s_b_57_3 s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
    emitter.store_local(DV_sym_40709_0_min, s_b_55_4);
    /* ???:4294967295 [F] s_b_55_6 = constant u8 1 (const) */
    /* execute.simd:296 [D] s_b_55_1[s_b_55_6] */
    auto s_b_55_7 = emitter.vector_extract(s_b_55_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:296 [D] s_b_55_8 = s_b_55_7<s_b_55_4 */
    auto s_b_55_8 = emitter.cmp_lt(s_b_55_7, s_b_55_4);
    /* execute.simd:296 [D] s_b_55_9: If s_b_55_8: Jump b_56 else b_57 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_56;
        dynamic_block_queue.push(block_b_56);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_57;
        dynamic_block_queue.push(block_b_57);
        false_target = block;
      }
      emitter.branch(s_b_55_8, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_56 not fully fixed
  // BLOCK b_57 not fully fixed
  // BLOCK b_58 not fully fixed
  // BLOCK b_59 not fully fixed
  // BLOCK b_60 not fully fixed
  // BLOCK b_61 not fully fixed
  // BLOCK b_62 not fully fixed
  // BLOCK b_63 not fully fixed
  // BLOCK b_64 not fully fixed
  // BLOCK b_65 not fully fixed
  // BLOCK b_66 not fully fixed
  // BLOCK b_67 not fully fixed
  // BLOCK b_68 not fully fixed
  // BLOCK b_69 not fully fixed
  /* b_0,  */
  fixed_block_b_70: 
  {
    /* execute.simd:305 [F] s_b_70_0=sym_40217_3_parameter_inst.rn (const) */
    /* execute.simd:305 [D] s_b_70_1 = ReadRegBank 20:s_b_70_0 (v4u32) */
    auto s_b_70_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_70_1,emitter.const_u8(16));
    }
    /* execute.simd:305 [D] s_b_70_2: sym_40841_0_rn = s_b_70_1, dominates: s_b_71_0 s_b_72_0 s_b_73_0 s_b_74_0 s_b_75_0  */
    emitter.store_local(DV_sym_40841_0_rn, s_b_70_1);
    /* execute.simd:307 [F] s_b_70_3 = constant s32 0 (const) */
    /* execute.simd:307 [D] s_b_70_1[s_b_70_3] */
    auto s_b_70_4 = emitter.vector_extract(s_b_70_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:307 [D] s_b_70_5: sym_40846_0_min = s_b_70_4, dominates: s_b_72_3 s_b_74_3 s_b_76_1  */
    emitter.store_local(DV_sym_40846_0_min, s_b_70_4);
    /* ???:4294967295 [F] s_b_70_6 = constant u8 1 (const) */
    /* execute.simd:309 [D] s_b_70_1[s_b_70_6] */
    auto s_b_70_7 = emitter.vector_extract(s_b_70_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:309 [D] s_b_70_8 = s_b_70_7<s_b_70_4 */
    auto s_b_70_8 = emitter.cmp_lt(s_b_70_7, s_b_70_4);
    /* execute.simd:309 [D] s_b_70_9: If s_b_70_8: Jump b_71 else b_72 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_71;
        dynamic_block_queue.push(block_b_71);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_72;
        dynamic_block_queue.push(block_b_72);
        false_target = block;
      }
      emitter.branch(s_b_70_8, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_71 not fully fixed
  // BLOCK b_72 not fully fixed
  // BLOCK b_73 not fully fixed
  // BLOCK b_74 not fully fixed
  // BLOCK b_75 not fully fixed
  // BLOCK b_76 not fully fixed
  /* b_0,  */
  fixed_block_b_77: 
  {
    /* execute.simd:318 [D] s_b_77_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_77_1: Jump b_1 (const) */
    {
      auto block = block_b_1;
      dynamic_block_queue.push(block_b_1);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  fixed_done:
  if (dynamic_block_queue.size() > 0) 
  {
    std::set<captive::arch::dbt::el::Block *> emitted_blocks;
    while (dynamic_block_queue.size() > 0) 
    {
      captive::arch::dbt::el::Block *block_index = dynamic_block_queue.front();
      dynamic_block_queue.pop();
      if (emitted_blocks.count(block_index)) continue;
      emitted_blocks.insert(block_index);
      if (block_index == block_b_1) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_1);
        /* ???:4294967295 [F] s_b_1_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_3) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_3);
        /* execute.simd:258 [D] s_b_3_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_3_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_3_1 = constant u8 1 (const) */
        /* execute.simd:258 [D] s_b_3_0[s_b_3_1] */
        auto s_b_3_2 = emitter.vector_extract(s_b_3_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:258 [D] s_b_3_3: sym_40230_0_min = s_b_3_2, dominates: s_b_4_3 s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_40230_0_min, s_b_3_2);
        /* execute.simd:258 [F] s_b_3_4: Jump b_4 (const) */
        {
          auto block = block_b_4;
          dynamic_block_queue.push(block_b_4);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.simd:257 [D] s_b_4_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_4_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_4_1 = constant u8 2 (const) */
        /* execute.simd:257 [D] s_b_4_0[s_b_4_1] */
        auto s_b_4_2 = emitter.vector_extract(s_b_4_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:257 [D] s_b_4_3 = sym_40230_0_min uint8_t */
        auto s_b_4_3 = emitter.load_local(DV_sym_40230_0_min, emitter.context().types().u8());
        /* execute.simd:257 [D] s_b_4_4 = s_b_4_2<s_b_4_3 */
        auto s_b_4_4 = emitter.cmp_lt(s_b_4_2, s_b_4_3);
        /* execute.simd:257 [D] s_b_4_5: If s_b_4_4: Jump b_5 else b_6 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_5;
            dynamic_block_queue.push(block_b_5);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_6;
            dynamic_block_queue.push(block_b_6);
            false_target = block;
          }
          emitter.branch(s_b_4_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:258 [D] s_b_5_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_5_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_5_1 = constant u8 2 (const) */
        /* execute.simd:258 [D] s_b_5_0[s_b_5_1] */
        auto s_b_5_2 = emitter.vector_extract(s_b_5_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:258 [D] s_b_5_3: sym_40230_0_min = s_b_5_2, dominates: s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_40230_0_min, s_b_5_2);
        /* execute.simd:258 [F] s_b_5_4: Jump b_6 (const) */
        {
          auto block = block_b_6;
          dynamic_block_queue.push(block_b_6);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:257 [D] s_b_6_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_6_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_6_1 = constant u8 3 (const) */
        /* execute.simd:257 [D] s_b_6_0[s_b_6_1] */
        auto s_b_6_2 = emitter.vector_extract(s_b_6_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:257 [D] s_b_6_3 = sym_40230_0_min uint8_t */
        auto s_b_6_3 = emitter.load_local(DV_sym_40230_0_min, emitter.context().types().u8());
        /* execute.simd:257 [D] s_b_6_4 = s_b_6_2<s_b_6_3 */
        auto s_b_6_4 = emitter.cmp_lt(s_b_6_2, s_b_6_3);
        /* execute.simd:257 [D] s_b_6_5: If s_b_6_4: Jump b_7 else b_8 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_7;
            dynamic_block_queue.push(block_b_7);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_8;
            dynamic_block_queue.push(block_b_8);
            false_target = block;
          }
          emitter.branch(s_b_6_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.simd:258 [D] s_b_7_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_7_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_7_1 = constant u8 3 (const) */
        /* execute.simd:258 [D] s_b_7_0[s_b_7_1] */
        auto s_b_7_2 = emitter.vector_extract(s_b_7_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:258 [D] s_b_7_3: sym_40230_0_min = s_b_7_2, dominates: s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_40230_0_min, s_b_7_2);
        /* execute.simd:258 [F] s_b_7_4: Jump b_8 (const) */
        {
          auto block = block_b_8;
          dynamic_block_queue.push(block_b_8);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.simd:257 [D] s_b_8_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_8_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_8_1 = constant u8 4 (const) */
        /* execute.simd:257 [D] s_b_8_0[s_b_8_1] */
        auto s_b_8_2 = emitter.vector_extract(s_b_8_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:257 [D] s_b_8_3 = sym_40230_0_min uint8_t */
        auto s_b_8_3 = emitter.load_local(DV_sym_40230_0_min, emitter.context().types().u8());
        /* execute.simd:257 [D] s_b_8_4 = s_b_8_2<s_b_8_3 */
        auto s_b_8_4 = emitter.cmp_lt(s_b_8_2, s_b_8_3);
        /* execute.simd:257 [D] s_b_8_5: If s_b_8_4: Jump b_9 else b_10 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_9;
            dynamic_block_queue.push(block_b_9);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_10;
            dynamic_block_queue.push(block_b_10);
            false_target = block;
          }
          emitter.branch(s_b_8_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.simd:258 [D] s_b_9_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_9_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_9_1 = constant u8 4 (const) */
        /* execute.simd:258 [D] s_b_9_0[s_b_9_1] */
        auto s_b_9_2 = emitter.vector_extract(s_b_9_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:258 [D] s_b_9_3: sym_40230_0_min = s_b_9_2, dominates: s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_40230_0_min, s_b_9_2);
        /* execute.simd:258 [F] s_b_9_4: Jump b_10 (const) */
        {
          auto block = block_b_10;
          dynamic_block_queue.push(block_b_10);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.simd:257 [D] s_b_10_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_10_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_10_1 = constant u8 5 (const) */
        /* execute.simd:257 [D] s_b_10_0[s_b_10_1] */
        auto s_b_10_2 = emitter.vector_extract(s_b_10_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:257 [D] s_b_10_3 = sym_40230_0_min uint8_t */
        auto s_b_10_3 = emitter.load_local(DV_sym_40230_0_min, emitter.context().types().u8());
        /* execute.simd:257 [D] s_b_10_4 = s_b_10_2<s_b_10_3 */
        auto s_b_10_4 = emitter.cmp_lt(s_b_10_2, s_b_10_3);
        /* execute.simd:257 [D] s_b_10_5: If s_b_10_4: Jump b_11 else b_12 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_11;
            dynamic_block_queue.push(block_b_11);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_12;
            dynamic_block_queue.push(block_b_12);
            false_target = block;
          }
          emitter.branch(s_b_10_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* execute.simd:258 [D] s_b_11_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_11_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_11_1 = constant u8 5 (const) */
        /* execute.simd:258 [D] s_b_11_0[s_b_11_1] */
        auto s_b_11_2 = emitter.vector_extract(s_b_11_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:258 [D] s_b_11_3: sym_40230_0_min = s_b_11_2, dominates: s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_40230_0_min, s_b_11_2);
        /* execute.simd:258 [F] s_b_11_4: Jump b_12 (const) */
        {
          auto block = block_b_12;
          dynamic_block_queue.push(block_b_12);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.simd:257 [D] s_b_12_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_12_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_12_1 = constant u8 6 (const) */
        /* execute.simd:257 [D] s_b_12_0[s_b_12_1] */
        auto s_b_12_2 = emitter.vector_extract(s_b_12_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:257 [D] s_b_12_3 = sym_40230_0_min uint8_t */
        auto s_b_12_3 = emitter.load_local(DV_sym_40230_0_min, emitter.context().types().u8());
        /* execute.simd:257 [D] s_b_12_4 = s_b_12_2<s_b_12_3 */
        auto s_b_12_4 = emitter.cmp_lt(s_b_12_2, s_b_12_3);
        /* execute.simd:257 [D] s_b_12_5: If s_b_12_4: Jump b_13 else b_14 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_13;
            dynamic_block_queue.push(block_b_13);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_14;
            dynamic_block_queue.push(block_b_14);
            false_target = block;
          }
          emitter.branch(s_b_12_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.simd:258 [D] s_b_13_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_13_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_13_1 = constant u8 6 (const) */
        /* execute.simd:258 [D] s_b_13_0[s_b_13_1] */
        auto s_b_13_2 = emitter.vector_extract(s_b_13_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:258 [D] s_b_13_3: sym_40230_0_min = s_b_13_2, dominates: s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_40230_0_min, s_b_13_2);
        /* execute.simd:258 [F] s_b_13_4: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.simd:257 [D] s_b_14_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_14_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_14_1 = constant u8 7 (const) */
        /* execute.simd:257 [D] s_b_14_0[s_b_14_1] */
        auto s_b_14_2 = emitter.vector_extract(s_b_14_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:257 [D] s_b_14_3 = sym_40230_0_min uint8_t */
        auto s_b_14_3 = emitter.load_local(DV_sym_40230_0_min, emitter.context().types().u8());
        /* execute.simd:257 [D] s_b_14_4 = s_b_14_2<s_b_14_3 */
        auto s_b_14_4 = emitter.cmp_lt(s_b_14_2, s_b_14_3);
        /* execute.simd:257 [D] s_b_14_5: If s_b_14_4: Jump b_15 else b_16 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_15;
            dynamic_block_queue.push(block_b_15);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_16;
            dynamic_block_queue.push(block_b_16);
            false_target = block;
          }
          emitter.branch(s_b_14_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.simd:258 [D] s_b_15_0 = sym_40225_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_15_0 = emitter.load_local(DV_sym_40225_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_15_1 = constant u8 7 (const) */
        /* execute.simd:258 [D] s_b_15_0[s_b_15_1] */
        auto s_b_15_2 = emitter.vector_extract(s_b_15_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:258 [D] s_b_15_3: sym_40230_0_min = s_b_15_2, dominates: s_b_16_1  */
        emitter.store_local(DV_sym_40230_0_min, s_b_15_2);
        /* execute.simd:258 [F] s_b_15_4: Jump b_16 (const) */
        {
          auto block = block_b_16;
          dynamic_block_queue.push(block_b_16);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.simd:262 [F] s_b_16_0=sym_40217_3_parameter_inst.rd (const) */
        /* execute.simd:262 [D] s_b_16_1 = sym_40230_0_min uint8_t */
        auto s_b_16_1 = emitter.load_local(DV_sym_40230_0_min, emitter.context().types().u8());
        /* execute.simd:6305 [D] s_b_16_2 = (u64)s_b_16_1 */
        auto s_b_16_2 = emitter.zx(s_b_16_1, emitter.context().types().u64());
        /* execute.simd:6305 [D] s_b_16_3: WriteRegBank 2:s_b_16_0 = s_b_16_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_2);
        /* execute.simd:6306 [F] s_b_16_4 = constant u64 0 (const) */
        /* execute.simd:6306 [F] s_b_16_5: WriteRegBank 3:s_b_16_0 = s_b_16_4 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_16_6: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.simd:271 [D] s_b_18_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_18_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_18_1 = constant u8 1 (const) */
        /* execute.simd:271 [D] s_b_18_0[s_b_18_1] */
        auto s_b_18_2 = emitter.vector_extract(s_b_18_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:271 [D] s_b_18_3: sym_40367_0_min = s_b_18_2, dominates: s_b_19_3 s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_18_2);
        /* execute.simd:271 [F] s_b_18_4: Jump b_19 (const) */
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.simd:270 [D] s_b_19_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_19_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_19_1 = constant u8 2 (const) */
        /* execute.simd:270 [D] s_b_19_0[s_b_19_1] */
        auto s_b_19_2 = emitter.vector_extract(s_b_19_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:270 [D] s_b_19_3 = sym_40367_0_min uint8_t */
        auto s_b_19_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_19_4 = s_b_19_2<s_b_19_3 */
        auto s_b_19_4 = emitter.cmp_lt(s_b_19_2, s_b_19_3);
        /* execute.simd:270 [D] s_b_19_5: If s_b_19_4: Jump b_20 else b_21 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_20;
            dynamic_block_queue.push(block_b_20);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_21;
            dynamic_block_queue.push(block_b_21);
            false_target = block;
          }
          emitter.branch(s_b_19_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.simd:271 [D] s_b_20_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_20_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_20_1 = constant u8 2 (const) */
        /* execute.simd:271 [D] s_b_20_0[s_b_20_1] */
        auto s_b_20_2 = emitter.vector_extract(s_b_20_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:271 [D] s_b_20_3: sym_40367_0_min = s_b_20_2, dominates: s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_20_2);
        /* execute.simd:271 [F] s_b_20_4: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.simd:270 [D] s_b_21_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_21_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_21_1 = constant u8 3 (const) */
        /* execute.simd:270 [D] s_b_21_0[s_b_21_1] */
        auto s_b_21_2 = emitter.vector_extract(s_b_21_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:270 [D] s_b_21_3 = sym_40367_0_min uint8_t */
        auto s_b_21_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_21_4 = s_b_21_2<s_b_21_3 */
        auto s_b_21_4 = emitter.cmp_lt(s_b_21_2, s_b_21_3);
        /* execute.simd:270 [D] s_b_21_5: If s_b_21_4: Jump b_22 else b_23 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_22;
            dynamic_block_queue.push(block_b_22);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_23;
            dynamic_block_queue.push(block_b_23);
            false_target = block;
          }
          emitter.branch(s_b_21_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.simd:271 [D] s_b_22_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_22_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_22_1 = constant u8 3 (const) */
        /* execute.simd:271 [D] s_b_22_0[s_b_22_1] */
        auto s_b_22_2 = emitter.vector_extract(s_b_22_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:271 [D] s_b_22_3: sym_40367_0_min = s_b_22_2, dominates: s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_22_2);
        /* execute.simd:271 [F] s_b_22_4: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.simd:270 [D] s_b_23_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_23_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_23_1 = constant u8 4 (const) */
        /* execute.simd:270 [D] s_b_23_0[s_b_23_1] */
        auto s_b_23_2 = emitter.vector_extract(s_b_23_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:270 [D] s_b_23_3 = sym_40367_0_min uint8_t */
        auto s_b_23_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_23_4 = s_b_23_2<s_b_23_3 */
        auto s_b_23_4 = emitter.cmp_lt(s_b_23_2, s_b_23_3);
        /* execute.simd:270 [D] s_b_23_5: If s_b_23_4: Jump b_24 else b_25 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_24;
            dynamic_block_queue.push(block_b_24);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_25;
            dynamic_block_queue.push(block_b_25);
            false_target = block;
          }
          emitter.branch(s_b_23_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.simd:271 [D] s_b_24_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_24_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_24_1 = constant u8 4 (const) */
        /* execute.simd:271 [D] s_b_24_0[s_b_24_1] */
        auto s_b_24_2 = emitter.vector_extract(s_b_24_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:271 [D] s_b_24_3: sym_40367_0_min = s_b_24_2, dominates: s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_24_2);
        /* execute.simd:271 [F] s_b_24_4: Jump b_25 (const) */
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.simd:270 [D] s_b_25_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_25_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_25_1 = constant u8 5 (const) */
        /* execute.simd:270 [D] s_b_25_0[s_b_25_1] */
        auto s_b_25_2 = emitter.vector_extract(s_b_25_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:270 [D] s_b_25_3 = sym_40367_0_min uint8_t */
        auto s_b_25_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_25_4 = s_b_25_2<s_b_25_3 */
        auto s_b_25_4 = emitter.cmp_lt(s_b_25_2, s_b_25_3);
        /* execute.simd:270 [D] s_b_25_5: If s_b_25_4: Jump b_26 else b_27 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_26;
            dynamic_block_queue.push(block_b_26);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_27;
            dynamic_block_queue.push(block_b_27);
            false_target = block;
          }
          emitter.branch(s_b_25_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.simd:271 [D] s_b_26_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_26_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_26_1 = constant u8 5 (const) */
        /* execute.simd:271 [D] s_b_26_0[s_b_26_1] */
        auto s_b_26_2 = emitter.vector_extract(s_b_26_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:271 [D] s_b_26_3: sym_40367_0_min = s_b_26_2, dominates: s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_26_2);
        /* execute.simd:271 [F] s_b_26_4: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.simd:270 [D] s_b_27_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_27_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_27_1 = constant u8 6 (const) */
        /* execute.simd:270 [D] s_b_27_0[s_b_27_1] */
        auto s_b_27_2 = emitter.vector_extract(s_b_27_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:270 [D] s_b_27_3 = sym_40367_0_min uint8_t */
        auto s_b_27_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_27_4 = s_b_27_2<s_b_27_3 */
        auto s_b_27_4 = emitter.cmp_lt(s_b_27_2, s_b_27_3);
        /* execute.simd:270 [D] s_b_27_5: If s_b_27_4: Jump b_28 else b_29 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_28;
            dynamic_block_queue.push(block_b_28);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_29;
            dynamic_block_queue.push(block_b_29);
            false_target = block;
          }
          emitter.branch(s_b_27_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.simd:271 [D] s_b_28_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_28_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_28_1 = constant u8 6 (const) */
        /* execute.simd:271 [D] s_b_28_0[s_b_28_1] */
        auto s_b_28_2 = emitter.vector_extract(s_b_28_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:271 [D] s_b_28_3: sym_40367_0_min = s_b_28_2, dominates: s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_28_2);
        /* execute.simd:271 [F] s_b_28_4: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.simd:270 [D] s_b_29_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_29_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_29_1 = constant u8 7 (const) */
        /* execute.simd:270 [D] s_b_29_0[s_b_29_1] */
        auto s_b_29_2 = emitter.vector_extract(s_b_29_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:270 [D] s_b_29_3 = sym_40367_0_min uint8_t */
        auto s_b_29_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_29_4 = s_b_29_2<s_b_29_3 */
        auto s_b_29_4 = emitter.cmp_lt(s_b_29_2, s_b_29_3);
        /* execute.simd:270 [D] s_b_29_5: If s_b_29_4: Jump b_30 else b_31 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_30;
            dynamic_block_queue.push(block_b_30);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_31;
            dynamic_block_queue.push(block_b_31);
            false_target = block;
          }
          emitter.branch(s_b_29_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.simd:271 [D] s_b_30_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_30_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_30_1 = constant u8 7 (const) */
        /* execute.simd:271 [D] s_b_30_0[s_b_30_1] */
        auto s_b_30_2 = emitter.vector_extract(s_b_30_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:271 [D] s_b_30_3: sym_40367_0_min = s_b_30_2, dominates: s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_30_2);
        /* execute.simd:271 [F] s_b_30_4: Jump b_31 (const) */
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.simd:270 [D] s_b_31_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_31_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_31_1 = constant u8 8 (const) */
        /* execute.simd:270 [D] s_b_31_0[s_b_31_1] */
        auto s_b_31_2 = emitter.vector_extract(s_b_31_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:270 [D] s_b_31_3 = sym_40367_0_min uint8_t */
        auto s_b_31_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_31_4 = s_b_31_2<s_b_31_3 */
        auto s_b_31_4 = emitter.cmp_lt(s_b_31_2, s_b_31_3);
        /* execute.simd:270 [D] s_b_31_5: If s_b_31_4: Jump b_32 else b_33 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_32;
            dynamic_block_queue.push(block_b_32);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_33;
            dynamic_block_queue.push(block_b_33);
            false_target = block;
          }
          emitter.branch(s_b_31_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.simd:271 [D] s_b_32_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_32_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_32_1 = constant u8 8 (const) */
        /* execute.simd:271 [D] s_b_32_0[s_b_32_1] */
        auto s_b_32_2 = emitter.vector_extract(s_b_32_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:271 [D] s_b_32_3: sym_40367_0_min = s_b_32_2, dominates: s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_32_2);
        /* execute.simd:271 [F] s_b_32_4: Jump b_33 (const) */
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.simd:270 [D] s_b_33_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_33_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_33_1 = constant u8 9 (const) */
        /* execute.simd:270 [D] s_b_33_0[s_b_33_1] */
        auto s_b_33_2 = emitter.vector_extract(s_b_33_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:270 [D] s_b_33_3 = sym_40367_0_min uint8_t */
        auto s_b_33_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_33_4 = s_b_33_2<s_b_33_3 */
        auto s_b_33_4 = emitter.cmp_lt(s_b_33_2, s_b_33_3);
        /* execute.simd:270 [D] s_b_33_5: If s_b_33_4: Jump b_34 else b_35 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_34;
            dynamic_block_queue.push(block_b_34);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_35;
            dynamic_block_queue.push(block_b_35);
            false_target = block;
          }
          emitter.branch(s_b_33_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.simd:271 [D] s_b_34_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_34_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_34_1 = constant u8 9 (const) */
        /* execute.simd:271 [D] s_b_34_0[s_b_34_1] */
        auto s_b_34_2 = emitter.vector_extract(s_b_34_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:271 [D] s_b_34_3: sym_40367_0_min = s_b_34_2, dominates: s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_34_2);
        /* execute.simd:271 [F] s_b_34_4: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.simd:270 [D] s_b_35_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_35_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_35_1 = constant u8 a (const) */
        /* execute.simd:270 [D] s_b_35_0[s_b_35_1] */
        auto s_b_35_2 = emitter.vector_extract(s_b_35_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:270 [D] s_b_35_3 = sym_40367_0_min uint8_t */
        auto s_b_35_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_35_4 = s_b_35_2<s_b_35_3 */
        auto s_b_35_4 = emitter.cmp_lt(s_b_35_2, s_b_35_3);
        /* execute.simd:270 [D] s_b_35_5: If s_b_35_4: Jump b_36 else b_37 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_36;
            dynamic_block_queue.push(block_b_36);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_37;
            dynamic_block_queue.push(block_b_37);
            false_target = block;
          }
          emitter.branch(s_b_35_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_36) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_36);
        /* execute.simd:271 [D] s_b_36_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_36_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_36_1 = constant u8 a (const) */
        /* execute.simd:271 [D] s_b_36_0[s_b_36_1] */
        auto s_b_36_2 = emitter.vector_extract(s_b_36_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:271 [D] s_b_36_3: sym_40367_0_min = s_b_36_2, dominates: s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_36_2);
        /* execute.simd:271 [F] s_b_36_4: Jump b_37 (const) */
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.simd:270 [D] s_b_37_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_37_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_37_1 = constant u8 b (const) */
        /* execute.simd:270 [D] s_b_37_0[s_b_37_1] */
        auto s_b_37_2 = emitter.vector_extract(s_b_37_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:270 [D] s_b_37_3 = sym_40367_0_min uint8_t */
        auto s_b_37_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_37_4 = s_b_37_2<s_b_37_3 */
        auto s_b_37_4 = emitter.cmp_lt(s_b_37_2, s_b_37_3);
        /* execute.simd:270 [D] s_b_37_5: If s_b_37_4: Jump b_38 else b_39 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_38;
            dynamic_block_queue.push(block_b_38);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_39;
            dynamic_block_queue.push(block_b_39);
            false_target = block;
          }
          emitter.branch(s_b_37_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_38) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_38);
        /* execute.simd:271 [D] s_b_38_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_38_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_38_1 = constant u8 b (const) */
        /* execute.simd:271 [D] s_b_38_0[s_b_38_1] */
        auto s_b_38_2 = emitter.vector_extract(s_b_38_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:271 [D] s_b_38_3: sym_40367_0_min = s_b_38_2, dominates: s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_38_2);
        /* execute.simd:271 [F] s_b_38_4: Jump b_39 (const) */
        {
          auto block = block_b_39;
          dynamic_block_queue.push(block_b_39);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.simd:270 [D] s_b_39_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_39_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_39_1 = constant u8 c (const) */
        /* execute.simd:270 [D] s_b_39_0[s_b_39_1] */
        auto s_b_39_2 = emitter.vector_extract(s_b_39_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:270 [D] s_b_39_3 = sym_40367_0_min uint8_t */
        auto s_b_39_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_39_4 = s_b_39_2<s_b_39_3 */
        auto s_b_39_4 = emitter.cmp_lt(s_b_39_2, s_b_39_3);
        /* execute.simd:270 [D] s_b_39_5: If s_b_39_4: Jump b_40 else b_41 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_40;
            dynamic_block_queue.push(block_b_40);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_41;
            dynamic_block_queue.push(block_b_41);
            false_target = block;
          }
          emitter.branch(s_b_39_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_40) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_40);
        /* execute.simd:271 [D] s_b_40_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_40_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_40_1 = constant u8 c (const) */
        /* execute.simd:271 [D] s_b_40_0[s_b_40_1] */
        auto s_b_40_2 = emitter.vector_extract(s_b_40_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:271 [D] s_b_40_3: sym_40367_0_min = s_b_40_2, dominates: s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_40_2);
        /* execute.simd:271 [F] s_b_40_4: Jump b_41 (const) */
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.simd:270 [D] s_b_41_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_41_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_41_1 = constant u8 d (const) */
        /* execute.simd:270 [D] s_b_41_0[s_b_41_1] */
        auto s_b_41_2 = emitter.vector_extract(s_b_41_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:270 [D] s_b_41_3 = sym_40367_0_min uint8_t */
        auto s_b_41_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_41_4 = s_b_41_2<s_b_41_3 */
        auto s_b_41_4 = emitter.cmp_lt(s_b_41_2, s_b_41_3);
        /* execute.simd:270 [D] s_b_41_5: If s_b_41_4: Jump b_42 else b_43 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_42;
            dynamic_block_queue.push(block_b_42);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_43;
            dynamic_block_queue.push(block_b_43);
            false_target = block;
          }
          emitter.branch(s_b_41_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_42) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_42);
        /* execute.simd:271 [D] s_b_42_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_42_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_42_1 = constant u8 d (const) */
        /* execute.simd:271 [D] s_b_42_0[s_b_42_1] */
        auto s_b_42_2 = emitter.vector_extract(s_b_42_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:271 [D] s_b_42_3: sym_40367_0_min = s_b_42_2, dominates: s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_42_2);
        /* execute.simd:271 [F] s_b_42_4: Jump b_43 (const) */
        {
          auto block = block_b_43;
          dynamic_block_queue.push(block_b_43);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_43) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_43);
        /* execute.simd:270 [D] s_b_43_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_43_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_43_1 = constant u8 e (const) */
        /* execute.simd:270 [D] s_b_43_0[s_b_43_1] */
        auto s_b_43_2 = emitter.vector_extract(s_b_43_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:270 [D] s_b_43_3 = sym_40367_0_min uint8_t */
        auto s_b_43_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_43_4 = s_b_43_2<s_b_43_3 */
        auto s_b_43_4 = emitter.cmp_lt(s_b_43_2, s_b_43_3);
        /* execute.simd:270 [D] s_b_43_5: If s_b_43_4: Jump b_44 else b_45 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_44;
            dynamic_block_queue.push(block_b_44);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_45;
            dynamic_block_queue.push(block_b_45);
            false_target = block;
          }
          emitter.branch(s_b_43_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_44) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_44);
        /* execute.simd:271 [D] s_b_44_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_44_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_44_1 = constant u8 e (const) */
        /* execute.simd:271 [D] s_b_44_0[s_b_44_1] */
        auto s_b_44_2 = emitter.vector_extract(s_b_44_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:271 [D] s_b_44_3: sym_40367_0_min = s_b_44_2, dominates: s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_44_2);
        /* execute.simd:271 [F] s_b_44_4: Jump b_45 (const) */
        {
          auto block = block_b_45;
          dynamic_block_queue.push(block_b_45);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_45) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_45);
        /* execute.simd:270 [D] s_b_45_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_45_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_45_1 = constant u8 f (const) */
        /* execute.simd:270 [D] s_b_45_0[s_b_45_1] */
        auto s_b_45_2 = emitter.vector_extract(s_b_45_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:270 [D] s_b_45_3 = sym_40367_0_min uint8_t */
        auto s_b_45_3 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:270 [D] s_b_45_4 = s_b_45_2<s_b_45_3 */
        auto s_b_45_4 = emitter.cmp_lt(s_b_45_2, s_b_45_3);
        /* execute.simd:270 [D] s_b_45_5: If s_b_45_4: Jump b_46 else b_47 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_46;
            dynamic_block_queue.push(block_b_46);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_47;
            dynamic_block_queue.push(block_b_47);
            false_target = block;
          }
          emitter.branch(s_b_45_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_46) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_46);
        /* execute.simd:271 [D] s_b_46_0 = sym_40362_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_46_0 = emitter.load_local(DV_sym_40362_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_46_1 = constant u8 f (const) */
        /* execute.simd:271 [D] s_b_46_0[s_b_46_1] */
        auto s_b_46_2 = emitter.vector_extract(s_b_46_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:271 [D] s_b_46_3: sym_40367_0_min = s_b_46_2, dominates: s_b_47_1  */
        emitter.store_local(DV_sym_40367_0_min, s_b_46_2);
        /* execute.simd:271 [F] s_b_46_4: Jump b_47 (const) */
        {
          auto block = block_b_47;
          dynamic_block_queue.push(block_b_47);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_47) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_47);
        /* execute.simd:275 [F] s_b_47_0=sym_40217_3_parameter_inst.rd (const) */
        /* execute.simd:275 [D] s_b_47_1 = sym_40367_0_min uint8_t */
        auto s_b_47_1 = emitter.load_local(DV_sym_40367_0_min, emitter.context().types().u8());
        /* execute.simd:6305 [D] s_b_47_2 = (u64)s_b_47_1 */
        auto s_b_47_2 = emitter.zx(s_b_47_1, emitter.context().types().u64());
        /* execute.simd:6305 [D] s_b_47_3: WriteRegBank 2:s_b_47_0 = s_b_47_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_47_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_47_2);
        /* execute.simd:6306 [F] s_b_47_4 = constant u64 0 (const) */
        /* execute.simd:6306 [F] s_b_47_5: WriteRegBank 3:s_b_47_0 = s_b_47_4 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_47_6: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_49) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_49);
        /* execute.simd:284 [D] s_b_49_0 = sym_40635_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_49_0 = emitter.load_local(DV_sym_40635_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_49_1 = constant u8 1 (const) */
        /* execute.simd:284 [D] s_b_49_0[s_b_49_1] */
        auto s_b_49_2 = emitter.vector_extract(s_b_49_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:284 [D] s_b_49_3: sym_40640_0_min = s_b_49_2, dominates: s_b_50_3 s_b_52_3 s_b_54_1  */
        emitter.store_local(DV_sym_40640_0_min, s_b_49_2);
        /* execute.simd:284 [F] s_b_49_4: Jump b_50 (const) */
        {
          auto block = block_b_50;
          dynamic_block_queue.push(block_b_50);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_50) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_50);
        /* execute.simd:283 [D] s_b_50_0 = sym_40635_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_50_0 = emitter.load_local(DV_sym_40635_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_50_1 = constant u8 2 (const) */
        /* execute.simd:283 [D] s_b_50_0[s_b_50_1] */
        auto s_b_50_2 = emitter.vector_extract(s_b_50_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:283 [D] s_b_50_3 = sym_40640_0_min uint16_t */
        auto s_b_50_3 = emitter.load_local(DV_sym_40640_0_min, emitter.context().types().u16());
        /* execute.simd:283 [D] s_b_50_4 = s_b_50_2<s_b_50_3 */
        auto s_b_50_4 = emitter.cmp_lt(s_b_50_2, s_b_50_3);
        /* execute.simd:283 [D] s_b_50_5: If s_b_50_4: Jump b_51 else b_52 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_51;
            dynamic_block_queue.push(block_b_51);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_52;
            dynamic_block_queue.push(block_b_52);
            false_target = block;
          }
          emitter.branch(s_b_50_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_51) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_51);
        /* execute.simd:284 [D] s_b_51_0 = sym_40635_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_51_0 = emitter.load_local(DV_sym_40635_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_51_1 = constant u8 2 (const) */
        /* execute.simd:284 [D] s_b_51_0[s_b_51_1] */
        auto s_b_51_2 = emitter.vector_extract(s_b_51_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:284 [D] s_b_51_3: sym_40640_0_min = s_b_51_2, dominates: s_b_52_3 s_b_54_1  */
        emitter.store_local(DV_sym_40640_0_min, s_b_51_2);
        /* execute.simd:284 [F] s_b_51_4: Jump b_52 (const) */
        {
          auto block = block_b_52;
          dynamic_block_queue.push(block_b_52);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_52) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_52);
        /* execute.simd:283 [D] s_b_52_0 = sym_40635_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_52_0 = emitter.load_local(DV_sym_40635_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_52_1 = constant u8 3 (const) */
        /* execute.simd:283 [D] s_b_52_0[s_b_52_1] */
        auto s_b_52_2 = emitter.vector_extract(s_b_52_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:283 [D] s_b_52_3 = sym_40640_0_min uint16_t */
        auto s_b_52_3 = emitter.load_local(DV_sym_40640_0_min, emitter.context().types().u16());
        /* execute.simd:283 [D] s_b_52_4 = s_b_52_2<s_b_52_3 */
        auto s_b_52_4 = emitter.cmp_lt(s_b_52_2, s_b_52_3);
        /* execute.simd:283 [D] s_b_52_5: If s_b_52_4: Jump b_53 else b_54 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_53;
            dynamic_block_queue.push(block_b_53);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_54;
            dynamic_block_queue.push(block_b_54);
            false_target = block;
          }
          emitter.branch(s_b_52_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_53) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_53);
        /* execute.simd:284 [D] s_b_53_0 = sym_40635_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_53_0 = emitter.load_local(DV_sym_40635_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_53_1 = constant u8 3 (const) */
        /* execute.simd:284 [D] s_b_53_0[s_b_53_1] */
        auto s_b_53_2 = emitter.vector_extract(s_b_53_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:284 [D] s_b_53_3: sym_40640_0_min = s_b_53_2, dominates: s_b_54_1  */
        emitter.store_local(DV_sym_40640_0_min, s_b_53_2);
        /* execute.simd:284 [F] s_b_53_4: Jump b_54 (const) */
        {
          auto block = block_b_54;
          dynamic_block_queue.push(block_b_54);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_54) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_54);
        /* execute.simd:288 [F] s_b_54_0=sym_40217_3_parameter_inst.rd (const) */
        /* execute.simd:288 [D] s_b_54_1 = sym_40640_0_min uint16_t */
        auto s_b_54_1 = emitter.load_local(DV_sym_40640_0_min, emitter.context().types().u16());
        /* execute.simd:6312 [D] s_b_54_2 = (u64)s_b_54_1 */
        auto s_b_54_2 = emitter.zx(s_b_54_1, emitter.context().types().u64());
        /* execute.simd:6312 [D] s_b_54_3: WriteRegBank 2:s_b_54_0 = s_b_54_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_54_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_54_2);
        /* execute.simd:6313 [F] s_b_54_4 = constant u64 0 (const) */
        /* execute.simd:6313 [F] s_b_54_5: WriteRegBank 3:s_b_54_0 = s_b_54_4 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_54_6: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_56) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_56);
        /* execute.simd:297 [D] s_b_56_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_56_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_56_1 = constant u8 1 (const) */
        /* execute.simd:297 [D] s_b_56_0[s_b_56_1] */
        auto s_b_56_2 = emitter.vector_extract(s_b_56_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:297 [D] s_b_56_3: sym_40709_0_min = s_b_56_2, dominates: s_b_57_3 s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40709_0_min, s_b_56_2);
        /* execute.simd:297 [F] s_b_56_4: Jump b_57 (const) */
        {
          auto block = block_b_57;
          dynamic_block_queue.push(block_b_57);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_57) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_57);
        /* execute.simd:296 [D] s_b_57_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_57_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_57_1 = constant u8 2 (const) */
        /* execute.simd:296 [D] s_b_57_0[s_b_57_1] */
        auto s_b_57_2 = emitter.vector_extract(s_b_57_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:296 [D] s_b_57_3 = sym_40709_0_min uint16_t */
        auto s_b_57_3 = emitter.load_local(DV_sym_40709_0_min, emitter.context().types().u16());
        /* execute.simd:296 [D] s_b_57_4 = s_b_57_2<s_b_57_3 */
        auto s_b_57_4 = emitter.cmp_lt(s_b_57_2, s_b_57_3);
        /* execute.simd:296 [D] s_b_57_5: If s_b_57_4: Jump b_58 else b_59 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_58;
            dynamic_block_queue.push(block_b_58);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_59;
            dynamic_block_queue.push(block_b_59);
            false_target = block;
          }
          emitter.branch(s_b_57_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_58) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_58);
        /* execute.simd:297 [D] s_b_58_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_58_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_58_1 = constant u8 2 (const) */
        /* execute.simd:297 [D] s_b_58_0[s_b_58_1] */
        auto s_b_58_2 = emitter.vector_extract(s_b_58_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:297 [D] s_b_58_3: sym_40709_0_min = s_b_58_2, dominates: s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40709_0_min, s_b_58_2);
        /* execute.simd:297 [F] s_b_58_4: Jump b_59 (const) */
        {
          auto block = block_b_59;
          dynamic_block_queue.push(block_b_59);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_59) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_59);
        /* execute.simd:296 [D] s_b_59_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_59_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_59_1 = constant u8 3 (const) */
        /* execute.simd:296 [D] s_b_59_0[s_b_59_1] */
        auto s_b_59_2 = emitter.vector_extract(s_b_59_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:296 [D] s_b_59_3 = sym_40709_0_min uint16_t */
        auto s_b_59_3 = emitter.load_local(DV_sym_40709_0_min, emitter.context().types().u16());
        /* execute.simd:296 [D] s_b_59_4 = s_b_59_2<s_b_59_3 */
        auto s_b_59_4 = emitter.cmp_lt(s_b_59_2, s_b_59_3);
        /* execute.simd:296 [D] s_b_59_5: If s_b_59_4: Jump b_60 else b_61 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_60;
            dynamic_block_queue.push(block_b_60);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_61;
            dynamic_block_queue.push(block_b_61);
            false_target = block;
          }
          emitter.branch(s_b_59_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_60) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_60);
        /* execute.simd:297 [D] s_b_60_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_60_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_60_1 = constant u8 3 (const) */
        /* execute.simd:297 [D] s_b_60_0[s_b_60_1] */
        auto s_b_60_2 = emitter.vector_extract(s_b_60_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:297 [D] s_b_60_3: sym_40709_0_min = s_b_60_2, dominates: s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40709_0_min, s_b_60_2);
        /* execute.simd:297 [F] s_b_60_4: Jump b_61 (const) */
        {
          auto block = block_b_61;
          dynamic_block_queue.push(block_b_61);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_61) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_61);
        /* execute.simd:296 [D] s_b_61_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_61_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_61_1 = constant u8 4 (const) */
        /* execute.simd:296 [D] s_b_61_0[s_b_61_1] */
        auto s_b_61_2 = emitter.vector_extract(s_b_61_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:296 [D] s_b_61_3 = sym_40709_0_min uint16_t */
        auto s_b_61_3 = emitter.load_local(DV_sym_40709_0_min, emitter.context().types().u16());
        /* execute.simd:296 [D] s_b_61_4 = s_b_61_2<s_b_61_3 */
        auto s_b_61_4 = emitter.cmp_lt(s_b_61_2, s_b_61_3);
        /* execute.simd:296 [D] s_b_61_5: If s_b_61_4: Jump b_62 else b_63 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_62;
            dynamic_block_queue.push(block_b_62);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_63;
            dynamic_block_queue.push(block_b_63);
            false_target = block;
          }
          emitter.branch(s_b_61_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_62) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_62);
        /* execute.simd:297 [D] s_b_62_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_62_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_62_1 = constant u8 4 (const) */
        /* execute.simd:297 [D] s_b_62_0[s_b_62_1] */
        auto s_b_62_2 = emitter.vector_extract(s_b_62_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:297 [D] s_b_62_3: sym_40709_0_min = s_b_62_2, dominates: s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40709_0_min, s_b_62_2);
        /* execute.simd:297 [F] s_b_62_4: Jump b_63 (const) */
        {
          auto block = block_b_63;
          dynamic_block_queue.push(block_b_63);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_63) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_63);
        /* execute.simd:296 [D] s_b_63_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_63_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_63_1 = constant u8 5 (const) */
        /* execute.simd:296 [D] s_b_63_0[s_b_63_1] */
        auto s_b_63_2 = emitter.vector_extract(s_b_63_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:296 [D] s_b_63_3 = sym_40709_0_min uint16_t */
        auto s_b_63_3 = emitter.load_local(DV_sym_40709_0_min, emitter.context().types().u16());
        /* execute.simd:296 [D] s_b_63_4 = s_b_63_2<s_b_63_3 */
        auto s_b_63_4 = emitter.cmp_lt(s_b_63_2, s_b_63_3);
        /* execute.simd:296 [D] s_b_63_5: If s_b_63_4: Jump b_64 else b_65 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_64;
            dynamic_block_queue.push(block_b_64);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_65;
            dynamic_block_queue.push(block_b_65);
            false_target = block;
          }
          emitter.branch(s_b_63_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_64) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_64);
        /* execute.simd:297 [D] s_b_64_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_64_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_64_1 = constant u8 5 (const) */
        /* execute.simd:297 [D] s_b_64_0[s_b_64_1] */
        auto s_b_64_2 = emitter.vector_extract(s_b_64_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:297 [D] s_b_64_3: sym_40709_0_min = s_b_64_2, dominates: s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40709_0_min, s_b_64_2);
        /* execute.simd:297 [F] s_b_64_4: Jump b_65 (const) */
        {
          auto block = block_b_65;
          dynamic_block_queue.push(block_b_65);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_65) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_65);
        /* execute.simd:296 [D] s_b_65_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_65_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_65_1 = constant u8 6 (const) */
        /* execute.simd:296 [D] s_b_65_0[s_b_65_1] */
        auto s_b_65_2 = emitter.vector_extract(s_b_65_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:296 [D] s_b_65_3 = sym_40709_0_min uint16_t */
        auto s_b_65_3 = emitter.load_local(DV_sym_40709_0_min, emitter.context().types().u16());
        /* execute.simd:296 [D] s_b_65_4 = s_b_65_2<s_b_65_3 */
        auto s_b_65_4 = emitter.cmp_lt(s_b_65_2, s_b_65_3);
        /* execute.simd:296 [D] s_b_65_5: If s_b_65_4: Jump b_66 else b_67 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_66;
            dynamic_block_queue.push(block_b_66);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_67;
            dynamic_block_queue.push(block_b_67);
            false_target = block;
          }
          emitter.branch(s_b_65_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_66) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_66);
        /* execute.simd:297 [D] s_b_66_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_66_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_66_1 = constant u8 6 (const) */
        /* execute.simd:297 [D] s_b_66_0[s_b_66_1] */
        auto s_b_66_2 = emitter.vector_extract(s_b_66_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:297 [D] s_b_66_3: sym_40709_0_min = s_b_66_2, dominates: s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40709_0_min, s_b_66_2);
        /* execute.simd:297 [F] s_b_66_4: Jump b_67 (const) */
        {
          auto block = block_b_67;
          dynamic_block_queue.push(block_b_67);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_67) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_67);
        /* execute.simd:296 [D] s_b_67_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_67_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_67_1 = constant u8 7 (const) */
        /* execute.simd:296 [D] s_b_67_0[s_b_67_1] */
        auto s_b_67_2 = emitter.vector_extract(s_b_67_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:296 [D] s_b_67_3 = sym_40709_0_min uint16_t */
        auto s_b_67_3 = emitter.load_local(DV_sym_40709_0_min, emitter.context().types().u16());
        /* execute.simd:296 [D] s_b_67_4 = s_b_67_2<s_b_67_3 */
        auto s_b_67_4 = emitter.cmp_lt(s_b_67_2, s_b_67_3);
        /* execute.simd:296 [D] s_b_67_5: If s_b_67_4: Jump b_68 else b_69 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_68;
            dynamic_block_queue.push(block_b_68);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_69;
            dynamic_block_queue.push(block_b_69);
            false_target = block;
          }
          emitter.branch(s_b_67_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_68) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_68);
        /* execute.simd:297 [D] s_b_68_0 = sym_40704_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_68_0 = emitter.load_local(DV_sym_40704_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_68_1 = constant u8 7 (const) */
        /* execute.simd:297 [D] s_b_68_0[s_b_68_1] */
        auto s_b_68_2 = emitter.vector_extract(s_b_68_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:297 [D] s_b_68_3: sym_40709_0_min = s_b_68_2, dominates: s_b_69_1  */
        emitter.store_local(DV_sym_40709_0_min, s_b_68_2);
        /* execute.simd:297 [F] s_b_68_4: Jump b_69 (const) */
        {
          auto block = block_b_69;
          dynamic_block_queue.push(block_b_69);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_69) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_69);
        /* execute.simd:301 [F] s_b_69_0=sym_40217_3_parameter_inst.rd (const) */
        /* execute.simd:301 [D] s_b_69_1 = sym_40709_0_min uint16_t */
        auto s_b_69_1 = emitter.load_local(DV_sym_40709_0_min, emitter.context().types().u16());
        /* execute.simd:6312 [D] s_b_69_2 = (u64)s_b_69_1 */
        auto s_b_69_2 = emitter.zx(s_b_69_1, emitter.context().types().u64());
        /* execute.simd:6312 [D] s_b_69_3: WriteRegBank 2:s_b_69_0 = s_b_69_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_69_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_69_2);
        /* execute.simd:6313 [F] s_b_69_4 = constant u64 0 (const) */
        /* execute.simd:6313 [F] s_b_69_5: WriteRegBank 3:s_b_69_0 = s_b_69_4 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_69_6: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_71) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_71);
        /* execute.simd:310 [D] s_b_71_0 = sym_40841_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_71_0 = emitter.load_local(DV_sym_40841_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_71_1 = constant u8 1 (const) */
        /* execute.simd:310 [D] s_b_71_0[s_b_71_1] */
        auto s_b_71_2 = emitter.vector_extract(s_b_71_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:310 [D] s_b_71_3: sym_40846_0_min = s_b_71_2, dominates: s_b_72_3 s_b_74_3 s_b_76_1  */
        emitter.store_local(DV_sym_40846_0_min, s_b_71_2);
        /* execute.simd:310 [F] s_b_71_4: Jump b_72 (const) */
        {
          auto block = block_b_72;
          dynamic_block_queue.push(block_b_72);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_72) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_72);
        /* execute.simd:309 [D] s_b_72_0 = sym_40841_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_72_0 = emitter.load_local(DV_sym_40841_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_72_1 = constant u8 2 (const) */
        /* execute.simd:309 [D] s_b_72_0[s_b_72_1] */
        auto s_b_72_2 = emitter.vector_extract(s_b_72_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:309 [D] s_b_72_3 = sym_40846_0_min uint32_t */
        auto s_b_72_3 = emitter.load_local(DV_sym_40846_0_min, emitter.context().types().u32());
        /* execute.simd:309 [D] s_b_72_4 = s_b_72_2<s_b_72_3 */
        auto s_b_72_4 = emitter.cmp_lt(s_b_72_2, s_b_72_3);
        /* execute.simd:309 [D] s_b_72_5: If s_b_72_4: Jump b_73 else b_74 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_73;
            dynamic_block_queue.push(block_b_73);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_74;
            dynamic_block_queue.push(block_b_74);
            false_target = block;
          }
          emitter.branch(s_b_72_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_73) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_73);
        /* execute.simd:310 [D] s_b_73_0 = sym_40841_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_73_0 = emitter.load_local(DV_sym_40841_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_73_1 = constant u8 2 (const) */
        /* execute.simd:310 [D] s_b_73_0[s_b_73_1] */
        auto s_b_73_2 = emitter.vector_extract(s_b_73_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:310 [D] s_b_73_3: sym_40846_0_min = s_b_73_2, dominates: s_b_74_3 s_b_76_1  */
        emitter.store_local(DV_sym_40846_0_min, s_b_73_2);
        /* execute.simd:310 [F] s_b_73_4: Jump b_74 (const) */
        {
          auto block = block_b_74;
          dynamic_block_queue.push(block_b_74);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_74) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_74);
        /* execute.simd:309 [D] s_b_74_0 = sym_40841_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_74_0 = emitter.load_local(DV_sym_40841_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_74_1 = constant u8 3 (const) */
        /* execute.simd:309 [D] s_b_74_0[s_b_74_1] */
        auto s_b_74_2 = emitter.vector_extract(s_b_74_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:309 [D] s_b_74_3 = sym_40846_0_min uint32_t */
        auto s_b_74_3 = emitter.load_local(DV_sym_40846_0_min, emitter.context().types().u32());
        /* execute.simd:309 [D] s_b_74_4 = s_b_74_2<s_b_74_3 */
        auto s_b_74_4 = emitter.cmp_lt(s_b_74_2, s_b_74_3);
        /* execute.simd:309 [D] s_b_74_5: If s_b_74_4: Jump b_75 else b_76 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_75;
            dynamic_block_queue.push(block_b_75);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_76;
            dynamic_block_queue.push(block_b_76);
            false_target = block;
          }
          emitter.branch(s_b_74_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_75) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_75);
        /* execute.simd:310 [D] s_b_75_0 = sym_40841_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_75_0 = emitter.load_local(DV_sym_40841_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_75_1 = constant u8 3 (const) */
        /* execute.simd:310 [D] s_b_75_0[s_b_75_1] */
        auto s_b_75_2 = emitter.vector_extract(s_b_75_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:310 [D] s_b_75_3: sym_40846_0_min = s_b_75_2, dominates: s_b_76_1  */
        emitter.store_local(DV_sym_40846_0_min, s_b_75_2);
        /* execute.simd:310 [F] s_b_75_4: Jump b_76 (const) */
        {
          auto block = block_b_76;
          dynamic_block_queue.push(block_b_76);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_76) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_76);
        /* execute.simd:314 [F] s_b_76_0=sym_40217_3_parameter_inst.rd (const) */
        /* execute.simd:314 [D] s_b_76_1 = sym_40846_0_min uint32_t */
        auto s_b_76_1 = emitter.load_local(DV_sym_40846_0_min, emitter.context().types().u32());
        /* execute.simd:6319 [D] s_b_76_2 = (u64)s_b_76_1 */
        auto s_b_76_2 = emitter.zx(s_b_76_1, emitter.context().types().u64());
        /* execute.simd:6319 [D] s_b_76_3: WriteRegBank 2:s_b_76_0 = s_b_76_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_76_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_76_2);
        /* execute.simd:6320 [F] s_b_76_4 = constant u64 0 (const) */
        /* execute.simd:6320 [F] s_b_76_5: WriteRegBank 3:s_b_76_0 = s_b_76_4 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_76_6: Jump b_1 (const) */
        {
          auto block = block_b_1;
          dynamic_block_queue.push(block_b_1);
          emitter.jump(block);
        }
      }
    }
  }
  else 
  {
    emitter.jump(__exit_block);
  }
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_usubl(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5942 [F] s_b_0_0=sym_45118_3_parameter_inst.tb (const) */
    /* execute.simd:5943 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5955 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5967 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5979 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5991 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:6003 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5942 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
    switch (insn.tb) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
      break;
    default:
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:5944 [F] s_b_2_0=sym_45118_3_parameter_inst.rn (const) */
    /* execute.simd:5944 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5944 [D] s_b_2_2 = (v8u8)s_b_2_1 */
    auto s_b_2_2 = (captive::arch::dbt::el::Value *)s_b_2_1;
    /* execute.simd:5945 [F] s_b_2_3=sym_45118_3_parameter_inst.rm (const) */
    /* execute.simd:5945 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5945 [D] s_b_2_5 = (v8u8)s_b_2_4 */
    auto s_b_2_5 = (captive::arch::dbt::el::Value *)s_b_2_4;
    /* ???:4294967295 [F] s_b_2_6 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5949 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5949 [D] s_b_2_9 = (u16)s_b_2_8 */
    auto s_b_2_9 = emitter.zx(s_b_2_8, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5949 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5949 [D] s_b_2_12 = (u16)s_b_2_11 */
    auto s_b_2_12 = emitter.zx(s_b_2_11, emitter.context().types().u16());
    /* execute.simd:5949 [D] s_b_2_13 = s_b_2_9-s_b_2_12 */
    auto s_b_2_13 = emitter.sub(s_b_2_9, s_b_2_12);
    /* execute.simd:5949 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5949 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5949 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5949 [D] s_b_2_18 = (u16)s_b_2_17 */
    auto s_b_2_18 = emitter.zx(s_b_2_17, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5949 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5949 [D] s_b_2_21 = (u16)s_b_2_20 */
    auto s_b_2_21 = emitter.zx(s_b_2_20, emitter.context().types().u16());
    /* execute.simd:5949 [D] s_b_2_22 = s_b_2_18-s_b_2_21 */
    auto s_b_2_22 = emitter.sub(s_b_2_18, s_b_2_21);
    /* execute.simd:5949 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5949 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5949 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5949 [D] s_b_2_27 = (u16)s_b_2_26 */
    auto s_b_2_27 = emitter.zx(s_b_2_26, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5949 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5949 [D] s_b_2_30 = (u16)s_b_2_29 */
    auto s_b_2_30 = emitter.zx(s_b_2_29, emitter.context().types().u16());
    /* execute.simd:5949 [D] s_b_2_31 = s_b_2_27-s_b_2_30 */
    auto s_b_2_31 = emitter.sub(s_b_2_27, s_b_2_30);
    /* execute.simd:5949 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5949 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5949 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5949 [D] s_b_2_36 = (u16)s_b_2_35 */
    auto s_b_2_36 = emitter.zx(s_b_2_35, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5949 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5949 [D] s_b_2_39 = (u16)s_b_2_38 */
    auto s_b_2_39 = emitter.zx(s_b_2_38, emitter.context().types().u16());
    /* execute.simd:5949 [D] s_b_2_40 = s_b_2_36-s_b_2_39 */
    auto s_b_2_40 = emitter.sub(s_b_2_36, s_b_2_39);
    /* execute.simd:5949 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5949 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5949 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5949 [D] s_b_2_45 = (u16)s_b_2_44 */
    auto s_b_2_45 = emitter.zx(s_b_2_44, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5949 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5949 [D] s_b_2_48 = (u16)s_b_2_47 */
    auto s_b_2_48 = emitter.zx(s_b_2_47, emitter.context().types().u16());
    /* execute.simd:5949 [D] s_b_2_49 = s_b_2_45-s_b_2_48 */
    auto s_b_2_49 = emitter.sub(s_b_2_45, s_b_2_48);
    /* execute.simd:5949 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5949 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5949 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5949 [D] s_b_2_54 = (u16)s_b_2_53 */
    auto s_b_2_54 = emitter.zx(s_b_2_53, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5949 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5949 [D] s_b_2_57 = (u16)s_b_2_56 */
    auto s_b_2_57 = emitter.zx(s_b_2_56, emitter.context().types().u16());
    /* execute.simd:5949 [D] s_b_2_58 = s_b_2_54-s_b_2_57 */
    auto s_b_2_58 = emitter.sub(s_b_2_54, s_b_2_57);
    /* execute.simd:5949 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5949 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5949 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5949 [D] s_b_2_63 = (u16)s_b_2_62 */
    auto s_b_2_63 = emitter.zx(s_b_2_62, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5949 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5949 [D] s_b_2_66 = (u16)s_b_2_65 */
    auto s_b_2_66 = emitter.zx(s_b_2_65, emitter.context().types().u16());
    /* execute.simd:5949 [D] s_b_2_67 = s_b_2_63-s_b_2_66 */
    auto s_b_2_67 = emitter.sub(s_b_2_63, s_b_2_66);
    /* execute.simd:5949 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5949 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5949 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5949 [D] s_b_2_72 = (u16)s_b_2_71 */
    auto s_b_2_72 = emitter.zx(s_b_2_71, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5949 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5949 [D] s_b_2_75 = (u16)s_b_2_74 */
    auto s_b_2_75 = emitter.zx(s_b_2_74, emitter.context().types().u16());
    /* execute.simd:5949 [D] s_b_2_76 = s_b_2_72-s_b_2_75 */
    auto s_b_2_76 = emitter.sub(s_b_2_72, s_b_2_75);
    /* execute.simd:5949 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5949 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5952 [F] s_b_2_79=sym_45118_3_parameter_inst.rd (const) */
    /* execute.simd:5952 [D] s_b_2_80: WriteRegBank 18:s_b_2_79 = s_b_2_78 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_78,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_78);
    /* execute.simd:0 [F] s_b_2_81: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5956 [F] s_b_3_0=sym_45118_3_parameter_inst.rn (const) */
    /* execute.simd:5956 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5956 [D] s_b_3_2 = (v16u8)s_b_3_1 */
    auto s_b_3_2 = (captive::arch::dbt::el::Value *)s_b_3_1;
    /* execute.simd:5957 [F] s_b_3_3=sym_45118_3_parameter_inst.rm (const) */
    /* execute.simd:5957 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5957 [D] s_b_3_5 = (v16u8)s_b_3_4 */
    auto s_b_3_5 = (captive::arch::dbt::el::Value *)s_b_3_4;
    /* ???:4294967295 [F] s_b_3_6 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5961 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5961 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5961 [D] s_b_3_9 = (u16)s_b_3_8 */
    auto s_b_3_9 = emitter.zx(s_b_3_8, emitter.context().types().u16());
    /* execute.simd:5961 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5961 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5961 [D] s_b_3_12 = (u16)s_b_3_11 */
    auto s_b_3_12 = emitter.zx(s_b_3_11, emitter.context().types().u16());
    /* execute.simd:5961 [D] s_b_3_13 = s_b_3_9-s_b_3_12 */
    auto s_b_3_13 = emitter.sub(s_b_3_9, s_b_3_12);
    /* execute.simd:5961 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5961 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5961 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5961 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5961 [D] s_b_3_18 = (u16)s_b_3_17 */
    auto s_b_3_18 = emitter.zx(s_b_3_17, emitter.context().types().u16());
    /* execute.simd:5961 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5961 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5961 [D] s_b_3_21 = (u16)s_b_3_20 */
    auto s_b_3_21 = emitter.zx(s_b_3_20, emitter.context().types().u16());
    /* execute.simd:5961 [D] s_b_3_22 = s_b_3_18-s_b_3_21 */
    auto s_b_3_22 = emitter.sub(s_b_3_18, s_b_3_21);
    /* execute.simd:5961 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5961 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5961 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5961 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5961 [D] s_b_3_27 = (u16)s_b_3_26 */
    auto s_b_3_27 = emitter.zx(s_b_3_26, emitter.context().types().u16());
    /* execute.simd:5961 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5961 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5961 [D] s_b_3_30 = (u16)s_b_3_29 */
    auto s_b_3_30 = emitter.zx(s_b_3_29, emitter.context().types().u16());
    /* execute.simd:5961 [D] s_b_3_31 = s_b_3_27-s_b_3_30 */
    auto s_b_3_31 = emitter.sub(s_b_3_27, s_b_3_30);
    /* execute.simd:5961 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5961 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5961 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5961 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5961 [D] s_b_3_36 = (u16)s_b_3_35 */
    auto s_b_3_36 = emitter.zx(s_b_3_35, emitter.context().types().u16());
    /* execute.simd:5961 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5961 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5961 [D] s_b_3_39 = (u16)s_b_3_38 */
    auto s_b_3_39 = emitter.zx(s_b_3_38, emitter.context().types().u16());
    /* execute.simd:5961 [D] s_b_3_40 = s_b_3_36-s_b_3_39 */
    auto s_b_3_40 = emitter.sub(s_b_3_36, s_b_3_39);
    /* execute.simd:5961 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5961 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5961 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5961 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5961 [D] s_b_3_45 = (u16)s_b_3_44 */
    auto s_b_3_45 = emitter.zx(s_b_3_44, emitter.context().types().u16());
    /* execute.simd:5961 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5961 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5961 [D] s_b_3_48 = (u16)s_b_3_47 */
    auto s_b_3_48 = emitter.zx(s_b_3_47, emitter.context().types().u16());
    /* execute.simd:5961 [D] s_b_3_49 = s_b_3_45-s_b_3_48 */
    auto s_b_3_49 = emitter.sub(s_b_3_45, s_b_3_48);
    /* execute.simd:5961 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5961 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5961 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5961 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5961 [D] s_b_3_54 = (u16)s_b_3_53 */
    auto s_b_3_54 = emitter.zx(s_b_3_53, emitter.context().types().u16());
    /* execute.simd:5961 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5961 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5961 [D] s_b_3_57 = (u16)s_b_3_56 */
    auto s_b_3_57 = emitter.zx(s_b_3_56, emitter.context().types().u16());
    /* execute.simd:5961 [D] s_b_3_58 = s_b_3_54-s_b_3_57 */
    auto s_b_3_58 = emitter.sub(s_b_3_54, s_b_3_57);
    /* execute.simd:5961 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5961 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5961 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5961 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5961 [D] s_b_3_63 = (u16)s_b_3_62 */
    auto s_b_3_63 = emitter.zx(s_b_3_62, emitter.context().types().u16());
    /* execute.simd:5961 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5961 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5961 [D] s_b_3_66 = (u16)s_b_3_65 */
    auto s_b_3_66 = emitter.zx(s_b_3_65, emitter.context().types().u16());
    /* execute.simd:5961 [D] s_b_3_67 = s_b_3_63-s_b_3_66 */
    auto s_b_3_67 = emitter.sub(s_b_3_63, s_b_3_66);
    /* execute.simd:5961 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5961 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5961 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5961 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5961 [D] s_b_3_72 = (u16)s_b_3_71 */
    auto s_b_3_72 = emitter.zx(s_b_3_71, emitter.context().types().u16());
    /* execute.simd:5961 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5961 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5961 [D] s_b_3_75 = (u16)s_b_3_74 */
    auto s_b_3_75 = emitter.zx(s_b_3_74, emitter.context().types().u16());
    /* execute.simd:5961 [D] s_b_3_76 = s_b_3_72-s_b_3_75 */
    auto s_b_3_76 = emitter.sub(s_b_3_72, s_b_3_75);
    /* execute.simd:5961 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5961 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5964 [F] s_b_3_79=sym_45118_3_parameter_inst.rd (const) */
    /* execute.simd:5964 [D] s_b_3_80: WriteRegBank 18:s_b_3_79 = s_b_3_78 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_78,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_78);
    /* execute.simd:0 [F] s_b_3_81: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5968 [F] s_b_4_0=sym_45118_3_parameter_inst.rn (const) */
    /* execute.simd:5968 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5968 [D] s_b_4_2 = (v4u16)s_b_4_1 */
    auto s_b_4_2 = (captive::arch::dbt::el::Value *)s_b_4_1;
    /* execute.simd:5969 [F] s_b_4_3=sym_45118_3_parameter_inst.rm (const) */
    /* execute.simd:5969 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5969 [D] s_b_4_5 = (v4u16)s_b_4_4 */
    auto s_b_4_5 = (captive::arch::dbt::el::Value *)s_b_4_4;
    /* ???:4294967295 [F] s_b_4_6 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5973 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5973 [D] s_b_4_9 = (u32)s_b_4_8 */
    auto s_b_4_9 = emitter.zx(s_b_4_8, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5973 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5973 [D] s_b_4_12 = (u32)s_b_4_11 */
    auto s_b_4_12 = emitter.zx(s_b_4_11, emitter.context().types().u32());
    /* execute.simd:5973 [D] s_b_4_13 = s_b_4_9-s_b_4_12 */
    auto s_b_4_13 = emitter.sub(s_b_4_9, s_b_4_12);
    /* execute.simd:5973 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5973 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5973 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5973 [D] s_b_4_18 = (u32)s_b_4_17 */
    auto s_b_4_18 = emitter.zx(s_b_4_17, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5973 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5973 [D] s_b_4_21 = (u32)s_b_4_20 */
    auto s_b_4_21 = emitter.zx(s_b_4_20, emitter.context().types().u32());
    /* execute.simd:5973 [D] s_b_4_22 = s_b_4_18-s_b_4_21 */
    auto s_b_4_22 = emitter.sub(s_b_4_18, s_b_4_21);
    /* execute.simd:5973 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5973 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5973 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5973 [D] s_b_4_27 = (u32)s_b_4_26 */
    auto s_b_4_27 = emitter.zx(s_b_4_26, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5973 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5973 [D] s_b_4_30 = (u32)s_b_4_29 */
    auto s_b_4_30 = emitter.zx(s_b_4_29, emitter.context().types().u32());
    /* execute.simd:5973 [D] s_b_4_31 = s_b_4_27-s_b_4_30 */
    auto s_b_4_31 = emitter.sub(s_b_4_27, s_b_4_30);
    /* execute.simd:5973 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5973 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5973 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5973 [D] s_b_4_36 = (u32)s_b_4_35 */
    auto s_b_4_36 = emitter.zx(s_b_4_35, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5973 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5973 [D] s_b_4_39 = (u32)s_b_4_38 */
    auto s_b_4_39 = emitter.zx(s_b_4_38, emitter.context().types().u32());
    /* execute.simd:5973 [D] s_b_4_40 = s_b_4_36-s_b_4_39 */
    auto s_b_4_40 = emitter.sub(s_b_4_36, s_b_4_39);
    /* execute.simd:5973 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5973 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5976 [F] s_b_4_43=sym_45118_3_parameter_inst.rd (const) */
    /* execute.simd:5976 [D] s_b_4_44: WriteRegBank 20:s_b_4_43 = s_b_4_42 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_42,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_42);
    /* execute.simd:0 [F] s_b_4_45: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5980 [F] s_b_5_0=sym_45118_3_parameter_inst.rn (const) */
    /* execute.simd:5980 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5980 [D] s_b_5_2 = (v8u16)s_b_5_1 */
    auto s_b_5_2 = (captive::arch::dbt::el::Value *)s_b_5_1;
    /* execute.simd:5981 [F] s_b_5_3=sym_45118_3_parameter_inst.rm (const) */
    /* execute.simd:5981 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5981 [D] s_b_5_5 = (v8u16)s_b_5_4 */
    auto s_b_5_5 = (captive::arch::dbt::el::Value *)s_b_5_4;
    /* ???:4294967295 [F] s_b_5_6 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5985 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5985 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5985 [D] s_b_5_9 = (u32)s_b_5_8 */
    auto s_b_5_9 = emitter.zx(s_b_5_8, emitter.context().types().u32());
    /* execute.simd:5985 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5985 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5985 [D] s_b_5_12 = (u32)s_b_5_11 */
    auto s_b_5_12 = emitter.zx(s_b_5_11, emitter.context().types().u32());
    /* execute.simd:5985 [D] s_b_5_13 = s_b_5_9-s_b_5_12 */
    auto s_b_5_13 = emitter.sub(s_b_5_9, s_b_5_12);
    /* execute.simd:5985 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5985 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5985 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5985 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5985 [D] s_b_5_18 = (u32)s_b_5_17 */
    auto s_b_5_18 = emitter.zx(s_b_5_17, emitter.context().types().u32());
    /* execute.simd:5985 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5985 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5985 [D] s_b_5_21 = (u32)s_b_5_20 */
    auto s_b_5_21 = emitter.zx(s_b_5_20, emitter.context().types().u32());
    /* execute.simd:5985 [D] s_b_5_22 = s_b_5_18-s_b_5_21 */
    auto s_b_5_22 = emitter.sub(s_b_5_18, s_b_5_21);
    /* execute.simd:5985 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5985 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5985 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5985 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5985 [D] s_b_5_27 = (u32)s_b_5_26 */
    auto s_b_5_27 = emitter.zx(s_b_5_26, emitter.context().types().u32());
    /* execute.simd:5985 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5985 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5985 [D] s_b_5_30 = (u32)s_b_5_29 */
    auto s_b_5_30 = emitter.zx(s_b_5_29, emitter.context().types().u32());
    /* execute.simd:5985 [D] s_b_5_31 = s_b_5_27-s_b_5_30 */
    auto s_b_5_31 = emitter.sub(s_b_5_27, s_b_5_30);
    /* execute.simd:5985 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5985 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5985 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5985 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5985 [D] s_b_5_36 = (u32)s_b_5_35 */
    auto s_b_5_36 = emitter.zx(s_b_5_35, emitter.context().types().u32());
    /* execute.simd:5985 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5985 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5985 [D] s_b_5_39 = (u32)s_b_5_38 */
    auto s_b_5_39 = emitter.zx(s_b_5_38, emitter.context().types().u32());
    /* execute.simd:5985 [D] s_b_5_40 = s_b_5_36-s_b_5_39 */
    auto s_b_5_40 = emitter.sub(s_b_5_36, s_b_5_39);
    /* execute.simd:5985 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5985 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5988 [F] s_b_5_43=sym_45118_3_parameter_inst.rd (const) */
    /* execute.simd:5988 [D] s_b_5_44: WriteRegBank 20:s_b_5_43 = s_b_5_42 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_42,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_42);
    /* execute.simd:0 [F] s_b_5_45: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5992 [F] s_b_6_0=sym_45118_3_parameter_inst.rn (const) */
    /* execute.simd:5992 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5992 [D] s_b_6_2 = (v2u32)s_b_6_1 */
    auto s_b_6_2 = (captive::arch::dbt::el::Value *)s_b_6_1;
    /* execute.simd:5993 [F] s_b_6_3=sym_45118_3_parameter_inst.rm (const) */
    /* execute.simd:5993 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5993 [D] s_b_6_5 = (v2u32)s_b_6_4 */
    auto s_b_6_5 = (captive::arch::dbt::el::Value *)s_b_6_4;
    /* ???:4294967295 [F] s_b_6_6 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5997 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5997 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5997 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5997 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.simd:5997 [D] s_b_6_13 = s_b_6_9-s_b_6_12 */
    auto s_b_6_13 = emitter.sub(s_b_6_9, s_b_6_12);
    /* execute.simd:5997 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5997 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5997 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5997 [D] s_b_6_18 = (u64)s_b_6_17 */
    auto s_b_6_18 = emitter.zx(s_b_6_17, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5997 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5997 [D] s_b_6_21 = (u64)s_b_6_20 */
    auto s_b_6_21 = emitter.zx(s_b_6_20, emitter.context().types().u64());
    /* execute.simd:5997 [D] s_b_6_22 = s_b_6_18-s_b_6_21 */
    auto s_b_6_22 = emitter.sub(s_b_6_18, s_b_6_21);
    /* execute.simd:5997 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5997 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:6000 [F] s_b_6_25=sym_45118_3_parameter_inst.rd (const) */
    /* execute.simd:6000 [D] s_b_6_26: WriteRegBank 21:s_b_6_25 = s_b_6_24 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_24,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_24);
    /* execute.simd:0 [F] s_b_6_27: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:6004 [F] s_b_7_0=sym_45118_3_parameter_inst.rn (const) */
    /* execute.simd:6004 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:6004 [D] s_b_7_2 = (v4u32)s_b_7_1 */
    auto s_b_7_2 = (captive::arch::dbt::el::Value *)s_b_7_1;
    /* execute.simd:6005 [F] s_b_7_3=sym_45118_3_parameter_inst.rm (const) */
    /* execute.simd:6005 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:6005 [D] s_b_7_5 = (v4u32)s_b_7_4 */
    auto s_b_7_5 = (captive::arch::dbt::el::Value *)s_b_7_4;
    /* ???:4294967295 [F] s_b_7_6 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:6009 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:6009 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:6009 [D] s_b_7_9 = (u64)s_b_7_8 */
    auto s_b_7_9 = emitter.zx(s_b_7_8, emitter.context().types().u64());
    /* execute.simd:6009 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:6009 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:6009 [D] s_b_7_12 = (u64)s_b_7_11 */
    auto s_b_7_12 = emitter.zx(s_b_7_11, emitter.context().types().u64());
    /* execute.simd:6009 [D] s_b_7_13 = s_b_7_9-s_b_7_12 */
    auto s_b_7_13 = emitter.sub(s_b_7_9, s_b_7_12);
    /* execute.simd:6009 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:6009 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:6009 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:6009 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:6009 [D] s_b_7_18 = (u64)s_b_7_17 */
    auto s_b_7_18 = emitter.zx(s_b_7_17, emitter.context().types().u64());
    /* execute.simd:6009 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:6009 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:6009 [D] s_b_7_21 = (u64)s_b_7_20 */
    auto s_b_7_21 = emitter.zx(s_b_7_20, emitter.context().types().u64());
    /* execute.simd:6009 [D] s_b_7_22 = s_b_7_18-s_b_7_21 */
    auto s_b_7_22 = emitter.sub(s_b_7_18, s_b_7_21);
    /* execute.simd:6009 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:6009 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:6012 [F] s_b_7_25=sym_45118_3_parameter_inst.rd (const) */
    /* execute.simd:6012 [D] s_b_7_26: WriteRegBank 21:s_b_7_25 = s_b_7_24 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_24,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_24);
    /* execute.simd:0 [F] s_b_7_27: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:6016 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5942 [F] s_b_8_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_xtn(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2289 [F] s_b_0_0=sym_47630_3_parameter_inst.arrangement (const) */
    /* execute.simd:2290 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:2307 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:2324 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:2337 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:2350 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:2361 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:2289 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
      break;
    default:
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:2291 [F] s_b_2_0=sym_47630_3_parameter_inst.rn (const) */
    /* execute.simd:2291 [D] s_b_2_1 = ReadRegBank 18:s_b_2_0 (v8u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_2_2 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:2294 [F] s_b_2_3 = constant s32 0 (const) */
    /* execute.simd:2294 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2294 [D] s_b_2_5 = (u8)s_b_2_4 */
    auto s_b_2_5 = emitter.truncate(s_b_2_4, emitter.context().types().u8());
    /* execute.simd:2294 [F] s_b_2_6 = constant s32 0 (const) */
    /* execute.simd:2294 [D] s_b_2_7 = s_b_2_2[s_b_2_6] <= s_b_2_5 */
    auto s_b_2_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_2_5);
    /* execute.simd:2295 [F] s_b_2_8 = constant s32 1 (const) */
    /* execute.simd:2295 [D] s_b_2_1[s_b_2_8] */
    auto s_b_2_9 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2295 [D] s_b_2_10 = (u8)s_b_2_9 */
    auto s_b_2_10 = emitter.truncate(s_b_2_9, emitter.context().types().u8());
    /* execute.simd:2295 [F] s_b_2_11 = constant s32 1 (const) */
    /* execute.simd:2295 [D] s_b_2_12 = s_b_2_7[s_b_2_11] <= s_b_2_10 */
    auto s_b_2_12 = emitter.vector_insert(s_b_2_7, emitter.const_s32((int32_t)1ULL), s_b_2_10);
    /* execute.simd:2296 [F] s_b_2_13 = constant s32 2 (const) */
    /* execute.simd:2296 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2296 [D] s_b_2_15 = (u8)s_b_2_14 */
    auto s_b_2_15 = emitter.truncate(s_b_2_14, emitter.context().types().u8());
    /* execute.simd:2296 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:2296 [D] s_b_2_17 = s_b_2_12[s_b_2_16] <= s_b_2_15 */
    auto s_b_2_17 = emitter.vector_insert(s_b_2_12, emitter.const_s32((int32_t)2ULL), s_b_2_15);
    /* execute.simd:2297 [F] s_b_2_18 = constant s32 3 (const) */
    /* execute.simd:2297 [D] s_b_2_1[s_b_2_18] */
    auto s_b_2_19 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2297 [D] s_b_2_20 = (u8)s_b_2_19 */
    auto s_b_2_20 = emitter.truncate(s_b_2_19, emitter.context().types().u8());
    /* execute.simd:2297 [F] s_b_2_21 = constant s32 3 (const) */
    /* execute.simd:2297 [D] s_b_2_22 = s_b_2_17[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_17, emitter.const_s32((int32_t)3ULL), s_b_2_20);
    /* execute.simd:2298 [F] s_b_2_23 = constant s32 4 (const) */
    /* execute.simd:2298 [D] s_b_2_1[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:2298 [D] s_b_2_25 = (u8)s_b_2_24 */
    auto s_b_2_25 = emitter.truncate(s_b_2_24, emitter.context().types().u8());
    /* execute.simd:2298 [F] s_b_2_26 = constant s32 4 (const) */
    /* execute.simd:2298 [D] s_b_2_27 = s_b_2_22[s_b_2_26] <= s_b_2_25 */
    auto s_b_2_27 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)4ULL), s_b_2_25);
    /* execute.simd:2299 [F] s_b_2_28 = constant s32 5 (const) */
    /* execute.simd:2299 [D] s_b_2_1[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:2299 [D] s_b_2_30 = (u8)s_b_2_29 */
    auto s_b_2_30 = emitter.truncate(s_b_2_29, emitter.context().types().u8());
    /* execute.simd:2299 [F] s_b_2_31 = constant s32 5 (const) */
    /* execute.simd:2299 [D] s_b_2_32 = s_b_2_27[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_27, emitter.const_s32((int32_t)5ULL), s_b_2_30);
    /* execute.simd:2300 [F] s_b_2_33 = constant s32 6 (const) */
    /* execute.simd:2300 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:2300 [D] s_b_2_35 = (u8)s_b_2_34 */
    auto s_b_2_35 = emitter.truncate(s_b_2_34, emitter.context().types().u8());
    /* execute.simd:2300 [F] s_b_2_36 = constant s32 6 (const) */
    /* execute.simd:2300 [D] s_b_2_37 = s_b_2_32[s_b_2_36] <= s_b_2_35 */
    auto s_b_2_37 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)6ULL), s_b_2_35);
    /* execute.simd:2301 [F] s_b_2_38 = constant s32 7 (const) */
    /* execute.simd:2301 [D] s_b_2_1[s_b_2_38] */
    auto s_b_2_39 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:2301 [D] s_b_2_40 = (u8)s_b_2_39 */
    auto s_b_2_40 = emitter.truncate(s_b_2_39, emitter.context().types().u8());
    /* execute.simd:2301 [F] s_b_2_41 = constant s32 7 (const) */
    /* execute.simd:2301 [D] s_b_2_42 = s_b_2_37[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_37, emitter.const_s32((int32_t)7ULL), s_b_2_40);
    /* execute.simd:2303 [F] s_b_2_43=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2303 [D] s_b_2_44: WriteRegBank 16:s_b_2_43 = s_b_2_42 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_42,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_42);
    /* execute.simd:0 [F] s_b_2_45: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2308 [F] s_b_3_0=sym_47630_3_parameter_inst.rn (const) */
    /* execute.simd:2308 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:2310 [F] s_b_3_2=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2310 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:2311 [F] s_b_3_4 = constant s32 0 (const) */
    /* execute.simd:2311 [D] s_b_3_1[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2311 [D] s_b_3_6 = (u8)s_b_3_5 */
    auto s_b_3_6 = emitter.truncate(s_b_3_5, emitter.context().types().u8());
    /* execute.simd:2311 [F] s_b_3_7 = constant s32 8 (const) */
    /* execute.simd:2311 [D] s_b_3_8 = s_b_3_3[s_b_3_7] <= s_b_3_6 */
    auto s_b_3_8 = emitter.vector_insert(s_b_3_3, emitter.const_s32((int32_t)8ULL), s_b_3_6);
    /* execute.simd:2312 [F] s_b_3_9 = constant s32 1 (const) */
    /* execute.simd:2312 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2312 [D] s_b_3_11 = (u8)s_b_3_10 */
    auto s_b_3_11 = emitter.truncate(s_b_3_10, emitter.context().types().u8());
    /* execute.simd:2312 [F] s_b_3_12 = constant s32 9 (const) */
    /* execute.simd:2312 [D] s_b_3_13 = s_b_3_8[s_b_3_12] <= s_b_3_11 */
    auto s_b_3_13 = emitter.vector_insert(s_b_3_8, emitter.const_s32((int32_t)9ULL), s_b_3_11);
    /* execute.simd:2313 [F] s_b_3_14 = constant s32 2 (const) */
    /* execute.simd:2313 [D] s_b_3_1[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2313 [D] s_b_3_16 = (u8)s_b_3_15 */
    auto s_b_3_16 = emitter.truncate(s_b_3_15, emitter.context().types().u8());
    /* execute.simd:2313 [F] s_b_3_17 = constant s32 a (const) */
    /* execute.simd:2313 [D] s_b_3_18 = s_b_3_13[s_b_3_17] <= s_b_3_16 */
    auto s_b_3_18 = emitter.vector_insert(s_b_3_13, emitter.const_s32((int32_t)10ULL), s_b_3_16);
    /* execute.simd:2314 [F] s_b_3_19 = constant s32 3 (const) */
    /* execute.simd:2314 [D] s_b_3_1[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2314 [D] s_b_3_21 = (u8)s_b_3_20 */
    auto s_b_3_21 = emitter.truncate(s_b_3_20, emitter.context().types().u8());
    /* execute.simd:2314 [F] s_b_3_22 = constant s32 b (const) */
    /* execute.simd:2314 [D] s_b_3_23 = s_b_3_18[s_b_3_22] <= s_b_3_21 */
    auto s_b_3_23 = emitter.vector_insert(s_b_3_18, emitter.const_s32((int32_t)11ULL), s_b_3_21);
    /* execute.simd:2315 [F] s_b_3_24 = constant s32 4 (const) */
    /* execute.simd:2315 [D] s_b_3_1[s_b_3_24] */
    auto s_b_3_25 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:2315 [D] s_b_3_26 = (u8)s_b_3_25 */
    auto s_b_3_26 = emitter.truncate(s_b_3_25, emitter.context().types().u8());
    /* execute.simd:2315 [F] s_b_3_27 = constant s32 c (const) */
    /* execute.simd:2315 [D] s_b_3_28 = s_b_3_23[s_b_3_27] <= s_b_3_26 */
    auto s_b_3_28 = emitter.vector_insert(s_b_3_23, emitter.const_s32((int32_t)12ULL), s_b_3_26);
    /* execute.simd:2316 [F] s_b_3_29 = constant s32 5 (const) */
    /* execute.simd:2316 [D] s_b_3_1[s_b_3_29] */
    auto s_b_3_30 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:2316 [D] s_b_3_31 = (u8)s_b_3_30 */
    auto s_b_3_31 = emitter.truncate(s_b_3_30, emitter.context().types().u8());
    /* execute.simd:2316 [F] s_b_3_32 = constant s32 d (const) */
    /* execute.simd:2316 [D] s_b_3_33 = s_b_3_28[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_28, emitter.const_s32((int32_t)13ULL), s_b_3_31);
    /* execute.simd:2317 [F] s_b_3_34 = constant s32 6 (const) */
    /* execute.simd:2317 [D] s_b_3_1[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:2317 [D] s_b_3_36 = (u8)s_b_3_35 */
    auto s_b_3_36 = emitter.truncate(s_b_3_35, emitter.context().types().u8());
    /* execute.simd:2317 [F] s_b_3_37 = constant s32 e (const) */
    /* execute.simd:2317 [D] s_b_3_38 = s_b_3_33[s_b_3_37] <= s_b_3_36 */
    auto s_b_3_38 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)14ULL), s_b_3_36);
    /* execute.simd:2318 [F] s_b_3_39 = constant s32 7 (const) */
    /* execute.simd:2318 [D] s_b_3_1[s_b_3_39] */
    auto s_b_3_40 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:2318 [D] s_b_3_41 = (u8)s_b_3_40 */
    auto s_b_3_41 = emitter.truncate(s_b_3_40, emitter.context().types().u8());
    /* execute.simd:2318 [F] s_b_3_42 = constant s32 f (const) */
    /* execute.simd:2318 [D] s_b_3_43 = s_b_3_38[s_b_3_42] <= s_b_3_41 */
    auto s_b_3_43 = emitter.vector_insert(s_b_3_38, emitter.const_s32((int32_t)15ULL), s_b_3_41);
    /* execute.simd:2320 [F] s_b_3_44=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2320 [D] s_b_3_45: WriteRegBank 16:s_b_3_44 = s_b_3_43 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_43,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_43);
    /* execute.simd:0 [F] s_b_3_46: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2325 [F] s_b_4_0=sym_47630_3_parameter_inst.rn (const) */
    /* execute.simd:2325 [D] s_b_4_1 = ReadRegBank 20:s_b_4_0 (v4u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_4_2 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:2328 [F] s_b_4_3 = constant s32 0 (const) */
    /* execute.simd:2328 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2328 [D] s_b_4_5 = (u16)s_b_4_4 */
    auto s_b_4_5 = emitter.truncate(s_b_4_4, emitter.context().types().u16());
    /* execute.simd:2328 [F] s_b_4_6 = constant s32 0 (const) */
    /* execute.simd:2328 [D] s_b_4_7 = s_b_4_2[s_b_4_6] <= s_b_4_5 */
    auto s_b_4_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_4_5);
    /* execute.simd:2329 [F] s_b_4_8 = constant s32 1 (const) */
    /* execute.simd:2329 [D] s_b_4_1[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2329 [D] s_b_4_10 = (u16)s_b_4_9 */
    auto s_b_4_10 = emitter.truncate(s_b_4_9, emitter.context().types().u16());
    /* execute.simd:2329 [F] s_b_4_11 = constant s32 1 (const) */
    /* execute.simd:2329 [D] s_b_4_12 = s_b_4_7[s_b_4_11] <= s_b_4_10 */
    auto s_b_4_12 = emitter.vector_insert(s_b_4_7, emitter.const_s32((int32_t)1ULL), s_b_4_10);
    /* execute.simd:2330 [F] s_b_4_13 = constant s32 2 (const) */
    /* execute.simd:2330 [D] s_b_4_1[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2330 [D] s_b_4_15 = (u16)s_b_4_14 */
    auto s_b_4_15 = emitter.truncate(s_b_4_14, emitter.context().types().u16());
    /* execute.simd:2330 [F] s_b_4_16 = constant s32 2 (const) */
    /* execute.simd:2330 [D] s_b_4_17 = s_b_4_12[s_b_4_16] <= s_b_4_15 */
    auto s_b_4_17 = emitter.vector_insert(s_b_4_12, emitter.const_s32((int32_t)2ULL), s_b_4_15);
    /* execute.simd:2331 [F] s_b_4_18 = constant s32 3 (const) */
    /* execute.simd:2331 [D] s_b_4_1[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2331 [D] s_b_4_20 = (u16)s_b_4_19 */
    auto s_b_4_20 = emitter.truncate(s_b_4_19, emitter.context().types().u16());
    /* execute.simd:2331 [F] s_b_4_21 = constant s32 3 (const) */
    /* execute.simd:2331 [D] s_b_4_22 = s_b_4_17[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_17, emitter.const_s32((int32_t)3ULL), s_b_4_20);
    /* execute.simd:2333 [F] s_b_4_23=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2333 [D] s_b_4_24: WriteRegBank 18:s_b_4_23 = s_b_4_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_22,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_22);
    /* execute.simd:0 [F] s_b_4_25: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:2338 [F] s_b_5_0=sym_47630_3_parameter_inst.rn (const) */
    /* execute.simd:2338 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:2340 [F] s_b_5_2=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2340 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:2341 [F] s_b_5_4 = constant s32 0 (const) */
    /* execute.simd:2341 [D] s_b_5_1[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2341 [D] s_b_5_6 = (u16)s_b_5_5 */
    auto s_b_5_6 = emitter.truncate(s_b_5_5, emitter.context().types().u16());
    /* execute.simd:2341 [F] s_b_5_7 = constant s32 4 (const) */
    /* execute.simd:2341 [D] s_b_5_8 = s_b_5_3[s_b_5_7] <= s_b_5_6 */
    auto s_b_5_8 = emitter.vector_insert(s_b_5_3, emitter.const_s32((int32_t)4ULL), s_b_5_6);
    /* execute.simd:2342 [F] s_b_5_9 = constant s32 1 (const) */
    /* execute.simd:2342 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2342 [D] s_b_5_11 = (u16)s_b_5_10 */
    auto s_b_5_11 = emitter.truncate(s_b_5_10, emitter.context().types().u16());
    /* execute.simd:2342 [F] s_b_5_12 = constant s32 5 (const) */
    /* execute.simd:2342 [D] s_b_5_13 = s_b_5_8[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(s_b_5_8, emitter.const_s32((int32_t)5ULL), s_b_5_11);
    /* execute.simd:2343 [F] s_b_5_14 = constant s32 2 (const) */
    /* execute.simd:2343 [D] s_b_5_1[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2343 [D] s_b_5_16 = (u16)s_b_5_15 */
    auto s_b_5_16 = emitter.truncate(s_b_5_15, emitter.context().types().u16());
    /* execute.simd:2343 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:2343 [D] s_b_5_18 = s_b_5_13[s_b_5_17] <= s_b_5_16 */
    auto s_b_5_18 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)6ULL), s_b_5_16);
    /* execute.simd:2344 [F] s_b_5_19 = constant s32 3 (const) */
    /* execute.simd:2344 [D] s_b_5_1[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2344 [D] s_b_5_21 = (u16)s_b_5_20 */
    auto s_b_5_21 = emitter.truncate(s_b_5_20, emitter.context().types().u16());
    /* execute.simd:2344 [F] s_b_5_22 = constant s32 7 (const) */
    /* execute.simd:2344 [D] s_b_5_23 = s_b_5_18[s_b_5_22] <= s_b_5_21 */
    auto s_b_5_23 = emitter.vector_insert(s_b_5_18, emitter.const_s32((int32_t)7ULL), s_b_5_21);
    /* execute.simd:2346 [F] s_b_5_24=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2346 [D] s_b_5_25: WriteRegBank 18:s_b_5_24 = s_b_5_23 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_23,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_23);
    /* execute.simd:0 [F] s_b_5_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2351 [F] s_b_6_0=sym_47630_3_parameter_inst.rn (const) */
    /* execute.simd:2351 [D] s_b_6_1 = ReadRegBank 21:s_b_6_0 (v2u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:2354 [F] s_b_6_3 = constant s32 0 (const) */
    /* execute.simd:2354 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2354 [D] s_b_6_5 = (u32)s_b_6_4 */
    auto s_b_6_5 = emitter.truncate(s_b_6_4, emitter.context().types().u32());
    /* execute.simd:2354 [F] s_b_6_6 = constant s32 0 (const) */
    /* execute.simd:2354 [D] s_b_6_7 = s_b_6_2[s_b_6_6] <= s_b_6_5 */
    auto s_b_6_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_6_5);
    /* execute.simd:2355 [F] s_b_6_8 = constant s32 1 (const) */
    /* execute.simd:2355 [D] s_b_6_1[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2355 [D] s_b_6_10 = (u32)s_b_6_9 */
    auto s_b_6_10 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.simd:2355 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:2355 [D] s_b_6_12 = s_b_6_7[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_7, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:2357 [F] s_b_6_13=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2357 [D] s_b_6_14: WriteRegBank 20:s_b_6_13 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12);
    /* execute.simd:0 [F] s_b_6_15: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2362 [F] s_b_7_0=sym_47630_3_parameter_inst.rn (const) */
    /* execute.simd:2362 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:2364 [F] s_b_7_2=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2364 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:2365 [F] s_b_7_4 = constant s32 0 (const) */
    /* execute.simd:2365 [D] s_b_7_1[s_b_7_4] */
    auto s_b_7_5 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2365 [D] s_b_7_6 = (u32)s_b_7_5 */
    auto s_b_7_6 = emitter.truncate(s_b_7_5, emitter.context().types().u32());
    /* execute.simd:2365 [F] s_b_7_7 = constant s32 2 (const) */
    /* execute.simd:2365 [D] s_b_7_8 = s_b_7_3[s_b_7_7] <= s_b_7_6 */
    auto s_b_7_8 = emitter.vector_insert(s_b_7_3, emitter.const_s32((int32_t)2ULL), s_b_7_6);
    /* execute.simd:2366 [F] s_b_7_9 = constant s32 1 (const) */
    /* execute.simd:2366 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2366 [D] s_b_7_11 = (u32)s_b_7_10 */
    auto s_b_7_11 = emitter.truncate(s_b_7_10, emitter.context().types().u32());
    /* execute.simd:2366 [F] s_b_7_12 = constant s32 3 (const) */
    /* execute.simd:2366 [D] s_b_7_13 = s_b_7_8[s_b_7_12] <= s_b_7_11 */
    auto s_b_7_13 = emitter.vector_insert(s_b_7_8, emitter.const_s32((int32_t)3ULL), s_b_7_11);
    /* execute.simd:2368 [F] s_b_7_14=sym_47630_3_parameter_inst.rd (const) */
    /* execute.simd:2368 [D] s_b_7_15: WriteRegBank 20:s_b_7_14 = s_b_7_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_13,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_13);
    /* execute.simd:0 [F] s_b_7_16: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2373 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_8_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template class arm64_jit2<true>;
template class arm64_jit2<false>;
