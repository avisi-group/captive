#include <aarch64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::aarch64;
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_addp_vector(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:925 [F] s_b_0_0=sym_3761_3_parameter_inst.arrangement (const) */
    /* execute.simd:926 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:944 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:960 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:978 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:994 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:1012 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:1028 [F] s_b_0_7 = constant s32 6 (const) */
    /* execute.simd:925 [F] s_b_0_8: Switch s_b_0_0: < <todo> > def b_9 (const) -> b_9, b_8, b_7, b_6, b_5, b_4, b_3, b_2,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
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
    default:
      goto fixed_block_b_9;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8, b_9,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:927 [F] s_b_2_0=sym_3761_3_parameter_inst.rn (const) */
    /* execute.simd:927 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:928 [F] s_b_2_2=sym_3761_3_parameter_inst.rm (const) */
    /* execute.simd:928 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant v8u8 
    {
    }
    (const) */
    /* execute.simd:932 [F] s_b_2_5 = constant u32 0 (const) */
    /* execute.simd:932 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:932 [F] s_b_2_7 = constant u32 1 (const) */
    /* execute.simd:932 [D] s_b_2_1[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:932 [D] s_b_2_9 = s_b_2_6+s_b_2_8 */
    auto s_b_2_9 = emitter.add(s_b_2_6, s_b_2_8);
    /* execute.simd:932 [F] s_b_2_10 = constant s32 0 (const) */
    /* execute.simd:932 [D] s_b_2_11 = s_b_2_4[s_b_2_10] <= s_b_2_9 */
    auto s_b_2_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 8>(0)[0], emitter.context().types().v8u8()), emitter.const_s32((int32_t)0ULL), s_b_2_9);
    /* execute.simd:932 [F] s_b_2_12 = constant u32 2 (const) */
    /* execute.simd:932 [D] s_b_2_1[s_b_2_12] */
    auto s_b_2_13 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:932 [F] s_b_2_14 = constant u32 3 (const) */
    /* execute.simd:932 [D] s_b_2_1[s_b_2_14] */
    auto s_b_2_15 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:932 [D] s_b_2_16 = s_b_2_13+s_b_2_15 */
    auto s_b_2_16 = emitter.add(s_b_2_13, s_b_2_15);
    /* execute.simd:932 [F] s_b_2_17 = constant s32 1 (const) */
    /* execute.simd:932 [D] s_b_2_18 = s_b_2_11[s_b_2_17] <= s_b_2_16 */
    auto s_b_2_18 = emitter.vector_insert(s_b_2_11, emitter.const_s32((int32_t)1ULL), s_b_2_16);
    /* execute.simd:932 [F] s_b_2_19 = constant u32 4 (const) */
    /* execute.simd:932 [D] s_b_2_1[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:932 [F] s_b_2_21 = constant u32 5 (const) */
    /* execute.simd:932 [D] s_b_2_1[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:932 [D] s_b_2_23 = s_b_2_20+s_b_2_22 */
    auto s_b_2_23 = emitter.add(s_b_2_20, s_b_2_22);
    /* execute.simd:932 [F] s_b_2_24 = constant s32 2 (const) */
    /* execute.simd:932 [D] s_b_2_25 = s_b_2_18[s_b_2_24] <= s_b_2_23 */
    auto s_b_2_25 = emitter.vector_insert(s_b_2_18, emitter.const_s32((int32_t)2ULL), s_b_2_23);
    /* execute.simd:932 [F] s_b_2_26 = constant u32 6 (const) */
    /* execute.simd:932 [D] s_b_2_1[s_b_2_26] */
    auto s_b_2_27 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:932 [F] s_b_2_28 = constant u32 7 (const) */
    /* execute.simd:932 [D] s_b_2_1[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:932 [D] s_b_2_30 = s_b_2_27+s_b_2_29 */
    auto s_b_2_30 = emitter.add(s_b_2_27, s_b_2_29);
    /* execute.simd:932 [F] s_b_2_31 = constant s32 3 (const) */
    /* execute.simd:932 [D] s_b_2_32 = s_b_2_25[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_25, emitter.const_s32((int32_t)3ULL), s_b_2_30);
    /* execute.simd:936 [F] s_b_2_33 = constant u32 0 (const) */
    /* execute.simd:936 [D] s_b_2_3[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_3, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:936 [F] s_b_2_35 = constant u32 1 (const) */
    /* execute.simd:936 [D] s_b_2_3[s_b_2_35] */
    auto s_b_2_36 = emitter.vector_extract(s_b_2_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:936 [D] s_b_2_37 = s_b_2_34+s_b_2_36 */
    auto s_b_2_37 = emitter.add(s_b_2_34, s_b_2_36);
    /* execute.simd:936 [F] s_b_2_38 = constant s32 4 (const) */
    /* execute.simd:936 [D] s_b_2_39 = s_b_2_32[s_b_2_38] <= s_b_2_37 */
    auto s_b_2_39 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)4ULL), s_b_2_37);
    /* execute.simd:936 [F] s_b_2_40 = constant u32 2 (const) */
    /* execute.simd:936 [D] s_b_2_3[s_b_2_40] */
    auto s_b_2_41 = emitter.vector_extract(s_b_2_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:936 [F] s_b_2_42 = constant u32 3 (const) */
    /* execute.simd:936 [D] s_b_2_3[s_b_2_42] */
    auto s_b_2_43 = emitter.vector_extract(s_b_2_3, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:936 [D] s_b_2_44 = s_b_2_41+s_b_2_43 */
    auto s_b_2_44 = emitter.add(s_b_2_41, s_b_2_43);
    /* execute.simd:936 [F] s_b_2_45 = constant s32 5 (const) */
    /* execute.simd:936 [D] s_b_2_46 = s_b_2_39[s_b_2_45] <= s_b_2_44 */
    auto s_b_2_46 = emitter.vector_insert(s_b_2_39, emitter.const_s32((int32_t)5ULL), s_b_2_44);
    /* execute.simd:936 [F] s_b_2_47 = constant u32 4 (const) */
    /* execute.simd:936 [D] s_b_2_3[s_b_2_47] */
    auto s_b_2_48 = emitter.vector_extract(s_b_2_3, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:936 [F] s_b_2_49 = constant u32 5 (const) */
    /* execute.simd:936 [D] s_b_2_3[s_b_2_49] */
    auto s_b_2_50 = emitter.vector_extract(s_b_2_3, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:936 [D] s_b_2_51 = s_b_2_48+s_b_2_50 */
    auto s_b_2_51 = emitter.add(s_b_2_48, s_b_2_50);
    /* execute.simd:936 [F] s_b_2_52 = constant s32 6 (const) */
    /* execute.simd:936 [D] s_b_2_53 = s_b_2_46[s_b_2_52] <= s_b_2_51 */
    auto s_b_2_53 = emitter.vector_insert(s_b_2_46, emitter.const_s32((int32_t)6ULL), s_b_2_51);
    /* execute.simd:936 [F] s_b_2_54 = constant u32 6 (const) */
    /* execute.simd:936 [D] s_b_2_3[s_b_2_54] */
    auto s_b_2_55 = emitter.vector_extract(s_b_2_3, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:936 [F] s_b_2_56 = constant u32 7 (const) */
    /* execute.simd:936 [D] s_b_2_3[s_b_2_56] */
    auto s_b_2_57 = emitter.vector_extract(s_b_2_3, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:936 [D] s_b_2_58 = s_b_2_55+s_b_2_57 */
    auto s_b_2_58 = emitter.add(s_b_2_55, s_b_2_57);
    /* execute.simd:936 [F] s_b_2_59 = constant s32 7 (const) */
    /* execute.simd:936 [D] s_b_2_60 = s_b_2_53[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_53, emitter.const_s32((int32_t)7ULL), s_b_2_58);
    /* execute.simd:939 [F] s_b_2_61=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:939 [D] s_b_2_62: WriteRegBank 15:s_b_2_61 = s_b_2_60 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_60,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_60);
    /* execute.simd:940 [F] s_b_2_63=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:940 [F] s_b_2_64 = constant u64 0 (const) */
    /* execute.simd:940 [F] s_b_2_65: WriteRegBank 3:s_b_2_63 = s_b_2_64 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_66: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:945 [F] s_b_3_0=sym_3761_3_parameter_inst.rn (const) */
    /* execute.simd:945 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:946 [F] s_b_3_2=sym_3761_3_parameter_inst.rm (const) */
    /* execute.simd:946 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:950 [F] s_b_3_5 = constant u32 0 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:950 [F] s_b_3_7 = constant u32 1 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:950 [D] s_b_3_9 = s_b_3_6+s_b_3_8 */
    auto s_b_3_9 = emitter.add(s_b_3_6, s_b_3_8);
    /* execute.simd:950 [F] s_b_3_10 = constant s32 0 (const) */
    /* execute.simd:950 [D] s_b_3_11 = s_b_3_4[s_b_3_10] <= s_b_3_9 */
    auto s_b_3_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_3_9);
    /* execute.simd:950 [F] s_b_3_12 = constant u32 2 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_12] */
    auto s_b_3_13 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:950 [F] s_b_3_14 = constant u32 3 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:950 [D] s_b_3_16 = s_b_3_13+s_b_3_15 */
    auto s_b_3_16 = emitter.add(s_b_3_13, s_b_3_15);
    /* execute.simd:950 [F] s_b_3_17 = constant s32 1 (const) */
    /* execute.simd:950 [D] s_b_3_18 = s_b_3_11[s_b_3_17] <= s_b_3_16 */
    auto s_b_3_18 = emitter.vector_insert(s_b_3_11, emitter.const_s32((int32_t)1ULL), s_b_3_16);
    /* execute.simd:950 [F] s_b_3_19 = constant u32 4 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:950 [F] s_b_3_21 = constant u32 5 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:950 [D] s_b_3_23 = s_b_3_20+s_b_3_22 */
    auto s_b_3_23 = emitter.add(s_b_3_20, s_b_3_22);
    /* execute.simd:950 [F] s_b_3_24 = constant s32 2 (const) */
    /* execute.simd:950 [D] s_b_3_25 = s_b_3_18[s_b_3_24] <= s_b_3_23 */
    auto s_b_3_25 = emitter.vector_insert(s_b_3_18, emitter.const_s32((int32_t)2ULL), s_b_3_23);
    /* execute.simd:950 [F] s_b_3_26 = constant u32 6 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_26] */
    auto s_b_3_27 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:950 [F] s_b_3_28 = constant u32 7 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:950 [D] s_b_3_30 = s_b_3_27+s_b_3_29 */
    auto s_b_3_30 = emitter.add(s_b_3_27, s_b_3_29);
    /* execute.simd:950 [F] s_b_3_31 = constant s32 3 (const) */
    /* execute.simd:950 [D] s_b_3_32 = s_b_3_25[s_b_3_31] <= s_b_3_30 */
    auto s_b_3_32 = emitter.vector_insert(s_b_3_25, emitter.const_s32((int32_t)3ULL), s_b_3_30);
    /* execute.simd:950 [F] s_b_3_33 = constant u32 8 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:950 [F] s_b_3_35 = constant u32 9 (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_35] */
    auto s_b_3_36 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:950 [D] s_b_3_37 = s_b_3_34+s_b_3_36 */
    auto s_b_3_37 = emitter.add(s_b_3_34, s_b_3_36);
    /* execute.simd:950 [F] s_b_3_38 = constant s32 4 (const) */
    /* execute.simd:950 [D] s_b_3_39 = s_b_3_32[s_b_3_38] <= s_b_3_37 */
    auto s_b_3_39 = emitter.vector_insert(s_b_3_32, emitter.const_s32((int32_t)4ULL), s_b_3_37);
    /* execute.simd:950 [F] s_b_3_40 = constant u32 a (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_40] */
    auto s_b_3_41 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:950 [F] s_b_3_42 = constant u32 b (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_42] */
    auto s_b_3_43 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:950 [D] s_b_3_44 = s_b_3_41+s_b_3_43 */
    auto s_b_3_44 = emitter.add(s_b_3_41, s_b_3_43);
    /* execute.simd:950 [F] s_b_3_45 = constant s32 5 (const) */
    /* execute.simd:950 [D] s_b_3_46 = s_b_3_39[s_b_3_45] <= s_b_3_44 */
    auto s_b_3_46 = emitter.vector_insert(s_b_3_39, emitter.const_s32((int32_t)5ULL), s_b_3_44);
    /* execute.simd:950 [F] s_b_3_47 = constant u32 c (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_47] */
    auto s_b_3_48 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:950 [F] s_b_3_49 = constant u32 d (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:950 [D] s_b_3_51 = s_b_3_48+s_b_3_50 */
    auto s_b_3_51 = emitter.add(s_b_3_48, s_b_3_50);
    /* execute.simd:950 [F] s_b_3_52 = constant s32 6 (const) */
    /* execute.simd:950 [D] s_b_3_53 = s_b_3_46[s_b_3_52] <= s_b_3_51 */
    auto s_b_3_53 = emitter.vector_insert(s_b_3_46, emitter.const_s32((int32_t)6ULL), s_b_3_51);
    /* execute.simd:950 [F] s_b_3_54 = constant u32 e (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_54] */
    auto s_b_3_55 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:950 [F] s_b_3_56 = constant u32 f (const) */
    /* execute.simd:950 [D] s_b_3_1[s_b_3_56] */
    auto s_b_3_57 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:950 [D] s_b_3_58 = s_b_3_55+s_b_3_57 */
    auto s_b_3_58 = emitter.add(s_b_3_55, s_b_3_57);
    /* execute.simd:950 [F] s_b_3_59 = constant s32 7 (const) */
    /* execute.simd:950 [D] s_b_3_60 = s_b_3_53[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_53, emitter.const_s32((int32_t)7ULL), s_b_3_58);
    /* execute.simd:954 [F] s_b_3_61 = constant u32 0 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:954 [F] s_b_3_63 = constant u32 1 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_63] */
    auto s_b_3_64 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:954 [D] s_b_3_65 = s_b_3_62+s_b_3_64 */
    auto s_b_3_65 = emitter.add(s_b_3_62, s_b_3_64);
    /* execute.simd:954 [F] s_b_3_66 = constant s32 8 (const) */
    /* execute.simd:954 [D] s_b_3_67 = s_b_3_60[s_b_3_66] <= s_b_3_65 */
    auto s_b_3_67 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)8ULL), s_b_3_65);
    /* execute.simd:954 [F] s_b_3_68 = constant u32 2 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_68] */
    auto s_b_3_69 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:954 [F] s_b_3_70 = constant u32 3 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:954 [D] s_b_3_72 = s_b_3_69+s_b_3_71 */
    auto s_b_3_72 = emitter.add(s_b_3_69, s_b_3_71);
    /* execute.simd:954 [F] s_b_3_73 = constant s32 9 (const) */
    /* execute.simd:954 [D] s_b_3_74 = s_b_3_67[s_b_3_73] <= s_b_3_72 */
    auto s_b_3_74 = emitter.vector_insert(s_b_3_67, emitter.const_s32((int32_t)9ULL), s_b_3_72);
    /* execute.simd:954 [F] s_b_3_75 = constant u32 4 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_75] */
    auto s_b_3_76 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:954 [F] s_b_3_77 = constant u32 5 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_77] */
    auto s_b_3_78 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:954 [D] s_b_3_79 = s_b_3_76+s_b_3_78 */
    auto s_b_3_79 = emitter.add(s_b_3_76, s_b_3_78);
    /* execute.simd:954 [F] s_b_3_80 = constant s32 a (const) */
    /* execute.simd:954 [D] s_b_3_81 = s_b_3_74[s_b_3_80] <= s_b_3_79 */
    auto s_b_3_81 = emitter.vector_insert(s_b_3_74, emitter.const_s32((int32_t)10ULL), s_b_3_79);
    /* execute.simd:954 [F] s_b_3_82 = constant u32 6 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_82] */
    auto s_b_3_83 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:954 [F] s_b_3_84 = constant u32 7 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_84] */
    auto s_b_3_85 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:954 [D] s_b_3_86 = s_b_3_83+s_b_3_85 */
    auto s_b_3_86 = emitter.add(s_b_3_83, s_b_3_85);
    /* execute.simd:954 [F] s_b_3_87 = constant s32 b (const) */
    /* execute.simd:954 [D] s_b_3_88 = s_b_3_81[s_b_3_87] <= s_b_3_86 */
    auto s_b_3_88 = emitter.vector_insert(s_b_3_81, emitter.const_s32((int32_t)11ULL), s_b_3_86);
    /* execute.simd:954 [F] s_b_3_89 = constant u32 8 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_89] */
    auto s_b_3_90 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:954 [F] s_b_3_91 = constant u32 9 (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_91] */
    auto s_b_3_92 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:954 [D] s_b_3_93 = s_b_3_90+s_b_3_92 */
    auto s_b_3_93 = emitter.add(s_b_3_90, s_b_3_92);
    /* execute.simd:954 [F] s_b_3_94 = constant s32 c (const) */
    /* execute.simd:954 [D] s_b_3_95 = s_b_3_88[s_b_3_94] <= s_b_3_93 */
    auto s_b_3_95 = emitter.vector_insert(s_b_3_88, emitter.const_s32((int32_t)12ULL), s_b_3_93);
    /* execute.simd:954 [F] s_b_3_96 = constant u32 a (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_96] */
    auto s_b_3_97 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:954 [F] s_b_3_98 = constant u32 b (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_98] */
    auto s_b_3_99 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:954 [D] s_b_3_100 = s_b_3_97+s_b_3_99 */
    auto s_b_3_100 = emitter.add(s_b_3_97, s_b_3_99);
    /* execute.simd:954 [F] s_b_3_101 = constant s32 d (const) */
    /* execute.simd:954 [D] s_b_3_102 = s_b_3_95[s_b_3_101] <= s_b_3_100 */
    auto s_b_3_102 = emitter.vector_insert(s_b_3_95, emitter.const_s32((int32_t)13ULL), s_b_3_100);
    /* execute.simd:954 [F] s_b_3_103 = constant u32 c (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_103] */
    auto s_b_3_104 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:954 [F] s_b_3_105 = constant u32 d (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_105] */
    auto s_b_3_106 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:954 [D] s_b_3_107 = s_b_3_104+s_b_3_106 */
    auto s_b_3_107 = emitter.add(s_b_3_104, s_b_3_106);
    /* execute.simd:954 [F] s_b_3_108 = constant s32 e (const) */
    /* execute.simd:954 [D] s_b_3_109 = s_b_3_102[s_b_3_108] <= s_b_3_107 */
    auto s_b_3_109 = emitter.vector_insert(s_b_3_102, emitter.const_s32((int32_t)14ULL), s_b_3_107);
    /* execute.simd:954 [F] s_b_3_110 = constant u32 e (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_110] */
    auto s_b_3_111 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:954 [F] s_b_3_112 = constant u32 f (const) */
    /* execute.simd:954 [D] s_b_3_3[s_b_3_112] */
    auto s_b_3_113 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:954 [D] s_b_3_114 = s_b_3_111+s_b_3_113 */
    auto s_b_3_114 = emitter.add(s_b_3_111, s_b_3_113);
    /* execute.simd:954 [F] s_b_3_115 = constant s32 f (const) */
    /* execute.simd:954 [D] s_b_3_116 = s_b_3_109[s_b_3_115] <= s_b_3_114 */
    auto s_b_3_116 = emitter.vector_insert(s_b_3_109, emitter.const_s32((int32_t)15ULL), s_b_3_114);
    /* execute.simd:957 [F] s_b_3_117=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:957 [D] s_b_3_118: WriteRegBank 16:s_b_3_117 = s_b_3_116 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_116,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_116);
    /* execute.simd:0 [F] s_b_3_119: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:961 [F] s_b_4_0=sym_3761_3_parameter_inst.rn (const) */
    /* execute.simd:961 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:962 [F] s_b_4_2=sym_3761_3_parameter_inst.rm (const) */
    /* execute.simd:962 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant v4u16 
    {
    }
    (const) */
    /* execute.simd:966 [F] s_b_4_5 = constant u32 0 (const) */
    /* execute.simd:966 [D] s_b_4_1[s_b_4_5] */
    auto s_b_4_6 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:966 [F] s_b_4_7 = constant u32 1 (const) */
    /* execute.simd:966 [D] s_b_4_1[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:966 [D] s_b_4_9 = s_b_4_6+s_b_4_8 */
    auto s_b_4_9 = emitter.add(s_b_4_6, s_b_4_8);
    /* execute.simd:966 [F] s_b_4_10 = constant s32 0 (const) */
    /* execute.simd:966 [D] s_b_4_11 = s_b_4_4[s_b_4_10] <= s_b_4_9 */
    auto s_b_4_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 4>(0)[0], emitter.context().types().v4u16()), emitter.const_s32((int32_t)0ULL), s_b_4_9);
    /* execute.simd:966 [F] s_b_4_12 = constant u32 2 (const) */
    /* execute.simd:966 [D] s_b_4_1[s_b_4_12] */
    auto s_b_4_13 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:966 [F] s_b_4_14 = constant u32 3 (const) */
    /* execute.simd:966 [D] s_b_4_1[s_b_4_14] */
    auto s_b_4_15 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:966 [D] s_b_4_16 = s_b_4_13+s_b_4_15 */
    auto s_b_4_16 = emitter.add(s_b_4_13, s_b_4_15);
    /* execute.simd:966 [F] s_b_4_17 = constant s32 1 (const) */
    /* execute.simd:966 [D] s_b_4_18 = s_b_4_11[s_b_4_17] <= s_b_4_16 */
    auto s_b_4_18 = emitter.vector_insert(s_b_4_11, emitter.const_s32((int32_t)1ULL), s_b_4_16);
    /* execute.simd:970 [F] s_b_4_19 = constant u32 0 (const) */
    /* execute.simd:970 [D] s_b_4_3[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_3, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:970 [F] s_b_4_21 = constant u32 1 (const) */
    /* execute.simd:970 [D] s_b_4_3[s_b_4_21] */
    auto s_b_4_22 = emitter.vector_extract(s_b_4_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:970 [D] s_b_4_23 = s_b_4_20+s_b_4_22 */
    auto s_b_4_23 = emitter.add(s_b_4_20, s_b_4_22);
    /* execute.simd:970 [F] s_b_4_24 = constant s32 2 (const) */
    /* execute.simd:970 [D] s_b_4_25 = s_b_4_18[s_b_4_24] <= s_b_4_23 */
    auto s_b_4_25 = emitter.vector_insert(s_b_4_18, emitter.const_s32((int32_t)2ULL), s_b_4_23);
    /* execute.simd:970 [F] s_b_4_26 = constant u32 2 (const) */
    /* execute.simd:970 [D] s_b_4_3[s_b_4_26] */
    auto s_b_4_27 = emitter.vector_extract(s_b_4_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:970 [F] s_b_4_28 = constant u32 3 (const) */
    /* execute.simd:970 [D] s_b_4_3[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_3, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:970 [D] s_b_4_30 = s_b_4_27+s_b_4_29 */
    auto s_b_4_30 = emitter.add(s_b_4_27, s_b_4_29);
    /* execute.simd:970 [F] s_b_4_31 = constant s32 3 (const) */
    /* execute.simd:970 [D] s_b_4_32 = s_b_4_25[s_b_4_31] <= s_b_4_30 */
    auto s_b_4_32 = emitter.vector_insert(s_b_4_25, emitter.const_s32((int32_t)3ULL), s_b_4_30);
    /* execute.simd:973 [F] s_b_4_33=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:973 [D] s_b_4_34: WriteRegBank 17:s_b_4_33 = s_b_4_32 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_32,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_32);
    /* execute.simd:974 [F] s_b_4_35=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:974 [F] s_b_4_36 = constant u64 0 (const) */
    /* execute.simd:974 [F] s_b_4_37: WriteRegBank 3:s_b_4_35 = s_b_4_36 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_38: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:979 [F] s_b_5_0=sym_3761_3_parameter_inst.rn (const) */
    /* execute.simd:979 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:980 [F] s_b_5_2=sym_3761_3_parameter_inst.rm (const) */
    /* execute.simd:980 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:984 [F] s_b_5_5 = constant u32 0 (const) */
    /* execute.simd:984 [D] s_b_5_1[s_b_5_5] */
    auto s_b_5_6 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:984 [F] s_b_5_7 = constant u32 1 (const) */
    /* execute.simd:984 [D] s_b_5_1[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:984 [D] s_b_5_9 = s_b_5_6+s_b_5_8 */
    auto s_b_5_9 = emitter.add(s_b_5_6, s_b_5_8);
    /* execute.simd:984 [F] s_b_5_10 = constant s32 0 (const) */
    /* execute.simd:984 [D] s_b_5_11 = s_b_5_4[s_b_5_10] <= s_b_5_9 */
    auto s_b_5_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_5_9);
    /* execute.simd:984 [F] s_b_5_12 = constant u32 2 (const) */
    /* execute.simd:984 [D] s_b_5_1[s_b_5_12] */
    auto s_b_5_13 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:984 [F] s_b_5_14 = constant u32 3 (const) */
    /* execute.simd:984 [D] s_b_5_1[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:984 [D] s_b_5_16 = s_b_5_13+s_b_5_15 */
    auto s_b_5_16 = emitter.add(s_b_5_13, s_b_5_15);
    /* execute.simd:984 [F] s_b_5_17 = constant s32 1 (const) */
    /* execute.simd:984 [D] s_b_5_18 = s_b_5_11[s_b_5_17] <= s_b_5_16 */
    auto s_b_5_18 = emitter.vector_insert(s_b_5_11, emitter.const_s32((int32_t)1ULL), s_b_5_16);
    /* execute.simd:984 [F] s_b_5_19 = constant u32 4 (const) */
    /* execute.simd:984 [D] s_b_5_1[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:984 [F] s_b_5_21 = constant u32 5 (const) */
    /* execute.simd:984 [D] s_b_5_1[s_b_5_21] */
    auto s_b_5_22 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:984 [D] s_b_5_23 = s_b_5_20+s_b_5_22 */
    auto s_b_5_23 = emitter.add(s_b_5_20, s_b_5_22);
    /* execute.simd:984 [F] s_b_5_24 = constant s32 2 (const) */
    /* execute.simd:984 [D] s_b_5_25 = s_b_5_18[s_b_5_24] <= s_b_5_23 */
    auto s_b_5_25 = emitter.vector_insert(s_b_5_18, emitter.const_s32((int32_t)2ULL), s_b_5_23);
    /* execute.simd:984 [F] s_b_5_26 = constant u32 6 (const) */
    /* execute.simd:984 [D] s_b_5_1[s_b_5_26] */
    auto s_b_5_27 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:984 [F] s_b_5_28 = constant u32 7 (const) */
    /* execute.simd:984 [D] s_b_5_1[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:984 [D] s_b_5_30 = s_b_5_27+s_b_5_29 */
    auto s_b_5_30 = emitter.add(s_b_5_27, s_b_5_29);
    /* execute.simd:984 [F] s_b_5_31 = constant s32 3 (const) */
    /* execute.simd:984 [D] s_b_5_32 = s_b_5_25[s_b_5_31] <= s_b_5_30 */
    auto s_b_5_32 = emitter.vector_insert(s_b_5_25, emitter.const_s32((int32_t)3ULL), s_b_5_30);
    /* execute.simd:988 [F] s_b_5_33 = constant u32 0 (const) */
    /* execute.simd:988 [D] s_b_5_3[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:988 [F] s_b_5_35 = constant u32 1 (const) */
    /* execute.simd:988 [D] s_b_5_3[s_b_5_35] */
    auto s_b_5_36 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:988 [D] s_b_5_37 = s_b_5_34+s_b_5_36 */
    auto s_b_5_37 = emitter.add(s_b_5_34, s_b_5_36);
    /* execute.simd:988 [F] s_b_5_38 = constant s32 4 (const) */
    /* execute.simd:988 [D] s_b_5_39 = s_b_5_32[s_b_5_38] <= s_b_5_37 */
    auto s_b_5_39 = emitter.vector_insert(s_b_5_32, emitter.const_s32((int32_t)4ULL), s_b_5_37);
    /* execute.simd:988 [F] s_b_5_40 = constant u32 2 (const) */
    /* execute.simd:988 [D] s_b_5_3[s_b_5_40] */
    auto s_b_5_41 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:988 [F] s_b_5_42 = constant u32 3 (const) */
    /* execute.simd:988 [D] s_b_5_3[s_b_5_42] */
    auto s_b_5_43 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:988 [D] s_b_5_44 = s_b_5_41+s_b_5_43 */
    auto s_b_5_44 = emitter.add(s_b_5_41, s_b_5_43);
    /* execute.simd:988 [F] s_b_5_45 = constant s32 5 (const) */
    /* execute.simd:988 [D] s_b_5_46 = s_b_5_39[s_b_5_45] <= s_b_5_44 */
    auto s_b_5_46 = emitter.vector_insert(s_b_5_39, emitter.const_s32((int32_t)5ULL), s_b_5_44);
    /* execute.simd:988 [F] s_b_5_47 = constant u32 4 (const) */
    /* execute.simd:988 [D] s_b_5_3[s_b_5_47] */
    auto s_b_5_48 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:988 [F] s_b_5_49 = constant u32 5 (const) */
    /* execute.simd:988 [D] s_b_5_3[s_b_5_49] */
    auto s_b_5_50 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:988 [D] s_b_5_51 = s_b_5_48+s_b_5_50 */
    auto s_b_5_51 = emitter.add(s_b_5_48, s_b_5_50);
    /* execute.simd:988 [F] s_b_5_52 = constant s32 6 (const) */
    /* execute.simd:988 [D] s_b_5_53 = s_b_5_46[s_b_5_52] <= s_b_5_51 */
    auto s_b_5_53 = emitter.vector_insert(s_b_5_46, emitter.const_s32((int32_t)6ULL), s_b_5_51);
    /* execute.simd:988 [F] s_b_5_54 = constant u32 6 (const) */
    /* execute.simd:988 [D] s_b_5_3[s_b_5_54] */
    auto s_b_5_55 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:988 [F] s_b_5_56 = constant u32 7 (const) */
    /* execute.simd:988 [D] s_b_5_3[s_b_5_56] */
    auto s_b_5_57 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:988 [D] s_b_5_58 = s_b_5_55+s_b_5_57 */
    auto s_b_5_58 = emitter.add(s_b_5_55, s_b_5_57);
    /* execute.simd:988 [F] s_b_5_59 = constant s32 7 (const) */
    /* execute.simd:988 [D] s_b_5_60 = s_b_5_53[s_b_5_59] <= s_b_5_58 */
    auto s_b_5_60 = emitter.vector_insert(s_b_5_53, emitter.const_s32((int32_t)7ULL), s_b_5_58);
    /* execute.simd:990 [F] s_b_5_61=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:990 [D] s_b_5_62: WriteRegBank 18:s_b_5_61 = s_b_5_60 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_60,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_60);
    /* execute.simd:0 [F] s_b_5_63: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:995 [F] s_b_6_0=sym_3761_3_parameter_inst.rn (const) */
    /* execute.simd:995 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:996 [F] s_b_6_2=sym_3761_3_parameter_inst.rm (const) */
    /* execute.simd:996 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_4 = constant v2u32 
    {
    }
    (const) */
    /* execute.simd:1000 [F] s_b_6_5 = constant u32 0 (const) */
    /* execute.simd:1000 [D] s_b_6_1[s_b_6_5] */
    auto s_b_6_6 = emitter.vector_extract(s_b_6_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:1000 [F] s_b_6_7 = constant u32 1 (const) */
    /* execute.simd:1000 [D] s_b_6_1[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:1000 [D] s_b_6_9 = s_b_6_6+s_b_6_8 */
    auto s_b_6_9 = emitter.add(s_b_6_6, s_b_6_8);
    /* execute.simd:1000 [F] s_b_6_10 = constant s32 0 (const) */
    /* execute.simd:1000 [D] s_b_6_11 = s_b_6_4[s_b_6_10] <= s_b_6_9 */
    auto s_b_6_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 2>(0)[0], emitter.context().types().v2u32()), emitter.const_s32((int32_t)0ULL), s_b_6_9);
    /* execute.simd:1004 [F] s_b_6_12 = constant u32 0 (const) */
    /* execute.simd:1004 [D] s_b_6_3[s_b_6_12] */
    auto s_b_6_13 = emitter.vector_extract(s_b_6_3, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:1004 [F] s_b_6_14 = constant u32 1 (const) */
    /* execute.simd:1004 [D] s_b_6_3[s_b_6_14] */
    auto s_b_6_15 = emitter.vector_extract(s_b_6_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:1004 [D] s_b_6_16 = s_b_6_13+s_b_6_15 */
    auto s_b_6_16 = emitter.add(s_b_6_13, s_b_6_15);
    /* execute.simd:1004 [F] s_b_6_17 = constant s32 1 (const) */
    /* execute.simd:1004 [D] s_b_6_18 = s_b_6_11[s_b_6_17] <= s_b_6_16 */
    auto s_b_6_18 = emitter.vector_insert(s_b_6_11, emitter.const_s32((int32_t)1ULL), s_b_6_16);
    /* execute.simd:1007 [F] s_b_6_19=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:1007 [D] s_b_6_20: WriteRegBank 19:s_b_6_19 = s_b_6_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_18,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_18);
    /* execute.simd:1008 [F] s_b_6_21=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:1008 [F] s_b_6_22 = constant u64 0 (const) */
    /* execute.simd:1008 [F] s_b_6_23: WriteRegBank 3:s_b_6_21 = s_b_6_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_24: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:1013 [F] s_b_7_0=sym_3761_3_parameter_inst.rn (const) */
    /* execute.simd:1013 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:1014 [F] s_b_7_2=sym_3761_3_parameter_inst.rm (const) */
    /* execute.simd:1014 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:1018 [F] s_b_7_5 = constant u32 0 (const) */
    /* execute.simd:1018 [D] s_b_7_1[s_b_7_5] */
    auto s_b_7_6 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:1018 [F] s_b_7_7 = constant u32 1 (const) */
    /* execute.simd:1018 [D] s_b_7_1[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:1018 [D] s_b_7_9 = s_b_7_6+s_b_7_8 */
    auto s_b_7_9 = emitter.add(s_b_7_6, s_b_7_8);
    /* execute.simd:1018 [F] s_b_7_10 = constant s32 0 (const) */
    /* execute.simd:1018 [D] s_b_7_11 = s_b_7_4[s_b_7_10] <= s_b_7_9 */
    auto s_b_7_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_7_9);
    /* execute.simd:1018 [F] s_b_7_12 = constant u32 2 (const) */
    /* execute.simd:1018 [D] s_b_7_1[s_b_7_12] */
    auto s_b_7_13 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:1018 [F] s_b_7_14 = constant u32 3 (const) */
    /* execute.simd:1018 [D] s_b_7_1[s_b_7_14] */
    auto s_b_7_15 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:1018 [D] s_b_7_16 = s_b_7_13+s_b_7_15 */
    auto s_b_7_16 = emitter.add(s_b_7_13, s_b_7_15);
    /* execute.simd:1018 [F] s_b_7_17 = constant s32 1 (const) */
    /* execute.simd:1018 [D] s_b_7_18 = s_b_7_11[s_b_7_17] <= s_b_7_16 */
    auto s_b_7_18 = emitter.vector_insert(s_b_7_11, emitter.const_s32((int32_t)1ULL), s_b_7_16);
    /* execute.simd:1022 [F] s_b_7_19 = constant u32 0 (const) */
    /* execute.simd:1022 [D] s_b_7_3[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:1022 [F] s_b_7_21 = constant u32 1 (const) */
    /* execute.simd:1022 [D] s_b_7_3[s_b_7_21] */
    auto s_b_7_22 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:1022 [D] s_b_7_23 = s_b_7_20+s_b_7_22 */
    auto s_b_7_23 = emitter.add(s_b_7_20, s_b_7_22);
    /* execute.simd:1022 [F] s_b_7_24 = constant s32 2 (const) */
    /* execute.simd:1022 [D] s_b_7_25 = s_b_7_18[s_b_7_24] <= s_b_7_23 */
    auto s_b_7_25 = emitter.vector_insert(s_b_7_18, emitter.const_s32((int32_t)2ULL), s_b_7_23);
    /* execute.simd:1022 [F] s_b_7_26 = constant u32 2 (const) */
    /* execute.simd:1022 [D] s_b_7_3[s_b_7_26] */
    auto s_b_7_27 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:1022 [F] s_b_7_28 = constant u32 3 (const) */
    /* execute.simd:1022 [D] s_b_7_3[s_b_7_28] */
    auto s_b_7_29 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:1022 [D] s_b_7_30 = s_b_7_27+s_b_7_29 */
    auto s_b_7_30 = emitter.add(s_b_7_27, s_b_7_29);
    /* execute.simd:1022 [F] s_b_7_31 = constant s32 3 (const) */
    /* execute.simd:1022 [D] s_b_7_32 = s_b_7_25[s_b_7_31] <= s_b_7_30 */
    auto s_b_7_32 = emitter.vector_insert(s_b_7_25, emitter.const_s32((int32_t)3ULL), s_b_7_30);
    /* execute.simd:1025 [F] s_b_7_33=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:1025 [D] s_b_7_34: WriteRegBank 20:s_b_7_33 = s_b_7_32 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_32,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_32);
    /* execute.simd:0 [F] s_b_7_35: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:1029 [F] s_b_8_0=sym_3761_3_parameter_inst.rn (const) */
    /* execute.simd:1029 [D] s_b_8_1 = ReadRegBank 21:s_b_8_0 (v2u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* execute.simd:1030 [F] s_b_8_2=sym_3761_3_parameter_inst.rm (const) */
    /* execute.simd:1030 [D] s_b_8_3 = ReadRegBank 21:s_b_8_2 (v2u64) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_4 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:1034 [F] s_b_8_5 = constant u32 0 (const) */
    /* execute.simd:1034 [D] s_b_8_1[s_b_8_5] */
    auto s_b_8_6 = emitter.vector_extract(s_b_8_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:1034 [F] s_b_8_7 = constant u32 1 (const) */
    /* execute.simd:1034 [D] s_b_8_1[s_b_8_7] */
    auto s_b_8_8 = emitter.vector_extract(s_b_8_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:1034 [D] s_b_8_9 = s_b_8_6+s_b_8_8 */
    auto s_b_8_9 = emitter.add(s_b_8_6, s_b_8_8);
    /* execute.simd:1034 [F] s_b_8_10 = constant s32 0 (const) */
    /* execute.simd:1034 [D] s_b_8_11 = s_b_8_4[s_b_8_10] <= s_b_8_9 */
    auto s_b_8_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_8_9);
    /* execute.simd:1038 [F] s_b_8_12 = constant u32 0 (const) */
    /* execute.simd:1038 [D] s_b_8_3[s_b_8_12] */
    auto s_b_8_13 = emitter.vector_extract(s_b_8_3, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:1038 [F] s_b_8_14 = constant u32 1 (const) */
    /* execute.simd:1038 [D] s_b_8_3[s_b_8_14] */
    auto s_b_8_15 = emitter.vector_extract(s_b_8_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:1038 [D] s_b_8_16 = s_b_8_13+s_b_8_15 */
    auto s_b_8_16 = emitter.add(s_b_8_13, s_b_8_15);
    /* execute.simd:1038 [F] s_b_8_17 = constant s32 1 (const) */
    /* execute.simd:1038 [D] s_b_8_18 = s_b_8_11[s_b_8_17] <= s_b_8_16 */
    auto s_b_8_18 = emitter.vector_insert(s_b_8_11, emitter.const_s32((int32_t)1ULL), s_b_8_16);
    /* execute.simd:1041 [F] s_b_8_19=sym_3761_3_parameter_inst.rd (const) */
    /* execute.simd:1041 [D] s_b_8_20: WriteRegBank 21:s_b_8_19 = s_b_8_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_18,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_18);
    /* execute.simd:0 [F] s_b_8_21: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.simd:1045 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_1 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_barrier(const aarch64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_br(const aarch64_decode_a64_UB_REG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:552 [F] s_b_0_0=sym_6409_3_parameter_inst.opc (const) */
    /* execute.a64:552 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:552 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.a64:552 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:552 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_2 (const) */
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
    /* execute.a64:553 [D] s_b_1_0 = read_pc */
    auto s_b_1_0 = emitter.load_pc();
    /* execute.a64:553 [F] s_b_1_1 = constant u64 4 (const) */
    /* execute.a64:553 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2684 [F] s_b_1_3 = constant u8 1e (const) */
    /* execute.a64:2684 [D] s_b_1_4: WriteRegBank 0:s_b_1_3 = s_b_1_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * (uint8_t)30ULL))),s_b_1_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * (uint8_t)30ULL))),s_b_1_2);
    /* execute.a64:0 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0, b_1,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2657 [F] s_b_2_0=sym_6409_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2651 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_2_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_2_5 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_2_6: Select s_b_2_3 ? s_b_2_4 : s_b_2_5 */
    captive::arch::dbt::el::Value *s_b_2_6;
    s_b_2_6 = (s_b_2_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_2_5);
    /* execute.a64:557 [D] s_b_2_7 = write_pc */
    emitter.store_pc(s_b_2_6);
    /* ???:4294967295 [F] s_b_2_8: Return */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_cls(const aarch64_decode_a64_DP_1S&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_54242_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_54197_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_6962_0_rn = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_6926_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2221 [F] s_b_0_0=sym_6917_3_parameter_inst.sf (const) */
    /* execute.a64:2221 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2222 [F] s_b_1_0=sym_6917_3_parameter_inst.rn (const) */
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
    /* execute.a64:2222 [D] s_b_1_7: sym_6926_0_rn = s_b_1_6, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_6926_0_rn, s_b_1_6);
    /* execute.a64:2224 [F] s_b_1_8 = constant u64 0 (const) */
    /* execute.a64:2224 [D] s_b_1_9 = s_b_1_6==s_b_1_8 */
    auto s_b_1_9 = emitter.cmp_eq(s_b_1_6, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2224 [D] s_b_1_10: If s_b_1_9: Jump b_4 else b_5 */
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
    /* execute.a64:2231 [F] s_b_3_0=sym_6917_3_parameter_inst.rn (const) */
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
    /* execute.a64:2231 [D] s_b_3_7: sym_6962_0_rn = s_b_3_6, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_6962_0_rn, s_b_3_6);
    /* execute.a64:2233 [F] s_b_3_8 = constant u32 0 (const) */
    /* execute.a64:2233 [D] s_b_3_9 = s_b_3_6==s_b_3_8 */
    auto s_b_3_9 = emitter.cmp_eq(s_b_3_6, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2233 [D] s_b_3_10: If s_b_3_9: Jump b_6 else b_7 */
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
      emitter.branch(s_b_3_9, true_target, false_target);
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
        /* execute.a64:2225 [F] s_b_4_0=sym_6917_3_parameter_inst.rd (const) */
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
        /* execute.a64:2227 [D] s_b_5_0 = sym_6926_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_6926_0_rn, emitter.context().types().u64());
        /* execute.a64:2227 [F] s_b_5_1 = constant u64 1 (const) */
        /* execute.a64:2227 [D] s_b_5_2 = s_b_5_0>>s_b_5_1 */
        auto s_b_5_2 = emitter.shr(s_b_5_0, emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:2227 [F] s_b_5_3 = constant u64 8000000000000000 (const) */
        /* execute.a64:2227 [F] s_b_5_4 = ~s_b_5_3 (const) */
        uint64_t s_b_5_4 = ~(uint64_t)9223372036854775808ULL;
        /* execute.a64:2227 [D] s_b_5_5 = s_b_5_0&s_b_5_4 */
        auto s_b_5_5 = emitter.bitwise_and(s_b_5_0, emitter.const_u64(s_b_5_4));
        /* execute.a64:2227 [D] s_b_5_6 = s_b_5_2^s_b_5_5 */
        auto s_b_5_6 = emitter.bitwise_xor(s_b_5_2, s_b_5_5);
        /* execute.a64:2227 [D] s_b_5_7: sym_6926_0_rn = s_b_5_6, dominates:  */
        emitter.store_local(DV_sym_6926_0_rn, s_b_5_6);
        /* execute.a64:2228 [F] s_b_5_8=sym_6917_3_parameter_inst.rd (const) */
        /* execute.a64:2228 [D] s_b_5_9 = __builtin_clz64 */
        auto s_b_5_9 = emitter.clz(s_b_5_6);
        /* execute.a64:2228 [D] s_b_5_10 = (u64)s_b_5_9 */
        auto s_b_5_10 = (captive::arch::dbt::el::Value *)s_b_5_9;
        /* execute.a64:2228 [F] s_b_5_11 = constant u64 1 (const) */
        /* execute.a64:2228 [D] s_b_5_12 = s_b_5_10-s_b_5_11 */
        auto s_b_5_12 = emitter.sub(s_b_5_10, emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:2228 [D] s_b_5_13: sym_54197_3_parameter_value = s_b_5_12, dominates: s_b_9_1  */
        emitter.store_local(DV_sym_54197_3_parameter_value, s_b_5_12);
        /* execute.a64:2682 [F] s_b_5_14 = (u32)s_b_5_8 (const) */
        /* execute.a64:2682 [F] s_b_5_15 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_5_16 = s_b_5_14==s_b_5_15 (const) */
        uint8_t s_b_5_16 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_5_17: If s_b_5_16: Jump b_2 else b_9 (const) */
        if (s_b_5_16) 
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
        /* execute.a64:2234 [F] s_b_6_0=sym_6917_3_parameter_inst.rd (const) */
        /* execute.a64:2674 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
        /* execute.a64:2674 [F] s_b_6_2 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
        uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_6_4: If s_b_6_3: Jump b_2 else b_10 (const) */
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
        /* execute.a64:2236 [D] s_b_7_0 = sym_6962_0_rn uint32_t */
        auto s_b_7_0 = emitter.load_local(DV_sym_6962_0_rn, emitter.context().types().u32());
        /* execute.a64:2236 [F] s_b_7_1 = constant u32 1 (const) */
        /* execute.a64:2236 [D] s_b_7_2 = s_b_7_0>>s_b_7_1 */
        auto s_b_7_2 = emitter.shr(s_b_7_0, emitter.const_u32((uint32_t)1ULL));
        /* execute.a64:2236 [F] s_b_7_3 = constant u32 80000000 (const) */
        /* execute.a64:2236 [F] s_b_7_4 = ~s_b_7_3 (const) */
        uint32_t s_b_7_4 = ~(uint32_t)2147483648ULL;
        /* execute.a64:2236 [D] s_b_7_5 = s_b_7_0&s_b_7_4 */
        auto s_b_7_5 = emitter.bitwise_and(s_b_7_0, emitter.const_u32(s_b_7_4));
        /* execute.a64:2236 [D] s_b_7_6 = s_b_7_2^s_b_7_5 */
        auto s_b_7_6 = emitter.bitwise_xor(s_b_7_2, s_b_7_5);
        /* execute.a64:2236 [D] s_b_7_7: sym_6962_0_rn = s_b_7_6, dominates:  */
        emitter.store_local(DV_sym_6962_0_rn, s_b_7_6);
        /* execute.a64:2237 [F] s_b_7_8=sym_6917_3_parameter_inst.rd (const) */
        /* execute.a64:2237 [D] s_b_7_9 = __builtin_clz32 */
        auto s_b_7_9 = emitter.clz(s_b_7_6);
        /* execute.a64:2237 [D] s_b_7_10 = (u32)s_b_7_9 */
        auto s_b_7_10 = (captive::arch::dbt::el::Value *)s_b_7_9;
        /* execute.a64:2237 [F] s_b_7_11 = constant u32 1 (const) */
        /* execute.a64:2237 [D] s_b_7_12 = s_b_7_10-s_b_7_11 */
        auto s_b_7_12 = emitter.sub(s_b_7_10, emitter.const_u32((uint32_t)1ULL));
        /* execute.a64:2237 [D] s_b_7_13: sym_54242_3_parameter_value = s_b_7_12, dominates: s_b_11_1  */
        emitter.store_local(DV_sym_54242_3_parameter_value, s_b_7_12);
        /* execute.a64:2674 [F] s_b_7_14 = (u32)s_b_7_8 (const) */
        /* execute.a64:2674 [F] s_b_7_15 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_7_16 = s_b_7_14==s_b_7_15 (const) */
        uint8_t s_b_7_16 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_7_17: If s_b_7_16: Jump b_2 else b_11 (const) */
        if (s_b_7_16) 
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
        /* execute.a64:2684 [F] s_b_8_0=sym_6917_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [F] s_b_8_1 = constant u64 3f (const) */
        /* execute.a64:2684 [F] s_b_8_2: WriteRegBank 0:s_b_8_0 = s_b_8_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)63ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)63ULL));
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
        /* execute.a64:2684 [F] s_b_9_0=sym_6917_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_9_1 = sym_54197_3_parameter_value uint64_t */
        auto s_b_9_1 = emitter.load_local(DV_sym_54197_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2676 [F] s_b_10_0=sym_6917_3_parameter_inst.rd (const) */
        /* execute.a64:2676 [F] s_b_10_1 = constant u64 1f (const) */
        /* execute.a64:2676 [F] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)31ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),emitter.const_u64((uint64_t)31ULL));
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
        /* execute.a64:2676 [F] s_b_11_0=sym_6917_3_parameter_inst.rd (const) */
        /* execute.a64:2676 [D] s_b_11_1 = sym_54242_3_parameter_value uint32_t */
        auto s_b_11_1 = emitter.load_local(DV_sym_54242_3_parameter_value, emitter.context().types().u32());
        /* execute.a64:2676 [D] s_b_11_2 = (u64)s_b_11_1 */
        auto s_b_11_2 = emitter.zx(s_b_11_1, emitter.context().types().u64());
        /* execute.a64:2676 [D] s_b_11_3: WriteRegBank 0:s_b_11_0 = s_b_11_2 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_2,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_11_2);
        /* execute.a64:0 [F] s_b_11_4: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_cnt(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2074 [F] s_b_0_0=sym_8524_3_parameter_inst.SCALAR (const) */
    /* execute.simd:2074 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2075 [D] s_b_1_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:2075 [F] s_b_1_1: Jump b_2 (const) */
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
    /* execute.simd:2077 [F] s_b_3_0=sym_8524_3_parameter_inst.arrangement (const) */
    /* execute.simd:2078 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:2091 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:2102 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:2106 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:2110 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:2114 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:2118 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:2077 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_11 (const) -> b_11, b_10, b_9, b_8, b_7, b_6, b_5, b_4,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_4;
      break;
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2079 [F] s_b_4_0=sym_8524_3_parameter_inst.rn (const) */
    /* execute.simd:2079 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_2 = constant v8u8 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_3 = constant u8 0 (const) */
    /* execute.simd:2083 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:2083 [D] s_b_4_5 = (u32)s_b_4_4 */
    auto s_b_4_5 = emitter.zx(s_b_4_4, emitter.context().types().u32());
    /* execute.simd:2083 [D] s_b_4_6 = __builtin_popcount32 */
    auto s_b_4_6 = emitter.call(__captive___builtin_popcount32, s_b_4_5);
    /* execute.simd:2083 [D] s_b_4_7 = (u8)s_b_4_6 */
    auto s_b_4_7 = emitter.truncate(s_b_4_6, emitter.context().types().u8());
    /* execute.simd:2083 [F] s_b_4_8 = constant s32 0 (const) */
    /* execute.simd:2083 [D] s_b_4_9 = s_b_4_2[s_b_4_8] <= s_b_4_7 */
    auto s_b_4_9 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 8>(0)[0], emitter.context().types().v8u8()), emitter.const_s32((int32_t)0ULL), s_b_4_7);
    /* ???:4294967295 [F] s_b_4_10 = constant u8 1 (const) */
    /* execute.simd:2083 [D] s_b_4_1[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:2083 [D] s_b_4_12 = (u32)s_b_4_11 */
    auto s_b_4_12 = emitter.zx(s_b_4_11, emitter.context().types().u32());
    /* execute.simd:2083 [D] s_b_4_13 = __builtin_popcount32 */
    auto s_b_4_13 = emitter.call(__captive___builtin_popcount32, s_b_4_12);
    /* execute.simd:2083 [D] s_b_4_14 = (u8)s_b_4_13 */
    auto s_b_4_14 = emitter.truncate(s_b_4_13, emitter.context().types().u8());
    /* execute.simd:2083 [F] s_b_4_15 = constant s32 1 (const) */
    /* execute.simd:2083 [D] s_b_4_16 = s_b_4_9[s_b_4_15] <= s_b_4_14 */
    auto s_b_4_16 = emitter.vector_insert(s_b_4_9, emitter.const_s32((int32_t)1ULL), s_b_4_14);
    /* ???:4294967295 [F] s_b_4_17 = constant u8 2 (const) */
    /* execute.simd:2083 [D] s_b_4_1[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:2083 [D] s_b_4_19 = (u32)s_b_4_18 */
    auto s_b_4_19 = emitter.zx(s_b_4_18, emitter.context().types().u32());
    /* execute.simd:2083 [D] s_b_4_20 = __builtin_popcount32 */
    auto s_b_4_20 = emitter.call(__captive___builtin_popcount32, s_b_4_19);
    /* execute.simd:2083 [D] s_b_4_21 = (u8)s_b_4_20 */
    auto s_b_4_21 = emitter.truncate(s_b_4_20, emitter.context().types().u8());
    /* execute.simd:2083 [F] s_b_4_22 = constant s32 2 (const) */
    /* execute.simd:2083 [D] s_b_4_23 = s_b_4_16[s_b_4_22] <= s_b_4_21 */
    auto s_b_4_23 = emitter.vector_insert(s_b_4_16, emitter.const_s32((int32_t)2ULL), s_b_4_21);
    /* ???:4294967295 [F] s_b_4_24 = constant u8 3 (const) */
    /* execute.simd:2083 [D] s_b_4_1[s_b_4_24] */
    auto s_b_4_25 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:2083 [D] s_b_4_26 = (u32)s_b_4_25 */
    auto s_b_4_26 = emitter.zx(s_b_4_25, emitter.context().types().u32());
    /* execute.simd:2083 [D] s_b_4_27 = __builtin_popcount32 */
    auto s_b_4_27 = emitter.call(__captive___builtin_popcount32, s_b_4_26);
    /* execute.simd:2083 [D] s_b_4_28 = (u8)s_b_4_27 */
    auto s_b_4_28 = emitter.truncate(s_b_4_27, emitter.context().types().u8());
    /* execute.simd:2083 [F] s_b_4_29 = constant s32 3 (const) */
    /* execute.simd:2083 [D] s_b_4_30 = s_b_4_23[s_b_4_29] <= s_b_4_28 */
    auto s_b_4_30 = emitter.vector_insert(s_b_4_23, emitter.const_s32((int32_t)3ULL), s_b_4_28);
    /* ???:4294967295 [F] s_b_4_31 = constant u8 4 (const) */
    /* execute.simd:2083 [D] s_b_4_1[s_b_4_31] */
    auto s_b_4_32 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:2083 [D] s_b_4_33 = (u32)s_b_4_32 */
    auto s_b_4_33 = emitter.zx(s_b_4_32, emitter.context().types().u32());
    /* execute.simd:2083 [D] s_b_4_34 = __builtin_popcount32 */
    auto s_b_4_34 = emitter.call(__captive___builtin_popcount32, s_b_4_33);
    /* execute.simd:2083 [D] s_b_4_35 = (u8)s_b_4_34 */
    auto s_b_4_35 = emitter.truncate(s_b_4_34, emitter.context().types().u8());
    /* execute.simd:2083 [F] s_b_4_36 = constant s32 4 (const) */
    /* execute.simd:2083 [D] s_b_4_37 = s_b_4_30[s_b_4_36] <= s_b_4_35 */
    auto s_b_4_37 = emitter.vector_insert(s_b_4_30, emitter.const_s32((int32_t)4ULL), s_b_4_35);
    /* ???:4294967295 [F] s_b_4_38 = constant u8 5 (const) */
    /* execute.simd:2083 [D] s_b_4_1[s_b_4_38] */
    auto s_b_4_39 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:2083 [D] s_b_4_40 = (u32)s_b_4_39 */
    auto s_b_4_40 = emitter.zx(s_b_4_39, emitter.context().types().u32());
    /* execute.simd:2083 [D] s_b_4_41 = __builtin_popcount32 */
    auto s_b_4_41 = emitter.call(__captive___builtin_popcount32, s_b_4_40);
    /* execute.simd:2083 [D] s_b_4_42 = (u8)s_b_4_41 */
    auto s_b_4_42 = emitter.truncate(s_b_4_41, emitter.context().types().u8());
    /* execute.simd:2083 [F] s_b_4_43 = constant s32 5 (const) */
    /* execute.simd:2083 [D] s_b_4_44 = s_b_4_37[s_b_4_43] <= s_b_4_42 */
    auto s_b_4_44 = emitter.vector_insert(s_b_4_37, emitter.const_s32((int32_t)5ULL), s_b_4_42);
    /* ???:4294967295 [F] s_b_4_45 = constant u8 6 (const) */
    /* execute.simd:2083 [D] s_b_4_1[s_b_4_45] */
    auto s_b_4_46 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:2083 [D] s_b_4_47 = (u32)s_b_4_46 */
    auto s_b_4_47 = emitter.zx(s_b_4_46, emitter.context().types().u32());
    /* execute.simd:2083 [D] s_b_4_48 = __builtin_popcount32 */
    auto s_b_4_48 = emitter.call(__captive___builtin_popcount32, s_b_4_47);
    /* execute.simd:2083 [D] s_b_4_49 = (u8)s_b_4_48 */
    auto s_b_4_49 = emitter.truncate(s_b_4_48, emitter.context().types().u8());
    /* execute.simd:2083 [F] s_b_4_50 = constant s32 6 (const) */
    /* execute.simd:2083 [D] s_b_4_51 = s_b_4_44[s_b_4_50] <= s_b_4_49 */
    auto s_b_4_51 = emitter.vector_insert(s_b_4_44, emitter.const_s32((int32_t)6ULL), s_b_4_49);
    /* ???:4294967295 [F] s_b_4_52 = constant u8 7 (const) */
    /* execute.simd:2083 [D] s_b_4_1[s_b_4_52] */
    auto s_b_4_53 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:2083 [D] s_b_4_54 = (u32)s_b_4_53 */
    auto s_b_4_54 = emitter.zx(s_b_4_53, emitter.context().types().u32());
    /* execute.simd:2083 [D] s_b_4_55 = __builtin_popcount32 */
    auto s_b_4_55 = emitter.call(__captive___builtin_popcount32, s_b_4_54);
    /* execute.simd:2083 [D] s_b_4_56 = (u8)s_b_4_55 */
    auto s_b_4_56 = emitter.truncate(s_b_4_55, emitter.context().types().u8());
    /* execute.simd:2083 [F] s_b_4_57 = constant s32 7 (const) */
    /* execute.simd:2083 [D] s_b_4_58 = s_b_4_51[s_b_4_57] <= s_b_4_56 */
    auto s_b_4_58 = emitter.vector_insert(s_b_4_51, emitter.const_s32((int32_t)7ULL), s_b_4_56);
    /* execute.simd:2086 [F] s_b_4_59=sym_8524_3_parameter_inst.rd (const) */
    /* execute.simd:2086 [D] s_b_4_60: WriteRegBank 15:s_b_4_59 = s_b_4_58 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_58,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_58);
    /* execute.simd:2087 [F] s_b_4_61=sym_8524_3_parameter_inst.rd (const) */
    /* execute.simd:2087 [F] s_b_4_62 = constant u64 0 (const) */
    /* execute.simd:2087 [F] s_b_4_63: WriteRegBank 3:s_b_4_61 = s_b_4_62 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_64: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:2092 [F] s_b_5_0=sym_8524_3_parameter_inst.rn (const) */
    /* execute.simd:2092 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_2 = constant v16u8 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_5_3 = constant u8 0 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_3] */
    auto s_b_5_4 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:2096 [D] s_b_5_5 = (u32)s_b_5_4 */
    auto s_b_5_5 = emitter.zx(s_b_5_4, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_6 = __builtin_popcount32 */
    auto s_b_5_6 = emitter.call(__captive___builtin_popcount32, s_b_5_5);
    /* execute.simd:2096 [D] s_b_5_7 = (u8)s_b_5_6 */
    auto s_b_5_7 = emitter.truncate(s_b_5_6, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_8 = constant s32 0 (const) */
    /* execute.simd:2096 [D] s_b_5_9 = s_b_5_2[s_b_5_8] <= s_b_5_7 */
    auto s_b_5_9 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_5_7);
    /* ???:4294967295 [F] s_b_5_10 = constant u8 1 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:2096 [D] s_b_5_12 = (u32)s_b_5_11 */
    auto s_b_5_12 = emitter.zx(s_b_5_11, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_13 = __builtin_popcount32 */
    auto s_b_5_13 = emitter.call(__captive___builtin_popcount32, s_b_5_12);
    /* execute.simd:2096 [D] s_b_5_14 = (u8)s_b_5_13 */
    auto s_b_5_14 = emitter.truncate(s_b_5_13, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_15 = constant s32 1 (const) */
    /* execute.simd:2096 [D] s_b_5_16 = s_b_5_9[s_b_5_15] <= s_b_5_14 */
    auto s_b_5_16 = emitter.vector_insert(s_b_5_9, emitter.const_s32((int32_t)1ULL), s_b_5_14);
    /* ???:4294967295 [F] s_b_5_17 = constant u8 2 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:2096 [D] s_b_5_19 = (u32)s_b_5_18 */
    auto s_b_5_19 = emitter.zx(s_b_5_18, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_20 = __builtin_popcount32 */
    auto s_b_5_20 = emitter.call(__captive___builtin_popcount32, s_b_5_19);
    /* execute.simd:2096 [D] s_b_5_21 = (u8)s_b_5_20 */
    auto s_b_5_21 = emitter.truncate(s_b_5_20, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_22 = constant s32 2 (const) */
    /* execute.simd:2096 [D] s_b_5_23 = s_b_5_16[s_b_5_22] <= s_b_5_21 */
    auto s_b_5_23 = emitter.vector_insert(s_b_5_16, emitter.const_s32((int32_t)2ULL), s_b_5_21);
    /* ???:4294967295 [F] s_b_5_24 = constant u8 3 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_24] */
    auto s_b_5_25 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:2096 [D] s_b_5_26 = (u32)s_b_5_25 */
    auto s_b_5_26 = emitter.zx(s_b_5_25, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_27 = __builtin_popcount32 */
    auto s_b_5_27 = emitter.call(__captive___builtin_popcount32, s_b_5_26);
    /* execute.simd:2096 [D] s_b_5_28 = (u8)s_b_5_27 */
    auto s_b_5_28 = emitter.truncate(s_b_5_27, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_29 = constant s32 3 (const) */
    /* execute.simd:2096 [D] s_b_5_30 = s_b_5_23[s_b_5_29] <= s_b_5_28 */
    auto s_b_5_30 = emitter.vector_insert(s_b_5_23, emitter.const_s32((int32_t)3ULL), s_b_5_28);
    /* ???:4294967295 [F] s_b_5_31 = constant u8 4 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_31] */
    auto s_b_5_32 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:2096 [D] s_b_5_33 = (u32)s_b_5_32 */
    auto s_b_5_33 = emitter.zx(s_b_5_32, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_34 = __builtin_popcount32 */
    auto s_b_5_34 = emitter.call(__captive___builtin_popcount32, s_b_5_33);
    /* execute.simd:2096 [D] s_b_5_35 = (u8)s_b_5_34 */
    auto s_b_5_35 = emitter.truncate(s_b_5_34, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_36 = constant s32 4 (const) */
    /* execute.simd:2096 [D] s_b_5_37 = s_b_5_30[s_b_5_36] <= s_b_5_35 */
    auto s_b_5_37 = emitter.vector_insert(s_b_5_30, emitter.const_s32((int32_t)4ULL), s_b_5_35);
    /* ???:4294967295 [F] s_b_5_38 = constant u8 5 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_38] */
    auto s_b_5_39 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:2096 [D] s_b_5_40 = (u32)s_b_5_39 */
    auto s_b_5_40 = emitter.zx(s_b_5_39, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_41 = __builtin_popcount32 */
    auto s_b_5_41 = emitter.call(__captive___builtin_popcount32, s_b_5_40);
    /* execute.simd:2096 [D] s_b_5_42 = (u8)s_b_5_41 */
    auto s_b_5_42 = emitter.truncate(s_b_5_41, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_43 = constant s32 5 (const) */
    /* execute.simd:2096 [D] s_b_5_44 = s_b_5_37[s_b_5_43] <= s_b_5_42 */
    auto s_b_5_44 = emitter.vector_insert(s_b_5_37, emitter.const_s32((int32_t)5ULL), s_b_5_42);
    /* ???:4294967295 [F] s_b_5_45 = constant u8 6 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_45] */
    auto s_b_5_46 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:2096 [D] s_b_5_47 = (u32)s_b_5_46 */
    auto s_b_5_47 = emitter.zx(s_b_5_46, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_48 = __builtin_popcount32 */
    auto s_b_5_48 = emitter.call(__captive___builtin_popcount32, s_b_5_47);
    /* execute.simd:2096 [D] s_b_5_49 = (u8)s_b_5_48 */
    auto s_b_5_49 = emitter.truncate(s_b_5_48, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_50 = constant s32 6 (const) */
    /* execute.simd:2096 [D] s_b_5_51 = s_b_5_44[s_b_5_50] <= s_b_5_49 */
    auto s_b_5_51 = emitter.vector_insert(s_b_5_44, emitter.const_s32((int32_t)6ULL), s_b_5_49);
    /* ???:4294967295 [F] s_b_5_52 = constant u8 7 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_52] */
    auto s_b_5_53 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:2096 [D] s_b_5_54 = (u32)s_b_5_53 */
    auto s_b_5_54 = emitter.zx(s_b_5_53, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_55 = __builtin_popcount32 */
    auto s_b_5_55 = emitter.call(__captive___builtin_popcount32, s_b_5_54);
    /* execute.simd:2096 [D] s_b_5_56 = (u8)s_b_5_55 */
    auto s_b_5_56 = emitter.truncate(s_b_5_55, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_57 = constant s32 7 (const) */
    /* execute.simd:2096 [D] s_b_5_58 = s_b_5_51[s_b_5_57] <= s_b_5_56 */
    auto s_b_5_58 = emitter.vector_insert(s_b_5_51, emitter.const_s32((int32_t)7ULL), s_b_5_56);
    /* ???:4294967295 [F] s_b_5_59 = constant u8 8 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_59] */
    auto s_b_5_60 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)8ULL));
    /* execute.simd:2096 [D] s_b_5_61 = (u32)s_b_5_60 */
    auto s_b_5_61 = emitter.zx(s_b_5_60, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_62 = __builtin_popcount32 */
    auto s_b_5_62 = emitter.call(__captive___builtin_popcount32, s_b_5_61);
    /* execute.simd:2096 [D] s_b_5_63 = (u8)s_b_5_62 */
    auto s_b_5_63 = emitter.truncate(s_b_5_62, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_64 = constant s32 8 (const) */
    /* execute.simd:2096 [D] s_b_5_65 = s_b_5_58[s_b_5_64] <= s_b_5_63 */
    auto s_b_5_65 = emitter.vector_insert(s_b_5_58, emitter.const_s32((int32_t)8ULL), s_b_5_63);
    /* ???:4294967295 [F] s_b_5_66 = constant u8 9 (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_66] */
    auto s_b_5_67 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)9ULL));
    /* execute.simd:2096 [D] s_b_5_68 = (u32)s_b_5_67 */
    auto s_b_5_68 = emitter.zx(s_b_5_67, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_69 = __builtin_popcount32 */
    auto s_b_5_69 = emitter.call(__captive___builtin_popcount32, s_b_5_68);
    /* execute.simd:2096 [D] s_b_5_70 = (u8)s_b_5_69 */
    auto s_b_5_70 = emitter.truncate(s_b_5_69, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_71 = constant s32 9 (const) */
    /* execute.simd:2096 [D] s_b_5_72 = s_b_5_65[s_b_5_71] <= s_b_5_70 */
    auto s_b_5_72 = emitter.vector_insert(s_b_5_65, emitter.const_s32((int32_t)9ULL), s_b_5_70);
    /* ???:4294967295 [F] s_b_5_73 = constant u8 a (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_73] */
    auto s_b_5_74 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)10ULL));
    /* execute.simd:2096 [D] s_b_5_75 = (u32)s_b_5_74 */
    auto s_b_5_75 = emitter.zx(s_b_5_74, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_76 = __builtin_popcount32 */
    auto s_b_5_76 = emitter.call(__captive___builtin_popcount32, s_b_5_75);
    /* execute.simd:2096 [D] s_b_5_77 = (u8)s_b_5_76 */
    auto s_b_5_77 = emitter.truncate(s_b_5_76, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_78 = constant s32 a (const) */
    /* execute.simd:2096 [D] s_b_5_79 = s_b_5_72[s_b_5_78] <= s_b_5_77 */
    auto s_b_5_79 = emitter.vector_insert(s_b_5_72, emitter.const_s32((int32_t)10ULL), s_b_5_77);
    /* ???:4294967295 [F] s_b_5_80 = constant u8 b (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_80] */
    auto s_b_5_81 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)11ULL));
    /* execute.simd:2096 [D] s_b_5_82 = (u32)s_b_5_81 */
    auto s_b_5_82 = emitter.zx(s_b_5_81, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_83 = __builtin_popcount32 */
    auto s_b_5_83 = emitter.call(__captive___builtin_popcount32, s_b_5_82);
    /* execute.simd:2096 [D] s_b_5_84 = (u8)s_b_5_83 */
    auto s_b_5_84 = emitter.truncate(s_b_5_83, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_85 = constant s32 b (const) */
    /* execute.simd:2096 [D] s_b_5_86 = s_b_5_79[s_b_5_85] <= s_b_5_84 */
    auto s_b_5_86 = emitter.vector_insert(s_b_5_79, emitter.const_s32((int32_t)11ULL), s_b_5_84);
    /* ???:4294967295 [F] s_b_5_87 = constant u8 c (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_87] */
    auto s_b_5_88 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)12ULL));
    /* execute.simd:2096 [D] s_b_5_89 = (u32)s_b_5_88 */
    auto s_b_5_89 = emitter.zx(s_b_5_88, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_90 = __builtin_popcount32 */
    auto s_b_5_90 = emitter.call(__captive___builtin_popcount32, s_b_5_89);
    /* execute.simd:2096 [D] s_b_5_91 = (u8)s_b_5_90 */
    auto s_b_5_91 = emitter.truncate(s_b_5_90, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_92 = constant s32 c (const) */
    /* execute.simd:2096 [D] s_b_5_93 = s_b_5_86[s_b_5_92] <= s_b_5_91 */
    auto s_b_5_93 = emitter.vector_insert(s_b_5_86, emitter.const_s32((int32_t)12ULL), s_b_5_91);
    /* ???:4294967295 [F] s_b_5_94 = constant u8 d (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_94] */
    auto s_b_5_95 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)13ULL));
    /* execute.simd:2096 [D] s_b_5_96 = (u32)s_b_5_95 */
    auto s_b_5_96 = emitter.zx(s_b_5_95, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_97 = __builtin_popcount32 */
    auto s_b_5_97 = emitter.call(__captive___builtin_popcount32, s_b_5_96);
    /* execute.simd:2096 [D] s_b_5_98 = (u8)s_b_5_97 */
    auto s_b_5_98 = emitter.truncate(s_b_5_97, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_99 = constant s32 d (const) */
    /* execute.simd:2096 [D] s_b_5_100 = s_b_5_93[s_b_5_99] <= s_b_5_98 */
    auto s_b_5_100 = emitter.vector_insert(s_b_5_93, emitter.const_s32((int32_t)13ULL), s_b_5_98);
    /* ???:4294967295 [F] s_b_5_101 = constant u8 e (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_101] */
    auto s_b_5_102 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)14ULL));
    /* execute.simd:2096 [D] s_b_5_103 = (u32)s_b_5_102 */
    auto s_b_5_103 = emitter.zx(s_b_5_102, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_104 = __builtin_popcount32 */
    auto s_b_5_104 = emitter.call(__captive___builtin_popcount32, s_b_5_103);
    /* execute.simd:2096 [D] s_b_5_105 = (u8)s_b_5_104 */
    auto s_b_5_105 = emitter.truncate(s_b_5_104, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_106 = constant s32 e (const) */
    /* execute.simd:2096 [D] s_b_5_107 = s_b_5_100[s_b_5_106] <= s_b_5_105 */
    auto s_b_5_107 = emitter.vector_insert(s_b_5_100, emitter.const_s32((int32_t)14ULL), s_b_5_105);
    /* ???:4294967295 [F] s_b_5_108 = constant u8 f (const) */
    /* execute.simd:2096 [D] s_b_5_1[s_b_5_108] */
    auto s_b_5_109 = emitter.vector_extract(s_b_5_1, emitter.const_u8((uint8_t)15ULL));
    /* execute.simd:2096 [D] s_b_5_110 = (u32)s_b_5_109 */
    auto s_b_5_110 = emitter.zx(s_b_5_109, emitter.context().types().u32());
    /* execute.simd:2096 [D] s_b_5_111 = __builtin_popcount32 */
    auto s_b_5_111 = emitter.call(__captive___builtin_popcount32, s_b_5_110);
    /* execute.simd:2096 [D] s_b_5_112 = (u8)s_b_5_111 */
    auto s_b_5_112 = emitter.truncate(s_b_5_111, emitter.context().types().u8());
    /* execute.simd:2096 [F] s_b_5_113 = constant s32 f (const) */
    /* execute.simd:2096 [D] s_b_5_114 = s_b_5_107[s_b_5_113] <= s_b_5_112 */
    auto s_b_5_114 = emitter.vector_insert(s_b_5_107, emitter.const_s32((int32_t)15ULL), s_b_5_112);
    /* execute.simd:2099 [F] s_b_5_115=sym_8524_3_parameter_inst.rd (const) */
    /* execute.simd:2099 [D] s_b_5_116: WriteRegBank 16:s_b_5_115 = s_b_5_114 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_114,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_114);
    /* execute.simd:0 [F] s_b_5_117: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2103 [D] s_b_6_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_6_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2107 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_7_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2111 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_8_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:2115 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2119 [D] s_b_10_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_10_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:2123 [D] s_b_11_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_dup_elem(const aarch64_decode_a64_SIMD_COPY&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:279 [F] s_b_0_0=sym_9107_3_parameter_inst.arrangement (const) */
    /* execute.simd:280 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:294 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:306 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:319 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:331 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:344 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:356 [F] s_b_0_7 = constant s32 6 (const) */
    /* execute.simd:279 [F] s_b_0_8: Switch s_b_0_0: < <todo> > def b_9 (const) -> b_9, b_8, b_7, b_6, b_5, b_4, b_3, b_2,  */
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
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.simd:281 [F] s_b_2_0=sym_9107_3_parameter_inst.rn (const) */
    /* execute.simd:281 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_2 = constant v8u8 
    {
    }
    (const) */
    /* execute.simd:284 [F] s_b_2_3=sym_9107_3_parameter_inst.eindex (const) */
    /* execute.simd:284 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_u8(insn.eindex));
    /* execute.simd:286 [F] s_b_2_5 = constant s32 0 (const) */
    /* execute.simd:286 [D] s_b_2_6 = s_b_2_2[s_b_2_5] <= s_b_2_4 */
    auto s_b_2_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 8>(0)[0], emitter.context().types().v8u8()), emitter.const_s32((int32_t)0ULL), s_b_2_4);
    /* execute.simd:286 [F] s_b_2_7 = constant s32 1 (const) */
    /* execute.simd:286 [D] s_b_2_8 = s_b_2_6[s_b_2_7] <= s_b_2_4 */
    auto s_b_2_8 = emitter.vector_insert(s_b_2_6, emitter.const_s32((int32_t)1ULL), s_b_2_4);
    /* execute.simd:286 [F] s_b_2_9 = constant s32 2 (const) */
    /* execute.simd:286 [D] s_b_2_10 = s_b_2_8[s_b_2_9] <= s_b_2_4 */
    auto s_b_2_10 = emitter.vector_insert(s_b_2_8, emitter.const_s32((int32_t)2ULL), s_b_2_4);
    /* execute.simd:286 [F] s_b_2_11 = constant s32 3 (const) */
    /* execute.simd:286 [D] s_b_2_12 = s_b_2_10[s_b_2_11] <= s_b_2_4 */
    auto s_b_2_12 = emitter.vector_insert(s_b_2_10, emitter.const_s32((int32_t)3ULL), s_b_2_4);
    /* execute.simd:286 [F] s_b_2_13 = constant s32 4 (const) */
    /* execute.simd:286 [D] s_b_2_14 = s_b_2_12[s_b_2_13] <= s_b_2_4 */
    auto s_b_2_14 = emitter.vector_insert(s_b_2_12, emitter.const_s32((int32_t)4ULL), s_b_2_4);
    /* execute.simd:286 [F] s_b_2_15 = constant s32 5 (const) */
    /* execute.simd:286 [D] s_b_2_16 = s_b_2_14[s_b_2_15] <= s_b_2_4 */
    auto s_b_2_16 = emitter.vector_insert(s_b_2_14, emitter.const_s32((int32_t)5ULL), s_b_2_4);
    /* execute.simd:286 [F] s_b_2_17 = constant s32 6 (const) */
    /* execute.simd:286 [D] s_b_2_18 = s_b_2_16[s_b_2_17] <= s_b_2_4 */
    auto s_b_2_18 = emitter.vector_insert(s_b_2_16, emitter.const_s32((int32_t)6ULL), s_b_2_4);
    /* execute.simd:286 [F] s_b_2_19 = constant s32 7 (const) */
    /* execute.simd:286 [D] s_b_2_20 = s_b_2_18[s_b_2_19] <= s_b_2_4 */
    auto s_b_2_20 = emitter.vector_insert(s_b_2_18, emitter.const_s32((int32_t)7ULL), s_b_2_4);
    /* execute.simd:289 [F] s_b_2_21=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:289 [D] s_b_2_22: WriteRegBank 15:s_b_2_21 = s_b_2_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_20,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_20);
    /* execute.simd:290 [F] s_b_2_23=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:290 [F] s_b_2_24 = constant u64 0 (const) */
    /* execute.simd:290 [F] s_b_2_25: WriteRegBank 3:s_b_2_23 = s_b_2_24 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:295 [F] s_b_3_0=sym_9107_3_parameter_inst.rn (const) */
    /* execute.simd:295 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_2 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:298 [F] s_b_3_3=sym_9107_3_parameter_inst.eindex (const) */
    /* execute.simd:298 [D] s_b_3_1[s_b_3_3] */
    auto s_b_3_4 = emitter.vector_extract(s_b_3_1, emitter.const_u8(insn.eindex));
    /* execute.simd:300 [F] s_b_3_5 = constant s32 0 (const) */
    /* execute.simd:300 [D] s_b_3_6 = s_b_3_2[s_b_3_5] <= s_b_3_4 */
    auto s_b_3_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_7 = constant s32 1 (const) */
    /* execute.simd:300 [D] s_b_3_8 = s_b_3_6[s_b_3_7] <= s_b_3_4 */
    auto s_b_3_8 = emitter.vector_insert(s_b_3_6, emitter.const_s32((int32_t)1ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_9 = constant s32 2 (const) */
    /* execute.simd:300 [D] s_b_3_10 = s_b_3_8[s_b_3_9] <= s_b_3_4 */
    auto s_b_3_10 = emitter.vector_insert(s_b_3_8, emitter.const_s32((int32_t)2ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_11 = constant s32 3 (const) */
    /* execute.simd:300 [D] s_b_3_12 = s_b_3_10[s_b_3_11] <= s_b_3_4 */
    auto s_b_3_12 = emitter.vector_insert(s_b_3_10, emitter.const_s32((int32_t)3ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_13 = constant s32 4 (const) */
    /* execute.simd:300 [D] s_b_3_14 = s_b_3_12[s_b_3_13] <= s_b_3_4 */
    auto s_b_3_14 = emitter.vector_insert(s_b_3_12, emitter.const_s32((int32_t)4ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_15 = constant s32 5 (const) */
    /* execute.simd:300 [D] s_b_3_16 = s_b_3_14[s_b_3_15] <= s_b_3_4 */
    auto s_b_3_16 = emitter.vector_insert(s_b_3_14, emitter.const_s32((int32_t)5ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_17 = constant s32 6 (const) */
    /* execute.simd:300 [D] s_b_3_18 = s_b_3_16[s_b_3_17] <= s_b_3_4 */
    auto s_b_3_18 = emitter.vector_insert(s_b_3_16, emitter.const_s32((int32_t)6ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_19 = constant s32 7 (const) */
    /* execute.simd:300 [D] s_b_3_20 = s_b_3_18[s_b_3_19] <= s_b_3_4 */
    auto s_b_3_20 = emitter.vector_insert(s_b_3_18, emitter.const_s32((int32_t)7ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_21 = constant s32 8 (const) */
    /* execute.simd:300 [D] s_b_3_22 = s_b_3_20[s_b_3_21] <= s_b_3_4 */
    auto s_b_3_22 = emitter.vector_insert(s_b_3_20, emitter.const_s32((int32_t)8ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_23 = constant s32 9 (const) */
    /* execute.simd:300 [D] s_b_3_24 = s_b_3_22[s_b_3_23] <= s_b_3_4 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_22, emitter.const_s32((int32_t)9ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_25 = constant s32 a (const) */
    /* execute.simd:300 [D] s_b_3_26 = s_b_3_24[s_b_3_25] <= s_b_3_4 */
    auto s_b_3_26 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)10ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_27 = constant s32 b (const) */
    /* execute.simd:300 [D] s_b_3_28 = s_b_3_26[s_b_3_27] <= s_b_3_4 */
    auto s_b_3_28 = emitter.vector_insert(s_b_3_26, emitter.const_s32((int32_t)11ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_29 = constant s32 c (const) */
    /* execute.simd:300 [D] s_b_3_30 = s_b_3_28[s_b_3_29] <= s_b_3_4 */
    auto s_b_3_30 = emitter.vector_insert(s_b_3_28, emitter.const_s32((int32_t)12ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_31 = constant s32 d (const) */
    /* execute.simd:300 [D] s_b_3_32 = s_b_3_30[s_b_3_31] <= s_b_3_4 */
    auto s_b_3_32 = emitter.vector_insert(s_b_3_30, emitter.const_s32((int32_t)13ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_33 = constant s32 e (const) */
    /* execute.simd:300 [D] s_b_3_34 = s_b_3_32[s_b_3_33] <= s_b_3_4 */
    auto s_b_3_34 = emitter.vector_insert(s_b_3_32, emitter.const_s32((int32_t)14ULL), s_b_3_4);
    /* execute.simd:300 [F] s_b_3_35 = constant s32 f (const) */
    /* execute.simd:300 [D] s_b_3_36 = s_b_3_34[s_b_3_35] <= s_b_3_4 */
    auto s_b_3_36 = emitter.vector_insert(s_b_3_34, emitter.const_s32((int32_t)15ULL), s_b_3_4);
    /* execute.simd:303 [F] s_b_3_37=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:303 [D] s_b_3_38: WriteRegBank 16:s_b_3_37 = s_b_3_36 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_36,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_36);
    /* execute.simd:0 [F] s_b_3_39: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:307 [F] s_b_4_0=sym_9107_3_parameter_inst.rn (const) */
    /* execute.simd:307 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_2 = constant v4u16 
    {
    }
    (const) */
    /* execute.simd:310 [F] s_b_4_3=sym_9107_3_parameter_inst.eindex (const) */
    /* execute.simd:310 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_u8(insn.eindex));
    /* execute.simd:312 [F] s_b_4_5 = constant s32 0 (const) */
    /* execute.simd:312 [D] s_b_4_6 = s_b_4_2[s_b_4_5] <= s_b_4_4 */
    auto s_b_4_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 4>(0)[0], emitter.context().types().v4u16()), emitter.const_s32((int32_t)0ULL), s_b_4_4);
    /* execute.simd:312 [F] s_b_4_7 = constant s32 1 (const) */
    /* execute.simd:312 [D] s_b_4_8 = s_b_4_6[s_b_4_7] <= s_b_4_4 */
    auto s_b_4_8 = emitter.vector_insert(s_b_4_6, emitter.const_s32((int32_t)1ULL), s_b_4_4);
    /* execute.simd:312 [F] s_b_4_9 = constant s32 2 (const) */
    /* execute.simd:312 [D] s_b_4_10 = s_b_4_8[s_b_4_9] <= s_b_4_4 */
    auto s_b_4_10 = emitter.vector_insert(s_b_4_8, emitter.const_s32((int32_t)2ULL), s_b_4_4);
    /* execute.simd:312 [F] s_b_4_11 = constant s32 3 (const) */
    /* execute.simd:312 [D] s_b_4_12 = s_b_4_10[s_b_4_11] <= s_b_4_4 */
    auto s_b_4_12 = emitter.vector_insert(s_b_4_10, emitter.const_s32((int32_t)3ULL), s_b_4_4);
    /* execute.simd:315 [F] s_b_4_13=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:315 [D] s_b_4_14: WriteRegBank 17:s_b_4_13 = s_b_4_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_12);
    /* execute.simd:316 [F] s_b_4_15=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:316 [F] s_b_4_16 = constant u64 0 (const) */
    /* execute.simd:316 [F] s_b_4_17: WriteRegBank 3:s_b_4_15 = s_b_4_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_18: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:320 [F] s_b_5_0=sym_9107_3_parameter_inst.rn (const) */
    /* execute.simd:320 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_2 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:323 [F] s_b_5_3=sym_9107_3_parameter_inst.eindex (const) */
    /* execute.simd:323 [D] s_b_5_1[s_b_5_3] */
    auto s_b_5_4 = emitter.vector_extract(s_b_5_1, emitter.const_u8(insn.eindex));
    /* execute.simd:325 [F] s_b_5_5 = constant s32 0 (const) */
    /* execute.simd:325 [D] s_b_5_6 = s_b_5_2[s_b_5_5] <= s_b_5_4 */
    auto s_b_5_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_5_4);
    /* execute.simd:325 [F] s_b_5_7 = constant s32 1 (const) */
    /* execute.simd:325 [D] s_b_5_8 = s_b_5_6[s_b_5_7] <= s_b_5_4 */
    auto s_b_5_8 = emitter.vector_insert(s_b_5_6, emitter.const_s32((int32_t)1ULL), s_b_5_4);
    /* execute.simd:325 [F] s_b_5_9 = constant s32 2 (const) */
    /* execute.simd:325 [D] s_b_5_10 = s_b_5_8[s_b_5_9] <= s_b_5_4 */
    auto s_b_5_10 = emitter.vector_insert(s_b_5_8, emitter.const_s32((int32_t)2ULL), s_b_5_4);
    /* execute.simd:325 [F] s_b_5_11 = constant s32 3 (const) */
    /* execute.simd:325 [D] s_b_5_12 = s_b_5_10[s_b_5_11] <= s_b_5_4 */
    auto s_b_5_12 = emitter.vector_insert(s_b_5_10, emitter.const_s32((int32_t)3ULL), s_b_5_4);
    /* execute.simd:325 [F] s_b_5_13 = constant s32 4 (const) */
    /* execute.simd:325 [D] s_b_5_14 = s_b_5_12[s_b_5_13] <= s_b_5_4 */
    auto s_b_5_14 = emitter.vector_insert(s_b_5_12, emitter.const_s32((int32_t)4ULL), s_b_5_4);
    /* execute.simd:325 [F] s_b_5_15 = constant s32 5 (const) */
    /* execute.simd:325 [D] s_b_5_16 = s_b_5_14[s_b_5_15] <= s_b_5_4 */
    auto s_b_5_16 = emitter.vector_insert(s_b_5_14, emitter.const_s32((int32_t)5ULL), s_b_5_4);
    /* execute.simd:325 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:325 [D] s_b_5_18 = s_b_5_16[s_b_5_17] <= s_b_5_4 */
    auto s_b_5_18 = emitter.vector_insert(s_b_5_16, emitter.const_s32((int32_t)6ULL), s_b_5_4);
    /* execute.simd:325 [F] s_b_5_19 = constant s32 7 (const) */
    /* execute.simd:325 [D] s_b_5_20 = s_b_5_18[s_b_5_19] <= s_b_5_4 */
    auto s_b_5_20 = emitter.vector_insert(s_b_5_18, emitter.const_s32((int32_t)7ULL), s_b_5_4);
    /* execute.simd:328 [F] s_b_5_21=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:328 [D] s_b_5_22: WriteRegBank 18:s_b_5_21 = s_b_5_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_20,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_20);
    /* execute.simd:0 [F] s_b_5_23: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:332 [F] s_b_6_0=sym_9107_3_parameter_inst.rn (const) */
    /* execute.simd:332 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v2u32 
    {
    }
    (const) */
    /* execute.simd:335 [F] s_b_6_3=sym_9107_3_parameter_inst.eindex (const) */
    /* execute.simd:335 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_u8(insn.eindex));
    /* execute.simd:337 [F] s_b_6_5 = constant s32 0 (const) */
    /* execute.simd:337 [D] s_b_6_6 = s_b_6_2[s_b_6_5] <= s_b_6_4 */
    auto s_b_6_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 2>(0)[0], emitter.context().types().v2u32()), emitter.const_s32((int32_t)0ULL), s_b_6_4);
    /* execute.simd:337 [F] s_b_6_7 = constant s32 1 (const) */
    /* execute.simd:337 [D] s_b_6_8 = s_b_6_6[s_b_6_7] <= s_b_6_4 */
    auto s_b_6_8 = emitter.vector_insert(s_b_6_6, emitter.const_s32((int32_t)1ULL), s_b_6_4);
    /* execute.simd:340 [F] s_b_6_9=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:340 [D] s_b_6_10: WriteRegBank 19:s_b_6_9 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_8,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_8);
    /* execute.simd:341 [F] s_b_6_11=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:341 [F] s_b_6_12 = constant u64 0 (const) */
    /* execute.simd:341 [F] s_b_6_13: WriteRegBank 3:s_b_6_11 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:345 [F] s_b_7_0=sym_9107_3_parameter_inst.rn (const) */
    /* execute.simd:345 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_2 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:348 [F] s_b_7_3=sym_9107_3_parameter_inst.eindex (const) */
    /* execute.simd:348 [D] s_b_7_1[s_b_7_3] */
    auto s_b_7_4 = emitter.vector_extract(s_b_7_1, emitter.const_u8(insn.eindex));
    /* execute.simd:350 [F] s_b_7_5 = constant s32 0 (const) */
    /* execute.simd:350 [D] s_b_7_6 = s_b_7_2[s_b_7_5] <= s_b_7_4 */
    auto s_b_7_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_7_4);
    /* execute.simd:350 [F] s_b_7_7 = constant s32 1 (const) */
    /* execute.simd:350 [D] s_b_7_8 = s_b_7_6[s_b_7_7] <= s_b_7_4 */
    auto s_b_7_8 = emitter.vector_insert(s_b_7_6, emitter.const_s32((int32_t)1ULL), s_b_7_4);
    /* execute.simd:350 [F] s_b_7_9 = constant s32 2 (const) */
    /* execute.simd:350 [D] s_b_7_10 = s_b_7_8[s_b_7_9] <= s_b_7_4 */
    auto s_b_7_10 = emitter.vector_insert(s_b_7_8, emitter.const_s32((int32_t)2ULL), s_b_7_4);
    /* execute.simd:350 [F] s_b_7_11 = constant s32 3 (const) */
    /* execute.simd:350 [D] s_b_7_12 = s_b_7_10[s_b_7_11] <= s_b_7_4 */
    auto s_b_7_12 = emitter.vector_insert(s_b_7_10, emitter.const_s32((int32_t)3ULL), s_b_7_4);
    /* execute.simd:353 [F] s_b_7_13=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:353 [D] s_b_7_14: WriteRegBank 20:s_b_7_13 = s_b_7_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_12);
    /* execute.simd:0 [F] s_b_7_15: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:357 [F] s_b_8_0=sym_9107_3_parameter_inst.rn (const) */
    /* execute.simd:357 [D] s_b_8_1 = ReadRegBank 21:s_b_8_0 (v2u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_2 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:360 [F] s_b_8_3=sym_9107_3_parameter_inst.eindex (const) */
    /* execute.simd:360 [D] s_b_8_1[s_b_8_3] */
    auto s_b_8_4 = emitter.vector_extract(s_b_8_1, emitter.const_u8(insn.eindex));
    /* execute.simd:362 [F] s_b_8_5 = constant s32 0 (const) */
    /* execute.simd:362 [D] s_b_8_6 = s_b_8_2[s_b_8_5] <= s_b_8_4 */
    auto s_b_8_6 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_8_4);
    /* execute.simd:362 [F] s_b_8_7 = constant s32 1 (const) */
    /* execute.simd:362 [D] s_b_8_8 = s_b_8_6[s_b_8_7] <= s_b_8_4 */
    auto s_b_8_8 = emitter.vector_insert(s_b_8_6, emitter.const_s32((int32_t)1ULL), s_b_8_4);
    /* execute.simd:365 [F] s_b_8_9=sym_9107_3_parameter_inst.rd (const) */
    /* execute.simd:365 [D] s_b_8_10: WriteRegBank 21:s_b_8_9 = s_b_8_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_8,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_8);
    /* execute.simd:0 [F] s_b_8_11: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.simd:369 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_1 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_extr(const aarch64_decode_a64_EXTRACT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_10215_0_v = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_10248_0_rn = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_10259_0_v = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_58955_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_58914_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_59092_1__R_s_b_19_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_59112_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_59134_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_59156_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_59178_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_58939_1__R_s_b_3_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_58981_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:151 [F] s_b_0_0=sym_10203_3_parameter_inst.rn (const) */
    /* execute.a64:151 [F] s_b_0_1=sym_10203_3_parameter_inst.rm (const) */
    /* execute.a64:151 [F] s_b_0_2 = s_b_0_0==s_b_0_1 (const) */
    uint8_t s_b_0_2 = ((uint8_t)(insn.rn == insn.rm));
    /* execute.a64:151 [F] s_b_0_3: If s_b_0_2: Jump b_1 else b_3 (const) */
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
    /* execute.a64:152 [F] s_b_1_0=sym_10203_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_1_1: If s_b_1_0: Jump b_11 else b_12 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_17, b_18, b_19, b_20, b_24, b_25, b_26, b_27,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:162 [F] s_b_3_0=sym_10203_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_3_1: If s_b_3_0: Jump b_14 else b_15 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_13,  */
  fixed_block_b_4: 
  {
    /* execute.a64:155 [D] s_b_4_0 = sym_10215_0_v uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_10215_0_v, emitter.context().types().u64());
    /* execute.a64:155 [D] s_b_4_1 = (u32)s_b_4_0 */
    auto s_b_4_1 = emitter.truncate(s_b_4_0, emitter.context().types().u32());
    /* execute.a64:155 [F] s_b_4_2=sym_10203_3_parameter_inst.imms (const) */
    /* execute.a64:155 [F] s_b_4_3 = (u32)s_b_4_2 (const) */
    /* execute.a64:155 [D] s_b_4_4 = s_b_4_1>>>s_b_4_3 */
    auto s_b_4_4 = emitter.ror(s_b_4_1, emitter.const_u32(((uint32_t)insn.imms)));
    /* execute.a64:155 [D] s_b_4_5 = (u64)s_b_4_4 */
    auto s_b_4_5 = emitter.zx(s_b_4_4, emitter.context().types().u64());
    /* execute.a64:155 [D] s_b_4_6: sym_10215_0_v = s_b_4_5, dominates: s_b_5_1  */
    emitter.store_local(DV_sym_10215_0_v, s_b_4_5);
    /* execute.a64:155 [F] s_b_4_7: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_6,  */
  fixed_block_b_5: 
  {
    /* execute.a64:160 [F] s_b_5_0=sym_10203_3_parameter_inst.sf (const) */
    /* execute.a64:160 [D] s_b_5_1 = sym_10215_0_v uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_10215_0_v, emitter.context().types().u64());
    /* execute.a64:160 [D] s_b_5_2: sym_58955_3_parameter_value = s_b_5_1, dominates: s_b_17_1 s_b_18_1  */
    emitter.store_local(DV_sym_58955_3_parameter_value, s_b_5_1);
    /* execute.a64:2690 [F] s_b_5_3: If s_b_5_0: Jump b_17 else b_18 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_13,  */
  fixed_block_b_6: 
  {
    /* execute.a64:157 [D] s_b_6_0 = sym_10215_0_v uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_10215_0_v, emitter.context().types().u64());
    /* execute.a64:157 [F] s_b_6_1=sym_10203_3_parameter_inst.imms (const) */
    /* execute.a64:157 [F] s_b_6_2 = (u64)s_b_6_1 (const) */
    /* execute.a64:157 [D] s_b_6_3 = s_b_6_0>>>s_b_6_2 */
    auto s_b_6_3 = emitter.ror(s_b_6_0, emitter.const_u64(((uint64_t)insn.imms)));
    /* execute.a64:157 [D] s_b_6_4: sym_10215_0_v = s_b_6_3, dominates: s_b_5_1  */
    emitter.store_local(DV_sym_10215_0_v, s_b_6_3);
    /* execute.a64:157 [F] s_b_6_5: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_23,  */
  fixed_block_b_7: 
  {
    /* execute.a64:168 [F] s_b_7_0=sym_10203_3_parameter_inst.imms (const) */
    /* execute.a64:168 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:168 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.a64:168 [F] s_b_7_3 = s_b_7_1>s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.imms) > (uint32_t)0ULL));
    /* execute.a64:168 [F] s_b_7_4: If s_b_7_3: Jump b_10 else b_8 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_7, b_9, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:175 [F] s_b_8_0=sym_10203_3_parameter_inst.sf (const) */
    /* execute.a64:175 [D] s_b_8_1 = sym_10259_0_v uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_10259_0_v, emitter.context().types().u64());
    /* execute.a64:175 [D] s_b_8_2: sym_58981_3_parameter_value = s_b_8_1, dominates: s_b_19_1 s_b_20_1  */
    emitter.store_local(DV_sym_58981_3_parameter_value, s_b_8_1);
    /* execute.a64:2690 [F] s_b_8_3: If s_b_8_0: Jump b_19 else b_20 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_23,  */
  fixed_block_b_9: 
  {
    /* execute.a64:172 [D] s_b_9_0 = sym_10259_0_v uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_10259_0_v, emitter.context().types().u64());
    /* execute.a64:172 [D] s_b_9_1 = sym_10248_0_rn uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_10248_0_rn, emitter.context().types().u64());
    /* execute.a64:172 [F] s_b_9_2=sym_10203_3_parameter_inst.imms (const) */
    /* execute.a64:172 [F] s_b_9_3 = constant u32 20 (const) */
    /* execute.a64:172 [F] s_b_9_4 = (u32)s_b_9_2 (const) */
    /* execute.a64:172 [F] s_b_9_5 = s_b_9_3-s_b_9_4 (const) */
    uint32_t s_b_9_5 = ((uint32_t)((uint32_t)32ULL - ((uint32_t)insn.imms)));
    /* execute.a64:172 [F] s_b_9_6 = (u64)s_b_9_5 (const) */
    /* execute.a64:172 [D] s_b_9_7 = s_b_9_1<<s_b_9_6 */
    auto s_b_9_7 = emitter.shl(s_b_9_1, emitter.const_u64(((uint64_t)s_b_9_5)));
    /* ???:4294967295 [D] s_b_9_8 = s_b_9_0|s_b_9_7 */
    auto s_b_9_8 = emitter.bitwise_or(s_b_9_0, s_b_9_7);
    /* execute.a64:172 [D] s_b_9_9: sym_10259_0_v = s_b_9_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_10259_0_v, s_b_9_8);
    /* execute.a64:172 [F] s_b_9_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_10: 
  {
    /* execute.a64:169 [D] s_b_10_0 = sym_10259_0_v uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_10259_0_v, emitter.context().types().u64());
    /* execute.a64:169 [D] s_b_10_1 = sym_10248_0_rn uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_10248_0_rn, emitter.context().types().u64());
    /* execute.a64:169 [F] s_b_10_2=sym_10203_3_parameter_inst.imms (const) */
    /* execute.a64:169 [F] s_b_10_3 = constant u32 40 (const) */
    /* execute.a64:169 [F] s_b_10_4 = (u32)s_b_10_2 (const) */
    /* execute.a64:169 [F] s_b_10_5 = s_b_10_3-s_b_10_4 (const) */
    uint32_t s_b_10_5 = ((uint32_t)((uint32_t)64ULL - ((uint32_t)insn.imms)));
    /* execute.a64:169 [F] s_b_10_6 = (u64)s_b_10_5 (const) */
    /* execute.a64:169 [D] s_b_10_7 = s_b_10_1<<s_b_10_6 */
    auto s_b_10_7 = emitter.shl(s_b_10_1, emitter.const_u64(((uint64_t)s_b_10_5)));
    /* ???:4294967295 [D] s_b_10_8 = s_b_10_0|s_b_10_7 */
    auto s_b_10_8 = emitter.bitwise_or(s_b_10_0, s_b_10_7);
    /* execute.a64:169 [D] s_b_10_9: sym_10259_0_v = s_b_10_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_10259_0_v, s_b_10_8);
    /* execute.a64:169 [F] s_b_10_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_1,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2657 [F] s_b_11_0=sym_10203_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2651 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_11_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_11_5 = ReadRegBank 0:s_b_11_0 (u64) */
    auto s_b_11_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_11_6: Select s_b_11_3 ? s_b_11_4 : s_b_11_5 */
    captive::arch::dbt::el::Value *s_b_11_6;
    s_b_11_6 = (s_b_11_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_11_5);
    /* execute.a64:2657 [D] s_b_11_7: sym_58914_1__R_s_b_1_4 = s_b_11_6, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_58914_1__R_s_b_1_4, s_b_11_6);
    /* execute.a64:2657 [F] s_b_11_8: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_1,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2659 [F] s_b_12_0=sym_10203_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.a64:2646 [F] s_b_12_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_12_5 = ReadRegBank 1:s_b_12_0 (u32) */
    auto s_b_12_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_12_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_12_6: Select s_b_12_3 ? s_b_12_4 : s_b_12_5 */
    captive::arch::dbt::el::Value *s_b_12_6;
    s_b_12_6 = (s_b_12_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_12_5);
    /* execute.a64:2659 [D] s_b_12_7 = (u64)s_b_12_6 */
    auto s_b_12_7 = emitter.zx(s_b_12_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_12_8: sym_58914_1__R_s_b_1_4 = s_b_12_7, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_58914_1__R_s_b_1_4, s_b_12_7);
    /* execute.a64:2659 [F] s_b_12_9: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_11, b_12,  */
  fixed_block_b_13: 
  {
    /* execute.a64:152 [D] s_b_13_0 = sym_58914_1__R_s_b_1_4 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_58914_1__R_s_b_1_4, emitter.context().types().u64());
    /* execute.a64:152 [D] s_b_13_1: sym_10215_0_v = s_b_13_0, dominates: s_b_4_0 s_b_6_0  */
    emitter.store_local(DV_sym_10215_0_v, s_b_13_0);
    /* execute.a64:154 [F] s_b_13_2=sym_10203_3_parameter_inst.sf (const) */
    /* execute.a64:154 [F] s_b_13_3 = (u32)s_b_13_2 (const) */
    /* execute.a64:154 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:154 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
    uint8_t s_b_13_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:154 [F] s_b_13_6: If s_b_13_5: Jump b_4 else b_6 (const) */
    if (s_b_13_5) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_3,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2657 [F] s_b_14_0=sym_10203_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
    /* execute.a64:2651 [F] s_b_14_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_14_3 = s_b_14_1==s_b_14_2 (const) */
    uint8_t s_b_14_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_14_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_14_5 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_14_6: Select s_b_14_3 ? s_b_14_4 : s_b_14_5 */
    captive::arch::dbt::el::Value *s_b_14_6;
    s_b_14_6 = (s_b_14_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_14_5);
    /* execute.a64:2657 [D] s_b_14_7: sym_58939_1__R_s_b_3_4 = s_b_14_6, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_58939_1__R_s_b_3_4, s_b_14_6);
    /* execute.a64:2657 [F] s_b_14_8: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_3,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2659 [F] s_b_15_0=sym_10203_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.a64:2646 [F] s_b_15_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_15_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_15_5 = ReadRegBank 1:s_b_15_0 (u32) */
    auto s_b_15_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_15_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_15_6: Select s_b_15_3 ? s_b_15_4 : s_b_15_5 */
    captive::arch::dbt::el::Value *s_b_15_6;
    s_b_15_6 = (s_b_15_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_15_5);
    /* execute.a64:2659 [D] s_b_15_7 = (u64)s_b_15_6 */
    auto s_b_15_7 = emitter.zx(s_b_15_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_15_8: sym_58939_1__R_s_b_3_4 = s_b_15_7, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_58939_1__R_s_b_3_4, s_b_15_7);
    /* execute.a64:2659 [F] s_b_15_9: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_14, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:162 [D] s_b_16_0 = sym_58939_1__R_s_b_3_4 uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_58939_1__R_s_b_3_4, emitter.context().types().u64());
    /* execute.a64:162 [D] s_b_16_1: sym_10248_0_rn = s_b_16_0, dominates: s_b_10_1 s_b_9_1  */
    emitter.store_local(DV_sym_10248_0_rn, s_b_16_0);
    /* execute.a64:163 [F] s_b_16_2=sym_10203_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_16_3: If s_b_16_2: Jump b_21 else b_22 (const) */
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
  fixed_block_b_17: 
  {
    /* execute.a64:2691 [F] s_b_17_0=sym_10203_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_17_1 = sym_58955_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_58955_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_17_2: sym_59112_3_parameter_value = s_b_17_1, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_59112_3_parameter_value, s_b_17_1);
    /* execute.a64:2682 [F] s_b_17_3 = (u32)s_b_17_0 (const) */
    /* execute.a64:2682 [F] s_b_17_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_17_5 = s_b_17_3==s_b_17_4 (const) */
    uint8_t s_b_17_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_17_6: If s_b_17_5: Jump b_2 else b_24 (const) */
    if (s_b_17_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2693 [F] s_b_18_0=sym_10203_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_18_1 = sym_58955_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_58955_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_18_2 = (u32)s_b_18_1 */
    auto s_b_18_2 = emitter.truncate(s_b_18_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_18_3 = (u64)s_b_18_2 */
    auto s_b_18_3 = emitter.zx(s_b_18_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_18_4: sym_59134_3_parameter_value = s_b_18_3, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_59134_3_parameter_value, s_b_18_3);
    /* execute.a64:2682 [F] s_b_18_5 = (u32)s_b_18_0 (const) */
    /* execute.a64:2682 [F] s_b_18_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_18_7 = s_b_18_5==s_b_18_6 (const) */
    uint8_t s_b_18_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_18_8: If s_b_18_7: Jump b_2 else b_25 (const) */
    if (s_b_18_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_8,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2691 [F] s_b_19_0=sym_10203_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_19_1 = sym_58981_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_58981_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_19_2: sym_59156_3_parameter_value = s_b_19_1, dominates: s_b_26_1  */
    emitter.store_local(DV_sym_59156_3_parameter_value, s_b_19_1);
    /* execute.a64:2682 [F] s_b_19_3 = (u32)s_b_19_0 (const) */
    /* execute.a64:2682 [F] s_b_19_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_19_5 = s_b_19_3==s_b_19_4 (const) */
    uint8_t s_b_19_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_19_6: If s_b_19_5: Jump b_2 else b_26 (const) */
    if (s_b_19_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_8,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2693 [F] s_b_20_0=sym_10203_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_20_1 = sym_58981_3_parameter_value uint64_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_58981_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_20_2 = (u32)s_b_20_1 */
    auto s_b_20_2 = emitter.truncate(s_b_20_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_20_3 = (u64)s_b_20_2 */
    auto s_b_20_3 = emitter.zx(s_b_20_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_20_4: sym_59178_3_parameter_value = s_b_20_3, dominates: s_b_27_1  */
    emitter.store_local(DV_sym_59178_3_parameter_value, s_b_20_3);
    /* execute.a64:2682 [F] s_b_20_5 = (u32)s_b_20_0 (const) */
    /* execute.a64:2682 [F] s_b_20_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_20_7 = s_b_20_5==s_b_20_6 (const) */
    uint8_t s_b_20_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_20_8: If s_b_20_7: Jump b_2 else b_27 (const) */
    if (s_b_20_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_16,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2657 [F] s_b_21_0=sym_10203_3_parameter_inst.rm (const) */
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
    /* execute.a64:2657 [D] s_b_21_7: sym_59092_1__R_s_b_19_6 = s_b_21_6, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_59092_1__R_s_b_19_6, s_b_21_6);
    /* execute.a64:2657 [F] s_b_21_8: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_16,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2659 [F] s_b_22_0=sym_10203_3_parameter_inst.rm (const) */
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
    /* execute.a64:2659 [D] s_b_22_8: sym_59092_1__R_s_b_19_6 = s_b_22_7, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_59092_1__R_s_b_19_6, s_b_22_7);
    /* execute.a64:2659 [F] s_b_22_9: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:163 [D] s_b_23_0 = sym_59092_1__R_s_b_19_6 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_59092_1__R_s_b_19_6, emitter.context().types().u64());
    /* execute.a64:165 [F] s_b_23_1=sym_10203_3_parameter_inst.imms (const) */
    /* execute.a64:165 [F] s_b_23_2 = (u64)s_b_23_1 (const) */
    /* execute.a64:165 [D] s_b_23_3 = s_b_23_0>>s_b_23_2 */
    auto s_b_23_3 = emitter.shr(s_b_23_0, emitter.const_u64(((uint64_t)insn.imms)));
    /* execute.a64:165 [D] s_b_23_4: sym_10259_0_v = s_b_23_3, dominates: s_b_10_0 s_b_8_1 s_b_9_0  */
    emitter.store_local(DV_sym_10259_0_v, s_b_23_3);
    /* execute.a64:167 [F] s_b_23_5=sym_10203_3_parameter_inst.sf (const) */
    /* execute.a64:167 [F] s_b_23_6: If s_b_23_5: Jump b_7 else b_9 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_17,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2684 [F] s_b_24_0=sym_10203_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_24_1 = sym_59112_3_parameter_value uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_59112_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_24_2: WriteRegBank 0:s_b_24_0 = s_b_24_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_24_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_24_1);
    /* execute.a64:0 [F] s_b_24_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_18,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2684 [F] s_b_25_0=sym_10203_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_25_1 = sym_59134_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_59134_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1);
    /* execute.a64:0 [F] s_b_25_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_19,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2684 [F] s_b_26_0=sym_10203_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_26_1 = sym_59156_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_59156_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1);
    /* execute.a64:0 [F] s_b_26_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_20,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2684 [F] s_b_27_0=sym_10203_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_27_1 = sym_59178_3_parameter_value uint64_t */
    auto s_b_27_1 = emitter.load_local(DV_sym_59178_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_27_2: WriteRegBank 0:s_b_27_0 = s_b_27_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_27_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_27_1);
    /* execute.a64:0 [F] s_b_27_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fcvt(const aarch64_decode_a64_FP_DP_1&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4377 [F] s_b_0_0=sym_10758_3_parameter_inst.type (const) */
    /* execute.simd:4377 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4377 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4377 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4377 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4379 [F] s_b_1_0=sym_10758_3_parameter_inst.opcode (const) */
    /* execute.simd:4379 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4379 [F] s_b_1_2 = constant u32 5 (const) */
    /* execute.simd:4379 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)5ULL));
    /* execute.simd:4379 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_5, b_7, b_8, b_9,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4385 [F] s_b_3_0=sym_10758_3_parameter_inst.type (const) */
    /* execute.simd:4385 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4385 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4385 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4385 [F] s_b_3_4: If s_b_3_3: Jump b_6 else b_7 (const) */
    if (s_b_3_3) 
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
    /* execute.simd:4381 [F] s_b_4_0=sym_10758_3_parameter_inst.rd (const) */
    /* execute.simd:4381 [F] s_b_4_1=sym_10758_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_4_2 = ReadRegBank 9:s_b_4_1 (f32) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_2,emitter.const_u8(4));
    }
    /* execute.simd:4381 [D] s_b_4_3 = (f64)s_b_4_2 */
    auto s_b_4_3 = emitter.convert(s_b_4_2, emitter.context().types().f64());
    /* execute.simd:6110 [D] s_b_4_4: WriteRegBank 11:s_b_4_0 = s_b_4_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_3);
    /* execute.simd:6111 [F] s_b_4_5 = constant u64 0 (const) */
    /* execute.simd:6111 [F] s_b_4_6: WriteRegBank 3:s_b_4_0 = s_b_4_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4383 [D] s_b_5_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4383 [F] s_b_5_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4387 [F] s_b_6_0=sym_10758_3_parameter_inst.opcode (const) */
    /* execute.simd:4387 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.simd:4387 [F] s_b_6_2 = constant u32 4 (const) */
    /* execute.simd:4387 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)4ULL));
    /* execute.simd:4387 [F] s_b_6_4: If s_b_6_3: Jump b_8 else b_9 (const) */
    if (s_b_6_3) 
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
    /* execute.simd:4394 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4394 [F] s_b_7_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4389 [F] s_b_8_0=sym_10758_3_parameter_inst.rd (const) */
    /* execute.simd:4389 [F] s_b_8_1=sym_10758_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_8_2 = ReadRegBank 11:s_b_8_1 (f64) */
    auto s_b_8_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_2,emitter.const_u8(8));
    }
    /* execute.simd:4389 [D] s_b_8_3 = (f32)s_b_8_2 */
    auto s_b_8_3 = emitter.convert(s_b_8_2, emitter.context().types().f32());
    /* execute.simd:6102 [D] s_b_8_4: WriteRegBank 9:s_b_8_0 = s_b_8_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_3,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_3);
    /* execute.simd:6103 [F] s_b_8_5 = constant u32 0 (const) */
    /* execute.simd:6103 [F] s_b_8_6: WriteRegBank 10:s_b_8_0 = s_b_8_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6104 [F] s_b_8_7 = constant u64 0 (const) */
    /* execute.simd:6104 [F] s_b_8_8: WriteRegBank 3:s_b_8_0 = s_b_8_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4391 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4391 [F] s_b_9_1: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fmaxnmv(const aarch64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fmul(const aarch64_decode_a64_FP_DP_2&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4039 [F] s_b_0_0=sym_12114_3_parameter_inst.type (const) */
    /* execute.simd:4039 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4039 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4039 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4039 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4041 [F] s_b_1_0=sym_12114_3_parameter_inst.rn (const) */
    /* execute.simd:6092 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4042 [F] s_b_1_2=sym_12114_3_parameter_inst.rm (const) */
    /* execute.simd:6092 [D] s_b_1_3 = ReadRegBank 9:s_b_1_2 (f32) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(4));
    }
    /* execute.simd:4044 [D] s_b_1_4 = s_b_1_1*s_b_1_3 */
    auto s_b_1_4 = emitter.mul(s_b_1_1, s_b_1_3);
    /* execute.simd:4045 [F] s_b_1_5=sym_12114_3_parameter_inst.rd (const) */
    /* execute.simd:6102 [D] s_b_1_6: WriteRegBank 9:s_b_1_5 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4);
    /* execute.simd:6103 [F] s_b_1_7 = constant u32 0 (const) */
    /* execute.simd:6103 [F] s_b_1_8: WriteRegBank 10:s_b_1_5 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6104 [F] s_b_1_9 = constant u64 0 (const) */
    /* execute.simd:6104 [F] s_b_1_10: WriteRegBank 3:s_b_1_5 = s_b_1_9 */
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
    /* execute.simd:4048 [F] s_b_3_0=sym_12114_3_parameter_inst.rn (const) */
    /* execute.simd:6097 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4049 [F] s_b_3_2=sym_12114_3_parameter_inst.rm (const) */
    /* execute.simd:6097 [D] s_b_3_3 = ReadRegBank 11:s_b_3_2 (f64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:4051 [D] s_b_3_4 = s_b_3_1*s_b_3_3 */
    auto s_b_3_4 = emitter.mul(s_b_3_1, s_b_3_3);
    /* execute.simd:4052 [F] s_b_3_5=sym_12114_3_parameter_inst.rd (const) */
    /* execute.simd:6110 [D] s_b_3_6: WriteRegBank 11:s_b_3_5 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:6111 [F] s_b_3_7 = constant u64 0 (const) */
    /* execute.simd:6111 [F] s_b_3_8: WriteRegBank 3:s_b_3_5 = s_b_3_7 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fsub_vector(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1348 [F] s_b_0_0=sym_12578_3_parameter_inst.Q (const) */
    /* execute.simd:1349 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:1359 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:1348 [F] s_b_0_3: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_3, b_2, b_1,  */
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
    /* execute.simd:1350 [F] s_b_2_0=sym_12578_3_parameter_inst.rn (const) */
    /* execute.simd:1350 [D] s_b_2_1 = ReadRegBank 12:s_b_2_0 (v2f32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1351 [F] s_b_2_2=sym_12578_3_parameter_inst.rm (const) */
    /* execute.simd:1351 [D] s_b_2_3 = ReadRegBank 12:s_b_2_2 (v2f32) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* execute.simd:1353 [D] s_b_2_4 = s_b_2_1-s_b_2_3 */
    auto s_b_2_4 = emitter.sub(s_b_2_1, s_b_2_3);
    /* execute.simd:1354 [F] s_b_2_5=sym_12578_3_parameter_inst.rd (const) */
    /* execute.simd:1354 [D] s_b_2_6: WriteRegBank 12:s_b_2_5 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4);
    /* execute.simd:1355 [F] s_b_2_7=sym_12578_3_parameter_inst.rd (const) */
    /* execute.simd:1355 [F] s_b_2_8 = constant u64 0 (const) */
    /* execute.simd:1355 [F] s_b_2_9: WriteRegBank 3:s_b_2_7 = s_b_2_8 */
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
    /* execute.simd:1360 [F] s_b_3_0=sym_12578_3_parameter_inst.size (const) */
    /* execute.simd:1361 [F] s_b_3_1 = constant s32 2 (const) */
    /* execute.simd:1370 [F] s_b_3_2 = constant s32 3 (const) */
    /* execute.simd:1360 [F] s_b_3_3: Switch s_b_3_0: < <todo> > def b_1 (const) -> b_5, b_4, b_1,  */
    switch (insn.size) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:1362 [F] s_b_4_0=sym_12578_3_parameter_inst.rn (const) */
    /* execute.simd:1362 [D] s_b_4_1 = ReadRegBank 13:s_b_4_0 (v4f32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:1363 [F] s_b_4_2=sym_12578_3_parameter_inst.rm (const) */
    /* execute.simd:1363 [D] s_b_4_3 = ReadRegBank 13:s_b_4_2 (v4f32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(16));
    }
    /* execute.simd:1365 [D] s_b_4_4 = s_b_4_1-s_b_4_3 */
    auto s_b_4_4 = emitter.sub(s_b_4_1, s_b_4_3);
    /* execute.simd:1366 [F] s_b_4_5=sym_12578_3_parameter_inst.rd (const) */
    /* execute.simd:1366 [D] s_b_4_6: WriteRegBank 13:s_b_4_5 = s_b_4_4 */
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
    /* execute.simd:1371 [F] s_b_5_0=sym_12578_3_parameter_inst.rn (const) */
    /* execute.simd:1371 [D] s_b_5_1 = ReadRegBank 14:s_b_5_0 (v2f64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1372 [F] s_b_5_2=sym_12578_3_parameter_inst.rm (const) */
    /* execute.simd:1372 [D] s_b_5_3 = ReadRegBank 14:s_b_5_2 (v2f64) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1374 [D] s_b_5_4 = s_b_5_1-s_b_5_3 */
    auto s_b_5_4 = emitter.sub(s_b_5_1, s_b_5_3);
    /* execute.simd:1375 [F] s_b_5_5=sym_12578_3_parameter_inst.rd (const) */
    /* execute.simd:1375 [D] s_b_5_6: WriteRegBank 14:s_b_5_5 = s_b_5_4 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ld2(const aarch64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_64633_3_parameter_rt;
  auto DV_sym_64684_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_64735_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_64760_1_tmp_s_b_5_2;
  auto DV_sym_64763_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64792_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64718_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_64596_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64631_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_64629_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13351_0_rt;
  uint8_t CV_sym_13339_0_lane;
  auto DV_sym_13316_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64667_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_64701_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_64639_3_parameter_lane;
  auto DV_sym_64650_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13310_3_parameter_inst.rn (const) */
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
    /* execute.simd:2326 [F] s_b_1_0 = sym_13339_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13339_0_lane;
    /* execute.simd:2326 [F] s_b_1_1=sym_13310_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2326 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2326 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2327 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2327 [F] s_b_2_1: sym_13351_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13351_0_rt = (uint8_t)0ULL;
    /* execute.simd:2327 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2327 [F] s_b_4_0 = sym_13351_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13351_0_rt;
    /* execute.simd:2327 [F] s_b_4_1=sym_13310_3_parameter_inst.regcnt (const) */
    /* execute.simd:2327 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2327 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2328 [F] s_b_5_0=sym_13310_3_parameter_inst.arrangement (const) */
    /* execute.simd:2328 [F] s_b_5_1=sym_13310_3_parameter_inst.rt (const) */
    /* execute.simd:2328 [F] s_b_5_2 = sym_13351_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13351_0_rt;
    /* execute.simd:2328 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2328 [F] s_b_5_4 = sym_13339_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13339_0_lane;
    /* execute.simd:2328 [D] s_b_5_5 = sym_13316_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13316_0_address, emitter.context().types().u64());
    /* execute.simd:2328 [F] s_b_5_6: sym_64633_3_parameter_rt = s_b_5_3 (const), dominates: s_b_13_2 s_b_10_2 s_b_11_2 s_b_16_2 s_b_15_2 s_b_14_2 s_b_12_2  */
    CV_sym_64633_3_parameter_rt = s_b_5_3;
    /* execute.simd:2328 [F] s_b_5_7: sym_64639_3_parameter_lane = s_b_5_4 (const), dominates: s_b_13_5 s_b_10_5 s_b_11_5 s_b_16_5 s_b_15_5 s_b_14_5 s_b_12_5  */
    CV_sym_64639_3_parameter_lane = s_b_5_4;
    /* execute.simd:2328 [D] s_b_5_8: sym_64629_3_parameter_addr = s_b_5_5, dominates: s_b_13_0 s_b_10_0 s_b_11_0 s_b_16_0 s_b_15_0 s_b_14_0 s_b_12_0  */
    emitter.store_local(DV_sym_64629_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_64760_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_17_1  */
    CV_sym_64760_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_64763_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_64763_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3700 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3709 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3718 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3727 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3736 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3745 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3754 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3699 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_9 (const) -> b_13, b_9, b_10, b_11, b_16, b_15, b_14, b_12,  */
    switch (insn.arrangement) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_11;
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
    /* execute.simd:2326 [F] s_b_6_0 = sym_13339_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13339_0_lane;
    /* execute.simd:2326 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2326 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2326 [F] s_b_6_3: sym_13339_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13339_0_lane = s_b_6_2;
    /* execute.simd:2326 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2733 [F] s_b_7_0=sym_13310_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_7_1 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_7_2: sym_64596_1__R_s_b_0_5 = s_b_7_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_64596_1__R_s_b_0_5, s_b_7_1);
    /* execute.a64:2733 [F] s_b_7_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_22,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2321 [D] s_b_8_0 = sym_64596_1__R_s_b_0_5 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_64596_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2321 [D] s_b_8_1: sym_13316_0_address = s_b_8_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13316_0_address, s_b_8_0);
    /* execute.simd:2323 [F] s_b_8_2=sym_13310_3_parameter_inst.rt (const) */
    /* execute.simd:2323 [F] s_b_8_3 = constant u64 0 (const) */
    /* execute.simd:2323 [F] s_b_8_4 = constant u64 0 (const) */
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
    /* execute.simd:2324 [F] s_b_8_7=sym_13310_3_parameter_inst.rt (const) */
    /* execute.simd:2324 [F] s_b_8_8 = (u32)s_b_8_7 (const) */
    /* execute.simd:2324 [F] s_b_8_9 = constant u32 1 (const) */
    /* execute.simd:2324 [F] s_b_8_10 = s_b_8_8+s_b_8_9 (const) */
    uint32_t s_b_8_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2324 [F] s_b_8_11 = (u8)s_b_8_10 (const) */
    /* execute.simd:2324 [F] s_b_8_12 = constant u64 0 (const) */
    /* execute.simd:2324 [F] s_b_8_13 = constant u64 0 (const) */
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
    /* execute.simd:2326 [F] s_b_8_16 = constant u8 0 (const) */
    /* execute.simd:2326 [F] s_b_8_17: sym_13339_0_lane = s_b_8_16 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13339_0_lane = (uint8_t)0ULL;
    /* execute.simd:2326 [F] s_b_8_18: Jump b_1 (const) */
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
    /* execute.simd:3702 [D] s_b_10_0 = sym_64629_3_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_64629_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 1 s_b_10_0 => sym_64631_0_mem_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_64631_0_mem_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(1));
    }
    /* execute.simd:3704 [F] s_b_10_2 = sym_64633_3_parameter_rt (const) uint8_t */
    uint8_t s_b_10_2 = CV_sym_64633_3_parameter_rt;
    /* execute.simd:3704 [D] s_b_10_3 = ReadRegBank 15:s_b_10_2 (v8u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:3705 [D] s_b_10_4 = sym_64631_0_mem_value uint8_t */
    auto s_b_10_4 = emitter.load_local(DV_sym_64631_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3705 [F] s_b_10_5 = sym_64639_3_parameter_lane (const) uint8_t */
    uint8_t s_b_10_5 = CV_sym_64639_3_parameter_lane;
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
    /* execute.simd:3711 [D] s_b_11_0 = sym_64629_3_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_64629_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 1 s_b_11_0 => sym_64650_0_mem_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_64650_0_mem_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(1));
    }
    /* execute.simd:3713 [F] s_b_11_2 = sym_64633_3_parameter_rt (const) uint8_t */
    uint8_t s_b_11_2 = CV_sym_64633_3_parameter_rt;
    /* execute.simd:3713 [D] s_b_11_3 = ReadRegBank 16:s_b_11_2 (v16u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:3714 [D] s_b_11_4 = sym_64650_0_mem_value uint8_t */
    auto s_b_11_4 = emitter.load_local(DV_sym_64650_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3714 [F] s_b_11_5 = sym_64639_3_parameter_lane (const) uint8_t */
    uint8_t s_b_11_5 = CV_sym_64639_3_parameter_lane;
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
    /* execute.simd:3720 [D] s_b_12_0 = sym_64629_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_64629_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_64667_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_64667_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3722 [F] s_b_12_2 = sym_64633_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_64633_3_parameter_rt;
    /* execute.simd:3722 [D] s_b_12_3 = ReadRegBank 17:s_b_12_2 (v4u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3723 [D] s_b_12_4 = sym_64667_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_64667_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3723 [F] s_b_12_5 = sym_64639_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_64639_3_parameter_lane;
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
    /* execute.simd:3729 [D] s_b_13_0 = sym_64629_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_64629_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 2 s_b_13_0 => sym_64684_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_64684_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(2));
    }
    /* execute.simd:3731 [F] s_b_13_2 = sym_64633_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_64633_3_parameter_rt;
    /* execute.simd:3731 [D] s_b_13_3 = ReadRegBank 18:s_b_13_2 (v8u16) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3732 [D] s_b_13_4 = sym_64684_0_mem_value uint16_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_64684_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3732 [F] s_b_13_5 = sym_64639_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_64639_3_parameter_lane;
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
    /* execute.simd:3738 [D] s_b_14_0 = sym_64629_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_64629_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_64701_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_64701_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.simd:3740 [F] s_b_14_2 = sym_64633_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_64633_3_parameter_rt;
    /* execute.simd:3740 [D] s_b_14_3 = ReadRegBank 19:s_b_14_2 (v2u32) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3741 [D] s_b_14_4 = sym_64701_0_mem_value uint32_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_64701_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3741 [F] s_b_14_5 = sym_64639_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_64639_3_parameter_lane;
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
    /* execute.simd:3747 [D] s_b_15_0 = sym_64629_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_64629_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 4 s_b_15_0 => sym_64718_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_64718_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(4));
    }
    /* execute.simd:3749 [F] s_b_15_2 = sym_64633_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_64633_3_parameter_rt;
    /* execute.simd:3749 [D] s_b_15_3 = ReadRegBank 20:s_b_15_2 (v4u32) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3750 [D] s_b_15_4 = sym_64718_0_mem_value uint32_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_64718_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3750 [F] s_b_15_5 = sym_64639_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_64639_3_parameter_lane;
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
    /* execute.simd:3756 [D] s_b_16_0 = sym_64629_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_64629_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_64735_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_64735_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.simd:3758 [F] s_b_16_2 = sym_64633_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_64633_3_parameter_rt;
    /* execute.simd:3758 [D] s_b_16_3 = ReadRegBank 21:s_b_16_2 (v2u64) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3759 [D] s_b_16_4 = sym_64735_0_mem_value uint64_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_64735_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3759 [F] s_b_16_5 = sym_64639_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_64639_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_17_0 = sym_64763_1_tmp_s_b_5_5 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_64763_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1 = sym_64760_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_17_1 = CV_sym_64760_1_tmp_s_b_5_2;
    /* execute.simd:2329 [F] s_b_17_2=sym_13310_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* ???:4294967295 [D] s_b_17_4 = s_b_17_0+s_b_17_3 */
    auto s_b_17_4 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2329 [D] s_b_17_5: sym_13316_0_address = s_b_17_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13316_0_address, s_b_17_4);
    /* execute.simd:2327 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:2327 [F] s_b_17_7 = s_b_17_1+s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(s_b_17_1 + (uint8_t)1ULL));
    /* execute.simd:2327 [F] s_b_17_8: sym_13351_0_rt = s_b_17_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13351_0_rt = s_b_17_7;
    /* execute.simd:2327 [F] s_b_17_9: Jump b_4 (const) */
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
    /* execute.a64:2702 [D] s_b_19_1: sym_64792_1__R_s_b_10_0 = s_b_19_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_64792_1__R_s_b_10_0, s_b_19_0);
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
    /* execute.a64:2705 [D] s_b_20_1: sym_64792_1__R_s_b_10_0 = s_b_20_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_64792_1__R_s_b_10_0, s_b_20_0);
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
    /* execute.a64:2707 [D] s_b_21_1: sym_64792_1__R_s_b_10_0 = s_b_21_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_64792_1__R_s_b_10_0, s_b_21_0);
    /* execute.a64:2707 [F] s_b_21_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19, b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2731 [D] s_b_22_0 = sym_64792_1__R_s_b_10_0 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_64792_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_22_1: sym_64596_1__R_s_b_0_5 = s_b_22_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_64596_1__R_s_b_0_5, s_b_22_0);
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldarh(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_71263_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_71301_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_72100_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_71364_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_71419_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13944_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_1_0=sym_13944_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_1_2: sym_71263_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_71263_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2733 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:699 [D] s_b_2_0 = sym_71263_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_71263_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:700 [D] s_b_2_1: sym_71364_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_71364_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 2 s_b_2_0 => sym_71419_0_data16 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_71419_0_data16, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(2));
    }
    /* execute.a64:1677 [D] s_b_2_3 = sym_71419_0_data16 uint16_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_71419_0_data16, emitter.context().types().u16());
    /* execute.a64:1677 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_2_5=sym_13944_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_2_8: sym_72100_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_72100_3_parameter_value, s_b_2_7);
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
    /* execute.a64:2702 [D] s_b_4_1: sym_71301_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_71301_1__R_s_b_4_0, s_b_4_0);
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
    /* execute.a64:2705 [D] s_b_5_1: sym_71301_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_71301_1__R_s_b_4_0, s_b_5_0);
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
    /* execute.a64:2707 [D] s_b_6_1: sym_71301_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_71301_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2707 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2731 [D] s_b_7_0 = sym_71301_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_71301_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_7_1: sym_71263_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_71263_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2731 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1723 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_8_1 = sym_71364_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_71364_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_10_0=sym_13944_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_10_1 = sym_72100_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_72100_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldpi(const aarch64_decode_a64_LS_REG_PAIR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14313_0_d132 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_14319_0_d232 = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_14323_0_data1;
  auto DV_sym_14323_0_data1 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_14327_0_data2;
  auto DV_sym_14327_0_data2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14292_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87596_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87304_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87324_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87368_1__R_s_b_14_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87426_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87448_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87466_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87518_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87540_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87557_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14286_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_15 else b_10 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_11,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1597 [D] s_b_1_0 = sym_14292_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14292_0_address, emitter.context().types().u64());
    /* execute.a64:1597 [F] s_b_1_1=sym_14286_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.a64:1597 [D] s_b_1_3: sym_14292_0_address = s_b_1_2, dominates: s_b_3_0 s_b_8_0 s_b_24_1 s_b_6_0  */
    emitter.store_local(DV_sym_14292_0_address, s_b_1_2);
    /* execute.a64:1597 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_11,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1603 [F] s_b_2_0=sym_14286_3_parameter_inst.opc (const) */
    /* execute.a64:1603 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:1603 [F] s_b_2_2 = constant u32 0 (const) */
    /* execute.a64:1603 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:1603 [F] s_b_2_4: If s_b_2_3: Jump b_3 else b_5 (const) */
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
    /* execute.a64:1607 [D] s_b_3_0 = sym_14292_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14292_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_1 = Load 4 s_b_3_0 => sym_14313_0_d132 */
    auto s_b_3_1 = emitter.load_memory(s_b_3_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_14313_0_d132, s_b_3_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_1, emitter.const_u8(4));
    }
    /* execute.a64:1608 [F] s_b_3_2 = constant u64 4 (const) */
    /* execute.a64:1608 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64((uint64_t)4ULL));
    /* ???:4294967295 [D] s_b_3_4 = Load 4 s_b_3_3 => sym_14319_0_d232 */
    auto s_b_3_4 = emitter.load_memory(s_b_3_3, emitter.context().types().u32());
    emitter.store_local(DV_sym_14319_0_d232, s_b_3_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_3, s_b_3_4, emitter.const_u8(4));
    }
    /* execute.a64:1610 [D] s_b_3_5 = sym_14313_0_d132 uint32_t */
    auto s_b_3_5 = emitter.load_local(DV_sym_14313_0_d132, emitter.context().types().u32());
    /* execute.a64:1610 [D] s_b_3_6 = (u64)s_b_3_5 */
    auto s_b_3_6 = emitter.zx(s_b_3_5, emitter.context().types().u64());
    /* execute.a64:1610 [D] s_b_3_7: sym_14323_0_data1 = s_b_3_6, dominates: s_b_9_4  */
    emitter.store_local(DV_sym_14323_0_data1, s_b_3_6);
    /* execute.a64:1611 [D] s_b_3_8 = sym_14319_0_d232 uint32_t */
    auto s_b_3_8 = emitter.load_local(DV_sym_14319_0_d232, emitter.context().types().u32());
    /* execute.a64:1611 [D] s_b_3_9 = (u64)s_b_3_8 */
    auto s_b_3_9 = emitter.zx(s_b_3_8, emitter.context().types().u64());
    /* execute.a64:1611 [D] s_b_3_10: sym_14327_0_data2 = s_b_3_9, dominates: s_b_14_4  */
    emitter.store_local(DV_sym_14327_0_data2, s_b_3_9);
    /* execute.a64:1604 [F] s_b_3_11: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_6, b_7,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1621 [F] s_b_4_0=sym_14286_3_parameter_inst.P (const) */
    /* execute.a64:1621 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:1621 [F] s_b_4_2: If s_b_4_1: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1612 [F] s_b_5_0=sym_14286_3_parameter_inst.opc (const) */
    /* execute.a64:1612 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1612 [F] s_b_5_2 = constant u32 2 (const) */
    /* execute.a64:1612 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1612 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1613 [D] s_b_6_0 = sym_14292_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_14292_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1 = Load 8 s_b_6_0 => sym_14323_0_data1 */
    auto s_b_6_1 = emitter.load_memory(s_b_6_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_14323_0_data1, s_b_6_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_1, emitter.const_u8(8));
    }
    /* execute.a64:1614 [F] s_b_6_2 = constant u64 8 (const) */
    /* execute.a64:1614 [D] s_b_6_3 = s_b_6_0+s_b_6_2 */
    auto s_b_6_3 = emitter.add(s_b_6_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_6_4 = Load 8 s_b_6_3 => sym_14327_0_data2 */
    auto s_b_6_4 = emitter.load_memory(s_b_6_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_14327_0_data2, s_b_6_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_3, s_b_6_4, emitter.const_u8(8));
    }
    /* execute.a64:1613 [F] s_b_6_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1616 [F] s_b_7_0 = constant u64 0 (const) */
    /* execute.a64:1616 [F] s_b_7_1: sym_14323_0_data1 = s_b_7_0 (const), dominates: s_b_9_4  */
    CV_sym_14323_0_data1 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_14323_0_data1, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1617 [F] s_b_7_2 = constant u64 0 (const) */
    /* execute.a64:1617 [F] s_b_7_3: sym_14327_0_data2 = s_b_7_2 (const), dominates: s_b_14_4  */
    CV_sym_14327_0_data2 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_14327_0_data2, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1618 [D] s_b_7_4 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1616 [F] s_b_7_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1622 [D] s_b_8_0 = sym_14292_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_14292_0_address, emitter.context().types().u64());
    /* execute.a64:1622 [F] s_b_8_1=sym_14286_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_8_2 = s_b_8_0+s_b_8_1 */
    auto s_b_8_2 = emitter.add(s_b_8_0, emitter.const_u64(insn.immu64));
    /* execute.a64:1622 [D] s_b_8_3: sym_14292_0_address = s_b_8_2, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_14292_0_address, s_b_8_2);
    /* execute.a64:1622 [F] s_b_8_4: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1625 [F] s_b_9_0=sym_14286_3_parameter_inst.opc (const) */
    /* execute.a64:1625 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:1625 [F] s_b_9_2 = constant u32 2 (const) */
    /* execute.a64:1625 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1625 [D] s_b_9_4 = sym_14323_0_data1 uint64_t */
    auto s_b_9_4 = emitter.load_local(DV_sym_14323_0_data1, emitter.context().types().u64());
    /* execute.a64:1625 [D] s_b_9_5: sym_87324_3_parameter_value = s_b_9_4, dominates: s_b_12_1 s_b_13_1  */
    emitter.store_local(DV_sym_87324_3_parameter_value, s_b_9_4);
    /* execute.a64:2690 [F] s_b_9_6: If s_b_9_3: Jump b_12 else b_13 (const) */
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
    /* execute.a64:2733 [F] s_b_10_0=sym_14286_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_10_2: sym_87304_1__R_s_b_0_5 = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_87304_1__R_s_b_0_5, s_b_10_1);
    /* execute.a64:2733 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_19,  */
  fixed_block_b_11: 
  {
    /* execute.a64:1594 [D] s_b_11_0 = sym_87304_1__R_s_b_0_5 uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_87304_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1594 [D] s_b_11_1: sym_14292_0_address = s_b_11_0, dominates: s_b_1_0 s_b_3_0 s_b_8_0 s_b_24_1 s_b_6_0  */
    emitter.store_local(DV_sym_14292_0_address, s_b_11_0);
    /* execute.a64:1596 [F] s_b_11_2=sym_14286_3_parameter_inst.P (const) */
    /* execute.a64:1596 [F] s_b_11_3: If s_b_11_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2691 [F] s_b_12_0=sym_14286_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_12_1 = sym_87324_3_parameter_value uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_87324_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_12_2: sym_87426_3_parameter_value = s_b_12_1, dominates: s_b_20_1  */
    emitter.store_local(DV_sym_87426_3_parameter_value, s_b_12_1);
    /* execute.a64:2682 [F] s_b_12_3 = (u32)s_b_12_0 (const) */
    /* execute.a64:2682 [F] s_b_12_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_12_6: If s_b_12_5: Jump b_14 else b_20 (const) */
    if (s_b_12_5) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_9,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2693 [F] s_b_13_0=sym_14286_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_13_1 = sym_87324_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_87324_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_13_2 = (u32)s_b_13_1 */
    auto s_b_13_2 = emitter.truncate(s_b_13_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_13_3 = (u64)s_b_13_2 */
    auto s_b_13_3 = emitter.zx(s_b_13_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_13_4: sym_87448_3_parameter_value = s_b_13_3, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_87448_3_parameter_value, s_b_13_3);
    /* execute.a64:2682 [F] s_b_13_5 = (u32)s_b_13_0 (const) */
    /* execute.a64:2682 [F] s_b_13_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_13_7 = s_b_13_5==s_b_13_6 (const) */
    uint8_t s_b_13_7 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_13_8: If s_b_13_7: Jump b_14 else b_21 (const) */
    if (s_b_13_7) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_12, b_13, b_20, b_21,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1626 [F] s_b_14_0=sym_14286_3_parameter_inst.opc (const) */
    /* execute.a64:1626 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
    /* execute.a64:1626 [F] s_b_14_2 = constant u32 2 (const) */
    /* execute.a64:1626 [F] s_b_14_3 = s_b_14_1==s_b_14_2 (const) */
    uint8_t s_b_14_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1626 [D] s_b_14_4 = sym_14327_0_data2 uint64_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_14327_0_data2, emitter.context().types().u64());
    /* execute.a64:1626 [D] s_b_14_5: sym_87466_3_parameter_value = s_b_14_4, dominates: s_b_22_1 s_b_23_1  */
    emitter.store_local(DV_sym_87466_3_parameter_value, s_b_14_4);
    /* execute.a64:2690 [F] s_b_14_6: If s_b_14_3: Jump b_22 else b_23 (const) */
    if (s_b_14_3) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_0,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2701 [F] s_b_15_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_15_1 = __builtin_get_feature */
    uint32_t s_b_15_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_15_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(s_b_15_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_15_4: If s_b_15_3: Jump b_16 else b_25 (const) */
    if (s_b_15_3) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2702 [D] s_b_16_0 = ReadReg 20 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_16_1: sym_87368_1__R_s_b_14_0 = s_b_16_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_87368_1__R_s_b_14_0, s_b_16_0);
    /* execute.a64:2702 [F] s_b_16_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_25,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2705 [D] s_b_17_0 = ReadReg 20 (u64) */
    auto s_b_17_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_17_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_17_1: sym_87368_1__R_s_b_14_0 = s_b_17_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_87368_1__R_s_b_14_0, s_b_17_0);
    /* execute.a64:2705 [F] s_b_17_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_25,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2707 [D] s_b_18_0 = ReadReg 21 (u64) */
    auto s_b_18_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_18_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_18_1: sym_87368_1__R_s_b_14_0 = s_b_18_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_87368_1__R_s_b_14_0, s_b_18_0);
    /* execute.a64:2707 [F] s_b_18_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_16, b_17, b_18,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2731 [D] s_b_19_0 = sym_87368_1__R_s_b_14_0 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_87368_1__R_s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_19_1: sym_87304_1__R_s_b_0_5 = s_b_19_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_87304_1__R_s_b_0_5, s_b_19_0);
    /* execute.a64:2731 [F] s_b_19_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_12,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2684 [F] s_b_20_0=sym_14286_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_20_1 = sym_87426_3_parameter_value uint64_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_87426_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_20_2: WriteRegBank 0:s_b_20_0 = s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_20_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_20_1);
    /* execute.a64:0 [F] s_b_20_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_13,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2684 [F] s_b_21_0=sym_14286_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_21_1 = sym_87448_3_parameter_value uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_87448_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_21_2: WriteRegBank 0:s_b_21_0 = s_b_21_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_21_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_21_1);
    /* execute.a64:0 [F] s_b_21_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_14,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2691 [F] s_b_22_0=sym_14286_3_parameter_inst.rt2 (const) */
    /* execute.a64:2691 [D] s_b_22_1 = sym_87466_3_parameter_value uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_87466_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_22_2: sym_87518_3_parameter_value = s_b_22_1, dominates: s_b_26_1  */
    emitter.store_local(DV_sym_87518_3_parameter_value, s_b_22_1);
    /* execute.a64:2682 [F] s_b_22_3 = (u32)s_b_22_0 (const) */
    /* execute.a64:2682 [F] s_b_22_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_22_5 = s_b_22_3==s_b_22_4 (const) */
    uint8_t s_b_22_5 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_22_6: If s_b_22_5: Jump b_24 else b_26 (const) */
    if (s_b_22_5) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_14,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2693 [F] s_b_23_0=sym_14286_3_parameter_inst.rt2 (const) */
    /* execute.a64:2693 [D] s_b_23_1 = sym_87466_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_87466_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_23_2 = (u32)s_b_23_1 */
    auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_23_3 = (u64)s_b_23_2 */
    auto s_b_23_3 = emitter.zx(s_b_23_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_23_4: sym_87540_3_parameter_value = s_b_23_3, dominates: s_b_27_1  */
    emitter.store_local(DV_sym_87540_3_parameter_value, s_b_23_3);
    /* execute.a64:2682 [F] s_b_23_5 = (u32)s_b_23_0 (const) */
    /* execute.a64:2682 [F] s_b_23_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_23_7 = s_b_23_5==s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_23_8: If s_b_23_7: Jump b_24 else b_27 (const) */
    if (s_b_23_7) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_22, b_23, b_26, b_27,  */
  fixed_block_b_24: 
  {
    /* execute.a64:1628 [F] s_b_24_0 = constant u8 1 (const) */
    /* execute.a64:1628 [D] s_b_24_1 = sym_14292_0_address uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_14292_0_address, emitter.context().types().u64());
    /* execute.a64:1628 [D] s_b_24_2: sym_87557_3_parameter_value = s_b_24_1, dominates: s_b_28_0 s_b_30_0 s_b_31_1  */
    emitter.store_local(DV_sym_87557_3_parameter_value, s_b_24_1);
    /* execute.a64:2746 [F] s_b_24_3 = !s_b_24_0 (const) */
    uint8_t s_b_24_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_24_4: If s_b_24_3: Jump b_28 else b_29 (const) */
    if (s_b_24_3) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_15,  */
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
    /* execute.a64:2704 [F] s_b_25_6: If s_b_25_5: Jump b_17 else b_18 (const) */
    if (s_b_25_5) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_22,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2684 [F] s_b_26_0=sym_14286_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_26_1 = sym_87518_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_87518_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_26_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_26_1);
    /* execute.a64:0 [F] s_b_26_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2684 [F] s_b_27_0=sym_14286_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_27_1 = sym_87540_3_parameter_value uint64_t */
    auto s_b_27_1 = emitter.load_local(DV_sym_87540_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_27_2: WriteRegBank 0:s_b_27_0 = s_b_27_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_27_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_27_1);
    /* execute.a64:0 [F] s_b_27_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_24,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2747 [D] s_b_28_0 = sym_87557_3_parameter_value uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_87557_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_28_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_28_2 = s_b_28_0&s_b_28_1 */
    auto s_b_28_2 = emitter.bitwise_and(s_b_28_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_28_3: sym_87557_3_parameter_value = s_b_28_2, dominates: s_b_30_0 s_b_31_1  */
    emitter.store_local(DV_sym_87557_3_parameter_value, s_b_28_2);
    /* execute.a64:2747 [F] s_b_28_4: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_24, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2750 [F] s_b_29_0=sym_14286_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
    /* execute.a64:2750 [F] s_b_29_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_29_4: If s_b_29_3: Jump b_30 else b_31 (const) */
    if (s_b_29_3) 
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
    /* execute.a64:2751 [D] s_b_30_0 = sym_87557_3_parameter_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_87557_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_30_1: sym_87596_3_parameter_value = s_b_30_0, dominates: s_b_33_0 s_b_34_0 s_b_35_0  */
    emitter.store_local(DV_sym_87596_3_parameter_value, s_b_30_0);
    /* execute.a64:2714 [F] s_b_30_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_30_3 = __builtin_get_feature */
    uint32_t s_b_30_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_30_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_30_5 = s_b_30_3==s_b_30_4 (const) */
    uint8_t s_b_30_5 = ((uint8_t)(s_b_30_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_30_6: If s_b_30_5: Jump b_33 else b_36 (const) */
    if (s_b_30_5) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_36;
    }
  }
  /* b_29,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2753 [F] s_b_31_0=sym_14286_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_31_1 = sym_87557_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_87557_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_31_2: WriteRegBank 0:s_b_31_0 = s_b_31_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_31_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_31_1);
    /* execute.a64:2753 [F] s_b_31_3: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_31, b_33, b_34, b_35,  */
  fixed_block_b_32: 
  {
    /* ???:4294967295 [F] s_b_32_0: Return */
    goto fixed_done;
  }
  /* b_30,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2715 [D] s_b_33_0 = sym_87596_3_parameter_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_87596_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_33_1: WriteReg 20 = s_b_33_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_33_0);
    /* execute.a64:2715 [F] s_b_33_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_36,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2718 [D] s_b_34_0 = sym_87596_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_87596_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_34_1: WriteReg 20 = s_b_34_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_34_0);
    /* execute.a64:2718 [F] s_b_34_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_36,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2720 [D] s_b_35_0 = sym_87596_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_87596_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_35_1: WriteReg 21 = s_b_35_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_35_0);
    /* execute.a64:2720 [F] s_b_35_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_30,  */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldr_reg_simd(const aarch64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_15022_0_shift;
  uint64_t CV_sym_15049_0_rm;
  auto DV_sym_15049_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_15147_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96816_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_96889_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96638_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96941_1__R_s_b_45_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96632_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96669_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_96743_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_96147_1__R_s_b_2_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3870 [F] s_b_0_0=sym_15004_3_parameter_inst.S (const) */
    /* execute.simd:3870 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:3870 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:3870 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.S) == (uint32_t)0ULL));
    /* execute.simd:3870 [F] s_b_0_4 = constant u8 0 (const) */
    /* execute.simd:3870 [F] s_b_0_5=sym_15004_3_parameter_inst.X (const) */
    /* execute.simd:3870 [F] s_b_0_6 = (u32)s_b_0_5 (const) */
    /* execute.simd:3870 [F] s_b_0_7 = constant u32 1 (const) */
    /* execute.simd:3870 [F] s_b_0_8 = s_b_0_6==s_b_0_7 (const) */
    uint8_t s_b_0_8 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* execute.simd:3870 [F] s_b_0_9 = constant u8 4 (const) */
    /* execute.simd:3870 [F] s_b_0_10=sym_15004_3_parameter_inst.size (const) */
    /* execute.simd:3870 [F] s_b_0_11 = (u8)s_b_0_10 (const) */
    /* execute.simd:3870 [F] s_b_0_12: Select s_b_0_8 ? s_b_0_9 : s_b_0_11 (const) */
    uint8_t s_b_0_12 = ((uint8_t)(s_b_0_8 ? ((uint8_t)4ULL) : (((uint8_t)insn.size))));
    /* execute.simd:3870 [F] s_b_0_13: Select s_b_0_3 ? s_b_0_4 : s_b_0_12 (const) */
    uint8_t s_b_0_13 = ((uint8_t)(s_b_0_3 ? ((uint8_t)0ULL) : (s_b_0_12)));
    /* execute.simd:3870 [F] s_b_0_14: sym_15022_0_shift = s_b_0_13 (const), dominates: s_b_1_1 s_b_4_1 s_b_6_1 s_b_8_1  */
    CV_sym_15022_0_shift = s_b_0_13;
    /* execute.simd:3873 [F] s_b_0_15=sym_15004_3_parameter_inst.option0 (const) */
    /* execute.simd:3873 [F] s_b_0_16 = (u32)s_b_0_15 (const) */
    /* execute.simd:3873 [F] s_b_0_17 = constant u32 0 (const) */
    /* execute.simd:3873 [F] s_b_0_18 = s_b_0_16==s_b_0_17 (const) */
    uint8_t s_b_0_18 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.simd:3873 [F] s_b_0_19=sym_15004_3_parameter_inst.option21 (const) */
    /* execute.simd:3873 [F] s_b_0_20 = (u32)s_b_0_19 (const) */
    /* execute.simd:3873 [F] s_b_0_21 = constant u32 1 (const) */
    /* execute.simd:3873 [F] s_b_0_22 = s_b_0_20==s_b_0_21 (const) */
    uint8_t s_b_0_22 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_23 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_24 = s_b_0_18!=s_b_0_23 (const) */
    uint8_t s_b_0_24 = ((uint8_t)(s_b_0_18 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_25 = s_b_0_22!=s_b_0_23 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(s_b_0_22 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_26 = s_b_0_24&s_b_0_25 (const) */
    uint8_t s_b_0_26 = ((uint8_t)(s_b_0_24 & s_b_0_25));
    /* execute.simd:3873 [F] s_b_0_27: If s_b_0_26: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3874 [F] s_b_1_0=sym_15004_3_parameter_inst.rm (const) */
    /* execute.simd:3874 [F] s_b_1_1 = sym_15022_0_shift (const) uint8_t */
    uint8_t s_b_1_1 = CV_sym_15022_0_shift;
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
    /* execute.simd:3874 [D] s_b_1_13: sym_15049_0_rm = s_b_1_12, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_15049_0_rm, s_b_1_12);
    /* execute.simd:3874 [F] s_b_1_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_8, b_9,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2730 [F] s_b_2_0=sym_15004_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2730 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_2_4: If s_b_2_3: Jump b_22 else b_20 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:3875 [F] s_b_3_0=sym_15004_3_parameter_inst.option0 (const) */
    /* execute.simd:3875 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:3875 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:3875 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.simd:3875 [F] s_b_3_4=sym_15004_3_parameter_inst.option21 (const) */
    /* execute.simd:3875 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:3875 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.simd:3875 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:3875 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.simd:3876 [F] s_b_4_0=sym_15004_3_parameter_inst.rm (const) */
    /* execute.simd:3876 [F] s_b_4_1 = sym_15022_0_shift (const) uint8_t */
    uint8_t s_b_4_1 = CV_sym_15022_0_shift;
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
    /* execute.simd:3876 [D] s_b_4_14: sym_15049_0_rm = s_b_4_13, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_15049_0_rm, s_b_4_13);
    /* execute.simd:3876 [F] s_b_4_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:3877 [F] s_b_5_0=sym_15004_3_parameter_inst.option0 (const) */
    /* execute.simd:3877 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:3877 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:3877 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.simd:3877 [F] s_b_5_4=sym_15004_3_parameter_inst.option21 (const) */
    /* execute.simd:3877 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:3877 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.simd:3877 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.simd:3877 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.simd:3878 [F] s_b_6_0=sym_15004_3_parameter_inst.rm (const) */
    /* execute.simd:3878 [F] s_b_6_1 = sym_15022_0_shift (const) uint8_t */
    uint8_t s_b_6_1 = CV_sym_15022_0_shift;
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
    /* execute.simd:3878 [D] s_b_6_10: sym_15049_0_rm = s_b_6_9, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_15049_0_rm, s_b_6_9);
    /* execute.simd:3878 [F] s_b_6_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:3879 [F] s_b_7_0=sym_15004_3_parameter_inst.option0 (const) */
    /* execute.simd:3879 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:3879 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.simd:3879 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.simd:3879 [F] s_b_7_4=sym_15004_3_parameter_inst.option21 (const) */
    /* execute.simd:3879 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:3879 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.simd:3879 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:3879 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.simd:3880 [F] s_b_8_0=sym_15004_3_parameter_inst.rm (const) */
    /* execute.simd:3880 [F] s_b_8_1 = sym_15022_0_shift (const) uint8_t */
    uint8_t s_b_8_1 = CV_sym_15022_0_shift;
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
    /* execute.simd:3880 [D] s_b_8_10: sym_15049_0_rm = s_b_8_9, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_15049_0_rm, s_b_8_9);
    /* execute.simd:3880 [F] s_b_8_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3882 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.simd:3882 [F] s_b_9_1: sym_15049_0_rm = s_b_9_0 (const), dominates: s_b_21_1  */
    CV_sym_15049_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_15049_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:3883 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:3882 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_21,  */
  fixed_block_b_10: 
  {
    /* execute.simd:3889 [F] s_b_10_0=sym_15004_3_parameter_inst.X (const) */
    /* execute.simd:3889 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:3889 [F] s_b_10_2 = constant u32 1 (const) */
    /* execute.simd:3889 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* execute.simd:3889 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
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
  /* b_21,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3896 [F] s_b_12_0=sym_15004_3_parameter_inst.size (const) */
    /* execute.simd:3896 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.simd:3896 [F] s_b_12_2 = constant u32 1 (const) */
    /* execute.simd:3896 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:3896 [F] s_b_12_4: If s_b_12_3: Jump b_15 else b_16 (const) */
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
    /* execute.simd:3891 [D] s_b_13_0 = sym_15147_0_address uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_15147_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 8 s_b_13_0 => sym_96632_0_vl */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_96632_0_vl, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(8));
    }
    /* execute.simd:3639 [F] s_b_13_2 = constant u64 8 (const) */
    /* execute.simd:3639 [D] s_b_13_3 = s_b_13_0+s_b_13_2 */
    auto s_b_13_3 = emitter.add(s_b_13_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_13_4 = Load 8 s_b_13_3 => sym_96638_0_vh */
    auto s_b_13_4 = emitter.load_memory(s_b_13_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_96638_0_vh, s_b_13_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_3, s_b_13_4, emitter.const_u8(8));
    }
    /* execute.simd:3640 [F] s_b_13_5=sym_15004_3_parameter_inst.rt (const) */
    /* execute.simd:3640 [D] s_b_13_6 = sym_96632_0_vl uint64_t */
    auto s_b_13_6 = emitter.load_local(DV_sym_96632_0_vl, emitter.context().types().u64());
    /* execute.simd:3640 [D] s_b_13_7 = sym_96638_0_vh uint64_t */
    auto s_b_13_7 = emitter.load_local(DV_sym_96638_0_vh, emitter.context().types().u64());
    /* execute.simd:6145 [D] s_b_13_8: WriteRegBank 2:s_b_13_5 = s_b_13_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_6);
    /* execute.simd:6146 [D] s_b_13_9: WriteRegBank 3:s_b_13_5 = s_b_13_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_7);
    /* execute.simd:0 [F] s_b_13_10: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.simd:3894 [D] s_b_14_0 = sym_15147_0_address uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_15147_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 1 s_b_14_0 => sym_96669_0_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_96669_0_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(1));
    }
    /* execute.simd:3610 [F] s_b_14_2=sym_15004_3_parameter_inst.rt (const) */
    /* execute.simd:3610 [D] s_b_14_3 = sym_96669_0_value uint8_t */
    auto s_b_14_3 = emitter.load_local(DV_sym_96669_0_value, emitter.context().types().u8());
    /* execute.simd:6117 [D] s_b_14_4 = (u64)s_b_14_3 */
    auto s_b_14_4 = emitter.zx(s_b_14_3, emitter.context().types().u64());
    /* execute.simd:6117 [D] s_b_14_5: WriteRegBank 2:s_b_14_2 = s_b_14_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_4);
    /* execute.simd:6118 [F] s_b_14_6 = constant u64 0 (const) */
    /* execute.simd:6118 [F] s_b_14_7: WriteRegBank 3:s_b_14_2 = s_b_14_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_14_8: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_12,  */
  fixed_block_b_15: 
  {
    /* execute.simd:3898 [D] s_b_15_0 = sym_15147_0_address uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_15147_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_96743_0_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_96743_0_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3617 [F] s_b_15_2=sym_15004_3_parameter_inst.rt (const) */
    /* execute.simd:3617 [D] s_b_15_3 = sym_96743_0_value uint16_t */
    auto s_b_15_3 = emitter.load_local(DV_sym_96743_0_value, emitter.context().types().u16());
    /* execute.simd:6124 [D] s_b_15_4 = (u64)s_b_15_3 */
    auto s_b_15_4 = emitter.zx(s_b_15_3, emitter.context().types().u64());
    /* execute.simd:6124 [D] s_b_15_5: WriteRegBank 2:s_b_15_2 = s_b_15_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_15_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_15_4);
    /* execute.simd:6125 [F] s_b_15_6 = constant u64 0 (const) */
    /* execute.simd:6125 [F] s_b_15_7: WriteRegBank 3:s_b_15_2 = s_b_15_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_15_8: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_12,  */
  fixed_block_b_16: 
  {
    /* execute.simd:3899 [F] s_b_16_0=sym_15004_3_parameter_inst.size (const) */
    /* execute.simd:3899 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.simd:3899 [F] s_b_16_2 = constant u32 2 (const) */
    /* execute.simd:3899 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:3899 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
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
    /* execute.simd:3901 [D] s_b_17_0 = sym_15147_0_address uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_15147_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_96816_0_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_96816_0_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3624 [F] s_b_17_2=sym_15004_3_parameter_inst.rt (const) */
    /* execute.simd:3624 [D] s_b_17_3 = sym_96816_0_value uint32_t */
    auto s_b_17_3 = emitter.load_local(DV_sym_96816_0_value, emitter.context().types().u32());
    /* execute.simd:6131 [D] s_b_17_4 = (u64)s_b_17_3 */
    auto s_b_17_4 = emitter.zx(s_b_17_3, emitter.context().types().u64());
    /* execute.simd:6131 [D] s_b_17_5: WriteRegBank 2:s_b_17_2 = s_b_17_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_17_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_17_4);
    /* execute.simd:6132 [F] s_b_17_6 = constant u64 0 (const) */
    /* execute.simd:6132 [F] s_b_17_7: WriteRegBank 3:s_b_17_2 = s_b_17_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_17_8: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3902 [F] s_b_18_0=sym_15004_3_parameter_inst.size (const) */
    /* execute.simd:3902 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
    /* execute.simd:3902 [F] s_b_18_2 = constant u32 3 (const) */
    /* execute.simd:3902 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:3902 [F] s_b_18_4: If s_b_18_3: Jump b_19 else b_11 (const) */
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
    /* execute.simd:3904 [D] s_b_19_0 = sym_15147_0_address uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_15147_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_19_1 = Load 8 s_b_19_0 => sym_96889_0_value */
    auto s_b_19_1 = emitter.load_memory(s_b_19_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_96889_0_value, s_b_19_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_19_0, s_b_19_1, emitter.const_u8(8));
    }
    /* execute.simd:3631 [F] s_b_19_2=sym_15004_3_parameter_inst.rt (const) */
    /* execute.simd:3631 [D] s_b_19_3 = sym_96889_0_value uint64_t */
    auto s_b_19_3 = emitter.load_local(DV_sym_96889_0_value, emitter.context().types().u64());
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
    /* execute.simd:0 [F] s_b_19_7: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_2,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2733 [F] s_b_20_0=sym_15004_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_20_2: sym_96147_1__R_s_b_2_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_96147_1__R_s_b_2_5, s_b_20_1);
    /* execute.a64:2733 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_26,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3886 [D] s_b_21_0 = sym_96147_1__R_s_b_2_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_96147_1__R_s_b_2_5, emitter.context().types().u64());
    /* execute.simd:3886 [D] s_b_21_1 = sym_15049_0_rm uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_15049_0_rm, emitter.context().types().u64());
    /* execute.simd:3886 [D] s_b_21_2 = s_b_21_0+s_b_21_1 */
    auto s_b_21_2 = emitter.add(s_b_21_0, s_b_21_1);
    /* execute.simd:3886 [D] s_b_21_3: sym_15147_0_address = s_b_21_2, dominates: s_b_13_0 s_b_14_0 s_b_15_0 s_b_17_0 s_b_19_0  */
    emitter.store_local(DV_sym_15147_0_address, s_b_21_2);
    /* execute.simd:3888 [F] s_b_21_4=sym_15004_3_parameter_inst.size (const) */
    /* execute.simd:3888 [F] s_b_21_5 = (u32)s_b_21_4 (const) */
    /* execute.simd:3888 [F] s_b_21_6 = constant u32 0 (const) */
    /* execute.simd:3888 [F] s_b_21_7 = s_b_21_5==s_b_21_6 (const) */
    uint8_t s_b_21_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:3888 [F] s_b_21_8: If s_b_21_7: Jump b_10 else b_12 (const) */
    if (s_b_21_7) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_2,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2701 [F] s_b_22_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_22_1 = __builtin_get_feature */
    uint32_t s_b_22_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_22_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(s_b_22_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_22_4: If s_b_22_3: Jump b_23 else b_27 (const) */
    if (s_b_22_3) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2702 [D] s_b_23_0 = ReadReg 20 (u64) */
    auto s_b_23_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_23_1: sym_96941_1__R_s_b_45_0 = s_b_23_0, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_96941_1__R_s_b_45_0, s_b_23_0);
    /* execute.a64:2702 [F] s_b_23_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_27,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2705 [D] s_b_24_0 = ReadReg 20 (u64) */
    auto s_b_24_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_24_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_24_1: sym_96941_1__R_s_b_45_0 = s_b_24_0, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_96941_1__R_s_b_45_0, s_b_24_0);
    /* execute.a64:2705 [F] s_b_24_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_27,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2707 [D] s_b_25_0 = ReadReg 21 (u64) */
    auto s_b_25_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_25_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_25_1: sym_96941_1__R_s_b_45_0 = s_b_25_0, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_96941_1__R_s_b_45_0, s_b_25_0);
    /* execute.a64:2707 [F] s_b_25_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_23, b_24, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2731 [D] s_b_26_0 = sym_96941_1__R_s_b_45_0 uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_96941_1__R_s_b_45_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_26_1: sym_96147_1__R_s_b_2_5 = s_b_26_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_96147_1__R_s_b_2_5, s_b_26_0);
    /* execute.a64:2731 [F] s_b_26_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_22,  */
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
    /* execute.a64:2704 [F] s_b_27_6: If s_b_27_5: Jump b_24 else b_25 (const) */
    if (s_b_27_5) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_25;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldrsw(const aarch64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_107670_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_107773_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_107641_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_107851_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_108222_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_107907_1__R_s_b_8_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_108660_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_15942_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_15936_3_parameter_inst.rn (const) */
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
    /* execute.a64:983 [D] s_b_1_0 = sym_15942_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15942_0_address, emitter.context().types().u64());
    /* execute.a64:983 [F] s_b_1_1=sym_15936_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:983 [D] s_b_1_4: sym_15942_0_address = s_b_1_3, dominates: s_b_2_0 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_15942_0_address, s_b_1_3);
    /* execute.a64:983 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_6,  */
  fixed_block_b_2: 
  {
    /* execute.a64:986 [D] s_b_2_0 = sym_15942_0_address uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_15942_0_address, emitter.context().types().u64());
    /* execute.a64:986 [D] s_b_2_1: sym_107670_3_parameter_address = s_b_2_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_107670_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 4 s_b_2_0 => sym_107773_0_data32 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_107773_0_data32, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(4));
    }
    /* execute.a64:1691 [D] s_b_2_3 = sym_107773_0_data32 uint32_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_107773_0_data32, emitter.context().types().u32());
    /* execute.a64:1691 [D] s_b_2_4 = (s32)s_b_2_3 */
    auto s_b_2_4 = emitter.reinterpret(s_b_2_3, emitter.context().types().s32());
    /* execute.a64:1691 [D] s_b_2_5 = (s64)s_b_2_4 */
    auto s_b_2_5 = emitter.sx(s_b_2_4, emitter.context().types().s64());
    /* execute.a64:1691 [D] s_b_2_6 = (u64)s_b_2_5 */
    auto s_b_2_6 = emitter.reinterpret(s_b_2_5, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_2_7=sym_15936_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_2_8: sym_108660_3_parameter_value = s_b_2_6, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_108660_3_parameter_value, s_b_2_6);
    /* execute.a64:2682 [F] s_b_2_9 = (u32)s_b_2_7 (const) */
    /* execute.a64:2682 [F] s_b_2_10 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_2_11 = s_b_2_9==s_b_2_10 (const) */
    uint8_t s_b_2_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_2_12: If s_b_2_11: Jump b_7 else b_22 (const) */
    if (s_b_2_11) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_7,  */
  fixed_block_b_3: 
  {
    /* execute.a64:989 [D] s_b_3_0 = sym_15942_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_15942_0_address, emitter.context().types().u64());
    /* execute.a64:989 [F] s_b_3_1=sym_15936_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:989 [D] s_b_3_4: sym_15942_0_address = s_b_3_3, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_15942_0_address, s_b_3_3);
    /* execute.a64:989 [F] s_b_3_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_7,  */
  fixed_block_b_4: 
  {
    /* execute.a64:992 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.a64:992 [D] s_b_4_1 = sym_15942_0_address uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_15942_0_address, emitter.context().types().u64());
    /* execute.a64:992 [D] s_b_4_2: sym_107851_3_parameter_value = s_b_4_1, dominates: s_b_8_0 s_b_10_0 s_b_11_1  */
    emitter.store_local(DV_sym_107851_3_parameter_value, s_b_4_1);
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
    /* execute.a64:2733 [F] s_b_5_0=sym_15936_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_5_2: sym_107641_1__R_s_b_0_5 = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_107641_1__R_s_b_0_5, s_b_5_1);
    /* execute.a64:2733 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_17,  */
  fixed_block_b_6: 
  {
    /* execute.a64:980 [D] s_b_6_0 = sym_107641_1__R_s_b_0_5 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_107641_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:980 [D] s_b_6_1: sym_15942_0_address = s_b_6_0, dominates: s_b_1_0 s_b_2_0 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_15942_0_address, s_b_6_0);
    /* execute.a64:982 [F] s_b_6_2=sym_15936_3_parameter_inst.P (const) */
    /* execute.a64:982 [F] s_b_6_3: If s_b_6_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_2, b_22,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1723 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_7_1 = sym_107670_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_107670_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* execute.a64:988 [F] s_b_7_3=sym_15936_3_parameter_inst.P (const) */
    /* execute.a64:988 [F] s_b_7_4 = !s_b_7_3 (const) */
    uint8_t s_b_7_4 = !insn.P;
    /* execute.a64:988 [F] s_b_7_5: If s_b_7_4: Jump b_3 else b_4 (const) */
    if (s_b_7_4) 
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
    /* execute.a64:2747 [D] s_b_8_0 = sym_107851_3_parameter_value uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_107851_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_8_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_8_2 = s_b_8_0&s_b_8_1 */
    auto s_b_8_2 = emitter.bitwise_and(s_b_8_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_8_3: sym_107851_3_parameter_value = s_b_8_2, dominates: s_b_10_0 s_b_11_1  */
    emitter.store_local(DV_sym_107851_3_parameter_value, s_b_8_2);
    /* execute.a64:2747 [F] s_b_8_4: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2750 [F] s_b_9_0=sym_15936_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_10_0 = sym_107851_3_parameter_value uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_107851_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_10_1: sym_108222_3_parameter_value = s_b_10_0, dominates: s_b_18_0 s_b_19_0 s_b_20_0  */
    emitter.store_local(DV_sym_108222_3_parameter_value, s_b_10_0);
    /* execute.a64:2714 [F] s_b_10_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_10_3 = __builtin_get_feature */
    uint32_t s_b_10_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_10_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(s_b_10_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_10_6: If s_b_10_5: Jump b_18 else b_23 (const) */
    if (s_b_10_5) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2753 [F] s_b_11_0=sym_15936_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_11_1 = sym_107851_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_107851_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1);
    /* execute.a64:2753 [F] s_b_11_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11, b_18, b_19, b_20,  */
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
    /* execute.a64:2701 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_21 (const) */
    if (s_b_13_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_21;
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
    /* execute.a64:2702 [D] s_b_14_1: sym_107907_1__R_s_b_8_0 = s_b_14_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_107907_1__R_s_b_8_0, s_b_14_0);
    /* execute.a64:2702 [F] s_b_14_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_21,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2705 [D] s_b_15_0 = ReadReg 20 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_15_1: sym_107907_1__R_s_b_8_0 = s_b_15_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_107907_1__R_s_b_8_0, s_b_15_0);
    /* execute.a64:2705 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_21,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2707 [D] s_b_16_0 = ReadReg 21 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_16_1: sym_107907_1__R_s_b_8_0 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_107907_1__R_s_b_8_0, s_b_16_0);
    /* execute.a64:2707 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_14, b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2731 [D] s_b_17_0 = sym_107907_1__R_s_b_8_0 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_107907_1__R_s_b_8_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_17_1: sym_107641_1__R_s_b_0_5 = s_b_17_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_107641_1__R_s_b_0_5, s_b_17_0);
    /* execute.a64:2731 [F] s_b_17_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_10,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2715 [D] s_b_18_0 = sym_108222_3_parameter_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_108222_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_18_1: WriteReg 20 = s_b_18_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_18_0);
    /* execute.a64:2715 [F] s_b_18_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_23,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2718 [D] s_b_19_0 = sym_108222_3_parameter_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_108222_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_19_1: WriteReg 20 = s_b_19_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_19_0);
    /* execute.a64:2718 [F] s_b_19_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_23,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2720 [D] s_b_20_0 = sym_108222_3_parameter_value uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_108222_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_20_1: WriteReg 21 = s_b_20_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_20_0);
    /* execute.a64:2720 [F] s_b_20_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_13,  */
  fixed_block_b_21: 
  {
    /* execute.a64:3012 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_21_1 = __builtin_get_feature */
    uint32_t s_b_21_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_21_2 = (u8)s_b_21_1 (const) */
    /* execute.a64:2704 [F] s_b_21_3 = (u32)s_b_21_2 (const) */
    /* execute.a64:2704 [F] s_b_21_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_21_5 = s_b_21_3==s_b_21_4 (const) */
    uint8_t s_b_21_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_21_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_21_6: If s_b_21_5: Jump b_15 else b_16 (const) */
    if (s_b_21_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_2,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2684 [F] s_b_22_0=sym_15936_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_22_1 = sym_108660_3_parameter_value uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_108660_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_22_2: WriteRegBank 0:s_b_22_0 = s_b_22_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_22_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_22_1);
    /* execute.a64:0 [F] s_b_22_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_10,  */
  fixed_block_b_23: 
  {
    /* execute.a64:3012 [F] s_b_23_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_23_1 = __builtin_get_feature */
    uint32_t s_b_23_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_23_2 = (u8)s_b_23_1 (const) */
    /* execute.a64:2717 [F] s_b_23_3 = (u32)s_b_23_2 (const) */
    /* execute.a64:2717 [F] s_b_23_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_23_5 = s_b_23_3==s_b_23_4 (const) */
    uint8_t s_b_23_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_23_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_23_6: If s_b_23_5: Jump b_19 else b_20 (const) */
    if (s_b_23_5) 
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldurb(const aarch64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_109481_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109677_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109699_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109765_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109597_1__R_s_b_13_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16088_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_16074_3_parameter_inst.rn (const) */
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
    /* execute.a64:1309 [D] s_b_1_0 = sym_16088_0_value uint8_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16088_0_value, emitter.context().types().u8());
    /* execute.a64:1309 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_2=sym_16074_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_3 = (u32)s_b_1_1 */
    auto s_b_1_3 = emitter.truncate(s_b_1_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_5: sym_109677_3_parameter_value = s_b_1_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_109677_3_parameter_value, s_b_1_4);
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
    /* execute.a64:1310 [F] s_b_3_0=sym_16074_3_parameter_inst.opc (const) */
    /* execute.a64:1310 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1310 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1310 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1310 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1311 [D] s_b_4_0 = sym_16088_0_value uint8_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_16088_0_value, emitter.context().types().u8());
    /* execute.a64:1311 [D] s_b_4_1 = (s8)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s8());
    /* execute.a64:1311 [D] s_b_4_2 = (s64)s_b_4_1 */
    auto s_b_4_2 = emitter.sx(s_b_4_1, emitter.context().types().s64());
    /* execute.a64:1311 [D] s_b_4_3 = (u64)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_4_4=sym_16074_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_4_5: sym_109699_3_parameter_value = s_b_4_3, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_109699_3_parameter_value, s_b_4_3);
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
    /* execute.a64:1312 [F] s_b_5_0=sym_16074_3_parameter_inst.opc (const) */
    /* execute.a64:1312 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1312 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:1312 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:1312 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1313 [D] s_b_6_0 = sym_16088_0_value uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_16088_0_value, emitter.context().types().u8());
    /* execute.a64:1313 [D] s_b_6_1 = (s8)s_b_6_0 */
    auto s_b_6_1 = emitter.reinterpret(s_b_6_0, emitter.context().types().s8());
    /* execute.a64:1313 [D] s_b_6_2 = (s64)s_b_6_1 */
    auto s_b_6_2 = emitter.sx(s_b_6_1, emitter.context().types().s64());
    /* execute.a64:1313 [D] s_b_6_3 = (u64)s_b_6_2 */
    auto s_b_6_3 = emitter.reinterpret(s_b_6_2, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_4=sym_16074_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_6_5 = (u32)s_b_6_3 */
    auto s_b_6_5 = emitter.truncate(s_b_6_3, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_7: sym_109765_3_parameter_value = s_b_6_6, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_109765_3_parameter_value, s_b_6_6);
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
    /* execute.a64:1315 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1315 [F] s_b_7_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2733 [F] s_b_8_0=sym_16074_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_8_2: sym_109481_1__R_s_b_0_5 = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_109481_1__R_s_b_0_5, s_b_8_1);
    /* execute.a64:2733 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_14,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1302 [D] s_b_9_0 = sym_109481_1__R_s_b_0_5 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_109481_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1303 [F] s_b_9_1=sym_16074_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_9_2 = (u64)s_b_9_1 (const) */
    /* ???:4294967295 [D] s_b_9_3 = s_b_9_0+s_b_9_2 */
    auto s_b_9_3 = emitter.add(s_b_9_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* ???:4294967295 [D] s_b_9_4 = Load 1 s_b_9_3 => sym_16088_0_value */
    auto s_b_9_4 = emitter.load_memory(s_b_9_3, emitter.context().types().u8());
    emitter.store_local(DV_sym_16088_0_value, s_b_9_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_3, s_b_9_4, emitter.const_u8(1));
    }
    /* execute.a64:1308 [F] s_b_9_5=sym_16074_3_parameter_inst.opc (const) */
    /* execute.a64:1308 [F] s_b_9_6 = (u32)s_b_9_5 (const) */
    /* execute.a64:1308 [F] s_b_9_7 = constant u32 1 (const) */
    /* execute.a64:1308 [F] s_b_9_8 = s_b_9_6==s_b_9_7 (const) */
    uint8_t s_b_9_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:1308 [F] s_b_9_9: If s_b_9_8: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2702 [D] s_b_11_1: sym_109597_1__R_s_b_13_0 = s_b_11_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109597_1__R_s_b_13_0, s_b_11_0);
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
    /* execute.a64:2705 [D] s_b_12_1: sym_109597_1__R_s_b_13_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109597_1__R_s_b_13_0, s_b_12_0);
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
    /* execute.a64:2707 [D] s_b_13_1: sym_109597_1__R_s_b_13_0 = s_b_13_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_109597_1__R_s_b_13_0, s_b_13_0);
    /* execute.a64:2707 [F] s_b_13_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_11, b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2731 [D] s_b_14_0 = sym_109597_1__R_s_b_13_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_109597_1__R_s_b_13_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_14_1: sym_109481_1__R_s_b_0_5 = s_b_14_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_109481_1__R_s_b_0_5, s_b_14_0);
    /* execute.a64:2731 [F] s_b_14_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2684 [F] s_b_15_0=sym_16074_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_109677_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_109677_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_16_0=sym_16074_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_109699_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_109699_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_17_0=sym_16074_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_17_1 = sym_109765_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_109765_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_lsrv(const aarch64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_120443_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120320_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120345_1__R_s_b_2_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120473_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120495_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16449_0_amount = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2293 [F] s_b_0_0=sym_16444_3_parameter_inst.sf (const) */
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
    /* execute.a64:2295 [D] s_b_1_0 = sym_16449_0_amount uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16449_0_amount, emitter.context().types().u64());
    /* execute.a64:2295 [F] s_b_1_1 = constant u64 3f (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0&s_b_1_1 */
    auto s_b_1_2 = emitter.bitwise_and(s_b_1_0, emitter.const_u64((uint64_t)63ULL));
    /* execute.a64:2295 [D] s_b_1_3: sym_16449_0_amount = s_b_1_2, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_16449_0_amount, s_b_1_2);
    /* execute.a64:2295 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2300 [F] s_b_2_0=sym_16444_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_2_1: If s_b_2_0: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2297 [D] s_b_3_0 = sym_16449_0_amount uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_16449_0_amount, emitter.context().types().u64());
    /* execute.a64:2297 [F] s_b_3_1 = constant u64 1f (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0&s_b_3_1 */
    auto s_b_3_2 = emitter.bitwise_and(s_b_3_0, emitter.const_u64((uint64_t)31ULL));
    /* execute.a64:2297 [D] s_b_3_3: sym_16449_0_amount = s_b_3_2, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_16449_0_amount, s_b_3_2);
    /* execute.a64:2297 [F] s_b_3_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2657 [F] s_b_4_0=sym_16444_3_parameter_inst.rm (const) */
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
    /* execute.a64:2657 [D] s_b_4_7: sym_120320_1__R_s_b_0_4 = s_b_4_6, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_120320_1__R_s_b_0_4, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_16444_3_parameter_inst.rm (const) */
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
    /* execute.a64:2659 [D] s_b_5_8: sym_120320_1__R_s_b_0_4 = s_b_5_7, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_120320_1__R_s_b_0_4, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2293 [D] s_b_6_0 = sym_120320_1__R_s_b_0_4 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_120320_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2293 [D] s_b_6_1: sym_16449_0_amount = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_16449_0_amount, s_b_6_0);
    /* execute.a64:2294 [F] s_b_6_2=sym_16444_3_parameter_inst.sf (const) */
    /* execute.a64:2294 [F] s_b_6_3: If s_b_6_2: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2657 [F] s_b_7_0=sym_16444_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2651 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_7_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_7_5 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_7_6: Select s_b_7_3 ? s_b_7_4 : s_b_7_5 */
    captive::arch::dbt::el::Value *s_b_7_6;
    s_b_7_6 = (s_b_7_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_7_5);
    /* execute.a64:2657 [D] s_b_7_7: sym_120345_1__R_s_b_2_6 = s_b_7_6, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_120345_1__R_s_b_2_6, s_b_7_6);
    /* execute.a64:2657 [F] s_b_7_8: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2659 [F] s_b_8_0=sym_16444_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2646 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_8_5 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    captive::arch::dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2659 [D] s_b_8_7 = (u64)s_b_8_6 */
    auto s_b_8_7 = emitter.zx(s_b_8_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_8_8: sym_120345_1__R_s_b_2_6 = s_b_8_7, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_120345_1__R_s_b_2_6, s_b_8_7);
    /* execute.a64:2659 [F] s_b_8_9: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [F] s_b_9_0=sym_16444_3_parameter_inst.sf (const) */
    /* execute.a64:2300 [D] s_b_9_1 = sym_120345_1__R_s_b_2_6 uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_120345_1__R_s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2300 [D] s_b_9_2 = sym_16449_0_amount uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_16449_0_amount, emitter.context().types().u64());
    /* execute.a64:2300 [D] s_b_9_3 = s_b_9_1>>s_b_9_2 */
    auto s_b_9_3 = emitter.shr(s_b_9_1, s_b_9_2);
    /* execute.a64:2300 [D] s_b_9_4: sym_120443_3_parameter_value = s_b_9_3, dominates: s_b_10_1 s_b_11_1  */
    emitter.store_local(DV_sym_120443_3_parameter_value, s_b_9_3);
    /* execute.a64:2690 [F] s_b_9_5: If s_b_9_0: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2691 [F] s_b_10_0=sym_16444_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_10_1 = sym_120443_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_120443_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_10_2: sym_120473_3_parameter_value = s_b_10_1, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_120473_3_parameter_value, s_b_10_1);
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
    /* execute.a64:2693 [F] s_b_11_0=sym_16444_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_11_1 = sym_120443_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_120443_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_2 = (u32)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_4: sym_120495_3_parameter_value = s_b_11_3, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_120495_3_parameter_value, s_b_11_3);
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
    /* execute.a64:2684 [F] s_b_13_0=sym_16444_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_13_1 = sym_120473_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_120473_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_14_0=sym_16444_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_120495_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_120495_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_mrs(const aarch64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_123068_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_16830_0_value;
  auto DV_sym_16830_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:436 [F] s_b_0_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:436 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:436 [F] s_b_0_2 = constant u32 2 (const) */
    /* execute.a64:436 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)2ULL));
    /* execute.a64:436 [F] s_b_0_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:436 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:436 [F] s_b_0_6 = constant u32 0 (const) */
    /* execute.a64:436 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* execute.a64:436 [F] s_b_0_8=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:436 [F] s_b_0_9 = (u32)s_b_0_8 (const) */
    /* execute.a64:436 [F] s_b_0_10 = constant u32 4 (const) */
    /* execute.a64:436 [F] s_b_0_11 = s_b_0_9==s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_0_12 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_13 = s_b_0_7!=s_b_0_12 (const) */
    uint8_t s_b_0_13 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_14 = s_b_0_11!=s_b_0_12 (const) */
    uint8_t s_b_0_14 = ((uint8_t)(s_b_0_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_15 = s_b_0_13|s_b_0_14 (const) */
    uint8_t s_b_0_15 = ((uint8_t)(s_b_0_13 | s_b_0_14));
    /* execute.a64:436 [F] s_b_0_16=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:436 [F] s_b_0_17 = (u32)s_b_0_16 (const) */
    /* execute.a64:436 [F] s_b_0_18 = constant u32 6 (const) */
    /* execute.a64:436 [F] s_b_0_19 = s_b_0_17==s_b_0_18 (const) */
    uint8_t s_b_0_19 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_0_20 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_21 = s_b_0_15!=s_b_0_20 (const) */
    uint8_t s_b_0_21 = ((uint8_t)(s_b_0_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_22 = s_b_0_19!=s_b_0_20 (const) */
    uint8_t s_b_0_22 = ((uint8_t)(s_b_0_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_23 = s_b_0_21|s_b_0_22 (const) */
    uint8_t s_b_0_23 = ((uint8_t)(s_b_0_21 | s_b_0_22));
    /* ???:4294967295 [F] s_b_0_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_25 = s_b_0_3!=s_b_0_24 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_26 = s_b_0_23!=s_b_0_24 (const) */
    uint8_t s_b_0_26 = ((uint8_t)(s_b_0_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_27 = s_b_0_25&s_b_0_26 (const) */
    uint8_t s_b_0_27 = ((uint8_t)(s_b_0_25 & s_b_0_26));
    /* execute.a64:436 [F] s_b_0_28=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:436 [F] s_b_0_29 = (u32)s_b_0_28 (const) */
    /* execute.a64:436 [F] s_b_0_30 = constant u32 2 (const) */
    /* execute.a64:436 [F] s_b_0_31 = s_b_0_29==s_b_0_30 (const) */
    uint8_t s_b_0_31 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_0_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_33 = s_b_0_27!=s_b_0_32 (const) */
    uint8_t s_b_0_33 = ((uint8_t)(s_b_0_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_34 = s_b_0_31!=s_b_0_32 (const) */
    uint8_t s_b_0_34 = ((uint8_t)(s_b_0_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_35 = s_b_0_33&s_b_0_34 (const) */
    uint8_t s_b_0_35 = ((uint8_t)(s_b_0_33 & s_b_0_34));
    /* execute.a64:436 [F] s_b_0_36=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:436 [F] s_b_0_37 = (u32)s_b_0_36 (const) */
    /* execute.a64:436 [F] s_b_0_38 = constant u32 0 (const) */
    /* execute.a64:436 [F] s_b_0_39 = s_b_0_37==s_b_0_38 (const) */
    uint8_t s_b_0_39 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_0_40 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_41 = s_b_0_35!=s_b_0_40 (const) */
    uint8_t s_b_0_41 = ((uint8_t)(s_b_0_35 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_42 = s_b_0_39!=s_b_0_40 (const) */
    uint8_t s_b_0_42 = ((uint8_t)(s_b_0_39 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_43 = s_b_0_41&s_b_0_42 (const) */
    uint8_t s_b_0_43 = ((uint8_t)(s_b_0_41 & s_b_0_42));
    /* execute.a64:436 [F] s_b_0_44=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:436 [F] s_b_0_45 = (u32)s_b_0_44 (const) */
    /* execute.a64:436 [F] s_b_0_46 = constant u32 0 (const) */
    /* execute.a64:436 [F] s_b_0_47 = s_b_0_45==s_b_0_46 (const) */
    uint8_t s_b_0_47 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_0_48 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_49 = s_b_0_43!=s_b_0_48 (const) */
    uint8_t s_b_0_49 = ((uint8_t)(s_b_0_43 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_50 = s_b_0_47!=s_b_0_48 (const) */
    uint8_t s_b_0_50 = ((uint8_t)(s_b_0_47 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_51 = s_b_0_49&s_b_0_50 (const) */
    uint8_t s_b_0_51 = ((uint8_t)(s_b_0_49 & s_b_0_50));
    /* execute.a64:436 [F] s_b_0_52: If s_b_0_51: Jump b_1 else b_3 (const) */
    if (s_b_0_51) 
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
    /* execute.a64:437 [D] s_b_1_0 = ReadReg 10 (u64) */
    auto s_b_1_0 = emitter.load_register(emitter.const_u32(1312), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1312), s_b_1_0, emitter.const_u8(8));
    }
    /* execute.a64:437 [D] s_b_1_1: sym_16830_0_value = s_b_1_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_1_0);
    /* execute.a64:437 [F] s_b_1_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_9, b_11, b_13, b_15, b_17, b_19, b_21, b_23, b_25, b_27, b_29, b_31, b_32, b_34,  */
  fixed_block_b_2: 
  {
    /* execute.a64:474 [D] s_b_2_0 = sym_16830_0_value uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_16830_0_value, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_2_1=sym_16764_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_2_2: sym_123068_3_parameter_value = s_b_2_0, dominates: s_b_35_1  */
    emitter.store_local(DV_sym_123068_3_parameter_value, s_b_2_0);
    /* execute.a64:2682 [F] s_b_2_3 = (u32)s_b_2_1 (const) */
    /* execute.a64:2682 [F] s_b_2_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_2_5 = s_b_2_3==s_b_2_4 (const) */
    uint8_t s_b_2_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_2_6: If s_b_2_5: Jump b_33 else b_35 (const) */
    if (s_b_2_5) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:438 [F] s_b_3_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:438 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:438 [F] s_b_3_2 = constant u32 3 (const) */
    /* execute.a64:438 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:438 [F] s_b_3_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:438 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:438 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.a64:438 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:438 [F] s_b_3_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:438 [F] s_b_3_13 = (u32)s_b_3_12 (const) */
    /* execute.a64:438 [F] s_b_3_14 = constant u32 2 (const) */
    /* execute.a64:438 [F] s_b_3_15 = s_b_3_13==s_b_3_14 (const) */
    uint8_t s_b_3_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_3_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_17 = s_b_3_11!=s_b_3_16 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(s_b_3_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_18 = s_b_3_15!=s_b_3_16 (const) */
    uint8_t s_b_3_18 = ((uint8_t)(s_b_3_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_19 = s_b_3_17&s_b_3_18 (const) */
    uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 & s_b_3_18));
    /* execute.a64:438 [F] s_b_3_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:438 [F] s_b_3_21 = (u32)s_b_3_20 (const) */
    /* execute.a64:438 [F] s_b_3_22 = constant u32 0 (const) */
    /* execute.a64:438 [F] s_b_3_23 = s_b_3_21==s_b_3_22 (const) */
    uint8_t s_b_3_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_25 = s_b_3_19!=s_b_3_24 (const) */
    uint8_t s_b_3_25 = ((uint8_t)(s_b_3_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_26 = s_b_3_23!=s_b_3_24 (const) */
    uint8_t s_b_3_26 = ((uint8_t)(s_b_3_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_27 = s_b_3_25&s_b_3_26 (const) */
    uint8_t s_b_3_27 = ((uint8_t)(s_b_3_25 & s_b_3_26));
    /* execute.a64:438 [F] s_b_3_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:438 [F] s_b_3_29 = (u32)s_b_3_28 (const) */
    /* execute.a64:438 [F] s_b_3_30 = constant u32 1 (const) */
    /* execute.a64:438 [F] s_b_3_31 = s_b_3_29==s_b_3_30 (const) */
    uint8_t s_b_3_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_3_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_33 = s_b_3_27!=s_b_3_32 (const) */
    uint8_t s_b_3_33 = ((uint8_t)(s_b_3_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_34 = s_b_3_31!=s_b_3_32 (const) */
    uint8_t s_b_3_34 = ((uint8_t)(s_b_3_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_35 = s_b_3_33&s_b_3_34 (const) */
    uint8_t s_b_3_35 = ((uint8_t)(s_b_3_33 & s_b_3_34));
    /* execute.a64:438 [F] s_b_3_36: If s_b_3_35: Jump b_4 else b_5 (const) */
    if (s_b_3_35) 
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
    /* execute.a64:439 [D] s_b_4_0 = ReadReg 11 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1320), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1320), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:439 [D] s_b_4_1: sym_16830_0_value = s_b_4_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_4_0);
    /* execute.a64:439 [F] s_b_4_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:440 [F] s_b_5_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:440 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:440 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:440 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:440 [F] s_b_5_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:440 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:440 [F] s_b_5_6 = constant u32 0 (const) */
    /* execute.a64:440 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:440 [F] s_b_5_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:440 [F] s_b_5_13 = (u32)s_b_5_12 (const) */
    /* execute.a64:440 [F] s_b_5_14 = constant u32 4 (const) */
    /* execute.a64:440 [F] s_b_5_15 = s_b_5_13==s_b_5_14 (const) */
    uint8_t s_b_5_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_5_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_17 = s_b_5_11!=s_b_5_16 (const) */
    uint8_t s_b_5_17 = ((uint8_t)(s_b_5_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_18 = s_b_5_15!=s_b_5_16 (const) */
    uint8_t s_b_5_18 = ((uint8_t)(s_b_5_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_19 = s_b_5_17&s_b_5_18 (const) */
    uint8_t s_b_5_19 = ((uint8_t)(s_b_5_17 & s_b_5_18));
    /* execute.a64:440 [F] s_b_5_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:440 [F] s_b_5_21 = (u32)s_b_5_20 (const) */
    /* execute.a64:440 [F] s_b_5_22 = constant u32 2 (const) */
    /* execute.a64:440 [F] s_b_5_23 = s_b_5_21==s_b_5_22 (const) */
    uint8_t s_b_5_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_5_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_25 = s_b_5_19!=s_b_5_24 (const) */
    uint8_t s_b_5_25 = ((uint8_t)(s_b_5_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_26 = s_b_5_23!=s_b_5_24 (const) */
    uint8_t s_b_5_26 = ((uint8_t)(s_b_5_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_27 = s_b_5_25&s_b_5_26 (const) */
    uint8_t s_b_5_27 = ((uint8_t)(s_b_5_25 & s_b_5_26));
    /* execute.a64:440 [F] s_b_5_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:440 [F] s_b_5_29 = (u32)s_b_5_28 (const) */
    /* execute.a64:440 [F] s_b_5_30 = constant u32 0 (const) */
    /* execute.a64:440 [F] s_b_5_31 = s_b_5_29==s_b_5_30 (const) */
    uint8_t s_b_5_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_33 = s_b_5_27!=s_b_5_32 (const) */
    uint8_t s_b_5_33 = ((uint8_t)(s_b_5_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_34 = s_b_5_31!=s_b_5_32 (const) */
    uint8_t s_b_5_34 = ((uint8_t)(s_b_5_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_35 = s_b_5_33&s_b_5_34 (const) */
    uint8_t s_b_5_35 = ((uint8_t)(s_b_5_33 & s_b_5_34));
    /* execute.a64:440 [F] s_b_5_36: If s_b_5_35: Jump b_6 else b_7 (const) */
    if (s_b_5_35) 
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
    /* execute.a64:441 [F] s_b_6_0 = constant u32 1 (const) */
    /* execute.a64:441 [F] s_b_6_1 = __builtin_get_feature */
    uint32_t s_b_6_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:441 [F] s_b_6_2 = (u64)s_b_6_1 (const) */
    /* execute.a64:441 [F] s_b_6_3: sym_16830_0_value = s_b_6_2 (const), dominates: s_b_2_0  */
    CV_sym_16830_0_value = ((uint64_t)s_b_6_1);
    emitter.store_local(DV_sym_16830_0_value, emitter.const_u64(((uint64_t)s_b_6_1)));
    /* execute.a64:441 [F] s_b_6_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:442 [F] s_b_7_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:442 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:442 [F] s_b_7_2 = constant u32 3 (const) */
    /* execute.a64:442 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:442 [F] s_b_7_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:442 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:442 [F] s_b_7_6 = constant u32 0 (const) */
    /* execute.a64:442 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:442 [F] s_b_7_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:442 [F] s_b_7_13 = (u32)s_b_7_12 (const) */
    /* execute.a64:442 [F] s_b_7_14 = constant u32 4 (const) */
    /* execute.a64:442 [F] s_b_7_15 = s_b_7_13==s_b_7_14 (const) */
    uint8_t s_b_7_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_7_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_17 = s_b_7_11!=s_b_7_16 (const) */
    uint8_t s_b_7_17 = ((uint8_t)(s_b_7_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_18 = s_b_7_15!=s_b_7_16 (const) */
    uint8_t s_b_7_18 = ((uint8_t)(s_b_7_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_19 = s_b_7_17&s_b_7_18 (const) */
    uint8_t s_b_7_19 = ((uint8_t)(s_b_7_17 & s_b_7_18));
    /* execute.a64:442 [F] s_b_7_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:442 [F] s_b_7_21 = (u32)s_b_7_20 (const) */
    /* execute.a64:442 [F] s_b_7_22 = constant u32 2 (const) */
    /* execute.a64:442 [F] s_b_7_23 = s_b_7_21==s_b_7_22 (const) */
    uint8_t s_b_7_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_7_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_25 = s_b_7_19!=s_b_7_24 (const) */
    uint8_t s_b_7_25 = ((uint8_t)(s_b_7_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_26 = s_b_7_23!=s_b_7_24 (const) */
    uint8_t s_b_7_26 = ((uint8_t)(s_b_7_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_27 = s_b_7_25&s_b_7_26 (const) */
    uint8_t s_b_7_27 = ((uint8_t)(s_b_7_25 & s_b_7_26));
    /* execute.a64:442 [F] s_b_7_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:442 [F] s_b_7_29 = (u32)s_b_7_28 (const) */
    /* execute.a64:442 [F] s_b_7_30 = constant u32 2 (const) */
    /* execute.a64:442 [F] s_b_7_31 = s_b_7_29==s_b_7_30 (const) */
    uint8_t s_b_7_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_7_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_33 = s_b_7_27!=s_b_7_32 (const) */
    uint8_t s_b_7_33 = ((uint8_t)(s_b_7_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_34 = s_b_7_31!=s_b_7_32 (const) */
    uint8_t s_b_7_34 = ((uint8_t)(s_b_7_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_35 = s_b_7_33&s_b_7_34 (const) */
    uint8_t s_b_7_35 = ((uint8_t)(s_b_7_33 & s_b_7_34));
    /* execute.a64:442 [F] s_b_7_36: If s_b_7_35: Jump b_34 else b_8 (const) */
    if (s_b_7_35) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:444 [F] s_b_8_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:444 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:444 [F] s_b_8_2 = constant u32 3 (const) */
    /* execute.a64:444 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:444 [F] s_b_8_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:444 [F] s_b_8_5 = (u32)s_b_8_4 (const) */
    /* execute.a64:444 [F] s_b_8_6 = constant u32 0 (const) */
    /* execute.a64:444 [F] s_b_8_7 = s_b_8_5==s_b_8_6 (const) */
    uint8_t s_b_8_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_8_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_8_9 = s_b_8_3!=s_b_8_8 (const) */
    uint8_t s_b_8_9 = ((uint8_t)(s_b_8_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_8_10 = s_b_8_7!=s_b_8_8 (const) */
    uint8_t s_b_8_10 = ((uint8_t)(s_b_8_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_8_11 = s_b_8_9&s_b_8_10 (const) */
    uint8_t s_b_8_11 = ((uint8_t)(s_b_8_9 & s_b_8_10));
    /* execute.a64:444 [F] s_b_8_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:444 [F] s_b_8_13 = (u32)s_b_8_12 (const) */
    /* execute.a64:444 [F] s_b_8_14 = constant u32 4 (const) */
    /* execute.a64:444 [F] s_b_8_15 = s_b_8_13==s_b_8_14 (const) */
    uint8_t s_b_8_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_8_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_8_17 = s_b_8_11!=s_b_8_16 (const) */
    uint8_t s_b_8_17 = ((uint8_t)(s_b_8_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_8_18 = s_b_8_15!=s_b_8_16 (const) */
    uint8_t s_b_8_18 = ((uint8_t)(s_b_8_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_8_19 = s_b_8_17&s_b_8_18 (const) */
    uint8_t s_b_8_19 = ((uint8_t)(s_b_8_17 & s_b_8_18));
    /* execute.a64:444 [F] s_b_8_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:444 [F] s_b_8_21 = (u32)s_b_8_20 (const) */
    /* execute.a64:444 [F] s_b_8_22 = constant u32 1 (const) */
    /* execute.a64:444 [F] s_b_8_23 = s_b_8_21==s_b_8_22 (const) */
    uint8_t s_b_8_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_8_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_8_25 = s_b_8_19!=s_b_8_24 (const) */
    uint8_t s_b_8_25 = ((uint8_t)(s_b_8_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_8_26 = s_b_8_23!=s_b_8_24 (const) */
    uint8_t s_b_8_26 = ((uint8_t)(s_b_8_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_8_27 = s_b_8_25&s_b_8_26 (const) */
    uint8_t s_b_8_27 = ((uint8_t)(s_b_8_25 & s_b_8_26));
    /* execute.a64:444 [F] s_b_8_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:444 [F] s_b_8_29 = (u32)s_b_8_28 (const) */
    /* execute.a64:444 [F] s_b_8_30 = constant u32 0 (const) */
    /* execute.a64:444 [F] s_b_8_31 = s_b_8_29==s_b_8_30 (const) */
    uint8_t s_b_8_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_8_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_8_33 = s_b_8_27!=s_b_8_32 (const) */
    uint8_t s_b_8_33 = ((uint8_t)(s_b_8_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_8_34 = s_b_8_31!=s_b_8_32 (const) */
    uint8_t s_b_8_34 = ((uint8_t)(s_b_8_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_8_35 = s_b_8_33&s_b_8_34 (const) */
    uint8_t s_b_8_35 = ((uint8_t)(s_b_8_33 & s_b_8_34));
    /* execute.a64:444 [F] s_b_8_36: If s_b_8_35: Jump b_9 else b_10 (const) */
    if (s_b_8_35) 
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
    /* execute.a64:445 [D] s_b_9_0 = ReadReg 20 (u64) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_9_0, emitter.const_u8(8));
    }
    /* execute.a64:445 [D] s_b_9_1: sym_16830_0_value = s_b_9_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_9_0);
    /* execute.a64:445 [F] s_b_9_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:446 [F] s_b_10_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:446 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:446 [F] s_b_10_2 = constant u32 3 (const) */
    /* execute.a64:446 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:446 [F] s_b_10_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:446 [F] s_b_10_5 = (u32)s_b_10_4 (const) */
    /* execute.a64:446 [F] s_b_10_6 = constant u32 4 (const) */
    /* execute.a64:446 [F] s_b_10_7 = s_b_10_5==s_b_10_6 (const) */
    uint8_t s_b_10_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_10_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_10_9 = s_b_10_3!=s_b_10_8 (const) */
    uint8_t s_b_10_9 = ((uint8_t)(s_b_10_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_10_10 = s_b_10_7!=s_b_10_8 (const) */
    uint8_t s_b_10_10 = ((uint8_t)(s_b_10_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_10_11 = s_b_10_9&s_b_10_10 (const) */
    uint8_t s_b_10_11 = ((uint8_t)(s_b_10_9 & s_b_10_10));
    /* execute.a64:446 [F] s_b_10_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:446 [F] s_b_10_13 = (u32)s_b_10_12 (const) */
    /* execute.a64:446 [F] s_b_10_14 = constant u32 4 (const) */
    /* execute.a64:446 [F] s_b_10_15 = s_b_10_13==s_b_10_14 (const) */
    uint8_t s_b_10_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_10_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_10_17 = s_b_10_11!=s_b_10_16 (const) */
    uint8_t s_b_10_17 = ((uint8_t)(s_b_10_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_10_18 = s_b_10_15!=s_b_10_16 (const) */
    uint8_t s_b_10_18 = ((uint8_t)(s_b_10_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_10_19 = s_b_10_17&s_b_10_18 (const) */
    uint8_t s_b_10_19 = ((uint8_t)(s_b_10_17 & s_b_10_18));
    /* execute.a64:446 [F] s_b_10_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:446 [F] s_b_10_21 = (u32)s_b_10_20 (const) */
    /* execute.a64:446 [F] s_b_10_22 = constant u32 1 (const) */
    /* execute.a64:446 [F] s_b_10_23 = s_b_10_21==s_b_10_22 (const) */
    uint8_t s_b_10_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_10_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_10_25 = s_b_10_19!=s_b_10_24 (const) */
    uint8_t s_b_10_25 = ((uint8_t)(s_b_10_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_10_26 = s_b_10_23!=s_b_10_24 (const) */
    uint8_t s_b_10_26 = ((uint8_t)(s_b_10_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_10_27 = s_b_10_25&s_b_10_26 (const) */
    uint8_t s_b_10_27 = ((uint8_t)(s_b_10_25 & s_b_10_26));
    /* execute.a64:446 [F] s_b_10_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:446 [F] s_b_10_29 = (u32)s_b_10_28 (const) */
    /* execute.a64:446 [F] s_b_10_30 = constant u32 0 (const) */
    /* execute.a64:446 [F] s_b_10_31 = s_b_10_29==s_b_10_30 (const) */
    uint8_t s_b_10_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_10_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_10_33 = s_b_10_27!=s_b_10_32 (const) */
    uint8_t s_b_10_33 = ((uint8_t)(s_b_10_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_10_34 = s_b_10_31!=s_b_10_32 (const) */
    uint8_t s_b_10_34 = ((uint8_t)(s_b_10_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_10_35 = s_b_10_33&s_b_10_34 (const) */
    uint8_t s_b_10_35 = ((uint8_t)(s_b_10_33 & s_b_10_34));
    /* execute.a64:446 [F] s_b_10_36: If s_b_10_35: Jump b_11 else b_12 (const) */
    if (s_b_10_35) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:447 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:447 [D] s_b_11_1: sym_16830_0_value = s_b_11_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_11_0);
    /* execute.a64:447 [F] s_b_11_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_10,  */
  fixed_block_b_12: 
  {
    /* execute.a64:448 [F] s_b_12_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:448 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.a64:448 [F] s_b_12_2 = constant u32 3 (const) */
    /* execute.a64:448 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:448 [F] s_b_12_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:448 [F] s_b_12_5 = (u32)s_b_12_4 (const) */
    /* execute.a64:448 [F] s_b_12_6 = constant u32 0 (const) */
    /* execute.a64:448 [F] s_b_12_7 = s_b_12_5==s_b_12_6 (const) */
    uint8_t s_b_12_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_12_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_12_9 = s_b_12_3!=s_b_12_8 (const) */
    uint8_t s_b_12_9 = ((uint8_t)(s_b_12_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_12_10 = s_b_12_7!=s_b_12_8 (const) */
    uint8_t s_b_12_10 = ((uint8_t)(s_b_12_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_12_11 = s_b_12_9&s_b_12_10 (const) */
    uint8_t s_b_12_11 = ((uint8_t)(s_b_12_9 & s_b_12_10));
    /* execute.a64:448 [F] s_b_12_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:448 [F] s_b_12_13 = (u32)s_b_12_12 (const) */
    /* execute.a64:448 [F] s_b_12_14 = constant u32 4 (const) */
    /* execute.a64:448 [F] s_b_12_15 = s_b_12_13==s_b_12_14 (const) */
    uint8_t s_b_12_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_12_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_12_17 = s_b_12_11!=s_b_12_16 (const) */
    uint8_t s_b_12_17 = ((uint8_t)(s_b_12_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_12_18 = s_b_12_15!=s_b_12_16 (const) */
    uint8_t s_b_12_18 = ((uint8_t)(s_b_12_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_12_19 = s_b_12_17&s_b_12_18 (const) */
    uint8_t s_b_12_19 = ((uint8_t)(s_b_12_17 & s_b_12_18));
    /* execute.a64:448 [F] s_b_12_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:448 [F] s_b_12_21 = (u32)s_b_12_20 (const) */
    /* execute.a64:448 [F] s_b_12_22 = constant u32 0 (const) */
    /* execute.a64:448 [F] s_b_12_23 = s_b_12_21==s_b_12_22 (const) */
    uint8_t s_b_12_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_12_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_12_25 = s_b_12_19!=s_b_12_24 (const) */
    uint8_t s_b_12_25 = ((uint8_t)(s_b_12_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_12_26 = s_b_12_23!=s_b_12_24 (const) */
    uint8_t s_b_12_26 = ((uint8_t)(s_b_12_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_12_27 = s_b_12_25&s_b_12_26 (const) */
    uint8_t s_b_12_27 = ((uint8_t)(s_b_12_25 & s_b_12_26));
    /* execute.a64:448 [F] s_b_12_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:448 [F] s_b_12_29 = (u32)s_b_12_28 (const) */
    /* execute.a64:448 [F] s_b_12_30 = constant u32 0 (const) */
    /* execute.a64:448 [F] s_b_12_31 = s_b_12_29==s_b_12_30 (const) */
    uint8_t s_b_12_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_12_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_12_33 = s_b_12_27!=s_b_12_32 (const) */
    uint8_t s_b_12_33 = ((uint8_t)(s_b_12_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_12_34 = s_b_12_31!=s_b_12_32 (const) */
    uint8_t s_b_12_34 = ((uint8_t)(s_b_12_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_12_35 = s_b_12_33&s_b_12_34 (const) */
    uint8_t s_b_12_35 = ((uint8_t)(s_b_12_33 & s_b_12_34));
    /* execute.a64:448 [F] s_b_12_36: If s_b_12_35: Jump b_13 else b_14 (const) */
    if (s_b_12_35) 
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
    /* execute.a64:449 [D] s_b_13_0 = ReadReg 17 (u32) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1384), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1384), s_b_13_0, emitter.const_u8(4));
    }
    /* execute.a64:449 [D] s_b_13_1 = (u64)s_b_13_0 */
    auto s_b_13_1 = emitter.zx(s_b_13_0, emitter.context().types().u64());
    /* execute.a64:449 [D] s_b_13_2: sym_16830_0_value = s_b_13_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_13_1);
    /* execute.a64:449 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:450 [F] s_b_14_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:450 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
    /* execute.a64:450 [F] s_b_14_2 = constant u32 3 (const) */
    /* execute.a64:450 [F] s_b_14_3 = s_b_14_1==s_b_14_2 (const) */
    uint8_t s_b_14_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:450 [F] s_b_14_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:450 [F] s_b_14_5 = (u32)s_b_14_4 (const) */
    /* execute.a64:450 [F] s_b_14_6 = constant u32 0 (const) */
    /* execute.a64:450 [F] s_b_14_7 = s_b_14_5==s_b_14_6 (const) */
    uint8_t s_b_14_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_14_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_14_9 = s_b_14_3!=s_b_14_8 (const) */
    uint8_t s_b_14_9 = ((uint8_t)(s_b_14_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_14_10 = s_b_14_7!=s_b_14_8 (const) */
    uint8_t s_b_14_10 = ((uint8_t)(s_b_14_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_14_11 = s_b_14_9&s_b_14_10 (const) */
    uint8_t s_b_14_11 = ((uint8_t)(s_b_14_9 & s_b_14_10));
    /* execute.a64:450 [F] s_b_14_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:450 [F] s_b_14_13 = (u32)s_b_14_12 (const) */
    /* execute.a64:450 [F] s_b_14_14 = constant u32 4 (const) */
    /* execute.a64:450 [F] s_b_14_15 = s_b_14_13==s_b_14_14 (const) */
    uint8_t s_b_14_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_14_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_14_17 = s_b_14_11!=s_b_14_16 (const) */
    uint8_t s_b_14_17 = ((uint8_t)(s_b_14_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_14_18 = s_b_14_15!=s_b_14_16 (const) */
    uint8_t s_b_14_18 = ((uint8_t)(s_b_14_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_14_19 = s_b_14_17&s_b_14_18 (const) */
    uint8_t s_b_14_19 = ((uint8_t)(s_b_14_17 & s_b_14_18));
    /* execute.a64:450 [F] s_b_14_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:450 [F] s_b_14_21 = (u32)s_b_14_20 (const) */
    /* execute.a64:450 [F] s_b_14_22 = constant u32 0 (const) */
    /* execute.a64:450 [F] s_b_14_23 = s_b_14_21==s_b_14_22 (const) */
    uint8_t s_b_14_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_14_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_14_25 = s_b_14_19!=s_b_14_24 (const) */
    uint8_t s_b_14_25 = ((uint8_t)(s_b_14_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_14_26 = s_b_14_23!=s_b_14_24 (const) */
    uint8_t s_b_14_26 = ((uint8_t)(s_b_14_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_14_27 = s_b_14_25&s_b_14_26 (const) */
    uint8_t s_b_14_27 = ((uint8_t)(s_b_14_25 & s_b_14_26));
    /* execute.a64:450 [F] s_b_14_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:450 [F] s_b_14_29 = (u32)s_b_14_28 (const) */
    /* execute.a64:450 [F] s_b_14_30 = constant u32 1 (const) */
    /* execute.a64:450 [F] s_b_14_31 = s_b_14_29==s_b_14_30 (const) */
    uint8_t s_b_14_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_14_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_14_33 = s_b_14_27!=s_b_14_32 (const) */
    uint8_t s_b_14_33 = ((uint8_t)(s_b_14_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_14_34 = s_b_14_31!=s_b_14_32 (const) */
    uint8_t s_b_14_34 = ((uint8_t)(s_b_14_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_14_35 = s_b_14_33&s_b_14_34 (const) */
    uint8_t s_b_14_35 = ((uint8_t)(s_b_14_33 & s_b_14_34));
    /* execute.a64:450 [F] s_b_14_36: If s_b_14_35: Jump b_15 else b_16 (const) */
    if (s_b_14_35) 
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
    /* execute.a64:451 [D] s_b_15_0 = ReadReg 16 (u64) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1376), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1376), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:451 [D] s_b_15_1: sym_16830_0_value = s_b_15_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_15_0);
    /* execute.a64:451 [F] s_b_15_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:452 [F] s_b_16_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:452 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:452 [F] s_b_16_2 = constant u32 3 (const) */
    /* execute.a64:452 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:452 [F] s_b_16_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:452 [F] s_b_16_5 = (u32)s_b_16_4 (const) */
    /* execute.a64:452 [F] s_b_16_6 = constant u32 0 (const) */
    /* execute.a64:452 [F] s_b_16_7 = s_b_16_5==s_b_16_6 (const) */
    uint8_t s_b_16_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_16_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_16_9 = s_b_16_3!=s_b_16_8 (const) */
    uint8_t s_b_16_9 = ((uint8_t)(s_b_16_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_16_10 = s_b_16_7!=s_b_16_8 (const) */
    uint8_t s_b_16_10 = ((uint8_t)(s_b_16_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_16_11 = s_b_16_9&s_b_16_10 (const) */
    uint8_t s_b_16_11 = ((uint8_t)(s_b_16_9 & s_b_16_10));
    /* execute.a64:452 [F] s_b_16_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:452 [F] s_b_16_13 = (u32)s_b_16_12 (const) */
    /* execute.a64:452 [F] s_b_16_14 = constant u32 d (const) */
    /* execute.a64:452 [F] s_b_16_15 = s_b_16_13==s_b_16_14 (const) */
    uint8_t s_b_16_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)13ULL));
    /* ???:4294967295 [F] s_b_16_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_16_17 = s_b_16_11!=s_b_16_16 (const) */
    uint8_t s_b_16_17 = ((uint8_t)(s_b_16_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_16_18 = s_b_16_15!=s_b_16_16 (const) */
    uint8_t s_b_16_18 = ((uint8_t)(s_b_16_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_16_19 = s_b_16_17&s_b_16_18 (const) */
    uint8_t s_b_16_19 = ((uint8_t)(s_b_16_17 & s_b_16_18));
    /* execute.a64:452 [F] s_b_16_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:452 [F] s_b_16_21 = (u32)s_b_16_20 (const) */
    /* execute.a64:452 [F] s_b_16_22 = constant u32 0 (const) */
    /* execute.a64:452 [F] s_b_16_23 = s_b_16_21==s_b_16_22 (const) */
    uint8_t s_b_16_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_16_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_16_25 = s_b_16_19!=s_b_16_24 (const) */
    uint8_t s_b_16_25 = ((uint8_t)(s_b_16_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_16_26 = s_b_16_23!=s_b_16_24 (const) */
    uint8_t s_b_16_26 = ((uint8_t)(s_b_16_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_16_27 = s_b_16_25&s_b_16_26 (const) */
    uint8_t s_b_16_27 = ((uint8_t)(s_b_16_25 & s_b_16_26));
    /* execute.a64:452 [F] s_b_16_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:452 [F] s_b_16_29 = (u32)s_b_16_28 (const) */
    /* execute.a64:452 [F] s_b_16_30 = constant u32 1 (const) */
    /* execute.a64:452 [F] s_b_16_31 = s_b_16_29==s_b_16_30 (const) */
    uint8_t s_b_16_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_16_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_16_33 = s_b_16_27!=s_b_16_32 (const) */
    uint8_t s_b_16_33 = ((uint8_t)(s_b_16_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_16_34 = s_b_16_31!=s_b_16_32 (const) */
    uint8_t s_b_16_34 = ((uint8_t)(s_b_16_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_16_35 = s_b_16_33&s_b_16_34 (const) */
    uint8_t s_b_16_35 = ((uint8_t)(s_b_16_33 & s_b_16_34));
    /* execute.a64:452 [F] s_b_16_36: If s_b_16_35: Jump b_17 else b_18 (const) */
    if (s_b_16_35) 
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
    /* execute.a64:453 [D] s_b_17_0 = ReadReg 24 (u32) */
    auto s_b_17_0 = emitter.load_register(emitter.const_u32(1432), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1432), s_b_17_0, emitter.const_u8(4));
    }
    /* execute.a64:453 [D] s_b_17_1 = (u64)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u64());
    /* execute.a64:453 [D] s_b_17_2: sym_16830_0_value = s_b_17_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_17_1);
    /* execute.a64:453 [F] s_b_17_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:454 [F] s_b_18_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:454 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
    /* execute.a64:454 [F] s_b_18_2 = constant u32 2 (const) */
    /* execute.a64:454 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)2ULL));
    /* execute.a64:454 [F] s_b_18_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:454 [F] s_b_18_5 = (u32)s_b_18_4 (const) */
    /* execute.a64:454 [F] s_b_18_6 = constant u32 0 (const) */
    /* execute.a64:454 [F] s_b_18_7 = s_b_18_5==s_b_18_6 (const) */
    uint8_t s_b_18_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_18_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_18_9 = s_b_18_3!=s_b_18_8 (const) */
    uint8_t s_b_18_9 = ((uint8_t)(s_b_18_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_18_10 = s_b_18_7!=s_b_18_8 (const) */
    uint8_t s_b_18_10 = ((uint8_t)(s_b_18_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_18_11 = s_b_18_9&s_b_18_10 (const) */
    uint8_t s_b_18_11 = ((uint8_t)(s_b_18_9 & s_b_18_10));
    /* execute.a64:454 [F] s_b_18_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:454 [F] s_b_18_13 = (u32)s_b_18_12 (const) */
    /* execute.a64:454 [F] s_b_18_14 = constant u32 0 (const) */
    /* execute.a64:454 [F] s_b_18_15 = s_b_18_13==s_b_18_14 (const) */
    uint8_t s_b_18_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_18_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_18_17 = s_b_18_11!=s_b_18_16 (const) */
    uint8_t s_b_18_17 = ((uint8_t)(s_b_18_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_18_18 = s_b_18_15!=s_b_18_16 (const) */
    uint8_t s_b_18_18 = ((uint8_t)(s_b_18_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_18_19 = s_b_18_17&s_b_18_18 (const) */
    uint8_t s_b_18_19 = ((uint8_t)(s_b_18_17 & s_b_18_18));
    /* execute.a64:454 [F] s_b_18_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:454 [F] s_b_18_21 = (u32)s_b_18_20 (const) */
    /* execute.a64:454 [F] s_b_18_22 = constant u32 2 (const) */
    /* execute.a64:454 [F] s_b_18_23 = s_b_18_21==s_b_18_22 (const) */
    uint8_t s_b_18_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_18_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_18_25 = s_b_18_19!=s_b_18_24 (const) */
    uint8_t s_b_18_25 = ((uint8_t)(s_b_18_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_18_26 = s_b_18_23!=s_b_18_24 (const) */
    uint8_t s_b_18_26 = ((uint8_t)(s_b_18_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_18_27 = s_b_18_25&s_b_18_26 (const) */
    uint8_t s_b_18_27 = ((uint8_t)(s_b_18_25 & s_b_18_26));
    /* execute.a64:454 [F] s_b_18_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:454 [F] s_b_18_29 = (u32)s_b_18_28 (const) */
    /* execute.a64:454 [F] s_b_18_30 = constant u32 2 (const) */
    /* execute.a64:454 [F] s_b_18_31 = s_b_18_29==s_b_18_30 (const) */
    uint8_t s_b_18_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_18_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_18_33 = s_b_18_27!=s_b_18_32 (const) */
    uint8_t s_b_18_33 = ((uint8_t)(s_b_18_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_18_34 = s_b_18_31!=s_b_18_32 (const) */
    uint8_t s_b_18_34 = ((uint8_t)(s_b_18_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_18_35 = s_b_18_33&s_b_18_34 (const) */
    uint8_t s_b_18_35 = ((uint8_t)(s_b_18_33 & s_b_18_34));
    /* execute.a64:454 [F] s_b_18_36: If s_b_18_35: Jump b_19 else b_20 (const) */
    if (s_b_18_35) 
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
    /* execute.a64:455 [D] s_b_19_0 = ReadReg 23 (u32) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1428), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1428), s_b_19_0, emitter.const_u8(4));
    }
    /* execute.a64:455 [D] s_b_19_1 = (u64)s_b_19_0 */
    auto s_b_19_1 = emitter.zx(s_b_19_0, emitter.context().types().u64());
    /* execute.a64:455 [D] s_b_19_2: sym_16830_0_value = s_b_19_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_19_1);
    /* execute.a64:455 [F] s_b_19_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_18,  */
  fixed_block_b_20: 
  {
    /* execute.a64:456 [F] s_b_20_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:456 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
    /* execute.a64:456 [F] s_b_20_2 = constant u32 3 (const) */
    /* execute.a64:456 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:456 [F] s_b_20_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:456 [F] s_b_20_5 = (u32)s_b_20_4 (const) */
    /* execute.a64:456 [F] s_b_20_6 = constant u32 0 (const) */
    /* execute.a64:456 [F] s_b_20_7 = s_b_20_5==s_b_20_6 (const) */
    uint8_t s_b_20_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_20_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_20_9 = s_b_20_3!=s_b_20_8 (const) */
    uint8_t s_b_20_9 = ((uint8_t)(s_b_20_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_20_10 = s_b_20_7!=s_b_20_8 (const) */
    uint8_t s_b_20_10 = ((uint8_t)(s_b_20_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_20_11 = s_b_20_9&s_b_20_10 (const) */
    uint8_t s_b_20_11 = ((uint8_t)(s_b_20_9 & s_b_20_10));
    /* execute.a64:456 [F] s_b_20_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:456 [F] s_b_20_13 = (u32)s_b_20_12 (const) */
    /* execute.a64:456 [F] s_b_20_14 = constant u32 2 (const) */
    /* execute.a64:456 [F] s_b_20_15 = s_b_20_13==s_b_20_14 (const) */
    uint8_t s_b_20_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_20_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_20_17 = s_b_20_11!=s_b_20_16 (const) */
    uint8_t s_b_20_17 = ((uint8_t)(s_b_20_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_20_18 = s_b_20_15!=s_b_20_16 (const) */
    uint8_t s_b_20_18 = ((uint8_t)(s_b_20_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_20_19 = s_b_20_17&s_b_20_18 (const) */
    uint8_t s_b_20_19 = ((uint8_t)(s_b_20_17 & s_b_20_18));
    /* execute.a64:456 [F] s_b_20_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:456 [F] s_b_20_21 = (u32)s_b_20_20 (const) */
    /* execute.a64:456 [F] s_b_20_22 = constant u32 0 (const) */
    /* execute.a64:456 [F] s_b_20_23 = s_b_20_21==s_b_20_22 (const) */
    uint8_t s_b_20_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_20_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_20_25 = s_b_20_19!=s_b_20_24 (const) */
    uint8_t s_b_20_25 = ((uint8_t)(s_b_20_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_20_26 = s_b_20_23!=s_b_20_24 (const) */
    uint8_t s_b_20_26 = ((uint8_t)(s_b_20_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_20_27 = s_b_20_25&s_b_20_26 (const) */
    uint8_t s_b_20_27 = ((uint8_t)(s_b_20_25 & s_b_20_26));
    /* execute.a64:456 [F] s_b_20_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:456 [F] s_b_20_29 = (u32)s_b_20_28 (const) */
    /* execute.a64:456 [F] s_b_20_30 = constant u32 2 (const) */
    /* execute.a64:456 [F] s_b_20_31 = s_b_20_29==s_b_20_30 (const) */
    uint8_t s_b_20_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_20_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_20_33 = s_b_20_27!=s_b_20_32 (const) */
    uint8_t s_b_20_33 = ((uint8_t)(s_b_20_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_20_34 = s_b_20_31!=s_b_20_32 (const) */
    uint8_t s_b_20_34 = ((uint8_t)(s_b_20_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_20_35 = s_b_20_33&s_b_20_34 (const) */
    uint8_t s_b_20_35 = ((uint8_t)(s_b_20_33 & s_b_20_34));
    /* execute.a64:456 [F] s_b_20_36: If s_b_20_35: Jump b_21 else b_22 (const) */
    if (s_b_20_35) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:457 [D] s_b_21_0 = ReadReg 12 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1328), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1328), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:457 [D] s_b_21_1: sym_16830_0_value = s_b_21_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_21_0);
    /* execute.a64:457 [F] s_b_21_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_20,  */
  fixed_block_b_22: 
  {
    /* execute.a64:458 [F] s_b_22_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:458 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
    /* execute.a64:458 [F] s_b_22_2 = constant u32 3 (const) */
    /* execute.a64:458 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:458 [F] s_b_22_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:458 [F] s_b_22_5 = (u32)s_b_22_4 (const) */
    /* execute.a64:458 [F] s_b_22_6 = constant u32 3 (const) */
    /* execute.a64:458 [F] s_b_22_7 = s_b_22_5==s_b_22_6 (const) */
    uint8_t s_b_22_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_22_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_22_9 = s_b_22_3!=s_b_22_8 (const) */
    uint8_t s_b_22_9 = ((uint8_t)(s_b_22_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_22_10 = s_b_22_7!=s_b_22_8 (const) */
    uint8_t s_b_22_10 = ((uint8_t)(s_b_22_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_22_11 = s_b_22_9&s_b_22_10 (const) */
    uint8_t s_b_22_11 = ((uint8_t)(s_b_22_9 & s_b_22_10));
    /* execute.a64:458 [F] s_b_22_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:458 [F] s_b_22_13 = (u32)s_b_22_12 (const) */
    /* execute.a64:458 [F] s_b_22_14 = constant u32 d (const) */
    /* execute.a64:458 [F] s_b_22_15 = s_b_22_13==s_b_22_14 (const) */
    uint8_t s_b_22_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)13ULL));
    /* ???:4294967295 [F] s_b_22_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_22_17 = s_b_22_11!=s_b_22_16 (const) */
    uint8_t s_b_22_17 = ((uint8_t)(s_b_22_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_22_18 = s_b_22_15!=s_b_22_16 (const) */
    uint8_t s_b_22_18 = ((uint8_t)(s_b_22_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_22_19 = s_b_22_17&s_b_22_18 (const) */
    uint8_t s_b_22_19 = ((uint8_t)(s_b_22_17 & s_b_22_18));
    /* execute.a64:458 [F] s_b_22_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:458 [F] s_b_22_21 = (u32)s_b_22_20 (const) */
    /* execute.a64:458 [F] s_b_22_22 = constant u32 0 (const) */
    /* execute.a64:458 [F] s_b_22_23 = s_b_22_21==s_b_22_22 (const) */
    uint8_t s_b_22_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_22_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_22_25 = s_b_22_19!=s_b_22_24 (const) */
    uint8_t s_b_22_25 = ((uint8_t)(s_b_22_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_22_26 = s_b_22_23!=s_b_22_24 (const) */
    uint8_t s_b_22_26 = ((uint8_t)(s_b_22_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_22_27 = s_b_22_25&s_b_22_26 (const) */
    uint8_t s_b_22_27 = ((uint8_t)(s_b_22_25 & s_b_22_26));
    /* execute.a64:458 [F] s_b_22_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:458 [F] s_b_22_29 = (u32)s_b_22_28 (const) */
    /* execute.a64:458 [F] s_b_22_30 = constant u32 2 (const) */
    /* execute.a64:458 [F] s_b_22_31 = s_b_22_29==s_b_22_30 (const) */
    uint8_t s_b_22_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_22_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_22_33 = s_b_22_27!=s_b_22_32 (const) */
    uint8_t s_b_22_33 = ((uint8_t)(s_b_22_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_22_34 = s_b_22_31!=s_b_22_32 (const) */
    uint8_t s_b_22_34 = ((uint8_t)(s_b_22_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_22_35 = s_b_22_33&s_b_22_34 (const) */
    uint8_t s_b_22_35 = ((uint8_t)(s_b_22_33 & s_b_22_34));
    /* execute.a64:458 [F] s_b_22_36: If s_b_22_35: Jump b_23 else b_24 (const) */
    if (s_b_22_35) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:459 [D] s_b_23_0 = ReadReg 14 (u64) */
    auto s_b_23_0 = emitter.load_register(emitter.const_u32(1344), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1344), s_b_23_0, emitter.const_u8(8));
    }
    /* execute.a64:459 [D] s_b_23_1: sym_16830_0_value = s_b_23_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_23_0);
    /* execute.a64:459 [F] s_b_23_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_22,  */
  fixed_block_b_24: 
  {
    /* execute.a64:460 [F] s_b_24_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:460 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:460 [F] s_b_24_2 = constant u32 3 (const) */
    /* execute.a64:460 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:460 [F] s_b_24_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:460 [F] s_b_24_5 = (u32)s_b_24_4 (const) */
    /* execute.a64:460 [F] s_b_24_6 = constant u32 0 (const) */
    /* execute.a64:460 [F] s_b_24_7 = s_b_24_5==s_b_24_6 (const) */
    uint8_t s_b_24_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_24_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_24_9 = s_b_24_3!=s_b_24_8 (const) */
    uint8_t s_b_24_9 = ((uint8_t)(s_b_24_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_24_10 = s_b_24_7!=s_b_24_8 (const) */
    uint8_t s_b_24_10 = ((uint8_t)(s_b_24_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_24_11 = s_b_24_9&s_b_24_10 (const) */
    uint8_t s_b_24_11 = ((uint8_t)(s_b_24_9 & s_b_24_10));
    /* execute.a64:460 [F] s_b_24_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:460 [F] s_b_24_13 = (u32)s_b_24_12 (const) */
    /* execute.a64:460 [F] s_b_24_14 = constant u32 d (const) */
    /* execute.a64:460 [F] s_b_24_15 = s_b_24_13==s_b_24_14 (const) */
    uint8_t s_b_24_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)13ULL));
    /* ???:4294967295 [F] s_b_24_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_24_17 = s_b_24_11!=s_b_24_16 (const) */
    uint8_t s_b_24_17 = ((uint8_t)(s_b_24_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_24_18 = s_b_24_15!=s_b_24_16 (const) */
    uint8_t s_b_24_18 = ((uint8_t)(s_b_24_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_24_19 = s_b_24_17&s_b_24_18 (const) */
    uint8_t s_b_24_19 = ((uint8_t)(s_b_24_17 & s_b_24_18));
    /* execute.a64:460 [F] s_b_24_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:460 [F] s_b_24_21 = (u32)s_b_24_20 (const) */
    /* execute.a64:460 [F] s_b_24_22 = constant u32 0 (const) */
    /* execute.a64:460 [F] s_b_24_23 = s_b_24_21==s_b_24_22 (const) */
    uint8_t s_b_24_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_24_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_24_25 = s_b_24_19!=s_b_24_24 (const) */
    uint8_t s_b_24_25 = ((uint8_t)(s_b_24_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_24_26 = s_b_24_23!=s_b_24_24 (const) */
    uint8_t s_b_24_26 = ((uint8_t)(s_b_24_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_24_27 = s_b_24_25&s_b_24_26 (const) */
    uint8_t s_b_24_27 = ((uint8_t)(s_b_24_25 & s_b_24_26));
    /* execute.a64:460 [F] s_b_24_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:460 [F] s_b_24_29 = (u32)s_b_24_28 (const) */
    /* execute.a64:460 [F] s_b_24_30 = constant u32 4 (const) */
    /* execute.a64:460 [F] s_b_24_31 = s_b_24_29==s_b_24_30 (const) */
    uint8_t s_b_24_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_24_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_24_33 = s_b_24_27!=s_b_24_32 (const) */
    uint8_t s_b_24_33 = ((uint8_t)(s_b_24_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_24_34 = s_b_24_31!=s_b_24_32 (const) */
    uint8_t s_b_24_34 = ((uint8_t)(s_b_24_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_24_35 = s_b_24_33&s_b_24_34 (const) */
    uint8_t s_b_24_35 = ((uint8_t)(s_b_24_33 & s_b_24_34));
    /* execute.a64:460 [F] s_b_24_36: If s_b_24_35: Jump b_25 else b_26 (const) */
    if (s_b_24_35) 
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
    /* execute.a64:461 [D] s_b_25_0 = ReadReg 15 (u64) */
    auto s_b_25_0 = emitter.load_register(emitter.const_u32(1352), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1352), s_b_25_0, emitter.const_u8(8));
    }
    /* execute.a64:461 [D] s_b_25_1: sym_16830_0_value = s_b_25_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_25_0);
    /* execute.a64:461 [F] s_b_25_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_24,  */
  fixed_block_b_26: 
  {
    /* execute.a64:462 [F] s_b_26_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:462 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
    /* execute.a64:462 [F] s_b_26_2 = constant u32 3 (const) */
    /* execute.a64:462 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:462 [F] s_b_26_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:462 [F] s_b_26_5 = (u32)s_b_26_4 (const) */
    /* execute.a64:462 [F] s_b_26_6 = constant u32 3 (const) */
    /* execute.a64:462 [F] s_b_26_7 = s_b_26_5==s_b_26_6 (const) */
    uint8_t s_b_26_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_26_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_26_9 = s_b_26_3!=s_b_26_8 (const) */
    uint8_t s_b_26_9 = ((uint8_t)(s_b_26_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_26_10 = s_b_26_7!=s_b_26_8 (const) */
    uint8_t s_b_26_10 = ((uint8_t)(s_b_26_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_26_11 = s_b_26_9&s_b_26_10 (const) */
    uint8_t s_b_26_11 = ((uint8_t)(s_b_26_9 & s_b_26_10));
    /* execute.a64:462 [F] s_b_26_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:462 [F] s_b_26_13 = (u32)s_b_26_12 (const) */
    /* execute.a64:462 [F] s_b_26_14 = constant u32 4 (const) */
    /* execute.a64:462 [F] s_b_26_15 = s_b_26_13==s_b_26_14 (const) */
    uint8_t s_b_26_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_26_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_26_17 = s_b_26_11!=s_b_26_16 (const) */
    uint8_t s_b_26_17 = ((uint8_t)(s_b_26_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_26_18 = s_b_26_15!=s_b_26_16 (const) */
    uint8_t s_b_26_18 = ((uint8_t)(s_b_26_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_26_19 = s_b_26_17&s_b_26_18 (const) */
    uint8_t s_b_26_19 = ((uint8_t)(s_b_26_17 & s_b_26_18));
    /* execute.a64:462 [F] s_b_26_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:462 [F] s_b_26_21 = (u32)s_b_26_20 (const) */
    /* execute.a64:462 [F] s_b_26_22 = constant u32 2 (const) */
    /* execute.a64:462 [F] s_b_26_23 = s_b_26_21==s_b_26_22 (const) */
    uint8_t s_b_26_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_26_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_26_25 = s_b_26_19!=s_b_26_24 (const) */
    uint8_t s_b_26_25 = ((uint8_t)(s_b_26_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_26_26 = s_b_26_23!=s_b_26_24 (const) */
    uint8_t s_b_26_26 = ((uint8_t)(s_b_26_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_26_27 = s_b_26_25&s_b_26_26 (const) */
    uint8_t s_b_26_27 = ((uint8_t)(s_b_26_25 & s_b_26_26));
    /* execute.a64:462 [F] s_b_26_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:462 [F] s_b_26_29 = (u32)s_b_26_28 (const) */
    /* execute.a64:462 [F] s_b_26_30 = constant u32 0 (const) */
    /* execute.a64:462 [F] s_b_26_31 = s_b_26_29==s_b_26_30 (const) */
    uint8_t s_b_26_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_26_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_26_33 = s_b_26_27!=s_b_26_32 (const) */
    uint8_t s_b_26_33 = ((uint8_t)(s_b_26_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_26_34 = s_b_26_31!=s_b_26_32 (const) */
    uint8_t s_b_26_34 = ((uint8_t)(s_b_26_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_26_35 = s_b_26_33&s_b_26_34 (const) */
    uint8_t s_b_26_35 = ((uint8_t)(s_b_26_33 & s_b_26_34));
    /* execute.a64:462 [F] s_b_26_36: If s_b_26_35: Jump b_27 else b_28 (const) */
    if (s_b_26_35) 
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
    /* execute.a64:464 [D] s_b_27_0 = ReadReg 1 (u8) */
    auto s_b_27_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_27_0, emitter.const_u8(1));
    }
    /* execute.a64:464 [D] s_b_27_1 = (u64)s_b_27_0 */
    auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
    /* execute.a64:464 [F] s_b_27_2 = constant u64 1f (const) */
    /* execute.a64:464 [D] s_b_27_3 = s_b_27_1<<s_b_27_2 */
    auto s_b_27_3 = emitter.shl(s_b_27_1, emitter.const_u64((uint64_t)31ULL));
    /* execute.a64:464 [D] s_b_27_4 = ReadReg 2 (u8) */
    auto s_b_27_4 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_27_4, emitter.const_u8(1));
    }
    /* execute.a64:464 [D] s_b_27_5 = (u64)s_b_27_4 */
    auto s_b_27_5 = emitter.zx(s_b_27_4, emitter.context().types().u64());
    /* execute.a64:464 [F] s_b_27_6 = constant u64 1e (const) */
    /* execute.a64:464 [D] s_b_27_7 = s_b_27_5<<s_b_27_6 */
    auto s_b_27_7 = emitter.shl(s_b_27_5, emitter.const_u64((uint64_t)30ULL));
    /* execute.a64:464 [D] s_b_27_8 = s_b_27_3|s_b_27_7 */
    auto s_b_27_8 = emitter.bitwise_or(s_b_27_3, s_b_27_7);
    /* execute.a64:464 [D] s_b_27_9 = ReadReg 3 (u8) */
    auto s_b_27_9 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_27_9, emitter.const_u8(1));
    }
    /* execute.a64:464 [D] s_b_27_10 = (u64)s_b_27_9 */
    auto s_b_27_10 = emitter.zx(s_b_27_9, emitter.context().types().u64());
    /* execute.a64:464 [F] s_b_27_11 = constant u64 1d (const) */
    /* execute.a64:464 [D] s_b_27_12 = s_b_27_10<<s_b_27_11 */
    auto s_b_27_12 = emitter.shl(s_b_27_10, emitter.const_u64((uint64_t)29ULL));
    /* execute.a64:464 [D] s_b_27_13 = s_b_27_8|s_b_27_12 */
    auto s_b_27_13 = emitter.bitwise_or(s_b_27_8, s_b_27_12);
    /* execute.a64:464 [D] s_b_27_14 = ReadReg 4 (u8) */
    auto s_b_27_14 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_27_14, emitter.const_u8(1));
    }
    /* execute.a64:464 [D] s_b_27_15 = (u64)s_b_27_14 */
    auto s_b_27_15 = emitter.zx(s_b_27_14, emitter.context().types().u64());
    /* execute.a64:464 [F] s_b_27_16 = constant u64 1c (const) */
    /* execute.a64:464 [D] s_b_27_17 = s_b_27_15<<s_b_27_16 */
    auto s_b_27_17 = emitter.shl(s_b_27_15, emitter.const_u64((uint64_t)28ULL));
    /* execute.a64:464 [D] s_b_27_18 = s_b_27_13|s_b_27_17 */
    auto s_b_27_18 = emitter.bitwise_or(s_b_27_13, s_b_27_17);
    /* execute.a64:464 [D] s_b_27_19: sym_16830_0_value = s_b_27_18, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_27_18);
    /* execute.a64:464 [F] s_b_27_20: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_26,  */
  fixed_block_b_28: 
  {
    /* execute.a64:465 [F] s_b_28_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:465 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:465 [F] s_b_28_2 = constant u32 3 (const) */
    /* execute.a64:465 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:465 [F] s_b_28_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:465 [F] s_b_28_5 = (u32)s_b_28_4 (const) */
    /* execute.a64:465 [F] s_b_28_6 = constant u32 3 (const) */
    /* execute.a64:465 [F] s_b_28_7 = s_b_28_5==s_b_28_6 (const) */
    uint8_t s_b_28_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_28_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_28_9 = s_b_28_3!=s_b_28_8 (const) */
    uint8_t s_b_28_9 = ((uint8_t)(s_b_28_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_28_10 = s_b_28_7!=s_b_28_8 (const) */
    uint8_t s_b_28_10 = ((uint8_t)(s_b_28_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_28_11 = s_b_28_9&s_b_28_10 (const) */
    uint8_t s_b_28_11 = ((uint8_t)(s_b_28_9 & s_b_28_10));
    /* execute.a64:465 [F] s_b_28_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:465 [F] s_b_28_13 = (u32)s_b_28_12 (const) */
    /* execute.a64:465 [F] s_b_28_14 = constant u32 4 (const) */
    /* execute.a64:465 [F] s_b_28_15 = s_b_28_13==s_b_28_14 (const) */
    uint8_t s_b_28_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_28_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_28_17 = s_b_28_11!=s_b_28_16 (const) */
    uint8_t s_b_28_17 = ((uint8_t)(s_b_28_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_28_18 = s_b_28_15!=s_b_28_16 (const) */
    uint8_t s_b_28_18 = ((uint8_t)(s_b_28_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_28_19 = s_b_28_17&s_b_28_18 (const) */
    uint8_t s_b_28_19 = ((uint8_t)(s_b_28_17 & s_b_28_18));
    /* execute.a64:465 [F] s_b_28_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:465 [F] s_b_28_21 = (u32)s_b_28_20 (const) */
    /* execute.a64:465 [F] s_b_28_22 = constant u32 2 (const) */
    /* execute.a64:465 [F] s_b_28_23 = s_b_28_21==s_b_28_22 (const) */
    uint8_t s_b_28_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_28_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_28_25 = s_b_28_19!=s_b_28_24 (const) */
    uint8_t s_b_28_25 = ((uint8_t)(s_b_28_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_28_26 = s_b_28_23!=s_b_28_24 (const) */
    uint8_t s_b_28_26 = ((uint8_t)(s_b_28_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_28_27 = s_b_28_25&s_b_28_26 (const) */
    uint8_t s_b_28_27 = ((uint8_t)(s_b_28_25 & s_b_28_26));
    /* execute.a64:465 [F] s_b_28_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:465 [F] s_b_28_29 = (u32)s_b_28_28 (const) */
    /* execute.a64:465 [F] s_b_28_30 = constant u32 1 (const) */
    /* execute.a64:465 [F] s_b_28_31 = s_b_28_29==s_b_28_30 (const) */
    uint8_t s_b_28_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_28_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_28_33 = s_b_28_27!=s_b_28_32 (const) */
    uint8_t s_b_28_33 = ((uint8_t)(s_b_28_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_28_34 = s_b_28_31!=s_b_28_32 (const) */
    uint8_t s_b_28_34 = ((uint8_t)(s_b_28_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_28_35 = s_b_28_33&s_b_28_34 (const) */
    uint8_t s_b_28_35 = ((uint8_t)(s_b_28_33 & s_b_28_34));
    /* execute.a64:465 [F] s_b_28_36: If s_b_28_35: Jump b_29 else b_30 (const) */
    if (s_b_28_35) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:467 [D] s_b_29_0 = ReadReg 5 (u8) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_29_0, emitter.const_u8(1));
    }
    /* execute.a64:467 [D] s_b_29_1 = (u64)s_b_29_0 */
    auto s_b_29_1 = emitter.zx(s_b_29_0, emitter.context().types().u64());
    /* execute.a64:467 [F] s_b_29_2 = constant u64 9 (const) */
    /* execute.a64:467 [D] s_b_29_3 = s_b_29_1<<s_b_29_2 */
    auto s_b_29_3 = emitter.shl(s_b_29_1, emitter.const_u64((uint64_t)9ULL));
    /* execute.a64:467 [D] s_b_29_4 = ReadReg 6 (u8) */
    auto s_b_29_4 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_29_4, emitter.const_u8(1));
    }
    /* execute.a64:467 [D] s_b_29_5 = (u64)s_b_29_4 */
    auto s_b_29_5 = emitter.zx(s_b_29_4, emitter.context().types().u64());
    /* execute.a64:467 [F] s_b_29_6 = constant u64 8 (const) */
    /* execute.a64:467 [D] s_b_29_7 = s_b_29_5<<s_b_29_6 */
    auto s_b_29_7 = emitter.shl(s_b_29_5, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:467 [D] s_b_29_8 = s_b_29_3|s_b_29_7 */
    auto s_b_29_8 = emitter.bitwise_or(s_b_29_3, s_b_29_7);
    /* execute.a64:467 [D] s_b_29_9 = ReadReg 7 (u8) */
    auto s_b_29_9 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_29_9, emitter.const_u8(1));
    }
    /* execute.a64:467 [D] s_b_29_10 = (u64)s_b_29_9 */
    auto s_b_29_10 = emitter.zx(s_b_29_9, emitter.context().types().u64());
    /* execute.a64:467 [F] s_b_29_11 = constant u64 7 (const) */
    /* execute.a64:467 [D] s_b_29_12 = s_b_29_10<<s_b_29_11 */
    auto s_b_29_12 = emitter.shl(s_b_29_10, emitter.const_u64((uint64_t)7ULL));
    /* execute.a64:467 [D] s_b_29_13 = s_b_29_8|s_b_29_12 */
    auto s_b_29_13 = emitter.bitwise_or(s_b_29_8, s_b_29_12);
    /* execute.a64:467 [D] s_b_29_14 = ReadReg 8 (u8) */
    auto s_b_29_14 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_29_14, emitter.const_u8(1));
    }
    /* execute.a64:467 [D] s_b_29_15 = (u64)s_b_29_14 */
    auto s_b_29_15 = emitter.zx(s_b_29_14, emitter.context().types().u64());
    /* execute.a64:467 [F] s_b_29_16 = constant u64 6 (const) */
    /* execute.a64:467 [D] s_b_29_17 = s_b_29_15<<s_b_29_16 */
    auto s_b_29_17 = emitter.shl(s_b_29_15, emitter.const_u64((uint64_t)6ULL));
    /* execute.a64:467 [D] s_b_29_18 = s_b_29_13|s_b_29_17 */
    auto s_b_29_18 = emitter.bitwise_or(s_b_29_13, s_b_29_17);
    /* execute.a64:467 [D] s_b_29_19: sym_16830_0_value = s_b_29_18, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_29_18);
    /* execute.a64:467 [F] s_b_29_20: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_28,  */
  fixed_block_b_30: 
  {
    /* execute.a64:468 [F] s_b_30_0=sym_16764_3_parameter_inst.op0 (const) */
    /* execute.a64:468 [F] s_b_30_1 = (u32)s_b_30_0 (const) */
    /* execute.a64:468 [F] s_b_30_2 = constant u32 3 (const) */
    /* execute.a64:468 [F] s_b_30_3 = s_b_30_1==s_b_30_2 (const) */
    uint8_t s_b_30_3 = ((uint8_t)(((uint32_t)insn.op0) == (uint32_t)3ULL));
    /* execute.a64:468 [F] s_b_30_4=sym_16764_3_parameter_inst.op1 (const) */
    /* execute.a64:468 [F] s_b_30_5 = (u32)s_b_30_4 (const) */
    /* execute.a64:468 [F] s_b_30_6 = constant u32 3 (const) */
    /* execute.a64:468 [F] s_b_30_7 = s_b_30_5==s_b_30_6 (const) */
    uint8_t s_b_30_7 = ((uint8_t)(((uint32_t)insn.op1) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_30_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_30_9 = s_b_30_3!=s_b_30_8 (const) */
    uint8_t s_b_30_9 = ((uint8_t)(s_b_30_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_30_10 = s_b_30_7!=s_b_30_8 (const) */
    uint8_t s_b_30_10 = ((uint8_t)(s_b_30_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_30_11 = s_b_30_9&s_b_30_10 (const) */
    uint8_t s_b_30_11 = ((uint8_t)(s_b_30_9 & s_b_30_10));
    /* execute.a64:468 [F] s_b_30_12=sym_16764_3_parameter_inst.crn (const) */
    /* execute.a64:468 [F] s_b_30_13 = (u32)s_b_30_12 (const) */
    /* execute.a64:468 [F] s_b_30_14 = constant u32 4 (const) */
    /* execute.a64:468 [F] s_b_30_15 = s_b_30_13==s_b_30_14 (const) */
    uint8_t s_b_30_15 = ((uint8_t)(((uint32_t)insn.crn) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_30_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_30_17 = s_b_30_11!=s_b_30_16 (const) */
    uint8_t s_b_30_17 = ((uint8_t)(s_b_30_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_30_18 = s_b_30_15!=s_b_30_16 (const) */
    uint8_t s_b_30_18 = ((uint8_t)(s_b_30_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_30_19 = s_b_30_17&s_b_30_18 (const) */
    uint8_t s_b_30_19 = ((uint8_t)(s_b_30_17 & s_b_30_18));
    /* execute.a64:468 [F] s_b_30_20=sym_16764_3_parameter_inst.crm (const) */
    /* execute.a64:468 [F] s_b_30_21 = (u32)s_b_30_20 (const) */
    /* execute.a64:468 [F] s_b_30_22 = constant u32 4 (const) */
    /* execute.a64:468 [F] s_b_30_23 = s_b_30_21==s_b_30_22 (const) */
    uint8_t s_b_30_23 = ((uint8_t)(((uint32_t)insn.crm) == (uint32_t)4ULL));
    /* ???:4294967295 [F] s_b_30_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_30_25 = s_b_30_19!=s_b_30_24 (const) */
    uint8_t s_b_30_25 = ((uint8_t)(s_b_30_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_30_26 = s_b_30_23!=s_b_30_24 (const) */
    uint8_t s_b_30_26 = ((uint8_t)(s_b_30_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_30_27 = s_b_30_25&s_b_30_26 (const) */
    uint8_t s_b_30_27 = ((uint8_t)(s_b_30_25 & s_b_30_26));
    /* execute.a64:468 [F] s_b_30_28=sym_16764_3_parameter_inst.op2 (const) */
    /* execute.a64:468 [F] s_b_30_29 = (u32)s_b_30_28 (const) */
    /* execute.a64:468 [F] s_b_30_30 = constant u32 0 (const) */
    /* execute.a64:468 [F] s_b_30_31 = s_b_30_29==s_b_30_30 (const) */
    uint8_t s_b_30_31 = ((uint8_t)(((uint32_t)insn.op2) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_30_32 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_30_33 = s_b_30_27!=s_b_30_32 (const) */
    uint8_t s_b_30_33 = ((uint8_t)(s_b_30_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_30_34 = s_b_30_31!=s_b_30_32 (const) */
    uint8_t s_b_30_34 = ((uint8_t)(s_b_30_31 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_30_35 = s_b_30_33&s_b_30_34 (const) */
    uint8_t s_b_30_35 = ((uint8_t)(s_b_30_33 & s_b_30_34));
    /* execute.a64:468 [F] s_b_30_36: If s_b_30_35: Jump b_31 else b_32 (const) */
    if (s_b_30_35) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:469 [D] s_b_31_0 = ReadReg 22 (u32) */
    auto s_b_31_0 = emitter.load_register(emitter.const_u32(1424), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1424), s_b_31_0, emitter.const_u8(4));
    }
    /* execute.a64:469 [D] s_b_31_1 = (u64)s_b_31_0 */
    auto s_b_31_1 = emitter.zx(s_b_31_0, emitter.context().types().u64());
    /* execute.a64:469 [D] s_b_31_2: sym_16830_0_value = s_b_31_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_16830_0_value, s_b_31_1);
    /* execute.a64:469 [F] s_b_31_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_30,  */
  fixed_block_b_32: 
  {
    /* execute.a64:471 [F] s_b_32_0=sym_16764_3_parameter_inst.ir (const) */
    /* execute.a64:471 [F] s_b_32_1 = constant u32 10 (const) */
    /* execute.a64:471 [D] ??? */
    {
      auto tmp = emitter.load_device(emitter.const_u32((uint32_t)16ULL), emitter.const_u32(insn.ir), emitter.context().types().u64());
      emitter.store_local(DV_sym_16830_0_value, tmp);
      if (TRACE) 
      {
        emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_DEVICE,emitter.const_u32((uint32_t)16ULL), emitter.const_u32(insn.ir), tmp);
      }
    }
    /* execute.a64:471 [F] s_b_32_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_35,  */
  fixed_block_b_33: 
  {
    /* ???:4294967295 [F] s_b_33_0: Return */
    goto fixed_done;
  }
  /* b_7,  */
  fixed_block_b_34: 
  {
    /* execute.a64:3012 [F] s_b_34_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_34_1 = __builtin_get_feature */
    uint32_t s_b_34_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_34_2 = (u8)s_b_34_1 (const) */
    /* execute.a64:443 [F] s_b_34_3 = (u32)s_b_34_2 (const) */
    /* execute.a64:443 [F] s_b_34_4 = constant u32 2 (const) */
    /* execute.a64:443 [F] s_b_34_5 = s_b_34_3<<s_b_34_4 (const) */
    uint32_t s_b_34_5 = ((uint32_t)(((uint32_t)((uint8_t)s_b_34_1)) << (uint32_t)2ULL));
    /* execute.a64:443 [F] s_b_34_6 = (u64)s_b_34_5 (const) */
    /* execute.a64:443 [F] s_b_34_7: sym_16830_0_value = s_b_34_6 (const), dominates: s_b_2_0  */
    CV_sym_16830_0_value = ((uint64_t)s_b_34_5);
    emitter.store_local(DV_sym_16830_0_value, emitter.const_u64(((uint64_t)s_b_34_5)));
    /* execute.a64:443 [F] s_b_34_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2684 [F] s_b_35_0=sym_16764_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_35_1 = sym_123068_3_parameter_value uint64_t */
    auto s_b_35_1 = emitter.load_local(DV_sym_123068_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_35_2: WriteRegBank 0:s_b_35_0 = s_b_35_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_35_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_35_1);
    /* execute.a64:0 [F] s_b_35_3: Jump b_33 (const) */
    goto fixed_block_b_33;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_neg_simd(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:6009 [F] s_b_0_0=sym_18986_3_parameter_inst.SCALAR (const) */
    /* execute.simd:6009 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:6009 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.simd:6009 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:6009 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:6010 [F] s_b_1_0=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6010 [F] s_b_1_1=sym_18986_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:6010 [D] s_b_1_3 = (s64)s_b_1_2 */
    auto s_b_1_3 = emitter.reinterpret(s_b_1_2, emitter.context().types().s64());
    /* execute.simd:6010 [D] s_b_1_4 = -s_b_1_3 */
    auto s_b_1_4 = emitter.neg(s_b_1_3);
    /* execute.simd:6010 [D] s_b_1_5 = (u64)s_b_1_4 */
    auto s_b_1_5 = emitter.reinterpret(s_b_1_4, emitter.context().types().u64());
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
    /* execute.simd:6012 [F] s_b_3_0=sym_18986_3_parameter_inst.arrangement (const) */
    /* execute.simd:6013 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:6019 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:6024 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:6030 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:6035 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:6041 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:6046 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:6012 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
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
    /* execute.simd:6014 [F] s_b_4_0=sym_18986_3_parameter_inst.rn (const) */
    /* execute.simd:6014 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:6015 [F] s_b_4_2=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6015 [D] s_b_4_3 = -s_b_4_1 */
    auto s_b_4_3 = emitter.neg(s_b_4_1);
    /* execute.simd:6015 [D] s_b_4_4: WriteRegBank 15:s_b_4_2 = s_b_4_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_3);
    /* execute.simd:6016 [F] s_b_4_5=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6016 [F] s_b_4_6 = constant u64 0 (const) */
    /* execute.simd:6016 [F] s_b_4_7: WriteRegBank 3:s_b_4_5 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:6020 [F] s_b_5_0=sym_18986_3_parameter_inst.rn (const) */
    /* execute.simd:6020 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:6021 [F] s_b_5_2=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6021 [D] s_b_5_3 = -s_b_5_1 */
    auto s_b_5_3 = emitter.neg(s_b_5_1);
    /* execute.simd:6021 [D] s_b_5_4: WriteRegBank 16:s_b_5_2 = s_b_5_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_3,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_3);
    /* execute.simd:0 [F] s_b_5_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:6025 [F] s_b_6_0=sym_18986_3_parameter_inst.rn (const) */
    /* execute.simd:6025 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:6026 [F] s_b_6_2=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6026 [D] s_b_6_3 = -s_b_6_1 */
    auto s_b_6_3 = emitter.neg(s_b_6_1);
    /* execute.simd:6026 [D] s_b_6_4: WriteRegBank 17:s_b_6_2 = s_b_6_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_3);
    /* execute.simd:6027 [F] s_b_6_5=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6027 [F] s_b_6_6 = constant u64 0 (const) */
    /* execute.simd:6027 [F] s_b_6_7: WriteRegBank 3:s_b_6_5 = s_b_6_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:6031 [F] s_b_7_0=sym_18986_3_parameter_inst.rn (const) */
    /* execute.simd:6031 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:6032 [F] s_b_7_2=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6032 [D] s_b_7_3 = -s_b_7_1 */
    auto s_b_7_3 = emitter.neg(s_b_7_1);
    /* execute.simd:6032 [D] s_b_7_4: WriteRegBank 18:s_b_7_2 = s_b_7_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3);
    /* execute.simd:0 [F] s_b_7_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:6036 [F] s_b_8_0=sym_18986_3_parameter_inst.rn (const) */
    /* execute.simd:6036 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:6037 [F] s_b_8_2=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6037 [D] s_b_8_3 = -s_b_8_1 */
    auto s_b_8_3 = emitter.neg(s_b_8_1);
    /* execute.simd:6037 [D] s_b_8_4: WriteRegBank 19:s_b_8_2 = s_b_8_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_3);
    /* execute.simd:6038 [F] s_b_8_5=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6038 [F] s_b_8_6 = constant u64 0 (const) */
    /* execute.simd:6038 [F] s_b_8_7: WriteRegBank 3:s_b_8_5 = s_b_8_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_8_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:6042 [F] s_b_9_0=sym_18986_3_parameter_inst.rn (const) */
    /* execute.simd:6042 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:6043 [F] s_b_9_2=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6043 [D] s_b_9_3 = -s_b_9_1 */
    auto s_b_9_3 = emitter.neg(s_b_9_1);
    /* execute.simd:6043 [D] s_b_9_4: WriteRegBank 20:s_b_9_2 = s_b_9_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_3,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_3);
    /* execute.simd:0 [F] s_b_9_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:6047 [F] s_b_10_0=sym_18986_3_parameter_inst.rn (const) */
    /* execute.simd:6047 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:6048 [F] s_b_10_2=sym_18986_3_parameter_inst.rd (const) */
    /* execute.simd:6048 [D] s_b_10_3 = -s_b_10_1 */
    auto s_b_10_3 = emitter.neg(s_b_10_1);
    /* execute.simd:6048 [D] s_b_10_4: WriteRegBank 21:s_b_10_2 = s_b_10_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_3,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_3);
    /* execute.simd:0 [F] s_b_10_5: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_prfm_lit(const aarch64_decode_a64_LOAD_REG_LIT&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_rev32(const aarch64_decode_a64_DP_1S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_126038_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2192 [F] s_b_0_0=sym_19850_3_parameter_inst.rn (const) */
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
    /* execute.a64:2194 [D] s_b_0_7 = (u32)s_b_0_6 */
    auto s_b_0_7 = emitter.truncate(s_b_0_6, emitter.context().types().u32());
    /* execute.a64:2194 [D] s_b_0_8 = __builtin_bswap32 */
    auto s_b_0_8 = emitter.bswap(s_b_0_7);
    /* execute.a64:2194 [D] s_b_0_9 = (u64)s_b_0_8 */
    auto s_b_0_9 = emitter.zx(s_b_0_8, emitter.context().types().u64());
    /* execute.a64:2195 [F] s_b_0_10 = constant u64 20 (const) */
    /* execute.a64:2195 [D] s_b_0_11 = s_b_0_6>>s_b_0_10 */
    auto s_b_0_11 = emitter.shr(s_b_0_6, emitter.const_u64((uint64_t)32ULL));
    /* execute.a64:2195 [D] s_b_0_12 = (u32)s_b_0_11 */
    auto s_b_0_12 = emitter.truncate(s_b_0_11, emitter.context().types().u32());
    /* execute.a64:2195 [D] s_b_0_13 = __builtin_bswap32 */
    auto s_b_0_13 = emitter.bswap(s_b_0_12);
    /* execute.a64:2195 [D] s_b_0_14 = (u64)s_b_0_13 */
    auto s_b_0_14 = emitter.zx(s_b_0_13, emitter.context().types().u64());
    /* execute.a64:2195 [F] s_b_0_15 = constant u64 20 (const) */
    /* execute.a64:2195 [D] s_b_0_16 = s_b_0_14<<s_b_0_15 */
    auto s_b_0_16 = emitter.shl(s_b_0_14, emitter.const_u64((uint64_t)32ULL));
    /* execute.a64:2197 [D] s_b_0_17 = s_b_0_16|s_b_0_9 */
    auto s_b_0_17 = emitter.bitwise_or(s_b_0_16, s_b_0_9);
    /* execute.a64:2691 [F] s_b_0_18=sym_19850_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_0_19: sym_126038_3_parameter_value = s_b_0_17, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_126038_3_parameter_value, s_b_0_17);
    /* execute.a64:2682 [F] s_b_0_20 = (u32)s_b_0_18 (const) */
    /* execute.a64:2682 [F] s_b_0_21 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_0_22 = s_b_0_20==s_b_0_21 (const) */
    uint8_t s_b_0_22 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_0_23: If s_b_0_22: Jump b_1 else b_2 (const) */
    if (s_b_0_22) 
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
    /* execute.a64:2684 [F] s_b_2_0=sym_19850_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_2_1 = sym_126038_3_parameter_value uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_126038_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sbfm(const aarch64_decode_a64_BITFIELD&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_127003_1_tmp_s_b_12_19;
  uint8_t CV_sym_126920_1_tmp_s_b_10_8;
  auto DV_sym_127229_3_parameter_immz = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_126886_0_replaced_parameter_len;
  uint8_t CV_sym_127000_1_tmp_s_b_12_13;
  auto DV_sym_127296_1__R_s_b_47_6 = emitter.alloc_local(emitter.context().types().s64(), false);
  uint8_t CV_sym_127310_1_tmp_s_b_47_1;
  auto DV_sym_127325_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127369_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126956_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127040_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126950_0_replaced_parameter_src = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127347_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127413_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126931_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_126966_0_replaced_parameter_len;
  auto DV_sym_127014_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126876_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127094_3_parameter_immz = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_127085_3_parameter_bits;
  auto DV_sym_127187_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127391_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126837_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127161_1__R_s_b_37_5 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_22053_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_127220_3_parameter_bits;
  auto DV_sym_127209_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126870_0_replaced_parameter_src = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:59 [F] s_b_0_0=sym_21928_3_parameter_inst.immr (const) */
    /* execute.a64:59 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:59 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:59 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.immr) == (uint32_t)0ULL));
    /* execute.a64:59 [F] s_b_0_4=sym_21928_3_parameter_inst.imms (const) */
    /* execute.a64:59 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:59 [F] s_b_0_6 = constant u32 7 (const) */
    /* execute.a64:59 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.imms) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:59 [F] s_b_0_12=sym_21928_3_parameter_inst.sf (const) */
    /* execute.a64:59 [F] s_b_0_13=sym_21928_3_parameter_inst.N (const) */
    /* execute.a64:59 [F] s_b_0_14 = s_b_0_12==s_b_0_13 (const) */
    uint8_t s_b_0_14 = ((uint8_t)(insn.sf == insn.N));
    /* ???:4294967295 [F] s_b_0_15 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_16 = s_b_0_11!=s_b_0_15 (const) */
    uint8_t s_b_0_16 = ((uint8_t)(s_b_0_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_17 = s_b_0_14!=s_b_0_15 (const) */
    uint8_t s_b_0_17 = ((uint8_t)(s_b_0_14 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_18 = s_b_0_16&s_b_0_17 (const) */
    uint8_t s_b_0_18 = ((uint8_t)(s_b_0_16 & s_b_0_17));
    /* execute.a64:59 [F] s_b_0_19: If s_b_0_18: Jump b_1 else b_3 (const) */
    if (s_b_0_18) 
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
    /* execute.a64:61 [F] s_b_1_0=sym_21928_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2646 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_5 = ReadRegBank 1:s_b_1_0 (u32) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 */
    captive::arch::dbt::el::Value *s_b_1_6;
    s_b_1_6 = (s_b_1_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_5);
    /* execute.a64:2659 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_1_8=sym_21928_3_parameter_inst.sf (const) */
    /* execute.a64:61 [D] s_b_1_9 = (s8)s_b_1_7 */
    auto s_b_1_9 = emitter.truncate(s_b_1_7, emitter.context().types().s8());
    /* execute.a64:61 [D] s_b_1_10 = (s64)s_b_1_9 */
    auto s_b_1_10 = emitter.sx(s_b_1_9, emitter.context().types().s64());
    /* execute.a64:61 [D] s_b_1_11 = (u64)s_b_1_10 */
    auto s_b_1_11 = emitter.reinterpret(s_b_1_10, emitter.context().types().u64());
    /* execute.a64:61 [D] s_b_1_12: sym_127014_3_parameter_value = s_b_1_11, dominates: s_b_22_1 s_b_23_1  */
    emitter.store_local(DV_sym_127014_3_parameter_value, s_b_1_11);
    /* execute.a64:2690 [F] s_b_1_13: If s_b_1_8: Jump b_22 else b_23 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_6, b_17, b_18, b_22, b_23, b_24, b_25, b_35, b_36, b_46, b_47, b_48, b_49, b_50,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:62 [F] s_b_3_0=sym_21928_3_parameter_inst.immr (const) */
    /* execute.a64:62 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:62 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:62 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.immr) == (uint32_t)0ULL));
    /* execute.a64:62 [F] s_b_3_4=sym_21928_3_parameter_inst.imms (const) */
    /* execute.a64:62 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:62 [F] s_b_3_6 = constant u32 f (const) */
    /* execute.a64:62 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.imms) == (uint32_t)15ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:62 [F] s_b_3_12=sym_21928_3_parameter_inst.sf (const) */
    /* execute.a64:62 [F] s_b_3_13=sym_21928_3_parameter_inst.N (const) */
    /* execute.a64:62 [F] s_b_3_14 = s_b_3_12==s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(insn.sf == insn.N));
    /* ???:4294967295 [F] s_b_3_15 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_16 = s_b_3_11!=s_b_3_15 (const) */
    uint8_t s_b_3_16 = ((uint8_t)(s_b_3_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_17 = s_b_3_14!=s_b_3_15 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(s_b_3_14 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_18 = s_b_3_16&s_b_3_17 (const) */
    uint8_t s_b_3_18 = ((uint8_t)(s_b_3_16 & s_b_3_17));
    /* execute.a64:62 [F] s_b_3_19: If s_b_3_18: Jump b_4 else b_5 (const) */
    if (s_b_3_18) 
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
    /* execute.a64:64 [F] s_b_4_0=sym_21928_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [F] s_b_4_8=sym_21928_3_parameter_inst.sf (const) */
    /* execute.a64:64 [D] s_b_4_9 = (s16)s_b_4_7 */
    auto s_b_4_9 = emitter.truncate(s_b_4_7, emitter.context().types().s16());
    /* execute.a64:64 [D] s_b_4_10 = (s64)s_b_4_9 */
    auto s_b_4_10 = emitter.sx(s_b_4_9, emitter.context().types().s64());
    /* execute.a64:64 [D] s_b_4_11 = (u64)s_b_4_10 */
    auto s_b_4_11 = emitter.reinterpret(s_b_4_10, emitter.context().types().u64());
    /* execute.a64:64 [D] s_b_4_12: sym_127040_3_parameter_value = s_b_4_11, dominates: s_b_24_1 s_b_25_1  */
    emitter.store_local(DV_sym_127040_3_parameter_value, s_b_4_11);
    /* execute.a64:2690 [F] s_b_4_13: If s_b_4_8: Jump b_24 else b_25 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:65 [F] s_b_5_0=sym_21928_3_parameter_inst.immr (const) */
    /* execute.a64:65 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:65 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:65 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.immr) == (uint32_t)0ULL));
    /* execute.a64:65 [F] s_b_5_4=sym_21928_3_parameter_inst.imms (const) */
    /* execute.a64:65 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:65 [F] s_b_5_6 = constant u32 1f (const) */
    /* execute.a64:65 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.imms) == (uint32_t)31ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:65 [F] s_b_5_12=sym_21928_3_parameter_inst.sf (const) */
    /* execute.a64:65 [F] s_b_5_13 = (u32)s_b_5_12 (const) */
    /* execute.a64:65 [F] s_b_5_14 = constant u32 1 (const) */
    /* execute.a64:65 [F] s_b_5_15 = s_b_5_13==s_b_5_14 (const) */
    uint8_t s_b_5_15 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_17 = s_b_5_11!=s_b_5_16 (const) */
    uint8_t s_b_5_17 = ((uint8_t)(s_b_5_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_18 = s_b_5_15!=s_b_5_16 (const) */
    uint8_t s_b_5_18 = ((uint8_t)(s_b_5_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_19 = s_b_5_17&s_b_5_18 (const) */
    uint8_t s_b_5_19 = ((uint8_t)(s_b_5_17 & s_b_5_18));
    /* execute.a64:65 [F] s_b_5_20=sym_21928_3_parameter_inst.N (const) */
    /* execute.a64:65 [F] s_b_5_21 = (u32)s_b_5_20 (const) */
    /* execute.a64:65 [F] s_b_5_22 = constant u32 1 (const) */
    /* execute.a64:65 [F] s_b_5_23 = s_b_5_21==s_b_5_22 (const) */
    uint8_t s_b_5_23 = ((uint8_t)(((uint32_t)insn.N) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_25 = s_b_5_19!=s_b_5_24 (const) */
    uint8_t s_b_5_25 = ((uint8_t)(s_b_5_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_26 = s_b_5_23!=s_b_5_24 (const) */
    uint8_t s_b_5_26 = ((uint8_t)(s_b_5_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_27 = s_b_5_25&s_b_5_26 (const) */
    uint8_t s_b_5_27 = ((uint8_t)(s_b_5_25 & s_b_5_26));
    /* execute.a64:65 [F] s_b_5_28: If s_b_5_27: Jump b_6 else b_7 (const) */
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
    /* execute.a64:67 [F] s_b_6_0=sym_21928_3_parameter_inst.rn (const) */
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
    /* execute.a64:67 [D] s_b_6_8 = (s32)s_b_6_7 */
    auto s_b_6_8 = emitter.truncate(s_b_6_7, emitter.context().types().s32());
    /* execute.a64:67 [D] s_b_6_9 = (s64)s_b_6_8 */
    auto s_b_6_9 = emitter.sx(s_b_6_8, emitter.context().types().s64());
    /* execute.a64:67 [D] s_b_6_10 = (u64)s_b_6_9 */
    auto s_b_6_10 = emitter.reinterpret(s_b_6_9, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_6_11=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_6_12: sym_127413_3_parameter_value = s_b_6_10, dominates: s_b_50_1  */
    emitter.store_local(DV_sym_127413_3_parameter_value, s_b_6_10);
    /* execute.a64:2682 [F] s_b_6_13 = (u32)s_b_6_11 (const) */
    /* execute.a64:2682 [F] s_b_6_14 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_6_15 = s_b_6_13==s_b_6_14 (const) */
    uint8_t s_b_6_15 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_6_16: If s_b_6_15: Jump b_2 else b_50 (const) */
    if (s_b_6_15) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_50;
    }
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:69 [F] s_b_7_0=sym_21928_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_7_1: If s_b_7_0: Jump b_11 else b_13 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_12,  */
  fixed_block_b_8: 
  {
    /* execute.a64:73 [F] s_b_8_0=sym_21928_3_parameter_inst.imms (const) */
    /* execute.a64:73 [F] s_b_8_1=sym_21928_3_parameter_inst.immr (const) */
    /* execute.a64:73 [F] s_b_8_2 = s_b_8_0-s_b_8_1 (const) */
    uint8_t s_b_8_2 = ((uint8_t)(insn.imms - insn.immr));
    /* execute.a64:73 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:73 [F] s_b_8_4 = constant u32 1 (const) */
    /* execute.a64:73 [F] s_b_8_5 = s_b_8_3+s_b_8_4 (const) */
    uint32_t s_b_8_5 = ((uint32_t)(((uint32_t)s_b_8_2) + (uint32_t)1ULL));
    /* execute.a64:73 [F] s_b_8_6 = (u8)s_b_8_5 (const) */
    /* execute.a64:75 [D] s_b_8_7 = sym_22053_0_value uint64_t */
    auto s_b_8_7 = emitter.load_local(DV_sym_22053_0_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_8_8: sym_126920_1_tmp_s_b_10_8 = s_b_8_6 (const), dominates: s_b_15_1  */
    CV_sym_126920_1_tmp_s_b_10_8 = ((uint8_t)s_b_8_5);
    /* ???:4294967295 [D] s_b_8_9: sym_126870_0_replaced_parameter_src = s_b_8_7, dominates: s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_126870_0_replaced_parameter_src, s_b_8_7);
    /* ???:4294967295 [F] s_b_8_10: sym_126886_0_replaced_parameter_len = s_b_8_6 (const), dominates: s_b_16_5  */
    CV_sym_126886_0_replaced_parameter_len = ((uint8_t)s_b_8_5);
    /* execute.a64:2507 [F] s_b_8_11 = (u32)s_b_8_6 (const) */
    /* execute.a64:2507 [F] s_b_8_12 = constant u32 40 (const) */
    /* execute.a64:2507 [F] s_b_8_13 = s_b_8_11>=s_b_8_12 (const) */
    uint8_t s_b_8_13 = ((uint8_t)(((uint32_t)((uint8_t)s_b_8_5)) >= (uint32_t)64ULL));
    /* execute.a64:2507 [F] s_b_8_14: If s_b_8_13: Jump b_14 else b_16 (const) */
    if (s_b_8_13) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_34, b_45,  */
  fixed_block_b_9: 
  {
    /* execute.a64:86 [F] s_b_9_0=sym_21928_3_parameter_inst.sf (const) */
    /* execute.a64:86 [D] s_b_9_1 = sym_22053_0_value uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_22053_0_value, emitter.context().types().u64());
    /* execute.a64:86 [D] s_b_9_2: sym_126931_3_parameter_value = s_b_9_1, dominates: s_b_17_1 s_b_18_1  */
    emitter.store_local(DV_sym_126931_3_parameter_value, s_b_9_1);
    /* execute.a64:2690 [F] s_b_9_3: If s_b_9_0: Jump b_17 else b_18 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_12,  */
  fixed_block_b_10: 
  {
    /* execute.a64:78 [F] s_b_10_0=sym_21928_3_parameter_inst.immr (const) */
    /* execute.a64:78 [F] s_b_10_1 = -s_b_10_0 (const) */
    uint8_t s_b_10_1 = -insn.immr;
    /* execute.a64:78 [F] s_b_10_2=sym_21928_3_parameter_inst.sf (const) */
    /* execute.a64:78 [F] s_b_10_3 = (u32)s_b_10_2 (const) */
    /* execute.a64:78 [F] s_b_10_4 = constant u32 0 (const) */
    /* execute.a64:78 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:78 [F] s_b_10_6 = constant s32 20 (const) */
    /* execute.a64:78 [F] s_b_10_7 = constant s32 40 (const) */
    /* execute.a64:78 [F] s_b_10_8: Select s_b_10_5 ? s_b_10_6 : s_b_10_7 (const) */
    int32_t s_b_10_8 = ((int32_t)(s_b_10_5 ? ((int32_t)32ULL) : ((int32_t)64ULL)));
    /* execute.a64:78 [F] s_b_10_9 = (u32)s_b_10_1 (const) */
    /* execute.a64:78 [F] s_b_10_10 = (u32)s_b_10_8 (const) */
    /* execute.a64:78 [F] s_b_10_11 = s_b_10_9%s_b_10_10 (const) */
    uint32_t s_b_10_11 = ((uint32_t)(((uint32_t)s_b_10_1) % ((uint32_t)s_b_10_8)));
    /* execute.a64:78 [F] s_b_10_12 = (u8)s_b_10_11 (const) */
    /* execute.a64:79 [F] s_b_10_13=sym_21928_3_parameter_inst.imms (const) */
    /* execute.a64:79 [F] s_b_10_14 = (u32)s_b_10_13 (const) */
    /* execute.a64:79 [F] s_b_10_15 = constant u32 1 (const) */
    /* execute.a64:79 [F] s_b_10_16 = s_b_10_14+s_b_10_15 (const) */
    uint32_t s_b_10_16 = ((uint32_t)(((uint32_t)insn.imms) + (uint32_t)1ULL));
    /* execute.a64:79 [F] s_b_10_17 = (u8)s_b_10_16 (const) */
    /* execute.a64:81 [D] s_b_10_18 = sym_22053_0_value uint64_t */
    auto s_b_10_18 = emitter.load_local(DV_sym_22053_0_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_10_19: sym_127000_1_tmp_s_b_12_13 = s_b_10_12 (const), dominates: s_b_20_2  */
    CV_sym_127000_1_tmp_s_b_12_13 = ((uint8_t)s_b_10_11);
    /* ???:4294967295 [F] s_b_10_20: sym_127003_1_tmp_s_b_12_19 = s_b_10_17 (const), dominates: s_b_20_1  */
    CV_sym_127003_1_tmp_s_b_12_19 = ((uint8_t)s_b_10_16);
    /* ???:4294967295 [D] s_b_10_21: sym_126950_0_replaced_parameter_src = s_b_10_18, dominates: s_b_19_0 s_b_21_0  */
    emitter.store_local(DV_sym_126950_0_replaced_parameter_src, s_b_10_18);
    /* ???:4294967295 [F] s_b_10_22: sym_126966_0_replaced_parameter_len = s_b_10_17 (const), dominates: s_b_21_4  */
    CV_sym_126966_0_replaced_parameter_len = ((uint8_t)s_b_10_16);
    /* execute.a64:2507 [F] s_b_10_23 = (u32)s_b_10_17 (const) */
    /* execute.a64:2507 [F] s_b_10_24 = constant u32 40 (const) */
    /* execute.a64:2507 [F] s_b_10_25 = s_b_10_23>=s_b_10_24 (const) */
    uint8_t s_b_10_25 = ((uint8_t)(((uint32_t)((uint8_t)s_b_10_16)) >= (uint32_t)64ULL));
    /* execute.a64:2507 [F] s_b_10_26: If s_b_10_25: Jump b_19 else b_21 (const) */
    if (s_b_10_25) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_7,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2657 [F] s_b_11_0=sym_21928_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2651 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_11_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_11_5 = ReadRegBank 0:s_b_11_0 (u64) */
    auto s_b_11_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_11_6: Select s_b_11_3 ? s_b_11_4 : s_b_11_5 */
    captive::arch::dbt::el::Value *s_b_11_6;
    s_b_11_6 = (s_b_11_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_11_5);
    /* ???:4294967295 [D] s_b_11_7: sym_126837_0_return_symbol = s_b_11_6, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_126837_0_return_symbol, s_b_11_6);
    /* ???:4294967295 [F] s_b_11_8: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11, b_13,  */
  fixed_block_b_12: 
  {
    /* ???:4294967295 [D] s_b_12_0 = sym_126837_0_return_symbol uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_126837_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:69 [D] s_b_12_1: sym_22053_0_value = s_b_12_0, dominates: s_b_8_7 s_b_10_18  */
    emitter.store_local(DV_sym_22053_0_value, s_b_12_0);
    /* execute.a64:71 [F] s_b_12_2=sym_21928_3_parameter_inst.imms (const) */
    /* execute.a64:71 [F] s_b_12_3=sym_21928_3_parameter_inst.immr (const) */
    /* execute.a64:71 [F] s_b_12_4 = s_b_12_2>=s_b_12_3 (const) */
    uint8_t s_b_12_4 = ((uint8_t)(insn.imms >= insn.immr));
    /* execute.a64:71 [F] s_b_12_5: If s_b_12_4: Jump b_8 else b_10 (const) */
    if (s_b_12_4) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_7,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2659 [F] s_b_13_0=sym_21928_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:2646 [F] s_b_13_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_13_5 = ReadRegBank 1:s_b_13_0 (u32) */
    auto s_b_13_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_13_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_13_6: Select s_b_13_3 ? s_b_13_4 : s_b_13_5 */
    captive::arch::dbt::el::Value *s_b_13_6;
    s_b_13_6 = (s_b_13_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_13_5);
    /* execute.a64:2659 [D] s_b_13_7 = (u64)s_b_13_6 */
    auto s_b_13_7 = emitter.zx(s_b_13_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_8: sym_126837_0_return_symbol = s_b_13_7, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_126837_0_return_symbol, s_b_13_7);
    /* ???:4294967295 [F] s_b_13_9: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_8,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2508 [D] s_b_14_0 = sym_126870_0_replaced_parameter_src uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_126870_0_replaced_parameter_src, emitter.context().types().u64());
    /* execute.a64:2508 [F] s_b_14_1=sym_21928_3_parameter_inst.immr (const) */
    /* execute.a64:2508 [F] s_b_14_2 = (u64)s_b_14_1 (const) */
    /* execute.a64:2508 [D] s_b_14_3 = s_b_14_0>>s_b_14_2 */
    auto s_b_14_3 = emitter.shr(s_b_14_0, emitter.const_u64(((uint64_t)insn.immr)));
    /* ???:4294967295 [D] s_b_14_4: sym_126876_0_return_symbol = s_b_14_3, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_126876_0_return_symbol, s_b_14_3);
    /* ???:4294967295 [F] s_b_14_5: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14, b_16,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_126876_0_return_symbol uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_126876_0_return_symbol, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_15_1 = sym_126920_1_tmp_s_b_10_8 (const) uint8_t */
    uint8_t s_b_15_1 = CV_sym_126920_1_tmp_s_b_10_8;
    /* execute.a64:75 [D] s_b_15_2: sym_22053_0_value = s_b_15_0, dominates:  */
    emitter.store_local(DV_sym_22053_0_value, s_b_15_0);
    /* execute.a64:76 [D] s_b_15_3: sym_127094_3_parameter_immz = s_b_15_0, dominates: s_b_26_0 s_b_28_0 s_b_30_0 s_b_32_0 s_b_33_0  */
    emitter.store_local(DV_sym_127094_3_parameter_immz, s_b_15_0);
    /* execute.a64:76 [F] s_b_15_4: sym_127085_3_parameter_bits = s_b_15_1 (const), dominates: s_b_27_0 s_b_29_0 s_b_31_0 s_b_33_2  */
    CV_sym_127085_3_parameter_bits = s_b_15_1;
    /* execute.a64:2776 [F] s_b_15_5 = (u32)s_b_15_1 (const) */
    /* execute.a64:2776 [F] s_b_15_6 = constant u32 8 (const) */
    /* execute.a64:2776 [F] s_b_15_7 = s_b_15_5==s_b_15_6 (const) */
    uint8_t s_b_15_7 = ((uint8_t)(((uint32_t)s_b_15_1) == (uint32_t)8ULL));
    /* execute.a64:2776 [F] s_b_15_8: If s_b_15_7: Jump b_26 else b_27 (const) */
    if (s_b_15_7) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_8,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2510 [D] s_b_16_0 = sym_126870_0_replaced_parameter_src uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_126870_0_replaced_parameter_src, emitter.context().types().u64());
    /* execute.a64:2510 [F] s_b_16_1=sym_21928_3_parameter_inst.immr (const) */
    /* execute.a64:2510 [F] s_b_16_2 = (u64)s_b_16_1 (const) */
    /* execute.a64:2510 [D] s_b_16_3 = s_b_16_0>>s_b_16_2 */
    auto s_b_16_3 = emitter.shr(s_b_16_0, emitter.const_u64(((uint64_t)insn.immr)));
    /* execute.a64:2510 [F] s_b_16_4 = constant u64 1 (const) */
    /* execute.a64:2510 [F] s_b_16_5 = sym_126886_0_replaced_parameter_len (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_126886_0_replaced_parameter_len;
    /* execute.a64:2510 [F] s_b_16_6 = (u64)s_b_16_5 (const) */
    /* execute.a64:2510 [F] s_b_16_7 = s_b_16_4<<s_b_16_6 (const) */
    uint64_t s_b_16_7 = ((uint64_t)((uint64_t)1ULL << ((uint64_t)s_b_16_5)));
    /* execute.a64:2510 [F] s_b_16_8 = constant u64 1 (const) */
    /* execute.a64:2510 [F] s_b_16_9 = s_b_16_7-s_b_16_8 (const) */
    uint64_t s_b_16_9 = ((uint64_t)(s_b_16_7 - (uint64_t)1ULL));
    /* execute.a64:2510 [D] s_b_16_10 = s_b_16_3&s_b_16_9 */
    auto s_b_16_10 = emitter.bitwise_and(s_b_16_3, emitter.const_u64(s_b_16_9));
    /* ???:4294967295 [D] s_b_16_11: sym_126876_0_return_symbol = s_b_16_10, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_126876_0_return_symbol, s_b_16_10);
    /* ???:4294967295 [F] s_b_16_12: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_9,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2691 [F] s_b_17_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_17_1 = sym_126931_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_126931_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_17_2: sym_127187_3_parameter_value = s_b_17_1, dominates: s_b_35_1  */
    emitter.store_local(DV_sym_127187_3_parameter_value, s_b_17_1);
    /* execute.a64:2682 [F] s_b_17_3 = (u32)s_b_17_0 (const) */
    /* execute.a64:2682 [F] s_b_17_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_17_5 = s_b_17_3==s_b_17_4 (const) */
    uint8_t s_b_17_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_17_6: If s_b_17_5: Jump b_2 else b_35 (const) */
    if (s_b_17_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_9,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2693 [F] s_b_18_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_18_1 = sym_126931_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_126931_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_18_2 = (u32)s_b_18_1 */
    auto s_b_18_2 = emitter.truncate(s_b_18_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_18_3 = (u64)s_b_18_2 */
    auto s_b_18_3 = emitter.zx(s_b_18_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_18_4: sym_127209_3_parameter_value = s_b_18_3, dominates: s_b_36_1  */
    emitter.store_local(DV_sym_127209_3_parameter_value, s_b_18_3);
    /* execute.a64:2682 [F] s_b_18_5 = (u32)s_b_18_0 (const) */
    /* execute.a64:2682 [F] s_b_18_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_18_7 = s_b_18_5==s_b_18_6 (const) */
    uint8_t s_b_18_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_18_8: If s_b_18_7: Jump b_2 else b_36 (const) */
    if (s_b_18_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_36;
    }
  }
  /* b_10,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2508 [D] s_b_19_0 = sym_126950_0_replaced_parameter_src uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_126950_0_replaced_parameter_src, emitter.context().types().u64());
    /* execute.a64:2508 [F] s_b_19_1 = constant u64 0 (const) */
    /* execute.a64:2508 [D] s_b_19_2 = s_b_19_0>>s_b_19_1 */
    auto s_b_19_2 = emitter.shr(s_b_19_0, emitter.const_u64((uint64_t)0ULL));
    /* ???:4294967295 [D] s_b_19_3: sym_126956_0_return_symbol = s_b_19_2, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_126956_0_return_symbol, s_b_19_2);
    /* ???:4294967295 [F] s_b_19_4: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_19, b_21,  */
  fixed_block_b_20: 
  {
    /* ???:4294967295 [D] s_b_20_0 = sym_126956_0_return_symbol uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_126956_0_return_symbol, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_20_1 = sym_127003_1_tmp_s_b_12_19 (const) uint8_t */
    uint8_t s_b_20_1 = CV_sym_127003_1_tmp_s_b_12_19;
    /* ???:4294967295 [F] s_b_20_2 = sym_127000_1_tmp_s_b_12_13 (const) uint8_t */
    uint8_t s_b_20_2 = CV_sym_127000_1_tmp_s_b_12_13;
    /* execute.a64:81 [D] s_b_20_3: sym_22053_0_value = s_b_20_0, dominates:  */
    emitter.store_local(DV_sym_22053_0_value, s_b_20_0);
    /* execute.a64:82 [D] s_b_20_4: sym_127229_3_parameter_immz = s_b_20_0, dominates: s_b_37_0 s_b_39_0 s_b_41_0 s_b_43_0 s_b_44_0  */
    emitter.store_local(DV_sym_127229_3_parameter_immz, s_b_20_0);
    /* execute.a64:82 [F] s_b_20_5: sym_127220_3_parameter_bits = s_b_20_1 (const), dominates: s_b_38_0 s_b_40_0 s_b_42_0 s_b_44_2  */
    CV_sym_127220_3_parameter_bits = s_b_20_1;
    /* ???:4294967295 [F] s_b_20_6: sym_127310_1_tmp_s_b_47_1 = s_b_20_2 (const), dominates: s_b_45_0  */
    CV_sym_127310_1_tmp_s_b_47_1 = s_b_20_2;
    /* execute.a64:2776 [F] s_b_20_7 = (u32)s_b_20_1 (const) */
    /* execute.a64:2776 [F] s_b_20_8 = constant u32 8 (const) */
    /* execute.a64:2776 [F] s_b_20_9 = s_b_20_7==s_b_20_8 (const) */
    uint8_t s_b_20_9 = ((uint8_t)(((uint32_t)s_b_20_1) == (uint32_t)8ULL));
    /* execute.a64:2776 [F] s_b_20_10: If s_b_20_9: Jump b_37 else b_38 (const) */
    if (s_b_20_9) 
    {
      goto fixed_block_b_37;
    }
    else 
    {
      goto fixed_block_b_38;
    }
  }
  /* b_10,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2510 [D] s_b_21_0 = sym_126950_0_replaced_parameter_src uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_126950_0_replaced_parameter_src, emitter.context().types().u64());
    /* execute.a64:2510 [F] s_b_21_1 = constant u64 0 (const) */
    /* execute.a64:2510 [D] s_b_21_2 = s_b_21_0>>s_b_21_1 */
    auto s_b_21_2 = emitter.shr(s_b_21_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2510 [F] s_b_21_3 = constant u64 1 (const) */
    /* execute.a64:2510 [F] s_b_21_4 = sym_126966_0_replaced_parameter_len (const) uint8_t */
    uint8_t s_b_21_4 = CV_sym_126966_0_replaced_parameter_len;
    /* execute.a64:2510 [F] s_b_21_5 = (u64)s_b_21_4 (const) */
    /* execute.a64:2510 [F] s_b_21_6 = s_b_21_3<<s_b_21_5 (const) */
    uint64_t s_b_21_6 = ((uint64_t)((uint64_t)1ULL << ((uint64_t)s_b_21_4)));
    /* execute.a64:2510 [F] s_b_21_7 = constant u64 1 (const) */
    /* execute.a64:2510 [F] s_b_21_8 = s_b_21_6-s_b_21_7 (const) */
    uint64_t s_b_21_8 = ((uint64_t)(s_b_21_6 - (uint64_t)1ULL));
    /* execute.a64:2510 [D] s_b_21_9 = s_b_21_2&s_b_21_8 */
    auto s_b_21_9 = emitter.bitwise_and(s_b_21_2, emitter.const_u64(s_b_21_8));
    /* ???:4294967295 [D] s_b_21_10: sym_126956_0_return_symbol = s_b_21_9, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_126956_0_return_symbol, s_b_21_9);
    /* ???:4294967295 [F] s_b_21_11: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_1,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2691 [F] s_b_22_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_22_1 = sym_127014_3_parameter_value uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_127014_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_22_2: sym_127325_3_parameter_value = s_b_22_1, dominates: s_b_46_1  */
    emitter.store_local(DV_sym_127325_3_parameter_value, s_b_22_1);
    /* execute.a64:2682 [F] s_b_22_3 = (u32)s_b_22_0 (const) */
    /* execute.a64:2682 [F] s_b_22_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_22_5 = s_b_22_3==s_b_22_4 (const) */
    uint8_t s_b_22_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_22_6: If s_b_22_5: Jump b_2 else b_46 (const) */
    if (s_b_22_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_46;
    }
  }
  /* b_1,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2693 [F] s_b_23_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_23_1 = sym_127014_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_127014_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_23_2 = (u32)s_b_23_1 */
    auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_23_3 = (u64)s_b_23_2 */
    auto s_b_23_3 = emitter.zx(s_b_23_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_23_4: sym_127347_3_parameter_value = s_b_23_3, dominates: s_b_47_1  */
    emitter.store_local(DV_sym_127347_3_parameter_value, s_b_23_3);
    /* execute.a64:2682 [F] s_b_23_5 = (u32)s_b_23_0 (const) */
    /* execute.a64:2682 [F] s_b_23_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_23_7 = s_b_23_5==s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_23_8: If s_b_23_7: Jump b_2 else b_47 (const) */
    if (s_b_23_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_47;
    }
  }
  /* b_4,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2691 [F] s_b_24_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_24_1 = sym_127040_3_parameter_value uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_127040_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_24_2: sym_127369_3_parameter_value = s_b_24_1, dominates: s_b_48_1  */
    emitter.store_local(DV_sym_127369_3_parameter_value, s_b_24_1);
    /* execute.a64:2682 [F] s_b_24_3 = (u32)s_b_24_0 (const) */
    /* execute.a64:2682 [F] s_b_24_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_24_5 = s_b_24_3==s_b_24_4 (const) */
    uint8_t s_b_24_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_24_6: If s_b_24_5: Jump b_2 else b_48 (const) */
    if (s_b_24_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_48;
    }
  }
  /* b_4,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2693 [F] s_b_25_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_25_1 = sym_127040_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_127040_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_25_2 = (u32)s_b_25_1 */
    auto s_b_25_2 = emitter.truncate(s_b_25_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_25_3 = (u64)s_b_25_2 */
    auto s_b_25_3 = emitter.zx(s_b_25_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_25_4: sym_127391_3_parameter_value = s_b_25_3, dominates: s_b_49_1  */
    emitter.store_local(DV_sym_127391_3_parameter_value, s_b_25_3);
    /* execute.a64:2682 [F] s_b_25_5 = (u32)s_b_25_0 (const) */
    /* execute.a64:2682 [F] s_b_25_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_25_7 = s_b_25_5==s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_25_8: If s_b_25_7: Jump b_2 else b_49 (const) */
    if (s_b_25_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_49;
    }
  }
  /* b_15,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2777 [D] s_b_26_0 = sym_127094_3_parameter_immz uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_127094_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2777 [D] s_b_26_1 = (s8)s_b_26_0 */
    auto s_b_26_1 = emitter.truncate(s_b_26_0, emitter.context().types().s8());
    /* execute.a64:2777 [D] s_b_26_2 = (s64)s_b_26_1 */
    auto s_b_26_2 = emitter.sx(s_b_26_1, emitter.context().types().s64());
    /* execute.a64:2777 [D] s_b_26_3: sym_127161_1__R_s_b_37_5 = s_b_26_2, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_127161_1__R_s_b_37_5, s_b_26_2);
    /* execute.a64:2777 [F] s_b_26_4: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_15,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2778 [F] s_b_27_0 = sym_127085_3_parameter_bits (const) uint8_t */
    uint8_t s_b_27_0 = CV_sym_127085_3_parameter_bits;
    /* execute.a64:2778 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
    /* execute.a64:2778 [F] s_b_27_2 = constant u32 10 (const) */
    /* execute.a64:2778 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(((uint32_t)s_b_27_0) == (uint32_t)16ULL));
    /* execute.a64:2778 [F] s_b_27_4: If s_b_27_3: Jump b_28 else b_29 (const) */
    if (s_b_27_3) 
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
    /* execute.a64:2779 [D] s_b_28_0 = sym_127094_3_parameter_immz uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_127094_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2779 [D] s_b_28_1 = (s16)s_b_28_0 */
    auto s_b_28_1 = emitter.truncate(s_b_28_0, emitter.context().types().s16());
    /* execute.a64:2779 [D] s_b_28_2 = (s64)s_b_28_1 */
    auto s_b_28_2 = emitter.sx(s_b_28_1, emitter.context().types().s64());
    /* execute.a64:2779 [D] s_b_28_3: sym_127161_1__R_s_b_37_5 = s_b_28_2, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_127161_1__R_s_b_37_5, s_b_28_2);
    /* execute.a64:2779 [F] s_b_28_4: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_27,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2780 [F] s_b_29_0 = sym_127085_3_parameter_bits (const) uint8_t */
    uint8_t s_b_29_0 = CV_sym_127085_3_parameter_bits;
    /* execute.a64:2780 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
    /* execute.a64:2780 [F] s_b_29_2 = constant u32 20 (const) */
    /* execute.a64:2780 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(((uint32_t)s_b_29_0) == (uint32_t)32ULL));
    /* execute.a64:2780 [F] s_b_29_4: If s_b_29_3: Jump b_30 else b_31 (const) */
    if (s_b_29_3) 
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
    /* execute.a64:2781 [D] s_b_30_0 = sym_127094_3_parameter_immz uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_127094_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_30_1 = (s32)s_b_30_0 */
    auto s_b_30_1 = emitter.truncate(s_b_30_0, emitter.context().types().s32());
    /* execute.a64:2781 [D] s_b_30_2 = (s64)s_b_30_1 */
    auto s_b_30_2 = emitter.sx(s_b_30_1, emitter.context().types().s64());
    /* execute.a64:2781 [D] s_b_30_3: sym_127161_1__R_s_b_37_5 = s_b_30_2, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_127161_1__R_s_b_37_5, s_b_30_2);
    /* execute.a64:2781 [F] s_b_30_4: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_29,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2782 [F] s_b_31_0 = sym_127085_3_parameter_bits (const) uint8_t */
    uint8_t s_b_31_0 = CV_sym_127085_3_parameter_bits;
    /* execute.a64:2782 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
    /* execute.a64:2782 [F] s_b_31_2 = constant u32 40 (const) */
    /* execute.a64:2782 [F] s_b_31_3 = s_b_31_1==s_b_31_2 (const) */
    uint8_t s_b_31_3 = ((uint8_t)(((uint32_t)s_b_31_0) == (uint32_t)64ULL));
    /* execute.a64:2782 [F] s_b_31_4: If s_b_31_3: Jump b_32 else b_33 (const) */
    if (s_b_31_3) 
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
    /* execute.a64:2783 [D] s_b_32_0 = sym_127094_3_parameter_immz uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_127094_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_32_1 = (s64)s_b_32_0 */
    auto s_b_32_1 = emitter.reinterpret(s_b_32_0, emitter.context().types().s64());
    /* execute.a64:2783 [D] s_b_32_2: sym_127161_1__R_s_b_37_5 = s_b_32_1, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_127161_1__R_s_b_37_5, s_b_32_1);
    /* execute.a64:2783 [F] s_b_32_3: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_31,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2785 [D] s_b_33_0 = sym_127094_3_parameter_immz uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_127094_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2785 [D] s_b_33_1 = (s64)s_b_33_0 */
    auto s_b_33_1 = emitter.reinterpret(s_b_33_0, emitter.context().types().s64());
    /* execute.a64:2785 [F] s_b_33_2 = sym_127085_3_parameter_bits (const) uint8_t */
    uint8_t s_b_33_2 = CV_sym_127085_3_parameter_bits;
    /* execute.a64:2785 [F] s_b_33_3 = constant u32 40 (const) */
    /* execute.a64:2785 [F] s_b_33_4 = (u32)s_b_33_2 (const) */
    /* execute.a64:2785 [F] s_b_33_5 = s_b_33_3-s_b_33_4 (const) */
    uint32_t s_b_33_5 = ((uint32_t)((uint32_t)64ULL - ((uint32_t)s_b_33_2)));
    /* execute.a64:2785 [F] s_b_33_6 = (s64)s_b_33_5 (const) */
    /* execute.a64:2785 [D] s_b_33_7 = s_b_33_1<<s_b_33_6 */
    auto s_b_33_7 = emitter.shl(s_b_33_1, emitter.const_s64(((int64_t)s_b_33_5)));
    /* execute.a64:2785 [D] s_b_33_8 = (s64)s_b_33_7 */
    auto s_b_33_8 = (captive::arch::dbt::el::Value *)s_b_33_7;
    /* execute.a64:2785 [F] s_b_33_9 = constant u32 40 (const) */
    /* execute.a64:2785 [F] s_b_33_10 = (u32)s_b_33_2 (const) */
    /* execute.a64:2785 [F] s_b_33_11 = s_b_33_9-s_b_33_10 (const) */
    uint32_t s_b_33_11 = ((uint32_t)((uint32_t)64ULL - ((uint32_t)s_b_33_2)));
    /* execute.a64:2785 [F] s_b_33_12 = (s64)s_b_33_11 (const) */
    /* execute.a64:2785 [D] s_b_33_13 = s_b_33_8->>s_b_33_12 */
    auto s_b_33_13 = emitter.sar(s_b_33_8, emitter.const_s64(((int64_t)s_b_33_11)));
    /* execute.a64:2785 [D] s_b_33_14: sym_127161_1__R_s_b_37_5 = s_b_33_13, dominates: s_b_34_0  */
    emitter.store_local(DV_sym_127161_1__R_s_b_37_5, s_b_33_13);
    /* execute.a64:2785 [F] s_b_33_15: Jump b_34 (const) */
    goto fixed_block_b_34;
  }
  /* b_26, b_28, b_30, b_32, b_33,  */
  fixed_block_b_34: 
  {
    /* execute.a64:76 [D] s_b_34_0 = sym_127161_1__R_s_b_37_5 int64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_127161_1__R_s_b_37_5, emitter.context().types().s64());
    /* execute.a64:76 [D] s_b_34_1 = (u64)s_b_34_0 */
    auto s_b_34_1 = emitter.reinterpret(s_b_34_0, emitter.context().types().u64());
    /* execute.a64:76 [D] s_b_34_2: sym_22053_0_value = s_b_34_1, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_22053_0_value, s_b_34_1);
    /* execute.a64:72 [F] s_b_34_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_17,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2684 [F] s_b_35_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_35_1 = sym_127187_3_parameter_value uint64_t */
    auto s_b_35_1 = emitter.load_local(DV_sym_127187_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_35_2: WriteRegBank 0:s_b_35_0 = s_b_35_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_35_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_35_1);
    /* execute.a64:0 [F] s_b_35_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_18,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2684 [F] s_b_36_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_36_1 = sym_127209_3_parameter_value uint64_t */
    auto s_b_36_1 = emitter.load_local(DV_sym_127209_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_36_2: WriteRegBank 0:s_b_36_0 = s_b_36_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_36_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_36_1);
    /* execute.a64:0 [F] s_b_36_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_20,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2777 [D] s_b_37_0 = sym_127229_3_parameter_immz uint64_t */
    auto s_b_37_0 = emitter.load_local(DV_sym_127229_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2777 [D] s_b_37_1 = (s8)s_b_37_0 */
    auto s_b_37_1 = emitter.truncate(s_b_37_0, emitter.context().types().s8());
    /* execute.a64:2777 [D] s_b_37_2 = (s64)s_b_37_1 */
    auto s_b_37_2 = emitter.sx(s_b_37_1, emitter.context().types().s64());
    /* execute.a64:2777 [D] s_b_37_3: sym_127296_1__R_s_b_47_6 = s_b_37_2, dominates: s_b_45_1  */
    emitter.store_local(DV_sym_127296_1__R_s_b_47_6, s_b_37_2);
    /* execute.a64:2777 [F] s_b_37_4: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_20,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2778 [F] s_b_38_0 = sym_127220_3_parameter_bits (const) uint8_t */
    uint8_t s_b_38_0 = CV_sym_127220_3_parameter_bits;
    /* execute.a64:2778 [F] s_b_38_1 = (u32)s_b_38_0 (const) */
    /* execute.a64:2778 [F] s_b_38_2 = constant u32 10 (const) */
    /* execute.a64:2778 [F] s_b_38_3 = s_b_38_1==s_b_38_2 (const) */
    uint8_t s_b_38_3 = ((uint8_t)(((uint32_t)s_b_38_0) == (uint32_t)16ULL));
    /* execute.a64:2778 [F] s_b_38_4: If s_b_38_3: Jump b_39 else b_40 (const) */
    if (s_b_38_3) 
    {
      goto fixed_block_b_39;
    }
    else 
    {
      goto fixed_block_b_40;
    }
  }
  /* b_38,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2779 [D] s_b_39_0 = sym_127229_3_parameter_immz uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_127229_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2779 [D] s_b_39_1 = (s16)s_b_39_0 */
    auto s_b_39_1 = emitter.truncate(s_b_39_0, emitter.context().types().s16());
    /* execute.a64:2779 [D] s_b_39_2 = (s64)s_b_39_1 */
    auto s_b_39_2 = emitter.sx(s_b_39_1, emitter.context().types().s64());
    /* execute.a64:2779 [D] s_b_39_3: sym_127296_1__R_s_b_47_6 = s_b_39_2, dominates: s_b_45_1  */
    emitter.store_local(DV_sym_127296_1__R_s_b_47_6, s_b_39_2);
    /* execute.a64:2779 [F] s_b_39_4: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_38,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2780 [F] s_b_40_0 = sym_127220_3_parameter_bits (const) uint8_t */
    uint8_t s_b_40_0 = CV_sym_127220_3_parameter_bits;
    /* execute.a64:2780 [F] s_b_40_1 = (u32)s_b_40_0 (const) */
    /* execute.a64:2780 [F] s_b_40_2 = constant u32 20 (const) */
    /* execute.a64:2780 [F] s_b_40_3 = s_b_40_1==s_b_40_2 (const) */
    uint8_t s_b_40_3 = ((uint8_t)(((uint32_t)s_b_40_0) == (uint32_t)32ULL));
    /* execute.a64:2780 [F] s_b_40_4: If s_b_40_3: Jump b_41 else b_42 (const) */
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
    /* execute.a64:2781 [D] s_b_41_0 = sym_127229_3_parameter_immz uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_127229_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_41_1 = (s32)s_b_41_0 */
    auto s_b_41_1 = emitter.truncate(s_b_41_0, emitter.context().types().s32());
    /* execute.a64:2781 [D] s_b_41_2 = (s64)s_b_41_1 */
    auto s_b_41_2 = emitter.sx(s_b_41_1, emitter.context().types().s64());
    /* execute.a64:2781 [D] s_b_41_3: sym_127296_1__R_s_b_47_6 = s_b_41_2, dominates: s_b_45_1  */
    emitter.store_local(DV_sym_127296_1__R_s_b_47_6, s_b_41_2);
    /* execute.a64:2781 [F] s_b_41_4: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_40,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2782 [F] s_b_42_0 = sym_127220_3_parameter_bits (const) uint8_t */
    uint8_t s_b_42_0 = CV_sym_127220_3_parameter_bits;
    /* execute.a64:2782 [F] s_b_42_1 = (u32)s_b_42_0 (const) */
    /* execute.a64:2782 [F] s_b_42_2 = constant u32 40 (const) */
    /* execute.a64:2782 [F] s_b_42_3 = s_b_42_1==s_b_42_2 (const) */
    uint8_t s_b_42_3 = ((uint8_t)(((uint32_t)s_b_42_0) == (uint32_t)64ULL));
    /* execute.a64:2782 [F] s_b_42_4: If s_b_42_3: Jump b_43 else b_44 (const) */
    if (s_b_42_3) 
    {
      goto fixed_block_b_43;
    }
    else 
    {
      goto fixed_block_b_44;
    }
  }
  /* b_42,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2783 [D] s_b_43_0 = sym_127229_3_parameter_immz uint64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_127229_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_43_1 = (s64)s_b_43_0 */
    auto s_b_43_1 = emitter.reinterpret(s_b_43_0, emitter.context().types().s64());
    /* execute.a64:2783 [D] s_b_43_2: sym_127296_1__R_s_b_47_6 = s_b_43_1, dominates: s_b_45_1  */
    emitter.store_local(DV_sym_127296_1__R_s_b_47_6, s_b_43_1);
    /* execute.a64:2783 [F] s_b_43_3: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_42,  */
  fixed_block_b_44: 
  {
    /* execute.a64:2785 [D] s_b_44_0 = sym_127229_3_parameter_immz uint64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_127229_3_parameter_immz, emitter.context().types().u64());
    /* execute.a64:2785 [D] s_b_44_1 = (s64)s_b_44_0 */
    auto s_b_44_1 = emitter.reinterpret(s_b_44_0, emitter.context().types().s64());
    /* execute.a64:2785 [F] s_b_44_2 = sym_127220_3_parameter_bits (const) uint8_t */
    uint8_t s_b_44_2 = CV_sym_127220_3_parameter_bits;
    /* execute.a64:2785 [F] s_b_44_3 = constant u32 40 (const) */
    /* execute.a64:2785 [F] s_b_44_4 = (u32)s_b_44_2 (const) */
    /* execute.a64:2785 [F] s_b_44_5 = s_b_44_3-s_b_44_4 (const) */
    uint32_t s_b_44_5 = ((uint32_t)((uint32_t)64ULL - ((uint32_t)s_b_44_2)));
    /* execute.a64:2785 [F] s_b_44_6 = (s64)s_b_44_5 (const) */
    /* execute.a64:2785 [D] s_b_44_7 = s_b_44_1<<s_b_44_6 */
    auto s_b_44_7 = emitter.shl(s_b_44_1, emitter.const_s64(((int64_t)s_b_44_5)));
    /* execute.a64:2785 [D] s_b_44_8 = (s64)s_b_44_7 */
    auto s_b_44_8 = (captive::arch::dbt::el::Value *)s_b_44_7;
    /* execute.a64:2785 [F] s_b_44_9 = constant u32 40 (const) */
    /* execute.a64:2785 [F] s_b_44_10 = (u32)s_b_44_2 (const) */
    /* execute.a64:2785 [F] s_b_44_11 = s_b_44_9-s_b_44_10 (const) */
    uint32_t s_b_44_11 = ((uint32_t)((uint32_t)64ULL - ((uint32_t)s_b_44_2)));
    /* execute.a64:2785 [F] s_b_44_12 = (s64)s_b_44_11 (const) */
    /* execute.a64:2785 [D] s_b_44_13 = s_b_44_8->>s_b_44_12 */
    auto s_b_44_13 = emitter.sar(s_b_44_8, emitter.const_s64(((int64_t)s_b_44_11)));
    /* execute.a64:2785 [D] s_b_44_14: sym_127296_1__R_s_b_47_6 = s_b_44_13, dominates: s_b_45_1  */
    emitter.store_local(DV_sym_127296_1__R_s_b_47_6, s_b_44_13);
    /* execute.a64:2785 [F] s_b_44_15: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_37, b_39, b_41, b_43, b_44,  */
  fixed_block_b_45: 
  {
    /* ???:4294967295 [F] s_b_45_0 = sym_127310_1_tmp_s_b_47_1 (const) uint8_t */
    uint8_t s_b_45_0 = CV_sym_127310_1_tmp_s_b_47_1;
    /* execute.a64:82 [D] s_b_45_1 = sym_127296_1__R_s_b_47_6 int64_t */
    auto s_b_45_1 = emitter.load_local(DV_sym_127296_1__R_s_b_47_6, emitter.context().types().s64());
    /* execute.a64:82 [D] s_b_45_2 = (u64)s_b_45_1 */
    auto s_b_45_2 = emitter.reinterpret(s_b_45_1, emitter.context().types().u64());
    /* execute.a64:82 [D] s_b_45_3: sym_22053_0_value = s_b_45_2, dominates:  */
    emitter.store_local(DV_sym_22053_0_value, s_b_45_2);
    /* ???:4294967295 [F] s_b_45_4 = (u64)s_b_45_0 (const) */
    /* ???:4294967295 [D] s_b_45_5 = s_b_45_2<<s_b_45_4 */
    auto s_b_45_5 = emitter.shl(s_b_45_2, emitter.const_u64(((uint64_t)s_b_45_0)));
    /* execute.a64:83 [D] s_b_45_6: sym_22053_0_value = s_b_45_5, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_22053_0_value, s_b_45_5);
    /* execute.a64:78 [F] s_b_45_7: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_22,  */
  fixed_block_b_46: 
  {
    /* execute.a64:2684 [F] s_b_46_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_46_1 = sym_127325_3_parameter_value uint64_t */
    auto s_b_46_1 = emitter.load_local(DV_sym_127325_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_46_2: WriteRegBank 0:s_b_46_0 = s_b_46_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_46_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_46_1);
    /* execute.a64:0 [F] s_b_46_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_23,  */
  fixed_block_b_47: 
  {
    /* execute.a64:2684 [F] s_b_47_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_47_1 = sym_127347_3_parameter_value uint64_t */
    auto s_b_47_1 = emitter.load_local(DV_sym_127347_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_47_2: WriteRegBank 0:s_b_47_0 = s_b_47_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_47_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_47_1);
    /* execute.a64:0 [F] s_b_47_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_24,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2684 [F] s_b_48_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_48_1 = sym_127369_3_parameter_value uint64_t */
    auto s_b_48_1 = emitter.load_local(DV_sym_127369_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_48_2: WriteRegBank 0:s_b_48_0 = s_b_48_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_48_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_48_1);
    /* execute.a64:0 [F] s_b_48_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_25,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2684 [F] s_b_49_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_49_1 = sym_127391_3_parameter_value uint64_t */
    auto s_b_49_1 = emitter.load_local(DV_sym_127391_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_49_2: WriteRegBank 0:s_b_49_0 = s_b_49_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_49_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_49_1);
    /* execute.a64:0 [F] s_b_49_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_50: 
  {
    /* execute.a64:2684 [F] s_b_50_0=sym_21928_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_50_1 = sym_127413_3_parameter_value uint64_t */
    auto s_b_50_1 = emitter.load_local(DV_sym_127413_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_50_2: WriteRegBank 0:s_b_50_0 = s_b_50_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_50_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_50_1);
    /* execute.a64:0 [F] s_b_50_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_smaxv(const aarch64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_22868_0_rn = emitter.alloc_local(emitter.context().types().v8s8(), true);
  auto DV_sym_22874_0_min = emitter.alloc_local(emitter.context().types().s8(), true);
  auto DV_sym_23007_0_rn = emitter.alloc_local(emitter.context().types().v16s8(), true);
  auto DV_sym_23013_0_min = emitter.alloc_local(emitter.context().types().s8(), true);
  auto DV_sym_23282_0_rn = emitter.alloc_local(emitter.context().types().v4s16(), true);
  auto DV_sym_23288_0_min = emitter.alloc_local(emitter.context().types().s16(), true);
  auto DV_sym_23353_0_rn = emitter.alloc_local(emitter.context().types().v8s16(), true);
  auto DV_sym_23359_0_min = emitter.alloc_local(emitter.context().types().s16(), true);
  auto DV_sym_23492_0_rn = emitter.alloc_local(emitter.context().types().v4s32(), true);
  auto DV_sym_23498_0_min = emitter.alloc_local(emitter.context().types().s32(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:87 [F] s_b_0_0=sym_22860_3_parameter_inst.arrangement (const) */
    /* execute.simd:88 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:101 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:114 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:127 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:140 [F] s_b_0_5 = constant s32 5 (const) */
    /* execute.simd:87 [F] s_b_0_6: Switch s_b_0_0: < <todo> > def b_77 (const) -> b_2, b_17, b_48, b_55, b_70, b_77,  */
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
    /* execute.simd:89 [F] s_b_2_0=sym_22860_3_parameter_inst.rn (const) */
    /* execute.simd:89 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:89 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:89 [D] s_b_2_3: sym_22868_0_rn = s_b_2_2, dominates: s_b_3_0 s_b_4_0 s_b_5_0 s_b_6_0 s_b_7_0 s_b_8_0 s_b_9_0 s_b_10_0 s_b_11_0 s_b_12_0 s_b_13_0 s_b_14_0 s_b_15_0  */
    emitter.store_local(DV_sym_22868_0_rn, s_b_2_2);
    /* execute.simd:91 [F] s_b_2_4 = constant s32 0 (const) */
    /* execute.simd:91 [D] s_b_2_2[s_b_2_4] */
    auto s_b_2_5 = emitter.vector_extract(s_b_2_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:91 [D] s_b_2_6: sym_22874_0_min = s_b_2_5, dominates: s_b_4_3 s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
    emitter.store_local(DV_sym_22874_0_min, s_b_2_5);
    /* ???:4294967295 [F] s_b_2_7 = constant u8 1 (const) */
    /* execute.simd:93 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:93 [D] s_b_2_9 = s_b_2_8>s_b_2_5 */
    auto s_b_2_9 = emitter.cmp_gt(s_b_2_8, s_b_2_5);
    /* execute.simd:93 [D] s_b_2_10: If s_b_2_9: Jump b_3 else b_4 */
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
    /* execute.simd:102 [F] s_b_17_0=sym_22860_3_parameter_inst.rn (const) */
    /* execute.simd:102 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:102 [D] s_b_17_2 = (v16s8)s_b_17_1 */
    auto s_b_17_2 = emitter.reinterpret(s_b_17_1, emitter.context().types().v16s8());
    /* execute.simd:102 [D] s_b_17_3: sym_23007_0_rn = s_b_17_2, dominates: s_b_18_0 s_b_19_0 s_b_20_0 s_b_21_0 s_b_22_0 s_b_23_0 s_b_24_0 s_b_25_0 s_b_26_0 s_b_27_0 s_b_28_0 s_b_29_0 s_b_30_0 s_b_31_0 s_b_32_0 s_b_33_0 s_b_34_0 s_b_35_0 s_b_36_0 s_b_37_0 s_b_38_0 s_b_39_0 s_b_40_0 s_b_41_0 s_b_42_0 s_b_43_0 s_b_44_0 s_b_45_0 s_b_46_0  */
    emitter.store_local(DV_sym_23007_0_rn, s_b_17_2);
    /* execute.simd:104 [F] s_b_17_4 = constant s32 0 (const) */
    /* execute.simd:104 [D] s_b_17_2[s_b_17_4] */
    auto s_b_17_5 = emitter.vector_extract(s_b_17_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:104 [D] s_b_17_6: sym_23013_0_min = s_b_17_5, dominates: s_b_19_3 s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
    emitter.store_local(DV_sym_23013_0_min, s_b_17_5);
    /* ???:4294967295 [F] s_b_17_7 = constant u8 1 (const) */
    /* execute.simd:106 [D] s_b_17_2[s_b_17_7] */
    auto s_b_17_8 = emitter.vector_extract(s_b_17_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:106 [D] s_b_17_9 = s_b_17_8>s_b_17_5 */
    auto s_b_17_9 = emitter.cmp_gt(s_b_17_8, s_b_17_5);
    /* execute.simd:106 [D] s_b_17_10: If s_b_17_9: Jump b_18 else b_19 */
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
    /* execute.simd:115 [F] s_b_48_0=sym_22860_3_parameter_inst.rn (const) */
    /* execute.simd:115 [D] s_b_48_1 = ReadRegBank 17:s_b_48_0 (v4u16) */
    auto s_b_48_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_48_1,emitter.const_u8(8));
    }
    /* execute.simd:115 [D] s_b_48_2 = (v4s16)s_b_48_1 */
    auto s_b_48_2 = emitter.reinterpret(s_b_48_1, emitter.context().types().v4s16());
    /* execute.simd:115 [D] s_b_48_3: sym_23282_0_rn = s_b_48_2, dominates: s_b_49_0 s_b_50_0 s_b_51_0 s_b_52_0 s_b_53_0  */
    emitter.store_local(DV_sym_23282_0_rn, s_b_48_2);
    /* execute.simd:117 [F] s_b_48_4 = constant s32 0 (const) */
    /* execute.simd:117 [D] s_b_48_2[s_b_48_4] */
    auto s_b_48_5 = emitter.vector_extract(s_b_48_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:117 [D] s_b_48_6: sym_23288_0_min = s_b_48_5, dominates: s_b_50_3 s_b_52_3 s_b_54_1  */
    emitter.store_local(DV_sym_23288_0_min, s_b_48_5);
    /* ???:4294967295 [F] s_b_48_7 = constant u8 1 (const) */
    /* execute.simd:119 [D] s_b_48_2[s_b_48_7] */
    auto s_b_48_8 = emitter.vector_extract(s_b_48_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:119 [D] s_b_48_9 = s_b_48_8>s_b_48_5 */
    auto s_b_48_9 = emitter.cmp_gt(s_b_48_8, s_b_48_5);
    /* execute.simd:119 [D] s_b_48_10: If s_b_48_9: Jump b_49 else b_50 */
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
    /* execute.simd:128 [F] s_b_55_0=sym_22860_3_parameter_inst.rn (const) */
    /* execute.simd:128 [D] s_b_55_1 = ReadRegBank 18:s_b_55_0 (v8u16) */
    auto s_b_55_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_55_1,emitter.const_u8(16));
    }
    /* execute.simd:128 [D] s_b_55_2 = (v8s16)s_b_55_1 */
    auto s_b_55_2 = emitter.reinterpret(s_b_55_1, emitter.context().types().v8s16());
    /* execute.simd:128 [D] s_b_55_3: sym_23353_0_rn = s_b_55_2, dominates: s_b_56_0 s_b_57_0 s_b_58_0 s_b_59_0 s_b_60_0 s_b_61_0 s_b_62_0 s_b_63_0 s_b_64_0 s_b_65_0 s_b_66_0 s_b_67_0 s_b_68_0  */
    emitter.store_local(DV_sym_23353_0_rn, s_b_55_2);
    /* execute.simd:130 [F] s_b_55_4 = constant s32 0 (const) */
    /* execute.simd:130 [D] s_b_55_2[s_b_55_4] */
    auto s_b_55_5 = emitter.vector_extract(s_b_55_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:130 [D] s_b_55_6: sym_23359_0_min = s_b_55_5, dominates: s_b_57_3 s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
    emitter.store_local(DV_sym_23359_0_min, s_b_55_5);
    /* ???:4294967295 [F] s_b_55_7 = constant u8 1 (const) */
    /* execute.simd:132 [D] s_b_55_2[s_b_55_7] */
    auto s_b_55_8 = emitter.vector_extract(s_b_55_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:132 [D] s_b_55_9 = s_b_55_8>s_b_55_5 */
    auto s_b_55_9 = emitter.cmp_gt(s_b_55_8, s_b_55_5);
    /* execute.simd:132 [D] s_b_55_10: If s_b_55_9: Jump b_56 else b_57 */
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
    /* execute.simd:141 [F] s_b_70_0=sym_22860_3_parameter_inst.rn (const) */
    /* execute.simd:141 [D] s_b_70_1 = ReadRegBank 20:s_b_70_0 (v4u32) */
    auto s_b_70_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_70_1,emitter.const_u8(16));
    }
    /* execute.simd:141 [D] s_b_70_2 = (v4s32)s_b_70_1 */
    auto s_b_70_2 = emitter.reinterpret(s_b_70_1, emitter.context().types().v4s32());
    /* execute.simd:141 [D] s_b_70_3: sym_23492_0_rn = s_b_70_2, dominates: s_b_71_0 s_b_72_0 s_b_73_0 s_b_74_0 s_b_75_0  */
    emitter.store_local(DV_sym_23492_0_rn, s_b_70_2);
    /* execute.simd:143 [F] s_b_70_4 = constant s32 0 (const) */
    /* execute.simd:143 [D] s_b_70_2[s_b_70_4] */
    auto s_b_70_5 = emitter.vector_extract(s_b_70_2, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:143 [D] s_b_70_6: sym_23498_0_min = s_b_70_5, dominates: s_b_72_3 s_b_74_3 s_b_76_1  */
    emitter.store_local(DV_sym_23498_0_min, s_b_70_5);
    /* ???:4294967295 [F] s_b_70_7 = constant u8 1 (const) */
    /* execute.simd:145 [D] s_b_70_2[s_b_70_7] */
    auto s_b_70_8 = emitter.vector_extract(s_b_70_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:145 [D] s_b_70_9 = s_b_70_8>s_b_70_5 */
    auto s_b_70_9 = emitter.cmp_gt(s_b_70_8, s_b_70_5);
    /* execute.simd:145 [D] s_b_70_10: If s_b_70_9: Jump b_71 else b_72 */
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
    /* execute.simd:154 [D] s_b_77_0 = trap */
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
        /* execute.simd:94 [D] s_b_3_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_3_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_3_1 = constant u8 1 (const) */
        /* execute.simd:94 [D] s_b_3_0[s_b_3_1] */
        auto s_b_3_2 = emitter.vector_extract(s_b_3_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:94 [D] s_b_3_3: sym_22874_0_min = s_b_3_2, dominates: s_b_4_3 s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_22874_0_min, s_b_3_2);
        /* execute.simd:94 [F] s_b_3_4: Jump b_4 (const) */
        {
          auto block = block_b_4;
          dynamic_block_queue.push(block_b_4);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.simd:93 [D] s_b_4_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_4_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_4_1 = constant u8 2 (const) */
        /* execute.simd:93 [D] s_b_4_0[s_b_4_1] */
        auto s_b_4_2 = emitter.vector_extract(s_b_4_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:93 [D] s_b_4_3 = sym_22874_0_min int8_t */
        auto s_b_4_3 = emitter.load_local(DV_sym_22874_0_min, emitter.context().types().s8());
        /* execute.simd:93 [D] s_b_4_4 = s_b_4_2>s_b_4_3 */
        auto s_b_4_4 = emitter.cmp_gt(s_b_4_2, s_b_4_3);
        /* execute.simd:93 [D] s_b_4_5: If s_b_4_4: Jump b_5 else b_6 */
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
        /* execute.simd:94 [D] s_b_5_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_5_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_5_1 = constant u8 2 (const) */
        /* execute.simd:94 [D] s_b_5_0[s_b_5_1] */
        auto s_b_5_2 = emitter.vector_extract(s_b_5_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:94 [D] s_b_5_3: sym_22874_0_min = s_b_5_2, dominates: s_b_6_3 s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_22874_0_min, s_b_5_2);
        /* execute.simd:94 [F] s_b_5_4: Jump b_6 (const) */
        {
          auto block = block_b_6;
          dynamic_block_queue.push(block_b_6);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:93 [D] s_b_6_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_6_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_6_1 = constant u8 3 (const) */
        /* execute.simd:93 [D] s_b_6_0[s_b_6_1] */
        auto s_b_6_2 = emitter.vector_extract(s_b_6_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:93 [D] s_b_6_3 = sym_22874_0_min int8_t */
        auto s_b_6_3 = emitter.load_local(DV_sym_22874_0_min, emitter.context().types().s8());
        /* execute.simd:93 [D] s_b_6_4 = s_b_6_2>s_b_6_3 */
        auto s_b_6_4 = emitter.cmp_gt(s_b_6_2, s_b_6_3);
        /* execute.simd:93 [D] s_b_6_5: If s_b_6_4: Jump b_7 else b_8 */
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
        /* execute.simd:94 [D] s_b_7_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_7_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_7_1 = constant u8 3 (const) */
        /* execute.simd:94 [D] s_b_7_0[s_b_7_1] */
        auto s_b_7_2 = emitter.vector_extract(s_b_7_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:94 [D] s_b_7_3: sym_22874_0_min = s_b_7_2, dominates: s_b_8_3 s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_22874_0_min, s_b_7_2);
        /* execute.simd:94 [F] s_b_7_4: Jump b_8 (const) */
        {
          auto block = block_b_8;
          dynamic_block_queue.push(block_b_8);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.simd:93 [D] s_b_8_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_8_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_8_1 = constant u8 4 (const) */
        /* execute.simd:93 [D] s_b_8_0[s_b_8_1] */
        auto s_b_8_2 = emitter.vector_extract(s_b_8_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:93 [D] s_b_8_3 = sym_22874_0_min int8_t */
        auto s_b_8_3 = emitter.load_local(DV_sym_22874_0_min, emitter.context().types().s8());
        /* execute.simd:93 [D] s_b_8_4 = s_b_8_2>s_b_8_3 */
        auto s_b_8_4 = emitter.cmp_gt(s_b_8_2, s_b_8_3);
        /* execute.simd:93 [D] s_b_8_5: If s_b_8_4: Jump b_9 else b_10 */
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
        /* execute.simd:94 [D] s_b_9_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_9_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_9_1 = constant u8 4 (const) */
        /* execute.simd:94 [D] s_b_9_0[s_b_9_1] */
        auto s_b_9_2 = emitter.vector_extract(s_b_9_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:94 [D] s_b_9_3: sym_22874_0_min = s_b_9_2, dominates: s_b_10_3 s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_22874_0_min, s_b_9_2);
        /* execute.simd:94 [F] s_b_9_4: Jump b_10 (const) */
        {
          auto block = block_b_10;
          dynamic_block_queue.push(block_b_10);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.simd:93 [D] s_b_10_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_10_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_10_1 = constant u8 5 (const) */
        /* execute.simd:93 [D] s_b_10_0[s_b_10_1] */
        auto s_b_10_2 = emitter.vector_extract(s_b_10_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:93 [D] s_b_10_3 = sym_22874_0_min int8_t */
        auto s_b_10_3 = emitter.load_local(DV_sym_22874_0_min, emitter.context().types().s8());
        /* execute.simd:93 [D] s_b_10_4 = s_b_10_2>s_b_10_3 */
        auto s_b_10_4 = emitter.cmp_gt(s_b_10_2, s_b_10_3);
        /* execute.simd:93 [D] s_b_10_5: If s_b_10_4: Jump b_11 else b_12 */
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
        /* execute.simd:94 [D] s_b_11_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_11_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_11_1 = constant u8 5 (const) */
        /* execute.simd:94 [D] s_b_11_0[s_b_11_1] */
        auto s_b_11_2 = emitter.vector_extract(s_b_11_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:94 [D] s_b_11_3: sym_22874_0_min = s_b_11_2, dominates: s_b_12_3 s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_22874_0_min, s_b_11_2);
        /* execute.simd:94 [F] s_b_11_4: Jump b_12 (const) */
        {
          auto block = block_b_12;
          dynamic_block_queue.push(block_b_12);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.simd:93 [D] s_b_12_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_12_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_12_1 = constant u8 6 (const) */
        /* execute.simd:93 [D] s_b_12_0[s_b_12_1] */
        auto s_b_12_2 = emitter.vector_extract(s_b_12_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:93 [D] s_b_12_3 = sym_22874_0_min int8_t */
        auto s_b_12_3 = emitter.load_local(DV_sym_22874_0_min, emitter.context().types().s8());
        /* execute.simd:93 [D] s_b_12_4 = s_b_12_2>s_b_12_3 */
        auto s_b_12_4 = emitter.cmp_gt(s_b_12_2, s_b_12_3);
        /* execute.simd:93 [D] s_b_12_5: If s_b_12_4: Jump b_13 else b_14 */
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
        /* execute.simd:94 [D] s_b_13_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_13_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_13_1 = constant u8 6 (const) */
        /* execute.simd:94 [D] s_b_13_0[s_b_13_1] */
        auto s_b_13_2 = emitter.vector_extract(s_b_13_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:94 [D] s_b_13_3: sym_22874_0_min = s_b_13_2, dominates: s_b_14_3 s_b_16_1  */
        emitter.store_local(DV_sym_22874_0_min, s_b_13_2);
        /* execute.simd:94 [F] s_b_13_4: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.simd:93 [D] s_b_14_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_14_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_14_1 = constant u8 7 (const) */
        /* execute.simd:93 [D] s_b_14_0[s_b_14_1] */
        auto s_b_14_2 = emitter.vector_extract(s_b_14_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:93 [D] s_b_14_3 = sym_22874_0_min int8_t */
        auto s_b_14_3 = emitter.load_local(DV_sym_22874_0_min, emitter.context().types().s8());
        /* execute.simd:93 [D] s_b_14_4 = s_b_14_2>s_b_14_3 */
        auto s_b_14_4 = emitter.cmp_gt(s_b_14_2, s_b_14_3);
        /* execute.simd:93 [D] s_b_14_5: If s_b_14_4: Jump b_15 else b_16 */
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
        /* execute.simd:94 [D] s_b_15_0 = sym_22868_0_rn wutils::Vector<int8_t, 8> */
        auto s_b_15_0 = emitter.load_local(DV_sym_22868_0_rn, emitter.context().types().v8s8());
        /* ???:4294967295 [F] s_b_15_1 = constant u8 7 (const) */
        /* execute.simd:94 [D] s_b_15_0[s_b_15_1] */
        auto s_b_15_2 = emitter.vector_extract(s_b_15_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:94 [D] s_b_15_3: sym_22874_0_min = s_b_15_2, dominates: s_b_16_1  */
        emitter.store_local(DV_sym_22874_0_min, s_b_15_2);
        /* execute.simd:94 [F] s_b_15_4: Jump b_16 (const) */
        {
          auto block = block_b_16;
          dynamic_block_queue.push(block_b_16);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.simd:98 [F] s_b_16_0=sym_22860_3_parameter_inst.rd (const) */
        /* execute.simd:98 [D] s_b_16_1 = sym_22874_0_min int8_t */
        auto s_b_16_1 = emitter.load_local(DV_sym_22874_0_min, emitter.context().types().s8());
        /* execute.simd:98 [D] s_b_16_2 = (u8)s_b_16_1 */
        auto s_b_16_2 = emitter.reinterpret(s_b_16_1, emitter.context().types().u8());
        /* execute.simd:6117 [D] s_b_16_3 = (u64)s_b_16_2 */
        auto s_b_16_3 = emitter.zx(s_b_16_2, emitter.context().types().u64());
        /* execute.simd:6117 [D] s_b_16_4: WriteRegBank 2:s_b_16_0 = s_b_16_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_3);
        /* execute.simd:6118 [F] s_b_16_5 = constant u64 0 (const) */
        /* execute.simd:6118 [F] s_b_16_6: WriteRegBank 3:s_b_16_0 = s_b_16_5 */
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
        /* execute.simd:107 [D] s_b_18_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_18_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_18_1 = constant u8 1 (const) */
        /* execute.simd:107 [D] s_b_18_0[s_b_18_1] */
        auto s_b_18_2 = emitter.vector_extract(s_b_18_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:107 [D] s_b_18_3: sym_23013_0_min = s_b_18_2, dominates: s_b_19_3 s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_18_2);
        /* execute.simd:107 [F] s_b_18_4: Jump b_19 (const) */
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.simd:106 [D] s_b_19_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_19_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_19_1 = constant u8 2 (const) */
        /* execute.simd:106 [D] s_b_19_0[s_b_19_1] */
        auto s_b_19_2 = emitter.vector_extract(s_b_19_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:106 [D] s_b_19_3 = sym_23013_0_min int8_t */
        auto s_b_19_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_19_4 = s_b_19_2>s_b_19_3 */
        auto s_b_19_4 = emitter.cmp_gt(s_b_19_2, s_b_19_3);
        /* execute.simd:106 [D] s_b_19_5: If s_b_19_4: Jump b_20 else b_21 */
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
        /* execute.simd:107 [D] s_b_20_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_20_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_20_1 = constant u8 2 (const) */
        /* execute.simd:107 [D] s_b_20_0[s_b_20_1] */
        auto s_b_20_2 = emitter.vector_extract(s_b_20_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:107 [D] s_b_20_3: sym_23013_0_min = s_b_20_2, dominates: s_b_21_3 s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_20_2);
        /* execute.simd:107 [F] s_b_20_4: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.simd:106 [D] s_b_21_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_21_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_21_1 = constant u8 3 (const) */
        /* execute.simd:106 [D] s_b_21_0[s_b_21_1] */
        auto s_b_21_2 = emitter.vector_extract(s_b_21_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:106 [D] s_b_21_3 = sym_23013_0_min int8_t */
        auto s_b_21_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_21_4 = s_b_21_2>s_b_21_3 */
        auto s_b_21_4 = emitter.cmp_gt(s_b_21_2, s_b_21_3);
        /* execute.simd:106 [D] s_b_21_5: If s_b_21_4: Jump b_22 else b_23 */
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
        /* execute.simd:107 [D] s_b_22_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_22_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_22_1 = constant u8 3 (const) */
        /* execute.simd:107 [D] s_b_22_0[s_b_22_1] */
        auto s_b_22_2 = emitter.vector_extract(s_b_22_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:107 [D] s_b_22_3: sym_23013_0_min = s_b_22_2, dominates: s_b_23_3 s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_22_2);
        /* execute.simd:107 [F] s_b_22_4: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.simd:106 [D] s_b_23_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_23_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_23_1 = constant u8 4 (const) */
        /* execute.simd:106 [D] s_b_23_0[s_b_23_1] */
        auto s_b_23_2 = emitter.vector_extract(s_b_23_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:106 [D] s_b_23_3 = sym_23013_0_min int8_t */
        auto s_b_23_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_23_4 = s_b_23_2>s_b_23_3 */
        auto s_b_23_4 = emitter.cmp_gt(s_b_23_2, s_b_23_3);
        /* execute.simd:106 [D] s_b_23_5: If s_b_23_4: Jump b_24 else b_25 */
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
        /* execute.simd:107 [D] s_b_24_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_24_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_24_1 = constant u8 4 (const) */
        /* execute.simd:107 [D] s_b_24_0[s_b_24_1] */
        auto s_b_24_2 = emitter.vector_extract(s_b_24_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:107 [D] s_b_24_3: sym_23013_0_min = s_b_24_2, dominates: s_b_25_3 s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_24_2);
        /* execute.simd:107 [F] s_b_24_4: Jump b_25 (const) */
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.simd:106 [D] s_b_25_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_25_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_25_1 = constant u8 5 (const) */
        /* execute.simd:106 [D] s_b_25_0[s_b_25_1] */
        auto s_b_25_2 = emitter.vector_extract(s_b_25_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:106 [D] s_b_25_3 = sym_23013_0_min int8_t */
        auto s_b_25_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_25_4 = s_b_25_2>s_b_25_3 */
        auto s_b_25_4 = emitter.cmp_gt(s_b_25_2, s_b_25_3);
        /* execute.simd:106 [D] s_b_25_5: If s_b_25_4: Jump b_26 else b_27 */
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
        /* execute.simd:107 [D] s_b_26_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_26_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_26_1 = constant u8 5 (const) */
        /* execute.simd:107 [D] s_b_26_0[s_b_26_1] */
        auto s_b_26_2 = emitter.vector_extract(s_b_26_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:107 [D] s_b_26_3: sym_23013_0_min = s_b_26_2, dominates: s_b_27_3 s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_26_2);
        /* execute.simd:107 [F] s_b_26_4: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.simd:106 [D] s_b_27_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_27_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_27_1 = constant u8 6 (const) */
        /* execute.simd:106 [D] s_b_27_0[s_b_27_1] */
        auto s_b_27_2 = emitter.vector_extract(s_b_27_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:106 [D] s_b_27_3 = sym_23013_0_min int8_t */
        auto s_b_27_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_27_4 = s_b_27_2>s_b_27_3 */
        auto s_b_27_4 = emitter.cmp_gt(s_b_27_2, s_b_27_3);
        /* execute.simd:106 [D] s_b_27_5: If s_b_27_4: Jump b_28 else b_29 */
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
        /* execute.simd:107 [D] s_b_28_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_28_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_28_1 = constant u8 6 (const) */
        /* execute.simd:107 [D] s_b_28_0[s_b_28_1] */
        auto s_b_28_2 = emitter.vector_extract(s_b_28_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:107 [D] s_b_28_3: sym_23013_0_min = s_b_28_2, dominates: s_b_29_3 s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_28_2);
        /* execute.simd:107 [F] s_b_28_4: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.simd:106 [D] s_b_29_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_29_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_29_1 = constant u8 7 (const) */
        /* execute.simd:106 [D] s_b_29_0[s_b_29_1] */
        auto s_b_29_2 = emitter.vector_extract(s_b_29_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:106 [D] s_b_29_3 = sym_23013_0_min int8_t */
        auto s_b_29_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_29_4 = s_b_29_2>s_b_29_3 */
        auto s_b_29_4 = emitter.cmp_gt(s_b_29_2, s_b_29_3);
        /* execute.simd:106 [D] s_b_29_5: If s_b_29_4: Jump b_30 else b_31 */
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
        /* execute.simd:107 [D] s_b_30_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_30_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_30_1 = constant u8 7 (const) */
        /* execute.simd:107 [D] s_b_30_0[s_b_30_1] */
        auto s_b_30_2 = emitter.vector_extract(s_b_30_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:107 [D] s_b_30_3: sym_23013_0_min = s_b_30_2, dominates: s_b_31_3 s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_30_2);
        /* execute.simd:107 [F] s_b_30_4: Jump b_31 (const) */
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.simd:106 [D] s_b_31_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_31_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_31_1 = constant u8 8 (const) */
        /* execute.simd:106 [D] s_b_31_0[s_b_31_1] */
        auto s_b_31_2 = emitter.vector_extract(s_b_31_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:106 [D] s_b_31_3 = sym_23013_0_min int8_t */
        auto s_b_31_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_31_4 = s_b_31_2>s_b_31_3 */
        auto s_b_31_4 = emitter.cmp_gt(s_b_31_2, s_b_31_3);
        /* execute.simd:106 [D] s_b_31_5: If s_b_31_4: Jump b_32 else b_33 */
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
        /* execute.simd:107 [D] s_b_32_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_32_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_32_1 = constant u8 8 (const) */
        /* execute.simd:107 [D] s_b_32_0[s_b_32_1] */
        auto s_b_32_2 = emitter.vector_extract(s_b_32_0, emitter.const_u8((uint8_t)8ULL));
        /* execute.simd:107 [D] s_b_32_3: sym_23013_0_min = s_b_32_2, dominates: s_b_33_3 s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_32_2);
        /* execute.simd:107 [F] s_b_32_4: Jump b_33 (const) */
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.simd:106 [D] s_b_33_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_33_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_33_1 = constant u8 9 (const) */
        /* execute.simd:106 [D] s_b_33_0[s_b_33_1] */
        auto s_b_33_2 = emitter.vector_extract(s_b_33_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:106 [D] s_b_33_3 = sym_23013_0_min int8_t */
        auto s_b_33_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_33_4 = s_b_33_2>s_b_33_3 */
        auto s_b_33_4 = emitter.cmp_gt(s_b_33_2, s_b_33_3);
        /* execute.simd:106 [D] s_b_33_5: If s_b_33_4: Jump b_34 else b_35 */
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
        /* execute.simd:107 [D] s_b_34_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_34_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_34_1 = constant u8 9 (const) */
        /* execute.simd:107 [D] s_b_34_0[s_b_34_1] */
        auto s_b_34_2 = emitter.vector_extract(s_b_34_0, emitter.const_u8((uint8_t)9ULL));
        /* execute.simd:107 [D] s_b_34_3: sym_23013_0_min = s_b_34_2, dominates: s_b_35_3 s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_34_2);
        /* execute.simd:107 [F] s_b_34_4: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.simd:106 [D] s_b_35_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_35_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_35_1 = constant u8 a (const) */
        /* execute.simd:106 [D] s_b_35_0[s_b_35_1] */
        auto s_b_35_2 = emitter.vector_extract(s_b_35_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:106 [D] s_b_35_3 = sym_23013_0_min int8_t */
        auto s_b_35_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_35_4 = s_b_35_2>s_b_35_3 */
        auto s_b_35_4 = emitter.cmp_gt(s_b_35_2, s_b_35_3);
        /* execute.simd:106 [D] s_b_35_5: If s_b_35_4: Jump b_36 else b_37 */
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
        /* execute.simd:107 [D] s_b_36_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_36_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_36_1 = constant u8 a (const) */
        /* execute.simd:107 [D] s_b_36_0[s_b_36_1] */
        auto s_b_36_2 = emitter.vector_extract(s_b_36_0, emitter.const_u8((uint8_t)10ULL));
        /* execute.simd:107 [D] s_b_36_3: sym_23013_0_min = s_b_36_2, dominates: s_b_37_3 s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_36_2);
        /* execute.simd:107 [F] s_b_36_4: Jump b_37 (const) */
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.simd:106 [D] s_b_37_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_37_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_37_1 = constant u8 b (const) */
        /* execute.simd:106 [D] s_b_37_0[s_b_37_1] */
        auto s_b_37_2 = emitter.vector_extract(s_b_37_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:106 [D] s_b_37_3 = sym_23013_0_min int8_t */
        auto s_b_37_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_37_4 = s_b_37_2>s_b_37_3 */
        auto s_b_37_4 = emitter.cmp_gt(s_b_37_2, s_b_37_3);
        /* execute.simd:106 [D] s_b_37_5: If s_b_37_4: Jump b_38 else b_39 */
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
        /* execute.simd:107 [D] s_b_38_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_38_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_38_1 = constant u8 b (const) */
        /* execute.simd:107 [D] s_b_38_0[s_b_38_1] */
        auto s_b_38_2 = emitter.vector_extract(s_b_38_0, emitter.const_u8((uint8_t)11ULL));
        /* execute.simd:107 [D] s_b_38_3: sym_23013_0_min = s_b_38_2, dominates: s_b_39_3 s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_38_2);
        /* execute.simd:107 [F] s_b_38_4: Jump b_39 (const) */
        {
          auto block = block_b_39;
          dynamic_block_queue.push(block_b_39);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.simd:106 [D] s_b_39_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_39_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_39_1 = constant u8 c (const) */
        /* execute.simd:106 [D] s_b_39_0[s_b_39_1] */
        auto s_b_39_2 = emitter.vector_extract(s_b_39_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:106 [D] s_b_39_3 = sym_23013_0_min int8_t */
        auto s_b_39_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_39_4 = s_b_39_2>s_b_39_3 */
        auto s_b_39_4 = emitter.cmp_gt(s_b_39_2, s_b_39_3);
        /* execute.simd:106 [D] s_b_39_5: If s_b_39_4: Jump b_40 else b_41 */
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
        /* execute.simd:107 [D] s_b_40_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_40_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_40_1 = constant u8 c (const) */
        /* execute.simd:107 [D] s_b_40_0[s_b_40_1] */
        auto s_b_40_2 = emitter.vector_extract(s_b_40_0, emitter.const_u8((uint8_t)12ULL));
        /* execute.simd:107 [D] s_b_40_3: sym_23013_0_min = s_b_40_2, dominates: s_b_41_3 s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_40_2);
        /* execute.simd:107 [F] s_b_40_4: Jump b_41 (const) */
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.simd:106 [D] s_b_41_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_41_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_41_1 = constant u8 d (const) */
        /* execute.simd:106 [D] s_b_41_0[s_b_41_1] */
        auto s_b_41_2 = emitter.vector_extract(s_b_41_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:106 [D] s_b_41_3 = sym_23013_0_min int8_t */
        auto s_b_41_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_41_4 = s_b_41_2>s_b_41_3 */
        auto s_b_41_4 = emitter.cmp_gt(s_b_41_2, s_b_41_3);
        /* execute.simd:106 [D] s_b_41_5: If s_b_41_4: Jump b_42 else b_43 */
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
        /* execute.simd:107 [D] s_b_42_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_42_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_42_1 = constant u8 d (const) */
        /* execute.simd:107 [D] s_b_42_0[s_b_42_1] */
        auto s_b_42_2 = emitter.vector_extract(s_b_42_0, emitter.const_u8((uint8_t)13ULL));
        /* execute.simd:107 [D] s_b_42_3: sym_23013_0_min = s_b_42_2, dominates: s_b_43_3 s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_42_2);
        /* execute.simd:107 [F] s_b_42_4: Jump b_43 (const) */
        {
          auto block = block_b_43;
          dynamic_block_queue.push(block_b_43);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_43) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_43);
        /* execute.simd:106 [D] s_b_43_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_43_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_43_1 = constant u8 e (const) */
        /* execute.simd:106 [D] s_b_43_0[s_b_43_1] */
        auto s_b_43_2 = emitter.vector_extract(s_b_43_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:106 [D] s_b_43_3 = sym_23013_0_min int8_t */
        auto s_b_43_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_43_4 = s_b_43_2>s_b_43_3 */
        auto s_b_43_4 = emitter.cmp_gt(s_b_43_2, s_b_43_3);
        /* execute.simd:106 [D] s_b_43_5: If s_b_43_4: Jump b_44 else b_45 */
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
        /* execute.simd:107 [D] s_b_44_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_44_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_44_1 = constant u8 e (const) */
        /* execute.simd:107 [D] s_b_44_0[s_b_44_1] */
        auto s_b_44_2 = emitter.vector_extract(s_b_44_0, emitter.const_u8((uint8_t)14ULL));
        /* execute.simd:107 [D] s_b_44_3: sym_23013_0_min = s_b_44_2, dominates: s_b_45_3 s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_44_2);
        /* execute.simd:107 [F] s_b_44_4: Jump b_45 (const) */
        {
          auto block = block_b_45;
          dynamic_block_queue.push(block_b_45);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_45) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_45);
        /* execute.simd:106 [D] s_b_45_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_45_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_45_1 = constant u8 f (const) */
        /* execute.simd:106 [D] s_b_45_0[s_b_45_1] */
        auto s_b_45_2 = emitter.vector_extract(s_b_45_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:106 [D] s_b_45_3 = sym_23013_0_min int8_t */
        auto s_b_45_3 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:106 [D] s_b_45_4 = s_b_45_2>s_b_45_3 */
        auto s_b_45_4 = emitter.cmp_gt(s_b_45_2, s_b_45_3);
        /* execute.simd:106 [D] s_b_45_5: If s_b_45_4: Jump b_46 else b_47 */
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
        /* execute.simd:107 [D] s_b_46_0 = sym_23007_0_rn wutils::Vector<int8_t, 16> */
        auto s_b_46_0 = emitter.load_local(DV_sym_23007_0_rn, emitter.context().types().v16s8());
        /* ???:4294967295 [F] s_b_46_1 = constant u8 f (const) */
        /* execute.simd:107 [D] s_b_46_0[s_b_46_1] */
        auto s_b_46_2 = emitter.vector_extract(s_b_46_0, emitter.const_u8((uint8_t)15ULL));
        /* execute.simd:107 [D] s_b_46_3: sym_23013_0_min = s_b_46_2, dominates: s_b_47_1  */
        emitter.store_local(DV_sym_23013_0_min, s_b_46_2);
        /* execute.simd:107 [F] s_b_46_4: Jump b_47 (const) */
        {
          auto block = block_b_47;
          dynamic_block_queue.push(block_b_47);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_47) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_47);
        /* execute.simd:111 [F] s_b_47_0=sym_22860_3_parameter_inst.rd (const) */
        /* execute.simd:111 [D] s_b_47_1 = sym_23013_0_min int8_t */
        auto s_b_47_1 = emitter.load_local(DV_sym_23013_0_min, emitter.context().types().s8());
        /* execute.simd:111 [D] s_b_47_2 = (u8)s_b_47_1 */
        auto s_b_47_2 = emitter.reinterpret(s_b_47_1, emitter.context().types().u8());
        /* execute.simd:6117 [D] s_b_47_3 = (u64)s_b_47_2 */
        auto s_b_47_3 = emitter.zx(s_b_47_2, emitter.context().types().u64());
        /* execute.simd:6117 [D] s_b_47_4: WriteRegBank 2:s_b_47_0 = s_b_47_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_47_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_47_3);
        /* execute.simd:6118 [F] s_b_47_5 = constant u64 0 (const) */
        /* execute.simd:6118 [F] s_b_47_6: WriteRegBank 3:s_b_47_0 = s_b_47_5 */
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
        /* execute.simd:120 [D] s_b_49_0 = sym_23282_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_49_0 = emitter.load_local(DV_sym_23282_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_49_1 = constant u8 1 (const) */
        /* execute.simd:120 [D] s_b_49_0[s_b_49_1] */
        auto s_b_49_2 = emitter.vector_extract(s_b_49_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:120 [D] s_b_49_3: sym_23288_0_min = s_b_49_2, dominates: s_b_50_3 s_b_52_3 s_b_54_1  */
        emitter.store_local(DV_sym_23288_0_min, s_b_49_2);
        /* execute.simd:120 [F] s_b_49_4: Jump b_50 (const) */
        {
          auto block = block_b_50;
          dynamic_block_queue.push(block_b_50);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_50) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_50);
        /* execute.simd:119 [D] s_b_50_0 = sym_23282_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_50_0 = emitter.load_local(DV_sym_23282_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_50_1 = constant u8 2 (const) */
        /* execute.simd:119 [D] s_b_50_0[s_b_50_1] */
        auto s_b_50_2 = emitter.vector_extract(s_b_50_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:119 [D] s_b_50_3 = sym_23288_0_min int16_t */
        auto s_b_50_3 = emitter.load_local(DV_sym_23288_0_min, emitter.context().types().s16());
        /* execute.simd:119 [D] s_b_50_4 = s_b_50_2>s_b_50_3 */
        auto s_b_50_4 = emitter.cmp_gt(s_b_50_2, s_b_50_3);
        /* execute.simd:119 [D] s_b_50_5: If s_b_50_4: Jump b_51 else b_52 */
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
        /* execute.simd:120 [D] s_b_51_0 = sym_23282_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_51_0 = emitter.load_local(DV_sym_23282_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_51_1 = constant u8 2 (const) */
        /* execute.simd:120 [D] s_b_51_0[s_b_51_1] */
        auto s_b_51_2 = emitter.vector_extract(s_b_51_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:120 [D] s_b_51_3: sym_23288_0_min = s_b_51_2, dominates: s_b_52_3 s_b_54_1  */
        emitter.store_local(DV_sym_23288_0_min, s_b_51_2);
        /* execute.simd:120 [F] s_b_51_4: Jump b_52 (const) */
        {
          auto block = block_b_52;
          dynamic_block_queue.push(block_b_52);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_52) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_52);
        /* execute.simd:119 [D] s_b_52_0 = sym_23282_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_52_0 = emitter.load_local(DV_sym_23282_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_52_1 = constant u8 3 (const) */
        /* execute.simd:119 [D] s_b_52_0[s_b_52_1] */
        auto s_b_52_2 = emitter.vector_extract(s_b_52_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:119 [D] s_b_52_3 = sym_23288_0_min int16_t */
        auto s_b_52_3 = emitter.load_local(DV_sym_23288_0_min, emitter.context().types().s16());
        /* execute.simd:119 [D] s_b_52_4 = s_b_52_2>s_b_52_3 */
        auto s_b_52_4 = emitter.cmp_gt(s_b_52_2, s_b_52_3);
        /* execute.simd:119 [D] s_b_52_5: If s_b_52_4: Jump b_53 else b_54 */
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
        /* execute.simd:120 [D] s_b_53_0 = sym_23282_0_rn wutils::Vector<int16_t, 4> */
        auto s_b_53_0 = emitter.load_local(DV_sym_23282_0_rn, emitter.context().types().v4s16());
        /* ???:4294967295 [F] s_b_53_1 = constant u8 3 (const) */
        /* execute.simd:120 [D] s_b_53_0[s_b_53_1] */
        auto s_b_53_2 = emitter.vector_extract(s_b_53_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:120 [D] s_b_53_3: sym_23288_0_min = s_b_53_2, dominates: s_b_54_1  */
        emitter.store_local(DV_sym_23288_0_min, s_b_53_2);
        /* execute.simd:120 [F] s_b_53_4: Jump b_54 (const) */
        {
          auto block = block_b_54;
          dynamic_block_queue.push(block_b_54);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_54) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_54);
        /* execute.simd:124 [F] s_b_54_0=sym_22860_3_parameter_inst.rd (const) */
        /* execute.simd:124 [D] s_b_54_1 = sym_23288_0_min int16_t */
        auto s_b_54_1 = emitter.load_local(DV_sym_23288_0_min, emitter.context().types().s16());
        /* execute.simd:124 [D] s_b_54_2 = (u16)s_b_54_1 */
        auto s_b_54_2 = emitter.reinterpret(s_b_54_1, emitter.context().types().u16());
        /* execute.simd:6124 [D] s_b_54_3 = (u64)s_b_54_2 */
        auto s_b_54_3 = emitter.zx(s_b_54_2, emitter.context().types().u64());
        /* execute.simd:6124 [D] s_b_54_4: WriteRegBank 2:s_b_54_0 = s_b_54_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_54_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_54_3);
        /* execute.simd:6125 [F] s_b_54_5 = constant u64 0 (const) */
        /* execute.simd:6125 [F] s_b_54_6: WriteRegBank 3:s_b_54_0 = s_b_54_5 */
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
        /* execute.simd:133 [D] s_b_56_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_56_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_56_1 = constant u8 1 (const) */
        /* execute.simd:133 [D] s_b_56_0[s_b_56_1] */
        auto s_b_56_2 = emitter.vector_extract(s_b_56_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:133 [D] s_b_56_3: sym_23359_0_min = s_b_56_2, dominates: s_b_57_3 s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_23359_0_min, s_b_56_2);
        /* execute.simd:133 [F] s_b_56_4: Jump b_57 (const) */
        {
          auto block = block_b_57;
          dynamic_block_queue.push(block_b_57);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_57) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_57);
        /* execute.simd:132 [D] s_b_57_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_57_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_57_1 = constant u8 2 (const) */
        /* execute.simd:132 [D] s_b_57_0[s_b_57_1] */
        auto s_b_57_2 = emitter.vector_extract(s_b_57_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:132 [D] s_b_57_3 = sym_23359_0_min int16_t */
        auto s_b_57_3 = emitter.load_local(DV_sym_23359_0_min, emitter.context().types().s16());
        /* execute.simd:132 [D] s_b_57_4 = s_b_57_2>s_b_57_3 */
        auto s_b_57_4 = emitter.cmp_gt(s_b_57_2, s_b_57_3);
        /* execute.simd:132 [D] s_b_57_5: If s_b_57_4: Jump b_58 else b_59 */
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
        /* execute.simd:133 [D] s_b_58_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_58_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_58_1 = constant u8 2 (const) */
        /* execute.simd:133 [D] s_b_58_0[s_b_58_1] */
        auto s_b_58_2 = emitter.vector_extract(s_b_58_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:133 [D] s_b_58_3: sym_23359_0_min = s_b_58_2, dominates: s_b_59_3 s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_23359_0_min, s_b_58_2);
        /* execute.simd:133 [F] s_b_58_4: Jump b_59 (const) */
        {
          auto block = block_b_59;
          dynamic_block_queue.push(block_b_59);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_59) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_59);
        /* execute.simd:132 [D] s_b_59_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_59_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_59_1 = constant u8 3 (const) */
        /* execute.simd:132 [D] s_b_59_0[s_b_59_1] */
        auto s_b_59_2 = emitter.vector_extract(s_b_59_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:132 [D] s_b_59_3 = sym_23359_0_min int16_t */
        auto s_b_59_3 = emitter.load_local(DV_sym_23359_0_min, emitter.context().types().s16());
        /* execute.simd:132 [D] s_b_59_4 = s_b_59_2>s_b_59_3 */
        auto s_b_59_4 = emitter.cmp_gt(s_b_59_2, s_b_59_3);
        /* execute.simd:132 [D] s_b_59_5: If s_b_59_4: Jump b_60 else b_61 */
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
        /* execute.simd:133 [D] s_b_60_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_60_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_60_1 = constant u8 3 (const) */
        /* execute.simd:133 [D] s_b_60_0[s_b_60_1] */
        auto s_b_60_2 = emitter.vector_extract(s_b_60_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:133 [D] s_b_60_3: sym_23359_0_min = s_b_60_2, dominates: s_b_61_3 s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_23359_0_min, s_b_60_2);
        /* execute.simd:133 [F] s_b_60_4: Jump b_61 (const) */
        {
          auto block = block_b_61;
          dynamic_block_queue.push(block_b_61);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_61) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_61);
        /* execute.simd:132 [D] s_b_61_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_61_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_61_1 = constant u8 4 (const) */
        /* execute.simd:132 [D] s_b_61_0[s_b_61_1] */
        auto s_b_61_2 = emitter.vector_extract(s_b_61_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:132 [D] s_b_61_3 = sym_23359_0_min int16_t */
        auto s_b_61_3 = emitter.load_local(DV_sym_23359_0_min, emitter.context().types().s16());
        /* execute.simd:132 [D] s_b_61_4 = s_b_61_2>s_b_61_3 */
        auto s_b_61_4 = emitter.cmp_gt(s_b_61_2, s_b_61_3);
        /* execute.simd:132 [D] s_b_61_5: If s_b_61_4: Jump b_62 else b_63 */
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
        /* execute.simd:133 [D] s_b_62_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_62_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_62_1 = constant u8 4 (const) */
        /* execute.simd:133 [D] s_b_62_0[s_b_62_1] */
        auto s_b_62_2 = emitter.vector_extract(s_b_62_0, emitter.const_u8((uint8_t)4ULL));
        /* execute.simd:133 [D] s_b_62_3: sym_23359_0_min = s_b_62_2, dominates: s_b_63_3 s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_23359_0_min, s_b_62_2);
        /* execute.simd:133 [F] s_b_62_4: Jump b_63 (const) */
        {
          auto block = block_b_63;
          dynamic_block_queue.push(block_b_63);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_63) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_63);
        /* execute.simd:132 [D] s_b_63_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_63_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_63_1 = constant u8 5 (const) */
        /* execute.simd:132 [D] s_b_63_0[s_b_63_1] */
        auto s_b_63_2 = emitter.vector_extract(s_b_63_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:132 [D] s_b_63_3 = sym_23359_0_min int16_t */
        auto s_b_63_3 = emitter.load_local(DV_sym_23359_0_min, emitter.context().types().s16());
        /* execute.simd:132 [D] s_b_63_4 = s_b_63_2>s_b_63_3 */
        auto s_b_63_4 = emitter.cmp_gt(s_b_63_2, s_b_63_3);
        /* execute.simd:132 [D] s_b_63_5: If s_b_63_4: Jump b_64 else b_65 */
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
        /* execute.simd:133 [D] s_b_64_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_64_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_64_1 = constant u8 5 (const) */
        /* execute.simd:133 [D] s_b_64_0[s_b_64_1] */
        auto s_b_64_2 = emitter.vector_extract(s_b_64_0, emitter.const_u8((uint8_t)5ULL));
        /* execute.simd:133 [D] s_b_64_3: sym_23359_0_min = s_b_64_2, dominates: s_b_65_3 s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_23359_0_min, s_b_64_2);
        /* execute.simd:133 [F] s_b_64_4: Jump b_65 (const) */
        {
          auto block = block_b_65;
          dynamic_block_queue.push(block_b_65);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_65) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_65);
        /* execute.simd:132 [D] s_b_65_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_65_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_65_1 = constant u8 6 (const) */
        /* execute.simd:132 [D] s_b_65_0[s_b_65_1] */
        auto s_b_65_2 = emitter.vector_extract(s_b_65_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:132 [D] s_b_65_3 = sym_23359_0_min int16_t */
        auto s_b_65_3 = emitter.load_local(DV_sym_23359_0_min, emitter.context().types().s16());
        /* execute.simd:132 [D] s_b_65_4 = s_b_65_2>s_b_65_3 */
        auto s_b_65_4 = emitter.cmp_gt(s_b_65_2, s_b_65_3);
        /* execute.simd:132 [D] s_b_65_5: If s_b_65_4: Jump b_66 else b_67 */
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
        /* execute.simd:133 [D] s_b_66_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_66_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_66_1 = constant u8 6 (const) */
        /* execute.simd:133 [D] s_b_66_0[s_b_66_1] */
        auto s_b_66_2 = emitter.vector_extract(s_b_66_0, emitter.const_u8((uint8_t)6ULL));
        /* execute.simd:133 [D] s_b_66_3: sym_23359_0_min = s_b_66_2, dominates: s_b_67_3 s_b_69_1  */
        emitter.store_local(DV_sym_23359_0_min, s_b_66_2);
        /* execute.simd:133 [F] s_b_66_4: Jump b_67 (const) */
        {
          auto block = block_b_67;
          dynamic_block_queue.push(block_b_67);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_67) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_67);
        /* execute.simd:132 [D] s_b_67_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_67_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_67_1 = constant u8 7 (const) */
        /* execute.simd:132 [D] s_b_67_0[s_b_67_1] */
        auto s_b_67_2 = emitter.vector_extract(s_b_67_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:132 [D] s_b_67_3 = sym_23359_0_min int16_t */
        auto s_b_67_3 = emitter.load_local(DV_sym_23359_0_min, emitter.context().types().s16());
        /* execute.simd:132 [D] s_b_67_4 = s_b_67_2>s_b_67_3 */
        auto s_b_67_4 = emitter.cmp_gt(s_b_67_2, s_b_67_3);
        /* execute.simd:132 [D] s_b_67_5: If s_b_67_4: Jump b_68 else b_69 */
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
        /* execute.simd:133 [D] s_b_68_0 = sym_23353_0_rn wutils::Vector<int16_t, 8> */
        auto s_b_68_0 = emitter.load_local(DV_sym_23353_0_rn, emitter.context().types().v8s16());
        /* ???:4294967295 [F] s_b_68_1 = constant u8 7 (const) */
        /* execute.simd:133 [D] s_b_68_0[s_b_68_1] */
        auto s_b_68_2 = emitter.vector_extract(s_b_68_0, emitter.const_u8((uint8_t)7ULL));
        /* execute.simd:133 [D] s_b_68_3: sym_23359_0_min = s_b_68_2, dominates: s_b_69_1  */
        emitter.store_local(DV_sym_23359_0_min, s_b_68_2);
        /* execute.simd:133 [F] s_b_68_4: Jump b_69 (const) */
        {
          auto block = block_b_69;
          dynamic_block_queue.push(block_b_69);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_69) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_69);
        /* execute.simd:137 [F] s_b_69_0=sym_22860_3_parameter_inst.rd (const) */
        /* execute.simd:137 [D] s_b_69_1 = sym_23359_0_min int16_t */
        auto s_b_69_1 = emitter.load_local(DV_sym_23359_0_min, emitter.context().types().s16());
        /* execute.simd:137 [D] s_b_69_2 = (u16)s_b_69_1 */
        auto s_b_69_2 = emitter.reinterpret(s_b_69_1, emitter.context().types().u16());
        /* execute.simd:6124 [D] s_b_69_3 = (u64)s_b_69_2 */
        auto s_b_69_3 = emitter.zx(s_b_69_2, emitter.context().types().u64());
        /* execute.simd:6124 [D] s_b_69_4: WriteRegBank 2:s_b_69_0 = s_b_69_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_69_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_69_3);
        /* execute.simd:6125 [F] s_b_69_5 = constant u64 0 (const) */
        /* execute.simd:6125 [F] s_b_69_6: WriteRegBank 3:s_b_69_0 = s_b_69_5 */
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
        /* execute.simd:146 [D] s_b_71_0 = sym_23492_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_71_0 = emitter.load_local(DV_sym_23492_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_71_1 = constant u8 1 (const) */
        /* execute.simd:146 [D] s_b_71_0[s_b_71_1] */
        auto s_b_71_2 = emitter.vector_extract(s_b_71_0, emitter.const_u8((uint8_t)1ULL));
        /* execute.simd:146 [D] s_b_71_3: sym_23498_0_min = s_b_71_2, dominates: s_b_72_3 s_b_74_3 s_b_76_1  */
        emitter.store_local(DV_sym_23498_0_min, s_b_71_2);
        /* execute.simd:146 [F] s_b_71_4: Jump b_72 (const) */
        {
          auto block = block_b_72;
          dynamic_block_queue.push(block_b_72);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_72) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_72);
        /* execute.simd:145 [D] s_b_72_0 = sym_23492_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_72_0 = emitter.load_local(DV_sym_23492_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_72_1 = constant u8 2 (const) */
        /* execute.simd:145 [D] s_b_72_0[s_b_72_1] */
        auto s_b_72_2 = emitter.vector_extract(s_b_72_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:145 [D] s_b_72_3 = sym_23498_0_min int32_t */
        auto s_b_72_3 = emitter.load_local(DV_sym_23498_0_min, emitter.context().types().s32());
        /* execute.simd:145 [D] s_b_72_4 = s_b_72_2>s_b_72_3 */
        auto s_b_72_4 = emitter.cmp_gt(s_b_72_2, s_b_72_3);
        /* execute.simd:145 [D] s_b_72_5: If s_b_72_4: Jump b_73 else b_74 */
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
        /* execute.simd:146 [D] s_b_73_0 = sym_23492_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_73_0 = emitter.load_local(DV_sym_23492_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_73_1 = constant u8 2 (const) */
        /* execute.simd:146 [D] s_b_73_0[s_b_73_1] */
        auto s_b_73_2 = emitter.vector_extract(s_b_73_0, emitter.const_u8((uint8_t)2ULL));
        /* execute.simd:146 [D] s_b_73_3: sym_23498_0_min = s_b_73_2, dominates: s_b_74_3 s_b_76_1  */
        emitter.store_local(DV_sym_23498_0_min, s_b_73_2);
        /* execute.simd:146 [F] s_b_73_4: Jump b_74 (const) */
        {
          auto block = block_b_74;
          dynamic_block_queue.push(block_b_74);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_74) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_74);
        /* execute.simd:145 [D] s_b_74_0 = sym_23492_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_74_0 = emitter.load_local(DV_sym_23492_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_74_1 = constant u8 3 (const) */
        /* execute.simd:145 [D] s_b_74_0[s_b_74_1] */
        auto s_b_74_2 = emitter.vector_extract(s_b_74_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:145 [D] s_b_74_3 = sym_23498_0_min int32_t */
        auto s_b_74_3 = emitter.load_local(DV_sym_23498_0_min, emitter.context().types().s32());
        /* execute.simd:145 [D] s_b_74_4 = s_b_74_2>s_b_74_3 */
        auto s_b_74_4 = emitter.cmp_gt(s_b_74_2, s_b_74_3);
        /* execute.simd:145 [D] s_b_74_5: If s_b_74_4: Jump b_75 else b_76 */
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
        /* execute.simd:146 [D] s_b_75_0 = sym_23492_0_rn wutils::Vector<int32_t, 4> */
        auto s_b_75_0 = emitter.load_local(DV_sym_23492_0_rn, emitter.context().types().v4s32());
        /* ???:4294967295 [F] s_b_75_1 = constant u8 3 (const) */
        /* execute.simd:146 [D] s_b_75_0[s_b_75_1] */
        auto s_b_75_2 = emitter.vector_extract(s_b_75_0, emitter.const_u8((uint8_t)3ULL));
        /* execute.simd:146 [D] s_b_75_3: sym_23498_0_min = s_b_75_2, dominates: s_b_76_1  */
        emitter.store_local(DV_sym_23498_0_min, s_b_75_2);
        /* execute.simd:146 [F] s_b_75_4: Jump b_76 (const) */
        {
          auto block = block_b_76;
          dynamic_block_queue.push(block_b_76);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_76) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_76);
        /* execute.simd:150 [F] s_b_76_0=sym_22860_3_parameter_inst.rd (const) */
        /* execute.simd:150 [D] s_b_76_1 = sym_23498_0_min int32_t */
        auto s_b_76_1 = emitter.load_local(DV_sym_23498_0_min, emitter.context().types().s32());
        /* execute.simd:150 [D] s_b_76_2 = (u32)s_b_76_1 */
        auto s_b_76_2 = emitter.reinterpret(s_b_76_1, emitter.context().types().u32());
        /* execute.simd:6131 [D] s_b_76_3 = (u64)s_b_76_2 */
        auto s_b_76_3 = emitter.zx(s_b_76_2, emitter.context().types().u64());
        /* execute.simd:6131 [D] s_b_76_4: WriteRegBank 2:s_b_76_0 = s_b_76_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_76_3,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_76_3);
        /* execute.simd:6132 [F] s_b_76_5 = constant u64 0 (const) */
        /* execute.simd:6132 [F] s_b_76_6: WriteRegBank 3:s_b_76_0 = s_b_76_5 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sshll(const aarch64_decode_a64_SIMD_SHIFT_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3170 [F] s_b_0_0=sym_27668_3_parameter_inst.arrangement (const) */
    /* execute.simd:3171 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:3182 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:3193 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:3204 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:3215 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:3226 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:3170 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:3172 [F] s_b_2_0=sym_27668_3_parameter_inst.rn (const) */
    /* execute.simd:3172 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:3172 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_3 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_4 = constant u8 0 (const) */
    /* execute.simd:3176 [D] s_b_2_2[s_b_2_4] */
    auto s_b_2_5 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3176 [D] s_b_2_6 = (s16)s_b_2_5 */
    auto s_b_2_6 = emitter.sx(s_b_2_5, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_7=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3176 [D] s_b_2_8 = (u16)s_b_2_6 */
    auto s_b_2_8 = emitter.reinterpret(s_b_2_6, emitter.context().types().u16());
    /* execute.simd:3176 [F] s_b_2_9 = (u16)s_b_2_7 (const) */
    /* execute.simd:3176 [D] s_b_2_10 = s_b_2_8<<s_b_2_9 */
    auto s_b_2_10 = emitter.shl(s_b_2_8, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3176 [D] s_b_2_11 = (s16)s_b_2_10 */
    auto s_b_2_11 = emitter.reinterpret(s_b_2_10, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_12 = constant s32 0 (const) */
    /* execute.simd:3176 [D] s_b_2_13 = s_b_2_3[s_b_2_12] <= s_b_2_11 */
    auto s_b_2_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_11);
    /* ???:4294967295 [F] s_b_2_14 = constant u8 1 (const) */
    /* execute.simd:3176 [D] s_b_2_2[s_b_2_14] */
    auto s_b_2_15 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3176 [D] s_b_2_16 = (s16)s_b_2_15 */
    auto s_b_2_16 = emitter.sx(s_b_2_15, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_17=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3176 [D] s_b_2_18 = (u16)s_b_2_16 */
    auto s_b_2_18 = emitter.reinterpret(s_b_2_16, emitter.context().types().u16());
    /* execute.simd:3176 [F] s_b_2_19 = (u16)s_b_2_17 (const) */
    /* execute.simd:3176 [D] s_b_2_20 = s_b_2_18<<s_b_2_19 */
    auto s_b_2_20 = emitter.shl(s_b_2_18, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3176 [D] s_b_2_21 = (s16)s_b_2_20 */
    auto s_b_2_21 = emitter.reinterpret(s_b_2_20, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_22 = constant s32 1 (const) */
    /* execute.simd:3176 [D] s_b_2_23 = s_b_2_13[s_b_2_22] <= s_b_2_21 */
    auto s_b_2_23 = emitter.vector_insert(s_b_2_13, emitter.const_s32((int32_t)1ULL), s_b_2_21);
    /* ???:4294967295 [F] s_b_2_24 = constant u8 2 (const) */
    /* execute.simd:3176 [D] s_b_2_2[s_b_2_24] */
    auto s_b_2_25 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3176 [D] s_b_2_26 = (s16)s_b_2_25 */
    auto s_b_2_26 = emitter.sx(s_b_2_25, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_27=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3176 [D] s_b_2_28 = (u16)s_b_2_26 */
    auto s_b_2_28 = emitter.reinterpret(s_b_2_26, emitter.context().types().u16());
    /* execute.simd:3176 [F] s_b_2_29 = (u16)s_b_2_27 (const) */
    /* execute.simd:3176 [D] s_b_2_30 = s_b_2_28<<s_b_2_29 */
    auto s_b_2_30 = emitter.shl(s_b_2_28, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3176 [D] s_b_2_31 = (s16)s_b_2_30 */
    auto s_b_2_31 = emitter.reinterpret(s_b_2_30, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:3176 [D] s_b_2_33 = s_b_2_23[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_23, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:3176 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3176 [D] s_b_2_36 = (s16)s_b_2_35 */
    auto s_b_2_36 = emitter.sx(s_b_2_35, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_37=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3176 [D] s_b_2_38 = (u16)s_b_2_36 */
    auto s_b_2_38 = emitter.reinterpret(s_b_2_36, emitter.context().types().u16());
    /* execute.simd:3176 [F] s_b_2_39 = (u16)s_b_2_37 (const) */
    /* execute.simd:3176 [D] s_b_2_40 = s_b_2_38<<s_b_2_39 */
    auto s_b_2_40 = emitter.shl(s_b_2_38, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3176 [D] s_b_2_41 = (s16)s_b_2_40 */
    auto s_b_2_41 = emitter.reinterpret(s_b_2_40, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_42 = constant s32 3 (const) */
    /* execute.simd:3176 [D] s_b_2_43 = s_b_2_33[s_b_2_42] <= s_b_2_41 */
    auto s_b_2_43 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_41);
    /* ???:4294967295 [F] s_b_2_44 = constant u8 4 (const) */
    /* execute.simd:3176 [D] s_b_2_2[s_b_2_44] */
    auto s_b_2_45 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3176 [D] s_b_2_46 = (s16)s_b_2_45 */
    auto s_b_2_46 = emitter.sx(s_b_2_45, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_47=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3176 [D] s_b_2_48 = (u16)s_b_2_46 */
    auto s_b_2_48 = emitter.reinterpret(s_b_2_46, emitter.context().types().u16());
    /* execute.simd:3176 [F] s_b_2_49 = (u16)s_b_2_47 (const) */
    /* execute.simd:3176 [D] s_b_2_50 = s_b_2_48<<s_b_2_49 */
    auto s_b_2_50 = emitter.shl(s_b_2_48, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3176 [D] s_b_2_51 = (s16)s_b_2_50 */
    auto s_b_2_51 = emitter.reinterpret(s_b_2_50, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_52 = constant s32 4 (const) */
    /* execute.simd:3176 [D] s_b_2_53 = s_b_2_43[s_b_2_52] <= s_b_2_51 */
    auto s_b_2_53 = emitter.vector_insert(s_b_2_43, emitter.const_s32((int32_t)4ULL), s_b_2_51);
    /* ???:4294967295 [F] s_b_2_54 = constant u8 5 (const) */
    /* execute.simd:3176 [D] s_b_2_2[s_b_2_54] */
    auto s_b_2_55 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3176 [D] s_b_2_56 = (s16)s_b_2_55 */
    auto s_b_2_56 = emitter.sx(s_b_2_55, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_57=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3176 [D] s_b_2_58 = (u16)s_b_2_56 */
    auto s_b_2_58 = emitter.reinterpret(s_b_2_56, emitter.context().types().u16());
    /* execute.simd:3176 [F] s_b_2_59 = (u16)s_b_2_57 (const) */
    /* execute.simd:3176 [D] s_b_2_60 = s_b_2_58<<s_b_2_59 */
    auto s_b_2_60 = emitter.shl(s_b_2_58, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3176 [D] s_b_2_61 = (s16)s_b_2_60 */
    auto s_b_2_61 = emitter.reinterpret(s_b_2_60, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_62 = constant s32 5 (const) */
    /* execute.simd:3176 [D] s_b_2_63 = s_b_2_53[s_b_2_62] <= s_b_2_61 */
    auto s_b_2_63 = emitter.vector_insert(s_b_2_53, emitter.const_s32((int32_t)5ULL), s_b_2_61);
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:3176 [D] s_b_2_2[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3176 [D] s_b_2_66 = (s16)s_b_2_65 */
    auto s_b_2_66 = emitter.sx(s_b_2_65, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_67=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3176 [D] s_b_2_68 = (u16)s_b_2_66 */
    auto s_b_2_68 = emitter.reinterpret(s_b_2_66, emitter.context().types().u16());
    /* execute.simd:3176 [F] s_b_2_69 = (u16)s_b_2_67 (const) */
    /* execute.simd:3176 [D] s_b_2_70 = s_b_2_68<<s_b_2_69 */
    auto s_b_2_70 = emitter.shl(s_b_2_68, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3176 [D] s_b_2_71 = (s16)s_b_2_70 */
    auto s_b_2_71 = emitter.reinterpret(s_b_2_70, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_72 = constant s32 6 (const) */
    /* execute.simd:3176 [D] s_b_2_73 = s_b_2_63[s_b_2_72] <= s_b_2_71 */
    auto s_b_2_73 = emitter.vector_insert(s_b_2_63, emitter.const_s32((int32_t)6ULL), s_b_2_71);
    /* ???:4294967295 [F] s_b_2_74 = constant u8 7 (const) */
    /* execute.simd:3176 [D] s_b_2_2[s_b_2_74] */
    auto s_b_2_75 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3176 [D] s_b_2_76 = (s16)s_b_2_75 */
    auto s_b_2_76 = emitter.sx(s_b_2_75, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_77=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3176 [D] s_b_2_78 = (u16)s_b_2_76 */
    auto s_b_2_78 = emitter.reinterpret(s_b_2_76, emitter.context().types().u16());
    /* execute.simd:3176 [F] s_b_2_79 = (u16)s_b_2_77 (const) */
    /* execute.simd:3176 [D] s_b_2_80 = s_b_2_78<<s_b_2_79 */
    auto s_b_2_80 = emitter.shl(s_b_2_78, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3176 [D] s_b_2_81 = (s16)s_b_2_80 */
    auto s_b_2_81 = emitter.reinterpret(s_b_2_80, emitter.context().types().s16());
    /* execute.simd:3176 [F] s_b_2_82 = constant s32 7 (const) */
    /* execute.simd:3176 [D] s_b_2_83 = s_b_2_73[s_b_2_82] <= s_b_2_81 */
    auto s_b_2_83 = emitter.vector_insert(s_b_2_73, emitter.const_s32((int32_t)7ULL), s_b_2_81);
    /* execute.simd:3179 [F] s_b_2_84=sym_27668_3_parameter_inst.rd (const) */
    /* execute.simd:3179 [D] s_b_2_85 = (v8u16)s_b_2_83 */
    auto s_b_2_85 = emitter.reinterpret(s_b_2_83, emitter.context().types().v8u16());
    /* execute.simd:3179 [D] s_b_2_86: WriteRegBank 18:s_b_2_84 = s_b_2_85 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_85,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_85);
    /* execute.simd:0 [F] s_b_2_87: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:3183 [F] s_b_3_0=sym_27668_3_parameter_inst.rn (const) */
    /* execute.simd:3183 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:3183 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_3 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_3_4 = constant u8 8 (const) */
    /* execute.simd:3187 [D] s_b_3_2[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)8ULL));
    /* execute.simd:3187 [D] s_b_3_6 = (s16)s_b_3_5 */
    auto s_b_3_6 = emitter.sx(s_b_3_5, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_7=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3187 [D] s_b_3_8 = (u16)s_b_3_6 */
    auto s_b_3_8 = emitter.reinterpret(s_b_3_6, emitter.context().types().u16());
    /* execute.simd:3187 [F] s_b_3_9 = (u16)s_b_3_7 (const) */
    /* execute.simd:3187 [D] s_b_3_10 = s_b_3_8<<s_b_3_9 */
    auto s_b_3_10 = emitter.shl(s_b_3_8, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3187 [D] s_b_3_11 = (s16)s_b_3_10 */
    auto s_b_3_11 = emitter.reinterpret(s_b_3_10, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_12 = constant s32 0 (const) */
    /* execute.simd:3187 [D] s_b_3_13 = s_b_3_3[s_b_3_12] <= s_b_3_11 */
    auto s_b_3_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_11);
    /* ???:4294967295 [F] s_b_3_14 = constant u8 9 (const) */
    /* execute.simd:3187 [D] s_b_3_2[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)9ULL));
    /* execute.simd:3187 [D] s_b_3_16 = (s16)s_b_3_15 */
    auto s_b_3_16 = emitter.sx(s_b_3_15, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_17=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3187 [D] s_b_3_18 = (u16)s_b_3_16 */
    auto s_b_3_18 = emitter.reinterpret(s_b_3_16, emitter.context().types().u16());
    /* execute.simd:3187 [F] s_b_3_19 = (u16)s_b_3_17 (const) */
    /* execute.simd:3187 [D] s_b_3_20 = s_b_3_18<<s_b_3_19 */
    auto s_b_3_20 = emitter.shl(s_b_3_18, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3187 [D] s_b_3_21 = (s16)s_b_3_20 */
    auto s_b_3_21 = emitter.reinterpret(s_b_3_20, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_22 = constant s32 1 (const) */
    /* execute.simd:3187 [D] s_b_3_23 = s_b_3_13[s_b_3_22] <= s_b_3_21 */
    auto s_b_3_23 = emitter.vector_insert(s_b_3_13, emitter.const_s32((int32_t)1ULL), s_b_3_21);
    /* ???:4294967295 [F] s_b_3_24 = constant u8 a (const) */
    /* execute.simd:3187 [D] s_b_3_2[s_b_3_24] */
    auto s_b_3_25 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)10ULL));
    /* execute.simd:3187 [D] s_b_3_26 = (s16)s_b_3_25 */
    auto s_b_3_26 = emitter.sx(s_b_3_25, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_27=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3187 [D] s_b_3_28 = (u16)s_b_3_26 */
    auto s_b_3_28 = emitter.reinterpret(s_b_3_26, emitter.context().types().u16());
    /* execute.simd:3187 [F] s_b_3_29 = (u16)s_b_3_27 (const) */
    /* execute.simd:3187 [D] s_b_3_30 = s_b_3_28<<s_b_3_29 */
    auto s_b_3_30 = emitter.shl(s_b_3_28, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3187 [D] s_b_3_31 = (s16)s_b_3_30 */
    auto s_b_3_31 = emitter.reinterpret(s_b_3_30, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:3187 [D] s_b_3_33 = s_b_3_23[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_23, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* ???:4294967295 [F] s_b_3_34 = constant u8 b (const) */
    /* execute.simd:3187 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)11ULL));
    /* execute.simd:3187 [D] s_b_3_36 = (s16)s_b_3_35 */
    auto s_b_3_36 = emitter.sx(s_b_3_35, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_37=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3187 [D] s_b_3_38 = (u16)s_b_3_36 */
    auto s_b_3_38 = emitter.reinterpret(s_b_3_36, emitter.context().types().u16());
    /* execute.simd:3187 [F] s_b_3_39 = (u16)s_b_3_37 (const) */
    /* execute.simd:3187 [D] s_b_3_40 = s_b_3_38<<s_b_3_39 */
    auto s_b_3_40 = emitter.shl(s_b_3_38, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3187 [D] s_b_3_41 = (s16)s_b_3_40 */
    auto s_b_3_41 = emitter.reinterpret(s_b_3_40, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_42 = constant s32 3 (const) */
    /* execute.simd:3187 [D] s_b_3_43 = s_b_3_33[s_b_3_42] <= s_b_3_41 */
    auto s_b_3_43 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_41);
    /* ???:4294967295 [F] s_b_3_44 = constant u8 c (const) */
    /* execute.simd:3187 [D] s_b_3_2[s_b_3_44] */
    auto s_b_3_45 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)12ULL));
    /* execute.simd:3187 [D] s_b_3_46 = (s16)s_b_3_45 */
    auto s_b_3_46 = emitter.sx(s_b_3_45, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_47=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3187 [D] s_b_3_48 = (u16)s_b_3_46 */
    auto s_b_3_48 = emitter.reinterpret(s_b_3_46, emitter.context().types().u16());
    /* execute.simd:3187 [F] s_b_3_49 = (u16)s_b_3_47 (const) */
    /* execute.simd:3187 [D] s_b_3_50 = s_b_3_48<<s_b_3_49 */
    auto s_b_3_50 = emitter.shl(s_b_3_48, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3187 [D] s_b_3_51 = (s16)s_b_3_50 */
    auto s_b_3_51 = emitter.reinterpret(s_b_3_50, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_52 = constant s32 4 (const) */
    /* execute.simd:3187 [D] s_b_3_53 = s_b_3_43[s_b_3_52] <= s_b_3_51 */
    auto s_b_3_53 = emitter.vector_insert(s_b_3_43, emitter.const_s32((int32_t)4ULL), s_b_3_51);
    /* ???:4294967295 [F] s_b_3_54 = constant u8 d (const) */
    /* execute.simd:3187 [D] s_b_3_2[s_b_3_54] */
    auto s_b_3_55 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)13ULL));
    /* execute.simd:3187 [D] s_b_3_56 = (s16)s_b_3_55 */
    auto s_b_3_56 = emitter.sx(s_b_3_55, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_57=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3187 [D] s_b_3_58 = (u16)s_b_3_56 */
    auto s_b_3_58 = emitter.reinterpret(s_b_3_56, emitter.context().types().u16());
    /* execute.simd:3187 [F] s_b_3_59 = (u16)s_b_3_57 (const) */
    /* execute.simd:3187 [D] s_b_3_60 = s_b_3_58<<s_b_3_59 */
    auto s_b_3_60 = emitter.shl(s_b_3_58, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3187 [D] s_b_3_61 = (s16)s_b_3_60 */
    auto s_b_3_61 = emitter.reinterpret(s_b_3_60, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_62 = constant s32 5 (const) */
    /* execute.simd:3187 [D] s_b_3_63 = s_b_3_53[s_b_3_62] <= s_b_3_61 */
    auto s_b_3_63 = emitter.vector_insert(s_b_3_53, emitter.const_s32((int32_t)5ULL), s_b_3_61);
    /* ???:4294967295 [F] s_b_3_64 = constant u8 e (const) */
    /* execute.simd:3187 [D] s_b_3_2[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)14ULL));
    /* execute.simd:3187 [D] s_b_3_66 = (s16)s_b_3_65 */
    auto s_b_3_66 = emitter.sx(s_b_3_65, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_67=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3187 [D] s_b_3_68 = (u16)s_b_3_66 */
    auto s_b_3_68 = emitter.reinterpret(s_b_3_66, emitter.context().types().u16());
    /* execute.simd:3187 [F] s_b_3_69 = (u16)s_b_3_67 (const) */
    /* execute.simd:3187 [D] s_b_3_70 = s_b_3_68<<s_b_3_69 */
    auto s_b_3_70 = emitter.shl(s_b_3_68, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3187 [D] s_b_3_71 = (s16)s_b_3_70 */
    auto s_b_3_71 = emitter.reinterpret(s_b_3_70, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_72 = constant s32 6 (const) */
    /* execute.simd:3187 [D] s_b_3_73 = s_b_3_63[s_b_3_72] <= s_b_3_71 */
    auto s_b_3_73 = emitter.vector_insert(s_b_3_63, emitter.const_s32((int32_t)6ULL), s_b_3_71);
    /* ???:4294967295 [F] s_b_3_74 = constant u8 f (const) */
    /* execute.simd:3187 [D] s_b_3_2[s_b_3_74] */
    auto s_b_3_75 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)15ULL));
    /* execute.simd:3187 [D] s_b_3_76 = (s16)s_b_3_75 */
    auto s_b_3_76 = emitter.sx(s_b_3_75, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_77=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3187 [D] s_b_3_78 = (u16)s_b_3_76 */
    auto s_b_3_78 = emitter.reinterpret(s_b_3_76, emitter.context().types().u16());
    /* execute.simd:3187 [F] s_b_3_79 = (u16)s_b_3_77 (const) */
    /* execute.simd:3187 [D] s_b_3_80 = s_b_3_78<<s_b_3_79 */
    auto s_b_3_80 = emitter.shl(s_b_3_78, emitter.const_u16(((uint16_t)insn.shift_amount)));
    /* execute.simd:3187 [D] s_b_3_81 = (s16)s_b_3_80 */
    auto s_b_3_81 = emitter.reinterpret(s_b_3_80, emitter.context().types().s16());
    /* execute.simd:3187 [F] s_b_3_82 = constant s32 7 (const) */
    /* execute.simd:3187 [D] s_b_3_83 = s_b_3_73[s_b_3_82] <= s_b_3_81 */
    auto s_b_3_83 = emitter.vector_insert(s_b_3_73, emitter.const_s32((int32_t)7ULL), s_b_3_81);
    /* execute.simd:3190 [F] s_b_3_84=sym_27668_3_parameter_inst.rd (const) */
    /* execute.simd:3190 [D] s_b_3_85 = (v8u16)s_b_3_83 */
    auto s_b_3_85 = emitter.reinterpret(s_b_3_83, emitter.context().types().v8u16());
    /* execute.simd:3190 [D] s_b_3_86: WriteRegBank 18:s_b_3_84 = s_b_3_85 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_85,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_85);
    /* execute.simd:0 [F] s_b_3_87: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:3194 [F] s_b_4_0=sym_27668_3_parameter_inst.rn (const) */
    /* execute.simd:3194 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:3194 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_3 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_4 = constant u8 0 (const) */
    /* execute.simd:3198 [D] s_b_4_2[s_b_4_4] */
    auto s_b_4_5 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3198 [D] s_b_4_6 = (s32)s_b_4_5 */
    auto s_b_4_6 = emitter.sx(s_b_4_5, emitter.context().types().s32());
    /* execute.simd:3198 [F] s_b_4_7=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3198 [D] s_b_4_8 = (u32)s_b_4_6 */
    auto s_b_4_8 = emitter.reinterpret(s_b_4_6, emitter.context().types().u32());
    /* execute.simd:3198 [F] s_b_4_9 = (u32)s_b_4_7 (const) */
    /* execute.simd:3198 [D] s_b_4_10 = s_b_4_8<<s_b_4_9 */
    auto s_b_4_10 = emitter.shl(s_b_4_8, emitter.const_u32(((uint32_t)insn.shift_amount)));
    /* execute.simd:3198 [D] s_b_4_11 = (s32)s_b_4_10 */
    auto s_b_4_11 = emitter.reinterpret(s_b_4_10, emitter.context().types().s32());
    /* execute.simd:3198 [F] s_b_4_12 = constant s32 0 (const) */
    /* execute.simd:3198 [D] s_b_4_13 = s_b_4_3[s_b_4_12] <= s_b_4_11 */
    auto s_b_4_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_11);
    /* ???:4294967295 [F] s_b_4_14 = constant u8 1 (const) */
    /* execute.simd:3198 [D] s_b_4_2[s_b_4_14] */
    auto s_b_4_15 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3198 [D] s_b_4_16 = (s32)s_b_4_15 */
    auto s_b_4_16 = emitter.sx(s_b_4_15, emitter.context().types().s32());
    /* execute.simd:3198 [F] s_b_4_17=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3198 [D] s_b_4_18 = (u32)s_b_4_16 */
    auto s_b_4_18 = emitter.reinterpret(s_b_4_16, emitter.context().types().u32());
    /* execute.simd:3198 [F] s_b_4_19 = (u32)s_b_4_17 (const) */
    /* execute.simd:3198 [D] s_b_4_20 = s_b_4_18<<s_b_4_19 */
    auto s_b_4_20 = emitter.shl(s_b_4_18, emitter.const_u32(((uint32_t)insn.shift_amount)));
    /* execute.simd:3198 [D] s_b_4_21 = (s32)s_b_4_20 */
    auto s_b_4_21 = emitter.reinterpret(s_b_4_20, emitter.context().types().s32());
    /* execute.simd:3198 [F] s_b_4_22 = constant s32 1 (const) */
    /* execute.simd:3198 [D] s_b_4_23 = s_b_4_13[s_b_4_22] <= s_b_4_21 */
    auto s_b_4_23 = emitter.vector_insert(s_b_4_13, emitter.const_s32((int32_t)1ULL), s_b_4_21);
    /* ???:4294967295 [F] s_b_4_24 = constant u8 2 (const) */
    /* execute.simd:3198 [D] s_b_4_2[s_b_4_24] */
    auto s_b_4_25 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3198 [D] s_b_4_26 = (s32)s_b_4_25 */
    auto s_b_4_26 = emitter.sx(s_b_4_25, emitter.context().types().s32());
    /* execute.simd:3198 [F] s_b_4_27=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3198 [D] s_b_4_28 = (u32)s_b_4_26 */
    auto s_b_4_28 = emitter.reinterpret(s_b_4_26, emitter.context().types().u32());
    /* execute.simd:3198 [F] s_b_4_29 = (u32)s_b_4_27 (const) */
    /* execute.simd:3198 [D] s_b_4_30 = s_b_4_28<<s_b_4_29 */
    auto s_b_4_30 = emitter.shl(s_b_4_28, emitter.const_u32(((uint32_t)insn.shift_amount)));
    /* execute.simd:3198 [D] s_b_4_31 = (s32)s_b_4_30 */
    auto s_b_4_31 = emitter.reinterpret(s_b_4_30, emitter.context().types().s32());
    /* execute.simd:3198 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:3198 [D] s_b_4_33 = s_b_4_23[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_23, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:3198 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3198 [D] s_b_4_36 = (s32)s_b_4_35 */
    auto s_b_4_36 = emitter.sx(s_b_4_35, emitter.context().types().s32());
    /* execute.simd:3198 [F] s_b_4_37=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3198 [D] s_b_4_38 = (u32)s_b_4_36 */
    auto s_b_4_38 = emitter.reinterpret(s_b_4_36, emitter.context().types().u32());
    /* execute.simd:3198 [F] s_b_4_39 = (u32)s_b_4_37 (const) */
    /* execute.simd:3198 [D] s_b_4_40 = s_b_4_38<<s_b_4_39 */
    auto s_b_4_40 = emitter.shl(s_b_4_38, emitter.const_u32(((uint32_t)insn.shift_amount)));
    /* execute.simd:3198 [D] s_b_4_41 = (s32)s_b_4_40 */
    auto s_b_4_41 = emitter.reinterpret(s_b_4_40, emitter.context().types().s32());
    /* execute.simd:3198 [F] s_b_4_42 = constant s32 3 (const) */
    /* execute.simd:3198 [D] s_b_4_43 = s_b_4_33[s_b_4_42] <= s_b_4_41 */
    auto s_b_4_43 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_41);
    /* execute.simd:3201 [F] s_b_4_44=sym_27668_3_parameter_inst.rd (const) */
    /* execute.simd:3201 [D] s_b_4_45 = (v4u32)s_b_4_43 */
    auto s_b_4_45 = emitter.reinterpret(s_b_4_43, emitter.context().types().v4u32());
    /* execute.simd:3201 [D] s_b_4_46: WriteRegBank 20:s_b_4_44 = s_b_4_45 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_45,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_45);
    /* execute.simd:0 [F] s_b_4_47: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:3205 [F] s_b_5_0=sym_27668_3_parameter_inst.rn (const) */
    /* execute.simd:3205 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:3205 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_3 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_5_4 = constant u8 4 (const) */
    /* execute.simd:3209 [D] s_b_5_2[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3209 [D] s_b_5_6 = (s32)s_b_5_5 */
    auto s_b_5_6 = emitter.sx(s_b_5_5, emitter.context().types().s32());
    /* execute.simd:3209 [F] s_b_5_7=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3209 [D] s_b_5_8 = (u32)s_b_5_6 */
    auto s_b_5_8 = emitter.reinterpret(s_b_5_6, emitter.context().types().u32());
    /* execute.simd:3209 [F] s_b_5_9 = (u32)s_b_5_7 (const) */
    /* execute.simd:3209 [D] s_b_5_10 = s_b_5_8<<s_b_5_9 */
    auto s_b_5_10 = emitter.shl(s_b_5_8, emitter.const_u32(((uint32_t)insn.shift_amount)));
    /* execute.simd:3209 [D] s_b_5_11 = (s32)s_b_5_10 */
    auto s_b_5_11 = emitter.reinterpret(s_b_5_10, emitter.context().types().s32());
    /* execute.simd:3209 [F] s_b_5_12 = constant s32 0 (const) */
    /* execute.simd:3209 [D] s_b_5_13 = s_b_5_3[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_11);
    /* ???:4294967295 [F] s_b_5_14 = constant u8 5 (const) */
    /* execute.simd:3209 [D] s_b_5_2[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3209 [D] s_b_5_16 = (s32)s_b_5_15 */
    auto s_b_5_16 = emitter.sx(s_b_5_15, emitter.context().types().s32());
    /* execute.simd:3209 [F] s_b_5_17=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3209 [D] s_b_5_18 = (u32)s_b_5_16 */
    auto s_b_5_18 = emitter.reinterpret(s_b_5_16, emitter.context().types().u32());
    /* execute.simd:3209 [F] s_b_5_19 = (u32)s_b_5_17 (const) */
    /* execute.simd:3209 [D] s_b_5_20 = s_b_5_18<<s_b_5_19 */
    auto s_b_5_20 = emitter.shl(s_b_5_18, emitter.const_u32(((uint32_t)insn.shift_amount)));
    /* execute.simd:3209 [D] s_b_5_21 = (s32)s_b_5_20 */
    auto s_b_5_21 = emitter.reinterpret(s_b_5_20, emitter.context().types().s32());
    /* execute.simd:3209 [F] s_b_5_22 = constant s32 1 (const) */
    /* execute.simd:3209 [D] s_b_5_23 = s_b_5_13[s_b_5_22] <= s_b_5_21 */
    auto s_b_5_23 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)1ULL), s_b_5_21);
    /* ???:4294967295 [F] s_b_5_24 = constant u8 6 (const) */
    /* execute.simd:3209 [D] s_b_5_2[s_b_5_24] */
    auto s_b_5_25 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3209 [D] s_b_5_26 = (s32)s_b_5_25 */
    auto s_b_5_26 = emitter.sx(s_b_5_25, emitter.context().types().s32());
    /* execute.simd:3209 [F] s_b_5_27=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3209 [D] s_b_5_28 = (u32)s_b_5_26 */
    auto s_b_5_28 = emitter.reinterpret(s_b_5_26, emitter.context().types().u32());
    /* execute.simd:3209 [F] s_b_5_29 = (u32)s_b_5_27 (const) */
    /* execute.simd:3209 [D] s_b_5_30 = s_b_5_28<<s_b_5_29 */
    auto s_b_5_30 = emitter.shl(s_b_5_28, emitter.const_u32(((uint32_t)insn.shift_amount)));
    /* execute.simd:3209 [D] s_b_5_31 = (s32)s_b_5_30 */
    auto s_b_5_31 = emitter.reinterpret(s_b_5_30, emitter.context().types().s32());
    /* execute.simd:3209 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:3209 [D] s_b_5_33 = s_b_5_23[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_23, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* ???:4294967295 [F] s_b_5_34 = constant u8 7 (const) */
    /* execute.simd:3209 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3209 [D] s_b_5_36 = (s32)s_b_5_35 */
    auto s_b_5_36 = emitter.sx(s_b_5_35, emitter.context().types().s32());
    /* execute.simd:3209 [F] s_b_5_37=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3209 [D] s_b_5_38 = (u32)s_b_5_36 */
    auto s_b_5_38 = emitter.reinterpret(s_b_5_36, emitter.context().types().u32());
    /* execute.simd:3209 [F] s_b_5_39 = (u32)s_b_5_37 (const) */
    /* execute.simd:3209 [D] s_b_5_40 = s_b_5_38<<s_b_5_39 */
    auto s_b_5_40 = emitter.shl(s_b_5_38, emitter.const_u32(((uint32_t)insn.shift_amount)));
    /* execute.simd:3209 [D] s_b_5_41 = (s32)s_b_5_40 */
    auto s_b_5_41 = emitter.reinterpret(s_b_5_40, emitter.context().types().s32());
    /* execute.simd:3209 [F] s_b_5_42 = constant s32 3 (const) */
    /* execute.simd:3209 [D] s_b_5_43 = s_b_5_33[s_b_5_42] <= s_b_5_41 */
    auto s_b_5_43 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_41);
    /* execute.simd:3212 [F] s_b_5_44=sym_27668_3_parameter_inst.rd (const) */
    /* execute.simd:3212 [D] s_b_5_45 = (v4u32)s_b_5_43 */
    auto s_b_5_45 = emitter.reinterpret(s_b_5_43, emitter.context().types().v4u32());
    /* execute.simd:3212 [D] s_b_5_46: WriteRegBank 20:s_b_5_44 = s_b_5_45 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_45,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_45);
    /* execute.simd:0 [F] s_b_5_47: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:3216 [F] s_b_6_0=sym_27668_3_parameter_inst.rn (const) */
    /* execute.simd:3216 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:3216 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_3 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_4 = constant u8 0 (const) */
    /* execute.simd:3220 [D] s_b_6_2[s_b_6_4] */
    auto s_b_6_5 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3220 [D] s_b_6_6 = (s64)s_b_6_5 */
    auto s_b_6_6 = emitter.sx(s_b_6_5, emitter.context().types().s64());
    /* execute.simd:3220 [F] s_b_6_7=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3220 [D] s_b_6_8 = (u64)s_b_6_6 */
    auto s_b_6_8 = emitter.reinterpret(s_b_6_6, emitter.context().types().u64());
    /* execute.simd:3220 [F] s_b_6_9 = (u64)s_b_6_7 (const) */
    /* execute.simd:3220 [D] s_b_6_10 = s_b_6_8<<s_b_6_9 */
    auto s_b_6_10 = emitter.shl(s_b_6_8, emitter.const_u64(((uint64_t)insn.shift_amount)));
    /* execute.simd:3220 [D] s_b_6_11 = (s64)s_b_6_10 */
    auto s_b_6_11 = emitter.reinterpret(s_b_6_10, emitter.context().types().s64());
    /* execute.simd:3220 [F] s_b_6_12 = constant s32 0 (const) */
    /* execute.simd:3220 [D] s_b_6_13 = s_b_6_3[s_b_6_12] <= s_b_6_11 */
    auto s_b_6_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_11);
    /* ???:4294967295 [F] s_b_6_14 = constant u8 1 (const) */
    /* execute.simd:3220 [D] s_b_6_2[s_b_6_14] */
    auto s_b_6_15 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3220 [D] s_b_6_16 = (s64)s_b_6_15 */
    auto s_b_6_16 = emitter.sx(s_b_6_15, emitter.context().types().s64());
    /* execute.simd:3220 [F] s_b_6_17=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3220 [D] s_b_6_18 = (u64)s_b_6_16 */
    auto s_b_6_18 = emitter.reinterpret(s_b_6_16, emitter.context().types().u64());
    /* execute.simd:3220 [F] s_b_6_19 = (u64)s_b_6_17 (const) */
    /* execute.simd:3220 [D] s_b_6_20 = s_b_6_18<<s_b_6_19 */
    auto s_b_6_20 = emitter.shl(s_b_6_18, emitter.const_u64(((uint64_t)insn.shift_amount)));
    /* execute.simd:3220 [D] s_b_6_21 = (s64)s_b_6_20 */
    auto s_b_6_21 = emitter.reinterpret(s_b_6_20, emitter.context().types().s64());
    /* execute.simd:3220 [F] s_b_6_22 = constant s32 1 (const) */
    /* execute.simd:3220 [D] s_b_6_23 = s_b_6_13[s_b_6_22] <= s_b_6_21 */
    auto s_b_6_23 = emitter.vector_insert(s_b_6_13, emitter.const_s32((int32_t)1ULL), s_b_6_21);
    /* execute.simd:3223 [F] s_b_6_24=sym_27668_3_parameter_inst.rd (const) */
    /* execute.simd:3223 [D] s_b_6_25 = (v2u64)s_b_6_23 */
    auto s_b_6_25 = emitter.reinterpret(s_b_6_23, emitter.context().types().v2u64());
    /* execute.simd:3223 [D] s_b_6_26: WriteRegBank 21:s_b_6_24 = s_b_6_25 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_25,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_25);
    /* execute.simd:0 [F] s_b_6_27: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:3227 [F] s_b_7_0=sym_27668_3_parameter_inst.rn (const) */
    /* execute.simd:3227 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:3227 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_3 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_7_4 = constant u8 2 (const) */
    /* execute.simd:3231 [D] s_b_7_2[s_b_7_4] */
    auto s_b_7_5 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3231 [D] s_b_7_6 = (s64)s_b_7_5 */
    auto s_b_7_6 = emitter.sx(s_b_7_5, emitter.context().types().s64());
    /* execute.simd:3231 [F] s_b_7_7=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3231 [D] s_b_7_8 = (u64)s_b_7_6 */
    auto s_b_7_8 = emitter.reinterpret(s_b_7_6, emitter.context().types().u64());
    /* execute.simd:3231 [F] s_b_7_9 = (u64)s_b_7_7 (const) */
    /* execute.simd:3231 [D] s_b_7_10 = s_b_7_8<<s_b_7_9 */
    auto s_b_7_10 = emitter.shl(s_b_7_8, emitter.const_u64(((uint64_t)insn.shift_amount)));
    /* execute.simd:3231 [D] s_b_7_11 = (s64)s_b_7_10 */
    auto s_b_7_11 = emitter.reinterpret(s_b_7_10, emitter.context().types().s64());
    /* execute.simd:3231 [F] s_b_7_12 = constant s32 0 (const) */
    /* execute.simd:3231 [D] s_b_7_13 = s_b_7_3[s_b_7_12] <= s_b_7_11 */
    auto s_b_7_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_11);
    /* ???:4294967295 [F] s_b_7_14 = constant u8 3 (const) */
    /* execute.simd:3231 [D] s_b_7_2[s_b_7_14] */
    auto s_b_7_15 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3231 [D] s_b_7_16 = (s64)s_b_7_15 */
    auto s_b_7_16 = emitter.sx(s_b_7_15, emitter.context().types().s64());
    /* execute.simd:3231 [F] s_b_7_17=sym_27668_3_parameter_inst.shift_amount (const) */
    /* execute.simd:3231 [D] s_b_7_18 = (u64)s_b_7_16 */
    auto s_b_7_18 = emitter.reinterpret(s_b_7_16, emitter.context().types().u64());
    /* execute.simd:3231 [F] s_b_7_19 = (u64)s_b_7_17 (const) */
    /* execute.simd:3231 [D] s_b_7_20 = s_b_7_18<<s_b_7_19 */
    auto s_b_7_20 = emitter.shl(s_b_7_18, emitter.const_u64(((uint64_t)insn.shift_amount)));
    /* execute.simd:3231 [D] s_b_7_21 = (s64)s_b_7_20 */
    auto s_b_7_21 = emitter.reinterpret(s_b_7_20, emitter.context().types().s64());
    /* execute.simd:3231 [F] s_b_7_22 = constant s32 1 (const) */
    /* execute.simd:3231 [D] s_b_7_23 = s_b_7_13[s_b_7_22] <= s_b_7_21 */
    auto s_b_7_23 = emitter.vector_insert(s_b_7_13, emitter.const_s32((int32_t)1ULL), s_b_7_21);
    /* execute.simd:3234 [F] s_b_7_24=sym_27668_3_parameter_inst.rd (const) */
    /* execute.simd:3234 [D] s_b_7_25 = (v2u64)s_b_7_23 */
    auto s_b_7_25 = emitter.reinterpret(s_b_7_23, emitter.context().types().v2u64());
    /* execute.simd:3234 [D] s_b_7_26: WriteRegBank 21:s_b_7_24 = s_b_7_25 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_25,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_25);
    /* execute.simd:0 [F] s_b_7_27: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:3238 [D] s_b_8_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_st2(const aarch64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_131511_1_tmp_s_b_5_2;
  auto DV_sym_131514_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_131437_3_parameter_lane;
  auto DV_sym_131320_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_131429_3_parameter_rt;
  auto DV_sym_131434_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_131337_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30454_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30460_0_lane;
  uint8_t CV_sym_30472_0_rt;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2381 [F] s_b_0_0=sym_30448_3_parameter_inst.rn (const) */
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
    /* execute.simd:2383 [F] s_b_1_0 = sym_30460_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30460_0_lane;
    /* execute.simd:2383 [F] s_b_1_1=sym_30448_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2383 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2383 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2384 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2384 [F] s_b_2_1: sym_30472_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30472_0_rt = (uint8_t)0ULL;
    /* execute.simd:2384 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2384 [F] s_b_4_0 = sym_30472_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30472_0_rt;
    /* execute.simd:2384 [F] s_b_4_1=sym_30448_3_parameter_inst.regcnt (const) */
    /* execute.simd:2384 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2384 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2385 [F] s_b_5_0=sym_30448_3_parameter_inst.arrangement (const) */
    /* execute.simd:2385 [F] s_b_5_1=sym_30448_3_parameter_inst.rt (const) */
    /* execute.simd:2385 [F] s_b_5_2 = sym_30472_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30472_0_rt;
    /* execute.simd:2385 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2385 [F] s_b_5_4 = sym_30460_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30460_0_lane;
    /* execute.simd:2385 [D] s_b_5_5 = sym_30454_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30454_0_address, emitter.context().types().u64());
    /* execute.simd:2385 [F] s_b_5_6: sym_131429_3_parameter_rt = s_b_5_3 (const), dominates: s_b_18_0 s_b_21_0 s_b_22_0 s_b_17_0 s_b_20_0 s_b_16_0 s_b_19_0  */
    CV_sym_131429_3_parameter_rt = s_b_5_3;
    /* execute.simd:2385 [F] s_b_5_7: sym_131437_3_parameter_lane = s_b_5_4 (const), dominates: s_b_18_3 s_b_21_3 s_b_22_3 s_b_17_3 s_b_20_3 s_b_16_3 s_b_19_3  */
    CV_sym_131437_3_parameter_lane = s_b_5_4;
    /* execute.simd:2385 [D] s_b_5_8: sym_131434_3_parameter_addr = s_b_5_5, dominates: s_b_18_2 s_b_21_2 s_b_22_2 s_b_17_2 s_b_20_2 s_b_16_2 s_b_19_2  */
    emitter.store_local(DV_sym_131434_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_131511_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_23_1  */
    CV_sym_131511_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_131514_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_131514_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3774 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3779 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3784 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3789 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3794 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3799 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3804 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3773 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_15 (const) -> b_18, b_21, b_22, b_17, b_20, b_16, b_15, b_19,  */
    switch (insn.arrangement) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_18;
      break;
    default:
      goto fixed_block_b_15;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2383 [F] s_b_6_0 = sym_30460_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30460_0_lane;
    /* execute.simd:2383 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2383 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2383 [F] s_b_6_3: sym_30460_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30460_0_lane = s_b_6_2;
    /* execute.simd:2383 [F] s_b_6_4: Jump b_1 (const) */
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
    /* execute.a64:2733 [F] s_b_8_0=sym_30448_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_131320_0_return_symbol = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_131320_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_12,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_131320_0_return_symbol uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_131320_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2381 [D] s_b_9_1: sym_30454_0_address = s_b_9_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30454_0_address, s_b_9_0);
    /* execute.simd:2383 [F] s_b_9_2 = constant u8 0 (const) */
    /* execute.simd:2383 [F] s_b_9_3: sym_30460_0_lane = s_b_9_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30460_0_lane = (uint8_t)0ULL;
    /* execute.simd:2383 [F] s_b_9_4: Jump b_1 (const) */
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
    /* execute.a64:2702 [D] s_b_10_1: sym_131337_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_131337_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2731 [D] s_b_12_0 = sym_131337_1__R_s_b_3_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_131337_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1: sym_131320_0_return_symbol = s_b_12_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_131320_0_return_symbol, s_b_12_0);
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
    /* execute.a64:2705 [D] s_b_13_1: sym_131337_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_131337_1__R_s_b_3_0, s_b_13_0);
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
    /* execute.a64:2707 [D] s_b_14_1: sym_131337_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_131337_1__R_s_b_3_0, s_b_14_0);
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
    /* execute.simd:3775 [F] s_b_16_0 = sym_131429_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_0 = CV_sym_131429_3_parameter_rt;
    /* execute.simd:3775 [D] s_b_16_1 = ReadRegBank 15:s_b_16_0 (v8u8) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:3776 [D] s_b_16_2 = sym_131434_3_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_131434_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3776 [F] s_b_16_3 = sym_131437_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_3 = CV_sym_131437_3_parameter_lane;
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
    /* execute.simd:3780 [F] s_b_17_0 = sym_131429_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_0 = CV_sym_131429_3_parameter_rt;
    /* execute.simd:3780 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:3781 [D] s_b_17_2 = sym_131434_3_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_131434_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3781 [F] s_b_17_3 = sym_131437_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_3 = CV_sym_131437_3_parameter_lane;
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
    /* execute.simd:3785 [F] s_b_18_0 = sym_131429_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_131429_3_parameter_rt;
    /* execute.simd:3785 [D] s_b_18_1 = ReadRegBank 17:s_b_18_0 (v4u16) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3786 [D] s_b_18_2 = sym_131434_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_131434_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3786 [F] s_b_18_3 = sym_131437_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_131437_3_parameter_lane;
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
    /* execute.simd:3790 [F] s_b_19_0 = sym_131429_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_131429_3_parameter_rt;
    /* execute.simd:3790 [D] s_b_19_1 = ReadRegBank 18:s_b_19_0 (v8u16) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3791 [D] s_b_19_2 = sym_131434_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_131434_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3791 [F] s_b_19_3 = sym_131437_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_131437_3_parameter_lane;
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
    /* execute.simd:3795 [F] s_b_20_0 = sym_131429_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_131429_3_parameter_rt;
    /* execute.simd:3795 [D] s_b_20_1 = ReadRegBank 19:s_b_20_0 (v2u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3796 [D] s_b_20_2 = sym_131434_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_131434_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3796 [F] s_b_20_3 = sym_131437_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_131437_3_parameter_lane;
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
    /* execute.simd:3800 [F] s_b_21_0 = sym_131429_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_131429_3_parameter_rt;
    /* execute.simd:3800 [D] s_b_21_1 = ReadRegBank 20:s_b_21_0 (v4u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3801 [D] s_b_21_2 = sym_131434_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_131434_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3801 [F] s_b_21_3 = sym_131437_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_131437_3_parameter_lane;
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
    /* execute.simd:3805 [F] s_b_22_0 = sym_131429_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_131429_3_parameter_rt;
    /* execute.simd:3805 [D] s_b_22_1 = ReadRegBank 21:s_b_22_0 (v2u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3806 [D] s_b_22_2 = sym_131434_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_131434_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3806 [F] s_b_22_3 = sym_131437_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_131437_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_23_0 = sym_131514_1_tmp_s_b_5_5 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_131514_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1 = sym_131511_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_23_1 = CV_sym_131511_1_tmp_s_b_5_2;
    /* execute.simd:2386 [F] s_b_23_2=sym_30448_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* ???:4294967295 [D] s_b_23_4 = s_b_23_0+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2386 [D] s_b_23_5: sym_30454_0_address = s_b_23_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30454_0_address, s_b_23_4);
    /* execute.simd:2384 [F] s_b_23_6 = constant u8 1 (const) */
    /* execute.simd:2384 [F] s_b_23_7 = s_b_23_1+s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(s_b_23_1 + (uint8_t)1ULL));
    /* execute.simd:2384 [F] s_b_23_8: sym_30472_0_rt = s_b_23_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30472_0_rt = s_b_23_7;
    /* execute.simd:2384 [F] s_b_23_9: Jump b_4 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stlrh(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_133875_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_133858_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:693 [F] s_b_0_0=sym_30908_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_2_0=sym_30908_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_133858_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_133858_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_133858_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_133858_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:694 [F] s_b_3_1=sym_30908_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_3_2 = (u32)s_b_3_1 (const) */
    /* execute.a64:2646 [F] s_b_3_3 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_3_4 = s_b_3_2==s_b_3_3 (const) */
    uint8_t s_b_3_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_3_5 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_3_6 = ReadRegBank 1:s_b_3_1 (u32) */
    auto s_b_3_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_3_6,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_3_7: Select s_b_3_4 ? s_b_3_5 : s_b_3_6 */
    captive::arch::dbt::el::Value *s_b_3_7;
    s_b_3_7 = (s_b_3_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_3_6);
    /* execute.a64:2659 [D] s_b_3_8 = (u64)s_b_3_7 */
    auto s_b_3_8 = emitter.zx(s_b_3_7, emitter.context().types().u64());
    /* execute.a64:1787 [D] s_b_3_9 = (u16)s_b_3_8 */
    auto s_b_3_9 = emitter.truncate(s_b_3_8, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_3_10: Store 2 s_b_3_0 <= s_b_3_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_0, s_b_3_9, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_3_0, s_b_3_9);
    /* ???:4294967295 [F] s_b_3_11: Return */
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
    /* execute.a64:2702 [D] s_b_4_1: sym_133875_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_133875_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2731 [D] s_b_6_0 = sym_133875_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_133875_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_133858_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_133858_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2705 [D] s_b_7_1: sym_133875_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_133875_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2707 [D] s_b_8_1: sym_133875_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_133875_1__R_s_b_3_0, s_b_8_0);
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stpi(const aarch64_decode_a64_LS_REG_PAIR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_137206_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137245_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137109_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137284_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137325_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31356_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31374_0_data1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31383_0_data2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137126_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1568 [F] s_b_0_0=sym_31350_3_parameter_inst.rn (const) */
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
  /* b_11,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1571 [D] s_b_1_0 = sym_31356_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31356_0_address, emitter.context().types().u64());
    /* execute.a64:1571 [F] s_b_1_1=sym_31350_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.a64:1571 [D] s_b_1_3: sym_31356_0_address = s_b_1_2, dominates: s_b_3_0 s_b_7_0 s_b_8_1 s_b_6_0  */
    emitter.store_local(DV_sym_31356_0_address, s_b_1_2);
    /* execute.a64:1571 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_11,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1574 [F] s_b_2_0=sym_31350_3_parameter_inst.opc (const) */
    /* execute.a64:1574 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:1574 [F] s_b_2_2 = constant u32 2 (const) */
    /* execute.a64:1574 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:2656 [F] s_b_2_4: If s_b_2_3: Jump b_17 else b_19 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_26,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1578 [D] s_b_3_0 = sym_31356_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31356_0_address, emitter.context().types().u64());
    /* execute.a64:1578 [D] s_b_3_1 = sym_31374_0_data1 uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_31374_0_data1, emitter.context().types().u64());
    /* execute.a64:1578 [D] s_b_3_2 = (u32)s_b_3_1 */
    auto s_b_3_2 = emitter.truncate(s_b_3_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_3_3: Store 4 s_b_3_0 <= s_b_3_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_3_0, s_b_3_2);
    /* execute.a64:1579 [F] s_b_3_4 = constant u64 4 (const) */
    /* execute.a64:1579 [D] s_b_3_5 = s_b_3_0+s_b_3_4 */
    auto s_b_3_5 = emitter.add(s_b_3_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:1579 [D] s_b_3_6 = sym_31383_0_data2 uint64_t */
    auto s_b_3_6 = emitter.load_local(DV_sym_31383_0_data2, emitter.context().types().u64());
    /* execute.a64:1579 [D] s_b_3_7 = (u32)s_b_3_6 */
    auto s_b_3_7 = emitter.truncate(s_b_3_6, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_3_8: Store 4 s_b_3_5 <= s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_5, s_b_3_7, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_3_5, s_b_3_7);
    /* execute.a64:1578 [F] s_b_3_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_5, b_6,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1585 [F] s_b_4_0=sym_31350_3_parameter_inst.P (const) */
    /* execute.a64:1585 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:1585 [F] s_b_4_2: If s_b_4_1: Jump b_7 else b_8 (const) */
    if (s_b_4_1) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_26,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1580 [F] s_b_5_0=sym_31350_3_parameter_inst.opc (const) */
    /* execute.a64:1580 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1580 [F] s_b_5_2 = constant u32 2 (const) */
    /* execute.a64:1580 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1580 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_4 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:1581 [D] s_b_6_0 = sym_31356_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_31356_0_address, emitter.context().types().u64());
    /* execute.a64:1581 [D] s_b_6_1 = sym_31374_0_data1 uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_31374_0_data1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_2: Store 8 s_b_6_0 <= s_b_6_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_6_0, s_b_6_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_6_0, s_b_6_1);
    /* execute.a64:1582 [F] s_b_6_3 = constant u64 8 (const) */
    /* execute.a64:1582 [D] s_b_6_4 = s_b_6_0+s_b_6_3 */
    auto s_b_6_4 = emitter.add(s_b_6_0, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:1582 [D] s_b_6_5 = sym_31383_0_data2 uint64_t */
    auto s_b_6_5 = emitter.load_local(DV_sym_31383_0_data2, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_6: Store 8 s_b_6_4 <= s_b_6_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_6_4, s_b_6_5, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_6_4, s_b_6_5);
    /* execute.a64:1581 [F] s_b_6_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1586 [D] s_b_7_0 = sym_31356_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_31356_0_address, emitter.context().types().u64());
    /* execute.a64:1586 [F] s_b_7_1=sym_31350_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_7_2 = s_b_7_0+s_b_7_1 */
    auto s_b_7_2 = emitter.add(s_b_7_0, emitter.const_u64(insn.immu64));
    /* execute.a64:1586 [D] s_b_7_3: sym_31356_0_address = s_b_7_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_31356_0_address, s_b_7_2);
    /* execute.a64:1586 [F] s_b_7_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_4, b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1589 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.a64:1589 [D] s_b_8_1 = sym_31356_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_31356_0_address, emitter.context().types().u64());
    /* execute.a64:1589 [D] s_b_8_2: sym_137245_3_parameter_value = s_b_8_1, dominates: s_b_20_0 s_b_22_0 s_b_23_1  */
    emitter.store_local(DV_sym_137245_3_parameter_value, s_b_8_1);
    /* execute.a64:2746 [F] s_b_8_3 = !s_b_8_0 (const) */
    uint8_t s_b_8_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_8_4: If s_b_8_3: Jump b_20 else b_21 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_21;
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
    /* execute.a64:2733 [F] s_b_10_0=sym_31350_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_137109_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_137109_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_137109_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_137109_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1568 [D] s_b_11_1: sym_31356_0_address = s_b_11_0, dominates: s_b_1_0 s_b_3_0 s_b_7_0 s_b_8_1 s_b_6_0  */
    emitter.store_local(DV_sym_31356_0_address, s_b_11_0);
    /* execute.a64:1570 [F] s_b_11_2=sym_31350_3_parameter_inst.P (const) */
    /* execute.a64:1570 [F] s_b_11_3: If s_b_11_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
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
    /* execute.a64:2702 [D] s_b_12_1: sym_137126_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_137126_1__R_s_b_3_0, s_b_12_0);
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
    /* execute.a64:2731 [D] s_b_14_0 = sym_137126_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_137126_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_137109_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_137109_0_return_symbol, s_b_14_0);
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
    /* execute.a64:2705 [D] s_b_15_1: sym_137126_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_137126_1__R_s_b_3_0, s_b_15_0);
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
    /* execute.a64:2707 [D] s_b_16_1: sym_137126_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_137126_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2707 [F] s_b_16_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_2,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2657 [F] s_b_17_0=sym_31350_3_parameter_inst.rt (const) */
    /* execute.a64:2651 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
    /* execute.a64:2651 [F] s_b_17_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_17_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_17_5 = ReadRegBank 0:s_b_17_0 (u64) */
    auto s_b_17_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_17_6: Select s_b_17_3 ? s_b_17_4 : s_b_17_5 */
    captive::arch::dbt::el::Value *s_b_17_6;
    s_b_17_6 = (s_b_17_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_17_5);
    /* ???:4294967295 [D] s_b_17_7: sym_137206_0_return_symbol = s_b_17_6, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_137206_0_return_symbol, s_b_17_6);
    /* ???:4294967295 [F] s_b_17_8: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_17, b_19,  */
  fixed_block_b_18: 
  {
    /* ???:4294967295 [D] s_b_18_0 = sym_137206_0_return_symbol uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_137206_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1574 [D] s_b_18_1: sym_31374_0_data1 = s_b_18_0, dominates: s_b_3_1 s_b_6_1  */
    emitter.store_local(DV_sym_31374_0_data1, s_b_18_0);
    /* execute.a64:1575 [F] s_b_18_2=sym_31350_3_parameter_inst.opc (const) */
    /* execute.a64:1575 [F] s_b_18_3 = (u32)s_b_18_2 (const) */
    /* execute.a64:1575 [F] s_b_18_4 = constant u32 2 (const) */
    /* execute.a64:1575 [F] s_b_18_5 = s_b_18_3==s_b_18_4 (const) */
    uint8_t s_b_18_5 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:2656 [F] s_b_18_6: If s_b_18_5: Jump b_25 else b_27 (const) */
    if (s_b_18_5) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_2,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2659 [F] s_b_19_0=sym_31350_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2646 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_19_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_19_5 = ReadRegBank 1:s_b_19_0 (u32) */
    auto s_b_19_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_19_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_19_6: Select s_b_19_3 ? s_b_19_4 : s_b_19_5 */
    captive::arch::dbt::el::Value *s_b_19_6;
    s_b_19_6 = (s_b_19_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_19_5);
    /* execute.a64:2659 [D] s_b_19_7 = (u64)s_b_19_6 */
    auto s_b_19_7 = emitter.zx(s_b_19_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_19_8: sym_137206_0_return_symbol = s_b_19_7, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_137206_0_return_symbol, s_b_19_7);
    /* ???:4294967295 [F] s_b_19_9: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_8,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2747 [D] s_b_20_0 = sym_137245_3_parameter_value uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_137245_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_20_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_20_2 = s_b_20_0&s_b_20_1 */
    auto s_b_20_2 = emitter.bitwise_and(s_b_20_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_20_3: sym_137245_3_parameter_value = s_b_20_2, dominates: s_b_22_0 s_b_23_1  */
    emitter.store_local(DV_sym_137245_3_parameter_value, s_b_20_2);
    /* execute.a64:2747 [F] s_b_20_4: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_8, b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2750 [F] s_b_21_0=sym_31350_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:2750 [F] s_b_21_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2750 [F] s_b_21_4: If s_b_21_3: Jump b_22 else b_23 (const) */
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
    /* execute.a64:2751 [D] s_b_22_0 = sym_137245_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_137245_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_22_1: sym_137325_3_parameter_value = s_b_22_0, dominates: s_b_28_0 s_b_29_0 s_b_30_0  */
    emitter.store_local(DV_sym_137325_3_parameter_value, s_b_22_0);
    /* execute.a64:2714 [F] s_b_22_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_22_3 = __builtin_get_feature */
    uint32_t s_b_22_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_22_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_22_5 = s_b_22_3==s_b_22_4 (const) */
    uint8_t s_b_22_5 = ((uint8_t)(s_b_22_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_22_6: If s_b_22_5: Jump b_28 else b_31 (const) */
    if (s_b_22_5) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_21,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2753 [F] s_b_23_0=sym_31350_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_23_1 = sym_137245_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_137245_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_23_2: WriteRegBank 0:s_b_23_0 = s_b_23_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_23_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_23_1);
    /* execute.a64:2753 [F] s_b_23_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23, b_28, b_29, b_30,  */
  fixed_block_b_24: 
  {
    /* ???:4294967295 [F] s_b_24_0: Return */
    goto fixed_done;
  }
  /* b_18,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2657 [F] s_b_25_0=sym_31350_3_parameter_inst.rt2 (const) */
    /* execute.a64:2651 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:2651 [F] s_b_25_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_25_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_25_5 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_25_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_25_6: Select s_b_25_3 ? s_b_25_4 : s_b_25_5 */
    captive::arch::dbt::el::Value *s_b_25_6;
    s_b_25_6 = (s_b_25_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_25_5);
    /* ???:4294967295 [D] s_b_25_7: sym_137284_0_return_symbol = s_b_25_6, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_137284_0_return_symbol, s_b_25_6);
    /* ???:4294967295 [F] s_b_25_8: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_25, b_27,  */
  fixed_block_b_26: 
  {
    /* ???:4294967295 [D] s_b_26_0 = sym_137284_0_return_symbol uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_137284_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1575 [D] s_b_26_1: sym_31383_0_data2 = s_b_26_0, dominates: s_b_3_6 s_b_6_5  */
    emitter.store_local(DV_sym_31383_0_data2, s_b_26_0);
    /* execute.a64:1577 [F] s_b_26_2=sym_31350_3_parameter_inst.opc (const) */
    /* execute.a64:1577 [F] s_b_26_3 = (u32)s_b_26_2 (const) */
    /* execute.a64:1577 [F] s_b_26_4 = constant u32 0 (const) */
    /* execute.a64:1577 [F] s_b_26_5 = s_b_26_3==s_b_26_4 (const) */
    uint8_t s_b_26_5 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:1577 [F] s_b_26_6: If s_b_26_5: Jump b_3 else b_5 (const) */
    if (s_b_26_5) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_18,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2659 [F] s_b_27_0=sym_31350_3_parameter_inst.rt2 (const) */
    /* execute.a64:2646 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
    /* execute.a64:2646 [F] s_b_27_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_27_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_27_5 = ReadRegBank 1:s_b_27_0 (u32) */
    auto s_b_27_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_27_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_27_6: Select s_b_27_3 ? s_b_27_4 : s_b_27_5 */
    captive::arch::dbt::el::Value *s_b_27_6;
    s_b_27_6 = (s_b_27_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_27_5);
    /* execute.a64:2659 [D] s_b_27_7 = (u64)s_b_27_6 */
    auto s_b_27_7 = emitter.zx(s_b_27_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_27_8: sym_137284_0_return_symbol = s_b_27_7, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_137284_0_return_symbol, s_b_27_7);
    /* ???:4294967295 [F] s_b_27_9: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_22,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2715 [D] s_b_28_0 = sym_137325_3_parameter_value uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_137325_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_28_1: WriteReg 20 = s_b_28_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_28_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_28_0);
    /* execute.a64:2715 [F] s_b_28_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_31,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2718 [D] s_b_29_0 = sym_137325_3_parameter_value uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_137325_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_29_1: WriteReg 20 = s_b_29_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_29_0);
    /* execute.a64:2718 [F] s_b_29_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_31,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2720 [D] s_b_30_0 = sym_137325_3_parameter_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_137325_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_30_1: WriteReg 21 = s_b_30_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_30_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_30_0);
    /* execute.a64:2720 [F] s_b_30_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_22,  */
  fixed_block_b_31: 
  {
    /* execute.a64:3012 [F] s_b_31_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_31_1 = __builtin_get_feature */
    uint32_t s_b_31_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_31_2 = (u8)s_b_31_1 (const) */
    /* execute.a64:2717 [F] s_b_31_3 = (u32)s_b_31_2 (const) */
    /* execute.a64:2717 [F] s_b_31_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_31_5 = s_b_31_3==s_b_31_4 (const) */
    uint8_t s_b_31_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_31_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_31_6: If s_b_31_5: Jump b_29 else b_30 (const) */
    if (s_b_31_5) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_30;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_strh(const aarch64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_141609_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141434_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32260_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141570_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141451_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1015 [F] s_b_0_0=sym_32254_3_parameter_inst.rn (const) */
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
    /* execute.a64:1018 [D] s_b_1_0 = sym_32260_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_32260_0_address, emitter.context().types().u64());
    /* execute.a64:1018 [F] s_b_1_1=sym_32254_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1018 [D] s_b_1_4: sym_32260_0_address = s_b_1_3, dominates: s_b_2_9 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_32260_0_address, s_b_1_3);
    /* execute.a64:1018 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1021 [F] s_b_2_0=sym_32254_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2646 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_2_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_2_5 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_2_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_2_6: Select s_b_2_3 ? s_b_2_4 : s_b_2_5 */
    captive::arch::dbt::el::Value *s_b_2_6;
    s_b_2_6 = (s_b_2_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_2_5);
    /* execute.a64:2659 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:1021 [D] s_b_2_8 = (u16)s_b_2_7 */
    auto s_b_2_8 = emitter.truncate(s_b_2_7, emitter.context().types().u16());
    /* execute.a64:1022 [D] s_b_2_9 = sym_32260_0_address uint64_t */
    auto s_b_2_9 = emitter.load_local(DV_sym_32260_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_10: Store 2 s_b_2_9 <= s_b_2_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_2_9, s_b_2_8, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_2_9, s_b_2_8);
    /* execute.a64:1024 [F] s_b_2_11=sym_32254_3_parameter_inst.P (const) */
    /* execute.a64:1024 [F] s_b_2_12 = !s_b_2_11 (const) */
    uint8_t s_b_2_12 = !insn.P;
    /* execute.a64:1024 [F] s_b_2_13: If s_b_2_12: Jump b_3 else b_4 (const) */
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
    /* execute.a64:1025 [D] s_b_3_0 = sym_32260_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_32260_0_address, emitter.context().types().u64());
    /* execute.a64:1025 [F] s_b_3_1=sym_32254_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1025 [D] s_b_3_4: sym_32260_0_address = s_b_3_3, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_32260_0_address, s_b_3_3);
    /* execute.a64:1025 [F] s_b_3_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_2, b_3,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1028 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.a64:1028 [D] s_b_4_1 = sym_32260_0_address uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_32260_0_address, emitter.context().types().u64());
    /* execute.a64:1028 [D] s_b_4_2: sym_141570_3_parameter_value = s_b_4_1, dominates: s_b_13_0 s_b_15_0 s_b_16_1  */
    emitter.store_local(DV_sym_141570_3_parameter_value, s_b_4_1);
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
    /* execute.a64:2733 [F] s_b_6_0=sym_32254_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_6_1 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_6_2: sym_141434_0_return_symbol = s_b_6_1, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_141434_0_return_symbol, s_b_6_1);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_10,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [D] s_b_7_0 = sym_141434_0_return_symbol uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_141434_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1015 [D] s_b_7_1: sym_32260_0_address = s_b_7_0, dominates: s_b_1_0 s_b_2_9 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_32260_0_address, s_b_7_0);
    /* execute.a64:1017 [F] s_b_7_2=sym_32254_3_parameter_inst.P (const) */
    /* execute.a64:1017 [F] s_b_7_3: If s_b_7_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2702 [D] s_b_8_1: sym_141451_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_141451_1__R_s_b_3_0, s_b_8_0);
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
    /* execute.a64:2731 [D] s_b_10_0 = sym_141451_1__R_s_b_3_0 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_141451_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1: sym_141434_0_return_symbol = s_b_10_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_141434_0_return_symbol, s_b_10_0);
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
    /* execute.a64:2705 [D] s_b_11_1: sym_141451_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_141451_1__R_s_b_3_0, s_b_11_0);
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
    /* execute.a64:2707 [D] s_b_12_1: sym_141451_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_141451_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2707 [F] s_b_12_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_4,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2747 [D] s_b_13_0 = sym_141570_3_parameter_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_141570_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_13_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_13_2 = s_b_13_0&s_b_13_1 */
    auto s_b_13_2 = emitter.bitwise_and(s_b_13_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_13_3: sym_141570_3_parameter_value = s_b_13_2, dominates: s_b_15_0 s_b_16_1  */
    emitter.store_local(DV_sym_141570_3_parameter_value, s_b_13_2);
    /* execute.a64:2747 [F] s_b_13_4: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_4, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2750 [F] s_b_14_0=sym_32254_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_15_0 = sym_141570_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_141570_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_15_1: sym_141609_3_parameter_value = s_b_15_0, dominates: s_b_18_0 s_b_19_0 s_b_20_0  */
    emitter.store_local(DV_sym_141609_3_parameter_value, s_b_15_0);
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
    /* execute.a64:2753 [F] s_b_16_0=sym_32254_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_16_1 = sym_141570_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_141570_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_16_1,emitter.const_u8(8));
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
    /* execute.a64:2715 [D] s_b_18_0 = sym_141609_3_parameter_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_141609_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_18_1: WriteReg 20 = s_b_18_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_18_0);
    /* execute.a64:2715 [F] s_b_18_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_21,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2718 [D] s_b_19_0 = sym_141609_3_parameter_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_141609_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_19_1: WriteReg 20 = s_b_19_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_19_0);
    /* execute.a64:2718 [F] s_b_19_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_21,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2720 [D] s_b_20_0 = sym_141609_3_parameter_value uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_141609_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_20_1: WriteReg 21 = s_b_20_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sturb(const aarch64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_142945_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_142962_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1294 [F] s_b_0_0=sym_32563_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_2_0=sym_32563_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_142945_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_142945_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_142945_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_142945_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1295 [F] s_b_3_1=sym_32563_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1297 [F] s_b_3_4=sym_32563_3_parameter_inst.rt (const) */
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
    /* execute.a64:1297 [D] s_b_3_12 = (u8)s_b_3_11 */
    auto s_b_3_12 = emitter.truncate(s_b_3_11, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_3_13: Store 1 s_b_3_3 <= s_b_3_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_3, s_b_3_12, emitter.const_u8(1));
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
    /* execute.a64:2702 [D] s_b_4_1: sym_142962_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_142962_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2731 [D] s_b_6_0 = sym_142962_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_142962_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_142945_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_142945_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2705 [D] s_b_7_1: sym_142962_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_142962_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2707 [D] s_b_8_1: sym_142962_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_142962_1__R_s_b_3_0, s_b_8_0);
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sub_vector(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:844 [F] s_b_0_0=sym_32979_3_parameter_inst.SCALAR (const) */
    /* execute.simd:844 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:844 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.simd:844 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:844 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:845 [F] s_b_1_0=sym_32979_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:846 [F] s_b_1_2=sym_32979_3_parameter_inst.rm (const) */
    /* execute.simd:6167 [D] s_b_1_3 = ReadRegBank 7:s_b_1_2 (u64) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(8));
    }
    /* execute.simd:848 [F] s_b_1_4=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:848 [D] s_b_1_5 = s_b_1_1-s_b_1_3 */
    auto s_b_1_5 = emitter.sub(s_b_1_1, s_b_1_3);
    /* execute.simd:6138 [D] s_b_1_6: WriteRegBank 2:s_b_1_4 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6139 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_1_8: WriteRegBank 3:s_b_1_4 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_1_9: Jump b_2 (const) */
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
    /* execute.simd:850 [F] s_b_3_0=sym_32979_3_parameter_inst.arrangement (const) */
    /* execute.simd:851 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:861 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:869 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:879 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:888 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:898 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:906 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:850 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_11 (const) -> b_4, b_5, b_6, b_7, b_8, b_9, b_10, b_11,  */
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
      goto fixed_block_b_11;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:852 [F] s_b_4_0=sym_32979_3_parameter_inst.rn (const) */
    /* execute.simd:852 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:853 [F] s_b_4_2=sym_32979_3_parameter_inst.rm (const) */
    /* execute.simd:853 [D] s_b_4_3 = ReadRegBank 15:s_b_4_2 (v8u8) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* execute.simd:855 [D] s_b_4_4 = s_b_4_1-s_b_4_3 */
    auto s_b_4_4 = emitter.sub(s_b_4_1, s_b_4_3);
    /* execute.simd:856 [F] s_b_4_5=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:856 [D] s_b_4_6: WriteRegBank 15:s_b_4_5 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:857 [F] s_b_4_7=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:857 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:857 [F] s_b_4_9: WriteRegBank 3:s_b_4_7 = s_b_4_8 */
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
    /* execute.simd:862 [F] s_b_5_0=sym_32979_3_parameter_inst.rn (const) */
    /* execute.simd:862 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:863 [F] s_b_5_2=sym_32979_3_parameter_inst.rm (const) */
    /* execute.simd:863 [D] s_b_5_3 = ReadRegBank 16:s_b_5_2 (v16u8) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:865 [D] s_b_5_4 = s_b_5_1-s_b_5_3 */
    auto s_b_5_4 = emitter.sub(s_b_5_1, s_b_5_3);
    /* execute.simd:866 [F] s_b_5_5=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:866 [D] s_b_5_6: WriteRegBank 16:s_b_5_5 = s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4);
    /* execute.simd:0 [F] s_b_5_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:870 [F] s_b_6_0=sym_32979_3_parameter_inst.rn (const) */
    /* execute.simd:870 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:871 [F] s_b_6_2=sym_32979_3_parameter_inst.rm (const) */
    /* execute.simd:871 [D] s_b_6_3 = ReadRegBank 17:s_b_6_2 (v4u16) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:873 [D] s_b_6_4 = s_b_6_1-s_b_6_3 */
    auto s_b_6_4 = emitter.sub(s_b_6_1, s_b_6_3);
    /* execute.simd:874 [F] s_b_6_5=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:874 [D] s_b_6_6: WriteRegBank 17:s_b_6_5 = s_b_6_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
    /* execute.simd:875 [F] s_b_6_7=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:875 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:875 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
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
    /* execute.simd:880 [F] s_b_7_0=sym_32979_3_parameter_inst.rn (const) */
    /* execute.simd:880 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:881 [F] s_b_7_2=sym_32979_3_parameter_inst.rm (const) */
    /* execute.simd:881 [D] s_b_7_3 = ReadRegBank 18:s_b_7_2 (v8u16) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:883 [D] s_b_7_4 = s_b_7_1-s_b_7_3 */
    auto s_b_7_4 = emitter.sub(s_b_7_1, s_b_7_3);
    /* execute.simd:884 [F] s_b_7_5=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:884 [D] s_b_7_6: WriteRegBank 18:s_b_7_5 = s_b_7_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4);
    /* execute.simd:0 [F] s_b_7_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:889 [F] s_b_8_0=sym_32979_3_parameter_inst.rn (const) */
    /* execute.simd:889 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:890 [F] s_b_8_2=sym_32979_3_parameter_inst.rm (const) */
    /* execute.simd:890 [D] s_b_8_3 = ReadRegBank 19:s_b_8_2 (v2u32) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(8));
    }
    /* execute.simd:892 [D] s_b_8_4 = s_b_8_1-s_b_8_3 */
    auto s_b_8_4 = emitter.sub(s_b_8_1, s_b_8_3);
    /* execute.simd:893 [F] s_b_8_5=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:893 [D] s_b_8_6: WriteRegBank 19:s_b_8_5 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4);
    /* execute.simd:894 [F] s_b_8_7=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:894 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:894 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
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
    /* execute.simd:899 [F] s_b_9_0=sym_32979_3_parameter_inst.rn (const) */
    /* execute.simd:899 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:900 [F] s_b_9_2=sym_32979_3_parameter_inst.rm (const) */
    /* execute.simd:900 [D] s_b_9_3 = ReadRegBank 20:s_b_9_2 (v4u32) */
    auto s_b_9_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_9_3,emitter.const_u8(16));
    }
    /* execute.simd:902 [D] s_b_9_4 = s_b_9_1-s_b_9_3 */
    auto s_b_9_4 = emitter.sub(s_b_9_1, s_b_9_3);
    /* execute.simd:903 [F] s_b_9_5=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:903 [D] s_b_9_6: WriteRegBank 20:s_b_9_5 = s_b_9_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_4);
    /* execute.simd:0 [F] s_b_9_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:907 [F] s_b_10_0=sym_32979_3_parameter_inst.rn (const) */
    /* execute.simd:907 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:908 [F] s_b_10_2=sym_32979_3_parameter_inst.rm (const) */
    /* execute.simd:908 [D] s_b_10_3 = ReadRegBank 21:s_b_10_2 (v2u64) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_3,emitter.const_u8(16));
    }
    /* execute.simd:910 [D] s_b_10_4 = s_b_10_1-s_b_10_3 */
    auto s_b_10_4 = emitter.sub(s_b_10_1, s_b_10_3);
    /* execute.simd:911 [F] s_b_10_5=sym_32979_3_parameter_inst.rd (const) */
    /* execute.simd:911 [D] s_b_10_6: WriteRegBank 21:s_b_10_5 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4);
    /* execute.simd:0 [F] s_b_10_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:916 [D] s_b_11_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_uaddlp(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3322 [F] s_b_0_0=sym_37638_3_parameter_inst.arrangement (const) */
    /* execute.simd:3323 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:3335 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:3346 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:3358 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:3369 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:3378 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:3322 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:3324 [F] s_b_2_0=sym_37638_3_parameter_inst.rn (const) */
    /* execute.simd:3324 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_2 = constant v4u16 
    {
    }
    (const) */
    /* execute.simd:3328 [F] s_b_2_3 = constant u32 0 (const) */
    /* execute.simd:3328 [D] s_b_2_1[s_b_2_3] */
    auto s_b_2_4 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3328 [D] s_b_2_5 = (u16)s_b_2_4 */
    auto s_b_2_5 = emitter.zx(s_b_2_4, emitter.context().types().u16());
    /* execute.simd:3328 [F] s_b_2_6 = constant u32 1 (const) */
    /* execute.simd:3328 [D] s_b_2_1[s_b_2_6] */
    auto s_b_2_7 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3328 [D] s_b_2_8 = (u16)s_b_2_7 */
    auto s_b_2_8 = emitter.zx(s_b_2_7, emitter.context().types().u16());
    /* execute.simd:3328 [D] s_b_2_9 = s_b_2_5+s_b_2_8 */
    auto s_b_2_9 = emitter.add(s_b_2_5, s_b_2_8);
    /* execute.simd:3328 [F] s_b_2_10 = constant s32 0 (const) */
    /* execute.simd:3328 [D] s_b_2_11 = s_b_2_2[s_b_2_10] <= s_b_2_9 */
    auto s_b_2_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 4>(0)[0], emitter.context().types().v4u16()), emitter.const_s32((int32_t)0ULL), s_b_2_9);
    /* execute.simd:3328 [F] s_b_2_12 = constant u32 2 (const) */
    /* execute.simd:3328 [D] s_b_2_1[s_b_2_12] */
    auto s_b_2_13 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3328 [D] s_b_2_14 = (u16)s_b_2_13 */
    auto s_b_2_14 = emitter.zx(s_b_2_13, emitter.context().types().u16());
    /* execute.simd:3328 [F] s_b_2_15 = constant u32 3 (const) */
    /* execute.simd:3328 [D] s_b_2_1[s_b_2_15] */
    auto s_b_2_16 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3328 [D] s_b_2_17 = (u16)s_b_2_16 */
    auto s_b_2_17 = emitter.zx(s_b_2_16, emitter.context().types().u16());
    /* execute.simd:3328 [D] s_b_2_18 = s_b_2_14+s_b_2_17 */
    auto s_b_2_18 = emitter.add(s_b_2_14, s_b_2_17);
    /* execute.simd:3328 [F] s_b_2_19 = constant s32 1 (const) */
    /* execute.simd:3328 [D] s_b_2_20 = s_b_2_11[s_b_2_19] <= s_b_2_18 */
    auto s_b_2_20 = emitter.vector_insert(s_b_2_11, emitter.const_s32((int32_t)1ULL), s_b_2_18);
    /* execute.simd:3328 [F] s_b_2_21 = constant u32 4 (const) */
    /* execute.simd:3328 [D] s_b_2_1[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3328 [D] s_b_2_23 = (u16)s_b_2_22 */
    auto s_b_2_23 = emitter.zx(s_b_2_22, emitter.context().types().u16());
    /* execute.simd:3328 [F] s_b_2_24 = constant u32 5 (const) */
    /* execute.simd:3328 [D] s_b_2_1[s_b_2_24] */
    auto s_b_2_25 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3328 [D] s_b_2_26 = (u16)s_b_2_25 */
    auto s_b_2_26 = emitter.zx(s_b_2_25, emitter.context().types().u16());
    /* execute.simd:3328 [D] s_b_2_27 = s_b_2_23+s_b_2_26 */
    auto s_b_2_27 = emitter.add(s_b_2_23, s_b_2_26);
    /* execute.simd:3328 [F] s_b_2_28 = constant s32 2 (const) */
    /* execute.simd:3328 [D] s_b_2_29 = s_b_2_20[s_b_2_28] <= s_b_2_27 */
    auto s_b_2_29 = emitter.vector_insert(s_b_2_20, emitter.const_s32((int32_t)2ULL), s_b_2_27);
    /* execute.simd:3328 [F] s_b_2_30 = constant u32 6 (const) */
    /* execute.simd:3328 [D] s_b_2_1[s_b_2_30] */
    auto s_b_2_31 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3328 [D] s_b_2_32 = (u16)s_b_2_31 */
    auto s_b_2_32 = emitter.zx(s_b_2_31, emitter.context().types().u16());
    /* execute.simd:3328 [F] s_b_2_33 = constant u32 7 (const) */
    /* execute.simd:3328 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3328 [D] s_b_2_35 = (u16)s_b_2_34 */
    auto s_b_2_35 = emitter.zx(s_b_2_34, emitter.context().types().u16());
    /* execute.simd:3328 [D] s_b_2_36 = s_b_2_32+s_b_2_35 */
    auto s_b_2_36 = emitter.add(s_b_2_32, s_b_2_35);
    /* execute.simd:3328 [F] s_b_2_37 = constant s32 3 (const) */
    /* execute.simd:3328 [D] s_b_2_38 = s_b_2_29[s_b_2_37] <= s_b_2_36 */
    auto s_b_2_38 = emitter.vector_insert(s_b_2_29, emitter.const_s32((int32_t)3ULL), s_b_2_36);
    /* execute.simd:3331 [F] s_b_2_39=sym_37638_3_parameter_inst.rd (const) */
    /* execute.simd:3331 [D] s_b_2_40: WriteRegBank 17:s_b_2_39 = s_b_2_38 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_38,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_38);
    /* execute.simd:3332 [F] s_b_2_41=sym_37638_3_parameter_inst.rd (const) */
    /* execute.simd:3332 [F] s_b_2_42 = constant u64 0 (const) */
    /* execute.simd:3332 [F] s_b_2_43: WriteRegBank 3:s_b_2_41 = s_b_2_42 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_2_44: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:3336 [F] s_b_3_0=sym_37638_3_parameter_inst.rn (const) */
    /* execute.simd:3336 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_2 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:3340 [F] s_b_3_3 = constant u32 0 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_3] */
    auto s_b_3_4 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3340 [D] s_b_3_5 = (u16)s_b_3_4 */
    auto s_b_3_5 = emitter.zx(s_b_3_4, emitter.context().types().u16());
    /* execute.simd:3340 [F] s_b_3_6 = constant u32 1 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_6] */
    auto s_b_3_7 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3340 [D] s_b_3_8 = (u16)s_b_3_7 */
    auto s_b_3_8 = emitter.zx(s_b_3_7, emitter.context().types().u16());
    /* execute.simd:3340 [D] s_b_3_9 = s_b_3_5+s_b_3_8 */
    auto s_b_3_9 = emitter.add(s_b_3_5, s_b_3_8);
    /* execute.simd:3340 [F] s_b_3_10 = constant s32 0 (const) */
    /* execute.simd:3340 [D] s_b_3_11 = s_b_3_2[s_b_3_10] <= s_b_3_9 */
    auto s_b_3_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_9);
    /* execute.simd:3340 [F] s_b_3_12 = constant u32 2 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_12] */
    auto s_b_3_13 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3340 [D] s_b_3_14 = (u16)s_b_3_13 */
    auto s_b_3_14 = emitter.zx(s_b_3_13, emitter.context().types().u16());
    /* execute.simd:3340 [F] s_b_3_15 = constant u32 3 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_15] */
    auto s_b_3_16 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3340 [D] s_b_3_17 = (u16)s_b_3_16 */
    auto s_b_3_17 = emitter.zx(s_b_3_16, emitter.context().types().u16());
    /* execute.simd:3340 [D] s_b_3_18 = s_b_3_14+s_b_3_17 */
    auto s_b_3_18 = emitter.add(s_b_3_14, s_b_3_17);
    /* execute.simd:3340 [F] s_b_3_19 = constant s32 1 (const) */
    /* execute.simd:3340 [D] s_b_3_20 = s_b_3_11[s_b_3_19] <= s_b_3_18 */
    auto s_b_3_20 = emitter.vector_insert(s_b_3_11, emitter.const_s32((int32_t)1ULL), s_b_3_18);
    /* execute.simd:3340 [F] s_b_3_21 = constant u32 4 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3340 [D] s_b_3_23 = (u16)s_b_3_22 */
    auto s_b_3_23 = emitter.zx(s_b_3_22, emitter.context().types().u16());
    /* execute.simd:3340 [F] s_b_3_24 = constant u32 5 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_24] */
    auto s_b_3_25 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3340 [D] s_b_3_26 = (u16)s_b_3_25 */
    auto s_b_3_26 = emitter.zx(s_b_3_25, emitter.context().types().u16());
    /* execute.simd:3340 [D] s_b_3_27 = s_b_3_23+s_b_3_26 */
    auto s_b_3_27 = emitter.add(s_b_3_23, s_b_3_26);
    /* execute.simd:3340 [F] s_b_3_28 = constant s32 2 (const) */
    /* execute.simd:3340 [D] s_b_3_29 = s_b_3_20[s_b_3_28] <= s_b_3_27 */
    auto s_b_3_29 = emitter.vector_insert(s_b_3_20, emitter.const_s32((int32_t)2ULL), s_b_3_27);
    /* execute.simd:3340 [F] s_b_3_30 = constant u32 6 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_30] */
    auto s_b_3_31 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3340 [D] s_b_3_32 = (u16)s_b_3_31 */
    auto s_b_3_32 = emitter.zx(s_b_3_31, emitter.context().types().u16());
    /* execute.simd:3340 [F] s_b_3_33 = constant u32 7 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3340 [D] s_b_3_35 = (u16)s_b_3_34 */
    auto s_b_3_35 = emitter.zx(s_b_3_34, emitter.context().types().u16());
    /* execute.simd:3340 [D] s_b_3_36 = s_b_3_32+s_b_3_35 */
    auto s_b_3_36 = emitter.add(s_b_3_32, s_b_3_35);
    /* execute.simd:3340 [F] s_b_3_37 = constant s32 3 (const) */
    /* execute.simd:3340 [D] s_b_3_38 = s_b_3_29[s_b_3_37] <= s_b_3_36 */
    auto s_b_3_38 = emitter.vector_insert(s_b_3_29, emitter.const_s32((int32_t)3ULL), s_b_3_36);
    /* execute.simd:3340 [F] s_b_3_39 = constant u32 8 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_39] */
    auto s_b_3_40 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:3340 [D] s_b_3_41 = (u16)s_b_3_40 */
    auto s_b_3_41 = emitter.zx(s_b_3_40, emitter.context().types().u16());
    /* execute.simd:3340 [F] s_b_3_42 = constant u32 9 (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_42] */
    auto s_b_3_43 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:3340 [D] s_b_3_44 = (u16)s_b_3_43 */
    auto s_b_3_44 = emitter.zx(s_b_3_43, emitter.context().types().u16());
    /* execute.simd:3340 [D] s_b_3_45 = s_b_3_41+s_b_3_44 */
    auto s_b_3_45 = emitter.add(s_b_3_41, s_b_3_44);
    /* execute.simd:3340 [F] s_b_3_46 = constant s32 4 (const) */
    /* execute.simd:3340 [D] s_b_3_47 = s_b_3_38[s_b_3_46] <= s_b_3_45 */
    auto s_b_3_47 = emitter.vector_insert(s_b_3_38, emitter.const_s32((int32_t)4ULL), s_b_3_45);
    /* execute.simd:3340 [F] s_b_3_48 = constant u32 a (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_48] */
    auto s_b_3_49 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:3340 [D] s_b_3_50 = (u16)s_b_3_49 */
    auto s_b_3_50 = emitter.zx(s_b_3_49, emitter.context().types().u16());
    /* execute.simd:3340 [F] s_b_3_51 = constant u32 b (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_51] */
    auto s_b_3_52 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:3340 [D] s_b_3_53 = (u16)s_b_3_52 */
    auto s_b_3_53 = emitter.zx(s_b_3_52, emitter.context().types().u16());
    /* execute.simd:3340 [D] s_b_3_54 = s_b_3_50+s_b_3_53 */
    auto s_b_3_54 = emitter.add(s_b_3_50, s_b_3_53);
    /* execute.simd:3340 [F] s_b_3_55 = constant s32 5 (const) */
    /* execute.simd:3340 [D] s_b_3_56 = s_b_3_47[s_b_3_55] <= s_b_3_54 */
    auto s_b_3_56 = emitter.vector_insert(s_b_3_47, emitter.const_s32((int32_t)5ULL), s_b_3_54);
    /* execute.simd:3340 [F] s_b_3_57 = constant u32 c (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:3340 [D] s_b_3_59 = (u16)s_b_3_58 */
    auto s_b_3_59 = emitter.zx(s_b_3_58, emitter.context().types().u16());
    /* execute.simd:3340 [F] s_b_3_60 = constant u32 d (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_60] */
    auto s_b_3_61 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:3340 [D] s_b_3_62 = (u16)s_b_3_61 */
    auto s_b_3_62 = emitter.zx(s_b_3_61, emitter.context().types().u16());
    /* execute.simd:3340 [D] s_b_3_63 = s_b_3_59+s_b_3_62 */
    auto s_b_3_63 = emitter.add(s_b_3_59, s_b_3_62);
    /* execute.simd:3340 [F] s_b_3_64 = constant s32 6 (const) */
    /* execute.simd:3340 [D] s_b_3_65 = s_b_3_56[s_b_3_64] <= s_b_3_63 */
    auto s_b_3_65 = emitter.vector_insert(s_b_3_56, emitter.const_s32((int32_t)6ULL), s_b_3_63);
    /* execute.simd:3340 [F] s_b_3_66 = constant u32 e (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_66] */
    auto s_b_3_67 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:3340 [D] s_b_3_68 = (u16)s_b_3_67 */
    auto s_b_3_68 = emitter.zx(s_b_3_67, emitter.context().types().u16());
    /* execute.simd:3340 [F] s_b_3_69 = constant u32 f (const) */
    /* execute.simd:3340 [D] s_b_3_1[s_b_3_69] */
    auto s_b_3_70 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:3340 [D] s_b_3_71 = (u16)s_b_3_70 */
    auto s_b_3_71 = emitter.zx(s_b_3_70, emitter.context().types().u16());
    /* execute.simd:3340 [D] s_b_3_72 = s_b_3_68+s_b_3_71 */
    auto s_b_3_72 = emitter.add(s_b_3_68, s_b_3_71);
    /* execute.simd:3340 [F] s_b_3_73 = constant s32 7 (const) */
    /* execute.simd:3340 [D] s_b_3_74 = s_b_3_65[s_b_3_73] <= s_b_3_72 */
    auto s_b_3_74 = emitter.vector_insert(s_b_3_65, emitter.const_s32((int32_t)7ULL), s_b_3_72);
    /* execute.simd:3343 [F] s_b_3_75=sym_37638_3_parameter_inst.rd (const) */
    /* execute.simd:3343 [D] s_b_3_76: WriteRegBank 18:s_b_3_75 = s_b_3_74 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_74,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_74);
    /* execute.simd:0 [F] s_b_3_77: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:3347 [F] s_b_4_0=sym_37638_3_parameter_inst.rn (const) */
    /* execute.simd:3347 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_2 = constant v2u32 
    {
    }
    (const) */
    /* execute.simd:3351 [F] s_b_4_3 = constant u32 0 (const) */
    /* execute.simd:3351 [D] s_b_4_1[s_b_4_3] */
    auto s_b_4_4 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3351 [D] s_b_4_5 = (u32)s_b_4_4 */
    auto s_b_4_5 = emitter.zx(s_b_4_4, emitter.context().types().u32());
    /* execute.simd:3351 [F] s_b_4_6 = constant u32 1 (const) */
    /* execute.simd:3351 [D] s_b_4_1[s_b_4_6] */
    auto s_b_4_7 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3351 [D] s_b_4_8 = (u32)s_b_4_7 */
    auto s_b_4_8 = emitter.zx(s_b_4_7, emitter.context().types().u32());
    /* execute.simd:3351 [D] s_b_4_9 = s_b_4_5+s_b_4_8 */
    auto s_b_4_9 = emitter.add(s_b_4_5, s_b_4_8);
    /* execute.simd:3351 [F] s_b_4_10 = constant s32 0 (const) */
    /* execute.simd:3351 [D] s_b_4_11 = s_b_4_2[s_b_4_10] <= s_b_4_9 */
    auto s_b_4_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 2>(0)[0], emitter.context().types().v2u32()), emitter.const_s32((int32_t)0ULL), s_b_4_9);
    /* execute.simd:3351 [F] s_b_4_12 = constant u32 2 (const) */
    /* execute.simd:3351 [D] s_b_4_1[s_b_4_12] */
    auto s_b_4_13 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3351 [D] s_b_4_14 = (u32)s_b_4_13 */
    auto s_b_4_14 = emitter.zx(s_b_4_13, emitter.context().types().u32());
    /* execute.simd:3351 [F] s_b_4_15 = constant u32 3 (const) */
    /* execute.simd:3351 [D] s_b_4_1[s_b_4_15] */
    auto s_b_4_16 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3351 [D] s_b_4_17 = (u32)s_b_4_16 */
    auto s_b_4_17 = emitter.zx(s_b_4_16, emitter.context().types().u32());
    /* execute.simd:3351 [D] s_b_4_18 = s_b_4_14+s_b_4_17 */
    auto s_b_4_18 = emitter.add(s_b_4_14, s_b_4_17);
    /* execute.simd:3351 [F] s_b_4_19 = constant s32 1 (const) */
    /* execute.simd:3351 [D] s_b_4_20 = s_b_4_11[s_b_4_19] <= s_b_4_18 */
    auto s_b_4_20 = emitter.vector_insert(s_b_4_11, emitter.const_s32((int32_t)1ULL), s_b_4_18);
    /* execute.simd:3354 [F] s_b_4_21=sym_37638_3_parameter_inst.rd (const) */
    /* execute.simd:3354 [D] s_b_4_22: WriteRegBank 19:s_b_4_21 = s_b_4_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_20,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_20);
    /* execute.simd:3355 [F] s_b_4_23=sym_37638_3_parameter_inst.rd (const) */
    /* execute.simd:3355 [F] s_b_4_24 = constant u64 0 (const) */
    /* execute.simd:3355 [F] s_b_4_25: WriteRegBank 3:s_b_4_23 = s_b_4_24 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:3359 [F] s_b_5_0=sym_37638_3_parameter_inst.rn (const) */
    /* execute.simd:3359 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_2 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:3363 [F] s_b_5_3 = constant u32 0 (const) */
    /* execute.simd:3363 [D] s_b_5_1[s_b_5_3] */
    auto s_b_5_4 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3363 [D] s_b_5_5 = (u32)s_b_5_4 */
    auto s_b_5_5 = emitter.zx(s_b_5_4, emitter.context().types().u32());
    /* execute.simd:3363 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.simd:3363 [D] s_b_5_1[s_b_5_6] */
    auto s_b_5_7 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3363 [D] s_b_5_8 = (u32)s_b_5_7 */
    auto s_b_5_8 = emitter.zx(s_b_5_7, emitter.context().types().u32());
    /* execute.simd:3363 [D] s_b_5_9 = s_b_5_5+s_b_5_8 */
    auto s_b_5_9 = emitter.add(s_b_5_5, s_b_5_8);
    /* execute.simd:3363 [F] s_b_5_10 = constant s32 0 (const) */
    /* execute.simd:3363 [D] s_b_5_11 = s_b_5_2[s_b_5_10] <= s_b_5_9 */
    auto s_b_5_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_5_9);
    /* execute.simd:3363 [F] s_b_5_12 = constant u32 2 (const) */
    /* execute.simd:3363 [D] s_b_5_1[s_b_5_12] */
    auto s_b_5_13 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3363 [D] s_b_5_14 = (u32)s_b_5_13 */
    auto s_b_5_14 = emitter.zx(s_b_5_13, emitter.context().types().u32());
    /* execute.simd:3363 [F] s_b_5_15 = constant u32 3 (const) */
    /* execute.simd:3363 [D] s_b_5_1[s_b_5_15] */
    auto s_b_5_16 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3363 [D] s_b_5_17 = (u32)s_b_5_16 */
    auto s_b_5_17 = emitter.zx(s_b_5_16, emitter.context().types().u32());
    /* execute.simd:3363 [D] s_b_5_18 = s_b_5_14+s_b_5_17 */
    auto s_b_5_18 = emitter.add(s_b_5_14, s_b_5_17);
    /* execute.simd:3363 [F] s_b_5_19 = constant s32 1 (const) */
    /* execute.simd:3363 [D] s_b_5_20 = s_b_5_11[s_b_5_19] <= s_b_5_18 */
    auto s_b_5_20 = emitter.vector_insert(s_b_5_11, emitter.const_s32((int32_t)1ULL), s_b_5_18);
    /* execute.simd:3363 [F] s_b_5_21 = constant u32 4 (const) */
    /* execute.simd:3363 [D] s_b_5_1[s_b_5_21] */
    auto s_b_5_22 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3363 [D] s_b_5_23 = (u32)s_b_5_22 */
    auto s_b_5_23 = emitter.zx(s_b_5_22, emitter.context().types().u32());
    /* execute.simd:3363 [F] s_b_5_24 = constant u32 5 (const) */
    /* execute.simd:3363 [D] s_b_5_1[s_b_5_24] */
    auto s_b_5_25 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3363 [D] s_b_5_26 = (u32)s_b_5_25 */
    auto s_b_5_26 = emitter.zx(s_b_5_25, emitter.context().types().u32());
    /* execute.simd:3363 [D] s_b_5_27 = s_b_5_23+s_b_5_26 */
    auto s_b_5_27 = emitter.add(s_b_5_23, s_b_5_26);
    /* execute.simd:3363 [F] s_b_5_28 = constant s32 2 (const) */
    /* execute.simd:3363 [D] s_b_5_29 = s_b_5_20[s_b_5_28] <= s_b_5_27 */
    auto s_b_5_29 = emitter.vector_insert(s_b_5_20, emitter.const_s32((int32_t)2ULL), s_b_5_27);
    /* execute.simd:3363 [F] s_b_5_30 = constant u32 6 (const) */
    /* execute.simd:3363 [D] s_b_5_1[s_b_5_30] */
    auto s_b_5_31 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3363 [D] s_b_5_32 = (u32)s_b_5_31 */
    auto s_b_5_32 = emitter.zx(s_b_5_31, emitter.context().types().u32());
    /* execute.simd:3363 [F] s_b_5_33 = constant u32 7 (const) */
    /* execute.simd:3363 [D] s_b_5_1[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3363 [D] s_b_5_35 = (u32)s_b_5_34 */
    auto s_b_5_35 = emitter.zx(s_b_5_34, emitter.context().types().u32());
    /* execute.simd:3363 [D] s_b_5_36 = s_b_5_32+s_b_5_35 */
    auto s_b_5_36 = emitter.add(s_b_5_32, s_b_5_35);
    /* execute.simd:3363 [F] s_b_5_37 = constant s32 3 (const) */
    /* execute.simd:3363 [D] s_b_5_38 = s_b_5_29[s_b_5_37] <= s_b_5_36 */
    auto s_b_5_38 = emitter.vector_insert(s_b_5_29, emitter.const_s32((int32_t)3ULL), s_b_5_36);
    /* execute.simd:3366 [F] s_b_5_39=sym_37638_3_parameter_inst.rd (const) */
    /* execute.simd:3366 [D] s_b_5_40: WriteRegBank 20:s_b_5_39 = s_b_5_38 */
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
    /* execute.simd:3370 [F] s_b_6_0=sym_37638_3_parameter_inst.rn (const) */
    /* execute.simd:3370 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:3373 [F] s_b_6_3 = constant s32 0 (const) */
    /* execute.simd:3373 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3373 [D] s_b_6_5 = (u64)s_b_6_4 */
    auto s_b_6_5 = emitter.zx(s_b_6_4, emitter.context().types().u64());
    /* execute.simd:3373 [F] s_b_6_6 = constant s32 1 (const) */
    /* execute.simd:3373 [D] s_b_6_1[s_b_6_6] */
    auto s_b_6_7 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:3373 [D] s_b_6_8 = (u64)s_b_6_7 */
    auto s_b_6_8 = emitter.zx(s_b_6_7, emitter.context().types().u64());
    /* execute.simd:3373 [D] s_b_6_9 = s_b_6_5+s_b_6_8 */
    auto s_b_6_9 = emitter.add(s_b_6_5, s_b_6_8);
    /* execute.simd:3373 [F] s_b_6_10 = constant s32 0 (const) */
    /* execute.simd:3373 [D] s_b_6_11 = s_b_6_2[s_b_6_10] <= s_b_6_9 */
    auto s_b_6_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_6_9);
    /* execute.simd:3375 [F] s_b_6_12=sym_37638_3_parameter_inst.rd (const) */
    /* execute.simd:3375 [D] s_b_6_13: WriteRegBank 21:s_b_6_12 = s_b_6_11 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_11,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_11);
    /* execute.simd:0 [F] s_b_6_14: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:3379 [F] s_b_7_0=sym_37638_3_parameter_inst.rn (const) */
    /* execute.simd:3379 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_2 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:3382 [F] s_b_7_3 = constant s32 0 (const) */
    /* execute.simd:3382 [D] s_b_7_1[s_b_7_3] */
    auto s_b_7_4 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3382 [D] s_b_7_5 = (u64)s_b_7_4 */
    auto s_b_7_5 = emitter.zx(s_b_7_4, emitter.context().types().u64());
    /* execute.simd:3382 [F] s_b_7_6 = constant s32 1 (const) */
    /* execute.simd:3382 [D] s_b_7_1[s_b_7_6] */
    auto s_b_7_7 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:3382 [D] s_b_7_8 = (u64)s_b_7_7 */
    auto s_b_7_8 = emitter.zx(s_b_7_7, emitter.context().types().u64());
    /* execute.simd:3382 [D] s_b_7_9 = s_b_7_5+s_b_7_8 */
    auto s_b_7_9 = emitter.add(s_b_7_5, s_b_7_8);
    /* execute.simd:3382 [F] s_b_7_10 = constant s32 0 (const) */
    /* execute.simd:3382 [D] s_b_7_11 = s_b_7_2[s_b_7_10] <= s_b_7_9 */
    auto s_b_7_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_7_9);
    /* execute.simd:3383 [F] s_b_7_12 = constant s32 2 (const) */
    /* execute.simd:3383 [D] s_b_7_1[s_b_7_12] */
    auto s_b_7_13 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:3383 [D] s_b_7_14 = (u64)s_b_7_13 */
    auto s_b_7_14 = emitter.zx(s_b_7_13, emitter.context().types().u64());
    /* execute.simd:3383 [F] s_b_7_15 = constant s32 3 (const) */
    /* execute.simd:3383 [D] s_b_7_1[s_b_7_15] */
    auto s_b_7_16 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:3383 [D] s_b_7_17 = (u64)s_b_7_16 */
    auto s_b_7_17 = emitter.zx(s_b_7_16, emitter.context().types().u64());
    /* execute.simd:3383 [D] s_b_7_18 = s_b_7_14+s_b_7_17 */
    auto s_b_7_18 = emitter.add(s_b_7_14, s_b_7_17);
    /* execute.simd:3383 [F] s_b_7_19 = constant s32 1 (const) */
    /* execute.simd:3383 [D] s_b_7_20 = s_b_7_11[s_b_7_19] <= s_b_7_18 */
    auto s_b_7_20 = emitter.vector_insert(s_b_7_11, emitter.const_s32((int32_t)1ULL), s_b_7_18);
    /* execute.simd:3385 [F] s_b_7_21=sym_37638_3_parameter_inst.rd (const) */
    /* execute.simd:3385 [D] s_b_7_22: WriteRegBank 21:s_b_7_21 = s_b_7_20 */
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
    /* execute.simd:3389 [D] s_b_8_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_umaxv(const aarch64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ushr(const aarch64_decode_a64_SIMD_SHIFT_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4636 [F] s_b_0_0=sym_43668_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4636 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4637 [F] s_b_1_0=sym_43668_3_parameter_inst.immh (const) */
    /* execute.simd:4637 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4637 [F] s_b_1_2 = constant u32 3 (const) */
    /* execute.simd:4637 [F] s_b_1_3 = s_b_1_1<<s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4637 [F] s_b_1_4=sym_43668_3_parameter_inst.immb (const) */
    /* execute.simd:4637 [F] s_b_1_5 = (u32)s_b_1_4 (const) */
    /* execute.simd:4637 [F] s_b_1_6 = s_b_1_3|s_b_1_5 (const) */
    uint32_t s_b_1_6 = ((uint32_t)(s_b_1_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4637 [F] s_b_1_7 = constant u32 80 (const) */
    /* execute.simd:4637 [F] s_b_1_8 = s_b_1_7-s_b_1_6 (const) */
    uint32_t s_b_1_8 = ((uint32_t)((uint32_t)128ULL - s_b_1_6));
    /* execute.simd:4637 [F] s_b_1_9 = (u64)s_b_1_8 (const) */
    /* execute.simd:4638 [F] s_b_1_10=sym_43668_3_parameter_inst.rd (const) */
    /* execute.simd:4638 [F] s_b_1_11=sym_43668_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_1_12 = ReadRegBank 7:s_b_1_11 (u64) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_12,emitter.const_u8(8));
    }
    /* execute.simd:4638 [D] s_b_1_13 = s_b_1_12>>s_b_1_9 */
    auto s_b_1_13 = emitter.shr(s_b_1_12, emitter.const_u64(((uint64_t)s_b_1_8)));
    /* execute.simd:6138 [D] s_b_1_14: WriteRegBank 2:s_b_1_10 = s_b_1_13 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_13);
    /* execute.simd:6139 [F] s_b_1_15 = constant u64 0 (const) */
    /* execute.simd:6139 [F] s_b_1_16: WriteRegBank 3:s_b_1_10 = s_b_1_15 */
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
    /* execute.simd:4640 [F] s_b_3_0=sym_43668_3_parameter_inst.arrangement (const) */
    /* execute.simd:4641 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:4649 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:4656 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:4664 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:4671 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:4679 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:4686 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:4640 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
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
    /* execute.simd:4642 [F] s_b_4_0=sym_43668_3_parameter_inst.immh (const) */
    /* execute.simd:4642 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4642 [F] s_b_4_2 = constant u32 3 (const) */
    /* execute.simd:4642 [F] s_b_4_3 = s_b_4_1<<s_b_4_2 (const) */
    uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4642 [F] s_b_4_4=sym_43668_3_parameter_inst.immb (const) */
    /* execute.simd:4642 [F] s_b_4_5 = (u32)s_b_4_4 (const) */
    /* execute.simd:4642 [F] s_b_4_6 = s_b_4_3|s_b_4_5 (const) */
    uint32_t s_b_4_6 = ((uint32_t)(s_b_4_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4642 [F] s_b_4_7 = constant u32 10 (const) */
    /* execute.simd:4642 [F] s_b_4_8 = s_b_4_7-s_b_4_6 (const) */
    uint32_t s_b_4_8 = ((uint32_t)((uint32_t)16ULL - s_b_4_6));
    /* execute.simd:4642 [F] s_b_4_9 = (u64)s_b_4_8 (const) */
    /* execute.simd:4644 [F] s_b_4_10=sym_43668_3_parameter_inst.rn (const) */
    /* execute.simd:4644 [D] s_b_4_11 = ReadRegBank 15:s_b_4_10 (v8u8) */
    auto s_b_4_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_11,emitter.const_u8(8));
    }
    /* execute.simd:4645 [F] s_b_4_12=sym_43668_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_4_13 = (v8u8)s_b_4_9 (const) */
    auto s_b_4_13 = wutils::Vector<uint8_t, 8>(((uint64_t)s_b_4_8));
    /* execute.simd:4645 [D] s_b_4_14 = s_b_4_11>>s_b_4_13 */
    auto s_b_4_14 = emitter.shr(s_b_4_11, emitter.constant_vector_splat(s_b_4_13[0], emitter.context().types().v8u8()));
    /* execute.simd:4645 [D] s_b_4_15: WriteRegBank 15:s_b_4_12 = s_b_4_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_14,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_14);
    /* execute.simd:4646 [F] s_b_4_16=sym_43668_3_parameter_inst.rd (const) */
    /* execute.simd:4646 [F] s_b_4_17 = constant u64 0 (const) */
    /* execute.simd:4646 [F] s_b_4_18: WriteRegBank 3:s_b_4_16 = s_b_4_17 */
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
    /* execute.simd:4650 [F] s_b_5_0=sym_43668_3_parameter_inst.immh (const) */
    /* execute.simd:4650 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4650 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.simd:4650 [F] s_b_5_3 = s_b_5_1<<s_b_5_2 (const) */
    uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4650 [F] s_b_5_4=sym_43668_3_parameter_inst.immb (const) */
    /* execute.simd:4650 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4650 [F] s_b_5_6 = s_b_5_3|s_b_5_5 (const) */
    uint32_t s_b_5_6 = ((uint32_t)(s_b_5_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4650 [F] s_b_5_7 = constant u32 10 (const) */
    /* execute.simd:4650 [F] s_b_5_8 = s_b_5_7-s_b_5_6 (const) */
    uint32_t s_b_5_8 = ((uint32_t)((uint32_t)16ULL - s_b_5_6));
    /* execute.simd:4650 [F] s_b_5_9 = (u64)s_b_5_8 (const) */
    /* execute.simd:4652 [F] s_b_5_10=sym_43668_3_parameter_inst.rn (const) */
    /* execute.simd:4652 [D] s_b_5_11 = ReadRegBank 16:s_b_5_10 (v16u8) */
    auto s_b_5_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_11,emitter.const_u8(16));
    }
    /* execute.simd:4653 [F] s_b_5_12=sym_43668_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_5_13 = (v16u8)s_b_5_9 (const) */
    auto s_b_5_13 = wutils::Vector<uint8_t, 16>(((uint64_t)s_b_5_8));
    /* execute.simd:4653 [D] s_b_5_14 = s_b_5_11>>s_b_5_13 */
    auto s_b_5_14 = emitter.shr(s_b_5_11, emitter.constant_vector_splat(s_b_5_13[0], emitter.context().types().v16u8()));
    /* execute.simd:4653 [D] s_b_5_15: WriteRegBank 16:s_b_5_12 = s_b_5_14 */
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
    /* execute.simd:4657 [F] s_b_6_0=sym_43668_3_parameter_inst.immh (const) */
    /* execute.simd:4657 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.simd:4657 [F] s_b_6_2 = constant u32 3 (const) */
    /* execute.simd:4657 [F] s_b_6_3 = s_b_6_1<<s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4657 [F] s_b_6_4=sym_43668_3_parameter_inst.immb (const) */
    /* execute.simd:4657 [F] s_b_6_5 = (u32)s_b_6_4 (const) */
    /* execute.simd:4657 [F] s_b_6_6 = s_b_6_3|s_b_6_5 (const) */
    uint32_t s_b_6_6 = ((uint32_t)(s_b_6_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4657 [F] s_b_6_7 = constant u32 20 (const) */
    /* execute.simd:4657 [F] s_b_6_8 = s_b_6_7-s_b_6_6 (const) */
    uint32_t s_b_6_8 = ((uint32_t)((uint32_t)32ULL - s_b_6_6));
    /* execute.simd:4657 [F] s_b_6_9 = (u64)s_b_6_8 (const) */
    /* execute.simd:4659 [F] s_b_6_10=sym_43668_3_parameter_inst.rn (const) */
    /* execute.simd:4659 [D] s_b_6_11 = ReadRegBank 17:s_b_6_10 (v4u16) */
    auto s_b_6_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_11,emitter.const_u8(8));
    }
    /* execute.simd:4660 [F] s_b_6_12=sym_43668_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_6_13 = (v4u16)s_b_6_9 (const) */
    auto s_b_6_13 = wutils::Vector<uint16_t, 4>(((uint64_t)s_b_6_8));
    /* execute.simd:4660 [D] s_b_6_14 = s_b_6_11>>s_b_6_13 */
    auto s_b_6_14 = emitter.shr(s_b_6_11, emitter.constant_vector_splat(s_b_6_13[0], emitter.context().types().v4u16()));
    /* execute.simd:4660 [D] s_b_6_15: WriteRegBank 17:s_b_6_12 = s_b_6_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_14,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_14);
    /* execute.simd:4661 [F] s_b_6_16=sym_43668_3_parameter_inst.rd (const) */
    /* execute.simd:4661 [F] s_b_6_17 = constant u64 0 (const) */
    /* execute.simd:4661 [F] s_b_6_18: WriteRegBank 3:s_b_6_16 = s_b_6_17 */
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
    /* execute.simd:4665 [F] s_b_7_0=sym_43668_3_parameter_inst.immh (const) */
    /* execute.simd:4665 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4665 [F] s_b_7_2 = constant u32 3 (const) */
    /* execute.simd:4665 [F] s_b_7_3 = s_b_7_1<<s_b_7_2 (const) */
    uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4665 [F] s_b_7_4=sym_43668_3_parameter_inst.immb (const) */
    /* execute.simd:4665 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4665 [F] s_b_7_6 = s_b_7_3|s_b_7_5 (const) */
    uint32_t s_b_7_6 = ((uint32_t)(s_b_7_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4665 [F] s_b_7_7 = constant u32 20 (const) */
    /* execute.simd:4665 [F] s_b_7_8 = s_b_7_7-s_b_7_6 (const) */
    uint32_t s_b_7_8 = ((uint32_t)((uint32_t)32ULL - s_b_7_6));
    /* execute.simd:4665 [F] s_b_7_9 = (u64)s_b_7_8 (const) */
    /* execute.simd:4667 [F] s_b_7_10=sym_43668_3_parameter_inst.rn (const) */
    /* execute.simd:4667 [D] s_b_7_11 = ReadRegBank 18:s_b_7_10 (v8u16) */
    auto s_b_7_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_11,emitter.const_u8(16));
    }
    /* execute.simd:4668 [F] s_b_7_12=sym_43668_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_7_13 = (v8u16)s_b_7_9 (const) */
    auto s_b_7_13 = wutils::Vector<uint16_t, 8>(((uint64_t)s_b_7_8));
    /* execute.simd:4668 [D] s_b_7_14 = s_b_7_11>>s_b_7_13 */
    auto s_b_7_14 = emitter.shr(s_b_7_11, emitter.constant_vector_splat(s_b_7_13[0], emitter.context().types().v8u16()));
    /* execute.simd:4668 [D] s_b_7_15: WriteRegBank 18:s_b_7_12 = s_b_7_14 */
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
    /* execute.simd:4672 [F] s_b_8_0=sym_43668_3_parameter_inst.immh (const) */
    /* execute.simd:4672 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.simd:4672 [F] s_b_8_2 = constant u32 3 (const) */
    /* execute.simd:4672 [F] s_b_8_3 = s_b_8_1<<s_b_8_2 (const) */
    uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4672 [F] s_b_8_4=sym_43668_3_parameter_inst.immb (const) */
    /* execute.simd:4672 [F] s_b_8_5 = (u32)s_b_8_4 (const) */
    /* execute.simd:4672 [F] s_b_8_6 = s_b_8_3|s_b_8_5 (const) */
    uint32_t s_b_8_6 = ((uint32_t)(s_b_8_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4672 [F] s_b_8_7 = constant u32 40 (const) */
    /* execute.simd:4672 [F] s_b_8_8 = s_b_8_7-s_b_8_6 (const) */
    uint32_t s_b_8_8 = ((uint32_t)((uint32_t)64ULL - s_b_8_6));
    /* execute.simd:4672 [F] s_b_8_9 = (u64)s_b_8_8 (const) */
    /* execute.simd:4674 [F] s_b_8_10=sym_43668_3_parameter_inst.rn (const) */
    /* execute.simd:4674 [D] s_b_8_11 = ReadRegBank 19:s_b_8_10 (v2u32) */
    auto s_b_8_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_11,emitter.const_u8(8));
    }
    /* execute.simd:4675 [F] s_b_8_12=sym_43668_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_8_13 = (v2u32)s_b_8_9 (const) */
    auto s_b_8_13 = wutils::Vector<uint32_t, 2>(((uint64_t)s_b_8_8));
    /* execute.simd:4675 [D] s_b_8_14 = s_b_8_11>>s_b_8_13 */
    auto s_b_8_14 = emitter.shr(s_b_8_11, emitter.constant_vector_splat(s_b_8_13[0], emitter.context().types().v2u32()));
    /* execute.simd:4675 [D] s_b_8_15: WriteRegBank 19:s_b_8_12 = s_b_8_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_14,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_14);
    /* execute.simd:4676 [F] s_b_8_16=sym_43668_3_parameter_inst.rd (const) */
    /* execute.simd:4676 [F] s_b_8_17 = constant u64 0 (const) */
    /* execute.simd:4676 [F] s_b_8_18: WriteRegBank 3:s_b_8_16 = s_b_8_17 */
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
    /* execute.simd:4680 [F] s_b_9_0=sym_43668_3_parameter_inst.immh (const) */
    /* execute.simd:4680 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4680 [F] s_b_9_2 = constant u32 3 (const) */
    /* execute.simd:4680 [F] s_b_9_3 = s_b_9_1<<s_b_9_2 (const) */
    uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4680 [F] s_b_9_4=sym_43668_3_parameter_inst.immb (const) */
    /* execute.simd:4680 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4680 [F] s_b_9_6 = s_b_9_3|s_b_9_5 (const) */
    uint32_t s_b_9_6 = ((uint32_t)(s_b_9_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4680 [F] s_b_9_7 = constant u32 40 (const) */
    /* execute.simd:4680 [F] s_b_9_8 = s_b_9_7-s_b_9_6 (const) */
    uint32_t s_b_9_8 = ((uint32_t)((uint32_t)64ULL - s_b_9_6));
    /* execute.simd:4680 [F] s_b_9_9 = (u64)s_b_9_8 (const) */
    /* execute.simd:4682 [F] s_b_9_10=sym_43668_3_parameter_inst.rn (const) */
    /* execute.simd:4682 [D] s_b_9_11 = ReadRegBank 20:s_b_9_10 (v4u32) */
    auto s_b_9_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_11,emitter.const_u8(16));
    }
    /* execute.simd:4683 [F] s_b_9_12=sym_43668_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_9_13 = (v4u32)s_b_9_9 (const) */
    auto s_b_9_13 = wutils::Vector<uint32_t, 4>(((uint64_t)s_b_9_8));
    /* execute.simd:4683 [D] s_b_9_14 = s_b_9_11>>s_b_9_13 */
    auto s_b_9_14 = emitter.shr(s_b_9_11, emitter.constant_vector_splat(s_b_9_13[0], emitter.context().types().v4u32()));
    /* execute.simd:4683 [D] s_b_9_15: WriteRegBank 20:s_b_9_12 = s_b_9_14 */
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
    /* execute.simd:4687 [F] s_b_10_0=sym_43668_3_parameter_inst.immh (const) */
    /* execute.simd:4687 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4687 [F] s_b_10_2 = constant u32 3 (const) */
    /* execute.simd:4687 [F] s_b_10_3 = s_b_10_1<<s_b_10_2 (const) */
    uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.immh) << (uint32_t)3ULL));
    /* execute.simd:4687 [F] s_b_10_4=sym_43668_3_parameter_inst.immb (const) */
    /* execute.simd:4687 [F] s_b_10_5 = (u32)s_b_10_4 (const) */
    /* execute.simd:4687 [F] s_b_10_6 = s_b_10_3|s_b_10_5 (const) */
    uint32_t s_b_10_6 = ((uint32_t)(s_b_10_3 | ((uint32_t)insn.immb)));
    /* execute.simd:4687 [F] s_b_10_7 = constant u32 80 (const) */
    /* execute.simd:4687 [F] s_b_10_8 = s_b_10_7-s_b_10_6 (const) */
    uint32_t s_b_10_8 = ((uint32_t)((uint32_t)128ULL - s_b_10_6));
    /* execute.simd:4687 [F] s_b_10_9 = (u64)s_b_10_8 (const) */
    /* execute.simd:4689 [F] s_b_10_10=sym_43668_3_parameter_inst.rn (const) */
    /* execute.simd:4689 [D] s_b_10_11 = ReadRegBank 21:s_b_10_10 (v2u64) */
    auto s_b_10_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_11,emitter.const_u8(16));
    }
    /* execute.simd:4690 [F] s_b_10_12=sym_43668_3_parameter_inst.rd (const) */
    /* ???:4294967295 [F] s_b_10_13 = (v2u64)s_b_10_9 (const) */
    auto s_b_10_13 = wutils::Vector<uint64_t, 2>(((uint64_t)s_b_10_8));
    /* execute.simd:4690 [D] s_b_10_14 = s_b_10_11>>s_b_10_13 */
    auto s_b_10_14 = emitter.shr(s_b_10_11, emitter.constant_vector_splat(s_b_10_13[0], emitter.context().types().v2u64()));
    /* execute.simd:4690 [D] s_b_10_15: WriteRegBank 21:s_b_10_12 = s_b_10_14 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_vstur(const aarch64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_150991_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_151008_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_151085_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3831 [F] s_b_0_0=sym_46381_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_2_0=sym_46381_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_150991_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_150991_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_150991_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_150991_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:3832 [F] s_b_3_1=sym_46381_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.simd:3834 [F] s_b_3_4=sym_46381_3_parameter_inst.size (const) */
    /* execute.simd:3834 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:3834 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:3834 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:3834 [F] s_b_3_8=sym_46381_3_parameter_inst.opc (const) */
    /* execute.simd:3834 [F] s_b_3_9 = (u32)s_b_3_8 (const) */
    /* execute.simd:3834 [F] s_b_3_10 = constant u32 0 (const) */
    /* execute.simd:3834 [F] s_b_3_11 = s_b_3_9==s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.simd:3834 [F] s_b_3_12 = constant u8 0 (const) */
    /* execute.simd:3834 [F] s_b_3_13 = constant u8 4 (const) */
    /* execute.simd:3834 [F] s_b_3_14: Select s_b_3_11 ? s_b_3_12 : s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(s_b_3_11 ? ((uint8_t)0ULL) : ((uint8_t)4ULL)));
    /* execute.simd:3834 [F] s_b_3_15=sym_46381_3_parameter_inst.size (const) */
    /* execute.simd:3834 [F] s_b_3_16 = (u8)s_b_3_15 (const) */
    /* execute.simd:3834 [F] s_b_3_17: Select s_b_3_7 ? s_b_3_14 : s_b_3_16 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(s_b_3_7 ? (s_b_3_14) : (((uint8_t)insn.size))));
    /* ???:4294967295 [D] s_b_3_18: sym_151085_0_replaced_parameter_addr = s_b_3_3, dominates: s_b_13_3 s_b_12_2 s_b_10_2 s_b_9_2 s_b_11_2  */
    emitter.store_local(DV_sym_151085_0_replaced_parameter_addr, s_b_3_3);
    /* execute.simd:3566 [F] s_b_3_19 = constant s32 0 (const) */
    /* execute.simd:3572 [F] s_b_3_20 = constant s32 1 (const) */
    /* execute.simd:3578 [F] s_b_3_21 = constant s32 2 (const) */
    /* execute.simd:3584 [F] s_b_3_22 = constant s32 3 (const) */
    /* execute.simd:3590 [F] s_b_3_23 = constant s32 4 (const) */
    /* execute.simd:3565 [F] s_b_3_24: Switch s_b_3_17: < <todo> > def b_14 (const) -> b_14, b_13, b_12, b_10, b_9, b_11,  */
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
    /* execute.a64:2702 [D] s_b_4_0 = ReadReg 20 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_4_1: sym_151008_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_151008_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2731 [D] s_b_6_0 = sym_151008_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_151008_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_150991_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_150991_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2705 [D] s_b_7_1: sym_151008_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_151008_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2707 [D] s_b_8_1: sym_151008_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_151008_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2707 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3568 [F] s_b_9_0=sym_46381_3_parameter_inst.rt (const) */
    /* execute.simd:6152 [D] s_b_9_1 = ReadRegBank 4:s_b_9_0 (u8) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_1,emitter.const_u8(1));
    }
    /* execute.simd:3569 [D] s_b_9_2 = sym_151085_0_replaced_parameter_addr uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_151085_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3574 [F] s_b_10_0=sym_46381_3_parameter_inst.rt (const) */
    /* execute.simd:6157 [D] s_b_10_1 = ReadRegBank 5:s_b_10_0 (u16) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_1,emitter.const_u8(2));
    }
    /* execute.simd:3575 [D] s_b_10_2 = sym_151085_0_replaced_parameter_addr uint64_t */
    auto s_b_10_2 = emitter.load_local(DV_sym_151085_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3580 [F] s_b_11_0=sym_46381_3_parameter_inst.rt (const) */
    /* execute.simd:6162 [D] s_b_11_1 = ReadRegBank 6:s_b_11_0 (u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_11_1,emitter.const_u8(4));
    }
    /* execute.simd:3581 [D] s_b_11_2 = sym_151085_0_replaced_parameter_addr uint64_t */
    auto s_b_11_2 = emitter.load_local(DV_sym_151085_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3586 [F] s_b_12_0=sym_46381_3_parameter_inst.rt (const) */
    /* execute.simd:6167 [D] s_b_12_1 = ReadRegBank 7:s_b_12_0 (u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:3587 [D] s_b_12_2 = sym_151085_0_replaced_parameter_addr uint64_t */
    auto s_b_12_2 = emitter.load_local(DV_sym_151085_0_replaced_parameter_addr, emitter.context().types().u64());
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
    /* execute.simd:3594 [F] s_b_13_0=sym_46381_3_parameter_inst.rt (const) */
    /* execute.simd:6172 [D] s_b_13_1 = ReadRegBank 2:s_b_13_0 (u64) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1,emitter.const_u8(8));
    }
    /* execute.simd:6173 [D] s_b_13_2 = ReadRegBank 3:s_b_13_0 (u64) */
    auto s_b_13_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),s_b_13_2,emitter.const_u8(8));
    }
    /* execute.simd:3595 [D] s_b_13_3 = sym_151085_0_replaced_parameter_addr uint64_t */
    auto s_b_13_3 = emitter.load_local(DV_sym_151085_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_4: Store 8 s_b_13_3 <= s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_13_3, s_b_13_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_13_3, s_b_13_1);
    /* execute.simd:3596 [F] s_b_13_5 = constant u64 8 (const) */
    /* execute.simd:3596 [D] s_b_13_6 = s_b_13_3+s_b_13_5 */
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
template class aarch64_jit2<true>;
template class aarch64_jit2<false>;
