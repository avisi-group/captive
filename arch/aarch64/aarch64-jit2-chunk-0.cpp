#include <aarch64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::aarch64;
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_abs_simd(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3473 [F] s_b_0_0=sym_2511_3_parameter_inst.SCALAR (const) */
    /* execute.simd:3473 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3474 [F] s_b_1_0=sym_2511_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:3474 [D] s_b_1_2 = (s64)s_b_1_1 */
    auto s_b_1_2 = emitter.reinterpret(s_b_1_1, emitter.context().types().s64());
    /* execute.simd:3475 [F] s_b_1_3=sym_2511_3_parameter_inst.rd (const) */
    /* execute.simd:3475 [D] s_b_1_4 = __builtin_abs64 */
    auto s_b_1_4 = emitter.call(__captive___builtin_abs64, s_b_1_2);
    /* execute.simd:6138 [D] s_b_1_5: WriteRegBank 2:s_b_1_3 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4);
    /* execute.simd:6139 [F] s_b_1_6 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_1_7: WriteRegBank 3:s_b_1_3 = s_b_1_6 */
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
    /* execute.simd:3477 [F] s_b_3_0=sym_2511_3_parameter_inst.arrangement (const) */
    /* execute.simd:3478 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:3489 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:3500 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:3511 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:3522 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:3533 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:3544 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:3477 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_11 (const) -> b_11, b_10, b_9, b_8, b_7, b_6, b_5, b_4,  */
    switch (insn.arrangement) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_4;
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
    /* execute.simd:3479 [F] s_b_4_0=sym_2511_3_parameter_inst.rn (const) */
    /* execute.simd:3479 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:3479 [D] s_b_4_2 = (v8s8)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_4_3 = constant v16u8 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_4 = constant u8 0 (const) */
    /* execute.simd:3483 [D] s_b_4_2[s_b_4_4] */
    auto s_b_4_5 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3483 [D] s_b_4_6 = (s32)s_b_4_5 */
    auto s_b_4_6 = emitter.sx(s_b_4_5, emitter.context().types().s32());
    /* execute.simd:3483 [D] s_b_4_7 = __builtin_abs32 */
    auto s_b_4_7 = emitter.call(__captive___builtin_abs32, s_b_4_6);
    /* execute.simd:3483 [D] s_b_4_8 = (u8)s_b_4_7 */
    auto s_b_4_8 = emitter.truncate(s_b_4_7, emitter.context().types().u8());
    /* execute.simd:3483 [F] s_b_4_9 = constant s32 0 (const) */
    /* execute.simd:3483 [D] s_b_4_10 = s_b_4_3[s_b_4_9] <= s_b_4_8 */
    auto s_b_4_10 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_4_8);
    /* ???:4294967295 [F] s_b_4_11 = constant u8 1 (const) */
    /* execute.simd:3483 [D] s_b_4_2[s_b_4_11] */
    auto s_b_4_12 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3483 [D] s_b_4_13 = (s32)s_b_4_12 */
    auto s_b_4_13 = emitter.sx(s_b_4_12, emitter.context().types().s32());
    /* execute.simd:3483 [D] s_b_4_14 = __builtin_abs32 */
    auto s_b_4_14 = emitter.call(__captive___builtin_abs32, s_b_4_13);
    /* execute.simd:3483 [D] s_b_4_15 = (u8)s_b_4_14 */
    auto s_b_4_15 = emitter.truncate(s_b_4_14, emitter.context().types().u8());
    /* execute.simd:3483 [F] s_b_4_16 = constant s32 1 (const) */
    /* execute.simd:3483 [D] s_b_4_17 = s_b_4_10[s_b_4_16] <= s_b_4_15 */
    auto s_b_4_17 = emitter.vector_insert(s_b_4_10, emitter.const_s32((int32_t)1ULL), s_b_4_15);
    /* ???:4294967295 [F] s_b_4_18 = constant u8 2 (const) */
    /* execute.simd:3483 [D] s_b_4_2[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3483 [D] s_b_4_20 = (s32)s_b_4_19 */
    auto s_b_4_20 = emitter.sx(s_b_4_19, emitter.context().types().s32());
    /* execute.simd:3483 [D] s_b_4_21 = __builtin_abs32 */
    auto s_b_4_21 = emitter.call(__captive___builtin_abs32, s_b_4_20);
    /* execute.simd:3483 [D] s_b_4_22 = (u8)s_b_4_21 */
    auto s_b_4_22 = emitter.truncate(s_b_4_21, emitter.context().types().u8());
    /* execute.simd:3483 [F] s_b_4_23 = constant s32 2 (const) */
    /* execute.simd:3483 [D] s_b_4_24 = s_b_4_17[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_17, emitter.const_s32((int32_t)2ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 3 (const) */
    /* execute.simd:3483 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3483 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* execute.simd:3483 [D] s_b_4_28 = __builtin_abs32 */
    auto s_b_4_28 = emitter.call(__captive___builtin_abs32, s_b_4_27);
    /* execute.simd:3483 [D] s_b_4_29 = (u8)s_b_4_28 */
    auto s_b_4_29 = emitter.truncate(s_b_4_28, emitter.context().types().u8());
    /* execute.simd:3483 [F] s_b_4_30 = constant s32 3 (const) */
    /* execute.simd:3483 [D] s_b_4_31 = s_b_4_24[s_b_4_30] <= s_b_4_29 */
    auto s_b_4_31 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)3ULL), s_b_4_29);
    /* ???:4294967295 [F] s_b_4_32 = constant u8 4 (const) */
    /* execute.simd:3483 [D] s_b_4_2[s_b_4_32] */
    auto s_b_4_33 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3483 [D] s_b_4_34 = (s32)s_b_4_33 */
    auto s_b_4_34 = emitter.sx(s_b_4_33, emitter.context().types().s32());
    /* execute.simd:3483 [D] s_b_4_35 = __builtin_abs32 */
    auto s_b_4_35 = emitter.call(__captive___builtin_abs32, s_b_4_34);
    /* execute.simd:3483 [D] s_b_4_36 = (u8)s_b_4_35 */
    auto s_b_4_36 = emitter.truncate(s_b_4_35, emitter.context().types().u8());
    /* execute.simd:3483 [F] s_b_4_37 = constant s32 4 (const) */
    /* execute.simd:3483 [D] s_b_4_38 = s_b_4_31[s_b_4_37] <= s_b_4_36 */
    auto s_b_4_38 = emitter.vector_insert(s_b_4_31, emitter.const_s32((int32_t)4ULL), s_b_4_36);
    /* ???:4294967295 [F] s_b_4_39 = constant u8 5 (const) */
    /* execute.simd:3483 [D] s_b_4_2[s_b_4_39] */
    auto s_b_4_40 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3483 [D] s_b_4_41 = (s32)s_b_4_40 */
    auto s_b_4_41 = emitter.sx(s_b_4_40, emitter.context().types().s32());
    /* execute.simd:3483 [D] s_b_4_42 = __builtin_abs32 */
    auto s_b_4_42 = emitter.call(__captive___builtin_abs32, s_b_4_41);
    /* execute.simd:3483 [D] s_b_4_43 = (u8)s_b_4_42 */
    auto s_b_4_43 = emitter.truncate(s_b_4_42, emitter.context().types().u8());
    /* execute.simd:3483 [F] s_b_4_44 = constant s32 5 (const) */
    /* execute.simd:3483 [D] s_b_4_45 = s_b_4_38[s_b_4_44] <= s_b_4_43 */
    auto s_b_4_45 = emitter.vector_insert(s_b_4_38, emitter.const_s32((int32_t)5ULL), s_b_4_43);
    /* ???:4294967295 [F] s_b_4_46 = constant u8 6 (const) */
    /* execute.simd:3483 [D] s_b_4_2[s_b_4_46] */
    auto s_b_4_47 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3483 [D] s_b_4_48 = (s32)s_b_4_47 */
    auto s_b_4_48 = emitter.sx(s_b_4_47, emitter.context().types().s32());
    /* execute.simd:3483 [D] s_b_4_49 = __builtin_abs32 */
    auto s_b_4_49 = emitter.call(__captive___builtin_abs32, s_b_4_48);
    /* execute.simd:3483 [D] s_b_4_50 = (u8)s_b_4_49 */
    auto s_b_4_50 = emitter.truncate(s_b_4_49, emitter.context().types().u8());
    /* execute.simd:3483 [F] s_b_4_51 = constant s32 6 (const) */
    /* execute.simd:3483 [D] s_b_4_52 = s_b_4_45[s_b_4_51] <= s_b_4_50 */
    auto s_b_4_52 = emitter.vector_insert(s_b_4_45, emitter.const_s32((int32_t)6ULL), s_b_4_50);
    /* ???:4294967295 [F] s_b_4_53 = constant u8 7 (const) */
    /* execute.simd:3483 [D] s_b_4_2[s_b_4_53] */
    auto s_b_4_54 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3483 [D] s_b_4_55 = (s32)s_b_4_54 */
    auto s_b_4_55 = emitter.sx(s_b_4_54, emitter.context().types().s32());
    /* execute.simd:3483 [D] s_b_4_56 = __builtin_abs32 */
    auto s_b_4_56 = emitter.call(__captive___builtin_abs32, s_b_4_55);
    /* execute.simd:3483 [D] s_b_4_57 = (u8)s_b_4_56 */
    auto s_b_4_57 = emitter.truncate(s_b_4_56, emitter.context().types().u8());
    /* execute.simd:3483 [F] s_b_4_58 = constant s32 7 (const) */
    /* execute.simd:3483 [D] s_b_4_59 = s_b_4_52[s_b_4_58] <= s_b_4_57 */
    auto s_b_4_59 = emitter.vector_insert(s_b_4_52, emitter.const_s32((int32_t)7ULL), s_b_4_57);
    /* execute.simd:3486 [F] s_b_4_60=sym_2511_3_parameter_inst.rd (const) */
    /* execute.simd:3486 [D] s_b_4_61: WriteRegBank 16:s_b_4_60 = s_b_4_59 */
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
    /* execute.simd:3490 [F] s_b_5_0=sym_2511_3_parameter_inst.rn (const) */
    /* execute.simd:3490 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:3490 [D] s_b_5_2 = (v16s8)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_5_3 = constant v16u8 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_5_4 = constant u8 0 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3494 [D] s_b_5_6 = (s32)s_b_5_5 */
    auto s_b_5_6 = emitter.sx(s_b_5_5, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_7 = __builtin_abs32 */
    auto s_b_5_7 = emitter.call(__captive___builtin_abs32, s_b_5_6);
    /* execute.simd:3494 [D] s_b_5_8 = (u8)s_b_5_7 */
    auto s_b_5_8 = emitter.truncate(s_b_5_7, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_9 = constant s32 0 (const) */
    /* execute.simd:3494 [D] s_b_5_10 = s_b_5_3[s_b_5_9] <= s_b_5_8 */
    auto s_b_5_10 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_5_8);
    /* ???:4294967295 [F] s_b_5_11 = constant u8 1 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_11] */
    auto s_b_5_12 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3494 [D] s_b_5_13 = (s32)s_b_5_12 */
    auto s_b_5_13 = emitter.sx(s_b_5_12, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_14 = __builtin_abs32 */
    auto s_b_5_14 = emitter.call(__captive___builtin_abs32, s_b_5_13);
    /* execute.simd:3494 [D] s_b_5_15 = (u8)s_b_5_14 */
    auto s_b_5_15 = emitter.truncate(s_b_5_14, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_16 = constant s32 1 (const) */
    /* execute.simd:3494 [D] s_b_5_17 = s_b_5_10[s_b_5_16] <= s_b_5_15 */
    auto s_b_5_17 = emitter.vector_insert(s_b_5_10, emitter.const_s32((int32_t)1ULL), s_b_5_15);
    /* ???:4294967295 [F] s_b_5_18 = constant u8 2 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_18] */
    auto s_b_5_19 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3494 [D] s_b_5_20 = (s32)s_b_5_19 */
    auto s_b_5_20 = emitter.sx(s_b_5_19, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_21 = __builtin_abs32 */
    auto s_b_5_21 = emitter.call(__captive___builtin_abs32, s_b_5_20);
    /* execute.simd:3494 [D] s_b_5_22 = (u8)s_b_5_21 */
    auto s_b_5_22 = emitter.truncate(s_b_5_21, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_23 = constant s32 2 (const) */
    /* execute.simd:3494 [D] s_b_5_24 = s_b_5_17[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_17, emitter.const_s32((int32_t)2ULL), s_b_5_22);
    /* ???:4294967295 [F] s_b_5_25 = constant u8 3 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3494 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_28 = __builtin_abs32 */
    auto s_b_5_28 = emitter.call(__captive___builtin_abs32, s_b_5_27);
    /* execute.simd:3494 [D] s_b_5_29 = (u8)s_b_5_28 */
    auto s_b_5_29 = emitter.truncate(s_b_5_28, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_30 = constant s32 3 (const) */
    /* execute.simd:3494 [D] s_b_5_31 = s_b_5_24[s_b_5_30] <= s_b_5_29 */
    auto s_b_5_31 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)3ULL), s_b_5_29);
    /* ???:4294967295 [F] s_b_5_32 = constant u8 4 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_32] */
    auto s_b_5_33 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3494 [D] s_b_5_34 = (s32)s_b_5_33 */
    auto s_b_5_34 = emitter.sx(s_b_5_33, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_35 = __builtin_abs32 */
    auto s_b_5_35 = emitter.call(__captive___builtin_abs32, s_b_5_34);
    /* execute.simd:3494 [D] s_b_5_36 = (u8)s_b_5_35 */
    auto s_b_5_36 = emitter.truncate(s_b_5_35, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_37 = constant s32 4 (const) */
    /* execute.simd:3494 [D] s_b_5_38 = s_b_5_31[s_b_5_37] <= s_b_5_36 */
    auto s_b_5_38 = emitter.vector_insert(s_b_5_31, emitter.const_s32((int32_t)4ULL), s_b_5_36);
    /* ???:4294967295 [F] s_b_5_39 = constant u8 5 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_39] */
    auto s_b_5_40 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3494 [D] s_b_5_41 = (s32)s_b_5_40 */
    auto s_b_5_41 = emitter.sx(s_b_5_40, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_42 = __builtin_abs32 */
    auto s_b_5_42 = emitter.call(__captive___builtin_abs32, s_b_5_41);
    /* execute.simd:3494 [D] s_b_5_43 = (u8)s_b_5_42 */
    auto s_b_5_43 = emitter.truncate(s_b_5_42, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_44 = constant s32 5 (const) */
    /* execute.simd:3494 [D] s_b_5_45 = s_b_5_38[s_b_5_44] <= s_b_5_43 */
    auto s_b_5_45 = emitter.vector_insert(s_b_5_38, emitter.const_s32((int32_t)5ULL), s_b_5_43);
    /* ???:4294967295 [F] s_b_5_46 = constant u8 6 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_46] */
    auto s_b_5_47 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3494 [D] s_b_5_48 = (s32)s_b_5_47 */
    auto s_b_5_48 = emitter.sx(s_b_5_47, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_49 = __builtin_abs32 */
    auto s_b_5_49 = emitter.call(__captive___builtin_abs32, s_b_5_48);
    /* execute.simd:3494 [D] s_b_5_50 = (u8)s_b_5_49 */
    auto s_b_5_50 = emitter.truncate(s_b_5_49, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_51 = constant s32 6 (const) */
    /* execute.simd:3494 [D] s_b_5_52 = s_b_5_45[s_b_5_51] <= s_b_5_50 */
    auto s_b_5_52 = emitter.vector_insert(s_b_5_45, emitter.const_s32((int32_t)6ULL), s_b_5_50);
    /* ???:4294967295 [F] s_b_5_53 = constant u8 7 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_53] */
    auto s_b_5_54 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3494 [D] s_b_5_55 = (s32)s_b_5_54 */
    auto s_b_5_55 = emitter.sx(s_b_5_54, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_56 = __builtin_abs32 */
    auto s_b_5_56 = emitter.call(__captive___builtin_abs32, s_b_5_55);
    /* execute.simd:3494 [D] s_b_5_57 = (u8)s_b_5_56 */
    auto s_b_5_57 = emitter.truncate(s_b_5_56, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_58 = constant s32 7 (const) */
    /* execute.simd:3494 [D] s_b_5_59 = s_b_5_52[s_b_5_58] <= s_b_5_57 */
    auto s_b_5_59 = emitter.vector_insert(s_b_5_52, emitter.const_s32((int32_t)7ULL), s_b_5_57);
    /* ???:4294967295 [F] s_b_5_60 = constant u8 8 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_60] */
    auto s_b_5_61 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)8ULL));
    /* execute.simd:3494 [D] s_b_5_62 = (s32)s_b_5_61 */
    auto s_b_5_62 = emitter.sx(s_b_5_61, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_63 = __builtin_abs32 */
    auto s_b_5_63 = emitter.call(__captive___builtin_abs32, s_b_5_62);
    /* execute.simd:3494 [D] s_b_5_64 = (u8)s_b_5_63 */
    auto s_b_5_64 = emitter.truncate(s_b_5_63, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_65 = constant s32 8 (const) */
    /* execute.simd:3494 [D] s_b_5_66 = s_b_5_59[s_b_5_65] <= s_b_5_64 */
    auto s_b_5_66 = emitter.vector_insert(s_b_5_59, emitter.const_s32((int32_t)8ULL), s_b_5_64);
    /* ???:4294967295 [F] s_b_5_67 = constant u8 9 (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_67] */
    auto s_b_5_68 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)9ULL));
    /* execute.simd:3494 [D] s_b_5_69 = (s32)s_b_5_68 */
    auto s_b_5_69 = emitter.sx(s_b_5_68, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_70 = __builtin_abs32 */
    auto s_b_5_70 = emitter.call(__captive___builtin_abs32, s_b_5_69);
    /* execute.simd:3494 [D] s_b_5_71 = (u8)s_b_5_70 */
    auto s_b_5_71 = emitter.truncate(s_b_5_70, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_72 = constant s32 9 (const) */
    /* execute.simd:3494 [D] s_b_5_73 = s_b_5_66[s_b_5_72] <= s_b_5_71 */
    auto s_b_5_73 = emitter.vector_insert(s_b_5_66, emitter.const_s32((int32_t)9ULL), s_b_5_71);
    /* ???:4294967295 [F] s_b_5_74 = constant u8 a (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_74] */
    auto s_b_5_75 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)10ULL));
    /* execute.simd:3494 [D] s_b_5_76 = (s32)s_b_5_75 */
    auto s_b_5_76 = emitter.sx(s_b_5_75, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_77 = __builtin_abs32 */
    auto s_b_5_77 = emitter.call(__captive___builtin_abs32, s_b_5_76);
    /* execute.simd:3494 [D] s_b_5_78 = (u8)s_b_5_77 */
    auto s_b_5_78 = emitter.truncate(s_b_5_77, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_79 = constant s32 a (const) */
    /* execute.simd:3494 [D] s_b_5_80 = s_b_5_73[s_b_5_79] <= s_b_5_78 */
    auto s_b_5_80 = emitter.vector_insert(s_b_5_73, emitter.const_s32((int32_t)10ULL), s_b_5_78);
    /* ???:4294967295 [F] s_b_5_81 = constant u8 b (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_81] */
    auto s_b_5_82 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)11ULL));
    /* execute.simd:3494 [D] s_b_5_83 = (s32)s_b_5_82 */
    auto s_b_5_83 = emitter.sx(s_b_5_82, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_84 = __builtin_abs32 */
    auto s_b_5_84 = emitter.call(__captive___builtin_abs32, s_b_5_83);
    /* execute.simd:3494 [D] s_b_5_85 = (u8)s_b_5_84 */
    auto s_b_5_85 = emitter.truncate(s_b_5_84, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_86 = constant s32 b (const) */
    /* execute.simd:3494 [D] s_b_5_87 = s_b_5_80[s_b_5_86] <= s_b_5_85 */
    auto s_b_5_87 = emitter.vector_insert(s_b_5_80, emitter.const_s32((int32_t)11ULL), s_b_5_85);
    /* ???:4294967295 [F] s_b_5_88 = constant u8 c (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_88] */
    auto s_b_5_89 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)12ULL));
    /* execute.simd:3494 [D] s_b_5_90 = (s32)s_b_5_89 */
    auto s_b_5_90 = emitter.sx(s_b_5_89, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_91 = __builtin_abs32 */
    auto s_b_5_91 = emitter.call(__captive___builtin_abs32, s_b_5_90);
    /* execute.simd:3494 [D] s_b_5_92 = (u8)s_b_5_91 */
    auto s_b_5_92 = emitter.truncate(s_b_5_91, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_93 = constant s32 c (const) */
    /* execute.simd:3494 [D] s_b_5_94 = s_b_5_87[s_b_5_93] <= s_b_5_92 */
    auto s_b_5_94 = emitter.vector_insert(s_b_5_87, emitter.const_s32((int32_t)12ULL), s_b_5_92);
    /* ???:4294967295 [F] s_b_5_95 = constant u8 d (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_95] */
    auto s_b_5_96 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)13ULL));
    /* execute.simd:3494 [D] s_b_5_97 = (s32)s_b_5_96 */
    auto s_b_5_97 = emitter.sx(s_b_5_96, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_98 = __builtin_abs32 */
    auto s_b_5_98 = emitter.call(__captive___builtin_abs32, s_b_5_97);
    /* execute.simd:3494 [D] s_b_5_99 = (u8)s_b_5_98 */
    auto s_b_5_99 = emitter.truncate(s_b_5_98, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_100 = constant s32 d (const) */
    /* execute.simd:3494 [D] s_b_5_101 = s_b_5_94[s_b_5_100] <= s_b_5_99 */
    auto s_b_5_101 = emitter.vector_insert(s_b_5_94, emitter.const_s32((int32_t)13ULL), s_b_5_99);
    /* ???:4294967295 [F] s_b_5_102 = constant u8 e (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_102] */
    auto s_b_5_103 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)14ULL));
    /* execute.simd:3494 [D] s_b_5_104 = (s32)s_b_5_103 */
    auto s_b_5_104 = emitter.sx(s_b_5_103, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_105 = __builtin_abs32 */
    auto s_b_5_105 = emitter.call(__captive___builtin_abs32, s_b_5_104);
    /* execute.simd:3494 [D] s_b_5_106 = (u8)s_b_5_105 */
    auto s_b_5_106 = emitter.truncate(s_b_5_105, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_107 = constant s32 e (const) */
    /* execute.simd:3494 [D] s_b_5_108 = s_b_5_101[s_b_5_107] <= s_b_5_106 */
    auto s_b_5_108 = emitter.vector_insert(s_b_5_101, emitter.const_s32((int32_t)14ULL), s_b_5_106);
    /* ???:4294967295 [F] s_b_5_109 = constant u8 f (const) */
    /* execute.simd:3494 [D] s_b_5_2[s_b_5_109] */
    auto s_b_5_110 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)15ULL));
    /* execute.simd:3494 [D] s_b_5_111 = (s32)s_b_5_110 */
    auto s_b_5_111 = emitter.sx(s_b_5_110, emitter.context().types().s32());
    /* execute.simd:3494 [D] s_b_5_112 = __builtin_abs32 */
    auto s_b_5_112 = emitter.call(__captive___builtin_abs32, s_b_5_111);
    /* execute.simd:3494 [D] s_b_5_113 = (u8)s_b_5_112 */
    auto s_b_5_113 = emitter.truncate(s_b_5_112, emitter.context().types().u8());
    /* execute.simd:3494 [F] s_b_5_114 = constant s32 f (const) */
    /* execute.simd:3494 [D] s_b_5_115 = s_b_5_108[s_b_5_114] <= s_b_5_113 */
    auto s_b_5_115 = emitter.vector_insert(s_b_5_108, emitter.const_s32((int32_t)15ULL), s_b_5_113);
    /* execute.simd:3497 [F] s_b_5_116=sym_2511_3_parameter_inst.rd (const) */
    /* execute.simd:3497 [D] s_b_5_117: WriteRegBank 16:s_b_5_116 = s_b_5_115 */
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
    /* execute.simd:3501 [F] s_b_6_0=sym_2511_3_parameter_inst.rn (const) */
    /* execute.simd:3501 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:3501 [D] s_b_6_2 = (v4s16)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_6_3 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_4 = constant u8 0 (const) */
    /* execute.simd:3505 [D] s_b_6_2[s_b_6_4] */
    auto s_b_6_5 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3505 [D] s_b_6_6 = (s32)s_b_6_5 */
    auto s_b_6_6 = emitter.sx(s_b_6_5, emitter.context().types().s32());
    /* execute.simd:3505 [D] s_b_6_7 = __builtin_abs32 */
    auto s_b_6_7 = emitter.call(__captive___builtin_abs32, s_b_6_6);
    /* execute.simd:3505 [D] s_b_6_8 = (u16)s_b_6_7 */
    auto s_b_6_8 = emitter.truncate(s_b_6_7, emitter.context().types().u16());
    /* execute.simd:3505 [F] s_b_6_9 = constant s32 0 (const) */
    /* execute.simd:3505 [D] s_b_6_10 = s_b_6_3[s_b_6_9] <= s_b_6_8 */
    auto s_b_6_10 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_6_8);
    /* ???:4294967295 [F] s_b_6_11 = constant u8 1 (const) */
    /* execute.simd:3505 [D] s_b_6_2[s_b_6_11] */
    auto s_b_6_12 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3505 [D] s_b_6_13 = (s32)s_b_6_12 */
    auto s_b_6_13 = emitter.sx(s_b_6_12, emitter.context().types().s32());
    /* execute.simd:3505 [D] s_b_6_14 = __builtin_abs32 */
    auto s_b_6_14 = emitter.call(__captive___builtin_abs32, s_b_6_13);
    /* execute.simd:3505 [D] s_b_6_15 = (u16)s_b_6_14 */
    auto s_b_6_15 = emitter.truncate(s_b_6_14, emitter.context().types().u16());
    /* execute.simd:3505 [F] s_b_6_16 = constant s32 1 (const) */
    /* execute.simd:3505 [D] s_b_6_17 = s_b_6_10[s_b_6_16] <= s_b_6_15 */
    auto s_b_6_17 = emitter.vector_insert(s_b_6_10, emitter.const_s32((int32_t)1ULL), s_b_6_15);
    /* ???:4294967295 [F] s_b_6_18 = constant u8 2 (const) */
    /* execute.simd:3505 [D] s_b_6_2[s_b_6_18] */
    auto s_b_6_19 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3505 [D] s_b_6_20 = (s32)s_b_6_19 */
    auto s_b_6_20 = emitter.sx(s_b_6_19, emitter.context().types().s32());
    /* execute.simd:3505 [D] s_b_6_21 = __builtin_abs32 */
    auto s_b_6_21 = emitter.call(__captive___builtin_abs32, s_b_6_20);
    /* execute.simd:3505 [D] s_b_6_22 = (u16)s_b_6_21 */
    auto s_b_6_22 = emitter.truncate(s_b_6_21, emitter.context().types().u16());
    /* execute.simd:3505 [F] s_b_6_23 = constant s32 2 (const) */
    /* execute.simd:3505 [D] s_b_6_24 = s_b_6_17[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_17, emitter.const_s32((int32_t)2ULL), s_b_6_22);
    /* ???:4294967295 [F] s_b_6_25 = constant u8 3 (const) */
    /* execute.simd:3505 [D] s_b_6_2[s_b_6_25] */
    auto s_b_6_26 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3505 [D] s_b_6_27 = (s32)s_b_6_26 */
    auto s_b_6_27 = emitter.sx(s_b_6_26, emitter.context().types().s32());
    /* execute.simd:3505 [D] s_b_6_28 = __builtin_abs32 */
    auto s_b_6_28 = emitter.call(__captive___builtin_abs32, s_b_6_27);
    /* execute.simd:3505 [D] s_b_6_29 = (u16)s_b_6_28 */
    auto s_b_6_29 = emitter.truncate(s_b_6_28, emitter.context().types().u16());
    /* execute.simd:3505 [F] s_b_6_30 = constant s32 3 (const) */
    /* execute.simd:3505 [D] s_b_6_31 = s_b_6_24[s_b_6_30] <= s_b_6_29 */
    auto s_b_6_31 = emitter.vector_insert(s_b_6_24, emitter.const_s32((int32_t)3ULL), s_b_6_29);
    /* execute.simd:3508 [F] s_b_6_32=sym_2511_3_parameter_inst.rd (const) */
    /* execute.simd:3508 [D] s_b_6_33: WriteRegBank 18:s_b_6_32 = s_b_6_31 */
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
    /* execute.simd:3512 [F] s_b_7_0=sym_2511_3_parameter_inst.rn (const) */
    /* execute.simd:3512 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:3512 [D] s_b_7_2 = (v8s16)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_7_3 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_7_4 = constant u8 0 (const) */
    /* execute.simd:3516 [D] s_b_7_2[s_b_7_4] */
    auto s_b_7_5 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3516 [D] s_b_7_6 = (s32)s_b_7_5 */
    auto s_b_7_6 = emitter.sx(s_b_7_5, emitter.context().types().s32());
    /* execute.simd:3516 [D] s_b_7_7 = __builtin_abs32 */
    auto s_b_7_7 = emitter.call(__captive___builtin_abs32, s_b_7_6);
    /* execute.simd:3516 [D] s_b_7_8 = (u16)s_b_7_7 */
    auto s_b_7_8 = emitter.truncate(s_b_7_7, emitter.context().types().u16());
    /* execute.simd:3516 [F] s_b_7_9 = constant s32 0 (const) */
    /* execute.simd:3516 [D] s_b_7_10 = s_b_7_3[s_b_7_9] <= s_b_7_8 */
    auto s_b_7_10 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_7_8);
    /* ???:4294967295 [F] s_b_7_11 = constant u8 1 (const) */
    /* execute.simd:3516 [D] s_b_7_2[s_b_7_11] */
    auto s_b_7_12 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3516 [D] s_b_7_13 = (s32)s_b_7_12 */
    auto s_b_7_13 = emitter.sx(s_b_7_12, emitter.context().types().s32());
    /* execute.simd:3516 [D] s_b_7_14 = __builtin_abs32 */
    auto s_b_7_14 = emitter.call(__captive___builtin_abs32, s_b_7_13);
    /* execute.simd:3516 [D] s_b_7_15 = (u16)s_b_7_14 */
    auto s_b_7_15 = emitter.truncate(s_b_7_14, emitter.context().types().u16());
    /* execute.simd:3516 [F] s_b_7_16 = constant s32 1 (const) */
    /* execute.simd:3516 [D] s_b_7_17 = s_b_7_10[s_b_7_16] <= s_b_7_15 */
    auto s_b_7_17 = emitter.vector_insert(s_b_7_10, emitter.const_s32((int32_t)1ULL), s_b_7_15);
    /* ???:4294967295 [F] s_b_7_18 = constant u8 2 (const) */
    /* execute.simd:3516 [D] s_b_7_2[s_b_7_18] */
    auto s_b_7_19 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3516 [D] s_b_7_20 = (s32)s_b_7_19 */
    auto s_b_7_20 = emitter.sx(s_b_7_19, emitter.context().types().s32());
    /* execute.simd:3516 [D] s_b_7_21 = __builtin_abs32 */
    auto s_b_7_21 = emitter.call(__captive___builtin_abs32, s_b_7_20);
    /* execute.simd:3516 [D] s_b_7_22 = (u16)s_b_7_21 */
    auto s_b_7_22 = emitter.truncate(s_b_7_21, emitter.context().types().u16());
    /* execute.simd:3516 [F] s_b_7_23 = constant s32 2 (const) */
    /* execute.simd:3516 [D] s_b_7_24 = s_b_7_17[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_17, emitter.const_s32((int32_t)2ULL), s_b_7_22);
    /* ???:4294967295 [F] s_b_7_25 = constant u8 3 (const) */
    /* execute.simd:3516 [D] s_b_7_2[s_b_7_25] */
    auto s_b_7_26 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3516 [D] s_b_7_27 = (s32)s_b_7_26 */
    auto s_b_7_27 = emitter.sx(s_b_7_26, emitter.context().types().s32());
    /* execute.simd:3516 [D] s_b_7_28 = __builtin_abs32 */
    auto s_b_7_28 = emitter.call(__captive___builtin_abs32, s_b_7_27);
    /* execute.simd:3516 [D] s_b_7_29 = (u16)s_b_7_28 */
    auto s_b_7_29 = emitter.truncate(s_b_7_28, emitter.context().types().u16());
    /* execute.simd:3516 [F] s_b_7_30 = constant s32 3 (const) */
    /* execute.simd:3516 [D] s_b_7_31 = s_b_7_24[s_b_7_30] <= s_b_7_29 */
    auto s_b_7_31 = emitter.vector_insert(s_b_7_24, emitter.const_s32((int32_t)3ULL), s_b_7_29);
    /* ???:4294967295 [F] s_b_7_32 = constant u8 4 (const) */
    /* execute.simd:3516 [D] s_b_7_2[s_b_7_32] */
    auto s_b_7_33 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3516 [D] s_b_7_34 = (s32)s_b_7_33 */
    auto s_b_7_34 = emitter.sx(s_b_7_33, emitter.context().types().s32());
    /* execute.simd:3516 [D] s_b_7_35 = __builtin_abs32 */
    auto s_b_7_35 = emitter.call(__captive___builtin_abs32, s_b_7_34);
    /* execute.simd:3516 [D] s_b_7_36 = (u16)s_b_7_35 */
    auto s_b_7_36 = emitter.truncate(s_b_7_35, emitter.context().types().u16());
    /* execute.simd:3516 [F] s_b_7_37 = constant s32 4 (const) */
    /* execute.simd:3516 [D] s_b_7_38 = s_b_7_31[s_b_7_37] <= s_b_7_36 */
    auto s_b_7_38 = emitter.vector_insert(s_b_7_31, emitter.const_s32((int32_t)4ULL), s_b_7_36);
    /* ???:4294967295 [F] s_b_7_39 = constant u8 5 (const) */
    /* execute.simd:3516 [D] s_b_7_2[s_b_7_39] */
    auto s_b_7_40 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3516 [D] s_b_7_41 = (s32)s_b_7_40 */
    auto s_b_7_41 = emitter.sx(s_b_7_40, emitter.context().types().s32());
    /* execute.simd:3516 [D] s_b_7_42 = __builtin_abs32 */
    auto s_b_7_42 = emitter.call(__captive___builtin_abs32, s_b_7_41);
    /* execute.simd:3516 [D] s_b_7_43 = (u16)s_b_7_42 */
    auto s_b_7_43 = emitter.truncate(s_b_7_42, emitter.context().types().u16());
    /* execute.simd:3516 [F] s_b_7_44 = constant s32 5 (const) */
    /* execute.simd:3516 [D] s_b_7_45 = s_b_7_38[s_b_7_44] <= s_b_7_43 */
    auto s_b_7_45 = emitter.vector_insert(s_b_7_38, emitter.const_s32((int32_t)5ULL), s_b_7_43);
    /* ???:4294967295 [F] s_b_7_46 = constant u8 6 (const) */
    /* execute.simd:3516 [D] s_b_7_2[s_b_7_46] */
    auto s_b_7_47 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3516 [D] s_b_7_48 = (s32)s_b_7_47 */
    auto s_b_7_48 = emitter.sx(s_b_7_47, emitter.context().types().s32());
    /* execute.simd:3516 [D] s_b_7_49 = __builtin_abs32 */
    auto s_b_7_49 = emitter.call(__captive___builtin_abs32, s_b_7_48);
    /* execute.simd:3516 [D] s_b_7_50 = (u16)s_b_7_49 */
    auto s_b_7_50 = emitter.truncate(s_b_7_49, emitter.context().types().u16());
    /* execute.simd:3516 [F] s_b_7_51 = constant s32 6 (const) */
    /* execute.simd:3516 [D] s_b_7_52 = s_b_7_45[s_b_7_51] <= s_b_7_50 */
    auto s_b_7_52 = emitter.vector_insert(s_b_7_45, emitter.const_s32((int32_t)6ULL), s_b_7_50);
    /* ???:4294967295 [F] s_b_7_53 = constant u8 7 (const) */
    /* execute.simd:3516 [D] s_b_7_2[s_b_7_53] */
    auto s_b_7_54 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3516 [D] s_b_7_55 = (s32)s_b_7_54 */
    auto s_b_7_55 = emitter.sx(s_b_7_54, emitter.context().types().s32());
    /* execute.simd:3516 [D] s_b_7_56 = __builtin_abs32 */
    auto s_b_7_56 = emitter.call(__captive___builtin_abs32, s_b_7_55);
    /* execute.simd:3516 [D] s_b_7_57 = (u16)s_b_7_56 */
    auto s_b_7_57 = emitter.truncate(s_b_7_56, emitter.context().types().u16());
    /* execute.simd:3516 [F] s_b_7_58 = constant s32 7 (const) */
    /* execute.simd:3516 [D] s_b_7_59 = s_b_7_52[s_b_7_58] <= s_b_7_57 */
    auto s_b_7_59 = emitter.vector_insert(s_b_7_52, emitter.const_s32((int32_t)7ULL), s_b_7_57);
    /* execute.simd:3519 [F] s_b_7_60=sym_2511_3_parameter_inst.rd (const) */
    /* execute.simd:3519 [D] s_b_7_61: WriteRegBank 18:s_b_7_60 = s_b_7_59 */
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
    /* execute.simd:3523 [F] s_b_8_0=sym_2511_3_parameter_inst.rn (const) */
    /* execute.simd:3523 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:3523 [D] s_b_8_2 = (v2s32)s_b_8_1 */
    auto s_b_8_2 = emitter.reinterpret(s_b_8_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_8_3 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_8_4 = constant u8 0 (const) */
    /* execute.simd:3527 [D] s_b_8_2[s_b_8_4] */
    auto s_b_8_5 = emitter.vector_extract(s_b_8_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3527 [D] s_b_8_6 = __builtin_abs32 */
    auto s_b_8_6 = emitter.call(__captive___builtin_abs32, s_b_8_5);
    /* execute.simd:3527 [F] s_b_8_7 = constant s32 0 (const) */
    /* execute.simd:3527 [D] s_b_8_8 = s_b_8_3[s_b_8_7] <= s_b_8_6 */
    auto s_b_8_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_8_6);
    /* ???:4294967295 [F] s_b_8_9 = constant u8 1 (const) */
    /* execute.simd:3527 [D] s_b_8_2[s_b_8_9] */
    auto s_b_8_10 = emitter.vector_extract(s_b_8_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3527 [D] s_b_8_11 = __builtin_abs32 */
    auto s_b_8_11 = emitter.call(__captive___builtin_abs32, s_b_8_10);
    /* execute.simd:3527 [F] s_b_8_12 = constant s32 1 (const) */
    /* execute.simd:3527 [D] s_b_8_13 = s_b_8_8[s_b_8_12] <= s_b_8_11 */
    auto s_b_8_13 = emitter.vector_insert(s_b_8_8, emitter.const_s32((int32_t)1ULL), s_b_8_11);
    /* execute.simd:3530 [F] s_b_8_14=sym_2511_3_parameter_inst.rd (const) */
    /* execute.simd:3530 [D] s_b_8_15: WriteRegBank 20:s_b_8_14 = s_b_8_13 */
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
    /* execute.simd:3534 [F] s_b_9_0=sym_2511_3_parameter_inst.rn (const) */
    /* execute.simd:3534 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:3534 [D] s_b_9_2 = (v4s32)s_b_9_1 */
    auto s_b_9_2 = emitter.reinterpret(s_b_9_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_9_3 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_9_4 = constant u8 0 (const) */
    /* execute.simd:3538 [D] s_b_9_2[s_b_9_4] */
    auto s_b_9_5 = emitter.vector_extract(s_b_9_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3538 [D] s_b_9_6 = __builtin_abs32 */
    auto s_b_9_6 = emitter.call(__captive___builtin_abs32, s_b_9_5);
    /* execute.simd:3538 [F] s_b_9_7 = constant s32 0 (const) */
    /* execute.simd:3538 [D] s_b_9_8 = s_b_9_3[s_b_9_7] <= s_b_9_6 */
    auto s_b_9_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_9_6);
    /* ???:4294967295 [F] s_b_9_9 = constant u8 1 (const) */
    /* execute.simd:3538 [D] s_b_9_2[s_b_9_9] */
    auto s_b_9_10 = emitter.vector_extract(s_b_9_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3538 [D] s_b_9_11 = __builtin_abs32 */
    auto s_b_9_11 = emitter.call(__captive___builtin_abs32, s_b_9_10);
    /* execute.simd:3538 [F] s_b_9_12 = constant s32 1 (const) */
    /* execute.simd:3538 [D] s_b_9_13 = s_b_9_8[s_b_9_12] <= s_b_9_11 */
    auto s_b_9_13 = emitter.vector_insert(s_b_9_8, emitter.const_s32((int32_t)1ULL), s_b_9_11);
    /* ???:4294967295 [F] s_b_9_14 = constant u8 2 (const) */
    /* execute.simd:3538 [D] s_b_9_2[s_b_9_14] */
    auto s_b_9_15 = emitter.vector_extract(s_b_9_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3538 [D] s_b_9_16 = __builtin_abs32 */
    auto s_b_9_16 = emitter.call(__captive___builtin_abs32, s_b_9_15);
    /* execute.simd:3538 [F] s_b_9_17 = constant s32 2 (const) */
    /* execute.simd:3538 [D] s_b_9_18 = s_b_9_13[s_b_9_17] <= s_b_9_16 */
    auto s_b_9_18 = emitter.vector_insert(s_b_9_13, emitter.const_s32((int32_t)2ULL), s_b_9_16);
    /* ???:4294967295 [F] s_b_9_19 = constant u8 3 (const) */
    /* execute.simd:3538 [D] s_b_9_2[s_b_9_19] */
    auto s_b_9_20 = emitter.vector_extract(s_b_9_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3538 [D] s_b_9_21 = __builtin_abs32 */
    auto s_b_9_21 = emitter.call(__captive___builtin_abs32, s_b_9_20);
    /* execute.simd:3538 [F] s_b_9_22 = constant s32 3 (const) */
    /* execute.simd:3538 [D] s_b_9_23 = s_b_9_18[s_b_9_22] <= s_b_9_21 */
    auto s_b_9_23 = emitter.vector_insert(s_b_9_18, emitter.const_s32((int32_t)3ULL), s_b_9_21);
    /* execute.simd:3541 [F] s_b_9_24=sym_2511_3_parameter_inst.rd (const) */
    /* execute.simd:3541 [D] s_b_9_25: WriteRegBank 20:s_b_9_24 = s_b_9_23 */
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
    /* execute.simd:3545 [F] s_b_10_0=sym_2511_3_parameter_inst.rn (const) */
    /* execute.simd:3545 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:3545 [D] s_b_10_2 = (v2s64)s_b_10_1 */
    auto s_b_10_2 = emitter.reinterpret(s_b_10_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_10_3 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_10_4 = constant u8 0 (const) */
    /* execute.simd:3549 [D] s_b_10_2[s_b_10_4] */
    auto s_b_10_5 = emitter.vector_extract(s_b_10_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3549 [D] s_b_10_6 = __builtin_abs64 */
    auto s_b_10_6 = emitter.call(__captive___builtin_abs64, s_b_10_5);
    /* execute.simd:3549 [F] s_b_10_7 = constant s32 0 (const) */
    /* execute.simd:3549 [D] s_b_10_8 = s_b_10_3[s_b_10_7] <= s_b_10_6 */
    auto s_b_10_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_10_6);
    /* ???:4294967295 [F] s_b_10_9 = constant u8 1 (const) */
    /* execute.simd:3549 [D] s_b_10_2[s_b_10_9] */
    auto s_b_10_10 = emitter.vector_extract(s_b_10_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3549 [D] s_b_10_11 = __builtin_abs64 */
    auto s_b_10_11 = emitter.call(__captive___builtin_abs64, s_b_10_10);
    /* execute.simd:3549 [F] s_b_10_12 = constant s32 1 (const) */
    /* execute.simd:3549 [D] s_b_10_13 = s_b_10_8[s_b_10_12] <= s_b_10_11 */
    auto s_b_10_13 = emitter.vector_insert(s_b_10_8, emitter.const_s32((int32_t)1ULL), s_b_10_11);
    /* execute.simd:3552 [F] s_b_10_14=sym_2511_3_parameter_inst.rd (const) */
    /* execute.simd:3552 [D] s_b_10_15: WriteRegBank 21:s_b_10_14 = s_b_10_13 */
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
    /* execute.simd:3556 [D] s_b_11_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_addv(const aarch64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_5274_0_total;
  auto DV_sym_5274_0_total = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:162 [F] s_b_0_0 = constant u64 0 (const) */
    /* execute.simd:162 [F] s_b_0_1: sym_5274_0_total = s_b_0_0 (const), dominates: s_b_7_2 s_b_13_1 s_b_12_1 s_b_11_1 s_b_5_2 s_b_4_2 s_b_3_2 s_b_2_2  */
    CV_sym_5274_0_total = (uint64_t)0ULL;
    emitter.store_local(DV_sym_5274_0_total, emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:164 [F] s_b_0_2=sym_5271_3_parameter_inst.arrangement (const) */
    /* execute.simd:165 [F] s_b_0_3 = constant s32 0 (const) */
    /* execute.simd:173 [F] s_b_0_4 = constant s32 1 (const) */
    /* execute.simd:181 [F] s_b_0_5 = constant s32 2 (const) */
    /* execute.simd:189 [F] s_b_0_6 = constant s32 3 (const) */
    /* execute.simd:197 [F] s_b_0_7 = constant s32 4 (const) */
    /* execute.simd:201 [F] s_b_0_8 = constant s32 5 (const) */
    /* execute.simd:209 [F] s_b_0_9 = constant s32 6 (const) */
    /* execute.simd:164 [F] s_b_0_10: Switch s_b_0_2: < <todo> > def b_9 (const) -> b_7, b_6, b_5, b_4, b_3, b_2, b_9, b_8,  */
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
    /* execute.simd:219 [F] s_b_1_0=sym_5271_3_parameter_inst.size (const) */
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
    /* execute.simd:166 [F] s_b_2_0=sym_5271_3_parameter_inst.rn (const) */
    /* execute.simd:166 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:169 [F] s_b_2_2 = sym_5274_0_total (const) uint64_t */
    uint64_t s_b_2_2 = CV_sym_5274_0_total;
    /* ???:4294967295 [F] s_b_2_3 = constant u8 0 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_2_5 = (u64)s_b_2_4 */
    auto s_b_2_5 = emitter.zx(s_b_2_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_6 = s_b_2_2+s_b_2_5 */
    auto s_b_2_6 = emitter.add(emitter.const_u64(s_b_2_2), s_b_2_5);
    /* execute.simd:169 [D] s_b_2_7: sym_5274_0_total = s_b_2_6, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_2_6);
    /* ???:4294967295 [F] s_b_2_8 = constant u8 1 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_8] */
    auto s_b_2_9 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_2_10 = (u64)s_b_2_9 */
    auto s_b_2_10 = emitter.zx(s_b_2_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_11 = s_b_2_6+s_b_2_10 */
    auto s_b_2_11 = emitter.add(s_b_2_6, s_b_2_10);
    /* execute.simd:169 [D] s_b_2_12: sym_5274_0_total = s_b_2_11, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_2_11);
    /* ???:4294967295 [F] s_b_2_13 = constant u8 2 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_2_15 = (u64)s_b_2_14 */
    auto s_b_2_15 = emitter.zx(s_b_2_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_16 = s_b_2_11+s_b_2_15 */
    auto s_b_2_16 = emitter.add(s_b_2_11, s_b_2_15);
    /* execute.simd:169 [D] s_b_2_17: sym_5274_0_total = s_b_2_16, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_2_16);
    /* ???:4294967295 [F] s_b_2_18 = constant u8 3 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_18] */
    auto s_b_2_19 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_2_20 = (u64)s_b_2_19 */
    auto s_b_2_20 = emitter.zx(s_b_2_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_21 = s_b_2_16+s_b_2_20 */
    auto s_b_2_21 = emitter.add(s_b_2_16, s_b_2_20);
    /* execute.simd:169 [D] s_b_2_22: sym_5274_0_total = s_b_2_21, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_2_21);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 4 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [D] s_b_2_25 = (u64)s_b_2_24 */
    auto s_b_2_25 = emitter.zx(s_b_2_24, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_26 = s_b_2_21+s_b_2_25 */
    auto s_b_2_26 = emitter.add(s_b_2_21, s_b_2_25);
    /* execute.simd:169 [D] s_b_2_27: sym_5274_0_total = s_b_2_26, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_2_26);
    /* ???:4294967295 [F] s_b_2_28 = constant u8 5 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [D] s_b_2_30 = (u64)s_b_2_29 */
    auto s_b_2_30 = emitter.zx(s_b_2_29, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_31 = s_b_2_26+s_b_2_30 */
    auto s_b_2_31 = emitter.add(s_b_2_26, s_b_2_30);
    /* execute.simd:169 [D] s_b_2_32: sym_5274_0_total = s_b_2_31, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_2_31);
    /* ???:4294967295 [F] s_b_2_33 = constant u8 6 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [D] s_b_2_35 = (u64)s_b_2_34 */
    auto s_b_2_35 = emitter.zx(s_b_2_34, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_36 = s_b_2_31+s_b_2_35 */
    auto s_b_2_36 = emitter.add(s_b_2_31, s_b_2_35);
    /* execute.simd:169 [D] s_b_2_37: sym_5274_0_total = s_b_2_36, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_2_36);
    /* ???:4294967295 [F] s_b_2_38 = constant u8 7 (const) */
    /* execute.simd:169 [D] s_b_2_1[s_b_2_38] */
    auto s_b_2_39 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [D] s_b_2_40 = (u64)s_b_2_39 */
    auto s_b_2_40 = emitter.zx(s_b_2_39, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_41 = s_b_2_36+s_b_2_40 */
    auto s_b_2_41 = emitter.add(s_b_2_36, s_b_2_40);
    /* execute.simd:169 [D] s_b_2_42: sym_5274_0_total = s_b_2_41, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5274_0_total, s_b_2_41);
    /* execute.simd:0 [F] s_b_2_43: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:174 [F] s_b_3_0=sym_5271_3_parameter_inst.rn (const) */
    /* execute.simd:174 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:177 [F] s_b_3_2 = sym_5274_0_total (const) uint64_t */
    uint64_t s_b_3_2 = CV_sym_5274_0_total;
    /* ???:4294967295 [F] s_b_3_3 = constant u8 0 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_3] */
    auto s_b_3_4 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_3_5 = (u64)s_b_3_4 */
    auto s_b_3_5 = emitter.zx(s_b_3_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_6 = s_b_3_2+s_b_3_5 */
    auto s_b_3_6 = emitter.add(emitter.const_u64(s_b_3_2), s_b_3_5);
    /* execute.simd:177 [D] s_b_3_7: sym_5274_0_total = s_b_3_6, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_6);
    /* ???:4294967295 [F] s_b_3_8 = constant u8 1 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_8] */
    auto s_b_3_9 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_3_10 = (u64)s_b_3_9 */
    auto s_b_3_10 = emitter.zx(s_b_3_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_11 = s_b_3_6+s_b_3_10 */
    auto s_b_3_11 = emitter.add(s_b_3_6, s_b_3_10);
    /* execute.simd:177 [D] s_b_3_12: sym_5274_0_total = s_b_3_11, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_11);
    /* ???:4294967295 [F] s_b_3_13 = constant u8 2 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_13] */
    auto s_b_3_14 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_3_15 = (u64)s_b_3_14 */
    auto s_b_3_15 = emitter.zx(s_b_3_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_16 = s_b_3_11+s_b_3_15 */
    auto s_b_3_16 = emitter.add(s_b_3_11, s_b_3_15);
    /* execute.simd:177 [D] s_b_3_17: sym_5274_0_total = s_b_3_16, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_16);
    /* ???:4294967295 [F] s_b_3_18 = constant u8 3 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_18] */
    auto s_b_3_19 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_3_20 = (u64)s_b_3_19 */
    auto s_b_3_20 = emitter.zx(s_b_3_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_21 = s_b_3_16+s_b_3_20 */
    auto s_b_3_21 = emitter.add(s_b_3_16, s_b_3_20);
    /* execute.simd:177 [D] s_b_3_22: sym_5274_0_total = s_b_3_21, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_21);
    /* ???:4294967295 [F] s_b_3_23 = constant u8 4 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [D] s_b_3_25 = (u64)s_b_3_24 */
    auto s_b_3_25 = emitter.zx(s_b_3_24, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_26 = s_b_3_21+s_b_3_25 */
    auto s_b_3_26 = emitter.add(s_b_3_21, s_b_3_25);
    /* execute.simd:177 [D] s_b_3_27: sym_5274_0_total = s_b_3_26, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_26);
    /* ???:4294967295 [F] s_b_3_28 = constant u8 5 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [D] s_b_3_30 = (u64)s_b_3_29 */
    auto s_b_3_30 = emitter.zx(s_b_3_29, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_31 = s_b_3_26+s_b_3_30 */
    auto s_b_3_31 = emitter.add(s_b_3_26, s_b_3_30);
    /* execute.simd:177 [D] s_b_3_32: sym_5274_0_total = s_b_3_31, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_31);
    /* ???:4294967295 [F] s_b_3_33 = constant u8 6 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [D] s_b_3_35 = (u64)s_b_3_34 */
    auto s_b_3_35 = emitter.zx(s_b_3_34, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_36 = s_b_3_31+s_b_3_35 */
    auto s_b_3_36 = emitter.add(s_b_3_31, s_b_3_35);
    /* execute.simd:177 [D] s_b_3_37: sym_5274_0_total = s_b_3_36, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_36);
    /* ???:4294967295 [F] s_b_3_38 = constant u8 7 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_38] */
    auto s_b_3_39 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [D] s_b_3_40 = (u64)s_b_3_39 */
    auto s_b_3_40 = emitter.zx(s_b_3_39, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_41 = s_b_3_36+s_b_3_40 */
    auto s_b_3_41 = emitter.add(s_b_3_36, s_b_3_40);
    /* execute.simd:177 [D] s_b_3_42: sym_5274_0_total = s_b_3_41, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_41);
    /* ???:4294967295 [F] s_b_3_43 = constant u8 8 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)8ULL));
    /* ???:4294967295 [D] s_b_3_45 = (u64)s_b_3_44 */
    auto s_b_3_45 = emitter.zx(s_b_3_44, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_46 = s_b_3_41+s_b_3_45 */
    auto s_b_3_46 = emitter.add(s_b_3_41, s_b_3_45);
    /* execute.simd:177 [D] s_b_3_47: sym_5274_0_total = s_b_3_46, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_46);
    /* ???:4294967295 [F] s_b_3_48 = constant u8 9 (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_48] */
    auto s_b_3_49 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)9ULL));
    /* ???:4294967295 [D] s_b_3_50 = (u64)s_b_3_49 */
    auto s_b_3_50 = emitter.zx(s_b_3_49, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_51 = s_b_3_46+s_b_3_50 */
    auto s_b_3_51 = emitter.add(s_b_3_46, s_b_3_50);
    /* execute.simd:177 [D] s_b_3_52: sym_5274_0_total = s_b_3_51, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_51);
    /* ???:4294967295 [F] s_b_3_53 = constant u8 a (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)10ULL));
    /* ???:4294967295 [D] s_b_3_55 = (u64)s_b_3_54 */
    auto s_b_3_55 = emitter.zx(s_b_3_54, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_56 = s_b_3_51+s_b_3_55 */
    auto s_b_3_56 = emitter.add(s_b_3_51, s_b_3_55);
    /* execute.simd:177 [D] s_b_3_57: sym_5274_0_total = s_b_3_56, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_56);
    /* ???:4294967295 [F] s_b_3_58 = constant u8 b (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_58] */
    auto s_b_3_59 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)11ULL));
    /* ???:4294967295 [D] s_b_3_60 = (u64)s_b_3_59 */
    auto s_b_3_60 = emitter.zx(s_b_3_59, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_61 = s_b_3_56+s_b_3_60 */
    auto s_b_3_61 = emitter.add(s_b_3_56, s_b_3_60);
    /* execute.simd:177 [D] s_b_3_62: sym_5274_0_total = s_b_3_61, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_61);
    /* ???:4294967295 [F] s_b_3_63 = constant u8 c (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_63] */
    auto s_b_3_64 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)12ULL));
    /* ???:4294967295 [D] s_b_3_65 = (u64)s_b_3_64 */
    auto s_b_3_65 = emitter.zx(s_b_3_64, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_66 = s_b_3_61+s_b_3_65 */
    auto s_b_3_66 = emitter.add(s_b_3_61, s_b_3_65);
    /* execute.simd:177 [D] s_b_3_67: sym_5274_0_total = s_b_3_66, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_66);
    /* ???:4294967295 [F] s_b_3_68 = constant u8 d (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_68] */
    auto s_b_3_69 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)13ULL));
    /* ???:4294967295 [D] s_b_3_70 = (u64)s_b_3_69 */
    auto s_b_3_70 = emitter.zx(s_b_3_69, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_71 = s_b_3_66+s_b_3_70 */
    auto s_b_3_71 = emitter.add(s_b_3_66, s_b_3_70);
    /* execute.simd:177 [D] s_b_3_72: sym_5274_0_total = s_b_3_71, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_71);
    /* ???:4294967295 [F] s_b_3_73 = constant u8 e (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)14ULL));
    /* ???:4294967295 [D] s_b_3_75 = (u64)s_b_3_74 */
    auto s_b_3_75 = emitter.zx(s_b_3_74, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_76 = s_b_3_71+s_b_3_75 */
    auto s_b_3_76 = emitter.add(s_b_3_71, s_b_3_75);
    /* execute.simd:177 [D] s_b_3_77: sym_5274_0_total = s_b_3_76, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_76);
    /* ???:4294967295 [F] s_b_3_78 = constant u8 f (const) */
    /* execute.simd:177 [D] s_b_3_1[s_b_3_78] */
    auto s_b_3_79 = emitter.vector_extract(s_b_3_1, emitter.const_u8((uint8_t)15ULL));
    /* ???:4294967295 [D] s_b_3_80 = (u64)s_b_3_79 */
    auto s_b_3_80 = emitter.zx(s_b_3_79, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_81 = s_b_3_76+s_b_3_80 */
    auto s_b_3_81 = emitter.add(s_b_3_76, s_b_3_80);
    /* execute.simd:177 [D] s_b_3_82: sym_5274_0_total = s_b_3_81, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5274_0_total, s_b_3_81);
    /* execute.simd:0 [F] s_b_3_83: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:182 [F] s_b_4_0=sym_5271_3_parameter_inst.rn (const) */
    /* execute.simd:182 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:185 [F] s_b_4_2 = sym_5274_0_total (const) uint64_t */
    uint64_t s_b_4_2 = CV_sym_5274_0_total;
    /* ???:4294967295 [F] s_b_4_3 = constant u8 0 (const) */
    /* execute.simd:185 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_4_5 = (u64)s_b_4_4 */
    auto s_b_4_5 = emitter.zx(s_b_4_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_6 = s_b_4_2+s_b_4_5 */
    auto s_b_4_6 = emitter.add(emitter.const_u64(s_b_4_2), s_b_4_5);
    /* execute.simd:185 [D] s_b_4_7: sym_5274_0_total = s_b_4_6, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_4_6);
    /* ???:4294967295 [F] s_b_4_8 = constant u8 1 (const) */
    /* execute.simd:185 [D] s_b_4_1[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_4_10 = (u64)s_b_4_9 */
    auto s_b_4_10 = emitter.zx(s_b_4_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_11 = s_b_4_6+s_b_4_10 */
    auto s_b_4_11 = emitter.add(s_b_4_6, s_b_4_10);
    /* execute.simd:185 [D] s_b_4_12: sym_5274_0_total = s_b_4_11, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_4_11);
    /* ???:4294967295 [F] s_b_4_13 = constant u8 2 (const) */
    /* execute.simd:185 [D] s_b_4_1[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_4_15 = (u64)s_b_4_14 */
    auto s_b_4_15 = emitter.zx(s_b_4_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_16 = s_b_4_11+s_b_4_15 */
    auto s_b_4_16 = emitter.add(s_b_4_11, s_b_4_15);
    /* execute.simd:185 [D] s_b_4_17: sym_5274_0_total = s_b_4_16, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_4_16);
    /* ???:4294967295 [F] s_b_4_18 = constant u8 3 (const) */
    /* execute.simd:185 [D] s_b_4_1[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_4_20 = (u64)s_b_4_19 */
    auto s_b_4_20 = emitter.zx(s_b_4_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_21 = s_b_4_16+s_b_4_20 */
    auto s_b_4_21 = emitter.add(s_b_4_16, s_b_4_20);
    /* execute.simd:185 [D] s_b_4_22: sym_5274_0_total = s_b_4_21, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5274_0_total, s_b_4_21);
    /* execute.simd:0 [F] s_b_4_23: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:190 [F] s_b_5_0=sym_5271_3_parameter_inst.rn (const) */
    /* execute.simd:190 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:193 [F] s_b_5_2 = sym_5274_0_total (const) uint64_t */
    uint64_t s_b_5_2 = CV_sym_5274_0_total;
    /* ???:4294967295 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_3] */
    auto s_b_5_4 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_5_5 = (u64)s_b_5_4 */
    auto s_b_5_5 = emitter.zx(s_b_5_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_6 = s_b_5_2+s_b_5_5 */
    auto s_b_5_6 = emitter.add(emitter.const_u64(s_b_5_2), s_b_5_5);
    /* execute.simd:193 [D] s_b_5_7: sym_5274_0_total = s_b_5_6, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_5_6);
    /* ???:4294967295 [F] s_b_5_8 = constant u8 1 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_8] */
    auto s_b_5_9 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_5_10 = (u64)s_b_5_9 */
    auto s_b_5_10 = emitter.zx(s_b_5_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_11 = s_b_5_6+s_b_5_10 */
    auto s_b_5_11 = emitter.add(s_b_5_6, s_b_5_10);
    /* execute.simd:193 [D] s_b_5_12: sym_5274_0_total = s_b_5_11, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_5_11);
    /* ???:4294967295 [F] s_b_5_13 = constant u8 2 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_13] */
    auto s_b_5_14 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_5_15 = (u64)s_b_5_14 */
    auto s_b_5_15 = emitter.zx(s_b_5_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_16 = s_b_5_11+s_b_5_15 */
    auto s_b_5_16 = emitter.add(s_b_5_11, s_b_5_15);
    /* execute.simd:193 [D] s_b_5_17: sym_5274_0_total = s_b_5_16, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_5_16);
    /* ???:4294967295 [F] s_b_5_18 = constant u8 3 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_18] */
    auto s_b_5_19 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_5_20 = (u64)s_b_5_19 */
    auto s_b_5_20 = emitter.zx(s_b_5_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_21 = s_b_5_16+s_b_5_20 */
    auto s_b_5_21 = emitter.add(s_b_5_16, s_b_5_20);
    /* execute.simd:193 [D] s_b_5_22: sym_5274_0_total = s_b_5_21, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_5_21);
    /* ???:4294967295 [F] s_b_5_23 = constant u8 4 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [D] s_b_5_25 = (u64)s_b_5_24 */
    auto s_b_5_25 = emitter.zx(s_b_5_24, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_26 = s_b_5_21+s_b_5_25 */
    auto s_b_5_26 = emitter.add(s_b_5_21, s_b_5_25);
    /* execute.simd:193 [D] s_b_5_27: sym_5274_0_total = s_b_5_26, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_5_26);
    /* ???:4294967295 [F] s_b_5_28 = constant u8 5 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [D] s_b_5_30 = (u64)s_b_5_29 */
    auto s_b_5_30 = emitter.zx(s_b_5_29, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_31 = s_b_5_26+s_b_5_30 */
    auto s_b_5_31 = emitter.add(s_b_5_26, s_b_5_30);
    /* execute.simd:193 [D] s_b_5_32: sym_5274_0_total = s_b_5_31, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_5_31);
    /* ???:4294967295 [F] s_b_5_33 = constant u8 6 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [D] s_b_5_35 = (u64)s_b_5_34 */
    auto s_b_5_35 = emitter.zx(s_b_5_34, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_36 = s_b_5_31+s_b_5_35 */
    auto s_b_5_36 = emitter.add(s_b_5_31, s_b_5_35);
    /* execute.simd:193 [D] s_b_5_37: sym_5274_0_total = s_b_5_36, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_5_36);
    /* ???:4294967295 [F] s_b_5_38 = constant u8 7 (const) */
    /* execute.simd:193 [D] s_b_5_1[s_b_5_38] */
    auto s_b_5_39 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [D] s_b_5_40 = (u64)s_b_5_39 */
    auto s_b_5_40 = emitter.zx(s_b_5_39, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_41 = s_b_5_36+s_b_5_40 */
    auto s_b_5_41 = emitter.add(s_b_5_36, s_b_5_40);
    /* execute.simd:193 [D] s_b_5_42: sym_5274_0_total = s_b_5_41, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5274_0_total, s_b_5_41);
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
    /* execute.simd:202 [F] s_b_7_0=sym_5271_3_parameter_inst.rn (const) */
    /* execute.simd:202 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:205 [F] s_b_7_2 = sym_5274_0_total (const) uint64_t */
    uint64_t s_b_7_2 = CV_sym_5274_0_total;
    /* ???:4294967295 [F] s_b_7_3 = constant u8 0 (const) */
    /* execute.simd:205 [D] s_b_7_1[s_b_7_3] */
    auto s_b_7_4 = emitter.vector_extract(s_b_7_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [D] s_b_7_5 = (u64)s_b_7_4 */
    auto s_b_7_5 = emitter.zx(s_b_7_4, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_6 = s_b_7_2+s_b_7_5 */
    auto s_b_7_6 = emitter.add(emitter.const_u64(s_b_7_2), s_b_7_5);
    /* execute.simd:205 [D] s_b_7_7: sym_5274_0_total = s_b_7_6, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_7_6);
    /* ???:4294967295 [F] s_b_7_8 = constant u8 1 (const) */
    /* execute.simd:205 [D] s_b_7_1[s_b_7_8] */
    auto s_b_7_9 = emitter.vector_extract(s_b_7_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [D] s_b_7_10 = (u64)s_b_7_9 */
    auto s_b_7_10 = emitter.zx(s_b_7_9, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_11 = s_b_7_6+s_b_7_10 */
    auto s_b_7_11 = emitter.add(s_b_7_6, s_b_7_10);
    /* execute.simd:205 [D] s_b_7_12: sym_5274_0_total = s_b_7_11, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_7_11);
    /* ???:4294967295 [F] s_b_7_13 = constant u8 2 (const) */
    /* execute.simd:205 [D] s_b_7_1[s_b_7_13] */
    auto s_b_7_14 = emitter.vector_extract(s_b_7_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [D] s_b_7_15 = (u64)s_b_7_14 */
    auto s_b_7_15 = emitter.zx(s_b_7_14, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_16 = s_b_7_11+s_b_7_15 */
    auto s_b_7_16 = emitter.add(s_b_7_11, s_b_7_15);
    /* execute.simd:205 [D] s_b_7_17: sym_5274_0_total = s_b_7_16, dominates:  */
    emitter.store_local(DV_sym_5274_0_total, s_b_7_16);
    /* ???:4294967295 [F] s_b_7_18 = constant u8 3 (const) */
    /* execute.simd:205 [D] s_b_7_1[s_b_7_18] */
    auto s_b_7_19 = emitter.vector_extract(s_b_7_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [D] s_b_7_20 = (u64)s_b_7_19 */
    auto s_b_7_20 = emitter.zx(s_b_7_19, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_21 = s_b_7_16+s_b_7_20 */
    auto s_b_7_21 = emitter.add(s_b_7_16, s_b_7_20);
    /* execute.simd:205 [D] s_b_7_22: sym_5274_0_total = s_b_7_21, dominates: s_b_13_1 s_b_12_1 s_b_11_1  */
    emitter.store_local(DV_sym_5274_0_total, s_b_7_21);
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
    /* execute.simd:221 [F] s_b_11_0=sym_5271_3_parameter_inst.rd (const) */
    /* execute.simd:221 [D] s_b_11_1 = sym_5274_0_total uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_5274_0_total, emitter.context().types().u64());
    /* execute.simd:221 [D] s_b_11_2 = (u8)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u8());
    /* execute.simd:6117 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.simd:6117 [D] s_b_11_4: WriteRegBank 2:s_b_11_0 = s_b_11_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_3);
    /* execute.simd:6118 [F] s_b_11_5 = constant u64 0 (const) */
    /* execute.simd:6118 [F] s_b_11_6: WriteRegBank 3:s_b_11_0 = s_b_11_5 */
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
    /* execute.simd:225 [F] s_b_12_0=sym_5271_3_parameter_inst.rd (const) */
    /* execute.simd:225 [D] s_b_12_1 = sym_5274_0_total uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_5274_0_total, emitter.context().types().u64());
    /* execute.simd:225 [D] s_b_12_2 = (u16)s_b_12_1 */
    auto s_b_12_2 = emitter.truncate(s_b_12_1, emitter.context().types().u16());
    /* execute.simd:6124 [D] s_b_12_3 = (u64)s_b_12_2 */
    auto s_b_12_3 = emitter.zx(s_b_12_2, emitter.context().types().u64());
    /* execute.simd:6124 [D] s_b_12_4: WriteRegBank 2:s_b_12_0 = s_b_12_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_3);
    /* execute.simd:6125 [F] s_b_12_5 = constant u64 0 (const) */
    /* execute.simd:6125 [F] s_b_12_6: WriteRegBank 3:s_b_12_0 = s_b_12_5 */
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
    /* execute.simd:229 [F] s_b_13_0=sym_5271_3_parameter_inst.rd (const) */
    /* execute.simd:229 [D] s_b_13_1 = sym_5274_0_total uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_5274_0_total, emitter.context().types().u64());
    /* execute.simd:229 [D] s_b_13_2 = (u32)s_b_13_1 */
    auto s_b_13_2 = emitter.truncate(s_b_13_1, emitter.context().types().u32());
    /* execute.simd:6131 [D] s_b_13_3 = (u64)s_b_13_2 */
    auto s_b_13_3 = emitter.zx(s_b_13_2, emitter.context().types().u64());
    /* execute.simd:6131 [D] s_b_13_4: WriteRegBank 2:s_b_13_0 = s_b_13_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_13_3);
    /* execute.simd:6132 [F] s_b_13_5 = constant u64 0 (const) */
    /* execute.simd:6132 [F] s_b_13_6: WriteRegBank 3:s_b_13_0 = s_b_13_5 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_bcond(const aarch64_decode_a64_COND_B_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  if (insn.is_predicated) 
  {
    auto __predicate_taken = emitter.context().create_block();
    auto predicate_result = generate_predicate_a64_COND_B_IMM(insn, emitter);
    if (TRACE) 
    {
      auto __predicate_not_taken = emitter.context().create_block();
      emitter.branch(predicate_result, __predicate_taken, __predicate_not_taken);
      emitter.set_current_block(__predicate_not_taken);
      emitter.trace(captive::arch::dbt::el::TraceEvent::NOT_TAKEN);
      if (insn.end_of_block) 
      {
        emitter.inc_pc(emitter.const_u8(4));
      }
      emitter.jump(__exit_block);
    }
    else if (insn.end_of_block) 
    {
      auto __predicate_not_taken = emitter.context().create_block();
      emitter.branch(predicate_result, __predicate_taken, __predicate_not_taken);
      emitter.set_current_block(__predicate_not_taken);
      emitter.inc_pc(emitter.const_u8(4));
      emitter.jump(__exit_block);
    }
    else 
    {
      emitter.branch(predicate_result, __predicate_taken, __exit_block);
    }
    emitter.set_current_block(__predicate_taken);
  }
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:307 [D] s_b_0_0 = read_pc */
    auto s_b_0_0 = emitter.load_pc();
    /* execute.a64:307 [D] s_b_0_1 = (s64)s_b_0_0 */
    auto s_b_0_1 = emitter.reinterpret(s_b_0_0, emitter.context().types().s64());
    /* execute.a64:307 [F] s_b_0_2=sym_6053_3_parameter_inst.imms64 (const) */
    /* execute.a64:307 [D] s_b_0_3 = s_b_0_1+s_b_0_2 */
    auto s_b_0_3 = emitter.add(s_b_0_1, emitter.const_s64(insn.imms64));
    /* execute.a64:307 [D] s_b_0_4 = (u64)s_b_0_3 */
    auto s_b_0_4 = emitter.reinterpret(s_b_0_3, emitter.context().types().u64());
    /* execute.a64:307 [D] s_b_0_5 = write_pc */
    emitter.store_pc(s_b_0_4);
    /* ???:4294967295 [F] s_b_0_6: Return */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_bsl(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2224 [F] s_b_0_0=sym_6439_3_parameter_inst.Q (const) */
    /* execute.simd:2224 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2232 [F] s_b_1_0=sym_6439_3_parameter_inst.rd (const) */
    /* execute.simd:6172 [D] s_b_1_1 = ReadRegBank 2:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_1_2 = ReadRegBank 3:s_b_1_0 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:2233 [F] s_b_1_3=sym_6439_3_parameter_inst.rn (const) */
    /* execute.simd:6172 [D] s_b_1_4 = ReadRegBank 2:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_1_5 = ReadRegBank 3:s_b_1_3 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.simd:2234 [F] s_b_1_6=sym_6439_3_parameter_inst.rm (const) */
    /* execute.simd:6172 [D] s_b_1_7 = ReadRegBank 2:s_b_1_6 (u64) */
    auto s_b_1_7 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_7,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_1_8 = ReadRegBank 3:s_b_1_6 (u64) */
    auto s_b_1_8 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_1_8,emitter.const_u8(8));
    }
    /* execute.simd:2236 [F] s_b_1_9=sym_6439_3_parameter_inst.rd (const) */
    /* execute.simd:2236 [D] s_b_1_10 = s_b_1_7^s_b_1_4 */
    auto s_b_1_10 = emitter.bitwise_xor(s_b_1_7, s_b_1_4);
    /* execute.simd:2236 [D] s_b_1_11 = s_b_1_10&s_b_1_1 */
    auto s_b_1_11 = emitter.bitwise_and(s_b_1_10, s_b_1_1);
    /* execute.simd:2236 [D] s_b_1_12 = s_b_1_7^s_b_1_11 */
    auto s_b_1_12 = emitter.bitwise_xor(s_b_1_7, s_b_1_11);
    /* execute.simd:2236 [D] s_b_1_13 = s_b_1_8^s_b_1_5 */
    auto s_b_1_13 = emitter.bitwise_xor(s_b_1_8, s_b_1_5);
    /* execute.simd:2236 [D] s_b_1_14 = s_b_1_13&s_b_1_2 */
    auto s_b_1_14 = emitter.bitwise_and(s_b_1_13, s_b_1_2);
    /* execute.simd:2236 [D] s_b_1_15 = s_b_1_8^s_b_1_14 */
    auto s_b_1_15 = emitter.bitwise_xor(s_b_1_8, s_b_1_14);
    /* execute.simd:6145 [D] s_b_1_16: WriteRegBank 2:s_b_1_9 = s_b_1_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_12);
    /* execute.simd:6146 [D] s_b_1_17: WriteRegBank 3:s_b_1_9 = s_b_1_15 */
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
    /* execute.simd:2242 [F] s_b_3_0=sym_6439_3_parameter_inst.rd (const) */
    /* execute.simd:6167 [D] s_b_3_1 = ReadRegBank 7:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:2243 [F] s_b_3_2=sym_6439_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_3_3 = ReadRegBank 7:s_b_3_2 (u64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:2244 [F] s_b_3_4=sym_6439_3_parameter_inst.rm (const) */
    /* execute.simd:6167 [D] s_b_3_5 = ReadRegBank 7:s_b_3_4 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:2246 [F] s_b_3_6=sym_6439_3_parameter_inst.rd (const) */
    /* execute.simd:2246 [D] s_b_3_7 = s_b_3_5^s_b_3_3 */
    auto s_b_3_7 = emitter.bitwise_xor(s_b_3_5, s_b_3_3);
    /* execute.simd:2246 [D] s_b_3_8 = s_b_3_7&s_b_3_1 */
    auto s_b_3_8 = emitter.bitwise_and(s_b_3_7, s_b_3_1);
    /* execute.simd:2246 [D] s_b_3_9 = s_b_3_5^s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_xor(s_b_3_5, s_b_3_8);
    /* execute.simd:6138 [D] s_b_3_10: WriteRegBank 2:s_b_3_6 = s_b_3_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_9,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_9);
    /* execute.simd:6139 [F] s_b_3_11 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_3_12: WriteRegBank 3:s_b_3_6 = s_b_3_11 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_clz(const aarch64_decode_a64_DP_1S&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_54562_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_54672_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_7040_0_rn = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_7009_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2202 [F] s_b_0_0=sym_6998_3_parameter_inst.sf (const) */
    /* execute.a64:2202 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2657 [F] s_b_1_0=sym_6998_3_parameter_inst.rn (const) */
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
    /* execute.a64:2203 [D] s_b_1_7: sym_7009_0_rn = s_b_1_6, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_7009_0_rn, s_b_1_6);
    /* execute.a64:2204 [F] s_b_1_8 = constant u64 0 (const) */
    /* execute.a64:2204 [D] s_b_1_9 = s_b_1_6==s_b_1_8 */
    auto s_b_1_9 = emitter.cmp_eq(s_b_1_6, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2204 [D] s_b_1_10: If s_b_1_9: Jump b_4 else b_5 */
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
    /* execute.a64:2659 [F] s_b_3_0=sym_6998_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:2646 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_3_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_3_5 = ReadRegBank 1:s_b_3_0 (u32) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_3_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_3_6: Select s_b_3_3 ? s_b_3_4 : s_b_3_5 */
    captive::arch::dbt::el::Value *s_b_3_6;
    s_b_3_6 = (s_b_3_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_3_5);
    /* execute.a64:2659 [D] s_b_3_7 = (u64)s_b_3_6 */
    auto s_b_3_7 = emitter.zx(s_b_3_6, emitter.context().types().u64());
    /* execute.a64:2210 [D] s_b_3_8 = (u32)s_b_3_7 */
    auto s_b_3_8 = emitter.truncate(s_b_3_7, emitter.context().types().u32());
    /* execute.a64:2210 [D] s_b_3_9: sym_7040_0_rn = s_b_3_8, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_7040_0_rn, s_b_3_8);
    /* execute.a64:2211 [F] s_b_3_10 = constant u32 0 (const) */
    /* execute.a64:2211 [D] s_b_3_11 = s_b_3_8==s_b_3_10 */
    auto s_b_3_11 = emitter.cmp_eq(s_b_3_8, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2211 [D] s_b_3_12: If s_b_3_11: Jump b_6 else b_7 */
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
      emitter.branch(s_b_3_11, true_target, false_target);
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
        /* execute.a64:2691 [F] s_b_4_0=sym_6998_3_parameter_inst.rd (const) */
        /* execute.a64:2682 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
        /* execute.a64:2682 [F] s_b_4_2 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
        uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_4_4: If s_b_4_3: Jump b_2 else b_8 (const) */
        if (s_b_4_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_8;
          dynamic_block_queue.push(block_b_8);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2207 [D] s_b_5_0 = sym_7009_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_7009_0_rn, emitter.context().types().u64());
        /* execute.a64:2207 [D] s_b_5_1 = __builtin_clz64 */
        auto s_b_5_1 = emitter.clz(s_b_5_0);
        /* execute.a64:2207 [D] s_b_5_2 = (u64)s_b_5_1 */
        auto s_b_5_2 = (captive::arch::dbt::el::Value *)s_b_5_1;
        /* execute.a64:2691 [F] s_b_5_3=sym_6998_3_parameter_inst.rd (const) */
        /* execute.a64:2691 [D] s_b_5_4: sym_54562_3_parameter_value = s_b_5_2, dominates: s_b_9_1  */
        emitter.store_local(DV_sym_54562_3_parameter_value, s_b_5_2);
        /* execute.a64:2682 [F] s_b_5_5 = (u32)s_b_5_3 (const) */
        /* execute.a64:2682 [F] s_b_5_6 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
        uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_5_8: If s_b_5_7: Jump b_2 else b_9 (const) */
        if (s_b_5_7) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_9;
          dynamic_block_queue.push(block_b_9);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.a64:2693 [F] s_b_6_0=sym_6998_3_parameter_inst.rd (const) */
        /* execute.a64:2682 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
        /* execute.a64:2682 [F] s_b_6_2 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
        uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_6_4: If s_b_6_3: Jump b_2 else b_10 (const) */
        if (s_b_6_3) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_10;
          dynamic_block_queue.push(block_b_10);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.a64:2214 [D] s_b_7_0 = sym_7040_0_rn uint32_t */
        auto s_b_7_0 = emitter.load_local(DV_sym_7040_0_rn, emitter.context().types().u32());
        /* execute.a64:2214 [D] s_b_7_1 = __builtin_clz32 */
        auto s_b_7_1 = emitter.clz(s_b_7_0);
        /* execute.a64:2214 [D] s_b_7_2 = (u64)s_b_7_1 */
        auto s_b_7_2 = emitter.zx(s_b_7_1, emitter.context().types().u64());
        /* execute.a64:2693 [F] s_b_7_3=sym_6998_3_parameter_inst.rd (const) */
        /* execute.a64:2693 [D] s_b_7_4 = (u32)s_b_7_2 */
        auto s_b_7_4 = emitter.truncate(s_b_7_2, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_7_5 = (u64)s_b_7_4 */
        auto s_b_7_5 = emitter.zx(s_b_7_4, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_7_6: sym_54672_3_parameter_value = s_b_7_5, dominates: s_b_11_1  */
        emitter.store_local(DV_sym_54672_3_parameter_value, s_b_7_5);
        /* execute.a64:2682 [F] s_b_7_7 = (u32)s_b_7_3 (const) */
        /* execute.a64:2682 [F] s_b_7_8 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_7_9 = s_b_7_7==s_b_7_8 (const) */
        uint8_t s_b_7_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_7_10: If s_b_7_9: Jump b_2 else b_11 (const) */
        if (s_b_7_9) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.a64:2684 [F] s_b_8_0=sym_6998_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [F] s_b_8_1 = constant u64 40 (const) */
        /* execute.a64:2684 [F] s_b_8_2: WriteRegBank 0:s_b_8_0 = s_b_8_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)64ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)64ULL));
        /* execute.a64:0 [F] s_b_8_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.a64:2684 [F] s_b_9_0=sym_6998_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_9_1 = sym_54562_3_parameter_value uint64_t */
        auto s_b_9_1 = emitter.load_local(DV_sym_54562_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_9_2: WriteRegBank 0:s_b_9_0 = s_b_9_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_9_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_9_1);
        /* execute.a64:0 [F] s_b_9_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.a64:2684 [F] s_b_10_0=sym_6998_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [F] s_b_10_1 = constant u64 20 (const) */
        /* execute.a64:2684 [F] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)32ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)32ULL));
        /* execute.a64:0 [F] s_b_10_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* execute.a64:2684 [F] s_b_11_0=sym_6998_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_11_1 = sym_54672_3_parameter_value uint64_t */
        auto s_b_11_1 = emitter.load_local(DV_sym_54672_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_1);
        /* execute.a64:0 [F] s_b_11_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_crc32(const aarch64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_dup_gen(const aarch64_decode_a64_SIMD_COPY&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_9735_0_rlo = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_9688_0_element = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_56967_1__R_s_b_0_8 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:377 [F] s_b_0_0=sym_9679_3_parameter_inst.width (const) */
    /* execute.simd:377 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:377 [F] s_b_0_2 = constant u32 40 (const) */
    /* execute.simd:377 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.width) == (uint32_t)64ULL));
    /* execute.a64:2656 [F] s_b_0_4: If s_b_0_3: Jump b_13 else b_14 (const) */
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
    /* execute.simd:421 [F] s_b_1_0=sym_9679_3_parameter_inst.Q (const) */
    /* execute.simd:421 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:421 [F] s_b_1_2 = constant u32 1 (const) */
    /* execute.simd:421 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* execute.simd:421 [F] s_b_1_4: If s_b_1_3: Jump b_10 else b_12 (const) */
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
    /* execute.simd:382 [D] s_b_2_0 = sym_9688_0_element uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_9688_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_2_1 = constant u64 ff (const) */
    /* ???:4294967295 [D] s_b_2_2 = s_b_2_0&s_b_2_1 */
    auto s_b_2_2 = emitter.bitwise_and(s_b_2_0, emitter.const_u64((uint64_t)255ULL));
    /* execute.simd:382 [D] s_b_2_3: sym_9688_0_element = s_b_2_2, dominates:  */
    emitter.store_local(DV_sym_9688_0_element, s_b_2_2);
    /* execute.simd:383 [F] s_b_2_4 = constant u64 8 (const) */
    /* execute.simd:383 [D] s_b_2_5 = s_b_2_2<<s_b_2_4 */
    auto s_b_2_5 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)8ULL));
    /* execute.simd:383 [D] s_b_2_6 = s_b_2_2|s_b_2_5 */
    auto s_b_2_6 = emitter.bitwise_or(s_b_2_2, s_b_2_5);
    /* execute.simd:383 [F] s_b_2_7 = constant u64 10 (const) */
    /* execute.simd:383 [D] s_b_2_8 = s_b_2_2<<s_b_2_7 */
    auto s_b_2_8 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)16ULL));
    /* execute.simd:383 [D] s_b_2_9 = s_b_2_6|s_b_2_8 */
    auto s_b_2_9 = emitter.bitwise_or(s_b_2_6, s_b_2_8);
    /* execute.simd:383 [F] s_b_2_10 = constant u64 18 (const) */
    /* execute.simd:383 [D] s_b_2_11 = s_b_2_2<<s_b_2_10 */
    auto s_b_2_11 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)24ULL));
    /* execute.simd:383 [D] s_b_2_12 = s_b_2_9|s_b_2_11 */
    auto s_b_2_12 = emitter.bitwise_or(s_b_2_9, s_b_2_11);
    /* execute.simd:383 [F] s_b_2_13 = constant u64 20 (const) */
    /* execute.simd:383 [D] s_b_2_14 = s_b_2_2<<s_b_2_13 */
    auto s_b_2_14 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:383 [D] s_b_2_15 = s_b_2_12|s_b_2_14 */
    auto s_b_2_15 = emitter.bitwise_or(s_b_2_12, s_b_2_14);
    /* execute.simd:383 [F] s_b_2_16 = constant u64 28 (const) */
    /* execute.simd:383 [D] s_b_2_17 = s_b_2_2<<s_b_2_16 */
    auto s_b_2_17 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)40ULL));
    /* execute.simd:383 [D] s_b_2_18 = s_b_2_15|s_b_2_17 */
    auto s_b_2_18 = emitter.bitwise_or(s_b_2_15, s_b_2_17);
    /* execute.simd:383 [F] s_b_2_19 = constant u64 30 (const) */
    /* execute.simd:383 [D] s_b_2_20 = s_b_2_2<<s_b_2_19 */
    auto s_b_2_20 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)48ULL));
    /* execute.simd:383 [D] s_b_2_21 = s_b_2_18|s_b_2_20 */
    auto s_b_2_21 = emitter.bitwise_or(s_b_2_18, s_b_2_20);
    /* execute.simd:383 [F] s_b_2_22 = constant u64 38 (const) */
    /* execute.simd:383 [D] s_b_2_23 = s_b_2_2<<s_b_2_22 */
    auto s_b_2_23 = emitter.shl(s_b_2_2, emitter.const_u64((uint64_t)56ULL));
    /* execute.simd:383 [D] s_b_2_24 = s_b_2_21|s_b_2_23 */
    auto s_b_2_24 = emitter.bitwise_or(s_b_2_21, s_b_2_23);
    /* execute.simd:383 [D] s_b_2_25: sym_9735_0_rlo = s_b_2_24, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9735_0_rlo, s_b_2_24);
    /* execute.simd:0 [F] s_b_2_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_3: 
  {
    /* execute.simd:387 [D] s_b_3_0 = sym_9688_0_element uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_9688_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_3_1 = constant u64 ff (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0&s_b_3_1 */
    auto s_b_3_2 = emitter.bitwise_and(s_b_3_0, emitter.const_u64((uint64_t)255ULL));
    /* execute.simd:387 [D] s_b_3_3: sym_9688_0_element = s_b_3_2, dominates:  */
    emitter.store_local(DV_sym_9688_0_element, s_b_3_2);
    /* execute.simd:388 [F] s_b_3_4 = constant u64 8 (const) */
    /* execute.simd:388 [D] s_b_3_5 = s_b_3_2<<s_b_3_4 */
    auto s_b_3_5 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)8ULL));
    /* execute.simd:388 [D] s_b_3_6 = s_b_3_2|s_b_3_5 */
    auto s_b_3_6 = emitter.bitwise_or(s_b_3_2, s_b_3_5);
    /* execute.simd:388 [F] s_b_3_7 = constant u64 10 (const) */
    /* execute.simd:388 [D] s_b_3_8 = s_b_3_2<<s_b_3_7 */
    auto s_b_3_8 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)16ULL));
    /* execute.simd:388 [D] s_b_3_9 = s_b_3_6|s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_or(s_b_3_6, s_b_3_8);
    /* execute.simd:388 [F] s_b_3_10 = constant u64 18 (const) */
    /* execute.simd:388 [D] s_b_3_11 = s_b_3_2<<s_b_3_10 */
    auto s_b_3_11 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)24ULL));
    /* execute.simd:388 [D] s_b_3_12 = s_b_3_9|s_b_3_11 */
    auto s_b_3_12 = emitter.bitwise_or(s_b_3_9, s_b_3_11);
    /* execute.simd:388 [F] s_b_3_13 = constant u64 20 (const) */
    /* execute.simd:388 [D] s_b_3_14 = s_b_3_2<<s_b_3_13 */
    auto s_b_3_14 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:388 [D] s_b_3_15 = s_b_3_12|s_b_3_14 */
    auto s_b_3_15 = emitter.bitwise_or(s_b_3_12, s_b_3_14);
    /* execute.simd:388 [F] s_b_3_16 = constant u64 28 (const) */
    /* execute.simd:388 [D] s_b_3_17 = s_b_3_2<<s_b_3_16 */
    auto s_b_3_17 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)40ULL));
    /* execute.simd:388 [D] s_b_3_18 = s_b_3_15|s_b_3_17 */
    auto s_b_3_18 = emitter.bitwise_or(s_b_3_15, s_b_3_17);
    /* execute.simd:388 [F] s_b_3_19 = constant u64 30 (const) */
    /* execute.simd:388 [D] s_b_3_20 = s_b_3_2<<s_b_3_19 */
    auto s_b_3_20 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)48ULL));
    /* execute.simd:388 [D] s_b_3_21 = s_b_3_18|s_b_3_20 */
    auto s_b_3_21 = emitter.bitwise_or(s_b_3_18, s_b_3_20);
    /* execute.simd:388 [F] s_b_3_22 = constant u64 38 (const) */
    /* execute.simd:388 [D] s_b_3_23 = s_b_3_2<<s_b_3_22 */
    auto s_b_3_23 = emitter.shl(s_b_3_2, emitter.const_u64((uint64_t)56ULL));
    /* execute.simd:388 [D] s_b_3_24 = s_b_3_21|s_b_3_23 */
    auto s_b_3_24 = emitter.bitwise_or(s_b_3_21, s_b_3_23);
    /* execute.simd:388 [D] s_b_3_25: sym_9735_0_rlo = s_b_3_24, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9735_0_rlo, s_b_3_24);
    /* execute.simd:0 [F] s_b_3_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_4: 
  {
    /* execute.simd:392 [D] s_b_4_0 = sym_9688_0_element uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_9688_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_4_1 = constant u64 ffff (const) */
    /* ???:4294967295 [D] s_b_4_2 = s_b_4_0&s_b_4_1 */
    auto s_b_4_2 = emitter.bitwise_and(s_b_4_0, emitter.const_u64((uint64_t)65535ULL));
    /* execute.simd:392 [D] s_b_4_3: sym_9688_0_element = s_b_4_2, dominates:  */
    emitter.store_local(DV_sym_9688_0_element, s_b_4_2);
    /* execute.simd:393 [F] s_b_4_4 = constant u64 10 (const) */
    /* execute.simd:393 [D] s_b_4_5 = s_b_4_2<<s_b_4_4 */
    auto s_b_4_5 = emitter.shl(s_b_4_2, emitter.const_u64((uint64_t)16ULL));
    /* execute.simd:393 [D] s_b_4_6 = s_b_4_2|s_b_4_5 */
    auto s_b_4_6 = emitter.bitwise_or(s_b_4_2, s_b_4_5);
    /* execute.simd:393 [F] s_b_4_7 = constant u64 20 (const) */
    /* execute.simd:393 [D] s_b_4_8 = s_b_4_2<<s_b_4_7 */
    auto s_b_4_8 = emitter.shl(s_b_4_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:393 [D] s_b_4_9 = s_b_4_6|s_b_4_8 */
    auto s_b_4_9 = emitter.bitwise_or(s_b_4_6, s_b_4_8);
    /* execute.simd:393 [F] s_b_4_10 = constant u64 30 (const) */
    /* execute.simd:393 [D] s_b_4_11 = s_b_4_2<<s_b_4_10 */
    auto s_b_4_11 = emitter.shl(s_b_4_2, emitter.const_u64((uint64_t)48ULL));
    /* execute.simd:393 [D] s_b_4_12 = s_b_4_9|s_b_4_11 */
    auto s_b_4_12 = emitter.bitwise_or(s_b_4_9, s_b_4_11);
    /* execute.simd:393 [D] s_b_4_13: sym_9735_0_rlo = s_b_4_12, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9735_0_rlo, s_b_4_12);
    /* execute.simd:0 [F] s_b_4_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_5: 
  {
    /* execute.simd:397 [D] s_b_5_0 = sym_9688_0_element uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_9688_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_5_1 = constant u64 ffff (const) */
    /* ???:4294967295 [D] s_b_5_2 = s_b_5_0&s_b_5_1 */
    auto s_b_5_2 = emitter.bitwise_and(s_b_5_0, emitter.const_u64((uint64_t)65535ULL));
    /* execute.simd:397 [D] s_b_5_3: sym_9688_0_element = s_b_5_2, dominates:  */
    emitter.store_local(DV_sym_9688_0_element, s_b_5_2);
    /* execute.simd:398 [F] s_b_5_4 = constant u64 10 (const) */
    /* execute.simd:398 [D] s_b_5_5 = s_b_5_2<<s_b_5_4 */
    auto s_b_5_5 = emitter.shl(s_b_5_2, emitter.const_u64((uint64_t)16ULL));
    /* execute.simd:398 [D] s_b_5_6 = s_b_5_2|s_b_5_5 */
    auto s_b_5_6 = emitter.bitwise_or(s_b_5_2, s_b_5_5);
    /* execute.simd:398 [F] s_b_5_7 = constant u64 20 (const) */
    /* execute.simd:398 [D] s_b_5_8 = s_b_5_2<<s_b_5_7 */
    auto s_b_5_8 = emitter.shl(s_b_5_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:398 [D] s_b_5_9 = s_b_5_6|s_b_5_8 */
    auto s_b_5_9 = emitter.bitwise_or(s_b_5_6, s_b_5_8);
    /* execute.simd:398 [F] s_b_5_10 = constant u64 30 (const) */
    /* execute.simd:398 [D] s_b_5_11 = s_b_5_2<<s_b_5_10 */
    auto s_b_5_11 = emitter.shl(s_b_5_2, emitter.const_u64((uint64_t)48ULL));
    /* execute.simd:398 [D] s_b_5_12 = s_b_5_9|s_b_5_11 */
    auto s_b_5_12 = emitter.bitwise_or(s_b_5_9, s_b_5_11);
    /* execute.simd:398 [D] s_b_5_13: sym_9735_0_rlo = s_b_5_12, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9735_0_rlo, s_b_5_12);
    /* execute.simd:0 [F] s_b_5_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_6: 
  {
    /* execute.simd:402 [D] s_b_6_0 = sym_9688_0_element uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_9688_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_6_2 = s_b_6_0&s_b_6_1 */
    auto s_b_6_2 = emitter.bitwise_and(s_b_6_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.simd:402 [D] s_b_6_3: sym_9688_0_element = s_b_6_2, dominates:  */
    emitter.store_local(DV_sym_9688_0_element, s_b_6_2);
    /* execute.simd:403 [F] s_b_6_4 = constant u64 20 (const) */
    /* execute.simd:403 [D] s_b_6_5 = s_b_6_2<<s_b_6_4 */
    auto s_b_6_5 = emitter.shl(s_b_6_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:403 [D] s_b_6_6 = s_b_6_2|s_b_6_5 */
    auto s_b_6_6 = emitter.bitwise_or(s_b_6_2, s_b_6_5);
    /* execute.simd:403 [D] s_b_6_7: sym_9735_0_rlo = s_b_6_6, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9735_0_rlo, s_b_6_6);
    /* execute.simd:0 [F] s_b_6_8: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_7: 
  {
    /* execute.simd:407 [D] s_b_7_0 = sym_9688_0_element uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_9688_0_element, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_7_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_7_2 = s_b_7_0&s_b_7_1 */
    auto s_b_7_2 = emitter.bitwise_and(s_b_7_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.simd:407 [D] s_b_7_3: sym_9688_0_element = s_b_7_2, dominates:  */
    emitter.store_local(DV_sym_9688_0_element, s_b_7_2);
    /* execute.simd:408 [F] s_b_7_4 = constant u64 20 (const) */
    /* execute.simd:408 [D] s_b_7_5 = s_b_7_2<<s_b_7_4 */
    auto s_b_7_5 = emitter.shl(s_b_7_2, emitter.const_u64((uint64_t)32ULL));
    /* execute.simd:408 [D] s_b_7_6 = s_b_7_2|s_b_7_5 */
    auto s_b_7_6 = emitter.bitwise_or(s_b_7_2, s_b_7_5);
    /* execute.simd:408 [D] s_b_7_7: sym_9735_0_rlo = s_b_7_6, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9735_0_rlo, s_b_7_6);
    /* execute.simd:0 [F] s_b_7_8: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_8: 
  {
    /* execute.simd:412 [D] s_b_8_0 = sym_9688_0_element uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_9688_0_element, emitter.context().types().u64());
    /* execute.simd:412 [D] s_b_8_1: sym_9735_0_rlo = s_b_8_0, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_9735_0_rlo, s_b_8_0);
    /* execute.simd:0 [F] s_b_8_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_9: 
  {
    /* execute.simd:416 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.simd:422 [F] s_b_10_0=sym_9679_3_parameter_inst.rd (const) */
    /* execute.simd:422 [D] s_b_10_1 = sym_9735_0_rlo uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_9735_0_rlo, emitter.context().types().u64());
    /* execute.simd:6145 [D] s_b_10_2: WriteRegBank 2:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_1);
    /* execute.simd:6146 [D] s_b_10_3: WriteRegBank 3:s_b_10_0 = s_b_10_1 */
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
    /* execute.simd:424 [F] s_b_12_0=sym_9679_3_parameter_inst.rd (const) */
    /* execute.simd:424 [D] s_b_12_1 = sym_9735_0_rlo uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_9735_0_rlo, emitter.context().types().u64());
    /* execute.simd:6138 [D] s_b_12_2: WriteRegBank 2:s_b_12_0 = s_b_12_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_1);
    /* execute.simd:6139 [F] s_b_12_3 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_12_4: WriteRegBank 3:s_b_12_0 = s_b_12_3 */
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
    /* execute.a64:2657 [F] s_b_13_0=sym_9679_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:2651 [F] s_b_13_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_13_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_13_5 = ReadRegBank 0:s_b_13_0 (u64) */
    auto s_b_13_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_13_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_13_6: Select s_b_13_3 ? s_b_13_4 : s_b_13_5 */
    captive::arch::dbt::el::Value *s_b_13_6;
    s_b_13_6 = (s_b_13_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_13_5);
    /* execute.a64:2657 [D] s_b_13_7: sym_56967_1__R_s_b_0_8 = s_b_13_6, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_56967_1__R_s_b_0_8, s_b_13_6);
    /* execute.a64:2657 [F] s_b_13_8: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2659 [F] s_b_14_0=sym_9679_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
    /* execute.a64:2646 [F] s_b_14_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_14_3 = s_b_14_1==s_b_14_2 (const) */
    uint8_t s_b_14_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_14_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_14_5 = ReadRegBank 1:s_b_14_0 (u32) */
    auto s_b_14_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_14_6: Select s_b_14_3 ? s_b_14_4 : s_b_14_5 */
    captive::arch::dbt::el::Value *s_b_14_6;
    s_b_14_6 = (s_b_14_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_14_5);
    /* execute.a64:2659 [D] s_b_14_7 = (u64)s_b_14_6 */
    auto s_b_14_7 = emitter.zx(s_b_14_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_14_8: sym_56967_1__R_s_b_0_8 = s_b_14_7, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_56967_1__R_s_b_0_8, s_b_14_7);
    /* execute.a64:2659 [F] s_b_14_9: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* execute.simd:377 [D] s_b_15_0 = sym_56967_1__R_s_b_0_8 uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_56967_1__R_s_b_0_8, emitter.context().types().u64());
    /* execute.simd:377 [D] s_b_15_1: sym_9688_0_element = s_b_15_0, dominates: s_b_6_0 s_b_5_0 s_b_3_0 s_b_2_0 s_b_8_0 s_b_7_0 s_b_4_0  */
    emitter.store_local(DV_sym_9688_0_element, s_b_15_0);
    /* execute.simd:380 [F] s_b_15_2=sym_9679_3_parameter_inst.arrangement (const) */
    /* execute.simd:381 [F] s_b_15_3 = constant s32 0 (const) */
    /* execute.simd:386 [F] s_b_15_4 = constant s32 1 (const) */
    /* execute.simd:391 [F] s_b_15_5 = constant s32 2 (const) */
    /* execute.simd:396 [F] s_b_15_6 = constant s32 3 (const) */
    /* execute.simd:401 [F] s_b_15_7 = constant s32 4 (const) */
    /* execute.simd:406 [F] s_b_15_8 = constant s32 5 (const) */
    /* execute.simd:411 [F] s_b_15_9 = constant s32 6 (const) */
    /* execute.simd:380 [F] s_b_15_10: Switch s_b_15_2: < <todo> > def b_9 (const) -> b_6, b_5, b_3, b_2, b_9, b_8, b_7, b_4,  */
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
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fabd(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1647 [F] s_b_0_0=sym_10306_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1647 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1648 [F] s_b_1_0=sym_10306_3_parameter_inst.size (const) */
    /* execute.simd:1648 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:1648 [F] s_b_1_2 = constant u32 2 (const) */
    /* execute.simd:1648 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:1648 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:1660 [D] s_b_3_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:1660 [F] s_b_3_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1649 [F] s_b_4_0=sym_10306_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_4_1 = ReadRegBank 9:s_b_4_0 (f32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(4));
    }
    /* execute.simd:1650 [F] s_b_4_2=sym_10306_3_parameter_inst.rm (const) */
    /* execute.simd:6092 [D] s_b_4_3 = ReadRegBank 9:s_b_4_2 (f32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(4));
    }
    /* execute.simd:1652 [F] s_b_4_4=sym_10306_3_parameter_inst.rd (const) */
    /* execute.simd:1652 [D] s_b_4_5 = s_b_4_1-s_b_4_3 */
    auto s_b_4_5 = emitter.sub(s_b_4_1, s_b_4_3);
    /* execute.simd:1652 [D] s_b_4_6 = float_abs */
    auto s_b_4_6 = emitter.call(__captive_float_abs, s_b_4_5);
    /* execute.simd:6102 [D] s_b_4_7: WriteRegBank 9:s_b_4_4 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6);
    /* execute.simd:6103 [F] s_b_4_8 = constant u32 0 (const) */
    /* execute.simd:6103 [F] s_b_4_9: WriteRegBank 10:s_b_4_4 = s_b_4_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6104 [F] s_b_4_10 = constant u64 0 (const) */
    /* execute.simd:6104 [F] s_b_4_11: WriteRegBank 3:s_b_4_4 = s_b_4_10 */
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
    /* execute.simd:1653 [F] s_b_5_0=sym_10306_3_parameter_inst.size (const) */
    /* execute.simd:1653 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:1653 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.simd:1653 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:1653 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
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
    /* execute.simd:1654 [F] s_b_6_0=sym_10306_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_6_1 = ReadRegBank 11:s_b_6_0 (f64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1655 [F] s_b_6_2=sym_10306_3_parameter_inst.rm (const) */
    /* execute.simd:6097 [D] s_b_6_3 = ReadRegBank 11:s_b_6_2 (f64) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1657 [F] s_b_6_4=sym_10306_3_parameter_inst.rd (const) */
    /* execute.simd:1657 [D] s_b_6_5 = s_b_6_1-s_b_6_3 */
    auto s_b_6_5 = emitter.sub(s_b_6_1, s_b_6_3);
    /* execute.simd:1657 [D] s_b_6_6 = double_abs */
    auto s_b_6_6 = emitter.call(__captive_double_abs, s_b_6_5);
    /* execute.simd:6110 [D] s_b_6_7: WriteRegBank 11:s_b_6_4 = s_b_6_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6);
    /* execute.simd:6111 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:6111 [F] s_b_6_9: WriteRegBank 3:s_b_6_4 = s_b_6_8 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fcvtas_simd(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4507 [F] s_b_0_0=sym_10819_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4507 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4507 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.simd:4507 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:4507 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4508 [F] s_b_1_0=sym_10819_3_parameter_inst.size (const) */
    /* execute.simd:4508 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4508 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4508 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4508 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4516 [D] s_b_3_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4516 [F] s_b_3_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4510 [F] s_b_4_0=sym_10819_3_parameter_inst.rd (const) */
    /* execute.simd:4510 [F] s_b_4_1=sym_10819_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_4_2 = ReadRegBank 9:s_b_4_1 (f32) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_2,emitter.const_u8(4));
    }
    /* execute.simd:4510 [F] s_b_4_3 = constant u8 0 (const) */
    /* execute.simd:4510 [D] s_b_4_4 = __builtin_fcvt_f32_s32 */
    auto s_b_4_4 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:4510 [D] s_b_4_5 = (u32)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().u32());
    /* execute.simd:6131 [D] s_b_4_6 = (u64)s_b_4_5 */
    auto s_b_4_6 = emitter.zx(s_b_4_5, emitter.context().types().u64());
    /* execute.simd:6131 [D] s_b_4_7: WriteRegBank 2:s_b_4_0 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6);
    /* execute.simd:6132 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:6132 [F] s_b_4_9: WriteRegBank 3:s_b_4_0 = s_b_4_8 */
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
    /* execute.simd:4513 [F] s_b_5_0=sym_10819_3_parameter_inst.rd (const) */
    /* execute.simd:4513 [F] s_b_5_1=sym_10819_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_5_2 = ReadRegBank 11:s_b_5_1 (f64) */
    auto s_b_5_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_2,emitter.const_u8(8));
    }
    /* execute.simd:4513 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.simd:4513 [D] s_b_5_4 = __builtin_fcvt_f64_s64 */
    auto s_b_5_4 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:4513 [D] s_b_5_5 = (u64)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().u64());
    /* execute.simd:6138 [D] s_b_5_6: WriteRegBank 2:s_b_5_0 = s_b_5_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5);
    /* execute.simd:6139 [F] s_b_5_7 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_5_8: WriteRegBank 3:s_b_5_0 = s_b_5_7 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fmaxv(const aarch64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fmul_vector(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1310 [F] s_b_0_0=sym_12161_3_parameter_inst.Q (const) */
    /* execute.simd:1311 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:1321 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:1310 [F] s_b_0_3: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_3, b_2, b_1,  */
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
    /* execute.simd:1312 [F] s_b_2_0=sym_12161_3_parameter_inst.rn (const) */
    /* execute.simd:1312 [D] s_b_2_1 = ReadRegBank 12:s_b_2_0 (v2f32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1313 [F] s_b_2_2=sym_12161_3_parameter_inst.rm (const) */
    /* execute.simd:1313 [D] s_b_2_3 = ReadRegBank 12:s_b_2_2 (v2f32) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* execute.simd:1315 [D] s_b_2_4 = s_b_2_1*s_b_2_3 */
    auto s_b_2_4 = emitter.mul(s_b_2_1, s_b_2_3);
    /* execute.simd:1316 [F] s_b_2_5=sym_12161_3_parameter_inst.rd (const) */
    /* execute.simd:1316 [D] s_b_2_6: WriteRegBank 12:s_b_2_5 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4);
    /* execute.simd:1317 [F] s_b_2_7=sym_12161_3_parameter_inst.rd (const) */
    /* execute.simd:1317 [F] s_b_2_8 = constant u64 0 (const) */
    /* execute.simd:1317 [F] s_b_2_9: WriteRegBank 3:s_b_2_7 = s_b_2_8 */
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
    /* execute.simd:1322 [F] s_b_3_0=sym_12161_3_parameter_inst.size (const) */
    /* execute.simd:1323 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:1332 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:1322 [F] s_b_3_3: Switch s_b_3_0: < <todo> > def b_1 (const) -> b_5, b_4, b_1,  */
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
    /* execute.simd:1324 [F] s_b_4_0=sym_12161_3_parameter_inst.rn (const) */
    /* execute.simd:1324 [D] s_b_4_1 = ReadRegBank 13:s_b_4_0 (v4f32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:1325 [F] s_b_4_2=sym_12161_3_parameter_inst.rm (const) */
    /* execute.simd:1325 [D] s_b_4_3 = ReadRegBank 13:s_b_4_2 (v4f32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(16));
    }
    /* execute.simd:1327 [D] s_b_4_4 = s_b_4_1*s_b_4_3 */
    auto s_b_4_4 = emitter.mul(s_b_4_1, s_b_4_3);
    /* execute.simd:1328 [F] s_b_4_5=sym_12161_3_parameter_inst.rd (const) */
    /* execute.simd:1328 [D] s_b_4_6: WriteRegBank 13:s_b_4_5 = s_b_4_4 */
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
    /* execute.simd:1333 [F] s_b_5_0=sym_12161_3_parameter_inst.rn (const) */
    /* execute.simd:1333 [D] s_b_5_1 = ReadRegBank 14:s_b_5_0 (v2f64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1334 [F] s_b_5_2=sym_12161_3_parameter_inst.rm (const) */
    /* execute.simd:1334 [D] s_b_5_3 = ReadRegBank 14:s_b_5_2 (v2f64) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1336 [D] s_b_5_4 = s_b_5_1*s_b_5_3 */
    auto s_b_5_4 = emitter.mul(s_b_5_1, s_b_5_3);
    /* execute.simd:1337 [F] s_b_5_5=sym_12161_3_parameter_inst.rd (const) */
    /* execute.simd:1337 [D] s_b_5_6: WriteRegBank 14:s_b_5_5 = s_b_5_4 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_hint(const aarch64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ld2pi(const aarch64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_65413_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_65336_1__R_s_b_31_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64959_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_64996_3_parameter_rt;
  auto DV_sym_65047_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_64992_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64994_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_65002_3_parameter_lane;
  auto DV_sym_65013_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_65030_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_65064_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_65081_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_65098_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_65123_1_tmp_s_b_5_2;
  auto DV_sym_65126_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_65172_1__R_s_b_7_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_65191_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_65247_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13424_0_rt;
  uint8_t CV_sym_13412_0_lane;
  auto DV_sym_13389_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13383_3_parameter_inst.rn (const) */
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
    /* execute.simd:2441 [F] s_b_1_0 = sym_13412_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13412_0_lane;
    /* execute.simd:2441 [F] s_b_1_1=sym_13383_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2441 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2441 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2442 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2442 [F] s_b_2_1: sym_13424_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13424_0_rt = (uint8_t)0ULL;
    /* execute.simd:2442 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2448 [F] s_b_3_0=sym_13383_3_parameter_inst.rm (const) */
    /* execute.simd:2448 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2448 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2448 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2448 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2442 [F] s_b_4_0 = sym_13424_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13424_0_rt;
    /* execute.simd:2442 [F] s_b_4_1=sym_13383_3_parameter_inst.regcnt (const) */
    /* execute.simd:2442 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2442 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2443 [F] s_b_5_0=sym_13383_3_parameter_inst.arrangement (const) */
    /* execute.simd:2443 [F] s_b_5_1=sym_13383_3_parameter_inst.rt (const) */
    /* execute.simd:2443 [F] s_b_5_2 = sym_13424_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13424_0_rt;
    /* execute.simd:2443 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2443 [F] s_b_5_4 = sym_13412_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13412_0_lane;
    /* execute.simd:2443 [D] s_b_5_5 = sym_13389_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13389_0_address, emitter.context().types().u64());
    /* execute.simd:2443 [F] s_b_5_6: sym_64996_3_parameter_rt = s_b_5_3 (const), dominates: s_b_12_2 s_b_17_2 s_b_18_2 s_b_14_2 s_b_16_2 s_b_15_2 s_b_13_2  */
    CV_sym_64996_3_parameter_rt = s_b_5_3;
    /* execute.simd:2443 [F] s_b_5_7: sym_65002_3_parameter_lane = s_b_5_4 (const), dominates: s_b_12_5 s_b_17_5 s_b_18_5 s_b_14_5 s_b_16_5 s_b_15_5 s_b_13_5  */
    CV_sym_65002_3_parameter_lane = s_b_5_4;
    /* execute.simd:2443 [D] s_b_5_8: sym_64992_3_parameter_addr = s_b_5_5, dominates: s_b_12_0 s_b_17_0 s_b_18_0 s_b_14_0 s_b_16_0 s_b_15_0 s_b_13_0  */
    emitter.store_local(DV_sym_64992_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_65123_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_19_1  */
    CV_sym_65123_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_65126_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_65126_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3700 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3709 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3718 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3727 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3736 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3745 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3754 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3699 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_11 (const) -> b_12, b_17, b_18, b_14, b_11, b_16, b_15, b_13,  */
    switch (insn.arrangement) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_15;
      break;
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
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2441 [F] s_b_6_0 = sym_13412_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13412_0_lane;
    /* execute.simd:2441 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2441 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2441 [F] s_b_6_3: sym_13412_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13412_0_lane = s_b_6_2;
    /* execute.simd:2441 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2730 [F] s_b_7_0=sym_13383_3_parameter_inst.rn (const) */
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
    /* execute.simd:2452 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2452 [D] s_b_8_1 = sym_13389_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_13389_0_address, emitter.context().types().u64());
    /* execute.simd:2452 [D] s_b_8_2: sym_65191_3_parameter_value = s_b_8_1, dominates: s_b_22_0 s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_65191_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2733 [F] s_b_9_0=sym_13383_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_9_2: sym_64959_1__R_s_b_0_5 = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_64959_1__R_s_b_0_5, s_b_9_1);
    /* execute.a64:2733 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_31,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2436 [D] s_b_10_0 = sym_64959_1__R_s_b_0_5 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_64959_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2436 [D] s_b_10_1: sym_13389_0_address = s_b_10_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13389_0_address, s_b_10_0);
    /* execute.simd:2438 [F] s_b_10_2=sym_13383_3_parameter_inst.rt (const) */
    /* execute.simd:2438 [F] s_b_10_3 = constant u64 0 (const) */
    /* execute.simd:2438 [F] s_b_10_4 = constant u64 0 (const) */
    /* execute.simd:6145 [F] s_b_10_5: WriteRegBank 2:s_b_10_2 = s_b_10_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6146 [F] s_b_10_6: WriteRegBank 3:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2439 [F] s_b_10_7=sym_13383_3_parameter_inst.rt (const) */
    /* execute.simd:2439 [F] s_b_10_8 = (u32)s_b_10_7 (const) */
    /* execute.simd:2439 [F] s_b_10_9 = constant u32 1 (const) */
    /* execute.simd:2439 [F] s_b_10_10 = s_b_10_8+s_b_10_9 (const) */
    uint32_t s_b_10_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2439 [F] s_b_10_11 = (u8)s_b_10_10 (const) */
    /* execute.simd:2439 [F] s_b_10_12 = constant u64 0 (const) */
    /* execute.simd:2439 [F] s_b_10_13 = constant u64 0 (const) */
    /* execute.simd:6145 [F] s_b_10_14: WriteRegBank 2:s_b_10_11 = s_b_10_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6146 [F] s_b_10_15: WriteRegBank 3:s_b_10_11 = s_b_10_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2441 [F] s_b_10_16 = constant u8 0 (const) */
    /* execute.simd:2441 [F] s_b_10_17: sym_13412_0_lane = s_b_10_16 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13412_0_lane = (uint8_t)0ULL;
    /* execute.simd:2441 [F] s_b_10_18: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3764 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_11_1: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3702 [D] s_b_12_0 = sym_64992_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_64992_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 1 s_b_12_0 => sym_64994_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_64994_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(1));
    }
    /* execute.simd:3704 [F] s_b_12_2 = sym_64996_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_64996_3_parameter_rt;
    /* execute.simd:3704 [D] s_b_12_3 = ReadRegBank 15:s_b_12_2 (v8u8) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3705 [D] s_b_12_4 = sym_64994_0_mem_value uint8_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_64994_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3705 [F] s_b_12_5 = sym_65002_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_65002_3_parameter_lane;
    /* execute.simd:3705 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3705 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3706 [D] s_b_12_8: WriteRegBank 15:s_b_12_2 = s_b_12_7 */
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
    /* execute.simd:3711 [D] s_b_13_0 = sym_64992_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_64992_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 1 s_b_13_0 => sym_65013_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_65013_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(1));
    }
    /* execute.simd:3713 [F] s_b_13_2 = sym_64996_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_64996_3_parameter_rt;
    /* execute.simd:3713 [D] s_b_13_3 = ReadRegBank 16:s_b_13_2 (v16u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3714 [D] s_b_13_4 = sym_65013_0_mem_value uint8_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_65013_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3714 [F] s_b_13_5 = sym_65002_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_65002_3_parameter_lane;
    /* execute.simd:3714 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3714 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3715 [D] s_b_13_8: WriteRegBank 16:s_b_13_2 = s_b_13_7 */
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
    /* execute.simd:3720 [D] s_b_14_0 = sym_64992_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_64992_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 2 s_b_14_0 => sym_65030_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_65030_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(2));
    }
    /* execute.simd:3722 [F] s_b_14_2 = sym_64996_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_64996_3_parameter_rt;
    /* execute.simd:3722 [D] s_b_14_3 = ReadRegBank 17:s_b_14_2 (v4u16) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3723 [D] s_b_14_4 = sym_65030_0_mem_value uint16_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_65030_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3723 [F] s_b_14_5 = sym_65002_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_65002_3_parameter_lane;
    /* execute.simd:3723 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3723 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3724 [D] s_b_14_8: WriteRegBank 17:s_b_14_2 = s_b_14_7 */
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
    /* execute.simd:3729 [D] s_b_15_0 = sym_64992_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_64992_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_65047_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_65047_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3731 [F] s_b_15_2 = sym_64996_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_64996_3_parameter_rt;
    /* execute.simd:3731 [D] s_b_15_3 = ReadRegBank 18:s_b_15_2 (v8u16) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3732 [D] s_b_15_4 = sym_65047_0_mem_value uint16_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_65047_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3732 [F] s_b_15_5 = sym_65002_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_65002_3_parameter_lane;
    /* execute.simd:3732 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3732 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3733 [D] s_b_15_8: WriteRegBank 18:s_b_15_2 = s_b_15_7 */
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
    /* execute.simd:3738 [D] s_b_16_0 = sym_64992_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_64992_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 4 s_b_16_0 => sym_65064_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_65064_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(4));
    }
    /* execute.simd:3740 [F] s_b_16_2 = sym_64996_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_64996_3_parameter_rt;
    /* execute.simd:3740 [D] s_b_16_3 = ReadRegBank 19:s_b_16_2 (v2u32) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(8));
    }
    /* execute.simd:3741 [D] s_b_16_4 = sym_65064_0_mem_value uint32_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_65064_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3741 [F] s_b_16_5 = sym_65002_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_65002_3_parameter_lane;
    /* execute.simd:3741 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3741 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3742 [D] s_b_16_8: WriteRegBank 19:s_b_16_2 = s_b_16_7 */
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
    /* execute.simd:3747 [D] s_b_17_0 = sym_64992_3_parameter_addr uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_64992_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_65081_0_mem_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_65081_0_mem_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3749 [F] s_b_17_2 = sym_64996_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_2 = CV_sym_64996_3_parameter_rt;
    /* execute.simd:3749 [D] s_b_17_3 = ReadRegBank 20:s_b_17_2 (v4u32) */
    auto s_b_17_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_3,emitter.const_u8(16));
    }
    /* execute.simd:3750 [D] s_b_17_4 = sym_65081_0_mem_value uint32_t */
    auto s_b_17_4 = emitter.load_local(DV_sym_65081_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3750 [F] s_b_17_5 = sym_65002_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_5 = CV_sym_65002_3_parameter_lane;
    /* execute.simd:3750 [F] s_b_17_6 = (s32)s_b_17_5 (const) */
    /* execute.simd:3750 [D] s_b_17_7 = s_b_17_3[s_b_17_6] <= s_b_17_4 */
    auto s_b_17_7 = emitter.vector_insert(s_b_17_3, emitter.const_s32(((int32_t)s_b_17_5)), s_b_17_4);
    /* execute.simd:3751 [D] s_b_17_8: WriteRegBank 20:s_b_17_2 = s_b_17_7 */
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
    /* execute.simd:3756 [D] s_b_18_0 = sym_64992_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_64992_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 8 s_b_18_0 => sym_65098_0_mem_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_65098_0_mem_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(8));
    }
    /* execute.simd:3758 [F] s_b_18_2 = sym_64996_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_2 = CV_sym_64996_3_parameter_rt;
    /* execute.simd:3758 [D] s_b_18_3 = ReadRegBank 21:s_b_18_2 (v2u64) */
    auto s_b_18_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_3,emitter.const_u8(16));
    }
    /* execute.simd:3759 [D] s_b_18_4 = sym_65098_0_mem_value uint64_t */
    auto s_b_18_4 = emitter.load_local(DV_sym_65098_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3759 [F] s_b_18_5 = sym_65002_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_5 = CV_sym_65002_3_parameter_lane;
    /* execute.simd:3759 [F] s_b_18_6 = (s32)s_b_18_5 (const) */
    /* execute.simd:3759 [D] s_b_18_7 = s_b_18_3[s_b_18_6] <= s_b_18_4 */
    auto s_b_18_7 = emitter.vector_insert(s_b_18_3, emitter.const_s32(((int32_t)s_b_18_5)), s_b_18_4);
    /* execute.simd:3760 [D] s_b_18_8: WriteRegBank 21:s_b_18_2 = s_b_18_7 */
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
    /* ???:4294967295 [D] s_b_19_0 = sym_65126_1_tmp_s_b_5_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_65126_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1 = sym_65123_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_19_1 = CV_sym_65123_1_tmp_s_b_5_2;
    /* execute.simd:2444 [F] s_b_19_2=sym_13383_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_19_3 = (u64)s_b_19_2 (const) */
    /* ???:4294967295 [D] s_b_19_4 = s_b_19_0+s_b_19_3 */
    auto s_b_19_4 = emitter.add(s_b_19_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2444 [D] s_b_19_5: sym_13389_0_address = s_b_19_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13389_0_address, s_b_19_4);
    /* execute.simd:2442 [F] s_b_19_6 = constant u8 1 (const) */
    /* execute.simd:2442 [F] s_b_19_7 = s_b_19_1+s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(s_b_19_1 + (uint8_t)1ULL));
    /* execute.simd:2442 [F] s_b_19_8: sym_13424_0_rt = s_b_19_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13424_0_rt = s_b_19_7;
    /* execute.simd:2442 [F] s_b_19_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2733 [F] s_b_20_0=sym_13383_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_20_2: sym_65172_1__R_s_b_7_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_65172_1__R_s_b_7_5, s_b_20_1);
    /* execute.a64:2733 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_36,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2449 [D] s_b_21_0 = sym_65172_1__R_s_b_7_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_65172_1__R_s_b_7_5, emitter.context().types().u64());
    /* execute.simd:2449 [F] s_b_21_1=sym_13383_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_21_2 = (u32)s_b_21_1 (const) */
    /* execute.a64:2651 [F] s_b_21_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_21_4 = s_b_21_2==s_b_21_3 (const) */
    uint8_t s_b_21_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_21_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_21_6 = ReadRegBank 0:s_b_21_1 (u64) */
    auto s_b_21_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_21_7: Select s_b_21_4 ? s_b_21_5 : s_b_21_6 */
    captive::arch::dbt::el::Value *s_b_21_7;
    s_b_21_7 = (s_b_21_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_21_6);
    /* execute.simd:2449 [D] s_b_21_8 = s_b_21_0+s_b_21_7 */
    auto s_b_21_8 = emitter.add(s_b_21_0, s_b_21_7);
    /* execute.simd:2449 [D] s_b_21_9: sym_13389_0_address = s_b_21_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_13389_0_address, s_b_21_8);
    /* execute.simd:2449 [F] s_b_21_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_8,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2747 [D] s_b_22_0 = sym_65191_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_65191_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_22_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_22_2 = s_b_22_0&s_b_22_1 */
    auto s_b_22_2 = emitter.bitwise_and(s_b_22_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_22_3: sym_65191_3_parameter_value = s_b_22_2, dominates: s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_65191_3_parameter_value, s_b_22_2);
    /* execute.a64:2747 [F] s_b_22_4: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2750 [F] s_b_23_0=sym_13383_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_24_0 = sym_65191_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_65191_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_24_1: sym_65413_3_parameter_value = s_b_24_0, dominates: s_b_37_0 s_b_38_0 s_b_39_0  */
    emitter.store_local(DV_sym_65413_3_parameter_value, s_b_24_0);
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
    /* execute.a64:2753 [F] s_b_25_0=sym_13383_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_25_1 = sym_65191_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_65191_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1,emitter.const_u8(8));
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_28_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_28_1: sym_65247_1__R_s_b_12_0 = s_b_28_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_65247_1__R_s_b_12_0, s_b_28_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_29_1: sym_65247_1__R_s_b_12_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_65247_1__R_s_b_12_0, s_b_29_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_30_1: sym_65247_1__R_s_b_12_0 = s_b_30_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_65247_1__R_s_b_12_0, s_b_30_0);
    /* execute.a64:2707 [F] s_b_30_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_28, b_29, b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2731 [D] s_b_31_0 = sym_65247_1__R_s_b_12_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_65247_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_31_1: sym_64959_1__R_s_b_0_5 = s_b_31_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_64959_1__R_s_b_0_5, s_b_31_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_33_1: sym_65336_1__R_s_b_31_0 = s_b_33_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_65336_1__R_s_b_31_0, s_b_33_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_34_1: sym_65336_1__R_s_b_31_0 = s_b_34_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_65336_1__R_s_b_31_0, s_b_34_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_35_1: sym_65336_1__R_s_b_31_0 = s_b_35_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_65336_1__R_s_b_31_0, s_b_35_0);
    /* execute.a64:2707 [F] s_b_35_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_33, b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2731 [D] s_b_36_0 = sym_65336_1__R_s_b_31_0 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_65336_1__R_s_b_31_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_36_1: sym_65172_1__R_s_b_7_5 = s_b_36_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_65172_1__R_s_b_7_5, s_b_36_0);
    /* execute.a64:2731 [F] s_b_36_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_24,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2715 [D] s_b_37_0 = sym_65413_3_parameter_value uint64_t */
    auto s_b_37_0 = emitter.load_local(DV_sym_65413_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_37_1: WriteReg 20 = s_b_37_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_37_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_37_0);
    /* execute.a64:2715 [F] s_b_37_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_42,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2718 [D] s_b_38_0 = sym_65413_3_parameter_value uint64_t */
    auto s_b_38_0 = emitter.load_local(DV_sym_65413_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_38_1: WriteReg 20 = s_b_38_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_38_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_38_0);
    /* execute.a64:2718 [F] s_b_38_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_42,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2720 [D] s_b_39_0 = sym_65413_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_65413_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_39_1: WriteReg 21 = s_b_39_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_39_0, emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldaxp(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_13971_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_72919_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_72522_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_72745_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_72551_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_72948_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_73374_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_72654_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_73722_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_72873_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_73271_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_72725_1_tmp_s_b_1_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_73850_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_74656_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_74374_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75870_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_75936_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13965_3_parameter_inst.rn (const) */
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
    /* execute.a64:831 [D] s_b_1_0 = sym_13971_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_13971_0_address, emitter.context().types().u64());
    /* execute.a64:831 [D] s_b_1_1: sym_72551_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_72551_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2: sym_72725_1_tmp_s_b_1_0 = s_b_1_0, dominates: s_b_6_3  */
    emitter.store_local(DV_sym_72725_1_tmp_s_b_1_0, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_3 = Load 4 s_b_1_0 => sym_72654_0_data32 */
    auto s_b_1_3 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_72654_0_data32, s_b_1_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_3, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_1_4 = sym_72654_0_data32 uint32_t */
    auto s_b_1_4 = emitter.load_local(DV_sym_72654_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_1_5 = (u64)s_b_1_4 */
    auto s_b_1_5 = emitter.zx(s_b_1_4, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_6=sym_13965_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_7 = (u32)s_b_1_5 */
    auto s_b_1_7 = emitter.truncate(s_b_1_5, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_8 = (u64)s_b_1_7 */
    auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_9: sym_74374_3_parameter_value = s_b_1_8, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_74374_3_parameter_value, s_b_1_8);
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
    /* execute.a64:834 [D] s_b_3_0 = sym_13971_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_13971_0_address, emitter.context().types().u64());
    /* execute.a64:834 [D] s_b_3_1: sym_72745_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_72745_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2: sym_72919_1_tmp_s_b_3_0 = s_b_3_0, dominates: s_b_7_3  */
    emitter.store_local(DV_sym_72919_1_tmp_s_b_3_0, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_3 = Load 8 s_b_3_0 => sym_72873_0_data64 */
    auto s_b_3_3 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_72873_0_data64, s_b_3_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_3, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_3_4 = sym_72873_0_data64 uint64_t */
    auto s_b_3_4 = emitter.load_local(DV_sym_72873_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_3_5=sym_13965_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_3_6: sym_74656_3_parameter_value = s_b_3_4, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_74656_3_parameter_value, s_b_3_4);
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
    /* execute.a64:2733 [F] s_b_4_0=sym_13965_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_4_2: sym_72522_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_72522_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2733 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:828 [D] s_b_5_0 = sym_72522_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_72522_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:828 [D] s_b_5_1: sym_13971_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_13971_0_address, s_b_5_0);
    /* execute.a64:830 [F] s_b_5_2=sym_13965_3_parameter_inst.size (const) */
    /* execute.a64:830 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:830 [F] s_b_5_4 = constant u32 2 (const) */
    /* execute.a64:830 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:830 [F] s_b_5_6: If s_b_5_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1723 [F] s_b_6_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_6_1 = sym_72551_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_72551_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* ???:4294967295 [D] s_b_6_3 = sym_72725_1_tmp_s_b_1_0 uint64_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_72725_1_tmp_s_b_1_0, emitter.context().types().u64());
    /* execute.a64:832 [F] s_b_6_4 = constant u64 4 (const) */
    /* execute.a64:832 [D] s_b_6_5 = s_b_6_3+s_b_6_4 */
    auto s_b_6_5 = emitter.add(s_b_6_3, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:832 [D] s_b_6_6: sym_73271_3_parameter_address = s_b_6_5, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_73271_3_parameter_address, s_b_6_5);
    /* ???:4294967295 [D] s_b_6_7 = Load 4 s_b_6_5 => sym_73374_0_data32 */
    auto s_b_6_7 = emitter.load_memory(s_b_6_5, emitter.context().types().u32());
    emitter.store_local(DV_sym_73374_0_data32, s_b_6_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_5, s_b_6_7, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_6_8 = sym_73374_0_data32 uint32_t */
    auto s_b_6_8 = emitter.load_local(DV_sym_73374_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_10=sym_13965_3_parameter_inst.rt2 (const) */
    /* execute.a64:2693 [D] s_b_6_11 = (u32)s_b_6_9 */
    auto s_b_6_11 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_13: sym_75870_3_parameter_value = s_b_6_12, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_75870_3_parameter_value, s_b_6_12);
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
    /* execute.a64:1723 [D] s_b_7_1 = sym_72745_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_72745_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* ???:4294967295 [D] s_b_7_3 = sym_72919_1_tmp_s_b_3_0 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_72919_1_tmp_s_b_3_0, emitter.context().types().u64());
    /* execute.a64:835 [F] s_b_7_4 = constant u64 8 (const) */
    /* execute.a64:835 [D] s_b_7_5 = s_b_7_3+s_b_7_4 */
    auto s_b_7_5 = emitter.add(s_b_7_3, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:835 [D] s_b_7_6: sym_73722_3_parameter_address = s_b_7_5, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_73722_3_parameter_address, s_b_7_5);
    /* ???:4294967295 [D] s_b_7_7 = Load 8 s_b_7_5 => sym_73850_0_data64 */
    auto s_b_7_7 = emitter.load_memory(s_b_7_5, emitter.context().types().u64());
    emitter.store_local(DV_sym_73850_0_data64, s_b_7_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_5, s_b_7_7, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_7_8 = sym_73850_0_data64 uint64_t */
    auto s_b_7_8 = emitter.load_local(DV_sym_73850_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_9=sym_13965_3_parameter_inst.rt2 (const) */
    /* execute.a64:2691 [D] s_b_7_10: sym_75936_3_parameter_value = s_b_7_8, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_75936_3_parameter_value, s_b_7_8);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_9_1: sym_72948_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_72948_1__R_s_b_7_0, s_b_9_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_10_1: sym_72948_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_72948_1__R_s_b_7_0, s_b_10_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_11_1: sym_72948_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_72948_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2707 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2731 [D] s_b_12_0 = sym_72948_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_72948_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_12_1: sym_72522_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_72522_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2731 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_6, b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1723 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_13_1 = sym_73271_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_73271_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7, b_19,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1723 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_14_1 = sym_73722_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_73722_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_16_0=sym_13965_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_74374_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_74374_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
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
    /* execute.a64:2684 [F] s_b_17_0=sym_13965_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_17_1 = sym_74656_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_74656_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
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
    /* execute.a64:2684 [F] s_b_18_0=sym_13965_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_18_1 = sym_75870_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_75870_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
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
    /* execute.a64:2684 [F] s_b_19_0=sym_13965_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_19_1 = sym_75936_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_75936_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldpi_simd(const aarch64_decode_a64_LS_REG_PAIR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14395_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87913_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87907_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87893_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_87878_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_87814_1__R_s_b_8_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87876_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88085_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_87935_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87900_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_87727_0_offset;
  auto DV_sym_88083_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87886_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_88120_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87707_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88114_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_87721_3_parameter_size;
  auto DV_sym_87732_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88107_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87758_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_88100_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_88093_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14389_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_13 else b_5 (const) */
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
    /* execute.simd:745 [D] s_b_1_0 = sym_14395_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14395_0_addr, emitter.context().types().u64());
    /* execute.simd:745 [F] s_b_1_1=sym_14389_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.simd:745 [D] s_b_1_3: sym_14395_0_addr = s_b_1_2, dominates: s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_14395_0_addr, s_b_1_2);
    /* execute.simd:745 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_6,  */
  fixed_block_b_2: 
  {
    /* execute.simd:748 [F] s_b_2_0=sym_14389_3_parameter_inst.opc (const) */
    /* execute.simd:748 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.simd:748 [F] s_b_2_2 = constant u32 2 (const) */
    /* execute.simd:748 [F] s_b_2_3 = s_b_2_1+s_b_2_2 (const) */
    uint32_t s_b_2_3 = ((uint32_t)(((uint32_t)insn.opc) + (uint32_t)2ULL));
    /* execute.simd:748 [F] s_b_2_4 = (u8)s_b_2_3 (const) */
    /* execute.simd:748 [D] s_b_2_5 = sym_14395_0_addr uint64_t */
    auto s_b_2_5 = emitter.load_local(DV_sym_14395_0_addr, emitter.context().types().u64());
    /* execute.simd:748 [F] s_b_2_6: sym_87721_3_parameter_size = s_b_2_4 (const), dominates: s_b_23_0  */
    CV_sym_87721_3_parameter_size = ((uint8_t)s_b_2_3);
    /* execute.simd:748 [D] s_b_2_7: sym_87732_3_parameter_addr = s_b_2_5, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_87732_3_parameter_addr, s_b_2_5);
    /* execute.simd:703 [F] s_b_2_8 = constant u32 1 (const) */
    /* execute.simd:703 [F] s_b_2_9 = (u32)s_b_2_4 (const) */
    /* execute.simd:703 [F] s_b_2_10 = s_b_2_8<<s_b_2_9 (const) */
    uint32_t s_b_2_10 = ((uint32_t)((uint32_t)1ULL << ((uint32_t)((uint8_t)s_b_2_3))));
    /* execute.simd:703 [F] s_b_2_11 = (u8)s_b_2_10 (const) */
    /* execute.simd:703 [F] s_b_2_12: sym_87727_0_offset = s_b_2_11 (const), dominates: s_b_23_2  */
    CV_sym_87727_0_offset = ((uint8_t)s_b_2_10);
    /* execute.simd:704 [D] s_b_2_13: sym_87876_3_parameter_addr = s_b_2_5, dominates: s_b_21_0 s_b_22_0 s_b_20_0 s_b_19_0 s_b_18_0  */
    emitter.store_local(DV_sym_87876_3_parameter_addr, s_b_2_5);
    /* execute.simd:3606 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:3613 [F] s_b_2_15 = constant s32 1 (const) */
    /* execute.simd:3620 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:3627 [F] s_b_2_17 = constant s32 3 (const) */
    /* execute.simd:3634 [F] s_b_2_18 = constant s32 4 (const) */
    /* execute.simd:3605 [F] s_b_2_19: Switch s_b_2_4: < <todo> > def b_23 (const) -> b_21, b_22, b_20, b_23, b_19, b_18,  */
    switch (((uint8_t)s_b_2_3)) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_20;
      break;
    default:
      goto fixed_block_b_23;
    }
  }
  /* b_7,  */
  fixed_block_b_3: 
  {
    /* execute.simd:751 [D] s_b_3_0 = sym_14395_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14395_0_addr, emitter.context().types().u64());
    /* execute.simd:751 [F] s_b_3_1=sym_14389_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:751 [D] s_b_3_3: sym_14395_0_addr = s_b_3_2, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_14395_0_addr, s_b_3_2);
    /* execute.simd:751 [F] s_b_3_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_7,  */
  fixed_block_b_4: 
  {
    /* execute.simd:754 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.simd:754 [D] s_b_4_1 = sym_14395_0_addr uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_14395_0_addr, emitter.context().types().u64());
    /* execute.simd:754 [D] s_b_4_2: sym_87758_3_parameter_value = s_b_4_1, dominates: s_b_8_0 s_b_10_0 s_b_11_1  */
    emitter.store_local(DV_sym_87758_3_parameter_value, s_b_4_1);
    /* execute.a64:2746 [F] s_b_4_3 = !s_b_4_0 (const) */
    uint8_t s_b_4_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_4_4: If s_b_4_3: Jump b_8 else b_9 (const) */
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
    /* execute.a64:2733 [F] s_b_5_0=sym_14389_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_5_2: sym_87707_1__R_s_b_0_5 = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_87707_1__R_s_b_0_5, s_b_5_1);
    /* execute.a64:2733 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_17,  */
  fixed_block_b_6: 
  {
    /* execute.simd:743 [D] s_b_6_0 = sym_87707_1__R_s_b_0_5 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_87707_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:743 [D] s_b_6_1: sym_14395_0_addr = s_b_6_0, dominates: s_b_1_0 s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_14395_0_addr, s_b_6_0);
    /* execute.simd:744 [F] s_b_6_2=sym_14389_3_parameter_inst.P (const) */
    /* execute.simd:744 [F] s_b_6_3: If s_b_6_2: Jump b_1 else b_2 (const) */
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
    /* execute.simd:750 [F] s_b_7_0=sym_14389_3_parameter_inst.P (const) */
    /* execute.simd:750 [F] s_b_7_1 = !s_b_7_0 (const) */
    uint8_t s_b_7_1 = !insn.P;
    /* execute.simd:750 [F] s_b_7_2: If s_b_7_1: Jump b_3 else b_4 (const) */
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
    /* execute.a64:2747 [D] s_b_8_0 = sym_87758_3_parameter_value uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_87758_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_8_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_8_2 = s_b_8_0&s_b_8_1 */
    auto s_b_8_2 = emitter.bitwise_and(s_b_8_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_8_3: sym_87758_3_parameter_value = s_b_8_2, dominates: s_b_10_0 s_b_11_1  */
    emitter.store_local(DV_sym_87758_3_parameter_value, s_b_8_2);
    /* execute.a64:2747 [F] s_b_8_4: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2750 [F] s_b_9_0=sym_14389_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:2750 [F] s_b_9_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2751 [D] s_b_10_0 = sym_87758_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_87758_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_10_1: sym_87935_3_parameter_value = s_b_10_0, dominates: s_b_24_0 s_b_25_0 s_b_26_0  */
    emitter.store_local(DV_sym_87935_3_parameter_value, s_b_10_0);
    /* execute.a64:2714 [F] s_b_10_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_10_3 = __builtin_get_feature */
    uint32_t s_b_10_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_10_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(s_b_10_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_10_6: If s_b_10_5: Jump b_24 else b_33 (const) */
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
    /* execute.a64:2753 [F] s_b_11_0=sym_14389_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_11_1 = sym_87758_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_87758_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1);
    /* execute.a64:2753 [F] s_b_11_3: Jump b_12 (const) */
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
    /* execute.a64:2701 [F] s_b_13_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_13_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(s_b_13_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_27 (const) */
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
    /* execute.a64:2702 [D] s_b_14_0 = ReadReg 20 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_14_1: sym_87814_1__R_s_b_8_0 = s_b_14_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_87814_1__R_s_b_8_0, s_b_14_0);
    /* execute.a64:2702 [F] s_b_14_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_27,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2705 [D] s_b_15_0 = ReadReg 20 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_15_1: sym_87814_1__R_s_b_8_0 = s_b_15_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_87814_1__R_s_b_8_0, s_b_15_0);
    /* execute.a64:2705 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_27,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2707 [D] s_b_16_0 = ReadReg 21 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_16_1: sym_87814_1__R_s_b_8_0 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_87814_1__R_s_b_8_0, s_b_16_0);
    /* execute.a64:2707 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_14, b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2731 [D] s_b_17_0 = sym_87814_1__R_s_b_8_0 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_87814_1__R_s_b_8_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_17_1: sym_87707_1__R_s_b_0_5 = s_b_17_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_87707_1__R_s_b_0_5, s_b_17_0);
    /* execute.a64:2731 [F] s_b_17_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_2,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3609 [D] s_b_18_0 = sym_87876_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_87876_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 1 s_b_18_0 => sym_87878_0_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_87878_0_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(1));
    }
    /* execute.simd:3610 [F] s_b_18_2=sym_14389_3_parameter_inst.rt (const) */
    /* execute.simd:3610 [D] s_b_18_3 = sym_87878_0_value uint8_t */
    auto s_b_18_3 = emitter.load_local(DV_sym_87878_0_value, emitter.context().types().u8());
    /* execute.simd:6117 [D] s_b_18_4 = (u64)s_b_18_3 */
    auto s_b_18_4 = emitter.zx(s_b_18_3, emitter.context().types().u64());
    /* execute.simd:6117 [D] s_b_18_5: WriteRegBank 2:s_b_18_2 = s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_4);
    /* execute.simd:6118 [F] s_b_18_6 = constant u64 0 (const) */
    /* execute.simd:6118 [F] s_b_18_7: WriteRegBank 3:s_b_18_2 = s_b_18_6 */
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
    /* execute.simd:3630 [D] s_b_19_0 = sym_87876_3_parameter_addr uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_87876_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_19_1 = Load 8 s_b_19_0 => sym_87900_0_value */
    auto s_b_19_1 = emitter.load_memory(s_b_19_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_87900_0_value, s_b_19_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_19_0, s_b_19_1, emitter.const_u8(8));
    }
    /* execute.simd:3631 [F] s_b_19_2=sym_14389_3_parameter_inst.rt (const) */
    /* execute.simd:3631 [D] s_b_19_3 = sym_87900_0_value uint64_t */
    auto s_b_19_3 = emitter.load_local(DV_sym_87900_0_value, emitter.context().types().u64());
    /* execute.simd:6138 [D] s_b_19_4: WriteRegBank 2:s_b_19_2 = s_b_19_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_19_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_19_3);
    /* execute.simd:6139 [F] s_b_19_5 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_19_6: WriteRegBank 3:s_b_19_2 = s_b_19_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_19_7: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_2,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3616 [D] s_b_20_0 = sym_87876_3_parameter_addr uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_87876_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_1 = Load 2 s_b_20_0 => sym_87886_0_value */
    auto s_b_20_1 = emitter.load_memory(s_b_20_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_87886_0_value, s_b_20_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_20_0, s_b_20_1, emitter.const_u8(2));
    }
    /* execute.simd:3617 [F] s_b_20_2=sym_14389_3_parameter_inst.rt (const) */
    /* execute.simd:3617 [D] s_b_20_3 = sym_87886_0_value uint16_t */
    auto s_b_20_3 = emitter.load_local(DV_sym_87886_0_value, emitter.context().types().u16());
    /* execute.simd:6124 [D] s_b_20_4 = (u64)s_b_20_3 */
    auto s_b_20_4 = emitter.zx(s_b_20_3, emitter.context().types().u64());
    /* execute.simd:6124 [D] s_b_20_5: WriteRegBank 2:s_b_20_2 = s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_20_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_20_4);
    /* execute.simd:6125 [F] s_b_20_6 = constant u64 0 (const) */
    /* execute.simd:6125 [F] s_b_20_7: WriteRegBank 3:s_b_20_2 = s_b_20_6 */
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
    /* execute.simd:3623 [D] s_b_21_0 = sym_87876_3_parameter_addr uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_87876_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_1 = Load 4 s_b_21_0 => sym_87893_0_value */
    auto s_b_21_1 = emitter.load_memory(s_b_21_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_87893_0_value, s_b_21_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_21_0, s_b_21_1, emitter.const_u8(4));
    }
    /* execute.simd:3624 [F] s_b_21_2=sym_14389_3_parameter_inst.rt (const) */
    /* execute.simd:3624 [D] s_b_21_3 = sym_87893_0_value uint32_t */
    auto s_b_21_3 = emitter.load_local(DV_sym_87893_0_value, emitter.context().types().u32());
    /* execute.simd:6131 [D] s_b_21_4 = (u64)s_b_21_3 */
    auto s_b_21_4 = emitter.zx(s_b_21_3, emitter.context().types().u64());
    /* execute.simd:6131 [D] s_b_21_5: WriteRegBank 2:s_b_21_2 = s_b_21_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_21_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_21_4);
    /* execute.simd:6132 [F] s_b_21_6 = constant u64 0 (const) */
    /* execute.simd:6132 [F] s_b_21_7: WriteRegBank 3:s_b_21_2 = s_b_21_6 */
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
    /* execute.simd:3638 [D] s_b_22_0 = sym_87876_3_parameter_addr uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_87876_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_22_1 = Load 8 s_b_22_0 => sym_87907_0_vl */
    auto s_b_22_1 = emitter.load_memory(s_b_22_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_87907_0_vl, s_b_22_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_22_0, s_b_22_1, emitter.const_u8(8));
    }
    /* execute.simd:3639 [F] s_b_22_2 = constant u64 8 (const) */
    /* execute.simd:3639 [D] s_b_22_3 = s_b_22_0+s_b_22_2 */
    auto s_b_22_3 = emitter.add(s_b_22_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_22_4 = Load 8 s_b_22_3 => sym_87913_0_vh */
    auto s_b_22_4 = emitter.load_memory(s_b_22_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_87913_0_vh, s_b_22_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_22_3, s_b_22_4, emitter.const_u8(8));
    }
    /* execute.simd:3640 [F] s_b_22_5=sym_14389_3_parameter_inst.rt (const) */
    /* execute.simd:3640 [D] s_b_22_6 = sym_87907_0_vl uint64_t */
    auto s_b_22_6 = emitter.load_local(DV_sym_87907_0_vl, emitter.context().types().u64());
    /* execute.simd:3640 [D] s_b_22_7 = sym_87913_0_vh uint64_t */
    auto s_b_22_7 = emitter.load_local(DV_sym_87913_0_vh, emitter.context().types().u64());
    /* execute.simd:6145 [D] s_b_22_8: WriteRegBank 2:s_b_22_5 = s_b_22_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_22_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_22_6);
    /* execute.simd:6146 [D] s_b_22_9: WriteRegBank 3:s_b_22_5 = s_b_22_7 */
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
    /* execute.simd:705 [F] s_b_23_0 = sym_87721_3_parameter_size (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_87721_3_parameter_size;
    /* execute.simd:705 [D] s_b_23_1 = sym_87732_3_parameter_addr uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_87732_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:705 [F] s_b_23_2 = sym_87727_0_offset (const) uint8_t */
    uint8_t s_b_23_2 = CV_sym_87727_0_offset;
    /* execute.simd:705 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* execute.simd:705 [D] s_b_23_4 = s_b_23_1+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_1, emitter.const_u64(((uint64_t)s_b_23_2)));
    /* execute.simd:705 [D] s_b_23_5: sym_88083_3_parameter_addr = s_b_23_4, dominates: s_b_32_0 s_b_31_0 s_b_30_0 s_b_29_0 s_b_28_0  */
    emitter.store_local(DV_sym_88083_3_parameter_addr, s_b_23_4);
    /* execute.simd:3606 [F] s_b_23_6 = constant s32 0 (const) */
    /* execute.simd:3613 [F] s_b_23_7 = constant s32 1 (const) */
    /* execute.simd:3620 [F] s_b_23_8 = constant s32 2 (const) */
    /* execute.simd:3627 [F] s_b_23_9 = constant s32 3 (const) */
    /* execute.simd:3634 [F] s_b_23_10 = constant s32 4 (const) */
    /* execute.simd:3605 [F] s_b_23_11: Switch s_b_23_0: < <todo> > def b_7 (const) -> b_32, b_31, b_30, b_29, b_28, b_7,  */
    switch (s_b_23_0) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_30;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_31;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_28;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_29;
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
    /* execute.a64:2715 [D] s_b_24_0 = sym_87935_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_87935_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_24_1: WriteReg 20 = s_b_24_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_24_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_24_0);
    /* execute.a64:2715 [F] s_b_24_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_33,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2718 [D] s_b_25_0 = sym_87935_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_87935_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_25_1: WriteReg 20 = s_b_25_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_25_0);
    /* execute.a64:2718 [F] s_b_25_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_33,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2720 [D] s_b_26_0 = sym_87935_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_87935_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_26_1: WriteReg 21 = s_b_26_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_26_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_26_0);
    /* execute.a64:2720 [F] s_b_26_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_27: 
  {
    /* execute.a64:3012 [F] s_b_27_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_27_1 = __builtin_get_feature */
    uint32_t s_b_27_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_27_2 = (u8)s_b_27_1 (const) */
    /* execute.a64:2704 [F] s_b_27_3 = (u32)s_b_27_2 (const) */
    /* execute.a64:2704 [F] s_b_27_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_27_5 = s_b_27_3==s_b_27_4 (const) */
    uint8_t s_b_27_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_27_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_27_6: If s_b_27_5: Jump b_15 else b_16 (const) */
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
    /* execute.simd:3609 [D] s_b_28_0 = sym_88083_3_parameter_addr uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_88083_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_28_1 = Load 1 s_b_28_0 => sym_88085_0_value */
    auto s_b_28_1 = emitter.load_memory(s_b_28_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_88085_0_value, s_b_28_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_28_0, s_b_28_1, emitter.const_u8(1));
    }
    /* execute.simd:3610 [F] s_b_28_2=sym_14389_3_parameter_inst.rt2 (const) */
    /* execute.simd:3610 [D] s_b_28_3 = sym_88085_0_value uint8_t */
    auto s_b_28_3 = emitter.load_local(DV_sym_88085_0_value, emitter.context().types().u8());
    /* execute.simd:6117 [D] s_b_28_4 = (u64)s_b_28_3 */
    auto s_b_28_4 = emitter.zx(s_b_28_3, emitter.context().types().u64());
    /* execute.simd:6117 [D] s_b_28_5: WriteRegBank 2:s_b_28_2 = s_b_28_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_28_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_28_4);
    /* execute.simd:6118 [F] s_b_28_6 = constant u64 0 (const) */
    /* execute.simd:6118 [F] s_b_28_7: WriteRegBank 3:s_b_28_2 = s_b_28_6 */
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
    /* execute.simd:3630 [D] s_b_29_0 = sym_88083_3_parameter_addr uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_88083_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_29_1 = Load 8 s_b_29_0 => sym_88107_0_value */
    auto s_b_29_1 = emitter.load_memory(s_b_29_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_88107_0_value, s_b_29_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_29_0, s_b_29_1, emitter.const_u8(8));
    }
    /* execute.simd:3631 [F] s_b_29_2=sym_14389_3_parameter_inst.rt2 (const) */
    /* execute.simd:3631 [D] s_b_29_3 = sym_88107_0_value uint64_t */
    auto s_b_29_3 = emitter.load_local(DV_sym_88107_0_value, emitter.context().types().u64());
    /* execute.simd:6138 [D] s_b_29_4: WriteRegBank 2:s_b_29_2 = s_b_29_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_29_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_29_3);
    /* execute.simd:6139 [F] s_b_29_5 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_29_6: WriteRegBank 3:s_b_29_2 = s_b_29_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_29_7: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_23,  */
  fixed_block_b_30: 
  {
    /* execute.simd:3616 [D] s_b_30_0 = sym_88083_3_parameter_addr uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_88083_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_30_1 = Load 2 s_b_30_0 => sym_88093_0_value */
    auto s_b_30_1 = emitter.load_memory(s_b_30_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_88093_0_value, s_b_30_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_30_0, s_b_30_1, emitter.const_u8(2));
    }
    /* execute.simd:3617 [F] s_b_30_2=sym_14389_3_parameter_inst.rt2 (const) */
    /* execute.simd:3617 [D] s_b_30_3 = sym_88093_0_value uint16_t */
    auto s_b_30_3 = emitter.load_local(DV_sym_88093_0_value, emitter.context().types().u16());
    /* execute.simd:6124 [D] s_b_30_4 = (u64)s_b_30_3 */
    auto s_b_30_4 = emitter.zx(s_b_30_3, emitter.context().types().u64());
    /* execute.simd:6124 [D] s_b_30_5: WriteRegBank 2:s_b_30_2 = s_b_30_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_30_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_30_4);
    /* execute.simd:6125 [F] s_b_30_6 = constant u64 0 (const) */
    /* execute.simd:6125 [F] s_b_30_7: WriteRegBank 3:s_b_30_2 = s_b_30_6 */
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
    /* execute.simd:3623 [D] s_b_31_0 = sym_88083_3_parameter_addr uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_88083_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1 = Load 4 s_b_31_0 => sym_88100_0_value */
    auto s_b_31_1 = emitter.load_memory(s_b_31_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_88100_0_value, s_b_31_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_31_0, s_b_31_1, emitter.const_u8(4));
    }
    /* execute.simd:3624 [F] s_b_31_2=sym_14389_3_parameter_inst.rt2 (const) */
    /* execute.simd:3624 [D] s_b_31_3 = sym_88100_0_value uint32_t */
    auto s_b_31_3 = emitter.load_local(DV_sym_88100_0_value, emitter.context().types().u32());
    /* execute.simd:6131 [D] s_b_31_4 = (u64)s_b_31_3 */
    auto s_b_31_4 = emitter.zx(s_b_31_3, emitter.context().types().u64());
    /* execute.simd:6131 [D] s_b_31_5: WriteRegBank 2:s_b_31_2 = s_b_31_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_31_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_31_4);
    /* execute.simd:6132 [F] s_b_31_6 = constant u64 0 (const) */
    /* execute.simd:6132 [F] s_b_31_7: WriteRegBank 3:s_b_31_2 = s_b_31_6 */
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
    /* execute.simd:3638 [D] s_b_32_0 = sym_88083_3_parameter_addr uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_88083_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_1 = Load 8 s_b_32_0 => sym_88114_0_vl */
    auto s_b_32_1 = emitter.load_memory(s_b_32_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_88114_0_vl, s_b_32_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_32_0, s_b_32_1, emitter.const_u8(8));
    }
    /* execute.simd:3639 [F] s_b_32_2 = constant u64 8 (const) */
    /* execute.simd:3639 [D] s_b_32_3 = s_b_32_0+s_b_32_2 */
    auto s_b_32_3 = emitter.add(s_b_32_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_32_4 = Load 8 s_b_32_3 => sym_88120_0_vh */
    auto s_b_32_4 = emitter.load_memory(s_b_32_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_88120_0_vh, s_b_32_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_32_3, s_b_32_4, emitter.const_u8(8));
    }
    /* execute.simd:3640 [F] s_b_32_5=sym_14389_3_parameter_inst.rt2 (const) */
    /* execute.simd:3640 [D] s_b_32_6 = sym_88114_0_vl uint64_t */
    auto s_b_32_6 = emitter.load_local(DV_sym_88114_0_vl, emitter.context().types().u64());
    /* execute.simd:3640 [D] s_b_32_7 = sym_88120_0_vh uint64_t */
    auto s_b_32_7 = emitter.load_local(DV_sym_88120_0_vh, emitter.context().types().u64());
    /* execute.simd:6145 [D] s_b_32_8: WriteRegBank 2:s_b_32_5 = s_b_32_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_32_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_32_6);
    /* execute.simd:6146 [D] s_b_32_9: WriteRegBank 3:s_b_32_5 = s_b_32_7 */
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
    /* execute.a64:3012 [F] s_b_33_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_33_1 = __builtin_get_feature */
    uint32_t s_b_33_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_33_2 = (u8)s_b_33_1 (const) */
    /* execute.a64:2717 [F] s_b_33_3 = (u32)s_b_33_2 (const) */
    /* execute.a64:2717 [F] s_b_33_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_33_5 = s_b_33_3==s_b_33_4 (const) */
    uint8_t s_b_33_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_33_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_33_6: If s_b_33_5: Jump b_25 else b_26 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldrb(const aarch64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_15235_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_97980_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_97564_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_98212_1__R_s_b_14_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_97598_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_97593_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_99047_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_97975_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_98156_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_99753_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_97789_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_97784_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_100241_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_99243_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_15229_3_parameter_inst.rn (const) */
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
    /* execute.a64:898 [D] s_b_1_0 = sym_15235_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15235_0_address, emitter.context().types().u64());
    /* execute.a64:898 [F] s_b_1_1=sym_15229_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:898 [D] s_b_1_4: sym_15235_0_address = s_b_1_3, dominates: s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15235_0_address, s_b_1_3);
    /* execute.a64:898 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_11,  */
  fixed_block_b_2: 
  {
    /* execute.a64:901 [F] s_b_2_0=sym_15229_3_parameter_inst.X (const) */
    /* execute.a64:901 [F] s_b_2_1: If s_b_2_0: Jump b_3 else b_5 (const) */
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
    /* execute.a64:902 [F] s_b_3_0=sym_15229_3_parameter_inst.L (const) */
    /* execute.a64:902 [F] s_b_3_1: If s_b_3_0: Jump b_6 else b_7 (const) */
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
    /* execute.a64:911 [F] s_b_4_0=sym_15229_3_parameter_inst.P (const) */
    /* execute.a64:911 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:911 [F] s_b_4_2: If s_b_4_1: Jump b_8 else b_9 (const) */
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
    /* execute.a64:908 [D] s_b_5_0 = sym_15235_0_address uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_15235_0_address, emitter.context().types().u64());
    /* execute.a64:908 [D] s_b_5_1: sym_97593_3_parameter_address = s_b_5_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_97593_3_parameter_address, s_b_5_0);
    /* ???:4294967295 [D] s_b_5_2 = Load 1 s_b_5_0 => sym_97598_0_data8 */
    auto s_b_5_2 = emitter.load_memory(s_b_5_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_97598_0_data8, s_b_5_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_5_0, s_b_5_2, emitter.const_u8(1));
    }
    /* execute.a64:1663 [D] s_b_5_3 = sym_97598_0_data8 uint8_t */
    auto s_b_5_3 = emitter.load_local(DV_sym_97598_0_data8, emitter.context().types().u8());
    /* execute.a64:1663 [D] s_b_5_4 = (u64)s_b_5_3 */
    auto s_b_5_4 = emitter.zx(s_b_5_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_5_5=sym_15229_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_5_6 = (u32)s_b_5_4 */
    auto s_b_5_6 = emitter.truncate(s_b_5_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_5_8: sym_99243_3_parameter_value = s_b_5_7, dominates: s_b_29_1  */
    emitter.store_local(DV_sym_99243_3_parameter_value, s_b_5_7);
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
    /* execute.a64:903 [D] s_b_6_0 = sym_15235_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_15235_0_address, emitter.context().types().u64());
    /* execute.a64:903 [D] s_b_6_1: sym_97784_3_parameter_address = s_b_6_0, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_97784_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 1 s_b_6_0 => sym_97789_0_data8 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_97789_0_data8, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(1));
    }
    /* execute.a64:1665 [D] s_b_6_3 = sym_97789_0_data8 uint8_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_97789_0_data8, emitter.context().types().u8());
    /* execute.a64:1665 [D] s_b_6_4 = (s8)s_b_6_3 */
    auto s_b_6_4 = emitter.reinterpret(s_b_6_3, emitter.context().types().s8());
    /* execute.a64:1665 [D] s_b_6_5 = (s64)s_b_6_4 */
    auto s_b_6_5 = emitter.sx(s_b_6_4, emitter.context().types().s64());
    /* execute.a64:1665 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.reinterpret(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_7=sym_15229_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_6_8 = (u32)s_b_6_6 */
    auto s_b_6_8 = emitter.truncate(s_b_6_6, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_10: sym_99753_3_parameter_value = s_b_6_9, dominates: s_b_30_1  */
    emitter.store_local(DV_sym_99753_3_parameter_value, s_b_6_9);
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
    /* execute.a64:905 [D] s_b_7_0 = sym_15235_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_15235_0_address, emitter.context().types().u64());
    /* execute.a64:905 [D] s_b_7_1: sym_97975_3_parameter_address = s_b_7_0, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_97975_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 1 s_b_7_0 => sym_97980_0_data8 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_97980_0_data8, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(1));
    }
    /* execute.a64:1667 [D] s_b_7_3 = sym_97980_0_data8 uint8_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_97980_0_data8, emitter.context().types().u8());
    /* execute.a64:1667 [D] s_b_7_4 = (s8)s_b_7_3 */
    auto s_b_7_4 = emitter.reinterpret(s_b_7_3, emitter.context().types().s8());
    /* execute.a64:1667 [D] s_b_7_5 = (s64)s_b_7_4 */
    auto s_b_7_5 = emitter.sx(s_b_7_4, emitter.context().types().s64());
    /* execute.a64:1667 [D] s_b_7_6 = (u64)s_b_7_5 */
    auto s_b_7_6 = emitter.reinterpret(s_b_7_5, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_7=sym_15229_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_7_8: sym_100241_3_parameter_value = s_b_7_6, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_100241_3_parameter_value, s_b_7_6);
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
    /* execute.a64:912 [D] s_b_8_0 = sym_15235_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_15235_0_address, emitter.context().types().u64());
    /* execute.a64:912 [F] s_b_8_1=sym_15229_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_8_2 = (u64)s_b_8_1 (const) */
    /* ???:4294967295 [D] s_b_8_3 = s_b_8_0+s_b_8_2 */
    auto s_b_8_3 = emitter.add(s_b_8_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:912 [D] s_b_8_4: sym_15235_0_address = s_b_8_3, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_15235_0_address, s_b_8_3);
    /* execute.a64:912 [F] s_b_8_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:915 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:915 [D] s_b_9_1 = sym_15235_0_address uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_15235_0_address, emitter.context().types().u64());
    /* execute.a64:915 [D] s_b_9_2: sym_98156_3_parameter_value = s_b_9_1, dominates: s_b_15_0 s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_98156_3_parameter_value, s_b_9_1);
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
    /* execute.a64:2733 [F] s_b_10_0=sym_15229_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_10_2: sym_97564_1__R_s_b_0_5 = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_97564_1__R_s_b_0_5, s_b_10_1);
    /* execute.a64:2733 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_24,  */
  fixed_block_b_11: 
  {
    /* execute.a64:895 [D] s_b_11_0 = sym_97564_1__R_s_b_0_5 uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_97564_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:895 [D] s_b_11_1: sym_15235_0_address = s_b_11_0, dominates: s_b_1_0 s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15235_0_address, s_b_11_0);
    /* execute.a64:897 [F] s_b_11_2=sym_15229_3_parameter_inst.P (const) */
    /* execute.a64:897 [F] s_b_11_3: If s_b_11_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:1723 [D] s_b_12_1 = sym_97593_3_parameter_address uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_97593_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_12_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_12_1);
    /* execute.a64:0 [F] s_b_12_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_6, b_30,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1723 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_13_1 = sym_97784_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_97784_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_31,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1723 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_14_1 = sym_97975_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_97975_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_14_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2747 [D] s_b_15_0 = sym_98156_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_98156_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_15_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_15_2 = s_b_15_0&s_b_15_1 */
    auto s_b_15_2 = emitter.bitwise_and(s_b_15_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_15_3: sym_98156_3_parameter_value = s_b_15_2, dominates: s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_98156_3_parameter_value, s_b_15_2);
    /* execute.a64:2747 [F] s_b_15_4: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_9, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2750 [F] s_b_16_0=sym_15229_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_17_0 = sym_98156_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_98156_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_17_1: sym_99047_3_parameter_value = s_b_17_0, dominates: s_b_25_0 s_b_26_0 s_b_27_0  */
    emitter.store_local(DV_sym_99047_3_parameter_value, s_b_17_0);
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
    /* execute.a64:2753 [F] s_b_18_0=sym_15229_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_18_1 = sym_98156_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_98156_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2702 [D] s_b_21_1: sym_98212_1__R_s_b_14_0 = s_b_21_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_98212_1__R_s_b_14_0, s_b_21_0);
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
    /* execute.a64:2705 [D] s_b_22_1: sym_98212_1__R_s_b_14_0 = s_b_22_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_98212_1__R_s_b_14_0, s_b_22_0);
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
    /* execute.a64:2707 [D] s_b_23_1: sym_98212_1__R_s_b_14_0 = s_b_23_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_98212_1__R_s_b_14_0, s_b_23_0);
    /* execute.a64:2707 [F] s_b_23_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2731 [D] s_b_24_0 = sym_98212_1__R_s_b_14_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_98212_1__R_s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_24_1: sym_97564_1__R_s_b_0_5 = s_b_24_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_97564_1__R_s_b_0_5, s_b_24_0);
    /* execute.a64:2731 [F] s_b_24_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_17,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2715 [D] s_b_25_0 = sym_99047_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_99047_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2718 [D] s_b_26_0 = sym_99047_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_99047_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2720 [D] s_b_27_0 = sym_99047_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_99047_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_29_0=sym_15229_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_29_1 = sym_99243_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_99243_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_30_0=sym_15229_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_30_1 = sym_99753_3_parameter_value uint64_t */
    auto s_b_30_1 = emitter.load_local(DV_sym_99753_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_31_0=sym_15229_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_31_1 = sym_100241_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_100241_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldrsw_lit(const aarch64_decode_a64_LOAD_REG_LIT&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldurh(const aarch64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_110075_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110097_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109879_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109995_1__R_s_b_13_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110163_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16162_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_16148_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_10 else b_8 (const) */
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
    /* execute.a64:1336 [D] s_b_1_0 = sym_16162_0_value uint16_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16162_0_value, emitter.context().types().u16());
    /* execute.a64:1336 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_2=sym_16148_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_3 = (u32)s_b_1_1 */
    auto s_b_1_3 = emitter.truncate(s_b_1_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_5: sym_110075_3_parameter_value = s_b_1_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_110075_3_parameter_value, s_b_1_4);
    /* execute.a64:2682 [F] s_b_1_6 = (u32)s_b_1_2 (const) */
    /* execute.a64:2682 [F] s_b_1_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_1_8 = s_b_1_6==s_b_1_7 (const) */
    uint8_t s_b_1_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_1_9: If s_b_1_8: Jump b_2 else b_15 (const) */
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
    /* execute.a64:1337 [F] s_b_3_0=sym_16148_3_parameter_inst.opc (const) */
    /* execute.a64:1337 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1337 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1337 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1337 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1338 [D] s_b_4_0 = sym_16162_0_value uint16_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_16162_0_value, emitter.context().types().u16());
    /* execute.a64:1338 [D] s_b_4_1 = (s16)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s16());
    /* execute.a64:1338 [D] s_b_4_2 = (s64)s_b_4_1 */
    auto s_b_4_2 = emitter.sx(s_b_4_1, emitter.context().types().s64());
    /* execute.a64:1338 [D] s_b_4_3 = (u64)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_4_4=sym_16148_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_4_5: sym_110097_3_parameter_value = s_b_4_3, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_110097_3_parameter_value, s_b_4_3);
    /* execute.a64:2682 [F] s_b_4_6 = (u32)s_b_4_4 (const) */
    /* execute.a64:2682 [F] s_b_4_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_4_8 = s_b_4_6==s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_4_9: If s_b_4_8: Jump b_2 else b_16 (const) */
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
    /* execute.a64:1339 [F] s_b_5_0=sym_16148_3_parameter_inst.opc (const) */
    /* execute.a64:1339 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1339 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:1339 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:1339 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1340 [D] s_b_6_0 = sym_16162_0_value uint16_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_16162_0_value, emitter.context().types().u16());
    /* execute.a64:1340 [D] s_b_6_1 = (s16)s_b_6_0 */
    auto s_b_6_1 = emitter.reinterpret(s_b_6_0, emitter.context().types().s16());
    /* execute.a64:1340 [D] s_b_6_2 = (s64)s_b_6_1 */
    auto s_b_6_2 = emitter.sx(s_b_6_1, emitter.context().types().s64());
    /* execute.a64:1340 [D] s_b_6_3 = (u64)s_b_6_2 */
    auto s_b_6_3 = emitter.reinterpret(s_b_6_2, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_4=sym_16148_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_6_5 = (u32)s_b_6_3 */
    auto s_b_6_5 = emitter.truncate(s_b_6_3, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_7: sym_110163_3_parameter_value = s_b_6_6, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_110163_3_parameter_value, s_b_6_6);
    /* execute.a64:2682 [F] s_b_6_8 = (u32)s_b_6_4 (const) */
    /* execute.a64:2682 [F] s_b_6_9 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_6_10 = s_b_6_8==s_b_6_9 (const) */
    uint8_t s_b_6_10 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_6_11: If s_b_6_10: Jump b_2 else b_17 (const) */
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
    /* execute.a64:1342 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1342 [F] s_b_7_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2733 [F] s_b_8_0=sym_16148_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_8_2: sym_109879_1__R_s_b_0_5 = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_109879_1__R_s_b_0_5, s_b_8_1);
    /* execute.a64:2733 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_14,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1329 [D] s_b_9_0 = sym_109879_1__R_s_b_0_5 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_109879_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1330 [F] s_b_9_1=sym_16148_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_9_2 = (u64)s_b_9_1 (const) */
    /* ???:4294967295 [D] s_b_9_3 = s_b_9_0+s_b_9_2 */
    auto s_b_9_3 = emitter.add(s_b_9_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* ???:4294967295 [D] s_b_9_4 = Load 2 s_b_9_3 => sym_16162_0_value */
    auto s_b_9_4 = emitter.load_memory(s_b_9_3, emitter.context().types().u16());
    emitter.store_local(DV_sym_16162_0_value, s_b_9_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_3, s_b_9_4, emitter.const_u8(2));
    }
    /* execute.a64:1335 [F] s_b_9_5=sym_16148_3_parameter_inst.opc (const) */
    /* execute.a64:1335 [F] s_b_9_6 = (u32)s_b_9_5 (const) */
    /* execute.a64:1335 [F] s_b_9_7 = constant u32 1 (const) */
    /* execute.a64:1335 [F] s_b_9_8 = s_b_9_6==s_b_9_7 (const) */
    uint8_t s_b_9_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:1335 [F] s_b_9_9: If s_b_9_8: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2701 [F] s_b_10_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_10_1 = __builtin_get_feature */
    uint32_t s_b_10_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(s_b_10_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_10_4: If s_b_10_3: Jump b_11 else b_18 (const) */
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
    /* execute.a64:2702 [D] s_b_11_0 = ReadReg 20 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_11_1: sym_109995_1__R_s_b_13_0 = s_b_11_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109995_1__R_s_b_13_0, s_b_11_0);
    /* execute.a64:2702 [F] s_b_11_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_18,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2705 [D] s_b_12_0 = ReadReg 20 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_12_1: sym_109995_1__R_s_b_13_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109995_1__R_s_b_13_0, s_b_12_0);
    /* execute.a64:2705 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2707 [D] s_b_13_0 = ReadReg 21 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_13_1: sym_109995_1__R_s_b_13_0 = s_b_13_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109995_1__R_s_b_13_0, s_b_13_0);
    /* execute.a64:2707 [F] s_b_13_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_11, b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2731 [D] s_b_14_0 = sym_109995_1__R_s_b_13_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_109995_1__R_s_b_13_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_14_1: sym_109879_1__R_s_b_0_5 = s_b_14_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_109879_1__R_s_b_0_5, s_b_14_0);
    /* execute.a64:2731 [F] s_b_14_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2684 [F] s_b_15_0=sym_16148_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_110075_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_110075_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
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
    /* execute.a64:2684 [F] s_b_16_0=sym_16148_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_110097_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_110097_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
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
    /* execute.a64:2684 [F] s_b_17_0=sym_16148_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_17_1 = sym_110163_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_110163_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
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
    /* execute.a64:3012 [F] s_b_18_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_18_1 = __builtin_get_feature */
    uint32_t s_b_18_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_18_2 = (u8)s_b_18_1 (const) */
    /* execute.a64:2704 [F] s_b_18_3 = (u32)s_b_18_2 (const) */
    /* execute.a64:2704 [F] s_b_18_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_18_5 = s_b_18_3==s_b_18_4 (const) */
    uint8_t s_b_18_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_18_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_18_6: If s_b_18_5: Jump b_12 else b_13 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_madd(const aarch64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_120601_1__R_s_b_4_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120757_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120667_1__R_s_b_12_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120609_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120678_1_tmp_s_b_12_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120727_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120779_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120538_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120675_1_tmp_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2343 [F] s_b_0_0=sym_16476_3_parameter_inst.sf (const) */
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
    /* execute.a64:2657 [F] s_b_1_0=sym_16476_3_parameter_inst.ra (const) */
    /* execute.a64:2651 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2651 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_1_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_1_5 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 */
    captive::arch::dbt::el::Value *s_b_1_6;
    s_b_1_6 = (s_b_1_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_1_5);
    /* execute.a64:2657 [D] s_b_1_7: sym_120538_1__R_s_b_0_4 = s_b_1_6, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_120538_1__R_s_b_0_4, s_b_1_6);
    /* execute.a64:2657 [F] s_b_1_8: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2659 [F] s_b_2_0=sym_16476_3_parameter_inst.ra (const) */
    /* execute.a64:2646 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2646 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_2_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_2_5 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_2_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_2_6: Select s_b_2_3 ? s_b_2_4 : s_b_2_5 */
    captive::arch::dbt::el::Value *s_b_2_6;
    s_b_2_6 = (s_b_2_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_2_5);
    /* execute.a64:2659 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_2_8: sym_120538_1__R_s_b_0_4 = s_b_2_7, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_120538_1__R_s_b_0_4, s_b_2_7);
    /* execute.a64:2659 [F] s_b_2_9: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2343 [D] s_b_3_0 = sym_120538_1__R_s_b_0_4 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_120538_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2343 [F] s_b_3_1=sym_16476_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_120609_1_tmp_s_b_4_0 = s_b_3_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_120609_1_tmp_s_b_4_0, s_b_3_0);
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
    /* execute.a64:2657 [F] s_b_4_0=sym_16476_3_parameter_inst.rn (const) */
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
    /* execute.a64:2657 [D] s_b_4_7: sym_120601_1__R_s_b_4_5 = s_b_4_6, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_120601_1__R_s_b_4_5, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_16476_3_parameter_inst.rn (const) */
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
    /* execute.a64:2659 [D] s_b_5_8: sym_120601_1__R_s_b_4_5 = s_b_5_7, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_120601_1__R_s_b_4_5, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_120609_1_tmp_s_b_4_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_120609_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2343 [D] s_b_6_1 = sym_120601_1__R_s_b_4_5 uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_120601_1__R_s_b_4_5, emitter.context().types().u64());
    /* execute.a64:2343 [F] s_b_6_2=sym_16476_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_6_3: sym_120675_1_tmp_s_b_12_0 = s_b_6_0, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_120675_1_tmp_s_b_12_0, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_4: sym_120678_1_tmp_s_b_12_1 = s_b_6_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_120678_1_tmp_s_b_12_1, s_b_6_1);
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
    /* execute.a64:2657 [F] s_b_7_0=sym_16476_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2651 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_7_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_7_5 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_7_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_7_6: Select s_b_7_3 ? s_b_7_4 : s_b_7_5 */
    captive::arch::dbt::el::Value *s_b_7_6;
    s_b_7_6 = (s_b_7_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_7_5);
    /* execute.a64:2657 [D] s_b_7_7: sym_120667_1__R_s_b_12_6 = s_b_7_6, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_120667_1__R_s_b_12_6, s_b_7_6);
    /* execute.a64:2657 [F] s_b_7_8: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2659 [F] s_b_8_0=sym_16476_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2646 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_8_5 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_8_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    captive::arch::dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2659 [D] s_b_8_7 = (u64)s_b_8_6 */
    auto s_b_8_7 = emitter.zx(s_b_8_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_8_8: sym_120667_1__R_s_b_12_6 = s_b_8_7, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_120667_1__R_s_b_12_6, s_b_8_7);
    /* execute.a64:2659 [F] s_b_8_9: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_120678_1_tmp_s_b_12_1 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_120678_1_tmp_s_b_12_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1 = sym_120675_1_tmp_s_b_12_0 uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_120675_1_tmp_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2343 [D] s_b_9_2 = sym_120667_1__R_s_b_12_6 uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_120667_1__R_s_b_12_6, emitter.context().types().u64());
    /* execute.a64:2343 [D] s_b_9_3 = s_b_9_0*s_b_9_2 */
    auto s_b_9_3 = emitter.mul(s_b_9_0, s_b_9_2);
    /* execute.a64:2343 [D] s_b_9_4 = s_b_9_1+s_b_9_3 */
    auto s_b_9_4 = emitter.add(s_b_9_1, s_b_9_3);
    /* execute.a64:2344 [F] s_b_9_5=sym_16476_3_parameter_inst.sf (const) */
    /* execute.a64:2344 [D] s_b_9_6: sym_120727_3_parameter_value = s_b_9_4, dominates: s_b_10_1 s_b_11_1  */
    emitter.store_local(DV_sym_120727_3_parameter_value, s_b_9_4);
    /* execute.a64:2690 [F] s_b_9_7: If s_b_9_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2691 [F] s_b_10_0=sym_16476_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_10_1 = sym_120727_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_120727_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_10_2: sym_120757_3_parameter_value = s_b_10_1, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_120757_3_parameter_value, s_b_10_1);
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
    /* execute.a64:2693 [F] s_b_11_0=sym_16476_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_11_1 = sym_120727_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_120727_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_2 = (u32)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_4: sym_120779_3_parameter_value = s_b_11_3, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_120779_3_parameter_value, s_b_11_3);
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
    /* execute.a64:2684 [F] s_b_13_0=sym_16476_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_13_1 = sym_120757_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_120757_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_14_0=sym_16476_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_120779_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_120779_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_msr_imm(const aarch64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:337 [F] s_b_0_0=sym_17635_3_parameter_inst.op1 (const) */
    /* execute.a64:337 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:337 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:337 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* execute.a64:337 [F] s_b_0_4=sym_17635_3_parameter_inst.op2 (const) */
    /* execute.a64:337 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:337 [F] s_b_0_6 = constant u32 5 (const) */
    /* execute.a64:337 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)5ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:337 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
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
    /* execute.a64:339 [F] s_b_1_0=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:339 [F] s_b_1_1 = (u8)s_b_1_0 (const) */
    /* execute.a64:2953 [F] s_b_1_2 = constant u32 1 (const) */
    /* execute.a64:2953 [F] s_b_1_3 = (u32)s_b_1_1 (const) */
    /* execute.a64:2953 [D] s_b_1_4 = __builtin_set_feature */
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
    /* execute.a64:340 [F] s_b_3_0=sym_17635_3_parameter_inst.op1 (const) */
    /* execute.a64:340 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:340 [F] s_b_3_2 = constant u32 3 (const) */
    /* execute.a64:340 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* execute.a64:340 [F] s_b_3_4=sym_17635_3_parameter_inst.op2 (const) */
    /* execute.a64:340 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:340 [F] s_b_3_6 = constant u32 6 (const) */
    /* execute.a64:340 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:340 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:342 [D] s_b_4_0 = ReadReg 5 (u8) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_4_0, emitter.const_u8(1));
    }
    /* execute.a64:342 [F] s_b_4_1=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:342 [F] s_b_4_2 = (u32)s_b_4_1 (const) */
    /* execute.a64:342 [F] s_b_4_3 = constant u32 8 (const) */
    /* execute.a64:342 [F] s_b_4_4 = s_b_4_2&s_b_4_3 (const) */
    uint32_t s_b_4_4 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)8ULL));
    /* execute.a64:342 [F] s_b_4_5 = constant u32 8 (const) */
    /* execute.a64:342 [F] s_b_4_6 = s_b_4_4==s_b_4_5 (const) */
    uint8_t s_b_4_6 = ((uint8_t)(s_b_4_4 == (uint32_t)8ULL));
    /* execute.a64:342 [D] s_b_4_7 = s_b_4_0|s_b_4_6 */
    auto s_b_4_7 = emitter.bitwise_or(s_b_4_0, emitter.const_u8(s_b_4_6));
    /* execute.a64:342 [D] s_b_4_8: WriteReg 5 = s_b_4_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), s_b_4_7, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), s_b_4_7);
    /* execute.a64:343 [D] s_b_4_9 = ReadReg 6 (u8) */
    auto s_b_4_9 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_4_9, emitter.const_u8(1));
    }
    /* execute.a64:343 [F] s_b_4_10=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:343 [F] s_b_4_11 = (u32)s_b_4_10 (const) */
    /* execute.a64:343 [F] s_b_4_12 = constant u32 4 (const) */
    /* execute.a64:343 [F] s_b_4_13 = s_b_4_11&s_b_4_12 (const) */
    uint32_t s_b_4_13 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)4ULL));
    /* execute.a64:343 [F] s_b_4_14 = constant u32 4 (const) */
    /* execute.a64:343 [F] s_b_4_15 = s_b_4_13==s_b_4_14 (const) */
    uint8_t s_b_4_15 = ((uint8_t)(s_b_4_13 == (uint32_t)4ULL));
    /* execute.a64:343 [D] s_b_4_16 = s_b_4_9|s_b_4_15 */
    auto s_b_4_16 = emitter.bitwise_or(s_b_4_9, emitter.const_u8(s_b_4_15));
    /* execute.a64:343 [D] s_b_4_17: WriteReg 6 = s_b_4_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), s_b_4_16, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), s_b_4_16);
    /* execute.a64:344 [D] s_b_4_18 = ReadReg 7 (u8) */
    auto s_b_4_18 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_4_18, emitter.const_u8(1));
    }
    /* execute.a64:344 [F] s_b_4_19=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:344 [F] s_b_4_20 = (u32)s_b_4_19 (const) */
    /* execute.a64:344 [F] s_b_4_21 = constant u32 2 (const) */
    /* execute.a64:344 [F] s_b_4_22 = s_b_4_20&s_b_4_21 (const) */
    uint32_t s_b_4_22 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)2ULL));
    /* execute.a64:344 [F] s_b_4_23 = constant u32 2 (const) */
    /* execute.a64:344 [F] s_b_4_24 = s_b_4_22==s_b_4_23 (const) */
    uint8_t s_b_4_24 = ((uint8_t)(s_b_4_22 == (uint32_t)2ULL));
    /* execute.a64:344 [D] s_b_4_25 = s_b_4_18|s_b_4_24 */
    auto s_b_4_25 = emitter.bitwise_or(s_b_4_18, emitter.const_u8(s_b_4_24));
    /* execute.a64:344 [D] s_b_4_26: WriteReg 7 = s_b_4_25 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), s_b_4_25, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), s_b_4_25);
    /* execute.a64:345 [D] s_b_4_27 = ReadReg 8 (u8) */
    auto s_b_4_27 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_4_27, emitter.const_u8(1));
    }
    /* execute.a64:345 [F] s_b_4_28=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:345 [F] s_b_4_29 = (u32)s_b_4_28 (const) */
    /* execute.a64:345 [F] s_b_4_30 = constant u32 1 (const) */
    /* execute.a64:345 [F] s_b_4_31 = s_b_4_29&s_b_4_30 (const) */
    uint32_t s_b_4_31 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)1ULL));
    /* execute.a64:345 [F] s_b_4_32 = constant u32 1 (const) */
    /* execute.a64:345 [F] s_b_4_33 = s_b_4_31==s_b_4_32 (const) */
    uint8_t s_b_4_33 = ((uint8_t)(s_b_4_31 == (uint32_t)1ULL));
    /* execute.a64:345 [D] s_b_4_34 = s_b_4_27|s_b_4_33 */
    auto s_b_4_34 = emitter.bitwise_or(s_b_4_27, emitter.const_u8(s_b_4_33));
    /* execute.a64:345 [D] s_b_4_35: WriteReg 8 = s_b_4_34 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), s_b_4_34, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), s_b_4_34);
    /* execute.a64:342 [F] s_b_4_36: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:346 [F] s_b_5_0=sym_17635_3_parameter_inst.op1 (const) */
    /* execute.a64:346 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:346 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:346 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* execute.a64:346 [F] s_b_5_4=sym_17635_3_parameter_inst.op2 (const) */
    /* execute.a64:346 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:346 [F] s_b_5_6 = constant u32 7 (const) */
    /* execute.a64:346 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:346 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:348 [D] s_b_6_0 = ReadReg 5 (u8) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_6_0, emitter.const_u8(1));
    }
    /* execute.a64:348 [F] s_b_6_1=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:348 [F] s_b_6_2 = (u32)s_b_6_1 (const) */
    /* execute.a64:348 [F] s_b_6_3 = constant u32 8 (const) */
    /* execute.a64:348 [F] s_b_6_4 = s_b_6_2&s_b_6_3 (const) */
    uint32_t s_b_6_4 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)8ULL));
    /* execute.a64:348 [F] s_b_6_5 = constant u32 8 (const) */
    /* execute.a64:348 [F] s_b_6_6 = s_b_6_4!=s_b_6_5 (const) */
    uint8_t s_b_6_6 = ((uint8_t)(s_b_6_4 != (uint32_t)8ULL));
    /* execute.a64:348 [D] s_b_6_7 = s_b_6_0&s_b_6_6 */
    auto s_b_6_7 = emitter.bitwise_and(s_b_6_0, emitter.const_u8(s_b_6_6));
    /* execute.a64:348 [D] s_b_6_8: WriteReg 5 = s_b_6_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), s_b_6_7, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), s_b_6_7);
    /* execute.a64:349 [D] s_b_6_9 = ReadReg 6 (u8) */
    auto s_b_6_9 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_6_9, emitter.const_u8(1));
    }
    /* execute.a64:349 [F] s_b_6_10=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:349 [F] s_b_6_11 = (u32)s_b_6_10 (const) */
    /* execute.a64:349 [F] s_b_6_12 = constant u32 4 (const) */
    /* execute.a64:349 [F] s_b_6_13 = s_b_6_11&s_b_6_12 (const) */
    uint32_t s_b_6_13 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)4ULL));
    /* execute.a64:349 [F] s_b_6_14 = constant u32 4 (const) */
    /* execute.a64:349 [F] s_b_6_15 = s_b_6_13!=s_b_6_14 (const) */
    uint8_t s_b_6_15 = ((uint8_t)(s_b_6_13 != (uint32_t)4ULL));
    /* execute.a64:349 [D] s_b_6_16 = s_b_6_9&s_b_6_15 */
    auto s_b_6_16 = emitter.bitwise_and(s_b_6_9, emitter.const_u8(s_b_6_15));
    /* execute.a64:349 [D] s_b_6_17: WriteReg 6 = s_b_6_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), s_b_6_16, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), s_b_6_16);
    /* execute.a64:350 [D] s_b_6_18 = ReadReg 7 (u8) */
    auto s_b_6_18 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_6_18, emitter.const_u8(1));
    }
    /* execute.a64:350 [F] s_b_6_19=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:350 [F] s_b_6_20 = (u32)s_b_6_19 (const) */
    /* execute.a64:350 [F] s_b_6_21 = constant u32 2 (const) */
    /* execute.a64:350 [F] s_b_6_22 = s_b_6_20&s_b_6_21 (const) */
    uint32_t s_b_6_22 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)2ULL));
    /* execute.a64:350 [F] s_b_6_23 = constant u32 2 (const) */
    /* execute.a64:350 [F] s_b_6_24 = s_b_6_22!=s_b_6_23 (const) */
    uint8_t s_b_6_24 = ((uint8_t)(s_b_6_22 != (uint32_t)2ULL));
    /* execute.a64:350 [D] s_b_6_25 = s_b_6_18&s_b_6_24 */
    auto s_b_6_25 = emitter.bitwise_and(s_b_6_18, emitter.const_u8(s_b_6_24));
    /* execute.a64:350 [D] s_b_6_26: WriteReg 7 = s_b_6_25 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), s_b_6_25, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), s_b_6_25);
    /* execute.a64:351 [D] s_b_6_27 = ReadReg 8 (u8) */
    auto s_b_6_27 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_6_27, emitter.const_u8(1));
    }
    /* execute.a64:351 [F] s_b_6_28=sym_17635_3_parameter_inst.crm (const) */
    /* execute.a64:351 [F] s_b_6_29 = (u32)s_b_6_28 (const) */
    /* execute.a64:351 [F] s_b_6_30 = constant u32 1 (const) */
    /* execute.a64:351 [F] s_b_6_31 = s_b_6_29&s_b_6_30 (const) */
    uint32_t s_b_6_31 = ((uint32_t)(((uint32_t)insn.crm) & (uint32_t)1ULL));
    /* execute.a64:351 [F] s_b_6_32 = constant u32 1 (const) */
    /* execute.a64:351 [F] s_b_6_33 = s_b_6_31!=s_b_6_32 (const) */
    uint8_t s_b_6_33 = ((uint8_t)(s_b_6_31 != (uint32_t)1ULL));
    /* execute.a64:351 [D] s_b_6_34 = s_b_6_27&s_b_6_33 */
    auto s_b_6_34 = emitter.bitwise_and(s_b_6_27, emitter.const_u8(s_b_6_33));
    /* execute.a64:351 [D] s_b_6_35: WriteReg 8 = s_b_6_34 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), s_b_6_34, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), s_b_6_34);
    /* execute.a64:352 [D] s_b_6_36 = trigger_irq */
    emitter.call(__captive_trigger_irq);
    /* execute.a64:348 [F] s_b_6_37: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:354 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:354 [F] s_b_7_1: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_not_simd(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:6057 [F] s_b_0_0=sym_19100_3_parameter_inst.Q (const) */
    /* execute.simd:6057 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:6057 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:6057 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:6057 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:6058 [F] s_b_1_0=sym_19100_3_parameter_inst.rd (const) */
    /* execute.simd:6058 [F] s_b_1_1=sym_19100_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:6058 [D] s_b_1_3 = ~s_b_1_2 */
    auto s_b_1_3 = emitter.bitwise_not(s_b_1_2);
    /* execute.simd:6138 [D] s_b_1_4: WriteRegBank 2:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3);
    /* execute.simd:6139 [F] s_b_1_5 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_1_6: WriteRegBank 3:s_b_1_0 = s_b_1_5 */
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
    /* execute.simd:6063 [F] s_b_3_0=sym_19100_3_parameter_inst.rn (const) */
    /* execute.simd:6172 [D] s_b_3_1 = ReadRegBank 2:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_3_2 = ReadRegBank 3:s_b_3_0 (u64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:6064 [F] s_b_3_3=sym_19100_3_parameter_inst.rd (const) */
    /* execute.simd:6064 [D] s_b_3_4 = ~s_b_3_1 */
    auto s_b_3_4 = emitter.bitwise_not(s_b_3_1);
    /* execute.simd:6064 [D] s_b_3_5 = ~s_b_3_2 */
    auto s_b_3_5 = emitter.bitwise_not(s_b_3_2);
    /* execute.simd:6145 [D] s_b_3_6: WriteRegBank 2:s_b_3_3 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:6146 [D] s_b_3_7: WriteRegBank 3:s_b_3_3 = s_b_3_5 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_prfm_reg(const aarch64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_rev32_simd(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:565 [F] s_b_0_0=sym_19885_3_parameter_inst.arrangement (const) */
    /* execute.simd:566 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:576 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:587 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:597 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:565 [F] s_b_0_5: Switch s_b_0_0: < <todo> > def b_6 (const) -> b_2, b_3, b_4, b_5, b_6,  */
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
    /* execute.simd:567 [F] s_b_2_0=sym_19885_3_parameter_inst.rn (const) */
    /* execute.simd:567 [D] s_b_2_1 = ReadRegBank 19:s_b_2_0 (v2u32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:569 [F] s_b_2_2 = constant s32 0 (const) */
    /* execute.simd:569 [D] s_b_2_1[s_b_2_2] */
    auto s_b_2_3 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:569 [D] s_b_2_4 = __builtin_bswap32 */
    auto s_b_2_4 = emitter.bswap(s_b_2_3);
    /* execute.simd:569 [F] s_b_2_5 = constant s32 0 (const) */
    /* execute.simd:569 [D] s_b_2_6 = s_b_2_1[s_b_2_5] <= s_b_2_4 */
    auto s_b_2_6 = emitter.vector_insert(s_b_2_1, emitter.const_s32((int32_t)0ULL), s_b_2_4);
    /* execute.simd:570 [F] s_b_2_7 = constant s32 1 (const) */
    /* execute.simd:570 [D] s_b_2_6[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_6, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:570 [D] s_b_2_9 = __builtin_bswap32 */
    auto s_b_2_9 = emitter.bswap(s_b_2_8);
    /* execute.simd:570 [F] s_b_2_10 = constant s32 1 (const) */
    /* execute.simd:570 [D] s_b_2_11 = s_b_2_6[s_b_2_10] <= s_b_2_9 */
    auto s_b_2_11 = emitter.vector_insert(s_b_2_6, emitter.const_s32((int32_t)1ULL), s_b_2_9);
    /* execute.simd:572 [F] s_b_2_12=sym_19885_3_parameter_inst.rd (const) */
    /* execute.simd:572 [D] s_b_2_13: WriteRegBank 19:s_b_2_12 = s_b_2_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_11,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_11);
    /* execute.simd:573 [F] s_b_2_14=sym_19885_3_parameter_inst.rd (const) */
    /* execute.simd:573 [F] s_b_2_15 = constant u64 0 (const) */
    /* execute.simd:573 [F] s_b_2_16: WriteRegBank 3:s_b_2_14 = s_b_2_15 */
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
    /* execute.simd:577 [F] s_b_3_0=sym_19885_3_parameter_inst.rn (const) */
    /* execute.simd:577 [D] s_b_3_1 = ReadRegBank 20:s_b_3_0 (v4u32) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:579 [F] s_b_3_2 = constant s32 0 (const) */
    /* execute.simd:579 [D] s_b_3_1[s_b_3_2] */
    auto s_b_3_3 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:579 [D] s_b_3_4 = __builtin_bswap32 */
    auto s_b_3_4 = emitter.bswap(s_b_3_3);
    /* execute.simd:579 [F] s_b_3_5 = constant s32 0 (const) */
    /* execute.simd:579 [D] s_b_3_6 = s_b_3_1[s_b_3_5] <= s_b_3_4 */
    auto s_b_3_6 = emitter.vector_insert(s_b_3_1, emitter.const_s32((int32_t)0ULL), s_b_3_4);
    /* execute.simd:580 [F] s_b_3_7 = constant s32 1 (const) */
    /* execute.simd:580 [D] s_b_3_6[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_6, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:580 [D] s_b_3_9 = __builtin_bswap32 */
    auto s_b_3_9 = emitter.bswap(s_b_3_8);
    /* execute.simd:580 [F] s_b_3_10 = constant s32 1 (const) */
    /* execute.simd:580 [D] s_b_3_11 = s_b_3_6[s_b_3_10] <= s_b_3_9 */
    auto s_b_3_11 = emitter.vector_insert(s_b_3_6, emitter.const_s32((int32_t)1ULL), s_b_3_9);
    /* execute.simd:581 [F] s_b_3_12 = constant s32 2 (const) */
    /* execute.simd:581 [D] s_b_3_11[s_b_3_12] */
    auto s_b_3_13 = emitter.vector_extract(s_b_3_11, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:581 [D] s_b_3_14 = __builtin_bswap32 */
    auto s_b_3_14 = emitter.bswap(s_b_3_13);
    /* execute.simd:581 [F] s_b_3_15 = constant s32 2 (const) */
    /* execute.simd:581 [D] s_b_3_16 = s_b_3_11[s_b_3_15] <= s_b_3_14 */
    auto s_b_3_16 = emitter.vector_insert(s_b_3_11, emitter.const_s32((int32_t)2ULL), s_b_3_14);
    /* execute.simd:582 [F] s_b_3_17 = constant s32 3 (const) */
    /* execute.simd:582 [D] s_b_3_16[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_16, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:582 [D] s_b_3_19 = __builtin_bswap32 */
    auto s_b_3_19 = emitter.bswap(s_b_3_18);
    /* execute.simd:582 [F] s_b_3_20 = constant s32 3 (const) */
    /* execute.simd:582 [D] s_b_3_21 = s_b_3_16[s_b_3_20] <= s_b_3_19 */
    auto s_b_3_21 = emitter.vector_insert(s_b_3_16, emitter.const_s32((int32_t)3ULL), s_b_3_19);
    /* execute.simd:584 [F] s_b_3_22=sym_19885_3_parameter_inst.rd (const) */
    /* execute.simd:584 [D] s_b_3_23: WriteRegBank 20:s_b_3_22 = s_b_3_21 */
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
    /* execute.simd:588 [F] s_b_4_0=sym_19885_3_parameter_inst.rn (const) */
    /* execute.simd:588 [D] s_b_4_1 = ReadRegBank 19:s_b_4_0 (v2u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:590 [F] s_b_4_2 = constant s32 0 (const) */
    /* execute.simd:590 [D] s_b_4_1[s_b_4_2] */
    auto s_b_4_3 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:590 [F] s_b_4_4 = constant u32 10 (const) */
    /* execute.simd:590 [D] s_b_4_5 = s_b_4_3>>>s_b_4_4 */
    auto s_b_4_5 = emitter.ror(s_b_4_3, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:590 [F] s_b_4_6 = constant s32 0 (const) */
    /* execute.simd:590 [D] s_b_4_7 = s_b_4_1[s_b_4_6] <= s_b_4_5 */
    auto s_b_4_7 = emitter.vector_insert(s_b_4_1, emitter.const_s32((int32_t)0ULL), s_b_4_5);
    /* execute.simd:591 [F] s_b_4_8 = constant s32 1 (const) */
    /* execute.simd:591 [D] s_b_4_7[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_7, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:591 [F] s_b_4_10 = constant u32 10 (const) */
    /* execute.simd:591 [D] s_b_4_11 = s_b_4_9>>>s_b_4_10 */
    auto s_b_4_11 = emitter.ror(s_b_4_9, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:591 [F] s_b_4_12 = constant s32 1 (const) */
    /* execute.simd:591 [D] s_b_4_13 = s_b_4_7[s_b_4_12] <= s_b_4_11 */
    auto s_b_4_13 = emitter.vector_insert(s_b_4_7, emitter.const_s32((int32_t)1ULL), s_b_4_11);
    /* execute.simd:593 [F] s_b_4_14=sym_19885_3_parameter_inst.rd (const) */
    /* execute.simd:593 [D] s_b_4_15: WriteRegBank 19:s_b_4_14 = s_b_4_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_13);
    /* execute.simd:594 [F] s_b_4_16=sym_19885_3_parameter_inst.rd (const) */
    /* execute.simd:594 [F] s_b_4_17 = constant u64 0 (const) */
    /* execute.simd:594 [F] s_b_4_18: WriteRegBank 3:s_b_4_16 = s_b_4_17 */
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
    /* execute.simd:598 [F] s_b_5_0=sym_19885_3_parameter_inst.rn (const) */
    /* execute.simd:598 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:600 [F] s_b_5_2 = constant s32 0 (const) */
    /* execute.simd:600 [D] s_b_5_1[s_b_5_2] */
    auto s_b_5_3 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:600 [F] s_b_5_4 = constant u32 10 (const) */
    /* execute.simd:600 [D] s_b_5_5 = s_b_5_3>>>s_b_5_4 */
    auto s_b_5_5 = emitter.ror(s_b_5_3, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:600 [F] s_b_5_6 = constant s32 0 (const) */
    /* execute.simd:600 [D] s_b_5_7 = s_b_5_1[s_b_5_6] <= s_b_5_5 */
    auto s_b_5_7 = emitter.vector_insert(s_b_5_1, emitter.const_s32((int32_t)0ULL), s_b_5_5);
    /* execute.simd:601 [F] s_b_5_8 = constant s32 1 (const) */
    /* execute.simd:601 [D] s_b_5_7[s_b_5_8] */
    auto s_b_5_9 = emitter.vector_extract(s_b_5_7, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:601 [F] s_b_5_10 = constant u32 10 (const) */
    /* execute.simd:601 [D] s_b_5_11 = s_b_5_9>>>s_b_5_10 */
    auto s_b_5_11 = emitter.ror(s_b_5_9, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:601 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:601 [D] s_b_5_13 = s_b_5_7[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(s_b_5_7, emitter.const_s32((int32_t)1ULL), s_b_5_11);
    /* execute.simd:602 [F] s_b_5_14 = constant s32 2 (const) */
    /* execute.simd:602 [D] s_b_5_13[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_13, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:602 [F] s_b_5_16 = constant u32 10 (const) */
    /* execute.simd:602 [D] s_b_5_17 = s_b_5_15>>>s_b_5_16 */
    auto s_b_5_17 = emitter.ror(s_b_5_15, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:602 [F] s_b_5_18 = constant s32 2 (const) */
    /* execute.simd:602 [D] s_b_5_19 = s_b_5_13[s_b_5_18] <= s_b_5_17 */
    auto s_b_5_19 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)2ULL), s_b_5_17);
    /* execute.simd:603 [F] s_b_5_20 = constant s32 3 (const) */
    /* execute.simd:603 [D] s_b_5_19[s_b_5_20] */
    auto s_b_5_21 = emitter.vector_extract(s_b_5_19, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:603 [F] s_b_5_22 = constant u32 10 (const) */
    /* execute.simd:603 [D] s_b_5_23 = s_b_5_21>>>s_b_5_22 */
    auto s_b_5_23 = emitter.ror(s_b_5_21, emitter.const_u32((uint32_t)16ULL));
    /* execute.simd:603 [F] s_b_5_24 = constant s32 3 (const) */
    /* execute.simd:603 [D] s_b_5_25 = s_b_5_19[s_b_5_24] <= s_b_5_23 */
    auto s_b_5_25 = emitter.vector_insert(s_b_5_19, emitter.const_s32((int32_t)3ULL), s_b_5_23);
    /* execute.simd:605 [F] s_b_5_26=sym_19885_3_parameter_inst.rd (const) */
    /* execute.simd:605 [D] s_b_5_27: WriteRegBank 20:s_b_5_26 = s_b_5_25 */
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
    /* execute.simd:609 [D] s_b_6_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_scvtf(const aarch64_decode_a64_CVT_FP_I&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4158 [F] s_b_0_0=sym_22136_3_parameter_inst.sf (const) */
    /* execute.simd:4158 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4158 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4158 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4158 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4159 [F] s_b_1_0=sym_22136_3_parameter_inst.type (const) */
    /* execute.simd:4159 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4159 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4159 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4159 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4166 [F] s_b_3_0=sym_22136_3_parameter_inst.sf (const) */
    /* execute.simd:4166 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4166 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4166 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4166 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_2 (const) */
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
    /* execute.simd:4161 [F] s_b_4_0=sym_22136_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [F] s_b_4_8=sym_22136_3_parameter_inst.rd (const) */
    /* execute.simd:4161 [D] s_b_4_9 = (s32)s_b_4_7 */
    auto s_b_4_9 = emitter.truncate(s_b_4_7, emitter.context().types().s32());
    /* execute.simd:4161 [D] s_b_4_10 = (f32)s_b_4_9 */
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
    /* execute.simd:4162 [F] s_b_5_0=sym_22136_3_parameter_inst.type (const) */
    /* execute.simd:4162 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4162 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4162 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4162 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
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
    /* execute.simd:4164 [F] s_b_6_0=sym_22136_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [F] s_b_6_8=sym_22136_3_parameter_inst.rd (const) */
    /* execute.simd:4164 [D] s_b_6_9 = (s32)s_b_6_7 */
    auto s_b_6_9 = emitter.truncate(s_b_6_7, emitter.context().types().s32());
    /* execute.simd:4164 [D] s_b_6_10 = (f64)s_b_6_9 */
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
    /* execute.simd:4167 [F] s_b_7_0=sym_22136_3_parameter_inst.type (const) */
    /* execute.simd:4167 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4167 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4167 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4167 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4169 [F] s_b_8_0=sym_22136_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [F] s_b_8_7=sym_22136_3_parameter_inst.rd (const) */
    /* execute.simd:4169 [D] s_b_8_8 = (s64)s_b_8_6 */
    auto s_b_8_8 = emitter.reinterpret(s_b_8_6, emitter.context().types().s64());
    /* execute.simd:4169 [D] s_b_8_9 = (f32)s_b_8_8 */
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
    /* execute.simd:4170 [F] s_b_9_0=sym_22136_3_parameter_inst.type (const) */
    /* execute.simd:4170 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4170 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4170 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4170 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_2 (const) */
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
    /* execute.simd:4172 [F] s_b_10_0=sym_22136_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [F] s_b_10_7=sym_22136_3_parameter_inst.rd (const) */
    /* execute.simd:4172 [D] s_b_10_8 = (s64)s_b_10_6 */
    auto s_b_10_8 = emitter.reinterpret(s_b_10_6, emitter.context().types().s64());
    /* execute.simd:4172 [D] s_b_10_9 = (f64)s_b_10_8 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_smin(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2821 [F] s_b_0_0=sym_23565_3_parameter_inst.arrangement (const) */
    /* execute.simd:2822 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:2834 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:2844 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:2855 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:2865 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:2876 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:2821 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:2823 [F] s_b_2_0=sym_23565_3_parameter_inst.rn (const) */
    /* execute.simd:2823 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:2823 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:2824 [F] s_b_2_3=sym_23565_3_parameter_inst.rm (const) */
    /* execute.simd:2824 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:2824 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* execute.simd:2826 [D] s_b_2_6 = s_b_2_2>s_b_2_5 */
    auto s_b_2_6 = emitter.cmp_gt(s_b_2_2, s_b_2_5);
    /* execute.simd:2827 [D] s_b_2_7 = ~s_b_2_6 */
    auto s_b_2_7 = emitter.bitwise_not(s_b_2_6);
    /* execute.simd:2827 [D] s_b_2_8 = s_b_2_2&s_b_2_7 */
    auto s_b_2_8 = emitter.bitwise_and(s_b_2_2, s_b_2_7);
    /* execute.simd:2827 [D] s_b_2_9 = s_b_2_5&s_b_2_6 */
    auto s_b_2_9 = emitter.bitwise_and(s_b_2_5, s_b_2_6);
    /* execute.simd:2827 [D] s_b_2_10 = s_b_2_8|s_b_2_9 */
    auto s_b_2_10 = emitter.bitwise_or(s_b_2_8, s_b_2_9);
    /* execute.simd:2829 [F] s_b_2_11=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2829 [D] s_b_2_12 = (v8u8)s_b_2_10 */
    auto s_b_2_12 = emitter.reinterpret(s_b_2_10, emitter.context().types().v8u8());
    /* execute.simd:2829 [D] s_b_2_13: WriteRegBank 15:s_b_2_11 = s_b_2_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_12);
    /* execute.simd:2830 [F] s_b_2_14=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2830 [F] s_b_2_15 = constant u64 0 (const) */
    /* execute.simd:2830 [F] s_b_2_16: WriteRegBank 3:s_b_2_14 = s_b_2_15 */
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
    /* execute.simd:2835 [F] s_b_3_0=sym_23565_3_parameter_inst.rn (const) */
    /* execute.simd:2835 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:2835 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:2836 [F] s_b_3_3=sym_23565_3_parameter_inst.rm (const) */
    /* execute.simd:2836 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:2836 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* execute.simd:2838 [D] s_b_3_6 = s_b_3_2>s_b_3_5 */
    auto s_b_3_6 = emitter.cmp_gt(s_b_3_2, s_b_3_5);
    /* execute.simd:2839 [D] s_b_3_7 = ~s_b_3_6 */
    auto s_b_3_7 = emitter.bitwise_not(s_b_3_6);
    /* execute.simd:2839 [D] s_b_3_8 = s_b_3_2&s_b_3_7 */
    auto s_b_3_8 = emitter.bitwise_and(s_b_3_2, s_b_3_7);
    /* execute.simd:2839 [D] s_b_3_9 = s_b_3_5&s_b_3_6 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_5, s_b_3_6);
    /* execute.simd:2839 [D] s_b_3_10 = s_b_3_8|s_b_3_9 */
    auto s_b_3_10 = emitter.bitwise_or(s_b_3_8, s_b_3_9);
    /* execute.simd:2841 [F] s_b_3_11=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2841 [D] s_b_3_12 = (v16u8)s_b_3_10 */
    auto s_b_3_12 = emitter.reinterpret(s_b_3_10, emitter.context().types().v16u8());
    /* execute.simd:2841 [D] s_b_3_13: WriteRegBank 16:s_b_3_11 = s_b_3_12 */
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
    /* execute.simd:2845 [F] s_b_4_0=sym_23565_3_parameter_inst.rn (const) */
    /* execute.simd:2845 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:2845 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:2846 [F] s_b_4_3=sym_23565_3_parameter_inst.rm (const) */
    /* execute.simd:2846 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:2846 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* execute.simd:2848 [D] s_b_4_6 = s_b_4_2>s_b_4_5 */
    auto s_b_4_6 = emitter.cmp_gt(s_b_4_2, s_b_4_5);
    /* execute.simd:2849 [D] s_b_4_7 = ~s_b_4_6 */
    auto s_b_4_7 = emitter.bitwise_not(s_b_4_6);
    /* execute.simd:2849 [D] s_b_4_8 = s_b_4_2&s_b_4_7 */
    auto s_b_4_8 = emitter.bitwise_and(s_b_4_2, s_b_4_7);
    /* execute.simd:2849 [D] s_b_4_9 = s_b_4_5&s_b_4_6 */
    auto s_b_4_9 = emitter.bitwise_and(s_b_4_5, s_b_4_6);
    /* execute.simd:2849 [D] s_b_4_10 = s_b_4_8|s_b_4_9 */
    auto s_b_4_10 = emitter.bitwise_or(s_b_4_8, s_b_4_9);
    /* execute.simd:2851 [F] s_b_4_11=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2851 [D] s_b_4_12 = (v4u16)s_b_4_10 */
    auto s_b_4_12 = emitter.reinterpret(s_b_4_10, emitter.context().types().v4u16());
    /* execute.simd:2851 [D] s_b_4_13: WriteRegBank 17:s_b_4_11 = s_b_4_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_12);
    /* execute.simd:2852 [F] s_b_4_14=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2852 [F] s_b_4_15 = constant u64 0 (const) */
    /* execute.simd:2852 [F] s_b_4_16: WriteRegBank 3:s_b_4_14 = s_b_4_15 */
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
    /* execute.simd:2856 [F] s_b_5_0=sym_23565_3_parameter_inst.rn (const) */
    /* execute.simd:2856 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:2856 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:2857 [F] s_b_5_3=sym_23565_3_parameter_inst.rm (const) */
    /* execute.simd:2857 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:2857 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* execute.simd:2859 [D] s_b_5_6 = s_b_5_2>s_b_5_5 */
    auto s_b_5_6 = emitter.cmp_gt(s_b_5_2, s_b_5_5);
    /* execute.simd:2860 [D] s_b_5_7 = ~s_b_5_6 */
    auto s_b_5_7 = emitter.bitwise_not(s_b_5_6);
    /* execute.simd:2860 [D] s_b_5_8 = s_b_5_2&s_b_5_7 */
    auto s_b_5_8 = emitter.bitwise_and(s_b_5_2, s_b_5_7);
    /* execute.simd:2860 [D] s_b_5_9 = s_b_5_5&s_b_5_6 */
    auto s_b_5_9 = emitter.bitwise_and(s_b_5_5, s_b_5_6);
    /* execute.simd:2860 [D] s_b_5_10 = s_b_5_8|s_b_5_9 */
    auto s_b_5_10 = emitter.bitwise_or(s_b_5_8, s_b_5_9);
    /* execute.simd:2862 [F] s_b_5_11=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2862 [D] s_b_5_12 = (v8u16)s_b_5_10 */
    auto s_b_5_12 = emitter.reinterpret(s_b_5_10, emitter.context().types().v8u16());
    /* execute.simd:2862 [D] s_b_5_13: WriteRegBank 18:s_b_5_11 = s_b_5_12 */
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
    /* execute.simd:2866 [F] s_b_6_0=sym_23565_3_parameter_inst.rn (const) */
    /* execute.simd:2866 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:2866 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:2867 [F] s_b_6_3=sym_23565_3_parameter_inst.rm (const) */
    /* execute.simd:2867 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:2867 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* execute.simd:2869 [D] s_b_6_6 = s_b_6_2>s_b_6_5 */
    auto s_b_6_6 = emitter.cmp_gt(s_b_6_2, s_b_6_5);
    /* execute.simd:2870 [D] s_b_6_7 = ~s_b_6_6 */
    auto s_b_6_7 = emitter.bitwise_not(s_b_6_6);
    /* execute.simd:2870 [D] s_b_6_8 = s_b_6_2&s_b_6_7 */
    auto s_b_6_8 = emitter.bitwise_and(s_b_6_2, s_b_6_7);
    /* execute.simd:2870 [D] s_b_6_9 = s_b_6_5&s_b_6_6 */
    auto s_b_6_9 = emitter.bitwise_and(s_b_6_5, s_b_6_6);
    /* execute.simd:2870 [D] s_b_6_10 = s_b_6_8|s_b_6_9 */
    auto s_b_6_10 = emitter.bitwise_or(s_b_6_8, s_b_6_9);
    /* execute.simd:2872 [F] s_b_6_11=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2872 [D] s_b_6_12 = (v2u32)s_b_6_10 */
    auto s_b_6_12 = emitter.reinterpret(s_b_6_10, emitter.context().types().v2u32());
    /* execute.simd:2872 [D] s_b_6_13: WriteRegBank 19:s_b_6_11 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12);
    /* execute.simd:2873 [F] s_b_6_14=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2873 [F] s_b_6_15 = constant u64 0 (const) */
    /* execute.simd:2873 [F] s_b_6_16: WriteRegBank 3:s_b_6_14 = s_b_6_15 */
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
    /* execute.simd:2877 [F] s_b_7_0=sym_23565_3_parameter_inst.rn (const) */
    /* execute.simd:2877 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:2877 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:2878 [F] s_b_7_3=sym_23565_3_parameter_inst.rm (const) */
    /* execute.simd:2878 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:2878 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* execute.simd:2880 [D] s_b_7_6 = s_b_7_2>s_b_7_5 */
    auto s_b_7_6 = emitter.cmp_gt(s_b_7_2, s_b_7_5);
    /* execute.simd:2881 [D] s_b_7_7 = ~s_b_7_6 */
    auto s_b_7_7 = emitter.bitwise_not(s_b_7_6);
    /* execute.simd:2881 [D] s_b_7_8 = s_b_7_2&s_b_7_7 */
    auto s_b_7_8 = emitter.bitwise_and(s_b_7_2, s_b_7_7);
    /* execute.simd:2881 [D] s_b_7_9 = s_b_7_5&s_b_7_6 */
    auto s_b_7_9 = emitter.bitwise_and(s_b_7_5, s_b_7_6);
    /* execute.simd:2881 [D] s_b_7_10 = s_b_7_8|s_b_7_9 */
    auto s_b_7_10 = emitter.bitwise_or(s_b_7_8, s_b_7_9);
    /* execute.simd:2883 [F] s_b_7_11=sym_23565_3_parameter_inst.rd (const) */
    /* execute.simd:2883 [D] s_b_7_12 = (v4u32)s_b_7_10 */
    auto s_b_7_12 = emitter.reinterpret(s_b_7_10, emitter.context().types().v4u32());
    /* execute.simd:2883 [D] s_b_7_13: WriteRegBank 20:s_b_7_11 = s_b_7_12 */
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
    /* execute.simd:2887 [D] s_b_8_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sshr(const aarch64_decode_a64_SIMD_SHIFT_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4699 [F] s_b_0_0=sym_28352_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4699 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4700 [F] s_b_1_0=sym_28352_3_parameter_inst.immh (const) */
    /* execute.simd:4700 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4700 [F] s_b_1_2 = constant u32 3 (const) */
    /* execute.simd:4700 [F] s_b_1_3 = s_b_1_1<<s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4700 [F] s_b_1_4=sym_28352_3_parameter_inst.immb (const) */
    /* execute.simd:4700 [F] s_b_1_5 = (u32)s_b_1_4 (const) */
    /* execute.simd:4700 [F] s_b_1_6 = s_b_1_3|s_b_1_5 (const) */
    uint32_t s_b_1_6 = ((uint32_t)(s_b_1_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4700 [F] s_b_1_7 = constant u32 80 (const) */
    /* execute.simd:4700 [F] s_b_1_8 = s_b_1_7-s_b_1_6 (const) */
    uint32_t s_b_1_8 = ((uint32_t)((uint32_t)128ULL - s_b_1_6));
    /* execute.simd:4700 [F] s_b_1_9 = (u64)s_b_1_8 (const) */
    /* execute.simd:4701 [F] s_b_1_10=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4701 [F] s_b_1_11=sym_28352_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_1_12 = ReadRegBank 7:s_b_1_11 (u64) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_12,emitter.const_u8(8));
    }
    /* execute.simd:4701 [D] s_b_1_13 = (s64)s_b_1_12 */
    auto s_b_1_13 = emitter.reinterpret(s_b_1_12, emitter.context().types().s64());
    /* execute.simd:4701 [D] s_b_1_14 = (u64)s_b_1_13 */
    auto s_b_1_14 = emitter.reinterpret(s_b_1_13, emitter.context().types().u64());
    /* execute.simd:4701 [D] s_b_1_15 = s_b_1_14->>s_b_1_9 */
    auto s_b_1_15 = emitter.sar(s_b_1_14, emitter.const_u64(((uint64_t)s_b_1_8)));
    /* execute.simd:4701 [D] s_b_1_16 = (u64)s_b_1_15 */
    auto s_b_1_16 = (captive::arch::dbt::el::Value *)s_b_1_15;
    /* execute.simd:6138 [D] s_b_1_17: WriteRegBank 2:s_b_1_10 = s_b_1_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_16);
    /* execute.simd:6139 [F] s_b_1_18 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_1_19: WriteRegBank 3:s_b_1_10 = s_b_1_18 */
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
    /* execute.simd:4703 [F] s_b_3_0=sym_28352_3_parameter_inst.arrangement (const) */
    /* execute.simd:4704 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:4712 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:4719 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:4727 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:4734 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:4742 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:4749 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:4703 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
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
    /* execute.simd:4705 [F] s_b_4_0=sym_28352_3_parameter_inst.immh (const) */
    /* execute.simd:4705 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4705 [F] s_b_4_2 = constant u32 3 (const) */
    /* execute.simd:4705 [F] s_b_4_3 = s_b_4_1<<s_b_4_2 (const) */
    uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4705 [F] s_b_4_4=sym_28352_3_parameter_inst.immb (const) */
    /* execute.simd:4705 [F] s_b_4_5 = (u32)s_b_4_4 (const) */
    /* execute.simd:4705 [F] s_b_4_6 = s_b_4_3|s_b_4_5 (const) */
    uint32_t s_b_4_6 = ((uint32_t)(s_b_4_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4705 [F] s_b_4_7 = constant u32 10 (const) */
    /* execute.simd:4705 [F] s_b_4_8 = s_b_4_7-s_b_4_6 (const) */
    uint32_t s_b_4_8 = ((uint32_t)((uint32_t)16ULL - s_b_4_6));
    /* execute.simd:4705 [F] s_b_4_9 = (u64)s_b_4_8 (const) */
    /* execute.simd:4707 [F] s_b_4_10=sym_28352_3_parameter_inst.rn (const) */
    /* execute.simd:4707 [D] s_b_4_11 = ReadRegBank 15:s_b_4_10 (v8u8) */
    auto s_b_4_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_11,emitter.const_u8(8));
    }
    /* execute.simd:4708 [F] s_b_4_12=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4708 [D] s_b_4_13 = (v8s8)s_b_4_11 */
    auto s_b_4_13 = emitter.reinterpret(s_b_4_11, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_4_14 = (v8s8)s_b_4_9 (const) */
    auto s_b_4_14 = wutils::Vector<int8_t, 8>(((uint64_t)s_b_4_8));
    /* execute.simd:4708 [D] s_b_4_15 = s_b_4_13->>s_b_4_14 */
    auto s_b_4_15 = emitter.sar(s_b_4_13, emitter.constant_vector_splat(s_b_4_14[0], emitter.context().types().v8s8()));
    /* execute.simd:4708 [D] s_b_4_16 = (v8u8)s_b_4_15 */
    auto s_b_4_16 = emitter.reinterpret(s_b_4_15, emitter.context().types().v8u8());
    /* execute.simd:4708 [D] s_b_4_17: WriteRegBank 15:s_b_4_12 = s_b_4_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_16);
    /* execute.simd:4709 [F] s_b_4_18=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4709 [F] s_b_4_19 = constant u64 0 (const) */
    /* execute.simd:4709 [F] s_b_4_20: WriteRegBank 3:s_b_4_18 = s_b_4_19 */
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
    /* execute.simd:4713 [F] s_b_5_0=sym_28352_3_parameter_inst.immh (const) */
    /* execute.simd:4713 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4713 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.simd:4713 [F] s_b_5_3 = s_b_5_1<<s_b_5_2 (const) */
    uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4713 [F] s_b_5_4=sym_28352_3_parameter_inst.immb (const) */
    /* execute.simd:4713 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4713 [F] s_b_5_6 = s_b_5_3|s_b_5_5 (const) */
    uint32_t s_b_5_6 = ((uint32_t)(s_b_5_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4713 [F] s_b_5_7 = constant u32 10 (const) */
    /* execute.simd:4713 [F] s_b_5_8 = s_b_5_7-s_b_5_6 (const) */
    uint32_t s_b_5_8 = ((uint32_t)((uint32_t)16ULL - s_b_5_6));
    /* execute.simd:4713 [F] s_b_5_9 = (u64)s_b_5_8 (const) */
    /* execute.simd:4715 [F] s_b_5_10=sym_28352_3_parameter_inst.rn (const) */
    /* execute.simd:4715 [D] s_b_5_11 = ReadRegBank 16:s_b_5_10 (v16u8) */
    auto s_b_5_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_11,emitter.const_u8(16));
    }
    /* execute.simd:4716 [F] s_b_5_12=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4716 [D] s_b_5_13 = (v16s8)s_b_5_11 */
    auto s_b_5_13 = emitter.reinterpret(s_b_5_11, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_5_14 = (v16s8)s_b_5_9 (const) */
    auto s_b_5_14 = wutils::Vector<int8_t, 16>(((uint64_t)s_b_5_8));
    /* execute.simd:4716 [D] s_b_5_15 = s_b_5_13->>s_b_5_14 */
    auto s_b_5_15 = emitter.sar(s_b_5_13, emitter.constant_vector_splat(s_b_5_14[0], emitter.context().types().v16s8()));
    /* execute.simd:4716 [D] s_b_5_16 = (v16u8)s_b_5_15 */
    auto s_b_5_16 = emitter.reinterpret(s_b_5_15, emitter.context().types().v16u8());
    /* execute.simd:4716 [D] s_b_5_17: WriteRegBank 16:s_b_5_12 = s_b_5_16 */
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
    /* execute.simd:4720 [F] s_b_6_0=sym_28352_3_parameter_inst.immh (const) */
    /* execute.simd:4720 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.simd:4720 [F] s_b_6_2 = constant u32 3 (const) */
    /* execute.simd:4720 [F] s_b_6_3 = s_b_6_1<<s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4720 [F] s_b_6_4=sym_28352_3_parameter_inst.immb (const) */
    /* execute.simd:4720 [F] s_b_6_5 = (u32)s_b_6_4 (const) */
    /* execute.simd:4720 [F] s_b_6_6 = s_b_6_3|s_b_6_5 (const) */
    uint32_t s_b_6_6 = ((uint32_t)(s_b_6_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4720 [F] s_b_6_7 = constant u32 20 (const) */
    /* execute.simd:4720 [F] s_b_6_8 = s_b_6_7-s_b_6_6 (const) */
    uint32_t s_b_6_8 = ((uint32_t)((uint32_t)32ULL - s_b_6_6));
    /* execute.simd:4720 [F] s_b_6_9 = (u64)s_b_6_8 (const) */
    /* execute.simd:4722 [F] s_b_6_10=sym_28352_3_parameter_inst.rn (const) */
    /* execute.simd:4722 [D] s_b_6_11 = ReadRegBank 17:s_b_6_10 (v4u16) */
    auto s_b_6_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_11,emitter.const_u8(8));
    }
    /* execute.simd:4723 [F] s_b_6_12=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4723 [D] s_b_6_13 = (v4s16)s_b_6_11 */
    auto s_b_6_13 = emitter.reinterpret(s_b_6_11, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_6_14 = (v4s16)s_b_6_9 (const) */
    auto s_b_6_14 = wutils::Vector<int16_t, 4>(((uint64_t)s_b_6_8));
    /* execute.simd:4723 [D] s_b_6_15 = s_b_6_13->>s_b_6_14 */
    auto s_b_6_15 = emitter.sar(s_b_6_13, emitter.constant_vector_splat(s_b_6_14[0], emitter.context().types().v4s16()));
    /* execute.simd:4723 [D] s_b_6_16 = (v4u16)s_b_6_15 */
    auto s_b_6_16 = emitter.reinterpret(s_b_6_15, emitter.context().types().v4u16());
    /* execute.simd:4723 [D] s_b_6_17: WriteRegBank 17:s_b_6_12 = s_b_6_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_16);
    /* execute.simd:4724 [F] s_b_6_18=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4724 [F] s_b_6_19 = constant u64 0 (const) */
    /* execute.simd:4724 [F] s_b_6_20: WriteRegBank 3:s_b_6_18 = s_b_6_19 */
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
    /* execute.simd:4728 [F] s_b_7_0=sym_28352_3_parameter_inst.immh (const) */
    /* execute.simd:4728 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4728 [F] s_b_7_2 = constant u32 3 (const) */
    /* execute.simd:4728 [F] s_b_7_3 = s_b_7_1<<s_b_7_2 (const) */
    uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4728 [F] s_b_7_4=sym_28352_3_parameter_inst.immb (const) */
    /* execute.simd:4728 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4728 [F] s_b_7_6 = s_b_7_3|s_b_7_5 (const) */
    uint32_t s_b_7_6 = ((uint32_t)(s_b_7_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4728 [F] s_b_7_7 = constant u32 20 (const) */
    /* execute.simd:4728 [F] s_b_7_8 = s_b_7_7-s_b_7_6 (const) */
    uint32_t s_b_7_8 = ((uint32_t)((uint32_t)32ULL - s_b_7_6));
    /* execute.simd:4728 [F] s_b_7_9 = (u64)s_b_7_8 (const) */
    /* execute.simd:4730 [F] s_b_7_10=sym_28352_3_parameter_inst.rn (const) */
    /* execute.simd:4730 [D] s_b_7_11 = ReadRegBank 18:s_b_7_10 (v8u16) */
    auto s_b_7_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_11,emitter.const_u8(16));
    }
    /* execute.simd:4731 [F] s_b_7_12=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4731 [D] s_b_7_13 = (v8s16)s_b_7_11 */
    auto s_b_7_13 = emitter.reinterpret(s_b_7_11, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_7_14 = (v8s16)s_b_7_9 (const) */
    auto s_b_7_14 = wutils::Vector<int16_t, 8>(((uint64_t)s_b_7_8));
    /* execute.simd:4731 [D] s_b_7_15 = s_b_7_13->>s_b_7_14 */
    auto s_b_7_15 = emitter.sar(s_b_7_13, emitter.constant_vector_splat(s_b_7_14[0], emitter.context().types().v8s16()));
    /* execute.simd:4731 [D] s_b_7_16 = (v8u16)s_b_7_15 */
    auto s_b_7_16 = emitter.reinterpret(s_b_7_15, emitter.context().types().v8u16());
    /* execute.simd:4731 [D] s_b_7_17: WriteRegBank 18:s_b_7_12 = s_b_7_16 */
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
    /* execute.simd:4735 [F] s_b_8_0=sym_28352_3_parameter_inst.immh (const) */
    /* execute.simd:4735 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.simd:4735 [F] s_b_8_2 = constant u32 3 (const) */
    /* execute.simd:4735 [F] s_b_8_3 = s_b_8_1<<s_b_8_2 (const) */
    uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4735 [F] s_b_8_4=sym_28352_3_parameter_inst.immb (const) */
    /* execute.simd:4735 [F] s_b_8_5 = (u32)s_b_8_4 (const) */
    /* execute.simd:4735 [F] s_b_8_6 = s_b_8_3|s_b_8_5 (const) */
    uint32_t s_b_8_6 = ((uint32_t)(s_b_8_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4735 [F] s_b_8_7 = constant u32 40 (const) */
    /* execute.simd:4735 [F] s_b_8_8 = s_b_8_7-s_b_8_6 (const) */
    uint32_t s_b_8_8 = ((uint32_t)((uint32_t)64ULL - s_b_8_6));
    /* execute.simd:4735 [F] s_b_8_9 = (u64)s_b_8_8 (const) */
    /* execute.simd:4737 [F] s_b_8_10=sym_28352_3_parameter_inst.rn (const) */
    /* execute.simd:4737 [D] s_b_8_11 = ReadRegBank 19:s_b_8_10 (v2u32) */
    auto s_b_8_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_11,emitter.const_u8(8));
    }
    /* execute.simd:4738 [F] s_b_8_12=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4738 [D] s_b_8_13 = (v2s32)s_b_8_11 */
    auto s_b_8_13 = emitter.reinterpret(s_b_8_11, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_8_14 = (v2s32)s_b_8_9 (const) */
    auto s_b_8_14 = wutils::Vector<int32_t, 2>(((uint64_t)s_b_8_8));
    /* execute.simd:4738 [D] s_b_8_15 = s_b_8_13->>s_b_8_14 */
    auto s_b_8_15 = emitter.sar(s_b_8_13, emitter.constant_vector_splat(s_b_8_14[0], emitter.context().types().v2s32()));
    /* execute.simd:4738 [D] s_b_8_16 = (v2u32)s_b_8_15 */
    auto s_b_8_16 = emitter.reinterpret(s_b_8_15, emitter.context().types().v2u32());
    /* execute.simd:4738 [D] s_b_8_17: WriteRegBank 19:s_b_8_12 = s_b_8_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_16);
    /* execute.simd:4739 [F] s_b_8_18=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4739 [F] s_b_8_19 = constant u64 0 (const) */
    /* execute.simd:4739 [F] s_b_8_20: WriteRegBank 3:s_b_8_18 = s_b_8_19 */
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
    /* execute.simd:4743 [F] s_b_9_0=sym_28352_3_parameter_inst.immh (const) */
    /* execute.simd:4743 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4743 [F] s_b_9_2 = constant u32 3 (const) */
    /* execute.simd:4743 [F] s_b_9_3 = s_b_9_1<<s_b_9_2 (const) */
    uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4743 [F] s_b_9_4=sym_28352_3_parameter_inst.immb (const) */
    /* execute.simd:4743 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4743 [F] s_b_9_6 = s_b_9_3|s_b_9_5 (const) */
    uint32_t s_b_9_6 = ((uint32_t)(s_b_9_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4743 [F] s_b_9_7 = constant u32 40 (const) */
    /* execute.simd:4743 [F] s_b_9_8 = s_b_9_7-s_b_9_6 (const) */
    uint32_t s_b_9_8 = ((uint32_t)((uint32_t)64ULL - s_b_9_6));
    /* execute.simd:4743 [F] s_b_9_9 = (u64)s_b_9_8 (const) */
    /* execute.simd:4745 [F] s_b_9_10=sym_28352_3_parameter_inst.rn (const) */
    /* execute.simd:4745 [D] s_b_9_11 = ReadRegBank 20:s_b_9_10 (v4u32) */
    auto s_b_9_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_11,emitter.const_u8(16));
    }
    /* execute.simd:4746 [F] s_b_9_12=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4746 [D] s_b_9_13 = (v4s32)s_b_9_11 */
    auto s_b_9_13 = emitter.reinterpret(s_b_9_11, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_9_14 = (v4s32)s_b_9_9 (const) */
    auto s_b_9_14 = wutils::Vector<int32_t, 4>(((uint64_t)s_b_9_8));
    /* execute.simd:4746 [D] s_b_9_15 = s_b_9_13->>s_b_9_14 */
    auto s_b_9_15 = emitter.sar(s_b_9_13, emitter.constant_vector_splat(s_b_9_14[0], emitter.context().types().v4s32()));
    /* execute.simd:4746 [D] s_b_9_16 = (v4u32)s_b_9_15 */
    auto s_b_9_16 = emitter.reinterpret(s_b_9_15, emitter.context().types().v4u32());
    /* execute.simd:4746 [D] s_b_9_17: WriteRegBank 20:s_b_9_12 = s_b_9_16 */
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
    /* execute.simd:4750 [F] s_b_10_0=sym_28352_3_parameter_inst.immh (const) */
    /* execute.simd:4750 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4750 [F] s_b_10_2 = constant u32 3 (const) */
    /* execute.simd:4750 [F] s_b_10_3 = s_b_10_1<<s_b_10_2 (const) */
    uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4750 [F] s_b_10_4=sym_28352_3_parameter_inst.immb (const) */
    /* execute.simd:4750 [F] s_b_10_5 = (u32)s_b_10_4 (const) */
    /* execute.simd:4750 [F] s_b_10_6 = s_b_10_3|s_b_10_5 (const) */
    uint32_t s_b_10_6 = ((uint32_t)(s_b_10_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4750 [F] s_b_10_7 = constant u32 80 (const) */
    /* execute.simd:4750 [F] s_b_10_8 = s_b_10_7-s_b_10_6 (const) */
    uint32_t s_b_10_8 = ((uint32_t)((uint32_t)128ULL - s_b_10_6));
    /* execute.simd:4750 [F] s_b_10_9 = (u64)s_b_10_8 (const) */
    /* execute.simd:4752 [F] s_b_10_10=sym_28352_3_parameter_inst.rn (const) */
    /* execute.simd:4752 [D] s_b_10_11 = ReadRegBank 21:s_b_10_10 (v2u64) */
    auto s_b_10_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_11,emitter.const_u8(16));
    }
    /* execute.simd:4753 [F] s_b_10_12=sym_28352_3_parameter_inst.rd (const) */
    /* execute.simd:4753 [D] s_b_10_13 = (v2s64)s_b_10_11 */
    auto s_b_10_13 = emitter.reinterpret(s_b_10_11, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_10_14 = (v2s64)s_b_10_9 (const) */
    auto s_b_10_14 = wutils::Vector<int64_t, 2>(((uint64_t)s_b_10_8));
    /* execute.simd:4753 [D] s_b_10_15 = s_b_10_13->>s_b_10_14 */
    auto s_b_10_15 = emitter.sar(s_b_10_13, emitter.constant_vector_splat(s_b_10_14[0], emitter.context().types().v2s64()));
    /* execute.simd:4753 [D] s_b_10_16 = (v2u64)s_b_10_15 */
    auto s_b_10_16 = emitter.reinterpret(s_b_10_15, emitter.context().types().v2u64());
    /* execute.simd:4753 [D] s_b_10_17: WriteRegBank 21:s_b_10_12 = s_b_10_16 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_st2pi(const aarch64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_131661_3_parameter_lane;
  auto DV_sym_131760_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_131855_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_131738_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_131653_3_parameter_rt;
  auto DV_sym_131777_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_131914_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_131561_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_131544_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30510_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30516_0_lane;
  uint8_t CV_sym_30528_0_rt;
  uint8_t CV_sym_131735_1_tmp_s_b_5_2;
  auto DV_sym_131658_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2520 [F] s_b_0_0=sym_30504_3_parameter_inst.rn (const) */
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
    /* execute.simd:2522 [F] s_b_1_0 = sym_30516_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30516_0_lane;
    /* execute.simd:2522 [F] s_b_1_1=sym_30504_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2522 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2522 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2523 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2523 [F] s_b_2_1: sym_30528_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30528_0_rt = (uint8_t)0ULL;
    /* execute.simd:2523 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2529 [F] s_b_3_0=sym_30504_3_parameter_inst.rm (const) */
    /* execute.simd:2529 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2529 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2529 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2529 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2523 [F] s_b_4_0 = sym_30528_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30528_0_rt;
    /* execute.simd:2523 [F] s_b_4_1=sym_30504_3_parameter_inst.regcnt (const) */
    /* execute.simd:2523 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2523 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2524 [F] s_b_5_0=sym_30504_3_parameter_inst.arrangement (const) */
    /* execute.simd:2524 [F] s_b_5_1=sym_30504_3_parameter_inst.rt (const) */
    /* execute.simd:2524 [F] s_b_5_2 = sym_30528_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30528_0_rt;
    /* execute.simd:2524 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2524 [F] s_b_5_4 = sym_30516_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30516_0_lane;
    /* execute.simd:2524 [D] s_b_5_5 = sym_30510_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30510_0_address, emitter.context().types().u64());
    /* execute.simd:2524 [F] s_b_5_6: sym_131653_3_parameter_rt = s_b_5_3 (const), dominates: s_b_19_0 s_b_20_0 s_b_21_0 s_b_22_0 s_b_23_0 s_b_24_0 s_b_18_0  */
    CV_sym_131653_3_parameter_rt = s_b_5_3;
    /* execute.simd:2524 [F] s_b_5_7: sym_131661_3_parameter_lane = s_b_5_4 (const), dominates: s_b_19_3 s_b_20_3 s_b_21_3 s_b_22_3 s_b_23_3 s_b_24_3 s_b_18_3  */
    CV_sym_131661_3_parameter_lane = s_b_5_4;
    /* execute.simd:2524 [D] s_b_5_8: sym_131658_3_parameter_addr = s_b_5_5, dominates: s_b_19_2 s_b_20_2 s_b_21_2 s_b_22_2 s_b_23_2 s_b_24_2 s_b_18_2  */
    emitter.store_local(DV_sym_131658_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_131735_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_25_1  */
    CV_sym_131735_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_131738_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_131738_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3774 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3779 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3784 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3789 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3794 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3799 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3804 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3773 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_17 (const) -> b_19, b_20, b_21, b_22, b_23, b_24, b_18, b_17,  */
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
    case (int32_t)0ULL:
      goto fixed_block_b_18;
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
    /* execute.simd:2522 [F] s_b_6_0 = sym_30516_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30516_0_lane;
    /* execute.simd:2522 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2522 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2522 [F] s_b_6_3: sym_30516_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30516_0_lane = s_b_6_2;
    /* execute.simd:2522 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2530 [F] s_b_7_0=sym_30504_3_parameter_inst.rn (const) */
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
    /* execute.simd:2533 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2533 [D] s_b_8_1 = sym_30510_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_30510_0_address, emitter.context().types().u64());
    /* execute.simd:2533 [D] s_b_8_2: sym_131855_3_parameter_value = s_b_8_1, dominates: s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_131855_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2733 [F] s_b_10_0=sym_30504_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_131544_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_131544_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_131544_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_131544_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2520 [D] s_b_11_1: sym_30510_0_address = s_b_11_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30510_0_address, s_b_11_0);
    /* execute.simd:2522 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.simd:2522 [F] s_b_11_3: sym_30516_0_lane = s_b_11_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30516_0_lane = (uint8_t)0ULL;
    /* execute.simd:2522 [F] s_b_11_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2702 [D] s_b_12_0 = ReadReg 20 (u64) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_12_1: sym_131561_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_131561_1__R_s_b_3_0, s_b_12_0);
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
    /* execute.a64:2731 [D] s_b_14_0 = sym_131561_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_131561_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_131544_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_131544_0_return_symbol, s_b_14_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_15_1: sym_131561_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_131561_1__R_s_b_3_0, s_b_15_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_16_1: sym_131561_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_131561_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2707 [F] s_b_16_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3810 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_17_1: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3775 [F] s_b_18_0 = sym_131653_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_131653_3_parameter_rt;
    /* execute.simd:3775 [D] s_b_18_1 = ReadRegBank 15:s_b_18_0 (v8u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3776 [D] s_b_18_2 = sym_131658_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_131658_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3776 [F] s_b_18_3 = sym_131661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_131661_3_parameter_lane;
    /* execute.simd:3776 [D] s_b_18_1[s_b_18_3] */
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
    /* execute.simd:3780 [F] s_b_19_0 = sym_131653_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_131653_3_parameter_rt;
    /* execute.simd:3780 [D] s_b_19_1 = ReadRegBank 16:s_b_19_0 (v16u8) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3781 [D] s_b_19_2 = sym_131658_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_131658_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3781 [F] s_b_19_3 = sym_131661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_131661_3_parameter_lane;
    /* execute.simd:3781 [D] s_b_19_1[s_b_19_3] */
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
    /* execute.simd:3785 [F] s_b_20_0 = sym_131653_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_131653_3_parameter_rt;
    /* execute.simd:3785 [D] s_b_20_1 = ReadRegBank 17:s_b_20_0 (v4u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3786 [D] s_b_20_2 = sym_131658_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_131658_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3786 [F] s_b_20_3 = sym_131661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_131661_3_parameter_lane;
    /* execute.simd:3786 [D] s_b_20_1[s_b_20_3] */
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
    /* execute.simd:3790 [F] s_b_21_0 = sym_131653_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_131653_3_parameter_rt;
    /* execute.simd:3790 [D] s_b_21_1 = ReadRegBank 18:s_b_21_0 (v8u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3791 [D] s_b_21_2 = sym_131658_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_131658_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3791 [F] s_b_21_3 = sym_131661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_131661_3_parameter_lane;
    /* execute.simd:3791 [D] s_b_21_1[s_b_21_3] */
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
    /* execute.simd:3795 [F] s_b_22_0 = sym_131653_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_131653_3_parameter_rt;
    /* execute.simd:3795 [D] s_b_22_1 = ReadRegBank 19:s_b_22_0 (v2u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:3796 [D] s_b_22_2 = sym_131658_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_131658_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3796 [F] s_b_22_3 = sym_131661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_131661_3_parameter_lane;
    /* execute.simd:3796 [D] s_b_22_1[s_b_22_3] */
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
    /* execute.simd:3800 [F] s_b_23_0 = sym_131653_3_parameter_rt (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_131653_3_parameter_rt;
    /* execute.simd:3800 [D] s_b_23_1 = ReadRegBank 20:s_b_23_0 (v4u32) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:3801 [D] s_b_23_2 = sym_131658_3_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_131658_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3801 [F] s_b_23_3 = sym_131661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_23_3 = CV_sym_131661_3_parameter_lane;
    /* execute.simd:3801 [D] s_b_23_1[s_b_23_3] */
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
    /* execute.simd:3805 [F] s_b_24_0 = sym_131653_3_parameter_rt (const) uint8_t */
    uint8_t s_b_24_0 = CV_sym_131653_3_parameter_rt;
    /* execute.simd:3805 [D] s_b_24_1 = ReadRegBank 21:s_b_24_0 (v2u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))),s_b_24_1,emitter.const_u8(16));
    }
    /* execute.simd:3806 [D] s_b_24_2 = sym_131658_3_parameter_addr uint64_t */
    auto s_b_24_2 = emitter.load_local(DV_sym_131658_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3806 [F] s_b_24_3 = sym_131661_3_parameter_lane (const) uint8_t */
    uint8_t s_b_24_3 = CV_sym_131661_3_parameter_lane;
    /* execute.simd:3806 [D] s_b_24_1[s_b_24_3] */
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
    /* ???:4294967295 [D] s_b_25_0 = sym_131738_1_tmp_s_b_5_5 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_131738_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_25_1 = sym_131735_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_25_1 = CV_sym_131735_1_tmp_s_b_5_2;
    /* execute.simd:2525 [F] s_b_25_2=sym_30504_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_25_3 = (u64)s_b_25_2 (const) */
    /* ???:4294967295 [D] s_b_25_4 = s_b_25_0+s_b_25_3 */
    auto s_b_25_4 = emitter.add(s_b_25_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2525 [D] s_b_25_5: sym_30510_0_address = s_b_25_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30510_0_address, s_b_25_4);
    /* execute.simd:2523 [F] s_b_25_6 = constant u8 1 (const) */
    /* execute.simd:2523 [F] s_b_25_7 = s_b_25_1+s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(s_b_25_1 + (uint8_t)1ULL));
    /* execute.simd:2523 [F] s_b_25_8: sym_30528_0_rt = s_b_25_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30528_0_rt = s_b_25_7;
    /* execute.simd:2523 [F] s_b_25_9: Jump b_4 (const) */
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
    /* execute.a64:2733 [F] s_b_27_0=sym_30504_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_27_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_27_2: sym_131760_0_return_symbol = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_131760_0_return_symbol, s_b_27_1);
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_31,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_131760_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_131760_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2530 [F] s_b_28_1=sym_30504_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_28_2 = (u32)s_b_28_1 (const) */
    /* execute.a64:2651 [F] s_b_28_3 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_28_4 = s_b_28_2==s_b_28_3 (const) */
    uint8_t s_b_28_4 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_28_5 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_28_6 = ReadRegBank 0:s_b_28_1 (u64) */
    auto s_b_28_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_6,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_28_7: Select s_b_28_4 ? s_b_28_5 : s_b_28_6 */
    captive::arch::dbt::el::Value *s_b_28_7;
    s_b_28_7 = (s_b_28_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_28_6);
    /* execute.simd:2530 [D] s_b_28_8 = s_b_28_0+s_b_28_7 */
    auto s_b_28_8 = emitter.add(s_b_28_0, s_b_28_7);
    /* execute.simd:2530 [D] s_b_28_9: sym_30510_0_address = s_b_28_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_30510_0_address, s_b_28_8);
    /* execute.simd:2530 [F] s_b_28_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_26,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2702 [D] s_b_29_0 = ReadReg 20 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_29_1: sym_131777_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_131777_1__R_s_b_3_0, s_b_29_0);
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
    /* execute.a64:2731 [D] s_b_31_0 = sym_131777_1__R_s_b_3_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_131777_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1: sym_131760_0_return_symbol = s_b_31_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_131760_0_return_symbol, s_b_31_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_32_1: sym_131777_1__R_s_b_3_0 = s_b_32_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_131777_1__R_s_b_3_0, s_b_32_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_33_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_33_1: sym_131777_1__R_s_b_3_0 = s_b_33_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_131777_1__R_s_b_3_0, s_b_33_0);
    /* execute.a64:2707 [F] s_b_33_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_8,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2747 [D] s_b_34_0 = sym_131855_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_131855_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_34_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_34_2 = s_b_34_0&s_b_34_1 */
    auto s_b_34_2 = emitter.bitwise_and(s_b_34_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_34_3: sym_131855_3_parameter_value = s_b_34_2, dominates: s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_131855_3_parameter_value, s_b_34_2);
    /* execute.a64:2747 [F] s_b_34_4: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_8, b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2750 [F] s_b_35_0=sym_30504_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_36_0 = sym_131855_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_131855_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_36_1: sym_131914_3_parameter_value = s_b_36_0, dominates: s_b_39_0 s_b_40_0 s_b_41_0  */
    emitter.store_local(DV_sym_131914_3_parameter_value, s_b_36_0);
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
    /* execute.a64:2753 [F] s_b_37_0=sym_30504_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_37_1 = sym_131855_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_131855_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_37_2: WriteRegBank 0:s_b_37_0 = s_b_37_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_37_1,emitter.const_u8(8));
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
    /* execute.a64:2715 [D] s_b_39_0 = sym_131914_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_131914_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_39_1: WriteReg 20 = s_b_39_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_39_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_39_0);
    /* execute.a64:2715 [F] s_b_39_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_42,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2718 [D] s_b_40_0 = sym_131914_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_131914_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_40_1: WriteReg 20 = s_b_40_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_40_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_40_0);
    /* execute.a64:2718 [F] s_b_40_2: Jump b_38 (const) */
    goto fixed_block_b_38;
  }
  /* b_42,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2720 [D] s_b_41_0 = sym_131914_3_parameter_value uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_131914_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_41_1: WriteReg 21 = s_b_41_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_41_0, emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stlxp(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_134111_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30933_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_134094_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:770 [F] s_b_0_0=sym_30927_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_9 (const) */
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
    /* execute.a64:773 [F] s_b_1_0 = constant u32 0 (const) */
    /* execute.a64:773 [D] s_b_1_1 = sym_30933_0_address uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_30933_0_address, emitter.context().types().u64());
    /* execute.a64:773 [D] s_b_1_2 = mem_monitor_release */
    auto s_b_1_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_1_1);
    /* execute.a64:773 [D] s_b_1_3: If s_b_1_2: Jump b_4 else b_5 */
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
    /* execute.a64:781 [F] s_b_3_0 = constant u32 0 (const) */
    /* execute.a64:781 [D] s_b_3_1 = sym_30933_0_address uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_30933_0_address, emitter.context().types().u64());
    /* execute.a64:781 [D] s_b_3_2 = mem_monitor_release */
    auto s_b_3_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_3_1);
    /* execute.a64:781 [D] s_b_3_3: If s_b_3_2: Jump b_6 else b_7 */
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
    /* execute.a64:2701 [F] s_b_8_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_8_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(s_b_8_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_8_4: If s_b_8_3: Jump b_11 else b_12 (const) */
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
    /* execute.a64:2733 [F] s_b_9_0=sym_30927_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_134094_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_134094_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_134094_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_134094_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:770 [D] s_b_10_1: sym_30933_0_address = s_b_10_0, dominates: s_b_1_1 s_b_4_0 s_b_3_1 s_b_6_0  */
    emitter.store_local(DV_sym_30933_0_address, s_b_10_0);
    /* execute.a64:772 [F] s_b_10_2=sym_30927_3_parameter_inst.size (const) */
    /* execute.a64:772 [F] s_b_10_3 = (u32)s_b_10_2 (const) */
    /* execute.a64:772 [F] s_b_10_4 = constant u32 2 (const) */
    /* execute.a64:772 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:772 [F] s_b_10_6: If s_b_10_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2702 [D] s_b_11_0 = ReadReg 20 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_11_1: sym_134111_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_134111_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2702 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_8,  */
  fixed_block_b_12: 
  {
    /* execute.a64:3012 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_12_1 = __builtin_get_feature */
    uint32_t s_b_12_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_12_2 = (u8)s_b_12_1 (const) */
    /* execute.a64:2704 [F] s_b_12_3 = (u32)s_b_12_2 (const) */
    /* execute.a64:2704 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_12_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_12_6: If s_b_12_5: Jump b_14 else b_15 (const) */
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
    /* execute.a64:2731 [D] s_b_13_0 = sym_134111_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_134111_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_134094_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_134094_0_return_symbol, s_b_13_0);
    /* ???:4294967295 [F] s_b_13_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2705 [D] s_b_14_0 = ReadReg 20 (u64) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_14_1: sym_134111_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_134111_1__R_s_b_3_0, s_b_14_0);
    /* execute.a64:2705 [F] s_b_14_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_12,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2707 [D] s_b_15_0 = ReadReg 21 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_15_1: sym_134111_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_134111_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2707 [F] s_b_15_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  // BLOCK b_16 not fully fixed
  // BLOCK b_17 not fully fixed
  // BLOCK b_18 not fully fixed
  // BLOCK b_19 not fully fixed
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
        /* execute.a64:774 [D] s_b_4_0 = sym_30933_0_address uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_30933_0_address, emitter.context().types().u64());
        /* execute.a64:774 [F] s_b_4_1=sym_30927_3_parameter_inst.rt (const) */
        /* execute.a64:2646 [F] s_b_4_2 = (u32)s_b_4_1 (const) */
        /* execute.a64:2646 [F] s_b_4_3 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_4_4 = s_b_4_2==s_b_4_3 (const) */
        uint8_t s_b_4_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_4_5 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_4_6 = ReadRegBank 1:s_b_4_1 (u32) */
        auto s_b_4_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_4_6,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_4_7: Select s_b_4_4 ? s_b_4_5 : s_b_4_6 */
        captive::arch::dbt::el::Value *s_b_4_7;
        s_b_4_7 = (s_b_4_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_6);
        /* execute.a64:2659 [D] s_b_4_8 = (u64)s_b_4_7 */
        auto s_b_4_8 = emitter.zx(s_b_4_7, emitter.context().types().u64());
        /* execute.a64:1792 [D] s_b_4_9 = (u32)s_b_4_8 */
        auto s_b_4_9 = emitter.truncate(s_b_4_8, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_4_10: Store 4 s_b_4_0 <= s_b_4_9 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_4_0, s_b_4_9, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_4_0, s_b_4_9);
        /* execute.a64:775 [F] s_b_4_11 = constant u64 4 (const) */
        /* execute.a64:775 [D] s_b_4_12 = s_b_4_0+s_b_4_11 */
        auto s_b_4_12 = emitter.add(s_b_4_0, emitter.const_u64((uint64_t)4ULL));
        /* execute.a64:775 [F] s_b_4_13=sym_30927_3_parameter_inst.rt2 (const) */
        /* execute.a64:2646 [F] s_b_4_14 = (u32)s_b_4_13 (const) */
        /* execute.a64:2646 [F] s_b_4_15 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_4_16 = s_b_4_14==s_b_4_15 (const) */
        uint8_t s_b_4_16 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_4_17 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_4_18 = ReadRegBank 1:s_b_4_13 (u32) */
        auto s_b_4_18 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_4_18,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_4_19: Select s_b_4_16 ? s_b_4_17 : s_b_4_18 */
        captive::arch::dbt::el::Value *s_b_4_19;
        s_b_4_19 = (s_b_4_16) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_18);
        /* execute.a64:2659 [D] s_b_4_20 = (u64)s_b_4_19 */
        auto s_b_4_20 = emitter.zx(s_b_4_19, emitter.context().types().u64());
        /* execute.a64:1792 [D] s_b_4_21 = (u32)s_b_4_20 */
        auto s_b_4_21 = emitter.truncate(s_b_4_20, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_4_22: Store 4 s_b_4_12 <= s_b_4_21 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_4_12, s_b_4_21, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_4_12, s_b_4_21);
        /* execute.a64:776 [F] s_b_4_23=sym_30927_3_parameter_inst.rs (const) */
        /* execute.a64:2674 [F] s_b_4_24 = (u32)s_b_4_23 (const) */
        /* execute.a64:2674 [F] s_b_4_25 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_4_26 = s_b_4_24==s_b_4_25 (const) */
        uint8_t s_b_4_26 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_4_27: If s_b_4_26: Jump b_2 else b_18 (const) */
        if (s_b_4_26) 
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:778 [F] s_b_5_0=sym_30927_3_parameter_inst.rs (const) */
        /* execute.a64:2674 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
        /* execute.a64:2674 [F] s_b_5_2 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
        uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_5_4: If s_b_5_3: Jump b_2 else b_16 (const) */
        if (s_b_5_3) 
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
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.a64:782 [D] s_b_6_0 = sym_30933_0_address uint64_t */
        auto s_b_6_0 = emitter.load_local(DV_sym_30933_0_address, emitter.context().types().u64());
        /* execute.a64:782 [F] s_b_6_1=sym_30927_3_parameter_inst.rt (const) */
        /* execute.a64:2651 [F] s_b_6_2 = (u32)s_b_6_1 (const) */
        /* execute.a64:2651 [F] s_b_6_3 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_6_4 = s_b_6_2==s_b_6_3 (const) */
        uint8_t s_b_6_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_6_5 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_6_6 = ReadRegBank 0:s_b_6_1 (u64) */
        auto s_b_6_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_6_6,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_6_7: Select s_b_6_4 ? s_b_6_5 : s_b_6_6 */
        captive::arch::dbt::el::Value *s_b_6_7;
        s_b_6_7 = (s_b_6_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_6_6);
        /* ???:4294967295 [D] s_b_6_8: Store 8 s_b_6_0 <= s_b_6_7 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_6_0, s_b_6_7, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_6_0, s_b_6_7);
        /* execute.a64:783 [F] s_b_6_9 = constant u64 8 (const) */
        /* execute.a64:783 [D] s_b_6_10 = s_b_6_0+s_b_6_9 */
        auto s_b_6_10 = emitter.add(s_b_6_0, emitter.const_u64((uint64_t)8ULL));
        /* execute.a64:783 [F] s_b_6_11=sym_30927_3_parameter_inst.rt2 (const) */
        /* execute.a64:2651 [F] s_b_6_12 = (u32)s_b_6_11 (const) */
        /* execute.a64:2651 [F] s_b_6_13 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_6_14 = s_b_6_12==s_b_6_13 (const) */
        uint8_t s_b_6_14 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_6_15 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_6_16 = ReadRegBank 0:s_b_6_11 (u64) */
        auto s_b_6_16 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_6_16,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_6_17: Select s_b_6_14 ? s_b_6_15 : s_b_6_16 */
        captive::arch::dbt::el::Value *s_b_6_17;
        s_b_6_17 = (s_b_6_14) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_6_16);
        /* ???:4294967295 [D] s_b_6_18: Store 8 s_b_6_10 <= s_b_6_17 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_6_10, s_b_6_17, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_6_10, s_b_6_17);
        /* execute.a64:784 [F] s_b_6_19=sym_30927_3_parameter_inst.rs (const) */
        /* execute.a64:2674 [F] s_b_6_20 = (u32)s_b_6_19 (const) */
        /* execute.a64:2674 [F] s_b_6_21 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_6_22 = s_b_6_20==s_b_6_21 (const) */
        uint8_t s_b_6_22 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_6_23: If s_b_6_22: Jump b_2 else b_19 (const) */
        if (s_b_6_22) 
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
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.a64:786 [F] s_b_7_0=sym_30927_3_parameter_inst.rs (const) */
        /* execute.a64:2674 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
        /* execute.a64:2674 [F] s_b_7_2 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
        uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_7_4: If s_b_7_3: Jump b_2 else b_17 (const) */
        if (s_b_7_3) 
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
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.a64:2676 [F] s_b_16_0=sym_30927_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_16_1 = constant u64 1 (const) */
        /* execute.a64:2676 [F] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
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
        /* execute.a64:2676 [F] s_b_17_0=sym_30927_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_17_1 = constant u64 1 (const) */
        /* execute.a64:2676 [F] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:0 [F] s_b_17_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2676 [F] s_b_18_0=sym_30927_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_18_1 = constant u64 0 (const) */
        /* execute.a64:2676 [F] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_18_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.a64:2676 [F] s_b_19_0=sym_30927_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_19_1 = constant u64 0 (const) */
        /* execute.a64:2676 [F] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_19_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stpi_simd(const aarch64_decode_a64_LS_REG_PAIR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_137654_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137615_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137487_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137395_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31448_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137530_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137520_1_tmp_s_b_0_7 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_137522_1_tmp_s_b_0_5;
  uint8_t CV_sym_137524_1_tmp_s_b_0_1;
  auto DV_sym_137412_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:719 [F] s_b_0_0=sym_31442_3_parameter_inst.rn (const) */
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
    /* execute.simd:721 [D] s_b_1_0 = sym_31448_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31448_0_addr, emitter.context().types().u64());
    /* execute.simd:721 [F] s_b_1_1=sym_31442_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.simd:721 [D] s_b_1_3: sym_31448_0_addr = s_b_1_2, dominates: s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_31448_0_addr, s_b_1_2);
    /* execute.simd:721 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.simd:724 [F] s_b_2_0=sym_31442_3_parameter_inst.opc (const) */
    /* execute.simd:724 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.simd:724 [F] s_b_2_2 = constant u32 2 (const) */
    /* execute.simd:724 [F] s_b_2_3 = s_b_2_1+s_b_2_2 (const) */
    uint32_t s_b_2_3 = ((uint32_t)(((uint32_t)insn.opc) + (uint32_t)2ULL));
    /* execute.simd:724 [F] s_b_2_4 = (u8)s_b_2_3 (const) */
    /* execute.simd:724 [D] s_b_2_5 = sym_31448_0_addr uint64_t */
    auto s_b_2_5 = emitter.load_local(DV_sym_31448_0_addr, emitter.context().types().u64());
    /* execute.simd:695 [F] s_b_2_6 = constant u32 1 (const) */
    /* execute.simd:695 [F] s_b_2_7 = (u32)s_b_2_4 (const) */
    /* execute.simd:695 [F] s_b_2_8 = s_b_2_6<<s_b_2_7 (const) */
    uint32_t s_b_2_8 = ((uint32_t)((uint32_t)1ULL << ((uint32_t)((uint8_t)s_b_2_3))));
    /* execute.simd:695 [F] s_b_2_9 = (u8)s_b_2_8 (const) */
    /* ???:4294967295 [F] s_b_2_10: sym_137524_1_tmp_s_b_0_1 = s_b_2_4 (const), dominates: s_b_14_2  */
    CV_sym_137524_1_tmp_s_b_0_1 = ((uint8_t)s_b_2_3);
    /* ???:4294967295 [F] s_b_2_11: sym_137522_1_tmp_s_b_0_5 = s_b_2_9 (const), dominates: s_b_14_1  */
    CV_sym_137522_1_tmp_s_b_0_5 = ((uint8_t)s_b_2_8);
    /* ???:4294967295 [D] s_b_2_12: sym_137520_1_tmp_s_b_0_7 = s_b_2_5, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_137520_1_tmp_s_b_0_7, s_b_2_5);
    /* ???:4294967295 [D] s_b_2_13: sym_137487_0_replaced_parameter_addr = s_b_2_5, dominates: s_b_15_2 s_b_16_2 s_b_13_2 s_b_17_2 s_b_18_3  */
    emitter.store_local(DV_sym_137487_0_replaced_parameter_addr, s_b_2_5);
    /* execute.simd:3566 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:3572 [F] s_b_2_15 = constant s32 1 (const) */
    /* execute.simd:3578 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:3584 [F] s_b_2_17 = constant s32 3 (const) */
    /* execute.simd:3590 [F] s_b_2_18 = constant s32 4 (const) */
    /* execute.simd:3565 [F] s_b_2_19: Switch s_b_2_4: < <todo> > def b_14 (const) -> b_14, b_15, b_16, b_13, b_17, b_18,  */
    switch (((uint8_t)s_b_2_3)) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_17;
      break;
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
    default:
      goto fixed_block_b_14;
    }
  }
  /* b_24,  */
  fixed_block_b_3: 
  {
    /* execute.simd:727 [D] s_b_3_0 = sym_31448_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31448_0_addr, emitter.context().types().u64());
    /* execute.simd:727 [F] s_b_3_1=sym_31442_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:727 [D] s_b_3_3: sym_31448_0_addr = s_b_3_2, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_31448_0_addr, s_b_3_2);
    /* execute.simd:727 [F] s_b_3_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_24,  */
  fixed_block_b_4: 
  {
    /* execute.simd:730 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.simd:730 [D] s_b_4_1 = sym_31448_0_addr uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_31448_0_addr, emitter.context().types().u64());
    /* execute.simd:730 [D] s_b_4_2: sym_137615_3_parameter_value = s_b_4_1, dominates: s_b_25_0 s_b_27_0 s_b_28_1  */
    emitter.store_local(DV_sym_137615_3_parameter_value, s_b_4_1);
    /* execute.a64:2746 [F] s_b_4_3 = !s_b_4_0 (const) */
    uint8_t s_b_4_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_4_4: If s_b_4_3: Jump b_25 else b_26 (const) */
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
    /* execute.a64:2733 [F] s_b_6_0=sym_31442_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_6_1 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_6_2: sym_137395_0_return_symbol = s_b_6_1, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_137395_0_return_symbol, s_b_6_1);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_10,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [D] s_b_7_0 = sym_137395_0_return_symbol uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_137395_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:719 [D] s_b_7_1: sym_31448_0_addr = s_b_7_0, dominates: s_b_1_0 s_b_2_5 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_31448_0_addr, s_b_7_0);
    /* execute.simd:720 [F] s_b_7_2=sym_31442_3_parameter_inst.P (const) */
    /* execute.simd:720 [F] s_b_7_3: If s_b_7_2: Jump b_1 else b_2 (const) */
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_8_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_8_1: sym_137412_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_137412_1__R_s_b_3_0, s_b_8_0);
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
    /* execute.a64:2731 [D] s_b_10_0 = sym_137412_1__R_s_b_3_0 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_137412_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1: sym_137395_0_return_symbol = s_b_10_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_137395_0_return_symbol, s_b_10_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_11_1: sym_137412_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_137412_1__R_s_b_3_0, s_b_11_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_12_1: sym_137412_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_137412_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2707 [F] s_b_12_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_2,  */
  fixed_block_b_13: 
  {
    /* execute.simd:3568 [F] s_b_13_0=sym_31442_3_parameter_inst.rt (const) */
    /* execute.simd:6152 [D] s_b_13_1 = ReadRegBank 4:s_b_13_0 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1,emitter.const_u8(1));
    }
    /* execute.simd:3569 [D] s_b_13_2 = sym_137487_0_replaced_parameter_addr uint64_t */
    auto s_b_13_2 = emitter.load_local(DV_sym_137487_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* ???:4294967295 [D] s_b_14_0 = sym_137520_1_tmp_s_b_0_7 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_137520_1_tmp_s_b_0_7, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_14_1 = sym_137522_1_tmp_s_b_0_5 (const) uint8_t */
    uint8_t s_b_14_1 = CV_sym_137522_1_tmp_s_b_0_5;
    /* ???:4294967295 [F] s_b_14_2 = sym_137524_1_tmp_s_b_0_1 (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_137524_1_tmp_s_b_0_1;
    /* execute.simd:697 [F] s_b_14_3 = (u64)s_b_14_1 (const) */
    /* execute.simd:697 [D] s_b_14_4 = s_b_14_0+s_b_14_3 */
    auto s_b_14_4 = emitter.add(s_b_14_0, emitter.const_u64(((uint64_t)s_b_14_1)));
    /* ???:4294967295 [D] s_b_14_5: sym_137530_0_replaced_parameter_addr = s_b_14_4, dominates: s_b_21_2 s_b_23_2 s_b_19_3 s_b_20_2 s_b_22_2  */
    emitter.store_local(DV_sym_137530_0_replaced_parameter_addr, s_b_14_4);
    /* execute.simd:3566 [F] s_b_14_6 = constant s32 0 (const) */
    /* execute.simd:3572 [F] s_b_14_7 = constant s32 1 (const) */
    /* execute.simd:3578 [F] s_b_14_8 = constant s32 2 (const) */
    /* execute.simd:3584 [F] s_b_14_9 = constant s32 3 (const) */
    /* execute.simd:3590 [F] s_b_14_10 = constant s32 4 (const) */
    /* execute.simd:3565 [F] s_b_14_11: Switch s_b_14_2: < <todo> > def b_24 (const) -> b_21, b_23, b_24, b_19, b_20, b_22,  */
    switch (s_b_14_2) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_21;
      break;
    default:
      goto fixed_block_b_24;
    }
  }
  /* b_2,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3574 [F] s_b_15_0=sym_31442_3_parameter_inst.rt (const) */
    /* execute.simd:6157 [D] s_b_15_1 = ReadRegBank 5:s_b_15_0 (u16) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_15_1,emitter.const_u8(2));
    }
    /* execute.simd:3575 [D] s_b_15_2 = sym_137487_0_replaced_parameter_addr uint64_t */
    auto s_b_15_2 = emitter.load_local(DV_sym_137487_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3580 [F] s_b_16_0=sym_31442_3_parameter_inst.rt (const) */
    /* execute.simd:6162 [D] s_b_16_1 = ReadRegBank 6:s_b_16_0 (u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_1,emitter.const_u8(4));
    }
    /* execute.simd:3581 [D] s_b_16_2 = sym_137487_0_replaced_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_137487_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3586 [F] s_b_17_0=sym_31442_3_parameter_inst.rt (const) */
    /* execute.simd:6167 [D] s_b_17_1 = ReadRegBank 7:s_b_17_0 (u64) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_17_1,emitter.const_u8(8));
    }
    /* execute.simd:3587 [D] s_b_17_2 = sym_137487_0_replaced_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_137487_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3594 [F] s_b_18_0=sym_31442_3_parameter_inst.rt (const) */
    /* execute.simd:6172 [D] s_b_18_1 = ReadRegBank 2:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_18_2 = ReadRegBank 3:s_b_18_0 (u64) */
    auto s_b_18_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_18_2,emitter.const_u8(8));
    }
    /* execute.simd:3595 [D] s_b_18_3 = sym_137487_0_replaced_parameter_addr uint64_t */
    auto s_b_18_3 = emitter.load_local(DV_sym_137487_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_4: Store 8 s_b_18_3 <= s_b_18_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_18_3, s_b_18_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_18_3, s_b_18_1);
    /* execute.simd:3596 [F] s_b_18_5 = constant u64 8 (const) */
    /* execute.simd:3596 [D] s_b_18_6 = s_b_18_3+s_b_18_5 */
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
    /* execute.simd:3594 [F] s_b_19_0=sym_31442_3_parameter_inst.rt2 (const) */
    /* execute.simd:6172 [D] s_b_19_1 = ReadRegBank 2:s_b_19_0 (u64) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_19_2 = ReadRegBank 3:s_b_19_0 (u64) */
    auto s_b_19_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt2))),s_b_19_2,emitter.const_u8(8));
    }
    /* execute.simd:3595 [D] s_b_19_3 = sym_137530_0_replaced_parameter_addr uint64_t */
    auto s_b_19_3 = emitter.load_local(DV_sym_137530_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_19_4: Store 8 s_b_19_3 <= s_b_19_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_19_3, s_b_19_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_19_3, s_b_19_1);
    /* execute.simd:3596 [F] s_b_19_5 = constant u64 8 (const) */
    /* execute.simd:3596 [D] s_b_19_6 = s_b_19_3+s_b_19_5 */
    auto s_b_19_6 = emitter.add(s_b_19_3, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_19_7: Store 8 s_b_19_6 <= s_b_19_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_19_6, s_b_19_2, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_19_6, s_b_19_2);
    /* execute.simd:0 [F] s_b_19_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_20: 
  {
    /* execute.simd:3580 [F] s_b_20_0=sym_31442_3_parameter_inst.rt2 (const) */
    /* execute.simd:6162 [D] s_b_20_1 = ReadRegBank 6:s_b_20_0 (u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_20_1,emitter.const_u8(4));
    }
    /* execute.simd:3581 [D] s_b_20_2 = sym_137530_0_replaced_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_137530_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3568 [F] s_b_21_0=sym_31442_3_parameter_inst.rt2 (const) */
    /* execute.simd:6152 [D] s_b_21_1 = ReadRegBank 4:s_b_21_0 (u8) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_21_1,emitter.const_u8(1));
    }
    /* execute.simd:3569 [D] s_b_21_2 = sym_137530_0_replaced_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_137530_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_3: Store 1 s_b_21_2 <= s_b_21_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_21_2, s_b_21_1, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_21_2, s_b_21_1);
    /* execute.simd:0 [F] s_b_21_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_22: 
  {
    /* execute.simd:3586 [F] s_b_22_0=sym_31442_3_parameter_inst.rt2 (const) */
    /* execute.simd:6167 [D] s_b_22_1 = ReadRegBank 7:s_b_22_0 (u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:3587 [D] s_b_22_2 = sym_137530_0_replaced_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_137530_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_22_3: Store 8 s_b_22_2 <= s_b_22_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_22_2, s_b_22_1);
    /* execute.simd:0 [F] s_b_22_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14,  */
  fixed_block_b_23: 
  {
    /* execute.simd:3574 [F] s_b_23_0=sym_31442_3_parameter_inst.rt2 (const) */
    /* execute.simd:6157 [D] s_b_23_1 = ReadRegBank 5:s_b_23_0 (u16) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt2))),s_b_23_1,emitter.const_u8(2));
    }
    /* execute.simd:3575 [D] s_b_23_2 = sym_137530_0_replaced_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_137530_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_23_3: Store 2 s_b_23_2 <= s_b_23_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_23_2, s_b_23_1, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_23_2, s_b_23_1);
    /* execute.simd:0 [F] s_b_23_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_14, b_19, b_20, b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.simd:726 [F] s_b_24_0=sym_31442_3_parameter_inst.P (const) */
    /* execute.simd:726 [F] s_b_24_1 = !s_b_24_0 (const) */
    uint8_t s_b_24_1 = !insn.P;
    /* execute.simd:726 [F] s_b_24_2: If s_b_24_1: Jump b_3 else b_4 (const) */
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
    /* execute.a64:2747 [D] s_b_25_0 = sym_137615_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_137615_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_25_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_25_2 = s_b_25_0&s_b_25_1 */
    auto s_b_25_2 = emitter.bitwise_and(s_b_25_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_25_3: sym_137615_3_parameter_value = s_b_25_2, dominates: s_b_27_0 s_b_28_1  */
    emitter.store_local(DV_sym_137615_3_parameter_value, s_b_25_2);
    /* execute.a64:2747 [F] s_b_25_4: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_4, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2750 [F] s_b_26_0=sym_31442_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
    /* execute.a64:2750 [F] s_b_26_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_26_4: If s_b_26_3: Jump b_27 else b_28 (const) */
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
    /* execute.a64:2751 [D] s_b_27_0 = sym_137615_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_137615_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_27_1: sym_137654_3_parameter_value = s_b_27_0, dominates: s_b_30_0 s_b_31_0 s_b_32_0  */
    emitter.store_local(DV_sym_137654_3_parameter_value, s_b_27_0);
    /* execute.a64:2714 [F] s_b_27_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_27_3 = __builtin_get_feature */
    uint32_t s_b_27_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_27_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_27_5 = s_b_27_3==s_b_27_4 (const) */
    uint8_t s_b_27_5 = ((uint8_t)(s_b_27_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_27_6: If s_b_27_5: Jump b_30 else b_33 (const) */
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
    /* execute.a64:2753 [F] s_b_28_0=sym_31442_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_28_1 = sym_137615_3_parameter_value uint64_t */
    auto s_b_28_1 = emitter.load_local(DV_sym_137615_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_28_2: WriteRegBank 0:s_b_28_0 = s_b_28_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_28_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_28_1);
    /* execute.a64:2753 [F] s_b_28_3: Jump b_29 (const) */
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
    /* execute.a64:2715 [D] s_b_30_0 = sym_137654_3_parameter_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_137654_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_30_1: WriteReg 20 = s_b_30_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_30_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_30_0);
    /* execute.a64:2715 [F] s_b_30_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_33,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2718 [D] s_b_31_0 = sym_137654_3_parameter_value uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_137654_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_31_1: WriteReg 20 = s_b_31_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_31_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_31_0);
    /* execute.a64:2718 [F] s_b_31_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_33,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2720 [D] s_b_32_0 = sym_137654_3_parameter_value uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_137654_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_32_1: WriteReg 21 = s_b_32_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_32_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_32_0);
    /* execute.a64:2720 [F] s_b_32_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27,  */
  fixed_block_b_33: 
  {
    /* execute.a64:3012 [F] s_b_33_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_33_1 = __builtin_get_feature */
    uint32_t s_b_33_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_33_2 = (u8)s_b_33_1 (const) */
    /* execute.a64:2717 [F] s_b_33_3 = (u32)s_b_33_2 (const) */
    /* execute.a64:2717 [F] s_b_33_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_33_5 = s_b_33_3==s_b_33_4 (const) */
    uint8_t s_b_33_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_33_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_33_6: If s_b_33_5: Jump b_31 else b_32 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_strh_reg(const aarch64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_32327_0_rm;
  auto DV_sym_32327_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141834_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141851_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1162 [F] s_b_0_0=sym_32300_3_parameter_inst.option0 (const) */
    /* execute.a64:1162 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1162 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1162 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1162 [F] s_b_0_4=sym_32300_3_parameter_inst.option21 (const) */
    /* execute.a64:1162 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:1162 [F] s_b_0_6 = constant u32 1 (const) */
    /* execute.a64:1162 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:1162 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1163 [F] s_b_1_0=sym_32300_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2646 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_5 = ReadRegBank 1:s_b_1_0 (u32) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_1_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 */
    captive::arch::dbt::el::Value *s_b_1_6;
    s_b_1_6 = (s_b_1_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_5);
    /* execute.a64:2659 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2616 [D] s_b_1_8 = (u32)s_b_1_7 */
    auto s_b_1_8 = emitter.truncate(s_b_1_7, emitter.context().types().u32());
    /* execute.a64:2616 [D] s_b_1_9 = (u64)s_b_1_8 */
    auto s_b_1_9 = emitter.zx(s_b_1_8, emitter.context().types().u64());
    /* execute.a64:2616 [F] s_b_1_10=sym_32300_3_parameter_inst.S (const) */
    /* execute.a64:2616 [F] s_b_1_11 = (u64)s_b_1_10 (const) */
    /* execute.a64:2616 [D] s_b_1_12 = s_b_1_9<<s_b_1_11 */
    auto s_b_1_12 = emitter.shl(s_b_1_9, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1163 [D] s_b_1_13: sym_32327_0_rm = s_b_1_12, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_32327_0_rm, s_b_1_12);
    /* execute.a64:1163 [F] s_b_1_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_8, b_9,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1175 [F] s_b_2_0=sym_32300_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2730 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_2_4: If s_b_2_3: Jump b_10 else b_11 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1164 [F] s_b_3_0=sym_32300_3_parameter_inst.option0 (const) */
    /* execute.a64:1164 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1164 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1164 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1164 [F] s_b_3_4=sym_32300_3_parameter_inst.option21 (const) */
    /* execute.a64:1164 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:1164 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.a64:1164 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:1164 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1165 [F] s_b_4_0=sym_32300_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2646 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_4_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_4_5 = ReadRegBank 1:s_b_4_0 (u32) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_4_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_4_6: Select s_b_4_3 ? s_b_4_4 : s_b_4_5 */
    captive::arch::dbt::el::Value *s_b_4_6;
    s_b_4_6 = (s_b_4_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_5);
    /* execute.a64:2659 [D] s_b_4_7 = (u64)s_b_4_6 */
    auto s_b_4_7 = emitter.zx(s_b_4_6, emitter.context().types().u64());
    /* execute.a64:2632 [D] s_b_4_8 = (s32)s_b_4_7 */
    auto s_b_4_8 = emitter.truncate(s_b_4_7, emitter.context().types().s32());
    /* execute.a64:2632 [D] s_b_4_9 = (s64)s_b_4_8 */
    auto s_b_4_9 = emitter.sx(s_b_4_8, emitter.context().types().s64());
    /* execute.a64:2632 [D] s_b_4_10 = (u64)s_b_4_9 */
    auto s_b_4_10 = emitter.reinterpret(s_b_4_9, emitter.context().types().u64());
    /* execute.a64:2632 [F] s_b_4_11=sym_32300_3_parameter_inst.S (const) */
    /* execute.a64:2632 [F] s_b_4_12 = (u64)s_b_4_11 (const) */
    /* execute.a64:2632 [D] s_b_4_13 = s_b_4_10<<s_b_4_12 */
    auto s_b_4_13 = emitter.shl(s_b_4_10, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1165 [D] s_b_4_14: sym_32327_0_rm = s_b_4_13, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_32327_0_rm, s_b_4_13);
    /* execute.a64:1165 [F] s_b_4_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1166 [F] s_b_5_0=sym_32300_3_parameter_inst.option0 (const) */
    /* execute.a64:1166 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1166 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1166 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1166 [F] s_b_5_4=sym_32300_3_parameter_inst.option21 (const) */
    /* execute.a64:1166 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1166 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:1166 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1166 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1167 [F] s_b_6_0=sym_32300_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2651 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_6_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_6_5 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_6_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_6_6: Select s_b_6_3 ? s_b_6_4 : s_b_6_5 */
    captive::arch::dbt::el::Value *s_b_6_6;
    s_b_6_6 = (s_b_6_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_6_5);
    /* execute.a64:2620 [F] s_b_6_7=sym_32300_3_parameter_inst.S (const) */
    /* execute.a64:2620 [F] s_b_6_8 = (u64)s_b_6_7 (const) */
    /* execute.a64:2620 [D] s_b_6_9 = s_b_6_6<<s_b_6_8 */
    auto s_b_6_9 = emitter.shl(s_b_6_6, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1167 [D] s_b_6_10: sym_32327_0_rm = s_b_6_9, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_32327_0_rm, s_b_6_9);
    /* execute.a64:1167 [F] s_b_6_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1168 [F] s_b_7_0=sym_32300_3_parameter_inst.option0 (const) */
    /* execute.a64:1168 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1168 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1168 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1168 [F] s_b_7_4=sym_32300_3_parameter_inst.option21 (const) */
    /* execute.a64:1168 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:1168 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.a64:1168 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:1168 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1169 [F] s_b_8_0=sym_32300_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2651 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_8_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_8_5 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_8_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    captive::arch::dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2636 [F] s_b_8_7=sym_32300_3_parameter_inst.S (const) */
    /* execute.a64:2636 [F] s_b_8_8 = (u64)s_b_8_7 (const) */
    /* execute.a64:2636 [D] s_b_8_9 = s_b_8_6<<s_b_8_8 */
    auto s_b_8_9 = emitter.shl(s_b_8_6, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1169 [D] s_b_8_10: sym_32327_0_rm = s_b_8_9, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_32327_0_rm, s_b_8_9);
    /* execute.a64:1169 [F] s_b_8_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1171 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:1171 [F] s_b_9_1: sym_32327_0_rm = s_b_9_0 (const), dominates: s_b_12_1  */
    CV_sym_32327_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_32327_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1172 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1171 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2701 [F] s_b_10_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_10_1 = __builtin_get_feature */
    uint32_t s_b_10_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(s_b_10_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
    if (s_b_10_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_2,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2733 [F] s_b_11_0=sym_32300_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_11_1 = ReadRegBank 0:s_b_11_0 (u64) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_11_2: sym_141834_0_return_symbol = s_b_11_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_141834_0_return_symbol, s_b_11_1);
    /* ???:4294967295 [F] s_b_11_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11, b_15,  */
  fixed_block_b_12: 
  {
    /* ???:4294967295 [D] s_b_12_0 = sym_141834_0_return_symbol uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_141834_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1175 [D] s_b_12_1 = sym_32327_0_rm uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_32327_0_rm, emitter.context().types().u64());
    /* execute.a64:1175 [D] s_b_12_2 = s_b_12_0+s_b_12_1 */
    auto s_b_12_2 = emitter.add(s_b_12_0, s_b_12_1);
    /* execute.a64:1177 [F] s_b_12_3=sym_32300_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_12_4 = (u32)s_b_12_3 (const) */
    /* execute.a64:2646 [F] s_b_12_5 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_12_6 = s_b_12_4==s_b_12_5 (const) */
    uint8_t s_b_12_6 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_12_7 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_12_8 = ReadRegBank 1:s_b_12_3 (u32) */
    auto s_b_12_8 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_12_8,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_12_9: Select s_b_12_6 ? s_b_12_7 : s_b_12_8 */
    captive::arch::dbt::el::Value *s_b_12_9;
    s_b_12_9 = (s_b_12_6) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_12_8);
    /* execute.a64:2659 [D] s_b_12_10 = (u64)s_b_12_9 */
    auto s_b_12_10 = emitter.zx(s_b_12_9, emitter.context().types().u64());
    /* execute.a64:1177 [D] s_b_12_11 = (u16)s_b_12_10 */
    auto s_b_12_11 = emitter.truncate(s_b_12_10, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_12_12: Store 2 s_b_12_2 <= s_b_12_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_12_2, s_b_12_11, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_12_2, s_b_12_11);
    /* ???:4294967295 [F] s_b_12_13: Return */
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2702 [D] s_b_13_0 = ReadReg 20 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_13_1: sym_141851_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_141851_1__R_s_b_3_0, s_b_13_0);
    /* execute.a64:2702 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:3012 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_14_1 = __builtin_get_feature */
    uint32_t s_b_14_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_14_2 = (u8)s_b_14_1 (const) */
    /* execute.a64:2704 [F] s_b_14_3 = (u32)s_b_14_2 (const) */
    /* execute.a64:2704 [F] s_b_14_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_14_5 = s_b_14_3==s_b_14_4 (const) */
    uint8_t s_b_14_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_14_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_14_6: If s_b_14_5: Jump b_16 else b_17 (const) */
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
    /* execute.a64:2731 [D] s_b_15_0 = sym_141851_1__R_s_b_3_0 uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_141851_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1: sym_141834_0_return_symbol = s_b_15_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_141834_0_return_symbol, s_b_15_0);
    /* ???:4294967295 [F] s_b_15_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2705 [D] s_b_16_0 = ReadReg 20 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_16_1: sym_141851_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_141851_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2705 [F] s_b_16_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2707 [D] s_b_17_0 = ReadReg 21 (u64) */
    auto s_b_17_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_17_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_17_1: sym_141851_1__R_s_b_3_0 = s_b_17_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_141851_1__R_s_b_3_0, s_b_17_0);
    /* execute.a64:2707 [F] s_b_17_2: Jump b_15 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sturh(const aarch64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_143118_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_143101_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1321 [F] s_b_0_0=sym_32585_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_2_0=sym_32585_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_143101_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_143101_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_143101_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_143101_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1322 [F] s_b_3_1=sym_32585_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1324 [F] s_b_3_4=sym_32585_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:2646 [F] s_b_3_6 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_3_8 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_3_9 = ReadRegBank 1:s_b_3_4 (u32) */
    auto s_b_3_9 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_3_9,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_3_10: Select s_b_3_7 ? s_b_3_8 : s_b_3_9 */
    captive::arch::dbt::el::Value *s_b_3_10;
    s_b_3_10 = (s_b_3_7) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_3_9);
    /* execute.a64:2659 [D] s_b_3_11 = (u64)s_b_3_10 */
    auto s_b_3_11 = emitter.zx(s_b_3_10, emitter.context().types().u64());
    /* execute.a64:1324 [D] s_b_3_12 = (u16)s_b_3_11 */
    auto s_b_3_12 = emitter.truncate(s_b_3_11, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_3_13: Store 2 s_b_3_3 <= s_b_3_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_3, s_b_3_12, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_3_3, s_b_3_12);
    /* ???:4294967295 [F] s_b_3_14: Return */
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2702 [D] s_b_4_0 = ReadReg 20 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_4_1: sym_143118_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_143118_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2731 [D] s_b_6_0 = sym_143118_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_143118_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_143101_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_143101_0_return_symbol, s_b_6_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_7_1: sym_143118_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_143118_1__R_s_b_3_0, s_b_7_0);
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
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_8_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_8_1: sym_143118_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_143118_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2707 [F] s_b_8_2: Jump b_6 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_subi(const aarch64_decode_a64_ADD_SUB_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_145968_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_145985_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_146065_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_145833_0_return_symbol;
  uint32_t CV_sym_145830_0_replaced_parameter_imm;
  auto DV_sym_145874_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_33164_0_imm;
  auto DV_sym_33169_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_145916_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_145939_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_146008_1__R_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:34 [F] s_b_0_0=sym_33158_3_parameter_inst.imm12 (const) */
    /* execute.a64:34 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:34 [F] s_b_0_2=sym_33158_3_parameter_inst.shift (const) */
    /* ???:4294967295 [F] s_b_0_3: sym_145830_0_replaced_parameter_imm = s_b_0_1 (const), dominates: s_b_8_0 s_b_6_0  */
    CV_sym_145830_0_replaced_parameter_imm = ((uint32_t)insn.imm12);
    /* execute.a64:2762 [F] s_b_0_4 = constant s32 0 (const) */
    /* execute.a64:2765 [F] s_b_0_5 = constant s32 1 (const) */
    /* execute.a64:2761 [F] s_b_0_6: Switch s_b_0_2: < <todo> > def b_9 (const) -> b_9, b_8, b_6,  */
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
    /* execute.a64:38 [F] s_b_1_0=sym_33158_3_parameter_inst.sf (const) */
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
    /* execute.a64:44 [F] s_b_3_0=sym_33158_3_parameter_inst.sf (const) */
    /* execute.a64:44 [D] s_b_3_1 = sym_33169_0_op1 uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_33169_0_op1, emitter.context().types().u64());
    /* execute.a64:44 [F] s_b_3_2 = sym_33164_0_imm (const) uint64_t */
    uint64_t s_b_3_2 = CV_sym_33164_0_imm;
    /* execute.a64:44 [D] s_b_3_3 = s_b_3_1-s_b_3_2 */
    auto s_b_3_3 = emitter.sub(s_b_3_1, emitter.const_u64(s_b_3_2));
    /* execute.a64:44 [D] s_b_3_4: sym_145874_3_parameter_value = s_b_3_3, dominates: s_b_10_0 s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_145874_3_parameter_value, s_b_3_3);
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
    /* execute.a64:39 [F] s_b_4_0=sym_33158_3_parameter_inst.rd (const) */
    /* execute.a64:39 [D] s_b_4_1 = sym_33169_0_op1 uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_33169_0_op1, emitter.context().types().u64());
    /* execute.a64:39 [D] s_b_4_2 = (u32)s_b_4_1 */
    auto s_b_4_2 = emitter.truncate(s_b_4_1, emitter.context().types().u32());
    /* execute.a64:39 [F] s_b_4_3 = sym_33164_0_imm (const) uint64_t */
    uint64_t s_b_4_3 = CV_sym_33164_0_imm;
    /* execute.a64:39 [F] s_b_4_4 = (u32)s_b_4_3 (const) */
    /* execute.a64:39 [F] s_b_4_5 = constant u8 0 (const) */
    /* execute.a64:39 [D] s_b_4_6 = __builtin_sbc32_flags */
    auto s_b_4_6 = emitter.sbcf(s_b_4_2, emitter.const_u32(((uint32_t)s_b_4_3)), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:39 [D] s_b_4_7: sym_145916_3_parameter_value = s_b_4_6, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_145916_3_parameter_value, s_b_4_6);
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
    /* execute.a64:41 [F] s_b_5_0=sym_33158_3_parameter_inst.rd (const) */
    /* execute.a64:41 [D] s_b_5_1 = sym_33169_0_op1 uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_33169_0_op1, emitter.context().types().u64());
    /* execute.a64:41 [F] s_b_5_2 = sym_33164_0_imm (const) uint64_t */
    uint64_t s_b_5_2 = CV_sym_33164_0_imm;
    /* execute.a64:41 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.a64:41 [D] s_b_5_4 = __builtin_sbc64_flags */
    auto s_b_5_4 = emitter.sbcf(s_b_5_1, emitter.const_u64(s_b_5_2), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:41 [D] s_b_5_5: sym_145939_3_parameter_value = s_b_5_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_145939_3_parameter_value, s_b_5_4);
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
    /* execute.a64:2763 [F] s_b_6_0 = sym_145830_0_replaced_parameter_imm (const) uint32_t */
    uint32_t s_b_6_0 = CV_sym_145830_0_replaced_parameter_imm;
    /* execute.a64:2763 [F] s_b_6_1 = (u64)s_b_6_0 (const) */
    /* ???:4294967295 [F] s_b_6_2: sym_145833_0_return_symbol = s_b_6_1 (const), dominates: s_b_7_0  */
    CV_sym_145833_0_return_symbol = ((uint64_t)s_b_6_0);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_8, b_9,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [F] s_b_7_0 = sym_145833_0_return_symbol (const) uint64_t */
    uint64_t s_b_7_0 = CV_sym_145833_0_return_symbol;
    /* execute.a64:34 [F] s_b_7_1: sym_33164_0_imm = s_b_7_0 (const), dominates: s_b_4_3 s_b_5_2 s_b_3_2  */
    CV_sym_33164_0_imm = s_b_7_0;
    /* execute.a64:35 [F] s_b_7_2=sym_33158_3_parameter_inst.sf (const) */
    /* execute.a64:2729 [F] s_b_7_3: If s_b_7_2: Jump b_16 else b_19 (const) */
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
    /* execute.a64:2766 [F] s_b_8_0 = sym_145830_0_replaced_parameter_imm (const) uint32_t */
    uint32_t s_b_8_0 = CV_sym_145830_0_replaced_parameter_imm;
    /* execute.a64:2766 [F] s_b_8_1 = constant u32 c (const) */
    /* execute.a64:2766 [F] s_b_8_2 = s_b_8_0<<s_b_8_1 (const) */
    uint32_t s_b_8_2 = ((uint32_t)(s_b_8_0 << (uint32_t)12ULL));
    /* execute.a64:2766 [F] s_b_8_3 = (u64)s_b_8_2 (const) */
    /* ???:4294967295 [F] s_b_8_4: sym_145833_0_return_symbol = s_b_8_3 (const), dominates: s_b_7_0  */
    CV_sym_145833_0_return_symbol = ((uint64_t)s_b_8_2);
    /* ???:4294967295 [F] s_b_8_5: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2769 [F] s_b_9_0 = constant u64 0 (const) */
    /* ???:4294967295 [F] s_b_9_1: sym_145833_0_return_symbol = s_b_9_0 (const), dominates: s_b_7_0  */
    CV_sym_145833_0_return_symbol = (uint64_t)0ULL;
    /* ???:4294967295 [F] s_b_9_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2747 [D] s_b_10_0 = sym_145874_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_145874_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_10_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_10_2 = s_b_10_0&s_b_10_1 */
    auto s_b_10_2 = emitter.bitwise_and(s_b_10_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_10_3: sym_145874_3_parameter_value = s_b_10_2, dominates: s_b_12_0 s_b_13_1  */
    emitter.store_local(DV_sym_145874_3_parameter_value, s_b_10_2);
    /* execute.a64:2747 [F] s_b_10_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2750 [F] s_b_11_0=sym_33158_3_parameter_inst.rd (const) */
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
    /* execute.a64:2751 [D] s_b_12_0 = sym_145874_3_parameter_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_145874_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_12_1: sym_146065_3_parameter_value = s_b_12_0, dominates: s_b_33_0 s_b_34_0 s_b_35_0  */
    emitter.store_local(DV_sym_146065_3_parameter_value, s_b_12_0);
    /* execute.a64:2714 [F] s_b_12_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_12_3 = __builtin_get_feature */
    uint32_t s_b_12_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(s_b_12_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_12_6: If s_b_12_5: Jump b_33 else b_36 (const) */
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
    /* execute.a64:2753 [F] s_b_13_0=sym_33158_3_parameter_inst.rd (const) */
    /* execute.a64:2753 [D] s_b_13_1 = sym_145874_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_145874_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_13_1);
    /* execute.a64:2753 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2676 [F] s_b_14_0=sym_33158_3_parameter_inst.rd (const) */
    /* execute.a64:2676 [D] s_b_14_1 = sym_145916_3_parameter_value uint32_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_145916_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2676 [D] s_b_14_2 = (u64)s_b_14_1 */
    auto s_b_14_2 = emitter.zx(s_b_14_1, emitter.context().types().u64());
    /* execute.a64:2676 [D] s_b_14_3: WriteRegBank 0:s_b_14_0 = s_b_14_2 */
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
    /* execute.a64:2684 [F] s_b_15_0=sym_33158_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_145939_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_145939_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
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
    /* execute.a64:2730 [F] s_b_16_0=sym_33158_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2730 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
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
    /* execute.a64:2701 [F] s_b_17_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_17_1 = __builtin_get_feature */
    uint32_t s_b_17_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(s_b_17_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_17_4: If s_b_17_3: Jump b_23 else b_24 (const) */
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
    /* execute.a64:2733 [F] s_b_18_0=sym_33158_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_18_2: sym_145968_0_return_symbol = s_b_18_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_145968_0_return_symbol, s_b_18_1);
    /* ???:4294967295 [F] s_b_18_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_7,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2736 [F] s_b_19_0=sym_33158_3_parameter_inst.rn (const) */
    /* execute.a64:2736 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2736 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2736 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2736 [F] s_b_19_4: If s_b_19_3: Jump b_20 else b_21 (const) */
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
    /* execute.a64:2701 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_20_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_20_4: If s_b_20_3: Jump b_28 else b_29 (const) */
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
    /* execute.a64:2739 [F] s_b_21_0=sym_33158_3_parameter_inst.rn (const) */
    /* execute.a64:2739 [D] s_b_21_1 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_1,emitter.const_u8(4));
    }
    /* execute.a64:2739 [D] s_b_21_2 = (u64)s_b_21_1 */
    auto s_b_21_2 = emitter.zx(s_b_21_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_3: sym_145968_0_return_symbol = s_b_21_2, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_145968_0_return_symbol, s_b_21_2);
    /* ???:4294967295 [F] s_b_21_4: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_18, b_21, b_25, b_30,  */
  fixed_block_b_22: 
  {
    /* ???:4294967295 [D] s_b_22_0 = sym_145968_0_return_symbol uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_145968_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:35 [D] s_b_22_1: sym_33169_0_op1 = s_b_22_0, dominates: s_b_4_1 s_b_5_1 s_b_3_1  */
    emitter.store_local(DV_sym_33169_0_op1, s_b_22_0);
    /* execute.a64:37 [F] s_b_22_2=sym_33158_3_parameter_inst.S (const) */
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
    /* execute.a64:2702 [D] s_b_23_0 = ReadReg 20 (u64) */
    auto s_b_23_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_23_1: sym_145985_1__R_s_b_3_0 = s_b_23_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_145985_1__R_s_b_3_0, s_b_23_0);
    /* execute.a64:2702 [F] s_b_23_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_17,  */
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
    /* execute.a64:2731 [D] s_b_25_0 = sym_145985_1__R_s_b_3_0 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_145985_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_25_1: sym_145968_0_return_symbol = s_b_25_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_145968_0_return_symbol, s_b_25_0);
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
    /* execute.a64:2705 [D] s_b_26_1: sym_145985_1__R_s_b_3_0 = s_b_26_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_145985_1__R_s_b_3_0, s_b_26_0);
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
    /* execute.a64:2707 [D] s_b_27_1: sym_145985_1__R_s_b_3_0 = s_b_27_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_145985_1__R_s_b_3_0, s_b_27_0);
    /* execute.a64:2707 [F] s_b_27_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_20,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2702 [D] s_b_28_0 = ReadReg 20 (u64) */
    auto s_b_28_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_28_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_28_1: sym_146008_1__R_s_b_5_0 = s_b_28_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_146008_1__R_s_b_5_0, s_b_28_0);
    /* execute.a64:2702 [F] s_b_28_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_20,  */
  fixed_block_b_29: 
  {
    /* execute.a64:3012 [F] s_b_29_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_29_1 = __builtin_get_feature */
    uint32_t s_b_29_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_29_2 = (u8)s_b_29_1 (const) */
    /* execute.a64:2704 [F] s_b_29_3 = (u32)s_b_29_2 (const) */
    /* execute.a64:2704 [F] s_b_29_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_29_5 = s_b_29_3==s_b_29_4 (const) */
    uint8_t s_b_29_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_29_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_29_6: If s_b_29_5: Jump b_31 else b_32 (const) */
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
    /* execute.a64:2737 [D] s_b_30_0 = sym_146008_1__R_s_b_5_0 uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_146008_1__R_s_b_5_0, emitter.context().types().u64());
    /* execute.a64:2737 [D] s_b_30_1 = (u32)s_b_30_0 */
    auto s_b_30_1 = emitter.truncate(s_b_30_0, emitter.context().types().u32());
    /* execute.a64:2737 [D] s_b_30_2 = (u64)s_b_30_1 */
    auto s_b_30_2 = emitter.zx(s_b_30_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_30_3: sym_145968_0_return_symbol = s_b_30_2, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_145968_0_return_symbol, s_b_30_2);
    /* ???:4294967295 [F] s_b_30_4: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_29,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2705 [D] s_b_31_0 = ReadReg 20 (u64) */
    auto s_b_31_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_31_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_31_1: sym_146008_1__R_s_b_5_0 = s_b_31_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_146008_1__R_s_b_5_0, s_b_31_0);
    /* execute.a64:2705 [F] s_b_31_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_29,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2707 [D] s_b_32_0 = ReadReg 21 (u64) */
    auto s_b_32_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_32_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_32_1: sym_146008_1__R_s_b_5_0 = s_b_32_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_146008_1__R_s_b_5_0, s_b_32_0);
    /* execute.a64:2707 [F] s_b_32_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_12,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2715 [D] s_b_33_0 = sym_146065_3_parameter_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_146065_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_33_1: WriteReg 20 = s_b_33_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_33_0);
    /* execute.a64:2715 [F] s_b_33_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_36,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2718 [D] s_b_34_0 = sym_146065_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_146065_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_34_1: WriteReg 20 = s_b_34_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_34_0);
    /* execute.a64:2718 [F] s_b_34_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_36,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2720 [D] s_b_35_0 = sym_146065_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_146065_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_35_1: WriteReg 21 = s_b_35_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_35_0);
    /* execute.a64:2720 [F] s_b_35_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_36: 
  {
    /* execute.a64:3012 [F] s_b_36_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_36_1 = __builtin_get_feature */
    uint32_t s_b_36_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_36_2 = (u8)s_b_36_1 (const) */
    /* execute.a64:2717 [F] s_b_36_3 = (u32)s_b_36_2 (const) */
    /* execute.a64:2717 [F] s_b_36_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_36_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_36_6: If s_b_36_5: Jump b_34 else b_35 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_uaddlv(const aarch64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_uminv(const aarch64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_usubl(const aarch64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5754 [F] s_b_0_0=sym_43903_3_parameter_inst.tb (const) */
    /* execute.simd:5755 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5767 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5779 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5791 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5803 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5815 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5754 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5756 [F] s_b_2_0=sym_43903_3_parameter_inst.rn (const) */
    /* execute.simd:5756 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5756 [D] s_b_2_2 = (v8u8)s_b_2_1 */
    auto s_b_2_2 = (captive::arch::dbt::el::Value *)s_b_2_1;
    /* execute.simd:5757 [F] s_b_2_3=sym_43903_3_parameter_inst.rm (const) */
    /* execute.simd:5757 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5757 [D] s_b_2_5 = (v8u8)s_b_2_4 */
    auto s_b_2_5 = (captive::arch::dbt::el::Value *)s_b_2_4;
    /* ???:4294967295 [F] s_b_2_6 = constant v8u16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5761 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5761 [D] s_b_2_9 = (u16)s_b_2_8 */
    auto s_b_2_9 = emitter.zx(s_b_2_8, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5761 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5761 [D] s_b_2_12 = (u16)s_b_2_11 */
    auto s_b_2_12 = emitter.zx(s_b_2_11, emitter.context().types().u16());
    /* execute.simd:5761 [D] s_b_2_13 = s_b_2_9-s_b_2_12 */
    auto s_b_2_13 = emitter.sub(s_b_2_9, s_b_2_12);
    /* execute.simd:5761 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5761 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5761 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5761 [D] s_b_2_18 = (u16)s_b_2_17 */
    auto s_b_2_18 = emitter.zx(s_b_2_17, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5761 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5761 [D] s_b_2_21 = (u16)s_b_2_20 */
    auto s_b_2_21 = emitter.zx(s_b_2_20, emitter.context().types().u16());
    /* execute.simd:5761 [D] s_b_2_22 = s_b_2_18-s_b_2_21 */
    auto s_b_2_22 = emitter.sub(s_b_2_18, s_b_2_21);
    /* execute.simd:5761 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5761 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5761 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5761 [D] s_b_2_27 = (u16)s_b_2_26 */
    auto s_b_2_27 = emitter.zx(s_b_2_26, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5761 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5761 [D] s_b_2_30 = (u16)s_b_2_29 */
    auto s_b_2_30 = emitter.zx(s_b_2_29, emitter.context().types().u16());
    /* execute.simd:5761 [D] s_b_2_31 = s_b_2_27-s_b_2_30 */
    auto s_b_2_31 = emitter.sub(s_b_2_27, s_b_2_30);
    /* execute.simd:5761 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5761 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5761 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5761 [D] s_b_2_36 = (u16)s_b_2_35 */
    auto s_b_2_36 = emitter.zx(s_b_2_35, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5761 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5761 [D] s_b_2_39 = (u16)s_b_2_38 */
    auto s_b_2_39 = emitter.zx(s_b_2_38, emitter.context().types().u16());
    /* execute.simd:5761 [D] s_b_2_40 = s_b_2_36-s_b_2_39 */
    auto s_b_2_40 = emitter.sub(s_b_2_36, s_b_2_39);
    /* execute.simd:5761 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5761 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5761 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5761 [D] s_b_2_45 = (u16)s_b_2_44 */
    auto s_b_2_45 = emitter.zx(s_b_2_44, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5761 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5761 [D] s_b_2_48 = (u16)s_b_2_47 */
    auto s_b_2_48 = emitter.zx(s_b_2_47, emitter.context().types().u16());
    /* execute.simd:5761 [D] s_b_2_49 = s_b_2_45-s_b_2_48 */
    auto s_b_2_49 = emitter.sub(s_b_2_45, s_b_2_48);
    /* execute.simd:5761 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5761 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5761 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5761 [D] s_b_2_54 = (u16)s_b_2_53 */
    auto s_b_2_54 = emitter.zx(s_b_2_53, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5761 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5761 [D] s_b_2_57 = (u16)s_b_2_56 */
    auto s_b_2_57 = emitter.zx(s_b_2_56, emitter.context().types().u16());
    /* execute.simd:5761 [D] s_b_2_58 = s_b_2_54-s_b_2_57 */
    auto s_b_2_58 = emitter.sub(s_b_2_54, s_b_2_57);
    /* execute.simd:5761 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5761 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5761 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5761 [D] s_b_2_63 = (u16)s_b_2_62 */
    auto s_b_2_63 = emitter.zx(s_b_2_62, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5761 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5761 [D] s_b_2_66 = (u16)s_b_2_65 */
    auto s_b_2_66 = emitter.zx(s_b_2_65, emitter.context().types().u16());
    /* execute.simd:5761 [D] s_b_2_67 = s_b_2_63-s_b_2_66 */
    auto s_b_2_67 = emitter.sub(s_b_2_63, s_b_2_66);
    /* execute.simd:5761 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5761 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5761 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5761 [D] s_b_2_72 = (u16)s_b_2_71 */
    auto s_b_2_72 = emitter.zx(s_b_2_71, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5761 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5761 [D] s_b_2_75 = (u16)s_b_2_74 */
    auto s_b_2_75 = emitter.zx(s_b_2_74, emitter.context().types().u16());
    /* execute.simd:5761 [D] s_b_2_76 = s_b_2_72-s_b_2_75 */
    auto s_b_2_76 = emitter.sub(s_b_2_72, s_b_2_75);
    /* execute.simd:5761 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5761 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5764 [F] s_b_2_79=sym_43903_3_parameter_inst.rd (const) */
    /* execute.simd:5764 [D] s_b_2_80: WriteRegBank 18:s_b_2_79 = s_b_2_78 */
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
    /* execute.simd:5768 [F] s_b_3_0=sym_43903_3_parameter_inst.rn (const) */
    /* execute.simd:5768 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5768 [D] s_b_3_2 = (v16u8)s_b_3_1 */
    auto s_b_3_2 = (captive::arch::dbt::el::Value *)s_b_3_1;
    /* execute.simd:5769 [F] s_b_3_3=sym_43903_3_parameter_inst.rm (const) */
    /* execute.simd:5769 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5769 [D] s_b_3_5 = (v16u8)s_b_3_4 */
    auto s_b_3_5 = (captive::arch::dbt::el::Value *)s_b_3_4;
    /* ???:4294967295 [F] s_b_3_6 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5773 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5773 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5773 [D] s_b_3_9 = (u16)s_b_3_8 */
    auto s_b_3_9 = emitter.zx(s_b_3_8, emitter.context().types().u16());
    /* execute.simd:5773 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5773 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5773 [D] s_b_3_12 = (u16)s_b_3_11 */
    auto s_b_3_12 = emitter.zx(s_b_3_11, emitter.context().types().u16());
    /* execute.simd:5773 [D] s_b_3_13 = s_b_3_9-s_b_3_12 */
    auto s_b_3_13 = emitter.sub(s_b_3_9, s_b_3_12);
    /* execute.simd:5773 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5773 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5773 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5773 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5773 [D] s_b_3_18 = (u16)s_b_3_17 */
    auto s_b_3_18 = emitter.zx(s_b_3_17, emitter.context().types().u16());
    /* execute.simd:5773 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5773 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5773 [D] s_b_3_21 = (u16)s_b_3_20 */
    auto s_b_3_21 = emitter.zx(s_b_3_20, emitter.context().types().u16());
    /* execute.simd:5773 [D] s_b_3_22 = s_b_3_18-s_b_3_21 */
    auto s_b_3_22 = emitter.sub(s_b_3_18, s_b_3_21);
    /* execute.simd:5773 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5773 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5773 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5773 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5773 [D] s_b_3_27 = (u16)s_b_3_26 */
    auto s_b_3_27 = emitter.zx(s_b_3_26, emitter.context().types().u16());
    /* execute.simd:5773 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5773 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5773 [D] s_b_3_30 = (u16)s_b_3_29 */
    auto s_b_3_30 = emitter.zx(s_b_3_29, emitter.context().types().u16());
    /* execute.simd:5773 [D] s_b_3_31 = s_b_3_27-s_b_3_30 */
    auto s_b_3_31 = emitter.sub(s_b_3_27, s_b_3_30);
    /* execute.simd:5773 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5773 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5773 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5773 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5773 [D] s_b_3_36 = (u16)s_b_3_35 */
    auto s_b_3_36 = emitter.zx(s_b_3_35, emitter.context().types().u16());
    /* execute.simd:5773 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5773 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5773 [D] s_b_3_39 = (u16)s_b_3_38 */
    auto s_b_3_39 = emitter.zx(s_b_3_38, emitter.context().types().u16());
    /* execute.simd:5773 [D] s_b_3_40 = s_b_3_36-s_b_3_39 */
    auto s_b_3_40 = emitter.sub(s_b_3_36, s_b_3_39);
    /* execute.simd:5773 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5773 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5773 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5773 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5773 [D] s_b_3_45 = (u16)s_b_3_44 */
    auto s_b_3_45 = emitter.zx(s_b_3_44, emitter.context().types().u16());
    /* execute.simd:5773 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5773 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5773 [D] s_b_3_48 = (u16)s_b_3_47 */
    auto s_b_3_48 = emitter.zx(s_b_3_47, emitter.context().types().u16());
    /* execute.simd:5773 [D] s_b_3_49 = s_b_3_45-s_b_3_48 */
    auto s_b_3_49 = emitter.sub(s_b_3_45, s_b_3_48);
    /* execute.simd:5773 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5773 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5773 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5773 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5773 [D] s_b_3_54 = (u16)s_b_3_53 */
    auto s_b_3_54 = emitter.zx(s_b_3_53, emitter.context().types().u16());
    /* execute.simd:5773 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5773 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5773 [D] s_b_3_57 = (u16)s_b_3_56 */
    auto s_b_3_57 = emitter.zx(s_b_3_56, emitter.context().types().u16());
    /* execute.simd:5773 [D] s_b_3_58 = s_b_3_54-s_b_3_57 */
    auto s_b_3_58 = emitter.sub(s_b_3_54, s_b_3_57);
    /* execute.simd:5773 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5773 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5773 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5773 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5773 [D] s_b_3_63 = (u16)s_b_3_62 */
    auto s_b_3_63 = emitter.zx(s_b_3_62, emitter.context().types().u16());
    /* execute.simd:5773 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5773 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5773 [D] s_b_3_66 = (u16)s_b_3_65 */
    auto s_b_3_66 = emitter.zx(s_b_3_65, emitter.context().types().u16());
    /* execute.simd:5773 [D] s_b_3_67 = s_b_3_63-s_b_3_66 */
    auto s_b_3_67 = emitter.sub(s_b_3_63, s_b_3_66);
    /* execute.simd:5773 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5773 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5773 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5773 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5773 [D] s_b_3_72 = (u16)s_b_3_71 */
    auto s_b_3_72 = emitter.zx(s_b_3_71, emitter.context().types().u16());
    /* execute.simd:5773 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5773 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5773 [D] s_b_3_75 = (u16)s_b_3_74 */
    auto s_b_3_75 = emitter.zx(s_b_3_74, emitter.context().types().u16());
    /* execute.simd:5773 [D] s_b_3_76 = s_b_3_72-s_b_3_75 */
    auto s_b_3_76 = emitter.sub(s_b_3_72, s_b_3_75);
    /* execute.simd:5773 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5773 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5776 [F] s_b_3_79=sym_43903_3_parameter_inst.rd (const) */
    /* execute.simd:5776 [D] s_b_3_80: WriteRegBank 18:s_b_3_79 = s_b_3_78 */
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
    /* execute.simd:5780 [F] s_b_4_0=sym_43903_3_parameter_inst.rn (const) */
    /* execute.simd:5780 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5780 [D] s_b_4_2 = (v4u16)s_b_4_1 */
    auto s_b_4_2 = (captive::arch::dbt::el::Value *)s_b_4_1;
    /* execute.simd:5781 [F] s_b_4_3=sym_43903_3_parameter_inst.rm (const) */
    /* execute.simd:5781 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5781 [D] s_b_4_5 = (v4u16)s_b_4_4 */
    auto s_b_4_5 = (captive::arch::dbt::el::Value *)s_b_4_4;
    /* ???:4294967295 [F] s_b_4_6 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5785 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5785 [D] s_b_4_9 = (u32)s_b_4_8 */
    auto s_b_4_9 = emitter.zx(s_b_4_8, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5785 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5785 [D] s_b_4_12 = (u32)s_b_4_11 */
    auto s_b_4_12 = emitter.zx(s_b_4_11, emitter.context().types().u32());
    /* execute.simd:5785 [D] s_b_4_13 = s_b_4_9-s_b_4_12 */
    auto s_b_4_13 = emitter.sub(s_b_4_9, s_b_4_12);
    /* execute.simd:5785 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5785 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5785 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5785 [D] s_b_4_18 = (u32)s_b_4_17 */
    auto s_b_4_18 = emitter.zx(s_b_4_17, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5785 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5785 [D] s_b_4_21 = (u32)s_b_4_20 */
    auto s_b_4_21 = emitter.zx(s_b_4_20, emitter.context().types().u32());
    /* execute.simd:5785 [D] s_b_4_22 = s_b_4_18-s_b_4_21 */
    auto s_b_4_22 = emitter.sub(s_b_4_18, s_b_4_21);
    /* execute.simd:5785 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5785 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5785 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5785 [D] s_b_4_27 = (u32)s_b_4_26 */
    auto s_b_4_27 = emitter.zx(s_b_4_26, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5785 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5785 [D] s_b_4_30 = (u32)s_b_4_29 */
    auto s_b_4_30 = emitter.zx(s_b_4_29, emitter.context().types().u32());
    /* execute.simd:5785 [D] s_b_4_31 = s_b_4_27-s_b_4_30 */
    auto s_b_4_31 = emitter.sub(s_b_4_27, s_b_4_30);
    /* execute.simd:5785 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5785 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5785 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5785 [D] s_b_4_36 = (u32)s_b_4_35 */
    auto s_b_4_36 = emitter.zx(s_b_4_35, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5785 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5785 [D] s_b_4_39 = (u32)s_b_4_38 */
    auto s_b_4_39 = emitter.zx(s_b_4_38, emitter.context().types().u32());
    /* execute.simd:5785 [D] s_b_4_40 = s_b_4_36-s_b_4_39 */
    auto s_b_4_40 = emitter.sub(s_b_4_36, s_b_4_39);
    /* execute.simd:5785 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5785 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5788 [F] s_b_4_43=sym_43903_3_parameter_inst.rd (const) */
    /* execute.simd:5788 [D] s_b_4_44: WriteRegBank 20:s_b_4_43 = s_b_4_42 */
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
    /* execute.simd:5792 [F] s_b_5_0=sym_43903_3_parameter_inst.rn (const) */
    /* execute.simd:5792 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5792 [D] s_b_5_2 = (v8u16)s_b_5_1 */
    auto s_b_5_2 = (captive::arch::dbt::el::Value *)s_b_5_1;
    /* execute.simd:5793 [F] s_b_5_3=sym_43903_3_parameter_inst.rm (const) */
    /* execute.simd:5793 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5793 [D] s_b_5_5 = (v8u16)s_b_5_4 */
    auto s_b_5_5 = (captive::arch::dbt::el::Value *)s_b_5_4;
    /* ???:4294967295 [F] s_b_5_6 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5797 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5797 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5797 [D] s_b_5_9 = (u32)s_b_5_8 */
    auto s_b_5_9 = emitter.zx(s_b_5_8, emitter.context().types().u32());
    /* execute.simd:5797 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5797 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5797 [D] s_b_5_12 = (u32)s_b_5_11 */
    auto s_b_5_12 = emitter.zx(s_b_5_11, emitter.context().types().u32());
    /* execute.simd:5797 [D] s_b_5_13 = s_b_5_9-s_b_5_12 */
    auto s_b_5_13 = emitter.sub(s_b_5_9, s_b_5_12);
    /* execute.simd:5797 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5797 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5797 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5797 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5797 [D] s_b_5_18 = (u32)s_b_5_17 */
    auto s_b_5_18 = emitter.zx(s_b_5_17, emitter.context().types().u32());
    /* execute.simd:5797 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5797 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5797 [D] s_b_5_21 = (u32)s_b_5_20 */
    auto s_b_5_21 = emitter.zx(s_b_5_20, emitter.context().types().u32());
    /* execute.simd:5797 [D] s_b_5_22 = s_b_5_18-s_b_5_21 */
    auto s_b_5_22 = emitter.sub(s_b_5_18, s_b_5_21);
    /* execute.simd:5797 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5797 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5797 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5797 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5797 [D] s_b_5_27 = (u32)s_b_5_26 */
    auto s_b_5_27 = emitter.zx(s_b_5_26, emitter.context().types().u32());
    /* execute.simd:5797 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5797 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5797 [D] s_b_5_30 = (u32)s_b_5_29 */
    auto s_b_5_30 = emitter.zx(s_b_5_29, emitter.context().types().u32());
    /* execute.simd:5797 [D] s_b_5_31 = s_b_5_27-s_b_5_30 */
    auto s_b_5_31 = emitter.sub(s_b_5_27, s_b_5_30);
    /* execute.simd:5797 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5797 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5797 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5797 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5797 [D] s_b_5_36 = (u32)s_b_5_35 */
    auto s_b_5_36 = emitter.zx(s_b_5_35, emitter.context().types().u32());
    /* execute.simd:5797 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5797 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5797 [D] s_b_5_39 = (u32)s_b_5_38 */
    auto s_b_5_39 = emitter.zx(s_b_5_38, emitter.context().types().u32());
    /* execute.simd:5797 [D] s_b_5_40 = s_b_5_36-s_b_5_39 */
    auto s_b_5_40 = emitter.sub(s_b_5_36, s_b_5_39);
    /* execute.simd:5797 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5797 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5800 [F] s_b_5_43=sym_43903_3_parameter_inst.rd (const) */
    /* execute.simd:5800 [D] s_b_5_44: WriteRegBank 20:s_b_5_43 = s_b_5_42 */
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
    /* execute.simd:5804 [F] s_b_6_0=sym_43903_3_parameter_inst.rn (const) */
    /* execute.simd:5804 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5804 [D] s_b_6_2 = (v2u32)s_b_6_1 */
    auto s_b_6_2 = (captive::arch::dbt::el::Value *)s_b_6_1;
    /* execute.simd:5805 [F] s_b_6_3=sym_43903_3_parameter_inst.rm (const) */
    /* execute.simd:5805 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5805 [D] s_b_6_5 = (v2u32)s_b_6_4 */
    auto s_b_6_5 = (captive::arch::dbt::el::Value *)s_b_6_4;
    /* ???:4294967295 [F] s_b_6_6 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5809 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5809 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5809 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5809 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.simd:5809 [D] s_b_6_13 = s_b_6_9-s_b_6_12 */
    auto s_b_6_13 = emitter.sub(s_b_6_9, s_b_6_12);
    /* execute.simd:5809 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5809 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5809 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5809 [D] s_b_6_18 = (u64)s_b_6_17 */
    auto s_b_6_18 = emitter.zx(s_b_6_17, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5809 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5809 [D] s_b_6_21 = (u64)s_b_6_20 */
    auto s_b_6_21 = emitter.zx(s_b_6_20, emitter.context().types().u64());
    /* execute.simd:5809 [D] s_b_6_22 = s_b_6_18-s_b_6_21 */
    auto s_b_6_22 = emitter.sub(s_b_6_18, s_b_6_21);
    /* execute.simd:5809 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5809 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:5812 [F] s_b_6_25=sym_43903_3_parameter_inst.rd (const) */
    /* execute.simd:5812 [D] s_b_6_26: WriteRegBank 21:s_b_6_25 = s_b_6_24 */
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
    /* execute.simd:5816 [F] s_b_7_0=sym_43903_3_parameter_inst.rn (const) */
    /* execute.simd:5816 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5816 [D] s_b_7_2 = (v4u32)s_b_7_1 */
    auto s_b_7_2 = (captive::arch::dbt::el::Value *)s_b_7_1;
    /* execute.simd:5817 [F] s_b_7_3=sym_43903_3_parameter_inst.rm (const) */
    /* execute.simd:5817 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5817 [D] s_b_7_5 = (v4u32)s_b_7_4 */
    auto s_b_7_5 = (captive::arch::dbt::el::Value *)s_b_7_4;
    /* ???:4294967295 [F] s_b_7_6 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5821 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:5821 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5821 [D] s_b_7_9 = (u64)s_b_7_8 */
    auto s_b_7_9 = emitter.zx(s_b_7_8, emitter.context().types().u64());
    /* execute.simd:5821 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:5821 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5821 [D] s_b_7_12 = (u64)s_b_7_11 */
    auto s_b_7_12 = emitter.zx(s_b_7_11, emitter.context().types().u64());
    /* execute.simd:5821 [D] s_b_7_13 = s_b_7_9-s_b_7_12 */
    auto s_b_7_13 = emitter.sub(s_b_7_9, s_b_7_12);
    /* execute.simd:5821 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:5821 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:5821 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:5821 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5821 [D] s_b_7_18 = (u64)s_b_7_17 */
    auto s_b_7_18 = emitter.zx(s_b_7_17, emitter.context().types().u64());
    /* execute.simd:5821 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:5821 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5821 [D] s_b_7_21 = (u64)s_b_7_20 */
    auto s_b_7_21 = emitter.zx(s_b_7_20, emitter.context().types().u64());
    /* execute.simd:5821 [D] s_b_7_22 = s_b_7_18-s_b_7_21 */
    auto s_b_7_22 = emitter.sub(s_b_7_18, s_b_7_21);
    /* execute.simd:5821 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:5821 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:5824 [F] s_b_7_25=sym_43903_3_parameter_inst.rd (const) */
    /* execute.simd:5824 [D] s_b_7_26: WriteRegBank 21:s_b_7_25 = s_b_7_24 */
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
    /* execute.simd:5828 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5754 [F] s_b_8_1: Jump b_1 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_xtn(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2132 [F] s_b_0_0=sym_46415_3_parameter_inst.arrangement (const) */
    /* execute.simd:2133 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:2150 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:2167 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:2180 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:2193 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:2204 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:2132 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:2134 [F] s_b_2_0=sym_46415_3_parameter_inst.rn (const) */
    /* execute.simd:2134 [D] s_b_2_1 = ReadRegBank 18:s_b_2_0 (v8u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_2_2 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:2137 [F] s_b_2_3 = constant s32 0 (const) */
    /* execute.simd:2137 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2137 [D] s_b_2_5 = (u8)s_b_2_4 */
    auto s_b_2_5 = emitter.truncate(s_b_2_4, emitter.context().types().u8());
    /* execute.simd:2137 [F] s_b_2_6 = constant s32 0 (const) */
    /* execute.simd:2137 [D] s_b_2_7 = s_b_2_2[s_b_2_6] <= s_b_2_5 */
    auto s_b_2_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_2_5);
    /* execute.simd:2138 [F] s_b_2_8 = constant s32 1 (const) */
    /* execute.simd:2138 [D] s_b_2_1[s_b_2_8] */
    auto s_b_2_9 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2138 [D] s_b_2_10 = (u8)s_b_2_9 */
    auto s_b_2_10 = emitter.truncate(s_b_2_9, emitter.context().types().u8());
    /* execute.simd:2138 [F] s_b_2_11 = constant s32 1 (const) */
    /* execute.simd:2138 [D] s_b_2_12 = s_b_2_7[s_b_2_11] <= s_b_2_10 */
    auto s_b_2_12 = emitter.vector_insert(s_b_2_7, emitter.const_s32((int32_t)1ULL), s_b_2_10);
    /* execute.simd:2139 [F] s_b_2_13 = constant s32 2 (const) */
    /* execute.simd:2139 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2139 [D] s_b_2_15 = (u8)s_b_2_14 */
    auto s_b_2_15 = emitter.truncate(s_b_2_14, emitter.context().types().u8());
    /* execute.simd:2139 [F] s_b_2_16 = constant s32 2 (const) */
    /* execute.simd:2139 [D] s_b_2_17 = s_b_2_12[s_b_2_16] <= s_b_2_15 */
    auto s_b_2_17 = emitter.vector_insert(s_b_2_12, emitter.const_s32((int32_t)2ULL), s_b_2_15);
    /* execute.simd:2140 [F] s_b_2_18 = constant s32 3 (const) */
    /* execute.simd:2140 [D] s_b_2_1[s_b_2_18] */
    auto s_b_2_19 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2140 [D] s_b_2_20 = (u8)s_b_2_19 */
    auto s_b_2_20 = emitter.truncate(s_b_2_19, emitter.context().types().u8());
    /* execute.simd:2140 [F] s_b_2_21 = constant s32 3 (const) */
    /* execute.simd:2140 [D] s_b_2_22 = s_b_2_17[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_17, emitter.const_s32((int32_t)3ULL), s_b_2_20);
    /* execute.simd:2141 [F] s_b_2_23 = constant s32 4 (const) */
    /* execute.simd:2141 [D] s_b_2_1[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:2141 [D] s_b_2_25 = (u8)s_b_2_24 */
    auto s_b_2_25 = emitter.truncate(s_b_2_24, emitter.context().types().u8());
    /* execute.simd:2141 [F] s_b_2_26 = constant s32 4 (const) */
    /* execute.simd:2141 [D] s_b_2_27 = s_b_2_22[s_b_2_26] <= s_b_2_25 */
    auto s_b_2_27 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)4ULL), s_b_2_25);
    /* execute.simd:2142 [F] s_b_2_28 = constant s32 5 (const) */
    /* execute.simd:2142 [D] s_b_2_1[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:2142 [D] s_b_2_30 = (u8)s_b_2_29 */
    auto s_b_2_30 = emitter.truncate(s_b_2_29, emitter.context().types().u8());
    /* execute.simd:2142 [F] s_b_2_31 = constant s32 5 (const) */
    /* execute.simd:2142 [D] s_b_2_32 = s_b_2_27[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_27, emitter.const_s32((int32_t)5ULL), s_b_2_30);
    /* execute.simd:2143 [F] s_b_2_33 = constant s32 6 (const) */
    /* execute.simd:2143 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:2143 [D] s_b_2_35 = (u8)s_b_2_34 */
    auto s_b_2_35 = emitter.truncate(s_b_2_34, emitter.context().types().u8());
    /* execute.simd:2143 [F] s_b_2_36 = constant s32 6 (const) */
    /* execute.simd:2143 [D] s_b_2_37 = s_b_2_32[s_b_2_36] <= s_b_2_35 */
    auto s_b_2_37 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)6ULL), s_b_2_35);
    /* execute.simd:2144 [F] s_b_2_38 = constant s32 7 (const) */
    /* execute.simd:2144 [D] s_b_2_1[s_b_2_38] */
    auto s_b_2_39 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:2144 [D] s_b_2_40 = (u8)s_b_2_39 */
    auto s_b_2_40 = emitter.truncate(s_b_2_39, emitter.context().types().u8());
    /* execute.simd:2144 [F] s_b_2_41 = constant s32 7 (const) */
    /* execute.simd:2144 [D] s_b_2_42 = s_b_2_37[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_37, emitter.const_s32((int32_t)7ULL), s_b_2_40);
    /* execute.simd:2146 [F] s_b_2_43=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2146 [D] s_b_2_44: WriteRegBank 16:s_b_2_43 = s_b_2_42 */
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
    /* execute.simd:2151 [F] s_b_3_0=sym_46415_3_parameter_inst.rn (const) */
    /* execute.simd:2151 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:2153 [F] s_b_3_2=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2153 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:2154 [F] s_b_3_4 = constant s32 0 (const) */
    /* execute.simd:2154 [D] s_b_3_1[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2154 [D] s_b_3_6 = (u8)s_b_3_5 */
    auto s_b_3_6 = emitter.truncate(s_b_3_5, emitter.context().types().u8());
    /* execute.simd:2154 [F] s_b_3_7 = constant s32 8 (const) */
    /* execute.simd:2154 [D] s_b_3_8 = s_b_3_3[s_b_3_7] <= s_b_3_6 */
    auto s_b_3_8 = emitter.vector_insert(s_b_3_3, emitter.const_s32((int32_t)8ULL), s_b_3_6);
    /* execute.simd:2155 [F] s_b_3_9 = constant s32 1 (const) */
    /* execute.simd:2155 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2155 [D] s_b_3_11 = (u8)s_b_3_10 */
    auto s_b_3_11 = emitter.truncate(s_b_3_10, emitter.context().types().u8());
    /* execute.simd:2155 [F] s_b_3_12 = constant s32 9 (const) */
    /* execute.simd:2155 [D] s_b_3_13 = s_b_3_8[s_b_3_12] <= s_b_3_11 */
    auto s_b_3_13 = emitter.vector_insert(s_b_3_8, emitter.const_s32((int32_t)9ULL), s_b_3_11);
    /* execute.simd:2156 [F] s_b_3_14 = constant s32 2 (const) */
    /* execute.simd:2156 [D] s_b_3_1[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2156 [D] s_b_3_16 = (u8)s_b_3_15 */
    auto s_b_3_16 = emitter.truncate(s_b_3_15, emitter.context().types().u8());
    /* execute.simd:2156 [F] s_b_3_17 = constant s32 a (const) */
    /* execute.simd:2156 [D] s_b_3_18 = s_b_3_13[s_b_3_17] <= s_b_3_16 */
    auto s_b_3_18 = emitter.vector_insert(s_b_3_13, emitter.const_s32((int32_t)10ULL), s_b_3_16);
    /* execute.simd:2157 [F] s_b_3_19 = constant s32 3 (const) */
    /* execute.simd:2157 [D] s_b_3_1[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2157 [D] s_b_3_21 = (u8)s_b_3_20 */
    auto s_b_3_21 = emitter.truncate(s_b_3_20, emitter.context().types().u8());
    /* execute.simd:2157 [F] s_b_3_22 = constant s32 b (const) */
    /* execute.simd:2157 [D] s_b_3_23 = s_b_3_18[s_b_3_22] <= s_b_3_21 */
    auto s_b_3_23 = emitter.vector_insert(s_b_3_18, emitter.const_s32((int32_t)11ULL), s_b_3_21);
    /* execute.simd:2158 [F] s_b_3_24 = constant s32 4 (const) */
    /* execute.simd:2158 [D] s_b_3_1[s_b_3_24] */
    auto s_b_3_25 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:2158 [D] s_b_3_26 = (u8)s_b_3_25 */
    auto s_b_3_26 = emitter.truncate(s_b_3_25, emitter.context().types().u8());
    /* execute.simd:2158 [F] s_b_3_27 = constant s32 c (const) */
    /* execute.simd:2158 [D] s_b_3_28 = s_b_3_23[s_b_3_27] <= s_b_3_26 */
    auto s_b_3_28 = emitter.vector_insert(s_b_3_23, emitter.const_s32((int32_t)12ULL), s_b_3_26);
    /* execute.simd:2159 [F] s_b_3_29 = constant s32 5 (const) */
    /* execute.simd:2159 [D] s_b_3_1[s_b_3_29] */
    auto s_b_3_30 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)5ULL));
    /* execute.simd:2159 [D] s_b_3_31 = (u8)s_b_3_30 */
    auto s_b_3_31 = emitter.truncate(s_b_3_30, emitter.context().types().u8());
    /* execute.simd:2159 [F] s_b_3_32 = constant s32 d (const) */
    /* execute.simd:2159 [D] s_b_3_33 = s_b_3_28[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_28, emitter.const_s32((int32_t)13ULL), s_b_3_31);
    /* execute.simd:2160 [F] s_b_3_34 = constant s32 6 (const) */
    /* execute.simd:2160 [D] s_b_3_1[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:2160 [D] s_b_3_36 = (u8)s_b_3_35 */
    auto s_b_3_36 = emitter.truncate(s_b_3_35, emitter.context().types().u8());
    /* execute.simd:2160 [F] s_b_3_37 = constant s32 e (const) */
    /* execute.simd:2160 [D] s_b_3_38 = s_b_3_33[s_b_3_37] <= s_b_3_36 */
    auto s_b_3_38 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)14ULL), s_b_3_36);
    /* execute.simd:2161 [F] s_b_3_39 = constant s32 7 (const) */
    /* execute.simd:2161 [D] s_b_3_1[s_b_3_39] */
    auto s_b_3_40 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)7ULL));
    /* execute.simd:2161 [D] s_b_3_41 = (u8)s_b_3_40 */
    auto s_b_3_41 = emitter.truncate(s_b_3_40, emitter.context().types().u8());
    /* execute.simd:2161 [F] s_b_3_42 = constant s32 f (const) */
    /* execute.simd:2161 [D] s_b_3_43 = s_b_3_38[s_b_3_42] <= s_b_3_41 */
    auto s_b_3_43 = emitter.vector_insert(s_b_3_38, emitter.const_s32((int32_t)15ULL), s_b_3_41);
    /* execute.simd:2163 [F] s_b_3_44=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2163 [D] s_b_3_45: WriteRegBank 16:s_b_3_44 = s_b_3_43 */
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
    /* execute.simd:2168 [F] s_b_4_0=sym_46415_3_parameter_inst.rn (const) */
    /* execute.simd:2168 [D] s_b_4_1 = ReadRegBank 20:s_b_4_0 (v4u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_4_2 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:2171 [F] s_b_4_3 = constant s32 0 (const) */
    /* execute.simd:2171 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2171 [D] s_b_4_5 = (u16)s_b_4_4 */
    auto s_b_4_5 = emitter.truncate(s_b_4_4, emitter.context().types().u16());
    /* execute.simd:2171 [F] s_b_4_6 = constant s32 0 (const) */
    /* execute.simd:2171 [D] s_b_4_7 = s_b_4_2[s_b_4_6] <= s_b_4_5 */
    auto s_b_4_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_4_5);
    /* execute.simd:2172 [F] s_b_4_8 = constant s32 1 (const) */
    /* execute.simd:2172 [D] s_b_4_1[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2172 [D] s_b_4_10 = (u16)s_b_4_9 */
    auto s_b_4_10 = emitter.truncate(s_b_4_9, emitter.context().types().u16());
    /* execute.simd:2172 [F] s_b_4_11 = constant s32 1 (const) */
    /* execute.simd:2172 [D] s_b_4_12 = s_b_4_7[s_b_4_11] <= s_b_4_10 */
    auto s_b_4_12 = emitter.vector_insert(s_b_4_7, emitter.const_s32((int32_t)1ULL), s_b_4_10);
    /* execute.simd:2173 [F] s_b_4_13 = constant s32 2 (const) */
    /* execute.simd:2173 [D] s_b_4_1[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2173 [D] s_b_4_15 = (u16)s_b_4_14 */
    auto s_b_4_15 = emitter.truncate(s_b_4_14, emitter.context().types().u16());
    /* execute.simd:2173 [F] s_b_4_16 = constant s32 2 (const) */
    /* execute.simd:2173 [D] s_b_4_17 = s_b_4_12[s_b_4_16] <= s_b_4_15 */
    auto s_b_4_17 = emitter.vector_insert(s_b_4_12, emitter.const_s32((int32_t)2ULL), s_b_4_15);
    /* execute.simd:2174 [F] s_b_4_18 = constant s32 3 (const) */
    /* execute.simd:2174 [D] s_b_4_1[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2174 [D] s_b_4_20 = (u16)s_b_4_19 */
    auto s_b_4_20 = emitter.truncate(s_b_4_19, emitter.context().types().u16());
    /* execute.simd:2174 [F] s_b_4_21 = constant s32 3 (const) */
    /* execute.simd:2174 [D] s_b_4_22 = s_b_4_17[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_17, emitter.const_s32((int32_t)3ULL), s_b_4_20);
    /* execute.simd:2176 [F] s_b_4_23=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2176 [D] s_b_4_24: WriteRegBank 18:s_b_4_23 = s_b_4_22 */
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
    /* execute.simd:2181 [F] s_b_5_0=sym_46415_3_parameter_inst.rn (const) */
    /* execute.simd:2181 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:2183 [F] s_b_5_2=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2183 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:2184 [F] s_b_5_4 = constant s32 0 (const) */
    /* execute.simd:2184 [D] s_b_5_1[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2184 [D] s_b_5_6 = (u16)s_b_5_5 */
    auto s_b_5_6 = emitter.truncate(s_b_5_5, emitter.context().types().u16());
    /* execute.simd:2184 [F] s_b_5_7 = constant s32 4 (const) */
    /* execute.simd:2184 [D] s_b_5_8 = s_b_5_3[s_b_5_7] <= s_b_5_6 */
    auto s_b_5_8 = emitter.vector_insert(s_b_5_3, emitter.const_s32((int32_t)4ULL), s_b_5_6);
    /* execute.simd:2185 [F] s_b_5_9 = constant s32 1 (const) */
    /* execute.simd:2185 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2185 [D] s_b_5_11 = (u16)s_b_5_10 */
    auto s_b_5_11 = emitter.truncate(s_b_5_10, emitter.context().types().u16());
    /* execute.simd:2185 [F] s_b_5_12 = constant s32 5 (const) */
    /* execute.simd:2185 [D] s_b_5_13 = s_b_5_8[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(s_b_5_8, emitter.const_s32((int32_t)5ULL), s_b_5_11);
    /* execute.simd:2186 [F] s_b_5_14 = constant s32 2 (const) */
    /* execute.simd:2186 [D] s_b_5_1[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:2186 [D] s_b_5_16 = (u16)s_b_5_15 */
    auto s_b_5_16 = emitter.truncate(s_b_5_15, emitter.context().types().u16());
    /* execute.simd:2186 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:2186 [D] s_b_5_18 = s_b_5_13[s_b_5_17] <= s_b_5_16 */
    auto s_b_5_18 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)6ULL), s_b_5_16);
    /* execute.simd:2187 [F] s_b_5_19 = constant s32 3 (const) */
    /* execute.simd:2187 [D] s_b_5_1[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:2187 [D] s_b_5_21 = (u16)s_b_5_20 */
    auto s_b_5_21 = emitter.truncate(s_b_5_20, emitter.context().types().u16());
    /* execute.simd:2187 [F] s_b_5_22 = constant s32 7 (const) */
    /* execute.simd:2187 [D] s_b_5_23 = s_b_5_18[s_b_5_22] <= s_b_5_21 */
    auto s_b_5_23 = emitter.vector_insert(s_b_5_18, emitter.const_s32((int32_t)7ULL), s_b_5_21);
    /* execute.simd:2189 [F] s_b_5_24=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2189 [D] s_b_5_25: WriteRegBank 18:s_b_5_24 = s_b_5_23 */
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
    /* execute.simd:2194 [F] s_b_6_0=sym_46415_3_parameter_inst.rn (const) */
    /* execute.simd:2194 [D] s_b_6_1 = ReadRegBank 21:s_b_6_0 (v2u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:2197 [F] s_b_6_3 = constant s32 0 (const) */
    /* execute.simd:2197 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2197 [D] s_b_6_5 = (u32)s_b_6_4 */
    auto s_b_6_5 = emitter.truncate(s_b_6_4, emitter.context().types().u32());
    /* execute.simd:2197 [F] s_b_6_6 = constant s32 0 (const) */
    /* execute.simd:2197 [D] s_b_6_7 = s_b_6_2[s_b_6_6] <= s_b_6_5 */
    auto s_b_6_7 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_6_5);
    /* execute.simd:2198 [F] s_b_6_8 = constant s32 1 (const) */
    /* execute.simd:2198 [D] s_b_6_1[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2198 [D] s_b_6_10 = (u32)s_b_6_9 */
    auto s_b_6_10 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.simd:2198 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:2198 [D] s_b_6_12 = s_b_6_7[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_7, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:2200 [F] s_b_6_13=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2200 [D] s_b_6_14: WriteRegBank 20:s_b_6_13 = s_b_6_12 */
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
    /* execute.simd:2205 [F] s_b_7_0=sym_46415_3_parameter_inst.rn (const) */
    /* execute.simd:2205 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:2207 [F] s_b_7_2=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2207 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:2208 [F] s_b_7_4 = constant s32 0 (const) */
    /* execute.simd:2208 [D] s_b_7_1[s_b_7_4] */
    auto s_b_7_5 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:2208 [D] s_b_7_6 = (u32)s_b_7_5 */
    auto s_b_7_6 = emitter.truncate(s_b_7_5, emitter.context().types().u32());
    /* execute.simd:2208 [F] s_b_7_7 = constant s32 2 (const) */
    /* execute.simd:2208 [D] s_b_7_8 = s_b_7_3[s_b_7_7] <= s_b_7_6 */
    auto s_b_7_8 = emitter.vector_insert(s_b_7_3, emitter.const_s32((int32_t)2ULL), s_b_7_6);
    /* execute.simd:2209 [F] s_b_7_9 = constant s32 1 (const) */
    /* execute.simd:2209 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:2209 [D] s_b_7_11 = (u32)s_b_7_10 */
    auto s_b_7_11 = emitter.truncate(s_b_7_10, emitter.context().types().u32());
    /* execute.simd:2209 [F] s_b_7_12 = constant s32 3 (const) */
    /* execute.simd:2209 [D] s_b_7_13 = s_b_7_8[s_b_7_12] <= s_b_7_11 */
    auto s_b_7_13 = emitter.vector_insert(s_b_7_8, emitter.const_s32((int32_t)3ULL), s_b_7_11);
    /* execute.simd:2211 [F] s_b_7_14=sym_46415_3_parameter_inst.rd (const) */
    /* execute.simd:2211 [D] s_b_7_15: WriteRegBank 20:s_b_7_14 = s_b_7_13 */
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
    /* execute.simd:2216 [D] s_b_8_0 = trap */
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
template class aarch64_jit2<true>;
template class aarch64_jit2<false>;
