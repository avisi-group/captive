#include <aarch64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::aarch64;
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_addi(const aarch64_decode_a64_ADD_SUB_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_48616_3_parameter_imm;
  auto DV_sym_48875_1__R_s_b_32_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_48631_1__R_s_b_0_5;
  auto DV_sym_48787_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48648_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48690_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_48713_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48766_1__R_s_b_11_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48839_1__R_s_b_30_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3700_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_3695_0_imm;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:18 [F] s_b_0_0=sym_3689_3_parameter_inst.imm12 (const) */
    /* execute.a64:18 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:18 [F] s_b_0_2=sym_3689_3_parameter_inst.shift (const) */
    /* execute.a64:18 [F] s_b_0_3: sym_48616_3_parameter_imm = s_b_0_1 (const), dominates: s_b_8_0 s_b_7_0  */
    CV_sym_48616_3_parameter_imm = ((uint32_t)insn.imm12);
    /* execute.a64:2762 [F] s_b_0_4 = constant s32 0 (const) */
    /* execute.a64:2765 [F] s_b_0_5 = constant s32 1 (const) */
    /* execute.a64:2761 [F] s_b_0_6: Switch s_b_0_2: < <todo> > def b_6 (const) -> b_8, b_6, b_7,  */
    switch (insn.shift) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_7;
      break;
    default:
      goto fixed_block_b_6;
    }
  }
  /* b_20,  */
  fixed_block_b_1: 
  {
    /* execute.a64:22 [F] s_b_1_0=sym_3689_3_parameter_inst.sf (const) */
    /* execute.a64:22 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:22 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.a64:22 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:22 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_5, b_13, b_14, b_15, b_21, b_22, b_23,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_20,  */
  fixed_block_b_3: 
  {
    /* execute.a64:28 [F] s_b_3_0=sym_3689_3_parameter_inst.sf (const) */
    /* execute.a64:28 [D] s_b_3_1 = sym_3700_0_op1 uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_3700_0_op1, emitter.context().types().u64());
    /* execute.a64:28 [F] s_b_3_2 = sym_3695_0_imm (const) uint64_t */
    uint64_t s_b_3_2 = CV_sym_3695_0_imm;
    /* execute.a64:28 [D] s_b_3_3 = s_b_3_1+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_1, emitter.const_u64(s_b_3_2));
    /* execute.a64:28 [D] s_b_3_4: sym_48648_3_parameter_value = s_b_3_3, dominates: s_b_10_0 s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_48648_3_parameter_value, s_b_3_3);
    /* execute.a64:2746 [F] s_b_3_5 = !s_b_3_0 (const) */
    uint8_t s_b_3_5 = !insn.sf;
    /* execute.a64:2746 [F] s_b_3_6: If s_b_3_5: Jump b_10 else b_11 (const) */
    if (s_b_3_5) 
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
    /* execute.a64:23 [F] s_b_4_0=sym_3689_3_parameter_inst.rd (const) */
    /* execute.a64:23 [D] s_b_4_1 = sym_3700_0_op1 uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_3700_0_op1, emitter.context().types().u64());
    /* execute.a64:23 [D] s_b_4_2 = (u32)s_b_4_1 */
    auto s_b_4_2 = emitter.truncate(s_b_4_1, emitter.context().types().u32());
    /* execute.a64:23 [F] s_b_4_3 = sym_3695_0_imm (const) uint64_t */
    uint64_t s_b_4_3 = CV_sym_3695_0_imm;
    /* execute.a64:23 [F] s_b_4_4 = (u32)s_b_4_3 (const) */
    /* execute.a64:23 [F] s_b_4_5 = constant u8 0 (const) */
    /* execute.a64:23 [D] s_b_4_6 = __builtin_adc32_flags */
    auto s_b_4_6 = emitter.adcf(s_b_4_2, emitter.const_u32(((uint32_t)s_b_4_3)), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:23 [D] s_b_4_7: sym_48690_3_parameter_value = s_b_4_6, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_48690_3_parameter_value, s_b_4_6);
    /* execute.a64:2674 [F] s_b_4_8 = (u32)s_b_4_0 (const) */
    /* execute.a64:2674 [F] s_b_4_9 = constant u32 1f (const) */
    /* execute.a64:2674 [F] s_b_4_10 = s_b_4_8==s_b_4_9 (const) */
    uint8_t s_b_4_10 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2674 [F] s_b_4_11: If s_b_4_10: Jump b_2 else b_14 (const) */
    if (s_b_4_10) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:25 [F] s_b_5_0=sym_3689_3_parameter_inst.rd (const) */
    /* execute.a64:25 [D] s_b_5_1 = sym_3700_0_op1 uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_3700_0_op1, emitter.context().types().u64());
    /* execute.a64:25 [F] s_b_5_2 = sym_3695_0_imm (const) uint64_t */
    uint64_t s_b_5_2 = CV_sym_3695_0_imm;
    /* execute.a64:25 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.a64:25 [D] s_b_5_4 = __builtin_adc64_flags */
    auto s_b_5_4 = emitter.adcf(s_b_5_1, emitter.const_u64(s_b_5_2), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:25 [D] s_b_5_5: sym_48713_3_parameter_value = s_b_5_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_48713_3_parameter_value, s_b_5_4);
    /* execute.a64:2682 [F] s_b_5_6 = (u32)s_b_5_0 (const) */
    /* execute.a64:2682 [F] s_b_5_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_5_8 = s_b_5_6==s_b_5_7 (const) */
    uint8_t s_b_5_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_5_9: If s_b_5_8: Jump b_2 else b_15 (const) */
    if (s_b_5_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2769 [F] s_b_6_0 = constant u64 0 (const) */
    /* execute.a64:2769 [F] s_b_6_1: sym_48631_1__R_s_b_0_5 = s_b_6_0 (const), dominates: s_b_9_0  */
    CV_sym_48631_1__R_s_b_0_5 = (uint64_t)0ULL;
    /* execute.a64:2769 [F] s_b_6_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2766 [F] s_b_7_0 = sym_48616_3_parameter_imm (const) uint32_t */
    uint32_t s_b_7_0 = CV_sym_48616_3_parameter_imm;
    /* execute.a64:2766 [F] s_b_7_1 = constant u32 c (const) */
    /* execute.a64:2766 [F] s_b_7_2 = s_b_7_0<<s_b_7_1 (const) */
    uint32_t s_b_7_2 = ((uint32_t)(s_b_7_0 << (uint32_t)12ULL));
    /* execute.a64:2766 [F] s_b_7_3 = (u64)s_b_7_2 (const) */
    /* execute.a64:2766 [F] s_b_7_4: sym_48631_1__R_s_b_0_5 = s_b_7_3 (const), dominates: s_b_9_0  */
    CV_sym_48631_1__R_s_b_0_5 = ((uint64_t)s_b_7_2);
    /* execute.a64:2766 [F] s_b_7_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2763 [F] s_b_8_0 = sym_48616_3_parameter_imm (const) uint32_t */
    uint32_t s_b_8_0 = CV_sym_48616_3_parameter_imm;
    /* execute.a64:2763 [F] s_b_8_1 = (u64)s_b_8_0 (const) */
    /* execute.a64:2763 [F] s_b_8_2: sym_48631_1__R_s_b_0_5 = s_b_8_1 (const), dominates: s_b_9_0  */
    CV_sym_48631_1__R_s_b_0_5 = ((uint64_t)s_b_8_0);
    /* execute.a64:2763 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6, b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:18 [F] s_b_9_0 = sym_48631_1__R_s_b_0_5 (const) uint64_t */
    uint64_t s_b_9_0 = CV_sym_48631_1__R_s_b_0_5;
    /* execute.a64:18 [F] s_b_9_1: sym_3695_0_imm = s_b_9_0 (const), dominates: s_b_4_3 s_b_5_2 s_b_3_2  */
    CV_sym_3695_0_imm = s_b_9_0;
    /* execute.a64:19 [F] s_b_9_2=sym_3689_3_parameter_inst.sf (const) */
    /* execute.a64:2729 [F] s_b_9_3: If s_b_9_2: Jump b_16 else b_17 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2747 [D] s_b_10_0 = sym_48648_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_48648_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_10_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_10_2 = s_b_10_0&s_b_10_1 */
    auto s_b_10_2 = emitter.bitwise_and(s_b_10_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_10_3: sym_48648_3_parameter_value = s_b_10_2, dominates: s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_48648_3_parameter_value, s_b_10_2);
    /* execute.a64:2747 [F] s_b_10_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2750 [F] s_b_11_0=sym_3689_3_parameter_inst.rd (const) */
    /* execute.a64:2750 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2750 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_11_4: If s_b_11_3: Jump b_12 else b_13 (const) */
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
    /* execute.a64:2751 [D] s_b_12_0 = sym_48648_3_parameter_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_48648_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_12_1: sym_48787_3_parameter_value = s_b_12_0, dominates: s_b_21_0 s_b_22_0 s_b_23_0  */
    emitter.store_local(DV_sym_48787_3_parameter_value, s_b_12_0);
    /* execute.a64:2714 [F] s_b_12_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_12_3 = __builtin_get_feature */
    uint32_t s_b_12_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(s_b_12_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_12_6: If s_b_12_5: Jump b_21 else b_34 (const) */
    if (s_b_12_5) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_34;
    }
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2753 [F] s_b_13_0=sym_3689_3_parameter_inst.rd (const) */
    /* execute.a64:2753 [D] s_b_13_1 = sym_48648_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_48648_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1);
    /* execute.a64:2753 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2676 [F] s_b_14_0=sym_3689_3_parameter_inst.rd (const) */
    /* execute.a64:2676 [D] s_b_14_1 = sym_48690_3_parameter_value uint32_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_48690_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2676 [D] s_b_14_2 = (u64)s_b_14_1 */
    auto s_b_14_2 = emitter.zx(s_b_14_1, emitter.context().types().u64());
    /* execute.a64:2676 [D] s_b_14_3: WriteRegBank 0:s_b_14_0 = s_b_14_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2684 [F] s_b_15_0=sym_3689_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_48713_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_48713_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1);
    /* execute.a64:0 [F] s_b_15_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2730 [F] s_b_16_0=sym_3689_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2730 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_16_4: If s_b_16_3: Jump b_24 else b_18 (const) */
    if (s_b_16_3) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_9,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2736 [F] s_b_17_0=sym_3689_3_parameter_inst.rn (const) */
    /* execute.a64:2736 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
    /* execute.a64:2736 [F] s_b_17_2 = constant u32 1f (const) */
    /* execute.a64:2736 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2736 [F] s_b_17_4: If s_b_17_3: Jump b_29 else b_19 (const) */
    if (s_b_17_3) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2733 [F] s_b_18_0=sym_3689_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_18_2: sym_48766_1__R_s_b_11_6 = s_b_18_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_48766_1__R_s_b_11_6, s_b_18_1);
    /* execute.a64:2733 [F] s_b_18_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_17,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2739 [F] s_b_19_0=sym_3689_3_parameter_inst.rn (const) */
    /* execute.a64:2739 [D] s_b_19_1 = ReadRegBank 1:s_b_19_0 (u32) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1,emitter.const_u8(4));
    }
    /* execute.a64:2739 [D] s_b_19_2 = (u64)s_b_19_1 */
    auto s_b_19_2 = emitter.zx(s_b_19_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_19_3: sym_48766_1__R_s_b_11_6 = s_b_19_2, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_48766_1__R_s_b_11_6, s_b_19_2);
    /* execute.a64:2739 [F] s_b_19_4: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_18, b_19, b_28, b_33,  */
  fixed_block_b_20: 
  {
    /* execute.a64:19 [D] s_b_20_0 = sym_48766_1__R_s_b_11_6 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_48766_1__R_s_b_11_6, emitter.context().types().u64());
    /* execute.a64:19 [D] s_b_20_1: sym_3700_0_op1 = s_b_20_0, dominates: s_b_4_1 s_b_5_1 s_b_3_1  */
    emitter.store_local(DV_sym_3700_0_op1, s_b_20_0);
    /* execute.a64:21 [F] s_b_20_2=sym_3689_3_parameter_inst.S (const) */
    /* execute.a64:21 [F] s_b_20_3: If s_b_20_2: Jump b_1 else b_3 (const) */
    if (insn.S) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_12,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2715 [D] s_b_21_0 = sym_48787_3_parameter_value uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_48787_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_21_1: WriteReg 20 = s_b_21_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_21_0);
    /* execute.a64:2715 [F] s_b_21_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_34,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2718 [D] s_b_22_0 = sym_48787_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_48787_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_22_1: WriteReg 20 = s_b_22_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_22_0);
    /* execute.a64:2718 [F] s_b_22_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_34,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2720 [D] s_b_23_0 = sym_48787_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_48787_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_23_1: WriteReg 21 = s_b_23_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_23_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_23_0);
    /* execute.a64:2720 [F] s_b_23_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_16,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2701 [F] s_b_24_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_24_1 = __builtin_get_feature */
    uint32_t s_b_24_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_24_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(s_b_24_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_24_4: If s_b_24_3: Jump b_25 else b_35 (const) */
    if (s_b_24_3) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_24,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2702 [D] s_b_25_0 = ReadReg 20 (u64) */
    auto s_b_25_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_25_1: sym_48839_1__R_s_b_30_0 = s_b_25_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_48839_1__R_s_b_30_0, s_b_25_0);
    /* execute.a64:2702 [F] s_b_25_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_35,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2705 [D] s_b_26_0 = ReadReg 20 (u64) */
    auto s_b_26_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_26_1: sym_48839_1__R_s_b_30_0 = s_b_26_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_48839_1__R_s_b_30_0, s_b_26_0);
    /* execute.a64:2705 [F] s_b_26_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_35,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2707 [D] s_b_27_0 = ReadReg 21 (u64) */
    auto s_b_27_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_27_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_27_1: sym_48839_1__R_s_b_30_0 = s_b_27_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_48839_1__R_s_b_30_0, s_b_27_0);
    /* execute.a64:2707 [F] s_b_27_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_25, b_26, b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2731 [D] s_b_28_0 = sym_48839_1__R_s_b_30_0 uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_48839_1__R_s_b_30_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_28_1: sym_48766_1__R_s_b_11_6 = s_b_28_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_48766_1__R_s_b_11_6, s_b_28_0);
    /* execute.a64:2731 [F] s_b_28_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_17,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2701 [F] s_b_29_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_29_1 = __builtin_get_feature */
    uint32_t s_b_29_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_29_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(s_b_29_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_29_4: If s_b_29_3: Jump b_30 else b_36 (const) */
    if (s_b_29_3) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_36;
    }
  }
  /* b_29,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2702 [D] s_b_30_0 = ReadReg 20 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_30_1: sym_48875_1__R_s_b_32_0 = s_b_30_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_48875_1__R_s_b_32_0, s_b_30_0);
    /* execute.a64:2702 [F] s_b_30_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_36,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2705 [D] s_b_31_0 = ReadReg 20 (u64) */
    auto s_b_31_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_31_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_31_1: sym_48875_1__R_s_b_32_0 = s_b_31_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_48875_1__R_s_b_32_0, s_b_31_0);
    /* execute.a64:2705 [F] s_b_31_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_36,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2707 [D] s_b_32_0 = ReadReg 21 (u64) */
    auto s_b_32_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_32_1: sym_48875_1__R_s_b_32_0 = s_b_32_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_48875_1__R_s_b_32_0, s_b_32_0);
    /* execute.a64:2707 [F] s_b_32_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_30, b_31, b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2737 [D] s_b_33_0 = sym_48875_1__R_s_b_32_0 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_48875_1__R_s_b_32_0, emitter.context().types().u64());
    /* execute.a64:2737 [D] s_b_33_1 = (u32)s_b_33_0 */
    auto s_b_33_1 = emitter.truncate(s_b_33_0, emitter.context().types().u32());
    /* execute.a64:2737 [D] s_b_33_2 = (u64)s_b_33_1 */
    auto s_b_33_2 = emitter.zx(s_b_33_1, emitter.context().types().u64());
    /* execute.a64:2737 [D] s_b_33_3: sym_48766_1__R_s_b_11_6 = s_b_33_2, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_48766_1__R_s_b_11_6, s_b_33_2);
    /* execute.a64:2737 [F] s_b_33_4: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_12,  */
  fixed_block_b_34: 
  {
    /* execute.a64:3012 [F] s_b_34_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_34_1 = __builtin_get_feature */
    uint32_t s_b_34_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_34_2 = (u8)s_b_34_1 (const) */
    /* execute.a64:2717 [F] s_b_34_3 = (u32)s_b_34_2 (const) */
    /* execute.a64:2717 [F] s_b_34_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_34_5 = s_b_34_3==s_b_34_4 (const) */
    uint8_t s_b_34_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_34_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_34_6: If s_b_34_5: Jump b_22 else b_23 (const) */
    if (s_b_34_5) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_24,  */
  fixed_block_b_35: 
  {
    /* execute.a64:3012 [F] s_b_35_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_35_1 = __builtin_get_feature */
    uint32_t s_b_35_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_35_2 = (u8)s_b_35_1 (const) */
    /* execute.a64:2704 [F] s_b_35_3 = (u32)s_b_35_2 (const) */
    /* execute.a64:2704 [F] s_b_35_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_35_5 = s_b_35_3==s_b_35_4 (const) */
    uint8_t s_b_35_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_35_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_35_6: If s_b_35_5: Jump b_26 else b_27 (const) */
    if (s_b_35_5) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_29,  */
  fixed_block_b_36: 
  {
    /* execute.a64:3012 [F] s_b_36_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_36_1 = __builtin_get_feature */
    uint32_t s_b_36_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_36_2 = (u8)s_b_36_1 (const) */
    /* execute.a64:2704 [F] s_b_36_3 = (u32)s_b_36_2 (const) */
    /* execute.a64:2704 [F] s_b_36_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_36_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_36_6: If s_b_36_5: Jump b_31 else b_32 (const) */
    if (s_b_36_5) 
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_asrv(const aarch64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_5984_0_amount = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_50899_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50787_1__R_s_b_2_6 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_50847_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50746_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50877_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2305 [F] s_b_0_0=sym_5979_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_4 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_6,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2307 [D] s_b_1_0 = sym_5984_0_amount uint8_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_5984_0_amount, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_1_2 = constant u64 3f (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_1&s_b_1_2 */
    auto s_b_1_3 = emitter.bitwise_and(s_b_1_1, emitter.const_u64((uint64_t)63ULL));
    /* execute.a64:2307 [D] s_b_1_4 = (u8)s_b_1_3 */
    auto s_b_1_4 = emitter.truncate(s_b_1_3, emitter.context().types().u8());
    /* execute.a64:2307 [D] s_b_1_5: sym_5984_0_amount = s_b_1_4, dominates: s_b_9_3  */
    emitter.store_local(DV_sym_5984_0_amount, s_b_1_4);
    /* execute.a64:2307 [F] s_b_1_6: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2312 [F] s_b_2_0=sym_5979_3_parameter_inst.sf (const) */
    /* execute.a64:2665 [F] s_b_2_1: If s_b_2_0: Jump b_7 else b_8 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_6,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2309 [D] s_b_3_0 = sym_5984_0_amount uint8_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_5984_0_amount, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_3_1 = (u64)s_b_3_0 */
    auto s_b_3_1 = emitter.zx(s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_3_2 = constant u64 1f (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_1&s_b_3_2 */
    auto s_b_3_3 = emitter.bitwise_and(s_b_3_1, emitter.const_u64((uint64_t)31ULL));
    /* execute.a64:2309 [D] s_b_3_4 = (u8)s_b_3_3 */
    auto s_b_3_4 = emitter.truncate(s_b_3_3, emitter.context().types().u8());
    /* execute.a64:2309 [D] s_b_3_5: sym_5984_0_amount = s_b_3_4, dominates: s_b_9_3  */
    emitter.store_local(DV_sym_5984_0_amount, s_b_3_4);
    /* execute.a64:2309 [F] s_b_3_6: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2657 [F] s_b_4_0=sym_5979_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2651 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_4_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_4_5 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_4_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2657 [D] s_b_4_7: sym_50746_1__R_s_b_0_4 = s_b_4_6, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_50746_1__R_s_b_0_4, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_5979_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2646 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_5_5 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_5_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_5_6: Select s_b_5_3 ? s_b_5_4 : s_b_5_5 */
    dbt::el::Value *s_b_5_6;
    s_b_5_6 = (s_b_5_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_5_5);
    /* execute.a64:2659 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_5_8: sym_50746_1__R_s_b_0_4 = s_b_5_7, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_50746_1__R_s_b_0_4, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2305 [D] s_b_6_0 = sym_50746_1__R_s_b_0_4 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_50746_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2305 [D] s_b_6_1 = (u8)s_b_6_0 */
    auto s_b_6_1 = emitter.truncate(s_b_6_0, emitter.context().types().u8());
    /* execute.a64:2305 [D] s_b_6_2: sym_5984_0_amount = s_b_6_1, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_5984_0_amount, s_b_6_1);
    /* execute.a64:2306 [F] s_b_6_3=sym_5979_3_parameter_inst.sf (const) */
    /* execute.a64:2306 [F] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_2,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2666 [F] s_b_7_0=sym_5979_3_parameter_inst.rn (const) */
    /* execute.a64:2666 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2666 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_7_4 = constant s64 0 (const) */
    /* execute.a64:2666 [F] s_b_7_5=sym_5979_3_parameter_inst.rn (const) */
    /* execute.a64:2666 [D] s_b_7_6 = ReadRegBank 0:s_b_7_5 (u64) */
    auto s_b_7_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_6,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_7_7 = (s64)s_b_7_6 */
    auto s_b_7_7 = emitter.reinterpret(s_b_7_6, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_7_8: Select s_b_7_3 ? s_b_7_4 : s_b_7_7 */
    dbt::el::Value *s_b_7_8;
    s_b_7_8 = (s_b_7_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_7_7);
    /* execute.a64:2666 [D] s_b_7_9: sym_50787_1__R_s_b_2_6 = s_b_7_8, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_50787_1__R_s_b_2_6, s_b_7_8);
    /* execute.a64:2666 [F] s_b_7_10: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2668 [F] s_b_8_0=sym_5979_3_parameter_inst.rn (const) */
    /* execute.a64:2668 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2668 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_8_4 = constant s64 0 (const) */
    /* execute.a64:2668 [F] s_b_8_5=sym_5979_3_parameter_inst.rn (const) */
    /* execute.a64:2668 [D] s_b_8_6 = ReadRegBank 1:s_b_8_5 (u32) */
    auto s_b_8_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_6,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_8_7 = (s32)s_b_8_6 */
    auto s_b_8_7 = emitter.reinterpret(s_b_8_6, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_8_8 = (s64)s_b_8_7 */
    auto s_b_8_8 = emitter.sx(s_b_8_7, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_8_9: Select s_b_8_3 ? s_b_8_4 : s_b_8_8 */
    dbt::el::Value *s_b_8_9;
    s_b_8_9 = (s_b_8_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_8_8);
    /* execute.a64:2668 [D] s_b_8_10: sym_50787_1__R_s_b_2_6 = s_b_8_9, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_50787_1__R_s_b_2_6, s_b_8_9);
    /* execute.a64:2668 [F] s_b_8_11: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [F] s_b_9_0=sym_5979_3_parameter_inst.sf (const) */
    /* execute.a64:2312 [D] s_b_9_1 = sym_50787_1__R_s_b_2_6 int64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_50787_1__R_s_b_2_6, emitter.context().types().s64());
    /* execute.a64:2312 [D] s_b_9_2 = (s64)s_b_9_1 */
    auto s_b_9_2 = (dbt::el::Value *)s_b_9_1;
    /* execute.a64:2312 [D] s_b_9_3 = sym_5984_0_amount uint8_t */
    auto s_b_9_3 = emitter.load_local(DV_sym_5984_0_amount, emitter.context().types().u8());
    /* execute.a64:2312 [D] s_b_9_4 = (u64)s_b_9_2 */
    auto s_b_9_4 = emitter.reinterpret(s_b_9_2, emitter.context().types().u64());
    /* execute.a64:2312 [D] s_b_9_5 = (u64)s_b_9_3 */
    auto s_b_9_5 = emitter.zx(s_b_9_3, emitter.context().types().u64());
    /* execute.a64:2312 [D] s_b_9_6 = s_b_9_4->>s_b_9_5 */
    auto s_b_9_6 = emitter.sar(s_b_9_4, s_b_9_5);
    /* execute.a64:2312 [D] s_b_9_7 = (u64)s_b_9_6 */
    auto s_b_9_7 = (dbt::el::Value *)s_b_9_6;
    /* execute.a64:2312 [D] s_b_9_8: sym_50847_3_parameter_value = s_b_9_7, dominates: s_b_10_1 s_b_11_1  */
    emitter.store_local(DV_sym_50847_3_parameter_value, s_b_9_7);
    /* execute.a64:2690 [F] s_b_9_9: If s_b_9_0: Jump b_10 else b_11 (const) */
    if (insn.sf) 
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
    /* execute.a64:2691 [F] s_b_10_0=sym_5979_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_10_1 = sym_50847_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_50847_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_10_2: sym_50877_3_parameter_value = s_b_10_1, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_50877_3_parameter_value, s_b_10_1);
    /* execute.a64:2682 [F] s_b_10_3 = (u32)s_b_10_0 (const) */
    /* execute.a64:2682 [F] s_b_10_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_10_6: If s_b_10_5: Jump b_12 else b_13 (const) */
    if (s_b_10_5) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2693 [F] s_b_11_0=sym_5979_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_11_1 = sym_50847_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_50847_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_2 = (u32)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_4: sym_50899_3_parameter_value = s_b_11_3, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_50899_3_parameter_value, s_b_11_3);
    /* execute.a64:2682 [F] s_b_11_5 = (u32)s_b_11_0 (const) */
    /* execute.a64:2682 [F] s_b_11_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_11_7 = s_b_11_5==s_b_11_6 (const) */
    uint8_t s_b_11_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_11_8: If s_b_11_7: Jump b_12 else b_14 (const) */
    if (s_b_11_7) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_10, b_11, b_13, b_14,  */
  fixed_block_b_12: 
  {
    /* ???:4294967295 [F] s_b_12_0: Return */
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2684 [F] s_b_13_0=sym_5979_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_13_1 = sym_50877_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_50877_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2684 [F] s_b_14_0=sym_5979_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_50899_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_50899_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_12 (const) */
    goto fixed_block_b_12;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_bif(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2347 [F] s_b_0_0=sym_6286_3_parameter_inst.Q (const) */
    /* execute.simd:2347 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
    if (insn.Q) 
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
    /* execute.simd:2355 [F] s_b_1_0=sym_6286_3_parameter_inst.rd (const) */
    /* execute.simd:6239 [D] s_b_1_1 = ReadRegBank 2:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:6240 [D] s_b_1_2 = ReadRegBank 3:s_b_1_0 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:2356 [F] s_b_1_3=sym_6286_3_parameter_inst.rn (const) */
    /* execute.simd:6239 [D] s_b_1_4 = ReadRegBank 2:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:6240 [D] s_b_1_5 = ReadRegBank 3:s_b_1_3 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.simd:2357 [F] s_b_1_6=sym_6286_3_parameter_inst.rm (const) */
    /* execute.simd:6239 [D] s_b_1_7 = ReadRegBank 2:s_b_1_6 (u64) */
    auto s_b_1_7 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_7,emitter.const_u8(8));
    }
    /* execute.simd:6240 [D] s_b_1_8 = ReadRegBank 3:s_b_1_6 (u64) */
    auto s_b_1_8 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_1_8,emitter.const_u8(8));
    }
    /* execute.simd:2359 [F] s_b_1_9=sym_6286_3_parameter_inst.rd (const) */
    /* execute.simd:2359 [D] s_b_1_10 = s_b_1_1^s_b_1_4 */
    auto s_b_1_10 = emitter.bitwise_xor(s_b_1_1, s_b_1_4);
    /* execute.simd:2359 [D] s_b_1_11 = ~s_b_1_7 */
    auto s_b_1_11 = emitter.bitwise_not(s_b_1_7);
    /* execute.simd:2359 [D] s_b_1_12 = s_b_1_10&s_b_1_11 */
    auto s_b_1_12 = emitter.bitwise_and(s_b_1_10, s_b_1_11);
    /* execute.simd:2359 [D] s_b_1_13 = s_b_1_1^s_b_1_12 */
    auto s_b_1_13 = emitter.bitwise_xor(s_b_1_1, s_b_1_12);
    /* execute.simd:2359 [D] s_b_1_14 = s_b_1_2^s_b_1_5 */
    auto s_b_1_14 = emitter.bitwise_xor(s_b_1_2, s_b_1_5);
    /* execute.simd:2359 [D] s_b_1_15 = ~s_b_1_8 */
    auto s_b_1_15 = emitter.bitwise_not(s_b_1_8);
    /* execute.simd:2359 [D] s_b_1_16 = s_b_1_14&s_b_1_15 */
    auto s_b_1_16 = emitter.bitwise_and(s_b_1_14, s_b_1_15);
    /* execute.simd:2359 [D] s_b_1_17 = s_b_1_2^s_b_1_16 */
    auto s_b_1_17 = emitter.bitwise_xor(s_b_1_2, s_b_1_16);
    /* execute.simd:6212 [D] s_b_1_18: WriteRegBank 2:s_b_1_9 = s_b_1_13 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13);
    /* execute.simd:6213 [D] s_b_1_19: WriteRegBank 3:s_b_1_9 = s_b_1_17 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_17,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_17);
    /* execute.simd:0 [F] s_b_1_20: Jump b_2 (const) */
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
    /* execute.simd:2365 [F] s_b_3_0=sym_6286_3_parameter_inst.rd (const) */
    /* execute.simd:6234 [D] s_b_3_1 = ReadRegBank 7:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:2366 [F] s_b_3_2=sym_6286_3_parameter_inst.rn (const) */
    /* execute.simd:6234 [D] s_b_3_3 = ReadRegBank 7:s_b_3_2 (u64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:2367 [F] s_b_3_4=sym_6286_3_parameter_inst.rm (const) */
    /* execute.simd:6234 [D] s_b_3_5 = ReadRegBank 7:s_b_3_4 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:2369 [F] s_b_3_6=sym_6286_3_parameter_inst.rd (const) */
    /* execute.simd:2369 [D] s_b_3_7 = s_b_3_1^s_b_3_3 */
    auto s_b_3_7 = emitter.bitwise_xor(s_b_3_1, s_b_3_3);
    /* execute.simd:2369 [D] s_b_3_8 = ~s_b_3_5 */
    auto s_b_3_8 = emitter.bitwise_not(s_b_3_5);
    /* execute.simd:2369 [D] s_b_3_9 = s_b_3_7&s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_7, s_b_3_8);
    /* execute.simd:2369 [D] s_b_3_10 = s_b_3_1^s_b_3_9 */
    auto s_b_3_10 = emitter.bitwise_xor(s_b_3_1, s_b_3_9);
    /* execute.simd:6205 [D] s_b_3_11: WriteRegBank 2:s_b_3_6 = s_b_3_10 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_10,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_10);
    /* execute.simd:6206 [F] s_b_3_12 = constant u64 0 (const) */
    /* execute.simd:6206 [F] s_b_3_13: WriteRegBank 3:s_b_3_6 = s_b_3_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_3_14: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ccmpr(const aarch64_decode_a64_COND_CMP_REG&insn, captive::arch::dbt::el::Emitter& emitter)
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
  uint8_t CV_sym_53994_0_state;
  auto DV_sym_53994_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_54107_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_54170_1__R_s_b_23_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_54082_1__R_s_b_0_2 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_6844_0_rm = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_6839_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2063 [F] s_b_0_0=sym_6821_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_53994_0_state = s_b_0_1 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_53994_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_53994_0_state, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2793 [F] s_b_0_3 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:2793 [F] s_b_0_5 = s_b_0_3>>s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(((uint32_t)insn.cond) >> (uint32_t)1ULL));
    /* execute.a64:2794 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.a64:2798 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.a64:2802 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.a64:2806 [F] s_b_0_9 = constant s32 3 (const) */
    /* execute.a64:2810 [F] s_b_0_10 = constant s32 4 (const) */
    /* execute.a64:2814 [F] s_b_0_11 = constant s32 5 (const) */
    /* execute.a64:2818 [F] s_b_0_12 = constant s32 6 (const) */
    /* execute.a64:2822 [F] s_b_0_13 = constant s32 7 (const) */
    /* execute.a64:2793 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_12, b_14, b_10, b_9, b_6, b_13, b_8, b_11, b_7,  */
    switch (s_b_0_5) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
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
    /* execute.a64:2828 [F] s_b_6_0=sym_6821_3_parameter_inst.cond (const) */
    /* execute.a64:2828 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2828 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_6_3 = s_b_6_1&s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_6_6=sym_6821_3_parameter_inst.cond (const) */
    /* execute.a64:2828 [F] s_b_6_7 = (u64)s_b_6_6 (const) */
    /* execute.a64:2828 [F] s_b_6_8 = constant u64 f (const) */
    /* execute.a64:2828 [F] s_b_6_9 = s_b_6_7!=s_b_6_8 (const) */
    uint8_t s_b_6_9 = ((uint8_t)(((uint64_t)insn.cond) != (uint64_t)15ULL));
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_6_11 = s_b_6_5!=s_b_6_10 (const) */
    uint8_t s_b_6_11 = ((uint8_t)(s_b_6_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_12 = s_b_6_9!=s_b_6_10 (const) */
    uint8_t s_b_6_12 = ((uint8_t)(s_b_6_9 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_13 = s_b_6_11&s_b_6_12 (const) */
    uint8_t s_b_6_13 = ((uint8_t)(s_b_6_11 & s_b_6_12));
    /* execute.a64:2828 [F] s_b_6_14: If s_b_6_13: Jump b_15 else b_16 (const) */
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
    /* execute.a64:2803 [D] s_b_7_0 = ReadReg 1 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2803 [D] s_b_7_1: sym_53994_0_state = s_b_7_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53994_0_state, s_b_7_0);
    /* execute.a64:0 [F] s_b_7_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2799 [D] s_b_8_0 = ReadReg 3 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2799 [D] s_b_8_1: sym_53994_0_state = s_b_8_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53994_0_state, s_b_8_0);
    /* execute.a64:0 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2795 [D] s_b_9_0 = ReadReg 2 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2795 [D] s_b_9_1: sym_53994_0_state = s_b_9_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53994_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2815 [D] s_b_10_0 = ReadReg 1 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_10_1 = ReadReg 4 (u8) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_10_1, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_10_2 = s_b_10_0==s_b_10_1 */
    auto s_b_10_2 = emitter.cmp_eq(s_b_10_0, s_b_10_1);
    /* execute.a64:2815 [D] s_b_10_3: sym_53994_0_state = s_b_10_2, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53994_0_state, s_b_10_2);
    /* execute.a64:0 [F] s_b_10_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2819 [D] s_b_11_0 = ReadReg 1 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_11_1 = ReadReg 4 (u8) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_11_1, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_11_2 = s_b_11_0==s_b_11_1 */
    auto s_b_11_2 = emitter.cmp_eq(s_b_11_0, s_b_11_1);
    /* execute.a64:2819 [D] s_b_11_3 = ReadReg 2 (u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_11_3, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_11_4 = !s_b_11_3 */
    auto s_b_11_4 = emitter.cmp_eq(s_b_11_3, emitter.const_u8(0));
    /* execute.a64:2819 [D] s_b_11_5 = s_b_11_2&s_b_11_4 */
    auto s_b_11_5 = emitter.bitwise_and(s_b_11_2, s_b_11_4);
    /* execute.a64:2819 [D] s_b_11_6: sym_53994_0_state = s_b_11_5, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53994_0_state, s_b_11_5);
    /* execute.a64:0 [F] s_b_11_7: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2811 [D] s_b_12_0 = ReadReg 3 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_12_1 = ReadReg 2 (u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_12_1, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_12_2 = !s_b_12_1 */
    auto s_b_12_2 = emitter.cmp_eq(s_b_12_1, emitter.const_u8(0));
    /* execute.a64:2811 [D] s_b_12_3 = s_b_12_0&s_b_12_2 */
    auto s_b_12_3 = emitter.bitwise_and(s_b_12_0, s_b_12_2);
    /* execute.a64:2811 [D] s_b_12_4: sym_53994_0_state = s_b_12_3, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53994_0_state, s_b_12_3);
    /* execute.a64:0 [F] s_b_12_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2823 [F] s_b_13_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_13_1: sym_53994_0_state = s_b_13_0 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_53994_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_53994_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_13_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2807 [D] s_b_14_0 = ReadReg 4 (u8) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_0, emitter.const_u8(1));
    }
    /* execute.a64:2807 [D] s_b_14_1: sym_53994_0_state = s_b_14_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53994_0_state, s_b_14_0);
    /* execute.a64:0 [F] s_b_14_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2829 [D] s_b_15_0 = sym_53994_0_state uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_53994_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_15_1 = !s_b_15_0 */
    auto s_b_15_1 = emitter.cmp_eq(s_b_15_0, emitter.const_u8(0));
    /* execute.a64:2829 [D] s_b_15_2: sym_54082_1__R_s_b_0_2 = s_b_15_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_54082_1__R_s_b_0_2, s_b_15_1);
    /* execute.a64:2829 [F] s_b_15_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2831 [D] s_b_16_0 = sym_53994_0_state uint8_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_53994_0_state, emitter.context().types().u8());
    /* execute.a64:2831 [D] s_b_16_1: sym_54082_1__R_s_b_0_2 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_54082_1__R_s_b_0_2, s_b_16_0);
    /* execute.a64:2831 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2063 [D] s_b_17_0 = sym_54082_1__R_s_b_0_2 uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_54082_1__R_s_b_0_2, emitter.context().types().u8());
    /* execute.a64:2064 [D] s_b_17_1 = (u32)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u32());
    /* execute.a64:2064 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.a64:2064 [D] s_b_17_3 = s_b_17_1!=s_b_17_2 */
    auto s_b_17_3 = emitter.cmp_ne(s_b_17_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2064 [D] s_b_17_4: If s_b_17_3: Jump b_1 else b_3 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_1;
        dynamic_block_queue.push(block_b_1);
        true_target = block;
      }
      dbt::el::Block *false_target;
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
        /* execute.a64:2065 [F] s_b_1_0=sym_6821_3_parameter_inst.sf (const) */
        /* execute.a64:2656 [F] s_b_1_1: If s_b_1_0: Jump b_18 else b_19 (const) */
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
        /* execute.a64:2074 [F] s_b_3_0=sym_6821_3_parameter_inst.nzcv (const) */
        /* execute.a64:2074 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.a64:2074 [F] s_b_3_2 = constant u32 8 (const) */
        /* execute.a64:2074 [F] s_b_3_3 = s_b_3_1&s_b_3_2 (const) */
        uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)8ULL));
        /* execute.a64:2074 [F] s_b_3_4 = constant u32 8 (const) */
        /* execute.a64:2074 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
        uint8_t s_b_3_5 = ((uint8_t)(s_b_3_3 == (uint32_t)8ULL));
        /* execute.a64:2074 [F] s_b_3_6: WriteReg 1 = s_b_3_5 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), emitter.const_u8(s_b_3_5), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1296), emitter.const_u8(s_b_3_5));
        /* execute.a64:2075 [F] s_b_3_7=sym_6821_3_parameter_inst.nzcv (const) */
        /* execute.a64:2075 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
        /* execute.a64:2075 [F] s_b_3_9 = constant u32 4 (const) */
        /* execute.a64:2075 [F] s_b_3_10 = s_b_3_8&s_b_3_9 (const) */
        uint32_t s_b_3_10 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)4ULL));
        /* execute.a64:2075 [F] s_b_3_11 = constant u32 4 (const) */
        /* execute.a64:2075 [F] s_b_3_12 = s_b_3_10==s_b_3_11 (const) */
        uint8_t s_b_3_12 = ((uint8_t)(s_b_3_10 == (uint32_t)4ULL));
        /* execute.a64:2075 [F] s_b_3_13: WriteReg 2 = s_b_3_12 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), emitter.const_u8(s_b_3_12), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1297), emitter.const_u8(s_b_3_12));
        /* execute.a64:2076 [F] s_b_3_14=sym_6821_3_parameter_inst.nzcv (const) */
        /* execute.a64:2076 [F] s_b_3_15 = (u32)s_b_3_14 (const) */
        /* execute.a64:2076 [F] s_b_3_16 = constant u32 2 (const) */
        /* execute.a64:2076 [F] s_b_3_17 = s_b_3_15&s_b_3_16 (const) */
        uint32_t s_b_3_17 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)2ULL));
        /* execute.a64:2076 [F] s_b_3_18 = constant u32 2 (const) */
        /* execute.a64:2076 [F] s_b_3_19 = s_b_3_17==s_b_3_18 (const) */
        uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 == (uint32_t)2ULL));
        /* execute.a64:2076 [F] s_b_3_20: WriteReg 3 = s_b_3_19 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8(s_b_3_19), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1298), emitter.const_u8(s_b_3_19));
        /* execute.a64:2077 [F] s_b_3_21=sym_6821_3_parameter_inst.nzcv (const) */
        /* execute.a64:2077 [F] s_b_3_22 = (u32)s_b_3_21 (const) */
        /* execute.a64:2077 [F] s_b_3_23 = constant u32 1 (const) */
        /* execute.a64:2077 [F] s_b_3_24 = s_b_3_22&s_b_3_23 (const) */
        uint32_t s_b_3_24 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)1ULL));
        /* execute.a64:2077 [F] s_b_3_25 = constant u32 1 (const) */
        /* execute.a64:2077 [F] s_b_3_26 = s_b_3_24==s_b_3_25 (const) */
        uint8_t s_b_3_26 = ((uint8_t)(s_b_3_24 == (uint32_t)1ULL));
        /* execute.a64:2077 [F] s_b_3_27: WriteReg 4 = s_b_3_26 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8(s_b_3_26), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1299), emitter.const_u8(s_b_3_26));
        /* execute.a64:2074 [F] s_b_3_28: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.a64:2069 [D] s_b_4_0 = sym_6839_0_rn uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_6839_0_rn, emitter.context().types().u64());
        /* execute.a64:2069 [D] s_b_4_1 = (u32)s_b_4_0 */
        auto s_b_4_1 = emitter.truncate(s_b_4_0, emitter.context().types().u32());
        /* execute.a64:2069 [D] s_b_4_2 = sym_6844_0_rm uint64_t */
        auto s_b_4_2 = emitter.load_local(DV_sym_6844_0_rm, emitter.context().types().u64());
        /* execute.a64:2069 [D] s_b_4_3 = (u32)s_b_4_2 */
        auto s_b_4_3 = emitter.truncate(s_b_4_2, emitter.context().types().u32());
        /* execute.a64:2069 [D] s_b_4_4 = ~s_b_4_3 */
        auto s_b_4_4 = emitter.bitwise_not(s_b_4_3);
        /* execute.a64:2069 [F] s_b_4_5 = constant u8 1 (const) */
        /* execute.a64:2069 [D] s_b_4_6 = __builtin_adc32_flags */
        auto s_b_4_6 = emitter.adcf(s_b_4_1, s_b_4_4, emitter.const_u8((uint8_t)1ULL));
        /* execute.a64:2069 [F] s_b_4_7: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2071 [D] s_b_5_0 = sym_6839_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_6839_0_rn, emitter.context().types().u64());
        /* execute.a64:2071 [D] s_b_5_1 = sym_6844_0_rm uint64_t */
        auto s_b_5_1 = emitter.load_local(DV_sym_6844_0_rm, emitter.context().types().u64());
        /* execute.a64:2071 [D] s_b_5_2 = ~s_b_5_1 */
        auto s_b_5_2 = emitter.bitwise_not(s_b_5_1);
        /* execute.a64:2071 [F] s_b_5_3 = constant u8 1 (const) */
        /* execute.a64:2071 [D] s_b_5_4 = __builtin_adc64_flags */
        auto s_b_5_4 = emitter.adcf(s_b_5_0, s_b_5_2, emitter.const_u8((uint8_t)1ULL));
        /* execute.a64:2071 [F] s_b_5_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2657 [F] s_b_18_0=sym_6821_3_parameter_inst.rn (const) */
        /* execute.a64:2651 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
        /* execute.a64:2651 [F] s_b_18_2 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
        uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_18_4 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_18_5 = ReadRegBank 0:s_b_18_0 (u64) */
        auto s_b_18_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_5,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_18_6: Select s_b_18_3 ? s_b_18_4 : s_b_18_5 */
        dbt::el::Value *s_b_18_6;
        s_b_18_6 = (s_b_18_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_18_5);
        /* execute.a64:2657 [D] s_b_18_7: sym_54107_1__R_s_b_1_4 = s_b_18_6, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_54107_1__R_s_b_1_4, s_b_18_6);
        /* execute.a64:2657 [F] s_b_18_8: Jump b_20 (const) */
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.a64:2659 [F] s_b_19_0=sym_6821_3_parameter_inst.rn (const) */
        /* execute.a64:2646 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.a64:2646 [F] s_b_19_2 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
        uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_19_4 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_19_5 = ReadRegBank 1:s_b_19_0 (u32) */
        auto s_b_19_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_5,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_19_6: Select s_b_19_3 ? s_b_19_4 : s_b_19_5 */
        dbt::el::Value *s_b_19_6;
        s_b_19_6 = (s_b_19_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_19_5);
        /* execute.a64:2659 [D] s_b_19_7 = (u64)s_b_19_6 */
        auto s_b_19_7 = emitter.zx(s_b_19_6, emitter.context().types().u64());
        /* execute.a64:2659 [D] s_b_19_8: sym_54107_1__R_s_b_1_4 = s_b_19_7, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_54107_1__R_s_b_1_4, s_b_19_7);
        /* execute.a64:2659 [F] s_b_19_9: Jump b_20 (const) */
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.a64:2065 [D] s_b_20_0 = sym_54107_1__R_s_b_1_4 uint64_t */
        auto s_b_20_0 = emitter.load_local(DV_sym_54107_1__R_s_b_1_4, emitter.context().types().u64());
        /* execute.a64:2065 [D] s_b_20_1: sym_6839_0_rn = s_b_20_0, dominates: s_b_4_0 s_b_5_0  */
        emitter.store_local(DV_sym_6839_0_rn, s_b_20_0);
        /* execute.a64:2066 [F] s_b_20_2=sym_6821_3_parameter_inst.sf (const) */
        /* execute.a64:2656 [F] s_b_20_3: If s_b_20_2: Jump b_21 else b_22 (const) */
        if (insn.sf) 
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
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.a64:2657 [F] s_b_21_0=sym_6821_3_parameter_inst.rm (const) */
        /* execute.a64:2651 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
        /* execute.a64:2651 [F] s_b_21_2 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
        uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_21_4 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_21_5 = ReadRegBank 0:s_b_21_0 (u64) */
        auto s_b_21_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_5,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_21_6: Select s_b_21_3 ? s_b_21_4 : s_b_21_5 */
        dbt::el::Value *s_b_21_6;
        s_b_21_6 = (s_b_21_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_21_5);
        /* execute.a64:2657 [D] s_b_21_7: sym_54170_1__R_s_b_23_6 = s_b_21_6, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_54170_1__R_s_b_23_6, s_b_21_6);
        /* execute.a64:2657 [F] s_b_21_8: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.a64:2659 [F] s_b_22_0=sym_6821_3_parameter_inst.rm (const) */
        /* execute.a64:2646 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
        /* execute.a64:2646 [F] s_b_22_2 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
        uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_22_4 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_22_5 = ReadRegBank 1:s_b_22_0 (u32) */
        auto s_b_22_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_5,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_22_6: Select s_b_22_3 ? s_b_22_4 : s_b_22_5 */
        dbt::el::Value *s_b_22_6;
        s_b_22_6 = (s_b_22_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_22_5);
        /* execute.a64:2659 [D] s_b_22_7 = (u64)s_b_22_6 */
        auto s_b_22_7 = emitter.zx(s_b_22_6, emitter.context().types().u64());
        /* execute.a64:2659 [D] s_b_22_8: sym_54170_1__R_s_b_23_6 = s_b_22_7, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_54170_1__R_s_b_23_6, s_b_22_7);
        /* execute.a64:2659 [F] s_b_22_9: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.a64:2066 [D] s_b_23_0 = sym_54170_1__R_s_b_23_6 uint64_t */
        auto s_b_23_0 = emitter.load_local(DV_sym_54170_1__R_s_b_23_6, emitter.context().types().u64());
        /* execute.a64:2066 [D] s_b_23_1: sym_6844_0_rm = s_b_23_0, dominates: s_b_4_2 s_b_5_1  */
        emitter.store_local(DV_sym_6844_0_rm, s_b_23_0);
        /* execute.a64:2068 [F] s_b_23_2=sym_6821_3_parameter_inst.sf (const) */
        /* execute.a64:2068 [F] s_b_23_3 = (u32)s_b_23_2 (const) */
        /* execute.a64:2068 [F] s_b_23_4 = constant u32 0 (const) */
        /* execute.a64:2068 [F] s_b_23_5 = s_b_23_3==s_b_23_4 (const) */
        uint8_t s_b_23_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
        /* execute.a64:2068 [F] s_b_23_6: If s_b_23_5: Jump b_4 else b_5 (const) */
        if (s_b_23_5) 
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_cmlt_zero(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_8 = emitter.context().create_block();
  auto block_b_9 = emitter.context().create_block();
  auto DV_sym_7971_0_rn = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1967 [F] s_b_0_0=sym_7962_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1967 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1968 [F] s_b_1_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:6234 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:1968 [D] s_b_1_2: sym_7971_0_rn = s_b_1_1, dominates: s_b_4_0 s_b_5_0  */
    emitter.store_local(DV_sym_7971_0_rn, s_b_1_1);
    /* execute.simd:1970 [F] s_b_1_3=sym_7962_3_parameter_inst.U (const) */
    /* execute.simd:1970 [F] s_b_1_4 = (u32)s_b_1_3 (const) */
    /* execute.simd:1970 [F] s_b_1_5 = constant u32 1 (const) */
    /* execute.simd:1970 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:1970 [F] s_b_1_7: If s_b_1_6: Jump b_4 else b_5 (const) */
    if (s_b_1_6) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1984 [F] s_b_3_0=sym_7962_3_parameter_inst.U (const) */
    /* execute.simd:1984 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:1984 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:1984 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:1984 [F] s_b_3_4: If s_b_3_3: Jump b_10 else b_11 (const) */
    if (s_b_3_3) 
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
    /* execute.simd:1971 [D] s_b_4_0 = sym_7971_0_rn uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_7971_0_rn, emitter.context().types().u64());
    /* execute.simd:1971 [D] s_b_4_1 = (s64)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s64());
    /* execute.simd:1971 [F] s_b_4_2 = constant s64 0 (const) */
    /* execute.simd:1971 [D] s_b_4_3 = s_b_4_1<=s_b_4_2 */
    auto s_b_4_3 = emitter.cmp_le(s_b_4_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:1971 [D] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_6;
        dynamic_block_queue.push(block_b_6);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_7;
        dynamic_block_queue.push(block_b_7);
        false_target = block;
      }
      emitter.branch(s_b_4_3, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:1977 [D] s_b_5_0 = sym_7971_0_rn uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_7971_0_rn, emitter.context().types().u64());
    /* execute.simd:1977 [D] s_b_5_1 = (s64)s_b_5_0 */
    auto s_b_5_1 = emitter.reinterpret(s_b_5_0, emitter.context().types().s64());
    /* execute.simd:1977 [F] s_b_5_2 = constant s64 0 (const) */
    /* execute.simd:1977 [D] s_b_5_3 = s_b_5_1<s_b_5_2 */
    auto s_b_5_3 = emitter.cmp_lt(s_b_5_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:1977 [D] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_8;
        dynamic_block_queue.push(block_b_8);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_9;
        dynamic_block_queue.push(block_b_9);
        false_target = block;
      }
      emitter.branch(s_b_5_3, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_6 not fully fixed
  // BLOCK b_7 not fully fixed
  // BLOCK b_8 not fully fixed
  // BLOCK b_9 not fully fixed
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:1985 [F] s_b_10_0=sym_7962_3_parameter_inst.arrangement (const) */
    /* execute.simd:1986 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.simd:1995 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.simd:2003 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.simd:2012 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.simd:2020 [F] s_b_10_5 = constant s32 4 (const) */
    /* execute.simd:2029 [F] s_b_10_6 = constant s32 5 (const) */
    /* execute.simd:2037 [F] s_b_10_7 = constant s32 6 (const) */
    /* execute.simd:1985 [F] s_b_10_8: Switch s_b_10_0: < <todo> > def b_19 (const) -> b_19, b_18, b_17, b_16, b_15, b_14, b_13, b_12,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    default:
      goto fixed_block_b_19;
    }
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:2051 [F] s_b_11_0=sym_7962_3_parameter_inst.arrangement (const) */
    /* execute.simd:2052 [F] s_b_11_1 = constant s32 0 (const) */
    /* execute.simd:2061 [F] s_b_11_2 = constant s32 1 (const) */
    /* execute.simd:2069 [F] s_b_11_3 = constant s32 2 (const) */
    /* execute.simd:2078 [F] s_b_11_4 = constant s32 3 (const) */
    /* execute.simd:2086 [F] s_b_11_5 = constant s32 4 (const) */
    /* execute.simd:2095 [F] s_b_11_6 = constant s32 5 (const) */
    /* execute.simd:2103 [F] s_b_11_7 = constant s32 6 (const) */
    /* execute.simd:2051 [F] s_b_11_8: Switch s_b_11_0: < <todo> > def b_27 (const) -> b_27, b_26, b_25, b_24, b_23, b_22, b_21, b_20,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_26;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_25;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_24;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_20;
      break;
    default:
      goto fixed_block_b_27;
    }
  }
  /* b_10,  */
  fixed_block_b_12: 
  {
    /* execute.simd:1987 [F] s_b_12_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:1987 [D] s_b_12_1 = ReadRegBank 15:s_b_12_0 (v8u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:1987 [D] s_b_12_2 = (v8s8)s_b_12_1 */
    auto s_b_12_2 = emitter.reinterpret(s_b_12_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_12_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:1989 [D] s_b_12_4 = s_b_12_2<=s_b_12_3 */
    auto s_b_12_4 = emitter.cmp_le(s_b_12_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:1989 [D] s_b_12_5 = (v8u8)s_b_12_4 */
    auto s_b_12_5 = emitter.reinterpret(s_b_12_4, emitter.context().types().v8u8());
    /* execute.simd:1990 [F] s_b_12_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:1990 [D] s_b_12_7: WriteRegBank 15:s_b_12_6 = s_b_12_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5);
    /* execute.simd:1991 [F] s_b_12_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:1991 [F] s_b_12_9 = constant u64 0 (const) */
    /* execute.simd:1991 [F] s_b_12_10: WriteRegBank 3:s_b_12_8 = s_b_12_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_12_11: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.simd:1996 [F] s_b_13_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:1996 [D] s_b_13_1 = ReadRegBank 16:s_b_13_0 (v16u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_13_1,emitter.const_u8(16));
    }
    /* execute.simd:1996 [D] s_b_13_2 = (v16s8)s_b_13_1 */
    auto s_b_13_2 = emitter.reinterpret(s_b_13_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_13_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:1998 [D] s_b_13_4 = s_b_13_2<=s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_le(s_b_13_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:1998 [D] s_b_13_5 = (v16u8)s_b_13_4 */
    auto s_b_13_5 = emitter.reinterpret(s_b_13_4, emitter.context().types().v16u8());
    /* execute.simd:1999 [F] s_b_13_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:1999 [D] s_b_13_7: WriteRegBank 16:s_b_13_6 = s_b_13_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_5);
    /* execute.simd:0 [F] s_b_13_8: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.simd:2004 [F] s_b_14_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2004 [D] s_b_14_1 = ReadRegBank 17:s_b_14_0 (v4u16) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.simd:2004 [D] s_b_14_2 = (v4s16)s_b_14_1 */
    auto s_b_14_2 = emitter.reinterpret(s_b_14_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_14_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:2006 [D] s_b_14_4 = s_b_14_2<=s_b_14_3 */
    auto s_b_14_4 = emitter.cmp_le(s_b_14_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:2006 [D] s_b_14_5 = (v4u16)s_b_14_4 */
    auto s_b_14_5 = emitter.reinterpret(s_b_14_4, emitter.context().types().v4u16());
    /* execute.simd:2007 [F] s_b_14_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2007 [D] s_b_14_7: WriteRegBank 17:s_b_14_6 = s_b_14_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5);
    /* execute.simd:2008 [F] s_b_14_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2008 [F] s_b_14_9 = constant u64 0 (const) */
    /* execute.simd:2008 [F] s_b_14_10: WriteRegBank 3:s_b_14_8 = s_b_14_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_14_11: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_15: 
  {
    /* execute.simd:2013 [F] s_b_15_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2013 [D] s_b_15_1 = ReadRegBank 18:s_b_15_0 (v8u16) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_15_1,emitter.const_u8(16));
    }
    /* execute.simd:2013 [D] s_b_15_2 = (v8s16)s_b_15_1 */
    auto s_b_15_2 = emitter.reinterpret(s_b_15_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_15_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:2015 [D] s_b_15_4 = s_b_15_2<=s_b_15_3 */
    auto s_b_15_4 = emitter.cmp_le(s_b_15_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:2015 [D] s_b_15_5 = (v8u16)s_b_15_4 */
    auto s_b_15_5 = emitter.reinterpret(s_b_15_4, emitter.context().types().v8u16());
    /* execute.simd:2017 [F] s_b_15_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2017 [D] s_b_15_7: WriteRegBank 18:s_b_15_6 = s_b_15_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_15_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_15_5);
    /* execute.simd:0 [F] s_b_15_8: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_16: 
  {
    /* execute.simd:2021 [F] s_b_16_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2021 [D] s_b_16_1 = ReadRegBank 19:s_b_16_0 (v2u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:2021 [D] s_b_16_2 = (v2s32)s_b_16_1 */
    auto s_b_16_2 = emitter.reinterpret(s_b_16_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_16_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:2023 [D] s_b_16_4 = s_b_16_2<=s_b_16_3 */
    auto s_b_16_4 = emitter.cmp_le(s_b_16_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:2023 [D] s_b_16_5 = (v2u32)s_b_16_4 */
    auto s_b_16_5 = emitter.reinterpret(s_b_16_4, emitter.context().types().v2u32());
    /* execute.simd:2024 [F] s_b_16_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2024 [D] s_b_16_7: WriteRegBank 19:s_b_16_6 = s_b_16_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5);
    /* execute.simd:2025 [F] s_b_16_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2025 [F] s_b_16_9 = constant u64 0 (const) */
    /* execute.simd:2025 [F] s_b_16_10: WriteRegBank 3:s_b_16_8 = s_b_16_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_16_11: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_17: 
  {
    /* execute.simd:2030 [F] s_b_17_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2030 [D] s_b_17_1 = ReadRegBank 20:s_b_17_0 (v4u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:2030 [D] s_b_17_2 = (v4s32)s_b_17_1 */
    auto s_b_17_2 = emitter.reinterpret(s_b_17_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_17_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:2032 [D] s_b_17_4 = s_b_17_2<=s_b_17_3 */
    auto s_b_17_4 = emitter.cmp_le(s_b_17_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:2032 [D] s_b_17_5 = (v4u32)s_b_17_4 */
    auto s_b_17_5 = emitter.reinterpret(s_b_17_4, emitter.context().types().v4u32());
    /* execute.simd:2034 [F] s_b_17_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2034 [D] s_b_17_7: WriteRegBank 20:s_b_17_6 = s_b_17_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_17_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_17_5);
    /* execute.simd:0 [F] s_b_17_8: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_18: 
  {
    /* execute.simd:2038 [F] s_b_18_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2038 [D] s_b_18_1 = ReadRegBank 21:s_b_18_0 (v2u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_18_1,emitter.const_u8(16));
    }
    /* execute.simd:2038 [D] s_b_18_2 = (v2s64)s_b_18_1 */
    auto s_b_18_2 = emitter.reinterpret(s_b_18_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_18_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:2040 [D] s_b_18_4 = s_b_18_2<=s_b_18_3 */
    auto s_b_18_4 = emitter.cmp_le(s_b_18_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:2040 [D] s_b_18_5 = (v2u64)s_b_18_4 */
    auto s_b_18_5 = emitter.reinterpret(s_b_18_4, emitter.context().types().v2u64());
    /* execute.simd:2042 [F] s_b_18_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2042 [D] s_b_18_7: WriteRegBank 21:s_b_18_6 = s_b_18_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_18_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_18_5);
    /* execute.simd:0 [F] s_b_18_8: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_19: 
  {
    /* execute.simd:2046 [D] s_b_19_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_19_1: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_11,  */
  fixed_block_b_20: 
  {
    /* execute.simd:2053 [F] s_b_20_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2053 [D] s_b_20_1 = ReadRegBank 15:s_b_20_0 (v8u8) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:2053 [D] s_b_20_2 = (v8s8)s_b_20_1 */
    auto s_b_20_2 = emitter.reinterpret(s_b_20_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_20_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:2055 [D] s_b_20_4 = s_b_20_2<s_b_20_3 */
    auto s_b_20_4 = emitter.cmp_lt(s_b_20_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:2055 [D] s_b_20_5 = (v8u8)s_b_20_4 */
    auto s_b_20_5 = emitter.reinterpret(s_b_20_4, emitter.context().types().v8u8());
    /* execute.simd:2056 [F] s_b_20_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2056 [D] s_b_20_7: WriteRegBank 15:s_b_20_6 = s_b_20_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5);
    /* execute.simd:2057 [F] s_b_20_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2057 [F] s_b_20_9 = constant u64 0 (const) */
    /* execute.simd:2057 [F] s_b_20_10: WriteRegBank 3:s_b_20_8 = s_b_20_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_20_11: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_11,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2062 [F] s_b_21_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2062 [D] s_b_21_1 = ReadRegBank 16:s_b_21_0 (v16u8) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:2062 [D] s_b_21_2 = (v16s8)s_b_21_1 */
    auto s_b_21_2 = emitter.reinterpret(s_b_21_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_21_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:2064 [D] s_b_21_4 = s_b_21_2<s_b_21_3 */
    auto s_b_21_4 = emitter.cmp_lt(s_b_21_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:2064 [D] s_b_21_5 = (v16u8)s_b_21_4 */
    auto s_b_21_5 = emitter.reinterpret(s_b_21_4, emitter.context().types().v16u8());
    /* execute.simd:2065 [F] s_b_21_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2065 [D] s_b_21_7: WriteRegBank 16:s_b_21_6 = s_b_21_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_21_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_21_5);
    /* execute.simd:0 [F] s_b_21_8: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_11,  */
  fixed_block_b_22: 
  {
    /* execute.simd:2070 [F] s_b_22_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2070 [D] s_b_22_1 = ReadRegBank 17:s_b_22_0 (v4u16) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:2070 [D] s_b_22_2 = (v4s16)s_b_22_1 */
    auto s_b_22_2 = emitter.reinterpret(s_b_22_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_22_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:2072 [D] s_b_22_4 = s_b_22_2<s_b_22_3 */
    auto s_b_22_4 = emitter.cmp_lt(s_b_22_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:2072 [D] s_b_22_5 = (v4u16)s_b_22_4 */
    auto s_b_22_5 = emitter.reinterpret(s_b_22_4, emitter.context().types().v4u16());
    /* execute.simd:2073 [F] s_b_22_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2073 [D] s_b_22_7: WriteRegBank 17:s_b_22_6 = s_b_22_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5);
    /* execute.simd:2074 [F] s_b_22_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2074 [F] s_b_22_9 = constant u64 0 (const) */
    /* execute.simd:2074 [F] s_b_22_10: WriteRegBank 3:s_b_22_8 = s_b_22_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_22_11: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_11,  */
  fixed_block_b_23: 
  {
    /* execute.simd:2079 [F] s_b_23_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2079 [D] s_b_23_1 = ReadRegBank 18:s_b_23_0 (v8u16) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:2079 [D] s_b_23_2 = (v8s16)s_b_23_1 */
    auto s_b_23_2 = emitter.reinterpret(s_b_23_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_23_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:2081 [D] s_b_23_4 = s_b_23_2<s_b_23_3 */
    auto s_b_23_4 = emitter.cmp_lt(s_b_23_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:2081 [D] s_b_23_5 = (v8u16)s_b_23_4 */
    auto s_b_23_5 = emitter.reinterpret(s_b_23_4, emitter.context().types().v8u16());
    /* execute.simd:2083 [F] s_b_23_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2083 [D] s_b_23_7: WriteRegBank 18:s_b_23_6 = s_b_23_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_23_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_23_5);
    /* execute.simd:0 [F] s_b_23_8: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_11,  */
  fixed_block_b_24: 
  {
    /* execute.simd:2087 [F] s_b_24_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2087 [D] s_b_24_1 = ReadRegBank 19:s_b_24_0 (v2u32) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_24_1,emitter.const_u8(8));
    }
    /* execute.simd:2087 [D] s_b_24_2 = (v2s32)s_b_24_1 */
    auto s_b_24_2 = emitter.reinterpret(s_b_24_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_24_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:2089 [D] s_b_24_4 = s_b_24_2<s_b_24_3 */
    auto s_b_24_4 = emitter.cmp_lt(s_b_24_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:2089 [D] s_b_24_5 = (v2u32)s_b_24_4 */
    auto s_b_24_5 = emitter.reinterpret(s_b_24_4, emitter.context().types().v2u32());
    /* execute.simd:2090 [F] s_b_24_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2090 [D] s_b_24_7: WriteRegBank 19:s_b_24_6 = s_b_24_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5);
    /* execute.simd:2091 [F] s_b_24_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2091 [F] s_b_24_9 = constant u64 0 (const) */
    /* execute.simd:2091 [F] s_b_24_10: WriteRegBank 3:s_b_24_8 = s_b_24_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_24_11: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_11,  */
  fixed_block_b_25: 
  {
    /* execute.simd:2096 [F] s_b_25_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2096 [D] s_b_25_1 = ReadRegBank 20:s_b_25_0 (v4u32) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_25_1,emitter.const_u8(16));
    }
    /* execute.simd:2096 [D] s_b_25_2 = (v4s32)s_b_25_1 */
    auto s_b_25_2 = emitter.reinterpret(s_b_25_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_25_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:2098 [D] s_b_25_4 = s_b_25_2<s_b_25_3 */
    auto s_b_25_4 = emitter.cmp_lt(s_b_25_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:2098 [D] s_b_25_5 = (v4u32)s_b_25_4 */
    auto s_b_25_5 = emitter.reinterpret(s_b_25_4, emitter.context().types().v4u32());
    /* execute.simd:2100 [F] s_b_25_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2100 [D] s_b_25_7: WriteRegBank 20:s_b_25_6 = s_b_25_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_25_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_25_5);
    /* execute.simd:0 [F] s_b_25_8: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_11,  */
  fixed_block_b_26: 
  {
    /* execute.simd:2104 [F] s_b_26_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2104 [D] s_b_26_1 = ReadRegBank 21:s_b_26_0 (v2u64) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_26_1,emitter.const_u8(16));
    }
    /* execute.simd:2104 [D] s_b_26_2 = (v2s64)s_b_26_1 */
    auto s_b_26_2 = emitter.reinterpret(s_b_26_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_26_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:2106 [D] s_b_26_4 = s_b_26_2<s_b_26_3 */
    auto s_b_26_4 = emitter.cmp_lt(s_b_26_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:2106 [D] s_b_26_5 = (v2u64)s_b_26_4 */
    auto s_b_26_5 = emitter.reinterpret(s_b_26_4, emitter.context().types().v2u64());
    /* execute.simd:2108 [F] s_b_26_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2108 [D] s_b_26_7: WriteRegBank 21:s_b_26_6 = s_b_26_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_26_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_26_5);
    /* execute.simd:0 [F] s_b_26_8: Jump b_2 (const) */
    {
      auto block = block_b_2;
      dynamic_block_queue.push(block_b_2);
      emitter.jump(block);
    }
    goto fixed_done;
  }
  /* b_11,  */
  fixed_block_b_27: 
  {
    /* execute.simd:2112 [D] s_b_27_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_27_1: Jump b_2 (const) */
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
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:1972 [F] s_b_6_0=sym_7962_3_parameter_inst.rd (const) */
        /* execute.simd:1972 [F] s_b_6_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6205 [F] s_b_6_2: WriteRegBank 2:s_b_6_0 = s_b_6_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6206 [F] s_b_6_3 = constant u64 0 (const) */
        /* execute.simd:6206 [F] s_b_6_4: WriteRegBank 3:s_b_6_0 = s_b_6_3 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_6_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.simd:1974 [F] s_b_7_0=sym_7962_3_parameter_inst.rd (const) */
        /* execute.simd:1974 [F] s_b_7_1 = constant u64 0 (const) */
        /* execute.simd:6205 [F] s_b_7_2: WriteRegBank 2:s_b_7_0 = s_b_7_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6206 [F] s_b_7_3 = constant u64 0 (const) */
        /* execute.simd:6206 [F] s_b_7_4: WriteRegBank 3:s_b_7_0 = s_b_7_3 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_7_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.simd:1978 [F] s_b_8_0=sym_7962_3_parameter_inst.rd (const) */
        /* execute.simd:1978 [F] s_b_8_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6205 [F] s_b_8_2: WriteRegBank 2:s_b_8_0 = s_b_8_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6206 [F] s_b_8_3 = constant u64 0 (const) */
        /* execute.simd:6206 [F] s_b_8_4: WriteRegBank 3:s_b_8_0 = s_b_8_3 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_8_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.simd:1980 [F] s_b_9_0=sym_7962_3_parameter_inst.rd (const) */
        /* execute.simd:1980 [F] s_b_9_1 = constant u64 0 (const) */
        /* execute.simd:6205 [F] s_b_9_2: WriteRegBank 2:s_b_9_0 = s_b_9_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6206 [F] s_b_9_3 = constant u64 0 (const) */
        /* execute.simd:6206 [F] s_b_9_4: WriteRegBank 3:s_b_9_0 = s_b_9_3 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_9_5: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_csneg(const aarch64_decode_a64_COND_SEL&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
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
  auto DV_sym_56937_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56915_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56893_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56871_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56686_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56777_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  uint8_t CV_sym_56592_0_state;
  auto DV_sym_56592_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_56635_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_56717_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56841_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2139 [F] s_b_0_0=sym_9067_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_56592_0_state = s_b_0_1 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_56592_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_56592_0_state, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2793 [F] s_b_0_3 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:2793 [F] s_b_0_5 = s_b_0_3>>s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(((uint32_t)insn.cond) >> (uint32_t)1ULL));
    /* execute.a64:2794 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.a64:2798 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.a64:2802 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.a64:2806 [F] s_b_0_9 = constant s32 3 (const) */
    /* execute.a64:2810 [F] s_b_0_10 = constant s32 4 (const) */
    /* execute.a64:2814 [F] s_b_0_11 = constant s32 5 (const) */
    /* execute.a64:2818 [F] s_b_0_12 = constant s32 6 (const) */
    /* execute.a64:2822 [F] s_b_0_13 = constant s32 7 (const) */
    /* execute.a64:2793 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_4 (const) -> b_4, b_7, b_8, b_9, b_10, b_11, b_12, b_13, b_14,  */
    switch (s_b_0_5) 
    {
    case (int32_t)5ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    default:
      goto fixed_block_b_4;
    }
  }
  // BLOCK b_1 not fully fixed
  // BLOCK b_2 not fully fixed
  // BLOCK b_3 not fully fixed
  /* b_0, b_7, b_8, b_9, b_10, b_11, b_12, b_13, b_14,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2828 [F] s_b_4_0=sym_9067_3_parameter_inst.cond (const) */
    /* execute.a64:2828 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2828 [F] s_b_4_2 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_4_3 = s_b_4_1&s_b_4_2 (const) */
    uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_4_4 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_4_5 = s_b_4_3==s_b_4_4 (const) */
    uint8_t s_b_4_5 = ((uint8_t)(s_b_4_3 == (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_4_6 = (u64)s_b_4_0 (const) */
    /* execute.a64:2828 [F] s_b_4_7 = constant u64 f (const) */
    /* execute.a64:2828 [F] s_b_4_8 = s_b_4_6!=s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint64_t)insn.cond) != (uint64_t)15ULL));
    /* ???:4294967295 [F] s_b_4_9 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_4_10 = s_b_4_5!=s_b_4_9 (const) */
    uint8_t s_b_4_10 = ((uint8_t)(s_b_4_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_11 = s_b_4_8!=s_b_4_9 (const) */
    uint8_t s_b_4_11 = ((uint8_t)(s_b_4_8 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_12 = s_b_4_10&s_b_4_11 (const) */
    uint8_t s_b_4_12 = ((uint8_t)(s_b_4_10 & s_b_4_11));
    /* execute.a64:2828 [F] s_b_4_13: If s_b_4_12: Jump b_5 else b_6 (const) */
    if (s_b_4_12) 
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
    /* execute.a64:2829 [D] s_b_5_0 = sym_56592_0_state uint8_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_56592_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_5_1 = !s_b_5_0 */
    auto s_b_5_1 = emitter.cmp_eq(s_b_5_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_5_2: sym_56635_0_return_symbol = s_b_5_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_56635_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2831 [D] s_b_6_0 = sym_56592_0_state uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_56592_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_6_1: sym_56635_0_return_symbol = s_b_6_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_56635_0_return_symbol, s_b_6_0);
    /* ???:4294967295 [F] s_b_6_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2795 [D] s_b_7_0 = ReadReg 2 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2795 [D] s_b_7_1: sym_56592_0_state = s_b_7_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56592_0_state, s_b_7_0);
    /* execute.a64:0 [F] s_b_7_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2799 [D] s_b_8_0 = ReadReg 3 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2799 [D] s_b_8_1: sym_56592_0_state = s_b_8_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56592_0_state, s_b_8_0);
    /* execute.a64:0 [F] s_b_8_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2803 [D] s_b_9_0 = ReadReg 1 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2803 [D] s_b_9_1: sym_56592_0_state = s_b_9_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56592_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2807 [D] s_b_10_0 = ReadReg 4 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2807 [D] s_b_10_1: sym_56592_0_state = s_b_10_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56592_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2811 [D] s_b_11_0 = ReadReg 3 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_11_1 = ReadReg 2 (u8) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_11_1, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_11_2 = !s_b_11_1 */
    auto s_b_11_2 = emitter.cmp_eq(s_b_11_1, emitter.const_u8(0));
    /* execute.a64:2811 [D] s_b_11_3 = s_b_11_0&s_b_11_2 */
    auto s_b_11_3 = emitter.bitwise_and(s_b_11_0, s_b_11_2);
    /* execute.a64:2811 [D] s_b_11_4: sym_56592_0_state = s_b_11_3, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56592_0_state, s_b_11_3);
    /* execute.a64:0 [F] s_b_11_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2815 [D] s_b_12_0 = ReadReg 1 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_12_1 = ReadReg 4 (u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_12_1, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_12_2 = s_b_12_0==s_b_12_1 */
    auto s_b_12_2 = emitter.cmp_eq(s_b_12_0, s_b_12_1);
    /* execute.a64:2815 [D] s_b_12_3: sym_56592_0_state = s_b_12_2, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56592_0_state, s_b_12_2);
    /* execute.a64:0 [F] s_b_12_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2819 [D] s_b_13_0 = ReadReg 1 (u8) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_1 = ReadReg 4 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_13_1, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_2 = s_b_13_0==s_b_13_1 */
    auto s_b_13_2 = emitter.cmp_eq(s_b_13_0, s_b_13_1);
    /* execute.a64:2819 [D] s_b_13_3 = ReadReg 2 (u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_13_3, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_4 = !s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_eq(s_b_13_3, emitter.const_u8(0));
    /* execute.a64:2819 [D] s_b_13_5 = s_b_13_2&s_b_13_4 */
    auto s_b_13_5 = emitter.bitwise_and(s_b_13_2, s_b_13_4);
    /* execute.a64:2819 [D] s_b_13_6: sym_56592_0_state = s_b_13_5, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56592_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2823 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_14_1: sym_56592_0_state = s_b_14_0 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_56592_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_56592_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5, b_6,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_56635_0_return_symbol uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_56635_0_return_symbol, emitter.context().types().u8());
    /* execute.a64:2141 [D] s_b_15_1 = (u32)s_b_15_0 */
    auto s_b_15_1 = emitter.zx(s_b_15_0, emitter.context().types().u32());
    /* execute.a64:2141 [F] s_b_15_2 = constant u32 0 (const) */
    /* execute.a64:2141 [D] s_b_15_3 = s_b_15_1==s_b_15_2 */
    auto s_b_15_3 = emitter.cmp_eq(s_b_15_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2141 [D] s_b_15_4: If s_b_15_3: Jump b_1 else b_3 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_1;
        dynamic_block_queue.push(block_b_1);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_3;
        dynamic_block_queue.push(block_b_3);
        false_target = block;
      }
      emitter.branch(s_b_15_3, true_target, false_target);
    }
    goto fixed_done;
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
        /* execute.a64:2142 [F] s_b_1_0=sym_9067_3_parameter_inst.sf (const) */
        /* execute.a64:2656 [F] s_b_1_1: If s_b_1_0: Jump b_16 else b_17 (const) */
        if (insn.sf) 
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
      else if (block_index == block_b_2) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_2);
        /* ???:4294967295 [F] s_b_2_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_3) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_3);
        /* execute.a64:2144 [F] s_b_3_0=sym_9067_3_parameter_inst.sf (const) */
        /* execute.a64:2656 [F] s_b_3_1: If s_b_3_0: Jump b_19 else b_20 (const) */
        if (insn.sf) 
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.a64:2657 [F] s_b_16_0=sym_9067_3_parameter_inst.rm (const) */
        /* execute.a64:2651 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
        /* execute.a64:2651 [F] s_b_16_2 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
        uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_16_4 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_16_5 = ReadRegBank 0:s_b_16_0 (u64) */
        auto s_b_16_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_16_5,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_16_6: Select s_b_16_3 ? s_b_16_4 : s_b_16_5 */
        dbt::el::Value *s_b_16_6;
        s_b_16_6 = (s_b_16_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_16_5);
        /* execute.a64:2657 [D] s_b_16_7: sym_56686_1__R_s_b_1_6 = s_b_16_6, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_56686_1__R_s_b_1_6, s_b_16_6);
        /* execute.a64:2657 [F] s_b_16_8: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.a64:2659 [F] s_b_17_0=sym_9067_3_parameter_inst.rm (const) */
        /* execute.a64:2646 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
        /* execute.a64:2646 [F] s_b_17_2 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
        uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_17_4 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_17_5 = ReadRegBank 1:s_b_17_0 (u32) */
        auto s_b_17_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_17_5,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_17_6: Select s_b_17_3 ? s_b_17_4 : s_b_17_5 */
        dbt::el::Value *s_b_17_6;
        s_b_17_6 = (s_b_17_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_17_5);
        /* execute.a64:2659 [D] s_b_17_7 = (u64)s_b_17_6 */
        auto s_b_17_7 = emitter.zx(s_b_17_6, emitter.context().types().u64());
        /* execute.a64:2659 [D] s_b_17_8: sym_56686_1__R_s_b_1_6 = s_b_17_7, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_56686_1__R_s_b_1_6, s_b_17_7);
        /* execute.a64:2659 [F] s_b_17_9: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* ???:4294967295 [F] s_b_18_0=sym_9067_3_parameter_inst.sf (const) */
        /* execute.a64:2142 [D] s_b_18_1 = sym_56686_1__R_s_b_1_6 uint64_t */
        auto s_b_18_1 = emitter.load_local(DV_sym_56686_1__R_s_b_1_6, emitter.context().types().u64());
        /* execute.a64:2142 [D] s_b_18_2 = ~s_b_18_1 */
        auto s_b_18_2 = emitter.bitwise_not(s_b_18_1);
        /* execute.a64:2142 [F] s_b_18_3 = constant u64 1 (const) */
        /* execute.a64:2142 [D] s_b_18_4 = s_b_18_2+s_b_18_3 */
        auto s_b_18_4 = emitter.add(s_b_18_2, emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:2142 [D] s_b_18_5: sym_56777_3_parameter_value = s_b_18_4, dominates: s_b_22_1 s_b_23_1  */
        emitter.store_local(DV_sym_56777_3_parameter_value, s_b_18_4);
        /* execute.a64:2690 [F] s_b_18_6: If s_b_18_0: Jump b_22 else b_23 (const) */
        if (insn.sf) 
        {
          auto block = block_b_22;
          dynamic_block_queue.push(block_b_22);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.a64:2657 [F] s_b_19_0=sym_9067_3_parameter_inst.rn (const) */
        /* execute.a64:2651 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.a64:2651 [F] s_b_19_2 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
        uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_19_4 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_19_5 = ReadRegBank 0:s_b_19_0 (u64) */
        auto s_b_19_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_5,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_19_6: Select s_b_19_3 ? s_b_19_4 : s_b_19_5 */
        dbt::el::Value *s_b_19_6;
        s_b_19_6 = (s_b_19_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_19_5);
        /* execute.a64:2657 [D] s_b_19_7: sym_56717_1__R_s_b_3_6 = s_b_19_6, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_56717_1__R_s_b_3_6, s_b_19_6);
        /* execute.a64:2657 [F] s_b_19_8: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.a64:2659 [F] s_b_20_0=sym_9067_3_parameter_inst.rn (const) */
        /* execute.a64:2646 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
        /* execute.a64:2646 [F] s_b_20_2 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
        uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_20_4 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_20_5 = ReadRegBank 1:s_b_20_0 (u32) */
        auto s_b_20_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_5,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_20_6: Select s_b_20_3 ? s_b_20_4 : s_b_20_5 */
        dbt::el::Value *s_b_20_6;
        s_b_20_6 = (s_b_20_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_20_5);
        /* execute.a64:2659 [D] s_b_20_7 = (u64)s_b_20_6 */
        auto s_b_20_7 = emitter.zx(s_b_20_6, emitter.context().types().u64());
        /* execute.a64:2659 [D] s_b_20_8: sym_56717_1__R_s_b_3_6 = s_b_20_7, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_56717_1__R_s_b_3_6, s_b_20_7);
        /* execute.a64:2659 [F] s_b_20_9: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* ???:4294967295 [F] s_b_21_0=sym_9067_3_parameter_inst.sf (const) */
        /* execute.a64:2144 [D] s_b_21_1 = sym_56717_1__R_s_b_3_6 uint64_t */
        auto s_b_21_1 = emitter.load_local(DV_sym_56717_1__R_s_b_3_6, emitter.context().types().u64());
        /* execute.a64:2144 [D] s_b_21_2: sym_56841_3_parameter_value = s_b_21_1, dominates: s_b_24_1 s_b_25_1  */
        emitter.store_local(DV_sym_56841_3_parameter_value, s_b_21_1);
        /* execute.a64:2690 [F] s_b_21_3: If s_b_21_0: Jump b_24 else b_25 (const) */
        if (insn.sf) 
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
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.a64:2691 [F] s_b_22_0=sym_9067_3_parameter_inst.rd (const) */
        /* execute.a64:2691 [D] s_b_22_1 = sym_56777_3_parameter_value uint64_t */
        auto s_b_22_1 = emitter.load_local(DV_sym_56777_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_22_2: sym_56871_3_parameter_value = s_b_22_1, dominates: s_b_26_1  */
        emitter.store_local(DV_sym_56871_3_parameter_value, s_b_22_1);
        /* execute.a64:2682 [F] s_b_22_3 = (u32)s_b_22_0 (const) */
        /* execute.a64:2682 [F] s_b_22_4 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_22_5 = s_b_22_3==s_b_22_4 (const) */
        uint8_t s_b_22_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_22_6: If s_b_22_5: Jump b_2 else b_26 (const) */
        if (s_b_22_5) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.a64:2693 [F] s_b_23_0=sym_9067_3_parameter_inst.rd (const) */
        /* execute.a64:2693 [D] s_b_23_1 = sym_56777_3_parameter_value uint64_t */
        auto s_b_23_1 = emitter.load_local(DV_sym_56777_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_23_2 = (u32)s_b_23_1 */
        auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_23_3 = (u64)s_b_23_2 */
        auto s_b_23_3 = emitter.zx(s_b_23_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_23_4: sym_56893_3_parameter_value = s_b_23_3, dominates: s_b_27_1  */
        emitter.store_local(DV_sym_56893_3_parameter_value, s_b_23_3);
        /* execute.a64:2682 [F] s_b_23_5 = (u32)s_b_23_0 (const) */
        /* execute.a64:2682 [F] s_b_23_6 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_23_7 = s_b_23_5==s_b_23_6 (const) */
        uint8_t s_b_23_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_23_8: If s_b_23_7: Jump b_2 else b_27 (const) */
        if (s_b_23_7) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.a64:2691 [F] s_b_24_0=sym_9067_3_parameter_inst.rd (const) */
        /* execute.a64:2691 [D] s_b_24_1 = sym_56841_3_parameter_value uint64_t */
        auto s_b_24_1 = emitter.load_local(DV_sym_56841_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_24_2: sym_56915_3_parameter_value = s_b_24_1, dominates: s_b_28_1  */
        emitter.store_local(DV_sym_56915_3_parameter_value, s_b_24_1);
        /* execute.a64:2682 [F] s_b_24_3 = (u32)s_b_24_0 (const) */
        /* execute.a64:2682 [F] s_b_24_4 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_24_5 = s_b_24_3==s_b_24_4 (const) */
        uint8_t s_b_24_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_24_6: If s_b_24_5: Jump b_2 else b_28 (const) */
        if (s_b_24_5) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_28;
          dynamic_block_queue.push(block_b_28);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.a64:2693 [F] s_b_25_0=sym_9067_3_parameter_inst.rd (const) */
        /* execute.a64:2693 [D] s_b_25_1 = sym_56841_3_parameter_value uint64_t */
        auto s_b_25_1 = emitter.load_local(DV_sym_56841_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_25_2 = (u32)s_b_25_1 */
        auto s_b_25_2 = emitter.truncate(s_b_25_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_25_3 = (u64)s_b_25_2 */
        auto s_b_25_3 = emitter.zx(s_b_25_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_25_4: sym_56937_3_parameter_value = s_b_25_3, dominates: s_b_29_1  */
        emitter.store_local(DV_sym_56937_3_parameter_value, s_b_25_3);
        /* execute.a64:2682 [F] s_b_25_5 = (u32)s_b_25_0 (const) */
        /* execute.a64:2682 [F] s_b_25_6 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_25_7 = s_b_25_5==s_b_25_6 (const) */
        uint8_t s_b_25_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_25_8: If s_b_25_7: Jump b_2 else b_29 (const) */
        if (s_b_25_7) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.a64:2684 [F] s_b_26_0=sym_9067_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_26_1 = sym_56871_3_parameter_value uint64_t */
        auto s_b_26_1 = emitter.load_local(DV_sym_56871_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1);
        /* execute.a64:0 [F] s_b_26_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.a64:2684 [F] s_b_27_0=sym_9067_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_27_1 = sym_56893_3_parameter_value uint64_t */
        auto s_b_27_1 = emitter.load_local(DV_sym_56893_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_27_2: WriteRegBank 0:s_b_27_0 = s_b_27_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_27_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_27_1);
        /* execute.a64:0 [F] s_b_27_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.a64:2684 [F] s_b_28_0=sym_9067_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_28_1 = sym_56915_3_parameter_value uint64_t */
        auto s_b_28_1 = emitter.load_local(DV_sym_56915_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_28_2: WriteRegBank 0:s_b_28_0 = s_b_28_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_28_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_28_1);
        /* execute.a64:0 [F] s_b_28_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.a64:2684 [F] s_b_29_0=sym_9067_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_29_1 = sym_56937_3_parameter_value uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_56937_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_29_2: WriteRegBank 0:s_b_29_0 = s_b_29_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_29_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_29_1);
        /* execute.a64:0 [F] s_b_29_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_exgen(const aarch64_decode_a64_EX_GEN&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  emitter.mark_used_feature(4);
  emitter.mark_used_feature(5);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_58493_0_spsr = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_58441_0_parameter_voff;
  auto DV_sym_58439_0_parameter_retaddr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_58437_0_parameter_syndrome;
  auto DV_sym_58563_0_spsr = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_58664_3_parameter_syndrome;
  uint64_t CV_sym_58575_3_parameter_voff;
  auto DV_sym_58613_3_parameter_retaddr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:315 [F] s_b_0_0=sym_10068_3_parameter_inst.opc (const) */
    /* execute.a64:315 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:315 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.a64:315 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:315 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.a64:316 [F] s_b_1_0=sym_10068_3_parameter_inst.imm16 (const) */
    /* execute.a64:2870 [D] s_b_1_1 = read_pc */
    auto s_b_1_1 = emitter.load_pc();
    /* execute.a64:2871 [F] s_b_1_2 = constant u64 0 (const) */
    /* execute.a64:2873 [F] s_b_1_3 = constant u8 1 (const) */
    /* execute.a64:2873 [F] s_b_1_4 = (u32)s_b_1_0 (const) */
    /* execute.a64:2873 [F] s_b_1_5: sym_58664_3_parameter_syndrome = s_b_1_4 (const), dominates: s_b_21_10  */
    CV_sym_58664_3_parameter_syndrome = ((uint32_t)insn.imm16);
    /* execute.a64:2873 [D] s_b_1_6: sym_58613_3_parameter_retaddr = s_b_1_1, dominates: s_b_21_8  */
    emitter.store_local(DV_sym_58613_3_parameter_retaddr, s_b_1_1);
    /* execute.a64:2873 [F] s_b_1_7: sym_58575_3_parameter_voff = s_b_1_2 (const), dominates: s_b_19_0 s_b_22_0 s_b_21_27  */
    CV_sym_58575_3_parameter_voff = (uint64_t)0ULL;
    /* execute.a64:2837 [D] s_b_1_8 = ReadReg 1 (u8) */
    auto s_b_1_8 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_1_8, emitter.const_u8(1));
    }
    /* execute.a64:2837 [D] s_b_1_9 = (u32)s_b_1_8 */
    auto s_b_1_9 = emitter.zx(s_b_1_8, emitter.context().types().u32());
    /* execute.a64:2837 [F] s_b_1_10 = constant u32 1f (const) */
    /* execute.a64:2837 [D] s_b_1_11 = s_b_1_9<<s_b_1_10 */
    auto s_b_1_11 = emitter.shl(s_b_1_9, emitter.const_u32((uint32_t)31ULL));
    /* execute.a64:2838 [D] s_b_1_12 = ReadReg 2 (u8) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_1_12, emitter.const_u8(1));
    }
    /* execute.a64:2838 [D] s_b_1_13 = (u32)s_b_1_12 */
    auto s_b_1_13 = emitter.zx(s_b_1_12, emitter.context().types().u32());
    /* execute.a64:2838 [F] s_b_1_14 = constant u32 1e (const) */
    /* execute.a64:2838 [D] s_b_1_15 = s_b_1_13<<s_b_1_14 */
    auto s_b_1_15 = emitter.shl(s_b_1_13, emitter.const_u32((uint32_t)30ULL));
    /* execute.a64:2837 [D] s_b_1_16 = s_b_1_11|s_b_1_15 */
    auto s_b_1_16 = emitter.bitwise_or(s_b_1_11, s_b_1_15);
    /* execute.a64:2839 [D] s_b_1_17 = ReadReg 3 (u8) */
    auto s_b_1_17 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_1_17, emitter.const_u8(1));
    }
    /* execute.a64:2839 [D] s_b_1_18 = (u32)s_b_1_17 */
    auto s_b_1_18 = emitter.zx(s_b_1_17, emitter.context().types().u32());
    /* execute.a64:2839 [F] s_b_1_19 = constant u32 1d (const) */
    /* execute.a64:2839 [D] s_b_1_20 = s_b_1_18<<s_b_1_19 */
    auto s_b_1_20 = emitter.shl(s_b_1_18, emitter.const_u32((uint32_t)29ULL));
    /* execute.a64:2838 [D] s_b_1_21 = s_b_1_16|s_b_1_20 */
    auto s_b_1_21 = emitter.bitwise_or(s_b_1_16, s_b_1_20);
    /* execute.a64:2840 [D] s_b_1_22 = ReadReg 4 (u8) */
    auto s_b_1_22 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_1_22, emitter.const_u8(1));
    }
    /* execute.a64:2840 [D] s_b_1_23 = (u32)s_b_1_22 */
    auto s_b_1_23 = emitter.zx(s_b_1_22, emitter.context().types().u32());
    /* execute.a64:2840 [F] s_b_1_24 = constant u32 1c (const) */
    /* execute.a64:2840 [D] s_b_1_25 = s_b_1_23<<s_b_1_24 */
    auto s_b_1_25 = emitter.shl(s_b_1_23, emitter.const_u32((uint32_t)28ULL));
    /* execute.a64:2839 [D] s_b_1_26 = s_b_1_21|s_b_1_25 */
    auto s_b_1_26 = emitter.bitwise_or(s_b_1_21, s_b_1_25);
    /* execute.a64:2841 [D] s_b_1_27 = ReadReg 5 (u8) */
    auto s_b_1_27 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_1_27, emitter.const_u8(1));
    }
    /* execute.a64:2841 [D] s_b_1_28 = (u32)s_b_1_27 */
    auto s_b_1_28 = emitter.zx(s_b_1_27, emitter.context().types().u32());
    /* execute.a64:2841 [F] s_b_1_29 = constant u32 9 (const) */
    /* execute.a64:2841 [D] s_b_1_30 = s_b_1_28<<s_b_1_29 */
    auto s_b_1_30 = emitter.shl(s_b_1_28, emitter.const_u32((uint32_t)9ULL));
    /* execute.a64:2840 [D] s_b_1_31 = s_b_1_26|s_b_1_30 */
    auto s_b_1_31 = emitter.bitwise_or(s_b_1_26, s_b_1_30);
    /* execute.a64:2842 [D] s_b_1_32 = ReadReg 6 (u8) */
    auto s_b_1_32 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_1_32, emitter.const_u8(1));
    }
    /* execute.a64:2842 [D] s_b_1_33 = (u32)s_b_1_32 */
    auto s_b_1_33 = emitter.zx(s_b_1_32, emitter.context().types().u32());
    /* execute.a64:2842 [F] s_b_1_34 = constant u32 8 (const) */
    /* execute.a64:2842 [D] s_b_1_35 = s_b_1_33<<s_b_1_34 */
    auto s_b_1_35 = emitter.shl(s_b_1_33, emitter.const_u32((uint32_t)8ULL));
    /* execute.a64:2841 [D] s_b_1_36 = s_b_1_31|s_b_1_35 */
    auto s_b_1_36 = emitter.bitwise_or(s_b_1_31, s_b_1_35);
    /* execute.a64:2843 [D] s_b_1_37 = ReadReg 7 (u8) */
    auto s_b_1_37 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_1_37, emitter.const_u8(1));
    }
    /* execute.a64:2843 [D] s_b_1_38 = (u32)s_b_1_37 */
    auto s_b_1_38 = emitter.zx(s_b_1_37, emitter.context().types().u32());
    /* execute.a64:2843 [F] s_b_1_39 = constant u32 7 (const) */
    /* execute.a64:2843 [D] s_b_1_40 = s_b_1_38<<s_b_1_39 */
    auto s_b_1_40 = emitter.shl(s_b_1_38, emitter.const_u32((uint32_t)7ULL));
    /* execute.a64:2842 [D] s_b_1_41 = s_b_1_36|s_b_1_40 */
    auto s_b_1_41 = emitter.bitwise_or(s_b_1_36, s_b_1_40);
    /* execute.a64:2844 [D] s_b_1_42 = ReadReg 8 (u8) */
    auto s_b_1_42 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_1_42, emitter.const_u8(1));
    }
    /* execute.a64:2844 [D] s_b_1_43 = (u32)s_b_1_42 */
    auto s_b_1_43 = emitter.zx(s_b_1_42, emitter.context().types().u32());
    /* execute.a64:2844 [F] s_b_1_44 = constant u32 6 (const) */
    /* execute.a64:2844 [D] s_b_1_45 = s_b_1_43<<s_b_1_44 */
    auto s_b_1_45 = emitter.shl(s_b_1_43, emitter.const_u32((uint32_t)6ULL));
    /* execute.a64:2843 [D] s_b_1_46 = s_b_1_41|s_b_1_45 */
    auto s_b_1_46 = emitter.bitwise_or(s_b_1_41, s_b_1_45);
    /* execute.a64:3012 [F] s_b_1_47 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_1_48 = __builtin_get_feature */
    uint32_t s_b_1_48 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_1_49 = (u8)s_b_1_48 (const) */
    /* execute.a64:2845 [F] s_b_1_50 = (u32)s_b_1_49 (const) */
    /* execute.a64:2845 [F] s_b_1_51 = constant u32 2 (const) */
    /* execute.a64:2845 [F] s_b_1_52 = s_b_1_50<<s_b_1_51 (const) */
    uint32_t s_b_1_52 = ((uint32_t)(((uint32_t)((uint8_t)s_b_1_48)) << (uint32_t)2ULL));
    /* execute.a64:2844 [D] s_b_1_53 = s_b_1_46|s_b_1_52 */
    auto s_b_1_53 = emitter.bitwise_or(s_b_1_46, emitter.const_u32(s_b_1_52));
    /* execute.a64:2846 [F] s_b_1_54 = constant u32 1 (const) */
    /* execute.a64:2846 [F] s_b_1_55 = __builtin_get_feature */
    uint32_t s_b_1_55 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2846 [F] s_b_1_56 = (u32)s_b_1_55 (const) */
    /* execute.a64:2845 [D] s_b_1_57 = s_b_1_53|s_b_1_56 */
    auto s_b_1_57 = emitter.bitwise_or(s_b_1_53, emitter.const_u32(((uint32_t)s_b_1_55)));
    /* execute.a64:2959 [D] s_b_1_58: sym_58563_0_spsr = s_b_1_57, dominates: s_b_21_6  */
    emitter.store_local(DV_sym_58563_0_spsr, s_b_1_57);
    /* execute.a64:3012 [F] s_b_1_59 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_1_60 = __builtin_get_feature */
    uint32_t s_b_1_60 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_1_61 = (u8)s_b_1_60 (const) */
    /* execute.a64:2962 [F] s_b_1_62 = s_b_1_3>s_b_1_61 (const) */
    uint8_t s_b_1_62 = ((uint8_t)((uint8_t)1ULL > ((uint8_t)s_b_1_60)));
    /* execute.a64:2962 [F] s_b_1_63: If s_b_1_62: Jump b_19 else b_20 (const) */
    if (s_b_1_62) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_6, b_8, b_9, b_10, b_11, b_13, b_17, b_21,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:317 [F] s_b_3_0=sym_10068_3_parameter_inst.opc (const) */
    /* execute.a64:317 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:317 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:317 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:317 [F] s_b_3_4=sym_10068_3_parameter_inst.ll (const) */
    /* execute.a64:317 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:317 [F] s_b_3_6 = constant u32 1 (const) */
    /* execute.a64:317 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.ll) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:317 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2879 [F] s_b_4_0 = constant u32 4 (const) */
    /* execute.a64:2879 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)4ULL);
    /* execute.a64:2879 [F] s_b_4_2: If s_b_4_1: Jump b_11 else b_12 (const) */
    if (s_b_4_1) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:319 [F] s_b_5_0=sym_10068_3_parameter_inst.opc (const) */
    /* execute.a64:319 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:319 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:319 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:319 [F] s_b_5_4=sym_10068_3_parameter_inst.ll (const) */
    /* execute.a64:319 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:319 [F] s_b_5_6 = constant u32 3 (const) */
    /* execute.a64:319 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.ll) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:319 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:320 [F] s_b_6_0 = constant u32 11 (const) */
    /* execute.a64:320 [F] s_b_6_1 = constant u32 0 (const) */
    /* execute.a64:320 [F] s_b_6_2 = constant u64 0 (const) */
    /* ???:4294967295 [D] s_b_6_3 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)17ULL), emitter.const_u32((uint32_t)0ULL), emitter.const_u64((uint64_t)0ULL));
    }
    emitter.store_device(emitter.const_u32((uint32_t)17ULL), emitter.const_u32((uint32_t)0ULL), emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:321 [D] s_b_6_4 = read_pc */
    auto s_b_6_4 = emitter.load_pc();
    /* execute.a64:321 [F] s_b_6_5 = constant u64 4 (const) */
    /* execute.a64:321 [D] s_b_6_6 = s_b_6_4+s_b_6_5 */
    auto s_b_6_6 = emitter.add(s_b_6_4, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:321 [D] s_b_6_7 = write_pc */
    emitter.store_pc(s_b_6_6);
    /* execute.a64:320 [F] s_b_6_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:322 [F] s_b_7_0=sym_10068_3_parameter_inst.opc (const) */
    /* execute.a64:322 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:322 [F] s_b_7_2 = constant u32 2 (const) */
    /* execute.a64:322 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:322 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
    if (s_b_7_3) 
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
    /* execute.a64:323 [F] s_b_8_0=sym_10068_3_parameter_inst.imm16 (const) */
    /* execute.a64:323 [F] s_b_8_1 = (u64)s_b_8_0 (const) */
    /* execute.a64:323 [F] s_b_8_2 = constant u64 f000 (const) */
    /* execute.a64:323 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint64_t)insn.imm16) == (uint64_t)61440ULL));
    /* execute.a64:323 [F] s_b_8_4: If s_b_8_3: Jump b_10 else b_2 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:328 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:328 [F] s_b_9_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:324 [F] s_b_10_0 = constant u32 13 (const) */
    /* execute.a64:324 [F] s_b_10_1 = constant u32 0 (const) */
    /* execute.a64:324 [F] s_b_10_2 = constant u64 0 (const) */
    /* ???:4294967295 [D] s_b_10_3 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)0ULL), emitter.const_u64((uint64_t)0ULL));
    }
    emitter.store_device(emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)0ULL), emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:325 [D] s_b_10_4 = read_pc */
    auto s_b_10_4 = emitter.load_pc();
    /* execute.a64:325 [F] s_b_10_5 = constant u64 4 (const) */
    /* execute.a64:325 [D] s_b_10_6 = s_b_10_4+s_b_10_5 */
    auto s_b_10_6 = emitter.add(s_b_10_4, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:325 [D] s_b_10_7 = write_pc */
    emitter.store_pc(s_b_10_6);
    /* execute.a64:324 [F] s_b_10_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2880 [F] s_b_11_0=sym_10068_3_parameter_inst.imm16 (const) */
    /* execute.a64:2880 [F] s_b_11_1 = constant u32 13 (const) */
    /* execute.a64:2880 [F] s_b_11_2 = constant u32 1 (const) */
    /* execute.a64:2880 [F] s_b_11_3 = (u64)s_b_11_0 (const) */
    /* ???:4294967295 [D] s_b_11_4 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)1ULL), emitter.const_u64(((uint64_t)insn.imm16)));
    }
    emitter.store_device(emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)1ULL), emitter.const_u64(((uint64_t)insn.imm16)));
    /* execute.a64:2881 [D] s_b_11_5 = read_pc */
    auto s_b_11_5 = emitter.load_pc();
    /* execute.a64:2881 [F] s_b_11_6 = constant u64 4 (const) */
    /* execute.a64:2881 [D] s_b_11_7 = s_b_11_5+s_b_11_6 */
    auto s_b_11_7 = emitter.add(s_b_11_5, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2881 [D] s_b_11_8 = write_pc */
    emitter.store_pc(s_b_11_7);
    /* execute.a64:2880 [F] s_b_11_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2882 [F] s_b_12_0 = constant u32 5 (const) */
    /* execute.a64:2882 [F] s_b_12_1 = __builtin_get_feature */
    uint32_t s_b_12_1 = __get_feature((uint32_t)5ULL);
    /* execute.a64:2882 [F] s_b_12_2: If s_b_12_1: Jump b_13 else b_14 (const) */
    if (s_b_12_1) 
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
    /* execute.a64:2883 [F] s_b_13_0 = constant u32 3 (const) */
    /* execute.a64:2883 [F] s_b_13_1=sym_10068_3_parameter_inst.imm16 (const) */
    /* execute.a64:2883 [F] s_b_13_2 = (u32)s_b_13_1 (const) */
    /* execute.a64:2883 [D] s_b_13_3 = take_exception */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2884 [D] s_b_13_4 = read_pc */
    auto s_b_13_4 = emitter.load_pc();
    /* execute.a64:2884 [F] s_b_13_5 = constant u64 4 (const) */
    /* execute.a64:2884 [D] s_b_13_6 = s_b_13_4+s_b_13_5 */
    auto s_b_13_6 = emitter.add(s_b_13_4, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2884 [D] s_b_13_7 = write_pc */
    emitter.store_pc(s_b_13_6);
    /* execute.a64:2883 [F] s_b_13_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2886 [D] s_b_14_0 = read_pc */
    auto s_b_14_0 = emitter.load_pc();
    /* execute.a64:2886 [F] s_b_14_1 = constant u64 4 (const) */
    /* execute.a64:2886 [D] s_b_14_2 = s_b_14_0+s_b_14_1 */
    auto s_b_14_2 = emitter.add(s_b_14_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2887 [F] s_b_14_3 = constant u64 0 (const) */
    /* execute.a64:2889 [F] s_b_14_4 = constant u8 1 (const) */
    /* execute.a64:2889 [F] s_b_14_5=sym_10068_3_parameter_inst.imm16 (const) */
    /* execute.a64:2889 [F] s_b_14_6 = (u32)s_b_14_5 (const) */
    /* execute.a64:2889 [F] s_b_14_7: sym_58437_0_parameter_syndrome = s_b_14_6 (const), dominates: s_b_17_10  */
    CV_sym_58437_0_parameter_syndrome = ((uint32_t)insn.imm16);
    /* execute.a64:2889 [D] s_b_14_8: sym_58439_0_parameter_retaddr = s_b_14_2, dominates: s_b_17_8  */
    emitter.store_local(DV_sym_58439_0_parameter_retaddr, s_b_14_2);
    /* execute.a64:2889 [F] s_b_14_9: sym_58441_0_parameter_voff = s_b_14_3 (const), dominates: s_b_15_0 s_b_18_0 s_b_17_27  */
    CV_sym_58441_0_parameter_voff = (uint64_t)0ULL;
    /* execute.a64:2837 [D] s_b_14_10 = ReadReg 1 (u8) */
    auto s_b_14_10 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_14_10, emitter.const_u8(1));
    }
    /* execute.a64:2837 [D] s_b_14_11 = (u32)s_b_14_10 */
    auto s_b_14_11 = emitter.zx(s_b_14_10, emitter.context().types().u32());
    /* execute.a64:2837 [F] s_b_14_12 = constant u32 1f (const) */
    /* execute.a64:2837 [D] s_b_14_13 = s_b_14_11<<s_b_14_12 */
    auto s_b_14_13 = emitter.shl(s_b_14_11, emitter.const_u32((uint32_t)31ULL));
    /* execute.a64:2838 [D] s_b_14_14 = ReadReg 2 (u8) */
    auto s_b_14_14 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_14_14, emitter.const_u8(1));
    }
    /* execute.a64:2838 [D] s_b_14_15 = (u32)s_b_14_14 */
    auto s_b_14_15 = emitter.zx(s_b_14_14, emitter.context().types().u32());
    /* execute.a64:2838 [F] s_b_14_16 = constant u32 1e (const) */
    /* execute.a64:2838 [D] s_b_14_17 = s_b_14_15<<s_b_14_16 */
    auto s_b_14_17 = emitter.shl(s_b_14_15, emitter.const_u32((uint32_t)30ULL));
    /* execute.a64:2837 [D] s_b_14_18 = s_b_14_13|s_b_14_17 */
    auto s_b_14_18 = emitter.bitwise_or(s_b_14_13, s_b_14_17);
    /* execute.a64:2839 [D] s_b_14_19 = ReadReg 3 (u8) */
    auto s_b_14_19 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_14_19, emitter.const_u8(1));
    }
    /* execute.a64:2839 [D] s_b_14_20 = (u32)s_b_14_19 */
    auto s_b_14_20 = emitter.zx(s_b_14_19, emitter.context().types().u32());
    /* execute.a64:2839 [F] s_b_14_21 = constant u32 1d (const) */
    /* execute.a64:2839 [D] s_b_14_22 = s_b_14_20<<s_b_14_21 */
    auto s_b_14_22 = emitter.shl(s_b_14_20, emitter.const_u32((uint32_t)29ULL));
    /* execute.a64:2838 [D] s_b_14_23 = s_b_14_18|s_b_14_22 */
    auto s_b_14_23 = emitter.bitwise_or(s_b_14_18, s_b_14_22);
    /* execute.a64:2840 [D] s_b_14_24 = ReadReg 4 (u8) */
    auto s_b_14_24 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_24, emitter.const_u8(1));
    }
    /* execute.a64:2840 [D] s_b_14_25 = (u32)s_b_14_24 */
    auto s_b_14_25 = emitter.zx(s_b_14_24, emitter.context().types().u32());
    /* execute.a64:2840 [F] s_b_14_26 = constant u32 1c (const) */
    /* execute.a64:2840 [D] s_b_14_27 = s_b_14_25<<s_b_14_26 */
    auto s_b_14_27 = emitter.shl(s_b_14_25, emitter.const_u32((uint32_t)28ULL));
    /* execute.a64:2839 [D] s_b_14_28 = s_b_14_23|s_b_14_27 */
    auto s_b_14_28 = emitter.bitwise_or(s_b_14_23, s_b_14_27);
    /* execute.a64:2841 [D] s_b_14_29 = ReadReg 5 (u8) */
    auto s_b_14_29 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_14_29, emitter.const_u8(1));
    }
    /* execute.a64:2841 [D] s_b_14_30 = (u32)s_b_14_29 */
    auto s_b_14_30 = emitter.zx(s_b_14_29, emitter.context().types().u32());
    /* execute.a64:2841 [F] s_b_14_31 = constant u32 9 (const) */
    /* execute.a64:2841 [D] s_b_14_32 = s_b_14_30<<s_b_14_31 */
    auto s_b_14_32 = emitter.shl(s_b_14_30, emitter.const_u32((uint32_t)9ULL));
    /* execute.a64:2840 [D] s_b_14_33 = s_b_14_28|s_b_14_32 */
    auto s_b_14_33 = emitter.bitwise_or(s_b_14_28, s_b_14_32);
    /* execute.a64:2842 [D] s_b_14_34 = ReadReg 6 (u8) */
    auto s_b_14_34 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_14_34, emitter.const_u8(1));
    }
    /* execute.a64:2842 [D] s_b_14_35 = (u32)s_b_14_34 */
    auto s_b_14_35 = emitter.zx(s_b_14_34, emitter.context().types().u32());
    /* execute.a64:2842 [F] s_b_14_36 = constant u32 8 (const) */
    /* execute.a64:2842 [D] s_b_14_37 = s_b_14_35<<s_b_14_36 */
    auto s_b_14_37 = emitter.shl(s_b_14_35, emitter.const_u32((uint32_t)8ULL));
    /* execute.a64:2841 [D] s_b_14_38 = s_b_14_33|s_b_14_37 */
    auto s_b_14_38 = emitter.bitwise_or(s_b_14_33, s_b_14_37);
    /* execute.a64:2843 [D] s_b_14_39 = ReadReg 7 (u8) */
    auto s_b_14_39 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_14_39, emitter.const_u8(1));
    }
    /* execute.a64:2843 [D] s_b_14_40 = (u32)s_b_14_39 */
    auto s_b_14_40 = emitter.zx(s_b_14_39, emitter.context().types().u32());
    /* execute.a64:2843 [F] s_b_14_41 = constant u32 7 (const) */
    /* execute.a64:2843 [D] s_b_14_42 = s_b_14_40<<s_b_14_41 */
    auto s_b_14_42 = emitter.shl(s_b_14_40, emitter.const_u32((uint32_t)7ULL));
    /* execute.a64:2842 [D] s_b_14_43 = s_b_14_38|s_b_14_42 */
    auto s_b_14_43 = emitter.bitwise_or(s_b_14_38, s_b_14_42);
    /* execute.a64:2844 [D] s_b_14_44 = ReadReg 8 (u8) */
    auto s_b_14_44 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_14_44, emitter.const_u8(1));
    }
    /* execute.a64:2844 [D] s_b_14_45 = (u32)s_b_14_44 */
    auto s_b_14_45 = emitter.zx(s_b_14_44, emitter.context().types().u32());
    /* execute.a64:2844 [F] s_b_14_46 = constant u32 6 (const) */
    /* execute.a64:2844 [D] s_b_14_47 = s_b_14_45<<s_b_14_46 */
    auto s_b_14_47 = emitter.shl(s_b_14_45, emitter.const_u32((uint32_t)6ULL));
    /* execute.a64:2843 [D] s_b_14_48 = s_b_14_43|s_b_14_47 */
    auto s_b_14_48 = emitter.bitwise_or(s_b_14_43, s_b_14_47);
    /* execute.a64:3012 [F] s_b_14_49 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_14_50 = __builtin_get_feature */
    uint32_t s_b_14_50 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_14_51 = (u8)s_b_14_50 (const) */
    /* execute.a64:2845 [F] s_b_14_52 = (u32)s_b_14_51 (const) */
    /* execute.a64:2845 [F] s_b_14_53 = constant u32 2 (const) */
    /* execute.a64:2845 [F] s_b_14_54 = s_b_14_52<<s_b_14_53 (const) */
    uint32_t s_b_14_54 = ((uint32_t)(((uint32_t)((uint8_t)s_b_14_50)) << (uint32_t)2ULL));
    /* execute.a64:2844 [D] s_b_14_55 = s_b_14_48|s_b_14_54 */
    auto s_b_14_55 = emitter.bitwise_or(s_b_14_48, emitter.const_u32(s_b_14_54));
    /* execute.a64:2846 [F] s_b_14_56 = constant u32 1 (const) */
    /* execute.a64:2846 [F] s_b_14_57 = __builtin_get_feature */
    uint32_t s_b_14_57 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2846 [F] s_b_14_58 = (u32)s_b_14_57 (const) */
    /* execute.a64:2845 [D] s_b_14_59 = s_b_14_55|s_b_14_58 */
    auto s_b_14_59 = emitter.bitwise_or(s_b_14_55, emitter.const_u32(((uint32_t)s_b_14_57)));
    /* execute.a64:2959 [D] s_b_14_60: sym_58493_0_spsr = s_b_14_59, dominates: s_b_17_6  */
    emitter.store_local(DV_sym_58493_0_spsr, s_b_14_59);
    /* execute.a64:3012 [F] s_b_14_61 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_14_62 = __builtin_get_feature */
    uint32_t s_b_14_62 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_14_63 = (u8)s_b_14_62 (const) */
    /* execute.a64:2962 [F] s_b_14_64 = s_b_14_4>s_b_14_63 (const) */
    uint8_t s_b_14_64 = ((uint8_t)((uint8_t)1ULL > ((uint8_t)s_b_14_62)));
    /* execute.a64:2962 [F] s_b_14_65: If s_b_14_64: Jump b_15 else b_16 (const) */
    if (s_b_14_64) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2963 [F] s_b_15_0 = sym_58441_0_parameter_voff (const) uint64_t */
    uint64_t s_b_15_0 = CV_sym_58441_0_parameter_voff;
    /* ???:4294967295 [F] s_b_15_1 = constant u64 400 (const) */
    /* ???:4294967295 [F] s_b_15_2 = s_b_15_0+s_b_15_1 (const) */
    uint64_t s_b_15_2 = ((uint64_t)(s_b_15_0 + (uint64_t)1024ULL));
    /* execute.a64:2963 [F] s_b_15_3: sym_58441_0_parameter_voff = s_b_15_2 (const), dominates: s_b_17_27  */
    CV_sym_58441_0_parameter_voff = s_b_15_2;
    /* execute.a64:2963 [F] s_b_15_4: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2964 [F] s_b_16_0 = constant u32 1 (const) */
    /* execute.a64:2964 [F] s_b_16_1 = __builtin_get_feature */
    uint32_t s_b_16_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2964 [F] s_b_16_2 = constant u32 1 (const) */
    /* execute.a64:2964 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(s_b_16_1 == (uint32_t)1ULL));
    /* execute.a64:2964 [F] s_b_16_4: If s_b_16_3: Jump b_18 else b_17 (const) */
    if (s_b_16_3) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_15, b_16, b_18,  */
  fixed_block_b_17: 
  {
    /* execute.a64:3017 [F] s_b_17_0 = constant u32 0 (const) */
    /* execute.a64:3017 [F] s_b_17_1 = constant u32 1 (const) */
    /* execute.a64:3017 [D] s_b_17_2 = __builtin_set_feature */
    emitter.set_feature((uint32_t)0ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:2953 [F] s_b_17_3 = constant u32 1 (const) */
    /* execute.a64:2953 [F] s_b_17_4 = constant u32 1 (const) */
    /* execute.a64:2953 [D] s_b_17_5 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:2975 [D] s_b_17_6 = sym_58493_0_spsr uint32_t */
    auto s_b_17_6 = emitter.load_local(DV_sym_58493_0_spsr, emitter.context().types().u32());
    /* execute.a64:2975 [D] s_b_17_7: WriteReg 17 = s_b_17_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_17_6, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_17_6);
    /* execute.a64:2976 [D] s_b_17_8 = sym_58439_0_parameter_retaddr uint64_t */
    auto s_b_17_8 = emitter.load_local(DV_sym_58439_0_parameter_retaddr, emitter.context().types().u64());
    /* execute.a64:2976 [D] s_b_17_9: WriteReg 16 = s_b_17_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_17_8, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_17_8);
    /* execute.a64:2981 [F] s_b_17_10 = sym_58437_0_parameter_syndrome (const) uint32_t */
    uint32_t s_b_17_10 = CV_sym_58437_0_parameter_syndrome;
    /* execute.a64:2981 [F] s_b_17_11 = (u64)s_b_17_10 (const) */
    /* execute.a64:2981 [F] s_b_17_12 = constant u64 1ffffff (const) */
    /* execute.a64:2981 [F] s_b_17_13 = s_b_17_11&s_b_17_12 (const) */
    uint64_t s_b_17_13 = ((uint64_t)(((uint64_t)s_b_17_10) & (uint64_t)33554431ULL));
    /* execute.a64:2981 [F] s_b_17_14 = constant u64 56000000 (const) */
    /* execute.a64:2981 [F] s_b_17_15 = s_b_17_14|s_b_17_13 (const) */
    uint64_t s_b_17_15 = ((uint64_t)((uint64_t)1442840576ULL | s_b_17_13));
    /* execute.a64:2981 [F] s_b_17_16 = (u32)s_b_17_15 (const) */
    /* execute.a64:2981 [F] s_b_17_17: WriteReg 18 = s_b_17_16 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1392), emitter.const_u32(((uint32_t)s_b_17_15)), emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1392), emitter.const_u32(((uint32_t)s_b_17_15)));
    /* execute.a64:2991 [F] s_b_17_18 = constant u8 1 (const) */
    /* execute.a64:2991 [F] s_b_17_19: WriteReg 5 = s_b_17_18 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:2992 [F] s_b_17_20 = constant u8 1 (const) */
    /* execute.a64:2992 [F] s_b_17_21: WriteReg 6 = s_b_17_20 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:2993 [F] s_b_17_22 = constant u8 1 (const) */
    /* execute.a64:2993 [F] s_b_17_23: WriteReg 7 = s_b_17_22 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:2994 [F] s_b_17_24 = constant u8 1 (const) */
    /* execute.a64:2994 [F] s_b_17_25: WriteReg 8 = s_b_17_24 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:2996 [D] s_b_17_26 = ReadReg 13 (u64) */
    auto s_b_17_26 = emitter.load_register(emitter.const_u32(1336), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1336), s_b_17_26, emitter.const_u8(8));
    }
    /* execute.a64:2998 [F] s_b_17_27 = sym_58441_0_parameter_voff (const) uint64_t */
    uint64_t s_b_17_27 = CV_sym_58441_0_parameter_voff;
    /* execute.a64:2998 [D] s_b_17_28 = s_b_17_26+s_b_17_27 */
    auto s_b_17_28 = emitter.add(s_b_17_26, emitter.const_u64(s_b_17_27));
    /* execute.a64:2998 [D] s_b_17_29 = write_pc */
    emitter.store_pc(s_b_17_28);
    /* execute.a64:0 [F] s_b_17_30: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2965 [F] s_b_18_0 = sym_58441_0_parameter_voff (const) uint64_t */
    uint64_t s_b_18_0 = CV_sym_58441_0_parameter_voff;
    /* ???:4294967295 [F] s_b_18_1 = constant u64 200 (const) */
    /* ???:4294967295 [F] s_b_18_2 = s_b_18_0+s_b_18_1 (const) */
    uint64_t s_b_18_2 = ((uint64_t)(s_b_18_0 + (uint64_t)512ULL));
    /* execute.a64:2965 [F] s_b_18_3: sym_58441_0_parameter_voff = s_b_18_2 (const), dominates: s_b_17_27  */
    CV_sym_58441_0_parameter_voff = s_b_18_2;
    /* execute.a64:2965 [F] s_b_18_4: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_1,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2963 [F] s_b_19_0 = sym_58575_3_parameter_voff (const) uint64_t */
    uint64_t s_b_19_0 = CV_sym_58575_3_parameter_voff;
    /* ???:4294967295 [F] s_b_19_1 = constant u64 400 (const) */
    /* ???:4294967295 [F] s_b_19_2 = s_b_19_0+s_b_19_1 (const) */
    uint64_t s_b_19_2 = ((uint64_t)(s_b_19_0 + (uint64_t)1024ULL));
    /* execute.a64:2963 [F] s_b_19_3: sym_58575_3_parameter_voff = s_b_19_2 (const), dominates: s_b_21_27  */
    CV_sym_58575_3_parameter_voff = s_b_19_2;
    /* execute.a64:2963 [F] s_b_19_4: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_1,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2964 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:2964 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2964 [F] s_b_20_2 = constant u32 1 (const) */
    /* execute.a64:2964 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)1ULL));
    /* execute.a64:2964 [F] s_b_20_4: If s_b_20_3: Jump b_22 else b_21 (const) */
    if (s_b_20_3) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_19, b_20, b_22,  */
  fixed_block_b_21: 
  {
    /* execute.a64:3017 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:3017 [F] s_b_21_1 = constant u32 1 (const) */
    /* execute.a64:3017 [D] s_b_21_2 = __builtin_set_feature */
    emitter.set_feature((uint32_t)0ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:2953 [F] s_b_21_3 = constant u32 1 (const) */
    /* execute.a64:2953 [F] s_b_21_4 = constant u32 1 (const) */
    /* execute.a64:2953 [D] s_b_21_5 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:2975 [D] s_b_21_6 = sym_58563_0_spsr uint32_t */
    auto s_b_21_6 = emitter.load_local(DV_sym_58563_0_spsr, emitter.context().types().u32());
    /* execute.a64:2975 [D] s_b_21_7: WriteReg 17 = s_b_21_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_21_6, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_21_6);
    /* execute.a64:2976 [D] s_b_21_8 = sym_58613_3_parameter_retaddr uint64_t */
    auto s_b_21_8 = emitter.load_local(DV_sym_58613_3_parameter_retaddr, emitter.context().types().u64());
    /* execute.a64:2976 [D] s_b_21_9: WriteReg 16 = s_b_21_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_21_8, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_21_8);
    /* execute.a64:2981 [F] s_b_21_10 = sym_58664_3_parameter_syndrome (const) uint32_t */
    uint32_t s_b_21_10 = CV_sym_58664_3_parameter_syndrome;
    /* execute.a64:2981 [F] s_b_21_11 = (u64)s_b_21_10 (const) */
    /* execute.a64:2981 [F] s_b_21_12 = constant u64 1ffffff (const) */
    /* execute.a64:2981 [F] s_b_21_13 = s_b_21_11&s_b_21_12 (const) */
    uint64_t s_b_21_13 = ((uint64_t)(((uint64_t)s_b_21_10) & (uint64_t)33554431ULL));
    /* execute.a64:2981 [F] s_b_21_14 = constant u64 f2000000 (const) */
    /* execute.a64:2981 [F] s_b_21_15 = s_b_21_14|s_b_21_13 (const) */
    uint64_t s_b_21_15 = ((uint64_t)((uint64_t)4060086272ULL | s_b_21_13));
    /* execute.a64:2981 [F] s_b_21_16 = (u32)s_b_21_15 (const) */
    /* execute.a64:2981 [F] s_b_21_17: WriteReg 18 = s_b_21_16 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1392), emitter.const_u32(((uint32_t)s_b_21_15)), emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1392), emitter.const_u32(((uint32_t)s_b_21_15)));
    /* execute.a64:2991 [F] s_b_21_18 = constant u8 1 (const) */
    /* execute.a64:2991 [F] s_b_21_19: WriteReg 5 = s_b_21_18 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:2992 [F] s_b_21_20 = constant u8 1 (const) */
    /* execute.a64:2992 [F] s_b_21_21: WriteReg 6 = s_b_21_20 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:2993 [F] s_b_21_22 = constant u8 1 (const) */
    /* execute.a64:2993 [F] s_b_21_23: WriteReg 7 = s_b_21_22 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:2994 [F] s_b_21_24 = constant u8 1 (const) */
    /* execute.a64:2994 [F] s_b_21_25: WriteReg 8 = s_b_21_24 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:2996 [D] s_b_21_26 = ReadReg 13 (u64) */
    auto s_b_21_26 = emitter.load_register(emitter.const_u32(1336), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1336), s_b_21_26, emitter.const_u8(8));
    }
    /* execute.a64:2998 [F] s_b_21_27 = sym_58575_3_parameter_voff (const) uint64_t */
    uint64_t s_b_21_27 = CV_sym_58575_3_parameter_voff;
    /* execute.a64:2998 [D] s_b_21_28 = s_b_21_26+s_b_21_27 */
    auto s_b_21_28 = emitter.add(s_b_21_26, emitter.const_u64(s_b_21_27));
    /* execute.a64:2998 [D] s_b_21_29 = write_pc */
    emitter.store_pc(s_b_21_28);
    /* execute.a64:0 [F] s_b_21_30: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_20,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2965 [F] s_b_22_0 = sym_58575_3_parameter_voff (const) uint64_t */
    uint64_t s_b_22_0 = CV_sym_58575_3_parameter_voff;
    /* ???:4294967295 [F] s_b_22_1 = constant u64 200 (const) */
    /* ???:4294967295 [F] s_b_22_2 = s_b_22_0+s_b_22_1 (const) */
    uint64_t s_b_22_2 = ((uint64_t)(s_b_22_0 + (uint64_t)512ULL));
    /* execute.a64:2965 [F] s_b_22_3: sym_58575_3_parameter_voff = s_b_22_2 (const), dominates: s_b_21_27  */
    CV_sym_58575_3_parameter_voff = s_b_22_2;
    /* execute.a64:2965 [F] s_b_22_4: Jump b_21 (const) */
    goto fixed_block_b_21;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fcmpe(const aarch64_decode_a64_FP_CMP&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_10685_0_rm = emitter.alloc_local(emitter.context().types().f32(), false);
  auto DV_sym_10707_0_rn = emitter.alloc_local(emitter.context().types().f64(), false);
  double CV_sym_10726_1_temporary_value;
  auto DV_sym_10726_1_temporary_value = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_10737_0_rm = emitter.alloc_local(emitter.context().types().f64(), false);
  float CV_sym_10674_1_temporary_value;
  auto DV_sym_10674_1_temporary_value = emitter.alloc_local(emitter.context().types().f32(), false);
  auto DV_sym_10655_0_rn = emitter.alloc_local(emitter.context().types().f32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4654 [F] s_b_0_0=sym_10642_3_parameter_inst.type (const) */
    /* execute.simd:4654 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4654 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4654 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4654 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4656 [F] s_b_1_0=sym_10642_3_parameter_inst.rn (const) */
    /* execute.simd:6159 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4656 [D] s_b_1_2: sym_10655_0_rn = s_b_1_1, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_10655_0_rn, s_b_1_1);
    /* execute.simd:4657 [F] s_b_1_3=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4657 [F] s_b_1_4 = (u64)s_b_1_3 (const) */
    /* execute.simd:4657 [F] s_b_1_5 = constant u64 18 (const) */
    /* execute.simd:4657 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint64_t)insn.opcode2) == (uint64_t)24ULL));
    /* execute.simd:4657 [F] s_b_1_7=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4657 [F] s_b_1_8 = (u64)s_b_1_7 (const) */
    /* execute.simd:4657 [F] s_b_1_9 = constant u64 8 (const) */
    /* execute.simd:4657 [F] s_b_1_10 = s_b_1_8==s_b_1_9 (const) */
    uint8_t s_b_1_10 = ((uint8_t)(((uint64_t)insn.opcode2) == (uint64_t)8ULL));
    /* ???:4294967295 [F] s_b_1_11 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_1_12 = s_b_1_6!=s_b_1_11 (const) */
    uint8_t s_b_1_12 = ((uint8_t)(s_b_1_6 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_13 = s_b_1_10!=s_b_1_11 (const) */
    uint8_t s_b_1_13 = ((uint8_t)(s_b_1_10 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_14 = s_b_1_12|s_b_1_13 (const) */
    uint8_t s_b_1_14 = ((uint8_t)(s_b_1_12 | s_b_1_13));
    /* execute.simd:4657 [F] s_b_1_15: If s_b_1_14: Jump b_4 else b_5 (const) */
    if (s_b_1_14) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_7, b_8, b_12, b_13,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4666 [F] s_b_3_0=sym_10642_3_parameter_inst.rn (const) */
    /* execute.simd:6164 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4666 [D] s_b_3_2: sym_10707_0_rn = s_b_3_1, dominates: s_b_12_0 s_b_13_0  */
    emitter.store_local(DV_sym_10707_0_rn, s_b_3_1);
    /* execute.simd:4667 [F] s_b_3_3=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4667 [F] s_b_3_4 = (u64)s_b_3_3 (const) */
    /* execute.simd:4667 [F] s_b_3_5 = constant u64 18 (const) */
    /* execute.simd:4667 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint64_t)insn.opcode2) == (uint64_t)24ULL));
    /* execute.simd:4667 [F] s_b_3_7=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4667 [F] s_b_3_8 = (u64)s_b_3_7 (const) */
    /* execute.simd:4667 [F] s_b_3_9 = constant u64 8 (const) */
    /* execute.simd:4667 [F] s_b_3_10 = s_b_3_8==s_b_3_9 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(((uint64_t)insn.opcode2) == (uint64_t)8ULL));
    /* ???:4294967295 [F] s_b_3_11 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_12 = s_b_3_6!=s_b_3_11 (const) */
    uint8_t s_b_3_12 = ((uint8_t)(s_b_3_6 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_13 = s_b_3_10!=s_b_3_11 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(s_b_3_10 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_14 = s_b_3_12|s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(s_b_3_12 | s_b_3_13));
    /* execute.simd:4667 [F] s_b_3_15: If s_b_3_14: Jump b_9 else b_10 (const) */
    if (s_b_3_14) 
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
    /* execute.simd:4657 [F] s_b_4_0 = constant f32 0 (const) */
    float s_b_4_0;
    {
      uint32_t __tmp = 0;
      s_b_4_0 = *(float *)&__tmp;
    }
    /* execute.simd:4657 [F] s_b_4_1: sym_10674_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_10674_1_temporary_value = s_b_4_0;
    emitter.store_local(DV_sym_10674_1_temporary_value, emitter.const_f32(s_b_4_0));
    /* execute.simd:4657 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4657 [F] s_b_5_0=sym_10642_3_parameter_inst.rm (const) */
    /* execute.simd:6159 [D] s_b_5_1 = ReadRegBank 9:s_b_5_0 (f32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_1,emitter.const_u8(4));
    }
    /* execute.simd:4657 [D] s_b_5_2: sym_10674_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_10674_1_temporary_value, s_b_5_1);
    /* execute.simd:4657 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4657 [D] s_b_6_0 = sym_10674_1_temporary_value float */
    auto s_b_6_0 = emitter.load_local(DV_sym_10674_1_temporary_value, emitter.context().types().f32());
    /* execute.simd:4657 [D] s_b_6_1: sym_10685_0_rm = s_b_6_0, dominates: s_b_7_1 s_b_8_1  */
    emitter.store_local(DV_sym_10685_0_rm, s_b_6_0);
    /* execute.simd:4659 [F] s_b_6_2=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4659 [F] s_b_6_3 = (u64)s_b_6_2 (const) */
    /* execute.simd:4659 [F] s_b_6_4 = constant u64 10 (const) */
    /* execute.simd:4659 [F] s_b_6_5 = s_b_6_3&s_b_6_4 (const) */
    uint64_t s_b_6_5 = ((uint64_t)(((uint64_t)insn.opcode2) & (uint64_t)16ULL));
    /* execute.simd:4659 [F] s_b_6_6: If s_b_6_5: Jump b_7 else b_8 (const) */
    if (s_b_6_5) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_6,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4660 [D] s_b_7_0 = sym_10655_0_rn float */
    auto s_b_7_0 = emitter.load_local(DV_sym_10655_0_rn, emitter.context().types().f32());
    /* execute.simd:4660 [D] s_b_7_1 = sym_10685_0_rm float */
    auto s_b_7_1 = emitter.load_local(DV_sym_10685_0_rm, emitter.context().types().f32());
    /* execute.simd:4660 [D] s_b_7_2 = __builtin_cmpf32e_flags */
    emitter.call(__captive___builtin_cmpf32e_flags, s_b_7_0, s_b_7_1);
    /* execute.simd:4660 [F] s_b_7_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4662 [D] s_b_8_0 = sym_10655_0_rn float */
    auto s_b_8_0 = emitter.load_local(DV_sym_10655_0_rn, emitter.context().types().f32());
    /* execute.simd:4662 [D] s_b_8_1 = sym_10685_0_rm float */
    auto s_b_8_1 = emitter.load_local(DV_sym_10685_0_rm, emitter.context().types().f32());
    /* execute.simd:4662 [D] s_b_8_2 = __builtin_cmpf32_flags */
    emitter.call(__captive___builtin_cmpf32_flags, s_b_8_0, s_b_8_1);
    /* execute.simd:4662 [F] s_b_8_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4667 [F] s_b_9_0 = constant f64 0 (const) */
    double s_b_9_0;
    {
      uint64_t __tmp = 0;
      s_b_9_0 = *(double *)&__tmp;
    }
    /* execute.simd:4667 [F] s_b_9_1: sym_10726_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_10726_1_temporary_value = s_b_9_0;
    emitter.store_local(DV_sym_10726_1_temporary_value, emitter.const_f64(s_b_9_0));
    /* execute.simd:4667 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4667 [F] s_b_10_0=sym_10642_3_parameter_inst.rm (const) */
    /* execute.simd:6164 [D] s_b_10_1 = ReadRegBank 11:s_b_10_0 (f64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.simd:4667 [D] s_b_10_2: sym_10726_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_10726_1_temporary_value, s_b_10_1);
    /* execute.simd:4667 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4667 [D] s_b_11_0 = sym_10726_1_temporary_value double */
    auto s_b_11_0 = emitter.load_local(DV_sym_10726_1_temporary_value, emitter.context().types().f64());
    /* execute.simd:4667 [D] s_b_11_1: sym_10737_0_rm = s_b_11_0, dominates: s_b_12_1 s_b_13_1  */
    emitter.store_local(DV_sym_10737_0_rm, s_b_11_0);
    /* execute.simd:4669 [F] s_b_11_2=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4669 [F] s_b_11_3 = (u64)s_b_11_2 (const) */
    /* execute.simd:4669 [F] s_b_11_4 = constant u64 10 (const) */
    /* execute.simd:4669 [F] s_b_11_5 = s_b_11_3&s_b_11_4 (const) */
    uint64_t s_b_11_5 = ((uint64_t)(((uint64_t)insn.opcode2) & (uint64_t)16ULL));
    /* execute.simd:4669 [F] s_b_11_6: If s_b_11_5: Jump b_12 else b_13 (const) */
    if (s_b_11_5) 
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
    /* execute.simd:4670 [D] s_b_12_0 = sym_10707_0_rn double */
    auto s_b_12_0 = emitter.load_local(DV_sym_10707_0_rn, emitter.context().types().f64());
    /* execute.simd:4670 [D] s_b_12_1 = sym_10737_0_rm double */
    auto s_b_12_1 = emitter.load_local(DV_sym_10737_0_rm, emitter.context().types().f64());
    /* execute.simd:4670 [D] s_b_12_2 = __builtin_cmpf64e_flags */
    emitter.call(__captive___builtin_cmpf64e_flags, s_b_12_0, s_b_12_1);
    /* execute.simd:4670 [F] s_b_12_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4672 [D] s_b_13_0 = sym_10707_0_rn double */
    auto s_b_13_0 = emitter.load_local(DV_sym_10707_0_rn, emitter.context().types().f64());
    /* execute.simd:4672 [D] s_b_13_1 = sym_10737_0_rm double */
    auto s_b_13_1 = emitter.load_local(DV_sym_10737_0_rm, emitter.context().types().f64());
    /* execute.simd:4672 [D] s_b_13_2 = __builtin_cmpf64_flags */
    emitter.call(__captive___builtin_cmpf64_flags, s_b_13_0, s_b_13_1);
    /* execute.simd:4672 [F] s_b_13_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fdiv(const aarch64_decode_a64_FP_DP_2&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4144 [F] s_b_0_0=sym_11622_3_parameter_inst.type (const) */
    /* execute.simd:4144 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4144 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4144 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4144 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4146 [F] s_b_1_0=sym_11622_3_parameter_inst.rn (const) */
    /* execute.simd:6159 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4147 [F] s_b_1_2=sym_11622_3_parameter_inst.rm (const) */
    /* execute.simd:6159 [D] s_b_1_3 = ReadRegBank 9:s_b_1_2 (f32) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(4));
    }
    /* execute.simd:4149 [D] s_b_1_4 = s_b_1_1/s_b_1_3 */
    auto s_b_1_4 = emitter.div(s_b_1_1, s_b_1_3);
    /* execute.simd:4150 [F] s_b_1_5=sym_11622_3_parameter_inst.rd (const) */
    /* execute.simd:6169 [D] s_b_1_6: WriteRegBank 9:s_b_1_5 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4);
    /* execute.simd:6170 [F] s_b_1_7 = constant u32 0 (const) */
    /* execute.simd:6170 [F] s_b_1_8: WriteRegBank 10:s_b_1_5 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6171 [F] s_b_1_9 = constant u64 0 (const) */
    /* execute.simd:6171 [F] s_b_1_10: WriteRegBank 3:s_b_1_5 = s_b_1_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_11: Jump b_2 (const) */
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
    /* execute.simd:4153 [F] s_b_3_0=sym_11622_3_parameter_inst.rn (const) */
    /* execute.simd:6164 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4154 [F] s_b_3_2=sym_11622_3_parameter_inst.rm (const) */
    /* execute.simd:6164 [D] s_b_3_3 = ReadRegBank 11:s_b_3_2 (f64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:4156 [D] s_b_3_4 = s_b_3_1/s_b_3_3 */
    auto s_b_3_4 = emitter.div(s_b_3_1, s_b_3_3);
    /* execute.simd:4157 [F] s_b_3_5=sym_11622_3_parameter_inst.rd (const) */
    /* execute.simd:6177 [D] s_b_3_6: WriteRegBank 11:s_b_3_5 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:6178 [F] s_b_3_7 = constant u64 0 (const) */
    /* execute.simd:6178 [F] s_b_3_8: WriteRegBank 3:s_b_3_5 = s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_3_9: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fmov_gen(const aarch64_decode_a64_CVT_FP_I&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_62147_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_62245_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_62289_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4035 [F] s_b_0_0=sym_11885_3_parameter_inst.sf (const) */
    /* execute.simd:4035 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4035 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4035 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4035 [F] s_b_0_4=sym_11885_3_parameter_inst.type (const) */
    /* execute.simd:4035 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.simd:4035 [F] s_b_0_6 = constant u32 0 (const) */
    /* execute.simd:4035 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.simd:4035 [F] s_b_0_12=sym_11885_3_parameter_inst.rmode (const) */
    /* execute.simd:4035 [F] s_b_0_13 = (u32)s_b_0_12 (const) */
    /* execute.simd:4035 [F] s_b_0_14 = constant u32 0 (const) */
    /* execute.simd:4035 [F] s_b_0_15 = s_b_0_13==s_b_0_14 (const) */
    uint8_t s_b_0_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_0_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_17 = s_b_0_11!=s_b_0_16 (const) */
    uint8_t s_b_0_17 = ((uint8_t)(s_b_0_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_18 = s_b_0_15!=s_b_0_16 (const) */
    uint8_t s_b_0_18 = ((uint8_t)(s_b_0_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_19 = s_b_0_17&s_b_0_18 (const) */
    uint8_t s_b_0_19 = ((uint8_t)(s_b_0_17 & s_b_0_18));
    /* execute.simd:4035 [F] s_b_0_20=sym_11885_3_parameter_inst.opcode (const) */
    /* execute.simd:4035 [F] s_b_0_21 = (u32)s_b_0_20 (const) */
    /* execute.simd:4035 [F] s_b_0_22 = constant u32 7 (const) */
    /* execute.simd:4035 [F] s_b_0_23 = s_b_0_21==s_b_0_22 (const) */
    uint8_t s_b_0_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_0_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_25 = s_b_0_19!=s_b_0_24 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(s_b_0_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_26 = s_b_0_23!=s_b_0_24 (const) */
    uint8_t s_b_0_26 = ((uint8_t)(s_b_0_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_27 = s_b_0_25&s_b_0_26 (const) */
    uint8_t s_b_0_27 = ((uint8_t)(s_b_0_25 & s_b_0_26));
    /* execute.simd:4035 [F] s_b_0_28: If s_b_0_27: Jump b_1 else b_3 (const) */
    if (s_b_0_27) 
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
    /* execute.a64:2659 [F] s_b_1_0=sym_11885_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2646 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_5 = ReadRegBank 1:s_b_1_0 (u32) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 */
    dbt::el::Value *s_b_1_6;
    s_b_1_6 = (s_b_1_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_5);
    /* execute.a64:2659 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_1_8=sym_11885_3_parameter_inst.rd (const) */
    /* execute.simd:4037 [D] s_b_1_9 = (u32)s_b_1_7 */
    auto s_b_1_9 = emitter.truncate(s_b_1_7, emitter.context().types().u32());
    /* execute.simd:4037 [D] s_b_1_10: WriteRegBank 6:s_b_1_8 = s_b_1_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_9,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_9);
    /* execute.simd:4038 [F] s_b_1_11=sym_11885_3_parameter_inst.rd (const) */
    /* execute.simd:4038 [F] s_b_1_12 = constant u32 0 (const) */
    /* execute.simd:4038 [F] s_b_1_13: WriteRegBank 10:s_b_1_11 = s_b_1_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:4039 [F] s_b_1_14=sym_11885_3_parameter_inst.rd (const) */
    /* execute.simd:4039 [F] s_b_1_15 = constant u64 0 (const) */
    /* execute.simd:4039 [F] s_b_1_16: WriteRegBank 3:s_b_1_14 = s_b_1_15 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4037 [F] s_b_1_17: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_8, b_10, b_12, b_13, b_14, b_15, b_16,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4040 [F] s_b_3_0=sym_11885_3_parameter_inst.sf (const) */
    /* execute.simd:4040 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4040 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4040 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4040 [F] s_b_3_4=sym_11885_3_parameter_inst.type (const) */
    /* execute.simd:4040 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4040 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:4040 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4040 [F] s_b_3_12=sym_11885_3_parameter_inst.rmode (const) */
    /* execute.simd:4040 [F] s_b_3_13 = (u32)s_b_3_12 (const) */
    /* execute.simd:4040 [F] s_b_3_14 = constant u32 0 (const) */
    /* execute.simd:4040 [F] s_b_3_15 = s_b_3_13==s_b_3_14 (const) */
    uint8_t s_b_3_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_17 = s_b_3_11!=s_b_3_16 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(s_b_3_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_18 = s_b_3_15!=s_b_3_16 (const) */
    uint8_t s_b_3_18 = ((uint8_t)(s_b_3_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_19 = s_b_3_17&s_b_3_18 (const) */
    uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 & s_b_3_18));
    /* execute.simd:4040 [F] s_b_3_20=sym_11885_3_parameter_inst.opcode (const) */
    /* execute.simd:4040 [F] s_b_3_21 = (u32)s_b_3_20 (const) */
    /* execute.simd:4040 [F] s_b_3_22 = constant u32 6 (const) */
    /* execute.simd:4040 [F] s_b_3_23 = s_b_3_21==s_b_3_22 (const) */
    uint8_t s_b_3_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_3_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_25 = s_b_3_19!=s_b_3_24 (const) */
    uint8_t s_b_3_25 = ((uint8_t)(s_b_3_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_26 = s_b_3_23!=s_b_3_24 (const) */
    uint8_t s_b_3_26 = ((uint8_t)(s_b_3_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_27 = s_b_3_25&s_b_3_26 (const) */
    uint8_t s_b_3_27 = ((uint8_t)(s_b_3_25 & s_b_3_26));
    /* execute.simd:4040 [F] s_b_3_28: If s_b_3_27: Jump b_4 else b_5 (const) */
    if (s_b_3_27) 
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
    /* execute.simd:4042 [F] s_b_4_0=sym_11885_3_parameter_inst.rn (const) */
    /* execute.simd:4042 [D] s_b_4_1 = ReadRegBank 6:s_b_4_0 (u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(4));
    }
    /* execute.simd:4042 [D] s_b_4_2 = (u64)s_b_4_1 */
    auto s_b_4_2 = emitter.zx(s_b_4_1, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_4_3=sym_11885_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_4_4 = (u32)s_b_4_2 */
    auto s_b_4_4 = emitter.truncate(s_b_4_2, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_4_5 = (u64)s_b_4_4 */
    auto s_b_4_5 = emitter.zx(s_b_4_4, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_4_6: sym_62147_3_parameter_value = s_b_4_5, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_62147_3_parameter_value, s_b_4_5);
    /* execute.a64:2682 [F] s_b_4_7 = (u32)s_b_4_3 (const) */
    /* execute.a64:2682 [F] s_b_4_8 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_4_9 = s_b_4_7==s_b_4_8 (const) */
    uint8_t s_b_4_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_4_10: If s_b_4_9: Jump b_2 else b_14 (const) */
    if (s_b_4_9) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4043 [F] s_b_5_0=sym_11885_3_parameter_inst.sf (const) */
    /* execute.simd:4043 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4043 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4043 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4043 [F] s_b_5_4=sym_11885_3_parameter_inst.type (const) */
    /* execute.simd:4043 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4043 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.simd:4043 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.simd:4043 [F] s_b_5_12=sym_11885_3_parameter_inst.rmode (const) */
    /* execute.simd:4043 [F] s_b_5_13 = (u32)s_b_5_12 (const) */
    /* execute.simd:4043 [F] s_b_5_14 = constant u32 0 (const) */
    /* execute.simd:4043 [F] s_b_5_15 = s_b_5_13==s_b_5_14 (const) */
    uint8_t s_b_5_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_17 = s_b_5_11!=s_b_5_16 (const) */
    uint8_t s_b_5_17 = ((uint8_t)(s_b_5_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_18 = s_b_5_15!=s_b_5_16 (const) */
    uint8_t s_b_5_18 = ((uint8_t)(s_b_5_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_19 = s_b_5_17&s_b_5_18 (const) */
    uint8_t s_b_5_19 = ((uint8_t)(s_b_5_17 & s_b_5_18));
    /* execute.simd:4043 [F] s_b_5_20=sym_11885_3_parameter_inst.opcode (const) */
    /* execute.simd:4043 [F] s_b_5_21 = (u32)s_b_5_20 (const) */
    /* execute.simd:4043 [F] s_b_5_22 = constant u32 7 (const) */
    /* execute.simd:4043 [F] s_b_5_23 = s_b_5_21==s_b_5_22 (const) */
    uint8_t s_b_5_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_5_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_25 = s_b_5_19!=s_b_5_24 (const) */
    uint8_t s_b_5_25 = ((uint8_t)(s_b_5_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_26 = s_b_5_23!=s_b_5_24 (const) */
    uint8_t s_b_5_26 = ((uint8_t)(s_b_5_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_27 = s_b_5_25&s_b_5_26 (const) */
    uint8_t s_b_5_27 = ((uint8_t)(s_b_5_25 & s_b_5_26));
    /* execute.simd:4043 [F] s_b_5_28: If s_b_5_27: Jump b_6 else b_7 (const) */
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
    /* execute.a64:2657 [F] s_b_6_0=sym_11885_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2651 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_6_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_6_5 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_6_6: Select s_b_6_3 ? s_b_6_4 : s_b_6_5 */
    dbt::el::Value *s_b_6_6;
    s_b_6_6 = (s_b_6_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_6_5);
    /* ???:4294967295 [F] s_b_6_7=sym_11885_3_parameter_inst.rd (const) */
    /* execute.simd:4045 [D] s_b_6_8: WriteRegBank 7:s_b_6_7 = s_b_6_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6);
    /* execute.simd:4046 [F] s_b_6_9=sym_11885_3_parameter_inst.rd (const) */
    /* execute.simd:4046 [F] s_b_6_10 = constant u64 0 (const) */
    /* execute.simd:4046 [F] s_b_6_11: WriteRegBank 3:s_b_6_9 = s_b_6_10 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4045 [F] s_b_6_12: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4047 [F] s_b_7_0=sym_11885_3_parameter_inst.sf (const) */
    /* execute.simd:4047 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4047 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.simd:4047 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4047 [F] s_b_7_4=sym_11885_3_parameter_inst.type (const) */
    /* execute.simd:4047 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4047 [F] s_b_7_6 = constant u32 2 (const) */
    /* execute.simd:4047 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:4047 [F] s_b_7_12=sym_11885_3_parameter_inst.rmode (const) */
    /* execute.simd:4047 [F] s_b_7_13 = (u32)s_b_7_12 (const) */
    /* execute.simd:4047 [F] s_b_7_14 = constant u32 1 (const) */
    /* execute.simd:4047 [F] s_b_7_15 = s_b_7_13==s_b_7_14 (const) */
    uint8_t s_b_7_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_7_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_17 = s_b_7_11!=s_b_7_16 (const) */
    uint8_t s_b_7_17 = ((uint8_t)(s_b_7_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_18 = s_b_7_15!=s_b_7_16 (const) */
    uint8_t s_b_7_18 = ((uint8_t)(s_b_7_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_19 = s_b_7_17&s_b_7_18 (const) */
    uint8_t s_b_7_19 = ((uint8_t)(s_b_7_17 & s_b_7_18));
    /* execute.simd:4047 [F] s_b_7_20=sym_11885_3_parameter_inst.opcode (const) */
    /* execute.simd:4047 [F] s_b_7_21 = (u32)s_b_7_20 (const) */
    /* execute.simd:4047 [F] s_b_7_22 = constant u32 7 (const) */
    /* execute.simd:4047 [F] s_b_7_23 = s_b_7_21==s_b_7_22 (const) */
    uint8_t s_b_7_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_7_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_25 = s_b_7_19!=s_b_7_24 (const) */
    uint8_t s_b_7_25 = ((uint8_t)(s_b_7_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_26 = s_b_7_23!=s_b_7_24 (const) */
    uint8_t s_b_7_26 = ((uint8_t)(s_b_7_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_27 = s_b_7_25&s_b_7_26 (const) */
    uint8_t s_b_7_27 = ((uint8_t)(s_b_7_25 & s_b_7_26));
    /* execute.simd:4047 [F] s_b_7_28: If s_b_7_27: Jump b_8 else b_9 (const) */
    if (s_b_7_27) 
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
    /* execute.a64:2657 [F] s_b_8_0=sym_11885_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2651 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_8_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_8_5 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_8_5);
    /* ???:4294967295 [F] s_b_8_7=sym_11885_3_parameter_inst.rd (const) */
    /* execute.simd:4049 [D] s_b_8_8: WriteRegBank 3:s_b_8_7 = s_b_8_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_8_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_8_6);
    /* execute.simd:4049 [F] s_b_8_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4050 [F] s_b_9_0=sym_11885_3_parameter_inst.sf (const) */
    /* execute.simd:4050 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4050 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4050 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4050 [F] s_b_9_4=sym_11885_3_parameter_inst.type (const) */
    /* execute.simd:4050 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4050 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.simd:4050 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.simd:4050 [F] s_b_9_12=sym_11885_3_parameter_inst.rmode (const) */
    /* execute.simd:4050 [F] s_b_9_13 = (u32)s_b_9_12 (const) */
    /* execute.simd:4050 [F] s_b_9_14 = constant u32 0 (const) */
    /* execute.simd:4050 [F] s_b_9_15 = s_b_9_13==s_b_9_14 (const) */
    uint8_t s_b_9_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_9_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_17 = s_b_9_11!=s_b_9_16 (const) */
    uint8_t s_b_9_17 = ((uint8_t)(s_b_9_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_18 = s_b_9_15!=s_b_9_16 (const) */
    uint8_t s_b_9_18 = ((uint8_t)(s_b_9_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_19 = s_b_9_17&s_b_9_18 (const) */
    uint8_t s_b_9_19 = ((uint8_t)(s_b_9_17 & s_b_9_18));
    /* execute.simd:4050 [F] s_b_9_20=sym_11885_3_parameter_inst.opcode (const) */
    /* execute.simd:4050 [F] s_b_9_21 = (u32)s_b_9_20 (const) */
    /* execute.simd:4050 [F] s_b_9_22 = constant u32 6 (const) */
    /* execute.simd:4050 [F] s_b_9_23 = s_b_9_21==s_b_9_22 (const) */
    uint8_t s_b_9_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_9_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_25 = s_b_9_19!=s_b_9_24 (const) */
    uint8_t s_b_9_25 = ((uint8_t)(s_b_9_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_26 = s_b_9_23!=s_b_9_24 (const) */
    uint8_t s_b_9_26 = ((uint8_t)(s_b_9_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_27 = s_b_9_25&s_b_9_26 (const) */
    uint8_t s_b_9_27 = ((uint8_t)(s_b_9_25 & s_b_9_26));
    /* execute.simd:4050 [F] s_b_9_28: If s_b_9_27: Jump b_10 else b_11 (const) */
    if (s_b_9_27) 
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
    /* execute.simd:4052 [F] s_b_10_0=sym_11885_3_parameter_inst.rn (const) */
    /* execute.simd:4052 [D] s_b_10_1 = ReadRegBank 7:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2691 [F] s_b_10_2=sym_11885_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_10_3: sym_62245_3_parameter_value = s_b_10_1, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_62245_3_parameter_value, s_b_10_1);
    /* execute.a64:2682 [F] s_b_10_4 = (u32)s_b_10_2 (const) */
    /* execute.a64:2682 [F] s_b_10_5 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_10_6 = s_b_10_4==s_b_10_5 (const) */
    uint8_t s_b_10_6 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_10_7: If s_b_10_6: Jump b_2 else b_15 (const) */
    if (s_b_10_6) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4053 [F] s_b_11_0=sym_11885_3_parameter_inst.sf (const) */
    /* execute.simd:4053 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.simd:4053 [F] s_b_11_2 = constant u32 1 (const) */
    /* execute.simd:4053 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4053 [F] s_b_11_4=sym_11885_3_parameter_inst.type (const) */
    /* execute.simd:4053 [F] s_b_11_5 = (u32)s_b_11_4 (const) */
    /* execute.simd:4053 [F] s_b_11_6 = constant u32 2 (const) */
    /* execute.simd:4053 [F] s_b_11_7 = s_b_11_5==s_b_11_6 (const) */
    uint8_t s_b_11_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_11_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_9 = s_b_11_3!=s_b_11_8 (const) */
    uint8_t s_b_11_9 = ((uint8_t)(s_b_11_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_10 = s_b_11_7!=s_b_11_8 (const) */
    uint8_t s_b_11_10 = ((uint8_t)(s_b_11_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_11 = s_b_11_9&s_b_11_10 (const) */
    uint8_t s_b_11_11 = ((uint8_t)(s_b_11_9 & s_b_11_10));
    /* execute.simd:4053 [F] s_b_11_12=sym_11885_3_parameter_inst.rmode (const) */
    /* execute.simd:4053 [F] s_b_11_13 = (u32)s_b_11_12 (const) */
    /* execute.simd:4053 [F] s_b_11_14 = constant u32 1 (const) */
    /* execute.simd:4053 [F] s_b_11_15 = s_b_11_13==s_b_11_14 (const) */
    uint8_t s_b_11_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_11_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_17 = s_b_11_11!=s_b_11_16 (const) */
    uint8_t s_b_11_17 = ((uint8_t)(s_b_11_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_18 = s_b_11_15!=s_b_11_16 (const) */
    uint8_t s_b_11_18 = ((uint8_t)(s_b_11_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_19 = s_b_11_17&s_b_11_18 (const) */
    uint8_t s_b_11_19 = ((uint8_t)(s_b_11_17 & s_b_11_18));
    /* execute.simd:4053 [F] s_b_11_20=sym_11885_3_parameter_inst.opcode (const) */
    /* execute.simd:4053 [F] s_b_11_21 = (u32)s_b_11_20 (const) */
    /* execute.simd:4053 [F] s_b_11_22 = constant u32 6 (const) */
    /* execute.simd:4053 [F] s_b_11_23 = s_b_11_21==s_b_11_22 (const) */
    uint8_t s_b_11_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_11_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_25 = s_b_11_19!=s_b_11_24 (const) */
    uint8_t s_b_11_25 = ((uint8_t)(s_b_11_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_26 = s_b_11_23!=s_b_11_24 (const) */
    uint8_t s_b_11_26 = ((uint8_t)(s_b_11_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_27 = s_b_11_25&s_b_11_26 (const) */
    uint8_t s_b_11_27 = ((uint8_t)(s_b_11_25 & s_b_11_26));
    /* execute.simd:4053 [F] s_b_11_28: If s_b_11_27: Jump b_12 else b_13 (const) */
    if (s_b_11_27) 
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
    /* execute.simd:4055 [F] s_b_12_0=sym_11885_3_parameter_inst.rn (const) */
    /* execute.simd:4055 [D] s_b_12_1 = ReadRegBank 3:s_b_12_0 (u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.a64:2691 [F] s_b_12_2=sym_11885_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_12_3: sym_62289_3_parameter_value = s_b_12_1, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_62289_3_parameter_value, s_b_12_1);
    /* execute.a64:2682 [F] s_b_12_4 = (u32)s_b_12_2 (const) */
    /* execute.a64:2682 [F] s_b_12_5 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_12_6 = s_b_12_4==s_b_12_5 (const) */
    uint8_t s_b_12_6 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_12_7: If s_b_12_6: Jump b_2 else b_16 (const) */
    if (s_b_12_6) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4057 [D] s_b_13_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4057 [F] s_b_13_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2684 [F] s_b_14_0=sym_11885_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_62147_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_62147_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_10,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2684 [F] s_b_15_0=sym_11885_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_62245_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_62245_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1);
    /* execute.a64:0 [F] s_b_15_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2684 [F] s_b_16_0=sym_11885_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_62289_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_62289_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_frintx(const aarch64_decode_a64_FP_DP_1&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_12563_0_rmode;
  auto DV_sym_12563_0_rmode = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4590 [F] s_b_0_0=sym_12556_3_parameter_inst.opcode (const) */
    /* execute.simd:4591 [F] s_b_0_1 = constant s32 8 (const) */
    /* execute.simd:4595 [F] s_b_0_2 = constant s32 9 (const) */
    /* execute.simd:4599 [F] s_b_0_3 = constant s32 a (const) */
    /* execute.simd:4603 [F] s_b_0_4 = constant s32 b (const) */
    /* execute.simd:4607 [F] s_b_0_5 = constant s32 c (const) */
    /* execute.simd:4611 [F] s_b_0_6 = constant s32 e (const) */
    /* execute.simd:4615 [F] s_b_0_7 = constant s32 f (const) */
    /* execute.simd:4590 [F] s_b_0_8: Switch s_b_0_0: < <todo> > def b_9 (const) -> b_8, b_7, b_6, b_5, b_4, b_3, b_2, b_9,  */
    switch (insn.opcode) 
    {
    case (int32_t)15ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)14ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)8ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)12ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)11ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)10ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)9ULL:
      goto fixed_block_b_3;
      break;
    default:
      goto fixed_block_b_9;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8, b_9,  */
  fixed_block_b_1: 
  {
    /* execute.simd:4625 [F] s_b_1_0=sym_12556_3_parameter_inst.type (const) */
    /* execute.simd:4625 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4625 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4625 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4625 [F] s_b_1_4: If s_b_1_3: Jump b_10 else b_12 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:4592 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:4592 [F] s_b_2_1: sym_12563_0_rmode = s_b_2_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12563_0_rmode = (uint8_t)0ULL;
    emitter.store_local(DV_sym_12563_0_rmode, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:0 [F] s_b_2_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4596 [F] s_b_3_0 = constant u8 1 (const) */
    /* execute.simd:4596 [F] s_b_3_1: sym_12563_0_rmode = s_b_3_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12563_0_rmode = (uint8_t)1ULL;
    emitter.store_local(DV_sym_12563_0_rmode, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:0 [F] s_b_3_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4600 [F] s_b_4_0 = constant u8 2 (const) */
    /* execute.simd:4600 [F] s_b_4_1: sym_12563_0_rmode = s_b_4_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12563_0_rmode = (uint8_t)2ULL;
    emitter.store_local(DV_sym_12563_0_rmode, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:0 [F] s_b_4_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4604 [F] s_b_5_0 = constant u8 3 (const) */
    /* execute.simd:4604 [F] s_b_5_1: sym_12563_0_rmode = s_b_5_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12563_0_rmode = (uint8_t)3ULL;
    emitter.store_local(DV_sym_12563_0_rmode, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:0 [F] s_b_5_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4608 [F] s_b_6_0 = constant u8 0 (const) */
    /* execute.simd:4608 [F] s_b_6_1: sym_12563_0_rmode = s_b_6_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12563_0_rmode = (uint8_t)0ULL;
    emitter.store_local(DV_sym_12563_0_rmode, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:0 [F] s_b_6_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4612 [D] s_b_7_0 = __builtin_get_fp_rounding */
    auto s_b_7_0 = emitter.call(__captive___builtin_get_fp_rounding);
    /* execute.simd:4612 [D] s_b_7_1 = (u8)s_b_7_0 */
    auto s_b_7_1 = emitter.truncate(s_b_7_0, emitter.context().types().u8());
    /* execute.simd:4612 [D] s_b_7_2: sym_12563_0_rmode = s_b_7_1, dominates: s_b_10_3 s_b_12_3  */
    emitter.store_local(DV_sym_12563_0_rmode, s_b_7_1);
    /* execute.simd:0 [F] s_b_7_3: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4616 [D] s_b_8_0 = __builtin_get_fp_rounding */
    auto s_b_8_0 = emitter.call(__captive___builtin_get_fp_rounding);
    /* execute.simd:4616 [D] s_b_8_1 = (u8)s_b_8_0 */
    auto s_b_8_1 = emitter.truncate(s_b_8_0, emitter.context().types().u8());
    /* execute.simd:4616 [D] s_b_8_2: sym_12563_0_rmode = s_b_8_1, dominates: s_b_10_3 s_b_12_3  */
    emitter.store_local(DV_sym_12563_0_rmode, s_b_8_1);
    /* execute.simd:0 [F] s_b_8_3: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4620 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4626 [F] s_b_10_0=sym_12556_3_parameter_inst.rn (const) */
    /* execute.simd:6159 [D] s_b_10_1 = ReadRegBank 9:s_b_10_0 (f32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(4));
    }
    /* execute.simd:4627 [F] s_b_10_2=sym_12556_3_parameter_inst.rd (const) */
    /* execute.simd:4627 [D] s_b_10_3 = sym_12563_0_rmode uint8_t */
    auto s_b_10_3 = emitter.load_local(DV_sym_12563_0_rmode, emitter.context().types().u8());
    /* execute.simd:4627 [D] s_b_10_4 = __builtin_f32_round */
    auto s_b_10_4 = emitter.call(__captive___builtin_f32_round, s_b_10_1, s_b_10_3);
    /* execute.simd:6169 [D] s_b_10_5: WriteRegBank 9:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4);
    /* execute.simd:6170 [F] s_b_10_6 = constant u32 0 (const) */
    /* execute.simd:6170 [F] s_b_10_7: WriteRegBank 10:s_b_10_2 = s_b_10_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6171 [F] s_b_10_8 = constant u64 0 (const) */
    /* execute.simd:6171 [F] s_b_10_9: WriteRegBank 3:s_b_10_2 = s_b_10_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_10_10: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_12,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [F] s_b_11_0: Return */
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_12: 
  {
    /* execute.simd:4629 [F] s_b_12_0=sym_12556_3_parameter_inst.rn (const) */
    /* execute.simd:6164 [D] s_b_12_1 = ReadRegBank 11:s_b_12_0 (f64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:4630 [F] s_b_12_2=sym_12556_3_parameter_inst.rd (const) */
    /* execute.simd:4630 [D] s_b_12_3 = sym_12563_0_rmode uint8_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_12563_0_rmode, emitter.context().types().u8());
    /* execute.simd:4630 [D] s_b_12_4 = __builtin_f64_round */
    auto s_b_12_4 = emitter.call(__captive___builtin_f64_round, s_b_12_1, s_b_12_3);
    /* execute.simd:6177 [D] s_b_12_5: WriteRegBank 11:s_b_12_2 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_4);
    /* execute.simd:6178 [F] s_b_12_6 = constant u64 0 (const) */
    /* execute.simd:6178 [F] s_b_12_7: WriteRegBank 3:s_b_12_2 = s_b_12_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_12_8: Jump b_11 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ld1pi(const aarch64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_64038_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64231_1__R_s_b_33_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64308_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63904_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63854_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_64035_1_tmp_s_b_5_4;
  auto DV_sym_63925_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_63906_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_63993_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_64084_1__R_s_b_7_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64103_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64159_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63942_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_64010_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_63908_3_parameter_rt;
  auto DV_sym_63959_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  uint8_t CV_sym_63914_3_parameter_lane;
  auto DV_sym_63976_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_13133_0_lane;
  uint8_t CV_sym_13113_0_rt;
  auto DV_sym_13107_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13101_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_27 else b_9 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_6, b_10,  */
  fixed_block_b_1: 
  {
    /* execute.simd:2486 [F] s_b_1_0 = sym_13113_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13113_0_rt;
    /* execute.simd:2486 [F] s_b_1_1=sym_13101_3_parameter_inst.regcnt (const) */
    /* execute.simd:2486 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2486 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2487 [F] s_b_2_0=sym_13101_3_parameter_inst.rt (const) */
    /* execute.simd:2487 [F] s_b_2_1 = sym_13113_0_rt (const) uint8_t */
    uint8_t s_b_2_1 = CV_sym_13113_0_rt;
    /* execute.simd:2487 [F] s_b_2_2 = s_b_2_0+s_b_2_1 (const) */
    uint8_t s_b_2_2 = ((uint8_t)(insn.rt + s_b_2_1));
    /* execute.simd:2487 [F] s_b_2_3 = constant u64 0 (const) */
    /* execute.simd:2487 [F] s_b_2_4 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_2_5: WriteRegBank 2:s_b_2_2 = s_b_2_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6213 [F] s_b_2_6: WriteRegBank 3:s_b_2_2 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2488 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:2488 [F] s_b_2_8: sym_13133_0_lane = s_b_2_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_13133_0_lane = (uint8_t)0ULL;
    /* execute.simd:2488 [F] s_b_2_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2494 [F] s_b_3_0=sym_13101_3_parameter_inst.rm (const) */
    /* execute.simd:2494 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2494 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2494 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2494 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_19,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2488 [F] s_b_4_0 = sym_13133_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13133_0_lane;
    /* execute.simd:2488 [F] s_b_4_1=sym_13101_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2488 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2488 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2489 [F] s_b_5_0=sym_13101_3_parameter_inst.arrangement (const) */
    /* execute.simd:2489 [F] s_b_5_1=sym_13101_3_parameter_inst.rt (const) */
    /* execute.simd:2489 [F] s_b_5_2 = sym_13113_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13113_0_rt;
    /* execute.simd:2489 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2489 [F] s_b_5_4 = sym_13133_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13133_0_lane;
    /* execute.simd:2489 [D] s_b_5_5 = sym_13107_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13107_0_address, emitter.context().types().u64());
    /* execute.simd:2489 [F] s_b_5_6: sym_63908_3_parameter_rt = s_b_5_3 (const), dominates: s_b_17_2 s_b_16_2 s_b_15_2 s_b_14_2 s_b_13_2 s_b_12_2 s_b_18_2  */
    CV_sym_63908_3_parameter_rt = s_b_5_3;
    /* execute.simd:2489 [F] s_b_5_7: sym_63914_3_parameter_lane = s_b_5_4 (const), dominates: s_b_17_5 s_b_16_5 s_b_15_5 s_b_14_5 s_b_13_5 s_b_12_5 s_b_18_5  */
    CV_sym_63914_3_parameter_lane = s_b_5_4;
    /* execute.simd:2489 [D] s_b_5_8: sym_63904_3_parameter_addr = s_b_5_5, dominates: s_b_17_0 s_b_16_0 s_b_15_0 s_b_14_0 s_b_13_0 s_b_12_0 s_b_18_0  */
    emitter.store_local(DV_sym_63904_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_64035_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_19_1  */
    CV_sym_64035_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_64038_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_64038_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3767 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3776 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3785 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3794 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3803 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3812 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3821 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3766 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_11 (const) -> b_17, b_16, b_15, b_14, b_13, b_12, b_18, b_11,  */
    switch (insn.arrangement) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_13;
      break;
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2486 [F] s_b_6_0 = sym_13113_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13113_0_rt;
    /* execute.simd:2486 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2486 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2486 [F] s_b_6_3: sym_13113_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_13113_0_rt = s_b_6_2;
    /* execute.simd:2486 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2730 [F] s_b_7_0=sym_13101_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2730 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_7_4: If s_b_7_3: Jump b_32 else b_20 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_32;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_3, b_21,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2498 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2498 [D] s_b_8_1 = sym_13107_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_13107_0_address, emitter.context().types().u64());
    /* execute.simd:2498 [D] s_b_8_2: sym_64103_3_parameter_value = s_b_8_1, dominates: s_b_22_0 s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_64103_3_parameter_value, s_b_8_1);
    /* execute.a64:2746 [F] s_b_8_3 = !s_b_8_0 (const) */
    uint8_t s_b_8_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_8_4: If s_b_8_3: Jump b_22 else b_23 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2733 [F] s_b_9_0=sym_13101_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_9_2: sym_63854_1__R_s_b_0_5 = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_63854_1__R_s_b_0_5, s_b_9_1);
    /* execute.a64:2733 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_31,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2484 [D] s_b_10_0 = sym_63854_1__R_s_b_0_5 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_63854_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2484 [D] s_b_10_1: sym_13107_0_address = s_b_10_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13107_0_address, s_b_10_0);
    /* execute.simd:2486 [F] s_b_10_2 = constant u8 0 (const) */
    /* execute.simd:2486 [F] s_b_10_3: sym_13113_0_rt = s_b_10_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_13113_0_rt = (uint8_t)0ULL;
    /* execute.simd:2486 [F] s_b_10_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3831 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_11_1: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3769 [D] s_b_12_0 = sym_63904_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_63904_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 1 s_b_12_0 => sym_63906_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_63906_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(1));
    }
    /* execute.simd:3771 [F] s_b_12_2 = sym_63908_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_63908_3_parameter_rt;
    /* execute.simd:3771 [D] s_b_12_3 = ReadRegBank 15:s_b_12_2 (v8u8) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3772 [D] s_b_12_4 = sym_63906_0_mem_value uint8_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_63906_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3772 [F] s_b_12_5 = sym_63914_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_63914_3_parameter_lane;
    /* execute.simd:3772 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3772 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3773 [D] s_b_12_8: WriteRegBank 15:s_b_12_2 = s_b_12_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7);
    /* execute.simd:0 [F] s_b_12_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3778 [D] s_b_13_0 = sym_63904_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_63904_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 1 s_b_13_0 => sym_63925_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_63925_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(1));
    }
    /* execute.simd:3780 [F] s_b_13_2 = sym_63908_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_63908_3_parameter_rt;
    /* execute.simd:3780 [D] s_b_13_3 = ReadRegBank 16:s_b_13_2 (v16u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3781 [D] s_b_13_4 = sym_63925_0_mem_value uint8_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_63925_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3781 [F] s_b_13_5 = sym_63914_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_63914_3_parameter_lane;
    /* execute.simd:3781 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3781 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3782 [D] s_b_13_8: WriteRegBank 16:s_b_13_2 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7);
    /* execute.simd:0 [F] s_b_13_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_14: 
  {
    /* execute.simd:3787 [D] s_b_14_0 = sym_63904_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_63904_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 2 s_b_14_0 => sym_63942_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_63942_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(2));
    }
    /* execute.simd:3789 [F] s_b_14_2 = sym_63908_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_63908_3_parameter_rt;
    /* execute.simd:3789 [D] s_b_14_3 = ReadRegBank 17:s_b_14_2 (v4u16) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3790 [D] s_b_14_4 = sym_63942_0_mem_value uint16_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_63942_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3790 [F] s_b_14_5 = sym_63914_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_63914_3_parameter_lane;
    /* execute.simd:3790 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3790 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3791 [D] s_b_14_8: WriteRegBank 17:s_b_14_2 = s_b_14_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7);
    /* execute.simd:0 [F] s_b_14_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3796 [D] s_b_15_0 = sym_63904_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_63904_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_63959_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_63959_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3798 [F] s_b_15_2 = sym_63908_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_63908_3_parameter_rt;
    /* execute.simd:3798 [D] s_b_15_3 = ReadRegBank 18:s_b_15_2 (v8u16) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3799 [D] s_b_15_4 = sym_63959_0_mem_value uint16_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_63959_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3799 [F] s_b_15_5 = sym_63914_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_63914_3_parameter_lane;
    /* execute.simd:3799 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3799 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3800 [D] s_b_15_8: WriteRegBank 18:s_b_15_2 = s_b_15_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7);
    /* execute.simd:0 [F] s_b_15_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3805 [D] s_b_16_0 = sym_63904_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_63904_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 4 s_b_16_0 => sym_63976_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_63976_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(4));
    }
    /* execute.simd:3807 [F] s_b_16_2 = sym_63908_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_63908_3_parameter_rt;
    /* execute.simd:3807 [D] s_b_16_3 = ReadRegBank 19:s_b_16_2 (v2u32) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(8));
    }
    /* execute.simd:3808 [D] s_b_16_4 = sym_63976_0_mem_value uint32_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_63976_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3808 [F] s_b_16_5 = sym_63914_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_63914_3_parameter_lane;
    /* execute.simd:3808 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3808 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3809 [D] s_b_16_8: WriteRegBank 19:s_b_16_2 = s_b_16_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7);
    /* execute.simd:0 [F] s_b_16_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3814 [D] s_b_17_0 = sym_63904_3_parameter_addr uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_63904_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_63993_0_mem_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_63993_0_mem_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3816 [F] s_b_17_2 = sym_63908_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_2 = CV_sym_63908_3_parameter_rt;
    /* execute.simd:3816 [D] s_b_17_3 = ReadRegBank 20:s_b_17_2 (v4u32) */
    auto s_b_17_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_3,emitter.const_u8(16));
    }
    /* execute.simd:3817 [D] s_b_17_4 = sym_63993_0_mem_value uint32_t */
    auto s_b_17_4 = emitter.load_local(DV_sym_63993_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3817 [F] s_b_17_5 = sym_63914_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_5 = CV_sym_63914_3_parameter_lane;
    /* execute.simd:3817 [F] s_b_17_6 = (s32)s_b_17_5 (const) */
    /* execute.simd:3817 [D] s_b_17_7 = s_b_17_3[s_b_17_6] <= s_b_17_4 */
    auto s_b_17_7 = emitter.vector_insert(s_b_17_3, emitter.const_s32(((int32_t)s_b_17_5)), s_b_17_4);
    /* execute.simd:3818 [D] s_b_17_8: WriteRegBank 20:s_b_17_2 = s_b_17_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_7);
    /* execute.simd:0 [F] s_b_17_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3823 [D] s_b_18_0 = sym_63904_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_63904_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 8 s_b_18_0 => sym_64010_0_mem_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_64010_0_mem_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(8));
    }
    /* execute.simd:3825 [F] s_b_18_2 = sym_63908_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_2 = CV_sym_63908_3_parameter_rt;
    /* execute.simd:3825 [D] s_b_18_3 = ReadRegBank 21:s_b_18_2 (v2u64) */
    auto s_b_18_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_3,emitter.const_u8(16));
    }
    /* execute.simd:3826 [D] s_b_18_4 = sym_64010_0_mem_value uint64_t */
    auto s_b_18_4 = emitter.load_local(DV_sym_64010_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3826 [F] s_b_18_5 = sym_63914_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_5 = CV_sym_63914_3_parameter_lane;
    /* execute.simd:3826 [F] s_b_18_6 = (s32)s_b_18_5 (const) */
    /* execute.simd:3826 [D] s_b_18_7 = s_b_18_3[s_b_18_6] <= s_b_18_4 */
    auto s_b_18_7 = emitter.vector_insert(s_b_18_3, emitter.const_s32(((int32_t)s_b_18_5)), s_b_18_4);
    /* execute.simd:3827 [D] s_b_18_8: WriteRegBank 21:s_b_18_2 = s_b_18_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_7);
    /* execute.simd:0 [F] s_b_18_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_11, b_12, b_13, b_14, b_15, b_16, b_17, b_18,  */
  fixed_block_b_19: 
  {
    /* ???:4294967295 [D] s_b_19_0 = sym_64038_1_tmp_s_b_5_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_64038_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1 = sym_64035_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_19_1 = CV_sym_64035_1_tmp_s_b_5_4;
    /* execute.simd:2490 [F] s_b_19_2=sym_13101_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_19_3 = (u64)s_b_19_2 (const) */
    /* ???:4294967295 [D] s_b_19_4 = s_b_19_0+s_b_19_3 */
    auto s_b_19_4 = emitter.add(s_b_19_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2490 [D] s_b_19_5: sym_13107_0_address = s_b_19_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13107_0_address, s_b_19_4);
    /* execute.simd:2488 [F] s_b_19_6 = constant u8 1 (const) */
    /* execute.simd:2488 [F] s_b_19_7 = s_b_19_1+s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(s_b_19_1 + (uint8_t)1ULL));
    /* execute.simd:2488 [F] s_b_19_8: sym_13133_0_lane = s_b_19_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_13133_0_lane = s_b_19_7;
    /* execute.simd:2488 [F] s_b_19_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2733 [F] s_b_20_0=sym_13101_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_20_2: sym_64084_1__R_s_b_7_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_64084_1__R_s_b_7_5, s_b_20_1);
    /* execute.a64:2733 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_36,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2495 [D] s_b_21_0 = sym_64084_1__R_s_b_7_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_64084_1__R_s_b_7_5, emitter.context().types().u64());
    /* execute.simd:2495 [F] s_b_21_1=sym_13101_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_21_2 = (u32)s_b_21_1 (const) */
    /* execute.a64:2651 [F] s_b_21_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_21_4 = s_b_21_2==s_b_21_3 (const) */
    uint8_t s_b_21_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_21_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_21_6 = ReadRegBank 0:s_b_21_1 (u64) */
    auto s_b_21_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_21_7: Select s_b_21_4 ? s_b_21_5 : s_b_21_6 */
    dbt::el::Value *s_b_21_7;
    s_b_21_7 = (s_b_21_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_21_6);
    /* execute.simd:2495 [D] s_b_21_8 = s_b_21_0+s_b_21_7 */
    auto s_b_21_8 = emitter.add(s_b_21_0, s_b_21_7);
    /* execute.simd:2495 [D] s_b_21_9: sym_13107_0_address = s_b_21_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_13107_0_address, s_b_21_8);
    /* execute.simd:2495 [F] s_b_21_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_8,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2747 [D] s_b_22_0 = sym_64103_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_64103_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_22_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_22_2 = s_b_22_0&s_b_22_1 */
    auto s_b_22_2 = emitter.bitwise_and(s_b_22_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_22_3: sym_64103_3_parameter_value = s_b_22_2, dominates: s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_64103_3_parameter_value, s_b_22_2);
    /* execute.a64:2747 [F] s_b_22_4: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2750 [F] s_b_23_0=sym_13101_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2750 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_23_4: If s_b_23_3: Jump b_24 else b_25 (const) */
    if (s_b_23_3) 
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
    /* execute.a64:2751 [D] s_b_24_0 = sym_64103_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_64103_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_24_1: sym_64308_3_parameter_value = s_b_24_0, dominates: s_b_37_0 s_b_38_0 s_b_39_0  */
    emitter.store_local(DV_sym_64308_3_parameter_value, s_b_24_0);
    /* execute.a64:2714 [F] s_b_24_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_24_3 = __builtin_get_feature */
    uint32_t s_b_24_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_24_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_24_5 = s_b_24_3==s_b_24_4 (const) */
    uint8_t s_b_24_5 = ((uint8_t)(s_b_24_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_24_6: If s_b_24_5: Jump b_37 else b_42 (const) */
    if (s_b_24_5) 
    {
      goto fixed_block_b_37;
    }
    else 
    {
      goto fixed_block_b_42;
    }
  }
  /* b_23,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2753 [F] s_b_25_0=sym_13101_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_25_1 = sym_64103_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_64103_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1);
    /* execute.a64:2753 [F] s_b_25_3: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_25, b_37, b_38, b_39,  */
  fixed_block_b_26: 
  {
    /* ???:4294967295 [F] s_b_26_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2701 [F] s_b_27_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_27_1 = __builtin_get_feature */
    uint32_t s_b_27_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_27_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(s_b_27_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_27_4: If s_b_27_3: Jump b_28 else b_40 (const) */
    if (s_b_27_3) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_40;
    }
  }
  /* b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2702 [D] s_b_28_0 = ReadReg 20 (u64) */
    auto s_b_28_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_28_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_28_1: sym_64159_1__R_s_b_12_0 = s_b_28_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_64159_1__R_s_b_12_0, s_b_28_0);
    /* execute.a64:2702 [F] s_b_28_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_40,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2705 [D] s_b_29_0 = ReadReg 20 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_29_1: sym_64159_1__R_s_b_12_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_64159_1__R_s_b_12_0, s_b_29_0);
    /* execute.a64:2705 [F] s_b_29_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_40,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2707 [D] s_b_30_0 = ReadReg 21 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_30_1: sym_64159_1__R_s_b_12_0 = s_b_30_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_64159_1__R_s_b_12_0, s_b_30_0);
    /* execute.a64:2707 [F] s_b_30_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_28, b_29, b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2731 [D] s_b_31_0 = sym_64159_1__R_s_b_12_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_64159_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_31_1: sym_63854_1__R_s_b_0_5 = s_b_31_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_63854_1__R_s_b_0_5, s_b_31_0);
    /* execute.a64:2731 [F] s_b_31_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_7,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2701 [F] s_b_32_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_32_1 = __builtin_get_feature */
    uint32_t s_b_32_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_32_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_32_3 = s_b_32_1==s_b_32_2 (const) */
    uint8_t s_b_32_3 = ((uint8_t)(s_b_32_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_32_4: If s_b_32_3: Jump b_33 else b_41 (const) */
    if (s_b_32_3) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_41;
    }
  }
  /* b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2702 [D] s_b_33_0 = ReadReg 20 (u64) */
    auto s_b_33_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_33_1: sym_64231_1__R_s_b_33_0 = s_b_33_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_64231_1__R_s_b_33_0, s_b_33_0);
    /* execute.a64:2702 [F] s_b_33_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_41,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2705 [D] s_b_34_0 = ReadReg 20 (u64) */
    auto s_b_34_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_34_1: sym_64231_1__R_s_b_33_0 = s_b_34_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_64231_1__R_s_b_33_0, s_b_34_0);
    /* execute.a64:2705 [F] s_b_34_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_41,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2707 [D] s_b_35_0 = ReadReg 21 (u64) */
    auto s_b_35_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_35_1: sym_64231_1__R_s_b_33_0 = s_b_35_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_64231_1__R_s_b_33_0, s_b_35_0);
    /* execute.a64:2707 [F] s_b_35_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_33, b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2731 [D] s_b_36_0 = sym_64231_1__R_s_b_33_0 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_64231_1__R_s_b_33_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_36_1: sym_64084_1__R_s_b_7_5 = s_b_36_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_64084_1__R_s_b_7_5, s_b_36_0);
    /* execute.a64:2731 [F] s_b_36_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_24,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2715 [D] s_b_37_0 = sym_64308_3_parameter_value uint64_t */
    auto s_b_37_0 = emitter.load_local(DV_sym_64308_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_37_1: WriteReg 20 = s_b_37_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_37_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_37_0);
    /* execute.a64:2715 [F] s_b_37_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_42,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2718 [D] s_b_38_0 = sym_64308_3_parameter_value uint64_t */
    auto s_b_38_0 = emitter.load_local(DV_sym_64308_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_38_1: WriteReg 20 = s_b_38_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_38_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_38_0);
    /* execute.a64:2718 [F] s_b_38_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_42,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2720 [D] s_b_39_0 = sym_64308_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_64308_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_39_1: WriteReg 21 = s_b_39_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_39_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_39_0);
    /* execute.a64:2720 [F] s_b_39_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_27,  */
  fixed_block_b_40: 
  {
    /* execute.a64:3012 [F] s_b_40_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_40_1 = __builtin_get_feature */
    uint32_t s_b_40_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_40_2 = (u8)s_b_40_1 (const) */
    /* execute.a64:2704 [F] s_b_40_3 = (u32)s_b_40_2 (const) */
    /* execute.a64:2704 [F] s_b_40_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_40_5 = s_b_40_3==s_b_40_4 (const) */
    uint8_t s_b_40_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_40_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_40_6: If s_b_40_5: Jump b_29 else b_30 (const) */
    if (s_b_40_5) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_32,  */
  fixed_block_b_41: 
  {
    /* execute.a64:3012 [F] s_b_41_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_41_1 = __builtin_get_feature */
    uint32_t s_b_41_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_41_2 = (u8)s_b_41_1 (const) */
    /* execute.a64:2704 [F] s_b_41_3 = (u32)s_b_41_2 (const) */
    /* execute.a64:2704 [F] s_b_41_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_41_5 = s_b_41_3==s_b_41_4 (const) */
    uint8_t s_b_41_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_41_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_41_6: If s_b_41_5: Jump b_34 else b_35 (const) */
    if (s_b_41_5) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_24,  */
  fixed_block_b_42: 
  {
    /* execute.a64:3012 [F] s_b_42_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_42_1 = __builtin_get_feature */
    uint32_t s_b_42_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_42_2 = (u8)s_b_42_1 (const) */
    /* execute.a64:2717 [F] s_b_42_3 = (u32)s_b_42_2 (const) */
    /* execute.a64:2717 [F] s_b_42_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_42_5 = s_b_42_3==s_b_42_4 (const) */
    uint8_t s_b_42_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_42_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_42_6: If s_b_42_5: Jump b_38 else b_39 (const) */
    if (s_b_42_5) 
    {
      goto fixed_block_b_38;
    }
    else 
    {
      goto fixed_block_b_39;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ld4pi(const aarch64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_13946_0_lane;
  uint8_t CV_sym_13958_0_rt;
  auto DV_sym_67691_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67404_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67469_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67450_1__R_s_b_7_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67270_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67308_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_67359_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_67291_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_67325_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  uint8_t CV_sym_67280_3_parameter_lane;
  uint8_t CV_sym_67274_3_parameter_rt;
  auto DV_sym_67376_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67614_1__R_s_b_31_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_67401_1_tmp_s_b_5_2;
  auto DV_sym_67272_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_67525_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67237_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67342_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_13901_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13895_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_27 else b_9 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_6, b_10,  */
  fixed_block_b_1: 
  {
    /* execute.simd:2553 [F] s_b_1_0 = sym_13946_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13946_0_lane;
    /* execute.simd:2553 [F] s_b_1_1=sym_13895_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2553 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2553 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2554 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2554 [F] s_b_2_1: sym_13958_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13958_0_rt = (uint8_t)0ULL;
    /* execute.simd:2554 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2560 [F] s_b_3_0=sym_13895_3_parameter_inst.rm (const) */
    /* execute.simd:2560 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2560 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2560 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2560 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_19,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2554 [F] s_b_4_0 = sym_13958_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13958_0_rt;
    /* execute.simd:2554 [F] s_b_4_1=sym_13895_3_parameter_inst.regcnt (const) */
    /* execute.simd:2554 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2554 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2555 [F] s_b_5_0=sym_13895_3_parameter_inst.arrangement (const) */
    /* execute.simd:2555 [F] s_b_5_1=sym_13895_3_parameter_inst.rt (const) */
    /* execute.simd:2555 [F] s_b_5_2 = sym_13958_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13958_0_rt;
    /* execute.simd:2555 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2555 [F] s_b_5_4 = sym_13946_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13946_0_lane;
    /* execute.simd:2555 [D] s_b_5_5 = sym_13901_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13901_0_address, emitter.context().types().u64());
    /* execute.simd:2555 [F] s_b_5_6: sym_67274_3_parameter_rt = s_b_5_3 (const), dominates: s_b_18_2 s_b_13_2 s_b_14_2 s_b_12_2 s_b_17_2 s_b_16_2 s_b_15_2  */
    CV_sym_67274_3_parameter_rt = s_b_5_3;
    /* execute.simd:2555 [F] s_b_5_7: sym_67280_3_parameter_lane = s_b_5_4 (const), dominates: s_b_18_5 s_b_13_5 s_b_14_5 s_b_12_5 s_b_17_5 s_b_16_5 s_b_15_5  */
    CV_sym_67280_3_parameter_lane = s_b_5_4;
    /* execute.simd:2555 [D] s_b_5_8: sym_67270_3_parameter_addr = s_b_5_5, dominates: s_b_18_0 s_b_13_0 s_b_14_0 s_b_12_0 s_b_17_0 s_b_16_0 s_b_15_0  */
    emitter.store_local(DV_sym_67270_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_67401_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_19_1  */
    CV_sym_67401_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_67404_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_67404_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3767 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3776 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3785 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3794 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3803 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3812 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3821 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3766 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_11 (const) -> b_18, b_13, b_14, b_11, b_12, b_17, b_16, b_15,  */
    switch (insn.arrangement) 
    {
    case (int32_t)5ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_16;
      break;
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2553 [F] s_b_6_0 = sym_13946_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13946_0_lane;
    /* execute.simd:2553 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2553 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2553 [F] s_b_6_3: sym_13946_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13946_0_lane = s_b_6_2;
    /* execute.simd:2553 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2730 [F] s_b_7_0=sym_13895_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2730 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_7_4: If s_b_7_3: Jump b_32 else b_20 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_32;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_3, b_21,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2564 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2564 [D] s_b_8_1 = sym_13901_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_13901_0_address, emitter.context().types().u64());
    /* execute.simd:2564 [D] s_b_8_2: sym_67469_3_parameter_value = s_b_8_1, dominates: s_b_22_0 s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_67469_3_parameter_value, s_b_8_1);
    /* execute.a64:2746 [F] s_b_8_3 = !s_b_8_0 (const) */
    uint8_t s_b_8_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_8_4: If s_b_8_3: Jump b_22 else b_23 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2733 [F] s_b_9_0=sym_13895_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_9_2: sym_67237_1__R_s_b_0_5 = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_67237_1__R_s_b_0_5, s_b_9_1);
    /* execute.a64:2733 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_31,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2546 [D] s_b_10_0 = sym_67237_1__R_s_b_0_5 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_67237_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2546 [D] s_b_10_1: sym_13901_0_address = s_b_10_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13901_0_address, s_b_10_0);
    /* execute.simd:2548 [F] s_b_10_2=sym_13895_3_parameter_inst.rt (const) */
    /* execute.simd:2548 [F] s_b_10_3 = constant u64 0 (const) */
    /* execute.simd:2548 [F] s_b_10_4 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_10_5: WriteRegBank 2:s_b_10_2 = s_b_10_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6213 [F] s_b_10_6: WriteRegBank 3:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2549 [F] s_b_10_7=sym_13895_3_parameter_inst.rt (const) */
    /* execute.simd:2549 [F] s_b_10_8 = (u32)s_b_10_7 (const) */
    /* execute.simd:2549 [F] s_b_10_9 = constant u32 1 (const) */
    /* execute.simd:2549 [F] s_b_10_10 = s_b_10_8+s_b_10_9 (const) */
    uint32_t s_b_10_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2549 [F] s_b_10_11 = (u8)s_b_10_10 (const) */
    /* execute.simd:2549 [F] s_b_10_12 = constant u64 0 (const) */
    /* execute.simd:2549 [F] s_b_10_13 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_10_14: WriteRegBank 2:s_b_10_11 = s_b_10_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6213 [F] s_b_10_15: WriteRegBank 3:s_b_10_11 = s_b_10_13 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2550 [F] s_b_10_16=sym_13895_3_parameter_inst.rt (const) */
    /* execute.simd:2550 [F] s_b_10_17 = (u32)s_b_10_16 (const) */
    /* execute.simd:2550 [F] s_b_10_18 = constant u32 2 (const) */
    /* execute.simd:2550 [F] s_b_10_19 = s_b_10_17+s_b_10_18 (const) */
    uint32_t s_b_10_19 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)2ULL));
    /* execute.simd:2550 [F] s_b_10_20 = (u8)s_b_10_19 (const) */
    /* execute.simd:2550 [F] s_b_10_21 = constant u64 0 (const) */
    /* execute.simd:2550 [F] s_b_10_22 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_10_23: WriteRegBank 2:s_b_10_20 = s_b_10_21 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6213 [F] s_b_10_24: WriteRegBank 3:s_b_10_20 = s_b_10_22 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2551 [F] s_b_10_25=sym_13895_3_parameter_inst.rt (const) */
    /* execute.simd:2551 [F] s_b_10_26 = (u32)s_b_10_25 (const) */
    /* execute.simd:2551 [F] s_b_10_27 = constant u32 3 (const) */
    /* execute.simd:2551 [F] s_b_10_28 = s_b_10_26+s_b_10_27 (const) */
    uint32_t s_b_10_28 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)3ULL));
    /* execute.simd:2551 [F] s_b_10_29 = (u8)s_b_10_28 (const) */
    /* execute.simd:2551 [F] s_b_10_30 = constant u64 0 (const) */
    /* execute.simd:2551 [F] s_b_10_31 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_10_32: WriteRegBank 2:s_b_10_29 = s_b_10_30 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6213 [F] s_b_10_33: WriteRegBank 3:s_b_10_29 = s_b_10_31 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2553 [F] s_b_10_34 = constant u8 0 (const) */
    /* execute.simd:2553 [F] s_b_10_35: sym_13946_0_lane = s_b_10_34 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13946_0_lane = (uint8_t)0ULL;
    /* execute.simd:2553 [F] s_b_10_36: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3831 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_11_1: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3769 [D] s_b_12_0 = sym_67270_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_67270_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 1 s_b_12_0 => sym_67272_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_67272_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(1));
    }
    /* execute.simd:3771 [F] s_b_12_2 = sym_67274_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_67274_3_parameter_rt;
    /* execute.simd:3771 [D] s_b_12_3 = ReadRegBank 15:s_b_12_2 (v8u8) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3772 [D] s_b_12_4 = sym_67272_0_mem_value uint8_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_67272_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3772 [F] s_b_12_5 = sym_67280_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_67280_3_parameter_lane;
    /* execute.simd:3772 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3772 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3773 [D] s_b_12_8: WriteRegBank 15:s_b_12_2 = s_b_12_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7);
    /* execute.simd:0 [F] s_b_12_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3778 [D] s_b_13_0 = sym_67270_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_67270_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 1 s_b_13_0 => sym_67291_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_67291_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(1));
    }
    /* execute.simd:3780 [F] s_b_13_2 = sym_67274_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_67274_3_parameter_rt;
    /* execute.simd:3780 [D] s_b_13_3 = ReadRegBank 16:s_b_13_2 (v16u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3781 [D] s_b_13_4 = sym_67291_0_mem_value uint8_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_67291_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3781 [F] s_b_13_5 = sym_67280_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_67280_3_parameter_lane;
    /* execute.simd:3781 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3781 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3782 [D] s_b_13_8: WriteRegBank 16:s_b_13_2 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7);
    /* execute.simd:0 [F] s_b_13_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_14: 
  {
    /* execute.simd:3787 [D] s_b_14_0 = sym_67270_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_67270_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 2 s_b_14_0 => sym_67308_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_67308_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(2));
    }
    /* execute.simd:3789 [F] s_b_14_2 = sym_67274_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_67274_3_parameter_rt;
    /* execute.simd:3789 [D] s_b_14_3 = ReadRegBank 17:s_b_14_2 (v4u16) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3790 [D] s_b_14_4 = sym_67308_0_mem_value uint16_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_67308_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3790 [F] s_b_14_5 = sym_67280_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_67280_3_parameter_lane;
    /* execute.simd:3790 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3790 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3791 [D] s_b_14_8: WriteRegBank 17:s_b_14_2 = s_b_14_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7);
    /* execute.simd:0 [F] s_b_14_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3796 [D] s_b_15_0 = sym_67270_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_67270_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_67325_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_67325_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3798 [F] s_b_15_2 = sym_67274_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_67274_3_parameter_rt;
    /* execute.simd:3798 [D] s_b_15_3 = ReadRegBank 18:s_b_15_2 (v8u16) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3799 [D] s_b_15_4 = sym_67325_0_mem_value uint16_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_67325_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3799 [F] s_b_15_5 = sym_67280_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_67280_3_parameter_lane;
    /* execute.simd:3799 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3799 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3800 [D] s_b_15_8: WriteRegBank 18:s_b_15_2 = s_b_15_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7);
    /* execute.simd:0 [F] s_b_15_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3805 [D] s_b_16_0 = sym_67270_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_67270_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 4 s_b_16_0 => sym_67342_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_67342_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(4));
    }
    /* execute.simd:3807 [F] s_b_16_2 = sym_67274_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_67274_3_parameter_rt;
    /* execute.simd:3807 [D] s_b_16_3 = ReadRegBank 19:s_b_16_2 (v2u32) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(8));
    }
    /* execute.simd:3808 [D] s_b_16_4 = sym_67342_0_mem_value uint32_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_67342_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3808 [F] s_b_16_5 = sym_67280_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_67280_3_parameter_lane;
    /* execute.simd:3808 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3808 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3809 [D] s_b_16_8: WriteRegBank 19:s_b_16_2 = s_b_16_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7);
    /* execute.simd:0 [F] s_b_16_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3814 [D] s_b_17_0 = sym_67270_3_parameter_addr uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_67270_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_67359_0_mem_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_67359_0_mem_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3816 [F] s_b_17_2 = sym_67274_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_2 = CV_sym_67274_3_parameter_rt;
    /* execute.simd:3816 [D] s_b_17_3 = ReadRegBank 20:s_b_17_2 (v4u32) */
    auto s_b_17_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_3,emitter.const_u8(16));
    }
    /* execute.simd:3817 [D] s_b_17_4 = sym_67359_0_mem_value uint32_t */
    auto s_b_17_4 = emitter.load_local(DV_sym_67359_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3817 [F] s_b_17_5 = sym_67280_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_5 = CV_sym_67280_3_parameter_lane;
    /* execute.simd:3817 [F] s_b_17_6 = (s32)s_b_17_5 (const) */
    /* execute.simd:3817 [D] s_b_17_7 = s_b_17_3[s_b_17_6] <= s_b_17_4 */
    auto s_b_17_7 = emitter.vector_insert(s_b_17_3, emitter.const_s32(((int32_t)s_b_17_5)), s_b_17_4);
    /* execute.simd:3818 [D] s_b_17_8: WriteRegBank 20:s_b_17_2 = s_b_17_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_7);
    /* execute.simd:0 [F] s_b_17_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3823 [D] s_b_18_0 = sym_67270_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_67270_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 8 s_b_18_0 => sym_67376_0_mem_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_67376_0_mem_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(8));
    }
    /* execute.simd:3825 [F] s_b_18_2 = sym_67274_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_2 = CV_sym_67274_3_parameter_rt;
    /* execute.simd:3825 [D] s_b_18_3 = ReadRegBank 21:s_b_18_2 (v2u64) */
    auto s_b_18_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_3,emitter.const_u8(16));
    }
    /* execute.simd:3826 [D] s_b_18_4 = sym_67376_0_mem_value uint64_t */
    auto s_b_18_4 = emitter.load_local(DV_sym_67376_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3826 [F] s_b_18_5 = sym_67280_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_5 = CV_sym_67280_3_parameter_lane;
    /* execute.simd:3826 [F] s_b_18_6 = (s32)s_b_18_5 (const) */
    /* execute.simd:3826 [D] s_b_18_7 = s_b_18_3[s_b_18_6] <= s_b_18_4 */
    auto s_b_18_7 = emitter.vector_insert(s_b_18_3, emitter.const_s32(((int32_t)s_b_18_5)), s_b_18_4);
    /* execute.simd:3827 [D] s_b_18_8: WriteRegBank 21:s_b_18_2 = s_b_18_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_7);
    /* execute.simd:0 [F] s_b_18_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_11, b_12, b_13, b_14, b_15, b_16, b_17, b_18,  */
  fixed_block_b_19: 
  {
    /* ???:4294967295 [D] s_b_19_0 = sym_67404_1_tmp_s_b_5_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_67404_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1 = sym_67401_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_19_1 = CV_sym_67401_1_tmp_s_b_5_2;
    /* execute.simd:2556 [F] s_b_19_2=sym_13895_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_19_3 = (u64)s_b_19_2 (const) */
    /* ???:4294967295 [D] s_b_19_4 = s_b_19_0+s_b_19_3 */
    auto s_b_19_4 = emitter.add(s_b_19_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2556 [D] s_b_19_5: sym_13901_0_address = s_b_19_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13901_0_address, s_b_19_4);
    /* execute.simd:2554 [F] s_b_19_6 = constant u8 1 (const) */
    /* execute.simd:2554 [F] s_b_19_7 = s_b_19_1+s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(s_b_19_1 + (uint8_t)1ULL));
    /* execute.simd:2554 [F] s_b_19_8: sym_13958_0_rt = s_b_19_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13958_0_rt = s_b_19_7;
    /* execute.simd:2554 [F] s_b_19_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2733 [F] s_b_20_0=sym_13895_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_20_2: sym_67450_1__R_s_b_7_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_67450_1__R_s_b_7_5, s_b_20_1);
    /* execute.a64:2733 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_36,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2561 [D] s_b_21_0 = sym_67450_1__R_s_b_7_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_67450_1__R_s_b_7_5, emitter.context().types().u64());
    /* execute.simd:2561 [F] s_b_21_1=sym_13895_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_21_2 = (u32)s_b_21_1 (const) */
    /* execute.a64:2651 [F] s_b_21_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_21_4 = s_b_21_2==s_b_21_3 (const) */
    uint8_t s_b_21_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_21_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_21_6 = ReadRegBank 0:s_b_21_1 (u64) */
    auto s_b_21_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_21_7: Select s_b_21_4 ? s_b_21_5 : s_b_21_6 */
    dbt::el::Value *s_b_21_7;
    s_b_21_7 = (s_b_21_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_21_6);
    /* execute.simd:2561 [D] s_b_21_8 = s_b_21_0+s_b_21_7 */
    auto s_b_21_8 = emitter.add(s_b_21_0, s_b_21_7);
    /* execute.simd:2561 [D] s_b_21_9: sym_13901_0_address = s_b_21_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_13901_0_address, s_b_21_8);
    /* execute.simd:2561 [F] s_b_21_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_8,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2747 [D] s_b_22_0 = sym_67469_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_67469_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_22_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_22_2 = s_b_22_0&s_b_22_1 */
    auto s_b_22_2 = emitter.bitwise_and(s_b_22_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_22_3: sym_67469_3_parameter_value = s_b_22_2, dominates: s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_67469_3_parameter_value, s_b_22_2);
    /* execute.a64:2747 [F] s_b_22_4: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2750 [F] s_b_23_0=sym_13895_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2750 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_23_4: If s_b_23_3: Jump b_24 else b_25 (const) */
    if (s_b_23_3) 
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
    /* execute.a64:2751 [D] s_b_24_0 = sym_67469_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_67469_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_24_1: sym_67691_3_parameter_value = s_b_24_0, dominates: s_b_37_0 s_b_38_0 s_b_39_0  */
    emitter.store_local(DV_sym_67691_3_parameter_value, s_b_24_0);
    /* execute.a64:2714 [F] s_b_24_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_24_3 = __builtin_get_feature */
    uint32_t s_b_24_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_24_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_24_5 = s_b_24_3==s_b_24_4 (const) */
    uint8_t s_b_24_5 = ((uint8_t)(s_b_24_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_24_6: If s_b_24_5: Jump b_37 else b_42 (const) */
    if (s_b_24_5) 
    {
      goto fixed_block_b_37;
    }
    else 
    {
      goto fixed_block_b_42;
    }
  }
  /* b_23,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2753 [F] s_b_25_0=sym_13895_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_25_1 = sym_67469_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_67469_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1);
    /* execute.a64:2753 [F] s_b_25_3: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_25, b_37, b_38, b_39,  */
  fixed_block_b_26: 
  {
    /* ???:4294967295 [F] s_b_26_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2701 [F] s_b_27_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_27_1 = __builtin_get_feature */
    uint32_t s_b_27_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_27_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(s_b_27_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_27_4: If s_b_27_3: Jump b_28 else b_40 (const) */
    if (s_b_27_3) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_40;
    }
  }
  /* b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2702 [D] s_b_28_0 = ReadReg 20 (u64) */
    auto s_b_28_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_28_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_28_1: sym_67525_1__R_s_b_12_0 = s_b_28_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67525_1__R_s_b_12_0, s_b_28_0);
    /* execute.a64:2702 [F] s_b_28_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_40,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2705 [D] s_b_29_0 = ReadReg 20 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_29_1: sym_67525_1__R_s_b_12_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67525_1__R_s_b_12_0, s_b_29_0);
    /* execute.a64:2705 [F] s_b_29_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_40,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2707 [D] s_b_30_0 = ReadReg 21 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_30_1: sym_67525_1__R_s_b_12_0 = s_b_30_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67525_1__R_s_b_12_0, s_b_30_0);
    /* execute.a64:2707 [F] s_b_30_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_28, b_29, b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2731 [D] s_b_31_0 = sym_67525_1__R_s_b_12_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_67525_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_31_1: sym_67237_1__R_s_b_0_5 = s_b_31_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_67237_1__R_s_b_0_5, s_b_31_0);
    /* execute.a64:2731 [F] s_b_31_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_7,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2701 [F] s_b_32_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_32_1 = __builtin_get_feature */
    uint32_t s_b_32_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_32_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_32_3 = s_b_32_1==s_b_32_2 (const) */
    uint8_t s_b_32_3 = ((uint8_t)(s_b_32_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_32_4: If s_b_32_3: Jump b_33 else b_41 (const) */
    if (s_b_32_3) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_41;
    }
  }
  /* b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2702 [D] s_b_33_0 = ReadReg 20 (u64) */
    auto s_b_33_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_33_1: sym_67614_1__R_s_b_31_0 = s_b_33_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_67614_1__R_s_b_31_0, s_b_33_0);
    /* execute.a64:2702 [F] s_b_33_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_41,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2705 [D] s_b_34_0 = ReadReg 20 (u64) */
    auto s_b_34_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_34_1: sym_67614_1__R_s_b_31_0 = s_b_34_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_67614_1__R_s_b_31_0, s_b_34_0);
    /* execute.a64:2705 [F] s_b_34_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_41,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2707 [D] s_b_35_0 = ReadReg 21 (u64) */
    auto s_b_35_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_35_1: sym_67614_1__R_s_b_31_0 = s_b_35_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_67614_1__R_s_b_31_0, s_b_35_0);
    /* execute.a64:2707 [F] s_b_35_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_33, b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2731 [D] s_b_36_0 = sym_67614_1__R_s_b_31_0 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_67614_1__R_s_b_31_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_36_1: sym_67450_1__R_s_b_7_5 = s_b_36_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_67450_1__R_s_b_7_5, s_b_36_0);
    /* execute.a64:2731 [F] s_b_36_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_24,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2715 [D] s_b_37_0 = sym_67691_3_parameter_value uint64_t */
    auto s_b_37_0 = emitter.load_local(DV_sym_67691_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_37_1: WriteReg 20 = s_b_37_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_37_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_37_0);
    /* execute.a64:2715 [F] s_b_37_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_42,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2718 [D] s_b_38_0 = sym_67691_3_parameter_value uint64_t */
    auto s_b_38_0 = emitter.load_local(DV_sym_67691_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_38_1: WriteReg 20 = s_b_38_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_38_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_38_0);
    /* execute.a64:2718 [F] s_b_38_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_42,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2720 [D] s_b_39_0 = sym_67691_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_67691_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_39_1: WriteReg 21 = s_b_39_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_39_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_39_0);
    /* execute.a64:2720 [F] s_b_39_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_27,  */
  fixed_block_b_40: 
  {
    /* execute.a64:3012 [F] s_b_40_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_40_1 = __builtin_get_feature */
    uint32_t s_b_40_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_40_2 = (u8)s_b_40_1 (const) */
    /* execute.a64:2704 [F] s_b_40_3 = (u32)s_b_40_2 (const) */
    /* execute.a64:2704 [F] s_b_40_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_40_5 = s_b_40_3==s_b_40_4 (const) */
    uint8_t s_b_40_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_40_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_40_6: If s_b_40_5: Jump b_29 else b_30 (const) */
    if (s_b_40_5) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_32,  */
  fixed_block_b_41: 
  {
    /* execute.a64:3012 [F] s_b_41_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_41_1 = __builtin_get_feature */
    uint32_t s_b_41_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_41_2 = (u8)s_b_41_1 (const) */
    /* execute.a64:2704 [F] s_b_41_3 = (u32)s_b_41_2 (const) */
    /* execute.a64:2704 [F] s_b_41_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_41_5 = s_b_41_3==s_b_41_4 (const) */
    uint8_t s_b_41_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_41_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_41_6: If s_b_41_5: Jump b_34 else b_35 (const) */
    if (s_b_41_5) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_24,  */
  fixed_block_b_42: 
  {
    /* execute.a64:3012 [F] s_b_42_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_42_1 = __builtin_get_feature */
    uint32_t s_b_42_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_42_2 = (u8)s_b_42_1 (const) */
    /* execute.a64:2717 [F] s_b_42_3 = (u32)s_b_42_2 (const) */
    /* execute.a64:2717 [F] s_b_42_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_42_5 = s_b_42_3==s_b_42_4 (const) */
    uint8_t s_b_42_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_42_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_42_6: If s_b_42_5: Jump b_38 else b_39 (const) */
    if (s_b_42_5) 
    {
      goto fixed_block_b_38;
    }
    else 
    {
      goto fixed_block_b_39;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldnp(const aarch64_decode_a64_LS_NO_ALLOC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14262_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_82032_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_83232_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_82458_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_82061_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_82383_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_83884_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_82429_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_83360_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_82164_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_82884_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_82255_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_82781_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84166_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_82235_1_tmp_s_b_1_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_85446_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_85380_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14253_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_4 (const) */
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
    /* execute.a64:882 [D] s_b_1_0 = sym_14262_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14262_0_addr, emitter.context().types().u64());
    /* execute.a64:882 [D] s_b_1_1: sym_82061_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_82061_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2: sym_82235_1_tmp_s_b_1_0 = s_b_1_0, dominates: s_b_6_3  */
    emitter.store_local(DV_sym_82235_1_tmp_s_b_1_0, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_3 = Load 4 s_b_1_0 => sym_82164_0_data32 */
    auto s_b_1_3 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_82164_0_data32, s_b_1_3);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_3, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_1_4 = sym_82164_0_data32 uint32_t */
    auto s_b_1_4 = emitter.load_local(DV_sym_82164_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_1_5 = (u64)s_b_1_4 */
    auto s_b_1_5 = emitter.zx(s_b_1_4, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_6=sym_14253_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_7 = (u32)s_b_1_5 */
    auto s_b_1_7 = emitter.truncate(s_b_1_5, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_8 = (u64)s_b_1_7 */
    auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_9: sym_83884_3_parameter_value = s_b_1_8, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_83884_3_parameter_value, s_b_1_8);
    /* execute.a64:2682 [F] s_b_1_10 = (u32)s_b_1_6 (const) */
    /* execute.a64:2682 [F] s_b_1_11 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_1_12 = s_b_1_10==s_b_1_11 (const) */
    uint8_t s_b_1_12 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_1_13: If s_b_1_12: Jump b_6 else b_16 (const) */
    if (s_b_1_12) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_13, b_14,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_5,  */
  fixed_block_b_3: 
  {
    /* execute.a64:885 [D] s_b_3_0 = sym_14262_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14262_0_addr, emitter.context().types().u64());
    /* execute.a64:885 [D] s_b_3_1: sym_82255_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_82255_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2: sym_82429_1_tmp_s_b_3_0 = s_b_3_0, dominates: s_b_7_3  */
    emitter.store_local(DV_sym_82429_1_tmp_s_b_3_0, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_3 = Load 8 s_b_3_0 => sym_82383_0_data64 */
    auto s_b_3_3 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_82383_0_data64, s_b_3_3);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_3, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_3_4 = sym_82383_0_data64 uint64_t */
    auto s_b_3_4 = emitter.load_local(DV_sym_82383_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_3_5=sym_14253_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_3_6: sym_84166_3_parameter_value = s_b_3_4, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_84166_3_parameter_value, s_b_3_4);
    /* execute.a64:2682 [F] s_b_3_7 = (u32)s_b_3_5 (const) */
    /* execute.a64:2682 [F] s_b_3_8 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_3_9 = s_b_3_7==s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_3_10: If s_b_3_9: Jump b_7 else b_17 (const) */
    if (s_b_3_9) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2733 [F] s_b_4_0=sym_14253_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_4_2: sym_82032_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_82032_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2733 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:879 [D] s_b_5_0 = sym_82032_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_82032_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:879 [F] s_b_5_1=sym_14253_3_parameter_inst.imms64 (const) */
    /* execute.a64:879 [F] s_b_5_2 = (u64)s_b_5_1 (const) */
    /* execute.a64:879 [D] s_b_5_3 = s_b_5_0+s_b_5_2 */
    auto s_b_5_3 = emitter.add(s_b_5_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:879 [D] s_b_5_4: sym_14262_0_addr = s_b_5_3, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14262_0_addr, s_b_5_3);
    /* execute.a64:881 [F] s_b_5_5=sym_14253_3_parameter_inst.opc (const) */
    /* execute.a64:881 [F] s_b_5_6 = (u32)s_b_5_5 (const) */
    /* execute.a64:881 [F] s_b_5_7 = constant u32 0 (const) */
    /* execute.a64:881 [F] s_b_5_8 = s_b_5_6==s_b_5_7 (const) */
    uint8_t s_b_5_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:881 [F] s_b_5_9: If s_b_5_8: Jump b_1 else b_3 (const) */
    if (s_b_5_8) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_1, b_16,  */
  fixed_block_b_6: 
  {
    /* execute.a64:1723 [F] s_b_6_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_6_1 = sym_82061_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_82061_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* ???:4294967295 [D] s_b_6_3 = sym_82235_1_tmp_s_b_1_0 uint64_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_82235_1_tmp_s_b_1_0, emitter.context().types().u64());
    /* execute.a64:883 [F] s_b_6_4 = constant u64 4 (const) */
    /* execute.a64:883 [D] s_b_6_5 = s_b_6_3+s_b_6_4 */
    auto s_b_6_5 = emitter.add(s_b_6_3, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:883 [D] s_b_6_6: sym_82781_3_parameter_address = s_b_6_5, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_82781_3_parameter_address, s_b_6_5);
    /* ???:4294967295 [D] s_b_6_7 = Load 4 s_b_6_5 => sym_82884_0_data32 */
    auto s_b_6_7 = emitter.load_memory(s_b_6_5, emitter.context().types().u32());
    emitter.store_local(DV_sym_82884_0_data32, s_b_6_7);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_5, s_b_6_7, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_6_8 = sym_82884_0_data32 uint32_t */
    auto s_b_6_8 = emitter.load_local(DV_sym_82884_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_10=sym_14253_3_parameter_inst.rt2 (const) */
    /* execute.a64:2693 [D] s_b_6_11 = (u32)s_b_6_9 */
    auto s_b_6_11 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_13: sym_85380_3_parameter_value = s_b_6_12, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_85380_3_parameter_value, s_b_6_12);
    /* execute.a64:2682 [F] s_b_6_14 = (u32)s_b_6_10 (const) */
    /* execute.a64:2682 [F] s_b_6_15 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_6_16 = s_b_6_14==s_b_6_15 (const) */
    uint8_t s_b_6_16 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_6_17: If s_b_6_16: Jump b_13 else b_18 (const) */
    if (s_b_6_16) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_3, b_17,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1723 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_7_1 = sym_82255_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_82255_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* ???:4294967295 [D] s_b_7_3 = sym_82429_1_tmp_s_b_3_0 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_82429_1_tmp_s_b_3_0, emitter.context().types().u64());
    /* execute.a64:886 [F] s_b_7_4 = constant u64 8 (const) */
    /* execute.a64:886 [D] s_b_7_5 = s_b_7_3+s_b_7_4 */
    auto s_b_7_5 = emitter.add(s_b_7_3, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:886 [D] s_b_7_6: sym_83232_3_parameter_address = s_b_7_5, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_83232_3_parameter_address, s_b_7_5);
    /* ???:4294967295 [D] s_b_7_7 = Load 8 s_b_7_5 => sym_83360_0_data64 */
    auto s_b_7_7 = emitter.load_memory(s_b_7_5, emitter.context().types().u64());
    emitter.store_local(DV_sym_83360_0_data64, s_b_7_7);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_5, s_b_7_7, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_7_8 = sym_83360_0_data64 uint64_t */
    auto s_b_7_8 = emitter.load_local(DV_sym_83360_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_9=sym_14253_3_parameter_inst.rt2 (const) */
    /* execute.a64:2691 [D] s_b_7_10: sym_85446_3_parameter_value = s_b_7_8, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_85446_3_parameter_value, s_b_7_8);
    /* execute.a64:2682 [F] s_b_7_11 = (u32)s_b_7_9 (const) */
    /* execute.a64:2682 [F] s_b_7_12 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_7_13 = s_b_7_11==s_b_7_12 (const) */
    uint8_t s_b_7_13 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_7_14: If s_b_7_13: Jump b_14 else b_19 (const) */
    if (s_b_7_13) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2701 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_8_4: If s_b_8_3: Jump b_9 else b_15 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2702 [D] s_b_9_0 = ReadReg 20 (u64) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_9_1: sym_82458_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_82458_1__R_s_b_7_0, s_b_9_0);
    /* execute.a64:2702 [F] s_b_9_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_15,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2705 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_10_1: sym_82458_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_82458_1__R_s_b_7_0, s_b_10_0);
    /* execute.a64:2705 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_15,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2707 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_11_1: sym_82458_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_82458_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2707 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2731 [D] s_b_12_0 = sym_82458_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_82458_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_12_1: sym_82032_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_82032_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2731 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_6, b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1723 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_13_1 = sym_82781_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_82781_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7, b_19,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1723 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_14_1 = sym_83232_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_83232_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_14_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_15: 
  {
    /* execute.a64:3012 [F] s_b_15_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_15_1 = __builtin_get_feature */
    uint32_t s_b_15_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_15_2 = (u8)s_b_15_1 (const) */
    /* execute.a64:2704 [F] s_b_15_3 = (u32)s_b_15_2 (const) */
    /* execute.a64:2704 [F] s_b_15_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_15_5 = s_b_15_3==s_b_15_4 (const) */
    uint8_t s_b_15_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_15_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_15_6: If s_b_15_5: Jump b_10 else b_11 (const) */
    if (s_b_15_5) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_1,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2684 [F] s_b_16_0=sym_14253_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_83884_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_83884_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2684 [F] s_b_17_0=sym_14253_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_17_1 = sym_84166_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_84166_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1);
    /* execute.a64:0 [F] s_b_17_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2684 [F] s_b_18_0=sym_14253_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_18_1 = sym_85380_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_85380_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_18_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_18_1);
    /* execute.a64:0 [F] s_b_18_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_7,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2684 [F] s_b_19_0=sym_14253_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_19_1 = sym_85446_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_85446_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_19_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_19_1);
    /* execute.a64:0 [F] s_b_19_3: Jump b_14 (const) */
    goto fixed_block_b_14;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldr_lit(const aarch64_decode_a64_LOAD_REG_LIT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14872_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92597_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92700_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_92788_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92916_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_93960_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_93938_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:585 [D] s_b_0_0 = read_pc */
    auto s_b_0_0 = emitter.load_pc();
    /* execute.a64:585 [F] s_b_0_1=sym_14866_3_parameter_inst.label (const) */
    /* execute.a64:585 [F] s_b_0_2 = (u64)s_b_0_1 (const) */
    /* execute.a64:585 [D] s_b_0_3 = s_b_0_0+s_b_0_2 */
    auto s_b_0_3 = emitter.add(s_b_0_0, emitter.const_u64(((uint64_t)insn.label)));
    /* execute.a64:585 [D] s_b_0_4: sym_14872_0_address = s_b_0_3, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14872_0_address, s_b_0_3);
    /* execute.a64:587 [F] s_b_0_5=sym_14866_3_parameter_inst.opc (const) */
    /* execute.a64:587 [F] s_b_0_6 = (u32)s_b_0_5 (const) */
    /* execute.a64:587 [F] s_b_0_7 = constant u32 0 (const) */
    /* execute.a64:587 [F] s_b_0_8 = s_b_0_6==s_b_0_7 (const) */
    uint8_t s_b_0_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:587 [F] s_b_0_9: If s_b_0_8: Jump b_1 else b_3 (const) */
    if (s_b_0_8) 
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
    /* execute.a64:588 [D] s_b_1_0 = sym_14872_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14872_0_address, emitter.context().types().u64());
    /* execute.a64:588 [D] s_b_1_1: sym_92597_3_parameter_address = s_b_1_0, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_92597_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2 = Load 4 s_b_1_0 => sym_92700_0_data32 */
    auto s_b_1_2 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_92700_0_data32, s_b_1_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_2, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_1_3 = sym_92700_0_data32 uint32_t */
    auto s_b_1_3 = emitter.load_local(DV_sym_92700_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_5=sym_14866_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_6 = (u32)s_b_1_4 */
    auto s_b_1_6 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_8: sym_93938_3_parameter_value = s_b_1_7, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_93938_3_parameter_value, s_b_1_7);
    /* execute.a64:2682 [F] s_b_1_9 = (u32)s_b_1_5 (const) */
    /* execute.a64:2682 [F] s_b_1_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_1_11 = s_b_1_9==s_b_1_10 (const) */
    uint8_t s_b_1_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_1_12: If s_b_1_11: Jump b_4 else b_6 (const) */
    if (s_b_1_11) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_4, b_5,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:590 [D] s_b_3_0 = sym_14872_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14872_0_address, emitter.context().types().u64());
    /* execute.a64:590 [D] s_b_3_1: sym_92788_3_parameter_address = s_b_3_0, dominates: s_b_5_1  */
    emitter.store_local(DV_sym_92788_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2 = Load 8 s_b_3_0 => sym_92916_0_data64 */
    auto s_b_3_2 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_92916_0_data64, s_b_3_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_3_3 = sym_92916_0_data64 uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_92916_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_3_4=sym_14866_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_3_5: sym_93960_3_parameter_value = s_b_3_3, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_93960_3_parameter_value, s_b_3_3);
    /* execute.a64:2682 [F] s_b_3_6 = (u32)s_b_3_4 (const) */
    /* execute.a64:2682 [F] s_b_3_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_3_8 = s_b_3_6==s_b_3_7 (const) */
    uint8_t s_b_3_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_3_9: If s_b_3_8: Jump b_5 else b_7 (const) */
    if (s_b_3_8) 
    {
      goto fixed_block_b_5;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_1, b_6,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1723 [F] s_b_4_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_4_1 = sym_92597_3_parameter_address uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_92597_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_4_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_4_1);
    /* execute.a64:0 [F] s_b_4_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3, b_7,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1723 [F] s_b_5_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_5_1 = sym_92788_3_parameter_address uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_92788_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_5_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_5_1);
    /* execute.a64:0 [F] s_b_5_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2684 [F] s_b_6_0=sym_14866_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_6_1 = sym_93938_3_parameter_value uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_93938_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_6_2: WriteRegBank 0:s_b_6_0 = s_b_6_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_6_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_6_1);
    /* execute.a64:0 [F] s_b_6_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2684 [F] s_b_7_0=sym_14866_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_7_1 = sym_93960_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_93960_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_7_2: WriteRegBank 0:s_b_7_0 = s_b_7_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_7_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_7_1);
    /* execute.a64:0 [F] s_b_7_3: Jump b_5 (const) */
    goto fixed_block_b_5;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldrh_reg(const aarch64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_106983_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_107049_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_106881_1__R_s_b_37_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_106339_1__R_s_b_2_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_106961_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_15797_0_rm;
  auto DV_sym_15797_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_15898_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1130 [F] s_b_0_0=sym_15770_3_parameter_inst.option0 (const) */
    /* execute.a64:1130 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1130 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1130 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1130 [F] s_b_0_4=sym_15770_3_parameter_inst.option21 (const) */
    /* execute.a64:1130 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:1130 [F] s_b_0_6 = constant u32 1 (const) */
    /* execute.a64:1130 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:1130 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1131 [F] s_b_1_0=sym_15770_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2646 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_5 = ReadRegBank 1:s_b_1_0 (u32) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_1_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 */
    dbt::el::Value *s_b_1_6;
    s_b_1_6 = (s_b_1_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_5);
    /* execute.a64:2659 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2616 [D] s_b_1_8 = (u32)s_b_1_7 */
    auto s_b_1_8 = emitter.truncate(s_b_1_7, emitter.context().types().u32());
    /* execute.a64:2616 [D] s_b_1_9 = (u64)s_b_1_8 */
    auto s_b_1_9 = emitter.zx(s_b_1_8, emitter.context().types().u64());
    /* execute.a64:2616 [F] s_b_1_10=sym_15770_3_parameter_inst.S (const) */
    /* execute.a64:2616 [F] s_b_1_11 = (u64)s_b_1_10 (const) */
    /* execute.a64:2616 [D] s_b_1_12 = s_b_1_9<<s_b_1_11 */
    auto s_b_1_12 = emitter.shl(s_b_1_9, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1131 [D] s_b_1_13: sym_15797_0_rm = s_b_1_12, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_15797_0_rm, s_b_1_12);
    /* execute.a64:1131 [F] s_b_1_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_8, b_9,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2730 [F] s_b_2_0=sym_15770_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2730 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_2_4: If s_b_2_3: Jump b_17 else b_15 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1132 [F] s_b_3_0=sym_15770_3_parameter_inst.option0 (const) */
    /* execute.a64:1132 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1132 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1132 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1132 [F] s_b_3_4=sym_15770_3_parameter_inst.option21 (const) */
    /* execute.a64:1132 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:1132 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.a64:1132 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:1132 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1133 [F] s_b_4_0=sym_15770_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2646 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_4_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_4_5 = ReadRegBank 1:s_b_4_0 (u32) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_4_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2659 [D] s_b_4_7 = (u64)s_b_4_6 */
    auto s_b_4_7 = emitter.zx(s_b_4_6, emitter.context().types().u64());
    /* execute.a64:2632 [D] s_b_4_8 = (s32)s_b_4_7 */
    auto s_b_4_8 = emitter.truncate(s_b_4_7, emitter.context().types().s32());
    /* execute.a64:2632 [D] s_b_4_9 = (s64)s_b_4_8 */
    auto s_b_4_9 = emitter.sx(s_b_4_8, emitter.context().types().s64());
    /* execute.a64:2632 [D] s_b_4_10 = (u64)s_b_4_9 */
    auto s_b_4_10 = emitter.reinterpret(s_b_4_9, emitter.context().types().u64());
    /* execute.a64:2632 [F] s_b_4_11=sym_15770_3_parameter_inst.S (const) */
    /* execute.a64:2632 [F] s_b_4_12 = (u64)s_b_4_11 (const) */
    /* execute.a64:2632 [D] s_b_4_13 = s_b_4_10<<s_b_4_12 */
    auto s_b_4_13 = emitter.shl(s_b_4_10, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1133 [D] s_b_4_14: sym_15797_0_rm = s_b_4_13, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_15797_0_rm, s_b_4_13);
    /* execute.a64:1133 [F] s_b_4_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1134 [F] s_b_5_0=sym_15770_3_parameter_inst.option0 (const) */
    /* execute.a64:1134 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1134 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1134 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1134 [F] s_b_5_4=sym_15770_3_parameter_inst.option21 (const) */
    /* execute.a64:1134 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1134 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:1134 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1134 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1135 [F] s_b_6_0=sym_15770_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2651 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_6_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_6_5 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_6_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_6_6: Select s_b_6_3 ? s_b_6_4 : s_b_6_5 */
    dbt::el::Value *s_b_6_6;
    s_b_6_6 = (s_b_6_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_6_5);
    /* execute.a64:2620 [F] s_b_6_7=sym_15770_3_parameter_inst.S (const) */
    /* execute.a64:2620 [F] s_b_6_8 = (u64)s_b_6_7 (const) */
    /* execute.a64:2620 [D] s_b_6_9 = s_b_6_6<<s_b_6_8 */
    auto s_b_6_9 = emitter.shl(s_b_6_6, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1135 [D] s_b_6_10: sym_15797_0_rm = s_b_6_9, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_15797_0_rm, s_b_6_9);
    /* execute.a64:1135 [F] s_b_6_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1136 [F] s_b_7_0=sym_15770_3_parameter_inst.option0 (const) */
    /* execute.a64:1136 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1136 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1136 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1136 [F] s_b_7_4=sym_15770_3_parameter_inst.option21 (const) */
    /* execute.a64:1136 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:1136 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.a64:1136 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:1136 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1137 [F] s_b_8_0=sym_15770_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2651 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_8_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_8_5 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_8_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2636 [F] s_b_8_7=sym_15770_3_parameter_inst.S (const) */
    /* execute.a64:2636 [F] s_b_8_8 = (u64)s_b_8_7 (const) */
    /* execute.a64:2636 [D] s_b_8_9 = s_b_8_6<<s_b_8_8 */
    auto s_b_8_9 = emitter.shl(s_b_8_6, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1137 [D] s_b_8_10: sym_15797_0_rm = s_b_8_9, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_15797_0_rm, s_b_8_9);
    /* execute.a64:1137 [F] s_b_8_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1139 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:1139 [F] s_b_9_1: sym_15797_0_rm = s_b_9_0 (const), dominates: s_b_16_1  */
    CV_sym_15797_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_15797_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1140 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1139 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_16,  */
  fixed_block_b_10: 
  {
    /* execute.a64:1149 [F] s_b_10_0=sym_15770_3_parameter_inst.L (const) */
    /* execute.a64:1149 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:1149 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:1149 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.L) == (uint32_t)0ULL));
    /* execute.a64:1149 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_12, b_13, b_14, b_22, b_23, b_24,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [F] s_b_11_0: Return */
    goto fixed_done;
  }
  /* b_16,  */
  fixed_block_b_12: 
  {
    /* execute.a64:1155 [D] s_b_12_0 = sym_15898_0_value uint16_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_15898_0_value, emitter.context().types().u16());
    /* execute.a64:1155 [D] s_b_12_1 = (u64)s_b_12_0 */
    auto s_b_12_1 = emitter.zx(s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_12_2=sym_15770_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_12_3 = (u32)s_b_12_1 */
    auto s_b_12_3 = emitter.truncate(s_b_12_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_12_4 = (u64)s_b_12_3 */
    auto s_b_12_4 = emitter.zx(s_b_12_3, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_12_5: sym_106961_3_parameter_value = s_b_12_4, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_106961_3_parameter_value, s_b_12_4);
    /* execute.a64:2682 [F] s_b_12_6 = (u32)s_b_12_2 (const) */
    /* execute.a64:2682 [F] s_b_12_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_12_8 = s_b_12_6==s_b_12_7 (const) */
    uint8_t s_b_12_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_12_9: If s_b_12_8: Jump b_11 else b_22 (const) */
    if (s_b_12_8) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1150 [D] s_b_13_0 = sym_15898_0_value uint16_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_15898_0_value, emitter.context().types().u16());
    /* execute.a64:1150 [D] s_b_13_1 = (s16)s_b_13_0 */
    auto s_b_13_1 = emitter.reinterpret(s_b_13_0, emitter.context().types().s16());
    /* execute.a64:1150 [D] s_b_13_2 = (s64)s_b_13_1 */
    auto s_b_13_2 = emitter.sx(s_b_13_1, emitter.context().types().s64());
    /* execute.a64:1150 [D] s_b_13_3 = (u64)s_b_13_2 */
    auto s_b_13_3 = emitter.reinterpret(s_b_13_2, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_13_4=sym_15770_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_13_5: sym_106983_3_parameter_value = s_b_13_3, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_106983_3_parameter_value, s_b_13_3);
    /* execute.a64:2682 [F] s_b_13_6 = (u32)s_b_13_4 (const) */
    /* execute.a64:2682 [F] s_b_13_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_13_8 = s_b_13_6==s_b_13_7 (const) */
    uint8_t s_b_13_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_13_9: If s_b_13_8: Jump b_11 else b_23 (const) */
    if (s_b_13_8) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1152 [D] s_b_14_0 = sym_15898_0_value uint16_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_15898_0_value, emitter.context().types().u16());
    /* execute.a64:1152 [D] s_b_14_1 = (s16)s_b_14_0 */
    auto s_b_14_1 = emitter.reinterpret(s_b_14_0, emitter.context().types().s16());
    /* execute.a64:1152 [D] s_b_14_2 = (s64)s_b_14_1 */
    auto s_b_14_2 = emitter.sx(s_b_14_1, emitter.context().types().s64());
    /* execute.a64:1152 [D] s_b_14_3 = (u64)s_b_14_2 */
    auto s_b_14_3 = emitter.reinterpret(s_b_14_2, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_14_4=sym_15770_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_14_5 = (u32)s_b_14_3 */
    auto s_b_14_5 = emitter.truncate(s_b_14_3, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_14_6 = (u64)s_b_14_5 */
    auto s_b_14_6 = emitter.zx(s_b_14_5, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_14_7: sym_107049_3_parameter_value = s_b_14_6, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_107049_3_parameter_value, s_b_14_6);
    /* execute.a64:2682 [F] s_b_14_8 = (u32)s_b_14_4 (const) */
    /* execute.a64:2682 [F] s_b_14_9 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_14_10 = s_b_14_8==s_b_14_9 (const) */
    uint8_t s_b_14_10 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_14_11: If s_b_14_10: Jump b_11 else b_24 (const) */
    if (s_b_14_10) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_2,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2733 [F] s_b_15_0=sym_15770_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_15_1 = ReadRegBank 0:s_b_15_0 (u64) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_15_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_15_2: sym_106339_1__R_s_b_2_5 = s_b_15_1, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_106339_1__R_s_b_2_5, s_b_15_1);
    /* execute.a64:2733 [F] s_b_15_3: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_15, b_21,  */
  fixed_block_b_16: 
  {
    /* execute.a64:1143 [D] s_b_16_0 = sym_106339_1__R_s_b_2_5 uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_106339_1__R_s_b_2_5, emitter.context().types().u64());
    /* execute.a64:1143 [D] s_b_16_1 = sym_15797_0_rm uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_15797_0_rm, emitter.context().types().u64());
    /* execute.a64:1143 [D] s_b_16_2 = s_b_16_0+s_b_16_1 */
    auto s_b_16_2 = emitter.add(s_b_16_0, s_b_16_1);
    /* ???:4294967295 [D] s_b_16_3 = Load 2 s_b_16_2 => sym_15898_0_value */
    auto s_b_16_3 = emitter.load_memory(s_b_16_2, emitter.context().types().u16());
    emitter.store_local(DV_sym_15898_0_value, s_b_16_3);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_2, s_b_16_3, emitter.const_u8(2));
    }
    /* execute.a64:1148 [F] s_b_16_4=sym_15770_3_parameter_inst.X (const) */
    /* execute.a64:1148 [F] s_b_16_5: If s_b_16_4: Jump b_10 else b_12 (const) */
    if (insn.X) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_2,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2701 [F] s_b_17_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_17_1 = __builtin_get_feature */
    uint32_t s_b_17_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(s_b_17_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_17_4: If s_b_17_3: Jump b_18 else b_25 (const) */
    if (s_b_17_3) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2702 [D] s_b_18_0 = ReadReg 20 (u64) */
    auto s_b_18_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_18_1: sym_106881_1__R_s_b_37_0 = s_b_18_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_106881_1__R_s_b_37_0, s_b_18_0);
    /* execute.a64:2702 [F] s_b_18_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_25,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2705 [D] s_b_19_0 = ReadReg 20 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_19_1: sym_106881_1__R_s_b_37_0 = s_b_19_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_106881_1__R_s_b_37_0, s_b_19_0);
    /* execute.a64:2705 [F] s_b_19_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_25,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2707 [D] s_b_20_0 = ReadReg 21 (u64) */
    auto s_b_20_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_20_1: sym_106881_1__R_s_b_37_0 = s_b_20_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_106881_1__R_s_b_37_0, s_b_20_0);
    /* execute.a64:2707 [F] s_b_20_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_18, b_19, b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2731 [D] s_b_21_0 = sym_106881_1__R_s_b_37_0 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_106881_1__R_s_b_37_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_21_1: sym_106339_1__R_s_b_2_5 = s_b_21_0, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_106339_1__R_s_b_2_5, s_b_21_0);
    /* execute.a64:2731 [F] s_b_21_2: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_12,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2684 [F] s_b_22_0=sym_15770_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_22_1 = sym_106961_3_parameter_value uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_106961_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_22_2: WriteRegBank 0:s_b_22_0 = s_b_22_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_22_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_22_1);
    /* execute.a64:0 [F] s_b_22_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_13,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2684 [F] s_b_23_0=sym_15770_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_23_1 = sym_106983_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_106983_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_23_2: WriteRegBank 0:s_b_23_0 = s_b_23_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_23_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_23_1);
    /* execute.a64:0 [F] s_b_23_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_14,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2684 [F] s_b_24_0=sym_15770_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_24_1 = sym_107049_3_parameter_value uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_107049_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_24_2: WriteRegBank 0:s_b_24_0 = s_b_24_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_24_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_24_1);
    /* execute.a64:0 [F] s_b_24_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_17,  */
  fixed_block_b_25: 
  {
    /* execute.a64:3012 [F] s_b_25_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_25_1 = __builtin_get_feature */
    uint32_t s_b_25_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_25_2 = (u8)s_b_25_1 (const) */
    /* execute.a64:2704 [F] s_b_25_3 = (u32)s_b_25_2 (const) */
    /* execute.a64:2704 [F] s_b_25_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_25_5 = s_b_25_3==s_b_25_4 (const) */
    uint8_t s_b_25_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_25_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_25_6: If s_b_25_5: Jump b_19 else b_20 (const) */
    if (s_b_25_5) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldtrh(const aarch64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:3075 [D] s_b_0_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldxrb(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_117637_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_117536_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_118241_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_117574_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_117642_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_16494_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_3 else b_1 (const) */
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
    /* execute.a64:2733 [F] s_b_1_0=sym_16494_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_1_2: sym_117536_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_117536_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2733 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:633 [D] s_b_2_0 = sym_117536_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_117536_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:634 [D] s_b_2_1: sym_117637_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_117637_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 1 s_b_2_0 => sym_117642_0_data8 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_117642_0_data8, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(1));
    }
    /* execute.a64:1663 [D] s_b_2_3 = sym_117642_0_data8 uint8_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_117642_0_data8, emitter.context().types().u8());
    /* execute.a64:1663 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_2_5=sym_16494_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_2_8: sym_118241_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_118241_3_parameter_value, s_b_2_7);
    /* execute.a64:2682 [F] s_b_2_9 = (u32)s_b_2_5 (const) */
    /* execute.a64:2682 [F] s_b_2_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_2_11 = s_b_2_9==s_b_2_10 (const) */
    uint8_t s_b_2_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_2_12: If s_b_2_11: Jump b_8 else b_10 (const) */
    if (s_b_2_11) 
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
    /* execute.a64:2701 [F] s_b_3_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_3_1 = __builtin_get_feature */
    uint32_t s_b_3_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(s_b_3_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_9 (const) */
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
    /* execute.a64:2702 [D] s_b_4_0 = ReadReg 20 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_4_1: sym_117574_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_117574_1__R_s_b_4_0, s_b_4_0);
    /* execute.a64:2702 [F] s_b_4_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2705 [D] s_b_5_0 = ReadReg 20 (u64) */
    auto s_b_5_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_5_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_5_1: sym_117574_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_117574_1__R_s_b_4_0, s_b_5_0);
    /* execute.a64:2705 [F] s_b_5_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2707 [D] s_b_6_0 = ReadReg 21 (u64) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_6_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_6_1: sym_117574_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_117574_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2707 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2731 [D] s_b_7_0 = sym_117574_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_117574_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_7_1: sym_117536_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_117536_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2731 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1723 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_8_1 = sym_117637_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_117637_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_8_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Return */
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:3012 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_9_2 = (u8)s_b_9_1 (const) */
    /* execute.a64:2704 [F] s_b_9_3 = (u32)s_b_9_2 (const) */
    /* execute.a64:2704 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_9_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_9_6: If s_b_9_5: Jump b_5 else b_6 (const) */
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
    /* execute.a64:2684 [F] s_b_10_0=sym_16494_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_10_1 = sym_118241_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_118241_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1,emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_movk(const aarch64_decode_a64_MOVE_WIDE_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_122852_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122906_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122936_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122958_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:256 [F] s_b_0_0=sym_16838_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_2 (const) */
    if (insn.sf) 
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
    /* execute.a64:2657 [F] s_b_1_0=sym_16838_3_parameter_inst.rd (const) */
    /* execute.a64:2651 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2651 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_1_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_1_5 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 */
    dbt::el::Value *s_b_1_6;
    s_b_1_6 = (s_b_1_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_1_5);
    /* execute.a64:2657 [D] s_b_1_7: sym_122852_1__R_s_b_0_4 = s_b_1_6, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_122852_1__R_s_b_0_4, s_b_1_6);
    /* execute.a64:2657 [F] s_b_1_8: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2659 [F] s_b_2_0=sym_16838_3_parameter_inst.rd (const) */
    /* execute.a64:2646 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2646 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_2_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_2_5 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_2_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_2_6: Select s_b_2_3 ? s_b_2_4 : s_b_2_5 */
    dbt::el::Value *s_b_2_6;
    s_b_2_6 = (s_b_2_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_2_5);
    /* execute.a64:2659 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_2_8: sym_122852_1__R_s_b_0_4 = s_b_2_7, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_122852_1__R_s_b_0_4, s_b_2_7);
    /* execute.a64:2659 [F] s_b_2_9: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:256 [D] s_b_3_0 = sym_122852_1__R_s_b_0_4 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_122852_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:256 [F] s_b_3_1 = constant u64 ffff (const) */
    /* execute.a64:256 [F] s_b_3_2=sym_16838_3_parameter_inst.shift_amount (const) */
    /* execute.a64:256 [F] s_b_3_3 = (u64)s_b_3_2 (const) */
    /* execute.a64:256 [F] s_b_3_4 = s_b_3_1<<s_b_3_3 (const) */
    uint64_t s_b_3_4 = ((uint64_t)((uint64_t)65535ULL << ((uint64_t)insn.shift_amount)));
    /* execute.a64:256 [F] s_b_3_5 = ~s_b_3_4 (const) */
    uint64_t s_b_3_5 = ~s_b_3_4;
    /* execute.a64:256 [D] s_b_3_6 = s_b_3_0&s_b_3_5 */
    auto s_b_3_6 = emitter.bitwise_and(s_b_3_0, emitter.const_u64(s_b_3_5));
    /* execute.a64:257 [F] s_b_3_7=sym_16838_3_parameter_inst.imm16 (const) */
    /* execute.a64:257 [F] s_b_3_8 = (u64)s_b_3_7 (const) */
    /* execute.a64:257 [F] s_b_3_9=sym_16838_3_parameter_inst.shift_amount (const) */
    /* execute.a64:257 [F] s_b_3_10 = (u64)s_b_3_9 (const) */
    /* execute.a64:257 [F] s_b_3_11 = s_b_3_8<<s_b_3_10 (const) */
    uint64_t s_b_3_11 = ((uint64_t)(((uint64_t)insn.imm16) << ((uint64_t)insn.shift_amount)));
    /* ???:4294967295 [D] s_b_3_12 = s_b_3_6|s_b_3_11 */
    auto s_b_3_12 = emitter.bitwise_or(s_b_3_6, emitter.const_u64(s_b_3_11));
    /* execute.a64:259 [F] s_b_3_13=sym_16838_3_parameter_inst.sf (const) */
    /* execute.a64:259 [D] s_b_3_14: sym_122906_3_parameter_value = s_b_3_12, dominates: s_b_4_1 s_b_5_1  */
    emitter.store_local(DV_sym_122906_3_parameter_value, s_b_3_12);
    /* execute.a64:2690 [F] s_b_3_15: If s_b_3_13: Jump b_4 else b_5 (const) */
    if (insn.sf) 
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
    /* execute.a64:2691 [F] s_b_4_0=sym_16838_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_4_1 = sym_122906_3_parameter_value uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_122906_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_4_2: sym_122936_3_parameter_value = s_b_4_1, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_122936_3_parameter_value, s_b_4_1);
    /* execute.a64:2682 [F] s_b_4_3 = (u32)s_b_4_0 (const) */
    /* execute.a64:2682 [F] s_b_4_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_4_5 = s_b_4_3==s_b_4_4 (const) */
    uint8_t s_b_4_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_4_6: If s_b_4_5: Jump b_6 else b_7 (const) */
    if (s_b_4_5) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2693 [F] s_b_5_0=sym_16838_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_5_1 = sym_122906_3_parameter_value uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_122906_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_5_2 = (u32)s_b_5_1 */
    auto s_b_5_2 = emitter.truncate(s_b_5_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_5_3 = (u64)s_b_5_2 */
    auto s_b_5_3 = emitter.zx(s_b_5_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_5_4: sym_122958_3_parameter_value = s_b_5_3, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_122958_3_parameter_value, s_b_5_3);
    /* execute.a64:2682 [F] s_b_5_5 = (u32)s_b_5_0 (const) */
    /* execute.a64:2682 [F] s_b_5_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_5_8: If s_b_5_7: Jump b_6 else b_8 (const) */
    if (s_b_5_7) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_4, b_5, b_7, b_8,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [F] s_b_6_0: Return */
    goto fixed_done;
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2684 [F] s_b_7_0=sym_16838_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_7_1 = sym_122936_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_122936_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_7_2: WriteRegBank 0:s_b_7_0 = s_b_7_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_7_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_7_1);
    /* execute.a64:0 [F] s_b_7_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2684 [F] s_b_8_0=sym_16838_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_8_1 = sym_122958_3_parameter_value uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_122958_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_8_2: WriteRegBank 0:s_b_8_0 = s_b_8_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_8_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_8_1);
    /* execute.a64:0 [F] s_b_8_3: Jump b_6 (const) */
    goto fixed_block_b_6;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_mul_idx_vector(const aarch64_decode_a64_SIMD_VECTOR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1299 [F] s_b_0_0=sym_18857_3_parameter_inst.arrangement (const) */
    /* execute.simd:1300 [F] s_b_0_1 = constant s32 2 (const) */
    /* execute.simd:1309 [F] s_b_0_2 = constant s32 3 (const) */
    /* execute.simd:1317 [F] s_b_0_3 = constant s32 4 (const) */
    /* execute.simd:1326 [F] s_b_0_4 = constant s32 5 (const) */
    /* execute.simd:1299 [F] s_b_0_5: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4, b_5,  */
    switch (insn.arrangement) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_5;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_0, b_2, b_3, b_4, b_5,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:1301 [F] s_b_2_0=sym_18857_3_parameter_inst.rn (const) */
    /* execute.simd:1301 [D] s_b_2_1 = ReadRegBank 17:s_b_2_0 (v4u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1302 [F] s_b_2_2=sym_18857_3_parameter_inst.rmr (const) */
    /* execute.simd:1302 [D] s_b_2_3 = ReadRegBank 18:s_b_2_2 (v8u16) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))),s_b_2_3,emitter.const_u8(16));
    }
    /* execute.simd:1303 [F] s_b_2_4=sym_18857_3_parameter_inst.eindex (const) */
    /* execute.simd:1303 [D] s_b_2_3[s_b_2_4] */
    auto s_b_2_5 = emitter.vector_extract(s_b_2_3, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_2_6 = (v4u16)s_b_2_5 */
    auto s_b_2_6 = emitter.splat(s_b_2_5, emitter.context().types().v4u16());
    /* execute.simd:1303 [D] s_b_2_7 = s_b_2_1*s_b_2_6 */
    auto s_b_2_7 = emitter.mul(s_b_2_1, s_b_2_6);
    /* execute.simd:1305 [F] s_b_2_8=sym_18857_3_parameter_inst.rd (const) */
    /* execute.simd:1305 [D] s_b_2_9: WriteRegBank 17:s_b_2_8 = s_b_2_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_7);
    /* execute.simd:1306 [F] s_b_2_10=sym_18857_3_parameter_inst.rd (const) */
    /* execute.simd:1306 [F] s_b_2_11 = constant u64 0 (const) */
    /* execute.simd:1306 [F] s_b_2_12: WriteRegBank 3:s_b_2_10 = s_b_2_11 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_13: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1310 [F] s_b_3_0=sym_18857_3_parameter_inst.rn (const) */
    /* execute.simd:1310 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:1311 [F] s_b_3_2=sym_18857_3_parameter_inst.rmr (const) */
    /* execute.simd:1311 [D] s_b_3_3 = ReadRegBank 18:s_b_3_2 (v8u16) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:1312 [F] s_b_3_4=sym_18857_3_parameter_inst.eindex (const) */
    /* execute.simd:1312 [D] s_b_3_3[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_3, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_3_6 = (v8u16)s_b_3_5 */
    auto s_b_3_6 = emitter.splat(s_b_3_5, emitter.context().types().v8u16());
    /* execute.simd:1312 [D] s_b_3_7 = s_b_3_1*s_b_3_6 */
    auto s_b_3_7 = emitter.mul(s_b_3_1, s_b_3_6);
    /* execute.simd:1314 [F] s_b_3_8=sym_18857_3_parameter_inst.rd (const) */
    /* execute.simd:1314 [D] s_b_3_9: WriteRegBank 18:s_b_3_8 = s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7);
    /* execute.simd:0 [F] s_b_3_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1318 [F] s_b_4_0=sym_18857_3_parameter_inst.rn (const) */
    /* execute.simd:1318 [D] s_b_4_1 = ReadRegBank 19:s_b_4_0 (v2u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:1319 [F] s_b_4_2=sym_18857_3_parameter_inst.rmr (const) */
    /* execute.simd:1319 [D] s_b_4_3 = ReadRegBank 20:s_b_4_2 (v4u32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))),s_b_4_3,emitter.const_u8(16));
    }
    /* execute.simd:1320 [F] s_b_4_4=sym_18857_3_parameter_inst.eindex (const) */
    /* execute.simd:1320 [D] s_b_4_3[s_b_4_4] */
    auto s_b_4_5 = emitter.vector_extract(s_b_4_3, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_4_6 = (v2u32)s_b_4_5 */
    auto s_b_4_6 = emitter.splat(s_b_4_5, emitter.context().types().v2u32());
    /* execute.simd:1320 [D] s_b_4_7 = s_b_4_1*s_b_4_6 */
    auto s_b_4_7 = emitter.mul(s_b_4_1, s_b_4_6);
    /* execute.simd:1322 [F] s_b_4_8=sym_18857_3_parameter_inst.rd (const) */
    /* execute.simd:1322 [D] s_b_4_9: WriteRegBank 19:s_b_4_8 = s_b_4_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_7);
    /* execute.simd:1323 [F] s_b_4_10=sym_18857_3_parameter_inst.rd (const) */
    /* execute.simd:1323 [F] s_b_4_11 = constant u64 0 (const) */
    /* execute.simd:1323 [F] s_b_4_12: WriteRegBank 3:s_b_4_10 = s_b_4_11 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_13: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:1327 [F] s_b_5_0=sym_18857_3_parameter_inst.rn (const) */
    /* execute.simd:1327 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1328 [F] s_b_5_2=sym_18857_3_parameter_inst.rmr (const) */
    /* execute.simd:1328 [D] s_b_5_3 = ReadRegBank 20:s_b_5_2 (v4u32) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1329 [F] s_b_5_4=sym_18857_3_parameter_inst.eindex (const) */
    /* execute.simd:1329 [D] s_b_5_3[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_3, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_5_6 = (v4u32)s_b_5_5 */
    auto s_b_5_6 = emitter.splat(s_b_5_5, emitter.context().types().v4u32());
    /* execute.simd:1329 [D] s_b_5_7 = s_b_5_1*s_b_5_6 */
    auto s_b_5_7 = emitter.mul(s_b_5_1, s_b_5_6);
    /* execute.simd:1331 [F] s_b_5_8=sym_18857_3_parameter_inst.rd (const) */
    /* execute.simd:1331 [D] s_b_5_9: WriteRegBank 20:s_b_5_8 = s_b_5_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_7);
    /* execute.simd:0 [F] s_b_5_10: Jump b_1 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_orrsr(const aarch64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_124559_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124375_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_124529_1__R_s_b_6_10;
  auto DV_sym_124529_1__R_s_b_6_10 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124391_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19384_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19391_0_op2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124699_1__R_s_b_22_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_124658_1__R_s_b_21_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124633_1__R_s_b_20_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124581_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124608_1__R_s_b_17_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2474 [F] s_b_0_0=sym_19379_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_3 else b_4 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_18,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2477 [D] s_b_1_0 = sym_19391_0_op2 uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_19391_0_op2, emitter.context().types().u64());
    /* execute.a64:2477 [D] s_b_1_1 = ~s_b_1_0 */
    auto s_b_1_1 = emitter.bitwise_not(s_b_1_0);
    /* execute.a64:2477 [D] s_b_1_2: sym_19391_0_op2 = s_b_1_1, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_19391_0_op2, s_b_1_1);
    /* execute.a64:2477 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_18,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2479 [D] s_b_2_0 = sym_19384_0_op1 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_19384_0_op1, emitter.context().types().u64());
    /* execute.a64:2479 [D] s_b_2_1 = sym_19391_0_op2 uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_19391_0_op2, emitter.context().types().u64());
    /* execute.a64:2479 [D] s_b_2_2 = s_b_2_0|s_b_2_1 */
    auto s_b_2_2 = emitter.bitwise_or(s_b_2_0, s_b_2_1);
    /* execute.a64:2481 [F] s_b_2_3=sym_19379_3_parameter_inst.sf (const) */
    /* execute.a64:2481 [D] s_b_2_4: sym_124391_3_parameter_value = s_b_2_2, dominates: s_b_6_1 s_b_7_1  */
    emitter.store_local(DV_sym_124391_3_parameter_value, s_b_2_2);
    /* execute.a64:2690 [F] s_b_2_5: If s_b_2_3: Jump b_6 else b_7 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2657 [F] s_b_3_0=sym_19379_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:2651 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_3_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_3_5 = ReadRegBank 0:s_b_3_0 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_3_6: Select s_b_3_3 ? s_b_3_4 : s_b_3_5 */
    dbt::el::Value *s_b_3_6;
    s_b_3_6 = (s_b_3_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_3_5);
    /* execute.a64:2657 [D] s_b_3_7: sym_124375_1__R_s_b_0_4 = s_b_3_6, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_124375_1__R_s_b_0_4, s_b_3_6);
    /* execute.a64:2657 [F] s_b_3_8: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2659 [F] s_b_4_0=sym_19379_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2646 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_4_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_4_5 = ReadRegBank 1:s_b_4_0 (u32) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2659 [D] s_b_4_7 = (u64)s_b_4_6 */
    auto s_b_4_7 = emitter.zx(s_b_4_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_4_8: sym_124375_1__R_s_b_0_4 = s_b_4_7, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_124375_1__R_s_b_0_4, s_b_4_7);
    /* execute.a64:2659 [F] s_b_4_9: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_3, b_4,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2474 [D] s_b_5_0 = sym_124375_1__R_s_b_0_4 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_124375_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2474 [D] s_b_5_1: sym_19384_0_op1 = s_b_5_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_19384_0_op1, s_b_5_0);
    /* execute.a64:2475 [F] s_b_5_2=sym_19379_3_parameter_inst.imm6 (const) */
    /* execute.a64:2572 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:2572 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2572 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.imm6) == (uint32_t)0ULL));
    /* execute.a64:2572 [F] s_b_5_6: If s_b_5_5: Jump b_9 else b_10 (const) */
    if (s_b_5_5) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_2,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2691 [F] s_b_6_0=sym_19379_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_6_1 = sym_124391_3_parameter_value uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_124391_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_6_2: sym_124559_3_parameter_value = s_b_6_1, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_124559_3_parameter_value, s_b_6_1);
    /* execute.a64:2682 [F] s_b_6_3 = (u32)s_b_6_0 (const) */
    /* execute.a64:2682 [F] s_b_6_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_6_6: If s_b_6_5: Jump b_8 else b_19 (const) */
    if (s_b_6_5) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_2,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2693 [F] s_b_7_0=sym_19379_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_7_1 = sym_124391_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_124391_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_7_2 = (u32)s_b_7_1 */
    auto s_b_7_2 = emitter.truncate(s_b_7_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_7_3 = (u64)s_b_7_2 */
    auto s_b_7_3 = emitter.zx(s_b_7_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_7_4: sym_124581_3_parameter_value = s_b_7_3, dominates: s_b_20_1  */
    emitter.store_local(DV_sym_124581_3_parameter_value, s_b_7_3);
    /* execute.a64:2682 [F] s_b_7_5 = (u32)s_b_7_0 (const) */
    /* execute.a64:2682 [F] s_b_7_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_7_8: If s_b_7_7: Jump b_8 else b_20 (const) */
    if (s_b_7_7) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_6, b_7, b_19, b_20,  */
  fixed_block_b_8: 
  {
    /* ???:4294967295 [F] s_b_8_0: Return */
    goto fixed_done;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2572 [F] s_b_9_0=sym_19379_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_9_1: If s_b_9_0: Jump b_21 else b_22 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_5,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2574 [F] s_b_10_0=sym_19379_3_parameter_inst.shift (const) */
    /* execute.a64:2575 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.a64:2579 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.a64:2583 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.a64:2587 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.a64:2574 [F] s_b_10_5: Switch s_b_10_0: < <todo> > def b_11 (const) -> b_14, b_15, b_12, b_13, b_11,  */
    switch (insn.shift) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_15;
      break;
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2597 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2598 [F] s_b_11_1 = constant u64 0 (const) */
    /* execute.a64:2598 [F] s_b_11_2: sym_124529_1__R_s_b_6_10 = s_b_11_1 (const), dominates: s_b_18_0  */
    CV_sym_124529_1__R_s_b_6_10 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_124529_1__R_s_b_6_10, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2598 [F] s_b_11_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_10,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2577 [F] s_b_12_0=sym_19379_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_12_1: If s_b_12_0: Jump b_24 else b_25 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2581 [F] s_b_13_0=sym_19379_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_13_1: If s_b_13_0: Jump b_27 else b_28 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_28;
    }
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2585 [F] s_b_14_0=sym_19379_3_parameter_inst.sf (const) */
    /* execute.a64:2665 [F] s_b_14_1: If s_b_14_0: Jump b_30 else b_31 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_10,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2589 [F] s_b_15_0=sym_19379_3_parameter_inst.sf (const) */
    /* execute.a64:2589 [F] s_b_15_1: If s_b_15_0: Jump b_16 else b_17 (const) */
    if (insn.sf) 
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
    /* execute.a64:2657 [F] s_b_16_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2651 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_16_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_16_5 = ReadRegBank 0:s_b_16_0 (u64) */
    auto s_b_16_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_16_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_16_6: Select s_b_16_3 ? s_b_16_4 : s_b_16_5 */
    dbt::el::Value *s_b_16_6;
    s_b_16_6 = (s_b_16_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_16_5);
    /* execute.a64:2590 [F] s_b_16_7=sym_19379_3_parameter_inst.imm6 (const) */
    /* execute.a64:2590 [F] s_b_16_8 = (u64)s_b_16_7 (const) */
    /* execute.a64:2590 [D] s_b_16_9 = s_b_16_6>>>s_b_16_8 */
    auto s_b_16_9 = emitter.ror(s_b_16_6, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2590 [D] s_b_16_10: sym_124529_1__R_s_b_6_10 = s_b_16_9, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_124529_1__R_s_b_6_10, s_b_16_9);
    /* execute.a64:2590 [F] s_b_16_11: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_15,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2659 [F] s_b_17_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
    /* execute.a64:2646 [F] s_b_17_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_17_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_17_5 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_17_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_17_6: Select s_b_17_3 ? s_b_17_4 : s_b_17_5 */
    dbt::el::Value *s_b_17_6;
    s_b_17_6 = (s_b_17_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_17_5);
    /* execute.a64:2659 [D] s_b_17_7 = (u64)s_b_17_6 */
    auto s_b_17_7 = emitter.zx(s_b_17_6, emitter.context().types().u64());
    /* execute.a64:2592 [D] s_b_17_8 = (u32)s_b_17_7 */
    auto s_b_17_8 = emitter.truncate(s_b_17_7, emitter.context().types().u32());
    /* execute.a64:2592 [F] s_b_17_9=sym_19379_3_parameter_inst.imm6 (const) */
    /* execute.a64:2592 [F] s_b_17_10 = (u32)s_b_17_9 (const) */
    /* execute.a64:2592 [D] s_b_17_11 = s_b_17_8>>>s_b_17_10 */
    auto s_b_17_11 = emitter.ror(s_b_17_8, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2592 [D] s_b_17_12 = (u64)s_b_17_11 */
    auto s_b_17_12 = emitter.zx(s_b_17_11, emitter.context().types().u64());
    /* execute.a64:2592 [D] s_b_17_13: sym_124529_1__R_s_b_6_10 = s_b_17_12, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_124529_1__R_s_b_6_10, s_b_17_12);
    /* execute.a64:2592 [F] s_b_17_14: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_11, b_16, b_17, b_23, b_26, b_29, b_32,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2475 [D] s_b_18_0 = sym_124529_1__R_s_b_6_10 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_124529_1__R_s_b_6_10, emitter.context().types().u64());
    /* execute.a64:2475 [D] s_b_18_1: sym_19391_0_op2 = s_b_18_0, dominates: s_b_1_0 s_b_2_1  */
    emitter.store_local(DV_sym_19391_0_op2, s_b_18_0);
    /* execute.a64:2477 [F] s_b_18_2=sym_19379_3_parameter_inst.N (const) */
    /* execute.a64:2477 [F] s_b_18_3: If s_b_18_2: Jump b_1 else b_2 (const) */
    if (insn.N) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_6,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2684 [F] s_b_19_0=sym_19379_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_19_1 = sym_124559_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_124559_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_19_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_19_1);
    /* execute.a64:0 [F] s_b_19_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2684 [F] s_b_20_0=sym_19379_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_20_1 = sym_124581_3_parameter_value uint64_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_124581_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_20_2: WriteRegBank 0:s_b_20_0 = s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_1);
    /* execute.a64:0 [F] s_b_20_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_9,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2657 [F] s_b_21_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:2651 [F] s_b_21_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_21_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_21_5 = ReadRegBank 0:s_b_21_0 (u64) */
    auto s_b_21_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_21_6: Select s_b_21_3 ? s_b_21_4 : s_b_21_5 */
    dbt::el::Value *s_b_21_6;
    s_b_21_6 = (s_b_21_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_21_5);
    /* execute.a64:2657 [D] s_b_21_7: sym_124608_1__R_s_b_17_4 = s_b_21_6, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_124608_1__R_s_b_17_4, s_b_21_6);
    /* execute.a64:2657 [F] s_b_21_8: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_9,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2659 [F] s_b_22_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
    /* execute.a64:2646 [F] s_b_22_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_22_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_22_5 = ReadRegBank 1:s_b_22_0 (u32) */
    auto s_b_22_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_22_6: Select s_b_22_3 ? s_b_22_4 : s_b_22_5 */
    dbt::el::Value *s_b_22_6;
    s_b_22_6 = (s_b_22_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_22_5);
    /* execute.a64:2659 [D] s_b_22_7 = (u64)s_b_22_6 */
    auto s_b_22_7 = emitter.zx(s_b_22_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_22_8: sym_124608_1__R_s_b_17_4 = s_b_22_7, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_124608_1__R_s_b_17_4, s_b_22_7);
    /* execute.a64:2659 [F] s_b_22_9: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2572 [D] s_b_23_0 = sym_124608_1__R_s_b_17_4 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_124608_1__R_s_b_17_4, emitter.context().types().u64());
    /* execute.a64:2572 [D] s_b_23_1: sym_124529_1__R_s_b_6_10 = s_b_23_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_124529_1__R_s_b_6_10, s_b_23_0);
    /* execute.a64:2572 [F] s_b_23_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_12,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2657 [F] s_b_24_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:2651 [F] s_b_24_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_24_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_24_5 = ReadRegBank 0:s_b_24_0 (u64) */
    auto s_b_24_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_24_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_24_6: Select s_b_24_3 ? s_b_24_4 : s_b_24_5 */
    dbt::el::Value *s_b_24_6;
    s_b_24_6 = (s_b_24_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_24_5);
    /* execute.a64:2657 [D] s_b_24_7: sym_124633_1__R_s_b_20_4 = s_b_24_6, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_124633_1__R_s_b_20_4, s_b_24_6);
    /* execute.a64:2657 [F] s_b_24_8: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_12,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2659 [F] s_b_25_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:2646 [F] s_b_25_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_25_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_25_5 = ReadRegBank 1:s_b_25_0 (u32) */
    auto s_b_25_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_25_6: Select s_b_25_3 ? s_b_25_4 : s_b_25_5 */
    dbt::el::Value *s_b_25_6;
    s_b_25_6 = (s_b_25_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_25_5);
    /* execute.a64:2659 [D] s_b_25_7 = (u64)s_b_25_6 */
    auto s_b_25_7 = emitter.zx(s_b_25_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_25_8: sym_124633_1__R_s_b_20_4 = s_b_25_7, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_124633_1__R_s_b_20_4, s_b_25_7);
    /* execute.a64:2659 [F] s_b_25_9: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_24, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2577 [D] s_b_26_0 = sym_124633_1__R_s_b_20_4 uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_124633_1__R_s_b_20_4, emitter.context().types().u64());
    /* execute.a64:2577 [F] s_b_26_1=sym_19379_3_parameter_inst.imm6 (const) */
    /* execute.a64:2577 [F] s_b_26_2 = (u64)s_b_26_1 (const) */
    /* execute.a64:2577 [D] s_b_26_3 = s_b_26_0<<s_b_26_2 */
    auto s_b_26_3 = emitter.shl(s_b_26_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2577 [D] s_b_26_4: sym_124529_1__R_s_b_6_10 = s_b_26_3, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_124529_1__R_s_b_6_10, s_b_26_3);
    /* execute.a64:2577 [F] s_b_26_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2657 [F] s_b_27_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
    /* execute.a64:2651 [F] s_b_27_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_27_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_27_5 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_27_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_27_6: Select s_b_27_3 ? s_b_27_4 : s_b_27_5 */
    dbt::el::Value *s_b_27_6;
    s_b_27_6 = (s_b_27_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_27_5);
    /* execute.a64:2657 [D] s_b_27_7: sym_124658_1__R_s_b_21_4 = s_b_27_6, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_124658_1__R_s_b_21_4, s_b_27_6);
    /* execute.a64:2657 [F] s_b_27_8: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_13,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2659 [F] s_b_28_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:2646 [F] s_b_28_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_28_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_28_5 = ReadRegBank 1:s_b_28_0 (u32) */
    auto s_b_28_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_28_6: Select s_b_28_3 ? s_b_28_4 : s_b_28_5 */
    dbt::el::Value *s_b_28_6;
    s_b_28_6 = (s_b_28_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_28_5);
    /* execute.a64:2659 [D] s_b_28_7 = (u64)s_b_28_6 */
    auto s_b_28_7 = emitter.zx(s_b_28_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_28_8: sym_124658_1__R_s_b_21_4 = s_b_28_7, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_124658_1__R_s_b_21_4, s_b_28_7);
    /* execute.a64:2659 [F] s_b_28_9: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2581 [D] s_b_29_0 = sym_124658_1__R_s_b_21_4 uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_124658_1__R_s_b_21_4, emitter.context().types().u64());
    /* execute.a64:2581 [F] s_b_29_1=sym_19379_3_parameter_inst.imm6 (const) */
    /* execute.a64:2581 [F] s_b_29_2 = (u64)s_b_29_1 (const) */
    /* execute.a64:2581 [D] s_b_29_3 = s_b_29_0>>s_b_29_2 */
    auto s_b_29_3 = emitter.shr(s_b_29_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2581 [D] s_b_29_4: sym_124529_1__R_s_b_6_10 = s_b_29_3, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_124529_1__R_s_b_6_10, s_b_29_3);
    /* execute.a64:2581 [F] s_b_29_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_14,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2666 [F] s_b_30_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [F] s_b_30_1 = (u32)s_b_30_0 (const) */
    /* execute.a64:2666 [F] s_b_30_2 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_30_3 = s_b_30_1==s_b_30_2 (const) */
    uint8_t s_b_30_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_30_4 = constant s64 0 (const) */
    /* execute.a64:2666 [F] s_b_30_5=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [D] s_b_30_6 = ReadRegBank 0:s_b_30_5 (u64) */
    auto s_b_30_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_30_6,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_30_7 = (s64)s_b_30_6 */
    auto s_b_30_7 = emitter.reinterpret(s_b_30_6, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_30_8: Select s_b_30_3 ? s_b_30_4 : s_b_30_7 */
    dbt::el::Value *s_b_30_8;
    s_b_30_8 = (s_b_30_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_30_7);
    /* execute.a64:2666 [D] s_b_30_9: sym_124699_1__R_s_b_22_4 = s_b_30_8, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_124699_1__R_s_b_22_4, s_b_30_8);
    /* execute.a64:2666 [F] s_b_30_10: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_14,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2668 [F] s_b_31_0=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
    /* execute.a64:2668 [F] s_b_31_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_31_3 = s_b_31_1==s_b_31_2 (const) */
    uint8_t s_b_31_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_31_4 = constant s64 0 (const) */
    /* execute.a64:2668 [F] s_b_31_5=sym_19379_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [D] s_b_31_6 = ReadRegBank 1:s_b_31_5 (u32) */
    auto s_b_31_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_31_6,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_31_7 = (s32)s_b_31_6 */
    auto s_b_31_7 = emitter.reinterpret(s_b_31_6, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_31_8 = (s64)s_b_31_7 */
    auto s_b_31_8 = emitter.sx(s_b_31_7, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_31_9: Select s_b_31_3 ? s_b_31_4 : s_b_31_8 */
    dbt::el::Value *s_b_31_9;
    s_b_31_9 = (s_b_31_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_31_8);
    /* execute.a64:2668 [D] s_b_31_10: sym_124699_1__R_s_b_22_4 = s_b_31_9, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_124699_1__R_s_b_22_4, s_b_31_9);
    /* execute.a64:2668 [F] s_b_31_11: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2585 [D] s_b_32_0 = sym_124699_1__R_s_b_22_4 int64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_124699_1__R_s_b_22_4, emitter.context().types().s64());
    /* execute.a64:2585 [F] s_b_32_1=sym_19379_3_parameter_inst.imm6 (const) */
    /* execute.a64:2585 [D] s_b_32_2 = (u64)s_b_32_0 */
    auto s_b_32_2 = emitter.reinterpret(s_b_32_0, emitter.context().types().u64());
    /* execute.a64:2585 [F] s_b_32_3 = (u64)s_b_32_1 (const) */
    /* execute.a64:2585 [D] s_b_32_4 = s_b_32_2->>s_b_32_3 */
    auto s_b_32_4 = emitter.sar(s_b_32_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2585 [D] s_b_32_5 = (u64)s_b_32_4 */
    auto s_b_32_5 = (dbt::el::Value *)s_b_32_4;
    /* execute.a64:2585 [D] s_b_32_6: sym_124529_1__R_s_b_6_10 = s_b_32_5, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_124529_1__R_s_b_6_10, s_b_32_5);
    /* execute.a64:2585 [F] s_b_32_7: Jump b_18 (const) */
    goto fixed_block_b_18;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ret(const aarch64_decode_a64_UB_REG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:562 [F] s_b_0_0=sym_19899_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2651 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_0_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_0_5 = ReadRegBank 0:s_b_0_0 (u64) */
    auto s_b_0_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_0_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_0_6: Select s_b_0_3 ? s_b_0_4 : s_b_0_5 */
    dbt::el::Value *s_b_0_6;
    s_b_0_6 = (s_b_0_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_0_5);
    /* execute.a64:563 [D] s_b_0_7 = write_pc */
    emitter.store_pc(s_b_0_6);
    /* ???:4294967295 [F] s_b_0_8: Return */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_saddlv(const aarch64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:3075 [D] s_b_0_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_shll(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3232 [D] s_b_0_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_smulh(const aarch64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_129379_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2377 [F] s_b_0_0=sym_24654_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2651 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_0_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_0_5 = ReadRegBank 0:s_b_0_0 (u64) */
    auto s_b_0_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_0_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_0_6: Select s_b_0_3 ? s_b_0_4 : s_b_0_5 */
    dbt::el::Value *s_b_0_6;
    s_b_0_6 = (s_b_0_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_0_5);
    /* execute.a64:2377 [D] s_b_0_7 = (s64)s_b_0_6 */
    auto s_b_0_7 = emitter.reinterpret(s_b_0_6, emitter.context().types().s64());
    /* execute.a64:2378 [F] s_b_0_8=sym_24654_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_0_9 = (u32)s_b_0_8 (const) */
    /* execute.a64:2651 [F] s_b_0_10 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_0_11 = s_b_0_9==s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_0_12 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_0_13 = ReadRegBank 0:s_b_0_8 (u64) */
    auto s_b_0_13 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_0_13,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_0_14: Select s_b_0_11 ? s_b_0_12 : s_b_0_13 */
    dbt::el::Value *s_b_0_14;
    s_b_0_14 = (s_b_0_11) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_0_13);
    /* execute.a64:2378 [D] s_b_0_15 = (s64)s_b_0_14 */
    auto s_b_0_15 = emitter.reinterpret(s_b_0_14, emitter.context().types().s64());
    /* execute.a64:2380 [D] s_b_0_16 = (u64)s_b_0_7 */
    auto s_b_0_16 = emitter.reinterpret(s_b_0_7, emitter.context().types().u64());
    /* execute.a64:2380 [D] s_b_0_17 = (u64)s_b_0_15 */
    auto s_b_0_17 = emitter.reinterpret(s_b_0_15, emitter.context().types().u64());
    /* execute.a64:2380 [D] s_b_0_18 = __builtin_smulh */
    auto s_b_0_18 = emitter.smulh(s_b_0_16, s_b_0_17);
    /* execute.a64:2380 [D] s_b_0_19 = (u64)s_b_0_18 */
    auto s_b_0_19 = (dbt::el::Value *)s_b_0_18;
    /* execute.a64:2691 [F] s_b_0_20=sym_24654_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_0_21: sym_129379_3_parameter_value = s_b_0_19, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_129379_3_parameter_value, s_b_0_19);
    /* execute.a64:2682 [F] s_b_0_22 = (u32)s_b_0_20 (const) */
    /* execute.a64:2682 [F] s_b_0_23 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_0_24 = s_b_0_22==s_b_0_23 (const) */
    uint8_t s_b_0_24 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_0_25: If s_b_0_24: Jump b_1 else b_2 (const) */
    if (s_b_0_24) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_0, b_2,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2684 [F] s_b_2_0=sym_24654_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_2_1 = sym_129379_3_parameter_value uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_129379_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_2_2: WriteRegBank 0:s_b_2_0 = s_b_2_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_2_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_2_1);
    /* execute.a64:0 [F] s_b_2_3: Jump b_1 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_st1pi(const aarch64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_130655_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_130638_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_130747_3_parameter_rt;
  auto DV_sym_130752_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_130871_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_130755_3_parameter_lane;
  auto DV_sym_130949_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_131008_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_130832_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_130829_1_tmp_s_b_5_4;
  auto DV_sym_130854_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30310_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30316_0_rt;
  uint8_t CV_sym_30328_0_lane;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2569 [F] s_b_0_0=sym_30304_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_9 else b_10 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_6, b_11,  */
  fixed_block_b_1: 
  {
    /* execute.simd:2571 [F] s_b_1_0 = sym_30316_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30316_0_rt;
    /* execute.simd:2571 [F] s_b_1_1=sym_30304_3_parameter_inst.regcnt (const) */
    /* execute.simd:2571 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2571 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2572 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2572 [F] s_b_2_1: sym_30328_0_lane = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30328_0_lane = (uint8_t)0ULL;
    /* execute.simd:2572 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2578 [F] s_b_3_0=sym_30304_3_parameter_inst.rm (const) */
    /* execute.simd:2578 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2578 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2578 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2578 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_25,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2572 [F] s_b_4_0 = sym_30328_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30328_0_lane;
    /* execute.simd:2572 [F] s_b_4_1=sym_30304_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2572 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2572 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2573 [F] s_b_5_0=sym_30304_3_parameter_inst.arrangement (const) */
    /* execute.simd:2573 [F] s_b_5_1=sym_30304_3_parameter_inst.rt (const) */
    /* execute.simd:2573 [F] s_b_5_2 = sym_30316_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30316_0_rt;
    /* execute.simd:2573 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2573 [F] s_b_5_4 = sym_30328_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30328_0_lane;
    /* execute.simd:2573 [D] s_b_5_5 = sym_30310_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30310_0_address, emitter.context().types().u64());
    /* execute.simd:2573 [F] s_b_5_6: sym_130747_3_parameter_rt = s_b_5_3 (const), dominates: s_b_20_0 s_b_21_0 s_b_22_0 s_b_23_0 s_b_19_0 s_b_24_0 s_b_18_0  */
    CV_sym_130747_3_parameter_rt = s_b_5_3;
    /* execute.simd:2573 [F] s_b_5_7: sym_130755_3_parameter_lane = s_b_5_4 (const), dominates: s_b_20_3 s_b_21_3 s_b_22_3 s_b_23_3 s_b_19_3 s_b_24_3 s_b_18_3  */
    CV_sym_130755_3_parameter_lane = s_b_5_4;
    /* execute.simd:2573 [D] s_b_5_8: sym_130752_3_parameter_addr = s_b_5_5, dominates: s_b_20_2 s_b_21_2 s_b_22_2 s_b_23_2 s_b_19_2 s_b_24_2 s_b_18_2  */
    emitter.store_local(DV_sym_130752_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_130829_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_25_1  */
    CV_sym_130829_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_130832_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_130832_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3841 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3846 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3851 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3856 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3861 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3866 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3871 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3840 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_17 (const) -> b_17, b_20, b_21, b_22, b_23, b_19, b_24, b_18,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_24;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_22;
      break;
    default:
      goto fixed_block_b_17;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2571 [F] s_b_6_0 = sym_30316_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30316_0_rt;
    /* execute.simd:2571 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2571 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2571 [F] s_b_6_3: sym_30316_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30316_0_rt = s_b_6_2;
    /* execute.simd:2571 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2579 [F] s_b_7_0=sym_30304_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2730 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_7_4: If s_b_7_3: Jump b_26 else b_27 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_3, b_28,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2582 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2582 [D] s_b_8_1 = sym_30310_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_30310_0_address, emitter.context().types().u64());
    /* execute.simd:2582 [D] s_b_8_2: sym_130949_3_parameter_value = s_b_8_1, dominates: s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_130949_3_parameter_value, s_b_8_1);
    /* execute.a64:2746 [F] s_b_8_3 = !s_b_8_0 (const) */
    uint8_t s_b_8_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_8_4: If s_b_8_3: Jump b_34 else b_35 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2701 [F] s_b_9_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_9_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(s_b_9_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_9_4: If s_b_9_3: Jump b_12 else b_13 (const) */
    if (s_b_9_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2733 [F] s_b_10_0=sym_30304_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_130638_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_130638_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_130638_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_130638_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2569 [D] s_b_11_1: sym_30310_0_address = s_b_11_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30310_0_address, s_b_11_0);
    /* execute.simd:2571 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.simd:2571 [F] s_b_11_3: sym_30316_0_rt = s_b_11_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30316_0_rt = (uint8_t)0ULL;
    /* execute.simd:2571 [F] s_b_11_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2702 [D] s_b_12_0 = ReadReg 20 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_12_1: sym_130655_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_130655_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2702 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_9,  */
  fixed_block_b_13: 
  {
    /* execute.a64:3012 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_13_2 = (u8)s_b_13_1 (const) */
    /* execute.a64:2704 [F] s_b_13_3 = (u32)s_b_13_2 (const) */
    /* execute.a64:2704 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
    uint8_t s_b_13_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_13_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_13_6: If s_b_13_5: Jump b_15 else b_16 (const) */
    if (s_b_13_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_12, b_15, b_16,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2731 [D] s_b_14_0 = sym_130655_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_130655_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_130638_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_130638_0_return_symbol, s_b_14_0);
    /* ???:4294967295 [F] s_b_14_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_13,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2705 [D] s_b_15_0 = ReadReg 20 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_15_1: sym_130655_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_130655_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2705 [F] s_b_15_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_13,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2707 [D] s_b_16_0 = ReadReg 21 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_16_1: sym_130655_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_130655_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2707 [F] s_b_16_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3877 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_17_1: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3842 [F] s_b_18_0 = sym_130747_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_130747_3_parameter_rt;
    /* execute.simd:3842 [D] s_b_18_1 = ReadRegBank 15:s_b_18_0 (v8u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3843 [D] s_b_18_2 = sym_130752_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_130752_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3843 [F] s_b_18_3 = sym_130755_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_130755_3_parameter_lane;
    /* execute.simd:3843 [D] s_b_18_1[s_b_18_3] */
    auto s_b_18_4 = emitter.vector_extract(s_b_18_1, emitter.const_u8(s_b_18_3));
    /* ???:4294967295 [D] s_b_18_5: Store 1 s_b_18_2 <= s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_18_2, s_b_18_4);
    /* execute.simd:0 [F] s_b_18_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3847 [F] s_b_19_0 = sym_130747_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_130747_3_parameter_rt;
    /* execute.simd:3847 [D] s_b_19_1 = ReadRegBank 16:s_b_19_0 (v16u8) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3848 [D] s_b_19_2 = sym_130752_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_130752_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3848 [F] s_b_19_3 = sym_130755_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_130755_3_parameter_lane;
    /* execute.simd:3848 [D] s_b_19_1[s_b_19_3] */
    auto s_b_19_4 = emitter.vector_extract(s_b_19_1, emitter.const_u8(s_b_19_3));
    /* ???:4294967295 [D] s_b_19_5: Store 1 s_b_19_2 <= s_b_19_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_19_2, s_b_19_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_19_2, s_b_19_4);
    /* execute.simd:0 [F] s_b_19_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3852 [F] s_b_20_0 = sym_130747_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_130747_3_parameter_rt;
    /* execute.simd:3852 [D] s_b_20_1 = ReadRegBank 17:s_b_20_0 (v4u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3853 [D] s_b_20_2 = sym_130752_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_130752_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3853 [F] s_b_20_3 = sym_130755_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_130755_3_parameter_lane;
    /* execute.simd:3853 [D] s_b_20_1[s_b_20_3] */
    auto s_b_20_4 = emitter.vector_extract(s_b_20_1, emitter.const_u8(s_b_20_3));
    /* ???:4294967295 [D] s_b_20_5: Store 2 s_b_20_2 <= s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_20_2, s_b_20_4);
    /* execute.simd:0 [F] s_b_20_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3857 [F] s_b_21_0 = sym_130747_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_130747_3_parameter_rt;
    /* execute.simd:3857 [D] s_b_21_1 = ReadRegBank 18:s_b_21_0 (v8u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3858 [D] s_b_21_2 = sym_130752_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_130752_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3858 [F] s_b_21_3 = sym_130755_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_130755_3_parameter_lane;
    /* execute.simd:3858 [D] s_b_21_1[s_b_21_3] */
    auto s_b_21_4 = emitter.vector_extract(s_b_21_1, emitter.const_u8(s_b_21_3));
    /* ???:4294967295 [D] s_b_21_5: Store 2 s_b_21_2 <= s_b_21_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_21_2, s_b_21_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_21_2, s_b_21_4);
    /* execute.simd:0 [F] s_b_21_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3862 [F] s_b_22_0 = sym_130747_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_130747_3_parameter_rt;
    /* execute.simd:3862 [D] s_b_22_1 = ReadRegBank 19:s_b_22_0 (v2u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:3863 [D] s_b_22_2 = sym_130752_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_130752_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3863 [F] s_b_22_3 = sym_130755_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_130755_3_parameter_lane;
    /* execute.simd:3863 [D] s_b_22_1[s_b_22_3] */
    auto s_b_22_4 = emitter.vector_extract(s_b_22_1, emitter.const_u8(s_b_22_3));
    /* ???:4294967295 [D] s_b_22_5: Store 4 s_b_22_2 <= s_b_22_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_22_2, s_b_22_4);
    /* execute.simd:0 [F] s_b_22_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_23: 
  {
    /* execute.simd:3867 [F] s_b_23_0 = sym_130747_3_parameter_rt (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_130747_3_parameter_rt;
    /* execute.simd:3867 [D] s_b_23_1 = ReadRegBank 20:s_b_23_0 (v4u32) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:3868 [D] s_b_23_2 = sym_130752_3_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_130752_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3868 [F] s_b_23_3 = sym_130755_3_parameter_lane (const) uint8_t */
    uint8_t s_b_23_3 = CV_sym_130755_3_parameter_lane;
    /* execute.simd:3868 [D] s_b_23_1[s_b_23_3] */
    auto s_b_23_4 = emitter.vector_extract(s_b_23_1, emitter.const_u8(s_b_23_3));
    /* ???:4294967295 [D] s_b_23_5: Store 4 s_b_23_2 <= s_b_23_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_23_2, s_b_23_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_23_2, s_b_23_4);
    /* execute.simd:0 [F] s_b_23_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_24: 
  {
    /* execute.simd:3872 [F] s_b_24_0 = sym_130747_3_parameter_rt (const) uint8_t */
    uint8_t s_b_24_0 = CV_sym_130747_3_parameter_rt;
    /* execute.simd:3872 [D] s_b_24_1 = ReadRegBank 21:s_b_24_0 (v2u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))),s_b_24_1,emitter.const_u8(16));
    }
    /* execute.simd:3873 [D] s_b_24_2 = sym_130752_3_parameter_addr uint64_t */
    auto s_b_24_2 = emitter.load_local(DV_sym_130752_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3873 [F] s_b_24_3 = sym_130755_3_parameter_lane (const) uint8_t */
    uint8_t s_b_24_3 = CV_sym_130755_3_parameter_lane;
    /* execute.simd:3873 [D] s_b_24_1[s_b_24_3] */
    auto s_b_24_4 = emitter.vector_extract(s_b_24_1, emitter.const_u8(s_b_24_3));
    /* ???:4294967295 [D] s_b_24_5: Store 8 s_b_24_2 <= s_b_24_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_24_2, s_b_24_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_24_2, s_b_24_4);
    /* execute.simd:0 [F] s_b_24_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_17, b_18, b_19, b_20, b_21, b_22, b_23, b_24,  */
  fixed_block_b_25: 
  {
    /* ???:4294967295 [D] s_b_25_0 = sym_130832_1_tmp_s_b_5_5 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_130832_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_25_1 = sym_130829_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_25_1 = CV_sym_130829_1_tmp_s_b_5_4;
    /* execute.simd:2574 [F] s_b_25_2=sym_30304_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_25_3 = (u64)s_b_25_2 (const) */
    /* ???:4294967295 [D] s_b_25_4 = s_b_25_0+s_b_25_3 */
    auto s_b_25_4 = emitter.add(s_b_25_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2574 [D] s_b_25_5: sym_30310_0_address = s_b_25_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30310_0_address, s_b_25_4);
    /* execute.simd:2572 [F] s_b_25_6 = constant u8 1 (const) */
    /* execute.simd:2572 [F] s_b_25_7 = s_b_25_1+s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(s_b_25_1 + (uint8_t)1ULL));
    /* execute.simd:2572 [F] s_b_25_8: sym_30328_0_lane = s_b_25_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30328_0_lane = s_b_25_7;
    /* execute.simd:2572 [F] s_b_25_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2701 [F] s_b_26_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_26_1 = __builtin_get_feature */
    uint32_t s_b_26_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_26_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(s_b_26_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_26_4: If s_b_26_3: Jump b_29 else b_30 (const) */
    if (s_b_26_3) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_7,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2733 [F] s_b_27_0=sym_30304_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_27_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_27_2: sym_130854_0_return_symbol = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_130854_0_return_symbol, s_b_27_1);
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_31,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_130854_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_130854_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2579 [F] s_b_28_1=sym_30304_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_28_2 = (u32)s_b_28_1 (const) */
    /* execute.a64:2651 [F] s_b_28_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_28_4 = s_b_28_2==s_b_28_3 (const) */
    uint8_t s_b_28_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_28_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_28_6 = ReadRegBank 0:s_b_28_1 (u64) */
    auto s_b_28_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_28_7: Select s_b_28_4 ? s_b_28_5 : s_b_28_6 */
    dbt::el::Value *s_b_28_7;
    s_b_28_7 = (s_b_28_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_28_6);
    /* execute.simd:2579 [D] s_b_28_8 = s_b_28_0+s_b_28_7 */
    auto s_b_28_8 = emitter.add(s_b_28_0, s_b_28_7);
    /* execute.simd:2579 [D] s_b_28_9: sym_30310_0_address = s_b_28_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_30310_0_address, s_b_28_8);
    /* execute.simd:2579 [F] s_b_28_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_26,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2702 [D] s_b_29_0 = ReadReg 20 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_29_1: sym_130871_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_130871_1__R_s_b_3_0, s_b_29_0);
    /* execute.a64:2702 [F] s_b_29_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_26,  */
  fixed_block_b_30: 
  {
    /* execute.a64:3012 [F] s_b_30_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_30_1 = __builtin_get_feature */
    uint32_t s_b_30_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_30_2 = (u8)s_b_30_1 (const) */
    /* execute.a64:2704 [F] s_b_30_3 = (u32)s_b_30_2 (const) */
    /* execute.a64:2704 [F] s_b_30_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_30_5 = s_b_30_3==s_b_30_4 (const) */
    uint8_t s_b_30_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_30_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_30_6: If s_b_30_5: Jump b_32 else b_33 (const) */
    if (s_b_30_5) 
    {
      goto fixed_block_b_32;
    }
    else 
    {
      goto fixed_block_b_33;
    }
  }
  /* b_29, b_32, b_33,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2731 [D] s_b_31_0 = sym_130871_1__R_s_b_3_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_130871_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1: sym_130854_0_return_symbol = s_b_31_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_130854_0_return_symbol, s_b_31_0);
    /* ???:4294967295 [F] s_b_31_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_30,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2705 [D] s_b_32_0 = ReadReg 20 (u64) */
    auto s_b_32_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_32_1: sym_130871_1__R_s_b_3_0 = s_b_32_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_130871_1__R_s_b_3_0, s_b_32_0);
    /* execute.a64:2705 [F] s_b_32_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_30,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2707 [D] s_b_33_0 = ReadReg 21 (u64) */
    auto s_b_33_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_33_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_33_1: sym_130871_1__R_s_b_3_0 = s_b_33_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_130871_1__R_s_b_3_0, s_b_33_0);
    /* execute.a64:2707 [F] s_b_33_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_8,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2747 [D] s_b_34_0 = sym_130949_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_130949_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_34_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_34_2 = s_b_34_0&s_b_34_1 */
    auto s_b_34_2 = emitter.bitwise_and(s_b_34_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_34_3: sym_130949_3_parameter_value = s_b_34_2, dominates: s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_130949_3_parameter_value, s_b_34_2);
    /* execute.a64:2747 [F] s_b_34_4: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_8, b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2750 [F] s_b_35_0=sym_30304_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
    /* execute.a64:2750 [F] s_b_35_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_35_3 = s_b_35_1==s_b_35_2 (const) */
    uint8_t s_b_35_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_35_4: If s_b_35_3: Jump b_36 else b_37 (const) */
    if (s_b_35_3) 
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
    /* execute.a64:2751 [D] s_b_36_0 = sym_130949_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_130949_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_36_1: sym_131008_3_parameter_value = s_b_36_0, dominates: s_b_39_0 s_b_40_0 s_b_41_0  */
    emitter.store_local(DV_sym_131008_3_parameter_value, s_b_36_0);
    /* execute.a64:2714 [F] s_b_36_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_36_3 = __builtin_get_feature */
    uint32_t s_b_36_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_36_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(s_b_36_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_36_6: If s_b_36_5: Jump b_39 else b_42 (const) */
    if (s_b_36_5) 
    {
      goto fixed_block_b_39;
    }
    else 
    {
      goto fixed_block_b_42;
    }
  }
  /* b_35,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2753 [F] s_b_37_0=sym_30304_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_37_1 = sym_130949_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_130949_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_37_2: WriteRegBank 0:s_b_37_0 = s_b_37_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_37_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_37_1);
    /* execute.a64:2753 [F] s_b_37_3: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_37, b_39, b_40, b_41,  */
  fixed_block_b_38: 
  {
    /* ???:4294967295 [F] s_b_38_0: Return */
    goto fixed_done;
  }
  /* b_36,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2715 [D] s_b_39_0 = sym_131008_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_131008_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_39_1: WriteReg 20 = s_b_39_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_39_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_39_0);
    /* execute.a64:2715 [F] s_b_39_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_42,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2718 [D] s_b_40_0 = sym_131008_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_131008_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_40_1: WriteReg 20 = s_b_40_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_40_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_40_0);
    /* execute.a64:2718 [F] s_b_40_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_42,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2720 [D] s_b_41_0 = sym_131008_3_parameter_value uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_131008_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_41_1: WriteReg 21 = s_b_41_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_41_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_41_0);
    /* execute.a64:2720 [F] s_b_41_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_36,  */
  fixed_block_b_42: 
  {
    /* execute.a64:3012 [F] s_b_42_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_42_1 = __builtin_get_feature */
    uint32_t s_b_42_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_42_2 = (u8)s_b_42_1 (const) */
    /* execute.a64:2717 [F] s_b_42_3 = (u32)s_b_42_2 (const) */
    /* execute.a64:2717 [F] s_b_42_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_42_5 = s_b_42_3==s_b_42_4 (const) */
    uint8_t s_b_42_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_42_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_42_6: If s_b_42_5: Jump b_40 else b_41 (const) */
    if (s_b_42_5) 
    {
      goto fixed_block_b_40;
    }
    else 
    {
      goto fixed_block_b_41;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_st4pi(const aarch64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_133186_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_133189_3_parameter_lane;
  uint8_t CV_sym_133181_3_parameter_rt;
  auto DV_sym_133305_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_133442_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_133072_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_133263_1_tmp_s_b_5_2;
  auto DV_sym_133266_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30910_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30916_0_lane;
  uint8_t CV_sym_30928_0_rt;
  auto DV_sym_133089_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_133383_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_133288_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2623 [F] s_b_0_0=sym_30904_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_9 else b_10 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_6, b_11,  */
  fixed_block_b_1: 
  {
    /* execute.simd:2625 [F] s_b_1_0 = sym_30916_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30916_0_lane;
    /* execute.simd:2625 [F] s_b_1_1=sym_30904_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2625 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2625 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2626 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2626 [F] s_b_2_1: sym_30928_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30928_0_rt = (uint8_t)0ULL;
    /* execute.simd:2626 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2632 [F] s_b_3_0=sym_30904_3_parameter_inst.rm (const) */
    /* execute.simd:2632 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2632 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2632 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2632 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_2, b_25,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2626 [F] s_b_4_0 = sym_30928_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30928_0_rt;
    /* execute.simd:2626 [F] s_b_4_1=sym_30904_3_parameter_inst.regcnt (const) */
    /* execute.simd:2626 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2626 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2627 [F] s_b_5_0=sym_30904_3_parameter_inst.arrangement (const) */
    /* execute.simd:2627 [F] s_b_5_1=sym_30904_3_parameter_inst.rt (const) */
    /* execute.simd:2627 [F] s_b_5_2 = sym_30928_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30928_0_rt;
    /* execute.simd:2627 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2627 [F] s_b_5_4 = sym_30916_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30916_0_lane;
    /* execute.simd:2627 [D] s_b_5_5 = sym_30910_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30910_0_address, emitter.context().types().u64());
    /* execute.simd:2627 [F] s_b_5_6: sym_133181_3_parameter_rt = s_b_5_3 (const), dominates: s_b_22_0 s_b_23_0 s_b_21_0 s_b_24_0 s_b_18_0 s_b_19_0 s_b_20_0  */
    CV_sym_133181_3_parameter_rt = s_b_5_3;
    /* execute.simd:2627 [F] s_b_5_7: sym_133189_3_parameter_lane = s_b_5_4 (const), dominates: s_b_22_3 s_b_23_3 s_b_21_3 s_b_24_3 s_b_18_3 s_b_19_3 s_b_20_3  */
    CV_sym_133189_3_parameter_lane = s_b_5_4;
    /* execute.simd:2627 [D] s_b_5_8: sym_133186_3_parameter_addr = s_b_5_5, dominates: s_b_22_2 s_b_23_2 s_b_21_2 s_b_24_2 s_b_18_2 s_b_19_2 s_b_20_2  */
    emitter.store_local(DV_sym_133186_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_133263_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_25_1  */
    CV_sym_133263_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_133266_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_133266_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3841 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3846 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3851 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3856 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3861 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3866 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3871 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3840 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_17 (const) -> b_22, b_23, b_21, b_24, b_17, b_18, b_19, b_20,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_24;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    default:
      goto fixed_block_b_17;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2625 [F] s_b_6_0 = sym_30916_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30916_0_lane;
    /* execute.simd:2625 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2625 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2625 [F] s_b_6_3: sym_30916_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30916_0_lane = s_b_6_2;
    /* execute.simd:2625 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2633 [F] s_b_7_0=sym_30904_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2730 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_7_4: If s_b_7_3: Jump b_26 else b_27 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_3, b_28,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2636 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2636 [D] s_b_8_1 = sym_30910_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_30910_0_address, emitter.context().types().u64());
    /* execute.simd:2636 [D] s_b_8_2: sym_133383_3_parameter_value = s_b_8_1, dominates: s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_133383_3_parameter_value, s_b_8_1);
    /* execute.a64:2746 [F] s_b_8_3 = !s_b_8_0 (const) */
    uint8_t s_b_8_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_8_4: If s_b_8_3: Jump b_34 else b_35 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2701 [F] s_b_9_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_9_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(s_b_9_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_9_4: If s_b_9_3: Jump b_12 else b_13 (const) */
    if (s_b_9_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2733 [F] s_b_10_0=sym_30904_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_133072_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_133072_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_133072_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_133072_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2623 [D] s_b_11_1: sym_30910_0_address = s_b_11_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30910_0_address, s_b_11_0);
    /* execute.simd:2625 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.simd:2625 [F] s_b_11_3: sym_30916_0_lane = s_b_11_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30916_0_lane = (uint8_t)0ULL;
    /* execute.simd:2625 [F] s_b_11_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2702 [D] s_b_12_0 = ReadReg 20 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_12_1: sym_133089_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_133089_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2702 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_9,  */
  fixed_block_b_13: 
  {
    /* execute.a64:3012 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_13_2 = (u8)s_b_13_1 (const) */
    /* execute.a64:2704 [F] s_b_13_3 = (u32)s_b_13_2 (const) */
    /* execute.a64:2704 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
    uint8_t s_b_13_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_13_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_13_6: If s_b_13_5: Jump b_15 else b_16 (const) */
    if (s_b_13_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_12, b_15, b_16,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2731 [D] s_b_14_0 = sym_133089_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_133089_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_133072_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_133072_0_return_symbol, s_b_14_0);
    /* ???:4294967295 [F] s_b_14_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_13,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2705 [D] s_b_15_0 = ReadReg 20 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_15_1: sym_133089_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_133089_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2705 [F] s_b_15_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_13,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2707 [D] s_b_16_0 = ReadReg 21 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_16_1: sym_133089_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_133089_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2707 [F] s_b_16_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3877 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_17_1: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3842 [F] s_b_18_0 = sym_133181_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_133181_3_parameter_rt;
    /* execute.simd:3842 [D] s_b_18_1 = ReadRegBank 15:s_b_18_0 (v8u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3843 [D] s_b_18_2 = sym_133186_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_133186_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3843 [F] s_b_18_3 = sym_133189_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_133189_3_parameter_lane;
    /* execute.simd:3843 [D] s_b_18_1[s_b_18_3] */
    auto s_b_18_4 = emitter.vector_extract(s_b_18_1, emitter.const_u8(s_b_18_3));
    /* ???:4294967295 [D] s_b_18_5: Store 1 s_b_18_2 <= s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_18_2, s_b_18_4);
    /* execute.simd:0 [F] s_b_18_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3847 [F] s_b_19_0 = sym_133181_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_133181_3_parameter_rt;
    /* execute.simd:3847 [D] s_b_19_1 = ReadRegBank 16:s_b_19_0 (v16u8) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3848 [D] s_b_19_2 = sym_133186_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_133186_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3848 [F] s_b_19_3 = sym_133189_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_133189_3_parameter_lane;
    /* execute.simd:3848 [D] s_b_19_1[s_b_19_3] */
    auto s_b_19_4 = emitter.vector_extract(s_b_19_1, emitter.const_u8(s_b_19_3));
    /* ???:4294967295 [D] s_b_19_5: Store 1 s_b_19_2 <= s_b_19_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_19_2, s_b_19_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_19_2, s_b_19_4);
    /* execute.simd:0 [F] s_b_19_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3852 [F] s_b_20_0 = sym_133181_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_133181_3_parameter_rt;
    /* execute.simd:3852 [D] s_b_20_1 = ReadRegBank 17:s_b_20_0 (v4u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3853 [D] s_b_20_2 = sym_133186_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_133186_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3853 [F] s_b_20_3 = sym_133189_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_133189_3_parameter_lane;
    /* execute.simd:3853 [D] s_b_20_1[s_b_20_3] */
    auto s_b_20_4 = emitter.vector_extract(s_b_20_1, emitter.const_u8(s_b_20_3));
    /* ???:4294967295 [D] s_b_20_5: Store 2 s_b_20_2 <= s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_20_2, s_b_20_4);
    /* execute.simd:0 [F] s_b_20_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3857 [F] s_b_21_0 = sym_133181_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_133181_3_parameter_rt;
    /* execute.simd:3857 [D] s_b_21_1 = ReadRegBank 18:s_b_21_0 (v8u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3858 [D] s_b_21_2 = sym_133186_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_133186_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3858 [F] s_b_21_3 = sym_133189_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_133189_3_parameter_lane;
    /* execute.simd:3858 [D] s_b_21_1[s_b_21_3] */
    auto s_b_21_4 = emitter.vector_extract(s_b_21_1, emitter.const_u8(s_b_21_3));
    /* ???:4294967295 [D] s_b_21_5: Store 2 s_b_21_2 <= s_b_21_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_21_2, s_b_21_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_21_2, s_b_21_4);
    /* execute.simd:0 [F] s_b_21_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3862 [F] s_b_22_0 = sym_133181_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_133181_3_parameter_rt;
    /* execute.simd:3862 [D] s_b_22_1 = ReadRegBank 19:s_b_22_0 (v2u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:3863 [D] s_b_22_2 = sym_133186_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_133186_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3863 [F] s_b_22_3 = sym_133189_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_133189_3_parameter_lane;
    /* execute.simd:3863 [D] s_b_22_1[s_b_22_3] */
    auto s_b_22_4 = emitter.vector_extract(s_b_22_1, emitter.const_u8(s_b_22_3));
    /* ???:4294967295 [D] s_b_22_5: Store 4 s_b_22_2 <= s_b_22_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_22_2, s_b_22_4);
    /* execute.simd:0 [F] s_b_22_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_23: 
  {
    /* execute.simd:3867 [F] s_b_23_0 = sym_133181_3_parameter_rt (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_133181_3_parameter_rt;
    /* execute.simd:3867 [D] s_b_23_1 = ReadRegBank 20:s_b_23_0 (v4u32) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:3868 [D] s_b_23_2 = sym_133186_3_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_133186_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3868 [F] s_b_23_3 = sym_133189_3_parameter_lane (const) uint8_t */
    uint8_t s_b_23_3 = CV_sym_133189_3_parameter_lane;
    /* execute.simd:3868 [D] s_b_23_1[s_b_23_3] */
    auto s_b_23_4 = emitter.vector_extract(s_b_23_1, emitter.const_u8(s_b_23_3));
    /* ???:4294967295 [D] s_b_23_5: Store 4 s_b_23_2 <= s_b_23_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_23_2, s_b_23_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_23_2, s_b_23_4);
    /* execute.simd:0 [F] s_b_23_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_24: 
  {
    /* execute.simd:3872 [F] s_b_24_0 = sym_133181_3_parameter_rt (const) uint8_t */
    uint8_t s_b_24_0 = CV_sym_133181_3_parameter_rt;
    /* execute.simd:3872 [D] s_b_24_1 = ReadRegBank 21:s_b_24_0 (v2u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))),s_b_24_1,emitter.const_u8(16));
    }
    /* execute.simd:3873 [D] s_b_24_2 = sym_133186_3_parameter_addr uint64_t */
    auto s_b_24_2 = emitter.load_local(DV_sym_133186_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3873 [F] s_b_24_3 = sym_133189_3_parameter_lane (const) uint8_t */
    uint8_t s_b_24_3 = CV_sym_133189_3_parameter_lane;
    /* execute.simd:3873 [D] s_b_24_1[s_b_24_3] */
    auto s_b_24_4 = emitter.vector_extract(s_b_24_1, emitter.const_u8(s_b_24_3));
    /* ???:4294967295 [D] s_b_24_5: Store 8 s_b_24_2 <= s_b_24_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_24_2, s_b_24_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_24_2, s_b_24_4);
    /* execute.simd:0 [F] s_b_24_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_17, b_18, b_19, b_20, b_21, b_22, b_23, b_24,  */
  fixed_block_b_25: 
  {
    /* ???:4294967295 [D] s_b_25_0 = sym_133266_1_tmp_s_b_5_5 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_133266_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_25_1 = sym_133263_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_25_1 = CV_sym_133263_1_tmp_s_b_5_2;
    /* execute.simd:2628 [F] s_b_25_2=sym_30904_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_25_3 = (u64)s_b_25_2 (const) */
    /* ???:4294967295 [D] s_b_25_4 = s_b_25_0+s_b_25_3 */
    auto s_b_25_4 = emitter.add(s_b_25_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2628 [D] s_b_25_5: sym_30910_0_address = s_b_25_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30910_0_address, s_b_25_4);
    /* execute.simd:2626 [F] s_b_25_6 = constant u8 1 (const) */
    /* execute.simd:2626 [F] s_b_25_7 = s_b_25_1+s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(s_b_25_1 + (uint8_t)1ULL));
    /* execute.simd:2626 [F] s_b_25_8: sym_30928_0_rt = s_b_25_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30928_0_rt = s_b_25_7;
    /* execute.simd:2626 [F] s_b_25_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2701 [F] s_b_26_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_26_1 = __builtin_get_feature */
    uint32_t s_b_26_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_26_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(s_b_26_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_26_4: If s_b_26_3: Jump b_29 else b_30 (const) */
    if (s_b_26_3) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_7,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2733 [F] s_b_27_0=sym_30904_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_27_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_27_2: sym_133288_0_return_symbol = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_133288_0_return_symbol, s_b_27_1);
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_31,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_133288_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_133288_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2633 [F] s_b_28_1=sym_30904_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_28_2 = (u32)s_b_28_1 (const) */
    /* execute.a64:2651 [F] s_b_28_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_28_4 = s_b_28_2==s_b_28_3 (const) */
    uint8_t s_b_28_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_28_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_28_6 = ReadRegBank 0:s_b_28_1 (u64) */
    auto s_b_28_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_28_7: Select s_b_28_4 ? s_b_28_5 : s_b_28_6 */
    dbt::el::Value *s_b_28_7;
    s_b_28_7 = (s_b_28_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_28_6);
    /* execute.simd:2633 [D] s_b_28_8 = s_b_28_0+s_b_28_7 */
    auto s_b_28_8 = emitter.add(s_b_28_0, s_b_28_7);
    /* execute.simd:2633 [D] s_b_28_9: sym_30910_0_address = s_b_28_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_30910_0_address, s_b_28_8);
    /* execute.simd:2633 [F] s_b_28_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_26,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2702 [D] s_b_29_0 = ReadReg 20 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_29_1: sym_133305_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_133305_1__R_s_b_3_0, s_b_29_0);
    /* execute.a64:2702 [F] s_b_29_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_26,  */
  fixed_block_b_30: 
  {
    /* execute.a64:3012 [F] s_b_30_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_30_1 = __builtin_get_feature */
    uint32_t s_b_30_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_30_2 = (u8)s_b_30_1 (const) */
    /* execute.a64:2704 [F] s_b_30_3 = (u32)s_b_30_2 (const) */
    /* execute.a64:2704 [F] s_b_30_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_30_5 = s_b_30_3==s_b_30_4 (const) */
    uint8_t s_b_30_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_30_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_30_6: If s_b_30_5: Jump b_32 else b_33 (const) */
    if (s_b_30_5) 
    {
      goto fixed_block_b_32;
    }
    else 
    {
      goto fixed_block_b_33;
    }
  }
  /* b_29, b_32, b_33,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2731 [D] s_b_31_0 = sym_133305_1__R_s_b_3_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_133305_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1: sym_133288_0_return_symbol = s_b_31_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_133288_0_return_symbol, s_b_31_0);
    /* ???:4294967295 [F] s_b_31_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_30,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2705 [D] s_b_32_0 = ReadReg 20 (u64) */
    auto s_b_32_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_32_1: sym_133305_1__R_s_b_3_0 = s_b_32_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_133305_1__R_s_b_3_0, s_b_32_0);
    /* execute.a64:2705 [F] s_b_32_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_30,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2707 [D] s_b_33_0 = ReadReg 21 (u64) */
    auto s_b_33_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_33_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_33_1: sym_133305_1__R_s_b_3_0 = s_b_33_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_133305_1__R_s_b_3_0, s_b_33_0);
    /* execute.a64:2707 [F] s_b_33_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_8,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2747 [D] s_b_34_0 = sym_133383_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_133383_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_34_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_34_2 = s_b_34_0&s_b_34_1 */
    auto s_b_34_2 = emitter.bitwise_and(s_b_34_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_34_3: sym_133383_3_parameter_value = s_b_34_2, dominates: s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_133383_3_parameter_value, s_b_34_2);
    /* execute.a64:2747 [F] s_b_34_4: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_8, b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2750 [F] s_b_35_0=sym_30904_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
    /* execute.a64:2750 [F] s_b_35_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_35_3 = s_b_35_1==s_b_35_2 (const) */
    uint8_t s_b_35_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_35_4: If s_b_35_3: Jump b_36 else b_37 (const) */
    if (s_b_35_3) 
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
    /* execute.a64:2751 [D] s_b_36_0 = sym_133383_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_133383_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_36_1: sym_133442_3_parameter_value = s_b_36_0, dominates: s_b_39_0 s_b_40_0 s_b_41_0  */
    emitter.store_local(DV_sym_133442_3_parameter_value, s_b_36_0);
    /* execute.a64:2714 [F] s_b_36_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_36_3 = __builtin_get_feature */
    uint32_t s_b_36_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_36_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(s_b_36_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_36_6: If s_b_36_5: Jump b_39 else b_42 (const) */
    if (s_b_36_5) 
    {
      goto fixed_block_b_39;
    }
    else 
    {
      goto fixed_block_b_42;
    }
  }
  /* b_35,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2753 [F] s_b_37_0=sym_30904_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_37_1 = sym_133383_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_133383_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_37_2: WriteRegBank 0:s_b_37_0 = s_b_37_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_37_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_37_1);
    /* execute.a64:2753 [F] s_b_37_3: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_37, b_39, b_40, b_41,  */
  fixed_block_b_38: 
  {
    /* ???:4294967295 [F] s_b_38_0: Return */
    goto fixed_done;
  }
  /* b_36,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2715 [D] s_b_39_0 = sym_133442_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_133442_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_39_1: WriteReg 20 = s_b_39_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_39_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_39_0);
    /* execute.a64:2715 [F] s_b_39_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_42,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2718 [D] s_b_40_0 = sym_133442_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_133442_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_40_1: WriteReg 20 = s_b_40_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_40_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_40_0);
    /* execute.a64:2718 [F] s_b_40_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_42,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2720 [D] s_b_41_0 = sym_133442_3_parameter_value uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_133442_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_41_1: WriteReg 21 = s_b_41_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_41_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_41_0);
    /* execute.a64:2720 [F] s_b_41_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_36,  */
  fixed_block_b_42: 
  {
    /* execute.a64:3012 [F] s_b_42_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_42_1 = __builtin_get_feature */
    uint32_t s_b_42_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_42_2 = (u8)s_b_42_1 (const) */
    /* execute.a64:2717 [F] s_b_42_3 = (u32)s_b_42_2 (const) */
    /* execute.a64:2717 [F] s_b_42_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_42_5 = s_b_42_3==s_b_42_4 (const) */
    uint8_t s_b_42_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_42_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_42_6: If s_b_42_5: Jump b_40 else b_41 (const) */
    if (s_b_42_5) 
    {
      goto fixed_block_b_40;
    }
    else 
    {
      goto fixed_block_b_41;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stnp(const aarch64_decode_a64_LS_NO_ALLOC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_135960_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_135977_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31310_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:866 [F] s_b_0_0=sym_31301_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_4 else b_5 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_6,  */
  fixed_block_b_1: 
  {
    /* execute.a64:869 [D] s_b_1_0 = sym_31310_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31310_0_addr, emitter.context().types().u64());
    /* execute.a64:869 [F] s_b_1_1=sym_31301_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_1_2 = (u32)s_b_1_1 (const) */
    /* execute.a64:2646 [F] s_b_1_3 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_4 = s_b_1_2==s_b_1_3 (const) */
    uint8_t s_b_1_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_5 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_6 = ReadRegBank 1:s_b_1_1 (u32) */
    auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_1_6,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_7: Select s_b_1_4 ? s_b_1_5 : s_b_1_6 */
    dbt::el::Value *s_b_1_7;
    s_b_1_7 = (s_b_1_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_6);
    /* execute.a64:2659 [D] s_b_1_8 = (u64)s_b_1_7 */
    auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
    /* execute.a64:1792 [D] s_b_1_9 = (u32)s_b_1_8 */
    auto s_b_1_9 = emitter.truncate(s_b_1_8, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_1_10: Store 4 s_b_1_0 <= s_b_1_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_1_0, s_b_1_9, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_1_0, s_b_1_9);
    /* execute.a64:870 [F] s_b_1_11 = constant u64 4 (const) */
    /* execute.a64:870 [D] s_b_1_12 = s_b_1_0+s_b_1_11 */
    auto s_b_1_12 = emitter.add(s_b_1_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:870 [F] s_b_1_13=sym_31301_3_parameter_inst.rt2 (const) */
    /* execute.a64:2646 [F] s_b_1_14 = (u32)s_b_1_13 (const) */
    /* execute.a64:2646 [F] s_b_1_15 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_16 = s_b_1_14==s_b_1_15 (const) */
    uint8_t s_b_1_16 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_17 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_18 = ReadRegBank 1:s_b_1_13 (u32) */
    auto s_b_1_18 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_1_18,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_19: Select s_b_1_16 ? s_b_1_17 : s_b_1_18 */
    dbt::el::Value *s_b_1_19;
    s_b_1_19 = (s_b_1_16) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_18);
    /* execute.a64:2659 [D] s_b_1_20 = (u64)s_b_1_19 */
    auto s_b_1_20 = emitter.zx(s_b_1_19, emitter.context().types().u64());
    /* execute.a64:1792 [D] s_b_1_21 = (u32)s_b_1_20 */
    auto s_b_1_21 = emitter.truncate(s_b_1_20, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_1_22: Store 4 s_b_1_12 <= s_b_1_21 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_1_12, s_b_1_21, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_1_12, s_b_1_21);
    /* execute.a64:0 [F] s_b_1_23: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_6,  */
  fixed_block_b_3: 
  {
    /* execute.a64:872 [D] s_b_3_0 = sym_31310_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31310_0_addr, emitter.context().types().u64());
    /* execute.a64:872 [F] s_b_3_1=sym_31301_3_parameter_inst.rt (const) */
    /* execute.a64:2651 [F] s_b_3_2 = (u32)s_b_3_1 (const) */
    /* execute.a64:2651 [F] s_b_3_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_3_4 = s_b_3_2==s_b_3_3 (const) */
    uint8_t s_b_3_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_3_6 = ReadRegBank 0:s_b_3_1 (u64) */
    auto s_b_3_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_3_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_3_7: Select s_b_3_4 ? s_b_3_5 : s_b_3_6 */
    dbt::el::Value *s_b_3_7;
    s_b_3_7 = (s_b_3_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_3_6);
    /* ???:4294967295 [D] s_b_3_8: Store 8 s_b_3_0 <= s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_3_0, s_b_3_7, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_3_0, s_b_3_7);
    /* execute.a64:873 [F] s_b_3_9 = constant u64 8 (const) */
    /* execute.a64:873 [D] s_b_3_10 = s_b_3_0+s_b_3_9 */
    auto s_b_3_10 = emitter.add(s_b_3_0, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:873 [F] s_b_3_11=sym_31301_3_parameter_inst.rt2 (const) */
    /* execute.a64:2651 [F] s_b_3_12 = (u32)s_b_3_11 (const) */
    /* execute.a64:2651 [F] s_b_3_13 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_3_14 = s_b_3_12==s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_3_15 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_3_16 = ReadRegBank 0:s_b_3_11 (u64) */
    auto s_b_3_16 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_3_16,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_3_17: Select s_b_3_14 ? s_b_3_15 : s_b_3_16 */
    dbt::el::Value *s_b_3_17;
    s_b_3_17 = (s_b_3_14) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_3_16);
    /* ???:4294967295 [D] s_b_3_18: Store 8 s_b_3_10 <= s_b_3_17 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_3_10, s_b_3_17, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_3_10, s_b_3_17);
    /* execute.a64:0 [F] s_b_3_19: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2701 [F] s_b_4_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(s_b_4_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_4_4: If s_b_4_3: Jump b_7 else b_8 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2733 [F] s_b_5_0=sym_31301_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_135960_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_135960_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_135960_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_135960_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:866 [F] s_b_6_1=sym_31301_3_parameter_inst.imms64 (const) */
    /* execute.a64:866 [F] s_b_6_2 = (u64)s_b_6_1 (const) */
    /* execute.a64:866 [D] s_b_6_3 = s_b_6_0+s_b_6_2 */
    auto s_b_6_3 = emitter.add(s_b_6_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:866 [D] s_b_6_4: sym_31310_0_addr = s_b_6_3, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_31310_0_addr, s_b_6_3);
    /* execute.a64:868 [F] s_b_6_5=sym_31301_3_parameter_inst.opc (const) */
    /* execute.a64:868 [F] s_b_6_6 = (u32)s_b_6_5 (const) */
    /* execute.a64:868 [F] s_b_6_7 = constant u32 0 (const) */
    /* execute.a64:868 [F] s_b_6_8 = s_b_6_6==s_b_6_7 (const) */
    uint8_t s_b_6_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:868 [F] s_b_6_9: If s_b_6_8: Jump b_1 else b_3 (const) */
    if (s_b_6_8) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2702 [D] s_b_7_0 = ReadReg 20 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_7_1: sym_135977_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135977_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2702 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:3012 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_8_2 = (u8)s_b_8_1 (const) */
    /* execute.a64:2704 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:2704 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_8_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_8_6: If s_b_8_5: Jump b_10 else b_11 (const) */
    if (s_b_8_5) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_7, b_10, b_11,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2731 [D] s_b_9_0 = sym_135977_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_135977_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_135960_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_135960_0_return_symbol, s_b_9_0);
    /* ???:4294967295 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2705 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_10_1: sym_135977_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135977_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2705 [F] s_b_10_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2707 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_11_1: sym_135977_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135977_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2707 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_strb(const aarch64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_140455_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_140472_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_140630_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32188_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_140591_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:997 [F] s_b_0_0=sym_32182_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_5 else b_6 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_5;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_7,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1000 [D] s_b_1_0 = sym_32188_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_32188_0_address, emitter.context().types().u64());
    /* execute.a64:1000 [F] s_b_1_1=sym_32182_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1000 [D] s_b_1_4: sym_32188_0_address = s_b_1_3, dominates: s_b_2_9 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_32188_0_address, s_b_1_3);
    /* execute.a64:1000 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1003 [F] s_b_2_0=sym_32182_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2646 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_2_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_2_5 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_2_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_2_6: Select s_b_2_3 ? s_b_2_4 : s_b_2_5 */
    dbt::el::Value *s_b_2_6;
    s_b_2_6 = (s_b_2_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_2_5);
    /* execute.a64:2659 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:1003 [D] s_b_2_8 = (u8)s_b_2_7 */
    auto s_b_2_8 = emitter.truncate(s_b_2_7, emitter.context().types().u8());
    /* execute.a64:1004 [D] s_b_2_9 = sym_32188_0_address uint64_t */
    auto s_b_2_9 = emitter.load_local(DV_sym_32188_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_10: Store 1 s_b_2_9 <= s_b_2_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_2_9, s_b_2_8, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_2_9, s_b_2_8);
    /* execute.a64:1006 [F] s_b_2_11=sym_32182_3_parameter_inst.P (const) */
    /* execute.a64:1006 [F] s_b_2_12 = !s_b_2_11 (const) */
    uint8_t s_b_2_12 = !insn.P;
    /* execute.a64:1006 [F] s_b_2_13: If s_b_2_12: Jump b_3 else b_4 (const) */
    if (s_b_2_12) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1007 [D] s_b_3_0 = sym_32188_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_32188_0_address, emitter.context().types().u64());
    /* execute.a64:1007 [F] s_b_3_1=sym_32182_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1007 [D] s_b_3_4: sym_32188_0_address = s_b_3_3, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_32188_0_address, s_b_3_3);
    /* execute.a64:1007 [F] s_b_3_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_2, b_3,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1010 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.a64:1010 [D] s_b_4_1 = sym_32188_0_address uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_32188_0_address, emitter.context().types().u64());
    /* execute.a64:1010 [D] s_b_4_2: sym_140591_3_parameter_value = s_b_4_1, dominates: s_b_13_0 s_b_15_0 s_b_16_1  */
    emitter.store_local(DV_sym_140591_3_parameter_value, s_b_4_1);
    /* execute.a64:2746 [F] s_b_4_3 = !s_b_4_0 (const) */
    uint8_t s_b_4_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_4_4: If s_b_4_3: Jump b_13 else b_14 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2701 [F] s_b_5_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_5_1 = __builtin_get_feature */
    uint32_t s_b_5_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(s_b_5_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2733 [F] s_b_6_0=sym_32182_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_6_1 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_6_2: sym_140455_0_return_symbol = s_b_6_1, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_140455_0_return_symbol, s_b_6_1);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_10,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [D] s_b_7_0 = sym_140455_0_return_symbol uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_140455_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:997 [D] s_b_7_1: sym_32188_0_address = s_b_7_0, dominates: s_b_1_0 s_b_2_9 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_32188_0_address, s_b_7_0);
    /* execute.a64:999 [F] s_b_7_2=sym_32182_3_parameter_inst.P (const) */
    /* execute.a64:999 [F] s_b_7_3: If s_b_7_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2702 [D] s_b_8_0 = ReadReg 20 (u64) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_8_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_8_1: sym_140472_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_140472_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2702 [F] s_b_8_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.a64:3012 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_9_2 = (u8)s_b_9_1 (const) */
    /* execute.a64:2704 [F] s_b_9_3 = (u32)s_b_9_2 (const) */
    /* execute.a64:2704 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_9_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_9_6: If s_b_9_5: Jump b_11 else b_12 (const) */
    if (s_b_9_5) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_8, b_11, b_12,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2731 [D] s_b_10_0 = sym_140472_1__R_s_b_3_0 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_140472_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1: sym_140455_0_return_symbol = s_b_10_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_140455_0_return_symbol, s_b_10_0);
    /* ???:4294967295 [F] s_b_10_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2705 [D] s_b_11_0 = ReadReg 20 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_11_1: sym_140472_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_140472_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2705 [F] s_b_11_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2707 [D] s_b_12_0 = ReadReg 21 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_12_1: sym_140472_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_140472_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2707 [F] s_b_12_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_4,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2747 [D] s_b_13_0 = sym_140591_3_parameter_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_140591_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_13_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_13_2 = s_b_13_0&s_b_13_1 */
    auto s_b_13_2 = emitter.bitwise_and(s_b_13_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_13_3: sym_140591_3_parameter_value = s_b_13_2, dominates: s_b_15_0 s_b_16_1  */
    emitter.store_local(DV_sym_140591_3_parameter_value, s_b_13_2);
    /* execute.a64:2747 [F] s_b_13_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_4, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2750 [F] s_b_14_0=sym_32182_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
    /* execute.a64:2750 [F] s_b_14_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_14_3 = s_b_14_1==s_b_14_2 (const) */
    uint8_t s_b_14_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_14_4: If s_b_14_3: Jump b_15 else b_16 (const) */
    if (s_b_14_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2751 [D] s_b_15_0 = sym_140591_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_140591_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_15_1: sym_140630_3_parameter_value = s_b_15_0, dominates: s_b_18_0 s_b_19_0 s_b_20_0  */
    emitter.store_local(DV_sym_140630_3_parameter_value, s_b_15_0);
    /* execute.a64:2714 [F] s_b_15_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_15_3 = __builtin_get_feature */
    uint32_t s_b_15_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_15_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_15_5 = s_b_15_3==s_b_15_4 (const) */
    uint8_t s_b_15_5 = ((uint8_t)(s_b_15_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_15_6: If s_b_15_5: Jump b_18 else b_21 (const) */
    if (s_b_15_5) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2753 [F] s_b_16_0=sym_32182_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_16_1 = sym_140591_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_140591_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_16_1);
    /* execute.a64:2753 [F] s_b_16_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_16, b_18, b_19, b_20,  */
  fixed_block_b_17: 
  {
    /* ???:4294967295 [F] s_b_17_0: Return */
    goto fixed_done;
  }
  /* b_15,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2715 [D] s_b_18_0 = sym_140630_3_parameter_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_140630_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_18_1: WriteReg 20 = s_b_18_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_18_0);
    /* execute.a64:2715 [F] s_b_18_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_21,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2718 [D] s_b_19_0 = sym_140630_3_parameter_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_140630_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_19_1: WriteReg 20 = s_b_19_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_19_0);
    /* execute.a64:2718 [F] s_b_19_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_21,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2720 [D] s_b_20_0 = sym_140630_3_parameter_value uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_140630_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_20_1: WriteReg 21 = s_b_20_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_20_0);
    /* execute.a64:2720 [F] s_b_20_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15,  */
  fixed_block_b_21: 
  {
    /* execute.a64:3012 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_21_1 = __builtin_get_feature */
    uint32_t s_b_21_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_21_2 = (u8)s_b_21_1 (const) */
    /* execute.a64:2717 [F] s_b_21_3 = (u32)s_b_21_2 (const) */
    /* execute.a64:2717 [F] s_b_21_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_21_5 = s_b_21_3==s_b_21_4 (const) */
    uint8_t s_b_21_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_21_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_21_6: If s_b_21_5: Jump b_19 else b_20 (const) */
    if (s_b_21_5) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sttrb(const aarch64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:3075 [D] s_b_0_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stxrh(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto block_b_12 = emitter.context().create_block();
  auto block_b_13 = emitter.context().create_block();
  auto DV_sym_144872_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32951_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_144855_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:657 [F] s_b_0_0=sym_32945_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_4 else b_5 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  // BLOCK b_1 not fully fixed
  // BLOCK b_2 not fully fixed
  // BLOCK b_3 not fully fixed
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2701 [F] s_b_4_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(s_b_4_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_4_4: If s_b_4_3: Jump b_7 else b_8 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2733 [F] s_b_5_0=sym_32945_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_144855_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_144855_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_144855_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_144855_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:657 [D] s_b_6_1: sym_32951_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_32951_0_address, s_b_6_0);
    /* execute.a64:659 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:659 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:659 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_1;
        dynamic_block_queue.push(block_b_1);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_3;
        dynamic_block_queue.push(block_b_3);
        false_target = block;
      }
      emitter.branch(s_b_6_3, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2702 [D] s_b_7_0 = ReadReg 20 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_7_1: sym_144872_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144872_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2702 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:3012 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_8_2 = (u8)s_b_8_1 (const) */
    /* execute.a64:2704 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:2704 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_8_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_8_6: If s_b_8_5: Jump b_10 else b_11 (const) */
    if (s_b_8_5) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_7, b_10, b_11,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2731 [D] s_b_9_0 = sym_144872_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_144872_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_144855_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_144855_0_return_symbol, s_b_9_0);
    /* ???:4294967295 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2705 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_10_1: sym_144872_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144872_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2705 [F] s_b_10_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2707 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_11_1: sym_144872_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144872_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2707 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  // BLOCK b_12 not fully fixed
  // BLOCK b_13 not fully fixed
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
        /* execute.a64:660 [D] s_b_1_0 = sym_32951_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_32951_0_address, emitter.context().types().u64());
        /* execute.a64:660 [F] s_b_1_1=sym_32945_3_parameter_inst.rt (const) */
        /* execute.a64:2646 [F] s_b_1_2 = (u32)s_b_1_1 (const) */
        /* execute.a64:2646 [F] s_b_1_3 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_1_4 = s_b_1_2==s_b_1_3 (const) */
        uint8_t s_b_1_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_1_5 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_1_6 = ReadRegBank 1:s_b_1_1 (u32) */
        auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_1_6,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_1_7: Select s_b_1_4 ? s_b_1_5 : s_b_1_6 */
        dbt::el::Value *s_b_1_7;
        s_b_1_7 = (s_b_1_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_6);
        /* execute.a64:2659 [D] s_b_1_8 = (u64)s_b_1_7 */
        auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
        /* execute.a64:1787 [D] s_b_1_9 = (u16)s_b_1_8 */
        auto s_b_1_9 = emitter.truncate(s_b_1_8, emitter.context().types().u16());
        /* ???:4294967295 [D] s_b_1_10: Store 2 s_b_1_0 <= s_b_1_9 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_1_0, s_b_1_9, emitter.const_u8(2));
        }
        emitter.store_memory(s_b_1_0, s_b_1_9);
        /* execute.a64:661 [F] s_b_1_11=sym_32945_3_parameter_inst.rs (const) */
        /* execute.a64:2674 [F] s_b_1_12 = (u32)s_b_1_11 (const) */
        /* execute.a64:2674 [F] s_b_1_13 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_1_14 = s_b_1_12==s_b_1_13 (const) */
        uint8_t s_b_1_14 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_1_15: If s_b_1_14: Jump b_2 else b_13 (const) */
        if (s_b_1_14) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_13;
          dynamic_block_queue.push(block_b_13);
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
        /* execute.a64:663 [F] s_b_3_0=sym_32945_3_parameter_inst.rs (const) */
        /* execute.a64:2674 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.a64:2674 [F] s_b_3_2 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
        uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_3_4: If s_b_3_3: Jump b_2 else b_12 (const) */
        if (s_b_3_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_12;
          dynamic_block_queue.push(block_b_12);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.a64:2676 [F] s_b_12_0=sym_32945_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_12_1 = constant u64 1 (const) */
        /* execute.a64:2676 [F] s_b_12_2: WriteRegBank 0:s_b_12_0 = s_b_12_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:0 [F] s_b_12_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.a64:2676 [F] s_b_13_0=sym_32945_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_13_1 = constant u64 0 (const) */
        /* execute.a64:2676 [F] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_13_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_tbz(const aarch64_decode_a64_TEST_B_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto DV_sym_147030_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_36147_0_base = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:523 [F] s_b_0_0=sym_36139_3_parameter_inst.b5 (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_4 else b_6 (const) */
    if (insn.b5) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  // BLOCK b_1 not fully fixed
  // BLOCK b_2 not fully fixed
  // BLOCK b_3 not fully fixed
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2657 [F] s_b_4_0=sym_36139_3_parameter_inst.rt (const) */
    /* execute.a64:2651 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2651 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_4_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_4_5 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_4_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_4_5);
    /* ???:4294967295 [D] s_b_4_7: sym_147030_0_return_symbol = s_b_4_6, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_147030_0_return_symbol, s_b_4_6);
    /* ???:4294967295 [F] s_b_4_8: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_6,  */
  fixed_block_b_5: 
  {
    /* ???:4294967295 [D] s_b_5_0 = sym_147030_0_return_symbol uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_147030_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:525 [D] s_b_5_1 = read_pc */
    auto s_b_5_1 = emitter.load_pc();
    /* execute.a64:525 [D] s_b_5_2: sym_36147_0_base = s_b_5_1, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_36147_0_base, s_b_5_1);
    /* execute.a64:527 [F] s_b_5_3=sym_36139_3_parameter_inst.bit_pos (const) */
    /* execute.a64:527 [F] s_b_5_4 = (u64)s_b_5_3 (const) */
    /* execute.a64:527 [D] s_b_5_5 = s_b_5_0>>s_b_5_4 */
    auto s_b_5_5 = emitter.shr(s_b_5_0, emitter.const_u64(((uint64_t)insn.bit_pos)));
    /* execute.a64:527 [F] s_b_5_6 = constant u64 1 (const) */
    /* execute.a64:527 [D] s_b_5_7 = s_b_5_5&s_b_5_6 */
    auto s_b_5_7 = emitter.bitwise_and(s_b_5_5, emitter.const_u64((uint64_t)1ULL));
    /* execute.a64:527 [F] s_b_5_8=sym_36139_3_parameter_inst.op (const) */
    /* execute.a64:527 [F] s_b_5_9 = (u64)s_b_5_8 (const) */
    /* execute.a64:527 [D] s_b_5_10 = s_b_5_7==s_b_5_9 */
    auto s_b_5_10 = emitter.cmp_eq(s_b_5_7, emitter.const_u64(((uint64_t)insn.op)));
    /* execute.a64:527 [D] s_b_5_11: If s_b_5_10: Jump b_1 else b_3 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_1;
        dynamic_block_queue.push(block_b_1);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_3;
        dynamic_block_queue.push(block_b_3);
        false_target = block;
      }
      emitter.branch(s_b_5_10, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2659 [F] s_b_6_0=sym_36139_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2646 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_6_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_6_5 = ReadRegBank 1:s_b_6_0 (u32) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_6_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_6_6: Select s_b_6_3 ? s_b_6_4 : s_b_6_5 */
    dbt::el::Value *s_b_6_6;
    s_b_6_6 = (s_b_6_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_6_5);
    /* execute.a64:2659 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_8: sym_147030_0_return_symbol = s_b_6_7, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_147030_0_return_symbol, s_b_6_7);
    /* ???:4294967295 [F] s_b_6_9: Jump b_5 (const) */
    goto fixed_block_b_5;
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
        /* execute.a64:528 [D] s_b_1_0 = sym_36147_0_base uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_36147_0_base, emitter.context().types().u64());
        /* execute.a64:528 [D] s_b_1_1 = (s64)s_b_1_0 */
        auto s_b_1_1 = emitter.reinterpret(s_b_1_0, emitter.context().types().s64());
        /* execute.a64:528 [F] s_b_1_2=sym_36139_3_parameter_inst.imms64 (const) */
        /* execute.a64:528 [D] s_b_1_3 = s_b_1_1+s_b_1_2 */
        auto s_b_1_3 = emitter.add(s_b_1_1, emitter.const_s64(insn.imms64));
        /* execute.a64:528 [D] s_b_1_4 = (u64)s_b_1_3 */
        auto s_b_1_4 = emitter.reinterpret(s_b_1_3, emitter.context().types().u64());
        /* execute.a64:528 [D] s_b_1_5 = write_pc */
        emitter.store_pc(s_b_1_4);
        /* execute.a64:528 [F] s_b_1_6: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
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
        /* execute.a64:530 [D] s_b_3_0 = sym_36147_0_base uint64_t */
        auto s_b_3_0 = emitter.load_local(DV_sym_36147_0_base, emitter.context().types().u64());
        /* execute.a64:530 [F] s_b_3_1 = constant u64 4 (const) */
        /* execute.a64:530 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
        auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64((uint64_t)4ULL));
        /* execute.a64:530 [D] s_b_3_3 = write_pc */
        emitter.store_pc(s_b_3_2);
        /* execute.a64:530 [F] s_b_3_4: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ucvtf_simd(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4291 [F] s_b_0_0=sym_39549_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4291 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4292 [F] s_b_1_0=sym_39549_3_parameter_inst.size (const) */
    /* execute.simd:4292 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4292 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4292 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4292 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4300 [F] s_b_3_0=sym_39549_3_parameter_inst.size (const) */
    /* execute.simd:4300 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4300 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4300 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4300 [F] s_b_3_4=sym_39549_3_parameter_inst.Q (const) */
    /* execute.simd:4300 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4300 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:4300 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4300 [F] s_b_3_12: If s_b_3_11: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4294 [F] s_b_4_0=sym_39549_3_parameter_inst.rd (const) */
    /* execute.simd:4294 [F] s_b_4_1=sym_39549_3_parameter_inst.rn (const) */
    /* execute.simd:6229 [D] s_b_4_2 = ReadRegBank 6:s_b_4_1 (u32) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_2,emitter.const_u8(4));
    }
    /* execute.simd:4294 [D] s_b_4_3 = (u32)s_b_4_2 */
    auto s_b_4_3 = (dbt::el::Value *)s_b_4_2;
    /* execute.simd:4294 [D] s_b_4_4 = (f32)s_b_4_3 */
    auto s_b_4_4 = emitter.convert(s_b_4_3, emitter.context().types().f32());
    /* execute.simd:6169 [D] s_b_4_5: WriteRegBank 9:s_b_4_0 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:6170 [F] s_b_4_6 = constant u32 0 (const) */
    /* execute.simd:6170 [F] s_b_4_7: WriteRegBank 10:s_b_4_0 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6171 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:6171 [F] s_b_4_9: WriteRegBank 3:s_b_4_0 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4297 [F] s_b_5_0=sym_39549_3_parameter_inst.rd (const) */
    /* execute.simd:4297 [F] s_b_5_1=sym_39549_3_parameter_inst.rn (const) */
    /* execute.simd:6234 [D] s_b_5_2 = ReadRegBank 7:s_b_5_1 (u64) */
    auto s_b_5_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_2,emitter.const_u8(8));
    }
    /* execute.simd:4297 [D] s_b_5_3 = (u64)s_b_5_2 */
    auto s_b_5_3 = (dbt::el::Value *)s_b_5_2;
    /* execute.simd:4297 [D] s_b_5_4 = (f64)s_b_5_3 */
    auto s_b_5_4 = emitter.convert(s_b_5_3, emitter.context().types().f64());
    /* execute.simd:6177 [D] s_b_5_5: WriteRegBank 11:s_b_5_0 = s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4);
    /* execute.simd:6178 [F] s_b_5_6 = constant u64 0 (const) */
    /* execute.simd:6178 [F] s_b_5_7: WriteRegBank 3:s_b_5_0 = s_b_5_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_5_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4301 [F] s_b_6_0=sym_39549_3_parameter_inst.rn (const) */
    /* execute.simd:4301 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v2f32 
    {
    }
    (const) */
    /* execute.simd:4304 [F] s_b_6_3 = constant s32 0 (const) */
    /* execute.simd:4304 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4304 [D] s_b_6_5 = (f32)s_b_6_4 */
    auto s_b_6_5 = emitter.convert(s_b_6_4, emitter.context().types().f32());
    /* execute.simd:4304 [F] s_b_6_6 = constant s32 0 (const) */
    /* execute.simd:4304 [D] s_b_6_7 = s_b_6_2[s_b_6_6] <= s_b_6_5 */
    auto s_b_6_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<float, 2>(0.000000)[0], emitter.context().types().v2f32()), emitter.const_s32((int32_t)0ULL), s_b_6_5);
    /* execute.simd:4305 [F] s_b_6_8 = constant s32 1 (const) */
    /* execute.simd:4305 [D] s_b_6_1[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4305 [D] s_b_6_10 = (f32)s_b_6_9 */
    auto s_b_6_10 = emitter.convert(s_b_6_9, emitter.context().types().f32());
    /* execute.simd:4305 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:4305 [D] s_b_6_12 = s_b_6_7[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_7, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:4307 [F] s_b_6_13=sym_39549_3_parameter_inst.rd (const) */
    /* execute.simd:4307 [D] s_b_6_14: WriteRegBank 12:s_b_6_13 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12);
    /* execute.simd:4308 [F] s_b_6_15=sym_39549_3_parameter_inst.rd (const) */
    /* execute.simd:4308 [F] s_b_6_16 = constant u64 0 (const) */
    /* execute.simd:4308 [F] s_b_6_17: WriteRegBank 3:s_b_6_15 = s_b_6_16 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4301 [F] s_b_6_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4309 [F] s_b_7_0=sym_39549_3_parameter_inst.size (const) */
    /* execute.simd:4309 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4309 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4309 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4309 [F] s_b_7_4=sym_39549_3_parameter_inst.Q (const) */
    /* execute.simd:4309 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4309 [F] s_b_7_6 = constant u32 1 (const) */
    /* execute.simd:4309 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:4309 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4310 [F] s_b_8_0=sym_39549_3_parameter_inst.rn (const) */
    /* execute.simd:4310 [D] s_b_8_1 = ReadRegBank 20:s_b_8_0 (v4u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_2 = constant v4f32 
    {
    }
    (const) */
    /* execute.simd:4313 [F] s_b_8_3 = constant s32 0 (const) */
    /* execute.simd:4313 [D] s_b_8_1[s_b_8_3] */
    auto s_b_8_4 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4313 [D] s_b_8_5 = (f32)s_b_8_4 */
    auto s_b_8_5 = emitter.convert(s_b_8_4, emitter.context().types().f32());
    /* execute.simd:4313 [F] s_b_8_6 = constant s32 0 (const) */
    /* execute.simd:4313 [D] s_b_8_7 = s_b_8_2[s_b_8_6] <= s_b_8_5 */
    auto s_b_8_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<float, 4>(0.000000)[0], emitter.context().types().v4f32()), emitter.const_s32((int32_t)0ULL), s_b_8_5);
    /* execute.simd:4314 [F] s_b_8_8 = constant s32 1 (const) */
    /* execute.simd:4314 [D] s_b_8_1[s_b_8_8] */
    auto s_b_8_9 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4314 [D] s_b_8_10 = (f32)s_b_8_9 */
    auto s_b_8_10 = emitter.convert(s_b_8_9, emitter.context().types().f32());
    /* execute.simd:4314 [F] s_b_8_11 = constant s32 1 (const) */
    /* execute.simd:4314 [D] s_b_8_12 = s_b_8_7[s_b_8_11] <= s_b_8_10 */
    auto s_b_8_12 = emitter.vector_insert(s_b_8_7, emitter.const_s32((int32_t)1ULL), s_b_8_10);
    /* execute.simd:4315 [F] s_b_8_13 = constant s32 2 (const) */
    /* execute.simd:4315 [D] s_b_8_1[s_b_8_13] */
    auto s_b_8_14 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4315 [D] s_b_8_15 = (f32)s_b_8_14 */
    auto s_b_8_15 = emitter.convert(s_b_8_14, emitter.context().types().f32());
    /* execute.simd:4315 [F] s_b_8_16 = constant s32 2 (const) */
    /* execute.simd:4315 [D] s_b_8_17 = s_b_8_12[s_b_8_16] <= s_b_8_15 */
    auto s_b_8_17 = emitter.vector_insert(s_b_8_12, emitter.const_s32((int32_t)2ULL), s_b_8_15);
    /* execute.simd:4316 [F] s_b_8_18 = constant s32 3 (const) */
    /* execute.simd:4316 [D] s_b_8_1[s_b_8_18] */
    auto s_b_8_19 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4316 [D] s_b_8_20 = (f32)s_b_8_19 */
    auto s_b_8_20 = emitter.convert(s_b_8_19, emitter.context().types().f32());
    /* execute.simd:4316 [F] s_b_8_21 = constant s32 3 (const) */
    /* execute.simd:4316 [D] s_b_8_22 = s_b_8_17[s_b_8_21] <= s_b_8_20 */
    auto s_b_8_22 = emitter.vector_insert(s_b_8_17, emitter.const_s32((int32_t)3ULL), s_b_8_20);
    /* execute.simd:4318 [F] s_b_8_23=sym_39549_3_parameter_inst.rd (const) */
    /* execute.simd:4318 [D] s_b_8_24: WriteRegBank 13:s_b_8_23 = s_b_8_22 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_22,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_22);
    /* execute.simd:4310 [F] s_b_8_25: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4319 [F] s_b_9_0=sym_39549_3_parameter_inst.size (const) */
    /* execute.simd:4319 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4319 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4319 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:4319 [F] s_b_9_4=sym_39549_3_parameter_inst.Q (const) */
    /* execute.simd:4319 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4319 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.simd:4319 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.simd:4319 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
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
    /* execute.simd:4320 [F] s_b_10_0=sym_39549_3_parameter_inst.rn (const) */
    /* execute.simd:4320 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_10_2 = constant v2f64 
    {
    }
    (const) */
    /* execute.simd:4323 [F] s_b_10_3 = constant s32 0 (const) */
    /* execute.simd:4323 [D] s_b_10_1[s_b_10_3] */
    auto s_b_10_4 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4323 [D] s_b_10_5 = (f64)s_b_10_4 */
    auto s_b_10_5 = emitter.convert(s_b_10_4, emitter.context().types().f64());
    /* execute.simd:4323 [F] s_b_10_6 = constant s32 0 (const) */
    /* execute.simd:4323 [D] s_b_10_7 = s_b_10_2[s_b_10_6] <= s_b_10_5 */
    auto s_b_10_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<double, 2>(0.000000)[0], emitter.context().types().v2f64()), emitter.const_s32((int32_t)0ULL), s_b_10_5);
    /* execute.simd:4324 [F] s_b_10_8 = constant s32 1 (const) */
    /* execute.simd:4324 [D] s_b_10_1[s_b_10_8] */
    auto s_b_10_9 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4324 [D] s_b_10_10 = (f64)s_b_10_9 */
    auto s_b_10_10 = emitter.convert(s_b_10_9, emitter.context().types().f64());
    /* execute.simd:4324 [F] s_b_10_11 = constant s32 1 (const) */
    /* execute.simd:4324 [D] s_b_10_12 = s_b_10_7[s_b_10_11] <= s_b_10_10 */
    auto s_b_10_12 = emitter.vector_insert(s_b_10_7, emitter.const_s32((int32_t)1ULL), s_b_10_10);
    /* execute.simd:4326 [F] s_b_10_13=sym_39549_3_parameter_inst.rd (const) */
    /* execute.simd:4326 [D] s_b_10_14: WriteRegBank 14:s_b_10_13 = s_b_10_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_12);
    /* execute.simd:4320 [F] s_b_10_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4328 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4328 [F] s_b_11_1: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_umull(const aarch64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5317 [F] s_b_0_0=sym_40067_3_parameter_inst.tb (const) */
    /* execute.simd:5318 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5331 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5344 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5357 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5370 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5383 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5317 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5319 [F] s_b_2_0=sym_40067_3_parameter_inst.rn (const) */
    /* execute.simd:5319 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5320 [F] s_b_2_2=sym_40067_3_parameter_inst.rm (const) */
    /* execute.simd:5320 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_5 = constant u8 0 (const) */
    /* execute.simd:5325 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5325 [D] s_b_2_7 = (u16)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_8 = constant u8 0 (const) */
    /* execute.simd:5325 [D] s_b_2_3[s_b_2_8] */
    auto s_b_2_9 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5325 [D] s_b_2_10 = (u16)s_b_2_9 */
    auto s_b_2_10 = emitter.zx(s_b_2_9, emitter.context().types().u16());
    /* execute.simd:5325 [D] s_b_2_11 = s_b_2_7*s_b_2_10 */
    auto s_b_2_11 = emitter.mul(s_b_2_7, s_b_2_10);
    /* execute.simd:5325 [F] s_b_2_12 = constant s32 0 (const) */
    /* execute.simd:5325 [D] s_b_2_13 = s_b_2_4[s_b_2_12] <= s_b_2_11 */
    auto s_b_2_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_11);
    /* ???:4294967295 [F] s_b_2_14 = constant u8 1 (const) */
    /* execute.simd:5325 [D] s_b_2_1[s_b_2_14] */
    auto s_b_2_15 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5325 [D] s_b_2_16 = (u16)s_b_2_15 */
    auto s_b_2_16 = emitter.zx(s_b_2_15, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_17 = constant u8 1 (const) */
    /* execute.simd:5325 [D] s_b_2_3[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5325 [D] s_b_2_19 = (u16)s_b_2_18 */
    auto s_b_2_19 = emitter.zx(s_b_2_18, emitter.context().types().u16());
    /* execute.simd:5325 [D] s_b_2_20 = s_b_2_16*s_b_2_19 */
    auto s_b_2_20 = emitter.mul(s_b_2_16, s_b_2_19);
    /* execute.simd:5325 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:5325 [D] s_b_2_22 = s_b_2_13[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_13, emitter.const_s32((int32_t)1ULL), s_b_2_20);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 2 (const) */
    /* execute.simd:5325 [D] s_b_2_1[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5325 [D] s_b_2_25 = (u16)s_b_2_24 */
    auto s_b_2_25 = emitter.zx(s_b_2_24, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_26 = constant u8 2 (const) */
    /* execute.simd:5325 [D] s_b_2_3[s_b_2_26] */
    auto s_b_2_27 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5325 [D] s_b_2_28 = (u16)s_b_2_27 */
    auto s_b_2_28 = emitter.zx(s_b_2_27, emitter.context().types().u16());
    /* execute.simd:5325 [D] s_b_2_29 = s_b_2_25*s_b_2_28 */
    auto s_b_2_29 = emitter.mul(s_b_2_25, s_b_2_28);
    /* execute.simd:5325 [F] s_b_2_30 = constant s32 2 (const) */
    /* execute.simd:5325 [D] s_b_2_31 = s_b_2_22[s_b_2_30] <= s_b_2_29 */
    auto s_b_2_31 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)2ULL), s_b_2_29);
    /* ???:4294967295 [F] s_b_2_32 = constant u8 3 (const) */
    /* execute.simd:5325 [D] s_b_2_1[s_b_2_32] */
    auto s_b_2_33 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5325 [D] s_b_2_34 = (u16)s_b_2_33 */
    auto s_b_2_34 = emitter.zx(s_b_2_33, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_35 = constant u8 3 (const) */
    /* execute.simd:5325 [D] s_b_2_3[s_b_2_35] */
    auto s_b_2_36 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5325 [D] s_b_2_37 = (u16)s_b_2_36 */
    auto s_b_2_37 = emitter.zx(s_b_2_36, emitter.context().types().u16());
    /* execute.simd:5325 [D] s_b_2_38 = s_b_2_34*s_b_2_37 */
    auto s_b_2_38 = emitter.mul(s_b_2_34, s_b_2_37);
    /* execute.simd:5325 [F] s_b_2_39 = constant s32 3 (const) */
    /* execute.simd:5325 [D] s_b_2_40 = s_b_2_31[s_b_2_39] <= s_b_2_38 */
    auto s_b_2_40 = emitter.vector_insert(s_b_2_31, emitter.const_s32((int32_t)3ULL), s_b_2_38);
    /* ???:4294967295 [F] s_b_2_41 = constant u8 4 (const) */
    /* execute.simd:5325 [D] s_b_2_1[s_b_2_41] */
    auto s_b_2_42 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5325 [D] s_b_2_43 = (u16)s_b_2_42 */
    auto s_b_2_43 = emitter.zx(s_b_2_42, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_44 = constant u8 4 (const) */
    /* execute.simd:5325 [D] s_b_2_3[s_b_2_44] */
    auto s_b_2_45 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5325 [D] s_b_2_46 = (u16)s_b_2_45 */
    auto s_b_2_46 = emitter.zx(s_b_2_45, emitter.context().types().u16());
    /* execute.simd:5325 [D] s_b_2_47 = s_b_2_43*s_b_2_46 */
    auto s_b_2_47 = emitter.mul(s_b_2_43, s_b_2_46);
    /* execute.simd:5325 [F] s_b_2_48 = constant s32 4 (const) */
    /* execute.simd:5325 [D] s_b_2_49 = s_b_2_40[s_b_2_48] <= s_b_2_47 */
    auto s_b_2_49 = emitter.vector_insert(s_b_2_40, emitter.const_s32((int32_t)4ULL), s_b_2_47);
    /* ???:4294967295 [F] s_b_2_50 = constant u8 5 (const) */
    /* execute.simd:5325 [D] s_b_2_1[s_b_2_50] */
    auto s_b_2_51 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5325 [D] s_b_2_52 = (u16)s_b_2_51 */
    auto s_b_2_52 = emitter.zx(s_b_2_51, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_53 = constant u8 5 (const) */
    /* execute.simd:5325 [D] s_b_2_3[s_b_2_53] */
    auto s_b_2_54 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5325 [D] s_b_2_55 = (u16)s_b_2_54 */
    auto s_b_2_55 = emitter.zx(s_b_2_54, emitter.context().types().u16());
    /* execute.simd:5325 [D] s_b_2_56 = s_b_2_52*s_b_2_55 */
    auto s_b_2_56 = emitter.mul(s_b_2_52, s_b_2_55);
    /* execute.simd:5325 [F] s_b_2_57 = constant s32 5 (const) */
    /* execute.simd:5325 [D] s_b_2_58 = s_b_2_49[s_b_2_57] <= s_b_2_56 */
    auto s_b_2_58 = emitter.vector_insert(s_b_2_49, emitter.const_s32((int32_t)5ULL), s_b_2_56);
    /* ???:4294967295 [F] s_b_2_59 = constant u8 6 (const) */
    /* execute.simd:5325 [D] s_b_2_1[s_b_2_59] */
    auto s_b_2_60 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5325 [D] s_b_2_61 = (u16)s_b_2_60 */
    auto s_b_2_61 = emitter.zx(s_b_2_60, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_62 = constant u8 6 (const) */
    /* execute.simd:5325 [D] s_b_2_3[s_b_2_62] */
    auto s_b_2_63 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5325 [D] s_b_2_64 = (u16)s_b_2_63 */
    auto s_b_2_64 = emitter.zx(s_b_2_63, emitter.context().types().u16());
    /* execute.simd:5325 [D] s_b_2_65 = s_b_2_61*s_b_2_64 */
    auto s_b_2_65 = emitter.mul(s_b_2_61, s_b_2_64);
    /* execute.simd:5325 [F] s_b_2_66 = constant s32 6 (const) */
    /* execute.simd:5325 [D] s_b_2_67 = s_b_2_58[s_b_2_66] <= s_b_2_65 */
    auto s_b_2_67 = emitter.vector_insert(s_b_2_58, emitter.const_s32((int32_t)6ULL), s_b_2_65);
    /* ???:4294967295 [F] s_b_2_68 = constant u8 7 (const) */
    /* execute.simd:5325 [D] s_b_2_1[s_b_2_68] */
    auto s_b_2_69 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5325 [D] s_b_2_70 = (u16)s_b_2_69 */
    auto s_b_2_70 = emitter.zx(s_b_2_69, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_71 = constant u8 7 (const) */
    /* execute.simd:5325 [D] s_b_2_3[s_b_2_71] */
    auto s_b_2_72 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5325 [D] s_b_2_73 = (u16)s_b_2_72 */
    auto s_b_2_73 = emitter.zx(s_b_2_72, emitter.context().types().u16());
    /* execute.simd:5325 [D] s_b_2_74 = s_b_2_70*s_b_2_73 */
    auto s_b_2_74 = emitter.mul(s_b_2_70, s_b_2_73);
    /* execute.simd:5325 [F] s_b_2_75 = constant s32 7 (const) */
    /* execute.simd:5325 [D] s_b_2_76 = s_b_2_67[s_b_2_75] <= s_b_2_74 */
    auto s_b_2_76 = emitter.vector_insert(s_b_2_67, emitter.const_s32((int32_t)7ULL), s_b_2_74);
    /* execute.simd:5328 [F] s_b_2_77=sym_40067_3_parameter_inst.rd (const) */
    /* execute.simd:5328 [D] s_b_2_78: WriteRegBank 18:s_b_2_77 = s_b_2_76 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_76,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_76);
    /* execute.simd:0 [F] s_b_2_79: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5332 [F] s_b_3_0=sym_40067_3_parameter_inst.rn (const) */
    /* execute.simd:5332 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5333 [F] s_b_3_2=sym_40067_3_parameter_inst.rm (const) */
    /* execute.simd:5333 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5338 [F] s_b_3_5 = constant u32 8 (const) */
    /* execute.simd:5338 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5338 [D] s_b_3_7 = (u16)s_b_3_6 */
    auto s_b_3_7 = emitter.zx(s_b_3_6, emitter.context().types().u16());
    /* execute.simd:5338 [F] s_b_3_8 = constant u32 8 (const) */
    /* execute.simd:5338 [D] s_b_3_3[s_b_3_8] */
    auto s_b_3_9 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5338 [D] s_b_3_10 = (u16)s_b_3_9 */
    auto s_b_3_10 = emitter.zx(s_b_3_9, emitter.context().types().u16());
    /* execute.simd:5338 [D] s_b_3_11 = s_b_3_7*s_b_3_10 */
    auto s_b_3_11 = emitter.mul(s_b_3_7, s_b_3_10);
    /* execute.simd:5338 [F] s_b_3_12 = constant s32 0 (const) */
    /* execute.simd:5338 [D] s_b_3_13 = s_b_3_4[s_b_3_12] <= s_b_3_11 */
    auto s_b_3_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_11);
    /* execute.simd:5338 [F] s_b_3_14 = constant u32 9 (const) */
    /* execute.simd:5338 [D] s_b_3_1[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5338 [D] s_b_3_16 = (u16)s_b_3_15 */
    auto s_b_3_16 = emitter.zx(s_b_3_15, emitter.context().types().u16());
    /* execute.simd:5338 [F] s_b_3_17 = constant u32 9 (const) */
    /* execute.simd:5338 [D] s_b_3_3[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5338 [D] s_b_3_19 = (u16)s_b_3_18 */
    auto s_b_3_19 = emitter.zx(s_b_3_18, emitter.context().types().u16());
    /* execute.simd:5338 [D] s_b_3_20 = s_b_3_16*s_b_3_19 */
    auto s_b_3_20 = emitter.mul(s_b_3_16, s_b_3_19);
    /* execute.simd:5338 [F] s_b_3_21 = constant s32 1 (const) */
    /* execute.simd:5338 [D] s_b_3_22 = s_b_3_13[s_b_3_21] <= s_b_3_20 */
    auto s_b_3_22 = emitter.vector_insert(s_b_3_13, emitter.const_s32((int32_t)1ULL), s_b_3_20);
    /* execute.simd:5338 [F] s_b_3_23 = constant u32 a (const) */
    /* execute.simd:5338 [D] s_b_3_1[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5338 [D] s_b_3_25 = (u16)s_b_3_24 */
    auto s_b_3_25 = emitter.zx(s_b_3_24, emitter.context().types().u16());
    /* execute.simd:5338 [F] s_b_3_26 = constant u32 a (const) */
    /* execute.simd:5338 [D] s_b_3_3[s_b_3_26] */
    auto s_b_3_27 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5338 [D] s_b_3_28 = (u16)s_b_3_27 */
    auto s_b_3_28 = emitter.zx(s_b_3_27, emitter.context().types().u16());
    /* execute.simd:5338 [D] s_b_3_29 = s_b_3_25*s_b_3_28 */
    auto s_b_3_29 = emitter.mul(s_b_3_25, s_b_3_28);
    /* execute.simd:5338 [F] s_b_3_30 = constant s32 2 (const) */
    /* execute.simd:5338 [D] s_b_3_31 = s_b_3_22[s_b_3_30] <= s_b_3_29 */
    auto s_b_3_31 = emitter.vector_insert(s_b_3_22, emitter.const_s32((int32_t)2ULL), s_b_3_29);
    /* execute.simd:5338 [F] s_b_3_32 = constant u32 b (const) */
    /* execute.simd:5338 [D] s_b_3_1[s_b_3_32] */
    auto s_b_3_33 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5338 [D] s_b_3_34 = (u16)s_b_3_33 */
    auto s_b_3_34 = emitter.zx(s_b_3_33, emitter.context().types().u16());
    /* execute.simd:5338 [F] s_b_3_35 = constant u32 b (const) */
    /* execute.simd:5338 [D] s_b_3_3[s_b_3_35] */
    auto s_b_3_36 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5338 [D] s_b_3_37 = (u16)s_b_3_36 */
    auto s_b_3_37 = emitter.zx(s_b_3_36, emitter.context().types().u16());
    /* execute.simd:5338 [D] s_b_3_38 = s_b_3_34*s_b_3_37 */
    auto s_b_3_38 = emitter.mul(s_b_3_34, s_b_3_37);
    /* execute.simd:5338 [F] s_b_3_39 = constant s32 3 (const) */
    /* execute.simd:5338 [D] s_b_3_40 = s_b_3_31[s_b_3_39] <= s_b_3_38 */
    auto s_b_3_40 = emitter.vector_insert(s_b_3_31, emitter.const_s32((int32_t)3ULL), s_b_3_38);
    /* execute.simd:5338 [F] s_b_3_41 = constant u32 c (const) */
    /* execute.simd:5338 [D] s_b_3_1[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5338 [D] s_b_3_43 = (u16)s_b_3_42 */
    auto s_b_3_43 = emitter.zx(s_b_3_42, emitter.context().types().u16());
    /* execute.simd:5338 [F] s_b_3_44 = constant u32 c (const) */
    /* execute.simd:5338 [D] s_b_3_3[s_b_3_44] */
    auto s_b_3_45 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5338 [D] s_b_3_46 = (u16)s_b_3_45 */
    auto s_b_3_46 = emitter.zx(s_b_3_45, emitter.context().types().u16());
    /* execute.simd:5338 [D] s_b_3_47 = s_b_3_43*s_b_3_46 */
    auto s_b_3_47 = emitter.mul(s_b_3_43, s_b_3_46);
    /* execute.simd:5338 [F] s_b_3_48 = constant s32 4 (const) */
    /* execute.simd:5338 [D] s_b_3_49 = s_b_3_40[s_b_3_48] <= s_b_3_47 */
    auto s_b_3_49 = emitter.vector_insert(s_b_3_40, emitter.const_s32((int32_t)4ULL), s_b_3_47);
    /* execute.simd:5338 [F] s_b_3_50 = constant u32 d (const) */
    /* execute.simd:5338 [D] s_b_3_1[s_b_3_50] */
    auto s_b_3_51 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5338 [D] s_b_3_52 = (u16)s_b_3_51 */
    auto s_b_3_52 = emitter.zx(s_b_3_51, emitter.context().types().u16());
    /* execute.simd:5338 [F] s_b_3_53 = constant u32 d (const) */
    /* execute.simd:5338 [D] s_b_3_3[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5338 [D] s_b_3_55 = (u16)s_b_3_54 */
    auto s_b_3_55 = emitter.zx(s_b_3_54, emitter.context().types().u16());
    /* execute.simd:5338 [D] s_b_3_56 = s_b_3_52*s_b_3_55 */
    auto s_b_3_56 = emitter.mul(s_b_3_52, s_b_3_55);
    /* execute.simd:5338 [F] s_b_3_57 = constant s32 5 (const) */
    /* execute.simd:5338 [D] s_b_3_58 = s_b_3_49[s_b_3_57] <= s_b_3_56 */
    auto s_b_3_58 = emitter.vector_insert(s_b_3_49, emitter.const_s32((int32_t)5ULL), s_b_3_56);
    /* execute.simd:5338 [F] s_b_3_59 = constant u32 e (const) */
    /* execute.simd:5338 [D] s_b_3_1[s_b_3_59] */
    auto s_b_3_60 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5338 [D] s_b_3_61 = (u16)s_b_3_60 */
    auto s_b_3_61 = emitter.zx(s_b_3_60, emitter.context().types().u16());
    /* execute.simd:5338 [F] s_b_3_62 = constant u32 e (const) */
    /* execute.simd:5338 [D] s_b_3_3[s_b_3_62] */
    auto s_b_3_63 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5338 [D] s_b_3_64 = (u16)s_b_3_63 */
    auto s_b_3_64 = emitter.zx(s_b_3_63, emitter.context().types().u16());
    /* execute.simd:5338 [D] s_b_3_65 = s_b_3_61*s_b_3_64 */
    auto s_b_3_65 = emitter.mul(s_b_3_61, s_b_3_64);
    /* execute.simd:5338 [F] s_b_3_66 = constant s32 6 (const) */
    /* execute.simd:5338 [D] s_b_3_67 = s_b_3_58[s_b_3_66] <= s_b_3_65 */
    auto s_b_3_67 = emitter.vector_insert(s_b_3_58, emitter.const_s32((int32_t)6ULL), s_b_3_65);
    /* execute.simd:5338 [F] s_b_3_68 = constant u32 f (const) */
    /* execute.simd:5338 [D] s_b_3_1[s_b_3_68] */
    auto s_b_3_69 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5338 [D] s_b_3_70 = (u16)s_b_3_69 */
    auto s_b_3_70 = emitter.zx(s_b_3_69, emitter.context().types().u16());
    /* execute.simd:5338 [F] s_b_3_71 = constant u32 f (const) */
    /* execute.simd:5338 [D] s_b_3_3[s_b_3_71] */
    auto s_b_3_72 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5338 [D] s_b_3_73 = (u16)s_b_3_72 */
    auto s_b_3_73 = emitter.zx(s_b_3_72, emitter.context().types().u16());
    /* execute.simd:5338 [D] s_b_3_74 = s_b_3_70*s_b_3_73 */
    auto s_b_3_74 = emitter.mul(s_b_3_70, s_b_3_73);
    /* execute.simd:5338 [F] s_b_3_75 = constant s32 7 (const) */
    /* execute.simd:5338 [D] s_b_3_76 = s_b_3_67[s_b_3_75] <= s_b_3_74 */
    auto s_b_3_76 = emitter.vector_insert(s_b_3_67, emitter.const_s32((int32_t)7ULL), s_b_3_74);
    /* execute.simd:5341 [F] s_b_3_77=sym_40067_3_parameter_inst.rd (const) */
    /* execute.simd:5341 [D] s_b_3_78: WriteRegBank 18:s_b_3_77 = s_b_3_76 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_76,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_76);
    /* execute.simd:0 [F] s_b_3_79: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5345 [F] s_b_4_0=sym_40067_3_parameter_inst.rn (const) */
    /* execute.simd:5345 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5346 [F] s_b_4_2=sym_40067_3_parameter_inst.rm (const) */
    /* execute.simd:5346 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_5 = constant u8 0 (const) */
    /* execute.simd:5351 [D] s_b_4_1[s_b_4_5] */
    auto s_b_4_6 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5351 [D] s_b_4_7 = (u32)s_b_4_6 */
    auto s_b_4_7 = emitter.zx(s_b_4_6, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_8 = constant u8 0 (const) */
    /* execute.simd:5351 [D] s_b_4_3[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5351 [D] s_b_4_10 = (u32)s_b_4_9 */
    auto s_b_4_10 = emitter.zx(s_b_4_9, emitter.context().types().u32());
    /* execute.simd:5351 [D] s_b_4_11 = s_b_4_7*s_b_4_10 */
    auto s_b_4_11 = emitter.mul(s_b_4_7, s_b_4_10);
    /* execute.simd:5351 [F] s_b_4_12 = constant s32 0 (const) */
    /* execute.simd:5351 [D] s_b_4_13 = s_b_4_4[s_b_4_12] <= s_b_4_11 */
    auto s_b_4_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_4_11);
    /* ???:4294967295 [F] s_b_4_14 = constant u8 1 (const) */
    /* execute.simd:5351 [D] s_b_4_1[s_b_4_14] */
    auto s_b_4_15 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5351 [D] s_b_4_16 = (u32)s_b_4_15 */
    auto s_b_4_16 = emitter.zx(s_b_4_15, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_17 = constant u8 1 (const) */
    /* execute.simd:5351 [D] s_b_4_3[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5351 [D] s_b_4_19 = (u32)s_b_4_18 */
    auto s_b_4_19 = emitter.zx(s_b_4_18, emitter.context().types().u32());
    /* execute.simd:5351 [D] s_b_4_20 = s_b_4_16*s_b_4_19 */
    auto s_b_4_20 = emitter.mul(s_b_4_16, s_b_4_19);
    /* execute.simd:5351 [F] s_b_4_21 = constant s32 1 (const) */
    /* execute.simd:5351 [D] s_b_4_22 = s_b_4_13[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_13, emitter.const_s32((int32_t)1ULL), s_b_4_20);
    /* ???:4294967295 [F] s_b_4_23 = constant u8 2 (const) */
    /* execute.simd:5351 [D] s_b_4_1[s_b_4_23] */
    auto s_b_4_24 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5351 [D] s_b_4_25 = (u32)s_b_4_24 */
    auto s_b_4_25 = emitter.zx(s_b_4_24, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_26 = constant u8 2 (const) */
    /* execute.simd:5351 [D] s_b_4_3[s_b_4_26] */
    auto s_b_4_27 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5351 [D] s_b_4_28 = (u32)s_b_4_27 */
    auto s_b_4_28 = emitter.zx(s_b_4_27, emitter.context().types().u32());
    /* execute.simd:5351 [D] s_b_4_29 = s_b_4_25*s_b_4_28 */
    auto s_b_4_29 = emitter.mul(s_b_4_25, s_b_4_28);
    /* execute.simd:5351 [F] s_b_4_30 = constant s32 2 (const) */
    /* execute.simd:5351 [D] s_b_4_31 = s_b_4_22[s_b_4_30] <= s_b_4_29 */
    auto s_b_4_31 = emitter.vector_insert(s_b_4_22, emitter.const_s32((int32_t)2ULL), s_b_4_29);
    /* ???:4294967295 [F] s_b_4_32 = constant u8 3 (const) */
    /* execute.simd:5351 [D] s_b_4_1[s_b_4_32] */
    auto s_b_4_33 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5351 [D] s_b_4_34 = (u32)s_b_4_33 */
    auto s_b_4_34 = emitter.zx(s_b_4_33, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_35 = constant u8 3 (const) */
    /* execute.simd:5351 [D] s_b_4_3[s_b_4_35] */
    auto s_b_4_36 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5351 [D] s_b_4_37 = (u32)s_b_4_36 */
    auto s_b_4_37 = emitter.zx(s_b_4_36, emitter.context().types().u32());
    /* execute.simd:5351 [D] s_b_4_38 = s_b_4_34*s_b_4_37 */
    auto s_b_4_38 = emitter.mul(s_b_4_34, s_b_4_37);
    /* execute.simd:5351 [F] s_b_4_39 = constant s32 3 (const) */
    /* execute.simd:5351 [D] s_b_4_40 = s_b_4_31[s_b_4_39] <= s_b_4_38 */
    auto s_b_4_40 = emitter.vector_insert(s_b_4_31, emitter.const_s32((int32_t)3ULL), s_b_4_38);
    /* execute.simd:5354 [F] s_b_4_41=sym_40067_3_parameter_inst.rd (const) */
    /* execute.simd:5354 [D] s_b_4_42: WriteRegBank 20:s_b_4_41 = s_b_4_40 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_40,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_40);
    /* execute.simd:0 [F] s_b_4_43: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5358 [F] s_b_5_0=sym_40067_3_parameter_inst.rn (const) */
    /* execute.simd:5358 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5359 [F] s_b_5_2=sym_40067_3_parameter_inst.rm (const) */
    /* execute.simd:5359 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5364 [F] s_b_5_5 = constant u32 4 (const) */
    /* execute.simd:5364 [D] s_b_5_1[s_b_5_5] */
    auto s_b_5_6 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5364 [D] s_b_5_7 = (u32)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u32());
    /* execute.simd:5364 [F] s_b_5_8 = constant u32 4 (const) */
    /* execute.simd:5364 [D] s_b_5_3[s_b_5_8] */
    auto s_b_5_9 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5364 [D] s_b_5_10 = (u32)s_b_5_9 */
    auto s_b_5_10 = emitter.zx(s_b_5_9, emitter.context().types().u32());
    /* execute.simd:5364 [D] s_b_5_11 = s_b_5_7*s_b_5_10 */
    auto s_b_5_11 = emitter.mul(s_b_5_7, s_b_5_10);
    /* execute.simd:5364 [F] s_b_5_12 = constant s32 0 (const) */
    /* execute.simd:5364 [D] s_b_5_13 = s_b_5_4[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_5_11);
    /* execute.simd:5364 [F] s_b_5_14 = constant u32 5 (const) */
    /* execute.simd:5364 [D] s_b_5_1[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5364 [D] s_b_5_16 = (u32)s_b_5_15 */
    auto s_b_5_16 = emitter.zx(s_b_5_15, emitter.context().types().u32());
    /* execute.simd:5364 [F] s_b_5_17 = constant u32 5 (const) */
    /* execute.simd:5364 [D] s_b_5_3[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5364 [D] s_b_5_19 = (u32)s_b_5_18 */
    auto s_b_5_19 = emitter.zx(s_b_5_18, emitter.context().types().u32());
    /* execute.simd:5364 [D] s_b_5_20 = s_b_5_16*s_b_5_19 */
    auto s_b_5_20 = emitter.mul(s_b_5_16, s_b_5_19);
    /* execute.simd:5364 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5364 [D] s_b_5_22 = s_b_5_13[s_b_5_21] <= s_b_5_20 */
    auto s_b_5_22 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)1ULL), s_b_5_20);
    /* execute.simd:5364 [F] s_b_5_23 = constant u32 6 (const) */
    /* execute.simd:5364 [D] s_b_5_1[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5364 [D] s_b_5_25 = (u32)s_b_5_24 */
    auto s_b_5_25 = emitter.zx(s_b_5_24, emitter.context().types().u32());
    /* execute.simd:5364 [F] s_b_5_26 = constant u32 6 (const) */
    /* execute.simd:5364 [D] s_b_5_3[s_b_5_26] */
    auto s_b_5_27 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5364 [D] s_b_5_28 = (u32)s_b_5_27 */
    auto s_b_5_28 = emitter.zx(s_b_5_27, emitter.context().types().u32());
    /* execute.simd:5364 [D] s_b_5_29 = s_b_5_25*s_b_5_28 */
    auto s_b_5_29 = emitter.mul(s_b_5_25, s_b_5_28);
    /* execute.simd:5364 [F] s_b_5_30 = constant s32 2 (const) */
    /* execute.simd:5364 [D] s_b_5_31 = s_b_5_22[s_b_5_30] <= s_b_5_29 */
    auto s_b_5_31 = emitter.vector_insert(s_b_5_22, emitter.const_s32((int32_t)2ULL), s_b_5_29);
    /* execute.simd:5364 [F] s_b_5_32 = constant u32 7 (const) */
    /* execute.simd:5364 [D] s_b_5_1[s_b_5_32] */
    auto s_b_5_33 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5364 [D] s_b_5_34 = (u32)s_b_5_33 */
    auto s_b_5_34 = emitter.zx(s_b_5_33, emitter.context().types().u32());
    /* execute.simd:5364 [F] s_b_5_35 = constant u32 7 (const) */
    /* execute.simd:5364 [D] s_b_5_3[s_b_5_35] */
    auto s_b_5_36 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5364 [D] s_b_5_37 = (u32)s_b_5_36 */
    auto s_b_5_37 = emitter.zx(s_b_5_36, emitter.context().types().u32());
    /* execute.simd:5364 [D] s_b_5_38 = s_b_5_34*s_b_5_37 */
    auto s_b_5_38 = emitter.mul(s_b_5_34, s_b_5_37);
    /* execute.simd:5364 [F] s_b_5_39 = constant s32 3 (const) */
    /* execute.simd:5364 [D] s_b_5_40 = s_b_5_31[s_b_5_39] <= s_b_5_38 */
    auto s_b_5_40 = emitter.vector_insert(s_b_5_31, emitter.const_s32((int32_t)3ULL), s_b_5_38);
    /* execute.simd:5367 [F] s_b_5_41=sym_40067_3_parameter_inst.rd (const) */
    /* execute.simd:5367 [D] s_b_5_42: WriteRegBank 20:s_b_5_41 = s_b_5_40 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_40,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_40);
    /* execute.simd:0 [F] s_b_5_43: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5371 [F] s_b_6_0=sym_40067_3_parameter_inst.rn (const) */
    /* execute.simd:5371 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5372 [F] s_b_6_2=sym_40067_3_parameter_inst.rm (const) */
    /* execute.simd:5372 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_4 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_5 = constant u8 0 (const) */
    /* execute.simd:5377 [D] s_b_6_1[s_b_6_5] */
    auto s_b_6_6 = emitter.vector_extract(s_b_6_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5377 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_8 = constant u8 0 (const) */
    /* execute.simd:5377 [D] s_b_6_3[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5377 [D] s_b_6_10 = (u64)s_b_6_9 */
    auto s_b_6_10 = emitter.zx(s_b_6_9, emitter.context().types().u64());
    /* execute.simd:5377 [D] s_b_6_11 = s_b_6_7*s_b_6_10 */
    auto s_b_6_11 = emitter.mul(s_b_6_7, s_b_6_10);
    /* execute.simd:5377 [F] s_b_6_12 = constant s32 0 (const) */
    /* execute.simd:5377 [D] s_b_6_13 = s_b_6_4[s_b_6_12] <= s_b_6_11 */
    auto s_b_6_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_6_11);
    /* ???:4294967295 [F] s_b_6_14 = constant u8 1 (const) */
    /* execute.simd:5377 [D] s_b_6_1[s_b_6_14] */
    auto s_b_6_15 = emitter.vector_extract(s_b_6_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5377 [D] s_b_6_16 = (u64)s_b_6_15 */
    auto s_b_6_16 = emitter.zx(s_b_6_15, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_17 = constant u8 1 (const) */
    /* execute.simd:5377 [D] s_b_6_3[s_b_6_17] */
    auto s_b_6_18 = emitter.vector_extract(s_b_6_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5377 [D] s_b_6_19 = (u64)s_b_6_18 */
    auto s_b_6_19 = emitter.zx(s_b_6_18, emitter.context().types().u64());
    /* execute.simd:5377 [D] s_b_6_20 = s_b_6_16*s_b_6_19 */
    auto s_b_6_20 = emitter.mul(s_b_6_16, s_b_6_19);
    /* execute.simd:5377 [F] s_b_6_21 = constant s32 1 (const) */
    /* execute.simd:5377 [D] s_b_6_22 = s_b_6_13[s_b_6_21] <= s_b_6_20 */
    auto s_b_6_22 = emitter.vector_insert(s_b_6_13, emitter.const_s32((int32_t)1ULL), s_b_6_20);
    /* execute.simd:5380 [F] s_b_6_23=sym_40067_3_parameter_inst.rd (const) */
    /* execute.simd:5380 [D] s_b_6_24: WriteRegBank 21:s_b_6_23 = s_b_6_22 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_22,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_22);
    /* execute.simd:0 [F] s_b_6_25: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:5384 [F] s_b_7_0=sym_40067_3_parameter_inst.rn (const) */
    /* execute.simd:5384 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5385 [F] s_b_7_2=sym_40067_3_parameter_inst.rm (const) */
    /* execute.simd:5385 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_4 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5390 [F] s_b_7_5 = constant u32 2 (const) */
    /* execute.simd:5390 [D] s_b_7_1[s_b_7_5] */
    auto s_b_7_6 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5390 [D] s_b_7_7 = (u64)s_b_7_6 */
    auto s_b_7_7 = emitter.zx(s_b_7_6, emitter.context().types().u64());
    /* execute.simd:5390 [F] s_b_7_8 = constant u32 2 (const) */
    /* execute.simd:5390 [D] s_b_7_3[s_b_7_8] */
    auto s_b_7_9 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5390 [D] s_b_7_10 = (u64)s_b_7_9 */
    auto s_b_7_10 = emitter.zx(s_b_7_9, emitter.context().types().u64());
    /* execute.simd:5390 [D] s_b_7_11 = s_b_7_7*s_b_7_10 */
    auto s_b_7_11 = emitter.mul(s_b_7_7, s_b_7_10);
    /* execute.simd:5390 [F] s_b_7_12 = constant s32 0 (const) */
    /* execute.simd:5390 [D] s_b_7_13 = s_b_7_4[s_b_7_12] <= s_b_7_11 */
    auto s_b_7_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_7_11);
    /* execute.simd:5390 [F] s_b_7_14 = constant u32 3 (const) */
    /* execute.simd:5390 [D] s_b_7_1[s_b_7_14] */
    auto s_b_7_15 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5390 [D] s_b_7_16 = (u64)s_b_7_15 */
    auto s_b_7_16 = emitter.zx(s_b_7_15, emitter.context().types().u64());
    /* execute.simd:5390 [F] s_b_7_17 = constant u32 3 (const) */
    /* execute.simd:5390 [D] s_b_7_3[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5390 [D] s_b_7_19 = (u64)s_b_7_18 */
    auto s_b_7_19 = emitter.zx(s_b_7_18, emitter.context().types().u64());
    /* execute.simd:5390 [D] s_b_7_20 = s_b_7_16*s_b_7_19 */
    auto s_b_7_20 = emitter.mul(s_b_7_16, s_b_7_19);
    /* execute.simd:5390 [F] s_b_7_21 = constant s32 1 (const) */
    /* execute.simd:5390 [D] s_b_7_22 = s_b_7_13[s_b_7_21] <= s_b_7_20 */
    auto s_b_7_22 = emitter.vector_insert(s_b_7_13, emitter.const_s32((int32_t)1ULL), s_b_7_20);
    /* execute.simd:5393 [F] s_b_7_23=sym_40067_3_parameter_inst.rd (const) */
    /* execute.simd:5393 [D] s_b_7_24: WriteRegBank 21:s_b_7_23 = s_b_7_22 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_22,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_22);
    /* execute.simd:0 [F] s_b_7_25: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:5397 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5317 [F] s_b_8_1: Jump b_1 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_vldr(const aarch64_decode_a64_LS_REG_UIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_150758_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_150737_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_150748_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_150714_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_150712_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_150762_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_150726_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_150621_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_150638_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3892 [F] s_b_0_0=sym_46417_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2701 [F] s_b_1_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_1_1 = __builtin_get_feature */
    uint32_t s_b_1_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(s_b_1_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2733 [F] s_b_2_0=sym_46417_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_150621_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_150621_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_150621_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_150621_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:3892 [F] s_b_3_1=sym_46417_3_parameter_inst.immu64 (const) */
    /* execute.simd:3892 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:3893 [F] s_b_3_3=sym_46417_3_parameter_inst.size (const) */
    /* execute.simd:3893 [F] s_b_3_4 = (u32)s_b_3_3 (const) */
    /* execute.simd:3893 [F] s_b_3_5 = constant u32 0 (const) */
    /* execute.simd:3893 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:3893 [F] s_b_3_7=sym_46417_3_parameter_inst.opc (const) */
    /* execute.simd:3893 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
    /* execute.simd:3893 [F] s_b_3_9 = constant u32 1 (const) */
    /* execute.simd:3893 [F] s_b_3_10 = s_b_3_8==s_b_3_9 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.simd:3893 [F] s_b_3_11 = constant u8 0 (const) */
    /* execute.simd:3893 [F] s_b_3_12 = constant u8 4 (const) */
    /* execute.simd:3893 [F] s_b_3_13: Select s_b_3_10 ? s_b_3_11 : s_b_3_12 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(s_b_3_10 ? ((uint8_t)0ULL) : ((uint8_t)4ULL)));
    /* execute.simd:3893 [F] s_b_3_14=sym_46417_3_parameter_inst.size (const) */
    /* execute.simd:3893 [F] s_b_3_15 = (u8)s_b_3_14 (const) */
    /* execute.simd:3893 [F] s_b_3_16: Select s_b_3_6 ? s_b_3_13 : s_b_3_15 (const) */
    uint8_t s_b_3_16 = ((uint8_t)(s_b_3_6 ? (s_b_3_13) : (((uint8_t)insn.size))));
    /* ???:4294967295 [D] s_b_3_17: sym_150712_0_replaced_parameter_addr = s_b_3_2, dominates: s_b_12_0 s_b_11_0 s_b_9_0 s_b_10_0 s_b_13_0  */
    emitter.store_local(DV_sym_150712_0_replaced_parameter_addr, s_b_3_2);
    /* execute.simd:3673 [F] s_b_3_18 = constant s32 0 (const) */
    /* execute.simd:3680 [F] s_b_3_19 = constant s32 1 (const) */
    /* execute.simd:3687 [F] s_b_3_20 = constant s32 2 (const) */
    /* execute.simd:3694 [F] s_b_3_21 = constant s32 3 (const) */
    /* execute.simd:3701 [F] s_b_3_22 = constant s32 4 (const) */
    /* execute.simd:3672 [F] s_b_3_23: Switch s_b_3_16: < <todo> > def b_14 (const) -> b_12, b_11, b_9, b_10, b_13, b_14,  */
    switch (s_b_3_16) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_13;
      break;
    default:
      goto fixed_block_b_14;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2702 [D] s_b_4_0 = ReadReg 20 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_4_1: sym_150638_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_150638_1__R_s_b_3_0, s_b_4_0);
    /* execute.a64:2702 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:3012 [F] s_b_5_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_5_1 = __builtin_get_feature */
    uint32_t s_b_5_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_5_2 = (u8)s_b_5_1 (const) */
    /* execute.a64:2704 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:2704 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_5_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_5_6: If s_b_5_5: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2731 [D] s_b_6_0 = sym_150638_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_150638_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_150621_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_150621_0_return_symbol, s_b_6_0);
    /* ???:4294967295 [F] s_b_6_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2705 [D] s_b_7_0 = ReadReg 20 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_7_1: sym_150638_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_150638_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2705 [F] s_b_7_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2707 [D] s_b_8_0 = ReadReg 21 (u64) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_8_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_8_1: sym_150638_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_150638_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2707 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3676 [D] s_b_9_0 = sym_150712_0_replaced_parameter_addr uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_150712_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1 = Load 1 s_b_9_0 => sym_150714_0_value */
    auto s_b_9_1 = emitter.load_memory(s_b_9_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_150714_0_value, s_b_9_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_0, s_b_9_1, emitter.const_u8(1));
    }
    /* execute.simd:3677 [F] s_b_9_2=sym_46417_3_parameter_inst.rt (const) */
    /* execute.simd:3677 [D] s_b_9_3 = sym_150714_0_value uint8_t */
    auto s_b_9_3 = emitter.load_local(DV_sym_150714_0_value, emitter.context().types().u8());
    /* execute.simd:6184 [D] s_b_9_4 = (u64)s_b_9_3 */
    auto s_b_9_4 = emitter.zx(s_b_9_3, emitter.context().types().u64());
    /* execute.simd:6184 [D] s_b_9_5: WriteRegBank 2:s_b_9_2 = s_b_9_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_4);
    /* execute.simd:6185 [F] s_b_9_6 = constant u64 0 (const) */
    /* execute.simd:6185 [F] s_b_9_7: WriteRegBank 3:s_b_9_2 = s_b_9_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_9_8: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3683 [D] s_b_10_0 = sym_150712_0_replaced_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_150712_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 2 s_b_10_0 => sym_150726_0_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_150726_0_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(2));
    }
    /* execute.simd:3684 [F] s_b_10_2=sym_46417_3_parameter_inst.rt (const) */
    /* execute.simd:3684 [D] s_b_10_3 = sym_150726_0_value uint16_t */
    auto s_b_10_3 = emitter.load_local(DV_sym_150726_0_value, emitter.context().types().u16());
    /* execute.simd:6191 [D] s_b_10_4 = (u64)s_b_10_3 */
    auto s_b_10_4 = emitter.zx(s_b_10_3, emitter.context().types().u64());
    /* execute.simd:6191 [D] s_b_10_5: WriteRegBank 2:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_4);
    /* execute.simd:6192 [F] s_b_10_6 = constant u64 0 (const) */
    /* execute.simd:6192 [F] s_b_10_7: WriteRegBank 3:s_b_10_2 = s_b_10_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_10_8: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3690 [D] s_b_11_0 = sym_150712_0_replaced_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_150712_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 4 s_b_11_0 => sym_150737_0_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_150737_0_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(4));
    }
    /* execute.simd:3691 [F] s_b_11_2=sym_46417_3_parameter_inst.rt (const) */
    /* execute.simd:3691 [D] s_b_11_3 = sym_150737_0_value uint32_t */
    auto s_b_11_3 = emitter.load_local(DV_sym_150737_0_value, emitter.context().types().u32());
    /* execute.simd:6198 [D] s_b_11_4 = (u64)s_b_11_3 */
    auto s_b_11_4 = emitter.zx(s_b_11_3, emitter.context().types().u64());
    /* execute.simd:6198 [D] s_b_11_5: WriteRegBank 2:s_b_11_2 = s_b_11_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_11_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_11_4);
    /* execute.simd:6199 [F] s_b_11_6 = constant u64 0 (const) */
    /* execute.simd:6199 [F] s_b_11_7: WriteRegBank 3:s_b_11_2 = s_b_11_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_11_8: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3697 [D] s_b_12_0 = sym_150712_0_replaced_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_150712_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 8 s_b_12_0 => sym_150748_0_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_150748_0_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(8));
    }
    /* execute.simd:3698 [F] s_b_12_2=sym_46417_3_parameter_inst.rt (const) */
    /* execute.simd:3698 [D] s_b_12_3 = sym_150748_0_value uint64_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_150748_0_value, emitter.context().types().u64());
    /* execute.simd:6205 [D] s_b_12_4: WriteRegBank 2:s_b_12_2 = s_b_12_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_3);
    /* execute.simd:6206 [F] s_b_12_5 = constant u64 0 (const) */
    /* execute.simd:6206 [F] s_b_12_6: WriteRegBank 3:s_b_12_2 = s_b_12_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_12_7: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3705 [D] s_b_13_0 = sym_150712_0_replaced_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_150712_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 8 s_b_13_0 => sym_150758_0_vl */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_150758_0_vl, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(8));
    }
    /* execute.simd:3706 [F] s_b_13_2 = constant u64 8 (const) */
    /* execute.simd:3706 [D] s_b_13_3 = s_b_13_0+s_b_13_2 */
    auto s_b_13_3 = emitter.add(s_b_13_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_13_4 = Load 8 s_b_13_3 => sym_150762_0_vh */
    auto s_b_13_4 = emitter.load_memory(s_b_13_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_150762_0_vh, s_b_13_4);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_3, s_b_13_4, emitter.const_u8(8));
    }
    /* execute.simd:3707 [F] s_b_13_5=sym_46417_3_parameter_inst.rt (const) */
    /* execute.simd:3707 [D] s_b_13_6 = sym_150758_0_vl uint64_t */
    auto s_b_13_6 = emitter.load_local(DV_sym_150758_0_vl, emitter.context().types().u64());
    /* execute.simd:3707 [D] s_b_13_7 = sym_150762_0_vh uint64_t */
    auto s_b_13_7 = emitter.load_local(DV_sym_150762_0_vh, emitter.context().types().u64());
    /* execute.simd:6212 [D] s_b_13_8: WriteRegBank 2:s_b_13_5 = s_b_13_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_6);
    /* execute.simd:6213 [D] s_b_13_9: WriteRegBank 3:s_b_13_5 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_7);
    /* execute.simd:0 [F] s_b_13_10: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3, b_9, b_10, b_11, b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* ???:4294967295 [F] s_b_14_0: Return */
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
template class aarch64_jit2<true>;
template class aarch64_jit2<false>;
