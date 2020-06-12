#include <arm64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::arm64;
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_addi(const arm64_decode_a64_ADD_SUB_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_49363_3_parameter_imm;
  auto DV_sym_49622_1__R_s_b_32_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_49378_1__R_s_b_0_5;
  auto DV_sym_49395_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49437_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_49586_1__R_s_b_30_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49460_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49534_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49513_1__R_s_b_11_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3622_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_3617_0_imm;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:18 [F] s_b_0_0=sym_3611_3_parameter_inst.imm12 (const) */
    /* execute.a64:18 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:18 [F] s_b_0_2=sym_3611_3_parameter_inst.shift (const) */
    /* execute.a64:18 [F] s_b_0_3: sym_49363_3_parameter_imm = s_b_0_1 (const), dominates: s_b_8_0 s_b_7_0  */
    CV_sym_49363_3_parameter_imm = ((uint32_t)insn.imm12);
    /* execute.a64:2803 [F] s_b_0_4 = constant s32 0 (const) */
    /* execute.a64:2806 [F] s_b_0_5 = constant s32 1 (const) */
    /* execute.a64:2802 [F] s_b_0_6: Switch s_b_0_2: < <todo> > def b_6 (const) -> b_8, b_6, b_7,  */
    switch (insn.shift) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
      break;
    default:
      goto fixed_block_b_6;
    }
  }
  /* b_20,  */
  fixed_block_b_1: 
  {
    /* execute.a64:22 [F] s_b_1_0=sym_3611_3_parameter_inst.sf (const) */
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
    /* execute.a64:28 [F] s_b_3_0=sym_3611_3_parameter_inst.sf (const) */
    /* execute.a64:28 [D] s_b_3_1 = sym_3622_0_op1 uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_3622_0_op1, emitter.context().types().u64());
    /* execute.a64:28 [F] s_b_3_2 = sym_3617_0_imm (const) uint64_t */
    uint64_t s_b_3_2 = CV_sym_3617_0_imm;
    /* execute.a64:28 [D] s_b_3_3 = s_b_3_1+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_1, emitter.const_u64(s_b_3_2));
    /* execute.a64:28 [D] s_b_3_4: sym_49395_3_parameter_value = s_b_3_3, dominates: s_b_10_0 s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_49395_3_parameter_value, s_b_3_3);
    /* execute.a64:2787 [F] s_b_3_5 = !s_b_3_0 (const) */
    uint8_t s_b_3_5 = !insn.sf;
    /* execute.a64:2787 [F] s_b_3_6: If s_b_3_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:23 [F] s_b_4_0=sym_3611_3_parameter_inst.rd (const) */
    /* execute.a64:23 [D] s_b_4_1 = sym_3622_0_op1 uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_3622_0_op1, emitter.context().types().u64());
    /* execute.a64:23 [D] s_b_4_2 = (u32)s_b_4_1 */
    auto s_b_4_2 = emitter.truncate(s_b_4_1, emitter.context().types().u32());
    /* execute.a64:23 [F] s_b_4_3 = sym_3617_0_imm (const) uint64_t */
    uint64_t s_b_4_3 = CV_sym_3617_0_imm;
    /* execute.a64:23 [F] s_b_4_4 = (u32)s_b_4_3 (const) */
    /* execute.a64:23 [F] s_b_4_5 = constant u8 0 (const) */
    /* execute.a64:23 [D] s_b_4_6 = __builtin_adc32_flags */
    auto s_b_4_6 = emitter.adcf(s_b_4_2, emitter.const_u32(((uint32_t)s_b_4_3)), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:23 [D] s_b_4_7: sym_49437_3_parameter_value = s_b_4_6, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_49437_3_parameter_value, s_b_4_6);
    /* execute.a64:2715 [F] s_b_4_8 = (u32)s_b_4_0 (const) */
    /* execute.a64:2715 [F] s_b_4_9 = constant u32 1f (const) */
    /* execute.a64:2715 [F] s_b_4_10 = s_b_4_8==s_b_4_9 (const) */
    uint8_t s_b_4_10 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2715 [F] s_b_4_11: If s_b_4_10: Jump b_2 else b_14 (const) */
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
    /* execute.a64:25 [F] s_b_5_0=sym_3611_3_parameter_inst.rd (const) */
    /* execute.a64:25 [D] s_b_5_1 = sym_3622_0_op1 uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_3622_0_op1, emitter.context().types().u64());
    /* execute.a64:25 [F] s_b_5_2 = sym_3617_0_imm (const) uint64_t */
    uint64_t s_b_5_2 = CV_sym_3617_0_imm;
    /* execute.a64:25 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.a64:25 [D] s_b_5_4 = __builtin_adc64_flags */
    auto s_b_5_4 = emitter.adcf(s_b_5_1, emitter.const_u64(s_b_5_2), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:25 [D] s_b_5_5: sym_49460_3_parameter_value = s_b_5_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_49460_3_parameter_value, s_b_5_4);
    /* execute.a64:2723 [F] s_b_5_6 = (u32)s_b_5_0 (const) */
    /* execute.a64:2723 [F] s_b_5_7 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_5_8 = s_b_5_6==s_b_5_7 (const) */
    uint8_t s_b_5_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_5_9: If s_b_5_8: Jump b_2 else b_15 (const) */
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
    /* execute.a64:2810 [F] s_b_6_0 = constant u64 0 (const) */
    /* execute.a64:2810 [F] s_b_6_1: sym_49378_1__R_s_b_0_5 = s_b_6_0 (const), dominates: s_b_9_0  */
    CV_sym_49378_1__R_s_b_0_5 = (uint64_t)0ULL;
    /* execute.a64:2810 [F] s_b_6_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2804 [F] s_b_7_0 = sym_49363_3_parameter_imm (const) uint32_t */
    uint32_t s_b_7_0 = CV_sym_49363_3_parameter_imm;
    /* execute.a64:2804 [F] s_b_7_1 = (u64)s_b_7_0 (const) */
    /* execute.a64:2804 [F] s_b_7_2: sym_49378_1__R_s_b_0_5 = s_b_7_1 (const), dominates: s_b_9_0  */
    CV_sym_49378_1__R_s_b_0_5 = ((uint64_t)s_b_7_0);
    /* execute.a64:2804 [F] s_b_7_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2807 [F] s_b_8_0 = sym_49363_3_parameter_imm (const) uint32_t */
    uint32_t s_b_8_0 = CV_sym_49363_3_parameter_imm;
    /* execute.a64:2807 [F] s_b_8_1 = constant u32 c (const) */
    /* execute.a64:2807 [F] s_b_8_2 = s_b_8_0<<s_b_8_1 (const) */
    uint32_t s_b_8_2 = ((uint32_t)(s_b_8_0 << (uint32_t)12ULL));
    /* execute.a64:2807 [F] s_b_8_3 = (u64)s_b_8_2 (const) */
    /* execute.a64:2807 [F] s_b_8_4: sym_49378_1__R_s_b_0_5 = s_b_8_3 (const), dominates: s_b_9_0  */
    CV_sym_49378_1__R_s_b_0_5 = ((uint64_t)s_b_8_2);
    /* execute.a64:2807 [F] s_b_8_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6, b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:18 [F] s_b_9_0 = sym_49378_1__R_s_b_0_5 (const) uint64_t */
    uint64_t s_b_9_0 = CV_sym_49378_1__R_s_b_0_5;
    /* execute.a64:18 [F] s_b_9_1: sym_3617_0_imm = s_b_9_0 (const), dominates: s_b_4_3 s_b_5_2 s_b_3_2  */
    CV_sym_3617_0_imm = s_b_9_0;
    /* execute.a64:19 [F] s_b_9_2=sym_3611_3_parameter_inst.sf (const) */
    /* execute.a64:2770 [F] s_b_9_3: If s_b_9_2: Jump b_16 else b_17 (const) */
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
    /* execute.a64:2788 [D] s_b_10_0 = sym_49395_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_49395_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2788 [F] s_b_10_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_10_2 = s_b_10_0&s_b_10_1 */
    auto s_b_10_2 = emitter.bitwise_and(s_b_10_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2788 [D] s_b_10_3: sym_49395_3_parameter_value = s_b_10_2, dominates: s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_49395_3_parameter_value, s_b_10_2);
    /* execute.a64:2788 [F] s_b_10_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2791 [F] s_b_11_0=sym_3611_3_parameter_inst.rd (const) */
    /* execute.a64:2791 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2791 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2791 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2791 [F] s_b_11_4: If s_b_11_3: Jump b_12 else b_13 (const) */
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
    /* execute.a64:2792 [D] s_b_12_0 = sym_49395_3_parameter_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_49395_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2792 [D] s_b_12_1: sym_49534_3_parameter_value = s_b_12_0, dominates: s_b_21_0 s_b_22_0 s_b_23_0  */
    emitter.store_local(DV_sym_49534_3_parameter_value, s_b_12_0);
    /* execute.a64:2755 [F] s_b_12_2 = constant u32 1 (const) */
    /* execute.a64:2755 [F] s_b_12_3 = __builtin_get_feature */
    uint32_t s_b_12_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2755 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2755 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(s_b_12_3 == (uint32_t)0ULL));
    /* execute.a64:2755 [F] s_b_12_6: If s_b_12_5: Jump b_21 else b_34 (const) */
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
    /* execute.a64:2794 [F] s_b_13_0=sym_3611_3_parameter_inst.rd (const) */
    /* execute.a64:2794 [D] s_b_13_1 = sym_49395_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_49395_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1);
    /* execute.a64:2794 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2717 [F] s_b_14_0=sym_3611_3_parameter_inst.rd (const) */
    /* execute.a64:2717 [D] s_b_14_1 = sym_49437_3_parameter_value uint32_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_49437_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2717 [D] s_b_14_2 = (u64)s_b_14_1 */
    auto s_b_14_2 = emitter.zx(s_b_14_1, emitter.context().types().u64());
    /* execute.a64:2717 [D] s_b_14_3: WriteRegBank 0:s_b_14_0 = s_b_14_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2725 [F] s_b_15_0=sym_3611_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [D] s_b_15_1 = sym_49460_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_49460_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1);
    /* execute.a64:0 [F] s_b_15_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2771 [F] s_b_16_0=sym_3611_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2771 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_16_4: If s_b_16_3: Jump b_24 else b_18 (const) */
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
    /* execute.a64:2777 [F] s_b_17_0=sym_3611_3_parameter_inst.rn (const) */
    /* execute.a64:2777 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
    /* execute.a64:2777 [F] s_b_17_2 = constant u32 1f (const) */
    /* execute.a64:2777 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2777 [F] s_b_17_4: If s_b_17_3: Jump b_29 else b_19 (const) */
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
    /* execute.a64:2774 [F] s_b_18_0=sym_3611_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.a64:2774 [D] s_b_18_2: sym_49513_1__R_s_b_11_6 = s_b_18_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_49513_1__R_s_b_11_6, s_b_18_1);
    /* execute.a64:2774 [F] s_b_18_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_17,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2780 [F] s_b_19_0=sym_3611_3_parameter_inst.rn (const) */
    /* execute.a64:2780 [D] s_b_19_1 = ReadRegBank 1:s_b_19_0 (u32) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1,emitter.const_u8(4));
    }
    /* execute.a64:2780 [D] s_b_19_2 = (u64)s_b_19_1 */
    auto s_b_19_2 = emitter.zx(s_b_19_1, emitter.context().types().u64());
    /* execute.a64:2780 [D] s_b_19_3: sym_49513_1__R_s_b_11_6 = s_b_19_2, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_49513_1__R_s_b_11_6, s_b_19_2);
    /* execute.a64:2780 [F] s_b_19_4: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_18, b_19, b_28, b_33,  */
  fixed_block_b_20: 
  {
    /* execute.a64:19 [D] s_b_20_0 = sym_49513_1__R_s_b_11_6 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_49513_1__R_s_b_11_6, emitter.context().types().u64());
    /* execute.a64:19 [D] s_b_20_1: sym_3622_0_op1 = s_b_20_0, dominates: s_b_4_1 s_b_5_1 s_b_3_1  */
    emitter.store_local(DV_sym_3622_0_op1, s_b_20_0);
    /* execute.a64:21 [F] s_b_20_2=sym_3611_3_parameter_inst.S (const) */
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
    /* execute.a64:2756 [D] s_b_21_0 = sym_49534_3_parameter_value uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_49534_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_21_1: WriteReg 20 = s_b_21_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_21_0);
    /* execute.a64:2756 [F] s_b_21_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_34,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2759 [D] s_b_22_0 = sym_49534_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_49534_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2759 [D] s_b_22_1: WriteReg 20 = s_b_22_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_22_0);
    /* execute.a64:2759 [F] s_b_22_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_34,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2761 [D] s_b_23_0 = sym_49534_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_49534_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2761 [D] s_b_23_1: WriteReg 21 = s_b_23_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_23_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_23_0);
    /* execute.a64:2761 [F] s_b_23_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_16,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2742 [F] s_b_24_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_24_1 = __builtin_get_feature */
    uint32_t s_b_24_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_24_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(s_b_24_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_24_4: If s_b_24_3: Jump b_25 else b_35 (const) */
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
    /* execute.a64:2743 [D] s_b_25_0 = ReadReg 20 (u64) */
    auto s_b_25_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_25_1: sym_49586_1__R_s_b_30_0 = s_b_25_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_49586_1__R_s_b_30_0, s_b_25_0);
    /* execute.a64:2743 [F] s_b_25_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_35,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2746 [D] s_b_26_0 = ReadReg 20 (u64) */
    auto s_b_26_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_26_1: sym_49586_1__R_s_b_30_0 = s_b_26_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_49586_1__R_s_b_30_0, s_b_26_0);
    /* execute.a64:2746 [F] s_b_26_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_35,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2748 [D] s_b_27_0 = ReadReg 21 (u64) */
    auto s_b_27_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_27_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_27_1: sym_49586_1__R_s_b_30_0 = s_b_27_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_49586_1__R_s_b_30_0, s_b_27_0);
    /* execute.a64:2748 [F] s_b_27_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_25, b_26, b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2772 [D] s_b_28_0 = sym_49586_1__R_s_b_30_0 uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_49586_1__R_s_b_30_0, emitter.context().types().u64());
    /* execute.a64:2772 [D] s_b_28_1: sym_49513_1__R_s_b_11_6 = s_b_28_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_49513_1__R_s_b_11_6, s_b_28_0);
    /* execute.a64:2772 [F] s_b_28_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_17,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2742 [F] s_b_29_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_29_1 = __builtin_get_feature */
    uint32_t s_b_29_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_29_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(s_b_29_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_29_4: If s_b_29_3: Jump b_30 else b_36 (const) */
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
    /* execute.a64:2743 [D] s_b_30_0 = ReadReg 20 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_30_1: sym_49622_1__R_s_b_32_0 = s_b_30_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_49622_1__R_s_b_32_0, s_b_30_0);
    /* execute.a64:2743 [F] s_b_30_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_36,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2746 [D] s_b_31_0 = ReadReg 20 (u64) */
    auto s_b_31_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_31_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_31_1: sym_49622_1__R_s_b_32_0 = s_b_31_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_49622_1__R_s_b_32_0, s_b_31_0);
    /* execute.a64:2746 [F] s_b_31_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_36,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2748 [D] s_b_32_0 = ReadReg 21 (u64) */
    auto s_b_32_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_32_1: sym_49622_1__R_s_b_32_0 = s_b_32_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_49622_1__R_s_b_32_0, s_b_32_0);
    /* execute.a64:2748 [F] s_b_32_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_30, b_31, b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2778 [D] s_b_33_0 = sym_49622_1__R_s_b_32_0 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_49622_1__R_s_b_32_0, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_33_1 = (u32)s_b_33_0 */
    auto s_b_33_1 = emitter.truncate(s_b_33_0, emitter.context().types().u32());
    /* execute.a64:2778 [D] s_b_33_2 = (u64)s_b_33_1 */
    auto s_b_33_2 = emitter.zx(s_b_33_1, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_33_3: sym_49513_1__R_s_b_11_6 = s_b_33_2, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_49513_1__R_s_b_11_6, s_b_33_2);
    /* execute.a64:2778 [F] s_b_33_4: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_12,  */
  fixed_block_b_34: 
  {
    /* execute.a64:3053 [F] s_b_34_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_34_1 = __builtin_get_feature */
    uint32_t s_b_34_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_34_2 = (u8)s_b_34_1 (const) */
    /* execute.a64:2758 [F] s_b_34_3 = (u32)s_b_34_2 (const) */
    /* execute.a64:2758 [F] s_b_34_4 = constant u32 0 (const) */
    /* execute.a64:2758 [F] s_b_34_5 = s_b_34_3==s_b_34_4 (const) */
    uint8_t s_b_34_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_34_1)) == (uint32_t)0ULL));
    /* execute.a64:2758 [F] s_b_34_6: If s_b_34_5: Jump b_22 else b_23 (const) */
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
    /* execute.a64:3053 [F] s_b_35_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_35_1 = __builtin_get_feature */
    uint32_t s_b_35_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_35_2 = (u8)s_b_35_1 (const) */
    /* execute.a64:2745 [F] s_b_35_3 = (u32)s_b_35_2 (const) */
    /* execute.a64:2745 [F] s_b_35_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_35_5 = s_b_35_3==s_b_35_4 (const) */
    uint8_t s_b_35_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_35_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_35_6: If s_b_35_5: Jump b_26 else b_27 (const) */
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
    /* execute.a64:3053 [F] s_b_36_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_36_1 = __builtin_get_feature */
    uint32_t s_b_36_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_36_2 = (u8)s_b_36_1 (const) */
    /* execute.a64:2745 [F] s_b_36_3 = (u32)s_b_36_2 (const) */
    /* execute.a64:2745 [F] s_b_36_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_36_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_36_6: If s_b_36_5: Jump b_31 else b_32 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_asrv(const arm64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_51651_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51818_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_5906_0_amount = emitter.alloc_local(emitter.context().types().u8(), false);
  int64_t CV_sym_51684_1_temporary_value;
  auto DV_sym_51684_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_51696_1_temporary_value;
  auto DV_sym_51696_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_51710_1__R_s_b_2_6 = emitter.alloc_local(emitter.context().types().s64(), false);
  uint64_t CV_sym_51735_1_temporary_value;
  auto DV_sym_51735_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_51763_1_temporary_value;
  auto DV_sym_51763_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_51840_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51788_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2346 [F] s_b_0_0=sym_5901_3_parameter_inst.sf (const) */
    /* execute.a64:2697 [F] s_b_0_1: If s_b_0_0: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2348 [D] s_b_1_0 = sym_5906_0_amount uint8_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_5906_0_amount, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_1_1 = (u32)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_1_2 = constant u32 3f (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_1&s_b_1_2 */
    auto s_b_1_3 = emitter.bitwise_and(s_b_1_1, emitter.const_u32((uint32_t)63ULL));
    /* execute.a64:2348 [D] s_b_1_4 = (u8)s_b_1_3 */
    auto s_b_1_4 = emitter.truncate(s_b_1_3, emitter.context().types().u8());
    /* execute.a64:2348 [D] s_b_1_5: sym_5906_0_amount = s_b_1_4, dominates: s_b_15_3  */
    emitter.store_local(DV_sym_5906_0_amount, s_b_1_4);
    /* execute.a64:2348 [F] s_b_1_6: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2353 [F] s_b_2_0=sym_5901_3_parameter_inst.sf (const) */
    /* execute.a64:2706 [F] s_b_2_1: If s_b_2_0: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2350 [D] s_b_3_0 = sym_5906_0_amount uint8_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_5906_0_amount, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_3_1 = (u32)s_b_3_0 */
    auto s_b_3_1 = emitter.zx(s_b_3_0, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_3_2 = constant u32 1f (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_1&s_b_3_2 */
    auto s_b_3_3 = emitter.bitwise_and(s_b_3_1, emitter.const_u32((uint32_t)31ULL));
    /* execute.a64:2350 [D] s_b_3_4 = (u8)s_b_3_3 */
    auto s_b_3_4 = emitter.truncate(s_b_3_3, emitter.context().types().u8());
    /* execute.a64:2350 [D] s_b_3_5: sym_5906_0_amount = s_b_3_4, dominates: s_b_15_3  */
    emitter.store_local(DV_sym_5906_0_amount, s_b_3_4);
    /* execute.a64:2350 [F] s_b_3_6: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2698 [F] s_b_4_0=sym_5901_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2692 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_4_4: If s_b_4_3: Jump b_16 else b_17 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2700 [F] s_b_5_0=sym_5901_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2687 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_5_4: If s_b_5_3: Jump b_19 else b_20 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_18, b_21,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2346 [D] s_b_6_0 = sym_51651_1__R_s_b_0_4 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_51651_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2346 [D] s_b_6_1 = (u8)s_b_6_0 */
    auto s_b_6_1 = emitter.truncate(s_b_6_0, emitter.context().types().u8());
    /* execute.a64:2346 [D] s_b_6_2: sym_5906_0_amount = s_b_6_1, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_5906_0_amount, s_b_6_1);
    /* execute.a64:2347 [F] s_b_6_3=sym_5901_3_parameter_inst.sf (const) */
    /* execute.a64:2347 [F] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2707 [F] s_b_7_0=sym_5901_3_parameter_inst.rn (const) */
    /* execute.a64:2707 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2707 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2707 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2707 [F] s_b_7_4: If s_b_7_3: Jump b_9 else b_10 (const) */
    if (s_b_7_3) 
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
    /* execute.a64:2709 [F] s_b_8_0=sym_5901_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2709 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_8_4: If s_b_8_3: Jump b_11 else b_12 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2707 [F] s_b_9_0 = constant s64 0 (const) */
    /* execute.a64:2707 [F] s_b_9_1: sym_51684_1_temporary_value = s_b_9_0 (const), dominates: s_b_13_0  */
    CV_sym_51684_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_51684_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2707 [F] s_b_9_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2707 [F] s_b_10_0=sym_5901_3_parameter_inst.rn (const) */
    /* execute.a64:2707 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_10_2 = (s64)s_b_10_1 */
    auto s_b_10_2 = emitter.reinterpret(s_b_10_1, emitter.context().types().s64());
    /* execute.a64:2707 [D] s_b_10_3: sym_51684_1_temporary_value = s_b_10_2, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_51684_1_temporary_value, s_b_10_2);
    /* execute.a64:2707 [F] s_b_10_4: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [F] s_b_11_0 = constant s64 0 (const) */
    /* execute.a64:2709 [F] s_b_11_1: sym_51696_1_temporary_value = s_b_11_0 (const), dominates: s_b_14_0  */
    CV_sym_51696_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_51696_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2709 [F] s_b_11_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_8,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0=sym_5901_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_12_1 = ReadRegBank 1:s_b_12_0 (u32) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_12_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_12_2 = (s32)s_b_12_1 */
    auto s_b_12_2 = emitter.reinterpret(s_b_12_1, emitter.context().types().s32());
    /* execute.a64:2709 [D] s_b_12_3 = (s64)s_b_12_2 */
    auto s_b_12_3 = emitter.sx(s_b_12_2, emitter.context().types().s64());
    /* execute.a64:2709 [D] s_b_12_4: sym_51696_1_temporary_value = s_b_12_3, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_51696_1_temporary_value, s_b_12_3);
    /* execute.a64:2709 [F] s_b_12_5: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_9, b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2707 [D] s_b_13_0 = sym_51684_1_temporary_value int64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_51684_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2707 [D] s_b_13_1: sym_51710_1__R_s_b_2_6 = s_b_13_0, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_51710_1__R_s_b_2_6, s_b_13_0);
    /* execute.a64:2707 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_11, b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_51696_1_temporary_value int64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_51696_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2709 [D] s_b_14_1: sym_51710_1__R_s_b_2_6 = s_b_14_0, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_51710_1__R_s_b_2_6, s_b_14_0);
    /* execute.a64:2709 [F] s_b_14_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [F] s_b_15_0=sym_5901_3_parameter_inst.sf (const) */
    /* execute.a64:2353 [D] s_b_15_1 = sym_51710_1__R_s_b_2_6 int64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_51710_1__R_s_b_2_6, emitter.context().types().s64());
    /* execute.a64:2353 [D] s_b_15_2 = (s64)s_b_15_1 */
    auto s_b_15_2 = (captive::arch::dbt::el::Value *)s_b_15_1;
    /* execute.a64:2353 [D] s_b_15_3 = sym_5906_0_amount uint8_t */
    auto s_b_15_3 = emitter.load_local(DV_sym_5906_0_amount, emitter.context().types().u8());
    /* execute.a64:2353 [D] s_b_15_4 = (u64)s_b_15_2 */
    auto s_b_15_4 = emitter.reinterpret(s_b_15_2, emitter.context().types().u64());
    /* execute.a64:2353 [D] s_b_15_5 = (u64)s_b_15_3 */
    auto s_b_15_5 = emitter.zx(s_b_15_3, emitter.context().types().u64());
    /* execute.a64:2353 [D] s_b_15_6 = s_b_15_4->>s_b_15_5 */
    auto s_b_15_6 = emitter.sar(s_b_15_4, s_b_15_5);
    /* execute.a64:2353 [D] s_b_15_7 = (u64)s_b_15_6 */
    auto s_b_15_7 = (captive::arch::dbt::el::Value *)s_b_15_6;
    /* execute.a64:2353 [D] s_b_15_8: sym_51788_3_parameter_value = s_b_15_7, dominates: s_b_22_1 s_b_23_1  */
    emitter.store_local(DV_sym_51788_3_parameter_value, s_b_15_7);
    /* execute.a64:2731 [F] s_b_15_9: If s_b_15_0: Jump b_22 else b_23 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_4,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2692 [F] s_b_16_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_16_1: sym_51735_1_temporary_value = s_b_16_0 (const), dominates: s_b_18_0  */
    CV_sym_51735_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51735_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2692 [F] s_b_17_0=sym_5901_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [D] s_b_17_1 = ReadRegBank 0:s_b_17_0 (u64) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_17_2: sym_51735_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_51735_1_temporary_value, s_b_17_1);
    /* execute.a64:2692 [F] s_b_17_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_16, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2692 [D] s_b_18_0 = sym_51735_1_temporary_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_51735_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2698 [D] s_b_18_1: sym_51651_1__R_s_b_0_4 = s_b_18_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_51651_1__R_s_b_0_4, s_b_18_0);
    /* execute.a64:2698 [F] s_b_18_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2687 [F] s_b_19_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_19_1: sym_51763_1_temporary_value = s_b_19_0 (const), dominates: s_b_21_0  */
    CV_sym_51763_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51763_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_19_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_5,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2687 [F] s_b_20_0=sym_5901_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [D] s_b_20_1 = ReadRegBank 1:s_b_20_0 (u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_20_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_20_2: sym_51763_1_temporary_value = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_51763_1_temporary_value, s_b_20_1);
    /* execute.a64:2687 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_19, b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2687 [D] s_b_21_0 = sym_51763_1_temporary_value uint32_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_51763_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_21_1 = (u64)s_b_21_0 */
    auto s_b_21_1 = emitter.zx(s_b_21_0, emitter.context().types().u64());
    /* execute.a64:2700 [D] s_b_21_2: sym_51651_1__R_s_b_0_4 = s_b_21_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_51651_1__R_s_b_0_4, s_b_21_1);
    /* execute.a64:2700 [F] s_b_21_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_15,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2732 [F] s_b_22_0=sym_5901_3_parameter_inst.rd (const) */
    /* execute.a64:2732 [D] s_b_22_1 = sym_51788_3_parameter_value uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_51788_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2732 [D] s_b_22_2: sym_51818_3_parameter_value = s_b_22_1, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_51818_3_parameter_value, s_b_22_1);
    /* execute.a64:2723 [F] s_b_22_3 = (u32)s_b_22_0 (const) */
    /* execute.a64:2723 [F] s_b_22_4 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_22_5 = s_b_22_3==s_b_22_4 (const) */
    uint8_t s_b_22_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_22_6: If s_b_22_5: Jump b_24 else b_25 (const) */
    if (s_b_22_5) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_15,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2734 [F] s_b_23_0=sym_5901_3_parameter_inst.rd (const) */
    /* execute.a64:2734 [D] s_b_23_1 = sym_51788_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_51788_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_23_2 = (u32)s_b_23_1 */
    auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_23_3 = (u64)s_b_23_2 */
    auto s_b_23_3 = emitter.zx(s_b_23_2, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_23_4: sym_51840_3_parameter_value = s_b_23_3, dominates: s_b_26_1  */
    emitter.store_local(DV_sym_51840_3_parameter_value, s_b_23_3);
    /* execute.a64:2723 [F] s_b_23_5 = (u32)s_b_23_0 (const) */
    /* execute.a64:2723 [F] s_b_23_6 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_23_7 = s_b_23_5==s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_23_8: If s_b_23_7: Jump b_24 else b_26 (const) */
    if (s_b_23_7) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_22, b_23, b_25, b_26,  */
  fixed_block_b_24: 
  {
    /* ???:4294967295 [F] s_b_24_0: Return */
    goto fixed_done;
  }
  /* b_22,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2725 [F] s_b_25_0=sym_5901_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [D] s_b_25_1 = sym_51818_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_51818_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1);
    /* execute.a64:0 [F] s_b_25_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2725 [F] s_b_26_0=sym_5901_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [D] s_b_26_1 = sym_51840_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_51840_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1);
    /* execute.a64:0 [F] s_b_26_3: Jump b_24 (const) */
    goto fixed_block_b_24;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_bif(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2350 [F] s_b_0_0=sym_6291_3_parameter_inst.Q (const) */
    /* execute.simd:2350 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2358 [F] s_b_1_0=sym_6291_3_parameter_inst.rd (const) */
    /* execute.simd:6242 [D] s_b_1_1 = ReadRegBank 2:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:6243 [D] s_b_1_2 = ReadRegBank 3:s_b_1_0 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:2359 [F] s_b_1_3=sym_6291_3_parameter_inst.rn (const) */
    /* execute.simd:6242 [D] s_b_1_4 = ReadRegBank 2:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:6243 [D] s_b_1_5 = ReadRegBank 3:s_b_1_3 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.simd:2360 [F] s_b_1_6=sym_6291_3_parameter_inst.rm (const) */
    /* execute.simd:6242 [D] s_b_1_7 = ReadRegBank 2:s_b_1_6 (u64) */
    auto s_b_1_7 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_7,emitter.const_u8(8));
    }
    /* execute.simd:6243 [D] s_b_1_8 = ReadRegBank 3:s_b_1_6 (u64) */
    auto s_b_1_8 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_1_8,emitter.const_u8(8));
    }
    /* execute.simd:2362 [F] s_b_1_9=sym_6291_3_parameter_inst.rd (const) */
    /* execute.simd:2362 [D] s_b_1_10 = s_b_1_1^s_b_1_4 */
    auto s_b_1_10 = emitter.bitwise_xor(s_b_1_1, s_b_1_4);
    /* execute.simd:2362 [D] s_b_1_11 = ~s_b_1_7 */
    auto s_b_1_11 = emitter.bitwise_not(s_b_1_7);
    /* execute.simd:2362 [D] s_b_1_12 = s_b_1_10&s_b_1_11 */
    auto s_b_1_12 = emitter.bitwise_and(s_b_1_10, s_b_1_11);
    /* execute.simd:2362 [D] s_b_1_13 = s_b_1_1^s_b_1_12 */
    auto s_b_1_13 = emitter.bitwise_xor(s_b_1_1, s_b_1_12);
    /* execute.simd:2362 [D] s_b_1_14 = s_b_1_2^s_b_1_5 */
    auto s_b_1_14 = emitter.bitwise_xor(s_b_1_2, s_b_1_5);
    /* execute.simd:2362 [D] s_b_1_15 = ~s_b_1_8 */
    auto s_b_1_15 = emitter.bitwise_not(s_b_1_8);
    /* execute.simd:2362 [D] s_b_1_16 = s_b_1_14&s_b_1_15 */
    auto s_b_1_16 = emitter.bitwise_and(s_b_1_14, s_b_1_15);
    /* execute.simd:2362 [D] s_b_1_17 = s_b_1_2^s_b_1_16 */
    auto s_b_1_17 = emitter.bitwise_xor(s_b_1_2, s_b_1_16);
    /* execute.simd:6215 [D] s_b_1_18: WriteRegBank 2:s_b_1_9 = s_b_1_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13);
    /* execute.simd:6216 [D] s_b_1_19: WriteRegBank 3:s_b_1_9 = s_b_1_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_17,emitter.const_u8(8));
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
    /* execute.simd:2368 [F] s_b_3_0=sym_6291_3_parameter_inst.rd (const) */
    /* execute.simd:6237 [D] s_b_3_1 = ReadRegBank 7:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:2369 [F] s_b_3_2=sym_6291_3_parameter_inst.rn (const) */
    /* execute.simd:6237 [D] s_b_3_3 = ReadRegBank 7:s_b_3_2 (u64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:2370 [F] s_b_3_4=sym_6291_3_parameter_inst.rm (const) */
    /* execute.simd:6237 [D] s_b_3_5 = ReadRegBank 7:s_b_3_4 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:2372 [F] s_b_3_6=sym_6291_3_parameter_inst.rd (const) */
    /* execute.simd:2372 [D] s_b_3_7 = s_b_3_1^s_b_3_3 */
    auto s_b_3_7 = emitter.bitwise_xor(s_b_3_1, s_b_3_3);
    /* execute.simd:2372 [D] s_b_3_8 = ~s_b_3_5 */
    auto s_b_3_8 = emitter.bitwise_not(s_b_3_5);
    /* execute.simd:2372 [D] s_b_3_9 = s_b_3_7&s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_7, s_b_3_8);
    /* execute.simd:2372 [D] s_b_3_10 = s_b_3_1^s_b_3_9 */
    auto s_b_3_10 = emitter.bitwise_xor(s_b_3_1, s_b_3_9);
    /* execute.simd:6208 [D] s_b_3_11: WriteRegBank 2:s_b_3_6 = s_b_3_10 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_10,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_10);
    /* execute.simd:6209 [F] s_b_3_12 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_3_13: WriteRegBank 3:s_b_3_6 = s_b_3_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ccmpr(const arm64_decode_a64_COND_CMP_REG&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto block_b_27 = emitter.context().create_block();
  auto block_b_28 = emitter.context().create_block();
  auto block_b_29 = emitter.context().create_block();
  auto block_b_30 = emitter.context().create_block();
  auto block_b_31 = emitter.context().create_block();
  auto block_b_32 = emitter.context().create_block();
  auto block_b_33 = emitter.context().create_block();
  auto block_b_34 = emitter.context().create_block();
  auto block_b_35 = emitter.context().create_block();
  auto DV_sym_55446_1__R_s_b_23_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55465_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55493_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  uint8_t CV_sym_55252_0_state;
  auto DV_sym_55252_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55340_1__R_s_b_0_2 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55365_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55384_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55412_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_6849_0_rm = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_6844_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2104 [F] s_b_0_0=sym_6826_3_parameter_inst.cond (const) */
    /* execute.a64:2832 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2832 [F] s_b_0_2: sym_55252_0_state = s_b_0_1 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_55252_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_55252_0_state, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2834 [F] s_b_0_3 = (u32)s_b_0_0 (const) */
    /* execute.a64:2834 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:2834 [F] s_b_0_5 = s_b_0_3>>s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(((uint32_t)insn.cond) >> (uint32_t)1ULL));
    /* execute.a64:2835 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.a64:2839 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.a64:2843 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.a64:2847 [F] s_b_0_9 = constant s32 3 (const) */
    /* execute.a64:2851 [F] s_b_0_10 = constant s32 4 (const) */
    /* execute.a64:2855 [F] s_b_0_11 = constant s32 5 (const) */
    /* execute.a64:2859 [F] s_b_0_12 = constant s32 6 (const) */
    /* execute.a64:2863 [F] s_b_0_13 = constant s32 7 (const) */
    /* execute.a64:2834 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_9, b_8, b_7, b_6, b_10, b_11, b_12, b_13, b_14,  */
    switch (s_b_0_5) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_12;
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
    /* execute.a64:2869 [F] s_b_6_0=sym_6826_3_parameter_inst.cond (const) */
    /* execute.a64:2869 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2869 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.a64:2869 [F] s_b_6_3 = s_b_6_1&s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2869 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:2869 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:2869 [F] s_b_6_6=sym_6826_3_parameter_inst.cond (const) */
    /* execute.a64:2869 [F] s_b_6_7 = (u32)s_b_6_6 (const) */
    /* execute.a64:2869 [F] s_b_6_8 = constant u32 f (const) */
    /* execute.a64:2869 [F] s_b_6_9 = s_b_6_7!=s_b_6_8 (const) */
    uint8_t s_b_6_9 = ((uint8_t)(((uint32_t)insn.cond) != (uint32_t)15ULL));
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_6_11 = s_b_6_5!=s_b_6_10 (const) */
    uint8_t s_b_6_11 = ((uint8_t)(s_b_6_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_12 = s_b_6_9!=s_b_6_10 (const) */
    uint8_t s_b_6_12 = ((uint8_t)(s_b_6_9 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_13 = s_b_6_11&s_b_6_12 (const) */
    uint8_t s_b_6_13 = ((uint8_t)(s_b_6_11 & s_b_6_12));
    /* execute.a64:2869 [F] s_b_6_14: If s_b_6_13: Jump b_15 else b_16 (const) */
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
    /* execute.a64:2852 [D] s_b_7_0 = ReadReg 3 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2852 [D] s_b_7_1 = ReadReg 2 (u8) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_7_1, emitter.const_u8(1));
    }
    /* execute.a64:2852 [D] s_b_7_2 = !s_b_7_1 */
    auto s_b_7_2 = emitter.cmp_eq(s_b_7_1, emitter.const_u8(0));
    /* execute.a64:2852 [D] s_b_7_3 = s_b_7_0&s_b_7_2 */
    auto s_b_7_3 = emitter.bitwise_and(s_b_7_0, s_b_7_2);
    /* execute.a64:2852 [D] s_b_7_4: sym_55252_0_state = s_b_7_3, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55252_0_state, s_b_7_3);
    /* execute.a64:0 [F] s_b_7_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2848 [D] s_b_8_0 = ReadReg 4 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2848 [D] s_b_8_1: sym_55252_0_state = s_b_8_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55252_0_state, s_b_8_0);
    /* execute.a64:0 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2844 [D] s_b_9_0 = ReadReg 1 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2844 [D] s_b_9_1: sym_55252_0_state = s_b_9_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55252_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2840 [D] s_b_10_0 = ReadReg 3 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2840 [D] s_b_10_1: sym_55252_0_state = s_b_10_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55252_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2836 [D] s_b_11_0 = ReadReg 2 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2836 [D] s_b_11_1: sym_55252_0_state = s_b_11_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55252_0_state, s_b_11_0);
    /* execute.a64:0 [F] s_b_11_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2864 [F] s_b_12_0 = constant u8 1 (const) */
    /* execute.a64:2864 [F] s_b_12_1: sym_55252_0_state = s_b_12_0 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_55252_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_55252_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_12_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2860 [D] s_b_13_0 = ReadReg 1 (u8) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2860 [D] s_b_13_1 = ReadReg 4 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_13_1, emitter.const_u8(1));
    }
    /* execute.a64:2860 [D] s_b_13_2 = s_b_13_0==s_b_13_1 */
    auto s_b_13_2 = emitter.cmp_eq(s_b_13_0, s_b_13_1);
    /* execute.a64:2860 [D] s_b_13_3 = ReadReg 2 (u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_13_3, emitter.const_u8(1));
    }
    /* execute.a64:2860 [D] s_b_13_4 = !s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_eq(s_b_13_3, emitter.const_u8(0));
    /* execute.a64:2860 [D] s_b_13_5 = s_b_13_2&s_b_13_4 */
    auto s_b_13_5 = emitter.bitwise_and(s_b_13_2, s_b_13_4);
    /* execute.a64:2860 [D] s_b_13_6: sym_55252_0_state = s_b_13_5, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55252_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2856 [D] s_b_14_0 = ReadReg 1 (u8) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_14_0, emitter.const_u8(1));
    }
    /* execute.a64:2856 [D] s_b_14_1 = ReadReg 4 (u8) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_1, emitter.const_u8(1));
    }
    /* execute.a64:2856 [D] s_b_14_2 = s_b_14_0==s_b_14_1 */
    auto s_b_14_2 = emitter.cmp_eq(s_b_14_0, s_b_14_1);
    /* execute.a64:2856 [D] s_b_14_3: sym_55252_0_state = s_b_14_2, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55252_0_state, s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2870 [D] s_b_15_0 = sym_55252_0_state uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_55252_0_state, emitter.context().types().u8());
    /* execute.a64:2870 [D] s_b_15_1 = !s_b_15_0 */
    auto s_b_15_1 = emitter.cmp_eq(s_b_15_0, emitter.const_u8(0));
    /* execute.a64:2870 [D] s_b_15_2: sym_55340_1__R_s_b_0_2 = s_b_15_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_55340_1__R_s_b_0_2, s_b_15_1);
    /* execute.a64:2870 [F] s_b_15_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2872 [D] s_b_16_0 = sym_55252_0_state uint8_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_55252_0_state, emitter.context().types().u8());
    /* execute.a64:2872 [D] s_b_16_1: sym_55340_1__R_s_b_0_2 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_55340_1__R_s_b_0_2, s_b_16_0);
    /* execute.a64:2872 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2104 [D] s_b_17_0 = sym_55340_1__R_s_b_0_2 uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_55340_1__R_s_b_0_2, emitter.context().types().u8());
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
  // BLOCK b_27 not fully fixed
  // BLOCK b_28 not fully fixed
  // BLOCK b_29 not fully fixed
  // BLOCK b_30 not fully fixed
  // BLOCK b_31 not fully fixed
  // BLOCK b_32 not fully fixed
  // BLOCK b_33 not fully fixed
  // BLOCK b_34 not fully fixed
  // BLOCK b_35 not fully fixed
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
        /* execute.a64:2106 [F] s_b_1_0=sym_6826_3_parameter_inst.sf (const) */
        /* execute.a64:2697 [F] s_b_1_1: If s_b_1_0: Jump b_18 else b_19 (const) */
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
        /* execute.a64:2115 [F] s_b_3_0=sym_6826_3_parameter_inst.nzcv (const) */
        /* execute.a64:2115 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.a64:2115 [F] s_b_3_2 = constant u32 8 (const) */
        /* execute.a64:2115 [F] s_b_3_3 = s_b_3_1&s_b_3_2 (const) */
        uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)8ULL));
        /* execute.a64:2115 [F] s_b_3_4 = constant u32 8 (const) */
        /* execute.a64:2115 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
        uint8_t s_b_3_5 = ((uint8_t)(s_b_3_3 == (uint32_t)8ULL));
        /* execute.a64:2115 [F] s_b_3_6: WriteReg 1 = s_b_3_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), emitter.const_u8(s_b_3_5), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1296), emitter.const_u8(s_b_3_5));
        /* execute.a64:2116 [F] s_b_3_7=sym_6826_3_parameter_inst.nzcv (const) */
        /* execute.a64:2116 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
        /* execute.a64:2116 [F] s_b_3_9 = constant u32 4 (const) */
        /* execute.a64:2116 [F] s_b_3_10 = s_b_3_8&s_b_3_9 (const) */
        uint32_t s_b_3_10 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)4ULL));
        /* execute.a64:2116 [F] s_b_3_11 = constant u32 4 (const) */
        /* execute.a64:2116 [F] s_b_3_12 = s_b_3_10==s_b_3_11 (const) */
        uint8_t s_b_3_12 = ((uint8_t)(s_b_3_10 == (uint32_t)4ULL));
        /* execute.a64:2116 [F] s_b_3_13: WriteReg 2 = s_b_3_12 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), emitter.const_u8(s_b_3_12), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1297), emitter.const_u8(s_b_3_12));
        /* execute.a64:2117 [F] s_b_3_14=sym_6826_3_parameter_inst.nzcv (const) */
        /* execute.a64:2117 [F] s_b_3_15 = (u32)s_b_3_14 (const) */
        /* execute.a64:2117 [F] s_b_3_16 = constant u32 2 (const) */
        /* execute.a64:2117 [F] s_b_3_17 = s_b_3_15&s_b_3_16 (const) */
        uint32_t s_b_3_17 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)2ULL));
        /* execute.a64:2117 [F] s_b_3_18 = constant u32 2 (const) */
        /* execute.a64:2117 [F] s_b_3_19 = s_b_3_17==s_b_3_18 (const) */
        uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 == (uint32_t)2ULL));
        /* execute.a64:2117 [F] s_b_3_20: WriteReg 3 = s_b_3_19 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8(s_b_3_19), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1298), emitter.const_u8(s_b_3_19));
        /* execute.a64:2118 [F] s_b_3_21=sym_6826_3_parameter_inst.nzcv (const) */
        /* execute.a64:2118 [F] s_b_3_22 = (u32)s_b_3_21 (const) */
        /* execute.a64:2118 [F] s_b_3_23 = constant u32 1 (const) */
        /* execute.a64:2118 [F] s_b_3_24 = s_b_3_22&s_b_3_23 (const) */
        uint32_t s_b_3_24 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)1ULL));
        /* execute.a64:2118 [F] s_b_3_25 = constant u32 1 (const) */
        /* execute.a64:2118 [F] s_b_3_26 = s_b_3_24==s_b_3_25 (const) */
        uint8_t s_b_3_26 = ((uint8_t)(s_b_3_24 == (uint32_t)1ULL));
        /* execute.a64:2118 [F] s_b_3_27: WriteReg 4 = s_b_3_26 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8(s_b_3_26), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1299), emitter.const_u8(s_b_3_26));
        /* execute.a64:2115 [F] s_b_3_28: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.a64:2110 [D] s_b_4_0 = sym_6844_0_rn uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_6844_0_rn, emitter.context().types().u64());
        /* execute.a64:2110 [D] s_b_4_1 = (u32)s_b_4_0 */
        auto s_b_4_1 = emitter.truncate(s_b_4_0, emitter.context().types().u32());
        /* execute.a64:2110 [D] s_b_4_2 = sym_6849_0_rm uint64_t */
        auto s_b_4_2 = emitter.load_local(DV_sym_6849_0_rm, emitter.context().types().u64());
        /* execute.a64:2110 [D] s_b_4_3 = (u32)s_b_4_2 */
        auto s_b_4_3 = emitter.truncate(s_b_4_2, emitter.context().types().u32());
        /* execute.a64:2110 [D] s_b_4_4 = ~s_b_4_3 */
        auto s_b_4_4 = emitter.bitwise_not(s_b_4_3);
        /* execute.a64:2110 [F] s_b_4_5 = constant u8 1 (const) */
        /* execute.a64:2110 [D] s_b_4_6 = __builtin_adc32_flags */
        auto s_b_4_6 = emitter.adcf(s_b_4_1, s_b_4_4, emitter.const_u8((uint8_t)1ULL));
        /* execute.a64:2110 [F] s_b_4_7: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2112 [D] s_b_5_0 = sym_6844_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_6844_0_rn, emitter.context().types().u64());
        /* execute.a64:2112 [D] s_b_5_1 = sym_6849_0_rm uint64_t */
        auto s_b_5_1 = emitter.load_local(DV_sym_6849_0_rm, emitter.context().types().u64());
        /* execute.a64:2112 [D] s_b_5_2 = ~s_b_5_1 */
        auto s_b_5_2 = emitter.bitwise_not(s_b_5_1);
        /* execute.a64:2112 [F] s_b_5_3 = constant u8 1 (const) */
        /* execute.a64:2112 [D] s_b_5_4 = __builtin_adc64_flags */
        auto s_b_5_4 = emitter.adcf(s_b_5_0, s_b_5_2, emitter.const_u8((uint8_t)1ULL));
        /* execute.a64:2112 [F] s_b_5_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2698 [F] s_b_18_0=sym_6826_3_parameter_inst.rn (const) */
        /* execute.a64:2692 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
        /* execute.a64:2692 [F] s_b_18_2 = constant u32 1f (const) */
        /* execute.a64:2692 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
        uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2692 [F] s_b_18_4: If s_b_18_3: Jump b_21 else b_22 (const) */
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
        /* execute.a64:2700 [F] s_b_19_0=sym_6826_3_parameter_inst.rn (const) */
        /* execute.a64:2687 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.a64:2687 [F] s_b_19_2 = constant u32 1f (const) */
        /* execute.a64:2687 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
        uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2687 [F] s_b_19_4: If s_b_19_3: Jump b_24 else b_25 (const) */
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
        /* execute.a64:2106 [D] s_b_20_0 = sym_55365_1__R_s_b_1_4 uint64_t */
        auto s_b_20_0 = emitter.load_local(DV_sym_55365_1__R_s_b_1_4, emitter.context().types().u64());
        /* execute.a64:2106 [D] s_b_20_1: sym_6844_0_rn = s_b_20_0, dominates: s_b_4_0 s_b_5_0  */
        emitter.store_local(DV_sym_6844_0_rn, s_b_20_0);
        /* execute.a64:2107 [F] s_b_20_2=sym_6826_3_parameter_inst.sf (const) */
        /* execute.a64:2697 [F] s_b_20_3: If s_b_20_2: Jump b_27 else b_28 (const) */
        if (insn.sf) 
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
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.a64:2692 [F] s_b_21_0 = constant u64 0 (const) */
        /* execute.a64:2692 [D] s_b_21_1: sym_55384_1_temporary_value = s_b_21_0, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_55384_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2692 [F] s_b_21_2: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.a64:2692 [F] s_b_22_0=sym_6826_3_parameter_inst.rn (const) */
        /* execute.a64:2692 [D] s_b_22_1 = ReadRegBank 0:s_b_22_0 (u64) */
        auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_22_1,emitter.const_u8(8));
        }
        /* execute.a64:2692 [D] s_b_22_2: sym_55384_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_55384_1_temporary_value, s_b_22_1);
        /* execute.a64:2692 [F] s_b_22_3: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.a64:2692 [D] s_b_23_0 = sym_55384_1_temporary_value uint64_t */
        auto s_b_23_0 = emitter.load_local(DV_sym_55384_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2698 [D] s_b_23_1: sym_55365_1__R_s_b_1_4 = s_b_23_0, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_55365_1__R_s_b_1_4, s_b_23_0);
        /* execute.a64:2698 [F] s_b_23_2: Jump b_20 (const) */
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.a64:2687 [F] s_b_24_0 = constant u32 0 (const) */
        /* execute.a64:2687 [D] s_b_24_1: sym_55412_1_temporary_value = s_b_24_0, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_55412_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2687 [F] s_b_24_2: Jump b_26 (const) */
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.a64:2687 [F] s_b_25_0=sym_6826_3_parameter_inst.rn (const) */
        /* execute.a64:2687 [D] s_b_25_1 = ReadRegBank 1:s_b_25_0 (u32) */
        auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1,emitter.const_u8(4));
        }
        /* execute.a64:2687 [D] s_b_25_2: sym_55412_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_55412_1_temporary_value, s_b_25_1);
        /* execute.a64:2687 [F] s_b_25_3: Jump b_26 (const) */
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.a64:2687 [D] s_b_26_0 = sym_55412_1_temporary_value uint32_t */
        auto s_b_26_0 = emitter.load_local(DV_sym_55412_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2700 [D] s_b_26_1 = (u64)s_b_26_0 */
        auto s_b_26_1 = emitter.zx(s_b_26_0, emitter.context().types().u64());
        /* execute.a64:2700 [D] s_b_26_2: sym_55365_1__R_s_b_1_4 = s_b_26_1, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_55365_1__R_s_b_1_4, s_b_26_1);
        /* execute.a64:2700 [F] s_b_26_3: Jump b_20 (const) */
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.a64:2698 [F] s_b_27_0=sym_6826_3_parameter_inst.rm (const) */
        /* execute.a64:2692 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
        /* execute.a64:2692 [F] s_b_27_2 = constant u32 1f (const) */
        /* execute.a64:2692 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
        uint8_t s_b_27_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2692 [F] s_b_27_4: If s_b_27_3: Jump b_30 else b_31 (const) */
        if (s_b_27_3) 
        {
          auto block = block_b_30;
          dynamic_block_queue.push(block_b_30);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.a64:2700 [F] s_b_28_0=sym_6826_3_parameter_inst.rm (const) */
        /* execute.a64:2687 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
        /* execute.a64:2687 [F] s_b_28_2 = constant u32 1f (const) */
        /* execute.a64:2687 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
        uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2687 [F] s_b_28_4: If s_b_28_3: Jump b_33 else b_34 (const) */
        if (s_b_28_3) 
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_34;
          dynamic_block_queue.push(block_b_34);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.a64:2107 [D] s_b_29_0 = sym_55446_1__R_s_b_23_6 uint64_t */
        auto s_b_29_0 = emitter.load_local(DV_sym_55446_1__R_s_b_23_6, emitter.context().types().u64());
        /* execute.a64:2107 [D] s_b_29_1: sym_6849_0_rm = s_b_29_0, dominates: s_b_4_2 s_b_5_1  */
        emitter.store_local(DV_sym_6849_0_rm, s_b_29_0);
        /* execute.a64:2109 [F] s_b_29_2=sym_6826_3_parameter_inst.sf (const) */
        /* execute.a64:2109 [F] s_b_29_3 = (u32)s_b_29_2 (const) */
        /* execute.a64:2109 [F] s_b_29_4 = constant u32 0 (const) */
        /* execute.a64:2109 [F] s_b_29_5 = s_b_29_3==s_b_29_4 (const) */
        uint8_t s_b_29_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
        /* execute.a64:2109 [F] s_b_29_6: If s_b_29_5: Jump b_4 else b_5 (const) */
        if (s_b_29_5) 
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
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.a64:2692 [F] s_b_30_0 = constant u64 0 (const) */
        /* execute.a64:2692 [D] s_b_30_1: sym_55465_1_temporary_value = s_b_30_0, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_55465_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2692 [F] s_b_30_2: Jump b_32 (const) */
        {
          auto block = block_b_32;
          dynamic_block_queue.push(block_b_32);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.a64:2692 [F] s_b_31_0=sym_6826_3_parameter_inst.rm (const) */
        /* execute.a64:2692 [D] s_b_31_1 = ReadRegBank 0:s_b_31_0 (u64) */
        auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_31_1,emitter.const_u8(8));
        }
        /* execute.a64:2692 [D] s_b_31_2: sym_55465_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_55465_1_temporary_value, s_b_31_1);
        /* execute.a64:2692 [F] s_b_31_3: Jump b_32 (const) */
        {
          auto block = block_b_32;
          dynamic_block_queue.push(block_b_32);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.a64:2692 [D] s_b_32_0 = sym_55465_1_temporary_value uint64_t */
        auto s_b_32_0 = emitter.load_local(DV_sym_55465_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2698 [D] s_b_32_1: sym_55446_1__R_s_b_23_6 = s_b_32_0, dominates: s_b_29_0  */
        emitter.store_local(DV_sym_55446_1__R_s_b_23_6, s_b_32_0);
        /* execute.a64:2698 [F] s_b_32_2: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.a64:2687 [F] s_b_33_0 = constant u32 0 (const) */
        /* execute.a64:2687 [D] s_b_33_1: sym_55493_1_temporary_value = s_b_33_0, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_55493_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2687 [F] s_b_33_2: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.a64:2687 [F] s_b_34_0=sym_6826_3_parameter_inst.rm (const) */
        /* execute.a64:2687 [D] s_b_34_1 = ReadRegBank 1:s_b_34_0 (u32) */
        auto s_b_34_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_34_1,emitter.const_u8(4));
        }
        /* execute.a64:2687 [D] s_b_34_2: sym_55493_1_temporary_value = s_b_34_1, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_55493_1_temporary_value, s_b_34_1);
        /* execute.a64:2687 [F] s_b_34_3: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.a64:2687 [D] s_b_35_0 = sym_55493_1_temporary_value uint32_t */
        auto s_b_35_0 = emitter.load_local(DV_sym_55493_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2700 [D] s_b_35_1 = (u64)s_b_35_0 */
        auto s_b_35_1 = emitter.zx(s_b_35_0, emitter.context().types().u64());
        /* execute.a64:2700 [D] s_b_35_2: sym_55446_1__R_s_b_23_6 = s_b_35_1, dominates: s_b_29_0  */
        emitter.store_local(DV_sym_55446_1__R_s_b_23_6, s_b_35_1);
        /* execute.a64:2700 [F] s_b_35_3: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_cmlt_zero(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_8 = emitter.context().create_block();
  auto block_b_9 = emitter.context().create_block();
  auto DV_sym_7976_0_rn = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1970 [F] s_b_0_0=sym_7967_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1970 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1971 [F] s_b_1_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:6237 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:1971 [D] s_b_1_2: sym_7976_0_rn = s_b_1_1, dominates: s_b_4_0 s_b_5_0  */
    emitter.store_local(DV_sym_7976_0_rn, s_b_1_1);
    /* execute.simd:1973 [F] s_b_1_3=sym_7967_3_parameter_inst.U (const) */
    /* execute.simd:1973 [F] s_b_1_4 = (u32)s_b_1_3 (const) */
    /* execute.simd:1973 [F] s_b_1_5 = constant u32 1 (const) */
    /* execute.simd:1973 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:1973 [F] s_b_1_7: If s_b_1_6: Jump b_4 else b_5 (const) */
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
    /* execute.simd:1987 [F] s_b_3_0=sym_7967_3_parameter_inst.U (const) */
    /* execute.simd:1987 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:1987 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:1987 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:1987 [F] s_b_3_4: If s_b_3_3: Jump b_10 else b_11 (const) */
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
    /* execute.simd:1974 [D] s_b_4_0 = sym_7976_0_rn uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_7976_0_rn, emitter.context().types().u64());
    /* execute.simd:1974 [D] s_b_4_1 = (s64)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s64());
    /* execute.simd:1974 [F] s_b_4_2 = constant s64 0 (const) */
    /* execute.simd:1974 [D] s_b_4_3 = s_b_4_1<=s_b_4_2 */
    auto s_b_4_3 = emitter.cmp_le(s_b_4_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:1974 [D] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 */
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
      emitter.branch(s_b_4_3, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:1980 [D] s_b_5_0 = sym_7976_0_rn uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_7976_0_rn, emitter.context().types().u64());
    /* execute.simd:1980 [D] s_b_5_1 = (s64)s_b_5_0 */
    auto s_b_5_1 = emitter.reinterpret(s_b_5_0, emitter.context().types().s64());
    /* execute.simd:1980 [F] s_b_5_2 = constant s64 0 (const) */
    /* execute.simd:1980 [D] s_b_5_3 = s_b_5_1<s_b_5_2 */
    auto s_b_5_3 = emitter.cmp_lt(s_b_5_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:1980 [D] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_8;
        dynamic_block_queue.push(block_b_8);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
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
    /* execute.simd:1988 [F] s_b_10_0=sym_7967_3_parameter_inst.arrangement (const) */
    /* execute.simd:1989 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.simd:1998 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.simd:2006 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.simd:2015 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.simd:2023 [F] s_b_10_5 = constant s32 4 (const) */
    /* execute.simd:2032 [F] s_b_10_6 = constant s32 5 (const) */
    /* execute.simd:2040 [F] s_b_10_7 = constant s32 6 (const) */
    /* execute.simd:1988 [F] s_b_10_8: Switch s_b_10_0: < <todo> > def b_19 (const) -> b_19, b_18, b_17, b_16, b_15, b_14, b_13, b_12,  */
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
    /* execute.simd:2054 [F] s_b_11_0=sym_7967_3_parameter_inst.arrangement (const) */
    /* execute.simd:2055 [F] s_b_11_1 = constant s32 0 (const) */
    /* execute.simd:2064 [F] s_b_11_2 = constant s32 1 (const) */
    /* execute.simd:2072 [F] s_b_11_3 = constant s32 2 (const) */
    /* execute.simd:2081 [F] s_b_11_4 = constant s32 3 (const) */
    /* execute.simd:2089 [F] s_b_11_5 = constant s32 4 (const) */
    /* execute.simd:2098 [F] s_b_11_6 = constant s32 5 (const) */
    /* execute.simd:2106 [F] s_b_11_7 = constant s32 6 (const) */
    /* execute.simd:2054 [F] s_b_11_8: Switch s_b_11_0: < <todo> > def b_27 (const) -> b_27, b_26, b_25, b_24, b_23, b_22, b_21, b_20,  */
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
    /* execute.simd:1990 [F] s_b_12_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:1990 [D] s_b_12_1 = ReadRegBank 15:s_b_12_0 (v8u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:1990 [D] s_b_12_2 = (v8s8)s_b_12_1 */
    auto s_b_12_2 = emitter.reinterpret(s_b_12_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_12_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:1992 [D] s_b_12_4 = s_b_12_2<=s_b_12_3 */
    auto s_b_12_4 = emitter.cmp_le(s_b_12_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:1992 [D] s_b_12_5 = (v8u8)s_b_12_4 */
    auto s_b_12_5 = emitter.reinterpret(s_b_12_4, emitter.context().types().v8u8());
    /* execute.simd:1993 [F] s_b_12_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:1993 [D] s_b_12_7: WriteRegBank 15:s_b_12_6 = s_b_12_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5);
    /* execute.simd:1994 [F] s_b_12_8=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:1994 [F] s_b_12_9 = constant u64 0 (const) */
    /* execute.simd:1994 [F] s_b_12_10: WriteRegBank 3:s_b_12_8 = s_b_12_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:1999 [F] s_b_13_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:1999 [D] s_b_13_1 = ReadRegBank 16:s_b_13_0 (v16u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_13_1,emitter.const_u8(16));
    }
    /* execute.simd:1999 [D] s_b_13_2 = (v16s8)s_b_13_1 */
    auto s_b_13_2 = emitter.reinterpret(s_b_13_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_13_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:2001 [D] s_b_13_4 = s_b_13_2<=s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_le(s_b_13_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:2001 [D] s_b_13_5 = (v16u8)s_b_13_4 */
    auto s_b_13_5 = emitter.reinterpret(s_b_13_4, emitter.context().types().v16u8());
    /* execute.simd:2002 [F] s_b_13_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2002 [D] s_b_13_7: WriteRegBank 16:s_b_13_6 = s_b_13_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_5,emitter.const_u8(16));
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
    /* execute.simd:2007 [F] s_b_14_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2007 [D] s_b_14_1 = ReadRegBank 17:s_b_14_0 (v4u16) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.simd:2007 [D] s_b_14_2 = (v4s16)s_b_14_1 */
    auto s_b_14_2 = emitter.reinterpret(s_b_14_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_14_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:2009 [D] s_b_14_4 = s_b_14_2<=s_b_14_3 */
    auto s_b_14_4 = emitter.cmp_le(s_b_14_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:2009 [D] s_b_14_5 = (v4u16)s_b_14_4 */
    auto s_b_14_5 = emitter.reinterpret(s_b_14_4, emitter.context().types().v4u16());
    /* execute.simd:2010 [F] s_b_14_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2010 [D] s_b_14_7: WriteRegBank 17:s_b_14_6 = s_b_14_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5);
    /* execute.simd:2011 [F] s_b_14_8=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2011 [F] s_b_14_9 = constant u64 0 (const) */
    /* execute.simd:2011 [F] s_b_14_10: WriteRegBank 3:s_b_14_8 = s_b_14_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:2016 [F] s_b_15_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2016 [D] s_b_15_1 = ReadRegBank 18:s_b_15_0 (v8u16) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_15_1,emitter.const_u8(16));
    }
    /* execute.simd:2016 [D] s_b_15_2 = (v8s16)s_b_15_1 */
    auto s_b_15_2 = emitter.reinterpret(s_b_15_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_15_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:2018 [D] s_b_15_4 = s_b_15_2<=s_b_15_3 */
    auto s_b_15_4 = emitter.cmp_le(s_b_15_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:2018 [D] s_b_15_5 = (v8u16)s_b_15_4 */
    auto s_b_15_5 = emitter.reinterpret(s_b_15_4, emitter.context().types().v8u16());
    /* execute.simd:2020 [F] s_b_15_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2020 [D] s_b_15_7: WriteRegBank 18:s_b_15_6 = s_b_15_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_15_5,emitter.const_u8(16));
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
    /* execute.simd:2024 [F] s_b_16_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2024 [D] s_b_16_1 = ReadRegBank 19:s_b_16_0 (v2u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:2024 [D] s_b_16_2 = (v2s32)s_b_16_1 */
    auto s_b_16_2 = emitter.reinterpret(s_b_16_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_16_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:2026 [D] s_b_16_4 = s_b_16_2<=s_b_16_3 */
    auto s_b_16_4 = emitter.cmp_le(s_b_16_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:2026 [D] s_b_16_5 = (v2u32)s_b_16_4 */
    auto s_b_16_5 = emitter.reinterpret(s_b_16_4, emitter.context().types().v2u32());
    /* execute.simd:2027 [F] s_b_16_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2027 [D] s_b_16_7: WriteRegBank 19:s_b_16_6 = s_b_16_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5);
    /* execute.simd:2028 [F] s_b_16_8=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2028 [F] s_b_16_9 = constant u64 0 (const) */
    /* execute.simd:2028 [F] s_b_16_10: WriteRegBank 3:s_b_16_8 = s_b_16_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:2033 [F] s_b_17_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2033 [D] s_b_17_1 = ReadRegBank 20:s_b_17_0 (v4u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:2033 [D] s_b_17_2 = (v4s32)s_b_17_1 */
    auto s_b_17_2 = emitter.reinterpret(s_b_17_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_17_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:2035 [D] s_b_17_4 = s_b_17_2<=s_b_17_3 */
    auto s_b_17_4 = emitter.cmp_le(s_b_17_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:2035 [D] s_b_17_5 = (v4u32)s_b_17_4 */
    auto s_b_17_5 = emitter.reinterpret(s_b_17_4, emitter.context().types().v4u32());
    /* execute.simd:2037 [F] s_b_17_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2037 [D] s_b_17_7: WriteRegBank 20:s_b_17_6 = s_b_17_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_17_5,emitter.const_u8(16));
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
    /* execute.simd:2041 [F] s_b_18_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2041 [D] s_b_18_1 = ReadRegBank 21:s_b_18_0 (v2u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_18_1,emitter.const_u8(16));
    }
    /* execute.simd:2041 [D] s_b_18_2 = (v2s64)s_b_18_1 */
    auto s_b_18_2 = emitter.reinterpret(s_b_18_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_18_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:2043 [D] s_b_18_4 = s_b_18_2<=s_b_18_3 */
    auto s_b_18_4 = emitter.cmp_le(s_b_18_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:2043 [D] s_b_18_5 = (v2u64)s_b_18_4 */
    auto s_b_18_5 = emitter.reinterpret(s_b_18_4, emitter.context().types().v2u64());
    /* execute.simd:2045 [F] s_b_18_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2045 [D] s_b_18_7: WriteRegBank 21:s_b_18_6 = s_b_18_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_18_5,emitter.const_u8(16));
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
    /* execute.simd:2049 [D] s_b_19_0 = trap */
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
    /* execute.simd:2056 [F] s_b_20_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2056 [D] s_b_20_1 = ReadRegBank 15:s_b_20_0 (v8u8) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:2056 [D] s_b_20_2 = (v8s8)s_b_20_1 */
    auto s_b_20_2 = emitter.reinterpret(s_b_20_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_20_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:2058 [D] s_b_20_4 = s_b_20_2<s_b_20_3 */
    auto s_b_20_4 = emitter.cmp_lt(s_b_20_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:2058 [D] s_b_20_5 = (v8u8)s_b_20_4 */
    auto s_b_20_5 = emitter.reinterpret(s_b_20_4, emitter.context().types().v8u8());
    /* execute.simd:2059 [F] s_b_20_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2059 [D] s_b_20_7: WriteRegBank 15:s_b_20_6 = s_b_20_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5);
    /* execute.simd:2060 [F] s_b_20_8=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2060 [F] s_b_20_9 = constant u64 0 (const) */
    /* execute.simd:2060 [F] s_b_20_10: WriteRegBank 3:s_b_20_8 = s_b_20_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:2065 [F] s_b_21_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2065 [D] s_b_21_1 = ReadRegBank 16:s_b_21_0 (v16u8) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:2065 [D] s_b_21_2 = (v16s8)s_b_21_1 */
    auto s_b_21_2 = emitter.reinterpret(s_b_21_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_21_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:2067 [D] s_b_21_4 = s_b_21_2<s_b_21_3 */
    auto s_b_21_4 = emitter.cmp_lt(s_b_21_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:2067 [D] s_b_21_5 = (v16u8)s_b_21_4 */
    auto s_b_21_5 = emitter.reinterpret(s_b_21_4, emitter.context().types().v16u8());
    /* execute.simd:2068 [F] s_b_21_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2068 [D] s_b_21_7: WriteRegBank 16:s_b_21_6 = s_b_21_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_21_5,emitter.const_u8(16));
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
    /* execute.simd:2073 [F] s_b_22_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2073 [D] s_b_22_1 = ReadRegBank 17:s_b_22_0 (v4u16) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:2073 [D] s_b_22_2 = (v4s16)s_b_22_1 */
    auto s_b_22_2 = emitter.reinterpret(s_b_22_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_22_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:2075 [D] s_b_22_4 = s_b_22_2<s_b_22_3 */
    auto s_b_22_4 = emitter.cmp_lt(s_b_22_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:2075 [D] s_b_22_5 = (v4u16)s_b_22_4 */
    auto s_b_22_5 = emitter.reinterpret(s_b_22_4, emitter.context().types().v4u16());
    /* execute.simd:2076 [F] s_b_22_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2076 [D] s_b_22_7: WriteRegBank 17:s_b_22_6 = s_b_22_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5);
    /* execute.simd:2077 [F] s_b_22_8=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2077 [F] s_b_22_9 = constant u64 0 (const) */
    /* execute.simd:2077 [F] s_b_22_10: WriteRegBank 3:s_b_22_8 = s_b_22_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:2082 [F] s_b_23_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2082 [D] s_b_23_1 = ReadRegBank 18:s_b_23_0 (v8u16) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:2082 [D] s_b_23_2 = (v8s16)s_b_23_1 */
    auto s_b_23_2 = emitter.reinterpret(s_b_23_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_23_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:2084 [D] s_b_23_4 = s_b_23_2<s_b_23_3 */
    auto s_b_23_4 = emitter.cmp_lt(s_b_23_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:2084 [D] s_b_23_5 = (v8u16)s_b_23_4 */
    auto s_b_23_5 = emitter.reinterpret(s_b_23_4, emitter.context().types().v8u16());
    /* execute.simd:2086 [F] s_b_23_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2086 [D] s_b_23_7: WriteRegBank 18:s_b_23_6 = s_b_23_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_23_5,emitter.const_u8(16));
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
    /* execute.simd:2090 [F] s_b_24_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2090 [D] s_b_24_1 = ReadRegBank 19:s_b_24_0 (v2u32) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_24_1,emitter.const_u8(8));
    }
    /* execute.simd:2090 [D] s_b_24_2 = (v2s32)s_b_24_1 */
    auto s_b_24_2 = emitter.reinterpret(s_b_24_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_24_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:2092 [D] s_b_24_4 = s_b_24_2<s_b_24_3 */
    auto s_b_24_4 = emitter.cmp_lt(s_b_24_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:2092 [D] s_b_24_5 = (v2u32)s_b_24_4 */
    auto s_b_24_5 = emitter.reinterpret(s_b_24_4, emitter.context().types().v2u32());
    /* execute.simd:2093 [F] s_b_24_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2093 [D] s_b_24_7: WriteRegBank 19:s_b_24_6 = s_b_24_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5);
    /* execute.simd:2094 [F] s_b_24_8=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2094 [F] s_b_24_9 = constant u64 0 (const) */
    /* execute.simd:2094 [F] s_b_24_10: WriteRegBank 3:s_b_24_8 = s_b_24_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:2099 [F] s_b_25_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2099 [D] s_b_25_1 = ReadRegBank 20:s_b_25_0 (v4u32) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_25_1,emitter.const_u8(16));
    }
    /* execute.simd:2099 [D] s_b_25_2 = (v4s32)s_b_25_1 */
    auto s_b_25_2 = emitter.reinterpret(s_b_25_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_25_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:2101 [D] s_b_25_4 = s_b_25_2<s_b_25_3 */
    auto s_b_25_4 = emitter.cmp_lt(s_b_25_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:2101 [D] s_b_25_5 = (v4u32)s_b_25_4 */
    auto s_b_25_5 = emitter.reinterpret(s_b_25_4, emitter.context().types().v4u32());
    /* execute.simd:2103 [F] s_b_25_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2103 [D] s_b_25_7: WriteRegBank 20:s_b_25_6 = s_b_25_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_25_5,emitter.const_u8(16));
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
    /* execute.simd:2107 [F] s_b_26_0=sym_7967_3_parameter_inst.rn (const) */
    /* execute.simd:2107 [D] s_b_26_1 = ReadRegBank 21:s_b_26_0 (v2u64) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_26_1,emitter.const_u8(16));
    }
    /* execute.simd:2107 [D] s_b_26_2 = (v2s64)s_b_26_1 */
    auto s_b_26_2 = emitter.reinterpret(s_b_26_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_26_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:2109 [D] s_b_26_4 = s_b_26_2<s_b_26_3 */
    auto s_b_26_4 = emitter.cmp_lt(s_b_26_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:2109 [D] s_b_26_5 = (v2u64)s_b_26_4 */
    auto s_b_26_5 = emitter.reinterpret(s_b_26_4, emitter.context().types().v2u64());
    /* execute.simd:2111 [F] s_b_26_6=sym_7967_3_parameter_inst.rd (const) */
    /* execute.simd:2111 [D] s_b_26_7: WriteRegBank 21:s_b_26_6 = s_b_26_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_26_5,emitter.const_u8(16));
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
    /* execute.simd:2115 [D] s_b_27_0 = trap */
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
        /* execute.simd:1975 [F] s_b_6_0=sym_7967_3_parameter_inst.rd (const) */
        /* execute.simd:1975 [F] s_b_6_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6208 [F] s_b_6_2: WriteRegBank 2:s_b_6_0 = s_b_6_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6209 [F] s_b_6_3 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_6_4: WriteRegBank 3:s_b_6_0 = s_b_6_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
        /* execute.simd:1977 [F] s_b_7_0=sym_7967_3_parameter_inst.rd (const) */
        /* execute.simd:1977 [F] s_b_7_1 = constant u64 0 (const) */
        /* execute.simd:6208 [F] s_b_7_2: WriteRegBank 2:s_b_7_0 = s_b_7_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6209 [F] s_b_7_3 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_7_4: WriteRegBank 3:s_b_7_0 = s_b_7_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
        /* execute.simd:1981 [F] s_b_8_0=sym_7967_3_parameter_inst.rd (const) */
        /* execute.simd:1981 [F] s_b_8_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6208 [F] s_b_8_2: WriteRegBank 2:s_b_8_0 = s_b_8_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6209 [F] s_b_8_3 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_8_4: WriteRegBank 3:s_b_8_0 = s_b_8_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
        /* execute.simd:1983 [F] s_b_9_0=sym_7967_3_parameter_inst.rd (const) */
        /* execute.simd:1983 [F] s_b_9_1 = constant u64 0 (const) */
        /* execute.simd:6208 [F] s_b_9_2: WriteRegBank 2:s_b_9_0 = s_b_9_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6209 [F] s_b_9_3 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_9_4: WriteRegBank 3:s_b_9_0 = s_b_9_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_csneg(const arm64_decode_a64_COND_SEL&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_58451_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58385_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58302_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58429_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58407_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58330_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  uint8_t CV_sym_58070_0_state;
  auto DV_sym_58070_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_58355_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58273_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58195_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58164_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58220_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58113_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_58248_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2180 [F] s_b_0_0=sym_9072_3_parameter_inst.cond (const) */
    /* execute.a64:2832 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2832 [F] s_b_0_2: sym_58070_0_state = s_b_0_1 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_58070_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_58070_0_state, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2834 [F] s_b_0_3 = (u32)s_b_0_0 (const) */
    /* execute.a64:2834 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:2834 [F] s_b_0_5 = s_b_0_3>>s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(((uint32_t)insn.cond) >> (uint32_t)1ULL));
    /* execute.a64:2835 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.a64:2839 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.a64:2843 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.a64:2847 [F] s_b_0_9 = constant s32 3 (const) */
    /* execute.a64:2851 [F] s_b_0_10 = constant s32 4 (const) */
    /* execute.a64:2855 [F] s_b_0_11 = constant s32 5 (const) */
    /* execute.a64:2859 [F] s_b_0_12 = constant s32 6 (const) */
    /* execute.a64:2863 [F] s_b_0_13 = constant s32 7 (const) */
    /* execute.a64:2834 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_4 (const) -> b_8, b_9, b_10, b_11, b_12, b_13, b_14, b_4, b_7,  */
    switch (s_b_0_5) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_11;
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
    /* execute.a64:2869 [F] s_b_4_0=sym_9072_3_parameter_inst.cond (const) */
    /* execute.a64:2869 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2869 [F] s_b_4_2 = constant u32 1 (const) */
    /* execute.a64:2869 [F] s_b_4_3 = s_b_4_1&s_b_4_2 (const) */
    uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2869 [F] s_b_4_4 = constant u32 1 (const) */
    /* execute.a64:2869 [F] s_b_4_5 = s_b_4_3==s_b_4_4 (const) */
    uint8_t s_b_4_5 = ((uint8_t)(s_b_4_3 == (uint32_t)1ULL));
    /* execute.a64:2869 [F] s_b_4_6 = (u32)s_b_4_0 (const) */
    /* execute.a64:2869 [F] s_b_4_7 = constant u32 f (const) */
    /* execute.a64:2869 [F] s_b_4_8 = s_b_4_6!=s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.cond) != (uint32_t)15ULL));
    /* ???:4294967295 [F] s_b_4_9 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_4_10 = s_b_4_5!=s_b_4_9 (const) */
    uint8_t s_b_4_10 = ((uint8_t)(s_b_4_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_11 = s_b_4_8!=s_b_4_9 (const) */
    uint8_t s_b_4_11 = ((uint8_t)(s_b_4_8 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_12 = s_b_4_10&s_b_4_11 (const) */
    uint8_t s_b_4_12 = ((uint8_t)(s_b_4_10 & s_b_4_11));
    /* execute.a64:2869 [F] s_b_4_13: If s_b_4_12: Jump b_5 else b_6 (const) */
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
    /* execute.a64:2870 [D] s_b_5_0 = sym_58070_0_state uint8_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_58070_0_state, emitter.context().types().u8());
    /* execute.a64:2870 [D] s_b_5_1 = !s_b_5_0 */
    auto s_b_5_1 = emitter.cmp_eq(s_b_5_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_5_2: sym_58113_0_return_symbol = s_b_5_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_58113_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2872 [D] s_b_6_0 = sym_58070_0_state uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_58070_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_6_1: sym_58113_0_return_symbol = s_b_6_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_58113_0_return_symbol, s_b_6_0);
    /* ???:4294967295 [F] s_b_6_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2836 [D] s_b_7_0 = ReadReg 2 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2836 [D] s_b_7_1: sym_58070_0_state = s_b_7_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58070_0_state, s_b_7_0);
    /* execute.a64:0 [F] s_b_7_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2840 [D] s_b_8_0 = ReadReg 3 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2840 [D] s_b_8_1: sym_58070_0_state = s_b_8_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58070_0_state, s_b_8_0);
    /* execute.a64:0 [F] s_b_8_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2844 [D] s_b_9_0 = ReadReg 1 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2844 [D] s_b_9_1: sym_58070_0_state = s_b_9_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58070_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2848 [D] s_b_10_0 = ReadReg 4 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2848 [D] s_b_10_1: sym_58070_0_state = s_b_10_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58070_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2852 [D] s_b_11_0 = ReadReg 3 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2852 [D] s_b_11_1 = ReadReg 2 (u8) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_11_1, emitter.const_u8(1));
    }
    /* execute.a64:2852 [D] s_b_11_2 = !s_b_11_1 */
    auto s_b_11_2 = emitter.cmp_eq(s_b_11_1, emitter.const_u8(0));
    /* execute.a64:2852 [D] s_b_11_3 = s_b_11_0&s_b_11_2 */
    auto s_b_11_3 = emitter.bitwise_and(s_b_11_0, s_b_11_2);
    /* execute.a64:2852 [D] s_b_11_4: sym_58070_0_state = s_b_11_3, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58070_0_state, s_b_11_3);
    /* execute.a64:0 [F] s_b_11_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2856 [D] s_b_12_0 = ReadReg 1 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2856 [D] s_b_12_1 = ReadReg 4 (u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_12_1, emitter.const_u8(1));
    }
    /* execute.a64:2856 [D] s_b_12_2 = s_b_12_0==s_b_12_1 */
    auto s_b_12_2 = emitter.cmp_eq(s_b_12_0, s_b_12_1);
    /* execute.a64:2856 [D] s_b_12_3: sym_58070_0_state = s_b_12_2, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58070_0_state, s_b_12_2);
    /* execute.a64:0 [F] s_b_12_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2860 [D] s_b_13_0 = ReadReg 1 (u8) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2860 [D] s_b_13_1 = ReadReg 4 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_13_1, emitter.const_u8(1));
    }
    /* execute.a64:2860 [D] s_b_13_2 = s_b_13_0==s_b_13_1 */
    auto s_b_13_2 = emitter.cmp_eq(s_b_13_0, s_b_13_1);
    /* execute.a64:2860 [D] s_b_13_3 = ReadReg 2 (u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_13_3, emitter.const_u8(1));
    }
    /* execute.a64:2860 [D] s_b_13_4 = !s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_eq(s_b_13_3, emitter.const_u8(0));
    /* execute.a64:2860 [D] s_b_13_5 = s_b_13_2&s_b_13_4 */
    auto s_b_13_5 = emitter.bitwise_and(s_b_13_2, s_b_13_4);
    /* execute.a64:2860 [D] s_b_13_6: sym_58070_0_state = s_b_13_5, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58070_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2864 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2864 [F] s_b_14_1: sym_58070_0_state = s_b_14_0 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_58070_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_58070_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5, b_6,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_58113_0_return_symbol uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_58113_0_return_symbol, emitter.context().types().u8());
    /* execute.a64:2182 [D] s_b_15_1 = (u32)s_b_15_0 */
    auto s_b_15_1 = emitter.zx(s_b_15_0, emitter.context().types().u32());
    /* execute.a64:2182 [F] s_b_15_2 = constant u32 0 (const) */
    /* execute.a64:2182 [D] s_b_15_3 = s_b_15_1==s_b_15_2 */
    auto s_b_15_3 = emitter.cmp_eq(s_b_15_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2182 [D] s_b_15_4: If s_b_15_3: Jump b_1 else b_3 */
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
        /* execute.a64:2183 [F] s_b_1_0=sym_9072_3_parameter_inst.sf (const) */
        /* execute.a64:2697 [F] s_b_1_1: If s_b_1_0: Jump b_16 else b_17 (const) */
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
        /* execute.a64:2185 [F] s_b_3_0=sym_9072_3_parameter_inst.sf (const) */
        /* execute.a64:2697 [F] s_b_3_1: If s_b_3_0: Jump b_19 else b_20 (const) */
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
        /* execute.a64:2698 [F] s_b_16_0=sym_9072_3_parameter_inst.rm (const) */
        /* execute.a64:2692 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
        /* execute.a64:2692 [F] s_b_16_2 = constant u32 1f (const) */
        /* execute.a64:2692 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
        uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2692 [F] s_b_16_4: If s_b_16_3: Jump b_22 else b_23 (const) */
        if (s_b_16_3) 
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
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.a64:2700 [F] s_b_17_0=sym_9072_3_parameter_inst.rm (const) */
        /* execute.a64:2687 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
        /* execute.a64:2687 [F] s_b_17_2 = constant u32 1f (const) */
        /* execute.a64:2687 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
        uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2687 [F] s_b_17_4: If s_b_17_3: Jump b_25 else b_26 (const) */
        if (s_b_17_3) 
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* ???:4294967295 [F] s_b_18_0=sym_9072_3_parameter_inst.sf (const) */
        /* execute.a64:2183 [D] s_b_18_1 = sym_58164_1__R_s_b_1_6 uint64_t */
        auto s_b_18_1 = emitter.load_local(DV_sym_58164_1__R_s_b_1_6, emitter.context().types().u64());
        /* execute.a64:2183 [D] s_b_18_2 = ~s_b_18_1 */
        auto s_b_18_2 = emitter.bitwise_not(s_b_18_1);
        /* execute.a64:2183 [F] s_b_18_3 = constant u64 1 (const) */
        /* execute.a64:2183 [D] s_b_18_4 = s_b_18_2+s_b_18_3 */
        auto s_b_18_4 = emitter.add(s_b_18_2, emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:2183 [D] s_b_18_5: sym_58273_3_parameter_value = s_b_18_4, dominates: s_b_28_1 s_b_29_1  */
        emitter.store_local(DV_sym_58273_3_parameter_value, s_b_18_4);
        /* execute.a64:2731 [F] s_b_18_6: If s_b_18_0: Jump b_28 else b_29 (const) */
        if (insn.sf) 
        {
          auto block = block_b_28;
          dynamic_block_queue.push(block_b_28);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.a64:2698 [F] s_b_19_0=sym_9072_3_parameter_inst.rn (const) */
        /* execute.a64:2692 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.a64:2692 [F] s_b_19_2 = constant u32 1f (const) */
        /* execute.a64:2692 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
        uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2692 [F] s_b_19_4: If s_b_19_3: Jump b_30 else b_31 (const) */
        if (s_b_19_3) 
        {
          auto block = block_b_30;
          dynamic_block_queue.push(block_b_30);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.a64:2700 [F] s_b_20_0=sym_9072_3_parameter_inst.rn (const) */
        /* execute.a64:2687 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
        /* execute.a64:2687 [F] s_b_20_2 = constant u32 1f (const) */
        /* execute.a64:2687 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
        uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2687 [F] s_b_20_4: If s_b_20_3: Jump b_33 else b_34 (const) */
        if (s_b_20_3) 
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_34;
          dynamic_block_queue.push(block_b_34);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* ???:4294967295 [F] s_b_21_0=sym_9072_3_parameter_inst.sf (const) */
        /* execute.a64:2185 [D] s_b_21_1 = sym_58195_1__R_s_b_3_6 uint64_t */
        auto s_b_21_1 = emitter.load_local(DV_sym_58195_1__R_s_b_3_6, emitter.context().types().u64());
        /* execute.a64:2185 [D] s_b_21_2: sym_58355_3_parameter_value = s_b_21_1, dominates: s_b_36_1 s_b_37_1  */
        emitter.store_local(DV_sym_58355_3_parameter_value, s_b_21_1);
        /* execute.a64:2731 [F] s_b_21_3: If s_b_21_0: Jump b_36 else b_37 (const) */
        if (insn.sf) 
        {
          auto block = block_b_36;
          dynamic_block_queue.push(block_b_36);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.a64:2692 [F] s_b_22_0 = constant u64 0 (const) */
        /* execute.a64:2692 [D] s_b_22_1: sym_58220_1_temporary_value = s_b_22_0, dominates: s_b_24_0  */
        emitter.store_local(DV_sym_58220_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2692 [F] s_b_22_2: Jump b_24 (const) */
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.a64:2692 [F] s_b_23_0=sym_9072_3_parameter_inst.rm (const) */
        /* execute.a64:2692 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
        auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_23_1,emitter.const_u8(8));
        }
        /* execute.a64:2692 [D] s_b_23_2: sym_58220_1_temporary_value = s_b_23_1, dominates: s_b_24_0  */
        emitter.store_local(DV_sym_58220_1_temporary_value, s_b_23_1);
        /* execute.a64:2692 [F] s_b_23_3: Jump b_24 (const) */
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.a64:2692 [D] s_b_24_0 = sym_58220_1_temporary_value uint64_t */
        auto s_b_24_0 = emitter.load_local(DV_sym_58220_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2698 [D] s_b_24_1: sym_58164_1__R_s_b_1_6 = s_b_24_0, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_58164_1__R_s_b_1_6, s_b_24_0);
        /* execute.a64:2698 [F] s_b_24_2: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.a64:2687 [F] s_b_25_0 = constant u32 0 (const) */
        /* execute.a64:2687 [D] s_b_25_1: sym_58248_1_temporary_value = s_b_25_0, dominates: s_b_27_0  */
        emitter.store_local(DV_sym_58248_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2687 [F] s_b_25_2: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.a64:2687 [F] s_b_26_0=sym_9072_3_parameter_inst.rm (const) */
        /* execute.a64:2687 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
        auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_1,emitter.const_u8(4));
        }
        /* execute.a64:2687 [D] s_b_26_2: sym_58248_1_temporary_value = s_b_26_1, dominates: s_b_27_0  */
        emitter.store_local(DV_sym_58248_1_temporary_value, s_b_26_1);
        /* execute.a64:2687 [F] s_b_26_3: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.a64:2687 [D] s_b_27_0 = sym_58248_1_temporary_value uint32_t */
        auto s_b_27_0 = emitter.load_local(DV_sym_58248_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2700 [D] s_b_27_1 = (u64)s_b_27_0 */
        auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
        /* execute.a64:2700 [D] s_b_27_2: sym_58164_1__R_s_b_1_6 = s_b_27_1, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_58164_1__R_s_b_1_6, s_b_27_1);
        /* execute.a64:2700 [F] s_b_27_3: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.a64:2732 [F] s_b_28_0=sym_9072_3_parameter_inst.rd (const) */
        /* execute.a64:2732 [D] s_b_28_1 = sym_58273_3_parameter_value uint64_t */
        auto s_b_28_1 = emitter.load_local(DV_sym_58273_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2732 [D] s_b_28_2: sym_58385_3_parameter_value = s_b_28_1, dominates: s_b_38_1  */
        emitter.store_local(DV_sym_58385_3_parameter_value, s_b_28_1);
        /* execute.a64:2723 [F] s_b_28_3 = (u32)s_b_28_0 (const) */
        /* execute.a64:2723 [F] s_b_28_4 = constant u32 1f (const) */
        /* execute.a64:2723 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
        uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2723 [F] s_b_28_6: If s_b_28_5: Jump b_2 else b_38 (const) */
        if (s_b_28_5) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_38;
          dynamic_block_queue.push(block_b_38);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.a64:2734 [F] s_b_29_0=sym_9072_3_parameter_inst.rd (const) */
        /* execute.a64:2734 [D] s_b_29_1 = sym_58273_3_parameter_value uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_58273_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2734 [D] s_b_29_2 = (u32)s_b_29_1 */
        auto s_b_29_2 = emitter.truncate(s_b_29_1, emitter.context().types().u32());
        /* execute.a64:2734 [D] s_b_29_3 = (u64)s_b_29_2 */
        auto s_b_29_3 = emitter.zx(s_b_29_2, emitter.context().types().u64());
        /* execute.a64:2734 [D] s_b_29_4: sym_58407_3_parameter_value = s_b_29_3, dominates: s_b_39_1  */
        emitter.store_local(DV_sym_58407_3_parameter_value, s_b_29_3);
        /* execute.a64:2723 [F] s_b_29_5 = (u32)s_b_29_0 (const) */
        /* execute.a64:2723 [F] s_b_29_6 = constant u32 1f (const) */
        /* execute.a64:2723 [F] s_b_29_7 = s_b_29_5==s_b_29_6 (const) */
        uint8_t s_b_29_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2723 [F] s_b_29_8: If s_b_29_7: Jump b_2 else b_39 (const) */
        if (s_b_29_7) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_39;
          dynamic_block_queue.push(block_b_39);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.a64:2692 [F] s_b_30_0 = constant u64 0 (const) */
        /* execute.a64:2692 [D] s_b_30_1: sym_58302_1_temporary_value = s_b_30_0, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_58302_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2692 [F] s_b_30_2: Jump b_32 (const) */
        {
          auto block = block_b_32;
          dynamic_block_queue.push(block_b_32);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.a64:2692 [F] s_b_31_0=sym_9072_3_parameter_inst.rn (const) */
        /* execute.a64:2692 [D] s_b_31_1 = ReadRegBank 0:s_b_31_0 (u64) */
        auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_31_1,emitter.const_u8(8));
        }
        /* execute.a64:2692 [D] s_b_31_2: sym_58302_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_58302_1_temporary_value, s_b_31_1);
        /* execute.a64:2692 [F] s_b_31_3: Jump b_32 (const) */
        {
          auto block = block_b_32;
          dynamic_block_queue.push(block_b_32);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.a64:2692 [D] s_b_32_0 = sym_58302_1_temporary_value uint64_t */
        auto s_b_32_0 = emitter.load_local(DV_sym_58302_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2698 [D] s_b_32_1: sym_58195_1__R_s_b_3_6 = s_b_32_0, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_58195_1__R_s_b_3_6, s_b_32_0);
        /* execute.a64:2698 [F] s_b_32_2: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.a64:2687 [F] s_b_33_0 = constant u32 0 (const) */
        /* execute.a64:2687 [D] s_b_33_1: sym_58330_1_temporary_value = s_b_33_0, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_58330_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2687 [F] s_b_33_2: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.a64:2687 [F] s_b_34_0=sym_9072_3_parameter_inst.rn (const) */
        /* execute.a64:2687 [D] s_b_34_1 = ReadRegBank 1:s_b_34_0 (u32) */
        auto s_b_34_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_34_1,emitter.const_u8(4));
        }
        /* execute.a64:2687 [D] s_b_34_2: sym_58330_1_temporary_value = s_b_34_1, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_58330_1_temporary_value, s_b_34_1);
        /* execute.a64:2687 [F] s_b_34_3: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.a64:2687 [D] s_b_35_0 = sym_58330_1_temporary_value uint32_t */
        auto s_b_35_0 = emitter.load_local(DV_sym_58330_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2700 [D] s_b_35_1 = (u64)s_b_35_0 */
        auto s_b_35_1 = emitter.zx(s_b_35_0, emitter.context().types().u64());
        /* execute.a64:2700 [D] s_b_35_2: sym_58195_1__R_s_b_3_6 = s_b_35_1, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_58195_1__R_s_b_3_6, s_b_35_1);
        /* execute.a64:2700 [F] s_b_35_3: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_36) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_36);
        /* execute.a64:2732 [F] s_b_36_0=sym_9072_3_parameter_inst.rd (const) */
        /* execute.a64:2732 [D] s_b_36_1 = sym_58355_3_parameter_value uint64_t */
        auto s_b_36_1 = emitter.load_local(DV_sym_58355_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2732 [D] s_b_36_2: sym_58429_3_parameter_value = s_b_36_1, dominates: s_b_40_1  */
        emitter.store_local(DV_sym_58429_3_parameter_value, s_b_36_1);
        /* execute.a64:2723 [F] s_b_36_3 = (u32)s_b_36_0 (const) */
        /* execute.a64:2723 [F] s_b_36_4 = constant u32 1f (const) */
        /* execute.a64:2723 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
        uint8_t s_b_36_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2723 [F] s_b_36_6: If s_b_36_5: Jump b_2 else b_40 (const) */
        if (s_b_36_5) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_40;
          dynamic_block_queue.push(block_b_40);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.a64:2734 [F] s_b_37_0=sym_9072_3_parameter_inst.rd (const) */
        /* execute.a64:2734 [D] s_b_37_1 = sym_58355_3_parameter_value uint64_t */
        auto s_b_37_1 = emitter.load_local(DV_sym_58355_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2734 [D] s_b_37_2 = (u32)s_b_37_1 */
        auto s_b_37_2 = emitter.truncate(s_b_37_1, emitter.context().types().u32());
        /* execute.a64:2734 [D] s_b_37_3 = (u64)s_b_37_2 */
        auto s_b_37_3 = emitter.zx(s_b_37_2, emitter.context().types().u64());
        /* execute.a64:2734 [D] s_b_37_4: sym_58451_3_parameter_value = s_b_37_3, dominates: s_b_41_1  */
        emitter.store_local(DV_sym_58451_3_parameter_value, s_b_37_3);
        /* execute.a64:2723 [F] s_b_37_5 = (u32)s_b_37_0 (const) */
        /* execute.a64:2723 [F] s_b_37_6 = constant u32 1f (const) */
        /* execute.a64:2723 [F] s_b_37_7 = s_b_37_5==s_b_37_6 (const) */
        uint8_t s_b_37_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2723 [F] s_b_37_8: If s_b_37_7: Jump b_2 else b_41 (const) */
        if (s_b_37_7) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_38) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_38);
        /* execute.a64:2725 [F] s_b_38_0=sym_9072_3_parameter_inst.rd (const) */
        /* execute.a64:2725 [D] s_b_38_1 = sym_58385_3_parameter_value uint64_t */
        auto s_b_38_1 = emitter.load_local(DV_sym_58385_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2725 [D] s_b_38_2: WriteRegBank 0:s_b_38_0 = s_b_38_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_38_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_38_1);
        /* execute.a64:0 [F] s_b_38_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.a64:2725 [F] s_b_39_0=sym_9072_3_parameter_inst.rd (const) */
        /* execute.a64:2725 [D] s_b_39_1 = sym_58407_3_parameter_value uint64_t */
        auto s_b_39_1 = emitter.load_local(DV_sym_58407_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2725 [D] s_b_39_2: WriteRegBank 0:s_b_39_0 = s_b_39_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_39_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_39_1);
        /* execute.a64:0 [F] s_b_39_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_40) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_40);
        /* execute.a64:2725 [F] s_b_40_0=sym_9072_3_parameter_inst.rd (const) */
        /* execute.a64:2725 [D] s_b_40_1 = sym_58429_3_parameter_value uint64_t */
        auto s_b_40_1 = emitter.load_local(DV_sym_58429_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2725 [D] s_b_40_2: WriteRegBank 0:s_b_40_0 = s_b_40_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_40_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_40_1);
        /* execute.a64:0 [F] s_b_40_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.a64:2725 [F] s_b_41_0=sym_9072_3_parameter_inst.rd (const) */
        /* execute.a64:2725 [D] s_b_41_1 = sym_58451_3_parameter_value uint64_t */
        auto s_b_41_1 = emitter.load_local(DV_sym_58451_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2725 [D] s_b_41_2: WriteRegBank 0:s_b_41_0 = s_b_41_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_41_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_41_1);
        /* execute.a64:0 [F] s_b_41_3: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_exgen(const arm64_decode_a64_EX_GEN&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  emitter.mark_used_feature(4);
  emitter.mark_used_feature(5);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_60178_0_spsr = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_60190_3_parameter_voff;
  auto DV_sym_60110_0_spsr = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_60058_0_parameter_voff;
  auto DV_sym_60056_0_parameter_retaddr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_60054_0_parameter_syndrome;
  auto DV_sym_60228_3_parameter_retaddr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_60279_3_parameter_syndrome;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:356 [F] s_b_0_0=sym_10015_3_parameter_inst.opc (const) */
    /* execute.a64:356 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:356 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.a64:356 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:356 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.a64:357 [F] s_b_1_0=sym_10015_3_parameter_inst.imm16 (const) */
    /* execute.a64:2911 [D] s_b_1_1 = read_pc */
    auto s_b_1_1 = emitter.load_pc();
    /* execute.a64:2912 [F] s_b_1_2 = constant u64 0 (const) */
    /* execute.a64:2914 [F] s_b_1_3 = constant u8 1 (const) */
    /* execute.a64:2914 [F] s_b_1_4 = (u32)s_b_1_0 (const) */
    /* execute.a64:2914 [F] s_b_1_5: sym_60279_3_parameter_syndrome = s_b_1_4 (const), dominates: s_b_21_11  */
    CV_sym_60279_3_parameter_syndrome = ((uint32_t)insn.imm16);
    /* execute.a64:2914 [D] s_b_1_6: sym_60228_3_parameter_retaddr = s_b_1_1, dominates: s_b_21_8  */
    emitter.store_local(DV_sym_60228_3_parameter_retaddr, s_b_1_1);
    /* execute.a64:2914 [F] s_b_1_7: sym_60190_3_parameter_voff = s_b_1_2 (const), dominates: s_b_19_0 s_b_22_0 s_b_21_25  */
    CV_sym_60190_3_parameter_voff = (uint64_t)0ULL;
    /* execute.a64:2878 [D] s_b_1_8 = ReadReg 1 (u8) */
    auto s_b_1_8 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_1_8, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_1_9 = (u32)s_b_1_8 */
    auto s_b_1_9 = emitter.zx(s_b_1_8, emitter.context().types().u32());
    /* execute.a64:2878 [F] s_b_1_10 = constant u32 1f (const) */
    /* execute.a64:2878 [D] s_b_1_11 = s_b_1_9<<s_b_1_10 */
    auto s_b_1_11 = emitter.shl(s_b_1_9, emitter.const_u32((uint32_t)31ULL));
    /* execute.a64:2879 [D] s_b_1_12 = ReadReg 2 (u8) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_1_12, emitter.const_u8(1));
    }
    /* execute.a64:2879 [D] s_b_1_13 = (u32)s_b_1_12 */
    auto s_b_1_13 = emitter.zx(s_b_1_12, emitter.context().types().u32());
    /* execute.a64:2879 [F] s_b_1_14 = constant u32 1e (const) */
    /* execute.a64:2879 [D] s_b_1_15 = s_b_1_13<<s_b_1_14 */
    auto s_b_1_15 = emitter.shl(s_b_1_13, emitter.const_u32((uint32_t)30ULL));
    /* execute.a64:2878 [D] s_b_1_16 = s_b_1_11|s_b_1_15 */
    auto s_b_1_16 = emitter.bitwise_or(s_b_1_11, s_b_1_15);
    /* execute.a64:2880 [D] s_b_1_17 = ReadReg 3 (u8) */
    auto s_b_1_17 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_1_17, emitter.const_u8(1));
    }
    /* execute.a64:2880 [D] s_b_1_18 = (u32)s_b_1_17 */
    auto s_b_1_18 = emitter.zx(s_b_1_17, emitter.context().types().u32());
    /* execute.a64:2880 [F] s_b_1_19 = constant u32 1d (const) */
    /* execute.a64:2880 [D] s_b_1_20 = s_b_1_18<<s_b_1_19 */
    auto s_b_1_20 = emitter.shl(s_b_1_18, emitter.const_u32((uint32_t)29ULL));
    /* execute.a64:2879 [D] s_b_1_21 = s_b_1_16|s_b_1_20 */
    auto s_b_1_21 = emitter.bitwise_or(s_b_1_16, s_b_1_20);
    /* execute.a64:2881 [D] s_b_1_22 = ReadReg 4 (u8) */
    auto s_b_1_22 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_1_22, emitter.const_u8(1));
    }
    /* execute.a64:2881 [D] s_b_1_23 = (u32)s_b_1_22 */
    auto s_b_1_23 = emitter.zx(s_b_1_22, emitter.context().types().u32());
    /* execute.a64:2881 [F] s_b_1_24 = constant u32 1c (const) */
    /* execute.a64:2881 [D] s_b_1_25 = s_b_1_23<<s_b_1_24 */
    auto s_b_1_25 = emitter.shl(s_b_1_23, emitter.const_u32((uint32_t)28ULL));
    /* execute.a64:2880 [D] s_b_1_26 = s_b_1_21|s_b_1_25 */
    auto s_b_1_26 = emitter.bitwise_or(s_b_1_21, s_b_1_25);
    /* execute.a64:2882 [D] s_b_1_27 = ReadReg 5 (u8) */
    auto s_b_1_27 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_1_27, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_1_28 = (u32)s_b_1_27 */
    auto s_b_1_28 = emitter.zx(s_b_1_27, emitter.context().types().u32());
    /* execute.a64:2882 [F] s_b_1_29 = constant u32 9 (const) */
    /* execute.a64:2882 [D] s_b_1_30 = s_b_1_28<<s_b_1_29 */
    auto s_b_1_30 = emitter.shl(s_b_1_28, emitter.const_u32((uint32_t)9ULL));
    /* execute.a64:2881 [D] s_b_1_31 = s_b_1_26|s_b_1_30 */
    auto s_b_1_31 = emitter.bitwise_or(s_b_1_26, s_b_1_30);
    /* execute.a64:2883 [D] s_b_1_32 = ReadReg 6 (u8) */
    auto s_b_1_32 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_1_32, emitter.const_u8(1));
    }
    /* execute.a64:2883 [D] s_b_1_33 = (u32)s_b_1_32 */
    auto s_b_1_33 = emitter.zx(s_b_1_32, emitter.context().types().u32());
    /* execute.a64:2883 [F] s_b_1_34 = constant u32 8 (const) */
    /* execute.a64:2883 [D] s_b_1_35 = s_b_1_33<<s_b_1_34 */
    auto s_b_1_35 = emitter.shl(s_b_1_33, emitter.const_u32((uint32_t)8ULL));
    /* execute.a64:2882 [D] s_b_1_36 = s_b_1_31|s_b_1_35 */
    auto s_b_1_36 = emitter.bitwise_or(s_b_1_31, s_b_1_35);
    /* execute.a64:2884 [D] s_b_1_37 = ReadReg 7 (u8) */
    auto s_b_1_37 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_1_37, emitter.const_u8(1));
    }
    /* execute.a64:2884 [D] s_b_1_38 = (u32)s_b_1_37 */
    auto s_b_1_38 = emitter.zx(s_b_1_37, emitter.context().types().u32());
    /* execute.a64:2884 [F] s_b_1_39 = constant u32 7 (const) */
    /* execute.a64:2884 [D] s_b_1_40 = s_b_1_38<<s_b_1_39 */
    auto s_b_1_40 = emitter.shl(s_b_1_38, emitter.const_u32((uint32_t)7ULL));
    /* execute.a64:2883 [D] s_b_1_41 = s_b_1_36|s_b_1_40 */
    auto s_b_1_41 = emitter.bitwise_or(s_b_1_36, s_b_1_40);
    /* execute.a64:2885 [D] s_b_1_42 = ReadReg 8 (u8) */
    auto s_b_1_42 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_1_42, emitter.const_u8(1));
    }
    /* execute.a64:2885 [D] s_b_1_43 = (u32)s_b_1_42 */
    auto s_b_1_43 = emitter.zx(s_b_1_42, emitter.context().types().u32());
    /* execute.a64:2885 [F] s_b_1_44 = constant u32 6 (const) */
    /* execute.a64:2885 [D] s_b_1_45 = s_b_1_43<<s_b_1_44 */
    auto s_b_1_45 = emitter.shl(s_b_1_43, emitter.const_u32((uint32_t)6ULL));
    /* execute.a64:2884 [D] s_b_1_46 = s_b_1_41|s_b_1_45 */
    auto s_b_1_46 = emitter.bitwise_or(s_b_1_41, s_b_1_45);
    /* execute.a64:3053 [F] s_b_1_47 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_1_48 = __builtin_get_feature */
    uint32_t s_b_1_48 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_1_49 = (u8)s_b_1_48 (const) */
    /* execute.a64:2886 [F] s_b_1_50 = (u32)s_b_1_49 (const) */
    /* execute.a64:2886 [F] s_b_1_51 = constant u32 2 (const) */
    /* execute.a64:2886 [F] s_b_1_52 = s_b_1_50<<s_b_1_51 (const) */
    uint32_t s_b_1_52 = ((uint32_t)(((uint32_t)((uint8_t)s_b_1_48)) << (uint32_t)2ULL));
    /* execute.a64:2885 [D] s_b_1_53 = s_b_1_46|s_b_1_52 */
    auto s_b_1_53 = emitter.bitwise_or(s_b_1_46, emitter.const_u32(s_b_1_52));
    /* execute.a64:2887 [F] s_b_1_54 = constant u32 1 (const) */
    /* execute.a64:2887 [F] s_b_1_55 = __builtin_get_feature */
    uint32_t s_b_1_55 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2887 [F] s_b_1_56 = (u32)s_b_1_55 (const) */
    /* execute.a64:2886 [D] s_b_1_57 = s_b_1_53|s_b_1_56 */
    auto s_b_1_57 = emitter.bitwise_or(s_b_1_53, emitter.const_u32(((uint32_t)s_b_1_55)));
    /* execute.a64:3000 [D] s_b_1_58: sym_60178_0_spsr = s_b_1_57, dominates: s_b_21_6  */
    emitter.store_local(DV_sym_60178_0_spsr, s_b_1_57);
    /* execute.a64:3053 [F] s_b_1_59 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_1_60 = __builtin_get_feature */
    uint32_t s_b_1_60 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_1_61 = (u8)s_b_1_60 (const) */
    /* execute.a64:3003 [F] s_b_1_62 = s_b_1_3>s_b_1_61 (const) */
    uint8_t s_b_1_62 = ((uint8_t)((uint8_t)1ULL > ((uint8_t)s_b_1_60)));
    /* execute.a64:3003 [F] s_b_1_63: If s_b_1_62: Jump b_19 else b_20 (const) */
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
    /* execute.a64:358 [F] s_b_3_0=sym_10015_3_parameter_inst.opc (const) */
    /* execute.a64:358 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:358 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:358 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:358 [F] s_b_3_4=sym_10015_3_parameter_inst.ll (const) */
    /* execute.a64:358 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:358 [F] s_b_3_6 = constant u32 1 (const) */
    /* execute.a64:358 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.ll) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:358 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2920 [F] s_b_4_0 = constant u32 4 (const) */
    /* execute.a64:2920 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)4ULL);
    /* execute.a64:2920 [F] s_b_4_2: If s_b_4_1: Jump b_11 else b_12 (const) */
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
    /* execute.a64:360 [F] s_b_5_0=sym_10015_3_parameter_inst.opc (const) */
    /* execute.a64:360 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:360 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:360 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:360 [F] s_b_5_4=sym_10015_3_parameter_inst.ll (const) */
    /* execute.a64:360 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:360 [F] s_b_5_6 = constant u32 3 (const) */
    /* execute.a64:360 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.ll) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:360 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:361 [F] s_b_6_0 = constant u32 11 (const) */
    /* execute.a64:361 [F] s_b_6_1 = constant u32 0 (const) */
    /* execute.a64:361 [F] s_b_6_2 = constant u64 0 (const) */
    /* ???:4294967295 [D] s_b_6_3 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)17ULL), emitter.const_u32((uint32_t)0ULL), emitter.const_u64((uint64_t)0ULL));
    }
    emitter.store_device(emitter.const_u32((uint32_t)17ULL), emitter.const_u32((uint32_t)0ULL), emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:362 [D] s_b_6_4 = read_pc */
    auto s_b_6_4 = emitter.load_pc();
    /* execute.a64:362 [F] s_b_6_5 = constant u64 4 (const) */
    /* execute.a64:362 [D] s_b_6_6 = s_b_6_4+s_b_6_5 */
    auto s_b_6_6 = emitter.add(s_b_6_4, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:362 [D] s_b_6_7 = write_pc */
    emitter.store_pc(s_b_6_6);
    /* execute.a64:361 [F] s_b_6_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:363 [F] s_b_7_0=sym_10015_3_parameter_inst.opc (const) */
    /* execute.a64:363 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:363 [F] s_b_7_2 = constant u32 2 (const) */
    /* execute.a64:363 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:363 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
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
    /* execute.a64:364 [F] s_b_8_0=sym_10015_3_parameter_inst.imm16 (const) */
    /* execute.a64:364 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:364 [F] s_b_8_2 = constant u32 f000 (const) */
    /* execute.a64:364 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.imm16) == (uint32_t)61440ULL));
    /* execute.a64:364 [F] s_b_8_4: If s_b_8_3: Jump b_10 else b_2 (const) */
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
    /* execute.a64:369 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:369 [F] s_b_9_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:365 [F] s_b_10_0 = constant u32 13 (const) */
    /* execute.a64:365 [F] s_b_10_1 = constant u32 0 (const) */
    /* execute.a64:365 [F] s_b_10_2 = constant u64 0 (const) */
    /* ???:4294967295 [D] s_b_10_3 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)0ULL), emitter.const_u64((uint64_t)0ULL));
    }
    emitter.store_device(emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)0ULL), emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:366 [D] s_b_10_4 = read_pc */
    auto s_b_10_4 = emitter.load_pc();
    /* execute.a64:366 [F] s_b_10_5 = constant u64 4 (const) */
    /* execute.a64:366 [D] s_b_10_6 = s_b_10_4+s_b_10_5 */
    auto s_b_10_6 = emitter.add(s_b_10_4, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:366 [D] s_b_10_7 = write_pc */
    emitter.store_pc(s_b_10_6);
    /* execute.a64:365 [F] s_b_10_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2921 [F] s_b_11_0=sym_10015_3_parameter_inst.imm16 (const) */
    /* execute.a64:2921 [F] s_b_11_1 = constant u32 13 (const) */
    /* execute.a64:2921 [F] s_b_11_2 = constant u32 1 (const) */
    /* execute.a64:2921 [F] s_b_11_3 = (u64)s_b_11_0 (const) */
    /* ???:4294967295 [D] s_b_11_4 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)1ULL), emitter.const_u64(((uint64_t)insn.imm16)));
    }
    emitter.store_device(emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)1ULL), emitter.const_u64(((uint64_t)insn.imm16)));
    /* execute.a64:2922 [D] s_b_11_5 = read_pc */
    auto s_b_11_5 = emitter.load_pc();
    /* execute.a64:2922 [F] s_b_11_6 = constant u64 4 (const) */
    /* execute.a64:2922 [D] s_b_11_7 = s_b_11_5+s_b_11_6 */
    auto s_b_11_7 = emitter.add(s_b_11_5, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2922 [D] s_b_11_8 = write_pc */
    emitter.store_pc(s_b_11_7);
    /* execute.a64:2921 [F] s_b_11_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2923 [F] s_b_12_0 = constant u32 5 (const) */
    /* execute.a64:2923 [F] s_b_12_1 = __builtin_get_feature */
    uint32_t s_b_12_1 = __get_feature((uint32_t)5ULL);
    /* execute.a64:2923 [F] s_b_12_2: If s_b_12_1: Jump b_13 else b_14 (const) */
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
    /* execute.a64:2924 [F] s_b_13_0 = constant u32 3 (const) */
    /* execute.a64:2924 [F] s_b_13_1=sym_10015_3_parameter_inst.imm16 (const) */
    /* execute.a64:2924 [F] s_b_13_2 = (u32)s_b_13_1 (const) */
    /* execute.a64:2924 [D] s_b_13_3 = take_exception */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2925 [D] s_b_13_4 = read_pc */
    auto s_b_13_4 = emitter.load_pc();
    /* execute.a64:2925 [F] s_b_13_5 = constant u64 4 (const) */
    /* execute.a64:2925 [D] s_b_13_6 = s_b_13_4+s_b_13_5 */
    auto s_b_13_6 = emitter.add(s_b_13_4, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2925 [D] s_b_13_7 = write_pc */
    emitter.store_pc(s_b_13_6);
    /* execute.a64:2924 [F] s_b_13_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2927 [D] s_b_14_0 = read_pc */
    auto s_b_14_0 = emitter.load_pc();
    /* execute.a64:2927 [F] s_b_14_1 = constant u64 4 (const) */
    /* execute.a64:2927 [D] s_b_14_2 = s_b_14_0+s_b_14_1 */
    auto s_b_14_2 = emitter.add(s_b_14_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2928 [F] s_b_14_3 = constant u64 0 (const) */
    /* execute.a64:2930 [F] s_b_14_4 = constant u8 1 (const) */
    /* execute.a64:2930 [F] s_b_14_5=sym_10015_3_parameter_inst.imm16 (const) */
    /* execute.a64:2930 [F] s_b_14_6 = (u32)s_b_14_5 (const) */
    /* execute.a64:2930 [F] s_b_14_7: sym_60054_0_parameter_syndrome = s_b_14_6 (const), dominates: s_b_17_11  */
    CV_sym_60054_0_parameter_syndrome = ((uint32_t)insn.imm16);
    /* execute.a64:2930 [D] s_b_14_8: sym_60056_0_parameter_retaddr = s_b_14_2, dominates: s_b_17_8  */
    emitter.store_local(DV_sym_60056_0_parameter_retaddr, s_b_14_2);
    /* execute.a64:2930 [F] s_b_14_9: sym_60058_0_parameter_voff = s_b_14_3 (const), dominates: s_b_15_0 s_b_18_0 s_b_17_25  */
    CV_sym_60058_0_parameter_voff = (uint64_t)0ULL;
    /* execute.a64:2878 [D] s_b_14_10 = ReadReg 1 (u8) */
    auto s_b_14_10 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_14_10, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_14_11 = (u32)s_b_14_10 */
    auto s_b_14_11 = emitter.zx(s_b_14_10, emitter.context().types().u32());
    /* execute.a64:2878 [F] s_b_14_12 = constant u32 1f (const) */
    /* execute.a64:2878 [D] s_b_14_13 = s_b_14_11<<s_b_14_12 */
    auto s_b_14_13 = emitter.shl(s_b_14_11, emitter.const_u32((uint32_t)31ULL));
    /* execute.a64:2879 [D] s_b_14_14 = ReadReg 2 (u8) */
    auto s_b_14_14 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_14_14, emitter.const_u8(1));
    }
    /* execute.a64:2879 [D] s_b_14_15 = (u32)s_b_14_14 */
    auto s_b_14_15 = emitter.zx(s_b_14_14, emitter.context().types().u32());
    /* execute.a64:2879 [F] s_b_14_16 = constant u32 1e (const) */
    /* execute.a64:2879 [D] s_b_14_17 = s_b_14_15<<s_b_14_16 */
    auto s_b_14_17 = emitter.shl(s_b_14_15, emitter.const_u32((uint32_t)30ULL));
    /* execute.a64:2878 [D] s_b_14_18 = s_b_14_13|s_b_14_17 */
    auto s_b_14_18 = emitter.bitwise_or(s_b_14_13, s_b_14_17);
    /* execute.a64:2880 [D] s_b_14_19 = ReadReg 3 (u8) */
    auto s_b_14_19 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_14_19, emitter.const_u8(1));
    }
    /* execute.a64:2880 [D] s_b_14_20 = (u32)s_b_14_19 */
    auto s_b_14_20 = emitter.zx(s_b_14_19, emitter.context().types().u32());
    /* execute.a64:2880 [F] s_b_14_21 = constant u32 1d (const) */
    /* execute.a64:2880 [D] s_b_14_22 = s_b_14_20<<s_b_14_21 */
    auto s_b_14_22 = emitter.shl(s_b_14_20, emitter.const_u32((uint32_t)29ULL));
    /* execute.a64:2879 [D] s_b_14_23 = s_b_14_18|s_b_14_22 */
    auto s_b_14_23 = emitter.bitwise_or(s_b_14_18, s_b_14_22);
    /* execute.a64:2881 [D] s_b_14_24 = ReadReg 4 (u8) */
    auto s_b_14_24 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_24, emitter.const_u8(1));
    }
    /* execute.a64:2881 [D] s_b_14_25 = (u32)s_b_14_24 */
    auto s_b_14_25 = emitter.zx(s_b_14_24, emitter.context().types().u32());
    /* execute.a64:2881 [F] s_b_14_26 = constant u32 1c (const) */
    /* execute.a64:2881 [D] s_b_14_27 = s_b_14_25<<s_b_14_26 */
    auto s_b_14_27 = emitter.shl(s_b_14_25, emitter.const_u32((uint32_t)28ULL));
    /* execute.a64:2880 [D] s_b_14_28 = s_b_14_23|s_b_14_27 */
    auto s_b_14_28 = emitter.bitwise_or(s_b_14_23, s_b_14_27);
    /* execute.a64:2882 [D] s_b_14_29 = ReadReg 5 (u8) */
    auto s_b_14_29 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_14_29, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_14_30 = (u32)s_b_14_29 */
    auto s_b_14_30 = emitter.zx(s_b_14_29, emitter.context().types().u32());
    /* execute.a64:2882 [F] s_b_14_31 = constant u32 9 (const) */
    /* execute.a64:2882 [D] s_b_14_32 = s_b_14_30<<s_b_14_31 */
    auto s_b_14_32 = emitter.shl(s_b_14_30, emitter.const_u32((uint32_t)9ULL));
    /* execute.a64:2881 [D] s_b_14_33 = s_b_14_28|s_b_14_32 */
    auto s_b_14_33 = emitter.bitwise_or(s_b_14_28, s_b_14_32);
    /* execute.a64:2883 [D] s_b_14_34 = ReadReg 6 (u8) */
    auto s_b_14_34 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_14_34, emitter.const_u8(1));
    }
    /* execute.a64:2883 [D] s_b_14_35 = (u32)s_b_14_34 */
    auto s_b_14_35 = emitter.zx(s_b_14_34, emitter.context().types().u32());
    /* execute.a64:2883 [F] s_b_14_36 = constant u32 8 (const) */
    /* execute.a64:2883 [D] s_b_14_37 = s_b_14_35<<s_b_14_36 */
    auto s_b_14_37 = emitter.shl(s_b_14_35, emitter.const_u32((uint32_t)8ULL));
    /* execute.a64:2882 [D] s_b_14_38 = s_b_14_33|s_b_14_37 */
    auto s_b_14_38 = emitter.bitwise_or(s_b_14_33, s_b_14_37);
    /* execute.a64:2884 [D] s_b_14_39 = ReadReg 7 (u8) */
    auto s_b_14_39 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_14_39, emitter.const_u8(1));
    }
    /* execute.a64:2884 [D] s_b_14_40 = (u32)s_b_14_39 */
    auto s_b_14_40 = emitter.zx(s_b_14_39, emitter.context().types().u32());
    /* execute.a64:2884 [F] s_b_14_41 = constant u32 7 (const) */
    /* execute.a64:2884 [D] s_b_14_42 = s_b_14_40<<s_b_14_41 */
    auto s_b_14_42 = emitter.shl(s_b_14_40, emitter.const_u32((uint32_t)7ULL));
    /* execute.a64:2883 [D] s_b_14_43 = s_b_14_38|s_b_14_42 */
    auto s_b_14_43 = emitter.bitwise_or(s_b_14_38, s_b_14_42);
    /* execute.a64:2885 [D] s_b_14_44 = ReadReg 8 (u8) */
    auto s_b_14_44 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_14_44, emitter.const_u8(1));
    }
    /* execute.a64:2885 [D] s_b_14_45 = (u32)s_b_14_44 */
    auto s_b_14_45 = emitter.zx(s_b_14_44, emitter.context().types().u32());
    /* execute.a64:2885 [F] s_b_14_46 = constant u32 6 (const) */
    /* execute.a64:2885 [D] s_b_14_47 = s_b_14_45<<s_b_14_46 */
    auto s_b_14_47 = emitter.shl(s_b_14_45, emitter.const_u32((uint32_t)6ULL));
    /* execute.a64:2884 [D] s_b_14_48 = s_b_14_43|s_b_14_47 */
    auto s_b_14_48 = emitter.bitwise_or(s_b_14_43, s_b_14_47);
    /* execute.a64:3053 [F] s_b_14_49 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_14_50 = __builtin_get_feature */
    uint32_t s_b_14_50 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_14_51 = (u8)s_b_14_50 (const) */
    /* execute.a64:2886 [F] s_b_14_52 = (u32)s_b_14_51 (const) */
    /* execute.a64:2886 [F] s_b_14_53 = constant u32 2 (const) */
    /* execute.a64:2886 [F] s_b_14_54 = s_b_14_52<<s_b_14_53 (const) */
    uint32_t s_b_14_54 = ((uint32_t)(((uint32_t)((uint8_t)s_b_14_50)) << (uint32_t)2ULL));
    /* execute.a64:2885 [D] s_b_14_55 = s_b_14_48|s_b_14_54 */
    auto s_b_14_55 = emitter.bitwise_or(s_b_14_48, emitter.const_u32(s_b_14_54));
    /* execute.a64:2887 [F] s_b_14_56 = constant u32 1 (const) */
    /* execute.a64:2887 [F] s_b_14_57 = __builtin_get_feature */
    uint32_t s_b_14_57 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2887 [F] s_b_14_58 = (u32)s_b_14_57 (const) */
    /* execute.a64:2886 [D] s_b_14_59 = s_b_14_55|s_b_14_58 */
    auto s_b_14_59 = emitter.bitwise_or(s_b_14_55, emitter.const_u32(((uint32_t)s_b_14_57)));
    /* execute.a64:3000 [D] s_b_14_60: sym_60110_0_spsr = s_b_14_59, dominates: s_b_17_6  */
    emitter.store_local(DV_sym_60110_0_spsr, s_b_14_59);
    /* execute.a64:3053 [F] s_b_14_61 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_14_62 = __builtin_get_feature */
    uint32_t s_b_14_62 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_14_63 = (u8)s_b_14_62 (const) */
    /* execute.a64:3003 [F] s_b_14_64 = s_b_14_4>s_b_14_63 (const) */
    uint8_t s_b_14_64 = ((uint8_t)((uint8_t)1ULL > ((uint8_t)s_b_14_62)));
    /* execute.a64:3003 [F] s_b_14_65: If s_b_14_64: Jump b_15 else b_16 (const) */
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
    /* execute.a64:3004 [F] s_b_15_0 = sym_60058_0_parameter_voff (const) uint64_t */
    uint64_t s_b_15_0 = CV_sym_60058_0_parameter_voff;
    /* ???:4294967295 [F] s_b_15_1 = constant u64 400 (const) */
    /* ???:4294967295 [F] s_b_15_2 = s_b_15_0+s_b_15_1 (const) */
    uint64_t s_b_15_2 = ((uint64_t)(s_b_15_0 + (uint64_t)1024ULL));
    /* execute.a64:3004 [F] s_b_15_3: sym_60058_0_parameter_voff = s_b_15_2 (const), dominates: s_b_17_25  */
    CV_sym_60058_0_parameter_voff = s_b_15_2;
    /* execute.a64:3004 [F] s_b_15_4: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:3005 [F] s_b_16_0 = constant u32 1 (const) */
    /* execute.a64:3005 [F] s_b_16_1 = __builtin_get_feature */
    uint32_t s_b_16_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:3005 [F] s_b_16_2 = constant u32 1 (const) */
    /* execute.a64:3005 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(s_b_16_1 == (uint32_t)1ULL));
    /* execute.a64:3005 [F] s_b_16_4: If s_b_16_3: Jump b_18 else b_17 (const) */
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
    /* execute.a64:3058 [F] s_b_17_0 = constant u32 0 (const) */
    /* execute.a64:3058 [F] s_b_17_1 = constant u32 1 (const) */
    /* execute.a64:3058 [D] s_b_17_2 = __builtin_set_feature */
    emitter.set_feature((uint32_t)0ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:2994 [F] s_b_17_3 = constant u32 1 (const) */
    /* execute.a64:2994 [F] s_b_17_4 = constant u32 1 (const) */
    /* execute.a64:2994 [D] s_b_17_5 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:3016 [D] s_b_17_6 = sym_60110_0_spsr uint32_t */
    auto s_b_17_6 = emitter.load_local(DV_sym_60110_0_spsr, emitter.context().types().u32());
    /* execute.a64:3016 [D] s_b_17_7: WriteReg 17 = s_b_17_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_17_6, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_17_6);
    /* execute.a64:3017 [D] s_b_17_8 = sym_60056_0_parameter_retaddr uint64_t */
    auto s_b_17_8 = emitter.load_local(DV_sym_60056_0_parameter_retaddr, emitter.context().types().u64());
    /* execute.a64:3017 [D] s_b_17_9: WriteReg 16 = s_b_17_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_17_8, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_17_8);
    /* execute.a64:3022 [F] s_b_17_10 = constant u32 56000000 (const) */
    /* execute.a64:3022 [F] s_b_17_11 = sym_60054_0_parameter_syndrome (const) uint32_t */
    uint32_t s_b_17_11 = CV_sym_60054_0_parameter_syndrome;
    /* execute.a64:3022 [F] s_b_17_12 = constant u32 1ffffff (const) */
    /* execute.a64:3022 [F] s_b_17_13 = s_b_17_11&s_b_17_12 (const) */
    uint32_t s_b_17_13 = ((uint32_t)(s_b_17_11 & (uint32_t)33554431ULL));
    /* execute.a64:3022 [F] s_b_17_14 = s_b_17_10|s_b_17_13 (const) */
    uint32_t s_b_17_14 = ((uint32_t)((uint32_t)1442840576ULL | s_b_17_13));
    /* execute.a64:3022 [F] s_b_17_15: WriteReg 18 = s_b_17_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1392), emitter.const_u32(s_b_17_14), emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1392), emitter.const_u32(s_b_17_14));
    /* execute.a64:3032 [F] s_b_17_16 = constant u8 1 (const) */
    /* execute.a64:3032 [F] s_b_17_17: WriteReg 5 = s_b_17_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3033 [F] s_b_17_18 = constant u8 1 (const) */
    /* execute.a64:3033 [F] s_b_17_19: WriteReg 6 = s_b_17_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3034 [F] s_b_17_20 = constant u8 1 (const) */
    /* execute.a64:3034 [F] s_b_17_21: WriteReg 7 = s_b_17_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3035 [F] s_b_17_22 = constant u8 1 (const) */
    /* execute.a64:3035 [F] s_b_17_23: WriteReg 8 = s_b_17_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3037 [D] s_b_17_24 = ReadReg 13 (u64) */
    auto s_b_17_24 = emitter.load_register(emitter.const_u32(1336), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1336), s_b_17_24, emitter.const_u8(8));
    }
    /* execute.a64:3039 [F] s_b_17_25 = sym_60058_0_parameter_voff (const) uint64_t */
    uint64_t s_b_17_25 = CV_sym_60058_0_parameter_voff;
    /* execute.a64:3039 [D] s_b_17_26 = s_b_17_24+s_b_17_25 */
    auto s_b_17_26 = emitter.add(s_b_17_24, emitter.const_u64(s_b_17_25));
    /* execute.a64:3039 [D] s_b_17_27 = write_pc */
    emitter.store_pc(s_b_17_26);
    /* execute.a64:0 [F] s_b_17_28: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:3006 [F] s_b_18_0 = sym_60058_0_parameter_voff (const) uint64_t */
    uint64_t s_b_18_0 = CV_sym_60058_0_parameter_voff;
    /* ???:4294967295 [F] s_b_18_1 = constant u64 200 (const) */
    /* ???:4294967295 [F] s_b_18_2 = s_b_18_0+s_b_18_1 (const) */
    uint64_t s_b_18_2 = ((uint64_t)(s_b_18_0 + (uint64_t)512ULL));
    /* execute.a64:3006 [F] s_b_18_3: sym_60058_0_parameter_voff = s_b_18_2 (const), dominates: s_b_17_25  */
    CV_sym_60058_0_parameter_voff = s_b_18_2;
    /* execute.a64:3006 [F] s_b_18_4: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_1,  */
  fixed_block_b_19: 
  {
    /* execute.a64:3004 [F] s_b_19_0 = sym_60190_3_parameter_voff (const) uint64_t */
    uint64_t s_b_19_0 = CV_sym_60190_3_parameter_voff;
    /* ???:4294967295 [F] s_b_19_1 = constant u64 400 (const) */
    /* ???:4294967295 [F] s_b_19_2 = s_b_19_0+s_b_19_1 (const) */
    uint64_t s_b_19_2 = ((uint64_t)(s_b_19_0 + (uint64_t)1024ULL));
    /* execute.a64:3004 [F] s_b_19_3: sym_60190_3_parameter_voff = s_b_19_2 (const), dominates: s_b_21_25  */
    CV_sym_60190_3_parameter_voff = s_b_19_2;
    /* execute.a64:3004 [F] s_b_19_4: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_1,  */
  fixed_block_b_20: 
  {
    /* execute.a64:3005 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:3005 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:3005 [F] s_b_20_2 = constant u32 1 (const) */
    /* execute.a64:3005 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)1ULL));
    /* execute.a64:3005 [F] s_b_20_4: If s_b_20_3: Jump b_22 else b_21 (const) */
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
    /* execute.a64:3058 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:3058 [F] s_b_21_1 = constant u32 1 (const) */
    /* execute.a64:3058 [D] s_b_21_2 = __builtin_set_feature */
    emitter.set_feature((uint32_t)0ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:2994 [F] s_b_21_3 = constant u32 1 (const) */
    /* execute.a64:2994 [F] s_b_21_4 = constant u32 1 (const) */
    /* execute.a64:2994 [D] s_b_21_5 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:3016 [D] s_b_21_6 = sym_60178_0_spsr uint32_t */
    auto s_b_21_6 = emitter.load_local(DV_sym_60178_0_spsr, emitter.context().types().u32());
    /* execute.a64:3016 [D] s_b_21_7: WriteReg 17 = s_b_21_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_21_6, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_21_6);
    /* execute.a64:3017 [D] s_b_21_8 = sym_60228_3_parameter_retaddr uint64_t */
    auto s_b_21_8 = emitter.load_local(DV_sym_60228_3_parameter_retaddr, emitter.context().types().u64());
    /* execute.a64:3017 [D] s_b_21_9: WriteReg 16 = s_b_21_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_21_8, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_21_8);
    /* execute.a64:3022 [F] s_b_21_10 = constant u32 f2000000 (const) */
    /* execute.a64:3022 [F] s_b_21_11 = sym_60279_3_parameter_syndrome (const) uint32_t */
    uint32_t s_b_21_11 = CV_sym_60279_3_parameter_syndrome;
    /* execute.a64:3022 [F] s_b_21_12 = constant u32 1ffffff (const) */
    /* execute.a64:3022 [F] s_b_21_13 = s_b_21_11&s_b_21_12 (const) */
    uint32_t s_b_21_13 = ((uint32_t)(s_b_21_11 & (uint32_t)33554431ULL));
    /* execute.a64:3022 [F] s_b_21_14 = s_b_21_10|s_b_21_13 (const) */
    uint32_t s_b_21_14 = ((uint32_t)((uint32_t)4060086272ULL | s_b_21_13));
    /* execute.a64:3022 [F] s_b_21_15: WriteReg 18 = s_b_21_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1392), emitter.const_u32(s_b_21_14), emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1392), emitter.const_u32(s_b_21_14));
    /* execute.a64:3032 [F] s_b_21_16 = constant u8 1 (const) */
    /* execute.a64:3032 [F] s_b_21_17: WriteReg 5 = s_b_21_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3033 [F] s_b_21_18 = constant u8 1 (const) */
    /* execute.a64:3033 [F] s_b_21_19: WriteReg 6 = s_b_21_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3034 [F] s_b_21_20 = constant u8 1 (const) */
    /* execute.a64:3034 [F] s_b_21_21: WriteReg 7 = s_b_21_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3035 [F] s_b_21_22 = constant u8 1 (const) */
    /* execute.a64:3035 [F] s_b_21_23: WriteReg 8 = s_b_21_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3037 [D] s_b_21_24 = ReadReg 13 (u64) */
    auto s_b_21_24 = emitter.load_register(emitter.const_u32(1336), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1336), s_b_21_24, emitter.const_u8(8));
    }
    /* execute.a64:3039 [F] s_b_21_25 = sym_60190_3_parameter_voff (const) uint64_t */
    uint64_t s_b_21_25 = CV_sym_60190_3_parameter_voff;
    /* execute.a64:3039 [D] s_b_21_26 = s_b_21_24+s_b_21_25 */
    auto s_b_21_26 = emitter.add(s_b_21_24, emitter.const_u64(s_b_21_25));
    /* execute.a64:3039 [D] s_b_21_27 = write_pc */
    emitter.store_pc(s_b_21_26);
    /* execute.a64:0 [F] s_b_21_28: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_20,  */
  fixed_block_b_22: 
  {
    /* execute.a64:3006 [F] s_b_22_0 = sym_60190_3_parameter_voff (const) uint64_t */
    uint64_t s_b_22_0 = CV_sym_60190_3_parameter_voff;
    /* ???:4294967295 [F] s_b_22_1 = constant u64 200 (const) */
    /* ???:4294967295 [F] s_b_22_2 = s_b_22_0+s_b_22_1 (const) */
    uint64_t s_b_22_2 = ((uint64_t)(s_b_22_0 + (uint64_t)512ULL));
    /* execute.a64:3006 [F] s_b_22_3: sym_60190_3_parameter_voff = s_b_22_2 (const), dominates: s_b_21_25  */
    CV_sym_60190_3_parameter_voff = s_b_22_2;
    /* execute.a64:3006 [F] s_b_22_4: Jump b_21 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fcmpe(const arm64_decode_a64_FP_CMP&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_10684_0_rm = emitter.alloc_local(emitter.context().types().f64(), false);
  double CV_sym_10673_1_temporary_value;
  auto DV_sym_10673_1_temporary_value = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_10602_0_rn = emitter.alloc_local(emitter.context().types().f32(), false);
  float CV_sym_10621_1_temporary_value;
  auto DV_sym_10621_1_temporary_value = emitter.alloc_local(emitter.context().types().f32(), false);
  auto DV_sym_10654_0_rn = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_10632_0_rm = emitter.alloc_local(emitter.context().types().f32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4657 [F] s_b_0_0=sym_10589_3_parameter_inst.type (const) */
    /* execute.simd:4657 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4657 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4657 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4657 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4659 [F] s_b_1_0=sym_10589_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4659 [D] s_b_1_2: sym_10602_0_rn = s_b_1_1, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_10602_0_rn, s_b_1_1);
    /* execute.simd:4660 [F] s_b_1_3=sym_10589_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4660 [F] s_b_1_4 = (u32)s_b_1_3 (const) */
    /* execute.simd:4660 [F] s_b_1_5 = constant u32 18 (const) */
    /* execute.simd:4660 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint32_t)insn.opcode2) == (uint32_t)24ULL));
    /* execute.simd:4660 [F] s_b_1_7=sym_10589_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4660 [F] s_b_1_8 = (u32)s_b_1_7 (const) */
    /* execute.simd:4660 [F] s_b_1_9 = constant u32 8 (const) */
    /* execute.simd:4660 [F] s_b_1_10 = s_b_1_8==s_b_1_9 (const) */
    uint8_t s_b_1_10 = ((uint8_t)(((uint32_t)insn.opcode2) == (uint32_t)8ULL));
    /* ???:4294967295 [F] s_b_1_11 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_1_12 = s_b_1_6!=s_b_1_11 (const) */
    uint8_t s_b_1_12 = ((uint8_t)(s_b_1_6 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_13 = s_b_1_10!=s_b_1_11 (const) */
    uint8_t s_b_1_13 = ((uint8_t)(s_b_1_10 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_14 = s_b_1_12|s_b_1_13 (const) */
    uint8_t s_b_1_14 = ((uint8_t)(s_b_1_12 | s_b_1_13));
    /* execute.simd:4660 [F] s_b_1_15: If s_b_1_14: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4669 [F] s_b_3_0=sym_10589_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4669 [D] s_b_3_2: sym_10654_0_rn = s_b_3_1, dominates: s_b_12_0 s_b_13_0  */
    emitter.store_local(DV_sym_10654_0_rn, s_b_3_1);
    /* execute.simd:4670 [F] s_b_3_3=sym_10589_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4670 [F] s_b_3_4 = (u32)s_b_3_3 (const) */
    /* execute.simd:4670 [F] s_b_3_5 = constant u32 18 (const) */
    /* execute.simd:4670 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint32_t)insn.opcode2) == (uint32_t)24ULL));
    /* execute.simd:4670 [F] s_b_3_7=sym_10589_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4670 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
    /* execute.simd:4670 [F] s_b_3_9 = constant u32 8 (const) */
    /* execute.simd:4670 [F] s_b_3_10 = s_b_3_8==s_b_3_9 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(((uint32_t)insn.opcode2) == (uint32_t)8ULL));
    /* ???:4294967295 [F] s_b_3_11 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_12 = s_b_3_6!=s_b_3_11 (const) */
    uint8_t s_b_3_12 = ((uint8_t)(s_b_3_6 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_13 = s_b_3_10!=s_b_3_11 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(s_b_3_10 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_14 = s_b_3_12|s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(s_b_3_12 | s_b_3_13));
    /* execute.simd:4670 [F] s_b_3_15: If s_b_3_14: Jump b_9 else b_10 (const) */
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
    /* execute.simd:4660 [F] s_b_4_0 = constant f32 0 (const) */
    float s_b_4_0;
    {
      uint32_t __tmp = 0;
      s_b_4_0 = *(float *)&__tmp;
    }
    /* execute.simd:4660 [F] s_b_4_1: sym_10621_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_10621_1_temporary_value = s_b_4_0;
    emitter.store_local(DV_sym_10621_1_temporary_value, emitter.const_f32(s_b_4_0));
    /* execute.simd:4660 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4660 [F] s_b_5_0=sym_10589_3_parameter_inst.rm (const) */
    /* execute.simd:6162 [D] s_b_5_1 = ReadRegBank 9:s_b_5_0 (f32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_1,emitter.const_u8(4));
    }
    /* execute.simd:4660 [D] s_b_5_2: sym_10621_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_10621_1_temporary_value, s_b_5_1);
    /* execute.simd:4660 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4660 [D] s_b_6_0 = sym_10621_1_temporary_value float */
    auto s_b_6_0 = emitter.load_local(DV_sym_10621_1_temporary_value, emitter.context().types().f32());
    /* execute.simd:4660 [D] s_b_6_1: sym_10632_0_rm = s_b_6_0, dominates: s_b_7_1 s_b_8_1  */
    emitter.store_local(DV_sym_10632_0_rm, s_b_6_0);
    /* execute.simd:4662 [F] s_b_6_2=sym_10589_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4662 [F] s_b_6_3 = (u32)s_b_6_2 (const) */
    /* execute.simd:4662 [F] s_b_6_4 = constant u32 10 (const) */
    /* execute.simd:4662 [F] s_b_6_5 = s_b_6_3&s_b_6_4 (const) */
    uint32_t s_b_6_5 = ((uint32_t)(((uint32_t)insn.opcode2) & (uint32_t)16ULL));
    /* execute.simd:4662 [F] s_b_6_6: If s_b_6_5: Jump b_7 else b_8 (const) */
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
    /* execute.simd:4663 [D] s_b_7_0 = sym_10602_0_rn float */
    auto s_b_7_0 = emitter.load_local(DV_sym_10602_0_rn, emitter.context().types().f32());
    /* execute.simd:4663 [D] s_b_7_1 = sym_10632_0_rm float */
    auto s_b_7_1 = emitter.load_local(DV_sym_10632_0_rm, emitter.context().types().f32());
    /* execute.simd:4663 [D] s_b_7_2 = __builtin_cmpf32e_flags */
    emitter.call(__captive___builtin_cmpf32e_flags, s_b_7_0, s_b_7_1);
    /* execute.simd:4663 [F] s_b_7_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4665 [D] s_b_8_0 = sym_10602_0_rn float */
    auto s_b_8_0 = emitter.load_local(DV_sym_10602_0_rn, emitter.context().types().f32());
    /* execute.simd:4665 [D] s_b_8_1 = sym_10632_0_rm float */
    auto s_b_8_1 = emitter.load_local(DV_sym_10632_0_rm, emitter.context().types().f32());
    /* execute.simd:4665 [D] s_b_8_2 = __builtin_cmpf32_flags */
    emitter.call(__captive___builtin_cmpf32_flags, s_b_8_0, s_b_8_1);
    /* execute.simd:4665 [F] s_b_8_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4670 [F] s_b_9_0 = constant f64 0 (const) */
    double s_b_9_0;
    {
      uint64_t __tmp = 0;
      s_b_9_0 = *(double *)&__tmp;
    }
    /* execute.simd:4670 [F] s_b_9_1: sym_10673_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_10673_1_temporary_value = s_b_9_0;
    emitter.store_local(DV_sym_10673_1_temporary_value, emitter.const_f64(s_b_9_0));
    /* execute.simd:4670 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4670 [F] s_b_10_0=sym_10589_3_parameter_inst.rm (const) */
    /* execute.simd:6167 [D] s_b_10_1 = ReadRegBank 11:s_b_10_0 (f64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.simd:4670 [D] s_b_10_2: sym_10673_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_10673_1_temporary_value, s_b_10_1);
    /* execute.simd:4670 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4670 [D] s_b_11_0 = sym_10673_1_temporary_value double */
    auto s_b_11_0 = emitter.load_local(DV_sym_10673_1_temporary_value, emitter.context().types().f64());
    /* execute.simd:4670 [D] s_b_11_1: sym_10684_0_rm = s_b_11_0, dominates: s_b_12_1 s_b_13_1  */
    emitter.store_local(DV_sym_10684_0_rm, s_b_11_0);
    /* execute.simd:4672 [F] s_b_11_2=sym_10589_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4672 [F] s_b_11_3 = (u32)s_b_11_2 (const) */
    /* execute.simd:4672 [F] s_b_11_4 = constant u32 10 (const) */
    /* execute.simd:4672 [F] s_b_11_5 = s_b_11_3&s_b_11_4 (const) */
    uint32_t s_b_11_5 = ((uint32_t)(((uint32_t)insn.opcode2) & (uint32_t)16ULL));
    /* execute.simd:4672 [F] s_b_11_6: If s_b_11_5: Jump b_12 else b_13 (const) */
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
    /* execute.simd:4673 [D] s_b_12_0 = sym_10654_0_rn double */
    auto s_b_12_0 = emitter.load_local(DV_sym_10654_0_rn, emitter.context().types().f64());
    /* execute.simd:4673 [D] s_b_12_1 = sym_10684_0_rm double */
    auto s_b_12_1 = emitter.load_local(DV_sym_10684_0_rm, emitter.context().types().f64());
    /* execute.simd:4673 [D] s_b_12_2 = __builtin_cmpf64e_flags */
    emitter.call(__captive___builtin_cmpf64e_flags, s_b_12_0, s_b_12_1);
    /* execute.simd:4673 [F] s_b_12_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4675 [D] s_b_13_0 = sym_10654_0_rn double */
    auto s_b_13_0 = emitter.load_local(DV_sym_10654_0_rn, emitter.context().types().f64());
    /* execute.simd:4675 [D] s_b_13_1 = sym_10684_0_rm double */
    auto s_b_13_1 = emitter.load_local(DV_sym_10684_0_rm, emitter.context().types().f64());
    /* execute.simd:4675 [D] s_b_13_2 = __builtin_cmpf64_flags */
    emitter.call(__captive___builtin_cmpf64_flags, s_b_13_0, s_b_13_1);
    /* execute.simd:4675 [F] s_b_13_3: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fdiv(const arm64_decode_a64_FP_DP_2&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4147 [F] s_b_0_0=sym_11569_3_parameter_inst.type (const) */
    /* execute.simd:4147 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4147 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4147 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4147 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4149 [F] s_b_1_0=sym_11569_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4150 [F] s_b_1_2=sym_11569_3_parameter_inst.rm (const) */
    /* execute.simd:6162 [D] s_b_1_3 = ReadRegBank 9:s_b_1_2 (f32) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(4));
    }
    /* execute.simd:4152 [D] s_b_1_4 = s_b_1_1/s_b_1_3 */
    auto s_b_1_4 = emitter.div(s_b_1_1, s_b_1_3);
    /* execute.simd:4153 [F] s_b_1_5=sym_11569_3_parameter_inst.rd (const) */
    /* execute.simd:6172 [D] s_b_1_6: WriteRegBank 9:s_b_1_5 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4);
    /* execute.simd:6173 [F] s_b_1_7 = constant u32 0 (const) */
    /* execute.simd:6173 [F] s_b_1_8: WriteRegBank 10:s_b_1_5 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6174 [F] s_b_1_9 = constant u64 0 (const) */
    /* execute.simd:6174 [F] s_b_1_10: WriteRegBank 3:s_b_1_5 = s_b_1_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:4156 [F] s_b_3_0=sym_11569_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4157 [F] s_b_3_2=sym_11569_3_parameter_inst.rm (const) */
    /* execute.simd:6167 [D] s_b_3_3 = ReadRegBank 11:s_b_3_2 (f64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:4159 [D] s_b_3_4 = s_b_3_1/s_b_3_3 */
    auto s_b_3_4 = emitter.div(s_b_3_1, s_b_3_3);
    /* execute.simd:4160 [F] s_b_3_5=sym_11569_3_parameter_inst.rd (const) */
    /* execute.simd:6180 [D] s_b_3_6: WriteRegBank 11:s_b_3_5 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:6181 [F] s_b_3_7 = constant u64 0 (const) */
    /* execute.simd:6181 [F] s_b_3_8: WriteRegBank 3:s_b_3_5 = s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fmov_simd(const arm64_decode_a64_SIMD_MOD_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4912 [F] s_b_0_0=sym_12041_3_parameter_inst.op (const) */
    /* execute.simd:4912 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4912 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4912 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.op) == (uint32_t)0ULL));
    /* execute.simd:4912 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4913 [F] s_b_1_0=sym_12041_3_parameter_inst.Q (const) */
    /* execute.simd:4913 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4913 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4913 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:4913 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_3, b_4, b_5, b_6,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4920 [F] s_b_3_0=sym_12041_3_parameter_inst.Q (const) */
    /* execute.simd:4920 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4920 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4920 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* execute.simd:4920 [F] s_b_3_4=sym_12041_3_parameter_inst.op (const) */
    /* execute.simd:4920 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4920 [F] s_b_3_6 = constant u32 1 (const) */
    /* execute.simd:4920 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.op) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4920 [F] s_b_3_12: If s_b_3_11: Jump b_6 else b_2 (const) */
    if (s_b_3_11) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4915 [F] s_b_4_0=sym_12041_3_parameter_inst.rd (const) */
    /* execute.simd:4915 [F] s_b_4_1=sym_12041_3_parameter_inst.immu64 (const) */
    /* execute.simd:6208 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6209 [F] s_b_4_3 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_4_4: WriteRegBank 3:s_b_4_0 = s_b_4_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4918 [F] s_b_5_0=sym_12041_3_parameter_inst.rd (const) */
    /* execute.simd:4918 [F] s_b_5_1=sym_12041_3_parameter_inst.immu64 (const) */
    /* execute.simd:4918 [F] s_b_5_2=sym_12041_3_parameter_inst.immu64 (const) */
    /* execute.simd:6215 [F] s_b_5_3: WriteRegBank 2:s_b_5_0 = s_b_5_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6216 [F] s_b_5_4: WriteRegBank 3:s_b_5_0 = s_b_5_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:0 [F] s_b_5_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4922 [F] s_b_6_0=sym_12041_3_parameter_inst.rd (const) */
    /* execute.simd:4922 [F] s_b_6_1=sym_12041_3_parameter_inst.immu64 (const) */
    /* execute.simd:4922 [F] s_b_6_2=sym_12041_3_parameter_inst.immu64 (const) */
    /* execute.simd:6215 [F] s_b_6_3: WriteRegBank 2:s_b_6_0 = s_b_6_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6216 [F] s_b_6_4: WriteRegBank 3:s_b_6_0 = s_b_6_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:0 [F] s_b_6_5: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fsqrt(const arm64_decode_a64_FP_DP_1&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4639 [F] s_b_0_0=sym_12511_3_parameter_inst.type (const) */
    /* execute.simd:4639 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4639 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4639 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4639 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4640 [F] s_b_1_0=sym_12511_3_parameter_inst.rd (const) */
    /* execute.simd:4640 [F] s_b_1_1=sym_12511_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_1_2 = ReadRegBank 9:s_b_1_1 (f32) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(4));
    }
    /* execute.simd:4640 [D] s_b_1_3 = float_sqrt */
    auto s_b_1_3 = emitter.call(__captive_float_sqrt, s_b_1_2);
    /* execute.simd:6172 [D] s_b_1_4: WriteRegBank 9:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3);
    /* execute.simd:6173 [F] s_b_1_5 = constant u32 0 (const) */
    /* execute.simd:6173 [F] s_b_1_6: WriteRegBank 10:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6174 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6174 [F] s_b_1_8: WriteRegBank 3:s_b_1_0 = s_b_1_7 */
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
    /* execute.simd:4642 [F] s_b_3_0=sym_12511_3_parameter_inst.rd (const) */
    /* execute.simd:4642 [F] s_b_3_1=sym_12511_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_3_2 = ReadRegBank 11:s_b_3_1 (f64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:4642 [D] s_b_3_3 = double_sqrt */
    auto s_b_3_3 = emitter.call(__captive_double_sqrt, s_b_3_2);
    /* execute.simd:6180 [D] s_b_3_4: WriteRegBank 11:s_b_3_0 = s_b_3_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3);
    /* execute.simd:6181 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.simd:6181 [F] s_b_3_6: WriteRegBank 3:s_b_3_0 = s_b_3_5 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ld1r(const arm64_decode_a64_SIMD_LS_SINGLE&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_66247_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66285_1__R_s_b_21_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_13174_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_13139_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_13104_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_13069_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_13062_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2771 [F] s_b_0_0=sym_13056_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2771 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_4: If s_b_0_3: Jump b_16 else b_14 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_3, b_4, b_6, b_7, b_9, b_10, b_12, b_13, b_15,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_15,  */
  fixed_block_b_2: 
  {
    /* execute.simd:2649 [D] s_b_2_0 = sym_13062_0_addr uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_13062_0_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_1 = Load 1 s_b_2_0 => sym_13069_0_value */
    auto s_b_2_1 = emitter.load_memory(s_b_2_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_13069_0_value, s_b_2_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_1, emitter.const_u8(1));
    }
    /* execute.simd:2651 [F] s_b_2_2=sym_13056_3_parameter_inst.Q (const) */
    /* execute.simd:2651 [F] s_b_2_3 = (u32)s_b_2_2 (const) */
    /* execute.simd:2651 [F] s_b_2_4 = constant u32 0 (const) */
    /* execute.simd:2651 [F] s_b_2_5 = s_b_2_3==s_b_2_4 (const) */
    uint8_t s_b_2_5 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:2651 [F] s_b_2_6: If s_b_2_5: Jump b_3 else b_4 (const) */
    if (s_b_2_5) 
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
    /* execute.simd:2652 [D] s_b_3_0 = sym_13069_0_value uint8_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_13069_0_value, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_3_1 = (v8u8)s_b_3_0 */
    auto s_b_3_1 = emitter.splat(s_b_3_0, emitter.context().types().v8u8());
    /* execute.simd:2653 [F] s_b_3_2=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2653 [D] s_b_3_3: WriteRegBank 15:s_b_3_2 = s_b_3_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_1);
    /* execute.simd:2654 [F] s_b_3_4=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2654 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.simd:2654 [F] s_b_3_6: WriteRegBank 3:s_b_3_4 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2652 [F] s_b_3_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_2,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2656 [D] s_b_4_0 = sym_13069_0_value uint8_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_13069_0_value, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_4_1 = (v16u8)s_b_4_0 */
    auto s_b_4_1 = emitter.splat(s_b_4_0, emitter.context().types().v16u8());
    /* execute.simd:2657 [F] s_b_4_2=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2657 [D] s_b_4_3: WriteRegBank 16:s_b_4_2 = s_b_4_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_4_1,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_4_1);
    /* execute.simd:2656 [F] s_b_4_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_5: 
  {
    /* execute.simd:2663 [D] s_b_5_0 = sym_13062_0_addr uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_13062_0_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_1 = Load 2 s_b_5_0 => sym_13104_0_value */
    auto s_b_5_1 = emitter.load_memory(s_b_5_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_13104_0_value, s_b_5_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_5_0, s_b_5_1, emitter.const_u8(2));
    }
    /* execute.simd:2665 [F] s_b_5_2=sym_13056_3_parameter_inst.Q (const) */
    /* execute.simd:2665 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.simd:2665 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.simd:2665 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:2665 [F] s_b_5_6: If s_b_5_5: Jump b_6 else b_7 (const) */
    if (s_b_5_5) 
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
    /* execute.simd:2666 [D] s_b_6_0 = sym_13104_0_value uint16_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_13104_0_value, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_6_1 = (v4u16)s_b_6_0 */
    auto s_b_6_1 = emitter.splat(s_b_6_0, emitter.context().types().v4u16());
    /* execute.simd:2667 [F] s_b_6_2=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2667 [D] s_b_6_3: WriteRegBank 17:s_b_6_2 = s_b_6_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_6_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_6_1);
    /* execute.simd:2668 [F] s_b_6_4=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2668 [F] s_b_6_5 = constant u64 0 (const) */
    /* execute.simd:2668 [F] s_b_6_6: WriteRegBank 3:s_b_6_4 = s_b_6_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2666 [F] s_b_6_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2670 [D] s_b_7_0 = sym_13104_0_value uint16_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_13104_0_value, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_7_1 = (v8u16)s_b_7_0 */
    auto s_b_7_1 = emitter.splat(s_b_7_0, emitter.context().types().v8u16());
    /* execute.simd:2671 [F] s_b_7_2=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2671 [D] s_b_7_3: WriteRegBank 18:s_b_7_2 = s_b_7_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_7_1,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_7_1);
    /* execute.simd:2670 [F] s_b_7_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2677 [D] s_b_8_0 = sym_13062_0_addr uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_13062_0_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_8_1 = Load 4 s_b_8_0 => sym_13139_0_value */
    auto s_b_8_1 = emitter.load_memory(s_b_8_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_13139_0_value, s_b_8_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_8_0, s_b_8_1, emitter.const_u8(4));
    }
    /* execute.simd:2679 [F] s_b_8_2=sym_13056_3_parameter_inst.Q (const) */
    /* execute.simd:2679 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.simd:2679 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.simd:2679 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:2679 [F] s_b_8_6: If s_b_8_5: Jump b_9 else b_10 (const) */
    if (s_b_8_5) 
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
    /* execute.simd:2680 [D] s_b_9_0 = sym_13139_0_value uint32_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_13139_0_value, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_9_1 = (v2u32)s_b_9_0 */
    auto s_b_9_1 = emitter.splat(s_b_9_0, emitter.context().types().v2u32());
    /* execute.simd:2681 [F] s_b_9_2=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2681 [D] s_b_9_3: WriteRegBank 19:s_b_9_2 = s_b_9_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_1);
    /* execute.simd:2682 [F] s_b_9_4=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2682 [F] s_b_9_5 = constant u64 0 (const) */
    /* execute.simd:2682 [F] s_b_9_6: WriteRegBank 3:s_b_9_4 = s_b_9_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2680 [F] s_b_9_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2684 [D] s_b_10_0 = sym_13139_0_value uint32_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_13139_0_value, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_10_1 = (v4u32)s_b_10_0 */
    auto s_b_10_1 = emitter.splat(s_b_10_0, emitter.context().types().v4u32());
    /* execute.simd:2685 [F] s_b_10_2=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2685 [D] s_b_10_3: WriteRegBank 20:s_b_10_2 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_1,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_1);
    /* execute.simd:2684 [F] s_b_10_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_11: 
  {
    /* execute.simd:2691 [D] s_b_11_0 = sym_13062_0_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_13062_0_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 8 s_b_11_0 => sym_13174_0_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_13174_0_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(8));
    }
    /* execute.simd:2693 [F] s_b_11_2=sym_13056_3_parameter_inst.Q (const) */
    /* execute.simd:2693 [F] s_b_11_3 = (u32)s_b_11_2 (const) */
    /* execute.simd:2693 [F] s_b_11_4 = constant u32 0 (const) */
    /* execute.simd:2693 [F] s_b_11_5 = s_b_11_3==s_b_11_4 (const) */
    uint8_t s_b_11_5 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:2693 [F] s_b_11_6: If s_b_11_5: Jump b_12 else b_13 (const) */
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
    /* execute.simd:2694 [F] s_b_12_0=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2694 [D] s_b_12_1 = sym_13174_0_value uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_13174_0_value, emitter.context().types().u64());
    /* execute.simd:2694 [D] s_b_12_2: WriteRegBank 2:s_b_12_0 = s_b_12_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_1);
    /* execute.simd:2695 [F] s_b_12_3=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2695 [F] s_b_12_4 = constant u64 0 (const) */
    /* execute.simd:2695 [F] s_b_12_5: WriteRegBank 3:s_b_12_3 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2694 [F] s_b_12_6: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:2697 [D] s_b_13_0 = sym_13174_0_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_13174_0_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = (v2u64)s_b_13_0 */
    auto s_b_13_1 = emitter.splat(s_b_13_0, emitter.context().types().v2u64());
    /* execute.simd:2698 [F] s_b_13_2=sym_13056_3_parameter_inst.rt (const) */
    /* execute.simd:2698 [D] s_b_13_3: WriteRegBank 21:s_b_13_2 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1);
    /* execute.simd:2697 [F] s_b_13_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2774 [F] s_b_14_0=sym_13056_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2774 [D] s_b_14_2: sym_66247_1__R_s_b_0_5 = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_66247_1__R_s_b_0_5, s_b_14_1);
    /* execute.a64:2774 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14, b_20,  */
  fixed_block_b_15: 
  {
    /* execute.simd:2644 [D] s_b_15_0 = sym_66247_1__R_s_b_0_5 uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_66247_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2644 [D] s_b_15_1: sym_13062_0_addr = s_b_15_0, dominates: s_b_11_0 s_b_8_0 s_b_5_0 s_b_2_0  */
    emitter.store_local(DV_sym_13062_0_addr, s_b_15_0);
    /* execute.simd:2646 [F] s_b_15_2=sym_13056_3_parameter_inst.size (const) */
    /* execute.simd:2647 [F] s_b_15_3 = constant s32 0 (const) */
    /* execute.simd:2661 [F] s_b_15_4 = constant s32 1 (const) */
    /* execute.simd:2675 [F] s_b_15_5 = constant s32 2 (const) */
    /* execute.simd:2689 [F] s_b_15_6 = constant s32 3 (const) */
    /* execute.simd:2646 [F] s_b_15_7: Switch s_b_15_2: < <todo> > def b_1 (const) -> b_11, b_8, b_5, b_2, b_1,  */
    switch (insn.size) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_0,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2742 [F] s_b_16_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_16_1 = __builtin_get_feature */
    uint32_t s_b_16_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_16_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(s_b_16_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_21 (const) */
    if (s_b_16_3) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2743 [D] s_b_17_0 = ReadReg 20 (u64) */
    auto s_b_17_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_17_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_17_1: sym_66285_1__R_s_b_21_0 = s_b_17_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_66285_1__R_s_b_21_0, s_b_17_0);
    /* execute.a64:2743 [F] s_b_17_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_21,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2746 [D] s_b_18_0 = ReadReg 20 (u64) */
    auto s_b_18_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_18_1: sym_66285_1__R_s_b_21_0 = s_b_18_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_66285_1__R_s_b_21_0, s_b_18_0);
    /* execute.a64:2746 [F] s_b_18_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_21,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2748 [D] s_b_19_0 = ReadReg 21 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_19_1: sym_66285_1__R_s_b_21_0 = s_b_19_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_66285_1__R_s_b_21_0, s_b_19_0);
    /* execute.a64:2748 [F] s_b_19_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_17, b_18, b_19,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2772 [D] s_b_20_0 = sym_66285_1__R_s_b_21_0 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_66285_1__R_s_b_21_0, emitter.context().types().u64());
    /* execute.a64:2772 [D] s_b_20_1: sym_66247_1__R_s_b_0_5 = s_b_20_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_66247_1__R_s_b_0_5, s_b_20_0);
    /* execute.a64:2772 [F] s_b_20_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_16,  */
  fixed_block_b_21: 
  {
    /* execute.a64:3053 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_21_1 = __builtin_get_feature */
    uint32_t s_b_21_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_21_2 = (u8)s_b_21_1 (const) */
    /* execute.a64:2745 [F] s_b_21_3 = (u32)s_b_21_2 (const) */
    /* execute.a64:2745 [F] s_b_21_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_21_5 = s_b_21_3==s_b_21_4 (const) */
    uint8_t s_b_21_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_21_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_21_6: If s_b_21_5: Jump b_18 else b_19 (const) */
    if (s_b_21_5) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_19;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldar(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_70132_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69712_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69741_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69932_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_70060_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_71176_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_71198_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69844_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_13887_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2771 [F] s_b_0_0=sym_13881_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2771 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_4 (const) */
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
    /* execute.a64:896 [D] s_b_1_0 = sym_13887_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_13887_0_address, emitter.context().types().u64());
    /* execute.a64:896 [D] s_b_1_1: sym_69741_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_69741_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2 = Load 4 s_b_1_0 => sym_69844_0_data32 */
    auto s_b_1_2 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_69844_0_data32, s_b_1_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_2, emitter.const_u8(4));
    }
    /* execute.a64:1734 [D] s_b_1_3 = sym_69844_0_data32 uint32_t */
    auto s_b_1_3 = emitter.load_local(DV_sym_69844_0_data32, emitter.context().types().u32());
    /* execute.a64:1734 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2734 [F] s_b_1_5=sym_13881_3_parameter_inst.rt (const) */
    /* execute.a64:2734 [D] s_b_1_6 = (u32)s_b_1_4 */
    auto s_b_1_6 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_1_8: sym_71176_3_parameter_value = s_b_1_7, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_71176_3_parameter_value, s_b_1_7);
    /* execute.a64:2723 [F] s_b_1_9 = (u32)s_b_1_5 (const) */
    /* execute.a64:2723 [F] s_b_1_10 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_1_11 = s_b_1_9==s_b_1_10 (const) */
    uint8_t s_b_1_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_1_12: If s_b_1_11: Jump b_6 else b_14 (const) */
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
    /* execute.a64:898 [D] s_b_3_0 = sym_13887_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_13887_0_address, emitter.context().types().u64());
    /* execute.a64:898 [D] s_b_3_1: sym_69932_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_69932_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2 = Load 8 s_b_3_0 => sym_70060_0_data64 */
    auto s_b_3_2 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_70060_0_data64, s_b_3_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(8));
    }
    /* execute.a64:1742 [D] s_b_3_3 = sym_70060_0_data64 uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_70060_0_data64, emitter.context().types().u64());
    /* execute.a64:2732 [F] s_b_3_4=sym_13881_3_parameter_inst.rt (const) */
    /* execute.a64:2732 [D] s_b_3_5: sym_71198_3_parameter_value = s_b_3_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_71198_3_parameter_value, s_b_3_3);
    /* execute.a64:2723 [F] s_b_3_6 = (u32)s_b_3_4 (const) */
    /* execute.a64:2723 [F] s_b_3_7 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_3_8 = s_b_3_6==s_b_3_7 (const) */
    uint8_t s_b_3_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_3_9: If s_b_3_8: Jump b_7 else b_15 (const) */
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
    /* execute.a64:2774 [F] s_b_4_0=sym_13881_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2774 [D] s_b_4_2: sym_69712_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_69712_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2774 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:893 [D] s_b_5_0 = sym_69712_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_69712_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:893 [D] s_b_5_1: sym_13887_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_13887_0_address, s_b_5_0);
    /* execute.a64:895 [F] s_b_5_2=sym_13881_3_parameter_inst.size (const) */
    /* execute.a64:895 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:895 [F] s_b_5_4 = constant u32 2 (const) */
    /* execute.a64:895 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:895 [F] s_b_5_6: If s_b_5_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1764 [F] s_b_6_0 = constant u32 0 (const) */
    /* execute.a64:1764 [D] s_b_6_1 = sym_69741_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_69741_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1764 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* execute.a64:0 [F] s_b_6_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3, b_15,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1764 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1764 [D] s_b_7_1 = sym_69932_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_69932_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1764 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* execute.a64:0 [F] s_b_7_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2742 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_8_4: If s_b_8_3: Jump b_9 else b_13 (const) */
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
    /* execute.a64:2743 [D] s_b_9_0 = ReadReg 20 (u64) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_9_1: sym_70132_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_70132_1__R_s_b_7_0, s_b_9_0);
    /* execute.a64:2743 [F] s_b_9_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2746 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_10_1: sym_70132_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_70132_1__R_s_b_7_0, s_b_10_0);
    /* execute.a64:2746 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2748 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_11_1: sym_70132_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_70132_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2748 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2772 [D] s_b_12_0 = sym_70132_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_70132_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2772 [D] s_b_12_1: sym_69712_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_69712_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2772 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_8,  */
  fixed_block_b_13: 
  {
    /* execute.a64:3053 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_13_2 = (u8)s_b_13_1 (const) */
    /* execute.a64:2745 [F] s_b_13_3 = (u32)s_b_13_2 (const) */
    /* execute.a64:2745 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
    uint8_t s_b_13_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_13_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_13_6: If s_b_13_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2725 [F] s_b_14_0=sym_13881_3_parameter_inst.rt (const) */
    /* execute.a64:2725 [D] s_b_14_1 = sym_71176_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_71176_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
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
    /* execute.a64:2725 [F] s_b_15_0=sym_13881_3_parameter_inst.rt (const) */
    /* execute.a64:2725 [D] s_b_15_1 = sym_71198_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_71198_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldp(const arm64_decode_a64_LS_REG_PAIR_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14202_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14219_0_data1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14225_0_data2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14239_0_data1 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_14245_0_data2 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_88698_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88322_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88632_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88562_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88470_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88412_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2771 [F] s_b_0_0=sym_14196_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2771 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_4 (const) */
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
    /* execute.a64:1565 [D] s_b_1_0 = sym_14202_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14202_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_1 = Load 8 s_b_1_0 => sym_14219_0_data1 */
    auto s_b_1_1 = emitter.load_memory(s_b_1_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_14219_0_data1, s_b_1_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_1, emitter.const_u8(8));
    }
    /* execute.a64:1566 [F] s_b_1_2 = constant u64 8 (const) */
    /* execute.a64:1566 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_1_4 = Load 8 s_b_1_3 => sym_14225_0_data2 */
    auto s_b_1_4 = emitter.load_memory(s_b_1_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_14225_0_data2, s_b_1_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_3, s_b_1_4, emitter.const_u8(8));
    }
    /* execute.a64:1568 [D] s_b_1_5 = sym_14219_0_data1 uint64_t */
    auto s_b_1_5 = emitter.load_local(DV_sym_14219_0_data1, emitter.context().types().u64());
    /* execute.a64:2732 [F] s_b_1_6=sym_14196_3_parameter_inst.rt (const) */
    /* execute.a64:2732 [D] s_b_1_7: sym_88470_3_parameter_value = s_b_1_5, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_88470_3_parameter_value, s_b_1_5);
    /* execute.a64:2723 [F] s_b_1_8 = (u32)s_b_1_6 (const) */
    /* execute.a64:2723 [F] s_b_1_9 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_1_10 = s_b_1_8==s_b_1_9 (const) */
    uint8_t s_b_1_10 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_1_11: If s_b_1_10: Jump b_6 else b_13 (const) */
    if (s_b_1_10) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_6, b_7, b_16, b_17,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_5,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1574 [D] s_b_3_0 = sym_14202_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14202_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_1 = Load 4 s_b_3_0 => sym_14239_0_data1 */
    auto s_b_3_1 = emitter.load_memory(s_b_3_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_14239_0_data1, s_b_3_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_1, emitter.const_u8(4));
    }
    /* execute.a64:1575 [F] s_b_3_2 = constant u64 4 (const) */
    /* execute.a64:1575 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64((uint64_t)4ULL));
    /* ???:4294967295 [D] s_b_3_4 = Load 4 s_b_3_3 => sym_14245_0_data2 */
    auto s_b_3_4 = emitter.load_memory(s_b_3_3, emitter.context().types().u32());
    emitter.store_local(DV_sym_14245_0_data2, s_b_3_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_3, s_b_3_4, emitter.const_u8(4));
    }
    /* execute.a64:1577 [D] s_b_3_5 = sym_14239_0_data1 uint32_t */
    auto s_b_3_5 = emitter.load_local(DV_sym_14239_0_data1, emitter.context().types().u32());
    /* execute.a64:1577 [D] s_b_3_6 = (u64)s_b_3_5 */
    auto s_b_3_6 = emitter.zx(s_b_3_5, emitter.context().types().u64());
    /* execute.a64:2734 [F] s_b_3_7=sym_14196_3_parameter_inst.rt (const) */
    /* execute.a64:2734 [D] s_b_3_8 = (u32)s_b_3_6 */
    auto s_b_3_8 = emitter.truncate(s_b_3_6, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_3_9 = (u64)s_b_3_8 */
    auto s_b_3_9 = emitter.zx(s_b_3_8, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_3_10: sym_88562_3_parameter_value = s_b_3_9, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_88562_3_parameter_value, s_b_3_9);
    /* execute.a64:2723 [F] s_b_3_11 = (u32)s_b_3_7 (const) */
    /* execute.a64:2723 [F] s_b_3_12 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_3_13 = s_b_3_11==s_b_3_12 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_3_14: If s_b_3_13: Jump b_7 else b_14 (const) */
    if (s_b_3_13) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2774 [F] s_b_4_0=sym_14196_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2774 [D] s_b_4_2: sym_88322_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_88322_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2774 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1558 [D] s_b_5_0 = sym_88322_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_88322_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1558 [D] s_b_5_1: sym_14202_0_address = s_b_5_0, dominates:  */
    emitter.store_local(DV_sym_14202_0_address, s_b_5_0);
    /* execute.a64:1559 [F] s_b_5_2=sym_14196_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_5_3 = (u64)s_b_5_2 (const) */
    /* ???:4294967295 [D] s_b_5_4 = s_b_5_0+s_b_5_3 */
    auto s_b_5_4 = emitter.add(s_b_5_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1559 [D] s_b_5_5: sym_14202_0_address = s_b_5_4, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14202_0_address, s_b_5_4);
    /* execute.a64:1561 [F] s_b_5_6=sym_14196_3_parameter_inst.opc (const) */
    /* execute.a64:1561 [F] s_b_5_7 = (u32)s_b_5_6 (const) */
    /* execute.a64:1561 [F] s_b_5_8 = constant u32 2 (const) */
    /* execute.a64:1561 [F] s_b_5_9 = s_b_5_7==s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1561 [F] s_b_5_10: If s_b_5_9: Jump b_1 else b_3 (const) */
    if (s_b_5_9) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_1, b_13,  */
  fixed_block_b_6: 
  {
    /* execute.a64:1569 [D] s_b_6_0 = sym_14225_0_data2 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_14225_0_data2, emitter.context().types().u64());
    /* execute.a64:2732 [F] s_b_6_1=sym_14196_3_parameter_inst.rt2 (const) */
    /* execute.a64:2732 [D] s_b_6_2: sym_88632_3_parameter_value = s_b_6_0, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_88632_3_parameter_value, s_b_6_0);
    /* execute.a64:2723 [F] s_b_6_3 = (u32)s_b_6_1 (const) */
    /* execute.a64:2723 [F] s_b_6_4 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_6_6: If s_b_6_5: Jump b_2 else b_16 (const) */
    if (s_b_6_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_3, b_14,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1578 [D] s_b_7_0 = sym_14245_0_data2 uint32_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_14245_0_data2, emitter.context().types().u32());
    /* execute.a64:1578 [D] s_b_7_1 = (u64)s_b_7_0 */
    auto s_b_7_1 = emitter.zx(s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2734 [F] s_b_7_2=sym_14196_3_parameter_inst.rt2 (const) */
    /* execute.a64:2734 [D] s_b_7_3 = (u32)s_b_7_1 */
    auto s_b_7_3 = emitter.truncate(s_b_7_1, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_7_4 = (u64)s_b_7_3 */
    auto s_b_7_4 = emitter.zx(s_b_7_3, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_7_5: sym_88698_3_parameter_value = s_b_7_4, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_88698_3_parameter_value, s_b_7_4);
    /* execute.a64:2723 [F] s_b_7_6 = (u32)s_b_7_2 (const) */
    /* execute.a64:2723 [F] s_b_7_7 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_7_8 = s_b_7_6==s_b_7_7 (const) */
    uint8_t s_b_7_8 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_7_9: If s_b_7_8: Jump b_2 else b_17 (const) */
    if (s_b_7_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2742 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_8_4: If s_b_8_3: Jump b_9 else b_15 (const) */
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
    /* execute.a64:2743 [D] s_b_9_0 = ReadReg 20 (u64) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_9_1: sym_88412_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_88412_1__R_s_b_7_0, s_b_9_0);
    /* execute.a64:2743 [F] s_b_9_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_15,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2746 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_10_1: sym_88412_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_88412_1__R_s_b_7_0, s_b_10_0);
    /* execute.a64:2746 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_15,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2748 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_11_1: sym_88412_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_88412_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2748 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2772 [D] s_b_12_0 = sym_88412_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_88412_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2772 [D] s_b_12_1: sym_88322_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_88322_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2772 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_1,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2725 [F] s_b_13_0=sym_14196_3_parameter_inst.rt (const) */
    /* execute.a64:2725 [D] s_b_13_1 = sym_88470_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_88470_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2725 [F] s_b_14_0=sym_14196_3_parameter_inst.rt (const) */
    /* execute.a64:2725 [D] s_b_14_1 = sym_88562_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_88562_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_8,  */
  fixed_block_b_15: 
  {
    /* execute.a64:3053 [F] s_b_15_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_15_1 = __builtin_get_feature */
    uint32_t s_b_15_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_15_2 = (u8)s_b_15_1 (const) */
    /* execute.a64:2745 [F] s_b_15_3 = (u32)s_b_15_2 (const) */
    /* execute.a64:2745 [F] s_b_15_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_15_5 = s_b_15_3==s_b_15_4 (const) */
    uint8_t s_b_15_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_15_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_15_6: If s_b_15_5: Jump b_10 else b_11 (const) */
    if (s_b_15_5) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2725 [F] s_b_16_0=sym_14196_3_parameter_inst.rt2 (const) */
    /* execute.a64:2725 [D] s_b_16_1 = sym_88632_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_88632_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2725 [F] s_b_17_0=sym_14196_3_parameter_inst.rt2 (const) */
    /* execute.a64:2725 [D] s_b_17_1 = sym_88698_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_88698_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_17_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_17_1);
    /* execute.a64:0 [F] s_b_17_3: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldr_lit_simd(const arm64_decode_a64_LOAD_REG_LIT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_96651_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96724_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14784_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96730_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96578_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3917 [D] s_b_0_0 = read_pc */
    auto s_b_0_0 = emitter.load_pc();
    /* execute.simd:3917 [F] s_b_0_1=sym_14778_3_parameter_inst.label (const) */
    /* execute.simd:3917 [F] s_b_0_2 = (u64)s_b_0_1 (const) */
    /* execute.simd:3917 [D] s_b_0_3 = s_b_0_0+s_b_0_2 */
    auto s_b_0_3 = emitter.add(s_b_0_0, emitter.const_u64(((uint64_t)insn.label)));
    /* execute.simd:3917 [D] s_b_0_4: sym_14784_0_address = s_b_0_3, dominates: s_b_2_0 s_b_3_0 s_b_4_0  */
    emitter.store_local(DV_sym_14784_0_address, s_b_0_3);
    /* execute.simd:3919 [F] s_b_0_5=sym_14778_3_parameter_inst.opc (const) */
    /* execute.simd:3920 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.simd:3924 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.simd:3928 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.simd:3919 [F] s_b_0_9: Switch s_b_0_5: < <todo> > def b_5 (const) -> b_2, b_3, b_4, b_5,  */
    switch (insn.opc) 
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
    default:
      goto fixed_block_b_5;
    }
  }
  /* b_2, b_3, b_4, b_5,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:3921 [D] s_b_2_0 = sym_14784_0_address uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_14784_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_1 = Load 4 s_b_2_0 => sym_96578_0_value */
    auto s_b_2_1 = emitter.load_memory(s_b_2_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_96578_0_value, s_b_2_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_1, emitter.const_u8(4));
    }
    /* execute.simd:3694 [F] s_b_2_2=sym_14778_3_parameter_inst.rt (const) */
    /* execute.simd:3694 [D] s_b_2_3 = sym_96578_0_value uint32_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_96578_0_value, emitter.context().types().u32());
    /* execute.simd:6201 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.simd:6201 [D] s_b_2_5: WriteRegBank 2:s_b_2_2 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_2_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_2_4);
    /* execute.simd:6202 [F] s_b_2_6 = constant u64 0 (const) */
    /* execute.simd:6202 [F] s_b_2_7: WriteRegBank 3:s_b_2_2 = s_b_2_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_8: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:3925 [D] s_b_3_0 = sym_14784_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14784_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_1 = Load 8 s_b_3_0 => sym_96651_0_value */
    auto s_b_3_1 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_96651_0_value, s_b_3_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_1, emitter.const_u8(8));
    }
    /* execute.simd:3701 [F] s_b_3_2=sym_14778_3_parameter_inst.rt (const) */
    /* execute.simd:3701 [D] s_b_3_3 = sym_96651_0_value uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_96651_0_value, emitter.context().types().u64());
    /* execute.simd:6208 [D] s_b_3_4: WriteRegBank 2:s_b_3_2 = s_b_3_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_3);
    /* execute.simd:6209 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_3_6: WriteRegBank 3:s_b_3_2 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_3_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:3929 [D] s_b_4_0 = sym_14784_0_address uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_14784_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_1 = Load 8 s_b_4_0 => sym_96724_0_vl */
    auto s_b_4_1 = emitter.load_memory(s_b_4_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_96724_0_vl, s_b_4_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_4_0, s_b_4_1, emitter.const_u8(8));
    }
    /* execute.simd:3709 [F] s_b_4_2 = constant u64 8 (const) */
    /* execute.simd:3709 [D] s_b_4_3 = s_b_4_0+s_b_4_2 */
    auto s_b_4_3 = emitter.add(s_b_4_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_4_4 = Load 8 s_b_4_3 => sym_96730_0_vh */
    auto s_b_4_4 = emitter.load_memory(s_b_4_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_96730_0_vh, s_b_4_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_4_3, s_b_4_4, emitter.const_u8(8));
    }
    /* execute.simd:3710 [F] s_b_4_5=sym_14778_3_parameter_inst.rt (const) */
    /* execute.simd:3710 [D] s_b_4_6 = sym_96724_0_vl uint64_t */
    auto s_b_4_6 = emitter.load_local(DV_sym_96724_0_vl, emitter.context().types().u64());
    /* execute.simd:3710 [D] s_b_4_7 = sym_96730_0_vh uint64_t */
    auto s_b_4_7 = emitter.load_local(DV_sym_96730_0_vh, emitter.context().types().u64());
    /* execute.simd:6215 [D] s_b_4_8: WriteRegBank 2:s_b_4_5 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_4_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_4_6);
    /* execute.simd:6216 [D] s_b_4_9: WriteRegBank 3:s_b_4_5 = s_b_4_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_4_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_4_7);
    /* execute.simd:0 [F] s_b_4_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:3933 [D] s_b_5_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:3919 [F] s_b_5_1: Jump b_1 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldrhi(const arm64_decode_a64_LS_REG_UIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_109611_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_15822_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_109415_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109633_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109699_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109531_1__R_s_b_13_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2771 [F] s_b_0_0=sym_15811_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2771 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_4: If s_b_0_3: Jump b_10 else b_8 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_9,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1475 [D] s_b_1_0 = sym_15822_0_value uint16_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15822_0_value, emitter.context().types().u16());
    /* execute.a64:1475 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* execute.a64:2734 [F] s_b_1_2=sym_15811_3_parameter_inst.rt (const) */
    /* execute.a64:2734 [D] s_b_1_3 = (u32)s_b_1_1 */
    auto s_b_1_3 = emitter.truncate(s_b_1_1, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_1_5: sym_109611_3_parameter_value = s_b_1_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_109611_3_parameter_value, s_b_1_4);
    /* execute.a64:2723 [F] s_b_1_6 = (u32)s_b_1_2 (const) */
    /* execute.a64:2723 [F] s_b_1_7 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_1_8 = s_b_1_6==s_b_1_7 (const) */
    uint8_t s_b_1_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_1_9: If s_b_1_8: Jump b_2 else b_15 (const) */
    if (s_b_1_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_1, b_4, b_6, b_7, b_15, b_16, b_17,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_9,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1476 [F] s_b_3_0=sym_15811_3_parameter_inst.opc (const) */
    /* execute.a64:1476 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1476 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1476 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1476 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
    if (s_b_3_3) 
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
    /* execute.a64:1477 [D] s_b_4_0 = sym_15822_0_value uint16_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_15822_0_value, emitter.context().types().u16());
    /* execute.a64:1477 [D] s_b_4_1 = (s16)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s16());
    /* execute.a64:1477 [D] s_b_4_2 = (s64)s_b_4_1 */
    auto s_b_4_2 = emitter.sx(s_b_4_1, emitter.context().types().s64());
    /* execute.a64:1477 [D] s_b_4_3 = (u64)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().u64());
    /* execute.a64:2732 [F] s_b_4_4=sym_15811_3_parameter_inst.rt (const) */
    /* execute.a64:2732 [D] s_b_4_5: sym_109633_3_parameter_value = s_b_4_3, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_109633_3_parameter_value, s_b_4_3);
    /* execute.a64:2723 [F] s_b_4_6 = (u32)s_b_4_4 (const) */
    /* execute.a64:2723 [F] s_b_4_7 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_4_8 = s_b_4_6==s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_4_9: If s_b_4_8: Jump b_2 else b_16 (const) */
    if (s_b_4_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1478 [F] s_b_5_0=sym_15811_3_parameter_inst.opc (const) */
    /* execute.a64:1478 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1478 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:1478 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:1478 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_7 (const) */
    if (s_b_5_3) 
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
    /* execute.a64:1479 [D] s_b_6_0 = sym_15822_0_value uint16_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_15822_0_value, emitter.context().types().u16());
    /* execute.a64:1479 [D] s_b_6_1 = (s16)s_b_6_0 */
    auto s_b_6_1 = emitter.reinterpret(s_b_6_0, emitter.context().types().s16());
    /* execute.a64:1479 [D] s_b_6_2 = (s64)s_b_6_1 */
    auto s_b_6_2 = emitter.sx(s_b_6_1, emitter.context().types().s64());
    /* execute.a64:1479 [D] s_b_6_3 = (u64)s_b_6_2 */
    auto s_b_6_3 = emitter.reinterpret(s_b_6_2, emitter.context().types().u64());
    /* execute.a64:2734 [F] s_b_6_4=sym_15811_3_parameter_inst.rt (const) */
    /* execute.a64:2734 [D] s_b_6_5 = (u32)s_b_6_3 */
    auto s_b_6_5 = emitter.truncate(s_b_6_3, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_6_7: sym_109699_3_parameter_value = s_b_6_6, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_109699_3_parameter_value, s_b_6_6);
    /* execute.a64:2723 [F] s_b_6_8 = (u32)s_b_6_4 (const) */
    /* execute.a64:2723 [F] s_b_6_9 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_6_10 = s_b_6_8==s_b_6_9 (const) */
    uint8_t s_b_6_10 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_6_11: If s_b_6_10: Jump b_2 else b_17 (const) */
    if (s_b_6_10) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1481 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1481 [F] s_b_7_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2774 [F] s_b_8_0=sym_15811_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2774 [D] s_b_8_2: sym_109415_1__R_s_b_0_5 = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_109415_1__R_s_b_0_5, s_b_8_1);
    /* execute.a64:2774 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_14,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1469 [D] s_b_9_0 = sym_109415_1__R_s_b_0_5 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_109415_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1469 [F] s_b_9_1=sym_15811_3_parameter_inst.immu64 (const) */
    /* execute.a64:1469 [D] s_b_9_2 = s_b_9_0+s_b_9_1 */
    auto s_b_9_2 = emitter.add(s_b_9_0, emitter.const_u64(insn.immu64));
    /* ???:4294967295 [D] s_b_9_3 = Load 2 s_b_9_2 => sym_15822_0_value */
    auto s_b_9_3 = emitter.load_memory(s_b_9_2, emitter.context().types().u16());
    emitter.store_local(DV_sym_15822_0_value, s_b_9_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_2, s_b_9_3, emitter.const_u8(2));
    }
    /* execute.a64:1474 [F] s_b_9_4=sym_15811_3_parameter_inst.opc (const) */
    /* execute.a64:1474 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.a64:1474 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.a64:1474 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:1474 [F] s_b_9_8: If s_b_9_7: Jump b_1 else b_3 (const) */
    if (s_b_9_7) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2742 [F] s_b_10_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_10_1 = __builtin_get_feature */
    uint32_t s_b_10_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(s_b_10_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_10_4: If s_b_10_3: Jump b_11 else b_18 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2743 [D] s_b_11_0 = ReadReg 20 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_11_1: sym_109531_1__R_s_b_13_0 = s_b_11_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109531_1__R_s_b_13_0, s_b_11_0);
    /* execute.a64:2743 [F] s_b_11_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_18,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2746 [D] s_b_12_0 = ReadReg 20 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_12_1: sym_109531_1__R_s_b_13_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109531_1__R_s_b_13_0, s_b_12_0);
    /* execute.a64:2746 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2748 [D] s_b_13_0 = ReadReg 21 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_13_1: sym_109531_1__R_s_b_13_0 = s_b_13_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109531_1__R_s_b_13_0, s_b_13_0);
    /* execute.a64:2748 [F] s_b_13_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_11, b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2772 [D] s_b_14_0 = sym_109531_1__R_s_b_13_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_109531_1__R_s_b_13_0, emitter.context().types().u64());
    /* execute.a64:2772 [D] s_b_14_1: sym_109415_1__R_s_b_0_5 = s_b_14_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_109415_1__R_s_b_0_5, s_b_14_0);
    /* execute.a64:2772 [F] s_b_14_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2725 [F] s_b_15_0=sym_15811_3_parameter_inst.rt (const) */
    /* execute.a64:2725 [D] s_b_15_1 = sym_109611_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_109611_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_15_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_15_1);
    /* execute.a64:0 [F] s_b_15_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2725 [F] s_b_16_0=sym_15811_3_parameter_inst.rt (const) */
    /* execute.a64:2725 [D] s_b_16_1 = sym_109633_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_109633_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2725 [F] s_b_17_0=sym_15811_3_parameter_inst.rt (const) */
    /* execute.a64:2725 [D] s_b_17_1 = sym_109699_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_109699_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1);
    /* execute.a64:0 [F] s_b_17_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_10,  */
  fixed_block_b_18: 
  {
    /* execute.a64:3053 [F] s_b_18_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_18_1 = __builtin_get_feature */
    uint32_t s_b_18_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_18_2 = (u8)s_b_18_1 (const) */
    /* execute.a64:2745 [F] s_b_18_3 = (u32)s_b_18_2 (const) */
    /* execute.a64:2745 [F] s_b_18_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_18_5 = s_b_18_3==s_b_18_4 (const) */
    uint8_t s_b_18_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_18_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_18_6: If s_b_18_5: Jump b_12 else b_13 (const) */
    if (s_b_18_5) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldtrsw(const arm64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldxrh(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_120988_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_121026_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_121825_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_121089_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_121144_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2771 [F] s_b_0_0=sym_16384_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2771 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_4: If s_b_0_3: Jump b_3 else b_1 (const) */
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
    /* execute.a64:2774 [F] s_b_1_0=sym_16384_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2774 [D] s_b_1_2: sym_120988_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_120988_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2774 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:722 [D] s_b_2_0 = sym_120988_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_120988_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:723 [D] s_b_2_1: sym_121089_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_121089_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 2 s_b_2_0 => sym_121144_0_data16 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_121144_0_data16, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(2));
    }
    /* execute.a64:1718 [D] s_b_2_3 = sym_121144_0_data16 uint16_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_121144_0_data16, emitter.context().types().u16());
    /* execute.a64:1718 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2734 [F] s_b_2_5=sym_16384_3_parameter_inst.rt (const) */
    /* execute.a64:2734 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_2_8: sym_121825_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_121825_3_parameter_value, s_b_2_7);
    /* execute.a64:2723 [F] s_b_2_9 = (u32)s_b_2_5 (const) */
    /* execute.a64:2723 [F] s_b_2_10 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_2_11 = s_b_2_9==s_b_2_10 (const) */
    uint8_t s_b_2_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_2_12: If s_b_2_11: Jump b_8 else b_10 (const) */
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
    /* execute.a64:2742 [F] s_b_3_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_3_1 = __builtin_get_feature */
    uint32_t s_b_3_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(s_b_3_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_9 (const) */
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
    /* execute.a64:2743 [D] s_b_4_0 = ReadReg 20 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_4_1: sym_121026_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_121026_1__R_s_b_4_0, s_b_4_0);
    /* execute.a64:2743 [F] s_b_4_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2746 [D] s_b_5_0 = ReadReg 20 (u64) */
    auto s_b_5_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_5_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_5_1: sym_121026_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_121026_1__R_s_b_4_0, s_b_5_0);
    /* execute.a64:2746 [F] s_b_5_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2748 [D] s_b_6_0 = ReadReg 21 (u64) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_6_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_6_1: sym_121026_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_121026_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2748 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2772 [D] s_b_7_0 = sym_121026_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_121026_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2772 [D] s_b_7_1: sym_120988_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_120988_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2772 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1764 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1764 [D] s_b_8_1 = sym_121089_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_121089_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1764 [D] s_b_8_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Return */
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:3053 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_9_2 = (u8)s_b_9_1 (const) */
    /* execute.a64:2745 [F] s_b_9_3 = (u32)s_b_9_2 (const) */
    /* execute.a64:2745 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_9_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_9_6: If s_b_9_5: Jump b_5 else b_6 (const) */
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
    /* execute.a64:2725 [F] s_b_10_0=sym_16384_3_parameter_inst.rt (const) */
    /* execute.a64:2725 [D] s_b_10_1 = sym_121825_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_121825_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_movn(const arm64_decode_a64_MOVE_WIDE_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_125502_3_parameter_value;
  uint64_t CV_sym_125532_3_parameter_value;
  uint64_t CV_sym_125554_3_parameter_value;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:244 [F] s_b_0_0=sym_16734_3_parameter_inst.imm16 (const) */
    /* execute.a64:244 [F] s_b_0_1 = (u64)s_b_0_0 (const) */
    /* execute.a64:244 [F] s_b_0_2=sym_16734_3_parameter_inst.shift_amount (const) */
    /* execute.a64:244 [F] s_b_0_3 = (u64)s_b_0_2 (const) */
    /* execute.a64:244 [F] s_b_0_4 = s_b_0_1<<s_b_0_3 (const) */
    uint64_t s_b_0_4 = ((uint64_t)(((uint64_t)insn.imm16) << ((uint64_t)insn.shift_amount)));
    /* execute.a64:245 [F] s_b_0_5=sym_16734_3_parameter_inst.sf (const) */
    /* execute.a64:245 [F] s_b_0_6 = ~s_b_0_4 (const) */
    uint64_t s_b_0_6 = ~s_b_0_4;
    /* execute.a64:245 [F] s_b_0_7: sym_125502_3_parameter_value = s_b_0_6 (const), dominates: s_b_1_1 s_b_2_1  */
    CV_sym_125502_3_parameter_value = s_b_0_6;
    /* execute.a64:2731 [F] s_b_0_8: If s_b_0_5: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2732 [F] s_b_1_0=sym_16734_3_parameter_inst.rd (const) */
    /* execute.a64:2732 [F] s_b_1_1 = sym_125502_3_parameter_value (const) uint64_t */
    uint64_t s_b_1_1 = CV_sym_125502_3_parameter_value;
    /* execute.a64:2732 [F] s_b_1_2: sym_125532_3_parameter_value = s_b_1_1 (const), dominates: s_b_4_1  */
    CV_sym_125532_3_parameter_value = s_b_1_1;
    /* execute.a64:2723 [F] s_b_1_3 = (u32)s_b_1_0 (const) */
    /* execute.a64:2723 [F] s_b_1_4 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
    uint8_t s_b_1_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_1_6: If s_b_1_5: Jump b_3 else b_4 (const) */
    if (s_b_1_5) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2734 [F] s_b_2_0=sym_16734_3_parameter_inst.rd (const) */
    /* execute.a64:2734 [F] s_b_2_1 = sym_125502_3_parameter_value (const) uint64_t */
    uint64_t s_b_2_1 = CV_sym_125502_3_parameter_value;
    /* execute.a64:2734 [F] s_b_2_2 = (u32)s_b_2_1 (const) */
    /* execute.a64:2734 [F] s_b_2_3 = (u64)s_b_2_2 (const) */
    /* execute.a64:2734 [F] s_b_2_4: sym_125554_3_parameter_value = s_b_2_3 (const), dominates: s_b_5_1  */
    CV_sym_125554_3_parameter_value = ((uint64_t)((uint32_t)s_b_2_1));
    /* execute.a64:2723 [F] s_b_2_5 = (u32)s_b_2_0 (const) */
    /* execute.a64:2723 [F] s_b_2_6 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_2_7 = s_b_2_5==s_b_2_6 (const) */
    uint8_t s_b_2_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_2_8: If s_b_2_7: Jump b_3 else b_5 (const) */
    if (s_b_2_7) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_1, b_2, b_4, b_5,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [F] s_b_3_0: Return */
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2725 [F] s_b_4_0=sym_16734_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [F] s_b_4_1 = sym_125532_3_parameter_value (const) uint64_t */
    uint64_t s_b_4_1 = CV_sym_125532_3_parameter_value;
    /* execute.a64:2725 [F] s_b_4_2: WriteRegBank 0:s_b_4_0 = s_b_4_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64(s_b_4_1),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64(s_b_4_1));
    /* execute.a64:0 [F] s_b_4_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2725 [F] s_b_5_0=sym_16734_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [F] s_b_5_1 = sym_125554_3_parameter_value (const) uint64_t */
    uint64_t s_b_5_1 = CV_sym_125554_3_parameter_value;
    /* execute.a64:2725 [F] s_b_5_2: WriteRegBank 0:s_b_5_0 = s_b_5_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64(s_b_5_1),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64(s_b_5_1));
    /* execute.a64:0 [F] s_b_5_3: Jump b_3 (const) */
    goto fixed_block_b_3;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_mul_vector(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1214 [F] s_b_0_0=sym_18821_3_parameter_inst.arrangement (const) */
    /* execute.simd:1215 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:1224 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:1232 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:1241 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:1249 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:1258 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:1214 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4, b_5, b_6, b_7,  */
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
    /* execute.simd:1216 [F] s_b_2_0=sym_18821_3_parameter_inst.rn (const) */
    /* execute.simd:1216 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1217 [F] s_b_2_2=sym_18821_3_parameter_inst.rm (const) */
    /* execute.simd:1217 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* execute.simd:1218 [D] s_b_2_4 = s_b_2_1*s_b_2_3 */
    auto s_b_2_4 = emitter.mul(s_b_2_1, s_b_2_3);
    /* execute.simd:1220 [F] s_b_2_5=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1220 [D] s_b_2_6: WriteRegBank 15:s_b_2_5 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4);
    /* execute.simd:1221 [F] s_b_2_7=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1221 [F] s_b_2_8 = constant u64 0 (const) */
    /* execute.simd:1221 [F] s_b_2_9: WriteRegBank 3:s_b_2_7 = s_b_2_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1225 [F] s_b_3_0=sym_18821_3_parameter_inst.rn (const) */
    /* execute.simd:1225 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:1226 [F] s_b_3_2=sym_18821_3_parameter_inst.rm (const) */
    /* execute.simd:1226 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:1227 [D] s_b_3_4 = s_b_3_1*s_b_3_3 */
    auto s_b_3_4 = emitter.mul(s_b_3_1, s_b_3_3);
    /* execute.simd:1229 [F] s_b_3_5=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1229 [D] s_b_3_6: WriteRegBank 16:s_b_3_5 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:0 [F] s_b_3_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1233 [F] s_b_4_0=sym_18821_3_parameter_inst.rn (const) */
    /* execute.simd:1233 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:1234 [F] s_b_4_2=sym_18821_3_parameter_inst.rm (const) */
    /* execute.simd:1234 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* execute.simd:1235 [D] s_b_4_4 = s_b_4_1*s_b_4_3 */
    auto s_b_4_4 = emitter.mul(s_b_4_1, s_b_4_3);
    /* execute.simd:1237 [F] s_b_4_5=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1237 [D] s_b_4_6: WriteRegBank 17:s_b_4_5 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:1238 [F] s_b_4_7=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1238 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:1238 [F] s_b_4_9: WriteRegBank 3:s_b_4_7 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:1242 [F] s_b_5_0=sym_18821_3_parameter_inst.rn (const) */
    /* execute.simd:1242 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1243 [F] s_b_5_2=sym_18821_3_parameter_inst.rm (const) */
    /* execute.simd:1243 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1244 [D] s_b_5_4 = s_b_5_1*s_b_5_3 */
    auto s_b_5_4 = emitter.mul(s_b_5_1, s_b_5_3);
    /* execute.simd:1246 [F] s_b_5_5=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1246 [D] s_b_5_6: WriteRegBank 18:s_b_5_5 = s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4);
    /* execute.simd:0 [F] s_b_5_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:1250 [F] s_b_6_0=sym_18821_3_parameter_inst.rn (const) */
    /* execute.simd:1250 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1251 [F] s_b_6_2=sym_18821_3_parameter_inst.rm (const) */
    /* execute.simd:1251 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1252 [D] s_b_6_4 = s_b_6_1*s_b_6_3 */
    auto s_b_6_4 = emitter.mul(s_b_6_1, s_b_6_3);
    /* execute.simd:1254 [F] s_b_6_5=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1254 [D] s_b_6_6: WriteRegBank 19:s_b_6_5 = s_b_6_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
    /* execute.simd:1255 [F] s_b_6_7=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1255 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:1255 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:1259 [F] s_b_7_0=sym_18821_3_parameter_inst.rn (const) */
    /* execute.simd:1259 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:1260 [F] s_b_7_2=sym_18821_3_parameter_inst.rm (const) */
    /* execute.simd:1260 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:1261 [D] s_b_7_4 = s_b_7_1*s_b_7_3 */
    auto s_b_7_4 = emitter.mul(s_b_7_1, s_b_7_3);
    /* execute.simd:1263 [F] s_b_7_5=sym_18821_3_parameter_inst.rd (const) */
    /* execute.simd:1263 [D] s_b_7_6: WriteRegBank 20:s_b_7_5 = s_b_7_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4);
    /* execute.simd:0 [F] s_b_7_7: Jump b_1 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_pmull(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5182 [F] s_b_0_0=sym_19273_3_parameter_inst.tb (const) */
    /* execute.simd:5183 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5196 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5209 [F] s_b_0_3 = constant s32 6 (const) */
    /* execute.simd:5217 [F] s_b_0_4 = constant s32 7 (const) */
    /* execute.simd:5182 [F] s_b_0_5: Switch s_b_0_0: < <todo> > def b_6 (const) -> b_2, b_3, b_4, b_5, b_6,  */
    switch (insn.tb) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_5;
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
    /* execute.simd:5184 [F] s_b_2_0=sym_19273_3_parameter_inst.rn (const) */
    /* execute.simd:5184 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5185 [F] s_b_2_2=sym_19273_3_parameter_inst.rm (const) */
    /* execute.simd:5185 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_5 = constant u8 0 (const) */
    /* execute.simd:5190 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5190 [D] s_b_2_3[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5190 [D] s_b_2_9 = __builtin_polymul8 */
    auto s_b_2_9 = emitter.call(__captive___builtin_polymul8, s_b_2_6, s_b_2_8);
    /* execute.simd:5190 [F] s_b_2_10 = constant s32 0 (const) */
    /* execute.simd:5190 [D] s_b_2_11 = s_b_2_4[s_b_2_10] <= s_b_2_9 */
    auto s_b_2_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_9);
    /* ???:4294967295 [F] s_b_2_12 = constant u8 1 (const) */
    /* execute.simd:5190 [D] s_b_2_1[s_b_2_12] */
    auto s_b_2_13 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_2_14 = constant u8 1 (const) */
    /* execute.simd:5190 [D] s_b_2_3[s_b_2_14] */
    auto s_b_2_15 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5190 [D] s_b_2_16 = __builtin_polymul8 */
    auto s_b_2_16 = emitter.call(__captive___builtin_polymul8, s_b_2_13, s_b_2_15);
    /* execute.simd:5190 [F] s_b_2_17 = constant s32 1 (const) */
    /* execute.simd:5190 [D] s_b_2_18 = s_b_2_11[s_b_2_17] <= s_b_2_16 */
    auto s_b_2_18 = emitter.vector_insert(s_b_2_11, emitter.const_s32((int32_t)1ULL), s_b_2_16);
    /* ???:4294967295 [F] s_b_2_19 = constant u8 2 (const) */
    /* execute.simd:5190 [D] s_b_2_1[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_2_21 = constant u8 2 (const) */
    /* execute.simd:5190 [D] s_b_2_3[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5190 [D] s_b_2_23 = __builtin_polymul8 */
    auto s_b_2_23 = emitter.call(__captive___builtin_polymul8, s_b_2_20, s_b_2_22);
    /* execute.simd:5190 [F] s_b_2_24 = constant s32 2 (const) */
    /* execute.simd:5190 [D] s_b_2_25 = s_b_2_18[s_b_2_24] <= s_b_2_23 */
    auto s_b_2_25 = emitter.vector_insert(s_b_2_18, emitter.const_s32((int32_t)2ULL), s_b_2_23);
    /* ???:4294967295 [F] s_b_2_26 = constant u8 3 (const) */
    /* execute.simd:5190 [D] s_b_2_1[s_b_2_26] */
    auto s_b_2_27 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_2_28 = constant u8 3 (const) */
    /* execute.simd:5190 [D] s_b_2_3[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5190 [D] s_b_2_30 = __builtin_polymul8 */
    auto s_b_2_30 = emitter.call(__captive___builtin_polymul8, s_b_2_27, s_b_2_29);
    /* execute.simd:5190 [F] s_b_2_31 = constant s32 3 (const) */
    /* execute.simd:5190 [D] s_b_2_32 = s_b_2_25[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_25, emitter.const_s32((int32_t)3ULL), s_b_2_30);
    /* ???:4294967295 [F] s_b_2_33 = constant u8 4 (const) */
    /* execute.simd:5190 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [F] s_b_2_35 = constant u8 4 (const) */
    /* execute.simd:5190 [D] s_b_2_3[s_b_2_35] */
    auto s_b_2_36 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5190 [D] s_b_2_37 = __builtin_polymul8 */
    auto s_b_2_37 = emitter.call(__captive___builtin_polymul8, s_b_2_34, s_b_2_36);
    /* execute.simd:5190 [F] s_b_2_38 = constant s32 4 (const) */
    /* execute.simd:5190 [D] s_b_2_39 = s_b_2_32[s_b_2_38] <= s_b_2_37 */
    auto s_b_2_39 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)4ULL), s_b_2_37);
    /* ???:4294967295 [F] s_b_2_40 = constant u8 5 (const) */
    /* execute.simd:5190 [D] s_b_2_1[s_b_2_40] */
    auto s_b_2_41 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [F] s_b_2_42 = constant u8 5 (const) */
    /* execute.simd:5190 [D] s_b_2_3[s_b_2_42] */
    auto s_b_2_43 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5190 [D] s_b_2_44 = __builtin_polymul8 */
    auto s_b_2_44 = emitter.call(__captive___builtin_polymul8, s_b_2_41, s_b_2_43);
    /* execute.simd:5190 [F] s_b_2_45 = constant s32 5 (const) */
    /* execute.simd:5190 [D] s_b_2_46 = s_b_2_39[s_b_2_45] <= s_b_2_44 */
    auto s_b_2_46 = emitter.vector_insert(s_b_2_39, emitter.const_s32((int32_t)5ULL), s_b_2_44);
    /* ???:4294967295 [F] s_b_2_47 = constant u8 6 (const) */
    /* execute.simd:5190 [D] s_b_2_1[s_b_2_47] */
    auto s_b_2_48 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [F] s_b_2_49 = constant u8 6 (const) */
    /* execute.simd:5190 [D] s_b_2_3[s_b_2_49] */
    auto s_b_2_50 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5190 [D] s_b_2_51 = __builtin_polymul8 */
    auto s_b_2_51 = emitter.call(__captive___builtin_polymul8, s_b_2_48, s_b_2_50);
    /* execute.simd:5190 [F] s_b_2_52 = constant s32 6 (const) */
    /* execute.simd:5190 [D] s_b_2_53 = s_b_2_46[s_b_2_52] <= s_b_2_51 */
    auto s_b_2_53 = emitter.vector_insert(s_b_2_46, emitter.const_s32((int32_t)6ULL), s_b_2_51);
    /* ???:4294967295 [F] s_b_2_54 = constant u8 7 (const) */
    /* execute.simd:5190 [D] s_b_2_1[s_b_2_54] */
    auto s_b_2_55 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [F] s_b_2_56 = constant u8 7 (const) */
    /* execute.simd:5190 [D] s_b_2_3[s_b_2_56] */
    auto s_b_2_57 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5190 [D] s_b_2_58 = __builtin_polymul8 */
    auto s_b_2_58 = emitter.call(__captive___builtin_polymul8, s_b_2_55, s_b_2_57);
    /* execute.simd:5190 [F] s_b_2_59 = constant s32 7 (const) */
    /* execute.simd:5190 [D] s_b_2_60 = s_b_2_53[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_53, emitter.const_s32((int32_t)7ULL), s_b_2_58);
    /* execute.simd:5193 [F] s_b_2_61=sym_19273_3_parameter_inst.rd (const) */
    /* execute.simd:5193 [D] s_b_2_62: WriteRegBank 18:s_b_2_61 = s_b_2_60 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_60,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_60);
    /* execute.simd:0 [F] s_b_2_63: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5197 [F] s_b_3_0=sym_19273_3_parameter_inst.rn (const) */
    /* execute.simd:5197 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5198 [F] s_b_3_2=sym_19273_3_parameter_inst.rm (const) */
    /* execute.simd:5198 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5203 [F] s_b_3_5 = constant u32 8 (const) */
    /* execute.simd:5203 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5203 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5203 [D] s_b_3_3[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5203 [D] s_b_3_9 = __builtin_polymul8 */
    auto s_b_3_9 = emitter.call(__captive___builtin_polymul8, s_b_3_6, s_b_3_8);
    /* execute.simd:5203 [F] s_b_3_10 = constant s32 0 (const) */
    /* execute.simd:5203 [D] s_b_3_11 = s_b_3_4[s_b_3_10] <= s_b_3_9 */
    auto s_b_3_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_9);
    /* execute.simd:5203 [F] s_b_3_12 = constant u32 9 (const) */
    /* execute.simd:5203 [D] s_b_3_1[s_b_3_12] */
    auto s_b_3_13 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5203 [F] s_b_3_14 = constant u32 9 (const) */
    /* execute.simd:5203 [D] s_b_3_3[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5203 [D] s_b_3_16 = __builtin_polymul8 */
    auto s_b_3_16 = emitter.call(__captive___builtin_polymul8, s_b_3_13, s_b_3_15);
    /* execute.simd:5203 [F] s_b_3_17 = constant s32 1 (const) */
    /* execute.simd:5203 [D] s_b_3_18 = s_b_3_11[s_b_3_17] <= s_b_3_16 */
    auto s_b_3_18 = emitter.vector_insert(s_b_3_11, emitter.const_s32((int32_t)1ULL), s_b_3_16);
    /* execute.simd:5203 [F] s_b_3_19 = constant u32 a (const) */
    /* execute.simd:5203 [D] s_b_3_1[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5203 [F] s_b_3_21 = constant u32 a (const) */
    /* execute.simd:5203 [D] s_b_3_3[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5203 [D] s_b_3_23 = __builtin_polymul8 */
    auto s_b_3_23 = emitter.call(__captive___builtin_polymul8, s_b_3_20, s_b_3_22);
    /* execute.simd:5203 [F] s_b_3_24 = constant s32 2 (const) */
    /* execute.simd:5203 [D] s_b_3_25 = s_b_3_18[s_b_3_24] <= s_b_3_23 */
    auto s_b_3_25 = emitter.vector_insert(s_b_3_18, emitter.const_s32((int32_t)2ULL), s_b_3_23);
    /* execute.simd:5203 [F] s_b_3_26 = constant u32 b (const) */
    /* execute.simd:5203 [D] s_b_3_1[s_b_3_26] */
    auto s_b_3_27 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5203 [F] s_b_3_28 = constant u32 b (const) */
    /* execute.simd:5203 [D] s_b_3_3[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5203 [D] s_b_3_30 = __builtin_polymul8 */
    auto s_b_3_30 = emitter.call(__captive___builtin_polymul8, s_b_3_27, s_b_3_29);
    /* execute.simd:5203 [F] s_b_3_31 = constant s32 3 (const) */
    /* execute.simd:5203 [D] s_b_3_32 = s_b_3_25[s_b_3_31] <= s_b_3_30 */
    auto s_b_3_32 = emitter.vector_insert(s_b_3_25, emitter.const_s32((int32_t)3ULL), s_b_3_30);
    /* execute.simd:5203 [F] s_b_3_33 = constant u32 c (const) */
    /* execute.simd:5203 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5203 [F] s_b_3_35 = constant u32 c (const) */
    /* execute.simd:5203 [D] s_b_3_3[s_b_3_35] */
    auto s_b_3_36 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5203 [D] s_b_3_37 = __builtin_polymul8 */
    auto s_b_3_37 = emitter.call(__captive___builtin_polymul8, s_b_3_34, s_b_3_36);
    /* execute.simd:5203 [F] s_b_3_38 = constant s32 4 (const) */
    /* execute.simd:5203 [D] s_b_3_39 = s_b_3_32[s_b_3_38] <= s_b_3_37 */
    auto s_b_3_39 = emitter.vector_insert(s_b_3_32, emitter.const_s32((int32_t)4ULL), s_b_3_37);
    /* execute.simd:5203 [F] s_b_3_40 = constant u32 d (const) */
    /* execute.simd:5203 [D] s_b_3_1[s_b_3_40] */
    auto s_b_3_41 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5203 [F] s_b_3_42 = constant u32 d (const) */
    /* execute.simd:5203 [D] s_b_3_3[s_b_3_42] */
    auto s_b_3_43 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5203 [D] s_b_3_44 = __builtin_polymul8 */
    auto s_b_3_44 = emitter.call(__captive___builtin_polymul8, s_b_3_41, s_b_3_43);
    /* execute.simd:5203 [F] s_b_3_45 = constant s32 5 (const) */
    /* execute.simd:5203 [D] s_b_3_46 = s_b_3_39[s_b_3_45] <= s_b_3_44 */
    auto s_b_3_46 = emitter.vector_insert(s_b_3_39, emitter.const_s32((int32_t)5ULL), s_b_3_44);
    /* execute.simd:5203 [F] s_b_3_47 = constant u32 e (const) */
    /* execute.simd:5203 [D] s_b_3_1[s_b_3_47] */
    auto s_b_3_48 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5203 [F] s_b_3_49 = constant u32 e (const) */
    /* execute.simd:5203 [D] s_b_3_3[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5203 [D] s_b_3_51 = __builtin_polymul8 */
    auto s_b_3_51 = emitter.call(__captive___builtin_polymul8, s_b_3_48, s_b_3_50);
    /* execute.simd:5203 [F] s_b_3_52 = constant s32 6 (const) */
    /* execute.simd:5203 [D] s_b_3_53 = s_b_3_46[s_b_3_52] <= s_b_3_51 */
    auto s_b_3_53 = emitter.vector_insert(s_b_3_46, emitter.const_s32((int32_t)6ULL), s_b_3_51);
    /* execute.simd:5203 [F] s_b_3_54 = constant u32 f (const) */
    /* execute.simd:5203 [D] s_b_3_1[s_b_3_54] */
    auto s_b_3_55 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5203 [F] s_b_3_56 = constant u32 f (const) */
    /* execute.simd:5203 [D] s_b_3_3[s_b_3_56] */
    auto s_b_3_57 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5203 [D] s_b_3_58 = __builtin_polymul8 */
    auto s_b_3_58 = emitter.call(__captive___builtin_polymul8, s_b_3_55, s_b_3_57);
    /* execute.simd:5203 [F] s_b_3_59 = constant s32 7 (const) */
    /* execute.simd:5203 [D] s_b_3_60 = s_b_3_53[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_53, emitter.const_s32((int32_t)7ULL), s_b_3_58);
    /* execute.simd:5206 [F] s_b_3_61=sym_19273_3_parameter_inst.rd (const) */
    /* execute.simd:5206 [D] s_b_3_62: WriteRegBank 18:s_b_3_61 = s_b_3_60 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_60,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_60);
    /* execute.simd:0 [F] s_b_3_63: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5210 [F] s_b_4_0=sym_19273_3_parameter_inst.rn (const) */
    /* execute.simd:5210 [D] s_b_4_1 = ReadRegBank 7:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5211 [F] s_b_4_2=sym_19273_3_parameter_inst.rm (const) */
    /* execute.simd:5211 [D] s_b_4_3 = ReadRegBank 7:s_b_4_2 (u64) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* execute.simd:5213 [D] s_b_4_4 = __builtin_polymul64 */
    auto s_b_4_4 = emitter.call(__captive___builtin_polymul64, s_b_4_1, s_b_4_3);
    /* execute.simd:5214 [F] s_b_4_5=sym_19273_3_parameter_inst.rd (const) */
    /* execute.simd:5214 [D] s_b_4_6: WriteRegBank 22:s_b_4_5 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:0 [F] s_b_4_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5218 [F] s_b_5_0=sym_19273_3_parameter_inst.rn (const) */
    /* execute.simd:5218 [D] s_b_5_1 = ReadRegBank 21:s_b_5_0 (v2u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5219 [F] s_b_5_2=sym_19273_3_parameter_inst.rm (const) */
    /* execute.simd:5219 [D] s_b_5_3 = ReadRegBank 21:s_b_5_2 (v2u64) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:5221 [F] s_b_5_4 = constant s32 1 (const) */
    /* execute.simd:5221 [D] s_b_5_1[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5221 [F] s_b_5_6 = constant s32 1 (const) */
    /* execute.simd:5221 [D] s_b_5_3[s_b_5_6] */
    auto s_b_5_7 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5221 [D] s_b_5_8 = __builtin_polymul64 */
    auto s_b_5_8 = emitter.call(__captive___builtin_polymul64, s_b_5_5, s_b_5_7);
    /* execute.simd:5222 [F] s_b_5_9=sym_19273_3_parameter_inst.rd (const) */
    /* execute.simd:5222 [D] s_b_5_10: WriteRegBank 22:s_b_5_9 = s_b_5_8 */
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
    /* execute.simd:5226 [D] s_b_6_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5182 [F] s_b_6_1: Jump b_1 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_rev(const arm64_decode_a64_DP_1S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_128785_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_128686_1_temporary_value;
  auto DV_sym_128686_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_128851_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_128601_1_temporary_value;
  auto DV_sym_128601_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2209 [F] s_b_0_0=sym_19772_3_parameter_inst.sf (const) */
    /* execute.a64:2209 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
    if (insn.sf) 
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
    /* execute.a64:2210 [F] s_b_1_0=sym_19772_3_parameter_inst.rn (const) */
    /* execute.a64:2692 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2692 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_6, b_9, b_10, b_11,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2212 [F] s_b_3_0=sym_19772_3_parameter_inst.rn (const) */
    /* execute.a64:2687 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:2687 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2692 [F] s_b_4_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_4_1: sym_128601_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_128601_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_128601_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2692 [F] s_b_5_0=sym_19772_3_parameter_inst.rn (const) */
    /* execute.a64:2692 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_5_2: sym_128601_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_128601_1_temporary_value, s_b_5_1);
    /* execute.a64:2692 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2692 [D] s_b_6_0 = sym_128601_1_temporary_value uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_128601_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2210 [D] s_b_6_1 = __builtin_bswap64 */
    auto s_b_6_1 = emitter.bswap(s_b_6_0);
    /* execute.a64:2732 [F] s_b_6_2=sym_19772_3_parameter_inst.rd (const) */
    /* execute.a64:2732 [D] s_b_6_3: sym_128785_3_parameter_value = s_b_6_1, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_128785_3_parameter_value, s_b_6_1);
    /* execute.a64:2723 [F] s_b_6_4 = (u32)s_b_6_2 (const) */
    /* execute.a64:2723 [F] s_b_6_5 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_6_6 = s_b_6_4==s_b_6_5 (const) */
    uint8_t s_b_6_6 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_6_7: If s_b_6_6: Jump b_2 else b_10 (const) */
    if (s_b_6_6) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2687 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_7_1: sym_128686_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_128686_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_128686_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2687 [F] s_b_8_0=sym_19772_3_parameter_inst.rn (const) */
    /* execute.a64:2687 [D] s_b_8_1 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_8_2: sym_128686_1_temporary_value = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_128686_1_temporary_value, s_b_8_1);
    /* execute.a64:2687 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2687 [D] s_b_9_0 = sym_128686_1_temporary_value uint32_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_128686_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_9_1 = (u64)s_b_9_0 */
    auto s_b_9_1 = emitter.zx(s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2212 [D] s_b_9_2 = (u32)s_b_9_1 */
    auto s_b_9_2 = emitter.truncate(s_b_9_1, emitter.context().types().u32());
    /* execute.a64:2212 [D] s_b_9_3 = __builtin_bswap32 */
    auto s_b_9_3 = emitter.bswap(s_b_9_2);
    /* execute.a64:2212 [D] s_b_9_4 = (u64)s_b_9_3 */
    auto s_b_9_4 = emitter.zx(s_b_9_3, emitter.context().types().u64());
    /* execute.a64:2734 [F] s_b_9_5=sym_19772_3_parameter_inst.rd (const) */
    /* execute.a64:2734 [D] s_b_9_6 = (u32)s_b_9_4 */
    auto s_b_9_6 = emitter.truncate(s_b_9_4, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_9_7 = (u64)s_b_9_6 */
    auto s_b_9_7 = emitter.zx(s_b_9_6, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_9_8: sym_128851_3_parameter_value = s_b_9_7, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_128851_3_parameter_value, s_b_9_7);
    /* execute.a64:2723 [F] s_b_9_9 = (u32)s_b_9_5 (const) */
    /* execute.a64:2723 [F] s_b_9_10 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_9_11 = s_b_9_9==s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_9_12: If s_b_9_11: Jump b_2 else b_11 (const) */
    if (s_b_9_11) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_6,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2725 [F] s_b_10_0=sym_19772_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [D] s_b_10_1 = sym_128785_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_128785_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1);
    /* execute.a64:0 [F] s_b_10_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2725 [F] s_b_11_0=sym_19772_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [D] s_b_11_1 = sym_128851_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_128851_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1);
    /* execute.a64:0 [F] s_b_11_3: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_saddw(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5569 [F] s_b_0_0=sym_21130_3_parameter_inst.tb (const) */
    /* execute.simd:5570 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5583 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5596 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5609 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5622 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5635 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5569 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5571 [F] s_b_2_0=sym_21130_3_parameter_inst.rn (const) */
    /* execute.simd:5571 [D] s_b_2_1 = ReadRegBank 18:s_b_2_0 (v8u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(16));
    }
    /* execute.simd:5571 [D] s_b_2_2 = (v8s16)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s16());
    /* execute.simd:5572 [F] s_b_2_3=sym_21130_3_parameter_inst.rm (const) */
    /* execute.simd:5572 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5572 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5577 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_2_9 = constant u8 0 (const) */
    /* execute.simd:5577 [D] s_b_2_5[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5577 [D] s_b_2_11 = (s16)s_b_2_10 */
    auto s_b_2_11 = emitter.sx(s_b_2_10, emitter.context().types().s16());
    /* execute.simd:5577 [D] s_b_2_12 = s_b_2_8+s_b_2_11 */
    auto s_b_2_12 = emitter.add(s_b_2_8, s_b_2_11);
    /* execute.simd:5577 [F] s_b_2_13 = constant s32 0 (const) */
    /* execute.simd:5577 [D] s_b_2_14 = s_b_2_6[s_b_2_13] <= s_b_2_12 */
    auto s_b_2_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_12);
    /* ???:4294967295 [F] s_b_2_15 = constant u8 1 (const) */
    /* execute.simd:5577 [D] s_b_2_2[s_b_2_15] */
    auto s_b_2_16 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_2_17 = constant u8 1 (const) */
    /* execute.simd:5577 [D] s_b_2_5[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5577 [D] s_b_2_19 = (s16)s_b_2_18 */
    auto s_b_2_19 = emitter.sx(s_b_2_18, emitter.context().types().s16());
    /* execute.simd:5577 [D] s_b_2_20 = s_b_2_16+s_b_2_19 */
    auto s_b_2_20 = emitter.add(s_b_2_16, s_b_2_19);
    /* execute.simd:5577 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:5577 [D] s_b_2_22 = s_b_2_14[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_14, emitter.const_s32((int32_t)1ULL), s_b_2_20);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 2 (const) */
    /* execute.simd:5577 [D] s_b_2_2[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5577 [D] s_b_2_5[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5577 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* execute.simd:5577 [D] s_b_2_28 = s_b_2_24+s_b_2_27 */
    auto s_b_2_28 = emitter.add(s_b_2_24, s_b_2_27);
    /* execute.simd:5577 [F] s_b_2_29 = constant s32 2 (const) */
    /* execute.simd:5577 [D] s_b_2_30 = s_b_2_22[s_b_2_29] <= s_b_2_28 */
    auto s_b_2_30 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)2ULL), s_b_2_28);
    /* ???:4294967295 [F] s_b_2_31 = constant u8 3 (const) */
    /* execute.simd:5577 [D] s_b_2_2[s_b_2_31] */
    auto s_b_2_32 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_2_33 = constant u8 3 (const) */
    /* execute.simd:5577 [D] s_b_2_5[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5577 [D] s_b_2_35 = (s16)s_b_2_34 */
    auto s_b_2_35 = emitter.sx(s_b_2_34, emitter.context().types().s16());
    /* execute.simd:5577 [D] s_b_2_36 = s_b_2_32+s_b_2_35 */
    auto s_b_2_36 = emitter.add(s_b_2_32, s_b_2_35);
    /* execute.simd:5577 [F] s_b_2_37 = constant s32 3 (const) */
    /* execute.simd:5577 [D] s_b_2_38 = s_b_2_30[s_b_2_37] <= s_b_2_36 */
    auto s_b_2_38 = emitter.vector_insert(s_b_2_30, emitter.const_s32((int32_t)3ULL), s_b_2_36);
    /* ???:4294967295 [F] s_b_2_39 = constant u8 4 (const) */
    /* execute.simd:5577 [D] s_b_2_2[s_b_2_39] */
    auto s_b_2_40 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [F] s_b_2_41 = constant u8 4 (const) */
    /* execute.simd:5577 [D] s_b_2_5[s_b_2_41] */
    auto s_b_2_42 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5577 [D] s_b_2_43 = (s16)s_b_2_42 */
    auto s_b_2_43 = emitter.sx(s_b_2_42, emitter.context().types().s16());
    /* execute.simd:5577 [D] s_b_2_44 = s_b_2_40+s_b_2_43 */
    auto s_b_2_44 = emitter.add(s_b_2_40, s_b_2_43);
    /* execute.simd:5577 [F] s_b_2_45 = constant s32 4 (const) */
    /* execute.simd:5577 [D] s_b_2_46 = s_b_2_38[s_b_2_45] <= s_b_2_44 */
    auto s_b_2_46 = emitter.vector_insert(s_b_2_38, emitter.const_s32((int32_t)4ULL), s_b_2_44);
    /* ???:4294967295 [F] s_b_2_47 = constant u8 5 (const) */
    /* execute.simd:5577 [D] s_b_2_2[s_b_2_47] */
    auto s_b_2_48 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [F] s_b_2_49 = constant u8 5 (const) */
    /* execute.simd:5577 [D] s_b_2_5[s_b_2_49] */
    auto s_b_2_50 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5577 [D] s_b_2_51 = (s16)s_b_2_50 */
    auto s_b_2_51 = emitter.sx(s_b_2_50, emitter.context().types().s16());
    /* execute.simd:5577 [D] s_b_2_52 = s_b_2_48+s_b_2_51 */
    auto s_b_2_52 = emitter.add(s_b_2_48, s_b_2_51);
    /* execute.simd:5577 [F] s_b_2_53 = constant s32 5 (const) */
    /* execute.simd:5577 [D] s_b_2_54 = s_b_2_46[s_b_2_53] <= s_b_2_52 */
    auto s_b_2_54 = emitter.vector_insert(s_b_2_46, emitter.const_s32((int32_t)5ULL), s_b_2_52);
    /* ???:4294967295 [F] s_b_2_55 = constant u8 6 (const) */
    /* execute.simd:5577 [D] s_b_2_2[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [F] s_b_2_57 = constant u8 6 (const) */
    /* execute.simd:5577 [D] s_b_2_5[s_b_2_57] */
    auto s_b_2_58 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5577 [D] s_b_2_59 = (s16)s_b_2_58 */
    auto s_b_2_59 = emitter.sx(s_b_2_58, emitter.context().types().s16());
    /* execute.simd:5577 [D] s_b_2_60 = s_b_2_56+s_b_2_59 */
    auto s_b_2_60 = emitter.add(s_b_2_56, s_b_2_59);
    /* execute.simd:5577 [F] s_b_2_61 = constant s32 6 (const) */
    /* execute.simd:5577 [D] s_b_2_62 = s_b_2_54[s_b_2_61] <= s_b_2_60 */
    auto s_b_2_62 = emitter.vector_insert(s_b_2_54, emitter.const_s32((int32_t)6ULL), s_b_2_60);
    /* ???:4294967295 [F] s_b_2_63 = constant u8 7 (const) */
    /* execute.simd:5577 [D] s_b_2_2[s_b_2_63] */
    auto s_b_2_64 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [F] s_b_2_65 = constant u8 7 (const) */
    /* execute.simd:5577 [D] s_b_2_5[s_b_2_65] */
    auto s_b_2_66 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5577 [D] s_b_2_67 = (s16)s_b_2_66 */
    auto s_b_2_67 = emitter.sx(s_b_2_66, emitter.context().types().s16());
    /* execute.simd:5577 [D] s_b_2_68 = s_b_2_64+s_b_2_67 */
    auto s_b_2_68 = emitter.add(s_b_2_64, s_b_2_67);
    /* execute.simd:5577 [F] s_b_2_69 = constant s32 7 (const) */
    /* execute.simd:5577 [D] s_b_2_70 = s_b_2_62[s_b_2_69] <= s_b_2_68 */
    auto s_b_2_70 = emitter.vector_insert(s_b_2_62, emitter.const_s32((int32_t)7ULL), s_b_2_68);
    /* execute.simd:5580 [F] s_b_2_71=sym_21130_3_parameter_inst.rd (const) */
    /* execute.simd:5580 [D] s_b_2_72 = (v8u16)s_b_2_70 */
    auto s_b_2_72 = emitter.reinterpret(s_b_2_70, emitter.context().types().v8u16());
    /* execute.simd:5580 [D] s_b_2_73: WriteRegBank 18:s_b_2_71 = s_b_2_72 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_72,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_72);
    /* execute.simd:0 [F] s_b_2_74: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5584 [F] s_b_3_0=sym_21130_3_parameter_inst.rn (const) */
    /* execute.simd:5584 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5584 [D] s_b_3_2 = (v8s16)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v8s16());
    /* execute.simd:5585 [F] s_b_3_3=sym_21130_3_parameter_inst.rm (const) */
    /* execute.simd:5585 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5585 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_3_7 = constant u8 0 (const) */
    /* execute.simd:5590 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5590 [F] s_b_3_9 = constant u32 8 (const) */
    /* execute.simd:5590 [D] s_b_3_5[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5590 [D] s_b_3_11 = (s16)s_b_3_10 */
    auto s_b_3_11 = emitter.sx(s_b_3_10, emitter.context().types().s16());
    /* execute.simd:5590 [D] s_b_3_12 = s_b_3_8+s_b_3_11 */
    auto s_b_3_12 = emitter.add(s_b_3_8, s_b_3_11);
    /* execute.simd:5590 [F] s_b_3_13 = constant s32 0 (const) */
    /* execute.simd:5590 [D] s_b_3_14 = s_b_3_6[s_b_3_13] <= s_b_3_12 */
    auto s_b_3_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_12);
    /* ???:4294967295 [F] s_b_3_15 = constant u8 1 (const) */
    /* execute.simd:5590 [D] s_b_3_2[s_b_3_15] */
    auto s_b_3_16 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5590 [F] s_b_3_17 = constant u32 9 (const) */
    /* execute.simd:5590 [D] s_b_3_5[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5590 [D] s_b_3_19 = (s16)s_b_3_18 */
    auto s_b_3_19 = emitter.sx(s_b_3_18, emitter.context().types().s16());
    /* execute.simd:5590 [D] s_b_3_20 = s_b_3_16+s_b_3_19 */
    auto s_b_3_20 = emitter.add(s_b_3_16, s_b_3_19);
    /* execute.simd:5590 [F] s_b_3_21 = constant s32 1 (const) */
    /* execute.simd:5590 [D] s_b_3_22 = s_b_3_14[s_b_3_21] <= s_b_3_20 */
    auto s_b_3_22 = emitter.vector_insert(s_b_3_14, emitter.const_s32((int32_t)1ULL), s_b_3_20);
    /* ???:4294967295 [F] s_b_3_23 = constant u8 2 (const) */
    /* execute.simd:5590 [D] s_b_3_2[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5590 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5590 [D] s_b_3_5[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5590 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5590 [D] s_b_3_28 = s_b_3_24+s_b_3_27 */
    auto s_b_3_28 = emitter.add(s_b_3_24, s_b_3_27);
    /* execute.simd:5590 [F] s_b_3_29 = constant s32 2 (const) */
    /* execute.simd:5590 [D] s_b_3_30 = s_b_3_22[s_b_3_29] <= s_b_3_28 */
    auto s_b_3_30 = emitter.vector_insert(s_b_3_22, emitter.const_s32((int32_t)2ULL), s_b_3_28);
    /* ???:4294967295 [F] s_b_3_31 = constant u8 3 (const) */
    /* execute.simd:5590 [D] s_b_3_2[s_b_3_31] */
    auto s_b_3_32 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5590 [F] s_b_3_33 = constant u32 b (const) */
    /* execute.simd:5590 [D] s_b_3_5[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5590 [D] s_b_3_35 = (s16)s_b_3_34 */
    auto s_b_3_35 = emitter.sx(s_b_3_34, emitter.context().types().s16());
    /* execute.simd:5590 [D] s_b_3_36 = s_b_3_32+s_b_3_35 */
    auto s_b_3_36 = emitter.add(s_b_3_32, s_b_3_35);
    /* execute.simd:5590 [F] s_b_3_37 = constant s32 3 (const) */
    /* execute.simd:5590 [D] s_b_3_38 = s_b_3_30[s_b_3_37] <= s_b_3_36 */
    auto s_b_3_38 = emitter.vector_insert(s_b_3_30, emitter.const_s32((int32_t)3ULL), s_b_3_36);
    /* ???:4294967295 [F] s_b_3_39 = constant u8 4 (const) */
    /* execute.simd:5590 [D] s_b_3_2[s_b_3_39] */
    auto s_b_3_40 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5590 [F] s_b_3_41 = constant u32 c (const) */
    /* execute.simd:5590 [D] s_b_3_5[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5590 [D] s_b_3_43 = (s16)s_b_3_42 */
    auto s_b_3_43 = emitter.sx(s_b_3_42, emitter.context().types().s16());
    /* execute.simd:5590 [D] s_b_3_44 = s_b_3_40+s_b_3_43 */
    auto s_b_3_44 = emitter.add(s_b_3_40, s_b_3_43);
    /* execute.simd:5590 [F] s_b_3_45 = constant s32 4 (const) */
    /* execute.simd:5590 [D] s_b_3_46 = s_b_3_38[s_b_3_45] <= s_b_3_44 */
    auto s_b_3_46 = emitter.vector_insert(s_b_3_38, emitter.const_s32((int32_t)4ULL), s_b_3_44);
    /* ???:4294967295 [F] s_b_3_47 = constant u8 5 (const) */
    /* execute.simd:5590 [D] s_b_3_2[s_b_3_47] */
    auto s_b_3_48 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5590 [F] s_b_3_49 = constant u32 d (const) */
    /* execute.simd:5590 [D] s_b_3_5[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5590 [D] s_b_3_51 = (s16)s_b_3_50 */
    auto s_b_3_51 = emitter.sx(s_b_3_50, emitter.context().types().s16());
    /* execute.simd:5590 [D] s_b_3_52 = s_b_3_48+s_b_3_51 */
    auto s_b_3_52 = emitter.add(s_b_3_48, s_b_3_51);
    /* execute.simd:5590 [F] s_b_3_53 = constant s32 5 (const) */
    /* execute.simd:5590 [D] s_b_3_54 = s_b_3_46[s_b_3_53] <= s_b_3_52 */
    auto s_b_3_54 = emitter.vector_insert(s_b_3_46, emitter.const_s32((int32_t)5ULL), s_b_3_52);
    /* ???:4294967295 [F] s_b_3_55 = constant u8 6 (const) */
    /* execute.simd:5590 [D] s_b_3_2[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5590 [F] s_b_3_57 = constant u32 e (const) */
    /* execute.simd:5590 [D] s_b_3_5[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5590 [D] s_b_3_59 = (s16)s_b_3_58 */
    auto s_b_3_59 = emitter.sx(s_b_3_58, emitter.context().types().s16());
    /* execute.simd:5590 [D] s_b_3_60 = s_b_3_56+s_b_3_59 */
    auto s_b_3_60 = emitter.add(s_b_3_56, s_b_3_59);
    /* execute.simd:5590 [F] s_b_3_61 = constant s32 6 (const) */
    /* execute.simd:5590 [D] s_b_3_62 = s_b_3_54[s_b_3_61] <= s_b_3_60 */
    auto s_b_3_62 = emitter.vector_insert(s_b_3_54, emitter.const_s32((int32_t)6ULL), s_b_3_60);
    /* ???:4294967295 [F] s_b_3_63 = constant u8 7 (const) */
    /* execute.simd:5590 [D] s_b_3_2[s_b_3_63] */
    auto s_b_3_64 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5590 [F] s_b_3_65 = constant u32 f (const) */
    /* execute.simd:5590 [D] s_b_3_5[s_b_3_65] */
    auto s_b_3_66 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5590 [D] s_b_3_67 = (s16)s_b_3_66 */
    auto s_b_3_67 = emitter.sx(s_b_3_66, emitter.context().types().s16());
    /* execute.simd:5590 [D] s_b_3_68 = s_b_3_64+s_b_3_67 */
    auto s_b_3_68 = emitter.add(s_b_3_64, s_b_3_67);
    /* execute.simd:5590 [F] s_b_3_69 = constant s32 7 (const) */
    /* execute.simd:5590 [D] s_b_3_70 = s_b_3_62[s_b_3_69] <= s_b_3_68 */
    auto s_b_3_70 = emitter.vector_insert(s_b_3_62, emitter.const_s32((int32_t)7ULL), s_b_3_68);
    /* execute.simd:5593 [F] s_b_3_71=sym_21130_3_parameter_inst.rd (const) */
    /* execute.simd:5593 [D] s_b_3_72 = (v8u16)s_b_3_70 */
    auto s_b_3_72 = emitter.reinterpret(s_b_3_70, emitter.context().types().v8u16());
    /* execute.simd:5593 [D] s_b_3_73: WriteRegBank 18:s_b_3_71 = s_b_3_72 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_72,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_72);
    /* execute.simd:0 [F] s_b_3_74: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5597 [F] s_b_4_0=sym_21130_3_parameter_inst.rn (const) */
    /* execute.simd:5597 [D] s_b_4_1 = ReadRegBank 20:s_b_4_0 (v4u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:5597 [D] s_b_4_2 = (v4s32)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s32());
    /* execute.simd:5598 [F] s_b_4_3=sym_21130_3_parameter_inst.rm (const) */
    /* execute.simd:5598 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5598 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5603 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_9 = constant u8 0 (const) */
    /* execute.simd:5603 [D] s_b_4_5[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5603 [D] s_b_4_11 = (s32)s_b_4_10 */
    auto s_b_4_11 = emitter.sx(s_b_4_10, emitter.context().types().s32());
    /* execute.simd:5603 [D] s_b_4_12 = s_b_4_8+s_b_4_11 */
    auto s_b_4_12 = emitter.add(s_b_4_8, s_b_4_11);
    /* execute.simd:5603 [F] s_b_4_13 = constant s32 0 (const) */
    /* execute.simd:5603 [D] s_b_4_14 = s_b_4_6[s_b_4_13] <= s_b_4_12 */
    auto s_b_4_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_12);
    /* ???:4294967295 [F] s_b_4_15 = constant u8 1 (const) */
    /* execute.simd:5603 [D] s_b_4_2[s_b_4_15] */
    auto s_b_4_16 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_4_17 = constant u8 1 (const) */
    /* execute.simd:5603 [D] s_b_4_5[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5603 [D] s_b_4_19 = (s32)s_b_4_18 */
    auto s_b_4_19 = emitter.sx(s_b_4_18, emitter.context().types().s32());
    /* execute.simd:5603 [D] s_b_4_20 = s_b_4_16+s_b_4_19 */
    auto s_b_4_20 = emitter.add(s_b_4_16, s_b_4_19);
    /* execute.simd:5603 [F] s_b_4_21 = constant s32 1 (const) */
    /* execute.simd:5603 [D] s_b_4_22 = s_b_4_14[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_14, emitter.const_s32((int32_t)1ULL), s_b_4_20);
    /* ???:4294967295 [F] s_b_4_23 = constant u8 2 (const) */
    /* execute.simd:5603 [D] s_b_4_2[s_b_4_23] */
    auto s_b_4_24 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5603 [D] s_b_4_5[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5603 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* execute.simd:5603 [D] s_b_4_28 = s_b_4_24+s_b_4_27 */
    auto s_b_4_28 = emitter.add(s_b_4_24, s_b_4_27);
    /* execute.simd:5603 [F] s_b_4_29 = constant s32 2 (const) */
    /* execute.simd:5603 [D] s_b_4_30 = s_b_4_22[s_b_4_29] <= s_b_4_28 */
    auto s_b_4_30 = emitter.vector_insert(s_b_4_22, emitter.const_s32((int32_t)2ULL), s_b_4_28);
    /* ???:4294967295 [F] s_b_4_31 = constant u8 3 (const) */
    /* execute.simd:5603 [D] s_b_4_2[s_b_4_31] */
    auto s_b_4_32 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_4_33 = constant u8 3 (const) */
    /* execute.simd:5603 [D] s_b_4_5[s_b_4_33] */
    auto s_b_4_34 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5603 [D] s_b_4_35 = (s32)s_b_4_34 */
    auto s_b_4_35 = emitter.sx(s_b_4_34, emitter.context().types().s32());
    /* execute.simd:5603 [D] s_b_4_36 = s_b_4_32+s_b_4_35 */
    auto s_b_4_36 = emitter.add(s_b_4_32, s_b_4_35);
    /* execute.simd:5603 [F] s_b_4_37 = constant s32 3 (const) */
    /* execute.simd:5603 [D] s_b_4_38 = s_b_4_30[s_b_4_37] <= s_b_4_36 */
    auto s_b_4_38 = emitter.vector_insert(s_b_4_30, emitter.const_s32((int32_t)3ULL), s_b_4_36);
    /* execute.simd:5606 [F] s_b_4_39=sym_21130_3_parameter_inst.rd (const) */
    /* execute.simd:5606 [D] s_b_4_40 = (v4u32)s_b_4_38 */
    auto s_b_4_40 = emitter.reinterpret(s_b_4_38, emitter.context().types().v4u32());
    /* execute.simd:5606 [D] s_b_4_41: WriteRegBank 20:s_b_4_39 = s_b_4_40 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_40,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_40);
    /* execute.simd:0 [F] s_b_4_42: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5610 [F] s_b_5_0=sym_21130_3_parameter_inst.rn (const) */
    /* execute.simd:5610 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5610 [D] s_b_5_2 = (v4s32)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v4s32());
    /* execute.simd:5611 [F] s_b_5_3=sym_21130_3_parameter_inst.rm (const) */
    /* execute.simd:5611 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5611 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_5_7 = constant u8 0 (const) */
    /* execute.simd:5616 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5616 [F] s_b_5_9 = constant u32 4 (const) */
    /* execute.simd:5616 [D] s_b_5_5[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5616 [D] s_b_5_11 = (s32)s_b_5_10 */
    auto s_b_5_11 = emitter.sx(s_b_5_10, emitter.context().types().s32());
    /* execute.simd:5616 [D] s_b_5_12 = s_b_5_8+s_b_5_11 */
    auto s_b_5_12 = emitter.add(s_b_5_8, s_b_5_11);
    /* execute.simd:5616 [F] s_b_5_13 = constant s32 0 (const) */
    /* execute.simd:5616 [D] s_b_5_14 = s_b_5_6[s_b_5_13] <= s_b_5_12 */
    auto s_b_5_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_12);
    /* ???:4294967295 [F] s_b_5_15 = constant u8 1 (const) */
    /* execute.simd:5616 [D] s_b_5_2[s_b_5_15] */
    auto s_b_5_16 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5616 [F] s_b_5_17 = constant u32 5 (const) */
    /* execute.simd:5616 [D] s_b_5_5[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5616 [D] s_b_5_19 = (s32)s_b_5_18 */
    auto s_b_5_19 = emitter.sx(s_b_5_18, emitter.context().types().s32());
    /* execute.simd:5616 [D] s_b_5_20 = s_b_5_16+s_b_5_19 */
    auto s_b_5_20 = emitter.add(s_b_5_16, s_b_5_19);
    /* execute.simd:5616 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5616 [D] s_b_5_22 = s_b_5_14[s_b_5_21] <= s_b_5_20 */
    auto s_b_5_22 = emitter.vector_insert(s_b_5_14, emitter.const_s32((int32_t)1ULL), s_b_5_20);
    /* ???:4294967295 [F] s_b_5_23 = constant u8 2 (const) */
    /* execute.simd:5616 [D] s_b_5_2[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5616 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5616 [D] s_b_5_5[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5616 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5616 [D] s_b_5_28 = s_b_5_24+s_b_5_27 */
    auto s_b_5_28 = emitter.add(s_b_5_24, s_b_5_27);
    /* execute.simd:5616 [F] s_b_5_29 = constant s32 2 (const) */
    /* execute.simd:5616 [D] s_b_5_30 = s_b_5_22[s_b_5_29] <= s_b_5_28 */
    auto s_b_5_30 = emitter.vector_insert(s_b_5_22, emitter.const_s32((int32_t)2ULL), s_b_5_28);
    /* ???:4294967295 [F] s_b_5_31 = constant u8 3 (const) */
    /* execute.simd:5616 [D] s_b_5_2[s_b_5_31] */
    auto s_b_5_32 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5616 [F] s_b_5_33 = constant u32 7 (const) */
    /* execute.simd:5616 [D] s_b_5_5[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5616 [D] s_b_5_35 = (s32)s_b_5_34 */
    auto s_b_5_35 = emitter.sx(s_b_5_34, emitter.context().types().s32());
    /* execute.simd:5616 [D] s_b_5_36 = s_b_5_32+s_b_5_35 */
    auto s_b_5_36 = emitter.add(s_b_5_32, s_b_5_35);
    /* execute.simd:5616 [F] s_b_5_37 = constant s32 3 (const) */
    /* execute.simd:5616 [D] s_b_5_38 = s_b_5_30[s_b_5_37] <= s_b_5_36 */
    auto s_b_5_38 = emitter.vector_insert(s_b_5_30, emitter.const_s32((int32_t)3ULL), s_b_5_36);
    /* execute.simd:5619 [F] s_b_5_39=sym_21130_3_parameter_inst.rd (const) */
    /* execute.simd:5619 [D] s_b_5_40 = (v4u32)s_b_5_38 */
    auto s_b_5_40 = emitter.reinterpret(s_b_5_38, emitter.context().types().v4u32());
    /* execute.simd:5619 [D] s_b_5_41: WriteRegBank 20:s_b_5_39 = s_b_5_40 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_40,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_40);
    /* execute.simd:0 [F] s_b_5_42: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5623 [F] s_b_6_0=sym_21130_3_parameter_inst.rn (const) */
    /* execute.simd:5623 [D] s_b_6_1 = ReadRegBank 21:s_b_6_0 (v2u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(16));
    }
    /* execute.simd:5623 [D] s_b_6_2 = (v2s64)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s64());
    /* execute.simd:5624 [F] s_b_6_3=sym_21130_3_parameter_inst.rm (const) */
    /* execute.simd:5624 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5624 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5629 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_9 = constant u8 0 (const) */
    /* execute.simd:5629 [D] s_b_6_5[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5629 [D] s_b_6_11 = (s64)s_b_6_10 */
    auto s_b_6_11 = emitter.sx(s_b_6_10, emitter.context().types().s64());
    /* execute.simd:5629 [D] s_b_6_12 = s_b_6_8+s_b_6_11 */
    auto s_b_6_12 = emitter.add(s_b_6_8, s_b_6_11);
    /* execute.simd:5629 [F] s_b_6_13 = constant s32 0 (const) */
    /* execute.simd:5629 [D] s_b_6_14 = s_b_6_6[s_b_6_13] <= s_b_6_12 */
    auto s_b_6_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_12);
    /* ???:4294967295 [F] s_b_6_15 = constant u8 1 (const) */
    /* execute.simd:5629 [D] s_b_6_2[s_b_6_15] */
    auto s_b_6_16 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_6_17 = constant u8 1 (const) */
    /* execute.simd:5629 [D] s_b_6_5[s_b_6_17] */
    auto s_b_6_18 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5629 [D] s_b_6_19 = (s64)s_b_6_18 */
    auto s_b_6_19 = emitter.sx(s_b_6_18, emitter.context().types().s64());
    /* execute.simd:5629 [D] s_b_6_20 = s_b_6_16+s_b_6_19 */
    auto s_b_6_20 = emitter.add(s_b_6_16, s_b_6_19);
    /* execute.simd:5629 [F] s_b_6_21 = constant s32 1 (const) */
    /* execute.simd:5629 [D] s_b_6_22 = s_b_6_14[s_b_6_21] <= s_b_6_20 */
    auto s_b_6_22 = emitter.vector_insert(s_b_6_14, emitter.const_s32((int32_t)1ULL), s_b_6_20);
    /* execute.simd:5632 [F] s_b_6_23=sym_21130_3_parameter_inst.rd (const) */
    /* execute.simd:5632 [D] s_b_6_24 = (v2u64)s_b_6_22 */
    auto s_b_6_24 = emitter.reinterpret(s_b_6_22, emitter.context().types().v2u64());
    /* execute.simd:5632 [D] s_b_6_25: WriteRegBank 21:s_b_6_23 = s_b_6_24 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_24,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_24);
    /* execute.simd:0 [F] s_b_6_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:5636 [F] s_b_7_0=sym_21130_3_parameter_inst.rn (const) */
    /* execute.simd:5636 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5636 [D] s_b_7_2 = (v2s64)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v2s64());
    /* execute.simd:5637 [F] s_b_7_3=sym_21130_3_parameter_inst.rm (const) */
    /* execute.simd:5637 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5637 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_7_7 = constant u8 0 (const) */
    /* execute.simd:5642 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5642 [F] s_b_7_9 = constant u32 2 (const) */
    /* execute.simd:5642 [D] s_b_7_5[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5642 [D] s_b_7_11 = (s64)s_b_7_10 */
    auto s_b_7_11 = emitter.sx(s_b_7_10, emitter.context().types().s64());
    /* execute.simd:5642 [D] s_b_7_12 = s_b_7_8+s_b_7_11 */
    auto s_b_7_12 = emitter.add(s_b_7_8, s_b_7_11);
    /* execute.simd:5642 [F] s_b_7_13 = constant s32 0 (const) */
    /* execute.simd:5642 [D] s_b_7_14 = s_b_7_6[s_b_7_13] <= s_b_7_12 */
    auto s_b_7_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_12);
    /* ???:4294967295 [F] s_b_7_15 = constant u8 1 (const) */
    /* execute.simd:5642 [D] s_b_7_2[s_b_7_15] */
    auto s_b_7_16 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5642 [F] s_b_7_17 = constant u32 3 (const) */
    /* execute.simd:5642 [D] s_b_7_5[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5642 [D] s_b_7_19 = (s64)s_b_7_18 */
    auto s_b_7_19 = emitter.sx(s_b_7_18, emitter.context().types().s64());
    /* execute.simd:5642 [D] s_b_7_20 = s_b_7_16+s_b_7_19 */
    auto s_b_7_20 = emitter.add(s_b_7_16, s_b_7_19);
    /* execute.simd:5642 [F] s_b_7_21 = constant s32 1 (const) */
    /* execute.simd:5642 [D] s_b_7_22 = s_b_7_14[s_b_7_21] <= s_b_7_20 */
    auto s_b_7_22 = emitter.vector_insert(s_b_7_14, emitter.const_s32((int32_t)1ULL), s_b_7_20);
    /* execute.simd:5645 [F] s_b_7_23=sym_21130_3_parameter_inst.rd (const) */
    /* execute.simd:5645 [D] s_b_7_24 = (v2u64)s_b_7_22 */
    auto s_b_7_24 = emitter.reinterpret(s_b_7_22, emitter.context().types().v2u64());
    /* execute.simd:5645 [D] s_b_7_25: WriteRegBank 21:s_b_7_23 = s_b_7_24 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_24,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_24);
    /* execute.simd:0 [F] s_b_7_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:5649 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5569 [F] s_b_8_1: Jump b_1 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_smaddl(const arm64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_132245_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_132156_1_temporary_value;
  auto DV_sym_132156_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_132201_1_tmp_s_b_22_0 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_132204_1_tmp_s_b_22_1 = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_132105_1_temporary_value;
  auto DV_sym_132105_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_132135_1_tmp_s_b_11_0 = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_132042_1_temporary_value;
  auto DV_sym_132042_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2400 [F] s_b_0_0=sym_22605_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2709 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2709 [F] s_b_1_0 = constant s64 0 (const) */
    /* execute.a64:2709 [F] s_b_1_1: sym_132042_1_temporary_value = s_b_1_0 (const), dominates: s_b_3_0  */
    CV_sym_132042_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_132042_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2709 [F] s_b_1_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2709 [F] s_b_2_0=sym_22605_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_2_1 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_2_2 = (s32)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().s32());
    /* execute.a64:2709 [D] s_b_2_3 = (s64)s_b_2_2 */
    auto s_b_2_3 = emitter.sx(s_b_2_2, emitter.context().types().s64());
    /* execute.a64:2709 [D] s_b_2_4: sym_132042_1_temporary_value = s_b_2_3, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_132042_1_temporary_value, s_b_2_3);
    /* execute.a64:2709 [F] s_b_2_5: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2709 [D] s_b_3_0 = sym_132042_1_temporary_value int64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_132042_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2401 [F] s_b_3_1=sym_22605_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_132135_1_tmp_s_b_11_0 = s_b_3_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_132135_1_tmp_s_b_11_0, s_b_3_0);
    /* execute.a64:2709 [F] s_b_3_3 = (u32)s_b_3_1 (const) */
    /* execute.a64:2709 [F] s_b_3_4 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
    uint8_t s_b_3_5 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_3_6: If s_b_3_5: Jump b_4 else b_5 (const) */
    if (s_b_3_5) 
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
    /* execute.a64:2709 [F] s_b_4_0 = constant s64 0 (const) */
    /* execute.a64:2709 [F] s_b_4_1: sym_132105_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_132105_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_132105_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2709 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2709 [F] s_b_5_0=sym_22605_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_5_1 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_5_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_5_2 = (s32)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().s32());
    /* execute.a64:2709 [D] s_b_5_3 = (s64)s_b_5_2 */
    auto s_b_5_3 = emitter.sx(s_b_5_2, emitter.context().types().s64());
    /* execute.a64:2709 [D] s_b_5_4: sym_132105_1_temporary_value = s_b_5_3, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_132105_1_temporary_value, s_b_5_3);
    /* execute.a64:2709 [F] s_b_5_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2709 [D] s_b_6_0 = sym_132105_1_temporary_value int64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_132105_1_temporary_value, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_6_1 = sym_132135_1_tmp_s_b_11_0 int64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_132135_1_tmp_s_b_11_0, emitter.context().types().s64());
    /* execute.a64:2402 [F] s_b_6_2=sym_22605_3_parameter_inst.ra (const) */
    /* ???:4294967295 [D] s_b_6_3: sym_132201_1_tmp_s_b_22_0 = s_b_6_1, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_132201_1_tmp_s_b_22_0, s_b_6_1);
    /* ???:4294967295 [D] s_b_6_4: sym_132204_1_tmp_s_b_22_1 = s_b_6_0, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_132204_1_tmp_s_b_22_1, s_b_6_0);
    /* execute.a64:2707 [F] s_b_6_5 = (u32)s_b_6_2 (const) */
    /* execute.a64:2707 [F] s_b_6_6 = constant u32 1f (const) */
    /* execute.a64:2707 [F] s_b_6_7 = s_b_6_5==s_b_6_6 (const) */
    uint8_t s_b_6_7 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2707 [F] s_b_6_8: If s_b_6_7: Jump b_7 else b_8 (const) */
    if (s_b_6_7) 
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
    /* execute.a64:2707 [F] s_b_7_0 = constant s64 0 (const) */
    /* execute.a64:2707 [F] s_b_7_1: sym_132156_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_132156_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_132156_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2707 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2707 [F] s_b_8_0=sym_22605_3_parameter_inst.ra (const) */
    /* execute.a64:2707 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_8_2 = (s64)s_b_8_1 */
    auto s_b_8_2 = emitter.reinterpret(s_b_8_1, emitter.context().types().s64());
    /* execute.a64:2707 [D] s_b_8_3: sym_132156_1_temporary_value = s_b_8_2, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_132156_1_temporary_value, s_b_8_2);
    /* execute.a64:2707 [F] s_b_8_4: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2707 [D] s_b_9_0 = sym_132156_1_temporary_value int64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_132156_1_temporary_value, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_9_1 = sym_132204_1_tmp_s_b_22_1 int64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_132204_1_tmp_s_b_22_1, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_9_2 = sym_132201_1_tmp_s_b_22_0 int64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_132201_1_tmp_s_b_22_0, emitter.context().types().s64());
    /* execute.a64:2404 [D] s_b_9_3 = (s64)s_b_9_2 */
    auto s_b_9_3 = (captive::arch::dbt::el::Value *)s_b_9_2;
    /* execute.a64:2404 [D] s_b_9_4 = s_b_9_3*s_b_9_1 */
    auto s_b_9_4 = emitter.mul(s_b_9_3, s_b_9_1);
    /* execute.a64:2404 [D] s_b_9_5 = s_b_9_0+s_b_9_4 */
    auto s_b_9_5 = emitter.add(s_b_9_0, s_b_9_4);
    /* execute.a64:2404 [D] s_b_9_6 = (u64)s_b_9_5 */
    auto s_b_9_6 = emitter.reinterpret(s_b_9_5, emitter.context().types().u64());
    /* execute.a64:2732 [F] s_b_9_7=sym_22605_3_parameter_inst.rd (const) */
    /* execute.a64:2732 [D] s_b_9_8: sym_132245_3_parameter_value = s_b_9_6, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_132245_3_parameter_value, s_b_9_6);
    /* execute.a64:2723 [F] s_b_9_9 = (u32)s_b_9_7 (const) */
    /* execute.a64:2723 [F] s_b_9_10 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_9_11 = s_b_9_9==s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
    if (s_b_9_11) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_9, b_11,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [F] s_b_10_0: Return */
    goto fixed_done;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2725 [F] s_b_11_0=sym_22605_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [D] s_b_11_1 = sym_132245_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_132245_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1);
    /* execute.a64:0 [F] s_b_11_3: Jump b_10 (const) */
    goto fixed_block_b_10;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_smull(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5233 [F] s_b_0_0=sym_24545_3_parameter_inst.tb (const) */
    /* execute.simd:5234 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5247 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5260 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5273 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5286 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5299 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5233 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5235 [F] s_b_2_0=sym_24545_3_parameter_inst.rn (const) */
    /* execute.simd:5235 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5235 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:5236 [F] s_b_2_3=sym_24545_3_parameter_inst.rm (const) */
    /* execute.simd:5236 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5236 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5241 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5241 [D] s_b_2_9 = (s16)s_b_2_8 */
    auto s_b_2_9 = emitter.sx(s_b_2_8, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5241 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5241 [D] s_b_2_12 = (s16)s_b_2_11 */
    auto s_b_2_12 = emitter.sx(s_b_2_11, emitter.context().types().s16());
    /* execute.simd:5241 [D] s_b_2_13 = s_b_2_9*s_b_2_12 */
    auto s_b_2_13 = emitter.mul(s_b_2_9, s_b_2_12);
    /* execute.simd:5241 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5241 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5241 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5241 [D] s_b_2_18 = (s16)s_b_2_17 */
    auto s_b_2_18 = emitter.sx(s_b_2_17, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5241 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5241 [D] s_b_2_21 = (s16)s_b_2_20 */
    auto s_b_2_21 = emitter.sx(s_b_2_20, emitter.context().types().s16());
    /* execute.simd:5241 [D] s_b_2_22 = s_b_2_18*s_b_2_21 */
    auto s_b_2_22 = emitter.mul(s_b_2_18, s_b_2_21);
    /* execute.simd:5241 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5241 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5241 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5241 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5241 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5241 [D] s_b_2_30 = (s16)s_b_2_29 */
    auto s_b_2_30 = emitter.sx(s_b_2_29, emitter.context().types().s16());
    /* execute.simd:5241 [D] s_b_2_31 = s_b_2_27*s_b_2_30 */
    auto s_b_2_31 = emitter.mul(s_b_2_27, s_b_2_30);
    /* execute.simd:5241 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5241 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5241 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5241 [D] s_b_2_36 = (s16)s_b_2_35 */
    auto s_b_2_36 = emitter.sx(s_b_2_35, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5241 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5241 [D] s_b_2_39 = (s16)s_b_2_38 */
    auto s_b_2_39 = emitter.sx(s_b_2_38, emitter.context().types().s16());
    /* execute.simd:5241 [D] s_b_2_40 = s_b_2_36*s_b_2_39 */
    auto s_b_2_40 = emitter.mul(s_b_2_36, s_b_2_39);
    /* execute.simd:5241 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5241 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5241 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5241 [D] s_b_2_45 = (s16)s_b_2_44 */
    auto s_b_2_45 = emitter.sx(s_b_2_44, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5241 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5241 [D] s_b_2_48 = (s16)s_b_2_47 */
    auto s_b_2_48 = emitter.sx(s_b_2_47, emitter.context().types().s16());
    /* execute.simd:5241 [D] s_b_2_49 = s_b_2_45*s_b_2_48 */
    auto s_b_2_49 = emitter.mul(s_b_2_45, s_b_2_48);
    /* execute.simd:5241 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5241 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5241 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5241 [D] s_b_2_54 = (s16)s_b_2_53 */
    auto s_b_2_54 = emitter.sx(s_b_2_53, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5241 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5241 [D] s_b_2_57 = (s16)s_b_2_56 */
    auto s_b_2_57 = emitter.sx(s_b_2_56, emitter.context().types().s16());
    /* execute.simd:5241 [D] s_b_2_58 = s_b_2_54*s_b_2_57 */
    auto s_b_2_58 = emitter.mul(s_b_2_54, s_b_2_57);
    /* execute.simd:5241 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5241 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5241 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5241 [D] s_b_2_63 = (s16)s_b_2_62 */
    auto s_b_2_63 = emitter.sx(s_b_2_62, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5241 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5241 [D] s_b_2_66 = (s16)s_b_2_65 */
    auto s_b_2_66 = emitter.sx(s_b_2_65, emitter.context().types().s16());
    /* execute.simd:5241 [D] s_b_2_67 = s_b_2_63*s_b_2_66 */
    auto s_b_2_67 = emitter.mul(s_b_2_63, s_b_2_66);
    /* execute.simd:5241 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5241 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5241 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5241 [D] s_b_2_72 = (s16)s_b_2_71 */
    auto s_b_2_72 = emitter.sx(s_b_2_71, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5241 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5241 [D] s_b_2_75 = (s16)s_b_2_74 */
    auto s_b_2_75 = emitter.sx(s_b_2_74, emitter.context().types().s16());
    /* execute.simd:5241 [D] s_b_2_76 = s_b_2_72*s_b_2_75 */
    auto s_b_2_76 = emitter.mul(s_b_2_72, s_b_2_75);
    /* execute.simd:5241 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5241 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5244 [F] s_b_2_79=sym_24545_3_parameter_inst.rd (const) */
    /* execute.simd:5244 [D] s_b_2_80 = (v8u16)s_b_2_78 */
    auto s_b_2_80 = emitter.reinterpret(s_b_2_78, emitter.context().types().v8u16());
    /* execute.simd:5244 [D] s_b_2_81: WriteRegBank 18:s_b_2_79 = s_b_2_80 */
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
    /* execute.simd:5248 [F] s_b_3_0=sym_24545_3_parameter_inst.rn (const) */
    /* execute.simd:5248 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5248 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:5249 [F] s_b_3_3=sym_24545_3_parameter_inst.rm (const) */
    /* execute.simd:5249 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5249 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:5254 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5254 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5254 [D] s_b_3_9 = (s16)s_b_3_8 */
    auto s_b_3_9 = emitter.sx(s_b_3_8, emitter.context().types().s16());
    /* execute.simd:5254 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5254 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5254 [D] s_b_3_12 = (s16)s_b_3_11 */
    auto s_b_3_12 = emitter.sx(s_b_3_11, emitter.context().types().s16());
    /* execute.simd:5254 [D] s_b_3_13 = s_b_3_9*s_b_3_12 */
    auto s_b_3_13 = emitter.mul(s_b_3_9, s_b_3_12);
    /* execute.simd:5254 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5254 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5254 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5254 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5254 [D] s_b_3_18 = (s16)s_b_3_17 */
    auto s_b_3_18 = emitter.sx(s_b_3_17, emitter.context().types().s16());
    /* execute.simd:5254 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5254 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5254 [D] s_b_3_21 = (s16)s_b_3_20 */
    auto s_b_3_21 = emitter.sx(s_b_3_20, emitter.context().types().s16());
    /* execute.simd:5254 [D] s_b_3_22 = s_b_3_18*s_b_3_21 */
    auto s_b_3_22 = emitter.mul(s_b_3_18, s_b_3_21);
    /* execute.simd:5254 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5254 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5254 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5254 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5254 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5254 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5254 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5254 [D] s_b_3_30 = (s16)s_b_3_29 */
    auto s_b_3_30 = emitter.sx(s_b_3_29, emitter.context().types().s16());
    /* execute.simd:5254 [D] s_b_3_31 = s_b_3_27*s_b_3_30 */
    auto s_b_3_31 = emitter.mul(s_b_3_27, s_b_3_30);
    /* execute.simd:5254 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5254 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5254 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5254 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5254 [D] s_b_3_36 = (s16)s_b_3_35 */
    auto s_b_3_36 = emitter.sx(s_b_3_35, emitter.context().types().s16());
    /* execute.simd:5254 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5254 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5254 [D] s_b_3_39 = (s16)s_b_3_38 */
    auto s_b_3_39 = emitter.sx(s_b_3_38, emitter.context().types().s16());
    /* execute.simd:5254 [D] s_b_3_40 = s_b_3_36*s_b_3_39 */
    auto s_b_3_40 = emitter.mul(s_b_3_36, s_b_3_39);
    /* execute.simd:5254 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5254 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5254 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5254 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5254 [D] s_b_3_45 = (s16)s_b_3_44 */
    auto s_b_3_45 = emitter.sx(s_b_3_44, emitter.context().types().s16());
    /* execute.simd:5254 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5254 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5254 [D] s_b_3_48 = (s16)s_b_3_47 */
    auto s_b_3_48 = emitter.sx(s_b_3_47, emitter.context().types().s16());
    /* execute.simd:5254 [D] s_b_3_49 = s_b_3_45*s_b_3_48 */
    auto s_b_3_49 = emitter.mul(s_b_3_45, s_b_3_48);
    /* execute.simd:5254 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5254 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5254 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5254 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5254 [D] s_b_3_54 = (s16)s_b_3_53 */
    auto s_b_3_54 = emitter.sx(s_b_3_53, emitter.context().types().s16());
    /* execute.simd:5254 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5254 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5254 [D] s_b_3_57 = (s16)s_b_3_56 */
    auto s_b_3_57 = emitter.sx(s_b_3_56, emitter.context().types().s16());
    /* execute.simd:5254 [D] s_b_3_58 = s_b_3_54*s_b_3_57 */
    auto s_b_3_58 = emitter.mul(s_b_3_54, s_b_3_57);
    /* execute.simd:5254 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5254 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5254 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5254 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5254 [D] s_b_3_63 = (s16)s_b_3_62 */
    auto s_b_3_63 = emitter.sx(s_b_3_62, emitter.context().types().s16());
    /* execute.simd:5254 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5254 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5254 [D] s_b_3_66 = (s16)s_b_3_65 */
    auto s_b_3_66 = emitter.sx(s_b_3_65, emitter.context().types().s16());
    /* execute.simd:5254 [D] s_b_3_67 = s_b_3_63*s_b_3_66 */
    auto s_b_3_67 = emitter.mul(s_b_3_63, s_b_3_66);
    /* execute.simd:5254 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5254 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5254 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5254 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5254 [D] s_b_3_72 = (s16)s_b_3_71 */
    auto s_b_3_72 = emitter.sx(s_b_3_71, emitter.context().types().s16());
    /* execute.simd:5254 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5254 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5254 [D] s_b_3_75 = (s16)s_b_3_74 */
    auto s_b_3_75 = emitter.sx(s_b_3_74, emitter.context().types().s16());
    /* execute.simd:5254 [D] s_b_3_76 = s_b_3_72*s_b_3_75 */
    auto s_b_3_76 = emitter.mul(s_b_3_72, s_b_3_75);
    /* execute.simd:5254 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5254 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5257 [F] s_b_3_79=sym_24545_3_parameter_inst.rd (const) */
    /* execute.simd:5257 [D] s_b_3_80 = (v8u16)s_b_3_78 */
    auto s_b_3_80 = emitter.reinterpret(s_b_3_78, emitter.context().types().v8u16());
    /* execute.simd:5257 [D] s_b_3_81: WriteRegBank 18:s_b_3_79 = s_b_3_80 */
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
    /* execute.simd:5261 [F] s_b_4_0=sym_24545_3_parameter_inst.rn (const) */
    /* execute.simd:5261 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5261 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:5262 [F] s_b_4_3=sym_24545_3_parameter_inst.rm (const) */
    /* execute.simd:5262 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5262 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5267 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5267 [D] s_b_4_9 = (s32)s_b_4_8 */
    auto s_b_4_9 = emitter.sx(s_b_4_8, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5267 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5267 [D] s_b_4_12 = (s32)s_b_4_11 */
    auto s_b_4_12 = emitter.sx(s_b_4_11, emitter.context().types().s32());
    /* execute.simd:5267 [D] s_b_4_13 = s_b_4_9*s_b_4_12 */
    auto s_b_4_13 = emitter.mul(s_b_4_9, s_b_4_12);
    /* execute.simd:5267 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5267 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5267 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5267 [D] s_b_4_18 = (s32)s_b_4_17 */
    auto s_b_4_18 = emitter.sx(s_b_4_17, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5267 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5267 [D] s_b_4_21 = (s32)s_b_4_20 */
    auto s_b_4_21 = emitter.sx(s_b_4_20, emitter.context().types().s32());
    /* execute.simd:5267 [D] s_b_4_22 = s_b_4_18*s_b_4_21 */
    auto s_b_4_22 = emitter.mul(s_b_4_18, s_b_4_21);
    /* execute.simd:5267 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5267 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5267 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5267 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5267 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5267 [D] s_b_4_30 = (s32)s_b_4_29 */
    auto s_b_4_30 = emitter.sx(s_b_4_29, emitter.context().types().s32());
    /* execute.simd:5267 [D] s_b_4_31 = s_b_4_27*s_b_4_30 */
    auto s_b_4_31 = emitter.mul(s_b_4_27, s_b_4_30);
    /* execute.simd:5267 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5267 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5267 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5267 [D] s_b_4_36 = (s32)s_b_4_35 */
    auto s_b_4_36 = emitter.sx(s_b_4_35, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5267 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5267 [D] s_b_4_39 = (s32)s_b_4_38 */
    auto s_b_4_39 = emitter.sx(s_b_4_38, emitter.context().types().s32());
    /* execute.simd:5267 [D] s_b_4_40 = s_b_4_36*s_b_4_39 */
    auto s_b_4_40 = emitter.mul(s_b_4_36, s_b_4_39);
    /* execute.simd:5267 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5267 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5270 [F] s_b_4_43=sym_24545_3_parameter_inst.rd (const) */
    /* execute.simd:5270 [D] s_b_4_44 = (v4u32)s_b_4_42 */
    auto s_b_4_44 = emitter.reinterpret(s_b_4_42, emitter.context().types().v4u32());
    /* execute.simd:5270 [D] s_b_4_45: WriteRegBank 20:s_b_4_43 = s_b_4_44 */
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
    /* execute.simd:5274 [F] s_b_5_0=sym_24545_3_parameter_inst.rn (const) */
    /* execute.simd:5274 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5274 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:5275 [F] s_b_5_3=sym_24545_3_parameter_inst.rm (const) */
    /* execute.simd:5275 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5275 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:5280 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5280 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5280 [D] s_b_5_9 = (s32)s_b_5_8 */
    auto s_b_5_9 = emitter.sx(s_b_5_8, emitter.context().types().s32());
    /* execute.simd:5280 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5280 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5280 [D] s_b_5_12 = (s32)s_b_5_11 */
    auto s_b_5_12 = emitter.sx(s_b_5_11, emitter.context().types().s32());
    /* execute.simd:5280 [D] s_b_5_13 = s_b_5_9*s_b_5_12 */
    auto s_b_5_13 = emitter.mul(s_b_5_9, s_b_5_12);
    /* execute.simd:5280 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5280 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5280 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5280 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5280 [D] s_b_5_18 = (s32)s_b_5_17 */
    auto s_b_5_18 = emitter.sx(s_b_5_17, emitter.context().types().s32());
    /* execute.simd:5280 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5280 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5280 [D] s_b_5_21 = (s32)s_b_5_20 */
    auto s_b_5_21 = emitter.sx(s_b_5_20, emitter.context().types().s32());
    /* execute.simd:5280 [D] s_b_5_22 = s_b_5_18*s_b_5_21 */
    auto s_b_5_22 = emitter.mul(s_b_5_18, s_b_5_21);
    /* execute.simd:5280 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5280 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5280 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5280 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5280 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5280 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5280 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5280 [D] s_b_5_30 = (s32)s_b_5_29 */
    auto s_b_5_30 = emitter.sx(s_b_5_29, emitter.context().types().s32());
    /* execute.simd:5280 [D] s_b_5_31 = s_b_5_27*s_b_5_30 */
    auto s_b_5_31 = emitter.mul(s_b_5_27, s_b_5_30);
    /* execute.simd:5280 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5280 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5280 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5280 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5280 [D] s_b_5_36 = (s32)s_b_5_35 */
    auto s_b_5_36 = emitter.sx(s_b_5_35, emitter.context().types().s32());
    /* execute.simd:5280 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5280 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5280 [D] s_b_5_39 = (s32)s_b_5_38 */
    auto s_b_5_39 = emitter.sx(s_b_5_38, emitter.context().types().s32());
    /* execute.simd:5280 [D] s_b_5_40 = s_b_5_36*s_b_5_39 */
    auto s_b_5_40 = emitter.mul(s_b_5_36, s_b_5_39);
    /* execute.simd:5280 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5280 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5283 [F] s_b_5_43=sym_24545_3_parameter_inst.rd (const) */
    /* execute.simd:5283 [D] s_b_5_44 = (v4u32)s_b_5_42 */
    auto s_b_5_44 = emitter.reinterpret(s_b_5_42, emitter.context().types().v4u32());
    /* execute.simd:5283 [D] s_b_5_45: WriteRegBank 20:s_b_5_43 = s_b_5_44 */
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
    /* execute.simd:5287 [F] s_b_6_0=sym_24545_3_parameter_inst.rn (const) */
    /* execute.simd:5287 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5287 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:5288 [F] s_b_6_3=sym_24545_3_parameter_inst.rm (const) */
    /* execute.simd:5288 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5288 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5293 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5293 [D] s_b_6_9 = (s64)s_b_6_8 */
    auto s_b_6_9 = emitter.sx(s_b_6_8, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5293 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5293 [D] s_b_6_12 = (s64)s_b_6_11 */
    auto s_b_6_12 = emitter.sx(s_b_6_11, emitter.context().types().s64());
    /* execute.simd:5293 [D] s_b_6_13 = s_b_6_9*s_b_6_12 */
    auto s_b_6_13 = emitter.mul(s_b_6_9, s_b_6_12);
    /* execute.simd:5293 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5293 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5293 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5293 [D] s_b_6_18 = (s64)s_b_6_17 */
    auto s_b_6_18 = emitter.sx(s_b_6_17, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5293 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5293 [D] s_b_6_21 = (s64)s_b_6_20 */
    auto s_b_6_21 = emitter.sx(s_b_6_20, emitter.context().types().s64());
    /* execute.simd:5293 [D] s_b_6_22 = s_b_6_18*s_b_6_21 */
    auto s_b_6_22 = emitter.mul(s_b_6_18, s_b_6_21);
    /* execute.simd:5293 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5293 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:5296 [F] s_b_6_25=sym_24545_3_parameter_inst.rd (const) */
    /* execute.simd:5296 [D] s_b_6_26 = (v2u64)s_b_6_24 */
    auto s_b_6_26 = emitter.reinterpret(s_b_6_24, emitter.context().types().v2u64());
    /* execute.simd:5296 [D] s_b_6_27: WriteRegBank 21:s_b_6_25 = s_b_6_26 */
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
    /* execute.simd:5300 [F] s_b_7_0=sym_24545_3_parameter_inst.rn (const) */
    /* execute.simd:5300 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5300 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:5301 [F] s_b_7_3=sym_24545_3_parameter_inst.rm (const) */
    /* execute.simd:5301 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5301 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:5306 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:5306 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5306 [D] s_b_7_9 = (s64)s_b_7_8 */
    auto s_b_7_9 = emitter.sx(s_b_7_8, emitter.context().types().s64());
    /* execute.simd:5306 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:5306 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5306 [D] s_b_7_12 = (s64)s_b_7_11 */
    auto s_b_7_12 = emitter.sx(s_b_7_11, emitter.context().types().s64());
    /* execute.simd:5306 [D] s_b_7_13 = s_b_7_9*s_b_7_12 */
    auto s_b_7_13 = emitter.mul(s_b_7_9, s_b_7_12);
    /* execute.simd:5306 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:5306 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:5306 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:5306 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5306 [D] s_b_7_18 = (s64)s_b_7_17 */
    auto s_b_7_18 = emitter.sx(s_b_7_17, emitter.context().types().s64());
    /* execute.simd:5306 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:5306 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5306 [D] s_b_7_21 = (s64)s_b_7_20 */
    auto s_b_7_21 = emitter.sx(s_b_7_20, emitter.context().types().s64());
    /* execute.simd:5306 [D] s_b_7_22 = s_b_7_18*s_b_7_21 */
    auto s_b_7_22 = emitter.mul(s_b_7_18, s_b_7_21);
    /* execute.simd:5306 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:5306 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:5309 [F] s_b_7_25=sym_24545_3_parameter_inst.rd (const) */
    /* execute.simd:5309 [D] s_b_7_26 = (v2u64)s_b_7_24 */
    auto s_b_7_26 = emitter.reinterpret(s_b_7_24, emitter.context().types().v2u64());
    /* execute.simd:5309 [D] s_b_7_27: WriteRegBank 21:s_b_7_25 = s_b_7_26 */
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
    /* execute.simd:5313 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5233 [F] s_b_8_1: Jump b_1 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_st1s(const arm64_decode_a64_SIMD_LS_SINGLE&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_134649_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_134666_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30248_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2751 [F] s_b_0_0=sym_30242_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2771 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_9 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_2, b_3, b_5, b_6, b_7, b_10,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_2: 
  {
    /* execute.simd:2755 [F] s_b_2_0=sym_30242_3_parameter_inst.rt (const) */
    /* execute.simd:2755 [D] s_b_2_1 = ReadRegBank 16:s_b_2_0 (v16u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_2_1,emitter.const_u8(16));
    }
    /* execute.simd:2756 [D] s_b_2_2 = sym_30248_0_addr uint64_t */
    auto s_b_2_2 = emitter.load_local(DV_sym_30248_0_addr, emitter.context().types().u64());
    /* execute.simd:2756 [F] s_b_2_3=sym_30242_3_parameter_inst.eindex (const) */
    /* execute.simd:2756 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_2_5: Store 1 s_b_2_2 <= s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_2_2, s_b_2_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_2_2, s_b_2_4);
    /* execute.simd:0 [F] s_b_2_6: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_10,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2760 [F] s_b_3_0=sym_30242_3_parameter_inst.rt (const) */
    /* execute.simd:2760 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:2761 [D] s_b_3_2 = sym_30248_0_addr uint64_t */
    auto s_b_3_2 = emitter.load_local(DV_sym_30248_0_addr, emitter.context().types().u64());
    /* execute.simd:2761 [F] s_b_3_3=sym_30242_3_parameter_inst.eindex (const) */
    /* execute.simd:2761 [D] s_b_3_1[s_b_3_3] */
    auto s_b_3_4 = emitter.vector_extract(s_b_3_1, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_3_5: Store 2 s_b_3_2 <= s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_2, s_b_3_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_3_2, s_b_3_4);
    /* execute.simd:0 [F] s_b_3_6: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_10,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2765 [F] s_b_4_0=sym_30242_3_parameter_inst.size (const) */
    /* execute.simd:2765 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:2765 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.simd:2765 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:2765 [F] s_b_4_4: If s_b_4_3: Jump b_5 else b_6 (const) */
    if (s_b_4_3) 
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
    /* execute.simd:2766 [F] s_b_5_0=sym_30242_3_parameter_inst.rt (const) */
    /* execute.simd:2766 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:2767 [D] s_b_5_2 = sym_30248_0_addr uint64_t */
    auto s_b_5_2 = emitter.load_local(DV_sym_30248_0_addr, emitter.context().types().u64());
    /* execute.simd:2767 [F] s_b_5_3=sym_30242_3_parameter_inst.eindex (const) */
    /* execute.simd:2767 [D] s_b_5_1[s_b_5_3] */
    auto s_b_5_4 = emitter.vector_extract(s_b_5_1, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_5_5: Store 4 s_b_5_2 <= s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_5_2, s_b_5_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_5_2, s_b_5_4);
    /* execute.simd:2766 [F] s_b_5_6: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2768 [F] s_b_6_0=sym_30242_3_parameter_inst.size (const) */
    /* execute.simd:2768 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.simd:2768 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.simd:2768 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:2768 [F] s_b_6_4: If s_b_6_3: Jump b_7 else b_1 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_1;
    }
  }
  /* b_6,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2769 [F] s_b_7_0=sym_30242_3_parameter_inst.rt (const) */
    /* execute.simd:2769 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:2770 [D] s_b_7_2 = sym_30248_0_addr uint64_t */
    auto s_b_7_2 = emitter.load_local(DV_sym_30248_0_addr, emitter.context().types().u64());
    /* execute.simd:2770 [F] s_b_7_3=sym_30242_3_parameter_inst.eindex (const) */
    /* execute.simd:2770 [D] s_b_7_1[s_b_7_3] */
    auto s_b_7_4 = emitter.vector_extract(s_b_7_1, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_7_5: Store 8 s_b_7_2 <= s_b_7_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_7_2, s_b_7_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_7_2, s_b_7_4);
    /* execute.simd:2769 [F] s_b_7_6: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2742 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_8_4: If s_b_8_3: Jump b_11 else b_12 (const) */
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
    /* execute.a64:2774 [F] s_b_9_0=sym_30242_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_134649_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_134649_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_134649_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_134649_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2751 [D] s_b_10_1: sym_30248_0_addr = s_b_10_0, dominates: s_b_2_2 s_b_3_2 s_b_5_2 s_b_7_2  */
    emitter.store_local(DV_sym_30248_0_addr, s_b_10_0);
    /* execute.simd:2753 [F] s_b_10_2=sym_30242_3_parameter_inst.opcode (const) */
    /* execute.simd:2754 [F] s_b_10_3 = constant s32 0 (const) */
    /* execute.simd:2759 [F] s_b_10_4 = constant s32 2 (const) */
    /* execute.simd:2764 [F] s_b_10_5 = constant s32 4 (const) */
    /* execute.simd:2753 [F] s_b_10_6: Switch s_b_10_2: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4,  */
    switch (insn.opcode) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_4;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2743 [D] s_b_11_0 = ReadReg 20 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_11_1: sym_134666_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_134666_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2743 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_8,  */
  fixed_block_b_12: 
  {
    /* execute.a64:3053 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_12_1 = __builtin_get_feature */
    uint32_t s_b_12_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_12_2 = (u8)s_b_12_1 (const) */
    /* execute.a64:2745 [F] s_b_12_3 = (u32)s_b_12_2 (const) */
    /* execute.a64:2745 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_12_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_12_6: If s_b_12_5: Jump b_14 else b_15 (const) */
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
    /* execute.a64:2772 [D] s_b_13_0 = sym_134666_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_134666_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_134649_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_134649_0_return_symbol, s_b_13_0);
    /* ???:4294967295 [F] s_b_13_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2746 [D] s_b_14_0 = ReadReg 20 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_14_1: sym_134666_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_134666_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2746 [F] s_b_14_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_12,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2748 [D] s_b_15_0 = ReadReg 21 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_15_1: sym_134666_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_134666_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2748 [F] s_b_15_2: Jump b_13 (const) */
    goto fixed_block_b_13;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stlr(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_137140_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137157_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137261_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_137547_1_temporary_value;
  auto DV_sym_137547_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30848_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_137333_1_temporary_value;
  auto DV_sym_137333_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_137473_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:882 [F] s_b_0_0=sym_30842_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2771 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_4: If s_b_0_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:885 [D] s_b_1_0 = sym_30848_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_30848_0_address, emitter.context().types().u64());
    /* execute.a64:885 [F] s_b_1_1=sym_30842_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_1_2: sym_137261_1_tmp_s_b_4_0 = s_b_1_0, dominates: s_b_14_2  */
    emitter.store_local(DV_sym_137261_1_tmp_s_b_4_0, s_b_1_0);
    /* execute.a64:2687 [F] s_b_1_3 = (u32)s_b_1_1 (const) */
    /* execute.a64:2687 [F] s_b_1_4 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
    uint8_t s_b_1_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_1_6: If s_b_1_5: Jump b_12 else b_13 (const) */
    if (s_b_1_5) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_14, b_17,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_6,  */
  fixed_block_b_3: 
  {
    /* execute.a64:887 [D] s_b_3_0 = sym_30848_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_30848_0_address, emitter.context().types().u64());
    /* execute.a64:887 [F] s_b_3_1=sym_30842_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_137473_1_tmp_s_b_5_0 = s_b_3_0, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_137473_1_tmp_s_b_5_0, s_b_3_0);
    /* execute.a64:2692 [F] s_b_3_3 = (u32)s_b_3_1 (const) */
    /* execute.a64:2692 [F] s_b_3_4 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
    uint8_t s_b_3_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_3_6: If s_b_3_5: Jump b_15 else b_16 (const) */
    if (s_b_3_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2742 [F] s_b_4_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(s_b_4_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_4_4: If s_b_4_3: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2774 [F] s_b_5_0=sym_30842_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_137140_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_137140_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_137140_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_137140_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:882 [D] s_b_6_1: sym_30848_0_address = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_30848_0_address, s_b_6_0);
    /* execute.a64:884 [F] s_b_6_2=sym_30842_3_parameter_inst.size (const) */
    /* execute.a64:884 [F] s_b_6_3 = (u32)s_b_6_2 (const) */
    /* execute.a64:884 [F] s_b_6_4 = constant u32 2 (const) */
    /* execute.a64:884 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:884 [F] s_b_6_6: If s_b_6_5: Jump b_1 else b_3 (const) */
    if (s_b_6_5) 
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
    /* execute.a64:2743 [D] s_b_7_0 = ReadReg 20 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_7_1: sym_137157_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_137157_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2743 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:3053 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_8_2 = (u8)s_b_8_1 (const) */
    /* execute.a64:2745 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:2745 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_8_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_8_6: If s_b_8_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2772 [D] s_b_9_0 = sym_137157_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_137157_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_137140_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_137140_0_return_symbol, s_b_9_0);
    /* ???:4294967295 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2746 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_10_1: sym_137157_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_137157_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2746 [F] s_b_10_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2748 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_11_1: sym_137157_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_137157_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2748 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2687 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_12_1: sym_137333_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_137333_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_137333_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_1,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2687 [F] s_b_13_0=sym_30842_3_parameter_inst.rt (const) */
    /* execute.a64:2687 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_13_2: sym_137333_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_137333_1_temporary_value, s_b_13_1);
    /* execute.a64:2687 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2687 [D] s_b_14_0 = sym_137333_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_137333_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_2 = sym_137261_1_tmp_s_b_4_0 uint64_t */
    auto s_b_14_2 = emitter.load_local(DV_sym_137261_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:1833 [D] s_b_14_3 = (u32)s_b_14_1 */
    auto s_b_14_3 = emitter.truncate(s_b_14_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_14_4: Store 4 s_b_14_2 <= s_b_14_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_14_2, s_b_14_3, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_14_2, s_b_14_3);
    /* execute.a64:0 [F] s_b_14_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2692 [F] s_b_15_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_15_1: sym_137547_1_temporary_value = s_b_15_0 (const), dominates: s_b_17_0  */
    CV_sym_137547_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_137547_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_3,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2692 [F] s_b_16_0=sym_30842_3_parameter_inst.rt (const) */
    /* execute.a64:2692 [D] s_b_16_1 = ReadRegBank 0:s_b_16_0 (u64) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_16_2: sym_137547_1_temporary_value = s_b_16_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_137547_1_temporary_value, s_b_16_1);
    /* execute.a64:2692 [F] s_b_16_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2692 [D] s_b_17_0 = sym_137547_1_temporary_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_137547_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = sym_137473_1_tmp_s_b_5_0 uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_137473_1_tmp_s_b_5_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_2: Store 8 s_b_17_1 <= s_b_17_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_17_1, s_b_17_0, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_17_1, s_b_17_0);
    /* execute.a64:0 [F] s_b_17_3: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stp(const arm64_decode_a64_LS_REG_PAIR_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_142154_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_142145_1_temporary_value;
  auto DV_sym_142145_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_142159_1_temporary_value;
  auto DV_sym_142159_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_141967_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31259_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31273_0_data1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31282_0_data2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141984_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_142055_1_tmp_s_b_14_5;
  uint32_t CV_sym_142094_1_temporary_value;
  auto DV_sym_142094_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_142089_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_142080_1_temporary_value;
  auto DV_sym_142080_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1538 [F] s_b_0_0=sym_31227_3_parameter_inst.opc (const) */
    /* execute.a64:1538 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1538 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.a64:1538 [F] s_b_0_3 = s_b_0_1>>s_b_0_2 (const) */
    uint32_t s_b_0_3 = ((uint32_t)(((uint32_t)insn.opc) >> (uint32_t)1ULL));
    /* execute.a64:1538 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:1538 [F] s_b_0_5 = s_b_0_3&s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(s_b_0_3 & (uint32_t)1ULL));
    /* execute.a64:1538 [F] s_b_0_6 = constant u32 2 (const) */
    /* execute.a64:1538 [F] s_b_0_7 = s_b_0_6+s_b_0_5 (const) */
    uint32_t s_b_0_7 = ((uint32_t)((uint32_t)2ULL + s_b_0_5));
    /* execute.a64:1538 [F] s_b_0_8 = (u8)s_b_0_7 (const) */
    /* execute.a64:1539 [F] s_b_0_9=sym_31227_3_parameter_inst.imm7 (const) */
    /* execute.a64:1539 [F] s_b_0_10 = (u64)s_b_0_9 (const) */
    /* execute.a64:2826 [F] s_b_0_11 = (s64)s_b_0_10 (const) */
    /* execute.a64:2826 [F] s_b_0_12 = constant s64 39 (const) */
    /* execute.a64:2826 [F] s_b_0_13 = s_b_0_11<<s_b_0_12 (const) */
    int64_t s_b_0_13 = ((int64_t)(((int64_t)((uint64_t)insn.imm7)) << (int64_t)57ULL));
    /* execute.a64:2826 [F] s_b_0_14 = (s64)s_b_0_13 (const) */
    /* execute.a64:2826 [F] s_b_0_15 = constant s64 39 (const) */
    /* execute.a64:2826 [F] s_b_0_16 = s_b_0_14->>s_b_0_15 (const) */
    int64_t s_b_0_16 = ((int64_t)(((int64_t)s_b_0_13) >> (int64_t)57ULL));
    /* execute.a64:1539 [F] s_b_0_17 = (u64)s_b_0_16 (const) */
    /* execute.a64:1539 [F] s_b_0_18 = (u64)s_b_0_8 (const) */
    /* execute.a64:1539 [F] s_b_0_19 = s_b_0_17<<s_b_0_18 (const) */
    uint64_t s_b_0_19 = ((uint64_t)(((uint64_t)s_b_0_16) << ((uint64_t)((uint8_t)s_b_0_7))));
    /* execute.a64:1539 [F] s_b_0_20 = (s64)s_b_0_19 (const) */
    /* execute.a64:1541 [F] s_b_0_21=sym_31227_3_parameter_inst.rn (const) */
    /* ???:4294967295 [F] s_b_0_22: sym_142055_1_tmp_s_b_14_5 = s_b_0_20 (const), dominates: s_b_6_1  */
    CV_sym_142055_1_tmp_s_b_14_5 = ((int64_t)s_b_0_19);
    /* execute.a64:2771 [F] s_b_0_23 = (u32)s_b_0_21 (const) */
    /* execute.a64:2771 [F] s_b_0_24 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_25 = s_b_0_23==s_b_0_24 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_26: If s_b_0_25: Jump b_4 else b_5 (const) */
    if (s_b_0_25) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_28,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1548 [D] s_b_1_0 = sym_31259_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31259_0_address, emitter.context().types().u64());
    /* execute.a64:1548 [D] s_b_1_1 = sym_31273_0_data1 uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_31273_0_data1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_2: Store 8 s_b_1_0 <= s_b_1_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_1_0, s_b_1_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_1_0, s_b_1_1);
    /* execute.a64:1549 [F] s_b_1_3 = constant u64 8 (const) */
    /* execute.a64:1549 [D] s_b_1_4 = s_b_1_0+s_b_1_3 */
    auto s_b_1_4 = emitter.add(s_b_1_0, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:1549 [D] s_b_1_5 = sym_31282_0_data2 uint64_t */
    auto s_b_1_5 = emitter.load_local(DV_sym_31282_0_data2, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_6: Store 8 s_b_1_4 <= s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_1_4, s_b_1_5, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_1_4, s_b_1_5);
    /* execute.a64:1548 [F] s_b_1_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_28,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1551 [D] s_b_3_0 = sym_31259_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31259_0_address, emitter.context().types().u64());
    /* execute.a64:1551 [D] s_b_3_1 = sym_31273_0_data1 uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_31273_0_data1, emitter.context().types().u64());
    /* execute.a64:1551 [D] s_b_3_2 = (u32)s_b_3_1 */
    auto s_b_3_2 = emitter.truncate(s_b_3_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_3_3: Store 4 s_b_3_0 <= s_b_3_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_3_0, s_b_3_2);
    /* execute.a64:1552 [F] s_b_3_4 = constant u64 4 (const) */
    /* execute.a64:1552 [D] s_b_3_5 = s_b_3_0+s_b_3_4 */
    auto s_b_3_5 = emitter.add(s_b_3_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:1552 [D] s_b_3_6 = sym_31282_0_data2 uint64_t */
    auto s_b_3_6 = emitter.load_local(DV_sym_31282_0_data2, emitter.context().types().u64());
    /* execute.a64:1552 [D] s_b_3_7 = (u32)s_b_3_6 */
    auto s_b_3_7 = emitter.truncate(s_b_3_6, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_3_8: Store 4 s_b_3_5 <= s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_5, s_b_3_7, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_3_5, s_b_3_7);
    /* execute.a64:1551 [F] s_b_3_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2742 [F] s_b_4_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(s_b_4_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_4_4: If s_b_4_3: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2774 [F] s_b_5_0=sym_31227_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_141967_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_141967_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_141967_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_141967_0_return_symbol, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_1 = sym_142055_1_tmp_s_b_14_5 (const) int64_t */
    int64_t s_b_6_1 = CV_sym_142055_1_tmp_s_b_14_5;
    /* execute.a64:1541 [D] s_b_6_2: sym_31259_0_address = s_b_6_0, dominates:  */
    emitter.store_local(DV_sym_31259_0_address, s_b_6_0);
    /* ???:4294967295 [F] s_b_6_3 = (u64)s_b_6_1 (const) */
    /* ???:4294967295 [D] s_b_6_4 = s_b_6_0+s_b_6_3 */
    auto s_b_6_4 = emitter.add(s_b_6_0, emitter.const_u64(((uint64_t)s_b_6_1)));
    /* execute.a64:1542 [D] s_b_6_5: sym_31259_0_address = s_b_6_4, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_31259_0_address, s_b_6_4);
    /* execute.a64:1544 [F] s_b_6_6=sym_31227_3_parameter_inst.opc (const) */
    /* execute.a64:1544 [F] s_b_6_7 = (u32)s_b_6_6 (const) */
    /* execute.a64:1544 [F] s_b_6_8 = constant u32 2 (const) */
    /* execute.a64:1544 [F] s_b_6_9 = s_b_6_7==s_b_6_8 (const) */
    uint8_t s_b_6_9 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:2697 [F] s_b_6_10: If s_b_6_9: Jump b_12 else b_15 (const) */
    if (s_b_6_9) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2743 [D] s_b_7_0 = ReadReg 20 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_7_1: sym_141984_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141984_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2743 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:3053 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_8_2 = (u8)s_b_8_1 (const) */
    /* execute.a64:2745 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:2745 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_8_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_8_6: If s_b_8_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2772 [D] s_b_9_0 = sym_141984_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_141984_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_141967_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_141967_0_return_symbol, s_b_9_0);
    /* ???:4294967295 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2746 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_10_1: sym_141984_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141984_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2746 [F] s_b_10_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2748 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_11_1: sym_141984_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141984_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2748 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2698 [F] s_b_12_0=sym_31227_3_parameter_inst.rt (const) */
    /* execute.a64:2692 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.a64:2692 [F] s_b_12_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_12_4: If s_b_12_3: Jump b_13 else b_14 (const) */
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
    /* execute.a64:2692 [F] s_b_13_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_13_1: sym_142080_1_temporary_value = s_b_13_0 (const), dominates: s_b_18_0  */
    CV_sym_142080_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_142080_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_13_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2692 [F] s_b_14_0=sym_31227_3_parameter_inst.rt (const) */
    /* execute.a64:2692 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_14_2: sym_142080_1_temporary_value = s_b_14_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_142080_1_temporary_value, s_b_14_1);
    /* execute.a64:2692 [F] s_b_14_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2700 [F] s_b_15_0=sym_31227_3_parameter_inst.rt (const) */
    /* execute.a64:2687 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.a64:2687 [F] s_b_15_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_15_4: If s_b_15_3: Jump b_16 else b_17 (const) */
    if (s_b_15_3) 
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
    /* execute.a64:2687 [F] s_b_16_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_16_1: sym_142094_1_temporary_value = s_b_16_0 (const), dominates: s_b_20_0  */
    CV_sym_142094_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_142094_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_16_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_15,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2687 [F] s_b_17_0=sym_31227_3_parameter_inst.rt (const) */
    /* execute.a64:2687 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_17_2: sym_142094_1_temporary_value = s_b_17_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_142094_1_temporary_value, s_b_17_1);
    /* execute.a64:2687 [F] s_b_17_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_13, b_14,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2692 [D] s_b_18_0 = sym_142080_1_temporary_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_142080_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1: sym_142089_0_return_symbol = s_b_18_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_142089_0_return_symbol, s_b_18_0);
    /* ???:4294967295 [F] s_b_18_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_18, b_20,  */
  fixed_block_b_19: 
  {
    /* ???:4294967295 [D] s_b_19_0 = sym_142089_0_return_symbol uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_142089_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1544 [D] s_b_19_1: sym_31273_0_data1 = s_b_19_0, dominates: s_b_1_1 s_b_3_1  */
    emitter.store_local(DV_sym_31273_0_data1, s_b_19_0);
    /* execute.a64:1545 [F] s_b_19_2=sym_31227_3_parameter_inst.opc (const) */
    /* execute.a64:1545 [F] s_b_19_3 = (u32)s_b_19_2 (const) */
    /* execute.a64:1545 [F] s_b_19_4 = constant u32 2 (const) */
    /* execute.a64:1545 [F] s_b_19_5 = s_b_19_3==s_b_19_4 (const) */
    uint8_t s_b_19_5 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:2697 [F] s_b_19_6: If s_b_19_5: Jump b_21 else b_24 (const) */
    if (s_b_19_5) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_16, b_17,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2687 [D] s_b_20_0 = sym_142094_1_temporary_value uint32_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_142094_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_20_1 = (u64)s_b_20_0 */
    auto s_b_20_1 = emitter.zx(s_b_20_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_2: sym_142089_0_return_symbol = s_b_20_1, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_142089_0_return_symbol, s_b_20_1);
    /* ???:4294967295 [F] s_b_20_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_19,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2698 [F] s_b_21_0=sym_31227_3_parameter_inst.rt2 (const) */
    /* execute.a64:2692 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:2692 [F] s_b_21_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_21_4: If s_b_21_3: Jump b_22 else b_23 (const) */
    if (s_b_21_3) 
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
    /* execute.a64:2692 [F] s_b_22_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_22_1: sym_142145_1_temporary_value = s_b_22_0 (const), dominates: s_b_27_0  */
    CV_sym_142145_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_142145_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_22_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_21,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2692 [F] s_b_23_0=sym_31227_3_parameter_inst.rt2 (const) */
    /* execute.a64:2692 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_23_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_23_2: sym_142145_1_temporary_value = s_b_23_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_142145_1_temporary_value, s_b_23_1);
    /* execute.a64:2692 [F] s_b_23_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_19,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2700 [F] s_b_24_0=sym_31227_3_parameter_inst.rt2 (const) */
    /* execute.a64:2687 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:2687 [F] s_b_24_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_24_4: If s_b_24_3: Jump b_25 else b_26 (const) */
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
    /* execute.a64:2687 [F] s_b_25_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_25_1: sym_142159_1_temporary_value = s_b_25_0 (const), dominates: s_b_29_0  */
    CV_sym_142159_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_142159_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_25_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_24,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2687 [F] s_b_26_0=sym_31227_3_parameter_inst.rt2 (const) */
    /* execute.a64:2687 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_26_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_26_2: sym_142159_1_temporary_value = s_b_26_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_142159_1_temporary_value, s_b_26_1);
    /* execute.a64:2687 [F] s_b_26_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_22, b_23,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2692 [D] s_b_27_0 = sym_142145_1_temporary_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_142145_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_27_1: sym_142154_0_return_symbol = s_b_27_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_142154_0_return_symbol, s_b_27_0);
    /* ???:4294967295 [F] s_b_27_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_29,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_142154_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_142154_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1545 [D] s_b_28_1: sym_31282_0_data2 = s_b_28_0, dominates: s_b_1_5 s_b_3_6  */
    emitter.store_local(DV_sym_31282_0_data2, s_b_28_0);
    /* execute.a64:1547 [F] s_b_28_2=sym_31227_3_parameter_inst.opc (const) */
    /* execute.a64:1547 [F] s_b_28_3 = (u32)s_b_28_2 (const) */
    /* execute.a64:1547 [F] s_b_28_4 = constant u32 2 (const) */
    /* execute.a64:1547 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
    uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1547 [F] s_b_28_6: If s_b_28_5: Jump b_1 else b_3 (const) */
    if (s_b_28_5) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_25, b_26,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2687 [D] s_b_29_0 = sym_142159_1_temporary_value uint32_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_142159_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_29_1 = (u64)s_b_29_0 */
    auto s_b_29_1 = emitter.zx(s_b_29_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_29_2: sym_142154_0_return_symbol = s_b_29_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_142154_0_return_symbol, s_b_29_1);
    /* ???:4294967295 [F] s_b_29_3: Jump b_28 (const) */
    goto fixed_block_b_28;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_strb_reg(const arm64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_146568_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_32115_0_rm;
  auto DV_sym_32115_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_146495_1_temporary_value;
  auto DV_sym_146495_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_146768_1_temporary_value;
  auto DV_sym_146768_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_146922_1_temporary_value;
  auto DV_sym_146922_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_147088_1_temporary_value;
  auto DV_sym_147088_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_147173_1_temporary_value;
  auto DV_sym_147173_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_147202_1_tmp_s_b_52_2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_146551_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1150 [F] s_b_0_0=sym_32088_3_parameter_inst.option0 (const) */
    /* execute.a64:1150 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1150 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1150 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1150 [F] s_b_0_4=sym_32088_3_parameter_inst.option21 (const) */
    /* execute.a64:1150 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:1150 [F] s_b_0_6 = constant u32 1 (const) */
    /* execute.a64:1150 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:1150 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1151 [F] s_b_1_0=sym_32088_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2687 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_1_4: If s_b_1_3: Jump b_10 else b_11 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_9, b_12, b_23, b_26, b_29,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1163 [F] s_b_2_0=sym_32088_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2771 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_2_4: If s_b_2_3: Jump b_13 else b_14 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1152 [F] s_b_3_0=sym_32088_3_parameter_inst.option0 (const) */
    /* execute.a64:1152 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1152 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1152 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1152 [F] s_b_3_4=sym_32088_3_parameter_inst.option21 (const) */
    /* execute.a64:1152 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:1152 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.a64:1152 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:1152 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1153 [F] s_b_4_0=sym_32088_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2687 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_4_4: If s_b_4_3: Jump b_21 else b_22 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1154 [F] s_b_5_0=sym_32088_3_parameter_inst.option0 (const) */
    /* execute.a64:1154 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1154 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1154 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1154 [F] s_b_5_4=sym_32088_3_parameter_inst.option21 (const) */
    /* execute.a64:1154 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1154 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:1154 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1154 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1155 [F] s_b_6_0=sym_32088_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2692 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_6_4: If s_b_6_3: Jump b_24 else b_25 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1156 [F] s_b_7_0=sym_32088_3_parameter_inst.option0 (const) */
    /* execute.a64:1156 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1156 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1156 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1156 [F] s_b_7_4=sym_32088_3_parameter_inst.option21 (const) */
    /* execute.a64:1156 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:1156 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.a64:1156 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:1156 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1157 [F] s_b_8_0=sym_32088_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2692 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_8_4: If s_b_8_3: Jump b_27 else b_28 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_28;
    }
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1159 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:1159 [F] s_b_9_1: sym_32115_0_rm = s_b_9_0 (const), dominates: s_b_15_1  */
    CV_sym_32115_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_32115_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1160 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1159 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2687 [F] s_b_10_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_10_1: sym_146495_1_temporary_value = s_b_10_0 (const), dominates: s_b_12_0  */
    CV_sym_146495_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_146495_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_1,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2687 [F] s_b_11_0=sym_32088_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [D] s_b_11_1 = ReadRegBank 1:s_b_11_0 (u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_11_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_11_2: sym_146495_1_temporary_value = s_b_11_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_146495_1_temporary_value, s_b_11_1);
    /* execute.a64:2687 [F] s_b_11_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2687 [D] s_b_12_0 = sym_146495_1_temporary_value uint32_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_146495_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_12_1 = (u64)s_b_12_0 */
    auto s_b_12_1 = emitter.zx(s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2657 [D] s_b_12_2 = (u32)s_b_12_1 */
    auto s_b_12_2 = emitter.truncate(s_b_12_1, emitter.context().types().u32());
    /* execute.a64:2657 [D] s_b_12_3 = (u64)s_b_12_2 */
    auto s_b_12_3 = emitter.zx(s_b_12_2, emitter.context().types().u64());
    /* execute.a64:2657 [F] s_b_12_4=sym_32088_3_parameter_inst.S (const) */
    /* execute.a64:2657 [F] s_b_12_5 = (u64)s_b_12_4 (const) */
    /* execute.a64:2657 [D] s_b_12_6 = s_b_12_3<<s_b_12_5 */
    auto s_b_12_6 = emitter.shl(s_b_12_3, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1151 [D] s_b_12_7: sym_32115_0_rm = s_b_12_6, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32115_0_rm, s_b_12_6);
    /* execute.a64:1151 [F] s_b_12_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2742 [F] s_b_13_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_13_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(s_b_13_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_13_4: If s_b_13_3: Jump b_16 else b_17 (const) */
    if (s_b_13_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_2,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2774 [F] s_b_14_0=sym_32088_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_14_2: sym_146551_0_return_symbol = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_146551_0_return_symbol, s_b_14_1);
    /* ???:4294967295 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14, b_18,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_146551_0_return_symbol uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_146551_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1163 [D] s_b_15_1 = sym_32115_0_rm uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_32115_0_rm, emitter.context().types().u64());
    /* execute.a64:1163 [D] s_b_15_2 = s_b_15_0+s_b_15_1 */
    auto s_b_15_2 = emitter.add(s_b_15_0, s_b_15_1);
    /* execute.a64:1165 [F] s_b_15_3=sym_32088_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_15_4: sym_147202_1_tmp_s_b_52_2 = s_b_15_2, dominates: s_b_32_2  */
    emitter.store_local(DV_sym_147202_1_tmp_s_b_52_2, s_b_15_2);
    /* execute.a64:2687 [F] s_b_15_5 = (u32)s_b_15_3 (const) */
    /* execute.a64:2687 [F] s_b_15_6 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_15_7 = s_b_15_5==s_b_15_6 (const) */
    uint8_t s_b_15_7 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_15_8: If s_b_15_7: Jump b_30 else b_31 (const) */
    if (s_b_15_7) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_13,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2743 [D] s_b_16_0 = ReadReg 20 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_16_1: sym_146568_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_146568_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2743 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_17: 
  {
    /* execute.a64:3053 [F] s_b_17_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_17_1 = __builtin_get_feature */
    uint32_t s_b_17_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_17_2 = (u8)s_b_17_1 (const) */
    /* execute.a64:2745 [F] s_b_17_3 = (u32)s_b_17_2 (const) */
    /* execute.a64:2745 [F] s_b_17_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_17_5 = s_b_17_3==s_b_17_4 (const) */
    uint8_t s_b_17_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_17_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_17_6: If s_b_17_5: Jump b_19 else b_20 (const) */
    if (s_b_17_5) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_16, b_19, b_20,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2772 [D] s_b_18_0 = sym_146568_1__R_s_b_3_0 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_146568_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1: sym_146551_0_return_symbol = s_b_18_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_146551_0_return_symbol, s_b_18_0);
    /* ???:4294967295 [F] s_b_18_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_17,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2746 [D] s_b_19_0 = ReadReg 20 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_19_1: sym_146568_1__R_s_b_3_0 = s_b_19_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_146568_1__R_s_b_3_0, s_b_19_0);
    /* execute.a64:2746 [F] s_b_19_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_17,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2748 [D] s_b_20_0 = ReadReg 21 (u64) */
    auto s_b_20_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_20_1: sym_146568_1__R_s_b_3_0 = s_b_20_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_146568_1__R_s_b_3_0, s_b_20_0);
    /* execute.a64:2748 [F] s_b_20_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2687 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_21_1: sym_146768_1_temporary_value = s_b_21_0 (const), dominates: s_b_23_0  */
    CV_sym_146768_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_146768_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_21_2: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_4,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2687 [F] s_b_22_0=sym_32088_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [D] s_b_22_1 = ReadRegBank 1:s_b_22_0 (u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_22_2: sym_146768_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_146768_1_temporary_value, s_b_22_1);
    /* execute.a64:2687 [F] s_b_22_3: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2687 [D] s_b_23_0 = sym_146768_1_temporary_value uint32_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_146768_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_23_1 = (u64)s_b_23_0 */
    auto s_b_23_1 = emitter.zx(s_b_23_0, emitter.context().types().u64());
    /* execute.a64:2673 [D] s_b_23_2 = (s32)s_b_23_1 */
    auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().s32());
    /* execute.a64:2673 [D] s_b_23_3 = (s64)s_b_23_2 */
    auto s_b_23_3 = emitter.sx(s_b_23_2, emitter.context().types().s64());
    /* execute.a64:2673 [D] s_b_23_4 = (u64)s_b_23_3 */
    auto s_b_23_4 = emitter.reinterpret(s_b_23_3, emitter.context().types().u64());
    /* execute.a64:2673 [F] s_b_23_5=sym_32088_3_parameter_inst.S (const) */
    /* execute.a64:2673 [F] s_b_23_6 = (u64)s_b_23_5 (const) */
    /* execute.a64:2673 [D] s_b_23_7 = s_b_23_4<<s_b_23_6 */
    auto s_b_23_7 = emitter.shl(s_b_23_4, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1153 [D] s_b_23_8: sym_32115_0_rm = s_b_23_7, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32115_0_rm, s_b_23_7);
    /* execute.a64:1153 [F] s_b_23_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2692 [F] s_b_24_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_24_1: sym_146922_1_temporary_value = s_b_24_0 (const), dominates: s_b_26_0  */
    CV_sym_146922_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_146922_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_24_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_6,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2692 [F] s_b_25_0=sym_32088_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [D] s_b_25_1 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_25_2: sym_146922_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_146922_1_temporary_value, s_b_25_1);
    /* execute.a64:2692 [F] s_b_25_3: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_24, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2692 [D] s_b_26_0 = sym_146922_1_temporary_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_146922_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2661 [F] s_b_26_1=sym_32088_3_parameter_inst.S (const) */
    /* execute.a64:2661 [F] s_b_26_2 = (u64)s_b_26_1 (const) */
    /* execute.a64:2661 [D] s_b_26_3 = s_b_26_0<<s_b_26_2 */
    auto s_b_26_3 = emitter.shl(s_b_26_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1155 [D] s_b_26_4: sym_32115_0_rm = s_b_26_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32115_0_rm, s_b_26_3);
    /* execute.a64:1155 [F] s_b_26_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2692 [F] s_b_27_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_27_1: sym_147088_1_temporary_value = s_b_27_0 (const), dominates: s_b_29_0  */
    CV_sym_147088_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_147088_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_27_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_8,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2692 [F] s_b_28_0=sym_32088_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [D] s_b_28_1 = ReadRegBank 0:s_b_28_0 (u64) */
    auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_28_2: sym_147088_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_147088_1_temporary_value, s_b_28_1);
    /* execute.a64:2692 [F] s_b_28_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2692 [D] s_b_29_0 = sym_147088_1_temporary_value uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_147088_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2677 [F] s_b_29_1=sym_32088_3_parameter_inst.S (const) */
    /* execute.a64:2677 [F] s_b_29_2 = (u64)s_b_29_1 (const) */
    /* execute.a64:2677 [D] s_b_29_3 = s_b_29_0<<s_b_29_2 */
    auto s_b_29_3 = emitter.shl(s_b_29_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1157 [D] s_b_29_4: sym_32115_0_rm = s_b_29_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32115_0_rm, s_b_29_3);
    /* execute.a64:1157 [F] s_b_29_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2687 [F] s_b_30_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_30_1: sym_147173_1_temporary_value = s_b_30_0 (const), dominates: s_b_32_0  */
    CV_sym_147173_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_147173_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_30_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_15,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2687 [F] s_b_31_0=sym_32088_3_parameter_inst.rt (const) */
    /* execute.a64:2687 [D] s_b_31_1 = ReadRegBank 1:s_b_31_0 (u32) */
    auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_31_2: sym_147173_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_147173_1_temporary_value, s_b_31_1);
    /* execute.a64:2687 [F] s_b_31_3: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2687 [D] s_b_32_0 = sym_147173_1_temporary_value uint32_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_147173_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_32_1 = (u64)s_b_32_0 */
    auto s_b_32_1 = emitter.zx(s_b_32_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_2 = sym_147202_1_tmp_s_b_52_2 uint64_t */
    auto s_b_32_2 = emitter.load_local(DV_sym_147202_1_tmp_s_b_52_2, emitter.context().types().u64());
    /* execute.a64:1165 [D] s_b_32_3 = (u8)s_b_32_1 */
    auto s_b_32_3 = emitter.truncate(s_b_32_1, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_32_4: Store 1 s_b_32_2 <= s_b_32_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_32_2, s_b_32_3, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_32_2, s_b_32_3);
    /* ???:4294967295 [F] s_b_32_5: Return */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sttrh(const arm64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sub_ereg(const arm64_decode_a64_ADD_SUB_EREG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_152077_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32846_0_rn = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32860_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_151999_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152372_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_152276_1_temporary_value;
  auto DV_sym_152276_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_152288_1_temporary_value;
  auto DV_sym_152288_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_152438_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152334_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152261_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152167_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_152162_0_return_symbol;
  auto DV_sym_152162_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_151982_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152022_1__R_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1925 [F] s_b_0_0=sym_32841_3_parameter_inst.sf (const) */
    /* execute.a64:2770 [F] s_b_0_1: If s_b_0_0: Jump b_6 else b_9 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_28,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1929 [F] s_b_1_0=sym_32841_3_parameter_inst.sf (const) */
    /* execute.a64:1929 [F] s_b_1_1: If s_b_1_0: Jump b_4 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_5, b_26, b_46, b_47, b_48, b_49, b_50,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_28,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1935 [F] s_b_3_0=sym_32841_3_parameter_inst.sf (const) */
    /* execute.a64:1935 [D] s_b_3_1 = sym_32846_0_rn uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_32846_0_rn, emitter.context().types().u64());
    /* execute.a64:1935 [D] s_b_3_2 = sym_32860_0_rm uint64_t */
    auto s_b_3_2 = emitter.load_local(DV_sym_32860_0_rm, emitter.context().types().u64());
    /* execute.a64:1935 [D] s_b_3_3 = s_b_3_1-s_b_3_2 */
    auto s_b_3_3 = emitter.sub(s_b_3_1, s_b_3_2);
    /* execute.a64:1935 [D] s_b_3_4: sym_152077_3_parameter_value = s_b_3_3, dominates: s_b_23_0 s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_152077_3_parameter_value, s_b_3_3);
    /* execute.a64:2787 [F] s_b_3_5 = !s_b_3_0 (const) */
    uint8_t s_b_3_5 = !insn.sf;
    /* execute.a64:2787 [F] s_b_3_6: If s_b_3_5: Jump b_23 else b_24 (const) */
    if (s_b_3_5) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1930 [D] s_b_4_0 = sym_32846_0_rn uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_32846_0_rn, emitter.context().types().u64());
    /* execute.a64:1930 [D] s_b_4_1 = sym_32860_0_rm uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_32860_0_rm, emitter.context().types().u64());
    /* execute.a64:1930 [F] s_b_4_2 = constant u8 0 (const) */
    /* execute.a64:1930 [D] s_b_4_3 = __builtin_sbc64_flags */
    auto s_b_4_3 = emitter.sbcf(s_b_4_0, s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2732 [F] s_b_4_4=sym_32841_3_parameter_inst.rd (const) */
    /* execute.a64:2732 [D] s_b_4_5: sym_152372_3_parameter_value = s_b_4_3, dominates: s_b_49_1  */
    emitter.store_local(DV_sym_152372_3_parameter_value, s_b_4_3);
    /* execute.a64:2723 [F] s_b_4_6 = (u32)s_b_4_4 (const) */
    /* execute.a64:2723 [F] s_b_4_7 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_4_8 = s_b_4_6==s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_4_9: If s_b_4_8: Jump b_2 else b_49 (const) */
    if (s_b_4_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_49;
    }
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1932 [D] s_b_5_0 = sym_32846_0_rn uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_32846_0_rn, emitter.context().types().u64());
    /* execute.a64:1932 [D] s_b_5_1 = (u32)s_b_5_0 */
    auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().u32());
    /* execute.a64:1932 [D] s_b_5_2 = sym_32860_0_rm uint64_t */
    auto s_b_5_2 = emitter.load_local(DV_sym_32860_0_rm, emitter.context().types().u64());
    /* execute.a64:1932 [D] s_b_5_3 = (u32)s_b_5_2 */
    auto s_b_5_3 = emitter.truncate(s_b_5_2, emitter.context().types().u32());
    /* execute.a64:1932 [F] s_b_5_4 = constant u8 0 (const) */
    /* execute.a64:1932 [D] s_b_5_5 = __builtin_sbc32_flags */
    auto s_b_5_5 = emitter.sbcf(s_b_5_1, s_b_5_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:1932 [D] s_b_5_6 = (u64)s_b_5_5 */
    auto s_b_5_6 = emitter.zx(s_b_5_5, emitter.context().types().u64());
    /* execute.a64:2734 [F] s_b_5_7=sym_32841_3_parameter_inst.rd (const) */
    /* execute.a64:2734 [D] s_b_5_8 = (u32)s_b_5_6 */
    auto s_b_5_8 = emitter.truncate(s_b_5_6, emitter.context().types().u32());
    /* execute.a64:2734 [D] s_b_5_9 = (u64)s_b_5_8 */
    auto s_b_5_9 = emitter.zx(s_b_5_8, emitter.context().types().u64());
    /* execute.a64:2734 [D] s_b_5_10: sym_152438_3_parameter_value = s_b_5_9, dominates: s_b_50_1  */
    emitter.store_local(DV_sym_152438_3_parameter_value, s_b_5_9);
    /* execute.a64:2723 [F] s_b_5_11 = (u32)s_b_5_7 (const) */
    /* execute.a64:2723 [F] s_b_5_12 = constant u32 1f (const) */
    /* execute.a64:2723 [F] s_b_5_13 = s_b_5_11==s_b_5_12 (const) */
    uint8_t s_b_5_13 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2723 [F] s_b_5_14: If s_b_5_13: Jump b_2 else b_50 (const) */
    if (s_b_5_13) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_50;
    }
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2771 [F] s_b_6_0=sym_32841_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2771 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_6_4: If s_b_6_3: Jump b_7 else b_8 (const) */
    if (s_b_6_3) 
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
    /* execute.a64:2742 [F] s_b_7_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_7_1 = __builtin_get_feature */
    uint32_t s_b_7_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(s_b_7_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_7_4: If s_b_7_3: Jump b_13 else b_14 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2774 [F] s_b_8_0=sym_32841_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_151982_0_return_symbol = s_b_8_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_151982_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2777 [F] s_b_9_0=sym_32841_3_parameter_inst.rn (const) */
    /* execute.a64:2777 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:2777 [F] s_b_9_2 = constant u32 1f (const) */
    /* execute.a64:2777 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2777 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_11 (const) */
    if (s_b_9_3) 
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
    /* execute.a64:2742 [F] s_b_10_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_10_1 = __builtin_get_feature */
    uint32_t s_b_10_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(s_b_10_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_10_4: If s_b_10_3: Jump b_18 else b_19 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2780 [F] s_b_11_0=sym_32841_3_parameter_inst.rn (const) */
    /* execute.a64:2780 [D] s_b_11_1 = ReadRegBank 1:s_b_11_0 (u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1,emitter.const_u8(4));
    }
    /* execute.a64:2780 [D] s_b_11_2 = (u64)s_b_11_1 */
    auto s_b_11_2 = emitter.zx(s_b_11_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_3: sym_151982_0_return_symbol = s_b_11_2, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_151982_0_return_symbol, s_b_11_2);
    /* ???:4294967295 [F] s_b_11_4: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_8, b_11, b_15, b_20,  */
  fixed_block_b_12: 
  {
    /* ???:4294967295 [D] s_b_12_0 = sym_151982_0_return_symbol uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_151982_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1925 [D] s_b_12_1: sym_32846_0_rn = s_b_12_0, dominates: s_b_4_0 s_b_5_0 s_b_3_1  */
    emitter.store_local(DV_sym_32846_0_rn, s_b_12_0);
    /* execute.a64:1926 [F] s_b_12_2=sym_32841_3_parameter_inst.option (const) */
    /* execute.a64:1926 [F] s_b_12_3 = (u32)s_b_12_2 (const) */
    /* execute.a64:1926 [F] s_b_12_4 = constant u32 3 (const) */
    /* execute.a64:1926 [F] s_b_12_5 = s_b_12_3&s_b_12_4 (const) */
    uint32_t s_b_12_5 = ((uint32_t)(((uint32_t)insn.option) & (uint32_t)3ULL));
    /* execute.a64:1926 [F] s_b_12_6 = constant u32 3 (const) */
    /* execute.a64:1926 [F] s_b_12_7 = s_b_12_5==s_b_12_6 (const) */
    uint8_t s_b_12_7 = ((uint8_t)(s_b_12_5 == (uint32_t)3ULL));
    /* execute.a64:2697 [F] s_b_12_8: If s_b_12_7: Jump b_37 else b_40 (const) */
    if (s_b_12_7) 
    {
      goto fixed_block_b_37;
    }
    else 
    {
      goto fixed_block_b_40;
    }
  }
  /* b_7,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2743 [D] s_b_13_0 = ReadReg 20 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_13_1: sym_151999_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_151999_1__R_s_b_3_0, s_b_13_0);
    /* execute.a64:2743 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_7,  */
  fixed_block_b_14: 
  {
    /* execute.a64:3053 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_14_1 = __builtin_get_feature */
    uint32_t s_b_14_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_14_2 = (u8)s_b_14_1 (const) */
    /* execute.a64:2745 [F] s_b_14_3 = (u32)s_b_14_2 (const) */
    /* execute.a64:2745 [F] s_b_14_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_14_5 = s_b_14_3==s_b_14_4 (const) */
    uint8_t s_b_14_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_14_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_14_6: If s_b_14_5: Jump b_16 else b_17 (const) */
    if (s_b_14_5) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_13, b_16, b_17,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2772 [D] s_b_15_0 = sym_151999_1__R_s_b_3_0 uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_151999_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1: sym_151982_0_return_symbol = s_b_15_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_151982_0_return_symbol, s_b_15_0);
    /* ???:4294967295 [F] s_b_15_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2746 [D] s_b_16_0 = ReadReg 20 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_16_1: sym_151999_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_151999_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2746 [F] s_b_16_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2748 [D] s_b_17_0 = ReadReg 21 (u64) */
    auto s_b_17_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_17_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_17_1: sym_151999_1__R_s_b_3_0 = s_b_17_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_151999_1__R_s_b_3_0, s_b_17_0);
    /* execute.a64:2748 [F] s_b_17_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_10,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2743 [D] s_b_18_0 = ReadReg 20 (u64) */
    auto s_b_18_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_18_1: sym_152022_1__R_s_b_5_0 = s_b_18_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_152022_1__R_s_b_5_0, s_b_18_0);
    /* execute.a64:2743 [F] s_b_18_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_10,  */
  fixed_block_b_19: 
  {
    /* execute.a64:3053 [F] s_b_19_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_19_1 = __builtin_get_feature */
    uint32_t s_b_19_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_19_2 = (u8)s_b_19_1 (const) */
    /* execute.a64:2745 [F] s_b_19_3 = (u32)s_b_19_2 (const) */
    /* execute.a64:2745 [F] s_b_19_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_19_5 = s_b_19_3==s_b_19_4 (const) */
    uint8_t s_b_19_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_19_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_19_6: If s_b_19_5: Jump b_21 else b_22 (const) */
    if (s_b_19_5) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_18, b_21, b_22,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2778 [D] s_b_20_0 = sym_152022_1__R_s_b_5_0 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_152022_1__R_s_b_5_0, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_20_1 = (u32)s_b_20_0 */
    auto s_b_20_1 = emitter.truncate(s_b_20_0, emitter.context().types().u32());
    /* execute.a64:2778 [D] s_b_20_2 = (u64)s_b_20_1 */
    auto s_b_20_2 = emitter.zx(s_b_20_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_3: sym_151982_0_return_symbol = s_b_20_2, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_151982_0_return_symbol, s_b_20_2);
    /* ???:4294967295 [F] s_b_20_4: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_19,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2746 [D] s_b_21_0 = ReadReg 20 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_21_1: sym_152022_1__R_s_b_5_0 = s_b_21_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_152022_1__R_s_b_5_0, s_b_21_0);
    /* execute.a64:2746 [F] s_b_21_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_19,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2748 [D] s_b_22_0 = ReadReg 21 (u64) */
    auto s_b_22_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_22_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_22_1: sym_152022_1__R_s_b_5_0 = s_b_22_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_152022_1__R_s_b_5_0, s_b_22_0);
    /* execute.a64:2748 [F] s_b_22_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_3,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2788 [D] s_b_23_0 = sym_152077_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_152077_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2788 [F] s_b_23_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_23_2 = s_b_23_0&s_b_23_1 */
    auto s_b_23_2 = emitter.bitwise_and(s_b_23_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2788 [D] s_b_23_3: sym_152077_3_parameter_value = s_b_23_2, dominates: s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_152077_3_parameter_value, s_b_23_2);
    /* execute.a64:2788 [F] s_b_23_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_3, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2791 [F] s_b_24_0=sym_32841_3_parameter_inst.rd (const) */
    /* execute.a64:2791 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:2791 [F] s_b_24_2 = constant u32 1f (const) */
    /* execute.a64:2791 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2791 [F] s_b_24_4: If s_b_24_3: Jump b_25 else b_26 (const) */
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
    /* execute.a64:2792 [D] s_b_25_0 = sym_152077_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_152077_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2792 [D] s_b_25_1: sym_152334_3_parameter_value = s_b_25_0, dominates: s_b_46_0 s_b_47_0 s_b_48_0  */
    emitter.store_local(DV_sym_152334_3_parameter_value, s_b_25_0);
    /* execute.a64:2755 [F] s_b_25_2 = constant u32 1 (const) */
    /* execute.a64:2755 [F] s_b_25_3 = __builtin_get_feature */
    uint32_t s_b_25_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2755 [F] s_b_25_4 = constant u32 0 (const) */
    /* execute.a64:2755 [F] s_b_25_5 = s_b_25_3==s_b_25_4 (const) */
    uint8_t s_b_25_5 = ((uint8_t)(s_b_25_3 == (uint32_t)0ULL));
    /* execute.a64:2755 [F] s_b_25_6: If s_b_25_5: Jump b_46 else b_51 (const) */
    if (s_b_25_5) 
    {
      goto fixed_block_b_46;
    }
    else 
    {
      goto fixed_block_b_51;
    }
  }
  /* b_24,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2794 [F] s_b_26_0=sym_32841_3_parameter_inst.rd (const) */
    /* execute.a64:2794 [D] s_b_26_1 = sym_152077_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_152077_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1);
    /* execute.a64:2794 [F] s_b_26_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_43,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2681 [D] s_b_27_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2682 [F] s_b_27_1 = constant u64 0 (const) */
    /* ???:4294967295 [F] s_b_27_2: sym_152162_0_return_symbol = s_b_27_1 (const), dominates: s_b_28_0  */
    CV_sym_152162_0_return_symbol = (uint64_t)0ULL;
    emitter.store_local(DV_sym_152162_0_return_symbol, emitter.const_u64((uint64_t)0ULL));
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_29, b_30, b_31, b_32, b_33, b_34, b_35, b_36,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_152162_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_152162_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1926 [D] s_b_28_1: sym_32860_0_rm = s_b_28_0, dominates: s_b_4_1 s_b_5_2 s_b_3_2  */
    emitter.store_local(DV_sym_32860_0_rm, s_b_28_0);
    /* execute.a64:1928 [F] s_b_28_2=sym_32841_3_parameter_inst.S (const) */
    /* execute.a64:1928 [F] s_b_28_3: If s_b_28_2: Jump b_1 else b_3 (const) */
    if (insn.S) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_43,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2649 [D] s_b_29_0 = sym_152167_0_value uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_152167_0_value, emitter.context().types().u64());
    /* execute.a64:2649 [D] s_b_29_1 = (u8)s_b_29_0 */
    auto s_b_29_1 = emitter.truncate(s_b_29_0, emitter.context().types().u8());
    /* execute.a64:2649 [D] s_b_29_2 = (u64)s_b_29_1 */
    auto s_b_29_2 = emitter.zx(s_b_29_1, emitter.context().types().u64());
    /* execute.a64:2649 [F] s_b_29_3=sym_32841_3_parameter_inst.imm3 (const) */
    /* execute.a64:2649 [F] s_b_29_4 = (u64)s_b_29_3 (const) */
    /* execute.a64:2649 [D] s_b_29_5 = s_b_29_2<<s_b_29_4 */
    auto s_b_29_5 = emitter.shl(s_b_29_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_29_6: sym_152162_0_return_symbol = s_b_29_5, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152162_0_return_symbol, s_b_29_5);
    /* ???:4294967295 [F] s_b_29_7: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2653 [D] s_b_30_0 = sym_152167_0_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_152167_0_value, emitter.context().types().u64());
    /* execute.a64:2653 [D] s_b_30_1 = (u16)s_b_30_0 */
    auto s_b_30_1 = emitter.truncate(s_b_30_0, emitter.context().types().u16());
    /* execute.a64:2653 [D] s_b_30_2 = (u64)s_b_30_1 */
    auto s_b_30_2 = emitter.zx(s_b_30_1, emitter.context().types().u64());
    /* execute.a64:2653 [F] s_b_30_3=sym_32841_3_parameter_inst.imm3 (const) */
    /* execute.a64:2653 [F] s_b_30_4 = (u64)s_b_30_3 (const) */
    /* execute.a64:2653 [D] s_b_30_5 = s_b_30_2<<s_b_30_4 */
    auto s_b_30_5 = emitter.shl(s_b_30_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_30_6: sym_152162_0_return_symbol = s_b_30_5, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152162_0_return_symbol, s_b_30_5);
    /* ???:4294967295 [F] s_b_30_7: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2657 [D] s_b_31_0 = sym_152167_0_value uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_152167_0_value, emitter.context().types().u64());
    /* execute.a64:2657 [D] s_b_31_1 = (u32)s_b_31_0 */
    auto s_b_31_1 = emitter.truncate(s_b_31_0, emitter.context().types().u32());
    /* execute.a64:2657 [D] s_b_31_2 = (u64)s_b_31_1 */
    auto s_b_31_2 = emitter.zx(s_b_31_1, emitter.context().types().u64());
    /* execute.a64:2657 [F] s_b_31_3=sym_32841_3_parameter_inst.imm3 (const) */
    /* execute.a64:2657 [F] s_b_31_4 = (u64)s_b_31_3 (const) */
    /* execute.a64:2657 [D] s_b_31_5 = s_b_31_2<<s_b_31_4 */
    auto s_b_31_5 = emitter.shl(s_b_31_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_31_6: sym_152162_0_return_symbol = s_b_31_5, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152162_0_return_symbol, s_b_31_5);
    /* ???:4294967295 [F] s_b_31_7: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2661 [D] s_b_32_0 = sym_152167_0_value uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_152167_0_value, emitter.context().types().u64());
    /* execute.a64:2661 [F] s_b_32_1=sym_32841_3_parameter_inst.imm3 (const) */
    /* execute.a64:2661 [F] s_b_32_2 = (u64)s_b_32_1 (const) */
    /* execute.a64:2661 [D] s_b_32_3 = s_b_32_0<<s_b_32_2 */
    auto s_b_32_3 = emitter.shl(s_b_32_0, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_32_4: sym_152162_0_return_symbol = s_b_32_3, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152162_0_return_symbol, s_b_32_3);
    /* ???:4294967295 [F] s_b_32_5: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2665 [D] s_b_33_0 = sym_152167_0_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_152167_0_value, emitter.context().types().u64());
    /* execute.a64:2665 [D] s_b_33_1 = (s8)s_b_33_0 */
    auto s_b_33_1 = emitter.truncate(s_b_33_0, emitter.context().types().s8());
    /* execute.a64:2665 [D] s_b_33_2 = (s64)s_b_33_1 */
    auto s_b_33_2 = emitter.sx(s_b_33_1, emitter.context().types().s64());
    /* execute.a64:2665 [D] s_b_33_3 = (u64)s_b_33_2 */
    auto s_b_33_3 = emitter.reinterpret(s_b_33_2, emitter.context().types().u64());
    /* execute.a64:2665 [F] s_b_33_4=sym_32841_3_parameter_inst.imm3 (const) */
    /* execute.a64:2665 [F] s_b_33_5 = (u64)s_b_33_4 (const) */
    /* execute.a64:2665 [D] s_b_33_6 = s_b_33_3<<s_b_33_5 */
    auto s_b_33_6 = emitter.shl(s_b_33_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_33_7: sym_152162_0_return_symbol = s_b_33_6, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152162_0_return_symbol, s_b_33_6);
    /* ???:4294967295 [F] s_b_33_8: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2669 [D] s_b_34_0 = sym_152167_0_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_152167_0_value, emitter.context().types().u64());
    /* execute.a64:2669 [D] s_b_34_1 = (s16)s_b_34_0 */
    auto s_b_34_1 = emitter.truncate(s_b_34_0, emitter.context().types().s16());
    /* execute.a64:2669 [D] s_b_34_2 = (s64)s_b_34_1 */
    auto s_b_34_2 = emitter.sx(s_b_34_1, emitter.context().types().s64());
    /* execute.a64:2669 [D] s_b_34_3 = (u64)s_b_34_2 */
    auto s_b_34_3 = emitter.reinterpret(s_b_34_2, emitter.context().types().u64());
    /* execute.a64:2669 [F] s_b_34_4=sym_32841_3_parameter_inst.imm3 (const) */
    /* execute.a64:2669 [F] s_b_34_5 = (u64)s_b_34_4 (const) */
    /* execute.a64:2669 [D] s_b_34_6 = s_b_34_3<<s_b_34_5 */
    auto s_b_34_6 = emitter.shl(s_b_34_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_34_7: sym_152162_0_return_symbol = s_b_34_6, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152162_0_return_symbol, s_b_34_6);
    /* ???:4294967295 [F] s_b_34_8: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2673 [D] s_b_35_0 = sym_152167_0_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_152167_0_value, emitter.context().types().u64());
    /* execute.a64:2673 [D] s_b_35_1 = (s32)s_b_35_0 */
    auto s_b_35_1 = emitter.truncate(s_b_35_0, emitter.context().types().s32());
    /* execute.a64:2673 [D] s_b_35_2 = (s64)s_b_35_1 */
    auto s_b_35_2 = emitter.sx(s_b_35_1, emitter.context().types().s64());
    /* execute.a64:2673 [D] s_b_35_3 = (u64)s_b_35_2 */
    auto s_b_35_3 = emitter.reinterpret(s_b_35_2, emitter.context().types().u64());
    /* execute.a64:2673 [F] s_b_35_4=sym_32841_3_parameter_inst.imm3 (const) */
    /* execute.a64:2673 [F] s_b_35_5 = (u64)s_b_35_4 (const) */
    /* execute.a64:2673 [D] s_b_35_6 = s_b_35_3<<s_b_35_5 */
    auto s_b_35_6 = emitter.shl(s_b_35_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_35_7: sym_152162_0_return_symbol = s_b_35_6, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152162_0_return_symbol, s_b_35_6);
    /* ???:4294967295 [F] s_b_35_8: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2677 [D] s_b_36_0 = sym_152167_0_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_152167_0_value, emitter.context().types().u64());
    /* execute.a64:2677 [F] s_b_36_1=sym_32841_3_parameter_inst.imm3 (const) */
    /* execute.a64:2677 [F] s_b_36_2 = (u64)s_b_36_1 (const) */
    /* execute.a64:2677 [D] s_b_36_3 = s_b_36_0<<s_b_36_2 */
    auto s_b_36_3 = emitter.shl(s_b_36_0, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_36_4: sym_152162_0_return_symbol = s_b_36_3, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152162_0_return_symbol, s_b_36_3);
    /* ???:4294967295 [F] s_b_36_5: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_12,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2698 [F] s_b_37_0=sym_32841_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [F] s_b_37_1 = (u32)s_b_37_0 (const) */
    /* execute.a64:2692 [F] s_b_37_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_37_3 = s_b_37_1==s_b_37_2 (const) */
    uint8_t s_b_37_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_37_4: If s_b_37_3: Jump b_38 else b_39 (const) */
    if (s_b_37_3) 
    {
      goto fixed_block_b_38;
    }
    else 
    {
      goto fixed_block_b_39;
    }
  }
  /* b_37,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2692 [F] s_b_38_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_38_1: sym_152276_1_temporary_value = s_b_38_0 (const), dominates: s_b_44_0  */
    CV_sym_152276_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_152276_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_38_2: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_37,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2692 [F] s_b_39_0=sym_32841_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [D] s_b_39_1 = ReadRegBank 0:s_b_39_0 (u64) */
    auto s_b_39_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_39_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_39_2: sym_152276_1_temporary_value = s_b_39_1, dominates: s_b_44_0  */
    emitter.store_local(DV_sym_152276_1_temporary_value, s_b_39_1);
    /* execute.a64:2692 [F] s_b_39_3: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_12,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2700 [F] s_b_40_0=sym_32841_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [F] s_b_40_1 = (u32)s_b_40_0 (const) */
    /* execute.a64:2687 [F] s_b_40_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_40_3 = s_b_40_1==s_b_40_2 (const) */
    uint8_t s_b_40_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_40_4: If s_b_40_3: Jump b_41 else b_42 (const) */
    if (s_b_40_3) 
    {
      goto fixed_block_b_41;
    }
    else 
    {
      goto fixed_block_b_42;
    }
  }
  /* b_40,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2687 [F] s_b_41_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_41_1: sym_152288_1_temporary_value = s_b_41_0 (const), dominates: s_b_45_0  */
    CV_sym_152288_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_152288_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_41_2: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_40,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2687 [F] s_b_42_0=sym_32841_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [D] s_b_42_1 = ReadRegBank 1:s_b_42_0 (u32) */
    auto s_b_42_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_42_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_42_2: sym_152288_1_temporary_value = s_b_42_1, dominates: s_b_45_0  */
    emitter.store_local(DV_sym_152288_1_temporary_value, s_b_42_1);
    /* execute.a64:2687 [F] s_b_42_3: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_44, b_45,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2644 [D] s_b_43_0 = sym_152261_1__R_s_b_0_4 uint64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_152261_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2644 [D] s_b_43_1: sym_152167_0_value = s_b_43_0, dominates: s_b_36_0 s_b_35_0 s_b_34_0 s_b_33_0 s_b_32_0 s_b_31_0 s_b_30_0 s_b_29_0  */
    emitter.store_local(DV_sym_152167_0_value, s_b_43_0);
    /* execute.a64:2646 [F] s_b_43_2=sym_32841_3_parameter_inst.option (const) */
    /* execute.a64:2647 [F] s_b_43_3 = constant s32 0 (const) */
    /* execute.a64:2651 [F] s_b_43_4 = constant s32 1 (const) */
    /* execute.a64:2655 [F] s_b_43_5 = constant s32 2 (const) */
    /* execute.a64:2659 [F] s_b_43_6 = constant s32 3 (const) */
    /* execute.a64:2663 [F] s_b_43_7 = constant s32 4 (const) */
    /* execute.a64:2667 [F] s_b_43_8 = constant s32 5 (const) */
    /* execute.a64:2671 [F] s_b_43_9 = constant s32 6 (const) */
    /* execute.a64:2675 [F] s_b_43_10 = constant s32 7 (const) */
    /* execute.a64:2646 [F] s_b_43_11: Switch s_b_43_2: < <todo> > def b_27 (const) -> b_36, b_35, b_34, b_33, b_32, b_31, b_30, b_29, b_27,  */
    switch (insn.option) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_30;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_29;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_31;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_36;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_34;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_32;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_35;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_33;
      break;
    default:
      goto fixed_block_b_27;
    }
  }
  /* b_38, b_39,  */
  fixed_block_b_44: 
  {
    /* execute.a64:2692 [D] s_b_44_0 = sym_152276_1_temporary_value uint64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_152276_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2698 [D] s_b_44_1: sym_152261_1__R_s_b_0_4 = s_b_44_0, dominates: s_b_43_0  */
    emitter.store_local(DV_sym_152261_1__R_s_b_0_4, s_b_44_0);
    /* execute.a64:2698 [F] s_b_44_2: Jump b_43 (const) */
    goto fixed_block_b_43;
  }
  /* b_41, b_42,  */
  fixed_block_b_45: 
  {
    /* execute.a64:2687 [D] s_b_45_0 = sym_152288_1_temporary_value uint32_t */
    auto s_b_45_0 = emitter.load_local(DV_sym_152288_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_45_1 = (u64)s_b_45_0 */
    auto s_b_45_1 = emitter.zx(s_b_45_0, emitter.context().types().u64());
    /* execute.a64:2700 [D] s_b_45_2: sym_152261_1__R_s_b_0_4 = s_b_45_1, dominates: s_b_43_0  */
    emitter.store_local(DV_sym_152261_1__R_s_b_0_4, s_b_45_1);
    /* execute.a64:2700 [F] s_b_45_3: Jump b_43 (const) */
    goto fixed_block_b_43;
  }
  /* b_25,  */
  fixed_block_b_46: 
  {
    /* execute.a64:2756 [D] s_b_46_0 = sym_152334_3_parameter_value uint64_t */
    auto s_b_46_0 = emitter.load_local(DV_sym_152334_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_46_1: WriteReg 20 = s_b_46_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_46_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_46_0);
    /* execute.a64:2756 [F] s_b_46_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_51,  */
  fixed_block_b_47: 
  {
    /* execute.a64:2759 [D] s_b_47_0 = sym_152334_3_parameter_value uint64_t */
    auto s_b_47_0 = emitter.load_local(DV_sym_152334_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2759 [D] s_b_47_1: WriteReg 20 = s_b_47_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_47_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_47_0);
    /* execute.a64:2759 [F] s_b_47_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_51,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2761 [D] s_b_48_0 = sym_152334_3_parameter_value uint64_t */
    auto s_b_48_0 = emitter.load_local(DV_sym_152334_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2761 [D] s_b_48_1: WriteReg 21 = s_b_48_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_48_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_48_0);
    /* execute.a64:2761 [F] s_b_48_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2725 [F] s_b_49_0=sym_32841_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [D] s_b_49_1 = sym_152372_3_parameter_value uint64_t */
    auto s_b_49_1 = emitter.load_local(DV_sym_152372_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_49_2: WriteRegBank 0:s_b_49_0 = s_b_49_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_49_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_49_1);
    /* execute.a64:0 [F] s_b_49_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_50: 
  {
    /* execute.a64:2725 [F] s_b_50_0=sym_32841_3_parameter_inst.rd (const) */
    /* execute.a64:2725 [D] s_b_50_1 = sym_152438_3_parameter_value uint64_t */
    auto s_b_50_1 = emitter.load_local(DV_sym_152438_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2725 [D] s_b_50_2: WriteRegBank 0:s_b_50_0 = s_b_50_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_50_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_50_1);
    /* execute.a64:0 [F] s_b_50_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_25,  */
  fixed_block_b_51: 
  {
    /* execute.a64:3053 [F] s_b_51_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_51_1 = __builtin_get_feature */
    uint32_t s_b_51_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_51_2 = (u8)s_b_51_1 (const) */
    /* execute.a64:2758 [F] s_b_51_3 = (u32)s_b_51_2 (const) */
    /* execute.a64:2758 [F] s_b_51_4 = constant u32 0 (const) */
    /* execute.a64:2758 [F] s_b_51_5 = s_b_51_3==s_b_51_4 (const) */
    uint8_t s_b_51_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_51_1)) == (uint32_t)0ULL));
    /* execute.a64:2758 [F] s_b_51_6: If s_b_51_5: Jump b_47 else b_48 (const) */
    if (s_b_51_5) 
    {
      goto fixed_block_b_47;
    }
    else 
    {
      goto fixed_block_b_48;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_uadalp(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3467 [F] s_b_0_0=sym_36037_3_parameter_inst.arrangement (const) */
    /* execute.simd:3468 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:3480 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:3491 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:3503 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:3514 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:3524 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:3467 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:3469 [F] s_b_2_0=sym_36037_3_parameter_inst.rn (const) */
    /* execute.simd:3469 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:3470 [F] s_b_2_2=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3470 [D] s_b_2_3 = ReadRegBank 17:s_b_2_2 (v4u16) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant u8 0 (const) */
    /* execute.simd:3473 [D] s_b_2_3[s_b_2_4] */
    auto s_b_2_5 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3473 [F] s_b_2_6 = constant u32 0 (const) */
    /* execute.simd:3473 [D] s_b_2_1[s_b_2_6] */
    auto s_b_2_7 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3473 [D] s_b_2_8 = (u16)s_b_2_7 */
    auto s_b_2_8 = emitter.zx(s_b_2_7, emitter.context().types().u16());
    /* execute.simd:3473 [F] s_b_2_9 = constant u32 1 (const) */
    /* execute.simd:3473 [D] s_b_2_1[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3473 [D] s_b_2_11 = (u16)s_b_2_10 */
    auto s_b_2_11 = emitter.zx(s_b_2_10, emitter.context().types().u16());
    /* execute.simd:3473 [D] s_b_2_12 = s_b_2_8+s_b_2_11 */
    auto s_b_2_12 = emitter.add(s_b_2_8, s_b_2_11);
    /* ???:4294967295 [D] s_b_2_13 = s_b_2_5+s_b_2_12 */
    auto s_b_2_13 = emitter.add(s_b_2_5, s_b_2_12);
    /* execute.simd:3473 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:3473 [D] s_b_2_15 = s_b_2_3[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(s_b_2_3, emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:3473 [D] s_b_2_15[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_15, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3473 [F] s_b_2_18 = constant u32 2 (const) */
    /* execute.simd:3473 [D] s_b_2_1[s_b_2_18] */
    auto s_b_2_19 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3473 [D] s_b_2_20 = (u16)s_b_2_19 */
    auto s_b_2_20 = emitter.zx(s_b_2_19, emitter.context().types().u16());
    /* execute.simd:3473 [F] s_b_2_21 = constant u32 3 (const) */
    /* execute.simd:3473 [D] s_b_2_1[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3473 [D] s_b_2_23 = (u16)s_b_2_22 */
    auto s_b_2_23 = emitter.zx(s_b_2_22, emitter.context().types().u16());
    /* execute.simd:3473 [D] s_b_2_24 = s_b_2_20+s_b_2_23 */
    auto s_b_2_24 = emitter.add(s_b_2_20, s_b_2_23);
    /* ???:4294967295 [D] s_b_2_25 = s_b_2_17+s_b_2_24 */
    auto s_b_2_25 = emitter.add(s_b_2_17, s_b_2_24);
    /* execute.simd:3473 [F] s_b_2_26 = constant s32 1 (const) */
    /* execute.simd:3473 [D] s_b_2_27 = s_b_2_15[s_b_2_26] <= s_b_2_25 */
    auto s_b_2_27 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_25);
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:3473 [D] s_b_2_27[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_27, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3473 [F] s_b_2_30 = constant u32 4 (const) */
    /* execute.simd:3473 [D] s_b_2_1[s_b_2_30] */
    auto s_b_2_31 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3473 [D] s_b_2_32 = (u16)s_b_2_31 */
    auto s_b_2_32 = emitter.zx(s_b_2_31, emitter.context().types().u16());
    /* execute.simd:3473 [F] s_b_2_33 = constant u32 5 (const) */
    /* execute.simd:3473 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3473 [D] s_b_2_35 = (u16)s_b_2_34 */
    auto s_b_2_35 = emitter.zx(s_b_2_34, emitter.context().types().u16());
    /* execute.simd:3473 [D] s_b_2_36 = s_b_2_32+s_b_2_35 */
    auto s_b_2_36 = emitter.add(s_b_2_32, s_b_2_35);
    /* ???:4294967295 [D] s_b_2_37 = s_b_2_29+s_b_2_36 */
    auto s_b_2_37 = emitter.add(s_b_2_29, s_b_2_36);
    /* execute.simd:3473 [F] s_b_2_38 = constant s32 2 (const) */
    /* execute.simd:3473 [D] s_b_2_39 = s_b_2_27[s_b_2_38] <= s_b_2_37 */
    auto s_b_2_39 = emitter.vector_insert(s_b_2_27, emitter.const_s32((int32_t)2ULL), s_b_2_37);
    /* ???:4294967295 [F] s_b_2_40 = constant u8 3 (const) */
    /* execute.simd:3473 [D] s_b_2_39[s_b_2_40] */
    auto s_b_2_41 = emitter.vector_extract(s_b_2_39, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3473 [F] s_b_2_42 = constant u32 6 (const) */
    /* execute.simd:3473 [D] s_b_2_1[s_b_2_42] */
    auto s_b_2_43 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3473 [D] s_b_2_44 = (u16)s_b_2_43 */
    auto s_b_2_44 = emitter.zx(s_b_2_43, emitter.context().types().u16());
    /* execute.simd:3473 [F] s_b_2_45 = constant u32 7 (const) */
    /* execute.simd:3473 [D] s_b_2_1[s_b_2_45] */
    auto s_b_2_46 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3473 [D] s_b_2_47 = (u16)s_b_2_46 */
    auto s_b_2_47 = emitter.zx(s_b_2_46, emitter.context().types().u16());
    /* execute.simd:3473 [D] s_b_2_48 = s_b_2_44+s_b_2_47 */
    auto s_b_2_48 = emitter.add(s_b_2_44, s_b_2_47);
    /* ???:4294967295 [D] s_b_2_49 = s_b_2_41+s_b_2_48 */
    auto s_b_2_49 = emitter.add(s_b_2_41, s_b_2_48);
    /* execute.simd:3473 [F] s_b_2_50 = constant s32 3 (const) */
    /* execute.simd:3473 [D] s_b_2_51 = s_b_2_39[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_39, emitter.const_s32((int32_t)3ULL), s_b_2_49);
    /* execute.simd:3476 [F] s_b_2_52=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3476 [D] s_b_2_53: WriteRegBank 17:s_b_2_52 = s_b_2_51 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_51,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_51);
    /* execute.simd:3477 [F] s_b_2_54=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3477 [F] s_b_2_55 = constant u64 0 (const) */
    /* execute.simd:3477 [F] s_b_2_56: WriteRegBank 3:s_b_2_54 = s_b_2_55 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_57: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:3481 [F] s_b_3_0=sym_36037_3_parameter_inst.rn (const) */
    /* execute.simd:3481 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:3482 [F] s_b_3_2=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3482 [D] s_b_3_3 = ReadRegBank 18:s_b_3_2 (v8u16) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant u8 0 (const) */
    /* execute.simd:3485 [D] s_b_3_3[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3485 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_6] */
    auto s_b_3_7 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3485 [D] s_b_3_8 = (u16)s_b_3_7 */
    auto s_b_3_8 = emitter.zx(s_b_3_7, emitter.context().types().u16());
    /* execute.simd:3485 [F] s_b_3_9 = constant u32 1 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3485 [D] s_b_3_11 = (u16)s_b_3_10 */
    auto s_b_3_11 = emitter.zx(s_b_3_10, emitter.context().types().u16());
    /* execute.simd:3485 [D] s_b_3_12 = s_b_3_8+s_b_3_11 */
    auto s_b_3_12 = emitter.add(s_b_3_8, s_b_3_11);
    /* ???:4294967295 [D] s_b_3_13 = s_b_3_5+s_b_3_12 */
    auto s_b_3_13 = emitter.add(s_b_3_5, s_b_3_12);
    /* execute.simd:3485 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:3485 [D] s_b_3_15 = s_b_3_3[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(s_b_3_3, emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* ???:4294967295 [F] s_b_3_16 = constant u8 1 (const) */
    /* execute.simd:3485 [D] s_b_3_15[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_15, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3485 [F] s_b_3_18 = constant u32 2 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_18] */
    auto s_b_3_19 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3485 [D] s_b_3_20 = (u16)s_b_3_19 */
    auto s_b_3_20 = emitter.zx(s_b_3_19, emitter.context().types().u16());
    /* execute.simd:3485 [F] s_b_3_21 = constant u32 3 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3485 [D] s_b_3_23 = (u16)s_b_3_22 */
    auto s_b_3_23 = emitter.zx(s_b_3_22, emitter.context().types().u16());
    /* execute.simd:3485 [D] s_b_3_24 = s_b_3_20+s_b_3_23 */
    auto s_b_3_24 = emitter.add(s_b_3_20, s_b_3_23);
    /* ???:4294967295 [D] s_b_3_25 = s_b_3_17+s_b_3_24 */
    auto s_b_3_25 = emitter.add(s_b_3_17, s_b_3_24);
    /* execute.simd:3485 [F] s_b_3_26 = constant s32 1 (const) */
    /* execute.simd:3485 [D] s_b_3_27 = s_b_3_15[s_b_3_26] <= s_b_3_25 */
    auto s_b_3_27 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_25);
    /* ???:4294967295 [F] s_b_3_28 = constant u8 2 (const) */
    /* execute.simd:3485 [D] s_b_3_27[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_27, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3485 [F] s_b_3_30 = constant u32 4 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_30] */
    auto s_b_3_31 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3485 [D] s_b_3_32 = (u16)s_b_3_31 */
    auto s_b_3_32 = emitter.zx(s_b_3_31, emitter.context().types().u16());
    /* execute.simd:3485 [F] s_b_3_33 = constant u32 5 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3485 [D] s_b_3_35 = (u16)s_b_3_34 */
    auto s_b_3_35 = emitter.zx(s_b_3_34, emitter.context().types().u16());
    /* execute.simd:3485 [D] s_b_3_36 = s_b_3_32+s_b_3_35 */
    auto s_b_3_36 = emitter.add(s_b_3_32, s_b_3_35);
    /* ???:4294967295 [D] s_b_3_37 = s_b_3_29+s_b_3_36 */
    auto s_b_3_37 = emitter.add(s_b_3_29, s_b_3_36);
    /* execute.simd:3485 [F] s_b_3_38 = constant s32 2 (const) */
    /* execute.simd:3485 [D] s_b_3_39 = s_b_3_27[s_b_3_38] <= s_b_3_37 */
    auto s_b_3_39 = emitter.vector_insert(s_b_3_27, emitter.const_s32((int32_t)2ULL), s_b_3_37);
    /* ???:4294967295 [F] s_b_3_40 = constant u8 3 (const) */
    /* execute.simd:3485 [D] s_b_3_39[s_b_3_40] */
    auto s_b_3_41 = emitter.vector_extract(s_b_3_39, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3485 [F] s_b_3_42 = constant u32 6 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_42] */
    auto s_b_3_43 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3485 [D] s_b_3_44 = (u16)s_b_3_43 */
    auto s_b_3_44 = emitter.zx(s_b_3_43, emitter.context().types().u16());
    /* execute.simd:3485 [F] s_b_3_45 = constant u32 7 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_45] */
    auto s_b_3_46 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3485 [D] s_b_3_47 = (u16)s_b_3_46 */
    auto s_b_3_47 = emitter.zx(s_b_3_46, emitter.context().types().u16());
    /* execute.simd:3485 [D] s_b_3_48 = s_b_3_44+s_b_3_47 */
    auto s_b_3_48 = emitter.add(s_b_3_44, s_b_3_47);
    /* ???:4294967295 [D] s_b_3_49 = s_b_3_41+s_b_3_48 */
    auto s_b_3_49 = emitter.add(s_b_3_41, s_b_3_48);
    /* execute.simd:3485 [F] s_b_3_50 = constant s32 3 (const) */
    /* execute.simd:3485 [D] s_b_3_51 = s_b_3_39[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_39, emitter.const_s32((int32_t)3ULL), s_b_3_49);
    /* ???:4294967295 [F] s_b_3_52 = constant u8 4 (const) */
    /* execute.simd:3485 [D] s_b_3_51[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_51, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3485 [F] s_b_3_54 = constant u32 8 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_54] */
    auto s_b_3_55 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:3485 [D] s_b_3_56 = (u16)s_b_3_55 */
    auto s_b_3_56 = emitter.zx(s_b_3_55, emitter.context().types().u16());
    /* execute.simd:3485 [F] s_b_3_57 = constant u32 9 (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:3485 [D] s_b_3_59 = (u16)s_b_3_58 */
    auto s_b_3_59 = emitter.zx(s_b_3_58, emitter.context().types().u16());
    /* execute.simd:3485 [D] s_b_3_60 = s_b_3_56+s_b_3_59 */
    auto s_b_3_60 = emitter.add(s_b_3_56, s_b_3_59);
    /* ???:4294967295 [D] s_b_3_61 = s_b_3_53+s_b_3_60 */
    auto s_b_3_61 = emitter.add(s_b_3_53, s_b_3_60);
    /* execute.simd:3485 [F] s_b_3_62 = constant s32 4 (const) */
    /* execute.simd:3485 [D] s_b_3_63 = s_b_3_51[s_b_3_62] <= s_b_3_61 */
    auto s_b_3_63 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)4ULL), s_b_3_61);
    /* ???:4294967295 [F] s_b_3_64 = constant u8 5 (const) */
    /* execute.simd:3485 [D] s_b_3_63[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_63, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3485 [F] s_b_3_66 = constant u32 a (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_66] */
    auto s_b_3_67 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:3485 [D] s_b_3_68 = (u16)s_b_3_67 */
    auto s_b_3_68 = emitter.zx(s_b_3_67, emitter.context().types().u16());
    /* execute.simd:3485 [F] s_b_3_69 = constant u32 b (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_69] */
    auto s_b_3_70 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:3485 [D] s_b_3_71 = (u16)s_b_3_70 */
    auto s_b_3_71 = emitter.zx(s_b_3_70, emitter.context().types().u16());
    /* execute.simd:3485 [D] s_b_3_72 = s_b_3_68+s_b_3_71 */
    auto s_b_3_72 = emitter.add(s_b_3_68, s_b_3_71);
    /* ???:4294967295 [D] s_b_3_73 = s_b_3_65+s_b_3_72 */
    auto s_b_3_73 = emitter.add(s_b_3_65, s_b_3_72);
    /* execute.simd:3485 [F] s_b_3_74 = constant s32 5 (const) */
    /* execute.simd:3485 [D] s_b_3_75 = s_b_3_63[s_b_3_74] <= s_b_3_73 */
    auto s_b_3_75 = emitter.vector_insert(s_b_3_63, emitter.const_s32((int32_t)5ULL), s_b_3_73);
    /* ???:4294967295 [F] s_b_3_76 = constant u8 6 (const) */
    /* execute.simd:3485 [D] s_b_3_75[s_b_3_76] */
    auto s_b_3_77 = emitter.vector_extract(s_b_3_75, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3485 [F] s_b_3_78 = constant u32 c (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_78] */
    auto s_b_3_79 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:3485 [D] s_b_3_80 = (u16)s_b_3_79 */
    auto s_b_3_80 = emitter.zx(s_b_3_79, emitter.context().types().u16());
    /* execute.simd:3485 [F] s_b_3_81 = constant u32 d (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_81] */
    auto s_b_3_82 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:3485 [D] s_b_3_83 = (u16)s_b_3_82 */
    auto s_b_3_83 = emitter.zx(s_b_3_82, emitter.context().types().u16());
    /* execute.simd:3485 [D] s_b_3_84 = s_b_3_80+s_b_3_83 */
    auto s_b_3_84 = emitter.add(s_b_3_80, s_b_3_83);
    /* ???:4294967295 [D] s_b_3_85 = s_b_3_77+s_b_3_84 */
    auto s_b_3_85 = emitter.add(s_b_3_77, s_b_3_84);
    /* execute.simd:3485 [F] s_b_3_86 = constant s32 6 (const) */
    /* execute.simd:3485 [D] s_b_3_87 = s_b_3_75[s_b_3_86] <= s_b_3_85 */
    auto s_b_3_87 = emitter.vector_insert(s_b_3_75, emitter.const_s32((int32_t)6ULL), s_b_3_85);
    /* ???:4294967295 [F] s_b_3_88 = constant u8 7 (const) */
    /* execute.simd:3485 [D] s_b_3_87[s_b_3_88] */
    auto s_b_3_89 = emitter.vector_extract(s_b_3_87, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3485 [F] s_b_3_90 = constant u32 e (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_90] */
    auto s_b_3_91 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:3485 [D] s_b_3_92 = (u16)s_b_3_91 */
    auto s_b_3_92 = emitter.zx(s_b_3_91, emitter.context().types().u16());
    /* execute.simd:3485 [F] s_b_3_93 = constant u32 f (const) */
    /* execute.simd:3485 [D] s_b_3_1[s_b_3_93] */
    auto s_b_3_94 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:3485 [D] s_b_3_95 = (u16)s_b_3_94 */
    auto s_b_3_95 = emitter.zx(s_b_3_94, emitter.context().types().u16());
    /* execute.simd:3485 [D] s_b_3_96 = s_b_3_92+s_b_3_95 */
    auto s_b_3_96 = emitter.add(s_b_3_92, s_b_3_95);
    /* ???:4294967295 [D] s_b_3_97 = s_b_3_89+s_b_3_96 */
    auto s_b_3_97 = emitter.add(s_b_3_89, s_b_3_96);
    /* execute.simd:3485 [F] s_b_3_98 = constant s32 7 (const) */
    /* execute.simd:3485 [D] s_b_3_99 = s_b_3_87[s_b_3_98] <= s_b_3_97 */
    auto s_b_3_99 = emitter.vector_insert(s_b_3_87, emitter.const_s32((int32_t)7ULL), s_b_3_97);
    /* execute.simd:3488 [F] s_b_3_100=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3488 [D] s_b_3_101: WriteRegBank 18:s_b_3_100 = s_b_3_99 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_99,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_99);
    /* execute.simd:0 [F] s_b_3_102: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:3492 [F] s_b_4_0=sym_36037_3_parameter_inst.rn (const) */
    /* execute.simd:3492 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:3493 [F] s_b_4_2=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3493 [D] s_b_4_3 = ReadRegBank 19:s_b_4_2 (v2u32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant u8 0 (const) */
    /* execute.simd:3496 [D] s_b_4_3[s_b_4_4] */
    auto s_b_4_5 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3496 [F] s_b_4_6 = constant u32 0 (const) */
    /* execute.simd:3496 [D] s_b_4_1[s_b_4_6] */
    auto s_b_4_7 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3496 [D] s_b_4_8 = (u32)s_b_4_7 */
    auto s_b_4_8 = emitter.zx(s_b_4_7, emitter.context().types().u32());
    /* execute.simd:3496 [F] s_b_4_9 = constant u32 1 (const) */
    /* execute.simd:3496 [D] s_b_4_1[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3496 [D] s_b_4_11 = (u32)s_b_4_10 */
    auto s_b_4_11 = emitter.zx(s_b_4_10, emitter.context().types().u32());
    /* execute.simd:3496 [D] s_b_4_12 = s_b_4_8+s_b_4_11 */
    auto s_b_4_12 = emitter.add(s_b_4_8, s_b_4_11);
    /* ???:4294967295 [D] s_b_4_13 = s_b_4_5+s_b_4_12 */
    auto s_b_4_13 = emitter.add(s_b_4_5, s_b_4_12);
    /* execute.simd:3496 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:3496 [D] s_b_4_15 = s_b_4_3[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(s_b_4_3, emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:3496 [D] s_b_4_15[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_15, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3496 [F] s_b_4_18 = constant u32 2 (const) */
    /* execute.simd:3496 [D] s_b_4_1[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3496 [D] s_b_4_20 = (u32)s_b_4_19 */
    auto s_b_4_20 = emitter.zx(s_b_4_19, emitter.context().types().u32());
    /* execute.simd:3496 [F] s_b_4_21 = constant u32 3 (const) */
    /* execute.simd:3496 [D] s_b_4_1[s_b_4_21] */
    auto s_b_4_22 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3496 [D] s_b_4_23 = (u32)s_b_4_22 */
    auto s_b_4_23 = emitter.zx(s_b_4_22, emitter.context().types().u32());
    /* execute.simd:3496 [D] s_b_4_24 = s_b_4_20+s_b_4_23 */
    auto s_b_4_24 = emitter.add(s_b_4_20, s_b_4_23);
    /* ???:4294967295 [D] s_b_4_25 = s_b_4_17+s_b_4_24 */
    auto s_b_4_25 = emitter.add(s_b_4_17, s_b_4_24);
    /* execute.simd:3496 [F] s_b_4_26 = constant s32 1 (const) */
    /* execute.simd:3496 [D] s_b_4_27 = s_b_4_15[s_b_4_26] <= s_b_4_25 */
    auto s_b_4_27 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_25);
    /* execute.simd:3499 [F] s_b_4_28=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3499 [D] s_b_4_29: WriteRegBank 19:s_b_4_28 = s_b_4_27 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_27,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_27);
    /* execute.simd:3500 [F] s_b_4_30=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3500 [F] s_b_4_31 = constant u64 0 (const) */
    /* execute.simd:3500 [F] s_b_4_32: WriteRegBank 3:s_b_4_30 = s_b_4_31 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_33: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:3504 [F] s_b_5_0=sym_36037_3_parameter_inst.rn (const) */
    /* execute.simd:3504 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:3505 [F] s_b_5_2=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3505 [D] s_b_5_3 = ReadRegBank 20:s_b_5_2 (v4u32) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant u8 0 (const) */
    /* execute.simd:3508 [D] s_b_5_3[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3508 [F] s_b_5_6 = constant u32 0 (const) */
    /* execute.simd:3508 [D] s_b_5_1[s_b_5_6] */
    auto s_b_5_7 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3508 [D] s_b_5_8 = (u32)s_b_5_7 */
    auto s_b_5_8 = emitter.zx(s_b_5_7, emitter.context().types().u32());
    /* execute.simd:3508 [F] s_b_5_9 = constant u32 1 (const) */
    /* execute.simd:3508 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3508 [D] s_b_5_11 = (u32)s_b_5_10 */
    auto s_b_5_11 = emitter.zx(s_b_5_10, emitter.context().types().u32());
    /* execute.simd:3508 [D] s_b_5_12 = s_b_5_8+s_b_5_11 */
    auto s_b_5_12 = emitter.add(s_b_5_8, s_b_5_11);
    /* ???:4294967295 [D] s_b_5_13 = s_b_5_5+s_b_5_12 */
    auto s_b_5_13 = emitter.add(s_b_5_5, s_b_5_12);
    /* execute.simd:3508 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:3508 [D] s_b_5_15 = s_b_5_3[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(s_b_5_3, emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* ???:4294967295 [F] s_b_5_16 = constant u8 1 (const) */
    /* execute.simd:3508 [D] s_b_5_15[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_15, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3508 [F] s_b_5_18 = constant u32 2 (const) */
    /* execute.simd:3508 [D] s_b_5_1[s_b_5_18] */
    auto s_b_5_19 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3508 [D] s_b_5_20 = (u32)s_b_5_19 */
    auto s_b_5_20 = emitter.zx(s_b_5_19, emitter.context().types().u32());
    /* execute.simd:3508 [F] s_b_5_21 = constant u32 3 (const) */
    /* execute.simd:3508 [D] s_b_5_1[s_b_5_21] */
    auto s_b_5_22 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3508 [D] s_b_5_23 = (u32)s_b_5_22 */
    auto s_b_5_23 = emitter.zx(s_b_5_22, emitter.context().types().u32());
    /* execute.simd:3508 [D] s_b_5_24 = s_b_5_20+s_b_5_23 */
    auto s_b_5_24 = emitter.add(s_b_5_20, s_b_5_23);
    /* ???:4294967295 [D] s_b_5_25 = s_b_5_17+s_b_5_24 */
    auto s_b_5_25 = emitter.add(s_b_5_17, s_b_5_24);
    /* execute.simd:3508 [F] s_b_5_26 = constant s32 1 (const) */
    /* execute.simd:3508 [D] s_b_5_27 = s_b_5_15[s_b_5_26] <= s_b_5_25 */
    auto s_b_5_27 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_25);
    /* ???:4294967295 [F] s_b_5_28 = constant u8 2 (const) */
    /* execute.simd:3508 [D] s_b_5_27[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_27, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3508 [F] s_b_5_30 = constant u32 4 (const) */
    /* execute.simd:3508 [D] s_b_5_1[s_b_5_30] */
    auto s_b_5_31 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3508 [D] s_b_5_32 = (u32)s_b_5_31 */
    auto s_b_5_32 = emitter.zx(s_b_5_31, emitter.context().types().u32());
    /* execute.simd:3508 [F] s_b_5_33 = constant u32 5 (const) */
    /* execute.simd:3508 [D] s_b_5_1[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3508 [D] s_b_5_35 = (u32)s_b_5_34 */
    auto s_b_5_35 = emitter.zx(s_b_5_34, emitter.context().types().u32());
    /* execute.simd:3508 [D] s_b_5_36 = s_b_5_32+s_b_5_35 */
    auto s_b_5_36 = emitter.add(s_b_5_32, s_b_5_35);
    /* ???:4294967295 [D] s_b_5_37 = s_b_5_29+s_b_5_36 */
    auto s_b_5_37 = emitter.add(s_b_5_29, s_b_5_36);
    /* execute.simd:3508 [F] s_b_5_38 = constant s32 2 (const) */
    /* execute.simd:3508 [D] s_b_5_39 = s_b_5_27[s_b_5_38] <= s_b_5_37 */
    auto s_b_5_39 = emitter.vector_insert(s_b_5_27, emitter.const_s32((int32_t)2ULL), s_b_5_37);
    /* ???:4294967295 [F] s_b_5_40 = constant u8 3 (const) */
    /* execute.simd:3508 [D] s_b_5_39[s_b_5_40] */
    auto s_b_5_41 = emitter.vector_extract(s_b_5_39, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3508 [F] s_b_5_42 = constant u32 6 (const) */
    /* execute.simd:3508 [D] s_b_5_1[s_b_5_42] */
    auto s_b_5_43 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3508 [D] s_b_5_44 = (u32)s_b_5_43 */
    auto s_b_5_44 = emitter.zx(s_b_5_43, emitter.context().types().u32());
    /* execute.simd:3508 [F] s_b_5_45 = constant u32 7 (const) */
    /* execute.simd:3508 [D] s_b_5_1[s_b_5_45] */
    auto s_b_5_46 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3508 [D] s_b_5_47 = (u32)s_b_5_46 */
    auto s_b_5_47 = emitter.zx(s_b_5_46, emitter.context().types().u32());
    /* execute.simd:3508 [D] s_b_5_48 = s_b_5_44+s_b_5_47 */
    auto s_b_5_48 = emitter.add(s_b_5_44, s_b_5_47);
    /* ???:4294967295 [D] s_b_5_49 = s_b_5_41+s_b_5_48 */
    auto s_b_5_49 = emitter.add(s_b_5_41, s_b_5_48);
    /* execute.simd:3508 [F] s_b_5_50 = constant s32 3 (const) */
    /* execute.simd:3508 [D] s_b_5_51 = s_b_5_39[s_b_5_50] <= s_b_5_49 */
    auto s_b_5_51 = emitter.vector_insert(s_b_5_39, emitter.const_s32((int32_t)3ULL), s_b_5_49);
    /* execute.simd:3511 [F] s_b_5_52=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3511 [D] s_b_5_53: WriteRegBank 20:s_b_5_52 = s_b_5_51 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_51,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_51);
    /* execute.simd:0 [F] s_b_5_54: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:3515 [F] s_b_6_0=sym_36037_3_parameter_inst.rn (const) */
    /* execute.simd:3515 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:3516 [F] s_b_6_2=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3516 [D] s_b_6_3 = ReadRegBank 21:s_b_6_2 (v2u64) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_3,emitter.const_u8(16));
    }
    /* execute.simd:3518 [F] s_b_6_4 = constant s32 0 (const) */
    /* execute.simd:3518 [D] s_b_6_3[s_b_6_4] */
    auto s_b_6_5 = emitter.vector_extract(s_b_6_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3518 [F] s_b_6_6 = constant s32 0 (const) */
    /* execute.simd:3518 [D] s_b_6_1[s_b_6_6] */
    auto s_b_6_7 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3518 [D] s_b_6_8 = (u64)s_b_6_7 */
    auto s_b_6_8 = emitter.zx(s_b_6_7, emitter.context().types().u64());
    /* execute.simd:3518 [F] s_b_6_9 = constant s32 1 (const) */
    /* execute.simd:3518 [D] s_b_6_1[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:3518 [D] s_b_6_11 = (u64)s_b_6_10 */
    auto s_b_6_11 = emitter.zx(s_b_6_10, emitter.context().types().u64());
    /* execute.simd:3518 [D] s_b_6_12 = s_b_6_8+s_b_6_11 */
    auto s_b_6_12 = emitter.add(s_b_6_8, s_b_6_11);
    /* ???:4294967295 [D] s_b_6_13 = s_b_6_5+s_b_6_12 */
    auto s_b_6_13 = emitter.add(s_b_6_5, s_b_6_12);
    /* execute.simd:3518 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:3518 [D] s_b_6_15 = s_b_6_3[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(s_b_6_3, emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* execute.simd:3519 [F] s_b_6_16 = constant s32 1 (const) */
    /* execute.simd:3519 [F] s_b_6_17 = constant u64 0 (const) */
    /* execute.simd:3519 [D] s_b_6_18 = s_b_6_15[s_b_6_16] <= s_b_6_17 */
    auto s_b_6_18 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:3521 [F] s_b_6_19=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3521 [D] s_b_6_20: WriteRegBank 21:s_b_6_19 = s_b_6_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_18,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_18);
    /* execute.simd:0 [F] s_b_6_21: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:3525 [F] s_b_7_0=sym_36037_3_parameter_inst.rn (const) */
    /* execute.simd:3525 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:3526 [F] s_b_7_2=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3526 [D] s_b_7_3 = ReadRegBank 21:s_b_7_2 (v2u64) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:3528 [F] s_b_7_4 = constant s32 0 (const) */
    /* execute.simd:3528 [D] s_b_7_3[s_b_7_4] */
    auto s_b_7_5 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3528 [F] s_b_7_6 = constant s32 0 (const) */
    /* execute.simd:3528 [D] s_b_7_1[s_b_7_6] */
    auto s_b_7_7 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3528 [D] s_b_7_8 = (u64)s_b_7_7 */
    auto s_b_7_8 = emitter.zx(s_b_7_7, emitter.context().types().u64());
    /* execute.simd:3528 [F] s_b_7_9 = constant s32 1 (const) */
    /* execute.simd:3528 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:3528 [D] s_b_7_11 = (u64)s_b_7_10 */
    auto s_b_7_11 = emitter.zx(s_b_7_10, emitter.context().types().u64());
    /* execute.simd:3528 [D] s_b_7_12 = s_b_7_8+s_b_7_11 */
    auto s_b_7_12 = emitter.add(s_b_7_8, s_b_7_11);
    /* ???:4294967295 [D] s_b_7_13 = s_b_7_5+s_b_7_12 */
    auto s_b_7_13 = emitter.add(s_b_7_5, s_b_7_12);
    /* execute.simd:3528 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:3528 [D] s_b_7_15 = s_b_7_3[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(s_b_7_3, emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:3529 [F] s_b_7_16 = constant s32 1 (const) */
    /* execute.simd:3529 [D] s_b_7_15[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_15, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:3529 [F] s_b_7_18 = constant s32 2 (const) */
    /* execute.simd:3529 [D] s_b_7_1[s_b_7_18] */
    auto s_b_7_19 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:3529 [D] s_b_7_20 = (u64)s_b_7_19 */
    auto s_b_7_20 = emitter.zx(s_b_7_19, emitter.context().types().u64());
    /* execute.simd:3529 [F] s_b_7_21 = constant s32 3 (const) */
    /* execute.simd:3529 [D] s_b_7_1[s_b_7_21] */
    auto s_b_7_22 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:3529 [D] s_b_7_23 = (u64)s_b_7_22 */
    auto s_b_7_23 = emitter.zx(s_b_7_22, emitter.context().types().u64());
    /* execute.simd:3529 [D] s_b_7_24 = s_b_7_20+s_b_7_23 */
    auto s_b_7_24 = emitter.add(s_b_7_20, s_b_7_23);
    /* ???:4294967295 [D] s_b_7_25 = s_b_7_17+s_b_7_24 */
    auto s_b_7_25 = emitter.add(s_b_7_17, s_b_7_24);
    /* execute.simd:3529 [F] s_b_7_26 = constant s32 1 (const) */
    /* execute.simd:3529 [D] s_b_7_27 = s_b_7_15[s_b_7_26] <= s_b_7_25 */
    auto s_b_7_27 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_25);
    /* execute.simd:3531 [F] s_b_7_28=sym_36037_3_parameter_inst.rd (const) */
    /* execute.simd:3531 [D] s_b_7_29: WriteRegBank 21:s_b_7_28 = s_b_7_27 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_27,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_27);
    /* execute.simd:0 [F] s_b_7_30: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:3535 [D] s_b_8_0 = trap */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_udiv(const arm64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto block_b_13 = emitter.context().create_block();
  auto block_b_14 = emitter.context().create_block();
  auto block_b_15 = emitter.context().create_block();
  auto block_b_25 = emitter.context().create_block();
  auto block_b_26 = emitter.context().create_block();
  uint32_t CV_sym_156200_1_temporary_value;
  auto DV_sym_156200_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_156146_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  uint32_t CV_sym_156109_1_temporary_value;
  auto DV_sym_156109_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_156104_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_156095_1_temporary_value;
  auto DV_sym_156095_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_156241_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_156195_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_156186_1_temporary_value;
  auto DV_sym_156186_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_156263_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_39613_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_39618_0_rm = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_39629_0_result = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2288 [F] s_b_0_0=sym_39608_3_parameter_inst.sf (const) */
    /* execute.a64:2697 [F] s_b_0_1: If s_b_0_0: Jump b_4 else b_7 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  // BLOCK b_1 not fully fixed
  // BLOCK b_2 not fully fixed
  // BLOCK b_3 not fully fixed
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2698 [F] s_b_4_0=sym_39608_3_parameter_inst.rn (const) */
    /* execute.a64:2692 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2692 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_4_4: If s_b_4_3: Jump b_5 else b_6 (const) */
    if (s_b_4_3) 
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
    /* execute.a64:2692 [F] s_b_5_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_5_1: sym_156095_1_temporary_value = s_b_5_0 (const), dominates: s_b_10_0  */
    CV_sym_156095_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_156095_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_5_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2692 [F] s_b_6_0=sym_39608_3_parameter_inst.rn (const) */
    /* execute.a64:2692 [D] s_b_6_1 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_6_2: sym_156095_1_temporary_value = s_b_6_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_156095_1_temporary_value, s_b_6_1);
    /* execute.a64:2692 [F] s_b_6_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2700 [F] s_b_7_0=sym_39608_3_parameter_inst.rn (const) */
    /* execute.a64:2687 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2687 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
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
    /* execute.a64:2687 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_8_1: sym_156109_1_temporary_value = s_b_8_0 (const), dominates: s_b_12_0  */
    CV_sym_156109_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_156109_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_8_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2687 [F] s_b_9_0=sym_39608_3_parameter_inst.rn (const) */
    /* execute.a64:2687 [D] s_b_9_1 = ReadRegBank 1:s_b_9_0 (u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_9_2: sym_156109_1_temporary_value = s_b_9_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_156109_1_temporary_value, s_b_9_1);
    /* execute.a64:2687 [F] s_b_9_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_5, b_6,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2692 [D] s_b_10_0 = sym_156095_1_temporary_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_156095_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1: sym_156104_0_return_symbol = s_b_10_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_156104_0_return_symbol, s_b_10_0);
    /* ???:4294967295 [F] s_b_10_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_12,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_156104_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_156104_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:2288 [D] s_b_11_1: sym_39613_0_rn = s_b_11_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_39613_0_rn, s_b_11_0);
    /* execute.a64:2289 [F] s_b_11_2=sym_39608_3_parameter_inst.sf (const) */
    /* execute.a64:2697 [F] s_b_11_3: If s_b_11_2: Jump b_16 else b_19 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_8, b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2687 [D] s_b_12_0 = sym_156109_1_temporary_value uint32_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_156109_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_12_1 = (u64)s_b_12_0 */
    auto s_b_12_1 = emitter.zx(s_b_12_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_2: sym_156104_0_return_symbol = s_b_12_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_156104_0_return_symbol, s_b_12_1);
    /* ???:4294967295 [F] s_b_12_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  // BLOCK b_13 not fully fixed
  // BLOCK b_14 not fully fixed
  // BLOCK b_15 not fully fixed
  /* b_11,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2698 [F] s_b_16_0=sym_39608_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2692 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2692 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2692 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
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
    /* execute.a64:2692 [F] s_b_17_0 = constant u64 0 (const) */
    /* execute.a64:2692 [F] s_b_17_1: sym_156186_1_temporary_value = s_b_17_0 (const), dominates: s_b_22_0  */
    CV_sym_156186_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_156186_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2692 [F] s_b_17_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2692 [F] s_b_18_0=sym_39608_3_parameter_inst.rm (const) */
    /* execute.a64:2692 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.a64:2692 [D] s_b_18_2: sym_156186_1_temporary_value = s_b_18_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_156186_1_temporary_value, s_b_18_1);
    /* execute.a64:2692 [F] s_b_18_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_11,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2700 [F] s_b_19_0=sym_39608_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2687 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2687 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2687 [F] s_b_19_4: If s_b_19_3: Jump b_20 else b_21 (const) */
    if (s_b_19_3) 
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
    /* execute.a64:2687 [F] s_b_20_0 = constant u32 0 (const) */
    /* execute.a64:2687 [F] s_b_20_1: sym_156200_1_temporary_value = s_b_20_0 (const), dominates: s_b_24_0  */
    CV_sym_156200_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_156200_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2687 [F] s_b_20_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2687 [F] s_b_21_0=sym_39608_3_parameter_inst.rm (const) */
    /* execute.a64:2687 [D] s_b_21_1 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_1,emitter.const_u8(4));
    }
    /* execute.a64:2687 [D] s_b_21_2: sym_156200_1_temporary_value = s_b_21_1, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_156200_1_temporary_value, s_b_21_1);
    /* execute.a64:2687 [F] s_b_21_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_17, b_18,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2692 [D] s_b_22_0 = sym_156186_1_temporary_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_156186_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_22_1: sym_156195_0_return_symbol = s_b_22_0, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_156195_0_return_symbol, s_b_22_0);
    /* ???:4294967295 [F] s_b_22_2: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_22, b_24,  */
  fixed_block_b_23: 
  {
    /* ???:4294967295 [D] s_b_23_0 = sym_156195_0_return_symbol uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_156195_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:2289 [D] s_b_23_1: sym_39618_0_rm = s_b_23_0, dominates: s_b_3_1  */
    emitter.store_local(DV_sym_39618_0_rm, s_b_23_0);
    /* execute.a64:2292 [F] s_b_23_2 = constant u64 0 (const) */
    /* execute.a64:2292 [D] s_b_23_3 = s_b_23_0==s_b_23_2 */
    auto s_b_23_3 = emitter.cmp_eq(s_b_23_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2292 [D] s_b_23_4: If s_b_23_3: Jump b_1 else b_3 */
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
      emitter.branch(s_b_23_3, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_20, b_21,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2687 [D] s_b_24_0 = sym_156200_1_temporary_value uint32_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_156200_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2700 [D] s_b_24_1 = (u64)s_b_24_0 */
    auto s_b_24_1 = emitter.zx(s_b_24_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_24_2: sym_156195_0_return_symbol = s_b_24_1, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_156195_0_return_symbol, s_b_24_1);
    /* ???:4294967295 [F] s_b_24_3: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
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
        /* execute.a64:2293 [F] s_b_1_0 = constant u64 0 (const) */
        /* execute.a64:2293 [D] s_b_1_1: sym_39629_0_result = s_b_1_0, dominates: s_b_2_1  */
        emitter.store_local(DV_sym_39629_0_result, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2293 [F] s_b_1_2: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_2) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_2);
        /* execute.a64:2298 [F] s_b_2_0=sym_39608_3_parameter_inst.sf (const) */
        /* execute.a64:2298 [D] s_b_2_1 = sym_39629_0_result uint64_t */
        auto s_b_2_1 = emitter.load_local(DV_sym_39629_0_result, emitter.context().types().u64());
        /* execute.a64:2298 [D] s_b_2_2: sym_156146_3_parameter_value = s_b_2_1, dominates: s_b_13_1 s_b_14_1  */
        emitter.store_local(DV_sym_156146_3_parameter_value, s_b_2_1);
        /* execute.a64:2731 [F] s_b_2_3: If s_b_2_0: Jump b_13 else b_14 (const) */
        if (insn.sf) 
        {
          auto block = block_b_13;
          dynamic_block_queue.push(block_b_13);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_3) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_3);
        /* execute.a64:2295 [D] s_b_3_0 = sym_39613_0_rn uint64_t */
        auto s_b_3_0 = emitter.load_local(DV_sym_39613_0_rn, emitter.context().types().u64());
        /* execute.a64:2295 [D] s_b_3_1 = sym_39618_0_rm uint64_t */
        auto s_b_3_1 = emitter.load_local(DV_sym_39618_0_rm, emitter.context().types().u64());
        /* execute.a64:2295 [D] s_b_3_2 = s_b_3_0/s_b_3_1 */
        auto s_b_3_2 = emitter.div(s_b_3_0, s_b_3_1);
        /* execute.a64:2295 [D] s_b_3_3: sym_39629_0_result = s_b_3_2, dominates: s_b_2_1  */
        emitter.store_local(DV_sym_39629_0_result, s_b_3_2);
        /* execute.a64:2295 [F] s_b_3_4: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.a64:2732 [F] s_b_13_0=sym_39608_3_parameter_inst.rd (const) */
        /* execute.a64:2732 [D] s_b_13_1 = sym_156146_3_parameter_value uint64_t */
        auto s_b_13_1 = emitter.load_local(DV_sym_156146_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2732 [D] s_b_13_2: sym_156241_3_parameter_value = s_b_13_1, dominates: s_b_25_1  */
        emitter.store_local(DV_sym_156241_3_parameter_value, s_b_13_1);
        /* execute.a64:2723 [F] s_b_13_3 = (u32)s_b_13_0 (const) */
        /* execute.a64:2723 [F] s_b_13_4 = constant u32 1f (const) */
        /* execute.a64:2723 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
        uint8_t s_b_13_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2723 [F] s_b_13_6: If s_b_13_5: Jump b_15 else b_25 (const) */
        if (s_b_13_5) 
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.a64:2734 [F] s_b_14_0=sym_39608_3_parameter_inst.rd (const) */
        /* execute.a64:2734 [D] s_b_14_1 = sym_156146_3_parameter_value uint64_t */
        auto s_b_14_1 = emitter.load_local(DV_sym_156146_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2734 [D] s_b_14_2 = (u32)s_b_14_1 */
        auto s_b_14_2 = emitter.truncate(s_b_14_1, emitter.context().types().u32());
        /* execute.a64:2734 [D] s_b_14_3 = (u64)s_b_14_2 */
        auto s_b_14_3 = emitter.zx(s_b_14_2, emitter.context().types().u64());
        /* execute.a64:2734 [D] s_b_14_4: sym_156263_3_parameter_value = s_b_14_3, dominates: s_b_26_1  */
        emitter.store_local(DV_sym_156263_3_parameter_value, s_b_14_3);
        /* execute.a64:2723 [F] s_b_14_5 = (u32)s_b_14_0 (const) */
        /* execute.a64:2723 [F] s_b_14_6 = constant u32 1f (const) */
        /* execute.a64:2723 [F] s_b_14_7 = s_b_14_5==s_b_14_6 (const) */
        uint8_t s_b_14_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2723 [F] s_b_14_8: If s_b_14_7: Jump b_15 else b_26 (const) */
        if (s_b_14_7) 
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* ???:4294967295 [F] s_b_15_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.a64:2725 [F] s_b_25_0=sym_39608_3_parameter_inst.rd (const) */
        /* execute.a64:2725 [D] s_b_25_1 = sym_156241_3_parameter_value uint64_t */
        auto s_b_25_1 = emitter.load_local(DV_sym_156241_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2725 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1);
        /* execute.a64:0 [F] s_b_25_3: Jump b_15 (const) */
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.a64:2725 [F] s_b_26_0=sym_39608_3_parameter_inst.rd (const) */
        /* execute.a64:2725 [D] s_b_26_1 = sym_156263_3_parameter_value uint64_t */
        auto s_b_26_1 = emitter.load_local(DV_sym_156263_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2725 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1);
        /* execute.a64:0 [F] s_b_26_3: Jump b_15 (const) */
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ushl(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto block_b_51 = emitter.context().create_block();
  auto block_b_52 = emitter.context().create_block();
  auto block_b_53 = emitter.context().create_block();
  auto block_b_54 = emitter.context().create_block();
  auto block_b_55 = emitter.context().create_block();
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
  auto block_b_70 = emitter.context().create_block();
  auto block_b_71 = emitter.context().create_block();
  auto block_b_72 = emitter.context().create_block();
  auto block_b_73 = emitter.context().create_block();
  auto block_b_74 = emitter.context().create_block();
  auto block_b_75 = emitter.context().create_block();
  auto block_b_76 = emitter.context().create_block();
  auto block_b_77 = emitter.context().create_block();
  auto block_b_78 = emitter.context().create_block();
  auto block_b_79 = emitter.context().create_block();
  auto block_b_80 = emitter.context().create_block();
  auto block_b_81 = emitter.context().create_block();
  auto block_b_82 = emitter.context().create_block();
  auto block_b_83 = emitter.context().create_block();
  auto block_b_85 = emitter.context().create_block();
  auto block_b_86 = emitter.context().create_block();
  auto block_b_87 = emitter.context().create_block();
  auto block_b_88 = emitter.context().create_block();
  auto block_b_89 = emitter.context().create_block();
  auto block_b_90 = emitter.context().create_block();
  auto block_b_91 = emitter.context().create_block();
  auto block_b_92 = emitter.context().create_block();
  auto block_b_93 = emitter.context().create_block();
  auto block_b_94 = emitter.context().create_block();
  auto block_b_95 = emitter.context().create_block();
  auto block_b_96 = emitter.context().create_block();
  auto block_b_98 = emitter.context().create_block();
  auto block_b_99 = emitter.context().create_block();
  auto block_b_100 = emitter.context().create_block();
  auto block_b_101 = emitter.context().create_block();
  auto block_b_102 = emitter.context().create_block();
  auto block_b_103 = emitter.context().create_block();
  auto block_b_104 = emitter.context().create_block();
  auto block_b_105 = emitter.context().create_block();
  auto block_b_106 = emitter.context().create_block();
  auto block_b_107 = emitter.context().create_block();
  auto block_b_108 = emitter.context().create_block();
  auto block_b_109 = emitter.context().create_block();
  auto block_b_110 = emitter.context().create_block();
  auto block_b_111 = emitter.context().create_block();
  auto block_b_112 = emitter.context().create_block();
  auto block_b_113 = emitter.context().create_block();
  auto block_b_114 = emitter.context().create_block();
  auto block_b_115 = emitter.context().create_block();
  auto block_b_116 = emitter.context().create_block();
  auto block_b_117 = emitter.context().create_block();
  auto block_b_118 = emitter.context().create_block();
  auto block_b_119 = emitter.context().create_block();
  auto block_b_120 = emitter.context().create_block();
  auto block_b_121 = emitter.context().create_block();
  auto block_b_123 = emitter.context().create_block();
  auto block_b_124 = emitter.context().create_block();
  auto block_b_125 = emitter.context().create_block();
  auto block_b_126 = emitter.context().create_block();
  auto block_b_127 = emitter.context().create_block();
  auto block_b_128 = emitter.context().create_block();
  auto block_b_130 = emitter.context().create_block();
  auto block_b_131 = emitter.context().create_block();
  auto block_b_132 = emitter.context().create_block();
  auto block_b_133 = emitter.context().create_block();
  auto block_b_134 = emitter.context().create_block();
  auto block_b_135 = emitter.context().create_block();
  auto block_b_136 = emitter.context().create_block();
  auto block_b_137 = emitter.context().create_block();
  auto block_b_138 = emitter.context().create_block();
  auto block_b_139 = emitter.context().create_block();
  auto block_b_140 = emitter.context().create_block();
  auto block_b_141 = emitter.context().create_block();
  auto block_b_143 = emitter.context().create_block();
  auto block_b_144 = emitter.context().create_block();
  auto block_b_145 = emitter.context().create_block();
  auto block_b_146 = emitter.context().create_block();
  auto block_b_147 = emitter.context().create_block();
  auto block_b_148 = emitter.context().create_block();
  auto DV_sym_41405_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_41410_0_rm = emitter.alloc_local(emitter.context().types().s8(), true);
  auto DV_sym_41470_0_rn = emitter.alloc_local(emitter.context().types().v8u8(), true);
  auto DV_sym_41474_0_rm = emitter.alloc_local(emitter.context().types().v8s8(), true);
  wutils::Vector<uint8_t, 16> CV_sym_41479_0_rd;
  auto DV_sym_41479_0_rd = emitter.alloc_local(emitter.context().types().v16u8(), true);
  auto DV_sym_41876_0_rn = emitter.alloc_local(emitter.context().types().v16u8(), true);
  auto DV_sym_41880_0_rm = emitter.alloc_local(emitter.context().types().v16s8(), true);
  wutils::Vector<uint8_t, 16> CV_sym_41885_0_rd;
  auto DV_sym_41885_0_rd = emitter.alloc_local(emitter.context().types().v16u8(), true);
  auto DV_sym_42666_0_rn = emitter.alloc_local(emitter.context().types().v4u16(), true);
  auto DV_sym_42670_0_rm = emitter.alloc_local(emitter.context().types().v4s16(), true);
  wutils::Vector<uint16_t, 8> CV_sym_42675_0_rd;
  auto DV_sym_42675_0_rd = emitter.alloc_local(emitter.context().types().v8u16(), true);
  auto DV_sym_42880_0_rn = emitter.alloc_local(emitter.context().types().v8u16(), true);
  auto DV_sym_42884_0_rm = emitter.alloc_local(emitter.context().types().v8s16(), true);
  wutils::Vector<uint16_t, 8> CV_sym_42889_0_rd;
  auto DV_sym_42889_0_rd = emitter.alloc_local(emitter.context().types().v8u16(), true);
  auto DV_sym_43286_0_rn = emitter.alloc_local(emitter.context().types().v2u32(), true);
  auto DV_sym_43290_0_rm = emitter.alloc_local(emitter.context().types().v2s32(), true);
  wutils::Vector<uint32_t, 4> CV_sym_43295_0_rd;
  auto DV_sym_43295_0_rd = emitter.alloc_local(emitter.context().types().v4u32(), true);
  auto DV_sym_43402_0_rn = emitter.alloc_local(emitter.context().types().v4u32(), true);
  auto DV_sym_43406_0_rm = emitter.alloc_local(emitter.context().types().v4s32(), true);
  wutils::Vector<uint32_t, 4> CV_sym_43411_0_rd;
  auto DV_sym_43411_0_rd = emitter.alloc_local(emitter.context().types().v4u32(), true);
  auto DV_sym_43612_0_rn = emitter.alloc_local(emitter.context().types().v2u64(), true);
  auto DV_sym_43616_0_rm = emitter.alloc_local(emitter.context().types().v2s64(), true);
  wutils::Vector<uint64_t, 2> CV_sym_43621_0_rd;
  auto DV_sym_43621_0_rd = emitter.alloc_local(emitter.context().types().v2u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2965 [F] s_b_0_0=sym_41396_3_parameter_inst.SCALAR (const) */
    /* execute.simd:2965 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2966 [F] s_b_1_0=sym_41396_3_parameter_inst.rn (const) */
    /* execute.simd:6237 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:2966 [D] s_b_1_2: sym_41405_0_rn = s_b_1_1, dominates: s_b_6_1 s_b_9_1  */
    emitter.store_local(DV_sym_41405_0_rn, s_b_1_1);
    /* execute.simd:2967 [F] s_b_1_3=sym_41396_3_parameter_inst.rm (const) */
    /* execute.simd:6237 [D] s_b_1_4 = ReadRegBank 7:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:2967 [D] s_b_1_5 = (s8)s_b_1_4 */
    auto s_b_1_5 = emitter.truncate(s_b_1_4, emitter.context().types().s8());
    /* execute.simd:2967 [D] s_b_1_6: sym_41410_0_rm = s_b_1_5, dominates: s_b_5_0 s_b_6_2 s_b_7_0 s_b_9_2  */
    emitter.store_local(DV_sym_41410_0_rm, s_b_1_5);
    /* execute.simd:2969 [F] s_b_1_7 = constant s32 3f (const) */
    /* execute.simd:2969 [D] s_b_1_8 = (s32)s_b_1_5 */
    auto s_b_1_8 = emitter.sx(s_b_1_5, emitter.context().types().s32());
    /* execute.simd:2969 [D] s_b_1_9 = s_b_1_8>s_b_1_7 */
    auto s_b_1_9 = emitter.cmp_gt(s_b_1_8, emitter.const_s32((int32_t)63ULL));
    /* execute.simd:2969 [D] s_b_1_10: If s_b_1_9: Jump b_4 else b_5 */
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
      emitter.branch(s_b_1_9, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2979 [F] s_b_3_0=sym_41396_3_parameter_inst.arrangement (const) */
    /* execute.simd:2980 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:2996 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:3012 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:3028 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:3044 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:3060 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:3076 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:2979 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_149 (const) -> b_10, b_35, b_84, b_97, b_122, b_129, b_142, b_149,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_35;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_84;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_97;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_122;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_129;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_142;
      break;
    default:
      goto fixed_block_b_149;
    }
  }
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  // BLOCK b_6 not fully fixed
  // BLOCK b_7 not fully fixed
  // BLOCK b_8 not fully fixed
  // BLOCK b_9 not fully fixed
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2981 [F] s_b_10_0=sym_41396_3_parameter_inst.rn (const) */
    /* execute.simd:2981 [D] s_b_10_1 = ReadRegBank 15:s_b_10_0 (v8u8) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.simd:2981 [D] s_b_10_2: sym_41470_0_rn = s_b_10_1, dominates: s_b_11_0 s_b_14_0 s_b_17_0 s_b_20_0 s_b_23_0 s_b_26_0 s_b_29_0 s_b_32_0 s_b_34_0 s_b_31_0 s_b_28_0 s_b_25_0 s_b_22_0 s_b_19_0 s_b_16_0 s_b_13_0  */
    emitter.store_local(DV_sym_41470_0_rn, s_b_10_1);
    /* execute.simd:2982 [F] s_b_10_3=sym_41396_3_parameter_inst.rm (const) */
    /* execute.simd:2982 [D] s_b_10_4 = ReadRegBank 15:s_b_10_3 (v8u8) */
    auto s_b_10_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_4,emitter.const_u8(8));
    }
    /* execute.simd:2982 [D] s_b_10_5 = (v8s8)s_b_10_4 */
    auto s_b_10_5 = emitter.reinterpret(s_b_10_4, emitter.context().types().v8s8());
    /* execute.simd:2982 [D] s_b_10_6: sym_41474_0_rm = s_b_10_5, dominates: s_b_11_3 s_b_12_0 s_b_14_3 s_b_15_0 s_b_17_3 s_b_18_0 s_b_20_3 s_b_21_0 s_b_23_3 s_b_24_0 s_b_26_3 s_b_27_0 s_b_29_3 s_b_30_0 s_b_32_3 s_b_34_3 s_b_31_3 s_b_28_3 s_b_25_3 s_b_22_3 s_b_19_3 s_b_16_3 s_b_13_3  */
    emitter.store_local(DV_sym_41474_0_rm, s_b_10_5);
    /* ???:4294967295 [F] s_b_10_7 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:2984 [F] s_b_10_8: sym_41479_0_rd = s_b_10_7 (const), dominates: s_b_11_9 s_b_13_8  */
    CV_sym_41479_0_rd = wutils::Vector<uint8_t, 16>(0);
    emitter.store_local(DV_sym_41479_0_rd, emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()));
    /* ???:4294967295 [F] s_b_10_9 = constant u8 0 (const) */
    /* execute.simd:2986 [D] s_b_10_5[s_b_10_9] */
    auto s_b_10_10 = emitter.vector_extract(s_b_10_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:2986 [F] s_b_10_11 = constant s32 0 (const) */
    /* execute.simd:2986 [D] s_b_10_12 = (s32)s_b_10_10 */
    auto s_b_10_12 = emitter.sx(s_b_10_10, emitter.context().types().s32());
    /* execute.simd:2986 [D] s_b_10_13 = s_b_10_12<s_b_10_11 */
    auto s_b_10_13 = emitter.cmp_lt(s_b_10_12, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2986 [D] s_b_10_14: If s_b_10_13: Jump b_11 else b_13 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_11;
        dynamic_block_queue.push(block_b_11);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_13;
        dynamic_block_queue.push(block_b_13);
        false_target = block;
      }
      emitter.branch(s_b_10_13, true_target, false_target);
    }
    goto fixed_done;
  }
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
  /* b_3,  */
  fixed_block_b_35: 
  {
    /* execute.simd:2997 [F] s_b_35_0=sym_41396_3_parameter_inst.rn (const) */
    /* execute.simd:2997 [D] s_b_35_1 = ReadRegBank 16:s_b_35_0 (v16u8) */
    auto s_b_35_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_35_1,emitter.const_u8(16));
    }
    /* execute.simd:2997 [D] s_b_35_2: sym_41876_0_rn = s_b_35_1, dominates: s_b_36_0 s_b_39_0 s_b_42_0 s_b_45_0 s_b_48_0 s_b_51_0 s_b_54_0 s_b_57_0 s_b_60_0 s_b_63_0 s_b_66_0 s_b_69_0 s_b_72_0 s_b_75_0 s_b_78_0 s_b_81_0 s_b_83_0 s_b_80_0 s_b_77_0 s_b_74_0 s_b_71_0 s_b_68_0 s_b_65_0 s_b_62_0 s_b_59_0 s_b_56_0 s_b_53_0 s_b_50_0 s_b_47_0 s_b_44_0 s_b_41_0 s_b_38_0  */
    emitter.store_local(DV_sym_41876_0_rn, s_b_35_1);
    /* execute.simd:2998 [F] s_b_35_3=sym_41396_3_parameter_inst.rm (const) */
    /* execute.simd:2998 [D] s_b_35_4 = ReadRegBank 16:s_b_35_3 (v16u8) */
    auto s_b_35_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_35_4,emitter.const_u8(16));
    }
    /* execute.simd:2998 [D] s_b_35_5 = (v16s8)s_b_35_4 */
    auto s_b_35_5 = emitter.reinterpret(s_b_35_4, emitter.context().types().v16s8());
    /* execute.simd:2998 [D] s_b_35_6: sym_41880_0_rm = s_b_35_5, dominates: s_b_36_3 s_b_37_0 s_b_39_3 s_b_40_0 s_b_42_3 s_b_43_0 s_b_45_3 s_b_46_0 s_b_48_3 s_b_49_0 s_b_51_3 s_b_52_0 s_b_54_3 s_b_55_0 s_b_57_3 s_b_58_0 s_b_60_3 s_b_61_0 s_b_63_3 s_b_64_0 s_b_66_3 s_b_67_0 s_b_69_3 s_b_70_0 s_b_72_3 s_b_73_0 s_b_75_3 s_b_76_0 s_b_78_3 s_b_79_0 s_b_81_3 s_b_83_3 s_b_80_3 s_b_77_3 s_b_74_3 s_b_71_3 s_b_68_3 s_b_65_3 s_b_62_3 s_b_59_3 s_b_56_3 s_b_53_3 s_b_50_3 s_b_47_3 s_b_44_3 s_b_41_3 s_b_38_3  */
    emitter.store_local(DV_sym_41880_0_rm, s_b_35_5);
    /* ???:4294967295 [F] s_b_35_7 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:3000 [F] s_b_35_8: sym_41885_0_rd = s_b_35_7 (const), dominates: s_b_36_9 s_b_38_8  */
    CV_sym_41885_0_rd = wutils::Vector<uint8_t, 16>(0);
    emitter.store_local(DV_sym_41885_0_rd, emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()));
    /* ???:4294967295 [F] s_b_35_9 = constant u8 0 (const) */
    /* execute.simd:3002 [D] s_b_35_5[s_b_35_9] */
    auto s_b_35_10 = emitter.vector_extract(s_b_35_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3002 [F] s_b_35_11 = constant s32 0 (const) */
    /* execute.simd:3002 [D] s_b_35_12 = (s32)s_b_35_10 */
    auto s_b_35_12 = emitter.sx(s_b_35_10, emitter.context().types().s32());
    /* execute.simd:3002 [D] s_b_35_13 = s_b_35_12<s_b_35_11 */
    auto s_b_35_13 = emitter.cmp_lt(s_b_35_12, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3002 [D] s_b_35_14: If s_b_35_13: Jump b_36 else b_38 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_36;
        dynamic_block_queue.push(block_b_36);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_38;
        dynamic_block_queue.push(block_b_38);
        false_target = block;
      }
      emitter.branch(s_b_35_13, true_target, false_target);
    }
    goto fixed_done;
  }
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
  // BLOCK b_51 not fully fixed
  // BLOCK b_52 not fully fixed
  // BLOCK b_53 not fully fixed
  // BLOCK b_54 not fully fixed
  // BLOCK b_55 not fully fixed
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
  // BLOCK b_70 not fully fixed
  // BLOCK b_71 not fully fixed
  // BLOCK b_72 not fully fixed
  // BLOCK b_73 not fully fixed
  // BLOCK b_74 not fully fixed
  // BLOCK b_75 not fully fixed
  // BLOCK b_76 not fully fixed
  // BLOCK b_77 not fully fixed
  // BLOCK b_78 not fully fixed
  // BLOCK b_79 not fully fixed
  // BLOCK b_80 not fully fixed
  // BLOCK b_81 not fully fixed
  // BLOCK b_82 not fully fixed
  // BLOCK b_83 not fully fixed
  /* b_3,  */
  fixed_block_b_84: 
  {
    /* execute.simd:3013 [F] s_b_84_0=sym_41396_3_parameter_inst.rn (const) */
    /* execute.simd:3013 [D] s_b_84_1 = ReadRegBank 17:s_b_84_0 (v4u16) */
    auto s_b_84_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_84_1,emitter.const_u8(8));
    }
    /* execute.simd:3013 [D] s_b_84_2: sym_42666_0_rn = s_b_84_1, dominates: s_b_85_0 s_b_88_0 s_b_91_0 s_b_94_0 s_b_96_0 s_b_93_0 s_b_90_0 s_b_87_0  */
    emitter.store_local(DV_sym_42666_0_rn, s_b_84_1);
    /* execute.simd:3014 [F] s_b_84_3=sym_41396_3_parameter_inst.rm (const) */
    /* execute.simd:3014 [D] s_b_84_4 = ReadRegBank 17:s_b_84_3 (v4u16) */
    auto s_b_84_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_84_4,emitter.const_u8(8));
    }
    /* execute.simd:3014 [D] s_b_84_5 = (v4s16)s_b_84_4 */
    auto s_b_84_5 = emitter.reinterpret(s_b_84_4, emitter.context().types().v4s16());
    /* execute.simd:3014 [D] s_b_84_6: sym_42670_0_rm = s_b_84_5, dominates: s_b_85_3 s_b_86_0 s_b_88_3 s_b_89_0 s_b_91_3 s_b_92_0 s_b_94_3 s_b_96_3 s_b_93_3 s_b_90_3 s_b_87_3  */
    emitter.store_local(DV_sym_42670_0_rm, s_b_84_5);
    /* ???:4294967295 [F] s_b_84_7 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:3016 [F] s_b_84_8: sym_42675_0_rd = s_b_84_7 (const), dominates: s_b_85_9 s_b_87_8  */
    CV_sym_42675_0_rd = wutils::Vector<uint16_t, 8>(0);
    emitter.store_local(DV_sym_42675_0_rd, emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()));
    /* ???:4294967295 [F] s_b_84_9 = constant u8 0 (const) */
    /* execute.simd:3018 [D] s_b_84_5[s_b_84_9] */
    auto s_b_84_10 = emitter.vector_extract(s_b_84_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3018 [F] s_b_84_11 = constant s32 0 (const) */
    /* execute.simd:3018 [D] s_b_84_12 = (s32)s_b_84_10 */
    auto s_b_84_12 = emitter.sx(s_b_84_10, emitter.context().types().s32());
    /* execute.simd:3018 [D] s_b_84_13 = s_b_84_12<s_b_84_11 */
    auto s_b_84_13 = emitter.cmp_lt(s_b_84_12, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3018 [D] s_b_84_14: If s_b_84_13: Jump b_85 else b_87 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_85;
        dynamic_block_queue.push(block_b_85);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_87;
        dynamic_block_queue.push(block_b_87);
        false_target = block;
      }
      emitter.branch(s_b_84_13, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_85 not fully fixed
  // BLOCK b_86 not fully fixed
  // BLOCK b_87 not fully fixed
  // BLOCK b_88 not fully fixed
  // BLOCK b_89 not fully fixed
  // BLOCK b_90 not fully fixed
  // BLOCK b_91 not fully fixed
  // BLOCK b_92 not fully fixed
  // BLOCK b_93 not fully fixed
  // BLOCK b_94 not fully fixed
  // BLOCK b_95 not fully fixed
  // BLOCK b_96 not fully fixed
  /* b_3,  */
  fixed_block_b_97: 
  {
    /* execute.simd:3029 [F] s_b_97_0=sym_41396_3_parameter_inst.rn (const) */
    /* execute.simd:3029 [D] s_b_97_1 = ReadRegBank 18:s_b_97_0 (v8u16) */
    auto s_b_97_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_97_1,emitter.const_u8(16));
    }
    /* execute.simd:3029 [D] s_b_97_2: sym_42880_0_rn = s_b_97_1, dominates: s_b_98_0 s_b_101_0 s_b_104_0 s_b_107_0 s_b_110_0 s_b_113_0 s_b_116_0 s_b_119_0 s_b_121_0 s_b_118_0 s_b_115_0 s_b_112_0 s_b_109_0 s_b_106_0 s_b_103_0 s_b_100_0  */
    emitter.store_local(DV_sym_42880_0_rn, s_b_97_1);
    /* execute.simd:3030 [F] s_b_97_3=sym_41396_3_parameter_inst.rm (const) */
    /* execute.simd:3030 [D] s_b_97_4 = ReadRegBank 18:s_b_97_3 (v8u16) */
    auto s_b_97_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_97_4,emitter.const_u8(16));
    }
    /* execute.simd:3030 [D] s_b_97_5 = (v8s16)s_b_97_4 */
    auto s_b_97_5 = emitter.reinterpret(s_b_97_4, emitter.context().types().v8s16());
    /* execute.simd:3030 [D] s_b_97_6: sym_42884_0_rm = s_b_97_5, dominates: s_b_98_3 s_b_99_0 s_b_101_3 s_b_102_0 s_b_104_3 s_b_105_0 s_b_107_3 s_b_108_0 s_b_110_3 s_b_111_0 s_b_113_3 s_b_114_0 s_b_116_3 s_b_117_0 s_b_119_3 s_b_121_3 s_b_118_3 s_b_115_3 s_b_112_3 s_b_109_3 s_b_106_3 s_b_103_3 s_b_100_3  */
    emitter.store_local(DV_sym_42884_0_rm, s_b_97_5);
    /* ???:4294967295 [F] s_b_97_7 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:3032 [F] s_b_97_8: sym_42889_0_rd = s_b_97_7 (const), dominates: s_b_98_9 s_b_100_8  */
    CV_sym_42889_0_rd = wutils::Vector<uint16_t, 8>(0);
    emitter.store_local(DV_sym_42889_0_rd, emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()));
    /* ???:4294967295 [F] s_b_97_9 = constant u8 0 (const) */
    /* execute.simd:3034 [D] s_b_97_5[s_b_97_9] */
    auto s_b_97_10 = emitter.vector_extract(s_b_97_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3034 [F] s_b_97_11 = constant s32 0 (const) */
    /* execute.simd:3034 [D] s_b_97_12 = (s32)s_b_97_10 */
    auto s_b_97_12 = emitter.sx(s_b_97_10, emitter.context().types().s32());
    /* execute.simd:3034 [D] s_b_97_13 = s_b_97_12<s_b_97_11 */
    auto s_b_97_13 = emitter.cmp_lt(s_b_97_12, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3034 [D] s_b_97_14: If s_b_97_13: Jump b_98 else b_100 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_98;
        dynamic_block_queue.push(block_b_98);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_100;
        dynamic_block_queue.push(block_b_100);
        false_target = block;
      }
      emitter.branch(s_b_97_13, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_98 not fully fixed
  // BLOCK b_99 not fully fixed
  // BLOCK b_100 not fully fixed
  // BLOCK b_101 not fully fixed
  // BLOCK b_102 not fully fixed
  // BLOCK b_103 not fully fixed
  // BLOCK b_104 not fully fixed
  // BLOCK b_105 not fully fixed
  // BLOCK b_106 not fully fixed
  // BLOCK b_107 not fully fixed
  // BLOCK b_108 not fully fixed
  // BLOCK b_109 not fully fixed
  // BLOCK b_110 not fully fixed
  // BLOCK b_111 not fully fixed
  // BLOCK b_112 not fully fixed
  // BLOCK b_113 not fully fixed
  // BLOCK b_114 not fully fixed
  // BLOCK b_115 not fully fixed
  // BLOCK b_116 not fully fixed
  // BLOCK b_117 not fully fixed
  // BLOCK b_118 not fully fixed
  // BLOCK b_119 not fully fixed
  // BLOCK b_120 not fully fixed
  // BLOCK b_121 not fully fixed
  /* b_3,  */
  fixed_block_b_122: 
  {
    /* execute.simd:3045 [F] s_b_122_0=sym_41396_3_parameter_inst.rn (const) */
    /* execute.simd:3045 [D] s_b_122_1 = ReadRegBank 19:s_b_122_0 (v2u32) */
    auto s_b_122_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_122_1,emitter.const_u8(8));
    }
    /* execute.simd:3045 [D] s_b_122_2: sym_43286_0_rn = s_b_122_1, dominates: s_b_123_0 s_b_126_0 s_b_128_0 s_b_125_0  */
    emitter.store_local(DV_sym_43286_0_rn, s_b_122_1);
    /* execute.simd:3046 [F] s_b_122_3=sym_41396_3_parameter_inst.rm (const) */
    /* execute.simd:3046 [D] s_b_122_4 = ReadRegBank 19:s_b_122_3 (v2u32) */
    auto s_b_122_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_122_4,emitter.const_u8(8));
    }
    /* execute.simd:3046 [D] s_b_122_5 = (v2s32)s_b_122_4 */
    auto s_b_122_5 = emitter.reinterpret(s_b_122_4, emitter.context().types().v2s32());
    /* execute.simd:3046 [D] s_b_122_6: sym_43290_0_rm = s_b_122_5, dominates: s_b_123_3 s_b_124_0 s_b_126_3 s_b_128_3 s_b_125_3  */
    emitter.store_local(DV_sym_43290_0_rm, s_b_122_5);
    /* ???:4294967295 [F] s_b_122_7 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:3048 [F] s_b_122_8: sym_43295_0_rd = s_b_122_7 (const), dominates: s_b_123_9 s_b_125_8  */
    CV_sym_43295_0_rd = wutils::Vector<uint32_t, 4>(0);
    emitter.store_local(DV_sym_43295_0_rd, emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()));
    /* ???:4294967295 [F] s_b_122_9 = constant u8 0 (const) */
    /* execute.simd:3050 [D] s_b_122_5[s_b_122_9] */
    auto s_b_122_10 = emitter.vector_extract(s_b_122_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3050 [F] s_b_122_11 = constant s32 0 (const) */
    /* execute.simd:3050 [D] s_b_122_12 = s_b_122_10<s_b_122_11 */
    auto s_b_122_12 = emitter.cmp_lt(s_b_122_10, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3050 [D] s_b_122_13: If s_b_122_12: Jump b_123 else b_125 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_123;
        dynamic_block_queue.push(block_b_123);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_125;
        dynamic_block_queue.push(block_b_125);
        false_target = block;
      }
      emitter.branch(s_b_122_12, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_123 not fully fixed
  // BLOCK b_124 not fully fixed
  // BLOCK b_125 not fully fixed
  // BLOCK b_126 not fully fixed
  // BLOCK b_127 not fully fixed
  // BLOCK b_128 not fully fixed
  /* b_3,  */
  fixed_block_b_129: 
  {
    /* execute.simd:3061 [F] s_b_129_0=sym_41396_3_parameter_inst.rn (const) */
    /* execute.simd:3061 [D] s_b_129_1 = ReadRegBank 20:s_b_129_0 (v4u32) */
    auto s_b_129_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_129_1,emitter.const_u8(16));
    }
    /* execute.simd:3061 [D] s_b_129_2: sym_43402_0_rn = s_b_129_1, dominates: s_b_130_0 s_b_133_0 s_b_136_0 s_b_139_0 s_b_141_0 s_b_138_0 s_b_135_0 s_b_132_0  */
    emitter.store_local(DV_sym_43402_0_rn, s_b_129_1);
    /* execute.simd:3062 [F] s_b_129_3=sym_41396_3_parameter_inst.rm (const) */
    /* execute.simd:3062 [D] s_b_129_4 = ReadRegBank 20:s_b_129_3 (v4u32) */
    auto s_b_129_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_129_4,emitter.const_u8(16));
    }
    /* execute.simd:3062 [D] s_b_129_5 = (v4s32)s_b_129_4 */
    auto s_b_129_5 = emitter.reinterpret(s_b_129_4, emitter.context().types().v4s32());
    /* execute.simd:3062 [D] s_b_129_6: sym_43406_0_rm = s_b_129_5, dominates: s_b_130_3 s_b_131_0 s_b_133_3 s_b_134_0 s_b_136_3 s_b_137_0 s_b_139_3 s_b_141_3 s_b_138_3 s_b_135_3 s_b_132_3  */
    emitter.store_local(DV_sym_43406_0_rm, s_b_129_5);
    /* ???:4294967295 [F] s_b_129_7 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:3064 [F] s_b_129_8: sym_43411_0_rd = s_b_129_7 (const), dominates: s_b_130_9 s_b_132_8  */
    CV_sym_43411_0_rd = wutils::Vector<uint32_t, 4>(0);
    emitter.store_local(DV_sym_43411_0_rd, emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()));
    /* ???:4294967295 [F] s_b_129_9 = constant u8 0 (const) */
    /* execute.simd:3066 [D] s_b_129_5[s_b_129_9] */
    auto s_b_129_10 = emitter.vector_extract(s_b_129_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3066 [F] s_b_129_11 = constant s32 0 (const) */
    /* execute.simd:3066 [D] s_b_129_12 = s_b_129_10<s_b_129_11 */
    auto s_b_129_12 = emitter.cmp_lt(s_b_129_10, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3066 [D] s_b_129_13: If s_b_129_12: Jump b_130 else b_132 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_130;
        dynamic_block_queue.push(block_b_130);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_132;
        dynamic_block_queue.push(block_b_132);
        false_target = block;
      }
      emitter.branch(s_b_129_12, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_130 not fully fixed
  // BLOCK b_131 not fully fixed
  // BLOCK b_132 not fully fixed
  // BLOCK b_133 not fully fixed
  // BLOCK b_134 not fully fixed
  // BLOCK b_135 not fully fixed
  // BLOCK b_136 not fully fixed
  // BLOCK b_137 not fully fixed
  // BLOCK b_138 not fully fixed
  // BLOCK b_139 not fully fixed
  // BLOCK b_140 not fully fixed
  // BLOCK b_141 not fully fixed
  /* b_3,  */
  fixed_block_b_142: 
  {
    /* execute.simd:3077 [F] s_b_142_0=sym_41396_3_parameter_inst.rn (const) */
    /* execute.simd:3077 [D] s_b_142_1 = ReadRegBank 21:s_b_142_0 (v2u64) */
    auto s_b_142_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_142_1,emitter.const_u8(16));
    }
    /* execute.simd:3077 [D] s_b_142_2: sym_43612_0_rn = s_b_142_1, dominates: s_b_143_0 s_b_146_0 s_b_148_0 s_b_145_0  */
    emitter.store_local(DV_sym_43612_0_rn, s_b_142_1);
    /* execute.simd:3078 [F] s_b_142_3=sym_41396_3_parameter_inst.rm (const) */
    /* execute.simd:3078 [D] s_b_142_4 = ReadRegBank 21:s_b_142_3 (v2u64) */
    auto s_b_142_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_142_4,emitter.const_u8(16));
    }
    /* execute.simd:3078 [D] s_b_142_5 = (v2s64)s_b_142_4 */
    auto s_b_142_5 = emitter.reinterpret(s_b_142_4, emitter.context().types().v2s64());
    /* execute.simd:3078 [D] s_b_142_6: sym_43616_0_rm = s_b_142_5, dominates: s_b_143_3 s_b_144_0 s_b_146_3 s_b_148_3 s_b_145_3  */
    emitter.store_local(DV_sym_43616_0_rm, s_b_142_5);
    /* ???:4294967295 [F] s_b_142_7 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:3080 [F] s_b_142_8: sym_43621_0_rd = s_b_142_7 (const), dominates: s_b_143_9 s_b_145_8  */
    CV_sym_43621_0_rd = wutils::Vector<uint64_t, 2>(0);
    emitter.store_local(DV_sym_43621_0_rd, emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()));
    /* ???:4294967295 [F] s_b_142_9 = constant u8 0 (const) */
    /* execute.simd:3082 [D] s_b_142_5[s_b_142_9] */
    auto s_b_142_10 = emitter.vector_extract(s_b_142_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3082 [F] s_b_142_11 = constant s64 0 (const) */
    /* execute.simd:3082 [D] s_b_142_12 = s_b_142_10<s_b_142_11 */
    auto s_b_142_12 = emitter.cmp_lt(s_b_142_10, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:3082 [D] s_b_142_13: If s_b_142_12: Jump b_143 else b_145 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_143;
        dynamic_block_queue.push(block_b_143);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_145;
        dynamic_block_queue.push(block_b_145);
        false_target = block;
      }
      emitter.branch(s_b_142_12, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_143 not fully fixed
  // BLOCK b_144 not fully fixed
  // BLOCK b_145 not fully fixed
  // BLOCK b_146 not fully fixed
  // BLOCK b_147 not fully fixed
  // BLOCK b_148 not fully fixed
  /* b_3,  */
  fixed_block_b_149: 
  {
    /* execute.simd:3093 [D] s_b_149_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_149_1: Jump b_2 (const) */
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
        /* execute.simd:2970 [F] s_b_4_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:2970 [F] s_b_4_1 = constant u64 0 (const) */
        /* execute.simd:6208 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6209 [F] s_b_4_3 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_4_4: WriteRegBank 3:s_b_4_0 = s_b_4_3 */
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
        /* execute.simd:2971 [D] s_b_5_0 = sym_41410_0_rm int8_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_41410_0_rm, emitter.context().types().s8());
        /* execute.simd:2971 [F] s_b_5_1 = constant s32 0 (const) */
        /* execute.simd:2971 [D] s_b_5_2 = (s32)s_b_5_0 */
        auto s_b_5_2 = emitter.sx(s_b_5_0, emitter.context().types().s32());
        /* execute.simd:2971 [D] s_b_5_3 = s_b_5_2>s_b_5_1 */
        auto s_b_5_3 = emitter.cmp_gt(s_b_5_2, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:2971 [D] s_b_5_4: If s_b_5_3: Jump b_6 else b_7 */
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
          emitter.branch(s_b_5_3, true_target, false_target);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:2972 [F] s_b_6_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:2972 [D] s_b_6_1 = sym_41405_0_rn uint64_t */
        auto s_b_6_1 = emitter.load_local(DV_sym_41405_0_rn, emitter.context().types().u64());
        /* execute.simd:2972 [D] s_b_6_2 = sym_41410_0_rm int8_t */
        auto s_b_6_2 = emitter.load_local(DV_sym_41410_0_rm, emitter.context().types().s8());
        /* execute.simd:2972 [D] s_b_6_3 = (u64)s_b_6_2 */
        auto s_b_6_3 = emitter.zx(s_b_6_2, emitter.context().types().u64());
        /* execute.simd:2972 [D] s_b_6_4 = s_b_6_1<<s_b_6_3 */
        auto s_b_6_4 = emitter.shl(s_b_6_1, s_b_6_3);
        /* execute.simd:6208 [D] s_b_6_5: WriteRegBank 2:s_b_6_0 = s_b_6_4 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
        /* execute.simd:6209 [F] s_b_6_6 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_6_7: WriteRegBank 3:s_b_6_0 = s_b_6_6 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_6_8: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.simd:2973 [D] s_b_7_0 = sym_41410_0_rm int8_t */
        auto s_b_7_0 = emitter.load_local(DV_sym_41410_0_rm, emitter.context().types().s8());
        /* execute.simd:2973 [F] s_b_7_1 = constant u64 ffffffffffffffc1 (const) */
        /* execute.simd:2973 [D] s_b_7_2 = (u64)s_b_7_0 */
        auto s_b_7_2 = emitter.zx(s_b_7_0, emitter.context().types().u64());
        /* execute.simd:2973 [D] s_b_7_3 = s_b_7_2<s_b_7_1 */
        auto s_b_7_3 = emitter.cmp_lt(s_b_7_2, emitter.const_u64((uint64_t)18446744073709551553ULL));
        /* execute.simd:2973 [D] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_8;
            dynamic_block_queue.push(block_b_8);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_9;
            dynamic_block_queue.push(block_b_9);
            false_target = block;
          }
          emitter.branch(s_b_7_3, true_target, false_target);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.simd:2974 [F] s_b_8_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:2974 [F] s_b_8_1 = constant u64 0 (const) */
        /* execute.simd:6208 [F] s_b_8_2: WriteRegBank 2:s_b_8_0 = s_b_8_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6209 [F] s_b_8_3 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_8_4: WriteRegBank 3:s_b_8_0 = s_b_8_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
        /* execute.simd:2976 [F] s_b_9_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:2976 [D] s_b_9_1 = sym_41405_0_rn uint64_t */
        auto s_b_9_1 = emitter.load_local(DV_sym_41405_0_rn, emitter.context().types().u64());
        /* execute.simd:2976 [D] s_b_9_2 = sym_41410_0_rm int8_t */
        auto s_b_9_2 = emitter.load_local(DV_sym_41410_0_rm, emitter.context().types().s8());
        /* execute.simd:2976 [D] s_b_9_3 = -s_b_9_2 */
        auto s_b_9_3 = emitter.neg(s_b_9_2);
        /* execute.simd:2976 [D] s_b_9_4 = (u64)s_b_9_3 */
        auto s_b_9_4 = emitter.zx(s_b_9_3, emitter.context().types().u64());
        /* execute.simd:2976 [D] s_b_9_5 = s_b_9_1>>s_b_9_4 */
        auto s_b_9_5 = emitter.shr(s_b_9_1, s_b_9_4);
        /* execute.simd:6208 [D] s_b_9_6: WriteRegBank 2:s_b_9_0 = s_b_9_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_5,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_5);
        /* execute.simd:6209 [F] s_b_9_7 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_9_8: WriteRegBank 3:s_b_9_0 = s_b_9_7 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:0 [F] s_b_9_9: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* execute.simd:2987 [D] s_b_11_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_11_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_11_1 = constant u8 0 (const) */
        /* execute.simd:2987 [D] s_b_11_0[s_b_11_1] */
        auto s_b_11_2 = emitter.vector_extract(s_b_11_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:2987 [D] s_b_11_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_11_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_11_4 = constant u8 0 (const) */
        /* execute.simd:2987 [D] s_b_11_3[s_b_11_4] */
        auto s_b_11_5 = emitter.vector_extract(s_b_11_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:2987 [D] s_b_11_6 = -s_b_11_5 */
        auto s_b_11_6 = emitter.neg(s_b_11_5);
        /* execute.simd:2987 [D] s_b_11_7 = (u8)s_b_11_6 */
        auto s_b_11_7 = emitter.reinterpret(s_b_11_6, emitter.context().types().u8());
        /* execute.simd:2987 [D] s_b_11_8 = s_b_11_2>>s_b_11_7 */
        auto s_b_11_8 = emitter.shr(s_b_11_2, s_b_11_7);
        /* execute.simd:2987 [F] s_b_11_9 = sym_41479_0_rd (const) wutils::Vector<uint8_t, 16> */
        wutils::Vector<uint8_t, 16> s_b_11_9 = CV_sym_41479_0_rd;
        /* execute.simd:2987 [F] s_b_11_10 = constant s32 0 (const) */
        /* execute.simd:2987 [D] s_b_11_11 = s_b_11_9[s_b_11_10] <= s_b_11_8 */
        auto s_b_11_11 = emitter.vector_insert(emitter.constant_vector_splat(s_b_11_9[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_11_8);
        /* execute.simd:2987 [D] s_b_11_12: sym_41479_0_rd = s_b_11_11, dominates: s_b_14_9 s_b_16_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_11_11);
        /* execute.simd:2987 [F] s_b_11_13: Jump b_12 (const) */
        {
          auto block = block_b_12;
          dynamic_block_queue.push(block_b_12);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.simd:2986 [D] s_b_12_0 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_12_0 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_12_1 = constant u8 1 (const) */
        /* execute.simd:2986 [D] s_b_12_0[s_b_12_1] */
        auto s_b_12_2 = emitter.vector_extract(s_b_12_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:2986 [F] s_b_12_3 = constant s32 0 (const) */
        /* execute.simd:2986 [D] s_b_12_4 = (s32)s_b_12_2 */
        auto s_b_12_4 = emitter.sx(s_b_12_2, emitter.context().types().s32());
        /* execute.simd:2986 [D] s_b_12_5 = s_b_12_4<s_b_12_3 */
        auto s_b_12_5 = emitter.cmp_lt(s_b_12_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:2986 [D] s_b_12_6: If s_b_12_5: Jump b_14 else b_16 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_14;
            dynamic_block_queue.push(block_b_14);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_16;
            dynamic_block_queue.push(block_b_16);
            false_target = block;
          }
          emitter.branch(s_b_12_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.simd:2989 [D] s_b_13_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_13_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_13_1 = constant u8 0 (const) */
        /* execute.simd:2989 [D] s_b_13_0[s_b_13_1] */
        auto s_b_13_2 = emitter.vector_extract(s_b_13_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:2989 [D] s_b_13_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_13_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_13_4 = constant u8 0 (const) */
        /* execute.simd:2989 [D] s_b_13_3[s_b_13_4] */
        auto s_b_13_5 = emitter.vector_extract(s_b_13_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:2989 [D] s_b_13_6 = (u8)s_b_13_5 */
        auto s_b_13_6 = emitter.reinterpret(s_b_13_5, emitter.context().types().u8());
        /* execute.simd:2989 [D] s_b_13_7 = s_b_13_2<<s_b_13_6 */
        auto s_b_13_7 = emitter.shl(s_b_13_2, s_b_13_6);
        /* execute.simd:2989 [F] s_b_13_8 = sym_41479_0_rd (const) wutils::Vector<uint8_t, 16> */
        wutils::Vector<uint8_t, 16> s_b_13_8 = CV_sym_41479_0_rd;
        /* execute.simd:2989 [F] s_b_13_9 = constant s32 0 (const) */
        /* execute.simd:2989 [D] s_b_13_10 = s_b_13_8[s_b_13_9] <= s_b_13_7 */
        auto s_b_13_10 = emitter.vector_insert(emitter.constant_vector_splat(s_b_13_8[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_13_7);
        /* execute.simd:2989 [D] s_b_13_11: sym_41479_0_rd = s_b_13_10, dominates: s_b_14_9 s_b_16_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_13_10);
        /* execute.simd:2989 [F] s_b_13_12: Jump b_12 (const) */
        {
          auto block = block_b_12;
          dynamic_block_queue.push(block_b_12);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.simd:2987 [D] s_b_14_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_14_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_14_1 = constant u8 1 (const) */
        /* execute.simd:2987 [D] s_b_14_0[s_b_14_1] */
        auto s_b_14_2 = emitter.vector_extract(s_b_14_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:2987 [D] s_b_14_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_14_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_14_4 = constant u8 1 (const) */
        /* execute.simd:2987 [D] s_b_14_3[s_b_14_4] */
        auto s_b_14_5 = emitter.vector_extract(s_b_14_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:2987 [D] s_b_14_6 = -s_b_14_5 */
        auto s_b_14_6 = emitter.neg(s_b_14_5);
        /* execute.simd:2987 [D] s_b_14_7 = (u8)s_b_14_6 */
        auto s_b_14_7 = emitter.reinterpret(s_b_14_6, emitter.context().types().u8());
        /* execute.simd:2987 [D] s_b_14_8 = s_b_14_2>>s_b_14_7 */
        auto s_b_14_8 = emitter.shr(s_b_14_2, s_b_14_7);
        /* execute.simd:2987 [D] s_b_14_9 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_14_9 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2987 [F] s_b_14_10 = constant s32 1 (const) */
        /* execute.simd:2987 [D] s_b_14_11 = s_b_14_9[s_b_14_10] <= s_b_14_8 */
        auto s_b_14_11 = emitter.vector_insert(s_b_14_9, emitter.const_s32((int32_t)1ULL), s_b_14_8);
        /* execute.simd:2987 [D] s_b_14_12: sym_41479_0_rd = s_b_14_11, dominates: s_b_17_9 s_b_19_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_14_11);
        /* execute.simd:2987 [F] s_b_14_13: Jump b_15 (const) */
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.simd:2986 [D] s_b_15_0 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_15_0 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_15_1 = constant u8 2 (const) */
        /* execute.simd:2986 [D] s_b_15_0[s_b_15_1] */
        auto s_b_15_2 = emitter.vector_extract(s_b_15_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:2986 [F] s_b_15_3 = constant s32 0 (const) */
        /* execute.simd:2986 [D] s_b_15_4 = (s32)s_b_15_2 */
        auto s_b_15_4 = emitter.sx(s_b_15_2, emitter.context().types().s32());
        /* execute.simd:2986 [D] s_b_15_5 = s_b_15_4<s_b_15_3 */
        auto s_b_15_5 = emitter.cmp_lt(s_b_15_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:2986 [D] s_b_15_6: If s_b_15_5: Jump b_17 else b_19 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_17;
            dynamic_block_queue.push(block_b_17);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_19;
            dynamic_block_queue.push(block_b_19);
            false_target = block;
          }
          emitter.branch(s_b_15_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.simd:2989 [D] s_b_16_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_16_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_16_1 = constant u8 1 (const) */
        /* execute.simd:2989 [D] s_b_16_0[s_b_16_1] */
        auto s_b_16_2 = emitter.vector_extract(s_b_16_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:2989 [D] s_b_16_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_16_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_16_4 = constant u8 1 (const) */
        /* execute.simd:2989 [D] s_b_16_3[s_b_16_4] */
        auto s_b_16_5 = emitter.vector_extract(s_b_16_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:2989 [D] s_b_16_6 = (u8)s_b_16_5 */
        auto s_b_16_6 = emitter.reinterpret(s_b_16_5, emitter.context().types().u8());
        /* execute.simd:2989 [D] s_b_16_7 = s_b_16_2<<s_b_16_6 */
        auto s_b_16_7 = emitter.shl(s_b_16_2, s_b_16_6);
        /* execute.simd:2989 [D] s_b_16_8 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_16_8 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2989 [F] s_b_16_9 = constant s32 1 (const) */
        /* execute.simd:2989 [D] s_b_16_10 = s_b_16_8[s_b_16_9] <= s_b_16_7 */
        auto s_b_16_10 = emitter.vector_insert(s_b_16_8, emitter.const_s32((int32_t)1ULL), s_b_16_7);
        /* execute.simd:2989 [D] s_b_16_11: sym_41479_0_rd = s_b_16_10, dominates: s_b_17_9 s_b_19_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_16_10);
        /* execute.simd:2989 [F] s_b_16_12: Jump b_15 (const) */
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.simd:2987 [D] s_b_17_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_17_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_17_1 = constant u8 2 (const) */
        /* execute.simd:2987 [D] s_b_17_0[s_b_17_1] */
        auto s_b_17_2 = emitter.vector_extract(s_b_17_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:2987 [D] s_b_17_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_17_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_17_4 = constant u8 2 (const) */
        /* execute.simd:2987 [D] s_b_17_3[s_b_17_4] */
        auto s_b_17_5 = emitter.vector_extract(s_b_17_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:2987 [D] s_b_17_6 = -s_b_17_5 */
        auto s_b_17_6 = emitter.neg(s_b_17_5);
        /* execute.simd:2987 [D] s_b_17_7 = (u8)s_b_17_6 */
        auto s_b_17_7 = emitter.reinterpret(s_b_17_6, emitter.context().types().u8());
        /* execute.simd:2987 [D] s_b_17_8 = s_b_17_2>>s_b_17_7 */
        auto s_b_17_8 = emitter.shr(s_b_17_2, s_b_17_7);
        /* execute.simd:2987 [D] s_b_17_9 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_17_9 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2987 [F] s_b_17_10 = constant s32 2 (const) */
        /* execute.simd:2987 [D] s_b_17_11 = s_b_17_9[s_b_17_10] <= s_b_17_8 */
        auto s_b_17_11 = emitter.vector_insert(s_b_17_9, emitter.const_s32((int32_t)2ULL), s_b_17_8);
        /* execute.simd:2987 [D] s_b_17_12: sym_41479_0_rd = s_b_17_11, dominates: s_b_20_9 s_b_22_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_17_11);
        /* execute.simd:2987 [F] s_b_17_13: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.simd:2986 [D] s_b_18_0 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_18_0 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_18_1 = constant u8 3 (const) */
        /* execute.simd:2986 [D] s_b_18_0[s_b_18_1] */
        auto s_b_18_2 = emitter.vector_extract(s_b_18_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:2986 [F] s_b_18_3 = constant s32 0 (const) */
        /* execute.simd:2986 [D] s_b_18_4 = (s32)s_b_18_2 */
        auto s_b_18_4 = emitter.sx(s_b_18_2, emitter.context().types().s32());
        /* execute.simd:2986 [D] s_b_18_5 = s_b_18_4<s_b_18_3 */
        auto s_b_18_5 = emitter.cmp_lt(s_b_18_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:2986 [D] s_b_18_6: If s_b_18_5: Jump b_20 else b_22 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_20;
            dynamic_block_queue.push(block_b_20);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_22;
            dynamic_block_queue.push(block_b_22);
            false_target = block;
          }
          emitter.branch(s_b_18_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.simd:2989 [D] s_b_19_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_19_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_19_1 = constant u8 2 (const) */
        /* execute.simd:2989 [D] s_b_19_0[s_b_19_1] */
        auto s_b_19_2 = emitter.vector_extract(s_b_19_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:2989 [D] s_b_19_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_19_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_19_4 = constant u8 2 (const) */
        /* execute.simd:2989 [D] s_b_19_3[s_b_19_4] */
        auto s_b_19_5 = emitter.vector_extract(s_b_19_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:2989 [D] s_b_19_6 = (u8)s_b_19_5 */
        auto s_b_19_6 = emitter.reinterpret(s_b_19_5, emitter.context().types().u8());
        /* execute.simd:2989 [D] s_b_19_7 = s_b_19_2<<s_b_19_6 */
        auto s_b_19_7 = emitter.shl(s_b_19_2, s_b_19_6);
        /* execute.simd:2989 [D] s_b_19_8 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_19_8 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2989 [F] s_b_19_9 = constant s32 2 (const) */
        /* execute.simd:2989 [D] s_b_19_10 = s_b_19_8[s_b_19_9] <= s_b_19_7 */
        auto s_b_19_10 = emitter.vector_insert(s_b_19_8, emitter.const_s32((int32_t)2ULL), s_b_19_7);
        /* execute.simd:2989 [D] s_b_19_11: sym_41479_0_rd = s_b_19_10, dominates: s_b_20_9 s_b_22_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_19_10);
        /* execute.simd:2989 [F] s_b_19_12: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.simd:2987 [D] s_b_20_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_20_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_20_1 = constant u8 3 (const) */
        /* execute.simd:2987 [D] s_b_20_0[s_b_20_1] */
        auto s_b_20_2 = emitter.vector_extract(s_b_20_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:2987 [D] s_b_20_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_20_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_20_4 = constant u8 3 (const) */
        /* execute.simd:2987 [D] s_b_20_3[s_b_20_4] */
        auto s_b_20_5 = emitter.vector_extract(s_b_20_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:2987 [D] s_b_20_6 = -s_b_20_5 */
        auto s_b_20_6 = emitter.neg(s_b_20_5);
        /* execute.simd:2987 [D] s_b_20_7 = (u8)s_b_20_6 */
        auto s_b_20_7 = emitter.reinterpret(s_b_20_6, emitter.context().types().u8());
        /* execute.simd:2987 [D] s_b_20_8 = s_b_20_2>>s_b_20_7 */
        auto s_b_20_8 = emitter.shr(s_b_20_2, s_b_20_7);
        /* execute.simd:2987 [D] s_b_20_9 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_20_9 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2987 [F] s_b_20_10 = constant s32 3 (const) */
        /* execute.simd:2987 [D] s_b_20_11 = s_b_20_9[s_b_20_10] <= s_b_20_8 */
        auto s_b_20_11 = emitter.vector_insert(s_b_20_9, emitter.const_s32((int32_t)3ULL), s_b_20_8);
        /* execute.simd:2987 [D] s_b_20_12: sym_41479_0_rd = s_b_20_11, dominates: s_b_23_9 s_b_25_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_20_11);
        /* execute.simd:2987 [F] s_b_20_13: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.simd:2986 [D] s_b_21_0 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_21_0 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_21_1 = constant u8 4 (const) */
        /* execute.simd:2986 [D] s_b_21_0[s_b_21_1] */
        auto s_b_21_2 = emitter.vector_extract(s_b_21_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:2986 [F] s_b_21_3 = constant s32 0 (const) */
        /* execute.simd:2986 [D] s_b_21_4 = (s32)s_b_21_2 */
        auto s_b_21_4 = emitter.sx(s_b_21_2, emitter.context().types().s32());
        /* execute.simd:2986 [D] s_b_21_5 = s_b_21_4<s_b_21_3 */
        auto s_b_21_5 = emitter.cmp_lt(s_b_21_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:2986 [D] s_b_21_6: If s_b_21_5: Jump b_23 else b_25 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_23;
            dynamic_block_queue.push(block_b_23);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_25;
            dynamic_block_queue.push(block_b_25);
            false_target = block;
          }
          emitter.branch(s_b_21_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.simd:2989 [D] s_b_22_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_22_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_22_1 = constant u8 3 (const) */
        /* execute.simd:2989 [D] s_b_22_0[s_b_22_1] */
        auto s_b_22_2 = emitter.vector_extract(s_b_22_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:2989 [D] s_b_22_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_22_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_22_4 = constant u8 3 (const) */
        /* execute.simd:2989 [D] s_b_22_3[s_b_22_4] */
        auto s_b_22_5 = emitter.vector_extract(s_b_22_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:2989 [D] s_b_22_6 = (u8)s_b_22_5 */
        auto s_b_22_6 = emitter.reinterpret(s_b_22_5, emitter.context().types().u8());
        /* execute.simd:2989 [D] s_b_22_7 = s_b_22_2<<s_b_22_6 */
        auto s_b_22_7 = emitter.shl(s_b_22_2, s_b_22_6);
        /* execute.simd:2989 [D] s_b_22_8 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_22_8 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2989 [F] s_b_22_9 = constant s32 3 (const) */
        /* execute.simd:2989 [D] s_b_22_10 = s_b_22_8[s_b_22_9] <= s_b_22_7 */
        auto s_b_22_10 = emitter.vector_insert(s_b_22_8, emitter.const_s32((int32_t)3ULL), s_b_22_7);
        /* execute.simd:2989 [D] s_b_22_11: sym_41479_0_rd = s_b_22_10, dominates: s_b_23_9 s_b_25_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_22_10);
        /* execute.simd:2989 [F] s_b_22_12: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.simd:2987 [D] s_b_23_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_23_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_23_1 = constant u8 4 (const) */
        /* execute.simd:2987 [D] s_b_23_0[s_b_23_1] */
        auto s_b_23_2 = emitter.vector_extract(s_b_23_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:2987 [D] s_b_23_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_23_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_23_4 = constant u8 4 (const) */
        /* execute.simd:2987 [D] s_b_23_3[s_b_23_4] */
        auto s_b_23_5 = emitter.vector_extract(s_b_23_3, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:2987 [D] s_b_23_6 = -s_b_23_5 */
        auto s_b_23_6 = emitter.neg(s_b_23_5);
        /* execute.simd:2987 [D] s_b_23_7 = (u8)s_b_23_6 */
        auto s_b_23_7 = emitter.reinterpret(s_b_23_6, emitter.context().types().u8());
        /* execute.simd:2987 [D] s_b_23_8 = s_b_23_2>>s_b_23_7 */
        auto s_b_23_8 = emitter.shr(s_b_23_2, s_b_23_7);
        /* execute.simd:2987 [D] s_b_23_9 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_23_9 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2987 [F] s_b_23_10 = constant s32 4 (const) */
        /* execute.simd:2987 [D] s_b_23_11 = s_b_23_9[s_b_23_10] <= s_b_23_8 */
        auto s_b_23_11 = emitter.vector_insert(s_b_23_9, emitter.const_s32((int32_t)4ULL), s_b_23_8);
        /* execute.simd:2987 [D] s_b_23_12: sym_41479_0_rd = s_b_23_11, dominates: s_b_26_9 s_b_28_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_23_11);
        /* execute.simd:2987 [F] s_b_23_13: Jump b_24 (const) */
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.simd:2986 [D] s_b_24_0 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_24_0 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_24_1 = constant u8 5 (const) */
        /* execute.simd:2986 [D] s_b_24_0[s_b_24_1] */
        auto s_b_24_2 = emitter.vector_extract(s_b_24_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:2986 [F] s_b_24_3 = constant s32 0 (const) */
        /* execute.simd:2986 [D] s_b_24_4 = (s32)s_b_24_2 */
        auto s_b_24_4 = emitter.sx(s_b_24_2, emitter.context().types().s32());
        /* execute.simd:2986 [D] s_b_24_5 = s_b_24_4<s_b_24_3 */
        auto s_b_24_5 = emitter.cmp_lt(s_b_24_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:2986 [D] s_b_24_6: If s_b_24_5: Jump b_26 else b_28 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_26;
            dynamic_block_queue.push(block_b_26);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_28;
            dynamic_block_queue.push(block_b_28);
            false_target = block;
          }
          emitter.branch(s_b_24_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.simd:2989 [D] s_b_25_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_25_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_25_1 = constant u8 4 (const) */
        /* execute.simd:2989 [D] s_b_25_0[s_b_25_1] */
        auto s_b_25_2 = emitter.vector_extract(s_b_25_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:2989 [D] s_b_25_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_25_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_25_4 = constant u8 4 (const) */
        /* execute.simd:2989 [D] s_b_25_3[s_b_25_4] */
        auto s_b_25_5 = emitter.vector_extract(s_b_25_3, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:2989 [D] s_b_25_6 = (u8)s_b_25_5 */
        auto s_b_25_6 = emitter.reinterpret(s_b_25_5, emitter.context().types().u8());
        /* execute.simd:2989 [D] s_b_25_7 = s_b_25_2<<s_b_25_6 */
        auto s_b_25_7 = emitter.shl(s_b_25_2, s_b_25_6);
        /* execute.simd:2989 [D] s_b_25_8 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_25_8 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2989 [F] s_b_25_9 = constant s32 4 (const) */
        /* execute.simd:2989 [D] s_b_25_10 = s_b_25_8[s_b_25_9] <= s_b_25_7 */
        auto s_b_25_10 = emitter.vector_insert(s_b_25_8, emitter.const_s32((int32_t)4ULL), s_b_25_7);
        /* execute.simd:2989 [D] s_b_25_11: sym_41479_0_rd = s_b_25_10, dominates: s_b_26_9 s_b_28_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_25_10);
        /* execute.simd:2989 [F] s_b_25_12: Jump b_24 (const) */
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.simd:2987 [D] s_b_26_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_26_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_26_1 = constant u8 5 (const) */
        /* execute.simd:2987 [D] s_b_26_0[s_b_26_1] */
        auto s_b_26_2 = emitter.vector_extract(s_b_26_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:2987 [D] s_b_26_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_26_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_26_4 = constant u8 5 (const) */
        /* execute.simd:2987 [D] s_b_26_3[s_b_26_4] */
        auto s_b_26_5 = emitter.vector_extract(s_b_26_3, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:2987 [D] s_b_26_6 = -s_b_26_5 */
        auto s_b_26_6 = emitter.neg(s_b_26_5);
        /* execute.simd:2987 [D] s_b_26_7 = (u8)s_b_26_6 */
        auto s_b_26_7 = emitter.reinterpret(s_b_26_6, emitter.context().types().u8());
        /* execute.simd:2987 [D] s_b_26_8 = s_b_26_2>>s_b_26_7 */
        auto s_b_26_8 = emitter.shr(s_b_26_2, s_b_26_7);
        /* execute.simd:2987 [D] s_b_26_9 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_26_9 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2987 [F] s_b_26_10 = constant s32 5 (const) */
        /* execute.simd:2987 [D] s_b_26_11 = s_b_26_9[s_b_26_10] <= s_b_26_8 */
        auto s_b_26_11 = emitter.vector_insert(s_b_26_9, emitter.const_s32((int32_t)5ULL), s_b_26_8);
        /* execute.simd:2987 [D] s_b_26_12: sym_41479_0_rd = s_b_26_11, dominates: s_b_29_9 s_b_31_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_26_11);
        /* execute.simd:2987 [F] s_b_26_13: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.simd:2986 [D] s_b_27_0 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_27_0 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_27_1 = constant u8 6 (const) */
        /* execute.simd:2986 [D] s_b_27_0[s_b_27_1] */
        auto s_b_27_2 = emitter.vector_extract(s_b_27_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:2986 [F] s_b_27_3 = constant s32 0 (const) */
        /* execute.simd:2986 [D] s_b_27_4 = (s32)s_b_27_2 */
        auto s_b_27_4 = emitter.sx(s_b_27_2, emitter.context().types().s32());
        /* execute.simd:2986 [D] s_b_27_5 = s_b_27_4<s_b_27_3 */
        auto s_b_27_5 = emitter.cmp_lt(s_b_27_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:2986 [D] s_b_27_6: If s_b_27_5: Jump b_29 else b_31 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_29;
            dynamic_block_queue.push(block_b_29);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_31;
            dynamic_block_queue.push(block_b_31);
            false_target = block;
          }
          emitter.branch(s_b_27_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.simd:2989 [D] s_b_28_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_28_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_28_1 = constant u8 5 (const) */
        /* execute.simd:2989 [D] s_b_28_0[s_b_28_1] */
        auto s_b_28_2 = emitter.vector_extract(s_b_28_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:2989 [D] s_b_28_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_28_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_28_4 = constant u8 5 (const) */
        /* execute.simd:2989 [D] s_b_28_3[s_b_28_4] */
        auto s_b_28_5 = emitter.vector_extract(s_b_28_3, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:2989 [D] s_b_28_6 = (u8)s_b_28_5 */
        auto s_b_28_6 = emitter.reinterpret(s_b_28_5, emitter.context().types().u8());
        /* execute.simd:2989 [D] s_b_28_7 = s_b_28_2<<s_b_28_6 */
        auto s_b_28_7 = emitter.shl(s_b_28_2, s_b_28_6);
        /* execute.simd:2989 [D] s_b_28_8 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_28_8 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2989 [F] s_b_28_9 = constant s32 5 (const) */
        /* execute.simd:2989 [D] s_b_28_10 = s_b_28_8[s_b_28_9] <= s_b_28_7 */
        auto s_b_28_10 = emitter.vector_insert(s_b_28_8, emitter.const_s32((int32_t)5ULL), s_b_28_7);
        /* execute.simd:2989 [D] s_b_28_11: sym_41479_0_rd = s_b_28_10, dominates: s_b_29_9 s_b_31_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_28_10);
        /* execute.simd:2989 [F] s_b_28_12: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.simd:2987 [D] s_b_29_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_29_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_29_1 = constant u8 6 (const) */
        /* execute.simd:2987 [D] s_b_29_0[s_b_29_1] */
        auto s_b_29_2 = emitter.vector_extract(s_b_29_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:2987 [D] s_b_29_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_29_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_29_4 = constant u8 6 (const) */
        /* execute.simd:2987 [D] s_b_29_3[s_b_29_4] */
        auto s_b_29_5 = emitter.vector_extract(s_b_29_3, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:2987 [D] s_b_29_6 = -s_b_29_5 */
        auto s_b_29_6 = emitter.neg(s_b_29_5);
        /* execute.simd:2987 [D] s_b_29_7 = (u8)s_b_29_6 */
        auto s_b_29_7 = emitter.reinterpret(s_b_29_6, emitter.context().types().u8());
        /* execute.simd:2987 [D] s_b_29_8 = s_b_29_2>>s_b_29_7 */
        auto s_b_29_8 = emitter.shr(s_b_29_2, s_b_29_7);
        /* execute.simd:2987 [D] s_b_29_9 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_29_9 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2987 [F] s_b_29_10 = constant s32 6 (const) */
        /* execute.simd:2987 [D] s_b_29_11 = s_b_29_9[s_b_29_10] <= s_b_29_8 */
        auto s_b_29_11 = emitter.vector_insert(s_b_29_9, emitter.const_s32((int32_t)6ULL), s_b_29_8);
        /* execute.simd:2987 [D] s_b_29_12: sym_41479_0_rd = s_b_29_11, dominates: s_b_32_9 s_b_34_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_29_11);
        /* execute.simd:2987 [F] s_b_29_13: Jump b_30 (const) */
        {
          auto block = block_b_30;
          dynamic_block_queue.push(block_b_30);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.simd:2986 [D] s_b_30_0 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_30_0 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_30_1 = constant u8 7 (const) */
        /* execute.simd:2986 [D] s_b_30_0[s_b_30_1] */
        auto s_b_30_2 = emitter.vector_extract(s_b_30_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:2986 [F] s_b_30_3 = constant s32 0 (const) */
        /* execute.simd:2986 [D] s_b_30_4 = (s32)s_b_30_2 */
        auto s_b_30_4 = emitter.sx(s_b_30_2, emitter.context().types().s32());
        /* execute.simd:2986 [D] s_b_30_5 = s_b_30_4<s_b_30_3 */
        auto s_b_30_5 = emitter.cmp_lt(s_b_30_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:2986 [D] s_b_30_6: If s_b_30_5: Jump b_32 else b_34 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_32;
            dynamic_block_queue.push(block_b_32);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_34;
            dynamic_block_queue.push(block_b_34);
            false_target = block;
          }
          emitter.branch(s_b_30_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.simd:2989 [D] s_b_31_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_31_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_31_1 = constant u8 6 (const) */
        /* execute.simd:2989 [D] s_b_31_0[s_b_31_1] */
        auto s_b_31_2 = emitter.vector_extract(s_b_31_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:2989 [D] s_b_31_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_31_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_31_4 = constant u8 6 (const) */
        /* execute.simd:2989 [D] s_b_31_3[s_b_31_4] */
        auto s_b_31_5 = emitter.vector_extract(s_b_31_3, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:2989 [D] s_b_31_6 = (u8)s_b_31_5 */
        auto s_b_31_6 = emitter.reinterpret(s_b_31_5, emitter.context().types().u8());
        /* execute.simd:2989 [D] s_b_31_7 = s_b_31_2<<s_b_31_6 */
        auto s_b_31_7 = emitter.shl(s_b_31_2, s_b_31_6);
        /* execute.simd:2989 [D] s_b_31_8 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_31_8 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2989 [F] s_b_31_9 = constant s32 6 (const) */
        /* execute.simd:2989 [D] s_b_31_10 = s_b_31_8[s_b_31_9] <= s_b_31_7 */
        auto s_b_31_10 = emitter.vector_insert(s_b_31_8, emitter.const_s32((int32_t)6ULL), s_b_31_7);
        /* execute.simd:2989 [D] s_b_31_11: sym_41479_0_rd = s_b_31_10, dominates: s_b_32_9 s_b_34_8  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_31_10);
        /* execute.simd:2989 [F] s_b_31_12: Jump b_30 (const) */
        {
          auto block = block_b_30;
          dynamic_block_queue.push(block_b_30);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.simd:2987 [D] s_b_32_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_32_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_32_1 = constant u8 7 (const) */
        /* execute.simd:2987 [D] s_b_32_0[s_b_32_1] */
        auto s_b_32_2 = emitter.vector_extract(s_b_32_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:2987 [D] s_b_32_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_32_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_32_4 = constant u8 7 (const) */
        /* execute.simd:2987 [D] s_b_32_3[s_b_32_4] */
        auto s_b_32_5 = emitter.vector_extract(s_b_32_3, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:2987 [D] s_b_32_6 = -s_b_32_5 */
        auto s_b_32_6 = emitter.neg(s_b_32_5);
        /* execute.simd:2987 [D] s_b_32_7 = (u8)s_b_32_6 */
        auto s_b_32_7 = emitter.reinterpret(s_b_32_6, emitter.context().types().u8());
        /* execute.simd:2987 [D] s_b_32_8 = s_b_32_2>>s_b_32_7 */
        auto s_b_32_8 = emitter.shr(s_b_32_2, s_b_32_7);
        /* execute.simd:2987 [D] s_b_32_9 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_32_9 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2987 [F] s_b_32_10 = constant s32 7 (const) */
        /* execute.simd:2987 [D] s_b_32_11 = s_b_32_9[s_b_32_10] <= s_b_32_8 */
        auto s_b_32_11 = emitter.vector_insert(s_b_32_9, emitter.const_s32((int32_t)7ULL), s_b_32_8);
        /* execute.simd:2987 [D] s_b_32_12: sym_41479_0_rd = s_b_32_11, dominates: s_b_33_1  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_32_11);
        /* execute.simd:2987 [F] s_b_32_13: Jump b_33 (const) */
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.simd:2993 [F] s_b_33_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:2993 [D] s_b_33_1 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_33_1 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2993 [D] s_b_33_2: WriteRegBank 16:s_b_33_0 = s_b_33_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_33_1,emitter.const_u8(16));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_33_1);
        /* execute.simd:0 [F] s_b_33_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.simd:2989 [D] s_b_34_0 = sym_41470_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_34_0 = emitter.load_local(DV_sym_41470_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_34_1 = constant u8 7 (const) */
        /* execute.simd:2989 [D] s_b_34_0[s_b_34_1] */
        auto s_b_34_2 = emitter.vector_extract(s_b_34_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:2989 [D] s_b_34_3 = sym_41474_0_rm wutils::Vector<int8_t, 8> */
        auto s_b_34_3 = emitter.load_local(DV_sym_41474_0_rm, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_34_4 = constant u8 7 (const) */
        /* execute.simd:2989 [D] s_b_34_3[s_b_34_4] */
        auto s_b_34_5 = emitter.vector_extract(s_b_34_3, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:2989 [D] s_b_34_6 = (u8)s_b_34_5 */
        auto s_b_34_6 = emitter.reinterpret(s_b_34_5, emitter.context().types().u8());
        /* execute.simd:2989 [D] s_b_34_7 = s_b_34_2<<s_b_34_6 */
        auto s_b_34_7 = emitter.shl(s_b_34_2, s_b_34_6);
        /* execute.simd:2989 [D] s_b_34_8 = sym_41479_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_34_8 = emitter.load_local(DV_sym_41479_0_rd, emitter.context().types().v16u8());
        /* execute.simd:2989 [F] s_b_34_9 = constant s32 7 (const) */
        /* execute.simd:2989 [D] s_b_34_10 = s_b_34_8[s_b_34_9] <= s_b_34_7 */
        auto s_b_34_10 = emitter.vector_insert(s_b_34_8, emitter.const_s32((int32_t)7ULL), s_b_34_7);
        /* execute.simd:2989 [D] s_b_34_11: sym_41479_0_rd = s_b_34_10, dominates: s_b_33_1  */
        emitter.store_local(DV_sym_41479_0_rd, s_b_34_10);
        /* execute.simd:2989 [F] s_b_34_12: Jump b_33 (const) */
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_36) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_36);
        /* execute.simd:3003 [D] s_b_36_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_36_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_36_1 = constant u8 0 (const) */
        /* execute.simd:3003 [D] s_b_36_0[s_b_36_1] */
        auto s_b_36_2 = emitter.vector_extract(s_b_36_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3003 [D] s_b_36_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_36_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_36_4 = constant u8 0 (const) */
        /* execute.simd:3003 [D] s_b_36_3[s_b_36_4] */
        auto s_b_36_5 = emitter.vector_extract(s_b_36_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3003 [D] s_b_36_6 = -s_b_36_5 */
        auto s_b_36_6 = emitter.neg(s_b_36_5);
        /* execute.simd:3003 [D] s_b_36_7 = (u8)s_b_36_6 */
        auto s_b_36_7 = emitter.reinterpret(s_b_36_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_36_8 = s_b_36_2>>s_b_36_7 */
        auto s_b_36_8 = emitter.shr(s_b_36_2, s_b_36_7);
        /* execute.simd:3003 [F] s_b_36_9 = sym_41885_0_rd (const) wutils::Vector<uint8_t, 16> */
        wutils::Vector<uint8_t, 16> s_b_36_9 = CV_sym_41885_0_rd;
        /* execute.simd:3003 [F] s_b_36_10 = constant s32 0 (const) */
        /* execute.simd:3003 [D] s_b_36_11 = s_b_36_9[s_b_36_10] <= s_b_36_8 */
        auto s_b_36_11 = emitter.vector_insert(emitter.constant_vector_splat(s_b_36_9[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_36_8);
        /* execute.simd:3003 [D] s_b_36_12: sym_41885_0_rd = s_b_36_11, dominates: s_b_39_9 s_b_41_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_36_11);
        /* execute.simd:3003 [F] s_b_36_13: Jump b_37 (const) */
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.simd:3002 [D] s_b_37_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_37_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_37_1 = constant u8 1 (const) */
        /* execute.simd:3002 [D] s_b_37_0[s_b_37_1] */
        auto s_b_37_2 = emitter.vector_extract(s_b_37_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3002 [F] s_b_37_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_37_4 = (s32)s_b_37_2 */
        auto s_b_37_4 = emitter.sx(s_b_37_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_37_5 = s_b_37_4<s_b_37_3 */
        auto s_b_37_5 = emitter.cmp_lt(s_b_37_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_37_6: If s_b_37_5: Jump b_39 else b_41 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_39;
            dynamic_block_queue.push(block_b_39);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_41;
            dynamic_block_queue.push(block_b_41);
            false_target = block;
          }
          emitter.branch(s_b_37_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_38) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_38);
        /* execute.simd:3005 [D] s_b_38_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_38_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_38_1 = constant u8 0 (const) */
        /* execute.simd:3005 [D] s_b_38_0[s_b_38_1] */
        auto s_b_38_2 = emitter.vector_extract(s_b_38_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3005 [D] s_b_38_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_38_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_38_4 = constant u8 0 (const) */
        /* execute.simd:3005 [D] s_b_38_3[s_b_38_4] */
        auto s_b_38_5 = emitter.vector_extract(s_b_38_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3005 [D] s_b_38_6 = (u8)s_b_38_5 */
        auto s_b_38_6 = emitter.reinterpret(s_b_38_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_38_7 = s_b_38_2<<s_b_38_6 */
        auto s_b_38_7 = emitter.shl(s_b_38_2, s_b_38_6);
        /* execute.simd:3005 [F] s_b_38_8 = sym_41885_0_rd (const) wutils::Vector<uint8_t, 16> */
        wutils::Vector<uint8_t, 16> s_b_38_8 = CV_sym_41885_0_rd;
        /* execute.simd:3005 [F] s_b_38_9 = constant s32 0 (const) */
        /* execute.simd:3005 [D] s_b_38_10 = s_b_38_8[s_b_38_9] <= s_b_38_7 */
        auto s_b_38_10 = emitter.vector_insert(emitter.constant_vector_splat(s_b_38_8[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_38_7);
        /* execute.simd:3005 [D] s_b_38_11: sym_41885_0_rd = s_b_38_10, dominates: s_b_39_9 s_b_41_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_38_10);
        /* execute.simd:3005 [F] s_b_38_12: Jump b_37 (const) */
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.simd:3003 [D] s_b_39_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_39_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_39_1 = constant u8 1 (const) */
        /* execute.simd:3003 [D] s_b_39_0[s_b_39_1] */
        auto s_b_39_2 = emitter.vector_extract(s_b_39_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3003 [D] s_b_39_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_39_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_39_4 = constant u8 1 (const) */
        /* execute.simd:3003 [D] s_b_39_3[s_b_39_4] */
        auto s_b_39_5 = emitter.vector_extract(s_b_39_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3003 [D] s_b_39_6 = -s_b_39_5 */
        auto s_b_39_6 = emitter.neg(s_b_39_5);
        /* execute.simd:3003 [D] s_b_39_7 = (u8)s_b_39_6 */
        auto s_b_39_7 = emitter.reinterpret(s_b_39_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_39_8 = s_b_39_2>>s_b_39_7 */
        auto s_b_39_8 = emitter.shr(s_b_39_2, s_b_39_7);
        /* execute.simd:3003 [D] s_b_39_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_39_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_39_10 = constant s32 1 (const) */
        /* execute.simd:3003 [D] s_b_39_11 = s_b_39_9[s_b_39_10] <= s_b_39_8 */
        auto s_b_39_11 = emitter.vector_insert(s_b_39_9, emitter.const_s32((int32_t)1ULL), s_b_39_8);
        /* execute.simd:3003 [D] s_b_39_12: sym_41885_0_rd = s_b_39_11, dominates: s_b_42_9 s_b_44_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_39_11);
        /* execute.simd:3003 [F] s_b_39_13: Jump b_40 (const) */
        {
          auto block = block_b_40;
          dynamic_block_queue.push(block_b_40);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_40) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_40);
        /* execute.simd:3002 [D] s_b_40_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_40_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_40_1 = constant u8 2 (const) */
        /* execute.simd:3002 [D] s_b_40_0[s_b_40_1] */
        auto s_b_40_2 = emitter.vector_extract(s_b_40_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3002 [F] s_b_40_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_40_4 = (s32)s_b_40_2 */
        auto s_b_40_4 = emitter.sx(s_b_40_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_40_5 = s_b_40_4<s_b_40_3 */
        auto s_b_40_5 = emitter.cmp_lt(s_b_40_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_40_6: If s_b_40_5: Jump b_42 else b_44 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_42;
            dynamic_block_queue.push(block_b_42);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_44;
            dynamic_block_queue.push(block_b_44);
            false_target = block;
          }
          emitter.branch(s_b_40_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.simd:3005 [D] s_b_41_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_41_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_41_1 = constant u8 1 (const) */
        /* execute.simd:3005 [D] s_b_41_0[s_b_41_1] */
        auto s_b_41_2 = emitter.vector_extract(s_b_41_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3005 [D] s_b_41_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_41_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_41_4 = constant u8 1 (const) */
        /* execute.simd:3005 [D] s_b_41_3[s_b_41_4] */
        auto s_b_41_5 = emitter.vector_extract(s_b_41_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3005 [D] s_b_41_6 = (u8)s_b_41_5 */
        auto s_b_41_6 = emitter.reinterpret(s_b_41_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_41_7 = s_b_41_2<<s_b_41_6 */
        auto s_b_41_7 = emitter.shl(s_b_41_2, s_b_41_6);
        /* execute.simd:3005 [D] s_b_41_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_41_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_41_9 = constant s32 1 (const) */
        /* execute.simd:3005 [D] s_b_41_10 = s_b_41_8[s_b_41_9] <= s_b_41_7 */
        auto s_b_41_10 = emitter.vector_insert(s_b_41_8, emitter.const_s32((int32_t)1ULL), s_b_41_7);
        /* execute.simd:3005 [D] s_b_41_11: sym_41885_0_rd = s_b_41_10, dominates: s_b_42_9 s_b_44_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_41_10);
        /* execute.simd:3005 [F] s_b_41_12: Jump b_40 (const) */
        {
          auto block = block_b_40;
          dynamic_block_queue.push(block_b_40);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_42) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_42);
        /* execute.simd:3003 [D] s_b_42_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_42_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_42_1 = constant u8 2 (const) */
        /* execute.simd:3003 [D] s_b_42_0[s_b_42_1] */
        auto s_b_42_2 = emitter.vector_extract(s_b_42_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3003 [D] s_b_42_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_42_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_42_4 = constant u8 2 (const) */
        /* execute.simd:3003 [D] s_b_42_3[s_b_42_4] */
        auto s_b_42_5 = emitter.vector_extract(s_b_42_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3003 [D] s_b_42_6 = -s_b_42_5 */
        auto s_b_42_6 = emitter.neg(s_b_42_5);
        /* execute.simd:3003 [D] s_b_42_7 = (u8)s_b_42_6 */
        auto s_b_42_7 = emitter.reinterpret(s_b_42_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_42_8 = s_b_42_2>>s_b_42_7 */
        auto s_b_42_8 = emitter.shr(s_b_42_2, s_b_42_7);
        /* execute.simd:3003 [D] s_b_42_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_42_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_42_10 = constant s32 2 (const) */
        /* execute.simd:3003 [D] s_b_42_11 = s_b_42_9[s_b_42_10] <= s_b_42_8 */
        auto s_b_42_11 = emitter.vector_insert(s_b_42_9, emitter.const_s32((int32_t)2ULL), s_b_42_8);
        /* execute.simd:3003 [D] s_b_42_12: sym_41885_0_rd = s_b_42_11, dominates: s_b_45_9 s_b_47_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_42_11);
        /* execute.simd:3003 [F] s_b_42_13: Jump b_43 (const) */
        {
          auto block = block_b_43;
          dynamic_block_queue.push(block_b_43);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_43) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_43);
        /* execute.simd:3002 [D] s_b_43_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_43_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_43_1 = constant u8 3 (const) */
        /* execute.simd:3002 [D] s_b_43_0[s_b_43_1] */
        auto s_b_43_2 = emitter.vector_extract(s_b_43_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3002 [F] s_b_43_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_43_4 = (s32)s_b_43_2 */
        auto s_b_43_4 = emitter.sx(s_b_43_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_43_5 = s_b_43_4<s_b_43_3 */
        auto s_b_43_5 = emitter.cmp_lt(s_b_43_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_43_6: If s_b_43_5: Jump b_45 else b_47 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_45;
            dynamic_block_queue.push(block_b_45);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_47;
            dynamic_block_queue.push(block_b_47);
            false_target = block;
          }
          emitter.branch(s_b_43_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_44) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_44);
        /* execute.simd:3005 [D] s_b_44_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_44_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_44_1 = constant u8 2 (const) */
        /* execute.simd:3005 [D] s_b_44_0[s_b_44_1] */
        auto s_b_44_2 = emitter.vector_extract(s_b_44_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3005 [D] s_b_44_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_44_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_44_4 = constant u8 2 (const) */
        /* execute.simd:3005 [D] s_b_44_3[s_b_44_4] */
        auto s_b_44_5 = emitter.vector_extract(s_b_44_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3005 [D] s_b_44_6 = (u8)s_b_44_5 */
        auto s_b_44_6 = emitter.reinterpret(s_b_44_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_44_7 = s_b_44_2<<s_b_44_6 */
        auto s_b_44_7 = emitter.shl(s_b_44_2, s_b_44_6);
        /* execute.simd:3005 [D] s_b_44_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_44_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_44_9 = constant s32 2 (const) */
        /* execute.simd:3005 [D] s_b_44_10 = s_b_44_8[s_b_44_9] <= s_b_44_7 */
        auto s_b_44_10 = emitter.vector_insert(s_b_44_8, emitter.const_s32((int32_t)2ULL), s_b_44_7);
        /* execute.simd:3005 [D] s_b_44_11: sym_41885_0_rd = s_b_44_10, dominates: s_b_45_9 s_b_47_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_44_10);
        /* execute.simd:3005 [F] s_b_44_12: Jump b_43 (const) */
        {
          auto block = block_b_43;
          dynamic_block_queue.push(block_b_43);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_45) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_45);
        /* execute.simd:3003 [D] s_b_45_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_45_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_45_1 = constant u8 3 (const) */
        /* execute.simd:3003 [D] s_b_45_0[s_b_45_1] */
        auto s_b_45_2 = emitter.vector_extract(s_b_45_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3003 [D] s_b_45_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_45_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_45_4 = constant u8 3 (const) */
        /* execute.simd:3003 [D] s_b_45_3[s_b_45_4] */
        auto s_b_45_5 = emitter.vector_extract(s_b_45_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3003 [D] s_b_45_6 = -s_b_45_5 */
        auto s_b_45_6 = emitter.neg(s_b_45_5);
        /* execute.simd:3003 [D] s_b_45_7 = (u8)s_b_45_6 */
        auto s_b_45_7 = emitter.reinterpret(s_b_45_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_45_8 = s_b_45_2>>s_b_45_7 */
        auto s_b_45_8 = emitter.shr(s_b_45_2, s_b_45_7);
        /* execute.simd:3003 [D] s_b_45_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_45_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_45_10 = constant s32 3 (const) */
        /* execute.simd:3003 [D] s_b_45_11 = s_b_45_9[s_b_45_10] <= s_b_45_8 */
        auto s_b_45_11 = emitter.vector_insert(s_b_45_9, emitter.const_s32((int32_t)3ULL), s_b_45_8);
        /* execute.simd:3003 [D] s_b_45_12: sym_41885_0_rd = s_b_45_11, dominates: s_b_48_9 s_b_50_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_45_11);
        /* execute.simd:3003 [F] s_b_45_13: Jump b_46 (const) */
        {
          auto block = block_b_46;
          dynamic_block_queue.push(block_b_46);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_46) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_46);
        /* execute.simd:3002 [D] s_b_46_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_46_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_46_1 = constant u8 4 (const) */
        /* execute.simd:3002 [D] s_b_46_0[s_b_46_1] */
        auto s_b_46_2 = emitter.vector_extract(s_b_46_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3002 [F] s_b_46_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_46_4 = (s32)s_b_46_2 */
        auto s_b_46_4 = emitter.sx(s_b_46_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_46_5 = s_b_46_4<s_b_46_3 */
        auto s_b_46_5 = emitter.cmp_lt(s_b_46_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_46_6: If s_b_46_5: Jump b_48 else b_50 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_48;
            dynamic_block_queue.push(block_b_48);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_50;
            dynamic_block_queue.push(block_b_50);
            false_target = block;
          }
          emitter.branch(s_b_46_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_47) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_47);
        /* execute.simd:3005 [D] s_b_47_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_47_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_47_1 = constant u8 3 (const) */
        /* execute.simd:3005 [D] s_b_47_0[s_b_47_1] */
        auto s_b_47_2 = emitter.vector_extract(s_b_47_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3005 [D] s_b_47_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_47_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_47_4 = constant u8 3 (const) */
        /* execute.simd:3005 [D] s_b_47_3[s_b_47_4] */
        auto s_b_47_5 = emitter.vector_extract(s_b_47_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3005 [D] s_b_47_6 = (u8)s_b_47_5 */
        auto s_b_47_6 = emitter.reinterpret(s_b_47_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_47_7 = s_b_47_2<<s_b_47_6 */
        auto s_b_47_7 = emitter.shl(s_b_47_2, s_b_47_6);
        /* execute.simd:3005 [D] s_b_47_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_47_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_47_9 = constant s32 3 (const) */
        /* execute.simd:3005 [D] s_b_47_10 = s_b_47_8[s_b_47_9] <= s_b_47_7 */
        auto s_b_47_10 = emitter.vector_insert(s_b_47_8, emitter.const_s32((int32_t)3ULL), s_b_47_7);
        /* execute.simd:3005 [D] s_b_47_11: sym_41885_0_rd = s_b_47_10, dominates: s_b_48_9 s_b_50_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_47_10);
        /* execute.simd:3005 [F] s_b_47_12: Jump b_46 (const) */
        {
          auto block = block_b_46;
          dynamic_block_queue.push(block_b_46);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_48) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_48);
        /* execute.simd:3003 [D] s_b_48_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_48_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_48_1 = constant u8 4 (const) */
        /* execute.simd:3003 [D] s_b_48_0[s_b_48_1] */
        auto s_b_48_2 = emitter.vector_extract(s_b_48_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3003 [D] s_b_48_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_48_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_48_4 = constant u8 4 (const) */
        /* execute.simd:3003 [D] s_b_48_3[s_b_48_4] */
        auto s_b_48_5 = emitter.vector_extract(s_b_48_3, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3003 [D] s_b_48_6 = -s_b_48_5 */
        auto s_b_48_6 = emitter.neg(s_b_48_5);
        /* execute.simd:3003 [D] s_b_48_7 = (u8)s_b_48_6 */
        auto s_b_48_7 = emitter.reinterpret(s_b_48_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_48_8 = s_b_48_2>>s_b_48_7 */
        auto s_b_48_8 = emitter.shr(s_b_48_2, s_b_48_7);
        /* execute.simd:3003 [D] s_b_48_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_48_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_48_10 = constant s32 4 (const) */
        /* execute.simd:3003 [D] s_b_48_11 = s_b_48_9[s_b_48_10] <= s_b_48_8 */
        auto s_b_48_11 = emitter.vector_insert(s_b_48_9, emitter.const_s32((int32_t)4ULL), s_b_48_8);
        /* execute.simd:3003 [D] s_b_48_12: sym_41885_0_rd = s_b_48_11, dominates: s_b_51_9 s_b_53_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_48_11);
        /* execute.simd:3003 [F] s_b_48_13: Jump b_49 (const) */
        {
          auto block = block_b_49;
          dynamic_block_queue.push(block_b_49);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_49) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_49);
        /* execute.simd:3002 [D] s_b_49_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_49_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_49_1 = constant u8 5 (const) */
        /* execute.simd:3002 [D] s_b_49_0[s_b_49_1] */
        auto s_b_49_2 = emitter.vector_extract(s_b_49_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3002 [F] s_b_49_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_49_4 = (s32)s_b_49_2 */
        auto s_b_49_4 = emitter.sx(s_b_49_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_49_5 = s_b_49_4<s_b_49_3 */
        auto s_b_49_5 = emitter.cmp_lt(s_b_49_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_49_6: If s_b_49_5: Jump b_51 else b_53 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_51;
            dynamic_block_queue.push(block_b_51);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_53;
            dynamic_block_queue.push(block_b_53);
            false_target = block;
          }
          emitter.branch(s_b_49_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_50) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_50);
        /* execute.simd:3005 [D] s_b_50_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_50_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_50_1 = constant u8 4 (const) */
        /* execute.simd:3005 [D] s_b_50_0[s_b_50_1] */
        auto s_b_50_2 = emitter.vector_extract(s_b_50_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3005 [D] s_b_50_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_50_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_50_4 = constant u8 4 (const) */
        /* execute.simd:3005 [D] s_b_50_3[s_b_50_4] */
        auto s_b_50_5 = emitter.vector_extract(s_b_50_3, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3005 [D] s_b_50_6 = (u8)s_b_50_5 */
        auto s_b_50_6 = emitter.reinterpret(s_b_50_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_50_7 = s_b_50_2<<s_b_50_6 */
        auto s_b_50_7 = emitter.shl(s_b_50_2, s_b_50_6);
        /* execute.simd:3005 [D] s_b_50_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_50_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_50_9 = constant s32 4 (const) */
        /* execute.simd:3005 [D] s_b_50_10 = s_b_50_8[s_b_50_9] <= s_b_50_7 */
        auto s_b_50_10 = emitter.vector_insert(s_b_50_8, emitter.const_s32((int32_t)4ULL), s_b_50_7);
        /* execute.simd:3005 [D] s_b_50_11: sym_41885_0_rd = s_b_50_10, dominates: s_b_51_9 s_b_53_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_50_10);
        /* execute.simd:3005 [F] s_b_50_12: Jump b_49 (const) */
        {
          auto block = block_b_49;
          dynamic_block_queue.push(block_b_49);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_51) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_51);
        /* execute.simd:3003 [D] s_b_51_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_51_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_51_1 = constant u8 5 (const) */
        /* execute.simd:3003 [D] s_b_51_0[s_b_51_1] */
        auto s_b_51_2 = emitter.vector_extract(s_b_51_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3003 [D] s_b_51_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_51_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_51_4 = constant u8 5 (const) */
        /* execute.simd:3003 [D] s_b_51_3[s_b_51_4] */
        auto s_b_51_5 = emitter.vector_extract(s_b_51_3, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3003 [D] s_b_51_6 = -s_b_51_5 */
        auto s_b_51_6 = emitter.neg(s_b_51_5);
        /* execute.simd:3003 [D] s_b_51_7 = (u8)s_b_51_6 */
        auto s_b_51_7 = emitter.reinterpret(s_b_51_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_51_8 = s_b_51_2>>s_b_51_7 */
        auto s_b_51_8 = emitter.shr(s_b_51_2, s_b_51_7);
        /* execute.simd:3003 [D] s_b_51_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_51_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_51_10 = constant s32 5 (const) */
        /* execute.simd:3003 [D] s_b_51_11 = s_b_51_9[s_b_51_10] <= s_b_51_8 */
        auto s_b_51_11 = emitter.vector_insert(s_b_51_9, emitter.const_s32((int32_t)5ULL), s_b_51_8);
        /* execute.simd:3003 [D] s_b_51_12: sym_41885_0_rd = s_b_51_11, dominates: s_b_54_9 s_b_56_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_51_11);
        /* execute.simd:3003 [F] s_b_51_13: Jump b_52 (const) */
        {
          auto block = block_b_52;
          dynamic_block_queue.push(block_b_52);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_52) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_52);
        /* execute.simd:3002 [D] s_b_52_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_52_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_52_1 = constant u8 6 (const) */
        /* execute.simd:3002 [D] s_b_52_0[s_b_52_1] */
        auto s_b_52_2 = emitter.vector_extract(s_b_52_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3002 [F] s_b_52_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_52_4 = (s32)s_b_52_2 */
        auto s_b_52_4 = emitter.sx(s_b_52_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_52_5 = s_b_52_4<s_b_52_3 */
        auto s_b_52_5 = emitter.cmp_lt(s_b_52_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_52_6: If s_b_52_5: Jump b_54 else b_56 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_54;
            dynamic_block_queue.push(block_b_54);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_56;
            dynamic_block_queue.push(block_b_56);
            false_target = block;
          }
          emitter.branch(s_b_52_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_53) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_53);
        /* execute.simd:3005 [D] s_b_53_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_53_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_53_1 = constant u8 5 (const) */
        /* execute.simd:3005 [D] s_b_53_0[s_b_53_1] */
        auto s_b_53_2 = emitter.vector_extract(s_b_53_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3005 [D] s_b_53_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_53_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_53_4 = constant u8 5 (const) */
        /* execute.simd:3005 [D] s_b_53_3[s_b_53_4] */
        auto s_b_53_5 = emitter.vector_extract(s_b_53_3, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3005 [D] s_b_53_6 = (u8)s_b_53_5 */
        auto s_b_53_6 = emitter.reinterpret(s_b_53_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_53_7 = s_b_53_2<<s_b_53_6 */
        auto s_b_53_7 = emitter.shl(s_b_53_2, s_b_53_6);
        /* execute.simd:3005 [D] s_b_53_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_53_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_53_9 = constant s32 5 (const) */
        /* execute.simd:3005 [D] s_b_53_10 = s_b_53_8[s_b_53_9] <= s_b_53_7 */
        auto s_b_53_10 = emitter.vector_insert(s_b_53_8, emitter.const_s32((int32_t)5ULL), s_b_53_7);
        /* execute.simd:3005 [D] s_b_53_11: sym_41885_0_rd = s_b_53_10, dominates: s_b_54_9 s_b_56_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_53_10);
        /* execute.simd:3005 [F] s_b_53_12: Jump b_52 (const) */
        {
          auto block = block_b_52;
          dynamic_block_queue.push(block_b_52);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_54) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_54);
        /* execute.simd:3003 [D] s_b_54_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_54_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_54_1 = constant u8 6 (const) */
        /* execute.simd:3003 [D] s_b_54_0[s_b_54_1] */
        auto s_b_54_2 = emitter.vector_extract(s_b_54_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3003 [D] s_b_54_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_54_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_54_4 = constant u8 6 (const) */
        /* execute.simd:3003 [D] s_b_54_3[s_b_54_4] */
        auto s_b_54_5 = emitter.vector_extract(s_b_54_3, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3003 [D] s_b_54_6 = -s_b_54_5 */
        auto s_b_54_6 = emitter.neg(s_b_54_5);
        /* execute.simd:3003 [D] s_b_54_7 = (u8)s_b_54_6 */
        auto s_b_54_7 = emitter.reinterpret(s_b_54_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_54_8 = s_b_54_2>>s_b_54_7 */
        auto s_b_54_8 = emitter.shr(s_b_54_2, s_b_54_7);
        /* execute.simd:3003 [D] s_b_54_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_54_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_54_10 = constant s32 6 (const) */
        /* execute.simd:3003 [D] s_b_54_11 = s_b_54_9[s_b_54_10] <= s_b_54_8 */
        auto s_b_54_11 = emitter.vector_insert(s_b_54_9, emitter.const_s32((int32_t)6ULL), s_b_54_8);
        /* execute.simd:3003 [D] s_b_54_12: sym_41885_0_rd = s_b_54_11, dominates: s_b_57_9 s_b_59_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_54_11);
        /* execute.simd:3003 [F] s_b_54_13: Jump b_55 (const) */
        {
          auto block = block_b_55;
          dynamic_block_queue.push(block_b_55);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_55) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_55);
        /* execute.simd:3002 [D] s_b_55_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_55_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_55_1 = constant u8 7 (const) */
        /* execute.simd:3002 [D] s_b_55_0[s_b_55_1] */
        auto s_b_55_2 = emitter.vector_extract(s_b_55_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3002 [F] s_b_55_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_55_4 = (s32)s_b_55_2 */
        auto s_b_55_4 = emitter.sx(s_b_55_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_55_5 = s_b_55_4<s_b_55_3 */
        auto s_b_55_5 = emitter.cmp_lt(s_b_55_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_55_6: If s_b_55_5: Jump b_57 else b_59 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_57;
            dynamic_block_queue.push(block_b_57);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_59;
            dynamic_block_queue.push(block_b_59);
            false_target = block;
          }
          emitter.branch(s_b_55_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_56) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_56);
        /* execute.simd:3005 [D] s_b_56_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_56_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_56_1 = constant u8 6 (const) */
        /* execute.simd:3005 [D] s_b_56_0[s_b_56_1] */
        auto s_b_56_2 = emitter.vector_extract(s_b_56_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3005 [D] s_b_56_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_56_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_56_4 = constant u8 6 (const) */
        /* execute.simd:3005 [D] s_b_56_3[s_b_56_4] */
        auto s_b_56_5 = emitter.vector_extract(s_b_56_3, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3005 [D] s_b_56_6 = (u8)s_b_56_5 */
        auto s_b_56_6 = emitter.reinterpret(s_b_56_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_56_7 = s_b_56_2<<s_b_56_6 */
        auto s_b_56_7 = emitter.shl(s_b_56_2, s_b_56_6);
        /* execute.simd:3005 [D] s_b_56_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_56_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_56_9 = constant s32 6 (const) */
        /* execute.simd:3005 [D] s_b_56_10 = s_b_56_8[s_b_56_9] <= s_b_56_7 */
        auto s_b_56_10 = emitter.vector_insert(s_b_56_8, emitter.const_s32((int32_t)6ULL), s_b_56_7);
        /* execute.simd:3005 [D] s_b_56_11: sym_41885_0_rd = s_b_56_10, dominates: s_b_57_9 s_b_59_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_56_10);
        /* execute.simd:3005 [F] s_b_56_12: Jump b_55 (const) */
        {
          auto block = block_b_55;
          dynamic_block_queue.push(block_b_55);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_57) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_57);
        /* execute.simd:3003 [D] s_b_57_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_57_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_57_1 = constant u8 7 (const) */
        /* execute.simd:3003 [D] s_b_57_0[s_b_57_1] */
        auto s_b_57_2 = emitter.vector_extract(s_b_57_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3003 [D] s_b_57_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_57_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_57_4 = constant u8 7 (const) */
        /* execute.simd:3003 [D] s_b_57_3[s_b_57_4] */
        auto s_b_57_5 = emitter.vector_extract(s_b_57_3, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3003 [D] s_b_57_6 = -s_b_57_5 */
        auto s_b_57_6 = emitter.neg(s_b_57_5);
        /* execute.simd:3003 [D] s_b_57_7 = (u8)s_b_57_6 */
        auto s_b_57_7 = emitter.reinterpret(s_b_57_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_57_8 = s_b_57_2>>s_b_57_7 */
        auto s_b_57_8 = emitter.shr(s_b_57_2, s_b_57_7);
        /* execute.simd:3003 [D] s_b_57_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_57_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_57_10 = constant s32 7 (const) */
        /* execute.simd:3003 [D] s_b_57_11 = s_b_57_9[s_b_57_10] <= s_b_57_8 */
        auto s_b_57_11 = emitter.vector_insert(s_b_57_9, emitter.const_s32((int32_t)7ULL), s_b_57_8);
        /* execute.simd:3003 [D] s_b_57_12: sym_41885_0_rd = s_b_57_11, dominates: s_b_60_9 s_b_62_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_57_11);
        /* execute.simd:3003 [F] s_b_57_13: Jump b_58 (const) */
        {
          auto block = block_b_58;
          dynamic_block_queue.push(block_b_58);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_58) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_58);
        /* execute.simd:3002 [D] s_b_58_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_58_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_58_1 = constant u8 8 (const) */
        /* execute.simd:3002 [D] s_b_58_0[s_b_58_1] */
        auto s_b_58_2 = emitter.vector_extract(s_b_58_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:3002 [F] s_b_58_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_58_4 = (s32)s_b_58_2 */
        auto s_b_58_4 = emitter.sx(s_b_58_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_58_5 = s_b_58_4<s_b_58_3 */
        auto s_b_58_5 = emitter.cmp_lt(s_b_58_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_58_6: If s_b_58_5: Jump b_60 else b_62 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_60;
            dynamic_block_queue.push(block_b_60);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_62;
            dynamic_block_queue.push(block_b_62);
            false_target = block;
          }
          emitter.branch(s_b_58_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_59) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_59);
        /* execute.simd:3005 [D] s_b_59_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_59_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_59_1 = constant u8 7 (const) */
        /* execute.simd:3005 [D] s_b_59_0[s_b_59_1] */
        auto s_b_59_2 = emitter.vector_extract(s_b_59_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3005 [D] s_b_59_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_59_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_59_4 = constant u8 7 (const) */
        /* execute.simd:3005 [D] s_b_59_3[s_b_59_4] */
        auto s_b_59_5 = emitter.vector_extract(s_b_59_3, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3005 [D] s_b_59_6 = (u8)s_b_59_5 */
        auto s_b_59_6 = emitter.reinterpret(s_b_59_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_59_7 = s_b_59_2<<s_b_59_6 */
        auto s_b_59_7 = emitter.shl(s_b_59_2, s_b_59_6);
        /* execute.simd:3005 [D] s_b_59_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_59_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_59_9 = constant s32 7 (const) */
        /* execute.simd:3005 [D] s_b_59_10 = s_b_59_8[s_b_59_9] <= s_b_59_7 */
        auto s_b_59_10 = emitter.vector_insert(s_b_59_8, emitter.const_s32((int32_t)7ULL), s_b_59_7);
        /* execute.simd:3005 [D] s_b_59_11: sym_41885_0_rd = s_b_59_10, dominates: s_b_60_9 s_b_62_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_59_10);
        /* execute.simd:3005 [F] s_b_59_12: Jump b_58 (const) */
        {
          auto block = block_b_58;
          dynamic_block_queue.push(block_b_58);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_60) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_60);
        /* execute.simd:3003 [D] s_b_60_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_60_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_60_1 = constant u8 8 (const) */
        /* execute.simd:3003 [D] s_b_60_0[s_b_60_1] */
        auto s_b_60_2 = emitter.vector_extract(s_b_60_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:3003 [D] s_b_60_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_60_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_60_4 = constant u8 8 (const) */
        /* execute.simd:3003 [D] s_b_60_3[s_b_60_4] */
        auto s_b_60_5 = emitter.vector_extract(s_b_60_3, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:3003 [D] s_b_60_6 = -s_b_60_5 */
        auto s_b_60_6 = emitter.neg(s_b_60_5);
        /* execute.simd:3003 [D] s_b_60_7 = (u8)s_b_60_6 */
        auto s_b_60_7 = emitter.reinterpret(s_b_60_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_60_8 = s_b_60_2>>s_b_60_7 */
        auto s_b_60_8 = emitter.shr(s_b_60_2, s_b_60_7);
        /* execute.simd:3003 [D] s_b_60_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_60_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_60_10 = constant s32 8 (const) */
        /* execute.simd:3003 [D] s_b_60_11 = s_b_60_9[s_b_60_10] <= s_b_60_8 */
        auto s_b_60_11 = emitter.vector_insert(s_b_60_9, emitter.const_s32((int32_t)8ULL), s_b_60_8);
        /* execute.simd:3003 [D] s_b_60_12: sym_41885_0_rd = s_b_60_11, dominates: s_b_63_9 s_b_65_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_60_11);
        /* execute.simd:3003 [F] s_b_60_13: Jump b_61 (const) */
        {
          auto block = block_b_61;
          dynamic_block_queue.push(block_b_61);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_61) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_61);
        /* execute.simd:3002 [D] s_b_61_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_61_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_61_1 = constant u8 9 (const) */
        /* execute.simd:3002 [D] s_b_61_0[s_b_61_1] */
        auto s_b_61_2 = emitter.vector_extract(s_b_61_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:3002 [F] s_b_61_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_61_4 = (s32)s_b_61_2 */
        auto s_b_61_4 = emitter.sx(s_b_61_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_61_5 = s_b_61_4<s_b_61_3 */
        auto s_b_61_5 = emitter.cmp_lt(s_b_61_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_61_6: If s_b_61_5: Jump b_63 else b_65 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_63;
            dynamic_block_queue.push(block_b_63);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_65;
            dynamic_block_queue.push(block_b_65);
            false_target = block;
          }
          emitter.branch(s_b_61_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_62) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_62);
        /* execute.simd:3005 [D] s_b_62_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_62_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_62_1 = constant u8 8 (const) */
        /* execute.simd:3005 [D] s_b_62_0[s_b_62_1] */
        auto s_b_62_2 = emitter.vector_extract(s_b_62_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:3005 [D] s_b_62_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_62_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_62_4 = constant u8 8 (const) */
        /* execute.simd:3005 [D] s_b_62_3[s_b_62_4] */
        auto s_b_62_5 = emitter.vector_extract(s_b_62_3, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:3005 [D] s_b_62_6 = (u8)s_b_62_5 */
        auto s_b_62_6 = emitter.reinterpret(s_b_62_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_62_7 = s_b_62_2<<s_b_62_6 */
        auto s_b_62_7 = emitter.shl(s_b_62_2, s_b_62_6);
        /* execute.simd:3005 [D] s_b_62_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_62_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_62_9 = constant s32 8 (const) */
        /* execute.simd:3005 [D] s_b_62_10 = s_b_62_8[s_b_62_9] <= s_b_62_7 */
        auto s_b_62_10 = emitter.vector_insert(s_b_62_8, emitter.const_s32((int32_t)8ULL), s_b_62_7);
        /* execute.simd:3005 [D] s_b_62_11: sym_41885_0_rd = s_b_62_10, dominates: s_b_63_9 s_b_65_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_62_10);
        /* execute.simd:3005 [F] s_b_62_12: Jump b_61 (const) */
        {
          auto block = block_b_61;
          dynamic_block_queue.push(block_b_61);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_63) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_63);
        /* execute.simd:3003 [D] s_b_63_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_63_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_63_1 = constant u8 9 (const) */
        /* execute.simd:3003 [D] s_b_63_0[s_b_63_1] */
        auto s_b_63_2 = emitter.vector_extract(s_b_63_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:3003 [D] s_b_63_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_63_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_63_4 = constant u8 9 (const) */
        /* execute.simd:3003 [D] s_b_63_3[s_b_63_4] */
        auto s_b_63_5 = emitter.vector_extract(s_b_63_3, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:3003 [D] s_b_63_6 = -s_b_63_5 */
        auto s_b_63_6 = emitter.neg(s_b_63_5);
        /* execute.simd:3003 [D] s_b_63_7 = (u8)s_b_63_6 */
        auto s_b_63_7 = emitter.reinterpret(s_b_63_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_63_8 = s_b_63_2>>s_b_63_7 */
        auto s_b_63_8 = emitter.shr(s_b_63_2, s_b_63_7);
        /* execute.simd:3003 [D] s_b_63_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_63_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_63_10 = constant s32 9 (const) */
        /* execute.simd:3003 [D] s_b_63_11 = s_b_63_9[s_b_63_10] <= s_b_63_8 */
        auto s_b_63_11 = emitter.vector_insert(s_b_63_9, emitter.const_s32((int32_t)9ULL), s_b_63_8);
        /* execute.simd:3003 [D] s_b_63_12: sym_41885_0_rd = s_b_63_11, dominates: s_b_66_9 s_b_68_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_63_11);
        /* execute.simd:3003 [F] s_b_63_13: Jump b_64 (const) */
        {
          auto block = block_b_64;
          dynamic_block_queue.push(block_b_64);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_64) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_64);
        /* execute.simd:3002 [D] s_b_64_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_64_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_64_1 = constant u8 a (const) */
        /* execute.simd:3002 [D] s_b_64_0[s_b_64_1] */
        auto s_b_64_2 = emitter.vector_extract(s_b_64_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:3002 [F] s_b_64_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_64_4 = (s32)s_b_64_2 */
        auto s_b_64_4 = emitter.sx(s_b_64_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_64_5 = s_b_64_4<s_b_64_3 */
        auto s_b_64_5 = emitter.cmp_lt(s_b_64_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_64_6: If s_b_64_5: Jump b_66 else b_68 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_66;
            dynamic_block_queue.push(block_b_66);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_68;
            dynamic_block_queue.push(block_b_68);
            false_target = block;
          }
          emitter.branch(s_b_64_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_65) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_65);
        /* execute.simd:3005 [D] s_b_65_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_65_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_65_1 = constant u8 9 (const) */
        /* execute.simd:3005 [D] s_b_65_0[s_b_65_1] */
        auto s_b_65_2 = emitter.vector_extract(s_b_65_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:3005 [D] s_b_65_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_65_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_65_4 = constant u8 9 (const) */
        /* execute.simd:3005 [D] s_b_65_3[s_b_65_4] */
        auto s_b_65_5 = emitter.vector_extract(s_b_65_3, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:3005 [D] s_b_65_6 = (u8)s_b_65_5 */
        auto s_b_65_6 = emitter.reinterpret(s_b_65_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_65_7 = s_b_65_2<<s_b_65_6 */
        auto s_b_65_7 = emitter.shl(s_b_65_2, s_b_65_6);
        /* execute.simd:3005 [D] s_b_65_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_65_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_65_9 = constant s32 9 (const) */
        /* execute.simd:3005 [D] s_b_65_10 = s_b_65_8[s_b_65_9] <= s_b_65_7 */
        auto s_b_65_10 = emitter.vector_insert(s_b_65_8, emitter.const_s32((int32_t)9ULL), s_b_65_7);
        /* execute.simd:3005 [D] s_b_65_11: sym_41885_0_rd = s_b_65_10, dominates: s_b_66_9 s_b_68_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_65_10);
        /* execute.simd:3005 [F] s_b_65_12: Jump b_64 (const) */
        {
          auto block = block_b_64;
          dynamic_block_queue.push(block_b_64);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_66) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_66);
        /* execute.simd:3003 [D] s_b_66_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_66_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_66_1 = constant u8 a (const) */
        /* execute.simd:3003 [D] s_b_66_0[s_b_66_1] */
        auto s_b_66_2 = emitter.vector_extract(s_b_66_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:3003 [D] s_b_66_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_66_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_66_4 = constant u8 a (const) */
        /* execute.simd:3003 [D] s_b_66_3[s_b_66_4] */
        auto s_b_66_5 = emitter.vector_extract(s_b_66_3, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:3003 [D] s_b_66_6 = -s_b_66_5 */
        auto s_b_66_6 = emitter.neg(s_b_66_5);
        /* execute.simd:3003 [D] s_b_66_7 = (u8)s_b_66_6 */
        auto s_b_66_7 = emitter.reinterpret(s_b_66_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_66_8 = s_b_66_2>>s_b_66_7 */
        auto s_b_66_8 = emitter.shr(s_b_66_2, s_b_66_7);
        /* execute.simd:3003 [D] s_b_66_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_66_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_66_10 = constant s32 a (const) */
        /* execute.simd:3003 [D] s_b_66_11 = s_b_66_9[s_b_66_10] <= s_b_66_8 */
        auto s_b_66_11 = emitter.vector_insert(s_b_66_9, emitter.const_s32((int32_t)10ULL), s_b_66_8);
        /* execute.simd:3003 [D] s_b_66_12: sym_41885_0_rd = s_b_66_11, dominates: s_b_69_9 s_b_71_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_66_11);
        /* execute.simd:3003 [F] s_b_66_13: Jump b_67 (const) */
        {
          auto block = block_b_67;
          dynamic_block_queue.push(block_b_67);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_67) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_67);
        /* execute.simd:3002 [D] s_b_67_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_67_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_67_1 = constant u8 b (const) */
        /* execute.simd:3002 [D] s_b_67_0[s_b_67_1] */
        auto s_b_67_2 = emitter.vector_extract(s_b_67_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:3002 [F] s_b_67_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_67_4 = (s32)s_b_67_2 */
        auto s_b_67_4 = emitter.sx(s_b_67_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_67_5 = s_b_67_4<s_b_67_3 */
        auto s_b_67_5 = emitter.cmp_lt(s_b_67_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_67_6: If s_b_67_5: Jump b_69 else b_71 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_69;
            dynamic_block_queue.push(block_b_69);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_71;
            dynamic_block_queue.push(block_b_71);
            false_target = block;
          }
          emitter.branch(s_b_67_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_68) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_68);
        /* execute.simd:3005 [D] s_b_68_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_68_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_68_1 = constant u8 a (const) */
        /* execute.simd:3005 [D] s_b_68_0[s_b_68_1] */
        auto s_b_68_2 = emitter.vector_extract(s_b_68_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:3005 [D] s_b_68_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_68_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_68_4 = constant u8 a (const) */
        /* execute.simd:3005 [D] s_b_68_3[s_b_68_4] */
        auto s_b_68_5 = emitter.vector_extract(s_b_68_3, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:3005 [D] s_b_68_6 = (u8)s_b_68_5 */
        auto s_b_68_6 = emitter.reinterpret(s_b_68_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_68_7 = s_b_68_2<<s_b_68_6 */
        auto s_b_68_7 = emitter.shl(s_b_68_2, s_b_68_6);
        /* execute.simd:3005 [D] s_b_68_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_68_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_68_9 = constant s32 a (const) */
        /* execute.simd:3005 [D] s_b_68_10 = s_b_68_8[s_b_68_9] <= s_b_68_7 */
        auto s_b_68_10 = emitter.vector_insert(s_b_68_8, emitter.const_s32((int32_t)10ULL), s_b_68_7);
        /* execute.simd:3005 [D] s_b_68_11: sym_41885_0_rd = s_b_68_10, dominates: s_b_69_9 s_b_71_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_68_10);
        /* execute.simd:3005 [F] s_b_68_12: Jump b_67 (const) */
        {
          auto block = block_b_67;
          dynamic_block_queue.push(block_b_67);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_69) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_69);
        /* execute.simd:3003 [D] s_b_69_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_69_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_69_1 = constant u8 b (const) */
        /* execute.simd:3003 [D] s_b_69_0[s_b_69_1] */
        auto s_b_69_2 = emitter.vector_extract(s_b_69_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:3003 [D] s_b_69_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_69_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_69_4 = constant u8 b (const) */
        /* execute.simd:3003 [D] s_b_69_3[s_b_69_4] */
        auto s_b_69_5 = emitter.vector_extract(s_b_69_3, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:3003 [D] s_b_69_6 = -s_b_69_5 */
        auto s_b_69_6 = emitter.neg(s_b_69_5);
        /* execute.simd:3003 [D] s_b_69_7 = (u8)s_b_69_6 */
        auto s_b_69_7 = emitter.reinterpret(s_b_69_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_69_8 = s_b_69_2>>s_b_69_7 */
        auto s_b_69_8 = emitter.shr(s_b_69_2, s_b_69_7);
        /* execute.simd:3003 [D] s_b_69_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_69_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_69_10 = constant s32 b (const) */
        /* execute.simd:3003 [D] s_b_69_11 = s_b_69_9[s_b_69_10] <= s_b_69_8 */
        auto s_b_69_11 = emitter.vector_insert(s_b_69_9, emitter.const_s32((int32_t)11ULL), s_b_69_8);
        /* execute.simd:3003 [D] s_b_69_12: sym_41885_0_rd = s_b_69_11, dominates: s_b_72_9 s_b_74_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_69_11);
        /* execute.simd:3003 [F] s_b_69_13: Jump b_70 (const) */
        {
          auto block = block_b_70;
          dynamic_block_queue.push(block_b_70);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_70) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_70);
        /* execute.simd:3002 [D] s_b_70_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_70_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_70_1 = constant u8 c (const) */
        /* execute.simd:3002 [D] s_b_70_0[s_b_70_1] */
        auto s_b_70_2 = emitter.vector_extract(s_b_70_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:3002 [F] s_b_70_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_70_4 = (s32)s_b_70_2 */
        auto s_b_70_4 = emitter.sx(s_b_70_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_70_5 = s_b_70_4<s_b_70_3 */
        auto s_b_70_5 = emitter.cmp_lt(s_b_70_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_70_6: If s_b_70_5: Jump b_72 else b_74 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_72;
            dynamic_block_queue.push(block_b_72);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_74;
            dynamic_block_queue.push(block_b_74);
            false_target = block;
          }
          emitter.branch(s_b_70_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_71) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_71);
        /* execute.simd:3005 [D] s_b_71_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_71_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_71_1 = constant u8 b (const) */
        /* execute.simd:3005 [D] s_b_71_0[s_b_71_1] */
        auto s_b_71_2 = emitter.vector_extract(s_b_71_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:3005 [D] s_b_71_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_71_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_71_4 = constant u8 b (const) */
        /* execute.simd:3005 [D] s_b_71_3[s_b_71_4] */
        auto s_b_71_5 = emitter.vector_extract(s_b_71_3, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:3005 [D] s_b_71_6 = (u8)s_b_71_5 */
        auto s_b_71_6 = emitter.reinterpret(s_b_71_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_71_7 = s_b_71_2<<s_b_71_6 */
        auto s_b_71_7 = emitter.shl(s_b_71_2, s_b_71_6);
        /* execute.simd:3005 [D] s_b_71_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_71_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_71_9 = constant s32 b (const) */
        /* execute.simd:3005 [D] s_b_71_10 = s_b_71_8[s_b_71_9] <= s_b_71_7 */
        auto s_b_71_10 = emitter.vector_insert(s_b_71_8, emitter.const_s32((int32_t)11ULL), s_b_71_7);
        /* execute.simd:3005 [D] s_b_71_11: sym_41885_0_rd = s_b_71_10, dominates: s_b_72_9 s_b_74_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_71_10);
        /* execute.simd:3005 [F] s_b_71_12: Jump b_70 (const) */
        {
          auto block = block_b_70;
          dynamic_block_queue.push(block_b_70);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_72) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_72);
        /* execute.simd:3003 [D] s_b_72_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_72_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_72_1 = constant u8 c (const) */
        /* execute.simd:3003 [D] s_b_72_0[s_b_72_1] */
        auto s_b_72_2 = emitter.vector_extract(s_b_72_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:3003 [D] s_b_72_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_72_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_72_4 = constant u8 c (const) */
        /* execute.simd:3003 [D] s_b_72_3[s_b_72_4] */
        auto s_b_72_5 = emitter.vector_extract(s_b_72_3, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:3003 [D] s_b_72_6 = -s_b_72_5 */
        auto s_b_72_6 = emitter.neg(s_b_72_5);
        /* execute.simd:3003 [D] s_b_72_7 = (u8)s_b_72_6 */
        auto s_b_72_7 = emitter.reinterpret(s_b_72_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_72_8 = s_b_72_2>>s_b_72_7 */
        auto s_b_72_8 = emitter.shr(s_b_72_2, s_b_72_7);
        /* execute.simd:3003 [D] s_b_72_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_72_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_72_10 = constant s32 c (const) */
        /* execute.simd:3003 [D] s_b_72_11 = s_b_72_9[s_b_72_10] <= s_b_72_8 */
        auto s_b_72_11 = emitter.vector_insert(s_b_72_9, emitter.const_s32((int32_t)12ULL), s_b_72_8);
        /* execute.simd:3003 [D] s_b_72_12: sym_41885_0_rd = s_b_72_11, dominates: s_b_75_9 s_b_77_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_72_11);
        /* execute.simd:3003 [F] s_b_72_13: Jump b_73 (const) */
        {
          auto block = block_b_73;
          dynamic_block_queue.push(block_b_73);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_73) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_73);
        /* execute.simd:3002 [D] s_b_73_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_73_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_73_1 = constant u8 d (const) */
        /* execute.simd:3002 [D] s_b_73_0[s_b_73_1] */
        auto s_b_73_2 = emitter.vector_extract(s_b_73_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:3002 [F] s_b_73_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_73_4 = (s32)s_b_73_2 */
        auto s_b_73_4 = emitter.sx(s_b_73_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_73_5 = s_b_73_4<s_b_73_3 */
        auto s_b_73_5 = emitter.cmp_lt(s_b_73_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_73_6: If s_b_73_5: Jump b_75 else b_77 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_75;
            dynamic_block_queue.push(block_b_75);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_77;
            dynamic_block_queue.push(block_b_77);
            false_target = block;
          }
          emitter.branch(s_b_73_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_74) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_74);
        /* execute.simd:3005 [D] s_b_74_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_74_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_74_1 = constant u8 c (const) */
        /* execute.simd:3005 [D] s_b_74_0[s_b_74_1] */
        auto s_b_74_2 = emitter.vector_extract(s_b_74_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:3005 [D] s_b_74_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_74_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_74_4 = constant u8 c (const) */
        /* execute.simd:3005 [D] s_b_74_3[s_b_74_4] */
        auto s_b_74_5 = emitter.vector_extract(s_b_74_3, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:3005 [D] s_b_74_6 = (u8)s_b_74_5 */
        auto s_b_74_6 = emitter.reinterpret(s_b_74_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_74_7 = s_b_74_2<<s_b_74_6 */
        auto s_b_74_7 = emitter.shl(s_b_74_2, s_b_74_6);
        /* execute.simd:3005 [D] s_b_74_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_74_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_74_9 = constant s32 c (const) */
        /* execute.simd:3005 [D] s_b_74_10 = s_b_74_8[s_b_74_9] <= s_b_74_7 */
        auto s_b_74_10 = emitter.vector_insert(s_b_74_8, emitter.const_s32((int32_t)12ULL), s_b_74_7);
        /* execute.simd:3005 [D] s_b_74_11: sym_41885_0_rd = s_b_74_10, dominates: s_b_75_9 s_b_77_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_74_10);
        /* execute.simd:3005 [F] s_b_74_12: Jump b_73 (const) */
        {
          auto block = block_b_73;
          dynamic_block_queue.push(block_b_73);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_75) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_75);
        /* execute.simd:3003 [D] s_b_75_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_75_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_75_1 = constant u8 d (const) */
        /* execute.simd:3003 [D] s_b_75_0[s_b_75_1] */
        auto s_b_75_2 = emitter.vector_extract(s_b_75_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:3003 [D] s_b_75_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_75_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_75_4 = constant u8 d (const) */
        /* execute.simd:3003 [D] s_b_75_3[s_b_75_4] */
        auto s_b_75_5 = emitter.vector_extract(s_b_75_3, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:3003 [D] s_b_75_6 = -s_b_75_5 */
        auto s_b_75_6 = emitter.neg(s_b_75_5);
        /* execute.simd:3003 [D] s_b_75_7 = (u8)s_b_75_6 */
        auto s_b_75_7 = emitter.reinterpret(s_b_75_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_75_8 = s_b_75_2>>s_b_75_7 */
        auto s_b_75_8 = emitter.shr(s_b_75_2, s_b_75_7);
        /* execute.simd:3003 [D] s_b_75_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_75_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_75_10 = constant s32 d (const) */
        /* execute.simd:3003 [D] s_b_75_11 = s_b_75_9[s_b_75_10] <= s_b_75_8 */
        auto s_b_75_11 = emitter.vector_insert(s_b_75_9, emitter.const_s32((int32_t)13ULL), s_b_75_8);
        /* execute.simd:3003 [D] s_b_75_12: sym_41885_0_rd = s_b_75_11, dominates: s_b_78_9 s_b_80_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_75_11);
        /* execute.simd:3003 [F] s_b_75_13: Jump b_76 (const) */
        {
          auto block = block_b_76;
          dynamic_block_queue.push(block_b_76);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_76) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_76);
        /* execute.simd:3002 [D] s_b_76_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_76_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_76_1 = constant u8 e (const) */
        /* execute.simd:3002 [D] s_b_76_0[s_b_76_1] */
        auto s_b_76_2 = emitter.vector_extract(s_b_76_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:3002 [F] s_b_76_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_76_4 = (s32)s_b_76_2 */
        auto s_b_76_4 = emitter.sx(s_b_76_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_76_5 = s_b_76_4<s_b_76_3 */
        auto s_b_76_5 = emitter.cmp_lt(s_b_76_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_76_6: If s_b_76_5: Jump b_78 else b_80 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_78;
            dynamic_block_queue.push(block_b_78);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_80;
            dynamic_block_queue.push(block_b_80);
            false_target = block;
          }
          emitter.branch(s_b_76_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_77) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_77);
        /* execute.simd:3005 [D] s_b_77_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_77_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_77_1 = constant u8 d (const) */
        /* execute.simd:3005 [D] s_b_77_0[s_b_77_1] */
        auto s_b_77_2 = emitter.vector_extract(s_b_77_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:3005 [D] s_b_77_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_77_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_77_4 = constant u8 d (const) */
        /* execute.simd:3005 [D] s_b_77_3[s_b_77_4] */
        auto s_b_77_5 = emitter.vector_extract(s_b_77_3, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:3005 [D] s_b_77_6 = (u8)s_b_77_5 */
        auto s_b_77_6 = emitter.reinterpret(s_b_77_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_77_7 = s_b_77_2<<s_b_77_6 */
        auto s_b_77_7 = emitter.shl(s_b_77_2, s_b_77_6);
        /* execute.simd:3005 [D] s_b_77_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_77_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_77_9 = constant s32 d (const) */
        /* execute.simd:3005 [D] s_b_77_10 = s_b_77_8[s_b_77_9] <= s_b_77_7 */
        auto s_b_77_10 = emitter.vector_insert(s_b_77_8, emitter.const_s32((int32_t)13ULL), s_b_77_7);
        /* execute.simd:3005 [D] s_b_77_11: sym_41885_0_rd = s_b_77_10, dominates: s_b_78_9 s_b_80_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_77_10);
        /* execute.simd:3005 [F] s_b_77_12: Jump b_76 (const) */
        {
          auto block = block_b_76;
          dynamic_block_queue.push(block_b_76);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_78) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_78);
        /* execute.simd:3003 [D] s_b_78_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_78_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_78_1 = constant u8 e (const) */
        /* execute.simd:3003 [D] s_b_78_0[s_b_78_1] */
        auto s_b_78_2 = emitter.vector_extract(s_b_78_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:3003 [D] s_b_78_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_78_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_78_4 = constant u8 e (const) */
        /* execute.simd:3003 [D] s_b_78_3[s_b_78_4] */
        auto s_b_78_5 = emitter.vector_extract(s_b_78_3, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:3003 [D] s_b_78_6 = -s_b_78_5 */
        auto s_b_78_6 = emitter.neg(s_b_78_5);
        /* execute.simd:3003 [D] s_b_78_7 = (u8)s_b_78_6 */
        auto s_b_78_7 = emitter.reinterpret(s_b_78_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_78_8 = s_b_78_2>>s_b_78_7 */
        auto s_b_78_8 = emitter.shr(s_b_78_2, s_b_78_7);
        /* execute.simd:3003 [D] s_b_78_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_78_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_78_10 = constant s32 e (const) */
        /* execute.simd:3003 [D] s_b_78_11 = s_b_78_9[s_b_78_10] <= s_b_78_8 */
        auto s_b_78_11 = emitter.vector_insert(s_b_78_9, emitter.const_s32((int32_t)14ULL), s_b_78_8);
        /* execute.simd:3003 [D] s_b_78_12: sym_41885_0_rd = s_b_78_11, dominates: s_b_81_9 s_b_83_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_78_11);
        /* execute.simd:3003 [F] s_b_78_13: Jump b_79 (const) */
        {
          auto block = block_b_79;
          dynamic_block_queue.push(block_b_79);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_79) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_79);
        /* execute.simd:3002 [D] s_b_79_0 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_79_0 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_79_1 = constant u8 f (const) */
        /* execute.simd:3002 [D] s_b_79_0[s_b_79_1] */
        auto s_b_79_2 = emitter.vector_extract(s_b_79_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:3002 [F] s_b_79_3 = constant s32 0 (const) */
        /* execute.simd:3002 [D] s_b_79_4 = (s32)s_b_79_2 */
        auto s_b_79_4 = emitter.sx(s_b_79_2, emitter.context().types().s32());
        /* execute.simd:3002 [D] s_b_79_5 = s_b_79_4<s_b_79_3 */
        auto s_b_79_5 = emitter.cmp_lt(s_b_79_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3002 [D] s_b_79_6: If s_b_79_5: Jump b_81 else b_83 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_81;
            dynamic_block_queue.push(block_b_81);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_83;
            dynamic_block_queue.push(block_b_83);
            false_target = block;
          }
          emitter.branch(s_b_79_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_80) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_80);
        /* execute.simd:3005 [D] s_b_80_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_80_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_80_1 = constant u8 e (const) */
        /* execute.simd:3005 [D] s_b_80_0[s_b_80_1] */
        auto s_b_80_2 = emitter.vector_extract(s_b_80_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:3005 [D] s_b_80_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_80_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_80_4 = constant u8 e (const) */
        /* execute.simd:3005 [D] s_b_80_3[s_b_80_4] */
        auto s_b_80_5 = emitter.vector_extract(s_b_80_3, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:3005 [D] s_b_80_6 = (u8)s_b_80_5 */
        auto s_b_80_6 = emitter.reinterpret(s_b_80_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_80_7 = s_b_80_2<<s_b_80_6 */
        auto s_b_80_7 = emitter.shl(s_b_80_2, s_b_80_6);
        /* execute.simd:3005 [D] s_b_80_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_80_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_80_9 = constant s32 e (const) */
        /* execute.simd:3005 [D] s_b_80_10 = s_b_80_8[s_b_80_9] <= s_b_80_7 */
        auto s_b_80_10 = emitter.vector_insert(s_b_80_8, emitter.const_s32((int32_t)14ULL), s_b_80_7);
        /* execute.simd:3005 [D] s_b_80_11: sym_41885_0_rd = s_b_80_10, dominates: s_b_81_9 s_b_83_8  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_80_10);
        /* execute.simd:3005 [F] s_b_80_12: Jump b_79 (const) */
        {
          auto block = block_b_79;
          dynamic_block_queue.push(block_b_79);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_81) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_81);
        /* execute.simd:3003 [D] s_b_81_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_81_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_81_1 = constant u8 f (const) */
        /* execute.simd:3003 [D] s_b_81_0[s_b_81_1] */
        auto s_b_81_2 = emitter.vector_extract(s_b_81_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:3003 [D] s_b_81_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_81_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_81_4 = constant u8 f (const) */
        /* execute.simd:3003 [D] s_b_81_3[s_b_81_4] */
        auto s_b_81_5 = emitter.vector_extract(s_b_81_3, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:3003 [D] s_b_81_6 = -s_b_81_5 */
        auto s_b_81_6 = emitter.neg(s_b_81_5);
        /* execute.simd:3003 [D] s_b_81_7 = (u8)s_b_81_6 */
        auto s_b_81_7 = emitter.reinterpret(s_b_81_6, emitter.context().types().u8());
        /* execute.simd:3003 [D] s_b_81_8 = s_b_81_2>>s_b_81_7 */
        auto s_b_81_8 = emitter.shr(s_b_81_2, s_b_81_7);
        /* execute.simd:3003 [D] s_b_81_9 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_81_9 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3003 [F] s_b_81_10 = constant s32 f (const) */
        /* execute.simd:3003 [D] s_b_81_11 = s_b_81_9[s_b_81_10] <= s_b_81_8 */
        auto s_b_81_11 = emitter.vector_insert(s_b_81_9, emitter.const_s32((int32_t)15ULL), s_b_81_8);
        /* execute.simd:3003 [D] s_b_81_12: sym_41885_0_rd = s_b_81_11, dominates: s_b_82_1  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_81_11);
        /* execute.simd:3003 [F] s_b_81_13: Jump b_82 (const) */
        {
          auto block = block_b_82;
          dynamic_block_queue.push(block_b_82);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_82) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_82);
        /* execute.simd:3009 [F] s_b_82_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:3009 [D] s_b_82_1 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_82_1 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3009 [D] s_b_82_2: WriteRegBank 16:s_b_82_0 = s_b_82_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_82_1,emitter.const_u8(16));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_82_1);
        /* execute.simd:0 [F] s_b_82_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_83) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_83);
        /* execute.simd:3005 [D] s_b_83_0 = sym_41876_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_83_0 = emitter.load_local(DV_sym_41876_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_83_1 = constant u8 f (const) */
        /* execute.simd:3005 [D] s_b_83_0[s_b_83_1] */
        auto s_b_83_2 = emitter.vector_extract(s_b_83_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:3005 [D] s_b_83_3 = sym_41880_0_rm wutils::Vector<int8_t, 16> */
        auto s_b_83_3 = emitter.load_local(DV_sym_41880_0_rm, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_83_4 = constant u8 f (const) */
        /* execute.simd:3005 [D] s_b_83_3[s_b_83_4] */
        auto s_b_83_5 = emitter.vector_extract(s_b_83_3, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:3005 [D] s_b_83_6 = (u8)s_b_83_5 */
        auto s_b_83_6 = emitter.reinterpret(s_b_83_5, emitter.context().types().u8());
        /* execute.simd:3005 [D] s_b_83_7 = s_b_83_2<<s_b_83_6 */
        auto s_b_83_7 = emitter.shl(s_b_83_2, s_b_83_6);
        /* execute.simd:3005 [D] s_b_83_8 = sym_41885_0_rd wutils::Vector<uint8_t, 16> */
        auto s_b_83_8 = emitter.load_local(DV_sym_41885_0_rd, emitter.context().types().v16u8());
        /* execute.simd:3005 [F] s_b_83_9 = constant s32 f (const) */
        /* execute.simd:3005 [D] s_b_83_10 = s_b_83_8[s_b_83_9] <= s_b_83_7 */
        auto s_b_83_10 = emitter.vector_insert(s_b_83_8, emitter.const_s32((int32_t)15ULL), s_b_83_7);
        /* execute.simd:3005 [D] s_b_83_11: sym_41885_0_rd = s_b_83_10, dominates: s_b_82_1  */
        emitter.store_local(DV_sym_41885_0_rd, s_b_83_10);
        /* execute.simd:3005 [F] s_b_83_12: Jump b_82 (const) */
        {
          auto block = block_b_82;
          dynamic_block_queue.push(block_b_82);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_85) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_85);
        /* execute.simd:3019 [D] s_b_85_0 = sym_42666_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_85_0 = emitter.load_local(DV_sym_42666_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_85_1 = constant u8 0 (const) */
        /* execute.simd:3019 [D] s_b_85_0[s_b_85_1] */
        auto s_b_85_2 = emitter.vector_extract(s_b_85_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3019 [D] s_b_85_3 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_85_3 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_85_4 = constant u8 0 (const) */
        /* execute.simd:3019 [D] s_b_85_3[s_b_85_4] */
        auto s_b_85_5 = emitter.vector_extract(s_b_85_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3019 [D] s_b_85_6 = -s_b_85_5 */
        auto s_b_85_6 = emitter.neg(s_b_85_5);
        /* execute.simd:3019 [D] s_b_85_7 = (u16)s_b_85_6 */
        auto s_b_85_7 = emitter.reinterpret(s_b_85_6, emitter.context().types().u16());
        /* execute.simd:3019 [D] s_b_85_8 = s_b_85_2>>s_b_85_7 */
        auto s_b_85_8 = emitter.shr(s_b_85_2, s_b_85_7);
        /* execute.simd:3019 [F] s_b_85_9 = sym_42675_0_rd (const) wutils::Vector<uint16_t, 8> */
        wutils::Vector<uint16_t, 8> s_b_85_9 = CV_sym_42675_0_rd;
        /* execute.simd:3019 [F] s_b_85_10 = constant s32 0 (const) */
        /* execute.simd:3019 [D] s_b_85_11 = s_b_85_9[s_b_85_10] <= s_b_85_8 */
        auto s_b_85_11 = emitter.vector_insert(emitter.constant_vector_splat(s_b_85_9[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_85_8);
        /* execute.simd:3019 [D] s_b_85_12: sym_42675_0_rd = s_b_85_11, dominates: s_b_88_9 s_b_90_8  */
        emitter.store_local(DV_sym_42675_0_rd, s_b_85_11);
        /* execute.simd:3019 [F] s_b_85_13: Jump b_86 (const) */
        {
          auto block = block_b_86;
          dynamic_block_queue.push(block_b_86);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_86) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_86);
        /* execute.simd:3018 [D] s_b_86_0 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_86_0 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_86_1 = constant u8 1 (const) */
        /* execute.simd:3018 [D] s_b_86_0[s_b_86_1] */
        auto s_b_86_2 = emitter.vector_extract(s_b_86_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3018 [F] s_b_86_3 = constant s32 0 (const) */
        /* execute.simd:3018 [D] s_b_86_4 = (s32)s_b_86_2 */
        auto s_b_86_4 = emitter.sx(s_b_86_2, emitter.context().types().s32());
        /* execute.simd:3018 [D] s_b_86_5 = s_b_86_4<s_b_86_3 */
        auto s_b_86_5 = emitter.cmp_lt(s_b_86_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3018 [D] s_b_86_6: If s_b_86_5: Jump b_88 else b_90 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_88;
            dynamic_block_queue.push(block_b_88);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_90;
            dynamic_block_queue.push(block_b_90);
            false_target = block;
          }
          emitter.branch(s_b_86_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_87) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_87);
        /* execute.simd:3021 [D] s_b_87_0 = sym_42666_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_87_0 = emitter.load_local(DV_sym_42666_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_87_1 = constant u8 0 (const) */
        /* execute.simd:3021 [D] s_b_87_0[s_b_87_1] */
        auto s_b_87_2 = emitter.vector_extract(s_b_87_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3021 [D] s_b_87_3 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_87_3 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_87_4 = constant u8 0 (const) */
        /* execute.simd:3021 [D] s_b_87_3[s_b_87_4] */
        auto s_b_87_5 = emitter.vector_extract(s_b_87_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3021 [D] s_b_87_6 = (u16)s_b_87_5 */
        auto s_b_87_6 = emitter.reinterpret(s_b_87_5, emitter.context().types().u16());
        /* execute.simd:3021 [D] s_b_87_7 = s_b_87_2<<s_b_87_6 */
        auto s_b_87_7 = emitter.shl(s_b_87_2, s_b_87_6);
        /* execute.simd:3021 [F] s_b_87_8 = sym_42675_0_rd (const) wutils::Vector<uint16_t, 8> */
        wutils::Vector<uint16_t, 8> s_b_87_8 = CV_sym_42675_0_rd;
        /* execute.simd:3021 [F] s_b_87_9 = constant s32 0 (const) */
        /* execute.simd:3021 [D] s_b_87_10 = s_b_87_8[s_b_87_9] <= s_b_87_7 */
        auto s_b_87_10 = emitter.vector_insert(emitter.constant_vector_splat(s_b_87_8[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_87_7);
        /* execute.simd:3021 [D] s_b_87_11: sym_42675_0_rd = s_b_87_10, dominates: s_b_88_9 s_b_90_8  */
        emitter.store_local(DV_sym_42675_0_rd, s_b_87_10);
        /* execute.simd:3021 [F] s_b_87_12: Jump b_86 (const) */
        {
          auto block = block_b_86;
          dynamic_block_queue.push(block_b_86);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_88) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_88);
        /* execute.simd:3019 [D] s_b_88_0 = sym_42666_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_88_0 = emitter.load_local(DV_sym_42666_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_88_1 = constant u8 1 (const) */
        /* execute.simd:3019 [D] s_b_88_0[s_b_88_1] */
        auto s_b_88_2 = emitter.vector_extract(s_b_88_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3019 [D] s_b_88_3 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_88_3 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_88_4 = constant u8 1 (const) */
        /* execute.simd:3019 [D] s_b_88_3[s_b_88_4] */
        auto s_b_88_5 = emitter.vector_extract(s_b_88_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3019 [D] s_b_88_6 = -s_b_88_5 */
        auto s_b_88_6 = emitter.neg(s_b_88_5);
        /* execute.simd:3019 [D] s_b_88_7 = (u16)s_b_88_6 */
        auto s_b_88_7 = emitter.reinterpret(s_b_88_6, emitter.context().types().u16());
        /* execute.simd:3019 [D] s_b_88_8 = s_b_88_2>>s_b_88_7 */
        auto s_b_88_8 = emitter.shr(s_b_88_2, s_b_88_7);
        /* execute.simd:3019 [D] s_b_88_9 = sym_42675_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_88_9 = emitter.load_local(DV_sym_42675_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3019 [F] s_b_88_10 = constant s32 1 (const) */
        /* execute.simd:3019 [D] s_b_88_11 = s_b_88_9[s_b_88_10] <= s_b_88_8 */
        auto s_b_88_11 = emitter.vector_insert(s_b_88_9, emitter.const_s32((int32_t)1ULL), s_b_88_8);
        /* execute.simd:3019 [D] s_b_88_12: sym_42675_0_rd = s_b_88_11, dominates: s_b_91_9 s_b_93_8  */
        emitter.store_local(DV_sym_42675_0_rd, s_b_88_11);
        /* execute.simd:3019 [F] s_b_88_13: Jump b_89 (const) */
        {
          auto block = block_b_89;
          dynamic_block_queue.push(block_b_89);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_89) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_89);
        /* execute.simd:3018 [D] s_b_89_0 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_89_0 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_89_1 = constant u8 2 (const) */
        /* execute.simd:3018 [D] s_b_89_0[s_b_89_1] */
        auto s_b_89_2 = emitter.vector_extract(s_b_89_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3018 [F] s_b_89_3 = constant s32 0 (const) */
        /* execute.simd:3018 [D] s_b_89_4 = (s32)s_b_89_2 */
        auto s_b_89_4 = emitter.sx(s_b_89_2, emitter.context().types().s32());
        /* execute.simd:3018 [D] s_b_89_5 = s_b_89_4<s_b_89_3 */
        auto s_b_89_5 = emitter.cmp_lt(s_b_89_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3018 [D] s_b_89_6: If s_b_89_5: Jump b_91 else b_93 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_91;
            dynamic_block_queue.push(block_b_91);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_93;
            dynamic_block_queue.push(block_b_93);
            false_target = block;
          }
          emitter.branch(s_b_89_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_90) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_90);
        /* execute.simd:3021 [D] s_b_90_0 = sym_42666_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_90_0 = emitter.load_local(DV_sym_42666_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_90_1 = constant u8 1 (const) */
        /* execute.simd:3021 [D] s_b_90_0[s_b_90_1] */
        auto s_b_90_2 = emitter.vector_extract(s_b_90_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3021 [D] s_b_90_3 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_90_3 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_90_4 = constant u8 1 (const) */
        /* execute.simd:3021 [D] s_b_90_3[s_b_90_4] */
        auto s_b_90_5 = emitter.vector_extract(s_b_90_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3021 [D] s_b_90_6 = (u16)s_b_90_5 */
        auto s_b_90_6 = emitter.reinterpret(s_b_90_5, emitter.context().types().u16());
        /* execute.simd:3021 [D] s_b_90_7 = s_b_90_2<<s_b_90_6 */
        auto s_b_90_7 = emitter.shl(s_b_90_2, s_b_90_6);
        /* execute.simd:3021 [D] s_b_90_8 = sym_42675_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_90_8 = emitter.load_local(DV_sym_42675_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3021 [F] s_b_90_9 = constant s32 1 (const) */
        /* execute.simd:3021 [D] s_b_90_10 = s_b_90_8[s_b_90_9] <= s_b_90_7 */
        auto s_b_90_10 = emitter.vector_insert(s_b_90_8, emitter.const_s32((int32_t)1ULL), s_b_90_7);
        /* execute.simd:3021 [D] s_b_90_11: sym_42675_0_rd = s_b_90_10, dominates: s_b_91_9 s_b_93_8  */
        emitter.store_local(DV_sym_42675_0_rd, s_b_90_10);
        /* execute.simd:3021 [F] s_b_90_12: Jump b_89 (const) */
        {
          auto block = block_b_89;
          dynamic_block_queue.push(block_b_89);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_91) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_91);
        /* execute.simd:3019 [D] s_b_91_0 = sym_42666_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_91_0 = emitter.load_local(DV_sym_42666_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_91_1 = constant u8 2 (const) */
        /* execute.simd:3019 [D] s_b_91_0[s_b_91_1] */
        auto s_b_91_2 = emitter.vector_extract(s_b_91_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3019 [D] s_b_91_3 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_91_3 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_91_4 = constant u8 2 (const) */
        /* execute.simd:3019 [D] s_b_91_3[s_b_91_4] */
        auto s_b_91_5 = emitter.vector_extract(s_b_91_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3019 [D] s_b_91_6 = -s_b_91_5 */
        auto s_b_91_6 = emitter.neg(s_b_91_5);
        /* execute.simd:3019 [D] s_b_91_7 = (u16)s_b_91_6 */
        auto s_b_91_7 = emitter.reinterpret(s_b_91_6, emitter.context().types().u16());
        /* execute.simd:3019 [D] s_b_91_8 = s_b_91_2>>s_b_91_7 */
        auto s_b_91_8 = emitter.shr(s_b_91_2, s_b_91_7);
        /* execute.simd:3019 [D] s_b_91_9 = sym_42675_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_91_9 = emitter.load_local(DV_sym_42675_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3019 [F] s_b_91_10 = constant s32 2 (const) */
        /* execute.simd:3019 [D] s_b_91_11 = s_b_91_9[s_b_91_10] <= s_b_91_8 */
        auto s_b_91_11 = emitter.vector_insert(s_b_91_9, emitter.const_s32((int32_t)2ULL), s_b_91_8);
        /* execute.simd:3019 [D] s_b_91_12: sym_42675_0_rd = s_b_91_11, dominates: s_b_94_9 s_b_96_8  */
        emitter.store_local(DV_sym_42675_0_rd, s_b_91_11);
        /* execute.simd:3019 [F] s_b_91_13: Jump b_92 (const) */
        {
          auto block = block_b_92;
          dynamic_block_queue.push(block_b_92);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_92) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_92);
        /* execute.simd:3018 [D] s_b_92_0 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_92_0 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_92_1 = constant u8 3 (const) */
        /* execute.simd:3018 [D] s_b_92_0[s_b_92_1] */
        auto s_b_92_2 = emitter.vector_extract(s_b_92_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3018 [F] s_b_92_3 = constant s32 0 (const) */
        /* execute.simd:3018 [D] s_b_92_4 = (s32)s_b_92_2 */
        auto s_b_92_4 = emitter.sx(s_b_92_2, emitter.context().types().s32());
        /* execute.simd:3018 [D] s_b_92_5 = s_b_92_4<s_b_92_3 */
        auto s_b_92_5 = emitter.cmp_lt(s_b_92_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3018 [D] s_b_92_6: If s_b_92_5: Jump b_94 else b_96 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_94;
            dynamic_block_queue.push(block_b_94);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_96;
            dynamic_block_queue.push(block_b_96);
            false_target = block;
          }
          emitter.branch(s_b_92_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_93) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_93);
        /* execute.simd:3021 [D] s_b_93_0 = sym_42666_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_93_0 = emitter.load_local(DV_sym_42666_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_93_1 = constant u8 2 (const) */
        /* execute.simd:3021 [D] s_b_93_0[s_b_93_1] */
        auto s_b_93_2 = emitter.vector_extract(s_b_93_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3021 [D] s_b_93_3 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_93_3 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_93_4 = constant u8 2 (const) */
        /* execute.simd:3021 [D] s_b_93_3[s_b_93_4] */
        auto s_b_93_5 = emitter.vector_extract(s_b_93_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3021 [D] s_b_93_6 = (u16)s_b_93_5 */
        auto s_b_93_6 = emitter.reinterpret(s_b_93_5, emitter.context().types().u16());
        /* execute.simd:3021 [D] s_b_93_7 = s_b_93_2<<s_b_93_6 */
        auto s_b_93_7 = emitter.shl(s_b_93_2, s_b_93_6);
        /* execute.simd:3021 [D] s_b_93_8 = sym_42675_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_93_8 = emitter.load_local(DV_sym_42675_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3021 [F] s_b_93_9 = constant s32 2 (const) */
        /* execute.simd:3021 [D] s_b_93_10 = s_b_93_8[s_b_93_9] <= s_b_93_7 */
        auto s_b_93_10 = emitter.vector_insert(s_b_93_8, emitter.const_s32((int32_t)2ULL), s_b_93_7);
        /* execute.simd:3021 [D] s_b_93_11: sym_42675_0_rd = s_b_93_10, dominates: s_b_94_9 s_b_96_8  */
        emitter.store_local(DV_sym_42675_0_rd, s_b_93_10);
        /* execute.simd:3021 [F] s_b_93_12: Jump b_92 (const) */
        {
          auto block = block_b_92;
          dynamic_block_queue.push(block_b_92);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_94) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_94);
        /* execute.simd:3019 [D] s_b_94_0 = sym_42666_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_94_0 = emitter.load_local(DV_sym_42666_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_94_1 = constant u8 3 (const) */
        /* execute.simd:3019 [D] s_b_94_0[s_b_94_1] */
        auto s_b_94_2 = emitter.vector_extract(s_b_94_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3019 [D] s_b_94_3 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_94_3 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_94_4 = constant u8 3 (const) */
        /* execute.simd:3019 [D] s_b_94_3[s_b_94_4] */
        auto s_b_94_5 = emitter.vector_extract(s_b_94_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3019 [D] s_b_94_6 = -s_b_94_5 */
        auto s_b_94_6 = emitter.neg(s_b_94_5);
        /* execute.simd:3019 [D] s_b_94_7 = (u16)s_b_94_6 */
        auto s_b_94_7 = emitter.reinterpret(s_b_94_6, emitter.context().types().u16());
        /* execute.simd:3019 [D] s_b_94_8 = s_b_94_2>>s_b_94_7 */
        auto s_b_94_8 = emitter.shr(s_b_94_2, s_b_94_7);
        /* execute.simd:3019 [D] s_b_94_9 = sym_42675_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_94_9 = emitter.load_local(DV_sym_42675_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3019 [F] s_b_94_10 = constant s32 3 (const) */
        /* execute.simd:3019 [D] s_b_94_11 = s_b_94_9[s_b_94_10] <= s_b_94_8 */
        auto s_b_94_11 = emitter.vector_insert(s_b_94_9, emitter.const_s32((int32_t)3ULL), s_b_94_8);
        /* execute.simd:3019 [D] s_b_94_12: sym_42675_0_rd = s_b_94_11, dominates: s_b_95_1  */
        emitter.store_local(DV_sym_42675_0_rd, s_b_94_11);
        /* execute.simd:3019 [F] s_b_94_13: Jump b_95 (const) */
        {
          auto block = block_b_95;
          dynamic_block_queue.push(block_b_95);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_95) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_95);
        /* execute.simd:3025 [F] s_b_95_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:3025 [D] s_b_95_1 = sym_42675_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_95_1 = emitter.load_local(DV_sym_42675_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3025 [D] s_b_95_2: WriteRegBank 18:s_b_95_0 = s_b_95_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_95_1,emitter.const_u8(16));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_95_1);
        /* execute.simd:0 [F] s_b_95_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_96) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_96);
        /* execute.simd:3021 [D] s_b_96_0 = sym_42666_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_96_0 = emitter.load_local(DV_sym_42666_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_96_1 = constant u8 3 (const) */
        /* execute.simd:3021 [D] s_b_96_0[s_b_96_1] */
        auto s_b_96_2 = emitter.vector_extract(s_b_96_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3021 [D] s_b_96_3 = sym_42670_0_rm wutils::Vector<int16_t, 4> */
        auto s_b_96_3 = emitter.load_local(DV_sym_42670_0_rm, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_96_4 = constant u8 3 (const) */
        /* execute.simd:3021 [D] s_b_96_3[s_b_96_4] */
        auto s_b_96_5 = emitter.vector_extract(s_b_96_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3021 [D] s_b_96_6 = (u16)s_b_96_5 */
        auto s_b_96_6 = emitter.reinterpret(s_b_96_5, emitter.context().types().u16());
        /* execute.simd:3021 [D] s_b_96_7 = s_b_96_2<<s_b_96_6 */
        auto s_b_96_7 = emitter.shl(s_b_96_2, s_b_96_6);
        /* execute.simd:3021 [D] s_b_96_8 = sym_42675_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_96_8 = emitter.load_local(DV_sym_42675_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3021 [F] s_b_96_9 = constant s32 3 (const) */
        /* execute.simd:3021 [D] s_b_96_10 = s_b_96_8[s_b_96_9] <= s_b_96_7 */
        auto s_b_96_10 = emitter.vector_insert(s_b_96_8, emitter.const_s32((int32_t)3ULL), s_b_96_7);
        /* execute.simd:3021 [D] s_b_96_11: sym_42675_0_rd = s_b_96_10, dominates: s_b_95_1  */
        emitter.store_local(DV_sym_42675_0_rd, s_b_96_10);
        /* execute.simd:3021 [F] s_b_96_12: Jump b_95 (const) */
        {
          auto block = block_b_95;
          dynamic_block_queue.push(block_b_95);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_98) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_98);
        /* execute.simd:3035 [D] s_b_98_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_98_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_98_1 = constant u8 0 (const) */
        /* execute.simd:3035 [D] s_b_98_0[s_b_98_1] */
        auto s_b_98_2 = emitter.vector_extract(s_b_98_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3035 [D] s_b_98_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_98_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_98_4 = constant u8 0 (const) */
        /* execute.simd:3035 [D] s_b_98_3[s_b_98_4] */
        auto s_b_98_5 = emitter.vector_extract(s_b_98_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3035 [D] s_b_98_6 = -s_b_98_5 */
        auto s_b_98_6 = emitter.neg(s_b_98_5);
        /* execute.simd:3035 [D] s_b_98_7 = (u16)s_b_98_6 */
        auto s_b_98_7 = emitter.reinterpret(s_b_98_6, emitter.context().types().u16());
        /* execute.simd:3035 [D] s_b_98_8 = s_b_98_2>>s_b_98_7 */
        auto s_b_98_8 = emitter.shr(s_b_98_2, s_b_98_7);
        /* execute.simd:3035 [F] s_b_98_9 = sym_42889_0_rd (const) wutils::Vector<uint16_t, 8> */
        wutils::Vector<uint16_t, 8> s_b_98_9 = CV_sym_42889_0_rd;
        /* execute.simd:3035 [F] s_b_98_10 = constant s32 0 (const) */
        /* execute.simd:3035 [D] s_b_98_11 = s_b_98_9[s_b_98_10] <= s_b_98_8 */
        auto s_b_98_11 = emitter.vector_insert(emitter.constant_vector_splat(s_b_98_9[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_98_8);
        /* execute.simd:3035 [D] s_b_98_12: sym_42889_0_rd = s_b_98_11, dominates: s_b_101_9 s_b_103_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_98_11);
        /* execute.simd:3035 [F] s_b_98_13: Jump b_99 (const) */
        {
          auto block = block_b_99;
          dynamic_block_queue.push(block_b_99);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_99) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_99);
        /* execute.simd:3034 [D] s_b_99_0 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_99_0 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_99_1 = constant u8 1 (const) */
        /* execute.simd:3034 [D] s_b_99_0[s_b_99_1] */
        auto s_b_99_2 = emitter.vector_extract(s_b_99_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3034 [F] s_b_99_3 = constant s32 0 (const) */
        /* execute.simd:3034 [D] s_b_99_4 = (s32)s_b_99_2 */
        auto s_b_99_4 = emitter.sx(s_b_99_2, emitter.context().types().s32());
        /* execute.simd:3034 [D] s_b_99_5 = s_b_99_4<s_b_99_3 */
        auto s_b_99_5 = emitter.cmp_lt(s_b_99_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3034 [D] s_b_99_6: If s_b_99_5: Jump b_101 else b_103 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_101;
            dynamic_block_queue.push(block_b_101);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_103;
            dynamic_block_queue.push(block_b_103);
            false_target = block;
          }
          emitter.branch(s_b_99_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_100) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_100);
        /* execute.simd:3037 [D] s_b_100_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_100_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_100_1 = constant u8 0 (const) */
        /* execute.simd:3037 [D] s_b_100_0[s_b_100_1] */
        auto s_b_100_2 = emitter.vector_extract(s_b_100_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3037 [D] s_b_100_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_100_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_100_4 = constant u8 0 (const) */
        /* execute.simd:3037 [D] s_b_100_3[s_b_100_4] */
        auto s_b_100_5 = emitter.vector_extract(s_b_100_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3037 [D] s_b_100_6 = (u16)s_b_100_5 */
        auto s_b_100_6 = emitter.reinterpret(s_b_100_5, emitter.context().types().u16());
        /* execute.simd:3037 [D] s_b_100_7 = s_b_100_2<<s_b_100_6 */
        auto s_b_100_7 = emitter.shl(s_b_100_2, s_b_100_6);
        /* execute.simd:3037 [F] s_b_100_8 = sym_42889_0_rd (const) wutils::Vector<uint16_t, 8> */
        wutils::Vector<uint16_t, 8> s_b_100_8 = CV_sym_42889_0_rd;
        /* execute.simd:3037 [F] s_b_100_9 = constant s32 0 (const) */
        /* execute.simd:3037 [D] s_b_100_10 = s_b_100_8[s_b_100_9] <= s_b_100_7 */
        auto s_b_100_10 = emitter.vector_insert(emitter.constant_vector_splat(s_b_100_8[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_100_7);
        /* execute.simd:3037 [D] s_b_100_11: sym_42889_0_rd = s_b_100_10, dominates: s_b_101_9 s_b_103_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_100_10);
        /* execute.simd:3037 [F] s_b_100_12: Jump b_99 (const) */
        {
          auto block = block_b_99;
          dynamic_block_queue.push(block_b_99);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_101) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_101);
        /* execute.simd:3035 [D] s_b_101_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_101_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_101_1 = constant u8 1 (const) */
        /* execute.simd:3035 [D] s_b_101_0[s_b_101_1] */
        auto s_b_101_2 = emitter.vector_extract(s_b_101_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3035 [D] s_b_101_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_101_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_101_4 = constant u8 1 (const) */
        /* execute.simd:3035 [D] s_b_101_3[s_b_101_4] */
        auto s_b_101_5 = emitter.vector_extract(s_b_101_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3035 [D] s_b_101_6 = -s_b_101_5 */
        auto s_b_101_6 = emitter.neg(s_b_101_5);
        /* execute.simd:3035 [D] s_b_101_7 = (u16)s_b_101_6 */
        auto s_b_101_7 = emitter.reinterpret(s_b_101_6, emitter.context().types().u16());
        /* execute.simd:3035 [D] s_b_101_8 = s_b_101_2>>s_b_101_7 */
        auto s_b_101_8 = emitter.shr(s_b_101_2, s_b_101_7);
        /* execute.simd:3035 [D] s_b_101_9 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_101_9 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3035 [F] s_b_101_10 = constant s32 1 (const) */
        /* execute.simd:3035 [D] s_b_101_11 = s_b_101_9[s_b_101_10] <= s_b_101_8 */
        auto s_b_101_11 = emitter.vector_insert(s_b_101_9, emitter.const_s32((int32_t)1ULL), s_b_101_8);
        /* execute.simd:3035 [D] s_b_101_12: sym_42889_0_rd = s_b_101_11, dominates: s_b_104_9 s_b_106_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_101_11);
        /* execute.simd:3035 [F] s_b_101_13: Jump b_102 (const) */
        {
          auto block = block_b_102;
          dynamic_block_queue.push(block_b_102);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_102) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_102);
        /* execute.simd:3034 [D] s_b_102_0 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_102_0 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_102_1 = constant u8 2 (const) */
        /* execute.simd:3034 [D] s_b_102_0[s_b_102_1] */
        auto s_b_102_2 = emitter.vector_extract(s_b_102_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3034 [F] s_b_102_3 = constant s32 0 (const) */
        /* execute.simd:3034 [D] s_b_102_4 = (s32)s_b_102_2 */
        auto s_b_102_4 = emitter.sx(s_b_102_2, emitter.context().types().s32());
        /* execute.simd:3034 [D] s_b_102_5 = s_b_102_4<s_b_102_3 */
        auto s_b_102_5 = emitter.cmp_lt(s_b_102_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3034 [D] s_b_102_6: If s_b_102_5: Jump b_104 else b_106 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_104;
            dynamic_block_queue.push(block_b_104);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_106;
            dynamic_block_queue.push(block_b_106);
            false_target = block;
          }
          emitter.branch(s_b_102_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_103) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_103);
        /* execute.simd:3037 [D] s_b_103_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_103_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_103_1 = constant u8 1 (const) */
        /* execute.simd:3037 [D] s_b_103_0[s_b_103_1] */
        auto s_b_103_2 = emitter.vector_extract(s_b_103_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3037 [D] s_b_103_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_103_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_103_4 = constant u8 1 (const) */
        /* execute.simd:3037 [D] s_b_103_3[s_b_103_4] */
        auto s_b_103_5 = emitter.vector_extract(s_b_103_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3037 [D] s_b_103_6 = (u16)s_b_103_5 */
        auto s_b_103_6 = emitter.reinterpret(s_b_103_5, emitter.context().types().u16());
        /* execute.simd:3037 [D] s_b_103_7 = s_b_103_2<<s_b_103_6 */
        auto s_b_103_7 = emitter.shl(s_b_103_2, s_b_103_6);
        /* execute.simd:3037 [D] s_b_103_8 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_103_8 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3037 [F] s_b_103_9 = constant s32 1 (const) */
        /* execute.simd:3037 [D] s_b_103_10 = s_b_103_8[s_b_103_9] <= s_b_103_7 */
        auto s_b_103_10 = emitter.vector_insert(s_b_103_8, emitter.const_s32((int32_t)1ULL), s_b_103_7);
        /* execute.simd:3037 [D] s_b_103_11: sym_42889_0_rd = s_b_103_10, dominates: s_b_104_9 s_b_106_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_103_10);
        /* execute.simd:3037 [F] s_b_103_12: Jump b_102 (const) */
        {
          auto block = block_b_102;
          dynamic_block_queue.push(block_b_102);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_104) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_104);
        /* execute.simd:3035 [D] s_b_104_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_104_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_104_1 = constant u8 2 (const) */
        /* execute.simd:3035 [D] s_b_104_0[s_b_104_1] */
        auto s_b_104_2 = emitter.vector_extract(s_b_104_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3035 [D] s_b_104_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_104_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_104_4 = constant u8 2 (const) */
        /* execute.simd:3035 [D] s_b_104_3[s_b_104_4] */
        auto s_b_104_5 = emitter.vector_extract(s_b_104_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3035 [D] s_b_104_6 = -s_b_104_5 */
        auto s_b_104_6 = emitter.neg(s_b_104_5);
        /* execute.simd:3035 [D] s_b_104_7 = (u16)s_b_104_6 */
        auto s_b_104_7 = emitter.reinterpret(s_b_104_6, emitter.context().types().u16());
        /* execute.simd:3035 [D] s_b_104_8 = s_b_104_2>>s_b_104_7 */
        auto s_b_104_8 = emitter.shr(s_b_104_2, s_b_104_7);
        /* execute.simd:3035 [D] s_b_104_9 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_104_9 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3035 [F] s_b_104_10 = constant s32 2 (const) */
        /* execute.simd:3035 [D] s_b_104_11 = s_b_104_9[s_b_104_10] <= s_b_104_8 */
        auto s_b_104_11 = emitter.vector_insert(s_b_104_9, emitter.const_s32((int32_t)2ULL), s_b_104_8);
        /* execute.simd:3035 [D] s_b_104_12: sym_42889_0_rd = s_b_104_11, dominates: s_b_107_9 s_b_109_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_104_11);
        /* execute.simd:3035 [F] s_b_104_13: Jump b_105 (const) */
        {
          auto block = block_b_105;
          dynamic_block_queue.push(block_b_105);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_105) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_105);
        /* execute.simd:3034 [D] s_b_105_0 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_105_0 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_105_1 = constant u8 3 (const) */
        /* execute.simd:3034 [D] s_b_105_0[s_b_105_1] */
        auto s_b_105_2 = emitter.vector_extract(s_b_105_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3034 [F] s_b_105_3 = constant s32 0 (const) */
        /* execute.simd:3034 [D] s_b_105_4 = (s32)s_b_105_2 */
        auto s_b_105_4 = emitter.sx(s_b_105_2, emitter.context().types().s32());
        /* execute.simd:3034 [D] s_b_105_5 = s_b_105_4<s_b_105_3 */
        auto s_b_105_5 = emitter.cmp_lt(s_b_105_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3034 [D] s_b_105_6: If s_b_105_5: Jump b_107 else b_109 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_107;
            dynamic_block_queue.push(block_b_107);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_109;
            dynamic_block_queue.push(block_b_109);
            false_target = block;
          }
          emitter.branch(s_b_105_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_106) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_106);
        /* execute.simd:3037 [D] s_b_106_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_106_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_106_1 = constant u8 2 (const) */
        /* execute.simd:3037 [D] s_b_106_0[s_b_106_1] */
        auto s_b_106_2 = emitter.vector_extract(s_b_106_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3037 [D] s_b_106_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_106_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_106_4 = constant u8 2 (const) */
        /* execute.simd:3037 [D] s_b_106_3[s_b_106_4] */
        auto s_b_106_5 = emitter.vector_extract(s_b_106_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3037 [D] s_b_106_6 = (u16)s_b_106_5 */
        auto s_b_106_6 = emitter.reinterpret(s_b_106_5, emitter.context().types().u16());
        /* execute.simd:3037 [D] s_b_106_7 = s_b_106_2<<s_b_106_6 */
        auto s_b_106_7 = emitter.shl(s_b_106_2, s_b_106_6);
        /* execute.simd:3037 [D] s_b_106_8 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_106_8 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3037 [F] s_b_106_9 = constant s32 2 (const) */
        /* execute.simd:3037 [D] s_b_106_10 = s_b_106_8[s_b_106_9] <= s_b_106_7 */
        auto s_b_106_10 = emitter.vector_insert(s_b_106_8, emitter.const_s32((int32_t)2ULL), s_b_106_7);
        /* execute.simd:3037 [D] s_b_106_11: sym_42889_0_rd = s_b_106_10, dominates: s_b_107_9 s_b_109_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_106_10);
        /* execute.simd:3037 [F] s_b_106_12: Jump b_105 (const) */
        {
          auto block = block_b_105;
          dynamic_block_queue.push(block_b_105);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_107) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_107);
        /* execute.simd:3035 [D] s_b_107_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_107_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_107_1 = constant u8 3 (const) */
        /* execute.simd:3035 [D] s_b_107_0[s_b_107_1] */
        auto s_b_107_2 = emitter.vector_extract(s_b_107_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3035 [D] s_b_107_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_107_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_107_4 = constant u8 3 (const) */
        /* execute.simd:3035 [D] s_b_107_3[s_b_107_4] */
        auto s_b_107_5 = emitter.vector_extract(s_b_107_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3035 [D] s_b_107_6 = -s_b_107_5 */
        auto s_b_107_6 = emitter.neg(s_b_107_5);
        /* execute.simd:3035 [D] s_b_107_7 = (u16)s_b_107_6 */
        auto s_b_107_7 = emitter.reinterpret(s_b_107_6, emitter.context().types().u16());
        /* execute.simd:3035 [D] s_b_107_8 = s_b_107_2>>s_b_107_7 */
        auto s_b_107_8 = emitter.shr(s_b_107_2, s_b_107_7);
        /* execute.simd:3035 [D] s_b_107_9 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_107_9 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3035 [F] s_b_107_10 = constant s32 3 (const) */
        /* execute.simd:3035 [D] s_b_107_11 = s_b_107_9[s_b_107_10] <= s_b_107_8 */
        auto s_b_107_11 = emitter.vector_insert(s_b_107_9, emitter.const_s32((int32_t)3ULL), s_b_107_8);
        /* execute.simd:3035 [D] s_b_107_12: sym_42889_0_rd = s_b_107_11, dominates: s_b_110_9 s_b_112_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_107_11);
        /* execute.simd:3035 [F] s_b_107_13: Jump b_108 (const) */
        {
          auto block = block_b_108;
          dynamic_block_queue.push(block_b_108);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_108) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_108);
        /* execute.simd:3034 [D] s_b_108_0 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_108_0 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_108_1 = constant u8 4 (const) */
        /* execute.simd:3034 [D] s_b_108_0[s_b_108_1] */
        auto s_b_108_2 = emitter.vector_extract(s_b_108_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3034 [F] s_b_108_3 = constant s32 0 (const) */
        /* execute.simd:3034 [D] s_b_108_4 = (s32)s_b_108_2 */
        auto s_b_108_4 = emitter.sx(s_b_108_2, emitter.context().types().s32());
        /* execute.simd:3034 [D] s_b_108_5 = s_b_108_4<s_b_108_3 */
        auto s_b_108_5 = emitter.cmp_lt(s_b_108_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3034 [D] s_b_108_6: If s_b_108_5: Jump b_110 else b_112 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_110;
            dynamic_block_queue.push(block_b_110);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_112;
            dynamic_block_queue.push(block_b_112);
            false_target = block;
          }
          emitter.branch(s_b_108_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_109) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_109);
        /* execute.simd:3037 [D] s_b_109_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_109_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_109_1 = constant u8 3 (const) */
        /* execute.simd:3037 [D] s_b_109_0[s_b_109_1] */
        auto s_b_109_2 = emitter.vector_extract(s_b_109_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3037 [D] s_b_109_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_109_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_109_4 = constant u8 3 (const) */
        /* execute.simd:3037 [D] s_b_109_3[s_b_109_4] */
        auto s_b_109_5 = emitter.vector_extract(s_b_109_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3037 [D] s_b_109_6 = (u16)s_b_109_5 */
        auto s_b_109_6 = emitter.reinterpret(s_b_109_5, emitter.context().types().u16());
        /* execute.simd:3037 [D] s_b_109_7 = s_b_109_2<<s_b_109_6 */
        auto s_b_109_7 = emitter.shl(s_b_109_2, s_b_109_6);
        /* execute.simd:3037 [D] s_b_109_8 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_109_8 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3037 [F] s_b_109_9 = constant s32 3 (const) */
        /* execute.simd:3037 [D] s_b_109_10 = s_b_109_8[s_b_109_9] <= s_b_109_7 */
        auto s_b_109_10 = emitter.vector_insert(s_b_109_8, emitter.const_s32((int32_t)3ULL), s_b_109_7);
        /* execute.simd:3037 [D] s_b_109_11: sym_42889_0_rd = s_b_109_10, dominates: s_b_110_9 s_b_112_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_109_10);
        /* execute.simd:3037 [F] s_b_109_12: Jump b_108 (const) */
        {
          auto block = block_b_108;
          dynamic_block_queue.push(block_b_108);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_110) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_110);
        /* execute.simd:3035 [D] s_b_110_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_110_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_110_1 = constant u8 4 (const) */
        /* execute.simd:3035 [D] s_b_110_0[s_b_110_1] */
        auto s_b_110_2 = emitter.vector_extract(s_b_110_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3035 [D] s_b_110_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_110_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_110_4 = constant u8 4 (const) */
        /* execute.simd:3035 [D] s_b_110_3[s_b_110_4] */
        auto s_b_110_5 = emitter.vector_extract(s_b_110_3, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3035 [D] s_b_110_6 = -s_b_110_5 */
        auto s_b_110_6 = emitter.neg(s_b_110_5);
        /* execute.simd:3035 [D] s_b_110_7 = (u16)s_b_110_6 */
        auto s_b_110_7 = emitter.reinterpret(s_b_110_6, emitter.context().types().u16());
        /* execute.simd:3035 [D] s_b_110_8 = s_b_110_2>>s_b_110_7 */
        auto s_b_110_8 = emitter.shr(s_b_110_2, s_b_110_7);
        /* execute.simd:3035 [D] s_b_110_9 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_110_9 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3035 [F] s_b_110_10 = constant s32 4 (const) */
        /* execute.simd:3035 [D] s_b_110_11 = s_b_110_9[s_b_110_10] <= s_b_110_8 */
        auto s_b_110_11 = emitter.vector_insert(s_b_110_9, emitter.const_s32((int32_t)4ULL), s_b_110_8);
        /* execute.simd:3035 [D] s_b_110_12: sym_42889_0_rd = s_b_110_11, dominates: s_b_113_9 s_b_115_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_110_11);
        /* execute.simd:3035 [F] s_b_110_13: Jump b_111 (const) */
        {
          auto block = block_b_111;
          dynamic_block_queue.push(block_b_111);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_111) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_111);
        /* execute.simd:3034 [D] s_b_111_0 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_111_0 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_111_1 = constant u8 5 (const) */
        /* execute.simd:3034 [D] s_b_111_0[s_b_111_1] */
        auto s_b_111_2 = emitter.vector_extract(s_b_111_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3034 [F] s_b_111_3 = constant s32 0 (const) */
        /* execute.simd:3034 [D] s_b_111_4 = (s32)s_b_111_2 */
        auto s_b_111_4 = emitter.sx(s_b_111_2, emitter.context().types().s32());
        /* execute.simd:3034 [D] s_b_111_5 = s_b_111_4<s_b_111_3 */
        auto s_b_111_5 = emitter.cmp_lt(s_b_111_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3034 [D] s_b_111_6: If s_b_111_5: Jump b_113 else b_115 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_113;
            dynamic_block_queue.push(block_b_113);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_115;
            dynamic_block_queue.push(block_b_115);
            false_target = block;
          }
          emitter.branch(s_b_111_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_112) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_112);
        /* execute.simd:3037 [D] s_b_112_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_112_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_112_1 = constant u8 4 (const) */
        /* execute.simd:3037 [D] s_b_112_0[s_b_112_1] */
        auto s_b_112_2 = emitter.vector_extract(s_b_112_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3037 [D] s_b_112_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_112_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_112_4 = constant u8 4 (const) */
        /* execute.simd:3037 [D] s_b_112_3[s_b_112_4] */
        auto s_b_112_5 = emitter.vector_extract(s_b_112_3, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:3037 [D] s_b_112_6 = (u16)s_b_112_5 */
        auto s_b_112_6 = emitter.reinterpret(s_b_112_5, emitter.context().types().u16());
        /* execute.simd:3037 [D] s_b_112_7 = s_b_112_2<<s_b_112_6 */
        auto s_b_112_7 = emitter.shl(s_b_112_2, s_b_112_6);
        /* execute.simd:3037 [D] s_b_112_8 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_112_8 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3037 [F] s_b_112_9 = constant s32 4 (const) */
        /* execute.simd:3037 [D] s_b_112_10 = s_b_112_8[s_b_112_9] <= s_b_112_7 */
        auto s_b_112_10 = emitter.vector_insert(s_b_112_8, emitter.const_s32((int32_t)4ULL), s_b_112_7);
        /* execute.simd:3037 [D] s_b_112_11: sym_42889_0_rd = s_b_112_10, dominates: s_b_113_9 s_b_115_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_112_10);
        /* execute.simd:3037 [F] s_b_112_12: Jump b_111 (const) */
        {
          auto block = block_b_111;
          dynamic_block_queue.push(block_b_111);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_113) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_113);
        /* execute.simd:3035 [D] s_b_113_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_113_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_113_1 = constant u8 5 (const) */
        /* execute.simd:3035 [D] s_b_113_0[s_b_113_1] */
        auto s_b_113_2 = emitter.vector_extract(s_b_113_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3035 [D] s_b_113_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_113_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_113_4 = constant u8 5 (const) */
        /* execute.simd:3035 [D] s_b_113_3[s_b_113_4] */
        auto s_b_113_5 = emitter.vector_extract(s_b_113_3, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3035 [D] s_b_113_6 = -s_b_113_5 */
        auto s_b_113_6 = emitter.neg(s_b_113_5);
        /* execute.simd:3035 [D] s_b_113_7 = (u16)s_b_113_6 */
        auto s_b_113_7 = emitter.reinterpret(s_b_113_6, emitter.context().types().u16());
        /* execute.simd:3035 [D] s_b_113_8 = s_b_113_2>>s_b_113_7 */
        auto s_b_113_8 = emitter.shr(s_b_113_2, s_b_113_7);
        /* execute.simd:3035 [D] s_b_113_9 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_113_9 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3035 [F] s_b_113_10 = constant s32 5 (const) */
        /* execute.simd:3035 [D] s_b_113_11 = s_b_113_9[s_b_113_10] <= s_b_113_8 */
        auto s_b_113_11 = emitter.vector_insert(s_b_113_9, emitter.const_s32((int32_t)5ULL), s_b_113_8);
        /* execute.simd:3035 [D] s_b_113_12: sym_42889_0_rd = s_b_113_11, dominates: s_b_116_9 s_b_118_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_113_11);
        /* execute.simd:3035 [F] s_b_113_13: Jump b_114 (const) */
        {
          auto block = block_b_114;
          dynamic_block_queue.push(block_b_114);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_114) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_114);
        /* execute.simd:3034 [D] s_b_114_0 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_114_0 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_114_1 = constant u8 6 (const) */
        /* execute.simd:3034 [D] s_b_114_0[s_b_114_1] */
        auto s_b_114_2 = emitter.vector_extract(s_b_114_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3034 [F] s_b_114_3 = constant s32 0 (const) */
        /* execute.simd:3034 [D] s_b_114_4 = (s32)s_b_114_2 */
        auto s_b_114_4 = emitter.sx(s_b_114_2, emitter.context().types().s32());
        /* execute.simd:3034 [D] s_b_114_5 = s_b_114_4<s_b_114_3 */
        auto s_b_114_5 = emitter.cmp_lt(s_b_114_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3034 [D] s_b_114_6: If s_b_114_5: Jump b_116 else b_118 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_116;
            dynamic_block_queue.push(block_b_116);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_118;
            dynamic_block_queue.push(block_b_118);
            false_target = block;
          }
          emitter.branch(s_b_114_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_115) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_115);
        /* execute.simd:3037 [D] s_b_115_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_115_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_115_1 = constant u8 5 (const) */
        /* execute.simd:3037 [D] s_b_115_0[s_b_115_1] */
        auto s_b_115_2 = emitter.vector_extract(s_b_115_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3037 [D] s_b_115_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_115_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_115_4 = constant u8 5 (const) */
        /* execute.simd:3037 [D] s_b_115_3[s_b_115_4] */
        auto s_b_115_5 = emitter.vector_extract(s_b_115_3, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:3037 [D] s_b_115_6 = (u16)s_b_115_5 */
        auto s_b_115_6 = emitter.reinterpret(s_b_115_5, emitter.context().types().u16());
        /* execute.simd:3037 [D] s_b_115_7 = s_b_115_2<<s_b_115_6 */
        auto s_b_115_7 = emitter.shl(s_b_115_2, s_b_115_6);
        /* execute.simd:3037 [D] s_b_115_8 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_115_8 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3037 [F] s_b_115_9 = constant s32 5 (const) */
        /* execute.simd:3037 [D] s_b_115_10 = s_b_115_8[s_b_115_9] <= s_b_115_7 */
        auto s_b_115_10 = emitter.vector_insert(s_b_115_8, emitter.const_s32((int32_t)5ULL), s_b_115_7);
        /* execute.simd:3037 [D] s_b_115_11: sym_42889_0_rd = s_b_115_10, dominates: s_b_116_9 s_b_118_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_115_10);
        /* execute.simd:3037 [F] s_b_115_12: Jump b_114 (const) */
        {
          auto block = block_b_114;
          dynamic_block_queue.push(block_b_114);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_116) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_116);
        /* execute.simd:3035 [D] s_b_116_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_116_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_116_1 = constant u8 6 (const) */
        /* execute.simd:3035 [D] s_b_116_0[s_b_116_1] */
        auto s_b_116_2 = emitter.vector_extract(s_b_116_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3035 [D] s_b_116_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_116_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_116_4 = constant u8 6 (const) */
        /* execute.simd:3035 [D] s_b_116_3[s_b_116_4] */
        auto s_b_116_5 = emitter.vector_extract(s_b_116_3, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3035 [D] s_b_116_6 = -s_b_116_5 */
        auto s_b_116_6 = emitter.neg(s_b_116_5);
        /* execute.simd:3035 [D] s_b_116_7 = (u16)s_b_116_6 */
        auto s_b_116_7 = emitter.reinterpret(s_b_116_6, emitter.context().types().u16());
        /* execute.simd:3035 [D] s_b_116_8 = s_b_116_2>>s_b_116_7 */
        auto s_b_116_8 = emitter.shr(s_b_116_2, s_b_116_7);
        /* execute.simd:3035 [D] s_b_116_9 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_116_9 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3035 [F] s_b_116_10 = constant s32 6 (const) */
        /* execute.simd:3035 [D] s_b_116_11 = s_b_116_9[s_b_116_10] <= s_b_116_8 */
        auto s_b_116_11 = emitter.vector_insert(s_b_116_9, emitter.const_s32((int32_t)6ULL), s_b_116_8);
        /* execute.simd:3035 [D] s_b_116_12: sym_42889_0_rd = s_b_116_11, dominates: s_b_119_9 s_b_121_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_116_11);
        /* execute.simd:3035 [F] s_b_116_13: Jump b_117 (const) */
        {
          auto block = block_b_117;
          dynamic_block_queue.push(block_b_117);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_117) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_117);
        /* execute.simd:3034 [D] s_b_117_0 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_117_0 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_117_1 = constant u8 7 (const) */
        /* execute.simd:3034 [D] s_b_117_0[s_b_117_1] */
        auto s_b_117_2 = emitter.vector_extract(s_b_117_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3034 [F] s_b_117_3 = constant s32 0 (const) */
        /* execute.simd:3034 [D] s_b_117_4 = (s32)s_b_117_2 */
        auto s_b_117_4 = emitter.sx(s_b_117_2, emitter.context().types().s32());
        /* execute.simd:3034 [D] s_b_117_5 = s_b_117_4<s_b_117_3 */
        auto s_b_117_5 = emitter.cmp_lt(s_b_117_4, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3034 [D] s_b_117_6: If s_b_117_5: Jump b_119 else b_121 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_119;
            dynamic_block_queue.push(block_b_119);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_121;
            dynamic_block_queue.push(block_b_121);
            false_target = block;
          }
          emitter.branch(s_b_117_5, true_target, false_target);
        }
      }
      else if (block_index == block_b_118) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_118);
        /* execute.simd:3037 [D] s_b_118_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_118_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_118_1 = constant u8 6 (const) */
        /* execute.simd:3037 [D] s_b_118_0[s_b_118_1] */
        auto s_b_118_2 = emitter.vector_extract(s_b_118_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3037 [D] s_b_118_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_118_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_118_4 = constant u8 6 (const) */
        /* execute.simd:3037 [D] s_b_118_3[s_b_118_4] */
        auto s_b_118_5 = emitter.vector_extract(s_b_118_3, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:3037 [D] s_b_118_6 = (u16)s_b_118_5 */
        auto s_b_118_6 = emitter.reinterpret(s_b_118_5, emitter.context().types().u16());
        /* execute.simd:3037 [D] s_b_118_7 = s_b_118_2<<s_b_118_6 */
        auto s_b_118_7 = emitter.shl(s_b_118_2, s_b_118_6);
        /* execute.simd:3037 [D] s_b_118_8 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_118_8 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3037 [F] s_b_118_9 = constant s32 6 (const) */
        /* execute.simd:3037 [D] s_b_118_10 = s_b_118_8[s_b_118_9] <= s_b_118_7 */
        auto s_b_118_10 = emitter.vector_insert(s_b_118_8, emitter.const_s32((int32_t)6ULL), s_b_118_7);
        /* execute.simd:3037 [D] s_b_118_11: sym_42889_0_rd = s_b_118_10, dominates: s_b_119_9 s_b_121_8  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_118_10);
        /* execute.simd:3037 [F] s_b_118_12: Jump b_117 (const) */
        {
          auto block = block_b_117;
          dynamic_block_queue.push(block_b_117);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_119) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_119);
        /* execute.simd:3035 [D] s_b_119_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_119_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_119_1 = constant u8 7 (const) */
        /* execute.simd:3035 [D] s_b_119_0[s_b_119_1] */
        auto s_b_119_2 = emitter.vector_extract(s_b_119_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3035 [D] s_b_119_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_119_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_119_4 = constant u8 7 (const) */
        /* execute.simd:3035 [D] s_b_119_3[s_b_119_4] */
        auto s_b_119_5 = emitter.vector_extract(s_b_119_3, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3035 [D] s_b_119_6 = -s_b_119_5 */
        auto s_b_119_6 = emitter.neg(s_b_119_5);
        /* execute.simd:3035 [D] s_b_119_7 = (u16)s_b_119_6 */
        auto s_b_119_7 = emitter.reinterpret(s_b_119_6, emitter.context().types().u16());
        /* execute.simd:3035 [D] s_b_119_8 = s_b_119_2>>s_b_119_7 */
        auto s_b_119_8 = emitter.shr(s_b_119_2, s_b_119_7);
        /* execute.simd:3035 [D] s_b_119_9 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_119_9 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3035 [F] s_b_119_10 = constant s32 7 (const) */
        /* execute.simd:3035 [D] s_b_119_11 = s_b_119_9[s_b_119_10] <= s_b_119_8 */
        auto s_b_119_11 = emitter.vector_insert(s_b_119_9, emitter.const_s32((int32_t)7ULL), s_b_119_8);
        /* execute.simd:3035 [D] s_b_119_12: sym_42889_0_rd = s_b_119_11, dominates: s_b_120_1  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_119_11);
        /* execute.simd:3035 [F] s_b_119_13: Jump b_120 (const) */
        {
          auto block = block_b_120;
          dynamic_block_queue.push(block_b_120);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_120) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_120);
        /* execute.simd:3041 [F] s_b_120_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:3041 [D] s_b_120_1 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_120_1 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3041 [D] s_b_120_2: WriteRegBank 18:s_b_120_0 = s_b_120_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_120_1,emitter.const_u8(16));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_120_1);
        /* execute.simd:0 [F] s_b_120_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_121) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_121);
        /* execute.simd:3037 [D] s_b_121_0 = sym_42880_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_121_0 = emitter.load_local(DV_sym_42880_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_121_1 = constant u8 7 (const) */
        /* execute.simd:3037 [D] s_b_121_0[s_b_121_1] */
        auto s_b_121_2 = emitter.vector_extract(s_b_121_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3037 [D] s_b_121_3 = sym_42884_0_rm wutils::Vector<int16_t, 8> */
        auto s_b_121_3 = emitter.load_local(DV_sym_42884_0_rm, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_121_4 = constant u8 7 (const) */
        /* execute.simd:3037 [D] s_b_121_3[s_b_121_4] */
        auto s_b_121_5 = emitter.vector_extract(s_b_121_3, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:3037 [D] s_b_121_6 = (u16)s_b_121_5 */
        auto s_b_121_6 = emitter.reinterpret(s_b_121_5, emitter.context().types().u16());
        /* execute.simd:3037 [D] s_b_121_7 = s_b_121_2<<s_b_121_6 */
        auto s_b_121_7 = emitter.shl(s_b_121_2, s_b_121_6);
        /* execute.simd:3037 [D] s_b_121_8 = sym_42889_0_rd wutils::Vector<uint16_t, 8> */
        auto s_b_121_8 = emitter.load_local(DV_sym_42889_0_rd, emitter.context().types().v8u16());
        /* execute.simd:3037 [F] s_b_121_9 = constant s32 7 (const) */
        /* execute.simd:3037 [D] s_b_121_10 = s_b_121_8[s_b_121_9] <= s_b_121_7 */
        auto s_b_121_10 = emitter.vector_insert(s_b_121_8, emitter.const_s32((int32_t)7ULL), s_b_121_7);
        /* execute.simd:3037 [D] s_b_121_11: sym_42889_0_rd = s_b_121_10, dominates: s_b_120_1  */
        emitter.store_local(DV_sym_42889_0_rd, s_b_121_10);
        /* execute.simd:3037 [F] s_b_121_12: Jump b_120 (const) */
        {
          auto block = block_b_120;
          dynamic_block_queue.push(block_b_120);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_123) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_123);
        /* execute.simd:3051 [D] s_b_123_0 = sym_43286_0_rn wutils::Vector<uint32_t, 2> */
        auto s_b_123_0 = emitter.load_local(DV_sym_43286_0_rn, emitter.context().types().v2u32());
        /* ???:4294967295 [F] s_b_123_1 = constant u8 0 (const) */
        /* execute.simd:3051 [D] s_b_123_0[s_b_123_1] */
        auto s_b_123_2 = emitter.vector_extract(s_b_123_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3051 [D] s_b_123_3 = sym_43290_0_rm wutils::Vector<int32_t, 2> */
        auto s_b_123_3 = emitter.load_local(DV_sym_43290_0_rm, emitter.context().types().v2s32());
        /* ???:4294967295 [F] s_b_123_4 = constant u8 0 (const) */
        /* execute.simd:3051 [D] s_b_123_3[s_b_123_4] */
        auto s_b_123_5 = emitter.vector_extract(s_b_123_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3051 [D] s_b_123_6 = -s_b_123_5 */
        auto s_b_123_6 = emitter.neg(s_b_123_5);
        /* execute.simd:3051 [D] s_b_123_7 = (u32)s_b_123_6 */
        auto s_b_123_7 = emitter.reinterpret(s_b_123_6, emitter.context().types().u32());
        /* execute.simd:3051 [D] s_b_123_8 = s_b_123_2>>s_b_123_7 */
        auto s_b_123_8 = emitter.shr(s_b_123_2, s_b_123_7);
        /* execute.simd:3051 [F] s_b_123_9 = sym_43295_0_rd (const) wutils::Vector<uint32_t, 4> */
        wutils::Vector<uint32_t, 4> s_b_123_9 = CV_sym_43295_0_rd;
        /* execute.simd:3051 [F] s_b_123_10 = constant s32 0 (const) */
        /* execute.simd:3051 [D] s_b_123_11 = s_b_123_9[s_b_123_10] <= s_b_123_8 */
        auto s_b_123_11 = emitter.vector_insert(emitter.constant_vector_splat(s_b_123_9[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_123_8);
        /* execute.simd:3051 [D] s_b_123_12: sym_43295_0_rd = s_b_123_11, dominates: s_b_126_9 s_b_128_8  */
        emitter.store_local(DV_sym_43295_0_rd, s_b_123_11);
        /* execute.simd:3051 [F] s_b_123_13: Jump b_124 (const) */
        {
          auto block = block_b_124;
          dynamic_block_queue.push(block_b_124);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_124) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_124);
        /* execute.simd:3050 [D] s_b_124_0 = sym_43290_0_rm wutils::Vector<int32_t, 2> */
        auto s_b_124_0 = emitter.load_local(DV_sym_43290_0_rm, emitter.context().types().v2s32());
        /* ???:4294967295 [F] s_b_124_1 = constant u8 1 (const) */
        /* execute.simd:3050 [D] s_b_124_0[s_b_124_1] */
        auto s_b_124_2 = emitter.vector_extract(s_b_124_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3050 [F] s_b_124_3 = constant s32 0 (const) */
        /* execute.simd:3050 [D] s_b_124_4 = s_b_124_2<s_b_124_3 */
        auto s_b_124_4 = emitter.cmp_lt(s_b_124_2, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3050 [D] s_b_124_5: If s_b_124_4: Jump b_126 else b_128 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_126;
            dynamic_block_queue.push(block_b_126);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_128;
            dynamic_block_queue.push(block_b_128);
            false_target = block;
          }
          emitter.branch(s_b_124_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_125) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_125);
        /* execute.simd:3053 [D] s_b_125_0 = sym_43286_0_rn wutils::Vector<uint32_t, 2> */
        auto s_b_125_0 = emitter.load_local(DV_sym_43286_0_rn, emitter.context().types().v2u32());
        /* ???:4294967295 [F] s_b_125_1 = constant u8 0 (const) */
        /* execute.simd:3053 [D] s_b_125_0[s_b_125_1] */
        auto s_b_125_2 = emitter.vector_extract(s_b_125_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3053 [D] s_b_125_3 = sym_43290_0_rm wutils::Vector<int32_t, 2> */
        auto s_b_125_3 = emitter.load_local(DV_sym_43290_0_rm, emitter.context().types().v2s32());
        /* ???:4294967295 [F] s_b_125_4 = constant u8 0 (const) */
        /* execute.simd:3053 [D] s_b_125_3[s_b_125_4] */
        auto s_b_125_5 = emitter.vector_extract(s_b_125_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3053 [D] s_b_125_6 = (u32)s_b_125_5 */
        auto s_b_125_6 = emitter.reinterpret(s_b_125_5, emitter.context().types().u32());
        /* execute.simd:3053 [D] s_b_125_7 = s_b_125_2<<s_b_125_6 */
        auto s_b_125_7 = emitter.shl(s_b_125_2, s_b_125_6);
        /* execute.simd:3053 [F] s_b_125_8 = sym_43295_0_rd (const) wutils::Vector<uint32_t, 4> */
        wutils::Vector<uint32_t, 4> s_b_125_8 = CV_sym_43295_0_rd;
        /* execute.simd:3053 [F] s_b_125_9 = constant s32 0 (const) */
        /* execute.simd:3053 [D] s_b_125_10 = s_b_125_8[s_b_125_9] <= s_b_125_7 */
        auto s_b_125_10 = emitter.vector_insert(emitter.constant_vector_splat(s_b_125_8[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_125_7);
        /* execute.simd:3053 [D] s_b_125_11: sym_43295_0_rd = s_b_125_10, dominates: s_b_126_9 s_b_128_8  */
        emitter.store_local(DV_sym_43295_0_rd, s_b_125_10);
        /* execute.simd:3053 [F] s_b_125_12: Jump b_124 (const) */
        {
          auto block = block_b_124;
          dynamic_block_queue.push(block_b_124);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_126) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_126);
        /* execute.simd:3051 [D] s_b_126_0 = sym_43286_0_rn wutils::Vector<uint32_t, 2> */
        auto s_b_126_0 = emitter.load_local(DV_sym_43286_0_rn, emitter.context().types().v2u32());
        /* ???:4294967295 [F] s_b_126_1 = constant u8 1 (const) */
        /* execute.simd:3051 [D] s_b_126_0[s_b_126_1] */
        auto s_b_126_2 = emitter.vector_extract(s_b_126_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3051 [D] s_b_126_3 = sym_43290_0_rm wutils::Vector<int32_t, 2> */
        auto s_b_126_3 = emitter.load_local(DV_sym_43290_0_rm, emitter.context().types().v2s32());
        /* ???:4294967295 [F] s_b_126_4 = constant u8 1 (const) */
        /* execute.simd:3051 [D] s_b_126_3[s_b_126_4] */
        auto s_b_126_5 = emitter.vector_extract(s_b_126_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3051 [D] s_b_126_6 = -s_b_126_5 */
        auto s_b_126_6 = emitter.neg(s_b_126_5);
        /* execute.simd:3051 [D] s_b_126_7 = (u32)s_b_126_6 */
        auto s_b_126_7 = emitter.reinterpret(s_b_126_6, emitter.context().types().u32());
        /* execute.simd:3051 [D] s_b_126_8 = s_b_126_2>>s_b_126_7 */
        auto s_b_126_8 = emitter.shr(s_b_126_2, s_b_126_7);
        /* execute.simd:3051 [D] s_b_126_9 = sym_43295_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_126_9 = emitter.load_local(DV_sym_43295_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3051 [F] s_b_126_10 = constant s32 1 (const) */
        /* execute.simd:3051 [D] s_b_126_11 = s_b_126_9[s_b_126_10] <= s_b_126_8 */
        auto s_b_126_11 = emitter.vector_insert(s_b_126_9, emitter.const_s32((int32_t)1ULL), s_b_126_8);
        /* execute.simd:3051 [D] s_b_126_12: sym_43295_0_rd = s_b_126_11, dominates: s_b_127_1  */
        emitter.store_local(DV_sym_43295_0_rd, s_b_126_11);
        /* execute.simd:3051 [F] s_b_126_13: Jump b_127 (const) */
        {
          auto block = block_b_127;
          dynamic_block_queue.push(block_b_127);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_127) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_127);
        /* execute.simd:3057 [F] s_b_127_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:3057 [D] s_b_127_1 = sym_43295_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_127_1 = emitter.load_local(DV_sym_43295_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3057 [D] s_b_127_2: WriteRegBank 20:s_b_127_0 = s_b_127_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_127_1,emitter.const_u8(16));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_127_1);
        /* execute.simd:0 [F] s_b_127_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_128) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_128);
        /* execute.simd:3053 [D] s_b_128_0 = sym_43286_0_rn wutils::Vector<uint32_t, 2> */
        auto s_b_128_0 = emitter.load_local(DV_sym_43286_0_rn, emitter.context().types().v2u32());
        /* ???:4294967295 [F] s_b_128_1 = constant u8 1 (const) */
        /* execute.simd:3053 [D] s_b_128_0[s_b_128_1] */
        auto s_b_128_2 = emitter.vector_extract(s_b_128_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3053 [D] s_b_128_3 = sym_43290_0_rm wutils::Vector<int32_t, 2> */
        auto s_b_128_3 = emitter.load_local(DV_sym_43290_0_rm, emitter.context().types().v2s32());
        /* ???:4294967295 [F] s_b_128_4 = constant u8 1 (const) */
        /* execute.simd:3053 [D] s_b_128_3[s_b_128_4] */
        auto s_b_128_5 = emitter.vector_extract(s_b_128_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3053 [D] s_b_128_6 = (u32)s_b_128_5 */
        auto s_b_128_6 = emitter.reinterpret(s_b_128_5, emitter.context().types().u32());
        /* execute.simd:3053 [D] s_b_128_7 = s_b_128_2<<s_b_128_6 */
        auto s_b_128_7 = emitter.shl(s_b_128_2, s_b_128_6);
        /* execute.simd:3053 [D] s_b_128_8 = sym_43295_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_128_8 = emitter.load_local(DV_sym_43295_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3053 [F] s_b_128_9 = constant s32 1 (const) */
        /* execute.simd:3053 [D] s_b_128_10 = s_b_128_8[s_b_128_9] <= s_b_128_7 */
        auto s_b_128_10 = emitter.vector_insert(s_b_128_8, emitter.const_s32((int32_t)1ULL), s_b_128_7);
        /* execute.simd:3053 [D] s_b_128_11: sym_43295_0_rd = s_b_128_10, dominates: s_b_127_1  */
        emitter.store_local(DV_sym_43295_0_rd, s_b_128_10);
        /* execute.simd:3053 [F] s_b_128_12: Jump b_127 (const) */
        {
          auto block = block_b_127;
          dynamic_block_queue.push(block_b_127);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_130) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_130);
        /* execute.simd:3067 [D] s_b_130_0 = sym_43402_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_130_0 = emitter.load_local(DV_sym_43402_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_130_1 = constant u8 0 (const) */
        /* execute.simd:3067 [D] s_b_130_0[s_b_130_1] */
        auto s_b_130_2 = emitter.vector_extract(s_b_130_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3067 [D] s_b_130_3 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_130_3 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_130_4 = constant u8 0 (const) */
        /* execute.simd:3067 [D] s_b_130_3[s_b_130_4] */
        auto s_b_130_5 = emitter.vector_extract(s_b_130_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3067 [D] s_b_130_6 = -s_b_130_5 */
        auto s_b_130_6 = emitter.neg(s_b_130_5);
        /* execute.simd:3067 [D] s_b_130_7 = (u32)s_b_130_6 */
        auto s_b_130_7 = emitter.reinterpret(s_b_130_6, emitter.context().types().u32());
        /* execute.simd:3067 [D] s_b_130_8 = s_b_130_2>>s_b_130_7 */
        auto s_b_130_8 = emitter.shr(s_b_130_2, s_b_130_7);
        /* execute.simd:3067 [F] s_b_130_9 = sym_43411_0_rd (const) wutils::Vector<uint32_t, 4> */
        wutils::Vector<uint32_t, 4> s_b_130_9 = CV_sym_43411_0_rd;
        /* execute.simd:3067 [F] s_b_130_10 = constant s32 0 (const) */
        /* execute.simd:3067 [D] s_b_130_11 = s_b_130_9[s_b_130_10] <= s_b_130_8 */
        auto s_b_130_11 = emitter.vector_insert(emitter.constant_vector_splat(s_b_130_9[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_130_8);
        /* execute.simd:3067 [D] s_b_130_12: sym_43411_0_rd = s_b_130_11, dominates: s_b_133_9 s_b_135_8  */
        emitter.store_local(DV_sym_43411_0_rd, s_b_130_11);
        /* execute.simd:3067 [F] s_b_130_13: Jump b_131 (const) */
        {
          auto block = block_b_131;
          dynamic_block_queue.push(block_b_131);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_131) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_131);
        /* execute.simd:3066 [D] s_b_131_0 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_131_0 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_131_1 = constant u8 1 (const) */
        /* execute.simd:3066 [D] s_b_131_0[s_b_131_1] */
        auto s_b_131_2 = emitter.vector_extract(s_b_131_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3066 [F] s_b_131_3 = constant s32 0 (const) */
        /* execute.simd:3066 [D] s_b_131_4 = s_b_131_2<s_b_131_3 */
        auto s_b_131_4 = emitter.cmp_lt(s_b_131_2, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3066 [D] s_b_131_5: If s_b_131_4: Jump b_133 else b_135 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_133;
            dynamic_block_queue.push(block_b_133);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_135;
            dynamic_block_queue.push(block_b_135);
            false_target = block;
          }
          emitter.branch(s_b_131_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_132) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_132);
        /* execute.simd:3069 [D] s_b_132_0 = sym_43402_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_132_0 = emitter.load_local(DV_sym_43402_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_132_1 = constant u8 0 (const) */
        /* execute.simd:3069 [D] s_b_132_0[s_b_132_1] */
        auto s_b_132_2 = emitter.vector_extract(s_b_132_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3069 [D] s_b_132_3 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_132_3 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_132_4 = constant u8 0 (const) */
        /* execute.simd:3069 [D] s_b_132_3[s_b_132_4] */
        auto s_b_132_5 = emitter.vector_extract(s_b_132_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3069 [D] s_b_132_6 = (u32)s_b_132_5 */
        auto s_b_132_6 = emitter.reinterpret(s_b_132_5, emitter.context().types().u32());
        /* execute.simd:3069 [D] s_b_132_7 = s_b_132_2<<s_b_132_6 */
        auto s_b_132_7 = emitter.shl(s_b_132_2, s_b_132_6);
        /* execute.simd:3069 [F] s_b_132_8 = sym_43411_0_rd (const) wutils::Vector<uint32_t, 4> */
        wutils::Vector<uint32_t, 4> s_b_132_8 = CV_sym_43411_0_rd;
        /* execute.simd:3069 [F] s_b_132_9 = constant s32 0 (const) */
        /* execute.simd:3069 [D] s_b_132_10 = s_b_132_8[s_b_132_9] <= s_b_132_7 */
        auto s_b_132_10 = emitter.vector_insert(emitter.constant_vector_splat(s_b_132_8[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_132_7);
        /* execute.simd:3069 [D] s_b_132_11: sym_43411_0_rd = s_b_132_10, dominates: s_b_133_9 s_b_135_8  */
        emitter.store_local(DV_sym_43411_0_rd, s_b_132_10);
        /* execute.simd:3069 [F] s_b_132_12: Jump b_131 (const) */
        {
          auto block = block_b_131;
          dynamic_block_queue.push(block_b_131);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_133) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_133);
        /* execute.simd:3067 [D] s_b_133_0 = sym_43402_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_133_0 = emitter.load_local(DV_sym_43402_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_133_1 = constant u8 1 (const) */
        /* execute.simd:3067 [D] s_b_133_0[s_b_133_1] */
        auto s_b_133_2 = emitter.vector_extract(s_b_133_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3067 [D] s_b_133_3 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_133_3 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_133_4 = constant u8 1 (const) */
        /* execute.simd:3067 [D] s_b_133_3[s_b_133_4] */
        auto s_b_133_5 = emitter.vector_extract(s_b_133_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3067 [D] s_b_133_6 = -s_b_133_5 */
        auto s_b_133_6 = emitter.neg(s_b_133_5);
        /* execute.simd:3067 [D] s_b_133_7 = (u32)s_b_133_6 */
        auto s_b_133_7 = emitter.reinterpret(s_b_133_6, emitter.context().types().u32());
        /* execute.simd:3067 [D] s_b_133_8 = s_b_133_2>>s_b_133_7 */
        auto s_b_133_8 = emitter.shr(s_b_133_2, s_b_133_7);
        /* execute.simd:3067 [D] s_b_133_9 = sym_43411_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_133_9 = emitter.load_local(DV_sym_43411_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3067 [F] s_b_133_10 = constant s32 1 (const) */
        /* execute.simd:3067 [D] s_b_133_11 = s_b_133_9[s_b_133_10] <= s_b_133_8 */
        auto s_b_133_11 = emitter.vector_insert(s_b_133_9, emitter.const_s32((int32_t)1ULL), s_b_133_8);
        /* execute.simd:3067 [D] s_b_133_12: sym_43411_0_rd = s_b_133_11, dominates: s_b_136_9 s_b_138_8  */
        emitter.store_local(DV_sym_43411_0_rd, s_b_133_11);
        /* execute.simd:3067 [F] s_b_133_13: Jump b_134 (const) */
        {
          auto block = block_b_134;
          dynamic_block_queue.push(block_b_134);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_134) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_134);
        /* execute.simd:3066 [D] s_b_134_0 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_134_0 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_134_1 = constant u8 2 (const) */
        /* execute.simd:3066 [D] s_b_134_0[s_b_134_1] */
        auto s_b_134_2 = emitter.vector_extract(s_b_134_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3066 [F] s_b_134_3 = constant s32 0 (const) */
        /* execute.simd:3066 [D] s_b_134_4 = s_b_134_2<s_b_134_3 */
        auto s_b_134_4 = emitter.cmp_lt(s_b_134_2, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3066 [D] s_b_134_5: If s_b_134_4: Jump b_136 else b_138 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_136;
            dynamic_block_queue.push(block_b_136);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_138;
            dynamic_block_queue.push(block_b_138);
            false_target = block;
          }
          emitter.branch(s_b_134_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_135) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_135);
        /* execute.simd:3069 [D] s_b_135_0 = sym_43402_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_135_0 = emitter.load_local(DV_sym_43402_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_135_1 = constant u8 1 (const) */
        /* execute.simd:3069 [D] s_b_135_0[s_b_135_1] */
        auto s_b_135_2 = emitter.vector_extract(s_b_135_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3069 [D] s_b_135_3 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_135_3 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_135_4 = constant u8 1 (const) */
        /* execute.simd:3069 [D] s_b_135_3[s_b_135_4] */
        auto s_b_135_5 = emitter.vector_extract(s_b_135_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3069 [D] s_b_135_6 = (u32)s_b_135_5 */
        auto s_b_135_6 = emitter.reinterpret(s_b_135_5, emitter.context().types().u32());
        /* execute.simd:3069 [D] s_b_135_7 = s_b_135_2<<s_b_135_6 */
        auto s_b_135_7 = emitter.shl(s_b_135_2, s_b_135_6);
        /* execute.simd:3069 [D] s_b_135_8 = sym_43411_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_135_8 = emitter.load_local(DV_sym_43411_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3069 [F] s_b_135_9 = constant s32 1 (const) */
        /* execute.simd:3069 [D] s_b_135_10 = s_b_135_8[s_b_135_9] <= s_b_135_7 */
        auto s_b_135_10 = emitter.vector_insert(s_b_135_8, emitter.const_s32((int32_t)1ULL), s_b_135_7);
        /* execute.simd:3069 [D] s_b_135_11: sym_43411_0_rd = s_b_135_10, dominates: s_b_136_9 s_b_138_8  */
        emitter.store_local(DV_sym_43411_0_rd, s_b_135_10);
        /* execute.simd:3069 [F] s_b_135_12: Jump b_134 (const) */
        {
          auto block = block_b_134;
          dynamic_block_queue.push(block_b_134);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_136) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_136);
        /* execute.simd:3067 [D] s_b_136_0 = sym_43402_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_136_0 = emitter.load_local(DV_sym_43402_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_136_1 = constant u8 2 (const) */
        /* execute.simd:3067 [D] s_b_136_0[s_b_136_1] */
        auto s_b_136_2 = emitter.vector_extract(s_b_136_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3067 [D] s_b_136_3 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_136_3 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_136_4 = constant u8 2 (const) */
        /* execute.simd:3067 [D] s_b_136_3[s_b_136_4] */
        auto s_b_136_5 = emitter.vector_extract(s_b_136_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3067 [D] s_b_136_6 = -s_b_136_5 */
        auto s_b_136_6 = emitter.neg(s_b_136_5);
        /* execute.simd:3067 [D] s_b_136_7 = (u32)s_b_136_6 */
        auto s_b_136_7 = emitter.reinterpret(s_b_136_6, emitter.context().types().u32());
        /* execute.simd:3067 [D] s_b_136_8 = s_b_136_2>>s_b_136_7 */
        auto s_b_136_8 = emitter.shr(s_b_136_2, s_b_136_7);
        /* execute.simd:3067 [D] s_b_136_9 = sym_43411_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_136_9 = emitter.load_local(DV_sym_43411_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3067 [F] s_b_136_10 = constant s32 2 (const) */
        /* execute.simd:3067 [D] s_b_136_11 = s_b_136_9[s_b_136_10] <= s_b_136_8 */
        auto s_b_136_11 = emitter.vector_insert(s_b_136_9, emitter.const_s32((int32_t)2ULL), s_b_136_8);
        /* execute.simd:3067 [D] s_b_136_12: sym_43411_0_rd = s_b_136_11, dominates: s_b_139_9 s_b_141_8  */
        emitter.store_local(DV_sym_43411_0_rd, s_b_136_11);
        /* execute.simd:3067 [F] s_b_136_13: Jump b_137 (const) */
        {
          auto block = block_b_137;
          dynamic_block_queue.push(block_b_137);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_137) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_137);
        /* execute.simd:3066 [D] s_b_137_0 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_137_0 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_137_1 = constant u8 3 (const) */
        /* execute.simd:3066 [D] s_b_137_0[s_b_137_1] */
        auto s_b_137_2 = emitter.vector_extract(s_b_137_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3066 [F] s_b_137_3 = constant s32 0 (const) */
        /* execute.simd:3066 [D] s_b_137_4 = s_b_137_2<s_b_137_3 */
        auto s_b_137_4 = emitter.cmp_lt(s_b_137_2, emitter.const_s32((int32_t)0ULL));
        /* execute.simd:3066 [D] s_b_137_5: If s_b_137_4: Jump b_139 else b_141 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_139;
            dynamic_block_queue.push(block_b_139);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_141;
            dynamic_block_queue.push(block_b_141);
            false_target = block;
          }
          emitter.branch(s_b_137_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_138) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_138);
        /* execute.simd:3069 [D] s_b_138_0 = sym_43402_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_138_0 = emitter.load_local(DV_sym_43402_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_138_1 = constant u8 2 (const) */
        /* execute.simd:3069 [D] s_b_138_0[s_b_138_1] */
        auto s_b_138_2 = emitter.vector_extract(s_b_138_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3069 [D] s_b_138_3 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_138_3 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_138_4 = constant u8 2 (const) */
        /* execute.simd:3069 [D] s_b_138_3[s_b_138_4] */
        auto s_b_138_5 = emitter.vector_extract(s_b_138_3, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:3069 [D] s_b_138_6 = (u32)s_b_138_5 */
        auto s_b_138_6 = emitter.reinterpret(s_b_138_5, emitter.context().types().u32());
        /* execute.simd:3069 [D] s_b_138_7 = s_b_138_2<<s_b_138_6 */
        auto s_b_138_7 = emitter.shl(s_b_138_2, s_b_138_6);
        /* execute.simd:3069 [D] s_b_138_8 = sym_43411_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_138_8 = emitter.load_local(DV_sym_43411_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3069 [F] s_b_138_9 = constant s32 2 (const) */
        /* execute.simd:3069 [D] s_b_138_10 = s_b_138_8[s_b_138_9] <= s_b_138_7 */
        auto s_b_138_10 = emitter.vector_insert(s_b_138_8, emitter.const_s32((int32_t)2ULL), s_b_138_7);
        /* execute.simd:3069 [D] s_b_138_11: sym_43411_0_rd = s_b_138_10, dominates: s_b_139_9 s_b_141_8  */
        emitter.store_local(DV_sym_43411_0_rd, s_b_138_10);
        /* execute.simd:3069 [F] s_b_138_12: Jump b_137 (const) */
        {
          auto block = block_b_137;
          dynamic_block_queue.push(block_b_137);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_139) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_139);
        /* execute.simd:3067 [D] s_b_139_0 = sym_43402_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_139_0 = emitter.load_local(DV_sym_43402_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_139_1 = constant u8 3 (const) */
        /* execute.simd:3067 [D] s_b_139_0[s_b_139_1] */
        auto s_b_139_2 = emitter.vector_extract(s_b_139_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3067 [D] s_b_139_3 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_139_3 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_139_4 = constant u8 3 (const) */
        /* execute.simd:3067 [D] s_b_139_3[s_b_139_4] */
        auto s_b_139_5 = emitter.vector_extract(s_b_139_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3067 [D] s_b_139_6 = -s_b_139_5 */
        auto s_b_139_6 = emitter.neg(s_b_139_5);
        /* execute.simd:3067 [D] s_b_139_7 = (u32)s_b_139_6 */
        auto s_b_139_7 = emitter.reinterpret(s_b_139_6, emitter.context().types().u32());
        /* execute.simd:3067 [D] s_b_139_8 = s_b_139_2>>s_b_139_7 */
        auto s_b_139_8 = emitter.shr(s_b_139_2, s_b_139_7);
        /* execute.simd:3067 [D] s_b_139_9 = sym_43411_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_139_9 = emitter.load_local(DV_sym_43411_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3067 [F] s_b_139_10 = constant s32 3 (const) */
        /* execute.simd:3067 [D] s_b_139_11 = s_b_139_9[s_b_139_10] <= s_b_139_8 */
        auto s_b_139_11 = emitter.vector_insert(s_b_139_9, emitter.const_s32((int32_t)3ULL), s_b_139_8);
        /* execute.simd:3067 [D] s_b_139_12: sym_43411_0_rd = s_b_139_11, dominates: s_b_140_1  */
        emitter.store_local(DV_sym_43411_0_rd, s_b_139_11);
        /* execute.simd:3067 [F] s_b_139_13: Jump b_140 (const) */
        {
          auto block = block_b_140;
          dynamic_block_queue.push(block_b_140);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_140) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_140);
        /* execute.simd:3073 [F] s_b_140_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:3073 [D] s_b_140_1 = sym_43411_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_140_1 = emitter.load_local(DV_sym_43411_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3073 [D] s_b_140_2: WriteRegBank 20:s_b_140_0 = s_b_140_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_140_1,emitter.const_u8(16));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_140_1);
        /* execute.simd:0 [F] s_b_140_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_141) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_141);
        /* execute.simd:3069 [D] s_b_141_0 = sym_43402_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_141_0 = emitter.load_local(DV_sym_43402_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_141_1 = constant u8 3 (const) */
        /* execute.simd:3069 [D] s_b_141_0[s_b_141_1] */
        auto s_b_141_2 = emitter.vector_extract(s_b_141_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3069 [D] s_b_141_3 = sym_43406_0_rm wutils::Vector<int32_t, 4> */
        auto s_b_141_3 = emitter.load_local(DV_sym_43406_0_rm, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_141_4 = constant u8 3 (const) */
        /* execute.simd:3069 [D] s_b_141_3[s_b_141_4] */
        auto s_b_141_5 = emitter.vector_extract(s_b_141_3, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:3069 [D] s_b_141_6 = (u32)s_b_141_5 */
        auto s_b_141_6 = emitter.reinterpret(s_b_141_5, emitter.context().types().u32());
        /* execute.simd:3069 [D] s_b_141_7 = s_b_141_2<<s_b_141_6 */
        auto s_b_141_7 = emitter.shl(s_b_141_2, s_b_141_6);
        /* execute.simd:3069 [D] s_b_141_8 = sym_43411_0_rd wutils::Vector<uint32_t, 4> */
        auto s_b_141_8 = emitter.load_local(DV_sym_43411_0_rd, emitter.context().types().v4u32());
        /* execute.simd:3069 [F] s_b_141_9 = constant s32 3 (const) */
        /* execute.simd:3069 [D] s_b_141_10 = s_b_141_8[s_b_141_9] <= s_b_141_7 */
        auto s_b_141_10 = emitter.vector_insert(s_b_141_8, emitter.const_s32((int32_t)3ULL), s_b_141_7);
        /* execute.simd:3069 [D] s_b_141_11: sym_43411_0_rd = s_b_141_10, dominates: s_b_140_1  */
        emitter.store_local(DV_sym_43411_0_rd, s_b_141_10);
        /* execute.simd:3069 [F] s_b_141_12: Jump b_140 (const) */
        {
          auto block = block_b_140;
          dynamic_block_queue.push(block_b_140);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_143) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_143);
        /* execute.simd:3083 [D] s_b_143_0 = sym_43612_0_rn wutils::Vector<uint64_t, 2> */
        auto s_b_143_0 = emitter.load_local(DV_sym_43612_0_rn, emitter.context().types().v2u64());
        /* ???:4294967295 [F] s_b_143_1 = constant u8 0 (const) */
        /* execute.simd:3083 [D] s_b_143_0[s_b_143_1] */
        auto s_b_143_2 = emitter.vector_extract(s_b_143_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3083 [D] s_b_143_3 = sym_43616_0_rm wutils::Vector<int64_t, 2> */
        auto s_b_143_3 = emitter.load_local(DV_sym_43616_0_rm, emitter.context().types().v2s64());
        /* ???:4294967295 [F] s_b_143_4 = constant u8 0 (const) */
        /* execute.simd:3083 [D] s_b_143_3[s_b_143_4] */
        auto s_b_143_5 = emitter.vector_extract(s_b_143_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3083 [D] s_b_143_6 = -s_b_143_5 */
        auto s_b_143_6 = emitter.neg(s_b_143_5);
        /* execute.simd:3083 [D] s_b_143_7 = (u64)s_b_143_6 */
        auto s_b_143_7 = emitter.reinterpret(s_b_143_6, emitter.context().types().u64());
        /* execute.simd:3083 [D] s_b_143_8 = s_b_143_2>>s_b_143_7 */
        auto s_b_143_8 = emitter.shr(s_b_143_2, s_b_143_7);
        /* execute.simd:3083 [F] s_b_143_9 = sym_43621_0_rd (const) wutils::Vector<uint64_t, 2> */
        wutils::Vector<uint64_t, 2> s_b_143_9 = CV_sym_43621_0_rd;
        /* execute.simd:3083 [F] s_b_143_10 = constant s32 0 (const) */
        /* execute.simd:3083 [D] s_b_143_11 = s_b_143_9[s_b_143_10] <= s_b_143_8 */
        auto s_b_143_11 = emitter.vector_insert(emitter.constant_vector_splat(s_b_143_9[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_143_8);
        /* execute.simd:3083 [D] s_b_143_12: sym_43621_0_rd = s_b_143_11, dominates: s_b_146_9 s_b_148_8  */
        emitter.store_local(DV_sym_43621_0_rd, s_b_143_11);
        /* execute.simd:3083 [F] s_b_143_13: Jump b_144 (const) */
        {
          auto block = block_b_144;
          dynamic_block_queue.push(block_b_144);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_144) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_144);
        /* execute.simd:3082 [D] s_b_144_0 = sym_43616_0_rm wutils::Vector<int64_t, 2> */
        auto s_b_144_0 = emitter.load_local(DV_sym_43616_0_rm, emitter.context().types().v2s64());
        /* ???:4294967295 [F] s_b_144_1 = constant u8 1 (const) */
        /* execute.simd:3082 [D] s_b_144_0[s_b_144_1] */
        auto s_b_144_2 = emitter.vector_extract(s_b_144_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3082 [F] s_b_144_3 = constant s64 0 (const) */
        /* execute.simd:3082 [D] s_b_144_4 = s_b_144_2<s_b_144_3 */
        auto s_b_144_4 = emitter.cmp_lt(s_b_144_2, emitter.const_s64((int64_t)0ULL));
        /* execute.simd:3082 [D] s_b_144_5: If s_b_144_4: Jump b_146 else b_148 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_146;
            dynamic_block_queue.push(block_b_146);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
          {
            auto block = block_b_148;
            dynamic_block_queue.push(block_b_148);
            false_target = block;
          }
          emitter.branch(s_b_144_4, true_target, false_target);
        }
      }
      else if (block_index == block_b_145) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_145);
        /* execute.simd:3085 [D] s_b_145_0 = sym_43612_0_rn wutils::Vector<uint64_t, 2> */
        auto s_b_145_0 = emitter.load_local(DV_sym_43612_0_rn, emitter.context().types().v2u64());
        /* ???:4294967295 [F] s_b_145_1 = constant u8 0 (const) */
        /* execute.simd:3085 [D] s_b_145_0[s_b_145_1] */
        auto s_b_145_2 = emitter.vector_extract(s_b_145_0, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3085 [D] s_b_145_3 = sym_43616_0_rm wutils::Vector<int64_t, 2> */
        auto s_b_145_3 = emitter.load_local(DV_sym_43616_0_rm, emitter.context().types().v2s64());
        /* ???:4294967295 [F] s_b_145_4 = constant u8 0 (const) */
        /* execute.simd:3085 [D] s_b_145_3[s_b_145_4] */
        auto s_b_145_5 = emitter.vector_extract(s_b_145_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3085 [D] s_b_145_6 = (u64)s_b_145_5 */
        auto s_b_145_6 = emitter.reinterpret(s_b_145_5, emitter.context().types().u64());
        /* execute.simd:3085 [D] s_b_145_7 = s_b_145_2<<s_b_145_6 */
        auto s_b_145_7 = emitter.shl(s_b_145_2, s_b_145_6);
        /* execute.simd:3085 [F] s_b_145_8 = sym_43621_0_rd (const) wutils::Vector<uint64_t, 2> */
        wutils::Vector<uint64_t, 2> s_b_145_8 = CV_sym_43621_0_rd;
        /* execute.simd:3085 [F] s_b_145_9 = constant s32 0 (const) */
        /* execute.simd:3085 [D] s_b_145_10 = s_b_145_8[s_b_145_9] <= s_b_145_7 */
        auto s_b_145_10 = emitter.vector_insert(emitter.constant_vector_splat(s_b_145_8[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_145_7);
        /* execute.simd:3085 [D] s_b_145_11: sym_43621_0_rd = s_b_145_10, dominates: s_b_146_9 s_b_148_8  */
        emitter.store_local(DV_sym_43621_0_rd, s_b_145_10);
        /* execute.simd:3085 [F] s_b_145_12: Jump b_144 (const) */
        {
          auto block = block_b_144;
          dynamic_block_queue.push(block_b_144);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_146) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_146);
        /* execute.simd:3083 [D] s_b_146_0 = sym_43612_0_rn wutils::Vector<uint64_t, 2> */
        auto s_b_146_0 = emitter.load_local(DV_sym_43612_0_rn, emitter.context().types().v2u64());
        /* ???:4294967295 [F] s_b_146_1 = constant u8 1 (const) */
        /* execute.simd:3083 [D] s_b_146_0[s_b_146_1] */
        auto s_b_146_2 = emitter.vector_extract(s_b_146_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3083 [D] s_b_146_3 = sym_43616_0_rm wutils::Vector<int64_t, 2> */
        auto s_b_146_3 = emitter.load_local(DV_sym_43616_0_rm, emitter.context().types().v2s64());
        /* ???:4294967295 [F] s_b_146_4 = constant u8 1 (const) */
        /* execute.simd:3083 [D] s_b_146_3[s_b_146_4] */
        auto s_b_146_5 = emitter.vector_extract(s_b_146_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3083 [D] s_b_146_6 = -s_b_146_5 */
        auto s_b_146_6 = emitter.neg(s_b_146_5);
        /* execute.simd:3083 [D] s_b_146_7 = (u64)s_b_146_6 */
        auto s_b_146_7 = emitter.reinterpret(s_b_146_6, emitter.context().types().u64());
        /* execute.simd:3083 [D] s_b_146_8 = s_b_146_2>>s_b_146_7 */
        auto s_b_146_8 = emitter.shr(s_b_146_2, s_b_146_7);
        /* execute.simd:3083 [D] s_b_146_9 = sym_43621_0_rd wutils::Vector<uint64_t, 2> */
        auto s_b_146_9 = emitter.load_local(DV_sym_43621_0_rd, emitter.context().types().v2u64());
        /* execute.simd:3083 [F] s_b_146_10 = constant s32 1 (const) */
        /* execute.simd:3083 [D] s_b_146_11 = s_b_146_9[s_b_146_10] <= s_b_146_8 */
        auto s_b_146_11 = emitter.vector_insert(s_b_146_9, emitter.const_s32((int32_t)1ULL), s_b_146_8);
        /* execute.simd:3083 [D] s_b_146_12: sym_43621_0_rd = s_b_146_11, dominates: s_b_147_1  */
        emitter.store_local(DV_sym_43621_0_rd, s_b_146_11);
        /* execute.simd:3083 [F] s_b_146_13: Jump b_147 (const) */
        {
          auto block = block_b_147;
          dynamic_block_queue.push(block_b_147);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_147) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_147);
        /* execute.simd:3089 [F] s_b_147_0=sym_41396_3_parameter_inst.rd (const) */
        /* execute.simd:3089 [D] s_b_147_1 = sym_43621_0_rd wutils::Vector<uint64_t, 2> */
        auto s_b_147_1 = emitter.load_local(DV_sym_43621_0_rd, emitter.context().types().v2u64());
        /* execute.simd:3089 [D] s_b_147_2: WriteRegBank 21:s_b_147_0 = s_b_147_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_147_1,emitter.const_u8(16));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_147_1);
        /* execute.simd:0 [F] s_b_147_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_148) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_148);
        /* execute.simd:3085 [D] s_b_148_0 = sym_43612_0_rn wutils::Vector<uint64_t, 2> */
        auto s_b_148_0 = emitter.load_local(DV_sym_43612_0_rn, emitter.context().types().v2u64());
        /* ???:4294967295 [F] s_b_148_1 = constant u8 1 (const) */
        /* execute.simd:3085 [D] s_b_148_0[s_b_148_1] */
        auto s_b_148_2 = emitter.vector_extract(s_b_148_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3085 [D] s_b_148_3 = sym_43616_0_rm wutils::Vector<int64_t, 2> */
        auto s_b_148_3 = emitter.load_local(DV_sym_43616_0_rm, emitter.context().types().v2s64());
        /* ???:4294967295 [F] s_b_148_4 = constant u8 1 (const) */
        /* execute.simd:3085 [D] s_b_148_3[s_b_148_4] */
        auto s_b_148_5 = emitter.vector_extract(s_b_148_3, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:3085 [D] s_b_148_6 = (u64)s_b_148_5 */
        auto s_b_148_6 = emitter.reinterpret(s_b_148_5, emitter.context().types().u64());
        /* execute.simd:3085 [D] s_b_148_7 = s_b_148_2<<s_b_148_6 */
        auto s_b_148_7 = emitter.shl(s_b_148_2, s_b_148_6);
        /* execute.simd:3085 [D] s_b_148_8 = sym_43621_0_rd wutils::Vector<uint64_t, 2> */
        auto s_b_148_8 = emitter.load_local(DV_sym_43621_0_rd, emitter.context().types().v2u64());
        /* execute.simd:3085 [F] s_b_148_9 = constant s32 1 (const) */
        /* execute.simd:3085 [D] s_b_148_10 = s_b_148_8[s_b_148_9] <= s_b_148_7 */
        auto s_b_148_10 = emitter.vector_insert(s_b_148_8, emitter.const_s32((int32_t)1ULL), s_b_148_7);
        /* execute.simd:3085 [D] s_b_148_11: sym_43621_0_rd = s_b_148_10, dominates: s_b_147_1  */
        emitter.store_local(DV_sym_43621_0_rd, s_b_148_10);
        /* execute.simd:3085 [F] s_b_148_12: Jump b_147 (const) */
        {
          auto block = block_b_147;
          dynamic_block_queue.push(block_b_147);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_vldur(const arm64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_158614_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_158625_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158635_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158498_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158515_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158591_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_158589_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158603_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_158639_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3909 [F] s_b_0_0=sym_46997_3_parameter_inst.rn (const) */
    /* execute.a64:2771 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2771 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2771 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2771 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2742 [F] s_b_1_0 = constant u32 1 (const) */
    /* execute.a64:2742 [F] s_b_1_1 = __builtin_get_feature */
    uint32_t s_b_1_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2742 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.a64:2742 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(s_b_1_1 == (uint32_t)0ULL));
    /* execute.a64:2742 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2774 [F] s_b_2_0=sym_46997_3_parameter_inst.rn (const) */
    /* execute.a64:2774 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_158498_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_158498_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_158498_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_158498_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:3910 [F] s_b_3_1=sym_46997_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.simd:3912 [F] s_b_3_4=sym_46997_3_parameter_inst.size (const) */
    /* execute.simd:3912 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:3912 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:3912 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:3912 [F] s_b_3_8=sym_46997_3_parameter_inst.opc (const) */
    /* execute.simd:3912 [F] s_b_3_9 = (u32)s_b_3_8 (const) */
    /* execute.simd:3912 [F] s_b_3_10 = constant u32 1 (const) */
    /* execute.simd:3912 [F] s_b_3_11 = s_b_3_9==s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.simd:3912 [F] s_b_3_12 = constant u8 0 (const) */
    /* execute.simd:3912 [F] s_b_3_13 = constant u8 4 (const) */
    /* execute.simd:3912 [F] s_b_3_14: Select s_b_3_11 ? s_b_3_12 : s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(s_b_3_11 ? ((uint8_t)0ULL) : ((uint8_t)4ULL)));
    /* execute.simd:3912 [F] s_b_3_15=sym_46997_3_parameter_inst.size (const) */
    /* execute.simd:3912 [F] s_b_3_16 = (u8)s_b_3_15 (const) */
    /* execute.simd:3912 [F] s_b_3_17: Select s_b_3_7 ? s_b_3_14 : s_b_3_16 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(s_b_3_7 ? (s_b_3_14) : (((uint8_t)insn.size))));
    /* ???:4294967295 [D] s_b_3_18: sym_158589_0_replaced_parameter_addr = s_b_3_3, dominates: s_b_10_0 s_b_13_0 s_b_9_0 s_b_12_0 s_b_11_0  */
    emitter.store_local(DV_sym_158589_0_replaced_parameter_addr, s_b_3_3);
    /* execute.simd:3676 [F] s_b_3_19 = constant s32 0 (const) */
    /* execute.simd:3683 [F] s_b_3_20 = constant s32 1 (const) */
    /* execute.simd:3690 [F] s_b_3_21 = constant s32 2 (const) */
    /* execute.simd:3697 [F] s_b_3_22 = constant s32 3 (const) */
    /* execute.simd:3704 [F] s_b_3_23 = constant s32 4 (const) */
    /* execute.simd:3675 [F] s_b_3_24: Switch s_b_3_17: < <todo> > def b_14 (const) -> b_10, b_14, b_13, b_9, b_12, b_11,  */
    switch (s_b_3_17) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_12;
      break;
    default:
      goto fixed_block_b_14;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2743 [D] s_b_4_0 = ReadReg 20 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2743 [D] s_b_4_1: sym_158515_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_158515_1__R_s_b_3_0, s_b_4_0);
    /* execute.a64:2743 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:3053 [F] s_b_5_0 = constant u32 0 (const) */
    /* execute.a64:3053 [F] s_b_5_1 = __builtin_get_feature */
    uint32_t s_b_5_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3053 [F] s_b_5_2 = (u8)s_b_5_1 (const) */
    /* execute.a64:2745 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:2745 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2745 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_5_1)) == (uint32_t)0ULL));
    /* execute.a64:2745 [F] s_b_5_6: If s_b_5_5: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2772 [D] s_b_6_0 = sym_158515_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_158515_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_158498_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_158498_0_return_symbol, s_b_6_0);
    /* ???:4294967295 [F] s_b_6_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2746 [D] s_b_7_0 = ReadReg 20 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2746 [D] s_b_7_1: sym_158515_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_158515_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2746 [F] s_b_7_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2748 [D] s_b_8_0 = ReadReg 21 (u64) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_8_0, emitter.const_u8(8));
    }
    /* execute.a64:2748 [D] s_b_8_1: sym_158515_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_158515_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2748 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3679 [D] s_b_9_0 = sym_158589_0_replaced_parameter_addr uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_158589_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1 = Load 1 s_b_9_0 => sym_158591_0_value */
    auto s_b_9_1 = emitter.load_memory(s_b_9_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_158591_0_value, s_b_9_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_0, s_b_9_1, emitter.const_u8(1));
    }
    /* execute.simd:3680 [F] s_b_9_2=sym_46997_3_parameter_inst.rt (const) */
    /* execute.simd:3680 [D] s_b_9_3 = sym_158591_0_value uint8_t */
    auto s_b_9_3 = emitter.load_local(DV_sym_158591_0_value, emitter.context().types().u8());
    /* execute.simd:6187 [D] s_b_9_4 = (u64)s_b_9_3 */
    auto s_b_9_4 = emitter.zx(s_b_9_3, emitter.context().types().u64());
    /* execute.simd:6187 [D] s_b_9_5: WriteRegBank 2:s_b_9_2 = s_b_9_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_4);
    /* execute.simd:6188 [F] s_b_9_6 = constant u64 0 (const) */
    /* execute.simd:6188 [F] s_b_9_7: WriteRegBank 3:s_b_9_2 = s_b_9_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_9_8: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3686 [D] s_b_10_0 = sym_158589_0_replaced_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_158589_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 2 s_b_10_0 => sym_158603_0_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_158603_0_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(2));
    }
    /* execute.simd:3687 [F] s_b_10_2=sym_46997_3_parameter_inst.rt (const) */
    /* execute.simd:3687 [D] s_b_10_3 = sym_158603_0_value uint16_t */
    auto s_b_10_3 = emitter.load_local(DV_sym_158603_0_value, emitter.context().types().u16());
    /* execute.simd:6194 [D] s_b_10_4 = (u64)s_b_10_3 */
    auto s_b_10_4 = emitter.zx(s_b_10_3, emitter.context().types().u64());
    /* execute.simd:6194 [D] s_b_10_5: WriteRegBank 2:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_4);
    /* execute.simd:6195 [F] s_b_10_6 = constant u64 0 (const) */
    /* execute.simd:6195 [F] s_b_10_7: WriteRegBank 3:s_b_10_2 = s_b_10_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_10_8: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3693 [D] s_b_11_0 = sym_158589_0_replaced_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_158589_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 4 s_b_11_0 => sym_158614_0_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_158614_0_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(4));
    }
    /* execute.simd:3694 [F] s_b_11_2=sym_46997_3_parameter_inst.rt (const) */
    /* execute.simd:3694 [D] s_b_11_3 = sym_158614_0_value uint32_t */
    auto s_b_11_3 = emitter.load_local(DV_sym_158614_0_value, emitter.context().types().u32());
    /* execute.simd:6201 [D] s_b_11_4 = (u64)s_b_11_3 */
    auto s_b_11_4 = emitter.zx(s_b_11_3, emitter.context().types().u64());
    /* execute.simd:6201 [D] s_b_11_5: WriteRegBank 2:s_b_11_2 = s_b_11_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_11_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_11_4);
    /* execute.simd:6202 [F] s_b_11_6 = constant u64 0 (const) */
    /* execute.simd:6202 [F] s_b_11_7: WriteRegBank 3:s_b_11_2 = s_b_11_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_11_8: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3700 [D] s_b_12_0 = sym_158589_0_replaced_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_158589_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 8 s_b_12_0 => sym_158625_0_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_158625_0_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(8));
    }
    /* execute.simd:3701 [F] s_b_12_2=sym_46997_3_parameter_inst.rt (const) */
    /* execute.simd:3701 [D] s_b_12_3 = sym_158625_0_value uint64_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_158625_0_value, emitter.context().types().u64());
    /* execute.simd:6208 [D] s_b_12_4: WriteRegBank 2:s_b_12_2 = s_b_12_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_3);
    /* execute.simd:6209 [F] s_b_12_5 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_12_6: WriteRegBank 3:s_b_12_2 = s_b_12_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_12_7: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3708 [D] s_b_13_0 = sym_158589_0_replaced_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_158589_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 8 s_b_13_0 => sym_158635_0_vl */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_158635_0_vl, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(8));
    }
    /* execute.simd:3709 [F] s_b_13_2 = constant u64 8 (const) */
    /* execute.simd:3709 [D] s_b_13_3 = s_b_13_0+s_b_13_2 */
    auto s_b_13_3 = emitter.add(s_b_13_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_13_4 = Load 8 s_b_13_3 => sym_158639_0_vh */
    auto s_b_13_4 = emitter.load_memory(s_b_13_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_158639_0_vh, s_b_13_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_3, s_b_13_4, emitter.const_u8(8));
    }
    /* execute.simd:3710 [F] s_b_13_5=sym_46997_3_parameter_inst.rt (const) */
    /* execute.simd:3710 [D] s_b_13_6 = sym_158635_0_vl uint64_t */
    auto s_b_13_6 = emitter.load_local(DV_sym_158635_0_vl, emitter.context().types().u64());
    /* execute.simd:3710 [D] s_b_13_7 = sym_158639_0_vh uint64_t */
    auto s_b_13_7 = emitter.load_local(DV_sym_158639_0_vh, emitter.context().types().u64());
    /* execute.simd:6215 [D] s_b_13_8: WriteRegBank 2:s_b_13_5 = s_b_13_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_6);
    /* execute.simd:6216 [D] s_b_13_9: WriteRegBank 3:s_b_13_5 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_7,emitter.const_u8(8));
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
template class arm64_jit2<true>;
template class arm64_jit2<false>;
