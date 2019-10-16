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
  uint32_t CV_sym_48705_3_parameter_imm;
  auto DV_sym_48876_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48928_1__R_s_b_30_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_48720_1__R_s_b_0_5;
  auto DV_sym_48737_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48964_1__R_s_b_32_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48779_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_48855_1__R_s_b_11_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48802_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3700_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_3695_0_imm;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:18 [F] s_b_0_0=sym_3689_3_parameter_inst.imm12 (const) */
    /* execute.a64:18 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:18 [F] s_b_0_2=sym_3689_3_parameter_inst.shift (const) */
    /* execute.a64:18 [F] s_b_0_3: sym_48705_3_parameter_imm = s_b_0_1 (const), dominates: s_b_8_0 s_b_7_0  */
    CV_sym_48705_3_parameter_imm = ((uint32_t)insn.imm12);
    /* execute.a64:2762 [F] s_b_0_4 = constant s32 0 (const) */
    /* execute.a64:2765 [F] s_b_0_5 = constant s32 1 (const) */
    /* execute.a64:2761 [F] s_b_0_6: Switch s_b_0_2: < <todo> > def b_6 (const) -> b_8, b_6, b_7,  */
    switch (insn.shift) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_8;
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
    /* execute.a64:28 [D] s_b_3_4: sym_48737_3_parameter_value = s_b_3_3, dominates: s_b_10_0 s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_48737_3_parameter_value, s_b_3_3);
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
    /* execute.a64:23 [D] s_b_4_7: sym_48779_3_parameter_value = s_b_4_6, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_48779_3_parameter_value, s_b_4_6);
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
    /* execute.a64:25 [D] s_b_5_5: sym_48802_3_parameter_value = s_b_5_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_48802_3_parameter_value, s_b_5_4);
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
    /* execute.a64:2769 [F] s_b_6_1: sym_48720_1__R_s_b_0_5 = s_b_6_0 (const), dominates: s_b_9_0  */
    CV_sym_48720_1__R_s_b_0_5 = (uint64_t)0ULL;
    /* execute.a64:2769 [F] s_b_6_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2766 [F] s_b_7_0 = sym_48705_3_parameter_imm (const) uint32_t */
    uint32_t s_b_7_0 = CV_sym_48705_3_parameter_imm;
    /* execute.a64:2766 [F] s_b_7_1 = constant u32 c (const) */
    /* execute.a64:2766 [F] s_b_7_2 = s_b_7_0<<s_b_7_1 (const) */
    uint32_t s_b_7_2 = ((uint32_t)(s_b_7_0 << (uint32_t)12ULL));
    /* execute.a64:2766 [F] s_b_7_3 = (u64)s_b_7_2 (const) */
    /* execute.a64:2766 [F] s_b_7_4: sym_48720_1__R_s_b_0_5 = s_b_7_3 (const), dominates: s_b_9_0  */
    CV_sym_48720_1__R_s_b_0_5 = ((uint64_t)s_b_7_2);
    /* execute.a64:2766 [F] s_b_7_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2763 [F] s_b_8_0 = sym_48705_3_parameter_imm (const) uint32_t */
    uint32_t s_b_8_0 = CV_sym_48705_3_parameter_imm;
    /* execute.a64:2763 [F] s_b_8_1 = (u64)s_b_8_0 (const) */
    /* execute.a64:2763 [F] s_b_8_2: sym_48720_1__R_s_b_0_5 = s_b_8_1 (const), dominates: s_b_9_0  */
    CV_sym_48720_1__R_s_b_0_5 = ((uint64_t)s_b_8_0);
    /* execute.a64:2763 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6, b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:18 [F] s_b_9_0 = sym_48720_1__R_s_b_0_5 (const) uint64_t */
    uint64_t s_b_9_0 = CV_sym_48720_1__R_s_b_0_5;
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
    /* execute.a64:2747 [D] s_b_10_0 = sym_48737_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_48737_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_10_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_10_2 = s_b_10_0&s_b_10_1 */
    auto s_b_10_2 = emitter.bitwise_and(s_b_10_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_10_3: sym_48737_3_parameter_value = s_b_10_2, dominates: s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_48737_3_parameter_value, s_b_10_2);
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
    /* execute.a64:2751 [D] s_b_12_0 = sym_48737_3_parameter_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_48737_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_12_1: sym_48876_3_parameter_value = s_b_12_0, dominates: s_b_21_0 s_b_22_0 s_b_23_0  */
    emitter.store_local(DV_sym_48876_3_parameter_value, s_b_12_0);
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
    /* execute.a64:2753 [D] s_b_13_1 = sym_48737_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_48737_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2676 [D] s_b_14_1 = sym_48779_3_parameter_value uint32_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_48779_3_parameter_value, emitter.context().types().u32());
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
    /* execute.a64:2684 [D] s_b_15_1 = sym_48802_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_48802_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2733 [D] s_b_18_2: sym_48855_1__R_s_b_11_6 = s_b_18_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_48855_1__R_s_b_11_6, s_b_18_1);
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
    /* execute.a64:2739 [D] s_b_19_3: sym_48855_1__R_s_b_11_6 = s_b_19_2, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_48855_1__R_s_b_11_6, s_b_19_2);
    /* execute.a64:2739 [F] s_b_19_4: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_18, b_19, b_28, b_33,  */
  fixed_block_b_20: 
  {
    /* execute.a64:19 [D] s_b_20_0 = sym_48855_1__R_s_b_11_6 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_48855_1__R_s_b_11_6, emitter.context().types().u64());
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
    /* execute.a64:2715 [D] s_b_21_0 = sym_48876_3_parameter_value uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_48876_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2718 [D] s_b_22_0 = sym_48876_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_48876_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2720 [D] s_b_23_0 = sym_48876_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_48876_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2702 [D] s_b_25_1: sym_48928_1__R_s_b_30_0 = s_b_25_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_48928_1__R_s_b_30_0, s_b_25_0);
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
    /* execute.a64:2705 [D] s_b_26_1: sym_48928_1__R_s_b_30_0 = s_b_26_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_48928_1__R_s_b_30_0, s_b_26_0);
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
    /* execute.a64:2707 [D] s_b_27_1: sym_48928_1__R_s_b_30_0 = s_b_27_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_48928_1__R_s_b_30_0, s_b_27_0);
    /* execute.a64:2707 [F] s_b_27_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_25, b_26, b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2731 [D] s_b_28_0 = sym_48928_1__R_s_b_30_0 uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_48928_1__R_s_b_30_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_28_1: sym_48855_1__R_s_b_11_6 = s_b_28_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_48855_1__R_s_b_11_6, s_b_28_0);
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
    /* execute.a64:2702 [D] s_b_30_1: sym_48964_1__R_s_b_32_0 = s_b_30_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_48964_1__R_s_b_32_0, s_b_30_0);
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
    /* execute.a64:2705 [D] s_b_31_1: sym_48964_1__R_s_b_32_0 = s_b_31_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_48964_1__R_s_b_32_0, s_b_31_0);
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
    /* execute.a64:2707 [D] s_b_32_1: sym_48964_1__R_s_b_32_0 = s_b_32_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_48964_1__R_s_b_32_0, s_b_32_0);
    /* execute.a64:2707 [F] s_b_32_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_30, b_31, b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2737 [D] s_b_33_0 = sym_48964_1__R_s_b_32_0 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_48964_1__R_s_b_32_0, emitter.context().types().u64());
    /* execute.a64:2737 [D] s_b_33_1 = (u32)s_b_33_0 */
    auto s_b_33_1 = emitter.truncate(s_b_33_0, emitter.context().types().u32());
    /* execute.a64:2737 [D] s_b_33_2 = (u64)s_b_33_1 */
    auto s_b_33_2 = emitter.zx(s_b_33_1, emitter.context().types().u64());
    /* execute.a64:2737 [D] s_b_33_3: sym_48855_1__R_s_b_11_6 = s_b_33_2, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_48855_1__R_s_b_11_6, s_b_33_2);
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
  auto DV_sym_50966_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_5984_0_amount = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_50835_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50876_1__R_s_b_2_6 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_50936_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50988_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
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
    /* execute.a64:2657 [D] s_b_4_7: sym_50835_1__R_s_b_0_4 = s_b_4_6, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_50835_1__R_s_b_0_4, s_b_4_6);
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
    /* execute.a64:2659 [D] s_b_5_8: sym_50835_1__R_s_b_0_4 = s_b_5_7, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_50835_1__R_s_b_0_4, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2305 [D] s_b_6_0 = sym_50835_1__R_s_b_0_4 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_50835_1__R_s_b_0_4, emitter.context().types().u64());
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
    /* execute.a64:2666 [D] s_b_7_9: sym_50876_1__R_s_b_2_6 = s_b_7_8, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_50876_1__R_s_b_2_6, s_b_7_8);
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
    /* execute.a64:2668 [D] s_b_8_10: sym_50876_1__R_s_b_2_6 = s_b_8_9, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_50876_1__R_s_b_2_6, s_b_8_9);
    /* execute.a64:2668 [F] s_b_8_11: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [F] s_b_9_0=sym_5979_3_parameter_inst.sf (const) */
    /* execute.a64:2312 [D] s_b_9_1 = sym_50876_1__R_s_b_2_6 int64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_50876_1__R_s_b_2_6, emitter.context().types().s64());
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
    /* execute.a64:2312 [D] s_b_9_8: sym_50936_3_parameter_value = s_b_9_7, dominates: s_b_10_1 s_b_11_1  */
    emitter.store_local(DV_sym_50936_3_parameter_value, s_b_9_7);
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
    /* execute.a64:2691 [D] s_b_10_1 = sym_50936_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_50936_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_10_2: sym_50966_3_parameter_value = s_b_10_1, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_50966_3_parameter_value, s_b_10_1);
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
    /* execute.a64:2693 [D] s_b_11_1 = sym_50936_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_50936_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_2 = (u32)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_4: sym_50988_3_parameter_value = s_b_11_3, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_50988_3_parameter_value, s_b_11_3);
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
    /* execute.a64:2684 [D] s_b_13_1 = sym_50966_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_50966_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [D] s_b_14_1 = sym_50988_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_50988_3_parameter_value, emitter.context().types().u64());
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
    /* execute.simd:2388 [F] s_b_0_0=sym_6286_3_parameter_inst.Q (const) */
    /* execute.simd:2388 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2396 [F] s_b_1_0=sym_6286_3_parameter_inst.rd (const) */
    /* execute.simd:6280 [D] s_b_1_1 = ReadRegBank 2:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:6281 [D] s_b_1_2 = ReadRegBank 3:s_b_1_0 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:2397 [F] s_b_1_3=sym_6286_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_1_4 = ReadRegBank 2:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:6281 [D] s_b_1_5 = ReadRegBank 3:s_b_1_3 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.simd:2398 [F] s_b_1_6=sym_6286_3_parameter_inst.rm (const) */
    /* execute.simd:6280 [D] s_b_1_7 = ReadRegBank 2:s_b_1_6 (u64) */
    auto s_b_1_7 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_7,emitter.const_u8(8));
    }
    /* execute.simd:6281 [D] s_b_1_8 = ReadRegBank 3:s_b_1_6 (u64) */
    auto s_b_1_8 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_1_8,emitter.const_u8(8));
    }
    /* execute.simd:2400 [F] s_b_1_9=sym_6286_3_parameter_inst.rd (const) */
    /* execute.simd:2400 [D] s_b_1_10 = s_b_1_1^s_b_1_4 */
    auto s_b_1_10 = emitter.bitwise_xor(s_b_1_1, s_b_1_4);
    /* execute.simd:2400 [D] s_b_1_11 = ~s_b_1_7 */
    auto s_b_1_11 = emitter.bitwise_not(s_b_1_7);
    /* execute.simd:2400 [D] s_b_1_12 = s_b_1_10&s_b_1_11 */
    auto s_b_1_12 = emitter.bitwise_and(s_b_1_10, s_b_1_11);
    /* execute.simd:2400 [D] s_b_1_13 = s_b_1_1^s_b_1_12 */
    auto s_b_1_13 = emitter.bitwise_xor(s_b_1_1, s_b_1_12);
    /* execute.simd:2400 [D] s_b_1_14 = s_b_1_2^s_b_1_5 */
    auto s_b_1_14 = emitter.bitwise_xor(s_b_1_2, s_b_1_5);
    /* execute.simd:2400 [D] s_b_1_15 = ~s_b_1_8 */
    auto s_b_1_15 = emitter.bitwise_not(s_b_1_8);
    /* execute.simd:2400 [D] s_b_1_16 = s_b_1_14&s_b_1_15 */
    auto s_b_1_16 = emitter.bitwise_and(s_b_1_14, s_b_1_15);
    /* execute.simd:2400 [D] s_b_1_17 = s_b_1_2^s_b_1_16 */
    auto s_b_1_17 = emitter.bitwise_xor(s_b_1_2, s_b_1_16);
    /* execute.simd:6253 [D] s_b_1_18: WriteRegBank 2:s_b_1_9 = s_b_1_13 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13);
    /* execute.simd:6254 [D] s_b_1_19: WriteRegBank 3:s_b_1_9 = s_b_1_17 */
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
    /* execute.simd:2406 [F] s_b_3_0=sym_6286_3_parameter_inst.rd (const) */
    /* execute.simd:6275 [D] s_b_3_1 = ReadRegBank 7:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:2407 [F] s_b_3_2=sym_6286_3_parameter_inst.rn (const) */
    /* execute.simd:6275 [D] s_b_3_3 = ReadRegBank 7:s_b_3_2 (u64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:2408 [F] s_b_3_4=sym_6286_3_parameter_inst.rm (const) */
    /* execute.simd:6275 [D] s_b_3_5 = ReadRegBank 7:s_b_3_4 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:2410 [F] s_b_3_6=sym_6286_3_parameter_inst.rd (const) */
    /* execute.simd:2410 [D] s_b_3_7 = s_b_3_1^s_b_3_3 */
    auto s_b_3_7 = emitter.bitwise_xor(s_b_3_1, s_b_3_3);
    /* execute.simd:2410 [D] s_b_3_8 = ~s_b_3_5 */
    auto s_b_3_8 = emitter.bitwise_not(s_b_3_5);
    /* execute.simd:2410 [D] s_b_3_9 = s_b_3_7&s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_7, s_b_3_8);
    /* execute.simd:2410 [D] s_b_3_10 = s_b_3_1^s_b_3_9 */
    auto s_b_3_10 = emitter.bitwise_xor(s_b_3_1, s_b_3_9);
    /* execute.simd:6246 [D] s_b_3_11: WriteRegBank 2:s_b_3_6 = s_b_3_10 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_10,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_10);
    /* execute.simd:6247 [F] s_b_3_12 = constant u64 0 (const) */
    /* execute.simd:6247 [F] s_b_3_13: WriteRegBank 3:s_b_3_6 = s_b_3_12 */
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
  auto DV_sym_54259_1__R_s_b_23_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  uint8_t CV_sym_54083_0_state;
  auto DV_sym_54083_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_54196_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_54171_1__R_s_b_0_2 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_6844_0_rm = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_6839_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2063 [F] s_b_0_0=sym_6821_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_54083_0_state = s_b_0_1 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_54083_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_54083_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2793 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_10, b_11, b_12, b_13, b_14, b_7, b_8, b_9, b_6,  */
    switch (s_b_0_5) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_10;
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
    /* execute.a64:2807 [D] s_b_7_0 = ReadReg 4 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2807 [D] s_b_7_1: sym_54083_0_state = s_b_7_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_54083_0_state, s_b_7_0);
    /* execute.a64:0 [F] s_b_7_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2803 [D] s_b_8_0 = ReadReg 1 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2803 [D] s_b_8_1: sym_54083_0_state = s_b_8_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_54083_0_state, s_b_8_0);
    /* execute.a64:0 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2799 [D] s_b_9_0 = ReadReg 3 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2799 [D] s_b_9_1: sym_54083_0_state = s_b_9_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_54083_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2795 [D] s_b_10_0 = ReadReg 2 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2795 [D] s_b_10_1: sym_54083_0_state = s_b_10_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_54083_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2823 [F] s_b_11_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_11_1: sym_54083_0_state = s_b_11_0 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_54083_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_54083_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_11_2: Jump b_6 (const) */
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
    /* execute.a64:2811 [D] s_b_12_4: sym_54083_0_state = s_b_12_3, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_54083_0_state, s_b_12_3);
    /* execute.a64:0 [F] s_b_12_5: Jump b_6 (const) */
    goto fixed_block_b_6;
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
    /* execute.a64:2819 [D] s_b_13_6: sym_54083_0_state = s_b_13_5, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_54083_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2815 [D] s_b_14_0 = ReadReg 1 (u8) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_14_0, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_14_1 = ReadReg 4 (u8) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_1, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_14_2 = s_b_14_0==s_b_14_1 */
    auto s_b_14_2 = emitter.cmp_eq(s_b_14_0, s_b_14_1);
    /* execute.a64:2815 [D] s_b_14_3: sym_54083_0_state = s_b_14_2, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_54083_0_state, s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2829 [D] s_b_15_0 = sym_54083_0_state uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_54083_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_15_1 = !s_b_15_0 */
    auto s_b_15_1 = emitter.cmp_eq(s_b_15_0, emitter.const_u8(0));
    /* execute.a64:2829 [D] s_b_15_2: sym_54171_1__R_s_b_0_2 = s_b_15_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_54171_1__R_s_b_0_2, s_b_15_1);
    /* execute.a64:2829 [F] s_b_15_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2831 [D] s_b_16_0 = sym_54083_0_state uint8_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_54083_0_state, emitter.context().types().u8());
    /* execute.a64:2831 [D] s_b_16_1: sym_54171_1__R_s_b_0_2 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_54171_1__R_s_b_0_2, s_b_16_0);
    /* execute.a64:2831 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2063 [D] s_b_17_0 = sym_54171_1__R_s_b_0_2 uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_54171_1__R_s_b_0_2, emitter.context().types().u8());
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
        /* execute.a64:2657 [D] s_b_18_7: sym_54196_1__R_s_b_1_4 = s_b_18_6, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_54196_1__R_s_b_1_4, s_b_18_6);
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
        /* execute.a64:2659 [D] s_b_19_8: sym_54196_1__R_s_b_1_4 = s_b_19_7, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_54196_1__R_s_b_1_4, s_b_19_7);
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
        /* execute.a64:2065 [D] s_b_20_0 = sym_54196_1__R_s_b_1_4 uint64_t */
        auto s_b_20_0 = emitter.load_local(DV_sym_54196_1__R_s_b_1_4, emitter.context().types().u64());
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
        /* execute.a64:2657 [D] s_b_21_7: sym_54259_1__R_s_b_23_6 = s_b_21_6, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_54259_1__R_s_b_23_6, s_b_21_6);
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
        /* execute.a64:2659 [D] s_b_22_8: sym_54259_1__R_s_b_23_6 = s_b_22_7, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_54259_1__R_s_b_23_6, s_b_22_7);
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
        /* execute.a64:2066 [D] s_b_23_0 = sym_54259_1__R_s_b_23_6 uint64_t */
        auto s_b_23_0 = emitter.load_local(DV_sym_54259_1__R_s_b_23_6, emitter.context().types().u64());
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
    /* execute.simd:2008 [F] s_b_0_0=sym_7962_3_parameter_inst.SCALAR (const) */
    /* execute.simd:2008 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2009 [F] s_b_1_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:6275 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:2009 [D] s_b_1_2: sym_7971_0_rn = s_b_1_1, dominates: s_b_4_0 s_b_5_0  */
    emitter.store_local(DV_sym_7971_0_rn, s_b_1_1);
    /* execute.simd:2011 [F] s_b_1_3=sym_7962_3_parameter_inst.U (const) */
    /* execute.simd:2011 [F] s_b_1_4 = (u32)s_b_1_3 (const) */
    /* execute.simd:2011 [F] s_b_1_5 = constant u32 1 (const) */
    /* execute.simd:2011 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:2011 [F] s_b_1_7: If s_b_1_6: Jump b_4 else b_5 (const) */
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
    /* execute.simd:2025 [F] s_b_3_0=sym_7962_3_parameter_inst.U (const) */
    /* execute.simd:2025 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2025 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:2025 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:2025 [F] s_b_3_4: If s_b_3_3: Jump b_10 else b_11 (const) */
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
    /* execute.simd:2012 [D] s_b_4_0 = sym_7971_0_rn uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_7971_0_rn, emitter.context().types().u64());
    /* execute.simd:2012 [D] s_b_4_1 = (s64)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s64());
    /* execute.simd:2012 [F] s_b_4_2 = constant s64 0 (const) */
    /* execute.simd:2012 [D] s_b_4_3 = s_b_4_1<=s_b_4_2 */
    auto s_b_4_3 = emitter.cmp_le(s_b_4_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:2012 [D] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 */
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
    /* execute.simd:2018 [D] s_b_5_0 = sym_7971_0_rn uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_7971_0_rn, emitter.context().types().u64());
    /* execute.simd:2018 [D] s_b_5_1 = (s64)s_b_5_0 */
    auto s_b_5_1 = emitter.reinterpret(s_b_5_0, emitter.context().types().s64());
    /* execute.simd:2018 [F] s_b_5_2 = constant s64 0 (const) */
    /* execute.simd:2018 [D] s_b_5_3 = s_b_5_1<s_b_5_2 */
    auto s_b_5_3 = emitter.cmp_lt(s_b_5_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:2018 [D] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 */
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
    /* execute.simd:2026 [F] s_b_10_0=sym_7962_3_parameter_inst.arrangement (const) */
    /* execute.simd:2027 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.simd:2036 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.simd:2044 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.simd:2053 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.simd:2061 [F] s_b_10_5 = constant s32 4 (const) */
    /* execute.simd:2070 [F] s_b_10_6 = constant s32 5 (const) */
    /* execute.simd:2078 [F] s_b_10_7 = constant s32 6 (const) */
    /* execute.simd:2026 [F] s_b_10_8: Switch s_b_10_0: < <todo> > def b_19 (const) -> b_19, b_18, b_17, b_16, b_15, b_14, b_13, b_12,  */
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
    /* execute.simd:2092 [F] s_b_11_0=sym_7962_3_parameter_inst.arrangement (const) */
    /* execute.simd:2093 [F] s_b_11_1 = constant s32 0 (const) */
    /* execute.simd:2102 [F] s_b_11_2 = constant s32 1 (const) */
    /* execute.simd:2110 [F] s_b_11_3 = constant s32 2 (const) */
    /* execute.simd:2119 [F] s_b_11_4 = constant s32 3 (const) */
    /* execute.simd:2127 [F] s_b_11_5 = constant s32 4 (const) */
    /* execute.simd:2136 [F] s_b_11_6 = constant s32 5 (const) */
    /* execute.simd:2144 [F] s_b_11_7 = constant s32 6 (const) */
    /* execute.simd:2092 [F] s_b_11_8: Switch s_b_11_0: < <todo> > def b_27 (const) -> b_27, b_26, b_25, b_24, b_23, b_22, b_21, b_20,  */
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
    /* execute.simd:2028 [F] s_b_12_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2028 [D] s_b_12_1 = ReadRegBank 15:s_b_12_0 (v8u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:2028 [D] s_b_12_2 = (v8s8)s_b_12_1 */
    auto s_b_12_2 = emitter.reinterpret(s_b_12_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_12_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:2030 [D] s_b_12_4 = s_b_12_2<=s_b_12_3 */
    auto s_b_12_4 = emitter.cmp_le(s_b_12_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:2030 [D] s_b_12_5 = (v8u8)s_b_12_4 */
    auto s_b_12_5 = emitter.reinterpret(s_b_12_4, emitter.context().types().v8u8());
    /* execute.simd:2031 [F] s_b_12_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2031 [D] s_b_12_7: WriteRegBank 15:s_b_12_6 = s_b_12_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5);
    /* execute.simd:2032 [F] s_b_12_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2032 [F] s_b_12_9 = constant u64 0 (const) */
    /* execute.simd:2032 [F] s_b_12_10: WriteRegBank 3:s_b_12_8 = s_b_12_9 */
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
    /* execute.simd:2037 [F] s_b_13_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2037 [D] s_b_13_1 = ReadRegBank 16:s_b_13_0 (v16u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_13_1,emitter.const_u8(16));
    }
    /* execute.simd:2037 [D] s_b_13_2 = (v16s8)s_b_13_1 */
    auto s_b_13_2 = emitter.reinterpret(s_b_13_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_13_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:2039 [D] s_b_13_4 = s_b_13_2<=s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_le(s_b_13_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:2039 [D] s_b_13_5 = (v16u8)s_b_13_4 */
    auto s_b_13_5 = emitter.reinterpret(s_b_13_4, emitter.context().types().v16u8());
    /* execute.simd:2040 [F] s_b_13_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2040 [D] s_b_13_7: WriteRegBank 16:s_b_13_6 = s_b_13_5 */
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
    /* execute.simd:2045 [F] s_b_14_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2045 [D] s_b_14_1 = ReadRegBank 17:s_b_14_0 (v4u16) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.simd:2045 [D] s_b_14_2 = (v4s16)s_b_14_1 */
    auto s_b_14_2 = emitter.reinterpret(s_b_14_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_14_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:2047 [D] s_b_14_4 = s_b_14_2<=s_b_14_3 */
    auto s_b_14_4 = emitter.cmp_le(s_b_14_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:2047 [D] s_b_14_5 = (v4u16)s_b_14_4 */
    auto s_b_14_5 = emitter.reinterpret(s_b_14_4, emitter.context().types().v4u16());
    /* execute.simd:2048 [F] s_b_14_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2048 [D] s_b_14_7: WriteRegBank 17:s_b_14_6 = s_b_14_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5);
    /* execute.simd:2049 [F] s_b_14_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2049 [F] s_b_14_9 = constant u64 0 (const) */
    /* execute.simd:2049 [F] s_b_14_10: WriteRegBank 3:s_b_14_8 = s_b_14_9 */
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
    /* execute.simd:2054 [F] s_b_15_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2054 [D] s_b_15_1 = ReadRegBank 18:s_b_15_0 (v8u16) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_15_1,emitter.const_u8(16));
    }
    /* execute.simd:2054 [D] s_b_15_2 = (v8s16)s_b_15_1 */
    auto s_b_15_2 = emitter.reinterpret(s_b_15_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_15_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:2056 [D] s_b_15_4 = s_b_15_2<=s_b_15_3 */
    auto s_b_15_4 = emitter.cmp_le(s_b_15_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:2056 [D] s_b_15_5 = (v8u16)s_b_15_4 */
    auto s_b_15_5 = emitter.reinterpret(s_b_15_4, emitter.context().types().v8u16());
    /* execute.simd:2058 [F] s_b_15_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2058 [D] s_b_15_7: WriteRegBank 18:s_b_15_6 = s_b_15_5 */
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
    /* execute.simd:2062 [F] s_b_16_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2062 [D] s_b_16_1 = ReadRegBank 19:s_b_16_0 (v2u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:2062 [D] s_b_16_2 = (v2s32)s_b_16_1 */
    auto s_b_16_2 = emitter.reinterpret(s_b_16_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_16_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:2064 [D] s_b_16_4 = s_b_16_2<=s_b_16_3 */
    auto s_b_16_4 = emitter.cmp_le(s_b_16_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:2064 [D] s_b_16_5 = (v2u32)s_b_16_4 */
    auto s_b_16_5 = emitter.reinterpret(s_b_16_4, emitter.context().types().v2u32());
    /* execute.simd:2065 [F] s_b_16_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2065 [D] s_b_16_7: WriteRegBank 19:s_b_16_6 = s_b_16_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5);
    /* execute.simd:2066 [F] s_b_16_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2066 [F] s_b_16_9 = constant u64 0 (const) */
    /* execute.simd:2066 [F] s_b_16_10: WriteRegBank 3:s_b_16_8 = s_b_16_9 */
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
    /* execute.simd:2071 [F] s_b_17_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2071 [D] s_b_17_1 = ReadRegBank 20:s_b_17_0 (v4u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:2071 [D] s_b_17_2 = (v4s32)s_b_17_1 */
    auto s_b_17_2 = emitter.reinterpret(s_b_17_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_17_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:2073 [D] s_b_17_4 = s_b_17_2<=s_b_17_3 */
    auto s_b_17_4 = emitter.cmp_le(s_b_17_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:2073 [D] s_b_17_5 = (v4u32)s_b_17_4 */
    auto s_b_17_5 = emitter.reinterpret(s_b_17_4, emitter.context().types().v4u32());
    /* execute.simd:2075 [F] s_b_17_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2075 [D] s_b_17_7: WriteRegBank 20:s_b_17_6 = s_b_17_5 */
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
    /* execute.simd:2079 [F] s_b_18_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2079 [D] s_b_18_1 = ReadRegBank 21:s_b_18_0 (v2u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_18_1,emitter.const_u8(16));
    }
    /* execute.simd:2079 [D] s_b_18_2 = (v2s64)s_b_18_1 */
    auto s_b_18_2 = emitter.reinterpret(s_b_18_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_18_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:2081 [D] s_b_18_4 = s_b_18_2<=s_b_18_3 */
    auto s_b_18_4 = emitter.cmp_le(s_b_18_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:2081 [D] s_b_18_5 = (v2u64)s_b_18_4 */
    auto s_b_18_5 = emitter.reinterpret(s_b_18_4, emitter.context().types().v2u64());
    /* execute.simd:2083 [F] s_b_18_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2083 [D] s_b_18_7: WriteRegBank 21:s_b_18_6 = s_b_18_5 */
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
    /* execute.simd:2087 [D] s_b_19_0 = trap */
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
    /* execute.simd:2094 [F] s_b_20_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2094 [D] s_b_20_1 = ReadRegBank 15:s_b_20_0 (v8u8) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:2094 [D] s_b_20_2 = (v8s8)s_b_20_1 */
    auto s_b_20_2 = emitter.reinterpret(s_b_20_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_20_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:2096 [D] s_b_20_4 = s_b_20_2<s_b_20_3 */
    auto s_b_20_4 = emitter.cmp_lt(s_b_20_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:2096 [D] s_b_20_5 = (v8u8)s_b_20_4 */
    auto s_b_20_5 = emitter.reinterpret(s_b_20_4, emitter.context().types().v8u8());
    /* execute.simd:2097 [F] s_b_20_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2097 [D] s_b_20_7: WriteRegBank 15:s_b_20_6 = s_b_20_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5);
    /* execute.simd:2098 [F] s_b_20_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2098 [F] s_b_20_9 = constant u64 0 (const) */
    /* execute.simd:2098 [F] s_b_20_10: WriteRegBank 3:s_b_20_8 = s_b_20_9 */
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
    /* execute.simd:2103 [F] s_b_21_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2103 [D] s_b_21_1 = ReadRegBank 16:s_b_21_0 (v16u8) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:2103 [D] s_b_21_2 = (v16s8)s_b_21_1 */
    auto s_b_21_2 = emitter.reinterpret(s_b_21_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_21_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:2105 [D] s_b_21_4 = s_b_21_2<s_b_21_3 */
    auto s_b_21_4 = emitter.cmp_lt(s_b_21_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:2105 [D] s_b_21_5 = (v16u8)s_b_21_4 */
    auto s_b_21_5 = emitter.reinterpret(s_b_21_4, emitter.context().types().v16u8());
    /* execute.simd:2106 [F] s_b_21_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2106 [D] s_b_21_7: WriteRegBank 16:s_b_21_6 = s_b_21_5 */
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
    /* execute.simd:2111 [F] s_b_22_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2111 [D] s_b_22_1 = ReadRegBank 17:s_b_22_0 (v4u16) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:2111 [D] s_b_22_2 = (v4s16)s_b_22_1 */
    auto s_b_22_2 = emitter.reinterpret(s_b_22_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_22_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:2113 [D] s_b_22_4 = s_b_22_2<s_b_22_3 */
    auto s_b_22_4 = emitter.cmp_lt(s_b_22_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:2113 [D] s_b_22_5 = (v4u16)s_b_22_4 */
    auto s_b_22_5 = emitter.reinterpret(s_b_22_4, emitter.context().types().v4u16());
    /* execute.simd:2114 [F] s_b_22_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2114 [D] s_b_22_7: WriteRegBank 17:s_b_22_6 = s_b_22_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5);
    /* execute.simd:2115 [F] s_b_22_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2115 [F] s_b_22_9 = constant u64 0 (const) */
    /* execute.simd:2115 [F] s_b_22_10: WriteRegBank 3:s_b_22_8 = s_b_22_9 */
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
    /* execute.simd:2120 [F] s_b_23_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2120 [D] s_b_23_1 = ReadRegBank 18:s_b_23_0 (v8u16) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:2120 [D] s_b_23_2 = (v8s16)s_b_23_1 */
    auto s_b_23_2 = emitter.reinterpret(s_b_23_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_23_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:2122 [D] s_b_23_4 = s_b_23_2<s_b_23_3 */
    auto s_b_23_4 = emitter.cmp_lt(s_b_23_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:2122 [D] s_b_23_5 = (v8u16)s_b_23_4 */
    auto s_b_23_5 = emitter.reinterpret(s_b_23_4, emitter.context().types().v8u16());
    /* execute.simd:2124 [F] s_b_23_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2124 [D] s_b_23_7: WriteRegBank 18:s_b_23_6 = s_b_23_5 */
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
    /* execute.simd:2128 [F] s_b_24_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2128 [D] s_b_24_1 = ReadRegBank 19:s_b_24_0 (v2u32) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_24_1,emitter.const_u8(8));
    }
    /* execute.simd:2128 [D] s_b_24_2 = (v2s32)s_b_24_1 */
    auto s_b_24_2 = emitter.reinterpret(s_b_24_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_24_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:2130 [D] s_b_24_4 = s_b_24_2<s_b_24_3 */
    auto s_b_24_4 = emitter.cmp_lt(s_b_24_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:2130 [D] s_b_24_5 = (v2u32)s_b_24_4 */
    auto s_b_24_5 = emitter.reinterpret(s_b_24_4, emitter.context().types().v2u32());
    /* execute.simd:2131 [F] s_b_24_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2131 [D] s_b_24_7: WriteRegBank 19:s_b_24_6 = s_b_24_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5);
    /* execute.simd:2132 [F] s_b_24_8=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2132 [F] s_b_24_9 = constant u64 0 (const) */
    /* execute.simd:2132 [F] s_b_24_10: WriteRegBank 3:s_b_24_8 = s_b_24_9 */
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
    /* execute.simd:2137 [F] s_b_25_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2137 [D] s_b_25_1 = ReadRegBank 20:s_b_25_0 (v4u32) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_25_1,emitter.const_u8(16));
    }
    /* execute.simd:2137 [D] s_b_25_2 = (v4s32)s_b_25_1 */
    auto s_b_25_2 = emitter.reinterpret(s_b_25_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_25_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:2139 [D] s_b_25_4 = s_b_25_2<s_b_25_3 */
    auto s_b_25_4 = emitter.cmp_lt(s_b_25_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:2139 [D] s_b_25_5 = (v4u32)s_b_25_4 */
    auto s_b_25_5 = emitter.reinterpret(s_b_25_4, emitter.context().types().v4u32());
    /* execute.simd:2141 [F] s_b_25_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2141 [D] s_b_25_7: WriteRegBank 20:s_b_25_6 = s_b_25_5 */
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
    /* execute.simd:2145 [F] s_b_26_0=sym_7962_3_parameter_inst.rn (const) */
    /* execute.simd:2145 [D] s_b_26_1 = ReadRegBank 21:s_b_26_0 (v2u64) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_26_1,emitter.const_u8(16));
    }
    /* execute.simd:2145 [D] s_b_26_2 = (v2s64)s_b_26_1 */
    auto s_b_26_2 = emitter.reinterpret(s_b_26_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_26_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:2147 [D] s_b_26_4 = s_b_26_2<s_b_26_3 */
    auto s_b_26_4 = emitter.cmp_lt(s_b_26_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:2147 [D] s_b_26_5 = (v2u64)s_b_26_4 */
    auto s_b_26_5 = emitter.reinterpret(s_b_26_4, emitter.context().types().v2u64());
    /* execute.simd:2149 [F] s_b_26_6=sym_7962_3_parameter_inst.rd (const) */
    /* execute.simd:2149 [D] s_b_26_7: WriteRegBank 21:s_b_26_6 = s_b_26_5 */
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
    /* execute.simd:2153 [D] s_b_27_0 = trap */
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
        /* execute.simd:2013 [F] s_b_6_0=sym_7962_3_parameter_inst.rd (const) */
        /* execute.simd:2013 [F] s_b_6_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6246 [F] s_b_6_2: WriteRegBank 2:s_b_6_0 = s_b_6_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6247 [F] s_b_6_3 = constant u64 0 (const) */
        /* execute.simd:6247 [F] s_b_6_4: WriteRegBank 3:s_b_6_0 = s_b_6_3 */
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
        /* execute.simd:2015 [F] s_b_7_0=sym_7962_3_parameter_inst.rd (const) */
        /* execute.simd:2015 [F] s_b_7_1 = constant u64 0 (const) */
        /* execute.simd:6246 [F] s_b_7_2: WriteRegBank 2:s_b_7_0 = s_b_7_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6247 [F] s_b_7_3 = constant u64 0 (const) */
        /* execute.simd:6247 [F] s_b_7_4: WriteRegBank 3:s_b_7_0 = s_b_7_3 */
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
        /* execute.simd:2019 [F] s_b_8_0=sym_7962_3_parameter_inst.rd (const) */
        /* execute.simd:2019 [F] s_b_8_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6246 [F] s_b_8_2: WriteRegBank 2:s_b_8_0 = s_b_8_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6247 [F] s_b_8_3 = constant u64 0 (const) */
        /* execute.simd:6247 [F] s_b_8_4: WriteRegBank 3:s_b_8_0 = s_b_8_3 */
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
        /* execute.simd:2021 [F] s_b_9_0=sym_7962_3_parameter_inst.rd (const) */
        /* execute.simd:2021 [F] s_b_9_1 = constant u64 0 (const) */
        /* execute.simd:6246 [F] s_b_9_2: WriteRegBank 2:s_b_9_0 = s_b_9_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6247 [F] s_b_9_3 = constant u64 0 (const) */
        /* execute.simd:6247 [F] s_b_9_4: WriteRegBank 3:s_b_9_0 = s_b_9_3 */
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
  auto DV_sym_57004_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_57026_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56982_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56775_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56960_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56866_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  uint8_t CV_sym_56681_0_state;
  auto DV_sym_56681_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_56724_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_56806_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56930_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2139 [F] s_b_0_0=sym_9067_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_56681_0_state = s_b_0_1 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_56681_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_56681_0_state, emitter.const_u8((uint8_t)0ULL));
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
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_14;
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
    /* execute.a64:2829 [D] s_b_5_0 = sym_56681_0_state uint8_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_56681_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_5_1 = !s_b_5_0 */
    auto s_b_5_1 = emitter.cmp_eq(s_b_5_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_5_2: sym_56724_0_return_symbol = s_b_5_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_56724_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2831 [D] s_b_6_0 = sym_56681_0_state uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_56681_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_6_1: sym_56724_0_return_symbol = s_b_6_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_56724_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2795 [D] s_b_7_1: sym_56681_0_state = s_b_7_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56681_0_state, s_b_7_0);
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
    /* execute.a64:2799 [D] s_b_8_1: sym_56681_0_state = s_b_8_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56681_0_state, s_b_8_0);
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
    /* execute.a64:2803 [D] s_b_9_1: sym_56681_0_state = s_b_9_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56681_0_state, s_b_9_0);
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
    /* execute.a64:2807 [D] s_b_10_1: sym_56681_0_state = s_b_10_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56681_0_state, s_b_10_0);
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
    /* execute.a64:2811 [D] s_b_11_4: sym_56681_0_state = s_b_11_3, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56681_0_state, s_b_11_3);
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
    /* execute.a64:2815 [D] s_b_12_3: sym_56681_0_state = s_b_12_2, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56681_0_state, s_b_12_2);
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
    /* execute.a64:2819 [D] s_b_13_6: sym_56681_0_state = s_b_13_5, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56681_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2823 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_14_1: sym_56681_0_state = s_b_14_0 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_56681_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_56681_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5, b_6,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_56724_0_return_symbol uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_56724_0_return_symbol, emitter.context().types().u8());
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
        /* execute.a64:2657 [D] s_b_16_7: sym_56775_1__R_s_b_1_6 = s_b_16_6, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_56775_1__R_s_b_1_6, s_b_16_6);
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
        /* execute.a64:2659 [D] s_b_17_8: sym_56775_1__R_s_b_1_6 = s_b_17_7, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_56775_1__R_s_b_1_6, s_b_17_7);
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
        /* execute.a64:2142 [D] s_b_18_1 = sym_56775_1__R_s_b_1_6 uint64_t */
        auto s_b_18_1 = emitter.load_local(DV_sym_56775_1__R_s_b_1_6, emitter.context().types().u64());
        /* execute.a64:2142 [D] s_b_18_2 = ~s_b_18_1 */
        auto s_b_18_2 = emitter.bitwise_not(s_b_18_1);
        /* execute.a64:2142 [F] s_b_18_3 = constant u64 1 (const) */
        /* execute.a64:2142 [D] s_b_18_4 = s_b_18_2+s_b_18_3 */
        auto s_b_18_4 = emitter.add(s_b_18_2, emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:2142 [D] s_b_18_5: sym_56866_3_parameter_value = s_b_18_4, dominates: s_b_22_1 s_b_23_1  */
        emitter.store_local(DV_sym_56866_3_parameter_value, s_b_18_4);
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
        /* execute.a64:2657 [D] s_b_19_7: sym_56806_1__R_s_b_3_6 = s_b_19_6, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_56806_1__R_s_b_3_6, s_b_19_6);
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
        /* execute.a64:2659 [D] s_b_20_8: sym_56806_1__R_s_b_3_6 = s_b_20_7, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_56806_1__R_s_b_3_6, s_b_20_7);
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
        /* execute.a64:2144 [D] s_b_21_1 = sym_56806_1__R_s_b_3_6 uint64_t */
        auto s_b_21_1 = emitter.load_local(DV_sym_56806_1__R_s_b_3_6, emitter.context().types().u64());
        /* execute.a64:2144 [D] s_b_21_2: sym_56930_3_parameter_value = s_b_21_1, dominates: s_b_24_1 s_b_25_1  */
        emitter.store_local(DV_sym_56930_3_parameter_value, s_b_21_1);
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
        /* execute.a64:2691 [D] s_b_22_1 = sym_56866_3_parameter_value uint64_t */
        auto s_b_22_1 = emitter.load_local(DV_sym_56866_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_22_2: sym_56960_3_parameter_value = s_b_22_1, dominates: s_b_26_1  */
        emitter.store_local(DV_sym_56960_3_parameter_value, s_b_22_1);
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
        /* execute.a64:2693 [D] s_b_23_1 = sym_56866_3_parameter_value uint64_t */
        auto s_b_23_1 = emitter.load_local(DV_sym_56866_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_23_2 = (u32)s_b_23_1 */
        auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_23_3 = (u64)s_b_23_2 */
        auto s_b_23_3 = emitter.zx(s_b_23_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_23_4: sym_56982_3_parameter_value = s_b_23_3, dominates: s_b_27_1  */
        emitter.store_local(DV_sym_56982_3_parameter_value, s_b_23_3);
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
        /* execute.a64:2691 [D] s_b_24_1 = sym_56930_3_parameter_value uint64_t */
        auto s_b_24_1 = emitter.load_local(DV_sym_56930_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_24_2: sym_57004_3_parameter_value = s_b_24_1, dominates: s_b_28_1  */
        emitter.store_local(DV_sym_57004_3_parameter_value, s_b_24_1);
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
        /* execute.a64:2693 [D] s_b_25_1 = sym_56930_3_parameter_value uint64_t */
        auto s_b_25_1 = emitter.load_local(DV_sym_56930_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_25_2 = (u32)s_b_25_1 */
        auto s_b_25_2 = emitter.truncate(s_b_25_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_25_3 = (u64)s_b_25_2 */
        auto s_b_25_3 = emitter.zx(s_b_25_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_25_4: sym_57026_3_parameter_value = s_b_25_3, dominates: s_b_29_1  */
        emitter.store_local(DV_sym_57026_3_parameter_value, s_b_25_3);
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
        /* execute.a64:2684 [D] s_b_26_1 = sym_56960_3_parameter_value uint64_t */
        auto s_b_26_1 = emitter.load_local(DV_sym_56960_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2684 [D] s_b_27_1 = sym_56982_3_parameter_value uint64_t */
        auto s_b_27_1 = emitter.load_local(DV_sym_56982_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2684 [D] s_b_28_1 = sym_57004_3_parameter_value uint64_t */
        auto s_b_28_1 = emitter.load_local(DV_sym_57004_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2684 [D] s_b_29_1 = sym_57026_3_parameter_value uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_57026_3_parameter_value, emitter.context().types().u64());
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
  auto DV_sym_58582_0_spsr = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_58530_0_parameter_voff;
  auto DV_sym_58528_0_parameter_retaddr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_58526_0_parameter_syndrome;
  auto DV_sym_58652_0_spsr = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_58664_3_parameter_voff;
  uint32_t CV_sym_58753_3_parameter_syndrome;
  auto DV_sym_58702_3_parameter_retaddr = emitter.alloc_local(emitter.context().types().u64(), false);
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
    /* execute.a64:2873 [F] s_b_1_5: sym_58753_3_parameter_syndrome = s_b_1_4 (const), dominates: s_b_21_10  */
    CV_sym_58753_3_parameter_syndrome = ((uint32_t)insn.imm16);
    /* execute.a64:2873 [D] s_b_1_6: sym_58702_3_parameter_retaddr = s_b_1_1, dominates: s_b_21_8  */
    emitter.store_local(DV_sym_58702_3_parameter_retaddr, s_b_1_1);
    /* execute.a64:2873 [F] s_b_1_7: sym_58664_3_parameter_voff = s_b_1_2 (const), dominates: s_b_19_0 s_b_22_0 s_b_21_27  */
    CV_sym_58664_3_parameter_voff = (uint64_t)0ULL;
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
    /* execute.a64:2959 [D] s_b_1_58: sym_58652_0_spsr = s_b_1_57, dominates: s_b_21_6  */
    emitter.store_local(DV_sym_58652_0_spsr, s_b_1_57);
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
    /* execute.a64:2889 [F] s_b_14_7: sym_58526_0_parameter_syndrome = s_b_14_6 (const), dominates: s_b_17_10  */
    CV_sym_58526_0_parameter_syndrome = ((uint32_t)insn.imm16);
    /* execute.a64:2889 [D] s_b_14_8: sym_58528_0_parameter_retaddr = s_b_14_2, dominates: s_b_17_8  */
    emitter.store_local(DV_sym_58528_0_parameter_retaddr, s_b_14_2);
    /* execute.a64:2889 [F] s_b_14_9: sym_58530_0_parameter_voff = s_b_14_3 (const), dominates: s_b_15_0 s_b_18_0 s_b_17_27  */
    CV_sym_58530_0_parameter_voff = (uint64_t)0ULL;
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
    /* execute.a64:2959 [D] s_b_14_60: sym_58582_0_spsr = s_b_14_59, dominates: s_b_17_6  */
    emitter.store_local(DV_sym_58582_0_spsr, s_b_14_59);
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
    /* execute.a64:2963 [F] s_b_15_0 = sym_58530_0_parameter_voff (const) uint64_t */
    uint64_t s_b_15_0 = CV_sym_58530_0_parameter_voff;
    /* ???:4294967295 [F] s_b_15_1 = constant u64 400 (const) */
    /* ???:4294967295 [F] s_b_15_2 = s_b_15_0+s_b_15_1 (const) */
    uint64_t s_b_15_2 = ((uint64_t)(s_b_15_0 + (uint64_t)1024ULL));
    /* execute.a64:2963 [F] s_b_15_3: sym_58530_0_parameter_voff = s_b_15_2 (const), dominates: s_b_17_27  */
    CV_sym_58530_0_parameter_voff = s_b_15_2;
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
    /* execute.a64:2975 [D] s_b_17_6 = sym_58582_0_spsr uint32_t */
    auto s_b_17_6 = emitter.load_local(DV_sym_58582_0_spsr, emitter.context().types().u32());
    /* execute.a64:2975 [D] s_b_17_7: WriteReg 17 = s_b_17_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_17_6, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_17_6);
    /* execute.a64:2976 [D] s_b_17_8 = sym_58528_0_parameter_retaddr uint64_t */
    auto s_b_17_8 = emitter.load_local(DV_sym_58528_0_parameter_retaddr, emitter.context().types().u64());
    /* execute.a64:2976 [D] s_b_17_9: WriteReg 16 = s_b_17_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_17_8, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_17_8);
    /* execute.a64:2981 [F] s_b_17_10 = sym_58526_0_parameter_syndrome (const) uint32_t */
    uint32_t s_b_17_10 = CV_sym_58526_0_parameter_syndrome;
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
    /* execute.a64:2998 [F] s_b_17_27 = sym_58530_0_parameter_voff (const) uint64_t */
    uint64_t s_b_17_27 = CV_sym_58530_0_parameter_voff;
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
    /* execute.a64:2965 [F] s_b_18_0 = sym_58530_0_parameter_voff (const) uint64_t */
    uint64_t s_b_18_0 = CV_sym_58530_0_parameter_voff;
    /* ???:4294967295 [F] s_b_18_1 = constant u64 200 (const) */
    /* ???:4294967295 [F] s_b_18_2 = s_b_18_0+s_b_18_1 (const) */
    uint64_t s_b_18_2 = ((uint64_t)(s_b_18_0 + (uint64_t)512ULL));
    /* execute.a64:2965 [F] s_b_18_3: sym_58530_0_parameter_voff = s_b_18_2 (const), dominates: s_b_17_27  */
    CV_sym_58530_0_parameter_voff = s_b_18_2;
    /* execute.a64:2965 [F] s_b_18_4: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_1,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2963 [F] s_b_19_0 = sym_58664_3_parameter_voff (const) uint64_t */
    uint64_t s_b_19_0 = CV_sym_58664_3_parameter_voff;
    /* ???:4294967295 [F] s_b_19_1 = constant u64 400 (const) */
    /* ???:4294967295 [F] s_b_19_2 = s_b_19_0+s_b_19_1 (const) */
    uint64_t s_b_19_2 = ((uint64_t)(s_b_19_0 + (uint64_t)1024ULL));
    /* execute.a64:2963 [F] s_b_19_3: sym_58664_3_parameter_voff = s_b_19_2 (const), dominates: s_b_21_27  */
    CV_sym_58664_3_parameter_voff = s_b_19_2;
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
    /* execute.a64:2975 [D] s_b_21_6 = sym_58652_0_spsr uint32_t */
    auto s_b_21_6 = emitter.load_local(DV_sym_58652_0_spsr, emitter.context().types().u32());
    /* execute.a64:2975 [D] s_b_21_7: WriteReg 17 = s_b_21_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_21_6, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_21_6);
    /* execute.a64:2976 [D] s_b_21_8 = sym_58702_3_parameter_retaddr uint64_t */
    auto s_b_21_8 = emitter.load_local(DV_sym_58702_3_parameter_retaddr, emitter.context().types().u64());
    /* execute.a64:2976 [D] s_b_21_9: WriteReg 16 = s_b_21_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_21_8, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_21_8);
    /* execute.a64:2981 [F] s_b_21_10 = sym_58753_3_parameter_syndrome (const) uint32_t */
    uint32_t s_b_21_10 = CV_sym_58753_3_parameter_syndrome;
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
    /* execute.a64:2998 [F] s_b_21_27 = sym_58664_3_parameter_voff (const) uint64_t */
    uint64_t s_b_21_27 = CV_sym_58664_3_parameter_voff;
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
    /* execute.a64:2965 [F] s_b_22_0 = sym_58664_3_parameter_voff (const) uint64_t */
    uint64_t s_b_22_0 = CV_sym_58664_3_parameter_voff;
    /* ???:4294967295 [F] s_b_22_1 = constant u64 200 (const) */
    /* ???:4294967295 [F] s_b_22_2 = s_b_22_0+s_b_22_1 (const) */
    uint64_t s_b_22_2 = ((uint64_t)(s_b_22_0 + (uint64_t)512ULL));
    /* execute.a64:2965 [F] s_b_22_3: sym_58664_3_parameter_voff = s_b_22_2 (const), dominates: s_b_21_27  */
    CV_sym_58664_3_parameter_voff = s_b_22_2;
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
  auto DV_sym_10655_0_rn = emitter.alloc_local(emitter.context().types().f32(), false);
  float CV_sym_10674_1_temporary_value;
  auto DV_sym_10674_1_temporary_value = emitter.alloc_local(emitter.context().types().f32(), false);
  auto DV_sym_10707_0_rn = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_10737_0_rm = emitter.alloc_local(emitter.context().types().f64(), false);
  double CV_sym_10726_1_temporary_value;
  auto DV_sym_10726_1_temporary_value = emitter.alloc_local(emitter.context().types().f64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4695 [F] s_b_0_0=sym_10642_3_parameter_inst.type (const) */
    /* execute.simd:4695 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4695 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4695 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4695 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4697 [F] s_b_1_0=sym_10642_3_parameter_inst.rn (const) */
    /* execute.simd:6200 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4697 [D] s_b_1_2: sym_10655_0_rn = s_b_1_1, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_10655_0_rn, s_b_1_1);
    /* execute.simd:4698 [F] s_b_1_3=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4698 [F] s_b_1_4 = (u64)s_b_1_3 (const) */
    /* execute.simd:4698 [F] s_b_1_5 = constant u64 18 (const) */
    /* execute.simd:4698 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint64_t)insn.opcode2) == (uint64_t)24ULL));
    /* execute.simd:4698 [F] s_b_1_7=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4698 [F] s_b_1_8 = (u64)s_b_1_7 (const) */
    /* execute.simd:4698 [F] s_b_1_9 = constant u64 8 (const) */
    /* execute.simd:4698 [F] s_b_1_10 = s_b_1_8==s_b_1_9 (const) */
    uint8_t s_b_1_10 = ((uint8_t)(((uint64_t)insn.opcode2) == (uint64_t)8ULL));
    /* ???:4294967295 [F] s_b_1_11 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_1_12 = s_b_1_6!=s_b_1_11 (const) */
    uint8_t s_b_1_12 = ((uint8_t)(s_b_1_6 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_13 = s_b_1_10!=s_b_1_11 (const) */
    uint8_t s_b_1_13 = ((uint8_t)(s_b_1_10 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_14 = s_b_1_12|s_b_1_13 (const) */
    uint8_t s_b_1_14 = ((uint8_t)(s_b_1_12 | s_b_1_13));
    /* execute.simd:4698 [F] s_b_1_15: If s_b_1_14: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4707 [F] s_b_3_0=sym_10642_3_parameter_inst.rn (const) */
    /* execute.simd:6205 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4707 [D] s_b_3_2: sym_10707_0_rn = s_b_3_1, dominates: s_b_12_0 s_b_13_0  */
    emitter.store_local(DV_sym_10707_0_rn, s_b_3_1);
    /* execute.simd:4708 [F] s_b_3_3=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4708 [F] s_b_3_4 = (u64)s_b_3_3 (const) */
    /* execute.simd:4708 [F] s_b_3_5 = constant u64 18 (const) */
    /* execute.simd:4708 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint64_t)insn.opcode2) == (uint64_t)24ULL));
    /* execute.simd:4708 [F] s_b_3_7=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4708 [F] s_b_3_8 = (u64)s_b_3_7 (const) */
    /* execute.simd:4708 [F] s_b_3_9 = constant u64 8 (const) */
    /* execute.simd:4708 [F] s_b_3_10 = s_b_3_8==s_b_3_9 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(((uint64_t)insn.opcode2) == (uint64_t)8ULL));
    /* ???:4294967295 [F] s_b_3_11 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_12 = s_b_3_6!=s_b_3_11 (const) */
    uint8_t s_b_3_12 = ((uint8_t)(s_b_3_6 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_13 = s_b_3_10!=s_b_3_11 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(s_b_3_10 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_14 = s_b_3_12|s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(s_b_3_12 | s_b_3_13));
    /* execute.simd:4708 [F] s_b_3_15: If s_b_3_14: Jump b_9 else b_10 (const) */
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
    /* execute.simd:4698 [F] s_b_4_0 = constant f32 0 (const) */
    float s_b_4_0;
    {
      uint32_t __tmp = 0;
      s_b_4_0 = *(float *)&__tmp;
    }
    /* execute.simd:4698 [F] s_b_4_1: sym_10674_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_10674_1_temporary_value = s_b_4_0;
    emitter.store_local(DV_sym_10674_1_temporary_value, emitter.const_f32(s_b_4_0));
    /* execute.simd:4698 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4698 [F] s_b_5_0=sym_10642_3_parameter_inst.rm (const) */
    /* execute.simd:6200 [D] s_b_5_1 = ReadRegBank 9:s_b_5_0 (f32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_1,emitter.const_u8(4));
    }
    /* execute.simd:4698 [D] s_b_5_2: sym_10674_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_10674_1_temporary_value, s_b_5_1);
    /* execute.simd:4698 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4698 [D] s_b_6_0 = sym_10674_1_temporary_value float */
    auto s_b_6_0 = emitter.load_local(DV_sym_10674_1_temporary_value, emitter.context().types().f32());
    /* execute.simd:4698 [D] s_b_6_1: sym_10685_0_rm = s_b_6_0, dominates: s_b_7_1 s_b_8_1  */
    emitter.store_local(DV_sym_10685_0_rm, s_b_6_0);
    /* execute.simd:4700 [F] s_b_6_2=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4700 [F] s_b_6_3 = (u64)s_b_6_2 (const) */
    /* execute.simd:4700 [F] s_b_6_4 = constant u64 10 (const) */
    /* execute.simd:4700 [F] s_b_6_5 = s_b_6_3&s_b_6_4 (const) */
    uint64_t s_b_6_5 = ((uint64_t)(((uint64_t)insn.opcode2) & (uint64_t)16ULL));
    /* execute.simd:4700 [F] s_b_6_6: If s_b_6_5: Jump b_7 else b_8 (const) */
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
    /* execute.simd:4701 [D] s_b_7_0 = sym_10655_0_rn float */
    auto s_b_7_0 = emitter.load_local(DV_sym_10655_0_rn, emitter.context().types().f32());
    /* execute.simd:4701 [D] s_b_7_1 = sym_10685_0_rm float */
    auto s_b_7_1 = emitter.load_local(DV_sym_10685_0_rm, emitter.context().types().f32());
    /* execute.simd:4701 [D] s_b_7_2 = __builtin_cmpf32e_flags */
    emitter.call(__captive___builtin_cmpf32e_flags, s_b_7_0, s_b_7_1);
    /* execute.simd:4701 [F] s_b_7_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4703 [D] s_b_8_0 = sym_10655_0_rn float */
    auto s_b_8_0 = emitter.load_local(DV_sym_10655_0_rn, emitter.context().types().f32());
    /* execute.simd:4703 [D] s_b_8_1 = sym_10685_0_rm float */
    auto s_b_8_1 = emitter.load_local(DV_sym_10685_0_rm, emitter.context().types().f32());
    /* execute.simd:4703 [D] s_b_8_2 = __builtin_cmpf32_flags */
    emitter.call(__captive___builtin_cmpf32_flags, s_b_8_0, s_b_8_1);
    /* execute.simd:4703 [F] s_b_8_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4708 [F] s_b_9_0 = constant f64 0 (const) */
    double s_b_9_0;
    {
      uint64_t __tmp = 0;
      s_b_9_0 = *(double *)&__tmp;
    }
    /* execute.simd:4708 [F] s_b_9_1: sym_10726_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_10726_1_temporary_value = s_b_9_0;
    emitter.store_local(DV_sym_10726_1_temporary_value, emitter.const_f64(s_b_9_0));
    /* execute.simd:4708 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4708 [F] s_b_10_0=sym_10642_3_parameter_inst.rm (const) */
    /* execute.simd:6205 [D] s_b_10_1 = ReadRegBank 11:s_b_10_0 (f64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.simd:4708 [D] s_b_10_2: sym_10726_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_10726_1_temporary_value, s_b_10_1);
    /* execute.simd:4708 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4708 [D] s_b_11_0 = sym_10726_1_temporary_value double */
    auto s_b_11_0 = emitter.load_local(DV_sym_10726_1_temporary_value, emitter.context().types().f64());
    /* execute.simd:4708 [D] s_b_11_1: sym_10737_0_rm = s_b_11_0, dominates: s_b_12_1 s_b_13_1  */
    emitter.store_local(DV_sym_10737_0_rm, s_b_11_0);
    /* execute.simd:4710 [F] s_b_11_2=sym_10642_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4710 [F] s_b_11_3 = (u64)s_b_11_2 (const) */
    /* execute.simd:4710 [F] s_b_11_4 = constant u64 10 (const) */
    /* execute.simd:4710 [F] s_b_11_5 = s_b_11_3&s_b_11_4 (const) */
    uint64_t s_b_11_5 = ((uint64_t)(((uint64_t)insn.opcode2) & (uint64_t)16ULL));
    /* execute.simd:4710 [F] s_b_11_6: If s_b_11_5: Jump b_12 else b_13 (const) */
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
    /* execute.simd:4711 [D] s_b_12_0 = sym_10707_0_rn double */
    auto s_b_12_0 = emitter.load_local(DV_sym_10707_0_rn, emitter.context().types().f64());
    /* execute.simd:4711 [D] s_b_12_1 = sym_10737_0_rm double */
    auto s_b_12_1 = emitter.load_local(DV_sym_10737_0_rm, emitter.context().types().f64());
    /* execute.simd:4711 [D] s_b_12_2 = __builtin_cmpf64e_flags */
    emitter.call(__captive___builtin_cmpf64e_flags, s_b_12_0, s_b_12_1);
    /* execute.simd:4711 [F] s_b_12_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4713 [D] s_b_13_0 = sym_10707_0_rn double */
    auto s_b_13_0 = emitter.load_local(DV_sym_10707_0_rn, emitter.context().types().f64());
    /* execute.simd:4713 [D] s_b_13_1 = sym_10737_0_rm double */
    auto s_b_13_1 = emitter.load_local(DV_sym_10737_0_rm, emitter.context().types().f64());
    /* execute.simd:4713 [D] s_b_13_2 = __builtin_cmpf64_flags */
    emitter.call(__captive___builtin_cmpf64_flags, s_b_13_0, s_b_13_1);
    /* execute.simd:4713 [F] s_b_13_3: Jump b_2 (const) */
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
    /* execute.simd:4185 [F] s_b_0_0=sym_11622_3_parameter_inst.type (const) */
    /* execute.simd:4185 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4185 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4185 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4185 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4187 [F] s_b_1_0=sym_11622_3_parameter_inst.rn (const) */
    /* execute.simd:6200 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4188 [F] s_b_1_2=sym_11622_3_parameter_inst.rm (const) */
    /* execute.simd:6200 [D] s_b_1_3 = ReadRegBank 9:s_b_1_2 (f32) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(4));
    }
    /* execute.simd:4190 [D] s_b_1_4 = s_b_1_1/s_b_1_3 */
    auto s_b_1_4 = emitter.div(s_b_1_1, s_b_1_3);
    /* execute.simd:4191 [F] s_b_1_5=sym_11622_3_parameter_inst.rd (const) */
    /* execute.simd:6210 [D] s_b_1_6: WriteRegBank 9:s_b_1_5 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4);
    /* execute.simd:6211 [F] s_b_1_7 = constant u32 0 (const) */
    /* execute.simd:6211 [F] s_b_1_8: WriteRegBank 10:s_b_1_5 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6212 [F] s_b_1_9 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_1_10: WriteRegBank 3:s_b_1_5 = s_b_1_9 */
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
    /* execute.simd:4194 [F] s_b_3_0=sym_11622_3_parameter_inst.rn (const) */
    /* execute.simd:6205 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4195 [F] s_b_3_2=sym_11622_3_parameter_inst.rm (const) */
    /* execute.simd:6205 [D] s_b_3_3 = ReadRegBank 11:s_b_3_2 (f64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:4197 [D] s_b_3_4 = s_b_3_1/s_b_3_3 */
    auto s_b_3_4 = emitter.div(s_b_3_1, s_b_3_3);
    /* execute.simd:4198 [F] s_b_3_5=sym_11622_3_parameter_inst.rd (const) */
    /* execute.simd:6218 [D] s_b_3_6: WriteRegBank 11:s_b_3_5 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:6219 [F] s_b_3_7 = constant u64 0 (const) */
    /* execute.simd:6219 [F] s_b_3_8: WriteRegBank 3:s_b_3_5 = s_b_3_7 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fmov(const aarch64_decode_a64_FP_DP_1&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4058 [F] s_b_0_0=sym_11951_3_parameter_inst.type (const) */
    /* execute.simd:4058 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4058 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4058 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4058 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4059 [F] s_b_1_0=sym_11951_3_parameter_inst.rd (const) */
    /* execute.simd:4059 [F] s_b_1_1=sym_11951_3_parameter_inst.rn (const) */
    /* execute.simd:6200 [D] s_b_1_2 = ReadRegBank 9:s_b_1_1 (f32) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(4));
    }
    /* execute.simd:6210 [D] s_b_1_3: WriteRegBank 9:s_b_1_0 = s_b_1_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_2,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_2);
    /* execute.simd:6211 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.simd:6211 [F] s_b_1_5: WriteRegBank 10:s_b_1_0 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6212 [F] s_b_1_6 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_1_7: WriteRegBank 3:s_b_1_0 = s_b_1_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_8: Jump b_2 (const) */
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
    /* execute.simd:4061 [F] s_b_3_0=sym_11951_3_parameter_inst.rd (const) */
    /* execute.simd:4061 [F] s_b_3_1=sym_11951_3_parameter_inst.rn (const) */
    /* execute.simd:6205 [D] s_b_3_2 = ReadRegBank 11:s_b_3_1 (f64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:6218 [D] s_b_3_3: WriteRegBank 11:s_b_3_0 = s_b_3_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_2);
    /* execute.simd:6219 [F] s_b_3_4 = constant u64 0 (const) */
    /* execute.simd:6219 [F] s_b_3_5: WriteRegBank 3:s_b_3_0 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_3_6: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fnmul(const aarch64_decode_a64_FP_DP_2&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4166 [F] s_b_0_0=sym_12596_3_parameter_inst.type (const) */
    /* execute.simd:4166 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4166 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4166 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4166 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4168 [F] s_b_1_0=sym_12596_3_parameter_inst.rn (const) */
    /* execute.simd:6200 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4169 [F] s_b_1_2=sym_12596_3_parameter_inst.rm (const) */
    /* execute.simd:6200 [D] s_b_1_3 = ReadRegBank 9:s_b_1_2 (f32) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(4));
    }
    /* execute.simd:4171 [D] s_b_1_4 = s_b_1_1*s_b_1_3 */
    auto s_b_1_4 = emitter.mul(s_b_1_1, s_b_1_3);
    /* execute.simd:4171 [D] s_b_1_5 = -s_b_1_4 */
    auto s_b_1_5 = emitter.neg(s_b_1_4);
    /* execute.simd:4172 [F] s_b_1_6=sym_12596_3_parameter_inst.rd (const) */
    /* execute.simd:6210 [D] s_b_1_7: WriteRegBank 9:s_b_1_6 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6211 [F] s_b_1_8 = constant u32 0 (const) */
    /* execute.simd:6211 [F] s_b_1_9: WriteRegBank 10:s_b_1_6 = s_b_1_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6212 [F] s_b_1_10 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_1_11: WriteRegBank 3:s_b_1_6 = s_b_1_10 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_12: Jump b_2 (const) */
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
    /* execute.simd:4175 [F] s_b_3_0=sym_12596_3_parameter_inst.rn (const) */
    /* execute.simd:6205 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4176 [F] s_b_3_2=sym_12596_3_parameter_inst.rm (const) */
    /* execute.simd:6205 [D] s_b_3_3 = ReadRegBank 11:s_b_3_2 (f64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:4178 [D] s_b_3_4 = s_b_3_1*s_b_3_3 */
    auto s_b_3_4 = emitter.mul(s_b_3_1, s_b_3_3);
    /* execute.simd:4178 [D] s_b_3_5 = -s_b_3_4 */
    auto s_b_3_5 = emitter.neg(s_b_3_4);
    /* execute.simd:4179 [F] s_b_3_6=sym_12596_3_parameter_inst.rd (const) */
    /* execute.simd:6218 [D] s_b_3_7: WriteRegBank 11:s_b_3_6 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_5);
    /* execute.simd:6219 [F] s_b_3_8 = constant u64 0 (const) */
    /* execute.simd:6219 [F] s_b_3_9: WriteRegBank 3:s_b_3_6 = s_b_3_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_3_10: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ld1(const aarch64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_63651_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_63661_3_parameter_lane;
  auto DV_sym_63723_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_63601_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63706_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  uint8_t CV_sym_63782_1_tmp_s_b_5_4;
  auto DV_sym_63757_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63740_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_63689_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_63814_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63653_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_63655_3_parameter_rt;
  auto DV_sym_63672_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_13158_0_lane;
  uint8_t CV_sym_13138_0_rt;
  auto DV_sym_13132_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63785_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13126_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_18 else b_7 (const) */
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
    /* execute.simd:2418 [F] s_b_1_0 = sym_13138_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13138_0_rt;
    /* execute.simd:2418 [F] s_b_1_1=sym_13126_3_parameter_inst.regcnt (const) */
    /* execute.simd:2418 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2418 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2419 [F] s_b_2_0=sym_13126_3_parameter_inst.rt (const) */
    /* execute.simd:2419 [F] s_b_2_1 = sym_13138_0_rt (const) uint8_t */
    uint8_t s_b_2_1 = CV_sym_13138_0_rt;
    /* execute.simd:2419 [F] s_b_2_2 = s_b_2_0+s_b_2_1 (const) */
    uint8_t s_b_2_2 = ((uint8_t)(insn.rt + s_b_2_1));
    /* execute.simd:2419 [F] s_b_2_3 = constant u64 0 (const) */
    /* execute.simd:2419 [F] s_b_2_4 = constant u64 0 (const) */
    /* execute.simd:6253 [F] s_b_2_5: WriteRegBank 2:s_b_2_2 = s_b_2_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6254 [F] s_b_2_6: WriteRegBank 3:s_b_2_2 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2420 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:2420 [F] s_b_2_8: sym_13158_0_lane = s_b_2_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_13158_0_lane = (uint8_t)0ULL;
    /* execute.simd:2420 [F] s_b_2_9: Jump b_4 (const) */
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
    /* execute.simd:2420 [F] s_b_4_0 = sym_13158_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13158_0_lane;
    /* execute.simd:2420 [F] s_b_4_1=sym_13126_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2420 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2420 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2421 [F] s_b_5_0=sym_13126_3_parameter_inst.arrangement (const) */
    /* execute.simd:2421 [F] s_b_5_1=sym_13126_3_parameter_inst.rt (const) */
    /* execute.simd:2421 [F] s_b_5_2 = sym_13138_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13138_0_rt;
    /* execute.simd:2421 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2421 [F] s_b_5_4 = sym_13158_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13158_0_lane;
    /* execute.simd:2421 [D] s_b_5_5 = sym_13132_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13132_0_address, emitter.context().types().u64());
    /* execute.simd:2421 [F] s_b_5_6: sym_63655_3_parameter_rt = s_b_5_3 (const), dominates: s_b_13_2 s_b_16_2 s_b_15_2 s_b_11_2 s_b_12_2 s_b_14_2 s_b_10_2  */
    CV_sym_63655_3_parameter_rt = s_b_5_3;
    /* execute.simd:2421 [F] s_b_5_7: sym_63661_3_parameter_lane = s_b_5_4 (const), dominates: s_b_13_5 s_b_16_5 s_b_15_5 s_b_11_5 s_b_12_5 s_b_14_5 s_b_10_5  */
    CV_sym_63661_3_parameter_lane = s_b_5_4;
    /* execute.simd:2421 [D] s_b_5_8: sym_63651_3_parameter_addr = s_b_5_5, dominates: s_b_13_0 s_b_16_0 s_b_15_0 s_b_11_0 s_b_12_0 s_b_14_0 s_b_10_0  */
    emitter.store_local(DV_sym_63651_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_63782_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_17_1  */
    CV_sym_63782_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_63785_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_63785_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3808 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3817 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3826 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3835 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3844 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3853 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3862 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3807 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_9 (const) -> b_13, b_16, b_15, b_11, b_12, b_14, b_9, b_10,  */
    switch (insn.arrangement) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_11;
      break;
    default:
      goto fixed_block_b_9;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2418 [F] s_b_6_0 = sym_13138_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13138_0_rt;
    /* execute.simd:2418 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2418 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2418 [F] s_b_6_3: sym_13138_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_13138_0_rt = s_b_6_2;
    /* execute.simd:2418 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2733 [F] s_b_7_0=sym_13126_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_7_1 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_7_2: sym_63601_1__R_s_b_0_5 = s_b_7_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_63601_1__R_s_b_0_5, s_b_7_1);
    /* execute.a64:2733 [F] s_b_7_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_22,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2416 [D] s_b_8_0 = sym_63601_1__R_s_b_0_5 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_63601_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2416 [D] s_b_8_1: sym_13132_0_address = s_b_8_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13132_0_address, s_b_8_0);
    /* execute.simd:2418 [F] s_b_8_2 = constant u8 0 (const) */
    /* execute.simd:2418 [F] s_b_8_3: sym_13138_0_rt = s_b_8_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_13138_0_rt = (uint8_t)0ULL;
    /* execute.simd:2418 [F] s_b_8_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3872 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3810 [D] s_b_10_0 = sym_63651_3_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_63651_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 1 s_b_10_0 => sym_63653_0_mem_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_63653_0_mem_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(1));
    }
    /* execute.simd:3812 [F] s_b_10_2 = sym_63655_3_parameter_rt (const) uint8_t */
    uint8_t s_b_10_2 = CV_sym_63655_3_parameter_rt;
    /* execute.simd:3812 [D] s_b_10_3 = ReadRegBank 15:s_b_10_2 (v8u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:3813 [D] s_b_10_4 = sym_63653_0_mem_value uint8_t */
    auto s_b_10_4 = emitter.load_local(DV_sym_63653_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3813 [F] s_b_10_5 = sym_63661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_10_5 = CV_sym_63661_3_parameter_lane;
    /* execute.simd:3813 [F] s_b_10_6 = (s32)s_b_10_5 (const) */
    /* execute.simd:3813 [D] s_b_10_7 = s_b_10_3[s_b_10_6] <= s_b_10_4 */
    auto s_b_10_7 = emitter.vector_insert(s_b_10_3, emitter.const_s32(((int32_t)s_b_10_5)), s_b_10_4);
    /* execute.simd:3814 [D] s_b_10_8: WriteRegBank 15:s_b_10_2 = s_b_10_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_7);
    /* execute.simd:0 [F] s_b_10_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3819 [D] s_b_11_0 = sym_63651_3_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_63651_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 1 s_b_11_0 => sym_63672_0_mem_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_63672_0_mem_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(1));
    }
    /* execute.simd:3821 [F] s_b_11_2 = sym_63655_3_parameter_rt (const) uint8_t */
    uint8_t s_b_11_2 = CV_sym_63655_3_parameter_rt;
    /* execute.simd:3821 [D] s_b_11_3 = ReadRegBank 16:s_b_11_2 (v16u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:3822 [D] s_b_11_4 = sym_63672_0_mem_value uint8_t */
    auto s_b_11_4 = emitter.load_local(DV_sym_63672_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3822 [F] s_b_11_5 = sym_63661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_11_5 = CV_sym_63661_3_parameter_lane;
    /* execute.simd:3822 [F] s_b_11_6 = (s32)s_b_11_5 (const) */
    /* execute.simd:3822 [D] s_b_11_7 = s_b_11_3[s_b_11_6] <= s_b_11_4 */
    auto s_b_11_7 = emitter.vector_insert(s_b_11_3, emitter.const_s32(((int32_t)s_b_11_5)), s_b_11_4);
    /* execute.simd:3823 [D] s_b_11_8: WriteRegBank 16:s_b_11_2 = s_b_11_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_7);
    /* execute.simd:0 [F] s_b_11_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3828 [D] s_b_12_0 = sym_63651_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_63651_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_63689_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_63689_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3830 [F] s_b_12_2 = sym_63655_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_63655_3_parameter_rt;
    /* execute.simd:3830 [D] s_b_12_3 = ReadRegBank 17:s_b_12_2 (v4u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3831 [D] s_b_12_4 = sym_63689_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_63689_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3831 [F] s_b_12_5 = sym_63661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_63661_3_parameter_lane;
    /* execute.simd:3831 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3831 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3832 [D] s_b_12_8: WriteRegBank 17:s_b_12_2 = s_b_12_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7);
    /* execute.simd:0 [F] s_b_12_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3837 [D] s_b_13_0 = sym_63651_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_63651_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 2 s_b_13_0 => sym_63706_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_63706_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(2));
    }
    /* execute.simd:3839 [F] s_b_13_2 = sym_63655_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_63655_3_parameter_rt;
    /* execute.simd:3839 [D] s_b_13_3 = ReadRegBank 18:s_b_13_2 (v8u16) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3840 [D] s_b_13_4 = sym_63706_0_mem_value uint16_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_63706_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3840 [F] s_b_13_5 = sym_63661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_63661_3_parameter_lane;
    /* execute.simd:3840 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3840 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3841 [D] s_b_13_8: WriteRegBank 18:s_b_13_2 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7);
    /* execute.simd:0 [F] s_b_13_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_14: 
  {
    /* execute.simd:3846 [D] s_b_14_0 = sym_63651_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_63651_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_63723_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_63723_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.simd:3848 [F] s_b_14_2 = sym_63655_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_63655_3_parameter_rt;
    /* execute.simd:3848 [D] s_b_14_3 = ReadRegBank 19:s_b_14_2 (v2u32) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3849 [D] s_b_14_4 = sym_63723_0_mem_value uint32_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_63723_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3849 [F] s_b_14_5 = sym_63661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_63661_3_parameter_lane;
    /* execute.simd:3849 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3849 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3850 [D] s_b_14_8: WriteRegBank 19:s_b_14_2 = s_b_14_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7);
    /* execute.simd:0 [F] s_b_14_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3855 [D] s_b_15_0 = sym_63651_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_63651_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 4 s_b_15_0 => sym_63740_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_63740_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(4));
    }
    /* execute.simd:3857 [F] s_b_15_2 = sym_63655_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_63655_3_parameter_rt;
    /* execute.simd:3857 [D] s_b_15_3 = ReadRegBank 20:s_b_15_2 (v4u32) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3858 [D] s_b_15_4 = sym_63740_0_mem_value uint32_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_63740_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3858 [F] s_b_15_5 = sym_63661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_63661_3_parameter_lane;
    /* execute.simd:3858 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3858 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3859 [D] s_b_15_8: WriteRegBank 20:s_b_15_2 = s_b_15_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7);
    /* execute.simd:0 [F] s_b_15_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3864 [D] s_b_16_0 = sym_63651_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_63651_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_63757_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_63757_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.simd:3866 [F] s_b_16_2 = sym_63655_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_63655_3_parameter_rt;
    /* execute.simd:3866 [D] s_b_16_3 = ReadRegBank 21:s_b_16_2 (v2u64) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3867 [D] s_b_16_4 = sym_63757_0_mem_value uint64_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_63757_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3867 [F] s_b_16_5 = sym_63661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_63661_3_parameter_lane;
    /* execute.simd:3867 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3867 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3868 [D] s_b_16_8: WriteRegBank 21:s_b_16_2 = s_b_16_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7);
    /* execute.simd:0 [F] s_b_16_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_9, b_10, b_11, b_12, b_13, b_14, b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* ???:4294967295 [D] s_b_17_0 = sym_63785_1_tmp_s_b_5_5 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_63785_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1 = sym_63782_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_17_1 = CV_sym_63782_1_tmp_s_b_5_4;
    /* execute.simd:2422 [F] s_b_17_2=sym_13126_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* ???:4294967295 [D] s_b_17_4 = s_b_17_0+s_b_17_3 */
    auto s_b_17_4 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2422 [D] s_b_17_5: sym_13132_0_address = s_b_17_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13132_0_address, s_b_17_4);
    /* execute.simd:2420 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:2420 [F] s_b_17_7 = s_b_17_1+s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(s_b_17_1 + (uint8_t)1ULL));
    /* execute.simd:2420 [F] s_b_17_8: sym_13158_0_lane = s_b_17_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_13158_0_lane = s_b_17_7;
    /* execute.simd:2420 [F] s_b_17_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2701 [F] s_b_18_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_18_1 = __builtin_get_feature */
    uint32_t s_b_18_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_18_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(s_b_18_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_18_4: If s_b_18_3: Jump b_19 else b_23 (const) */
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
    /* execute.a64:2702 [D] s_b_19_0 = ReadReg 20 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_19_1: sym_63814_1__R_s_b_10_0 = s_b_19_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_63814_1__R_s_b_10_0, s_b_19_0);
    /* execute.a64:2702 [F] s_b_19_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_23,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2705 [D] s_b_20_0 = ReadReg 20 (u64) */
    auto s_b_20_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_20_1: sym_63814_1__R_s_b_10_0 = s_b_20_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_63814_1__R_s_b_10_0, s_b_20_0);
    /* execute.a64:2705 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_23,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2707 [D] s_b_21_0 = ReadReg 21 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_21_1: sym_63814_1__R_s_b_10_0 = s_b_21_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_63814_1__R_s_b_10_0, s_b_21_0);
    /* execute.a64:2707 [F] s_b_21_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19, b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2731 [D] s_b_22_0 = sym_63814_1__R_s_b_10_0 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_63814_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_22_1: sym_63601_1__R_s_b_0_5 = s_b_22_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_63601_1__R_s_b_0_5, s_b_22_0);
    /* execute.a64:2731 [F] s_b_22_2: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_18,  */
  fixed_block_b_23: 
  {
    /* execute.a64:3012 [F] s_b_23_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_23_1 = __builtin_get_feature */
    uint32_t s_b_23_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_23_2 = (u8)s_b_23_1 (const) */
    /* execute.a64:2704 [F] s_b_23_3 = (u32)s_b_23_2 (const) */
    /* execute.a64:2704 [F] s_b_23_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_23_5 = s_b_23_3==s_b_23_4 (const) */
    uint8_t s_b_23_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_23_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_23_6: If s_b_23_5: Jump b_20 else b_21 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ld4(const aarch64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_67120_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66924_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66957_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67091_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_67088_1_tmp_s_b_5_2;
  auto DV_sym_66959_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_66995_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_66978_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_67029_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_66967_3_parameter_lane;
  uint8_t CV_sym_66961_3_parameter_rt;
  auto DV_sym_67012_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_67063_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13940_0_lane;
  auto DV_sym_67046_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_13895_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13952_0_rt;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13889_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_18 else b_7 (const) */
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
    /* execute.simd:2467 [F] s_b_1_0 = sym_13940_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13940_0_lane;
    /* execute.simd:2467 [F] s_b_1_1=sym_13889_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2467 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2467 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2468 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2468 [F] s_b_2_1: sym_13952_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13952_0_rt = (uint8_t)0ULL;
    /* execute.simd:2468 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2468 [F] s_b_4_0 = sym_13952_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13952_0_rt;
    /* execute.simd:2468 [F] s_b_4_1=sym_13889_3_parameter_inst.regcnt (const) */
    /* execute.simd:2468 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2468 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2469 [F] s_b_5_0=sym_13889_3_parameter_inst.arrangement (const) */
    /* execute.simd:2469 [F] s_b_5_1=sym_13889_3_parameter_inst.rt (const) */
    /* execute.simd:2469 [F] s_b_5_2 = sym_13952_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13952_0_rt;
    /* execute.simd:2469 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2469 [F] s_b_5_4 = sym_13940_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13940_0_lane;
    /* execute.simd:2469 [D] s_b_5_5 = sym_13895_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13895_0_address, emitter.context().types().u64());
    /* execute.simd:2469 [F] s_b_5_6: sym_66961_3_parameter_rt = s_b_5_3 (const), dominates: s_b_10_2 s_b_11_2 s_b_16_2 s_b_15_2 s_b_14_2 s_b_13_2 s_b_12_2  */
    CV_sym_66961_3_parameter_rt = s_b_5_3;
    /* execute.simd:2469 [F] s_b_5_7: sym_66967_3_parameter_lane = s_b_5_4 (const), dominates: s_b_10_5 s_b_11_5 s_b_16_5 s_b_15_5 s_b_14_5 s_b_13_5 s_b_12_5  */
    CV_sym_66967_3_parameter_lane = s_b_5_4;
    /* execute.simd:2469 [D] s_b_5_8: sym_66957_3_parameter_addr = s_b_5_5, dominates: s_b_10_0 s_b_11_0 s_b_16_0 s_b_15_0 s_b_14_0 s_b_13_0 s_b_12_0  */
    emitter.store_local(DV_sym_66957_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_67088_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_17_1  */
    CV_sym_67088_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_67091_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_67091_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3808 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3817 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3826 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3835 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3844 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3853 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3862 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3807 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_9 (const) -> b_9, b_10, b_11, b_16, b_15, b_14, b_13, b_12,  */
    switch (insn.arrangement) 
    {
    case (int32_t)5ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_10;
      break;
    default:
      goto fixed_block_b_9;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2467 [F] s_b_6_0 = sym_13940_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13940_0_lane;
    /* execute.simd:2467 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2467 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2467 [F] s_b_6_3: sym_13940_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13940_0_lane = s_b_6_2;
    /* execute.simd:2467 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2733 [F] s_b_7_0=sym_13889_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_7_1 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_7_2: sym_66924_1__R_s_b_0_5 = s_b_7_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_66924_1__R_s_b_0_5, s_b_7_1);
    /* execute.a64:2733 [F] s_b_7_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_22,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2460 [D] s_b_8_0 = sym_66924_1__R_s_b_0_5 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_66924_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2460 [D] s_b_8_1: sym_13895_0_address = s_b_8_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13895_0_address, s_b_8_0);
    /* execute.simd:2462 [F] s_b_8_2=sym_13889_3_parameter_inst.rt (const) */
    /* execute.simd:2462 [F] s_b_8_3 = constant u64 0 (const) */
    /* execute.simd:2462 [F] s_b_8_4 = constant u64 0 (const) */
    /* execute.simd:6253 [F] s_b_8_5: WriteRegBank 2:s_b_8_2 = s_b_8_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6254 [F] s_b_8_6: WriteRegBank 3:s_b_8_2 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2463 [F] s_b_8_7=sym_13889_3_parameter_inst.rt (const) */
    /* execute.simd:2463 [F] s_b_8_8 = (u32)s_b_8_7 (const) */
    /* execute.simd:2463 [F] s_b_8_9 = constant u32 1 (const) */
    /* execute.simd:2463 [F] s_b_8_10 = s_b_8_8+s_b_8_9 (const) */
    uint32_t s_b_8_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2463 [F] s_b_8_11 = (u8)s_b_8_10 (const) */
    /* execute.simd:2463 [F] s_b_8_12 = constant u64 0 (const) */
    /* execute.simd:2463 [F] s_b_8_13 = constant u64 0 (const) */
    /* execute.simd:6253 [F] s_b_8_14: WriteRegBank 2:s_b_8_11 = s_b_8_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6254 [F] s_b_8_15: WriteRegBank 3:s_b_8_11 = s_b_8_13 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2464 [F] s_b_8_16=sym_13889_3_parameter_inst.rt (const) */
    /* execute.simd:2464 [F] s_b_8_17 = (u32)s_b_8_16 (const) */
    /* execute.simd:2464 [F] s_b_8_18 = constant u32 2 (const) */
    /* execute.simd:2464 [F] s_b_8_19 = s_b_8_17+s_b_8_18 (const) */
    uint32_t s_b_8_19 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)2ULL));
    /* execute.simd:2464 [F] s_b_8_20 = (u8)s_b_8_19 (const) */
    /* execute.simd:2464 [F] s_b_8_21 = constant u64 0 (const) */
    /* execute.simd:2464 [F] s_b_8_22 = constant u64 0 (const) */
    /* execute.simd:6253 [F] s_b_8_23: WriteRegBank 2:s_b_8_20 = s_b_8_21 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6254 [F] s_b_8_24: WriteRegBank 3:s_b_8_20 = s_b_8_22 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2465 [F] s_b_8_25=sym_13889_3_parameter_inst.rt (const) */
    /* execute.simd:2465 [F] s_b_8_26 = (u32)s_b_8_25 (const) */
    /* execute.simd:2465 [F] s_b_8_27 = constant u32 3 (const) */
    /* execute.simd:2465 [F] s_b_8_28 = s_b_8_26+s_b_8_27 (const) */
    uint32_t s_b_8_28 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)3ULL));
    /* execute.simd:2465 [F] s_b_8_29 = (u8)s_b_8_28 (const) */
    /* execute.simd:2465 [F] s_b_8_30 = constant u64 0 (const) */
    /* execute.simd:2465 [F] s_b_8_31 = constant u64 0 (const) */
    /* execute.simd:6253 [F] s_b_8_32: WriteRegBank 2:s_b_8_29 = s_b_8_30 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6254 [F] s_b_8_33: WriteRegBank 3:s_b_8_29 = s_b_8_31 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2467 [F] s_b_8_34 = constant u8 0 (const) */
    /* execute.simd:2467 [F] s_b_8_35: sym_13940_0_lane = s_b_8_34 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13940_0_lane = (uint8_t)0ULL;
    /* execute.simd:2467 [F] s_b_8_36: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3872 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3810 [D] s_b_10_0 = sym_66957_3_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_66957_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 1 s_b_10_0 => sym_66959_0_mem_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66959_0_mem_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(1));
    }
    /* execute.simd:3812 [F] s_b_10_2 = sym_66961_3_parameter_rt (const) uint8_t */
    uint8_t s_b_10_2 = CV_sym_66961_3_parameter_rt;
    /* execute.simd:3812 [D] s_b_10_3 = ReadRegBank 15:s_b_10_2 (v8u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:3813 [D] s_b_10_4 = sym_66959_0_mem_value uint8_t */
    auto s_b_10_4 = emitter.load_local(DV_sym_66959_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3813 [F] s_b_10_5 = sym_66967_3_parameter_lane (const) uint8_t */
    uint8_t s_b_10_5 = CV_sym_66967_3_parameter_lane;
    /* execute.simd:3813 [F] s_b_10_6 = (s32)s_b_10_5 (const) */
    /* execute.simd:3813 [D] s_b_10_7 = s_b_10_3[s_b_10_6] <= s_b_10_4 */
    auto s_b_10_7 = emitter.vector_insert(s_b_10_3, emitter.const_s32(((int32_t)s_b_10_5)), s_b_10_4);
    /* execute.simd:3814 [D] s_b_10_8: WriteRegBank 15:s_b_10_2 = s_b_10_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_7);
    /* execute.simd:0 [F] s_b_10_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3819 [D] s_b_11_0 = sym_66957_3_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_66957_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 1 s_b_11_0 => sym_66978_0_mem_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66978_0_mem_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(1));
    }
    /* execute.simd:3821 [F] s_b_11_2 = sym_66961_3_parameter_rt (const) uint8_t */
    uint8_t s_b_11_2 = CV_sym_66961_3_parameter_rt;
    /* execute.simd:3821 [D] s_b_11_3 = ReadRegBank 16:s_b_11_2 (v16u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:3822 [D] s_b_11_4 = sym_66978_0_mem_value uint8_t */
    auto s_b_11_4 = emitter.load_local(DV_sym_66978_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3822 [F] s_b_11_5 = sym_66967_3_parameter_lane (const) uint8_t */
    uint8_t s_b_11_5 = CV_sym_66967_3_parameter_lane;
    /* execute.simd:3822 [F] s_b_11_6 = (s32)s_b_11_5 (const) */
    /* execute.simd:3822 [D] s_b_11_7 = s_b_11_3[s_b_11_6] <= s_b_11_4 */
    auto s_b_11_7 = emitter.vector_insert(s_b_11_3, emitter.const_s32(((int32_t)s_b_11_5)), s_b_11_4);
    /* execute.simd:3823 [D] s_b_11_8: WriteRegBank 16:s_b_11_2 = s_b_11_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_7);
    /* execute.simd:0 [F] s_b_11_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3828 [D] s_b_12_0 = sym_66957_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_66957_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_66995_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66995_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3830 [F] s_b_12_2 = sym_66961_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_66961_3_parameter_rt;
    /* execute.simd:3830 [D] s_b_12_3 = ReadRegBank 17:s_b_12_2 (v4u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3831 [D] s_b_12_4 = sym_66995_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_66995_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3831 [F] s_b_12_5 = sym_66967_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_66967_3_parameter_lane;
    /* execute.simd:3831 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3831 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3832 [D] s_b_12_8: WriteRegBank 17:s_b_12_2 = s_b_12_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7);
    /* execute.simd:0 [F] s_b_12_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3837 [D] s_b_13_0 = sym_66957_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_66957_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 2 s_b_13_0 => sym_67012_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_67012_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(2));
    }
    /* execute.simd:3839 [F] s_b_13_2 = sym_66961_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_66961_3_parameter_rt;
    /* execute.simd:3839 [D] s_b_13_3 = ReadRegBank 18:s_b_13_2 (v8u16) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3840 [D] s_b_13_4 = sym_67012_0_mem_value uint16_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_67012_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3840 [F] s_b_13_5 = sym_66967_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_66967_3_parameter_lane;
    /* execute.simd:3840 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3840 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3841 [D] s_b_13_8: WriteRegBank 18:s_b_13_2 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7);
    /* execute.simd:0 [F] s_b_13_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_14: 
  {
    /* execute.simd:3846 [D] s_b_14_0 = sym_66957_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_66957_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_67029_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_67029_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.simd:3848 [F] s_b_14_2 = sym_66961_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_66961_3_parameter_rt;
    /* execute.simd:3848 [D] s_b_14_3 = ReadRegBank 19:s_b_14_2 (v2u32) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3849 [D] s_b_14_4 = sym_67029_0_mem_value uint32_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_67029_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3849 [F] s_b_14_5 = sym_66967_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_66967_3_parameter_lane;
    /* execute.simd:3849 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3849 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3850 [D] s_b_14_8: WriteRegBank 19:s_b_14_2 = s_b_14_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7);
    /* execute.simd:0 [F] s_b_14_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3855 [D] s_b_15_0 = sym_66957_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_66957_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 4 s_b_15_0 => sym_67046_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_67046_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(4));
    }
    /* execute.simd:3857 [F] s_b_15_2 = sym_66961_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_66961_3_parameter_rt;
    /* execute.simd:3857 [D] s_b_15_3 = ReadRegBank 20:s_b_15_2 (v4u32) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3858 [D] s_b_15_4 = sym_67046_0_mem_value uint32_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_67046_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3858 [F] s_b_15_5 = sym_66967_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_66967_3_parameter_lane;
    /* execute.simd:3858 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3858 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3859 [D] s_b_15_8: WriteRegBank 20:s_b_15_2 = s_b_15_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7);
    /* execute.simd:0 [F] s_b_15_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3864 [D] s_b_16_0 = sym_66957_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_66957_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_67063_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_67063_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.simd:3866 [F] s_b_16_2 = sym_66961_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_66961_3_parameter_rt;
    /* execute.simd:3866 [D] s_b_16_3 = ReadRegBank 21:s_b_16_2 (v2u64) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3867 [D] s_b_16_4 = sym_67063_0_mem_value uint64_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_67063_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3867 [F] s_b_16_5 = sym_66967_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_66967_3_parameter_lane;
    /* execute.simd:3867 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3867 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3868 [D] s_b_16_8: WriteRegBank 21:s_b_16_2 = s_b_16_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7);
    /* execute.simd:0 [F] s_b_16_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_9, b_10, b_11, b_12, b_13, b_14, b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* ???:4294967295 [D] s_b_17_0 = sym_67091_1_tmp_s_b_5_5 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_67091_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1 = sym_67088_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_17_1 = CV_sym_67088_1_tmp_s_b_5_2;
    /* execute.simd:2470 [F] s_b_17_2=sym_13889_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* ???:4294967295 [D] s_b_17_4 = s_b_17_0+s_b_17_3 */
    auto s_b_17_4 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2470 [D] s_b_17_5: sym_13895_0_address = s_b_17_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13895_0_address, s_b_17_4);
    /* execute.simd:2468 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:2468 [F] s_b_17_7 = s_b_17_1+s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(s_b_17_1 + (uint8_t)1ULL));
    /* execute.simd:2468 [F] s_b_17_8: sym_13952_0_rt = s_b_17_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13952_0_rt = s_b_17_7;
    /* execute.simd:2468 [F] s_b_17_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2701 [F] s_b_18_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_18_1 = __builtin_get_feature */
    uint32_t s_b_18_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_18_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(s_b_18_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_18_4: If s_b_18_3: Jump b_19 else b_23 (const) */
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
    /* execute.a64:2702 [D] s_b_19_0 = ReadReg 20 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_19_1: sym_67120_1__R_s_b_10_0 = s_b_19_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_67120_1__R_s_b_10_0, s_b_19_0);
    /* execute.a64:2702 [F] s_b_19_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_23,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2705 [D] s_b_20_0 = ReadReg 20 (u64) */
    auto s_b_20_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_20_1: sym_67120_1__R_s_b_10_0 = s_b_20_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_67120_1__R_s_b_10_0, s_b_20_0);
    /* execute.a64:2705 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_23,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2707 [D] s_b_21_0 = ReadReg 21 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_21_1: sym_67120_1__R_s_b_10_0 = s_b_21_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_67120_1__R_s_b_10_0, s_b_21_0);
    /* execute.a64:2707 [F] s_b_21_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19, b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2731 [D] s_b_22_0 = sym_67120_1__R_s_b_10_0 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_67120_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_22_1: sym_66924_1__R_s_b_0_5 = s_b_22_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_66924_1__R_s_b_0_5, s_b_22_0);
    /* execute.a64:2731 [F] s_b_22_2: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_18,  */
  fixed_block_b_23: 
  {
    /* execute.a64:3012 [F] s_b_23_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_23_1 = __builtin_get_feature */
    uint32_t s_b_23_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_23_2 = (u8)s_b_23_1 (const) */
    /* execute.a64:2704 [F] s_b_23_3 = (u32)s_b_23_2 (const) */
    /* execute.a64:2704 [F] s_b_23_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_23_5 = s_b_23_3==s_b_23_4 (const) */
    uint8_t s_b_23_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_23_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_23_6: If s_b_23_5: Jump b_20 else b_21 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldaxrh(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_80901_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_80863_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_80964_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_81019_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_81700_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14321_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_1_0=sym_14321_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_1_2: sym_80863_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_80863_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2733 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:687 [D] s_b_2_0 = sym_80863_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_80863_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:688 [D] s_b_2_1: sym_80964_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_80964_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 2 s_b_2_0 => sym_81019_0_data16 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_81019_0_data16, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(2));
    }
    /* execute.a64:1677 [D] s_b_2_3 = sym_81019_0_data16 uint16_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_81019_0_data16, emitter.context().types().u16());
    /* execute.a64:1677 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_2_5=sym_14321_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_2_8: sym_81700_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_81700_3_parameter_value, s_b_2_7);
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
    /* execute.a64:2702 [D] s_b_4_1: sym_80901_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_80901_1__R_s_b_4_0, s_b_4_0);
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
    /* execute.a64:2705 [D] s_b_5_1: sym_80901_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_80901_1__R_s_b_4_0, s_b_5_0);
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
    /* execute.a64:2707 [D] s_b_6_1: sym_80901_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_80901_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2707 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2731 [D] s_b_7_0 = sym_80901_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_80901_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_7_1: sym_80863_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_80863_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2731 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1723 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_8_1 = sym_80964_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_80964_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_10_0=sym_14321_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_10_1 = sym_81700_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_81700_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldr(const aarch64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14785_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89702_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91279_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89895_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_90228_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91783_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89511_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89999_0_data128_2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89614_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_89482_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90117_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_90041_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_90284_1__R_s_b_28_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90193_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89993_0_data128_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91805_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89830_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14779_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_28 else b_19 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_20,  */
  fixed_block_b_1: 
  {
    /* execute.a64:948 [D] s_b_1_0 = sym_14785_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* execute.a64:948 [F] s_b_1_1=sym_14779_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:948 [D] s_b_1_4: sym_14785_0_address = s_b_1_3, dominates: s_b_6_0 s_b_17_0 s_b_18_1 s_b_7_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_14785_0_address, s_b_1_3);
    /* execute.a64:948 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_20,  */
  fixed_block_b_2: 
  {
    /* execute.a64:951 [F] s_b_2_0=sym_14779_3_parameter_inst.V (const) */
    /* execute.a64:951 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:951 [F] s_b_2_2 = constant u32 0 (const) */
    /* execute.a64:951 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.V) == (uint32_t)0ULL));
    /* execute.a64:951 [F] s_b_2_4: If s_b_2_3: Jump b_3 else b_5 (const) */
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
    /* execute.a64:952 [F] s_b_3_0=sym_14779_3_parameter_inst.size (const) */
    /* execute.a64:952 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:952 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:952 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:952 [F] s_b_3_4: If s_b_3_3: Jump b_6 else b_7 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_8, b_10, b_12, b_14, b_15, b_16, b_21, b_22,  */
  fixed_block_b_4: 
  {
    /* execute.a64:971 [F] s_b_4_0=sym_14779_3_parameter_inst.P (const) */
    /* execute.a64:971 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:971 [F] s_b_4_2: If s_b_4_1: Jump b_17 else b_18 (const) */
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
    /* execute.a64:958 [F] s_b_5_0=sym_14779_3_parameter_inst.size (const) */
    /* execute.a64:958 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:958 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:958 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.a64:958 [F] s_b_5_4=sym_14779_3_parameter_inst.X (const) */
    /* execute.a64:958 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:958 [F] s_b_5_6 = constant u32 0 (const) */
    /* execute.a64:958 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:958 [F] s_b_5_12: If s_b_5_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:953 [D] s_b_6_0 = sym_14785_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* execute.a64:953 [D] s_b_6_1: sym_89511_3_parameter_address = s_b_6_0, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_89511_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 4 s_b_6_0 => sym_89614_0_data32 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_89614_0_data32, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_6_3 = sym_89614_0_data32 uint32_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_89614_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_6_4 = (u64)s_b_6_3 */
    auto s_b_6_4 = emitter.zx(s_b_6_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_5=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_6_6 = (u32)s_b_6_4 */
    auto s_b_6_6 = emitter.truncate(s_b_6_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_8: sym_91783_3_parameter_value = s_b_6_7, dominates: s_b_37_1  */
    emitter.store_local(DV_sym_91783_3_parameter_value, s_b_6_7);
    /* execute.a64:2682 [F] s_b_6_9 = (u32)s_b_6_5 (const) */
    /* execute.a64:2682 [F] s_b_6_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_6_11 = s_b_6_9==s_b_6_10 (const) */
    uint8_t s_b_6_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_6_12: If s_b_6_11: Jump b_21 else b_37 (const) */
    if (s_b_6_11) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_37;
    }
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:955 [D] s_b_7_0 = sym_14785_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* execute.a64:955 [D] s_b_7_1: sym_89702_3_parameter_address = s_b_7_0, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_89702_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 8 s_b_7_0 => sym_89830_0_data64 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_89830_0_data64, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_7_3 = sym_89830_0_data64 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_89830_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_4=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_7_5: sym_91805_3_parameter_value = s_b_7_3, dominates: s_b_38_1  */
    emitter.store_local(DV_sym_91805_3_parameter_value, s_b_7_3);
    /* execute.a64:2682 [F] s_b_7_6 = (u32)s_b_7_4 (const) */
    /* execute.a64:2682 [F] s_b_7_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_7_8 = s_b_7_6==s_b_7_7 (const) */
    uint8_t s_b_7_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_7_9: If s_b_7_8: Jump b_22 else b_38 (const) */
    if (s_b_7_8) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_38;
    }
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.a64:959 [D] s_b_8_0 = sym_14785_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_8_1 = Load 1 s_b_8_0 => sym_89895_0_data8 */
    auto s_b_8_1 = emitter.load_memory(s_b_8_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_89895_0_data8, s_b_8_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_8_0, s_b_8_1, emitter.const_u8(1));
    }
    /* execute.a64:1733 [F] s_b_8_2=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:1733 [D] s_b_8_3 = sym_89895_0_data8 uint8_t */
    auto s_b_8_3 = emitter.load_local(DV_sym_89895_0_data8, emitter.context().types().u8());
    /* execute.simd:6225 [D] s_b_8_4 = (u64)s_b_8_3 */
    auto s_b_8_4 = emitter.zx(s_b_8_3, emitter.context().types().u64());
    /* execute.simd:6225 [D] s_b_8_5: WriteRegBank 2:s_b_8_2 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_8_4);
    /* execute.simd:6226 [F] s_b_8_6 = constant u64 0 (const) */
    /* execute.simd:6226 [F] s_b_8_7: WriteRegBank 3:s_b_8_2 = s_b_8_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_8: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.a64:960 [F] s_b_9_0=sym_14779_3_parameter_inst.size (const) */
    /* execute.a64:960 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:960 [F] s_b_9_2 = constant u32 0 (const) */
    /* execute.a64:960 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.a64:960 [F] s_b_9_4=sym_14779_3_parameter_inst.X (const) */
    /* execute.a64:960 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.a64:960 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.a64:960 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.a64:960 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
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
    /* execute.a64:961 [D] s_b_10_0 = sym_14785_0_address uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 8 s_b_10_0 => sym_89993_0_data128_1 */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_89993_0_data128_1, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(8));
    }
    /* execute.a64:1763 [F] s_b_10_2 = constant u64 8 (const) */
    /* execute.a64:1763 [D] s_b_10_3 = s_b_10_0+s_b_10_2 */
    auto s_b_10_3 = emitter.add(s_b_10_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_10_4 = Load 8 s_b_10_3 => sym_89999_0_data128_2 */
    auto s_b_10_4 = emitter.load_memory(s_b_10_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_89999_0_data128_2, s_b_10_4);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_3, s_b_10_4, emitter.const_u8(8));
    }
    /* execute.a64:1765 [F] s_b_10_5=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:1765 [D] s_b_10_6 = sym_89993_0_data128_1 uint64_t */
    auto s_b_10_6 = emitter.load_local(DV_sym_89993_0_data128_1, emitter.context().types().u64());
    /* execute.a64:1765 [D] s_b_10_7 = sym_89999_0_data128_2 uint64_t */
    auto s_b_10_7 = emitter.load_local(DV_sym_89999_0_data128_2, emitter.context().types().u64());
    /* execute.simd:6253 [D] s_b_10_8: WriteRegBank 2:s_b_10_5 = s_b_10_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_6);
    /* execute.simd:6254 [D] s_b_10_9: WriteRegBank 3:s_b_10_5 = s_b_10_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_10_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_10_7);
    /* execute.simd:0 [F] s_b_10_10: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:962 [F] s_b_11_0=sym_14779_3_parameter_inst.size (const) */
    /* execute.a64:962 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:962 [F] s_b_11_2 = constant u32 1 (const) */
    /* execute.a64:962 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.a64:962 [F] s_b_11_4: If s_b_11_3: Jump b_12 else b_13 (const) */
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
    /* execute.a64:963 [D] s_b_12_0 = sym_14785_0_address uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_90041_0_data16 */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_90041_0_data16, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.a64:1740 [F] s_b_12_2=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:1740 [D] s_b_12_3 = sym_90041_0_data16 uint16_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_90041_0_data16, emitter.context().types().u16());
    /* execute.simd:6232 [D] s_b_12_4 = (u64)s_b_12_3 */
    auto s_b_12_4 = emitter.zx(s_b_12_3, emitter.context().types().u64());
    /* execute.simd:6232 [D] s_b_12_5: WriteRegBank 2:s_b_12_2 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_4);
    /* execute.simd:6233 [F] s_b_12_6 = constant u64 0 (const) */
    /* execute.simd:6233 [F] s_b_12_7: WriteRegBank 3:s_b_12_2 = s_b_12_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_12_8: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:964 [F] s_b_13_0=sym_14779_3_parameter_inst.size (const) */
    /* execute.a64:964 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:964 [F] s_b_13_2 = constant u32 2 (const) */
    /* execute.a64:964 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:964 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_15 (const) */
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
    /* execute.a64:965 [D] s_b_14_0 = sym_14785_0_address uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_90117_0_data32 */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_90117_0_data32, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.a64:1747 [F] s_b_14_2=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:1747 [D] s_b_14_3 = sym_90117_0_data32 uint32_t */
    auto s_b_14_3 = emitter.load_local(DV_sym_90117_0_data32, emitter.context().types().u32());
    /* execute.simd:6239 [D] s_b_14_4 = (u64)s_b_14_3 */
    auto s_b_14_4 = emitter.zx(s_b_14_3, emitter.context().types().u64());
    /* execute.simd:6239 [D] s_b_14_5: WriteRegBank 2:s_b_14_2 = s_b_14_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_4);
    /* execute.simd:6240 [F] s_b_14_6 = constant u64 0 (const) */
    /* execute.simd:6240 [F] s_b_14_7: WriteRegBank 3:s_b_14_2 = s_b_14_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_14_8: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_13,  */
  fixed_block_b_15: 
  {
    /* execute.a64:966 [F] s_b_15_0=sym_14779_3_parameter_inst.size (const) */
    /* execute.a64:966 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.a64:966 [F] s_b_15_2 = constant u32 3 (const) */
    /* execute.a64:966 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.a64:966 [F] s_b_15_4: If s_b_15_3: Jump b_16 else b_4 (const) */
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
    /* execute.a64:967 [D] s_b_16_0 = sym_14785_0_address uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_90193_0_data64 */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90193_0_data64, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.a64:1754 [F] s_b_16_2=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:1754 [D] s_b_16_3 = sym_90193_0_data64 uint64_t */
    auto s_b_16_3 = emitter.load_local(DV_sym_90193_0_data64, emitter.context().types().u64());
    /* execute.simd:6246 [D] s_b_16_4: WriteRegBank 2:s_b_16_2 = s_b_16_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_3);
    /* execute.simd:6247 [F] s_b_16_5 = constant u64 0 (const) */
    /* execute.simd:6247 [F] s_b_16_6: WriteRegBank 3:s_b_16_2 = s_b_16_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_16_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_4,  */
  fixed_block_b_17: 
  {
    /* execute.a64:972 [D] s_b_17_0 = sym_14785_0_address uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* execute.a64:972 [F] s_b_17_1=sym_14779_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_17_2 = (u64)s_b_17_1 (const) */
    /* ???:4294967295 [D] s_b_17_3 = s_b_17_0+s_b_17_2 */
    auto s_b_17_3 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:972 [D] s_b_17_4: sym_14785_0_address = s_b_17_3, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_14785_0_address, s_b_17_3);
    /* execute.a64:972 [F] s_b_17_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:975 [F] s_b_18_0 = constant u8 1 (const) */
    /* execute.a64:975 [D] s_b_18_1 = sym_14785_0_address uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_14785_0_address, emitter.context().types().u64());
    /* execute.a64:975 [D] s_b_18_2: sym_90228_3_parameter_value = s_b_18_1, dominates: s_b_23_0 s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_90228_3_parameter_value, s_b_18_1);
    /* execute.a64:2746 [F] s_b_18_3 = !s_b_18_0 (const) */
    uint8_t s_b_18_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_18_4: If s_b_18_3: Jump b_23 else b_24 (const) */
    if (s_b_18_3) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_0,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2733 [F] s_b_19_0=sym_14779_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_19_1 = ReadRegBank 0:s_b_19_0 (u64) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_19_2: sym_89482_1__R_s_b_0_5 = s_b_19_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_89482_1__R_s_b_0_5, s_b_19_1);
    /* execute.a64:2733 [F] s_b_19_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_19, b_32,  */
  fixed_block_b_20: 
  {
    /* execute.a64:945 [D] s_b_20_0 = sym_89482_1__R_s_b_0_5 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_89482_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:945 [D] s_b_20_1: sym_14785_0_address = s_b_20_0, dominates: s_b_1_0 s_b_6_0 s_b_17_0 s_b_18_1 s_b_7_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_14785_0_address, s_b_20_0);
    /* execute.a64:947 [F] s_b_20_2=sym_14779_3_parameter_inst.P (const) */
    /* execute.a64:947 [F] s_b_20_3: If s_b_20_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_6, b_37,  */
  fixed_block_b_21: 
  {
    /* execute.a64:1723 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_21_1 = sym_89511_3_parameter_address uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_89511_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_21_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_21_1);
    /* execute.a64:0 [F] s_b_21_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_38,  */
  fixed_block_b_22: 
  {
    /* execute.a64:1723 [F] s_b_22_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_22_1 = sym_89702_3_parameter_address uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_89702_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_22_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_22_1);
    /* execute.a64:0 [F] s_b_22_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_18,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2747 [D] s_b_23_0 = sym_90228_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_90228_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_23_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_23_2 = s_b_23_0&s_b_23_1 */
    auto s_b_23_2 = emitter.bitwise_and(s_b_23_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_23_3: sym_90228_3_parameter_value = s_b_23_2, dominates: s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_90228_3_parameter_value, s_b_23_2);
    /* execute.a64:2747 [F] s_b_23_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_18, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2750 [F] s_b_24_0=sym_14779_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:2750 [F] s_b_24_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_24_4: If s_b_24_3: Jump b_25 else b_26 (const) */
    if (s_b_24_3) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_24,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2751 [D] s_b_25_0 = sym_90228_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_90228_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_25_1: sym_91279_3_parameter_value = s_b_25_0, dominates: s_b_33_0 s_b_34_0 s_b_35_0  */
    emitter.store_local(DV_sym_91279_3_parameter_value, s_b_25_0);
    /* execute.a64:2714 [F] s_b_25_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_25_3 = __builtin_get_feature */
    uint32_t s_b_25_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_25_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_25_5 = s_b_25_3==s_b_25_4 (const) */
    uint8_t s_b_25_5 = ((uint8_t)(s_b_25_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_25_6: If s_b_25_5: Jump b_33 else b_39 (const) */
    if (s_b_25_5) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_39;
    }
  }
  /* b_24,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2753 [F] s_b_26_0=sym_14779_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_26_1 = sym_90228_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_90228_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_26_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_26_1);
    /* execute.a64:2753 [F] s_b_26_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_26, b_33, b_34, b_35,  */
  fixed_block_b_27: 
  {
    /* ???:4294967295 [F] s_b_27_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2701 [F] s_b_28_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_28_1 = __builtin_get_feature */
    uint32_t s_b_28_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_28_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(s_b_28_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_28_4: If s_b_28_3: Jump b_29 else b_36 (const) */
    if (s_b_28_3) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_36;
    }
  }
  /* b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2702 [D] s_b_29_0 = ReadReg 20 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_29_1: sym_90284_1__R_s_b_28_0 = s_b_29_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_90284_1__R_s_b_28_0, s_b_29_0);
    /* execute.a64:2702 [F] s_b_29_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_36,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2705 [D] s_b_30_0 = ReadReg 20 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_30_1: sym_90284_1__R_s_b_28_0 = s_b_30_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_90284_1__R_s_b_28_0, s_b_30_0);
    /* execute.a64:2705 [F] s_b_30_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_36,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2707 [D] s_b_31_0 = ReadReg 21 (u64) */
    auto s_b_31_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_31_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_31_1: sym_90284_1__R_s_b_28_0 = s_b_31_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_90284_1__R_s_b_28_0, s_b_31_0);
    /* execute.a64:2707 [F] s_b_31_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_29, b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2731 [D] s_b_32_0 = sym_90284_1__R_s_b_28_0 uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_90284_1__R_s_b_28_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_32_1: sym_89482_1__R_s_b_0_5 = s_b_32_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_89482_1__R_s_b_0_5, s_b_32_0);
    /* execute.a64:2731 [F] s_b_32_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_25,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2715 [D] s_b_33_0 = sym_91279_3_parameter_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_91279_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_33_1: WriteReg 20 = s_b_33_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_33_0);
    /* execute.a64:2715 [F] s_b_33_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_39,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2718 [D] s_b_34_0 = sym_91279_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_91279_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_34_1: WriteReg 20 = s_b_34_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_34_0);
    /* execute.a64:2718 [F] s_b_34_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_39,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2720 [D] s_b_35_0 = sym_91279_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_91279_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_35_1: WriteReg 21 = s_b_35_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_35_0);
    /* execute.a64:2720 [F] s_b_35_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_28,  */
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
    /* execute.a64:2704 [F] s_b_36_6: If s_b_36_5: Jump b_30 else b_31 (const) */
    if (s_b_36_5) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_6,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2684 [F] s_b_37_0=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_37_1 = sym_91783_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_91783_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_37_2: WriteRegBank 0:s_b_37_0 = s_b_37_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_37_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_37_1);
    /* execute.a64:0 [F] s_b_37_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_7,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2684 [F] s_b_38_0=sym_14779_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_38_1 = sym_91805_3_parameter_value uint64_t */
    auto s_b_38_1 = emitter.load_local(DV_sym_91805_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_38_2: WriteRegBank 0:s_b_38_0 = s_b_38_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_38_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_38_1);
    /* execute.a64:0 [F] s_b_38_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_25,  */
  fixed_block_b_39: 
  {
    /* execute.a64:3012 [F] s_b_39_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_39_1 = __builtin_get_feature */
    uint32_t s_b_39_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_39_2 = (u8)s_b_39_1 (const) */
    /* execute.a64:2717 [F] s_b_39_3 = (u32)s_b_39_2 (const) */
    /* execute.a64:2717 [F] s_b_39_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_39_5 = s_b_39_3==s_b_39_4 (const) */
    uint8_t s_b_39_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_39_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_39_6: If s_b_39_5: Jump b_34 else b_35 (const) */
    if (s_b_39_5) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldrh(const aarch64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_102780_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_103055_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_103000_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_104263_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102864_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_103246_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_103428_1__R_s_b_14_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_103372_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_103191_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102809_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105589_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_104591_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105101_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_15782_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_15776_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_20 else b_10 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_11,  */
  fixed_block_b_1: 
  {
    /* execute.a64:923 [D] s_b_1_0 = sym_15782_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15782_0_address, emitter.context().types().u64());
    /* execute.a64:923 [F] s_b_1_1=sym_15776_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:923 [D] s_b_1_4: sym_15782_0_address = s_b_1_3, dominates: s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15782_0_address, s_b_1_3);
    /* execute.a64:923 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_11,  */
  fixed_block_b_2: 
  {
    /* execute.a64:926 [F] s_b_2_0=sym_15776_3_parameter_inst.X (const) */
    /* execute.a64:926 [F] s_b_2_1: If s_b_2_0: Jump b_3 else b_5 (const) */
    if (insn.X) 
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
    /* execute.a64:927 [F] s_b_3_0=sym_15776_3_parameter_inst.L (const) */
    /* execute.a64:927 [F] s_b_3_1: If s_b_3_0: Jump b_6 else b_7 (const) */
    if (insn.L) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_12, b_13, b_14,  */
  fixed_block_b_4: 
  {
    /* execute.a64:936 [F] s_b_4_0=sym_15776_3_parameter_inst.P (const) */
    /* execute.a64:936 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:936 [F] s_b_4_2: If s_b_4_1: Jump b_8 else b_9 (const) */
    if (s_b_4_1) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_2,  */
  fixed_block_b_5: 
  {
    /* execute.a64:933 [D] s_b_5_0 = sym_15782_0_address uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_15782_0_address, emitter.context().types().u64());
    /* execute.a64:933 [D] s_b_5_1: sym_102809_3_parameter_address = s_b_5_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_102809_3_parameter_address, s_b_5_0);
    /* ???:4294967295 [D] s_b_5_2 = Load 2 s_b_5_0 => sym_102864_0_data16 */
    auto s_b_5_2 = emitter.load_memory(s_b_5_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_102864_0_data16, s_b_5_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_5_0, s_b_5_2, emitter.const_u8(2));
    }
    /* execute.a64:1677 [D] s_b_5_3 = sym_102864_0_data16 uint16_t */
    auto s_b_5_3 = emitter.load_local(DV_sym_102864_0_data16, emitter.context().types().u16());
    /* execute.a64:1677 [D] s_b_5_4 = (u64)s_b_5_3 */
    auto s_b_5_4 = emitter.zx(s_b_5_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_5_5=sym_15776_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_5_6 = (u32)s_b_5_4 */
    auto s_b_5_6 = emitter.truncate(s_b_5_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_5_8: sym_104591_3_parameter_value = s_b_5_7, dominates: s_b_29_1  */
    emitter.store_local(DV_sym_104591_3_parameter_value, s_b_5_7);
    /* execute.a64:2682 [F] s_b_5_9 = (u32)s_b_5_5 (const) */
    /* execute.a64:2682 [F] s_b_5_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_5_11 = s_b_5_9==s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_5_12: If s_b_5_11: Jump b_12 else b_29 (const) */
    if (s_b_5_11) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.a64:928 [D] s_b_6_0 = sym_15782_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_15782_0_address, emitter.context().types().u64());
    /* execute.a64:928 [D] s_b_6_1: sym_103000_3_parameter_address = s_b_6_0, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_103000_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 2 s_b_6_0 => sym_103055_0_data16 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_103055_0_data16, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(2));
    }
    /* execute.a64:1679 [D] s_b_6_3 = sym_103055_0_data16 uint16_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_103055_0_data16, emitter.context().types().u16());
    /* execute.a64:1679 [D] s_b_6_4 = (s16)s_b_6_3 */
    auto s_b_6_4 = emitter.reinterpret(s_b_6_3, emitter.context().types().s16());
    /* execute.a64:1679 [D] s_b_6_5 = (s64)s_b_6_4 */
    auto s_b_6_5 = emitter.sx(s_b_6_4, emitter.context().types().s64());
    /* execute.a64:1679 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.reinterpret(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_7=sym_15776_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_6_8 = (u32)s_b_6_6 */
    auto s_b_6_8 = emitter.truncate(s_b_6_6, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_10: sym_105101_3_parameter_value = s_b_6_9, dominates: s_b_30_1  */
    emitter.store_local(DV_sym_105101_3_parameter_value, s_b_6_9);
    /* execute.a64:2682 [F] s_b_6_11 = (u32)s_b_6_7 (const) */
    /* execute.a64:2682 [F] s_b_6_12 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_6_13 = s_b_6_11==s_b_6_12 (const) */
    uint8_t s_b_6_13 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_6_14: If s_b_6_13: Jump b_13 else b_30 (const) */
    if (s_b_6_13) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:930 [D] s_b_7_0 = sym_15782_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_15782_0_address, emitter.context().types().u64());
    /* execute.a64:930 [D] s_b_7_1: sym_103191_3_parameter_address = s_b_7_0, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_103191_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 2 s_b_7_0 => sym_103246_0_data16 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_103246_0_data16, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(2));
    }
    /* execute.a64:1681 [D] s_b_7_3 = sym_103246_0_data16 uint16_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_103246_0_data16, emitter.context().types().u16());
    /* execute.a64:1681 [D] s_b_7_4 = (s16)s_b_7_3 */
    auto s_b_7_4 = emitter.reinterpret(s_b_7_3, emitter.context().types().s16());
    /* execute.a64:1681 [D] s_b_7_5 = (s64)s_b_7_4 */
    auto s_b_7_5 = emitter.sx(s_b_7_4, emitter.context().types().s64());
    /* execute.a64:1681 [D] s_b_7_6 = (u64)s_b_7_5 */
    auto s_b_7_6 = emitter.reinterpret(s_b_7_5, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_7=sym_15776_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_7_8: sym_105589_3_parameter_value = s_b_7_6, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_105589_3_parameter_value, s_b_7_6);
    /* execute.a64:2682 [F] s_b_7_9 = (u32)s_b_7_7 (const) */
    /* execute.a64:2682 [F] s_b_7_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_7_11 = s_b_7_9==s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_7_12: If s_b_7_11: Jump b_14 else b_31 (const) */
    if (s_b_7_11) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:937 [D] s_b_8_0 = sym_15782_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_15782_0_address, emitter.context().types().u64());
    /* execute.a64:937 [F] s_b_8_1=sym_15776_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_8_2 = (u64)s_b_8_1 (const) */
    /* ???:4294967295 [D] s_b_8_3 = s_b_8_0+s_b_8_2 */
    auto s_b_8_3 = emitter.add(s_b_8_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:937 [D] s_b_8_4: sym_15782_0_address = s_b_8_3, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_15782_0_address, s_b_8_3);
    /* execute.a64:937 [F] s_b_8_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:940 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:940 [D] s_b_9_1 = sym_15782_0_address uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_15782_0_address, emitter.context().types().u64());
    /* execute.a64:940 [D] s_b_9_2: sym_103372_3_parameter_value = s_b_9_1, dominates: s_b_15_0 s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_103372_3_parameter_value, s_b_9_1);
    /* execute.a64:2746 [F] s_b_9_3 = !s_b_9_0 (const) */
    uint8_t s_b_9_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_9_4: If s_b_9_3: Jump b_15 else b_16 (const) */
    if (s_b_9_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2733 [F] s_b_10_0=sym_15776_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_10_2: sym_102780_1__R_s_b_0_5 = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_102780_1__R_s_b_0_5, s_b_10_1);
    /* execute.a64:2733 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_24,  */
  fixed_block_b_11: 
  {
    /* execute.a64:920 [D] s_b_11_0 = sym_102780_1__R_s_b_0_5 uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_102780_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:920 [D] s_b_11_1: sym_15782_0_address = s_b_11_0, dominates: s_b_1_0 s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15782_0_address, s_b_11_0);
    /* execute.a64:922 [F] s_b_11_2=sym_15776_3_parameter_inst.P (const) */
    /* execute.a64:922 [F] s_b_11_3: If s_b_11_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_5, b_29,  */
  fixed_block_b_12: 
  {
    /* execute.a64:1723 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_12_1 = sym_102809_3_parameter_address uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_102809_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_12_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_12_1);
    /* execute.a64:0 [F] s_b_12_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_6, b_30,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1723 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_13_1 = sym_103000_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_103000_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_31,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1723 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_14_1 = sym_103191_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_103191_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_14_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2747 [D] s_b_15_0 = sym_103372_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_103372_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_15_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_15_2 = s_b_15_0&s_b_15_1 */
    auto s_b_15_2 = emitter.bitwise_and(s_b_15_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_15_3: sym_103372_3_parameter_value = s_b_15_2, dominates: s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_103372_3_parameter_value, s_b_15_2);
    /* execute.a64:2747 [F] s_b_15_4: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_9, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2750 [F] s_b_16_0=sym_15776_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2750 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
    if (s_b_16_3) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2751 [D] s_b_17_0 = sym_103372_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_103372_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_17_1: sym_104263_3_parameter_value = s_b_17_0, dominates: s_b_25_0 s_b_26_0 s_b_27_0  */
    emitter.store_local(DV_sym_104263_3_parameter_value, s_b_17_0);
    /* execute.a64:2714 [F] s_b_17_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_17_3 = __builtin_get_feature */
    uint32_t s_b_17_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_17_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_17_5 = s_b_17_3==s_b_17_4 (const) */
    uint8_t s_b_17_5 = ((uint8_t)(s_b_17_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_17_6: If s_b_17_5: Jump b_25 else b_32 (const) */
    if (s_b_17_5) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2753 [F] s_b_18_0=sym_15776_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_18_1 = sym_103372_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_103372_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1);
    /* execute.a64:2753 [F] s_b_18_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_18, b_25, b_26, b_27,  */
  fixed_block_b_19: 
  {
    /* ???:4294967295 [F] s_b_19_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2701 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_20_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_20_4: If s_b_20_3: Jump b_21 else b_28 (const) */
    if (s_b_20_3) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_28;
    }
  }
  /* b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2702 [D] s_b_21_0 = ReadReg 20 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_21_1: sym_103428_1__R_s_b_14_0 = s_b_21_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_103428_1__R_s_b_14_0, s_b_21_0);
    /* execute.a64:2702 [F] s_b_21_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_28,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2705 [D] s_b_22_0 = ReadReg 20 (u64) */
    auto s_b_22_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_22_1: sym_103428_1__R_s_b_14_0 = s_b_22_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_103428_1__R_s_b_14_0, s_b_22_0);
    /* execute.a64:2705 [F] s_b_22_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_28,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2707 [D] s_b_23_0 = ReadReg 21 (u64) */
    auto s_b_23_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_23_1: sym_103428_1__R_s_b_14_0 = s_b_23_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_103428_1__R_s_b_14_0, s_b_23_0);
    /* execute.a64:2707 [F] s_b_23_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2731 [D] s_b_24_0 = sym_103428_1__R_s_b_14_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_103428_1__R_s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_24_1: sym_102780_1__R_s_b_0_5 = s_b_24_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_102780_1__R_s_b_0_5, s_b_24_0);
    /* execute.a64:2731 [F] s_b_24_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_17,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2715 [D] s_b_25_0 = sym_104263_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_104263_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_25_1: WriteReg 20 = s_b_25_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_25_0);
    /* execute.a64:2715 [F] s_b_25_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_32,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2718 [D] s_b_26_0 = sym_104263_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_104263_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_26_1: WriteReg 20 = s_b_26_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_26_0);
    /* execute.a64:2718 [F] s_b_26_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_32,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2720 [D] s_b_27_0 = sym_104263_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_104263_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_27_1: WriteReg 21 = s_b_27_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_27_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_27_0);
    /* execute.a64:2720 [F] s_b_27_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_20,  */
  fixed_block_b_28: 
  {
    /* execute.a64:3012 [F] s_b_28_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_28_1 = __builtin_get_feature */
    uint32_t s_b_28_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_28_2 = (u8)s_b_28_1 (const) */
    /* execute.a64:2704 [F] s_b_28_3 = (u32)s_b_28_2 (const) */
    /* execute.a64:2704 [F] s_b_28_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
    uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_28_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_28_6: If s_b_28_5: Jump b_22 else b_23 (const) */
    if (s_b_28_5) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_5,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2684 [F] s_b_29_0=sym_15776_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_29_1 = sym_104591_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_104591_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_29_2: WriteRegBank 0:s_b_29_0 = s_b_29_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_29_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_29_1);
    /* execute.a64:0 [F] s_b_29_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_6,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2684 [F] s_b_30_0=sym_15776_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_30_1 = sym_105101_3_parameter_value uint64_t */
    auto s_b_30_1 = emitter.load_local(DV_sym_105101_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_30_2: WriteRegBank 0:s_b_30_0 = s_b_30_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_30_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_30_1);
    /* execute.a64:0 [F] s_b_30_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_7,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2684 [F] s_b_31_0=sym_15776_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_31_1 = sym_105589_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_105589_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_31_2: WriteRegBank 0:s_b_31_0 = s_b_31_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1);
    /* execute.a64:0 [F] s_b_31_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_17,  */
  fixed_block_b_32: 
  {
    /* execute.a64:3012 [F] s_b_32_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_32_1 = __builtin_get_feature */
    uint32_t s_b_32_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_32_2 = (u8)s_b_32_1 (const) */
    /* execute.a64:2717 [F] s_b_32_3 = (u32)s_b_32_2 (const) */
    /* execute.a64:2717 [F] s_b_32_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_32_5 = s_b_32_3==s_b_32_4 (const) */
    uint8_t s_b_32_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_32_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_32_6: If s_b_32_5: Jump b_26 else b_27 (const) */
    if (s_b_32_5) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldtrb(const aarch64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldxr(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_115655_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16546_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115727_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115307_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_116793_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115336_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115439_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_115527_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_116771_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_16540_3_parameter_inst.rn (const) */
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
    /* execute.a64:796 [D] s_b_1_0 = sym_16546_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16546_0_address, emitter.context().types().u64());
    /* execute.a64:796 [D] s_b_1_1: sym_115336_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_115336_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2 = Load 4 s_b_1_0 => sym_115439_0_data32 */
    auto s_b_1_2 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_115439_0_data32, s_b_1_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_2, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_1_3 = sym_115439_0_data32 uint32_t */
    auto s_b_1_3 = emitter.load_local(DV_sym_115439_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_5=sym_16540_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_6 = (u32)s_b_1_4 */
    auto s_b_1_6 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_8: sym_116771_3_parameter_value = s_b_1_7, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_116771_3_parameter_value, s_b_1_7);
    /* execute.a64:2682 [F] s_b_1_9 = (u32)s_b_1_5 (const) */
    /* execute.a64:2682 [F] s_b_1_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_1_11 = s_b_1_9==s_b_1_10 (const) */
    uint8_t s_b_1_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_1_12: If s_b_1_11: Jump b_6 else b_14 (const) */
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
    /* execute.a64:798 [D] s_b_3_0 = sym_16546_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_16546_0_address, emitter.context().types().u64());
    /* execute.a64:798 [D] s_b_3_1: sym_115527_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_115527_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2 = Load 8 s_b_3_0 => sym_115655_0_data64 */
    auto s_b_3_2 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_115655_0_data64, s_b_3_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_3_3 = sym_115655_0_data64 uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_115655_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_3_4=sym_16540_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_3_5: sym_116793_3_parameter_value = s_b_3_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_116793_3_parameter_value, s_b_3_3);
    /* execute.a64:2682 [F] s_b_3_6 = (u32)s_b_3_4 (const) */
    /* execute.a64:2682 [F] s_b_3_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_3_8 = s_b_3_6==s_b_3_7 (const) */
    uint8_t s_b_3_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_3_9: If s_b_3_8: Jump b_7 else b_15 (const) */
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
    /* execute.a64:2733 [F] s_b_4_0=sym_16540_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_4_2: sym_115307_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_115307_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2733 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:793 [D] s_b_5_0 = sym_115307_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_115307_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:793 [D] s_b_5_1: sym_16546_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_16546_0_address, s_b_5_0);
    /* execute.a64:795 [F] s_b_5_2=sym_16540_3_parameter_inst.size (const) */
    /* execute.a64:795 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:795 [F] s_b_5_4 = constant u32 2 (const) */
    /* execute.a64:795 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:795 [F] s_b_5_6: If s_b_5_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1723 [F] s_b_6_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_6_1 = sym_115336_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_115336_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* execute.a64:0 [F] s_b_6_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3, b_15,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1723 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_7_1 = sym_115527_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_115527_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* execute.a64:0 [F] s_b_7_3: Jump b_2 (const) */
    goto fixed_block_b_2;
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
    /* execute.a64:2701 [F] s_b_8_4: If s_b_8_3: Jump b_9 else b_13 (const) */
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
    /* execute.a64:2702 [D] s_b_9_0 = ReadReg 20 (u64) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_9_1: sym_115727_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_115727_1__R_s_b_7_0, s_b_9_0);
    /* execute.a64:2702 [F] s_b_9_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2705 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_10_1: sym_115727_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_115727_1__R_s_b_7_0, s_b_10_0);
    /* execute.a64:2705 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2707 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_11_1: sym_115727_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_115727_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2707 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2731 [D] s_b_12_0 = sym_115727_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_115727_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_12_1: sym_115307_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_115307_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2731 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_8,  */
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
    /* execute.a64:2704 [F] s_b_13_6: If s_b_13_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2684 [F] s_b_14_0=sym_16540_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_116771_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_116771_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2684 [F] s_b_15_0=sym_16540_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_116793_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_116793_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_15_1,emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_movi(const aarch64_decode_a64_SIMD_MOD_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4918 [F] s_b_0_0=sym_16905_3_parameter_inst.Q (const) */
    /* execute.simd:4918 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4918 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4918 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:4918 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4919 [F] s_b_1_0=sym_16905_3_parameter_inst.rd (const) */
    /* execute.simd:4919 [F] s_b_1_1=sym_16905_3_parameter_inst.immu64 (const) */
    /* execute.simd:6246 [F] s_b_1_2: WriteRegBank 2:s_b_1_0 = s_b_1_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6247 [F] s_b_1_3 = constant u64 0 (const) */
    /* execute.simd:6247 [F] s_b_1_4: WriteRegBank 3:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_5: Jump b_2 (const) */
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
    /* execute.simd:4921 [F] s_b_3_0=sym_16905_3_parameter_inst.rd (const) */
    /* execute.simd:4921 [F] s_b_3_1=sym_16905_3_parameter_inst.immu64 (const) */
    /* execute.simd:4921 [F] s_b_3_2=sym_16905_3_parameter_inst.immu64 (const) */
    /* execute.simd:6253 [F] s_b_3_3: WriteRegBank 2:s_b_3_0 = s_b_3_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6254 [F] s_b_3_4: WriteRegBank 3:s_b_3_0 = s_b_3_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:0 [F] s_b_3_5: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_msub(const aarch64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_123838_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123816_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123597_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123668_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123734_1_tmp_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123786_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123726_1__R_s_b_12_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123737_1_tmp_s_b_12_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123660_1__R_s_b_4_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2349 [F] s_b_0_0=sym_18915_3_parameter_inst.sf (const) */
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
    /* execute.a64:2657 [F] s_b_1_0=sym_18915_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2651 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_1_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_1_5 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 */
    dbt::el::Value *s_b_1_6;
    s_b_1_6 = (s_b_1_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_1_5);
    /* execute.a64:2657 [D] s_b_1_7: sym_123597_1__R_s_b_0_4 = s_b_1_6, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_123597_1__R_s_b_0_4, s_b_1_6);
    /* execute.a64:2657 [F] s_b_1_8: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2659 [F] s_b_2_0=sym_18915_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2646 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_2_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_2_5 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_2_6: Select s_b_2_3 ? s_b_2_4 : s_b_2_5 */
    dbt::el::Value *s_b_2_6;
    s_b_2_6 = (s_b_2_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_2_5);
    /* execute.a64:2659 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_2_8: sym_123597_1__R_s_b_0_4 = s_b_2_7, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_123597_1__R_s_b_0_4, s_b_2_7);
    /* execute.a64:2659 [F] s_b_2_9: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2349 [D] s_b_3_0 = sym_123597_1__R_s_b_0_4 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_123597_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2350 [F] s_b_3_1=sym_18915_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_123668_1_tmp_s_b_4_0 = s_b_3_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_123668_1_tmp_s_b_4_0, s_b_3_0);
    /* execute.a64:2656 [F] s_b_3_3: If s_b_3_1: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2657 [F] s_b_4_0=sym_18915_3_parameter_inst.rm (const) */
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
    /* execute.a64:2657 [D] s_b_4_7: sym_123660_1__R_s_b_4_5 = s_b_4_6, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_123660_1__R_s_b_4_5, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_18915_3_parameter_inst.rm (const) */
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
    /* execute.a64:2659 [D] s_b_5_8: sym_123660_1__R_s_b_4_5 = s_b_5_7, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_123660_1__R_s_b_4_5, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_123668_1_tmp_s_b_4_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_123668_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2350 [D] s_b_6_1 = sym_123660_1__R_s_b_4_5 uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_123660_1__R_s_b_4_5, emitter.context().types().u64());
    /* execute.a64:2351 [F] s_b_6_2=sym_18915_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_6_3: sym_123734_1_tmp_s_b_12_0 = s_b_6_0, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_123734_1_tmp_s_b_12_0, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_4: sym_123737_1_tmp_s_b_12_1 = s_b_6_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_123737_1_tmp_s_b_12_1, s_b_6_1);
    /* execute.a64:2656 [F] s_b_6_5: If s_b_6_2: Jump b_7 else b_8 (const) */
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
  fixed_block_b_7: 
  {
    /* execute.a64:2657 [F] s_b_7_0=sym_18915_3_parameter_inst.ra (const) */
    /* execute.a64:2651 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2651 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_7_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_7_5 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_7_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_7_6: Select s_b_7_3 ? s_b_7_4 : s_b_7_5 */
    dbt::el::Value *s_b_7_6;
    s_b_7_6 = (s_b_7_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_7_5);
    /* execute.a64:2657 [D] s_b_7_7: sym_123726_1__R_s_b_12_6 = s_b_7_6, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_123726_1__R_s_b_12_6, s_b_7_6);
    /* execute.a64:2657 [F] s_b_7_8: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2659 [F] s_b_8_0=sym_18915_3_parameter_inst.ra (const) */
    /* execute.a64:2646 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2646 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_8_5 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_8_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2659 [D] s_b_8_7 = (u64)s_b_8_6 */
    auto s_b_8_7 = emitter.zx(s_b_8_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_8_8: sym_123726_1__R_s_b_12_6 = s_b_8_7, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_123726_1__R_s_b_12_6, s_b_8_7);
    /* execute.a64:2659 [F] s_b_8_9: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_123737_1_tmp_s_b_12_1 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_123737_1_tmp_s_b_12_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1 = sym_123734_1_tmp_s_b_12_0 uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_123734_1_tmp_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2351 [D] s_b_9_2 = sym_123726_1__R_s_b_12_6 uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_123726_1__R_s_b_12_6, emitter.context().types().u64());
    /* execute.a64:2353 [D] s_b_9_3 = (u64)s_b_9_1 */
    auto s_b_9_3 = (dbt::el::Value *)s_b_9_1;
    /* execute.a64:2353 [D] s_b_9_4 = s_b_9_3*s_b_9_0 */
    auto s_b_9_4 = emitter.mul(s_b_9_3, s_b_9_0);
    /* execute.a64:2353 [D] s_b_9_5 = s_b_9_2-s_b_9_4 */
    auto s_b_9_5 = emitter.sub(s_b_9_2, s_b_9_4);
    /* execute.a64:2354 [F] s_b_9_6=sym_18915_3_parameter_inst.sf (const) */
    /* execute.a64:2354 [D] s_b_9_7: sym_123786_3_parameter_value = s_b_9_5, dominates: s_b_10_1 s_b_11_1  */
    emitter.store_local(DV_sym_123786_3_parameter_value, s_b_9_5);
    /* execute.a64:2690 [F] s_b_9_8: If s_b_9_6: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2691 [F] s_b_10_0=sym_18915_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_10_1 = sym_123786_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_123786_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_10_2: sym_123816_3_parameter_value = s_b_10_1, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_123816_3_parameter_value, s_b_10_1);
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
    /* execute.a64:2693 [F] s_b_11_0=sym_18915_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_11_1 = sym_123786_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_123786_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_2 = (u32)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_4: sym_123838_3_parameter_value = s_b_11_3, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_123838_3_parameter_value, s_b_11_3);
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
    /* execute.a64:2684 [F] s_b_13_0=sym_18915_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_13_1 = sym_123816_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_123816_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_14_0=sym_18915_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_123838_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_123838_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_orri(const aarch64_decode_a64_LOGICAL_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_124386_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124222_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124274_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124237_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124351_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19435_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:215 [F] s_b_0_0=sym_19430_3_parameter_inst.sf (const) */
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
    /* execute.a64:218 [D] s_b_1_0 = sym_19435_0_op1 uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_19435_0_op1, emitter.context().types().u64());
    /* execute.a64:218 [F] s_b_1_1=sym_19430_3_parameter_inst.immu64 (const) */
    /* execute.a64:218 [D] s_b_1_2 = s_b_1_0|s_b_1_1 */
    auto s_b_1_2 = emitter.bitwise_or(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.a64:219 [F] s_b_1_3 = constant u8 1 (const) */
    /* execute.a64:219 [D] s_b_1_4: sym_124237_3_parameter_value = s_b_1_2, dominates: s_b_7_0 s_b_9_0 s_b_10_1  */
    emitter.store_local(DV_sym_124237_3_parameter_value, s_b_1_2);
    /* execute.a64:2746 [F] s_b_1_5 = !s_b_1_3 (const) */
    uint8_t s_b_1_5 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_1_6: If s_b_1_5: Jump b_7 else b_8 (const) */
    if (s_b_1_5) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_10, b_14, b_15, b_16, b_17, b_18, b_19, b_20,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_6,  */
  fixed_block_b_3: 
  {
    /* execute.a64:221 [D] s_b_3_0 = sym_19435_0_op1 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_19435_0_op1, emitter.context().types().u64());
    /* execute.a64:221 [D] s_b_3_1 = (u32)s_b_3_0 */
    auto s_b_3_1 = emitter.truncate(s_b_3_0, emitter.context().types().u32());
    /* execute.a64:221 [F] s_b_3_2=sym_19430_3_parameter_inst.immu32 (const) */
    /* execute.a64:221 [D] s_b_3_3 = s_b_3_1|s_b_3_2 */
    auto s_b_3_3 = emitter.bitwise_or(s_b_3_1, emitter.const_u32(insn.immu32));
    /* execute.a64:222 [F] s_b_3_4 = constant u8 0 (const) */
    /* execute.a64:222 [D] s_b_3_5 = (u64)s_b_3_3 */
    auto s_b_3_5 = emitter.zx(s_b_3_3, emitter.context().types().u64());
    /* execute.a64:222 [D] s_b_3_6: sym_124274_3_parameter_value = s_b_3_5, dominates: s_b_11_0 s_b_13_0 s_b_14_1  */
    emitter.store_local(DV_sym_124274_3_parameter_value, s_b_3_5);
    /* execute.a64:2746 [F] s_b_3_7 = !s_b_3_4 (const) */
    uint8_t s_b_3_7 = !(uint8_t)0ULL;
    /* execute.a64:2746 [F] s_b_3_8: If s_b_3_7: Jump b_11 else b_12 (const) */
    if (s_b_3_7) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2657 [F] s_b_4_0=sym_19430_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2651 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_4_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_4_5 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2657 [D] s_b_4_7: sym_124222_1__R_s_b_0_4 = s_b_4_6, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_124222_1__R_s_b_0_4, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_19430_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2646 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_5_5 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_5_6: Select s_b_5_3 ? s_b_5_4 : s_b_5_5 */
    dbt::el::Value *s_b_5_6;
    s_b_5_6 = (s_b_5_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_5_5);
    /* execute.a64:2659 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_5_8: sym_124222_1__R_s_b_0_4 = s_b_5_7, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_124222_1__R_s_b_0_4, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:215 [D] s_b_6_0 = sym_124222_1__R_s_b_0_4 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_124222_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:215 [D] s_b_6_1: sym_19435_0_op1 = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_19435_0_op1, s_b_6_0);
    /* execute.a64:217 [F] s_b_6_2=sym_19430_3_parameter_inst.sf (const) */
    /* execute.a64:217 [F] s_b_6_3: If s_b_6_2: Jump b_1 else b_3 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_1,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2747 [D] s_b_7_0 = sym_124237_3_parameter_value uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_124237_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_7_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_7_2 = s_b_7_0&s_b_7_1 */
    auto s_b_7_2 = emitter.bitwise_and(s_b_7_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_7_3: sym_124237_3_parameter_value = s_b_7_2, dominates: s_b_9_0 s_b_10_1  */
    emitter.store_local(DV_sym_124237_3_parameter_value, s_b_7_2);
    /* execute.a64:2747 [F] s_b_7_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_1, b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2750 [F] s_b_8_0=sym_19430_3_parameter_inst.rd (const) */
    /* execute.a64:2750 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2750 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_8_4: If s_b_8_3: Jump b_9 else b_10 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2751 [D] s_b_9_0 = sym_124237_3_parameter_value uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_124237_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_9_1: sym_124351_3_parameter_value = s_b_9_0, dominates: s_b_15_0 s_b_16_0 s_b_17_0  */
    emitter.store_local(DV_sym_124351_3_parameter_value, s_b_9_0);
    /* execute.a64:2714 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_9_3 = __builtin_get_feature */
    uint32_t s_b_9_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(s_b_9_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_9_6: If s_b_9_5: Jump b_15 else b_21 (const) */
    if (s_b_9_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2753 [F] s_b_10_0=sym_19430_3_parameter_inst.rd (const) */
    /* execute.a64:2753 [D] s_b_10_1 = sym_124237_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_124237_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1);
    /* execute.a64:2753 [F] s_b_10_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2747 [D] s_b_11_0 = sym_124274_3_parameter_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_124274_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_11_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_11_2 = s_b_11_0&s_b_11_1 */
    auto s_b_11_2 = emitter.bitwise_and(s_b_11_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_11_3: sym_124274_3_parameter_value = s_b_11_2, dominates: s_b_13_0 s_b_14_1  */
    emitter.store_local(DV_sym_124274_3_parameter_value, s_b_11_2);
    /* execute.a64:2747 [F] s_b_11_4: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_3, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2750 [F] s_b_12_0=sym_19430_3_parameter_inst.rd (const) */
    /* execute.a64:2750 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.a64:2750 [F] s_b_12_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_12_4: If s_b_12_3: Jump b_13 else b_14 (const) */
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
    /* execute.a64:2751 [D] s_b_13_0 = sym_124274_3_parameter_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_124274_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_13_1: sym_124386_3_parameter_value = s_b_13_0, dominates: s_b_18_0 s_b_19_0 s_b_20_0  */
    emitter.store_local(DV_sym_124386_3_parameter_value, s_b_13_0);
    /* execute.a64:2714 [F] s_b_13_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_13_3 = __builtin_get_feature */
    uint32_t s_b_13_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
    uint8_t s_b_13_5 = ((uint8_t)(s_b_13_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_13_6: If s_b_13_5: Jump b_18 else b_22 (const) */
    if (s_b_13_5) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2753 [F] s_b_14_0=sym_19430_3_parameter_inst.rd (const) */
    /* execute.a64:2753 [D] s_b_14_1 = sym_124274_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_124274_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1);
    /* execute.a64:2753 [F] s_b_14_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2715 [D] s_b_15_0 = sym_124351_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_124351_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_15_1: WriteReg 20 = s_b_15_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_15_0);
    /* execute.a64:2715 [F] s_b_15_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_21,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2718 [D] s_b_16_0 = sym_124351_3_parameter_value uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_124351_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_16_1: WriteReg 20 = s_b_16_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_16_0);
    /* execute.a64:2718 [F] s_b_16_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_21,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2720 [D] s_b_17_0 = sym_124351_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_124351_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_17_1: WriteReg 21 = s_b_17_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_17_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_17_0);
    /* execute.a64:2720 [F] s_b_17_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_13,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2715 [D] s_b_18_0 = sym_124386_3_parameter_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_124386_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_18_1: WriteReg 20 = s_b_18_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_18_0);
    /* execute.a64:2715 [F] s_b_18_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_22,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2718 [D] s_b_19_0 = sym_124386_3_parameter_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_124386_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_19_1: WriteReg 20 = s_b_19_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_19_0);
    /* execute.a64:2718 [F] s_b_19_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_22,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2720 [D] s_b_20_0 = sym_124386_3_parameter_value uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_124386_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_20_1: WriteReg 21 = s_b_20_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_20_0);
    /* execute.a64:2720 [F] s_b_20_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
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
    /* execute.a64:2717 [F] s_b_21_6: If s_b_21_5: Jump b_16 else b_17 (const) */
    if (s_b_21_5) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_13,  */
  fixed_block_b_22: 
  {
    /* execute.a64:3012 [F] s_b_22_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_22_1 = __builtin_get_feature */
    uint32_t s_b_22_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_22_2 = (u8)s_b_22_1 (const) */
    /* execute.a64:2717 [F] s_b_22_3 = (u32)s_b_22_2 (const) */
    /* execute.a64:2717 [F] s_b_22_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_22_5 = s_b_22_3==s_b_22_4 (const) */
    uint8_t s_b_22_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_22_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_22_6: If s_b_22_5: Jump b_19 else b_20 (const) */
    if (s_b_22_5) 
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_rbit(const aarch64_decode_a64_DP_1S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_125250_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_125187_1__R_s_b_0_7 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_125353_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_125375_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_19955_0_output;
  auto DV_sym_19955_0_output = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19961_0_input = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2154 [F] s_b_0_0 = constant u64 0 (const) */
    /* execute.a64:2154 [F] s_b_0_1: sym_19955_0_output = s_b_0_0 (const), dominates:  */
    CV_sym_19955_0_output = (uint64_t)0ULL;
    /* execute.a64:2155 [F] s_b_0_2=sym_19952_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_3: If s_b_0_2: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2158 [D] s_b_1_0 = sym_19961_0_input uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_19961_0_input, emitter.context().types().u64());
    /* execute.a64:2158 [D] s_b_1_1 = (u32)s_b_1_0 */
    auto s_b_1_1 = emitter.truncate(s_b_1_0, emitter.context().types().u32());
    /* execute.a64:2549 [F] s_b_1_2 = constant u64 aaaaaaaa (const) */
    /* ???:4294967295 [D] s_b_1_3 = (u64)s_b_1_1 */
    auto s_b_1_3 = emitter.zx(s_b_1_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_4 = s_b_1_3&s_b_1_2 */
    auto s_b_1_4 = emitter.bitwise_and(s_b_1_3, emitter.const_u64((uint64_t)2863311530ULL));
    /* execute.a64:2549 [D] s_b_1_5 = (u32)s_b_1_4 */
    auto s_b_1_5 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2550 [F] s_b_1_6 = constant u32 2 (const) */
    /* execute.a64:2550 [D] s_b_1_7 = s_b_1_5>>>s_b_1_6 */
    auto s_b_1_7 = emitter.ror(s_b_1_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.a64:2551 [F] s_b_1_8 = constant u64 55555555 (const) */
    /* ???:4294967295 [D] s_b_1_9 = (u64)s_b_1_1 */
    auto s_b_1_9 = emitter.zx(s_b_1_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_10 = s_b_1_9&s_b_1_8 */
    auto s_b_1_10 = emitter.bitwise_and(s_b_1_9, emitter.const_u64((uint64_t)1431655765ULL));
    /* execute.a64:2551 [D] s_b_1_11 = (u32)s_b_1_10 */
    auto s_b_1_11 = emitter.truncate(s_b_1_10, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_1_12 = s_b_1_7|s_b_1_11 */
    auto s_b_1_12 = emitter.bitwise_or(s_b_1_7, s_b_1_11);
    /* execute.a64:2555 [F] s_b_1_13 = constant u64 66666666 (const) */
    /* ???:4294967295 [D] s_b_1_14 = (u64)s_b_1_12 */
    auto s_b_1_14 = emitter.zx(s_b_1_12, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_15 = s_b_1_14&s_b_1_13 */
    auto s_b_1_15 = emitter.bitwise_and(s_b_1_14, emitter.const_u64((uint64_t)1717986918ULL));
    /* execute.a64:2555 [D] s_b_1_16 = (u32)s_b_1_15 */
    auto s_b_1_16 = emitter.truncate(s_b_1_15, emitter.context().types().u32());
    /* execute.a64:2556 [F] s_b_1_17 = constant u32 4 (const) */
    /* execute.a64:2556 [D] s_b_1_18 = s_b_1_16>>>s_b_1_17 */
    auto s_b_1_18 = emitter.ror(s_b_1_16, emitter.const_u32((uint32_t)4ULL));
    /* execute.a64:2557 [F] s_b_1_19 = constant u64 99999999 (const) */
    /* ???:4294967295 [D] s_b_1_20 = (u64)s_b_1_12 */
    auto s_b_1_20 = emitter.zx(s_b_1_12, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_21 = s_b_1_20&s_b_1_19 */
    auto s_b_1_21 = emitter.bitwise_and(s_b_1_20, emitter.const_u64((uint64_t)2576980377ULL));
    /* execute.a64:2557 [D] s_b_1_22 = (u32)s_b_1_21 */
    auto s_b_1_22 = emitter.truncate(s_b_1_21, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_1_23 = s_b_1_18|s_b_1_22 */
    auto s_b_1_23 = emitter.bitwise_or(s_b_1_18, s_b_1_22);
    /* execute.a64:2561 [F] s_b_1_24 = constant u64 1e1e1e1e (const) */
    /* ???:4294967295 [D] s_b_1_25 = (u64)s_b_1_23 */
    auto s_b_1_25 = emitter.zx(s_b_1_23, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_26 = s_b_1_25&s_b_1_24 */
    auto s_b_1_26 = emitter.bitwise_and(s_b_1_25, emitter.const_u64((uint64_t)505290270ULL));
    /* execute.a64:2561 [D] s_b_1_27 = (u32)s_b_1_26 */
    auto s_b_1_27 = emitter.truncate(s_b_1_26, emitter.context().types().u32());
    /* execute.a64:2562 [F] s_b_1_28 = constant u32 8 (const) */
    /* execute.a64:2562 [D] s_b_1_29 = s_b_1_27>>>s_b_1_28 */
    auto s_b_1_29 = emitter.ror(s_b_1_27, emitter.const_u32((uint32_t)8ULL));
    /* execute.a64:2563 [F] s_b_1_30 = constant u64 e1e1e1e1 (const) */
    /* ???:4294967295 [D] s_b_1_31 = (u64)s_b_1_23 */
    auto s_b_1_31 = emitter.zx(s_b_1_23, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_32 = s_b_1_31&s_b_1_30 */
    auto s_b_1_32 = emitter.bitwise_and(s_b_1_31, emitter.const_u64((uint64_t)3789677025ULL));
    /* execute.a64:2563 [D] s_b_1_33 = (u32)s_b_1_32 */
    auto s_b_1_33 = emitter.truncate(s_b_1_32, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_1_34 = s_b_1_29|s_b_1_33 */
    auto s_b_1_34 = emitter.bitwise_or(s_b_1_29, s_b_1_33);
    /* execute.a64:2566 [F] s_b_1_35 = constant u32 7 (const) */
    /* execute.a64:2566 [D] s_b_1_36 = s_b_1_34<<<s_b_1_35 */
    auto s_b_1_36 = emitter.rol(s_b_1_34, emitter.const_u32((uint32_t)7ULL));
    /* execute.a64:2567 [D] s_b_1_37 = __builtin_bswap32 */
    auto s_b_1_37 = emitter.bswap(s_b_1_36);
    /* execute.a64:2158 [D] s_b_1_38 = (u64)s_b_1_37 */
    auto s_b_1_38 = emitter.zx(s_b_1_37, emitter.context().types().u64());
    /* execute.a64:2158 [D] s_b_1_39: sym_19955_0_output = s_b_1_38, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_19955_0_output, s_b_1_38);
    /* execute.a64:2158 [F] s_b_1_40: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2163 [F] s_b_2_0=sym_19952_3_parameter_inst.sf (const) */
    /* execute.a64:2163 [D] s_b_2_1 = sym_19955_0_output uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_19955_0_output, emitter.context().types().u64());
    /* execute.a64:2163 [D] s_b_2_2: sym_125250_3_parameter_value = s_b_2_1, dominates: s_b_7_1 s_b_8_1  */
    emitter.store_local(DV_sym_125250_3_parameter_value, s_b_2_1);
    /* execute.a64:2690 [F] s_b_2_3: If s_b_2_0: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2160 [D] s_b_3_0 = sym_19961_0_input uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_19961_0_input, emitter.context().types().u64());
    /* execute.a64:2524 [F] s_b_3_1 = constant u64 aaaaaaaaaaaaaaaa (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0&s_b_3_1 */
    auto s_b_3_2 = emitter.bitwise_and(s_b_3_0, emitter.const_u64((uint64_t)12297829382473034410ULL));
    /* execute.a64:2525 [F] s_b_3_3 = constant u64 2 (const) */
    /* execute.a64:2525 [D] s_b_3_4 = s_b_3_2>>>s_b_3_3 */
    auto s_b_3_4 = emitter.ror(s_b_3_2, emitter.const_u64((uint64_t)2ULL));
    /* execute.a64:2526 [F] s_b_3_5 = constant u64 5555555555555555 (const) */
    /* ???:4294967295 [D] s_b_3_6 = s_b_3_0&s_b_3_5 */
    auto s_b_3_6 = emitter.bitwise_and(s_b_3_0, emitter.const_u64((uint64_t)6148914691236517205ULL));
    /* ???:4294967295 [D] s_b_3_7 = s_b_3_4|s_b_3_6 */
    auto s_b_3_7 = emitter.bitwise_or(s_b_3_4, s_b_3_6);
    /* execute.a64:2530 [F] s_b_3_8 = constant u64 6666666666666666 (const) */
    /* ???:4294967295 [D] s_b_3_9 = s_b_3_7&s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_7, emitter.const_u64((uint64_t)7378697629483820646ULL));
    /* execute.a64:2531 [F] s_b_3_10 = constant u64 4 (const) */
    /* execute.a64:2531 [D] s_b_3_11 = s_b_3_9>>>s_b_3_10 */
    auto s_b_3_11 = emitter.ror(s_b_3_9, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2532 [F] s_b_3_12 = constant u64 9999999999999999 (const) */
    /* ???:4294967295 [D] s_b_3_13 = s_b_3_7&s_b_3_12 */
    auto s_b_3_13 = emitter.bitwise_and(s_b_3_7, emitter.const_u64((uint64_t)11068046444225730969ULL));
    /* ???:4294967295 [D] s_b_3_14 = s_b_3_11|s_b_3_13 */
    auto s_b_3_14 = emitter.bitwise_or(s_b_3_11, s_b_3_13);
    /* execute.a64:2536 [F] s_b_3_15 = constant u64 1e1e1e1e1e1e1e1e (const) */
    /* ???:4294967295 [D] s_b_3_16 = s_b_3_14&s_b_3_15 */
    auto s_b_3_16 = emitter.bitwise_and(s_b_3_14, emitter.const_u64((uint64_t)2170205185142300190ULL));
    /* execute.a64:2537 [F] s_b_3_17 = constant u64 8 (const) */
    /* execute.a64:2537 [D] s_b_3_18 = s_b_3_16>>>s_b_3_17 */
    auto s_b_3_18 = emitter.ror(s_b_3_16, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:2538 [F] s_b_3_19 = constant u64 e1e1e1e1e1e1e1e1 (const) */
    /* ???:4294967295 [D] s_b_3_20 = s_b_3_14&s_b_3_19 */
    auto s_b_3_20 = emitter.bitwise_and(s_b_3_14, emitter.const_u64((uint64_t)16276538888567251425ULL));
    /* ???:4294967295 [D] s_b_3_21 = s_b_3_18|s_b_3_20 */
    auto s_b_3_21 = emitter.bitwise_or(s_b_3_18, s_b_3_20);
    /* execute.a64:2541 [F] s_b_3_22 = constant u64 7 (const) */
    /* execute.a64:2541 [D] s_b_3_23 = s_b_3_21<<<s_b_3_22 */
    auto s_b_3_23 = emitter.rol(s_b_3_21, emitter.const_u64((uint64_t)7ULL));
    /* execute.a64:2542 [D] s_b_3_24 = __builtin_bswap64 */
    auto s_b_3_24 = emitter.bswap(s_b_3_23);
    /* execute.a64:2160 [D] s_b_3_25: sym_19955_0_output = s_b_3_24, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_19955_0_output, s_b_3_24);
    /* execute.a64:2160 [F] s_b_3_26: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2657 [F] s_b_4_0=sym_19952_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2651 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_4_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_4_5 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2657 [D] s_b_4_7: sym_125187_1__R_s_b_0_7 = s_b_4_6, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_125187_1__R_s_b_0_7, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_19952_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2646 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_5_5 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_5_6: Select s_b_5_3 ? s_b_5_4 : s_b_5_5 */
    dbt::el::Value *s_b_5_6;
    s_b_5_6 = (s_b_5_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_5_5);
    /* execute.a64:2659 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_5_8: sym_125187_1__R_s_b_0_7 = s_b_5_7, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_125187_1__R_s_b_0_7, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2155 [D] s_b_6_0 = sym_125187_1__R_s_b_0_7 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_125187_1__R_s_b_0_7, emitter.context().types().u64());
    /* execute.a64:2155 [D] s_b_6_1: sym_19961_0_input = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_19961_0_input, s_b_6_0);
    /* execute.a64:2157 [F] s_b_6_2=sym_19952_3_parameter_inst.sf (const) */
    /* execute.a64:2157 [F] s_b_6_3 = (u32)s_b_6_2 (const) */
    /* execute.a64:2157 [F] s_b_6_4 = constant u32 0 (const) */
    /* execute.a64:2157 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:2157 [F] s_b_6_6: If s_b_6_5: Jump b_1 else b_3 (const) */
    if (s_b_6_5) 
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
    /* execute.a64:2691 [F] s_b_7_0=sym_19952_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_7_1 = sym_125250_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_125250_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_7_2: sym_125353_3_parameter_value = s_b_7_1, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_125353_3_parameter_value, s_b_7_1);
    /* execute.a64:2682 [F] s_b_7_3 = (u32)s_b_7_0 (const) */
    /* execute.a64:2682 [F] s_b_7_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_7_5 = s_b_7_3==s_b_7_4 (const) */
    uint8_t s_b_7_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_7_6: If s_b_7_5: Jump b_9 else b_10 (const) */
    if (s_b_7_5) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2693 [F] s_b_8_0=sym_19952_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_8_1 = sym_125250_3_parameter_value uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_125250_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_8_2 = (u32)s_b_8_1 */
    auto s_b_8_2 = emitter.truncate(s_b_8_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_8_3 = (u64)s_b_8_2 */
    auto s_b_8_3 = emitter.zx(s_b_8_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_8_4: sym_125375_3_parameter_value = s_b_8_3, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_125375_3_parameter_value, s_b_8_3);
    /* execute.a64:2682 [F] s_b_8_5 = (u32)s_b_8_0 (const) */
    /* execute.a64:2682 [F] s_b_8_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_8_7 = s_b_8_5==s_b_8_6 (const) */
    uint8_t s_b_8_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_8_8: If s_b_8_7: Jump b_9 else b_11 (const) */
    if (s_b_8_7) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_7, b_8, b_10, b_11,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [F] s_b_9_0: Return */
    goto fixed_done;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2684 [F] s_b_10_0=sym_19952_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_10_1 = sym_125353_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_125353_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1);
    /* execute.a64:0 [F] s_b_10_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2684 [F] s_b_11_0=sym_19952_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_11_1 = sym_125375_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_125375_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1);
    /* execute.a64:0 [F] s_b_11_3: Jump b_9 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_saddl(const aarch64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5445 [F] s_b_0_0=sym_20556_3_parameter_inst.tb (const) */
    /* execute.simd:5446 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5458 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5470 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5482 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5494 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5506 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5445 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5447 [F] s_b_2_0=sym_20556_3_parameter_inst.rn (const) */
    /* execute.simd:5447 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5447 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:5448 [F] s_b_2_3=sym_20556_3_parameter_inst.rm (const) */
    /* execute.simd:5448 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5448 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5452 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5452 [D] s_b_2_9 = (s16)s_b_2_8 */
    auto s_b_2_9 = emitter.sx(s_b_2_8, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5452 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5452 [D] s_b_2_12 = (s16)s_b_2_11 */
    auto s_b_2_12 = emitter.sx(s_b_2_11, emitter.context().types().s16());
    /* execute.simd:5452 [D] s_b_2_13 = s_b_2_9+s_b_2_12 */
    auto s_b_2_13 = emitter.add(s_b_2_9, s_b_2_12);
    /* execute.simd:5452 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5452 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5452 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5452 [D] s_b_2_18 = (s16)s_b_2_17 */
    auto s_b_2_18 = emitter.sx(s_b_2_17, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5452 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5452 [D] s_b_2_21 = (s16)s_b_2_20 */
    auto s_b_2_21 = emitter.sx(s_b_2_20, emitter.context().types().s16());
    /* execute.simd:5452 [D] s_b_2_22 = s_b_2_18+s_b_2_21 */
    auto s_b_2_22 = emitter.add(s_b_2_18, s_b_2_21);
    /* execute.simd:5452 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5452 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5452 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5452 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5452 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5452 [D] s_b_2_30 = (s16)s_b_2_29 */
    auto s_b_2_30 = emitter.sx(s_b_2_29, emitter.context().types().s16());
    /* execute.simd:5452 [D] s_b_2_31 = s_b_2_27+s_b_2_30 */
    auto s_b_2_31 = emitter.add(s_b_2_27, s_b_2_30);
    /* execute.simd:5452 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5452 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5452 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5452 [D] s_b_2_36 = (s16)s_b_2_35 */
    auto s_b_2_36 = emitter.sx(s_b_2_35, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5452 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5452 [D] s_b_2_39 = (s16)s_b_2_38 */
    auto s_b_2_39 = emitter.sx(s_b_2_38, emitter.context().types().s16());
    /* execute.simd:5452 [D] s_b_2_40 = s_b_2_36+s_b_2_39 */
    auto s_b_2_40 = emitter.add(s_b_2_36, s_b_2_39);
    /* execute.simd:5452 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5452 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5452 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5452 [D] s_b_2_45 = (s16)s_b_2_44 */
    auto s_b_2_45 = emitter.sx(s_b_2_44, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5452 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5452 [D] s_b_2_48 = (s16)s_b_2_47 */
    auto s_b_2_48 = emitter.sx(s_b_2_47, emitter.context().types().s16());
    /* execute.simd:5452 [D] s_b_2_49 = s_b_2_45+s_b_2_48 */
    auto s_b_2_49 = emitter.add(s_b_2_45, s_b_2_48);
    /* execute.simd:5452 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5452 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5452 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5452 [D] s_b_2_54 = (s16)s_b_2_53 */
    auto s_b_2_54 = emitter.sx(s_b_2_53, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5452 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5452 [D] s_b_2_57 = (s16)s_b_2_56 */
    auto s_b_2_57 = emitter.sx(s_b_2_56, emitter.context().types().s16());
    /* execute.simd:5452 [D] s_b_2_58 = s_b_2_54+s_b_2_57 */
    auto s_b_2_58 = emitter.add(s_b_2_54, s_b_2_57);
    /* execute.simd:5452 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5452 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5452 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5452 [D] s_b_2_63 = (s16)s_b_2_62 */
    auto s_b_2_63 = emitter.sx(s_b_2_62, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5452 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5452 [D] s_b_2_66 = (s16)s_b_2_65 */
    auto s_b_2_66 = emitter.sx(s_b_2_65, emitter.context().types().s16());
    /* execute.simd:5452 [D] s_b_2_67 = s_b_2_63+s_b_2_66 */
    auto s_b_2_67 = emitter.add(s_b_2_63, s_b_2_66);
    /* execute.simd:5452 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5452 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5452 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5452 [D] s_b_2_72 = (s16)s_b_2_71 */
    auto s_b_2_72 = emitter.sx(s_b_2_71, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5452 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5452 [D] s_b_2_75 = (s16)s_b_2_74 */
    auto s_b_2_75 = emitter.sx(s_b_2_74, emitter.context().types().s16());
    /* execute.simd:5452 [D] s_b_2_76 = s_b_2_72+s_b_2_75 */
    auto s_b_2_76 = emitter.add(s_b_2_72, s_b_2_75);
    /* execute.simd:5452 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5452 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5455 [F] s_b_2_79=sym_20556_3_parameter_inst.rd (const) */
    /* execute.simd:5455 [D] s_b_2_80 = (v8u16)s_b_2_78 */
    auto s_b_2_80 = emitter.reinterpret(s_b_2_78, emitter.context().types().v8u16());
    /* execute.simd:5455 [D] s_b_2_81: WriteRegBank 18:s_b_2_79 = s_b_2_80 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_80,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_80);
    /* execute.simd:0 [F] s_b_2_82: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5459 [F] s_b_3_0=sym_20556_3_parameter_inst.rn (const) */
    /* execute.simd:5459 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5459 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:5460 [F] s_b_3_3=sym_20556_3_parameter_inst.rm (const) */
    /* execute.simd:5460 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5460 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:5464 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5464 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5464 [D] s_b_3_9 = (s16)s_b_3_8 */
    auto s_b_3_9 = emitter.sx(s_b_3_8, emitter.context().types().s16());
    /* execute.simd:5464 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5464 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5464 [D] s_b_3_12 = (s16)s_b_3_11 */
    auto s_b_3_12 = emitter.sx(s_b_3_11, emitter.context().types().s16());
    /* execute.simd:5464 [D] s_b_3_13 = s_b_3_9+s_b_3_12 */
    auto s_b_3_13 = emitter.add(s_b_3_9, s_b_3_12);
    /* execute.simd:5464 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5464 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5464 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5464 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5464 [D] s_b_3_18 = (s16)s_b_3_17 */
    auto s_b_3_18 = emitter.sx(s_b_3_17, emitter.context().types().s16());
    /* execute.simd:5464 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5464 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5464 [D] s_b_3_21 = (s16)s_b_3_20 */
    auto s_b_3_21 = emitter.sx(s_b_3_20, emitter.context().types().s16());
    /* execute.simd:5464 [D] s_b_3_22 = s_b_3_18+s_b_3_21 */
    auto s_b_3_22 = emitter.add(s_b_3_18, s_b_3_21);
    /* execute.simd:5464 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5464 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5464 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5464 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5464 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5464 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5464 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5464 [D] s_b_3_30 = (s16)s_b_3_29 */
    auto s_b_3_30 = emitter.sx(s_b_3_29, emitter.context().types().s16());
    /* execute.simd:5464 [D] s_b_3_31 = s_b_3_27+s_b_3_30 */
    auto s_b_3_31 = emitter.add(s_b_3_27, s_b_3_30);
    /* execute.simd:5464 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5464 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5464 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5464 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5464 [D] s_b_3_36 = (s16)s_b_3_35 */
    auto s_b_3_36 = emitter.sx(s_b_3_35, emitter.context().types().s16());
    /* execute.simd:5464 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5464 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5464 [D] s_b_3_39 = (s16)s_b_3_38 */
    auto s_b_3_39 = emitter.sx(s_b_3_38, emitter.context().types().s16());
    /* execute.simd:5464 [D] s_b_3_40 = s_b_3_36+s_b_3_39 */
    auto s_b_3_40 = emitter.add(s_b_3_36, s_b_3_39);
    /* execute.simd:5464 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5464 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5464 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5464 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5464 [D] s_b_3_45 = (s16)s_b_3_44 */
    auto s_b_3_45 = emitter.sx(s_b_3_44, emitter.context().types().s16());
    /* execute.simd:5464 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5464 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5464 [D] s_b_3_48 = (s16)s_b_3_47 */
    auto s_b_3_48 = emitter.sx(s_b_3_47, emitter.context().types().s16());
    /* execute.simd:5464 [D] s_b_3_49 = s_b_3_45+s_b_3_48 */
    auto s_b_3_49 = emitter.add(s_b_3_45, s_b_3_48);
    /* execute.simd:5464 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5464 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5464 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5464 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5464 [D] s_b_3_54 = (s16)s_b_3_53 */
    auto s_b_3_54 = emitter.sx(s_b_3_53, emitter.context().types().s16());
    /* execute.simd:5464 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5464 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5464 [D] s_b_3_57 = (s16)s_b_3_56 */
    auto s_b_3_57 = emitter.sx(s_b_3_56, emitter.context().types().s16());
    /* execute.simd:5464 [D] s_b_3_58 = s_b_3_54+s_b_3_57 */
    auto s_b_3_58 = emitter.add(s_b_3_54, s_b_3_57);
    /* execute.simd:5464 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5464 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5464 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5464 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5464 [D] s_b_3_63 = (s16)s_b_3_62 */
    auto s_b_3_63 = emitter.sx(s_b_3_62, emitter.context().types().s16());
    /* execute.simd:5464 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5464 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5464 [D] s_b_3_66 = (s16)s_b_3_65 */
    auto s_b_3_66 = emitter.sx(s_b_3_65, emitter.context().types().s16());
    /* execute.simd:5464 [D] s_b_3_67 = s_b_3_63+s_b_3_66 */
    auto s_b_3_67 = emitter.add(s_b_3_63, s_b_3_66);
    /* execute.simd:5464 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5464 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5464 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5464 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5464 [D] s_b_3_72 = (s16)s_b_3_71 */
    auto s_b_3_72 = emitter.sx(s_b_3_71, emitter.context().types().s16());
    /* execute.simd:5464 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5464 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5464 [D] s_b_3_75 = (s16)s_b_3_74 */
    auto s_b_3_75 = emitter.sx(s_b_3_74, emitter.context().types().s16());
    /* execute.simd:5464 [D] s_b_3_76 = s_b_3_72+s_b_3_75 */
    auto s_b_3_76 = emitter.add(s_b_3_72, s_b_3_75);
    /* execute.simd:5464 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5464 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5467 [F] s_b_3_79=sym_20556_3_parameter_inst.rd (const) */
    /* execute.simd:5467 [D] s_b_3_80 = (v8u16)s_b_3_78 */
    auto s_b_3_80 = emitter.reinterpret(s_b_3_78, emitter.context().types().v8u16());
    /* execute.simd:5467 [D] s_b_3_81: WriteRegBank 18:s_b_3_79 = s_b_3_80 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_80,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_80);
    /* execute.simd:0 [F] s_b_3_82: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5471 [F] s_b_4_0=sym_20556_3_parameter_inst.rn (const) */
    /* execute.simd:5471 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5471 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:5472 [F] s_b_4_3=sym_20556_3_parameter_inst.rm (const) */
    /* execute.simd:5472 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5472 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5476 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5476 [D] s_b_4_9 = (s32)s_b_4_8 */
    auto s_b_4_9 = emitter.sx(s_b_4_8, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5476 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5476 [D] s_b_4_12 = (s32)s_b_4_11 */
    auto s_b_4_12 = emitter.sx(s_b_4_11, emitter.context().types().s32());
    /* execute.simd:5476 [D] s_b_4_13 = s_b_4_9+s_b_4_12 */
    auto s_b_4_13 = emitter.add(s_b_4_9, s_b_4_12);
    /* execute.simd:5476 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5476 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5476 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5476 [D] s_b_4_18 = (s32)s_b_4_17 */
    auto s_b_4_18 = emitter.sx(s_b_4_17, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5476 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5476 [D] s_b_4_21 = (s32)s_b_4_20 */
    auto s_b_4_21 = emitter.sx(s_b_4_20, emitter.context().types().s32());
    /* execute.simd:5476 [D] s_b_4_22 = s_b_4_18+s_b_4_21 */
    auto s_b_4_22 = emitter.add(s_b_4_18, s_b_4_21);
    /* execute.simd:5476 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5476 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5476 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5476 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5476 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5476 [D] s_b_4_30 = (s32)s_b_4_29 */
    auto s_b_4_30 = emitter.sx(s_b_4_29, emitter.context().types().s32());
    /* execute.simd:5476 [D] s_b_4_31 = s_b_4_27+s_b_4_30 */
    auto s_b_4_31 = emitter.add(s_b_4_27, s_b_4_30);
    /* execute.simd:5476 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5476 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5476 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5476 [D] s_b_4_36 = (s32)s_b_4_35 */
    auto s_b_4_36 = emitter.sx(s_b_4_35, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5476 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5476 [D] s_b_4_39 = (s32)s_b_4_38 */
    auto s_b_4_39 = emitter.sx(s_b_4_38, emitter.context().types().s32());
    /* execute.simd:5476 [D] s_b_4_40 = s_b_4_36+s_b_4_39 */
    auto s_b_4_40 = emitter.add(s_b_4_36, s_b_4_39);
    /* execute.simd:5476 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5476 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5479 [F] s_b_4_43=sym_20556_3_parameter_inst.rd (const) */
    /* execute.simd:5479 [D] s_b_4_44 = (v4u32)s_b_4_42 */
    auto s_b_4_44 = emitter.reinterpret(s_b_4_42, emitter.context().types().v4u32());
    /* execute.simd:5479 [D] s_b_4_45: WriteRegBank 20:s_b_4_43 = s_b_4_44 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_44,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_44);
    /* execute.simd:0 [F] s_b_4_46: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5483 [F] s_b_5_0=sym_20556_3_parameter_inst.rn (const) */
    /* execute.simd:5483 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5483 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:5484 [F] s_b_5_3=sym_20556_3_parameter_inst.rm (const) */
    /* execute.simd:5484 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5484 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:5488 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5488 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5488 [D] s_b_5_9 = (s32)s_b_5_8 */
    auto s_b_5_9 = emitter.sx(s_b_5_8, emitter.context().types().s32());
    /* execute.simd:5488 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5488 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5488 [D] s_b_5_12 = (s32)s_b_5_11 */
    auto s_b_5_12 = emitter.sx(s_b_5_11, emitter.context().types().s32());
    /* execute.simd:5488 [D] s_b_5_13 = s_b_5_9+s_b_5_12 */
    auto s_b_5_13 = emitter.add(s_b_5_9, s_b_5_12);
    /* execute.simd:5488 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5488 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5488 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5488 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5488 [D] s_b_5_18 = (s32)s_b_5_17 */
    auto s_b_5_18 = emitter.sx(s_b_5_17, emitter.context().types().s32());
    /* execute.simd:5488 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5488 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5488 [D] s_b_5_21 = (s32)s_b_5_20 */
    auto s_b_5_21 = emitter.sx(s_b_5_20, emitter.context().types().s32());
    /* execute.simd:5488 [D] s_b_5_22 = s_b_5_18+s_b_5_21 */
    auto s_b_5_22 = emitter.add(s_b_5_18, s_b_5_21);
    /* execute.simd:5488 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5488 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5488 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5488 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5488 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5488 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5488 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5488 [D] s_b_5_30 = (s32)s_b_5_29 */
    auto s_b_5_30 = emitter.sx(s_b_5_29, emitter.context().types().s32());
    /* execute.simd:5488 [D] s_b_5_31 = s_b_5_27+s_b_5_30 */
    auto s_b_5_31 = emitter.add(s_b_5_27, s_b_5_30);
    /* execute.simd:5488 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5488 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5488 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5488 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5488 [D] s_b_5_36 = (s32)s_b_5_35 */
    auto s_b_5_36 = emitter.sx(s_b_5_35, emitter.context().types().s32());
    /* execute.simd:5488 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5488 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5488 [D] s_b_5_39 = (s32)s_b_5_38 */
    auto s_b_5_39 = emitter.sx(s_b_5_38, emitter.context().types().s32());
    /* execute.simd:5488 [D] s_b_5_40 = s_b_5_36+s_b_5_39 */
    auto s_b_5_40 = emitter.add(s_b_5_36, s_b_5_39);
    /* execute.simd:5488 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5488 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5491 [F] s_b_5_43=sym_20556_3_parameter_inst.rd (const) */
    /* execute.simd:5491 [D] s_b_5_44 = (v4u32)s_b_5_42 */
    auto s_b_5_44 = emitter.reinterpret(s_b_5_42, emitter.context().types().v4u32());
    /* execute.simd:5491 [D] s_b_5_45: WriteRegBank 20:s_b_5_43 = s_b_5_44 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_44,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_44);
    /* execute.simd:0 [F] s_b_5_46: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5495 [F] s_b_6_0=sym_20556_3_parameter_inst.rn (const) */
    /* execute.simd:5495 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5495 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:5496 [F] s_b_6_3=sym_20556_3_parameter_inst.rm (const) */
    /* execute.simd:5496 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5496 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5500 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5500 [D] s_b_6_9 = (s64)s_b_6_8 */
    auto s_b_6_9 = emitter.sx(s_b_6_8, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5500 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5500 [D] s_b_6_12 = (s64)s_b_6_11 */
    auto s_b_6_12 = emitter.sx(s_b_6_11, emitter.context().types().s64());
    /* execute.simd:5500 [D] s_b_6_13 = s_b_6_9+s_b_6_12 */
    auto s_b_6_13 = emitter.add(s_b_6_9, s_b_6_12);
    /* execute.simd:5500 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5500 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5500 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5500 [D] s_b_6_18 = (s64)s_b_6_17 */
    auto s_b_6_18 = emitter.sx(s_b_6_17, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5500 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5500 [D] s_b_6_21 = (s64)s_b_6_20 */
    auto s_b_6_21 = emitter.sx(s_b_6_20, emitter.context().types().s64());
    /* execute.simd:5500 [D] s_b_6_22 = s_b_6_18+s_b_6_21 */
    auto s_b_6_22 = emitter.add(s_b_6_18, s_b_6_21);
    /* execute.simd:5500 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5500 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:5503 [F] s_b_6_25=sym_20556_3_parameter_inst.rd (const) */
    /* execute.simd:5503 [D] s_b_6_26 = (v2u64)s_b_6_24 */
    auto s_b_6_26 = emitter.reinterpret(s_b_6_24, emitter.context().types().v2u64());
    /* execute.simd:5503 [D] s_b_6_27: WriteRegBank 21:s_b_6_25 = s_b_6_26 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_26,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_26);
    /* execute.simd:0 [F] s_b_6_28: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:5507 [F] s_b_7_0=sym_20556_3_parameter_inst.rn (const) */
    /* execute.simd:5507 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5507 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:5508 [F] s_b_7_3=sym_20556_3_parameter_inst.rm (const) */
    /* execute.simd:5508 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5508 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:5512 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:5512 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5512 [D] s_b_7_9 = (s64)s_b_7_8 */
    auto s_b_7_9 = emitter.sx(s_b_7_8, emitter.context().types().s64());
    /* execute.simd:5512 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:5512 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5512 [D] s_b_7_12 = (s64)s_b_7_11 */
    auto s_b_7_12 = emitter.sx(s_b_7_11, emitter.context().types().s64());
    /* execute.simd:5512 [D] s_b_7_13 = s_b_7_9+s_b_7_12 */
    auto s_b_7_13 = emitter.add(s_b_7_9, s_b_7_12);
    /* execute.simd:5512 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:5512 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:5512 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:5512 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5512 [D] s_b_7_18 = (s64)s_b_7_17 */
    auto s_b_7_18 = emitter.sx(s_b_7_17, emitter.context().types().s64());
    /* execute.simd:5512 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:5512 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5512 [D] s_b_7_21 = (s64)s_b_7_20 */
    auto s_b_7_21 = emitter.sx(s_b_7_20, emitter.context().types().s64());
    /* execute.simd:5512 [D] s_b_7_22 = s_b_7_18+s_b_7_21 */
    auto s_b_7_22 = emitter.add(s_b_7_18, s_b_7_21);
    /* execute.simd:5512 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:5512 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:5515 [F] s_b_7_25=sym_20556_3_parameter_inst.rd (const) */
    /* execute.simd:5515 [D] s_b_7_26 = (v2u64)s_b_7_24 */
    auto s_b_7_26 = emitter.reinterpret(s_b_7_24, emitter.context().types().v2u64());
    /* execute.simd:5515 [D] s_b_7_27: WriteRegBank 21:s_b_7_25 = s_b_7_26 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_26,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_26);
    /* execute.simd:0 [F] s_b_7_28: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:5519 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5445 [F] s_b_8_1: Jump b_1 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_shl_simd(const aarch64_decode_a64_SIMD_SHIFT_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4870 [F] s_b_0_0=sym_22705_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4870 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4871 [F] s_b_1_0=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4871 [F] s_b_1_1=sym_22705_3_parameter_inst.rn (const) */
    /* execute.simd:6275 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:4871 [F] s_b_1_3=sym_22705_3_parameter_inst.shift_amount (const) */
    /* execute.simd:4871 [F] s_b_1_4 = (u64)s_b_1_3 (const) */
    /* execute.simd:4871 [D] s_b_1_5 = s_b_1_2<<s_b_1_4 */
    auto s_b_1_5 = emitter.shl(s_b_1_2, emitter.const_u64(((uint64_t)insn.shift_amount)));
    /* execute.simd:6246 [D] s_b_1_6: WriteRegBank 2:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6247 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6247 [F] s_b_1_8: WriteRegBank 3:s_b_1_0 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4873 [F] s_b_3_0=sym_22705_3_parameter_inst.arrangement (const) */
    /* execute.simd:4874 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:4880 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:4885 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:4891 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:4896 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:4902 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:4907 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:4873 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_10;
      break;
    default:
      goto fixed_block_b_2;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4875 [F] s_b_4_0=sym_22705_3_parameter_inst.rn (const) */
    /* execute.simd:4875 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:4876 [F] s_b_4_2=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4876 [F] s_b_4_3=sym_22705_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_4_4 = (v8u8)s_b_4_3 (const) */
    auto s_b_4_4 = wutils::Vector<uint8_t, 8>(insn.shift_amount);
    /* execute.simd:4876 [D] s_b_4_5 = s_b_4_1<<s_b_4_4 */
    auto s_b_4_5 = emitter.shl(s_b_4_1, emitter.constant_vector_splat(s_b_4_4[0], emitter.context().types().v8u8()));
    /* execute.simd:4876 [D] s_b_4_6: WriteRegBank 15:s_b_4_2 = s_b_4_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_5);
    /* execute.simd:4877 [F] s_b_4_7=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4877 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:4877 [F] s_b_4_9: WriteRegBank 3:s_b_4_7 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4881 [F] s_b_5_0=sym_22705_3_parameter_inst.rn (const) */
    /* execute.simd:4881 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:4882 [F] s_b_5_2=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4882 [F] s_b_5_3=sym_22705_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_5_4 = (v16u8)s_b_5_3 (const) */
    auto s_b_5_4 = wutils::Vector<uint8_t, 16>(insn.shift_amount);
    /* execute.simd:4882 [D] s_b_5_5 = s_b_5_1<<s_b_5_4 */
    auto s_b_5_5 = emitter.shl(s_b_5_1, emitter.constant_vector_splat(s_b_5_4[0], emitter.context().types().v16u8()));
    /* execute.simd:4882 [D] s_b_5_6: WriteRegBank 16:s_b_5_2 = s_b_5_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5);
    /* execute.simd:0 [F] s_b_5_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4886 [F] s_b_6_0=sym_22705_3_parameter_inst.rn (const) */
    /* execute.simd:4886 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:4887 [F] s_b_6_2=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4887 [F] s_b_6_3=sym_22705_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_6_4 = (v4u16)s_b_6_3 (const) */
    auto s_b_6_4 = wutils::Vector<uint16_t, 4>(insn.shift_amount);
    /* execute.simd:4887 [D] s_b_6_5 = s_b_6_1<<s_b_6_4 */
    auto s_b_6_5 = emitter.shl(s_b_6_1, emitter.constant_vector_splat(s_b_6_4[0], emitter.context().types().v4u16()));
    /* execute.simd:4887 [D] s_b_6_6: WriteRegBank 17:s_b_6_2 = s_b_6_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_5);
    /* execute.simd:4888 [F] s_b_6_7=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4888 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:4888 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4892 [F] s_b_7_0=sym_22705_3_parameter_inst.rn (const) */
    /* execute.simd:4892 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:4893 [F] s_b_7_2=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4893 [F] s_b_7_3=sym_22705_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_7_4 = (v8u16)s_b_7_3 (const) */
    auto s_b_7_4 = wutils::Vector<uint16_t, 8>(insn.shift_amount);
    /* execute.simd:4893 [D] s_b_7_5 = s_b_7_1<<s_b_7_4 */
    auto s_b_7_5 = emitter.shl(s_b_7_1, emitter.constant_vector_splat(s_b_7_4[0], emitter.context().types().v8u16()));
    /* execute.simd:4893 [D] s_b_7_6: WriteRegBank 18:s_b_7_2 = s_b_7_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5);
    /* execute.simd:0 [F] s_b_7_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4897 [F] s_b_8_0=sym_22705_3_parameter_inst.rn (const) */
    /* execute.simd:4897 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:4898 [F] s_b_8_2=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4898 [F] s_b_8_3=sym_22705_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_8_4 = (v2u32)s_b_8_3 (const) */
    auto s_b_8_4 = wutils::Vector<uint32_t, 2>(insn.shift_amount);
    /* execute.simd:4898 [D] s_b_8_5 = s_b_8_1<<s_b_8_4 */
    auto s_b_8_5 = emitter.shl(s_b_8_1, emitter.constant_vector_splat(s_b_8_4[0], emitter.context().types().v2u32()));
    /* execute.simd:4898 [D] s_b_8_6: WriteRegBank 19:s_b_8_2 = s_b_8_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_5);
    /* execute.simd:4899 [F] s_b_8_7=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4899 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:4899 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4903 [F] s_b_9_0=sym_22705_3_parameter_inst.rn (const) */
    /* execute.simd:4903 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:4904 [F] s_b_9_2=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4904 [F] s_b_9_3=sym_22705_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_9_4 = (v4u32)s_b_9_3 (const) */
    auto s_b_9_4 = wutils::Vector<uint32_t, 4>(insn.shift_amount);
    /* execute.simd:4904 [D] s_b_9_5 = s_b_9_1<<s_b_9_4 */
    auto s_b_9_5 = emitter.shl(s_b_9_1, emitter.constant_vector_splat(s_b_9_4[0], emitter.context().types().v4u32()));
    /* execute.simd:4904 [D] s_b_9_6: WriteRegBank 20:s_b_9_2 = s_b_9_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_5);
    /* execute.simd:0 [F] s_b_9_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4908 [F] s_b_10_0=sym_22705_3_parameter_inst.rn (const) */
    /* execute.simd:4908 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:4909 [F] s_b_10_2=sym_22705_3_parameter_inst.rd (const) */
    /* execute.simd:4909 [F] s_b_10_3=sym_22705_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_10_4 = (v2u64)s_b_10_3 (const) */
    auto s_b_10_4 = wutils::Vector<uint64_t, 2>(insn.shift_amount);
    /* execute.simd:4909 [D] s_b_10_5 = s_b_10_1<<s_b_10_4 */
    auto s_b_10_5 = emitter.shl(s_b_10_1, emitter.constant_vector_splat(s_b_10_4[0], emitter.context().types().v2u64()));
    /* execute.simd:4909 [D] s_b_10_6: WriteRegBank 21:s_b_10_2 = s_b_10_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_5);
    /* execute.simd:0 [F] s_b_10_7: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_smsubl(const aarch64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_129301_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2368 [F] s_b_0_0=sym_24710_3_parameter_inst.rn (const) */
    /* execute.a64:2668 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2668 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_0_4 = constant s64 0 (const) */
    /* execute.a64:2668 [D] s_b_0_5 = ReadRegBank 1:s_b_0_0 (u32) */
    auto s_b_0_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_0_5,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_0_6 = (s32)s_b_0_5 */
    auto s_b_0_6 = emitter.reinterpret(s_b_0_5, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_0_7 = (s64)s_b_0_6 */
    auto s_b_0_7 = emitter.sx(s_b_0_6, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_0_8: Select s_b_0_3 ? s_b_0_4 : s_b_0_7 */
    dbt::el::Value *s_b_0_8;
    s_b_0_8 = (s_b_0_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_0_7);
    /* execute.a64:2369 [F] s_b_0_9=sym_24710_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [F] s_b_0_10 = (u32)s_b_0_9 (const) */
    /* execute.a64:2668 [F] s_b_0_11 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_0_12 = s_b_0_10==s_b_0_11 (const) */
    uint8_t s_b_0_12 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_0_13 = constant s64 0 (const) */
    /* execute.a64:2668 [D] s_b_0_14 = ReadRegBank 1:s_b_0_9 (u32) */
    auto s_b_0_14 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_0_14,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_0_15 = (s32)s_b_0_14 */
    auto s_b_0_15 = emitter.reinterpret(s_b_0_14, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_0_16 = (s64)s_b_0_15 */
    auto s_b_0_16 = emitter.sx(s_b_0_15, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_0_17: Select s_b_0_12 ? s_b_0_13 : s_b_0_16 */
    dbt::el::Value *s_b_0_17;
    s_b_0_17 = (s_b_0_12) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_0_16);
    /* execute.a64:2370 [F] s_b_0_18=sym_24710_3_parameter_inst.ra (const) */
    /* execute.a64:2666 [F] s_b_0_19 = (u32)s_b_0_18 (const) */
    /* execute.a64:2666 [F] s_b_0_20 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_0_21 = s_b_0_19==s_b_0_20 (const) */
    uint8_t s_b_0_21 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_0_22 = constant s64 0 (const) */
    /* execute.a64:2666 [D] s_b_0_23 = ReadRegBank 0:s_b_0_18 (u64) */
    auto s_b_0_23 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_0_23,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_0_24 = (s64)s_b_0_23 */
    auto s_b_0_24 = emitter.reinterpret(s_b_0_23, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_0_25: Select s_b_0_21 ? s_b_0_22 : s_b_0_24 */
    dbt::el::Value *s_b_0_25;
    s_b_0_25 = (s_b_0_21) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_0_24);
    /* execute.a64:2372 [D] s_b_0_26 = (s64)s_b_0_8 */
    auto s_b_0_26 = (dbt::el::Value *)s_b_0_8;
    /* execute.a64:2372 [D] s_b_0_27 = s_b_0_26*s_b_0_17 */
    auto s_b_0_27 = emitter.mul(s_b_0_26, s_b_0_17);
    /* execute.a64:2372 [D] s_b_0_28 = s_b_0_25-s_b_0_27 */
    auto s_b_0_28 = emitter.sub(s_b_0_25, s_b_0_27);
    /* execute.a64:2372 [D] s_b_0_29 = (u64)s_b_0_28 */
    auto s_b_0_29 = emitter.reinterpret(s_b_0_28, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_0_30=sym_24710_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_0_31: sym_129301_3_parameter_value = s_b_0_29, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_129301_3_parameter_value, s_b_0_29);
    /* execute.a64:2682 [F] s_b_0_32 = (u32)s_b_0_30 (const) */
    /* execute.a64:2682 [F] s_b_0_33 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_0_34 = s_b_0_32==s_b_0_33 (const) */
    uint8_t s_b_0_34 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_0_35: If s_b_0_34: Jump b_1 else b_2 (const) */
    if (s_b_0_34) 
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
    /* execute.a64:2684 [F] s_b_2_0=sym_24710_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_2_1 = sym_129301_3_parameter_value uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_129301_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_st1(const aarch64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_130698_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_130695_1_tmp_s_b_5_4;
  uint8_t CV_sym_130613_3_parameter_rt;
  auto DV_sym_130521_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_130618_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_130621_3_parameter_lane;
  auto DV_sym_30343_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30349_0_rt;
  uint8_t CV_sym_30361_0_lane;
  auto DV_sym_130504_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2477 [F] s_b_0_0=sym_30337_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2479 [F] s_b_1_0 = sym_30349_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30349_0_rt;
    /* execute.simd:2479 [F] s_b_1_1=sym_30337_3_parameter_inst.regcnt (const) */
    /* execute.simd:2479 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2479 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2480 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2480 [F] s_b_2_1: sym_30361_0_lane = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30361_0_lane = (uint8_t)0ULL;
    /* execute.simd:2480 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2480 [F] s_b_4_0 = sym_30361_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30361_0_lane;
    /* execute.simd:2480 [F] s_b_4_1=sym_30337_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2480 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2480 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2481 [F] s_b_5_0=sym_30337_3_parameter_inst.arrangement (const) */
    /* execute.simd:2481 [F] s_b_5_1=sym_30337_3_parameter_inst.rt (const) */
    /* execute.simd:2481 [F] s_b_5_2 = sym_30349_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30349_0_rt;
    /* execute.simd:2481 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2481 [F] s_b_5_4 = sym_30361_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30361_0_lane;
    /* execute.simd:2481 [D] s_b_5_5 = sym_30343_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30343_0_address, emitter.context().types().u64());
    /* execute.simd:2481 [F] s_b_5_6: sym_130613_3_parameter_rt = s_b_5_3 (const), dominates: s_b_18_0 s_b_22_0 s_b_21_0 s_b_20_0 s_b_19_0 s_b_17_0 s_b_16_0  */
    CV_sym_130613_3_parameter_rt = s_b_5_3;
    /* execute.simd:2481 [F] s_b_5_7: sym_130621_3_parameter_lane = s_b_5_4 (const), dominates: s_b_18_3 s_b_22_3 s_b_21_3 s_b_20_3 s_b_19_3 s_b_17_3 s_b_16_3  */
    CV_sym_130621_3_parameter_lane = s_b_5_4;
    /* execute.simd:2481 [D] s_b_5_8: sym_130618_3_parameter_addr = s_b_5_5, dominates: s_b_18_2 s_b_22_2 s_b_21_2 s_b_20_2 s_b_19_2 s_b_17_2 s_b_16_2  */
    emitter.store_local(DV_sym_130618_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_130695_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_23_1  */
    CV_sym_130695_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_130698_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_130698_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3882 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3887 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3892 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3897 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3902 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3907 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3912 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3881 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_15 (const) -> b_18, b_22, b_21, b_20, b_19, b_17, b_16, b_15,  */
    switch (insn.arrangement) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_21;
      break;
    default:
      goto fixed_block_b_15;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2479 [F] s_b_6_0 = sym_30349_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30349_0_rt;
    /* execute.simd:2479 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2479 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2479 [F] s_b_6_3: sym_30349_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30349_0_rt = s_b_6_2;
    /* execute.simd:2479 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2701 [F] s_b_7_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_7_1 = __builtin_get_feature */
    uint32_t s_b_7_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(s_b_7_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_7_4: If s_b_7_3: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2733 [F] s_b_8_0=sym_30337_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_130504_0_return_symbol = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_130504_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_12,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_130504_0_return_symbol uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_130504_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2477 [D] s_b_9_1: sym_30343_0_address = s_b_9_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30343_0_address, s_b_9_0);
    /* execute.simd:2479 [F] s_b_9_2 = constant u8 0 (const) */
    /* execute.simd:2479 [F] s_b_9_3: sym_30349_0_rt = s_b_9_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30349_0_rt = (uint8_t)0ULL;
    /* execute.simd:2479 [F] s_b_9_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2702 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_10_1: sym_130521_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_130521_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2702 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_7,  */
  fixed_block_b_11: 
  {
    /* execute.a64:3012 [F] s_b_11_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_11_1 = __builtin_get_feature */
    uint32_t s_b_11_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_11_2 = (u8)s_b_11_1 (const) */
    /* execute.a64:2704 [F] s_b_11_3 = (u32)s_b_11_2 (const) */
    /* execute.a64:2704 [F] s_b_11_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_11_5 = s_b_11_3==s_b_11_4 (const) */
    uint8_t s_b_11_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_11_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_11_6: If s_b_11_5: Jump b_13 else b_14 (const) */
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
    /* execute.a64:2731 [D] s_b_12_0 = sym_130521_1__R_s_b_3_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_130521_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1: sym_130504_0_return_symbol = s_b_12_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_130504_0_return_symbol, s_b_12_0);
    /* ???:4294967295 [F] s_b_12_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2705 [D] s_b_13_0 = ReadReg 20 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_13_1: sym_130521_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_130521_1__R_s_b_3_0, s_b_13_0);
    /* execute.a64:2705 [F] s_b_13_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2707 [D] s_b_14_0 = ReadReg 21 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_14_1: sym_130521_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_130521_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2707 [F] s_b_14_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3918 [D] s_b_15_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_15_1: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3913 [F] s_b_16_0 = sym_130613_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_0 = CV_sym_130613_3_parameter_rt;
    /* execute.simd:3913 [D] s_b_16_1 = ReadRegBank 21:s_b_16_0 (v2u64) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))),s_b_16_1,emitter.const_u8(16));
    }
    /* execute.simd:3914 [D] s_b_16_2 = sym_130618_3_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_130618_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3914 [F] s_b_16_3 = sym_130621_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_3 = CV_sym_130621_3_parameter_lane;
    /* execute.simd:3914 [D] s_b_16_1[s_b_16_3] */
    auto s_b_16_4 = emitter.vector_extract(s_b_16_1, emitter.const_u8(s_b_16_3));
    /* ???:4294967295 [D] s_b_16_5: Store 8 s_b_16_2 <= s_b_16_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_16_2, s_b_16_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_16_2, s_b_16_4);
    /* execute.simd:0 [F] s_b_16_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3883 [F] s_b_17_0 = sym_130613_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_0 = CV_sym_130613_3_parameter_rt;
    /* execute.simd:3883 [D] s_b_17_1 = ReadRegBank 15:s_b_17_0 (v8u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.simd:3884 [D] s_b_17_2 = sym_130618_3_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_130618_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3884 [F] s_b_17_3 = sym_130621_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_3 = CV_sym_130621_3_parameter_lane;
    /* execute.simd:3884 [D] s_b_17_1[s_b_17_3] */
    auto s_b_17_4 = emitter.vector_extract(s_b_17_1, emitter.const_u8(s_b_17_3));
    /* ???:4294967295 [D] s_b_17_5: Store 1 s_b_17_2 <= s_b_17_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_17_2, s_b_17_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_17_2, s_b_17_4);
    /* execute.simd:0 [F] s_b_17_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3888 [F] s_b_18_0 = sym_130613_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_130613_3_parameter_rt;
    /* execute.simd:3888 [D] s_b_18_1 = ReadRegBank 16:s_b_18_0 (v16u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(16));
    }
    /* execute.simd:3889 [D] s_b_18_2 = sym_130618_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_130618_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3889 [F] s_b_18_3 = sym_130621_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_130621_3_parameter_lane;
    /* execute.simd:3889 [D] s_b_18_1[s_b_18_3] */
    auto s_b_18_4 = emitter.vector_extract(s_b_18_1, emitter.const_u8(s_b_18_3));
    /* ???:4294967295 [D] s_b_18_5: Store 1 s_b_18_2 <= s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_18_2, s_b_18_4);
    /* execute.simd:0 [F] s_b_18_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3893 [F] s_b_19_0 = sym_130613_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_130613_3_parameter_rt;
    /* execute.simd:3893 [D] s_b_19_1 = ReadRegBank 17:s_b_19_0 (v4u16) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.simd:3894 [D] s_b_19_2 = sym_130618_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_130618_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3894 [F] s_b_19_3 = sym_130621_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_130621_3_parameter_lane;
    /* execute.simd:3894 [D] s_b_19_1[s_b_19_3] */
    auto s_b_19_4 = emitter.vector_extract(s_b_19_1, emitter.const_u8(s_b_19_3));
    /* ???:4294967295 [D] s_b_19_5: Store 2 s_b_19_2 <= s_b_19_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_19_2, s_b_19_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_19_2, s_b_19_4);
    /* execute.simd:0 [F] s_b_19_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3898 [F] s_b_20_0 = sym_130613_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_130613_3_parameter_rt;
    /* execute.simd:3898 [D] s_b_20_1 = ReadRegBank 18:s_b_20_0 (v8u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(16));
    }
    /* execute.simd:3899 [D] s_b_20_2 = sym_130618_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_130618_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3899 [F] s_b_20_3 = sym_130621_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_130621_3_parameter_lane;
    /* execute.simd:3899 [D] s_b_20_1[s_b_20_3] */
    auto s_b_20_4 = emitter.vector_extract(s_b_20_1, emitter.const_u8(s_b_20_3));
    /* ???:4294967295 [D] s_b_20_5: Store 2 s_b_20_2 <= s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_20_2, s_b_20_4);
    /* execute.simd:0 [F] s_b_20_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3903 [F] s_b_21_0 = sym_130613_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_130613_3_parameter_rt;
    /* execute.simd:3903 [D] s_b_21_1 = ReadRegBank 19:s_b_21_0 (v2u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(8));
    }
    /* execute.simd:3904 [D] s_b_21_2 = sym_130618_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_130618_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3904 [F] s_b_21_3 = sym_130621_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_130621_3_parameter_lane;
    /* execute.simd:3904 [D] s_b_21_1[s_b_21_3] */
    auto s_b_21_4 = emitter.vector_extract(s_b_21_1, emitter.const_u8(s_b_21_3));
    /* ???:4294967295 [D] s_b_21_5: Store 4 s_b_21_2 <= s_b_21_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_21_2, s_b_21_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_21_2, s_b_21_4);
    /* execute.simd:0 [F] s_b_21_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3908 [F] s_b_22_0 = sym_130613_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_130613_3_parameter_rt;
    /* execute.simd:3908 [D] s_b_22_1 = ReadRegBank 20:s_b_22_0 (v4u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3909 [D] s_b_22_2 = sym_130618_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_130618_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3909 [F] s_b_22_3 = sym_130621_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_130621_3_parameter_lane;
    /* execute.simd:3909 [D] s_b_22_1[s_b_22_3] */
    auto s_b_22_4 = emitter.vector_extract(s_b_22_1, emitter.const_u8(s_b_22_3));
    /* ???:4294967295 [D] s_b_22_5: Store 4 s_b_22_2 <= s_b_22_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_22_2, s_b_22_4);
    /* execute.simd:0 [F] s_b_22_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_15, b_16, b_17, b_18, b_19, b_20, b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* ???:4294967295 [D] s_b_23_0 = sym_130698_1_tmp_s_b_5_5 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_130698_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1 = sym_130695_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_23_1 = CV_sym_130695_1_tmp_s_b_5_4;
    /* execute.simd:2482 [F] s_b_23_2=sym_30337_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* ???:4294967295 [D] s_b_23_4 = s_b_23_0+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2482 [D] s_b_23_5: sym_30343_0_address = s_b_23_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30343_0_address, s_b_23_4);
    /* execute.simd:2480 [F] s_b_23_6 = constant u8 1 (const) */
    /* execute.simd:2480 [F] s_b_23_7 = s_b_23_1+s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(s_b_23_1 + (uint8_t)1ULL));
    /* execute.simd:2480 [F] s_b_23_8: sym_30361_0_lane = s_b_23_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30361_0_lane = s_b_23_7;
    /* execute.simd:2480 [F] s_b_23_9: Jump b_4 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_st4(const aarch64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_133047_3_parameter_rt;
  auto DV_sym_133132_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_133129_1_tmp_s_b_5_2;
  auto DV_sym_132955_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132938_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_133055_3_parameter_lane;
  auto DV_sym_30943_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30949_0_lane;
  uint8_t CV_sym_30961_0_rt;
  auto DV_sym_133052_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2513 [F] s_b_0_0=sym_30937_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2515 [F] s_b_1_0 = sym_30949_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30949_0_lane;
    /* execute.simd:2515 [F] s_b_1_1=sym_30937_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2515 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2515 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2516 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2516 [F] s_b_2_1: sym_30961_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30961_0_rt = (uint8_t)0ULL;
    /* execute.simd:2516 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2516 [F] s_b_4_0 = sym_30961_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30961_0_rt;
    /* execute.simd:2516 [F] s_b_4_1=sym_30937_3_parameter_inst.regcnt (const) */
    /* execute.simd:2516 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2516 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2517 [F] s_b_5_0=sym_30937_3_parameter_inst.arrangement (const) */
    /* execute.simd:2517 [F] s_b_5_1=sym_30937_3_parameter_inst.rt (const) */
    /* execute.simd:2517 [F] s_b_5_2 = sym_30961_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30961_0_rt;
    /* execute.simd:2517 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2517 [F] s_b_5_4 = sym_30949_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30949_0_lane;
    /* execute.simd:2517 [D] s_b_5_5 = sym_30943_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30943_0_address, emitter.context().types().u64());
    /* execute.simd:2517 [F] s_b_5_6: sym_133047_3_parameter_rt = s_b_5_3 (const), dominates: s_b_22_0 s_b_21_0 s_b_17_0 s_b_20_0 s_b_19_0 s_b_16_0 s_b_18_0  */
    CV_sym_133047_3_parameter_rt = s_b_5_3;
    /* execute.simd:2517 [F] s_b_5_7: sym_133055_3_parameter_lane = s_b_5_4 (const), dominates: s_b_22_3 s_b_21_3 s_b_17_3 s_b_20_3 s_b_19_3 s_b_16_3 s_b_18_3  */
    CV_sym_133055_3_parameter_lane = s_b_5_4;
    /* execute.simd:2517 [D] s_b_5_8: sym_133052_3_parameter_addr = s_b_5_5, dominates: s_b_22_2 s_b_21_2 s_b_17_2 s_b_20_2 s_b_19_2 s_b_16_2 s_b_18_2  */
    emitter.store_local(DV_sym_133052_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_133129_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_23_1  */
    CV_sym_133129_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_133132_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_133132_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3882 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3887 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3892 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3897 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3902 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3907 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3912 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3881 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_15 (const) -> b_22, b_21, b_17, b_20, b_19, b_16, b_15, b_18,  */
    switch (insn.arrangement) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_20;
      break;
    default:
      goto fixed_block_b_15;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2515 [F] s_b_6_0 = sym_30949_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30949_0_lane;
    /* execute.simd:2515 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2515 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2515 [F] s_b_6_3: sym_30949_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30949_0_lane = s_b_6_2;
    /* execute.simd:2515 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2701 [F] s_b_7_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_7_1 = __builtin_get_feature */
    uint32_t s_b_7_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(s_b_7_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_7_4: If s_b_7_3: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2733 [F] s_b_8_0=sym_30937_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_132938_0_return_symbol = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_132938_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_12,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_132938_0_return_symbol uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_132938_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2513 [D] s_b_9_1: sym_30943_0_address = s_b_9_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30943_0_address, s_b_9_0);
    /* execute.simd:2515 [F] s_b_9_2 = constant u8 0 (const) */
    /* execute.simd:2515 [F] s_b_9_3: sym_30949_0_lane = s_b_9_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30949_0_lane = (uint8_t)0ULL;
    /* execute.simd:2515 [F] s_b_9_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2702 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_10_1: sym_132955_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_132955_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2702 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_7,  */
  fixed_block_b_11: 
  {
    /* execute.a64:3012 [F] s_b_11_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_11_1 = __builtin_get_feature */
    uint32_t s_b_11_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_11_2 = (u8)s_b_11_1 (const) */
    /* execute.a64:2704 [F] s_b_11_3 = (u32)s_b_11_2 (const) */
    /* execute.a64:2704 [F] s_b_11_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_11_5 = s_b_11_3==s_b_11_4 (const) */
    uint8_t s_b_11_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_11_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_11_6: If s_b_11_5: Jump b_13 else b_14 (const) */
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
    /* execute.a64:2731 [D] s_b_12_0 = sym_132955_1__R_s_b_3_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_132955_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1: sym_132938_0_return_symbol = s_b_12_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_132938_0_return_symbol, s_b_12_0);
    /* ???:4294967295 [F] s_b_12_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2705 [D] s_b_13_0 = ReadReg 20 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_13_1: sym_132955_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_132955_1__R_s_b_3_0, s_b_13_0);
    /* execute.a64:2705 [F] s_b_13_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2707 [D] s_b_14_0 = ReadReg 21 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_14_1: sym_132955_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_132955_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2707 [F] s_b_14_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3918 [D] s_b_15_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_15_1: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3913 [F] s_b_16_0 = sym_133047_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_0 = CV_sym_133047_3_parameter_rt;
    /* execute.simd:3913 [D] s_b_16_1 = ReadRegBank 21:s_b_16_0 (v2u64) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))),s_b_16_1,emitter.const_u8(16));
    }
    /* execute.simd:3914 [D] s_b_16_2 = sym_133052_3_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_133052_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3914 [F] s_b_16_3 = sym_133055_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_3 = CV_sym_133055_3_parameter_lane;
    /* execute.simd:3914 [D] s_b_16_1[s_b_16_3] */
    auto s_b_16_4 = emitter.vector_extract(s_b_16_1, emitter.const_u8(s_b_16_3));
    /* ???:4294967295 [D] s_b_16_5: Store 8 s_b_16_2 <= s_b_16_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_16_2, s_b_16_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_16_2, s_b_16_4);
    /* execute.simd:0 [F] s_b_16_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3883 [F] s_b_17_0 = sym_133047_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_0 = CV_sym_133047_3_parameter_rt;
    /* execute.simd:3883 [D] s_b_17_1 = ReadRegBank 15:s_b_17_0 (v8u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.simd:3884 [D] s_b_17_2 = sym_133052_3_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_133052_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3884 [F] s_b_17_3 = sym_133055_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_3 = CV_sym_133055_3_parameter_lane;
    /* execute.simd:3884 [D] s_b_17_1[s_b_17_3] */
    auto s_b_17_4 = emitter.vector_extract(s_b_17_1, emitter.const_u8(s_b_17_3));
    /* ???:4294967295 [D] s_b_17_5: Store 1 s_b_17_2 <= s_b_17_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_17_2, s_b_17_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_17_2, s_b_17_4);
    /* execute.simd:0 [F] s_b_17_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3888 [F] s_b_18_0 = sym_133047_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_133047_3_parameter_rt;
    /* execute.simd:3888 [D] s_b_18_1 = ReadRegBank 16:s_b_18_0 (v16u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(16));
    }
    /* execute.simd:3889 [D] s_b_18_2 = sym_133052_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_133052_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3889 [F] s_b_18_3 = sym_133055_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_133055_3_parameter_lane;
    /* execute.simd:3889 [D] s_b_18_1[s_b_18_3] */
    auto s_b_18_4 = emitter.vector_extract(s_b_18_1, emitter.const_u8(s_b_18_3));
    /* ???:4294967295 [D] s_b_18_5: Store 1 s_b_18_2 <= s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_18_2, s_b_18_4);
    /* execute.simd:0 [F] s_b_18_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3893 [F] s_b_19_0 = sym_133047_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_133047_3_parameter_rt;
    /* execute.simd:3893 [D] s_b_19_1 = ReadRegBank 17:s_b_19_0 (v4u16) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.simd:3894 [D] s_b_19_2 = sym_133052_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_133052_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3894 [F] s_b_19_3 = sym_133055_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_133055_3_parameter_lane;
    /* execute.simd:3894 [D] s_b_19_1[s_b_19_3] */
    auto s_b_19_4 = emitter.vector_extract(s_b_19_1, emitter.const_u8(s_b_19_3));
    /* ???:4294967295 [D] s_b_19_5: Store 2 s_b_19_2 <= s_b_19_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_19_2, s_b_19_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_19_2, s_b_19_4);
    /* execute.simd:0 [F] s_b_19_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3898 [F] s_b_20_0 = sym_133047_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_133047_3_parameter_rt;
    /* execute.simd:3898 [D] s_b_20_1 = ReadRegBank 18:s_b_20_0 (v8u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(16));
    }
    /* execute.simd:3899 [D] s_b_20_2 = sym_133052_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_133052_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3899 [F] s_b_20_3 = sym_133055_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_133055_3_parameter_lane;
    /* execute.simd:3899 [D] s_b_20_1[s_b_20_3] */
    auto s_b_20_4 = emitter.vector_extract(s_b_20_1, emitter.const_u8(s_b_20_3));
    /* ???:4294967295 [D] s_b_20_5: Store 2 s_b_20_2 <= s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_20_2, s_b_20_4);
    /* execute.simd:0 [F] s_b_20_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3903 [F] s_b_21_0 = sym_133047_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_133047_3_parameter_rt;
    /* execute.simd:3903 [D] s_b_21_1 = ReadRegBank 19:s_b_21_0 (v2u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(8));
    }
    /* execute.simd:3904 [D] s_b_21_2 = sym_133052_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_133052_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3904 [F] s_b_21_3 = sym_133055_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_133055_3_parameter_lane;
    /* execute.simd:3904 [D] s_b_21_1[s_b_21_3] */
    auto s_b_21_4 = emitter.vector_extract(s_b_21_1, emitter.const_u8(s_b_21_3));
    /* ???:4294967295 [D] s_b_21_5: Store 4 s_b_21_2 <= s_b_21_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_21_2, s_b_21_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_21_2, s_b_21_4);
    /* execute.simd:0 [F] s_b_21_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3908 [F] s_b_22_0 = sym_133047_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_133047_3_parameter_rt;
    /* execute.simd:3908 [D] s_b_22_1 = ReadRegBank 20:s_b_22_0 (v4u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3909 [D] s_b_22_2 = sym_133052_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_133052_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3909 [F] s_b_22_3 = sym_133055_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_133055_3_parameter_lane;
    /* execute.simd:3909 [D] s_b_22_1[s_b_22_3] */
    auto s_b_22_4 = emitter.vector_extract(s_b_22_1, emitter.const_u8(s_b_22_3));
    /* ???:4294967295 [D] s_b_22_5: Store 4 s_b_22_2 <= s_b_22_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_22_2, s_b_22_4);
    /* execute.simd:0 [F] s_b_22_6: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_15, b_16, b_17, b_18, b_19, b_20, b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* ???:4294967295 [D] s_b_23_0 = sym_133132_1_tmp_s_b_5_5 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_133132_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1 = sym_133129_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_23_1 = CV_sym_133129_1_tmp_s_b_5_2;
    /* execute.simd:2518 [F] s_b_23_2=sym_30937_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* ???:4294967295 [D] s_b_23_4 = s_b_23_0+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2518 [D] s_b_23_5: sym_30943_0_address = s_b_23_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30943_0_address, s_b_23_4);
    /* execute.simd:2516 [F] s_b_23_6 = constant u8 1 (const) */
    /* execute.simd:2516 [F] s_b_23_7 = s_b_23_1+s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(s_b_23_1 + (uint8_t)1ULL));
    /* execute.simd:2516 [F] s_b_23_8: sym_30961_0_rt = s_b_23_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30961_0_rt = s_b_23_7;
    /* execute.simd:2516 [F] s_b_23_9: Jump b_4 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stlxrh(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_135764_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_135781_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31360_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:669 [F] s_b_0_0=sym_31354_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_5_0=sym_31354_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_135764_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_135764_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_135764_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_135764_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:669 [D] s_b_6_1: sym_31360_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_31360_0_address, s_b_6_0);
    /* execute.a64:671 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:671 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:671 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
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
    /* execute.a64:2702 [D] s_b_7_1: sym_135781_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135781_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2731 [D] s_b_9_0 = sym_135781_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_135781_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_135764_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_135764_0_return_symbol, s_b_9_0);
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
    /* execute.a64:2705 [D] s_b_10_1: sym_135781_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135781_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2707 [D] s_b_11_1: sym_135781_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135781_1__R_s_b_3_0, s_b_11_0);
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
        /* execute.a64:672 [D] s_b_1_0 = sym_31360_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_31360_0_address, emitter.context().types().u64());
        /* execute.a64:672 [F] s_b_1_1=sym_31354_3_parameter_inst.rt (const) */
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
        /* execute.a64:673 [F] s_b_1_11=sym_31354_3_parameter_inst.rs (const) */
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
        /* execute.a64:675 [F] s_b_3_0=sym_31354_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_12_0=sym_31354_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_13_0=sym_31354_3_parameter_inst.rs (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_str_reg_simd(const aarch64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_32064_0_shift;
  uint64_t CV_sym_32091_0_rm;
  auto DV_sym_32091_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32189_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_139712_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_139695_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4018 [F] s_b_0_0=sym_32046_3_parameter_inst.S (const) */
    /* execute.simd:4018 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4018 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4018 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.S) == (uint32_t)0ULL));
    /* execute.simd:4018 [F] s_b_0_4 = constant u8 0 (const) */
    /* execute.simd:4018 [F] s_b_0_5=sym_32046_3_parameter_inst.X (const) */
    /* execute.simd:4018 [F] s_b_0_6 = (u32)s_b_0_5 (const) */
    /* execute.simd:4018 [F] s_b_0_7 = constant u32 1 (const) */
    /* execute.simd:4018 [F] s_b_0_8 = s_b_0_6==s_b_0_7 (const) */
    uint8_t s_b_0_8 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* execute.simd:4018 [F] s_b_0_9 = constant u8 4 (const) */
    /* execute.simd:4018 [F] s_b_0_10=sym_32046_3_parameter_inst.size (const) */
    /* execute.simd:4018 [F] s_b_0_11 = (u8)s_b_0_10 (const) */
    /* execute.simd:4018 [F] s_b_0_12: Select s_b_0_8 ? s_b_0_9 : s_b_0_11 (const) */
    uint8_t s_b_0_12 = ((uint8_t)(s_b_0_8 ? ((uint8_t)4ULL) : (((uint8_t)insn.size))));
    /* execute.simd:4018 [F] s_b_0_13: Select s_b_0_3 ? s_b_0_4 : s_b_0_12 (const) */
    uint8_t s_b_0_13 = ((uint8_t)(s_b_0_3 ? ((uint8_t)0ULL) : (s_b_0_12)));
    /* execute.simd:4018 [F] s_b_0_14: sym_32064_0_shift = s_b_0_13 (const), dominates: s_b_1_1 s_b_4_1 s_b_6_1 s_b_8_1  */
    CV_sym_32064_0_shift = s_b_0_13;
    /* execute.simd:4021 [F] s_b_0_15=sym_32046_3_parameter_inst.option0 (const) */
    /* execute.simd:4021 [F] s_b_0_16 = (u32)s_b_0_15 (const) */
    /* execute.simd:4021 [F] s_b_0_17 = constant u32 0 (const) */
    /* execute.simd:4021 [F] s_b_0_18 = s_b_0_16==s_b_0_17 (const) */
    uint8_t s_b_0_18 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.simd:4021 [F] s_b_0_19=sym_32046_3_parameter_inst.option21 (const) */
    /* execute.simd:4021 [F] s_b_0_20 = (u32)s_b_0_19 (const) */
    /* execute.simd:4021 [F] s_b_0_21 = constant u32 1 (const) */
    /* execute.simd:4021 [F] s_b_0_22 = s_b_0_20==s_b_0_21 (const) */
    uint8_t s_b_0_22 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_23 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_24 = s_b_0_18!=s_b_0_23 (const) */
    uint8_t s_b_0_24 = ((uint8_t)(s_b_0_18 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_25 = s_b_0_22!=s_b_0_23 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(s_b_0_22 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_26 = s_b_0_24&s_b_0_25 (const) */
    uint8_t s_b_0_26 = ((uint8_t)(s_b_0_24 & s_b_0_25));
    /* execute.simd:4021 [F] s_b_0_27: If s_b_0_26: Jump b_1 else b_3 (const) */
    if (s_b_0_26) 
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
    /* execute.simd:4022 [F] s_b_1_0=sym_32046_3_parameter_inst.rm (const) */
    /* execute.simd:4022 [F] s_b_1_1 = sym_32064_0_shift (const) uint8_t */
    uint8_t s_b_1_1 = CV_sym_32064_0_shift;
    /* execute.a64:2646 [F] s_b_1_2 = (u32)s_b_1_0 (const) */
    /* execute.a64:2646 [F] s_b_1_3 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_4 = s_b_1_2==s_b_1_3 (const) */
    uint8_t s_b_1_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_5 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_6 = ReadRegBank 1:s_b_1_0 (u32) */
    auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_1_6,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_7: Select s_b_1_4 ? s_b_1_5 : s_b_1_6 */
    dbt::el::Value *s_b_1_7;
    s_b_1_7 = (s_b_1_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_6);
    /* execute.a64:2659 [D] s_b_1_8 = (u64)s_b_1_7 */
    auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
    /* execute.a64:2616 [D] s_b_1_9 = (u32)s_b_1_8 */
    auto s_b_1_9 = emitter.truncate(s_b_1_8, emitter.context().types().u32());
    /* execute.a64:2616 [D] s_b_1_10 = (u64)s_b_1_9 */
    auto s_b_1_10 = emitter.zx(s_b_1_9, emitter.context().types().u64());
    /* execute.a64:2616 [F] s_b_1_11 = (u64)s_b_1_1 (const) */
    /* execute.a64:2616 [D] s_b_1_12 = s_b_1_10<<s_b_1_11 */
    auto s_b_1_12 = emitter.shl(s_b_1_10, emitter.const_u64(((uint64_t)s_b_1_1)));
    /* execute.simd:4022 [D] s_b_1_13: sym_32091_0_rm = s_b_1_12, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_32091_0_rm, s_b_1_12);
    /* execute.simd:4022 [F] s_b_1_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_8, b_9,  */
  fixed_block_b_2: 
  {
    /* execute.simd:4034 [F] s_b_2_0=sym_32046_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2730 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_2_4: If s_b_2_3: Jump b_20 else b_21 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4023 [F] s_b_3_0=sym_32046_3_parameter_inst.option0 (const) */
    /* execute.simd:4023 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4023 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4023 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.simd:4023 [F] s_b_3_4=sym_32046_3_parameter_inst.option21 (const) */
    /* execute.simd:4023 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4023 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.simd:4023 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4023 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4024 [F] s_b_4_0=sym_32046_3_parameter_inst.rm (const) */
    /* execute.simd:4024 [F] s_b_4_1 = sym_32064_0_shift (const) uint8_t */
    uint8_t s_b_4_1 = CV_sym_32064_0_shift;
    /* execute.a64:2646 [F] s_b_4_2 = (u32)s_b_4_0 (const) */
    /* execute.a64:2646 [F] s_b_4_3 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_4_4 = s_b_4_2==s_b_4_3 (const) */
    uint8_t s_b_4_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_4_5 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_4_6 = ReadRegBank 1:s_b_4_0 (u32) */
    auto s_b_4_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_4_6,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_4_7: Select s_b_4_4 ? s_b_4_5 : s_b_4_6 */
    dbt::el::Value *s_b_4_7;
    s_b_4_7 = (s_b_4_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_6);
    /* execute.a64:2659 [D] s_b_4_8 = (u64)s_b_4_7 */
    auto s_b_4_8 = emitter.zx(s_b_4_7, emitter.context().types().u64());
    /* execute.a64:2632 [D] s_b_4_9 = (s32)s_b_4_8 */
    auto s_b_4_9 = emitter.truncate(s_b_4_8, emitter.context().types().s32());
    /* execute.a64:2632 [D] s_b_4_10 = (s64)s_b_4_9 */
    auto s_b_4_10 = emitter.sx(s_b_4_9, emitter.context().types().s64());
    /* execute.a64:2632 [D] s_b_4_11 = (u64)s_b_4_10 */
    auto s_b_4_11 = emitter.reinterpret(s_b_4_10, emitter.context().types().u64());
    /* execute.a64:2632 [F] s_b_4_12 = (u64)s_b_4_1 (const) */
    /* execute.a64:2632 [D] s_b_4_13 = s_b_4_11<<s_b_4_12 */
    auto s_b_4_13 = emitter.shl(s_b_4_11, emitter.const_u64(((uint64_t)s_b_4_1)));
    /* execute.simd:4024 [D] s_b_4_14: sym_32091_0_rm = s_b_4_13, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_32091_0_rm, s_b_4_13);
    /* execute.simd:4024 [F] s_b_4_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4025 [F] s_b_5_0=sym_32046_3_parameter_inst.option0 (const) */
    /* execute.simd:4025 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4025 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4025 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.simd:4025 [F] s_b_5_4=sym_32046_3_parameter_inst.option21 (const) */
    /* execute.simd:4025 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4025 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.simd:4025 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.simd:4025 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4026 [F] s_b_6_0=sym_32046_3_parameter_inst.rm (const) */
    /* execute.simd:4026 [F] s_b_6_1 = sym_32064_0_shift (const) uint8_t */
    uint8_t s_b_6_1 = CV_sym_32064_0_shift;
    /* execute.a64:2651 [F] s_b_6_2 = (u32)s_b_6_0 (const) */
    /* execute.a64:2651 [F] s_b_6_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_6_4 = s_b_6_2==s_b_6_3 (const) */
    uint8_t s_b_6_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_6_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_6_6 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_6_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_6_7: Select s_b_6_4 ? s_b_6_5 : s_b_6_6 */
    dbt::el::Value *s_b_6_7;
    s_b_6_7 = (s_b_6_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_6_6);
    /* execute.a64:2620 [F] s_b_6_8 = (u64)s_b_6_1 (const) */
    /* execute.a64:2620 [D] s_b_6_9 = s_b_6_7<<s_b_6_8 */
    auto s_b_6_9 = emitter.shl(s_b_6_7, emitter.const_u64(((uint64_t)s_b_6_1)));
    /* execute.simd:4026 [D] s_b_6_10: sym_32091_0_rm = s_b_6_9, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_32091_0_rm, s_b_6_9);
    /* execute.simd:4026 [F] s_b_6_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4027 [F] s_b_7_0=sym_32046_3_parameter_inst.option0 (const) */
    /* execute.simd:4027 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4027 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.simd:4027 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.simd:4027 [F] s_b_7_4=sym_32046_3_parameter_inst.option21 (const) */
    /* execute.simd:4027 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4027 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.simd:4027 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:4027 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4028 [F] s_b_8_0=sym_32046_3_parameter_inst.rm (const) */
    /* execute.simd:4028 [F] s_b_8_1 = sym_32064_0_shift (const) uint8_t */
    uint8_t s_b_8_1 = CV_sym_32064_0_shift;
    /* execute.a64:2651 [F] s_b_8_2 = (u32)s_b_8_0 (const) */
    /* execute.a64:2651 [F] s_b_8_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_8_4 = s_b_8_2==s_b_8_3 (const) */
    uint8_t s_b_8_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_8_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_8_6 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_8_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_8_7: Select s_b_8_4 ? s_b_8_5 : s_b_8_6 */
    dbt::el::Value *s_b_8_7;
    s_b_8_7 = (s_b_8_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_8_6);
    /* execute.a64:2636 [F] s_b_8_8 = (u64)s_b_8_1 (const) */
    /* execute.a64:2636 [D] s_b_8_9 = s_b_8_7<<s_b_8_8 */
    auto s_b_8_9 = emitter.shl(s_b_8_7, emitter.const_u64(((uint64_t)s_b_8_1)));
    /* execute.simd:4028 [D] s_b_8_10: sym_32091_0_rm = s_b_8_9, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_32091_0_rm, s_b_8_9);
    /* execute.simd:4028 [F] s_b_8_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4030 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.simd:4030 [F] s_b_9_1: sym_32091_0_rm = s_b_9_0 (const), dominates: s_b_22_1  */
    CV_sym_32091_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_32091_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4031 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4030 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_22,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4037 [F] s_b_10_0=sym_32046_3_parameter_inst.X (const) */
    /* execute.simd:4037 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4037 [F] s_b_10_2 = constant u32 1 (const) */
    /* execute.simd:4037 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* execute.simd:4037 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_13, b_14, b_15, b_17, b_18, b_19,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [F] s_b_11_0: Return */
    goto fixed_done;
  }
  /* b_22,  */
  fixed_block_b_12: 
  {
    /* execute.simd:4044 [F] s_b_12_0=sym_32046_3_parameter_inst.size (const) */
    /* execute.simd:4044 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.simd:4044 [F] s_b_12_2 = constant u32 1 (const) */
    /* execute.simd:4044 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:4044 [F] s_b_12_4: If s_b_12_3: Jump b_15 else b_16 (const) */
    if (s_b_12_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4039 [F] s_b_13_0=sym_32046_3_parameter_inst.rt (const) */
    /* execute.simd:4039 [D] s_b_13_1 = sym_32189_0_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_32189_0_address, emitter.context().types().u64());
    /* execute.simd:6280 [D] s_b_13_2 = ReadRegBank 2:s_b_13_0 (u64) */
    auto s_b_13_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_2,emitter.const_u8(8));
    }
    /* execute.simd:6281 [D] s_b_13_3 = ReadRegBank 3:s_b_13_0 (u64) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_13_4: Store 8 s_b_13_1 <= s_b_13_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_13_1, s_b_13_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_13_1, s_b_13_2);
    /* execute.simd:3704 [F] s_b_13_5 = constant u64 8 (const) */
    /* execute.simd:3704 [D] s_b_13_6 = s_b_13_1+s_b_13_5 */
    auto s_b_13_6 = emitter.add(s_b_13_1, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_13_7: Store 8 s_b_13_6 <= s_b_13_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_13_6, s_b_13_3, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_13_6, s_b_13_3);
    /* execute.simd:0 [F] s_b_13_8: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.simd:4042 [F] s_b_14_0=sym_32046_3_parameter_inst.rt (const) */
    /* execute.simd:4042 [D] s_b_14_1 = sym_32189_0_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_32189_0_address, emitter.context().types().u64());
    /* execute.simd:6260 [D] s_b_14_2 = ReadRegBank 4:s_b_14_0 (u8) */
    auto s_b_14_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_2,emitter.const_u8(1));
    }
    /* ???:4294967295 [D] s_b_14_3: Store 1 s_b_14_1 <= s_b_14_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_14_1, s_b_14_2, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_14_1, s_b_14_2);
    /* execute.simd:0 [F] s_b_14_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_12,  */
  fixed_block_b_15: 
  {
    /* execute.simd:4046 [F] s_b_15_0=sym_32046_3_parameter_inst.rt (const) */
    /* execute.simd:4046 [D] s_b_15_1 = sym_32189_0_address uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_32189_0_address, emitter.context().types().u64());
    /* execute.simd:6265 [D] s_b_15_2 = ReadRegBank 5:s_b_15_0 (u16) */
    auto s_b_15_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_15_2,emitter.const_u8(2));
    }
    /* ???:4294967295 [D] s_b_15_3: Store 2 s_b_15_1 <= s_b_15_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_15_1, s_b_15_2, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_15_1, s_b_15_2);
    /* execute.simd:0 [F] s_b_15_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_12,  */
  fixed_block_b_16: 
  {
    /* execute.simd:4047 [F] s_b_16_0=sym_32046_3_parameter_inst.size (const) */
    /* execute.simd:4047 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.simd:4047 [F] s_b_16_2 = constant u32 2 (const) */
    /* execute.simd:4047 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4047 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
    if (s_b_16_3) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_16,  */
  fixed_block_b_17: 
  {
    /* execute.simd:4049 [F] s_b_17_0=sym_32046_3_parameter_inst.rt (const) */
    /* execute.simd:4049 [D] s_b_17_1 = sym_32189_0_address uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_32189_0_address, emitter.context().types().u64());
    /* execute.simd:6270 [D] s_b_17_2 = ReadRegBank 6:s_b_17_0 (u32) */
    auto s_b_17_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_17_2,emitter.const_u8(4));
    }
    /* ???:4294967295 [D] s_b_17_3: Store 4 s_b_17_1 <= s_b_17_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_17_1, s_b_17_2, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_17_1, s_b_17_2);
    /* execute.simd:0 [F] s_b_17_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.simd:4050 [F] s_b_18_0=sym_32046_3_parameter_inst.size (const) */
    /* execute.simd:4050 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
    /* execute.simd:4050 [F] s_b_18_2 = constant u32 3 (const) */
    /* execute.simd:4050 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:4050 [F] s_b_18_4: If s_b_18_3: Jump b_19 else b_11 (const) */
    if (s_b_18_3) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_18,  */
  fixed_block_b_19: 
  {
    /* execute.simd:4052 [F] s_b_19_0=sym_32046_3_parameter_inst.rt (const) */
    /* execute.simd:4052 [D] s_b_19_1 = sym_32189_0_address uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_32189_0_address, emitter.context().types().u64());
    /* execute.simd:6275 [D] s_b_19_2 = ReadRegBank 7:s_b_19_0 (u64) */
    auto s_b_19_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_19_2,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_19_3: Store 8 s_b_19_1 <= s_b_19_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_19_1, s_b_19_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_19_1, s_b_19_2);
    /* execute.simd:0 [F] s_b_19_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_2,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2701 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_20_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_20_4: If s_b_20_3: Jump b_23 else b_24 (const) */
    if (s_b_20_3) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_2,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2733 [F] s_b_21_0=sym_32046_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_21_2: sym_139695_0_return_symbol = s_b_21_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_139695_0_return_symbol, s_b_21_1);
    /* ???:4294967295 [F] s_b_21_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_21, b_25,  */
  fixed_block_b_22: 
  {
    /* ???:4294967295 [D] s_b_22_0 = sym_139695_0_return_symbol uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_139695_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:4034 [D] s_b_22_1 = sym_32091_0_rm uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_32091_0_rm, emitter.context().types().u64());
    /* execute.simd:4034 [D] s_b_22_2 = s_b_22_0+s_b_22_1 */
    auto s_b_22_2 = emitter.add(s_b_22_0, s_b_22_1);
    /* execute.simd:4034 [D] s_b_22_3: sym_32189_0_address = s_b_22_2, dominates: s_b_13_1 s_b_14_1 s_b_15_1 s_b_17_1 s_b_19_1  */
    emitter.store_local(DV_sym_32189_0_address, s_b_22_2);
    /* execute.simd:4036 [F] s_b_22_4=sym_32046_3_parameter_inst.size (const) */
    /* execute.simd:4036 [F] s_b_22_5 = (u32)s_b_22_4 (const) */
    /* execute.simd:4036 [F] s_b_22_6 = constant u32 0 (const) */
    /* execute.simd:4036 [F] s_b_22_7 = s_b_22_5==s_b_22_6 (const) */
    uint8_t s_b_22_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4036 [F] s_b_22_8: If s_b_22_7: Jump b_10 else b_12 (const) */
    if (s_b_22_7) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_20,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2702 [D] s_b_23_0 = ReadReg 20 (u64) */
    auto s_b_23_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_23_1: sym_139712_1__R_s_b_3_0 = s_b_23_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_139712_1__R_s_b_3_0, s_b_23_0);
    /* execute.a64:2702 [F] s_b_23_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_20,  */
  fixed_block_b_24: 
  {
    /* execute.a64:3012 [F] s_b_24_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_24_1 = __builtin_get_feature */
    uint32_t s_b_24_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_24_2 = (u8)s_b_24_1 (const) */
    /* execute.a64:2704 [F] s_b_24_3 = (u32)s_b_24_2 (const) */
    /* execute.a64:2704 [F] s_b_24_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_24_5 = s_b_24_3==s_b_24_4 (const) */
    uint8_t s_b_24_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_24_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_24_6: If s_b_24_5: Jump b_26 else b_27 (const) */
    if (s_b_24_5) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_23, b_26, b_27,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2731 [D] s_b_25_0 = sym_139712_1__R_s_b_3_0 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_139712_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_25_1: sym_139695_0_return_symbol = s_b_25_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_139695_0_return_symbol, s_b_25_0);
    /* ???:4294967295 [F] s_b_25_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_24,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2705 [D] s_b_26_0 = ReadReg 20 (u64) */
    auto s_b_26_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_26_1: sym_139712_1__R_s_b_3_0 = s_b_26_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_139712_1__R_s_b_3_0, s_b_26_0);
    /* execute.a64:2705 [F] s_b_26_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_24,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2707 [D] s_b_27_0 = ReadReg 21 (u64) */
    auto s_b_27_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_27_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_27_1: sym_139712_1__R_s_b_3_0 = s_b_27_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_139712_1__R_s_b_3_0, s_b_27_0);
    /* execute.a64:2707 [F] s_b_27_2: Jump b_25 (const) */
    goto fixed_block_b_25;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sttr(const aarch64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stxrb(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_144669_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_33004_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_144686_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:609 [F] s_b_0_0=sym_32998_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_5_0=sym_32998_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_144669_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_144669_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_144669_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_144669_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:609 [D] s_b_6_1: sym_33004_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_33004_0_address, s_b_6_0);
    /* execute.a64:611 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:611 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:611 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
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
    /* execute.a64:2702 [D] s_b_7_1: sym_144686_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144686_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2731 [D] s_b_9_0 = sym_144686_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_144686_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_144669_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_144669_0_return_symbol, s_b_9_0);
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
    /* execute.a64:2705 [D] s_b_10_1: sym_144686_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144686_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2707 [D] s_b_11_1: sym_144686_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144686_1__R_s_b_3_0, s_b_11_0);
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
        /* execute.a64:612 [D] s_b_1_0 = sym_33004_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_33004_0_address, emitter.context().types().u64());
        /* execute.a64:612 [F] s_b_1_1=sym_32998_3_parameter_inst.rt (const) */
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
        /* execute.a64:1782 [D] s_b_1_9 = (u8)s_b_1_8 */
        auto s_b_1_9 = emitter.truncate(s_b_1_8, emitter.context().types().u8());
        /* ???:4294967295 [D] s_b_1_10: Store 1 s_b_1_0 <= s_b_1_9 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_1_0, s_b_1_9, emitter.const_u8(1));
        }
        emitter.store_memory(s_b_1_0, s_b_1_9);
        /* execute.a64:613 [F] s_b_1_11=sym_32998_3_parameter_inst.rs (const) */
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
        /* execute.a64:615 [F] s_b_3_0=sym_32998_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_12_0=sym_32998_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_13_0=sym_32998_3_parameter_inst.rs (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_tbx(const aarch64_decode_a64_SIMD_TABLE_LOOKUP&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
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
  auto block_b_48 = emitter.context().create_block();
  auto block_b_49 = emitter.context().create_block();
  auto block_b_50 = emitter.context().create_block();
  auto DV_sym_35096_0_rm = emitter.alloc_local(emitter.context().types().u8(), true);
  auto DV_sym_35481_0_rm = emitter.alloc_local(emitter.context().types().u8(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3784 [F] s_b_0_0=sym_35073_3_parameter_inst.Q (const) */
    /* execute.simd:3784 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:3784 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:3784 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:3784 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3786 [F] s_b_1_0=sym_35073_3_parameter_inst.rm (const) */
    /* execute.simd:3786 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:3786 [F] s_b_1_2 = constant u32 10 (const) */
    /* execute.simd:3786 [F] s_b_1_3 = s_b_1_1*s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
    /* execute.simd:3786 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.simd:3786 [F] s_b_1_5 = s_b_1_3+s_b_1_4 (const) */
    uint32_t s_b_1_5 = ((uint32_t)(s_b_1_3 + (uint32_t)0ULL));
    /* execute.simd:3786 [D] s_b_1_6 = ReadRegBank 23:s_b_1_5 (u8) */
    auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_1_5))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_1_5))),s_b_1_6,emitter.const_u8(1));
    }
    /* execute.simd:3786 [D] s_b_1_7: sym_35096_0_rm = s_b_1_6, dominates: s_b_4_10  */
    emitter.store_local(DV_sym_35096_0_rm, s_b_1_6);
    /* execute.simd:3788 [F] s_b_1_8=sym_35073_3_parameter_inst.len (const) */
    /* execute.simd:3788 [F] s_b_1_9 = (u32)s_b_1_8 (const) */
    /* execute.simd:3788 [F] s_b_1_10 = constant u32 1 (const) */
    /* execute.simd:3788 [F] s_b_1_11 = s_b_1_9+s_b_1_10 (const) */
    uint32_t s_b_1_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
    /* execute.simd:3788 [F] s_b_1_12 = constant u32 10 (const) */
    /* execute.simd:3788 [F] s_b_1_13 = s_b_1_12*s_b_1_11 (const) */
    uint32_t s_b_1_13 = ((uint32_t)((uint32_t)16ULL * s_b_1_11));
    /* execute.simd:3788 [D] s_b_1_14 = (u32)s_b_1_6 */
    auto s_b_1_14 = emitter.zx(s_b_1_6, emitter.context().types().u32());
    /* execute.simd:3788 [D] s_b_1_15 = s_b_1_14<s_b_1_13 */
    auto s_b_1_15 = emitter.cmp_lt(s_b_1_14, emitter.const_u32(s_b_1_13));
    /* execute.simd:3788 [D] s_b_1_16: If s_b_1_15: Jump b_4 else b_5 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_4;
        dynamic_block_queue.push(block_b_4);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_5;
        dynamic_block_queue.push(block_b_5);
        false_target = block;
      }
      emitter.branch(s_b_1_15, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:3796 [F] s_b_3_0=sym_35073_3_parameter_inst.rm (const) */
    /* execute.simd:3796 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:3796 [F] s_b_3_2 = constant u32 10 (const) */
    /* execute.simd:3796 [F] s_b_3_3 = s_b_3_1*s_b_3_2 (const) */
    uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
    /* execute.simd:3796 [F] s_b_3_4 = constant u32 0 (const) */
    /* execute.simd:3796 [F] s_b_3_5 = s_b_3_3+s_b_3_4 (const) */
    uint32_t s_b_3_5 = ((uint32_t)(s_b_3_3 + (uint32_t)0ULL));
    /* execute.simd:3796 [D] s_b_3_6 = ReadRegBank 23:s_b_3_5 (u8) */
    auto s_b_3_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_3_5))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_3_5))),s_b_3_6,emitter.const_u8(1));
    }
    /* execute.simd:3796 [D] s_b_3_7: sym_35481_0_rm = s_b_3_6, dominates: s_b_20_10  */
    emitter.store_local(DV_sym_35481_0_rm, s_b_3_6);
    /* execute.simd:3798 [F] s_b_3_8=sym_35073_3_parameter_inst.len (const) */
    /* execute.simd:3798 [F] s_b_3_9 = (u32)s_b_3_8 (const) */
    /* execute.simd:3798 [F] s_b_3_10 = constant u32 1 (const) */
    /* execute.simd:3798 [F] s_b_3_11 = s_b_3_9+s_b_3_10 (const) */
    uint32_t s_b_3_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
    /* execute.simd:3798 [F] s_b_3_12 = constant u32 10 (const) */
    /* execute.simd:3798 [F] s_b_3_13 = s_b_3_12*s_b_3_11 (const) */
    uint32_t s_b_3_13 = ((uint32_t)((uint32_t)16ULL * s_b_3_11));
    /* execute.simd:3798 [D] s_b_3_14 = (u32)s_b_3_6 */
    auto s_b_3_14 = emitter.zx(s_b_3_6, emitter.context().types().u32());
    /* execute.simd:3798 [D] s_b_3_15 = s_b_3_14<s_b_3_13 */
    auto s_b_3_15 = emitter.cmp_lt(s_b_3_14, emitter.const_u32(s_b_3_13));
    /* execute.simd:3798 [D] s_b_3_16: If s_b_3_15: Jump b_20 else b_21 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_20;
        dynamic_block_queue.push(block_b_20);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_21;
        dynamic_block_queue.push(block_b_21);
        false_target = block;
      }
      emitter.branch(s_b_3_15, true_target, false_target);
    }
    goto fixed_done;
  }
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
  // BLOCK b_48 not fully fixed
  // BLOCK b_49 not fully fixed
  // BLOCK b_50 not fully fixed
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
        /* execute.simd:3789 [F] s_b_4_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3789 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
        /* execute.simd:3789 [F] s_b_4_2 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_4_3 = s_b_4_1*s_b_4_2 (const) */
        uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3789 [F] s_b_4_4 = constant u32 0 (const) */
        /* execute.simd:3789 [F] s_b_4_5 = s_b_4_3+s_b_4_4 (const) */
        uint32_t s_b_4_5 = ((uint32_t)(s_b_4_3 + (uint32_t)0ULL));
        /* execute.simd:3789 [F] s_b_4_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3789 [F] s_b_4_7 = (u32)s_b_4_6 (const) */
        /* execute.simd:3789 [F] s_b_4_8 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_4_9 = s_b_4_7*s_b_4_8 (const) */
        uint32_t s_b_4_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3789 [D] s_b_4_10 = sym_35096_0_rm uint8_t */
        auto s_b_4_10 = emitter.load_local(DV_sym_35096_0_rm, emitter.context().types().u8());
        /* execute.simd:3789 [D] s_b_4_11 = (u32)s_b_4_10 */
        auto s_b_4_11 = emitter.zx(s_b_4_10, emitter.context().types().u32());
        /* execute.simd:3789 [D] s_b_4_12 = s_b_4_9+s_b_4_11 */
        auto s_b_4_12 = emitter.add(emitter.const_u32(s_b_4_9), s_b_4_11);
        /* execute.simd:3789 [D] s_b_4_13 = ReadRegBank 23:s_b_4_12 (u8) */
        dbt::el::Value *s_b_4_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_4_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_4_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3789 [D] s_b_4_14: WriteRegBank 23:s_b_4_5 = s_b_4_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_4_5))),s_b_4_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_4_5))),s_b_4_13);
        /* execute.simd:3789 [F] s_b_4_15: Jump b_5 (const) */
        {
          auto block = block_b_5;
          dynamic_block_queue.push(block_b_5);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:3786 [F] s_b_5_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3786 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
        /* execute.simd:3786 [F] s_b_5_2 = constant u32 10 (const) */
        /* execute.simd:3786 [F] s_b_5_3 = s_b_5_1*s_b_5_2 (const) */
        uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3786 [F] s_b_5_4 = constant u32 1 (const) */
        /* execute.simd:3786 [F] s_b_5_5 = s_b_5_3+s_b_5_4 (const) */
        uint32_t s_b_5_5 = ((uint32_t)(s_b_5_3 + (uint32_t)1ULL));
        /* execute.simd:3786 [D] s_b_5_6 = ReadRegBank 23:s_b_5_5 (u8) */
        auto s_b_5_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_5_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_5_5))),s_b_5_6,emitter.const_u8(1));
        }
        /* execute.simd:3786 [D] s_b_5_7: sym_35096_0_rm = s_b_5_6, dominates: s_b_6_10  */
        emitter.store_local(DV_sym_35096_0_rm, s_b_5_6);
        /* execute.simd:3788 [F] s_b_5_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3788 [F] s_b_5_9 = (u32)s_b_5_8 (const) */
        /* execute.simd:3788 [F] s_b_5_10 = constant u32 1 (const) */
        /* execute.simd:3788 [F] s_b_5_11 = s_b_5_9+s_b_5_10 (const) */
        uint32_t s_b_5_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3788 [F] s_b_5_12 = constant u32 10 (const) */
        /* execute.simd:3788 [F] s_b_5_13 = s_b_5_12*s_b_5_11 (const) */
        uint32_t s_b_5_13 = ((uint32_t)((uint32_t)16ULL * s_b_5_11));
        /* execute.simd:3788 [D] s_b_5_14 = (u32)s_b_5_6 */
        auto s_b_5_14 = emitter.zx(s_b_5_6, emitter.context().types().u32());
        /* execute.simd:3788 [D] s_b_5_15 = s_b_5_14<s_b_5_13 */
        auto s_b_5_15 = emitter.cmp_lt(s_b_5_14, emitter.const_u32(s_b_5_13));
        /* execute.simd:3788 [D] s_b_5_16: If s_b_5_15: Jump b_6 else b_7 */
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
          emitter.branch(s_b_5_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:3789 [F] s_b_6_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3789 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
        /* execute.simd:3789 [F] s_b_6_2 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_6_3 = s_b_6_1*s_b_6_2 (const) */
        uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3789 [F] s_b_6_4 = constant u32 1 (const) */
        /* execute.simd:3789 [F] s_b_6_5 = s_b_6_3+s_b_6_4 (const) */
        uint32_t s_b_6_5 = ((uint32_t)(s_b_6_3 + (uint32_t)1ULL));
        /* execute.simd:3789 [F] s_b_6_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3789 [F] s_b_6_7 = (u32)s_b_6_6 (const) */
        /* execute.simd:3789 [F] s_b_6_8 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_6_9 = s_b_6_7*s_b_6_8 (const) */
        uint32_t s_b_6_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3789 [D] s_b_6_10 = sym_35096_0_rm uint8_t */
        auto s_b_6_10 = emitter.load_local(DV_sym_35096_0_rm, emitter.context().types().u8());
        /* execute.simd:3789 [D] s_b_6_11 = (u32)s_b_6_10 */
        auto s_b_6_11 = emitter.zx(s_b_6_10, emitter.context().types().u32());
        /* execute.simd:3789 [D] s_b_6_12 = s_b_6_9+s_b_6_11 */
        auto s_b_6_12 = emitter.add(emitter.const_u32(s_b_6_9), s_b_6_11);
        /* execute.simd:3789 [D] s_b_6_13 = ReadRegBank 23:s_b_6_12 (u8) */
        dbt::el::Value *s_b_6_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_6_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_6_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3789 [D] s_b_6_14: WriteRegBank 23:s_b_6_5 = s_b_6_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_6_5))),s_b_6_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_6_5))),s_b_6_13);
        /* execute.simd:3789 [F] s_b_6_15: Jump b_7 (const) */
        {
          auto block = block_b_7;
          dynamic_block_queue.push(block_b_7);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.simd:3786 [F] s_b_7_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3786 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
        /* execute.simd:3786 [F] s_b_7_2 = constant u32 10 (const) */
        /* execute.simd:3786 [F] s_b_7_3 = s_b_7_1*s_b_7_2 (const) */
        uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3786 [F] s_b_7_4 = constant u32 2 (const) */
        /* execute.simd:3786 [F] s_b_7_5 = s_b_7_3+s_b_7_4 (const) */
        uint32_t s_b_7_5 = ((uint32_t)(s_b_7_3 + (uint32_t)2ULL));
        /* execute.simd:3786 [D] s_b_7_6 = ReadRegBank 23:s_b_7_5 (u8) */
        auto s_b_7_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_7_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_7_5))),s_b_7_6,emitter.const_u8(1));
        }
        /* execute.simd:3786 [D] s_b_7_7: sym_35096_0_rm = s_b_7_6, dominates: s_b_8_10  */
        emitter.store_local(DV_sym_35096_0_rm, s_b_7_6);
        /* execute.simd:3788 [F] s_b_7_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3788 [F] s_b_7_9 = (u32)s_b_7_8 (const) */
        /* execute.simd:3788 [F] s_b_7_10 = constant u32 1 (const) */
        /* execute.simd:3788 [F] s_b_7_11 = s_b_7_9+s_b_7_10 (const) */
        uint32_t s_b_7_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3788 [F] s_b_7_12 = constant u32 10 (const) */
        /* execute.simd:3788 [F] s_b_7_13 = s_b_7_12*s_b_7_11 (const) */
        uint32_t s_b_7_13 = ((uint32_t)((uint32_t)16ULL * s_b_7_11));
        /* execute.simd:3788 [D] s_b_7_14 = (u32)s_b_7_6 */
        auto s_b_7_14 = emitter.zx(s_b_7_6, emitter.context().types().u32());
        /* execute.simd:3788 [D] s_b_7_15 = s_b_7_14<s_b_7_13 */
        auto s_b_7_15 = emitter.cmp_lt(s_b_7_14, emitter.const_u32(s_b_7_13));
        /* execute.simd:3788 [D] s_b_7_16: If s_b_7_15: Jump b_8 else b_9 */
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
          emitter.branch(s_b_7_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.simd:3789 [F] s_b_8_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3789 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
        /* execute.simd:3789 [F] s_b_8_2 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_8_3 = s_b_8_1*s_b_8_2 (const) */
        uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3789 [F] s_b_8_4 = constant u32 2 (const) */
        /* execute.simd:3789 [F] s_b_8_5 = s_b_8_3+s_b_8_4 (const) */
        uint32_t s_b_8_5 = ((uint32_t)(s_b_8_3 + (uint32_t)2ULL));
        /* execute.simd:3789 [F] s_b_8_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3789 [F] s_b_8_7 = (u32)s_b_8_6 (const) */
        /* execute.simd:3789 [F] s_b_8_8 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_8_9 = s_b_8_7*s_b_8_8 (const) */
        uint32_t s_b_8_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3789 [D] s_b_8_10 = sym_35096_0_rm uint8_t */
        auto s_b_8_10 = emitter.load_local(DV_sym_35096_0_rm, emitter.context().types().u8());
        /* execute.simd:3789 [D] s_b_8_11 = (u32)s_b_8_10 */
        auto s_b_8_11 = emitter.zx(s_b_8_10, emitter.context().types().u32());
        /* execute.simd:3789 [D] s_b_8_12 = s_b_8_9+s_b_8_11 */
        auto s_b_8_12 = emitter.add(emitter.const_u32(s_b_8_9), s_b_8_11);
        /* execute.simd:3789 [D] s_b_8_13 = ReadRegBank 23:s_b_8_12 (u8) */
        dbt::el::Value *s_b_8_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_8_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_8_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3789 [D] s_b_8_14: WriteRegBank 23:s_b_8_5 = s_b_8_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_8_5))),s_b_8_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_8_5))),s_b_8_13);
        /* execute.simd:3789 [F] s_b_8_15: Jump b_9 (const) */
        {
          auto block = block_b_9;
          dynamic_block_queue.push(block_b_9);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.simd:3786 [F] s_b_9_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3786 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
        /* execute.simd:3786 [F] s_b_9_2 = constant u32 10 (const) */
        /* execute.simd:3786 [F] s_b_9_3 = s_b_9_1*s_b_9_2 (const) */
        uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3786 [F] s_b_9_4 = constant u32 3 (const) */
        /* execute.simd:3786 [F] s_b_9_5 = s_b_9_3+s_b_9_4 (const) */
        uint32_t s_b_9_5 = ((uint32_t)(s_b_9_3 + (uint32_t)3ULL));
        /* execute.simd:3786 [D] s_b_9_6 = ReadRegBank 23:s_b_9_5 (u8) */
        auto s_b_9_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_9_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_9_5))),s_b_9_6,emitter.const_u8(1));
        }
        /* execute.simd:3786 [D] s_b_9_7: sym_35096_0_rm = s_b_9_6, dominates: s_b_10_10  */
        emitter.store_local(DV_sym_35096_0_rm, s_b_9_6);
        /* execute.simd:3788 [F] s_b_9_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3788 [F] s_b_9_9 = (u32)s_b_9_8 (const) */
        /* execute.simd:3788 [F] s_b_9_10 = constant u32 1 (const) */
        /* execute.simd:3788 [F] s_b_9_11 = s_b_9_9+s_b_9_10 (const) */
        uint32_t s_b_9_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3788 [F] s_b_9_12 = constant u32 10 (const) */
        /* execute.simd:3788 [F] s_b_9_13 = s_b_9_12*s_b_9_11 (const) */
        uint32_t s_b_9_13 = ((uint32_t)((uint32_t)16ULL * s_b_9_11));
        /* execute.simd:3788 [D] s_b_9_14 = (u32)s_b_9_6 */
        auto s_b_9_14 = emitter.zx(s_b_9_6, emitter.context().types().u32());
        /* execute.simd:3788 [D] s_b_9_15 = s_b_9_14<s_b_9_13 */
        auto s_b_9_15 = emitter.cmp_lt(s_b_9_14, emitter.const_u32(s_b_9_13));
        /* execute.simd:3788 [D] s_b_9_16: If s_b_9_15: Jump b_10 else b_11 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_10;
            dynamic_block_queue.push(block_b_10);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_11;
            dynamic_block_queue.push(block_b_11);
            false_target = block;
          }
          emitter.branch(s_b_9_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.simd:3789 [F] s_b_10_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3789 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
        /* execute.simd:3789 [F] s_b_10_2 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_10_3 = s_b_10_1*s_b_10_2 (const) */
        uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3789 [F] s_b_10_4 = constant u32 3 (const) */
        /* execute.simd:3789 [F] s_b_10_5 = s_b_10_3+s_b_10_4 (const) */
        uint32_t s_b_10_5 = ((uint32_t)(s_b_10_3 + (uint32_t)3ULL));
        /* execute.simd:3789 [F] s_b_10_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3789 [F] s_b_10_7 = (u32)s_b_10_6 (const) */
        /* execute.simd:3789 [F] s_b_10_8 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_10_9 = s_b_10_7*s_b_10_8 (const) */
        uint32_t s_b_10_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3789 [D] s_b_10_10 = sym_35096_0_rm uint8_t */
        auto s_b_10_10 = emitter.load_local(DV_sym_35096_0_rm, emitter.context().types().u8());
        /* execute.simd:3789 [D] s_b_10_11 = (u32)s_b_10_10 */
        auto s_b_10_11 = emitter.zx(s_b_10_10, emitter.context().types().u32());
        /* execute.simd:3789 [D] s_b_10_12 = s_b_10_9+s_b_10_11 */
        auto s_b_10_12 = emitter.add(emitter.const_u32(s_b_10_9), s_b_10_11);
        /* execute.simd:3789 [D] s_b_10_13 = ReadRegBank 23:s_b_10_12 (u8) */
        dbt::el::Value *s_b_10_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_10_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_10_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3789 [D] s_b_10_14: WriteRegBank 23:s_b_10_5 = s_b_10_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_10_5))),s_b_10_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_10_5))),s_b_10_13);
        /* execute.simd:3789 [F] s_b_10_15: Jump b_11 (const) */
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* execute.simd:3786 [F] s_b_11_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3786 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
        /* execute.simd:3786 [F] s_b_11_2 = constant u32 10 (const) */
        /* execute.simd:3786 [F] s_b_11_3 = s_b_11_1*s_b_11_2 (const) */
        uint32_t s_b_11_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3786 [F] s_b_11_4 = constant u32 4 (const) */
        /* execute.simd:3786 [F] s_b_11_5 = s_b_11_3+s_b_11_4 (const) */
        uint32_t s_b_11_5 = ((uint32_t)(s_b_11_3 + (uint32_t)4ULL));
        /* execute.simd:3786 [D] s_b_11_6 = ReadRegBank 23:s_b_11_5 (u8) */
        auto s_b_11_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_11_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_11_5))),s_b_11_6,emitter.const_u8(1));
        }
        /* execute.simd:3786 [D] s_b_11_7: sym_35096_0_rm = s_b_11_6, dominates: s_b_12_10  */
        emitter.store_local(DV_sym_35096_0_rm, s_b_11_6);
        /* execute.simd:3788 [F] s_b_11_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3788 [F] s_b_11_9 = (u32)s_b_11_8 (const) */
        /* execute.simd:3788 [F] s_b_11_10 = constant u32 1 (const) */
        /* execute.simd:3788 [F] s_b_11_11 = s_b_11_9+s_b_11_10 (const) */
        uint32_t s_b_11_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3788 [F] s_b_11_12 = constant u32 10 (const) */
        /* execute.simd:3788 [F] s_b_11_13 = s_b_11_12*s_b_11_11 (const) */
        uint32_t s_b_11_13 = ((uint32_t)((uint32_t)16ULL * s_b_11_11));
        /* execute.simd:3788 [D] s_b_11_14 = (u32)s_b_11_6 */
        auto s_b_11_14 = emitter.zx(s_b_11_6, emitter.context().types().u32());
        /* execute.simd:3788 [D] s_b_11_15 = s_b_11_14<s_b_11_13 */
        auto s_b_11_15 = emitter.cmp_lt(s_b_11_14, emitter.const_u32(s_b_11_13));
        /* execute.simd:3788 [D] s_b_11_16: If s_b_11_15: Jump b_12 else b_13 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_12;
            dynamic_block_queue.push(block_b_12);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_13;
            dynamic_block_queue.push(block_b_13);
            false_target = block;
          }
          emitter.branch(s_b_11_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.simd:3789 [F] s_b_12_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3789 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
        /* execute.simd:3789 [F] s_b_12_2 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_12_3 = s_b_12_1*s_b_12_2 (const) */
        uint32_t s_b_12_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3789 [F] s_b_12_4 = constant u32 4 (const) */
        /* execute.simd:3789 [F] s_b_12_5 = s_b_12_3+s_b_12_4 (const) */
        uint32_t s_b_12_5 = ((uint32_t)(s_b_12_3 + (uint32_t)4ULL));
        /* execute.simd:3789 [F] s_b_12_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3789 [F] s_b_12_7 = (u32)s_b_12_6 (const) */
        /* execute.simd:3789 [F] s_b_12_8 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_12_9 = s_b_12_7*s_b_12_8 (const) */
        uint32_t s_b_12_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3789 [D] s_b_12_10 = sym_35096_0_rm uint8_t */
        auto s_b_12_10 = emitter.load_local(DV_sym_35096_0_rm, emitter.context().types().u8());
        /* execute.simd:3789 [D] s_b_12_11 = (u32)s_b_12_10 */
        auto s_b_12_11 = emitter.zx(s_b_12_10, emitter.context().types().u32());
        /* execute.simd:3789 [D] s_b_12_12 = s_b_12_9+s_b_12_11 */
        auto s_b_12_12 = emitter.add(emitter.const_u32(s_b_12_9), s_b_12_11);
        /* execute.simd:3789 [D] s_b_12_13 = ReadRegBank 23:s_b_12_12 (u8) */
        dbt::el::Value *s_b_12_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_12_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_12_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3789 [D] s_b_12_14: WriteRegBank 23:s_b_12_5 = s_b_12_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_12_5))),s_b_12_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_12_5))),s_b_12_13);
        /* execute.simd:3789 [F] s_b_12_15: Jump b_13 (const) */
        {
          auto block = block_b_13;
          dynamic_block_queue.push(block_b_13);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.simd:3786 [F] s_b_13_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3786 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
        /* execute.simd:3786 [F] s_b_13_2 = constant u32 10 (const) */
        /* execute.simd:3786 [F] s_b_13_3 = s_b_13_1*s_b_13_2 (const) */
        uint32_t s_b_13_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3786 [F] s_b_13_4 = constant u32 5 (const) */
        /* execute.simd:3786 [F] s_b_13_5 = s_b_13_3+s_b_13_4 (const) */
        uint32_t s_b_13_5 = ((uint32_t)(s_b_13_3 + (uint32_t)5ULL));
        /* execute.simd:3786 [D] s_b_13_6 = ReadRegBank 23:s_b_13_5 (u8) */
        auto s_b_13_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_13_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_13_5))),s_b_13_6,emitter.const_u8(1));
        }
        /* execute.simd:3786 [D] s_b_13_7: sym_35096_0_rm = s_b_13_6, dominates: s_b_14_10  */
        emitter.store_local(DV_sym_35096_0_rm, s_b_13_6);
        /* execute.simd:3788 [F] s_b_13_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3788 [F] s_b_13_9 = (u32)s_b_13_8 (const) */
        /* execute.simd:3788 [F] s_b_13_10 = constant u32 1 (const) */
        /* execute.simd:3788 [F] s_b_13_11 = s_b_13_9+s_b_13_10 (const) */
        uint32_t s_b_13_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3788 [F] s_b_13_12 = constant u32 10 (const) */
        /* execute.simd:3788 [F] s_b_13_13 = s_b_13_12*s_b_13_11 (const) */
        uint32_t s_b_13_13 = ((uint32_t)((uint32_t)16ULL * s_b_13_11));
        /* execute.simd:3788 [D] s_b_13_14 = (u32)s_b_13_6 */
        auto s_b_13_14 = emitter.zx(s_b_13_6, emitter.context().types().u32());
        /* execute.simd:3788 [D] s_b_13_15 = s_b_13_14<s_b_13_13 */
        auto s_b_13_15 = emitter.cmp_lt(s_b_13_14, emitter.const_u32(s_b_13_13));
        /* execute.simd:3788 [D] s_b_13_16: If s_b_13_15: Jump b_14 else b_15 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_14;
            dynamic_block_queue.push(block_b_14);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_15;
            dynamic_block_queue.push(block_b_15);
            false_target = block;
          }
          emitter.branch(s_b_13_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.simd:3789 [F] s_b_14_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3789 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
        /* execute.simd:3789 [F] s_b_14_2 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_14_3 = s_b_14_1*s_b_14_2 (const) */
        uint32_t s_b_14_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3789 [F] s_b_14_4 = constant u32 5 (const) */
        /* execute.simd:3789 [F] s_b_14_5 = s_b_14_3+s_b_14_4 (const) */
        uint32_t s_b_14_5 = ((uint32_t)(s_b_14_3 + (uint32_t)5ULL));
        /* execute.simd:3789 [F] s_b_14_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3789 [F] s_b_14_7 = (u32)s_b_14_6 (const) */
        /* execute.simd:3789 [F] s_b_14_8 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_14_9 = s_b_14_7*s_b_14_8 (const) */
        uint32_t s_b_14_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3789 [D] s_b_14_10 = sym_35096_0_rm uint8_t */
        auto s_b_14_10 = emitter.load_local(DV_sym_35096_0_rm, emitter.context().types().u8());
        /* execute.simd:3789 [D] s_b_14_11 = (u32)s_b_14_10 */
        auto s_b_14_11 = emitter.zx(s_b_14_10, emitter.context().types().u32());
        /* execute.simd:3789 [D] s_b_14_12 = s_b_14_9+s_b_14_11 */
        auto s_b_14_12 = emitter.add(emitter.const_u32(s_b_14_9), s_b_14_11);
        /* execute.simd:3789 [D] s_b_14_13 = ReadRegBank 23:s_b_14_12 (u8) */
        dbt::el::Value *s_b_14_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_14_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_14_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3789 [D] s_b_14_14: WriteRegBank 23:s_b_14_5 = s_b_14_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_14_5))),s_b_14_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_14_5))),s_b_14_13);
        /* execute.simd:3789 [F] s_b_14_15: Jump b_15 (const) */
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.simd:3786 [F] s_b_15_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3786 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
        /* execute.simd:3786 [F] s_b_15_2 = constant u32 10 (const) */
        /* execute.simd:3786 [F] s_b_15_3 = s_b_15_1*s_b_15_2 (const) */
        uint32_t s_b_15_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3786 [F] s_b_15_4 = constant u32 6 (const) */
        /* execute.simd:3786 [F] s_b_15_5 = s_b_15_3+s_b_15_4 (const) */
        uint32_t s_b_15_5 = ((uint32_t)(s_b_15_3 + (uint32_t)6ULL));
        /* execute.simd:3786 [D] s_b_15_6 = ReadRegBank 23:s_b_15_5 (u8) */
        auto s_b_15_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_15_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_15_5))),s_b_15_6,emitter.const_u8(1));
        }
        /* execute.simd:3786 [D] s_b_15_7: sym_35096_0_rm = s_b_15_6, dominates: s_b_16_10  */
        emitter.store_local(DV_sym_35096_0_rm, s_b_15_6);
        /* execute.simd:3788 [F] s_b_15_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3788 [F] s_b_15_9 = (u32)s_b_15_8 (const) */
        /* execute.simd:3788 [F] s_b_15_10 = constant u32 1 (const) */
        /* execute.simd:3788 [F] s_b_15_11 = s_b_15_9+s_b_15_10 (const) */
        uint32_t s_b_15_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3788 [F] s_b_15_12 = constant u32 10 (const) */
        /* execute.simd:3788 [F] s_b_15_13 = s_b_15_12*s_b_15_11 (const) */
        uint32_t s_b_15_13 = ((uint32_t)((uint32_t)16ULL * s_b_15_11));
        /* execute.simd:3788 [D] s_b_15_14 = (u32)s_b_15_6 */
        auto s_b_15_14 = emitter.zx(s_b_15_6, emitter.context().types().u32());
        /* execute.simd:3788 [D] s_b_15_15 = s_b_15_14<s_b_15_13 */
        auto s_b_15_15 = emitter.cmp_lt(s_b_15_14, emitter.const_u32(s_b_15_13));
        /* execute.simd:3788 [D] s_b_15_16: If s_b_15_15: Jump b_16 else b_17 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_16;
            dynamic_block_queue.push(block_b_16);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_17;
            dynamic_block_queue.push(block_b_17);
            false_target = block;
          }
          emitter.branch(s_b_15_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.simd:3789 [F] s_b_16_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3789 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
        /* execute.simd:3789 [F] s_b_16_2 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_16_3 = s_b_16_1*s_b_16_2 (const) */
        uint32_t s_b_16_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3789 [F] s_b_16_4 = constant u32 6 (const) */
        /* execute.simd:3789 [F] s_b_16_5 = s_b_16_3+s_b_16_4 (const) */
        uint32_t s_b_16_5 = ((uint32_t)(s_b_16_3 + (uint32_t)6ULL));
        /* execute.simd:3789 [F] s_b_16_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3789 [F] s_b_16_7 = (u32)s_b_16_6 (const) */
        /* execute.simd:3789 [F] s_b_16_8 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_16_9 = s_b_16_7*s_b_16_8 (const) */
        uint32_t s_b_16_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3789 [D] s_b_16_10 = sym_35096_0_rm uint8_t */
        auto s_b_16_10 = emitter.load_local(DV_sym_35096_0_rm, emitter.context().types().u8());
        /* execute.simd:3789 [D] s_b_16_11 = (u32)s_b_16_10 */
        auto s_b_16_11 = emitter.zx(s_b_16_10, emitter.context().types().u32());
        /* execute.simd:3789 [D] s_b_16_12 = s_b_16_9+s_b_16_11 */
        auto s_b_16_12 = emitter.add(emitter.const_u32(s_b_16_9), s_b_16_11);
        /* execute.simd:3789 [D] s_b_16_13 = ReadRegBank 23:s_b_16_12 (u8) */
        dbt::el::Value *s_b_16_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_16_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_16_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3789 [D] s_b_16_14: WriteRegBank 23:s_b_16_5 = s_b_16_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_16_5))),s_b_16_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_16_5))),s_b_16_13);
        /* execute.simd:3789 [F] s_b_16_15: Jump b_17 (const) */
        {
          auto block = block_b_17;
          dynamic_block_queue.push(block_b_17);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.simd:3786 [F] s_b_17_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3786 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
        /* execute.simd:3786 [F] s_b_17_2 = constant u32 10 (const) */
        /* execute.simd:3786 [F] s_b_17_3 = s_b_17_1*s_b_17_2 (const) */
        uint32_t s_b_17_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3786 [F] s_b_17_4 = constant u32 7 (const) */
        /* execute.simd:3786 [F] s_b_17_5 = s_b_17_3+s_b_17_4 (const) */
        uint32_t s_b_17_5 = ((uint32_t)(s_b_17_3 + (uint32_t)7ULL));
        /* execute.simd:3786 [D] s_b_17_6 = ReadRegBank 23:s_b_17_5 (u8) */
        auto s_b_17_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_17_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_17_5))),s_b_17_6,emitter.const_u8(1));
        }
        /* execute.simd:3786 [D] s_b_17_7: sym_35096_0_rm = s_b_17_6, dominates: s_b_18_10  */
        emitter.store_local(DV_sym_35096_0_rm, s_b_17_6);
        /* execute.simd:3788 [F] s_b_17_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3788 [F] s_b_17_9 = (u32)s_b_17_8 (const) */
        /* execute.simd:3788 [F] s_b_17_10 = constant u32 1 (const) */
        /* execute.simd:3788 [F] s_b_17_11 = s_b_17_9+s_b_17_10 (const) */
        uint32_t s_b_17_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3788 [F] s_b_17_12 = constant u32 10 (const) */
        /* execute.simd:3788 [F] s_b_17_13 = s_b_17_12*s_b_17_11 (const) */
        uint32_t s_b_17_13 = ((uint32_t)((uint32_t)16ULL * s_b_17_11));
        /* execute.simd:3788 [D] s_b_17_14 = (u32)s_b_17_6 */
        auto s_b_17_14 = emitter.zx(s_b_17_6, emitter.context().types().u32());
        /* execute.simd:3788 [D] s_b_17_15 = s_b_17_14<s_b_17_13 */
        auto s_b_17_15 = emitter.cmp_lt(s_b_17_14, emitter.const_u32(s_b_17_13));
        /* execute.simd:3788 [D] s_b_17_16: If s_b_17_15: Jump b_18 else b_19 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_18;
            dynamic_block_queue.push(block_b_18);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_19;
            dynamic_block_queue.push(block_b_19);
            false_target = block;
          }
          emitter.branch(s_b_17_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.simd:3789 [F] s_b_18_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3789 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
        /* execute.simd:3789 [F] s_b_18_2 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_18_3 = s_b_18_1*s_b_18_2 (const) */
        uint32_t s_b_18_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3789 [F] s_b_18_4 = constant u32 7 (const) */
        /* execute.simd:3789 [F] s_b_18_5 = s_b_18_3+s_b_18_4 (const) */
        uint32_t s_b_18_5 = ((uint32_t)(s_b_18_3 + (uint32_t)7ULL));
        /* execute.simd:3789 [F] s_b_18_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3789 [F] s_b_18_7 = (u32)s_b_18_6 (const) */
        /* execute.simd:3789 [F] s_b_18_8 = constant u32 10 (const) */
        /* execute.simd:3789 [F] s_b_18_9 = s_b_18_7*s_b_18_8 (const) */
        uint32_t s_b_18_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3789 [D] s_b_18_10 = sym_35096_0_rm uint8_t */
        auto s_b_18_10 = emitter.load_local(DV_sym_35096_0_rm, emitter.context().types().u8());
        /* execute.simd:3789 [D] s_b_18_11 = (u32)s_b_18_10 */
        auto s_b_18_11 = emitter.zx(s_b_18_10, emitter.context().types().u32());
        /* execute.simd:3789 [D] s_b_18_12 = s_b_18_9+s_b_18_11 */
        auto s_b_18_12 = emitter.add(emitter.const_u32(s_b_18_9), s_b_18_11);
        /* execute.simd:3789 [D] s_b_18_13 = ReadRegBank 23:s_b_18_12 (u8) */
        dbt::el::Value *s_b_18_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_18_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_18_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3789 [D] s_b_18_14: WriteRegBank 23:s_b_18_5 = s_b_18_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_18_5))),s_b_18_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_18_5))),s_b_18_13);
        /* execute.simd:3789 [F] s_b_18_15: Jump b_19 (const) */
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.simd:3793 [F] s_b_19_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3793 [F] s_b_19_1 = constant u64 0 (const) */
        /* execute.simd:3793 [F] s_b_19_2: WriteRegBank 3:s_b_19_0 = s_b_19_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:3785 [F] s_b_19_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.simd:3799 [F] s_b_20_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
        /* execute.simd:3799 [F] s_b_20_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_20_3 = s_b_20_1*s_b_20_2 (const) */
        uint32_t s_b_20_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_20_4 = constant u32 0 (const) */
        /* execute.simd:3799 [F] s_b_20_5 = s_b_20_3+s_b_20_4 (const) */
        uint32_t s_b_20_5 = ((uint32_t)(s_b_20_3 + (uint32_t)0ULL));
        /* execute.simd:3799 [F] s_b_20_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_20_7 = (u32)s_b_20_6 (const) */
        /* execute.simd:3799 [F] s_b_20_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_20_9 = s_b_20_7*s_b_20_8 (const) */
        uint32_t s_b_20_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_20_10 = sym_35481_0_rm uint8_t */
        auto s_b_20_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_20_11 = (u32)s_b_20_10 */
        auto s_b_20_11 = emitter.zx(s_b_20_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_20_12 = s_b_20_9+s_b_20_11 */
        auto s_b_20_12 = emitter.add(emitter.const_u32(s_b_20_9), s_b_20_11);
        /* execute.simd:3799 [D] s_b_20_13 = ReadRegBank 23:s_b_20_12 (u8) */
        dbt::el::Value *s_b_20_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_20_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_20_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_20_14: WriteRegBank 23:s_b_20_5 = s_b_20_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_20_5))),s_b_20_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_20_5))),s_b_20_13);
        /* execute.simd:3799 [F] s_b_20_15: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.simd:3796 [F] s_b_21_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
        /* execute.simd:3796 [F] s_b_21_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_21_3 = s_b_21_1*s_b_21_2 (const) */
        uint32_t s_b_21_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_21_4 = constant u32 1 (const) */
        /* execute.simd:3796 [F] s_b_21_5 = s_b_21_3+s_b_21_4 (const) */
        uint32_t s_b_21_5 = ((uint32_t)(s_b_21_3 + (uint32_t)1ULL));
        /* execute.simd:3796 [D] s_b_21_6 = ReadRegBank 23:s_b_21_5 (u8) */
        auto s_b_21_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_21_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_21_5))),s_b_21_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_21_7: sym_35481_0_rm = s_b_21_6, dominates: s_b_22_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_21_6);
        /* execute.simd:3798 [F] s_b_21_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_21_9 = (u32)s_b_21_8 (const) */
        /* execute.simd:3798 [F] s_b_21_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_21_11 = s_b_21_9+s_b_21_10 (const) */
        uint32_t s_b_21_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_21_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_21_13 = s_b_21_12*s_b_21_11 (const) */
        uint32_t s_b_21_13 = ((uint32_t)((uint32_t)16ULL * s_b_21_11));
        /* execute.simd:3798 [D] s_b_21_14 = (u32)s_b_21_6 */
        auto s_b_21_14 = emitter.zx(s_b_21_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_21_15 = s_b_21_14<s_b_21_13 */
        auto s_b_21_15 = emitter.cmp_lt(s_b_21_14, emitter.const_u32(s_b_21_13));
        /* execute.simd:3798 [D] s_b_21_16: If s_b_21_15: Jump b_22 else b_23 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_22;
            dynamic_block_queue.push(block_b_22);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_23;
            dynamic_block_queue.push(block_b_23);
            false_target = block;
          }
          emitter.branch(s_b_21_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.simd:3799 [F] s_b_22_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
        /* execute.simd:3799 [F] s_b_22_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_22_3 = s_b_22_1*s_b_22_2 (const) */
        uint32_t s_b_22_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_22_4 = constant u32 1 (const) */
        /* execute.simd:3799 [F] s_b_22_5 = s_b_22_3+s_b_22_4 (const) */
        uint32_t s_b_22_5 = ((uint32_t)(s_b_22_3 + (uint32_t)1ULL));
        /* execute.simd:3799 [F] s_b_22_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_22_7 = (u32)s_b_22_6 (const) */
        /* execute.simd:3799 [F] s_b_22_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_22_9 = s_b_22_7*s_b_22_8 (const) */
        uint32_t s_b_22_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_22_10 = sym_35481_0_rm uint8_t */
        auto s_b_22_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_22_11 = (u32)s_b_22_10 */
        auto s_b_22_11 = emitter.zx(s_b_22_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_22_12 = s_b_22_9+s_b_22_11 */
        auto s_b_22_12 = emitter.add(emitter.const_u32(s_b_22_9), s_b_22_11);
        /* execute.simd:3799 [D] s_b_22_13 = ReadRegBank 23:s_b_22_12 (u8) */
        dbt::el::Value *s_b_22_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_22_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_22_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_22_14: WriteRegBank 23:s_b_22_5 = s_b_22_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_22_5))),s_b_22_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_22_5))),s_b_22_13);
        /* execute.simd:3799 [F] s_b_22_15: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.simd:3796 [F] s_b_23_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
        /* execute.simd:3796 [F] s_b_23_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_23_3 = s_b_23_1*s_b_23_2 (const) */
        uint32_t s_b_23_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_23_4 = constant u32 2 (const) */
        /* execute.simd:3796 [F] s_b_23_5 = s_b_23_3+s_b_23_4 (const) */
        uint32_t s_b_23_5 = ((uint32_t)(s_b_23_3 + (uint32_t)2ULL));
        /* execute.simd:3796 [D] s_b_23_6 = ReadRegBank 23:s_b_23_5 (u8) */
        auto s_b_23_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_23_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_23_5))),s_b_23_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_23_7: sym_35481_0_rm = s_b_23_6, dominates: s_b_24_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_23_6);
        /* execute.simd:3798 [F] s_b_23_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_23_9 = (u32)s_b_23_8 (const) */
        /* execute.simd:3798 [F] s_b_23_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_23_11 = s_b_23_9+s_b_23_10 (const) */
        uint32_t s_b_23_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_23_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_23_13 = s_b_23_12*s_b_23_11 (const) */
        uint32_t s_b_23_13 = ((uint32_t)((uint32_t)16ULL * s_b_23_11));
        /* execute.simd:3798 [D] s_b_23_14 = (u32)s_b_23_6 */
        auto s_b_23_14 = emitter.zx(s_b_23_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_23_15 = s_b_23_14<s_b_23_13 */
        auto s_b_23_15 = emitter.cmp_lt(s_b_23_14, emitter.const_u32(s_b_23_13));
        /* execute.simd:3798 [D] s_b_23_16: If s_b_23_15: Jump b_24 else b_25 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_24;
            dynamic_block_queue.push(block_b_24);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_25;
            dynamic_block_queue.push(block_b_25);
            false_target = block;
          }
          emitter.branch(s_b_23_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.simd:3799 [F] s_b_24_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
        /* execute.simd:3799 [F] s_b_24_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_24_3 = s_b_24_1*s_b_24_2 (const) */
        uint32_t s_b_24_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_24_4 = constant u32 2 (const) */
        /* execute.simd:3799 [F] s_b_24_5 = s_b_24_3+s_b_24_4 (const) */
        uint32_t s_b_24_5 = ((uint32_t)(s_b_24_3 + (uint32_t)2ULL));
        /* execute.simd:3799 [F] s_b_24_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_24_7 = (u32)s_b_24_6 (const) */
        /* execute.simd:3799 [F] s_b_24_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_24_9 = s_b_24_7*s_b_24_8 (const) */
        uint32_t s_b_24_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_24_10 = sym_35481_0_rm uint8_t */
        auto s_b_24_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_24_11 = (u32)s_b_24_10 */
        auto s_b_24_11 = emitter.zx(s_b_24_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_24_12 = s_b_24_9+s_b_24_11 */
        auto s_b_24_12 = emitter.add(emitter.const_u32(s_b_24_9), s_b_24_11);
        /* execute.simd:3799 [D] s_b_24_13 = ReadRegBank 23:s_b_24_12 (u8) */
        dbt::el::Value *s_b_24_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_24_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_24_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_24_14: WriteRegBank 23:s_b_24_5 = s_b_24_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_24_5))),s_b_24_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_24_5))),s_b_24_13);
        /* execute.simd:3799 [F] s_b_24_15: Jump b_25 (const) */
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.simd:3796 [F] s_b_25_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
        /* execute.simd:3796 [F] s_b_25_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_25_3 = s_b_25_1*s_b_25_2 (const) */
        uint32_t s_b_25_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_25_4 = constant u32 3 (const) */
        /* execute.simd:3796 [F] s_b_25_5 = s_b_25_3+s_b_25_4 (const) */
        uint32_t s_b_25_5 = ((uint32_t)(s_b_25_3 + (uint32_t)3ULL));
        /* execute.simd:3796 [D] s_b_25_6 = ReadRegBank 23:s_b_25_5 (u8) */
        auto s_b_25_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_25_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_25_5))),s_b_25_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_25_7: sym_35481_0_rm = s_b_25_6, dominates: s_b_26_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_25_6);
        /* execute.simd:3798 [F] s_b_25_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_25_9 = (u32)s_b_25_8 (const) */
        /* execute.simd:3798 [F] s_b_25_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_25_11 = s_b_25_9+s_b_25_10 (const) */
        uint32_t s_b_25_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_25_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_25_13 = s_b_25_12*s_b_25_11 (const) */
        uint32_t s_b_25_13 = ((uint32_t)((uint32_t)16ULL * s_b_25_11));
        /* execute.simd:3798 [D] s_b_25_14 = (u32)s_b_25_6 */
        auto s_b_25_14 = emitter.zx(s_b_25_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_25_15 = s_b_25_14<s_b_25_13 */
        auto s_b_25_15 = emitter.cmp_lt(s_b_25_14, emitter.const_u32(s_b_25_13));
        /* execute.simd:3798 [D] s_b_25_16: If s_b_25_15: Jump b_26 else b_27 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_26;
            dynamic_block_queue.push(block_b_26);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_27;
            dynamic_block_queue.push(block_b_27);
            false_target = block;
          }
          emitter.branch(s_b_25_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.simd:3799 [F] s_b_26_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
        /* execute.simd:3799 [F] s_b_26_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_26_3 = s_b_26_1*s_b_26_2 (const) */
        uint32_t s_b_26_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_26_4 = constant u32 3 (const) */
        /* execute.simd:3799 [F] s_b_26_5 = s_b_26_3+s_b_26_4 (const) */
        uint32_t s_b_26_5 = ((uint32_t)(s_b_26_3 + (uint32_t)3ULL));
        /* execute.simd:3799 [F] s_b_26_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_26_7 = (u32)s_b_26_6 (const) */
        /* execute.simd:3799 [F] s_b_26_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_26_9 = s_b_26_7*s_b_26_8 (const) */
        uint32_t s_b_26_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_26_10 = sym_35481_0_rm uint8_t */
        auto s_b_26_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_26_11 = (u32)s_b_26_10 */
        auto s_b_26_11 = emitter.zx(s_b_26_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_26_12 = s_b_26_9+s_b_26_11 */
        auto s_b_26_12 = emitter.add(emitter.const_u32(s_b_26_9), s_b_26_11);
        /* execute.simd:3799 [D] s_b_26_13 = ReadRegBank 23:s_b_26_12 (u8) */
        dbt::el::Value *s_b_26_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_26_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_26_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_26_14: WriteRegBank 23:s_b_26_5 = s_b_26_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_26_5))),s_b_26_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_26_5))),s_b_26_13);
        /* execute.simd:3799 [F] s_b_26_15: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.simd:3796 [F] s_b_27_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
        /* execute.simd:3796 [F] s_b_27_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_27_3 = s_b_27_1*s_b_27_2 (const) */
        uint32_t s_b_27_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_27_4 = constant u32 4 (const) */
        /* execute.simd:3796 [F] s_b_27_5 = s_b_27_3+s_b_27_4 (const) */
        uint32_t s_b_27_5 = ((uint32_t)(s_b_27_3 + (uint32_t)4ULL));
        /* execute.simd:3796 [D] s_b_27_6 = ReadRegBank 23:s_b_27_5 (u8) */
        auto s_b_27_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_27_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_27_5))),s_b_27_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_27_7: sym_35481_0_rm = s_b_27_6, dominates: s_b_28_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_27_6);
        /* execute.simd:3798 [F] s_b_27_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_27_9 = (u32)s_b_27_8 (const) */
        /* execute.simd:3798 [F] s_b_27_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_27_11 = s_b_27_9+s_b_27_10 (const) */
        uint32_t s_b_27_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_27_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_27_13 = s_b_27_12*s_b_27_11 (const) */
        uint32_t s_b_27_13 = ((uint32_t)((uint32_t)16ULL * s_b_27_11));
        /* execute.simd:3798 [D] s_b_27_14 = (u32)s_b_27_6 */
        auto s_b_27_14 = emitter.zx(s_b_27_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_27_15 = s_b_27_14<s_b_27_13 */
        auto s_b_27_15 = emitter.cmp_lt(s_b_27_14, emitter.const_u32(s_b_27_13));
        /* execute.simd:3798 [D] s_b_27_16: If s_b_27_15: Jump b_28 else b_29 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_28;
            dynamic_block_queue.push(block_b_28);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_29;
            dynamic_block_queue.push(block_b_29);
            false_target = block;
          }
          emitter.branch(s_b_27_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.simd:3799 [F] s_b_28_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
        /* execute.simd:3799 [F] s_b_28_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_28_3 = s_b_28_1*s_b_28_2 (const) */
        uint32_t s_b_28_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_28_4 = constant u32 4 (const) */
        /* execute.simd:3799 [F] s_b_28_5 = s_b_28_3+s_b_28_4 (const) */
        uint32_t s_b_28_5 = ((uint32_t)(s_b_28_3 + (uint32_t)4ULL));
        /* execute.simd:3799 [F] s_b_28_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_28_7 = (u32)s_b_28_6 (const) */
        /* execute.simd:3799 [F] s_b_28_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_28_9 = s_b_28_7*s_b_28_8 (const) */
        uint32_t s_b_28_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_28_10 = sym_35481_0_rm uint8_t */
        auto s_b_28_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_28_11 = (u32)s_b_28_10 */
        auto s_b_28_11 = emitter.zx(s_b_28_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_28_12 = s_b_28_9+s_b_28_11 */
        auto s_b_28_12 = emitter.add(emitter.const_u32(s_b_28_9), s_b_28_11);
        /* execute.simd:3799 [D] s_b_28_13 = ReadRegBank 23:s_b_28_12 (u8) */
        dbt::el::Value *s_b_28_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_28_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_28_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_28_14: WriteRegBank 23:s_b_28_5 = s_b_28_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_28_5))),s_b_28_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_28_5))),s_b_28_13);
        /* execute.simd:3799 [F] s_b_28_15: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.simd:3796 [F] s_b_29_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
        /* execute.simd:3796 [F] s_b_29_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_29_3 = s_b_29_1*s_b_29_2 (const) */
        uint32_t s_b_29_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_29_4 = constant u32 5 (const) */
        /* execute.simd:3796 [F] s_b_29_5 = s_b_29_3+s_b_29_4 (const) */
        uint32_t s_b_29_5 = ((uint32_t)(s_b_29_3 + (uint32_t)5ULL));
        /* execute.simd:3796 [D] s_b_29_6 = ReadRegBank 23:s_b_29_5 (u8) */
        auto s_b_29_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_29_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_29_5))),s_b_29_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_29_7: sym_35481_0_rm = s_b_29_6, dominates: s_b_30_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_29_6);
        /* execute.simd:3798 [F] s_b_29_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_29_9 = (u32)s_b_29_8 (const) */
        /* execute.simd:3798 [F] s_b_29_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_29_11 = s_b_29_9+s_b_29_10 (const) */
        uint32_t s_b_29_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_29_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_29_13 = s_b_29_12*s_b_29_11 (const) */
        uint32_t s_b_29_13 = ((uint32_t)((uint32_t)16ULL * s_b_29_11));
        /* execute.simd:3798 [D] s_b_29_14 = (u32)s_b_29_6 */
        auto s_b_29_14 = emitter.zx(s_b_29_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_29_15 = s_b_29_14<s_b_29_13 */
        auto s_b_29_15 = emitter.cmp_lt(s_b_29_14, emitter.const_u32(s_b_29_13));
        /* execute.simd:3798 [D] s_b_29_16: If s_b_29_15: Jump b_30 else b_31 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_30;
            dynamic_block_queue.push(block_b_30);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_31;
            dynamic_block_queue.push(block_b_31);
            false_target = block;
          }
          emitter.branch(s_b_29_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.simd:3799 [F] s_b_30_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_30_1 = (u32)s_b_30_0 (const) */
        /* execute.simd:3799 [F] s_b_30_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_30_3 = s_b_30_1*s_b_30_2 (const) */
        uint32_t s_b_30_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_30_4 = constant u32 5 (const) */
        /* execute.simd:3799 [F] s_b_30_5 = s_b_30_3+s_b_30_4 (const) */
        uint32_t s_b_30_5 = ((uint32_t)(s_b_30_3 + (uint32_t)5ULL));
        /* execute.simd:3799 [F] s_b_30_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_30_7 = (u32)s_b_30_6 (const) */
        /* execute.simd:3799 [F] s_b_30_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_30_9 = s_b_30_7*s_b_30_8 (const) */
        uint32_t s_b_30_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_30_10 = sym_35481_0_rm uint8_t */
        auto s_b_30_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_30_11 = (u32)s_b_30_10 */
        auto s_b_30_11 = emitter.zx(s_b_30_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_30_12 = s_b_30_9+s_b_30_11 */
        auto s_b_30_12 = emitter.add(emitter.const_u32(s_b_30_9), s_b_30_11);
        /* execute.simd:3799 [D] s_b_30_13 = ReadRegBank 23:s_b_30_12 (u8) */
        dbt::el::Value *s_b_30_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_30_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_30_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_30_14: WriteRegBank 23:s_b_30_5 = s_b_30_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_30_5))),s_b_30_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_30_5))),s_b_30_13);
        /* execute.simd:3799 [F] s_b_30_15: Jump b_31 (const) */
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.simd:3796 [F] s_b_31_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
        /* execute.simd:3796 [F] s_b_31_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_31_3 = s_b_31_1*s_b_31_2 (const) */
        uint32_t s_b_31_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_31_4 = constant u32 6 (const) */
        /* execute.simd:3796 [F] s_b_31_5 = s_b_31_3+s_b_31_4 (const) */
        uint32_t s_b_31_5 = ((uint32_t)(s_b_31_3 + (uint32_t)6ULL));
        /* execute.simd:3796 [D] s_b_31_6 = ReadRegBank 23:s_b_31_5 (u8) */
        auto s_b_31_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_31_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_31_5))),s_b_31_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_31_7: sym_35481_0_rm = s_b_31_6, dominates: s_b_32_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_31_6);
        /* execute.simd:3798 [F] s_b_31_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_31_9 = (u32)s_b_31_8 (const) */
        /* execute.simd:3798 [F] s_b_31_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_31_11 = s_b_31_9+s_b_31_10 (const) */
        uint32_t s_b_31_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_31_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_31_13 = s_b_31_12*s_b_31_11 (const) */
        uint32_t s_b_31_13 = ((uint32_t)((uint32_t)16ULL * s_b_31_11));
        /* execute.simd:3798 [D] s_b_31_14 = (u32)s_b_31_6 */
        auto s_b_31_14 = emitter.zx(s_b_31_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_31_15 = s_b_31_14<s_b_31_13 */
        auto s_b_31_15 = emitter.cmp_lt(s_b_31_14, emitter.const_u32(s_b_31_13));
        /* execute.simd:3798 [D] s_b_31_16: If s_b_31_15: Jump b_32 else b_33 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_32;
            dynamic_block_queue.push(block_b_32);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_33;
            dynamic_block_queue.push(block_b_33);
            false_target = block;
          }
          emitter.branch(s_b_31_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.simd:3799 [F] s_b_32_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_32_1 = (u32)s_b_32_0 (const) */
        /* execute.simd:3799 [F] s_b_32_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_32_3 = s_b_32_1*s_b_32_2 (const) */
        uint32_t s_b_32_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_32_4 = constant u32 6 (const) */
        /* execute.simd:3799 [F] s_b_32_5 = s_b_32_3+s_b_32_4 (const) */
        uint32_t s_b_32_5 = ((uint32_t)(s_b_32_3 + (uint32_t)6ULL));
        /* execute.simd:3799 [F] s_b_32_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_32_7 = (u32)s_b_32_6 (const) */
        /* execute.simd:3799 [F] s_b_32_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_32_9 = s_b_32_7*s_b_32_8 (const) */
        uint32_t s_b_32_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_32_10 = sym_35481_0_rm uint8_t */
        auto s_b_32_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_32_11 = (u32)s_b_32_10 */
        auto s_b_32_11 = emitter.zx(s_b_32_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_32_12 = s_b_32_9+s_b_32_11 */
        auto s_b_32_12 = emitter.add(emitter.const_u32(s_b_32_9), s_b_32_11);
        /* execute.simd:3799 [D] s_b_32_13 = ReadRegBank 23:s_b_32_12 (u8) */
        dbt::el::Value *s_b_32_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_32_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_32_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_32_14: WriteRegBank 23:s_b_32_5 = s_b_32_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_32_5))),s_b_32_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_32_5))),s_b_32_13);
        /* execute.simd:3799 [F] s_b_32_15: Jump b_33 (const) */
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.simd:3796 [F] s_b_33_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_33_1 = (u32)s_b_33_0 (const) */
        /* execute.simd:3796 [F] s_b_33_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_33_3 = s_b_33_1*s_b_33_2 (const) */
        uint32_t s_b_33_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_33_4 = constant u32 7 (const) */
        /* execute.simd:3796 [F] s_b_33_5 = s_b_33_3+s_b_33_4 (const) */
        uint32_t s_b_33_5 = ((uint32_t)(s_b_33_3 + (uint32_t)7ULL));
        /* execute.simd:3796 [D] s_b_33_6 = ReadRegBank 23:s_b_33_5 (u8) */
        auto s_b_33_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_33_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_33_5))),s_b_33_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_33_7: sym_35481_0_rm = s_b_33_6, dominates: s_b_34_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_33_6);
        /* execute.simd:3798 [F] s_b_33_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_33_9 = (u32)s_b_33_8 (const) */
        /* execute.simd:3798 [F] s_b_33_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_33_11 = s_b_33_9+s_b_33_10 (const) */
        uint32_t s_b_33_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_33_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_33_13 = s_b_33_12*s_b_33_11 (const) */
        uint32_t s_b_33_13 = ((uint32_t)((uint32_t)16ULL * s_b_33_11));
        /* execute.simd:3798 [D] s_b_33_14 = (u32)s_b_33_6 */
        auto s_b_33_14 = emitter.zx(s_b_33_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_33_15 = s_b_33_14<s_b_33_13 */
        auto s_b_33_15 = emitter.cmp_lt(s_b_33_14, emitter.const_u32(s_b_33_13));
        /* execute.simd:3798 [D] s_b_33_16: If s_b_33_15: Jump b_34 else b_35 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_34;
            dynamic_block_queue.push(block_b_34);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_35;
            dynamic_block_queue.push(block_b_35);
            false_target = block;
          }
          emitter.branch(s_b_33_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.simd:3799 [F] s_b_34_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
        /* execute.simd:3799 [F] s_b_34_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_34_3 = s_b_34_1*s_b_34_2 (const) */
        uint32_t s_b_34_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_34_4 = constant u32 7 (const) */
        /* execute.simd:3799 [F] s_b_34_5 = s_b_34_3+s_b_34_4 (const) */
        uint32_t s_b_34_5 = ((uint32_t)(s_b_34_3 + (uint32_t)7ULL));
        /* execute.simd:3799 [F] s_b_34_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_34_7 = (u32)s_b_34_6 (const) */
        /* execute.simd:3799 [F] s_b_34_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_34_9 = s_b_34_7*s_b_34_8 (const) */
        uint32_t s_b_34_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_34_10 = sym_35481_0_rm uint8_t */
        auto s_b_34_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_34_11 = (u32)s_b_34_10 */
        auto s_b_34_11 = emitter.zx(s_b_34_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_34_12 = s_b_34_9+s_b_34_11 */
        auto s_b_34_12 = emitter.add(emitter.const_u32(s_b_34_9), s_b_34_11);
        /* execute.simd:3799 [D] s_b_34_13 = ReadRegBank 23:s_b_34_12 (u8) */
        dbt::el::Value *s_b_34_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_34_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_34_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_34_14: WriteRegBank 23:s_b_34_5 = s_b_34_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_34_5))),s_b_34_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_34_5))),s_b_34_13);
        /* execute.simd:3799 [F] s_b_34_15: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.simd:3796 [F] s_b_35_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
        /* execute.simd:3796 [F] s_b_35_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_35_3 = s_b_35_1*s_b_35_2 (const) */
        uint32_t s_b_35_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_35_4 = constant u32 8 (const) */
        /* execute.simd:3796 [F] s_b_35_5 = s_b_35_3+s_b_35_4 (const) */
        uint32_t s_b_35_5 = ((uint32_t)(s_b_35_3 + (uint32_t)8ULL));
        /* execute.simd:3796 [D] s_b_35_6 = ReadRegBank 23:s_b_35_5 (u8) */
        auto s_b_35_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_35_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_35_5))),s_b_35_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_35_7: sym_35481_0_rm = s_b_35_6, dominates: s_b_36_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_35_6);
        /* execute.simd:3798 [F] s_b_35_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_35_9 = (u32)s_b_35_8 (const) */
        /* execute.simd:3798 [F] s_b_35_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_35_11 = s_b_35_9+s_b_35_10 (const) */
        uint32_t s_b_35_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_35_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_35_13 = s_b_35_12*s_b_35_11 (const) */
        uint32_t s_b_35_13 = ((uint32_t)((uint32_t)16ULL * s_b_35_11));
        /* execute.simd:3798 [D] s_b_35_14 = (u32)s_b_35_6 */
        auto s_b_35_14 = emitter.zx(s_b_35_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_35_15 = s_b_35_14<s_b_35_13 */
        auto s_b_35_15 = emitter.cmp_lt(s_b_35_14, emitter.const_u32(s_b_35_13));
        /* execute.simd:3798 [D] s_b_35_16: If s_b_35_15: Jump b_36 else b_37 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_36;
            dynamic_block_queue.push(block_b_36);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_37;
            dynamic_block_queue.push(block_b_37);
            false_target = block;
          }
          emitter.branch(s_b_35_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_36) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_36);
        /* execute.simd:3799 [F] s_b_36_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_36_1 = (u32)s_b_36_0 (const) */
        /* execute.simd:3799 [F] s_b_36_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_36_3 = s_b_36_1*s_b_36_2 (const) */
        uint32_t s_b_36_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_36_4 = constant u32 8 (const) */
        /* execute.simd:3799 [F] s_b_36_5 = s_b_36_3+s_b_36_4 (const) */
        uint32_t s_b_36_5 = ((uint32_t)(s_b_36_3 + (uint32_t)8ULL));
        /* execute.simd:3799 [F] s_b_36_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_36_7 = (u32)s_b_36_6 (const) */
        /* execute.simd:3799 [F] s_b_36_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_36_9 = s_b_36_7*s_b_36_8 (const) */
        uint32_t s_b_36_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_36_10 = sym_35481_0_rm uint8_t */
        auto s_b_36_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_36_11 = (u32)s_b_36_10 */
        auto s_b_36_11 = emitter.zx(s_b_36_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_36_12 = s_b_36_9+s_b_36_11 */
        auto s_b_36_12 = emitter.add(emitter.const_u32(s_b_36_9), s_b_36_11);
        /* execute.simd:3799 [D] s_b_36_13 = ReadRegBank 23:s_b_36_12 (u8) */
        dbt::el::Value *s_b_36_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_36_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_36_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_36_14: WriteRegBank 23:s_b_36_5 = s_b_36_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_36_5))),s_b_36_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_36_5))),s_b_36_13);
        /* execute.simd:3799 [F] s_b_36_15: Jump b_37 (const) */
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.simd:3796 [F] s_b_37_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_37_1 = (u32)s_b_37_0 (const) */
        /* execute.simd:3796 [F] s_b_37_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_37_3 = s_b_37_1*s_b_37_2 (const) */
        uint32_t s_b_37_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_37_4 = constant u32 9 (const) */
        /* execute.simd:3796 [F] s_b_37_5 = s_b_37_3+s_b_37_4 (const) */
        uint32_t s_b_37_5 = ((uint32_t)(s_b_37_3 + (uint32_t)9ULL));
        /* execute.simd:3796 [D] s_b_37_6 = ReadRegBank 23:s_b_37_5 (u8) */
        auto s_b_37_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_37_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_37_5))),s_b_37_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_37_7: sym_35481_0_rm = s_b_37_6, dominates: s_b_38_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_37_6);
        /* execute.simd:3798 [F] s_b_37_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_37_9 = (u32)s_b_37_8 (const) */
        /* execute.simd:3798 [F] s_b_37_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_37_11 = s_b_37_9+s_b_37_10 (const) */
        uint32_t s_b_37_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_37_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_37_13 = s_b_37_12*s_b_37_11 (const) */
        uint32_t s_b_37_13 = ((uint32_t)((uint32_t)16ULL * s_b_37_11));
        /* execute.simd:3798 [D] s_b_37_14 = (u32)s_b_37_6 */
        auto s_b_37_14 = emitter.zx(s_b_37_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_37_15 = s_b_37_14<s_b_37_13 */
        auto s_b_37_15 = emitter.cmp_lt(s_b_37_14, emitter.const_u32(s_b_37_13));
        /* execute.simd:3798 [D] s_b_37_16: If s_b_37_15: Jump b_38 else b_39 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_38;
            dynamic_block_queue.push(block_b_38);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_39;
            dynamic_block_queue.push(block_b_39);
            false_target = block;
          }
          emitter.branch(s_b_37_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_38) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_38);
        /* execute.simd:3799 [F] s_b_38_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_38_1 = (u32)s_b_38_0 (const) */
        /* execute.simd:3799 [F] s_b_38_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_38_3 = s_b_38_1*s_b_38_2 (const) */
        uint32_t s_b_38_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_38_4 = constant u32 9 (const) */
        /* execute.simd:3799 [F] s_b_38_5 = s_b_38_3+s_b_38_4 (const) */
        uint32_t s_b_38_5 = ((uint32_t)(s_b_38_3 + (uint32_t)9ULL));
        /* execute.simd:3799 [F] s_b_38_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_38_7 = (u32)s_b_38_6 (const) */
        /* execute.simd:3799 [F] s_b_38_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_38_9 = s_b_38_7*s_b_38_8 (const) */
        uint32_t s_b_38_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_38_10 = sym_35481_0_rm uint8_t */
        auto s_b_38_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_38_11 = (u32)s_b_38_10 */
        auto s_b_38_11 = emitter.zx(s_b_38_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_38_12 = s_b_38_9+s_b_38_11 */
        auto s_b_38_12 = emitter.add(emitter.const_u32(s_b_38_9), s_b_38_11);
        /* execute.simd:3799 [D] s_b_38_13 = ReadRegBank 23:s_b_38_12 (u8) */
        dbt::el::Value *s_b_38_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_38_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_38_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_38_14: WriteRegBank 23:s_b_38_5 = s_b_38_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_38_5))),s_b_38_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_38_5))),s_b_38_13);
        /* execute.simd:3799 [F] s_b_38_15: Jump b_39 (const) */
        {
          auto block = block_b_39;
          dynamic_block_queue.push(block_b_39);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.simd:3796 [F] s_b_39_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_39_1 = (u32)s_b_39_0 (const) */
        /* execute.simd:3796 [F] s_b_39_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_39_3 = s_b_39_1*s_b_39_2 (const) */
        uint32_t s_b_39_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_39_4 = constant u32 a (const) */
        /* execute.simd:3796 [F] s_b_39_5 = s_b_39_3+s_b_39_4 (const) */
        uint32_t s_b_39_5 = ((uint32_t)(s_b_39_3 + (uint32_t)10ULL));
        /* execute.simd:3796 [D] s_b_39_6 = ReadRegBank 23:s_b_39_5 (u8) */
        auto s_b_39_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_39_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_39_5))),s_b_39_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_39_7: sym_35481_0_rm = s_b_39_6, dominates: s_b_40_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_39_6);
        /* execute.simd:3798 [F] s_b_39_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_39_9 = (u32)s_b_39_8 (const) */
        /* execute.simd:3798 [F] s_b_39_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_39_11 = s_b_39_9+s_b_39_10 (const) */
        uint32_t s_b_39_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_39_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_39_13 = s_b_39_12*s_b_39_11 (const) */
        uint32_t s_b_39_13 = ((uint32_t)((uint32_t)16ULL * s_b_39_11));
        /* execute.simd:3798 [D] s_b_39_14 = (u32)s_b_39_6 */
        auto s_b_39_14 = emitter.zx(s_b_39_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_39_15 = s_b_39_14<s_b_39_13 */
        auto s_b_39_15 = emitter.cmp_lt(s_b_39_14, emitter.const_u32(s_b_39_13));
        /* execute.simd:3798 [D] s_b_39_16: If s_b_39_15: Jump b_40 else b_41 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_40;
            dynamic_block_queue.push(block_b_40);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_41;
            dynamic_block_queue.push(block_b_41);
            false_target = block;
          }
          emitter.branch(s_b_39_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_40) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_40);
        /* execute.simd:3799 [F] s_b_40_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_40_1 = (u32)s_b_40_0 (const) */
        /* execute.simd:3799 [F] s_b_40_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_40_3 = s_b_40_1*s_b_40_2 (const) */
        uint32_t s_b_40_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_40_4 = constant u32 a (const) */
        /* execute.simd:3799 [F] s_b_40_5 = s_b_40_3+s_b_40_4 (const) */
        uint32_t s_b_40_5 = ((uint32_t)(s_b_40_3 + (uint32_t)10ULL));
        /* execute.simd:3799 [F] s_b_40_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_40_7 = (u32)s_b_40_6 (const) */
        /* execute.simd:3799 [F] s_b_40_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_40_9 = s_b_40_7*s_b_40_8 (const) */
        uint32_t s_b_40_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_40_10 = sym_35481_0_rm uint8_t */
        auto s_b_40_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_40_11 = (u32)s_b_40_10 */
        auto s_b_40_11 = emitter.zx(s_b_40_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_40_12 = s_b_40_9+s_b_40_11 */
        auto s_b_40_12 = emitter.add(emitter.const_u32(s_b_40_9), s_b_40_11);
        /* execute.simd:3799 [D] s_b_40_13 = ReadRegBank 23:s_b_40_12 (u8) */
        dbt::el::Value *s_b_40_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_40_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_40_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_40_14: WriteRegBank 23:s_b_40_5 = s_b_40_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_40_5))),s_b_40_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_40_5))),s_b_40_13);
        /* execute.simd:3799 [F] s_b_40_15: Jump b_41 (const) */
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.simd:3796 [F] s_b_41_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_41_1 = (u32)s_b_41_0 (const) */
        /* execute.simd:3796 [F] s_b_41_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_41_3 = s_b_41_1*s_b_41_2 (const) */
        uint32_t s_b_41_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_41_4 = constant u32 b (const) */
        /* execute.simd:3796 [F] s_b_41_5 = s_b_41_3+s_b_41_4 (const) */
        uint32_t s_b_41_5 = ((uint32_t)(s_b_41_3 + (uint32_t)11ULL));
        /* execute.simd:3796 [D] s_b_41_6 = ReadRegBank 23:s_b_41_5 (u8) */
        auto s_b_41_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_41_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_41_5))),s_b_41_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_41_7: sym_35481_0_rm = s_b_41_6, dominates: s_b_42_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_41_6);
        /* execute.simd:3798 [F] s_b_41_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_41_9 = (u32)s_b_41_8 (const) */
        /* execute.simd:3798 [F] s_b_41_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_41_11 = s_b_41_9+s_b_41_10 (const) */
        uint32_t s_b_41_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_41_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_41_13 = s_b_41_12*s_b_41_11 (const) */
        uint32_t s_b_41_13 = ((uint32_t)((uint32_t)16ULL * s_b_41_11));
        /* execute.simd:3798 [D] s_b_41_14 = (u32)s_b_41_6 */
        auto s_b_41_14 = emitter.zx(s_b_41_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_41_15 = s_b_41_14<s_b_41_13 */
        auto s_b_41_15 = emitter.cmp_lt(s_b_41_14, emitter.const_u32(s_b_41_13));
        /* execute.simd:3798 [D] s_b_41_16: If s_b_41_15: Jump b_42 else b_43 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_42;
            dynamic_block_queue.push(block_b_42);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_43;
            dynamic_block_queue.push(block_b_43);
            false_target = block;
          }
          emitter.branch(s_b_41_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_42) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_42);
        /* execute.simd:3799 [F] s_b_42_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_42_1 = (u32)s_b_42_0 (const) */
        /* execute.simd:3799 [F] s_b_42_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_42_3 = s_b_42_1*s_b_42_2 (const) */
        uint32_t s_b_42_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_42_4 = constant u32 b (const) */
        /* execute.simd:3799 [F] s_b_42_5 = s_b_42_3+s_b_42_4 (const) */
        uint32_t s_b_42_5 = ((uint32_t)(s_b_42_3 + (uint32_t)11ULL));
        /* execute.simd:3799 [F] s_b_42_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_42_7 = (u32)s_b_42_6 (const) */
        /* execute.simd:3799 [F] s_b_42_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_42_9 = s_b_42_7*s_b_42_8 (const) */
        uint32_t s_b_42_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_42_10 = sym_35481_0_rm uint8_t */
        auto s_b_42_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_42_11 = (u32)s_b_42_10 */
        auto s_b_42_11 = emitter.zx(s_b_42_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_42_12 = s_b_42_9+s_b_42_11 */
        auto s_b_42_12 = emitter.add(emitter.const_u32(s_b_42_9), s_b_42_11);
        /* execute.simd:3799 [D] s_b_42_13 = ReadRegBank 23:s_b_42_12 (u8) */
        dbt::el::Value *s_b_42_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_42_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_42_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_42_14: WriteRegBank 23:s_b_42_5 = s_b_42_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_42_5))),s_b_42_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_42_5))),s_b_42_13);
        /* execute.simd:3799 [F] s_b_42_15: Jump b_43 (const) */
        {
          auto block = block_b_43;
          dynamic_block_queue.push(block_b_43);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_43) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_43);
        /* execute.simd:3796 [F] s_b_43_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_43_1 = (u32)s_b_43_0 (const) */
        /* execute.simd:3796 [F] s_b_43_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_43_3 = s_b_43_1*s_b_43_2 (const) */
        uint32_t s_b_43_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_43_4 = constant u32 c (const) */
        /* execute.simd:3796 [F] s_b_43_5 = s_b_43_3+s_b_43_4 (const) */
        uint32_t s_b_43_5 = ((uint32_t)(s_b_43_3 + (uint32_t)12ULL));
        /* execute.simd:3796 [D] s_b_43_6 = ReadRegBank 23:s_b_43_5 (u8) */
        auto s_b_43_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_43_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_43_5))),s_b_43_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_43_7: sym_35481_0_rm = s_b_43_6, dominates: s_b_44_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_43_6);
        /* execute.simd:3798 [F] s_b_43_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_43_9 = (u32)s_b_43_8 (const) */
        /* execute.simd:3798 [F] s_b_43_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_43_11 = s_b_43_9+s_b_43_10 (const) */
        uint32_t s_b_43_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_43_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_43_13 = s_b_43_12*s_b_43_11 (const) */
        uint32_t s_b_43_13 = ((uint32_t)((uint32_t)16ULL * s_b_43_11));
        /* execute.simd:3798 [D] s_b_43_14 = (u32)s_b_43_6 */
        auto s_b_43_14 = emitter.zx(s_b_43_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_43_15 = s_b_43_14<s_b_43_13 */
        auto s_b_43_15 = emitter.cmp_lt(s_b_43_14, emitter.const_u32(s_b_43_13));
        /* execute.simd:3798 [D] s_b_43_16: If s_b_43_15: Jump b_44 else b_45 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_44;
            dynamic_block_queue.push(block_b_44);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_45;
            dynamic_block_queue.push(block_b_45);
            false_target = block;
          }
          emitter.branch(s_b_43_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_44) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_44);
        /* execute.simd:3799 [F] s_b_44_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_44_1 = (u32)s_b_44_0 (const) */
        /* execute.simd:3799 [F] s_b_44_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_44_3 = s_b_44_1*s_b_44_2 (const) */
        uint32_t s_b_44_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_44_4 = constant u32 c (const) */
        /* execute.simd:3799 [F] s_b_44_5 = s_b_44_3+s_b_44_4 (const) */
        uint32_t s_b_44_5 = ((uint32_t)(s_b_44_3 + (uint32_t)12ULL));
        /* execute.simd:3799 [F] s_b_44_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_44_7 = (u32)s_b_44_6 (const) */
        /* execute.simd:3799 [F] s_b_44_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_44_9 = s_b_44_7*s_b_44_8 (const) */
        uint32_t s_b_44_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_44_10 = sym_35481_0_rm uint8_t */
        auto s_b_44_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_44_11 = (u32)s_b_44_10 */
        auto s_b_44_11 = emitter.zx(s_b_44_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_44_12 = s_b_44_9+s_b_44_11 */
        auto s_b_44_12 = emitter.add(emitter.const_u32(s_b_44_9), s_b_44_11);
        /* execute.simd:3799 [D] s_b_44_13 = ReadRegBank 23:s_b_44_12 (u8) */
        dbt::el::Value *s_b_44_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_44_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_44_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_44_14: WriteRegBank 23:s_b_44_5 = s_b_44_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_44_5))),s_b_44_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_44_5))),s_b_44_13);
        /* execute.simd:3799 [F] s_b_44_15: Jump b_45 (const) */
        {
          auto block = block_b_45;
          dynamic_block_queue.push(block_b_45);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_45) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_45);
        /* execute.simd:3796 [F] s_b_45_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_45_1 = (u32)s_b_45_0 (const) */
        /* execute.simd:3796 [F] s_b_45_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_45_3 = s_b_45_1*s_b_45_2 (const) */
        uint32_t s_b_45_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_45_4 = constant u32 d (const) */
        /* execute.simd:3796 [F] s_b_45_5 = s_b_45_3+s_b_45_4 (const) */
        uint32_t s_b_45_5 = ((uint32_t)(s_b_45_3 + (uint32_t)13ULL));
        /* execute.simd:3796 [D] s_b_45_6 = ReadRegBank 23:s_b_45_5 (u8) */
        auto s_b_45_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_45_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_45_5))),s_b_45_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_45_7: sym_35481_0_rm = s_b_45_6, dominates: s_b_46_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_45_6);
        /* execute.simd:3798 [F] s_b_45_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_45_9 = (u32)s_b_45_8 (const) */
        /* execute.simd:3798 [F] s_b_45_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_45_11 = s_b_45_9+s_b_45_10 (const) */
        uint32_t s_b_45_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_45_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_45_13 = s_b_45_12*s_b_45_11 (const) */
        uint32_t s_b_45_13 = ((uint32_t)((uint32_t)16ULL * s_b_45_11));
        /* execute.simd:3798 [D] s_b_45_14 = (u32)s_b_45_6 */
        auto s_b_45_14 = emitter.zx(s_b_45_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_45_15 = s_b_45_14<s_b_45_13 */
        auto s_b_45_15 = emitter.cmp_lt(s_b_45_14, emitter.const_u32(s_b_45_13));
        /* execute.simd:3798 [D] s_b_45_16: If s_b_45_15: Jump b_46 else b_47 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_46;
            dynamic_block_queue.push(block_b_46);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_47;
            dynamic_block_queue.push(block_b_47);
            false_target = block;
          }
          emitter.branch(s_b_45_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_46) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_46);
        /* execute.simd:3799 [F] s_b_46_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_46_1 = (u32)s_b_46_0 (const) */
        /* execute.simd:3799 [F] s_b_46_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_46_3 = s_b_46_1*s_b_46_2 (const) */
        uint32_t s_b_46_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_46_4 = constant u32 d (const) */
        /* execute.simd:3799 [F] s_b_46_5 = s_b_46_3+s_b_46_4 (const) */
        uint32_t s_b_46_5 = ((uint32_t)(s_b_46_3 + (uint32_t)13ULL));
        /* execute.simd:3799 [F] s_b_46_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_46_7 = (u32)s_b_46_6 (const) */
        /* execute.simd:3799 [F] s_b_46_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_46_9 = s_b_46_7*s_b_46_8 (const) */
        uint32_t s_b_46_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_46_10 = sym_35481_0_rm uint8_t */
        auto s_b_46_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_46_11 = (u32)s_b_46_10 */
        auto s_b_46_11 = emitter.zx(s_b_46_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_46_12 = s_b_46_9+s_b_46_11 */
        auto s_b_46_12 = emitter.add(emitter.const_u32(s_b_46_9), s_b_46_11);
        /* execute.simd:3799 [D] s_b_46_13 = ReadRegBank 23:s_b_46_12 (u8) */
        dbt::el::Value *s_b_46_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_46_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_46_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_46_14: WriteRegBank 23:s_b_46_5 = s_b_46_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_46_5))),s_b_46_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_46_5))),s_b_46_13);
        /* execute.simd:3799 [F] s_b_46_15: Jump b_47 (const) */
        {
          auto block = block_b_47;
          dynamic_block_queue.push(block_b_47);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_47) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_47);
        /* execute.simd:3796 [F] s_b_47_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_47_1 = (u32)s_b_47_0 (const) */
        /* execute.simd:3796 [F] s_b_47_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_47_3 = s_b_47_1*s_b_47_2 (const) */
        uint32_t s_b_47_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_47_4 = constant u32 e (const) */
        /* execute.simd:3796 [F] s_b_47_5 = s_b_47_3+s_b_47_4 (const) */
        uint32_t s_b_47_5 = ((uint32_t)(s_b_47_3 + (uint32_t)14ULL));
        /* execute.simd:3796 [D] s_b_47_6 = ReadRegBank 23:s_b_47_5 (u8) */
        auto s_b_47_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_47_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_47_5))),s_b_47_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_47_7: sym_35481_0_rm = s_b_47_6, dominates: s_b_48_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_47_6);
        /* execute.simd:3798 [F] s_b_47_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_47_9 = (u32)s_b_47_8 (const) */
        /* execute.simd:3798 [F] s_b_47_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_47_11 = s_b_47_9+s_b_47_10 (const) */
        uint32_t s_b_47_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_47_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_47_13 = s_b_47_12*s_b_47_11 (const) */
        uint32_t s_b_47_13 = ((uint32_t)((uint32_t)16ULL * s_b_47_11));
        /* execute.simd:3798 [D] s_b_47_14 = (u32)s_b_47_6 */
        auto s_b_47_14 = emitter.zx(s_b_47_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_47_15 = s_b_47_14<s_b_47_13 */
        auto s_b_47_15 = emitter.cmp_lt(s_b_47_14, emitter.const_u32(s_b_47_13));
        /* execute.simd:3798 [D] s_b_47_16: If s_b_47_15: Jump b_48 else b_49 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_48;
            dynamic_block_queue.push(block_b_48);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_49;
            dynamic_block_queue.push(block_b_49);
            false_target = block;
          }
          emitter.branch(s_b_47_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_48) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_48);
        /* execute.simd:3799 [F] s_b_48_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_48_1 = (u32)s_b_48_0 (const) */
        /* execute.simd:3799 [F] s_b_48_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_48_3 = s_b_48_1*s_b_48_2 (const) */
        uint32_t s_b_48_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_48_4 = constant u32 e (const) */
        /* execute.simd:3799 [F] s_b_48_5 = s_b_48_3+s_b_48_4 (const) */
        uint32_t s_b_48_5 = ((uint32_t)(s_b_48_3 + (uint32_t)14ULL));
        /* execute.simd:3799 [F] s_b_48_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_48_7 = (u32)s_b_48_6 (const) */
        /* execute.simd:3799 [F] s_b_48_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_48_9 = s_b_48_7*s_b_48_8 (const) */
        uint32_t s_b_48_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_48_10 = sym_35481_0_rm uint8_t */
        auto s_b_48_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_48_11 = (u32)s_b_48_10 */
        auto s_b_48_11 = emitter.zx(s_b_48_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_48_12 = s_b_48_9+s_b_48_11 */
        auto s_b_48_12 = emitter.add(emitter.const_u32(s_b_48_9), s_b_48_11);
        /* execute.simd:3799 [D] s_b_48_13 = ReadRegBank 23:s_b_48_12 (u8) */
        dbt::el::Value *s_b_48_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_48_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_48_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_48_14: WriteRegBank 23:s_b_48_5 = s_b_48_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_48_5))),s_b_48_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_48_5))),s_b_48_13);
        /* execute.simd:3799 [F] s_b_48_15: Jump b_49 (const) */
        {
          auto block = block_b_49;
          dynamic_block_queue.push(block_b_49);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_49) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_49);
        /* execute.simd:3796 [F] s_b_49_0=sym_35073_3_parameter_inst.rm (const) */
        /* execute.simd:3796 [F] s_b_49_1 = (u32)s_b_49_0 (const) */
        /* execute.simd:3796 [F] s_b_49_2 = constant u32 10 (const) */
        /* execute.simd:3796 [F] s_b_49_3 = s_b_49_1*s_b_49_2 (const) */
        uint32_t s_b_49_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3796 [F] s_b_49_4 = constant u32 f (const) */
        /* execute.simd:3796 [F] s_b_49_5 = s_b_49_3+s_b_49_4 (const) */
        uint32_t s_b_49_5 = ((uint32_t)(s_b_49_3 + (uint32_t)15ULL));
        /* execute.simd:3796 [D] s_b_49_6 = ReadRegBank 23:s_b_49_5 (u8) */
        auto s_b_49_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_49_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_49_5))),s_b_49_6,emitter.const_u8(1));
        }
        /* execute.simd:3796 [D] s_b_49_7: sym_35481_0_rm = s_b_49_6, dominates: s_b_50_10  */
        emitter.store_local(DV_sym_35481_0_rm, s_b_49_6);
        /* execute.simd:3798 [F] s_b_49_8=sym_35073_3_parameter_inst.len (const) */
        /* execute.simd:3798 [F] s_b_49_9 = (u32)s_b_49_8 (const) */
        /* execute.simd:3798 [F] s_b_49_10 = constant u32 1 (const) */
        /* execute.simd:3798 [F] s_b_49_11 = s_b_49_9+s_b_49_10 (const) */
        uint32_t s_b_49_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3798 [F] s_b_49_12 = constant u32 10 (const) */
        /* execute.simd:3798 [F] s_b_49_13 = s_b_49_12*s_b_49_11 (const) */
        uint32_t s_b_49_13 = ((uint32_t)((uint32_t)16ULL * s_b_49_11));
        /* execute.simd:3798 [D] s_b_49_14 = (u32)s_b_49_6 */
        auto s_b_49_14 = emitter.zx(s_b_49_6, emitter.context().types().u32());
        /* execute.simd:3798 [D] s_b_49_15 = s_b_49_14<s_b_49_13 */
        auto s_b_49_15 = emitter.cmp_lt(s_b_49_14, emitter.const_u32(s_b_49_13));
        /* execute.simd:3798 [D] s_b_49_16: If s_b_49_15: Jump b_50 else b_2 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_50;
            dynamic_block_queue.push(block_b_50);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_2;
            dynamic_block_queue.push(block_b_2);
            false_target = block;
          }
          emitter.branch(s_b_49_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_50) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_50);
        /* execute.simd:3799 [F] s_b_50_0=sym_35073_3_parameter_inst.rd (const) */
        /* execute.simd:3799 [F] s_b_50_1 = (u32)s_b_50_0 (const) */
        /* execute.simd:3799 [F] s_b_50_2 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_50_3 = s_b_50_1*s_b_50_2 (const) */
        uint32_t s_b_50_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3799 [F] s_b_50_4 = constant u32 f (const) */
        /* execute.simd:3799 [F] s_b_50_5 = s_b_50_3+s_b_50_4 (const) */
        uint32_t s_b_50_5 = ((uint32_t)(s_b_50_3 + (uint32_t)15ULL));
        /* execute.simd:3799 [F] s_b_50_6=sym_35073_3_parameter_inst.rn (const) */
        /* execute.simd:3799 [F] s_b_50_7 = (u32)s_b_50_6 (const) */
        /* execute.simd:3799 [F] s_b_50_8 = constant u32 10 (const) */
        /* execute.simd:3799 [F] s_b_50_9 = s_b_50_7*s_b_50_8 (const) */
        uint32_t s_b_50_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3799 [D] s_b_50_10 = sym_35481_0_rm uint8_t */
        auto s_b_50_10 = emitter.load_local(DV_sym_35481_0_rm, emitter.context().types().u8());
        /* execute.simd:3799 [D] s_b_50_11 = (u32)s_b_50_10 */
        auto s_b_50_11 = emitter.zx(s_b_50_10, emitter.context().types().u32());
        /* execute.simd:3799 [D] s_b_50_12 = s_b_50_9+s_b_50_11 */
        auto s_b_50_12 = emitter.add(emitter.const_u32(s_b_50_9), s_b_50_11);
        /* execute.simd:3799 [D] s_b_50_13 = ReadRegBank 23:s_b_50_12 (u8) */
        dbt::el::Value *s_b_50_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_50_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_50_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3799 [D] s_b_50_14: WriteRegBank 23:s_b_50_5 = s_b_50_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_50_5))),s_b_50_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_50_5))),s_b_50_13);
        /* execute.simd:3799 [F] s_b_50_15: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ucvtf(const aarch64_decode_a64_CVT_FP_I&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4376 [F] s_b_0_0=sym_39542_3_parameter_inst.sf (const) */
    /* execute.simd:4376 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4376 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4376 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4376 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4377 [F] s_b_1_0=sym_39542_3_parameter_inst.type (const) */
    /* execute.simd:4377 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4377 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4377 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4377 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_3, b_4, b_5, b_6, b_8, b_9, b_10,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4384 [F] s_b_3_0=sym_39542_3_parameter_inst.sf (const) */
    /* execute.simd:4384 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4384 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4384 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4384 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_2 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4379 [F] s_b_4_0=sym_39542_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [F] s_b_4_8=sym_39542_3_parameter_inst.rd (const) */
    /* execute.simd:4379 [D] s_b_4_9 = (u32)s_b_4_7 */
    auto s_b_4_9 = emitter.truncate(s_b_4_7, emitter.context().types().u32());
    /* execute.simd:4379 [D] s_b_4_10 = (f32)s_b_4_9 */
    auto s_b_4_10 = emitter.convert(s_b_4_9, emitter.context().types().f32());
    /* execute.simd:6210 [D] s_b_4_11: WriteRegBank 9:s_b_4_8 = s_b_4_10 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_10,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_10);
    /* execute.simd:6211 [F] s_b_4_12 = constant u32 0 (const) */
    /* execute.simd:6211 [F] s_b_4_13: WriteRegBank 10:s_b_4_8 = s_b_4_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6212 [F] s_b_4_14 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_4_15: WriteRegBank 3:s_b_4_8 = s_b_4_14 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_16: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4380 [F] s_b_5_0=sym_39542_3_parameter_inst.type (const) */
    /* execute.simd:4380 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4380 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4380 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4380 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_5,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4382 [F] s_b_6_0=sym_39542_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2646 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_6_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_6_5 = ReadRegBank 1:s_b_6_0 (u32) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_6_6: Select s_b_6_3 ? s_b_6_4 : s_b_6_5 */
    dbt::el::Value *s_b_6_6;
    s_b_6_6 = (s_b_6_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_6_5);
    /* execute.a64:2659 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_8=sym_39542_3_parameter_inst.rd (const) */
    /* execute.simd:4382 [D] s_b_6_9 = (u32)s_b_6_7 */
    auto s_b_6_9 = emitter.truncate(s_b_6_7, emitter.context().types().u32());
    /* execute.simd:4382 [D] s_b_6_10 = (f64)s_b_6_9 */
    auto s_b_6_10 = emitter.convert(s_b_6_9, emitter.context().types().f64());
    /* execute.simd:6218 [D] s_b_6_11: WriteRegBank 11:s_b_6_8 = s_b_6_10 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_10,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_10);
    /* execute.simd:6219 [F] s_b_6_12 = constant u64 0 (const) */
    /* execute.simd:6219 [F] s_b_6_13: WriteRegBank 3:s_b_6_8 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4385 [F] s_b_7_0=sym_39542_3_parameter_inst.type (const) */
    /* execute.simd:4385 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4385 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4385 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4385 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4387 [F] s_b_8_0=sym_39542_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [F] s_b_8_7=sym_39542_3_parameter_inst.rd (const) */
    /* execute.simd:4387 [D] s_b_8_8 = (u64)s_b_8_6 */
    auto s_b_8_8 = (dbt::el::Value *)s_b_8_6;
    /* execute.simd:4387 [D] s_b_8_9 = (f32)s_b_8_8 */
    auto s_b_8_9 = emitter.convert(s_b_8_8, emitter.context().types().f32());
    /* execute.simd:6210 [D] s_b_8_10: WriteRegBank 9:s_b_8_7 = s_b_8_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_9,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_9);
    /* execute.simd:6211 [F] s_b_8_11 = constant u32 0 (const) */
    /* execute.simd:6211 [F] s_b_8_12: WriteRegBank 10:s_b_8_7 = s_b_8_11 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6212 [F] s_b_8_13 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_8_14: WriteRegBank 3:s_b_8_7 = s_b_8_13 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4388 [F] s_b_9_0=sym_39542_3_parameter_inst.type (const) */
    /* execute.simd:4388 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4388 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4388 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4388 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_2 (const) */
    if (s_b_9_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_9,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4390 [F] s_b_10_0=sym_39542_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2651 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_10_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_10_5 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_10_6: Select s_b_10_3 ? s_b_10_4 : s_b_10_5 */
    dbt::el::Value *s_b_10_6;
    s_b_10_6 = (s_b_10_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_10_5);
    /* ???:4294967295 [F] s_b_10_7=sym_39542_3_parameter_inst.rd (const) */
    /* execute.simd:4390 [D] s_b_10_8 = (u64)s_b_10_6 */
    auto s_b_10_8 = (dbt::el::Value *)s_b_10_6;
    /* execute.simd:4390 [D] s_b_10_9 = (f64)s_b_10_8 */
    auto s_b_10_9 = emitter.convert(s_b_10_8, emitter.context().types().f64());
    /* execute.simd:6218 [D] s_b_10_10: WriteRegBank 11:s_b_10_7 = s_b_10_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_9,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_9);
    /* execute.simd:6219 [F] s_b_10_11 = constant u64 0 (const) */
    /* execute.simd:6219 [F] s_b_10_12: WriteRegBank 3:s_b_10_7 = s_b_10_11 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_10_13: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_umulh(const aarch64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_149658_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2422 [F] s_b_0_0=sym_40130_3_parameter_inst.rn (const) */
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
    /* execute.a64:2423 [F] s_b_0_7=sym_40130_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_0_8 = (u32)s_b_0_7 (const) */
    /* execute.a64:2651 [F] s_b_0_9 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_0_10 = s_b_0_8==s_b_0_9 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_0_11 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_0_12 = ReadRegBank 0:s_b_0_7 (u64) */
    auto s_b_0_12 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_0_12,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_0_13: Select s_b_0_10 ? s_b_0_11 : s_b_0_12 */
    dbt::el::Value *s_b_0_13;
    s_b_0_13 = (s_b_0_10) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_0_12);
    /* execute.a64:2425 [D] s_b_0_14 = __builtin_umulh */
    auto s_b_0_14 = emitter.umulh(s_b_0_6, s_b_0_13);
    /* execute.a64:2691 [F] s_b_0_15=sym_40130_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_0_16: sym_149658_3_parameter_value = s_b_0_14, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_149658_3_parameter_value, s_b_0_14);
    /* execute.a64:2682 [F] s_b_0_17 = (u32)s_b_0_15 (const) */
    /* execute.a64:2682 [F] s_b_0_18 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_0_19 = s_b_0_17==s_b_0_18 (const) */
    uint8_t s_b_0_19 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_0_20: If s_b_0_19: Jump b_1 else b_2 (const) */
    if (s_b_0_19) 
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
    /* execute.a64:2684 [F] s_b_2_0=sym_40130_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_2_1 = sym_149658_3_parameter_value uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_149658_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_uzp2(const aarch64_decode_a64_SIMD_PERMUTE&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5079 [F] s_b_0_0=sym_46065_3_parameter_inst.arrangement (const) */
    /* execute.simd:5080 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5097 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5122 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5135 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5152 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5163 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5176 [F] s_b_0_7 = constant s32 6 (const) */
    /* execute.simd:5079 [F] s_b_0_8: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    case (int32_t)6ULL:
      goto fixed_block_b_8;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_0, b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:5081 [F] s_b_2_0=sym_46065_3_parameter_inst.rn (const) */
    /* execute.simd:5081 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5082 [F] s_b_2_2=sym_46065_3_parameter_inst.rm (const) */
    /* execute.simd:5082 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:5085 [F] s_b_2_5 = constant s32 1 (const) */
    /* execute.simd:5085 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5085 [F] s_b_2_7 = constant s32 0 (const) */
    /* execute.simd:5085 [D] s_b_2_8 = s_b_2_4[s_b_2_7] <= s_b_2_6 */
    auto s_b_2_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_2_6);
    /* execute.simd:5086 [F] s_b_2_9 = constant s32 3 (const) */
    /* execute.simd:5086 [D] s_b_2_1[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5086 [F] s_b_2_11 = constant s32 1 (const) */
    /* execute.simd:5086 [D] s_b_2_12 = s_b_2_8[s_b_2_11] <= s_b_2_10 */
    auto s_b_2_12 = emitter.vector_insert(s_b_2_8, emitter.const_s32((int32_t)1ULL), s_b_2_10);
    /* execute.simd:5087 [F] s_b_2_13 = constant s32 5 (const) */
    /* execute.simd:5087 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5087 [F] s_b_2_15 = constant s32 2 (const) */
    /* execute.simd:5087 [D] s_b_2_16 = s_b_2_12[s_b_2_15] <= s_b_2_14 */
    auto s_b_2_16 = emitter.vector_insert(s_b_2_12, emitter.const_s32((int32_t)2ULL), s_b_2_14);
    /* execute.simd:5088 [F] s_b_2_17 = constant s32 7 (const) */
    /* execute.simd:5088 [D] s_b_2_1[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5088 [F] s_b_2_19 = constant s32 3 (const) */
    /* execute.simd:5088 [D] s_b_2_20 = s_b_2_16[s_b_2_19] <= s_b_2_18 */
    auto s_b_2_20 = emitter.vector_insert(s_b_2_16, emitter.const_s32((int32_t)3ULL), s_b_2_18);
    /* execute.simd:5089 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:5089 [D] s_b_2_3[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5089 [F] s_b_2_23 = constant s32 4 (const) */
    /* execute.simd:5089 [D] s_b_2_24 = s_b_2_20[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_20, emitter.const_s32((int32_t)4ULL), s_b_2_22);
    /* execute.simd:5090 [F] s_b_2_25 = constant s32 3 (const) */
    /* execute.simd:5090 [D] s_b_2_3[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5090 [F] s_b_2_27 = constant s32 5 (const) */
    /* execute.simd:5090 [D] s_b_2_28 = s_b_2_24[s_b_2_27] <= s_b_2_26 */
    auto s_b_2_28 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)5ULL), s_b_2_26);
    /* execute.simd:5091 [F] s_b_2_29 = constant s32 5 (const) */
    /* execute.simd:5091 [D] s_b_2_3[s_b_2_29] */
    auto s_b_2_30 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5091 [F] s_b_2_31 = constant s32 6 (const) */
    /* execute.simd:5091 [D] s_b_2_32 = s_b_2_28[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_28, emitter.const_s32((int32_t)6ULL), s_b_2_30);
    /* execute.simd:5092 [F] s_b_2_33 = constant s32 7 (const) */
    /* execute.simd:5092 [D] s_b_2_3[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5092 [F] s_b_2_35 = constant s32 7 (const) */
    /* execute.simd:5092 [D] s_b_2_36 = s_b_2_32[s_b_2_35] <= s_b_2_34 */
    auto s_b_2_36 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)7ULL), s_b_2_34);
    /* execute.simd:5094 [F] s_b_2_37=sym_46065_3_parameter_inst.rd (const) */
    /* execute.simd:5094 [D] s_b_2_38: WriteRegBank 16:s_b_2_37 = s_b_2_36 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_36,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_36);
    /* execute.simd:0 [F] s_b_2_39: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5098 [F] s_b_3_0=sym_46065_3_parameter_inst.rn (const) */
    /* execute.simd:5098 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5099 [F] s_b_3_2=sym_46065_3_parameter_inst.rm (const) */
    /* execute.simd:5099 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:5102 [F] s_b_3_5 = constant s32 1 (const) */
    /* execute.simd:5102 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5102 [F] s_b_3_7 = constant s32 0 (const) */
    /* execute.simd:5102 [D] s_b_3_8 = s_b_3_4[s_b_3_7] <= s_b_3_6 */
    auto s_b_3_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_3_6);
    /* execute.simd:5103 [F] s_b_3_9 = constant s32 3 (const) */
    /* execute.simd:5103 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5103 [F] s_b_3_11 = constant s32 1 (const) */
    /* execute.simd:5103 [D] s_b_3_12 = s_b_3_8[s_b_3_11] <= s_b_3_10 */
    auto s_b_3_12 = emitter.vector_insert(s_b_3_8, emitter.const_s32((int32_t)1ULL), s_b_3_10);
    /* execute.simd:5104 [F] s_b_3_13 = constant s32 5 (const) */
    /* execute.simd:5104 [D] s_b_3_1[s_b_3_13] */
    auto s_b_3_14 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5104 [F] s_b_3_15 = constant s32 2 (const) */
    /* execute.simd:5104 [D] s_b_3_16 = s_b_3_12[s_b_3_15] <= s_b_3_14 */
    auto s_b_3_16 = emitter.vector_insert(s_b_3_12, emitter.const_s32((int32_t)2ULL), s_b_3_14);
    /* execute.simd:5105 [F] s_b_3_17 = constant s32 7 (const) */
    /* execute.simd:5105 [D] s_b_3_1[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5105 [F] s_b_3_19 = constant s32 3 (const) */
    /* execute.simd:5105 [D] s_b_3_20 = s_b_3_16[s_b_3_19] <= s_b_3_18 */
    auto s_b_3_20 = emitter.vector_insert(s_b_3_16, emitter.const_s32((int32_t)3ULL), s_b_3_18);
    /* execute.simd:5106 [F] s_b_3_21 = constant s32 9 (const) */
    /* execute.simd:5106 [D] s_b_3_1[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)9ULL));
    /* execute.simd:5106 [F] s_b_3_23 = constant s32 4 (const) */
    /* execute.simd:5106 [D] s_b_3_24 = s_b_3_20[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_20, emitter.const_s32((int32_t)4ULL), s_b_3_22);
    /* execute.simd:5107 [F] s_b_3_25 = constant s32 b (const) */
    /* execute.simd:5107 [D] s_b_3_1[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)11ULL));
    /* execute.simd:5107 [F] s_b_3_27 = constant s32 5 (const) */
    /* execute.simd:5107 [D] s_b_3_28 = s_b_3_24[s_b_3_27] <= s_b_3_26 */
    auto s_b_3_28 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)5ULL), s_b_3_26);
    /* execute.simd:5108 [F] s_b_3_29 = constant s32 d (const) */
    /* execute.simd:5108 [D] s_b_3_1[s_b_3_29] */
    auto s_b_3_30 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)13ULL));
    /* execute.simd:5108 [F] s_b_3_31 = constant s32 6 (const) */
    /* execute.simd:5108 [D] s_b_3_32 = s_b_3_28[s_b_3_31] <= s_b_3_30 */
    auto s_b_3_32 = emitter.vector_insert(s_b_3_28, emitter.const_s32((int32_t)6ULL), s_b_3_30);
    /* execute.simd:5109 [F] s_b_3_33 = constant s32 f (const) */
    /* execute.simd:5109 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)15ULL));
    /* execute.simd:5109 [F] s_b_3_35 = constant s32 7 (const) */
    /* execute.simd:5109 [D] s_b_3_36 = s_b_3_32[s_b_3_35] <= s_b_3_34 */
    auto s_b_3_36 = emitter.vector_insert(s_b_3_32, emitter.const_s32((int32_t)7ULL), s_b_3_34);
    /* execute.simd:5110 [F] s_b_3_37 = constant s32 1 (const) */
    /* execute.simd:5110 [D] s_b_3_3[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5110 [F] s_b_3_39 = constant s32 8 (const) */
    /* execute.simd:5110 [D] s_b_3_40 = s_b_3_36[s_b_3_39] <= s_b_3_38 */
    auto s_b_3_40 = emitter.vector_insert(s_b_3_36, emitter.const_s32((int32_t)8ULL), s_b_3_38);
    /* execute.simd:5111 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5111 [D] s_b_3_3[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5111 [F] s_b_3_43 = constant s32 9 (const) */
    /* execute.simd:5111 [D] s_b_3_44 = s_b_3_40[s_b_3_43] <= s_b_3_42 */
    auto s_b_3_44 = emitter.vector_insert(s_b_3_40, emitter.const_s32((int32_t)9ULL), s_b_3_42);
    /* execute.simd:5112 [F] s_b_3_45 = constant s32 5 (const) */
    /* execute.simd:5112 [D] s_b_3_3[s_b_3_45] */
    auto s_b_3_46 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5112 [F] s_b_3_47 = constant s32 a (const) */
    /* execute.simd:5112 [D] s_b_3_48 = s_b_3_44[s_b_3_47] <= s_b_3_46 */
    auto s_b_3_48 = emitter.vector_insert(s_b_3_44, emitter.const_s32((int32_t)10ULL), s_b_3_46);
    /* execute.simd:5113 [F] s_b_3_49 = constant s32 7 (const) */
    /* execute.simd:5113 [D] s_b_3_3[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5113 [F] s_b_3_51 = constant s32 b (const) */
    /* execute.simd:5113 [D] s_b_3_52 = s_b_3_48[s_b_3_51] <= s_b_3_50 */
    auto s_b_3_52 = emitter.vector_insert(s_b_3_48, emitter.const_s32((int32_t)11ULL), s_b_3_50);
    /* execute.simd:5114 [F] s_b_3_53 = constant s32 9 (const) */
    /* execute.simd:5114 [D] s_b_3_3[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)9ULL));
    /* execute.simd:5114 [F] s_b_3_55 = constant s32 c (const) */
    /* execute.simd:5114 [D] s_b_3_56 = s_b_3_52[s_b_3_55] <= s_b_3_54 */
    auto s_b_3_56 = emitter.vector_insert(s_b_3_52, emitter.const_s32((int32_t)12ULL), s_b_3_54);
    /* execute.simd:5115 [F] s_b_3_57 = constant s32 b (const) */
    /* execute.simd:5115 [D] s_b_3_3[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)11ULL));
    /* execute.simd:5115 [F] s_b_3_59 = constant s32 d (const) */
    /* execute.simd:5115 [D] s_b_3_60 = s_b_3_56[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_56, emitter.const_s32((int32_t)13ULL), s_b_3_58);
    /* execute.simd:5116 [F] s_b_3_61 = constant s32 d (const) */
    /* execute.simd:5116 [D] s_b_3_3[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)13ULL));
    /* execute.simd:5116 [F] s_b_3_63 = constant s32 e (const) */
    /* execute.simd:5116 [D] s_b_3_64 = s_b_3_60[s_b_3_63] <= s_b_3_62 */
    auto s_b_3_64 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)14ULL), s_b_3_62);
    /* execute.simd:5117 [F] s_b_3_65 = constant s32 f (const) */
    /* execute.simd:5117 [D] s_b_3_3[s_b_3_65] */
    auto s_b_3_66 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)15ULL));
    /* execute.simd:5117 [F] s_b_3_67 = constant s32 f (const) */
    /* execute.simd:5117 [D] s_b_3_68 = s_b_3_64[s_b_3_67] <= s_b_3_66 */
    auto s_b_3_68 = emitter.vector_insert(s_b_3_64, emitter.const_s32((int32_t)15ULL), s_b_3_66);
    /* execute.simd:5119 [F] s_b_3_69=sym_46065_3_parameter_inst.rd (const) */
    /* execute.simd:5119 [D] s_b_3_70: WriteRegBank 16:s_b_3_69 = s_b_3_68 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_68,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_68);
    /* execute.simd:0 [F] s_b_3_71: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5123 [F] s_b_4_0=sym_46065_3_parameter_inst.rn (const) */
    /* execute.simd:5123 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5124 [F] s_b_4_2=sym_46065_3_parameter_inst.rm (const) */
    /* execute.simd:5124 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5127 [F] s_b_4_5 = constant s32 1 (const) */
    /* execute.simd:5127 [D] s_b_4_1[s_b_4_5] */
    auto s_b_4_6 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5127 [F] s_b_4_7 = constant s32 0 (const) */
    /* execute.simd:5127 [D] s_b_4_8 = s_b_4_4[s_b_4_7] <= s_b_4_6 */
    auto s_b_4_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_4_6);
    /* execute.simd:5128 [F] s_b_4_9 = constant s32 3 (const) */
    /* execute.simd:5128 [D] s_b_4_1[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5128 [F] s_b_4_11 = constant s32 1 (const) */
    /* execute.simd:5128 [D] s_b_4_12 = s_b_4_8[s_b_4_11] <= s_b_4_10 */
    auto s_b_4_12 = emitter.vector_insert(s_b_4_8, emitter.const_s32((int32_t)1ULL), s_b_4_10);
    /* execute.simd:5129 [F] s_b_4_13 = constant s32 1 (const) */
    /* execute.simd:5129 [D] s_b_4_3[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5129 [F] s_b_4_15 = constant s32 2 (const) */
    /* execute.simd:5129 [D] s_b_4_16 = s_b_4_12[s_b_4_15] <= s_b_4_14 */
    auto s_b_4_16 = emitter.vector_insert(s_b_4_12, emitter.const_s32((int32_t)2ULL), s_b_4_14);
    /* execute.simd:5130 [F] s_b_4_17 = constant s32 3 (const) */
    /* execute.simd:5130 [D] s_b_4_3[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5130 [F] s_b_4_19 = constant s32 3 (const) */
    /* execute.simd:5130 [D] s_b_4_20 = s_b_4_16[s_b_4_19] <= s_b_4_18 */
    auto s_b_4_20 = emitter.vector_insert(s_b_4_16, emitter.const_s32((int32_t)3ULL), s_b_4_18);
    /* execute.simd:5132 [F] s_b_4_21=sym_46065_3_parameter_inst.rd (const) */
    /* execute.simd:5132 [D] s_b_4_22: WriteRegBank 18:s_b_4_21 = s_b_4_20 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_20,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_20);
    /* execute.simd:0 [F] s_b_4_23: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5136 [F] s_b_5_0=sym_46065_3_parameter_inst.rn (const) */
    /* execute.simd:5136 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5137 [F] s_b_5_2=sym_46065_3_parameter_inst.rm (const) */
    /* execute.simd:5137 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5140 [F] s_b_5_5 = constant s32 1 (const) */
    /* execute.simd:5140 [D] s_b_5_1[s_b_5_5] */
    auto s_b_5_6 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5140 [F] s_b_5_7 = constant s32 0 (const) */
    /* execute.simd:5140 [D] s_b_5_8 = s_b_5_4[s_b_5_7] <= s_b_5_6 */
    auto s_b_5_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_5_6);
    /* execute.simd:5141 [F] s_b_5_9 = constant s32 3 (const) */
    /* execute.simd:5141 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5141 [F] s_b_5_11 = constant s32 1 (const) */
    /* execute.simd:5141 [D] s_b_5_12 = s_b_5_8[s_b_5_11] <= s_b_5_10 */
    auto s_b_5_12 = emitter.vector_insert(s_b_5_8, emitter.const_s32((int32_t)1ULL), s_b_5_10);
    /* execute.simd:5142 [F] s_b_5_13 = constant s32 5 (const) */
    /* execute.simd:5142 [D] s_b_5_1[s_b_5_13] */
    auto s_b_5_14 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5142 [F] s_b_5_15 = constant s32 2 (const) */
    /* execute.simd:5142 [D] s_b_5_16 = s_b_5_12[s_b_5_15] <= s_b_5_14 */
    auto s_b_5_16 = emitter.vector_insert(s_b_5_12, emitter.const_s32((int32_t)2ULL), s_b_5_14);
    /* execute.simd:5143 [F] s_b_5_17 = constant s32 7 (const) */
    /* execute.simd:5143 [D] s_b_5_1[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5143 [F] s_b_5_19 = constant s32 3 (const) */
    /* execute.simd:5143 [D] s_b_5_20 = s_b_5_16[s_b_5_19] <= s_b_5_18 */
    auto s_b_5_20 = emitter.vector_insert(s_b_5_16, emitter.const_s32((int32_t)3ULL), s_b_5_18);
    /* execute.simd:5144 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5144 [D] s_b_5_3[s_b_5_21] */
    auto s_b_5_22 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5144 [F] s_b_5_23 = constant s32 4 (const) */
    /* execute.simd:5144 [D] s_b_5_24 = s_b_5_20[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_20, emitter.const_s32((int32_t)4ULL), s_b_5_22);
    /* execute.simd:5145 [F] s_b_5_25 = constant s32 3 (const) */
    /* execute.simd:5145 [D] s_b_5_3[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5145 [F] s_b_5_27 = constant s32 5 (const) */
    /* execute.simd:5145 [D] s_b_5_28 = s_b_5_24[s_b_5_27] <= s_b_5_26 */
    auto s_b_5_28 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)5ULL), s_b_5_26);
    /* execute.simd:5146 [F] s_b_5_29 = constant s32 5 (const) */
    /* execute.simd:5146 [D] s_b_5_3[s_b_5_29] */
    auto s_b_5_30 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5146 [F] s_b_5_31 = constant s32 6 (const) */
    /* execute.simd:5146 [D] s_b_5_32 = s_b_5_28[s_b_5_31] <= s_b_5_30 */
    auto s_b_5_32 = emitter.vector_insert(s_b_5_28, emitter.const_s32((int32_t)6ULL), s_b_5_30);
    /* execute.simd:5147 [F] s_b_5_33 = constant s32 7 (const) */
    /* execute.simd:5147 [D] s_b_5_3[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5147 [F] s_b_5_35 = constant s32 7 (const) */
    /* execute.simd:5147 [D] s_b_5_36 = s_b_5_32[s_b_5_35] <= s_b_5_34 */
    auto s_b_5_36 = emitter.vector_insert(s_b_5_32, emitter.const_s32((int32_t)7ULL), s_b_5_34);
    /* execute.simd:5149 [F] s_b_5_37=sym_46065_3_parameter_inst.rd (const) */
    /* execute.simd:5149 [D] s_b_5_38: WriteRegBank 18:s_b_5_37 = s_b_5_36 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_36,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_36);
    /* execute.simd:0 [F] s_b_5_39: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5153 [F] s_b_6_0=sym_46065_3_parameter_inst.rn (const) */
    /* execute.simd:5153 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5154 [F] s_b_6_2=sym_46065_3_parameter_inst.rm (const) */
    /* execute.simd:5154 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5157 [F] s_b_6_5 = constant s32 1 (const) */
    /* execute.simd:5157 [D] s_b_6_1[s_b_6_5] */
    auto s_b_6_6 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5157 [F] s_b_6_7 = constant s32 0 (const) */
    /* execute.simd:5157 [D] s_b_6_8 = s_b_6_4[s_b_6_7] <= s_b_6_6 */
    auto s_b_6_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_6_6);
    /* execute.simd:5158 [F] s_b_6_9 = constant s32 1 (const) */
    /* execute.simd:5158 [D] s_b_6_3[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5158 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:5158 [D] s_b_6_12 = s_b_6_8[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_8, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:5160 [F] s_b_6_13=sym_46065_3_parameter_inst.rd (const) */
    /* execute.simd:5160 [D] s_b_6_14: WriteRegBank 20:s_b_6_13 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12);
    /* execute.simd:0 [F] s_b_6_15: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:5164 [F] s_b_7_0=sym_46065_3_parameter_inst.rn (const) */
    /* execute.simd:5164 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5165 [F] s_b_7_2=sym_46065_3_parameter_inst.rm (const) */
    /* execute.simd:5165 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5168 [F] s_b_7_5 = constant s32 1 (const) */
    /* execute.simd:5168 [D] s_b_7_1[s_b_7_5] */
    auto s_b_7_6 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5168 [F] s_b_7_7 = constant s32 0 (const) */
    /* execute.simd:5168 [D] s_b_7_8 = s_b_7_4[s_b_7_7] <= s_b_7_6 */
    auto s_b_7_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_7_6);
    /* execute.simd:5169 [F] s_b_7_9 = constant s32 3 (const) */
    /* execute.simd:5169 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5169 [F] s_b_7_11 = constant s32 1 (const) */
    /* execute.simd:5169 [D] s_b_7_12 = s_b_7_8[s_b_7_11] <= s_b_7_10 */
    auto s_b_7_12 = emitter.vector_insert(s_b_7_8, emitter.const_s32((int32_t)1ULL), s_b_7_10);
    /* execute.simd:5170 [F] s_b_7_13 = constant s32 1 (const) */
    /* execute.simd:5170 [D] s_b_7_3[s_b_7_13] */
    auto s_b_7_14 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5170 [F] s_b_7_15 = constant s32 2 (const) */
    /* execute.simd:5170 [D] s_b_7_16 = s_b_7_12[s_b_7_15] <= s_b_7_14 */
    auto s_b_7_16 = emitter.vector_insert(s_b_7_12, emitter.const_s32((int32_t)2ULL), s_b_7_14);
    /* execute.simd:5171 [F] s_b_7_17 = constant s32 3 (const) */
    /* execute.simd:5171 [D] s_b_7_3[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5171 [F] s_b_7_19 = constant s32 3 (const) */
    /* execute.simd:5171 [D] s_b_7_20 = s_b_7_16[s_b_7_19] <= s_b_7_18 */
    auto s_b_7_20 = emitter.vector_insert(s_b_7_16, emitter.const_s32((int32_t)3ULL), s_b_7_18);
    /* execute.simd:5173 [F] s_b_7_21=sym_46065_3_parameter_inst.rd (const) */
    /* execute.simd:5173 [D] s_b_7_22: WriteRegBank 20:s_b_7_21 = s_b_7_20 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_20,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_20);
    /* execute.simd:0 [F] s_b_7_23: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:5177 [F] s_b_8_0=sym_46065_3_parameter_inst.rn (const) */
    /* execute.simd:5177 [D] s_b_8_1 = ReadRegBank 21:s_b_8_0 (v2u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* execute.simd:5178 [F] s_b_8_2=sym_46065_3_parameter_inst.rm (const) */
    /* execute.simd:5178 [D] s_b_8_3 = ReadRegBank 21:s_b_8_2 (v2u64) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_4 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5181 [F] s_b_8_5 = constant s32 1 (const) */
    /* execute.simd:5181 [D] s_b_8_1[s_b_8_5] */
    auto s_b_8_6 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5181 [F] s_b_8_7 = constant s32 0 (const) */
    /* execute.simd:5181 [D] s_b_8_8 = s_b_8_4[s_b_8_7] <= s_b_8_6 */
    auto s_b_8_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_8_6);
    /* execute.simd:5182 [F] s_b_8_9 = constant s32 3 (const) */
    /* execute.simd:5182 [D] s_b_8_3[s_b_8_9] */
    auto s_b_8_10 = emitter.vector_extract(s_b_8_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5182 [F] s_b_8_11 = constant s32 1 (const) */
    /* execute.simd:5182 [D] s_b_8_12 = s_b_8_8[s_b_8_11] <= s_b_8_10 */
    auto s_b_8_12 = emitter.vector_insert(s_b_8_8, emitter.const_s32((int32_t)1ULL), s_b_8_10);
    /* execute.simd:5184 [F] s_b_8_13=sym_46065_3_parameter_inst.rd (const) */
    /* execute.simd:5184 [D] s_b_8_14: WriteRegBank 21:s_b_8_13 = s_b_8_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_12);
    /* execute.simd:0 [F] s_b_8_15: Jump b_1 (const) */
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
template class aarch64_jit2<true>;
template class aarch64_jit2<false>;
