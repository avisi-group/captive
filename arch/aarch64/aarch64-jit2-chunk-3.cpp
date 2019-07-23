#include <aarch64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::aarch64;
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_add_sreg(const aarch64_decode_a64_ADD_SUB_SREG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_47714_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_47990_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48017_1__R_s_b_29_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_47894_1__R_s_b_13_10;
  auto DV_sym_47894_1__R_s_b_13_10 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_47924_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48042_1__R_s_b_32_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48108_1__R_s_b_35_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_48083_1__R_s_b_33_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_3491_0_result = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_3465_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3448_0_op2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_3441_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1903 [F] s_b_0_0=sym_3436_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_10 else b_11 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_22,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1909 [F] s_b_1_0=sym_3436_3_parameter_inst.S (const) */
    /* execute.a64:1909 [F] s_b_1_1: If s_b_1_0: Jump b_4 else b_6 (const) */
    if (insn.S) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_5, b_8, b_23, b_24,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_22,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1919 [F] s_b_3_0=sym_3436_3_parameter_inst.S (const) */
    /* execute.a64:1919 [F] s_b_3_1: If s_b_3_0: Jump b_7 else b_9 (const) */
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
    /* execute.a64:1910 [D] s_b_4_0 = sym_3441_0_op1 uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_3441_0_op1, emitter.context().types().u64());
    /* execute.a64:1910 [D] s_b_4_1 = sym_3448_0_op2 uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_3448_0_op2, emitter.context().types().u64());
    /* execute.a64:1910 [F] s_b_4_2 = constant u8 0 (const) */
    /* execute.a64:1910 [D] s_b_4_3 = __builtin_adc64_flags */
    auto s_b_4_3 = emitter.adcf(s_b_4_0, s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:1910 [D] s_b_4_4: sym_3465_0_result = s_b_4_3, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_3465_0_result, s_b_4_3);
    /* execute.a64:1910 [F] s_b_4_5: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_6,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1915 [D] s_b_5_0 = sym_3465_0_result uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_3465_0_result, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_5_1=sym_3436_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_5_2: sym_47924_3_parameter_value = s_b_5_0, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_47924_3_parameter_value, s_b_5_0);
    /* execute.a64:2682 [F] s_b_5_3 = (u32)s_b_5_1 (const) */
    /* execute.a64:2682 [F] s_b_5_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_5_6: If s_b_5_5: Jump b_2 else b_23 (const) */
    if (s_b_5_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_1,  */
  fixed_block_b_6: 
  {
    /* execute.a64:1912 [D] s_b_6_0 = sym_3441_0_op1 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_3441_0_op1, emitter.context().types().u64());
    /* execute.a64:1912 [D] s_b_6_1 = sym_3448_0_op2 uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_3448_0_op2, emitter.context().types().u64());
    /* execute.a64:1912 [D] s_b_6_2 = s_b_6_0+s_b_6_1 */
    auto s_b_6_2 = emitter.add(s_b_6_0, s_b_6_1);
    /* execute.a64:1912 [D] s_b_6_3: sym_3465_0_result = s_b_6_2, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_3465_0_result, s_b_6_2);
    /* execute.a64:1912 [F] s_b_6_4: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1920 [D] s_b_7_0 = sym_3441_0_op1 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_3441_0_op1, emitter.context().types().u64());
    /* execute.a64:1920 [D] s_b_7_1 = (u32)s_b_7_0 */
    auto s_b_7_1 = emitter.truncate(s_b_7_0, emitter.context().types().u32());
    /* execute.a64:1920 [D] s_b_7_2 = sym_3448_0_op2 uint64_t */
    auto s_b_7_2 = emitter.load_local(DV_sym_3448_0_op2, emitter.context().types().u64());
    /* execute.a64:1920 [D] s_b_7_3 = (u32)s_b_7_2 */
    auto s_b_7_3 = emitter.truncate(s_b_7_2, emitter.context().types().u32());
    /* execute.a64:1920 [F] s_b_7_4 = constant u8 0 (const) */
    /* execute.a64:1920 [D] s_b_7_5 = __builtin_adc32_flags */
    auto s_b_7_5 = emitter.adcf(s_b_7_1, s_b_7_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:1920 [D] s_b_7_6: sym_3491_0_result = s_b_7_5, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_3491_0_result, s_b_7_5);
    /* execute.a64:1920 [F] s_b_7_7: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_9,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1925 [D] s_b_8_0 = sym_3491_0_result uint32_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_3491_0_result, emitter.context().types().u32());
    /* execute.a64:1925 [D] s_b_8_1 = (u64)s_b_8_0 */
    auto s_b_8_1 = emitter.zx(s_b_8_0, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_8_2=sym_3436_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_8_3 = (u32)s_b_8_1 */
    auto s_b_8_3 = emitter.truncate(s_b_8_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_8_4 = (u64)s_b_8_3 */
    auto s_b_8_4 = emitter.zx(s_b_8_3, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_8_5: sym_47990_3_parameter_value = s_b_8_4, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_47990_3_parameter_value, s_b_8_4);
    /* execute.a64:2682 [F] s_b_8_6 = (u32)s_b_8_2 (const) */
    /* execute.a64:2682 [F] s_b_8_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_8_8 = s_b_8_6==s_b_8_7 (const) */
    uint8_t s_b_8_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_8_9: If s_b_8_8: Jump b_2 else b_24 (const) */
    if (s_b_8_8) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1922 [D] s_b_9_0 = sym_3441_0_op1 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_3441_0_op1, emitter.context().types().u64());
    /* execute.a64:1922 [D] s_b_9_1 = (u32)s_b_9_0 */
    auto s_b_9_1 = emitter.truncate(s_b_9_0, emitter.context().types().u32());
    /* execute.a64:1922 [D] s_b_9_2 = sym_3448_0_op2 uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_3448_0_op2, emitter.context().types().u64());
    /* execute.a64:1922 [D] s_b_9_3 = (u32)s_b_9_2 */
    auto s_b_9_3 = emitter.truncate(s_b_9_2, emitter.context().types().u32());
    /* execute.a64:1922 [D] s_b_9_4 = s_b_9_1+s_b_9_3 */
    auto s_b_9_4 = emitter.add(s_b_9_1, s_b_9_3);
    /* execute.a64:1922 [D] s_b_9_5: sym_3491_0_result = s_b_9_4, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_3491_0_result, s_b_9_4);
    /* execute.a64:1922 [F] s_b_9_6: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2657 [F] s_b_10_0=sym_3436_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2651 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_10_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_10_5 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_10_6: Select s_b_10_3 ? s_b_10_4 : s_b_10_5 */
    captive::arch::dbt::el::Value *s_b_10_6;
    s_b_10_6 = (s_b_10_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_10_5);
    /* execute.a64:2657 [D] s_b_10_7: sym_47714_1__R_s_b_0_4 = s_b_10_6, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_47714_1__R_s_b_0_4, s_b_10_6);
    /* execute.a64:2657 [F] s_b_10_8: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2659 [F] s_b_11_0=sym_3436_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2646 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_11_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_11_5 = ReadRegBank 1:s_b_11_0 (u32) */
    auto s_b_11_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_11_6: Select s_b_11_3 ? s_b_11_4 : s_b_11_5 */
    captive::arch::dbt::el::Value *s_b_11_6;
    s_b_11_6 = (s_b_11_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_11_5);
    /* execute.a64:2659 [D] s_b_11_7 = (u64)s_b_11_6 */
    auto s_b_11_7 = emitter.zx(s_b_11_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_11_8: sym_47714_1__R_s_b_0_4 = s_b_11_7, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_47714_1__R_s_b_0_4, s_b_11_7);
    /* execute.a64:2659 [F] s_b_11_9: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:1903 [D] s_b_12_0 = sym_47714_1__R_s_b_0_4 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_47714_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:1903 [D] s_b_12_1: sym_3441_0_op1 = s_b_12_0, dominates: s_b_4_0 s_b_6_0 s_b_7_0 s_b_9_0  */
    emitter.store_local(DV_sym_3441_0_op1, s_b_12_0);
    /* execute.a64:1904 [F] s_b_12_2=sym_3436_3_parameter_inst.imm6 (const) */
    /* execute.a64:2572 [F] s_b_12_3 = (u32)s_b_12_2 (const) */
    /* execute.a64:2572 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2572 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(((uint32_t)insn.imm6) == (uint32_t)0ULL));
    /* execute.a64:2572 [F] s_b_12_6: If s_b_12_5: Jump b_13 else b_14 (const) */
    if (s_b_12_5) 
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
    /* execute.a64:2572 [F] s_b_13_0=sym_3436_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_13_1: If s_b_13_0: Jump b_25 else b_26 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2574 [F] s_b_14_0=sym_3436_3_parameter_inst.shift (const) */
    /* execute.a64:2575 [F] s_b_14_1 = constant s32 0 (const) */
    /* execute.a64:2579 [F] s_b_14_2 = constant s32 1 (const) */
    /* execute.a64:2583 [F] s_b_14_3 = constant s32 2 (const) */
    /* execute.a64:2587 [F] s_b_14_4 = constant s32 3 (const) */
    /* execute.a64:2574 [F] s_b_14_5: Switch s_b_14_0: < <todo> > def b_15 (const) -> b_15, b_16, b_17, b_18, b_19,  */
    switch (insn.shift) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_18;
      break;
    default:
      goto fixed_block_b_15;
    }
  }
  /* b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2597 [D] s_b_15_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2598 [F] s_b_15_1 = constant u64 0 (const) */
    /* execute.a64:2598 [F] s_b_15_2: sym_47894_1__R_s_b_13_10 = s_b_15_1 (const), dominates: s_b_22_0  */
    CV_sym_47894_1__R_s_b_13_10 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_47894_1__R_s_b_13_10, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2598 [F] s_b_15_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2577 [F] s_b_16_0=sym_3436_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_16_1: If s_b_16_0: Jump b_28 else b_29 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_14,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2585 [F] s_b_17_0=sym_3436_3_parameter_inst.sf (const) */
    /* execute.a64:2665 [F] s_b_17_1: If s_b_17_0: Jump b_31 else b_32 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_14,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2589 [F] s_b_18_0=sym_3436_3_parameter_inst.sf (const) */
    /* execute.a64:2589 [F] s_b_18_1: If s_b_18_0: Jump b_20 else b_21 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_14,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2581 [F] s_b_19_0=sym_3436_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_19_1: If s_b_19_0: Jump b_34 else b_35 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_18,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2657 [F] s_b_20_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
    /* execute.a64:2651 [F] s_b_20_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_20_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_20_5 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_20_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_20_6: Select s_b_20_3 ? s_b_20_4 : s_b_20_5 */
    captive::arch::dbt::el::Value *s_b_20_6;
    s_b_20_6 = (s_b_20_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_20_5);
    /* execute.a64:2590 [F] s_b_20_7=sym_3436_3_parameter_inst.imm6 (const) */
    /* execute.a64:2590 [F] s_b_20_8 = (u64)s_b_20_7 (const) */
    /* execute.a64:2590 [D] s_b_20_9 = s_b_20_6>>>s_b_20_8 */
    auto s_b_20_9 = emitter.ror(s_b_20_6, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2590 [D] s_b_20_10: sym_47894_1__R_s_b_13_10 = s_b_20_9, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_47894_1__R_s_b_13_10, s_b_20_9);
    /* execute.a64:2590 [F] s_b_20_11: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_18,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2659 [F] s_b_21_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:2646 [F] s_b_21_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_21_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_21_5 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_21_6: Select s_b_21_3 ? s_b_21_4 : s_b_21_5 */
    captive::arch::dbt::el::Value *s_b_21_6;
    s_b_21_6 = (s_b_21_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_21_5);
    /* execute.a64:2659 [D] s_b_21_7 = (u64)s_b_21_6 */
    auto s_b_21_7 = emitter.zx(s_b_21_6, emitter.context().types().u64());
    /* execute.a64:2592 [D] s_b_21_8 = (u32)s_b_21_7 */
    auto s_b_21_8 = emitter.truncate(s_b_21_7, emitter.context().types().u32());
    /* execute.a64:2592 [F] s_b_21_9=sym_3436_3_parameter_inst.imm6 (const) */
    /* execute.a64:2592 [F] s_b_21_10 = (u32)s_b_21_9 (const) */
    /* execute.a64:2592 [D] s_b_21_11 = s_b_21_8>>>s_b_21_10 */
    auto s_b_21_11 = emitter.ror(s_b_21_8, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2592 [D] s_b_21_12 = (u64)s_b_21_11 */
    auto s_b_21_12 = emitter.zx(s_b_21_11, emitter.context().types().u64());
    /* execute.a64:2592 [D] s_b_21_13: sym_47894_1__R_s_b_13_10 = s_b_21_12, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_47894_1__R_s_b_13_10, s_b_21_12);
    /* execute.a64:2592 [F] s_b_21_14: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_15, b_20, b_21, b_27, b_30, b_33, b_36,  */
  fixed_block_b_22: 
  {
    /* execute.a64:1904 [D] s_b_22_0 = sym_47894_1__R_s_b_13_10 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_47894_1__R_s_b_13_10, emitter.context().types().u64());
    /* execute.a64:1904 [D] s_b_22_1: sym_3448_0_op2 = s_b_22_0, dominates: s_b_4_1 s_b_6_1 s_b_7_2 s_b_9_2  */
    emitter.store_local(DV_sym_3448_0_op2, s_b_22_0);
    /* execute.a64:1906 [F] s_b_22_2=sym_3436_3_parameter_inst.sf (const) */
    /* execute.a64:1906 [F] s_b_22_3: If s_b_22_2: Jump b_1 else b_3 (const) */
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
  fixed_block_b_23: 
  {
    /* execute.a64:2684 [F] s_b_23_0=sym_3436_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_23_1 = sym_47924_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_47924_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_23_2: WriteRegBank 0:s_b_23_0 = s_b_23_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_1);
    /* execute.a64:0 [F] s_b_23_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2684 [F] s_b_24_0=sym_3436_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_24_1 = sym_47990_3_parameter_value uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_47990_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_24_2: WriteRegBank 0:s_b_24_0 = s_b_24_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_24_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_24_1);
    /* execute.a64:0 [F] s_b_24_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_13,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2657 [F] s_b_25_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:2651 [F] s_b_25_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_25_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_25_5 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_25_6: Select s_b_25_3 ? s_b_25_4 : s_b_25_5 */
    captive::arch::dbt::el::Value *s_b_25_6;
    s_b_25_6 = (s_b_25_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_25_5);
    /* execute.a64:2657 [D] s_b_25_7: sym_48017_1__R_s_b_29_4 = s_b_25_6, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_48017_1__R_s_b_29_4, s_b_25_6);
    /* execute.a64:2657 [F] s_b_25_8: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_13,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2659 [F] s_b_26_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
    /* execute.a64:2646 [F] s_b_26_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_26_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_26_5 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_26_6: Select s_b_26_3 ? s_b_26_4 : s_b_26_5 */
    captive::arch::dbt::el::Value *s_b_26_6;
    s_b_26_6 = (s_b_26_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_26_5);
    /* execute.a64:2659 [D] s_b_26_7 = (u64)s_b_26_6 */
    auto s_b_26_7 = emitter.zx(s_b_26_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_26_8: sym_48017_1__R_s_b_29_4 = s_b_26_7, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_48017_1__R_s_b_29_4, s_b_26_7);
    /* execute.a64:2659 [F] s_b_26_9: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_25, b_26,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2572 [D] s_b_27_0 = sym_48017_1__R_s_b_29_4 uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_48017_1__R_s_b_29_4, emitter.context().types().u64());
    /* execute.a64:2572 [D] s_b_27_1: sym_47894_1__R_s_b_13_10 = s_b_27_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_47894_1__R_s_b_13_10, s_b_27_0);
    /* execute.a64:2572 [F] s_b_27_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_16,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2657 [F] s_b_28_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:2651 [F] s_b_28_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_28_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_28_5 = ReadRegBank 0:s_b_28_0 (u64) */
    auto s_b_28_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_28_6: Select s_b_28_3 ? s_b_28_4 : s_b_28_5 */
    captive::arch::dbt::el::Value *s_b_28_6;
    s_b_28_6 = (s_b_28_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_28_5);
    /* execute.a64:2657 [D] s_b_28_7: sym_48042_1__R_s_b_32_4 = s_b_28_6, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_48042_1__R_s_b_32_4, s_b_28_6);
    /* execute.a64:2657 [F] s_b_28_8: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_16,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2659 [F] s_b_29_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
    /* execute.a64:2646 [F] s_b_29_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_29_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_29_5 = ReadRegBank 1:s_b_29_0 (u32) */
    auto s_b_29_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_29_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_29_6: Select s_b_29_3 ? s_b_29_4 : s_b_29_5 */
    captive::arch::dbt::el::Value *s_b_29_6;
    s_b_29_6 = (s_b_29_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_29_5);
    /* execute.a64:2659 [D] s_b_29_7 = (u64)s_b_29_6 */
    auto s_b_29_7 = emitter.zx(s_b_29_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_29_8: sym_48042_1__R_s_b_32_4 = s_b_29_7, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_48042_1__R_s_b_32_4, s_b_29_7);
    /* execute.a64:2659 [F] s_b_29_9: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_28, b_29,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2577 [D] s_b_30_0 = sym_48042_1__R_s_b_32_4 uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_48042_1__R_s_b_32_4, emitter.context().types().u64());
    /* execute.a64:2577 [F] s_b_30_1=sym_3436_3_parameter_inst.imm6 (const) */
    /* execute.a64:2577 [F] s_b_30_2 = (u64)s_b_30_1 (const) */
    /* execute.a64:2577 [D] s_b_30_3 = s_b_30_0<<s_b_30_2 */
    auto s_b_30_3 = emitter.shl(s_b_30_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2577 [D] s_b_30_4: sym_47894_1__R_s_b_13_10 = s_b_30_3, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_47894_1__R_s_b_13_10, s_b_30_3);
    /* execute.a64:2577 [F] s_b_30_5: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_17,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2666 [F] s_b_31_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
    /* execute.a64:2666 [F] s_b_31_2 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_31_3 = s_b_31_1==s_b_31_2 (const) */
    uint8_t s_b_31_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_31_4 = constant s64 0 (const) */
    /* execute.a64:2666 [F] s_b_31_5=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [D] s_b_31_6 = ReadRegBank 0:s_b_31_5 (u64) */
    auto s_b_31_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_31_6,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_31_7 = (s64)s_b_31_6 */
    auto s_b_31_7 = emitter.reinterpret(s_b_31_6, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_31_8: Select s_b_31_3 ? s_b_31_4 : s_b_31_7 */
    captive::arch::dbt::el::Value *s_b_31_8;
    s_b_31_8 = (s_b_31_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_31_7);
    /* execute.a64:2666 [D] s_b_31_9: sym_48083_1__R_s_b_33_4 = s_b_31_8, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_48083_1__R_s_b_33_4, s_b_31_8);
    /* execute.a64:2666 [F] s_b_31_10: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_17,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2668 [F] s_b_32_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [F] s_b_32_1 = (u32)s_b_32_0 (const) */
    /* execute.a64:2668 [F] s_b_32_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_32_3 = s_b_32_1==s_b_32_2 (const) */
    uint8_t s_b_32_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_32_4 = constant s64 0 (const) */
    /* execute.a64:2668 [F] s_b_32_5=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [D] s_b_32_6 = ReadRegBank 1:s_b_32_5 (u32) */
    auto s_b_32_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_32_6,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_32_7 = (s32)s_b_32_6 */
    auto s_b_32_7 = emitter.reinterpret(s_b_32_6, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_32_8 = (s64)s_b_32_7 */
    auto s_b_32_8 = emitter.sx(s_b_32_7, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_32_9: Select s_b_32_3 ? s_b_32_4 : s_b_32_8 */
    captive::arch::dbt::el::Value *s_b_32_9;
    s_b_32_9 = (s_b_32_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_32_8);
    /* execute.a64:2668 [D] s_b_32_10: sym_48083_1__R_s_b_33_4 = s_b_32_9, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_48083_1__R_s_b_33_4, s_b_32_9);
    /* execute.a64:2668 [F] s_b_32_11: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_31, b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2585 [D] s_b_33_0 = sym_48083_1__R_s_b_33_4 int64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_48083_1__R_s_b_33_4, emitter.context().types().s64());
    /* execute.a64:2585 [F] s_b_33_1=sym_3436_3_parameter_inst.imm6 (const) */
    /* execute.a64:2585 [D] s_b_33_2 = (u64)s_b_33_0 */
    auto s_b_33_2 = emitter.reinterpret(s_b_33_0, emitter.context().types().u64());
    /* execute.a64:2585 [F] s_b_33_3 = (u64)s_b_33_1 (const) */
    /* execute.a64:2585 [D] s_b_33_4 = s_b_33_2->>s_b_33_3 */
    auto s_b_33_4 = emitter.sar(s_b_33_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2585 [D] s_b_33_5 = (u64)s_b_33_4 */
    auto s_b_33_5 = (captive::arch::dbt::el::Value *)s_b_33_4;
    /* execute.a64:2585 [D] s_b_33_6: sym_47894_1__R_s_b_13_10 = s_b_33_5, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_47894_1__R_s_b_13_10, s_b_33_5);
    /* execute.a64:2585 [F] s_b_33_7: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2657 [F] s_b_34_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
    /* execute.a64:2651 [F] s_b_34_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_34_3 = s_b_34_1==s_b_34_2 (const) */
    uint8_t s_b_34_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_34_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_34_5 = ReadRegBank 0:s_b_34_0 (u64) */
    auto s_b_34_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_34_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_34_6: Select s_b_34_3 ? s_b_34_4 : s_b_34_5 */
    captive::arch::dbt::el::Value *s_b_34_6;
    s_b_34_6 = (s_b_34_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_34_5);
    /* execute.a64:2657 [D] s_b_34_7: sym_48108_1__R_s_b_35_4 = s_b_34_6, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_48108_1__R_s_b_35_4, s_b_34_6);
    /* execute.a64:2657 [F] s_b_34_8: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_19,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2659 [F] s_b_35_0=sym_3436_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
    /* execute.a64:2646 [F] s_b_35_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_35_3 = s_b_35_1==s_b_35_2 (const) */
    uint8_t s_b_35_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_35_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_35_5 = ReadRegBank 1:s_b_35_0 (u32) */
    auto s_b_35_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_35_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_35_6: Select s_b_35_3 ? s_b_35_4 : s_b_35_5 */
    captive::arch::dbt::el::Value *s_b_35_6;
    s_b_35_6 = (s_b_35_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_35_5);
    /* execute.a64:2659 [D] s_b_35_7 = (u64)s_b_35_6 */
    auto s_b_35_7 = emitter.zx(s_b_35_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_35_8: sym_48108_1__R_s_b_35_4 = s_b_35_7, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_48108_1__R_s_b_35_4, s_b_35_7);
    /* execute.a64:2659 [F] s_b_35_9: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2581 [D] s_b_36_0 = sym_48108_1__R_s_b_35_4 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_48108_1__R_s_b_35_4, emitter.context().types().u64());
    /* execute.a64:2581 [F] s_b_36_1=sym_3436_3_parameter_inst.imm6 (const) */
    /* execute.a64:2581 [F] s_b_36_2 = (u64)s_b_36_1 (const) */
    /* execute.a64:2581 [D] s_b_36_3 = s_b_36_0>>s_b_36_2 */
    auto s_b_36_3 = emitter.shr(s_b_36_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2581 [D] s_b_36_4: sym_47894_1__R_s_b_13_10 = s_b_36_3, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_47894_1__R_s_b_13_10, s_b_36_3);
    /* execute.a64:2581 [F] s_b_36_5: Jump b_22 (const) */
    goto fixed_block_b_22;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_andi(const aarch64_decode_a64_LOGICAL_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_49555_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49589_1_tmp_s_b_4_3 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_5891_0_result = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_5855_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_5845_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49599_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49745_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49786_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49655_1_tmp_s_b_7_3 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_49846_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49665_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_49865_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:184 [F] s_b_0_0=sym_5840_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_8 else b_9 (const) */
    if (insn.sf) 
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
    /* execute.a64:187 [D] s_b_1_0 = sym_5845_0_op1 uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_5845_0_op1, emitter.context().types().u64());
    /* execute.a64:187 [F] s_b_1_1=sym_5840_3_parameter_inst.immu64 (const) */
    /* execute.a64:187 [D] s_b_1_2 = s_b_1_0&s_b_1_1 */
    auto s_b_1_2 = emitter.bitwise_and(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.a64:187 [D] s_b_1_3: sym_5855_0_result = s_b_1_2, dominates: s_b_4_0 s_b_5_1  */
    emitter.store_local(DV_sym_5855_0_result, s_b_1_2);
    /* execute.a64:189 [F] s_b_1_4=sym_5840_3_parameter_inst.opc (const) */
    /* execute.a64:189 [F] s_b_1_5 = (u32)s_b_1_4 (const) */
    /* execute.a64:189 [F] s_b_1_6 = constant u32 3 (const) */
    /* execute.a64:189 [F] s_b_1_7 = s_b_1_5==s_b_1_6 (const) */
    uint8_t s_b_1_7 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:189 [F] s_b_1_8: If s_b_1_7: Jump b_4 else b_5 (const) */
    if (s_b_1_7) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_11, b_15, b_16, b_20, b_22, b_23, b_24, b_26, b_27, b_28,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_3: 
  {
    /* execute.a64:199 [D] s_b_3_0 = sym_5845_0_op1 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_5845_0_op1, emitter.context().types().u64());
    /* execute.a64:199 [D] s_b_3_1 = (u32)s_b_3_0 */
    auto s_b_3_1 = emitter.truncate(s_b_3_0, emitter.context().types().u32());
    /* execute.a64:199 [F] s_b_3_2=sym_5840_3_parameter_inst.immu32 (const) */
    /* execute.a64:199 [D] s_b_3_3 = s_b_3_1&s_b_3_2 */
    auto s_b_3_3 = emitter.bitwise_and(s_b_3_1, emitter.const_u32(insn.immu32));
    /* execute.a64:199 [D] s_b_3_4: sym_5891_0_result = s_b_3_3, dominates: s_b_6_0 s_b_7_1  */
    emitter.store_local(DV_sym_5891_0_result, s_b_3_3);
    /* execute.a64:201 [F] s_b_3_5=sym_5840_3_parameter_inst.opc (const) */
    /* execute.a64:201 [F] s_b_3_6 = (u32)s_b_3_5 (const) */
    /* execute.a64:201 [F] s_b_3_7 = constant u32 3 (const) */
    /* execute.a64:201 [F] s_b_3_8 = s_b_3_6==s_b_3_7 (const) */
    uint8_t s_b_3_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:201 [F] s_b_3_9: If s_b_3_8: Jump b_6 else b_7 (const) */
    if (s_b_3_8) 
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
    /* execute.a64:190 [D] s_b_4_0 = sym_5855_0_result uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_5855_0_result, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_1: sym_49589_1_tmp_s_b_4_3 = s_b_4_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_49589_1_tmp_s_b_4_3, s_b_4_0);
    /* execute.a64:2691 [F] s_b_4_2=sym_5840_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_4_3: sym_49745_3_parameter_value = s_b_4_0, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_49745_3_parameter_value, s_b_4_0);
    /* execute.a64:2682 [F] s_b_4_4 = (u32)s_b_4_2 (const) */
    /* execute.a64:2682 [F] s_b_4_5 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_4_6 = s_b_4_4==s_b_4_5 (const) */
    uint8_t s_b_4_6 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_4_7: If s_b_4_6: Jump b_11 else b_21 (const) */
    if (s_b_4_6) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:196 [F] s_b_5_0 = constant u8 1 (const) */
    /* execute.a64:196 [D] s_b_5_1 = sym_5855_0_result uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_5855_0_result, emitter.context().types().u64());
    /* execute.a64:196 [D] s_b_5_2: sym_49599_3_parameter_value = s_b_5_1, dominates: s_b_12_0 s_b_14_0 s_b_15_1  */
    emitter.store_local(DV_sym_49599_3_parameter_value, s_b_5_1);
    /* execute.a64:2746 [F] s_b_5_3 = !s_b_5_0 (const) */
    uint8_t s_b_5_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_5_4: If s_b_5_3: Jump b_12 else b_13 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.a64:202 [D] s_b_6_0 = sym_5891_0_result uint32_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_5891_0_result, emitter.context().types().u32());
    /* execute.a64:202 [D] s_b_6_1 = (u64)s_b_6_0 */
    auto s_b_6_1 = emitter.zx(s_b_6_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_2: sym_49655_1_tmp_s_b_7_3 = s_b_6_0, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_49655_1_tmp_s_b_7_3, s_b_6_0);
    /* execute.a64:2693 [F] s_b_6_3=sym_5840_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_6_4 = (u32)s_b_6_1 */
    auto s_b_6_4 = emitter.truncate(s_b_6_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_5 = (u64)s_b_6_4 */
    auto s_b_6_5 = emitter.zx(s_b_6_4, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_6: sym_49846_3_parameter_value = s_b_6_5, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_49846_3_parameter_value, s_b_6_5);
    /* execute.a64:2682 [F] s_b_6_7 = (u32)s_b_6_3 (const) */
    /* execute.a64:2682 [F] s_b_6_8 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_6_9 = s_b_6_7==s_b_6_8 (const) */
    uint8_t s_b_6_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_6_10: If s_b_6_9: Jump b_16 else b_25 (const) */
    if (s_b_6_9) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:208 [F] s_b_7_0 = constant u8 0 (const) */
    /* execute.a64:208 [D] s_b_7_1 = sym_5891_0_result uint32_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_5891_0_result, emitter.context().types().u32());
    /* execute.a64:208 [D] s_b_7_2 = (u64)s_b_7_1 */
    auto s_b_7_2 = emitter.zx(s_b_7_1, emitter.context().types().u64());
    /* execute.a64:208 [D] s_b_7_3: sym_49665_3_parameter_value = s_b_7_2, dominates: s_b_17_0 s_b_19_0 s_b_20_1  */
    emitter.store_local(DV_sym_49665_3_parameter_value, s_b_7_2);
    /* execute.a64:2746 [F] s_b_7_4 = !s_b_7_0 (const) */
    uint8_t s_b_7_4 = !(uint8_t)0ULL;
    /* execute.a64:2746 [F] s_b_7_5: If s_b_7_4: Jump b_17 else b_18 (const) */
    if (s_b_7_4) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2657 [F] s_b_8_0=sym_5840_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2651 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_8_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_8_5 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    captive::arch::dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2657 [D] s_b_8_7: sym_49555_1__R_s_b_0_4 = s_b_8_6, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_49555_1__R_s_b_0_4, s_b_8_6);
    /* execute.a64:2657 [F] s_b_8_8: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2659 [F] s_b_9_0=sym_5840_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:2646 [F] s_b_9_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_9_5 = ReadRegBank 1:s_b_9_0 (u32) */
    auto s_b_9_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_9_6: Select s_b_9_3 ? s_b_9_4 : s_b_9_5 */
    captive::arch::dbt::el::Value *s_b_9_6;
    s_b_9_6 = (s_b_9_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_9_5);
    /* execute.a64:2659 [D] s_b_9_7 = (u64)s_b_9_6 */
    auto s_b_9_7 = emitter.zx(s_b_9_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_9_8: sym_49555_1__R_s_b_0_4 = s_b_9_7, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_49555_1__R_s_b_0_4, s_b_9_7);
    /* execute.a64:2659 [F] s_b_9_9: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_8, b_9,  */
  fixed_block_b_10: 
  {
    /* execute.a64:184 [D] s_b_10_0 = sym_49555_1__R_s_b_0_4 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_49555_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:184 [D] s_b_10_1: sym_5845_0_op1 = s_b_10_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_5845_0_op1, s_b_10_0);
    /* execute.a64:186 [F] s_b_10_2=sym_5840_3_parameter_inst.sf (const) */
    /* execute.a64:186 [F] s_b_10_3: If s_b_10_2: Jump b_1 else b_3 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_3;
    }
  }
  /* b_4, b_21,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_49589_1_tmp_s_b_4_3 uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_49589_1_tmp_s_b_4_3, emitter.context().types().u64());
    /* execute.a64:192 [D] s_b_11_1 = __builtin_update_zn_flags64 */
    emitter.set_zn(s_b_11_0);
    /* execute.a64:193 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.a64:193 [F] s_b_11_3: WriteReg 3 = s_b_11_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:194 [F] s_b_11_4 = constant u8 0 (const) */
    /* execute.a64:194 [F] s_b_11_5: WriteReg 4 = s_b_11_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:190 [F] s_b_11_6: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2747 [D] s_b_12_0 = sym_49599_3_parameter_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_49599_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_12_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_12_2 = s_b_12_0&s_b_12_1 */
    auto s_b_12_2 = emitter.bitwise_and(s_b_12_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_12_3: sym_49599_3_parameter_value = s_b_12_2, dominates: s_b_14_0 s_b_15_1  */
    emitter.store_local(DV_sym_49599_3_parameter_value, s_b_12_2);
    /* execute.a64:2747 [F] s_b_12_4: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_5, b_12,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2750 [F] s_b_13_0=sym_5840_3_parameter_inst.rd (const) */
    /* execute.a64:2750 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:2750 [F] s_b_13_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_15 (const) */
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
    /* execute.a64:2751 [D] s_b_14_0 = sym_49599_3_parameter_value uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_49599_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_14_1: sym_49786_3_parameter_value = s_b_14_0, dominates: s_b_22_0 s_b_23_0 s_b_24_0  */
    emitter.store_local(DV_sym_49786_3_parameter_value, s_b_14_0);
    /* execute.a64:2714 [F] s_b_14_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_14_3 = __builtin_get_feature */
    uint32_t s_b_14_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_14_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_14_5 = s_b_14_3==s_b_14_4 (const) */
    uint8_t s_b_14_5 = ((uint8_t)(s_b_14_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_14_6: If s_b_14_5: Jump b_22 else b_29 (const) */
    if (s_b_14_5) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_13,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2753 [F] s_b_15_0=sym_5840_3_parameter_inst.rd (const) */
    /* execute.a64:2753 [D] s_b_15_1 = sym_49599_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_49599_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1);
    /* execute.a64:2753 [F] s_b_15_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6, b_25,  */
  fixed_block_b_16: 
  {
    /* ???:4294967295 [D] s_b_16_0 = sym_49655_1_tmp_s_b_7_3 uint32_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_49655_1_tmp_s_b_7_3, emitter.context().types().u32());
    /* execute.a64:204 [D] s_b_16_1 = __builtin_update_zn_flags32 */
    emitter.set_zn(s_b_16_0);
    /* execute.a64:205 [F] s_b_16_2 = constant u8 0 (const) */
    /* execute.a64:205 [F] s_b_16_3: WriteReg 3 = s_b_16_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:206 [F] s_b_16_4 = constant u8 0 (const) */
    /* execute.a64:206 [F] s_b_16_5: WriteReg 4 = s_b_16_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:202 [F] s_b_16_6: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2747 [D] s_b_17_0 = sym_49665_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_49665_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_17_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_17_2 = s_b_17_0&s_b_17_1 */
    auto s_b_17_2 = emitter.bitwise_and(s_b_17_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_17_3: sym_49665_3_parameter_value = s_b_17_2, dominates: s_b_19_0 s_b_20_1  */
    emitter.store_local(DV_sym_49665_3_parameter_value, s_b_17_2);
    /* execute.a64:2747 [F] s_b_17_4: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_7, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2750 [F] s_b_18_0=sym_5840_3_parameter_inst.rd (const) */
    /* execute.a64:2750 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
    /* execute.a64:2750 [F] s_b_18_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_18_4: If s_b_18_3: Jump b_19 else b_20 (const) */
    if (s_b_18_3) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_18,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2751 [D] s_b_19_0 = sym_49665_3_parameter_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_49665_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_19_1: sym_49865_3_parameter_value = s_b_19_0, dominates: s_b_26_0 s_b_27_0 s_b_28_0  */
    emitter.store_local(DV_sym_49865_3_parameter_value, s_b_19_0);
    /* execute.a64:2714 [F] s_b_19_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_19_3 = __builtin_get_feature */
    uint32_t s_b_19_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_19_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_19_5 = s_b_19_3==s_b_19_4 (const) */
    uint8_t s_b_19_5 = ((uint8_t)(s_b_19_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_19_6: If s_b_19_5: Jump b_26 else b_30 (const) */
    if (s_b_19_5) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_18,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2753 [F] s_b_20_0=sym_5840_3_parameter_inst.rd (const) */
    /* execute.a64:2753 [D] s_b_20_1 = sym_49665_3_parameter_value uint64_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_49665_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_20_2: WriteRegBank 0:s_b_20_0 = s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_1);
    /* execute.a64:2753 [F] s_b_20_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2684 [F] s_b_21_0=sym_5840_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_21_1 = sym_49745_3_parameter_value uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_49745_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_21_2: WriteRegBank 0:s_b_21_0 = s_b_21_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_21_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_21_1);
    /* execute.a64:0 [F] s_b_21_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_14,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2715 [D] s_b_22_0 = sym_49786_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_49786_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_22_1: WriteReg 20 = s_b_22_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_22_0);
    /* execute.a64:2715 [F] s_b_22_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_29,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2718 [D] s_b_23_0 = sym_49786_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_49786_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_23_1: WriteReg 20 = s_b_23_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_23_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_23_0);
    /* execute.a64:2718 [F] s_b_23_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_29,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2720 [D] s_b_24_0 = sym_49786_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_49786_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_24_1: WriteReg 21 = s_b_24_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_24_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_24_0);
    /* execute.a64:2720 [F] s_b_24_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2684 [F] s_b_25_0=sym_5840_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_25_1 = sym_49846_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_49846_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1);
    /* execute.a64:0 [F] s_b_25_3: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_19,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2715 [D] s_b_26_0 = sym_49865_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_49865_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_26_1: WriteReg 20 = s_b_26_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_26_0);
    /* execute.a64:2715 [F] s_b_26_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_30,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2718 [D] s_b_27_0 = sym_49865_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_49865_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_27_1: WriteReg 20 = s_b_27_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_27_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_27_0);
    /* execute.a64:2718 [F] s_b_27_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_30,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2720 [D] s_b_28_0 = sym_49865_3_parameter_value uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_49865_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_28_1: WriteReg 21 = s_b_28_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_28_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_28_0);
    /* execute.a64:2720 [F] s_b_28_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_14,  */
  fixed_block_b_29: 
  {
    /* execute.a64:3012 [F] s_b_29_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_29_1 = __builtin_get_feature */
    uint32_t s_b_29_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_29_2 = (u8)s_b_29_1 (const) */
    /* execute.a64:2717 [F] s_b_29_3 = (u32)s_b_29_2 (const) */
    /* execute.a64:2717 [F] s_b_29_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_29_5 = s_b_29_3==s_b_29_4 (const) */
    uint8_t s_b_29_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_29_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_29_6: If s_b_29_5: Jump b_23 else b_24 (const) */
    if (s_b_29_5) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_19,  */
  fixed_block_b_30: 
  {
    /* execute.a64:3012 [F] s_b_30_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_30_1 = __builtin_get_feature */
    uint32_t s_b_30_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_30_2 = (u8)s_b_30_1 (const) */
    /* execute.a64:2717 [F] s_b_30_3 = (u32)s_b_30_2 (const) */
    /* execute.a64:2717 [F] s_b_30_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_30_5 = s_b_30_3==s_b_30_4 (const) */
    uint8_t s_b_30_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_30_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_30_6: If s_b_30_5: Jump b_27 else b_28 (const) */
    if (s_b_30_5) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_28;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_bici(const aarch64_decode_a64_SIMD_MOD_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4828 [F] s_b_0_0=sym_6194_3_parameter_inst.Q (const) */
    /* execute.simd:4828 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4828 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4828 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:4828 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4829 [F] s_b_1_0=sym_6194_3_parameter_inst.rd (const) */
    /* execute.simd:6167 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:4830 [F] s_b_1_2=sym_6194_3_parameter_inst.rd (const) */
    /* execute.simd:4830 [F] s_b_1_3=sym_6194_3_parameter_inst.immu64 (const) */
    /* execute.simd:4830 [F] s_b_1_4 = ~s_b_1_3 (const) */
    uint64_t s_b_1_4 = ~insn.immu64;
    /* execute.simd:4830 [D] s_b_1_5 = s_b_1_1&s_b_1_4 */
    auto s_b_1_5 = emitter.bitwise_and(s_b_1_1, emitter.const_u64(s_b_1_4));
    /* execute.simd:6138 [D] s_b_1_6: WriteRegBank 2:s_b_1_2 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6139 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_1_8: WriteRegBank 3:s_b_1_2 = s_b_1_7 */
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
    /* execute.simd:4835 [F] s_b_3_0=sym_6194_3_parameter_inst.rd (const) */
    /* execute.simd:6172 [D] s_b_3_1 = ReadRegBank 2:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_3_2 = ReadRegBank 3:s_b_3_0 (u64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:4836 [F] s_b_3_3=sym_6194_3_parameter_inst.rd (const) */
    /* execute.simd:4836 [F] s_b_3_4=sym_6194_3_parameter_inst.immu64 (const) */
    /* execute.simd:4836 [F] s_b_3_5 = ~s_b_3_4 (const) */
    uint64_t s_b_3_5 = ~insn.immu64;
    /* execute.simd:4836 [D] s_b_3_6 = s_b_3_1&s_b_3_5 */
    auto s_b_3_6 = emitter.bitwise_and(s_b_3_1, emitter.const_u64(s_b_3_5));
    /* execute.simd:4836 [F] s_b_3_7=sym_6194_3_parameter_inst.immu64 (const) */
    /* execute.simd:4836 [F] s_b_3_8 = ~s_b_3_7 (const) */
    uint64_t s_b_3_8 = ~insn.immu64;
    /* execute.simd:4836 [D] s_b_3_9 = s_b_3_2&s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_2, emitter.const_u64(s_b_3_8));
    /* execute.simd:6145 [D] s_b_3_10: WriteRegBank 2:s_b_3_3 = s_b_3_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_6);
    /* execute.simd:6146 [D] s_b_3_11: WriteRegBank 3:s_b_3_3 = s_b_3_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_9,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_9);
    /* execute.simd:0 [F] s_b_3_12: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ccmnr(const aarch64_decode_a64_COND_CMP_REG&insn, captive::arch::dbt::el::Emitter& emitter)
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
  uint8_t CV_sym_53423_0_state;
  auto DV_sym_53423_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_53511_1__R_s_b_0_2 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_6670_0_rm = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_6665_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_53599_1__R_s_b_23_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_53536_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2083 [F] s_b_0_0=sym_6647_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_53423_0_state = s_b_0_1 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_53423_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_53423_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2793 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_11, b_9, b_8, b_10, b_13, b_12, b_14, b_6, b_7,  */
    switch (s_b_0_5) 
    {
    case (int32_t)7ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_13;
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
    /* execute.a64:2828 [F] s_b_6_0=sym_6647_3_parameter_inst.cond (const) */
    /* execute.a64:2828 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2828 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_6_3 = s_b_6_1&s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_6_6=sym_6647_3_parameter_inst.cond (const) */
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
    /* execute.a64:2823 [F] s_b_7_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_7_1: sym_53423_0_state = s_b_7_0 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_53423_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_53423_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_7_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2811 [D] s_b_8_0 = ReadReg 3 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_8_1 = ReadReg 2 (u8) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_8_1, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_8_2 = !s_b_8_1 */
    auto s_b_8_2 = emitter.cmp_eq(s_b_8_1, emitter.const_u8(0));
    /* execute.a64:2811 [D] s_b_8_3 = s_b_8_0&s_b_8_2 */
    auto s_b_8_3 = emitter.bitwise_and(s_b_8_0, s_b_8_2);
    /* execute.a64:2811 [D] s_b_8_4: sym_53423_0_state = s_b_8_3, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53423_0_state, s_b_8_3);
    /* execute.a64:0 [F] s_b_8_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2807 [D] s_b_9_0 = ReadReg 4 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2807 [D] s_b_9_1: sym_53423_0_state = s_b_9_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53423_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2803 [D] s_b_10_0 = ReadReg 1 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2803 [D] s_b_10_1: sym_53423_0_state = s_b_10_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53423_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2799 [D] s_b_11_0 = ReadReg 3 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2799 [D] s_b_11_1: sym_53423_0_state = s_b_11_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53423_0_state, s_b_11_0);
    /* execute.a64:0 [F] s_b_11_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2795 [D] s_b_12_0 = ReadReg 2 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2795 [D] s_b_12_1: sym_53423_0_state = s_b_12_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53423_0_state, s_b_12_0);
    /* execute.a64:0 [F] s_b_12_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2819 [D] s_b_13_0 = ReadReg 1 (u8) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_1 = ReadReg 4 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_13_1, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_2 = s_b_13_0==s_b_13_1 */
    auto s_b_13_2 = emitter.cmp_eq(s_b_13_0, s_b_13_1);
    /* execute.a64:2819 [D] s_b_13_3 = ReadReg 2 (u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_13_3, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_4 = !s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_eq(s_b_13_3, emitter.const_u8(0));
    /* execute.a64:2819 [D] s_b_13_5 = s_b_13_2&s_b_13_4 */
    auto s_b_13_5 = emitter.bitwise_and(s_b_13_2, s_b_13_4);
    /* execute.a64:2819 [D] s_b_13_6: sym_53423_0_state = s_b_13_5, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53423_0_state, s_b_13_5);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_14_0, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_14_1 = ReadReg 4 (u8) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_1, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_14_2 = s_b_14_0==s_b_14_1 */
    auto s_b_14_2 = emitter.cmp_eq(s_b_14_0, s_b_14_1);
    /* execute.a64:2815 [D] s_b_14_3: sym_53423_0_state = s_b_14_2, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53423_0_state, s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2829 [D] s_b_15_0 = sym_53423_0_state uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_53423_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_15_1 = !s_b_15_0 */
    auto s_b_15_1 = emitter.cmp_eq(s_b_15_0, emitter.const_u8(0));
    /* execute.a64:2829 [D] s_b_15_2: sym_53511_1__R_s_b_0_2 = s_b_15_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_53511_1__R_s_b_0_2, s_b_15_1);
    /* execute.a64:2829 [F] s_b_15_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2831 [D] s_b_16_0 = sym_53423_0_state uint8_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_53423_0_state, emitter.context().types().u8());
    /* execute.a64:2831 [D] s_b_16_1: sym_53511_1__R_s_b_0_2 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_53511_1__R_s_b_0_2, s_b_16_0);
    /* execute.a64:2831 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2083 [D] s_b_17_0 = sym_53511_1__R_s_b_0_2 uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_53511_1__R_s_b_0_2, emitter.context().types().u8());
    /* execute.a64:2084 [D] s_b_17_1 = (u32)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u32());
    /* execute.a64:2084 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.a64:2084 [D] s_b_17_3 = s_b_17_1!=s_b_17_2 */
    auto s_b_17_3 = emitter.cmp_ne(s_b_17_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2084 [D] s_b_17_4: If s_b_17_3: Jump b_1 else b_3 */
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
        /* execute.a64:2085 [F] s_b_1_0=sym_6647_3_parameter_inst.sf (const) */
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
        /* execute.a64:2094 [F] s_b_3_0=sym_6647_3_parameter_inst.nzcv (const) */
        /* execute.a64:2094 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.a64:2094 [F] s_b_3_2 = constant u32 8 (const) */
        /* execute.a64:2094 [F] s_b_3_3 = s_b_3_1&s_b_3_2 (const) */
        uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)8ULL));
        /* execute.a64:2094 [F] s_b_3_4 = constant u32 8 (const) */
        /* execute.a64:2094 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
        uint8_t s_b_3_5 = ((uint8_t)(s_b_3_3 == (uint32_t)8ULL));
        /* execute.a64:2094 [F] s_b_3_6: WriteReg 1 = s_b_3_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), emitter.const_u8(s_b_3_5), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1296), emitter.const_u8(s_b_3_5));
        /* execute.a64:2095 [F] s_b_3_7=sym_6647_3_parameter_inst.nzcv (const) */
        /* execute.a64:2095 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
        /* execute.a64:2095 [F] s_b_3_9 = constant u32 4 (const) */
        /* execute.a64:2095 [F] s_b_3_10 = s_b_3_8&s_b_3_9 (const) */
        uint32_t s_b_3_10 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)4ULL));
        /* execute.a64:2095 [F] s_b_3_11 = constant u32 4 (const) */
        /* execute.a64:2095 [F] s_b_3_12 = s_b_3_10==s_b_3_11 (const) */
        uint8_t s_b_3_12 = ((uint8_t)(s_b_3_10 == (uint32_t)4ULL));
        /* execute.a64:2095 [F] s_b_3_13: WriteReg 2 = s_b_3_12 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), emitter.const_u8(s_b_3_12), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1297), emitter.const_u8(s_b_3_12));
        /* execute.a64:2096 [F] s_b_3_14=sym_6647_3_parameter_inst.nzcv (const) */
        /* execute.a64:2096 [F] s_b_3_15 = (u32)s_b_3_14 (const) */
        /* execute.a64:2096 [F] s_b_3_16 = constant u32 2 (const) */
        /* execute.a64:2096 [F] s_b_3_17 = s_b_3_15&s_b_3_16 (const) */
        uint32_t s_b_3_17 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)2ULL));
        /* execute.a64:2096 [F] s_b_3_18 = constant u32 2 (const) */
        /* execute.a64:2096 [F] s_b_3_19 = s_b_3_17==s_b_3_18 (const) */
        uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 == (uint32_t)2ULL));
        /* execute.a64:2096 [F] s_b_3_20: WriteReg 3 = s_b_3_19 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8(s_b_3_19), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1298), emitter.const_u8(s_b_3_19));
        /* execute.a64:2097 [F] s_b_3_21=sym_6647_3_parameter_inst.nzcv (const) */
        /* execute.a64:2097 [F] s_b_3_22 = (u32)s_b_3_21 (const) */
        /* execute.a64:2097 [F] s_b_3_23 = constant u32 1 (const) */
        /* execute.a64:2097 [F] s_b_3_24 = s_b_3_22&s_b_3_23 (const) */
        uint32_t s_b_3_24 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)1ULL));
        /* execute.a64:2097 [F] s_b_3_25 = constant u32 1 (const) */
        /* execute.a64:2097 [F] s_b_3_26 = s_b_3_24==s_b_3_25 (const) */
        uint8_t s_b_3_26 = ((uint8_t)(s_b_3_24 == (uint32_t)1ULL));
        /* execute.a64:2097 [F] s_b_3_27: WriteReg 4 = s_b_3_26 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8(s_b_3_26), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1299), emitter.const_u8(s_b_3_26));
        /* execute.a64:2094 [F] s_b_3_28: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.a64:2089 [D] s_b_4_0 = sym_6665_0_rn uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_6665_0_rn, emitter.context().types().u64());
        /* execute.a64:2089 [D] s_b_4_1 = (u32)s_b_4_0 */
        auto s_b_4_1 = emitter.truncate(s_b_4_0, emitter.context().types().u32());
        /* execute.a64:2089 [D] s_b_4_2 = sym_6670_0_rm uint64_t */
        auto s_b_4_2 = emitter.load_local(DV_sym_6670_0_rm, emitter.context().types().u64());
        /* execute.a64:2089 [D] s_b_4_3 = (u32)s_b_4_2 */
        auto s_b_4_3 = emitter.truncate(s_b_4_2, emitter.context().types().u32());
        /* execute.a64:2089 [F] s_b_4_4 = constant u8 0 (const) */
        /* execute.a64:2089 [D] s_b_4_5 = __builtin_adc32_flags */
        auto s_b_4_5 = emitter.adcf(s_b_4_1, s_b_4_3, emitter.const_u8((uint8_t)0ULL));
        /* execute.a64:2089 [F] s_b_4_6: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2091 [D] s_b_5_0 = sym_6665_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_6665_0_rn, emitter.context().types().u64());
        /* execute.a64:2091 [D] s_b_5_1 = sym_6670_0_rm uint64_t */
        auto s_b_5_1 = emitter.load_local(DV_sym_6670_0_rm, emitter.context().types().u64());
        /* execute.a64:2091 [F] s_b_5_2 = constant u8 0 (const) */
        /* execute.a64:2091 [D] s_b_5_3 = __builtin_adc64_flags */
        auto s_b_5_3 = emitter.adcf(s_b_5_0, s_b_5_1, emitter.const_u8((uint8_t)0ULL));
        /* execute.a64:2091 [F] s_b_5_4: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2657 [F] s_b_18_0=sym_6647_3_parameter_inst.rn (const) */
        /* execute.a64:2651 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
        /* execute.a64:2651 [F] s_b_18_2 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
        uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_18_4 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_18_5 = ReadRegBank 0:s_b_18_0 (u64) */
        auto s_b_18_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_5,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_18_6: Select s_b_18_3 ? s_b_18_4 : s_b_18_5 */
        captive::arch::dbt::el::Value *s_b_18_6;
        s_b_18_6 = (s_b_18_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_18_5);
        /* execute.a64:2657 [D] s_b_18_7: sym_53536_1__R_s_b_1_4 = s_b_18_6, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_53536_1__R_s_b_1_4, s_b_18_6);
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
        /* execute.a64:2659 [F] s_b_19_0=sym_6647_3_parameter_inst.rn (const) */
        /* execute.a64:2646 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.a64:2646 [F] s_b_19_2 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
        uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_19_4 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_19_5 = ReadRegBank 1:s_b_19_0 (u32) */
        auto s_b_19_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_5,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_19_6: Select s_b_19_3 ? s_b_19_4 : s_b_19_5 */
        captive::arch::dbt::el::Value *s_b_19_6;
        s_b_19_6 = (s_b_19_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_19_5);
        /* execute.a64:2659 [D] s_b_19_7 = (u64)s_b_19_6 */
        auto s_b_19_7 = emitter.zx(s_b_19_6, emitter.context().types().u64());
        /* execute.a64:2659 [D] s_b_19_8: sym_53536_1__R_s_b_1_4 = s_b_19_7, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_53536_1__R_s_b_1_4, s_b_19_7);
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
        /* execute.a64:2085 [D] s_b_20_0 = sym_53536_1__R_s_b_1_4 uint64_t */
        auto s_b_20_0 = emitter.load_local(DV_sym_53536_1__R_s_b_1_4, emitter.context().types().u64());
        /* execute.a64:2085 [D] s_b_20_1: sym_6665_0_rn = s_b_20_0, dominates: s_b_4_0 s_b_5_0  */
        emitter.store_local(DV_sym_6665_0_rn, s_b_20_0);
        /* execute.a64:2086 [F] s_b_20_2=sym_6647_3_parameter_inst.sf (const) */
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
        /* execute.a64:2657 [F] s_b_21_0=sym_6647_3_parameter_inst.rm (const) */
        /* execute.a64:2651 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
        /* execute.a64:2651 [F] s_b_21_2 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
        uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_21_4 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_21_5 = ReadRegBank 0:s_b_21_0 (u64) */
        auto s_b_21_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_5,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_21_6: Select s_b_21_3 ? s_b_21_4 : s_b_21_5 */
        captive::arch::dbt::el::Value *s_b_21_6;
        s_b_21_6 = (s_b_21_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_21_5);
        /* execute.a64:2657 [D] s_b_21_7: sym_53599_1__R_s_b_23_6 = s_b_21_6, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_53599_1__R_s_b_23_6, s_b_21_6);
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
        /* execute.a64:2659 [F] s_b_22_0=sym_6647_3_parameter_inst.rm (const) */
        /* execute.a64:2646 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
        /* execute.a64:2646 [F] s_b_22_2 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
        uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_22_4 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_22_5 = ReadRegBank 1:s_b_22_0 (u32) */
        auto s_b_22_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_5,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_22_6: Select s_b_22_3 ? s_b_22_4 : s_b_22_5 */
        captive::arch::dbt::el::Value *s_b_22_6;
        s_b_22_6 = (s_b_22_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_22_5);
        /* execute.a64:2659 [D] s_b_22_7 = (u64)s_b_22_6 */
        auto s_b_22_7 = emitter.zx(s_b_22_6, emitter.context().types().u64());
        /* execute.a64:2659 [D] s_b_22_8: sym_53599_1__R_s_b_23_6 = s_b_22_7, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_53599_1__R_s_b_23_6, s_b_22_7);
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
        /* execute.a64:2086 [D] s_b_23_0 = sym_53599_1__R_s_b_23_6 uint64_t */
        auto s_b_23_0 = emitter.load_local(DV_sym_53599_1__R_s_b_23_6, emitter.context().types().u64());
        /* execute.a64:2086 [D] s_b_23_1: sym_6670_0_rm = s_b_23_0, dominates: s_b_4_2 s_b_5_1  */
        emitter.store_local(DV_sym_6670_0_rm, s_b_23_0);
        /* execute.a64:2088 [F] s_b_23_2=sym_6647_3_parameter_inst.sf (const) */
        /* execute.a64:2088 [F] s_b_23_3 = (u32)s_b_23_2 (const) */
        /* execute.a64:2088 [F] s_b_23_4 = constant u32 0 (const) */
        /* execute.a64:2088 [F] s_b_23_5 = s_b_23_3==s_b_23_4 (const) */
        uint8_t s_b_23_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
        /* execute.a64:2088 [F] s_b_23_6: If s_b_23_5: Jump b_4 else b_5 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_cmge_zero(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_8 = emitter.context().create_block();
  auto block_b_9 = emitter.context().create_block();
  auto DV_sym_7426_0_rn = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1745 [F] s_b_0_0=sym_7417_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1745 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1746 [F] s_b_1_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:1746 [D] s_b_1_2: sym_7426_0_rn = s_b_1_1, dominates: s_b_4_0 s_b_5_0  */
    emitter.store_local(DV_sym_7426_0_rn, s_b_1_1);
    /* execute.simd:1748 [F] s_b_1_3=sym_7417_3_parameter_inst.U (const) */
    /* execute.simd:1748 [F] s_b_1_4 = (u32)s_b_1_3 (const) */
    /* execute.simd:1748 [F] s_b_1_5 = constant u32 1 (const) */
    /* execute.simd:1748 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:1748 [F] s_b_1_7: If s_b_1_6: Jump b_4 else b_5 (const) */
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
    /* execute.simd:1762 [F] s_b_3_0=sym_7417_3_parameter_inst.U (const) */
    /* execute.simd:1762 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:1762 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:1762 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:1762 [F] s_b_3_4: If s_b_3_3: Jump b_10 else b_11 (const) */
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
    /* execute.simd:1749 [D] s_b_4_0 = sym_7426_0_rn uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_7426_0_rn, emitter.context().types().u64());
    /* execute.simd:1749 [D] s_b_4_1 = (s64)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s64());
    /* execute.simd:1749 [F] s_b_4_2 = constant s64 0 (const) */
    /* execute.simd:1749 [D] s_b_4_3 = s_b_4_1>=s_b_4_2 */
    auto s_b_4_3 = emitter.cmp_ge(s_b_4_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:1749 [D] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 */
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
    /* execute.simd:1755 [D] s_b_5_0 = sym_7426_0_rn uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_7426_0_rn, emitter.context().types().u64());
    /* execute.simd:1755 [D] s_b_5_1 = (s64)s_b_5_0 */
    auto s_b_5_1 = emitter.reinterpret(s_b_5_0, emitter.context().types().s64());
    /* execute.simd:1755 [F] s_b_5_2 = constant s64 0 (const) */
    /* execute.simd:1755 [D] s_b_5_3 = s_b_5_1>s_b_5_2 */
    auto s_b_5_3 = emitter.cmp_gt(s_b_5_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:1755 [D] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 */
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
    /* execute.simd:1763 [F] s_b_10_0=sym_7417_3_parameter_inst.arrangement (const) */
    /* execute.simd:1764 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.simd:1773 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.simd:1781 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.simd:1790 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.simd:1798 [F] s_b_10_5 = constant s32 4 (const) */
    /* execute.simd:1807 [F] s_b_10_6 = constant s32 5 (const) */
    /* execute.simd:1815 [F] s_b_10_7 = constant s32 6 (const) */
    /* execute.simd:1763 [F] s_b_10_8: Switch s_b_10_0: < <todo> > def b_19 (const) -> b_19, b_18, b_17, b_16, b_15, b_14, b_13, b_12,  */
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
    /* execute.simd:1829 [F] s_b_11_0=sym_7417_3_parameter_inst.arrangement (const) */
    /* execute.simd:1830 [F] s_b_11_1 = constant s32 0 (const) */
    /* execute.simd:1839 [F] s_b_11_2 = constant s32 1 (const) */
    /* execute.simd:1847 [F] s_b_11_3 = constant s32 2 (const) */
    /* execute.simd:1856 [F] s_b_11_4 = constant s32 3 (const) */
    /* execute.simd:1864 [F] s_b_11_5 = constant s32 4 (const) */
    /* execute.simd:1873 [F] s_b_11_6 = constant s32 5 (const) */
    /* execute.simd:1881 [F] s_b_11_7 = constant s32 6 (const) */
    /* execute.simd:1829 [F] s_b_11_8: Switch s_b_11_0: < <todo> > def b_27 (const) -> b_27, b_26, b_25, b_24, b_23, b_22, b_21, b_20,  */
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
    /* execute.simd:1765 [F] s_b_12_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1765 [D] s_b_12_1 = ReadRegBank 15:s_b_12_0 (v8u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:1765 [D] s_b_12_2 = (v8s8)s_b_12_1 */
    auto s_b_12_2 = emitter.reinterpret(s_b_12_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_12_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:1767 [D] s_b_12_4 = s_b_12_2>=s_b_12_3 */
    auto s_b_12_4 = emitter.cmp_ge(s_b_12_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:1767 [D] s_b_12_5 = (v8u8)s_b_12_4 */
    auto s_b_12_5 = emitter.reinterpret(s_b_12_4, emitter.context().types().v8u8());
    /* execute.simd:1768 [F] s_b_12_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1768 [D] s_b_12_7: WriteRegBank 15:s_b_12_6 = s_b_12_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5);
    /* execute.simd:1769 [F] s_b_12_8=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1769 [F] s_b_12_9 = constant u64 0 (const) */
    /* execute.simd:1769 [F] s_b_12_10: WriteRegBank 3:s_b_12_8 = s_b_12_9 */
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
    /* execute.simd:1774 [F] s_b_13_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1774 [D] s_b_13_1 = ReadRegBank 16:s_b_13_0 (v16u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_13_1,emitter.const_u8(16));
    }
    /* execute.simd:1774 [D] s_b_13_2 = (v16s8)s_b_13_1 */
    auto s_b_13_2 = emitter.reinterpret(s_b_13_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_13_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:1776 [D] s_b_13_4 = s_b_13_2>=s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_ge(s_b_13_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:1776 [D] s_b_13_5 = (v16u8)s_b_13_4 */
    auto s_b_13_5 = emitter.reinterpret(s_b_13_4, emitter.context().types().v16u8());
    /* execute.simd:1777 [F] s_b_13_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1777 [D] s_b_13_7: WriteRegBank 16:s_b_13_6 = s_b_13_5 */
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
    /* execute.simd:1782 [F] s_b_14_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1782 [D] s_b_14_1 = ReadRegBank 17:s_b_14_0 (v4u16) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.simd:1782 [D] s_b_14_2 = (v4s16)s_b_14_1 */
    auto s_b_14_2 = emitter.reinterpret(s_b_14_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_14_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:1784 [D] s_b_14_4 = s_b_14_2>=s_b_14_3 */
    auto s_b_14_4 = emitter.cmp_ge(s_b_14_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:1784 [D] s_b_14_5 = (v4u16)s_b_14_4 */
    auto s_b_14_5 = emitter.reinterpret(s_b_14_4, emitter.context().types().v4u16());
    /* execute.simd:1785 [F] s_b_14_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1785 [D] s_b_14_7: WriteRegBank 17:s_b_14_6 = s_b_14_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5);
    /* execute.simd:1786 [F] s_b_14_8=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1786 [F] s_b_14_9 = constant u64 0 (const) */
    /* execute.simd:1786 [F] s_b_14_10: WriteRegBank 3:s_b_14_8 = s_b_14_9 */
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
    /* execute.simd:1791 [F] s_b_15_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1791 [D] s_b_15_1 = ReadRegBank 18:s_b_15_0 (v8u16) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_15_1,emitter.const_u8(16));
    }
    /* execute.simd:1791 [D] s_b_15_2 = (v8s16)s_b_15_1 */
    auto s_b_15_2 = emitter.reinterpret(s_b_15_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_15_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:1793 [D] s_b_15_4 = s_b_15_2>=s_b_15_3 */
    auto s_b_15_4 = emitter.cmp_ge(s_b_15_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:1793 [D] s_b_15_5 = (v8u16)s_b_15_4 */
    auto s_b_15_5 = emitter.reinterpret(s_b_15_4, emitter.context().types().v8u16());
    /* execute.simd:1795 [F] s_b_15_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1795 [D] s_b_15_7: WriteRegBank 18:s_b_15_6 = s_b_15_5 */
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
    /* execute.simd:1799 [F] s_b_16_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1799 [D] s_b_16_1 = ReadRegBank 19:s_b_16_0 (v2u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:1799 [D] s_b_16_2 = (v2s32)s_b_16_1 */
    auto s_b_16_2 = emitter.reinterpret(s_b_16_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_16_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:1801 [D] s_b_16_4 = s_b_16_2>=s_b_16_3 */
    auto s_b_16_4 = emitter.cmp_ge(s_b_16_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:1801 [D] s_b_16_5 = (v2u32)s_b_16_4 */
    auto s_b_16_5 = emitter.reinterpret(s_b_16_4, emitter.context().types().v2u32());
    /* execute.simd:1802 [F] s_b_16_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1802 [D] s_b_16_7: WriteRegBank 19:s_b_16_6 = s_b_16_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5);
    /* execute.simd:1803 [F] s_b_16_8=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1803 [F] s_b_16_9 = constant u64 0 (const) */
    /* execute.simd:1803 [F] s_b_16_10: WriteRegBank 3:s_b_16_8 = s_b_16_9 */
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
    /* execute.simd:1808 [F] s_b_17_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1808 [D] s_b_17_1 = ReadRegBank 20:s_b_17_0 (v4u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:1808 [D] s_b_17_2 = (v4s32)s_b_17_1 */
    auto s_b_17_2 = emitter.reinterpret(s_b_17_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_17_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:1810 [D] s_b_17_4 = s_b_17_2>=s_b_17_3 */
    auto s_b_17_4 = emitter.cmp_ge(s_b_17_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:1810 [D] s_b_17_5 = (v4u32)s_b_17_4 */
    auto s_b_17_5 = emitter.reinterpret(s_b_17_4, emitter.context().types().v4u32());
    /* execute.simd:1812 [F] s_b_17_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1812 [D] s_b_17_7: WriteRegBank 20:s_b_17_6 = s_b_17_5 */
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
    /* execute.simd:1816 [F] s_b_18_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1816 [D] s_b_18_1 = ReadRegBank 21:s_b_18_0 (v2u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_18_1,emitter.const_u8(16));
    }
    /* execute.simd:1816 [D] s_b_18_2 = (v2s64)s_b_18_1 */
    auto s_b_18_2 = emitter.reinterpret(s_b_18_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_18_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:1818 [D] s_b_18_4 = s_b_18_2>=s_b_18_3 */
    auto s_b_18_4 = emitter.cmp_ge(s_b_18_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:1818 [D] s_b_18_5 = (v2u64)s_b_18_4 */
    auto s_b_18_5 = emitter.reinterpret(s_b_18_4, emitter.context().types().v2u64());
    /* execute.simd:1820 [F] s_b_18_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1820 [D] s_b_18_7: WriteRegBank 21:s_b_18_6 = s_b_18_5 */
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
    /* execute.simd:1824 [D] s_b_19_0 = trap */
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
    /* execute.simd:1831 [F] s_b_20_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1831 [D] s_b_20_1 = ReadRegBank 15:s_b_20_0 (v8u8) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:1831 [D] s_b_20_2 = (v8s8)s_b_20_1 */
    auto s_b_20_2 = emitter.reinterpret(s_b_20_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_20_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:1833 [D] s_b_20_4 = s_b_20_2>s_b_20_3 */
    auto s_b_20_4 = emitter.cmp_gt(s_b_20_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:1833 [D] s_b_20_5 = (v8u8)s_b_20_4 */
    auto s_b_20_5 = emitter.reinterpret(s_b_20_4, emitter.context().types().v8u8());
    /* execute.simd:1834 [F] s_b_20_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1834 [D] s_b_20_7: WriteRegBank 15:s_b_20_6 = s_b_20_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5);
    /* execute.simd:1835 [F] s_b_20_8=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1835 [F] s_b_20_9 = constant u64 0 (const) */
    /* execute.simd:1835 [F] s_b_20_10: WriteRegBank 3:s_b_20_8 = s_b_20_9 */
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
    /* execute.simd:1840 [F] s_b_21_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1840 [D] s_b_21_1 = ReadRegBank 16:s_b_21_0 (v16u8) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:1840 [D] s_b_21_2 = (v16s8)s_b_21_1 */
    auto s_b_21_2 = emitter.reinterpret(s_b_21_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_21_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:1842 [D] s_b_21_4 = s_b_21_2>s_b_21_3 */
    auto s_b_21_4 = emitter.cmp_gt(s_b_21_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:1842 [D] s_b_21_5 = (v16u8)s_b_21_4 */
    auto s_b_21_5 = emitter.reinterpret(s_b_21_4, emitter.context().types().v16u8());
    /* execute.simd:1843 [F] s_b_21_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1843 [D] s_b_21_7: WriteRegBank 16:s_b_21_6 = s_b_21_5 */
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
    /* execute.simd:1848 [F] s_b_22_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1848 [D] s_b_22_1 = ReadRegBank 17:s_b_22_0 (v4u16) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:1848 [D] s_b_22_2 = (v4s16)s_b_22_1 */
    auto s_b_22_2 = emitter.reinterpret(s_b_22_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_22_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:1850 [D] s_b_22_4 = s_b_22_2>s_b_22_3 */
    auto s_b_22_4 = emitter.cmp_gt(s_b_22_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:1850 [D] s_b_22_5 = (v4u16)s_b_22_4 */
    auto s_b_22_5 = emitter.reinterpret(s_b_22_4, emitter.context().types().v4u16());
    /* execute.simd:1851 [F] s_b_22_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1851 [D] s_b_22_7: WriteRegBank 17:s_b_22_6 = s_b_22_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5);
    /* execute.simd:1852 [F] s_b_22_8=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1852 [F] s_b_22_9 = constant u64 0 (const) */
    /* execute.simd:1852 [F] s_b_22_10: WriteRegBank 3:s_b_22_8 = s_b_22_9 */
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
    /* execute.simd:1857 [F] s_b_23_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1857 [D] s_b_23_1 = ReadRegBank 18:s_b_23_0 (v8u16) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:1857 [D] s_b_23_2 = (v8s16)s_b_23_1 */
    auto s_b_23_2 = emitter.reinterpret(s_b_23_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_23_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:1859 [D] s_b_23_4 = s_b_23_2>s_b_23_3 */
    auto s_b_23_4 = emitter.cmp_gt(s_b_23_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:1859 [D] s_b_23_5 = (v8u16)s_b_23_4 */
    auto s_b_23_5 = emitter.reinterpret(s_b_23_4, emitter.context().types().v8u16());
    /* execute.simd:1861 [F] s_b_23_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1861 [D] s_b_23_7: WriteRegBank 18:s_b_23_6 = s_b_23_5 */
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
    /* execute.simd:1865 [F] s_b_24_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1865 [D] s_b_24_1 = ReadRegBank 19:s_b_24_0 (v2u32) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_24_1,emitter.const_u8(8));
    }
    /* execute.simd:1865 [D] s_b_24_2 = (v2s32)s_b_24_1 */
    auto s_b_24_2 = emitter.reinterpret(s_b_24_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_24_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:1867 [D] s_b_24_4 = s_b_24_2>s_b_24_3 */
    auto s_b_24_4 = emitter.cmp_gt(s_b_24_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:1867 [D] s_b_24_5 = (v2u32)s_b_24_4 */
    auto s_b_24_5 = emitter.reinterpret(s_b_24_4, emitter.context().types().v2u32());
    /* execute.simd:1868 [F] s_b_24_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1868 [D] s_b_24_7: WriteRegBank 19:s_b_24_6 = s_b_24_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5);
    /* execute.simd:1869 [F] s_b_24_8=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1869 [F] s_b_24_9 = constant u64 0 (const) */
    /* execute.simd:1869 [F] s_b_24_10: WriteRegBank 3:s_b_24_8 = s_b_24_9 */
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
    /* execute.simd:1874 [F] s_b_25_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1874 [D] s_b_25_1 = ReadRegBank 20:s_b_25_0 (v4u32) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_25_1,emitter.const_u8(16));
    }
    /* execute.simd:1874 [D] s_b_25_2 = (v4s32)s_b_25_1 */
    auto s_b_25_2 = emitter.reinterpret(s_b_25_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_25_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:1876 [D] s_b_25_4 = s_b_25_2>s_b_25_3 */
    auto s_b_25_4 = emitter.cmp_gt(s_b_25_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:1876 [D] s_b_25_5 = (v4u32)s_b_25_4 */
    auto s_b_25_5 = emitter.reinterpret(s_b_25_4, emitter.context().types().v4u32());
    /* execute.simd:1878 [F] s_b_25_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1878 [D] s_b_25_7: WriteRegBank 20:s_b_25_6 = s_b_25_5 */
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
    /* execute.simd:1882 [F] s_b_26_0=sym_7417_3_parameter_inst.rn (const) */
    /* execute.simd:1882 [D] s_b_26_1 = ReadRegBank 21:s_b_26_0 (v2u64) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_26_1,emitter.const_u8(16));
    }
    /* execute.simd:1882 [D] s_b_26_2 = (v2s64)s_b_26_1 */
    auto s_b_26_2 = emitter.reinterpret(s_b_26_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_26_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:1884 [D] s_b_26_4 = s_b_26_2>s_b_26_3 */
    auto s_b_26_4 = emitter.cmp_gt(s_b_26_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:1884 [D] s_b_26_5 = (v2u64)s_b_26_4 */
    auto s_b_26_5 = emitter.reinterpret(s_b_26_4, emitter.context().types().v2u64());
    /* execute.simd:1886 [F] s_b_26_6=sym_7417_3_parameter_inst.rd (const) */
    /* execute.simd:1886 [D] s_b_26_7: WriteRegBank 21:s_b_26_6 = s_b_26_5 */
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
    /* execute.simd:1890 [D] s_b_27_0 = trap */
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
        /* execute.simd:1750 [F] s_b_6_0=sym_7417_3_parameter_inst.rd (const) */
        /* execute.simd:1750 [F] s_b_6_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6138 [F] s_b_6_2: WriteRegBank 2:s_b_6_0 = s_b_6_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6139 [F] s_b_6_3 = constant u64 0 (const) */
        /* execute.simd:6139 [F] s_b_6_4: WriteRegBank 3:s_b_6_0 = s_b_6_3 */
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
        /* execute.simd:1752 [F] s_b_7_0=sym_7417_3_parameter_inst.rd (const) */
        /* execute.simd:1752 [F] s_b_7_1 = constant u64 0 (const) */
        /* execute.simd:6138 [F] s_b_7_2: WriteRegBank 2:s_b_7_0 = s_b_7_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6139 [F] s_b_7_3 = constant u64 0 (const) */
        /* execute.simd:6139 [F] s_b_7_4: WriteRegBank 3:s_b_7_0 = s_b_7_3 */
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
        /* execute.simd:1756 [F] s_b_8_0=sym_7417_3_parameter_inst.rd (const) */
        /* execute.simd:1756 [F] s_b_8_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6138 [F] s_b_8_2: WriteRegBank 2:s_b_8_0 = s_b_8_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6139 [F] s_b_8_3 = constant u64 0 (const) */
        /* execute.simd:6139 [F] s_b_8_4: WriteRegBank 3:s_b_8_0 = s_b_8_3 */
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
        /* execute.simd:1758 [F] s_b_9_0=sym_7417_3_parameter_inst.rd (const) */
        /* execute.simd:1758 [F] s_b_9_1 = constant u64 0 (const) */
        /* execute.simd:6138 [F] s_b_9_2: WriteRegBank 2:s_b_9_0 = s_b_9_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6139 [F] s_b_9_3 = constant u64 0 (const) */
        /* execute.simd:6139 [F] s_b_9_4: WriteRegBank 3:s_b_9_0 = s_b_9_3 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_csinc(const aarch64_decode_a64_COND_SEL&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_55958_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56002_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55980_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55842_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55906_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55751_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55782_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  uint8_t CV_sym_55657_0_state;
  auto DV_sym_55657_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55700_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55936_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2117 [F] s_b_0_0=sym_9001_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_55657_0_state = s_b_0_1 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_55657_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_55657_0_state, emitter.const_u8((uint8_t)0ULL));
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
    case (int32_t)7ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_11;
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
    /* execute.a64:2828 [F] s_b_4_0=sym_9001_3_parameter_inst.cond (const) */
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
    /* execute.a64:2829 [D] s_b_5_0 = sym_55657_0_state uint8_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_55657_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_5_1 = !s_b_5_0 */
    auto s_b_5_1 = emitter.cmp_eq(s_b_5_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_5_2: sym_55700_0_return_symbol = s_b_5_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_55700_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2831 [D] s_b_6_0 = sym_55657_0_state uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_55657_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_6_1: sym_55700_0_return_symbol = s_b_6_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_55700_0_return_symbol, s_b_6_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2795 [D] s_b_7_1: sym_55657_0_state = s_b_7_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_55657_0_state, s_b_7_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2799 [D] s_b_8_1: sym_55657_0_state = s_b_8_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_55657_0_state, s_b_8_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2803 [D] s_b_9_1: sym_55657_0_state = s_b_9_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_55657_0_state, s_b_9_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2807 [D] s_b_10_1: sym_55657_0_state = s_b_10_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_55657_0_state, s_b_10_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_11_1 = ReadReg 2 (u8) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_11_1, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_11_2 = !s_b_11_1 */
    auto s_b_11_2 = emitter.cmp_eq(s_b_11_1, emitter.const_u8(0));
    /* execute.a64:2811 [D] s_b_11_3 = s_b_11_0&s_b_11_2 */
    auto s_b_11_3 = emitter.bitwise_and(s_b_11_0, s_b_11_2);
    /* execute.a64:2811 [D] s_b_11_4: sym_55657_0_state = s_b_11_3, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_55657_0_state, s_b_11_3);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_12_1 = ReadReg 4 (u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_12_1, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_12_2 = s_b_12_0==s_b_12_1 */
    auto s_b_12_2 = emitter.cmp_eq(s_b_12_0, s_b_12_1);
    /* execute.a64:2815 [D] s_b_12_3: sym_55657_0_state = s_b_12_2, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_55657_0_state, s_b_12_2);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_1 = ReadReg 4 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_13_1, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_2 = s_b_13_0==s_b_13_1 */
    auto s_b_13_2 = emitter.cmp_eq(s_b_13_0, s_b_13_1);
    /* execute.a64:2819 [D] s_b_13_3 = ReadReg 2 (u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_13_3, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_13_4 = !s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_eq(s_b_13_3, emitter.const_u8(0));
    /* execute.a64:2819 [D] s_b_13_5 = s_b_13_2&s_b_13_4 */
    auto s_b_13_5 = emitter.bitwise_and(s_b_13_2, s_b_13_4);
    /* execute.a64:2819 [D] s_b_13_6: sym_55657_0_state = s_b_13_5, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_55657_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2823 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_14_1: sym_55657_0_state = s_b_14_0 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_55657_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_55657_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5, b_6,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_55700_0_return_symbol uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_55700_0_return_symbol, emitter.context().types().u8());
    /* execute.a64:2119 [D] s_b_15_1 = (u32)s_b_15_0 */
    auto s_b_15_1 = emitter.zx(s_b_15_0, emitter.context().types().u32());
    /* execute.a64:2119 [F] s_b_15_2 = constant u32 0 (const) */
    /* execute.a64:2119 [D] s_b_15_3 = s_b_15_1==s_b_15_2 */
    auto s_b_15_3 = emitter.cmp_eq(s_b_15_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2119 [D] s_b_15_4: If s_b_15_3: Jump b_1 else b_3 */
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
        /* execute.a64:2120 [F] s_b_1_0=sym_9001_3_parameter_inst.sf (const) */
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
        /* execute.a64:2122 [F] s_b_3_0=sym_9001_3_parameter_inst.sf (const) */
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
        /* execute.a64:2657 [F] s_b_16_0=sym_9001_3_parameter_inst.rm (const) */
        /* execute.a64:2651 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
        /* execute.a64:2651 [F] s_b_16_2 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
        uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_16_4 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_16_5 = ReadRegBank 0:s_b_16_0 (u64) */
        auto s_b_16_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_16_5,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_16_6: Select s_b_16_3 ? s_b_16_4 : s_b_16_5 */
        captive::arch::dbt::el::Value *s_b_16_6;
        s_b_16_6 = (s_b_16_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_16_5);
        /* execute.a64:2657 [D] s_b_16_7: sym_55751_1__R_s_b_1_6 = s_b_16_6, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_55751_1__R_s_b_1_6, s_b_16_6);
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
        /* execute.a64:2659 [F] s_b_17_0=sym_9001_3_parameter_inst.rm (const) */
        /* execute.a64:2646 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
        /* execute.a64:2646 [F] s_b_17_2 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
        uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_17_4 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_17_5 = ReadRegBank 1:s_b_17_0 (u32) */
        auto s_b_17_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_17_5,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_17_6: Select s_b_17_3 ? s_b_17_4 : s_b_17_5 */
        captive::arch::dbt::el::Value *s_b_17_6;
        s_b_17_6 = (s_b_17_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_17_5);
        /* execute.a64:2659 [D] s_b_17_7 = (u64)s_b_17_6 */
        auto s_b_17_7 = emitter.zx(s_b_17_6, emitter.context().types().u64());
        /* execute.a64:2659 [D] s_b_17_8: sym_55751_1__R_s_b_1_6 = s_b_17_7, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_55751_1__R_s_b_1_6, s_b_17_7);
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
        /* ???:4294967295 [F] s_b_18_0=sym_9001_3_parameter_inst.sf (const) */
        /* execute.a64:2120 [D] s_b_18_1 = sym_55751_1__R_s_b_1_6 uint64_t */
        auto s_b_18_1 = emitter.load_local(DV_sym_55751_1__R_s_b_1_6, emitter.context().types().u64());
        /* execute.a64:2120 [F] s_b_18_2 = constant u64 1 (const) */
        /* execute.a64:2120 [D] s_b_18_3 = s_b_18_1+s_b_18_2 */
        auto s_b_18_3 = emitter.add(s_b_18_1, emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:2120 [D] s_b_18_4: sym_55842_3_parameter_value = s_b_18_3, dominates: s_b_22_1 s_b_23_1  */
        emitter.store_local(DV_sym_55842_3_parameter_value, s_b_18_3);
        /* execute.a64:2690 [F] s_b_18_5: If s_b_18_0: Jump b_22 else b_23 (const) */
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
        /* execute.a64:2657 [F] s_b_19_0=sym_9001_3_parameter_inst.rn (const) */
        /* execute.a64:2651 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.a64:2651 [F] s_b_19_2 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
        uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_19_4 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_19_5 = ReadRegBank 0:s_b_19_0 (u64) */
        auto s_b_19_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_5,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_19_6: Select s_b_19_3 ? s_b_19_4 : s_b_19_5 */
        captive::arch::dbt::el::Value *s_b_19_6;
        s_b_19_6 = (s_b_19_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_19_5);
        /* execute.a64:2657 [D] s_b_19_7: sym_55782_1__R_s_b_3_6 = s_b_19_6, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_55782_1__R_s_b_3_6, s_b_19_6);
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
        /* execute.a64:2659 [F] s_b_20_0=sym_9001_3_parameter_inst.rn (const) */
        /* execute.a64:2646 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
        /* execute.a64:2646 [F] s_b_20_2 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
        uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_20_4 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_20_5 = ReadRegBank 1:s_b_20_0 (u32) */
        auto s_b_20_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_5,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_20_6: Select s_b_20_3 ? s_b_20_4 : s_b_20_5 */
        captive::arch::dbt::el::Value *s_b_20_6;
        s_b_20_6 = (s_b_20_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_20_5);
        /* execute.a64:2659 [D] s_b_20_7 = (u64)s_b_20_6 */
        auto s_b_20_7 = emitter.zx(s_b_20_6, emitter.context().types().u64());
        /* execute.a64:2659 [D] s_b_20_8: sym_55782_1__R_s_b_3_6 = s_b_20_7, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_55782_1__R_s_b_3_6, s_b_20_7);
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
        /* ???:4294967295 [F] s_b_21_0=sym_9001_3_parameter_inst.sf (const) */
        /* execute.a64:2122 [D] s_b_21_1 = sym_55782_1__R_s_b_3_6 uint64_t */
        auto s_b_21_1 = emitter.load_local(DV_sym_55782_1__R_s_b_3_6, emitter.context().types().u64());
        /* execute.a64:2122 [D] s_b_21_2: sym_55906_3_parameter_value = s_b_21_1, dominates: s_b_24_1 s_b_25_1  */
        emitter.store_local(DV_sym_55906_3_parameter_value, s_b_21_1);
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
        /* execute.a64:2691 [F] s_b_22_0=sym_9001_3_parameter_inst.rd (const) */
        /* execute.a64:2691 [D] s_b_22_1 = sym_55842_3_parameter_value uint64_t */
        auto s_b_22_1 = emitter.load_local(DV_sym_55842_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_22_2: sym_55936_3_parameter_value = s_b_22_1, dominates: s_b_26_1  */
        emitter.store_local(DV_sym_55936_3_parameter_value, s_b_22_1);
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
        /* execute.a64:2693 [F] s_b_23_0=sym_9001_3_parameter_inst.rd (const) */
        /* execute.a64:2693 [D] s_b_23_1 = sym_55842_3_parameter_value uint64_t */
        auto s_b_23_1 = emitter.load_local(DV_sym_55842_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_23_2 = (u32)s_b_23_1 */
        auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_23_3 = (u64)s_b_23_2 */
        auto s_b_23_3 = emitter.zx(s_b_23_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_23_4: sym_55958_3_parameter_value = s_b_23_3, dominates: s_b_27_1  */
        emitter.store_local(DV_sym_55958_3_parameter_value, s_b_23_3);
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
        /* execute.a64:2691 [F] s_b_24_0=sym_9001_3_parameter_inst.rd (const) */
        /* execute.a64:2691 [D] s_b_24_1 = sym_55906_3_parameter_value uint64_t */
        auto s_b_24_1 = emitter.load_local(DV_sym_55906_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_24_2: sym_55980_3_parameter_value = s_b_24_1, dominates: s_b_28_1  */
        emitter.store_local(DV_sym_55980_3_parameter_value, s_b_24_1);
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
        /* execute.a64:2693 [F] s_b_25_0=sym_9001_3_parameter_inst.rd (const) */
        /* execute.a64:2693 [D] s_b_25_1 = sym_55906_3_parameter_value uint64_t */
        auto s_b_25_1 = emitter.load_local(DV_sym_55906_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_25_2 = (u32)s_b_25_1 */
        auto s_b_25_2 = emitter.truncate(s_b_25_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_25_3 = (u64)s_b_25_2 */
        auto s_b_25_3 = emitter.zx(s_b_25_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_25_4: sym_56002_3_parameter_value = s_b_25_3, dominates: s_b_29_1  */
        emitter.store_local(DV_sym_56002_3_parameter_value, s_b_25_3);
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
        /* execute.a64:2684 [F] s_b_26_0=sym_9001_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_26_1 = sym_55936_3_parameter_value uint64_t */
        auto s_b_26_1 = emitter.load_local(DV_sym_55936_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(8));
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
        /* execute.a64:2684 [F] s_b_27_0=sym_9001_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_27_1 = sym_55958_3_parameter_value uint64_t */
        auto s_b_27_1 = emitter.load_local(DV_sym_55958_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_27_2: WriteRegBank 0:s_b_27_0 = s_b_27_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_27_1,emitter.const_u8(8));
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
        /* execute.a64:2684 [F] s_b_28_0=sym_9001_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_28_1 = sym_55980_3_parameter_value uint64_t */
        auto s_b_28_1 = emitter.load_local(DV_sym_55980_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_28_2: WriteRegBank 0:s_b_28_0 = s_b_28_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_28_1,emitter.const_u8(8));
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
        /* execute.a64:2684 [F] s_b_29_0=sym_9001_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_29_1 = sym_56002_3_parameter_value uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_56002_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_29_2: WriteRegBank 0:s_b_29_0 = s_b_29_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_29_1,emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_eorsr(const aarch64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_57595_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_9980_0_op2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_9973_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_57644_1__R_s_b_17_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_57710_1__R_s_b_21_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_57411_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_57427_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_57735_1__R_s_b_23_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_57617_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_57669_1__R_s_b_20_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_57565_1__R_s_b_6_10;
  auto DV_sym_57565_1__R_s_b_6_10 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2493 [F] s_b_0_0=sym_9968_3_parameter_inst.sf (const) */
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
    /* execute.a64:2496 [D] s_b_1_0 = sym_9980_0_op2 uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_9980_0_op2, emitter.context().types().u64());
    /* execute.a64:2496 [D] s_b_1_1 = ~s_b_1_0 */
    auto s_b_1_1 = emitter.bitwise_not(s_b_1_0);
    /* execute.a64:2496 [D] s_b_1_2: sym_9980_0_op2 = s_b_1_1, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_9980_0_op2, s_b_1_1);
    /* execute.a64:2496 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_18,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2498 [D] s_b_2_0 = sym_9973_0_op1 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_9973_0_op1, emitter.context().types().u64());
    /* execute.a64:2498 [D] s_b_2_1 = sym_9980_0_op2 uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_9980_0_op2, emitter.context().types().u64());
    /* execute.a64:2498 [D] s_b_2_2 = s_b_2_0^s_b_2_1 */
    auto s_b_2_2 = emitter.bitwise_xor(s_b_2_0, s_b_2_1);
    /* execute.a64:2500 [F] s_b_2_3=sym_9968_3_parameter_inst.sf (const) */
    /* execute.a64:2500 [D] s_b_2_4: sym_57427_3_parameter_value = s_b_2_2, dominates: s_b_6_1 s_b_7_1  */
    emitter.store_local(DV_sym_57427_3_parameter_value, s_b_2_2);
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
    /* execute.a64:2657 [F] s_b_3_0=sym_9968_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:2651 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_3_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_3_5 = ReadRegBank 0:s_b_3_0 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_3_6: Select s_b_3_3 ? s_b_3_4 : s_b_3_5 */
    captive::arch::dbt::el::Value *s_b_3_6;
    s_b_3_6 = (s_b_3_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_3_5);
    /* execute.a64:2657 [D] s_b_3_7: sym_57411_1__R_s_b_0_4 = s_b_3_6, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_57411_1__R_s_b_0_4, s_b_3_6);
    /* execute.a64:2657 [F] s_b_3_8: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2659 [F] s_b_4_0=sym_9968_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2646 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_4_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_4_5 = ReadRegBank 1:s_b_4_0 (u32) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    captive::arch::dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2659 [D] s_b_4_7 = (u64)s_b_4_6 */
    auto s_b_4_7 = emitter.zx(s_b_4_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_4_8: sym_57411_1__R_s_b_0_4 = s_b_4_7, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_57411_1__R_s_b_0_4, s_b_4_7);
    /* execute.a64:2659 [F] s_b_4_9: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_3, b_4,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2493 [D] s_b_5_0 = sym_57411_1__R_s_b_0_4 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_57411_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2493 [D] s_b_5_1: sym_9973_0_op1 = s_b_5_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_9973_0_op1, s_b_5_0);
    /* execute.a64:2494 [F] s_b_5_2=sym_9968_3_parameter_inst.imm6 (const) */
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
    /* execute.a64:2691 [F] s_b_6_0=sym_9968_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_6_1 = sym_57427_3_parameter_value uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_57427_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_6_2: sym_57595_3_parameter_value = s_b_6_1, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_57595_3_parameter_value, s_b_6_1);
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
    /* execute.a64:2693 [F] s_b_7_0=sym_9968_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_7_1 = sym_57427_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_57427_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_7_2 = (u32)s_b_7_1 */
    auto s_b_7_2 = emitter.truncate(s_b_7_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_7_3 = (u64)s_b_7_2 */
    auto s_b_7_3 = emitter.zx(s_b_7_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_7_4: sym_57617_3_parameter_value = s_b_7_3, dominates: s_b_20_1  */
    emitter.store_local(DV_sym_57617_3_parameter_value, s_b_7_3);
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
    /* execute.a64:2572 [F] s_b_9_0=sym_9968_3_parameter_inst.sf (const) */
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
    /* execute.a64:2574 [F] s_b_10_0=sym_9968_3_parameter_inst.shift (const) */
    /* execute.a64:2575 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.a64:2579 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.a64:2583 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.a64:2587 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.a64:2574 [F] s_b_10_5: Switch s_b_10_0: < <todo> > def b_11 (const) -> b_11, b_13, b_14, b_15, b_12,  */
    switch (insn.shift) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_14;
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
    /* execute.a64:2598 [F] s_b_11_2: sym_57565_1__R_s_b_6_10 = s_b_11_1 (const), dominates: s_b_18_0  */
    CV_sym_57565_1__R_s_b_6_10 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_57565_1__R_s_b_6_10, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2598 [F] s_b_11_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_10,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2577 [F] s_b_12_0=sym_9968_3_parameter_inst.sf (const) */
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
    /* execute.a64:2585 [F] s_b_13_0=sym_9968_3_parameter_inst.sf (const) */
    /* execute.a64:2665 [F] s_b_13_1: If s_b_13_0: Jump b_27 else b_28 (const) */
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
    /* execute.a64:2589 [F] s_b_14_0=sym_9968_3_parameter_inst.sf (const) */
    /* execute.a64:2589 [F] s_b_14_1: If s_b_14_0: Jump b_16 else b_17 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_10,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2581 [F] s_b_15_0=sym_9968_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_15_1: If s_b_15_0: Jump b_30 else b_31 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2657 [F] s_b_16_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2651 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_16_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_16_5 = ReadRegBank 0:s_b_16_0 (u64) */
    auto s_b_16_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_16_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_16_6: Select s_b_16_3 ? s_b_16_4 : s_b_16_5 */
    captive::arch::dbt::el::Value *s_b_16_6;
    s_b_16_6 = (s_b_16_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_16_5);
    /* execute.a64:2590 [F] s_b_16_7=sym_9968_3_parameter_inst.imm6 (const) */
    /* execute.a64:2590 [F] s_b_16_8 = (u64)s_b_16_7 (const) */
    /* execute.a64:2590 [D] s_b_16_9 = s_b_16_6>>>s_b_16_8 */
    auto s_b_16_9 = emitter.ror(s_b_16_6, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2590 [D] s_b_16_10: sym_57565_1__R_s_b_6_10 = s_b_16_9, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_57565_1__R_s_b_6_10, s_b_16_9);
    /* execute.a64:2590 [F] s_b_16_11: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_14,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2659 [F] s_b_17_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
    /* execute.a64:2646 [F] s_b_17_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_17_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_17_5 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_17_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_17_6: Select s_b_17_3 ? s_b_17_4 : s_b_17_5 */
    captive::arch::dbt::el::Value *s_b_17_6;
    s_b_17_6 = (s_b_17_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_17_5);
    /* execute.a64:2659 [D] s_b_17_7 = (u64)s_b_17_6 */
    auto s_b_17_7 = emitter.zx(s_b_17_6, emitter.context().types().u64());
    /* execute.a64:2592 [D] s_b_17_8 = (u32)s_b_17_7 */
    auto s_b_17_8 = emitter.truncate(s_b_17_7, emitter.context().types().u32());
    /* execute.a64:2592 [F] s_b_17_9=sym_9968_3_parameter_inst.imm6 (const) */
    /* execute.a64:2592 [F] s_b_17_10 = (u32)s_b_17_9 (const) */
    /* execute.a64:2592 [D] s_b_17_11 = s_b_17_8>>>s_b_17_10 */
    auto s_b_17_11 = emitter.ror(s_b_17_8, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2592 [D] s_b_17_12 = (u64)s_b_17_11 */
    auto s_b_17_12 = emitter.zx(s_b_17_11, emitter.context().types().u64());
    /* execute.a64:2592 [D] s_b_17_13: sym_57565_1__R_s_b_6_10 = s_b_17_12, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_57565_1__R_s_b_6_10, s_b_17_12);
    /* execute.a64:2592 [F] s_b_17_14: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_11, b_16, b_17, b_23, b_26, b_29, b_32,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2494 [D] s_b_18_0 = sym_57565_1__R_s_b_6_10 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_57565_1__R_s_b_6_10, emitter.context().types().u64());
    /* execute.a64:2494 [D] s_b_18_1: sym_9980_0_op2 = s_b_18_0, dominates: s_b_1_0 s_b_2_1  */
    emitter.store_local(DV_sym_9980_0_op2, s_b_18_0);
    /* execute.a64:2496 [F] s_b_18_2=sym_9968_3_parameter_inst.N (const) */
    /* execute.a64:2496 [F] s_b_18_3: If s_b_18_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2684 [F] s_b_19_0=sym_9968_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_19_1 = sym_57595_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_57595_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_19_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_19_1);
    /* execute.a64:0 [F] s_b_19_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2684 [F] s_b_20_0=sym_9968_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_20_1 = sym_57617_3_parameter_value uint64_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_57617_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_20_2: WriteRegBank 0:s_b_20_0 = s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_1);
    /* execute.a64:0 [F] s_b_20_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_9,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2657 [F] s_b_21_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:2651 [F] s_b_21_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_21_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_21_5 = ReadRegBank 0:s_b_21_0 (u64) */
    auto s_b_21_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_21_6: Select s_b_21_3 ? s_b_21_4 : s_b_21_5 */
    captive::arch::dbt::el::Value *s_b_21_6;
    s_b_21_6 = (s_b_21_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_21_5);
    /* execute.a64:2657 [D] s_b_21_7: sym_57644_1__R_s_b_17_4 = s_b_21_6, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_57644_1__R_s_b_17_4, s_b_21_6);
    /* execute.a64:2657 [F] s_b_21_8: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_9,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2659 [F] s_b_22_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
    /* execute.a64:2646 [F] s_b_22_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_22_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_22_5 = ReadRegBank 1:s_b_22_0 (u32) */
    auto s_b_22_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_22_6: Select s_b_22_3 ? s_b_22_4 : s_b_22_5 */
    captive::arch::dbt::el::Value *s_b_22_6;
    s_b_22_6 = (s_b_22_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_22_5);
    /* execute.a64:2659 [D] s_b_22_7 = (u64)s_b_22_6 */
    auto s_b_22_7 = emitter.zx(s_b_22_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_22_8: sym_57644_1__R_s_b_17_4 = s_b_22_7, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_57644_1__R_s_b_17_4, s_b_22_7);
    /* execute.a64:2659 [F] s_b_22_9: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2572 [D] s_b_23_0 = sym_57644_1__R_s_b_17_4 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_57644_1__R_s_b_17_4, emitter.context().types().u64());
    /* execute.a64:2572 [D] s_b_23_1: sym_57565_1__R_s_b_6_10 = s_b_23_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_57565_1__R_s_b_6_10, s_b_23_0);
    /* execute.a64:2572 [F] s_b_23_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_12,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2657 [F] s_b_24_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:2651 [F] s_b_24_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_24_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_24_5 = ReadRegBank 0:s_b_24_0 (u64) */
    auto s_b_24_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_24_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_24_6: Select s_b_24_3 ? s_b_24_4 : s_b_24_5 */
    captive::arch::dbt::el::Value *s_b_24_6;
    s_b_24_6 = (s_b_24_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_24_5);
    /* execute.a64:2657 [D] s_b_24_7: sym_57669_1__R_s_b_20_4 = s_b_24_6, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_57669_1__R_s_b_20_4, s_b_24_6);
    /* execute.a64:2657 [F] s_b_24_8: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_12,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2659 [F] s_b_25_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:2646 [F] s_b_25_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_25_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_25_5 = ReadRegBank 1:s_b_25_0 (u32) */
    auto s_b_25_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_25_6: Select s_b_25_3 ? s_b_25_4 : s_b_25_5 */
    captive::arch::dbt::el::Value *s_b_25_6;
    s_b_25_6 = (s_b_25_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_25_5);
    /* execute.a64:2659 [D] s_b_25_7 = (u64)s_b_25_6 */
    auto s_b_25_7 = emitter.zx(s_b_25_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_25_8: sym_57669_1__R_s_b_20_4 = s_b_25_7, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_57669_1__R_s_b_20_4, s_b_25_7);
    /* execute.a64:2659 [F] s_b_25_9: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_24, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2577 [D] s_b_26_0 = sym_57669_1__R_s_b_20_4 uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_57669_1__R_s_b_20_4, emitter.context().types().u64());
    /* execute.a64:2577 [F] s_b_26_1=sym_9968_3_parameter_inst.imm6 (const) */
    /* execute.a64:2577 [F] s_b_26_2 = (u64)s_b_26_1 (const) */
    /* execute.a64:2577 [D] s_b_26_3 = s_b_26_0<<s_b_26_2 */
    auto s_b_26_3 = emitter.shl(s_b_26_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2577 [D] s_b_26_4: sym_57565_1__R_s_b_6_10 = s_b_26_3, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_57565_1__R_s_b_6_10, s_b_26_3);
    /* execute.a64:2577 [F] s_b_26_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2666 [F] s_b_27_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
    /* execute.a64:2666 [F] s_b_27_2 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_27_4 = constant s64 0 (const) */
    /* execute.a64:2666 [F] s_b_27_5=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [D] s_b_27_6 = ReadRegBank 0:s_b_27_5 (u64) */
    auto s_b_27_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_27_6,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_27_7 = (s64)s_b_27_6 */
    auto s_b_27_7 = emitter.reinterpret(s_b_27_6, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_27_8: Select s_b_27_3 ? s_b_27_4 : s_b_27_7 */
    captive::arch::dbt::el::Value *s_b_27_8;
    s_b_27_8 = (s_b_27_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_27_7);
    /* execute.a64:2666 [D] s_b_27_9: sym_57710_1__R_s_b_21_4 = s_b_27_8, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_57710_1__R_s_b_21_4, s_b_27_8);
    /* execute.a64:2666 [F] s_b_27_10: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_13,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2668 [F] s_b_28_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:2668 [F] s_b_28_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_28_4 = constant s64 0 (const) */
    /* execute.a64:2668 [F] s_b_28_5=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [D] s_b_28_6 = ReadRegBank 1:s_b_28_5 (u32) */
    auto s_b_28_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_6,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_28_7 = (s32)s_b_28_6 */
    auto s_b_28_7 = emitter.reinterpret(s_b_28_6, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_28_8 = (s64)s_b_28_7 */
    auto s_b_28_8 = emitter.sx(s_b_28_7, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_28_9: Select s_b_28_3 ? s_b_28_4 : s_b_28_8 */
    captive::arch::dbt::el::Value *s_b_28_9;
    s_b_28_9 = (s_b_28_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_28_8);
    /* execute.a64:2668 [D] s_b_28_10: sym_57710_1__R_s_b_21_4 = s_b_28_9, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_57710_1__R_s_b_21_4, s_b_28_9);
    /* execute.a64:2668 [F] s_b_28_11: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2585 [D] s_b_29_0 = sym_57710_1__R_s_b_21_4 int64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_57710_1__R_s_b_21_4, emitter.context().types().s64());
    /* execute.a64:2585 [F] s_b_29_1=sym_9968_3_parameter_inst.imm6 (const) */
    /* execute.a64:2585 [D] s_b_29_2 = (u64)s_b_29_0 */
    auto s_b_29_2 = emitter.reinterpret(s_b_29_0, emitter.context().types().u64());
    /* execute.a64:2585 [F] s_b_29_3 = (u64)s_b_29_1 (const) */
    /* execute.a64:2585 [D] s_b_29_4 = s_b_29_2->>s_b_29_3 */
    auto s_b_29_4 = emitter.sar(s_b_29_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2585 [D] s_b_29_5 = (u64)s_b_29_4 */
    auto s_b_29_5 = (captive::arch::dbt::el::Value *)s_b_29_4;
    /* execute.a64:2585 [D] s_b_29_6: sym_57565_1__R_s_b_6_10 = s_b_29_5, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_57565_1__R_s_b_6_10, s_b_29_5);
    /* execute.a64:2585 [F] s_b_29_7: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_15,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2657 [F] s_b_30_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_30_1 = (u32)s_b_30_0 (const) */
    /* execute.a64:2651 [F] s_b_30_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_30_3 = s_b_30_1==s_b_30_2 (const) */
    uint8_t s_b_30_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_30_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_30_5 = ReadRegBank 0:s_b_30_0 (u64) */
    auto s_b_30_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_30_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_30_6: Select s_b_30_3 ? s_b_30_4 : s_b_30_5 */
    captive::arch::dbt::el::Value *s_b_30_6;
    s_b_30_6 = (s_b_30_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_30_5);
    /* execute.a64:2657 [D] s_b_30_7: sym_57735_1__R_s_b_23_4 = s_b_30_6, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_57735_1__R_s_b_23_4, s_b_30_6);
    /* execute.a64:2657 [F] s_b_30_8: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_15,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2659 [F] s_b_31_0=sym_9968_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
    /* execute.a64:2646 [F] s_b_31_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_31_3 = s_b_31_1==s_b_31_2 (const) */
    uint8_t s_b_31_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_31_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_31_5 = ReadRegBank 1:s_b_31_0 (u32) */
    auto s_b_31_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_31_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_31_6: Select s_b_31_3 ? s_b_31_4 : s_b_31_5 */
    captive::arch::dbt::el::Value *s_b_31_6;
    s_b_31_6 = (s_b_31_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_31_5);
    /* execute.a64:2659 [D] s_b_31_7 = (u64)s_b_31_6 */
    auto s_b_31_7 = emitter.zx(s_b_31_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_31_8: sym_57735_1__R_s_b_23_4 = s_b_31_7, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_57735_1__R_s_b_23_4, s_b_31_7);
    /* execute.a64:2659 [F] s_b_31_9: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2581 [D] s_b_32_0 = sym_57735_1__R_s_b_23_4 uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_57735_1__R_s_b_23_4, emitter.context().types().u64());
    /* execute.a64:2581 [F] s_b_32_1=sym_9968_3_parameter_inst.imm6 (const) */
    /* execute.a64:2581 [F] s_b_32_2 = (u64)s_b_32_1 (const) */
    /* execute.a64:2581 [D] s_b_32_3 = s_b_32_0>>s_b_32_2 */
    auto s_b_32_3 = emitter.shr(s_b_32_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2581 [D] s_b_32_4: sym_57565_1__R_s_b_6_10 = s_b_32_3, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_57565_1__R_s_b_6_10, s_b_32_3);
    /* execute.a64:2581 [F] s_b_32_5: Jump b_18 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fccmpe(const aarch64_decode_a64_FP_CCMP&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  uint8_t CV_sym_59539_0_state;
  auto DV_sym_59539_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_59582_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4612 [F] s_b_0_0=sym_10438_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_59539_0_state = s_b_0_1 (const), dominates: s_b_7_0 s_b_8_0  */
    CV_sym_59539_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_59539_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2793 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_10, b_9, b_11, b_16, b_15, b_6, b_14, b_13, b_12,  */
    switch (s_b_0_5) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_16;
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
  /* b_0, b_9, b_10, b_11, b_12, b_13, b_14, b_15, b_16,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2828 [F] s_b_6_0=sym_10438_3_parameter_inst.cond (const) */
    /* execute.a64:2828 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2828 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_6_3 = s_b_6_1&s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_6_6 = (u64)s_b_6_0 (const) */
    /* execute.a64:2828 [F] s_b_6_7 = constant u64 f (const) */
    /* execute.a64:2828 [F] s_b_6_8 = s_b_6_6!=s_b_6_7 (const) */
    uint8_t s_b_6_8 = ((uint8_t)(((uint64_t)insn.cond) != (uint64_t)15ULL));
    /* ???:4294967295 [F] s_b_6_9 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_6_10 = s_b_6_5!=s_b_6_9 (const) */
    uint8_t s_b_6_10 = ((uint8_t)(s_b_6_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_11 = s_b_6_8!=s_b_6_9 (const) */
    uint8_t s_b_6_11 = ((uint8_t)(s_b_6_8 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_12 = s_b_6_10&s_b_6_11 (const) */
    uint8_t s_b_6_12 = ((uint8_t)(s_b_6_10 & s_b_6_11));
    /* execute.a64:2828 [F] s_b_6_13: If s_b_6_12: Jump b_7 else b_8 (const) */
    if (s_b_6_12) 
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
    /* execute.a64:2829 [D] s_b_7_0 = sym_59539_0_state uint8_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_59539_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_7_1 = !s_b_7_0 */
    auto s_b_7_1 = emitter.cmp_eq(s_b_7_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_7_2: sym_59582_0_return_symbol = s_b_7_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_59582_0_return_symbol, s_b_7_1);
    /* ???:4294967295 [F] s_b_7_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2831 [D] s_b_8_0 = sym_59539_0_state uint8_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_59539_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_8_1: sym_59582_0_return_symbol = s_b_8_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_59582_0_return_symbol, s_b_8_0);
    /* ???:4294967295 [F] s_b_8_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2795 [D] s_b_9_0 = ReadReg 2 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2795 [D] s_b_9_1: sym_59539_0_state = s_b_9_0, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_59539_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2799 [D] s_b_10_0 = ReadReg 3 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2799 [D] s_b_10_1: sym_59539_0_state = s_b_10_0, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_59539_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2803 [D] s_b_11_0 = ReadReg 1 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2803 [D] s_b_11_1: sym_59539_0_state = s_b_11_0, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_59539_0_state, s_b_11_0);
    /* execute.a64:0 [F] s_b_11_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2807 [D] s_b_12_0 = ReadReg 4 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2807 [D] s_b_12_1: sym_59539_0_state = s_b_12_0, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_59539_0_state, s_b_12_0);
    /* execute.a64:0 [F] s_b_12_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2811 [D] s_b_13_0 = ReadReg 3 (u8) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_13_1 = ReadReg 2 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_13_1, emitter.const_u8(1));
    }
    /* execute.a64:2811 [D] s_b_13_2 = !s_b_13_1 */
    auto s_b_13_2 = emitter.cmp_eq(s_b_13_1, emitter.const_u8(0));
    /* execute.a64:2811 [D] s_b_13_3 = s_b_13_0&s_b_13_2 */
    auto s_b_13_3 = emitter.bitwise_and(s_b_13_0, s_b_13_2);
    /* execute.a64:2811 [D] s_b_13_4: sym_59539_0_state = s_b_13_3, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_59539_0_state, s_b_13_3);
    /* execute.a64:0 [F] s_b_13_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2815 [D] s_b_14_0 = ReadReg 1 (u8) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_14_0, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_14_1 = ReadReg 4 (u8) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_1, emitter.const_u8(1));
    }
    /* execute.a64:2815 [D] s_b_14_2 = s_b_14_0==s_b_14_1 */
    auto s_b_14_2 = emitter.cmp_eq(s_b_14_0, s_b_14_1);
    /* execute.a64:2815 [D] s_b_14_3: sym_59539_0_state = s_b_14_2, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_59539_0_state, s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2819 [D] s_b_15_0 = ReadReg 1 (u8) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_15_0, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_15_1 = ReadReg 4 (u8) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_15_1, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_15_2 = s_b_15_0==s_b_15_1 */
    auto s_b_15_2 = emitter.cmp_eq(s_b_15_0, s_b_15_1);
    /* execute.a64:2819 [D] s_b_15_3 = ReadReg 2 (u8) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_15_3, emitter.const_u8(1));
    }
    /* execute.a64:2819 [D] s_b_15_4 = !s_b_15_3 */
    auto s_b_15_4 = emitter.cmp_eq(s_b_15_3, emitter.const_u8(0));
    /* execute.a64:2819 [D] s_b_15_5 = s_b_15_2&s_b_15_4 */
    auto s_b_15_5 = emitter.bitwise_and(s_b_15_2, s_b_15_4);
    /* execute.a64:2819 [D] s_b_15_6: sym_59539_0_state = s_b_15_5, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_59539_0_state, s_b_15_5);
    /* execute.a64:0 [F] s_b_15_7: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2823 [F] s_b_16_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_16_1: sym_59539_0_state = s_b_16_0 (const), dominates: s_b_7_0 s_b_8_0  */
    CV_sym_59539_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_59539_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_16_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_7, b_8,  */
  fixed_block_b_17: 
  {
    /* ???:4294967295 [D] s_b_17_0 = sym_59582_0_return_symbol uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_59582_0_return_symbol, emitter.context().types().u8());
    /* execute.simd:4614 [D] s_b_17_1 = (u32)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u32());
    /* execute.simd:4614 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.simd:4614 [D] s_b_17_3 = s_b_17_1==s_b_17_2 */
    auto s_b_17_3 = emitter.cmp_eq(s_b_17_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:4614 [D] s_b_17_4: If s_b_17_3: Jump b_1 else b_3 */
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
        /* execute.simd:4615 [F] s_b_1_0=sym_10438_3_parameter_inst.nzcv (const) */
        /* execute.simd:4615 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
        /* execute.simd:4615 [F] s_b_1_2 = constant u32 8 (const) */
        /* execute.simd:4615 [F] s_b_1_3 = s_b_1_1&s_b_1_2 (const) */
        uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)8ULL));
        /* execute.simd:4615 [F] s_b_1_4 = constant u32 8 (const) */
        /* execute.simd:4615 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
        uint8_t s_b_1_5 = ((uint8_t)(s_b_1_3 == (uint32_t)8ULL));
        /* execute.simd:4615 [F] s_b_1_6: WriteReg 1 = s_b_1_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), emitter.const_u8(s_b_1_5), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1296), emitter.const_u8(s_b_1_5));
        /* execute.simd:4616 [F] s_b_1_7=sym_10438_3_parameter_inst.nzcv (const) */
        /* execute.simd:4616 [F] s_b_1_8 = (u32)s_b_1_7 (const) */
        /* execute.simd:4616 [F] s_b_1_9 = constant u32 4 (const) */
        /* execute.simd:4616 [F] s_b_1_10 = s_b_1_8&s_b_1_9 (const) */
        uint32_t s_b_1_10 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)4ULL));
        /* execute.simd:4616 [F] s_b_1_11 = constant u32 4 (const) */
        /* execute.simd:4616 [F] s_b_1_12 = s_b_1_10==s_b_1_11 (const) */
        uint8_t s_b_1_12 = ((uint8_t)(s_b_1_10 == (uint32_t)4ULL));
        /* execute.simd:4616 [F] s_b_1_13: WriteReg 2 = s_b_1_12 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), emitter.const_u8(s_b_1_12), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1297), emitter.const_u8(s_b_1_12));
        /* execute.simd:4617 [F] s_b_1_14=sym_10438_3_parameter_inst.nzcv (const) */
        /* execute.simd:4617 [F] s_b_1_15 = (u32)s_b_1_14 (const) */
        /* execute.simd:4617 [F] s_b_1_16 = constant u32 2 (const) */
        /* execute.simd:4617 [F] s_b_1_17 = s_b_1_15&s_b_1_16 (const) */
        uint32_t s_b_1_17 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)2ULL));
        /* execute.simd:4617 [F] s_b_1_18 = constant u32 2 (const) */
        /* execute.simd:4617 [F] s_b_1_19 = s_b_1_17==s_b_1_18 (const) */
        uint8_t s_b_1_19 = ((uint8_t)(s_b_1_17 == (uint32_t)2ULL));
        /* execute.simd:4617 [F] s_b_1_20: WriteReg 3 = s_b_1_19 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8(s_b_1_19), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1298), emitter.const_u8(s_b_1_19));
        /* execute.simd:4618 [F] s_b_1_21=sym_10438_3_parameter_inst.nzcv (const) */
        /* execute.simd:4618 [F] s_b_1_22 = (u32)s_b_1_21 (const) */
        /* execute.simd:4618 [F] s_b_1_23 = constant u32 1 (const) */
        /* execute.simd:4618 [F] s_b_1_24 = s_b_1_22&s_b_1_23 (const) */
        uint32_t s_b_1_24 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)1ULL));
        /* execute.simd:4618 [F] s_b_1_25 = constant u32 1 (const) */
        /* execute.simd:4618 [F] s_b_1_26 = s_b_1_24==s_b_1_25 (const) */
        uint8_t s_b_1_26 = ((uint8_t)(s_b_1_24 == (uint32_t)1ULL));
        /* execute.simd:4618 [F] s_b_1_27: WriteReg 4 = s_b_1_26 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8(s_b_1_26), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1299), emitter.const_u8(s_b_1_26));
        /* execute.simd:4615 [F] s_b_1_28: Jump b_2 (const) */
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
        /* execute.simd:4620 [F] s_b_3_0=sym_10438_3_parameter_inst.type (const) */
        /* execute.simd:4620 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.simd:4620 [F] s_b_3_2 = constant u32 0 (const) */
        /* execute.simd:4620 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
        uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
        /* execute.simd:4620 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
        if (s_b_3_3) 
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
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.simd:4622 [F] s_b_4_0=sym_10438_3_parameter_inst.rn (const) */
        /* execute.simd:6092 [D] s_b_4_1 = ReadRegBank 9:s_b_4_0 (f32) */
        auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(4));
        }
        /* execute.simd:4623 [F] s_b_4_2=sym_10438_3_parameter_inst.rm (const) */
        /* execute.simd:6092 [D] s_b_4_3 = ReadRegBank 9:s_b_4_2 (f32) */
        auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(4));
        }
        /* execute.simd:4624 [D] s_b_4_4 = __builtin_cmpf32_flags */
        emitter.call(__captive___builtin_cmpf32_flags, s_b_4_1, s_b_4_3);
        /* execute.simd:4622 [F] s_b_4_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:4627 [F] s_b_5_0=sym_10438_3_parameter_inst.rn (const) */
        /* execute.simd:6097 [D] s_b_5_1 = ReadRegBank 11:s_b_5_0 (f64) */
        auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(8));
        }
        /* execute.simd:4628 [F] s_b_5_2=sym_10438_3_parameter_inst.rm (const) */
        /* execute.simd:6097 [D] s_b_5_3 = ReadRegBank 11:s_b_5_2 (f64) */
        auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(8));
        }
        /* execute.simd:4629 [D] s_b_5_4 = __builtin_cmpf64_flags */
        emitter.call(__captive___builtin_cmpf64_flags, s_b_5_1, s_b_5_3);
        /* execute.simd:4627 [F] s_b_5_5: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fcvtz_fxp(const aarch64_decode_a64_CVT_FP_FXP&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_61112_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_60999_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_61067_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_61157_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_61045_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_61135_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_61089_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_61022_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_11155_0_mulp;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4400 [F] s_b_0_0 = constant u64 1 (const) */
    /* execute.simd:4400 [F] s_b_0_1=sym_11150_3_parameter_inst.immu64 (const) */
    /* execute.simd:4400 [F] s_b_0_2 = s_b_0_0<<s_b_0_1 (const) */
    uint64_t s_b_0_2 = ((uint64_t)((uint64_t)1ULL << insn.immu64));
    /* execute.simd:4400 [F] s_b_0_3: sym_11155_0_mulp = s_b_0_2 (const), dominates: s_b_6_3 s_b_7_3 s_b_8_3 s_b_9_3 s_b_12_3 s_b_13_3 s_b_14_3 s_b_15_3  */
    CV_sym_11155_0_mulp = s_b_0_2;
    /* execute.simd:4402 [F] s_b_0_4=sym_11150_3_parameter_inst.opcode (const) */
    /* execute.simd:4402 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.simd:4402 [F] s_b_0_6 = constant u32 0 (const) */
    /* execute.simd:4402 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)0ULL));
    /* execute.simd:4402 [F] s_b_0_8: If s_b_0_7: Jump b_1 else b_3 (const) */
    if (s_b_0_7) 
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
    /* execute.simd:4404 [F] s_b_1_0=sym_11150_3_parameter_inst.sf (const) */
    /* execute.simd:4404 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4404 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4404 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4404 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_6, b_7, b_8, b_9, b_12, b_13, b_14, b_15, b_16, b_17, b_18, b_19, b_20, b_21, b_22, b_23,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4423 [F] s_b_3_0=sym_11150_3_parameter_inst.sf (const) */
    /* execute.simd:4423 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4423 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4423 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4423 [F] s_b_3_4: If s_b_3_3: Jump b_10 else b_11 (const) */
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
    /* execute.simd:4405 [F] s_b_4_0=sym_11150_3_parameter_inst.type (const) */
    /* execute.simd:4405 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4405 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.simd:4405 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4405 [F] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4413 [F] s_b_5_0=sym_11150_3_parameter_inst.type (const) */
    /* execute.simd:4413 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4413 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.simd:4413 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4413 [F] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4407 [F] s_b_6_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.simd:4407 [F] s_b_6_1=sym_11150_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_6_2 = ReadRegBank 9:s_b_6_1 (f32) */
    auto s_b_6_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_2,emitter.const_u8(4));
    }
    /* execute.simd:4407 [F] s_b_6_3 = sym_11155_0_mulp (const) uint64_t */
    uint64_t s_b_6_3 = CV_sym_11155_0_mulp;
    /* execute.simd:4407 [F] s_b_6_4 = (f32)s_b_6_3 (const) */
    /* execute.simd:4407 [D] s_b_6_5 = s_b_6_2*s_b_6_4 */
    auto s_b_6_5 = emitter.mul(s_b_6_2, emitter.const_f32(((float)s_b_6_3)));
    /* execute.simd:4407 [F] s_b_6_6=sym_11150_3_parameter_inst.rmode (const) */
    /* execute.simd:4407 [D] s_b_6_7 = __builtin_fcvt_f32_s32 */
    auto s_b_6_7 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_6_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4407 [D] s_b_6_8 = (u32)s_b_6_7 */
    auto s_b_6_8 = emitter.reinterpret(s_b_6_7, emitter.context().types().u32());
    /* execute.simd:4407 [D] s_b_6_9: sym_60999_3_parameter_value = s_b_6_8, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_60999_3_parameter_value, s_b_6_8);
    /* execute.a64:2674 [F] s_b_6_10 = (u32)s_b_6_0 (const) */
    /* execute.a64:2674 [F] s_b_6_11 = constant u32 1f (const) */
    /* execute.a64:2674 [F] s_b_6_12 = s_b_6_10==s_b_6_11 (const) */
    uint8_t s_b_6_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2674 [F] s_b_6_13: If s_b_6_12: Jump b_2 else b_16 (const) */
    if (s_b_6_12) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4410 [F] s_b_7_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.simd:4410 [F] s_b_7_1=sym_11150_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_7_2 = ReadRegBank 11:s_b_7_1 (f64) */
    auto s_b_7_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_2,emitter.const_u8(8));
    }
    /* execute.simd:4410 [F] s_b_7_3 = sym_11155_0_mulp (const) uint64_t */
    uint64_t s_b_7_3 = CV_sym_11155_0_mulp;
    /* execute.simd:4410 [F] s_b_7_4 = (f64)s_b_7_3 (const) */
    /* execute.simd:4410 [D] s_b_7_5 = s_b_7_2*s_b_7_4 */
    auto s_b_7_5 = emitter.mul(s_b_7_2, emitter.const_f64(((double)s_b_7_3)));
    /* execute.simd:4410 [F] s_b_7_6=sym_11150_3_parameter_inst.rmode (const) */
    /* execute.simd:4410 [D] s_b_7_7 = __builtin_fcvt_f64_s32 */
    auto s_b_7_7 = emitter.call(__captive___builtin_fcvt_f64_s32, s_b_7_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4410 [D] s_b_7_8 = (u32)s_b_7_7 */
    auto s_b_7_8 = emitter.reinterpret(s_b_7_7, emitter.context().types().u32());
    /* execute.simd:4410 [D] s_b_7_9: sym_61022_3_parameter_value = s_b_7_8, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_61022_3_parameter_value, s_b_7_8);
    /* execute.a64:2674 [F] s_b_7_10 = (u32)s_b_7_0 (const) */
    /* execute.a64:2674 [F] s_b_7_11 = constant u32 1f (const) */
    /* execute.a64:2674 [F] s_b_7_12 = s_b_7_10==s_b_7_11 (const) */
    uint8_t s_b_7_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2674 [F] s_b_7_13: If s_b_7_12: Jump b_2 else b_17 (const) */
    if (s_b_7_12) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4415 [F] s_b_8_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.simd:4415 [F] s_b_8_1=sym_11150_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_8_2 = ReadRegBank 9:s_b_8_1 (f32) */
    auto s_b_8_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_2,emitter.const_u8(4));
    }
    /* execute.simd:4415 [F] s_b_8_3 = sym_11155_0_mulp (const) uint64_t */
    uint64_t s_b_8_3 = CV_sym_11155_0_mulp;
    /* execute.simd:4415 [F] s_b_8_4 = (f32)s_b_8_3 (const) */
    /* execute.simd:4415 [D] s_b_8_5 = s_b_8_2*s_b_8_4 */
    auto s_b_8_5 = emitter.mul(s_b_8_2, emitter.const_f32(((float)s_b_8_3)));
    /* execute.simd:4415 [F] s_b_8_6=sym_11150_3_parameter_inst.rmode (const) */
    /* execute.simd:4415 [D] s_b_8_7 = __builtin_fcvt_f32_s64 */
    auto s_b_8_7 = emitter.call(__captive___builtin_fcvt_f32_s64, s_b_8_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4415 [D] s_b_8_8 = (u64)s_b_8_7 */
    auto s_b_8_8 = emitter.reinterpret(s_b_8_7, emitter.context().types().u64());
    /* execute.simd:4415 [D] s_b_8_9: sym_61045_3_parameter_value = s_b_8_8, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_61045_3_parameter_value, s_b_8_8);
    /* execute.a64:2682 [F] s_b_8_10 = (u32)s_b_8_0 (const) */
    /* execute.a64:2682 [F] s_b_8_11 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_8_12 = s_b_8_10==s_b_8_11 (const) */
    uint8_t s_b_8_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_8_13: If s_b_8_12: Jump b_2 else b_18 (const) */
    if (s_b_8_12) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4418 [F] s_b_9_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.simd:4418 [F] s_b_9_1=sym_11150_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_9_2 = ReadRegBank 11:s_b_9_1 (f64) */
    auto s_b_9_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_2,emitter.const_u8(8));
    }
    /* execute.simd:4418 [F] s_b_9_3 = sym_11155_0_mulp (const) uint64_t */
    uint64_t s_b_9_3 = CV_sym_11155_0_mulp;
    /* execute.simd:4418 [F] s_b_9_4 = (f64)s_b_9_3 (const) */
    /* execute.simd:4418 [D] s_b_9_5 = s_b_9_2*s_b_9_4 */
    auto s_b_9_5 = emitter.mul(s_b_9_2, emitter.const_f64(((double)s_b_9_3)));
    /* execute.simd:4418 [F] s_b_9_6=sym_11150_3_parameter_inst.rmode (const) */
    /* execute.simd:4418 [D] s_b_9_7 = __builtin_fcvt_f64_s64 */
    auto s_b_9_7 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_9_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4418 [D] s_b_9_8 = (u64)s_b_9_7 */
    auto s_b_9_8 = emitter.reinterpret(s_b_9_7, emitter.context().types().u64());
    /* execute.simd:4418 [D] s_b_9_9: sym_61067_3_parameter_value = s_b_9_8, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_61067_3_parameter_value, s_b_9_8);
    /* execute.a64:2682 [F] s_b_9_10 = (u32)s_b_9_0 (const) */
    /* execute.a64:2682 [F] s_b_9_11 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_9_12 = s_b_9_10==s_b_9_11 (const) */
    uint8_t s_b_9_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_9_13: If s_b_9_12: Jump b_2 else b_19 (const) */
    if (s_b_9_12) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4424 [F] s_b_10_0=sym_11150_3_parameter_inst.type (const) */
    /* execute.simd:4424 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4424 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.simd:4424 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4424 [F] s_b_10_4: If s_b_10_3: Jump b_12 else b_13 (const) */
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
    /* execute.simd:4432 [F] s_b_11_0=sym_11150_3_parameter_inst.type (const) */
    /* execute.simd:4432 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.simd:4432 [F] s_b_11_2 = constant u32 0 (const) */
    /* execute.simd:4432 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4432 [F] s_b_11_4: If s_b_11_3: Jump b_14 else b_15 (const) */
    if (s_b_11_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_10,  */
  fixed_block_b_12: 
  {
    /* execute.simd:4426 [F] s_b_12_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.simd:4426 [F] s_b_12_1=sym_11150_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_12_2 = ReadRegBank 9:s_b_12_1 (f32) */
    auto s_b_12_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_2,emitter.const_u8(4));
    }
    /* execute.simd:4426 [F] s_b_12_3 = sym_11155_0_mulp (const) uint64_t */
    uint64_t s_b_12_3 = CV_sym_11155_0_mulp;
    /* execute.simd:4426 [F] s_b_12_4 = (f32)s_b_12_3 (const) */
    /* execute.simd:4426 [D] s_b_12_5 = s_b_12_2*s_b_12_4 */
    auto s_b_12_5 = emitter.mul(s_b_12_2, emitter.const_f32(((float)s_b_12_3)));
    /* execute.simd:4426 [F] s_b_12_6=sym_11150_3_parameter_inst.rmode (const) */
    /* execute.simd:4426 [D] s_b_12_7 = __builtin_fcvt_f32_u32 */
    auto s_b_12_7 = emitter.call(__captive___builtin_fcvt_f32_u32, s_b_12_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4426 [D] s_b_12_8: sym_61089_3_parameter_value = s_b_12_7, dominates: s_b_20_1  */
    emitter.store_local(DV_sym_61089_3_parameter_value, s_b_12_7);
    /* execute.a64:2674 [F] s_b_12_9 = (u32)s_b_12_0 (const) */
    /* execute.a64:2674 [F] s_b_12_10 = constant u32 1f (const) */
    /* execute.a64:2674 [F] s_b_12_11 = s_b_12_9==s_b_12_10 (const) */
    uint8_t s_b_12_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2674 [F] s_b_12_12: If s_b_12_11: Jump b_2 else b_20 (const) */
    if (s_b_12_11) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4429 [F] s_b_13_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.simd:4429 [F] s_b_13_1=sym_11150_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_13_2 = ReadRegBank 11:s_b_13_1 (f64) */
    auto s_b_13_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_13_2,emitter.const_u8(8));
    }
    /* execute.simd:4429 [F] s_b_13_3 = sym_11155_0_mulp (const) uint64_t */
    uint64_t s_b_13_3 = CV_sym_11155_0_mulp;
    /* execute.simd:4429 [F] s_b_13_4 = (f64)s_b_13_3 (const) */
    /* execute.simd:4429 [D] s_b_13_5 = s_b_13_2*s_b_13_4 */
    auto s_b_13_5 = emitter.mul(s_b_13_2, emitter.const_f64(((double)s_b_13_3)));
    /* execute.simd:4429 [F] s_b_13_6=sym_11150_3_parameter_inst.rmode (const) */
    /* execute.simd:4429 [D] s_b_13_7 = __builtin_fcvt_f64_u32 */
    auto s_b_13_7 = emitter.call(__captive___builtin_fcvt_f64_u32, s_b_13_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4429 [D] s_b_13_8: sym_61112_3_parameter_value = s_b_13_7, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_61112_3_parameter_value, s_b_13_7);
    /* execute.a64:2674 [F] s_b_13_9 = (u32)s_b_13_0 (const) */
    /* execute.a64:2674 [F] s_b_13_10 = constant u32 1f (const) */
    /* execute.a64:2674 [F] s_b_13_11 = s_b_13_9==s_b_13_10 (const) */
    uint8_t s_b_13_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2674 [F] s_b_13_12: If s_b_13_11: Jump b_2 else b_21 (const) */
    if (s_b_13_11) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_11,  */
  fixed_block_b_14: 
  {
    /* execute.simd:4434 [F] s_b_14_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.simd:4434 [F] s_b_14_1=sym_11150_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_14_2 = ReadRegBank 9:s_b_14_1 (f32) */
    auto s_b_14_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_2,emitter.const_u8(4));
    }
    /* execute.simd:4434 [F] s_b_14_3 = sym_11155_0_mulp (const) uint64_t */
    uint64_t s_b_14_3 = CV_sym_11155_0_mulp;
    /* execute.simd:4434 [F] s_b_14_4 = (f32)s_b_14_3 (const) */
    /* execute.simd:4434 [D] s_b_14_5 = s_b_14_2*s_b_14_4 */
    auto s_b_14_5 = emitter.mul(s_b_14_2, emitter.const_f32(((float)s_b_14_3)));
    /* execute.simd:4434 [F] s_b_14_6=sym_11150_3_parameter_inst.rmode (const) */
    /* execute.simd:4434 [D] s_b_14_7 = __builtin_fcvt_f32_u64 */
    auto s_b_14_7 = emitter.call(__captive___builtin_fcvt_f32_u64, s_b_14_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4434 [D] s_b_14_8: sym_61135_3_parameter_value = s_b_14_7, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_61135_3_parameter_value, s_b_14_7);
    /* execute.a64:2682 [F] s_b_14_9 = (u32)s_b_14_0 (const) */
    /* execute.a64:2682 [F] s_b_14_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_14_11 = s_b_14_9==s_b_14_10 (const) */
    uint8_t s_b_14_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_14_12: If s_b_14_11: Jump b_2 else b_22 (const) */
    if (s_b_14_11) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_11,  */
  fixed_block_b_15: 
  {
    /* execute.simd:4437 [F] s_b_15_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.simd:4437 [F] s_b_15_1=sym_11150_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_15_2 = ReadRegBank 11:s_b_15_1 (f64) */
    auto s_b_15_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_15_2,emitter.const_u8(8));
    }
    /* execute.simd:4437 [F] s_b_15_3 = sym_11155_0_mulp (const) uint64_t */
    uint64_t s_b_15_3 = CV_sym_11155_0_mulp;
    /* execute.simd:4437 [F] s_b_15_4 = (f64)s_b_15_3 (const) */
    /* execute.simd:4437 [D] s_b_15_5 = s_b_15_2*s_b_15_4 */
    auto s_b_15_5 = emitter.mul(s_b_15_2, emitter.const_f64(((double)s_b_15_3)));
    /* execute.simd:4437 [F] s_b_15_6=sym_11150_3_parameter_inst.rmode (const) */
    /* execute.simd:4437 [D] s_b_15_7 = __builtin_fcvt_f64_u64 */
    auto s_b_15_7 = emitter.call(__captive___builtin_fcvt_f64_u64, s_b_15_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4437 [D] s_b_15_8: sym_61157_3_parameter_value = s_b_15_7, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_61157_3_parameter_value, s_b_15_7);
    /* execute.a64:2682 [F] s_b_15_9 = (u32)s_b_15_0 (const) */
    /* execute.a64:2682 [F] s_b_15_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_15_11 = s_b_15_9==s_b_15_10 (const) */
    uint8_t s_b_15_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_15_12: If s_b_15_11: Jump b_2 else b_23 (const) */
    if (s_b_15_11) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2676 [F] s_b_16_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.a64:2676 [D] s_b_16_1 = sym_60999_3_parameter_value uint32_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_60999_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2676 [D] s_b_16_2 = (u64)s_b_16_1 */
    auto s_b_16_2 = emitter.zx(s_b_16_1, emitter.context().types().u64());
    /* execute.a64:2676 [D] s_b_16_3: WriteRegBank 0:s_b_16_0 = s_b_16_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_2);
    /* execute.a64:0 [F] s_b_16_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2676 [F] s_b_17_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.a64:2676 [D] s_b_17_1 = sym_61022_3_parameter_value uint32_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_61022_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2676 [D] s_b_17_2 = (u64)s_b_17_1 */
    auto s_b_17_2 = emitter.zx(s_b_17_1, emitter.context().types().u64());
    /* execute.a64:2676 [D] s_b_17_3: WriteRegBank 0:s_b_17_0 = s_b_17_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_2);
    /* execute.a64:0 [F] s_b_17_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2684 [F] s_b_18_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_18_1 = sym_61045_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_61045_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_18_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_18_1);
    /* execute.a64:0 [F] s_b_18_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2684 [F] s_b_19_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_19_1 = sym_61067_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_61067_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_19_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_19_1);
    /* execute.a64:0 [F] s_b_19_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2676 [F] s_b_20_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.a64:2676 [D] s_b_20_1 = sym_61089_3_parameter_value uint32_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_61089_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2676 [D] s_b_20_2 = (u64)s_b_20_1 */
    auto s_b_20_2 = emitter.zx(s_b_20_1, emitter.context().types().u64());
    /* execute.a64:2676 [D] s_b_20_3: WriteRegBank 0:s_b_20_0 = s_b_20_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_20_2);
    /* execute.a64:0 [F] s_b_20_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_13,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2676 [F] s_b_21_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.a64:2676 [D] s_b_21_1 = sym_61112_3_parameter_value uint32_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_61112_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2676 [D] s_b_21_2 = (u64)s_b_21_1 */
    auto s_b_21_2 = emitter.zx(s_b_21_1, emitter.context().types().u64());
    /* execute.a64:2676 [D] s_b_21_3: WriteRegBank 0:s_b_21_0 = s_b_21_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_21_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_21_2);
    /* execute.a64:0 [F] s_b_21_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_14,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2684 [F] s_b_22_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_22_1 = sym_61135_3_parameter_value uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_61135_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_22_2: WriteRegBank 0:s_b_22_0 = s_b_22_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_22_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_22_1);
    /* execute.a64:0 [F] s_b_22_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2684 [F] s_b_23_0=sym_11150_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_23_1 = sym_61157_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_61157_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_23_2: WriteRegBank 0:s_b_23_0 = s_b_23_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_23_1);
    /* execute.a64:0 [F] s_b_23_3: Jump b_2 (const) */
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
    /* execute.simd:3950 [F] s_b_0_0=sym_11730_3_parameter_inst.type (const) */
    /* execute.simd:3950 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:3950 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:3950 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:3950 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3951 [F] s_b_1_0=sym_11730_3_parameter_inst.rd (const) */
    /* execute.simd:3951 [F] s_b_1_1=sym_11730_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_1_2 = ReadRegBank 9:s_b_1_1 (f32) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(4));
    }
    /* execute.simd:6102 [D] s_b_1_3: WriteRegBank 9:s_b_1_0 = s_b_1_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_2,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_2);
    /* execute.simd:6103 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.simd:6103 [F] s_b_1_5: WriteRegBank 10:s_b_1_0 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6104 [F] s_b_1_6 = constant u64 0 (const) */
    /* execute.simd:6104 [F] s_b_1_7: WriteRegBank 3:s_b_1_0 = s_b_1_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:3953 [F] s_b_3_0=sym_11730_3_parameter_inst.rd (const) */
    /* execute.simd:3953 [F] s_b_3_1=sym_11730_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_3_2 = ReadRegBank 11:s_b_3_1 (f64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:6110 [D] s_b_3_3: WriteRegBank 11:s_b_3_0 = s_b_3_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_2);
    /* execute.simd:6111 [F] s_b_3_4 = constant u64 0 (const) */
    /* execute.simd:6111 [F] s_b_3_5: WriteRegBank 3:s_b_3_0 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:4058 [F] s_b_0_0=sym_12375_3_parameter_inst.type (const) */
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
    /* execute.simd:4060 [F] s_b_1_0=sym_12375_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4061 [F] s_b_1_2=sym_12375_3_parameter_inst.rm (const) */
    /* execute.simd:6092 [D] s_b_1_3 = ReadRegBank 9:s_b_1_2 (f32) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(4));
    }
    /* execute.simd:4063 [D] s_b_1_4 = s_b_1_1*s_b_1_3 */
    auto s_b_1_4 = emitter.mul(s_b_1_1, s_b_1_3);
    /* execute.simd:4063 [D] s_b_1_5 = -s_b_1_4 */
    auto s_b_1_5 = emitter.neg(s_b_1_4);
    /* execute.simd:4064 [F] s_b_1_6=sym_12375_3_parameter_inst.rd (const) */
    /* execute.simd:6102 [D] s_b_1_7: WriteRegBank 9:s_b_1_6 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6103 [F] s_b_1_8 = constant u32 0 (const) */
    /* execute.simd:6103 [F] s_b_1_9: WriteRegBank 10:s_b_1_6 = s_b_1_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6104 [F] s_b_1_10 = constant u64 0 (const) */
    /* execute.simd:6104 [F] s_b_1_11: WriteRegBank 3:s_b_1_6 = s_b_1_10 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:4067 [F] s_b_3_0=sym_12375_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4068 [F] s_b_3_2=sym_12375_3_parameter_inst.rm (const) */
    /* execute.simd:6097 [D] s_b_3_3 = ReadRegBank 11:s_b_3_2 (f64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:4070 [D] s_b_3_4 = s_b_3_1*s_b_3_3 */
    auto s_b_3_4 = emitter.mul(s_b_3_1, s_b_3_3);
    /* execute.simd:4070 [D] s_b_3_5 = -s_b_3_4 */
    auto s_b_3_5 = emitter.neg(s_b_3_4);
    /* execute.simd:4071 [F] s_b_3_6=sym_12375_3_parameter_inst.rd (const) */
    /* execute.simd:6110 [D] s_b_3_7: WriteRegBank 11:s_b_3_6 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_5);
    /* execute.simd:6111 [F] s_b_3_8 = constant u64 0 (const) */
    /* execute.simd:6111 [F] s_b_3_9: WriteRegBank 3:s_b_3_6 = s_b_3_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
  auto DV_sym_63307_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_63361_3_parameter_rt;
  auto DV_sym_63359_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_63357_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_63367_3_parameter_lane;
  auto DV_sym_63446_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_63520_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63395_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_63378_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_63491_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_63488_1_tmp_s_b_5_4;
  auto DV_sym_63463_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63429_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_63412_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  uint8_t CV_sym_12937_0_lane;
  uint8_t CV_sym_12917_0_rt;
  auto DV_sym_12911_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_12905_3_parameter_inst.rn (const) */
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
    /* execute.simd:2310 [F] s_b_1_0 = sym_12917_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_12917_0_rt;
    /* execute.simd:2310 [F] s_b_1_1=sym_12905_3_parameter_inst.regcnt (const) */
    /* execute.simd:2310 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2310 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2311 [F] s_b_2_0=sym_12905_3_parameter_inst.rt (const) */
    /* execute.simd:2311 [F] s_b_2_1 = sym_12917_0_rt (const) uint8_t */
    uint8_t s_b_2_1 = CV_sym_12917_0_rt;
    /* execute.simd:2311 [F] s_b_2_2 = s_b_2_0+s_b_2_1 (const) */
    uint8_t s_b_2_2 = ((uint8_t)(insn.rt + s_b_2_1));
    /* execute.simd:2311 [F] s_b_2_3 = constant u64 0 (const) */
    /* execute.simd:2311 [F] s_b_2_4 = constant u64 0 (const) */
    /* execute.simd:6145 [F] s_b_2_5: WriteRegBank 2:s_b_2_2 = s_b_2_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6146 [F] s_b_2_6: WriteRegBank 3:s_b_2_2 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2312 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:2312 [F] s_b_2_8: sym_12937_0_lane = s_b_2_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_12937_0_lane = (uint8_t)0ULL;
    /* execute.simd:2312 [F] s_b_2_9: Jump b_4 (const) */
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
    /* execute.simd:2312 [F] s_b_4_0 = sym_12937_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_12937_0_lane;
    /* execute.simd:2312 [F] s_b_4_1=sym_12905_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2312 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2312 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2313 [F] s_b_5_0=sym_12905_3_parameter_inst.arrangement (const) */
    /* execute.simd:2313 [F] s_b_5_1=sym_12905_3_parameter_inst.rt (const) */
    /* execute.simd:2313 [F] s_b_5_2 = sym_12917_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_12917_0_rt;
    /* execute.simd:2313 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2313 [F] s_b_5_4 = sym_12937_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_12937_0_lane;
    /* execute.simd:2313 [D] s_b_5_5 = sym_12911_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_12911_0_address, emitter.context().types().u64());
    /* execute.simd:2313 [F] s_b_5_6: sym_63361_3_parameter_rt = s_b_5_3 (const), dominates: s_b_13_2 s_b_14_2 s_b_12_2 s_b_16_2 s_b_15_2 s_b_11_2 s_b_10_2  */
    CV_sym_63361_3_parameter_rt = s_b_5_3;
    /* execute.simd:2313 [F] s_b_5_7: sym_63367_3_parameter_lane = s_b_5_4 (const), dominates: s_b_13_5 s_b_14_5 s_b_12_5 s_b_16_5 s_b_15_5 s_b_11_5 s_b_10_5  */
    CV_sym_63367_3_parameter_lane = s_b_5_4;
    /* execute.simd:2313 [D] s_b_5_8: sym_63357_3_parameter_addr = s_b_5_5, dominates: s_b_13_0 s_b_14_0 s_b_12_0 s_b_16_0 s_b_15_0 s_b_11_0 s_b_10_0  */
    emitter.store_local(DV_sym_63357_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_63488_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_17_1  */
    CV_sym_63488_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_63491_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_63491_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3700 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3709 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3718 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3727 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3736 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3745 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3754 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3699 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_9 (const) -> b_13, b_14, b_12, b_9, b_16, b_15, b_11, b_10,  */
    switch (insn.arrangement) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_14;
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
    case (int32_t)2ULL:
      goto fixed_block_b_12;
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
    /* execute.simd:2310 [F] s_b_6_0 = sym_12917_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_12917_0_rt;
    /* execute.simd:2310 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2310 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2310 [F] s_b_6_3: sym_12917_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_12917_0_rt = s_b_6_2;
    /* execute.simd:2310 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2733 [F] s_b_7_0=sym_12905_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_7_1 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_7_2: sym_63307_1__R_s_b_0_5 = s_b_7_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_63307_1__R_s_b_0_5, s_b_7_1);
    /* execute.a64:2733 [F] s_b_7_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_22,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2308 [D] s_b_8_0 = sym_63307_1__R_s_b_0_5 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_63307_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2308 [D] s_b_8_1: sym_12911_0_address = s_b_8_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_12911_0_address, s_b_8_0);
    /* execute.simd:2310 [F] s_b_8_2 = constant u8 0 (const) */
    /* execute.simd:2310 [F] s_b_8_3: sym_12917_0_rt = s_b_8_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_12917_0_rt = (uint8_t)0ULL;
    /* execute.simd:2310 [F] s_b_8_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3764 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3702 [D] s_b_10_0 = sym_63357_3_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_63357_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 1 s_b_10_0 => sym_63359_0_mem_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_63359_0_mem_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(1));
    }
    /* execute.simd:3704 [F] s_b_10_2 = sym_63361_3_parameter_rt (const) uint8_t */
    uint8_t s_b_10_2 = CV_sym_63361_3_parameter_rt;
    /* execute.simd:3704 [D] s_b_10_3 = ReadRegBank 15:s_b_10_2 (v8u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:3705 [D] s_b_10_4 = sym_63359_0_mem_value uint8_t */
    auto s_b_10_4 = emitter.load_local(DV_sym_63359_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3705 [F] s_b_10_5 = sym_63367_3_parameter_lane (const) uint8_t */
    uint8_t s_b_10_5 = CV_sym_63367_3_parameter_lane;
    /* execute.simd:3705 [F] s_b_10_6 = (s32)s_b_10_5 (const) */
    /* execute.simd:3705 [D] s_b_10_7 = s_b_10_3[s_b_10_6] <= s_b_10_4 */
    auto s_b_10_7 = emitter.vector_insert(s_b_10_3, emitter.const_s32(((int32_t)s_b_10_5)), s_b_10_4);
    /* execute.simd:3706 [D] s_b_10_8: WriteRegBank 15:s_b_10_2 = s_b_10_7 */
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
    /* execute.simd:3711 [D] s_b_11_0 = sym_63357_3_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_63357_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 1 s_b_11_0 => sym_63378_0_mem_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_63378_0_mem_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(1));
    }
    /* execute.simd:3713 [F] s_b_11_2 = sym_63361_3_parameter_rt (const) uint8_t */
    uint8_t s_b_11_2 = CV_sym_63361_3_parameter_rt;
    /* execute.simd:3713 [D] s_b_11_3 = ReadRegBank 16:s_b_11_2 (v16u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:3714 [D] s_b_11_4 = sym_63378_0_mem_value uint8_t */
    auto s_b_11_4 = emitter.load_local(DV_sym_63378_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3714 [F] s_b_11_5 = sym_63367_3_parameter_lane (const) uint8_t */
    uint8_t s_b_11_5 = CV_sym_63367_3_parameter_lane;
    /* execute.simd:3714 [F] s_b_11_6 = (s32)s_b_11_5 (const) */
    /* execute.simd:3714 [D] s_b_11_7 = s_b_11_3[s_b_11_6] <= s_b_11_4 */
    auto s_b_11_7 = emitter.vector_insert(s_b_11_3, emitter.const_s32(((int32_t)s_b_11_5)), s_b_11_4);
    /* execute.simd:3715 [D] s_b_11_8: WriteRegBank 16:s_b_11_2 = s_b_11_7 */
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
    /* execute.simd:3720 [D] s_b_12_0 = sym_63357_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_63357_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_63395_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_63395_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3722 [F] s_b_12_2 = sym_63361_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_63361_3_parameter_rt;
    /* execute.simd:3722 [D] s_b_12_3 = ReadRegBank 17:s_b_12_2 (v4u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3723 [D] s_b_12_4 = sym_63395_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_63395_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3723 [F] s_b_12_5 = sym_63367_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_63367_3_parameter_lane;
    /* execute.simd:3723 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3723 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3724 [D] s_b_12_8: WriteRegBank 17:s_b_12_2 = s_b_12_7 */
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
    /* execute.simd:3729 [D] s_b_13_0 = sym_63357_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_63357_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 2 s_b_13_0 => sym_63412_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_63412_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(2));
    }
    /* execute.simd:3731 [F] s_b_13_2 = sym_63361_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_63361_3_parameter_rt;
    /* execute.simd:3731 [D] s_b_13_3 = ReadRegBank 18:s_b_13_2 (v8u16) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3732 [D] s_b_13_4 = sym_63412_0_mem_value uint16_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_63412_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3732 [F] s_b_13_5 = sym_63367_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_63367_3_parameter_lane;
    /* execute.simd:3732 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3732 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3733 [D] s_b_13_8: WriteRegBank 18:s_b_13_2 = s_b_13_7 */
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
    /* execute.simd:3738 [D] s_b_14_0 = sym_63357_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_63357_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_63429_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_63429_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.simd:3740 [F] s_b_14_2 = sym_63361_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_63361_3_parameter_rt;
    /* execute.simd:3740 [D] s_b_14_3 = ReadRegBank 19:s_b_14_2 (v2u32) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3741 [D] s_b_14_4 = sym_63429_0_mem_value uint32_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_63429_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3741 [F] s_b_14_5 = sym_63367_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_63367_3_parameter_lane;
    /* execute.simd:3741 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3741 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3742 [D] s_b_14_8: WriteRegBank 19:s_b_14_2 = s_b_14_7 */
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
    /* execute.simd:3747 [D] s_b_15_0 = sym_63357_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_63357_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 4 s_b_15_0 => sym_63446_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_63446_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(4));
    }
    /* execute.simd:3749 [F] s_b_15_2 = sym_63361_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_63361_3_parameter_rt;
    /* execute.simd:3749 [D] s_b_15_3 = ReadRegBank 20:s_b_15_2 (v4u32) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3750 [D] s_b_15_4 = sym_63446_0_mem_value uint32_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_63446_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3750 [F] s_b_15_5 = sym_63367_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_63367_3_parameter_lane;
    /* execute.simd:3750 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3750 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3751 [D] s_b_15_8: WriteRegBank 20:s_b_15_2 = s_b_15_7 */
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
    /* execute.simd:3756 [D] s_b_16_0 = sym_63357_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_63357_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_63463_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_63463_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.simd:3758 [F] s_b_16_2 = sym_63361_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_63361_3_parameter_rt;
    /* execute.simd:3758 [D] s_b_16_3 = ReadRegBank 21:s_b_16_2 (v2u64) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3759 [D] s_b_16_4 = sym_63463_0_mem_value uint64_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_63463_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3759 [F] s_b_16_5 = sym_63367_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_63367_3_parameter_lane;
    /* execute.simd:3759 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3759 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3760 [D] s_b_16_8: WriteRegBank 21:s_b_16_2 = s_b_16_7 */
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
    /* ???:4294967295 [D] s_b_17_0 = sym_63491_1_tmp_s_b_5_5 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_63491_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1 = sym_63488_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_17_1 = CV_sym_63488_1_tmp_s_b_5_4;
    /* execute.simd:2314 [F] s_b_17_2=sym_12905_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* ???:4294967295 [D] s_b_17_4 = s_b_17_0+s_b_17_3 */
    auto s_b_17_4 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2314 [D] s_b_17_5: sym_12911_0_address = s_b_17_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_12911_0_address, s_b_17_4);
    /* execute.simd:2312 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:2312 [F] s_b_17_7 = s_b_17_1+s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(s_b_17_1 + (uint8_t)1ULL));
    /* execute.simd:2312 [F] s_b_17_8: sym_12937_0_lane = s_b_17_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_12937_0_lane = s_b_17_7;
    /* execute.simd:2312 [F] s_b_17_9: Jump b_4 (const) */
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_19_1: sym_63520_1__R_s_b_10_0 = s_b_19_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_63520_1__R_s_b_10_0, s_b_19_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_20_1: sym_63520_1__R_s_b_10_0 = s_b_20_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_63520_1__R_s_b_10_0, s_b_20_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_21_1: sym_63520_1__R_s_b_10_0 = s_b_21_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_63520_1__R_s_b_10_0, s_b_21_0);
    /* execute.a64:2707 [F] s_b_21_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19, b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2731 [D] s_b_22_0 = sym_63520_1__R_s_b_10_0 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_63520_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_22_1: sym_63307_1__R_s_b_0_5 = s_b_22_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_63307_1__R_s_b_0_5, s_b_22_0);
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
  auto DV_sym_66630_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66752_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_66663_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66826_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66735_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_66665_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_66701_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_66769_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66684_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_66673_3_parameter_lane;
  uint8_t CV_sym_66667_3_parameter_rt;
  uint8_t CV_sym_13719_0_lane;
  uint8_t CV_sym_13731_0_rt;
  auto DV_sym_66797_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66718_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  uint8_t CV_sym_66794_1_tmp_s_b_5_2;
  auto DV_sym_13674_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13668_3_parameter_inst.rn (const) */
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
    /* execute.simd:2359 [F] s_b_1_0 = sym_13719_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13719_0_lane;
    /* execute.simd:2359 [F] s_b_1_1=sym_13668_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2359 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2359 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2360 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2360 [F] s_b_2_1: sym_13731_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13731_0_rt = (uint8_t)0ULL;
    /* execute.simd:2360 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2360 [F] s_b_4_0 = sym_13731_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13731_0_rt;
    /* execute.simd:2360 [F] s_b_4_1=sym_13668_3_parameter_inst.regcnt (const) */
    /* execute.simd:2360 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2360 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2361 [F] s_b_5_0=sym_13668_3_parameter_inst.arrangement (const) */
    /* execute.simd:2361 [F] s_b_5_1=sym_13668_3_parameter_inst.rt (const) */
    /* execute.simd:2361 [F] s_b_5_2 = sym_13731_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13731_0_rt;
    /* execute.simd:2361 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2361 [F] s_b_5_4 = sym_13719_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13719_0_lane;
    /* execute.simd:2361 [D] s_b_5_5 = sym_13674_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13674_0_address, emitter.context().types().u64());
    /* execute.simd:2361 [F] s_b_5_6: sym_66667_3_parameter_rt = s_b_5_3 (const), dominates: s_b_10_2 s_b_11_2 s_b_16_2 s_b_15_2 s_b_14_2 s_b_13_2 s_b_12_2  */
    CV_sym_66667_3_parameter_rt = s_b_5_3;
    /* execute.simd:2361 [F] s_b_5_7: sym_66673_3_parameter_lane = s_b_5_4 (const), dominates: s_b_10_5 s_b_11_5 s_b_16_5 s_b_15_5 s_b_14_5 s_b_13_5 s_b_12_5  */
    CV_sym_66673_3_parameter_lane = s_b_5_4;
    /* execute.simd:2361 [D] s_b_5_8: sym_66663_3_parameter_addr = s_b_5_5, dominates: s_b_10_0 s_b_11_0 s_b_16_0 s_b_15_0 s_b_14_0 s_b_13_0 s_b_12_0  */
    emitter.store_local(DV_sym_66663_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_66794_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_17_1  */
    CV_sym_66794_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_66797_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_66797_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3700 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3709 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3718 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3727 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3736 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3745 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3754 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3699 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_9 (const) -> b_9, b_10, b_11, b_16, b_15, b_14, b_13, b_12,  */
    switch (insn.arrangement) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_15;
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
    /* execute.simd:2359 [F] s_b_6_0 = sym_13719_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13719_0_lane;
    /* execute.simd:2359 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2359 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2359 [F] s_b_6_3: sym_13719_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13719_0_lane = s_b_6_2;
    /* execute.simd:2359 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2733 [F] s_b_7_0=sym_13668_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_7_1 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_7_2: sym_66630_1__R_s_b_0_5 = s_b_7_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_66630_1__R_s_b_0_5, s_b_7_1);
    /* execute.a64:2733 [F] s_b_7_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_22,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2352 [D] s_b_8_0 = sym_66630_1__R_s_b_0_5 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_66630_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2352 [D] s_b_8_1: sym_13674_0_address = s_b_8_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13674_0_address, s_b_8_0);
    /* execute.simd:2354 [F] s_b_8_2=sym_13668_3_parameter_inst.rt (const) */
    /* execute.simd:2354 [F] s_b_8_3 = constant u64 0 (const) */
    /* execute.simd:2354 [F] s_b_8_4 = constant u64 0 (const) */
    /* execute.simd:6145 [F] s_b_8_5: WriteRegBank 2:s_b_8_2 = s_b_8_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6146 [F] s_b_8_6: WriteRegBank 3:s_b_8_2 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2355 [F] s_b_8_7=sym_13668_3_parameter_inst.rt (const) */
    /* execute.simd:2355 [F] s_b_8_8 = (u32)s_b_8_7 (const) */
    /* execute.simd:2355 [F] s_b_8_9 = constant u32 1 (const) */
    /* execute.simd:2355 [F] s_b_8_10 = s_b_8_8+s_b_8_9 (const) */
    uint32_t s_b_8_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2355 [F] s_b_8_11 = (u8)s_b_8_10 (const) */
    /* execute.simd:2355 [F] s_b_8_12 = constant u64 0 (const) */
    /* execute.simd:2355 [F] s_b_8_13 = constant u64 0 (const) */
    /* execute.simd:6145 [F] s_b_8_14: WriteRegBank 2:s_b_8_11 = s_b_8_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6146 [F] s_b_8_15: WriteRegBank 3:s_b_8_11 = s_b_8_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2356 [F] s_b_8_16=sym_13668_3_parameter_inst.rt (const) */
    /* execute.simd:2356 [F] s_b_8_17 = (u32)s_b_8_16 (const) */
    /* execute.simd:2356 [F] s_b_8_18 = constant u32 2 (const) */
    /* execute.simd:2356 [F] s_b_8_19 = s_b_8_17+s_b_8_18 (const) */
    uint32_t s_b_8_19 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)2ULL));
    /* execute.simd:2356 [F] s_b_8_20 = (u8)s_b_8_19 (const) */
    /* execute.simd:2356 [F] s_b_8_21 = constant u64 0 (const) */
    /* execute.simd:2356 [F] s_b_8_22 = constant u64 0 (const) */
    /* execute.simd:6145 [F] s_b_8_23: WriteRegBank 2:s_b_8_20 = s_b_8_21 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6146 [F] s_b_8_24: WriteRegBank 3:s_b_8_20 = s_b_8_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2357 [F] s_b_8_25=sym_13668_3_parameter_inst.rt (const) */
    /* execute.simd:2357 [F] s_b_8_26 = (u32)s_b_8_25 (const) */
    /* execute.simd:2357 [F] s_b_8_27 = constant u32 3 (const) */
    /* execute.simd:2357 [F] s_b_8_28 = s_b_8_26+s_b_8_27 (const) */
    uint32_t s_b_8_28 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)3ULL));
    /* execute.simd:2357 [F] s_b_8_29 = (u8)s_b_8_28 (const) */
    /* execute.simd:2357 [F] s_b_8_30 = constant u64 0 (const) */
    /* execute.simd:2357 [F] s_b_8_31 = constant u64 0 (const) */
    /* execute.simd:6145 [F] s_b_8_32: WriteRegBank 2:s_b_8_29 = s_b_8_30 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6146 [F] s_b_8_33: WriteRegBank 3:s_b_8_29 = s_b_8_31 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2359 [F] s_b_8_34 = constant u8 0 (const) */
    /* execute.simd:2359 [F] s_b_8_35: sym_13719_0_lane = s_b_8_34 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13719_0_lane = (uint8_t)0ULL;
    /* execute.simd:2359 [F] s_b_8_36: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3764 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_5,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3702 [D] s_b_10_0 = sym_66663_3_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_66663_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 1 s_b_10_0 => sym_66665_0_mem_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66665_0_mem_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(1));
    }
    /* execute.simd:3704 [F] s_b_10_2 = sym_66667_3_parameter_rt (const) uint8_t */
    uint8_t s_b_10_2 = CV_sym_66667_3_parameter_rt;
    /* execute.simd:3704 [D] s_b_10_3 = ReadRegBank 15:s_b_10_2 (v8u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:3705 [D] s_b_10_4 = sym_66665_0_mem_value uint8_t */
    auto s_b_10_4 = emitter.load_local(DV_sym_66665_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3705 [F] s_b_10_5 = sym_66673_3_parameter_lane (const) uint8_t */
    uint8_t s_b_10_5 = CV_sym_66673_3_parameter_lane;
    /* execute.simd:3705 [F] s_b_10_6 = (s32)s_b_10_5 (const) */
    /* execute.simd:3705 [D] s_b_10_7 = s_b_10_3[s_b_10_6] <= s_b_10_4 */
    auto s_b_10_7 = emitter.vector_insert(s_b_10_3, emitter.const_s32(((int32_t)s_b_10_5)), s_b_10_4);
    /* execute.simd:3706 [D] s_b_10_8: WriteRegBank 15:s_b_10_2 = s_b_10_7 */
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
    /* execute.simd:3711 [D] s_b_11_0 = sym_66663_3_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_66663_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 1 s_b_11_0 => sym_66684_0_mem_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66684_0_mem_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(1));
    }
    /* execute.simd:3713 [F] s_b_11_2 = sym_66667_3_parameter_rt (const) uint8_t */
    uint8_t s_b_11_2 = CV_sym_66667_3_parameter_rt;
    /* execute.simd:3713 [D] s_b_11_3 = ReadRegBank 16:s_b_11_2 (v16u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:3714 [D] s_b_11_4 = sym_66684_0_mem_value uint8_t */
    auto s_b_11_4 = emitter.load_local(DV_sym_66684_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3714 [F] s_b_11_5 = sym_66673_3_parameter_lane (const) uint8_t */
    uint8_t s_b_11_5 = CV_sym_66673_3_parameter_lane;
    /* execute.simd:3714 [F] s_b_11_6 = (s32)s_b_11_5 (const) */
    /* execute.simd:3714 [D] s_b_11_7 = s_b_11_3[s_b_11_6] <= s_b_11_4 */
    auto s_b_11_7 = emitter.vector_insert(s_b_11_3, emitter.const_s32(((int32_t)s_b_11_5)), s_b_11_4);
    /* execute.simd:3715 [D] s_b_11_8: WriteRegBank 16:s_b_11_2 = s_b_11_7 */
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
    /* execute.simd:3720 [D] s_b_12_0 = sym_66663_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_66663_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_66701_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66701_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3722 [F] s_b_12_2 = sym_66667_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_66667_3_parameter_rt;
    /* execute.simd:3722 [D] s_b_12_3 = ReadRegBank 17:s_b_12_2 (v4u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3723 [D] s_b_12_4 = sym_66701_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_66701_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3723 [F] s_b_12_5 = sym_66673_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_66673_3_parameter_lane;
    /* execute.simd:3723 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3723 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3724 [D] s_b_12_8: WriteRegBank 17:s_b_12_2 = s_b_12_7 */
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
    /* execute.simd:3729 [D] s_b_13_0 = sym_66663_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_66663_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 2 s_b_13_0 => sym_66718_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66718_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(2));
    }
    /* execute.simd:3731 [F] s_b_13_2 = sym_66667_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_66667_3_parameter_rt;
    /* execute.simd:3731 [D] s_b_13_3 = ReadRegBank 18:s_b_13_2 (v8u16) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3732 [D] s_b_13_4 = sym_66718_0_mem_value uint16_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_66718_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3732 [F] s_b_13_5 = sym_66673_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_66673_3_parameter_lane;
    /* execute.simd:3732 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3732 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3733 [D] s_b_13_8: WriteRegBank 18:s_b_13_2 = s_b_13_7 */
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
    /* execute.simd:3738 [D] s_b_14_0 = sym_66663_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_66663_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_66735_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_66735_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.simd:3740 [F] s_b_14_2 = sym_66667_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_66667_3_parameter_rt;
    /* execute.simd:3740 [D] s_b_14_3 = ReadRegBank 19:s_b_14_2 (v2u32) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3741 [D] s_b_14_4 = sym_66735_0_mem_value uint32_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_66735_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3741 [F] s_b_14_5 = sym_66673_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_66673_3_parameter_lane;
    /* execute.simd:3741 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3741 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3742 [D] s_b_14_8: WriteRegBank 19:s_b_14_2 = s_b_14_7 */
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
    /* execute.simd:3747 [D] s_b_15_0 = sym_66663_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_66663_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 4 s_b_15_0 => sym_66752_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_66752_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(4));
    }
    /* execute.simd:3749 [F] s_b_15_2 = sym_66667_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_66667_3_parameter_rt;
    /* execute.simd:3749 [D] s_b_15_3 = ReadRegBank 20:s_b_15_2 (v4u32) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3750 [D] s_b_15_4 = sym_66752_0_mem_value uint32_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_66752_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3750 [F] s_b_15_5 = sym_66673_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_66673_3_parameter_lane;
    /* execute.simd:3750 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3750 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3751 [D] s_b_15_8: WriteRegBank 20:s_b_15_2 = s_b_15_7 */
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
    /* execute.simd:3756 [D] s_b_16_0 = sym_66663_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_66663_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_66769_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_66769_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.simd:3758 [F] s_b_16_2 = sym_66667_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_66667_3_parameter_rt;
    /* execute.simd:3758 [D] s_b_16_3 = ReadRegBank 21:s_b_16_2 (v2u64) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3759 [D] s_b_16_4 = sym_66769_0_mem_value uint64_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_66769_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3759 [F] s_b_16_5 = sym_66673_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_66673_3_parameter_lane;
    /* execute.simd:3759 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3759 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3760 [D] s_b_16_8: WriteRegBank 21:s_b_16_2 = s_b_16_7 */
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
    /* ???:4294967295 [D] s_b_17_0 = sym_66797_1_tmp_s_b_5_5 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_66797_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1 = sym_66794_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_17_1 = CV_sym_66794_1_tmp_s_b_5_2;
    /* execute.simd:2362 [F] s_b_17_2=sym_13668_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* ???:4294967295 [D] s_b_17_4 = s_b_17_0+s_b_17_3 */
    auto s_b_17_4 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2362 [D] s_b_17_5: sym_13674_0_address = s_b_17_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13674_0_address, s_b_17_4);
    /* execute.simd:2360 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:2360 [F] s_b_17_7 = s_b_17_1+s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(s_b_17_1 + (uint8_t)1ULL));
    /* execute.simd:2360 [F] s_b_17_8: sym_13731_0_rt = s_b_17_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13731_0_rt = s_b_17_7;
    /* execute.simd:2360 [F] s_b_17_9: Jump b_4 (const) */
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_19_1: sym_66826_1__R_s_b_10_0 = s_b_19_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_66826_1__R_s_b_10_0, s_b_19_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_20_1: sym_66826_1__R_s_b_10_0 = s_b_20_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_66826_1__R_s_b_10_0, s_b_20_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_21_1: sym_66826_1__R_s_b_10_0 = s_b_21_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_66826_1__R_s_b_10_0, s_b_21_0);
    /* execute.a64:2707 [F] s_b_21_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19, b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2731 [D] s_b_22_0 = sym_66826_1__R_s_b_10_0 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_66826_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_22_1: sym_66630_1__R_s_b_0_5 = s_b_22_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_66630_1__R_s_b_0_5, s_b_22_0);
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
  auto DV_sym_80569_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_80607_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_81406_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_80670_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_80725_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14100_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_1_0=sym_14100_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_1_2: sym_80569_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_80569_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2733 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:687 [D] s_b_2_0 = sym_80569_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_80569_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:688 [D] s_b_2_1: sym_80670_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_80670_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 2 s_b_2_0 => sym_80725_0_data16 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_80725_0_data16, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(2));
    }
    /* execute.a64:1677 [D] s_b_2_3 = sym_80725_0_data16 uint16_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_80725_0_data16, emitter.context().types().u16());
    /* execute.a64:1677 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_2_5=sym_14100_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_2_8: sym_81406_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_81406_3_parameter_value, s_b_2_7);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_4_1: sym_80607_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_80607_1__R_s_b_4_0, s_b_4_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_5_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_5_1: sym_80607_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_80607_1__R_s_b_4_0, s_b_5_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_6_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_6_1: sym_80607_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_80607_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2707 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2731 [D] s_b_7_0 = sym_80607_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_80607_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_7_1: sym_80569_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_80569_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2731 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1723 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_8_1 = sym_80670_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_80670_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_10_0=sym_14100_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_10_1 = sym_81406_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_81406_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldr(const aarch64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14564_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89188_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90985_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89747_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_89601_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_91511_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89408_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89823_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_89705_0_data128_2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89320_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_89217_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89899_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89699_0_data128_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89536_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89934_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89990_1__R_s_b_28_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91489_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14558_3_parameter_inst.rn (const) */
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
    /* execute.a64:948 [D] s_b_1_0 = sym_14564_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* execute.a64:948 [F] s_b_1_1=sym_14558_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:948 [D] s_b_1_4: sym_14564_0_address = s_b_1_3, dominates: s_b_6_0 s_b_17_0 s_b_18_1 s_b_7_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_14564_0_address, s_b_1_3);
    /* execute.a64:948 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_20,  */
  fixed_block_b_2: 
  {
    /* execute.a64:951 [F] s_b_2_0=sym_14558_3_parameter_inst.V (const) */
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
    /* execute.a64:952 [F] s_b_3_0=sym_14558_3_parameter_inst.size (const) */
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
    /* execute.a64:971 [F] s_b_4_0=sym_14558_3_parameter_inst.P (const) */
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
    /* execute.a64:958 [F] s_b_5_0=sym_14558_3_parameter_inst.size (const) */
    /* execute.a64:958 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:958 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:958 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.a64:958 [F] s_b_5_4=sym_14558_3_parameter_inst.X (const) */
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
    /* execute.a64:953 [D] s_b_6_0 = sym_14564_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* execute.a64:953 [D] s_b_6_1: sym_89217_3_parameter_address = s_b_6_0, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_89217_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 4 s_b_6_0 => sym_89320_0_data32 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_89320_0_data32, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_6_3 = sym_89320_0_data32 uint32_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_89320_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_6_4 = (u64)s_b_6_3 */
    auto s_b_6_4 = emitter.zx(s_b_6_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_5=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_6_6 = (u32)s_b_6_4 */
    auto s_b_6_6 = emitter.truncate(s_b_6_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_8: sym_91489_3_parameter_value = s_b_6_7, dominates: s_b_37_1  */
    emitter.store_local(DV_sym_91489_3_parameter_value, s_b_6_7);
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
    /* execute.a64:955 [D] s_b_7_0 = sym_14564_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* execute.a64:955 [D] s_b_7_1: sym_89408_3_parameter_address = s_b_7_0, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_89408_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 8 s_b_7_0 => sym_89536_0_data64 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_89536_0_data64, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_7_3 = sym_89536_0_data64 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_89536_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_4=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_7_5: sym_91511_3_parameter_value = s_b_7_3, dominates: s_b_38_1  */
    emitter.store_local(DV_sym_91511_3_parameter_value, s_b_7_3);
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
    /* execute.a64:959 [D] s_b_8_0 = sym_14564_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_8_1 = Load 1 s_b_8_0 => sym_89601_0_data8 */
    auto s_b_8_1 = emitter.load_memory(s_b_8_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_89601_0_data8, s_b_8_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_8_0, s_b_8_1, emitter.const_u8(1));
    }
    /* execute.a64:1733 [F] s_b_8_2=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:1733 [D] s_b_8_3 = sym_89601_0_data8 uint8_t */
    auto s_b_8_3 = emitter.load_local(DV_sym_89601_0_data8, emitter.context().types().u8());
    /* execute.simd:6117 [D] s_b_8_4 = (u64)s_b_8_3 */
    auto s_b_8_4 = emitter.zx(s_b_8_3, emitter.context().types().u64());
    /* execute.simd:6117 [D] s_b_8_5: WriteRegBank 2:s_b_8_2 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_8_4);
    /* execute.simd:6118 [F] s_b_8_6 = constant u64 0 (const) */
    /* execute.simd:6118 [F] s_b_8_7: WriteRegBank 3:s_b_8_2 = s_b_8_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_8: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.a64:960 [F] s_b_9_0=sym_14558_3_parameter_inst.size (const) */
    /* execute.a64:960 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:960 [F] s_b_9_2 = constant u32 0 (const) */
    /* execute.a64:960 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.a64:960 [F] s_b_9_4=sym_14558_3_parameter_inst.X (const) */
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
    /* execute.a64:961 [D] s_b_10_0 = sym_14564_0_address uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 8 s_b_10_0 => sym_89699_0_data128_1 */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_89699_0_data128_1, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(8));
    }
    /* execute.a64:1763 [F] s_b_10_2 = constant u64 8 (const) */
    /* execute.a64:1763 [D] s_b_10_3 = s_b_10_0+s_b_10_2 */
    auto s_b_10_3 = emitter.add(s_b_10_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_10_4 = Load 8 s_b_10_3 => sym_89705_0_data128_2 */
    auto s_b_10_4 = emitter.load_memory(s_b_10_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_89705_0_data128_2, s_b_10_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_3, s_b_10_4, emitter.const_u8(8));
    }
    /* execute.a64:1765 [F] s_b_10_5=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:1765 [D] s_b_10_6 = sym_89699_0_data128_1 uint64_t */
    auto s_b_10_6 = emitter.load_local(DV_sym_89699_0_data128_1, emitter.context().types().u64());
    /* execute.a64:1765 [D] s_b_10_7 = sym_89705_0_data128_2 uint64_t */
    auto s_b_10_7 = emitter.load_local(DV_sym_89705_0_data128_2, emitter.context().types().u64());
    /* execute.simd:6145 [D] s_b_10_8: WriteRegBank 2:s_b_10_5 = s_b_10_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_6);
    /* execute.simd:6146 [D] s_b_10_9: WriteRegBank 3:s_b_10_5 = s_b_10_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_10_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_10_7);
    /* execute.simd:0 [F] s_b_10_10: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:962 [F] s_b_11_0=sym_14558_3_parameter_inst.size (const) */
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
    /* execute.a64:963 [D] s_b_12_0 = sym_14564_0_address uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_89747_0_data16 */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_89747_0_data16, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.a64:1740 [F] s_b_12_2=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:1740 [D] s_b_12_3 = sym_89747_0_data16 uint16_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_89747_0_data16, emitter.context().types().u16());
    /* execute.simd:6124 [D] s_b_12_4 = (u64)s_b_12_3 */
    auto s_b_12_4 = emitter.zx(s_b_12_3, emitter.context().types().u64());
    /* execute.simd:6124 [D] s_b_12_5: WriteRegBank 2:s_b_12_2 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_4);
    /* execute.simd:6125 [F] s_b_12_6 = constant u64 0 (const) */
    /* execute.simd:6125 [F] s_b_12_7: WriteRegBank 3:s_b_12_2 = s_b_12_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_12_8: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.a64:964 [F] s_b_13_0=sym_14558_3_parameter_inst.size (const) */
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
    /* execute.a64:965 [D] s_b_14_0 = sym_14564_0_address uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_89823_0_data32 */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_89823_0_data32, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.a64:1747 [F] s_b_14_2=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:1747 [D] s_b_14_3 = sym_89823_0_data32 uint32_t */
    auto s_b_14_3 = emitter.load_local(DV_sym_89823_0_data32, emitter.context().types().u32());
    /* execute.simd:6131 [D] s_b_14_4 = (u64)s_b_14_3 */
    auto s_b_14_4 = emitter.zx(s_b_14_3, emitter.context().types().u64());
    /* execute.simd:6131 [D] s_b_14_5: WriteRegBank 2:s_b_14_2 = s_b_14_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_4);
    /* execute.simd:6132 [F] s_b_14_6 = constant u64 0 (const) */
    /* execute.simd:6132 [F] s_b_14_7: WriteRegBank 3:s_b_14_2 = s_b_14_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_14_8: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_13,  */
  fixed_block_b_15: 
  {
    /* execute.a64:966 [F] s_b_15_0=sym_14558_3_parameter_inst.size (const) */
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
    /* execute.a64:967 [D] s_b_16_0 = sym_14564_0_address uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_89899_0_data64 */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_89899_0_data64, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.a64:1754 [F] s_b_16_2=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:1754 [D] s_b_16_3 = sym_89899_0_data64 uint64_t */
    auto s_b_16_3 = emitter.load_local(DV_sym_89899_0_data64, emitter.context().types().u64());
    /* execute.simd:6138 [D] s_b_16_4: WriteRegBank 2:s_b_16_2 = s_b_16_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_3);
    /* execute.simd:6139 [F] s_b_16_5 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_16_6: WriteRegBank 3:s_b_16_2 = s_b_16_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_16_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_4,  */
  fixed_block_b_17: 
  {
    /* execute.a64:972 [D] s_b_17_0 = sym_14564_0_address uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* execute.a64:972 [F] s_b_17_1=sym_14558_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_17_2 = (u64)s_b_17_1 (const) */
    /* ???:4294967295 [D] s_b_17_3 = s_b_17_0+s_b_17_2 */
    auto s_b_17_3 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:972 [D] s_b_17_4: sym_14564_0_address = s_b_17_3, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_14564_0_address, s_b_17_3);
    /* execute.a64:972 [F] s_b_17_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:975 [F] s_b_18_0 = constant u8 1 (const) */
    /* execute.a64:975 [D] s_b_18_1 = sym_14564_0_address uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_14564_0_address, emitter.context().types().u64());
    /* execute.a64:975 [D] s_b_18_2: sym_89934_3_parameter_value = s_b_18_1, dominates: s_b_23_0 s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_89934_3_parameter_value, s_b_18_1);
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
    /* execute.a64:2733 [F] s_b_19_0=sym_14558_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_19_1 = ReadRegBank 0:s_b_19_0 (u64) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_19_2: sym_89188_1__R_s_b_0_5 = s_b_19_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_89188_1__R_s_b_0_5, s_b_19_1);
    /* execute.a64:2733 [F] s_b_19_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_19, b_32,  */
  fixed_block_b_20: 
  {
    /* execute.a64:945 [D] s_b_20_0 = sym_89188_1__R_s_b_0_5 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_89188_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:945 [D] s_b_20_1: sym_14564_0_address = s_b_20_0, dominates: s_b_1_0 s_b_6_0 s_b_17_0 s_b_18_1 s_b_7_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_14564_0_address, s_b_20_0);
    /* execute.a64:947 [F] s_b_20_2=sym_14558_3_parameter_inst.P (const) */
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
    /* execute.a64:1723 [D] s_b_21_1 = sym_89217_3_parameter_address uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_89217_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_21_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_21_1);
    /* execute.a64:0 [F] s_b_21_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_38,  */
  fixed_block_b_22: 
  {
    /* execute.a64:1723 [F] s_b_22_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_22_1 = sym_89408_3_parameter_address uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_89408_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_22_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_22_1);
    /* execute.a64:0 [F] s_b_22_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_18,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2747 [D] s_b_23_0 = sym_89934_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_89934_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_23_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_23_2 = s_b_23_0&s_b_23_1 */
    auto s_b_23_2 = emitter.bitwise_and(s_b_23_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_23_3: sym_89934_3_parameter_value = s_b_23_2, dominates: s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_89934_3_parameter_value, s_b_23_2);
    /* execute.a64:2747 [F] s_b_23_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_18, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2750 [F] s_b_24_0=sym_14558_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_25_0 = sym_89934_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_89934_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_25_1: sym_90985_3_parameter_value = s_b_25_0, dominates: s_b_33_0 s_b_34_0 s_b_35_0  */
    emitter.store_local(DV_sym_90985_3_parameter_value, s_b_25_0);
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
    /* execute.a64:2753 [F] s_b_26_0=sym_14558_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_26_1 = sym_89934_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_89934_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_26_1,emitter.const_u8(8));
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_29_1: sym_89990_1__R_s_b_28_0 = s_b_29_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_89990_1__R_s_b_28_0, s_b_29_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_30_1: sym_89990_1__R_s_b_28_0 = s_b_30_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_89990_1__R_s_b_28_0, s_b_30_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_31_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_31_1: sym_89990_1__R_s_b_28_0 = s_b_31_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_89990_1__R_s_b_28_0, s_b_31_0);
    /* execute.a64:2707 [F] s_b_31_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_29, b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2731 [D] s_b_32_0 = sym_89990_1__R_s_b_28_0 uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_89990_1__R_s_b_28_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_32_1: sym_89188_1__R_s_b_0_5 = s_b_32_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_89188_1__R_s_b_0_5, s_b_32_0);
    /* execute.a64:2731 [F] s_b_32_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_25,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2715 [D] s_b_33_0 = sym_90985_3_parameter_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_90985_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_33_1: WriteReg 20 = s_b_33_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_33_0);
    /* execute.a64:2715 [F] s_b_33_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_39,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2718 [D] s_b_34_0 = sym_90985_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_90985_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_34_1: WriteReg 20 = s_b_34_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_34_0);
    /* execute.a64:2718 [F] s_b_34_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_39,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2720 [D] s_b_35_0 = sym_90985_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_90985_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_35_1: WriteReg 21 = s_b_35_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
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
    /* execute.a64:2684 [F] s_b_37_0=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_37_1 = sym_91489_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_91489_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_37_2: WriteRegBank 0:s_b_37_0 = s_b_37_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_37_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_37_1);
    /* execute.a64:0 [F] s_b_37_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_7,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2684 [F] s_b_38_0=sym_14558_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_38_1 = sym_91511_3_parameter_value uint64_t */
    auto s_b_38_1 = emitter.load_local(DV_sym_91511_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_38_2: WriteRegBank 0:s_b_38_0 = s_b_38_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_38_1,emitter.const_u8(8));
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
  auto DV_sym_102761_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_102486_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102706_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_15561_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102952_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_102515_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102570_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_103969_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_103078_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_103134_1__R_s_b_14_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102897_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105295_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_104297_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_104807_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_15555_3_parameter_inst.rn (const) */
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
    /* execute.a64:923 [D] s_b_1_0 = sym_15561_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15561_0_address, emitter.context().types().u64());
    /* execute.a64:923 [F] s_b_1_1=sym_15555_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:923 [D] s_b_1_4: sym_15561_0_address = s_b_1_3, dominates: s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15561_0_address, s_b_1_3);
    /* execute.a64:923 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_11,  */
  fixed_block_b_2: 
  {
    /* execute.a64:926 [F] s_b_2_0=sym_15555_3_parameter_inst.X (const) */
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
    /* execute.a64:927 [F] s_b_3_0=sym_15555_3_parameter_inst.L (const) */
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
    /* execute.a64:936 [F] s_b_4_0=sym_15555_3_parameter_inst.P (const) */
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
    /* execute.a64:933 [D] s_b_5_0 = sym_15561_0_address uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_15561_0_address, emitter.context().types().u64());
    /* execute.a64:933 [D] s_b_5_1: sym_102515_3_parameter_address = s_b_5_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_102515_3_parameter_address, s_b_5_0);
    /* ???:4294967295 [D] s_b_5_2 = Load 2 s_b_5_0 => sym_102570_0_data16 */
    auto s_b_5_2 = emitter.load_memory(s_b_5_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_102570_0_data16, s_b_5_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_5_0, s_b_5_2, emitter.const_u8(2));
    }
    /* execute.a64:1677 [D] s_b_5_3 = sym_102570_0_data16 uint16_t */
    auto s_b_5_3 = emitter.load_local(DV_sym_102570_0_data16, emitter.context().types().u16());
    /* execute.a64:1677 [D] s_b_5_4 = (u64)s_b_5_3 */
    auto s_b_5_4 = emitter.zx(s_b_5_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_5_5=sym_15555_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_5_6 = (u32)s_b_5_4 */
    auto s_b_5_6 = emitter.truncate(s_b_5_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_5_8: sym_104297_3_parameter_value = s_b_5_7, dominates: s_b_29_1  */
    emitter.store_local(DV_sym_104297_3_parameter_value, s_b_5_7);
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
    /* execute.a64:928 [D] s_b_6_0 = sym_15561_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_15561_0_address, emitter.context().types().u64());
    /* execute.a64:928 [D] s_b_6_1: sym_102706_3_parameter_address = s_b_6_0, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_102706_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 2 s_b_6_0 => sym_102761_0_data16 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_102761_0_data16, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(2));
    }
    /* execute.a64:1679 [D] s_b_6_3 = sym_102761_0_data16 uint16_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_102761_0_data16, emitter.context().types().u16());
    /* execute.a64:1679 [D] s_b_6_4 = (s16)s_b_6_3 */
    auto s_b_6_4 = emitter.reinterpret(s_b_6_3, emitter.context().types().s16());
    /* execute.a64:1679 [D] s_b_6_5 = (s64)s_b_6_4 */
    auto s_b_6_5 = emitter.sx(s_b_6_4, emitter.context().types().s64());
    /* execute.a64:1679 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.reinterpret(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_7=sym_15555_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_6_8 = (u32)s_b_6_6 */
    auto s_b_6_8 = emitter.truncate(s_b_6_6, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_10: sym_104807_3_parameter_value = s_b_6_9, dominates: s_b_30_1  */
    emitter.store_local(DV_sym_104807_3_parameter_value, s_b_6_9);
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
    /* execute.a64:930 [D] s_b_7_0 = sym_15561_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_15561_0_address, emitter.context().types().u64());
    /* execute.a64:930 [D] s_b_7_1: sym_102897_3_parameter_address = s_b_7_0, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_102897_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 2 s_b_7_0 => sym_102952_0_data16 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_102952_0_data16, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(2));
    }
    /* execute.a64:1681 [D] s_b_7_3 = sym_102952_0_data16 uint16_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_102952_0_data16, emitter.context().types().u16());
    /* execute.a64:1681 [D] s_b_7_4 = (s16)s_b_7_3 */
    auto s_b_7_4 = emitter.reinterpret(s_b_7_3, emitter.context().types().s16());
    /* execute.a64:1681 [D] s_b_7_5 = (s64)s_b_7_4 */
    auto s_b_7_5 = emitter.sx(s_b_7_4, emitter.context().types().s64());
    /* execute.a64:1681 [D] s_b_7_6 = (u64)s_b_7_5 */
    auto s_b_7_6 = emitter.reinterpret(s_b_7_5, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_7=sym_15555_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_7_8: sym_105295_3_parameter_value = s_b_7_6, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_105295_3_parameter_value, s_b_7_6);
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
    /* execute.a64:937 [D] s_b_8_0 = sym_15561_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_15561_0_address, emitter.context().types().u64());
    /* execute.a64:937 [F] s_b_8_1=sym_15555_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_8_2 = (u64)s_b_8_1 (const) */
    /* ???:4294967295 [D] s_b_8_3 = s_b_8_0+s_b_8_2 */
    auto s_b_8_3 = emitter.add(s_b_8_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:937 [D] s_b_8_4: sym_15561_0_address = s_b_8_3, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_15561_0_address, s_b_8_3);
    /* execute.a64:937 [F] s_b_8_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:940 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:940 [D] s_b_9_1 = sym_15561_0_address uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_15561_0_address, emitter.context().types().u64());
    /* execute.a64:940 [D] s_b_9_2: sym_103078_3_parameter_value = s_b_9_1, dominates: s_b_15_0 s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_103078_3_parameter_value, s_b_9_1);
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
    /* execute.a64:2733 [F] s_b_10_0=sym_15555_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_10_2: sym_102486_1__R_s_b_0_5 = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_102486_1__R_s_b_0_5, s_b_10_1);
    /* execute.a64:2733 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_24,  */
  fixed_block_b_11: 
  {
    /* execute.a64:920 [D] s_b_11_0 = sym_102486_1__R_s_b_0_5 uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_102486_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:920 [D] s_b_11_1: sym_15561_0_address = s_b_11_0, dominates: s_b_1_0 s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15561_0_address, s_b_11_0);
    /* execute.a64:922 [F] s_b_11_2=sym_15555_3_parameter_inst.P (const) */
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
    /* execute.a64:1723 [D] s_b_12_1 = sym_102515_3_parameter_address uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_102515_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_12_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_12_1);
    /* execute.a64:0 [F] s_b_12_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_6, b_30,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1723 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_13_1 = sym_102706_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_102706_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_31,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1723 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_14_1 = sym_102897_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_102897_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_14_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2747 [D] s_b_15_0 = sym_103078_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_103078_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_15_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_15_2 = s_b_15_0&s_b_15_1 */
    auto s_b_15_2 = emitter.bitwise_and(s_b_15_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_15_3: sym_103078_3_parameter_value = s_b_15_2, dominates: s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_103078_3_parameter_value, s_b_15_2);
    /* execute.a64:2747 [F] s_b_15_4: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_9, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2750 [F] s_b_16_0=sym_15555_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_17_0 = sym_103078_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_103078_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_17_1: sym_103969_3_parameter_value = s_b_17_0, dominates: s_b_25_0 s_b_26_0 s_b_27_0  */
    emitter.store_local(DV_sym_103969_3_parameter_value, s_b_17_0);
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
    /* execute.a64:2753 [F] s_b_18_0=sym_15555_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_18_1 = sym_103078_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_103078_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_21_1: sym_103134_1__R_s_b_14_0 = s_b_21_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_103134_1__R_s_b_14_0, s_b_21_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_22_1: sym_103134_1__R_s_b_14_0 = s_b_22_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_103134_1__R_s_b_14_0, s_b_22_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_23_1: sym_103134_1__R_s_b_14_0 = s_b_23_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_103134_1__R_s_b_14_0, s_b_23_0);
    /* execute.a64:2707 [F] s_b_23_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2731 [D] s_b_24_0 = sym_103134_1__R_s_b_14_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_103134_1__R_s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_24_1: sym_102486_1__R_s_b_0_5 = s_b_24_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_102486_1__R_s_b_0_5, s_b_24_0);
    /* execute.a64:2731 [F] s_b_24_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_17,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2715 [D] s_b_25_0 = sym_103969_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_103969_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_25_1: WriteReg 20 = s_b_25_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_25_0);
    /* execute.a64:2715 [F] s_b_25_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_32,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2718 [D] s_b_26_0 = sym_103969_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_103969_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_26_1: WriteReg 20 = s_b_26_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_26_0);
    /* execute.a64:2718 [F] s_b_26_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_32,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2720 [D] s_b_27_0 = sym_103969_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_103969_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_27_1: WriteReg 21 = s_b_27_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_27_0, emitter.const_u8(8));
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
    /* execute.a64:2684 [F] s_b_29_0=sym_15555_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_29_1 = sym_104297_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_104297_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_29_2: WriteRegBank 0:s_b_29_0 = s_b_29_1 */
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
    /* execute.a64:2684 [F] s_b_30_0=sym_15555_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_30_1 = sym_104807_3_parameter_value uint64_t */
    auto s_b_30_1 = emitter.load_local(DV_sym_104807_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_30_2: WriteRegBank 0:s_b_30_0 = s_b_30_1 */
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
    /* execute.a64:2684 [F] s_b_31_0=sym_15555_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_31_1 = sym_105295_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_105295_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_31_2: WriteRegBank 0:s_b_31_0 = s_b_31_1 */
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
  auto DV_sym_115013_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115042_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115233_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115433_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_116477_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115145_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_116499_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_115361_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16325_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_16319_3_parameter_inst.rn (const) */
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
    /* execute.a64:796 [D] s_b_1_0 = sym_16325_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16325_0_address, emitter.context().types().u64());
    /* execute.a64:796 [D] s_b_1_1: sym_115042_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_115042_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2 = Load 4 s_b_1_0 => sym_115145_0_data32 */
    auto s_b_1_2 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_115145_0_data32, s_b_1_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_2, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_1_3 = sym_115145_0_data32 uint32_t */
    auto s_b_1_3 = emitter.load_local(DV_sym_115145_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_5=sym_16319_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_6 = (u32)s_b_1_4 */
    auto s_b_1_6 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_8: sym_116477_3_parameter_value = s_b_1_7, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_116477_3_parameter_value, s_b_1_7);
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
    /* execute.a64:798 [D] s_b_3_0 = sym_16325_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_16325_0_address, emitter.context().types().u64());
    /* execute.a64:798 [D] s_b_3_1: sym_115233_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_115233_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2 = Load 8 s_b_3_0 => sym_115361_0_data64 */
    auto s_b_3_2 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_115361_0_data64, s_b_3_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_3_3 = sym_115361_0_data64 uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_115361_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_3_4=sym_16319_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_3_5: sym_116499_3_parameter_value = s_b_3_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_116499_3_parameter_value, s_b_3_3);
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
    /* execute.a64:2733 [F] s_b_4_0=sym_16319_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_4_2: sym_115013_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_115013_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2733 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:793 [D] s_b_5_0 = sym_115013_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_115013_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:793 [D] s_b_5_1: sym_16325_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_16325_0_address, s_b_5_0);
    /* execute.a64:795 [F] s_b_5_2=sym_16319_3_parameter_inst.size (const) */
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
    /* execute.a64:1723 [D] s_b_6_1 = sym_115042_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_115042_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* execute.a64:0 [F] s_b_6_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3, b_15,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1723 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_7_1 = sym_115233_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_115233_3_parameter_address, emitter.context().types().u64());
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_9_1: sym_115433_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_115433_1__R_s_b_7_0, s_b_9_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_10_1: sym_115433_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_115433_1__R_s_b_7_0, s_b_10_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_11_1: sym_115433_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_115433_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2707 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2731 [D] s_b_12_0 = sym_115433_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_115433_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_12_1: sym_115013_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_115013_1__R_s_b_0_5, s_b_12_0);
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
    /* execute.a64:2684 [F] s_b_14_0=sym_16319_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_116477_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_116477_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
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
    /* execute.a64:2684 [F] s_b_15_0=sym_16319_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_116499_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_116499_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_movi(const aarch64_decode_a64_SIMD_MOD_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4810 [F] s_b_0_0=sym_16684_3_parameter_inst.Q (const) */
    /* execute.simd:4810 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4810 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4810 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:4810 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4811 [F] s_b_1_0=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:4811 [F] s_b_1_1=sym_16684_3_parameter_inst.immu64 (const) */
    /* execute.simd:6138 [F] s_b_1_2: WriteRegBank 2:s_b_1_0 = s_b_1_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6139 [F] s_b_1_3 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_1_4: WriteRegBank 3:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:4813 [F] s_b_3_0=sym_16684_3_parameter_inst.rd (const) */
    /* execute.simd:4813 [F] s_b_3_1=sym_16684_3_parameter_inst.immu64 (const) */
    /* execute.simd:4813 [F] s_b_3_2=sym_16684_3_parameter_inst.immu64 (const) */
    /* execute.simd:6145 [F] s_b_3_3: WriteRegBank 2:s_b_3_0 = s_b_3_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6146 [F] s_b_3_4: WriteRegBank 3:s_b_3_0 = s_b_3_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
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
  auto DV_sym_123374_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123303_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123366_1__R_s_b_4_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123522_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123544_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123440_1_tmp_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123443_1_tmp_s_b_12_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123492_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123432_1__R_s_b_12_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2349 [F] s_b_0_0=sym_18694_3_parameter_inst.sf (const) */
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
    /* execute.a64:2657 [F] s_b_1_0=sym_18694_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2651 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_1_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_1_5 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 */
    captive::arch::dbt::el::Value *s_b_1_6;
    s_b_1_6 = (s_b_1_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_1_5);
    /* execute.a64:2657 [D] s_b_1_7: sym_123303_1__R_s_b_0_4 = s_b_1_6, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_123303_1__R_s_b_0_4, s_b_1_6);
    /* execute.a64:2657 [F] s_b_1_8: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2659 [F] s_b_2_0=sym_18694_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2646 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_2_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_2_5 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_2_6: Select s_b_2_3 ? s_b_2_4 : s_b_2_5 */
    captive::arch::dbt::el::Value *s_b_2_6;
    s_b_2_6 = (s_b_2_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_2_5);
    /* execute.a64:2659 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_2_8: sym_123303_1__R_s_b_0_4 = s_b_2_7, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_123303_1__R_s_b_0_4, s_b_2_7);
    /* execute.a64:2659 [F] s_b_2_9: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2349 [D] s_b_3_0 = sym_123303_1__R_s_b_0_4 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_123303_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2350 [F] s_b_3_1=sym_18694_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_123374_1_tmp_s_b_4_0 = s_b_3_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_123374_1_tmp_s_b_4_0, s_b_3_0);
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
    /* execute.a64:2657 [F] s_b_4_0=sym_18694_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2651 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_4_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_4_5 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_4_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    captive::arch::dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2657 [D] s_b_4_7: sym_123366_1__R_s_b_4_5 = s_b_4_6, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_123366_1__R_s_b_4_5, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_18694_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2646 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_5_5 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_5_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_5_6: Select s_b_5_3 ? s_b_5_4 : s_b_5_5 */
    captive::arch::dbt::el::Value *s_b_5_6;
    s_b_5_6 = (s_b_5_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_5_5);
    /* execute.a64:2659 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_5_8: sym_123366_1__R_s_b_4_5 = s_b_5_7, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_123366_1__R_s_b_4_5, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_123374_1_tmp_s_b_4_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_123374_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2350 [D] s_b_6_1 = sym_123366_1__R_s_b_4_5 uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_123366_1__R_s_b_4_5, emitter.context().types().u64());
    /* execute.a64:2351 [F] s_b_6_2=sym_18694_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_6_3: sym_123440_1_tmp_s_b_12_0 = s_b_6_0, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_123440_1_tmp_s_b_12_0, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_4: sym_123443_1_tmp_s_b_12_1 = s_b_6_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_123443_1_tmp_s_b_12_1, s_b_6_1);
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
    /* execute.a64:2657 [F] s_b_7_0=sym_18694_3_parameter_inst.ra (const) */
    /* execute.a64:2651 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2651 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_7_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_7_5 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_7_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_7_6: Select s_b_7_3 ? s_b_7_4 : s_b_7_5 */
    captive::arch::dbt::el::Value *s_b_7_6;
    s_b_7_6 = (s_b_7_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_7_5);
    /* execute.a64:2657 [D] s_b_7_7: sym_123432_1__R_s_b_12_6 = s_b_7_6, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_123432_1__R_s_b_12_6, s_b_7_6);
    /* execute.a64:2657 [F] s_b_7_8: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2659 [F] s_b_8_0=sym_18694_3_parameter_inst.ra (const) */
    /* execute.a64:2646 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2646 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_8_5 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_8_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    captive::arch::dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2659 [D] s_b_8_7 = (u64)s_b_8_6 */
    auto s_b_8_7 = emitter.zx(s_b_8_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_8_8: sym_123432_1__R_s_b_12_6 = s_b_8_7, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_123432_1__R_s_b_12_6, s_b_8_7);
    /* execute.a64:2659 [F] s_b_8_9: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_123443_1_tmp_s_b_12_1 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_123443_1_tmp_s_b_12_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1 = sym_123440_1_tmp_s_b_12_0 uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_123440_1_tmp_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2351 [D] s_b_9_2 = sym_123432_1__R_s_b_12_6 uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_123432_1__R_s_b_12_6, emitter.context().types().u64());
    /* execute.a64:2353 [D] s_b_9_3 = (u64)s_b_9_1 */
    auto s_b_9_3 = (captive::arch::dbt::el::Value *)s_b_9_1;
    /* execute.a64:2353 [D] s_b_9_4 = s_b_9_3*s_b_9_0 */
    auto s_b_9_4 = emitter.mul(s_b_9_3, s_b_9_0);
    /* execute.a64:2353 [D] s_b_9_5 = s_b_9_2-s_b_9_4 */
    auto s_b_9_5 = emitter.sub(s_b_9_2, s_b_9_4);
    /* execute.a64:2354 [F] s_b_9_6=sym_18694_3_parameter_inst.sf (const) */
    /* execute.a64:2354 [D] s_b_9_7: sym_123492_3_parameter_value = s_b_9_5, dominates: s_b_10_1 s_b_11_1  */
    emitter.store_local(DV_sym_123492_3_parameter_value, s_b_9_5);
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
    /* execute.a64:2691 [F] s_b_10_0=sym_18694_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_10_1 = sym_123492_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_123492_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_10_2: sym_123522_3_parameter_value = s_b_10_1, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_123522_3_parameter_value, s_b_10_1);
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
    /* execute.a64:2693 [F] s_b_11_0=sym_18694_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_11_1 = sym_123492_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_123492_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_2 = (u32)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_4: sym_123544_3_parameter_value = s_b_11_3, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_123544_3_parameter_value, s_b_11_3);
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
    /* execute.a64:2684 [F] s_b_13_0=sym_18694_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_13_1 = sym_123522_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_123522_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2684 [F] s_b_14_0=sym_18694_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_123544_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_123544_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1,emitter.const_u8(8));
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
  auto DV_sym_123943_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124092_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124057_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123980_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19214_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123928_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:215 [F] s_b_0_0=sym_19209_3_parameter_inst.sf (const) */
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
    /* execute.a64:218 [D] s_b_1_0 = sym_19214_0_op1 uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_19214_0_op1, emitter.context().types().u64());
    /* execute.a64:218 [F] s_b_1_1=sym_19209_3_parameter_inst.immu64 (const) */
    /* execute.a64:218 [D] s_b_1_2 = s_b_1_0|s_b_1_1 */
    auto s_b_1_2 = emitter.bitwise_or(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.a64:219 [F] s_b_1_3 = constant u8 1 (const) */
    /* execute.a64:219 [D] s_b_1_4: sym_123943_3_parameter_value = s_b_1_2, dominates: s_b_7_0 s_b_9_0 s_b_10_1  */
    emitter.store_local(DV_sym_123943_3_parameter_value, s_b_1_2);
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
    /* execute.a64:221 [D] s_b_3_0 = sym_19214_0_op1 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_19214_0_op1, emitter.context().types().u64());
    /* execute.a64:221 [D] s_b_3_1 = (u32)s_b_3_0 */
    auto s_b_3_1 = emitter.truncate(s_b_3_0, emitter.context().types().u32());
    /* execute.a64:221 [F] s_b_3_2=sym_19209_3_parameter_inst.immu32 (const) */
    /* execute.a64:221 [D] s_b_3_3 = s_b_3_1|s_b_3_2 */
    auto s_b_3_3 = emitter.bitwise_or(s_b_3_1, emitter.const_u32(insn.immu32));
    /* execute.a64:222 [F] s_b_3_4 = constant u8 0 (const) */
    /* execute.a64:222 [D] s_b_3_5 = (u64)s_b_3_3 */
    auto s_b_3_5 = emitter.zx(s_b_3_3, emitter.context().types().u64());
    /* execute.a64:222 [D] s_b_3_6: sym_123980_3_parameter_value = s_b_3_5, dominates: s_b_11_0 s_b_13_0 s_b_14_1  */
    emitter.store_local(DV_sym_123980_3_parameter_value, s_b_3_5);
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
    /* execute.a64:2657 [F] s_b_4_0=sym_19209_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2651 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_4_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_4_5 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    captive::arch::dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2657 [D] s_b_4_7: sym_123928_1__R_s_b_0_4 = s_b_4_6, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_123928_1__R_s_b_0_4, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_19209_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2646 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_5_5 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_5_6: Select s_b_5_3 ? s_b_5_4 : s_b_5_5 */
    captive::arch::dbt::el::Value *s_b_5_6;
    s_b_5_6 = (s_b_5_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_5_5);
    /* execute.a64:2659 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_5_8: sym_123928_1__R_s_b_0_4 = s_b_5_7, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_123928_1__R_s_b_0_4, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:215 [D] s_b_6_0 = sym_123928_1__R_s_b_0_4 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_123928_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:215 [D] s_b_6_1: sym_19214_0_op1 = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_19214_0_op1, s_b_6_0);
    /* execute.a64:217 [F] s_b_6_2=sym_19209_3_parameter_inst.sf (const) */
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
    /* execute.a64:2747 [D] s_b_7_0 = sym_123943_3_parameter_value uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_123943_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_7_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_7_2 = s_b_7_0&s_b_7_1 */
    auto s_b_7_2 = emitter.bitwise_and(s_b_7_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_7_3: sym_123943_3_parameter_value = s_b_7_2, dominates: s_b_9_0 s_b_10_1  */
    emitter.store_local(DV_sym_123943_3_parameter_value, s_b_7_2);
    /* execute.a64:2747 [F] s_b_7_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_1, b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2750 [F] s_b_8_0=sym_19209_3_parameter_inst.rd (const) */
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
    /* execute.a64:2751 [D] s_b_9_0 = sym_123943_3_parameter_value uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_123943_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_9_1: sym_124057_3_parameter_value = s_b_9_0, dominates: s_b_15_0 s_b_16_0 s_b_17_0  */
    emitter.store_local(DV_sym_124057_3_parameter_value, s_b_9_0);
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
    /* execute.a64:2753 [F] s_b_10_0=sym_19209_3_parameter_inst.rd (const) */
    /* execute.a64:2753 [D] s_b_10_1 = sym_123943_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_123943_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1);
    /* execute.a64:2753 [F] s_b_10_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2747 [D] s_b_11_0 = sym_123980_3_parameter_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_123980_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_11_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_11_2 = s_b_11_0&s_b_11_1 */
    auto s_b_11_2 = emitter.bitwise_and(s_b_11_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_11_3: sym_123980_3_parameter_value = s_b_11_2, dominates: s_b_13_0 s_b_14_1  */
    emitter.store_local(DV_sym_123980_3_parameter_value, s_b_11_2);
    /* execute.a64:2747 [F] s_b_11_4: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_3, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2750 [F] s_b_12_0=sym_19209_3_parameter_inst.rd (const) */
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
    /* execute.a64:2751 [D] s_b_13_0 = sym_123980_3_parameter_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_123980_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_13_1: sym_124092_3_parameter_value = s_b_13_0, dominates: s_b_18_0 s_b_19_0 s_b_20_0  */
    emitter.store_local(DV_sym_124092_3_parameter_value, s_b_13_0);
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
    /* execute.a64:2753 [F] s_b_14_0=sym_19209_3_parameter_inst.rd (const) */
    /* execute.a64:2753 [D] s_b_14_1 = sym_123980_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_123980_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1);
    /* execute.a64:2753 [F] s_b_14_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2715 [D] s_b_15_0 = sym_124057_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_124057_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_15_1: WriteReg 20 = s_b_15_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_15_0);
    /* execute.a64:2715 [F] s_b_15_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_21,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2718 [D] s_b_16_0 = sym_124057_3_parameter_value uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_124057_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_16_1: WriteReg 20 = s_b_16_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_16_0);
    /* execute.a64:2718 [F] s_b_16_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_21,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2720 [D] s_b_17_0 = sym_124057_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_124057_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_17_1: WriteReg 21 = s_b_17_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_17_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_17_0);
    /* execute.a64:2720 [F] s_b_17_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_13,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2715 [D] s_b_18_0 = sym_124092_3_parameter_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_124092_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_18_1: WriteReg 20 = s_b_18_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_18_0);
    /* execute.a64:2715 [F] s_b_18_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_22,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2718 [D] s_b_19_0 = sym_124092_3_parameter_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_124092_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_19_1: WriteReg 20 = s_b_19_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_19_0);
    /* execute.a64:2718 [F] s_b_19_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_22,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2720 [D] s_b_20_0 = sym_124092_3_parameter_value uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_124092_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_20_1: WriteReg 21 = s_b_20_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
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
  auto DV_sym_125059_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124893_1__R_s_b_0_7 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_125081_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_19734_0_output;
  auto DV_sym_19734_0_output = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19740_0_input = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_124956_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2154 [F] s_b_0_0 = constant u64 0 (const) */
    /* execute.a64:2154 [F] s_b_0_1: sym_19734_0_output = s_b_0_0 (const), dominates:  */
    CV_sym_19734_0_output = (uint64_t)0ULL;
    /* execute.a64:2155 [F] s_b_0_2=sym_19731_3_parameter_inst.sf (const) */
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
    /* execute.a64:2158 [D] s_b_1_0 = sym_19740_0_input uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_19740_0_input, emitter.context().types().u64());
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
    /* execute.a64:2158 [D] s_b_1_39: sym_19734_0_output = s_b_1_38, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_19734_0_output, s_b_1_38);
    /* execute.a64:2158 [F] s_b_1_40: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2163 [F] s_b_2_0=sym_19731_3_parameter_inst.sf (const) */
    /* execute.a64:2163 [D] s_b_2_1 = sym_19734_0_output uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_19734_0_output, emitter.context().types().u64());
    /* execute.a64:2163 [D] s_b_2_2: sym_124956_3_parameter_value = s_b_2_1, dominates: s_b_7_1 s_b_8_1  */
    emitter.store_local(DV_sym_124956_3_parameter_value, s_b_2_1);
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
    /* execute.a64:2160 [D] s_b_3_0 = sym_19740_0_input uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_19740_0_input, emitter.context().types().u64());
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
    /* execute.a64:2160 [D] s_b_3_25: sym_19734_0_output = s_b_3_24, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_19734_0_output, s_b_3_24);
    /* execute.a64:2160 [F] s_b_3_26: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2657 [F] s_b_4_0=sym_19731_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2651 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_4_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_4_5 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    captive::arch::dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2657 [D] s_b_4_7: sym_124893_1__R_s_b_0_7 = s_b_4_6, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_124893_1__R_s_b_0_7, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_19731_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2646 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_5_5 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_5_6: Select s_b_5_3 ? s_b_5_4 : s_b_5_5 */
    captive::arch::dbt::el::Value *s_b_5_6;
    s_b_5_6 = (s_b_5_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_5_5);
    /* execute.a64:2659 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_5_8: sym_124893_1__R_s_b_0_7 = s_b_5_7, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_124893_1__R_s_b_0_7, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2155 [D] s_b_6_0 = sym_124893_1__R_s_b_0_7 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_124893_1__R_s_b_0_7, emitter.context().types().u64());
    /* execute.a64:2155 [D] s_b_6_1: sym_19740_0_input = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_19740_0_input, s_b_6_0);
    /* execute.a64:2157 [F] s_b_6_2=sym_19731_3_parameter_inst.sf (const) */
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
    /* execute.a64:2691 [F] s_b_7_0=sym_19731_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_7_1 = sym_124956_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_124956_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_7_2: sym_125059_3_parameter_value = s_b_7_1, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_125059_3_parameter_value, s_b_7_1);
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
    /* execute.a64:2693 [F] s_b_8_0=sym_19731_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_8_1 = sym_124956_3_parameter_value uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_124956_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_8_2 = (u32)s_b_8_1 */
    auto s_b_8_2 = emitter.truncate(s_b_8_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_8_3 = (u64)s_b_8_2 */
    auto s_b_8_3 = emitter.zx(s_b_8_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_8_4: sym_125081_3_parameter_value = s_b_8_3, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_125081_3_parameter_value, s_b_8_3);
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
    /* execute.a64:2684 [F] s_b_10_0=sym_19731_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_10_1 = sym_125059_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_125059_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1);
    /* execute.a64:0 [F] s_b_10_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2684 [F] s_b_11_0=sym_19731_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_11_1 = sym_125081_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_125081_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1,emitter.const_u8(8));
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
    /* execute.simd:5337 [F] s_b_0_0=sym_20335_3_parameter_inst.tb (const) */
    /* execute.simd:5338 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5350 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5362 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5374 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5386 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5398 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5337 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5339 [F] s_b_2_0=sym_20335_3_parameter_inst.rn (const) */
    /* execute.simd:5339 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5339 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:5340 [F] s_b_2_3=sym_20335_3_parameter_inst.rm (const) */
    /* execute.simd:5340 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5340 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5344 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5344 [D] s_b_2_9 = (s16)s_b_2_8 */
    auto s_b_2_9 = emitter.sx(s_b_2_8, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5344 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5344 [D] s_b_2_12 = (s16)s_b_2_11 */
    auto s_b_2_12 = emitter.sx(s_b_2_11, emitter.context().types().s16());
    /* execute.simd:5344 [D] s_b_2_13 = s_b_2_9+s_b_2_12 */
    auto s_b_2_13 = emitter.add(s_b_2_9, s_b_2_12);
    /* execute.simd:5344 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5344 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5344 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5344 [D] s_b_2_18 = (s16)s_b_2_17 */
    auto s_b_2_18 = emitter.sx(s_b_2_17, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5344 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5344 [D] s_b_2_21 = (s16)s_b_2_20 */
    auto s_b_2_21 = emitter.sx(s_b_2_20, emitter.context().types().s16());
    /* execute.simd:5344 [D] s_b_2_22 = s_b_2_18+s_b_2_21 */
    auto s_b_2_22 = emitter.add(s_b_2_18, s_b_2_21);
    /* execute.simd:5344 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5344 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5344 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5344 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5344 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5344 [D] s_b_2_30 = (s16)s_b_2_29 */
    auto s_b_2_30 = emitter.sx(s_b_2_29, emitter.context().types().s16());
    /* execute.simd:5344 [D] s_b_2_31 = s_b_2_27+s_b_2_30 */
    auto s_b_2_31 = emitter.add(s_b_2_27, s_b_2_30);
    /* execute.simd:5344 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5344 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5344 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5344 [D] s_b_2_36 = (s16)s_b_2_35 */
    auto s_b_2_36 = emitter.sx(s_b_2_35, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5344 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5344 [D] s_b_2_39 = (s16)s_b_2_38 */
    auto s_b_2_39 = emitter.sx(s_b_2_38, emitter.context().types().s16());
    /* execute.simd:5344 [D] s_b_2_40 = s_b_2_36+s_b_2_39 */
    auto s_b_2_40 = emitter.add(s_b_2_36, s_b_2_39);
    /* execute.simd:5344 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5344 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5344 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5344 [D] s_b_2_45 = (s16)s_b_2_44 */
    auto s_b_2_45 = emitter.sx(s_b_2_44, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5344 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5344 [D] s_b_2_48 = (s16)s_b_2_47 */
    auto s_b_2_48 = emitter.sx(s_b_2_47, emitter.context().types().s16());
    /* execute.simd:5344 [D] s_b_2_49 = s_b_2_45+s_b_2_48 */
    auto s_b_2_49 = emitter.add(s_b_2_45, s_b_2_48);
    /* execute.simd:5344 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5344 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5344 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5344 [D] s_b_2_54 = (s16)s_b_2_53 */
    auto s_b_2_54 = emitter.sx(s_b_2_53, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5344 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5344 [D] s_b_2_57 = (s16)s_b_2_56 */
    auto s_b_2_57 = emitter.sx(s_b_2_56, emitter.context().types().s16());
    /* execute.simd:5344 [D] s_b_2_58 = s_b_2_54+s_b_2_57 */
    auto s_b_2_58 = emitter.add(s_b_2_54, s_b_2_57);
    /* execute.simd:5344 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5344 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5344 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5344 [D] s_b_2_63 = (s16)s_b_2_62 */
    auto s_b_2_63 = emitter.sx(s_b_2_62, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5344 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5344 [D] s_b_2_66 = (s16)s_b_2_65 */
    auto s_b_2_66 = emitter.sx(s_b_2_65, emitter.context().types().s16());
    /* execute.simd:5344 [D] s_b_2_67 = s_b_2_63+s_b_2_66 */
    auto s_b_2_67 = emitter.add(s_b_2_63, s_b_2_66);
    /* execute.simd:5344 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5344 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5344 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5344 [D] s_b_2_72 = (s16)s_b_2_71 */
    auto s_b_2_72 = emitter.sx(s_b_2_71, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5344 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5344 [D] s_b_2_75 = (s16)s_b_2_74 */
    auto s_b_2_75 = emitter.sx(s_b_2_74, emitter.context().types().s16());
    /* execute.simd:5344 [D] s_b_2_76 = s_b_2_72+s_b_2_75 */
    auto s_b_2_76 = emitter.add(s_b_2_72, s_b_2_75);
    /* execute.simd:5344 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5344 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5347 [F] s_b_2_79=sym_20335_3_parameter_inst.rd (const) */
    /* execute.simd:5347 [D] s_b_2_80 = (v8u16)s_b_2_78 */
    auto s_b_2_80 = emitter.reinterpret(s_b_2_78, emitter.context().types().v8u16());
    /* execute.simd:5347 [D] s_b_2_81: WriteRegBank 18:s_b_2_79 = s_b_2_80 */
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
    /* execute.simd:5351 [F] s_b_3_0=sym_20335_3_parameter_inst.rn (const) */
    /* execute.simd:5351 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5351 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:5352 [F] s_b_3_3=sym_20335_3_parameter_inst.rm (const) */
    /* execute.simd:5352 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5352 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:5356 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5356 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5356 [D] s_b_3_9 = (s16)s_b_3_8 */
    auto s_b_3_9 = emitter.sx(s_b_3_8, emitter.context().types().s16());
    /* execute.simd:5356 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5356 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5356 [D] s_b_3_12 = (s16)s_b_3_11 */
    auto s_b_3_12 = emitter.sx(s_b_3_11, emitter.context().types().s16());
    /* execute.simd:5356 [D] s_b_3_13 = s_b_3_9+s_b_3_12 */
    auto s_b_3_13 = emitter.add(s_b_3_9, s_b_3_12);
    /* execute.simd:5356 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5356 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5356 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5356 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5356 [D] s_b_3_18 = (s16)s_b_3_17 */
    auto s_b_3_18 = emitter.sx(s_b_3_17, emitter.context().types().s16());
    /* execute.simd:5356 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5356 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5356 [D] s_b_3_21 = (s16)s_b_3_20 */
    auto s_b_3_21 = emitter.sx(s_b_3_20, emitter.context().types().s16());
    /* execute.simd:5356 [D] s_b_3_22 = s_b_3_18+s_b_3_21 */
    auto s_b_3_22 = emitter.add(s_b_3_18, s_b_3_21);
    /* execute.simd:5356 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5356 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5356 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5356 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5356 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5356 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5356 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5356 [D] s_b_3_30 = (s16)s_b_3_29 */
    auto s_b_3_30 = emitter.sx(s_b_3_29, emitter.context().types().s16());
    /* execute.simd:5356 [D] s_b_3_31 = s_b_3_27+s_b_3_30 */
    auto s_b_3_31 = emitter.add(s_b_3_27, s_b_3_30);
    /* execute.simd:5356 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5356 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5356 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5356 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5356 [D] s_b_3_36 = (s16)s_b_3_35 */
    auto s_b_3_36 = emitter.sx(s_b_3_35, emitter.context().types().s16());
    /* execute.simd:5356 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5356 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5356 [D] s_b_3_39 = (s16)s_b_3_38 */
    auto s_b_3_39 = emitter.sx(s_b_3_38, emitter.context().types().s16());
    /* execute.simd:5356 [D] s_b_3_40 = s_b_3_36+s_b_3_39 */
    auto s_b_3_40 = emitter.add(s_b_3_36, s_b_3_39);
    /* execute.simd:5356 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5356 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5356 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5356 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5356 [D] s_b_3_45 = (s16)s_b_3_44 */
    auto s_b_3_45 = emitter.sx(s_b_3_44, emitter.context().types().s16());
    /* execute.simd:5356 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5356 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5356 [D] s_b_3_48 = (s16)s_b_3_47 */
    auto s_b_3_48 = emitter.sx(s_b_3_47, emitter.context().types().s16());
    /* execute.simd:5356 [D] s_b_3_49 = s_b_3_45+s_b_3_48 */
    auto s_b_3_49 = emitter.add(s_b_3_45, s_b_3_48);
    /* execute.simd:5356 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5356 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5356 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5356 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5356 [D] s_b_3_54 = (s16)s_b_3_53 */
    auto s_b_3_54 = emitter.sx(s_b_3_53, emitter.context().types().s16());
    /* execute.simd:5356 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5356 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5356 [D] s_b_3_57 = (s16)s_b_3_56 */
    auto s_b_3_57 = emitter.sx(s_b_3_56, emitter.context().types().s16());
    /* execute.simd:5356 [D] s_b_3_58 = s_b_3_54+s_b_3_57 */
    auto s_b_3_58 = emitter.add(s_b_3_54, s_b_3_57);
    /* execute.simd:5356 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5356 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5356 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5356 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5356 [D] s_b_3_63 = (s16)s_b_3_62 */
    auto s_b_3_63 = emitter.sx(s_b_3_62, emitter.context().types().s16());
    /* execute.simd:5356 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5356 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5356 [D] s_b_3_66 = (s16)s_b_3_65 */
    auto s_b_3_66 = emitter.sx(s_b_3_65, emitter.context().types().s16());
    /* execute.simd:5356 [D] s_b_3_67 = s_b_3_63+s_b_3_66 */
    auto s_b_3_67 = emitter.add(s_b_3_63, s_b_3_66);
    /* execute.simd:5356 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5356 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5356 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5356 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5356 [D] s_b_3_72 = (s16)s_b_3_71 */
    auto s_b_3_72 = emitter.sx(s_b_3_71, emitter.context().types().s16());
    /* execute.simd:5356 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5356 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5356 [D] s_b_3_75 = (s16)s_b_3_74 */
    auto s_b_3_75 = emitter.sx(s_b_3_74, emitter.context().types().s16());
    /* execute.simd:5356 [D] s_b_3_76 = s_b_3_72+s_b_3_75 */
    auto s_b_3_76 = emitter.add(s_b_3_72, s_b_3_75);
    /* execute.simd:5356 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5356 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5359 [F] s_b_3_79=sym_20335_3_parameter_inst.rd (const) */
    /* execute.simd:5359 [D] s_b_3_80 = (v8u16)s_b_3_78 */
    auto s_b_3_80 = emitter.reinterpret(s_b_3_78, emitter.context().types().v8u16());
    /* execute.simd:5359 [D] s_b_3_81: WriteRegBank 18:s_b_3_79 = s_b_3_80 */
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
    /* execute.simd:5363 [F] s_b_4_0=sym_20335_3_parameter_inst.rn (const) */
    /* execute.simd:5363 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5363 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:5364 [F] s_b_4_3=sym_20335_3_parameter_inst.rm (const) */
    /* execute.simd:5364 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5364 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5368 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5368 [D] s_b_4_9 = (s32)s_b_4_8 */
    auto s_b_4_9 = emitter.sx(s_b_4_8, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5368 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5368 [D] s_b_4_12 = (s32)s_b_4_11 */
    auto s_b_4_12 = emitter.sx(s_b_4_11, emitter.context().types().s32());
    /* execute.simd:5368 [D] s_b_4_13 = s_b_4_9+s_b_4_12 */
    auto s_b_4_13 = emitter.add(s_b_4_9, s_b_4_12);
    /* execute.simd:5368 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5368 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5368 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5368 [D] s_b_4_18 = (s32)s_b_4_17 */
    auto s_b_4_18 = emitter.sx(s_b_4_17, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5368 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5368 [D] s_b_4_21 = (s32)s_b_4_20 */
    auto s_b_4_21 = emitter.sx(s_b_4_20, emitter.context().types().s32());
    /* execute.simd:5368 [D] s_b_4_22 = s_b_4_18+s_b_4_21 */
    auto s_b_4_22 = emitter.add(s_b_4_18, s_b_4_21);
    /* execute.simd:5368 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5368 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5368 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5368 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5368 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5368 [D] s_b_4_30 = (s32)s_b_4_29 */
    auto s_b_4_30 = emitter.sx(s_b_4_29, emitter.context().types().s32());
    /* execute.simd:5368 [D] s_b_4_31 = s_b_4_27+s_b_4_30 */
    auto s_b_4_31 = emitter.add(s_b_4_27, s_b_4_30);
    /* execute.simd:5368 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5368 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5368 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5368 [D] s_b_4_36 = (s32)s_b_4_35 */
    auto s_b_4_36 = emitter.sx(s_b_4_35, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5368 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5368 [D] s_b_4_39 = (s32)s_b_4_38 */
    auto s_b_4_39 = emitter.sx(s_b_4_38, emitter.context().types().s32());
    /* execute.simd:5368 [D] s_b_4_40 = s_b_4_36+s_b_4_39 */
    auto s_b_4_40 = emitter.add(s_b_4_36, s_b_4_39);
    /* execute.simd:5368 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5368 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5371 [F] s_b_4_43=sym_20335_3_parameter_inst.rd (const) */
    /* execute.simd:5371 [D] s_b_4_44 = (v4u32)s_b_4_42 */
    auto s_b_4_44 = emitter.reinterpret(s_b_4_42, emitter.context().types().v4u32());
    /* execute.simd:5371 [D] s_b_4_45: WriteRegBank 20:s_b_4_43 = s_b_4_44 */
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
    /* execute.simd:5375 [F] s_b_5_0=sym_20335_3_parameter_inst.rn (const) */
    /* execute.simd:5375 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5375 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:5376 [F] s_b_5_3=sym_20335_3_parameter_inst.rm (const) */
    /* execute.simd:5376 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5376 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:5380 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5380 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5380 [D] s_b_5_9 = (s32)s_b_5_8 */
    auto s_b_5_9 = emitter.sx(s_b_5_8, emitter.context().types().s32());
    /* execute.simd:5380 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5380 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5380 [D] s_b_5_12 = (s32)s_b_5_11 */
    auto s_b_5_12 = emitter.sx(s_b_5_11, emitter.context().types().s32());
    /* execute.simd:5380 [D] s_b_5_13 = s_b_5_9+s_b_5_12 */
    auto s_b_5_13 = emitter.add(s_b_5_9, s_b_5_12);
    /* execute.simd:5380 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5380 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5380 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5380 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5380 [D] s_b_5_18 = (s32)s_b_5_17 */
    auto s_b_5_18 = emitter.sx(s_b_5_17, emitter.context().types().s32());
    /* execute.simd:5380 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5380 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5380 [D] s_b_5_21 = (s32)s_b_5_20 */
    auto s_b_5_21 = emitter.sx(s_b_5_20, emitter.context().types().s32());
    /* execute.simd:5380 [D] s_b_5_22 = s_b_5_18+s_b_5_21 */
    auto s_b_5_22 = emitter.add(s_b_5_18, s_b_5_21);
    /* execute.simd:5380 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5380 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5380 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5380 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5380 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5380 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5380 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5380 [D] s_b_5_30 = (s32)s_b_5_29 */
    auto s_b_5_30 = emitter.sx(s_b_5_29, emitter.context().types().s32());
    /* execute.simd:5380 [D] s_b_5_31 = s_b_5_27+s_b_5_30 */
    auto s_b_5_31 = emitter.add(s_b_5_27, s_b_5_30);
    /* execute.simd:5380 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5380 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5380 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5380 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5380 [D] s_b_5_36 = (s32)s_b_5_35 */
    auto s_b_5_36 = emitter.sx(s_b_5_35, emitter.context().types().s32());
    /* execute.simd:5380 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5380 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5380 [D] s_b_5_39 = (s32)s_b_5_38 */
    auto s_b_5_39 = emitter.sx(s_b_5_38, emitter.context().types().s32());
    /* execute.simd:5380 [D] s_b_5_40 = s_b_5_36+s_b_5_39 */
    auto s_b_5_40 = emitter.add(s_b_5_36, s_b_5_39);
    /* execute.simd:5380 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5380 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5383 [F] s_b_5_43=sym_20335_3_parameter_inst.rd (const) */
    /* execute.simd:5383 [D] s_b_5_44 = (v4u32)s_b_5_42 */
    auto s_b_5_44 = emitter.reinterpret(s_b_5_42, emitter.context().types().v4u32());
    /* execute.simd:5383 [D] s_b_5_45: WriteRegBank 20:s_b_5_43 = s_b_5_44 */
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
    /* execute.simd:5387 [F] s_b_6_0=sym_20335_3_parameter_inst.rn (const) */
    /* execute.simd:5387 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5387 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:5388 [F] s_b_6_3=sym_20335_3_parameter_inst.rm (const) */
    /* execute.simd:5388 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5388 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5392 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5392 [D] s_b_6_9 = (s64)s_b_6_8 */
    auto s_b_6_9 = emitter.sx(s_b_6_8, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5392 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5392 [D] s_b_6_12 = (s64)s_b_6_11 */
    auto s_b_6_12 = emitter.sx(s_b_6_11, emitter.context().types().s64());
    /* execute.simd:5392 [D] s_b_6_13 = s_b_6_9+s_b_6_12 */
    auto s_b_6_13 = emitter.add(s_b_6_9, s_b_6_12);
    /* execute.simd:5392 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5392 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5392 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5392 [D] s_b_6_18 = (s64)s_b_6_17 */
    auto s_b_6_18 = emitter.sx(s_b_6_17, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5392 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5392 [D] s_b_6_21 = (s64)s_b_6_20 */
    auto s_b_6_21 = emitter.sx(s_b_6_20, emitter.context().types().s64());
    /* execute.simd:5392 [D] s_b_6_22 = s_b_6_18+s_b_6_21 */
    auto s_b_6_22 = emitter.add(s_b_6_18, s_b_6_21);
    /* execute.simd:5392 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5392 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:5395 [F] s_b_6_25=sym_20335_3_parameter_inst.rd (const) */
    /* execute.simd:5395 [D] s_b_6_26 = (v2u64)s_b_6_24 */
    auto s_b_6_26 = emitter.reinterpret(s_b_6_24, emitter.context().types().v2u64());
    /* execute.simd:5395 [D] s_b_6_27: WriteRegBank 21:s_b_6_25 = s_b_6_26 */
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
    /* execute.simd:5399 [F] s_b_7_0=sym_20335_3_parameter_inst.rn (const) */
    /* execute.simd:5399 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5399 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:5400 [F] s_b_7_3=sym_20335_3_parameter_inst.rm (const) */
    /* execute.simd:5400 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5400 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:5404 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:5404 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5404 [D] s_b_7_9 = (s64)s_b_7_8 */
    auto s_b_7_9 = emitter.sx(s_b_7_8, emitter.context().types().s64());
    /* execute.simd:5404 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:5404 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5404 [D] s_b_7_12 = (s64)s_b_7_11 */
    auto s_b_7_12 = emitter.sx(s_b_7_11, emitter.context().types().s64());
    /* execute.simd:5404 [D] s_b_7_13 = s_b_7_9+s_b_7_12 */
    auto s_b_7_13 = emitter.add(s_b_7_9, s_b_7_12);
    /* execute.simd:5404 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:5404 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:5404 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:5404 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5404 [D] s_b_7_18 = (s64)s_b_7_17 */
    auto s_b_7_18 = emitter.sx(s_b_7_17, emitter.context().types().s64());
    /* execute.simd:5404 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:5404 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5404 [D] s_b_7_21 = (s64)s_b_7_20 */
    auto s_b_7_21 = emitter.sx(s_b_7_20, emitter.context().types().s64());
    /* execute.simd:5404 [D] s_b_7_22 = s_b_7_18+s_b_7_21 */
    auto s_b_7_22 = emitter.add(s_b_7_18, s_b_7_21);
    /* execute.simd:5404 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:5404 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:5407 [F] s_b_7_25=sym_20335_3_parameter_inst.rd (const) */
    /* execute.simd:5407 [D] s_b_7_26 = (v2u64)s_b_7_24 */
    auto s_b_7_26 = emitter.reinterpret(s_b_7_24, emitter.context().types().v2u64());
    /* execute.simd:5407 [D] s_b_7_27: WriteRegBank 21:s_b_7_25 = s_b_7_26 */
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
    /* execute.simd:5411 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5337 [F] s_b_8_1: Jump b_1 (const) */
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
    /* execute.simd:4762 [F] s_b_0_0=sym_22484_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4762 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4763 [F] s_b_1_0=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4763 [F] s_b_1_1=sym_22484_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:4763 [F] s_b_1_3=sym_22484_3_parameter_inst.shift_amount (const) */
    /* execute.simd:4763 [F] s_b_1_4 = (u64)s_b_1_3 (const) */
    /* execute.simd:4763 [D] s_b_1_5 = s_b_1_2<<s_b_1_4 */
    auto s_b_1_5 = emitter.shl(s_b_1_2, emitter.const_u64(((uint64_t)insn.shift_amount)));
    /* execute.simd:6138 [D] s_b_1_6: WriteRegBank 2:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6139 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_1_8: WriteRegBank 3:s_b_1_0 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:4765 [F] s_b_3_0=sym_22484_3_parameter_inst.arrangement (const) */
    /* execute.simd:4766 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:4772 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:4777 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:4783 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:4788 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:4794 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:4799 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:4765 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
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
    /* execute.simd:4767 [F] s_b_4_0=sym_22484_3_parameter_inst.rn (const) */
    /* execute.simd:4767 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:4768 [F] s_b_4_2=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4768 [F] s_b_4_3=sym_22484_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_4_4 = (v8u8)s_b_4_3 (const) */
    auto s_b_4_4 = wutils::Vector<uint8_t, 8>(insn.shift_amount);
    /* execute.simd:4768 [D] s_b_4_5 = s_b_4_1<<s_b_4_4 */
    auto s_b_4_5 = emitter.shl(s_b_4_1, emitter.constant_vector_splat(s_b_4_4[0], emitter.context().types().v8u8()));
    /* execute.simd:4768 [D] s_b_4_6: WriteRegBank 15:s_b_4_2 = s_b_4_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_5);
    /* execute.simd:4769 [F] s_b_4_7=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4769 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:4769 [F] s_b_4_9: WriteRegBank 3:s_b_4_7 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4773 [F] s_b_5_0=sym_22484_3_parameter_inst.rn (const) */
    /* execute.simd:4773 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:4774 [F] s_b_5_2=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4774 [F] s_b_5_3=sym_22484_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_5_4 = (v16u8)s_b_5_3 (const) */
    auto s_b_5_4 = wutils::Vector<uint8_t, 16>(insn.shift_amount);
    /* execute.simd:4774 [D] s_b_5_5 = s_b_5_1<<s_b_5_4 */
    auto s_b_5_5 = emitter.shl(s_b_5_1, emitter.constant_vector_splat(s_b_5_4[0], emitter.context().types().v16u8()));
    /* execute.simd:4774 [D] s_b_5_6: WriteRegBank 16:s_b_5_2 = s_b_5_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5);
    /* execute.simd:0 [F] s_b_5_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4778 [F] s_b_6_0=sym_22484_3_parameter_inst.rn (const) */
    /* execute.simd:4778 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:4779 [F] s_b_6_2=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4779 [F] s_b_6_3=sym_22484_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_6_4 = (v4u16)s_b_6_3 (const) */
    auto s_b_6_4 = wutils::Vector<uint16_t, 4>(insn.shift_amount);
    /* execute.simd:4779 [D] s_b_6_5 = s_b_6_1<<s_b_6_4 */
    auto s_b_6_5 = emitter.shl(s_b_6_1, emitter.constant_vector_splat(s_b_6_4[0], emitter.context().types().v4u16()));
    /* execute.simd:4779 [D] s_b_6_6: WriteRegBank 17:s_b_6_2 = s_b_6_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_5);
    /* execute.simd:4780 [F] s_b_6_7=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4780 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:4780 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4784 [F] s_b_7_0=sym_22484_3_parameter_inst.rn (const) */
    /* execute.simd:4784 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:4785 [F] s_b_7_2=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4785 [F] s_b_7_3=sym_22484_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_7_4 = (v8u16)s_b_7_3 (const) */
    auto s_b_7_4 = wutils::Vector<uint16_t, 8>(insn.shift_amount);
    /* execute.simd:4785 [D] s_b_7_5 = s_b_7_1<<s_b_7_4 */
    auto s_b_7_5 = emitter.shl(s_b_7_1, emitter.constant_vector_splat(s_b_7_4[0], emitter.context().types().v8u16()));
    /* execute.simd:4785 [D] s_b_7_6: WriteRegBank 18:s_b_7_2 = s_b_7_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5);
    /* execute.simd:0 [F] s_b_7_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4789 [F] s_b_8_0=sym_22484_3_parameter_inst.rn (const) */
    /* execute.simd:4789 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:4790 [F] s_b_8_2=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4790 [F] s_b_8_3=sym_22484_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_8_4 = (v2u32)s_b_8_3 (const) */
    auto s_b_8_4 = wutils::Vector<uint32_t, 2>(insn.shift_amount);
    /* execute.simd:4790 [D] s_b_8_5 = s_b_8_1<<s_b_8_4 */
    auto s_b_8_5 = emitter.shl(s_b_8_1, emitter.constant_vector_splat(s_b_8_4[0], emitter.context().types().v2u32()));
    /* execute.simd:4790 [D] s_b_8_6: WriteRegBank 19:s_b_8_2 = s_b_8_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_5);
    /* execute.simd:4791 [F] s_b_8_7=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4791 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:4791 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4795 [F] s_b_9_0=sym_22484_3_parameter_inst.rn (const) */
    /* execute.simd:4795 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:4796 [F] s_b_9_2=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4796 [F] s_b_9_3=sym_22484_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_9_4 = (v4u32)s_b_9_3 (const) */
    auto s_b_9_4 = wutils::Vector<uint32_t, 4>(insn.shift_amount);
    /* execute.simd:4796 [D] s_b_9_5 = s_b_9_1<<s_b_9_4 */
    auto s_b_9_5 = emitter.shl(s_b_9_1, emitter.constant_vector_splat(s_b_9_4[0], emitter.context().types().v4u32()));
    /* execute.simd:4796 [D] s_b_9_6: WriteRegBank 20:s_b_9_2 = s_b_9_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_5,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_5);
    /* execute.simd:0 [F] s_b_9_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4800 [F] s_b_10_0=sym_22484_3_parameter_inst.rn (const) */
    /* execute.simd:4800 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:4801 [F] s_b_10_2=sym_22484_3_parameter_inst.rd (const) */
    /* execute.simd:4801 [F] s_b_10_3=sym_22484_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_10_4 = (v2u64)s_b_10_3 (const) */
    auto s_b_10_4 = wutils::Vector<uint64_t, 2>(insn.shift_amount);
    /* execute.simd:4801 [D] s_b_10_5 = s_b_10_1<<s_b_10_4 */
    auto s_b_10_5 = emitter.shl(s_b_10_1, emitter.constant_vector_splat(s_b_10_4[0], emitter.context().types().v2u64()));
    /* execute.simd:4801 [D] s_b_10_6: WriteRegBank 21:s_b_10_2 = s_b_10_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_5,emitter.const_u8(16));
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
  auto DV_sym_129007_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2368 [F] s_b_0_0=sym_24489_3_parameter_inst.rn (const) */
    /* execute.a64:2668 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2668 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_0_4 = constant s64 0 (const) */
    /* execute.a64:2668 [D] s_b_0_5 = ReadRegBank 1:s_b_0_0 (u32) */
    auto s_b_0_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_0_5,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_0_6 = (s32)s_b_0_5 */
    auto s_b_0_6 = emitter.reinterpret(s_b_0_5, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_0_7 = (s64)s_b_0_6 */
    auto s_b_0_7 = emitter.sx(s_b_0_6, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_0_8: Select s_b_0_3 ? s_b_0_4 : s_b_0_7 */
    captive::arch::dbt::el::Value *s_b_0_8;
    s_b_0_8 = (s_b_0_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_0_7);
    /* execute.a64:2369 [F] s_b_0_9=sym_24489_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [F] s_b_0_10 = (u32)s_b_0_9 (const) */
    /* execute.a64:2668 [F] s_b_0_11 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_0_12 = s_b_0_10==s_b_0_11 (const) */
    uint8_t s_b_0_12 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_0_13 = constant s64 0 (const) */
    /* execute.a64:2668 [D] s_b_0_14 = ReadRegBank 1:s_b_0_9 (u32) */
    auto s_b_0_14 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_0_14,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_0_15 = (s32)s_b_0_14 */
    auto s_b_0_15 = emitter.reinterpret(s_b_0_14, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_0_16 = (s64)s_b_0_15 */
    auto s_b_0_16 = emitter.sx(s_b_0_15, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_0_17: Select s_b_0_12 ? s_b_0_13 : s_b_0_16 */
    captive::arch::dbt::el::Value *s_b_0_17;
    s_b_0_17 = (s_b_0_12) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_0_16);
    /* execute.a64:2370 [F] s_b_0_18=sym_24489_3_parameter_inst.ra (const) */
    /* execute.a64:2666 [F] s_b_0_19 = (u32)s_b_0_18 (const) */
    /* execute.a64:2666 [F] s_b_0_20 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_0_21 = s_b_0_19==s_b_0_20 (const) */
    uint8_t s_b_0_21 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_0_22 = constant s64 0 (const) */
    /* execute.a64:2666 [D] s_b_0_23 = ReadRegBank 0:s_b_0_18 (u64) */
    auto s_b_0_23 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_0_23,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_0_24 = (s64)s_b_0_23 */
    auto s_b_0_24 = emitter.reinterpret(s_b_0_23, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_0_25: Select s_b_0_21 ? s_b_0_22 : s_b_0_24 */
    captive::arch::dbt::el::Value *s_b_0_25;
    s_b_0_25 = (s_b_0_21) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_0_24);
    /* execute.a64:2372 [D] s_b_0_26 = (s64)s_b_0_8 */
    auto s_b_0_26 = (captive::arch::dbt::el::Value *)s_b_0_8;
    /* execute.a64:2372 [D] s_b_0_27 = s_b_0_26*s_b_0_17 */
    auto s_b_0_27 = emitter.mul(s_b_0_26, s_b_0_17);
    /* execute.a64:2372 [D] s_b_0_28 = s_b_0_25-s_b_0_27 */
    auto s_b_0_28 = emitter.sub(s_b_0_25, s_b_0_27);
    /* execute.a64:2372 [D] s_b_0_29 = (u64)s_b_0_28 */
    auto s_b_0_29 = emitter.reinterpret(s_b_0_28, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_0_30=sym_24489_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_0_31: sym_129007_3_parameter_value = s_b_0_29, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_129007_3_parameter_value, s_b_0_29);
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
    /* execute.a64:2684 [F] s_b_2_0=sym_24489_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_2_1 = sym_129007_3_parameter_value uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_129007_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_2_2: WriteRegBank 0:s_b_2_0 = s_b_2_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_2_1,emitter.const_u8(8));
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
  uint8_t CV_sym_130327_3_parameter_lane;
  auto DV_sym_130210_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_130227_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_130319_3_parameter_rt;
  auto DV_sym_130324_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_130401_1_tmp_s_b_5_4;
  auto DV_sym_130404_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30122_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30128_0_rt;
  uint8_t CV_sym_30140_0_lane;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2369 [F] s_b_0_0=sym_30116_3_parameter_inst.rn (const) */
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
    /* execute.simd:2371 [F] s_b_1_0 = sym_30128_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30128_0_rt;
    /* execute.simd:2371 [F] s_b_1_1=sym_30116_3_parameter_inst.regcnt (const) */
    /* execute.simd:2371 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2371 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2372 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2372 [F] s_b_2_1: sym_30140_0_lane = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30140_0_lane = (uint8_t)0ULL;
    /* execute.simd:2372 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2372 [F] s_b_4_0 = sym_30140_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30140_0_lane;
    /* execute.simd:2372 [F] s_b_4_1=sym_30116_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2372 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2372 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2373 [F] s_b_5_0=sym_30116_3_parameter_inst.arrangement (const) */
    /* execute.simd:2373 [F] s_b_5_1=sym_30116_3_parameter_inst.rt (const) */
    /* execute.simd:2373 [F] s_b_5_2 = sym_30128_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30128_0_rt;
    /* execute.simd:2373 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2373 [F] s_b_5_4 = sym_30140_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30140_0_lane;
    /* execute.simd:2373 [D] s_b_5_5 = sym_30122_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30122_0_address, emitter.context().types().u64());
    /* execute.simd:2373 [F] s_b_5_6: sym_130319_3_parameter_rt = s_b_5_3 (const), dominates: s_b_18_0 s_b_21_0 s_b_22_0 s_b_17_0 s_b_16_0 s_b_19_0 s_b_20_0  */
    CV_sym_130319_3_parameter_rt = s_b_5_3;
    /* execute.simd:2373 [F] s_b_5_7: sym_130327_3_parameter_lane = s_b_5_4 (const), dominates: s_b_18_3 s_b_21_3 s_b_22_3 s_b_17_3 s_b_16_3 s_b_19_3 s_b_20_3  */
    CV_sym_130327_3_parameter_lane = s_b_5_4;
    /* execute.simd:2373 [D] s_b_5_8: sym_130324_3_parameter_addr = s_b_5_5, dominates: s_b_18_2 s_b_21_2 s_b_22_2 s_b_17_2 s_b_16_2 s_b_19_2 s_b_20_2  */
    emitter.store_local(DV_sym_130324_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_130401_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_23_1  */
    CV_sym_130401_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_130404_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_130404_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3774 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3779 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3784 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3789 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3794 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3799 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3804 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3773 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_15 (const) -> b_18, b_21, b_22, b_17, b_16, b_15, b_19, b_20,  */
    switch (insn.arrangement) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_21;
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
    /* execute.simd:2371 [F] s_b_6_0 = sym_30128_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30128_0_rt;
    /* execute.simd:2371 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2371 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2371 [F] s_b_6_3: sym_30128_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30128_0_rt = s_b_6_2;
    /* execute.simd:2371 [F] s_b_6_4: Jump b_1 (const) */
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
    /* execute.a64:2733 [F] s_b_8_0=sym_30116_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_130210_0_return_symbol = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_130210_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_12,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_130210_0_return_symbol uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_130210_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2369 [D] s_b_9_1: sym_30122_0_address = s_b_9_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30122_0_address, s_b_9_0);
    /* execute.simd:2371 [F] s_b_9_2 = constant u8 0 (const) */
    /* execute.simd:2371 [F] s_b_9_3: sym_30128_0_rt = s_b_9_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30128_0_rt = (uint8_t)0ULL;
    /* execute.simd:2371 [F] s_b_9_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2702 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_10_1: sym_130227_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_130227_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2731 [D] s_b_12_0 = sym_130227_1__R_s_b_3_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_130227_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1: sym_130210_0_return_symbol = s_b_12_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_130210_0_return_symbol, s_b_12_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_13_1: sym_130227_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_130227_1__R_s_b_3_0, s_b_13_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_14_1: sym_130227_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_130227_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2707 [F] s_b_14_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3810 [D] s_b_15_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_15_1: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3775 [F] s_b_16_0 = sym_130319_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_0 = CV_sym_130319_3_parameter_rt;
    /* execute.simd:3775 [D] s_b_16_1 = ReadRegBank 15:s_b_16_0 (v8u8) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:3776 [D] s_b_16_2 = sym_130324_3_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_130324_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3776 [F] s_b_16_3 = sym_130327_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_3 = CV_sym_130327_3_parameter_lane;
    /* execute.simd:3776 [D] s_b_16_1[s_b_16_3] */
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
    /* execute.simd:3780 [F] s_b_17_0 = sym_130319_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_0 = CV_sym_130319_3_parameter_rt;
    /* execute.simd:3780 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:3781 [D] s_b_17_2 = sym_130324_3_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_130324_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3781 [F] s_b_17_3 = sym_130327_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_3 = CV_sym_130327_3_parameter_lane;
    /* execute.simd:3781 [D] s_b_17_1[s_b_17_3] */
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
    /* execute.simd:3785 [F] s_b_18_0 = sym_130319_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_130319_3_parameter_rt;
    /* execute.simd:3785 [D] s_b_18_1 = ReadRegBank 17:s_b_18_0 (v4u16) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3786 [D] s_b_18_2 = sym_130324_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_130324_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3786 [F] s_b_18_3 = sym_130327_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_130327_3_parameter_lane;
    /* execute.simd:3786 [D] s_b_18_1[s_b_18_3] */
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
    /* execute.simd:3790 [F] s_b_19_0 = sym_130319_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_130319_3_parameter_rt;
    /* execute.simd:3790 [D] s_b_19_1 = ReadRegBank 18:s_b_19_0 (v8u16) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3791 [D] s_b_19_2 = sym_130324_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_130324_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3791 [F] s_b_19_3 = sym_130327_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_130327_3_parameter_lane;
    /* execute.simd:3791 [D] s_b_19_1[s_b_19_3] */
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
    /* execute.simd:3795 [F] s_b_20_0 = sym_130319_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_130319_3_parameter_rt;
    /* execute.simd:3795 [D] s_b_20_1 = ReadRegBank 19:s_b_20_0 (v2u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3796 [D] s_b_20_2 = sym_130324_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_130324_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3796 [F] s_b_20_3 = sym_130327_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_130327_3_parameter_lane;
    /* execute.simd:3796 [D] s_b_20_1[s_b_20_3] */
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
    /* execute.simd:3800 [F] s_b_21_0 = sym_130319_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_130319_3_parameter_rt;
    /* execute.simd:3800 [D] s_b_21_1 = ReadRegBank 20:s_b_21_0 (v4u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3801 [D] s_b_21_2 = sym_130324_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_130324_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3801 [F] s_b_21_3 = sym_130327_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_130327_3_parameter_lane;
    /* execute.simd:3801 [D] s_b_21_1[s_b_21_3] */
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
    /* execute.simd:3805 [F] s_b_22_0 = sym_130319_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_130319_3_parameter_rt;
    /* execute.simd:3805 [D] s_b_22_1 = ReadRegBank 21:s_b_22_0 (v2u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3806 [D] s_b_22_2 = sym_130324_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_130324_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3806 [F] s_b_22_3 = sym_130327_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_130327_3_parameter_lane;
    /* execute.simd:3806 [D] s_b_22_1[s_b_22_3] */
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
    /* ???:4294967295 [D] s_b_23_0 = sym_130404_1_tmp_s_b_5_5 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_130404_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1 = sym_130401_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_23_1 = CV_sym_130401_1_tmp_s_b_5_4;
    /* execute.simd:2374 [F] s_b_23_2=sym_30116_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* ???:4294967295 [D] s_b_23_4 = s_b_23_0+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2374 [D] s_b_23_5: sym_30122_0_address = s_b_23_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30122_0_address, s_b_23_4);
    /* execute.simd:2372 [F] s_b_23_6 = constant u8 1 (const) */
    /* execute.simd:2372 [F] s_b_23_7 = s_b_23_1+s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(s_b_23_1 + (uint8_t)1ULL));
    /* execute.simd:2372 [F] s_b_23_8: sym_30140_0_lane = s_b_23_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30140_0_lane = s_b_23_7;
    /* execute.simd:2372 [F] s_b_23_9: Jump b_4 (const) */
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
  auto DV_sym_132661_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132838_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132758_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132644_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_132753_3_parameter_rt;
  uint8_t CV_sym_132761_3_parameter_lane;
  auto DV_sym_30722_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30728_0_lane;
  uint8_t CV_sym_30740_0_rt;
  uint8_t CV_sym_132835_1_tmp_s_b_5_2;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2405 [F] s_b_0_0=sym_30716_3_parameter_inst.rn (const) */
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
    /* execute.simd:2407 [F] s_b_1_0 = sym_30728_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30728_0_lane;
    /* execute.simd:2407 [F] s_b_1_1=sym_30716_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2407 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2407 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2408 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2408 [F] s_b_2_1: sym_30740_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30740_0_rt = (uint8_t)0ULL;
    /* execute.simd:2408 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2408 [F] s_b_4_0 = sym_30740_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30740_0_rt;
    /* execute.simd:2408 [F] s_b_4_1=sym_30716_3_parameter_inst.regcnt (const) */
    /* execute.simd:2408 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2408 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2409 [F] s_b_5_0=sym_30716_3_parameter_inst.arrangement (const) */
    /* execute.simd:2409 [F] s_b_5_1=sym_30716_3_parameter_inst.rt (const) */
    /* execute.simd:2409 [F] s_b_5_2 = sym_30740_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30740_0_rt;
    /* execute.simd:2409 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2409 [F] s_b_5_4 = sym_30728_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30728_0_lane;
    /* execute.simd:2409 [D] s_b_5_5 = sym_30722_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30722_0_address, emitter.context().types().u64());
    /* execute.simd:2409 [F] s_b_5_6: sym_132753_3_parameter_rt = s_b_5_3 (const), dominates: s_b_21_0 s_b_20_0 s_b_19_0 s_b_18_0 s_b_17_0 s_b_16_0 s_b_22_0  */
    CV_sym_132753_3_parameter_rt = s_b_5_3;
    /* execute.simd:2409 [F] s_b_5_7: sym_132761_3_parameter_lane = s_b_5_4 (const), dominates: s_b_21_3 s_b_20_3 s_b_19_3 s_b_18_3 s_b_17_3 s_b_16_3 s_b_22_3  */
    CV_sym_132761_3_parameter_lane = s_b_5_4;
    /* execute.simd:2409 [D] s_b_5_8: sym_132758_3_parameter_addr = s_b_5_5, dominates: s_b_21_2 s_b_20_2 s_b_19_2 s_b_18_2 s_b_17_2 s_b_16_2 s_b_22_2  */
    emitter.store_local(DV_sym_132758_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_132835_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_23_1  */
    CV_sym_132835_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_132838_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_132838_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3774 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3779 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3784 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3789 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3794 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3799 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3804 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3773 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_15 (const) -> b_21, b_20, b_19, b_18, b_17, b_16, b_15, b_22,  */
    switch (insn.arrangement) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_19;
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
    case (int32_t)0ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_17;
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
    /* execute.simd:2407 [F] s_b_6_0 = sym_30728_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30728_0_lane;
    /* execute.simd:2407 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2407 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2407 [F] s_b_6_3: sym_30728_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30728_0_lane = s_b_6_2;
    /* execute.simd:2407 [F] s_b_6_4: Jump b_1 (const) */
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
    /* execute.a64:2733 [F] s_b_8_0=sym_30716_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_132644_0_return_symbol = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_132644_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_12,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_132644_0_return_symbol uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_132644_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2405 [D] s_b_9_1: sym_30722_0_address = s_b_9_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30722_0_address, s_b_9_0);
    /* execute.simd:2407 [F] s_b_9_2 = constant u8 0 (const) */
    /* execute.simd:2407 [F] s_b_9_3: sym_30728_0_lane = s_b_9_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30728_0_lane = (uint8_t)0ULL;
    /* execute.simd:2407 [F] s_b_9_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2702 [D] s_b_10_0 = ReadReg 20 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_10_1: sym_132661_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_132661_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2731 [D] s_b_12_0 = sym_132661_1__R_s_b_3_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_132661_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1: sym_132644_0_return_symbol = s_b_12_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_132644_0_return_symbol, s_b_12_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_13_1: sym_132661_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_132661_1__R_s_b_3_0, s_b_13_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_14_1: sym_132661_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_132661_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2707 [F] s_b_14_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3810 [D] s_b_15_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_15_1: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3775 [F] s_b_16_0 = sym_132753_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_0 = CV_sym_132753_3_parameter_rt;
    /* execute.simd:3775 [D] s_b_16_1 = ReadRegBank 15:s_b_16_0 (v8u8) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:3776 [D] s_b_16_2 = sym_132758_3_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_132758_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3776 [F] s_b_16_3 = sym_132761_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_3 = CV_sym_132761_3_parameter_lane;
    /* execute.simd:3776 [D] s_b_16_1[s_b_16_3] */
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
    /* execute.simd:3780 [F] s_b_17_0 = sym_132753_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_0 = CV_sym_132753_3_parameter_rt;
    /* execute.simd:3780 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:3781 [D] s_b_17_2 = sym_132758_3_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_132758_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3781 [F] s_b_17_3 = sym_132761_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_3 = CV_sym_132761_3_parameter_lane;
    /* execute.simd:3781 [D] s_b_17_1[s_b_17_3] */
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
    /* execute.simd:3785 [F] s_b_18_0 = sym_132753_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_132753_3_parameter_rt;
    /* execute.simd:3785 [D] s_b_18_1 = ReadRegBank 17:s_b_18_0 (v4u16) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3786 [D] s_b_18_2 = sym_132758_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_132758_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3786 [F] s_b_18_3 = sym_132761_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_132761_3_parameter_lane;
    /* execute.simd:3786 [D] s_b_18_1[s_b_18_3] */
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
    /* execute.simd:3790 [F] s_b_19_0 = sym_132753_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_132753_3_parameter_rt;
    /* execute.simd:3790 [D] s_b_19_1 = ReadRegBank 18:s_b_19_0 (v8u16) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3791 [D] s_b_19_2 = sym_132758_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_132758_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3791 [F] s_b_19_3 = sym_132761_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_132761_3_parameter_lane;
    /* execute.simd:3791 [D] s_b_19_1[s_b_19_3] */
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
    /* execute.simd:3795 [F] s_b_20_0 = sym_132753_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_132753_3_parameter_rt;
    /* execute.simd:3795 [D] s_b_20_1 = ReadRegBank 19:s_b_20_0 (v2u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3796 [D] s_b_20_2 = sym_132758_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_132758_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3796 [F] s_b_20_3 = sym_132761_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_132761_3_parameter_lane;
    /* execute.simd:3796 [D] s_b_20_1[s_b_20_3] */
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
    /* execute.simd:3800 [F] s_b_21_0 = sym_132753_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_132753_3_parameter_rt;
    /* execute.simd:3800 [D] s_b_21_1 = ReadRegBank 20:s_b_21_0 (v4u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3801 [D] s_b_21_2 = sym_132758_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_132758_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3801 [F] s_b_21_3 = sym_132761_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_132761_3_parameter_lane;
    /* execute.simd:3801 [D] s_b_21_1[s_b_21_3] */
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
    /* execute.simd:3805 [F] s_b_22_0 = sym_132753_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_132753_3_parameter_rt;
    /* execute.simd:3805 [D] s_b_22_1 = ReadRegBank 21:s_b_22_0 (v2u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3806 [D] s_b_22_2 = sym_132758_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_132758_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3806 [F] s_b_22_3 = sym_132761_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_132761_3_parameter_lane;
    /* execute.simd:3806 [D] s_b_22_1[s_b_22_3] */
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
    /* ???:4294967295 [D] s_b_23_0 = sym_132838_1_tmp_s_b_5_5 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_132838_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1 = sym_132835_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_23_1 = CV_sym_132835_1_tmp_s_b_5_2;
    /* execute.simd:2410 [F] s_b_23_2=sym_30716_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* ???:4294967295 [D] s_b_23_4 = s_b_23_0+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2410 [D] s_b_23_5: sym_30722_0_address = s_b_23_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30722_0_address, s_b_23_4);
    /* execute.simd:2408 [F] s_b_23_6 = constant u8 1 (const) */
    /* execute.simd:2408 [F] s_b_23_7 = s_b_23_1+s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(s_b_23_1 + (uint8_t)1ULL));
    /* execute.simd:2408 [F] s_b_23_8: sym_30740_0_rt = s_b_23_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30740_0_rt = s_b_23_7;
    /* execute.simd:2408 [F] s_b_23_9: Jump b_4 (const) */
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
  auto DV_sym_135487_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31139_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_135470_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:669 [F] s_b_0_0=sym_31133_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_5_0=sym_31133_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_135470_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_135470_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_135470_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_135470_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:669 [D] s_b_6_1: sym_31139_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_31139_0_address, s_b_6_0);
    /* execute.a64:671 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:671 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:671 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_7_1: sym_135487_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135487_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2731 [D] s_b_9_0 = sym_135487_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_135487_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_135470_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_135470_0_return_symbol, s_b_9_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_10_1: sym_135487_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135487_1__R_s_b_3_0, s_b_10_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_11_1: sym_135487_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135487_1__R_s_b_3_0, s_b_11_0);
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
        /* execute.a64:672 [D] s_b_1_0 = sym_31139_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_31139_0_address, emitter.context().types().u64());
        /* execute.a64:672 [F] s_b_1_1=sym_31133_3_parameter_inst.rt (const) */
        /* execute.a64:2646 [F] s_b_1_2 = (u32)s_b_1_1 (const) */
        /* execute.a64:2646 [F] s_b_1_3 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_1_4 = s_b_1_2==s_b_1_3 (const) */
        uint8_t s_b_1_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_1_5 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_1_6 = ReadRegBank 1:s_b_1_1 (u32) */
        auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_1_6,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_1_7: Select s_b_1_4 ? s_b_1_5 : s_b_1_6 */
        captive::arch::dbt::el::Value *s_b_1_7;
        s_b_1_7 = (s_b_1_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_6);
        /* execute.a64:2659 [D] s_b_1_8 = (u64)s_b_1_7 */
        auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
        /* execute.a64:1787 [D] s_b_1_9 = (u16)s_b_1_8 */
        auto s_b_1_9 = emitter.truncate(s_b_1_8, emitter.context().types().u16());
        /* ???:4294967295 [D] s_b_1_10: Store 2 s_b_1_0 <= s_b_1_9 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_1_0, s_b_1_9, emitter.const_u8(2));
        }
        emitter.store_memory(s_b_1_0, s_b_1_9);
        /* execute.a64:673 [F] s_b_1_11=sym_31133_3_parameter_inst.rs (const) */
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
        /* execute.a64:675 [F] s_b_3_0=sym_31133_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_12_0=sym_31133_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_12_1 = constant u64 1 (const) */
        /* execute.a64:2676 [F] s_b_12_2: WriteRegBank 0:s_b_12_0 = s_b_12_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
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
        /* execute.a64:2676 [F] s_b_13_0=sym_31133_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_13_1 = constant u64 0 (const) */
        /* execute.a64:2676 [F] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
  auto DV_sym_139418_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_31843_0_shift;
  uint64_t CV_sym_31870_0_rm;
  auto DV_sym_31870_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31968_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_139401_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3910 [F] s_b_0_0=sym_31825_3_parameter_inst.S (const) */
    /* execute.simd:3910 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:3910 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:3910 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.S) == (uint32_t)0ULL));
    /* execute.simd:3910 [F] s_b_0_4 = constant u8 0 (const) */
    /* execute.simd:3910 [F] s_b_0_5=sym_31825_3_parameter_inst.X (const) */
    /* execute.simd:3910 [F] s_b_0_6 = (u32)s_b_0_5 (const) */
    /* execute.simd:3910 [F] s_b_0_7 = constant u32 1 (const) */
    /* execute.simd:3910 [F] s_b_0_8 = s_b_0_6==s_b_0_7 (const) */
    uint8_t s_b_0_8 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* execute.simd:3910 [F] s_b_0_9 = constant u8 4 (const) */
    /* execute.simd:3910 [F] s_b_0_10=sym_31825_3_parameter_inst.size (const) */
    /* execute.simd:3910 [F] s_b_0_11 = (u8)s_b_0_10 (const) */
    /* execute.simd:3910 [F] s_b_0_12: Select s_b_0_8 ? s_b_0_9 : s_b_0_11 (const) */
    uint8_t s_b_0_12 = ((uint8_t)(s_b_0_8 ? ((uint8_t)4ULL) : (((uint8_t)insn.size))));
    /* execute.simd:3910 [F] s_b_0_13: Select s_b_0_3 ? s_b_0_4 : s_b_0_12 (const) */
    uint8_t s_b_0_13 = ((uint8_t)(s_b_0_3 ? ((uint8_t)0ULL) : (s_b_0_12)));
    /* execute.simd:3910 [F] s_b_0_14: sym_31843_0_shift = s_b_0_13 (const), dominates: s_b_1_1 s_b_4_1 s_b_6_1 s_b_8_1  */
    CV_sym_31843_0_shift = s_b_0_13;
    /* execute.simd:3913 [F] s_b_0_15=sym_31825_3_parameter_inst.option0 (const) */
    /* execute.simd:3913 [F] s_b_0_16 = (u32)s_b_0_15 (const) */
    /* execute.simd:3913 [F] s_b_0_17 = constant u32 0 (const) */
    /* execute.simd:3913 [F] s_b_0_18 = s_b_0_16==s_b_0_17 (const) */
    uint8_t s_b_0_18 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.simd:3913 [F] s_b_0_19=sym_31825_3_parameter_inst.option21 (const) */
    /* execute.simd:3913 [F] s_b_0_20 = (u32)s_b_0_19 (const) */
    /* execute.simd:3913 [F] s_b_0_21 = constant u32 1 (const) */
    /* execute.simd:3913 [F] s_b_0_22 = s_b_0_20==s_b_0_21 (const) */
    uint8_t s_b_0_22 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_23 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_24 = s_b_0_18!=s_b_0_23 (const) */
    uint8_t s_b_0_24 = ((uint8_t)(s_b_0_18 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_25 = s_b_0_22!=s_b_0_23 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(s_b_0_22 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_26 = s_b_0_24&s_b_0_25 (const) */
    uint8_t s_b_0_26 = ((uint8_t)(s_b_0_24 & s_b_0_25));
    /* execute.simd:3913 [F] s_b_0_27: If s_b_0_26: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3914 [F] s_b_1_0=sym_31825_3_parameter_inst.rm (const) */
    /* execute.simd:3914 [F] s_b_1_1 = sym_31843_0_shift (const) uint8_t */
    uint8_t s_b_1_1 = CV_sym_31843_0_shift;
    /* execute.a64:2646 [F] s_b_1_2 = (u32)s_b_1_0 (const) */
    /* execute.a64:2646 [F] s_b_1_3 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_4 = s_b_1_2==s_b_1_3 (const) */
    uint8_t s_b_1_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_5 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_6 = ReadRegBank 1:s_b_1_0 (u32) */
    auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_1_6,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_7: Select s_b_1_4 ? s_b_1_5 : s_b_1_6 */
    captive::arch::dbt::el::Value *s_b_1_7;
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
    /* execute.simd:3914 [D] s_b_1_13: sym_31870_0_rm = s_b_1_12, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_31870_0_rm, s_b_1_12);
    /* execute.simd:3914 [F] s_b_1_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_8, b_9,  */
  fixed_block_b_2: 
  {
    /* execute.simd:3926 [F] s_b_2_0=sym_31825_3_parameter_inst.rn (const) */
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
    /* execute.simd:3915 [F] s_b_3_0=sym_31825_3_parameter_inst.option0 (const) */
    /* execute.simd:3915 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:3915 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:3915 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.simd:3915 [F] s_b_3_4=sym_31825_3_parameter_inst.option21 (const) */
    /* execute.simd:3915 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:3915 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.simd:3915 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:3915 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.simd:3916 [F] s_b_4_0=sym_31825_3_parameter_inst.rm (const) */
    /* execute.simd:3916 [F] s_b_4_1 = sym_31843_0_shift (const) uint8_t */
    uint8_t s_b_4_1 = CV_sym_31843_0_shift;
    /* execute.a64:2646 [F] s_b_4_2 = (u32)s_b_4_0 (const) */
    /* execute.a64:2646 [F] s_b_4_3 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_4_4 = s_b_4_2==s_b_4_3 (const) */
    uint8_t s_b_4_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_4_5 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_4_6 = ReadRegBank 1:s_b_4_0 (u32) */
    auto s_b_4_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_4_6,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_4_7: Select s_b_4_4 ? s_b_4_5 : s_b_4_6 */
    captive::arch::dbt::el::Value *s_b_4_7;
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
    /* execute.simd:3916 [D] s_b_4_14: sym_31870_0_rm = s_b_4_13, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_31870_0_rm, s_b_4_13);
    /* execute.simd:3916 [F] s_b_4_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:3917 [F] s_b_5_0=sym_31825_3_parameter_inst.option0 (const) */
    /* execute.simd:3917 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:3917 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:3917 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.simd:3917 [F] s_b_5_4=sym_31825_3_parameter_inst.option21 (const) */
    /* execute.simd:3917 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:3917 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.simd:3917 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.simd:3917 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.simd:3918 [F] s_b_6_0=sym_31825_3_parameter_inst.rm (const) */
    /* execute.simd:3918 [F] s_b_6_1 = sym_31843_0_shift (const) uint8_t */
    uint8_t s_b_6_1 = CV_sym_31843_0_shift;
    /* execute.a64:2651 [F] s_b_6_2 = (u32)s_b_6_0 (const) */
    /* execute.a64:2651 [F] s_b_6_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_6_4 = s_b_6_2==s_b_6_3 (const) */
    uint8_t s_b_6_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_6_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_6_6 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_6_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_6_7: Select s_b_6_4 ? s_b_6_5 : s_b_6_6 */
    captive::arch::dbt::el::Value *s_b_6_7;
    s_b_6_7 = (s_b_6_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_6_6);
    /* execute.a64:2620 [F] s_b_6_8 = (u64)s_b_6_1 (const) */
    /* execute.a64:2620 [D] s_b_6_9 = s_b_6_7<<s_b_6_8 */
    auto s_b_6_9 = emitter.shl(s_b_6_7, emitter.const_u64(((uint64_t)s_b_6_1)));
    /* execute.simd:3918 [D] s_b_6_10: sym_31870_0_rm = s_b_6_9, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_31870_0_rm, s_b_6_9);
    /* execute.simd:3918 [F] s_b_6_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:3919 [F] s_b_7_0=sym_31825_3_parameter_inst.option0 (const) */
    /* execute.simd:3919 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:3919 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.simd:3919 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.simd:3919 [F] s_b_7_4=sym_31825_3_parameter_inst.option21 (const) */
    /* execute.simd:3919 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:3919 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.simd:3919 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:3919 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.simd:3920 [F] s_b_8_0=sym_31825_3_parameter_inst.rm (const) */
    /* execute.simd:3920 [F] s_b_8_1 = sym_31843_0_shift (const) uint8_t */
    uint8_t s_b_8_1 = CV_sym_31843_0_shift;
    /* execute.a64:2651 [F] s_b_8_2 = (u32)s_b_8_0 (const) */
    /* execute.a64:2651 [F] s_b_8_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_8_4 = s_b_8_2==s_b_8_3 (const) */
    uint8_t s_b_8_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_8_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_8_6 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_8_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_8_7: Select s_b_8_4 ? s_b_8_5 : s_b_8_6 */
    captive::arch::dbt::el::Value *s_b_8_7;
    s_b_8_7 = (s_b_8_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_8_6);
    /* execute.a64:2636 [F] s_b_8_8 = (u64)s_b_8_1 (const) */
    /* execute.a64:2636 [D] s_b_8_9 = s_b_8_7<<s_b_8_8 */
    auto s_b_8_9 = emitter.shl(s_b_8_7, emitter.const_u64(((uint64_t)s_b_8_1)));
    /* execute.simd:3920 [D] s_b_8_10: sym_31870_0_rm = s_b_8_9, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_31870_0_rm, s_b_8_9);
    /* execute.simd:3920 [F] s_b_8_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3922 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.simd:3922 [F] s_b_9_1: sym_31870_0_rm = s_b_9_0 (const), dominates: s_b_22_1  */
    CV_sym_31870_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_31870_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:3923 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:3922 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_22,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3929 [F] s_b_10_0=sym_31825_3_parameter_inst.X (const) */
    /* execute.simd:3929 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:3929 [F] s_b_10_2 = constant u32 1 (const) */
    /* execute.simd:3929 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* execute.simd:3929 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
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
    /* execute.simd:3936 [F] s_b_12_0=sym_31825_3_parameter_inst.size (const) */
    /* execute.simd:3936 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.simd:3936 [F] s_b_12_2 = constant u32 1 (const) */
    /* execute.simd:3936 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:3936 [F] s_b_12_4: If s_b_12_3: Jump b_15 else b_16 (const) */
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
    /* execute.simd:3931 [F] s_b_13_0=sym_31825_3_parameter_inst.rt (const) */
    /* execute.simd:3931 [D] s_b_13_1 = sym_31968_0_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_31968_0_address, emitter.context().types().u64());
    /* execute.simd:6172 [D] s_b_13_2 = ReadRegBank 2:s_b_13_0 (u64) */
    auto s_b_13_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_2,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_13_3 = ReadRegBank 3:s_b_13_0 (u64) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_13_4: Store 8 s_b_13_1 <= s_b_13_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_13_1, s_b_13_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_13_1, s_b_13_2);
    /* execute.simd:3596 [F] s_b_13_5 = constant u64 8 (const) */
    /* execute.simd:3596 [D] s_b_13_6 = s_b_13_1+s_b_13_5 */
    auto s_b_13_6 = emitter.add(s_b_13_1, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_13_7: Store 8 s_b_13_6 <= s_b_13_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_13_6, s_b_13_3, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_13_6, s_b_13_3);
    /* execute.simd:0 [F] s_b_13_8: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.simd:3934 [F] s_b_14_0=sym_31825_3_parameter_inst.rt (const) */
    /* execute.simd:3934 [D] s_b_14_1 = sym_31968_0_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_31968_0_address, emitter.context().types().u64());
    /* execute.simd:6152 [D] s_b_14_2 = ReadRegBank 4:s_b_14_0 (u8) */
    auto s_b_14_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_2,emitter.const_u8(1));
    }
    /* ???:4294967295 [D] s_b_14_3: Store 1 s_b_14_1 <= s_b_14_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_14_1, s_b_14_2, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_14_1, s_b_14_2);
    /* execute.simd:0 [F] s_b_14_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_12,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3938 [F] s_b_15_0=sym_31825_3_parameter_inst.rt (const) */
    /* execute.simd:3938 [D] s_b_15_1 = sym_31968_0_address uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_31968_0_address, emitter.context().types().u64());
    /* execute.simd:6157 [D] s_b_15_2 = ReadRegBank 5:s_b_15_0 (u16) */
    auto s_b_15_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_15_2,emitter.const_u8(2));
    }
    /* ???:4294967295 [D] s_b_15_3: Store 2 s_b_15_1 <= s_b_15_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_15_1, s_b_15_2, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_15_1, s_b_15_2);
    /* execute.simd:0 [F] s_b_15_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_12,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3939 [F] s_b_16_0=sym_31825_3_parameter_inst.size (const) */
    /* execute.simd:3939 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.simd:3939 [F] s_b_16_2 = constant u32 2 (const) */
    /* execute.simd:3939 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:3939 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
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
    /* execute.simd:3941 [F] s_b_17_0=sym_31825_3_parameter_inst.rt (const) */
    /* execute.simd:3941 [D] s_b_17_1 = sym_31968_0_address uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_31968_0_address, emitter.context().types().u64());
    /* execute.simd:6162 [D] s_b_17_2 = ReadRegBank 6:s_b_17_0 (u32) */
    auto s_b_17_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_17_2,emitter.const_u8(4));
    }
    /* ???:4294967295 [D] s_b_17_3: Store 4 s_b_17_1 <= s_b_17_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_17_1, s_b_17_2, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_17_1, s_b_17_2);
    /* execute.simd:0 [F] s_b_17_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3942 [F] s_b_18_0=sym_31825_3_parameter_inst.size (const) */
    /* execute.simd:3942 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
    /* execute.simd:3942 [F] s_b_18_2 = constant u32 3 (const) */
    /* execute.simd:3942 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:3942 [F] s_b_18_4: If s_b_18_3: Jump b_19 else b_11 (const) */
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
    /* execute.simd:3944 [F] s_b_19_0=sym_31825_3_parameter_inst.rt (const) */
    /* execute.simd:3944 [D] s_b_19_1 = sym_31968_0_address uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_31968_0_address, emitter.context().types().u64());
    /* execute.simd:6167 [D] s_b_19_2 = ReadRegBank 7:s_b_19_0 (u64) */
    auto s_b_19_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_19_2,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_19_3: Store 8 s_b_19_1 <= s_b_19_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_19_1, s_b_19_2, emitter.const_u8(8));
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
    /* execute.a64:2733 [F] s_b_21_0=sym_31825_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_21_2: sym_139401_0_return_symbol = s_b_21_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_139401_0_return_symbol, s_b_21_1);
    /* ???:4294967295 [F] s_b_21_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_21, b_25,  */
  fixed_block_b_22: 
  {
    /* ???:4294967295 [D] s_b_22_0 = sym_139401_0_return_symbol uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_139401_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:3926 [D] s_b_22_1 = sym_31870_0_rm uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_31870_0_rm, emitter.context().types().u64());
    /* execute.simd:3926 [D] s_b_22_2 = s_b_22_0+s_b_22_1 */
    auto s_b_22_2 = emitter.add(s_b_22_0, s_b_22_1);
    /* execute.simd:3926 [D] s_b_22_3: sym_31968_0_address = s_b_22_2, dominates: s_b_13_1 s_b_14_1 s_b_15_1 s_b_17_1 s_b_19_1  */
    emitter.store_local(DV_sym_31968_0_address, s_b_22_2);
    /* execute.simd:3928 [F] s_b_22_4=sym_31825_3_parameter_inst.size (const) */
    /* execute.simd:3928 [F] s_b_22_5 = (u32)s_b_22_4 (const) */
    /* execute.simd:3928 [F] s_b_22_6 = constant u32 0 (const) */
    /* execute.simd:3928 [F] s_b_22_7 = s_b_22_5==s_b_22_6 (const) */
    uint8_t s_b_22_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:3928 [F] s_b_22_8: If s_b_22_7: Jump b_10 else b_12 (const) */
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_23_1: sym_139418_1__R_s_b_3_0 = s_b_23_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_139418_1__R_s_b_3_0, s_b_23_0);
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
    /* execute.a64:2731 [D] s_b_25_0 = sym_139418_1__R_s_b_3_0 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_139418_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_25_1: sym_139401_0_return_symbol = s_b_25_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_139401_0_return_symbol, s_b_25_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_26_1: sym_139418_1__R_s_b_3_0 = s_b_26_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_139418_1__R_s_b_3_0, s_b_26_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_27_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_27_1: sym_139418_1__R_s_b_3_0 = s_b_27_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_139418_1__R_s_b_3_0, s_b_27_0);
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
  auto DV_sym_32783_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_144375_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_144392_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:609 [F] s_b_0_0=sym_32777_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_5_0=sym_32777_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_144375_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_144375_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_144375_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_144375_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:609 [D] s_b_6_1: sym_32783_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_32783_0_address, s_b_6_0);
    /* execute.a64:611 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:611 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:611 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_7_1: sym_144392_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144392_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2731 [D] s_b_9_0 = sym_144392_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_144392_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_144375_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_144375_0_return_symbol, s_b_9_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_10_1: sym_144392_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144392_1__R_s_b_3_0, s_b_10_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_11_1: sym_144392_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_144392_1__R_s_b_3_0, s_b_11_0);
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
        /* execute.a64:612 [D] s_b_1_0 = sym_32783_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_32783_0_address, emitter.context().types().u64());
        /* execute.a64:612 [F] s_b_1_1=sym_32777_3_parameter_inst.rt (const) */
        /* execute.a64:2646 [F] s_b_1_2 = (u32)s_b_1_1 (const) */
        /* execute.a64:2646 [F] s_b_1_3 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_1_4 = s_b_1_2==s_b_1_3 (const) */
        uint8_t s_b_1_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_1_5 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_1_6 = ReadRegBank 1:s_b_1_1 (u32) */
        auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_1_6,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_1_7: Select s_b_1_4 ? s_b_1_5 : s_b_1_6 */
        captive::arch::dbt::el::Value *s_b_1_7;
        s_b_1_7 = (s_b_1_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_6);
        /* execute.a64:2659 [D] s_b_1_8 = (u64)s_b_1_7 */
        auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
        /* execute.a64:1782 [D] s_b_1_9 = (u8)s_b_1_8 */
        auto s_b_1_9 = emitter.truncate(s_b_1_8, emitter.context().types().u8());
        /* ???:4294967295 [D] s_b_1_10: Store 1 s_b_1_0 <= s_b_1_9 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_1_0, s_b_1_9, emitter.const_u8(1));
        }
        emitter.store_memory(s_b_1_0, s_b_1_9);
        /* execute.a64:613 [F] s_b_1_11=sym_32777_3_parameter_inst.rs (const) */
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
        /* execute.a64:615 [F] s_b_3_0=sym_32777_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_12_0=sym_32777_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_12_1 = constant u64 1 (const) */
        /* execute.a64:2676 [F] s_b_12_2: WriteRegBank 0:s_b_12_0 = s_b_12_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
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
        /* execute.a64:2676 [F] s_b_13_0=sym_32777_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_13_1 = constant u64 0 (const) */
        /* execute.a64:2676 [F] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
  auto DV_sym_34875_0_rm = emitter.alloc_local(emitter.context().types().u8(), true);
  auto DV_sym_35260_0_rm = emitter.alloc_local(emitter.context().types().u8(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3676 [F] s_b_0_0=sym_34852_3_parameter_inst.Q (const) */
    /* execute.simd:3676 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:3676 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:3676 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:3676 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3678 [F] s_b_1_0=sym_34852_3_parameter_inst.rm (const) */
    /* execute.simd:3678 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:3678 [F] s_b_1_2 = constant u32 10 (const) */
    /* execute.simd:3678 [F] s_b_1_3 = s_b_1_1*s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
    /* execute.simd:3678 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.simd:3678 [F] s_b_1_5 = s_b_1_3+s_b_1_4 (const) */
    uint32_t s_b_1_5 = ((uint32_t)(s_b_1_3 + (uint32_t)0ULL));
    /* execute.simd:3678 [D] s_b_1_6 = ReadRegBank 23:s_b_1_5 (u8) */
    auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_1_5))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_1_5))),s_b_1_6,emitter.const_u8(1));
    }
    /* execute.simd:3678 [D] s_b_1_7: sym_34875_0_rm = s_b_1_6, dominates: s_b_4_10  */
    emitter.store_local(DV_sym_34875_0_rm, s_b_1_6);
    /* execute.simd:3680 [F] s_b_1_8=sym_34852_3_parameter_inst.len (const) */
    /* execute.simd:3680 [F] s_b_1_9 = (u32)s_b_1_8 (const) */
    /* execute.simd:3680 [F] s_b_1_10 = constant u32 1 (const) */
    /* execute.simd:3680 [F] s_b_1_11 = s_b_1_9+s_b_1_10 (const) */
    uint32_t s_b_1_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
    /* execute.simd:3680 [F] s_b_1_12 = constant u32 10 (const) */
    /* execute.simd:3680 [F] s_b_1_13 = s_b_1_12*s_b_1_11 (const) */
    uint32_t s_b_1_13 = ((uint32_t)((uint32_t)16ULL * s_b_1_11));
    /* execute.simd:3680 [D] s_b_1_14 = (u32)s_b_1_6 */
    auto s_b_1_14 = emitter.zx(s_b_1_6, emitter.context().types().u32());
    /* execute.simd:3680 [D] s_b_1_15 = s_b_1_14<s_b_1_13 */
    auto s_b_1_15 = emitter.cmp_lt(s_b_1_14, emitter.const_u32(s_b_1_13));
    /* execute.simd:3680 [D] s_b_1_16: If s_b_1_15: Jump b_4 else b_5 */
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
      emitter.branch(s_b_1_15, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:3688 [F] s_b_3_0=sym_34852_3_parameter_inst.rm (const) */
    /* execute.simd:3688 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:3688 [F] s_b_3_2 = constant u32 10 (const) */
    /* execute.simd:3688 [F] s_b_3_3 = s_b_3_1*s_b_3_2 (const) */
    uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
    /* execute.simd:3688 [F] s_b_3_4 = constant u32 0 (const) */
    /* execute.simd:3688 [F] s_b_3_5 = s_b_3_3+s_b_3_4 (const) */
    uint32_t s_b_3_5 = ((uint32_t)(s_b_3_3 + (uint32_t)0ULL));
    /* execute.simd:3688 [D] s_b_3_6 = ReadRegBank 23:s_b_3_5 (u8) */
    auto s_b_3_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_3_5))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_3_5))),s_b_3_6,emitter.const_u8(1));
    }
    /* execute.simd:3688 [D] s_b_3_7: sym_35260_0_rm = s_b_3_6, dominates: s_b_20_10  */
    emitter.store_local(DV_sym_35260_0_rm, s_b_3_6);
    /* execute.simd:3690 [F] s_b_3_8=sym_34852_3_parameter_inst.len (const) */
    /* execute.simd:3690 [F] s_b_3_9 = (u32)s_b_3_8 (const) */
    /* execute.simd:3690 [F] s_b_3_10 = constant u32 1 (const) */
    /* execute.simd:3690 [F] s_b_3_11 = s_b_3_9+s_b_3_10 (const) */
    uint32_t s_b_3_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
    /* execute.simd:3690 [F] s_b_3_12 = constant u32 10 (const) */
    /* execute.simd:3690 [F] s_b_3_13 = s_b_3_12*s_b_3_11 (const) */
    uint32_t s_b_3_13 = ((uint32_t)((uint32_t)16ULL * s_b_3_11));
    /* execute.simd:3690 [D] s_b_3_14 = (u32)s_b_3_6 */
    auto s_b_3_14 = emitter.zx(s_b_3_6, emitter.context().types().u32());
    /* execute.simd:3690 [D] s_b_3_15 = s_b_3_14<s_b_3_13 */
    auto s_b_3_15 = emitter.cmp_lt(s_b_3_14, emitter.const_u32(s_b_3_13));
    /* execute.simd:3690 [D] s_b_3_16: If s_b_3_15: Jump b_20 else b_21 */
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
        /* execute.simd:3681 [F] s_b_4_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3681 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
        /* execute.simd:3681 [F] s_b_4_2 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_4_3 = s_b_4_1*s_b_4_2 (const) */
        uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3681 [F] s_b_4_4 = constant u32 0 (const) */
        /* execute.simd:3681 [F] s_b_4_5 = s_b_4_3+s_b_4_4 (const) */
        uint32_t s_b_4_5 = ((uint32_t)(s_b_4_3 + (uint32_t)0ULL));
        /* execute.simd:3681 [F] s_b_4_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3681 [F] s_b_4_7 = (u32)s_b_4_6 (const) */
        /* execute.simd:3681 [F] s_b_4_8 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_4_9 = s_b_4_7*s_b_4_8 (const) */
        uint32_t s_b_4_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3681 [D] s_b_4_10 = sym_34875_0_rm uint8_t */
        auto s_b_4_10 = emitter.load_local(DV_sym_34875_0_rm, emitter.context().types().u8());
        /* execute.simd:3681 [D] s_b_4_11 = (u32)s_b_4_10 */
        auto s_b_4_11 = emitter.zx(s_b_4_10, emitter.context().types().u32());
        /* execute.simd:3681 [D] s_b_4_12 = s_b_4_9+s_b_4_11 */
        auto s_b_4_12 = emitter.add(emitter.const_u32(s_b_4_9), s_b_4_11);
        /* execute.simd:3681 [D] s_b_4_13 = ReadRegBank 23:s_b_4_12 (u8) */
        captive::arch::dbt::el::Value *s_b_4_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_4_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_4_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3681 [D] s_b_4_14: WriteRegBank 23:s_b_4_5 = s_b_4_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_4_5))),s_b_4_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_4_5))),s_b_4_13);
        /* execute.simd:3681 [F] s_b_4_15: Jump b_5 (const) */
        {
          auto block = block_b_5;
          dynamic_block_queue.push(block_b_5);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:3678 [F] s_b_5_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3678 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
        /* execute.simd:3678 [F] s_b_5_2 = constant u32 10 (const) */
        /* execute.simd:3678 [F] s_b_5_3 = s_b_5_1*s_b_5_2 (const) */
        uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3678 [F] s_b_5_4 = constant u32 1 (const) */
        /* execute.simd:3678 [F] s_b_5_5 = s_b_5_3+s_b_5_4 (const) */
        uint32_t s_b_5_5 = ((uint32_t)(s_b_5_3 + (uint32_t)1ULL));
        /* execute.simd:3678 [D] s_b_5_6 = ReadRegBank 23:s_b_5_5 (u8) */
        auto s_b_5_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_5_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_5_5))),s_b_5_6,emitter.const_u8(1));
        }
        /* execute.simd:3678 [D] s_b_5_7: sym_34875_0_rm = s_b_5_6, dominates: s_b_6_10  */
        emitter.store_local(DV_sym_34875_0_rm, s_b_5_6);
        /* execute.simd:3680 [F] s_b_5_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3680 [F] s_b_5_9 = (u32)s_b_5_8 (const) */
        /* execute.simd:3680 [F] s_b_5_10 = constant u32 1 (const) */
        /* execute.simd:3680 [F] s_b_5_11 = s_b_5_9+s_b_5_10 (const) */
        uint32_t s_b_5_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3680 [F] s_b_5_12 = constant u32 10 (const) */
        /* execute.simd:3680 [F] s_b_5_13 = s_b_5_12*s_b_5_11 (const) */
        uint32_t s_b_5_13 = ((uint32_t)((uint32_t)16ULL * s_b_5_11));
        /* execute.simd:3680 [D] s_b_5_14 = (u32)s_b_5_6 */
        auto s_b_5_14 = emitter.zx(s_b_5_6, emitter.context().types().u32());
        /* execute.simd:3680 [D] s_b_5_15 = s_b_5_14<s_b_5_13 */
        auto s_b_5_15 = emitter.cmp_lt(s_b_5_14, emitter.const_u32(s_b_5_13));
        /* execute.simd:3680 [D] s_b_5_16: If s_b_5_15: Jump b_6 else b_7 */
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
          emitter.branch(s_b_5_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:3681 [F] s_b_6_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3681 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
        /* execute.simd:3681 [F] s_b_6_2 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_6_3 = s_b_6_1*s_b_6_2 (const) */
        uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3681 [F] s_b_6_4 = constant u32 1 (const) */
        /* execute.simd:3681 [F] s_b_6_5 = s_b_6_3+s_b_6_4 (const) */
        uint32_t s_b_6_5 = ((uint32_t)(s_b_6_3 + (uint32_t)1ULL));
        /* execute.simd:3681 [F] s_b_6_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3681 [F] s_b_6_7 = (u32)s_b_6_6 (const) */
        /* execute.simd:3681 [F] s_b_6_8 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_6_9 = s_b_6_7*s_b_6_8 (const) */
        uint32_t s_b_6_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3681 [D] s_b_6_10 = sym_34875_0_rm uint8_t */
        auto s_b_6_10 = emitter.load_local(DV_sym_34875_0_rm, emitter.context().types().u8());
        /* execute.simd:3681 [D] s_b_6_11 = (u32)s_b_6_10 */
        auto s_b_6_11 = emitter.zx(s_b_6_10, emitter.context().types().u32());
        /* execute.simd:3681 [D] s_b_6_12 = s_b_6_9+s_b_6_11 */
        auto s_b_6_12 = emitter.add(emitter.const_u32(s_b_6_9), s_b_6_11);
        /* execute.simd:3681 [D] s_b_6_13 = ReadRegBank 23:s_b_6_12 (u8) */
        captive::arch::dbt::el::Value *s_b_6_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_6_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_6_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3681 [D] s_b_6_14: WriteRegBank 23:s_b_6_5 = s_b_6_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_6_5))),s_b_6_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_6_5))),s_b_6_13);
        /* execute.simd:3681 [F] s_b_6_15: Jump b_7 (const) */
        {
          auto block = block_b_7;
          dynamic_block_queue.push(block_b_7);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.simd:3678 [F] s_b_7_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3678 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
        /* execute.simd:3678 [F] s_b_7_2 = constant u32 10 (const) */
        /* execute.simd:3678 [F] s_b_7_3 = s_b_7_1*s_b_7_2 (const) */
        uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3678 [F] s_b_7_4 = constant u32 2 (const) */
        /* execute.simd:3678 [F] s_b_7_5 = s_b_7_3+s_b_7_4 (const) */
        uint32_t s_b_7_5 = ((uint32_t)(s_b_7_3 + (uint32_t)2ULL));
        /* execute.simd:3678 [D] s_b_7_6 = ReadRegBank 23:s_b_7_5 (u8) */
        auto s_b_7_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_7_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_7_5))),s_b_7_6,emitter.const_u8(1));
        }
        /* execute.simd:3678 [D] s_b_7_7: sym_34875_0_rm = s_b_7_6, dominates: s_b_8_10  */
        emitter.store_local(DV_sym_34875_0_rm, s_b_7_6);
        /* execute.simd:3680 [F] s_b_7_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3680 [F] s_b_7_9 = (u32)s_b_7_8 (const) */
        /* execute.simd:3680 [F] s_b_7_10 = constant u32 1 (const) */
        /* execute.simd:3680 [F] s_b_7_11 = s_b_7_9+s_b_7_10 (const) */
        uint32_t s_b_7_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3680 [F] s_b_7_12 = constant u32 10 (const) */
        /* execute.simd:3680 [F] s_b_7_13 = s_b_7_12*s_b_7_11 (const) */
        uint32_t s_b_7_13 = ((uint32_t)((uint32_t)16ULL * s_b_7_11));
        /* execute.simd:3680 [D] s_b_7_14 = (u32)s_b_7_6 */
        auto s_b_7_14 = emitter.zx(s_b_7_6, emitter.context().types().u32());
        /* execute.simd:3680 [D] s_b_7_15 = s_b_7_14<s_b_7_13 */
        auto s_b_7_15 = emitter.cmp_lt(s_b_7_14, emitter.const_u32(s_b_7_13));
        /* execute.simd:3680 [D] s_b_7_16: If s_b_7_15: Jump b_8 else b_9 */
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
          emitter.branch(s_b_7_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.simd:3681 [F] s_b_8_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3681 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
        /* execute.simd:3681 [F] s_b_8_2 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_8_3 = s_b_8_1*s_b_8_2 (const) */
        uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3681 [F] s_b_8_4 = constant u32 2 (const) */
        /* execute.simd:3681 [F] s_b_8_5 = s_b_8_3+s_b_8_4 (const) */
        uint32_t s_b_8_5 = ((uint32_t)(s_b_8_3 + (uint32_t)2ULL));
        /* execute.simd:3681 [F] s_b_8_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3681 [F] s_b_8_7 = (u32)s_b_8_6 (const) */
        /* execute.simd:3681 [F] s_b_8_8 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_8_9 = s_b_8_7*s_b_8_8 (const) */
        uint32_t s_b_8_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3681 [D] s_b_8_10 = sym_34875_0_rm uint8_t */
        auto s_b_8_10 = emitter.load_local(DV_sym_34875_0_rm, emitter.context().types().u8());
        /* execute.simd:3681 [D] s_b_8_11 = (u32)s_b_8_10 */
        auto s_b_8_11 = emitter.zx(s_b_8_10, emitter.context().types().u32());
        /* execute.simd:3681 [D] s_b_8_12 = s_b_8_9+s_b_8_11 */
        auto s_b_8_12 = emitter.add(emitter.const_u32(s_b_8_9), s_b_8_11);
        /* execute.simd:3681 [D] s_b_8_13 = ReadRegBank 23:s_b_8_12 (u8) */
        captive::arch::dbt::el::Value *s_b_8_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_8_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_8_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3681 [D] s_b_8_14: WriteRegBank 23:s_b_8_5 = s_b_8_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_8_5))),s_b_8_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_8_5))),s_b_8_13);
        /* execute.simd:3681 [F] s_b_8_15: Jump b_9 (const) */
        {
          auto block = block_b_9;
          dynamic_block_queue.push(block_b_9);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.simd:3678 [F] s_b_9_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3678 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
        /* execute.simd:3678 [F] s_b_9_2 = constant u32 10 (const) */
        /* execute.simd:3678 [F] s_b_9_3 = s_b_9_1*s_b_9_2 (const) */
        uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3678 [F] s_b_9_4 = constant u32 3 (const) */
        /* execute.simd:3678 [F] s_b_9_5 = s_b_9_3+s_b_9_4 (const) */
        uint32_t s_b_9_5 = ((uint32_t)(s_b_9_3 + (uint32_t)3ULL));
        /* execute.simd:3678 [D] s_b_9_6 = ReadRegBank 23:s_b_9_5 (u8) */
        auto s_b_9_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_9_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_9_5))),s_b_9_6,emitter.const_u8(1));
        }
        /* execute.simd:3678 [D] s_b_9_7: sym_34875_0_rm = s_b_9_6, dominates: s_b_10_10  */
        emitter.store_local(DV_sym_34875_0_rm, s_b_9_6);
        /* execute.simd:3680 [F] s_b_9_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3680 [F] s_b_9_9 = (u32)s_b_9_8 (const) */
        /* execute.simd:3680 [F] s_b_9_10 = constant u32 1 (const) */
        /* execute.simd:3680 [F] s_b_9_11 = s_b_9_9+s_b_9_10 (const) */
        uint32_t s_b_9_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3680 [F] s_b_9_12 = constant u32 10 (const) */
        /* execute.simd:3680 [F] s_b_9_13 = s_b_9_12*s_b_9_11 (const) */
        uint32_t s_b_9_13 = ((uint32_t)((uint32_t)16ULL * s_b_9_11));
        /* execute.simd:3680 [D] s_b_9_14 = (u32)s_b_9_6 */
        auto s_b_9_14 = emitter.zx(s_b_9_6, emitter.context().types().u32());
        /* execute.simd:3680 [D] s_b_9_15 = s_b_9_14<s_b_9_13 */
        auto s_b_9_15 = emitter.cmp_lt(s_b_9_14, emitter.const_u32(s_b_9_13));
        /* execute.simd:3680 [D] s_b_9_16: If s_b_9_15: Jump b_10 else b_11 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_10;
            dynamic_block_queue.push(block_b_10);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
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
        /* execute.simd:3681 [F] s_b_10_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3681 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
        /* execute.simd:3681 [F] s_b_10_2 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_10_3 = s_b_10_1*s_b_10_2 (const) */
        uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3681 [F] s_b_10_4 = constant u32 3 (const) */
        /* execute.simd:3681 [F] s_b_10_5 = s_b_10_3+s_b_10_4 (const) */
        uint32_t s_b_10_5 = ((uint32_t)(s_b_10_3 + (uint32_t)3ULL));
        /* execute.simd:3681 [F] s_b_10_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3681 [F] s_b_10_7 = (u32)s_b_10_6 (const) */
        /* execute.simd:3681 [F] s_b_10_8 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_10_9 = s_b_10_7*s_b_10_8 (const) */
        uint32_t s_b_10_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3681 [D] s_b_10_10 = sym_34875_0_rm uint8_t */
        auto s_b_10_10 = emitter.load_local(DV_sym_34875_0_rm, emitter.context().types().u8());
        /* execute.simd:3681 [D] s_b_10_11 = (u32)s_b_10_10 */
        auto s_b_10_11 = emitter.zx(s_b_10_10, emitter.context().types().u32());
        /* execute.simd:3681 [D] s_b_10_12 = s_b_10_9+s_b_10_11 */
        auto s_b_10_12 = emitter.add(emitter.const_u32(s_b_10_9), s_b_10_11);
        /* execute.simd:3681 [D] s_b_10_13 = ReadRegBank 23:s_b_10_12 (u8) */
        captive::arch::dbt::el::Value *s_b_10_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_10_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_10_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3681 [D] s_b_10_14: WriteRegBank 23:s_b_10_5 = s_b_10_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_10_5))),s_b_10_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_10_5))),s_b_10_13);
        /* execute.simd:3681 [F] s_b_10_15: Jump b_11 (const) */
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* execute.simd:3678 [F] s_b_11_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3678 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
        /* execute.simd:3678 [F] s_b_11_2 = constant u32 10 (const) */
        /* execute.simd:3678 [F] s_b_11_3 = s_b_11_1*s_b_11_2 (const) */
        uint32_t s_b_11_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3678 [F] s_b_11_4 = constant u32 4 (const) */
        /* execute.simd:3678 [F] s_b_11_5 = s_b_11_3+s_b_11_4 (const) */
        uint32_t s_b_11_5 = ((uint32_t)(s_b_11_3 + (uint32_t)4ULL));
        /* execute.simd:3678 [D] s_b_11_6 = ReadRegBank 23:s_b_11_5 (u8) */
        auto s_b_11_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_11_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_11_5))),s_b_11_6,emitter.const_u8(1));
        }
        /* execute.simd:3678 [D] s_b_11_7: sym_34875_0_rm = s_b_11_6, dominates: s_b_12_10  */
        emitter.store_local(DV_sym_34875_0_rm, s_b_11_6);
        /* execute.simd:3680 [F] s_b_11_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3680 [F] s_b_11_9 = (u32)s_b_11_8 (const) */
        /* execute.simd:3680 [F] s_b_11_10 = constant u32 1 (const) */
        /* execute.simd:3680 [F] s_b_11_11 = s_b_11_9+s_b_11_10 (const) */
        uint32_t s_b_11_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3680 [F] s_b_11_12 = constant u32 10 (const) */
        /* execute.simd:3680 [F] s_b_11_13 = s_b_11_12*s_b_11_11 (const) */
        uint32_t s_b_11_13 = ((uint32_t)((uint32_t)16ULL * s_b_11_11));
        /* execute.simd:3680 [D] s_b_11_14 = (u32)s_b_11_6 */
        auto s_b_11_14 = emitter.zx(s_b_11_6, emitter.context().types().u32());
        /* execute.simd:3680 [D] s_b_11_15 = s_b_11_14<s_b_11_13 */
        auto s_b_11_15 = emitter.cmp_lt(s_b_11_14, emitter.const_u32(s_b_11_13));
        /* execute.simd:3680 [D] s_b_11_16: If s_b_11_15: Jump b_12 else b_13 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_12;
            dynamic_block_queue.push(block_b_12);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
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
        /* execute.simd:3681 [F] s_b_12_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3681 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
        /* execute.simd:3681 [F] s_b_12_2 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_12_3 = s_b_12_1*s_b_12_2 (const) */
        uint32_t s_b_12_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3681 [F] s_b_12_4 = constant u32 4 (const) */
        /* execute.simd:3681 [F] s_b_12_5 = s_b_12_3+s_b_12_4 (const) */
        uint32_t s_b_12_5 = ((uint32_t)(s_b_12_3 + (uint32_t)4ULL));
        /* execute.simd:3681 [F] s_b_12_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3681 [F] s_b_12_7 = (u32)s_b_12_6 (const) */
        /* execute.simd:3681 [F] s_b_12_8 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_12_9 = s_b_12_7*s_b_12_8 (const) */
        uint32_t s_b_12_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3681 [D] s_b_12_10 = sym_34875_0_rm uint8_t */
        auto s_b_12_10 = emitter.load_local(DV_sym_34875_0_rm, emitter.context().types().u8());
        /* execute.simd:3681 [D] s_b_12_11 = (u32)s_b_12_10 */
        auto s_b_12_11 = emitter.zx(s_b_12_10, emitter.context().types().u32());
        /* execute.simd:3681 [D] s_b_12_12 = s_b_12_9+s_b_12_11 */
        auto s_b_12_12 = emitter.add(emitter.const_u32(s_b_12_9), s_b_12_11);
        /* execute.simd:3681 [D] s_b_12_13 = ReadRegBank 23:s_b_12_12 (u8) */
        captive::arch::dbt::el::Value *s_b_12_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_12_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_12_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3681 [D] s_b_12_14: WriteRegBank 23:s_b_12_5 = s_b_12_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_12_5))),s_b_12_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_12_5))),s_b_12_13);
        /* execute.simd:3681 [F] s_b_12_15: Jump b_13 (const) */
        {
          auto block = block_b_13;
          dynamic_block_queue.push(block_b_13);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.simd:3678 [F] s_b_13_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3678 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
        /* execute.simd:3678 [F] s_b_13_2 = constant u32 10 (const) */
        /* execute.simd:3678 [F] s_b_13_3 = s_b_13_1*s_b_13_2 (const) */
        uint32_t s_b_13_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3678 [F] s_b_13_4 = constant u32 5 (const) */
        /* execute.simd:3678 [F] s_b_13_5 = s_b_13_3+s_b_13_4 (const) */
        uint32_t s_b_13_5 = ((uint32_t)(s_b_13_3 + (uint32_t)5ULL));
        /* execute.simd:3678 [D] s_b_13_6 = ReadRegBank 23:s_b_13_5 (u8) */
        auto s_b_13_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_13_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_13_5))),s_b_13_6,emitter.const_u8(1));
        }
        /* execute.simd:3678 [D] s_b_13_7: sym_34875_0_rm = s_b_13_6, dominates: s_b_14_10  */
        emitter.store_local(DV_sym_34875_0_rm, s_b_13_6);
        /* execute.simd:3680 [F] s_b_13_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3680 [F] s_b_13_9 = (u32)s_b_13_8 (const) */
        /* execute.simd:3680 [F] s_b_13_10 = constant u32 1 (const) */
        /* execute.simd:3680 [F] s_b_13_11 = s_b_13_9+s_b_13_10 (const) */
        uint32_t s_b_13_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3680 [F] s_b_13_12 = constant u32 10 (const) */
        /* execute.simd:3680 [F] s_b_13_13 = s_b_13_12*s_b_13_11 (const) */
        uint32_t s_b_13_13 = ((uint32_t)((uint32_t)16ULL * s_b_13_11));
        /* execute.simd:3680 [D] s_b_13_14 = (u32)s_b_13_6 */
        auto s_b_13_14 = emitter.zx(s_b_13_6, emitter.context().types().u32());
        /* execute.simd:3680 [D] s_b_13_15 = s_b_13_14<s_b_13_13 */
        auto s_b_13_15 = emitter.cmp_lt(s_b_13_14, emitter.const_u32(s_b_13_13));
        /* execute.simd:3680 [D] s_b_13_16: If s_b_13_15: Jump b_14 else b_15 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_14;
            dynamic_block_queue.push(block_b_14);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
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
        /* execute.simd:3681 [F] s_b_14_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3681 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
        /* execute.simd:3681 [F] s_b_14_2 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_14_3 = s_b_14_1*s_b_14_2 (const) */
        uint32_t s_b_14_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3681 [F] s_b_14_4 = constant u32 5 (const) */
        /* execute.simd:3681 [F] s_b_14_5 = s_b_14_3+s_b_14_4 (const) */
        uint32_t s_b_14_5 = ((uint32_t)(s_b_14_3 + (uint32_t)5ULL));
        /* execute.simd:3681 [F] s_b_14_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3681 [F] s_b_14_7 = (u32)s_b_14_6 (const) */
        /* execute.simd:3681 [F] s_b_14_8 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_14_9 = s_b_14_7*s_b_14_8 (const) */
        uint32_t s_b_14_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3681 [D] s_b_14_10 = sym_34875_0_rm uint8_t */
        auto s_b_14_10 = emitter.load_local(DV_sym_34875_0_rm, emitter.context().types().u8());
        /* execute.simd:3681 [D] s_b_14_11 = (u32)s_b_14_10 */
        auto s_b_14_11 = emitter.zx(s_b_14_10, emitter.context().types().u32());
        /* execute.simd:3681 [D] s_b_14_12 = s_b_14_9+s_b_14_11 */
        auto s_b_14_12 = emitter.add(emitter.const_u32(s_b_14_9), s_b_14_11);
        /* execute.simd:3681 [D] s_b_14_13 = ReadRegBank 23:s_b_14_12 (u8) */
        captive::arch::dbt::el::Value *s_b_14_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_14_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_14_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3681 [D] s_b_14_14: WriteRegBank 23:s_b_14_5 = s_b_14_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_14_5))),s_b_14_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_14_5))),s_b_14_13);
        /* execute.simd:3681 [F] s_b_14_15: Jump b_15 (const) */
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.simd:3678 [F] s_b_15_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3678 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
        /* execute.simd:3678 [F] s_b_15_2 = constant u32 10 (const) */
        /* execute.simd:3678 [F] s_b_15_3 = s_b_15_1*s_b_15_2 (const) */
        uint32_t s_b_15_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3678 [F] s_b_15_4 = constant u32 6 (const) */
        /* execute.simd:3678 [F] s_b_15_5 = s_b_15_3+s_b_15_4 (const) */
        uint32_t s_b_15_5 = ((uint32_t)(s_b_15_3 + (uint32_t)6ULL));
        /* execute.simd:3678 [D] s_b_15_6 = ReadRegBank 23:s_b_15_5 (u8) */
        auto s_b_15_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_15_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_15_5))),s_b_15_6,emitter.const_u8(1));
        }
        /* execute.simd:3678 [D] s_b_15_7: sym_34875_0_rm = s_b_15_6, dominates: s_b_16_10  */
        emitter.store_local(DV_sym_34875_0_rm, s_b_15_6);
        /* execute.simd:3680 [F] s_b_15_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3680 [F] s_b_15_9 = (u32)s_b_15_8 (const) */
        /* execute.simd:3680 [F] s_b_15_10 = constant u32 1 (const) */
        /* execute.simd:3680 [F] s_b_15_11 = s_b_15_9+s_b_15_10 (const) */
        uint32_t s_b_15_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3680 [F] s_b_15_12 = constant u32 10 (const) */
        /* execute.simd:3680 [F] s_b_15_13 = s_b_15_12*s_b_15_11 (const) */
        uint32_t s_b_15_13 = ((uint32_t)((uint32_t)16ULL * s_b_15_11));
        /* execute.simd:3680 [D] s_b_15_14 = (u32)s_b_15_6 */
        auto s_b_15_14 = emitter.zx(s_b_15_6, emitter.context().types().u32());
        /* execute.simd:3680 [D] s_b_15_15 = s_b_15_14<s_b_15_13 */
        auto s_b_15_15 = emitter.cmp_lt(s_b_15_14, emitter.const_u32(s_b_15_13));
        /* execute.simd:3680 [D] s_b_15_16: If s_b_15_15: Jump b_16 else b_17 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_16;
            dynamic_block_queue.push(block_b_16);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
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
        /* execute.simd:3681 [F] s_b_16_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3681 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
        /* execute.simd:3681 [F] s_b_16_2 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_16_3 = s_b_16_1*s_b_16_2 (const) */
        uint32_t s_b_16_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3681 [F] s_b_16_4 = constant u32 6 (const) */
        /* execute.simd:3681 [F] s_b_16_5 = s_b_16_3+s_b_16_4 (const) */
        uint32_t s_b_16_5 = ((uint32_t)(s_b_16_3 + (uint32_t)6ULL));
        /* execute.simd:3681 [F] s_b_16_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3681 [F] s_b_16_7 = (u32)s_b_16_6 (const) */
        /* execute.simd:3681 [F] s_b_16_8 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_16_9 = s_b_16_7*s_b_16_8 (const) */
        uint32_t s_b_16_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3681 [D] s_b_16_10 = sym_34875_0_rm uint8_t */
        auto s_b_16_10 = emitter.load_local(DV_sym_34875_0_rm, emitter.context().types().u8());
        /* execute.simd:3681 [D] s_b_16_11 = (u32)s_b_16_10 */
        auto s_b_16_11 = emitter.zx(s_b_16_10, emitter.context().types().u32());
        /* execute.simd:3681 [D] s_b_16_12 = s_b_16_9+s_b_16_11 */
        auto s_b_16_12 = emitter.add(emitter.const_u32(s_b_16_9), s_b_16_11);
        /* execute.simd:3681 [D] s_b_16_13 = ReadRegBank 23:s_b_16_12 (u8) */
        captive::arch::dbt::el::Value *s_b_16_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_16_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_16_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3681 [D] s_b_16_14: WriteRegBank 23:s_b_16_5 = s_b_16_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_16_5))),s_b_16_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_16_5))),s_b_16_13);
        /* execute.simd:3681 [F] s_b_16_15: Jump b_17 (const) */
        {
          auto block = block_b_17;
          dynamic_block_queue.push(block_b_17);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.simd:3678 [F] s_b_17_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3678 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
        /* execute.simd:3678 [F] s_b_17_2 = constant u32 10 (const) */
        /* execute.simd:3678 [F] s_b_17_3 = s_b_17_1*s_b_17_2 (const) */
        uint32_t s_b_17_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3678 [F] s_b_17_4 = constant u32 7 (const) */
        /* execute.simd:3678 [F] s_b_17_5 = s_b_17_3+s_b_17_4 (const) */
        uint32_t s_b_17_5 = ((uint32_t)(s_b_17_3 + (uint32_t)7ULL));
        /* execute.simd:3678 [D] s_b_17_6 = ReadRegBank 23:s_b_17_5 (u8) */
        auto s_b_17_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_17_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_17_5))),s_b_17_6,emitter.const_u8(1));
        }
        /* execute.simd:3678 [D] s_b_17_7: sym_34875_0_rm = s_b_17_6, dominates: s_b_18_10  */
        emitter.store_local(DV_sym_34875_0_rm, s_b_17_6);
        /* execute.simd:3680 [F] s_b_17_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3680 [F] s_b_17_9 = (u32)s_b_17_8 (const) */
        /* execute.simd:3680 [F] s_b_17_10 = constant u32 1 (const) */
        /* execute.simd:3680 [F] s_b_17_11 = s_b_17_9+s_b_17_10 (const) */
        uint32_t s_b_17_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3680 [F] s_b_17_12 = constant u32 10 (const) */
        /* execute.simd:3680 [F] s_b_17_13 = s_b_17_12*s_b_17_11 (const) */
        uint32_t s_b_17_13 = ((uint32_t)((uint32_t)16ULL * s_b_17_11));
        /* execute.simd:3680 [D] s_b_17_14 = (u32)s_b_17_6 */
        auto s_b_17_14 = emitter.zx(s_b_17_6, emitter.context().types().u32());
        /* execute.simd:3680 [D] s_b_17_15 = s_b_17_14<s_b_17_13 */
        auto s_b_17_15 = emitter.cmp_lt(s_b_17_14, emitter.const_u32(s_b_17_13));
        /* execute.simd:3680 [D] s_b_17_16: If s_b_17_15: Jump b_18 else b_19 */
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
          emitter.branch(s_b_17_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.simd:3681 [F] s_b_18_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3681 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
        /* execute.simd:3681 [F] s_b_18_2 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_18_3 = s_b_18_1*s_b_18_2 (const) */
        uint32_t s_b_18_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3681 [F] s_b_18_4 = constant u32 7 (const) */
        /* execute.simd:3681 [F] s_b_18_5 = s_b_18_3+s_b_18_4 (const) */
        uint32_t s_b_18_5 = ((uint32_t)(s_b_18_3 + (uint32_t)7ULL));
        /* execute.simd:3681 [F] s_b_18_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3681 [F] s_b_18_7 = (u32)s_b_18_6 (const) */
        /* execute.simd:3681 [F] s_b_18_8 = constant u32 10 (const) */
        /* execute.simd:3681 [F] s_b_18_9 = s_b_18_7*s_b_18_8 (const) */
        uint32_t s_b_18_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3681 [D] s_b_18_10 = sym_34875_0_rm uint8_t */
        auto s_b_18_10 = emitter.load_local(DV_sym_34875_0_rm, emitter.context().types().u8());
        /* execute.simd:3681 [D] s_b_18_11 = (u32)s_b_18_10 */
        auto s_b_18_11 = emitter.zx(s_b_18_10, emitter.context().types().u32());
        /* execute.simd:3681 [D] s_b_18_12 = s_b_18_9+s_b_18_11 */
        auto s_b_18_12 = emitter.add(emitter.const_u32(s_b_18_9), s_b_18_11);
        /* execute.simd:3681 [D] s_b_18_13 = ReadRegBank 23:s_b_18_12 (u8) */
        captive::arch::dbt::el::Value *s_b_18_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_18_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_18_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3681 [D] s_b_18_14: WriteRegBank 23:s_b_18_5 = s_b_18_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_18_5))),s_b_18_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_18_5))),s_b_18_13);
        /* execute.simd:3681 [F] s_b_18_15: Jump b_19 (const) */
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.simd:3685 [F] s_b_19_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3685 [F] s_b_19_1 = constant u64 0 (const) */
        /* execute.simd:3685 [F] s_b_19_2: WriteRegBank 3:s_b_19_0 = s_b_19_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:3677 [F] s_b_19_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.simd:3691 [F] s_b_20_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
        /* execute.simd:3691 [F] s_b_20_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_20_3 = s_b_20_1*s_b_20_2 (const) */
        uint32_t s_b_20_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_20_4 = constant u32 0 (const) */
        /* execute.simd:3691 [F] s_b_20_5 = s_b_20_3+s_b_20_4 (const) */
        uint32_t s_b_20_5 = ((uint32_t)(s_b_20_3 + (uint32_t)0ULL));
        /* execute.simd:3691 [F] s_b_20_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_20_7 = (u32)s_b_20_6 (const) */
        /* execute.simd:3691 [F] s_b_20_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_20_9 = s_b_20_7*s_b_20_8 (const) */
        uint32_t s_b_20_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_20_10 = sym_35260_0_rm uint8_t */
        auto s_b_20_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_20_11 = (u32)s_b_20_10 */
        auto s_b_20_11 = emitter.zx(s_b_20_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_20_12 = s_b_20_9+s_b_20_11 */
        auto s_b_20_12 = emitter.add(emitter.const_u32(s_b_20_9), s_b_20_11);
        /* execute.simd:3691 [D] s_b_20_13 = ReadRegBank 23:s_b_20_12 (u8) */
        captive::arch::dbt::el::Value *s_b_20_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_20_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_20_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_20_14: WriteRegBank 23:s_b_20_5 = s_b_20_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_20_5))),s_b_20_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_20_5))),s_b_20_13);
        /* execute.simd:3691 [F] s_b_20_15: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.simd:3688 [F] s_b_21_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
        /* execute.simd:3688 [F] s_b_21_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_21_3 = s_b_21_1*s_b_21_2 (const) */
        uint32_t s_b_21_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_21_4 = constant u32 1 (const) */
        /* execute.simd:3688 [F] s_b_21_5 = s_b_21_3+s_b_21_4 (const) */
        uint32_t s_b_21_5 = ((uint32_t)(s_b_21_3 + (uint32_t)1ULL));
        /* execute.simd:3688 [D] s_b_21_6 = ReadRegBank 23:s_b_21_5 (u8) */
        auto s_b_21_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_21_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_21_5))),s_b_21_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_21_7: sym_35260_0_rm = s_b_21_6, dominates: s_b_22_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_21_6);
        /* execute.simd:3690 [F] s_b_21_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_21_9 = (u32)s_b_21_8 (const) */
        /* execute.simd:3690 [F] s_b_21_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_21_11 = s_b_21_9+s_b_21_10 (const) */
        uint32_t s_b_21_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_21_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_21_13 = s_b_21_12*s_b_21_11 (const) */
        uint32_t s_b_21_13 = ((uint32_t)((uint32_t)16ULL * s_b_21_11));
        /* execute.simd:3690 [D] s_b_21_14 = (u32)s_b_21_6 */
        auto s_b_21_14 = emitter.zx(s_b_21_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_21_15 = s_b_21_14<s_b_21_13 */
        auto s_b_21_15 = emitter.cmp_lt(s_b_21_14, emitter.const_u32(s_b_21_13));
        /* execute.simd:3690 [D] s_b_21_16: If s_b_21_15: Jump b_22 else b_23 */
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
          emitter.branch(s_b_21_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.simd:3691 [F] s_b_22_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
        /* execute.simd:3691 [F] s_b_22_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_22_3 = s_b_22_1*s_b_22_2 (const) */
        uint32_t s_b_22_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_22_4 = constant u32 1 (const) */
        /* execute.simd:3691 [F] s_b_22_5 = s_b_22_3+s_b_22_4 (const) */
        uint32_t s_b_22_5 = ((uint32_t)(s_b_22_3 + (uint32_t)1ULL));
        /* execute.simd:3691 [F] s_b_22_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_22_7 = (u32)s_b_22_6 (const) */
        /* execute.simd:3691 [F] s_b_22_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_22_9 = s_b_22_7*s_b_22_8 (const) */
        uint32_t s_b_22_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_22_10 = sym_35260_0_rm uint8_t */
        auto s_b_22_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_22_11 = (u32)s_b_22_10 */
        auto s_b_22_11 = emitter.zx(s_b_22_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_22_12 = s_b_22_9+s_b_22_11 */
        auto s_b_22_12 = emitter.add(emitter.const_u32(s_b_22_9), s_b_22_11);
        /* execute.simd:3691 [D] s_b_22_13 = ReadRegBank 23:s_b_22_12 (u8) */
        captive::arch::dbt::el::Value *s_b_22_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_22_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_22_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_22_14: WriteRegBank 23:s_b_22_5 = s_b_22_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_22_5))),s_b_22_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_22_5))),s_b_22_13);
        /* execute.simd:3691 [F] s_b_22_15: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.simd:3688 [F] s_b_23_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
        /* execute.simd:3688 [F] s_b_23_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_23_3 = s_b_23_1*s_b_23_2 (const) */
        uint32_t s_b_23_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_23_4 = constant u32 2 (const) */
        /* execute.simd:3688 [F] s_b_23_5 = s_b_23_3+s_b_23_4 (const) */
        uint32_t s_b_23_5 = ((uint32_t)(s_b_23_3 + (uint32_t)2ULL));
        /* execute.simd:3688 [D] s_b_23_6 = ReadRegBank 23:s_b_23_5 (u8) */
        auto s_b_23_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_23_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_23_5))),s_b_23_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_23_7: sym_35260_0_rm = s_b_23_6, dominates: s_b_24_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_23_6);
        /* execute.simd:3690 [F] s_b_23_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_23_9 = (u32)s_b_23_8 (const) */
        /* execute.simd:3690 [F] s_b_23_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_23_11 = s_b_23_9+s_b_23_10 (const) */
        uint32_t s_b_23_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_23_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_23_13 = s_b_23_12*s_b_23_11 (const) */
        uint32_t s_b_23_13 = ((uint32_t)((uint32_t)16ULL * s_b_23_11));
        /* execute.simd:3690 [D] s_b_23_14 = (u32)s_b_23_6 */
        auto s_b_23_14 = emitter.zx(s_b_23_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_23_15 = s_b_23_14<s_b_23_13 */
        auto s_b_23_15 = emitter.cmp_lt(s_b_23_14, emitter.const_u32(s_b_23_13));
        /* execute.simd:3690 [D] s_b_23_16: If s_b_23_15: Jump b_24 else b_25 */
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
          emitter.branch(s_b_23_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.simd:3691 [F] s_b_24_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
        /* execute.simd:3691 [F] s_b_24_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_24_3 = s_b_24_1*s_b_24_2 (const) */
        uint32_t s_b_24_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_24_4 = constant u32 2 (const) */
        /* execute.simd:3691 [F] s_b_24_5 = s_b_24_3+s_b_24_4 (const) */
        uint32_t s_b_24_5 = ((uint32_t)(s_b_24_3 + (uint32_t)2ULL));
        /* execute.simd:3691 [F] s_b_24_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_24_7 = (u32)s_b_24_6 (const) */
        /* execute.simd:3691 [F] s_b_24_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_24_9 = s_b_24_7*s_b_24_8 (const) */
        uint32_t s_b_24_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_24_10 = sym_35260_0_rm uint8_t */
        auto s_b_24_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_24_11 = (u32)s_b_24_10 */
        auto s_b_24_11 = emitter.zx(s_b_24_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_24_12 = s_b_24_9+s_b_24_11 */
        auto s_b_24_12 = emitter.add(emitter.const_u32(s_b_24_9), s_b_24_11);
        /* execute.simd:3691 [D] s_b_24_13 = ReadRegBank 23:s_b_24_12 (u8) */
        captive::arch::dbt::el::Value *s_b_24_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_24_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_24_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_24_14: WriteRegBank 23:s_b_24_5 = s_b_24_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_24_5))),s_b_24_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_24_5))),s_b_24_13);
        /* execute.simd:3691 [F] s_b_24_15: Jump b_25 (const) */
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.simd:3688 [F] s_b_25_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
        /* execute.simd:3688 [F] s_b_25_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_25_3 = s_b_25_1*s_b_25_2 (const) */
        uint32_t s_b_25_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_25_4 = constant u32 3 (const) */
        /* execute.simd:3688 [F] s_b_25_5 = s_b_25_3+s_b_25_4 (const) */
        uint32_t s_b_25_5 = ((uint32_t)(s_b_25_3 + (uint32_t)3ULL));
        /* execute.simd:3688 [D] s_b_25_6 = ReadRegBank 23:s_b_25_5 (u8) */
        auto s_b_25_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_25_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_25_5))),s_b_25_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_25_7: sym_35260_0_rm = s_b_25_6, dominates: s_b_26_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_25_6);
        /* execute.simd:3690 [F] s_b_25_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_25_9 = (u32)s_b_25_8 (const) */
        /* execute.simd:3690 [F] s_b_25_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_25_11 = s_b_25_9+s_b_25_10 (const) */
        uint32_t s_b_25_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_25_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_25_13 = s_b_25_12*s_b_25_11 (const) */
        uint32_t s_b_25_13 = ((uint32_t)((uint32_t)16ULL * s_b_25_11));
        /* execute.simd:3690 [D] s_b_25_14 = (u32)s_b_25_6 */
        auto s_b_25_14 = emitter.zx(s_b_25_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_25_15 = s_b_25_14<s_b_25_13 */
        auto s_b_25_15 = emitter.cmp_lt(s_b_25_14, emitter.const_u32(s_b_25_13));
        /* execute.simd:3690 [D] s_b_25_16: If s_b_25_15: Jump b_26 else b_27 */
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
          emitter.branch(s_b_25_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.simd:3691 [F] s_b_26_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
        /* execute.simd:3691 [F] s_b_26_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_26_3 = s_b_26_1*s_b_26_2 (const) */
        uint32_t s_b_26_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_26_4 = constant u32 3 (const) */
        /* execute.simd:3691 [F] s_b_26_5 = s_b_26_3+s_b_26_4 (const) */
        uint32_t s_b_26_5 = ((uint32_t)(s_b_26_3 + (uint32_t)3ULL));
        /* execute.simd:3691 [F] s_b_26_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_26_7 = (u32)s_b_26_6 (const) */
        /* execute.simd:3691 [F] s_b_26_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_26_9 = s_b_26_7*s_b_26_8 (const) */
        uint32_t s_b_26_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_26_10 = sym_35260_0_rm uint8_t */
        auto s_b_26_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_26_11 = (u32)s_b_26_10 */
        auto s_b_26_11 = emitter.zx(s_b_26_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_26_12 = s_b_26_9+s_b_26_11 */
        auto s_b_26_12 = emitter.add(emitter.const_u32(s_b_26_9), s_b_26_11);
        /* execute.simd:3691 [D] s_b_26_13 = ReadRegBank 23:s_b_26_12 (u8) */
        captive::arch::dbt::el::Value *s_b_26_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_26_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_26_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_26_14: WriteRegBank 23:s_b_26_5 = s_b_26_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_26_5))),s_b_26_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_26_5))),s_b_26_13);
        /* execute.simd:3691 [F] s_b_26_15: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.simd:3688 [F] s_b_27_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
        /* execute.simd:3688 [F] s_b_27_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_27_3 = s_b_27_1*s_b_27_2 (const) */
        uint32_t s_b_27_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_27_4 = constant u32 4 (const) */
        /* execute.simd:3688 [F] s_b_27_5 = s_b_27_3+s_b_27_4 (const) */
        uint32_t s_b_27_5 = ((uint32_t)(s_b_27_3 + (uint32_t)4ULL));
        /* execute.simd:3688 [D] s_b_27_6 = ReadRegBank 23:s_b_27_5 (u8) */
        auto s_b_27_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_27_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_27_5))),s_b_27_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_27_7: sym_35260_0_rm = s_b_27_6, dominates: s_b_28_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_27_6);
        /* execute.simd:3690 [F] s_b_27_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_27_9 = (u32)s_b_27_8 (const) */
        /* execute.simd:3690 [F] s_b_27_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_27_11 = s_b_27_9+s_b_27_10 (const) */
        uint32_t s_b_27_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_27_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_27_13 = s_b_27_12*s_b_27_11 (const) */
        uint32_t s_b_27_13 = ((uint32_t)((uint32_t)16ULL * s_b_27_11));
        /* execute.simd:3690 [D] s_b_27_14 = (u32)s_b_27_6 */
        auto s_b_27_14 = emitter.zx(s_b_27_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_27_15 = s_b_27_14<s_b_27_13 */
        auto s_b_27_15 = emitter.cmp_lt(s_b_27_14, emitter.const_u32(s_b_27_13));
        /* execute.simd:3690 [D] s_b_27_16: If s_b_27_15: Jump b_28 else b_29 */
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
          emitter.branch(s_b_27_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.simd:3691 [F] s_b_28_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
        /* execute.simd:3691 [F] s_b_28_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_28_3 = s_b_28_1*s_b_28_2 (const) */
        uint32_t s_b_28_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_28_4 = constant u32 4 (const) */
        /* execute.simd:3691 [F] s_b_28_5 = s_b_28_3+s_b_28_4 (const) */
        uint32_t s_b_28_5 = ((uint32_t)(s_b_28_3 + (uint32_t)4ULL));
        /* execute.simd:3691 [F] s_b_28_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_28_7 = (u32)s_b_28_6 (const) */
        /* execute.simd:3691 [F] s_b_28_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_28_9 = s_b_28_7*s_b_28_8 (const) */
        uint32_t s_b_28_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_28_10 = sym_35260_0_rm uint8_t */
        auto s_b_28_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_28_11 = (u32)s_b_28_10 */
        auto s_b_28_11 = emitter.zx(s_b_28_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_28_12 = s_b_28_9+s_b_28_11 */
        auto s_b_28_12 = emitter.add(emitter.const_u32(s_b_28_9), s_b_28_11);
        /* execute.simd:3691 [D] s_b_28_13 = ReadRegBank 23:s_b_28_12 (u8) */
        captive::arch::dbt::el::Value *s_b_28_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_28_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_28_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_28_14: WriteRegBank 23:s_b_28_5 = s_b_28_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_28_5))),s_b_28_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_28_5))),s_b_28_13);
        /* execute.simd:3691 [F] s_b_28_15: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.simd:3688 [F] s_b_29_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
        /* execute.simd:3688 [F] s_b_29_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_29_3 = s_b_29_1*s_b_29_2 (const) */
        uint32_t s_b_29_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_29_4 = constant u32 5 (const) */
        /* execute.simd:3688 [F] s_b_29_5 = s_b_29_3+s_b_29_4 (const) */
        uint32_t s_b_29_5 = ((uint32_t)(s_b_29_3 + (uint32_t)5ULL));
        /* execute.simd:3688 [D] s_b_29_6 = ReadRegBank 23:s_b_29_5 (u8) */
        auto s_b_29_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_29_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_29_5))),s_b_29_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_29_7: sym_35260_0_rm = s_b_29_6, dominates: s_b_30_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_29_6);
        /* execute.simd:3690 [F] s_b_29_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_29_9 = (u32)s_b_29_8 (const) */
        /* execute.simd:3690 [F] s_b_29_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_29_11 = s_b_29_9+s_b_29_10 (const) */
        uint32_t s_b_29_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_29_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_29_13 = s_b_29_12*s_b_29_11 (const) */
        uint32_t s_b_29_13 = ((uint32_t)((uint32_t)16ULL * s_b_29_11));
        /* execute.simd:3690 [D] s_b_29_14 = (u32)s_b_29_6 */
        auto s_b_29_14 = emitter.zx(s_b_29_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_29_15 = s_b_29_14<s_b_29_13 */
        auto s_b_29_15 = emitter.cmp_lt(s_b_29_14, emitter.const_u32(s_b_29_13));
        /* execute.simd:3690 [D] s_b_29_16: If s_b_29_15: Jump b_30 else b_31 */
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
          emitter.branch(s_b_29_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.simd:3691 [F] s_b_30_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_30_1 = (u32)s_b_30_0 (const) */
        /* execute.simd:3691 [F] s_b_30_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_30_3 = s_b_30_1*s_b_30_2 (const) */
        uint32_t s_b_30_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_30_4 = constant u32 5 (const) */
        /* execute.simd:3691 [F] s_b_30_5 = s_b_30_3+s_b_30_4 (const) */
        uint32_t s_b_30_5 = ((uint32_t)(s_b_30_3 + (uint32_t)5ULL));
        /* execute.simd:3691 [F] s_b_30_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_30_7 = (u32)s_b_30_6 (const) */
        /* execute.simd:3691 [F] s_b_30_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_30_9 = s_b_30_7*s_b_30_8 (const) */
        uint32_t s_b_30_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_30_10 = sym_35260_0_rm uint8_t */
        auto s_b_30_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_30_11 = (u32)s_b_30_10 */
        auto s_b_30_11 = emitter.zx(s_b_30_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_30_12 = s_b_30_9+s_b_30_11 */
        auto s_b_30_12 = emitter.add(emitter.const_u32(s_b_30_9), s_b_30_11);
        /* execute.simd:3691 [D] s_b_30_13 = ReadRegBank 23:s_b_30_12 (u8) */
        captive::arch::dbt::el::Value *s_b_30_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_30_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_30_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_30_14: WriteRegBank 23:s_b_30_5 = s_b_30_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_30_5))),s_b_30_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_30_5))),s_b_30_13);
        /* execute.simd:3691 [F] s_b_30_15: Jump b_31 (const) */
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.simd:3688 [F] s_b_31_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
        /* execute.simd:3688 [F] s_b_31_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_31_3 = s_b_31_1*s_b_31_2 (const) */
        uint32_t s_b_31_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_31_4 = constant u32 6 (const) */
        /* execute.simd:3688 [F] s_b_31_5 = s_b_31_3+s_b_31_4 (const) */
        uint32_t s_b_31_5 = ((uint32_t)(s_b_31_3 + (uint32_t)6ULL));
        /* execute.simd:3688 [D] s_b_31_6 = ReadRegBank 23:s_b_31_5 (u8) */
        auto s_b_31_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_31_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_31_5))),s_b_31_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_31_7: sym_35260_0_rm = s_b_31_6, dominates: s_b_32_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_31_6);
        /* execute.simd:3690 [F] s_b_31_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_31_9 = (u32)s_b_31_8 (const) */
        /* execute.simd:3690 [F] s_b_31_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_31_11 = s_b_31_9+s_b_31_10 (const) */
        uint32_t s_b_31_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_31_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_31_13 = s_b_31_12*s_b_31_11 (const) */
        uint32_t s_b_31_13 = ((uint32_t)((uint32_t)16ULL * s_b_31_11));
        /* execute.simd:3690 [D] s_b_31_14 = (u32)s_b_31_6 */
        auto s_b_31_14 = emitter.zx(s_b_31_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_31_15 = s_b_31_14<s_b_31_13 */
        auto s_b_31_15 = emitter.cmp_lt(s_b_31_14, emitter.const_u32(s_b_31_13));
        /* execute.simd:3690 [D] s_b_31_16: If s_b_31_15: Jump b_32 else b_33 */
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
          emitter.branch(s_b_31_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.simd:3691 [F] s_b_32_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_32_1 = (u32)s_b_32_0 (const) */
        /* execute.simd:3691 [F] s_b_32_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_32_3 = s_b_32_1*s_b_32_2 (const) */
        uint32_t s_b_32_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_32_4 = constant u32 6 (const) */
        /* execute.simd:3691 [F] s_b_32_5 = s_b_32_3+s_b_32_4 (const) */
        uint32_t s_b_32_5 = ((uint32_t)(s_b_32_3 + (uint32_t)6ULL));
        /* execute.simd:3691 [F] s_b_32_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_32_7 = (u32)s_b_32_6 (const) */
        /* execute.simd:3691 [F] s_b_32_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_32_9 = s_b_32_7*s_b_32_8 (const) */
        uint32_t s_b_32_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_32_10 = sym_35260_0_rm uint8_t */
        auto s_b_32_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_32_11 = (u32)s_b_32_10 */
        auto s_b_32_11 = emitter.zx(s_b_32_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_32_12 = s_b_32_9+s_b_32_11 */
        auto s_b_32_12 = emitter.add(emitter.const_u32(s_b_32_9), s_b_32_11);
        /* execute.simd:3691 [D] s_b_32_13 = ReadRegBank 23:s_b_32_12 (u8) */
        captive::arch::dbt::el::Value *s_b_32_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_32_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_32_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_32_14: WriteRegBank 23:s_b_32_5 = s_b_32_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_32_5))),s_b_32_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_32_5))),s_b_32_13);
        /* execute.simd:3691 [F] s_b_32_15: Jump b_33 (const) */
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.simd:3688 [F] s_b_33_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_33_1 = (u32)s_b_33_0 (const) */
        /* execute.simd:3688 [F] s_b_33_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_33_3 = s_b_33_1*s_b_33_2 (const) */
        uint32_t s_b_33_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_33_4 = constant u32 7 (const) */
        /* execute.simd:3688 [F] s_b_33_5 = s_b_33_3+s_b_33_4 (const) */
        uint32_t s_b_33_5 = ((uint32_t)(s_b_33_3 + (uint32_t)7ULL));
        /* execute.simd:3688 [D] s_b_33_6 = ReadRegBank 23:s_b_33_5 (u8) */
        auto s_b_33_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_33_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_33_5))),s_b_33_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_33_7: sym_35260_0_rm = s_b_33_6, dominates: s_b_34_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_33_6);
        /* execute.simd:3690 [F] s_b_33_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_33_9 = (u32)s_b_33_8 (const) */
        /* execute.simd:3690 [F] s_b_33_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_33_11 = s_b_33_9+s_b_33_10 (const) */
        uint32_t s_b_33_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_33_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_33_13 = s_b_33_12*s_b_33_11 (const) */
        uint32_t s_b_33_13 = ((uint32_t)((uint32_t)16ULL * s_b_33_11));
        /* execute.simd:3690 [D] s_b_33_14 = (u32)s_b_33_6 */
        auto s_b_33_14 = emitter.zx(s_b_33_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_33_15 = s_b_33_14<s_b_33_13 */
        auto s_b_33_15 = emitter.cmp_lt(s_b_33_14, emitter.const_u32(s_b_33_13));
        /* execute.simd:3690 [D] s_b_33_16: If s_b_33_15: Jump b_34 else b_35 */
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
          emitter.branch(s_b_33_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.simd:3691 [F] s_b_34_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
        /* execute.simd:3691 [F] s_b_34_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_34_3 = s_b_34_1*s_b_34_2 (const) */
        uint32_t s_b_34_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_34_4 = constant u32 7 (const) */
        /* execute.simd:3691 [F] s_b_34_5 = s_b_34_3+s_b_34_4 (const) */
        uint32_t s_b_34_5 = ((uint32_t)(s_b_34_3 + (uint32_t)7ULL));
        /* execute.simd:3691 [F] s_b_34_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_34_7 = (u32)s_b_34_6 (const) */
        /* execute.simd:3691 [F] s_b_34_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_34_9 = s_b_34_7*s_b_34_8 (const) */
        uint32_t s_b_34_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_34_10 = sym_35260_0_rm uint8_t */
        auto s_b_34_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_34_11 = (u32)s_b_34_10 */
        auto s_b_34_11 = emitter.zx(s_b_34_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_34_12 = s_b_34_9+s_b_34_11 */
        auto s_b_34_12 = emitter.add(emitter.const_u32(s_b_34_9), s_b_34_11);
        /* execute.simd:3691 [D] s_b_34_13 = ReadRegBank 23:s_b_34_12 (u8) */
        captive::arch::dbt::el::Value *s_b_34_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_34_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_34_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_34_14: WriteRegBank 23:s_b_34_5 = s_b_34_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_34_5))),s_b_34_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_34_5))),s_b_34_13);
        /* execute.simd:3691 [F] s_b_34_15: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.simd:3688 [F] s_b_35_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
        /* execute.simd:3688 [F] s_b_35_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_35_3 = s_b_35_1*s_b_35_2 (const) */
        uint32_t s_b_35_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_35_4 = constant u32 8 (const) */
        /* execute.simd:3688 [F] s_b_35_5 = s_b_35_3+s_b_35_4 (const) */
        uint32_t s_b_35_5 = ((uint32_t)(s_b_35_3 + (uint32_t)8ULL));
        /* execute.simd:3688 [D] s_b_35_6 = ReadRegBank 23:s_b_35_5 (u8) */
        auto s_b_35_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_35_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_35_5))),s_b_35_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_35_7: sym_35260_0_rm = s_b_35_6, dominates: s_b_36_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_35_6);
        /* execute.simd:3690 [F] s_b_35_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_35_9 = (u32)s_b_35_8 (const) */
        /* execute.simd:3690 [F] s_b_35_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_35_11 = s_b_35_9+s_b_35_10 (const) */
        uint32_t s_b_35_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_35_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_35_13 = s_b_35_12*s_b_35_11 (const) */
        uint32_t s_b_35_13 = ((uint32_t)((uint32_t)16ULL * s_b_35_11));
        /* execute.simd:3690 [D] s_b_35_14 = (u32)s_b_35_6 */
        auto s_b_35_14 = emitter.zx(s_b_35_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_35_15 = s_b_35_14<s_b_35_13 */
        auto s_b_35_15 = emitter.cmp_lt(s_b_35_14, emitter.const_u32(s_b_35_13));
        /* execute.simd:3690 [D] s_b_35_16: If s_b_35_15: Jump b_36 else b_37 */
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
          emitter.branch(s_b_35_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_36) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_36);
        /* execute.simd:3691 [F] s_b_36_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_36_1 = (u32)s_b_36_0 (const) */
        /* execute.simd:3691 [F] s_b_36_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_36_3 = s_b_36_1*s_b_36_2 (const) */
        uint32_t s_b_36_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_36_4 = constant u32 8 (const) */
        /* execute.simd:3691 [F] s_b_36_5 = s_b_36_3+s_b_36_4 (const) */
        uint32_t s_b_36_5 = ((uint32_t)(s_b_36_3 + (uint32_t)8ULL));
        /* execute.simd:3691 [F] s_b_36_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_36_7 = (u32)s_b_36_6 (const) */
        /* execute.simd:3691 [F] s_b_36_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_36_9 = s_b_36_7*s_b_36_8 (const) */
        uint32_t s_b_36_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_36_10 = sym_35260_0_rm uint8_t */
        auto s_b_36_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_36_11 = (u32)s_b_36_10 */
        auto s_b_36_11 = emitter.zx(s_b_36_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_36_12 = s_b_36_9+s_b_36_11 */
        auto s_b_36_12 = emitter.add(emitter.const_u32(s_b_36_9), s_b_36_11);
        /* execute.simd:3691 [D] s_b_36_13 = ReadRegBank 23:s_b_36_12 (u8) */
        captive::arch::dbt::el::Value *s_b_36_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_36_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_36_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_36_14: WriteRegBank 23:s_b_36_5 = s_b_36_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_36_5))),s_b_36_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_36_5))),s_b_36_13);
        /* execute.simd:3691 [F] s_b_36_15: Jump b_37 (const) */
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.simd:3688 [F] s_b_37_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_37_1 = (u32)s_b_37_0 (const) */
        /* execute.simd:3688 [F] s_b_37_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_37_3 = s_b_37_1*s_b_37_2 (const) */
        uint32_t s_b_37_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_37_4 = constant u32 9 (const) */
        /* execute.simd:3688 [F] s_b_37_5 = s_b_37_3+s_b_37_4 (const) */
        uint32_t s_b_37_5 = ((uint32_t)(s_b_37_3 + (uint32_t)9ULL));
        /* execute.simd:3688 [D] s_b_37_6 = ReadRegBank 23:s_b_37_5 (u8) */
        auto s_b_37_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_37_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_37_5))),s_b_37_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_37_7: sym_35260_0_rm = s_b_37_6, dominates: s_b_38_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_37_6);
        /* execute.simd:3690 [F] s_b_37_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_37_9 = (u32)s_b_37_8 (const) */
        /* execute.simd:3690 [F] s_b_37_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_37_11 = s_b_37_9+s_b_37_10 (const) */
        uint32_t s_b_37_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_37_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_37_13 = s_b_37_12*s_b_37_11 (const) */
        uint32_t s_b_37_13 = ((uint32_t)((uint32_t)16ULL * s_b_37_11));
        /* execute.simd:3690 [D] s_b_37_14 = (u32)s_b_37_6 */
        auto s_b_37_14 = emitter.zx(s_b_37_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_37_15 = s_b_37_14<s_b_37_13 */
        auto s_b_37_15 = emitter.cmp_lt(s_b_37_14, emitter.const_u32(s_b_37_13));
        /* execute.simd:3690 [D] s_b_37_16: If s_b_37_15: Jump b_38 else b_39 */
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
          emitter.branch(s_b_37_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_38) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_38);
        /* execute.simd:3691 [F] s_b_38_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_38_1 = (u32)s_b_38_0 (const) */
        /* execute.simd:3691 [F] s_b_38_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_38_3 = s_b_38_1*s_b_38_2 (const) */
        uint32_t s_b_38_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_38_4 = constant u32 9 (const) */
        /* execute.simd:3691 [F] s_b_38_5 = s_b_38_3+s_b_38_4 (const) */
        uint32_t s_b_38_5 = ((uint32_t)(s_b_38_3 + (uint32_t)9ULL));
        /* execute.simd:3691 [F] s_b_38_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_38_7 = (u32)s_b_38_6 (const) */
        /* execute.simd:3691 [F] s_b_38_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_38_9 = s_b_38_7*s_b_38_8 (const) */
        uint32_t s_b_38_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_38_10 = sym_35260_0_rm uint8_t */
        auto s_b_38_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_38_11 = (u32)s_b_38_10 */
        auto s_b_38_11 = emitter.zx(s_b_38_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_38_12 = s_b_38_9+s_b_38_11 */
        auto s_b_38_12 = emitter.add(emitter.const_u32(s_b_38_9), s_b_38_11);
        /* execute.simd:3691 [D] s_b_38_13 = ReadRegBank 23:s_b_38_12 (u8) */
        captive::arch::dbt::el::Value *s_b_38_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_38_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_38_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_38_14: WriteRegBank 23:s_b_38_5 = s_b_38_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_38_5))),s_b_38_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_38_5))),s_b_38_13);
        /* execute.simd:3691 [F] s_b_38_15: Jump b_39 (const) */
        {
          auto block = block_b_39;
          dynamic_block_queue.push(block_b_39);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.simd:3688 [F] s_b_39_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_39_1 = (u32)s_b_39_0 (const) */
        /* execute.simd:3688 [F] s_b_39_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_39_3 = s_b_39_1*s_b_39_2 (const) */
        uint32_t s_b_39_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_39_4 = constant u32 a (const) */
        /* execute.simd:3688 [F] s_b_39_5 = s_b_39_3+s_b_39_4 (const) */
        uint32_t s_b_39_5 = ((uint32_t)(s_b_39_3 + (uint32_t)10ULL));
        /* execute.simd:3688 [D] s_b_39_6 = ReadRegBank 23:s_b_39_5 (u8) */
        auto s_b_39_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_39_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_39_5))),s_b_39_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_39_7: sym_35260_0_rm = s_b_39_6, dominates: s_b_40_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_39_6);
        /* execute.simd:3690 [F] s_b_39_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_39_9 = (u32)s_b_39_8 (const) */
        /* execute.simd:3690 [F] s_b_39_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_39_11 = s_b_39_9+s_b_39_10 (const) */
        uint32_t s_b_39_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_39_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_39_13 = s_b_39_12*s_b_39_11 (const) */
        uint32_t s_b_39_13 = ((uint32_t)((uint32_t)16ULL * s_b_39_11));
        /* execute.simd:3690 [D] s_b_39_14 = (u32)s_b_39_6 */
        auto s_b_39_14 = emitter.zx(s_b_39_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_39_15 = s_b_39_14<s_b_39_13 */
        auto s_b_39_15 = emitter.cmp_lt(s_b_39_14, emitter.const_u32(s_b_39_13));
        /* execute.simd:3690 [D] s_b_39_16: If s_b_39_15: Jump b_40 else b_41 */
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
          emitter.branch(s_b_39_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_40) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_40);
        /* execute.simd:3691 [F] s_b_40_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_40_1 = (u32)s_b_40_0 (const) */
        /* execute.simd:3691 [F] s_b_40_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_40_3 = s_b_40_1*s_b_40_2 (const) */
        uint32_t s_b_40_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_40_4 = constant u32 a (const) */
        /* execute.simd:3691 [F] s_b_40_5 = s_b_40_3+s_b_40_4 (const) */
        uint32_t s_b_40_5 = ((uint32_t)(s_b_40_3 + (uint32_t)10ULL));
        /* execute.simd:3691 [F] s_b_40_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_40_7 = (u32)s_b_40_6 (const) */
        /* execute.simd:3691 [F] s_b_40_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_40_9 = s_b_40_7*s_b_40_8 (const) */
        uint32_t s_b_40_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_40_10 = sym_35260_0_rm uint8_t */
        auto s_b_40_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_40_11 = (u32)s_b_40_10 */
        auto s_b_40_11 = emitter.zx(s_b_40_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_40_12 = s_b_40_9+s_b_40_11 */
        auto s_b_40_12 = emitter.add(emitter.const_u32(s_b_40_9), s_b_40_11);
        /* execute.simd:3691 [D] s_b_40_13 = ReadRegBank 23:s_b_40_12 (u8) */
        captive::arch::dbt::el::Value *s_b_40_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_40_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_40_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_40_14: WriteRegBank 23:s_b_40_5 = s_b_40_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_40_5))),s_b_40_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_40_5))),s_b_40_13);
        /* execute.simd:3691 [F] s_b_40_15: Jump b_41 (const) */
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.simd:3688 [F] s_b_41_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_41_1 = (u32)s_b_41_0 (const) */
        /* execute.simd:3688 [F] s_b_41_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_41_3 = s_b_41_1*s_b_41_2 (const) */
        uint32_t s_b_41_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_41_4 = constant u32 b (const) */
        /* execute.simd:3688 [F] s_b_41_5 = s_b_41_3+s_b_41_4 (const) */
        uint32_t s_b_41_5 = ((uint32_t)(s_b_41_3 + (uint32_t)11ULL));
        /* execute.simd:3688 [D] s_b_41_6 = ReadRegBank 23:s_b_41_5 (u8) */
        auto s_b_41_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_41_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_41_5))),s_b_41_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_41_7: sym_35260_0_rm = s_b_41_6, dominates: s_b_42_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_41_6);
        /* execute.simd:3690 [F] s_b_41_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_41_9 = (u32)s_b_41_8 (const) */
        /* execute.simd:3690 [F] s_b_41_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_41_11 = s_b_41_9+s_b_41_10 (const) */
        uint32_t s_b_41_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_41_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_41_13 = s_b_41_12*s_b_41_11 (const) */
        uint32_t s_b_41_13 = ((uint32_t)((uint32_t)16ULL * s_b_41_11));
        /* execute.simd:3690 [D] s_b_41_14 = (u32)s_b_41_6 */
        auto s_b_41_14 = emitter.zx(s_b_41_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_41_15 = s_b_41_14<s_b_41_13 */
        auto s_b_41_15 = emitter.cmp_lt(s_b_41_14, emitter.const_u32(s_b_41_13));
        /* execute.simd:3690 [D] s_b_41_16: If s_b_41_15: Jump b_42 else b_43 */
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
          emitter.branch(s_b_41_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_42) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_42);
        /* execute.simd:3691 [F] s_b_42_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_42_1 = (u32)s_b_42_0 (const) */
        /* execute.simd:3691 [F] s_b_42_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_42_3 = s_b_42_1*s_b_42_2 (const) */
        uint32_t s_b_42_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_42_4 = constant u32 b (const) */
        /* execute.simd:3691 [F] s_b_42_5 = s_b_42_3+s_b_42_4 (const) */
        uint32_t s_b_42_5 = ((uint32_t)(s_b_42_3 + (uint32_t)11ULL));
        /* execute.simd:3691 [F] s_b_42_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_42_7 = (u32)s_b_42_6 (const) */
        /* execute.simd:3691 [F] s_b_42_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_42_9 = s_b_42_7*s_b_42_8 (const) */
        uint32_t s_b_42_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_42_10 = sym_35260_0_rm uint8_t */
        auto s_b_42_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_42_11 = (u32)s_b_42_10 */
        auto s_b_42_11 = emitter.zx(s_b_42_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_42_12 = s_b_42_9+s_b_42_11 */
        auto s_b_42_12 = emitter.add(emitter.const_u32(s_b_42_9), s_b_42_11);
        /* execute.simd:3691 [D] s_b_42_13 = ReadRegBank 23:s_b_42_12 (u8) */
        captive::arch::dbt::el::Value *s_b_42_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_42_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_42_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_42_14: WriteRegBank 23:s_b_42_5 = s_b_42_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_42_5))),s_b_42_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_42_5))),s_b_42_13);
        /* execute.simd:3691 [F] s_b_42_15: Jump b_43 (const) */
        {
          auto block = block_b_43;
          dynamic_block_queue.push(block_b_43);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_43) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_43);
        /* execute.simd:3688 [F] s_b_43_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_43_1 = (u32)s_b_43_0 (const) */
        /* execute.simd:3688 [F] s_b_43_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_43_3 = s_b_43_1*s_b_43_2 (const) */
        uint32_t s_b_43_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_43_4 = constant u32 c (const) */
        /* execute.simd:3688 [F] s_b_43_5 = s_b_43_3+s_b_43_4 (const) */
        uint32_t s_b_43_5 = ((uint32_t)(s_b_43_3 + (uint32_t)12ULL));
        /* execute.simd:3688 [D] s_b_43_6 = ReadRegBank 23:s_b_43_5 (u8) */
        auto s_b_43_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_43_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_43_5))),s_b_43_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_43_7: sym_35260_0_rm = s_b_43_6, dominates: s_b_44_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_43_6);
        /* execute.simd:3690 [F] s_b_43_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_43_9 = (u32)s_b_43_8 (const) */
        /* execute.simd:3690 [F] s_b_43_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_43_11 = s_b_43_9+s_b_43_10 (const) */
        uint32_t s_b_43_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_43_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_43_13 = s_b_43_12*s_b_43_11 (const) */
        uint32_t s_b_43_13 = ((uint32_t)((uint32_t)16ULL * s_b_43_11));
        /* execute.simd:3690 [D] s_b_43_14 = (u32)s_b_43_6 */
        auto s_b_43_14 = emitter.zx(s_b_43_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_43_15 = s_b_43_14<s_b_43_13 */
        auto s_b_43_15 = emitter.cmp_lt(s_b_43_14, emitter.const_u32(s_b_43_13));
        /* execute.simd:3690 [D] s_b_43_16: If s_b_43_15: Jump b_44 else b_45 */
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
          emitter.branch(s_b_43_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_44) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_44);
        /* execute.simd:3691 [F] s_b_44_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_44_1 = (u32)s_b_44_0 (const) */
        /* execute.simd:3691 [F] s_b_44_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_44_3 = s_b_44_1*s_b_44_2 (const) */
        uint32_t s_b_44_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_44_4 = constant u32 c (const) */
        /* execute.simd:3691 [F] s_b_44_5 = s_b_44_3+s_b_44_4 (const) */
        uint32_t s_b_44_5 = ((uint32_t)(s_b_44_3 + (uint32_t)12ULL));
        /* execute.simd:3691 [F] s_b_44_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_44_7 = (u32)s_b_44_6 (const) */
        /* execute.simd:3691 [F] s_b_44_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_44_9 = s_b_44_7*s_b_44_8 (const) */
        uint32_t s_b_44_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_44_10 = sym_35260_0_rm uint8_t */
        auto s_b_44_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_44_11 = (u32)s_b_44_10 */
        auto s_b_44_11 = emitter.zx(s_b_44_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_44_12 = s_b_44_9+s_b_44_11 */
        auto s_b_44_12 = emitter.add(emitter.const_u32(s_b_44_9), s_b_44_11);
        /* execute.simd:3691 [D] s_b_44_13 = ReadRegBank 23:s_b_44_12 (u8) */
        captive::arch::dbt::el::Value *s_b_44_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_44_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_44_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_44_14: WriteRegBank 23:s_b_44_5 = s_b_44_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_44_5))),s_b_44_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_44_5))),s_b_44_13);
        /* execute.simd:3691 [F] s_b_44_15: Jump b_45 (const) */
        {
          auto block = block_b_45;
          dynamic_block_queue.push(block_b_45);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_45) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_45);
        /* execute.simd:3688 [F] s_b_45_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_45_1 = (u32)s_b_45_0 (const) */
        /* execute.simd:3688 [F] s_b_45_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_45_3 = s_b_45_1*s_b_45_2 (const) */
        uint32_t s_b_45_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_45_4 = constant u32 d (const) */
        /* execute.simd:3688 [F] s_b_45_5 = s_b_45_3+s_b_45_4 (const) */
        uint32_t s_b_45_5 = ((uint32_t)(s_b_45_3 + (uint32_t)13ULL));
        /* execute.simd:3688 [D] s_b_45_6 = ReadRegBank 23:s_b_45_5 (u8) */
        auto s_b_45_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_45_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_45_5))),s_b_45_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_45_7: sym_35260_0_rm = s_b_45_6, dominates: s_b_46_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_45_6);
        /* execute.simd:3690 [F] s_b_45_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_45_9 = (u32)s_b_45_8 (const) */
        /* execute.simd:3690 [F] s_b_45_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_45_11 = s_b_45_9+s_b_45_10 (const) */
        uint32_t s_b_45_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_45_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_45_13 = s_b_45_12*s_b_45_11 (const) */
        uint32_t s_b_45_13 = ((uint32_t)((uint32_t)16ULL * s_b_45_11));
        /* execute.simd:3690 [D] s_b_45_14 = (u32)s_b_45_6 */
        auto s_b_45_14 = emitter.zx(s_b_45_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_45_15 = s_b_45_14<s_b_45_13 */
        auto s_b_45_15 = emitter.cmp_lt(s_b_45_14, emitter.const_u32(s_b_45_13));
        /* execute.simd:3690 [D] s_b_45_16: If s_b_45_15: Jump b_46 else b_47 */
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
          emitter.branch(s_b_45_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_46) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_46);
        /* execute.simd:3691 [F] s_b_46_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_46_1 = (u32)s_b_46_0 (const) */
        /* execute.simd:3691 [F] s_b_46_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_46_3 = s_b_46_1*s_b_46_2 (const) */
        uint32_t s_b_46_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_46_4 = constant u32 d (const) */
        /* execute.simd:3691 [F] s_b_46_5 = s_b_46_3+s_b_46_4 (const) */
        uint32_t s_b_46_5 = ((uint32_t)(s_b_46_3 + (uint32_t)13ULL));
        /* execute.simd:3691 [F] s_b_46_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_46_7 = (u32)s_b_46_6 (const) */
        /* execute.simd:3691 [F] s_b_46_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_46_9 = s_b_46_7*s_b_46_8 (const) */
        uint32_t s_b_46_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_46_10 = sym_35260_0_rm uint8_t */
        auto s_b_46_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_46_11 = (u32)s_b_46_10 */
        auto s_b_46_11 = emitter.zx(s_b_46_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_46_12 = s_b_46_9+s_b_46_11 */
        auto s_b_46_12 = emitter.add(emitter.const_u32(s_b_46_9), s_b_46_11);
        /* execute.simd:3691 [D] s_b_46_13 = ReadRegBank 23:s_b_46_12 (u8) */
        captive::arch::dbt::el::Value *s_b_46_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_46_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_46_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_46_14: WriteRegBank 23:s_b_46_5 = s_b_46_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_46_5))),s_b_46_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_46_5))),s_b_46_13);
        /* execute.simd:3691 [F] s_b_46_15: Jump b_47 (const) */
        {
          auto block = block_b_47;
          dynamic_block_queue.push(block_b_47);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_47) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_47);
        /* execute.simd:3688 [F] s_b_47_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_47_1 = (u32)s_b_47_0 (const) */
        /* execute.simd:3688 [F] s_b_47_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_47_3 = s_b_47_1*s_b_47_2 (const) */
        uint32_t s_b_47_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_47_4 = constant u32 e (const) */
        /* execute.simd:3688 [F] s_b_47_5 = s_b_47_3+s_b_47_4 (const) */
        uint32_t s_b_47_5 = ((uint32_t)(s_b_47_3 + (uint32_t)14ULL));
        /* execute.simd:3688 [D] s_b_47_6 = ReadRegBank 23:s_b_47_5 (u8) */
        auto s_b_47_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_47_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_47_5))),s_b_47_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_47_7: sym_35260_0_rm = s_b_47_6, dominates: s_b_48_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_47_6);
        /* execute.simd:3690 [F] s_b_47_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_47_9 = (u32)s_b_47_8 (const) */
        /* execute.simd:3690 [F] s_b_47_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_47_11 = s_b_47_9+s_b_47_10 (const) */
        uint32_t s_b_47_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_47_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_47_13 = s_b_47_12*s_b_47_11 (const) */
        uint32_t s_b_47_13 = ((uint32_t)((uint32_t)16ULL * s_b_47_11));
        /* execute.simd:3690 [D] s_b_47_14 = (u32)s_b_47_6 */
        auto s_b_47_14 = emitter.zx(s_b_47_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_47_15 = s_b_47_14<s_b_47_13 */
        auto s_b_47_15 = emitter.cmp_lt(s_b_47_14, emitter.const_u32(s_b_47_13));
        /* execute.simd:3690 [D] s_b_47_16: If s_b_47_15: Jump b_48 else b_49 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_48;
            dynamic_block_queue.push(block_b_48);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
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
        /* execute.simd:3691 [F] s_b_48_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_48_1 = (u32)s_b_48_0 (const) */
        /* execute.simd:3691 [F] s_b_48_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_48_3 = s_b_48_1*s_b_48_2 (const) */
        uint32_t s_b_48_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_48_4 = constant u32 e (const) */
        /* execute.simd:3691 [F] s_b_48_5 = s_b_48_3+s_b_48_4 (const) */
        uint32_t s_b_48_5 = ((uint32_t)(s_b_48_3 + (uint32_t)14ULL));
        /* execute.simd:3691 [F] s_b_48_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_48_7 = (u32)s_b_48_6 (const) */
        /* execute.simd:3691 [F] s_b_48_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_48_9 = s_b_48_7*s_b_48_8 (const) */
        uint32_t s_b_48_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_48_10 = sym_35260_0_rm uint8_t */
        auto s_b_48_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_48_11 = (u32)s_b_48_10 */
        auto s_b_48_11 = emitter.zx(s_b_48_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_48_12 = s_b_48_9+s_b_48_11 */
        auto s_b_48_12 = emitter.add(emitter.const_u32(s_b_48_9), s_b_48_11);
        /* execute.simd:3691 [D] s_b_48_13 = ReadRegBank 23:s_b_48_12 (u8) */
        captive::arch::dbt::el::Value *s_b_48_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_48_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_48_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_48_14: WriteRegBank 23:s_b_48_5 = s_b_48_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_48_5))),s_b_48_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_48_5))),s_b_48_13);
        /* execute.simd:3691 [F] s_b_48_15: Jump b_49 (const) */
        {
          auto block = block_b_49;
          dynamic_block_queue.push(block_b_49);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_49) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_49);
        /* execute.simd:3688 [F] s_b_49_0=sym_34852_3_parameter_inst.rm (const) */
        /* execute.simd:3688 [F] s_b_49_1 = (u32)s_b_49_0 (const) */
        /* execute.simd:3688 [F] s_b_49_2 = constant u32 10 (const) */
        /* execute.simd:3688 [F] s_b_49_3 = s_b_49_1*s_b_49_2 (const) */
        uint32_t s_b_49_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3688 [F] s_b_49_4 = constant u32 f (const) */
        /* execute.simd:3688 [F] s_b_49_5 = s_b_49_3+s_b_49_4 (const) */
        uint32_t s_b_49_5 = ((uint32_t)(s_b_49_3 + (uint32_t)15ULL));
        /* execute.simd:3688 [D] s_b_49_6 = ReadRegBank 23:s_b_49_5 (u8) */
        auto s_b_49_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_49_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_49_5))),s_b_49_6,emitter.const_u8(1));
        }
        /* execute.simd:3688 [D] s_b_49_7: sym_35260_0_rm = s_b_49_6, dominates: s_b_50_10  */
        emitter.store_local(DV_sym_35260_0_rm, s_b_49_6);
        /* execute.simd:3690 [F] s_b_49_8=sym_34852_3_parameter_inst.len (const) */
        /* execute.simd:3690 [F] s_b_49_9 = (u32)s_b_49_8 (const) */
        /* execute.simd:3690 [F] s_b_49_10 = constant u32 1 (const) */
        /* execute.simd:3690 [F] s_b_49_11 = s_b_49_9+s_b_49_10 (const) */
        uint32_t s_b_49_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3690 [F] s_b_49_12 = constant u32 10 (const) */
        /* execute.simd:3690 [F] s_b_49_13 = s_b_49_12*s_b_49_11 (const) */
        uint32_t s_b_49_13 = ((uint32_t)((uint32_t)16ULL * s_b_49_11));
        /* execute.simd:3690 [D] s_b_49_14 = (u32)s_b_49_6 */
        auto s_b_49_14 = emitter.zx(s_b_49_6, emitter.context().types().u32());
        /* execute.simd:3690 [D] s_b_49_15 = s_b_49_14<s_b_49_13 */
        auto s_b_49_15 = emitter.cmp_lt(s_b_49_14, emitter.const_u32(s_b_49_13));
        /* execute.simd:3690 [D] s_b_49_16: If s_b_49_15: Jump b_50 else b_2 */
        {
          captive::arch::dbt::el::Block *true_target;
          {
            auto block = block_b_50;
            dynamic_block_queue.push(block_b_50);
            true_target = block;
          }
          captive::arch::dbt::el::Block *false_target;
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
        /* execute.simd:3691 [F] s_b_50_0=sym_34852_3_parameter_inst.rd (const) */
        /* execute.simd:3691 [F] s_b_50_1 = (u32)s_b_50_0 (const) */
        /* execute.simd:3691 [F] s_b_50_2 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_50_3 = s_b_50_1*s_b_50_2 (const) */
        uint32_t s_b_50_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3691 [F] s_b_50_4 = constant u32 f (const) */
        /* execute.simd:3691 [F] s_b_50_5 = s_b_50_3+s_b_50_4 (const) */
        uint32_t s_b_50_5 = ((uint32_t)(s_b_50_3 + (uint32_t)15ULL));
        /* execute.simd:3691 [F] s_b_50_6=sym_34852_3_parameter_inst.rn (const) */
        /* execute.simd:3691 [F] s_b_50_7 = (u32)s_b_50_6 (const) */
        /* execute.simd:3691 [F] s_b_50_8 = constant u32 10 (const) */
        /* execute.simd:3691 [F] s_b_50_9 = s_b_50_7*s_b_50_8 (const) */
        uint32_t s_b_50_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3691 [D] s_b_50_10 = sym_35260_0_rm uint8_t */
        auto s_b_50_10 = emitter.load_local(DV_sym_35260_0_rm, emitter.context().types().u8());
        /* execute.simd:3691 [D] s_b_50_11 = (u32)s_b_50_10 */
        auto s_b_50_11 = emitter.zx(s_b_50_10, emitter.context().types().u32());
        /* execute.simd:3691 [D] s_b_50_12 = s_b_50_9+s_b_50_11 */
        auto s_b_50_12 = emitter.add(emitter.const_u32(s_b_50_9), s_b_50_11);
        /* execute.simd:3691 [D] s_b_50_13 = ReadRegBank 23:s_b_50_12 (u8) */
        captive::arch::dbt::el::Value *s_b_50_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_50_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_50_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3691 [D] s_b_50_14: WriteRegBank 23:s_b_50_5 = s_b_50_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_50_5))),s_b_50_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_50_5))),s_b_50_13);
        /* execute.simd:3691 [F] s_b_50_15: Jump b_2 (const) */
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
    /* execute.simd:4268 [F] s_b_0_0=sym_39321_3_parameter_inst.sf (const) */
    /* execute.simd:4268 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4268 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4268 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4268 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4269 [F] s_b_1_0=sym_39321_3_parameter_inst.type (const) */
    /* execute.simd:4269 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4269 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4269 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4269 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4276 [F] s_b_3_0=sym_39321_3_parameter_inst.sf (const) */
    /* execute.simd:4276 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4276 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4276 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4276 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_2 (const) */
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
    /* execute.simd:4271 [F] s_b_4_0=sym_39321_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2646 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_4_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_4_5 = ReadRegBank 1:s_b_4_0 (u32) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    captive::arch::dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2659 [D] s_b_4_7 = (u64)s_b_4_6 */
    auto s_b_4_7 = emitter.zx(s_b_4_6, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_4_8=sym_39321_3_parameter_inst.rd (const) */
    /* execute.simd:4271 [D] s_b_4_9 = (u32)s_b_4_7 */
    auto s_b_4_9 = emitter.truncate(s_b_4_7, emitter.context().types().u32());
    /* execute.simd:4271 [D] s_b_4_10 = (f32)s_b_4_9 */
    auto s_b_4_10 = emitter.convert(s_b_4_9, emitter.context().types().f32());
    /* execute.simd:6102 [D] s_b_4_11: WriteRegBank 9:s_b_4_8 = s_b_4_10 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_10,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_10);
    /* execute.simd:6103 [F] s_b_4_12 = constant u32 0 (const) */
    /* execute.simd:6103 [F] s_b_4_13: WriteRegBank 10:s_b_4_8 = s_b_4_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6104 [F] s_b_4_14 = constant u64 0 (const) */
    /* execute.simd:6104 [F] s_b_4_15: WriteRegBank 3:s_b_4_8 = s_b_4_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_16: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4272 [F] s_b_5_0=sym_39321_3_parameter_inst.type (const) */
    /* execute.simd:4272 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4272 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4272 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4272 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
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
    /* execute.simd:4274 [F] s_b_6_0=sym_39321_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2646 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_6_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_6_5 = ReadRegBank 1:s_b_6_0 (u32) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_6_6: Select s_b_6_3 ? s_b_6_4 : s_b_6_5 */
    captive::arch::dbt::el::Value *s_b_6_6;
    s_b_6_6 = (s_b_6_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_6_5);
    /* execute.a64:2659 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_8=sym_39321_3_parameter_inst.rd (const) */
    /* execute.simd:4274 [D] s_b_6_9 = (u32)s_b_6_7 */
    auto s_b_6_9 = emitter.truncate(s_b_6_7, emitter.context().types().u32());
    /* execute.simd:4274 [D] s_b_6_10 = (f64)s_b_6_9 */
    auto s_b_6_10 = emitter.convert(s_b_6_9, emitter.context().types().f64());
    /* execute.simd:6110 [D] s_b_6_11: WriteRegBank 11:s_b_6_8 = s_b_6_10 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_10,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_10);
    /* execute.simd:6111 [F] s_b_6_12 = constant u64 0 (const) */
    /* execute.simd:6111 [F] s_b_6_13: WriteRegBank 3:s_b_6_8 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4277 [F] s_b_7_0=sym_39321_3_parameter_inst.type (const) */
    /* execute.simd:4277 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4277 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4277 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4277 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4279 [F] s_b_8_0=sym_39321_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2651 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_8_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_8_5 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    captive::arch::dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_8_5);
    /* ???:4294967295 [F] s_b_8_7=sym_39321_3_parameter_inst.rd (const) */
    /* execute.simd:4279 [D] s_b_8_8 = (u64)s_b_8_6 */
    auto s_b_8_8 = (captive::arch::dbt::el::Value *)s_b_8_6;
    /* execute.simd:4279 [D] s_b_8_9 = (f32)s_b_8_8 */
    auto s_b_8_9 = emitter.convert(s_b_8_8, emitter.context().types().f32());
    /* execute.simd:6102 [D] s_b_8_10: WriteRegBank 9:s_b_8_7 = s_b_8_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_9,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_9);
    /* execute.simd:6103 [F] s_b_8_11 = constant u32 0 (const) */
    /* execute.simd:6103 [F] s_b_8_12: WriteRegBank 10:s_b_8_7 = s_b_8_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6104 [F] s_b_8_13 = constant u64 0 (const) */
    /* execute.simd:6104 [F] s_b_8_14: WriteRegBank 3:s_b_8_7 = s_b_8_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4280 [F] s_b_9_0=sym_39321_3_parameter_inst.type (const) */
    /* execute.simd:4280 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4280 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4280 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4280 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_2 (const) */
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
    /* execute.simd:4282 [F] s_b_10_0=sym_39321_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2651 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_10_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_10_5 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_10_6: Select s_b_10_3 ? s_b_10_4 : s_b_10_5 */
    captive::arch::dbt::el::Value *s_b_10_6;
    s_b_10_6 = (s_b_10_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_10_5);
    /* ???:4294967295 [F] s_b_10_7=sym_39321_3_parameter_inst.rd (const) */
    /* execute.simd:4282 [D] s_b_10_8 = (u64)s_b_10_6 */
    auto s_b_10_8 = (captive::arch::dbt::el::Value *)s_b_10_6;
    /* execute.simd:4282 [D] s_b_10_9 = (f64)s_b_10_8 */
    auto s_b_10_9 = emitter.convert(s_b_10_8, emitter.context().types().f64());
    /* execute.simd:6110 [D] s_b_10_10: WriteRegBank 11:s_b_10_7 = s_b_10_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_9,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_9);
    /* execute.simd:6111 [F] s_b_10_11 = constant u64 0 (const) */
    /* execute.simd:6111 [F] s_b_10_12: WriteRegBank 3:s_b_10_7 = s_b_10_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
  auto DV_sym_149364_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2422 [F] s_b_0_0=sym_39909_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2651 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_0_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_0_5 = ReadRegBank 0:s_b_0_0 (u64) */
    auto s_b_0_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_0_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_0_6: Select s_b_0_3 ? s_b_0_4 : s_b_0_5 */
    captive::arch::dbt::el::Value *s_b_0_6;
    s_b_0_6 = (s_b_0_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_0_5);
    /* execute.a64:2423 [F] s_b_0_7=sym_39909_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_0_8 = (u32)s_b_0_7 (const) */
    /* execute.a64:2651 [F] s_b_0_9 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_0_10 = s_b_0_8==s_b_0_9 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_0_11 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_0_12 = ReadRegBank 0:s_b_0_7 (u64) */
    auto s_b_0_12 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_0_12,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_0_13: Select s_b_0_10 ? s_b_0_11 : s_b_0_12 */
    captive::arch::dbt::el::Value *s_b_0_13;
    s_b_0_13 = (s_b_0_10) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_0_12);
    /* execute.a64:2425 [D] s_b_0_14 = __builtin_umulh */
    auto s_b_0_14 = emitter.umulh(s_b_0_6, s_b_0_13);
    /* execute.a64:2691 [F] s_b_0_15=sym_39909_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_0_16: sym_149364_3_parameter_value = s_b_0_14, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_149364_3_parameter_value, s_b_0_14);
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
    /* execute.a64:2684 [F] s_b_2_0=sym_39909_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_2_1 = sym_149364_3_parameter_value uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_149364_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_2_2: WriteRegBank 0:s_b_2_0 = s_b_2_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_2_1,emitter.const_u8(8));
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
    /* execute.simd:4971 [F] s_b_0_0=sym_45844_3_parameter_inst.arrangement (const) */
    /* execute.simd:4972 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:4989 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5014 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5027 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5044 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5055 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5068 [F] s_b_0_7 = constant s32 6 (const) */
    /* execute.simd:4971 [F] s_b_0_8: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:4973 [F] s_b_2_0=sym_45844_3_parameter_inst.rn (const) */
    /* execute.simd:4973 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:4974 [F] s_b_2_2=sym_45844_3_parameter_inst.rm (const) */
    /* execute.simd:4974 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:4977 [F] s_b_2_5 = constant s32 1 (const) */
    /* execute.simd:4977 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4977 [F] s_b_2_7 = constant s32 0 (const) */
    /* execute.simd:4977 [D] s_b_2_8 = s_b_2_4[s_b_2_7] <= s_b_2_6 */
    auto s_b_2_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_2_6);
    /* execute.simd:4978 [F] s_b_2_9 = constant s32 3 (const) */
    /* execute.simd:4978 [D] s_b_2_1[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4978 [F] s_b_2_11 = constant s32 1 (const) */
    /* execute.simd:4978 [D] s_b_2_12 = s_b_2_8[s_b_2_11] <= s_b_2_10 */
    auto s_b_2_12 = emitter.vector_insert(s_b_2_8, emitter.const_s32((int32_t)1ULL), s_b_2_10);
    /* execute.simd:4979 [F] s_b_2_13 = constant s32 5 (const) */
    /* execute.simd:4979 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:4979 [F] s_b_2_15 = constant s32 2 (const) */
    /* execute.simd:4979 [D] s_b_2_16 = s_b_2_12[s_b_2_15] <= s_b_2_14 */
    auto s_b_2_16 = emitter.vector_insert(s_b_2_12, emitter.const_s32((int32_t)2ULL), s_b_2_14);
    /* execute.simd:4980 [F] s_b_2_17 = constant s32 7 (const) */
    /* execute.simd:4980 [D] s_b_2_1[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:4980 [F] s_b_2_19 = constant s32 3 (const) */
    /* execute.simd:4980 [D] s_b_2_20 = s_b_2_16[s_b_2_19] <= s_b_2_18 */
    auto s_b_2_20 = emitter.vector_insert(s_b_2_16, emitter.const_s32((int32_t)3ULL), s_b_2_18);
    /* execute.simd:4981 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:4981 [D] s_b_2_3[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4981 [F] s_b_2_23 = constant s32 4 (const) */
    /* execute.simd:4981 [D] s_b_2_24 = s_b_2_20[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_20, emitter.const_s32((int32_t)4ULL), s_b_2_22);
    /* execute.simd:4982 [F] s_b_2_25 = constant s32 3 (const) */
    /* execute.simd:4982 [D] s_b_2_3[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4982 [F] s_b_2_27 = constant s32 5 (const) */
    /* execute.simd:4982 [D] s_b_2_28 = s_b_2_24[s_b_2_27] <= s_b_2_26 */
    auto s_b_2_28 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)5ULL), s_b_2_26);
    /* execute.simd:4983 [F] s_b_2_29 = constant s32 5 (const) */
    /* execute.simd:4983 [D] s_b_2_3[s_b_2_29] */
    auto s_b_2_30 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:4983 [F] s_b_2_31 = constant s32 6 (const) */
    /* execute.simd:4983 [D] s_b_2_32 = s_b_2_28[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_28, emitter.const_s32((int32_t)6ULL), s_b_2_30);
    /* execute.simd:4984 [F] s_b_2_33 = constant s32 7 (const) */
    /* execute.simd:4984 [D] s_b_2_3[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:4984 [F] s_b_2_35 = constant s32 7 (const) */
    /* execute.simd:4984 [D] s_b_2_36 = s_b_2_32[s_b_2_35] <= s_b_2_34 */
    auto s_b_2_36 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)7ULL), s_b_2_34);
    /* execute.simd:4986 [F] s_b_2_37=sym_45844_3_parameter_inst.rd (const) */
    /* execute.simd:4986 [D] s_b_2_38: WriteRegBank 16:s_b_2_37 = s_b_2_36 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_36,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_36);
    /* execute.simd:0 [F] s_b_2_39: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4990 [F] s_b_3_0=sym_45844_3_parameter_inst.rn (const) */
    /* execute.simd:4990 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:4991 [F] s_b_3_2=sym_45844_3_parameter_inst.rm (const) */
    /* execute.simd:4991 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:4994 [F] s_b_3_5 = constant s32 1 (const) */
    /* execute.simd:4994 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4994 [F] s_b_3_7 = constant s32 0 (const) */
    /* execute.simd:4994 [D] s_b_3_8 = s_b_3_4[s_b_3_7] <= s_b_3_6 */
    auto s_b_3_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_3_6);
    /* execute.simd:4995 [F] s_b_3_9 = constant s32 3 (const) */
    /* execute.simd:4995 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4995 [F] s_b_3_11 = constant s32 1 (const) */
    /* execute.simd:4995 [D] s_b_3_12 = s_b_3_8[s_b_3_11] <= s_b_3_10 */
    auto s_b_3_12 = emitter.vector_insert(s_b_3_8, emitter.const_s32((int32_t)1ULL), s_b_3_10);
    /* execute.simd:4996 [F] s_b_3_13 = constant s32 5 (const) */
    /* execute.simd:4996 [D] s_b_3_1[s_b_3_13] */
    auto s_b_3_14 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:4996 [F] s_b_3_15 = constant s32 2 (const) */
    /* execute.simd:4996 [D] s_b_3_16 = s_b_3_12[s_b_3_15] <= s_b_3_14 */
    auto s_b_3_16 = emitter.vector_insert(s_b_3_12, emitter.const_s32((int32_t)2ULL), s_b_3_14);
    /* execute.simd:4997 [F] s_b_3_17 = constant s32 7 (const) */
    /* execute.simd:4997 [D] s_b_3_1[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:4997 [F] s_b_3_19 = constant s32 3 (const) */
    /* execute.simd:4997 [D] s_b_3_20 = s_b_3_16[s_b_3_19] <= s_b_3_18 */
    auto s_b_3_20 = emitter.vector_insert(s_b_3_16, emitter.const_s32((int32_t)3ULL), s_b_3_18);
    /* execute.simd:4998 [F] s_b_3_21 = constant s32 9 (const) */
    /* execute.simd:4998 [D] s_b_3_1[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)9ULL));
    /* execute.simd:4998 [F] s_b_3_23 = constant s32 4 (const) */
    /* execute.simd:4998 [D] s_b_3_24 = s_b_3_20[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_20, emitter.const_s32((int32_t)4ULL), s_b_3_22);
    /* execute.simd:4999 [F] s_b_3_25 = constant s32 b (const) */
    /* execute.simd:4999 [D] s_b_3_1[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)11ULL));
    /* execute.simd:4999 [F] s_b_3_27 = constant s32 5 (const) */
    /* execute.simd:4999 [D] s_b_3_28 = s_b_3_24[s_b_3_27] <= s_b_3_26 */
    auto s_b_3_28 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)5ULL), s_b_3_26);
    /* execute.simd:5000 [F] s_b_3_29 = constant s32 d (const) */
    /* execute.simd:5000 [D] s_b_3_1[s_b_3_29] */
    auto s_b_3_30 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)13ULL));
    /* execute.simd:5000 [F] s_b_3_31 = constant s32 6 (const) */
    /* execute.simd:5000 [D] s_b_3_32 = s_b_3_28[s_b_3_31] <= s_b_3_30 */
    auto s_b_3_32 = emitter.vector_insert(s_b_3_28, emitter.const_s32((int32_t)6ULL), s_b_3_30);
    /* execute.simd:5001 [F] s_b_3_33 = constant s32 f (const) */
    /* execute.simd:5001 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)15ULL));
    /* execute.simd:5001 [F] s_b_3_35 = constant s32 7 (const) */
    /* execute.simd:5001 [D] s_b_3_36 = s_b_3_32[s_b_3_35] <= s_b_3_34 */
    auto s_b_3_36 = emitter.vector_insert(s_b_3_32, emitter.const_s32((int32_t)7ULL), s_b_3_34);
    /* execute.simd:5002 [F] s_b_3_37 = constant s32 1 (const) */
    /* execute.simd:5002 [D] s_b_3_3[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5002 [F] s_b_3_39 = constant s32 8 (const) */
    /* execute.simd:5002 [D] s_b_3_40 = s_b_3_36[s_b_3_39] <= s_b_3_38 */
    auto s_b_3_40 = emitter.vector_insert(s_b_3_36, emitter.const_s32((int32_t)8ULL), s_b_3_38);
    /* execute.simd:5003 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5003 [D] s_b_3_3[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5003 [F] s_b_3_43 = constant s32 9 (const) */
    /* execute.simd:5003 [D] s_b_3_44 = s_b_3_40[s_b_3_43] <= s_b_3_42 */
    auto s_b_3_44 = emitter.vector_insert(s_b_3_40, emitter.const_s32((int32_t)9ULL), s_b_3_42);
    /* execute.simd:5004 [F] s_b_3_45 = constant s32 5 (const) */
    /* execute.simd:5004 [D] s_b_3_3[s_b_3_45] */
    auto s_b_3_46 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5004 [F] s_b_3_47 = constant s32 a (const) */
    /* execute.simd:5004 [D] s_b_3_48 = s_b_3_44[s_b_3_47] <= s_b_3_46 */
    auto s_b_3_48 = emitter.vector_insert(s_b_3_44, emitter.const_s32((int32_t)10ULL), s_b_3_46);
    /* execute.simd:5005 [F] s_b_3_49 = constant s32 7 (const) */
    /* execute.simd:5005 [D] s_b_3_3[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5005 [F] s_b_3_51 = constant s32 b (const) */
    /* execute.simd:5005 [D] s_b_3_52 = s_b_3_48[s_b_3_51] <= s_b_3_50 */
    auto s_b_3_52 = emitter.vector_insert(s_b_3_48, emitter.const_s32((int32_t)11ULL), s_b_3_50);
    /* execute.simd:5006 [F] s_b_3_53 = constant s32 9 (const) */
    /* execute.simd:5006 [D] s_b_3_3[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)9ULL));
    /* execute.simd:5006 [F] s_b_3_55 = constant s32 c (const) */
    /* execute.simd:5006 [D] s_b_3_56 = s_b_3_52[s_b_3_55] <= s_b_3_54 */
    auto s_b_3_56 = emitter.vector_insert(s_b_3_52, emitter.const_s32((int32_t)12ULL), s_b_3_54);
    /* execute.simd:5007 [F] s_b_3_57 = constant s32 b (const) */
    /* execute.simd:5007 [D] s_b_3_3[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)11ULL));
    /* execute.simd:5007 [F] s_b_3_59 = constant s32 d (const) */
    /* execute.simd:5007 [D] s_b_3_60 = s_b_3_56[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_56, emitter.const_s32((int32_t)13ULL), s_b_3_58);
    /* execute.simd:5008 [F] s_b_3_61 = constant s32 d (const) */
    /* execute.simd:5008 [D] s_b_3_3[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)13ULL));
    /* execute.simd:5008 [F] s_b_3_63 = constant s32 e (const) */
    /* execute.simd:5008 [D] s_b_3_64 = s_b_3_60[s_b_3_63] <= s_b_3_62 */
    auto s_b_3_64 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)14ULL), s_b_3_62);
    /* execute.simd:5009 [F] s_b_3_65 = constant s32 f (const) */
    /* execute.simd:5009 [D] s_b_3_3[s_b_3_65] */
    auto s_b_3_66 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)15ULL));
    /* execute.simd:5009 [F] s_b_3_67 = constant s32 f (const) */
    /* execute.simd:5009 [D] s_b_3_68 = s_b_3_64[s_b_3_67] <= s_b_3_66 */
    auto s_b_3_68 = emitter.vector_insert(s_b_3_64, emitter.const_s32((int32_t)15ULL), s_b_3_66);
    /* execute.simd:5011 [F] s_b_3_69=sym_45844_3_parameter_inst.rd (const) */
    /* execute.simd:5011 [D] s_b_3_70: WriteRegBank 16:s_b_3_69 = s_b_3_68 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_68,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_68);
    /* execute.simd:0 [F] s_b_3_71: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5015 [F] s_b_4_0=sym_45844_3_parameter_inst.rn (const) */
    /* execute.simd:5015 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5016 [F] s_b_4_2=sym_45844_3_parameter_inst.rm (const) */
    /* execute.simd:5016 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5019 [F] s_b_4_5 = constant s32 1 (const) */
    /* execute.simd:5019 [D] s_b_4_1[s_b_4_5] */
    auto s_b_4_6 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5019 [F] s_b_4_7 = constant s32 0 (const) */
    /* execute.simd:5019 [D] s_b_4_8 = s_b_4_4[s_b_4_7] <= s_b_4_6 */
    auto s_b_4_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_4_6);
    /* execute.simd:5020 [F] s_b_4_9 = constant s32 3 (const) */
    /* execute.simd:5020 [D] s_b_4_1[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5020 [F] s_b_4_11 = constant s32 1 (const) */
    /* execute.simd:5020 [D] s_b_4_12 = s_b_4_8[s_b_4_11] <= s_b_4_10 */
    auto s_b_4_12 = emitter.vector_insert(s_b_4_8, emitter.const_s32((int32_t)1ULL), s_b_4_10);
    /* execute.simd:5021 [F] s_b_4_13 = constant s32 1 (const) */
    /* execute.simd:5021 [D] s_b_4_3[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5021 [F] s_b_4_15 = constant s32 2 (const) */
    /* execute.simd:5021 [D] s_b_4_16 = s_b_4_12[s_b_4_15] <= s_b_4_14 */
    auto s_b_4_16 = emitter.vector_insert(s_b_4_12, emitter.const_s32((int32_t)2ULL), s_b_4_14);
    /* execute.simd:5022 [F] s_b_4_17 = constant s32 3 (const) */
    /* execute.simd:5022 [D] s_b_4_3[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5022 [F] s_b_4_19 = constant s32 3 (const) */
    /* execute.simd:5022 [D] s_b_4_20 = s_b_4_16[s_b_4_19] <= s_b_4_18 */
    auto s_b_4_20 = emitter.vector_insert(s_b_4_16, emitter.const_s32((int32_t)3ULL), s_b_4_18);
    /* execute.simd:5024 [F] s_b_4_21=sym_45844_3_parameter_inst.rd (const) */
    /* execute.simd:5024 [D] s_b_4_22: WriteRegBank 18:s_b_4_21 = s_b_4_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_20,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_20);
    /* execute.simd:0 [F] s_b_4_23: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5028 [F] s_b_5_0=sym_45844_3_parameter_inst.rn (const) */
    /* execute.simd:5028 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5029 [F] s_b_5_2=sym_45844_3_parameter_inst.rm (const) */
    /* execute.simd:5029 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5032 [F] s_b_5_5 = constant s32 1 (const) */
    /* execute.simd:5032 [D] s_b_5_1[s_b_5_5] */
    auto s_b_5_6 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5032 [F] s_b_5_7 = constant s32 0 (const) */
    /* execute.simd:5032 [D] s_b_5_8 = s_b_5_4[s_b_5_7] <= s_b_5_6 */
    auto s_b_5_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_5_6);
    /* execute.simd:5033 [F] s_b_5_9 = constant s32 3 (const) */
    /* execute.simd:5033 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5033 [F] s_b_5_11 = constant s32 1 (const) */
    /* execute.simd:5033 [D] s_b_5_12 = s_b_5_8[s_b_5_11] <= s_b_5_10 */
    auto s_b_5_12 = emitter.vector_insert(s_b_5_8, emitter.const_s32((int32_t)1ULL), s_b_5_10);
    /* execute.simd:5034 [F] s_b_5_13 = constant s32 5 (const) */
    /* execute.simd:5034 [D] s_b_5_1[s_b_5_13] */
    auto s_b_5_14 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5034 [F] s_b_5_15 = constant s32 2 (const) */
    /* execute.simd:5034 [D] s_b_5_16 = s_b_5_12[s_b_5_15] <= s_b_5_14 */
    auto s_b_5_16 = emitter.vector_insert(s_b_5_12, emitter.const_s32((int32_t)2ULL), s_b_5_14);
    /* execute.simd:5035 [F] s_b_5_17 = constant s32 7 (const) */
    /* execute.simd:5035 [D] s_b_5_1[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5035 [F] s_b_5_19 = constant s32 3 (const) */
    /* execute.simd:5035 [D] s_b_5_20 = s_b_5_16[s_b_5_19] <= s_b_5_18 */
    auto s_b_5_20 = emitter.vector_insert(s_b_5_16, emitter.const_s32((int32_t)3ULL), s_b_5_18);
    /* execute.simd:5036 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5036 [D] s_b_5_3[s_b_5_21] */
    auto s_b_5_22 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5036 [F] s_b_5_23 = constant s32 4 (const) */
    /* execute.simd:5036 [D] s_b_5_24 = s_b_5_20[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_20, emitter.const_s32((int32_t)4ULL), s_b_5_22);
    /* execute.simd:5037 [F] s_b_5_25 = constant s32 3 (const) */
    /* execute.simd:5037 [D] s_b_5_3[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5037 [F] s_b_5_27 = constant s32 5 (const) */
    /* execute.simd:5037 [D] s_b_5_28 = s_b_5_24[s_b_5_27] <= s_b_5_26 */
    auto s_b_5_28 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)5ULL), s_b_5_26);
    /* execute.simd:5038 [F] s_b_5_29 = constant s32 5 (const) */
    /* execute.simd:5038 [D] s_b_5_3[s_b_5_29] */
    auto s_b_5_30 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:5038 [F] s_b_5_31 = constant s32 6 (const) */
    /* execute.simd:5038 [D] s_b_5_32 = s_b_5_28[s_b_5_31] <= s_b_5_30 */
    auto s_b_5_32 = emitter.vector_insert(s_b_5_28, emitter.const_s32((int32_t)6ULL), s_b_5_30);
    /* execute.simd:5039 [F] s_b_5_33 = constant s32 7 (const) */
    /* execute.simd:5039 [D] s_b_5_3[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:5039 [F] s_b_5_35 = constant s32 7 (const) */
    /* execute.simd:5039 [D] s_b_5_36 = s_b_5_32[s_b_5_35] <= s_b_5_34 */
    auto s_b_5_36 = emitter.vector_insert(s_b_5_32, emitter.const_s32((int32_t)7ULL), s_b_5_34);
    /* execute.simd:5041 [F] s_b_5_37=sym_45844_3_parameter_inst.rd (const) */
    /* execute.simd:5041 [D] s_b_5_38: WriteRegBank 18:s_b_5_37 = s_b_5_36 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_36,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_36);
    /* execute.simd:0 [F] s_b_5_39: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5045 [F] s_b_6_0=sym_45844_3_parameter_inst.rn (const) */
    /* execute.simd:5045 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5046 [F] s_b_6_2=sym_45844_3_parameter_inst.rm (const) */
    /* execute.simd:5046 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5049 [F] s_b_6_5 = constant s32 1 (const) */
    /* execute.simd:5049 [D] s_b_6_1[s_b_6_5] */
    auto s_b_6_6 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5049 [F] s_b_6_7 = constant s32 0 (const) */
    /* execute.simd:5049 [D] s_b_6_8 = s_b_6_4[s_b_6_7] <= s_b_6_6 */
    auto s_b_6_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_6_6);
    /* execute.simd:5050 [F] s_b_6_9 = constant s32 1 (const) */
    /* execute.simd:5050 [D] s_b_6_3[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5050 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:5050 [D] s_b_6_12 = s_b_6_8[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_8, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:5052 [F] s_b_6_13=sym_45844_3_parameter_inst.rd (const) */
    /* execute.simd:5052 [D] s_b_6_14: WriteRegBank 20:s_b_6_13 = s_b_6_12 */
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
    /* execute.simd:5056 [F] s_b_7_0=sym_45844_3_parameter_inst.rn (const) */
    /* execute.simd:5056 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5057 [F] s_b_7_2=sym_45844_3_parameter_inst.rm (const) */
    /* execute.simd:5057 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5060 [F] s_b_7_5 = constant s32 1 (const) */
    /* execute.simd:5060 [D] s_b_7_1[s_b_7_5] */
    auto s_b_7_6 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5060 [F] s_b_7_7 = constant s32 0 (const) */
    /* execute.simd:5060 [D] s_b_7_8 = s_b_7_4[s_b_7_7] <= s_b_7_6 */
    auto s_b_7_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_7_6);
    /* execute.simd:5061 [F] s_b_7_9 = constant s32 3 (const) */
    /* execute.simd:5061 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5061 [F] s_b_7_11 = constant s32 1 (const) */
    /* execute.simd:5061 [D] s_b_7_12 = s_b_7_8[s_b_7_11] <= s_b_7_10 */
    auto s_b_7_12 = emitter.vector_insert(s_b_7_8, emitter.const_s32((int32_t)1ULL), s_b_7_10);
    /* execute.simd:5062 [F] s_b_7_13 = constant s32 1 (const) */
    /* execute.simd:5062 [D] s_b_7_3[s_b_7_13] */
    auto s_b_7_14 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5062 [F] s_b_7_15 = constant s32 2 (const) */
    /* execute.simd:5062 [D] s_b_7_16 = s_b_7_12[s_b_7_15] <= s_b_7_14 */
    auto s_b_7_16 = emitter.vector_insert(s_b_7_12, emitter.const_s32((int32_t)2ULL), s_b_7_14);
    /* execute.simd:5063 [F] s_b_7_17 = constant s32 3 (const) */
    /* execute.simd:5063 [D] s_b_7_3[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5063 [F] s_b_7_19 = constant s32 3 (const) */
    /* execute.simd:5063 [D] s_b_7_20 = s_b_7_16[s_b_7_19] <= s_b_7_18 */
    auto s_b_7_20 = emitter.vector_insert(s_b_7_16, emitter.const_s32((int32_t)3ULL), s_b_7_18);
    /* execute.simd:5065 [F] s_b_7_21=sym_45844_3_parameter_inst.rd (const) */
    /* execute.simd:5065 [D] s_b_7_22: WriteRegBank 20:s_b_7_21 = s_b_7_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_20,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_20);
    /* execute.simd:0 [F] s_b_7_23: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:5069 [F] s_b_8_0=sym_45844_3_parameter_inst.rn (const) */
    /* execute.simd:5069 [D] s_b_8_1 = ReadRegBank 21:s_b_8_0 (v2u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* execute.simd:5070 [F] s_b_8_2=sym_45844_3_parameter_inst.rm (const) */
    /* execute.simd:5070 [D] s_b_8_3 = ReadRegBank 21:s_b_8_2 (v2u64) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_4 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5073 [F] s_b_8_5 = constant s32 1 (const) */
    /* execute.simd:5073 [D] s_b_8_1[s_b_8_5] */
    auto s_b_8_6 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5073 [F] s_b_8_7 = constant s32 0 (const) */
    /* execute.simd:5073 [D] s_b_8_8 = s_b_8_4[s_b_8_7] <= s_b_8_6 */
    auto s_b_8_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_8_6);
    /* execute.simd:5074 [F] s_b_8_9 = constant s32 3 (const) */
    /* execute.simd:5074 [D] s_b_8_3[s_b_8_9] */
    auto s_b_8_10 = emitter.vector_extract(s_b_8_3, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:5074 [F] s_b_8_11 = constant s32 1 (const) */
    /* execute.simd:5074 [D] s_b_8_12 = s_b_8_8[s_b_8_11] <= s_b_8_10 */
    auto s_b_8_12 = emitter.vector_insert(s_b_8_8, emitter.const_s32((int32_t)1ULL), s_b_8_10);
    /* execute.simd:5076 [F] s_b_8_13=sym_45844_3_parameter_inst.rd (const) */
    /* execute.simd:5076 [D] s_b_8_14: WriteRegBank 21:s_b_8_13 = s_b_8_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_12,emitter.const_u8(16));
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
