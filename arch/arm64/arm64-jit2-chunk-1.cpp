#include <arm64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::arm64;
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_adc(const arm64_decode_a64_ADD_SUB_CARRY&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_48279_1_temporary_value;
  auto DV_sym_48279_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_48307_1_temporary_value;
  auto DV_sym_48307_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_48258_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3290_0_result = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_3264_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3248_0_op2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3243_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_48110_1_temporary_value;
  auto DV_sym_48110_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48039_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_48138_1_temporary_value;
  auto DV_sym_48138_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_48172_1__R_s_b_13_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48192_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2024 [F] s_b_0_0=sym_3238_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_0_1: If s_b_0_0: Jump b_10 else b_11 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_21,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2030 [F] s_b_1_0=sym_3238_3_parameter_inst.S (const) */
    /* execute.a64:2030 [F] s_b_1_1: If s_b_1_0: Jump b_4 else b_6 (const) */
    if (insn.S) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_5, b_8, b_22, b_23,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_21,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2040 [F] s_b_3_0=sym_3238_3_parameter_inst.S (const) */
    /* execute.a64:2040 [F] s_b_3_1: If s_b_3_0: Jump b_7 else b_9 (const) */
    if (insn.S) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2031 [D] s_b_4_0 = sym_3243_0_op1 uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_3243_0_op1, emitter.context().types().u64());
    /* execute.a64:2031 [D] s_b_4_1 = sym_3248_0_op2 uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_3248_0_op2, emitter.context().types().u64());
    /* execute.a64:2031 [D] s_b_4_2 = ReadReg 3 (u8) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_4_2, emitter.const_u8(1));
    }
    /* execute.a64:2031 [D] s_b_4_3 = __builtin_adc64_flags */
    auto s_b_4_3 = emitter.adcf(s_b_4_0, s_b_4_1, s_b_4_2);
    /* execute.a64:2031 [D] s_b_4_4: sym_3264_0_result = s_b_4_3, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_3264_0_result, s_b_4_3);
    /* execute.a64:2031 [F] s_b_4_5: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_6,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2036 [D] s_b_5_0 = sym_3264_0_result uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_3264_0_result, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_5_1=sym_3238_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_5_2: sym_48192_3_parameter_value = s_b_5_0, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_48192_3_parameter_value, s_b_5_0);
    /* execute.a64:2745 [F] s_b_5_3 = (u32)s_b_5_1 (const) */
    /* execute.a64:2745 [F] s_b_5_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_5_6: If s_b_5_5: Jump b_2 else b_22 (const) */
    if (s_b_5_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_1,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2033 [D] s_b_6_0 = sym_3243_0_op1 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_3243_0_op1, emitter.context().types().u64());
    /* execute.a64:2033 [D] s_b_6_1 = sym_3248_0_op2 uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_3248_0_op2, emitter.context().types().u64());
    /* execute.a64:2033 [D] s_b_6_2 = ReadReg 3 (u8) */
    auto s_b_6_2 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_6_2, emitter.const_u8(1));
    }
    /* execute.a64:2033 [D] s_b_6_3 = __builtin_adc64 */
    auto s_b_6_3 = emitter.adc(s_b_6_0, s_b_6_1, s_b_6_2);
    /* execute.a64:2033 [D] s_b_6_4: sym_3264_0_result = s_b_6_3, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_3264_0_result, s_b_6_3);
    /* execute.a64:2033 [F] s_b_6_5: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2041 [D] s_b_7_0 = sym_3243_0_op1 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_3243_0_op1, emitter.context().types().u64());
    /* execute.a64:2041 [D] s_b_7_1 = (u32)s_b_7_0 */
    auto s_b_7_1 = emitter.truncate(s_b_7_0, emitter.context().types().u32());
    /* execute.a64:2041 [D] s_b_7_2 = sym_3248_0_op2 uint64_t */
    auto s_b_7_2 = emitter.load_local(DV_sym_3248_0_op2, emitter.context().types().u64());
    /* execute.a64:2041 [D] s_b_7_3 = (u32)s_b_7_2 */
    auto s_b_7_3 = emitter.truncate(s_b_7_2, emitter.context().types().u32());
    /* execute.a64:2041 [D] s_b_7_4 = ReadReg 3 (u8) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_7_4, emitter.const_u8(1));
    }
    /* execute.a64:2041 [D] s_b_7_5 = __builtin_adc32_flags */
    auto s_b_7_5 = emitter.adcf(s_b_7_1, s_b_7_3, s_b_7_4);
    /* execute.a64:2041 [D] s_b_7_6: sym_3290_0_result = s_b_7_5, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_3290_0_result, s_b_7_5);
    /* execute.a64:2041 [F] s_b_7_7: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_9,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2046 [D] s_b_8_0 = sym_3290_0_result uint32_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_3290_0_result, emitter.context().types().u32());
    /* execute.a64:2046 [D] s_b_8_1 = (u64)s_b_8_0 */
    auto s_b_8_1 = emitter.zx(s_b_8_0, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_8_2=sym_3238_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_8_3 = (u32)s_b_8_1 */
    auto s_b_8_3 = emitter.truncate(s_b_8_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_8_4 = (u64)s_b_8_3 */
    auto s_b_8_4 = emitter.zx(s_b_8_3, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_8_5: sym_48258_3_parameter_value = s_b_8_4, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_48258_3_parameter_value, s_b_8_4);
    /* execute.a64:2745 [F] s_b_8_6 = (u32)s_b_8_2 (const) */
    /* execute.a64:2745 [F] s_b_8_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_8_8 = s_b_8_6==s_b_8_7 (const) */
    uint8_t s_b_8_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_8_9: If s_b_8_8: Jump b_2 else b_23 (const) */
    if (s_b_8_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2043 [D] s_b_9_0 = sym_3243_0_op1 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_3243_0_op1, emitter.context().types().u64());
    /* execute.a64:2043 [D] s_b_9_1 = (u32)s_b_9_0 */
    auto s_b_9_1 = emitter.truncate(s_b_9_0, emitter.context().types().u32());
    /* execute.a64:2043 [D] s_b_9_2 = sym_3248_0_op2 uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_3248_0_op2, emitter.context().types().u64());
    /* execute.a64:2043 [D] s_b_9_3 = (u32)s_b_9_2 */
    auto s_b_9_3 = emitter.truncate(s_b_9_2, emitter.context().types().u32());
    /* execute.a64:2043 [D] s_b_9_4 = ReadReg 3 (u8) */
    auto s_b_9_4 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_9_4, emitter.const_u8(1));
    }
    /* execute.a64:2043 [D] s_b_9_5 = __builtin_adc32 */
    auto s_b_9_5 = emitter.adc(s_b_9_1, s_b_9_3, s_b_9_4);
    /* execute.a64:2043 [D] s_b_9_6: sym_3290_0_result = s_b_9_5, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_3290_0_result, s_b_9_5);
    /* execute.a64:2043 [F] s_b_9_7: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2720 [F] s_b_10_0=sym_3238_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2714 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2722 [F] s_b_11_0=sym_3238_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2709 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_11_4: If s_b_11_3: Jump b_16 else b_17 (const) */
    if (s_b_11_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_15, b_18,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2024 [D] s_b_12_0 = sym_48039_1__R_s_b_0_4 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_48039_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2024 [D] s_b_12_1: sym_3243_0_op1 = s_b_12_0, dominates: s_b_4_0 s_b_6_0 s_b_7_0 s_b_9_0  */
    emitter.store_local(DV_sym_3243_0_op1, s_b_12_0);
    /* execute.a64:2025 [F] s_b_12_2=sym_3238_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_12_3: If s_b_12_2: Jump b_19 else b_20 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2714 [F] s_b_13_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_13_1: sym_48110_1_temporary_value = s_b_13_0 (const), dominates: s_b_15_0  */
    CV_sym_48110_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_48110_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2714 [F] s_b_14_0=sym_3238_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_14_2: sym_48110_1_temporary_value = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_48110_1_temporary_value, s_b_14_1);
    /* execute.a64:2714 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2714 [D] s_b_15_0 = sym_48110_1_temporary_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_48110_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_15_1: sym_48039_1__R_s_b_0_4 = s_b_15_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_48039_1__R_s_b_0_4, s_b_15_0);
    /* execute.a64:2720 [F] s_b_15_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [F] s_b_16_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_16_1: sym_48138_1_temporary_value = s_b_16_0 (const), dominates: s_b_18_0  */
    CV_sym_48138_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_48138_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_11,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2709 [F] s_b_17_0=sym_3238_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_17_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_17_2: sym_48138_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_48138_1_temporary_value, s_b_17_1);
    /* execute.a64:2709 [F] s_b_17_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_16, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2709 [D] s_b_18_0 = sym_48138_1_temporary_value uint32_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_48138_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
    auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_18_2: sym_48039_1__R_s_b_0_4 = s_b_18_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_48039_1__R_s_b_0_4, s_b_18_1);
    /* execute.a64:2722 [F] s_b_18_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_12,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2720 [F] s_b_19_0=sym_3238_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2714 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_19_4: If s_b_19_3: Jump b_24 else b_25 (const) */
    if (s_b_19_3) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_12,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2722 [F] s_b_20_0=sym_3238_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
    /* execute.a64:2709 [F] s_b_20_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_20_4: If s_b_20_3: Jump b_27 else b_28 (const) */
    if (s_b_20_3) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_28;
    }
  }
  /* b_26, b_29,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2025 [D] s_b_21_0 = sym_48172_1__R_s_b_13_6 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_48172_1__R_s_b_13_6, emitter.context().types().u64());
    /* execute.a64:2025 [D] s_b_21_1: sym_3248_0_op2 = s_b_21_0, dominates: s_b_4_1 s_b_6_1 s_b_7_2 s_b_9_2  */
    emitter.store_local(DV_sym_3248_0_op2, s_b_21_0);
    /* execute.a64:2027 [F] s_b_21_2=sym_3238_3_parameter_inst.sf (const) */
    /* execute.a64:2027 [F] s_b_21_3: If s_b_21_2: Jump b_1 else b_3 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_5,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2747 [F] s_b_22_0=sym_3238_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_22_1 = sym_48192_3_parameter_value uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_48192_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_22_2: WriteRegBank 0:s_b_22_0 = s_b_22_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_22_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_22_1);
    /* execute.a64:0 [F] s_b_22_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2747 [F] s_b_23_0=sym_3238_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_23_1 = sym_48258_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_48258_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_23_2: WriteRegBank 0:s_b_23_0 = s_b_23_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_1);
    /* execute.a64:0 [F] s_b_23_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_19,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [F] s_b_24_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_24_1: sym_48279_1_temporary_value = s_b_24_0 (const), dominates: s_b_26_0  */
    CV_sym_48279_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_48279_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_24_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_19,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2714 [F] s_b_25_0=sym_3238_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_25_1 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_25_2: sym_48279_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_48279_1_temporary_value, s_b_25_1);
    /* execute.a64:2714 [F] s_b_25_3: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_24, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2714 [D] s_b_26_0 = sym_48279_1_temporary_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_48279_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_26_1: sym_48172_1__R_s_b_13_6 = s_b_26_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_48172_1__R_s_b_13_6, s_b_26_0);
    /* execute.a64:2720 [F] s_b_26_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2709 [F] s_b_27_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_27_1: sym_48307_1_temporary_value = s_b_27_0 (const), dominates: s_b_29_0  */
    CV_sym_48307_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_48307_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_27_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_20,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2709 [F] s_b_28_0=sym_3238_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_28_1 = ReadRegBank 1:s_b_28_0 (u32) */
    auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_28_2: sym_48307_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_48307_1_temporary_value, s_b_28_1);
    /* execute.a64:2709 [F] s_b_28_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2709 [D] s_b_29_0 = sym_48307_1_temporary_value uint32_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_48307_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_29_1 = (u64)s_b_29_0 */
    auto s_b_29_1 = emitter.zx(s_b_29_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_29_2: sym_48172_1__R_s_b_13_6 = s_b_29_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_48172_1__R_s_b_13_6, s_b_29_1);
    /* execute.a64:2722 [F] s_b_29_3: Jump b_21 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_adr(const arm64_decode_a64_PC_REL&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_50804_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_5712_0_base = emitter.alloc_local(emitter.context().types().s64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:267 [D] s_b_0_0 = read_pc */
    auto s_b_0_0 = emitter.load_pc();
    /* execute.a64:267 [D] s_b_0_1 = (s64)s_b_0_0 */
    auto s_b_0_1 = emitter.reinterpret(s_b_0_0, emitter.context().types().s64());
    /* execute.a64:267 [D] s_b_0_2: sym_5712_0_base = s_b_0_1, dominates: s_b_1_0 s_b_2_0  */
    emitter.store_local(DV_sym_5712_0_base, s_b_0_1);
    /* execute.a64:269 [F] s_b_0_3=sym_5708_3_parameter_inst.op (const) */
    /* execute.a64:269 [F] s_b_0_4 = (u32)s_b_0_3 (const) */
    /* execute.a64:269 [F] s_b_0_5 = constant u32 1 (const) */
    /* execute.a64:269 [F] s_b_0_6 = s_b_0_4==s_b_0_5 (const) */
    uint8_t s_b_0_6 = ((uint8_t)(((uint32_t)insn.op) == (uint32_t)1ULL));
    /* execute.a64:269 [F] s_b_0_7: If s_b_0_6: Jump b_1 else b_2 (const) */
    if (s_b_0_6) 
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
    /* execute.a64:270 [D] s_b_1_0 = sym_5712_0_base int64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_5712_0_base, emitter.context().types().s64());
    /* execute.a64:270 [F] s_b_1_1 = constant u64 fff (const) */
    /* execute.a64:270 [F] s_b_1_2 = ~s_b_1_1 (const) */
    uint64_t s_b_1_2 = ~(uint64_t)4095ULL;
    /* ???:4294967295 [D] s_b_1_3 = (u64)s_b_1_0 */
    auto s_b_1_3 = emitter.reinterpret(s_b_1_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_4 = s_b_1_3&s_b_1_2 */
    auto s_b_1_4 = emitter.bitwise_and(s_b_1_3, emitter.const_u64(s_b_1_2));
    /* execute.a64:270 [D] s_b_1_5 = (s64)s_b_1_4 */
    auto s_b_1_5 = emitter.reinterpret(s_b_1_4, emitter.context().types().s64());
    /* execute.a64:270 [D] s_b_1_6: sym_5712_0_base = s_b_1_5, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_5712_0_base, s_b_1_5);
    /* execute.a64:270 [F] s_b_1_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0, b_1,  */
  fixed_block_b_2: 
  {
    /* execute.a64:273 [D] s_b_2_0 = sym_5712_0_base int64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_5712_0_base, emitter.context().types().s64());
    /* execute.a64:273 [F] s_b_2_1=sym_5708_3_parameter_inst.imms64 (const) */
    /* execute.a64:273 [D] s_b_2_2 = s_b_2_0+s_b_2_1 */
    auto s_b_2_2 = emitter.add(s_b_2_0, emitter.const_s64(insn.imms64));
    /* execute.a64:273 [D] s_b_2_3 = (u64)s_b_2_2 */
    auto s_b_2_3 = emitter.reinterpret(s_b_2_2, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_2_4=sym_5708_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_2_5: sym_50804_3_parameter_value = s_b_2_3, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_50804_3_parameter_value, s_b_2_3);
    /* execute.a64:2745 [F] s_b_2_6 = (u32)s_b_2_4 (const) */
    /* execute.a64:2745 [F] s_b_2_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_2_8 = s_b_2_6==s_b_2_7 (const) */
    uint8_t s_b_2_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_2_9: If s_b_2_8: Jump b_3 else b_4 (const) */
    if (s_b_2_8) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_2, b_4,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [F] s_b_3_0: Return */
    goto fixed_done;
  }
  /* b_2,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2747 [F] s_b_4_0=sym_5708_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_4_1 = sym_50804_3_parameter_value uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_50804_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_4_2: WriteRegBank 0:s_b_4_0 = s_b_4_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_4_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_4_1);
    /* execute.a64:0 [F] s_b_4_3: Jump b_3 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_bfm(const arm64_decode_a64_BITFIELD&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_52743_1_temporary_value;
  auto DV_sym_52743_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_52810_1_temporary_value;
  auto DV_sym_52810_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_52645_1_temporary_value;
  auto DV_sym_52645_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_52935_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52889_1__R_s_b_15_10 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52905_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_52663_3_parameter_len;
  auto DV_sym_52672_3_parameter_src = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52696_1__R_s_b_7_15 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_52856_3_parameter_len;
  auto DV_sym_52865_3_parameter_src = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52957_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_52838_1_temporary_value;
  auto DV_sym_52838_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_52715_1_temporary_value;
  auto DV_sym_52715_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_6117_0_len;
  uint8_t CV_sym_6105_0_pos;
  auto DV_sym_6102_0_bits = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_52617_1_temporary_value;
  auto DV_sym_52617_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52573_1__R_s_b_2_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52598_1__R_s_b_3_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52548_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:96 [F] s_b_0_0=sym_6078_3_parameter_inst.imms (const) */
    /* execute.a64:96 [F] s_b_0_1=sym_6078_3_parameter_inst.immr (const) */
    /* execute.a64:96 [F] s_b_0_2 = s_b_0_0>=s_b_0_1 (const) */
    uint8_t s_b_0_2 = ((uint8_t)(insn.imms >= insn.immr));
    /* execute.a64:96 [F] s_b_0_3: If s_b_0_2: Jump b_1 else b_3 (const) */
    if (s_b_0_2) 
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
    /* execute.a64:97 [F] s_b_1_0=sym_6078_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_1_1: If s_b_1_0: Jump b_4 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_21, b_36,  */
  fixed_block_b_2: 
  {
    /* execute.a64:106 [F] s_b_2_0=sym_6078_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_2_1: If s_b_2_0: Jump b_7 else b_8 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:101 [F] s_b_3_0=sym_6078_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_3_1: If s_b_3_0: Jump b_10 else b_11 (const) */
    if (insn.sf) 
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
    /* execute.a64:2720 [F] s_b_4_0=sym_6078_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2714 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_4_4: If s_b_4_3: Jump b_13 else b_14 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2722 [F] s_b_5_0=sym_6078_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2709 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_5_4: If s_b_5_3: Jump b_16 else b_17 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_15, b_18,  */
  fixed_block_b_6: 
  {
    /* execute.a64:97 [D] s_b_6_0 = sym_52548_1__R_s_b_1_4 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_52548_1__R_s_b_1_4, emitter.context().types().u64());
    /* execute.a64:97 [F] s_b_6_1=sym_6078_3_parameter_inst.imms (const) */
    /* execute.a64:97 [F] s_b_6_2 = (u8)s_b_6_1 (const) */
    /* execute.a64:97 [F] s_b_6_3=sym_6078_3_parameter_inst.immr (const) */
    /* execute.a64:97 [F] s_b_6_4 = (u8)s_b_6_3 (const) */
    /* execute.a64:97 [F] s_b_6_5 = s_b_6_2-s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint8_t)insn.imms) - ((uint8_t)insn.immr)));
    /* execute.a64:97 [F] s_b_6_6 = (u32)s_b_6_5 (const) */
    /* execute.a64:97 [F] s_b_6_7 = constant u32 1 (const) */
    /* execute.a64:97 [F] s_b_6_8 = s_b_6_6+s_b_6_7 (const) */
    uint32_t s_b_6_8 = ((uint32_t)(((uint32_t)s_b_6_5) + (uint32_t)1ULL));
    /* execute.a64:97 [F] s_b_6_9 = (u8)s_b_6_8 (const) */
    /* execute.a64:97 [D] s_b_6_10: sym_52672_3_parameter_src = s_b_6_0, dominates: s_b_19_0 s_b_20_0  */
    emitter.store_local(DV_sym_52672_3_parameter_src, s_b_6_0);
    /* execute.a64:97 [F] s_b_6_11: sym_52663_3_parameter_len = s_b_6_9 (const), dominates: s_b_20_5  */
    CV_sym_52663_3_parameter_len = ((uint8_t)s_b_6_8);
    /* execute.a64:2570 [F] s_b_6_12 = (u32)s_b_6_9 (const) */
    /* execute.a64:2570 [F] s_b_6_13 = constant u32 40 (const) */
    /* execute.a64:2570 [F] s_b_6_14 = s_b_6_12>=s_b_6_13 (const) */
    uint8_t s_b_6_14 = ((uint8_t)(((uint32_t)((uint8_t)s_b_6_8)) >= (uint32_t)64ULL));
    /* execute.a64:2570 [F] s_b_6_15: If s_b_6_14: Jump b_19 else b_20 (const) */
    if (s_b_6_14) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_2,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2720 [F] s_b_7_0=sym_6078_3_parameter_inst.rd (const) */
    /* execute.a64:2714 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2714 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_7_4: If s_b_7_3: Jump b_22 else b_23 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2722 [F] s_b_8_0=sym_6078_3_parameter_inst.rd (const) */
    /* execute.a64:2709 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2709 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_8_4: If s_b_8_3: Jump b_25 else b_26 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_24, b_27,  */
  fixed_block_b_9: 
  {
    /* execute.a64:106 [D] s_b_9_0 = sym_52573_1__R_s_b_2_4 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_52573_1__R_s_b_2_4, emitter.context().types().u64());
    /* execute.a64:106 [D] s_b_9_1 = sym_6102_0_bits uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_6102_0_bits, emitter.context().types().u64());
    /* execute.a64:106 [F] s_b_9_2 = sym_6105_0_pos (const) uint8_t */
    uint8_t s_b_9_2 = CV_sym_6105_0_pos;
    /* execute.a64:106 [F] s_b_9_3 = sym_6117_0_len (const) uint8_t */
    uint8_t s_b_9_3 = CV_sym_6117_0_len;
    /* execute.a64:2579 [F] s_b_9_4 = constant u64 1 (const) */
    /* execute.a64:2579 [F] s_b_9_5 = (u64)s_b_9_3 (const) */
    /* execute.a64:2579 [F] s_b_9_6 = s_b_9_4<<s_b_9_5 (const) */
    uint64_t s_b_9_6 = ((uint64_t)((uint64_t)1ULL << ((uint64_t)s_b_9_3)));
    /* execute.a64:2579 [F] s_b_9_7 = constant u64 1 (const) */
    /* execute.a64:2579 [F] s_b_9_8 = s_b_9_6-s_b_9_7 (const) */
    uint64_t s_b_9_8 = ((uint64_t)(s_b_9_6 - (uint64_t)1ULL));
    /* execute.a64:2579 [F] s_b_9_9 = (u64)s_b_9_2 (const) */
    /* execute.a64:2579 [F] s_b_9_10 = s_b_9_8<<s_b_9_9 (const) */
    uint64_t s_b_9_10 = ((uint64_t)(s_b_9_8 << ((uint64_t)s_b_9_2)));
    /* execute.a64:2580 [D] s_b_9_11 = (u64)s_b_9_0 */
    auto s_b_9_11 = (captive::arch::dbt::el::Value *)s_b_9_0;
    /* execute.a64:2580 [F] s_b_9_12 = ~s_b_9_10 (const) */
    uint64_t s_b_9_12 = ~s_b_9_10;
    /* execute.a64:2580 [D] s_b_9_13 = s_b_9_11&s_b_9_12 */
    auto s_b_9_13 = emitter.bitwise_and(s_b_9_11, emitter.const_u64(s_b_9_12));
    /* execute.a64:2580 [D] s_b_9_14 = (u64)s_b_9_1 */
    auto s_b_9_14 = (captive::arch::dbt::el::Value *)s_b_9_1;
    /* execute.a64:2580 [F] s_b_9_15 = (u64)s_b_9_2 (const) */
    /* execute.a64:2580 [D] s_b_9_16 = s_b_9_14<<s_b_9_15 */
    auto s_b_9_16 = emitter.shl(s_b_9_14, emitter.const_u64(((uint64_t)s_b_9_2)));
    /* execute.a64:2580 [D] s_b_9_17 = s_b_9_13|s_b_9_16 */
    auto s_b_9_17 = emitter.bitwise_or(s_b_9_13, s_b_9_16);
    /* execute.a64:107 [F] s_b_9_18=sym_6078_3_parameter_inst.sf (const) */
    /* execute.a64:107 [D] s_b_9_19: sym_52905_3_parameter_value = s_b_9_17, dominates: s_b_37_1 s_b_38_1  */
    emitter.store_local(DV_sym_52905_3_parameter_value, s_b_9_17);
    /* execute.a64:2753 [F] s_b_9_20: If s_b_9_18: Jump b_37 else b_38 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_37;
    }
    else 
    {
      goto fixed_block_b_38;
    }
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2720 [F] s_b_10_0=sym_6078_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2714 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_10_4: If s_b_10_3: Jump b_28 else b_29 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2722 [F] s_b_11_0=sym_6078_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2709 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_11_4: If s_b_11_3: Jump b_31 else b_32 (const) */
    if (s_b_11_3) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_30, b_33,  */
  fixed_block_b_12: 
  {
    /* execute.a64:101 [D] s_b_12_0 = sym_52598_1__R_s_b_3_4 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_52598_1__R_s_b_3_4, emitter.context().types().u64());
    /* execute.a64:101 [F] s_b_12_1=sym_6078_3_parameter_inst.imms (const) */
    /* execute.a64:101 [F] s_b_12_2 = (u8)s_b_12_1 (const) */
    /* execute.a64:101 [F] s_b_12_3 = constant u8 1 (const) */
    /* execute.a64:101 [F] s_b_12_4 = s_b_12_2+s_b_12_3 (const) */
    uint8_t s_b_12_4 = ((uint8_t)(((uint8_t)insn.imms) + (uint8_t)1ULL));
    /* execute.a64:101 [D] s_b_12_5: sym_52865_3_parameter_src = s_b_12_0, dominates: s_b_34_0 s_b_35_0  */
    emitter.store_local(DV_sym_52865_3_parameter_src, s_b_12_0);
    /* execute.a64:101 [F] s_b_12_6: sym_52856_3_parameter_len = s_b_12_4 (const), dominates: s_b_35_4  */
    CV_sym_52856_3_parameter_len = s_b_12_4;
    /* execute.a64:2570 [F] s_b_12_7 = (u32)s_b_12_4 (const) */
    /* execute.a64:2570 [F] s_b_12_8 = constant u32 40 (const) */
    /* execute.a64:2570 [F] s_b_12_9 = s_b_12_7>=s_b_12_8 (const) */
    uint8_t s_b_12_9 = ((uint8_t)(((uint32_t)s_b_12_4) >= (uint32_t)64ULL));
    /* execute.a64:2570 [F] s_b_12_10: If s_b_12_9: Jump b_34 else b_35 (const) */
    if (s_b_12_9) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_4,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2714 [F] s_b_13_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_13_1: sym_52617_1_temporary_value = s_b_13_0 (const), dominates: s_b_15_0  */
    CV_sym_52617_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_52617_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2714 [F] s_b_14_0=sym_6078_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_14_2: sym_52617_1_temporary_value = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_52617_1_temporary_value, s_b_14_1);
    /* execute.a64:2714 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2714 [D] s_b_15_0 = sym_52617_1_temporary_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_52617_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_15_1: sym_52548_1__R_s_b_1_4 = s_b_15_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_52548_1__R_s_b_1_4, s_b_15_0);
    /* execute.a64:2720 [F] s_b_15_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [F] s_b_16_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_16_1: sym_52645_1_temporary_value = s_b_16_0 (const), dominates: s_b_18_0  */
    CV_sym_52645_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_52645_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2709 [F] s_b_17_0=sym_6078_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_17_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_17_2: sym_52645_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_52645_1_temporary_value, s_b_17_1);
    /* execute.a64:2709 [F] s_b_17_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_16, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2709 [D] s_b_18_0 = sym_52645_1_temporary_value uint32_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_52645_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
    auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_18_2: sym_52548_1__R_s_b_1_4 = s_b_18_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_52548_1__R_s_b_1_4, s_b_18_1);
    /* execute.a64:2722 [F] s_b_18_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2571 [D] s_b_19_0 = sym_52672_3_parameter_src uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_52672_3_parameter_src, emitter.context().types().u64());
    /* execute.a64:2571 [F] s_b_19_1=sym_6078_3_parameter_inst.immr (const) */
    /* execute.a64:2571 [F] s_b_19_2 = (u64)s_b_19_1 (const) */
    /* execute.a64:2571 [D] s_b_19_3 = s_b_19_0>>s_b_19_2 */
    auto s_b_19_3 = emitter.shr(s_b_19_0, emitter.const_u64(((uint64_t)insn.immr)));
    /* execute.a64:2571 [D] s_b_19_4: sym_52696_1__R_s_b_7_15 = s_b_19_3, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_52696_1__R_s_b_7_15, s_b_19_3);
    /* execute.a64:2571 [F] s_b_19_5: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_6,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2573 [D] s_b_20_0 = sym_52672_3_parameter_src uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_52672_3_parameter_src, emitter.context().types().u64());
    /* execute.a64:2573 [F] s_b_20_1=sym_6078_3_parameter_inst.immr (const) */
    /* execute.a64:2573 [F] s_b_20_2 = (u64)s_b_20_1 (const) */
    /* execute.a64:2573 [D] s_b_20_3 = s_b_20_0>>s_b_20_2 */
    auto s_b_20_3 = emitter.shr(s_b_20_0, emitter.const_u64(((uint64_t)insn.immr)));
    /* execute.a64:2573 [F] s_b_20_4 = constant u64 1 (const) */
    /* execute.a64:2573 [F] s_b_20_5 = sym_52663_3_parameter_len (const) uint8_t */
    uint8_t s_b_20_5 = CV_sym_52663_3_parameter_len;
    /* execute.a64:2573 [F] s_b_20_6 = (u64)s_b_20_5 (const) */
    /* execute.a64:2573 [F] s_b_20_7 = s_b_20_4<<s_b_20_6 (const) */
    uint64_t s_b_20_7 = ((uint64_t)((uint64_t)1ULL << ((uint64_t)s_b_20_5)));
    /* execute.a64:2573 [F] s_b_20_8 = constant u64 1 (const) */
    /* execute.a64:2573 [F] s_b_20_9 = s_b_20_7-s_b_20_8 (const) */
    uint64_t s_b_20_9 = ((uint64_t)(s_b_20_7 - (uint64_t)1ULL));
    /* execute.a64:2573 [D] s_b_20_10 = s_b_20_3&s_b_20_9 */
    auto s_b_20_10 = emitter.bitwise_and(s_b_20_3, emitter.const_u64(s_b_20_9));
    /* execute.a64:2573 [D] s_b_20_11: sym_52696_1__R_s_b_7_15 = s_b_20_10, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_52696_1__R_s_b_7_15, s_b_20_10);
    /* execute.a64:2573 [F] s_b_20_12: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_19, b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:97 [D] s_b_21_0 = sym_52696_1__R_s_b_7_15 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_52696_1__R_s_b_7_15, emitter.context().types().u64());
    /* execute.a64:97 [D] s_b_21_1: sym_6102_0_bits = s_b_21_0, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_6102_0_bits, s_b_21_0);
    /* execute.a64:98 [F] s_b_21_2 = constant u8 0 (const) */
    /* execute.a64:98 [F] s_b_21_3: sym_6105_0_pos = s_b_21_2 (const), dominates: s_b_9_2  */
    CV_sym_6105_0_pos = (uint8_t)0ULL;
    /* execute.a64:99 [F] s_b_21_4=sym_6078_3_parameter_inst.imms (const) */
    /* execute.a64:99 [F] s_b_21_5 = (u8)s_b_21_4 (const) */
    /* execute.a64:99 [F] s_b_21_6=sym_6078_3_parameter_inst.immr (const) */
    /* execute.a64:99 [F] s_b_21_7 = (u8)s_b_21_6 (const) */
    /* execute.a64:99 [F] s_b_21_8 = s_b_21_5-s_b_21_7 (const) */
    uint8_t s_b_21_8 = ((uint8_t)(((uint8_t)insn.imms) - ((uint8_t)insn.immr)));
    /* execute.a64:99 [F] s_b_21_9 = (u32)s_b_21_8 (const) */
    /* execute.a64:99 [F] s_b_21_10 = constant u32 1 (const) */
    /* execute.a64:99 [F] s_b_21_11 = s_b_21_9+s_b_21_10 (const) */
    uint32_t s_b_21_11 = ((uint32_t)(((uint32_t)s_b_21_8) + (uint32_t)1ULL));
    /* execute.a64:99 [F] s_b_21_12 = (u8)s_b_21_11 (const) */
    /* execute.a64:99 [F] s_b_21_13: sym_6117_0_len = s_b_21_12 (const), dominates: s_b_9_3  */
    CV_sym_6117_0_len = ((uint8_t)s_b_21_11);
    /* execute.a64:97 [F] s_b_21_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2714 [F] s_b_22_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_22_1: sym_52715_1_temporary_value = s_b_22_0 (const), dominates: s_b_24_0  */
    CV_sym_52715_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_52715_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_22_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_7,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [F] s_b_23_0=sym_6078_3_parameter_inst.rd (const) */
    /* execute.a64:2714 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_23_2: sym_52715_1_temporary_value = s_b_23_1, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_52715_1_temporary_value, s_b_23_1);
    /* execute.a64:2714 [F] s_b_23_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [D] s_b_24_0 = sym_52715_1_temporary_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_52715_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_24_1: sym_52573_1__R_s_b_2_4 = s_b_24_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_52573_1__R_s_b_2_4, s_b_24_0);
    /* execute.a64:2720 [F] s_b_24_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2709 [F] s_b_25_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_25_1: sym_52743_1_temporary_value = s_b_25_0 (const), dominates: s_b_27_0  */
    CV_sym_52743_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_52743_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_25_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_8,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2709 [F] s_b_26_0=sym_6078_3_parameter_inst.rd (const) */
    /* execute.a64:2709 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_26_2: sym_52743_1_temporary_value = s_b_26_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_52743_1_temporary_value, s_b_26_1);
    /* execute.a64:2709 [F] s_b_26_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_25, b_26,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2709 [D] s_b_27_0 = sym_52743_1_temporary_value uint32_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_52743_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_27_1 = (u64)s_b_27_0 */
    auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_27_2: sym_52573_1__R_s_b_2_4 = s_b_27_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_52573_1__R_s_b_2_4, s_b_27_1);
    /* execute.a64:2722 [F] s_b_27_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_10,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2714 [F] s_b_28_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_28_1: sym_52810_1_temporary_value = s_b_28_0 (const), dominates: s_b_30_0  */
    CV_sym_52810_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_52810_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_28_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_10,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2714 [F] s_b_29_0=sym_6078_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_29_1 = ReadRegBank 0:s_b_29_0 (u64) */
    auto s_b_29_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_29_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_29_2: sym_52810_1_temporary_value = s_b_29_1, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_52810_1_temporary_value, s_b_29_1);
    /* execute.a64:2714 [F] s_b_29_3: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_28, b_29,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2714 [D] s_b_30_0 = sym_52810_1_temporary_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_52810_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_30_1: sym_52598_1__R_s_b_3_4 = s_b_30_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_52598_1__R_s_b_3_4, s_b_30_0);
    /* execute.a64:2720 [F] s_b_30_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2709 [F] s_b_31_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_31_1: sym_52838_1_temporary_value = s_b_31_0 (const), dominates: s_b_33_0  */
    CV_sym_52838_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_52838_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_31_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_11,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2709 [F] s_b_32_0=sym_6078_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_32_1 = ReadRegBank 1:s_b_32_0 (u32) */
    auto s_b_32_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_32_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_32_2: sym_52838_1_temporary_value = s_b_32_1, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_52838_1_temporary_value, s_b_32_1);
    /* execute.a64:2709 [F] s_b_32_3: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_31, b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2709 [D] s_b_33_0 = sym_52838_1_temporary_value uint32_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_52838_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_33_1 = (u64)s_b_33_0 */
    auto s_b_33_1 = emitter.zx(s_b_33_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_33_2: sym_52598_1__R_s_b_3_4 = s_b_33_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_52598_1__R_s_b_3_4, s_b_33_1);
    /* execute.a64:2722 [F] s_b_33_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_12,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2571 [D] s_b_34_0 = sym_52865_3_parameter_src uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_52865_3_parameter_src, emitter.context().types().u64());
    /* execute.a64:2571 [F] s_b_34_1 = constant u64 0 (const) */
    /* execute.a64:2571 [D] s_b_34_2 = s_b_34_0>>s_b_34_1 */
    auto s_b_34_2 = emitter.shr(s_b_34_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2571 [D] s_b_34_3: sym_52889_1__R_s_b_15_10 = s_b_34_2, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_52889_1__R_s_b_15_10, s_b_34_2);
    /* execute.a64:2571 [F] s_b_34_4: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_12,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2573 [D] s_b_35_0 = sym_52865_3_parameter_src uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_52865_3_parameter_src, emitter.context().types().u64());
    /* execute.a64:2573 [F] s_b_35_1 = constant u64 0 (const) */
    /* execute.a64:2573 [D] s_b_35_2 = s_b_35_0>>s_b_35_1 */
    auto s_b_35_2 = emitter.shr(s_b_35_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2573 [F] s_b_35_3 = constant u64 1 (const) */
    /* execute.a64:2573 [F] s_b_35_4 = sym_52856_3_parameter_len (const) uint8_t */
    uint8_t s_b_35_4 = CV_sym_52856_3_parameter_len;
    /* execute.a64:2573 [F] s_b_35_5 = (u64)s_b_35_4 (const) */
    /* execute.a64:2573 [F] s_b_35_6 = s_b_35_3<<s_b_35_5 (const) */
    uint64_t s_b_35_6 = ((uint64_t)((uint64_t)1ULL << ((uint64_t)s_b_35_4)));
    /* execute.a64:2573 [F] s_b_35_7 = constant u64 1 (const) */
    /* execute.a64:2573 [F] s_b_35_8 = s_b_35_6-s_b_35_7 (const) */
    uint64_t s_b_35_8 = ((uint64_t)(s_b_35_6 - (uint64_t)1ULL));
    /* execute.a64:2573 [D] s_b_35_9 = s_b_35_2&s_b_35_8 */
    auto s_b_35_9 = emitter.bitwise_and(s_b_35_2, emitter.const_u64(s_b_35_8));
    /* execute.a64:2573 [D] s_b_35_10: sym_52889_1__R_s_b_15_10 = s_b_35_9, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_52889_1__R_s_b_15_10, s_b_35_9);
    /* execute.a64:2573 [F] s_b_35_11: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:101 [D] s_b_36_0 = sym_52889_1__R_s_b_15_10 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_52889_1__R_s_b_15_10, emitter.context().types().u64());
    /* execute.a64:101 [D] s_b_36_1: sym_6102_0_bits = s_b_36_0, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_6102_0_bits, s_b_36_0);
    /* execute.a64:102 [F] s_b_36_2=sym_6078_3_parameter_inst.sf (const) */
    /* execute.a64:102 [F] s_b_36_3 = (u32)s_b_36_2 (const) */
    /* execute.a64:102 [F] s_b_36_4 = constant u32 1 (const) */
    /* execute.a64:102 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.a64:102 [F] s_b_36_6 = constant u8 40 (const) */
    /* execute.a64:102 [F] s_b_36_7 = constant u8 20 (const) */
    /* execute.a64:102 [F] s_b_36_8: Select s_b_36_5 ? s_b_36_6 : s_b_36_7 (const) */
    uint8_t s_b_36_8 = ((uint8_t)(s_b_36_5 ? ((uint8_t)64ULL) : ((uint8_t)32ULL)));
    /* execute.a64:102 [F] s_b_36_9=sym_6078_3_parameter_inst.immr (const) */
    /* execute.a64:102 [F] s_b_36_10 = (u8)s_b_36_9 (const) */
    /* execute.a64:102 [F] s_b_36_11 = s_b_36_8-s_b_36_10 (const) */
    uint8_t s_b_36_11 = ((uint8_t)(s_b_36_8 - ((uint8_t)insn.immr)));
    /* execute.a64:102 [F] s_b_36_12: sym_6105_0_pos = s_b_36_11 (const), dominates: s_b_9_2  */
    CV_sym_6105_0_pos = s_b_36_11;
    /* execute.a64:103 [F] s_b_36_13=sym_6078_3_parameter_inst.imms (const) */
    /* execute.a64:103 [F] s_b_36_14 = (u8)s_b_36_13 (const) */
    /* execute.a64:103 [F] s_b_36_15 = (u32)s_b_36_14 (const) */
    /* execute.a64:103 [F] s_b_36_16 = constant u32 1 (const) */
    /* execute.a64:103 [F] s_b_36_17 = s_b_36_15+s_b_36_16 (const) */
    uint32_t s_b_36_17 = ((uint32_t)(((uint32_t)((uint8_t)insn.imms)) + (uint32_t)1ULL));
    /* execute.a64:103 [F] s_b_36_18 = (u8)s_b_36_17 (const) */
    /* execute.a64:103 [F] s_b_36_19: sym_6117_0_len = s_b_36_18 (const), dominates: s_b_9_3  */
    CV_sym_6117_0_len = ((uint8_t)s_b_36_17);
    /* execute.a64:101 [F] s_b_36_20: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2754 [F] s_b_37_0=sym_6078_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_37_1 = sym_52905_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_52905_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_37_2: sym_52935_3_parameter_value = s_b_37_1, dominates: s_b_40_1  */
    emitter.store_local(DV_sym_52935_3_parameter_value, s_b_37_1);
    /* execute.a64:2745 [F] s_b_37_3 = (u32)s_b_37_0 (const) */
    /* execute.a64:2745 [F] s_b_37_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_37_5 = s_b_37_3==s_b_37_4 (const) */
    uint8_t s_b_37_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_37_6: If s_b_37_5: Jump b_39 else b_40 (const) */
    if (s_b_37_5) 
    {
      goto fixed_block_b_39;
    }
    else 
    {
      goto fixed_block_b_40;
    }
  }
  /* b_9,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2756 [F] s_b_38_0=sym_6078_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_38_1 = sym_52905_3_parameter_value uint64_t */
    auto s_b_38_1 = emitter.load_local(DV_sym_52905_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_38_2 = (u32)s_b_38_1 */
    auto s_b_38_2 = emitter.truncate(s_b_38_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_38_3 = (u64)s_b_38_2 */
    auto s_b_38_3 = emitter.zx(s_b_38_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_38_4: sym_52957_3_parameter_value = s_b_38_3, dominates: s_b_41_1  */
    emitter.store_local(DV_sym_52957_3_parameter_value, s_b_38_3);
    /* execute.a64:2745 [F] s_b_38_5 = (u32)s_b_38_0 (const) */
    /* execute.a64:2745 [F] s_b_38_6 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_38_7 = s_b_38_5==s_b_38_6 (const) */
    uint8_t s_b_38_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_38_8: If s_b_38_7: Jump b_39 else b_41 (const) */
    if (s_b_38_7) 
    {
      goto fixed_block_b_39;
    }
    else 
    {
      goto fixed_block_b_41;
    }
  }
  /* b_37, b_38, b_40, b_41,  */
  fixed_block_b_39: 
  {
    /* ???:4294967295 [F] s_b_39_0: Return */
    goto fixed_done;
  }
  /* b_37,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2747 [F] s_b_40_0=sym_6078_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_40_1 = sym_52935_3_parameter_value uint64_t */
    auto s_b_40_1 = emitter.load_local(DV_sym_52935_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_40_2: WriteRegBank 0:s_b_40_0 = s_b_40_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_40_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_40_1);
    /* execute.a64:0 [F] s_b_40_3: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_38,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2747 [F] s_b_41_0=sym_6078_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_41_1 = sym_52957_3_parameter_value uint64_t */
    auto s_b_41_1 = emitter.load_local(DV_sym_52957_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_41_2: WriteRegBank 0:s_b_41_0 = s_b_41_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_41_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_41_1);
    /* execute.a64:0 [F] s_b_41_3: Jump b_39 (const) */
    goto fixed_block_b_39;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_cbz(const arm64_decode_a64_CMP_B_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_9 = emitter.context().create_block();
  auto block_b_10 = emitter.context().create_block();
  uint32_t CV_sym_55131_1_temporary_value;
  auto DV_sym_55131_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_55103_1_temporary_value;
  auto DV_sym_55103_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_55044_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_6519_0_test_val = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:285 [F] s_b_0_0=sym_6514_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_0_1: If s_b_0_0: Jump b_6 else b_7 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_8,  */
  fixed_block_b_1: 
  {
    /* execute.a64:288 [D] s_b_1_0 = sym_6519_0_test_val uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_6519_0_test_val, emitter.context().types().u64());
    /* execute.a64:288 [F] s_b_1_1 = constant u64 0 (const) */
    /* execute.a64:288 [D] s_b_1_2 = s_b_1_0==s_b_1_1 */
    auto s_b_1_2 = emitter.cmp_eq(s_b_1_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:288 [D] s_b_1_3: If s_b_1_2: Jump b_4 else b_9 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_4;
        dynamic_block_queue.push(block_b_4);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_9;
        dynamic_block_queue.push(block_b_9);
        false_target = block;
      }
      emitter.branch(s_b_1_2, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_8,  */
  fixed_block_b_3: 
  {
    /* execute.a64:294 [D] s_b_3_0 = sym_6519_0_test_val uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_6519_0_test_val, emitter.context().types().u64());
    /* execute.a64:294 [F] s_b_3_1 = constant u64 0 (const) */
    /* execute.a64:294 [D] s_b_3_2 = s_b_3_0!=s_b_3_1 */
    auto s_b_3_2 = emitter.cmp_ne(s_b_3_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:294 [D] s_b_3_3: If s_b_3_2: Jump b_5 else b_10 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_5;
        dynamic_block_queue.push(block_b_5);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_10;
        dynamic_block_queue.push(block_b_10);
        false_target = block;
      }
      emitter.branch(s_b_3_2, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2720 [F] s_b_6_0=sym_6514_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2714 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_6_4: If s_b_6_3: Jump b_11 else b_12 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2722 [F] s_b_7_0=sym_6514_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2709 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_7_4: If s_b_7_3: Jump b_14 else b_15 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_13, b_16,  */
  fixed_block_b_8: 
  {
    /* execute.a64:285 [D] s_b_8_0 = sym_55044_1__R_s_b_0_4 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_55044_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:285 [D] s_b_8_1: sym_6519_0_test_val = s_b_8_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_6519_0_test_val, s_b_8_0);
    /* execute.a64:287 [F] s_b_8_2=sym_6514_3_parameter_inst.op (const) */
    /* execute.a64:287 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:287 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:287 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.op) == (uint32_t)0ULL));
    /* execute.a64:287 [F] s_b_8_6: If s_b_8_5: Jump b_1 else b_3 (const) */
    if (s_b_8_5) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  // BLOCK b_9 not fully fixed
  // BLOCK b_10 not fully fixed
  /* b_6,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2714 [F] s_b_11_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_11_1: sym_55103_1_temporary_value = s_b_11_0 (const), dominates: s_b_13_0  */
    CV_sym_55103_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_55103_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_6,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2714 [F] s_b_12_0=sym_6514_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_12_1 = ReadRegBank 0:s_b_12_0 (u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_12_2: sym_55103_1_temporary_value = s_b_12_1, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_55103_1_temporary_value, s_b_12_1);
    /* execute.a64:2714 [F] s_b_12_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_11, b_12,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2714 [D] s_b_13_0 = sym_55103_1_temporary_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_55103_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_13_1: sym_55044_1__R_s_b_0_4 = s_b_13_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_55044_1__R_s_b_0_4, s_b_13_0);
    /* execute.a64:2720 [F] s_b_13_2: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_14_1: sym_55131_1_temporary_value = s_b_14_0 (const), dominates: s_b_16_0  */
    CV_sym_55131_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_55131_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_14_2: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_7,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2709 [F] s_b_15_0=sym_6514_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_15_1 = ReadRegBank 1:s_b_15_0 (u32) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_15_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_15_2: sym_55131_1_temporary_value = s_b_15_1, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_55131_1_temporary_value, s_b_15_1);
    /* execute.a64:2709 [F] s_b_15_3: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_14, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [D] s_b_16_0 = sym_55131_1_temporary_value uint32_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_55131_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_16_1 = (u64)s_b_16_0 */
    auto s_b_16_1 = emitter.zx(s_b_16_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_16_2: sym_55044_1__R_s_b_0_4 = s_b_16_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_55044_1__R_s_b_0_4, s_b_16_1);
    /* execute.a64:2722 [F] s_b_16_3: Jump b_8 (const) */
    goto fixed_block_b_8;
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
        /* execute.a64:289 [D] s_b_4_0 = read_pc */
        auto s_b_4_0 = emitter.load_pc();
        /* execute.a64:289 [D] s_b_4_1 = (s64)s_b_4_0 */
        auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s64());
        /* execute.a64:289 [F] s_b_4_2=sym_6514_3_parameter_inst.imms64 (const) */
        /* execute.a64:289 [D] s_b_4_3 = s_b_4_1+s_b_4_2 */
        auto s_b_4_3 = emitter.add(s_b_4_1, emitter.const_s64(insn.imms64));
        /* execute.a64:289 [D] s_b_4_4 = (u64)s_b_4_3 */
        auto s_b_4_4 = emitter.reinterpret(s_b_4_3, emitter.context().types().u64());
        /* execute.a64:571 [D] s_b_4_5 = write_pc */
        emitter.store_pc(s_b_4_4);
        /* execute.a64:572 [D] s_b_4_6 = __branch_taken */
        emitter.call(__captive___branch_taken);
        /* ???:4294967295 [F] s_b_4_7: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:295 [D] s_b_5_0 = read_pc */
        auto s_b_5_0 = emitter.load_pc();
        /* execute.a64:295 [D] s_b_5_1 = (s64)s_b_5_0 */
        auto s_b_5_1 = emitter.reinterpret(s_b_5_0, emitter.context().types().s64());
        /* execute.a64:295 [F] s_b_5_2=sym_6514_3_parameter_inst.imms64 (const) */
        /* execute.a64:295 [D] s_b_5_3 = s_b_5_1+s_b_5_2 */
        auto s_b_5_3 = emitter.add(s_b_5_1, emitter.const_s64(insn.imms64));
        /* execute.a64:295 [D] s_b_5_4 = (u64)s_b_5_3 */
        auto s_b_5_4 = emitter.reinterpret(s_b_5_3, emitter.context().types().u64());
        /* execute.a64:571 [D] s_b_5_5 = write_pc */
        emitter.store_pc(s_b_5_4);
        /* execute.a64:572 [D] s_b_5_6 = __branch_taken */
        emitter.call(__captive___branch_taken);
        /* ???:4294967295 [F] s_b_5_7: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.a64:578 [D] s_b_9_0 = read_pc */
        auto s_b_9_0 = emitter.load_pc();
        /* execute.a64:578 [F] s_b_9_1 = constant u64 4 (const) */
        /* execute.a64:578 [D] s_b_9_2 = s_b_9_0+s_b_9_1 */
        auto s_b_9_2 = emitter.add(s_b_9_0, emitter.const_u64((uint64_t)4ULL));
        /* execute.a64:578 [D] s_b_9_3 = write_pc */
        emitter.store_pc(s_b_9_2);
        /* execute.a64:579 [D] s_b_9_4 = __branch_not_taken */
        emitter.call(__captive___branch_not_taken);
        /* execute.a64:0 [F] s_b_9_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.a64:578 [D] s_b_10_0 = read_pc */
        auto s_b_10_0 = emitter.load_pc();
        /* execute.a64:578 [F] s_b_10_1 = constant u64 4 (const) */
        /* execute.a64:578 [D] s_b_10_2 = s_b_10_0+s_b_10_1 */
        auto s_b_10_2 = emitter.add(s_b_10_0, emitter.const_u64((uint64_t)4ULL));
        /* execute.a64:578 [D] s_b_10_3 = write_pc */
        emitter.store_pc(s_b_10_2);
        /* execute.a64:579 [D] s_b_10_4 = __branch_not_taken */
        emitter.call(__captive___branch_not_taken);
        /* execute.a64:0 [F] s_b_10_5: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_cmeq_reg(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
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
    /* execute.simd:1456 [F] s_b_0_0=sym_7073_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1456 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1457 [F] s_b_1_0=sym_7073_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:1458 [F] s_b_1_2=sym_7073_3_parameter_inst.rm (const) */
    /* execute.simd:6355 [D] s_b_1_3 = ReadRegBank 7:s_b_1_2 (u64) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(8));
    }
    /* execute.simd:1460 [D] s_b_1_4 = s_b_1_1==s_b_1_3 */
    auto s_b_1_4 = emitter.cmp_eq(s_b_1_1, s_b_1_3);
    /* execute.simd:1460 [D] s_b_1_5: If s_b_1_4: Jump b_4 else b_5 */
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
      emitter.branch(s_b_1_4, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1466 [F] s_b_3_0=sym_7073_3_parameter_inst.arrangement (const) */
    /* execute.simd:1467 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:1477 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:1486 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:1496 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:1505 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:1515 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:1524 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:1466 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_13 (const) -> b_13, b_12, b_11, b_10, b_9, b_8, b_7, b_6,  */
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
    /* execute.simd:1468 [F] s_b_6_0=sym_7073_3_parameter_inst.rn (const) */
    /* execute.simd:1468 [D] s_b_6_1 = ReadRegBank 15:s_b_6_0 (v8u8) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1469 [F] s_b_6_2=sym_7073_3_parameter_inst.rm (const) */
    /* execute.simd:1469 [D] s_b_6_3 = ReadRegBank 15:s_b_6_2 (v8u8) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1471 [D] s_b_6_4 = s_b_6_1==s_b_6_3 */
    auto s_b_6_4 = emitter.cmp_eq(s_b_6_1, s_b_6_3);
    /* execute.simd:1472 [F] s_b_6_5=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1472 [D] s_b_6_6: WriteRegBank 15:s_b_6_5 = s_b_6_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
    /* execute.simd:1473 [F] s_b_6_7=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1473 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:1473 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_10: Jump b_2 (const) */
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
    /* execute.simd:1478 [F] s_b_7_0=sym_7073_3_parameter_inst.rn (const) */
    /* execute.simd:1478 [D] s_b_7_1 = ReadRegBank 16:s_b_7_0 (v16u8) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:1479 [F] s_b_7_2=sym_7073_3_parameter_inst.rm (const) */
    /* execute.simd:1479 [D] s_b_7_3 = ReadRegBank 16:s_b_7_2 (v16u8) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:1481 [D] s_b_7_4 = s_b_7_1==s_b_7_3 */
    auto s_b_7_4 = emitter.cmp_eq(s_b_7_1, s_b_7_3);
    /* execute.simd:1482 [F] s_b_7_5=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1482 [D] s_b_7_6: WriteRegBank 16:s_b_7_5 = s_b_7_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4);
    /* execute.simd:0 [F] s_b_7_7: Jump b_2 (const) */
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
    /* execute.simd:1487 [F] s_b_8_0=sym_7073_3_parameter_inst.rn (const) */
    /* execute.simd:1487 [D] s_b_8_1 = ReadRegBank 17:s_b_8_0 (v4u16) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:1488 [F] s_b_8_2=sym_7073_3_parameter_inst.rm (const) */
    /* execute.simd:1488 [D] s_b_8_3 = ReadRegBank 17:s_b_8_2 (v4u16) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(8));
    }
    /* execute.simd:1490 [D] s_b_8_4 = s_b_8_1==s_b_8_3 */
    auto s_b_8_4 = emitter.cmp_eq(s_b_8_1, s_b_8_3);
    /* execute.simd:1491 [F] s_b_8_5=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1491 [D] s_b_8_6: WriteRegBank 17:s_b_8_5 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4);
    /* execute.simd:1492 [F] s_b_8_7=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1492 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:1492 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_10: Jump b_2 (const) */
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
    /* execute.simd:1497 [F] s_b_9_0=sym_7073_3_parameter_inst.rn (const) */
    /* execute.simd:1497 [D] s_b_9_1 = ReadRegBank 18:s_b_9_0 (v8u16) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:1498 [F] s_b_9_2=sym_7073_3_parameter_inst.rm (const) */
    /* execute.simd:1498 [D] s_b_9_3 = ReadRegBank 18:s_b_9_2 (v8u16) */
    auto s_b_9_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_9_3,emitter.const_u8(16));
    }
    /* execute.simd:1500 [D] s_b_9_4 = s_b_9_1==s_b_9_3 */
    auto s_b_9_4 = emitter.cmp_eq(s_b_9_1, s_b_9_3);
    /* execute.simd:1502 [F] s_b_9_5=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1502 [D] s_b_9_6: WriteRegBank 18:s_b_9_5 = s_b_9_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_4);
    /* execute.simd:0 [F] s_b_9_7: Jump b_2 (const) */
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
    /* execute.simd:1506 [F] s_b_10_0=sym_7073_3_parameter_inst.rn (const) */
    /* execute.simd:1506 [D] s_b_10_1 = ReadRegBank 19:s_b_10_0 (v2u32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.simd:1507 [F] s_b_10_2=sym_7073_3_parameter_inst.rm (const) */
    /* execute.simd:1507 [D] s_b_10_3 = ReadRegBank 19:s_b_10_2 (v2u32) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:1509 [D] s_b_10_4 = s_b_10_1==s_b_10_3 */
    auto s_b_10_4 = emitter.cmp_eq(s_b_10_1, s_b_10_3);
    /* execute.simd:1510 [F] s_b_10_5=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1510 [D] s_b_10_6: WriteRegBank 19:s_b_10_5 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4);
    /* execute.simd:1511 [F] s_b_10_7=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1511 [F] s_b_10_8 = constant u64 0 (const) */
    /* execute.simd:1511 [F] s_b_10_9: WriteRegBank 3:s_b_10_7 = s_b_10_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_10_10: Jump b_2 (const) */
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
    /* execute.simd:1516 [F] s_b_11_0=sym_7073_3_parameter_inst.rn (const) */
    /* execute.simd:1516 [D] s_b_11_1 = ReadRegBank 20:s_b_11_0 (v4u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_11_1,emitter.const_u8(16));
    }
    /* execute.simd:1517 [F] s_b_11_2=sym_7073_3_parameter_inst.rm (const) */
    /* execute.simd:1517 [D] s_b_11_3 = ReadRegBank 20:s_b_11_2 (v4u32) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:1519 [D] s_b_11_4 = s_b_11_1==s_b_11_3 */
    auto s_b_11_4 = emitter.cmp_eq(s_b_11_1, s_b_11_3);
    /* execute.simd:1521 [F] s_b_11_5=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1521 [D] s_b_11_6: WriteRegBank 20:s_b_11_5 = s_b_11_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_4);
    /* execute.simd:0 [F] s_b_11_7: Jump b_2 (const) */
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
    /* execute.simd:1525 [F] s_b_12_0=sym_7073_3_parameter_inst.rn (const) */
    /* execute.simd:1525 [D] s_b_12_1 = ReadRegBank 21:s_b_12_0 (v2u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(16));
    }
    /* execute.simd:1526 [F] s_b_12_2=sym_7073_3_parameter_inst.rm (const) */
    /* execute.simd:1526 [D] s_b_12_3 = ReadRegBank 21:s_b_12_2 (v2u64) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_12_3,emitter.const_u8(16));
    }
    /* execute.simd:1528 [D] s_b_12_4 = s_b_12_1==s_b_12_3 */
    auto s_b_12_4 = emitter.cmp_eq(s_b_12_1, s_b_12_3);
    /* execute.simd:1530 [F] s_b_12_5=sym_7073_3_parameter_inst.rd (const) */
    /* execute.simd:1530 [D] s_b_12_6: WriteRegBank 21:s_b_12_5 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_4);
    /* execute.simd:0 [F] s_b_12_7: Jump b_2 (const) */
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
    /* execute.simd:1534 [D] s_b_13_0 = trap */
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
        /* execute.simd:1461 [F] s_b_4_0=sym_7073_3_parameter_inst.rd (const) */
        /* execute.simd:1461 [F] s_b_4_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6326 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
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
        /* execute.simd:1463 [F] s_b_5_0=sym_7073_3_parameter_inst.rd (const) */
        /* execute.simd:1463 [F] s_b_5_1 = constant u64 0 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_crc32(const arm64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_dup_gen(const arm64_decode_a64_SIMD_COPY&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_59304_1__R_s_b_0_8 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_9926_0_rlo = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_9879_0_element = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_59384_1_temporary_value;
  auto DV_sym_59384_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_59356_1_temporary_value;
  auto DV_sym_59356_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:447 [F] s_b_0_0=sym_9870_3_parameter_inst.width (const) */
    /* execute.simd:447 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:447 [F] s_b_0_2 = constant u32 40 (const) */
    /* execute.simd:447 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.width) == (uint32_t)64ULL));
    /* execute.a64:2719 [F] s_b_0_4: If s_b_0_3: Jump b_13 else b_14 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8, b_9,  */
  fixed_block_b_1: 
  {
    /* execute.simd:491 [F] s_b_1_0=sym_9870_3_parameter_inst.Q (const) */
    /* execute.simd:491 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:491 [F] s_b_1_2 = constant u32 1 (const) */
    /* execute.simd:491 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* execute.simd:491 [F] s_b_1_4: If s_b_1_3: Jump b_10 else b_12 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_15,  */
  fixed_block_b_2: 
  {
    /* execute.simd:452 [D] s_b_2_0 = sym_9879_0_element uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_9879_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_2_1 = constant u64 ff (const) */
    /* ???:4294967295 [D] s_b_2_2 = s_b_2_0&s_b_2_1 */
    auto s_b_2_2 = emitter.bitwise_and(s_b_2_0, emitter.const_u64((uint64_t)255ULL));
    /* execute.simd:452 [D] s_b_2_3: sym_9879_0_element = s_b_2_2, dominates:  */
    emitter.store_local(DV_sym_9879_0_element, s_b_2_2);
    /* execute.simd:453 [F] s_b_2_4 = constant u64 8 (const) */
    /* execute.simd:453 [D] s_b_2_5 = s_b_2_2<<s_b_2_4 */
    auto s_b_2_5 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)8ULL));
    /* execute.simd:453 [D] s_b_2_6 = s_b_2_2|s_b_2_5 */
    auto s_b_2_6 = emitter.bitwise_or(s_b_2_2, s_b_2_5);
    /* execute.simd:453 [F] s_b_2_7 = constant u64 10 (const) */
    /* execute.simd:453 [D] s_b_2_8 = s_b_2_2<<s_b_2_7 */
    auto s_b_2_8 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)16ULL));
    /* execute.simd:453 [D] s_b_2_9 = s_b_2_6|s_b_2_8 */
    auto s_b_2_9 = emitter.bitwise_or(s_b_2_6, s_b_2_8);
    /* execute.simd:453 [F] s_b_2_10 = constant u64 18 (const) */
    /* execute.simd:453 [D] s_b_2_11 = s_b_2_2<<s_b_2_10 */
    auto s_b_2_11 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)24ULL));
    /* execute.simd:453 [D] s_b_2_12 = s_b_2_9|s_b_2_11 */
    auto s_b_2_12 = emitter.bitwise_or(s_b_2_9, s_b_2_11);
    /* execute.simd:453 [F] s_b_2_13 = constant u64 20 (const) */
    /* execute.simd:453 [D] s_b_2_14 = s_b_2_2<<s_b_2_13 */
    auto s_b_2_14 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:453 [D] s_b_2_15 = s_b_2_12|s_b_2_14 */
    auto s_b_2_15 = emitter.bitwise_or(s_b_2_12, s_b_2_14);
    /* execute.simd:453 [F] s_b_2_16 = constant u64 28 (const) */
    /* execute.simd:453 [D] s_b_2_17 = s_b_2_2<<s_b_2_16 */
    auto s_b_2_17 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)40ULL));
    /* execute.simd:453 [D] s_b_2_18 = s_b_2_15|s_b_2_17 */
    auto s_b_2_18 = emitter.bitwise_or(s_b_2_15, s_b_2_17);
    /* execute.simd:453 [F] s_b_2_19 = constant u64 30 (const) */
    /* execute.simd:453 [D] s_b_2_20 = s_b_2_2<<s_b_2_19 */
    auto s_b_2_20 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)48ULL));
    /* execute.simd:453 [D] s_b_2_21 = s_b_2_18|s_b_2_20 */
    auto s_b_2_21 = emitter.bitwise_or(s_b_2_18, s_b_2_20);
    /* execute.simd:453 [F] s_b_2_22 = constant u64 38 (const) */
    /* execute.simd:453 [D] s_b_2_23 = s_b_2_2<<s_b_2_22 */
    auto s_b_2_23 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)56ULL));
    /* execute.simd:453 [D] s_b_2_24 = s_b_2_21|s_b_2_23 */
    auto s_b_2_24 = emitter.bitwise_or(s_b_2_21, s_b_2_23);
    /* execute.simd:453 [D] s_b_2_25: sym_9926_0_rlo = s_b_2_24, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9926_0_rlo, s_b_2_24);
    /* execute.simd:0 [F] s_b_2_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_3: 
  {
    /* execute.simd:457 [D] s_b_3_0 = sym_9879_0_element uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_9879_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_3_1 = constant u64 ff (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0&s_b_3_1 */
    auto s_b_3_2 = emitter.bitwise_and(s_b_3_0, emitter.const_u64((uint64_t)255ULL));
    /* execute.simd:457 [D] s_b_3_3: sym_9879_0_element = s_b_3_2, dominates:  */
    emitter.store_local(DV_sym_9879_0_element, s_b_3_2);
    /* execute.simd:458 [F] s_b_3_4 = constant u64 8 (const) */
    /* execute.simd:458 [D] s_b_3_5 = s_b_3_2<<s_b_3_4 */
    auto s_b_3_5 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)8ULL));
    /* execute.simd:458 [D] s_b_3_6 = s_b_3_2|s_b_3_5 */
    auto s_b_3_6 = emitter.bitwise_or(s_b_3_2, s_b_3_5);
    /* execute.simd:458 [F] s_b_3_7 = constant u64 10 (const) */
    /* execute.simd:458 [D] s_b_3_8 = s_b_3_2<<s_b_3_7 */
    auto s_b_3_8 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)16ULL));
    /* execute.simd:458 [D] s_b_3_9 = s_b_3_6|s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_or(s_b_3_6, s_b_3_8);
    /* execute.simd:458 [F] s_b_3_10 = constant u64 18 (const) */
    /* execute.simd:458 [D] s_b_3_11 = s_b_3_2<<s_b_3_10 */
    auto s_b_3_11 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)24ULL));
    /* execute.simd:458 [D] s_b_3_12 = s_b_3_9|s_b_3_11 */
    auto s_b_3_12 = emitter.bitwise_or(s_b_3_9, s_b_3_11);
    /* execute.simd:458 [F] s_b_3_13 = constant u64 20 (const) */
    /* execute.simd:458 [D] s_b_3_14 = s_b_3_2<<s_b_3_13 */
    auto s_b_3_14 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:458 [D] s_b_3_15 = s_b_3_12|s_b_3_14 */
    auto s_b_3_15 = emitter.bitwise_or(s_b_3_12, s_b_3_14);
    /* execute.simd:458 [F] s_b_3_16 = constant u64 28 (const) */
    /* execute.simd:458 [D] s_b_3_17 = s_b_3_2<<s_b_3_16 */
    auto s_b_3_17 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)40ULL));
    /* execute.simd:458 [D] s_b_3_18 = s_b_3_15|s_b_3_17 */
    auto s_b_3_18 = emitter.bitwise_or(s_b_3_15, s_b_3_17);
    /* execute.simd:458 [F] s_b_3_19 = constant u64 30 (const) */
    /* execute.simd:458 [D] s_b_3_20 = s_b_3_2<<s_b_3_19 */
    auto s_b_3_20 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)48ULL));
    /* execute.simd:458 [D] s_b_3_21 = s_b_3_18|s_b_3_20 */
    auto s_b_3_21 = emitter.bitwise_or(s_b_3_18, s_b_3_20);
    /* execute.simd:458 [F] s_b_3_22 = constant u64 38 (const) */
    /* execute.simd:458 [D] s_b_3_23 = s_b_3_2<<s_b_3_22 */
    auto s_b_3_23 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)56ULL));
    /* execute.simd:458 [D] s_b_3_24 = s_b_3_21|s_b_3_23 */
    auto s_b_3_24 = emitter.bitwise_or(s_b_3_21, s_b_3_23);
    /* execute.simd:458 [D] s_b_3_25: sym_9926_0_rlo = s_b_3_24, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9926_0_rlo, s_b_3_24);
    /* execute.simd:0 [F] s_b_3_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_4: 
  {
    /* execute.simd:462 [D] s_b_4_0 = sym_9879_0_element uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_9879_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_4_1 = constant u64 ffff (const) */
    /* ???:4294967295 [D] s_b_4_2 = s_b_4_0&s_b_4_1 */
    auto s_b_4_2 = emitter.bitwise_and(s_b_4_0, emitter.const_u64((uint64_t)65535ULL));
    /* execute.simd:462 [D] s_b_4_3: sym_9879_0_element = s_b_4_2, dominates:  */
    emitter.store_local(DV_sym_9879_0_element, s_b_4_2);
    /* execute.simd:463 [F] s_b_4_4 = constant u64 10 (const) */
    /* execute.simd:463 [D] s_b_4_5 = s_b_4_2<<s_b_4_4 */
    auto s_b_4_5 = emitter.shl(s_b_4_2, emitter.const_u64((uint64_t)16ULL));
    /* execute.simd:463 [D] s_b_4_6 = s_b_4_2|s_b_4_5 */
    auto s_b_4_6 = emitter.bitwise_or(s_b_4_2, s_b_4_5);
    /* execute.simd:463 [F] s_b_4_7 = constant u64 20 (const) */
    /* execute.simd:463 [D] s_b_4_8 = s_b_4_2<<s_b_4_7 */
    auto s_b_4_8 = emitter.shl(s_b_4_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:463 [D] s_b_4_9 = s_b_4_6|s_b_4_8 */
    auto s_b_4_9 = emitter.bitwise_or(s_b_4_6, s_b_4_8);
    /* execute.simd:463 [F] s_b_4_10 = constant u64 30 (const) */
    /* execute.simd:463 [D] s_b_4_11 = s_b_4_2<<s_b_4_10 */
    auto s_b_4_11 = emitter.shl(s_b_4_2, emitter.const_u64((uint64_t)48ULL));
    /* execute.simd:463 [D] s_b_4_12 = s_b_4_9|s_b_4_11 */
    auto s_b_4_12 = emitter.bitwise_or(s_b_4_9, s_b_4_11);
    /* execute.simd:463 [D] s_b_4_13: sym_9926_0_rlo = s_b_4_12, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9926_0_rlo, s_b_4_12);
    /* execute.simd:0 [F] s_b_4_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_5: 
  {
    /* execute.simd:467 [D] s_b_5_0 = sym_9879_0_element uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_9879_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_5_1 = constant u64 ffff (const) */
    /* ???:4294967295 [D] s_b_5_2 = s_b_5_0&s_b_5_1 */
    auto s_b_5_2 = emitter.bitwise_and(s_b_5_0, emitter.const_u64((uint64_t)65535ULL));
    /* execute.simd:467 [D] s_b_5_3: sym_9879_0_element = s_b_5_2, dominates:  */
    emitter.store_local(DV_sym_9879_0_element, s_b_5_2);
    /* execute.simd:468 [F] s_b_5_4 = constant u64 10 (const) */
    /* execute.simd:468 [D] s_b_5_5 = s_b_5_2<<s_b_5_4 */
    auto s_b_5_5 = emitter.shl(s_b_5_2, emitter.const_u64((uint64_t)16ULL));
    /* execute.simd:468 [D] s_b_5_6 = s_b_5_2|s_b_5_5 */
    auto s_b_5_6 = emitter.bitwise_or(s_b_5_2, s_b_5_5);
    /* execute.simd:468 [F] s_b_5_7 = constant u64 20 (const) */
    /* execute.simd:468 [D] s_b_5_8 = s_b_5_2<<s_b_5_7 */
    auto s_b_5_8 = emitter.shl(s_b_5_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:468 [D] s_b_5_9 = s_b_5_6|s_b_5_8 */
    auto s_b_5_9 = emitter.bitwise_or(s_b_5_6, s_b_5_8);
    /* execute.simd:468 [F] s_b_5_10 = constant u64 30 (const) */
    /* execute.simd:468 [D] s_b_5_11 = s_b_5_2<<s_b_5_10 */
    auto s_b_5_11 = emitter.shl(s_b_5_2, emitter.const_u64((uint64_t)48ULL));
    /* execute.simd:468 [D] s_b_5_12 = s_b_5_9|s_b_5_11 */
    auto s_b_5_12 = emitter.bitwise_or(s_b_5_9, s_b_5_11);
    /* execute.simd:468 [D] s_b_5_13: sym_9926_0_rlo = s_b_5_12, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9926_0_rlo, s_b_5_12);
    /* execute.simd:0 [F] s_b_5_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_6: 
  {
    /* execute.simd:472 [D] s_b_6_0 = sym_9879_0_element uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_9879_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_6_2 = s_b_6_0&s_b_6_1 */
    auto s_b_6_2 = emitter.bitwise_and(s_b_6_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.simd:472 [D] s_b_6_3: sym_9879_0_element = s_b_6_2, dominates:  */
    emitter.store_local(DV_sym_9879_0_element, s_b_6_2);
    /* execute.simd:473 [F] s_b_6_4 = constant u64 20 (const) */
    /* execute.simd:473 [D] s_b_6_5 = s_b_6_2<<s_b_6_4 */
    auto s_b_6_5 = emitter.shl(s_b_6_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:473 [D] s_b_6_6 = s_b_6_2|s_b_6_5 */
    auto s_b_6_6 = emitter.bitwise_or(s_b_6_2, s_b_6_5);
    /* execute.simd:473 [D] s_b_6_7: sym_9926_0_rlo = s_b_6_6, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9926_0_rlo, s_b_6_6);
    /* execute.simd:0 [F] s_b_6_8: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_7: 
  {
    /* execute.simd:477 [D] s_b_7_0 = sym_9879_0_element uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_9879_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_7_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_7_2 = s_b_7_0&s_b_7_1 */
    auto s_b_7_2 = emitter.bitwise_and(s_b_7_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.simd:477 [D] s_b_7_3: sym_9879_0_element = s_b_7_2, dominates:  */
    emitter.store_local(DV_sym_9879_0_element, s_b_7_2);
    /* execute.simd:478 [F] s_b_7_4 = constant u64 20 (const) */
    /* execute.simd:478 [D] s_b_7_5 = s_b_7_2<<s_b_7_4 */
    auto s_b_7_5 = emitter.shl(s_b_7_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:478 [D] s_b_7_6 = s_b_7_2|s_b_7_5 */
    auto s_b_7_6 = emitter.bitwise_or(s_b_7_2, s_b_7_5);
    /* execute.simd:478 [D] s_b_7_7: sym_9926_0_rlo = s_b_7_6, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9926_0_rlo, s_b_7_6);
    /* execute.simd:0 [F] s_b_7_8: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_8: 
  {
    /* execute.simd:482 [D] s_b_8_0 = sym_9879_0_element uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_9879_0_element, emitter.context().types().u64());
    /* execute.simd:482 [D] s_b_8_1: sym_9926_0_rlo = s_b_8_0, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9926_0_rlo, s_b_8_0);
    /* execute.simd:0 [F] s_b_8_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_9: 
  {
    /* execute.simd:486 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.simd:492 [F] s_b_10_0=sym_9870_3_parameter_inst.rd (const) */
    /* execute.simd:492 [D] s_b_10_1 = sym_9926_0_rlo uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_9926_0_rlo, emitter.context().types().u64());
    /* execute.simd:6333 [D] s_b_10_2: WriteRegBank 2:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_1);
    /* execute.simd:6334 [D] s_b_10_3: WriteRegBank 3:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_10_1);
    /* execute.simd:0 [F] s_b_10_4: Jump b_11 (const) */
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
    /* execute.simd:494 [F] s_b_12_0=sym_9870_3_parameter_inst.rd (const) */
    /* execute.simd:494 [D] s_b_12_1 = sym_9926_0_rlo uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_9926_0_rlo, emitter.context().types().u64());
    /* execute.simd:6326 [D] s_b_12_2: WriteRegBank 2:s_b_12_0 = s_b_12_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_1);
    /* execute.simd:6327 [F] s_b_12_3 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_12_4: WriteRegBank 3:s_b_12_0 = s_b_12_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_12_5: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2720 [F] s_b_13_0=sym_9870_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:2714 [F] s_b_13_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_13_4: If s_b_13_3: Jump b_16 else b_17 (const) */
    if (s_b_13_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2722 [F] s_b_14_0=sym_9870_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
    /* execute.a64:2709 [F] s_b_14_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_14_3 = s_b_14_1==s_b_14_2 (const) */
    uint8_t s_b_14_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_14_4: If s_b_14_3: Jump b_19 else b_20 (const) */
    if (s_b_14_3) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_18, b_21,  */
  fixed_block_b_15: 
  {
    /* execute.simd:447 [D] s_b_15_0 = sym_59304_1__R_s_b_0_8 uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_59304_1__R_s_b_0_8, emitter.context().types().u64());
    /* execute.simd:447 [D] s_b_15_1: sym_9879_0_element = s_b_15_0, dominates: s_b_8_0 s_b_7_0 s_b_6_0 s_b_5_0 s_b_4_0 s_b_3_0 s_b_2_0  */
    emitter.store_local(DV_sym_9879_0_element, s_b_15_0);
    /* execute.simd:450 [F] s_b_15_2=sym_9870_3_parameter_inst.arrangement (const) */
    /* execute.simd:451 [F] s_b_15_3 = constant s32 0 (const) */
    /* execute.simd:456 [F] s_b_15_4 = constant s32 1 (const) */
    /* execute.simd:461 [F] s_b_15_5 = constant s32 2 (const) */
    /* execute.simd:466 [F] s_b_15_6 = constant s32 3 (const) */
    /* execute.simd:471 [F] s_b_15_7 = constant s32 4 (const) */
    /* execute.simd:476 [F] s_b_15_8 = constant s32 5 (const) */
    /* execute.simd:481 [F] s_b_15_9 = constant s32 6 (const) */
    /* execute.simd:450 [F] s_b_15_10: Switch s_b_15_2: < <todo> > def b_9 (const) -> b_9, b_8, b_7, b_6, b_5, b_4, b_3, b_2,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_6;
      break;
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
      goto fixed_block_b_9;
    }
  }
  /* b_13,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2714 [F] s_b_16_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_16_1: sym_59356_1_temporary_value = s_b_16_0 (const), dominates: s_b_18_0  */
    CV_sym_59356_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_59356_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2714 [F] s_b_17_0=sym_9870_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_17_1 = ReadRegBank 0:s_b_17_0 (u64) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_17_2: sym_59356_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_59356_1_temporary_value, s_b_17_1);
    /* execute.a64:2714 [F] s_b_17_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_16, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2714 [D] s_b_18_0 = sym_59356_1_temporary_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_59356_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_18_1: sym_59304_1__R_s_b_0_8 = s_b_18_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_59304_1__R_s_b_0_8, s_b_18_0);
    /* execute.a64:2720 [F] s_b_18_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2709 [F] s_b_19_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_19_1: sym_59384_1_temporary_value = s_b_19_0 (const), dominates: s_b_21_0  */
    CV_sym_59384_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_59384_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_19_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_14,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2709 [F] s_b_20_0=sym_9870_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_20_1 = ReadRegBank 1:s_b_20_0 (u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_20_2: sym_59384_1_temporary_value = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_59384_1_temporary_value, s_b_20_1);
    /* execute.a64:2709 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_19, b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2709 [D] s_b_21_0 = sym_59384_1_temporary_value uint32_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_59384_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_21_1 = (u64)s_b_21_0 */
    auto s_b_21_1 = emitter.zx(s_b_21_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_21_2: sym_59304_1__R_s_b_0_8 = s_b_21_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_59304_1__R_s_b_0_8, s_b_21_1);
    /* execute.a64:2722 [F] s_b_21_3: Jump b_15 (const) */
    goto fixed_block_b_15;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fabd(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1804 [F] s_b_0_0=sym_10497_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1804 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1805 [F] s_b_1_0=sym_10497_3_parameter_inst.size (const) */
    /* execute.simd:1805 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:1805 [F] s_b_1_2 = constant u32 2 (const) */
    /* execute.simd:1805 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:1805 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:1817 [D] s_b_3_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:1817 [F] s_b_3_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1806 [F] s_b_4_0=sym_10497_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_4_1 = ReadRegBank 9:s_b_4_0 (f32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(4));
    }
    /* execute.simd:1807 [F] s_b_4_2=sym_10497_3_parameter_inst.rm (const) */
    /* execute.simd:6280 [D] s_b_4_3 = ReadRegBank 9:s_b_4_2 (f32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(4));
    }
    /* execute.simd:1809 [F] s_b_4_4=sym_10497_3_parameter_inst.rd (const) */
    /* execute.simd:1809 [D] s_b_4_5 = s_b_4_1-s_b_4_3 */
    auto s_b_4_5 = emitter.sub(s_b_4_1, s_b_4_3);
    /* execute.simd:1809 [D] s_b_4_6 = float_abs */
    auto s_b_4_6 = emitter.call(__captive_float_abs, s_b_4_5);
    /* execute.simd:6290 [D] s_b_4_7: WriteRegBank 9:s_b_4_4 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6);
    /* execute.simd:6291 [F] s_b_4_8 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_4_9: WriteRegBank 10:s_b_4_4 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_4_10 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_4_11: WriteRegBank 3:s_b_4_4 = s_b_4_10 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_12: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:1810 [F] s_b_5_0=sym_10497_3_parameter_inst.size (const) */
    /* execute.simd:1810 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:1810 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.simd:1810 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:1810 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
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
    /* execute.simd:1811 [F] s_b_6_0=sym_10497_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_6_1 = ReadRegBank 11:s_b_6_0 (f64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1812 [F] s_b_6_2=sym_10497_3_parameter_inst.rm (const) */
    /* execute.simd:6285 [D] s_b_6_3 = ReadRegBank 11:s_b_6_2 (f64) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1814 [F] s_b_6_4=sym_10497_3_parameter_inst.rd (const) */
    /* execute.simd:1814 [D] s_b_6_5 = s_b_6_1-s_b_6_3 */
    auto s_b_6_5 = emitter.sub(s_b_6_1, s_b_6_3);
    /* execute.simd:1814 [D] s_b_6_6 = double_abs */
    auto s_b_6_6 = emitter.call(__captive_double_abs, s_b_6_5);
    /* execute.simd:6298 [D] s_b_6_7: WriteRegBank 11:s_b_6_4 = s_b_6_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6);
    /* execute.simd:6299 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_6_9: WriteRegBank 3:s_b_6_4 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_10: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fcvtas_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4695 [F] s_b_0_0=sym_11010_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4695 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4695 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.simd:4695 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
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
    /* execute.simd:4696 [F] s_b_1_0=sym_11010_3_parameter_inst.size (const) */
    /* execute.simd:4696 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4696 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4696 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4696 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_3, b_4, b_5,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4704 [D] s_b_3_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4704 [F] s_b_3_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4698 [F] s_b_4_0=sym_11010_3_parameter_inst.rd (const) */
    /* execute.simd:4698 [F] s_b_4_1=sym_11010_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_4_2 = ReadRegBank 9:s_b_4_1 (f32) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_2,emitter.const_u8(4));
    }
    /* execute.simd:4698 [F] s_b_4_3 = constant u8 0 (const) */
    /* execute.simd:4698 [D] s_b_4_4 = __builtin_fcvt_f32_s32 */
    auto s_b_4_4 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:4698 [D] s_b_4_5 = (u32)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().u32());
    /* execute.simd:6319 [D] s_b_4_6 = (u64)s_b_4_5 */
    auto s_b_4_6 = emitter.zx(s_b_4_5, emitter.context().types().u64());
    /* execute.simd:6319 [D] s_b_4_7: WriteRegBank 2:s_b_4_0 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6);
    /* execute.simd:6320 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:6320 [F] s_b_4_9: WriteRegBank 3:s_b_4_0 = s_b_4_8 */
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
    /* execute.simd:4701 [F] s_b_5_0=sym_11010_3_parameter_inst.rd (const) */
    /* execute.simd:4701 [F] s_b_5_1=sym_11010_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_5_2 = ReadRegBank 11:s_b_5_1 (f64) */
    auto s_b_5_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_2,emitter.const_u8(8));
    }
    /* execute.simd:4701 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.simd:4701 [D] s_b_5_4 = __builtin_fcvt_f64_s64 */
    auto s_b_5_4 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:4701 [D] s_b_5_5 = (u64)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().u64());
    /* execute.simd:6326 [D] s_b_5_6: WriteRegBank 2:s_b_5_0 = s_b_5_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5);
    /* execute.simd:6327 [F] s_b_5_7 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_5_8: WriteRegBank 3:s_b_5_0 = s_b_5_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_5_9: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fmaxv(const arm64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fmul_vector(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1380 [F] s_b_0_0=sym_12352_3_parameter_inst.Q (const) */
    /* execute.simd:1381 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:1391 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:1380 [F] s_b_0_3: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3,  */
    switch (insn.Q) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_2;
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
    /* execute.simd:1382 [F] s_b_2_0=sym_12352_3_parameter_inst.rn (const) */
    /* execute.simd:1382 [D] s_b_2_1 = ReadRegBank 12:s_b_2_0 (v2f32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1383 [F] s_b_2_2=sym_12352_3_parameter_inst.rm (const) */
    /* execute.simd:1383 [D] s_b_2_3 = ReadRegBank 12:s_b_2_2 (v2f32) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* execute.simd:1385 [D] s_b_2_4 = s_b_2_1*s_b_2_3 */
    auto s_b_2_4 = emitter.mul(s_b_2_1, s_b_2_3);
    /* execute.simd:1386 [F] s_b_2_5=sym_12352_3_parameter_inst.rd (const) */
    /* execute.simd:1386 [D] s_b_2_6: WriteRegBank 12:s_b_2_5 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4);
    /* execute.simd:1387 [F] s_b_2_7=sym_12352_3_parameter_inst.rd (const) */
    /* execute.simd:1387 [F] s_b_2_8 = constant u64 0 (const) */
    /* execute.simd:1387 [F] s_b_2_9: WriteRegBank 3:s_b_2_7 = s_b_2_8 */
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
    /* execute.simd:1392 [F] s_b_3_0=sym_12352_3_parameter_inst.size (const) */
    /* execute.simd:1393 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:1402 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:1392 [F] s_b_3_3: Switch s_b_3_0: < <todo> > def b_1 (const) -> b_1, b_5, b_4,  */
    switch (insn.size) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_4;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1394 [F] s_b_4_0=sym_12352_3_parameter_inst.rn (const) */
    /* execute.simd:1394 [D] s_b_4_1 = ReadRegBank 13:s_b_4_0 (v4f32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:1395 [F] s_b_4_2=sym_12352_3_parameter_inst.rm (const) */
    /* execute.simd:1395 [D] s_b_4_3 = ReadRegBank 13:s_b_4_2 (v4f32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(16));
    }
    /* execute.simd:1397 [D] s_b_4_4 = s_b_4_1*s_b_4_3 */
    auto s_b_4_4 = emitter.mul(s_b_4_1, s_b_4_3);
    /* execute.simd:1398 [F] s_b_4_5=sym_12352_3_parameter_inst.rd (const) */
    /* execute.simd:1398 [D] s_b_4_6: WriteRegBank 13:s_b_4_5 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:0 [F] s_b_4_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:1403 [F] s_b_5_0=sym_12352_3_parameter_inst.rn (const) */
    /* execute.simd:1403 [D] s_b_5_1 = ReadRegBank 14:s_b_5_0 (v2f64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1404 [F] s_b_5_2=sym_12352_3_parameter_inst.rm (const) */
    /* execute.simd:1404 [D] s_b_5_3 = ReadRegBank 14:s_b_5_2 (v2f64) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1406 [D] s_b_5_4 = s_b_5_1*s_b_5_3 */
    auto s_b_5_4 = emitter.mul(s_b_5_1, s_b_5_3);
    /* execute.simd:1407 [F] s_b_5_5=sym_12352_3_parameter_inst.rd (const) */
    /* execute.simd:1407 [D] s_b_5_6: WriteRegBank 14:s_b_5_5 = s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4);
    /* execute.simd:0 [F] s_b_5_7: Jump b_1 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_hint(const arm64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ld2pi(const arm64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_67628_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_68091_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_68079_1_tmp_s_b_35_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67663_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_67665_3_parameter_rt;
  auto DV_sym_67716_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_67661_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_67671_3_parameter_lane;
  auto DV_sym_67682_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_67699_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_67733_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_67750_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_67767_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_67792_1_tmp_s_b_5_2;
  auto DV_sym_67795_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67841_1__R_s_b_7_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67860_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67916_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_68005_1__R_s_b_31_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_68062_1_temporary_value;
  auto DV_sym_68062_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13611_0_rt;
  uint8_t CV_sym_13599_0_lane;
  auto DV_sym_13576_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_13570_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_27 else b_9 (const) */
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
    /* execute.simd:2598 [F] s_b_1_0 = sym_13599_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13599_0_lane;
    /* execute.simd:2598 [F] s_b_1_1=sym_13570_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2598 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2598 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2599 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2599 [F] s_b_2_1: sym_13611_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13611_0_rt = (uint8_t)0ULL;
    /* execute.simd:2599 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2605 [F] s_b_3_0=sym_13570_3_parameter_inst.rm (const) */
    /* execute.simd:2605 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2605 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2605 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2605 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2599 [F] s_b_4_0 = sym_13611_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13611_0_rt;
    /* execute.simd:2599 [F] s_b_4_1=sym_13570_3_parameter_inst.regcnt (const) */
    /* execute.simd:2599 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2599 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2600 [F] s_b_5_0=sym_13570_3_parameter_inst.arrangement (const) */
    /* execute.simd:2600 [F] s_b_5_1=sym_13570_3_parameter_inst.rt (const) */
    /* execute.simd:2600 [F] s_b_5_2 = sym_13611_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13611_0_rt;
    /* execute.simd:2600 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2600 [F] s_b_5_4 = sym_13599_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13599_0_lane;
    /* execute.simd:2600 [D] s_b_5_5 = sym_13576_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13576_0_address, emitter.context().types().u64());
    /* execute.simd:2600 [F] s_b_5_6: sym_67665_3_parameter_rt = s_b_5_3 (const), dominates: s_b_12_2 s_b_17_2 s_b_13_2 s_b_15_2 s_b_18_2 s_b_16_2 s_b_14_2  */
    CV_sym_67665_3_parameter_rt = s_b_5_3;
    /* execute.simd:2600 [F] s_b_5_7: sym_67671_3_parameter_lane = s_b_5_4 (const), dominates: s_b_12_5 s_b_17_5 s_b_13_5 s_b_15_5 s_b_18_5 s_b_16_5 s_b_14_5  */
    CV_sym_67671_3_parameter_lane = s_b_5_4;
    /* execute.simd:2600 [D] s_b_5_8: sym_67661_3_parameter_addr = s_b_5_5, dominates: s_b_12_0 s_b_17_0 s_b_13_0 s_b_15_0 s_b_18_0 s_b_16_0 s_b_14_0  */
    emitter.store_local(DV_sym_67661_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_67792_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_19_1  */
    CV_sym_67792_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_67795_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_67795_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3857 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3866 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3875 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3884 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3893 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3902 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3911 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3856 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_11 (const) -> b_12, b_11, b_17, b_13, b_15, b_18, b_16, b_14,  */
    switch (insn.arrangement) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_17;
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
    case (int32_t)3ULL:
      goto fixed_block_b_15;
      break;
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2598 [F] s_b_6_0 = sym_13599_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13599_0_lane;
    /* execute.simd:2598 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2598 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2598 [F] s_b_6_3: sym_13599_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13599_0_lane = s_b_6_2;
    /* execute.simd:2598 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2793 [F] s_b_7_0=sym_13570_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2793 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_7_4: If s_b_7_3: Jump b_32 else b_20 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_32;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_3, b_39,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2609 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2609 [D] s_b_8_1 = sym_13576_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_13576_0_address, emitter.context().types().u64());
    /* execute.simd:2609 [D] s_b_8_2: sym_67860_3_parameter_value = s_b_8_1, dominates: s_b_22_0 s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_67860_3_parameter_value, s_b_8_1);
    /* execute.a64:2809 [F] s_b_8_3 = !s_b_8_0 (const) */
    uint8_t s_b_8_3 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_8_4: If s_b_8_3: Jump b_22 else b_23 (const) */
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
    /* execute.a64:2796 [F] s_b_9_0=sym_13570_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_9_2: sym_67628_1__R_s_b_0_5 = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_67628_1__R_s_b_0_5, s_b_9_1);
    /* execute.a64:2796 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_31,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2593 [D] s_b_10_0 = sym_67628_1__R_s_b_0_5 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_67628_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2593 [D] s_b_10_1: sym_13576_0_address = s_b_10_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13576_0_address, s_b_10_0);
    /* execute.simd:2595 [F] s_b_10_2=sym_13570_3_parameter_inst.rt (const) */
    /* execute.simd:2595 [F] s_b_10_3 = constant u64 0 (const) */
    /* execute.simd:2595 [F] s_b_10_4 = constant u64 0 (const) */
    /* execute.simd:6333 [F] s_b_10_5: WriteRegBank 2:s_b_10_2 = s_b_10_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6334 [F] s_b_10_6: WriteRegBank 3:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2596 [F] s_b_10_7=sym_13570_3_parameter_inst.rt (const) */
    /* execute.simd:2596 [F] s_b_10_8 = (u32)s_b_10_7 (const) */
    /* execute.simd:2596 [F] s_b_10_9 = constant u32 1 (const) */
    /* execute.simd:2596 [F] s_b_10_10 = s_b_10_8+s_b_10_9 (const) */
    uint32_t s_b_10_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2596 [F] s_b_10_11 = (u8)s_b_10_10 (const) */
    /* execute.simd:2596 [F] s_b_10_12 = constant u64 0 (const) */
    /* execute.simd:2596 [F] s_b_10_13 = constant u64 0 (const) */
    /* execute.simd:6333 [F] s_b_10_14: WriteRegBank 2:s_b_10_11 = s_b_10_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6334 [F] s_b_10_15: WriteRegBank 3:s_b_10_11 = s_b_10_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2598 [F] s_b_10_16 = constant u8 0 (const) */
    /* execute.simd:2598 [F] s_b_10_17: sym_13599_0_lane = s_b_10_16 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13599_0_lane = (uint8_t)0ULL;
    /* execute.simd:2598 [F] s_b_10_18: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3921 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_11_1: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3859 [D] s_b_12_0 = sym_67661_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_67661_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 1 s_b_12_0 => sym_67663_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_67663_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(1));
    }
    /* execute.simd:3861 [F] s_b_12_2 = sym_67665_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_67665_3_parameter_rt;
    /* execute.simd:3861 [D] s_b_12_3 = ReadRegBank 15:s_b_12_2 (v8u8) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3862 [D] s_b_12_4 = sym_67663_0_mem_value uint8_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_67663_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3862 [F] s_b_12_5 = sym_67671_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_67671_3_parameter_lane;
    /* execute.simd:3862 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3862 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3863 [D] s_b_12_8: WriteRegBank 15:s_b_12_2 = s_b_12_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7);
    /* execute.simd:0 [F] s_b_12_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3868 [D] s_b_13_0 = sym_67661_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_67661_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 1 s_b_13_0 => sym_67682_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_67682_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(1));
    }
    /* execute.simd:3870 [F] s_b_13_2 = sym_67665_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_67665_3_parameter_rt;
    /* execute.simd:3870 [D] s_b_13_3 = ReadRegBank 16:s_b_13_2 (v16u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3871 [D] s_b_13_4 = sym_67682_0_mem_value uint8_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_67682_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3871 [F] s_b_13_5 = sym_67671_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_67671_3_parameter_lane;
    /* execute.simd:3871 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3871 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3872 [D] s_b_13_8: WriteRegBank 16:s_b_13_2 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_7);
    /* execute.simd:0 [F] s_b_13_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_14: 
  {
    /* execute.simd:3877 [D] s_b_14_0 = sym_67661_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_67661_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 2 s_b_14_0 => sym_67699_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_67699_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(2));
    }
    /* execute.simd:3879 [F] s_b_14_2 = sym_67665_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_67665_3_parameter_rt;
    /* execute.simd:3879 [D] s_b_14_3 = ReadRegBank 17:s_b_14_2 (v4u16) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3880 [D] s_b_14_4 = sym_67699_0_mem_value uint16_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_67699_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3880 [F] s_b_14_5 = sym_67671_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_67671_3_parameter_lane;
    /* execute.simd:3880 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3880 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3881 [D] s_b_14_8: WriteRegBank 17:s_b_14_2 = s_b_14_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_7);
    /* execute.simd:0 [F] s_b_14_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3886 [D] s_b_15_0 = sym_67661_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_67661_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_67716_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_67716_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3888 [F] s_b_15_2 = sym_67665_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_67665_3_parameter_rt;
    /* execute.simd:3888 [D] s_b_15_3 = ReadRegBank 18:s_b_15_2 (v8u16) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3889 [D] s_b_15_4 = sym_67716_0_mem_value uint16_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_67716_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3889 [F] s_b_15_5 = sym_67671_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_67671_3_parameter_lane;
    /* execute.simd:3889 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3889 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3890 [D] s_b_15_8: WriteRegBank 18:s_b_15_2 = s_b_15_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7);
    /* execute.simd:0 [F] s_b_15_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3895 [D] s_b_16_0 = sym_67661_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_67661_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 4 s_b_16_0 => sym_67733_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_67733_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(4));
    }
    /* execute.simd:3897 [F] s_b_16_2 = sym_67665_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_67665_3_parameter_rt;
    /* execute.simd:3897 [D] s_b_16_3 = ReadRegBank 19:s_b_16_2 (v2u32) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(8));
    }
    /* execute.simd:3898 [D] s_b_16_4 = sym_67733_0_mem_value uint32_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_67733_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3898 [F] s_b_16_5 = sym_67671_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_67671_3_parameter_lane;
    /* execute.simd:3898 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3898 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3899 [D] s_b_16_8: WriteRegBank 19:s_b_16_2 = s_b_16_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7);
    /* execute.simd:0 [F] s_b_16_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3904 [D] s_b_17_0 = sym_67661_3_parameter_addr uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_67661_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_67750_0_mem_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_67750_0_mem_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3906 [F] s_b_17_2 = sym_67665_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_2 = CV_sym_67665_3_parameter_rt;
    /* execute.simd:3906 [D] s_b_17_3 = ReadRegBank 20:s_b_17_2 (v4u32) */
    auto s_b_17_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_3,emitter.const_u8(16));
    }
    /* execute.simd:3907 [D] s_b_17_4 = sym_67750_0_mem_value uint32_t */
    auto s_b_17_4 = emitter.load_local(DV_sym_67750_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3907 [F] s_b_17_5 = sym_67671_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_5 = CV_sym_67671_3_parameter_lane;
    /* execute.simd:3907 [F] s_b_17_6 = (s32)s_b_17_5 (const) */
    /* execute.simd:3907 [D] s_b_17_7 = s_b_17_3[s_b_17_6] <= s_b_17_4 */
    auto s_b_17_7 = emitter.vector_insert(s_b_17_3, emitter.const_s32(((int32_t)s_b_17_5)), s_b_17_4);
    /* execute.simd:3908 [D] s_b_17_8: WriteRegBank 20:s_b_17_2 = s_b_17_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_7);
    /* execute.simd:0 [F] s_b_17_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3913 [D] s_b_18_0 = sym_67661_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_67661_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 8 s_b_18_0 => sym_67767_0_mem_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_67767_0_mem_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(8));
    }
    /* execute.simd:3915 [F] s_b_18_2 = sym_67665_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_2 = CV_sym_67665_3_parameter_rt;
    /* execute.simd:3915 [D] s_b_18_3 = ReadRegBank 21:s_b_18_2 (v2u64) */
    auto s_b_18_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_3,emitter.const_u8(16));
    }
    /* execute.simd:3916 [D] s_b_18_4 = sym_67767_0_mem_value uint64_t */
    auto s_b_18_4 = emitter.load_local(DV_sym_67767_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3916 [F] s_b_18_5 = sym_67671_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_5 = CV_sym_67671_3_parameter_lane;
    /* execute.simd:3916 [F] s_b_18_6 = (s32)s_b_18_5 (const) */
    /* execute.simd:3916 [D] s_b_18_7 = s_b_18_3[s_b_18_6] <= s_b_18_4 */
    auto s_b_18_7 = emitter.vector_insert(s_b_18_3, emitter.const_s32(((int32_t)s_b_18_5)), s_b_18_4);
    /* execute.simd:3917 [D] s_b_18_8: WriteRegBank 21:s_b_18_2 = s_b_18_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_7);
    /* execute.simd:0 [F] s_b_18_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_11, b_12, b_13, b_14, b_15, b_16, b_17, b_18,  */
  fixed_block_b_19: 
  {
    /* ???:4294967295 [D] s_b_19_0 = sym_67795_1_tmp_s_b_5_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_67795_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1 = sym_67792_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_19_1 = CV_sym_67792_1_tmp_s_b_5_2;
    /* execute.simd:2601 [F] s_b_19_2=sym_13570_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_19_3 = (u64)s_b_19_2 (const) */
    /* ???:4294967295 [D] s_b_19_4 = s_b_19_0+s_b_19_3 */
    auto s_b_19_4 = emitter.add(s_b_19_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2601 [D] s_b_19_5: sym_13576_0_address = s_b_19_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13576_0_address, s_b_19_4);
    /* execute.simd:2599 [F] s_b_19_6 = constant u8 1 (const) */
    /* execute.simd:2599 [F] s_b_19_7 = s_b_19_1+s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(s_b_19_1 + (uint8_t)1ULL));
    /* execute.simd:2599 [F] s_b_19_8: sym_13611_0_rt = s_b_19_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13611_0_rt = s_b_19_7;
    /* execute.simd:2599 [F] s_b_19_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2796 [F] s_b_20_0=sym_13570_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_20_2: sym_67841_1__R_s_b_7_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_67841_1__R_s_b_7_5, s_b_20_1);
    /* execute.a64:2796 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_36,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2606 [D] s_b_21_0 = sym_67841_1__R_s_b_7_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_67841_1__R_s_b_7_5, emitter.context().types().u64());
    /* execute.simd:2606 [F] s_b_21_1=sym_13570_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_21_2: sym_68079_1_tmp_s_b_35_0 = s_b_21_0, dominates: s_b_39_1  */
    emitter.store_local(DV_sym_68079_1_tmp_s_b_35_0, s_b_21_0);
    /* execute.a64:2714 [F] s_b_21_3 = (u32)s_b_21_1 (const) */
    /* execute.a64:2714 [F] s_b_21_4 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_21_5 = s_b_21_3==s_b_21_4 (const) */
    uint8_t s_b_21_5 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_21_6: If s_b_21_5: Jump b_37 else b_38 (const) */
    if (s_b_21_5) 
    {
      goto fixed_block_b_37;
    }
    else 
    {
      goto fixed_block_b_38;
    }
  }
  /* b_8,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2810 [D] s_b_22_0 = sym_67860_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_67860_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_22_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_22_2 = s_b_22_0&s_b_22_1 */
    auto s_b_22_2 = emitter.bitwise_and(s_b_22_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_22_3: sym_67860_3_parameter_value = s_b_22_2, dominates: s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_67860_3_parameter_value, s_b_22_2);
    /* execute.a64:2810 [F] s_b_22_4: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2813 [F] s_b_23_0=sym_13570_3_parameter_inst.rn (const) */
    /* execute.a64:2813 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2813 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_23_4: If s_b_23_3: Jump b_24 else b_25 (const) */
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
    /* execute.a64:2814 [D] s_b_24_0 = sym_67860_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_67860_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_24_1: sym_68091_3_parameter_value = s_b_24_0, dominates: s_b_40_0 s_b_41_0 s_b_42_0  */
    emitter.store_local(DV_sym_68091_3_parameter_value, s_b_24_0);
    /* execute.a64:2777 [F] s_b_24_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_24_3 = __builtin_get_feature */
    uint32_t s_b_24_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_24_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_24_5 = s_b_24_3==s_b_24_4 (const) */
    uint8_t s_b_24_5 = ((uint8_t)(s_b_24_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_24_6: If s_b_24_5: Jump b_40 else b_45 (const) */
    if (s_b_24_5) 
    {
      goto fixed_block_b_40;
    }
    else 
    {
      goto fixed_block_b_45;
    }
  }
  /* b_23,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2816 [F] s_b_25_0=sym_13570_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_25_1 = sym_67860_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_67860_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1);
    /* execute.a64:2816 [F] s_b_25_3: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_25, b_40, b_41, b_42,  */
  fixed_block_b_26: 
  {
    /* ???:4294967295 [F] s_b_26_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2764 [F] s_b_27_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_27_1 = __builtin_get_feature */
    uint32_t s_b_27_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_27_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(s_b_27_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_27_4: If s_b_27_3: Jump b_28 else b_43 (const) */
    if (s_b_27_3) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_43;
    }
  }
  /* b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2765 [D] s_b_28_0 = ReadReg 21 (u64) */
    auto s_b_28_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_28_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_28_1: sym_67916_1__R_s_b_12_0 = s_b_28_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67916_1__R_s_b_12_0, s_b_28_0);
    /* execute.a64:2765 [F] s_b_28_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_43,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2768 [D] s_b_29_0 = ReadReg 21 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_29_1: sym_67916_1__R_s_b_12_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67916_1__R_s_b_12_0, s_b_29_0);
    /* execute.a64:2768 [F] s_b_29_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_43,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2770 [D] s_b_30_0 = ReadReg 22 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_30_1: sym_67916_1__R_s_b_12_0 = s_b_30_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67916_1__R_s_b_12_0, s_b_30_0);
    /* execute.a64:2770 [F] s_b_30_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_28, b_29, b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2794 [D] s_b_31_0 = sym_67916_1__R_s_b_12_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_67916_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_31_1: sym_67628_1__R_s_b_0_5 = s_b_31_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_67628_1__R_s_b_0_5, s_b_31_0);
    /* execute.a64:2794 [F] s_b_31_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_7,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2764 [F] s_b_32_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_32_1 = __builtin_get_feature */
    uint32_t s_b_32_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_32_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_32_3 = s_b_32_1==s_b_32_2 (const) */
    uint8_t s_b_32_3 = ((uint8_t)(s_b_32_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_32_4: If s_b_32_3: Jump b_33 else b_44 (const) */
    if (s_b_32_3) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_44;
    }
  }
  /* b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2765 [D] s_b_33_0 = ReadReg 21 (u64) */
    auto s_b_33_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_33_1: sym_68005_1__R_s_b_31_0 = s_b_33_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_68005_1__R_s_b_31_0, s_b_33_0);
    /* execute.a64:2765 [F] s_b_33_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_44,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2768 [D] s_b_34_0 = ReadReg 21 (u64) */
    auto s_b_34_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_34_1: sym_68005_1__R_s_b_31_0 = s_b_34_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_68005_1__R_s_b_31_0, s_b_34_0);
    /* execute.a64:2768 [F] s_b_34_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_44,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2770 [D] s_b_35_0 = ReadReg 22 (u64) */
    auto s_b_35_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_35_1: sym_68005_1__R_s_b_31_0 = s_b_35_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_68005_1__R_s_b_31_0, s_b_35_0);
    /* execute.a64:2770 [F] s_b_35_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_33, b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2794 [D] s_b_36_0 = sym_68005_1__R_s_b_31_0 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_68005_1__R_s_b_31_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_36_1: sym_67841_1__R_s_b_7_5 = s_b_36_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_67841_1__R_s_b_7_5, s_b_36_0);
    /* execute.a64:2794 [F] s_b_36_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_21,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2714 [F] s_b_37_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_37_1: sym_68062_1_temporary_value = s_b_37_0 (const), dominates: s_b_39_0  */
    CV_sym_68062_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_68062_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_37_2: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_21,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2714 [F] s_b_38_0=sym_13570_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_38_1 = ReadRegBank 0:s_b_38_0 (u64) */
    auto s_b_38_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_38_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_38_2: sym_68062_1_temporary_value = s_b_38_1, dominates: s_b_39_0  */
    emitter.store_local(DV_sym_68062_1_temporary_value, s_b_38_1);
    /* execute.a64:2714 [F] s_b_38_3: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_37, b_38,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2714 [D] s_b_39_0 = sym_68062_1_temporary_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_68062_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_39_1 = sym_68079_1_tmp_s_b_35_0 uint64_t */
    auto s_b_39_1 = emitter.load_local(DV_sym_68079_1_tmp_s_b_35_0, emitter.context().types().u64());
    /* execute.simd:2606 [D] s_b_39_2 = s_b_39_1+s_b_39_0 */
    auto s_b_39_2 = emitter.add(s_b_39_1, s_b_39_0);
    /* execute.simd:2606 [D] s_b_39_3: sym_13576_0_address = s_b_39_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_13576_0_address, s_b_39_2);
    /* execute.simd:2606 [F] s_b_39_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_24,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2778 [D] s_b_40_0 = sym_68091_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_68091_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_40_1: WriteReg 21 = s_b_40_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_40_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_40_0);
    /* execute.a64:2778 [F] s_b_40_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_45,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2781 [D] s_b_41_0 = sym_68091_3_parameter_value uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_68091_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_41_1: WriteReg 21 = s_b_41_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_41_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_41_0);
    /* execute.a64:2781 [F] s_b_41_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_45,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2783 [D] s_b_42_0 = sym_68091_3_parameter_value uint64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_68091_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_42_1: WriteReg 22 = s_b_42_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_42_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_42_0);
    /* execute.a64:2783 [F] s_b_42_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_27,  */
  fixed_block_b_43: 
  {
    /* execute.a64:3075 [F] s_b_43_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_43_1 = __builtin_get_feature */
    uint32_t s_b_43_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_43_2 = (u8)s_b_43_1 (const) */
    /* execute.a64:2767 [F] s_b_43_3 = (u32)s_b_43_2 (const) */
    /* execute.a64:2767 [F] s_b_43_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_43_5 = s_b_43_3==s_b_43_4 (const) */
    uint8_t s_b_43_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_43_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_43_6: If s_b_43_5: Jump b_29 else b_30 (const) */
    if (s_b_43_5) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_32,  */
  fixed_block_b_44: 
  {
    /* execute.a64:3075 [F] s_b_44_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_44_1 = __builtin_get_feature */
    uint32_t s_b_44_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_44_2 = (u8)s_b_44_1 (const) */
    /* execute.a64:2767 [F] s_b_44_3 = (u32)s_b_44_2 (const) */
    /* execute.a64:2767 [F] s_b_44_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_44_5 = s_b_44_3==s_b_44_4 (const) */
    uint8_t s_b_44_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_44_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_44_6: If s_b_44_5: Jump b_34 else b_35 (const) */
    if (s_b_44_5) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_24,  */
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
    /* execute.a64:2780 [F] s_b_45_6: If s_b_45_5: Jump b_41 else b_42 (const) */
    if (s_b_45_5) 
    {
      goto fixed_block_b_41;
    }
    else 
    {
      goto fixed_block_b_42;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldaxp(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14158_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75221_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_76073_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_75353_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_75618_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_76421_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_76549_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75970_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75250_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75647_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75444_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75424_1_tmp_s_b_1_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_78569_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_78635_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_77073_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_77355_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75572_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14152_3_parameter_inst.rn (const) */
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
    /* execute.a64:894 [D] s_b_1_0 = sym_14158_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14158_0_address, emitter.context().types().u64());
    /* execute.a64:894 [D] s_b_1_1: sym_75250_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_75250_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2: sym_75424_1_tmp_s_b_1_0 = s_b_1_0, dominates: s_b_6_3  */
    emitter.store_local(DV_sym_75424_1_tmp_s_b_1_0, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_3 = Load 4 s_b_1_0 => sym_75353_0_data32 */
    auto s_b_1_3 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_75353_0_data32, s_b_1_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_3, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_1_4 = sym_75353_0_data32 uint32_t */
    auto s_b_1_4 = emitter.load_local(DV_sym_75353_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_1_5 = (u64)s_b_1_4 */
    auto s_b_1_5 = emitter.zx(s_b_1_4, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_6=sym_14152_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_7 = (u32)s_b_1_5 */
    auto s_b_1_7 = emitter.truncate(s_b_1_5, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_8 = (u64)s_b_1_7 */
    auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_9: sym_77073_3_parameter_value = s_b_1_8, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_77073_3_parameter_value, s_b_1_8);
    /* execute.a64:2745 [F] s_b_1_10 = (u32)s_b_1_6 (const) */
    /* execute.a64:2745 [F] s_b_1_11 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_1_12 = s_b_1_10==s_b_1_11 (const) */
    uint8_t s_b_1_12 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_1_13: If s_b_1_12: Jump b_6 else b_16 (const) */
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
    /* execute.a64:897 [D] s_b_3_0 = sym_14158_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14158_0_address, emitter.context().types().u64());
    /* execute.a64:897 [D] s_b_3_1: sym_75444_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_75444_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2: sym_75618_1_tmp_s_b_3_0 = s_b_3_0, dominates: s_b_7_3  */
    emitter.store_local(DV_sym_75618_1_tmp_s_b_3_0, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_3 = Load 8 s_b_3_0 => sym_75572_0_data64 */
    auto s_b_3_3 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_75572_0_data64, s_b_3_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_3, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_3_4 = sym_75572_0_data64 uint64_t */
    auto s_b_3_4 = emitter.load_local(DV_sym_75572_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_3_5=sym_14152_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_3_6: sym_77355_3_parameter_value = s_b_3_4, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_77355_3_parameter_value, s_b_3_4);
    /* execute.a64:2745 [F] s_b_3_7 = (u32)s_b_3_5 (const) */
    /* execute.a64:2745 [F] s_b_3_8 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_3_9 = s_b_3_7==s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_3_10: If s_b_3_9: Jump b_7 else b_17 (const) */
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
    /* execute.a64:2796 [F] s_b_4_0=sym_14152_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_4_2: sym_75221_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_75221_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2796 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:891 [D] s_b_5_0 = sym_75221_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_75221_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:891 [D] s_b_5_1: sym_14158_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14158_0_address, s_b_5_0);
    /* execute.a64:893 [F] s_b_5_2=sym_14152_3_parameter_inst.size (const) */
    /* execute.a64:893 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:893 [F] s_b_5_4 = constant u32 2 (const) */
    /* execute.a64:893 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:893 [F] s_b_5_6: If s_b_5_5: Jump b_1 else b_3 (const) */
    if (s_b_5_5) 
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
    /* execute.a64:1786 [F] s_b_6_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_6_1 = sym_75250_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_75250_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* ???:4294967295 [D] s_b_6_3 = sym_75424_1_tmp_s_b_1_0 uint64_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_75424_1_tmp_s_b_1_0, emitter.context().types().u64());
    /* execute.a64:895 [F] s_b_6_4 = constant u64 4 (const) */
    /* execute.a64:895 [D] s_b_6_5 = s_b_6_3+s_b_6_4 */
    auto s_b_6_5 = emitter.add(s_b_6_3, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:895 [D] s_b_6_6: sym_75970_3_parameter_address = s_b_6_5, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_75970_3_parameter_address, s_b_6_5);
    /* ???:4294967295 [D] s_b_6_7 = Load 4 s_b_6_5 => sym_76073_0_data32 */
    auto s_b_6_7 = emitter.load_memory(s_b_6_5, emitter.context().types().u32());
    emitter.store_local(DV_sym_76073_0_data32, s_b_6_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_5, s_b_6_7, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_6_8 = sym_76073_0_data32 uint32_t */
    auto s_b_6_8 = emitter.load_local(DV_sym_76073_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_10=sym_14152_3_parameter_inst.rt2 (const) */
    /* execute.a64:2756 [D] s_b_6_11 = (u32)s_b_6_9 */
    auto s_b_6_11 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_13: sym_78569_3_parameter_value = s_b_6_12, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_78569_3_parameter_value, s_b_6_12);
    /* execute.a64:2745 [F] s_b_6_14 = (u32)s_b_6_10 (const) */
    /* execute.a64:2745 [F] s_b_6_15 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_6_16 = s_b_6_14==s_b_6_15 (const) */
    uint8_t s_b_6_16 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_6_17: If s_b_6_16: Jump b_13 else b_18 (const) */
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
    /* execute.a64:1786 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_7_1 = sym_75444_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_75444_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* ???:4294967295 [D] s_b_7_3 = sym_75618_1_tmp_s_b_3_0 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_75618_1_tmp_s_b_3_0, emitter.context().types().u64());
    /* execute.a64:898 [F] s_b_7_4 = constant u64 8 (const) */
    /* execute.a64:898 [D] s_b_7_5 = s_b_7_3+s_b_7_4 */
    auto s_b_7_5 = emitter.add(s_b_7_3, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:898 [D] s_b_7_6: sym_76421_3_parameter_address = s_b_7_5, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_76421_3_parameter_address, s_b_7_5);
    /* ???:4294967295 [D] s_b_7_7 = Load 8 s_b_7_5 => sym_76549_0_data64 */
    auto s_b_7_7 = emitter.load_memory(s_b_7_5, emitter.context().types().u64());
    emitter.store_local(DV_sym_76549_0_data64, s_b_7_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_5, s_b_7_7, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_7_8 = sym_76549_0_data64 uint64_t */
    auto s_b_7_8 = emitter.load_local(DV_sym_76549_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_7_9=sym_14152_3_parameter_inst.rt2 (const) */
    /* execute.a64:2754 [D] s_b_7_10: sym_78635_3_parameter_value = s_b_7_8, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_78635_3_parameter_value, s_b_7_8);
    /* execute.a64:2745 [F] s_b_7_11 = (u32)s_b_7_9 (const) */
    /* execute.a64:2745 [F] s_b_7_12 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_7_13 = s_b_7_11==s_b_7_12 (const) */
    uint8_t s_b_7_13 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_7_14: If s_b_7_13: Jump b_14 else b_19 (const) */
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
    /* execute.a64:2764 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_8_4: If s_b_8_3: Jump b_9 else b_15 (const) */
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
    /* execute.a64:2765 [D] s_b_9_0 = ReadReg 21 (u64) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_9_1: sym_75647_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_75647_1__R_s_b_7_0, s_b_9_0);
    /* execute.a64:2765 [F] s_b_9_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_15,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2768 [D] s_b_10_0 = ReadReg 21 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_10_1: sym_75647_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_75647_1__R_s_b_7_0, s_b_10_0);
    /* execute.a64:2768 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_15,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2770 [D] s_b_11_0 = ReadReg 22 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_11_1: sym_75647_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_75647_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2794 [D] s_b_12_0 = sym_75647_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_75647_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_12_1: sym_75221_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_75221_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2794 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_6, b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1786 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_13_1 = sym_75970_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_75970_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7, b_19,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1786 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_14_1 = sym_76421_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_76421_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_14_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_15: 
  {
    /* execute.a64:3075 [F] s_b_15_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_15_1 = __builtin_get_feature */
    uint32_t s_b_15_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_15_2 = (u8)s_b_15_1 (const) */
    /* execute.a64:2767 [F] s_b_15_3 = (u32)s_b_15_2 (const) */
    /* execute.a64:2767 [F] s_b_15_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_15_5 = s_b_15_3==s_b_15_4 (const) */
    uint8_t s_b_15_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_15_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_15_6: If s_b_15_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2747 [F] s_b_16_0=sym_14152_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_16_1 = sym_77073_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_77073_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2747 [F] s_b_17_0=sym_14152_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_77355_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_77355_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1);
    /* execute.a64:0 [F] s_b_17_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2747 [F] s_b_18_0=sym_14152_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_18_1 = sym_78569_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_78569_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_18_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_18_1);
    /* execute.a64:0 [F] s_b_18_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_7,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2747 [F] s_b_19_0=sym_14152_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_19_1 = sym_78635_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_78635_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_19_1,emitter.const_u8(8));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldpi_simd(const arm64_decode_a64_LS_REG_PAIR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_90606_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_90426_0_offset;
  auto DV_sym_90592_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_14582_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90782_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90612_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90599_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90585_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_90792_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_90406_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_90420_3_parameter_size;
  auto DV_sym_90813_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90513_1__R_s_b_8_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90575_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90806_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90819_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90634_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90799_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_90431_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90577_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_90457_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90784_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14576_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_13 else b_5 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_6,  */
  fixed_block_b_1: 
  {
    /* execute.simd:815 [D] s_b_1_0 = sym_14582_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14582_0_addr, emitter.context().types().u64());
    /* execute.simd:815 [F] s_b_1_1=sym_14576_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.simd:815 [D] s_b_1_3: sym_14582_0_addr = s_b_1_2, dominates: s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_14582_0_addr, s_b_1_2);
    /* execute.simd:815 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_6,  */
  fixed_block_b_2: 
  {
    /* execute.simd:818 [F] s_b_2_0=sym_14576_3_parameter_inst.opc (const) */
    /* execute.simd:818 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.simd:818 [F] s_b_2_2 = constant u32 2 (const) */
    /* execute.simd:818 [F] s_b_2_3 = s_b_2_1+s_b_2_2 (const) */
    uint32_t s_b_2_3 = ((uint32_t)(((uint32_t)insn.opc) + (uint32_t)2ULL));
    /* execute.simd:818 [F] s_b_2_4 = (u8)s_b_2_3 (const) */
    /* execute.simd:818 [D] s_b_2_5 = sym_14582_0_addr uint64_t */
    auto s_b_2_5 = emitter.load_local(DV_sym_14582_0_addr, emitter.context().types().u64());
    /* execute.simd:818 [F] s_b_2_6: sym_90420_3_parameter_size = s_b_2_4 (const), dominates: s_b_23_0  */
    CV_sym_90420_3_parameter_size = ((uint8_t)s_b_2_3);
    /* execute.simd:818 [D] s_b_2_7: sym_90431_3_parameter_addr = s_b_2_5, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_90431_3_parameter_addr, s_b_2_5);
    /* execute.simd:773 [F] s_b_2_8 = constant u32 1 (const) */
    /* execute.simd:773 [F] s_b_2_9 = (u32)s_b_2_4 (const) */
    /* execute.simd:773 [F] s_b_2_10 = s_b_2_8<<s_b_2_9 (const) */
    uint32_t s_b_2_10 = ((uint32_t)((uint32_t)1ULL << ((uint32_t)((uint8_t)s_b_2_3))));
    /* execute.simd:773 [F] s_b_2_11 = (u8)s_b_2_10 (const) */
    /* execute.simd:773 [F] s_b_2_12: sym_90426_0_offset = s_b_2_11 (const), dominates: s_b_23_2  */
    CV_sym_90426_0_offset = ((uint8_t)s_b_2_10);
    /* execute.simd:774 [D] s_b_2_13: sym_90575_3_parameter_addr = s_b_2_5, dominates: s_b_22_0 s_b_20_0 s_b_21_0 s_b_19_0 s_b_18_0  */
    emitter.store_local(DV_sym_90575_3_parameter_addr, s_b_2_5);
    /* execute.simd:3763 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:3770 [F] s_b_2_15 = constant s32 1 (const) */
    /* execute.simd:3777 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:3784 [F] s_b_2_17 = constant s32 3 (const) */
    /* execute.simd:3791 [F] s_b_2_18 = constant s32 4 (const) */
    /* execute.simd:3762 [F] s_b_2_19: Switch s_b_2_4: < <todo> > def b_23 (const) -> b_22, b_20, b_23, b_21, b_19, b_18,  */
    switch (((uint8_t)s_b_2_3)) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_21;
      break;
    default:
      goto fixed_block_b_23;
    }
  }
  /* b_7,  */
  fixed_block_b_3: 
  {
    /* execute.simd:821 [D] s_b_3_0 = sym_14582_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14582_0_addr, emitter.context().types().u64());
    /* execute.simd:821 [F] s_b_3_1=sym_14576_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:821 [D] s_b_3_3: sym_14582_0_addr = s_b_3_2, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_14582_0_addr, s_b_3_2);
    /* execute.simd:821 [F] s_b_3_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_7,  */
  fixed_block_b_4: 
  {
    /* execute.simd:824 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.simd:824 [D] s_b_4_1 = sym_14582_0_addr uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_14582_0_addr, emitter.context().types().u64());
    /* execute.simd:824 [D] s_b_4_2: sym_90457_3_parameter_value = s_b_4_1, dominates: s_b_8_0 s_b_10_0 s_b_11_1  */
    emitter.store_local(DV_sym_90457_3_parameter_value, s_b_4_1);
    /* execute.a64:2809 [F] s_b_4_3 = !s_b_4_0 (const) */
    uint8_t s_b_4_3 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_4_4: If s_b_4_3: Jump b_8 else b_9 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2796 [F] s_b_5_0=sym_14576_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_5_2: sym_90406_1__R_s_b_0_5 = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_90406_1__R_s_b_0_5, s_b_5_1);
    /* execute.a64:2796 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_17,  */
  fixed_block_b_6: 
  {
    /* execute.simd:813 [D] s_b_6_0 = sym_90406_1__R_s_b_0_5 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_90406_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:813 [D] s_b_6_1: sym_14582_0_addr = s_b_6_0, dominates: s_b_1_0 s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_14582_0_addr, s_b_6_0);
    /* execute.simd:814 [F] s_b_6_2=sym_14576_3_parameter_inst.P (const) */
    /* execute.simd:814 [F] s_b_6_3: If s_b_6_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_23, b_28, b_29, b_30, b_31, b_32,  */
  fixed_block_b_7: 
  {
    /* execute.simd:820 [F] s_b_7_0=sym_14576_3_parameter_inst.P (const) */
    /* execute.simd:820 [F] s_b_7_1 = !s_b_7_0 (const) */
    uint8_t s_b_7_1 = !insn.P;
    /* execute.simd:820 [F] s_b_7_2: If s_b_7_1: Jump b_3 else b_4 (const) */
    if (s_b_7_1) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2810 [D] s_b_8_0 = sym_90457_3_parameter_value uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_90457_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_8_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_8_2 = s_b_8_0&s_b_8_1 */
    auto s_b_8_2 = emitter.bitwise_and(s_b_8_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_8_3: sym_90457_3_parameter_value = s_b_8_2, dominates: s_b_10_0 s_b_11_1  */
    emitter.store_local(DV_sym_90457_3_parameter_value, s_b_8_2);
    /* execute.a64:2810 [F] s_b_8_4: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2813 [F] s_b_9_0=sym_14576_3_parameter_inst.rn (const) */
    /* execute.a64:2813 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:2813 [F] s_b_9_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2814 [D] s_b_10_0 = sym_90457_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_90457_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_10_1: sym_90634_3_parameter_value = s_b_10_0, dominates: s_b_24_0 s_b_25_0 s_b_26_0  */
    emitter.store_local(DV_sym_90634_3_parameter_value, s_b_10_0);
    /* execute.a64:2777 [F] s_b_10_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_10_3 = __builtin_get_feature */
    uint32_t s_b_10_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_10_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(s_b_10_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_10_6: If s_b_10_5: Jump b_24 else b_33 (const) */
    if (s_b_10_5) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_33;
    }
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2816 [F] s_b_11_0=sym_14576_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_11_1 = sym_90457_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_90457_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1);
    /* execute.a64:2816 [F] s_b_11_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11, b_24, b_25, b_26,  */
  fixed_block_b_12: 
  {
    /* ???:4294967295 [F] s_b_12_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2764 [F] s_b_13_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_13_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(s_b_13_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_27 (const) */
    if (s_b_13_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2765 [D] s_b_14_0 = ReadReg 21 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_14_1: sym_90513_1__R_s_b_8_0 = s_b_14_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_90513_1__R_s_b_8_0, s_b_14_0);
    /* execute.a64:2765 [F] s_b_14_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_27,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2768 [D] s_b_15_0 = ReadReg 21 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_15_1: sym_90513_1__R_s_b_8_0 = s_b_15_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_90513_1__R_s_b_8_0, s_b_15_0);
    /* execute.a64:2768 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_27,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2770 [D] s_b_16_0 = ReadReg 22 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_16_1: sym_90513_1__R_s_b_8_0 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_90513_1__R_s_b_8_0, s_b_16_0);
    /* execute.a64:2770 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_14, b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2794 [D] s_b_17_0 = sym_90513_1__R_s_b_8_0 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_90513_1__R_s_b_8_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_17_1: sym_90406_1__R_s_b_0_5 = s_b_17_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_90406_1__R_s_b_0_5, s_b_17_0);
    /* execute.a64:2794 [F] s_b_17_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_2,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3780 [D] s_b_18_0 = sym_90575_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_90575_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 4 s_b_18_0 => sym_90592_0_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_90592_0_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(4));
    }
    /* execute.simd:3781 [F] s_b_18_2=sym_14576_3_parameter_inst.rt (const) */
    /* execute.simd:3781 [D] s_b_18_3 = sym_90592_0_value uint32_t */
    auto s_b_18_3 = emitter.load_local(DV_sym_90592_0_value, emitter.context().types().u32());
    /* execute.simd:6319 [D] s_b_18_4 = (u64)s_b_18_3 */
    auto s_b_18_4 = emitter.zx(s_b_18_3, emitter.context().types().u64());
    /* execute.simd:6319 [D] s_b_18_5: WriteRegBank 2:s_b_18_2 = s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_4);
    /* execute.simd:6320 [F] s_b_18_6 = constant u64 0 (const) */
    /* execute.simd:6320 [F] s_b_18_7: WriteRegBank 3:s_b_18_2 = s_b_18_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_18_8: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_2,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3766 [D] s_b_19_0 = sym_90575_3_parameter_addr uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_90575_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_19_1 = Load 1 s_b_19_0 => sym_90577_0_value */
    auto s_b_19_1 = emitter.load_memory(s_b_19_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_90577_0_value, s_b_19_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_19_0, s_b_19_1, emitter.const_u8(1));
    }
    /* execute.simd:3767 [F] s_b_19_2=sym_14576_3_parameter_inst.rt (const) */
    /* execute.simd:3767 [D] s_b_19_3 = sym_90577_0_value uint8_t */
    auto s_b_19_3 = emitter.load_local(DV_sym_90577_0_value, emitter.context().types().u8());
    /* execute.simd:6305 [D] s_b_19_4 = (u64)s_b_19_3 */
    auto s_b_19_4 = emitter.zx(s_b_19_3, emitter.context().types().u64());
    /* execute.simd:6305 [D] s_b_19_5: WriteRegBank 2:s_b_19_2 = s_b_19_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_19_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_19_4);
    /* execute.simd:6306 [F] s_b_19_6 = constant u64 0 (const) */
    /* execute.simd:6306 [F] s_b_19_7: WriteRegBank 3:s_b_19_2 = s_b_19_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_19_8: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_2,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3773 [D] s_b_20_0 = sym_90575_3_parameter_addr uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_90575_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_1 = Load 2 s_b_20_0 => sym_90585_0_value */
    auto s_b_20_1 = emitter.load_memory(s_b_20_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_90585_0_value, s_b_20_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_20_0, s_b_20_1, emitter.const_u8(2));
    }
    /* execute.simd:3774 [F] s_b_20_2=sym_14576_3_parameter_inst.rt (const) */
    /* execute.simd:3774 [D] s_b_20_3 = sym_90585_0_value uint16_t */
    auto s_b_20_3 = emitter.load_local(DV_sym_90585_0_value, emitter.context().types().u16());
    /* execute.simd:6312 [D] s_b_20_4 = (u64)s_b_20_3 */
    auto s_b_20_4 = emitter.zx(s_b_20_3, emitter.context().types().u64());
    /* execute.simd:6312 [D] s_b_20_5: WriteRegBank 2:s_b_20_2 = s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_20_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_20_4);
    /* execute.simd:6313 [F] s_b_20_6 = constant u64 0 (const) */
    /* execute.simd:6313 [F] s_b_20_7: WriteRegBank 3:s_b_20_2 = s_b_20_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_20_8: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_2,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3787 [D] s_b_21_0 = sym_90575_3_parameter_addr uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_90575_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_1 = Load 8 s_b_21_0 => sym_90599_0_value */
    auto s_b_21_1 = emitter.load_memory(s_b_21_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90599_0_value, s_b_21_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_21_0, s_b_21_1, emitter.const_u8(8));
    }
    /* execute.simd:3788 [F] s_b_21_2=sym_14576_3_parameter_inst.rt (const) */
    /* execute.simd:3788 [D] s_b_21_3 = sym_90599_0_value uint64_t */
    auto s_b_21_3 = emitter.load_local(DV_sym_90599_0_value, emitter.context().types().u64());
    /* execute.simd:6326 [D] s_b_21_4: WriteRegBank 2:s_b_21_2 = s_b_21_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_21_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_21_3);
    /* execute.simd:6327 [F] s_b_21_5 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_21_6: WriteRegBank 3:s_b_21_2 = s_b_21_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_21_7: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_2,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3795 [D] s_b_22_0 = sym_90575_3_parameter_addr uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_90575_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_22_1 = Load 8 s_b_22_0 => sym_90606_0_vl */
    auto s_b_22_1 = emitter.load_memory(s_b_22_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90606_0_vl, s_b_22_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_22_0, s_b_22_1, emitter.const_u8(8));
    }
    /* execute.simd:3796 [F] s_b_22_2 = constant u64 8 (const) */
    /* execute.simd:3796 [D] s_b_22_3 = s_b_22_0+s_b_22_2 */
    auto s_b_22_3 = emitter.add(s_b_22_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_22_4 = Load 8 s_b_22_3 => sym_90612_0_vh */
    auto s_b_22_4 = emitter.load_memory(s_b_22_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_90612_0_vh, s_b_22_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_22_3, s_b_22_4, emitter.const_u8(8));
    }
    /* execute.simd:3797 [F] s_b_22_5=sym_14576_3_parameter_inst.rt (const) */
    /* execute.simd:3797 [D] s_b_22_6 = sym_90606_0_vl uint64_t */
    auto s_b_22_6 = emitter.load_local(DV_sym_90606_0_vl, emitter.context().types().u64());
    /* execute.simd:3797 [D] s_b_22_7 = sym_90612_0_vh uint64_t */
    auto s_b_22_7 = emitter.load_local(DV_sym_90612_0_vh, emitter.context().types().u64());
    /* execute.simd:6333 [D] s_b_22_8: WriteRegBank 2:s_b_22_5 = s_b_22_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_22_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_22_6);
    /* execute.simd:6334 [D] s_b_22_9: WriteRegBank 3:s_b_22_5 = s_b_22_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_22_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_22_7);
    /* execute.simd:0 [F] s_b_22_10: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_2, b_18, b_19, b_20, b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.simd:775 [F] s_b_23_0 = sym_90420_3_parameter_size (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_90420_3_parameter_size;
    /* execute.simd:775 [D] s_b_23_1 = sym_90431_3_parameter_addr uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_90431_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:775 [F] s_b_23_2 = sym_90426_0_offset (const) uint8_t */
    uint8_t s_b_23_2 = CV_sym_90426_0_offset;
    /* execute.simd:775 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* execute.simd:775 [D] s_b_23_4 = s_b_23_1+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_1, emitter.const_u64(((uint64_t)s_b_23_2)));
    /* execute.simd:775 [D] s_b_23_5: sym_90782_3_parameter_addr = s_b_23_4, dominates: s_b_28_0 s_b_32_0 s_b_30_0 s_b_31_0 s_b_29_0  */
    emitter.store_local(DV_sym_90782_3_parameter_addr, s_b_23_4);
    /* execute.simd:3763 [F] s_b_23_6 = constant s32 0 (const) */
    /* execute.simd:3770 [F] s_b_23_7 = constant s32 1 (const) */
    /* execute.simd:3777 [F] s_b_23_8 = constant s32 2 (const) */
    /* execute.simd:3784 [F] s_b_23_9 = constant s32 3 (const) */
    /* execute.simd:3791 [F] s_b_23_10 = constant s32 4 (const) */
    /* execute.simd:3762 [F] s_b_23_11: Switch s_b_23_0: < <todo> > def b_7 (const) -> b_28, b_32, b_30, b_31, b_29, b_7,  */
    switch (s_b_23_0) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_28;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_31;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_30;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_32;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_29;
      break;
    default:
      goto fixed_block_b_7;
    }
  }
  /* b_10,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2778 [D] s_b_24_0 = sym_90634_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_90634_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_24_1: WriteReg 21 = s_b_24_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_24_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_24_0);
    /* execute.a64:2778 [F] s_b_24_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_33,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2781 [D] s_b_25_0 = sym_90634_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_90634_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_25_1: WriteReg 21 = s_b_25_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_25_0);
    /* execute.a64:2781 [F] s_b_25_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_33,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2783 [D] s_b_26_0 = sym_90634_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_90634_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_26_1: WriteReg 22 = s_b_26_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_26_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_26_0);
    /* execute.a64:2783 [F] s_b_26_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_27: 
  {
    /* execute.a64:3075 [F] s_b_27_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_27_1 = __builtin_get_feature */
    uint32_t s_b_27_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_27_2 = (u8)s_b_27_1 (const) */
    /* execute.a64:2767 [F] s_b_27_3 = (u32)s_b_27_2 (const) */
    /* execute.a64:2767 [F] s_b_27_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_27_5 = s_b_27_3==s_b_27_4 (const) */
    uint8_t s_b_27_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_27_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_27_6: If s_b_27_5: Jump b_15 else b_16 (const) */
    if (s_b_27_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_23,  */
  fixed_block_b_28: 
  {
    /* execute.simd:3780 [D] s_b_28_0 = sym_90782_3_parameter_addr uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_90782_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_28_1 = Load 4 s_b_28_0 => sym_90799_0_value */
    auto s_b_28_1 = emitter.load_memory(s_b_28_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_90799_0_value, s_b_28_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_28_0, s_b_28_1, emitter.const_u8(4));
    }
    /* execute.simd:3781 [F] s_b_28_2=sym_14576_3_parameter_inst.rt2 (const) */
    /* execute.simd:3781 [D] s_b_28_3 = sym_90799_0_value uint32_t */
    auto s_b_28_3 = emitter.load_local(DV_sym_90799_0_value, emitter.context().types().u32());
    /* execute.simd:6319 [D] s_b_28_4 = (u64)s_b_28_3 */
    auto s_b_28_4 = emitter.zx(s_b_28_3, emitter.context().types().u64());
    /* execute.simd:6319 [D] s_b_28_5: WriteRegBank 2:s_b_28_2 = s_b_28_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_28_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_28_4);
    /* execute.simd:6320 [F] s_b_28_6 = constant u64 0 (const) */
    /* execute.simd:6320 [F] s_b_28_7: WriteRegBank 3:s_b_28_2 = s_b_28_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_28_8: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_23,  */
  fixed_block_b_29: 
  {
    /* execute.simd:3766 [D] s_b_29_0 = sym_90782_3_parameter_addr uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_90782_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_29_1 = Load 1 s_b_29_0 => sym_90784_0_value */
    auto s_b_29_1 = emitter.load_memory(s_b_29_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_90784_0_value, s_b_29_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_29_0, s_b_29_1, emitter.const_u8(1));
    }
    /* execute.simd:3767 [F] s_b_29_2=sym_14576_3_parameter_inst.rt2 (const) */
    /* execute.simd:3767 [D] s_b_29_3 = sym_90784_0_value uint8_t */
    auto s_b_29_3 = emitter.load_local(DV_sym_90784_0_value, emitter.context().types().u8());
    /* execute.simd:6305 [D] s_b_29_4 = (u64)s_b_29_3 */
    auto s_b_29_4 = emitter.zx(s_b_29_3, emitter.context().types().u64());
    /* execute.simd:6305 [D] s_b_29_5: WriteRegBank 2:s_b_29_2 = s_b_29_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_29_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_29_4);
    /* execute.simd:6306 [F] s_b_29_6 = constant u64 0 (const) */
    /* execute.simd:6306 [F] s_b_29_7: WriteRegBank 3:s_b_29_2 = s_b_29_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_29_8: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_23,  */
  fixed_block_b_30: 
  {
    /* execute.simd:3773 [D] s_b_30_0 = sym_90782_3_parameter_addr uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_90782_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_30_1 = Load 2 s_b_30_0 => sym_90792_0_value */
    auto s_b_30_1 = emitter.load_memory(s_b_30_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_90792_0_value, s_b_30_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_30_0, s_b_30_1, emitter.const_u8(2));
    }
    /* execute.simd:3774 [F] s_b_30_2=sym_14576_3_parameter_inst.rt2 (const) */
    /* execute.simd:3774 [D] s_b_30_3 = sym_90792_0_value uint16_t */
    auto s_b_30_3 = emitter.load_local(DV_sym_90792_0_value, emitter.context().types().u16());
    /* execute.simd:6312 [D] s_b_30_4 = (u64)s_b_30_3 */
    auto s_b_30_4 = emitter.zx(s_b_30_3, emitter.context().types().u64());
    /* execute.simd:6312 [D] s_b_30_5: WriteRegBank 2:s_b_30_2 = s_b_30_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_30_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_30_4);
    /* execute.simd:6313 [F] s_b_30_6 = constant u64 0 (const) */
    /* execute.simd:6313 [F] s_b_30_7: WriteRegBank 3:s_b_30_2 = s_b_30_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_30_8: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_23,  */
  fixed_block_b_31: 
  {
    /* execute.simd:3787 [D] s_b_31_0 = sym_90782_3_parameter_addr uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_90782_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1 = Load 8 s_b_31_0 => sym_90806_0_value */
    auto s_b_31_1 = emitter.load_memory(s_b_31_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90806_0_value, s_b_31_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_31_0, s_b_31_1, emitter.const_u8(8));
    }
    /* execute.simd:3788 [F] s_b_31_2=sym_14576_3_parameter_inst.rt2 (const) */
    /* execute.simd:3788 [D] s_b_31_3 = sym_90806_0_value uint64_t */
    auto s_b_31_3 = emitter.load_local(DV_sym_90806_0_value, emitter.context().types().u64());
    /* execute.simd:6326 [D] s_b_31_4: WriteRegBank 2:s_b_31_2 = s_b_31_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_31_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_31_3);
    /* execute.simd:6327 [F] s_b_31_5 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_31_6: WriteRegBank 3:s_b_31_2 = s_b_31_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_31_7: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_23,  */
  fixed_block_b_32: 
  {
    /* execute.simd:3795 [D] s_b_32_0 = sym_90782_3_parameter_addr uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_90782_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_1 = Load 8 s_b_32_0 => sym_90813_0_vl */
    auto s_b_32_1 = emitter.load_memory(s_b_32_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90813_0_vl, s_b_32_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_32_0, s_b_32_1, emitter.const_u8(8));
    }
    /* execute.simd:3796 [F] s_b_32_2 = constant u64 8 (const) */
    /* execute.simd:3796 [D] s_b_32_3 = s_b_32_0+s_b_32_2 */
    auto s_b_32_3 = emitter.add(s_b_32_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_32_4 = Load 8 s_b_32_3 => sym_90819_0_vh */
    auto s_b_32_4 = emitter.load_memory(s_b_32_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_90819_0_vh, s_b_32_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_32_3, s_b_32_4, emitter.const_u8(8));
    }
    /* execute.simd:3797 [F] s_b_32_5=sym_14576_3_parameter_inst.rt2 (const) */
    /* execute.simd:3797 [D] s_b_32_6 = sym_90813_0_vl uint64_t */
    auto s_b_32_6 = emitter.load_local(DV_sym_90813_0_vl, emitter.context().types().u64());
    /* execute.simd:3797 [D] s_b_32_7 = sym_90819_0_vh uint64_t */
    auto s_b_32_7 = emitter.load_local(DV_sym_90819_0_vh, emitter.context().types().u64());
    /* execute.simd:6333 [D] s_b_32_8: WriteRegBank 2:s_b_32_5 = s_b_32_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_32_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_32_6);
    /* execute.simd:6334 [D] s_b_32_9: WriteRegBank 3:s_b_32_5 = s_b_32_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),s_b_32_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),s_b_32_7);
    /* execute.simd:0 [F] s_b_32_10: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_10,  */
  fixed_block_b_33: 
  {
    /* execute.a64:3075 [F] s_b_33_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_33_1 = __builtin_get_feature */
    uint32_t s_b_33_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_33_2 = (u8)s_b_33_1 (const) */
    /* execute.a64:2780 [F] s_b_33_3 = (u32)s_b_33_2 (const) */
    /* execute.a64:2780 [F] s_b_33_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_33_5 = s_b_33_3==s_b_33_4 (const) */
    uint8_t s_b_33_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_33_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_33_6: If s_b_33_5: Jump b_25 else b_26 (const) */
    if (s_b_33_5) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldrb(const arm64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_15422_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100879_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_100874_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100463_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100497_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_100492_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_101946_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_101111_1__R_s_b_14_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102142_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100688_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_101055_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102652_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100683_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_103140_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_15416_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_20 else b_10 (const) */
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
    /* execute.a64:961 [D] s_b_1_0 = sym_15422_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15422_0_address, emitter.context().types().u64());
    /* execute.a64:961 [F] s_b_1_1=sym_15416_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:961 [D] s_b_1_4: sym_15422_0_address = s_b_1_3, dominates: s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15422_0_address, s_b_1_3);
    /* execute.a64:961 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_11,  */
  fixed_block_b_2: 
  {
    /* execute.a64:964 [F] s_b_2_0=sym_15416_3_parameter_inst.X (const) */
    /* execute.a64:964 [F] s_b_2_1: If s_b_2_0: Jump b_3 else b_5 (const) */
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
    /* execute.a64:965 [F] s_b_3_0=sym_15416_3_parameter_inst.L (const) */
    /* execute.a64:965 [F] s_b_3_1: If s_b_3_0: Jump b_6 else b_7 (const) */
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
    /* execute.a64:974 [F] s_b_4_0=sym_15416_3_parameter_inst.P (const) */
    /* execute.a64:974 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:974 [F] s_b_4_2: If s_b_4_1: Jump b_8 else b_9 (const) */
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
    /* execute.a64:971 [D] s_b_5_0 = sym_15422_0_address uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_15422_0_address, emitter.context().types().u64());
    /* execute.a64:971 [D] s_b_5_1: sym_100492_3_parameter_address = s_b_5_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_100492_3_parameter_address, s_b_5_0);
    /* ???:4294967295 [D] s_b_5_2 = Load 1 s_b_5_0 => sym_100497_0_data8 */
    auto s_b_5_2 = emitter.load_memory(s_b_5_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_100497_0_data8, s_b_5_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_5_0, s_b_5_2, emitter.const_u8(1));
    }
    /* execute.a64:1726 [D] s_b_5_3 = sym_100497_0_data8 uint8_t */
    auto s_b_5_3 = emitter.load_local(DV_sym_100497_0_data8, emitter.context().types().u8());
    /* execute.a64:1726 [D] s_b_5_4 = (u64)s_b_5_3 */
    auto s_b_5_4 = emitter.zx(s_b_5_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_5_5=sym_15416_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_5_6 = (u32)s_b_5_4 */
    auto s_b_5_6 = emitter.truncate(s_b_5_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_5_8: sym_102142_3_parameter_value = s_b_5_7, dominates: s_b_29_1  */
    emitter.store_local(DV_sym_102142_3_parameter_value, s_b_5_7);
    /* execute.a64:2745 [F] s_b_5_9 = (u32)s_b_5_5 (const) */
    /* execute.a64:2745 [F] s_b_5_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_5_11 = s_b_5_9==s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_5_12: If s_b_5_11: Jump b_12 else b_29 (const) */
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
    /* execute.a64:966 [D] s_b_6_0 = sym_15422_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_15422_0_address, emitter.context().types().u64());
    /* execute.a64:966 [D] s_b_6_1: sym_100683_3_parameter_address = s_b_6_0, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_100683_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 1 s_b_6_0 => sym_100688_0_data8 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_100688_0_data8, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(1));
    }
    /* execute.a64:1728 [D] s_b_6_3 = sym_100688_0_data8 uint8_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_100688_0_data8, emitter.context().types().u8());
    /* execute.a64:1728 [D] s_b_6_4 = (s8)s_b_6_3 */
    auto s_b_6_4 = emitter.reinterpret(s_b_6_3, emitter.context().types().s8());
    /* execute.a64:1728 [D] s_b_6_5 = (s64)s_b_6_4 */
    auto s_b_6_5 = emitter.sx(s_b_6_4, emitter.context().types().s64());
    /* execute.a64:1728 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.reinterpret(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_7=sym_15416_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_6_8 = (u32)s_b_6_6 */
    auto s_b_6_8 = emitter.truncate(s_b_6_6, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_10: sym_102652_3_parameter_value = s_b_6_9, dominates: s_b_30_1  */
    emitter.store_local(DV_sym_102652_3_parameter_value, s_b_6_9);
    /* execute.a64:2745 [F] s_b_6_11 = (u32)s_b_6_7 (const) */
    /* execute.a64:2745 [F] s_b_6_12 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_6_13 = s_b_6_11==s_b_6_12 (const) */
    uint8_t s_b_6_13 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_6_14: If s_b_6_13: Jump b_13 else b_30 (const) */
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
    /* execute.a64:968 [D] s_b_7_0 = sym_15422_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_15422_0_address, emitter.context().types().u64());
    /* execute.a64:968 [D] s_b_7_1: sym_100874_3_parameter_address = s_b_7_0, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_100874_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 1 s_b_7_0 => sym_100879_0_data8 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_100879_0_data8, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(1));
    }
    /* execute.a64:1730 [D] s_b_7_3 = sym_100879_0_data8 uint8_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_100879_0_data8, emitter.context().types().u8());
    /* execute.a64:1730 [D] s_b_7_4 = (s8)s_b_7_3 */
    auto s_b_7_4 = emitter.reinterpret(s_b_7_3, emitter.context().types().s8());
    /* execute.a64:1730 [D] s_b_7_5 = (s64)s_b_7_4 */
    auto s_b_7_5 = emitter.sx(s_b_7_4, emitter.context().types().s64());
    /* execute.a64:1730 [D] s_b_7_6 = (u64)s_b_7_5 */
    auto s_b_7_6 = emitter.reinterpret(s_b_7_5, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_7_7=sym_15416_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_7_8: sym_103140_3_parameter_value = s_b_7_6, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_103140_3_parameter_value, s_b_7_6);
    /* execute.a64:2745 [F] s_b_7_9 = (u32)s_b_7_7 (const) */
    /* execute.a64:2745 [F] s_b_7_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_7_11 = s_b_7_9==s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_7_12: If s_b_7_11: Jump b_14 else b_31 (const) */
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
    /* execute.a64:975 [D] s_b_8_0 = sym_15422_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_15422_0_address, emitter.context().types().u64());
    /* execute.a64:975 [F] s_b_8_1=sym_15416_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_8_2 = (u64)s_b_8_1 (const) */
    /* ???:4294967295 [D] s_b_8_3 = s_b_8_0+s_b_8_2 */
    auto s_b_8_3 = emitter.add(s_b_8_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:975 [D] s_b_8_4: sym_15422_0_address = s_b_8_3, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_15422_0_address, s_b_8_3);
    /* execute.a64:975 [F] s_b_8_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:978 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:978 [D] s_b_9_1 = sym_15422_0_address uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_15422_0_address, emitter.context().types().u64());
    /* execute.a64:978 [D] s_b_9_2: sym_101055_3_parameter_value = s_b_9_1, dominates: s_b_15_0 s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_101055_3_parameter_value, s_b_9_1);
    /* execute.a64:2809 [F] s_b_9_3 = !s_b_9_0 (const) */
    uint8_t s_b_9_3 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_9_4: If s_b_9_3: Jump b_15 else b_16 (const) */
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
    /* execute.a64:2796 [F] s_b_10_0=sym_15416_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_10_2: sym_100463_1__R_s_b_0_5 = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_100463_1__R_s_b_0_5, s_b_10_1);
    /* execute.a64:2796 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_24,  */
  fixed_block_b_11: 
  {
    /* execute.a64:958 [D] s_b_11_0 = sym_100463_1__R_s_b_0_5 uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_100463_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:958 [D] s_b_11_1: sym_15422_0_address = s_b_11_0, dominates: s_b_1_0 s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15422_0_address, s_b_11_0);
    /* execute.a64:960 [F] s_b_11_2=sym_15416_3_parameter_inst.P (const) */
    /* execute.a64:960 [F] s_b_11_3: If s_b_11_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:1786 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_12_1 = sym_100492_3_parameter_address uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_100492_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_12_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_12_1);
    /* execute.a64:0 [F] s_b_12_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_6, b_30,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1786 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_13_1 = sym_100683_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_100683_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_31,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1786 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_14_1 = sym_100874_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_100874_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_14_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2810 [D] s_b_15_0 = sym_101055_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_101055_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_15_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_15_2 = s_b_15_0&s_b_15_1 */
    auto s_b_15_2 = emitter.bitwise_and(s_b_15_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_15_3: sym_101055_3_parameter_value = s_b_15_2, dominates: s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_101055_3_parameter_value, s_b_15_2);
    /* execute.a64:2810 [F] s_b_15_4: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_9, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2813 [F] s_b_16_0=sym_15416_3_parameter_inst.rn (const) */
    /* execute.a64:2813 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2813 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
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
    /* execute.a64:2814 [D] s_b_17_0 = sym_101055_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_101055_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_17_1: sym_101946_3_parameter_value = s_b_17_0, dominates: s_b_25_0 s_b_26_0 s_b_27_0  */
    emitter.store_local(DV_sym_101946_3_parameter_value, s_b_17_0);
    /* execute.a64:2777 [F] s_b_17_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_17_3 = __builtin_get_feature */
    uint32_t s_b_17_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_17_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_17_5 = s_b_17_3==s_b_17_4 (const) */
    uint8_t s_b_17_5 = ((uint8_t)(s_b_17_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_17_6: If s_b_17_5: Jump b_25 else b_32 (const) */
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
    /* execute.a64:2816 [F] s_b_18_0=sym_15416_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_18_1 = sym_101055_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_101055_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1);
    /* execute.a64:2816 [F] s_b_18_3: Jump b_19 (const) */
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
    /* execute.a64:2764 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_20_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_20_4: If s_b_20_3: Jump b_21 else b_28 (const) */
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
    /* execute.a64:2765 [D] s_b_21_0 = ReadReg 21 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_21_1: sym_101111_1__R_s_b_14_0 = s_b_21_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_101111_1__R_s_b_14_0, s_b_21_0);
    /* execute.a64:2765 [F] s_b_21_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_28,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2768 [D] s_b_22_0 = ReadReg 21 (u64) */
    auto s_b_22_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_22_1: sym_101111_1__R_s_b_14_0 = s_b_22_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_101111_1__R_s_b_14_0, s_b_22_0);
    /* execute.a64:2768 [F] s_b_22_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_28,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2770 [D] s_b_23_0 = ReadReg 22 (u64) */
    auto s_b_23_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_23_1: sym_101111_1__R_s_b_14_0 = s_b_23_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_101111_1__R_s_b_14_0, s_b_23_0);
    /* execute.a64:2770 [F] s_b_23_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2794 [D] s_b_24_0 = sym_101111_1__R_s_b_14_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_101111_1__R_s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_24_1: sym_100463_1__R_s_b_0_5 = s_b_24_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_100463_1__R_s_b_0_5, s_b_24_0);
    /* execute.a64:2794 [F] s_b_24_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_17,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2778 [D] s_b_25_0 = sym_101946_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_101946_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_25_1: WriteReg 21 = s_b_25_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_25_0);
    /* execute.a64:2778 [F] s_b_25_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_32,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2781 [D] s_b_26_0 = sym_101946_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_101946_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_26_1: WriteReg 21 = s_b_26_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_26_0);
    /* execute.a64:2781 [F] s_b_26_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_32,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2783 [D] s_b_27_0 = sym_101946_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_101946_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_27_1: WriteReg 22 = s_b_27_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_27_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_27_0);
    /* execute.a64:2783 [F] s_b_27_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_20,  */
  fixed_block_b_28: 
  {
    /* execute.a64:3075 [F] s_b_28_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_28_1 = __builtin_get_feature */
    uint32_t s_b_28_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_28_2 = (u8)s_b_28_1 (const) */
    /* execute.a64:2767 [F] s_b_28_3 = (u32)s_b_28_2 (const) */
    /* execute.a64:2767 [F] s_b_28_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
    uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_28_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_28_6: If s_b_28_5: Jump b_22 else b_23 (const) */
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
    /* execute.a64:2747 [F] s_b_29_0=sym_15416_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_29_1 = sym_102142_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_102142_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_29_2: WriteRegBank 0:s_b_29_0 = s_b_29_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_29_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_29_1);
    /* execute.a64:0 [F] s_b_29_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_6,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2747 [F] s_b_30_0=sym_15416_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_30_1 = sym_102652_3_parameter_value uint64_t */
    auto s_b_30_1 = emitter.load_local(DV_sym_102652_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_30_2: WriteRegBank 0:s_b_30_0 = s_b_30_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_30_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_30_1);
    /* execute.a64:0 [F] s_b_30_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_7,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2747 [F] s_b_31_0=sym_15416_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_31_1 = sym_103140_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_103140_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_31_2: WriteRegBank 0:s_b_31_0 = s_b_31_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1);
    /* execute.a64:0 [F] s_b_31_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_17,  */
  fixed_block_b_32: 
  {
    /* execute.a64:3075 [F] s_b_32_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_32_1 = __builtin_get_feature */
    uint32_t s_b_32_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_32_2 = (u8)s_b_32_1 (const) */
    /* execute.a64:2780 [F] s_b_32_3 = (u32)s_b_32_2 (const) */
    /* execute.a64:2780 [F] s_b_32_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_32_5 = s_b_32_3==s_b_32_4 (const) */
    uint8_t s_b_32_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_32_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_32_6: If s_b_32_5: Jump b_26 else b_27 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldrsw_lit(const arm64_decode_a64_LOAD_REG_LIT&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldurh(const arm64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_16349_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_113094_1__R_s_b_13_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_113196_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_113262_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_113174_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112978_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_16335_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_10 else b_8 (const) */
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
    /* execute.a64:1399 [D] s_b_1_0 = sym_16349_0_value uint16_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16349_0_value, emitter.context().types().u16());
    /* execute.a64:1399 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_2=sym_16335_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_3 = (u32)s_b_1_1 */
    auto s_b_1_3 = emitter.truncate(s_b_1_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_5: sym_113174_3_parameter_value = s_b_1_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_113174_3_parameter_value, s_b_1_4);
    /* execute.a64:2745 [F] s_b_1_6 = (u32)s_b_1_2 (const) */
    /* execute.a64:2745 [F] s_b_1_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_1_8 = s_b_1_6==s_b_1_7 (const) */
    uint8_t s_b_1_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_1_9: If s_b_1_8: Jump b_2 else b_15 (const) */
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
    /* execute.a64:1400 [F] s_b_3_0=sym_16335_3_parameter_inst.opc (const) */
    /* execute.a64:1400 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1400 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1400 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1400 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1401 [D] s_b_4_0 = sym_16349_0_value uint16_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_16349_0_value, emitter.context().types().u16());
    /* execute.a64:1401 [D] s_b_4_1 = (s16)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s16());
    /* execute.a64:1401 [D] s_b_4_2 = (s64)s_b_4_1 */
    auto s_b_4_2 = emitter.sx(s_b_4_1, emitter.context().types().s64());
    /* execute.a64:1401 [D] s_b_4_3 = (u64)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_4_4=sym_16335_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_4_5: sym_113196_3_parameter_value = s_b_4_3, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_113196_3_parameter_value, s_b_4_3);
    /* execute.a64:2745 [F] s_b_4_6 = (u32)s_b_4_4 (const) */
    /* execute.a64:2745 [F] s_b_4_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_4_8 = s_b_4_6==s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_4_9: If s_b_4_8: Jump b_2 else b_16 (const) */
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
    /* execute.a64:1402 [F] s_b_5_0=sym_16335_3_parameter_inst.opc (const) */
    /* execute.a64:1402 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1402 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:1402 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:1402 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1403 [D] s_b_6_0 = sym_16349_0_value uint16_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_16349_0_value, emitter.context().types().u16());
    /* execute.a64:1403 [D] s_b_6_1 = (s16)s_b_6_0 */
    auto s_b_6_1 = emitter.reinterpret(s_b_6_0, emitter.context().types().s16());
    /* execute.a64:1403 [D] s_b_6_2 = (s64)s_b_6_1 */
    auto s_b_6_2 = emitter.sx(s_b_6_1, emitter.context().types().s64());
    /* execute.a64:1403 [D] s_b_6_3 = (u64)s_b_6_2 */
    auto s_b_6_3 = emitter.reinterpret(s_b_6_2, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_4=sym_16335_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_6_5 = (u32)s_b_6_3 */
    auto s_b_6_5 = emitter.truncate(s_b_6_3, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_7: sym_113262_3_parameter_value = s_b_6_6, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_113262_3_parameter_value, s_b_6_6);
    /* execute.a64:2745 [F] s_b_6_8 = (u32)s_b_6_4 (const) */
    /* execute.a64:2745 [F] s_b_6_9 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_6_10 = s_b_6_8==s_b_6_9 (const) */
    uint8_t s_b_6_10 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_6_11: If s_b_6_10: Jump b_2 else b_17 (const) */
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
    /* execute.a64:1405 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1405 [F] s_b_7_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2796 [F] s_b_8_0=sym_16335_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_8_2: sym_112978_1__R_s_b_0_5 = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_112978_1__R_s_b_0_5, s_b_8_1);
    /* execute.a64:2796 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_14,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1392 [D] s_b_9_0 = sym_112978_1__R_s_b_0_5 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_112978_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1393 [F] s_b_9_1=sym_16335_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_9_2 = (u64)s_b_9_1 (const) */
    /* ???:4294967295 [D] s_b_9_3 = s_b_9_0+s_b_9_2 */
    auto s_b_9_3 = emitter.add(s_b_9_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* ???:4294967295 [D] s_b_9_4 = Load 2 s_b_9_3 => sym_16349_0_value */
    auto s_b_9_4 = emitter.load_memory(s_b_9_3, emitter.context().types().u16());
    emitter.store_local(DV_sym_16349_0_value, s_b_9_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_3, s_b_9_4, emitter.const_u8(2));
    }
    /* execute.a64:1398 [F] s_b_9_5=sym_16335_3_parameter_inst.opc (const) */
    /* execute.a64:1398 [F] s_b_9_6 = (u32)s_b_9_5 (const) */
    /* execute.a64:1398 [F] s_b_9_7 = constant u32 1 (const) */
    /* execute.a64:1398 [F] s_b_9_8 = s_b_9_6==s_b_9_7 (const) */
    uint8_t s_b_9_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:1398 [F] s_b_9_9: If s_b_9_8: Jump b_1 else b_3 (const) */
    if (s_b_9_8) 
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
    /* execute.a64:2764 [F] s_b_10_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_10_1 = __builtin_get_feature */
    uint32_t s_b_10_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(s_b_10_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_10_4: If s_b_10_3: Jump b_11 else b_18 (const) */
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
    /* execute.a64:2765 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_11_1: sym_113094_1__R_s_b_13_0 = s_b_11_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_113094_1__R_s_b_13_0, s_b_11_0);
    /* execute.a64:2765 [F] s_b_11_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_18,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2768 [D] s_b_12_0 = ReadReg 21 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_12_1: sym_113094_1__R_s_b_13_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_113094_1__R_s_b_13_0, s_b_12_0);
    /* execute.a64:2768 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2770 [D] s_b_13_0 = ReadReg 22 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_13_1: sym_113094_1__R_s_b_13_0 = s_b_13_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_113094_1__R_s_b_13_0, s_b_13_0);
    /* execute.a64:2770 [F] s_b_13_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_11, b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2794 [D] s_b_14_0 = sym_113094_1__R_s_b_13_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_113094_1__R_s_b_13_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_14_1: sym_112978_1__R_s_b_0_5 = s_b_14_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_112978_1__R_s_b_0_5, s_b_14_0);
    /* execute.a64:2794 [F] s_b_14_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2747 [F] s_b_15_0=sym_16335_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_15_1 = sym_113174_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_113174_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
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
    /* execute.a64:2747 [F] s_b_16_0=sym_16335_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_16_1 = sym_113196_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_113196_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
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
    /* execute.a64:2747 [F] s_b_17_0=sym_16335_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_113262_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_113262_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
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
    /* execute.a64:3075 [F] s_b_18_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_18_1 = __builtin_get_feature */
    uint32_t s_b_18_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_18_2 = (u8)s_b_18_1 (const) */
    /* execute.a64:2767 [F] s_b_18_3 = (u32)s_b_18_2 (const) */
    /* execute.a64:2767 [F] s_b_18_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_18_5 = s_b_18_3==s_b_18_4 (const) */
    uint8_t s_b_18_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_18_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_18_6: If s_b_18_5: Jump b_12 else b_13 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_madd(const arm64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_123893_1_tmp_s_b_18_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123717_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123990_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123890_1_tmp_s_b_18_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_123935_1_temporary_value;
  auto DV_sym_123935_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_123820_1_temporary_value;
  auto DV_sym_123820_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_123764_1_temporary_value;
  auto DV_sym_123764_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_123806_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124012_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123882_1__R_s_b_18_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_123848_1_temporary_value;
  auto DV_sym_123848_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_123736_1_temporary_value;
  auto DV_sym_123736_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_123907_1_temporary_value;
  auto DV_sym_123907_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123960_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123798_1__R_s_b_4_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2406 [F] s_b_0_0=sym_16663_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2720 [F] s_b_1_0=sym_16663_3_parameter_inst.ra (const) */
    /* execute.a64:2714 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2714 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2722 [F] s_b_2_0=sym_16663_3_parameter_inst.ra (const) */
    /* execute.a64:2709 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2709 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_2_4: If s_b_2_3: Jump b_7 else b_8 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_6, b_9,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2406 [D] s_b_3_0 = sym_123717_1__R_s_b_0_4 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_123717_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2406 [F] s_b_3_1=sym_16663_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_123806_1_tmp_s_b_4_0 = s_b_3_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_123806_1_tmp_s_b_4_0, s_b_3_0);
    /* execute.a64:2719 [F] s_b_3_3: If s_b_3_1: Jump b_10 else b_11 (const) */
    if (insn.sf) 
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
    /* execute.a64:2714 [F] s_b_4_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_4_1: sym_123736_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_123736_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_123736_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2714 [F] s_b_5_0=sym_16663_3_parameter_inst.ra (const) */
    /* execute.a64:2714 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_5_2: sym_123736_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_123736_1_temporary_value, s_b_5_1);
    /* execute.a64:2714 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2714 [D] s_b_6_0 = sym_123736_1_temporary_value uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_123736_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_6_1: sym_123717_1__R_s_b_0_4 = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_123717_1__R_s_b_0_4, s_b_6_0);
    /* execute.a64:2720 [F] s_b_6_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2709 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_7_1: sym_123764_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_123764_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_123764_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2709 [F] s_b_8_0=sym_16663_3_parameter_inst.ra (const) */
    /* execute.a64:2709 [D] s_b_8_1 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_8_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_8_2: sym_123764_1_temporary_value = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_123764_1_temporary_value, s_b_8_1);
    /* execute.a64:2709 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2709 [D] s_b_9_0 = sym_123764_1_temporary_value uint32_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_123764_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_9_1 = (u64)s_b_9_0 */
    auto s_b_9_1 = emitter.zx(s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_9_2: sym_123717_1__R_s_b_0_4 = s_b_9_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_123717_1__R_s_b_0_4, s_b_9_1);
    /* execute.a64:2722 [F] s_b_9_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2720 [F] s_b_10_0=sym_16663_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2714 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2722 [F] s_b_11_0=sym_16663_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2709 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_11_4: If s_b_11_3: Jump b_16 else b_17 (const) */
    if (s_b_11_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_15, b_18,  */
  fixed_block_b_12: 
  {
    /* ???:4294967295 [D] s_b_12_0 = sym_123806_1_tmp_s_b_4_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_123806_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2406 [D] s_b_12_1 = sym_123798_1__R_s_b_4_5 uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_123798_1__R_s_b_4_5, emitter.context().types().u64());
    /* execute.a64:2406 [F] s_b_12_2=sym_16663_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_12_3: sym_123890_1_tmp_s_b_18_0 = s_b_12_0, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_123890_1_tmp_s_b_18_0, s_b_12_0);
    /* ???:4294967295 [D] s_b_12_4: sym_123893_1_tmp_s_b_18_1 = s_b_12_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_123893_1_tmp_s_b_18_1, s_b_12_1);
    /* execute.a64:2719 [F] s_b_12_5: If s_b_12_2: Jump b_19 else b_20 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2714 [F] s_b_13_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_13_1: sym_123820_1_temporary_value = s_b_13_0 (const), dominates: s_b_15_0  */
    CV_sym_123820_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_123820_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2714 [F] s_b_14_0=sym_16663_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_14_2: sym_123820_1_temporary_value = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_123820_1_temporary_value, s_b_14_1);
    /* execute.a64:2714 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2714 [D] s_b_15_0 = sym_123820_1_temporary_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_123820_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_15_1: sym_123798_1__R_s_b_4_5 = s_b_15_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_123798_1__R_s_b_4_5, s_b_15_0);
    /* execute.a64:2720 [F] s_b_15_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [F] s_b_16_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_16_1: sym_123848_1_temporary_value = s_b_16_0 (const), dominates: s_b_18_0  */
    CV_sym_123848_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_123848_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_11,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2709 [F] s_b_17_0=sym_16663_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_17_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_17_2: sym_123848_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_123848_1_temporary_value, s_b_17_1);
    /* execute.a64:2709 [F] s_b_17_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_16, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2709 [D] s_b_18_0 = sym_123848_1_temporary_value uint32_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_123848_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
    auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_18_2: sym_123798_1__R_s_b_4_5 = s_b_18_1, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_123798_1__R_s_b_4_5, s_b_18_1);
    /* execute.a64:2722 [F] s_b_18_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_12,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2720 [F] s_b_19_0=sym_16663_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2714 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_19_4: If s_b_19_3: Jump b_22 else b_23 (const) */
    if (s_b_19_3) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_12,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2722 [F] s_b_20_0=sym_16663_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
    /* execute.a64:2709 [F] s_b_20_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_20_4: If s_b_20_3: Jump b_25 else b_26 (const) */
    if (s_b_20_3) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_24, b_27,  */
  fixed_block_b_21: 
  {
    /* ???:4294967295 [D] s_b_21_0 = sym_123893_1_tmp_s_b_18_1 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_123893_1_tmp_s_b_18_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_1 = sym_123890_1_tmp_s_b_18_0 uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_123890_1_tmp_s_b_18_0, emitter.context().types().u64());
    /* execute.a64:2406 [D] s_b_21_2 = sym_123882_1__R_s_b_18_6 uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_123882_1__R_s_b_18_6, emitter.context().types().u64());
    /* execute.a64:2406 [D] s_b_21_3 = s_b_21_0*s_b_21_2 */
    auto s_b_21_3 = emitter.mul(s_b_21_0, s_b_21_2);
    /* execute.a64:2406 [D] s_b_21_4 = s_b_21_1+s_b_21_3 */
    auto s_b_21_4 = emitter.add(s_b_21_1, s_b_21_3);
    /* execute.a64:2407 [F] s_b_21_5=sym_16663_3_parameter_inst.sf (const) */
    /* execute.a64:2407 [D] s_b_21_6: sym_123960_3_parameter_value = s_b_21_4, dominates: s_b_28_1 s_b_29_1  */
    emitter.store_local(DV_sym_123960_3_parameter_value, s_b_21_4);
    /* execute.a64:2753 [F] s_b_21_7: If s_b_21_5: Jump b_28 else b_29 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_19,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2714 [F] s_b_22_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_22_1: sym_123907_1_temporary_value = s_b_22_0 (const), dominates: s_b_24_0  */
    CV_sym_123907_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_123907_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_22_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [F] s_b_23_0=sym_16663_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_23_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_23_2: sym_123907_1_temporary_value = s_b_23_1, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_123907_1_temporary_value, s_b_23_1);
    /* execute.a64:2714 [F] s_b_23_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [D] s_b_24_0 = sym_123907_1_temporary_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_123907_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_24_1: sym_123882_1__R_s_b_18_6 = s_b_24_0, dominates: s_b_21_2  */
    emitter.store_local(DV_sym_123882_1__R_s_b_18_6, s_b_24_0);
    /* execute.a64:2720 [F] s_b_24_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2709 [F] s_b_25_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_25_1: sym_123935_1_temporary_value = s_b_25_0 (const), dominates: s_b_27_0  */
    CV_sym_123935_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_123935_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_25_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_20,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2709 [F] s_b_26_0=sym_16663_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_26_2: sym_123935_1_temporary_value = s_b_26_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_123935_1_temporary_value, s_b_26_1);
    /* execute.a64:2709 [F] s_b_26_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_25, b_26,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2709 [D] s_b_27_0 = sym_123935_1_temporary_value uint32_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_123935_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_27_1 = (u64)s_b_27_0 */
    auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_27_2: sym_123882_1__R_s_b_18_6 = s_b_27_1, dominates: s_b_21_2  */
    emitter.store_local(DV_sym_123882_1__R_s_b_18_6, s_b_27_1);
    /* execute.a64:2722 [F] s_b_27_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_21,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2754 [F] s_b_28_0=sym_16663_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_28_1 = sym_123960_3_parameter_value uint64_t */
    auto s_b_28_1 = emitter.load_local(DV_sym_123960_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_28_2: sym_123990_3_parameter_value = s_b_28_1, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_123990_3_parameter_value, s_b_28_1);
    /* execute.a64:2745 [F] s_b_28_3 = (u32)s_b_28_0 (const) */
    /* execute.a64:2745 [F] s_b_28_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
    uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_28_6: If s_b_28_5: Jump b_30 else b_31 (const) */
    if (s_b_28_5) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_21,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2756 [F] s_b_29_0=sym_16663_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_29_1 = sym_123960_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_123960_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_29_2 = (u32)s_b_29_1 */
    auto s_b_29_2 = emitter.truncate(s_b_29_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_29_3 = (u64)s_b_29_2 */
    auto s_b_29_3 = emitter.zx(s_b_29_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_29_4: sym_124012_3_parameter_value = s_b_29_3, dominates: s_b_32_1  */
    emitter.store_local(DV_sym_124012_3_parameter_value, s_b_29_3);
    /* execute.a64:2745 [F] s_b_29_5 = (u32)s_b_29_0 (const) */
    /* execute.a64:2745 [F] s_b_29_6 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_29_7 = s_b_29_5==s_b_29_6 (const) */
    uint8_t s_b_29_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_29_8: If s_b_29_7: Jump b_30 else b_32 (const) */
    if (s_b_29_7) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_28, b_29, b_31, b_32,  */
  fixed_block_b_30: 
  {
    /* ???:4294967295 [F] s_b_30_0: Return */
    goto fixed_done;
  }
  /* b_28,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2747 [F] s_b_31_0=sym_16663_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_31_1 = sym_123990_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_123990_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_31_2: WriteRegBank 0:s_b_31_0 = s_b_31_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_31_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_31_1);
    /* execute.a64:0 [F] s_b_31_3: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_29,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2747 [F] s_b_32_0=sym_16663_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_32_1 = sym_124012_3_parameter_value uint64_t */
    auto s_b_32_1 = emitter.load_local(DV_sym_124012_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_32_2: WriteRegBank 0:s_b_32_0 = s_b_32_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_32_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_32_1);
    /* execute.a64:0 [F] s_b_32_3: Jump b_30 (const) */
    goto fixed_block_b_30;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_msr_imm(const arm64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:378 [F] s_b_0_0=sym_18021_3_parameter_inst.op1 (const) */
    /* execute.a64:378 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:378 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:378 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* execute.a64:378 [F] s_b_0_4=sym_18021_3_parameter_inst.op2 (const) */
    /* execute.a64:378 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:378 [F] s_b_0_6 = constant u32 5 (const) */
    /* execute.a64:378 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)5ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:378 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
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
    /* execute.a64:380 [F] s_b_1_0=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:380 [F] s_b_1_1 = (u8)s_b_1_0 (const) */
    /* execute.a64:3016 [F] s_b_1_2 = constant u32 1 (const) */
    /* execute.a64:3016 [F] s_b_1_3 = (u32)s_b_1_1 (const) */
    /* execute.a64:3016 [D] s_b_1_4 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, emitter.const_u32(((uint32_t)((uint8_t)insn.crm))));
    /* execute.a64:0 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_7,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:381 [F] s_b_3_0=sym_18021_3_parameter_inst.op1 (const) */
    /* execute.a64:381 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:381 [F] s_b_3_2 = constant u32 3 (const) */
    /* execute.a64:381 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* execute.a64:381 [F] s_b_3_4=sym_18021_3_parameter_inst.op2 (const) */
    /* execute.a64:381 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:381 [F] s_b_3_6 = constant u32 6 (const) */
    /* execute.a64:381 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:381 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:383 [D] s_b_4_0 = ReadReg 5 (u8) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_4_0, emitter.const_u8(1));
    }
    /* execute.a64:383 [F] s_b_4_1=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:383 [F] s_b_4_2 = (u32)s_b_4_1 (const) */
    /* execute.a64:383 [F] s_b_4_3 = constant u32 8 (const) */
    /* execute.a64:383 [F] s_b_4_4 = s_b_4_2&s_b_4_3 (const) */
    uint32_t s_b_4_4 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)8ULL));
    /* execute.a64:383 [F] s_b_4_5 = constant u32 8 (const) */
    /* execute.a64:383 [F] s_b_4_6 = s_b_4_4==s_b_4_5 (const) */
    uint8_t s_b_4_6 = ((uint8_t)(s_b_4_4 == (uint32_t)8ULL));
    /* execute.a64:383 [D] s_b_4_7 = s_b_4_0|s_b_4_6 */
    auto s_b_4_7 = emitter.bitwise_or(s_b_4_0, emitter.const_u8(s_b_4_6));
    /* execute.a64:383 [D] s_b_4_8: WriteReg 5 = s_b_4_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), s_b_4_7, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), s_b_4_7);
    /* execute.a64:384 [D] s_b_4_9 = ReadReg 6 (u8) */
    auto s_b_4_9 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_4_9, emitter.const_u8(1));
    }
    /* execute.a64:384 [F] s_b_4_10=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:384 [F] s_b_4_11 = (u32)s_b_4_10 (const) */
    /* execute.a64:384 [F] s_b_4_12 = constant u32 4 (const) */
    /* execute.a64:384 [F] s_b_4_13 = s_b_4_11&s_b_4_12 (const) */
    uint32_t s_b_4_13 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)4ULL));
    /* execute.a64:384 [F] s_b_4_14 = constant u32 4 (const) */
    /* execute.a64:384 [F] s_b_4_15 = s_b_4_13==s_b_4_14 (const) */
    uint8_t s_b_4_15 = ((uint8_t)(s_b_4_13 == (uint32_t)4ULL));
    /* execute.a64:384 [D] s_b_4_16 = s_b_4_9|s_b_4_15 */
    auto s_b_4_16 = emitter.bitwise_or(s_b_4_9, emitter.const_u8(s_b_4_15));
    /* execute.a64:384 [D] s_b_4_17: WriteReg 6 = s_b_4_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), s_b_4_16, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), s_b_4_16);
    /* execute.a64:385 [D] s_b_4_18 = ReadReg 7 (u8) */
    auto s_b_4_18 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_4_18, emitter.const_u8(1));
    }
    /* execute.a64:385 [F] s_b_4_19=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:385 [F] s_b_4_20 = (u32)s_b_4_19 (const) */
    /* execute.a64:385 [F] s_b_4_21 = constant u32 2 (const) */
    /* execute.a64:385 [F] s_b_4_22 = s_b_4_20&s_b_4_21 (const) */
    uint32_t s_b_4_22 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)2ULL));
    /* execute.a64:385 [F] s_b_4_23 = constant u32 2 (const) */
    /* execute.a64:385 [F] s_b_4_24 = s_b_4_22==s_b_4_23 (const) */
    uint8_t s_b_4_24 = ((uint8_t)(s_b_4_22 == (uint32_t)2ULL));
    /* execute.a64:385 [D] s_b_4_25 = s_b_4_18|s_b_4_24 */
    auto s_b_4_25 = emitter.bitwise_or(s_b_4_18, emitter.const_u8(s_b_4_24));
    /* execute.a64:385 [D] s_b_4_26: WriteReg 7 = s_b_4_25 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), s_b_4_25, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), s_b_4_25);
    /* execute.a64:386 [D] s_b_4_27 = ReadReg 8 (u8) */
    auto s_b_4_27 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_4_27, emitter.const_u8(1));
    }
    /* execute.a64:386 [F] s_b_4_28=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:386 [F] s_b_4_29 = (u32)s_b_4_28 (const) */
    /* execute.a64:386 [F] s_b_4_30 = constant u32 1 (const) */
    /* execute.a64:386 [F] s_b_4_31 = s_b_4_29&s_b_4_30 (const) */
    uint32_t s_b_4_31 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)1ULL));
    /* execute.a64:386 [F] s_b_4_32 = constant u32 1 (const) */
    /* execute.a64:386 [F] s_b_4_33 = s_b_4_31==s_b_4_32 (const) */
    uint8_t s_b_4_33 = ((uint8_t)(s_b_4_31 == (uint32_t)1ULL));
    /* execute.a64:386 [D] s_b_4_34 = s_b_4_27|s_b_4_33 */
    auto s_b_4_34 = emitter.bitwise_or(s_b_4_27, emitter.const_u8(s_b_4_33));
    /* execute.a64:386 [D] s_b_4_35: WriteReg 8 = s_b_4_34 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), s_b_4_34, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), s_b_4_34);
    /* execute.a64:383 [F] s_b_4_36: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:387 [F] s_b_5_0=sym_18021_3_parameter_inst.op1 (const) */
    /* execute.a64:387 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:387 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:387 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* execute.a64:387 [F] s_b_5_4=sym_18021_3_parameter_inst.op2 (const) */
    /* execute.a64:387 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:387 [F] s_b_5_6 = constant u32 7 (const) */
    /* execute.a64:387 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:387 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:389 [D] s_b_6_0 = ReadReg 5 (u8) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_6_0, emitter.const_u8(1));
    }
    /* execute.a64:389 [F] s_b_6_1=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:389 [F] s_b_6_2 = (u32)s_b_6_1 (const) */
    /* execute.a64:389 [F] s_b_6_3 = constant u32 8 (const) */
    /* execute.a64:389 [F] s_b_6_4 = s_b_6_2&s_b_6_3 (const) */
    uint32_t s_b_6_4 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)8ULL));
    /* execute.a64:389 [F] s_b_6_5 = constant u32 8 (const) */
    /* execute.a64:389 [F] s_b_6_6 = s_b_6_4!=s_b_6_5 (const) */
    uint8_t s_b_6_6 = ((uint8_t)(s_b_6_4 != (uint32_t)8ULL));
    /* execute.a64:389 [D] s_b_6_7 = s_b_6_0&s_b_6_6 */
    auto s_b_6_7 = emitter.bitwise_and(s_b_6_0, emitter.const_u8(s_b_6_6));
    /* execute.a64:389 [D] s_b_6_8: WriteReg 5 = s_b_6_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), s_b_6_7, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), s_b_6_7);
    /* execute.a64:390 [D] s_b_6_9 = ReadReg 6 (u8) */
    auto s_b_6_9 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_6_9, emitter.const_u8(1));
    }
    /* execute.a64:390 [F] s_b_6_10=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:390 [F] s_b_6_11 = (u32)s_b_6_10 (const) */
    /* execute.a64:390 [F] s_b_6_12 = constant u32 4 (const) */
    /* execute.a64:390 [F] s_b_6_13 = s_b_6_11&s_b_6_12 (const) */
    uint32_t s_b_6_13 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)4ULL));
    /* execute.a64:390 [F] s_b_6_14 = constant u32 4 (const) */
    /* execute.a64:390 [F] s_b_6_15 = s_b_6_13!=s_b_6_14 (const) */
    uint8_t s_b_6_15 = ((uint8_t)(s_b_6_13 != (uint32_t)4ULL));
    /* execute.a64:390 [D] s_b_6_16 = s_b_6_9&s_b_6_15 */
    auto s_b_6_16 = emitter.bitwise_and(s_b_6_9, emitter.const_u8(s_b_6_15));
    /* execute.a64:390 [D] s_b_6_17: WriteReg 6 = s_b_6_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), s_b_6_16, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), s_b_6_16);
    /* execute.a64:391 [D] s_b_6_18 = ReadReg 7 (u8) */
    auto s_b_6_18 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_6_18, emitter.const_u8(1));
    }
    /* execute.a64:391 [F] s_b_6_19=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:391 [F] s_b_6_20 = (u32)s_b_6_19 (const) */
    /* execute.a64:391 [F] s_b_6_21 = constant u32 2 (const) */
    /* execute.a64:391 [F] s_b_6_22 = s_b_6_20&s_b_6_21 (const) */
    uint32_t s_b_6_22 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)2ULL));
    /* execute.a64:391 [F] s_b_6_23 = constant u32 2 (const) */
    /* execute.a64:391 [F] s_b_6_24 = s_b_6_22!=s_b_6_23 (const) */
    uint8_t s_b_6_24 = ((uint8_t)(s_b_6_22 != (uint32_t)2ULL));
    /* execute.a64:391 [D] s_b_6_25 = s_b_6_18&s_b_6_24 */
    auto s_b_6_25 = emitter.bitwise_and(s_b_6_18, emitter.const_u8(s_b_6_24));
    /* execute.a64:391 [D] s_b_6_26: WriteReg 7 = s_b_6_25 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), s_b_6_25, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), s_b_6_25);
    /* execute.a64:392 [D] s_b_6_27 = ReadReg 8 (u8) */
    auto s_b_6_27 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_6_27, emitter.const_u8(1));
    }
    /* execute.a64:392 [F] s_b_6_28=sym_18021_3_parameter_inst.crm (const) */
    /* execute.a64:392 [F] s_b_6_29 = (u32)s_b_6_28 (const) */
    /* execute.a64:392 [F] s_b_6_30 = constant u32 1 (const) */
    /* execute.a64:392 [F] s_b_6_31 = s_b_6_29&s_b_6_30 (const) */
    uint32_t s_b_6_31 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)1ULL));
    /* execute.a64:392 [F] s_b_6_32 = constant u32 1 (const) */
    /* execute.a64:392 [F] s_b_6_33 = s_b_6_31!=s_b_6_32 (const) */
    uint8_t s_b_6_33 = ((uint8_t)(s_b_6_31 != (uint32_t)1ULL));
    /* execute.a64:392 [D] s_b_6_34 = s_b_6_27&s_b_6_33 */
    auto s_b_6_34 = emitter.bitwise_and(s_b_6_27, emitter.const_u8(s_b_6_33));
    /* execute.a64:392 [D] s_b_6_35: WriteReg 8 = s_b_6_34 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), s_b_6_34, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), s_b_6_34);
    /* execute.a64:393 [D] s_b_6_36 = trigger_irq */
    emitter.call(__captive_trigger_irq);
    /* execute.a64:389 [F] s_b_6_37: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:395 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:395 [F] s_b_7_1: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_not_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:6245 [F] s_b_0_0=sym_19527_3_parameter_inst.Q (const) */
    /* execute.simd:6245 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:6245 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:6245 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:6245 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:6246 [F] s_b_1_0=sym_19527_3_parameter_inst.rd (const) */
    /* execute.simd:6246 [F] s_b_1_1=sym_19527_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:6246 [D] s_b_1_3 = ~s_b_1_2 */
    auto s_b_1_3 = emitter.bitwise_not(s_b_1_2);
    /* execute.simd:6326 [D] s_b_1_4: WriteRegBank 2:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3);
    /* execute.simd:6327 [F] s_b_1_5 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_6: WriteRegBank 3:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_7: Jump b_2 (const) */
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
    /* execute.simd:6251 [F] s_b_3_0=sym_19527_3_parameter_inst.rn (const) */
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
    /* execute.simd:6252 [F] s_b_3_3=sym_19527_3_parameter_inst.rd (const) */
    /* execute.simd:6252 [D] s_b_3_4 = ~s_b_3_1 */
    auto s_b_3_4 = emitter.bitwise_not(s_b_3_1);
    /* execute.simd:6252 [D] s_b_3_5 = ~s_b_3_2 */
    auto s_b_3_5 = emitter.bitwise_not(s_b_3_2);
    /* execute.simd:6333 [D] s_b_3_6: WriteRegBank 2:s_b_3_3 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:6334 [D] s_b_3_7: WriteRegBank 3:s_b_3_3 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_5);
    /* execute.simd:0 [F] s_b_3_8: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_prfm_reg(const arm64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_rev32_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:635 [F] s_b_0_0=sym_20311_3_parameter_inst.arrangement (const) */
    /* execute.simd:636 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:646 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:657 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:667 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:635 [F] s_b_0_5: Switch s_b_0_0: < <todo> > def b_6 (const) -> b_2, b_3, b_4, b_5, b_6,  */
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
    /* execute.simd:637 [F] s_b_2_0=sym_20311_3_parameter_inst.rn (const) */
    /* execute.simd:637 [D] s_b_2_1 = ReadRegBank 19:s_b_2_0 (v2u32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:639 [F] s_b_2_2 = constant s32 0 (const) */
    /* execute.simd:639 [D] s_b_2_1[s_b_2_2] */
    auto s_b_2_3 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:639 [D] s_b_2_4 = __builtin_bswap32 */
    auto s_b_2_4 = emitter.bswap(s_b_2_3);
    /* execute.simd:639 [F] s_b_2_5 = constant s32 0 (const) */
    /* execute.simd:639 [D] s_b_2_6 = s_b_2_1[s_b_2_5] <= s_b_2_4 */
    auto s_b_2_6 = emitter.vector_insert(s_b_2_1, emitter.const_s32((int32_t)0ULL), s_b_2_4);
    /* execute.simd:640 [F] s_b_2_7 = constant s32 1 (const) */
    /* execute.simd:640 [D] s_b_2_6[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_6, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:640 [D] s_b_2_9 = __builtin_bswap32 */
    auto s_b_2_9 = emitter.bswap(s_b_2_8);
    /* execute.simd:640 [F] s_b_2_10 = constant s32 1 (const) */
    /* execute.simd:640 [D] s_b_2_11 = s_b_2_6[s_b_2_10] <= s_b_2_9 */
    auto s_b_2_11 = emitter.vector_insert(s_b_2_6, emitter.const_s32((int32_t)1ULL), s_b_2_9);
    /* execute.simd:642 [F] s_b_2_12=sym_20311_3_parameter_inst.rd (const) */
    /* execute.simd:642 [D] s_b_2_13: WriteRegBank 19:s_b_2_12 = s_b_2_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_11,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_11);
    /* execute.simd:643 [F] s_b_2_14=sym_20311_3_parameter_inst.rd (const) */
    /* execute.simd:643 [F] s_b_2_15 = constant u64 0 (const) */
    /* execute.simd:643 [F] s_b_2_16: WriteRegBank 3:s_b_2_14 = s_b_2_15 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_17: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:647 [F] s_b_3_0=sym_20311_3_parameter_inst.rn (const) */
    /* execute.simd:647 [D] s_b_3_1 = ReadRegBank 20:s_b_3_0 (v4u32) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:649 [F] s_b_3_2 = constant s32 0 (const) */
    /* execute.simd:649 [D] s_b_3_1[s_b_3_2] */
    auto s_b_3_3 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:649 [D] s_b_3_4 = __builtin_bswap32 */
    auto s_b_3_4 = emitter.bswap(s_b_3_3);
    /* execute.simd:649 [F] s_b_3_5 = constant s32 0 (const) */
    /* execute.simd:649 [D] s_b_3_6 = s_b_3_1[s_b_3_5] <= s_b_3_4 */
    auto s_b_3_6 = emitter.vector_insert(s_b_3_1, emitter.const_s32((int32_t)0ULL), s_b_3_4);
    /* execute.simd:650 [F] s_b_3_7 = constant s32 1 (const) */
    /* execute.simd:650 [D] s_b_3_6[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_6, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:650 [D] s_b_3_9 = __builtin_bswap32 */
    auto s_b_3_9 = emitter.bswap(s_b_3_8);
    /* execute.simd:650 [F] s_b_3_10 = constant s32 1 (const) */
    /* execute.simd:650 [D] s_b_3_11 = s_b_3_6[s_b_3_10] <= s_b_3_9 */
    auto s_b_3_11 = emitter.vector_insert(s_b_3_6, emitter.const_s32((int32_t)1ULL), s_b_3_9);
    /* execute.simd:651 [F] s_b_3_12 = constant s32 2 (const) */
    /* execute.simd:651 [D] s_b_3_11[s_b_3_12] */
    auto s_b_3_13 = emitter.vector_extract(s_b_3_11, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:651 [D] s_b_3_14 = __builtin_bswap32 */
    auto s_b_3_14 = emitter.bswap(s_b_3_13);
    /* execute.simd:651 [F] s_b_3_15 = constant s32 2 (const) */
    /* execute.simd:651 [D] s_b_3_16 = s_b_3_11[s_b_3_15] <= s_b_3_14 */
    auto s_b_3_16 = emitter.vector_insert(s_b_3_11, emitter.const_s32((int32_t)2ULL), s_b_3_14);
    /* execute.simd:652 [F] s_b_3_17 = constant s32 3 (const) */
    /* execute.simd:652 [D] s_b_3_16[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_16, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:652 [D] s_b_3_19 = __builtin_bswap32 */
    auto s_b_3_19 = emitter.bswap(s_b_3_18);
    /* execute.simd:652 [F] s_b_3_20 = constant s32 3 (const) */
    /* execute.simd:652 [D] s_b_3_21 = s_b_3_16[s_b_3_20] <= s_b_3_19 */
    auto s_b_3_21 = emitter.vector_insert(s_b_3_16, emitter.const_s32((int32_t)3ULL), s_b_3_19);
    /* execute.simd:654 [F] s_b_3_22=sym_20311_3_parameter_inst.rd (const) */
    /* execute.simd:654 [D] s_b_3_23: WriteRegBank 20:s_b_3_22 = s_b_3_21 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_21,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_21);
    /* execute.simd:0 [F] s_b_3_24: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:658 [F] s_b_4_0=sym_20311_3_parameter_inst.rn (const) */
    /* execute.simd:658 [D] s_b_4_1 = ReadRegBank 19:s_b_4_0 (v2u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:660 [F] s_b_4_2 = constant s32 0 (const) */
    /* execute.simd:660 [D] s_b_4_1[s_b_4_2] */
    auto s_b_4_3 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:660 [F] s_b_4_4 = constant u32 10 (const) */
    /* execute.simd:660 [D] s_b_4_5 = s_b_4_3>>>s_b_4_4 */
    auto s_b_4_5 = emitter.ror(s_b_4_3, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:660 [F] s_b_4_6 = constant s32 0 (const) */
    /* execute.simd:660 [D] s_b_4_7 = s_b_4_1[s_b_4_6] <= s_b_4_5 */
    auto s_b_4_7 = emitter.vector_insert(s_b_4_1, emitter.const_s32((int32_t)0ULL), s_b_4_5);
    /* execute.simd:661 [F] s_b_4_8 = constant s32 1 (const) */
    /* execute.simd:661 [D] s_b_4_7[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_7, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:661 [F] s_b_4_10 = constant u32 10 (const) */
    /* execute.simd:661 [D] s_b_4_11 = s_b_4_9>>>s_b_4_10 */
    auto s_b_4_11 = emitter.ror(s_b_4_9, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:661 [F] s_b_4_12 = constant s32 1 (const) */
    /* execute.simd:661 [D] s_b_4_13 = s_b_4_7[s_b_4_12] <= s_b_4_11 */
    auto s_b_4_13 = emitter.vector_insert(s_b_4_7, emitter.const_s32((int32_t)1ULL), s_b_4_11);
    /* execute.simd:663 [F] s_b_4_14=sym_20311_3_parameter_inst.rd (const) */
    /* execute.simd:663 [D] s_b_4_15: WriteRegBank 19:s_b_4_14 = s_b_4_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_13);
    /* execute.simd:664 [F] s_b_4_16=sym_20311_3_parameter_inst.rd (const) */
    /* execute.simd:664 [F] s_b_4_17 = constant u64 0 (const) */
    /* execute.simd:664 [F] s_b_4_18: WriteRegBank 3:s_b_4_16 = s_b_4_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_19: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:668 [F] s_b_5_0=sym_20311_3_parameter_inst.rn (const) */
    /* execute.simd:668 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:670 [F] s_b_5_2 = constant s32 0 (const) */
    /* execute.simd:670 [D] s_b_5_1[s_b_5_2] */
    auto s_b_5_3 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:670 [F] s_b_5_4 = constant u32 10 (const) */
    /* execute.simd:670 [D] s_b_5_5 = s_b_5_3>>>s_b_5_4 */
    auto s_b_5_5 = emitter.ror(s_b_5_3, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:670 [F] s_b_5_6 = constant s32 0 (const) */
    /* execute.simd:670 [D] s_b_5_7 = s_b_5_1[s_b_5_6] <= s_b_5_5 */
    auto s_b_5_7 = emitter.vector_insert(s_b_5_1, emitter.const_s32((int32_t)0ULL), s_b_5_5);
    /* execute.simd:671 [F] s_b_5_8 = constant s32 1 (const) */
    /* execute.simd:671 [D] s_b_5_7[s_b_5_8] */
    auto s_b_5_9 = emitter.vector_extract(s_b_5_7, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:671 [F] s_b_5_10 = constant u32 10 (const) */
    /* execute.simd:671 [D] s_b_5_11 = s_b_5_9>>>s_b_5_10 */
    auto s_b_5_11 = emitter.ror(s_b_5_9, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:671 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:671 [D] s_b_5_13 = s_b_5_7[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(s_b_5_7, emitter.const_s32((int32_t)1ULL), s_b_5_11);
    /* execute.simd:672 [F] s_b_5_14 = constant s32 2 (const) */
    /* execute.simd:672 [D] s_b_5_13[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_13, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:672 [F] s_b_5_16 = constant u32 10 (const) */
    /* execute.simd:672 [D] s_b_5_17 = s_b_5_15>>>s_b_5_16 */
    auto s_b_5_17 = emitter.ror(s_b_5_15, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:672 [F] s_b_5_18 = constant s32 2 (const) */
    /* execute.simd:672 [D] s_b_5_19 = s_b_5_13[s_b_5_18] <= s_b_5_17 */
    auto s_b_5_19 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)2ULL), s_b_5_17);
    /* execute.simd:673 [F] s_b_5_20 = constant s32 3 (const) */
    /* execute.simd:673 [D] s_b_5_19[s_b_5_20] */
    auto s_b_5_21 = emitter.vector_extract(s_b_5_19, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:673 [F] s_b_5_22 = constant u32 10 (const) */
    /* execute.simd:673 [D] s_b_5_23 = s_b_5_21>>>s_b_5_22 */
    auto s_b_5_23 = emitter.ror(s_b_5_21, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:673 [F] s_b_5_24 = constant s32 3 (const) */
    /* execute.simd:673 [D] s_b_5_25 = s_b_5_19[s_b_5_24] <= s_b_5_23 */
    auto s_b_5_25 = emitter.vector_insert(s_b_5_19, emitter.const_s32((int32_t)3ULL), s_b_5_23);
    /* execute.simd:675 [F] s_b_5_26=sym_20311_3_parameter_inst.rd (const) */
    /* execute.simd:675 [D] s_b_5_27: WriteRegBank 20:s_b_5_26 = s_b_5_25 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_25,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_25);
    /* execute.simd:0 [F] s_b_5_28: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:679 [D] s_b_6_0 = trap */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_scvtf(const arm64_decode_a64_CVT_FP_I&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_131576_1_temporary_value;
  auto DV_sym_131576_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_131766_1_temporary_value;
  auto DV_sym_131766_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_131698_1_temporary_value;
  auto DV_sym_131698_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_131644_1_temporary_value;
  auto DV_sym_131644_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4315 [F] s_b_0_0=sym_22562_3_parameter_inst.sf (const) */
    /* execute.simd:4315 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4315 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4315 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4315 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4316 [F] s_b_1_0=sym_22562_3_parameter_inst.type (const) */
    /* execute.simd:4316 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4316 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4316 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4316 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_3, b_5, b_9, b_13, b_16, b_19, b_22,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4323 [F] s_b_3_0=sym_22562_3_parameter_inst.sf (const) */
    /* execute.simd:4323 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4323 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4323 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4323 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_2 (const) */
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
    /* execute.simd:4318 [F] s_b_4_0=sym_22562_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2709 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_4_4: If s_b_4_3: Jump b_11 else b_12 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4319 [F] s_b_5_0=sym_22562_3_parameter_inst.type (const) */
    /* execute.simd:4319 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4319 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4319 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4319 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
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
    /* execute.simd:4321 [F] s_b_6_0=sym_22562_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2709 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_6_4: If s_b_6_3: Jump b_14 else b_15 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4324 [F] s_b_7_0=sym_22562_3_parameter_inst.type (const) */
    /* execute.simd:4324 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4324 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4324 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4324 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4326 [F] s_b_8_0=sym_22562_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2714 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_8_4: If s_b_8_3: Jump b_17 else b_18 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4327 [F] s_b_9_0=sym_22562_3_parameter_inst.type (const) */
    /* execute.simd:4327 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4327 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4327 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4327 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_2 (const) */
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
    /* execute.simd:4329 [F] s_b_10_0=sym_22562_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2714 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_10_4: If s_b_10_3: Jump b_20 else b_21 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_4,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [F] s_b_11_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_11_1: sym_131576_1_temporary_value = s_b_11_0 (const), dominates: s_b_13_0  */
    CV_sym_131576_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_131576_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0=sym_22562_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_12_1 = ReadRegBank 1:s_b_12_0 (u32) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_12_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_12_2: sym_131576_1_temporary_value = s_b_12_1, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_131576_1_temporary_value, s_b_12_1);
    /* execute.a64:2709 [F] s_b_12_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_11, b_12,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [D] s_b_13_0 = sym_131576_1_temporary_value uint32_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_131576_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_13_1 = (u64)s_b_13_0 */
    auto s_b_13_1 = emitter.zx(s_b_13_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_13_2=sym_22562_3_parameter_inst.rd (const) */
    /* execute.simd:4318 [D] s_b_13_3 = (s32)s_b_13_1 */
    auto s_b_13_3 = emitter.truncate(s_b_13_1, emitter.context().types().s32());
    /* execute.simd:4318 [D] s_b_13_4 = (f32)s_b_13_3 */
    auto s_b_13_4 = emitter.convert(s_b_13_3, emitter.context().types().f32());
    /* execute.simd:6290 [D] s_b_13_5: WriteRegBank 9:s_b_13_2 = s_b_13_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_4);
    /* execute.simd:6291 [F] s_b_13_6 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_13_7: WriteRegBank 10:s_b_13_2 = s_b_13_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_13_8 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_13_9: WriteRegBank 3:s_b_13_2 = s_b_13_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_13_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_14_1: sym_131644_1_temporary_value = s_b_14_0 (const), dominates: s_b_16_0  */
    CV_sym_131644_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_131644_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_14_2: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2709 [F] s_b_15_0=sym_22562_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_15_1 = ReadRegBank 1:s_b_15_0 (u32) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_15_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_15_2: sym_131644_1_temporary_value = s_b_15_1, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_131644_1_temporary_value, s_b_15_1);
    /* execute.a64:2709 [F] s_b_15_3: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_14, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [D] s_b_16_0 = sym_131644_1_temporary_value uint32_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_131644_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_16_1 = (u64)s_b_16_0 */
    auto s_b_16_1 = emitter.zx(s_b_16_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_16_2=sym_22562_3_parameter_inst.rd (const) */
    /* execute.simd:4321 [D] s_b_16_3 = (s32)s_b_16_1 */
    auto s_b_16_3 = emitter.truncate(s_b_16_1, emitter.context().types().s32());
    /* execute.simd:4321 [D] s_b_16_4 = (f64)s_b_16_3 */
    auto s_b_16_4 = emitter.convert(s_b_16_3, emitter.context().types().f64());
    /* execute.simd:6298 [D] s_b_16_5: WriteRegBank 11:s_b_16_2 = s_b_16_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_4);
    /* execute.simd:6299 [F] s_b_16_6 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_16_7: WriteRegBank 3:s_b_16_2 = s_b_16_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_16_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2714 [F] s_b_17_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_17_1: sym_131698_1_temporary_value = s_b_17_0 (const), dominates: s_b_19_0  */
    CV_sym_131698_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_131698_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_17_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_8,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2714 [F] s_b_18_0=sym_22562_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_18_2: sym_131698_1_temporary_value = s_b_18_1, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_131698_1_temporary_value, s_b_18_1);
    /* execute.a64:2714 [F] s_b_18_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_17, b_18,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2714 [D] s_b_19_0 = sym_131698_1_temporary_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_131698_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1=sym_22562_3_parameter_inst.rd (const) */
    /* execute.simd:4326 [D] s_b_19_2 = (s64)s_b_19_0 */
    auto s_b_19_2 = emitter.reinterpret(s_b_19_0, emitter.context().types().s64());
    /* execute.simd:4326 [D] s_b_19_3 = (f32)s_b_19_2 */
    auto s_b_19_3 = emitter.convert(s_b_19_2, emitter.context().types().f32());
    /* execute.simd:6290 [D] s_b_19_4: WriteRegBank 9:s_b_19_1 = s_b_19_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_19_3,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_19_3);
    /* execute.simd:6291 [F] s_b_19_5 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_19_6: WriteRegBank 10:s_b_19_1 = s_b_19_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_19_7 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_19_8: WriteRegBank 3:s_b_19_1 = s_b_19_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_19_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_10,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2714 [F] s_b_20_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_20_1: sym_131766_1_temporary_value = s_b_20_0 (const), dominates: s_b_22_0  */
    CV_sym_131766_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_131766_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_10,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2714 [F] s_b_21_0=sym_22562_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_21_2: sym_131766_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_131766_1_temporary_value, s_b_21_1);
    /* execute.a64:2714 [F] s_b_21_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2714 [D] s_b_22_0 = sym_131766_1_temporary_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_131766_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_22_1=sym_22562_3_parameter_inst.rd (const) */
    /* execute.simd:4329 [D] s_b_22_2 = (s64)s_b_22_0 */
    auto s_b_22_2 = emitter.reinterpret(s_b_22_0, emitter.context().types().s64());
    /* execute.simd:4329 [D] s_b_22_3 = (f64)s_b_22_2 */
    auto s_b_22_3 = emitter.convert(s_b_22_2, emitter.context().types().f64());
    /* execute.simd:6298 [D] s_b_22_4: WriteRegBank 11:s_b_22_1 = s_b_22_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_3);
    /* execute.simd:6299 [F] s_b_22_5 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_22_6: WriteRegBank 3:s_b_22_1 = s_b_22_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_22_7: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_smin(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2978 [F] s_b_0_0=sym_23991_3_parameter_inst.arrangement (const) */
    /* execute.simd:2979 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:2991 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:3001 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:3012 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:3022 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:3033 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:2978 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:2980 [F] s_b_2_0=sym_23991_3_parameter_inst.rn (const) */
    /* execute.simd:2980 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:2980 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:2981 [F] s_b_2_3=sym_23991_3_parameter_inst.rm (const) */
    /* execute.simd:2981 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:2981 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* execute.simd:2983 [D] s_b_2_6 = s_b_2_2>s_b_2_5 */
    auto s_b_2_6 = emitter.cmp_gt(s_b_2_2, s_b_2_5);
    /* execute.simd:2984 [D] s_b_2_7 = ~s_b_2_6 */
    auto s_b_2_7 = emitter.bitwise_not(s_b_2_6);
    /* execute.simd:2984 [D] s_b_2_8 = s_b_2_2&s_b_2_7 */
    auto s_b_2_8 = emitter.bitwise_and(s_b_2_2, s_b_2_7);
    /* execute.simd:2984 [D] s_b_2_9 = s_b_2_5&s_b_2_6 */
    auto s_b_2_9 = emitter.bitwise_and(s_b_2_5, s_b_2_6);
    /* execute.simd:2984 [D] s_b_2_10 = s_b_2_8|s_b_2_9 */
    auto s_b_2_10 = emitter.bitwise_or(s_b_2_8, s_b_2_9);
    /* execute.simd:2986 [F] s_b_2_11=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:2986 [D] s_b_2_12 = (v8u8)s_b_2_10 */
    auto s_b_2_12 = emitter.reinterpret(s_b_2_10, emitter.context().types().v8u8());
    /* execute.simd:2986 [D] s_b_2_13: WriteRegBank 15:s_b_2_11 = s_b_2_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_12);
    /* execute.simd:2987 [F] s_b_2_14=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:2987 [F] s_b_2_15 = constant u64 0 (const) */
    /* execute.simd:2987 [F] s_b_2_16: WriteRegBank 3:s_b_2_14 = s_b_2_15 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_17: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2992 [F] s_b_3_0=sym_23991_3_parameter_inst.rn (const) */
    /* execute.simd:2992 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:2992 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:2993 [F] s_b_3_3=sym_23991_3_parameter_inst.rm (const) */
    /* execute.simd:2993 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:2993 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* execute.simd:2995 [D] s_b_3_6 = s_b_3_2>s_b_3_5 */
    auto s_b_3_6 = emitter.cmp_gt(s_b_3_2, s_b_3_5);
    /* execute.simd:2996 [D] s_b_3_7 = ~s_b_3_6 */
    auto s_b_3_7 = emitter.bitwise_not(s_b_3_6);
    /* execute.simd:2996 [D] s_b_3_8 = s_b_3_2&s_b_3_7 */
    auto s_b_3_8 = emitter.bitwise_and(s_b_3_2, s_b_3_7);
    /* execute.simd:2996 [D] s_b_3_9 = s_b_3_5&s_b_3_6 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_5, s_b_3_6);
    /* execute.simd:2996 [D] s_b_3_10 = s_b_3_8|s_b_3_9 */
    auto s_b_3_10 = emitter.bitwise_or(s_b_3_8, s_b_3_9);
    /* execute.simd:2998 [F] s_b_3_11=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:2998 [D] s_b_3_12 = (v16u8)s_b_3_10 */
    auto s_b_3_12 = emitter.reinterpret(s_b_3_10, emitter.context().types().v16u8());
    /* execute.simd:2998 [D] s_b_3_13: WriteRegBank 16:s_b_3_11 = s_b_3_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_12);
    /* execute.simd:0 [F] s_b_3_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:3002 [F] s_b_4_0=sym_23991_3_parameter_inst.rn (const) */
    /* execute.simd:3002 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:3002 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:3003 [F] s_b_4_3=sym_23991_3_parameter_inst.rm (const) */
    /* execute.simd:3003 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:3003 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* execute.simd:3005 [D] s_b_4_6 = s_b_4_2>s_b_4_5 */
    auto s_b_4_6 = emitter.cmp_gt(s_b_4_2, s_b_4_5);
    /* execute.simd:3006 [D] s_b_4_7 = ~s_b_4_6 */
    auto s_b_4_7 = emitter.bitwise_not(s_b_4_6);
    /* execute.simd:3006 [D] s_b_4_8 = s_b_4_2&s_b_4_7 */
    auto s_b_4_8 = emitter.bitwise_and(s_b_4_2, s_b_4_7);
    /* execute.simd:3006 [D] s_b_4_9 = s_b_4_5&s_b_4_6 */
    auto s_b_4_9 = emitter.bitwise_and(s_b_4_5, s_b_4_6);
    /* execute.simd:3006 [D] s_b_4_10 = s_b_4_8|s_b_4_9 */
    auto s_b_4_10 = emitter.bitwise_or(s_b_4_8, s_b_4_9);
    /* execute.simd:3008 [F] s_b_4_11=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:3008 [D] s_b_4_12 = (v4u16)s_b_4_10 */
    auto s_b_4_12 = emitter.reinterpret(s_b_4_10, emitter.context().types().v4u16());
    /* execute.simd:3008 [D] s_b_4_13: WriteRegBank 17:s_b_4_11 = s_b_4_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_12);
    /* execute.simd:3009 [F] s_b_4_14=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:3009 [F] s_b_4_15 = constant u64 0 (const) */
    /* execute.simd:3009 [F] s_b_4_16: WriteRegBank 3:s_b_4_14 = s_b_4_15 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_17: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:3013 [F] s_b_5_0=sym_23991_3_parameter_inst.rn (const) */
    /* execute.simd:3013 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:3013 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:3014 [F] s_b_5_3=sym_23991_3_parameter_inst.rm (const) */
    /* execute.simd:3014 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:3014 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* execute.simd:3016 [D] s_b_5_6 = s_b_5_2>s_b_5_5 */
    auto s_b_5_6 = emitter.cmp_gt(s_b_5_2, s_b_5_5);
    /* execute.simd:3017 [D] s_b_5_7 = ~s_b_5_6 */
    auto s_b_5_7 = emitter.bitwise_not(s_b_5_6);
    /* execute.simd:3017 [D] s_b_5_8 = s_b_5_2&s_b_5_7 */
    auto s_b_5_8 = emitter.bitwise_and(s_b_5_2, s_b_5_7);
    /* execute.simd:3017 [D] s_b_5_9 = s_b_5_5&s_b_5_6 */
    auto s_b_5_9 = emitter.bitwise_and(s_b_5_5, s_b_5_6);
    /* execute.simd:3017 [D] s_b_5_10 = s_b_5_8|s_b_5_9 */
    auto s_b_5_10 = emitter.bitwise_or(s_b_5_8, s_b_5_9);
    /* execute.simd:3019 [F] s_b_5_11=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:3019 [D] s_b_5_12 = (v8u16)s_b_5_10 */
    auto s_b_5_12 = emitter.reinterpret(s_b_5_10, emitter.context().types().v8u16());
    /* execute.simd:3019 [D] s_b_5_13: WriteRegBank 18:s_b_5_11 = s_b_5_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_12);
    /* execute.simd:0 [F] s_b_5_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:3023 [F] s_b_6_0=sym_23991_3_parameter_inst.rn (const) */
    /* execute.simd:3023 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:3023 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:3024 [F] s_b_6_3=sym_23991_3_parameter_inst.rm (const) */
    /* execute.simd:3024 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:3024 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* execute.simd:3026 [D] s_b_6_6 = s_b_6_2>s_b_6_5 */
    auto s_b_6_6 = emitter.cmp_gt(s_b_6_2, s_b_6_5);
    /* execute.simd:3027 [D] s_b_6_7 = ~s_b_6_6 */
    auto s_b_6_7 = emitter.bitwise_not(s_b_6_6);
    /* execute.simd:3027 [D] s_b_6_8 = s_b_6_2&s_b_6_7 */
    auto s_b_6_8 = emitter.bitwise_and(s_b_6_2, s_b_6_7);
    /* execute.simd:3027 [D] s_b_6_9 = s_b_6_5&s_b_6_6 */
    auto s_b_6_9 = emitter.bitwise_and(s_b_6_5, s_b_6_6);
    /* execute.simd:3027 [D] s_b_6_10 = s_b_6_8|s_b_6_9 */
    auto s_b_6_10 = emitter.bitwise_or(s_b_6_8, s_b_6_9);
    /* execute.simd:3029 [F] s_b_6_11=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:3029 [D] s_b_6_12 = (v2u32)s_b_6_10 */
    auto s_b_6_12 = emitter.reinterpret(s_b_6_10, emitter.context().types().v2u32());
    /* execute.simd:3029 [D] s_b_6_13: WriteRegBank 19:s_b_6_11 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12);
    /* execute.simd:3030 [F] s_b_6_14=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:3030 [F] s_b_6_15 = constant u64 0 (const) */
    /* execute.simd:3030 [F] s_b_6_16: WriteRegBank 3:s_b_6_14 = s_b_6_15 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_17: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:3034 [F] s_b_7_0=sym_23991_3_parameter_inst.rn (const) */
    /* execute.simd:3034 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:3034 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:3035 [F] s_b_7_3=sym_23991_3_parameter_inst.rm (const) */
    /* execute.simd:3035 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:3035 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* execute.simd:3037 [D] s_b_7_6 = s_b_7_2>s_b_7_5 */
    auto s_b_7_6 = emitter.cmp_gt(s_b_7_2, s_b_7_5);
    /* execute.simd:3038 [D] s_b_7_7 = ~s_b_7_6 */
    auto s_b_7_7 = emitter.bitwise_not(s_b_7_6);
    /* execute.simd:3038 [D] s_b_7_8 = s_b_7_2&s_b_7_7 */
    auto s_b_7_8 = emitter.bitwise_and(s_b_7_2, s_b_7_7);
    /* execute.simd:3038 [D] s_b_7_9 = s_b_7_5&s_b_7_6 */
    auto s_b_7_9 = emitter.bitwise_and(s_b_7_5, s_b_7_6);
    /* execute.simd:3038 [D] s_b_7_10 = s_b_7_8|s_b_7_9 */
    auto s_b_7_10 = emitter.bitwise_or(s_b_7_8, s_b_7_9);
    /* execute.simd:3040 [F] s_b_7_11=sym_23991_3_parameter_inst.rd (const) */
    /* execute.simd:3040 [D] s_b_7_12 = (v4u32)s_b_7_10 */
    auto s_b_7_12 = emitter.reinterpret(s_b_7_10, emitter.context().types().v4u32());
    /* execute.simd:3040 [D] s_b_7_13: WriteRegBank 20:s_b_7_11 = s_b_7_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_12);
    /* execute.simd:0 [F] s_b_7_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:3044 [D] s_b_8_0 = trap */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sshr(const arm64_decode_a64_SIMD_SHIFT_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4887 [F] s_b_0_0=sym_28778_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4887 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4888 [F] s_b_1_0=sym_28778_3_parameter_inst.immh (const) */
    /* execute.simd:4888 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4888 [F] s_b_1_2 = constant u32 3 (const) */
    /* execute.simd:4888 [F] s_b_1_3 = s_b_1_1<<s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4888 [F] s_b_1_4=sym_28778_3_parameter_inst.immb (const) */
    /* execute.simd:4888 [F] s_b_1_5 = (u32)s_b_1_4 (const) */
    /* execute.simd:4888 [F] s_b_1_6 = s_b_1_3|s_b_1_5 (const) */
    uint32_t s_b_1_6 = ((uint32_t)(s_b_1_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4888 [F] s_b_1_7 = constant u32 80 (const) */
    /* execute.simd:4888 [F] s_b_1_8 = s_b_1_7-s_b_1_6 (const) */
    uint32_t s_b_1_8 = ((uint32_t)((uint32_t)128ULL - s_b_1_6));
    /* execute.simd:4888 [F] s_b_1_9 = (u64)s_b_1_8 (const) */
    /* execute.simd:4889 [F] s_b_1_10=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4889 [F] s_b_1_11=sym_28778_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_12 = ReadRegBank 7:s_b_1_11 (u64) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_12,emitter.const_u8(8));
    }
    /* execute.simd:4889 [D] s_b_1_13 = (s64)s_b_1_12 */
    auto s_b_1_13 = emitter.reinterpret(s_b_1_12, emitter.context().types().s64());
    /* execute.simd:4889 [D] s_b_1_14 = (u64)s_b_1_13 */
    auto s_b_1_14 = emitter.reinterpret(s_b_1_13, emitter.context().types().u64());
    /* execute.simd:4889 [D] s_b_1_15 = s_b_1_14->>s_b_1_9 */
    auto s_b_1_15 = emitter.sar(s_b_1_14, emitter.const_u64(((uint64_t)s_b_1_8)));
    /* execute.simd:4889 [D] s_b_1_16 = (u64)s_b_1_15 */
    auto s_b_1_16 = (captive::arch::dbt::el::Value *)s_b_1_15;
    /* execute.simd:6326 [D] s_b_1_17: WriteRegBank 2:s_b_1_10 = s_b_1_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_16);
    /* execute.simd:6327 [F] s_b_1_18 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_19: WriteRegBank 3:s_b_1_10 = s_b_1_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_20: Jump b_2 (const) */
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
    /* execute.simd:4891 [F] s_b_3_0=sym_28778_3_parameter_inst.arrangement (const) */
    /* execute.simd:4892 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:4900 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:4907 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:4915 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:4922 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:4930 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:4937 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:4891 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
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
    /* execute.simd:4893 [F] s_b_4_0=sym_28778_3_parameter_inst.immh (const) */
    /* execute.simd:4893 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4893 [F] s_b_4_2 = constant u32 3 (const) */
    /* execute.simd:4893 [F] s_b_4_3 = s_b_4_1<<s_b_4_2 (const) */
    uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4893 [F] s_b_4_4=sym_28778_3_parameter_inst.immb (const) */
    /* execute.simd:4893 [F] s_b_4_5 = (u32)s_b_4_4 (const) */
    /* execute.simd:4893 [F] s_b_4_6 = s_b_4_3|s_b_4_5 (const) */
    uint32_t s_b_4_6 = ((uint32_t)(s_b_4_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4893 [F] s_b_4_7 = constant u32 10 (const) */
    /* execute.simd:4893 [F] s_b_4_8 = s_b_4_7-s_b_4_6 (const) */
    uint32_t s_b_4_8 = ((uint32_t)((uint32_t)16ULL - s_b_4_6));
    /* execute.simd:4893 [F] s_b_4_9 = (u64)s_b_4_8 (const) */
    /* execute.simd:4895 [F] s_b_4_10=sym_28778_3_parameter_inst.rn (const) */
    /* execute.simd:4895 [D] s_b_4_11 = ReadRegBank 15:s_b_4_10 (v8u8) */
    auto s_b_4_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_11,emitter.const_u8(8));
    }
    /* execute.simd:4896 [F] s_b_4_12=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4896 [D] s_b_4_13 = (v8s8)s_b_4_11 */
    auto s_b_4_13 = emitter.reinterpret(s_b_4_11, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_4_14 = (v8s8)s_b_4_9 (const) */
    auto s_b_4_14 = wutils::Vector<int8_t, 8>(((uint64_t)s_b_4_8));
    /* execute.simd:4896 [D] s_b_4_15 = s_b_4_13->>s_b_4_14 */
    auto s_b_4_15 = emitter.sar(s_b_4_13, emitter.constant_vector_splat(s_b_4_14[0], emitter.context().types().v8s8()));
    /* execute.simd:4896 [D] s_b_4_16 = (v8u8)s_b_4_15 */
    auto s_b_4_16 = emitter.reinterpret(s_b_4_15, emitter.context().types().v8u8());
    /* execute.simd:4896 [D] s_b_4_17: WriteRegBank 15:s_b_4_12 = s_b_4_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_16);
    /* execute.simd:4897 [F] s_b_4_18=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4897 [F] s_b_4_19 = constant u64 0 (const) */
    /* execute.simd:4897 [F] s_b_4_20: WriteRegBank 3:s_b_4_18 = s_b_4_19 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_21: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4901 [F] s_b_5_0=sym_28778_3_parameter_inst.immh (const) */
    /* execute.simd:4901 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4901 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.simd:4901 [F] s_b_5_3 = s_b_5_1<<s_b_5_2 (const) */
    uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4901 [F] s_b_5_4=sym_28778_3_parameter_inst.immb (const) */
    /* execute.simd:4901 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4901 [F] s_b_5_6 = s_b_5_3|s_b_5_5 (const) */
    uint32_t s_b_5_6 = ((uint32_t)(s_b_5_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4901 [F] s_b_5_7 = constant u32 10 (const) */
    /* execute.simd:4901 [F] s_b_5_8 = s_b_5_7-s_b_5_6 (const) */
    uint32_t s_b_5_8 = ((uint32_t)((uint32_t)16ULL - s_b_5_6));
    /* execute.simd:4901 [F] s_b_5_9 = (u64)s_b_5_8 (const) */
    /* execute.simd:4903 [F] s_b_5_10=sym_28778_3_parameter_inst.rn (const) */
    /* execute.simd:4903 [D] s_b_5_11 = ReadRegBank 16:s_b_5_10 (v16u8) */
    auto s_b_5_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_11,emitter.const_u8(16));
    }
    /* execute.simd:4904 [F] s_b_5_12=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4904 [D] s_b_5_13 = (v16s8)s_b_5_11 */
    auto s_b_5_13 = emitter.reinterpret(s_b_5_11, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_5_14 = (v16s8)s_b_5_9 (const) */
    auto s_b_5_14 = wutils::Vector<int8_t, 16>(((uint64_t)s_b_5_8));
    /* execute.simd:4904 [D] s_b_5_15 = s_b_5_13->>s_b_5_14 */
    auto s_b_5_15 = emitter.sar(s_b_5_13, emitter.constant_vector_splat(s_b_5_14[0], emitter.context().types().v16s8()));
    /* execute.simd:4904 [D] s_b_5_16 = (v16u8)s_b_5_15 */
    auto s_b_5_16 = emitter.reinterpret(s_b_5_15, emitter.context().types().v16u8());
    /* execute.simd:4904 [D] s_b_5_17: WriteRegBank 16:s_b_5_12 = s_b_5_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_16,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_16);
    /* execute.simd:0 [F] s_b_5_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4908 [F] s_b_6_0=sym_28778_3_parameter_inst.immh (const) */
    /* execute.simd:4908 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.simd:4908 [F] s_b_6_2 = constant u32 3 (const) */
    /* execute.simd:4908 [F] s_b_6_3 = s_b_6_1<<s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4908 [F] s_b_6_4=sym_28778_3_parameter_inst.immb (const) */
    /* execute.simd:4908 [F] s_b_6_5 = (u32)s_b_6_4 (const) */
    /* execute.simd:4908 [F] s_b_6_6 = s_b_6_3|s_b_6_5 (const) */
    uint32_t s_b_6_6 = ((uint32_t)(s_b_6_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4908 [F] s_b_6_7 = constant u32 20 (const) */
    /* execute.simd:4908 [F] s_b_6_8 = s_b_6_7-s_b_6_6 (const) */
    uint32_t s_b_6_8 = ((uint32_t)((uint32_t)32ULL - s_b_6_6));
    /* execute.simd:4908 [F] s_b_6_9 = (u64)s_b_6_8 (const) */
    /* execute.simd:4910 [F] s_b_6_10=sym_28778_3_parameter_inst.rn (const) */
    /* execute.simd:4910 [D] s_b_6_11 = ReadRegBank 17:s_b_6_10 (v4u16) */
    auto s_b_6_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_11,emitter.const_u8(8));
    }
    /* execute.simd:4911 [F] s_b_6_12=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4911 [D] s_b_6_13 = (v4s16)s_b_6_11 */
    auto s_b_6_13 = emitter.reinterpret(s_b_6_11, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_6_14 = (v4s16)s_b_6_9 (const) */
    auto s_b_6_14 = wutils::Vector<int16_t, 4>(((uint64_t)s_b_6_8));
    /* execute.simd:4911 [D] s_b_6_15 = s_b_6_13->>s_b_6_14 */
    auto s_b_6_15 = emitter.sar(s_b_6_13, emitter.constant_vector_splat(s_b_6_14[0], emitter.context().types().v4s16()));
    /* execute.simd:4911 [D] s_b_6_16 = (v4u16)s_b_6_15 */
    auto s_b_6_16 = emitter.reinterpret(s_b_6_15, emitter.context().types().v4u16());
    /* execute.simd:4911 [D] s_b_6_17: WriteRegBank 17:s_b_6_12 = s_b_6_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_16);
    /* execute.simd:4912 [F] s_b_6_18=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4912 [F] s_b_6_19 = constant u64 0 (const) */
    /* execute.simd:4912 [F] s_b_6_20: WriteRegBank 3:s_b_6_18 = s_b_6_19 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_21: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4916 [F] s_b_7_0=sym_28778_3_parameter_inst.immh (const) */
    /* execute.simd:4916 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4916 [F] s_b_7_2 = constant u32 3 (const) */
    /* execute.simd:4916 [F] s_b_7_3 = s_b_7_1<<s_b_7_2 (const) */
    uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4916 [F] s_b_7_4=sym_28778_3_parameter_inst.immb (const) */
    /* execute.simd:4916 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4916 [F] s_b_7_6 = s_b_7_3|s_b_7_5 (const) */
    uint32_t s_b_7_6 = ((uint32_t)(s_b_7_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4916 [F] s_b_7_7 = constant u32 20 (const) */
    /* execute.simd:4916 [F] s_b_7_8 = s_b_7_7-s_b_7_6 (const) */
    uint32_t s_b_7_8 = ((uint32_t)((uint32_t)32ULL - s_b_7_6));
    /* execute.simd:4916 [F] s_b_7_9 = (u64)s_b_7_8 (const) */
    /* execute.simd:4918 [F] s_b_7_10=sym_28778_3_parameter_inst.rn (const) */
    /* execute.simd:4918 [D] s_b_7_11 = ReadRegBank 18:s_b_7_10 (v8u16) */
    auto s_b_7_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_11,emitter.const_u8(16));
    }
    /* execute.simd:4919 [F] s_b_7_12=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4919 [D] s_b_7_13 = (v8s16)s_b_7_11 */
    auto s_b_7_13 = emitter.reinterpret(s_b_7_11, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_7_14 = (v8s16)s_b_7_9 (const) */
    auto s_b_7_14 = wutils::Vector<int16_t, 8>(((uint64_t)s_b_7_8));
    /* execute.simd:4919 [D] s_b_7_15 = s_b_7_13->>s_b_7_14 */
    auto s_b_7_15 = emitter.sar(s_b_7_13, emitter.constant_vector_splat(s_b_7_14[0], emitter.context().types().v8s16()));
    /* execute.simd:4919 [D] s_b_7_16 = (v8u16)s_b_7_15 */
    auto s_b_7_16 = emitter.reinterpret(s_b_7_15, emitter.context().types().v8u16());
    /* execute.simd:4919 [D] s_b_7_17: WriteRegBank 18:s_b_7_12 = s_b_7_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_16,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_16);
    /* execute.simd:0 [F] s_b_7_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4923 [F] s_b_8_0=sym_28778_3_parameter_inst.immh (const) */
    /* execute.simd:4923 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.simd:4923 [F] s_b_8_2 = constant u32 3 (const) */
    /* execute.simd:4923 [F] s_b_8_3 = s_b_8_1<<s_b_8_2 (const) */
    uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4923 [F] s_b_8_4=sym_28778_3_parameter_inst.immb (const) */
    /* execute.simd:4923 [F] s_b_8_5 = (u32)s_b_8_4 (const) */
    /* execute.simd:4923 [F] s_b_8_6 = s_b_8_3|s_b_8_5 (const) */
    uint32_t s_b_8_6 = ((uint32_t)(s_b_8_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4923 [F] s_b_8_7 = constant u32 40 (const) */
    /* execute.simd:4923 [F] s_b_8_8 = s_b_8_7-s_b_8_6 (const) */
    uint32_t s_b_8_8 = ((uint32_t)((uint32_t)64ULL - s_b_8_6));
    /* execute.simd:4923 [F] s_b_8_9 = (u64)s_b_8_8 (const) */
    /* execute.simd:4925 [F] s_b_8_10=sym_28778_3_parameter_inst.rn (const) */
    /* execute.simd:4925 [D] s_b_8_11 = ReadRegBank 19:s_b_8_10 (v2u32) */
    auto s_b_8_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_11,emitter.const_u8(8));
    }
    /* execute.simd:4926 [F] s_b_8_12=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4926 [D] s_b_8_13 = (v2s32)s_b_8_11 */
    auto s_b_8_13 = emitter.reinterpret(s_b_8_11, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_8_14 = (v2s32)s_b_8_9 (const) */
    auto s_b_8_14 = wutils::Vector<int32_t, 2>(((uint64_t)s_b_8_8));
    /* execute.simd:4926 [D] s_b_8_15 = s_b_8_13->>s_b_8_14 */
    auto s_b_8_15 = emitter.sar(s_b_8_13, emitter.constant_vector_splat(s_b_8_14[0], emitter.context().types().v2s32()));
    /* execute.simd:4926 [D] s_b_8_16 = (v2u32)s_b_8_15 */
    auto s_b_8_16 = emitter.reinterpret(s_b_8_15, emitter.context().types().v2u32());
    /* execute.simd:4926 [D] s_b_8_17: WriteRegBank 19:s_b_8_12 = s_b_8_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_16);
    /* execute.simd:4927 [F] s_b_8_18=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4927 [F] s_b_8_19 = constant u64 0 (const) */
    /* execute.simd:4927 [F] s_b_8_20: WriteRegBank 3:s_b_8_18 = s_b_8_19 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_21: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4931 [F] s_b_9_0=sym_28778_3_parameter_inst.immh (const) */
    /* execute.simd:4931 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4931 [F] s_b_9_2 = constant u32 3 (const) */
    /* execute.simd:4931 [F] s_b_9_3 = s_b_9_1<<s_b_9_2 (const) */
    uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4931 [F] s_b_9_4=sym_28778_3_parameter_inst.immb (const) */
    /* execute.simd:4931 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4931 [F] s_b_9_6 = s_b_9_3|s_b_9_5 (const) */
    uint32_t s_b_9_6 = ((uint32_t)(s_b_9_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4931 [F] s_b_9_7 = constant u32 40 (const) */
    /* execute.simd:4931 [F] s_b_9_8 = s_b_9_7-s_b_9_6 (const) */
    uint32_t s_b_9_8 = ((uint32_t)((uint32_t)64ULL - s_b_9_6));
    /* execute.simd:4931 [F] s_b_9_9 = (u64)s_b_9_8 (const) */
    /* execute.simd:4933 [F] s_b_9_10=sym_28778_3_parameter_inst.rn (const) */
    /* execute.simd:4933 [D] s_b_9_11 = ReadRegBank 20:s_b_9_10 (v4u32) */
    auto s_b_9_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_11,emitter.const_u8(16));
    }
    /* execute.simd:4934 [F] s_b_9_12=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4934 [D] s_b_9_13 = (v4s32)s_b_9_11 */
    auto s_b_9_13 = emitter.reinterpret(s_b_9_11, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_9_14 = (v4s32)s_b_9_9 (const) */
    auto s_b_9_14 = wutils::Vector<int32_t, 4>(((uint64_t)s_b_9_8));
    /* execute.simd:4934 [D] s_b_9_15 = s_b_9_13->>s_b_9_14 */
    auto s_b_9_15 = emitter.sar(s_b_9_13, emitter.constant_vector_splat(s_b_9_14[0], emitter.context().types().v4s32()));
    /* execute.simd:4934 [D] s_b_9_16 = (v4u32)s_b_9_15 */
    auto s_b_9_16 = emitter.reinterpret(s_b_9_15, emitter.context().types().v4u32());
    /* execute.simd:4934 [D] s_b_9_17: WriteRegBank 20:s_b_9_12 = s_b_9_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_16,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_16);
    /* execute.simd:0 [F] s_b_9_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4938 [F] s_b_10_0=sym_28778_3_parameter_inst.immh (const) */
    /* execute.simd:4938 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4938 [F] s_b_10_2 = constant u32 3 (const) */
    /* execute.simd:4938 [F] s_b_10_3 = s_b_10_1<<s_b_10_2 (const) */
    uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4938 [F] s_b_10_4=sym_28778_3_parameter_inst.immb (const) */
    /* execute.simd:4938 [F] s_b_10_5 = (u32)s_b_10_4 (const) */
    /* execute.simd:4938 [F] s_b_10_6 = s_b_10_3|s_b_10_5 (const) */
    uint32_t s_b_10_6 = ((uint32_t)(s_b_10_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4938 [F] s_b_10_7 = constant u32 80 (const) */
    /* execute.simd:4938 [F] s_b_10_8 = s_b_10_7-s_b_10_6 (const) */
    uint32_t s_b_10_8 = ((uint32_t)((uint32_t)128ULL - s_b_10_6));
    /* execute.simd:4938 [F] s_b_10_9 = (u64)s_b_10_8 (const) */
    /* execute.simd:4940 [F] s_b_10_10=sym_28778_3_parameter_inst.rn (const) */
    /* execute.simd:4940 [D] s_b_10_11 = ReadRegBank 21:s_b_10_10 (v2u64) */
    auto s_b_10_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_11,emitter.const_u8(16));
    }
    /* execute.simd:4941 [F] s_b_10_12=sym_28778_3_parameter_inst.rd (const) */
    /* execute.simd:4941 [D] s_b_10_13 = (v2s64)s_b_10_11 */
    auto s_b_10_13 = emitter.reinterpret(s_b_10_11, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_10_14 = (v2s64)s_b_10_9 (const) */
    auto s_b_10_14 = wutils::Vector<int64_t, 2>(((uint64_t)s_b_10_8));
    /* execute.simd:4941 [D] s_b_10_15 = s_b_10_13->>s_b_10_14 */
    auto s_b_10_15 = emitter.sar(s_b_10_13, emitter.constant_vector_splat(s_b_10_14[0], emitter.context().types().v2s64()));
    /* execute.simd:4941 [D] s_b_10_16 = (v2u64)s_b_10_15 */
    auto s_b_10_16 = emitter.reinterpret(s_b_10_15, emitter.context().types().v2u64());
    /* execute.simd:4941 [D] s_b_10_17: WriteRegBank 21:s_b_10_12 = s_b_10_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_16,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_16);
    /* execute.simd:0 [F] s_b_10_18: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_st2pi(const arm64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_136368_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_136248_1_tmp_s_b_5_2;
  auto DV_sym_136251_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_136290_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_136400_1_temporary_value;
  auto DV_sym_136400_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_136427_1_tmp_s_b_57_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_136166_3_parameter_rt;
  auto DV_sym_136171_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_136174_3_parameter_lane;
  auto DV_sym_136439_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_136057_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30936_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30942_0_lane;
  uint8_t CV_sym_30954_0_rt;
  auto DV_sym_136273_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_136074_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2677 [F] s_b_0_0=sym_30930_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_9 else b_10 (const) */
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
    /* execute.simd:2679 [F] s_b_1_0 = sym_30942_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30942_0_lane;
    /* execute.simd:2679 [F] s_b_1_1=sym_30930_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2679 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2679 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2680 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2680 [F] s_b_2_1: sym_30954_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30954_0_rt = (uint8_t)0ULL;
    /* execute.simd:2680 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2686 [F] s_b_3_0=sym_30930_3_parameter_inst.rm (const) */
    /* execute.simd:2686 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2686 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2686 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2686 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2680 [F] s_b_4_0 = sym_30954_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30954_0_rt;
    /* execute.simd:2680 [F] s_b_4_1=sym_30930_3_parameter_inst.regcnt (const) */
    /* execute.simd:2680 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2680 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2681 [F] s_b_5_0=sym_30930_3_parameter_inst.arrangement (const) */
    /* execute.simd:2681 [F] s_b_5_1=sym_30930_3_parameter_inst.rt (const) */
    /* execute.simd:2681 [F] s_b_5_2 = sym_30954_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30954_0_rt;
    /* execute.simd:2681 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2681 [F] s_b_5_4 = sym_30942_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30942_0_lane;
    /* execute.simd:2681 [D] s_b_5_5 = sym_30936_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30936_0_address, emitter.context().types().u64());
    /* execute.simd:2681 [F] s_b_5_6: sym_136166_3_parameter_rt = s_b_5_3 (const), dominates: s_b_18_0 s_b_19_0 s_b_20_0 s_b_21_0 s_b_22_0 s_b_23_0 s_b_24_0  */
    CV_sym_136166_3_parameter_rt = s_b_5_3;
    /* execute.simd:2681 [F] s_b_5_7: sym_136174_3_parameter_lane = s_b_5_4 (const), dominates: s_b_18_3 s_b_19_3 s_b_20_3 s_b_21_3 s_b_22_3 s_b_23_3 s_b_24_3  */
    CV_sym_136174_3_parameter_lane = s_b_5_4;
    /* execute.simd:2681 [D] s_b_5_8: sym_136171_3_parameter_addr = s_b_5_5, dominates: s_b_18_2 s_b_19_2 s_b_20_2 s_b_21_2 s_b_22_2 s_b_23_2 s_b_24_2  */
    emitter.store_local(DV_sym_136171_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_136248_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_25_1  */
    CV_sym_136248_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_136251_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_136251_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3931 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3936 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3941 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3946 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3951 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3956 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3961 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3930 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_17 (const) -> b_17, b_18, b_19, b_20, b_21, b_22, b_23, b_24,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_24;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
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
    default:
      goto fixed_block_b_17;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2679 [F] s_b_6_0 = sym_30942_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30942_0_lane;
    /* execute.simd:2679 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2679 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2679 [F] s_b_6_3: sym_30942_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30942_0_lane = s_b_6_2;
    /* execute.simd:2679 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2687 [F] s_b_7_0=sym_30930_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2793 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_7_4: If s_b_7_3: Jump b_26 else b_27 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_3, b_40,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2690 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2690 [D] s_b_8_1 = sym_30936_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_30936_0_address, emitter.context().types().u64());
    /* execute.simd:2690 [D] s_b_8_2: sym_136368_3_parameter_value = s_b_8_1, dominates: s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_136368_3_parameter_value, s_b_8_1);
    /* execute.a64:2809 [F] s_b_8_3 = !s_b_8_0 (const) */
    uint8_t s_b_8_3 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_8_4: If s_b_8_3: Jump b_34 else b_35 (const) */
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
    /* execute.a64:2764 [F] s_b_9_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_9_1 = __builtin_get_feature */
    uint32_t s_b_9_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_9_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(s_b_9_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_9_4: If s_b_9_3: Jump b_12 else b_13 (const) */
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
    /* execute.a64:2796 [F] s_b_10_0=sym_30930_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_136057_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_136057_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_136057_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_136057_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2677 [D] s_b_11_1: sym_30936_0_address = s_b_11_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30936_0_address, s_b_11_0);
    /* execute.simd:2679 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.simd:2679 [F] s_b_11_3: sym_30942_0_lane = s_b_11_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30942_0_lane = (uint8_t)0ULL;
    /* execute.simd:2679 [F] s_b_11_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2765 [D] s_b_12_0 = ReadReg 21 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_12_1: sym_136074_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_136074_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2765 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_9,  */
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
    /* execute.a64:2767 [F] s_b_13_6: If s_b_13_5: Jump b_15 else b_16 (const) */
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
    /* execute.a64:2794 [D] s_b_14_0 = sym_136074_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_136074_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_136057_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_136057_0_return_symbol, s_b_14_0);
    /* ???:4294967295 [F] s_b_14_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_13,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2768 [D] s_b_15_0 = ReadReg 21 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_15_1: sym_136074_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_136074_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2768 [F] s_b_15_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_13,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2770 [D] s_b_16_0 = ReadReg 22 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_16_1: sym_136074_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_136074_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2770 [F] s_b_16_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3967 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_17_1: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3932 [F] s_b_18_0 = sym_136166_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_136166_3_parameter_rt;
    /* execute.simd:3932 [D] s_b_18_1 = ReadRegBank 15:s_b_18_0 (v8u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3933 [D] s_b_18_2 = sym_136171_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_136171_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3933 [F] s_b_18_3 = sym_136174_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_136174_3_parameter_lane;
    /* execute.simd:3933 [D] s_b_18_1[s_b_18_3] */
    auto s_b_18_4 = emitter.vector_extract(s_b_18_1, emitter.const_u8(s_b_18_3));
    /* ???:4294967295 [D] s_b_18_5: Store 1 s_b_18_2 <= s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_18_2, s_b_18_4);
    /* execute.simd:0 [F] s_b_18_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3937 [F] s_b_19_0 = sym_136166_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_136166_3_parameter_rt;
    /* execute.simd:3937 [D] s_b_19_1 = ReadRegBank 16:s_b_19_0 (v16u8) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3938 [D] s_b_19_2 = sym_136171_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_136171_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3938 [F] s_b_19_3 = sym_136174_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_136174_3_parameter_lane;
    /* execute.simd:3938 [D] s_b_19_1[s_b_19_3] */
    auto s_b_19_4 = emitter.vector_extract(s_b_19_1, emitter.const_u8(s_b_19_3));
    /* ???:4294967295 [D] s_b_19_5: Store 1 s_b_19_2 <= s_b_19_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_19_2, s_b_19_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_19_2, s_b_19_4);
    /* execute.simd:0 [F] s_b_19_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3942 [F] s_b_20_0 = sym_136166_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_136166_3_parameter_rt;
    /* execute.simd:3942 [D] s_b_20_1 = ReadRegBank 17:s_b_20_0 (v4u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3943 [D] s_b_20_2 = sym_136171_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_136171_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3943 [F] s_b_20_3 = sym_136174_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_136174_3_parameter_lane;
    /* execute.simd:3943 [D] s_b_20_1[s_b_20_3] */
    auto s_b_20_4 = emitter.vector_extract(s_b_20_1, emitter.const_u8(s_b_20_3));
    /* ???:4294967295 [D] s_b_20_5: Store 2 s_b_20_2 <= s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_20_2, s_b_20_4);
    /* execute.simd:0 [F] s_b_20_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3947 [F] s_b_21_0 = sym_136166_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_136166_3_parameter_rt;
    /* execute.simd:3947 [D] s_b_21_1 = ReadRegBank 18:s_b_21_0 (v8u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3948 [D] s_b_21_2 = sym_136171_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_136171_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3948 [F] s_b_21_3 = sym_136174_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_136174_3_parameter_lane;
    /* execute.simd:3948 [D] s_b_21_1[s_b_21_3] */
    auto s_b_21_4 = emitter.vector_extract(s_b_21_1, emitter.const_u8(s_b_21_3));
    /* ???:4294967295 [D] s_b_21_5: Store 2 s_b_21_2 <= s_b_21_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_21_2, s_b_21_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_21_2, s_b_21_4);
    /* execute.simd:0 [F] s_b_21_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3952 [F] s_b_22_0 = sym_136166_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_136166_3_parameter_rt;
    /* execute.simd:3952 [D] s_b_22_1 = ReadRegBank 19:s_b_22_0 (v2u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:3953 [D] s_b_22_2 = sym_136171_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_136171_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3953 [F] s_b_22_3 = sym_136174_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_136174_3_parameter_lane;
    /* execute.simd:3953 [D] s_b_22_1[s_b_22_3] */
    auto s_b_22_4 = emitter.vector_extract(s_b_22_1, emitter.const_u8(s_b_22_3));
    /* ???:4294967295 [D] s_b_22_5: Store 4 s_b_22_2 <= s_b_22_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_22_2, s_b_22_4);
    /* execute.simd:0 [F] s_b_22_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_23: 
  {
    /* execute.simd:3957 [F] s_b_23_0 = sym_136166_3_parameter_rt (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_136166_3_parameter_rt;
    /* execute.simd:3957 [D] s_b_23_1 = ReadRegBank 20:s_b_23_0 (v4u32) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:3958 [D] s_b_23_2 = sym_136171_3_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_136171_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3958 [F] s_b_23_3 = sym_136174_3_parameter_lane (const) uint8_t */
    uint8_t s_b_23_3 = CV_sym_136174_3_parameter_lane;
    /* execute.simd:3958 [D] s_b_23_1[s_b_23_3] */
    auto s_b_23_4 = emitter.vector_extract(s_b_23_1, emitter.const_u8(s_b_23_3));
    /* ???:4294967295 [D] s_b_23_5: Store 4 s_b_23_2 <= s_b_23_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_23_2, s_b_23_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_23_2, s_b_23_4);
    /* execute.simd:0 [F] s_b_23_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_24: 
  {
    /* execute.simd:3962 [F] s_b_24_0 = sym_136166_3_parameter_rt (const) uint8_t */
    uint8_t s_b_24_0 = CV_sym_136166_3_parameter_rt;
    /* execute.simd:3962 [D] s_b_24_1 = ReadRegBank 21:s_b_24_0 (v2u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))),s_b_24_1,emitter.const_u8(16));
    }
    /* execute.simd:3963 [D] s_b_24_2 = sym_136171_3_parameter_addr uint64_t */
    auto s_b_24_2 = emitter.load_local(DV_sym_136171_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3963 [F] s_b_24_3 = sym_136174_3_parameter_lane (const) uint8_t */
    uint8_t s_b_24_3 = CV_sym_136174_3_parameter_lane;
    /* execute.simd:3963 [D] s_b_24_1[s_b_24_3] */
    auto s_b_24_4 = emitter.vector_extract(s_b_24_1, emitter.const_u8(s_b_24_3));
    /* ???:4294967295 [D] s_b_24_5: Store 8 s_b_24_2 <= s_b_24_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_24_2, s_b_24_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_24_2, s_b_24_4);
    /* execute.simd:0 [F] s_b_24_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_17, b_18, b_19, b_20, b_21, b_22, b_23, b_24,  */
  fixed_block_b_25: 
  {
    /* ???:4294967295 [D] s_b_25_0 = sym_136251_1_tmp_s_b_5_5 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_136251_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_25_1 = sym_136248_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_25_1 = CV_sym_136248_1_tmp_s_b_5_2;
    /* execute.simd:2682 [F] s_b_25_2=sym_30930_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_25_3 = (u64)s_b_25_2 (const) */
    /* ???:4294967295 [D] s_b_25_4 = s_b_25_0+s_b_25_3 */
    auto s_b_25_4 = emitter.add(s_b_25_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2682 [D] s_b_25_5: sym_30936_0_address = s_b_25_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30936_0_address, s_b_25_4);
    /* execute.simd:2680 [F] s_b_25_6 = constant u8 1 (const) */
    /* execute.simd:2680 [F] s_b_25_7 = s_b_25_1+s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(s_b_25_1 + (uint8_t)1ULL));
    /* execute.simd:2680 [F] s_b_25_8: sym_30954_0_rt = s_b_25_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30954_0_rt = s_b_25_7;
    /* execute.simd:2680 [F] s_b_25_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2764 [F] s_b_26_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_26_1 = __builtin_get_feature */
    uint32_t s_b_26_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_26_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(s_b_26_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_26_4: If s_b_26_3: Jump b_29 else b_30 (const) */
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
    /* execute.a64:2796 [F] s_b_27_0=sym_30930_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_27_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_27_2: sym_136273_0_return_symbol = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_136273_0_return_symbol, s_b_27_1);
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_31,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_136273_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_136273_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2687 [F] s_b_28_1=sym_30930_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_28_2: sym_136427_1_tmp_s_b_57_0 = s_b_28_0, dominates: s_b_40_1  */
    emitter.store_local(DV_sym_136427_1_tmp_s_b_57_0, s_b_28_0);
    /* execute.a64:2714 [F] s_b_28_3 = (u32)s_b_28_1 (const) */
    /* execute.a64:2714 [F] s_b_28_4 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
    uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_28_6: If s_b_28_5: Jump b_39 else b_41 (const) */
    if (s_b_28_5) 
    {
      goto fixed_block_b_39;
    }
    else 
    {
      goto fixed_block_b_41;
    }
  }
  /* b_26,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2765 [D] s_b_29_0 = ReadReg 21 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_29_1: sym_136290_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_136290_1__R_s_b_3_0, s_b_29_0);
    /* execute.a64:2765 [F] s_b_29_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_26,  */
  fixed_block_b_30: 
  {
    /* execute.a64:3075 [F] s_b_30_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_30_1 = __builtin_get_feature */
    uint32_t s_b_30_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_30_2 = (u8)s_b_30_1 (const) */
    /* execute.a64:2767 [F] s_b_30_3 = (u32)s_b_30_2 (const) */
    /* execute.a64:2767 [F] s_b_30_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_30_5 = s_b_30_3==s_b_30_4 (const) */
    uint8_t s_b_30_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_30_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_30_6: If s_b_30_5: Jump b_32 else b_33 (const) */
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
    /* execute.a64:2794 [D] s_b_31_0 = sym_136290_1__R_s_b_3_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_136290_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1: sym_136273_0_return_symbol = s_b_31_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_136273_0_return_symbol, s_b_31_0);
    /* ???:4294967295 [F] s_b_31_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_30,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2768 [D] s_b_32_0 = ReadReg 21 (u64) */
    auto s_b_32_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_32_1: sym_136290_1__R_s_b_3_0 = s_b_32_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_136290_1__R_s_b_3_0, s_b_32_0);
    /* execute.a64:2768 [F] s_b_32_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_30,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2770 [D] s_b_33_0 = ReadReg 22 (u64) */
    auto s_b_33_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_33_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_33_1: sym_136290_1__R_s_b_3_0 = s_b_33_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_136290_1__R_s_b_3_0, s_b_33_0);
    /* execute.a64:2770 [F] s_b_33_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_8,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2810 [D] s_b_34_0 = sym_136368_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_136368_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_34_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_34_2 = s_b_34_0&s_b_34_1 */
    auto s_b_34_2 = emitter.bitwise_and(s_b_34_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_34_3: sym_136368_3_parameter_value = s_b_34_2, dominates: s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_136368_3_parameter_value, s_b_34_2);
    /* execute.a64:2810 [F] s_b_34_4: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_8, b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2813 [F] s_b_35_0=sym_30930_3_parameter_inst.rn (const) */
    /* execute.a64:2813 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
    /* execute.a64:2813 [F] s_b_35_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_35_3 = s_b_35_1==s_b_35_2 (const) */
    uint8_t s_b_35_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_35_4: If s_b_35_3: Jump b_36 else b_37 (const) */
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
    /* execute.a64:2814 [D] s_b_36_0 = sym_136368_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_136368_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_36_1: sym_136439_3_parameter_value = s_b_36_0, dominates: s_b_42_0 s_b_43_0 s_b_44_0  */
    emitter.store_local(DV_sym_136439_3_parameter_value, s_b_36_0);
    /* execute.a64:2777 [F] s_b_36_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_36_3 = __builtin_get_feature */
    uint32_t s_b_36_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_36_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(s_b_36_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_36_6: If s_b_36_5: Jump b_42 else b_45 (const) */
    if (s_b_36_5) 
    {
      goto fixed_block_b_42;
    }
    else 
    {
      goto fixed_block_b_45;
    }
  }
  /* b_35,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2816 [F] s_b_37_0=sym_30930_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_37_1 = sym_136368_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_136368_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_37_2: WriteRegBank 0:s_b_37_0 = s_b_37_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_37_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_37_1);
    /* execute.a64:2816 [F] s_b_37_3: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_37, b_42, b_43, b_44,  */
  fixed_block_b_38: 
  {
    /* ???:4294967295 [F] s_b_38_0: Return */
    goto fixed_done;
  }
  /* b_28,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2714 [F] s_b_39_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_39_1: sym_136400_1_temporary_value = s_b_39_0 (const), dominates: s_b_40_0  */
    CV_sym_136400_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_136400_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_39_2: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_39, b_41,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2714 [D] s_b_40_0 = sym_136400_1_temporary_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_136400_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_40_1 = sym_136427_1_tmp_s_b_57_0 uint64_t */
    auto s_b_40_1 = emitter.load_local(DV_sym_136427_1_tmp_s_b_57_0, emitter.context().types().u64());
    /* execute.simd:2687 [D] s_b_40_2 = s_b_40_1+s_b_40_0 */
    auto s_b_40_2 = emitter.add(s_b_40_1, s_b_40_0);
    /* execute.simd:2687 [D] s_b_40_3: sym_30936_0_address = s_b_40_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_30936_0_address, s_b_40_2);
    /* execute.simd:2687 [F] s_b_40_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_28,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2714 [F] s_b_41_0=sym_30930_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_41_1 = ReadRegBank 0:s_b_41_0 (u64) */
    auto s_b_41_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_41_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_41_2: sym_136400_1_temporary_value = s_b_41_1, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_136400_1_temporary_value, s_b_41_1);
    /* execute.a64:2714 [F] s_b_41_3: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_36,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2778 [D] s_b_42_0 = sym_136439_3_parameter_value uint64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_136439_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_42_1: WriteReg 21 = s_b_42_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_42_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_42_0);
    /* execute.a64:2778 [F] s_b_42_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_45,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2781 [D] s_b_43_0 = sym_136439_3_parameter_value uint64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_136439_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_43_1: WriteReg 21 = s_b_43_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_43_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_43_0);
    /* execute.a64:2781 [F] s_b_43_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_45,  */
  fixed_block_b_44: 
  {
    /* execute.a64:2783 [D] s_b_44_0 = sym_136439_3_parameter_value uint64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_136439_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_44_1: WriteReg 22 = s_b_44_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_44_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_44_0);
    /* execute.a64:2783 [F] s_b_44_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_36,  */
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
    /* execute.a64:2780 [F] s_b_45_6: If s_b_45_5: Jump b_43 else b_44 (const) */
    if (s_b_45_5) 
    {
      goto fixed_block_b_43;
    }
    else 
    {
      goto fixed_block_b_44;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stlxp(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_139534_1_tmp_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139039_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_139143_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139215_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_139455_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139022_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_139805_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139665_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_31359_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139879_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139593_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139309_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139381_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:833 [F] s_b_0_0=sym_31353_3_parameter_inst.rn (const) */
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
    /* execute.a64:836 [F] s_b_1_0 = constant u32 0 (const) */
    /* execute.a64:836 [D] s_b_1_1 = sym_31359_0_address uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_31359_0_address, emitter.context().types().u64());
    /* execute.a64:836 [D] s_b_1_2 = mem_monitor_release */
    auto s_b_1_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_1_1);
    /* execute.a64:836 [D] s_b_1_3: If s_b_1_2: Jump b_4 else b_5 */
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
    /* execute.a64:844 [F] s_b_3_0 = constant u32 0 (const) */
    /* execute.a64:844 [D] s_b_3_1 = sym_31359_0_address uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_31359_0_address, emitter.context().types().u64());
    /* execute.a64:844 [D] s_b_3_2 = mem_monitor_release */
    auto s_b_3_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_3_1);
    /* execute.a64:844 [D] s_b_3_3: If s_b_3_2: Jump b_6 else b_7 */
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
    /* execute.a64:2796 [F] s_b_9_0=sym_31353_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_139022_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_139022_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_139022_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_139022_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:833 [D] s_b_10_1: sym_31359_0_address = s_b_10_0, dominates: s_b_1_1 s_b_4_0 s_b_3_1 s_b_6_0  */
    emitter.store_local(DV_sym_31359_0_address, s_b_10_0);
    /* execute.a64:835 [F] s_b_10_2=sym_31353_3_parameter_inst.size (const) */
    /* execute.a64:835 [F] s_b_10_3 = (u32)s_b_10_2 (const) */
    /* execute.a64:835 [F] s_b_10_4 = constant u32 2 (const) */
    /* execute.a64:835 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:835 [F] s_b_10_6: If s_b_10_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2765 [D] s_b_11_1: sym_139039_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_139039_1__R_s_b_3_0, s_b_11_0);
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
    /* execute.a64:2794 [D] s_b_13_0 = sym_139039_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_139039_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_139022_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_139022_0_return_symbol, s_b_13_0);
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
    /* execute.a64:2768 [D] s_b_14_1: sym_139039_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_139039_1__R_s_b_3_0, s_b_14_0);
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
    /* execute.a64:2770 [D] s_b_15_1: sym_139039_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_139039_1__R_s_b_3_0, s_b_15_0);
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
        /* execute.a64:837 [D] s_b_4_0 = sym_31359_0_address uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_31359_0_address, emitter.context().types().u64());
        /* execute.a64:837 [F] s_b_4_1=sym_31353_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_4_2: sym_139309_1_tmp_s_b_4_0 = s_b_4_0, dominates: s_b_18_5  */
        emitter.store_local(DV_sym_139309_1_tmp_s_b_4_0, s_b_4_0);
        /* ???:4294967295 [D] s_b_4_3: sym_139143_1_tmp_s_b_4_0 = s_b_4_0, dominates: s_b_18_2  */
        emitter.store_local(DV_sym_139143_1_tmp_s_b_4_0, s_b_4_0);
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
        /* execute.a64:841 [F] s_b_5_0=sym_31353_3_parameter_inst.rs (const) */
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
        /* execute.a64:845 [D] s_b_6_0 = sym_31359_0_address uint64_t */
        auto s_b_6_0 = emitter.load_local(DV_sym_31359_0_address, emitter.context().types().u64());
        /* execute.a64:845 [F] s_b_6_1=sym_31353_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_6_2: sym_139534_1_tmp_s_b_7_0 = s_b_6_0, dominates: s_b_22_3  */
        emitter.store_local(DV_sym_139534_1_tmp_s_b_7_0, s_b_6_0);
        /* ???:4294967295 [D] s_b_6_3: sym_139381_1_tmp_s_b_5_0 = s_b_6_0, dominates: s_b_22_1  */
        emitter.store_local(DV_sym_139381_1_tmp_s_b_5_0, s_b_6_0);
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
        /* execute.a64:849 [F] s_b_7_0=sym_31353_3_parameter_inst.rs (const) */
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
        /* execute.a64:2709 [D] s_b_16_1: sym_139215_1_temporary_value = s_b_16_0, dominates: s_b_18_0  */
        emitter.store_local(DV_sym_139215_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_17_0=sym_31353_3_parameter_inst.rt (const) */
        /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
        auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_17_2: sym_139215_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
        emitter.store_local(DV_sym_139215_1_temporary_value, s_b_17_1);
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
        /* execute.a64:2709 [D] s_b_18_0 = sym_139215_1_temporary_value uint32_t */
        auto s_b_18_0 = emitter.load_local(DV_sym_139215_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
        auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_18_2 = sym_139143_1_tmp_s_b_4_0 uint64_t */
        auto s_b_18_2 = emitter.load_local(DV_sym_139143_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:1855 [D] s_b_18_3 = (u32)s_b_18_1 */
        auto s_b_18_3 = emitter.truncate(s_b_18_1, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_18_4: Store 4 s_b_18_2 <= s_b_18_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_3, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_18_2, s_b_18_3);
        /* ???:4294967295 [D] s_b_18_5 = sym_139309_1_tmp_s_b_4_0 uint64_t */
        auto s_b_18_5 = emitter.load_local(DV_sym_139309_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:838 [F] s_b_18_6 = constant u64 4 (const) */
        /* execute.a64:838 [D] s_b_18_7 = s_b_18_5+s_b_18_6 */
        auto s_b_18_7 = emitter.add(s_b_18_5, emitter.const_u64((uint64_t)4ULL));
        /* execute.a64:838 [F] s_b_18_8=sym_31353_3_parameter_inst.rt2 (const) */
        /* ???:4294967295 [D] s_b_18_9: sym_139593_1_tmp_s_b_4_0 = s_b_18_7, dominates: s_b_26_2  */
        emitter.store_local(DV_sym_139593_1_tmp_s_b_4_0, s_b_18_7);
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
        /* execute.a64:2739 [F] s_b_19_0=sym_31353_3_parameter_inst.rs (const) */
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
        /* execute.a64:2714 [D] s_b_20_1: sym_139455_1_temporary_value = s_b_20_0, dominates: s_b_22_0  */
        emitter.store_local(DV_sym_139455_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_21_0=sym_31353_3_parameter_inst.rt (const) */
        /* execute.a64:2714 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
        auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_21_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_21_2: sym_139455_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
        emitter.store_local(DV_sym_139455_1_temporary_value, s_b_21_1);
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
        /* execute.a64:2714 [D] s_b_22_0 = sym_139455_1_temporary_value uint64_t */
        auto s_b_22_0 = emitter.load_local(DV_sym_139455_1_temporary_value, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_22_1 = sym_139381_1_tmp_s_b_5_0 uint64_t */
        auto s_b_22_1 = emitter.load_local(DV_sym_139381_1_tmp_s_b_5_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_22_2: Store 8 s_b_22_1 <= s_b_22_0 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_1, s_b_22_0, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_22_1, s_b_22_0);
        /* ???:4294967295 [D] s_b_22_3 = sym_139534_1_tmp_s_b_7_0 uint64_t */
        auto s_b_22_3 = emitter.load_local(DV_sym_139534_1_tmp_s_b_7_0, emitter.context().types().u64());
        /* execute.a64:846 [F] s_b_22_4 = constant u64 8 (const) */
        /* execute.a64:846 [D] s_b_22_5 = s_b_22_3+s_b_22_4 */
        auto s_b_22_5 = emitter.add(s_b_22_3, emitter.const_u64((uint64_t)8ULL));
        /* execute.a64:846 [F] s_b_22_6=sym_31353_3_parameter_inst.rt2 (const) */
        /* ???:4294967295 [D] s_b_22_7: sym_139805_1_tmp_s_b_5_0 = s_b_22_5, dominates: s_b_29_1  */
        emitter.store_local(DV_sym_139805_1_tmp_s_b_5_0, s_b_22_5);
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
        /* execute.a64:2739 [F] s_b_23_0=sym_31353_3_parameter_inst.rs (const) */
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
        /* execute.a64:2709 [D] s_b_24_1: sym_139665_1_temporary_value = s_b_24_0, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_139665_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_25_0=sym_31353_3_parameter_inst.rt2 (const) */
        /* execute.a64:2709 [D] s_b_25_1 = ReadRegBank 1:s_b_25_0 (u32) */
        auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_25_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_25_2: sym_139665_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_139665_1_temporary_value, s_b_25_1);
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
        /* execute.a64:2709 [D] s_b_26_0 = sym_139665_1_temporary_value uint32_t */
        auto s_b_26_0 = emitter.load_local(DV_sym_139665_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_26_1 = (u64)s_b_26_0 */
        auto s_b_26_1 = emitter.zx(s_b_26_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_26_2 = sym_139593_1_tmp_s_b_4_0 uint64_t */
        auto s_b_26_2 = emitter.load_local(DV_sym_139593_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:1855 [D] s_b_26_3 = (u32)s_b_26_1 */
        auto s_b_26_3 = emitter.truncate(s_b_26_1, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_26_4: Store 4 s_b_26_2 <= s_b_26_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_26_2, s_b_26_3, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_26_2, s_b_26_3);
        /* execute.a64:839 [F] s_b_26_5=sym_31353_3_parameter_inst.rs (const) */
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
        /* execute.a64:2714 [D] s_b_27_1: sym_139879_1_temporary_value = s_b_27_0, dominates: s_b_29_0  */
        emitter.store_local(DV_sym_139879_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_28_0=sym_31353_3_parameter_inst.rt2 (const) */
        /* execute.a64:2714 [D] s_b_28_1 = ReadRegBank 0:s_b_28_0 (u64) */
        auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_28_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_28_2: sym_139879_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
        emitter.store_local(DV_sym_139879_1_temporary_value, s_b_28_1);
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
        /* execute.a64:2714 [D] s_b_29_0 = sym_139879_1_temporary_value uint64_t */
        auto s_b_29_0 = emitter.load_local(DV_sym_139879_1_temporary_value, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_29_1 = sym_139805_1_tmp_s_b_5_0 uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_139805_1_tmp_s_b_5_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_29_2: Store 8 s_b_29_1 <= s_b_29_0 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_29_1, s_b_29_0, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_29_1, s_b_29_0);
        /* execute.a64:847 [F] s_b_29_3=sym_31353_3_parameter_inst.rs (const) */
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
        /* execute.a64:2739 [F] s_b_30_0=sym_31353_3_parameter_inst.rs (const) */
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
        /* execute.a64:2739 [F] s_b_31_0=sym_31353_3_parameter_inst.rs (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stpi_simd(const arm64_decode_a64_LS_REG_PAIR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_143682_1_tmp_s_b_0_5;
  auto DV_sym_143680_1_tmp_s_b_0_7 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143690_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143775_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_143684_1_tmp_s_b_0_1;
  auto DV_sym_143555_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31874_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143572_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143814_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143647_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:789 [F] s_b_0_0=sym_31868_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_5 else b_6 (const) */
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
    /* execute.simd:791 [D] s_b_1_0 = sym_31874_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31874_0_addr, emitter.context().types().u64());
    /* execute.simd:791 [F] s_b_1_1=sym_31868_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.simd:791 [D] s_b_1_3: sym_31874_0_addr = s_b_1_2, dominates: s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_31874_0_addr, s_b_1_2);
    /* execute.simd:791 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.simd:794 [F] s_b_2_0=sym_31868_3_parameter_inst.opc (const) */
    /* execute.simd:794 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.simd:794 [F] s_b_2_2 = constant u32 2 (const) */
    /* execute.simd:794 [F] s_b_2_3 = s_b_2_1+s_b_2_2 (const) */
    uint32_t s_b_2_3 = ((uint32_t)(((uint32_t)insn.opc) + (uint32_t)2ULL));
    /* execute.simd:794 [F] s_b_2_4 = (u8)s_b_2_3 (const) */
    /* execute.simd:794 [D] s_b_2_5 = sym_31874_0_addr uint64_t */
    auto s_b_2_5 = emitter.load_local(DV_sym_31874_0_addr, emitter.context().types().u64());
    /* execute.simd:765 [F] s_b_2_6 = constant u32 1 (const) */
    /* execute.simd:765 [F] s_b_2_7 = (u32)s_b_2_4 (const) */
    /* execute.simd:765 [F] s_b_2_8 = s_b_2_6<<s_b_2_7 (const) */
    uint32_t s_b_2_8 = ((uint32_t)((uint32_t)1ULL << ((uint32_t)((uint8_t)s_b_2_3))));
    /* execute.simd:765 [F] s_b_2_9 = (u8)s_b_2_8 (const) */
    /* ???:4294967295 [F] s_b_2_10: sym_143684_1_tmp_s_b_0_1 = s_b_2_4 (const), dominates: s_b_14_2  */
    CV_sym_143684_1_tmp_s_b_0_1 = ((uint8_t)s_b_2_3);
    /* ???:4294967295 [F] s_b_2_11: sym_143682_1_tmp_s_b_0_5 = s_b_2_9 (const), dominates: s_b_14_1  */
    CV_sym_143682_1_tmp_s_b_0_5 = ((uint8_t)s_b_2_8);
    /* ???:4294967295 [D] s_b_2_12: sym_143680_1_tmp_s_b_0_7 = s_b_2_5, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_143680_1_tmp_s_b_0_7, s_b_2_5);
    /* ???:4294967295 [D] s_b_2_13: sym_143647_0_replaced_parameter_addr = s_b_2_5, dominates: s_b_18_3 s_b_17_2 s_b_16_2 s_b_15_2 s_b_13_2  */
    emitter.store_local(DV_sym_143647_0_replaced_parameter_addr, s_b_2_5);
    /* execute.simd:3723 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:3729 [F] s_b_2_15 = constant s32 1 (const) */
    /* execute.simd:3735 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:3741 [F] s_b_2_17 = constant s32 3 (const) */
    /* execute.simd:3747 [F] s_b_2_18 = constant s32 4 (const) */
    /* execute.simd:3722 [F] s_b_2_19: Switch s_b_2_4: < <todo> > def b_14 (const) -> b_18, b_17, b_16, b_15, b_14, b_13,  */
    switch (((uint8_t)s_b_2_3)) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_17;
      break;
    default:
      goto fixed_block_b_14;
    }
  }
  /* b_24,  */
  fixed_block_b_3: 
  {
    /* execute.simd:797 [D] s_b_3_0 = sym_31874_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31874_0_addr, emitter.context().types().u64());
    /* execute.simd:797 [F] s_b_3_1=sym_31868_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:797 [D] s_b_3_3: sym_31874_0_addr = s_b_3_2, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_31874_0_addr, s_b_3_2);
    /* execute.simd:797 [F] s_b_3_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_24,  */
  fixed_block_b_4: 
  {
    /* execute.simd:800 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.simd:800 [D] s_b_4_1 = sym_31874_0_addr uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_31874_0_addr, emitter.context().types().u64());
    /* execute.simd:800 [D] s_b_4_2: sym_143775_3_parameter_value = s_b_4_1, dominates: s_b_25_0 s_b_27_0 s_b_28_1  */
    emitter.store_local(DV_sym_143775_3_parameter_value, s_b_4_1);
    /* execute.a64:2809 [F] s_b_4_3 = !s_b_4_0 (const) */
    uint8_t s_b_4_3 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_4_4: If s_b_4_3: Jump b_25 else b_26 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2764 [F] s_b_5_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_5_1 = __builtin_get_feature */
    uint32_t s_b_5_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(s_b_5_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 (const) */
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
    /* execute.a64:2796 [F] s_b_6_0=sym_31868_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_6_1 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_6_2: sym_143555_0_return_symbol = s_b_6_1, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_143555_0_return_symbol, s_b_6_1);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_10,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [D] s_b_7_0 = sym_143555_0_return_symbol uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_143555_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:789 [D] s_b_7_1: sym_31874_0_addr = s_b_7_0, dominates: s_b_1_0 s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_31874_0_addr, s_b_7_0);
    /* execute.simd:790 [F] s_b_7_2=sym_31868_3_parameter_inst.P (const) */
    /* execute.simd:790 [F] s_b_7_3: If s_b_7_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2765 [D] s_b_8_0 = ReadReg 21 (u64) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_8_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_8_1: sym_143572_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_143572_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2765 [F] s_b_8_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_5,  */
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
    /* execute.a64:2767 [F] s_b_9_6: If s_b_9_5: Jump b_11 else b_12 (const) */
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
    /* execute.a64:2794 [D] s_b_10_0 = sym_143572_1__R_s_b_3_0 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_143572_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1: sym_143555_0_return_symbol = s_b_10_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_143555_0_return_symbol, s_b_10_0);
    /* ???:4294967295 [F] s_b_10_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2768 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_11_1: sym_143572_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_143572_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2768 [F] s_b_11_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2770 [D] s_b_12_0 = ReadReg 22 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_12_1: sym_143572_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_143572_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2770 [F] s_b_12_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_2,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3725 [F] s_b_13_0=sym_31868_3_parameter_inst.rt (const) */
    /* execute.simd:6340 [D] s_b_13_1 = ReadRegBank 4:s_b_13_0 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1,emitter.const_u8(1));
    }
    /* execute.simd:3726 [D] s_b_13_2 = sym_143647_0_replaced_parameter_addr uint64_t */
    auto s_b_13_2 = emitter.load_local(DV_sym_143647_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_3: Store 1 s_b_13_2 <= s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_13_2, s_b_13_1, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_13_2, s_b_13_1);
    /* execute.simd:0 [F] s_b_13_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_2, b_13, b_15, b_16, b_17, b_18,  */
  fixed_block_b_14: 
  {
    /* ???:4294967295 [D] s_b_14_0 = sym_143680_1_tmp_s_b_0_7 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_143680_1_tmp_s_b_0_7, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_14_1 = sym_143682_1_tmp_s_b_0_5 (const) uint8_t */
    uint8_t s_b_14_1 = CV_sym_143682_1_tmp_s_b_0_5;
    /* ???:4294967295 [F] s_b_14_2 = sym_143684_1_tmp_s_b_0_1 (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_143684_1_tmp_s_b_0_1;
    /* execute.simd:767 [F] s_b_14_3 = (u64)s_b_14_1 (const) */
    /* execute.simd:767 [D] s_b_14_4 = s_b_14_0+s_b_14_3 */
    auto s_b_14_4 = emitter.add(s_b_14_0, emitter.const_u64(((uint64_t)s_b_14_1)));
    /* ???:4294967295 [D] s_b_14_5: sym_143690_0_replaced_parameter_addr = s_b_14_4, dominates: s_b_19_2 s_b_22_3 s_b_21_2 s_b_20_2 s_b_23_2  */
    emitter.store_local(DV_sym_143690_0_replaced_parameter_addr, s_b_14_4);
    /* execute.simd:3723 [F] s_b_14_6 = constant s32 0 (const) */
    /* execute.simd:3729 [F] s_b_14_7 = constant s32 1 (const) */
    /* execute.simd:3735 [F] s_b_14_8 = constant s32 2 (const) */
    /* execute.simd:3741 [F] s_b_14_9 = constant s32 3 (const) */
    /* execute.simd:3747 [F] s_b_14_10 = constant s32 4 (const) */
    /* execute.simd:3722 [F] s_b_14_11: Switch s_b_14_2: < <todo> > def b_24 (const) -> b_19, b_22, b_21, b_24, b_20, b_23,  */
    switch (s_b_14_2) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_22;
      break;
    default:
      goto fixed_block_b_24;
    }
  }
  /* b_2,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3731 [F] s_b_15_0=sym_31868_3_parameter_inst.rt (const) */
    /* execute.simd:6345 [D] s_b_15_1 = ReadRegBank 5:s_b_15_0 (u16) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_15_1,emitter.const_u8(2));
    }
    /* execute.simd:3732 [D] s_b_15_2 = sym_143647_0_replaced_parameter_addr uint64_t */
    auto s_b_15_2 = emitter.load_local(DV_sym_143647_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_3: Store 2 s_b_15_2 <= s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_15_2, s_b_15_1, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_15_2, s_b_15_1);
    /* execute.simd:0 [F] s_b_15_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_2,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3737 [F] s_b_16_0=sym_31868_3_parameter_inst.rt (const) */
    /* execute.simd:6350 [D] s_b_16_1 = ReadRegBank 6:s_b_16_0 (u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_1,emitter.const_u8(4));
    }
    /* execute.simd:3738 [D] s_b_16_2 = sym_143647_0_replaced_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_143647_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_3: Store 4 s_b_16_2 <= s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_16_2, s_b_16_1, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_16_2, s_b_16_1);
    /* execute.simd:0 [F] s_b_16_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_2,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3743 [F] s_b_17_0=sym_31868_3_parameter_inst.rt (const) */
    /* execute.simd:6355 [D] s_b_17_1 = ReadRegBank 7:s_b_17_0 (u64) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.simd:3744 [D] s_b_17_2 = sym_143647_0_replaced_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_143647_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_3: Store 8 s_b_17_2 <= s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_17_2, s_b_17_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_17_2, s_b_17_1);
    /* execute.simd:0 [F] s_b_17_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_2,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3751 [F] s_b_18_0=sym_31868_3_parameter_inst.rt (const) */
    /* execute.simd:6360 [D] s_b_18_1 = ReadRegBank 2:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_18_2 = ReadRegBank 3:s_b_18_0 (u64) */
    auto s_b_18_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_18_2,emitter.const_u8(8));
    }
    /* execute.simd:3752 [D] s_b_18_3 = sym_143647_0_replaced_parameter_addr uint64_t */
    auto s_b_18_3 = emitter.load_local(DV_sym_143647_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_4: Store 8 s_b_18_3 <= s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_3, s_b_18_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_18_3, s_b_18_1);
    /* execute.simd:3753 [F] s_b_18_5 = constant u64 8 (const) */
    /* execute.simd:3753 [D] s_b_18_6 = s_b_18_3+s_b_18_5 */
    auto s_b_18_6 = emitter.add(s_b_18_3, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_18_7: Store 8 s_b_18_6 <= s_b_18_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_6, s_b_18_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_18_6, s_b_18_2);
    /* execute.simd:0 [F] s_b_18_8: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_14,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3743 [F] s_b_19_0=sym_31868_3_parameter_inst.rt2 (const) */
    /* execute.simd:6355 [D] s_b_19_1 = ReadRegBank 7:s_b_19_0 (u64) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.simd:3744 [D] s_b_19_2 = sym_143690_0_replaced_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_143690_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_19_3: Store 8 s_b_19_2 <= s_b_19_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_19_2, s_b_19_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_19_2, s_b_19_1);
    /* execute.simd:0 [F] s_b_19_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3737 [F] s_b_20_0=sym_31868_3_parameter_inst.rt2 (const) */
    /* execute.simd:6350 [D] s_b_20_1 = ReadRegBank 6:s_b_20_0 (u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_20_1,emitter.const_u8(4));
    }
    /* execute.simd:3738 [D] s_b_20_2 = sym_143690_0_replaced_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_143690_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_3: Store 4 s_b_20_2 <= s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_1, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_20_2, s_b_20_1);
    /* execute.simd:0 [F] s_b_20_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3731 [F] s_b_21_0=sym_31868_3_parameter_inst.rt2 (const) */
    /* execute.simd:6345 [D] s_b_21_1 = ReadRegBank 5:s_b_21_0 (u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_21_1,emitter.const_u8(2));
    }
    /* execute.simd:3732 [D] s_b_21_2 = sym_143690_0_replaced_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_143690_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_3: Store 2 s_b_21_2 <= s_b_21_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_21_2, s_b_21_1, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_21_2, s_b_21_1);
    /* execute.simd:0 [F] s_b_21_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3751 [F] s_b_22_0=sym_31868_3_parameter_inst.rt2 (const) */
    /* execute.simd:6360 [D] s_b_22_1 = ReadRegBank 2:s_b_22_0 (u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_22_2 = ReadRegBank 3:s_b_22_0 (u64) */
    auto s_b_22_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),s_b_22_2,emitter.const_u8(8));
    }
    /* execute.simd:3752 [D] s_b_22_3 = sym_143690_0_replaced_parameter_addr uint64_t */
    auto s_b_22_3 = emitter.load_local(DV_sym_143690_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_22_4: Store 8 s_b_22_3 <= s_b_22_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_3, s_b_22_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_22_3, s_b_22_1);
    /* execute.simd:3753 [F] s_b_22_5 = constant u64 8 (const) */
    /* execute.simd:3753 [D] s_b_22_6 = s_b_22_3+s_b_22_5 */
    auto s_b_22_6 = emitter.add(s_b_22_3, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_22_7: Store 8 s_b_22_6 <= s_b_22_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_6, s_b_22_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_22_6, s_b_22_2);
    /* execute.simd:0 [F] s_b_22_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_23: 
  {
    /* execute.simd:3725 [F] s_b_23_0=sym_31868_3_parameter_inst.rt2 (const) */
    /* execute.simd:6340 [D] s_b_23_1 = ReadRegBank 4:s_b_23_0 (u8) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_23_1,emitter.const_u8(1));
    }
    /* execute.simd:3726 [D] s_b_23_2 = sym_143690_0_replaced_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_143690_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_23_3: Store 1 s_b_23_2 <= s_b_23_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_23_2, s_b_23_1, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_23_2, s_b_23_1);
    /* execute.simd:0 [F] s_b_23_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14, b_19, b_20, b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.simd:796 [F] s_b_24_0=sym_31868_3_parameter_inst.P (const) */
    /* execute.simd:796 [F] s_b_24_1 = !s_b_24_0 (const) */
    uint8_t s_b_24_1 = !insn.P;
    /* execute.simd:796 [F] s_b_24_2: If s_b_24_1: Jump b_3 else b_4 (const) */
    if (s_b_24_1) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_4,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2810 [D] s_b_25_0 = sym_143775_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_143775_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_25_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_25_2 = s_b_25_0&s_b_25_1 */
    auto s_b_25_2 = emitter.bitwise_and(s_b_25_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_25_3: sym_143775_3_parameter_value = s_b_25_2, dominates: s_b_27_0 s_b_28_1  */
    emitter.store_local(DV_sym_143775_3_parameter_value, s_b_25_2);
    /* execute.a64:2810 [F] s_b_25_4: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_4, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2813 [F] s_b_26_0=sym_31868_3_parameter_inst.rn (const) */
    /* execute.a64:2813 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
    /* execute.a64:2813 [F] s_b_26_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_26_4: If s_b_26_3: Jump b_27 else b_28 (const) */
    if (s_b_26_3) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_28;
    }
  }
  /* b_26,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2814 [D] s_b_27_0 = sym_143775_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_143775_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_27_1: sym_143814_3_parameter_value = s_b_27_0, dominates: s_b_30_0 s_b_31_0 s_b_32_0  */
    emitter.store_local(DV_sym_143814_3_parameter_value, s_b_27_0);
    /* execute.a64:2777 [F] s_b_27_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_27_3 = __builtin_get_feature */
    uint32_t s_b_27_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_27_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_27_5 = s_b_27_3==s_b_27_4 (const) */
    uint8_t s_b_27_5 = ((uint8_t)(s_b_27_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_27_6: If s_b_27_5: Jump b_30 else b_33 (const) */
    if (s_b_27_5) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_33;
    }
  }
  /* b_26,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2816 [F] s_b_28_0=sym_31868_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_28_1 = sym_143775_3_parameter_value uint64_t */
    auto s_b_28_1 = emitter.load_local(DV_sym_143775_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_28_2: WriteRegBank 0:s_b_28_0 = s_b_28_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_28_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_28_1);
    /* execute.a64:2816 [F] s_b_28_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_28, b_30, b_31, b_32,  */
  fixed_block_b_29: 
  {
    /* ???:4294967295 [F] s_b_29_0: Return */
    goto fixed_done;
  }
  /* b_27,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2778 [D] s_b_30_0 = sym_143814_3_parameter_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_143814_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_30_1: WriteReg 21 = s_b_30_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_30_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_30_0);
    /* execute.a64:2778 [F] s_b_30_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_33,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2781 [D] s_b_31_0 = sym_143814_3_parameter_value uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_143814_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_31_1: WriteReg 21 = s_b_31_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_31_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_31_0);
    /* execute.a64:2781 [F] s_b_31_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_33,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2783 [D] s_b_32_0 = sym_143814_3_parameter_value uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_143814_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_32_1: WriteReg 22 = s_b_32_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_32_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_32_0);
    /* execute.a64:2783 [F] s_b_32_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27,  */
  fixed_block_b_33: 
  {
    /* execute.a64:3075 [F] s_b_33_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_33_1 = __builtin_get_feature */
    uint32_t s_b_33_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_33_2 = (u8)s_b_33_1 (const) */
    /* execute.a64:2780 [F] s_b_33_3 = (u32)s_b_33_2 (const) */
    /* execute.a64:2780 [F] s_b_33_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_33_5 = s_b_33_3==s_b_33_4 (const) */
    uint8_t s_b_33_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_33_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_33_6: If s_b_33_5: Jump b_31 else b_32 (const) */
    if (s_b_33_5) 
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_strh_reg(const arm64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_149003_1_temporary_value;
  auto DV_sym_149003_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_32753_0_rm;
  auto DV_sym_32753_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_148849_1_temporary_value;
  auto DV_sym_148849_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_148649_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_148576_1_temporary_value;
  auto DV_sym_148576_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_148632_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_149254_1_temporary_value;
  auto DV_sym_149254_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_149169_1_temporary_value;
  auto DV_sym_149169_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_149283_1_tmp_s_b_52_2 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1225 [F] s_b_0_0=sym_32726_3_parameter_inst.option0 (const) */
    /* execute.a64:1225 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1225 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1225 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1225 [F] s_b_0_4=sym_32726_3_parameter_inst.option21 (const) */
    /* execute.a64:1225 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:1225 [F] s_b_0_6 = constant u32 1 (const) */
    /* execute.a64:1225 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:1225 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1226 [F] s_b_1_0=sym_32726_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2709 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_1_4: If s_b_1_3: Jump b_10 else b_11 (const) */
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
    /* execute.a64:1238 [F] s_b_2_0=sym_32726_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2793 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_2_4: If s_b_2_3: Jump b_13 else b_14 (const) */
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
    /* execute.a64:1227 [F] s_b_3_0=sym_32726_3_parameter_inst.option0 (const) */
    /* execute.a64:1227 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1227 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1227 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1227 [F] s_b_3_4=sym_32726_3_parameter_inst.option21 (const) */
    /* execute.a64:1227 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:1227 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.a64:1227 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:1227 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1228 [F] s_b_4_0=sym_32726_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2709 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_4_4: If s_b_4_3: Jump b_21 else b_22 (const) */
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
    /* execute.a64:1229 [F] s_b_5_0=sym_32726_3_parameter_inst.option0 (const) */
    /* execute.a64:1229 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1229 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1229 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1229 [F] s_b_5_4=sym_32726_3_parameter_inst.option21 (const) */
    /* execute.a64:1229 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1229 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:1229 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1229 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1230 [F] s_b_6_0=sym_32726_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2714 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_6_4: If s_b_6_3: Jump b_24 else b_25 (const) */
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
    /* execute.a64:1231 [F] s_b_7_0=sym_32726_3_parameter_inst.option0 (const) */
    /* execute.a64:1231 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1231 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1231 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1231 [F] s_b_7_4=sym_32726_3_parameter_inst.option21 (const) */
    /* execute.a64:1231 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:1231 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.a64:1231 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:1231 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1232 [F] s_b_8_0=sym_32726_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2714 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_8_4: If s_b_8_3: Jump b_27 else b_28 (const) */
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
    /* execute.a64:1234 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:1234 [F] s_b_9_1: sym_32753_0_rm = s_b_9_0 (const), dominates: s_b_15_1  */
    CV_sym_32753_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_32753_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1235 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1234 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2709 [F] s_b_10_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_10_1: sym_148576_1_temporary_value = s_b_10_0 (const), dominates: s_b_12_0  */
    CV_sym_148576_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_148576_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_1,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [F] s_b_11_0=sym_32726_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_11_1 = ReadRegBank 1:s_b_11_0 (u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_11_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_11_2: sym_148576_1_temporary_value = s_b_11_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_148576_1_temporary_value, s_b_11_1);
    /* execute.a64:2709 [F] s_b_11_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [D] s_b_12_0 = sym_148576_1_temporary_value uint32_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_148576_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_12_1 = (u64)s_b_12_0 */
    auto s_b_12_1 = emitter.zx(s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2679 [D] s_b_12_2 = (u32)s_b_12_1 */
    auto s_b_12_2 = emitter.truncate(s_b_12_1, emitter.context().types().u32());
    /* execute.a64:2679 [D] s_b_12_3 = (u64)s_b_12_2 */
    auto s_b_12_3 = emitter.zx(s_b_12_2, emitter.context().types().u64());
    /* execute.a64:2679 [F] s_b_12_4=sym_32726_3_parameter_inst.S (const) */
    /* execute.a64:2679 [F] s_b_12_5 = (u64)s_b_12_4 (const) */
    /* execute.a64:2679 [D] s_b_12_6 = s_b_12_3<<s_b_12_5 */
    auto s_b_12_6 = emitter.shl(s_b_12_3, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1226 [D] s_b_12_7: sym_32753_0_rm = s_b_12_6, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32753_0_rm, s_b_12_6);
    /* execute.a64:1226 [F] s_b_12_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2764 [F] s_b_13_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_13_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(s_b_13_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_13_4: If s_b_13_3: Jump b_16 else b_17 (const) */
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
    /* execute.a64:2796 [F] s_b_14_0=sym_32726_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_14_2: sym_148632_0_return_symbol = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_148632_0_return_symbol, s_b_14_1);
    /* ???:4294967295 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14, b_18,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_148632_0_return_symbol uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_148632_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1238 [D] s_b_15_1 = sym_32753_0_rm uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_32753_0_rm, emitter.context().types().u64());
    /* execute.a64:1238 [D] s_b_15_2 = s_b_15_0+s_b_15_1 */
    auto s_b_15_2 = emitter.add(s_b_15_0, s_b_15_1);
    /* execute.a64:1240 [F] s_b_15_3=sym_32726_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_15_4: sym_149283_1_tmp_s_b_52_2 = s_b_15_2, dominates: s_b_32_2  */
    emitter.store_local(DV_sym_149283_1_tmp_s_b_52_2, s_b_15_2);
    /* execute.a64:2709 [F] s_b_15_5 = (u32)s_b_15_3 (const) */
    /* execute.a64:2709 [F] s_b_15_6 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_15_7 = s_b_15_5==s_b_15_6 (const) */
    uint8_t s_b_15_7 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_15_8: If s_b_15_7: Jump b_30 else b_31 (const) */
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
    /* execute.a64:2765 [D] s_b_16_0 = ReadReg 21 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_16_1: sym_148649_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_148649_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2765 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_17: 
  {
    /* execute.a64:3075 [F] s_b_17_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_17_1 = __builtin_get_feature */
    uint32_t s_b_17_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_17_2 = (u8)s_b_17_1 (const) */
    /* execute.a64:2767 [F] s_b_17_3 = (u32)s_b_17_2 (const) */
    /* execute.a64:2767 [F] s_b_17_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_17_5 = s_b_17_3==s_b_17_4 (const) */
    uint8_t s_b_17_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_17_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_17_6: If s_b_17_5: Jump b_19 else b_20 (const) */
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
    /* execute.a64:2794 [D] s_b_18_0 = sym_148649_1__R_s_b_3_0 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_148649_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1: sym_148632_0_return_symbol = s_b_18_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_148632_0_return_symbol, s_b_18_0);
    /* ???:4294967295 [F] s_b_18_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_17,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2768 [D] s_b_19_0 = ReadReg 21 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_19_1: sym_148649_1__R_s_b_3_0 = s_b_19_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_148649_1__R_s_b_3_0, s_b_19_0);
    /* execute.a64:2768 [F] s_b_19_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_17,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2770 [D] s_b_20_0 = ReadReg 22 (u64) */
    auto s_b_20_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_20_1: sym_148649_1__R_s_b_3_0 = s_b_20_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_148649_1__R_s_b_3_0, s_b_20_0);
    /* execute.a64:2770 [F] s_b_20_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2709 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_21_1: sym_148849_1_temporary_value = s_b_21_0 (const), dominates: s_b_23_0  */
    CV_sym_148849_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_148849_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_21_2: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_4,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2709 [F] s_b_22_0=sym_32726_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_22_1 = ReadRegBank 1:s_b_22_0 (u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_22_2: sym_148849_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_148849_1_temporary_value, s_b_22_1);
    /* execute.a64:2709 [F] s_b_22_3: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2709 [D] s_b_23_0 = sym_148849_1_temporary_value uint32_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_148849_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_23_1 = (u64)s_b_23_0 */
    auto s_b_23_1 = emitter.zx(s_b_23_0, emitter.context().types().u64());
    /* execute.a64:2695 [D] s_b_23_2 = (s32)s_b_23_1 */
    auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().s32());
    /* execute.a64:2695 [D] s_b_23_3 = (s64)s_b_23_2 */
    auto s_b_23_3 = emitter.sx(s_b_23_2, emitter.context().types().s64());
    /* execute.a64:2695 [D] s_b_23_4 = (u64)s_b_23_3 */
    auto s_b_23_4 = emitter.reinterpret(s_b_23_3, emitter.context().types().u64());
    /* execute.a64:2695 [F] s_b_23_5=sym_32726_3_parameter_inst.S (const) */
    /* execute.a64:2695 [F] s_b_23_6 = (u64)s_b_23_5 (const) */
    /* execute.a64:2695 [D] s_b_23_7 = s_b_23_4<<s_b_23_6 */
    auto s_b_23_7 = emitter.shl(s_b_23_4, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1228 [D] s_b_23_8: sym_32753_0_rm = s_b_23_7, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32753_0_rm, s_b_23_7);
    /* execute.a64:1228 [F] s_b_23_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [F] s_b_24_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_24_1: sym_149003_1_temporary_value = s_b_24_0 (const), dominates: s_b_26_0  */
    CV_sym_149003_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_149003_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_24_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_6,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2714 [F] s_b_25_0=sym_32726_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_25_1 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_25_2: sym_149003_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_149003_1_temporary_value, s_b_25_1);
    /* execute.a64:2714 [F] s_b_25_3: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_24, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2714 [D] s_b_26_0 = sym_149003_1_temporary_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_149003_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2683 [F] s_b_26_1=sym_32726_3_parameter_inst.S (const) */
    /* execute.a64:2683 [F] s_b_26_2 = (u64)s_b_26_1 (const) */
    /* execute.a64:2683 [D] s_b_26_3 = s_b_26_0<<s_b_26_2 */
    auto s_b_26_3 = emitter.shl(s_b_26_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1230 [D] s_b_26_4: sym_32753_0_rm = s_b_26_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32753_0_rm, s_b_26_3);
    /* execute.a64:1230 [F] s_b_26_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2714 [F] s_b_27_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_27_1: sym_149169_1_temporary_value = s_b_27_0 (const), dominates: s_b_29_0  */
    CV_sym_149169_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_149169_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_27_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_8,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2714 [F] s_b_28_0=sym_32726_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_28_1 = ReadRegBank 0:s_b_28_0 (u64) */
    auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_28_2: sym_149169_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_149169_1_temporary_value, s_b_28_1);
    /* execute.a64:2714 [F] s_b_28_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2714 [D] s_b_29_0 = sym_149169_1_temporary_value uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_149169_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2699 [F] s_b_29_1=sym_32726_3_parameter_inst.S (const) */
    /* execute.a64:2699 [F] s_b_29_2 = (u64)s_b_29_1 (const) */
    /* execute.a64:2699 [D] s_b_29_3 = s_b_29_0<<s_b_29_2 */
    auto s_b_29_3 = emitter.shl(s_b_29_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1232 [D] s_b_29_4: sym_32753_0_rm = s_b_29_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32753_0_rm, s_b_29_3);
    /* execute.a64:1232 [F] s_b_29_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2709 [F] s_b_30_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_30_1: sym_149254_1_temporary_value = s_b_30_0 (const), dominates: s_b_32_0  */
    CV_sym_149254_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_149254_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_30_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_15,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2709 [F] s_b_31_0=sym_32726_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_31_1 = ReadRegBank 1:s_b_31_0 (u32) */
    auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_31_2: sym_149254_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_149254_1_temporary_value, s_b_31_1);
    /* execute.a64:2709 [F] s_b_31_3: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2709 [D] s_b_32_0 = sym_149254_1_temporary_value uint32_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_149254_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_32_1 = (u64)s_b_32_0 */
    auto s_b_32_1 = emitter.zx(s_b_32_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_2 = sym_149283_1_tmp_s_b_52_2 uint64_t */
    auto s_b_32_2 = emitter.load_local(DV_sym_149283_1_tmp_s_b_52_2, emitter.context().types().u64());
    /* execute.a64:1240 [D] s_b_32_3 = (u16)s_b_32_1 */
    auto s_b_32_3 = emitter.truncate(s_b_32_1, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_32_4: Store 2 s_b_32_2 <= s_b_32_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_32_2, s_b_32_3, emitter.const_u8(2));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sturh(const arm64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_150226_1_temporary_value;
  auto DV_sym_150226_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_150255_1_tmp_s_b_19_3 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_150102_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_150119_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1384 [F] s_b_0_0=sym_33011_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_2_0=sym_33011_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_150102_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_150102_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_150102_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_150102_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1385 [F] s_b_3_1=sym_33011_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1387 [F] s_b_3_4=sym_33011_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_3_5: sym_150255_1_tmp_s_b_19_3 = s_b_3_3, dominates: s_b_11_2  */
    emitter.store_local(DV_sym_150255_1_tmp_s_b_19_3, s_b_3_3);
    /* execute.a64:2709 [F] s_b_3_6 = (u32)s_b_3_4 (const) */
    /* execute.a64:2709 [F] s_b_3_7 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_3_8 = s_b_3_6==s_b_3_7 (const) */
    uint8_t s_b_3_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_3_9: If s_b_3_8: Jump b_9 else b_10 (const) */
    if (s_b_3_8) 
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
    /* execute.a64:2765 [D] s_b_4_1: sym_150119_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_150119_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2794 [D] s_b_6_0 = sym_150119_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_150119_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_150102_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_150102_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2768 [D] s_b_7_1: sym_150119_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_150119_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2770 [D] s_b_8_1: sym_150119_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_150119_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2770 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2709 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_9_1: sym_150226_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_150226_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_150226_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2709 [F] s_b_10_0=sym_33011_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_10_1 = ReadRegBank 1:s_b_10_0 (u32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_10_2: sym_150226_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_150226_1_temporary_value, s_b_10_1);
    /* execute.a64:2709 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [D] s_b_11_0 = sym_150226_1_temporary_value uint32_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_150226_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_11_1 = (u64)s_b_11_0 */
    auto s_b_11_1 = emitter.zx(s_b_11_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_2 = sym_150255_1_tmp_s_b_19_3 uint64_t */
    auto s_b_11_2 = emitter.load_local(DV_sym_150255_1_tmp_s_b_19_3, emitter.context().types().u64());
    /* execute.a64:1387 [D] s_b_11_3 = (u16)s_b_11_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_subi(const arm64_decode_a64_ADD_SUB_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_153815_0_return_symbol;
  uint32_t CV_sym_153812_0_replaced_parameter_imm;
  auto DV_sym_153856_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_33590_0_imm;
  auto DV_sym_33595_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153950_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153967_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153990_1__R_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153921_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_154047_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153898_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:34 [F] s_b_0_0=sym_33584_3_parameter_inst.imm12 (const) */
    /* execute.a64:34 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:34 [F] s_b_0_2=sym_33584_3_parameter_inst.shift (const) */
    /* ???:4294967295 [F] s_b_0_3: sym_153812_0_replaced_parameter_imm = s_b_0_1 (const), dominates: s_b_8_0 s_b_6_0  */
    CV_sym_153812_0_replaced_parameter_imm = ((uint32_t)insn.imm12);
    /* execute.a64:2825 [F] s_b_0_4 = constant s32 0 (const) */
    /* execute.a64:2828 [F] s_b_0_5 = constant s32 1 (const) */
    /* execute.a64:2824 [F] s_b_0_6: Switch s_b_0_2: < <todo> > def b_9 (const) -> b_8, b_6, b_9,  */
    switch (insn.shift) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
      break;
    default:
      goto fixed_block_b_9;
    }
  }
  /* b_22,  */
  fixed_block_b_1: 
  {
    /* execute.a64:38 [F] s_b_1_0=sym_33584_3_parameter_inst.sf (const) */
    /* execute.a64:38 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:38 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.a64:38 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:38 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_5, b_13, b_14, b_15, b_33, b_34, b_35,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_22,  */
  fixed_block_b_3: 
  {
    /* execute.a64:44 [F] s_b_3_0=sym_33584_3_parameter_inst.sf (const) */
    /* execute.a64:44 [D] s_b_3_1 = sym_33595_0_op1 uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_33595_0_op1, emitter.context().types().u64());
    /* execute.a64:44 [F] s_b_3_2 = sym_33590_0_imm (const) uint64_t */
    uint64_t s_b_3_2 = CV_sym_33590_0_imm;
    /* execute.a64:44 [D] s_b_3_3 = s_b_3_1-s_b_3_2 */
    auto s_b_3_3 = emitter.sub(s_b_3_1, emitter.const_u64(s_b_3_2));
    /* execute.a64:44 [D] s_b_3_4: sym_153856_3_parameter_value = s_b_3_3, dominates: s_b_10_0 s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_153856_3_parameter_value, s_b_3_3);
    /* execute.a64:2809 [F] s_b_3_5 = !s_b_3_0 (const) */
    uint8_t s_b_3_5 = !insn.sf;
    /* execute.a64:2809 [F] s_b_3_6: If s_b_3_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:39 [F] s_b_4_0=sym_33584_3_parameter_inst.rd (const) */
    /* execute.a64:39 [D] s_b_4_1 = sym_33595_0_op1 uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_33595_0_op1, emitter.context().types().u64());
    /* execute.a64:39 [D] s_b_4_2 = (u32)s_b_4_1 */
    auto s_b_4_2 = emitter.truncate(s_b_4_1, emitter.context().types().u32());
    /* execute.a64:39 [F] s_b_4_3 = sym_33590_0_imm (const) uint64_t */
    uint64_t s_b_4_3 = CV_sym_33590_0_imm;
    /* execute.a64:39 [F] s_b_4_4 = (u32)s_b_4_3 (const) */
    /* execute.a64:39 [F] s_b_4_5 = constant u8 0 (const) */
    /* execute.a64:39 [D] s_b_4_6 = __builtin_sbc32_flags */
    auto s_b_4_6 = emitter.sbcf(s_b_4_2, emitter.const_u32(((uint32_t)s_b_4_3)), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:39 [D] s_b_4_7: sym_153898_3_parameter_value = s_b_4_6, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_153898_3_parameter_value, s_b_4_6);
    /* execute.a64:2737 [F] s_b_4_8 = (u32)s_b_4_0 (const) */
    /* execute.a64:2737 [F] s_b_4_9 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_4_10 = s_b_4_8==s_b_4_9 (const) */
    uint8_t s_b_4_10 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_4_11: If s_b_4_10: Jump b_2 else b_14 (const) */
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
    /* execute.a64:41 [F] s_b_5_0=sym_33584_3_parameter_inst.rd (const) */
    /* execute.a64:41 [D] s_b_5_1 = sym_33595_0_op1 uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_33595_0_op1, emitter.context().types().u64());
    /* execute.a64:41 [F] s_b_5_2 = sym_33590_0_imm (const) uint64_t */
    uint64_t s_b_5_2 = CV_sym_33590_0_imm;
    /* execute.a64:41 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.a64:41 [D] s_b_5_4 = __builtin_sbc64_flags */
    auto s_b_5_4 = emitter.sbcf(s_b_5_1, emitter.const_u64(s_b_5_2), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:41 [D] s_b_5_5: sym_153921_3_parameter_value = s_b_5_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_153921_3_parameter_value, s_b_5_4);
    /* execute.a64:2745 [F] s_b_5_6 = (u32)s_b_5_0 (const) */
    /* execute.a64:2745 [F] s_b_5_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_5_8 = s_b_5_6==s_b_5_7 (const) */
    uint8_t s_b_5_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_5_9: If s_b_5_8: Jump b_2 else b_15 (const) */
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
    /* execute.a64:2826 [F] s_b_6_0 = sym_153812_0_replaced_parameter_imm (const) uint32_t */
    uint32_t s_b_6_0 = CV_sym_153812_0_replaced_parameter_imm;
    /* execute.a64:2826 [F] s_b_6_1 = (u64)s_b_6_0 (const) */
    /* ???:4294967295 [F] s_b_6_2: sym_153815_0_return_symbol = s_b_6_1 (const), dominates: s_b_7_0  */
    CV_sym_153815_0_return_symbol = ((uint64_t)s_b_6_0);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_8, b_9,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [F] s_b_7_0 = sym_153815_0_return_symbol (const) uint64_t */
    uint64_t s_b_7_0 = CV_sym_153815_0_return_symbol;
    /* execute.a64:34 [F] s_b_7_1: sym_33590_0_imm = s_b_7_0 (const), dominates: s_b_4_3 s_b_5_2 s_b_3_2  */
    CV_sym_33590_0_imm = s_b_7_0;
    /* execute.a64:35 [F] s_b_7_2=sym_33584_3_parameter_inst.sf (const) */
    /* execute.a64:2792 [F] s_b_7_3: If s_b_7_2: Jump b_16 else b_19 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2829 [F] s_b_8_0 = sym_153812_0_replaced_parameter_imm (const) uint32_t */
    uint32_t s_b_8_0 = CV_sym_153812_0_replaced_parameter_imm;
    /* execute.a64:2829 [F] s_b_8_1 = constant u32 c (const) */
    /* execute.a64:2829 [F] s_b_8_2 = s_b_8_0<<s_b_8_1 (const) */
    uint32_t s_b_8_2 = ((uint32_t)(s_b_8_0 << (uint32_t)12ULL));
    /* execute.a64:2829 [F] s_b_8_3 = (u64)s_b_8_2 (const) */
    /* ???:4294967295 [F] s_b_8_4: sym_153815_0_return_symbol = s_b_8_3 (const), dominates: s_b_7_0  */
    CV_sym_153815_0_return_symbol = ((uint64_t)s_b_8_2);
    /* ???:4294967295 [F] s_b_8_5: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2832 [F] s_b_9_0 = constant u64 0 (const) */
    /* ???:4294967295 [F] s_b_9_1: sym_153815_0_return_symbol = s_b_9_0 (const), dominates: s_b_7_0  */
    CV_sym_153815_0_return_symbol = (uint64_t)0ULL;
    /* ???:4294967295 [F] s_b_9_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2810 [D] s_b_10_0 = sym_153856_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_153856_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_10_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_10_2 = s_b_10_0&s_b_10_1 */
    auto s_b_10_2 = emitter.bitwise_and(s_b_10_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_10_3: sym_153856_3_parameter_value = s_b_10_2, dominates: s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_153856_3_parameter_value, s_b_10_2);
    /* execute.a64:2810 [F] s_b_10_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2813 [F] s_b_11_0=sym_33584_3_parameter_inst.rd (const) */
    /* execute.a64:2813 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2813 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_11_4: If s_b_11_3: Jump b_12 else b_13 (const) */
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
    /* execute.a64:2814 [D] s_b_12_0 = sym_153856_3_parameter_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_153856_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_12_1: sym_154047_3_parameter_value = s_b_12_0, dominates: s_b_33_0 s_b_34_0 s_b_35_0  */
    emitter.store_local(DV_sym_154047_3_parameter_value, s_b_12_0);
    /* execute.a64:2777 [F] s_b_12_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_12_3 = __builtin_get_feature */
    uint32_t s_b_12_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(s_b_12_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_12_6: If s_b_12_5: Jump b_33 else b_36 (const) */
    if (s_b_12_5) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_36;
    }
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2816 [F] s_b_13_0=sym_33584_3_parameter_inst.rd (const) */
    /* execute.a64:2816 [D] s_b_13_1 = sym_153856_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_153856_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1);
    /* execute.a64:2816 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2739 [F] s_b_14_0=sym_33584_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_14_1 = sym_153898_3_parameter_value uint32_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_153898_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_14_2 = (u64)s_b_14_1 */
    auto s_b_14_2 = emitter.zx(s_b_14_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_14_3: WriteRegBank 0:s_b_14_0 = s_b_14_2 */
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
    /* execute.a64:2747 [F] s_b_15_0=sym_33584_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_15_1 = sym_153921_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_153921_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1);
    /* execute.a64:0 [F] s_b_15_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2793 [F] s_b_16_0=sym_33584_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2793 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
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
    /* execute.a64:2764 [F] s_b_17_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_17_1 = __builtin_get_feature */
    uint32_t s_b_17_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(s_b_17_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_17_4: If s_b_17_3: Jump b_23 else b_24 (const) */
    if (s_b_17_3) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2796 [F] s_b_18_0=sym_33584_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_18_2: sym_153950_0_return_symbol = s_b_18_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_153950_0_return_symbol, s_b_18_1);
    /* ???:4294967295 [F] s_b_18_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_7,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2799 [F] s_b_19_0=sym_33584_3_parameter_inst.rn (const) */
    /* execute.a64:2799 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2799 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2799 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2799 [F] s_b_19_4: If s_b_19_3: Jump b_20 else b_21 (const) */
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
    /* execute.a64:2764 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_20_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_20_4: If s_b_20_3: Jump b_28 else b_29 (const) */
    if (s_b_20_3) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_19,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2802 [F] s_b_21_0=sym_33584_3_parameter_inst.rn (const) */
    /* execute.a64:2802 [D] s_b_21_1 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_1,emitter.const_u8(4));
    }
    /* execute.a64:2802 [D] s_b_21_2 = (u64)s_b_21_1 */
    auto s_b_21_2 = emitter.zx(s_b_21_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_3: sym_153950_0_return_symbol = s_b_21_2, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_153950_0_return_symbol, s_b_21_2);
    /* ???:4294967295 [F] s_b_21_4: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_18, b_21, b_25, b_30,  */
  fixed_block_b_22: 
  {
    /* ???:4294967295 [D] s_b_22_0 = sym_153950_0_return_symbol uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_153950_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:35 [D] s_b_22_1: sym_33595_0_op1 = s_b_22_0, dominates: s_b_4_1 s_b_5_1 s_b_3_1  */
    emitter.store_local(DV_sym_33595_0_op1, s_b_22_0);
    /* execute.a64:37 [F] s_b_22_2=sym_33584_3_parameter_inst.S (const) */
    /* execute.a64:37 [F] s_b_22_3: If s_b_22_2: Jump b_1 else b_3 (const) */
    if (insn.S) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_17,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2765 [D] s_b_23_0 = ReadReg 21 (u64) */
    auto s_b_23_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_23_1: sym_153967_1__R_s_b_3_0 = s_b_23_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_153967_1__R_s_b_3_0, s_b_23_0);
    /* execute.a64:2765 [F] s_b_23_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_17,  */
  fixed_block_b_24: 
  {
    /* execute.a64:3075 [F] s_b_24_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_24_1 = __builtin_get_feature */
    uint32_t s_b_24_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_24_2 = (u8)s_b_24_1 (const) */
    /* execute.a64:2767 [F] s_b_24_3 = (u32)s_b_24_2 (const) */
    /* execute.a64:2767 [F] s_b_24_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_24_5 = s_b_24_3==s_b_24_4 (const) */
    uint8_t s_b_24_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_24_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_24_6: If s_b_24_5: Jump b_26 else b_27 (const) */
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
    /* execute.a64:2794 [D] s_b_25_0 = sym_153967_1__R_s_b_3_0 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_153967_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_25_1: sym_153950_0_return_symbol = s_b_25_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_153950_0_return_symbol, s_b_25_0);
    /* ???:4294967295 [F] s_b_25_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_24,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2768 [D] s_b_26_0 = ReadReg 21 (u64) */
    auto s_b_26_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_26_1: sym_153967_1__R_s_b_3_0 = s_b_26_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_153967_1__R_s_b_3_0, s_b_26_0);
    /* execute.a64:2768 [F] s_b_26_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_24,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2770 [D] s_b_27_0 = ReadReg 22 (u64) */
    auto s_b_27_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_27_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_27_1: sym_153967_1__R_s_b_3_0 = s_b_27_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_153967_1__R_s_b_3_0, s_b_27_0);
    /* execute.a64:2770 [F] s_b_27_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_20,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2765 [D] s_b_28_0 = ReadReg 21 (u64) */
    auto s_b_28_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_28_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_28_1: sym_153990_1__R_s_b_5_0 = s_b_28_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_153990_1__R_s_b_5_0, s_b_28_0);
    /* execute.a64:2765 [F] s_b_28_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_20,  */
  fixed_block_b_29: 
  {
    /* execute.a64:3075 [F] s_b_29_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_29_1 = __builtin_get_feature */
    uint32_t s_b_29_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_29_2 = (u8)s_b_29_1 (const) */
    /* execute.a64:2767 [F] s_b_29_3 = (u32)s_b_29_2 (const) */
    /* execute.a64:2767 [F] s_b_29_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_29_5 = s_b_29_3==s_b_29_4 (const) */
    uint8_t s_b_29_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_29_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_29_6: If s_b_29_5: Jump b_31 else b_32 (const) */
    if (s_b_29_5) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_28, b_31, b_32,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2800 [D] s_b_30_0 = sym_153990_1__R_s_b_5_0 uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_153990_1__R_s_b_5_0, emitter.context().types().u64());
    /* execute.a64:2800 [D] s_b_30_1 = (u32)s_b_30_0 */
    auto s_b_30_1 = emitter.truncate(s_b_30_0, emitter.context().types().u32());
    /* execute.a64:2800 [D] s_b_30_2 = (u64)s_b_30_1 */
    auto s_b_30_2 = emitter.zx(s_b_30_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_30_3: sym_153950_0_return_symbol = s_b_30_2, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_153950_0_return_symbol, s_b_30_2);
    /* ???:4294967295 [F] s_b_30_4: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_29,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2768 [D] s_b_31_0 = ReadReg 21 (u64) */
    auto s_b_31_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_31_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_31_1: sym_153990_1__R_s_b_5_0 = s_b_31_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_153990_1__R_s_b_5_0, s_b_31_0);
    /* execute.a64:2768 [F] s_b_31_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_29,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2770 [D] s_b_32_0 = ReadReg 22 (u64) */
    auto s_b_32_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_32_1: sym_153990_1__R_s_b_5_0 = s_b_32_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_153990_1__R_s_b_5_0, s_b_32_0);
    /* execute.a64:2770 [F] s_b_32_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_12,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2778 [D] s_b_33_0 = sym_154047_3_parameter_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_154047_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_33_1: WriteReg 21 = s_b_33_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_33_0);
    /* execute.a64:2778 [F] s_b_33_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_36,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2781 [D] s_b_34_0 = sym_154047_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_154047_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_34_1: WriteReg 21 = s_b_34_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_34_0);
    /* execute.a64:2781 [F] s_b_34_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_36,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2783 [D] s_b_35_0 = sym_154047_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_154047_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_35_1: WriteReg 22 = s_b_35_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_35_0);
    /* execute.a64:2783 [F] s_b_35_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_36: 
  {
    /* execute.a64:3075 [F] s_b_36_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_36_1 = __builtin_get_feature */
    uint32_t s_b_36_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_36_2 = (u8)s_b_36_1 (const) */
    /* execute.a64:2780 [F] s_b_36_3 = (u32)s_b_36_2 (const) */
    /* execute.a64:2780 [F] s_b_36_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_36_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_36_6: If s_b_36_5: Jump b_34 else b_35 (const) */
    if (s_b_36_5) 
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_uaddlv(const arm64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_umaxv(const arm64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ushr(const arm64_decode_a64_SIMD_SHIFT_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4824 [F] s_b_0_0=sym_44883_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4824 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4825 [F] s_b_1_0=sym_44883_3_parameter_inst.immh (const) */
    /* execute.simd:4825 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4825 [F] s_b_1_2 = constant u32 3 (const) */
    /* execute.simd:4825 [F] s_b_1_3 = s_b_1_1<<s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4825 [F] s_b_1_4=sym_44883_3_parameter_inst.immb (const) */
    /* execute.simd:4825 [F] s_b_1_5 = (u32)s_b_1_4 (const) */
    /* execute.simd:4825 [F] s_b_1_6 = s_b_1_3|s_b_1_5 (const) */
    uint32_t s_b_1_6 = ((uint32_t)(s_b_1_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4825 [F] s_b_1_7 = constant u32 80 (const) */
    /* execute.simd:4825 [F] s_b_1_8 = s_b_1_7-s_b_1_6 (const) */
    uint32_t s_b_1_8 = ((uint32_t)((uint32_t)128ULL - s_b_1_6));
    /* execute.simd:4825 [F] s_b_1_9 = (u64)s_b_1_8 (const) */
    /* execute.simd:4826 [F] s_b_1_10=sym_44883_3_parameter_inst.rd (const) */
    /* execute.simd:4826 [F] s_b_1_11=sym_44883_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_12 = ReadRegBank 7:s_b_1_11 (u64) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_12,emitter.const_u8(8));
    }
    /* execute.simd:4826 [D] s_b_1_13 = s_b_1_12>>s_b_1_9 */
    auto s_b_1_13 = emitter.shr(s_b_1_12, emitter.const_u64(((uint64_t)s_b_1_8)));
    /* execute.simd:6326 [D] s_b_1_14: WriteRegBank 2:s_b_1_10 = s_b_1_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13);
    /* execute.simd:6327 [F] s_b_1_15 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_16: WriteRegBank 3:s_b_1_10 = s_b_1_15 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_17: Jump b_2 (const) */
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
    /* execute.simd:4828 [F] s_b_3_0=sym_44883_3_parameter_inst.arrangement (const) */
    /* execute.simd:4829 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:4837 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:4844 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:4852 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:4859 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:4867 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:4874 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:4828 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
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
    /* execute.simd:4830 [F] s_b_4_0=sym_44883_3_parameter_inst.immh (const) */
    /* execute.simd:4830 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4830 [F] s_b_4_2 = constant u32 3 (const) */
    /* execute.simd:4830 [F] s_b_4_3 = s_b_4_1<<s_b_4_2 (const) */
    uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4830 [F] s_b_4_4=sym_44883_3_parameter_inst.immb (const) */
    /* execute.simd:4830 [F] s_b_4_5 = (u32)s_b_4_4 (const) */
    /* execute.simd:4830 [F] s_b_4_6 = s_b_4_3|s_b_4_5 (const) */
    uint32_t s_b_4_6 = ((uint32_t)(s_b_4_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4830 [F] s_b_4_7 = constant u32 10 (const) */
    /* execute.simd:4830 [F] s_b_4_8 = s_b_4_7-s_b_4_6 (const) */
    uint32_t s_b_4_8 = ((uint32_t)((uint32_t)16ULL - s_b_4_6));
    /* execute.simd:4830 [F] s_b_4_9 = (u64)s_b_4_8 (const) */
    /* execute.simd:4832 [F] s_b_4_10=sym_44883_3_parameter_inst.rn (const) */
    /* execute.simd:4832 [D] s_b_4_11 = ReadRegBank 15:s_b_4_10 (v8u8) */
    auto s_b_4_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_11,emitter.const_u8(8));
    }
    /* execute.simd:4833 [F] s_b_4_12=sym_44883_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_4_13 = (v8u8)s_b_4_9 (const) */
    auto s_b_4_13 = wutils::Vector<uint8_t, 8>(((uint64_t)s_b_4_8));
    /* execute.simd:4833 [D] s_b_4_14 = s_b_4_11>>s_b_4_13 */
    auto s_b_4_14 = emitter.shr(s_b_4_11, emitter.constant_vector_splat(s_b_4_13[0], emitter.context().types().v8u8()));
    /* execute.simd:4833 [D] s_b_4_15: WriteRegBank 15:s_b_4_12 = s_b_4_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_14,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_14);
    /* execute.simd:4834 [F] s_b_4_16=sym_44883_3_parameter_inst.rd (const) */
    /* execute.simd:4834 [F] s_b_4_17 = constant u64 0 (const) */
    /* execute.simd:4834 [F] s_b_4_18: WriteRegBank 3:s_b_4_16 = s_b_4_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_19: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4838 [F] s_b_5_0=sym_44883_3_parameter_inst.immh (const) */
    /* execute.simd:4838 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4838 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.simd:4838 [F] s_b_5_3 = s_b_5_1<<s_b_5_2 (const) */
    uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4838 [F] s_b_5_4=sym_44883_3_parameter_inst.immb (const) */
    /* execute.simd:4838 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4838 [F] s_b_5_6 = s_b_5_3|s_b_5_5 (const) */
    uint32_t s_b_5_6 = ((uint32_t)(s_b_5_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4838 [F] s_b_5_7 = constant u32 10 (const) */
    /* execute.simd:4838 [F] s_b_5_8 = s_b_5_7-s_b_5_6 (const) */
    uint32_t s_b_5_8 = ((uint32_t)((uint32_t)16ULL - s_b_5_6));
    /* execute.simd:4838 [F] s_b_5_9 = (u64)s_b_5_8 (const) */
    /* execute.simd:4840 [F] s_b_5_10=sym_44883_3_parameter_inst.rn (const) */
    /* execute.simd:4840 [D] s_b_5_11 = ReadRegBank 16:s_b_5_10 (v16u8) */
    auto s_b_5_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_11,emitter.const_u8(16));
    }
    /* execute.simd:4841 [F] s_b_5_12=sym_44883_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_5_13 = (v16u8)s_b_5_9 (const) */
    auto s_b_5_13 = wutils::Vector<uint8_t, 16>(((uint64_t)s_b_5_8));
    /* execute.simd:4841 [D] s_b_5_14 = s_b_5_11>>s_b_5_13 */
    auto s_b_5_14 = emitter.shr(s_b_5_11, emitter.constant_vector_splat(s_b_5_13[0], emitter.context().types().v16u8()));
    /* execute.simd:4841 [D] s_b_5_15: WriteRegBank 16:s_b_5_12 = s_b_5_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_14,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_14);
    /* execute.simd:0 [F] s_b_5_16: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4845 [F] s_b_6_0=sym_44883_3_parameter_inst.immh (const) */
    /* execute.simd:4845 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.simd:4845 [F] s_b_6_2 = constant u32 3 (const) */
    /* execute.simd:4845 [F] s_b_6_3 = s_b_6_1<<s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4845 [F] s_b_6_4=sym_44883_3_parameter_inst.immb (const) */
    /* execute.simd:4845 [F] s_b_6_5 = (u32)s_b_6_4 (const) */
    /* execute.simd:4845 [F] s_b_6_6 = s_b_6_3|s_b_6_5 (const) */
    uint32_t s_b_6_6 = ((uint32_t)(s_b_6_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4845 [F] s_b_6_7 = constant u32 20 (const) */
    /* execute.simd:4845 [F] s_b_6_8 = s_b_6_7-s_b_6_6 (const) */
    uint32_t s_b_6_8 = ((uint32_t)((uint32_t)32ULL - s_b_6_6));
    /* execute.simd:4845 [F] s_b_6_9 = (u64)s_b_6_8 (const) */
    /* execute.simd:4847 [F] s_b_6_10=sym_44883_3_parameter_inst.rn (const) */
    /* execute.simd:4847 [D] s_b_6_11 = ReadRegBank 17:s_b_6_10 (v4u16) */
    auto s_b_6_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_11,emitter.const_u8(8));
    }
    /* execute.simd:4848 [F] s_b_6_12=sym_44883_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_6_13 = (v4u16)s_b_6_9 (const) */
    auto s_b_6_13 = wutils::Vector<uint16_t, 4>(((uint64_t)s_b_6_8));
    /* execute.simd:4848 [D] s_b_6_14 = s_b_6_11>>s_b_6_13 */
    auto s_b_6_14 = emitter.shr(s_b_6_11, emitter.constant_vector_splat(s_b_6_13[0], emitter.context().types().v4u16()));
    /* execute.simd:4848 [D] s_b_6_15: WriteRegBank 17:s_b_6_12 = s_b_6_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_14,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_14);
    /* execute.simd:4849 [F] s_b_6_16=sym_44883_3_parameter_inst.rd (const) */
    /* execute.simd:4849 [F] s_b_6_17 = constant u64 0 (const) */
    /* execute.simd:4849 [F] s_b_6_18: WriteRegBank 3:s_b_6_16 = s_b_6_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_19: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4853 [F] s_b_7_0=sym_44883_3_parameter_inst.immh (const) */
    /* execute.simd:4853 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4853 [F] s_b_7_2 = constant u32 3 (const) */
    /* execute.simd:4853 [F] s_b_7_3 = s_b_7_1<<s_b_7_2 (const) */
    uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4853 [F] s_b_7_4=sym_44883_3_parameter_inst.immb (const) */
    /* execute.simd:4853 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4853 [F] s_b_7_6 = s_b_7_3|s_b_7_5 (const) */
    uint32_t s_b_7_6 = ((uint32_t)(s_b_7_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4853 [F] s_b_7_7 = constant u32 20 (const) */
    /* execute.simd:4853 [F] s_b_7_8 = s_b_7_7-s_b_7_6 (const) */
    uint32_t s_b_7_8 = ((uint32_t)((uint32_t)32ULL - s_b_7_6));
    /* execute.simd:4853 [F] s_b_7_9 = (u64)s_b_7_8 (const) */
    /* execute.simd:4855 [F] s_b_7_10=sym_44883_3_parameter_inst.rn (const) */
    /* execute.simd:4855 [D] s_b_7_11 = ReadRegBank 18:s_b_7_10 (v8u16) */
    auto s_b_7_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_11,emitter.const_u8(16));
    }
    /* execute.simd:4856 [F] s_b_7_12=sym_44883_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_7_13 = (v8u16)s_b_7_9 (const) */
    auto s_b_7_13 = wutils::Vector<uint16_t, 8>(((uint64_t)s_b_7_8));
    /* execute.simd:4856 [D] s_b_7_14 = s_b_7_11>>s_b_7_13 */
    auto s_b_7_14 = emitter.shr(s_b_7_11, emitter.constant_vector_splat(s_b_7_13[0], emitter.context().types().v8u16()));
    /* execute.simd:4856 [D] s_b_7_15: WriteRegBank 18:s_b_7_12 = s_b_7_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_14,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_14);
    /* execute.simd:0 [F] s_b_7_16: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4860 [F] s_b_8_0=sym_44883_3_parameter_inst.immh (const) */
    /* execute.simd:4860 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.simd:4860 [F] s_b_8_2 = constant u32 3 (const) */
    /* execute.simd:4860 [F] s_b_8_3 = s_b_8_1<<s_b_8_2 (const) */
    uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4860 [F] s_b_8_4=sym_44883_3_parameter_inst.immb (const) */
    /* execute.simd:4860 [F] s_b_8_5 = (u32)s_b_8_4 (const) */
    /* execute.simd:4860 [F] s_b_8_6 = s_b_8_3|s_b_8_5 (const) */
    uint32_t s_b_8_6 = ((uint32_t)(s_b_8_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4860 [F] s_b_8_7 = constant u32 40 (const) */
    /* execute.simd:4860 [F] s_b_8_8 = s_b_8_7-s_b_8_6 (const) */
    uint32_t s_b_8_8 = ((uint32_t)((uint32_t)64ULL - s_b_8_6));
    /* execute.simd:4860 [F] s_b_8_9 = (u64)s_b_8_8 (const) */
    /* execute.simd:4862 [F] s_b_8_10=sym_44883_3_parameter_inst.rn (const) */
    /* execute.simd:4862 [D] s_b_8_11 = ReadRegBank 19:s_b_8_10 (v2u32) */
    auto s_b_8_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_11,emitter.const_u8(8));
    }
    /* execute.simd:4863 [F] s_b_8_12=sym_44883_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_8_13 = (v2u32)s_b_8_9 (const) */
    auto s_b_8_13 = wutils::Vector<uint32_t, 2>(((uint64_t)s_b_8_8));
    /* execute.simd:4863 [D] s_b_8_14 = s_b_8_11>>s_b_8_13 */
    auto s_b_8_14 = emitter.shr(s_b_8_11, emitter.constant_vector_splat(s_b_8_13[0], emitter.context().types().v2u32()));
    /* execute.simd:4863 [D] s_b_8_15: WriteRegBank 19:s_b_8_12 = s_b_8_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_14,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_14);
    /* execute.simd:4864 [F] s_b_8_16=sym_44883_3_parameter_inst.rd (const) */
    /* execute.simd:4864 [F] s_b_8_17 = constant u64 0 (const) */
    /* execute.simd:4864 [F] s_b_8_18: WriteRegBank 3:s_b_8_16 = s_b_8_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_19: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4868 [F] s_b_9_0=sym_44883_3_parameter_inst.immh (const) */
    /* execute.simd:4868 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4868 [F] s_b_9_2 = constant u32 3 (const) */
    /* execute.simd:4868 [F] s_b_9_3 = s_b_9_1<<s_b_9_2 (const) */
    uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4868 [F] s_b_9_4=sym_44883_3_parameter_inst.immb (const) */
    /* execute.simd:4868 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4868 [F] s_b_9_6 = s_b_9_3|s_b_9_5 (const) */
    uint32_t s_b_9_6 = ((uint32_t)(s_b_9_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4868 [F] s_b_9_7 = constant u32 40 (const) */
    /* execute.simd:4868 [F] s_b_9_8 = s_b_9_7-s_b_9_6 (const) */
    uint32_t s_b_9_8 = ((uint32_t)((uint32_t)64ULL - s_b_9_6));
    /* execute.simd:4868 [F] s_b_9_9 = (u64)s_b_9_8 (const) */
    /* execute.simd:4870 [F] s_b_9_10=sym_44883_3_parameter_inst.rn (const) */
    /* execute.simd:4870 [D] s_b_9_11 = ReadRegBank 20:s_b_9_10 (v4u32) */
    auto s_b_9_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_11,emitter.const_u8(16));
    }
    /* execute.simd:4871 [F] s_b_9_12=sym_44883_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_9_13 = (v4u32)s_b_9_9 (const) */
    auto s_b_9_13 = wutils::Vector<uint32_t, 4>(((uint64_t)s_b_9_8));
    /* execute.simd:4871 [D] s_b_9_14 = s_b_9_11>>s_b_9_13 */
    auto s_b_9_14 = emitter.shr(s_b_9_11, emitter.constant_vector_splat(s_b_9_13[0], emitter.context().types().v4u32()));
    /* execute.simd:4871 [D] s_b_9_15: WriteRegBank 20:s_b_9_12 = s_b_9_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_14,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_14);
    /* execute.simd:0 [F] s_b_9_16: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4875 [F] s_b_10_0=sym_44883_3_parameter_inst.immh (const) */
    /* execute.simd:4875 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4875 [F] s_b_10_2 = constant u32 3 (const) */
    /* execute.simd:4875 [F] s_b_10_3 = s_b_10_1<<s_b_10_2 (const) */
    uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4875 [F] s_b_10_4=sym_44883_3_parameter_inst.immb (const) */
    /* execute.simd:4875 [F] s_b_10_5 = (u32)s_b_10_4 (const) */
    /* execute.simd:4875 [F] s_b_10_6 = s_b_10_3|s_b_10_5 (const) */
    uint32_t s_b_10_6 = ((uint32_t)(s_b_10_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4875 [F] s_b_10_7 = constant u32 80 (const) */
    /* execute.simd:4875 [F] s_b_10_8 = s_b_10_7-s_b_10_6 (const) */
    uint32_t s_b_10_8 = ((uint32_t)((uint32_t)128ULL - s_b_10_6));
    /* execute.simd:4875 [F] s_b_10_9 = (u64)s_b_10_8 (const) */
    /* execute.simd:4877 [F] s_b_10_10=sym_44883_3_parameter_inst.rn (const) */
    /* execute.simd:4877 [D] s_b_10_11 = ReadRegBank 21:s_b_10_10 (v2u64) */
    auto s_b_10_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_11,emitter.const_u8(16));
    }
    /* execute.simd:4878 [F] s_b_10_12=sym_44883_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_10_13 = (v2u64)s_b_10_9 (const) */
    auto s_b_10_13 = wutils::Vector<uint64_t, 2>(((uint64_t)s_b_10_8));
    /* execute.simd:4878 [D] s_b_10_14 = s_b_10_11>>s_b_10_13 */
    auto s_b_10_14 = emitter.shr(s_b_10_11, emitter.constant_vector_splat(s_b_10_13[0], emitter.context().types().v2u64()));
    /* execute.simd:4878 [D] s_b_10_15: WriteRegBank 21:s_b_10_12 = s_b_10_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_14,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_14);
    /* execute.simd:0 [F] s_b_10_16: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_vstur(const arm64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_159853_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_159759_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_159776_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3988 [F] s_b_0_0=sym_47596_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_2_0=sym_47596_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_159759_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_159759_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_159759_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_159759_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:3989 [F] s_b_3_1=sym_47596_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.simd:3991 [F] s_b_3_4=sym_47596_3_parameter_inst.size (const) */
    /* execute.simd:3991 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:3991 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:3991 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:3991 [F] s_b_3_8=sym_47596_3_parameter_inst.opc (const) */
    /* execute.simd:3991 [F] s_b_3_9 = (u32)s_b_3_8 (const) */
    /* execute.simd:3991 [F] s_b_3_10 = constant u32 0 (const) */
    /* execute.simd:3991 [F] s_b_3_11 = s_b_3_9==s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.simd:3991 [F] s_b_3_12 = constant u8 0 (const) */
    /* execute.simd:3991 [F] s_b_3_13 = constant u8 4 (const) */
    /* execute.simd:3991 [F] s_b_3_14: Select s_b_3_11 ? s_b_3_12 : s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(s_b_3_11 ? ((uint8_t)0ULL) : ((uint8_t)4ULL)));
    /* execute.simd:3991 [F] s_b_3_15=sym_47596_3_parameter_inst.size (const) */
    /* execute.simd:3991 [F] s_b_3_16 = (u8)s_b_3_15 (const) */
    /* execute.simd:3991 [F] s_b_3_17: Select s_b_3_7 ? s_b_3_14 : s_b_3_16 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(s_b_3_7 ? (s_b_3_14) : (((uint8_t)insn.size))));
    /* ???:4294967295 [D] s_b_3_18: sym_159853_0_replaced_parameter_addr = s_b_3_3, dominates: s_b_9_2 s_b_11_2 s_b_13_3 s_b_12_2 s_b_10_2  */
    emitter.store_local(DV_sym_159853_0_replaced_parameter_addr, s_b_3_3);
    /* execute.simd:3723 [F] s_b_3_19 = constant s32 0 (const) */
    /* execute.simd:3729 [F] s_b_3_20 = constant s32 1 (const) */
    /* execute.simd:3735 [F] s_b_3_21 = constant s32 2 (const) */
    /* execute.simd:3741 [F] s_b_3_22 = constant s32 3 (const) */
    /* execute.simd:3747 [F] s_b_3_23 = constant s32 4 (const) */
    /* execute.simd:3722 [F] s_b_3_24: Switch s_b_3_17: < <todo> > def b_14 (const) -> b_9, b_11, b_14, b_13, b_12, b_10,  */
    switch (s_b_3_17) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_10;
      break;
    default:
      goto fixed_block_b_14;
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
    /* execute.a64:2765 [D] s_b_4_1: sym_159776_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_159776_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2794 [D] s_b_6_0 = sym_159776_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_159776_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_159759_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_159759_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2768 [D] s_b_7_1: sym_159776_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_159776_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2770 [D] s_b_8_1: sym_159776_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_159776_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2770 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3725 [F] s_b_9_0=sym_47596_3_parameter_inst.rt (const) */
    /* execute.simd:6340 [D] s_b_9_1 = ReadRegBank 4:s_b_9_0 (u8) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_1,emitter.const_u8(1));
    }
    /* execute.simd:3726 [D] s_b_9_2 = sym_159853_0_replaced_parameter_addr uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_159853_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_3: Store 1 s_b_9_2 <= s_b_9_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_9_2, s_b_9_1, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_9_2, s_b_9_1);
    /* execute.simd:0 [F] s_b_9_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3731 [F] s_b_10_0=sym_47596_3_parameter_inst.rt (const) */
    /* execute.simd:6345 [D] s_b_10_1 = ReadRegBank 5:s_b_10_0 (u16) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_1,emitter.const_u8(2));
    }
    /* execute.simd:3732 [D] s_b_10_2 = sym_159853_0_replaced_parameter_addr uint64_t */
    auto s_b_10_2 = emitter.load_local(DV_sym_159853_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_3: Store 2 s_b_10_2 <= s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_10_2, s_b_10_1, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_10_2, s_b_10_1);
    /* execute.simd:0 [F] s_b_10_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3737 [F] s_b_11_0=sym_47596_3_parameter_inst.rt (const) */
    /* execute.simd:6350 [D] s_b_11_1 = ReadRegBank 6:s_b_11_0 (u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_11_1,emitter.const_u8(4));
    }
    /* execute.simd:3738 [D] s_b_11_2 = sym_159853_0_replaced_parameter_addr uint64_t */
    auto s_b_11_2 = emitter.load_local(DV_sym_159853_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_3: Store 4 s_b_11_2 <= s_b_11_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_11_2, s_b_11_1, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_11_2, s_b_11_1);
    /* execute.simd:0 [F] s_b_11_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3743 [F] s_b_12_0=sym_47596_3_parameter_inst.rt (const) */
    /* execute.simd:6355 [D] s_b_12_1 = ReadRegBank 7:s_b_12_0 (u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:3744 [D] s_b_12_2 = sym_159853_0_replaced_parameter_addr uint64_t */
    auto s_b_12_2 = emitter.load_local(DV_sym_159853_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_3: Store 8 s_b_12_2 <= s_b_12_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_12_2, s_b_12_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_12_2, s_b_12_1);
    /* execute.simd:0 [F] s_b_12_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_3,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3751 [F] s_b_13_0=sym_47596_3_parameter_inst.rt (const) */
    /* execute.simd:6360 [D] s_b_13_1 = ReadRegBank 2:s_b_13_0 (u64) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_13_2 = ReadRegBank 3:s_b_13_0 (u64) */
    auto s_b_13_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_2,emitter.const_u8(8));
    }
    /* execute.simd:3752 [D] s_b_13_3 = sym_159853_0_replaced_parameter_addr uint64_t */
    auto s_b_13_3 = emitter.load_local(DV_sym_159853_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_4: Store 8 s_b_13_3 <= s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_13_3, s_b_13_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_13_3, s_b_13_1);
    /* execute.simd:3753 [F] s_b_13_5 = constant u64 8 (const) */
    /* execute.simd:3753 [D] s_b_13_6 = s_b_13_3+s_b_13_5 */
    auto s_b_13_6 = emitter.add(s_b_13_3, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_13_7: Store 8 s_b_13_6 <= s_b_13_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_13_6, s_b_13_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_13_6, s_b_13_2);
    /* execute.simd:0 [F] s_b_13_8: Jump b_14 (const) */
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
