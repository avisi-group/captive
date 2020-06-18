#include <arm64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::arm64;
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_abs_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3543 [F] s_b_0_0=sym_2449_3_parameter_inst.SCALAR (const) */
    /* execute.simd:3543 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3544 [F] s_b_1_0=sym_2449_3_parameter_inst.rn (const) */
    /* execute.simd:6237 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:3544 [D] s_b_1_2 = (s64)s_b_1_1 */
    auto s_b_1_2 = emitter.reinterpret(s_b_1_1, emitter.context().types().s64());
    /* execute.simd:3545 [F] s_b_1_3=sym_2449_3_parameter_inst.rd (const) */
    /* execute.simd:3545 [D] s_b_1_4 = __builtin_abs64 */
    auto s_b_1_4 = emitter.call(__captive___builtin_abs64, s_b_1_2);
    /* execute.simd:6208 [D] s_b_1_5: WriteRegBank 2:s_b_1_3 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4);
    /* execute.simd:6209 [F] s_b_1_6 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_1_7: WriteRegBank 3:s_b_1_3 = s_b_1_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_5, b_6, b_7, b_8, b_9, b_10, b_11,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:3547 [F] s_b_3_0=sym_2449_3_parameter_inst.arrangement (const) */
    /* execute.simd:3548 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:3559 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:3570 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:3581 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:3592 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:3603 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:3614 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:3547 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_11 (const) -> b_11, b_10, b_9, b_8, b_7, b_6, b_5, b_4,  */
    switch (insn.arrangement) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_10;
      break;
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:3549 [F] s_b_4_0=sym_2449_3_parameter_inst.rn (const) */
    /* execute.simd:3549 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:3549 [D] s_b_4_2 = (v8s8)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_4_3 = constant v16u8 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_4 = constant u8 0 (const) */
    /* execute.simd:3553 [D] s_b_4_2[s_b_4_4] */
    auto s_b_4_5 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3553 [D] s_b_4_6 = (s32)s_b_4_5 */
    auto s_b_4_6 = emitter.sx(s_b_4_5, emitter.context().types().s32());
    /* execute.simd:3553 [D] s_b_4_7 = __builtin_abs32 */
    auto s_b_4_7 = emitter.call(__captive___builtin_abs32, s_b_4_6);
    /* execute.simd:3553 [D] s_b_4_8 = (u8)s_b_4_7 */
    auto s_b_4_8 = emitter.truncate(s_b_4_7, emitter.context().types().u8());
    /* execute.simd:3553 [F] s_b_4_9 = constant s32 0 (const) */
    /* execute.simd:3553 [D] s_b_4_10 = s_b_4_3[s_b_4_9] <= s_b_4_8 */
    auto s_b_4_10 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_4_8);
    /* ???:4294967295 [F] s_b_4_11 = constant u8 1 (const) */
    /* execute.simd:3553 [D] s_b_4_2[s_b_4_11] */
    auto s_b_4_12 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3553 [D] s_b_4_13 = (s32)s_b_4_12 */
    auto s_b_4_13 = emitter.sx(s_b_4_12, emitter.context().types().s32());
    /* execute.simd:3553 [D] s_b_4_14 = __builtin_abs32 */
    auto s_b_4_14 = emitter.call(__captive___builtin_abs32, s_b_4_13);
    /* execute.simd:3553 [D] s_b_4_15 = (u8)s_b_4_14 */
    auto s_b_4_15 = emitter.truncate(s_b_4_14, emitter.context().types().u8());
    /* execute.simd:3553 [F] s_b_4_16 = constant s32 1 (const) */
    /* execute.simd:3553 [D] s_b_4_17 = s_b_4_10[s_b_4_16] <= s_b_4_15 */
    auto s_b_4_17 = emitter.vector_insert(s_b_4_10, emitter.const_s32((int32_t)1ULL), s_b_4_15);
    /* ???:4294967295 [F] s_b_4_18 = constant u8 2 (const) */
    /* execute.simd:3553 [D] s_b_4_2[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3553 [D] s_b_4_20 = (s32)s_b_4_19 */
    auto s_b_4_20 = emitter.sx(s_b_4_19, emitter.context().types().s32());
    /* execute.simd:3553 [D] s_b_4_21 = __builtin_abs32 */
    auto s_b_4_21 = emitter.call(__captive___builtin_abs32, s_b_4_20);
    /* execute.simd:3553 [D] s_b_4_22 = (u8)s_b_4_21 */
    auto s_b_4_22 = emitter.truncate(s_b_4_21, emitter.context().types().u8());
    /* execute.simd:3553 [F] s_b_4_23 = constant s32 2 (const) */
    /* execute.simd:3553 [D] s_b_4_24 = s_b_4_17[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_17, emitter.const_s32((int32_t)2ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 3 (const) */
    /* execute.simd:3553 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3553 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* execute.simd:3553 [D] s_b_4_28 = __builtin_abs32 */
    auto s_b_4_28 = emitter.call(__captive___builtin_abs32, s_b_4_27);
    /* execute.simd:3553 [D] s_b_4_29 = (u8)s_b_4_28 */
    auto s_b_4_29 = emitter.truncate(s_b_4_28, emitter.context().types().u8());
    /* execute.simd:3553 [F] s_b_4_30 = constant s32 3 (const) */
    /* execute.simd:3553 [D] s_b_4_31 = s_b_4_24[s_b_4_30] <= s_b_4_29 */
    auto s_b_4_31 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)3ULL), s_b_4_29);
    /* ???:4294967295 [F] s_b_4_32 = constant u8 4 (const) */
    /* execute.simd:3553 [D] s_b_4_2[s_b_4_32] */
    auto s_b_4_33 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3553 [D] s_b_4_34 = (s32)s_b_4_33 */
    auto s_b_4_34 = emitter.sx(s_b_4_33, emitter.context().types().s32());
    /* execute.simd:3553 [D] s_b_4_35 = __builtin_abs32 */
    auto s_b_4_35 = emitter.call(__captive___builtin_abs32, s_b_4_34);
    /* execute.simd:3553 [D] s_b_4_36 = (u8)s_b_4_35 */
    auto s_b_4_36 = emitter.truncate(s_b_4_35, emitter.context().types().u8());
    /* execute.simd:3553 [F] s_b_4_37 = constant s32 4 (const) */
    /* execute.simd:3553 [D] s_b_4_38 = s_b_4_31[s_b_4_37] <= s_b_4_36 */
    auto s_b_4_38 = emitter.vector_insert(s_b_4_31, emitter.const_s32((int32_t)4ULL), s_b_4_36);
    /* ???:4294967295 [F] s_b_4_39 = constant u8 5 (const) */
    /* execute.simd:3553 [D] s_b_4_2[s_b_4_39] */
    auto s_b_4_40 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3553 [D] s_b_4_41 = (s32)s_b_4_40 */
    auto s_b_4_41 = emitter.sx(s_b_4_40, emitter.context().types().s32());
    /* execute.simd:3553 [D] s_b_4_42 = __builtin_abs32 */
    auto s_b_4_42 = emitter.call(__captive___builtin_abs32, s_b_4_41);
    /* execute.simd:3553 [D] s_b_4_43 = (u8)s_b_4_42 */
    auto s_b_4_43 = emitter.truncate(s_b_4_42, emitter.context().types().u8());
    /* execute.simd:3553 [F] s_b_4_44 = constant s32 5 (const) */
    /* execute.simd:3553 [D] s_b_4_45 = s_b_4_38[s_b_4_44] <= s_b_4_43 */
    auto s_b_4_45 = emitter.vector_insert(s_b_4_38, emitter.const_s32((int32_t)5ULL), s_b_4_43);
    /* ???:4294967295 [F] s_b_4_46 = constant u8 6 (const) */
    /* execute.simd:3553 [D] s_b_4_2[s_b_4_46] */
    auto s_b_4_47 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3553 [D] s_b_4_48 = (s32)s_b_4_47 */
    auto s_b_4_48 = emitter.sx(s_b_4_47, emitter.context().types().s32());
    /* execute.simd:3553 [D] s_b_4_49 = __builtin_abs32 */
    auto s_b_4_49 = emitter.call(__captive___builtin_abs32, s_b_4_48);
    /* execute.simd:3553 [D] s_b_4_50 = (u8)s_b_4_49 */
    auto s_b_4_50 = emitter.truncate(s_b_4_49, emitter.context().types().u8());
    /* execute.simd:3553 [F] s_b_4_51 = constant s32 6 (const) */
    /* execute.simd:3553 [D] s_b_4_52 = s_b_4_45[s_b_4_51] <= s_b_4_50 */
    auto s_b_4_52 = emitter.vector_insert(s_b_4_45, emitter.const_s32((int32_t)6ULL), s_b_4_50);
    /* ???:4294967295 [F] s_b_4_53 = constant u8 7 (const) */
    /* execute.simd:3553 [D] s_b_4_2[s_b_4_53] */
    auto s_b_4_54 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3553 [D] s_b_4_55 = (s32)s_b_4_54 */
    auto s_b_4_55 = emitter.sx(s_b_4_54, emitter.context().types().s32());
    /* execute.simd:3553 [D] s_b_4_56 = __builtin_abs32 */
    auto s_b_4_56 = emitter.call(__captive___builtin_abs32, s_b_4_55);
    /* execute.simd:3553 [D] s_b_4_57 = (u8)s_b_4_56 */
    auto s_b_4_57 = emitter.truncate(s_b_4_56, emitter.context().types().u8());
    /* execute.simd:3553 [F] s_b_4_58 = constant s32 7 (const) */
    /* execute.simd:3553 [D] s_b_4_59 = s_b_4_52[s_b_4_58] <= s_b_4_57 */
    auto s_b_4_59 = emitter.vector_insert(s_b_4_52, emitter.const_s32((int32_t)7ULL), s_b_4_57);
    /* execute.simd:3556 [F] s_b_4_60=sym_2449_3_parameter_inst.rd (const) */
    /* execute.simd:3556 [D] s_b_4_61: WriteRegBank 16:s_b_4_60 = s_b_4_59 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_59,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_59);
    /* execute.simd:0 [F] s_b_4_62: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:3560 [F] s_b_5_0=sym_2449_3_parameter_inst.rn (const) */
    /* execute.simd:3560 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:3560 [D] s_b_5_2 = (v16s8)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_5_3 = constant v16u8 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_5_4 = constant u8 0 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3564 [D] s_b_5_6 = (s32)s_b_5_5 */
    auto s_b_5_6 = emitter.sx(s_b_5_5, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_7 = __builtin_abs32 */
    auto s_b_5_7 = emitter.call(__captive___builtin_abs32, s_b_5_6);
    /* execute.simd:3564 [D] s_b_5_8 = (u8)s_b_5_7 */
    auto s_b_5_8 = emitter.truncate(s_b_5_7, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_9 = constant s32 0 (const) */
    /* execute.simd:3564 [D] s_b_5_10 = s_b_5_3[s_b_5_9] <= s_b_5_8 */
    auto s_b_5_10 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_5_8);
    /* ???:4294967295 [F] s_b_5_11 = constant u8 1 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_11] */
    auto s_b_5_12 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3564 [D] s_b_5_13 = (s32)s_b_5_12 */
    auto s_b_5_13 = emitter.sx(s_b_5_12, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_14 = __builtin_abs32 */
    auto s_b_5_14 = emitter.call(__captive___builtin_abs32, s_b_5_13);
    /* execute.simd:3564 [D] s_b_5_15 = (u8)s_b_5_14 */
    auto s_b_5_15 = emitter.truncate(s_b_5_14, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_16 = constant s32 1 (const) */
    /* execute.simd:3564 [D] s_b_5_17 = s_b_5_10[s_b_5_16] <= s_b_5_15 */
    auto s_b_5_17 = emitter.vector_insert(s_b_5_10, emitter.const_s32((int32_t)1ULL), s_b_5_15);
    /* ???:4294967295 [F] s_b_5_18 = constant u8 2 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_18] */
    auto s_b_5_19 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3564 [D] s_b_5_20 = (s32)s_b_5_19 */
    auto s_b_5_20 = emitter.sx(s_b_5_19, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_21 = __builtin_abs32 */
    auto s_b_5_21 = emitter.call(__captive___builtin_abs32, s_b_5_20);
    /* execute.simd:3564 [D] s_b_5_22 = (u8)s_b_5_21 */
    auto s_b_5_22 = emitter.truncate(s_b_5_21, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_23 = constant s32 2 (const) */
    /* execute.simd:3564 [D] s_b_5_24 = s_b_5_17[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_17, emitter.const_s32((int32_t)2ULL), s_b_5_22);
    /* ???:4294967295 [F] s_b_5_25 = constant u8 3 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3564 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_28 = __builtin_abs32 */
    auto s_b_5_28 = emitter.call(__captive___builtin_abs32, s_b_5_27);
    /* execute.simd:3564 [D] s_b_5_29 = (u8)s_b_5_28 */
    auto s_b_5_29 = emitter.truncate(s_b_5_28, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_30 = constant s32 3 (const) */
    /* execute.simd:3564 [D] s_b_5_31 = s_b_5_24[s_b_5_30] <= s_b_5_29 */
    auto s_b_5_31 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)3ULL), s_b_5_29);
    /* ???:4294967295 [F] s_b_5_32 = constant u8 4 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_32] */
    auto s_b_5_33 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3564 [D] s_b_5_34 = (s32)s_b_5_33 */
    auto s_b_5_34 = emitter.sx(s_b_5_33, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_35 = __builtin_abs32 */
    auto s_b_5_35 = emitter.call(__captive___builtin_abs32, s_b_5_34);
    /* execute.simd:3564 [D] s_b_5_36 = (u8)s_b_5_35 */
    auto s_b_5_36 = emitter.truncate(s_b_5_35, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_37 = constant s32 4 (const) */
    /* execute.simd:3564 [D] s_b_5_38 = s_b_5_31[s_b_5_37] <= s_b_5_36 */
    auto s_b_5_38 = emitter.vector_insert(s_b_5_31, emitter.const_s32((int32_t)4ULL), s_b_5_36);
    /* ???:4294967295 [F] s_b_5_39 = constant u8 5 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_39] */
    auto s_b_5_40 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3564 [D] s_b_5_41 = (s32)s_b_5_40 */
    auto s_b_5_41 = emitter.sx(s_b_5_40, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_42 = __builtin_abs32 */
    auto s_b_5_42 = emitter.call(__captive___builtin_abs32, s_b_5_41);
    /* execute.simd:3564 [D] s_b_5_43 = (u8)s_b_5_42 */
    auto s_b_5_43 = emitter.truncate(s_b_5_42, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_44 = constant s32 5 (const) */
    /* execute.simd:3564 [D] s_b_5_45 = s_b_5_38[s_b_5_44] <= s_b_5_43 */
    auto s_b_5_45 = emitter.vector_insert(s_b_5_38, emitter.const_s32((int32_t)5ULL), s_b_5_43);
    /* ???:4294967295 [F] s_b_5_46 = constant u8 6 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_46] */
    auto s_b_5_47 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3564 [D] s_b_5_48 = (s32)s_b_5_47 */
    auto s_b_5_48 = emitter.sx(s_b_5_47, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_49 = __builtin_abs32 */
    auto s_b_5_49 = emitter.call(__captive___builtin_abs32, s_b_5_48);
    /* execute.simd:3564 [D] s_b_5_50 = (u8)s_b_5_49 */
    auto s_b_5_50 = emitter.truncate(s_b_5_49, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_51 = constant s32 6 (const) */
    /* execute.simd:3564 [D] s_b_5_52 = s_b_5_45[s_b_5_51] <= s_b_5_50 */
    auto s_b_5_52 = emitter.vector_insert(s_b_5_45, emitter.const_s32((int32_t)6ULL), s_b_5_50);
    /* ???:4294967295 [F] s_b_5_53 = constant u8 7 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_53] */
    auto s_b_5_54 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3564 [D] s_b_5_55 = (s32)s_b_5_54 */
    auto s_b_5_55 = emitter.sx(s_b_5_54, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_56 = __builtin_abs32 */
    auto s_b_5_56 = emitter.call(__captive___builtin_abs32, s_b_5_55);
    /* execute.simd:3564 [D] s_b_5_57 = (u8)s_b_5_56 */
    auto s_b_5_57 = emitter.truncate(s_b_5_56, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_58 = constant s32 7 (const) */
    /* execute.simd:3564 [D] s_b_5_59 = s_b_5_52[s_b_5_58] <= s_b_5_57 */
    auto s_b_5_59 = emitter.vector_insert(s_b_5_52, emitter.const_s32((int32_t)7ULL), s_b_5_57);
    /* ???:4294967295 [F] s_b_5_60 = constant u8 8 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_60] */
    auto s_b_5_61 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)8ULL));
    /* execute.simd:3564 [D] s_b_5_62 = (s32)s_b_5_61 */
    auto s_b_5_62 = emitter.sx(s_b_5_61, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_63 = __builtin_abs32 */
    auto s_b_5_63 = emitter.call(__captive___builtin_abs32, s_b_5_62);
    /* execute.simd:3564 [D] s_b_5_64 = (u8)s_b_5_63 */
    auto s_b_5_64 = emitter.truncate(s_b_5_63, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_65 = constant s32 8 (const) */
    /* execute.simd:3564 [D] s_b_5_66 = s_b_5_59[s_b_5_65] <= s_b_5_64 */
    auto s_b_5_66 = emitter.vector_insert(s_b_5_59, emitter.const_s32((int32_t)8ULL), s_b_5_64);
    /* ???:4294967295 [F] s_b_5_67 = constant u8 9 (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_67] */
    auto s_b_5_68 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)9ULL));
    /* execute.simd:3564 [D] s_b_5_69 = (s32)s_b_5_68 */
    auto s_b_5_69 = emitter.sx(s_b_5_68, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_70 = __builtin_abs32 */
    auto s_b_5_70 = emitter.call(__captive___builtin_abs32, s_b_5_69);
    /* execute.simd:3564 [D] s_b_5_71 = (u8)s_b_5_70 */
    auto s_b_5_71 = emitter.truncate(s_b_5_70, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_72 = constant s32 9 (const) */
    /* execute.simd:3564 [D] s_b_5_73 = s_b_5_66[s_b_5_72] <= s_b_5_71 */
    auto s_b_5_73 = emitter.vector_insert(s_b_5_66, emitter.const_s32((int32_t)9ULL), s_b_5_71);
    /* ???:4294967295 [F] s_b_5_74 = constant u8 a (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_74] */
    auto s_b_5_75 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)10ULL));
    /* execute.simd:3564 [D] s_b_5_76 = (s32)s_b_5_75 */
    auto s_b_5_76 = emitter.sx(s_b_5_75, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_77 = __builtin_abs32 */
    auto s_b_5_77 = emitter.call(__captive___builtin_abs32, s_b_5_76);
    /* execute.simd:3564 [D] s_b_5_78 = (u8)s_b_5_77 */
    auto s_b_5_78 = emitter.truncate(s_b_5_77, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_79 = constant s32 a (const) */
    /* execute.simd:3564 [D] s_b_5_80 = s_b_5_73[s_b_5_79] <= s_b_5_78 */
    auto s_b_5_80 = emitter.vector_insert(s_b_5_73, emitter.const_s32((int32_t)10ULL), s_b_5_78);
    /* ???:4294967295 [F] s_b_5_81 = constant u8 b (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_81] */
    auto s_b_5_82 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)11ULL));
    /* execute.simd:3564 [D] s_b_5_83 = (s32)s_b_5_82 */
    auto s_b_5_83 = emitter.sx(s_b_5_82, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_84 = __builtin_abs32 */
    auto s_b_5_84 = emitter.call(__captive___builtin_abs32, s_b_5_83);
    /* execute.simd:3564 [D] s_b_5_85 = (u8)s_b_5_84 */
    auto s_b_5_85 = emitter.truncate(s_b_5_84, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_86 = constant s32 b (const) */
    /* execute.simd:3564 [D] s_b_5_87 = s_b_5_80[s_b_5_86] <= s_b_5_85 */
    auto s_b_5_87 = emitter.vector_insert(s_b_5_80, emitter.const_s32((int32_t)11ULL), s_b_5_85);
    /* ???:4294967295 [F] s_b_5_88 = constant u8 c (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_88] */
    auto s_b_5_89 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)12ULL));
    /* execute.simd:3564 [D] s_b_5_90 = (s32)s_b_5_89 */
    auto s_b_5_90 = emitter.sx(s_b_5_89, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_91 = __builtin_abs32 */
    auto s_b_5_91 = emitter.call(__captive___builtin_abs32, s_b_5_90);
    /* execute.simd:3564 [D] s_b_5_92 = (u8)s_b_5_91 */
    auto s_b_5_92 = emitter.truncate(s_b_5_91, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_93 = constant s32 c (const) */
    /* execute.simd:3564 [D] s_b_5_94 = s_b_5_87[s_b_5_93] <= s_b_5_92 */
    auto s_b_5_94 = emitter.vector_insert(s_b_5_87, emitter.const_s32((int32_t)12ULL), s_b_5_92);
    /* ???:4294967295 [F] s_b_5_95 = constant u8 d (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_95] */
    auto s_b_5_96 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)13ULL));
    /* execute.simd:3564 [D] s_b_5_97 = (s32)s_b_5_96 */
    auto s_b_5_97 = emitter.sx(s_b_5_96, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_98 = __builtin_abs32 */
    auto s_b_5_98 = emitter.call(__captive___builtin_abs32, s_b_5_97);
    /* execute.simd:3564 [D] s_b_5_99 = (u8)s_b_5_98 */
    auto s_b_5_99 = emitter.truncate(s_b_5_98, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_100 = constant s32 d (const) */
    /* execute.simd:3564 [D] s_b_5_101 = s_b_5_94[s_b_5_100] <= s_b_5_99 */
    auto s_b_5_101 = emitter.vector_insert(s_b_5_94, emitter.const_s32((int32_t)13ULL), s_b_5_99);
    /* ???:4294967295 [F] s_b_5_102 = constant u8 e (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_102] */
    auto s_b_5_103 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)14ULL));
    /* execute.simd:3564 [D] s_b_5_104 = (s32)s_b_5_103 */
    auto s_b_5_104 = emitter.sx(s_b_5_103, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_105 = __builtin_abs32 */
    auto s_b_5_105 = emitter.call(__captive___builtin_abs32, s_b_5_104);
    /* execute.simd:3564 [D] s_b_5_106 = (u8)s_b_5_105 */
    auto s_b_5_106 = emitter.truncate(s_b_5_105, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_107 = constant s32 e (const) */
    /* execute.simd:3564 [D] s_b_5_108 = s_b_5_101[s_b_5_107] <= s_b_5_106 */
    auto s_b_5_108 = emitter.vector_insert(s_b_5_101, emitter.const_s32((int32_t)14ULL), s_b_5_106);
    /* ???:4294967295 [F] s_b_5_109 = constant u8 f (const) */
    /* execute.simd:3564 [D] s_b_5_2[s_b_5_109] */
    auto s_b_5_110 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)15ULL));
    /* execute.simd:3564 [D] s_b_5_111 = (s32)s_b_5_110 */
    auto s_b_5_111 = emitter.sx(s_b_5_110, emitter.context().types().s32());
    /* execute.simd:3564 [D] s_b_5_112 = __builtin_abs32 */
    auto s_b_5_112 = emitter.call(__captive___builtin_abs32, s_b_5_111);
    /* execute.simd:3564 [D] s_b_5_113 = (u8)s_b_5_112 */
    auto s_b_5_113 = emitter.truncate(s_b_5_112, emitter.context().types().u8());
    /* execute.simd:3564 [F] s_b_5_114 = constant s32 f (const) */
    /* execute.simd:3564 [D] s_b_5_115 = s_b_5_108[s_b_5_114] <= s_b_5_113 */
    auto s_b_5_115 = emitter.vector_insert(s_b_5_108, emitter.const_s32((int32_t)15ULL), s_b_5_113);
    /* execute.simd:3567 [F] s_b_5_116=sym_2449_3_parameter_inst.rd (const) */
    /* execute.simd:3567 [D] s_b_5_117: WriteRegBank 16:s_b_5_116 = s_b_5_115 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_115,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_115);
    /* execute.simd:0 [F] s_b_5_118: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:3571 [F] s_b_6_0=sym_2449_3_parameter_inst.rn (const) */
    /* execute.simd:3571 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:3571 [D] s_b_6_2 = (v4s16)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_6_3 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_4 = constant u8 0 (const) */
    /* execute.simd:3575 [D] s_b_6_2[s_b_6_4] */
    auto s_b_6_5 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3575 [D] s_b_6_6 = (s32)s_b_6_5 */
    auto s_b_6_6 = emitter.sx(s_b_6_5, emitter.context().types().s32());
    /* execute.simd:3575 [D] s_b_6_7 = __builtin_abs32 */
    auto s_b_6_7 = emitter.call(__captive___builtin_abs32, s_b_6_6);
    /* execute.simd:3575 [D] s_b_6_8 = (u16)s_b_6_7 */
    auto s_b_6_8 = emitter.truncate(s_b_6_7, emitter.context().types().u16());
    /* execute.simd:3575 [F] s_b_6_9 = constant s32 0 (const) */
    /* execute.simd:3575 [D] s_b_6_10 = s_b_6_3[s_b_6_9] <= s_b_6_8 */
    auto s_b_6_10 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_6_8);
    /* ???:4294967295 [F] s_b_6_11 = constant u8 1 (const) */
    /* execute.simd:3575 [D] s_b_6_2[s_b_6_11] */
    auto s_b_6_12 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3575 [D] s_b_6_13 = (s32)s_b_6_12 */
    auto s_b_6_13 = emitter.sx(s_b_6_12, emitter.context().types().s32());
    /* execute.simd:3575 [D] s_b_6_14 = __builtin_abs32 */
    auto s_b_6_14 = emitter.call(__captive___builtin_abs32, s_b_6_13);
    /* execute.simd:3575 [D] s_b_6_15 = (u16)s_b_6_14 */
    auto s_b_6_15 = emitter.truncate(s_b_6_14, emitter.context().types().u16());
    /* execute.simd:3575 [F] s_b_6_16 = constant s32 1 (const) */
    /* execute.simd:3575 [D] s_b_6_17 = s_b_6_10[s_b_6_16] <= s_b_6_15 */
    auto s_b_6_17 = emitter.vector_insert(s_b_6_10, emitter.const_s32((int32_t)1ULL), s_b_6_15);
    /* ???:4294967295 [F] s_b_6_18 = constant u8 2 (const) */
    /* execute.simd:3575 [D] s_b_6_2[s_b_6_18] */
    auto s_b_6_19 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3575 [D] s_b_6_20 = (s32)s_b_6_19 */
    auto s_b_6_20 = emitter.sx(s_b_6_19, emitter.context().types().s32());
    /* execute.simd:3575 [D] s_b_6_21 = __builtin_abs32 */
    auto s_b_6_21 = emitter.call(__captive___builtin_abs32, s_b_6_20);
    /* execute.simd:3575 [D] s_b_6_22 = (u16)s_b_6_21 */
    auto s_b_6_22 = emitter.truncate(s_b_6_21, emitter.context().types().u16());
    /* execute.simd:3575 [F] s_b_6_23 = constant s32 2 (const) */
    /* execute.simd:3575 [D] s_b_6_24 = s_b_6_17[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_17, emitter.const_s32((int32_t)2ULL), s_b_6_22);
    /* ???:4294967295 [F] s_b_6_25 = constant u8 3 (const) */
    /* execute.simd:3575 [D] s_b_6_2[s_b_6_25] */
    auto s_b_6_26 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3575 [D] s_b_6_27 = (s32)s_b_6_26 */
    auto s_b_6_27 = emitter.sx(s_b_6_26, emitter.context().types().s32());
    /* execute.simd:3575 [D] s_b_6_28 = __builtin_abs32 */
    auto s_b_6_28 = emitter.call(__captive___builtin_abs32, s_b_6_27);
    /* execute.simd:3575 [D] s_b_6_29 = (u16)s_b_6_28 */
    auto s_b_6_29 = emitter.truncate(s_b_6_28, emitter.context().types().u16());
    /* execute.simd:3575 [F] s_b_6_30 = constant s32 3 (const) */
    /* execute.simd:3575 [D] s_b_6_31 = s_b_6_24[s_b_6_30] <= s_b_6_29 */
    auto s_b_6_31 = emitter.vector_insert(s_b_6_24, emitter.const_s32((int32_t)3ULL), s_b_6_29);
    /* execute.simd:3578 [F] s_b_6_32=sym_2449_3_parameter_inst.rd (const) */
    /* execute.simd:3578 [D] s_b_6_33: WriteRegBank 18:s_b_6_32 = s_b_6_31 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_31,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_31);
    /* execute.simd:0 [F] s_b_6_34: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:3582 [F] s_b_7_0=sym_2449_3_parameter_inst.rn (const) */
    /* execute.simd:3582 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:3582 [D] s_b_7_2 = (v8s16)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_7_3 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_7_4 = constant u8 0 (const) */
    /* execute.simd:3586 [D] s_b_7_2[s_b_7_4] */
    auto s_b_7_5 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3586 [D] s_b_7_6 = (s32)s_b_7_5 */
    auto s_b_7_6 = emitter.sx(s_b_7_5, emitter.context().types().s32());
    /* execute.simd:3586 [D] s_b_7_7 = __builtin_abs32 */
    auto s_b_7_7 = emitter.call(__captive___builtin_abs32, s_b_7_6);
    /* execute.simd:3586 [D] s_b_7_8 = (u16)s_b_7_7 */
    auto s_b_7_8 = emitter.truncate(s_b_7_7, emitter.context().types().u16());
    /* execute.simd:3586 [F] s_b_7_9 = constant s32 0 (const) */
    /* execute.simd:3586 [D] s_b_7_10 = s_b_7_3[s_b_7_9] <= s_b_7_8 */
    auto s_b_7_10 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_7_8);
    /* ???:4294967295 [F] s_b_7_11 = constant u8 1 (const) */
    /* execute.simd:3586 [D] s_b_7_2[s_b_7_11] */
    auto s_b_7_12 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3586 [D] s_b_7_13 = (s32)s_b_7_12 */
    auto s_b_7_13 = emitter.sx(s_b_7_12, emitter.context().types().s32());
    /* execute.simd:3586 [D] s_b_7_14 = __builtin_abs32 */
    auto s_b_7_14 = emitter.call(__captive___builtin_abs32, s_b_7_13);
    /* execute.simd:3586 [D] s_b_7_15 = (u16)s_b_7_14 */
    auto s_b_7_15 = emitter.truncate(s_b_7_14, emitter.context().types().u16());
    /* execute.simd:3586 [F] s_b_7_16 = constant s32 1 (const) */
    /* execute.simd:3586 [D] s_b_7_17 = s_b_7_10[s_b_7_16] <= s_b_7_15 */
    auto s_b_7_17 = emitter.vector_insert(s_b_7_10, emitter.const_s32((int32_t)1ULL), s_b_7_15);
    /* ???:4294967295 [F] s_b_7_18 = constant u8 2 (const) */
    /* execute.simd:3586 [D] s_b_7_2[s_b_7_18] */
    auto s_b_7_19 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3586 [D] s_b_7_20 = (s32)s_b_7_19 */
    auto s_b_7_20 = emitter.sx(s_b_7_19, emitter.context().types().s32());
    /* execute.simd:3586 [D] s_b_7_21 = __builtin_abs32 */
    auto s_b_7_21 = emitter.call(__captive___builtin_abs32, s_b_7_20);
    /* execute.simd:3586 [D] s_b_7_22 = (u16)s_b_7_21 */
    auto s_b_7_22 = emitter.truncate(s_b_7_21, emitter.context().types().u16());
    /* execute.simd:3586 [F] s_b_7_23 = constant s32 2 (const) */
    /* execute.simd:3586 [D] s_b_7_24 = s_b_7_17[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_17, emitter.const_s32((int32_t)2ULL), s_b_7_22);
    /* ???:4294967295 [F] s_b_7_25 = constant u8 3 (const) */
    /* execute.simd:3586 [D] s_b_7_2[s_b_7_25] */
    auto s_b_7_26 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3586 [D] s_b_7_27 = (s32)s_b_7_26 */
    auto s_b_7_27 = emitter.sx(s_b_7_26, emitter.context().types().s32());
    /* execute.simd:3586 [D] s_b_7_28 = __builtin_abs32 */
    auto s_b_7_28 = emitter.call(__captive___builtin_abs32, s_b_7_27);
    /* execute.simd:3586 [D] s_b_7_29 = (u16)s_b_7_28 */
    auto s_b_7_29 = emitter.truncate(s_b_7_28, emitter.context().types().u16());
    /* execute.simd:3586 [F] s_b_7_30 = constant s32 3 (const) */
    /* execute.simd:3586 [D] s_b_7_31 = s_b_7_24[s_b_7_30] <= s_b_7_29 */
    auto s_b_7_31 = emitter.vector_insert(s_b_7_24, emitter.const_s32((int32_t)3ULL), s_b_7_29);
    /* ???:4294967295 [F] s_b_7_32 = constant u8 4 (const) */
    /* execute.simd:3586 [D] s_b_7_2[s_b_7_32] */
    auto s_b_7_33 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3586 [D] s_b_7_34 = (s32)s_b_7_33 */
    auto s_b_7_34 = emitter.sx(s_b_7_33, emitter.context().types().s32());
    /* execute.simd:3586 [D] s_b_7_35 = __builtin_abs32 */
    auto s_b_7_35 = emitter.call(__captive___builtin_abs32, s_b_7_34);
    /* execute.simd:3586 [D] s_b_7_36 = (u16)s_b_7_35 */
    auto s_b_7_36 = emitter.truncate(s_b_7_35, emitter.context().types().u16());
    /* execute.simd:3586 [F] s_b_7_37 = constant s32 4 (const) */
    /* execute.simd:3586 [D] s_b_7_38 = s_b_7_31[s_b_7_37] <= s_b_7_36 */
    auto s_b_7_38 = emitter.vector_insert(s_b_7_31, emitter.const_s32((int32_t)4ULL), s_b_7_36);
    /* ???:4294967295 [F] s_b_7_39 = constant u8 5 (const) */
    /* execute.simd:3586 [D] s_b_7_2[s_b_7_39] */
    auto s_b_7_40 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3586 [D] s_b_7_41 = (s32)s_b_7_40 */
    auto s_b_7_41 = emitter.sx(s_b_7_40, emitter.context().types().s32());
    /* execute.simd:3586 [D] s_b_7_42 = __builtin_abs32 */
    auto s_b_7_42 = emitter.call(__captive___builtin_abs32, s_b_7_41);
    /* execute.simd:3586 [D] s_b_7_43 = (u16)s_b_7_42 */
    auto s_b_7_43 = emitter.truncate(s_b_7_42, emitter.context().types().u16());
    /* execute.simd:3586 [F] s_b_7_44 = constant s32 5 (const) */
    /* execute.simd:3586 [D] s_b_7_45 = s_b_7_38[s_b_7_44] <= s_b_7_43 */
    auto s_b_7_45 = emitter.vector_insert(s_b_7_38, emitter.const_s32((int32_t)5ULL), s_b_7_43);
    /* ???:4294967295 [F] s_b_7_46 = constant u8 6 (const) */
    /* execute.simd:3586 [D] s_b_7_2[s_b_7_46] */
    auto s_b_7_47 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3586 [D] s_b_7_48 = (s32)s_b_7_47 */
    auto s_b_7_48 = emitter.sx(s_b_7_47, emitter.context().types().s32());
    /* execute.simd:3586 [D] s_b_7_49 = __builtin_abs32 */
    auto s_b_7_49 = emitter.call(__captive___builtin_abs32, s_b_7_48);
    /* execute.simd:3586 [D] s_b_7_50 = (u16)s_b_7_49 */
    auto s_b_7_50 = emitter.truncate(s_b_7_49, emitter.context().types().u16());
    /* execute.simd:3586 [F] s_b_7_51 = constant s32 6 (const) */
    /* execute.simd:3586 [D] s_b_7_52 = s_b_7_45[s_b_7_51] <= s_b_7_50 */
    auto s_b_7_52 = emitter.vector_insert(s_b_7_45, emitter.const_s32((int32_t)6ULL), s_b_7_50);
    /* ???:4294967295 [F] s_b_7_53 = constant u8 7 (const) */
    /* execute.simd:3586 [D] s_b_7_2[s_b_7_53] */
    auto s_b_7_54 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3586 [D] s_b_7_55 = (s32)s_b_7_54 */
    auto s_b_7_55 = emitter.sx(s_b_7_54, emitter.context().types().s32());
    /* execute.simd:3586 [D] s_b_7_56 = __builtin_abs32 */
    auto s_b_7_56 = emitter.call(__captive___builtin_abs32, s_b_7_55);
    /* execute.simd:3586 [D] s_b_7_57 = (u16)s_b_7_56 */
    auto s_b_7_57 = emitter.truncate(s_b_7_56, emitter.context().types().u16());
    /* execute.simd:3586 [F] s_b_7_58 = constant s32 7 (const) */
    /* execute.simd:3586 [D] s_b_7_59 = s_b_7_52[s_b_7_58] <= s_b_7_57 */
    auto s_b_7_59 = emitter.vector_insert(s_b_7_52, emitter.const_s32((int32_t)7ULL), s_b_7_57);
    /* execute.simd:3589 [F] s_b_7_60=sym_2449_3_parameter_inst.rd (const) */
    /* execute.simd:3589 [D] s_b_7_61: WriteRegBank 18:s_b_7_60 = s_b_7_59 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_59,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_59);
    /* execute.simd:0 [F] s_b_7_62: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:3593 [F] s_b_8_0=sym_2449_3_parameter_inst.rn (const) */
    /* execute.simd:3593 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:3593 [D] s_b_8_2 = (v2s32)s_b_8_1 */
    auto s_b_8_2 = emitter.reinterpret(s_b_8_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_8_3 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_8_4 = constant u8 0 (const) */
    /* execute.simd:3597 [D] s_b_8_2[s_b_8_4] */
    auto s_b_8_5 = emitter.vector_extract(s_b_8_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3597 [D] s_b_8_6 = __builtin_abs32 */
    auto s_b_8_6 = emitter.call(__captive___builtin_abs32, s_b_8_5);
    /* execute.simd:3597 [F] s_b_8_7 = constant s32 0 (const) */
    /* execute.simd:3597 [D] s_b_8_8 = s_b_8_3[s_b_8_7] <= s_b_8_6 */
    auto s_b_8_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_8_6);
    /* ???:4294967295 [F] s_b_8_9 = constant u8 1 (const) */
    /* execute.simd:3597 [D] s_b_8_2[s_b_8_9] */
    auto s_b_8_10 = emitter.vector_extract(s_b_8_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3597 [D] s_b_8_11 = __builtin_abs32 */
    auto s_b_8_11 = emitter.call(__captive___builtin_abs32, s_b_8_10);
    /* execute.simd:3597 [F] s_b_8_12 = constant s32 1 (const) */
    /* execute.simd:3597 [D] s_b_8_13 = s_b_8_8[s_b_8_12] <= s_b_8_11 */
    auto s_b_8_13 = emitter.vector_insert(s_b_8_8, emitter.const_s32((int32_t)1ULL), s_b_8_11);
    /* execute.simd:3600 [F] s_b_8_14=sym_2449_3_parameter_inst.rd (const) */
    /* execute.simd:3600 [D] s_b_8_15: WriteRegBank 20:s_b_8_14 = s_b_8_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_13,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_13);
    /* execute.simd:0 [F] s_b_8_16: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3604 [F] s_b_9_0=sym_2449_3_parameter_inst.rn (const) */
    /* execute.simd:3604 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:3604 [D] s_b_9_2 = (v4s32)s_b_9_1 */
    auto s_b_9_2 = emitter.reinterpret(s_b_9_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_9_3 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_9_4 = constant u8 0 (const) */
    /* execute.simd:3608 [D] s_b_9_2[s_b_9_4] */
    auto s_b_9_5 = emitter.vector_extract(s_b_9_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3608 [D] s_b_9_6 = __builtin_abs32 */
    auto s_b_9_6 = emitter.call(__captive___builtin_abs32, s_b_9_5);
    /* execute.simd:3608 [F] s_b_9_7 = constant s32 0 (const) */
    /* execute.simd:3608 [D] s_b_9_8 = s_b_9_3[s_b_9_7] <= s_b_9_6 */
    auto s_b_9_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_9_6);
    /* ???:4294967295 [F] s_b_9_9 = constant u8 1 (const) */
    /* execute.simd:3608 [D] s_b_9_2[s_b_9_9] */
    auto s_b_9_10 = emitter.vector_extract(s_b_9_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3608 [D] s_b_9_11 = __builtin_abs32 */
    auto s_b_9_11 = emitter.call(__captive___builtin_abs32, s_b_9_10);
    /* execute.simd:3608 [F] s_b_9_12 = constant s32 1 (const) */
    /* execute.simd:3608 [D] s_b_9_13 = s_b_9_8[s_b_9_12] <= s_b_9_11 */
    auto s_b_9_13 = emitter.vector_insert(s_b_9_8, emitter.const_s32((int32_t)1ULL), s_b_9_11);
    /* ???:4294967295 [F] s_b_9_14 = constant u8 2 (const) */
    /* execute.simd:3608 [D] s_b_9_2[s_b_9_14] */
    auto s_b_9_15 = emitter.vector_extract(s_b_9_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3608 [D] s_b_9_16 = __builtin_abs32 */
    auto s_b_9_16 = emitter.call(__captive___builtin_abs32, s_b_9_15);
    /* execute.simd:3608 [F] s_b_9_17 = constant s32 2 (const) */
    /* execute.simd:3608 [D] s_b_9_18 = s_b_9_13[s_b_9_17] <= s_b_9_16 */
    auto s_b_9_18 = emitter.vector_insert(s_b_9_13, emitter.const_s32((int32_t)2ULL), s_b_9_16);
    /* ???:4294967295 [F] s_b_9_19 = constant u8 3 (const) */
    /* execute.simd:3608 [D] s_b_9_2[s_b_9_19] */
    auto s_b_9_20 = emitter.vector_extract(s_b_9_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3608 [D] s_b_9_21 = __builtin_abs32 */
    auto s_b_9_21 = emitter.call(__captive___builtin_abs32, s_b_9_20);
    /* execute.simd:3608 [F] s_b_9_22 = constant s32 3 (const) */
    /* execute.simd:3608 [D] s_b_9_23 = s_b_9_18[s_b_9_22] <= s_b_9_21 */
    auto s_b_9_23 = emitter.vector_insert(s_b_9_18, emitter.const_s32((int32_t)3ULL), s_b_9_21);
    /* execute.simd:3611 [F] s_b_9_24=sym_2449_3_parameter_inst.rd (const) */
    /* execute.simd:3611 [D] s_b_9_25: WriteRegBank 20:s_b_9_24 = s_b_9_23 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_23,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_23);
    /* execute.simd:0 [F] s_b_9_26: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3615 [F] s_b_10_0=sym_2449_3_parameter_inst.rn (const) */
    /* execute.simd:3615 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:3615 [D] s_b_10_2 = (v2s64)s_b_10_1 */
    auto s_b_10_2 = emitter.reinterpret(s_b_10_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_10_3 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_10_4 = constant u8 0 (const) */
    /* execute.simd:3619 [D] s_b_10_2[s_b_10_4] */
    auto s_b_10_5 = emitter.vector_extract(s_b_10_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3619 [D] s_b_10_6 = __builtin_abs64 */
    auto s_b_10_6 = emitter.call(__captive___builtin_abs64, s_b_10_5);
    /* execute.simd:3619 [F] s_b_10_7 = constant s32 0 (const) */
    /* execute.simd:3619 [D] s_b_10_8 = s_b_10_3[s_b_10_7] <= s_b_10_6 */
    auto s_b_10_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_10_6);
    /* ???:4294967295 [F] s_b_10_9 = constant u8 1 (const) */
    /* execute.simd:3619 [D] s_b_10_2[s_b_10_9] */
    auto s_b_10_10 = emitter.vector_extract(s_b_10_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3619 [D] s_b_10_11 = __builtin_abs64 */
    auto s_b_10_11 = emitter.call(__captive___builtin_abs64, s_b_10_10);
    /* execute.simd:3619 [F] s_b_10_12 = constant s32 1 (const) */
    /* execute.simd:3619 [D] s_b_10_13 = s_b_10_8[s_b_10_12] <= s_b_10_11 */
    auto s_b_10_13 = emitter.vector_insert(s_b_10_8, emitter.const_s32((int32_t)1ULL), s_b_10_11);
    /* execute.simd:3622 [F] s_b_10_14=sym_2449_3_parameter_inst.rd (const) */
    /* execute.simd:3622 [D] s_b_10_15: WriteRegBank 21:s_b_10_14 = s_b_10_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_13,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_13);
    /* execute.simd:0 [F] s_b_10_16: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3626 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_11_1: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_addv(const arm64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_5212_0_total;
  auto DV_sym_5212_0_total = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:162 [F] s_b_0_0 = constant u64 0 (const) */
    /* execute.simd:162 [F] s_b_0_1: sym_5212_0_total = s_b_0_0 (const), dominates: s_b_13_1 s_b_12_1 s_b_11_1 s_b_7_2 s_b_5_2 s_b_4_2 s_b_3_2 s_b_2_2  */
    CV_sym_5212_0_total = (uint64_t)0ULL;
    emitter.store_local(DV_sym_5212_0_total, emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:164 [F] s_b_0_2=sym_5209_3_parameter_inst.arrangement (const) */
    /* execute.simd:165 [F] s_b_0_3 = constant s32 0 (const) */
    /* execute.simd:173 [F] s_b_0_4 = constant s32 1 (const) */
    /* execute.simd:181 [F] s_b_0_5 = constant s32 2 (const) */
    /* execute.simd:189 [F] s_b_0_6 = constant s32 3 (const) */
    /* execute.simd:197 [F] s_b_0_7 = constant s32 4 (const) */
    /* execute.simd:201 [F] s_b_0_8 = constant s32 5 (const) */
    /* execute.simd:209 [F] s_b_0_9 = constant s32 6 (const) */
    /* execute.simd:164 [F] s_b_0_10: Switch s_b_0_2: < <todo> > def b_9 (const) -> b_9, b_8, b_7, b_6, b_5, b_4, b_3, b_2,  */
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
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8, b_9,  */
  fixed_block_b_1: 
  {
    /* execute.simd:219 [F] s_b_1_0=sym_5209_3_parameter_inst.size (const) */
    /* execute.simd:220 [F] s_b_1_1 = constant s32 0 (const) */
    /* execute.simd:224 [F] s_b_1_2 = constant s32 1 (const) */
    /* execute.simd:228 [F] s_b_1_3 = constant s32 2 (const) */
    /* execute.simd:219 [F] s_b_1_4: Switch s_b_1_0: < <todo> > def b_14 (const) -> b_14, b_13, b_12, b_11,  */
    switch (insn.size) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_11;
      break;
    default:
      goto fixed_block_b_14;
    }
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:166 [F] s_b_2_0=sym_5209_3_parameter_inst.rn (const) */
    /* execute.simd:166 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:169 [F] s_b_2_2 = sym_5212_0_total (const) uint64_t */
    uint64_t s_b_2_2 = CV_sym_5212_0_total;
    /* ???:4294967295 [F] s_b_2_3 = constant u8 0 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_2_5 = (u64)s_b_2_4 */
    auto s_b_2_5 = emitter.zx(s_b_2_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_6 = s_b_2_2+s_b_2_5 */
    auto s_b_2_6 = emitter.add(emitter.const_u64(s_b_2_2), s_b_2_5);
    /* execute.simd:169 [D] s_b_2_7: sym_5212_0_total = s_b_2_6, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_2_6);
    /* ???:4294967295 [F] s_b_2_8 = constant u8 1 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_8] */
    auto s_b_2_9 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_2_10 = (u64)s_b_2_9 */
    auto s_b_2_10 = emitter.zx(s_b_2_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_11 = s_b_2_6+s_b_2_10 */
    auto s_b_2_11 = emitter.add(s_b_2_6, s_b_2_10);
    /* execute.simd:169 [D] s_b_2_12: sym_5212_0_total = s_b_2_11, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_2_11);
    /* ???:4294967295 [F] s_b_2_13 = constant u8 2 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_2_15 = (u64)s_b_2_14 */
    auto s_b_2_15 = emitter.zx(s_b_2_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_16 = s_b_2_11+s_b_2_15 */
    auto s_b_2_16 = emitter.add(s_b_2_11, s_b_2_15);
    /* execute.simd:169 [D] s_b_2_17: sym_5212_0_total = s_b_2_16, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_2_16);
    /* ???:4294967295 [F] s_b_2_18 = constant u8 3 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_18] */
    auto s_b_2_19 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_2_20 = (u64)s_b_2_19 */
    auto s_b_2_20 = emitter.zx(s_b_2_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_21 = s_b_2_16+s_b_2_20 */
    auto s_b_2_21 = emitter.add(s_b_2_16, s_b_2_20);
    /* execute.simd:169 [D] s_b_2_22: sym_5212_0_total = s_b_2_21, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_2_21);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 4 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [D] s_b_2_25 = (u64)s_b_2_24 */
    auto s_b_2_25 = emitter.zx(s_b_2_24, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_26 = s_b_2_21+s_b_2_25 */
    auto s_b_2_26 = emitter.add(s_b_2_21, s_b_2_25);
    /* execute.simd:169 [D] s_b_2_27: sym_5212_0_total = s_b_2_26, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_2_26);
    /* ???:4294967295 [F] s_b_2_28 = constant u8 5 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [D] s_b_2_30 = (u64)s_b_2_29 */
    auto s_b_2_30 = emitter.zx(s_b_2_29, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_31 = s_b_2_26+s_b_2_30 */
    auto s_b_2_31 = emitter.add(s_b_2_26, s_b_2_30);
    /* execute.simd:169 [D] s_b_2_32: sym_5212_0_total = s_b_2_31, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_2_31);
    /* ???:4294967295 [F] s_b_2_33 = constant u8 6 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [D] s_b_2_35 = (u64)s_b_2_34 */
    auto s_b_2_35 = emitter.zx(s_b_2_34, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_36 = s_b_2_31+s_b_2_35 */
    auto s_b_2_36 = emitter.add(s_b_2_31, s_b_2_35);
    /* execute.simd:169 [D] s_b_2_37: sym_5212_0_total = s_b_2_36, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_2_36);
    /* ???:4294967295 [F] s_b_2_38 = constant u8 7 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_38] */
    auto s_b_2_39 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [D] s_b_2_40 = (u64)s_b_2_39 */
    auto s_b_2_40 = emitter.zx(s_b_2_39, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_41 = s_b_2_36+s_b_2_40 */
    auto s_b_2_41 = emitter.add(s_b_2_36, s_b_2_40);
    /* execute.simd:169 [D] s_b_2_42: sym_5212_0_total = s_b_2_41, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5212_0_total, s_b_2_41);
    /* execute.simd:0 [F] s_b_2_43: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:174 [F] s_b_3_0=sym_5209_3_parameter_inst.rn (const) */
    /* execute.simd:174 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:177 [F] s_b_3_2 = sym_5212_0_total (const) uint64_t */
    uint64_t s_b_3_2 = CV_sym_5212_0_total;
    /* ???:4294967295 [F] s_b_3_3 = constant u8 0 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_3] */
    auto s_b_3_4 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_3_5 = (u64)s_b_3_4 */
    auto s_b_3_5 = emitter.zx(s_b_3_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_6 = s_b_3_2+s_b_3_5 */
    auto s_b_3_6 = emitter.add(emitter.const_u64(s_b_3_2), s_b_3_5);
    /* execute.simd:177 [D] s_b_3_7: sym_5212_0_total = s_b_3_6, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_6);
    /* ???:4294967295 [F] s_b_3_8 = constant u8 1 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_8] */
    auto s_b_3_9 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_3_10 = (u64)s_b_3_9 */
    auto s_b_3_10 = emitter.zx(s_b_3_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_11 = s_b_3_6+s_b_3_10 */
    auto s_b_3_11 = emitter.add(s_b_3_6, s_b_3_10);
    /* execute.simd:177 [D] s_b_3_12: sym_5212_0_total = s_b_3_11, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_11);
    /* ???:4294967295 [F] s_b_3_13 = constant u8 2 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_13] */
    auto s_b_3_14 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_3_15 = (u64)s_b_3_14 */
    auto s_b_3_15 = emitter.zx(s_b_3_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_16 = s_b_3_11+s_b_3_15 */
    auto s_b_3_16 = emitter.add(s_b_3_11, s_b_3_15);
    /* execute.simd:177 [D] s_b_3_17: sym_5212_0_total = s_b_3_16, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_16);
    /* ???:4294967295 [F] s_b_3_18 = constant u8 3 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_18] */
    auto s_b_3_19 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_3_20 = (u64)s_b_3_19 */
    auto s_b_3_20 = emitter.zx(s_b_3_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_21 = s_b_3_16+s_b_3_20 */
    auto s_b_3_21 = emitter.add(s_b_3_16, s_b_3_20);
    /* execute.simd:177 [D] s_b_3_22: sym_5212_0_total = s_b_3_21, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_21);
    /* ???:4294967295 [F] s_b_3_23 = constant u8 4 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [D] s_b_3_25 = (u64)s_b_3_24 */
    auto s_b_3_25 = emitter.zx(s_b_3_24, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_26 = s_b_3_21+s_b_3_25 */
    auto s_b_3_26 = emitter.add(s_b_3_21, s_b_3_25);
    /* execute.simd:177 [D] s_b_3_27: sym_5212_0_total = s_b_3_26, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_26);
    /* ???:4294967295 [F] s_b_3_28 = constant u8 5 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [D] s_b_3_30 = (u64)s_b_3_29 */
    auto s_b_3_30 = emitter.zx(s_b_3_29, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_31 = s_b_3_26+s_b_3_30 */
    auto s_b_3_31 = emitter.add(s_b_3_26, s_b_3_30);
    /* execute.simd:177 [D] s_b_3_32: sym_5212_0_total = s_b_3_31, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_31);
    /* ???:4294967295 [F] s_b_3_33 = constant u8 6 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [D] s_b_3_35 = (u64)s_b_3_34 */
    auto s_b_3_35 = emitter.zx(s_b_3_34, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_36 = s_b_3_31+s_b_3_35 */
    auto s_b_3_36 = emitter.add(s_b_3_31, s_b_3_35);
    /* execute.simd:177 [D] s_b_3_37: sym_5212_0_total = s_b_3_36, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_36);
    /* ???:4294967295 [F] s_b_3_38 = constant u8 7 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_38] */
    auto s_b_3_39 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [D] s_b_3_40 = (u64)s_b_3_39 */
    auto s_b_3_40 = emitter.zx(s_b_3_39, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_41 = s_b_3_36+s_b_3_40 */
    auto s_b_3_41 = emitter.add(s_b_3_36, s_b_3_40);
    /* execute.simd:177 [D] s_b_3_42: sym_5212_0_total = s_b_3_41, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_41);
    /* ???:4294967295 [F] s_b_3_43 = constant u8 8 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)8ULL));
    /* ???:4294967295 [D] s_b_3_45 = (u64)s_b_3_44 */
    auto s_b_3_45 = emitter.zx(s_b_3_44, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_46 = s_b_3_41+s_b_3_45 */
    auto s_b_3_46 = emitter.add(s_b_3_41, s_b_3_45);
    /* execute.simd:177 [D] s_b_3_47: sym_5212_0_total = s_b_3_46, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_46);
    /* ???:4294967295 [F] s_b_3_48 = constant u8 9 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_48] */
    auto s_b_3_49 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)9ULL));
    /* ???:4294967295 [D] s_b_3_50 = (u64)s_b_3_49 */
    auto s_b_3_50 = emitter.zx(s_b_3_49, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_51 = s_b_3_46+s_b_3_50 */
    auto s_b_3_51 = emitter.add(s_b_3_46, s_b_3_50);
    /* execute.simd:177 [D] s_b_3_52: sym_5212_0_total = s_b_3_51, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_51);
    /* ???:4294967295 [F] s_b_3_53 = constant u8 a (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)10ULL));
    /* ???:4294967295 [D] s_b_3_55 = (u64)s_b_3_54 */
    auto s_b_3_55 = emitter.zx(s_b_3_54, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_56 = s_b_3_51+s_b_3_55 */
    auto s_b_3_56 = emitter.add(s_b_3_51, s_b_3_55);
    /* execute.simd:177 [D] s_b_3_57: sym_5212_0_total = s_b_3_56, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_56);
    /* ???:4294967295 [F] s_b_3_58 = constant u8 b (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_58] */
    auto s_b_3_59 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)11ULL));
    /* ???:4294967295 [D] s_b_3_60 = (u64)s_b_3_59 */
    auto s_b_3_60 = emitter.zx(s_b_3_59, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_61 = s_b_3_56+s_b_3_60 */
    auto s_b_3_61 = emitter.add(s_b_3_56, s_b_3_60);
    /* execute.simd:177 [D] s_b_3_62: sym_5212_0_total = s_b_3_61, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_61);
    /* ???:4294967295 [F] s_b_3_63 = constant u8 c (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_63] */
    auto s_b_3_64 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)12ULL));
    /* ???:4294967295 [D] s_b_3_65 = (u64)s_b_3_64 */
    auto s_b_3_65 = emitter.zx(s_b_3_64, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_66 = s_b_3_61+s_b_3_65 */
    auto s_b_3_66 = emitter.add(s_b_3_61, s_b_3_65);
    /* execute.simd:177 [D] s_b_3_67: sym_5212_0_total = s_b_3_66, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_66);
    /* ???:4294967295 [F] s_b_3_68 = constant u8 d (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_68] */
    auto s_b_3_69 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)13ULL));
    /* ???:4294967295 [D] s_b_3_70 = (u64)s_b_3_69 */
    auto s_b_3_70 = emitter.zx(s_b_3_69, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_71 = s_b_3_66+s_b_3_70 */
    auto s_b_3_71 = emitter.add(s_b_3_66, s_b_3_70);
    /* execute.simd:177 [D] s_b_3_72: sym_5212_0_total = s_b_3_71, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_71);
    /* ???:4294967295 [F] s_b_3_73 = constant u8 e (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)14ULL));
    /* ???:4294967295 [D] s_b_3_75 = (u64)s_b_3_74 */
    auto s_b_3_75 = emitter.zx(s_b_3_74, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_76 = s_b_3_71+s_b_3_75 */
    auto s_b_3_76 = emitter.add(s_b_3_71, s_b_3_75);
    /* execute.simd:177 [D] s_b_3_77: sym_5212_0_total = s_b_3_76, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_76);
    /* ???:4294967295 [F] s_b_3_78 = constant u8 f (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_78] */
    auto s_b_3_79 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)15ULL));
    /* ???:4294967295 [D] s_b_3_80 = (u64)s_b_3_79 */
    auto s_b_3_80 = emitter.zx(s_b_3_79, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_81 = s_b_3_76+s_b_3_80 */
    auto s_b_3_81 = emitter.add(s_b_3_76, s_b_3_80);
    /* execute.simd:177 [D] s_b_3_82: sym_5212_0_total = s_b_3_81, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5212_0_total, s_b_3_81);
    /* execute.simd:0 [F] s_b_3_83: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:182 [F] s_b_4_0=sym_5209_3_parameter_inst.rn (const) */
    /* execute.simd:182 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:185 [F] s_b_4_2 = sym_5212_0_total (const) uint64_t */
    uint64_t s_b_4_2 = CV_sym_5212_0_total;
    /* ???:4294967295 [F] s_b_4_3 = constant u8 0 (const) */
    /* execute.simd:185 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_4_5 = (u64)s_b_4_4 */
    auto s_b_4_5 = emitter.zx(s_b_4_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_6 = s_b_4_2+s_b_4_5 */
    auto s_b_4_6 = emitter.add(emitter.const_u64(s_b_4_2), s_b_4_5);
    /* execute.simd:185 [D] s_b_4_7: sym_5212_0_total = s_b_4_6, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_4_6);
    /* ???:4294967295 [F] s_b_4_8 = constant u8 1 (const) */
    /* execute.simd:185 [D] s_b_4_1[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_4_10 = (u64)s_b_4_9 */
    auto s_b_4_10 = emitter.zx(s_b_4_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_11 = s_b_4_6+s_b_4_10 */
    auto s_b_4_11 = emitter.add(s_b_4_6, s_b_4_10);
    /* execute.simd:185 [D] s_b_4_12: sym_5212_0_total = s_b_4_11, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_4_11);
    /* ???:4294967295 [F] s_b_4_13 = constant u8 2 (const) */
    /* execute.simd:185 [D] s_b_4_1[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_4_15 = (u64)s_b_4_14 */
    auto s_b_4_15 = emitter.zx(s_b_4_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_16 = s_b_4_11+s_b_4_15 */
    auto s_b_4_16 = emitter.add(s_b_4_11, s_b_4_15);
    /* execute.simd:185 [D] s_b_4_17: sym_5212_0_total = s_b_4_16, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_4_16);
    /* ???:4294967295 [F] s_b_4_18 = constant u8 3 (const) */
    /* execute.simd:185 [D] s_b_4_1[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_4_20 = (u64)s_b_4_19 */
    auto s_b_4_20 = emitter.zx(s_b_4_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_21 = s_b_4_16+s_b_4_20 */
    auto s_b_4_21 = emitter.add(s_b_4_16, s_b_4_20);
    /* execute.simd:185 [D] s_b_4_22: sym_5212_0_total = s_b_4_21, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5212_0_total, s_b_4_21);
    /* execute.simd:0 [F] s_b_4_23: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:190 [F] s_b_5_0=sym_5209_3_parameter_inst.rn (const) */
    /* execute.simd:190 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:193 [F] s_b_5_2 = sym_5212_0_total (const) uint64_t */
    uint64_t s_b_5_2 = CV_sym_5212_0_total;
    /* ???:4294967295 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_3] */
    auto s_b_5_4 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_5_5 = (u64)s_b_5_4 */
    auto s_b_5_5 = emitter.zx(s_b_5_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_6 = s_b_5_2+s_b_5_5 */
    auto s_b_5_6 = emitter.add(emitter.const_u64(s_b_5_2), s_b_5_5);
    /* execute.simd:193 [D] s_b_5_7: sym_5212_0_total = s_b_5_6, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_5_6);
    /* ???:4294967295 [F] s_b_5_8 = constant u8 1 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_8] */
    auto s_b_5_9 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_5_10 = (u64)s_b_5_9 */
    auto s_b_5_10 = emitter.zx(s_b_5_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_11 = s_b_5_6+s_b_5_10 */
    auto s_b_5_11 = emitter.add(s_b_5_6, s_b_5_10);
    /* execute.simd:193 [D] s_b_5_12: sym_5212_0_total = s_b_5_11, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_5_11);
    /* ???:4294967295 [F] s_b_5_13 = constant u8 2 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_13] */
    auto s_b_5_14 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_5_15 = (u64)s_b_5_14 */
    auto s_b_5_15 = emitter.zx(s_b_5_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_16 = s_b_5_11+s_b_5_15 */
    auto s_b_5_16 = emitter.add(s_b_5_11, s_b_5_15);
    /* execute.simd:193 [D] s_b_5_17: sym_5212_0_total = s_b_5_16, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_5_16);
    /* ???:4294967295 [F] s_b_5_18 = constant u8 3 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_18] */
    auto s_b_5_19 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_5_20 = (u64)s_b_5_19 */
    auto s_b_5_20 = emitter.zx(s_b_5_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_21 = s_b_5_16+s_b_5_20 */
    auto s_b_5_21 = emitter.add(s_b_5_16, s_b_5_20);
    /* execute.simd:193 [D] s_b_5_22: sym_5212_0_total = s_b_5_21, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_5_21);
    /* ???:4294967295 [F] s_b_5_23 = constant u8 4 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [D] s_b_5_25 = (u64)s_b_5_24 */
    auto s_b_5_25 = emitter.zx(s_b_5_24, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_26 = s_b_5_21+s_b_5_25 */
    auto s_b_5_26 = emitter.add(s_b_5_21, s_b_5_25);
    /* execute.simd:193 [D] s_b_5_27: sym_5212_0_total = s_b_5_26, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_5_26);
    /* ???:4294967295 [F] s_b_5_28 = constant u8 5 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [D] s_b_5_30 = (u64)s_b_5_29 */
    auto s_b_5_30 = emitter.zx(s_b_5_29, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_31 = s_b_5_26+s_b_5_30 */
    auto s_b_5_31 = emitter.add(s_b_5_26, s_b_5_30);
    /* execute.simd:193 [D] s_b_5_32: sym_5212_0_total = s_b_5_31, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_5_31);
    /* ???:4294967295 [F] s_b_5_33 = constant u8 6 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [D] s_b_5_35 = (u64)s_b_5_34 */
    auto s_b_5_35 = emitter.zx(s_b_5_34, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_36 = s_b_5_31+s_b_5_35 */
    auto s_b_5_36 = emitter.add(s_b_5_31, s_b_5_35);
    /* execute.simd:193 [D] s_b_5_37: sym_5212_0_total = s_b_5_36, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_5_36);
    /* ???:4294967295 [F] s_b_5_38 = constant u8 7 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_38] */
    auto s_b_5_39 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [D] s_b_5_40 = (u64)s_b_5_39 */
    auto s_b_5_40 = emitter.zx(s_b_5_39, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_41 = s_b_5_36+s_b_5_40 */
    auto s_b_5_41 = emitter.add(s_b_5_36, s_b_5_40);
    /* execute.simd:193 [D] s_b_5_42: sym_5212_0_total = s_b_5_41, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5212_0_total, s_b_5_41);
    /* execute.simd:0 [F] s_b_5_43: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:198 [D] s_b_6_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_6_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:202 [F] s_b_7_0=sym_5209_3_parameter_inst.rn (const) */
    /* execute.simd:202 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:205 [F] s_b_7_2 = sym_5212_0_total (const) uint64_t */
    uint64_t s_b_7_2 = CV_sym_5212_0_total;
    /* ???:4294967295 [F] s_b_7_3 = constant u8 0 (const) */
    /* execute.simd:205 [D] s_b_7_1[s_b_7_3] */
    auto s_b_7_4 = emitter.vector_extract(s_b_7_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_7_5 = (u64)s_b_7_4 */
    auto s_b_7_5 = emitter.zx(s_b_7_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_6 = s_b_7_2+s_b_7_5 */
    auto s_b_7_6 = emitter.add(emitter.const_u64(s_b_7_2), s_b_7_5);
    /* execute.simd:205 [D] s_b_7_7: sym_5212_0_total = s_b_7_6, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_7_6);
    /* ???:4294967295 [F] s_b_7_8 = constant u8 1 (const) */
    /* execute.simd:205 [D] s_b_7_1[s_b_7_8] */
    auto s_b_7_9 = emitter.vector_extract(s_b_7_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_7_10 = (u64)s_b_7_9 */
    auto s_b_7_10 = emitter.zx(s_b_7_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_11 = s_b_7_6+s_b_7_10 */
    auto s_b_7_11 = emitter.add(s_b_7_6, s_b_7_10);
    /* execute.simd:205 [D] s_b_7_12: sym_5212_0_total = s_b_7_11, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_7_11);
    /* ???:4294967295 [F] s_b_7_13 = constant u8 2 (const) */
    /* execute.simd:205 [D] s_b_7_1[s_b_7_13] */
    auto s_b_7_14 = emitter.vector_extract(s_b_7_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_7_15 = (u64)s_b_7_14 */
    auto s_b_7_15 = emitter.zx(s_b_7_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_16 = s_b_7_11+s_b_7_15 */
    auto s_b_7_16 = emitter.add(s_b_7_11, s_b_7_15);
    /* execute.simd:205 [D] s_b_7_17: sym_5212_0_total = s_b_7_16, dominates:  */
    emitter.store_local(DV_sym_5212_0_total, s_b_7_16);
    /* ???:4294967295 [F] s_b_7_18 = constant u8 3 (const) */
    /* execute.simd:205 [D] s_b_7_1[s_b_7_18] */
    auto s_b_7_19 = emitter.vector_extract(s_b_7_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_7_20 = (u64)s_b_7_19 */
    auto s_b_7_20 = emitter.zx(s_b_7_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_21 = s_b_7_16+s_b_7_20 */
    auto s_b_7_21 = emitter.add(s_b_7_16, s_b_7_20);
    /* execute.simd:205 [D] s_b_7_22: sym_5212_0_total = s_b_7_21, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5212_0_total, s_b_7_21);
    /* execute.simd:0 [F] s_b_7_23: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:210 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_8_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.simd:214 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_11, b_12, b_13, b_14,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [F] s_b_10_0: Return */
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_11: 
  {
    /* execute.simd:221 [F] s_b_11_0=sym_5209_3_parameter_inst.rd (const) */
    /* execute.simd:221 [D] s_b_11_1 = sym_5212_0_total uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_5212_0_total, emitter.context().types().u64());
    /* execute.simd:221 [D] s_b_11_2 = (u8)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u8());
    /* execute.simd:6187 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.simd:6187 [D] s_b_11_4: WriteRegBank 2:s_b_11_0 = s_b_11_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_3);
    /* execute.simd:6188 [F] s_b_11_5 = constant u64 0 (const) */
    /* execute.simd:6188 [F] s_b_11_6: WriteRegBank 3:s_b_11_0 = s_b_11_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_11_7: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_1,  */
  fixed_block_b_12: 
  {
    /* execute.simd:225 [F] s_b_12_0=sym_5209_3_parameter_inst.rd (const) */
    /* execute.simd:225 [D] s_b_12_1 = sym_5212_0_total uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_5212_0_total, emitter.context().types().u64());
    /* execute.simd:225 [D] s_b_12_2 = (u16)s_b_12_1 */
    auto s_b_12_2 = emitter.truncate(s_b_12_1, emitter.context().types().u16());
    /* execute.simd:6194 [D] s_b_12_3 = (u64)s_b_12_2 */
    auto s_b_12_3 = emitter.zx(s_b_12_2, emitter.context().types().u64());
    /* execute.simd:6194 [D] s_b_12_4: WriteRegBank 2:s_b_12_0 = s_b_12_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_3);
    /* execute.simd:6195 [F] s_b_12_5 = constant u64 0 (const) */
    /* execute.simd:6195 [F] s_b_12_6: WriteRegBank 3:s_b_12_0 = s_b_12_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_12_7: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_1,  */
  fixed_block_b_13: 
  {
    /* execute.simd:229 [F] s_b_13_0=sym_5209_3_parameter_inst.rd (const) */
    /* execute.simd:229 [D] s_b_13_1 = sym_5212_0_total uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_5212_0_total, emitter.context().types().u64());
    /* execute.simd:229 [D] s_b_13_2 = (u32)s_b_13_1 */
    auto s_b_13_2 = emitter.truncate(s_b_13_1, emitter.context().types().u32());
    /* execute.simd:6201 [D] s_b_13_3 = (u64)s_b_13_2 */
    auto s_b_13_3 = emitter.zx(s_b_13_2, emitter.context().types().u64());
    /* execute.simd:6201 [D] s_b_13_4: WriteRegBank 2:s_b_13_0 = s_b_13_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_3);
    /* execute.simd:6202 [F] s_b_13_5 = constant u64 0 (const) */
    /* execute.simd:6202 [F] s_b_13_6: WriteRegBank 3:s_b_13_0 = s_b_13_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_13_7: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_1,  */
  fixed_block_b_14: 
  {
    /* execute.simd:233 [D] s_b_14_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_14_1: Jump b_10 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_bcond(const arm64_decode_a64_COND_B_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_10 = emitter.context().create_block();
  auto block_b_11 = emitter.context().create_block();
  auto block_b_12 = emitter.context().create_block();
  uint8_t CV_sym_5994_0_state;
  auto DV_sym_5994_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:307 [F] s_b_0_0 = constant u8 0 (const) */
    /* execute.a64:307 [F] s_b_0_1: sym_5994_0_state = s_b_0_0 (const), dominates: s_b_1_0  */
    CV_sym_5994_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_5994_0_state, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:309 [F] s_b_0_2=sym_5991_3_parameter_inst.cond (const) */
    /* execute.a64:309 [F] s_b_0_3 = (u32)s_b_0_2 (const) */
    /* execute.a64:309 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:309 [F] s_b_0_5 = s_b_0_3>>s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(((uint32_t)insn.cond) >> (uint32_t)1ULL));
    /* execute.a64:310 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.a64:314 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.a64:318 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.a64:322 [F] s_b_0_9 = constant s32 3 (const) */
    /* execute.a64:326 [F] s_b_0_10 = constant s32 4 (const) */
    /* execute.a64:330 [F] s_b_0_11 = constant s32 5 (const) */
    /* execute.a64:334 [F] s_b_0_12 = constant s32 6 (const) */
    /* execute.a64:338 [F] s_b_0_13 = constant s32 7 (const) */
    /* execute.a64:309 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_1 (const) -> b_9, b_8, b_7, b_6, b_5, b_4, b_3, b_2, b_1,  */
    switch (s_b_0_5) 
    {
    case (int32_t)7ULL:
      goto fixed_block_b_9;
      break;
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
      goto fixed_block_b_1;
    }
  }
  /* b_0, b_2, b_3, b_4, b_5, b_6, b_7, b_8, b_9,  */
  fixed_block_b_1: 
  {
    /* execute.a64:344 [D] s_b_1_0 = sym_5994_0_state uint8_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_5994_0_state, emitter.context().types().u8());
    /* execute.a64:344 [F] s_b_1_1=sym_5991_3_parameter_inst.cond (const) */
    /* execute.a64:344 [F] s_b_1_2 = (u32)s_b_1_1 (const) */
    /* execute.a64:344 [F] s_b_1_3 = constant u32 1 (const) */
    /* execute.a64:344 [F] s_b_1_4 = s_b_1_2&s_b_1_3 (const) */
    uint32_t s_b_1_4 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:344 [D] s_b_1_5 = (u32)s_b_1_0 */
    auto s_b_1_5 = emitter.zx(s_b_1_0, emitter.context().types().u32());
    /* execute.a64:344 [D] s_b_1_6 = s_b_1_5^s_b_1_4 */
    auto s_b_1_6 = emitter.bitwise_xor(s_b_1_5, emitter.const_u32(s_b_1_4));
    /* execute.a64:344 [D] s_b_1_7: If s_b_1_6: Jump b_10 else b_12 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_10;
        dynamic_block_queue.push(block_b_10);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_12;
        dynamic_block_queue.push(block_b_12);
        false_target = block;
      }
      emitter.branch(s_b_1_6, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:311 [D] s_b_2_0 = ReadReg 2 (u8) */
    auto s_b_2_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_2_0, emitter.const_u8(1));
    }
    /* execute.a64:311 [D] s_b_2_1: sym_5994_0_state = s_b_2_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_5994_0_state, s_b_2_0);
    /* execute.a64:0 [F] s_b_2_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:315 [D] s_b_3_0 = ReadReg 3 (u8) */
    auto s_b_3_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_3_0, emitter.const_u8(1));
    }
    /* execute.a64:315 [D] s_b_3_1: sym_5994_0_state = s_b_3_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_5994_0_state, s_b_3_0);
    /* execute.a64:0 [F] s_b_3_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:319 [D] s_b_4_0 = ReadReg 1 (u8) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_4_0, emitter.const_u8(1));
    }
    /* execute.a64:319 [D] s_b_4_1: sym_5994_0_state = s_b_4_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_5994_0_state, s_b_4_0);
    /* execute.a64:0 [F] s_b_4_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:323 [D] s_b_5_0 = ReadReg 4 (u8) */
    auto s_b_5_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_5_0, emitter.const_u8(1));
    }
    /* execute.a64:323 [D] s_b_5_1: sym_5994_0_state = s_b_5_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_5994_0_state, s_b_5_0);
    /* execute.a64:0 [F] s_b_5_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:327 [D] s_b_6_0 = ReadReg 3 (u8) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_6_0, emitter.const_u8(1));
    }
    /* execute.a64:327 [D] s_b_6_1 = ReadReg 2 (u8) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_6_1, emitter.const_u8(1));
    }
    /* execute.a64:327 [D] s_b_6_2 = !s_b_6_1 */
    auto s_b_6_2 = emitter.cmp_eq(s_b_6_1, emitter.const_u8(0));
    /* execute.a64:327 [D] s_b_6_3 = s_b_6_0&s_b_6_2 */
    auto s_b_6_3 = emitter.bitwise_and(s_b_6_0, s_b_6_2);
    /* execute.a64:327 [D] s_b_6_4: sym_5994_0_state = s_b_6_3, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_5994_0_state, s_b_6_3);
    /* execute.a64:0 [F] s_b_6_5: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:331 [D] s_b_7_0 = ReadReg 1 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:331 [D] s_b_7_1 = ReadReg 4 (u8) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_7_1, emitter.const_u8(1));
    }
    /* execute.a64:331 [D] s_b_7_2 = s_b_7_0==s_b_7_1 */
    auto s_b_7_2 = emitter.cmp_eq(s_b_7_0, s_b_7_1);
    /* execute.a64:331 [D] s_b_7_3: sym_5994_0_state = s_b_7_2, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_5994_0_state, s_b_7_2);
    /* execute.a64:0 [F] s_b_7_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:335 [D] s_b_8_0 = ReadReg 1 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:335 [D] s_b_8_1 = ReadReg 4 (u8) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_8_1, emitter.const_u8(1));
    }
    /* execute.a64:335 [D] s_b_8_2 = s_b_8_0==s_b_8_1 */
    auto s_b_8_2 = emitter.cmp_eq(s_b_8_0, s_b_8_1);
    /* execute.a64:335 [D] s_b_8_3 = ReadReg 2 (u8) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_8_3, emitter.const_u8(1));
    }
    /* execute.a64:335 [D] s_b_8_4 = !s_b_8_3 */
    auto s_b_8_4 = emitter.cmp_eq(s_b_8_3, emitter.const_u8(0));
    /* execute.a64:335 [D] s_b_8_5 = s_b_8_2&s_b_8_4 */
    auto s_b_8_5 = emitter.bitwise_and(s_b_8_2, s_b_8_4);
    /* execute.a64:335 [D] s_b_8_6: sym_5994_0_state = s_b_8_5, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_5994_0_state, s_b_8_5);
    /* execute.a64:0 [F] s_b_8_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:339 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:339 [F] s_b_9_1: sym_5994_0_state = s_b_9_0 (const), dominates: s_b_1_0  */
    CV_sym_5994_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_5994_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_9_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  // BLOCK b_10 not fully fixed
  // BLOCK b_11 not fully fixed
  // BLOCK b_12 not fully fixed
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
      if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.a64:345 [D] s_b_10_0 = read_pc */
        auto s_b_10_0 = emitter.load_pc();
        /* execute.a64:345 [D] s_b_10_1 = (s64)s_b_10_0 */
        auto s_b_10_1 = emitter.reinterpret(s_b_10_0, emitter.context().types().s64());
        /* execute.a64:345 [F] s_b_10_2=sym_5991_3_parameter_inst.imms64 (const) */
        /* execute.a64:345 [D] s_b_10_3 = s_b_10_1+s_b_10_2 */
        auto s_b_10_3 = emitter.add(s_b_10_1, emitter.const_s64(insn.imms64));
        /* execute.a64:345 [D] s_b_10_4 = (u64)s_b_10_3 */
        auto s_b_10_4 = emitter.reinterpret(s_b_10_3, emitter.context().types().u64());
        /* execute.a64:571 [D] s_b_10_5 = write_pc */
        emitter.store_pc(s_b_10_4);
        /* execute.a64:572 [D] s_b_10_6 = __branch_taken */
        emitter.call(__captive___branch_taken);
        /* execute.a64:0 [F] s_b_10_7: Jump b_11 (const) */
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* ???:4294967295 [F] s_b_11_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.a64:578 [D] s_b_12_0 = read_pc */
        auto s_b_12_0 = emitter.load_pc();
        /* execute.a64:578 [F] s_b_12_1 = constant u64 4 (const) */
        /* execute.a64:578 [D] s_b_12_2 = s_b_12_0+s_b_12_1 */
        auto s_b_12_2 = emitter.add(s_b_12_0, emitter.const_u64((uint64_t)4ULL));
        /* execute.a64:578 [D] s_b_12_3 = write_pc */
        emitter.store_pc(s_b_12_2);
        /* execute.a64:579 [D] s_b_12_4 = __branch_not_taken */
        emitter.call(__captive___branch_not_taken);
        /* execute.a64:0 [F] s_b_12_5: Jump b_11 (const) */
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_bsl(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2294 [F] s_b_0_0=sym_6454_3_parameter_inst.Q (const) */
    /* execute.simd:2294 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2302 [F] s_b_1_0=sym_6454_3_parameter_inst.rd (const) */
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
    /* execute.simd:2303 [F] s_b_1_3=sym_6454_3_parameter_inst.rn (const) */
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
    /* execute.simd:2304 [F] s_b_1_6=sym_6454_3_parameter_inst.rm (const) */
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
    /* execute.simd:2306 [F] s_b_1_9=sym_6454_3_parameter_inst.rd (const) */
    /* execute.simd:2306 [D] s_b_1_10 = s_b_1_7^s_b_1_4 */
    auto s_b_1_10 = emitter.bitwise_xor(s_b_1_7, s_b_1_4);
    /* execute.simd:2306 [D] s_b_1_11 = s_b_1_10&s_b_1_1 */
    auto s_b_1_11 = emitter.bitwise_and(s_b_1_10, s_b_1_1);
    /* execute.simd:2306 [D] s_b_1_12 = s_b_1_7^s_b_1_11 */
    auto s_b_1_12 = emitter.bitwise_xor(s_b_1_7, s_b_1_11);
    /* execute.simd:2306 [D] s_b_1_13 = s_b_1_8^s_b_1_5 */
    auto s_b_1_13 = emitter.bitwise_xor(s_b_1_8, s_b_1_5);
    /* execute.simd:2306 [D] s_b_1_14 = s_b_1_13&s_b_1_2 */
    auto s_b_1_14 = emitter.bitwise_and(s_b_1_13, s_b_1_2);
    /* execute.simd:2306 [D] s_b_1_15 = s_b_1_8^s_b_1_14 */
    auto s_b_1_15 = emitter.bitwise_xor(s_b_1_8, s_b_1_14);
    /* execute.simd:6215 [D] s_b_1_16: WriteRegBank 2:s_b_1_9 = s_b_1_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_12);
    /* execute.simd:6216 [D] s_b_1_17: WriteRegBank 3:s_b_1_9 = s_b_1_15 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_15,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_15);
    /* execute.simd:0 [F] s_b_1_18: Jump b_2 (const) */
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
    /* execute.simd:2312 [F] s_b_3_0=sym_6454_3_parameter_inst.rd (const) */
    /* execute.simd:6237 [D] s_b_3_1 = ReadRegBank 7:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:2313 [F] s_b_3_2=sym_6454_3_parameter_inst.rn (const) */
    /* execute.simd:6237 [D] s_b_3_3 = ReadRegBank 7:s_b_3_2 (u64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:2314 [F] s_b_3_4=sym_6454_3_parameter_inst.rm (const) */
    /* execute.simd:6237 [D] s_b_3_5 = ReadRegBank 7:s_b_3_4 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:2316 [F] s_b_3_6=sym_6454_3_parameter_inst.rd (const) */
    /* execute.simd:2316 [D] s_b_3_7 = s_b_3_5^s_b_3_3 */
    auto s_b_3_7 = emitter.bitwise_xor(s_b_3_5, s_b_3_3);
    /* execute.simd:2316 [D] s_b_3_8 = s_b_3_7&s_b_3_1 */
    auto s_b_3_8 = emitter.bitwise_and(s_b_3_7, s_b_3_1);
    /* execute.simd:2316 [D] s_b_3_9 = s_b_3_5^s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_xor(s_b_3_5, s_b_3_8);
    /* execute.simd:6208 [D] s_b_3_10: WriteRegBank 2:s_b_3_6 = s_b_3_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_9,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_9);
    /* execute.simd:6209 [F] s_b_3_11 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_3_12: WriteRegBank 3:s_b_3_6 = s_b_3_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_clz(const arm64_decode_a64_DP_1S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_14 = emitter.context().create_block();
  auto block_b_15 = emitter.context().create_block();
  auto block_b_16 = emitter.context().create_block();
  auto block_b_17 = emitter.context().create_block();
  uint64_t CV_sym_56220_1_temporary_value;
  auto DV_sym_56220_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_56304_1_temporary_value;
  auto DV_sym_56304_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_56377_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56487_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_7045_0_rn = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_7014_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2265 [F] s_b_0_0=sym_7003_3_parameter_inst.sf (const) */
    /* execute.a64:2265 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2720 [F] s_b_1_0=sym_7003_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2714 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_1_4: If s_b_1_3: Jump b_8 else b_9 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2722 [F] s_b_3_0=sym_7003_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:2709 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_3_4: If s_b_3_3: Jump b_11 else b_12 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  // BLOCK b_6 not fully fixed
  // BLOCK b_7 not fully fixed
  /* b_1,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2714 [F] s_b_8_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_8_1: sym_56220_1_temporary_value = s_b_8_0 (const), dominates: s_b_10_0  */
    CV_sym_56220_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_56220_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_8_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_1,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2714 [F] s_b_9_0=sym_7003_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_9_2: sym_56220_1_temporary_value = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_56220_1_temporary_value, s_b_9_1);
    /* execute.a64:2714 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_8, b_9,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2714 [D] s_b_10_0 = sym_56220_1_temporary_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_56220_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2266 [D] s_b_10_1: sym_7014_0_rn = s_b_10_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_7014_0_rn, s_b_10_0);
    /* execute.a64:2267 [F] s_b_10_2 = constant u64 0 (const) */
    /* execute.a64:2267 [D] s_b_10_3 = s_b_10_0==s_b_10_2 */
    auto s_b_10_3 = emitter.cmp_eq(s_b_10_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2267 [D] s_b_10_4: If s_b_10_3: Jump b_4 else b_5 */
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
      emitter.branch(s_b_10_3, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [F] s_b_11_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_11_1: sym_56304_1_temporary_value = s_b_11_0 (const), dominates: s_b_13_0  */
    CV_sym_56304_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_56304_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_3,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0=sym_7003_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_12_1 = ReadRegBank 1:s_b_12_0 (u32) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_12_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_12_2: sym_56304_1_temporary_value = s_b_12_1, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_56304_1_temporary_value, s_b_12_1);
    /* execute.a64:2709 [F] s_b_12_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_11, b_12,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [D] s_b_13_0 = sym_56304_1_temporary_value uint32_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_56304_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_13_1 = (u64)s_b_13_0 */
    auto s_b_13_1 = emitter.zx(s_b_13_0, emitter.context().types().u64());
    /* execute.a64:2273 [D] s_b_13_2 = (u32)s_b_13_1 */
    auto s_b_13_2 = emitter.truncate(s_b_13_1, emitter.context().types().u32());
    /* execute.a64:2273 [D] s_b_13_3: sym_7045_0_rn = s_b_13_2, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_7045_0_rn, s_b_13_2);
    /* execute.a64:2274 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2274 [D] s_b_13_5 = s_b_13_2==s_b_13_4 */
    auto s_b_13_5 = emitter.cmp_eq(s_b_13_2, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2274 [D] s_b_13_6: If s_b_13_5: Jump b_6 else b_7 */
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
      emitter.branch(s_b_13_5, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_14 not fully fixed
  // BLOCK b_15 not fully fixed
  // BLOCK b_16 not fully fixed
  // BLOCK b_17 not fully fixed
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
        /* execute.a64:2754 [F] s_b_4_0=sym_7003_3_parameter_inst.rd (const) */
        /* execute.a64:2745 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
        /* execute.a64:2745 [F] s_b_4_2 = constant u32 1f (const) */
        /* execute.a64:2745 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
        uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2745 [F] s_b_4_4: If s_b_4_3: Jump b_2 else b_14 (const) */
        if (s_b_4_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2270 [D] s_b_5_0 = sym_7014_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_7014_0_rn, emitter.context().types().u64());
        /* execute.a64:2270 [D] s_b_5_1 = __builtin_clz64 */
        auto s_b_5_1 = emitter.clz(s_b_5_0);
        /* execute.a64:2270 [D] s_b_5_2 = (u64)s_b_5_1 */
        auto s_b_5_2 = (captive::arch::dbt::el::Value *)s_b_5_1;
        /* execute.a64:2754 [F] s_b_5_3=sym_7003_3_parameter_inst.rd (const) */
        /* execute.a64:2754 [D] s_b_5_4: sym_56377_3_parameter_value = s_b_5_2, dominates: s_b_15_1  */
        emitter.store_local(DV_sym_56377_3_parameter_value, s_b_5_2);
        /* execute.a64:2745 [F] s_b_5_5 = (u32)s_b_5_3 (const) */
        /* execute.a64:2745 [F] s_b_5_6 = constant u32 1f (const) */
        /* execute.a64:2745 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
        uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2745 [F] s_b_5_8: If s_b_5_7: Jump b_2 else b_15 (const) */
        if (s_b_5_7) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.a64:2756 [F] s_b_6_0=sym_7003_3_parameter_inst.rd (const) */
        /* execute.a64:2745 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
        /* execute.a64:2745 [F] s_b_6_2 = constant u32 1f (const) */
        /* execute.a64:2745 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
        uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2745 [F] s_b_6_4: If s_b_6_3: Jump b_2 else b_16 (const) */
        if (s_b_6_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_16;
          dynamic_block_queue.push(block_b_16);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.a64:2277 [D] s_b_7_0 = sym_7045_0_rn uint32_t */
        auto s_b_7_0 = emitter.load_local(DV_sym_7045_0_rn, emitter.context().types().u32());
        /* execute.a64:2277 [D] s_b_7_1 = __builtin_clz32 */
        auto s_b_7_1 = emitter.clz(s_b_7_0);
        /* execute.a64:2277 [D] s_b_7_2 = (u64)s_b_7_1 */
        auto s_b_7_2 = emitter.zx(s_b_7_1, emitter.context().types().u64());
        /* execute.a64:2756 [F] s_b_7_3=sym_7003_3_parameter_inst.rd (const) */
        /* execute.a64:2756 [D] s_b_7_4 = (u32)s_b_7_2 */
        auto s_b_7_4 = emitter.truncate(s_b_7_2, emitter.context().types().u32());
        /* execute.a64:2756 [D] s_b_7_5 = (u64)s_b_7_4 */
        auto s_b_7_5 = emitter.zx(s_b_7_4, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_7_6: sym_56487_3_parameter_value = s_b_7_5, dominates: s_b_17_1  */
        emitter.store_local(DV_sym_56487_3_parameter_value, s_b_7_5);
        /* execute.a64:2745 [F] s_b_7_7 = (u32)s_b_7_3 (const) */
        /* execute.a64:2745 [F] s_b_7_8 = constant u32 1f (const) */
        /* execute.a64:2745 [F] s_b_7_9 = s_b_7_7==s_b_7_8 (const) */
        uint8_t s_b_7_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2745 [F] s_b_7_10: If s_b_7_9: Jump b_2 else b_17 (const) */
        if (s_b_7_9) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_17;
          dynamic_block_queue.push(block_b_17);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.a64:2747 [F] s_b_14_0=sym_7003_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [F] s_b_14_1 = constant u64 40 (const) */
        /* execute.a64:2747 [F] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)64ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)64ULL));
        /* execute.a64:0 [F] s_b_14_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.a64:2747 [F] s_b_15_0=sym_7003_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_15_1 = sym_56377_3_parameter_value uint64_t */
        auto s_b_15_1 = emitter.load_local(DV_sym_56377_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2747 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1);
        /* execute.a64:0 [F] s_b_15_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.a64:2747 [F] s_b_16_0=sym_7003_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [F] s_b_16_1 = constant u64 20 (const) */
        /* execute.a64:2747 [F] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)32ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)32ULL));
        /* execute.a64:0 [F] s_b_16_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.a64:2747 [F] s_b_17_0=sym_7003_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_17_1 = sym_56487_3_parameter_value uint64_t */
        auto s_b_17_1 = emitter.load_local(DV_sym_56487_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2747 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_1);
        /* execute.a64:0 [F] s_b_17_3: Jump b_2 (const) */
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
  auto DV_sym_58946_1__R_s_b_0_8 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_9740_0_rlo = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_9693_0_element = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_58998_1_temporary_value;
  auto DV_sym_58998_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_59026_1_temporary_value;
  auto DV_sym_59026_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:447 [F] s_b_0_0=sym_9684_3_parameter_inst.width (const) */
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
    /* execute.simd:491 [F] s_b_1_0=sym_9684_3_parameter_inst.Q (const) */
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
    /* execute.simd:452 [D] s_b_2_0 = sym_9693_0_element uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_9693_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_2_1 = constant u64 ff (const) */
    /* ???:4294967295 [D] s_b_2_2 = s_b_2_0&s_b_2_1 */
    auto s_b_2_2 = emitter.bitwise_and(s_b_2_0, emitter.const_u64((uint64_t)255ULL));
    /* execute.simd:452 [D] s_b_2_3: sym_9693_0_element = s_b_2_2, dominates:  */
    emitter.store_local(DV_sym_9693_0_element, s_b_2_2);
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
    /* execute.simd:453 [D] s_b_2_25: sym_9740_0_rlo = s_b_2_24, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9740_0_rlo, s_b_2_24);
    /* execute.simd:0 [F] s_b_2_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_3: 
  {
    /* execute.simd:457 [D] s_b_3_0 = sym_9693_0_element uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_9693_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_3_1 = constant u64 ff (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0&s_b_3_1 */
    auto s_b_3_2 = emitter.bitwise_and(s_b_3_0, emitter.const_u64((uint64_t)255ULL));
    /* execute.simd:457 [D] s_b_3_3: sym_9693_0_element = s_b_3_2, dominates:  */
    emitter.store_local(DV_sym_9693_0_element, s_b_3_2);
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
    /* execute.simd:458 [D] s_b_3_25: sym_9740_0_rlo = s_b_3_24, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9740_0_rlo, s_b_3_24);
    /* execute.simd:0 [F] s_b_3_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_4: 
  {
    /* execute.simd:462 [D] s_b_4_0 = sym_9693_0_element uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_9693_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_4_1 = constant u64 ffff (const) */
    /* ???:4294967295 [D] s_b_4_2 = s_b_4_0&s_b_4_1 */
    auto s_b_4_2 = emitter.bitwise_and(s_b_4_0, emitter.const_u64((uint64_t)65535ULL));
    /* execute.simd:462 [D] s_b_4_3: sym_9693_0_element = s_b_4_2, dominates:  */
    emitter.store_local(DV_sym_9693_0_element, s_b_4_2);
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
    /* execute.simd:463 [D] s_b_4_13: sym_9740_0_rlo = s_b_4_12, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9740_0_rlo, s_b_4_12);
    /* execute.simd:0 [F] s_b_4_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_5: 
  {
    /* execute.simd:467 [D] s_b_5_0 = sym_9693_0_element uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_9693_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_5_1 = constant u64 ffff (const) */
    /* ???:4294967295 [D] s_b_5_2 = s_b_5_0&s_b_5_1 */
    auto s_b_5_2 = emitter.bitwise_and(s_b_5_0, emitter.const_u64((uint64_t)65535ULL));
    /* execute.simd:467 [D] s_b_5_3: sym_9693_0_element = s_b_5_2, dominates:  */
    emitter.store_local(DV_sym_9693_0_element, s_b_5_2);
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
    /* execute.simd:468 [D] s_b_5_13: sym_9740_0_rlo = s_b_5_12, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9740_0_rlo, s_b_5_12);
    /* execute.simd:0 [F] s_b_5_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_6: 
  {
    /* execute.simd:472 [D] s_b_6_0 = sym_9693_0_element uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_9693_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_6_2 = s_b_6_0&s_b_6_1 */
    auto s_b_6_2 = emitter.bitwise_and(s_b_6_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.simd:472 [D] s_b_6_3: sym_9693_0_element = s_b_6_2, dominates:  */
    emitter.store_local(DV_sym_9693_0_element, s_b_6_2);
    /* execute.simd:473 [F] s_b_6_4 = constant u64 20 (const) */
    /* execute.simd:473 [D] s_b_6_5 = s_b_6_2<<s_b_6_4 */
    auto s_b_6_5 = emitter.shl(s_b_6_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:473 [D] s_b_6_6 = s_b_6_2|s_b_6_5 */
    auto s_b_6_6 = emitter.bitwise_or(s_b_6_2, s_b_6_5);
    /* execute.simd:473 [D] s_b_6_7: sym_9740_0_rlo = s_b_6_6, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9740_0_rlo, s_b_6_6);
    /* execute.simd:0 [F] s_b_6_8: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_7: 
  {
    /* execute.simd:477 [D] s_b_7_0 = sym_9693_0_element uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_9693_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_7_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_7_2 = s_b_7_0&s_b_7_1 */
    auto s_b_7_2 = emitter.bitwise_and(s_b_7_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.simd:477 [D] s_b_7_3: sym_9693_0_element = s_b_7_2, dominates:  */
    emitter.store_local(DV_sym_9693_0_element, s_b_7_2);
    /* execute.simd:478 [F] s_b_7_4 = constant u64 20 (const) */
    /* execute.simd:478 [D] s_b_7_5 = s_b_7_2<<s_b_7_4 */
    auto s_b_7_5 = emitter.shl(s_b_7_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:478 [D] s_b_7_6 = s_b_7_2|s_b_7_5 */
    auto s_b_7_6 = emitter.bitwise_or(s_b_7_2, s_b_7_5);
    /* execute.simd:478 [D] s_b_7_7: sym_9740_0_rlo = s_b_7_6, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9740_0_rlo, s_b_7_6);
    /* execute.simd:0 [F] s_b_7_8: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_8: 
  {
    /* execute.simd:482 [D] s_b_8_0 = sym_9693_0_element uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_9693_0_element, emitter.context().types().u64());
    /* execute.simd:482 [D] s_b_8_1: sym_9740_0_rlo = s_b_8_0, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9740_0_rlo, s_b_8_0);
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
    /* execute.simd:492 [F] s_b_10_0=sym_9684_3_parameter_inst.rd (const) */
    /* execute.simd:492 [D] s_b_10_1 = sym_9740_0_rlo uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_9740_0_rlo, emitter.context().types().u64());
    /* execute.simd:6215 [D] s_b_10_2: WriteRegBank 2:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_1);
    /* execute.simd:6216 [D] s_b_10_3: WriteRegBank 3:s_b_10_0 = s_b_10_1 */
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
    /* execute.simd:494 [F] s_b_12_0=sym_9684_3_parameter_inst.rd (const) */
    /* execute.simd:494 [D] s_b_12_1 = sym_9740_0_rlo uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_9740_0_rlo, emitter.context().types().u64());
    /* execute.simd:6208 [D] s_b_12_2: WriteRegBank 2:s_b_12_0 = s_b_12_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_1);
    /* execute.simd:6209 [F] s_b_12_3 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_12_4: WriteRegBank 3:s_b_12_0 = s_b_12_3 */
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
    /* execute.a64:2720 [F] s_b_13_0=sym_9684_3_parameter_inst.rn (const) */
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
    /* execute.a64:2722 [F] s_b_14_0=sym_9684_3_parameter_inst.rn (const) */
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
    /* execute.simd:447 [D] s_b_15_0 = sym_58946_1__R_s_b_0_8 uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_58946_1__R_s_b_0_8, emitter.context().types().u64());
    /* execute.simd:447 [D] s_b_15_1: sym_9693_0_element = s_b_15_0, dominates: s_b_8_0 s_b_7_0 s_b_6_0 s_b_5_0 s_b_4_0 s_b_3_0 s_b_2_0  */
    emitter.store_local(DV_sym_9693_0_element, s_b_15_0);
    /* execute.simd:450 [F] s_b_15_2=sym_9684_3_parameter_inst.arrangement (const) */
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
    /* execute.a64:2714 [F] s_b_16_1: sym_58998_1_temporary_value = s_b_16_0 (const), dominates: s_b_18_0  */
    CV_sym_58998_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_58998_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2714 [F] s_b_17_0=sym_9684_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_17_1 = ReadRegBank 0:s_b_17_0 (u64) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_17_2: sym_58998_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_58998_1_temporary_value, s_b_17_1);
    /* execute.a64:2714 [F] s_b_17_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_16, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2714 [D] s_b_18_0 = sym_58998_1_temporary_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_58998_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_18_1: sym_58946_1__R_s_b_0_8 = s_b_18_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_58946_1__R_s_b_0_8, s_b_18_0);
    /* execute.a64:2720 [F] s_b_18_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2709 [F] s_b_19_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_19_1: sym_59026_1_temporary_value = s_b_19_0 (const), dominates: s_b_21_0  */
    CV_sym_59026_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_59026_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_19_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_14,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2709 [F] s_b_20_0=sym_9684_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_20_1 = ReadRegBank 1:s_b_20_0 (u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_20_2: sym_59026_1_temporary_value = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_59026_1_temporary_value, s_b_20_1);
    /* execute.a64:2709 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_19, b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2709 [D] s_b_21_0 = sym_59026_1_temporary_value uint32_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_59026_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_21_1 = (u64)s_b_21_0 */
    auto s_b_21_1 = emitter.zx(s_b_21_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_21_2: sym_58946_1__R_s_b_0_8 = s_b_21_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_58946_1__R_s_b_0_8, s_b_21_1);
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
    /* execute.simd:1717 [F] s_b_0_0=sym_10311_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1717 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1718 [F] s_b_1_0=sym_10311_3_parameter_inst.size (const) */
    /* execute.simd:1718 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:1718 [F] s_b_1_2 = constant u32 2 (const) */
    /* execute.simd:1718 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:1718 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:1730 [D] s_b_3_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:1730 [F] s_b_3_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1719 [F] s_b_4_0=sym_10311_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_4_1 = ReadRegBank 9:s_b_4_0 (f32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(4));
    }
    /* execute.simd:1720 [F] s_b_4_2=sym_10311_3_parameter_inst.rm (const) */
    /* execute.simd:6162 [D] s_b_4_3 = ReadRegBank 9:s_b_4_2 (f32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(4));
    }
    /* execute.simd:1722 [F] s_b_4_4=sym_10311_3_parameter_inst.rd (const) */
    /* execute.simd:1722 [D] s_b_4_5 = s_b_4_1-s_b_4_3 */
    auto s_b_4_5 = emitter.sub(s_b_4_1, s_b_4_3);
    /* execute.simd:1722 [D] s_b_4_6 = float_abs */
    auto s_b_4_6 = emitter.call(__captive_float_abs, s_b_4_5);
    /* execute.simd:6172 [D] s_b_4_7: WriteRegBank 9:s_b_4_4 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6);
    /* execute.simd:6173 [F] s_b_4_8 = constant u32 0 (const) */
    /* execute.simd:6173 [F] s_b_4_9: WriteRegBank 10:s_b_4_4 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6174 [F] s_b_4_10 = constant u64 0 (const) */
    /* execute.simd:6174 [F] s_b_4_11: WriteRegBank 3:s_b_4_4 = s_b_4_10 */
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
    /* execute.simd:1723 [F] s_b_5_0=sym_10311_3_parameter_inst.size (const) */
    /* execute.simd:1723 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:1723 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.simd:1723 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:1723 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
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
    /* execute.simd:1724 [F] s_b_6_0=sym_10311_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_6_1 = ReadRegBank 11:s_b_6_0 (f64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1725 [F] s_b_6_2=sym_10311_3_parameter_inst.rm (const) */
    /* execute.simd:6167 [D] s_b_6_3 = ReadRegBank 11:s_b_6_2 (f64) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1727 [F] s_b_6_4=sym_10311_3_parameter_inst.rd (const) */
    /* execute.simd:1727 [D] s_b_6_5 = s_b_6_1-s_b_6_3 */
    auto s_b_6_5 = emitter.sub(s_b_6_1, s_b_6_3);
    /* execute.simd:1727 [D] s_b_6_6 = double_abs */
    auto s_b_6_6 = emitter.call(__captive_double_abs, s_b_6_5);
    /* execute.simd:6180 [D] s_b_6_7: WriteRegBank 11:s_b_6_4 = s_b_6_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6);
    /* execute.simd:6181 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:6181 [F] s_b_6_9: WriteRegBank 3:s_b_6_4 = s_b_6_8 */
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
    /* execute.simd:4577 [F] s_b_0_0=sym_10824_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4577 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4577 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.simd:4577 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:4577 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4578 [F] s_b_1_0=sym_10824_3_parameter_inst.size (const) */
    /* execute.simd:4578 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4578 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4578 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4578 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4586 [D] s_b_3_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4586 [F] s_b_3_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4580 [F] s_b_4_0=sym_10824_3_parameter_inst.rd (const) */
    /* execute.simd:4580 [F] s_b_4_1=sym_10824_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_4_2 = ReadRegBank 9:s_b_4_1 (f32) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_2,emitter.const_u8(4));
    }
    /* execute.simd:4580 [F] s_b_4_3 = constant u8 0 (const) */
    /* execute.simd:4580 [D] s_b_4_4 = __builtin_fcvt_f32_s32 */
    auto s_b_4_4 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:4580 [D] s_b_4_5 = (u32)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().u32());
    /* execute.simd:6201 [D] s_b_4_6 = (u64)s_b_4_5 */
    auto s_b_4_6 = emitter.zx(s_b_4_5, emitter.context().types().u64());
    /* execute.simd:6201 [D] s_b_4_7: WriteRegBank 2:s_b_4_0 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6);
    /* execute.simd:6202 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:6202 [F] s_b_4_9: WriteRegBank 3:s_b_4_0 = s_b_4_8 */
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
    /* execute.simd:4583 [F] s_b_5_0=sym_10824_3_parameter_inst.rd (const) */
    /* execute.simd:4583 [F] s_b_5_1=sym_10824_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_5_2 = ReadRegBank 11:s_b_5_1 (f64) */
    auto s_b_5_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_2,emitter.const_u8(8));
    }
    /* execute.simd:4583 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.simd:4583 [D] s_b_5_4 = __builtin_fcvt_f64_s64 */
    auto s_b_5_4 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:4583 [D] s_b_5_5 = (u64)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().u64());
    /* execute.simd:6208 [D] s_b_5_6: WriteRegBank 2:s_b_5_0 = s_b_5_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5);
    /* execute.simd:6209 [F] s_b_5_7 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_5_8: WriteRegBank 3:s_b_5_0 = s_b_5_7 */
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
    /* execute.simd:1380 [F] s_b_0_0=sym_12166_3_parameter_inst.Q (const) */
    /* execute.simd:1381 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:1391 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:1380 [F] s_b_0_3: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_3, b_1, b_2,  */
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
    /* execute.simd:1382 [F] s_b_2_0=sym_12166_3_parameter_inst.rn (const) */
    /* execute.simd:1382 [D] s_b_2_1 = ReadRegBank 12:s_b_2_0 (v2f32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1383 [F] s_b_2_2=sym_12166_3_parameter_inst.rm (const) */
    /* execute.simd:1383 [D] s_b_2_3 = ReadRegBank 12:s_b_2_2 (v2f32) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* execute.simd:1385 [D] s_b_2_4 = s_b_2_1*s_b_2_3 */
    auto s_b_2_4 = emitter.mul(s_b_2_1, s_b_2_3);
    /* execute.simd:1386 [F] s_b_2_5=sym_12166_3_parameter_inst.rd (const) */
    /* execute.simd:1386 [D] s_b_2_6: WriteRegBank 12:s_b_2_5 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4);
    /* execute.simd:1387 [F] s_b_2_7=sym_12166_3_parameter_inst.rd (const) */
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
    /* execute.simd:1392 [F] s_b_3_0=sym_12166_3_parameter_inst.size (const) */
    /* execute.simd:1393 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:1402 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:1392 [F] s_b_3_3: Switch s_b_3_0: < <todo> > def b_1 (const) -> b_1, b_4, b_5,  */
    switch (insn.size) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_5;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1394 [F] s_b_4_0=sym_12166_3_parameter_inst.rn (const) */
    /* execute.simd:1394 [D] s_b_4_1 = ReadRegBank 13:s_b_4_0 (v4f32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:1395 [F] s_b_4_2=sym_12166_3_parameter_inst.rm (const) */
    /* execute.simd:1395 [D] s_b_4_3 = ReadRegBank 13:s_b_4_2 (v4f32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(16));
    }
    /* execute.simd:1397 [D] s_b_4_4 = s_b_4_1*s_b_4_3 */
    auto s_b_4_4 = emitter.mul(s_b_4_1, s_b_4_3);
    /* execute.simd:1398 [F] s_b_4_5=sym_12166_3_parameter_inst.rd (const) */
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
    /* execute.simd:1403 [F] s_b_5_0=sym_12166_3_parameter_inst.rn (const) */
    /* execute.simd:1403 [D] s_b_5_1 = ReadRegBank 14:s_b_5_0 (v2f64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1404 [F] s_b_5_2=sym_12166_3_parameter_inst.rm (const) */
    /* execute.simd:1404 [D] s_b_5_3 = ReadRegBank 14:s_b_5_2 (v2f64) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1406 [D] s_b_5_4 = s_b_5_1*s_b_5_3 */
    auto s_b_5_4 = emitter.mul(s_b_5_1, s_b_5_3);
    /* execute.simd:1407 [F] s_b_5_5=sym_12166_3_parameter_inst.rd (const) */
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
  auto DV_sym_67733_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67305_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_67307_3_parameter_rt;
  auto DV_sym_67375_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_67358_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_67303_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_67313_3_parameter_lane;
  auto DV_sym_67324_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_67341_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_67392_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_67409_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_67434_1_tmp_s_b_5_2;
  auto DV_sym_67437_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67483_1__R_s_b_7_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67502_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67558_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67647_1__R_s_b_31_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67270_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_67721_1_tmp_s_b_35_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13425_0_rt;
  uint8_t CV_sym_13413_0_lane;
  auto DV_sym_13390_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_67704_1_temporary_value;
  auto DV_sym_67704_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_13384_3_parameter_inst.rn (const) */
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
    /* execute.simd:2511 [F] s_b_1_0 = sym_13413_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13413_0_lane;
    /* execute.simd:2511 [F] s_b_1_1=sym_13384_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2511 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2511 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2512 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2512 [F] s_b_2_1: sym_13425_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13425_0_rt = (uint8_t)0ULL;
    /* execute.simd:2512 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2518 [F] s_b_3_0=sym_13384_3_parameter_inst.rm (const) */
    /* execute.simd:2518 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2518 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2518 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2518 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2512 [F] s_b_4_0 = sym_13425_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13425_0_rt;
    /* execute.simd:2512 [F] s_b_4_1=sym_13384_3_parameter_inst.regcnt (const) */
    /* execute.simd:2512 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2512 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2513 [F] s_b_5_0=sym_13384_3_parameter_inst.arrangement (const) */
    /* execute.simd:2513 [F] s_b_5_1=sym_13384_3_parameter_inst.rt (const) */
    /* execute.simd:2513 [F] s_b_5_2 = sym_13425_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13425_0_rt;
    /* execute.simd:2513 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2513 [F] s_b_5_4 = sym_13413_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13413_0_lane;
    /* execute.simd:2513 [D] s_b_5_5 = sym_13390_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13390_0_address, emitter.context().types().u64());
    /* execute.simd:2513 [F] s_b_5_6: sym_67307_3_parameter_rt = s_b_5_3 (const), dominates: s_b_15_2 s_b_18_2 s_b_12_2 s_b_16_2 s_b_13_2 s_b_17_2 s_b_14_2  */
    CV_sym_67307_3_parameter_rt = s_b_5_3;
    /* execute.simd:2513 [F] s_b_5_7: sym_67313_3_parameter_lane = s_b_5_4 (const), dominates: s_b_15_5 s_b_18_5 s_b_12_5 s_b_16_5 s_b_13_5 s_b_17_5 s_b_14_5  */
    CV_sym_67313_3_parameter_lane = s_b_5_4;
    /* execute.simd:2513 [D] s_b_5_8: sym_67303_3_parameter_addr = s_b_5_5, dominates: s_b_15_0 s_b_18_0 s_b_12_0 s_b_16_0 s_b_13_0 s_b_17_0 s_b_14_0  */
    emitter.store_local(DV_sym_67303_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_67434_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_19_1  */
    CV_sym_67434_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_67437_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_67437_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3770 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3779 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3788 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3797 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3806 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3815 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3824 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3769 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_11 (const) -> b_15, b_18, b_12, b_11, b_16, b_13, b_17, b_14,  */
    switch (insn.arrangement) 
    {
    case (int32_t)5ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_12;
      break;
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2511 [F] s_b_6_0 = sym_13413_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13413_0_lane;
    /* execute.simd:2511 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2511 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2511 [F] s_b_6_3: sym_13413_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13413_0_lane = s_b_6_2;
    /* execute.simd:2511 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2793 [F] s_b_7_0=sym_13384_3_parameter_inst.rn (const) */
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
    /* execute.simd:2522 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2522 [D] s_b_8_1 = sym_13390_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_13390_0_address, emitter.context().types().u64());
    /* execute.simd:2522 [D] s_b_8_2: sym_67502_3_parameter_value = s_b_8_1, dominates: s_b_22_0 s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_67502_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2796 [F] s_b_9_0=sym_13384_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_9_2: sym_67270_1__R_s_b_0_5 = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_67270_1__R_s_b_0_5, s_b_9_1);
    /* execute.a64:2796 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_31,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2506 [D] s_b_10_0 = sym_67270_1__R_s_b_0_5 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_67270_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2506 [D] s_b_10_1: sym_13390_0_address = s_b_10_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13390_0_address, s_b_10_0);
    /* execute.simd:2508 [F] s_b_10_2=sym_13384_3_parameter_inst.rt (const) */
    /* execute.simd:2508 [F] s_b_10_3 = constant u64 0 (const) */
    /* execute.simd:2508 [F] s_b_10_4 = constant u64 0 (const) */
    /* execute.simd:6215 [F] s_b_10_5: WriteRegBank 2:s_b_10_2 = s_b_10_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6216 [F] s_b_10_6: WriteRegBank 3:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2509 [F] s_b_10_7=sym_13384_3_parameter_inst.rt (const) */
    /* execute.simd:2509 [F] s_b_10_8 = (u32)s_b_10_7 (const) */
    /* execute.simd:2509 [F] s_b_10_9 = constant u32 1 (const) */
    /* execute.simd:2509 [F] s_b_10_10 = s_b_10_8+s_b_10_9 (const) */
    uint32_t s_b_10_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2509 [F] s_b_10_11 = (u8)s_b_10_10 (const) */
    /* execute.simd:2509 [F] s_b_10_12 = constant u64 0 (const) */
    /* execute.simd:2509 [F] s_b_10_13 = constant u64 0 (const) */
    /* execute.simd:6215 [F] s_b_10_14: WriteRegBank 2:s_b_10_11 = s_b_10_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6216 [F] s_b_10_15: WriteRegBank 3:s_b_10_11 = s_b_10_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2511 [F] s_b_10_16 = constant u8 0 (const) */
    /* execute.simd:2511 [F] s_b_10_17: sym_13413_0_lane = s_b_10_16 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13413_0_lane = (uint8_t)0ULL;
    /* execute.simd:2511 [F] s_b_10_18: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3834 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_11_1: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3799 [D] s_b_12_0 = sym_67303_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_67303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_67358_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_67358_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3801 [F] s_b_12_2 = sym_67307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_67307_3_parameter_rt;
    /* execute.simd:3801 [D] s_b_12_3 = ReadRegBank 18:s_b_12_2 (v8u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(16));
    }
    /* execute.simd:3802 [D] s_b_12_4 = sym_67358_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_67358_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3802 [F] s_b_12_5 = sym_67313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_67313_3_parameter_lane;
    /* execute.simd:3802 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3802 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3803 [D] s_b_12_8: WriteRegBank 18:s_b_12_2 = s_b_12_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_7);
    /* execute.simd:0 [F] s_b_12_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3781 [D] s_b_13_0 = sym_67303_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_67303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 1 s_b_13_0 => sym_67324_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_67324_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(1));
    }
    /* execute.simd:3783 [F] s_b_13_2 = sym_67307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_67307_3_parameter_rt;
    /* execute.simd:3783 [D] s_b_13_3 = ReadRegBank 16:s_b_13_2 (v16u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3784 [D] s_b_13_4 = sym_67324_0_mem_value uint8_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_67324_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3784 [F] s_b_13_5 = sym_67313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_67313_3_parameter_lane;
    /* execute.simd:3784 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3784 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3785 [D] s_b_13_8: WriteRegBank 16:s_b_13_2 = s_b_13_7 */
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
    /* execute.simd:3772 [D] s_b_14_0 = sym_67303_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_67303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 1 s_b_14_0 => sym_67305_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_67305_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(1));
    }
    /* execute.simd:3774 [F] s_b_14_2 = sym_67307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_67307_3_parameter_rt;
    /* execute.simd:3774 [D] s_b_14_3 = ReadRegBank 15:s_b_14_2 (v8u8) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3775 [D] s_b_14_4 = sym_67305_0_mem_value uint8_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_67305_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3775 [F] s_b_14_5 = sym_67313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_67313_3_parameter_lane;
    /* execute.simd:3775 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3775 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3776 [D] s_b_14_8: WriteRegBank 15:s_b_14_2 = s_b_14_7 */
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
    /* execute.simd:3790 [D] s_b_15_0 = sym_67303_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_67303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_67341_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_67341_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3792 [F] s_b_15_2 = sym_67307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_67307_3_parameter_rt;
    /* execute.simd:3792 [D] s_b_15_3 = ReadRegBank 17:s_b_15_2 (v4u16) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(8));
    }
    /* execute.simd:3793 [D] s_b_15_4 = sym_67341_0_mem_value uint16_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_67341_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3793 [F] s_b_15_5 = sym_67313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_67313_3_parameter_lane;
    /* execute.simd:3793 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3793 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3794 [D] s_b_15_8: WriteRegBank 17:s_b_15_2 = s_b_15_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_7);
    /* execute.simd:0 [F] s_b_15_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3817 [D] s_b_16_0 = sym_67303_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_67303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 4 s_b_16_0 => sym_67392_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_67392_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(4));
    }
    /* execute.simd:3819 [F] s_b_16_2 = sym_67307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_67307_3_parameter_rt;
    /* execute.simd:3819 [D] s_b_16_3 = ReadRegBank 20:s_b_16_2 (v4u32) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3820 [D] s_b_16_4 = sym_67392_0_mem_value uint32_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_67392_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3820 [F] s_b_16_5 = sym_67313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_67313_3_parameter_lane;
    /* execute.simd:3820 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3820 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3821 [D] s_b_16_8: WriteRegBank 20:s_b_16_2 = s_b_16_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_7);
    /* execute.simd:0 [F] s_b_16_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3808 [D] s_b_17_0 = sym_67303_3_parameter_addr uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_67303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_67375_0_mem_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_67375_0_mem_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3810 [F] s_b_17_2 = sym_67307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_2 = CV_sym_67307_3_parameter_rt;
    /* execute.simd:3810 [D] s_b_17_3 = ReadRegBank 19:s_b_17_2 (v2u32) */
    auto s_b_17_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_3,emitter.const_u8(8));
    }
    /* execute.simd:3811 [D] s_b_17_4 = sym_67375_0_mem_value uint32_t */
    auto s_b_17_4 = emitter.load_local(DV_sym_67375_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3811 [F] s_b_17_5 = sym_67313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_5 = CV_sym_67313_3_parameter_lane;
    /* execute.simd:3811 [F] s_b_17_6 = (s32)s_b_17_5 (const) */
    /* execute.simd:3811 [D] s_b_17_7 = s_b_17_3[s_b_17_6] <= s_b_17_4 */
    auto s_b_17_7 = emitter.vector_insert(s_b_17_3, emitter.const_s32(((int32_t)s_b_17_5)), s_b_17_4);
    /* execute.simd:3812 [D] s_b_17_8: WriteRegBank 19:s_b_17_2 = s_b_17_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_7);
    /* execute.simd:0 [F] s_b_17_9: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3826 [D] s_b_18_0 = sym_67303_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_67303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 8 s_b_18_0 => sym_67409_0_mem_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_67409_0_mem_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(8));
    }
    /* execute.simd:3828 [F] s_b_18_2 = sym_67307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_2 = CV_sym_67307_3_parameter_rt;
    /* execute.simd:3828 [D] s_b_18_3 = ReadRegBank 21:s_b_18_2 (v2u64) */
    auto s_b_18_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_3,emitter.const_u8(16));
    }
    /* execute.simd:3829 [D] s_b_18_4 = sym_67409_0_mem_value uint64_t */
    auto s_b_18_4 = emitter.load_local(DV_sym_67409_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3829 [F] s_b_18_5 = sym_67313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_5 = CV_sym_67313_3_parameter_lane;
    /* execute.simd:3829 [F] s_b_18_6 = (s32)s_b_18_5 (const) */
    /* execute.simd:3829 [D] s_b_18_7 = s_b_18_3[s_b_18_6] <= s_b_18_4 */
    auto s_b_18_7 = emitter.vector_insert(s_b_18_3, emitter.const_s32(((int32_t)s_b_18_5)), s_b_18_4);
    /* execute.simd:3830 [D] s_b_18_8: WriteRegBank 21:s_b_18_2 = s_b_18_7 */
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
    /* ???:4294967295 [D] s_b_19_0 = sym_67437_1_tmp_s_b_5_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_67437_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1 = sym_67434_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_19_1 = CV_sym_67434_1_tmp_s_b_5_2;
    /* execute.simd:2514 [F] s_b_19_2=sym_13384_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_19_3 = (u64)s_b_19_2 (const) */
    /* ???:4294967295 [D] s_b_19_4 = s_b_19_0+s_b_19_3 */
    auto s_b_19_4 = emitter.add(s_b_19_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2514 [D] s_b_19_5: sym_13390_0_address = s_b_19_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13390_0_address, s_b_19_4);
    /* execute.simd:2512 [F] s_b_19_6 = constant u8 1 (const) */
    /* execute.simd:2512 [F] s_b_19_7 = s_b_19_1+s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(s_b_19_1 + (uint8_t)1ULL));
    /* execute.simd:2512 [F] s_b_19_8: sym_13425_0_rt = s_b_19_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13425_0_rt = s_b_19_7;
    /* execute.simd:2512 [F] s_b_19_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2796 [F] s_b_20_0=sym_13384_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_20_2: sym_67483_1__R_s_b_7_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_67483_1__R_s_b_7_5, s_b_20_1);
    /* execute.a64:2796 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_36,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2519 [D] s_b_21_0 = sym_67483_1__R_s_b_7_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_67483_1__R_s_b_7_5, emitter.context().types().u64());
    /* execute.simd:2519 [F] s_b_21_1=sym_13384_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_21_2: sym_67721_1_tmp_s_b_35_0 = s_b_21_0, dominates: s_b_39_1  */
    emitter.store_local(DV_sym_67721_1_tmp_s_b_35_0, s_b_21_0);
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
    /* execute.a64:2810 [D] s_b_22_0 = sym_67502_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_67502_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_22_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_22_2 = s_b_22_0&s_b_22_1 */
    auto s_b_22_2 = emitter.bitwise_and(s_b_22_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_22_3: sym_67502_3_parameter_value = s_b_22_2, dominates: s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_67502_3_parameter_value, s_b_22_2);
    /* execute.a64:2810 [F] s_b_22_4: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2813 [F] s_b_23_0=sym_13384_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_24_0 = sym_67502_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_67502_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_24_1: sym_67733_3_parameter_value = s_b_24_0, dominates: s_b_40_0 s_b_41_0 s_b_42_0  */
    emitter.store_local(DV_sym_67733_3_parameter_value, s_b_24_0);
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
    /* execute.a64:2816 [F] s_b_25_0=sym_13384_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_25_1 = sym_67502_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_67502_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2765 [D] s_b_28_1: sym_67558_1__R_s_b_12_0 = s_b_28_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67558_1__R_s_b_12_0, s_b_28_0);
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
    /* execute.a64:2768 [D] s_b_29_1: sym_67558_1__R_s_b_12_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67558_1__R_s_b_12_0, s_b_29_0);
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
    /* execute.a64:2770 [D] s_b_30_1: sym_67558_1__R_s_b_12_0 = s_b_30_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_67558_1__R_s_b_12_0, s_b_30_0);
    /* execute.a64:2770 [F] s_b_30_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_28, b_29, b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2794 [D] s_b_31_0 = sym_67558_1__R_s_b_12_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_67558_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_31_1: sym_67270_1__R_s_b_0_5 = s_b_31_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_67270_1__R_s_b_0_5, s_b_31_0);
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
    /* execute.a64:2765 [D] s_b_33_1: sym_67647_1__R_s_b_31_0 = s_b_33_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_67647_1__R_s_b_31_0, s_b_33_0);
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
    /* execute.a64:2768 [D] s_b_34_1: sym_67647_1__R_s_b_31_0 = s_b_34_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_67647_1__R_s_b_31_0, s_b_34_0);
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
    /* execute.a64:2770 [D] s_b_35_1: sym_67647_1__R_s_b_31_0 = s_b_35_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_67647_1__R_s_b_31_0, s_b_35_0);
    /* execute.a64:2770 [F] s_b_35_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_33, b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2794 [D] s_b_36_0 = sym_67647_1__R_s_b_31_0 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_67647_1__R_s_b_31_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_36_1: sym_67483_1__R_s_b_7_5 = s_b_36_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_67483_1__R_s_b_7_5, s_b_36_0);
    /* execute.a64:2794 [F] s_b_36_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_21,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2714 [F] s_b_37_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_37_1: sym_67704_1_temporary_value = s_b_37_0 (const), dominates: s_b_39_0  */
    CV_sym_67704_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_67704_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_37_2: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_21,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2714 [F] s_b_38_0=sym_13384_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_38_1 = ReadRegBank 0:s_b_38_0 (u64) */
    auto s_b_38_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_38_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_38_2: sym_67704_1_temporary_value = s_b_38_1, dominates: s_b_39_0  */
    emitter.store_local(DV_sym_67704_1_temporary_value, s_b_38_1);
    /* execute.a64:2714 [F] s_b_38_3: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_37, b_38,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2714 [D] s_b_39_0 = sym_67704_1_temporary_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_67704_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_39_1 = sym_67721_1_tmp_s_b_35_0 uint64_t */
    auto s_b_39_1 = emitter.load_local(DV_sym_67721_1_tmp_s_b_35_0, emitter.context().types().u64());
    /* execute.simd:2519 [D] s_b_39_2 = s_b_39_1+s_b_39_0 */
    auto s_b_39_2 = emitter.add(s_b_39_1, s_b_39_0);
    /* execute.simd:2519 [D] s_b_39_3: sym_13390_0_address = s_b_39_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_13390_0_address, s_b_39_2);
    /* execute.simd:2519 [F] s_b_39_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_24,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2778 [D] s_b_40_0 = sym_67733_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_67733_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_41_0 = sym_67733_3_parameter_value uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_67733_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_42_0 = sym_67733_3_parameter_value uint64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_67733_3_parameter_value, emitter.context().types().u64());
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
  auto DV_sym_13972_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75214_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_74892_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75260_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_76997_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_74995_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_75612_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_76191_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75066_1_tmp_s_b_1_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_76063_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_74863_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75289_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75086_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75715_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_78211_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_78277_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_76715_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_13966_3_parameter_inst.rn (const) */
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
    /* execute.a64:894 [D] s_b_1_0 = sym_13972_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_13972_0_address, emitter.context().types().u64());
    /* execute.a64:894 [D] s_b_1_1: sym_74892_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_74892_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2: sym_75066_1_tmp_s_b_1_0 = s_b_1_0, dominates: s_b_6_3  */
    emitter.store_local(DV_sym_75066_1_tmp_s_b_1_0, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_3 = Load 4 s_b_1_0 => sym_74995_0_data32 */
    auto s_b_1_3 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_74995_0_data32, s_b_1_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_3, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_1_4 = sym_74995_0_data32 uint32_t */
    auto s_b_1_4 = emitter.load_local(DV_sym_74995_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_1_5 = (u64)s_b_1_4 */
    auto s_b_1_5 = emitter.zx(s_b_1_4, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_6=sym_13966_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_7 = (u32)s_b_1_5 */
    auto s_b_1_7 = emitter.truncate(s_b_1_5, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_8 = (u64)s_b_1_7 */
    auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_9: sym_76715_3_parameter_value = s_b_1_8, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_76715_3_parameter_value, s_b_1_8);
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
    /* execute.a64:897 [D] s_b_3_0 = sym_13972_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_13972_0_address, emitter.context().types().u64());
    /* execute.a64:897 [D] s_b_3_1: sym_75086_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_75086_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2: sym_75260_1_tmp_s_b_3_0 = s_b_3_0, dominates: s_b_7_3  */
    emitter.store_local(DV_sym_75260_1_tmp_s_b_3_0, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_3 = Load 8 s_b_3_0 => sym_75214_0_data64 */
    auto s_b_3_3 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_75214_0_data64, s_b_3_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_3, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_3_4 = sym_75214_0_data64 uint64_t */
    auto s_b_3_4 = emitter.load_local(DV_sym_75214_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_3_5=sym_13966_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_3_6: sym_76997_3_parameter_value = s_b_3_4, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_76997_3_parameter_value, s_b_3_4);
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
    /* execute.a64:2796 [F] s_b_4_0=sym_13966_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_4_2: sym_74863_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_74863_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2796 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:891 [D] s_b_5_0 = sym_74863_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_74863_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:891 [D] s_b_5_1: sym_13972_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_13972_0_address, s_b_5_0);
    /* execute.a64:893 [F] s_b_5_2=sym_13966_3_parameter_inst.size (const) */
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
    /* execute.a64:1786 [D] s_b_6_1 = sym_74892_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_74892_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* ???:4294967295 [D] s_b_6_3 = sym_75066_1_tmp_s_b_1_0 uint64_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_75066_1_tmp_s_b_1_0, emitter.context().types().u64());
    /* execute.a64:895 [F] s_b_6_4 = constant u64 4 (const) */
    /* execute.a64:895 [D] s_b_6_5 = s_b_6_3+s_b_6_4 */
    auto s_b_6_5 = emitter.add(s_b_6_3, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:895 [D] s_b_6_6: sym_75612_3_parameter_address = s_b_6_5, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_75612_3_parameter_address, s_b_6_5);
    /* ???:4294967295 [D] s_b_6_7 = Load 4 s_b_6_5 => sym_75715_0_data32 */
    auto s_b_6_7 = emitter.load_memory(s_b_6_5, emitter.context().types().u32());
    emitter.store_local(DV_sym_75715_0_data32, s_b_6_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_5, s_b_6_7, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_6_8 = sym_75715_0_data32 uint32_t */
    auto s_b_6_8 = emitter.load_local(DV_sym_75715_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_10=sym_13966_3_parameter_inst.rt2 (const) */
    /* execute.a64:2756 [D] s_b_6_11 = (u32)s_b_6_9 */
    auto s_b_6_11 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_13: sym_78211_3_parameter_value = s_b_6_12, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_78211_3_parameter_value, s_b_6_12);
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
    /* execute.a64:1786 [D] s_b_7_1 = sym_75086_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_75086_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* ???:4294967295 [D] s_b_7_3 = sym_75260_1_tmp_s_b_3_0 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_75260_1_tmp_s_b_3_0, emitter.context().types().u64());
    /* execute.a64:898 [F] s_b_7_4 = constant u64 8 (const) */
    /* execute.a64:898 [D] s_b_7_5 = s_b_7_3+s_b_7_4 */
    auto s_b_7_5 = emitter.add(s_b_7_3, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:898 [D] s_b_7_6: sym_76063_3_parameter_address = s_b_7_5, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_76063_3_parameter_address, s_b_7_5);
    /* ???:4294967295 [D] s_b_7_7 = Load 8 s_b_7_5 => sym_76191_0_data64 */
    auto s_b_7_7 = emitter.load_memory(s_b_7_5, emitter.context().types().u64());
    emitter.store_local(DV_sym_76191_0_data64, s_b_7_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_5, s_b_7_7, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_7_8 = sym_76191_0_data64 uint64_t */
    auto s_b_7_8 = emitter.load_local(DV_sym_76191_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_7_9=sym_13966_3_parameter_inst.rt2 (const) */
    /* execute.a64:2754 [D] s_b_7_10: sym_78277_3_parameter_value = s_b_7_8, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_78277_3_parameter_value, s_b_7_8);
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
    /* execute.a64:2765 [D] s_b_9_1: sym_75289_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_75289_1__R_s_b_7_0, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_75289_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_75289_1__R_s_b_7_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_75289_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_75289_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2794 [D] s_b_12_0 = sym_75289_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_75289_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_12_1: sym_74863_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_74863_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2794 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_6, b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1786 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_13_1 = sym_75612_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_75612_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7, b_19,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1786 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_14_1 = sym_76063_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_76063_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_16_0=sym_13966_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_16_1 = sym_76715_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_76715_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_17_0=sym_13966_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_76997_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_76997_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_18_0=sym_13966_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_18_1 = sym_78211_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_78211_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_19_0=sym_13966_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_19_1 = sym_78277_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_78277_3_parameter_value, emitter.context().types().u64());
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
  auto DV_sym_14396_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90424_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_90068_0_offset;
  auto DV_sym_90155_1__R_s_b_8_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90073_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90099_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90241_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90276_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90455_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90217_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90219_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_90254_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90248_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90234_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_90227_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_90461_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90448_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_90441_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_90434_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  uint8_t CV_sym_90062_3_parameter_size;
  auto DV_sym_90426_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_90048_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14390_3_parameter_inst.rn (const) */
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
    /* execute.simd:815 [D] s_b_1_0 = sym_14396_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14396_0_addr, emitter.context().types().u64());
    /* execute.simd:815 [F] s_b_1_1=sym_14390_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.simd:815 [D] s_b_1_3: sym_14396_0_addr = s_b_1_2, dominates: s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_14396_0_addr, s_b_1_2);
    /* execute.simd:815 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_6,  */
  fixed_block_b_2: 
  {
    /* execute.simd:818 [F] s_b_2_0=sym_14390_3_parameter_inst.opc (const) */
    /* execute.simd:818 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.simd:818 [F] s_b_2_2 = constant u32 2 (const) */
    /* execute.simd:818 [F] s_b_2_3 = s_b_2_1+s_b_2_2 (const) */
    uint32_t s_b_2_3 = ((uint32_t)(((uint32_t)insn.opc) + (uint32_t)2ULL));
    /* execute.simd:818 [F] s_b_2_4 = (u8)s_b_2_3 (const) */
    /* execute.simd:818 [D] s_b_2_5 = sym_14396_0_addr uint64_t */
    auto s_b_2_5 = emitter.load_local(DV_sym_14396_0_addr, emitter.context().types().u64());
    /* execute.simd:818 [F] s_b_2_6: sym_90062_3_parameter_size = s_b_2_4 (const), dominates: s_b_23_0  */
    CV_sym_90062_3_parameter_size = ((uint8_t)s_b_2_3);
    /* execute.simd:818 [D] s_b_2_7: sym_90073_3_parameter_addr = s_b_2_5, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_90073_3_parameter_addr, s_b_2_5);
    /* execute.simd:773 [F] s_b_2_8 = constant u32 1 (const) */
    /* execute.simd:773 [F] s_b_2_9 = (u32)s_b_2_4 (const) */
    /* execute.simd:773 [F] s_b_2_10 = s_b_2_8<<s_b_2_9 (const) */
    uint32_t s_b_2_10 = ((uint32_t)((uint32_t)1ULL << ((uint32_t)((uint8_t)s_b_2_3))));
    /* execute.simd:773 [F] s_b_2_11 = (u8)s_b_2_10 (const) */
    /* execute.simd:773 [F] s_b_2_12: sym_90068_0_offset = s_b_2_11 (const), dominates: s_b_23_2  */
    CV_sym_90068_0_offset = ((uint8_t)s_b_2_10);
    /* execute.simd:774 [D] s_b_2_13: sym_90217_3_parameter_addr = s_b_2_5, dominates: s_b_18_0 s_b_22_0 s_b_21_0 s_b_19_0 s_b_20_0  */
    emitter.store_local(DV_sym_90217_3_parameter_addr, s_b_2_5);
    /* execute.simd:3676 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:3683 [F] s_b_2_15 = constant s32 1 (const) */
    /* execute.simd:3690 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:3697 [F] s_b_2_17 = constant s32 3 (const) */
    /* execute.simd:3704 [F] s_b_2_18 = constant s32 4 (const) */
    /* execute.simd:3675 [F] s_b_2_19: Switch s_b_2_4: < <todo> > def b_23 (const) -> b_18, b_22, b_21, b_19, b_23, b_20,  */
    switch (((uint8_t)s_b_2_3)) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_21;
      break;
    default:
      goto fixed_block_b_23;
    }
  }
  /* b_7,  */
  fixed_block_b_3: 
  {
    /* execute.simd:821 [D] s_b_3_0 = sym_14396_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14396_0_addr, emitter.context().types().u64());
    /* execute.simd:821 [F] s_b_3_1=sym_14390_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:821 [D] s_b_3_3: sym_14396_0_addr = s_b_3_2, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_14396_0_addr, s_b_3_2);
    /* execute.simd:821 [F] s_b_3_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_7,  */
  fixed_block_b_4: 
  {
    /* execute.simd:824 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.simd:824 [D] s_b_4_1 = sym_14396_0_addr uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_14396_0_addr, emitter.context().types().u64());
    /* execute.simd:824 [D] s_b_4_2: sym_90099_3_parameter_value = s_b_4_1, dominates: s_b_8_0 s_b_10_0 s_b_11_1  */
    emitter.store_local(DV_sym_90099_3_parameter_value, s_b_4_1);
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
    /* execute.a64:2796 [F] s_b_5_0=sym_14390_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_5_2: sym_90048_1__R_s_b_0_5 = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_90048_1__R_s_b_0_5, s_b_5_1);
    /* execute.a64:2796 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_17,  */
  fixed_block_b_6: 
  {
    /* execute.simd:813 [D] s_b_6_0 = sym_90048_1__R_s_b_0_5 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_90048_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:813 [D] s_b_6_1: sym_14396_0_addr = s_b_6_0, dominates: s_b_1_0 s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_14396_0_addr, s_b_6_0);
    /* execute.simd:814 [F] s_b_6_2=sym_14390_3_parameter_inst.P (const) */
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
    /* execute.simd:820 [F] s_b_7_0=sym_14390_3_parameter_inst.P (const) */
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
    /* execute.a64:2810 [D] s_b_8_0 = sym_90099_3_parameter_value uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_90099_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_8_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_8_2 = s_b_8_0&s_b_8_1 */
    auto s_b_8_2 = emitter.bitwise_and(s_b_8_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_8_3: sym_90099_3_parameter_value = s_b_8_2, dominates: s_b_10_0 s_b_11_1  */
    emitter.store_local(DV_sym_90099_3_parameter_value, s_b_8_2);
    /* execute.a64:2810 [F] s_b_8_4: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2813 [F] s_b_9_0=sym_14390_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_10_0 = sym_90099_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_90099_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_10_1: sym_90276_3_parameter_value = s_b_10_0, dominates: s_b_24_0 s_b_25_0 s_b_26_0  */
    emitter.store_local(DV_sym_90276_3_parameter_value, s_b_10_0);
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
    /* execute.a64:2816 [F] s_b_11_0=sym_14390_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_11_1 = sym_90099_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_90099_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2765 [D] s_b_14_1: sym_90155_1__R_s_b_8_0 = s_b_14_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_90155_1__R_s_b_8_0, s_b_14_0);
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
    /* execute.a64:2768 [D] s_b_15_1: sym_90155_1__R_s_b_8_0 = s_b_15_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_90155_1__R_s_b_8_0, s_b_15_0);
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
    /* execute.a64:2770 [D] s_b_16_1: sym_90155_1__R_s_b_8_0 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_90155_1__R_s_b_8_0, s_b_16_0);
    /* execute.a64:2770 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_14, b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2794 [D] s_b_17_0 = sym_90155_1__R_s_b_8_0 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_90155_1__R_s_b_8_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_17_1: sym_90048_1__R_s_b_0_5 = s_b_17_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_90048_1__R_s_b_0_5, s_b_17_0);
    /* execute.a64:2794 [F] s_b_17_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_2,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3679 [D] s_b_18_0 = sym_90217_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_90217_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 1 s_b_18_0 => sym_90219_0_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_90219_0_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(1));
    }
    /* execute.simd:3680 [F] s_b_18_2=sym_14390_3_parameter_inst.rt (const) */
    /* execute.simd:3680 [D] s_b_18_3 = sym_90219_0_value uint8_t */
    auto s_b_18_3 = emitter.load_local(DV_sym_90219_0_value, emitter.context().types().u8());
    /* execute.simd:6187 [D] s_b_18_4 = (u64)s_b_18_3 */
    auto s_b_18_4 = emitter.zx(s_b_18_3, emitter.context().types().u64());
    /* execute.simd:6187 [D] s_b_18_5: WriteRegBank 2:s_b_18_2 = s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_4);
    /* execute.simd:6188 [F] s_b_18_6 = constant u64 0 (const) */
    /* execute.simd:6188 [F] s_b_18_7: WriteRegBank 3:s_b_18_2 = s_b_18_6 */
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
    /* execute.simd:3686 [D] s_b_19_0 = sym_90217_3_parameter_addr uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_90217_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_19_1 = Load 2 s_b_19_0 => sym_90227_0_value */
    auto s_b_19_1 = emitter.load_memory(s_b_19_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_90227_0_value, s_b_19_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_19_0, s_b_19_1, emitter.const_u8(2));
    }
    /* execute.simd:3687 [F] s_b_19_2=sym_14390_3_parameter_inst.rt (const) */
    /* execute.simd:3687 [D] s_b_19_3 = sym_90227_0_value uint16_t */
    auto s_b_19_3 = emitter.load_local(DV_sym_90227_0_value, emitter.context().types().u16());
    /* execute.simd:6194 [D] s_b_19_4 = (u64)s_b_19_3 */
    auto s_b_19_4 = emitter.zx(s_b_19_3, emitter.context().types().u64());
    /* execute.simd:6194 [D] s_b_19_5: WriteRegBank 2:s_b_19_2 = s_b_19_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_19_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_19_4);
    /* execute.simd:6195 [F] s_b_19_6 = constant u64 0 (const) */
    /* execute.simd:6195 [F] s_b_19_7: WriteRegBank 3:s_b_19_2 = s_b_19_6 */
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
    /* execute.simd:3700 [D] s_b_20_0 = sym_90217_3_parameter_addr uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_90217_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_1 = Load 8 s_b_20_0 => sym_90241_0_value */
    auto s_b_20_1 = emitter.load_memory(s_b_20_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90241_0_value, s_b_20_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_20_0, s_b_20_1, emitter.const_u8(8));
    }
    /* execute.simd:3701 [F] s_b_20_2=sym_14390_3_parameter_inst.rt (const) */
    /* execute.simd:3701 [D] s_b_20_3 = sym_90241_0_value uint64_t */
    auto s_b_20_3 = emitter.load_local(DV_sym_90241_0_value, emitter.context().types().u64());
    /* execute.simd:6208 [D] s_b_20_4: WriteRegBank 2:s_b_20_2 = s_b_20_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_20_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_20_3);
    /* execute.simd:6209 [F] s_b_20_5 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_20_6: WriteRegBank 3:s_b_20_2 = s_b_20_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_20_7: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_2,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3693 [D] s_b_21_0 = sym_90217_3_parameter_addr uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_90217_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_1 = Load 4 s_b_21_0 => sym_90234_0_value */
    auto s_b_21_1 = emitter.load_memory(s_b_21_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_90234_0_value, s_b_21_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_21_0, s_b_21_1, emitter.const_u8(4));
    }
    /* execute.simd:3694 [F] s_b_21_2=sym_14390_3_parameter_inst.rt (const) */
    /* execute.simd:3694 [D] s_b_21_3 = sym_90234_0_value uint32_t */
    auto s_b_21_3 = emitter.load_local(DV_sym_90234_0_value, emitter.context().types().u32());
    /* execute.simd:6201 [D] s_b_21_4 = (u64)s_b_21_3 */
    auto s_b_21_4 = emitter.zx(s_b_21_3, emitter.context().types().u64());
    /* execute.simd:6201 [D] s_b_21_5: WriteRegBank 2:s_b_21_2 = s_b_21_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_21_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_21_4);
    /* execute.simd:6202 [F] s_b_21_6 = constant u64 0 (const) */
    /* execute.simd:6202 [F] s_b_21_7: WriteRegBank 3:s_b_21_2 = s_b_21_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_21_8: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_2,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3708 [D] s_b_22_0 = sym_90217_3_parameter_addr uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_90217_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_22_1 = Load 8 s_b_22_0 => sym_90248_0_vl */
    auto s_b_22_1 = emitter.load_memory(s_b_22_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90248_0_vl, s_b_22_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_22_0, s_b_22_1, emitter.const_u8(8));
    }
    /* execute.simd:3709 [F] s_b_22_2 = constant u64 8 (const) */
    /* execute.simd:3709 [D] s_b_22_3 = s_b_22_0+s_b_22_2 */
    auto s_b_22_3 = emitter.add(s_b_22_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_22_4 = Load 8 s_b_22_3 => sym_90254_0_vh */
    auto s_b_22_4 = emitter.load_memory(s_b_22_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_90254_0_vh, s_b_22_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_22_3, s_b_22_4, emitter.const_u8(8));
    }
    /* execute.simd:3710 [F] s_b_22_5=sym_14390_3_parameter_inst.rt (const) */
    /* execute.simd:3710 [D] s_b_22_6 = sym_90248_0_vl uint64_t */
    auto s_b_22_6 = emitter.load_local(DV_sym_90248_0_vl, emitter.context().types().u64());
    /* execute.simd:3710 [D] s_b_22_7 = sym_90254_0_vh uint64_t */
    auto s_b_22_7 = emitter.load_local(DV_sym_90254_0_vh, emitter.context().types().u64());
    /* execute.simd:6215 [D] s_b_22_8: WriteRegBank 2:s_b_22_5 = s_b_22_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_22_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_22_6);
    /* execute.simd:6216 [D] s_b_22_9: WriteRegBank 3:s_b_22_5 = s_b_22_7 */
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
    /* execute.simd:775 [F] s_b_23_0 = sym_90062_3_parameter_size (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_90062_3_parameter_size;
    /* execute.simd:775 [D] s_b_23_1 = sym_90073_3_parameter_addr uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_90073_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:775 [F] s_b_23_2 = sym_90068_0_offset (const) uint8_t */
    uint8_t s_b_23_2 = CV_sym_90068_0_offset;
    /* execute.simd:775 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* execute.simd:775 [D] s_b_23_4 = s_b_23_1+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_1, emitter.const_u64(((uint64_t)s_b_23_2)));
    /* execute.simd:775 [D] s_b_23_5: sym_90424_3_parameter_addr = s_b_23_4, dominates: s_b_31_0 s_b_28_0 s_b_30_0 s_b_29_0 s_b_32_0  */
    emitter.store_local(DV_sym_90424_3_parameter_addr, s_b_23_4);
    /* execute.simd:3676 [F] s_b_23_6 = constant s32 0 (const) */
    /* execute.simd:3683 [F] s_b_23_7 = constant s32 1 (const) */
    /* execute.simd:3690 [F] s_b_23_8 = constant s32 2 (const) */
    /* execute.simd:3697 [F] s_b_23_9 = constant s32 3 (const) */
    /* execute.simd:3704 [F] s_b_23_10 = constant s32 4 (const) */
    /* execute.simd:3675 [F] s_b_23_11: Switch s_b_23_0: < <todo> > def b_7 (const) -> b_31, b_28, b_7, b_30, b_29, b_32,  */
    switch (s_b_23_0) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_28;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_29;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_31;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_30;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_32;
      break;
    default:
      goto fixed_block_b_7;
    }
  }
  /* b_10,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2778 [D] s_b_24_0 = sym_90276_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_90276_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_25_0 = sym_90276_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_90276_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_26_0 = sym_90276_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_90276_3_parameter_value, emitter.context().types().u64());
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
    /* execute.simd:3679 [D] s_b_28_0 = sym_90424_3_parameter_addr uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_90424_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_28_1 = Load 1 s_b_28_0 => sym_90426_0_value */
    auto s_b_28_1 = emitter.load_memory(s_b_28_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_90426_0_value, s_b_28_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_28_0, s_b_28_1, emitter.const_u8(1));
    }
    /* execute.simd:3680 [F] s_b_28_2=sym_14390_3_parameter_inst.rt2 (const) */
    /* execute.simd:3680 [D] s_b_28_3 = sym_90426_0_value uint8_t */
    auto s_b_28_3 = emitter.load_local(DV_sym_90426_0_value, emitter.context().types().u8());
    /* execute.simd:6187 [D] s_b_28_4 = (u64)s_b_28_3 */
    auto s_b_28_4 = emitter.zx(s_b_28_3, emitter.context().types().u64());
    /* execute.simd:6187 [D] s_b_28_5: WriteRegBank 2:s_b_28_2 = s_b_28_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_28_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_28_4);
    /* execute.simd:6188 [F] s_b_28_6 = constant u64 0 (const) */
    /* execute.simd:6188 [F] s_b_28_7: WriteRegBank 3:s_b_28_2 = s_b_28_6 */
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
    /* execute.simd:3686 [D] s_b_29_0 = sym_90424_3_parameter_addr uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_90424_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_29_1 = Load 2 s_b_29_0 => sym_90434_0_value */
    auto s_b_29_1 = emitter.load_memory(s_b_29_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_90434_0_value, s_b_29_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_29_0, s_b_29_1, emitter.const_u8(2));
    }
    /* execute.simd:3687 [F] s_b_29_2=sym_14390_3_parameter_inst.rt2 (const) */
    /* execute.simd:3687 [D] s_b_29_3 = sym_90434_0_value uint16_t */
    auto s_b_29_3 = emitter.load_local(DV_sym_90434_0_value, emitter.context().types().u16());
    /* execute.simd:6194 [D] s_b_29_4 = (u64)s_b_29_3 */
    auto s_b_29_4 = emitter.zx(s_b_29_3, emitter.context().types().u64());
    /* execute.simd:6194 [D] s_b_29_5: WriteRegBank 2:s_b_29_2 = s_b_29_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_29_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_29_4);
    /* execute.simd:6195 [F] s_b_29_6 = constant u64 0 (const) */
    /* execute.simd:6195 [F] s_b_29_7: WriteRegBank 3:s_b_29_2 = s_b_29_6 */
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
    /* execute.simd:3700 [D] s_b_30_0 = sym_90424_3_parameter_addr uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_90424_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_30_1 = Load 8 s_b_30_0 => sym_90448_0_value */
    auto s_b_30_1 = emitter.load_memory(s_b_30_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90448_0_value, s_b_30_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_30_0, s_b_30_1, emitter.const_u8(8));
    }
    /* execute.simd:3701 [F] s_b_30_2=sym_14390_3_parameter_inst.rt2 (const) */
    /* execute.simd:3701 [D] s_b_30_3 = sym_90448_0_value uint64_t */
    auto s_b_30_3 = emitter.load_local(DV_sym_90448_0_value, emitter.context().types().u64());
    /* execute.simd:6208 [D] s_b_30_4: WriteRegBank 2:s_b_30_2 = s_b_30_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_30_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_30_3);
    /* execute.simd:6209 [F] s_b_30_5 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_30_6: WriteRegBank 3:s_b_30_2 = s_b_30_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_30_7: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_23,  */
  fixed_block_b_31: 
  {
    /* execute.simd:3693 [D] s_b_31_0 = sym_90424_3_parameter_addr uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_90424_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1 = Load 4 s_b_31_0 => sym_90441_0_value */
    auto s_b_31_1 = emitter.load_memory(s_b_31_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_90441_0_value, s_b_31_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_31_0, s_b_31_1, emitter.const_u8(4));
    }
    /* execute.simd:3694 [F] s_b_31_2=sym_14390_3_parameter_inst.rt2 (const) */
    /* execute.simd:3694 [D] s_b_31_3 = sym_90441_0_value uint32_t */
    auto s_b_31_3 = emitter.load_local(DV_sym_90441_0_value, emitter.context().types().u32());
    /* execute.simd:6201 [D] s_b_31_4 = (u64)s_b_31_3 */
    auto s_b_31_4 = emitter.zx(s_b_31_3, emitter.context().types().u64());
    /* execute.simd:6201 [D] s_b_31_5: WriteRegBank 2:s_b_31_2 = s_b_31_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_31_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_31_4);
    /* execute.simd:6202 [F] s_b_31_6 = constant u64 0 (const) */
    /* execute.simd:6202 [F] s_b_31_7: WriteRegBank 3:s_b_31_2 = s_b_31_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_31_8: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_23,  */
  fixed_block_b_32: 
  {
    /* execute.simd:3708 [D] s_b_32_0 = sym_90424_3_parameter_addr uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_90424_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_1 = Load 8 s_b_32_0 => sym_90455_0_vl */
    auto s_b_32_1 = emitter.load_memory(s_b_32_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_90455_0_vl, s_b_32_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_32_0, s_b_32_1, emitter.const_u8(8));
    }
    /* execute.simd:3709 [F] s_b_32_2 = constant u64 8 (const) */
    /* execute.simd:3709 [D] s_b_32_3 = s_b_32_0+s_b_32_2 */
    auto s_b_32_3 = emitter.add(s_b_32_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_32_4 = Load 8 s_b_32_3 => sym_90461_0_vh */
    auto s_b_32_4 = emitter.load_memory(s_b_32_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_90461_0_vh, s_b_32_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_32_3, s_b_32_4, emitter.const_u8(8));
    }
    /* execute.simd:3710 [F] s_b_32_5=sym_14390_3_parameter_inst.rt2 (const) */
    /* execute.simd:3710 [D] s_b_32_6 = sym_90455_0_vl uint64_t */
    auto s_b_32_6 = emitter.load_local(DV_sym_90455_0_vl, emitter.context().types().u64());
    /* execute.simd:3710 [D] s_b_32_7 = sym_90461_0_vh uint64_t */
    auto s_b_32_7 = emitter.load_local(DV_sym_90461_0_vh, emitter.context().types().u64());
    /* execute.simd:6215 [D] s_b_32_8: WriteRegBank 2:s_b_32_5 = s_b_32_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_32_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_32_6);
    /* execute.simd:6216 [D] s_b_32_9: WriteRegBank 3:s_b_32_5 = s_b_32_7 */
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
  auto DV_sym_15236_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100105_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100139_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_100134_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102294_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_101784_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100521_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_100516_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_101588_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100753_1__R_s_b_14_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100697_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100330_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_100325_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102782_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_15230_3_parameter_inst.rn (const) */
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
    /* execute.a64:961 [D] s_b_1_0 = sym_15236_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15236_0_address, emitter.context().types().u64());
    /* execute.a64:961 [F] s_b_1_1=sym_15230_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:961 [D] s_b_1_4: sym_15236_0_address = s_b_1_3, dominates: s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15236_0_address, s_b_1_3);
    /* execute.a64:961 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_11,  */
  fixed_block_b_2: 
  {
    /* execute.a64:964 [F] s_b_2_0=sym_15230_3_parameter_inst.X (const) */
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
    /* execute.a64:965 [F] s_b_3_0=sym_15230_3_parameter_inst.L (const) */
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
    /* execute.a64:974 [F] s_b_4_0=sym_15230_3_parameter_inst.P (const) */
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
    /* execute.a64:971 [D] s_b_5_0 = sym_15236_0_address uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_15236_0_address, emitter.context().types().u64());
    /* execute.a64:971 [D] s_b_5_1: sym_100134_3_parameter_address = s_b_5_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_100134_3_parameter_address, s_b_5_0);
    /* ???:4294967295 [D] s_b_5_2 = Load 1 s_b_5_0 => sym_100139_0_data8 */
    auto s_b_5_2 = emitter.load_memory(s_b_5_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_100139_0_data8, s_b_5_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_5_0, s_b_5_2, emitter.const_u8(1));
    }
    /* execute.a64:1726 [D] s_b_5_3 = sym_100139_0_data8 uint8_t */
    auto s_b_5_3 = emitter.load_local(DV_sym_100139_0_data8, emitter.context().types().u8());
    /* execute.a64:1726 [D] s_b_5_4 = (u64)s_b_5_3 */
    auto s_b_5_4 = emitter.zx(s_b_5_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_5_5=sym_15230_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_5_6 = (u32)s_b_5_4 */
    auto s_b_5_6 = emitter.truncate(s_b_5_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_5_8: sym_101784_3_parameter_value = s_b_5_7, dominates: s_b_29_1  */
    emitter.store_local(DV_sym_101784_3_parameter_value, s_b_5_7);
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
    /* execute.a64:966 [D] s_b_6_0 = sym_15236_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_15236_0_address, emitter.context().types().u64());
    /* execute.a64:966 [D] s_b_6_1: sym_100325_3_parameter_address = s_b_6_0, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_100325_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 1 s_b_6_0 => sym_100330_0_data8 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_100330_0_data8, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(1));
    }
    /* execute.a64:1728 [D] s_b_6_3 = sym_100330_0_data8 uint8_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_100330_0_data8, emitter.context().types().u8());
    /* execute.a64:1728 [D] s_b_6_4 = (s8)s_b_6_3 */
    auto s_b_6_4 = emitter.reinterpret(s_b_6_3, emitter.context().types().s8());
    /* execute.a64:1728 [D] s_b_6_5 = (s64)s_b_6_4 */
    auto s_b_6_5 = emitter.sx(s_b_6_4, emitter.context().types().s64());
    /* execute.a64:1728 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.reinterpret(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_7=sym_15230_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_6_8 = (u32)s_b_6_6 */
    auto s_b_6_8 = emitter.truncate(s_b_6_6, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_10: sym_102294_3_parameter_value = s_b_6_9, dominates: s_b_30_1  */
    emitter.store_local(DV_sym_102294_3_parameter_value, s_b_6_9);
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
    /* execute.a64:968 [D] s_b_7_0 = sym_15236_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_15236_0_address, emitter.context().types().u64());
    /* execute.a64:968 [D] s_b_7_1: sym_100516_3_parameter_address = s_b_7_0, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_100516_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 1 s_b_7_0 => sym_100521_0_data8 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_100521_0_data8, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(1));
    }
    /* execute.a64:1730 [D] s_b_7_3 = sym_100521_0_data8 uint8_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_100521_0_data8, emitter.context().types().u8());
    /* execute.a64:1730 [D] s_b_7_4 = (s8)s_b_7_3 */
    auto s_b_7_4 = emitter.reinterpret(s_b_7_3, emitter.context().types().s8());
    /* execute.a64:1730 [D] s_b_7_5 = (s64)s_b_7_4 */
    auto s_b_7_5 = emitter.sx(s_b_7_4, emitter.context().types().s64());
    /* execute.a64:1730 [D] s_b_7_6 = (u64)s_b_7_5 */
    auto s_b_7_6 = emitter.reinterpret(s_b_7_5, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_7_7=sym_15230_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_7_8: sym_102782_3_parameter_value = s_b_7_6, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_102782_3_parameter_value, s_b_7_6);
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
    /* execute.a64:975 [D] s_b_8_0 = sym_15236_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_15236_0_address, emitter.context().types().u64());
    /* execute.a64:975 [F] s_b_8_1=sym_15230_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_8_2 = (u64)s_b_8_1 (const) */
    /* ???:4294967295 [D] s_b_8_3 = s_b_8_0+s_b_8_2 */
    auto s_b_8_3 = emitter.add(s_b_8_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:975 [D] s_b_8_4: sym_15236_0_address = s_b_8_3, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_15236_0_address, s_b_8_3);
    /* execute.a64:975 [F] s_b_8_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:978 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:978 [D] s_b_9_1 = sym_15236_0_address uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_15236_0_address, emitter.context().types().u64());
    /* execute.a64:978 [D] s_b_9_2: sym_100697_3_parameter_value = s_b_9_1, dominates: s_b_15_0 s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_100697_3_parameter_value, s_b_9_1);
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
    /* execute.a64:2796 [F] s_b_10_0=sym_15230_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_10_2: sym_100105_1__R_s_b_0_5 = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_100105_1__R_s_b_0_5, s_b_10_1);
    /* execute.a64:2796 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_24,  */
  fixed_block_b_11: 
  {
    /* execute.a64:958 [D] s_b_11_0 = sym_100105_1__R_s_b_0_5 uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_100105_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:958 [D] s_b_11_1: sym_15236_0_address = s_b_11_0, dominates: s_b_1_0 s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15236_0_address, s_b_11_0);
    /* execute.a64:960 [F] s_b_11_2=sym_15230_3_parameter_inst.P (const) */
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
    /* execute.a64:1786 [D] s_b_12_1 = sym_100134_3_parameter_address uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_100134_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_12_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_12_1);
    /* execute.a64:0 [F] s_b_12_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_6, b_30,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1786 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_13_1 = sym_100325_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_100325_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_31,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1786 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_14_1 = sym_100516_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_100516_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_14_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2810 [D] s_b_15_0 = sym_100697_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_100697_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_15_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_15_2 = s_b_15_0&s_b_15_1 */
    auto s_b_15_2 = emitter.bitwise_and(s_b_15_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_15_3: sym_100697_3_parameter_value = s_b_15_2, dominates: s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_100697_3_parameter_value, s_b_15_2);
    /* execute.a64:2810 [F] s_b_15_4: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_9, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2813 [F] s_b_16_0=sym_15230_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_17_0 = sym_100697_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_100697_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_17_1: sym_101588_3_parameter_value = s_b_17_0, dominates: s_b_25_0 s_b_26_0 s_b_27_0  */
    emitter.store_local(DV_sym_101588_3_parameter_value, s_b_17_0);
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
    /* execute.a64:2816 [F] s_b_18_0=sym_15230_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_18_1 = sym_100697_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_100697_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2765 [D] s_b_21_1: sym_100753_1__R_s_b_14_0 = s_b_21_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_100753_1__R_s_b_14_0, s_b_21_0);
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
    /* execute.a64:2768 [D] s_b_22_1: sym_100753_1__R_s_b_14_0 = s_b_22_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_100753_1__R_s_b_14_0, s_b_22_0);
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
    /* execute.a64:2770 [D] s_b_23_1: sym_100753_1__R_s_b_14_0 = s_b_23_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_100753_1__R_s_b_14_0, s_b_23_0);
    /* execute.a64:2770 [F] s_b_23_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2794 [D] s_b_24_0 = sym_100753_1__R_s_b_14_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_100753_1__R_s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_24_1: sym_100105_1__R_s_b_0_5 = s_b_24_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_100105_1__R_s_b_0_5, s_b_24_0);
    /* execute.a64:2794 [F] s_b_24_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_17,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2778 [D] s_b_25_0 = sym_101588_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_101588_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_26_0 = sym_101588_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_101588_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_27_0 = sym_101588_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_101588_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_29_0=sym_15230_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_29_1 = sym_101784_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_101784_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_30_0=sym_15230_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_30_1 = sym_102294_3_parameter_value uint64_t */
    auto s_b_30_1 = emitter.load_local(DV_sym_102294_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_31_0=sym_15230_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_31_1 = sym_102782_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_102782_3_parameter_value, emitter.context().types().u64());
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
  auto DV_sym_112816_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112736_1__R_s_b_13_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112838_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112620_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112904_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16163_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_16149_3_parameter_inst.rn (const) */
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
    /* execute.a64:1399 [D] s_b_1_0 = sym_16163_0_value uint16_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16163_0_value, emitter.context().types().u16());
    /* execute.a64:1399 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_2=sym_16149_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_3 = (u32)s_b_1_1 */
    auto s_b_1_3 = emitter.truncate(s_b_1_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_5: sym_112816_3_parameter_value = s_b_1_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_112816_3_parameter_value, s_b_1_4);
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
    /* execute.a64:1400 [F] s_b_3_0=sym_16149_3_parameter_inst.opc (const) */
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
    /* execute.a64:1401 [D] s_b_4_0 = sym_16163_0_value uint16_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_16163_0_value, emitter.context().types().u16());
    /* execute.a64:1401 [D] s_b_4_1 = (s16)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s16());
    /* execute.a64:1401 [D] s_b_4_2 = (s64)s_b_4_1 */
    auto s_b_4_2 = emitter.sx(s_b_4_1, emitter.context().types().s64());
    /* execute.a64:1401 [D] s_b_4_3 = (u64)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_4_4=sym_16149_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_4_5: sym_112838_3_parameter_value = s_b_4_3, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_112838_3_parameter_value, s_b_4_3);
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
    /* execute.a64:1402 [F] s_b_5_0=sym_16149_3_parameter_inst.opc (const) */
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
    /* execute.a64:1403 [D] s_b_6_0 = sym_16163_0_value uint16_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_16163_0_value, emitter.context().types().u16());
    /* execute.a64:1403 [D] s_b_6_1 = (s16)s_b_6_0 */
    auto s_b_6_1 = emitter.reinterpret(s_b_6_0, emitter.context().types().s16());
    /* execute.a64:1403 [D] s_b_6_2 = (s64)s_b_6_1 */
    auto s_b_6_2 = emitter.sx(s_b_6_1, emitter.context().types().s64());
    /* execute.a64:1403 [D] s_b_6_3 = (u64)s_b_6_2 */
    auto s_b_6_3 = emitter.reinterpret(s_b_6_2, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_4=sym_16149_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_6_5 = (u32)s_b_6_3 */
    auto s_b_6_5 = emitter.truncate(s_b_6_3, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_7: sym_112904_3_parameter_value = s_b_6_6, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_112904_3_parameter_value, s_b_6_6);
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
    /* execute.a64:2796 [F] s_b_8_0=sym_16149_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_8_2: sym_112620_1__R_s_b_0_5 = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_112620_1__R_s_b_0_5, s_b_8_1);
    /* execute.a64:2796 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_14,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1392 [D] s_b_9_0 = sym_112620_1__R_s_b_0_5 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_112620_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1393 [F] s_b_9_1=sym_16149_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_9_2 = (u64)s_b_9_1 (const) */
    /* ???:4294967295 [D] s_b_9_3 = s_b_9_0+s_b_9_2 */
    auto s_b_9_3 = emitter.add(s_b_9_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* ???:4294967295 [D] s_b_9_4 = Load 2 s_b_9_3 => sym_16163_0_value */
    auto s_b_9_4 = emitter.load_memory(s_b_9_3, emitter.context().types().u16());
    emitter.store_local(DV_sym_16163_0_value, s_b_9_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_3, s_b_9_4, emitter.const_u8(2));
    }
    /* execute.a64:1398 [F] s_b_9_5=sym_16149_3_parameter_inst.opc (const) */
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
    /* execute.a64:2765 [D] s_b_11_1: sym_112736_1__R_s_b_13_0 = s_b_11_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_112736_1__R_s_b_13_0, s_b_11_0);
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
    /* execute.a64:2768 [D] s_b_12_1: sym_112736_1__R_s_b_13_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_112736_1__R_s_b_13_0, s_b_12_0);
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
    /* execute.a64:2770 [D] s_b_13_1: sym_112736_1__R_s_b_13_0 = s_b_13_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_112736_1__R_s_b_13_0, s_b_13_0);
    /* execute.a64:2770 [F] s_b_13_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_11, b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2794 [D] s_b_14_0 = sym_112736_1__R_s_b_13_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_112736_1__R_s_b_13_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_14_1: sym_112620_1__R_s_b_0_5 = s_b_14_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_112620_1__R_s_b_0_5, s_b_14_0);
    /* execute.a64:2794 [F] s_b_14_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2747 [F] s_b_15_0=sym_16149_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_15_1 = sym_112816_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_112816_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_16_0=sym_16149_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_16_1 = sym_112838_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_112838_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_17_0=sym_16149_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_112904_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_112904_3_parameter_value, emitter.context().types().u64());
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
  uint64_t CV_sym_123549_1_temporary_value;
  auto DV_sym_123549_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_123406_1_temporary_value;
  auto DV_sym_123406_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_123440_1__R_s_b_4_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123654_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_123490_1_temporary_value;
  auto DV_sym_123490_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_123524_1__R_s_b_18_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123535_1_tmp_s_b_18_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_123462_1_temporary_value;
  auto DV_sym_123462_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123532_1_tmp_s_b_18_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123602_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_123577_1_temporary_value;
  auto DV_sym_123577_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_123632_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123448_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_123378_1_temporary_value;
  auto DV_sym_123378_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_123359_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2406 [F] s_b_0_0=sym_16477_3_parameter_inst.sf (const) */
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
    /* execute.a64:2720 [F] s_b_1_0=sym_16477_3_parameter_inst.ra (const) */
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
    /* execute.a64:2722 [F] s_b_2_0=sym_16477_3_parameter_inst.ra (const) */
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
    /* execute.a64:2406 [D] s_b_3_0 = sym_123359_1__R_s_b_0_4 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_123359_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2406 [F] s_b_3_1=sym_16477_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_123448_1_tmp_s_b_4_0 = s_b_3_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_123448_1_tmp_s_b_4_0, s_b_3_0);
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
    /* execute.a64:2714 [F] s_b_4_1: sym_123378_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_123378_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_123378_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2714 [F] s_b_5_0=sym_16477_3_parameter_inst.ra (const) */
    /* execute.a64:2714 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_5_2: sym_123378_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_123378_1_temporary_value, s_b_5_1);
    /* execute.a64:2714 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2714 [D] s_b_6_0 = sym_123378_1_temporary_value uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_123378_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_6_1: sym_123359_1__R_s_b_0_4 = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_123359_1__R_s_b_0_4, s_b_6_0);
    /* execute.a64:2720 [F] s_b_6_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2709 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_7_1: sym_123406_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_123406_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_123406_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2709 [F] s_b_8_0=sym_16477_3_parameter_inst.ra (const) */
    /* execute.a64:2709 [D] s_b_8_1 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_8_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_8_2: sym_123406_1_temporary_value = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_123406_1_temporary_value, s_b_8_1);
    /* execute.a64:2709 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2709 [D] s_b_9_0 = sym_123406_1_temporary_value uint32_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_123406_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_9_1 = (u64)s_b_9_0 */
    auto s_b_9_1 = emitter.zx(s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_9_2: sym_123359_1__R_s_b_0_4 = s_b_9_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_123359_1__R_s_b_0_4, s_b_9_1);
    /* execute.a64:2722 [F] s_b_9_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2720 [F] s_b_10_0=sym_16477_3_parameter_inst.rn (const) */
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
    /* execute.a64:2722 [F] s_b_11_0=sym_16477_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [D] s_b_12_0 = sym_123448_1_tmp_s_b_4_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_123448_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2406 [D] s_b_12_1 = sym_123440_1__R_s_b_4_5 uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_123440_1__R_s_b_4_5, emitter.context().types().u64());
    /* execute.a64:2406 [F] s_b_12_2=sym_16477_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_12_3: sym_123532_1_tmp_s_b_18_0 = s_b_12_0, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_123532_1_tmp_s_b_18_0, s_b_12_0);
    /* ???:4294967295 [D] s_b_12_4: sym_123535_1_tmp_s_b_18_1 = s_b_12_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_123535_1_tmp_s_b_18_1, s_b_12_1);
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
    /* execute.a64:2714 [F] s_b_13_1: sym_123462_1_temporary_value = s_b_13_0 (const), dominates: s_b_15_0  */
    CV_sym_123462_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_123462_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2714 [F] s_b_14_0=sym_16477_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_14_2: sym_123462_1_temporary_value = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_123462_1_temporary_value, s_b_14_1);
    /* execute.a64:2714 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2714 [D] s_b_15_0 = sym_123462_1_temporary_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_123462_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_15_1: sym_123440_1__R_s_b_4_5 = s_b_15_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_123440_1__R_s_b_4_5, s_b_15_0);
    /* execute.a64:2720 [F] s_b_15_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [F] s_b_16_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_16_1: sym_123490_1_temporary_value = s_b_16_0 (const), dominates: s_b_18_0  */
    CV_sym_123490_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_123490_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_11,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2709 [F] s_b_17_0=sym_16477_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_17_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_17_2: sym_123490_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_123490_1_temporary_value, s_b_17_1);
    /* execute.a64:2709 [F] s_b_17_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_16, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2709 [D] s_b_18_0 = sym_123490_1_temporary_value uint32_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_123490_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
    auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_18_2: sym_123440_1__R_s_b_4_5 = s_b_18_1, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_123440_1__R_s_b_4_5, s_b_18_1);
    /* execute.a64:2722 [F] s_b_18_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_12,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2720 [F] s_b_19_0=sym_16477_3_parameter_inst.rm (const) */
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
    /* execute.a64:2722 [F] s_b_20_0=sym_16477_3_parameter_inst.rm (const) */
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
    /* ???:4294967295 [D] s_b_21_0 = sym_123535_1_tmp_s_b_18_1 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_123535_1_tmp_s_b_18_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_1 = sym_123532_1_tmp_s_b_18_0 uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_123532_1_tmp_s_b_18_0, emitter.context().types().u64());
    /* execute.a64:2406 [D] s_b_21_2 = sym_123524_1__R_s_b_18_6 uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_123524_1__R_s_b_18_6, emitter.context().types().u64());
    /* execute.a64:2406 [D] s_b_21_3 = s_b_21_0*s_b_21_2 */
    auto s_b_21_3 = emitter.mul(s_b_21_0, s_b_21_2);
    /* execute.a64:2406 [D] s_b_21_4 = s_b_21_1+s_b_21_3 */
    auto s_b_21_4 = emitter.add(s_b_21_1, s_b_21_3);
    /* execute.a64:2407 [F] s_b_21_5=sym_16477_3_parameter_inst.sf (const) */
    /* execute.a64:2407 [D] s_b_21_6: sym_123602_3_parameter_value = s_b_21_4, dominates: s_b_28_1 s_b_29_1  */
    emitter.store_local(DV_sym_123602_3_parameter_value, s_b_21_4);
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
    /* execute.a64:2714 [F] s_b_22_1: sym_123549_1_temporary_value = s_b_22_0 (const), dominates: s_b_24_0  */
    CV_sym_123549_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_123549_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_22_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [F] s_b_23_0=sym_16477_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_23_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_23_2: sym_123549_1_temporary_value = s_b_23_1, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_123549_1_temporary_value, s_b_23_1);
    /* execute.a64:2714 [F] s_b_23_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [D] s_b_24_0 = sym_123549_1_temporary_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_123549_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_24_1: sym_123524_1__R_s_b_18_6 = s_b_24_0, dominates: s_b_21_2  */
    emitter.store_local(DV_sym_123524_1__R_s_b_18_6, s_b_24_0);
    /* execute.a64:2720 [F] s_b_24_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2709 [F] s_b_25_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_25_1: sym_123577_1_temporary_value = s_b_25_0 (const), dominates: s_b_27_0  */
    CV_sym_123577_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_123577_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_25_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_20,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2709 [F] s_b_26_0=sym_16477_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_26_2: sym_123577_1_temporary_value = s_b_26_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_123577_1_temporary_value, s_b_26_1);
    /* execute.a64:2709 [F] s_b_26_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_25, b_26,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2709 [D] s_b_27_0 = sym_123577_1_temporary_value uint32_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_123577_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_27_1 = (u64)s_b_27_0 */
    auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_27_2: sym_123524_1__R_s_b_18_6 = s_b_27_1, dominates: s_b_21_2  */
    emitter.store_local(DV_sym_123524_1__R_s_b_18_6, s_b_27_1);
    /* execute.a64:2722 [F] s_b_27_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_21,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2754 [F] s_b_28_0=sym_16477_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_28_1 = sym_123602_3_parameter_value uint64_t */
    auto s_b_28_1 = emitter.load_local(DV_sym_123602_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_28_2: sym_123632_3_parameter_value = s_b_28_1, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_123632_3_parameter_value, s_b_28_1);
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
    /* execute.a64:2756 [F] s_b_29_0=sym_16477_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_29_1 = sym_123602_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_123602_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_29_2 = (u32)s_b_29_1 */
    auto s_b_29_2 = emitter.truncate(s_b_29_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_29_3 = (u64)s_b_29_2 */
    auto s_b_29_3 = emitter.zx(s_b_29_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_29_4: sym_123654_3_parameter_value = s_b_29_3, dominates: s_b_32_1  */
    emitter.store_local(DV_sym_123654_3_parameter_value, s_b_29_3);
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
    /* execute.a64:2747 [F] s_b_31_0=sym_16477_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_31_1 = sym_123632_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_123632_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_32_0=sym_16477_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_32_1 = sym_123654_3_parameter_value uint64_t */
    auto s_b_32_1 = emitter.load_local(DV_sym_123654_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:378 [F] s_b_0_0=sym_17835_3_parameter_inst.op1 (const) */
    /* execute.a64:378 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:378 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:378 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* execute.a64:378 [F] s_b_0_4=sym_17835_3_parameter_inst.op2 (const) */
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
    /* execute.a64:380 [F] s_b_1_0=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.a64:381 [F] s_b_3_0=sym_17835_3_parameter_inst.op1 (const) */
    /* execute.a64:381 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:381 [F] s_b_3_2 = constant u32 3 (const) */
    /* execute.a64:381 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* execute.a64:381 [F] s_b_3_4=sym_17835_3_parameter_inst.op2 (const) */
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
    /* execute.a64:383 [F] s_b_4_1=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.a64:384 [F] s_b_4_10=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.a64:385 [F] s_b_4_19=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.a64:386 [F] s_b_4_28=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.a64:387 [F] s_b_5_0=sym_17835_3_parameter_inst.op1 (const) */
    /* execute.a64:387 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:387 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:387 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* execute.a64:387 [F] s_b_5_4=sym_17835_3_parameter_inst.op2 (const) */
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
    /* execute.a64:389 [F] s_b_6_1=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.a64:390 [F] s_b_6_10=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.a64:391 [F] s_b_6_19=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.a64:392 [F] s_b_6_28=sym_17835_3_parameter_inst.crm (const) */
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
    /* execute.simd:6127 [F] s_b_0_0=sym_19341_3_parameter_inst.Q (const) */
    /* execute.simd:6127 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:6127 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:6127 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:6127 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:6128 [F] s_b_1_0=sym_19341_3_parameter_inst.rd (const) */
    /* execute.simd:6128 [F] s_b_1_1=sym_19341_3_parameter_inst.rn (const) */
    /* execute.simd:6237 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:6128 [D] s_b_1_3 = ~s_b_1_2 */
    auto s_b_1_3 = emitter.bitwise_not(s_b_1_2);
    /* execute.simd:6208 [D] s_b_1_4: WriteRegBank 2:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3);
    /* execute.simd:6209 [F] s_b_1_5 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_1_6: WriteRegBank 3:s_b_1_0 = s_b_1_5 */
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
    /* execute.simd:6133 [F] s_b_3_0=sym_19341_3_parameter_inst.rn (const) */
    /* execute.simd:6242 [D] s_b_3_1 = ReadRegBank 2:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:6243 [D] s_b_3_2 = ReadRegBank 3:s_b_3_0 (u64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:6134 [F] s_b_3_3=sym_19341_3_parameter_inst.rd (const) */
    /* execute.simd:6134 [D] s_b_3_4 = ~s_b_3_1 */
    auto s_b_3_4 = emitter.bitwise_not(s_b_3_1);
    /* execute.simd:6134 [D] s_b_3_5 = ~s_b_3_2 */
    auto s_b_3_5 = emitter.bitwise_not(s_b_3_2);
    /* execute.simd:6215 [D] s_b_3_6: WriteRegBank 2:s_b_3_3 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:6216 [D] s_b_3_7: WriteRegBank 3:s_b_3_3 = s_b_3_5 */
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
    /* execute.simd:635 [F] s_b_0_0=sym_20125_3_parameter_inst.arrangement (const) */
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
    /* execute.simd:637 [F] s_b_2_0=sym_20125_3_parameter_inst.rn (const) */
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
    /* execute.simd:642 [F] s_b_2_12=sym_20125_3_parameter_inst.rd (const) */
    /* execute.simd:642 [D] s_b_2_13: WriteRegBank 19:s_b_2_12 = s_b_2_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_11,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_11);
    /* execute.simd:643 [F] s_b_2_14=sym_20125_3_parameter_inst.rd (const) */
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
    /* execute.simd:647 [F] s_b_3_0=sym_20125_3_parameter_inst.rn (const) */
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
    /* execute.simd:654 [F] s_b_3_22=sym_20125_3_parameter_inst.rd (const) */
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
    /* execute.simd:658 [F] s_b_4_0=sym_20125_3_parameter_inst.rn (const) */
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
    /* execute.simd:663 [F] s_b_4_14=sym_20125_3_parameter_inst.rd (const) */
    /* execute.simd:663 [D] s_b_4_15: WriteRegBank 19:s_b_4_14 = s_b_4_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_13);
    /* execute.simd:664 [F] s_b_4_16=sym_20125_3_parameter_inst.rd (const) */
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
    /* execute.simd:668 [F] s_b_5_0=sym_20125_3_parameter_inst.rn (const) */
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
    /* execute.simd:675 [F] s_b_5_26=sym_20125_3_parameter_inst.rd (const) */
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
  uint64_t CV_sym_131340_1_temporary_value;
  auto DV_sym_131340_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_131218_1_temporary_value;
  auto DV_sym_131218_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_131408_1_temporary_value;
  auto DV_sym_131408_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_131286_1_temporary_value;
  auto DV_sym_131286_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4228 [F] s_b_0_0=sym_22376_3_parameter_inst.sf (const) */
    /* execute.simd:4228 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4228 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4228 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4228 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4229 [F] s_b_1_0=sym_22376_3_parameter_inst.type (const) */
    /* execute.simd:4229 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4229 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4229 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4229 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4236 [F] s_b_3_0=sym_22376_3_parameter_inst.sf (const) */
    /* execute.simd:4236 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4236 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4236 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4236 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_2 (const) */
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
    /* execute.simd:4231 [F] s_b_4_0=sym_22376_3_parameter_inst.rn (const) */
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
    /* execute.simd:4232 [F] s_b_5_0=sym_22376_3_parameter_inst.type (const) */
    /* execute.simd:4232 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4232 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4232 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4232 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
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
    /* execute.simd:4234 [F] s_b_6_0=sym_22376_3_parameter_inst.rn (const) */
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
    /* execute.simd:4237 [F] s_b_7_0=sym_22376_3_parameter_inst.type (const) */
    /* execute.simd:4237 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4237 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4237 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4237 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4239 [F] s_b_8_0=sym_22376_3_parameter_inst.rn (const) */
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
    /* execute.simd:4240 [F] s_b_9_0=sym_22376_3_parameter_inst.type (const) */
    /* execute.simd:4240 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4240 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4240 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4240 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_2 (const) */
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
    /* execute.simd:4242 [F] s_b_10_0=sym_22376_3_parameter_inst.rn (const) */
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
    /* execute.a64:2709 [F] s_b_11_1: sym_131218_1_temporary_value = s_b_11_0 (const), dominates: s_b_13_0  */
    CV_sym_131218_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_131218_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0=sym_22376_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_12_1 = ReadRegBank 1:s_b_12_0 (u32) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_12_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_12_2: sym_131218_1_temporary_value = s_b_12_1, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_131218_1_temporary_value, s_b_12_1);
    /* execute.a64:2709 [F] s_b_12_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_11, b_12,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [D] s_b_13_0 = sym_131218_1_temporary_value uint32_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_131218_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_13_1 = (u64)s_b_13_0 */
    auto s_b_13_1 = emitter.zx(s_b_13_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_13_2=sym_22376_3_parameter_inst.rd (const) */
    /* execute.simd:4231 [D] s_b_13_3 = (s32)s_b_13_1 */
    auto s_b_13_3 = emitter.truncate(s_b_13_1, emitter.context().types().s32());
    /* execute.simd:4231 [D] s_b_13_4 = (f32)s_b_13_3 */
    auto s_b_13_4 = emitter.convert(s_b_13_3, emitter.context().types().f32());
    /* execute.simd:6172 [D] s_b_13_5: WriteRegBank 9:s_b_13_2 = s_b_13_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_4);
    /* execute.simd:6173 [F] s_b_13_6 = constant u32 0 (const) */
    /* execute.simd:6173 [F] s_b_13_7: WriteRegBank 10:s_b_13_2 = s_b_13_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6174 [F] s_b_13_8 = constant u64 0 (const) */
    /* execute.simd:6174 [F] s_b_13_9: WriteRegBank 3:s_b_13_2 = s_b_13_8 */
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
    /* execute.a64:2709 [F] s_b_14_1: sym_131286_1_temporary_value = s_b_14_0 (const), dominates: s_b_16_0  */
    CV_sym_131286_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_131286_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_14_2: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2709 [F] s_b_15_0=sym_22376_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_15_1 = ReadRegBank 1:s_b_15_0 (u32) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_15_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_15_2: sym_131286_1_temporary_value = s_b_15_1, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_131286_1_temporary_value, s_b_15_1);
    /* execute.a64:2709 [F] s_b_15_3: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_14, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [D] s_b_16_0 = sym_131286_1_temporary_value uint32_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_131286_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_16_1 = (u64)s_b_16_0 */
    auto s_b_16_1 = emitter.zx(s_b_16_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_16_2=sym_22376_3_parameter_inst.rd (const) */
    /* execute.simd:4234 [D] s_b_16_3 = (s32)s_b_16_1 */
    auto s_b_16_3 = emitter.truncate(s_b_16_1, emitter.context().types().s32());
    /* execute.simd:4234 [D] s_b_16_4 = (f64)s_b_16_3 */
    auto s_b_16_4 = emitter.convert(s_b_16_3, emitter.context().types().f64());
    /* execute.simd:6180 [D] s_b_16_5: WriteRegBank 11:s_b_16_2 = s_b_16_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_4);
    /* execute.simd:6181 [F] s_b_16_6 = constant u64 0 (const) */
    /* execute.simd:6181 [F] s_b_16_7: WriteRegBank 3:s_b_16_2 = s_b_16_6 */
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
    /* execute.a64:2714 [F] s_b_17_1: sym_131340_1_temporary_value = s_b_17_0 (const), dominates: s_b_19_0  */
    CV_sym_131340_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_131340_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_17_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_8,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2714 [F] s_b_18_0=sym_22376_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_18_2: sym_131340_1_temporary_value = s_b_18_1, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_131340_1_temporary_value, s_b_18_1);
    /* execute.a64:2714 [F] s_b_18_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_17, b_18,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2714 [D] s_b_19_0 = sym_131340_1_temporary_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_131340_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1=sym_22376_3_parameter_inst.rd (const) */
    /* execute.simd:4239 [D] s_b_19_2 = (s64)s_b_19_0 */
    auto s_b_19_2 = emitter.reinterpret(s_b_19_0, emitter.context().types().s64());
    /* execute.simd:4239 [D] s_b_19_3 = (f32)s_b_19_2 */
    auto s_b_19_3 = emitter.convert(s_b_19_2, emitter.context().types().f32());
    /* execute.simd:6172 [D] s_b_19_4: WriteRegBank 9:s_b_19_1 = s_b_19_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_19_3,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_19_3);
    /* execute.simd:6173 [F] s_b_19_5 = constant u32 0 (const) */
    /* execute.simd:6173 [F] s_b_19_6: WriteRegBank 10:s_b_19_1 = s_b_19_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6174 [F] s_b_19_7 = constant u64 0 (const) */
    /* execute.simd:6174 [F] s_b_19_8: WriteRegBank 3:s_b_19_1 = s_b_19_7 */
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
    /* execute.a64:2714 [F] s_b_20_1: sym_131408_1_temporary_value = s_b_20_0 (const), dominates: s_b_22_0  */
    CV_sym_131408_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_131408_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_10,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2714 [F] s_b_21_0=sym_22376_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_21_2: sym_131408_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_131408_1_temporary_value, s_b_21_1);
    /* execute.a64:2714 [F] s_b_21_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2714 [D] s_b_22_0 = sym_131408_1_temporary_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_131408_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_22_1=sym_22376_3_parameter_inst.rd (const) */
    /* execute.simd:4242 [D] s_b_22_2 = (s64)s_b_22_0 */
    auto s_b_22_2 = emitter.reinterpret(s_b_22_0, emitter.context().types().s64());
    /* execute.simd:4242 [D] s_b_22_3 = (f64)s_b_22_2 */
    auto s_b_22_3 = emitter.convert(s_b_22_2, emitter.context().types().f64());
    /* execute.simd:6180 [D] s_b_22_4: WriteRegBank 11:s_b_22_1 = s_b_22_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_3);
    /* execute.simd:6181 [F] s_b_22_5 = constant u64 0 (const) */
    /* execute.simd:6181 [F] s_b_22_6: WriteRegBank 3:s_b_22_1 = s_b_22_5 */
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
    /* execute.simd:2891 [F] s_b_0_0=sym_23805_3_parameter_inst.arrangement (const) */
    /* execute.simd:2892 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:2904 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:2914 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:2925 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:2935 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:2946 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:2891 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:2893 [F] s_b_2_0=sym_23805_3_parameter_inst.rn (const) */
    /* execute.simd:2893 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:2893 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:2894 [F] s_b_2_3=sym_23805_3_parameter_inst.rm (const) */
    /* execute.simd:2894 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:2894 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* execute.simd:2896 [D] s_b_2_6 = s_b_2_2>s_b_2_5 */
    auto s_b_2_6 = emitter.cmp_gt(s_b_2_2, s_b_2_5);
    /* execute.simd:2897 [D] s_b_2_7 = ~s_b_2_6 */
    auto s_b_2_7 = emitter.bitwise_not(s_b_2_6);
    /* execute.simd:2897 [D] s_b_2_8 = s_b_2_2&s_b_2_7 */
    auto s_b_2_8 = emitter.bitwise_and(s_b_2_2, s_b_2_7);
    /* execute.simd:2897 [D] s_b_2_9 = s_b_2_5&s_b_2_6 */
    auto s_b_2_9 = emitter.bitwise_and(s_b_2_5, s_b_2_6);
    /* execute.simd:2897 [D] s_b_2_10 = s_b_2_8|s_b_2_9 */
    auto s_b_2_10 = emitter.bitwise_or(s_b_2_8, s_b_2_9);
    /* execute.simd:2899 [F] s_b_2_11=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2899 [D] s_b_2_12 = (v8u8)s_b_2_10 */
    auto s_b_2_12 = emitter.reinterpret(s_b_2_10, emitter.context().types().v8u8());
    /* execute.simd:2899 [D] s_b_2_13: WriteRegBank 15:s_b_2_11 = s_b_2_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_12);
    /* execute.simd:2900 [F] s_b_2_14=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2900 [F] s_b_2_15 = constant u64 0 (const) */
    /* execute.simd:2900 [F] s_b_2_16: WriteRegBank 3:s_b_2_14 = s_b_2_15 */
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
    /* execute.simd:2905 [F] s_b_3_0=sym_23805_3_parameter_inst.rn (const) */
    /* execute.simd:2905 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:2905 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:2906 [F] s_b_3_3=sym_23805_3_parameter_inst.rm (const) */
    /* execute.simd:2906 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:2906 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* execute.simd:2908 [D] s_b_3_6 = s_b_3_2>s_b_3_5 */
    auto s_b_3_6 = emitter.cmp_gt(s_b_3_2, s_b_3_5);
    /* execute.simd:2909 [D] s_b_3_7 = ~s_b_3_6 */
    auto s_b_3_7 = emitter.bitwise_not(s_b_3_6);
    /* execute.simd:2909 [D] s_b_3_8 = s_b_3_2&s_b_3_7 */
    auto s_b_3_8 = emitter.bitwise_and(s_b_3_2, s_b_3_7);
    /* execute.simd:2909 [D] s_b_3_9 = s_b_3_5&s_b_3_6 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_5, s_b_3_6);
    /* execute.simd:2909 [D] s_b_3_10 = s_b_3_8|s_b_3_9 */
    auto s_b_3_10 = emitter.bitwise_or(s_b_3_8, s_b_3_9);
    /* execute.simd:2911 [F] s_b_3_11=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2911 [D] s_b_3_12 = (v16u8)s_b_3_10 */
    auto s_b_3_12 = emitter.reinterpret(s_b_3_10, emitter.context().types().v16u8());
    /* execute.simd:2911 [D] s_b_3_13: WriteRegBank 16:s_b_3_11 = s_b_3_12 */
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
    /* execute.simd:2915 [F] s_b_4_0=sym_23805_3_parameter_inst.rn (const) */
    /* execute.simd:2915 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:2915 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:2916 [F] s_b_4_3=sym_23805_3_parameter_inst.rm (const) */
    /* execute.simd:2916 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:2916 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* execute.simd:2918 [D] s_b_4_6 = s_b_4_2>s_b_4_5 */
    auto s_b_4_6 = emitter.cmp_gt(s_b_4_2, s_b_4_5);
    /* execute.simd:2919 [D] s_b_4_7 = ~s_b_4_6 */
    auto s_b_4_7 = emitter.bitwise_not(s_b_4_6);
    /* execute.simd:2919 [D] s_b_4_8 = s_b_4_2&s_b_4_7 */
    auto s_b_4_8 = emitter.bitwise_and(s_b_4_2, s_b_4_7);
    /* execute.simd:2919 [D] s_b_4_9 = s_b_4_5&s_b_4_6 */
    auto s_b_4_9 = emitter.bitwise_and(s_b_4_5, s_b_4_6);
    /* execute.simd:2919 [D] s_b_4_10 = s_b_4_8|s_b_4_9 */
    auto s_b_4_10 = emitter.bitwise_or(s_b_4_8, s_b_4_9);
    /* execute.simd:2921 [F] s_b_4_11=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2921 [D] s_b_4_12 = (v4u16)s_b_4_10 */
    auto s_b_4_12 = emitter.reinterpret(s_b_4_10, emitter.context().types().v4u16());
    /* execute.simd:2921 [D] s_b_4_13: WriteRegBank 17:s_b_4_11 = s_b_4_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_12);
    /* execute.simd:2922 [F] s_b_4_14=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2922 [F] s_b_4_15 = constant u64 0 (const) */
    /* execute.simd:2922 [F] s_b_4_16: WriteRegBank 3:s_b_4_14 = s_b_4_15 */
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
    /* execute.simd:2926 [F] s_b_5_0=sym_23805_3_parameter_inst.rn (const) */
    /* execute.simd:2926 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:2926 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:2927 [F] s_b_5_3=sym_23805_3_parameter_inst.rm (const) */
    /* execute.simd:2927 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:2927 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* execute.simd:2929 [D] s_b_5_6 = s_b_5_2>s_b_5_5 */
    auto s_b_5_6 = emitter.cmp_gt(s_b_5_2, s_b_5_5);
    /* execute.simd:2930 [D] s_b_5_7 = ~s_b_5_6 */
    auto s_b_5_7 = emitter.bitwise_not(s_b_5_6);
    /* execute.simd:2930 [D] s_b_5_8 = s_b_5_2&s_b_5_7 */
    auto s_b_5_8 = emitter.bitwise_and(s_b_5_2, s_b_5_7);
    /* execute.simd:2930 [D] s_b_5_9 = s_b_5_5&s_b_5_6 */
    auto s_b_5_9 = emitter.bitwise_and(s_b_5_5, s_b_5_6);
    /* execute.simd:2930 [D] s_b_5_10 = s_b_5_8|s_b_5_9 */
    auto s_b_5_10 = emitter.bitwise_or(s_b_5_8, s_b_5_9);
    /* execute.simd:2932 [F] s_b_5_11=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2932 [D] s_b_5_12 = (v8u16)s_b_5_10 */
    auto s_b_5_12 = emitter.reinterpret(s_b_5_10, emitter.context().types().v8u16());
    /* execute.simd:2932 [D] s_b_5_13: WriteRegBank 18:s_b_5_11 = s_b_5_12 */
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
    /* execute.simd:2936 [F] s_b_6_0=sym_23805_3_parameter_inst.rn (const) */
    /* execute.simd:2936 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:2936 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:2937 [F] s_b_6_3=sym_23805_3_parameter_inst.rm (const) */
    /* execute.simd:2937 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:2937 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* execute.simd:2939 [D] s_b_6_6 = s_b_6_2>s_b_6_5 */
    auto s_b_6_6 = emitter.cmp_gt(s_b_6_2, s_b_6_5);
    /* execute.simd:2940 [D] s_b_6_7 = ~s_b_6_6 */
    auto s_b_6_7 = emitter.bitwise_not(s_b_6_6);
    /* execute.simd:2940 [D] s_b_6_8 = s_b_6_2&s_b_6_7 */
    auto s_b_6_8 = emitter.bitwise_and(s_b_6_2, s_b_6_7);
    /* execute.simd:2940 [D] s_b_6_9 = s_b_6_5&s_b_6_6 */
    auto s_b_6_9 = emitter.bitwise_and(s_b_6_5, s_b_6_6);
    /* execute.simd:2940 [D] s_b_6_10 = s_b_6_8|s_b_6_9 */
    auto s_b_6_10 = emitter.bitwise_or(s_b_6_8, s_b_6_9);
    /* execute.simd:2942 [F] s_b_6_11=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2942 [D] s_b_6_12 = (v2u32)s_b_6_10 */
    auto s_b_6_12 = emitter.reinterpret(s_b_6_10, emitter.context().types().v2u32());
    /* execute.simd:2942 [D] s_b_6_13: WriteRegBank 19:s_b_6_11 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12);
    /* execute.simd:2943 [F] s_b_6_14=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2943 [F] s_b_6_15 = constant u64 0 (const) */
    /* execute.simd:2943 [F] s_b_6_16: WriteRegBank 3:s_b_6_14 = s_b_6_15 */
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
    /* execute.simd:2947 [F] s_b_7_0=sym_23805_3_parameter_inst.rn (const) */
    /* execute.simd:2947 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:2947 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:2948 [F] s_b_7_3=sym_23805_3_parameter_inst.rm (const) */
    /* execute.simd:2948 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:2948 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* execute.simd:2950 [D] s_b_7_6 = s_b_7_2>s_b_7_5 */
    auto s_b_7_6 = emitter.cmp_gt(s_b_7_2, s_b_7_5);
    /* execute.simd:2951 [D] s_b_7_7 = ~s_b_7_6 */
    auto s_b_7_7 = emitter.bitwise_not(s_b_7_6);
    /* execute.simd:2951 [D] s_b_7_8 = s_b_7_2&s_b_7_7 */
    auto s_b_7_8 = emitter.bitwise_and(s_b_7_2, s_b_7_7);
    /* execute.simd:2951 [D] s_b_7_9 = s_b_7_5&s_b_7_6 */
    auto s_b_7_9 = emitter.bitwise_and(s_b_7_5, s_b_7_6);
    /* execute.simd:2951 [D] s_b_7_10 = s_b_7_8|s_b_7_9 */
    auto s_b_7_10 = emitter.bitwise_or(s_b_7_8, s_b_7_9);
    /* execute.simd:2953 [F] s_b_7_11=sym_23805_3_parameter_inst.rd (const) */
    /* execute.simd:2953 [D] s_b_7_12 = (v4u32)s_b_7_10 */
    auto s_b_7_12 = emitter.reinterpret(s_b_7_10, emitter.context().types().v4u32());
    /* execute.simd:2953 [D] s_b_7_13: WriteRegBank 20:s_b_7_11 = s_b_7_12 */
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
    /* execute.simd:2957 [D] s_b_8_0 = trap */
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
    /* execute.simd:4769 [F] s_b_0_0=sym_28592_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4769 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4770 [F] s_b_1_0=sym_28592_3_parameter_inst.immh (const) */
    /* execute.simd:4770 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4770 [F] s_b_1_2 = constant u32 3 (const) */
    /* execute.simd:4770 [F] s_b_1_3 = s_b_1_1<<s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4770 [F] s_b_1_4=sym_28592_3_parameter_inst.immb (const) */
    /* execute.simd:4770 [F] s_b_1_5 = (u32)s_b_1_4 (const) */
    /* execute.simd:4770 [F] s_b_1_6 = s_b_1_3|s_b_1_5 (const) */
    uint32_t s_b_1_6 = ((uint32_t)(s_b_1_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4770 [F] s_b_1_7 = constant u32 80 (const) */
    /* execute.simd:4770 [F] s_b_1_8 = s_b_1_7-s_b_1_6 (const) */
    uint32_t s_b_1_8 = ((uint32_t)((uint32_t)128ULL - s_b_1_6));
    /* execute.simd:4770 [F] s_b_1_9 = (u64)s_b_1_8 (const) */
    /* execute.simd:4771 [F] s_b_1_10=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4771 [F] s_b_1_11=sym_28592_3_parameter_inst.rn (const) */
    /* execute.simd:6237 [D] s_b_1_12 = ReadRegBank 7:s_b_1_11 (u64) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_12,emitter.const_u8(8));
    }
    /* execute.simd:4771 [D] s_b_1_13 = (s64)s_b_1_12 */
    auto s_b_1_13 = emitter.reinterpret(s_b_1_12, emitter.context().types().s64());
    /* execute.simd:4771 [D] s_b_1_14 = (u64)s_b_1_13 */
    auto s_b_1_14 = emitter.reinterpret(s_b_1_13, emitter.context().types().u64());
    /* execute.simd:4771 [D] s_b_1_15 = s_b_1_14->>s_b_1_9 */
    auto s_b_1_15 = emitter.sar(s_b_1_14, emitter.const_u64(((uint64_t)s_b_1_8)));
    /* execute.simd:4771 [D] s_b_1_16 = (u64)s_b_1_15 */
    auto s_b_1_16 = (captive::arch::dbt::el::Value *)s_b_1_15;
    /* execute.simd:6208 [D] s_b_1_17: WriteRegBank 2:s_b_1_10 = s_b_1_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_16);
    /* execute.simd:6209 [F] s_b_1_18 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_1_19: WriteRegBank 3:s_b_1_10 = s_b_1_18 */
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
    /* execute.simd:4773 [F] s_b_3_0=sym_28592_3_parameter_inst.arrangement (const) */
    /* execute.simd:4774 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:4782 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:4789 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:4797 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:4804 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:4812 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:4819 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:4773 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
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
    /* execute.simd:4775 [F] s_b_4_0=sym_28592_3_parameter_inst.immh (const) */
    /* execute.simd:4775 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4775 [F] s_b_4_2 = constant u32 3 (const) */
    /* execute.simd:4775 [F] s_b_4_3 = s_b_4_1<<s_b_4_2 (const) */
    uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4775 [F] s_b_4_4=sym_28592_3_parameter_inst.immb (const) */
    /* execute.simd:4775 [F] s_b_4_5 = (u32)s_b_4_4 (const) */
    /* execute.simd:4775 [F] s_b_4_6 = s_b_4_3|s_b_4_5 (const) */
    uint32_t s_b_4_6 = ((uint32_t)(s_b_4_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4775 [F] s_b_4_7 = constant u32 10 (const) */
    /* execute.simd:4775 [F] s_b_4_8 = s_b_4_7-s_b_4_6 (const) */
    uint32_t s_b_4_8 = ((uint32_t)((uint32_t)16ULL - s_b_4_6));
    /* execute.simd:4775 [F] s_b_4_9 = (u64)s_b_4_8 (const) */
    /* execute.simd:4777 [F] s_b_4_10=sym_28592_3_parameter_inst.rn (const) */
    /* execute.simd:4777 [D] s_b_4_11 = ReadRegBank 15:s_b_4_10 (v8u8) */
    auto s_b_4_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_11,emitter.const_u8(8));
    }
    /* execute.simd:4778 [F] s_b_4_12=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4778 [D] s_b_4_13 = (v8s8)s_b_4_11 */
    auto s_b_4_13 = emitter.reinterpret(s_b_4_11, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_4_14 = (v8s8)s_b_4_9 (const) */
    auto s_b_4_14 = wutils::Vector<int8_t, 8>(((uint64_t)s_b_4_8));
    /* execute.simd:4778 [D] s_b_4_15 = s_b_4_13->>s_b_4_14 */
    auto s_b_4_15 = emitter.sar(s_b_4_13, emitter.constant_vector_splat(s_b_4_14[0], emitter.context().types().v8s8()));
    /* execute.simd:4778 [D] s_b_4_16 = (v8u8)s_b_4_15 */
    auto s_b_4_16 = emitter.reinterpret(s_b_4_15, emitter.context().types().v8u8());
    /* execute.simd:4778 [D] s_b_4_17: WriteRegBank 15:s_b_4_12 = s_b_4_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_16);
    /* execute.simd:4779 [F] s_b_4_18=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4779 [F] s_b_4_19 = constant u64 0 (const) */
    /* execute.simd:4779 [F] s_b_4_20: WriteRegBank 3:s_b_4_18 = s_b_4_19 */
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
    /* execute.simd:4783 [F] s_b_5_0=sym_28592_3_parameter_inst.immh (const) */
    /* execute.simd:4783 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4783 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.simd:4783 [F] s_b_5_3 = s_b_5_1<<s_b_5_2 (const) */
    uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4783 [F] s_b_5_4=sym_28592_3_parameter_inst.immb (const) */
    /* execute.simd:4783 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4783 [F] s_b_5_6 = s_b_5_3|s_b_5_5 (const) */
    uint32_t s_b_5_6 = ((uint32_t)(s_b_5_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4783 [F] s_b_5_7 = constant u32 10 (const) */
    /* execute.simd:4783 [F] s_b_5_8 = s_b_5_7-s_b_5_6 (const) */
    uint32_t s_b_5_8 = ((uint32_t)((uint32_t)16ULL - s_b_5_6));
    /* execute.simd:4783 [F] s_b_5_9 = (u64)s_b_5_8 (const) */
    /* execute.simd:4785 [F] s_b_5_10=sym_28592_3_parameter_inst.rn (const) */
    /* execute.simd:4785 [D] s_b_5_11 = ReadRegBank 16:s_b_5_10 (v16u8) */
    auto s_b_5_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_11,emitter.const_u8(16));
    }
    /* execute.simd:4786 [F] s_b_5_12=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4786 [D] s_b_5_13 = (v16s8)s_b_5_11 */
    auto s_b_5_13 = emitter.reinterpret(s_b_5_11, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_5_14 = (v16s8)s_b_5_9 (const) */
    auto s_b_5_14 = wutils::Vector<int8_t, 16>(((uint64_t)s_b_5_8));
    /* execute.simd:4786 [D] s_b_5_15 = s_b_5_13->>s_b_5_14 */
    auto s_b_5_15 = emitter.sar(s_b_5_13, emitter.constant_vector_splat(s_b_5_14[0], emitter.context().types().v16s8()));
    /* execute.simd:4786 [D] s_b_5_16 = (v16u8)s_b_5_15 */
    auto s_b_5_16 = emitter.reinterpret(s_b_5_15, emitter.context().types().v16u8());
    /* execute.simd:4786 [D] s_b_5_17: WriteRegBank 16:s_b_5_12 = s_b_5_16 */
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
    /* execute.simd:4790 [F] s_b_6_0=sym_28592_3_parameter_inst.immh (const) */
    /* execute.simd:4790 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.simd:4790 [F] s_b_6_2 = constant u32 3 (const) */
    /* execute.simd:4790 [F] s_b_6_3 = s_b_6_1<<s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4790 [F] s_b_6_4=sym_28592_3_parameter_inst.immb (const) */
    /* execute.simd:4790 [F] s_b_6_5 = (u32)s_b_6_4 (const) */
    /* execute.simd:4790 [F] s_b_6_6 = s_b_6_3|s_b_6_5 (const) */
    uint32_t s_b_6_6 = ((uint32_t)(s_b_6_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4790 [F] s_b_6_7 = constant u32 20 (const) */
    /* execute.simd:4790 [F] s_b_6_8 = s_b_6_7-s_b_6_6 (const) */
    uint32_t s_b_6_8 = ((uint32_t)((uint32_t)32ULL - s_b_6_6));
    /* execute.simd:4790 [F] s_b_6_9 = (u64)s_b_6_8 (const) */
    /* execute.simd:4792 [F] s_b_6_10=sym_28592_3_parameter_inst.rn (const) */
    /* execute.simd:4792 [D] s_b_6_11 = ReadRegBank 17:s_b_6_10 (v4u16) */
    auto s_b_6_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_11,emitter.const_u8(8));
    }
    /* execute.simd:4793 [F] s_b_6_12=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4793 [D] s_b_6_13 = (v4s16)s_b_6_11 */
    auto s_b_6_13 = emitter.reinterpret(s_b_6_11, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_6_14 = (v4s16)s_b_6_9 (const) */
    auto s_b_6_14 = wutils::Vector<int16_t, 4>(((uint64_t)s_b_6_8));
    /* execute.simd:4793 [D] s_b_6_15 = s_b_6_13->>s_b_6_14 */
    auto s_b_6_15 = emitter.sar(s_b_6_13, emitter.constant_vector_splat(s_b_6_14[0], emitter.context().types().v4s16()));
    /* execute.simd:4793 [D] s_b_6_16 = (v4u16)s_b_6_15 */
    auto s_b_6_16 = emitter.reinterpret(s_b_6_15, emitter.context().types().v4u16());
    /* execute.simd:4793 [D] s_b_6_17: WriteRegBank 17:s_b_6_12 = s_b_6_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_16);
    /* execute.simd:4794 [F] s_b_6_18=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4794 [F] s_b_6_19 = constant u64 0 (const) */
    /* execute.simd:4794 [F] s_b_6_20: WriteRegBank 3:s_b_6_18 = s_b_6_19 */
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
    /* execute.simd:4798 [F] s_b_7_0=sym_28592_3_parameter_inst.immh (const) */
    /* execute.simd:4798 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4798 [F] s_b_7_2 = constant u32 3 (const) */
    /* execute.simd:4798 [F] s_b_7_3 = s_b_7_1<<s_b_7_2 (const) */
    uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4798 [F] s_b_7_4=sym_28592_3_parameter_inst.immb (const) */
    /* execute.simd:4798 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4798 [F] s_b_7_6 = s_b_7_3|s_b_7_5 (const) */
    uint32_t s_b_7_6 = ((uint32_t)(s_b_7_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4798 [F] s_b_7_7 = constant u32 20 (const) */
    /* execute.simd:4798 [F] s_b_7_8 = s_b_7_7-s_b_7_6 (const) */
    uint32_t s_b_7_8 = ((uint32_t)((uint32_t)32ULL - s_b_7_6));
    /* execute.simd:4798 [F] s_b_7_9 = (u64)s_b_7_8 (const) */
    /* execute.simd:4800 [F] s_b_7_10=sym_28592_3_parameter_inst.rn (const) */
    /* execute.simd:4800 [D] s_b_7_11 = ReadRegBank 18:s_b_7_10 (v8u16) */
    auto s_b_7_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_11,emitter.const_u8(16));
    }
    /* execute.simd:4801 [F] s_b_7_12=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4801 [D] s_b_7_13 = (v8s16)s_b_7_11 */
    auto s_b_7_13 = emitter.reinterpret(s_b_7_11, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_7_14 = (v8s16)s_b_7_9 (const) */
    auto s_b_7_14 = wutils::Vector<int16_t, 8>(((uint64_t)s_b_7_8));
    /* execute.simd:4801 [D] s_b_7_15 = s_b_7_13->>s_b_7_14 */
    auto s_b_7_15 = emitter.sar(s_b_7_13, emitter.constant_vector_splat(s_b_7_14[0], emitter.context().types().v8s16()));
    /* execute.simd:4801 [D] s_b_7_16 = (v8u16)s_b_7_15 */
    auto s_b_7_16 = emitter.reinterpret(s_b_7_15, emitter.context().types().v8u16());
    /* execute.simd:4801 [D] s_b_7_17: WriteRegBank 18:s_b_7_12 = s_b_7_16 */
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
    /* execute.simd:4805 [F] s_b_8_0=sym_28592_3_parameter_inst.immh (const) */
    /* execute.simd:4805 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.simd:4805 [F] s_b_8_2 = constant u32 3 (const) */
    /* execute.simd:4805 [F] s_b_8_3 = s_b_8_1<<s_b_8_2 (const) */
    uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4805 [F] s_b_8_4=sym_28592_3_parameter_inst.immb (const) */
    /* execute.simd:4805 [F] s_b_8_5 = (u32)s_b_8_4 (const) */
    /* execute.simd:4805 [F] s_b_8_6 = s_b_8_3|s_b_8_5 (const) */
    uint32_t s_b_8_6 = ((uint32_t)(s_b_8_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4805 [F] s_b_8_7 = constant u32 40 (const) */
    /* execute.simd:4805 [F] s_b_8_8 = s_b_8_7-s_b_8_6 (const) */
    uint32_t s_b_8_8 = ((uint32_t)((uint32_t)64ULL - s_b_8_6));
    /* execute.simd:4805 [F] s_b_8_9 = (u64)s_b_8_8 (const) */
    /* execute.simd:4807 [F] s_b_8_10=sym_28592_3_parameter_inst.rn (const) */
    /* execute.simd:4807 [D] s_b_8_11 = ReadRegBank 19:s_b_8_10 (v2u32) */
    auto s_b_8_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_11,emitter.const_u8(8));
    }
    /* execute.simd:4808 [F] s_b_8_12=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4808 [D] s_b_8_13 = (v2s32)s_b_8_11 */
    auto s_b_8_13 = emitter.reinterpret(s_b_8_11, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_8_14 = (v2s32)s_b_8_9 (const) */
    auto s_b_8_14 = wutils::Vector<int32_t, 2>(((uint64_t)s_b_8_8));
    /* execute.simd:4808 [D] s_b_8_15 = s_b_8_13->>s_b_8_14 */
    auto s_b_8_15 = emitter.sar(s_b_8_13, emitter.constant_vector_splat(s_b_8_14[0], emitter.context().types().v2s32()));
    /* execute.simd:4808 [D] s_b_8_16 = (v2u32)s_b_8_15 */
    auto s_b_8_16 = emitter.reinterpret(s_b_8_15, emitter.context().types().v2u32());
    /* execute.simd:4808 [D] s_b_8_17: WriteRegBank 19:s_b_8_12 = s_b_8_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_16);
    /* execute.simd:4809 [F] s_b_8_18=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4809 [F] s_b_8_19 = constant u64 0 (const) */
    /* execute.simd:4809 [F] s_b_8_20: WriteRegBank 3:s_b_8_18 = s_b_8_19 */
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
    /* execute.simd:4813 [F] s_b_9_0=sym_28592_3_parameter_inst.immh (const) */
    /* execute.simd:4813 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4813 [F] s_b_9_2 = constant u32 3 (const) */
    /* execute.simd:4813 [F] s_b_9_3 = s_b_9_1<<s_b_9_2 (const) */
    uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4813 [F] s_b_9_4=sym_28592_3_parameter_inst.immb (const) */
    /* execute.simd:4813 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4813 [F] s_b_9_6 = s_b_9_3|s_b_9_5 (const) */
    uint32_t s_b_9_6 = ((uint32_t)(s_b_9_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4813 [F] s_b_9_7 = constant u32 40 (const) */
    /* execute.simd:4813 [F] s_b_9_8 = s_b_9_7-s_b_9_6 (const) */
    uint32_t s_b_9_8 = ((uint32_t)((uint32_t)64ULL - s_b_9_6));
    /* execute.simd:4813 [F] s_b_9_9 = (u64)s_b_9_8 (const) */
    /* execute.simd:4815 [F] s_b_9_10=sym_28592_3_parameter_inst.rn (const) */
    /* execute.simd:4815 [D] s_b_9_11 = ReadRegBank 20:s_b_9_10 (v4u32) */
    auto s_b_9_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_11,emitter.const_u8(16));
    }
    /* execute.simd:4816 [F] s_b_9_12=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4816 [D] s_b_9_13 = (v4s32)s_b_9_11 */
    auto s_b_9_13 = emitter.reinterpret(s_b_9_11, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_9_14 = (v4s32)s_b_9_9 (const) */
    auto s_b_9_14 = wutils::Vector<int32_t, 4>(((uint64_t)s_b_9_8));
    /* execute.simd:4816 [D] s_b_9_15 = s_b_9_13->>s_b_9_14 */
    auto s_b_9_15 = emitter.sar(s_b_9_13, emitter.constant_vector_splat(s_b_9_14[0], emitter.context().types().v4s32()));
    /* execute.simd:4816 [D] s_b_9_16 = (v4u32)s_b_9_15 */
    auto s_b_9_16 = emitter.reinterpret(s_b_9_15, emitter.context().types().v4u32());
    /* execute.simd:4816 [D] s_b_9_17: WriteRegBank 20:s_b_9_12 = s_b_9_16 */
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
    /* execute.simd:4820 [F] s_b_10_0=sym_28592_3_parameter_inst.immh (const) */
    /* execute.simd:4820 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4820 [F] s_b_10_2 = constant u32 3 (const) */
    /* execute.simd:4820 [F] s_b_10_3 = s_b_10_1<<s_b_10_2 (const) */
    uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4820 [F] s_b_10_4=sym_28592_3_parameter_inst.immb (const) */
    /* execute.simd:4820 [F] s_b_10_5 = (u32)s_b_10_4 (const) */
    /* execute.simd:4820 [F] s_b_10_6 = s_b_10_3|s_b_10_5 (const) */
    uint32_t s_b_10_6 = ((uint32_t)(s_b_10_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4820 [F] s_b_10_7 = constant u32 80 (const) */
    /* execute.simd:4820 [F] s_b_10_8 = s_b_10_7-s_b_10_6 (const) */
    uint32_t s_b_10_8 = ((uint32_t)((uint32_t)128ULL - s_b_10_6));
    /* execute.simd:4820 [F] s_b_10_9 = (u64)s_b_10_8 (const) */
    /* execute.simd:4822 [F] s_b_10_10=sym_28592_3_parameter_inst.rn (const) */
    /* execute.simd:4822 [D] s_b_10_11 = ReadRegBank 21:s_b_10_10 (v2u64) */
    auto s_b_10_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_11,emitter.const_u8(16));
    }
    /* execute.simd:4823 [F] s_b_10_12=sym_28592_3_parameter_inst.rd (const) */
    /* execute.simd:4823 [D] s_b_10_13 = (v2s64)s_b_10_11 */
    auto s_b_10_13 = emitter.reinterpret(s_b_10_11, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_10_14 = (v2s64)s_b_10_9 (const) */
    auto s_b_10_14 = wutils::Vector<int64_t, 2>(((uint64_t)s_b_10_8));
    /* execute.simd:4823 [D] s_b_10_15 = s_b_10_13->>s_b_10_14 */
    auto s_b_10_15 = emitter.sar(s_b_10_13, emitter.constant_vector_splat(s_b_10_14[0], emitter.context().types().v2s64()));
    /* execute.simd:4823 [D] s_b_10_16 = (v2u64)s_b_10_15 */
    auto s_b_10_16 = emitter.reinterpret(s_b_10_15, emitter.context().types().v2u64());
    /* execute.simd:4823 [D] s_b_10_17: WriteRegBank 21:s_b_10_12 = s_b_10_16 */
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
  auto DV_sym_136069_1_tmp_s_b_57_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_135808_3_parameter_rt;
  auto DV_sym_135932_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_135893_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_135890_1_tmp_s_b_5_2;
  auto DV_sym_135813_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_135816_3_parameter_lane;
  auto DV_sym_136010_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_135915_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_135699_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_135716_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30750_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30756_0_lane;
  uint8_t CV_sym_30768_0_rt;
  auto DV_sym_136081_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_136042_1_temporary_value;
  auto DV_sym_136042_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2590 [F] s_b_0_0=sym_30744_3_parameter_inst.rn (const) */
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
    /* execute.simd:2592 [F] s_b_1_0 = sym_30756_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30756_0_lane;
    /* execute.simd:2592 [F] s_b_1_1=sym_30744_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2592 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2592 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2593 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2593 [F] s_b_2_1: sym_30768_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30768_0_rt = (uint8_t)0ULL;
    /* execute.simd:2593 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2599 [F] s_b_3_0=sym_30744_3_parameter_inst.rm (const) */
    /* execute.simd:2599 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2599 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2599 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2599 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2593 [F] s_b_4_0 = sym_30768_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30768_0_rt;
    /* execute.simd:2593 [F] s_b_4_1=sym_30744_3_parameter_inst.regcnt (const) */
    /* execute.simd:2593 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2593 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2594 [F] s_b_5_0=sym_30744_3_parameter_inst.arrangement (const) */
    /* execute.simd:2594 [F] s_b_5_1=sym_30744_3_parameter_inst.rt (const) */
    /* execute.simd:2594 [F] s_b_5_2 = sym_30768_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30768_0_rt;
    /* execute.simd:2594 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2594 [F] s_b_5_4 = sym_30756_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30756_0_lane;
    /* execute.simd:2594 [D] s_b_5_5 = sym_30750_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30750_0_address, emitter.context().types().u64());
    /* execute.simd:2594 [F] s_b_5_6: sym_135808_3_parameter_rt = s_b_5_3 (const), dominates: s_b_19_0 s_b_23_0 s_b_24_0 s_b_21_0 s_b_20_0 s_b_18_0 s_b_22_0  */
    CV_sym_135808_3_parameter_rt = s_b_5_3;
    /* execute.simd:2594 [F] s_b_5_7: sym_135816_3_parameter_lane = s_b_5_4 (const), dominates: s_b_19_3 s_b_23_3 s_b_24_3 s_b_21_3 s_b_20_3 s_b_18_3 s_b_22_3  */
    CV_sym_135816_3_parameter_lane = s_b_5_4;
    /* execute.simd:2594 [D] s_b_5_8: sym_135813_3_parameter_addr = s_b_5_5, dominates: s_b_19_2 s_b_23_2 s_b_24_2 s_b_21_2 s_b_20_2 s_b_18_2 s_b_22_2  */
    emitter.store_local(DV_sym_135813_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_135890_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_25_1  */
    CV_sym_135890_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_135893_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_135893_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3844 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3849 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3854 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3859 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3864 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3869 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3874 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3843 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_17 (const) -> b_19, b_23, b_24, b_21, b_20, b_17, b_18, b_22,  */
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
    /* execute.simd:2592 [F] s_b_6_0 = sym_30756_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30756_0_lane;
    /* execute.simd:2592 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2592 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2592 [F] s_b_6_3: sym_30756_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30756_0_lane = s_b_6_2;
    /* execute.simd:2592 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2600 [F] s_b_7_0=sym_30744_3_parameter_inst.rn (const) */
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
    /* execute.simd:2603 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2603 [D] s_b_8_1 = sym_30750_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_30750_0_address, emitter.context().types().u64());
    /* execute.simd:2603 [D] s_b_8_2: sym_136010_3_parameter_value = s_b_8_1, dominates: s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_136010_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2796 [F] s_b_10_0=sym_30744_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_135699_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_135699_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_135699_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_135699_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2590 [D] s_b_11_1: sym_30750_0_address = s_b_11_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30750_0_address, s_b_11_0);
    /* execute.simd:2592 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.simd:2592 [F] s_b_11_3: sym_30756_0_lane = s_b_11_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30756_0_lane = (uint8_t)0ULL;
    /* execute.simd:2592 [F] s_b_11_4: Jump b_1 (const) */
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
    /* execute.a64:2765 [D] s_b_12_1: sym_135716_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_135716_1__R_s_b_3_0, s_b_12_0);
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
    /* execute.a64:2794 [D] s_b_14_0 = sym_135716_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_135716_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_135699_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_135699_0_return_symbol, s_b_14_0);
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
    /* execute.a64:2768 [D] s_b_15_1: sym_135716_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_135716_1__R_s_b_3_0, s_b_15_0);
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
    /* execute.a64:2770 [D] s_b_16_1: sym_135716_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_135716_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2770 [F] s_b_16_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3880 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_17_1: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3845 [F] s_b_18_0 = sym_135808_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_135808_3_parameter_rt;
    /* execute.simd:3845 [D] s_b_18_1 = ReadRegBank 15:s_b_18_0 (v8u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3846 [D] s_b_18_2 = sym_135813_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_135813_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3846 [F] s_b_18_3 = sym_135816_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_135816_3_parameter_lane;
    /* execute.simd:3846 [D] s_b_18_1[s_b_18_3] */
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
    /* execute.simd:3850 [F] s_b_19_0 = sym_135808_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_135808_3_parameter_rt;
    /* execute.simd:3850 [D] s_b_19_1 = ReadRegBank 16:s_b_19_0 (v16u8) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3851 [D] s_b_19_2 = sym_135813_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_135813_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3851 [F] s_b_19_3 = sym_135816_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_135816_3_parameter_lane;
    /* execute.simd:3851 [D] s_b_19_1[s_b_19_3] */
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
    /* execute.simd:3855 [F] s_b_20_0 = sym_135808_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_135808_3_parameter_rt;
    /* execute.simd:3855 [D] s_b_20_1 = ReadRegBank 17:s_b_20_0 (v4u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3856 [D] s_b_20_2 = sym_135813_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_135813_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3856 [F] s_b_20_3 = sym_135816_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_135816_3_parameter_lane;
    /* execute.simd:3856 [D] s_b_20_1[s_b_20_3] */
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
    /* execute.simd:3860 [F] s_b_21_0 = sym_135808_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_135808_3_parameter_rt;
    /* execute.simd:3860 [D] s_b_21_1 = ReadRegBank 18:s_b_21_0 (v8u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3861 [D] s_b_21_2 = sym_135813_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_135813_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3861 [F] s_b_21_3 = sym_135816_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_135816_3_parameter_lane;
    /* execute.simd:3861 [D] s_b_21_1[s_b_21_3] */
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
    /* execute.simd:3865 [F] s_b_22_0 = sym_135808_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_135808_3_parameter_rt;
    /* execute.simd:3865 [D] s_b_22_1 = ReadRegBank 19:s_b_22_0 (v2u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:3866 [D] s_b_22_2 = sym_135813_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_135813_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3866 [F] s_b_22_3 = sym_135816_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_135816_3_parameter_lane;
    /* execute.simd:3866 [D] s_b_22_1[s_b_22_3] */
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
    /* execute.simd:3870 [F] s_b_23_0 = sym_135808_3_parameter_rt (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_135808_3_parameter_rt;
    /* execute.simd:3870 [D] s_b_23_1 = ReadRegBank 20:s_b_23_0 (v4u32) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:3871 [D] s_b_23_2 = sym_135813_3_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_135813_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3871 [F] s_b_23_3 = sym_135816_3_parameter_lane (const) uint8_t */
    uint8_t s_b_23_3 = CV_sym_135816_3_parameter_lane;
    /* execute.simd:3871 [D] s_b_23_1[s_b_23_3] */
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
    /* execute.simd:3875 [F] s_b_24_0 = sym_135808_3_parameter_rt (const) uint8_t */
    uint8_t s_b_24_0 = CV_sym_135808_3_parameter_rt;
    /* execute.simd:3875 [D] s_b_24_1 = ReadRegBank 21:s_b_24_0 (v2u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))),s_b_24_1,emitter.const_u8(16));
    }
    /* execute.simd:3876 [D] s_b_24_2 = sym_135813_3_parameter_addr uint64_t */
    auto s_b_24_2 = emitter.load_local(DV_sym_135813_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3876 [F] s_b_24_3 = sym_135816_3_parameter_lane (const) uint8_t */
    uint8_t s_b_24_3 = CV_sym_135816_3_parameter_lane;
    /* execute.simd:3876 [D] s_b_24_1[s_b_24_3] */
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
    /* ???:4294967295 [D] s_b_25_0 = sym_135893_1_tmp_s_b_5_5 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_135893_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_25_1 = sym_135890_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_25_1 = CV_sym_135890_1_tmp_s_b_5_2;
    /* execute.simd:2595 [F] s_b_25_2=sym_30744_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_25_3 = (u64)s_b_25_2 (const) */
    /* ???:4294967295 [D] s_b_25_4 = s_b_25_0+s_b_25_3 */
    auto s_b_25_4 = emitter.add(s_b_25_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2595 [D] s_b_25_5: sym_30750_0_address = s_b_25_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30750_0_address, s_b_25_4);
    /* execute.simd:2593 [F] s_b_25_6 = constant u8 1 (const) */
    /* execute.simd:2593 [F] s_b_25_7 = s_b_25_1+s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(s_b_25_1 + (uint8_t)1ULL));
    /* execute.simd:2593 [F] s_b_25_8: sym_30768_0_rt = s_b_25_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30768_0_rt = s_b_25_7;
    /* execute.simd:2593 [F] s_b_25_9: Jump b_4 (const) */
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
    /* execute.a64:2796 [F] s_b_27_0=sym_30744_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_27_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_27_2: sym_135915_0_return_symbol = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_135915_0_return_symbol, s_b_27_1);
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_31,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_135915_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_135915_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2600 [F] s_b_28_1=sym_30744_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_28_2: sym_136069_1_tmp_s_b_57_0 = s_b_28_0, dominates: s_b_40_1  */
    emitter.store_local(DV_sym_136069_1_tmp_s_b_57_0, s_b_28_0);
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
    /* execute.a64:2765 [D] s_b_29_1: sym_135932_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_135932_1__R_s_b_3_0, s_b_29_0);
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
    /* execute.a64:2794 [D] s_b_31_0 = sym_135932_1__R_s_b_3_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_135932_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1: sym_135915_0_return_symbol = s_b_31_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_135915_0_return_symbol, s_b_31_0);
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
    /* execute.a64:2768 [D] s_b_32_1: sym_135932_1__R_s_b_3_0 = s_b_32_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_135932_1__R_s_b_3_0, s_b_32_0);
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
    /* execute.a64:2770 [D] s_b_33_1: sym_135932_1__R_s_b_3_0 = s_b_33_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_135932_1__R_s_b_3_0, s_b_33_0);
    /* execute.a64:2770 [F] s_b_33_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_8,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2810 [D] s_b_34_0 = sym_136010_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_136010_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_34_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_34_2 = s_b_34_0&s_b_34_1 */
    auto s_b_34_2 = emitter.bitwise_and(s_b_34_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_34_3: sym_136010_3_parameter_value = s_b_34_2, dominates: s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_136010_3_parameter_value, s_b_34_2);
    /* execute.a64:2810 [F] s_b_34_4: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_8, b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2813 [F] s_b_35_0=sym_30744_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_36_0 = sym_136010_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_136010_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_36_1: sym_136081_3_parameter_value = s_b_36_0, dominates: s_b_42_0 s_b_43_0 s_b_44_0  */
    emitter.store_local(DV_sym_136081_3_parameter_value, s_b_36_0);
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
    /* execute.a64:2816 [F] s_b_37_0=sym_30744_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_37_1 = sym_136010_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_136010_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2714 [F] s_b_39_1: sym_136042_1_temporary_value = s_b_39_0 (const), dominates: s_b_40_0  */
    CV_sym_136042_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_136042_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_39_2: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_39, b_41,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2714 [D] s_b_40_0 = sym_136042_1_temporary_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_136042_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_40_1 = sym_136069_1_tmp_s_b_57_0 uint64_t */
    auto s_b_40_1 = emitter.load_local(DV_sym_136069_1_tmp_s_b_57_0, emitter.context().types().u64());
    /* execute.simd:2600 [D] s_b_40_2 = s_b_40_1+s_b_40_0 */
    auto s_b_40_2 = emitter.add(s_b_40_1, s_b_40_0);
    /* execute.simd:2600 [D] s_b_40_3: sym_30750_0_address = s_b_40_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_30750_0_address, s_b_40_2);
    /* execute.simd:2600 [F] s_b_40_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_28,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2714 [F] s_b_41_0=sym_30744_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_41_1 = ReadRegBank 0:s_b_41_0 (u64) */
    auto s_b_41_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_41_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_41_2: sym_136042_1_temporary_value = s_b_41_1, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_136042_1_temporary_value, s_b_41_1);
    /* execute.a64:2714 [F] s_b_41_3: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_36,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2778 [D] s_b_42_0 = sym_136081_3_parameter_value uint64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_136081_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_43_0 = sym_136081_3_parameter_value uint64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_136081_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_44_0 = sym_136081_3_parameter_value uint64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_136081_3_parameter_value, emitter.context().types().u64());
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
  auto DV_sym_139447_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139176_1_tmp_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_138664_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_139235_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139023_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_139307_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_138785_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_138681_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_139521_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_31173_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_138951_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_138857_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_139097_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:833 [F] s_b_0_0=sym_31167_3_parameter_inst.rn (const) */
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
    /* execute.a64:836 [D] s_b_1_1 = sym_31173_0_address uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_31173_0_address, emitter.context().types().u64());
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
    /* execute.a64:844 [D] s_b_3_1 = sym_31173_0_address uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_31173_0_address, emitter.context().types().u64());
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
    /* execute.a64:2796 [F] s_b_9_0=sym_31167_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_138664_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_138664_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_138664_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_138664_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:833 [D] s_b_10_1: sym_31173_0_address = s_b_10_0, dominates: s_b_1_1 s_b_4_0 s_b_3_1 s_b_6_0  */
    emitter.store_local(DV_sym_31173_0_address, s_b_10_0);
    /* execute.a64:835 [F] s_b_10_2=sym_31167_3_parameter_inst.size (const) */
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
    /* execute.a64:2765 [D] s_b_11_1: sym_138681_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_138681_1__R_s_b_3_0, s_b_11_0);
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
    /* execute.a64:2794 [D] s_b_13_0 = sym_138681_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_138681_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_138664_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_138664_0_return_symbol, s_b_13_0);
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
    /* execute.a64:2768 [D] s_b_14_1: sym_138681_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_138681_1__R_s_b_3_0, s_b_14_0);
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
    /* execute.a64:2770 [D] s_b_15_1: sym_138681_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_138681_1__R_s_b_3_0, s_b_15_0);
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
        /* execute.a64:837 [D] s_b_4_0 = sym_31173_0_address uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_31173_0_address, emitter.context().types().u64());
        /* execute.a64:837 [F] s_b_4_1=sym_31167_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_4_2: sym_138951_1_tmp_s_b_4_0 = s_b_4_0, dominates: s_b_18_5  */
        emitter.store_local(DV_sym_138951_1_tmp_s_b_4_0, s_b_4_0);
        /* ???:4294967295 [D] s_b_4_3: sym_138785_1_tmp_s_b_4_0 = s_b_4_0, dominates: s_b_18_2  */
        emitter.store_local(DV_sym_138785_1_tmp_s_b_4_0, s_b_4_0);
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
        /* execute.a64:841 [F] s_b_5_0=sym_31167_3_parameter_inst.rs (const) */
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
        /* execute.a64:845 [D] s_b_6_0 = sym_31173_0_address uint64_t */
        auto s_b_6_0 = emitter.load_local(DV_sym_31173_0_address, emitter.context().types().u64());
        /* execute.a64:845 [F] s_b_6_1=sym_31167_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_6_2: sym_139176_1_tmp_s_b_7_0 = s_b_6_0, dominates: s_b_22_3  */
        emitter.store_local(DV_sym_139176_1_tmp_s_b_7_0, s_b_6_0);
        /* ???:4294967295 [D] s_b_6_3: sym_139023_1_tmp_s_b_5_0 = s_b_6_0, dominates: s_b_22_1  */
        emitter.store_local(DV_sym_139023_1_tmp_s_b_5_0, s_b_6_0);
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
        /* execute.a64:849 [F] s_b_7_0=sym_31167_3_parameter_inst.rs (const) */
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
        /* execute.a64:2709 [D] s_b_16_1: sym_138857_1_temporary_value = s_b_16_0, dominates: s_b_18_0  */
        emitter.store_local(DV_sym_138857_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_17_0=sym_31167_3_parameter_inst.rt (const) */
        /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
        auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_17_2: sym_138857_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
        emitter.store_local(DV_sym_138857_1_temporary_value, s_b_17_1);
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
        /* execute.a64:2709 [D] s_b_18_0 = sym_138857_1_temporary_value uint32_t */
        auto s_b_18_0 = emitter.load_local(DV_sym_138857_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
        auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_18_2 = sym_138785_1_tmp_s_b_4_0 uint64_t */
        auto s_b_18_2 = emitter.load_local(DV_sym_138785_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:1855 [D] s_b_18_3 = (u32)s_b_18_1 */
        auto s_b_18_3 = emitter.truncate(s_b_18_1, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_18_4: Store 4 s_b_18_2 <= s_b_18_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_3, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_18_2, s_b_18_3);
        /* ???:4294967295 [D] s_b_18_5 = sym_138951_1_tmp_s_b_4_0 uint64_t */
        auto s_b_18_5 = emitter.load_local(DV_sym_138951_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:838 [F] s_b_18_6 = constant u64 4 (const) */
        /* execute.a64:838 [D] s_b_18_7 = s_b_18_5+s_b_18_6 */
        auto s_b_18_7 = emitter.add(s_b_18_5, emitter.const_u64((uint64_t)4ULL));
        /* execute.a64:838 [F] s_b_18_8=sym_31167_3_parameter_inst.rt2 (const) */
        /* ???:4294967295 [D] s_b_18_9: sym_139235_1_tmp_s_b_4_0 = s_b_18_7, dominates: s_b_26_2  */
        emitter.store_local(DV_sym_139235_1_tmp_s_b_4_0, s_b_18_7);
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
        /* execute.a64:2739 [F] s_b_19_0=sym_31167_3_parameter_inst.rs (const) */
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
        /* execute.a64:2714 [D] s_b_20_1: sym_139097_1_temporary_value = s_b_20_0, dominates: s_b_22_0  */
        emitter.store_local(DV_sym_139097_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_21_0=sym_31167_3_parameter_inst.rt (const) */
        /* execute.a64:2714 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
        auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_21_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_21_2: sym_139097_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
        emitter.store_local(DV_sym_139097_1_temporary_value, s_b_21_1);
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
        /* execute.a64:2714 [D] s_b_22_0 = sym_139097_1_temporary_value uint64_t */
        auto s_b_22_0 = emitter.load_local(DV_sym_139097_1_temporary_value, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_22_1 = sym_139023_1_tmp_s_b_5_0 uint64_t */
        auto s_b_22_1 = emitter.load_local(DV_sym_139023_1_tmp_s_b_5_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_22_2: Store 8 s_b_22_1 <= s_b_22_0 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_1, s_b_22_0, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_22_1, s_b_22_0);
        /* ???:4294967295 [D] s_b_22_3 = sym_139176_1_tmp_s_b_7_0 uint64_t */
        auto s_b_22_3 = emitter.load_local(DV_sym_139176_1_tmp_s_b_7_0, emitter.context().types().u64());
        /* execute.a64:846 [F] s_b_22_4 = constant u64 8 (const) */
        /* execute.a64:846 [D] s_b_22_5 = s_b_22_3+s_b_22_4 */
        auto s_b_22_5 = emitter.add(s_b_22_3, emitter.const_u64((uint64_t)8ULL));
        /* execute.a64:846 [F] s_b_22_6=sym_31167_3_parameter_inst.rt2 (const) */
        /* ???:4294967295 [D] s_b_22_7: sym_139447_1_tmp_s_b_5_0 = s_b_22_5, dominates: s_b_29_1  */
        emitter.store_local(DV_sym_139447_1_tmp_s_b_5_0, s_b_22_5);
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
        /* execute.a64:2739 [F] s_b_23_0=sym_31167_3_parameter_inst.rs (const) */
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
        /* execute.a64:2709 [D] s_b_24_1: sym_139307_1_temporary_value = s_b_24_0, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_139307_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_25_0=sym_31167_3_parameter_inst.rt2 (const) */
        /* execute.a64:2709 [D] s_b_25_1 = ReadRegBank 1:s_b_25_0 (u32) */
        auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_25_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_25_2: sym_139307_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_139307_1_temporary_value, s_b_25_1);
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
        /* execute.a64:2709 [D] s_b_26_0 = sym_139307_1_temporary_value uint32_t */
        auto s_b_26_0 = emitter.load_local(DV_sym_139307_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_26_1 = (u64)s_b_26_0 */
        auto s_b_26_1 = emitter.zx(s_b_26_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_26_2 = sym_139235_1_tmp_s_b_4_0 uint64_t */
        auto s_b_26_2 = emitter.load_local(DV_sym_139235_1_tmp_s_b_4_0, emitter.context().types().u64());
        /* execute.a64:1855 [D] s_b_26_3 = (u32)s_b_26_1 */
        auto s_b_26_3 = emitter.truncate(s_b_26_1, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_26_4: Store 4 s_b_26_2 <= s_b_26_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_26_2, s_b_26_3, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_26_2, s_b_26_3);
        /* execute.a64:839 [F] s_b_26_5=sym_31167_3_parameter_inst.rs (const) */
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
        /* execute.a64:2714 [D] s_b_27_1: sym_139521_1_temporary_value = s_b_27_0, dominates: s_b_29_0  */
        emitter.store_local(DV_sym_139521_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_28_0=sym_31167_3_parameter_inst.rt2 (const) */
        /* execute.a64:2714 [D] s_b_28_1 = ReadRegBank 0:s_b_28_0 (u64) */
        auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_28_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_28_2: sym_139521_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
        emitter.store_local(DV_sym_139521_1_temporary_value, s_b_28_1);
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
        /* execute.a64:2714 [D] s_b_29_0 = sym_139521_1_temporary_value uint64_t */
        auto s_b_29_0 = emitter.load_local(DV_sym_139521_1_temporary_value, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_29_1 = sym_139447_1_tmp_s_b_5_0 uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_139447_1_tmp_s_b_5_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_29_2: Store 8 s_b_29_1 <= s_b_29_0 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_29_1, s_b_29_0, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_29_1, s_b_29_0);
        /* execute.a64:847 [F] s_b_29_3=sym_31167_3_parameter_inst.rs (const) */
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
        /* execute.a64:2739 [F] s_b_30_0=sym_31167_3_parameter_inst.rs (const) */
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
        /* execute.a64:2739 [F] s_b_31_0=sym_31167_3_parameter_inst.rs (const) */
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
  auto DV_sym_143332_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143197_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143289_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_143326_1_tmp_s_b_0_1;
  uint8_t CV_sym_143324_1_tmp_s_b_0_5;
  auto DV_sym_143322_1_tmp_s_b_0_7 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143214_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31688_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143417_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143456_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:789 [F] s_b_0_0=sym_31682_3_parameter_inst.rn (const) */
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
    /* execute.simd:791 [D] s_b_1_0 = sym_31688_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31688_0_addr, emitter.context().types().u64());
    /* execute.simd:791 [F] s_b_1_1=sym_31682_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.simd:791 [D] s_b_1_3: sym_31688_0_addr = s_b_1_2, dominates: s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_31688_0_addr, s_b_1_2);
    /* execute.simd:791 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.simd:794 [F] s_b_2_0=sym_31682_3_parameter_inst.opc (const) */
    /* execute.simd:794 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.simd:794 [F] s_b_2_2 = constant u32 2 (const) */
    /* execute.simd:794 [F] s_b_2_3 = s_b_2_1+s_b_2_2 (const) */
    uint32_t s_b_2_3 = ((uint32_t)(((uint32_t)insn.opc) + (uint32_t)2ULL));
    /* execute.simd:794 [F] s_b_2_4 = (u8)s_b_2_3 (const) */
    /* execute.simd:794 [D] s_b_2_5 = sym_31688_0_addr uint64_t */
    auto s_b_2_5 = emitter.load_local(DV_sym_31688_0_addr, emitter.context().types().u64());
    /* execute.simd:765 [F] s_b_2_6 = constant u32 1 (const) */
    /* execute.simd:765 [F] s_b_2_7 = (u32)s_b_2_4 (const) */
    /* execute.simd:765 [F] s_b_2_8 = s_b_2_6<<s_b_2_7 (const) */
    uint32_t s_b_2_8 = ((uint32_t)((uint32_t)1ULL << ((uint32_t)((uint8_t)s_b_2_3))));
    /* execute.simd:765 [F] s_b_2_9 = (u8)s_b_2_8 (const) */
    /* ???:4294967295 [F] s_b_2_10: sym_143326_1_tmp_s_b_0_1 = s_b_2_4 (const), dominates: s_b_14_2  */
    CV_sym_143326_1_tmp_s_b_0_1 = ((uint8_t)s_b_2_3);
    /* ???:4294967295 [F] s_b_2_11: sym_143324_1_tmp_s_b_0_5 = s_b_2_9 (const), dominates: s_b_14_1  */
    CV_sym_143324_1_tmp_s_b_0_5 = ((uint8_t)s_b_2_8);
    /* ???:4294967295 [D] s_b_2_12: sym_143322_1_tmp_s_b_0_7 = s_b_2_5, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_143322_1_tmp_s_b_0_7, s_b_2_5);
    /* ???:4294967295 [D] s_b_2_13: sym_143289_0_replaced_parameter_addr = s_b_2_5, dominates: s_b_16_2 s_b_15_2 s_b_13_2 s_b_18_3 s_b_17_2  */
    emitter.store_local(DV_sym_143289_0_replaced_parameter_addr, s_b_2_5);
    /* execute.simd:3636 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:3642 [F] s_b_2_15 = constant s32 1 (const) */
    /* execute.simd:3648 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:3654 [F] s_b_2_17 = constant s32 3 (const) */
    /* execute.simd:3660 [F] s_b_2_18 = constant s32 4 (const) */
    /* execute.simd:3635 [F] s_b_2_19: Switch s_b_2_4: < <todo> > def b_14 (const) -> b_16, b_15, b_14, b_13, b_18, b_17,  */
    switch (((uint8_t)s_b_2_3)) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_16;
      break;
    default:
      goto fixed_block_b_14;
    }
  }
  /* b_24,  */
  fixed_block_b_3: 
  {
    /* execute.simd:797 [D] s_b_3_0 = sym_31688_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31688_0_addr, emitter.context().types().u64());
    /* execute.simd:797 [F] s_b_3_1=sym_31682_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:797 [D] s_b_3_3: sym_31688_0_addr = s_b_3_2, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_31688_0_addr, s_b_3_2);
    /* execute.simd:797 [F] s_b_3_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_24,  */
  fixed_block_b_4: 
  {
    /* execute.simd:800 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.simd:800 [D] s_b_4_1 = sym_31688_0_addr uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_31688_0_addr, emitter.context().types().u64());
    /* execute.simd:800 [D] s_b_4_2: sym_143417_3_parameter_value = s_b_4_1, dominates: s_b_25_0 s_b_27_0 s_b_28_1  */
    emitter.store_local(DV_sym_143417_3_parameter_value, s_b_4_1);
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
    /* execute.a64:2796 [F] s_b_6_0=sym_31682_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_6_1 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_6_2: sym_143197_0_return_symbol = s_b_6_1, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_143197_0_return_symbol, s_b_6_1);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_10,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [D] s_b_7_0 = sym_143197_0_return_symbol uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_143197_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:789 [D] s_b_7_1: sym_31688_0_addr = s_b_7_0, dominates: s_b_1_0 s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_31688_0_addr, s_b_7_0);
    /* execute.simd:790 [F] s_b_7_2=sym_31682_3_parameter_inst.P (const) */
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
    /* execute.a64:2765 [D] s_b_8_1: sym_143214_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_143214_1__R_s_b_3_0, s_b_8_0);
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
    /* execute.a64:2794 [D] s_b_10_0 = sym_143214_1__R_s_b_3_0 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_143214_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1: sym_143197_0_return_symbol = s_b_10_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_143197_0_return_symbol, s_b_10_0);
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
    /* execute.a64:2768 [D] s_b_11_1: sym_143214_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_143214_1__R_s_b_3_0, s_b_11_0);
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
    /* execute.a64:2770 [D] s_b_12_1: sym_143214_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_143214_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2770 [F] s_b_12_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_2,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3638 [F] s_b_13_0=sym_31682_3_parameter_inst.rt (const) */
    /* execute.simd:6222 [D] s_b_13_1 = ReadRegBank 4:s_b_13_0 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1,emitter.const_u8(1));
    }
    /* execute.simd:3639 [D] s_b_13_2 = sym_143289_0_replaced_parameter_addr uint64_t */
    auto s_b_13_2 = emitter.load_local(DV_sym_143289_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* ???:4294967295 [D] s_b_14_0 = sym_143322_1_tmp_s_b_0_7 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_143322_1_tmp_s_b_0_7, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_14_1 = sym_143324_1_tmp_s_b_0_5 (const) uint8_t */
    uint8_t s_b_14_1 = CV_sym_143324_1_tmp_s_b_0_5;
    /* ???:4294967295 [F] s_b_14_2 = sym_143326_1_tmp_s_b_0_1 (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_143326_1_tmp_s_b_0_1;
    /* execute.simd:767 [F] s_b_14_3 = (u64)s_b_14_1 (const) */
    /* execute.simd:767 [D] s_b_14_4 = s_b_14_0+s_b_14_3 */
    auto s_b_14_4 = emitter.add(s_b_14_0, emitter.const_u64(((uint64_t)s_b_14_1)));
    /* ???:4294967295 [D] s_b_14_5: sym_143332_0_replaced_parameter_addr = s_b_14_4, dominates: s_b_21_2 s_b_20_2 s_b_19_2 s_b_22_2 s_b_23_3  */
    emitter.store_local(DV_sym_143332_0_replaced_parameter_addr, s_b_14_4);
    /* execute.simd:3636 [F] s_b_14_6 = constant s32 0 (const) */
    /* execute.simd:3642 [F] s_b_14_7 = constant s32 1 (const) */
    /* execute.simd:3648 [F] s_b_14_8 = constant s32 2 (const) */
    /* execute.simd:3654 [F] s_b_14_9 = constant s32 3 (const) */
    /* execute.simd:3660 [F] s_b_14_10 = constant s32 4 (const) */
    /* execute.simd:3635 [F] s_b_14_11: Switch s_b_14_2: < <todo> > def b_24 (const) -> b_21, b_24, b_20, b_19, b_22, b_23,  */
    switch (s_b_14_2) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_20;
      break;
    default:
      goto fixed_block_b_24;
    }
  }
  /* b_2,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3644 [F] s_b_15_0=sym_31682_3_parameter_inst.rt (const) */
    /* execute.simd:6227 [D] s_b_15_1 = ReadRegBank 5:s_b_15_0 (u16) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_15_1,emitter.const_u8(2));
    }
    /* execute.simd:3645 [D] s_b_15_2 = sym_143289_0_replaced_parameter_addr uint64_t */
    auto s_b_15_2 = emitter.load_local(DV_sym_143289_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3650 [F] s_b_16_0=sym_31682_3_parameter_inst.rt (const) */
    /* execute.simd:6232 [D] s_b_16_1 = ReadRegBank 6:s_b_16_0 (u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_1,emitter.const_u8(4));
    }
    /* execute.simd:3651 [D] s_b_16_2 = sym_143289_0_replaced_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_143289_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3656 [F] s_b_17_0=sym_31682_3_parameter_inst.rt (const) */
    /* execute.simd:6237 [D] s_b_17_1 = ReadRegBank 7:s_b_17_0 (u64) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.simd:3657 [D] s_b_17_2 = sym_143289_0_replaced_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_143289_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3664 [F] s_b_18_0=sym_31682_3_parameter_inst.rt (const) */
    /* execute.simd:6242 [D] s_b_18_1 = ReadRegBank 2:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:6243 [D] s_b_18_2 = ReadRegBank 3:s_b_18_0 (u64) */
    auto s_b_18_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_18_2,emitter.const_u8(8));
    }
    /* execute.simd:3665 [D] s_b_18_3 = sym_143289_0_replaced_parameter_addr uint64_t */
    auto s_b_18_3 = emitter.load_local(DV_sym_143289_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_4: Store 8 s_b_18_3 <= s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_3, s_b_18_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_18_3, s_b_18_1);
    /* execute.simd:3666 [F] s_b_18_5 = constant u64 8 (const) */
    /* execute.simd:3666 [D] s_b_18_6 = s_b_18_3+s_b_18_5 */
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
    /* execute.simd:3656 [F] s_b_19_0=sym_31682_3_parameter_inst.rt2 (const) */
    /* execute.simd:6237 [D] s_b_19_1 = ReadRegBank 7:s_b_19_0 (u64) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.simd:3657 [D] s_b_19_2 = sym_143332_0_replaced_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_143332_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3638 [F] s_b_20_0=sym_31682_3_parameter_inst.rt2 (const) */
    /* execute.simd:6222 [D] s_b_20_1 = ReadRegBank 4:s_b_20_0 (u8) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_20_1,emitter.const_u8(1));
    }
    /* execute.simd:3639 [D] s_b_20_2 = sym_143332_0_replaced_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_143332_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_3: Store 1 s_b_20_2 <= s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_1, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_20_2, s_b_20_1);
    /* execute.simd:0 [F] s_b_20_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3644 [F] s_b_21_0=sym_31682_3_parameter_inst.rt2 (const) */
    /* execute.simd:6227 [D] s_b_21_1 = ReadRegBank 5:s_b_21_0 (u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_21_1,emitter.const_u8(2));
    }
    /* execute.simd:3645 [D] s_b_21_2 = sym_143332_0_replaced_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_143332_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3650 [F] s_b_22_0=sym_31682_3_parameter_inst.rt2 (const) */
    /* execute.simd:6232 [D] s_b_22_1 = ReadRegBank 6:s_b_22_0 (u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_22_1,emitter.const_u8(4));
    }
    /* execute.simd:3651 [D] s_b_22_2 = sym_143332_0_replaced_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_143332_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_22_3: Store 4 s_b_22_2 <= s_b_22_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_1, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_22_2, s_b_22_1);
    /* execute.simd:0 [F] s_b_22_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_23: 
  {
    /* execute.simd:3664 [F] s_b_23_0=sym_31682_3_parameter_inst.rt2 (const) */
    /* execute.simd:6242 [D] s_b_23_1 = ReadRegBank 2:s_b_23_0 (u64) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_23_1,emitter.const_u8(8));
    }
    /* execute.simd:6243 [D] s_b_23_2 = ReadRegBank 3:s_b_23_0 (u64) */
    auto s_b_23_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),s_b_23_2,emitter.const_u8(8));
    }
    /* execute.simd:3665 [D] s_b_23_3 = sym_143332_0_replaced_parameter_addr uint64_t */
    auto s_b_23_3 = emitter.load_local(DV_sym_143332_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_23_4: Store 8 s_b_23_3 <= s_b_23_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_23_3, s_b_23_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_23_3, s_b_23_1);
    /* execute.simd:3666 [F] s_b_23_5 = constant u64 8 (const) */
    /* execute.simd:3666 [D] s_b_23_6 = s_b_23_3+s_b_23_5 */
    auto s_b_23_6 = emitter.add(s_b_23_3, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_23_7: Store 8 s_b_23_6 <= s_b_23_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_23_6, s_b_23_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_23_6, s_b_23_2);
    /* execute.simd:0 [F] s_b_23_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14, b_19, b_20, b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.simd:796 [F] s_b_24_0=sym_31682_3_parameter_inst.P (const) */
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
    /* execute.a64:2810 [D] s_b_25_0 = sym_143417_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_143417_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_25_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_25_2 = s_b_25_0&s_b_25_1 */
    auto s_b_25_2 = emitter.bitwise_and(s_b_25_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_25_3: sym_143417_3_parameter_value = s_b_25_2, dominates: s_b_27_0 s_b_28_1  */
    emitter.store_local(DV_sym_143417_3_parameter_value, s_b_25_2);
    /* execute.a64:2810 [F] s_b_25_4: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_4, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2813 [F] s_b_26_0=sym_31682_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_27_0 = sym_143417_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_143417_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_27_1: sym_143456_3_parameter_value = s_b_27_0, dominates: s_b_30_0 s_b_31_0 s_b_32_0  */
    emitter.store_local(DV_sym_143456_3_parameter_value, s_b_27_0);
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
    /* execute.a64:2816 [F] s_b_28_0=sym_31682_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_28_1 = sym_143417_3_parameter_value uint64_t */
    auto s_b_28_1 = emitter.load_local(DV_sym_143417_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2778 [D] s_b_30_0 = sym_143456_3_parameter_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_143456_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_31_0 = sym_143456_3_parameter_value uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_143456_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_32_0 = sym_143456_3_parameter_value uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_143456_3_parameter_value, emitter.context().types().u64());
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
  uint64_t CV_sym_148811_1_temporary_value;
  auto DV_sym_148811_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_148645_1_temporary_value;
  auto DV_sym_148645_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148925_1_tmp_s_b_52_2 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_32567_0_rm;
  auto DV_sym_32567_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_148491_1_temporary_value;
  auto DV_sym_148491_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_148896_1_temporary_value;
  auto DV_sym_148896_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_148291_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_148218_1_temporary_value;
  auto DV_sym_148218_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_148274_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1225 [F] s_b_0_0=sym_32540_3_parameter_inst.option0 (const) */
    /* execute.a64:1225 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1225 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1225 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1225 [F] s_b_0_4=sym_32540_3_parameter_inst.option21 (const) */
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
    /* execute.a64:1226 [F] s_b_1_0=sym_32540_3_parameter_inst.rm (const) */
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
    /* execute.a64:1238 [F] s_b_2_0=sym_32540_3_parameter_inst.rn (const) */
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
    /* execute.a64:1227 [F] s_b_3_0=sym_32540_3_parameter_inst.option0 (const) */
    /* execute.a64:1227 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1227 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1227 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1227 [F] s_b_3_4=sym_32540_3_parameter_inst.option21 (const) */
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
    /* execute.a64:1228 [F] s_b_4_0=sym_32540_3_parameter_inst.rm (const) */
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
    /* execute.a64:1229 [F] s_b_5_0=sym_32540_3_parameter_inst.option0 (const) */
    /* execute.a64:1229 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1229 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1229 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1229 [F] s_b_5_4=sym_32540_3_parameter_inst.option21 (const) */
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
    /* execute.a64:1230 [F] s_b_6_0=sym_32540_3_parameter_inst.rm (const) */
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
    /* execute.a64:1231 [F] s_b_7_0=sym_32540_3_parameter_inst.option0 (const) */
    /* execute.a64:1231 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1231 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1231 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1231 [F] s_b_7_4=sym_32540_3_parameter_inst.option21 (const) */
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
    /* execute.a64:1232 [F] s_b_8_0=sym_32540_3_parameter_inst.rm (const) */
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
    /* execute.a64:1234 [F] s_b_9_1: sym_32567_0_rm = s_b_9_0 (const), dominates: s_b_15_1  */
    CV_sym_32567_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_32567_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1235 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1234 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2709 [F] s_b_10_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_10_1: sym_148218_1_temporary_value = s_b_10_0 (const), dominates: s_b_12_0  */
    CV_sym_148218_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_148218_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_1,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [F] s_b_11_0=sym_32540_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_11_1 = ReadRegBank 1:s_b_11_0 (u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_11_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_11_2: sym_148218_1_temporary_value = s_b_11_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_148218_1_temporary_value, s_b_11_1);
    /* execute.a64:2709 [F] s_b_11_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [D] s_b_12_0 = sym_148218_1_temporary_value uint32_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_148218_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_12_1 = (u64)s_b_12_0 */
    auto s_b_12_1 = emitter.zx(s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2679 [D] s_b_12_2 = (u32)s_b_12_1 */
    auto s_b_12_2 = emitter.truncate(s_b_12_1, emitter.context().types().u32());
    /* execute.a64:2679 [D] s_b_12_3 = (u64)s_b_12_2 */
    auto s_b_12_3 = emitter.zx(s_b_12_2, emitter.context().types().u64());
    /* execute.a64:2679 [F] s_b_12_4=sym_32540_3_parameter_inst.S (const) */
    /* execute.a64:2679 [F] s_b_12_5 = (u64)s_b_12_4 (const) */
    /* execute.a64:2679 [D] s_b_12_6 = s_b_12_3<<s_b_12_5 */
    auto s_b_12_6 = emitter.shl(s_b_12_3, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1226 [D] s_b_12_7: sym_32567_0_rm = s_b_12_6, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32567_0_rm, s_b_12_6);
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
    /* execute.a64:2796 [F] s_b_14_0=sym_32540_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_14_2: sym_148274_0_return_symbol = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_148274_0_return_symbol, s_b_14_1);
    /* ???:4294967295 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14, b_18,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_148274_0_return_symbol uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_148274_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1238 [D] s_b_15_1 = sym_32567_0_rm uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_32567_0_rm, emitter.context().types().u64());
    /* execute.a64:1238 [D] s_b_15_2 = s_b_15_0+s_b_15_1 */
    auto s_b_15_2 = emitter.add(s_b_15_0, s_b_15_1);
    /* execute.a64:1240 [F] s_b_15_3=sym_32540_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_15_4: sym_148925_1_tmp_s_b_52_2 = s_b_15_2, dominates: s_b_32_2  */
    emitter.store_local(DV_sym_148925_1_tmp_s_b_52_2, s_b_15_2);
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
    /* execute.a64:2765 [D] s_b_16_1: sym_148291_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_148291_1__R_s_b_3_0, s_b_16_0);
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
    /* execute.a64:2794 [D] s_b_18_0 = sym_148291_1__R_s_b_3_0 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_148291_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1: sym_148274_0_return_symbol = s_b_18_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_148274_0_return_symbol, s_b_18_0);
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
    /* execute.a64:2768 [D] s_b_19_1: sym_148291_1__R_s_b_3_0 = s_b_19_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_148291_1__R_s_b_3_0, s_b_19_0);
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
    /* execute.a64:2770 [D] s_b_20_1: sym_148291_1__R_s_b_3_0 = s_b_20_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_148291_1__R_s_b_3_0, s_b_20_0);
    /* execute.a64:2770 [F] s_b_20_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2709 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_21_1: sym_148491_1_temporary_value = s_b_21_0 (const), dominates: s_b_23_0  */
    CV_sym_148491_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_148491_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_21_2: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_4,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2709 [F] s_b_22_0=sym_32540_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_22_1 = ReadRegBank 1:s_b_22_0 (u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_22_2: sym_148491_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_148491_1_temporary_value, s_b_22_1);
    /* execute.a64:2709 [F] s_b_22_3: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2709 [D] s_b_23_0 = sym_148491_1_temporary_value uint32_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_148491_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_23_1 = (u64)s_b_23_0 */
    auto s_b_23_1 = emitter.zx(s_b_23_0, emitter.context().types().u64());
    /* execute.a64:2695 [D] s_b_23_2 = (s32)s_b_23_1 */
    auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().s32());
    /* execute.a64:2695 [D] s_b_23_3 = (s64)s_b_23_2 */
    auto s_b_23_3 = emitter.sx(s_b_23_2, emitter.context().types().s64());
    /* execute.a64:2695 [D] s_b_23_4 = (u64)s_b_23_3 */
    auto s_b_23_4 = emitter.reinterpret(s_b_23_3, emitter.context().types().u64());
    /* execute.a64:2695 [F] s_b_23_5=sym_32540_3_parameter_inst.S (const) */
    /* execute.a64:2695 [F] s_b_23_6 = (u64)s_b_23_5 (const) */
    /* execute.a64:2695 [D] s_b_23_7 = s_b_23_4<<s_b_23_6 */
    auto s_b_23_7 = emitter.shl(s_b_23_4, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1228 [D] s_b_23_8: sym_32567_0_rm = s_b_23_7, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32567_0_rm, s_b_23_7);
    /* execute.a64:1228 [F] s_b_23_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [F] s_b_24_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_24_1: sym_148645_1_temporary_value = s_b_24_0 (const), dominates: s_b_26_0  */
    CV_sym_148645_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_148645_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_24_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_6,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2714 [F] s_b_25_0=sym_32540_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_25_1 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_25_2: sym_148645_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_148645_1_temporary_value, s_b_25_1);
    /* execute.a64:2714 [F] s_b_25_3: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_24, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2714 [D] s_b_26_0 = sym_148645_1_temporary_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_148645_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2683 [F] s_b_26_1=sym_32540_3_parameter_inst.S (const) */
    /* execute.a64:2683 [F] s_b_26_2 = (u64)s_b_26_1 (const) */
    /* execute.a64:2683 [D] s_b_26_3 = s_b_26_0<<s_b_26_2 */
    auto s_b_26_3 = emitter.shl(s_b_26_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1230 [D] s_b_26_4: sym_32567_0_rm = s_b_26_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32567_0_rm, s_b_26_3);
    /* execute.a64:1230 [F] s_b_26_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2714 [F] s_b_27_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_27_1: sym_148811_1_temporary_value = s_b_27_0 (const), dominates: s_b_29_0  */
    CV_sym_148811_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_148811_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_27_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_8,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2714 [F] s_b_28_0=sym_32540_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_28_1 = ReadRegBank 0:s_b_28_0 (u64) */
    auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_28_2: sym_148811_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_148811_1_temporary_value, s_b_28_1);
    /* execute.a64:2714 [F] s_b_28_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2714 [D] s_b_29_0 = sym_148811_1_temporary_value uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_148811_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2699 [F] s_b_29_1=sym_32540_3_parameter_inst.S (const) */
    /* execute.a64:2699 [F] s_b_29_2 = (u64)s_b_29_1 (const) */
    /* execute.a64:2699 [D] s_b_29_3 = s_b_29_0<<s_b_29_2 */
    auto s_b_29_3 = emitter.shl(s_b_29_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1232 [D] s_b_29_4: sym_32567_0_rm = s_b_29_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32567_0_rm, s_b_29_3);
    /* execute.a64:1232 [F] s_b_29_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2709 [F] s_b_30_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_30_1: sym_148896_1_temporary_value = s_b_30_0 (const), dominates: s_b_32_0  */
    CV_sym_148896_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_148896_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_30_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_15,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2709 [F] s_b_31_0=sym_32540_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_31_1 = ReadRegBank 1:s_b_31_0 (u32) */
    auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_31_2: sym_148896_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_148896_1_temporary_value, s_b_31_1);
    /* execute.a64:2709 [F] s_b_31_3: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2709 [D] s_b_32_0 = sym_148896_1_temporary_value uint32_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_148896_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_32_1 = (u64)s_b_32_0 */
    auto s_b_32_1 = emitter.zx(s_b_32_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_2 = sym_148925_1_tmp_s_b_52_2 uint64_t */
    auto s_b_32_2 = emitter.load_local(DV_sym_148925_1_tmp_s_b_52_2, emitter.context().types().u64());
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
  uint32_t CV_sym_149868_1_temporary_value;
  auto DV_sym_149868_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_149897_1_tmp_s_b_19_3 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_149761_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_149744_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1384 [F] s_b_0_0=sym_32825_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_2_0=sym_32825_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_149744_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_149744_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_149744_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_149744_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1385 [F] s_b_3_1=sym_32825_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1387 [F] s_b_3_4=sym_32825_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_3_5: sym_149897_1_tmp_s_b_19_3 = s_b_3_3, dominates: s_b_11_2  */
    emitter.store_local(DV_sym_149897_1_tmp_s_b_19_3, s_b_3_3);
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
    /* execute.a64:2765 [D] s_b_4_1: sym_149761_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_149761_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2794 [D] s_b_6_0 = sym_149761_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_149761_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_149744_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_149744_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2768 [D] s_b_7_1: sym_149761_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_149761_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2770 [D] s_b_8_1: sym_149761_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_149761_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2770 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2709 [F] s_b_9_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_9_1: sym_149868_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_149868_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_149868_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2709 [F] s_b_10_0=sym_32825_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_10_1 = ReadRegBank 1:s_b_10_0 (u32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_10_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_10_2: sym_149868_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_149868_1_temporary_value, s_b_10_1);
    /* execute.a64:2709 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [D] s_b_11_0 = sym_149868_1_temporary_value uint32_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_149868_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_11_1 = (u64)s_b_11_0 */
    auto s_b_11_1 = emitter.zx(s_b_11_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_2 = sym_149897_1_tmp_s_b_19_3 uint64_t */
    auto s_b_11_2 = emitter.load_local(DV_sym_149897_1_tmp_s_b_19_3, emitter.context().types().u64());
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
  uint64_t CV_sym_153457_0_return_symbol;
  uint32_t CV_sym_153454_0_replaced_parameter_imm;
  auto DV_sym_153498_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_33404_0_imm;
  auto DV_sym_33409_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153632_1__R_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153563_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153609_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153540_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_153689_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153592_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:34 [F] s_b_0_0=sym_33398_3_parameter_inst.imm12 (const) */
    /* execute.a64:34 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:34 [F] s_b_0_2=sym_33398_3_parameter_inst.shift (const) */
    /* ???:4294967295 [F] s_b_0_3: sym_153454_0_replaced_parameter_imm = s_b_0_1 (const), dominates: s_b_8_0 s_b_6_0  */
    CV_sym_153454_0_replaced_parameter_imm = ((uint32_t)insn.imm12);
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
    /* execute.a64:38 [F] s_b_1_0=sym_33398_3_parameter_inst.sf (const) */
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
    /* execute.a64:44 [F] s_b_3_0=sym_33398_3_parameter_inst.sf (const) */
    /* execute.a64:44 [D] s_b_3_1 = sym_33409_0_op1 uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_33409_0_op1, emitter.context().types().u64());
    /* execute.a64:44 [F] s_b_3_2 = sym_33404_0_imm (const) uint64_t */
    uint64_t s_b_3_2 = CV_sym_33404_0_imm;
    /* execute.a64:44 [D] s_b_3_3 = s_b_3_1-s_b_3_2 */
    auto s_b_3_3 = emitter.sub(s_b_3_1, emitter.const_u64(s_b_3_2));
    /* execute.a64:44 [D] s_b_3_4: sym_153498_3_parameter_value = s_b_3_3, dominates: s_b_10_0 s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_153498_3_parameter_value, s_b_3_3);
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
    /* execute.a64:39 [F] s_b_4_0=sym_33398_3_parameter_inst.rd (const) */
    /* execute.a64:39 [D] s_b_4_1 = sym_33409_0_op1 uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_33409_0_op1, emitter.context().types().u64());
    /* execute.a64:39 [D] s_b_4_2 = (u32)s_b_4_1 */
    auto s_b_4_2 = emitter.truncate(s_b_4_1, emitter.context().types().u32());
    /* execute.a64:39 [F] s_b_4_3 = sym_33404_0_imm (const) uint64_t */
    uint64_t s_b_4_3 = CV_sym_33404_0_imm;
    /* execute.a64:39 [F] s_b_4_4 = (u32)s_b_4_3 (const) */
    /* execute.a64:39 [F] s_b_4_5 = constant u8 0 (const) */
    /* execute.a64:39 [D] s_b_4_6 = __builtin_sbc32_flags */
    auto s_b_4_6 = emitter.sbcf(s_b_4_2, emitter.const_u32(((uint32_t)s_b_4_3)), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:39 [D] s_b_4_7: sym_153540_3_parameter_value = s_b_4_6, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_153540_3_parameter_value, s_b_4_6);
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
    /* execute.a64:41 [F] s_b_5_0=sym_33398_3_parameter_inst.rd (const) */
    /* execute.a64:41 [D] s_b_5_1 = sym_33409_0_op1 uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_33409_0_op1, emitter.context().types().u64());
    /* execute.a64:41 [F] s_b_5_2 = sym_33404_0_imm (const) uint64_t */
    uint64_t s_b_5_2 = CV_sym_33404_0_imm;
    /* execute.a64:41 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.a64:41 [D] s_b_5_4 = __builtin_sbc64_flags */
    auto s_b_5_4 = emitter.sbcf(s_b_5_1, emitter.const_u64(s_b_5_2), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:41 [D] s_b_5_5: sym_153563_3_parameter_value = s_b_5_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_153563_3_parameter_value, s_b_5_4);
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
    /* execute.a64:2826 [F] s_b_6_0 = sym_153454_0_replaced_parameter_imm (const) uint32_t */
    uint32_t s_b_6_0 = CV_sym_153454_0_replaced_parameter_imm;
    /* execute.a64:2826 [F] s_b_6_1 = (u64)s_b_6_0 (const) */
    /* ???:4294967295 [F] s_b_6_2: sym_153457_0_return_symbol = s_b_6_1 (const), dominates: s_b_7_0  */
    CV_sym_153457_0_return_symbol = ((uint64_t)s_b_6_0);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_8, b_9,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [F] s_b_7_0 = sym_153457_0_return_symbol (const) uint64_t */
    uint64_t s_b_7_0 = CV_sym_153457_0_return_symbol;
    /* execute.a64:34 [F] s_b_7_1: sym_33404_0_imm = s_b_7_0 (const), dominates: s_b_4_3 s_b_5_2 s_b_3_2  */
    CV_sym_33404_0_imm = s_b_7_0;
    /* execute.a64:35 [F] s_b_7_2=sym_33398_3_parameter_inst.sf (const) */
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
    /* execute.a64:2829 [F] s_b_8_0 = sym_153454_0_replaced_parameter_imm (const) uint32_t */
    uint32_t s_b_8_0 = CV_sym_153454_0_replaced_parameter_imm;
    /* execute.a64:2829 [F] s_b_8_1 = constant u32 c (const) */
    /* execute.a64:2829 [F] s_b_8_2 = s_b_8_0<<s_b_8_1 (const) */
    uint32_t s_b_8_2 = ((uint32_t)(s_b_8_0 << (uint32_t)12ULL));
    /* execute.a64:2829 [F] s_b_8_3 = (u64)s_b_8_2 (const) */
    /* ???:4294967295 [F] s_b_8_4: sym_153457_0_return_symbol = s_b_8_3 (const), dominates: s_b_7_0  */
    CV_sym_153457_0_return_symbol = ((uint64_t)s_b_8_2);
    /* ???:4294967295 [F] s_b_8_5: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2832 [F] s_b_9_0 = constant u64 0 (const) */
    /* ???:4294967295 [F] s_b_9_1: sym_153457_0_return_symbol = s_b_9_0 (const), dominates: s_b_7_0  */
    CV_sym_153457_0_return_symbol = (uint64_t)0ULL;
    /* ???:4294967295 [F] s_b_9_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2810 [D] s_b_10_0 = sym_153498_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_153498_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_10_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_10_2 = s_b_10_0&s_b_10_1 */
    auto s_b_10_2 = emitter.bitwise_and(s_b_10_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_10_3: sym_153498_3_parameter_value = s_b_10_2, dominates: s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_153498_3_parameter_value, s_b_10_2);
    /* execute.a64:2810 [F] s_b_10_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2813 [F] s_b_11_0=sym_33398_3_parameter_inst.rd (const) */
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
    /* execute.a64:2814 [D] s_b_12_0 = sym_153498_3_parameter_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_153498_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_12_1: sym_153689_3_parameter_value = s_b_12_0, dominates: s_b_33_0 s_b_34_0 s_b_35_0  */
    emitter.store_local(DV_sym_153689_3_parameter_value, s_b_12_0);
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
    /* execute.a64:2816 [F] s_b_13_0=sym_33398_3_parameter_inst.rd (const) */
    /* execute.a64:2816 [D] s_b_13_1 = sym_153498_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_153498_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2739 [F] s_b_14_0=sym_33398_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_14_1 = sym_153540_3_parameter_value uint32_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_153540_3_parameter_value, emitter.context().types().u32());
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
    /* execute.a64:2747 [F] s_b_15_0=sym_33398_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_15_1 = sym_153563_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_153563_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2793 [F] s_b_16_0=sym_33398_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_18_0=sym_33398_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_18_2: sym_153592_0_return_symbol = s_b_18_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_153592_0_return_symbol, s_b_18_1);
    /* ???:4294967295 [F] s_b_18_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_7,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2799 [F] s_b_19_0=sym_33398_3_parameter_inst.rn (const) */
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
    /* execute.a64:2802 [F] s_b_21_0=sym_33398_3_parameter_inst.rn (const) */
    /* execute.a64:2802 [D] s_b_21_1 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_1,emitter.const_u8(4));
    }
    /* execute.a64:2802 [D] s_b_21_2 = (u64)s_b_21_1 */
    auto s_b_21_2 = emitter.zx(s_b_21_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_3: sym_153592_0_return_symbol = s_b_21_2, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_153592_0_return_symbol, s_b_21_2);
    /* ???:4294967295 [F] s_b_21_4: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_18, b_21, b_25, b_30,  */
  fixed_block_b_22: 
  {
    /* ???:4294967295 [D] s_b_22_0 = sym_153592_0_return_symbol uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_153592_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:35 [D] s_b_22_1: sym_33409_0_op1 = s_b_22_0, dominates: s_b_4_1 s_b_5_1 s_b_3_1  */
    emitter.store_local(DV_sym_33409_0_op1, s_b_22_0);
    /* execute.a64:37 [F] s_b_22_2=sym_33398_3_parameter_inst.S (const) */
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
    /* execute.a64:2765 [D] s_b_23_1: sym_153609_1__R_s_b_3_0 = s_b_23_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_153609_1__R_s_b_3_0, s_b_23_0);
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
    /* execute.a64:2794 [D] s_b_25_0 = sym_153609_1__R_s_b_3_0 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_153609_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_25_1: sym_153592_0_return_symbol = s_b_25_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_153592_0_return_symbol, s_b_25_0);
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
    /* execute.a64:2768 [D] s_b_26_1: sym_153609_1__R_s_b_3_0 = s_b_26_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_153609_1__R_s_b_3_0, s_b_26_0);
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
    /* execute.a64:2770 [D] s_b_27_1: sym_153609_1__R_s_b_3_0 = s_b_27_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_153609_1__R_s_b_3_0, s_b_27_0);
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
    /* execute.a64:2765 [D] s_b_28_1: sym_153632_1__R_s_b_5_0 = s_b_28_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_153632_1__R_s_b_5_0, s_b_28_0);
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
    /* execute.a64:2800 [D] s_b_30_0 = sym_153632_1__R_s_b_5_0 uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_153632_1__R_s_b_5_0, emitter.context().types().u64());
    /* execute.a64:2800 [D] s_b_30_1 = (u32)s_b_30_0 */
    auto s_b_30_1 = emitter.truncate(s_b_30_0, emitter.context().types().u32());
    /* execute.a64:2800 [D] s_b_30_2 = (u64)s_b_30_1 */
    auto s_b_30_2 = emitter.zx(s_b_30_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_30_3: sym_153592_0_return_symbol = s_b_30_2, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_153592_0_return_symbol, s_b_30_2);
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
    /* execute.a64:2768 [D] s_b_31_1: sym_153632_1__R_s_b_5_0 = s_b_31_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_153632_1__R_s_b_5_0, s_b_31_0);
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
    /* execute.a64:2770 [D] s_b_32_1: sym_153632_1__R_s_b_5_0 = s_b_32_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_153632_1__R_s_b_5_0, s_b_32_0);
    /* execute.a64:2770 [F] s_b_32_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_12,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2778 [D] s_b_33_0 = sym_153689_3_parameter_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_153689_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_34_0 = sym_153689_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_153689_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_35_0 = sym_153689_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_153689_3_parameter_value, emitter.context().types().u64());
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
  auto DV_sym_39932_0_rn = emitter.alloc_local(emitter.context().types().v8u8(), true);
  auto DV_sym_39937_0_min = emitter.alloc_local(emitter.context().types().u8(), true);
  auto DV_sym_40069_0_rn = emitter.alloc_local(emitter.context().types().v16u8(), true);
  auto DV_sym_40074_0_min = emitter.alloc_local(emitter.context().types().u8(), true);
  auto DV_sym_40342_0_rn = emitter.alloc_local(emitter.context().types().v4u16(), true);
  auto DV_sym_40347_0_min = emitter.alloc_local(emitter.context().types().u16(), true);
  auto DV_sym_40411_0_rn = emitter.alloc_local(emitter.context().types().v8u16(), true);
  auto DV_sym_40416_0_min = emitter.alloc_local(emitter.context().types().u16(), true);
  auto DV_sym_40548_0_rn = emitter.alloc_local(emitter.context().types().v4u32(), true);
  auto DV_sym_40553_0_min = emitter.alloc_local(emitter.context().types().u32(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:251 [F] s_b_0_0=sym_39924_3_parameter_inst.arrangement (const) */
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
    /* execute.simd:253 [F] s_b_2_0=sym_39924_3_parameter_inst.rn (const) */
    /* execute.simd:253 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:253 [D] s_b_2_2: sym_39932_0_rn = s_b_2_1, dominates: s_b_3_0 s_b_4_0 s_b_5_0 s_b_6_0 s_b_7_0 s_b_8_0 s_b_9_0 s_b_10_0 s_b_11_0 s_b_12_0 s_b_13_0 s_b_14_0 s_b_15_0  */
    emitter.store_local(DV_sym_39932_0_rn, s_b_2_1);
    /* execute.simd:255 [F] s_b_2_3 = constant s32 0 (const) */
    /* execute.simd:255 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:255 [D] s_b_2_5: sym_39937_0_min = s_b_2_4, dominates: s_b_4_3 s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
    emitter.store_local(DV_sym_39937_0_min, s_b_2_4);
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
    /* execute.simd:266 [F] s_b_17_0=sym_39924_3_parameter_inst.rn (const) */
    /* execute.simd:266 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:266 [D] s_b_17_2: sym_40069_0_rn = s_b_17_1, dominates: s_b_18_0 s_b_19_0 s_b_20_0 s_b_21_0 s_b_22_0 s_b_23_0 s_b_24_0 s_b_25_0 s_b_26_0 s_b_27_0 s_b_28_0 s_b_29_0 s_b_30_0 s_b_31_0 s_b_32_0 s_b_33_0 s_b_34_0 s_b_35_0 s_b_36_0 s_b_37_0 s_b_38_0 s_b_39_0 s_b_40_0 s_b_41_0 s_b_42_0 s_b_43_0 s_b_44_0 s_b_45_0 s_b_46_0  */
    emitter.store_local(DV_sym_40069_0_rn, s_b_17_1);
    /* execute.simd:268 [F] s_b_17_3 = constant s32 0 (const) */
    /* execute.simd:268 [D] s_b_17_1[s_b_17_3] */
    auto s_b_17_4 = emitter.vector_extract(s_b_17_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:268 [D] s_b_17_5: sym_40074_0_min = s_b_17_4, dominates: s_b_19_3 s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
    emitter.store_local(DV_sym_40074_0_min, s_b_17_4);
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
    /* execute.simd:279 [F] s_b_48_0=sym_39924_3_parameter_inst.rn (const) */
    /* execute.simd:279 [D] s_b_48_1 = ReadRegBank 17:s_b_48_0 (v4u16) */
    auto s_b_48_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_48_1,emitter.const_u8(8));
    }
    /* execute.simd:279 [D] s_b_48_2: sym_40342_0_rn = s_b_48_1, dominates: s_b_49_0 s_b_50_0 s_b_51_0 s_b_52_0 s_b_53_0  */
    emitter.store_local(DV_sym_40342_0_rn, s_b_48_1);
    /* execute.simd:281 [F] s_b_48_3 = constant s32 0 (const) */
    /* execute.simd:281 [D] s_b_48_1[s_b_48_3] */
    auto s_b_48_4 = emitter.vector_extract(s_b_48_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:281 [D] s_b_48_5: sym_40347_0_min = s_b_48_4, dominates: s_b_50_3 s_b_52_3 s_b_54_1  */
    emitter.store_local(DV_sym_40347_0_min, s_b_48_4);
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
    /* execute.simd:292 [F] s_b_55_0=sym_39924_3_parameter_inst.rn (const) */
    /* execute.simd:292 [D] s_b_55_1 = ReadRegBank 18:s_b_55_0 (v8u16) */
    auto s_b_55_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_55_1,emitter.const_u8(16));
    }
    /* execute.simd:292 [D] s_b_55_2: sym_40411_0_rn = s_b_55_1, dominates: s_b_56_0 s_b_57_0 s_b_58_0 s_b_59_0 s_b_60_0 s_b_61_0 s_b_62_0 s_b_63_0 s_b_64_0 s_b_65_0 s_b_66_0 s_b_67_0 s_b_68_0  */
    emitter.store_local(DV_sym_40411_0_rn, s_b_55_1);
    /* execute.simd:294 [F] s_b_55_3 = constant s32 0 (const) */
    /* execute.simd:294 [D] s_b_55_1[s_b_55_3] */
    auto s_b_55_4 = emitter.vector_extract(s_b_55_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:294 [D] s_b_55_5: sym_40416_0_min = s_b_55_4, dominates: s_b_57_3 s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
    emitter.store_local(DV_sym_40416_0_min, s_b_55_4);
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
    /* execute.simd:305 [F] s_b_70_0=sym_39924_3_parameter_inst.rn (const) */
    /* execute.simd:305 [D] s_b_70_1 = ReadRegBank 20:s_b_70_0 (v4u32) */
    auto s_b_70_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_70_1,emitter.const_u8(16));
    }
    /* execute.simd:305 [D] s_b_70_2: sym_40548_0_rn = s_b_70_1, dominates: s_b_71_0 s_b_72_0 s_b_73_0 s_b_74_0 s_b_75_0  */
    emitter.store_local(DV_sym_40548_0_rn, s_b_70_1);
    /* execute.simd:307 [F] s_b_70_3 = constant s32 0 (const) */
    /* execute.simd:307 [D] s_b_70_1[s_b_70_3] */
    auto s_b_70_4 = emitter.vector_extract(s_b_70_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:307 [D] s_b_70_5: sym_40553_0_min = s_b_70_4, dominates: s_b_72_3 s_b_74_3 s_b_76_1  */
    emitter.store_local(DV_sym_40553_0_min, s_b_70_4);
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
        /* execute.simd:258 [D] s_b_3_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_3_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_3_1 = constant u8 1 (const) */
        /* execute.simd:258 [D] s_b_3_0[s_b_3_1] */
        auto s_b_3_2 = emitter.vector_extract(s_b_3_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:258 [D] s_b_3_3: sym_39937_0_min = s_b_3_2, dominates: s_b_4_3 s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_39937_0_min, s_b_3_2);
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
        /* execute.simd:257 [D] s_b_4_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_4_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_4_1 = constant u8 2 (const) */
        /* execute.simd:257 [D] s_b_4_0[s_b_4_1] */
        auto s_b_4_2 = emitter.vector_extract(s_b_4_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:257 [D] s_b_4_3 = sym_39937_0_min uint8_t */
        auto s_b_4_3 = emitter.load_local(DV_sym_39937_0_min, emitter.context().types().u8());
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
        /* execute.simd:258 [D] s_b_5_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_5_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_5_1 = constant u8 2 (const) */
        /* execute.simd:258 [D] s_b_5_0[s_b_5_1] */
        auto s_b_5_2 = emitter.vector_extract(s_b_5_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:258 [D] s_b_5_3: sym_39937_0_min = s_b_5_2, dominates: s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_39937_0_min, s_b_5_2);
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
        /* execute.simd:257 [D] s_b_6_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_6_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_6_1 = constant u8 3 (const) */
        /* execute.simd:257 [D] s_b_6_0[s_b_6_1] */
        auto s_b_6_2 = emitter.vector_extract(s_b_6_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:257 [D] s_b_6_3 = sym_39937_0_min uint8_t */
        auto s_b_6_3 = emitter.load_local(DV_sym_39937_0_min, emitter.context().types().u8());
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
        /* execute.simd:258 [D] s_b_7_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_7_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_7_1 = constant u8 3 (const) */
        /* execute.simd:258 [D] s_b_7_0[s_b_7_1] */
        auto s_b_7_2 = emitter.vector_extract(s_b_7_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:258 [D] s_b_7_3: sym_39937_0_min = s_b_7_2, dominates: s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_39937_0_min, s_b_7_2);
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
        /* execute.simd:257 [D] s_b_8_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_8_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_8_1 = constant u8 4 (const) */
        /* execute.simd:257 [D] s_b_8_0[s_b_8_1] */
        auto s_b_8_2 = emitter.vector_extract(s_b_8_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:257 [D] s_b_8_3 = sym_39937_0_min uint8_t */
        auto s_b_8_3 = emitter.load_local(DV_sym_39937_0_min, emitter.context().types().u8());
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
        /* execute.simd:258 [D] s_b_9_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_9_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_9_1 = constant u8 4 (const) */
        /* execute.simd:258 [D] s_b_9_0[s_b_9_1] */
        auto s_b_9_2 = emitter.vector_extract(s_b_9_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:258 [D] s_b_9_3: sym_39937_0_min = s_b_9_2, dominates: s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_39937_0_min, s_b_9_2);
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
        /* execute.simd:257 [D] s_b_10_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_10_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_10_1 = constant u8 5 (const) */
        /* execute.simd:257 [D] s_b_10_0[s_b_10_1] */
        auto s_b_10_2 = emitter.vector_extract(s_b_10_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:257 [D] s_b_10_3 = sym_39937_0_min uint8_t */
        auto s_b_10_3 = emitter.load_local(DV_sym_39937_0_min, emitter.context().types().u8());
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
        /* execute.simd:258 [D] s_b_11_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_11_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_11_1 = constant u8 5 (const) */
        /* execute.simd:258 [D] s_b_11_0[s_b_11_1] */
        auto s_b_11_2 = emitter.vector_extract(s_b_11_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:258 [D] s_b_11_3: sym_39937_0_min = s_b_11_2, dominates: s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_39937_0_min, s_b_11_2);
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
        /* execute.simd:257 [D] s_b_12_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_12_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_12_1 = constant u8 6 (const) */
        /* execute.simd:257 [D] s_b_12_0[s_b_12_1] */
        auto s_b_12_2 = emitter.vector_extract(s_b_12_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:257 [D] s_b_12_3 = sym_39937_0_min uint8_t */
        auto s_b_12_3 = emitter.load_local(DV_sym_39937_0_min, emitter.context().types().u8());
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
        /* execute.simd:258 [D] s_b_13_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_13_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_13_1 = constant u8 6 (const) */
        /* execute.simd:258 [D] s_b_13_0[s_b_13_1] */
        auto s_b_13_2 = emitter.vector_extract(s_b_13_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:258 [D] s_b_13_3: sym_39937_0_min = s_b_13_2, dominates: s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_39937_0_min, s_b_13_2);
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
        /* execute.simd:257 [D] s_b_14_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_14_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_14_1 = constant u8 7 (const) */
        /* execute.simd:257 [D] s_b_14_0[s_b_14_1] */
        auto s_b_14_2 = emitter.vector_extract(s_b_14_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:257 [D] s_b_14_3 = sym_39937_0_min uint8_t */
        auto s_b_14_3 = emitter.load_local(DV_sym_39937_0_min, emitter.context().types().u8());
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
        /* execute.simd:258 [D] s_b_15_0 = sym_39932_0_rn wutils::Vector<uint8_t, 8> */
        auto s_b_15_0 = emitter.load_local(DV_sym_39932_0_rn, emitter.context().types().v8u8());
        /* ???:4294967295 [F] s_b_15_1 = constant u8 7 (const) */
        /* execute.simd:258 [D] s_b_15_0[s_b_15_1] */
        auto s_b_15_2 = emitter.vector_extract(s_b_15_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:258 [D] s_b_15_3: sym_39937_0_min = s_b_15_2, dominates: s_b_16_1  */
        emitter.store_local(DV_sym_39937_0_min, s_b_15_2);
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
        /* execute.simd:262 [F] s_b_16_0=sym_39924_3_parameter_inst.rd (const) */
        /* execute.simd:262 [D] s_b_16_1 = sym_39937_0_min uint8_t */
        auto s_b_16_1 = emitter.load_local(DV_sym_39937_0_min, emitter.context().types().u8());
        /* execute.simd:6187 [D] s_b_16_2 = (u64)s_b_16_1 */
        auto s_b_16_2 = emitter.zx(s_b_16_1, emitter.context().types().u64());
        /* execute.simd:6187 [D] s_b_16_3: WriteRegBank 2:s_b_16_0 = s_b_16_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_2);
        /* execute.simd:6188 [F] s_b_16_4 = constant u64 0 (const) */
        /* execute.simd:6188 [F] s_b_16_5: WriteRegBank 3:s_b_16_0 = s_b_16_4 */
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
        /* execute.simd:271 [D] s_b_18_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_18_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_18_1 = constant u8 1 (const) */
        /* execute.simd:271 [D] s_b_18_0[s_b_18_1] */
        auto s_b_18_2 = emitter.vector_extract(s_b_18_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:271 [D] s_b_18_3: sym_40074_0_min = s_b_18_2, dominates: s_b_19_3 s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_18_2);
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
        /* execute.simd:270 [D] s_b_19_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_19_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_19_1 = constant u8 2 (const) */
        /* execute.simd:270 [D] s_b_19_0[s_b_19_1] */
        auto s_b_19_2 = emitter.vector_extract(s_b_19_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:270 [D] s_b_19_3 = sym_40074_0_min uint8_t */
        auto s_b_19_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_20_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_20_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_20_1 = constant u8 2 (const) */
        /* execute.simd:271 [D] s_b_20_0[s_b_20_1] */
        auto s_b_20_2 = emitter.vector_extract(s_b_20_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:271 [D] s_b_20_3: sym_40074_0_min = s_b_20_2, dominates: s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_20_2);
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
        /* execute.simd:270 [D] s_b_21_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_21_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_21_1 = constant u8 3 (const) */
        /* execute.simd:270 [D] s_b_21_0[s_b_21_1] */
        auto s_b_21_2 = emitter.vector_extract(s_b_21_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:270 [D] s_b_21_3 = sym_40074_0_min uint8_t */
        auto s_b_21_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_22_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_22_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_22_1 = constant u8 3 (const) */
        /* execute.simd:271 [D] s_b_22_0[s_b_22_1] */
        auto s_b_22_2 = emitter.vector_extract(s_b_22_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:271 [D] s_b_22_3: sym_40074_0_min = s_b_22_2, dominates: s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_22_2);
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
        /* execute.simd:270 [D] s_b_23_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_23_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_23_1 = constant u8 4 (const) */
        /* execute.simd:270 [D] s_b_23_0[s_b_23_1] */
        auto s_b_23_2 = emitter.vector_extract(s_b_23_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:270 [D] s_b_23_3 = sym_40074_0_min uint8_t */
        auto s_b_23_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_24_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_24_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_24_1 = constant u8 4 (const) */
        /* execute.simd:271 [D] s_b_24_0[s_b_24_1] */
        auto s_b_24_2 = emitter.vector_extract(s_b_24_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:271 [D] s_b_24_3: sym_40074_0_min = s_b_24_2, dominates: s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_24_2);
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
        /* execute.simd:270 [D] s_b_25_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_25_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_25_1 = constant u8 5 (const) */
        /* execute.simd:270 [D] s_b_25_0[s_b_25_1] */
        auto s_b_25_2 = emitter.vector_extract(s_b_25_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:270 [D] s_b_25_3 = sym_40074_0_min uint8_t */
        auto s_b_25_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_26_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_26_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_26_1 = constant u8 5 (const) */
        /* execute.simd:271 [D] s_b_26_0[s_b_26_1] */
        auto s_b_26_2 = emitter.vector_extract(s_b_26_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:271 [D] s_b_26_3: sym_40074_0_min = s_b_26_2, dominates: s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_26_2);
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
        /* execute.simd:270 [D] s_b_27_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_27_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_27_1 = constant u8 6 (const) */
        /* execute.simd:270 [D] s_b_27_0[s_b_27_1] */
        auto s_b_27_2 = emitter.vector_extract(s_b_27_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:270 [D] s_b_27_3 = sym_40074_0_min uint8_t */
        auto s_b_27_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_28_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_28_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_28_1 = constant u8 6 (const) */
        /* execute.simd:271 [D] s_b_28_0[s_b_28_1] */
        auto s_b_28_2 = emitter.vector_extract(s_b_28_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:271 [D] s_b_28_3: sym_40074_0_min = s_b_28_2, dominates: s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_28_2);
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
        /* execute.simd:270 [D] s_b_29_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_29_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_29_1 = constant u8 7 (const) */
        /* execute.simd:270 [D] s_b_29_0[s_b_29_1] */
        auto s_b_29_2 = emitter.vector_extract(s_b_29_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:270 [D] s_b_29_3 = sym_40074_0_min uint8_t */
        auto s_b_29_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_30_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_30_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_30_1 = constant u8 7 (const) */
        /* execute.simd:271 [D] s_b_30_0[s_b_30_1] */
        auto s_b_30_2 = emitter.vector_extract(s_b_30_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:271 [D] s_b_30_3: sym_40074_0_min = s_b_30_2, dominates: s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_30_2);
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
        /* execute.simd:270 [D] s_b_31_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_31_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_31_1 = constant u8 8 (const) */
        /* execute.simd:270 [D] s_b_31_0[s_b_31_1] */
        auto s_b_31_2 = emitter.vector_extract(s_b_31_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:270 [D] s_b_31_3 = sym_40074_0_min uint8_t */
        auto s_b_31_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_32_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_32_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_32_1 = constant u8 8 (const) */
        /* execute.simd:271 [D] s_b_32_0[s_b_32_1] */
        auto s_b_32_2 = emitter.vector_extract(s_b_32_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:271 [D] s_b_32_3: sym_40074_0_min = s_b_32_2, dominates: s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_32_2);
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
        /* execute.simd:270 [D] s_b_33_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_33_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_33_1 = constant u8 9 (const) */
        /* execute.simd:270 [D] s_b_33_0[s_b_33_1] */
        auto s_b_33_2 = emitter.vector_extract(s_b_33_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:270 [D] s_b_33_3 = sym_40074_0_min uint8_t */
        auto s_b_33_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_34_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_34_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_34_1 = constant u8 9 (const) */
        /* execute.simd:271 [D] s_b_34_0[s_b_34_1] */
        auto s_b_34_2 = emitter.vector_extract(s_b_34_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:271 [D] s_b_34_3: sym_40074_0_min = s_b_34_2, dominates: s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_34_2);
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
        /* execute.simd:270 [D] s_b_35_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_35_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_35_1 = constant u8 a (const) */
        /* execute.simd:270 [D] s_b_35_0[s_b_35_1] */
        auto s_b_35_2 = emitter.vector_extract(s_b_35_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:270 [D] s_b_35_3 = sym_40074_0_min uint8_t */
        auto s_b_35_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_36_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_36_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_36_1 = constant u8 a (const) */
        /* execute.simd:271 [D] s_b_36_0[s_b_36_1] */
        auto s_b_36_2 = emitter.vector_extract(s_b_36_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:271 [D] s_b_36_3: sym_40074_0_min = s_b_36_2, dominates: s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_36_2);
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
        /* execute.simd:270 [D] s_b_37_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_37_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_37_1 = constant u8 b (const) */
        /* execute.simd:270 [D] s_b_37_0[s_b_37_1] */
        auto s_b_37_2 = emitter.vector_extract(s_b_37_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:270 [D] s_b_37_3 = sym_40074_0_min uint8_t */
        auto s_b_37_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_38_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_38_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_38_1 = constant u8 b (const) */
        /* execute.simd:271 [D] s_b_38_0[s_b_38_1] */
        auto s_b_38_2 = emitter.vector_extract(s_b_38_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:271 [D] s_b_38_3: sym_40074_0_min = s_b_38_2, dominates: s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_38_2);
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
        /* execute.simd:270 [D] s_b_39_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_39_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_39_1 = constant u8 c (const) */
        /* execute.simd:270 [D] s_b_39_0[s_b_39_1] */
        auto s_b_39_2 = emitter.vector_extract(s_b_39_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:270 [D] s_b_39_3 = sym_40074_0_min uint8_t */
        auto s_b_39_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_40_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_40_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_40_1 = constant u8 c (const) */
        /* execute.simd:271 [D] s_b_40_0[s_b_40_1] */
        auto s_b_40_2 = emitter.vector_extract(s_b_40_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:271 [D] s_b_40_3: sym_40074_0_min = s_b_40_2, dominates: s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_40_2);
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
        /* execute.simd:270 [D] s_b_41_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_41_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_41_1 = constant u8 d (const) */
        /* execute.simd:270 [D] s_b_41_0[s_b_41_1] */
        auto s_b_41_2 = emitter.vector_extract(s_b_41_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:270 [D] s_b_41_3 = sym_40074_0_min uint8_t */
        auto s_b_41_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_42_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_42_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_42_1 = constant u8 d (const) */
        /* execute.simd:271 [D] s_b_42_0[s_b_42_1] */
        auto s_b_42_2 = emitter.vector_extract(s_b_42_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:271 [D] s_b_42_3: sym_40074_0_min = s_b_42_2, dominates: s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_42_2);
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
        /* execute.simd:270 [D] s_b_43_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_43_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_43_1 = constant u8 e (const) */
        /* execute.simd:270 [D] s_b_43_0[s_b_43_1] */
        auto s_b_43_2 = emitter.vector_extract(s_b_43_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:270 [D] s_b_43_3 = sym_40074_0_min uint8_t */
        auto s_b_43_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_44_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_44_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_44_1 = constant u8 e (const) */
        /* execute.simd:271 [D] s_b_44_0[s_b_44_1] */
        auto s_b_44_2 = emitter.vector_extract(s_b_44_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:271 [D] s_b_44_3: sym_40074_0_min = s_b_44_2, dominates: s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_44_2);
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
        /* execute.simd:270 [D] s_b_45_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_45_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_45_1 = constant u8 f (const) */
        /* execute.simd:270 [D] s_b_45_0[s_b_45_1] */
        auto s_b_45_2 = emitter.vector_extract(s_b_45_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:270 [D] s_b_45_3 = sym_40074_0_min uint8_t */
        auto s_b_45_3 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
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
        /* execute.simd:271 [D] s_b_46_0 = sym_40069_0_rn wutils::Vector<uint8_t, 16> */
        auto s_b_46_0 = emitter.load_local(DV_sym_40069_0_rn, emitter.context().types().v16u8());
        /* ???:4294967295 [F] s_b_46_1 = constant u8 f (const) */
        /* execute.simd:271 [D] s_b_46_0[s_b_46_1] */
        auto s_b_46_2 = emitter.vector_extract(s_b_46_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:271 [D] s_b_46_3: sym_40074_0_min = s_b_46_2, dominates: s_b_47_1  */
        emitter.store_local(DV_sym_40074_0_min, s_b_46_2);
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
        /* execute.simd:275 [F] s_b_47_0=sym_39924_3_parameter_inst.rd (const) */
        /* execute.simd:275 [D] s_b_47_1 = sym_40074_0_min uint8_t */
        auto s_b_47_1 = emitter.load_local(DV_sym_40074_0_min, emitter.context().types().u8());
        /* execute.simd:6187 [D] s_b_47_2 = (u64)s_b_47_1 */
        auto s_b_47_2 = emitter.zx(s_b_47_1, emitter.context().types().u64());
        /* execute.simd:6187 [D] s_b_47_3: WriteRegBank 2:s_b_47_0 = s_b_47_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_47_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_47_2);
        /* execute.simd:6188 [F] s_b_47_4 = constant u64 0 (const) */
        /* execute.simd:6188 [F] s_b_47_5: WriteRegBank 3:s_b_47_0 = s_b_47_4 */
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
        /* execute.simd:284 [D] s_b_49_0 = sym_40342_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_49_0 = emitter.load_local(DV_sym_40342_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_49_1 = constant u8 1 (const) */
        /* execute.simd:284 [D] s_b_49_0[s_b_49_1] */
        auto s_b_49_2 = emitter.vector_extract(s_b_49_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:284 [D] s_b_49_3: sym_40347_0_min = s_b_49_2, dominates: s_b_50_3 s_b_52_3 s_b_54_1  */
        emitter.store_local(DV_sym_40347_0_min, s_b_49_2);
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
        /* execute.simd:283 [D] s_b_50_0 = sym_40342_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_50_0 = emitter.load_local(DV_sym_40342_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_50_1 = constant u8 2 (const) */
        /* execute.simd:283 [D] s_b_50_0[s_b_50_1] */
        auto s_b_50_2 = emitter.vector_extract(s_b_50_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:283 [D] s_b_50_3 = sym_40347_0_min uint16_t */
        auto s_b_50_3 = emitter.load_local(DV_sym_40347_0_min, emitter.context().types().u16());
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
        /* execute.simd:284 [D] s_b_51_0 = sym_40342_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_51_0 = emitter.load_local(DV_sym_40342_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_51_1 = constant u8 2 (const) */
        /* execute.simd:284 [D] s_b_51_0[s_b_51_1] */
        auto s_b_51_2 = emitter.vector_extract(s_b_51_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:284 [D] s_b_51_3: sym_40347_0_min = s_b_51_2, dominates: s_b_52_3 s_b_54_1  */
        emitter.store_local(DV_sym_40347_0_min, s_b_51_2);
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
        /* execute.simd:283 [D] s_b_52_0 = sym_40342_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_52_0 = emitter.load_local(DV_sym_40342_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_52_1 = constant u8 3 (const) */
        /* execute.simd:283 [D] s_b_52_0[s_b_52_1] */
        auto s_b_52_2 = emitter.vector_extract(s_b_52_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:283 [D] s_b_52_3 = sym_40347_0_min uint16_t */
        auto s_b_52_3 = emitter.load_local(DV_sym_40347_0_min, emitter.context().types().u16());
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
        /* execute.simd:284 [D] s_b_53_0 = sym_40342_0_rn wutils::Vector<uint16_t, 4> */
        auto s_b_53_0 = emitter.load_local(DV_sym_40342_0_rn, emitter.context().types().v4u16());
        /* ???:4294967295 [F] s_b_53_1 = constant u8 3 (const) */
        /* execute.simd:284 [D] s_b_53_0[s_b_53_1] */
        auto s_b_53_2 = emitter.vector_extract(s_b_53_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:284 [D] s_b_53_3: sym_40347_0_min = s_b_53_2, dominates: s_b_54_1  */
        emitter.store_local(DV_sym_40347_0_min, s_b_53_2);
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
        /* execute.simd:288 [F] s_b_54_0=sym_39924_3_parameter_inst.rd (const) */
        /* execute.simd:288 [D] s_b_54_1 = sym_40347_0_min uint16_t */
        auto s_b_54_1 = emitter.load_local(DV_sym_40347_0_min, emitter.context().types().u16());
        /* execute.simd:6194 [D] s_b_54_2 = (u64)s_b_54_1 */
        auto s_b_54_2 = emitter.zx(s_b_54_1, emitter.context().types().u64());
        /* execute.simd:6194 [D] s_b_54_3: WriteRegBank 2:s_b_54_0 = s_b_54_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_54_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_54_2);
        /* execute.simd:6195 [F] s_b_54_4 = constant u64 0 (const) */
        /* execute.simd:6195 [F] s_b_54_5: WriteRegBank 3:s_b_54_0 = s_b_54_4 */
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
        /* execute.simd:297 [D] s_b_56_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_56_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_56_1 = constant u8 1 (const) */
        /* execute.simd:297 [D] s_b_56_0[s_b_56_1] */
        auto s_b_56_2 = emitter.vector_extract(s_b_56_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:297 [D] s_b_56_3: sym_40416_0_min = s_b_56_2, dominates: s_b_57_3 s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40416_0_min, s_b_56_2);
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
        /* execute.simd:296 [D] s_b_57_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_57_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_57_1 = constant u8 2 (const) */
        /* execute.simd:296 [D] s_b_57_0[s_b_57_1] */
        auto s_b_57_2 = emitter.vector_extract(s_b_57_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:296 [D] s_b_57_3 = sym_40416_0_min uint16_t */
        auto s_b_57_3 = emitter.load_local(DV_sym_40416_0_min, emitter.context().types().u16());
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
        /* execute.simd:297 [D] s_b_58_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_58_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_58_1 = constant u8 2 (const) */
        /* execute.simd:297 [D] s_b_58_0[s_b_58_1] */
        auto s_b_58_2 = emitter.vector_extract(s_b_58_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:297 [D] s_b_58_3: sym_40416_0_min = s_b_58_2, dominates: s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40416_0_min, s_b_58_2);
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
        /* execute.simd:296 [D] s_b_59_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_59_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_59_1 = constant u8 3 (const) */
        /* execute.simd:296 [D] s_b_59_0[s_b_59_1] */
        auto s_b_59_2 = emitter.vector_extract(s_b_59_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:296 [D] s_b_59_3 = sym_40416_0_min uint16_t */
        auto s_b_59_3 = emitter.load_local(DV_sym_40416_0_min, emitter.context().types().u16());
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
        /* execute.simd:297 [D] s_b_60_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_60_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_60_1 = constant u8 3 (const) */
        /* execute.simd:297 [D] s_b_60_0[s_b_60_1] */
        auto s_b_60_2 = emitter.vector_extract(s_b_60_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:297 [D] s_b_60_3: sym_40416_0_min = s_b_60_2, dominates: s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40416_0_min, s_b_60_2);
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
        /* execute.simd:296 [D] s_b_61_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_61_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_61_1 = constant u8 4 (const) */
        /* execute.simd:296 [D] s_b_61_0[s_b_61_1] */
        auto s_b_61_2 = emitter.vector_extract(s_b_61_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:296 [D] s_b_61_3 = sym_40416_0_min uint16_t */
        auto s_b_61_3 = emitter.load_local(DV_sym_40416_0_min, emitter.context().types().u16());
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
        /* execute.simd:297 [D] s_b_62_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_62_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_62_1 = constant u8 4 (const) */
        /* execute.simd:297 [D] s_b_62_0[s_b_62_1] */
        auto s_b_62_2 = emitter.vector_extract(s_b_62_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:297 [D] s_b_62_3: sym_40416_0_min = s_b_62_2, dominates: s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40416_0_min, s_b_62_2);
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
        /* execute.simd:296 [D] s_b_63_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_63_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_63_1 = constant u8 5 (const) */
        /* execute.simd:296 [D] s_b_63_0[s_b_63_1] */
        auto s_b_63_2 = emitter.vector_extract(s_b_63_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:296 [D] s_b_63_3 = sym_40416_0_min uint16_t */
        auto s_b_63_3 = emitter.load_local(DV_sym_40416_0_min, emitter.context().types().u16());
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
        /* execute.simd:297 [D] s_b_64_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_64_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_64_1 = constant u8 5 (const) */
        /* execute.simd:297 [D] s_b_64_0[s_b_64_1] */
        auto s_b_64_2 = emitter.vector_extract(s_b_64_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:297 [D] s_b_64_3: sym_40416_0_min = s_b_64_2, dominates: s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40416_0_min, s_b_64_2);
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
        /* execute.simd:296 [D] s_b_65_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_65_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_65_1 = constant u8 6 (const) */
        /* execute.simd:296 [D] s_b_65_0[s_b_65_1] */
        auto s_b_65_2 = emitter.vector_extract(s_b_65_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:296 [D] s_b_65_3 = sym_40416_0_min uint16_t */
        auto s_b_65_3 = emitter.load_local(DV_sym_40416_0_min, emitter.context().types().u16());
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
        /* execute.simd:297 [D] s_b_66_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_66_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_66_1 = constant u8 6 (const) */
        /* execute.simd:297 [D] s_b_66_0[s_b_66_1] */
        auto s_b_66_2 = emitter.vector_extract(s_b_66_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:297 [D] s_b_66_3: sym_40416_0_min = s_b_66_2, dominates: s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_40416_0_min, s_b_66_2);
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
        /* execute.simd:296 [D] s_b_67_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_67_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_67_1 = constant u8 7 (const) */
        /* execute.simd:296 [D] s_b_67_0[s_b_67_1] */
        auto s_b_67_2 = emitter.vector_extract(s_b_67_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:296 [D] s_b_67_3 = sym_40416_0_min uint16_t */
        auto s_b_67_3 = emitter.load_local(DV_sym_40416_0_min, emitter.context().types().u16());
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
        /* execute.simd:297 [D] s_b_68_0 = sym_40411_0_rn wutils::Vector<uint16_t, 8> */
        auto s_b_68_0 = emitter.load_local(DV_sym_40411_0_rn, emitter.context().types().v8u16());
        /* ???:4294967295 [F] s_b_68_1 = constant u8 7 (const) */
        /* execute.simd:297 [D] s_b_68_0[s_b_68_1] */
        auto s_b_68_2 = emitter.vector_extract(s_b_68_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:297 [D] s_b_68_3: sym_40416_0_min = s_b_68_2, dominates: s_b_69_1  */
        emitter.store_local(DV_sym_40416_0_min, s_b_68_2);
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
        /* execute.simd:301 [F] s_b_69_0=sym_39924_3_parameter_inst.rd (const) */
        /* execute.simd:301 [D] s_b_69_1 = sym_40416_0_min uint16_t */
        auto s_b_69_1 = emitter.load_local(DV_sym_40416_0_min, emitter.context().types().u16());
        /* execute.simd:6194 [D] s_b_69_2 = (u64)s_b_69_1 */
        auto s_b_69_2 = emitter.zx(s_b_69_1, emitter.context().types().u64());
        /* execute.simd:6194 [D] s_b_69_3: WriteRegBank 2:s_b_69_0 = s_b_69_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_69_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_69_2);
        /* execute.simd:6195 [F] s_b_69_4 = constant u64 0 (const) */
        /* execute.simd:6195 [F] s_b_69_5: WriteRegBank 3:s_b_69_0 = s_b_69_4 */
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
        /* execute.simd:310 [D] s_b_71_0 = sym_40548_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_71_0 = emitter.load_local(DV_sym_40548_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_71_1 = constant u8 1 (const) */
        /* execute.simd:310 [D] s_b_71_0[s_b_71_1] */
        auto s_b_71_2 = emitter.vector_extract(s_b_71_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:310 [D] s_b_71_3: sym_40553_0_min = s_b_71_2, dominates: s_b_72_3 s_b_74_3 s_b_76_1  */
        emitter.store_local(DV_sym_40553_0_min, s_b_71_2);
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
        /* execute.simd:309 [D] s_b_72_0 = sym_40548_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_72_0 = emitter.load_local(DV_sym_40548_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_72_1 = constant u8 2 (const) */
        /* execute.simd:309 [D] s_b_72_0[s_b_72_1] */
        auto s_b_72_2 = emitter.vector_extract(s_b_72_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:309 [D] s_b_72_3 = sym_40553_0_min uint32_t */
        auto s_b_72_3 = emitter.load_local(DV_sym_40553_0_min, emitter.context().types().u32());
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
        /* execute.simd:310 [D] s_b_73_0 = sym_40548_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_73_0 = emitter.load_local(DV_sym_40548_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_73_1 = constant u8 2 (const) */
        /* execute.simd:310 [D] s_b_73_0[s_b_73_1] */
        auto s_b_73_2 = emitter.vector_extract(s_b_73_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:310 [D] s_b_73_3: sym_40553_0_min = s_b_73_2, dominates: s_b_74_3 s_b_76_1  */
        emitter.store_local(DV_sym_40553_0_min, s_b_73_2);
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
        /* execute.simd:309 [D] s_b_74_0 = sym_40548_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_74_0 = emitter.load_local(DV_sym_40548_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_74_1 = constant u8 3 (const) */
        /* execute.simd:309 [D] s_b_74_0[s_b_74_1] */
        auto s_b_74_2 = emitter.vector_extract(s_b_74_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:309 [D] s_b_74_3 = sym_40553_0_min uint32_t */
        auto s_b_74_3 = emitter.load_local(DV_sym_40553_0_min, emitter.context().types().u32());
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
        /* execute.simd:310 [D] s_b_75_0 = sym_40548_0_rn wutils::Vector<uint32_t, 4> */
        auto s_b_75_0 = emitter.load_local(DV_sym_40548_0_rn, emitter.context().types().v4u32());
        /* ???:4294967295 [F] s_b_75_1 = constant u8 3 (const) */
        /* execute.simd:310 [D] s_b_75_0[s_b_75_1] */
        auto s_b_75_2 = emitter.vector_extract(s_b_75_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:310 [D] s_b_75_3: sym_40553_0_min = s_b_75_2, dominates: s_b_76_1  */
        emitter.store_local(DV_sym_40553_0_min, s_b_75_2);
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
        /* execute.simd:314 [F] s_b_76_0=sym_39924_3_parameter_inst.rd (const) */
        /* execute.simd:314 [D] s_b_76_1 = sym_40553_0_min uint32_t */
        auto s_b_76_1 = emitter.load_local(DV_sym_40553_0_min, emitter.context().types().u32());
        /* execute.simd:6201 [D] s_b_76_2 = (u64)s_b_76_1 */
        auto s_b_76_2 = emitter.zx(s_b_76_1, emitter.context().types().u64());
        /* execute.simd:6201 [D] s_b_76_3: WriteRegBank 2:s_b_76_0 = s_b_76_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_76_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_76_2);
        /* execute.simd:6202 [F] s_b_76_4 = constant u64 0 (const) */
        /* execute.simd:6202 [F] s_b_76_5: WriteRegBank 3:s_b_76_0 = s_b_76_4 */
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
    /* execute.simd:5824 [F] s_b_0_0=sym_44825_3_parameter_inst.tb (const) */
    /* execute.simd:5825 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5837 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5849 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5861 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5873 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5885 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5824 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5826 [F] s_b_2_0=sym_44825_3_parameter_inst.rn (const) */
    /* execute.simd:5826 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5826 [D] s_b_2_2 = (v8u8)s_b_2_1 */
    auto s_b_2_2 = (captive::arch::dbt::el::Value *)s_b_2_1;
    /* execute.simd:5827 [F] s_b_2_3=sym_44825_3_parameter_inst.rm (const) */
    /* execute.simd:5827 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5827 [D] s_b_2_5 = (v8u8)s_b_2_4 */
    auto s_b_2_5 = (captive::arch::dbt::el::Value *)s_b_2_4;
    /* ???:4294967295 [F] s_b_2_6 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5831 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5831 [D] s_b_2_9 = (u16)s_b_2_8 */
    auto s_b_2_9 = emitter.zx(s_b_2_8, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5831 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5831 [D] s_b_2_12 = (u16)s_b_2_11 */
    auto s_b_2_12 = emitter.zx(s_b_2_11, emitter.context().types().u16());
    /* execute.simd:5831 [D] s_b_2_13 = s_b_2_9-s_b_2_12 */
    auto s_b_2_13 = emitter.sub(s_b_2_9, s_b_2_12);
    /* execute.simd:5831 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5831 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5831 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5831 [D] s_b_2_18 = (u16)s_b_2_17 */
    auto s_b_2_18 = emitter.zx(s_b_2_17, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5831 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5831 [D] s_b_2_21 = (u16)s_b_2_20 */
    auto s_b_2_21 = emitter.zx(s_b_2_20, emitter.context().types().u16());
    /* execute.simd:5831 [D] s_b_2_22 = s_b_2_18-s_b_2_21 */
    auto s_b_2_22 = emitter.sub(s_b_2_18, s_b_2_21);
    /* execute.simd:5831 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5831 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5831 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5831 [D] s_b_2_27 = (u16)s_b_2_26 */
    auto s_b_2_27 = emitter.zx(s_b_2_26, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5831 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5831 [D] s_b_2_30 = (u16)s_b_2_29 */
    auto s_b_2_30 = emitter.zx(s_b_2_29, emitter.context().types().u16());
    /* execute.simd:5831 [D] s_b_2_31 = s_b_2_27-s_b_2_30 */
    auto s_b_2_31 = emitter.sub(s_b_2_27, s_b_2_30);
    /* execute.simd:5831 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5831 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5831 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5831 [D] s_b_2_36 = (u16)s_b_2_35 */
    auto s_b_2_36 = emitter.zx(s_b_2_35, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5831 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5831 [D] s_b_2_39 = (u16)s_b_2_38 */
    auto s_b_2_39 = emitter.zx(s_b_2_38, emitter.context().types().u16());
    /* execute.simd:5831 [D] s_b_2_40 = s_b_2_36-s_b_2_39 */
    auto s_b_2_40 = emitter.sub(s_b_2_36, s_b_2_39);
    /* execute.simd:5831 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5831 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5831 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5831 [D] s_b_2_45 = (u16)s_b_2_44 */
    auto s_b_2_45 = emitter.zx(s_b_2_44, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5831 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5831 [D] s_b_2_48 = (u16)s_b_2_47 */
    auto s_b_2_48 = emitter.zx(s_b_2_47, emitter.context().types().u16());
    /* execute.simd:5831 [D] s_b_2_49 = s_b_2_45-s_b_2_48 */
    auto s_b_2_49 = emitter.sub(s_b_2_45, s_b_2_48);
    /* execute.simd:5831 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5831 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5831 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5831 [D] s_b_2_54 = (u16)s_b_2_53 */
    auto s_b_2_54 = emitter.zx(s_b_2_53, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5831 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5831 [D] s_b_2_57 = (u16)s_b_2_56 */
    auto s_b_2_57 = emitter.zx(s_b_2_56, emitter.context().types().u16());
    /* execute.simd:5831 [D] s_b_2_58 = s_b_2_54-s_b_2_57 */
    auto s_b_2_58 = emitter.sub(s_b_2_54, s_b_2_57);
    /* execute.simd:5831 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5831 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5831 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5831 [D] s_b_2_63 = (u16)s_b_2_62 */
    auto s_b_2_63 = emitter.zx(s_b_2_62, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5831 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5831 [D] s_b_2_66 = (u16)s_b_2_65 */
    auto s_b_2_66 = emitter.zx(s_b_2_65, emitter.context().types().u16());
    /* execute.simd:5831 [D] s_b_2_67 = s_b_2_63-s_b_2_66 */
    auto s_b_2_67 = emitter.sub(s_b_2_63, s_b_2_66);
    /* execute.simd:5831 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5831 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5831 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5831 [D] s_b_2_72 = (u16)s_b_2_71 */
    auto s_b_2_72 = emitter.zx(s_b_2_71, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5831 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5831 [D] s_b_2_75 = (u16)s_b_2_74 */
    auto s_b_2_75 = emitter.zx(s_b_2_74, emitter.context().types().u16());
    /* execute.simd:5831 [D] s_b_2_76 = s_b_2_72-s_b_2_75 */
    auto s_b_2_76 = emitter.sub(s_b_2_72, s_b_2_75);
    /* execute.simd:5831 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5831 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5834 [F] s_b_2_79=sym_44825_3_parameter_inst.rd (const) */
    /* execute.simd:5834 [D] s_b_2_80: WriteRegBank 18:s_b_2_79 = s_b_2_78 */
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
    /* execute.simd:5838 [F] s_b_3_0=sym_44825_3_parameter_inst.rn (const) */
    /* execute.simd:5838 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5838 [D] s_b_3_2 = (v16u8)s_b_3_1 */
    auto s_b_3_2 = (captive::arch::dbt::el::Value *)s_b_3_1;
    /* execute.simd:5839 [F] s_b_3_3=sym_44825_3_parameter_inst.rm (const) */
    /* execute.simd:5839 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5839 [D] s_b_3_5 = (v16u8)s_b_3_4 */
    auto s_b_3_5 = (captive::arch::dbt::el::Value *)s_b_3_4;
    /* ???:4294967295 [F] s_b_3_6 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5843 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5843 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5843 [D] s_b_3_9 = (u16)s_b_3_8 */
    auto s_b_3_9 = emitter.zx(s_b_3_8, emitter.context().types().u16());
    /* execute.simd:5843 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5843 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5843 [D] s_b_3_12 = (u16)s_b_3_11 */
    auto s_b_3_12 = emitter.zx(s_b_3_11, emitter.context().types().u16());
    /* execute.simd:5843 [D] s_b_3_13 = s_b_3_9-s_b_3_12 */
    auto s_b_3_13 = emitter.sub(s_b_3_9, s_b_3_12);
    /* execute.simd:5843 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5843 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5843 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5843 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5843 [D] s_b_3_18 = (u16)s_b_3_17 */
    auto s_b_3_18 = emitter.zx(s_b_3_17, emitter.context().types().u16());
    /* execute.simd:5843 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5843 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5843 [D] s_b_3_21 = (u16)s_b_3_20 */
    auto s_b_3_21 = emitter.zx(s_b_3_20, emitter.context().types().u16());
    /* execute.simd:5843 [D] s_b_3_22 = s_b_3_18-s_b_3_21 */
    auto s_b_3_22 = emitter.sub(s_b_3_18, s_b_3_21);
    /* execute.simd:5843 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5843 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5843 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5843 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5843 [D] s_b_3_27 = (u16)s_b_3_26 */
    auto s_b_3_27 = emitter.zx(s_b_3_26, emitter.context().types().u16());
    /* execute.simd:5843 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5843 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5843 [D] s_b_3_30 = (u16)s_b_3_29 */
    auto s_b_3_30 = emitter.zx(s_b_3_29, emitter.context().types().u16());
    /* execute.simd:5843 [D] s_b_3_31 = s_b_3_27-s_b_3_30 */
    auto s_b_3_31 = emitter.sub(s_b_3_27, s_b_3_30);
    /* execute.simd:5843 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5843 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5843 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5843 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5843 [D] s_b_3_36 = (u16)s_b_3_35 */
    auto s_b_3_36 = emitter.zx(s_b_3_35, emitter.context().types().u16());
    /* execute.simd:5843 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5843 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5843 [D] s_b_3_39 = (u16)s_b_3_38 */
    auto s_b_3_39 = emitter.zx(s_b_3_38, emitter.context().types().u16());
    /* execute.simd:5843 [D] s_b_3_40 = s_b_3_36-s_b_3_39 */
    auto s_b_3_40 = emitter.sub(s_b_3_36, s_b_3_39);
    /* execute.simd:5843 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5843 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5843 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5843 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5843 [D] s_b_3_45 = (u16)s_b_3_44 */
    auto s_b_3_45 = emitter.zx(s_b_3_44, emitter.context().types().u16());
    /* execute.simd:5843 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5843 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5843 [D] s_b_3_48 = (u16)s_b_3_47 */
    auto s_b_3_48 = emitter.zx(s_b_3_47, emitter.context().types().u16());
    /* execute.simd:5843 [D] s_b_3_49 = s_b_3_45-s_b_3_48 */
    auto s_b_3_49 = emitter.sub(s_b_3_45, s_b_3_48);
    /* execute.simd:5843 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5843 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5843 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5843 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5843 [D] s_b_3_54 = (u16)s_b_3_53 */
    auto s_b_3_54 = emitter.zx(s_b_3_53, emitter.context().types().u16());
    /* execute.simd:5843 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5843 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5843 [D] s_b_3_57 = (u16)s_b_3_56 */
    auto s_b_3_57 = emitter.zx(s_b_3_56, emitter.context().types().u16());
    /* execute.simd:5843 [D] s_b_3_58 = s_b_3_54-s_b_3_57 */
    auto s_b_3_58 = emitter.sub(s_b_3_54, s_b_3_57);
    /* execute.simd:5843 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5843 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5843 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5843 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5843 [D] s_b_3_63 = (u16)s_b_3_62 */
    auto s_b_3_63 = emitter.zx(s_b_3_62, emitter.context().types().u16());
    /* execute.simd:5843 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5843 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5843 [D] s_b_3_66 = (u16)s_b_3_65 */
    auto s_b_3_66 = emitter.zx(s_b_3_65, emitter.context().types().u16());
    /* execute.simd:5843 [D] s_b_3_67 = s_b_3_63-s_b_3_66 */
    auto s_b_3_67 = emitter.sub(s_b_3_63, s_b_3_66);
    /* execute.simd:5843 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5843 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5843 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5843 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5843 [D] s_b_3_72 = (u16)s_b_3_71 */
    auto s_b_3_72 = emitter.zx(s_b_3_71, emitter.context().types().u16());
    /* execute.simd:5843 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5843 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5843 [D] s_b_3_75 = (u16)s_b_3_74 */
    auto s_b_3_75 = emitter.zx(s_b_3_74, emitter.context().types().u16());
    /* execute.simd:5843 [D] s_b_3_76 = s_b_3_72-s_b_3_75 */
    auto s_b_3_76 = emitter.sub(s_b_3_72, s_b_3_75);
    /* execute.simd:5843 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5843 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5846 [F] s_b_3_79=sym_44825_3_parameter_inst.rd (const) */
    /* execute.simd:5846 [D] s_b_3_80: WriteRegBank 18:s_b_3_79 = s_b_3_78 */
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
    /* execute.simd:5850 [F] s_b_4_0=sym_44825_3_parameter_inst.rn (const) */
    /* execute.simd:5850 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5850 [D] s_b_4_2 = (v4u16)s_b_4_1 */
    auto s_b_4_2 = (captive::arch::dbt::el::Value *)s_b_4_1;
    /* execute.simd:5851 [F] s_b_4_3=sym_44825_3_parameter_inst.rm (const) */
    /* execute.simd:5851 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5851 [D] s_b_4_5 = (v4u16)s_b_4_4 */
    auto s_b_4_5 = (captive::arch::dbt::el::Value *)s_b_4_4;
    /* ???:4294967295 [F] s_b_4_6 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5855 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5855 [D] s_b_4_9 = (u32)s_b_4_8 */
    auto s_b_4_9 = emitter.zx(s_b_4_8, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5855 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5855 [D] s_b_4_12 = (u32)s_b_4_11 */
    auto s_b_4_12 = emitter.zx(s_b_4_11, emitter.context().types().u32());
    /* execute.simd:5855 [D] s_b_4_13 = s_b_4_9-s_b_4_12 */
    auto s_b_4_13 = emitter.sub(s_b_4_9, s_b_4_12);
    /* execute.simd:5855 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5855 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5855 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5855 [D] s_b_4_18 = (u32)s_b_4_17 */
    auto s_b_4_18 = emitter.zx(s_b_4_17, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5855 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5855 [D] s_b_4_21 = (u32)s_b_4_20 */
    auto s_b_4_21 = emitter.zx(s_b_4_20, emitter.context().types().u32());
    /* execute.simd:5855 [D] s_b_4_22 = s_b_4_18-s_b_4_21 */
    auto s_b_4_22 = emitter.sub(s_b_4_18, s_b_4_21);
    /* execute.simd:5855 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5855 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5855 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5855 [D] s_b_4_27 = (u32)s_b_4_26 */
    auto s_b_4_27 = emitter.zx(s_b_4_26, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5855 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5855 [D] s_b_4_30 = (u32)s_b_4_29 */
    auto s_b_4_30 = emitter.zx(s_b_4_29, emitter.context().types().u32());
    /* execute.simd:5855 [D] s_b_4_31 = s_b_4_27-s_b_4_30 */
    auto s_b_4_31 = emitter.sub(s_b_4_27, s_b_4_30);
    /* execute.simd:5855 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5855 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5855 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5855 [D] s_b_4_36 = (u32)s_b_4_35 */
    auto s_b_4_36 = emitter.zx(s_b_4_35, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5855 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5855 [D] s_b_4_39 = (u32)s_b_4_38 */
    auto s_b_4_39 = emitter.zx(s_b_4_38, emitter.context().types().u32());
    /* execute.simd:5855 [D] s_b_4_40 = s_b_4_36-s_b_4_39 */
    auto s_b_4_40 = emitter.sub(s_b_4_36, s_b_4_39);
    /* execute.simd:5855 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5855 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5858 [F] s_b_4_43=sym_44825_3_parameter_inst.rd (const) */
    /* execute.simd:5858 [D] s_b_4_44: WriteRegBank 20:s_b_4_43 = s_b_4_42 */
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
    /* execute.simd:5862 [F] s_b_5_0=sym_44825_3_parameter_inst.rn (const) */
    /* execute.simd:5862 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5862 [D] s_b_5_2 = (v8u16)s_b_5_1 */
    auto s_b_5_2 = (captive::arch::dbt::el::Value *)s_b_5_1;
    /* execute.simd:5863 [F] s_b_5_3=sym_44825_3_parameter_inst.rm (const) */
    /* execute.simd:5863 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5863 [D] s_b_5_5 = (v8u16)s_b_5_4 */
    auto s_b_5_5 = (captive::arch::dbt::el::Value *)s_b_5_4;
    /* ???:4294967295 [F] s_b_5_6 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5867 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5867 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5867 [D] s_b_5_9 = (u32)s_b_5_8 */
    auto s_b_5_9 = emitter.zx(s_b_5_8, emitter.context().types().u32());
    /* execute.simd:5867 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5867 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5867 [D] s_b_5_12 = (u32)s_b_5_11 */
    auto s_b_5_12 = emitter.zx(s_b_5_11, emitter.context().types().u32());
    /* execute.simd:5867 [D] s_b_5_13 = s_b_5_9-s_b_5_12 */
    auto s_b_5_13 = emitter.sub(s_b_5_9, s_b_5_12);
    /* execute.simd:5867 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5867 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5867 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5867 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5867 [D] s_b_5_18 = (u32)s_b_5_17 */
    auto s_b_5_18 = emitter.zx(s_b_5_17, emitter.context().types().u32());
    /* execute.simd:5867 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5867 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5867 [D] s_b_5_21 = (u32)s_b_5_20 */
    auto s_b_5_21 = emitter.zx(s_b_5_20, emitter.context().types().u32());
    /* execute.simd:5867 [D] s_b_5_22 = s_b_5_18-s_b_5_21 */
    auto s_b_5_22 = emitter.sub(s_b_5_18, s_b_5_21);
    /* execute.simd:5867 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5867 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5867 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5867 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5867 [D] s_b_5_27 = (u32)s_b_5_26 */
    auto s_b_5_27 = emitter.zx(s_b_5_26, emitter.context().types().u32());
    /* execute.simd:5867 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5867 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5867 [D] s_b_5_30 = (u32)s_b_5_29 */
    auto s_b_5_30 = emitter.zx(s_b_5_29, emitter.context().types().u32());
    /* execute.simd:5867 [D] s_b_5_31 = s_b_5_27-s_b_5_30 */
    auto s_b_5_31 = emitter.sub(s_b_5_27, s_b_5_30);
    /* execute.simd:5867 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5867 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5867 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5867 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5867 [D] s_b_5_36 = (u32)s_b_5_35 */
    auto s_b_5_36 = emitter.zx(s_b_5_35, emitter.context().types().u32());
    /* execute.simd:5867 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5867 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5867 [D] s_b_5_39 = (u32)s_b_5_38 */
    auto s_b_5_39 = emitter.zx(s_b_5_38, emitter.context().types().u32());
    /* execute.simd:5867 [D] s_b_5_40 = s_b_5_36-s_b_5_39 */
    auto s_b_5_40 = emitter.sub(s_b_5_36, s_b_5_39);
    /* execute.simd:5867 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5867 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5870 [F] s_b_5_43=sym_44825_3_parameter_inst.rd (const) */
    /* execute.simd:5870 [D] s_b_5_44: WriteRegBank 20:s_b_5_43 = s_b_5_42 */
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
    /* execute.simd:5874 [F] s_b_6_0=sym_44825_3_parameter_inst.rn (const) */
    /* execute.simd:5874 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5874 [D] s_b_6_2 = (v2u32)s_b_6_1 */
    auto s_b_6_2 = (captive::arch::dbt::el::Value *)s_b_6_1;
    /* execute.simd:5875 [F] s_b_6_3=sym_44825_3_parameter_inst.rm (const) */
    /* execute.simd:5875 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5875 [D] s_b_6_5 = (v2u32)s_b_6_4 */
    auto s_b_6_5 = (captive::arch::dbt::el::Value *)s_b_6_4;
    /* ???:4294967295 [F] s_b_6_6 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5879 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5879 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5879 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5879 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.simd:5879 [D] s_b_6_13 = s_b_6_9-s_b_6_12 */
    auto s_b_6_13 = emitter.sub(s_b_6_9, s_b_6_12);
    /* execute.simd:5879 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5879 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5879 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5879 [D] s_b_6_18 = (u64)s_b_6_17 */
    auto s_b_6_18 = emitter.zx(s_b_6_17, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5879 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5879 [D] s_b_6_21 = (u64)s_b_6_20 */
    auto s_b_6_21 = emitter.zx(s_b_6_20, emitter.context().types().u64());
    /* execute.simd:5879 [D] s_b_6_22 = s_b_6_18-s_b_6_21 */
    auto s_b_6_22 = emitter.sub(s_b_6_18, s_b_6_21);
    /* execute.simd:5879 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5879 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:5882 [F] s_b_6_25=sym_44825_3_parameter_inst.rd (const) */
    /* execute.simd:5882 [D] s_b_6_26: WriteRegBank 21:s_b_6_25 = s_b_6_24 */
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
    /* execute.simd:5886 [F] s_b_7_0=sym_44825_3_parameter_inst.rn (const) */
    /* execute.simd:5886 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5886 [D] s_b_7_2 = (v4u32)s_b_7_1 */
    auto s_b_7_2 = (captive::arch::dbt::el::Value *)s_b_7_1;
    /* execute.simd:5887 [F] s_b_7_3=sym_44825_3_parameter_inst.rm (const) */
    /* execute.simd:5887 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5887 [D] s_b_7_5 = (v4u32)s_b_7_4 */
    auto s_b_7_5 = (captive::arch::dbt::el::Value *)s_b_7_4;
    /* ???:4294967295 [F] s_b_7_6 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5891 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:5891 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5891 [D] s_b_7_9 = (u64)s_b_7_8 */
    auto s_b_7_9 = emitter.zx(s_b_7_8, emitter.context().types().u64());
    /* execute.simd:5891 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:5891 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5891 [D] s_b_7_12 = (u64)s_b_7_11 */
    auto s_b_7_12 = emitter.zx(s_b_7_11, emitter.context().types().u64());
    /* execute.simd:5891 [D] s_b_7_13 = s_b_7_9-s_b_7_12 */
    auto s_b_7_13 = emitter.sub(s_b_7_9, s_b_7_12);
    /* execute.simd:5891 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:5891 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:5891 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:5891 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5891 [D] s_b_7_18 = (u64)s_b_7_17 */
    auto s_b_7_18 = emitter.zx(s_b_7_17, emitter.context().types().u64());
    /* execute.simd:5891 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:5891 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5891 [D] s_b_7_21 = (u64)s_b_7_20 */
    auto s_b_7_21 = emitter.zx(s_b_7_20, emitter.context().types().u64());
    /* execute.simd:5891 [D] s_b_7_22 = s_b_7_18-s_b_7_21 */
    auto s_b_7_22 = emitter.sub(s_b_7_18, s_b_7_21);
    /* execute.simd:5891 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:5891 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:5894 [F] s_b_7_25=sym_44825_3_parameter_inst.rd (const) */
    /* execute.simd:5894 [D] s_b_7_26: WriteRegBank 21:s_b_7_25 = s_b_7_24 */
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
    /* execute.simd:5898 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5824 [F] s_b_8_1: Jump b_1 (const) */
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
    /* execute.simd:2202 [F] s_b_0_0=sym_47337_3_parameter_inst.arrangement (const) */
    /* execute.simd:2203 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:2220 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:2237 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:2250 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:2263 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:2274 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:2202 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:2204 [F] s_b_2_0=sym_47337_3_parameter_inst.rn (const) */
    /* execute.simd:2204 [D] s_b_2_1 = ReadRegBank 18:s_b_2_0 (v8u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_2_2 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:2207 [F] s_b_2_3 = constant s32 0 (const) */
    /* execute.simd:2207 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2207 [D] s_b_2_5 = (u8)s_b_2_4 */
    auto s_b_2_5 = emitter.truncate(s_b_2_4, emitter.context().types().u8());
    /* execute.simd:2207 [F] s_b_2_6 = constant s32 0 (const) */
    /* execute.simd:2207 [D] s_b_2_7 = s_b_2_2[s_b_2_6] <= s_b_2_5 */
    auto s_b_2_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_2_5);
    /* execute.simd:2208 [F] s_b_2_8 = constant s32 1 (const) */
    /* execute.simd:2208 [D] s_b_2_1[s_b_2_8] */
    auto s_b_2_9 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2208 [D] s_b_2_10 = (u8)s_b_2_9 */
    auto s_b_2_10 = emitter.truncate(s_b_2_9, emitter.context().types().u8());
    /* execute.simd:2208 [F] s_b_2_11 = constant s32 1 (const) */
    /* execute.simd:2208 [D] s_b_2_12 = s_b_2_7[s_b_2_11] <= s_b_2_10 */
    auto s_b_2_12 = emitter.vector_insert(s_b_2_7, emitter.const_s32((int32_t)1ULL), s_b_2_10);
    /* execute.simd:2209 [F] s_b_2_13 = constant s32 2 (const) */
    /* execute.simd:2209 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2209 [D] s_b_2_15 = (u8)s_b_2_14 */
    auto s_b_2_15 = emitter.truncate(s_b_2_14, emitter.context().types().u8());
    /* execute.simd:2209 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:2209 [D] s_b_2_17 = s_b_2_12[s_b_2_16] <= s_b_2_15 */
    auto s_b_2_17 = emitter.vector_insert(s_b_2_12, emitter.const_s32((int32_t)2ULL), s_b_2_15);
    /* execute.simd:2210 [F] s_b_2_18 = constant s32 3 (const) */
    /* execute.simd:2210 [D] s_b_2_1[s_b_2_18] */
    auto s_b_2_19 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2210 [D] s_b_2_20 = (u8)s_b_2_19 */
    auto s_b_2_20 = emitter.truncate(s_b_2_19, emitter.context().types().u8());
    /* execute.simd:2210 [F] s_b_2_21 = constant s32 3 (const) */
    /* execute.simd:2210 [D] s_b_2_22 = s_b_2_17[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_17, emitter.const_s32((int32_t)3ULL), s_b_2_20);
    /* execute.simd:2211 [F] s_b_2_23 = constant s32 4 (const) */
    /* execute.simd:2211 [D] s_b_2_1[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:2211 [D] s_b_2_25 = (u8)s_b_2_24 */
    auto s_b_2_25 = emitter.truncate(s_b_2_24, emitter.context().types().u8());
    /* execute.simd:2211 [F] s_b_2_26 = constant s32 4 (const) */
    /* execute.simd:2211 [D] s_b_2_27 = s_b_2_22[s_b_2_26] <= s_b_2_25 */
    auto s_b_2_27 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)4ULL), s_b_2_25);
    /* execute.simd:2212 [F] s_b_2_28 = constant s32 5 (const) */
    /* execute.simd:2212 [D] s_b_2_1[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:2212 [D] s_b_2_30 = (u8)s_b_2_29 */
    auto s_b_2_30 = emitter.truncate(s_b_2_29, emitter.context().types().u8());
    /* execute.simd:2212 [F] s_b_2_31 = constant s32 5 (const) */
    /* execute.simd:2212 [D] s_b_2_32 = s_b_2_27[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_27, emitter.const_s32((int32_t)5ULL), s_b_2_30);
    /* execute.simd:2213 [F] s_b_2_33 = constant s32 6 (const) */
    /* execute.simd:2213 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:2213 [D] s_b_2_35 = (u8)s_b_2_34 */
    auto s_b_2_35 = emitter.truncate(s_b_2_34, emitter.context().types().u8());
    /* execute.simd:2213 [F] s_b_2_36 = constant s32 6 (const) */
    /* execute.simd:2213 [D] s_b_2_37 = s_b_2_32[s_b_2_36] <= s_b_2_35 */
    auto s_b_2_37 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)6ULL), s_b_2_35);
    /* execute.simd:2214 [F] s_b_2_38 = constant s32 7 (const) */
    /* execute.simd:2214 [D] s_b_2_1[s_b_2_38] */
    auto s_b_2_39 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:2214 [D] s_b_2_40 = (u8)s_b_2_39 */
    auto s_b_2_40 = emitter.truncate(s_b_2_39, emitter.context().types().u8());
    /* execute.simd:2214 [F] s_b_2_41 = constant s32 7 (const) */
    /* execute.simd:2214 [D] s_b_2_42 = s_b_2_37[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_37, emitter.const_s32((int32_t)7ULL), s_b_2_40);
    /* execute.simd:2216 [F] s_b_2_43=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2216 [D] s_b_2_44: WriteRegBank 16:s_b_2_43 = s_b_2_42 */
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
    /* execute.simd:2221 [F] s_b_3_0=sym_47337_3_parameter_inst.rn (const) */
    /* execute.simd:2221 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:2223 [F] s_b_3_2=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2223 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:2224 [F] s_b_3_4 = constant s32 0 (const) */
    /* execute.simd:2224 [D] s_b_3_1[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2224 [D] s_b_3_6 = (u8)s_b_3_5 */
    auto s_b_3_6 = emitter.truncate(s_b_3_5, emitter.context().types().u8());
    /* execute.simd:2224 [F] s_b_3_7 = constant s32 8 (const) */
    /* execute.simd:2224 [D] s_b_3_8 = s_b_3_3[s_b_3_7] <= s_b_3_6 */
    auto s_b_3_8 = emitter.vector_insert(s_b_3_3, emitter.const_s32((int32_t)8ULL), s_b_3_6);
    /* execute.simd:2225 [F] s_b_3_9 = constant s32 1 (const) */
    /* execute.simd:2225 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2225 [D] s_b_3_11 = (u8)s_b_3_10 */
    auto s_b_3_11 = emitter.truncate(s_b_3_10, emitter.context().types().u8());
    /* execute.simd:2225 [F] s_b_3_12 = constant s32 9 (const) */
    /* execute.simd:2225 [D] s_b_3_13 = s_b_3_8[s_b_3_12] <= s_b_3_11 */
    auto s_b_3_13 = emitter.vector_insert(s_b_3_8, emitter.const_s32((int32_t)9ULL), s_b_3_11);
    /* execute.simd:2226 [F] s_b_3_14 = constant s32 2 (const) */
    /* execute.simd:2226 [D] s_b_3_1[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2226 [D] s_b_3_16 = (u8)s_b_3_15 */
    auto s_b_3_16 = emitter.truncate(s_b_3_15, emitter.context().types().u8());
    /* execute.simd:2226 [F] s_b_3_17 = constant s32 a (const) */
    /* execute.simd:2226 [D] s_b_3_18 = s_b_3_13[s_b_3_17] <= s_b_3_16 */
    auto s_b_3_18 = emitter.vector_insert(s_b_3_13, emitter.const_s32((int32_t)10ULL), s_b_3_16);
    /* execute.simd:2227 [F] s_b_3_19 = constant s32 3 (const) */
    /* execute.simd:2227 [D] s_b_3_1[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2227 [D] s_b_3_21 = (u8)s_b_3_20 */
    auto s_b_3_21 = emitter.truncate(s_b_3_20, emitter.context().types().u8());
    /* execute.simd:2227 [F] s_b_3_22 = constant s32 b (const) */
    /* execute.simd:2227 [D] s_b_3_23 = s_b_3_18[s_b_3_22] <= s_b_3_21 */
    auto s_b_3_23 = emitter.vector_insert(s_b_3_18, emitter.const_s32((int32_t)11ULL), s_b_3_21);
    /* execute.simd:2228 [F] s_b_3_24 = constant s32 4 (const) */
    /* execute.simd:2228 [D] s_b_3_1[s_b_3_24] */
    auto s_b_3_25 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:2228 [D] s_b_3_26 = (u8)s_b_3_25 */
    auto s_b_3_26 = emitter.truncate(s_b_3_25, emitter.context().types().u8());
    /* execute.simd:2228 [F] s_b_3_27 = constant s32 c (const) */
    /* execute.simd:2228 [D] s_b_3_28 = s_b_3_23[s_b_3_27] <= s_b_3_26 */
    auto s_b_3_28 = emitter.vector_insert(s_b_3_23, emitter.const_s32((int32_t)12ULL), s_b_3_26);
    /* execute.simd:2229 [F] s_b_3_29 = constant s32 5 (const) */
    /* execute.simd:2229 [D] s_b_3_1[s_b_3_29] */
    auto s_b_3_30 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:2229 [D] s_b_3_31 = (u8)s_b_3_30 */
    auto s_b_3_31 = emitter.truncate(s_b_3_30, emitter.context().types().u8());
    /* execute.simd:2229 [F] s_b_3_32 = constant s32 d (const) */
    /* execute.simd:2229 [D] s_b_3_33 = s_b_3_28[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_28, emitter.const_s32((int32_t)13ULL), s_b_3_31);
    /* execute.simd:2230 [F] s_b_3_34 = constant s32 6 (const) */
    /* execute.simd:2230 [D] s_b_3_1[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:2230 [D] s_b_3_36 = (u8)s_b_3_35 */
    auto s_b_3_36 = emitter.truncate(s_b_3_35, emitter.context().types().u8());
    /* execute.simd:2230 [F] s_b_3_37 = constant s32 e (const) */
    /* execute.simd:2230 [D] s_b_3_38 = s_b_3_33[s_b_3_37] <= s_b_3_36 */
    auto s_b_3_38 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)14ULL), s_b_3_36);
    /* execute.simd:2231 [F] s_b_3_39 = constant s32 7 (const) */
    /* execute.simd:2231 [D] s_b_3_1[s_b_3_39] */
    auto s_b_3_40 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:2231 [D] s_b_3_41 = (u8)s_b_3_40 */
    auto s_b_3_41 = emitter.truncate(s_b_3_40, emitter.context().types().u8());
    /* execute.simd:2231 [F] s_b_3_42 = constant s32 f (const) */
    /* execute.simd:2231 [D] s_b_3_43 = s_b_3_38[s_b_3_42] <= s_b_3_41 */
    auto s_b_3_43 = emitter.vector_insert(s_b_3_38, emitter.const_s32((int32_t)15ULL), s_b_3_41);
    /* execute.simd:2233 [F] s_b_3_44=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2233 [D] s_b_3_45: WriteRegBank 16:s_b_3_44 = s_b_3_43 */
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
    /* execute.simd:2238 [F] s_b_4_0=sym_47337_3_parameter_inst.rn (const) */
    /* execute.simd:2238 [D] s_b_4_1 = ReadRegBank 20:s_b_4_0 (v4u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_4_2 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:2241 [F] s_b_4_3 = constant s32 0 (const) */
    /* execute.simd:2241 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2241 [D] s_b_4_5 = (u16)s_b_4_4 */
    auto s_b_4_5 = emitter.truncate(s_b_4_4, emitter.context().types().u16());
    /* execute.simd:2241 [F] s_b_4_6 = constant s32 0 (const) */
    /* execute.simd:2241 [D] s_b_4_7 = s_b_4_2[s_b_4_6] <= s_b_4_5 */
    auto s_b_4_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_4_5);
    /* execute.simd:2242 [F] s_b_4_8 = constant s32 1 (const) */
    /* execute.simd:2242 [D] s_b_4_1[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2242 [D] s_b_4_10 = (u16)s_b_4_9 */
    auto s_b_4_10 = emitter.truncate(s_b_4_9, emitter.context().types().u16());
    /* execute.simd:2242 [F] s_b_4_11 = constant s32 1 (const) */
    /* execute.simd:2242 [D] s_b_4_12 = s_b_4_7[s_b_4_11] <= s_b_4_10 */
    auto s_b_4_12 = emitter.vector_insert(s_b_4_7, emitter.const_s32((int32_t)1ULL), s_b_4_10);
    /* execute.simd:2243 [F] s_b_4_13 = constant s32 2 (const) */
    /* execute.simd:2243 [D] s_b_4_1[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2243 [D] s_b_4_15 = (u16)s_b_4_14 */
    auto s_b_4_15 = emitter.truncate(s_b_4_14, emitter.context().types().u16());
    /* execute.simd:2243 [F] s_b_4_16 = constant s32 2 (const) */
    /* execute.simd:2243 [D] s_b_4_17 = s_b_4_12[s_b_4_16] <= s_b_4_15 */
    auto s_b_4_17 = emitter.vector_insert(s_b_4_12, emitter.const_s32((int32_t)2ULL), s_b_4_15);
    /* execute.simd:2244 [F] s_b_4_18 = constant s32 3 (const) */
    /* execute.simd:2244 [D] s_b_4_1[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2244 [D] s_b_4_20 = (u16)s_b_4_19 */
    auto s_b_4_20 = emitter.truncate(s_b_4_19, emitter.context().types().u16());
    /* execute.simd:2244 [F] s_b_4_21 = constant s32 3 (const) */
    /* execute.simd:2244 [D] s_b_4_22 = s_b_4_17[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_17, emitter.const_s32((int32_t)3ULL), s_b_4_20);
    /* execute.simd:2246 [F] s_b_4_23=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2246 [D] s_b_4_24: WriteRegBank 18:s_b_4_23 = s_b_4_22 */
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
    /* execute.simd:2251 [F] s_b_5_0=sym_47337_3_parameter_inst.rn (const) */
    /* execute.simd:2251 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:2253 [F] s_b_5_2=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2253 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:2254 [F] s_b_5_4 = constant s32 0 (const) */
    /* execute.simd:2254 [D] s_b_5_1[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2254 [D] s_b_5_6 = (u16)s_b_5_5 */
    auto s_b_5_6 = emitter.truncate(s_b_5_5, emitter.context().types().u16());
    /* execute.simd:2254 [F] s_b_5_7 = constant s32 4 (const) */
    /* execute.simd:2254 [D] s_b_5_8 = s_b_5_3[s_b_5_7] <= s_b_5_6 */
    auto s_b_5_8 = emitter.vector_insert(s_b_5_3, emitter.const_s32((int32_t)4ULL), s_b_5_6);
    /* execute.simd:2255 [F] s_b_5_9 = constant s32 1 (const) */
    /* execute.simd:2255 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2255 [D] s_b_5_11 = (u16)s_b_5_10 */
    auto s_b_5_11 = emitter.truncate(s_b_5_10, emitter.context().types().u16());
    /* execute.simd:2255 [F] s_b_5_12 = constant s32 5 (const) */
    /* execute.simd:2255 [D] s_b_5_13 = s_b_5_8[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(s_b_5_8, emitter.const_s32((int32_t)5ULL), s_b_5_11);
    /* execute.simd:2256 [F] s_b_5_14 = constant s32 2 (const) */
    /* execute.simd:2256 [D] s_b_5_1[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2256 [D] s_b_5_16 = (u16)s_b_5_15 */
    auto s_b_5_16 = emitter.truncate(s_b_5_15, emitter.context().types().u16());
    /* execute.simd:2256 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:2256 [D] s_b_5_18 = s_b_5_13[s_b_5_17] <= s_b_5_16 */
    auto s_b_5_18 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)6ULL), s_b_5_16);
    /* execute.simd:2257 [F] s_b_5_19 = constant s32 3 (const) */
    /* execute.simd:2257 [D] s_b_5_1[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2257 [D] s_b_5_21 = (u16)s_b_5_20 */
    auto s_b_5_21 = emitter.truncate(s_b_5_20, emitter.context().types().u16());
    /* execute.simd:2257 [F] s_b_5_22 = constant s32 7 (const) */
    /* execute.simd:2257 [D] s_b_5_23 = s_b_5_18[s_b_5_22] <= s_b_5_21 */
    auto s_b_5_23 = emitter.vector_insert(s_b_5_18, emitter.const_s32((int32_t)7ULL), s_b_5_21);
    /* execute.simd:2259 [F] s_b_5_24=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2259 [D] s_b_5_25: WriteRegBank 18:s_b_5_24 = s_b_5_23 */
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
    /* execute.simd:2264 [F] s_b_6_0=sym_47337_3_parameter_inst.rn (const) */
    /* execute.simd:2264 [D] s_b_6_1 = ReadRegBank 21:s_b_6_0 (v2u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:2267 [F] s_b_6_3 = constant s32 0 (const) */
    /* execute.simd:2267 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2267 [D] s_b_6_5 = (u32)s_b_6_4 */
    auto s_b_6_5 = emitter.truncate(s_b_6_4, emitter.context().types().u32());
    /* execute.simd:2267 [F] s_b_6_6 = constant s32 0 (const) */
    /* execute.simd:2267 [D] s_b_6_7 = s_b_6_2[s_b_6_6] <= s_b_6_5 */
    auto s_b_6_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_6_5);
    /* execute.simd:2268 [F] s_b_6_8 = constant s32 1 (const) */
    /* execute.simd:2268 [D] s_b_6_1[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2268 [D] s_b_6_10 = (u32)s_b_6_9 */
    auto s_b_6_10 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.simd:2268 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:2268 [D] s_b_6_12 = s_b_6_7[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_7, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:2270 [F] s_b_6_13=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2270 [D] s_b_6_14: WriteRegBank 20:s_b_6_13 = s_b_6_12 */
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
    /* execute.simd:2275 [F] s_b_7_0=sym_47337_3_parameter_inst.rn (const) */
    /* execute.simd:2275 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:2277 [F] s_b_7_2=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2277 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:2278 [F] s_b_7_4 = constant s32 0 (const) */
    /* execute.simd:2278 [D] s_b_7_1[s_b_7_4] */
    auto s_b_7_5 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2278 [D] s_b_7_6 = (u32)s_b_7_5 */
    auto s_b_7_6 = emitter.truncate(s_b_7_5, emitter.context().types().u32());
    /* execute.simd:2278 [F] s_b_7_7 = constant s32 2 (const) */
    /* execute.simd:2278 [D] s_b_7_8 = s_b_7_3[s_b_7_7] <= s_b_7_6 */
    auto s_b_7_8 = emitter.vector_insert(s_b_7_3, emitter.const_s32((int32_t)2ULL), s_b_7_6);
    /* execute.simd:2279 [F] s_b_7_9 = constant s32 1 (const) */
    /* execute.simd:2279 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2279 [D] s_b_7_11 = (u32)s_b_7_10 */
    auto s_b_7_11 = emitter.truncate(s_b_7_10, emitter.context().types().u32());
    /* execute.simd:2279 [F] s_b_7_12 = constant s32 3 (const) */
    /* execute.simd:2279 [D] s_b_7_13 = s_b_7_8[s_b_7_12] <= s_b_7_11 */
    auto s_b_7_13 = emitter.vector_insert(s_b_7_8, emitter.const_s32((int32_t)3ULL), s_b_7_11);
    /* execute.simd:2281 [F] s_b_7_14=sym_47337_3_parameter_inst.rd (const) */
    /* execute.simd:2281 [D] s_b_7_15: WriteRegBank 20:s_b_7_14 = s_b_7_13 */
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
    /* execute.simd:2286 [D] s_b_8_0 = trap */
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
