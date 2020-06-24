#include <arm64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::arm64;
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_add_vector(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:833 [F] s_b_0_0=sym_3448_3_parameter_inst.SCALAR (const) */
    /* execute.simd:833 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:833 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.simd:833 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:833 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:834 [F] s_b_1_0=sym_3448_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:835 [F] s_b_1_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:6355 [D] s_b_1_3 = ReadRegBank 7:s_b_1_2 (u64) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(8));
    }
    /* execute.simd:837 [F] s_b_1_4=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:837 [D] s_b_1_5 = s_b_1_1+s_b_1_3 */
    auto s_b_1_5 = emitter.add(s_b_1_1, s_b_1_3);
    /* execute.simd:6326 [D] s_b_1_6: WriteRegBank 2:s_b_1_4 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6327 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_8: WriteRegBank 3:s_b_1_4 = s_b_1_7 */
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
    /* execute.simd:839 [F] s_b_3_0=sym_3448_3_parameter_inst.arrangement (const) */
    /* execute.simd:840 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:850 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:858 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:868 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:877 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:887 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:895 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:839 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_11 (const) -> b_11, b_10, b_9, b_8, b_7, b_6, b_5, b_4,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_8;
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
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:841 [F] s_b_4_0=sym_3448_3_parameter_inst.rn (const) */
    /* execute.simd:841 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:842 [F] s_b_4_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:842 [D] s_b_4_3 = ReadRegBank 15:s_b_4_2 (v8u8) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* execute.simd:844 [D] s_b_4_4 = s_b_4_1+s_b_4_3 */
    auto s_b_4_4 = emitter.add(s_b_4_1, s_b_4_3);
    /* execute.simd:845 [F] s_b_4_5=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:845 [D] s_b_4_6: WriteRegBank 15:s_b_4_5 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:846 [F] s_b_4_7=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:846 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:846 [F] s_b_4_9: WriteRegBank 3:s_b_4_7 = s_b_4_8 */
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
    /* execute.simd:851 [F] s_b_5_0=sym_3448_3_parameter_inst.rn (const) */
    /* execute.simd:851 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:852 [F] s_b_5_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:852 [D] s_b_5_3 = ReadRegBank 16:s_b_5_2 (v16u8) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:854 [D] s_b_5_4 = s_b_5_1+s_b_5_3 */
    auto s_b_5_4 = emitter.add(s_b_5_1, s_b_5_3);
    /* execute.simd:855 [F] s_b_5_5=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:855 [D] s_b_5_6: WriteRegBank 16:s_b_5_5 = s_b_5_4 */
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
    /* execute.simd:859 [F] s_b_6_0=sym_3448_3_parameter_inst.rn (const) */
    /* execute.simd:859 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:860 [F] s_b_6_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:860 [D] s_b_6_3 = ReadRegBank 17:s_b_6_2 (v4u16) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:862 [D] s_b_6_4 = s_b_6_1+s_b_6_3 */
    auto s_b_6_4 = emitter.add(s_b_6_1, s_b_6_3);
    /* execute.simd:863 [F] s_b_6_5=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:863 [D] s_b_6_6: WriteRegBank 17:s_b_6_5 = s_b_6_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
    /* execute.simd:864 [F] s_b_6_7=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:864 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:864 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
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
    /* execute.simd:869 [F] s_b_7_0=sym_3448_3_parameter_inst.rn (const) */
    /* execute.simd:869 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:870 [F] s_b_7_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:870 [D] s_b_7_3 = ReadRegBank 18:s_b_7_2 (v8u16) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:872 [D] s_b_7_4 = s_b_7_1+s_b_7_3 */
    auto s_b_7_4 = emitter.add(s_b_7_1, s_b_7_3);
    /* execute.simd:873 [F] s_b_7_5=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:873 [D] s_b_7_6: WriteRegBank 18:s_b_7_5 = s_b_7_4 */
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
    /* execute.simd:878 [F] s_b_8_0=sym_3448_3_parameter_inst.rn (const) */
    /* execute.simd:878 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:879 [F] s_b_8_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:879 [D] s_b_8_3 = ReadRegBank 19:s_b_8_2 (v2u32) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(8));
    }
    /* execute.simd:881 [D] s_b_8_4 = s_b_8_1+s_b_8_3 */
    auto s_b_8_4 = emitter.add(s_b_8_1, s_b_8_3);
    /* execute.simd:882 [F] s_b_8_5=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:882 [D] s_b_8_6: WriteRegBank 19:s_b_8_5 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4);
    /* execute.simd:883 [F] s_b_8_7=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:883 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:883 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
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
    /* execute.simd:888 [F] s_b_9_0=sym_3448_3_parameter_inst.rn (const) */
    /* execute.simd:888 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:889 [F] s_b_9_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:889 [D] s_b_9_3 = ReadRegBank 20:s_b_9_2 (v4u32) */
    auto s_b_9_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_9_3,emitter.const_u8(16));
    }
    /* execute.simd:891 [D] s_b_9_4 = s_b_9_1+s_b_9_3 */
    auto s_b_9_4 = emitter.add(s_b_9_1, s_b_9_3);
    /* execute.simd:892 [F] s_b_9_5=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:892 [D] s_b_9_6: WriteRegBank 20:s_b_9_5 = s_b_9_4 */
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
    /* execute.simd:896 [F] s_b_10_0=sym_3448_3_parameter_inst.rn (const) */
    /* execute.simd:896 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:897 [F] s_b_10_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:897 [D] s_b_10_3 = ReadRegBank 21:s_b_10_2 (v2u64) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_3,emitter.const_u8(16));
    }
    /* execute.simd:899 [D] s_b_10_4 = s_b_10_1+s_b_10_3 */
    auto s_b_10_4 = emitter.add(s_b_10_1, s_b_10_3);
    /* execute.simd:900 [F] s_b_10_5=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:900 [D] s_b_10_6: WriteRegBank 21:s_b_10_5 = s_b_10_4 */
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
    /* execute.simd:905 [D] s_b_11_0 = trap */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_andsr(const arm64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_51394_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_51413_1_temporary_value;
  auto DV_sym_51413_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_5882_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_51782_1_temporary_value;
  auto DV_sym_51782_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51753_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52085_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_51810_1_temporary_value;
  auto DV_sym_51810_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_51687_1__R_s_b_26_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_51673_1_temporary_value;
  auto DV_sym_51673_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_51661_1_temporary_value;
  auto DV_sym_51661_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_51558_1_tmp_s_b_9_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51578_1__R_s_b_21_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_51838_1_temporary_value;
  auto DV_sym_51838_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_51866_1_temporary_value;
  auto DV_sym_51866_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_51540_1__R_s_b_9_9;
  auto DV_sym_51540_1__R_s_b_9_9 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51603_1__R_s_b_24_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51628_1__R_s_b_25_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_51950_1_temporary_value;
  auto DV_sym_51950_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_51441_1_temporary_value;
  auto DV_sym_51441_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_51894_1_temporary_value;
  auto DV_sym_51894_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52063_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_52034_1_temporary_value;
  auto DV_sym_52034_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_51922_1_temporary_value;
  auto DV_sym_51922_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2497 [F] s_b_0_0=sym_5865_3_parameter_inst.sf (const) */
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
  /* b_45,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2504 [F] s_b_1_0=sym_5865_3_parameter_inst.sf (const) */
    /* execute.a64:2504 [F] s_b_1_1: If s_b_1_0: Jump b_3 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_45,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2505 [D] s_b_3_0 = sym_5882_0_result uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_5882_0_result, emitter.context().types().u64());
    /* execute.a64:2505 [D] s_b_3_1 = __builtin_update_zn_flags64 */
    emitter.set_zn(s_b_3_0);
    /* execute.a64:2505 [F] s_b_3_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_5,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2510 [F] s_b_4_0 = constant u8 0 (const) */
    /* execute.a64:2510 [F] s_b_4_1: WriteReg 3 = s_b_4_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2511 [F] s_b_4_2 = constant u8 0 (const) */
    /* execute.a64:2511 [F] s_b_4_3: WriteReg 4 = s_b_4_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2504 [F] s_b_4_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2507 [D] s_b_5_0 = sym_5882_0_result uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_5882_0_result, emitter.context().types().u64());
    /* execute.a64:2507 [D] s_b_5_1 = (u32)s_b_5_0 */
    auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().u32());
    /* execute.a64:2507 [D] s_b_5_2 = __builtin_update_zn_flags32 */
    emitter.set_zn(s_b_5_1);
    /* execute.a64:2507 [F] s_b_5_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2720 [F] s_b_6_0=sym_5865_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2714 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_6_4: If s_b_6_3: Jump b_9 else b_10 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2722 [F] s_b_7_0=sym_5865_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2709 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_7_4: If s_b_7_3: Jump b_12 else b_13 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_11, b_14,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2497 [D] s_b_8_0 = sym_51394_1__R_s_b_0_4 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_51394_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2498 [F] s_b_8_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* ???:4294967295 [D] s_b_8_2: sym_51558_1_tmp_s_b_9_0 = s_b_8_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_51558_1_tmp_s_b_9_0, s_b_8_0);
    /* execute.a64:2635 [F] s_b_8_3 = (u32)s_b_8_1 (const) */
    /* execute.a64:2635 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2635 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.imm6) == (uint32_t)0ULL));
    /* execute.a64:2635 [F] s_b_8_6: If s_b_8_5: Jump b_15 else b_16 (const) */
    if (s_b_8_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_6,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2714 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_9_1: sym_51413_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_51413_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51413_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_6,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2714 [F] s_b_10_0=sym_5865_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_10_2: sym_51413_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_51413_1_temporary_value, s_b_10_1);
    /* execute.a64:2714 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2714 [D] s_b_11_0 = sym_51413_1_temporary_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_51413_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_11_1: sym_51394_1__R_s_b_0_4 = s_b_11_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_51394_1__R_s_b_0_4, s_b_11_0);
    /* execute.a64:2720 [F] s_b_11_2: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_12_1: sym_51441_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_51441_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51441_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_7,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [F] s_b_13_0=sym_5865_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_13_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_13_2: sym_51441_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_51441_1_temporary_value, s_b_13_1);
    /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_51441_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_51441_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_14_2: sym_51394_1__R_s_b_0_4 = s_b_14_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_51394_1__R_s_b_0_4, s_b_14_1);
    /* execute.a64:2722 [F] s_b_14_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_8,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2635 [F] s_b_15_0=sym_5865_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_15_1: If s_b_15_0: Jump b_25 else b_26 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_8,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2637 [F] s_b_16_0=sym_5865_3_parameter_inst.shift (const) */
    /* execute.a64:2638 [F] s_b_16_1 = constant s32 0 (const) */
    /* execute.a64:2642 [F] s_b_16_2 = constant s32 1 (const) */
    /* execute.a64:2646 [F] s_b_16_3 = constant s32 2 (const) */
    /* execute.a64:2650 [F] s_b_16_4 = constant s32 3 (const) */
    /* execute.a64:2637 [F] s_b_16_5: Switch s_b_16_0: < <todo> > def b_17 (const) -> b_20, b_21, b_17, b_19, b_18,  */
    switch (insn.shift) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    default:
      goto fixed_block_b_17;
    }
  }
  /* b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2660 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2661 [F] s_b_17_1 = constant u64 0 (const) */
    /* execute.a64:2661 [F] s_b_17_2: sym_51540_1__R_s_b_9_9 = s_b_17_1 (const), dominates: s_b_24_1  */
    CV_sym_51540_1__R_s_b_9_9 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51540_1__R_s_b_9_9, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2661 [F] s_b_17_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2640 [F] s_b_18_0=sym_5865_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_18_1: If s_b_18_0: Jump b_28 else b_29 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_16,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2644 [F] s_b_19_0=sym_5865_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_19_1: If s_b_19_0: Jump b_31 else b_32 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_16,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2648 [F] s_b_20_0=sym_5865_3_parameter_inst.sf (const) */
    /* execute.a64:2728 [F] s_b_20_1: If s_b_20_0: Jump b_34 else b_35 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_16,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2652 [F] s_b_21_0=sym_5865_3_parameter_inst.sf (const) */
    /* execute.a64:2652 [F] s_b_21_1: If s_b_21_0: Jump b_22 else b_23 (const) */
    if (insn.sf) 
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
    /* execute.a64:2720 [F] s_b_22_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
    /* execute.a64:2714 [F] s_b_22_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_22_4: If s_b_22_3: Jump b_64 else b_65 (const) */
    if (s_b_22_3) 
    {
      goto fixed_block_b_64;
    }
    else 
    {
      goto fixed_block_b_65;
    }
  }
  /* b_21,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2722 [F] s_b_23_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2709 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_23_4: If s_b_23_3: Jump b_67 else b_68 (const) */
    if (s_b_23_3) 
    {
      goto fixed_block_b_67;
    }
    else 
    {
      goto fixed_block_b_68;
    }
  }
  /* b_17, b_27, b_30, b_33, b_42, b_66, b_69,  */
  fixed_block_b_24: 
  {
    /* ???:4294967295 [D] s_b_24_0 = sym_51558_1_tmp_s_b_9_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_51558_1_tmp_s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2498 [D] s_b_24_1 = sym_51540_1__R_s_b_9_9 uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_51540_1__R_s_b_9_9, emitter.context().types().u64());
    /* execute.a64:2500 [D] s_b_24_2 = s_b_24_0&s_b_24_1 */
    auto s_b_24_2 = emitter.bitwise_and(s_b_24_0, s_b_24_1);
    /* execute.a64:2500 [D] s_b_24_3: sym_5882_0_result = s_b_24_2, dominates: s_b_3_0 s_b_5_0  */
    emitter.store_local(DV_sym_5882_0_result, s_b_24_2);
    /* execute.a64:2501 [F] s_b_24_4=sym_5865_3_parameter_inst.sf (const) */
    /* execute.a64:2501 [D] s_b_24_5: sym_51753_3_parameter_value = s_b_24_2, dominates: s_b_43_1 s_b_44_1  */
    emitter.store_local(DV_sym_51753_3_parameter_value, s_b_24_2);
    /* execute.a64:2753 [F] s_b_24_6: If s_b_24_4: Jump b_43 else b_44 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_43;
    }
    else 
    {
      goto fixed_block_b_44;
    }
  }
  /* b_15,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2720 [F] s_b_25_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:2714 [F] s_b_25_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_25_4: If s_b_25_3: Jump b_46 else b_47 (const) */
    if (s_b_25_3) 
    {
      goto fixed_block_b_46;
    }
    else 
    {
      goto fixed_block_b_47;
    }
  }
  /* b_15,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2722 [F] s_b_26_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
    /* execute.a64:2709 [F] s_b_26_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_26_4: If s_b_26_3: Jump b_49 else b_50 (const) */
    if (s_b_26_3) 
    {
      goto fixed_block_b_49;
    }
    else 
    {
      goto fixed_block_b_50;
    }
  }
  /* b_48, b_51,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2635 [D] s_b_27_0 = sym_51578_1__R_s_b_21_4 uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_51578_1__R_s_b_21_4, emitter.context().types().u64());
    /* execute.a64:2635 [D] s_b_27_1: sym_51540_1__R_s_b_9_9 = s_b_27_0, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51540_1__R_s_b_9_9, s_b_27_0);
    /* execute.a64:2635 [F] s_b_27_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_18,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2720 [F] s_b_28_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:2714 [F] s_b_28_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_28_4: If s_b_28_3: Jump b_52 else b_53 (const) */
    if (s_b_28_3) 
    {
      goto fixed_block_b_52;
    }
    else 
    {
      goto fixed_block_b_53;
    }
  }
  /* b_18,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2722 [F] s_b_29_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
    /* execute.a64:2709 [F] s_b_29_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_29_4: If s_b_29_3: Jump b_55 else b_56 (const) */
    if (s_b_29_3) 
    {
      goto fixed_block_b_55;
    }
    else 
    {
      goto fixed_block_b_56;
    }
  }
  /* b_54, b_57,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2640 [D] s_b_30_0 = sym_51603_1__R_s_b_24_4 uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_51603_1__R_s_b_24_4, emitter.context().types().u64());
    /* execute.a64:2640 [F] s_b_30_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2640 [F] s_b_30_2 = (u64)s_b_30_1 (const) */
    /* execute.a64:2640 [D] s_b_30_3 = s_b_30_0<<s_b_30_2 */
    auto s_b_30_3 = emitter.shl(s_b_30_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2640 [D] s_b_30_4: sym_51540_1__R_s_b_9_9 = s_b_30_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51540_1__R_s_b_9_9, s_b_30_3);
    /* execute.a64:2640 [F] s_b_30_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2720 [F] s_b_31_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
    /* execute.a64:2714 [F] s_b_31_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_31_3 = s_b_31_1==s_b_31_2 (const) */
    uint8_t s_b_31_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_31_4: If s_b_31_3: Jump b_58 else b_59 (const) */
    if (s_b_31_3) 
    {
      goto fixed_block_b_58;
    }
    else 
    {
      goto fixed_block_b_59;
    }
  }
  /* b_19,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2722 [F] s_b_32_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_32_1 = (u32)s_b_32_0 (const) */
    /* execute.a64:2709 [F] s_b_32_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_32_3 = s_b_32_1==s_b_32_2 (const) */
    uint8_t s_b_32_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_32_4: If s_b_32_3: Jump b_61 else b_62 (const) */
    if (s_b_32_3) 
    {
      goto fixed_block_b_61;
    }
    else 
    {
      goto fixed_block_b_62;
    }
  }
  /* b_60, b_63,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2644 [D] s_b_33_0 = sym_51628_1__R_s_b_25_4 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_51628_1__R_s_b_25_4, emitter.context().types().u64());
    /* execute.a64:2644 [F] s_b_33_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2644 [F] s_b_33_2 = (u64)s_b_33_1 (const) */
    /* execute.a64:2644 [D] s_b_33_3 = s_b_33_0>>s_b_33_2 */
    auto s_b_33_3 = emitter.shr(s_b_33_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2644 [D] s_b_33_4: sym_51540_1__R_s_b_9_9 = s_b_33_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51540_1__R_s_b_9_9, s_b_33_3);
    /* execute.a64:2644 [F] s_b_33_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_20,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2729 [F] s_b_34_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2729 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
    /* execute.a64:2729 [F] s_b_34_2 = constant u32 1f (const) */
    /* execute.a64:2729 [F] s_b_34_3 = s_b_34_1==s_b_34_2 (const) */
    uint8_t s_b_34_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2729 [F] s_b_34_4: If s_b_34_3: Jump b_36 else b_37 (const) */
    if (s_b_34_3) 
    {
      goto fixed_block_b_36;
    }
    else 
    {
      goto fixed_block_b_37;
    }
  }
  /* b_20,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2731 [F] s_b_35_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2731 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
    /* execute.a64:2731 [F] s_b_35_2 = constant u32 1f (const) */
    /* execute.a64:2731 [F] s_b_35_3 = s_b_35_1==s_b_35_2 (const) */
    uint8_t s_b_35_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2731 [F] s_b_35_4: If s_b_35_3: Jump b_38 else b_39 (const) */
    if (s_b_35_3) 
    {
      goto fixed_block_b_38;
    }
    else 
    {
      goto fixed_block_b_39;
    }
  }
  /* b_34,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2729 [F] s_b_36_0 = constant s64 0 (const) */
    /* execute.a64:2729 [F] s_b_36_1: sym_51661_1_temporary_value = s_b_36_0 (const), dominates: s_b_40_0  */
    CV_sym_51661_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_51661_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2729 [F] s_b_36_2: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_34,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2729 [F] s_b_37_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2729 [D] s_b_37_1 = ReadRegBank 0:s_b_37_0 (u64) */
    auto s_b_37_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_37_1,emitter.const_u8(8));
    }
    /* execute.a64:2729 [D] s_b_37_2 = (s64)s_b_37_1 */
    auto s_b_37_2 = emitter.reinterpret(s_b_37_1, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_37_3: sym_51661_1_temporary_value = s_b_37_2, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_51661_1_temporary_value, s_b_37_2);
    /* execute.a64:2729 [F] s_b_37_4: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_35,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2731 [F] s_b_38_0 = constant s64 0 (const) */
    /* execute.a64:2731 [F] s_b_38_1: sym_51673_1_temporary_value = s_b_38_0 (const), dominates: s_b_41_0  */
    CV_sym_51673_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_51673_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2731 [F] s_b_38_2: Jump b_41 (const) */
    goto fixed_block_b_41;
  }
  /* b_35,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2731 [F] s_b_39_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2731 [D] s_b_39_1 = ReadRegBank 1:s_b_39_0 (u32) */
    auto s_b_39_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_39_1,emitter.const_u8(4));
    }
    /* execute.a64:2731 [D] s_b_39_2 = (s32)s_b_39_1 */
    auto s_b_39_2 = emitter.reinterpret(s_b_39_1, emitter.context().types().s32());
    /* execute.a64:2731 [D] s_b_39_3 = (s64)s_b_39_2 */
    auto s_b_39_3 = emitter.sx(s_b_39_2, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_39_4: sym_51673_1_temporary_value = s_b_39_3, dominates: s_b_41_0  */
    emitter.store_local(DV_sym_51673_1_temporary_value, s_b_39_3);
    /* execute.a64:2731 [F] s_b_39_5: Jump b_41 (const) */
    goto fixed_block_b_41;
  }
  /* b_36, b_37,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2729 [D] s_b_40_0 = sym_51661_1_temporary_value int64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_51661_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_40_1: sym_51687_1__R_s_b_26_4 = s_b_40_0, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_51687_1__R_s_b_26_4, s_b_40_0);
    /* execute.a64:2729 [F] s_b_40_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_38, b_39,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2731 [D] s_b_41_0 = sym_51673_1_temporary_value int64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_51673_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_41_1: sym_51687_1__R_s_b_26_4 = s_b_41_0, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_51687_1__R_s_b_26_4, s_b_41_0);
    /* execute.a64:2731 [F] s_b_41_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_40, b_41,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2648 [D] s_b_42_0 = sym_51687_1__R_s_b_26_4 int64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_51687_1__R_s_b_26_4, emitter.context().types().s64());
    /* execute.a64:2648 [F] s_b_42_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2648 [D] s_b_42_2 = (u64)s_b_42_0 */
    auto s_b_42_2 = emitter.reinterpret(s_b_42_0, emitter.context().types().u64());
    /* execute.a64:2648 [F] s_b_42_3 = (u64)s_b_42_1 (const) */
    /* execute.a64:2648 [D] s_b_42_4 = s_b_42_2->>s_b_42_3 */
    auto s_b_42_4 = emitter.sar(s_b_42_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2648 [D] s_b_42_5 = (u64)s_b_42_4 */
    auto s_b_42_5 = (captive::arch::dbt::el::Value *)s_b_42_4;
    /* execute.a64:2648 [D] s_b_42_6: sym_51540_1__R_s_b_9_9 = s_b_42_5, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51540_1__R_s_b_9_9, s_b_42_5);
    /* execute.a64:2648 [F] s_b_42_7: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_24,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2754 [F] s_b_43_0=sym_5865_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_43_1 = sym_51753_3_parameter_value uint64_t */
    auto s_b_43_1 = emitter.load_local(DV_sym_51753_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_43_2: sym_52063_3_parameter_value = s_b_43_1, dominates: s_b_70_1  */
    emitter.store_local(DV_sym_52063_3_parameter_value, s_b_43_1);
    /* execute.a64:2745 [F] s_b_43_3 = (u32)s_b_43_0 (const) */
    /* execute.a64:2745 [F] s_b_43_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_43_5 = s_b_43_3==s_b_43_4 (const) */
    uint8_t s_b_43_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_43_6: If s_b_43_5: Jump b_45 else b_70 (const) */
    if (s_b_43_5) 
    {
      goto fixed_block_b_45;
    }
    else 
    {
      goto fixed_block_b_70;
    }
  }
  /* b_24,  */
  fixed_block_b_44: 
  {
    /* execute.a64:2756 [F] s_b_44_0=sym_5865_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_44_1 = sym_51753_3_parameter_value uint64_t */
    auto s_b_44_1 = emitter.load_local(DV_sym_51753_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_44_2 = (u32)s_b_44_1 */
    auto s_b_44_2 = emitter.truncate(s_b_44_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_44_3 = (u64)s_b_44_2 */
    auto s_b_44_3 = emitter.zx(s_b_44_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_44_4: sym_52085_3_parameter_value = s_b_44_3, dominates: s_b_71_1  */
    emitter.store_local(DV_sym_52085_3_parameter_value, s_b_44_3);
    /* execute.a64:2745 [F] s_b_44_5 = (u32)s_b_44_0 (const) */
    /* execute.a64:2745 [F] s_b_44_6 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_44_7 = s_b_44_5==s_b_44_6 (const) */
    uint8_t s_b_44_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_44_8: If s_b_44_7: Jump b_45 else b_71 (const) */
    if (s_b_44_7) 
    {
      goto fixed_block_b_45;
    }
    else 
    {
      goto fixed_block_b_71;
    }
  }
  /* b_43, b_44, b_70, b_71,  */
  fixed_block_b_45: 
  {
    /* execute.a64:2503 [F] s_b_45_0=sym_5865_3_parameter_inst.opc (const) */
    /* execute.a64:2503 [F] s_b_45_1 = (u32)s_b_45_0 (const) */
    /* execute.a64:2503 [F] s_b_45_2 = constant u32 3 (const) */
    /* execute.a64:2503 [F] s_b_45_3 = s_b_45_1==s_b_45_2 (const) */
    uint8_t s_b_45_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:2503 [F] s_b_45_4: If s_b_45_3: Jump b_1 else b_2 (const) */
    if (s_b_45_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_25,  */
  fixed_block_b_46: 
  {
    /* execute.a64:2714 [F] s_b_46_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_46_1: sym_51782_1_temporary_value = s_b_46_0 (const), dominates: s_b_48_0  */
    CV_sym_51782_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51782_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_46_2: Jump b_48 (const) */
    goto fixed_block_b_48;
  }
  /* b_25,  */
  fixed_block_b_47: 
  {
    /* execute.a64:2714 [F] s_b_47_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_47_1 = ReadRegBank 0:s_b_47_0 (u64) */
    auto s_b_47_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_47_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_47_2: sym_51782_1_temporary_value = s_b_47_1, dominates: s_b_48_0  */
    emitter.store_local(DV_sym_51782_1_temporary_value, s_b_47_1);
    /* execute.a64:2714 [F] s_b_47_3: Jump b_48 (const) */
    goto fixed_block_b_48;
  }
  /* b_46, b_47,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2714 [D] s_b_48_0 = sym_51782_1_temporary_value uint64_t */
    auto s_b_48_0 = emitter.load_local(DV_sym_51782_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_48_1: sym_51578_1__R_s_b_21_4 = s_b_48_0, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_51578_1__R_s_b_21_4, s_b_48_0);
    /* execute.a64:2720 [F] s_b_48_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_26,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2709 [F] s_b_49_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_49_1: sym_51810_1_temporary_value = s_b_49_0 (const), dominates: s_b_51_0  */
    CV_sym_51810_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51810_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_49_2: Jump b_51 (const) */
    goto fixed_block_b_51;
  }
  /* b_26,  */
  fixed_block_b_50: 
  {
    /* execute.a64:2709 [F] s_b_50_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_50_1 = ReadRegBank 1:s_b_50_0 (u32) */
    auto s_b_50_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_50_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_50_2: sym_51810_1_temporary_value = s_b_50_1, dominates: s_b_51_0  */
    emitter.store_local(DV_sym_51810_1_temporary_value, s_b_50_1);
    /* execute.a64:2709 [F] s_b_50_3: Jump b_51 (const) */
    goto fixed_block_b_51;
  }
  /* b_49, b_50,  */
  fixed_block_b_51: 
  {
    /* execute.a64:2709 [D] s_b_51_0 = sym_51810_1_temporary_value uint32_t */
    auto s_b_51_0 = emitter.load_local(DV_sym_51810_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_51_1 = (u64)s_b_51_0 */
    auto s_b_51_1 = emitter.zx(s_b_51_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_51_2: sym_51578_1__R_s_b_21_4 = s_b_51_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_51578_1__R_s_b_21_4, s_b_51_1);
    /* execute.a64:2722 [F] s_b_51_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_28,  */
  fixed_block_b_52: 
  {
    /* execute.a64:2714 [F] s_b_52_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_52_1: sym_51838_1_temporary_value = s_b_52_0 (const), dominates: s_b_54_0  */
    CV_sym_51838_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51838_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_52_2: Jump b_54 (const) */
    goto fixed_block_b_54;
  }
  /* b_28,  */
  fixed_block_b_53: 
  {
    /* execute.a64:2714 [F] s_b_53_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_53_1 = ReadRegBank 0:s_b_53_0 (u64) */
    auto s_b_53_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_53_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_53_2: sym_51838_1_temporary_value = s_b_53_1, dominates: s_b_54_0  */
    emitter.store_local(DV_sym_51838_1_temporary_value, s_b_53_1);
    /* execute.a64:2714 [F] s_b_53_3: Jump b_54 (const) */
    goto fixed_block_b_54;
  }
  /* b_52, b_53,  */
  fixed_block_b_54: 
  {
    /* execute.a64:2714 [D] s_b_54_0 = sym_51838_1_temporary_value uint64_t */
    auto s_b_54_0 = emitter.load_local(DV_sym_51838_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_54_1: sym_51603_1__R_s_b_24_4 = s_b_54_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_51603_1__R_s_b_24_4, s_b_54_0);
    /* execute.a64:2720 [F] s_b_54_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_29,  */
  fixed_block_b_55: 
  {
    /* execute.a64:2709 [F] s_b_55_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_55_1: sym_51866_1_temporary_value = s_b_55_0 (const), dominates: s_b_57_0  */
    CV_sym_51866_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51866_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_55_2: Jump b_57 (const) */
    goto fixed_block_b_57;
  }
  /* b_29,  */
  fixed_block_b_56: 
  {
    /* execute.a64:2709 [F] s_b_56_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_56_1 = ReadRegBank 1:s_b_56_0 (u32) */
    auto s_b_56_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_56_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_56_2: sym_51866_1_temporary_value = s_b_56_1, dominates: s_b_57_0  */
    emitter.store_local(DV_sym_51866_1_temporary_value, s_b_56_1);
    /* execute.a64:2709 [F] s_b_56_3: Jump b_57 (const) */
    goto fixed_block_b_57;
  }
  /* b_55, b_56,  */
  fixed_block_b_57: 
  {
    /* execute.a64:2709 [D] s_b_57_0 = sym_51866_1_temporary_value uint32_t */
    auto s_b_57_0 = emitter.load_local(DV_sym_51866_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_57_1 = (u64)s_b_57_0 */
    auto s_b_57_1 = emitter.zx(s_b_57_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_57_2: sym_51603_1__R_s_b_24_4 = s_b_57_1, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_51603_1__R_s_b_24_4, s_b_57_1);
    /* execute.a64:2722 [F] s_b_57_3: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_31,  */
  fixed_block_b_58: 
  {
    /* execute.a64:2714 [F] s_b_58_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_58_1: sym_51894_1_temporary_value = s_b_58_0 (const), dominates: s_b_60_0  */
    CV_sym_51894_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51894_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_58_2: Jump b_60 (const) */
    goto fixed_block_b_60;
  }
  /* b_31,  */
  fixed_block_b_59: 
  {
    /* execute.a64:2714 [F] s_b_59_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_59_1 = ReadRegBank 0:s_b_59_0 (u64) */
    auto s_b_59_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_59_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_59_2: sym_51894_1_temporary_value = s_b_59_1, dominates: s_b_60_0  */
    emitter.store_local(DV_sym_51894_1_temporary_value, s_b_59_1);
    /* execute.a64:2714 [F] s_b_59_3: Jump b_60 (const) */
    goto fixed_block_b_60;
  }
  /* b_58, b_59,  */
  fixed_block_b_60: 
  {
    /* execute.a64:2714 [D] s_b_60_0 = sym_51894_1_temporary_value uint64_t */
    auto s_b_60_0 = emitter.load_local(DV_sym_51894_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_60_1: sym_51628_1__R_s_b_25_4 = s_b_60_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_51628_1__R_s_b_25_4, s_b_60_0);
    /* execute.a64:2720 [F] s_b_60_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_32,  */
  fixed_block_b_61: 
  {
    /* execute.a64:2709 [F] s_b_61_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_61_1: sym_51922_1_temporary_value = s_b_61_0 (const), dominates: s_b_63_0  */
    CV_sym_51922_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51922_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_61_2: Jump b_63 (const) */
    goto fixed_block_b_63;
  }
  /* b_32,  */
  fixed_block_b_62: 
  {
    /* execute.a64:2709 [F] s_b_62_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_62_1 = ReadRegBank 1:s_b_62_0 (u32) */
    auto s_b_62_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_62_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_62_2: sym_51922_1_temporary_value = s_b_62_1, dominates: s_b_63_0  */
    emitter.store_local(DV_sym_51922_1_temporary_value, s_b_62_1);
    /* execute.a64:2709 [F] s_b_62_3: Jump b_63 (const) */
    goto fixed_block_b_63;
  }
  /* b_61, b_62,  */
  fixed_block_b_63: 
  {
    /* execute.a64:2709 [D] s_b_63_0 = sym_51922_1_temporary_value uint32_t */
    auto s_b_63_0 = emitter.load_local(DV_sym_51922_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_63_1 = (u64)s_b_63_0 */
    auto s_b_63_1 = emitter.zx(s_b_63_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_63_2: sym_51628_1__R_s_b_25_4 = s_b_63_1, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_51628_1__R_s_b_25_4, s_b_63_1);
    /* execute.a64:2722 [F] s_b_63_3: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_22,  */
  fixed_block_b_64: 
  {
    /* execute.a64:2714 [F] s_b_64_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_64_1: sym_51950_1_temporary_value = s_b_64_0 (const), dominates: s_b_66_0  */
    CV_sym_51950_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51950_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_64_2: Jump b_66 (const) */
    goto fixed_block_b_66;
  }
  /* b_22,  */
  fixed_block_b_65: 
  {
    /* execute.a64:2714 [F] s_b_65_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_65_1 = ReadRegBank 0:s_b_65_0 (u64) */
    auto s_b_65_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_65_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_65_2: sym_51950_1_temporary_value = s_b_65_1, dominates: s_b_66_0  */
    emitter.store_local(DV_sym_51950_1_temporary_value, s_b_65_1);
    /* execute.a64:2714 [F] s_b_65_3: Jump b_66 (const) */
    goto fixed_block_b_66;
  }
  /* b_64, b_65,  */
  fixed_block_b_66: 
  {
    /* execute.a64:2714 [D] s_b_66_0 = sym_51950_1_temporary_value uint64_t */
    auto s_b_66_0 = emitter.load_local(DV_sym_51950_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2653 [F] s_b_66_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2653 [F] s_b_66_2 = (u64)s_b_66_1 (const) */
    /* execute.a64:2653 [D] s_b_66_3 = s_b_66_0>>>s_b_66_2 */
    auto s_b_66_3 = emitter.ror(s_b_66_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2653 [D] s_b_66_4: sym_51540_1__R_s_b_9_9 = s_b_66_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51540_1__R_s_b_9_9, s_b_66_3);
    /* execute.a64:2653 [F] s_b_66_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_67: 
  {
    /* execute.a64:2709 [F] s_b_67_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_67_1: sym_52034_1_temporary_value = s_b_67_0 (const), dominates: s_b_69_0  */
    CV_sym_52034_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_52034_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_67_2: Jump b_69 (const) */
    goto fixed_block_b_69;
  }
  /* b_23,  */
  fixed_block_b_68: 
  {
    /* execute.a64:2709 [F] s_b_68_0=sym_5865_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_68_1 = ReadRegBank 1:s_b_68_0 (u32) */
    auto s_b_68_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_68_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_68_2: sym_52034_1_temporary_value = s_b_68_1, dominates: s_b_69_0  */
    emitter.store_local(DV_sym_52034_1_temporary_value, s_b_68_1);
    /* execute.a64:2709 [F] s_b_68_3: Jump b_69 (const) */
    goto fixed_block_b_69;
  }
  /* b_67, b_68,  */
  fixed_block_b_69: 
  {
    /* execute.a64:2709 [D] s_b_69_0 = sym_52034_1_temporary_value uint32_t */
    auto s_b_69_0 = emitter.load_local(DV_sym_52034_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_69_1 = (u64)s_b_69_0 */
    auto s_b_69_1 = emitter.zx(s_b_69_0, emitter.context().types().u64());
    /* execute.a64:2655 [D] s_b_69_2 = (u32)s_b_69_1 */
    auto s_b_69_2 = emitter.truncate(s_b_69_1, emitter.context().types().u32());
    /* execute.a64:2655 [F] s_b_69_3=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2655 [F] s_b_69_4 = (u32)s_b_69_3 (const) */
    /* execute.a64:2655 [D] s_b_69_5 = s_b_69_2>>>s_b_69_4 */
    auto s_b_69_5 = emitter.ror(s_b_69_2, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2655 [D] s_b_69_6 = (u64)s_b_69_5 */
    auto s_b_69_6 = emitter.zx(s_b_69_5, emitter.context().types().u64());
    /* execute.a64:2655 [D] s_b_69_7: sym_51540_1__R_s_b_9_9 = s_b_69_6, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51540_1__R_s_b_9_9, s_b_69_6);
    /* execute.a64:2655 [F] s_b_69_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_43,  */
  fixed_block_b_70: 
  {
    /* execute.a64:2747 [F] s_b_70_0=sym_5865_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_70_1 = sym_52063_3_parameter_value uint64_t */
    auto s_b_70_1 = emitter.load_local(DV_sym_52063_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_70_2: WriteRegBank 0:s_b_70_0 = s_b_70_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_70_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_70_1);
    /* execute.a64:0 [F] s_b_70_3: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_44,  */
  fixed_block_b_71: 
  {
    /* execute.a64:2747 [F] s_b_71_0=sym_5865_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_71_1 = sym_52085_3_parameter_value uint64_t */
    auto s_b_71_1 = emitter.load_local(DV_sym_52085_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_71_2: WriteRegBank 0:s_b_71_0 = s_b_71_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_71_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_71_1);
    /* execute.a64:0 [F] s_b_71_3: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_bicsr(const arm64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_53598_1_temporary_value;
  auto DV_sym_53598_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_53626_1_temporary_value;
  auto DV_sym_53626_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53541_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_53201_1_temporary_value;
  auto DV_sym_53201_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53475_1__R_s_b_26_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_53449_1_temporary_value;
  auto DV_sym_53449_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  uint64_t CV_sym_53682_1_temporary_value;
  auto DV_sym_53682_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53873_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_53710_1_temporary_value;
  auto DV_sym_53710_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_53182_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_53738_1_temporary_value;
  auto DV_sym_53738_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_53461_1_temporary_value;
  auto DV_sym_53461_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  uint32_t CV_sym_53229_1_temporary_value;
  auto DV_sym_53229_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_53570_1_temporary_value;
  auto DV_sym_53570_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53391_1__R_s_b_24_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_53654_1_temporary_value;
  auto DV_sym_53654_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_53328_1__R_s_b_9_9;
  auto DV_sym_53328_1__R_s_b_9_9 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53851_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53416_1__R_s_b_25_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_53822_1_temporary_value;
  auto DV_sym_53822_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_6266_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53366_1__R_s_b_21_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53346_1_tmp_s_b_9_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2517 [F] s_b_0_0=sym_6248_3_parameter_inst.sf (const) */
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
  /* b_45,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2524 [F] s_b_1_0=sym_6248_3_parameter_inst.sf (const) */
    /* execute.a64:2524 [F] s_b_1_1: If s_b_1_0: Jump b_3 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_45,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2525 [D] s_b_3_0 = sym_6266_0_result uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_6266_0_result, emitter.context().types().u64());
    /* execute.a64:2525 [D] s_b_3_1 = __builtin_update_zn_flags64 */
    emitter.set_zn(s_b_3_0);
    /* execute.a64:2525 [F] s_b_3_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_5,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2530 [F] s_b_4_0 = constant u8 0 (const) */
    /* execute.a64:2530 [F] s_b_4_1: WriteReg 3 = s_b_4_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2531 [F] s_b_4_2 = constant u8 0 (const) */
    /* execute.a64:2531 [F] s_b_4_3: WriteReg 4 = s_b_4_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2524 [F] s_b_4_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2527 [D] s_b_5_0 = sym_6266_0_result uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_6266_0_result, emitter.context().types().u64());
    /* execute.a64:2527 [D] s_b_5_1 = (u32)s_b_5_0 */
    auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().u32());
    /* execute.a64:2527 [D] s_b_5_2 = __builtin_update_zn_flags32 */
    emitter.set_zn(s_b_5_1);
    /* execute.a64:2527 [F] s_b_5_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2720 [F] s_b_6_0=sym_6248_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2714 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_6_4: If s_b_6_3: Jump b_9 else b_10 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2722 [F] s_b_7_0=sym_6248_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2709 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_7_4: If s_b_7_3: Jump b_12 else b_13 (const) */
    if (s_b_7_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_11, b_14,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2517 [D] s_b_8_0 = sym_53182_1__R_s_b_0_4 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_53182_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2518 [F] s_b_8_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* ???:4294967295 [D] s_b_8_2: sym_53346_1_tmp_s_b_9_0 = s_b_8_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_53346_1_tmp_s_b_9_0, s_b_8_0);
    /* execute.a64:2635 [F] s_b_8_3 = (u32)s_b_8_1 (const) */
    /* execute.a64:2635 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2635 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.imm6) == (uint32_t)0ULL));
    /* execute.a64:2635 [F] s_b_8_6: If s_b_8_5: Jump b_15 else b_16 (const) */
    if (s_b_8_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_6,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2714 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_9_1: sym_53201_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_53201_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53201_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_6,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2714 [F] s_b_10_0=sym_6248_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_10_2: sym_53201_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_53201_1_temporary_value, s_b_10_1);
    /* execute.a64:2714 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2714 [D] s_b_11_0 = sym_53201_1_temporary_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_53201_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_11_1: sym_53182_1__R_s_b_0_4 = s_b_11_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_53182_1__R_s_b_0_4, s_b_11_0);
    /* execute.a64:2720 [F] s_b_11_2: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_12_1: sym_53229_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_53229_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53229_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_7,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [F] s_b_13_0=sym_6248_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_13_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_13_2: sym_53229_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_53229_1_temporary_value, s_b_13_1);
    /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_53229_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_53229_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_14_2: sym_53182_1__R_s_b_0_4 = s_b_14_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_53182_1__R_s_b_0_4, s_b_14_1);
    /* execute.a64:2722 [F] s_b_14_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_8,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2635 [F] s_b_15_0=sym_6248_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_15_1: If s_b_15_0: Jump b_25 else b_26 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_8,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2637 [F] s_b_16_0=sym_6248_3_parameter_inst.shift (const) */
    /* execute.a64:2638 [F] s_b_16_1 = constant s32 0 (const) */
    /* execute.a64:2642 [F] s_b_16_2 = constant s32 1 (const) */
    /* execute.a64:2646 [F] s_b_16_3 = constant s32 2 (const) */
    /* execute.a64:2650 [F] s_b_16_4 = constant s32 3 (const) */
    /* execute.a64:2637 [F] s_b_16_5: Switch s_b_16_0: < <todo> > def b_17 (const) -> b_18, b_17, b_20, b_19, b_21,  */
    switch (insn.shift) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_21;
      break;
    default:
      goto fixed_block_b_17;
    }
  }
  /* b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2660 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2661 [F] s_b_17_1 = constant u64 0 (const) */
    /* execute.a64:2661 [F] s_b_17_2: sym_53328_1__R_s_b_9_9 = s_b_17_1 (const), dominates: s_b_24_1  */
    CV_sym_53328_1__R_s_b_9_9 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53328_1__R_s_b_9_9, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2661 [F] s_b_17_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2640 [F] s_b_18_0=sym_6248_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_18_1: If s_b_18_0: Jump b_28 else b_29 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_16,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2644 [F] s_b_19_0=sym_6248_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_19_1: If s_b_19_0: Jump b_31 else b_32 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_16,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2648 [F] s_b_20_0=sym_6248_3_parameter_inst.sf (const) */
    /* execute.a64:2728 [F] s_b_20_1: If s_b_20_0: Jump b_34 else b_35 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_16,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2652 [F] s_b_21_0=sym_6248_3_parameter_inst.sf (const) */
    /* execute.a64:2652 [F] s_b_21_1: If s_b_21_0: Jump b_22 else b_23 (const) */
    if (insn.sf) 
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
    /* execute.a64:2720 [F] s_b_22_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
    /* execute.a64:2714 [F] s_b_22_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_22_4: If s_b_22_3: Jump b_64 else b_65 (const) */
    if (s_b_22_3) 
    {
      goto fixed_block_b_64;
    }
    else 
    {
      goto fixed_block_b_65;
    }
  }
  /* b_21,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2722 [F] s_b_23_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2709 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_23_4: If s_b_23_3: Jump b_67 else b_68 (const) */
    if (s_b_23_3) 
    {
      goto fixed_block_b_67;
    }
    else 
    {
      goto fixed_block_b_68;
    }
  }
  /* b_17, b_27, b_30, b_33, b_42, b_66, b_69,  */
  fixed_block_b_24: 
  {
    /* ???:4294967295 [D] s_b_24_0 = sym_53346_1_tmp_s_b_9_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_53346_1_tmp_s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2518 [D] s_b_24_1 = sym_53328_1__R_s_b_9_9 uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_53328_1__R_s_b_9_9, emitter.context().types().u64());
    /* execute.a64:2520 [D] s_b_24_2 = ~s_b_24_1 */
    auto s_b_24_2 = emitter.bitwise_not(s_b_24_1);
    /* execute.a64:2520 [D] s_b_24_3 = s_b_24_0&s_b_24_2 */
    auto s_b_24_3 = emitter.bitwise_and(s_b_24_0, s_b_24_2);
    /* execute.a64:2520 [D] s_b_24_4: sym_6266_0_result = s_b_24_3, dominates: s_b_3_0 s_b_5_0  */
    emitter.store_local(DV_sym_6266_0_result, s_b_24_3);
    /* execute.a64:2521 [F] s_b_24_5=sym_6248_3_parameter_inst.sf (const) */
    /* execute.a64:2521 [D] s_b_24_6: sym_53541_3_parameter_value = s_b_24_3, dominates: s_b_43_1 s_b_44_1  */
    emitter.store_local(DV_sym_53541_3_parameter_value, s_b_24_3);
    /* execute.a64:2753 [F] s_b_24_7: If s_b_24_5: Jump b_43 else b_44 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_43;
    }
    else 
    {
      goto fixed_block_b_44;
    }
  }
  /* b_15,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2720 [F] s_b_25_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:2714 [F] s_b_25_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_25_4: If s_b_25_3: Jump b_46 else b_47 (const) */
    if (s_b_25_3) 
    {
      goto fixed_block_b_46;
    }
    else 
    {
      goto fixed_block_b_47;
    }
  }
  /* b_15,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2722 [F] s_b_26_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
    /* execute.a64:2709 [F] s_b_26_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_26_4: If s_b_26_3: Jump b_49 else b_50 (const) */
    if (s_b_26_3) 
    {
      goto fixed_block_b_49;
    }
    else 
    {
      goto fixed_block_b_50;
    }
  }
  /* b_48, b_51,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2635 [D] s_b_27_0 = sym_53366_1__R_s_b_21_4 uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_53366_1__R_s_b_21_4, emitter.context().types().u64());
    /* execute.a64:2635 [D] s_b_27_1: sym_53328_1__R_s_b_9_9 = s_b_27_0, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53328_1__R_s_b_9_9, s_b_27_0);
    /* execute.a64:2635 [F] s_b_27_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_18,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2720 [F] s_b_28_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:2714 [F] s_b_28_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_28_4: If s_b_28_3: Jump b_52 else b_53 (const) */
    if (s_b_28_3) 
    {
      goto fixed_block_b_52;
    }
    else 
    {
      goto fixed_block_b_53;
    }
  }
  /* b_18,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2722 [F] s_b_29_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
    /* execute.a64:2709 [F] s_b_29_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_29_4: If s_b_29_3: Jump b_55 else b_56 (const) */
    if (s_b_29_3) 
    {
      goto fixed_block_b_55;
    }
    else 
    {
      goto fixed_block_b_56;
    }
  }
  /* b_54, b_57,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2640 [D] s_b_30_0 = sym_53391_1__R_s_b_24_4 uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_53391_1__R_s_b_24_4, emitter.context().types().u64());
    /* execute.a64:2640 [F] s_b_30_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2640 [F] s_b_30_2 = (u64)s_b_30_1 (const) */
    /* execute.a64:2640 [D] s_b_30_3 = s_b_30_0<<s_b_30_2 */
    auto s_b_30_3 = emitter.shl(s_b_30_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2640 [D] s_b_30_4: sym_53328_1__R_s_b_9_9 = s_b_30_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53328_1__R_s_b_9_9, s_b_30_3);
    /* execute.a64:2640 [F] s_b_30_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2720 [F] s_b_31_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
    /* execute.a64:2714 [F] s_b_31_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_31_3 = s_b_31_1==s_b_31_2 (const) */
    uint8_t s_b_31_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_31_4: If s_b_31_3: Jump b_58 else b_59 (const) */
    if (s_b_31_3) 
    {
      goto fixed_block_b_58;
    }
    else 
    {
      goto fixed_block_b_59;
    }
  }
  /* b_19,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2722 [F] s_b_32_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_32_1 = (u32)s_b_32_0 (const) */
    /* execute.a64:2709 [F] s_b_32_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_32_3 = s_b_32_1==s_b_32_2 (const) */
    uint8_t s_b_32_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_32_4: If s_b_32_3: Jump b_61 else b_62 (const) */
    if (s_b_32_3) 
    {
      goto fixed_block_b_61;
    }
    else 
    {
      goto fixed_block_b_62;
    }
  }
  /* b_60, b_63,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2644 [D] s_b_33_0 = sym_53416_1__R_s_b_25_4 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_53416_1__R_s_b_25_4, emitter.context().types().u64());
    /* execute.a64:2644 [F] s_b_33_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2644 [F] s_b_33_2 = (u64)s_b_33_1 (const) */
    /* execute.a64:2644 [D] s_b_33_3 = s_b_33_0>>s_b_33_2 */
    auto s_b_33_3 = emitter.shr(s_b_33_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2644 [D] s_b_33_4: sym_53328_1__R_s_b_9_9 = s_b_33_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53328_1__R_s_b_9_9, s_b_33_3);
    /* execute.a64:2644 [F] s_b_33_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_20,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2729 [F] s_b_34_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2729 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
    /* execute.a64:2729 [F] s_b_34_2 = constant u32 1f (const) */
    /* execute.a64:2729 [F] s_b_34_3 = s_b_34_1==s_b_34_2 (const) */
    uint8_t s_b_34_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2729 [F] s_b_34_4: If s_b_34_3: Jump b_36 else b_37 (const) */
    if (s_b_34_3) 
    {
      goto fixed_block_b_36;
    }
    else 
    {
      goto fixed_block_b_37;
    }
  }
  /* b_20,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2731 [F] s_b_35_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2731 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
    /* execute.a64:2731 [F] s_b_35_2 = constant u32 1f (const) */
    /* execute.a64:2731 [F] s_b_35_3 = s_b_35_1==s_b_35_2 (const) */
    uint8_t s_b_35_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2731 [F] s_b_35_4: If s_b_35_3: Jump b_38 else b_39 (const) */
    if (s_b_35_3) 
    {
      goto fixed_block_b_38;
    }
    else 
    {
      goto fixed_block_b_39;
    }
  }
  /* b_34,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2729 [F] s_b_36_0 = constant s64 0 (const) */
    /* execute.a64:2729 [F] s_b_36_1: sym_53449_1_temporary_value = s_b_36_0 (const), dominates: s_b_40_0  */
    CV_sym_53449_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_53449_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2729 [F] s_b_36_2: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_34,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2729 [F] s_b_37_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2729 [D] s_b_37_1 = ReadRegBank 0:s_b_37_0 (u64) */
    auto s_b_37_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_37_1,emitter.const_u8(8));
    }
    /* execute.a64:2729 [D] s_b_37_2 = (s64)s_b_37_1 */
    auto s_b_37_2 = emitter.reinterpret(s_b_37_1, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_37_3: sym_53449_1_temporary_value = s_b_37_2, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_53449_1_temporary_value, s_b_37_2);
    /* execute.a64:2729 [F] s_b_37_4: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_35,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2731 [F] s_b_38_0 = constant s64 0 (const) */
    /* execute.a64:2731 [F] s_b_38_1: sym_53461_1_temporary_value = s_b_38_0 (const), dominates: s_b_41_0  */
    CV_sym_53461_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_53461_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2731 [F] s_b_38_2: Jump b_41 (const) */
    goto fixed_block_b_41;
  }
  /* b_35,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2731 [F] s_b_39_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2731 [D] s_b_39_1 = ReadRegBank 1:s_b_39_0 (u32) */
    auto s_b_39_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_39_1,emitter.const_u8(4));
    }
    /* execute.a64:2731 [D] s_b_39_2 = (s32)s_b_39_1 */
    auto s_b_39_2 = emitter.reinterpret(s_b_39_1, emitter.context().types().s32());
    /* execute.a64:2731 [D] s_b_39_3 = (s64)s_b_39_2 */
    auto s_b_39_3 = emitter.sx(s_b_39_2, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_39_4: sym_53461_1_temporary_value = s_b_39_3, dominates: s_b_41_0  */
    emitter.store_local(DV_sym_53461_1_temporary_value, s_b_39_3);
    /* execute.a64:2731 [F] s_b_39_5: Jump b_41 (const) */
    goto fixed_block_b_41;
  }
  /* b_36, b_37,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2729 [D] s_b_40_0 = sym_53449_1_temporary_value int64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_53449_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_40_1: sym_53475_1__R_s_b_26_4 = s_b_40_0, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_53475_1__R_s_b_26_4, s_b_40_0);
    /* execute.a64:2729 [F] s_b_40_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_38, b_39,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2731 [D] s_b_41_0 = sym_53461_1_temporary_value int64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_53461_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_41_1: sym_53475_1__R_s_b_26_4 = s_b_41_0, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_53475_1__R_s_b_26_4, s_b_41_0);
    /* execute.a64:2731 [F] s_b_41_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_40, b_41,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2648 [D] s_b_42_0 = sym_53475_1__R_s_b_26_4 int64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_53475_1__R_s_b_26_4, emitter.context().types().s64());
    /* execute.a64:2648 [F] s_b_42_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2648 [D] s_b_42_2 = (u64)s_b_42_0 */
    auto s_b_42_2 = emitter.reinterpret(s_b_42_0, emitter.context().types().u64());
    /* execute.a64:2648 [F] s_b_42_3 = (u64)s_b_42_1 (const) */
    /* execute.a64:2648 [D] s_b_42_4 = s_b_42_2->>s_b_42_3 */
    auto s_b_42_4 = emitter.sar(s_b_42_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2648 [D] s_b_42_5 = (u64)s_b_42_4 */
    auto s_b_42_5 = (captive::arch::dbt::el::Value *)s_b_42_4;
    /* execute.a64:2648 [D] s_b_42_6: sym_53328_1__R_s_b_9_9 = s_b_42_5, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53328_1__R_s_b_9_9, s_b_42_5);
    /* execute.a64:2648 [F] s_b_42_7: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_24,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2754 [F] s_b_43_0=sym_6248_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_43_1 = sym_53541_3_parameter_value uint64_t */
    auto s_b_43_1 = emitter.load_local(DV_sym_53541_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_43_2: sym_53851_3_parameter_value = s_b_43_1, dominates: s_b_70_1  */
    emitter.store_local(DV_sym_53851_3_parameter_value, s_b_43_1);
    /* execute.a64:2745 [F] s_b_43_3 = (u32)s_b_43_0 (const) */
    /* execute.a64:2745 [F] s_b_43_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_43_5 = s_b_43_3==s_b_43_4 (const) */
    uint8_t s_b_43_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_43_6: If s_b_43_5: Jump b_45 else b_70 (const) */
    if (s_b_43_5) 
    {
      goto fixed_block_b_45;
    }
    else 
    {
      goto fixed_block_b_70;
    }
  }
  /* b_24,  */
  fixed_block_b_44: 
  {
    /* execute.a64:2756 [F] s_b_44_0=sym_6248_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_44_1 = sym_53541_3_parameter_value uint64_t */
    auto s_b_44_1 = emitter.load_local(DV_sym_53541_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_44_2 = (u32)s_b_44_1 */
    auto s_b_44_2 = emitter.truncate(s_b_44_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_44_3 = (u64)s_b_44_2 */
    auto s_b_44_3 = emitter.zx(s_b_44_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_44_4: sym_53873_3_parameter_value = s_b_44_3, dominates: s_b_71_1  */
    emitter.store_local(DV_sym_53873_3_parameter_value, s_b_44_3);
    /* execute.a64:2745 [F] s_b_44_5 = (u32)s_b_44_0 (const) */
    /* execute.a64:2745 [F] s_b_44_6 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_44_7 = s_b_44_5==s_b_44_6 (const) */
    uint8_t s_b_44_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_44_8: If s_b_44_7: Jump b_45 else b_71 (const) */
    if (s_b_44_7) 
    {
      goto fixed_block_b_45;
    }
    else 
    {
      goto fixed_block_b_71;
    }
  }
  /* b_43, b_44, b_70, b_71,  */
  fixed_block_b_45: 
  {
    /* execute.a64:2523 [F] s_b_45_0=sym_6248_3_parameter_inst.opc (const) */
    /* execute.a64:2523 [F] s_b_45_1 = (u32)s_b_45_0 (const) */
    /* execute.a64:2523 [F] s_b_45_2 = constant u32 3 (const) */
    /* execute.a64:2523 [F] s_b_45_3 = s_b_45_1==s_b_45_2 (const) */
    uint8_t s_b_45_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:2523 [F] s_b_45_4: If s_b_45_3: Jump b_1 else b_2 (const) */
    if (s_b_45_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_25,  */
  fixed_block_b_46: 
  {
    /* execute.a64:2714 [F] s_b_46_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_46_1: sym_53570_1_temporary_value = s_b_46_0 (const), dominates: s_b_48_0  */
    CV_sym_53570_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53570_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_46_2: Jump b_48 (const) */
    goto fixed_block_b_48;
  }
  /* b_25,  */
  fixed_block_b_47: 
  {
    /* execute.a64:2714 [F] s_b_47_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_47_1 = ReadRegBank 0:s_b_47_0 (u64) */
    auto s_b_47_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_47_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_47_2: sym_53570_1_temporary_value = s_b_47_1, dominates: s_b_48_0  */
    emitter.store_local(DV_sym_53570_1_temporary_value, s_b_47_1);
    /* execute.a64:2714 [F] s_b_47_3: Jump b_48 (const) */
    goto fixed_block_b_48;
  }
  /* b_46, b_47,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2714 [D] s_b_48_0 = sym_53570_1_temporary_value uint64_t */
    auto s_b_48_0 = emitter.load_local(DV_sym_53570_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_48_1: sym_53366_1__R_s_b_21_4 = s_b_48_0, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_53366_1__R_s_b_21_4, s_b_48_0);
    /* execute.a64:2720 [F] s_b_48_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_26,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2709 [F] s_b_49_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_49_1: sym_53598_1_temporary_value = s_b_49_0 (const), dominates: s_b_51_0  */
    CV_sym_53598_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53598_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_49_2: Jump b_51 (const) */
    goto fixed_block_b_51;
  }
  /* b_26,  */
  fixed_block_b_50: 
  {
    /* execute.a64:2709 [F] s_b_50_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_50_1 = ReadRegBank 1:s_b_50_0 (u32) */
    auto s_b_50_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_50_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_50_2: sym_53598_1_temporary_value = s_b_50_1, dominates: s_b_51_0  */
    emitter.store_local(DV_sym_53598_1_temporary_value, s_b_50_1);
    /* execute.a64:2709 [F] s_b_50_3: Jump b_51 (const) */
    goto fixed_block_b_51;
  }
  /* b_49, b_50,  */
  fixed_block_b_51: 
  {
    /* execute.a64:2709 [D] s_b_51_0 = sym_53598_1_temporary_value uint32_t */
    auto s_b_51_0 = emitter.load_local(DV_sym_53598_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_51_1 = (u64)s_b_51_0 */
    auto s_b_51_1 = emitter.zx(s_b_51_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_51_2: sym_53366_1__R_s_b_21_4 = s_b_51_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_53366_1__R_s_b_21_4, s_b_51_1);
    /* execute.a64:2722 [F] s_b_51_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_28,  */
  fixed_block_b_52: 
  {
    /* execute.a64:2714 [F] s_b_52_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_52_1: sym_53626_1_temporary_value = s_b_52_0 (const), dominates: s_b_54_0  */
    CV_sym_53626_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53626_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_52_2: Jump b_54 (const) */
    goto fixed_block_b_54;
  }
  /* b_28,  */
  fixed_block_b_53: 
  {
    /* execute.a64:2714 [F] s_b_53_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_53_1 = ReadRegBank 0:s_b_53_0 (u64) */
    auto s_b_53_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_53_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_53_2: sym_53626_1_temporary_value = s_b_53_1, dominates: s_b_54_0  */
    emitter.store_local(DV_sym_53626_1_temporary_value, s_b_53_1);
    /* execute.a64:2714 [F] s_b_53_3: Jump b_54 (const) */
    goto fixed_block_b_54;
  }
  /* b_52, b_53,  */
  fixed_block_b_54: 
  {
    /* execute.a64:2714 [D] s_b_54_0 = sym_53626_1_temporary_value uint64_t */
    auto s_b_54_0 = emitter.load_local(DV_sym_53626_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_54_1: sym_53391_1__R_s_b_24_4 = s_b_54_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_53391_1__R_s_b_24_4, s_b_54_0);
    /* execute.a64:2720 [F] s_b_54_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_29,  */
  fixed_block_b_55: 
  {
    /* execute.a64:2709 [F] s_b_55_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_55_1: sym_53654_1_temporary_value = s_b_55_0 (const), dominates: s_b_57_0  */
    CV_sym_53654_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53654_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_55_2: Jump b_57 (const) */
    goto fixed_block_b_57;
  }
  /* b_29,  */
  fixed_block_b_56: 
  {
    /* execute.a64:2709 [F] s_b_56_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_56_1 = ReadRegBank 1:s_b_56_0 (u32) */
    auto s_b_56_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_56_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_56_2: sym_53654_1_temporary_value = s_b_56_1, dominates: s_b_57_0  */
    emitter.store_local(DV_sym_53654_1_temporary_value, s_b_56_1);
    /* execute.a64:2709 [F] s_b_56_3: Jump b_57 (const) */
    goto fixed_block_b_57;
  }
  /* b_55, b_56,  */
  fixed_block_b_57: 
  {
    /* execute.a64:2709 [D] s_b_57_0 = sym_53654_1_temporary_value uint32_t */
    auto s_b_57_0 = emitter.load_local(DV_sym_53654_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_57_1 = (u64)s_b_57_0 */
    auto s_b_57_1 = emitter.zx(s_b_57_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_57_2: sym_53391_1__R_s_b_24_4 = s_b_57_1, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_53391_1__R_s_b_24_4, s_b_57_1);
    /* execute.a64:2722 [F] s_b_57_3: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_31,  */
  fixed_block_b_58: 
  {
    /* execute.a64:2714 [F] s_b_58_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_58_1: sym_53682_1_temporary_value = s_b_58_0 (const), dominates: s_b_60_0  */
    CV_sym_53682_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53682_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_58_2: Jump b_60 (const) */
    goto fixed_block_b_60;
  }
  /* b_31,  */
  fixed_block_b_59: 
  {
    /* execute.a64:2714 [F] s_b_59_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_59_1 = ReadRegBank 0:s_b_59_0 (u64) */
    auto s_b_59_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_59_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_59_2: sym_53682_1_temporary_value = s_b_59_1, dominates: s_b_60_0  */
    emitter.store_local(DV_sym_53682_1_temporary_value, s_b_59_1);
    /* execute.a64:2714 [F] s_b_59_3: Jump b_60 (const) */
    goto fixed_block_b_60;
  }
  /* b_58, b_59,  */
  fixed_block_b_60: 
  {
    /* execute.a64:2714 [D] s_b_60_0 = sym_53682_1_temporary_value uint64_t */
    auto s_b_60_0 = emitter.load_local(DV_sym_53682_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_60_1: sym_53416_1__R_s_b_25_4 = s_b_60_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_53416_1__R_s_b_25_4, s_b_60_0);
    /* execute.a64:2720 [F] s_b_60_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_32,  */
  fixed_block_b_61: 
  {
    /* execute.a64:2709 [F] s_b_61_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_61_1: sym_53710_1_temporary_value = s_b_61_0 (const), dominates: s_b_63_0  */
    CV_sym_53710_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53710_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_61_2: Jump b_63 (const) */
    goto fixed_block_b_63;
  }
  /* b_32,  */
  fixed_block_b_62: 
  {
    /* execute.a64:2709 [F] s_b_62_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_62_1 = ReadRegBank 1:s_b_62_0 (u32) */
    auto s_b_62_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_62_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_62_2: sym_53710_1_temporary_value = s_b_62_1, dominates: s_b_63_0  */
    emitter.store_local(DV_sym_53710_1_temporary_value, s_b_62_1);
    /* execute.a64:2709 [F] s_b_62_3: Jump b_63 (const) */
    goto fixed_block_b_63;
  }
  /* b_61, b_62,  */
  fixed_block_b_63: 
  {
    /* execute.a64:2709 [D] s_b_63_0 = sym_53710_1_temporary_value uint32_t */
    auto s_b_63_0 = emitter.load_local(DV_sym_53710_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_63_1 = (u64)s_b_63_0 */
    auto s_b_63_1 = emitter.zx(s_b_63_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_63_2: sym_53416_1__R_s_b_25_4 = s_b_63_1, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_53416_1__R_s_b_25_4, s_b_63_1);
    /* execute.a64:2722 [F] s_b_63_3: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_22,  */
  fixed_block_b_64: 
  {
    /* execute.a64:2714 [F] s_b_64_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_64_1: sym_53738_1_temporary_value = s_b_64_0 (const), dominates: s_b_66_0  */
    CV_sym_53738_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53738_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_64_2: Jump b_66 (const) */
    goto fixed_block_b_66;
  }
  /* b_22,  */
  fixed_block_b_65: 
  {
    /* execute.a64:2714 [F] s_b_65_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_65_1 = ReadRegBank 0:s_b_65_0 (u64) */
    auto s_b_65_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_65_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_65_2: sym_53738_1_temporary_value = s_b_65_1, dominates: s_b_66_0  */
    emitter.store_local(DV_sym_53738_1_temporary_value, s_b_65_1);
    /* execute.a64:2714 [F] s_b_65_3: Jump b_66 (const) */
    goto fixed_block_b_66;
  }
  /* b_64, b_65,  */
  fixed_block_b_66: 
  {
    /* execute.a64:2714 [D] s_b_66_0 = sym_53738_1_temporary_value uint64_t */
    auto s_b_66_0 = emitter.load_local(DV_sym_53738_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2653 [F] s_b_66_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2653 [F] s_b_66_2 = (u64)s_b_66_1 (const) */
    /* execute.a64:2653 [D] s_b_66_3 = s_b_66_0>>>s_b_66_2 */
    auto s_b_66_3 = emitter.ror(s_b_66_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2653 [D] s_b_66_4: sym_53328_1__R_s_b_9_9 = s_b_66_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53328_1__R_s_b_9_9, s_b_66_3);
    /* execute.a64:2653 [F] s_b_66_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_67: 
  {
    /* execute.a64:2709 [F] s_b_67_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_67_1: sym_53822_1_temporary_value = s_b_67_0 (const), dominates: s_b_69_0  */
    CV_sym_53822_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53822_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_67_2: Jump b_69 (const) */
    goto fixed_block_b_69;
  }
  /* b_23,  */
  fixed_block_b_68: 
  {
    /* execute.a64:2709 [F] s_b_68_0=sym_6248_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_68_1 = ReadRegBank 1:s_b_68_0 (u32) */
    auto s_b_68_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_68_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_68_2: sym_53822_1_temporary_value = s_b_68_1, dominates: s_b_69_0  */
    emitter.store_local(DV_sym_53822_1_temporary_value, s_b_68_1);
    /* execute.a64:2709 [F] s_b_68_3: Jump b_69 (const) */
    goto fixed_block_b_69;
  }
  /* b_67, b_68,  */
  fixed_block_b_69: 
  {
    /* execute.a64:2709 [D] s_b_69_0 = sym_53822_1_temporary_value uint32_t */
    auto s_b_69_0 = emitter.load_local(DV_sym_53822_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_69_1 = (u64)s_b_69_0 */
    auto s_b_69_1 = emitter.zx(s_b_69_0, emitter.context().types().u64());
    /* execute.a64:2655 [D] s_b_69_2 = (u32)s_b_69_1 */
    auto s_b_69_2 = emitter.truncate(s_b_69_1, emitter.context().types().u32());
    /* execute.a64:2655 [F] s_b_69_3=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2655 [F] s_b_69_4 = (u32)s_b_69_3 (const) */
    /* execute.a64:2655 [D] s_b_69_5 = s_b_69_2>>>s_b_69_4 */
    auto s_b_69_5 = emitter.ror(s_b_69_2, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2655 [D] s_b_69_6 = (u64)s_b_69_5 */
    auto s_b_69_6 = emitter.zx(s_b_69_5, emitter.context().types().u64());
    /* execute.a64:2655 [D] s_b_69_7: sym_53328_1__R_s_b_9_9 = s_b_69_6, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53328_1__R_s_b_9_9, s_b_69_6);
    /* execute.a64:2655 [F] s_b_69_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_43,  */
  fixed_block_b_70: 
  {
    /* execute.a64:2747 [F] s_b_70_0=sym_6248_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_70_1 = sym_53851_3_parameter_value uint64_t */
    auto s_b_70_1 = emitter.load_local(DV_sym_53851_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_70_2: WriteRegBank 0:s_b_70_0 = s_b_70_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_70_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_70_1);
    /* execute.a64:0 [F] s_b_70_3: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_44,  */
  fixed_block_b_71: 
  {
    /* execute.a64:2747 [F] s_b_71_0=sym_6248_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_71_1 = sym_53873_3_parameter_value uint64_t */
    auto s_b_71_1 = emitter.load_local(DV_sym_53873_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_71_2: WriteRegBank 0:s_b_71_0 = s_b_71_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_71_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_71_1);
    /* execute.a64:0 [F] s_b_71_3: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  if (!insn.end_of_block) 
  {
    emitter.inc_pc(emitter.const_u8(4));
  }
  return true;
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ccmpi(const arm64_decode_a64_COND_CMP_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_55828_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  uint8_t CV_sym_55668_0_state;
  auto DV_sym_55668_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55756_1__R_s_b_0_2 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55781_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55800_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_6758_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2083 [F] s_b_0_0=sym_6740_3_parameter_inst.cond (const) */
    /* execute.a64:2854 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2854 [F] s_b_0_2: sym_55668_0_state = s_b_0_1 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_55668_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_55668_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2856 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_8, b_7, b_11, b_12, b_6, b_10, b_9, b_13, b_14,  */
    switch (s_b_0_5) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_7;
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
    /* execute.a64:2891 [F] s_b_6_0=sym_6740_3_parameter_inst.cond (const) */
    /* execute.a64:2891 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2891 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.a64:2891 [F] s_b_6_3 = s_b_6_1&s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2891 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:2891 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:2891 [F] s_b_6_6=sym_6740_3_parameter_inst.cond (const) */
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
    /* execute.a64:2878 [D] s_b_7_3: sym_55668_0_state = s_b_7_2, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55668_0_state, s_b_7_2);
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
    /* execute.a64:2874 [D] s_b_8_4: sym_55668_0_state = s_b_8_3, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55668_0_state, s_b_8_3);
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
    /* execute.a64:2870 [D] s_b_9_1: sym_55668_0_state = s_b_9_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55668_0_state, s_b_9_0);
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
    /* execute.a64:2866 [D] s_b_10_1: sym_55668_0_state = s_b_10_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55668_0_state, s_b_10_0);
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
    /* execute.a64:2862 [D] s_b_11_1: sym_55668_0_state = s_b_11_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55668_0_state, s_b_11_0);
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
    /* execute.a64:2858 [D] s_b_12_1: sym_55668_0_state = s_b_12_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55668_0_state, s_b_12_0);
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
    /* execute.a64:2882 [D] s_b_13_6: sym_55668_0_state = s_b_13_5, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55668_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2886 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2886 [F] s_b_14_1: sym_55668_0_state = s_b_14_0 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_55668_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_55668_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2892 [D] s_b_15_0 = sym_55668_0_state uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_55668_0_state, emitter.context().types().u8());
    /* execute.a64:2892 [D] s_b_15_1 = !s_b_15_0 */
    auto s_b_15_1 = emitter.cmp_eq(s_b_15_0, emitter.const_u8(0));
    /* execute.a64:2892 [D] s_b_15_2: sym_55756_1__R_s_b_0_2 = s_b_15_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_55756_1__R_s_b_0_2, s_b_15_1);
    /* execute.a64:2892 [F] s_b_15_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2894 [D] s_b_16_0 = sym_55668_0_state uint8_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_55668_0_state, emitter.context().types().u8());
    /* execute.a64:2894 [D] s_b_16_1: sym_55756_1__R_s_b_0_2 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_55756_1__R_s_b_0_2, s_b_16_0);
    /* execute.a64:2894 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2083 [D] s_b_17_0 = sym_55756_1__R_s_b_0_2 uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_55756_1__R_s_b_0_2, emitter.context().types().u8());
    /* execute.a64:2085 [D] s_b_17_1 = (u32)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u32());
    /* execute.a64:2085 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.a64:2085 [D] s_b_17_3 = s_b_17_1!=s_b_17_2 */
    auto s_b_17_3 = emitter.cmp_ne(s_b_17_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2085 [D] s_b_17_4: If s_b_17_3: Jump b_1 else b_3 */
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
        /* execute.a64:2086 [F] s_b_1_0=sym_6740_3_parameter_inst.sf (const) */
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
        /* execute.a64:2094 [F] s_b_3_0=sym_6740_3_parameter_inst.nzcv (const) */
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
        /* execute.a64:2095 [F] s_b_3_7=sym_6740_3_parameter_inst.nzcv (const) */
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
        /* execute.a64:2096 [F] s_b_3_14=sym_6740_3_parameter_inst.nzcv (const) */
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
        /* execute.a64:2097 [F] s_b_3_21=sym_6740_3_parameter_inst.nzcv (const) */
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
        /* execute.a64:2089 [D] s_b_4_0 = sym_6758_0_rn uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_6758_0_rn, emitter.context().types().u64());
        /* execute.a64:2089 [D] s_b_4_1 = (u32)s_b_4_0 */
        auto s_b_4_1 = emitter.truncate(s_b_4_0, emitter.context().types().u32());
        /* execute.a64:2089 [F] s_b_4_2=sym_6740_3_parameter_inst.imm5 (const) */
        /* execute.a64:2089 [F] s_b_4_3 = (u32)s_b_4_2 (const) */
        /* execute.a64:2089 [F] s_b_4_4 = ~s_b_4_3 (const) */
        uint32_t s_b_4_4 = ~((uint32_t)insn.imm5);
        /* execute.a64:2089 [F] s_b_4_5 = constant u8 1 (const) */
        /* execute.a64:2089 [D] s_b_4_6 = __builtin_adc32_flags */
        auto s_b_4_6 = emitter.adcf(s_b_4_1, emitter.const_u32(s_b_4_4), emitter.const_u8((uint8_t)1ULL));
        /* execute.a64:2089 [F] s_b_4_7: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2091 [D] s_b_5_0 = sym_6758_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_6758_0_rn, emitter.context().types().u64());
        /* execute.a64:2091 [F] s_b_5_1=sym_6740_3_parameter_inst.imm5 (const) */
        /* execute.a64:2091 [F] s_b_5_2 = (u64)s_b_5_1 (const) */
        /* execute.a64:2091 [F] s_b_5_3 = ~s_b_5_2 (const) */
        uint64_t s_b_5_3 = ~((uint64_t)insn.imm5);
        /* execute.a64:2091 [F] s_b_5_4 = constant u8 1 (const) */
        /* execute.a64:2091 [D] s_b_5_5 = __builtin_adc64_flags */
        auto s_b_5_5 = emitter.adcf(s_b_5_0, emitter.const_u64(s_b_5_3), emitter.const_u8((uint8_t)1ULL));
        /* execute.a64:2091 [F] s_b_5_6: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2720 [F] s_b_18_0=sym_6740_3_parameter_inst.rn (const) */
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
        /* execute.a64:2722 [F] s_b_19_0=sym_6740_3_parameter_inst.rn (const) */
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
        /* execute.a64:2086 [D] s_b_20_0 = sym_55781_1__R_s_b_1_4 uint64_t */
        auto s_b_20_0 = emitter.load_local(DV_sym_55781_1__R_s_b_1_4, emitter.context().types().u64());
        /* execute.a64:2086 [D] s_b_20_1: sym_6758_0_rn = s_b_20_0, dominates: s_b_4_0 s_b_5_0  */
        emitter.store_local(DV_sym_6758_0_rn, s_b_20_0);
        /* execute.a64:2088 [F] s_b_20_2=sym_6740_3_parameter_inst.sf (const) */
        /* execute.a64:2088 [F] s_b_20_3 = (u32)s_b_20_2 (const) */
        /* execute.a64:2088 [F] s_b_20_4 = constant u32 0 (const) */
        /* execute.a64:2088 [F] s_b_20_5 = s_b_20_3==s_b_20_4 (const) */
        uint8_t s_b_20_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
        /* execute.a64:2088 [F] s_b_20_6: If s_b_20_5: Jump b_4 else b_5 (const) */
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
        /* execute.a64:2714 [D] s_b_21_1: sym_55800_1_temporary_value = s_b_21_0, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_55800_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_22_0=sym_6740_3_parameter_inst.rn (const) */
        /* execute.a64:2714 [D] s_b_22_1 = ReadRegBank 0:s_b_22_0 (u64) */
        auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_22_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_22_2: sym_55800_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_55800_1_temporary_value, s_b_22_1);
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
        /* execute.a64:2714 [D] s_b_23_0 = sym_55800_1_temporary_value uint64_t */
        auto s_b_23_0 = emitter.load_local(DV_sym_55800_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_23_1: sym_55781_1__R_s_b_1_4 = s_b_23_0, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_55781_1__R_s_b_1_4, s_b_23_0);
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
        /* execute.a64:2709 [D] s_b_24_1: sym_55828_1_temporary_value = s_b_24_0, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_55828_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_25_0=sym_6740_3_parameter_inst.rn (const) */
        /* execute.a64:2709 [D] s_b_25_1 = ReadRegBank 1:s_b_25_0 (u32) */
        auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_25_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_25_2: sym_55828_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_55828_1_temporary_value, s_b_25_1);
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
        /* execute.a64:2709 [D] s_b_26_0 = sym_55828_1_temporary_value uint32_t */
        auto s_b_26_0 = emitter.load_local(DV_sym_55828_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_26_1 = (u64)s_b_26_0 */
        auto s_b_26_1 = emitter.zx(s_b_26_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_26_2: sym_55781_1__R_s_b_1_4 = s_b_26_1, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_55781_1__R_s_b_1_4, s_b_26_1);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_cmhi_reg(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
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
    /* execute.simd:1543 [F] s_b_0_0=sym_7781_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1543 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1544 [F] s_b_1_0=sym_7781_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:1545 [F] s_b_1_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:6355 [D] s_b_1_3 = ReadRegBank 7:s_b_1_2 (u64) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(8));
    }
    /* execute.simd:1547 [D] s_b_1_4 = s_b_1_1>s_b_1_3 */
    auto s_b_1_4 = emitter.cmp_gt(s_b_1_1, s_b_1_3);
    /* execute.simd:1547 [D] s_b_1_5: If s_b_1_4: Jump b_4 else b_5 */
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
    /* execute.simd:1553 [F] s_b_3_0=sym_7781_3_parameter_inst.arrangement (const) */
    /* execute.simd:1554 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:1564 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:1573 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:1583 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:1592 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:1602 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:1611 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:1553 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_13 (const) -> b_13, b_12, b_11, b_10, b_9, b_8, b_7, b_6,  */
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
    /* execute.simd:1555 [F] s_b_6_0=sym_7781_3_parameter_inst.rn (const) */
    /* execute.simd:1555 [D] s_b_6_1 = ReadRegBank 15:s_b_6_0 (v8u8) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1556 [F] s_b_6_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:1556 [D] s_b_6_3 = ReadRegBank 15:s_b_6_2 (v8u8) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1558 [D] s_b_6_4 = s_b_6_1>s_b_6_3 */
    auto s_b_6_4 = emitter.cmp_gt(s_b_6_1, s_b_6_3);
    /* execute.simd:1559 [F] s_b_6_5=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1559 [D] s_b_6_6: WriteRegBank 15:s_b_6_5 = s_b_6_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
    /* execute.simd:1560 [F] s_b_6_7=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1560 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:1560 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
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
    /* execute.simd:1565 [F] s_b_7_0=sym_7781_3_parameter_inst.rn (const) */
    /* execute.simd:1565 [D] s_b_7_1 = ReadRegBank 16:s_b_7_0 (v16u8) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:1566 [F] s_b_7_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:1566 [D] s_b_7_3 = ReadRegBank 16:s_b_7_2 (v16u8) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:1568 [D] s_b_7_4 = s_b_7_1>s_b_7_3 */
    auto s_b_7_4 = emitter.cmp_gt(s_b_7_1, s_b_7_3);
    /* execute.simd:1569 [F] s_b_7_5=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1569 [D] s_b_7_6: WriteRegBank 16:s_b_7_5 = s_b_7_4 */
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
    /* execute.simd:1574 [F] s_b_8_0=sym_7781_3_parameter_inst.rn (const) */
    /* execute.simd:1574 [D] s_b_8_1 = ReadRegBank 17:s_b_8_0 (v4u16) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:1575 [F] s_b_8_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:1575 [D] s_b_8_3 = ReadRegBank 17:s_b_8_2 (v4u16) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(8));
    }
    /* execute.simd:1577 [D] s_b_8_4 = s_b_8_1>s_b_8_3 */
    auto s_b_8_4 = emitter.cmp_gt(s_b_8_1, s_b_8_3);
    /* execute.simd:1578 [F] s_b_8_5=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1578 [D] s_b_8_6: WriteRegBank 17:s_b_8_5 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4);
    /* execute.simd:1579 [F] s_b_8_7=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1579 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:1579 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
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
    /* execute.simd:1584 [F] s_b_9_0=sym_7781_3_parameter_inst.rn (const) */
    /* execute.simd:1584 [D] s_b_9_1 = ReadRegBank 18:s_b_9_0 (v8u16) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:1585 [F] s_b_9_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:1585 [D] s_b_9_3 = ReadRegBank 18:s_b_9_2 (v8u16) */
    auto s_b_9_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_9_3,emitter.const_u8(16));
    }
    /* execute.simd:1587 [D] s_b_9_4 = s_b_9_1>s_b_9_3 */
    auto s_b_9_4 = emitter.cmp_gt(s_b_9_1, s_b_9_3);
    /* execute.simd:1589 [F] s_b_9_5=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1589 [D] s_b_9_6: WriteRegBank 18:s_b_9_5 = s_b_9_4 */
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
    /* execute.simd:1593 [F] s_b_10_0=sym_7781_3_parameter_inst.rn (const) */
    /* execute.simd:1593 [D] s_b_10_1 = ReadRegBank 19:s_b_10_0 (v2u32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.simd:1594 [F] s_b_10_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:1594 [D] s_b_10_3 = ReadRegBank 19:s_b_10_2 (v2u32) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:1596 [D] s_b_10_4 = s_b_10_1>s_b_10_3 */
    auto s_b_10_4 = emitter.cmp_gt(s_b_10_1, s_b_10_3);
    /* execute.simd:1597 [F] s_b_10_5=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1597 [D] s_b_10_6: WriteRegBank 19:s_b_10_5 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4);
    /* execute.simd:1598 [F] s_b_10_7=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1598 [F] s_b_10_8 = constant u64 0 (const) */
    /* execute.simd:1598 [F] s_b_10_9: WriteRegBank 3:s_b_10_7 = s_b_10_8 */
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
    /* execute.simd:1603 [F] s_b_11_0=sym_7781_3_parameter_inst.rn (const) */
    /* execute.simd:1603 [D] s_b_11_1 = ReadRegBank 20:s_b_11_0 (v4u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_11_1,emitter.const_u8(16));
    }
    /* execute.simd:1604 [F] s_b_11_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:1604 [D] s_b_11_3 = ReadRegBank 20:s_b_11_2 (v4u32) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:1606 [D] s_b_11_4 = s_b_11_1>s_b_11_3 */
    auto s_b_11_4 = emitter.cmp_gt(s_b_11_1, s_b_11_3);
    /* execute.simd:1608 [F] s_b_11_5=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1608 [D] s_b_11_6: WriteRegBank 20:s_b_11_5 = s_b_11_4 */
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
    /* execute.simd:1612 [F] s_b_12_0=sym_7781_3_parameter_inst.rn (const) */
    /* execute.simd:1612 [D] s_b_12_1 = ReadRegBank 21:s_b_12_0 (v2u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(16));
    }
    /* execute.simd:1613 [F] s_b_12_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:1613 [D] s_b_12_3 = ReadRegBank 21:s_b_12_2 (v2u64) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_12_3,emitter.const_u8(16));
    }
    /* execute.simd:1615 [D] s_b_12_4 = s_b_12_1>s_b_12_3 */
    auto s_b_12_4 = emitter.cmp_gt(s_b_12_1, s_b_12_3);
    /* execute.simd:1617 [F] s_b_12_5=sym_7781_3_parameter_inst.rd (const) */
    /* execute.simd:1617 [D] s_b_12_6: WriteRegBank 21:s_b_12_5 = s_b_12_4 */
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
    /* execute.simd:1621 [D] s_b_13_0 = trap */
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
        /* execute.simd:1548 [F] s_b_4_0=sym_7781_3_parameter_inst.rd (const) */
        /* execute.simd:1548 [F] s_b_4_1 = constant u64 ffffffffffffffff (const) */
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
        /* execute.simd:1550 [F] s_b_5_0=sym_7781_3_parameter_inst.rd (const) */
        /* execute.simd:1550 [F] s_b_5_1 = constant u64 0 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_csinc(const arm64_decode_a64_COND_SEL&insn, captive::arch::dbt::el::Emitter& emitter)
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
  uint8_t CV_sym_57874_0_state;
  auto DV_sym_57874_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_58255_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58159_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58189_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58211_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58233_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58052_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_58077_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58106_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58134_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_57968_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_57999_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58024_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_57917_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2180 [F] s_b_0_0=sym_9192_3_parameter_inst.cond (const) */
    /* execute.a64:2854 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2854 [F] s_b_0_2: sym_57874_0_state = s_b_0_1 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_57874_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_57874_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2856 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_4 (const) -> b_10, b_4, b_9, b_7, b_12, b_8, b_11, b_13, b_14,  */
    switch (s_b_0_5) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_14;
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
    /* execute.a64:2891 [F] s_b_4_0=sym_9192_3_parameter_inst.cond (const) */
    /* execute.a64:2891 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2891 [F] s_b_4_2 = constant u32 1 (const) */
    /* execute.a64:2891 [F] s_b_4_3 = s_b_4_1&s_b_4_2 (const) */
    uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2891 [F] s_b_4_4 = constant u32 1 (const) */
    /* execute.a64:2891 [F] s_b_4_5 = s_b_4_3==s_b_4_4 (const) */
    uint8_t s_b_4_5 = ((uint8_t)(s_b_4_3 == (uint32_t)1ULL));
    /* execute.a64:2891 [F] s_b_4_6 = (u32)s_b_4_0 (const) */
    /* execute.a64:2891 [F] s_b_4_7 = constant u32 f (const) */
    /* execute.a64:2891 [F] s_b_4_8 = s_b_4_6!=s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.cond) != (uint32_t)15ULL));
    /* ???:4294967295 [F] s_b_4_9 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_4_10 = s_b_4_5!=s_b_4_9 (const) */
    uint8_t s_b_4_10 = ((uint8_t)(s_b_4_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_11 = s_b_4_8!=s_b_4_9 (const) */
    uint8_t s_b_4_11 = ((uint8_t)(s_b_4_8 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_12 = s_b_4_10&s_b_4_11 (const) */
    uint8_t s_b_4_12 = ((uint8_t)(s_b_4_10 & s_b_4_11));
    /* execute.a64:2891 [F] s_b_4_13: If s_b_4_12: Jump b_5 else b_6 (const) */
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
    /* execute.a64:2892 [D] s_b_5_0 = sym_57874_0_state uint8_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_57874_0_state, emitter.context().types().u8());
    /* execute.a64:2892 [D] s_b_5_1 = !s_b_5_0 */
    auto s_b_5_1 = emitter.cmp_eq(s_b_5_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_5_2: sym_57917_0_return_symbol = s_b_5_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_57917_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2894 [D] s_b_6_0 = sym_57874_0_state uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_57874_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_6_1: sym_57917_0_return_symbol = s_b_6_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_57917_0_return_symbol, s_b_6_0);
    /* ???:4294967295 [F] s_b_6_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2858 [D] s_b_7_0 = ReadReg 2 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2858 [D] s_b_7_1: sym_57874_0_state = s_b_7_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57874_0_state, s_b_7_0);
    /* execute.a64:0 [F] s_b_7_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2862 [D] s_b_8_0 = ReadReg 3 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2862 [D] s_b_8_1: sym_57874_0_state = s_b_8_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57874_0_state, s_b_8_0);
    /* execute.a64:0 [F] s_b_8_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2866 [D] s_b_9_0 = ReadReg 1 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2866 [D] s_b_9_1: sym_57874_0_state = s_b_9_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57874_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2870 [D] s_b_10_0 = ReadReg 4 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2870 [D] s_b_10_1: sym_57874_0_state = s_b_10_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57874_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2874 [D] s_b_11_0 = ReadReg 3 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2874 [D] s_b_11_1 = ReadReg 2 (u8) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_11_1, emitter.const_u8(1));
    }
    /* execute.a64:2874 [D] s_b_11_2 = !s_b_11_1 */
    auto s_b_11_2 = emitter.cmp_eq(s_b_11_1, emitter.const_u8(0));
    /* execute.a64:2874 [D] s_b_11_3 = s_b_11_0&s_b_11_2 */
    auto s_b_11_3 = emitter.bitwise_and(s_b_11_0, s_b_11_2);
    /* execute.a64:2874 [D] s_b_11_4: sym_57874_0_state = s_b_11_3, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57874_0_state, s_b_11_3);
    /* execute.a64:0 [F] s_b_11_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2878 [D] s_b_12_0 = ReadReg 1 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_12_1 = ReadReg 4 (u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_12_1, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_12_2 = s_b_12_0==s_b_12_1 */
    auto s_b_12_2 = emitter.cmp_eq(s_b_12_0, s_b_12_1);
    /* execute.a64:2878 [D] s_b_12_3: sym_57874_0_state = s_b_12_2, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57874_0_state, s_b_12_2);
    /* execute.a64:0 [F] s_b_12_4: Jump b_4 (const) */
    goto fixed_block_b_4;
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
    /* execute.a64:2882 [D] s_b_13_6: sym_57874_0_state = s_b_13_5, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57874_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2886 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2886 [F] s_b_14_1: sym_57874_0_state = s_b_14_0 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_57874_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_57874_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5, b_6,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_57917_0_return_symbol uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_57917_0_return_symbol, emitter.context().types().u8());
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
        /* execute.a64:2183 [F] s_b_1_0=sym_9192_3_parameter_inst.sf (const) */
        /* execute.a64:2719 [F] s_b_1_1: If s_b_1_0: Jump b_16 else b_17 (const) */
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
        /* execute.a64:2185 [F] s_b_3_0=sym_9192_3_parameter_inst.sf (const) */
        /* execute.a64:2719 [F] s_b_3_1: If s_b_3_0: Jump b_19 else b_20 (const) */
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
        /* execute.a64:2720 [F] s_b_16_0=sym_9192_3_parameter_inst.rm (const) */
        /* execute.a64:2714 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
        /* execute.a64:2714 [F] s_b_16_2 = constant u32 1f (const) */
        /* execute.a64:2714 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
        uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2714 [F] s_b_16_4: If s_b_16_3: Jump b_22 else b_23 (const) */
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
        /* execute.a64:2722 [F] s_b_17_0=sym_9192_3_parameter_inst.rm (const) */
        /* execute.a64:2709 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
        /* execute.a64:2709 [F] s_b_17_2 = constant u32 1f (const) */
        /* execute.a64:2709 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
        uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
        /* execute.a64:2709 [F] s_b_17_4: If s_b_17_3: Jump b_25 else b_26 (const) */
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
        /* ???:4294967295 [F] s_b_18_0=sym_9192_3_parameter_inst.sf (const) */
        /* execute.a64:2183 [D] s_b_18_1 = sym_57968_1__R_s_b_1_6 uint64_t */
        auto s_b_18_1 = emitter.load_local(DV_sym_57968_1__R_s_b_1_6, emitter.context().types().u64());
        /* execute.a64:2183 [F] s_b_18_2 = constant u64 1 (const) */
        /* execute.a64:2183 [D] s_b_18_3 = s_b_18_1+s_b_18_2 */
        auto s_b_18_3 = emitter.add(s_b_18_1, emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:2183 [D] s_b_18_4: sym_58077_3_parameter_value = s_b_18_3, dominates: s_b_28_1 s_b_29_1  */
        emitter.store_local(DV_sym_58077_3_parameter_value, s_b_18_3);
        /* execute.a64:2753 [F] s_b_18_5: If s_b_18_0: Jump b_28 else b_29 (const) */
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
        /* execute.a64:2720 [F] s_b_19_0=sym_9192_3_parameter_inst.rn (const) */
        /* execute.a64:2714 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.a64:2714 [F] s_b_19_2 = constant u32 1f (const) */
        /* execute.a64:2714 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
        uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2714 [F] s_b_19_4: If s_b_19_3: Jump b_30 else b_31 (const) */
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
        /* execute.a64:2722 [F] s_b_20_0=sym_9192_3_parameter_inst.rn (const) */
        /* execute.a64:2709 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
        /* execute.a64:2709 [F] s_b_20_2 = constant u32 1f (const) */
        /* execute.a64:2709 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
        uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
        /* execute.a64:2709 [F] s_b_20_4: If s_b_20_3: Jump b_33 else b_34 (const) */
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
        /* ???:4294967295 [F] s_b_21_0=sym_9192_3_parameter_inst.sf (const) */
        /* execute.a64:2185 [D] s_b_21_1 = sym_57999_1__R_s_b_3_6 uint64_t */
        auto s_b_21_1 = emitter.load_local(DV_sym_57999_1__R_s_b_3_6, emitter.context().types().u64());
        /* execute.a64:2185 [D] s_b_21_2: sym_58159_3_parameter_value = s_b_21_1, dominates: s_b_36_1 s_b_37_1  */
        emitter.store_local(DV_sym_58159_3_parameter_value, s_b_21_1);
        /* execute.a64:2753 [F] s_b_21_3: If s_b_21_0: Jump b_36 else b_37 (const) */
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
        /* execute.a64:2714 [F] s_b_22_0 = constant u64 0 (const) */
        /* execute.a64:2714 [D] s_b_22_1: sym_58024_1_temporary_value = s_b_22_0, dominates: s_b_24_0  */
        emitter.store_local(DV_sym_58024_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2714 [F] s_b_22_2: Jump b_24 (const) */
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.a64:2714 [F] s_b_23_0=sym_9192_3_parameter_inst.rm (const) */
        /* execute.a64:2714 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
        auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_23_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_23_2: sym_58024_1_temporary_value = s_b_23_1, dominates: s_b_24_0  */
        emitter.store_local(DV_sym_58024_1_temporary_value, s_b_23_1);
        /* execute.a64:2714 [F] s_b_23_3: Jump b_24 (const) */
        {
          auto block = block_b_24;
          dynamic_block_queue.push(block_b_24);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.a64:2714 [D] s_b_24_0 = sym_58024_1_temporary_value uint64_t */
        auto s_b_24_0 = emitter.load_local(DV_sym_58024_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_24_1: sym_57968_1__R_s_b_1_6 = s_b_24_0, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_57968_1__R_s_b_1_6, s_b_24_0);
        /* execute.a64:2720 [F] s_b_24_2: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.a64:2709 [F] s_b_25_0 = constant u32 0 (const) */
        /* execute.a64:2709 [D] s_b_25_1: sym_58052_1_temporary_value = s_b_25_0, dominates: s_b_27_0  */
        emitter.store_local(DV_sym_58052_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2709 [F] s_b_25_2: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.a64:2709 [F] s_b_26_0=sym_9192_3_parameter_inst.rm (const) */
        /* execute.a64:2709 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
        auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_26_2: sym_58052_1_temporary_value = s_b_26_1, dominates: s_b_27_0  */
        emitter.store_local(DV_sym_58052_1_temporary_value, s_b_26_1);
        /* execute.a64:2709 [F] s_b_26_3: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.a64:2709 [D] s_b_27_0 = sym_58052_1_temporary_value uint32_t */
        auto s_b_27_0 = emitter.load_local(DV_sym_58052_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_27_1 = (u64)s_b_27_0 */
        auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_27_2: sym_57968_1__R_s_b_1_6 = s_b_27_1, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_57968_1__R_s_b_1_6, s_b_27_1);
        /* execute.a64:2722 [F] s_b_27_3: Jump b_18 (const) */
        {
          auto block = block_b_18;
          dynamic_block_queue.push(block_b_18);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.a64:2754 [F] s_b_28_0=sym_9192_3_parameter_inst.rd (const) */
        /* execute.a64:2754 [D] s_b_28_1 = sym_58077_3_parameter_value uint64_t */
        auto s_b_28_1 = emitter.load_local(DV_sym_58077_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2754 [D] s_b_28_2: sym_58189_3_parameter_value = s_b_28_1, dominates: s_b_38_1  */
        emitter.store_local(DV_sym_58189_3_parameter_value, s_b_28_1);
        /* execute.a64:2745 [F] s_b_28_3 = (u32)s_b_28_0 (const) */
        /* execute.a64:2745 [F] s_b_28_4 = constant u32 1f (const) */
        /* execute.a64:2745 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
        uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2745 [F] s_b_28_6: If s_b_28_5: Jump b_2 else b_38 (const) */
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
        /* execute.a64:2756 [F] s_b_29_0=sym_9192_3_parameter_inst.rd (const) */
        /* execute.a64:2756 [D] s_b_29_1 = sym_58077_3_parameter_value uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_58077_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_29_2 = (u32)s_b_29_1 */
        auto s_b_29_2 = emitter.truncate(s_b_29_1, emitter.context().types().u32());
        /* execute.a64:2756 [D] s_b_29_3 = (u64)s_b_29_2 */
        auto s_b_29_3 = emitter.zx(s_b_29_2, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_29_4: sym_58211_3_parameter_value = s_b_29_3, dominates: s_b_39_1  */
        emitter.store_local(DV_sym_58211_3_parameter_value, s_b_29_3);
        /* execute.a64:2745 [F] s_b_29_5 = (u32)s_b_29_0 (const) */
        /* execute.a64:2745 [F] s_b_29_6 = constant u32 1f (const) */
        /* execute.a64:2745 [F] s_b_29_7 = s_b_29_5==s_b_29_6 (const) */
        uint8_t s_b_29_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2745 [F] s_b_29_8: If s_b_29_7: Jump b_2 else b_39 (const) */
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
        /* execute.a64:2714 [F] s_b_30_0 = constant u64 0 (const) */
        /* execute.a64:2714 [D] s_b_30_1: sym_58106_1_temporary_value = s_b_30_0, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_58106_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:2714 [F] s_b_30_2: Jump b_32 (const) */
        {
          auto block = block_b_32;
          dynamic_block_queue.push(block_b_32);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.a64:2714 [F] s_b_31_0=sym_9192_3_parameter_inst.rn (const) */
        /* execute.a64:2714 [D] s_b_31_1 = ReadRegBank 0:s_b_31_0 (u64) */
        auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_31_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_31_2: sym_58106_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_58106_1_temporary_value, s_b_31_1);
        /* execute.a64:2714 [F] s_b_31_3: Jump b_32 (const) */
        {
          auto block = block_b_32;
          dynamic_block_queue.push(block_b_32);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.a64:2714 [D] s_b_32_0 = sym_58106_1_temporary_value uint64_t */
        auto s_b_32_0 = emitter.load_local(DV_sym_58106_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_32_1: sym_57999_1__R_s_b_3_6 = s_b_32_0, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_57999_1__R_s_b_3_6, s_b_32_0);
        /* execute.a64:2720 [F] s_b_32_2: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.a64:2709 [F] s_b_33_0 = constant u32 0 (const) */
        /* execute.a64:2709 [D] s_b_33_1: sym_58134_1_temporary_value = s_b_33_0, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_58134_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2709 [F] s_b_33_2: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.a64:2709 [F] s_b_34_0=sym_9192_3_parameter_inst.rn (const) */
        /* execute.a64:2709 [D] s_b_34_1 = ReadRegBank 1:s_b_34_0 (u32) */
        auto s_b_34_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_34_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_34_2: sym_58134_1_temporary_value = s_b_34_1, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_58134_1_temporary_value, s_b_34_1);
        /* execute.a64:2709 [F] s_b_34_3: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.a64:2709 [D] s_b_35_0 = sym_58134_1_temporary_value uint32_t */
        auto s_b_35_0 = emitter.load_local(DV_sym_58134_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_35_1 = (u64)s_b_35_0 */
        auto s_b_35_1 = emitter.zx(s_b_35_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_35_2: sym_57999_1__R_s_b_3_6 = s_b_35_1, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_57999_1__R_s_b_3_6, s_b_35_1);
        /* execute.a64:2722 [F] s_b_35_3: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_36) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_36);
        /* execute.a64:2754 [F] s_b_36_0=sym_9192_3_parameter_inst.rd (const) */
        /* execute.a64:2754 [D] s_b_36_1 = sym_58159_3_parameter_value uint64_t */
        auto s_b_36_1 = emitter.load_local(DV_sym_58159_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2754 [D] s_b_36_2: sym_58233_3_parameter_value = s_b_36_1, dominates: s_b_40_1  */
        emitter.store_local(DV_sym_58233_3_parameter_value, s_b_36_1);
        /* execute.a64:2745 [F] s_b_36_3 = (u32)s_b_36_0 (const) */
        /* execute.a64:2745 [F] s_b_36_4 = constant u32 1f (const) */
        /* execute.a64:2745 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
        uint8_t s_b_36_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2745 [F] s_b_36_6: If s_b_36_5: Jump b_2 else b_40 (const) */
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
        /* execute.a64:2756 [F] s_b_37_0=sym_9192_3_parameter_inst.rd (const) */
        /* execute.a64:2756 [D] s_b_37_1 = sym_58159_3_parameter_value uint64_t */
        auto s_b_37_1 = emitter.load_local(DV_sym_58159_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_37_2 = (u32)s_b_37_1 */
        auto s_b_37_2 = emitter.truncate(s_b_37_1, emitter.context().types().u32());
        /* execute.a64:2756 [D] s_b_37_3 = (u64)s_b_37_2 */
        auto s_b_37_3 = emitter.zx(s_b_37_2, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_37_4: sym_58255_3_parameter_value = s_b_37_3, dominates: s_b_41_1  */
        emitter.store_local(DV_sym_58255_3_parameter_value, s_b_37_3);
        /* execute.a64:2745 [F] s_b_37_5 = (u32)s_b_37_0 (const) */
        /* execute.a64:2745 [F] s_b_37_6 = constant u32 1f (const) */
        /* execute.a64:2745 [F] s_b_37_7 = s_b_37_5==s_b_37_6 (const) */
        uint8_t s_b_37_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2745 [F] s_b_37_8: If s_b_37_7: Jump b_2 else b_41 (const) */
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
        /* execute.a64:2747 [F] s_b_38_0=sym_9192_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_38_1 = sym_58189_3_parameter_value uint64_t */
        auto s_b_38_1 = emitter.load_local(DV_sym_58189_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2747 [D] s_b_38_2: WriteRegBank 0:s_b_38_0 = s_b_38_1 */
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
        /* execute.a64:2747 [F] s_b_39_0=sym_9192_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_39_1 = sym_58211_3_parameter_value uint64_t */
        auto s_b_39_1 = emitter.load_local(DV_sym_58211_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2747 [D] s_b_39_2: WriteRegBank 0:s_b_39_0 = s_b_39_1 */
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
        /* execute.a64:2747 [F] s_b_40_0=sym_9192_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_40_1 = sym_58233_3_parameter_value uint64_t */
        auto s_b_40_1 = emitter.load_local(DV_sym_58233_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2747 [D] s_b_40_2: WriteRegBank 0:s_b_40_0 = s_b_40_1 */
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
        /* execute.a64:2747 [F] s_b_41_0=sym_9192_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_41_1 = sym_58255_3_parameter_value uint64_t */
        auto s_b_41_1 = emitter.load_local(DV_sym_58255_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2747 [D] s_b_41_2: WriteRegBank 0:s_b_41_0 = s_b_41_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_eorsr(const arm64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_60385_1_temporary_value;
  auto DV_sym_60385_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_60329_1_temporary_value;
  auto DV_sym_60329_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_60122_1_temporary_value;
  auto DV_sym_60122_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  uint64_t CV_sym_60273_1_temporary_value;
  auto DV_sym_60273_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_60357_1_temporary_value;
  auto DV_sym_60357_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  int64_t CV_sym_60134_1_temporary_value;
  auto DV_sym_60134_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  uint32_t CV_sym_60301_1_temporary_value;
  auto DV_sym_60301_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_60245_1_temporary_value;
  auto DV_sym_60245_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_60469_1_temporary_value;
  auto DV_sym_60469_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_60217_1_temporary_value;
  auto DV_sym_60217_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_60148_1__R_s_b_28_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_10171_0_op2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_10164_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_60039_1__R_s_b_23_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_59990_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_60064_1__R_s_b_26_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_60012_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_60089_1__R_s_b_27_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_59861_1_temporary_value;
  auto DV_sym_59861_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_59788_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_59804_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_59833_1_temporary_value;
  auto DV_sym_59833_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_59960_1__R_s_b_6_10;
  auto DV_sym_59960_1__R_s_b_6_10 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2556 [F] s_b_0_0=sym_10159_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_0_1: If s_b_0_0: Jump b_3 else b_4 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_24,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2559 [D] s_b_1_0 = sym_10171_0_op2 uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_10171_0_op2, emitter.context().types().u64());
    /* execute.a64:2559 [D] s_b_1_1 = ~s_b_1_0 */
    auto s_b_1_1 = emitter.bitwise_not(s_b_1_0);
    /* execute.a64:2559 [D] s_b_1_2: sym_10171_0_op2 = s_b_1_1, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_10171_0_op2, s_b_1_1);
    /* execute.a64:2559 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_24,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2561 [D] s_b_2_0 = sym_10164_0_op1 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_10164_0_op1, emitter.context().types().u64());
    /* execute.a64:2561 [D] s_b_2_1 = sym_10171_0_op2 uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_10171_0_op2, emitter.context().types().u64());
    /* execute.a64:2561 [D] s_b_2_2 = s_b_2_0^s_b_2_1 */
    auto s_b_2_2 = emitter.bitwise_xor(s_b_2_0, s_b_2_1);
    /* execute.a64:2563 [F] s_b_2_3=sym_10159_3_parameter_inst.sf (const) */
    /* execute.a64:2563 [D] s_b_2_4: sym_59804_3_parameter_value = s_b_2_2, dominates: s_b_6_1 s_b_7_1  */
    emitter.store_local(DV_sym_59804_3_parameter_value, s_b_2_2);
    /* execute.a64:2753 [F] s_b_2_5: If s_b_2_3: Jump b_6 else b_7 (const) */
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
    /* execute.a64:2720 [F] s_b_3_0=sym_10159_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:2714 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_3_4: If s_b_3_3: Jump b_9 else b_10 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_10;
    }
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2722 [F] s_b_4_0=sym_10159_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2709 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_4_4: If s_b_4_3: Jump b_12 else b_13 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_11, b_14,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2556 [D] s_b_5_0 = sym_59788_1__R_s_b_0_4 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_59788_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2556 [D] s_b_5_1: sym_10164_0_op1 = s_b_5_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_10164_0_op1, s_b_5_0);
    /* execute.a64:2557 [F] s_b_5_2=sym_10159_3_parameter_inst.imm6 (const) */
    /* execute.a64:2635 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:2635 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.a64:2635 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.imm6) == (uint32_t)0ULL));
    /* execute.a64:2635 [F] s_b_5_6: If s_b_5_5: Jump b_15 else b_16 (const) */
    if (s_b_5_5) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_2,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2754 [F] s_b_6_0=sym_10159_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_6_1 = sym_59804_3_parameter_value uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_59804_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_6_2: sym_59990_3_parameter_value = s_b_6_1, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_59990_3_parameter_value, s_b_6_1);
    /* execute.a64:2745 [F] s_b_6_3 = (u32)s_b_6_0 (const) */
    /* execute.a64:2745 [F] s_b_6_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_6_6: If s_b_6_5: Jump b_8 else b_25 (const) */
    if (s_b_6_5) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_2,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2756 [F] s_b_7_0=sym_10159_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_7_1 = sym_59804_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_59804_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_7_2 = (u32)s_b_7_1 */
    auto s_b_7_2 = emitter.truncate(s_b_7_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_7_3 = (u64)s_b_7_2 */
    auto s_b_7_3 = emitter.zx(s_b_7_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_7_4: sym_60012_3_parameter_value = s_b_7_3, dominates: s_b_26_1  */
    emitter.store_local(DV_sym_60012_3_parameter_value, s_b_7_3);
    /* execute.a64:2745 [F] s_b_7_5 = (u32)s_b_7_0 (const) */
    /* execute.a64:2745 [F] s_b_7_6 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_7_8: If s_b_7_7: Jump b_8 else b_26 (const) */
    if (s_b_7_7) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_6, b_7, b_25, b_26,  */
  fixed_block_b_8: 
  {
    /* ???:4294967295 [F] s_b_8_0: Return */
    goto fixed_done;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2714 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_9_1: sym_59833_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_59833_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_59833_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2714 [F] s_b_10_0=sym_10159_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_10_2: sym_59833_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_59833_1_temporary_value, s_b_10_1);
    /* execute.a64:2714 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2714 [D] s_b_11_0 = sym_59833_1_temporary_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_59833_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_11_1: sym_59788_1__R_s_b_0_4 = s_b_11_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_59788_1__R_s_b_0_4, s_b_11_0);
    /* execute.a64:2720 [F] s_b_11_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_12_1: sym_59861_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_59861_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_59861_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_4,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [F] s_b_13_0=sym_10159_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_13_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_13_2: sym_59861_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_59861_1_temporary_value, s_b_13_1);
    /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_59861_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_59861_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_14_2: sym_59788_1__R_s_b_0_4 = s_b_14_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_59788_1__R_s_b_0_4, s_b_14_1);
    /* execute.a64:2722 [F] s_b_14_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2635 [F] s_b_15_0=sym_10159_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_15_1: If s_b_15_0: Jump b_27 else b_28 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_28;
    }
  }
  /* b_5,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2637 [F] s_b_16_0=sym_10159_3_parameter_inst.shift (const) */
    /* execute.a64:2638 [F] s_b_16_1 = constant s32 0 (const) */
    /* execute.a64:2642 [F] s_b_16_2 = constant s32 1 (const) */
    /* execute.a64:2646 [F] s_b_16_3 = constant s32 2 (const) */
    /* execute.a64:2650 [F] s_b_16_4 = constant s32 3 (const) */
    /* execute.a64:2637 [F] s_b_16_5: Switch s_b_16_0: < <todo> > def b_17 (const) -> b_17, b_18, b_19, b_20, b_21,  */
    switch (insn.shift) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_19;
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
    default:
      goto fixed_block_b_17;
    }
  }
  /* b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2660 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2661 [F] s_b_17_1 = constant u64 0 (const) */
    /* execute.a64:2661 [F] s_b_17_2: sym_59960_1__R_s_b_6_10 = s_b_17_1 (const), dominates: s_b_24_0  */
    CV_sym_59960_1__R_s_b_6_10 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_59960_1__R_s_b_6_10, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2661 [F] s_b_17_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2640 [F] s_b_18_0=sym_10159_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_18_1: If s_b_18_0: Jump b_30 else b_31 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_16,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2644 [F] s_b_19_0=sym_10159_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_19_1: If s_b_19_0: Jump b_33 else b_34 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_34;
    }
  }
  /* b_16,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2648 [F] s_b_20_0=sym_10159_3_parameter_inst.sf (const) */
    /* execute.a64:2728 [F] s_b_20_1: If s_b_20_0: Jump b_36 else b_37 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_36;
    }
    else 
    {
      goto fixed_block_b_37;
    }
  }
  /* b_16,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2652 [F] s_b_21_0=sym_10159_3_parameter_inst.sf (const) */
    /* execute.a64:2652 [F] s_b_21_1: If s_b_21_0: Jump b_22 else b_23 (const) */
    if (insn.sf) 
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
    /* execute.a64:2720 [F] s_b_22_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
    /* execute.a64:2714 [F] s_b_22_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_22_4: If s_b_22_3: Jump b_63 else b_64 (const) */
    if (s_b_22_3) 
    {
      goto fixed_block_b_63;
    }
    else 
    {
      goto fixed_block_b_64;
    }
  }
  /* b_21,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2722 [F] s_b_23_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2709 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_23_4: If s_b_23_3: Jump b_66 else b_67 (const) */
    if (s_b_23_3) 
    {
      goto fixed_block_b_66;
    }
    else 
    {
      goto fixed_block_b_67;
    }
  }
  /* b_17, b_29, b_32, b_35, b_44, b_65, b_68,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2557 [D] s_b_24_0 = sym_59960_1__R_s_b_6_10 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_59960_1__R_s_b_6_10, emitter.context().types().u64());
    /* execute.a64:2557 [D] s_b_24_1: sym_10171_0_op2 = s_b_24_0, dominates: s_b_1_0 s_b_2_1  */
    emitter.store_local(DV_sym_10171_0_op2, s_b_24_0);
    /* execute.a64:2559 [F] s_b_24_2=sym_10159_3_parameter_inst.N (const) */
    /* execute.a64:2559 [F] s_b_24_3: If s_b_24_2: Jump b_1 else b_2 (const) */
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
  fixed_block_b_25: 
  {
    /* execute.a64:2747 [F] s_b_25_0=sym_10159_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_25_1 = sym_59990_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_59990_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_25_2: WriteRegBank 0:s_b_25_0 = s_b_25_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_25_1);
    /* execute.a64:0 [F] s_b_25_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2747 [F] s_b_26_0=sym_10159_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_26_1 = sym_60012_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_60012_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1);
    /* execute.a64:0 [F] s_b_26_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_15,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2720 [F] s_b_27_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
    /* execute.a64:2714 [F] s_b_27_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_27_3 = s_b_27_1==s_b_27_2 (const) */
    uint8_t s_b_27_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_27_4: If s_b_27_3: Jump b_45 else b_46 (const) */
    if (s_b_27_3) 
    {
      goto fixed_block_b_45;
    }
    else 
    {
      goto fixed_block_b_46;
    }
  }
  /* b_15,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2722 [F] s_b_28_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:2709 [F] s_b_28_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_28_4: If s_b_28_3: Jump b_48 else b_49 (const) */
    if (s_b_28_3) 
    {
      goto fixed_block_b_48;
    }
    else 
    {
      goto fixed_block_b_49;
    }
  }
  /* b_47, b_50,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2635 [D] s_b_29_0 = sym_60039_1__R_s_b_23_4 uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_60039_1__R_s_b_23_4, emitter.context().types().u64());
    /* execute.a64:2635 [D] s_b_29_1: sym_59960_1__R_s_b_6_10 = s_b_29_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_59960_1__R_s_b_6_10, s_b_29_0);
    /* execute.a64:2635 [F] s_b_29_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_18,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2720 [F] s_b_30_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_30_1 = (u32)s_b_30_0 (const) */
    /* execute.a64:2714 [F] s_b_30_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_30_3 = s_b_30_1==s_b_30_2 (const) */
    uint8_t s_b_30_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_30_4: If s_b_30_3: Jump b_51 else b_52 (const) */
    if (s_b_30_3) 
    {
      goto fixed_block_b_51;
    }
    else 
    {
      goto fixed_block_b_52;
    }
  }
  /* b_18,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2722 [F] s_b_31_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
    /* execute.a64:2709 [F] s_b_31_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_31_3 = s_b_31_1==s_b_31_2 (const) */
    uint8_t s_b_31_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_31_4: If s_b_31_3: Jump b_54 else b_55 (const) */
    if (s_b_31_3) 
    {
      goto fixed_block_b_54;
    }
    else 
    {
      goto fixed_block_b_55;
    }
  }
  /* b_53, b_56,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2640 [D] s_b_32_0 = sym_60064_1__R_s_b_26_4 uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_60064_1__R_s_b_26_4, emitter.context().types().u64());
    /* execute.a64:2640 [F] s_b_32_1=sym_10159_3_parameter_inst.imm6 (const) */
    /* execute.a64:2640 [F] s_b_32_2 = (u64)s_b_32_1 (const) */
    /* execute.a64:2640 [D] s_b_32_3 = s_b_32_0<<s_b_32_2 */
    auto s_b_32_3 = emitter.shl(s_b_32_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2640 [D] s_b_32_4: sym_59960_1__R_s_b_6_10 = s_b_32_3, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_59960_1__R_s_b_6_10, s_b_32_3);
    /* execute.a64:2640 [F] s_b_32_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2720 [F] s_b_33_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_33_1 = (u32)s_b_33_0 (const) */
    /* execute.a64:2714 [F] s_b_33_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_33_3 = s_b_33_1==s_b_33_2 (const) */
    uint8_t s_b_33_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_33_4: If s_b_33_3: Jump b_57 else b_58 (const) */
    if (s_b_33_3) 
    {
      goto fixed_block_b_57;
    }
    else 
    {
      goto fixed_block_b_58;
    }
  }
  /* b_19,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2722 [F] s_b_34_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
    /* execute.a64:2709 [F] s_b_34_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_34_3 = s_b_34_1==s_b_34_2 (const) */
    uint8_t s_b_34_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_34_4: If s_b_34_3: Jump b_60 else b_61 (const) */
    if (s_b_34_3) 
    {
      goto fixed_block_b_60;
    }
    else 
    {
      goto fixed_block_b_61;
    }
  }
  /* b_59, b_62,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2644 [D] s_b_35_0 = sym_60089_1__R_s_b_27_4 uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_60089_1__R_s_b_27_4, emitter.context().types().u64());
    /* execute.a64:2644 [F] s_b_35_1=sym_10159_3_parameter_inst.imm6 (const) */
    /* execute.a64:2644 [F] s_b_35_2 = (u64)s_b_35_1 (const) */
    /* execute.a64:2644 [D] s_b_35_3 = s_b_35_0>>s_b_35_2 */
    auto s_b_35_3 = emitter.shr(s_b_35_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2644 [D] s_b_35_4: sym_59960_1__R_s_b_6_10 = s_b_35_3, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_59960_1__R_s_b_6_10, s_b_35_3);
    /* execute.a64:2644 [F] s_b_35_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_20,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2729 [F] s_b_36_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2729 [F] s_b_36_1 = (u32)s_b_36_0 (const) */
    /* execute.a64:2729 [F] s_b_36_2 = constant u32 1f (const) */
    /* execute.a64:2729 [F] s_b_36_3 = s_b_36_1==s_b_36_2 (const) */
    uint8_t s_b_36_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2729 [F] s_b_36_4: If s_b_36_3: Jump b_38 else b_39 (const) */
    if (s_b_36_3) 
    {
      goto fixed_block_b_38;
    }
    else 
    {
      goto fixed_block_b_39;
    }
  }
  /* b_20,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2731 [F] s_b_37_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2731 [F] s_b_37_1 = (u32)s_b_37_0 (const) */
    /* execute.a64:2731 [F] s_b_37_2 = constant u32 1f (const) */
    /* execute.a64:2731 [F] s_b_37_3 = s_b_37_1==s_b_37_2 (const) */
    uint8_t s_b_37_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2731 [F] s_b_37_4: If s_b_37_3: Jump b_40 else b_41 (const) */
    if (s_b_37_3) 
    {
      goto fixed_block_b_40;
    }
    else 
    {
      goto fixed_block_b_41;
    }
  }
  /* b_36,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2729 [F] s_b_38_0 = constant s64 0 (const) */
    /* execute.a64:2729 [F] s_b_38_1: sym_60122_1_temporary_value = s_b_38_0 (const), dominates: s_b_42_0  */
    CV_sym_60122_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_60122_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2729 [F] s_b_38_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_36,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2729 [F] s_b_39_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2729 [D] s_b_39_1 = ReadRegBank 0:s_b_39_0 (u64) */
    auto s_b_39_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_39_1,emitter.const_u8(8));
    }
    /* execute.a64:2729 [D] s_b_39_2 = (s64)s_b_39_1 */
    auto s_b_39_2 = emitter.reinterpret(s_b_39_1, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_39_3: sym_60122_1_temporary_value = s_b_39_2, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_60122_1_temporary_value, s_b_39_2);
    /* execute.a64:2729 [F] s_b_39_4: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_37,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2731 [F] s_b_40_0 = constant s64 0 (const) */
    /* execute.a64:2731 [F] s_b_40_1: sym_60134_1_temporary_value = s_b_40_0 (const), dominates: s_b_43_0  */
    CV_sym_60134_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_60134_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2731 [F] s_b_40_2: Jump b_43 (const) */
    goto fixed_block_b_43;
  }
  /* b_37,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2731 [F] s_b_41_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2731 [D] s_b_41_1 = ReadRegBank 1:s_b_41_0 (u32) */
    auto s_b_41_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_41_1,emitter.const_u8(4));
    }
    /* execute.a64:2731 [D] s_b_41_2 = (s32)s_b_41_1 */
    auto s_b_41_2 = emitter.reinterpret(s_b_41_1, emitter.context().types().s32());
    /* execute.a64:2731 [D] s_b_41_3 = (s64)s_b_41_2 */
    auto s_b_41_3 = emitter.sx(s_b_41_2, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_41_4: sym_60134_1_temporary_value = s_b_41_3, dominates: s_b_43_0  */
    emitter.store_local(DV_sym_60134_1_temporary_value, s_b_41_3);
    /* execute.a64:2731 [F] s_b_41_5: Jump b_43 (const) */
    goto fixed_block_b_43;
  }
  /* b_38, b_39,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2729 [D] s_b_42_0 = sym_60122_1_temporary_value int64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_60122_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_42_1: sym_60148_1__R_s_b_28_4 = s_b_42_0, dominates: s_b_44_0  */
    emitter.store_local(DV_sym_60148_1__R_s_b_28_4, s_b_42_0);
    /* execute.a64:2729 [F] s_b_42_2: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_40, b_41,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2731 [D] s_b_43_0 = sym_60134_1_temporary_value int64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_60134_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_43_1: sym_60148_1__R_s_b_28_4 = s_b_43_0, dominates: s_b_44_0  */
    emitter.store_local(DV_sym_60148_1__R_s_b_28_4, s_b_43_0);
    /* execute.a64:2731 [F] s_b_43_2: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_42, b_43,  */
  fixed_block_b_44: 
  {
    /* execute.a64:2648 [D] s_b_44_0 = sym_60148_1__R_s_b_28_4 int64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_60148_1__R_s_b_28_4, emitter.context().types().s64());
    /* execute.a64:2648 [F] s_b_44_1=sym_10159_3_parameter_inst.imm6 (const) */
    /* execute.a64:2648 [D] s_b_44_2 = (u64)s_b_44_0 */
    auto s_b_44_2 = emitter.reinterpret(s_b_44_0, emitter.context().types().u64());
    /* execute.a64:2648 [F] s_b_44_3 = (u64)s_b_44_1 (const) */
    /* execute.a64:2648 [D] s_b_44_4 = s_b_44_2->>s_b_44_3 */
    auto s_b_44_4 = emitter.sar(s_b_44_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2648 [D] s_b_44_5 = (u64)s_b_44_4 */
    auto s_b_44_5 = (captive::arch::dbt::el::Value *)s_b_44_4;
    /* execute.a64:2648 [D] s_b_44_6: sym_59960_1__R_s_b_6_10 = s_b_44_5, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_59960_1__R_s_b_6_10, s_b_44_5);
    /* execute.a64:2648 [F] s_b_44_7: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_27,  */
  fixed_block_b_45: 
  {
    /* execute.a64:2714 [F] s_b_45_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_45_1: sym_60217_1_temporary_value = s_b_45_0 (const), dominates: s_b_47_0  */
    CV_sym_60217_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_60217_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_45_2: Jump b_47 (const) */
    goto fixed_block_b_47;
  }
  /* b_27,  */
  fixed_block_b_46: 
  {
    /* execute.a64:2714 [F] s_b_46_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_46_1 = ReadRegBank 0:s_b_46_0 (u64) */
    auto s_b_46_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_46_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_46_2: sym_60217_1_temporary_value = s_b_46_1, dominates: s_b_47_0  */
    emitter.store_local(DV_sym_60217_1_temporary_value, s_b_46_1);
    /* execute.a64:2714 [F] s_b_46_3: Jump b_47 (const) */
    goto fixed_block_b_47;
  }
  /* b_45, b_46,  */
  fixed_block_b_47: 
  {
    /* execute.a64:2714 [D] s_b_47_0 = sym_60217_1_temporary_value uint64_t */
    auto s_b_47_0 = emitter.load_local(DV_sym_60217_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_47_1: sym_60039_1__R_s_b_23_4 = s_b_47_0, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_60039_1__R_s_b_23_4, s_b_47_0);
    /* execute.a64:2720 [F] s_b_47_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_28,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2709 [F] s_b_48_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_48_1: sym_60245_1_temporary_value = s_b_48_0 (const), dominates: s_b_50_0  */
    CV_sym_60245_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_60245_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_48_2: Jump b_50 (const) */
    goto fixed_block_b_50;
  }
  /* b_28,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2709 [F] s_b_49_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_49_1 = ReadRegBank 1:s_b_49_0 (u32) */
    auto s_b_49_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_49_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_49_2: sym_60245_1_temporary_value = s_b_49_1, dominates: s_b_50_0  */
    emitter.store_local(DV_sym_60245_1_temporary_value, s_b_49_1);
    /* execute.a64:2709 [F] s_b_49_3: Jump b_50 (const) */
    goto fixed_block_b_50;
  }
  /* b_48, b_49,  */
  fixed_block_b_50: 
  {
    /* execute.a64:2709 [D] s_b_50_0 = sym_60245_1_temporary_value uint32_t */
    auto s_b_50_0 = emitter.load_local(DV_sym_60245_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_50_1 = (u64)s_b_50_0 */
    auto s_b_50_1 = emitter.zx(s_b_50_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_50_2: sym_60039_1__R_s_b_23_4 = s_b_50_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_60039_1__R_s_b_23_4, s_b_50_1);
    /* execute.a64:2722 [F] s_b_50_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_30,  */
  fixed_block_b_51: 
  {
    /* execute.a64:2714 [F] s_b_51_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_51_1: sym_60273_1_temporary_value = s_b_51_0 (const), dominates: s_b_53_0  */
    CV_sym_60273_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_60273_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_51_2: Jump b_53 (const) */
    goto fixed_block_b_53;
  }
  /* b_30,  */
  fixed_block_b_52: 
  {
    /* execute.a64:2714 [F] s_b_52_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_52_1 = ReadRegBank 0:s_b_52_0 (u64) */
    auto s_b_52_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_52_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_52_2: sym_60273_1_temporary_value = s_b_52_1, dominates: s_b_53_0  */
    emitter.store_local(DV_sym_60273_1_temporary_value, s_b_52_1);
    /* execute.a64:2714 [F] s_b_52_3: Jump b_53 (const) */
    goto fixed_block_b_53;
  }
  /* b_51, b_52,  */
  fixed_block_b_53: 
  {
    /* execute.a64:2714 [D] s_b_53_0 = sym_60273_1_temporary_value uint64_t */
    auto s_b_53_0 = emitter.load_local(DV_sym_60273_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_53_1: sym_60064_1__R_s_b_26_4 = s_b_53_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_60064_1__R_s_b_26_4, s_b_53_0);
    /* execute.a64:2720 [F] s_b_53_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_31,  */
  fixed_block_b_54: 
  {
    /* execute.a64:2709 [F] s_b_54_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_54_1: sym_60301_1_temporary_value = s_b_54_0 (const), dominates: s_b_56_0  */
    CV_sym_60301_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_60301_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_54_2: Jump b_56 (const) */
    goto fixed_block_b_56;
  }
  /* b_31,  */
  fixed_block_b_55: 
  {
    /* execute.a64:2709 [F] s_b_55_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_55_1 = ReadRegBank 1:s_b_55_0 (u32) */
    auto s_b_55_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_55_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_55_2: sym_60301_1_temporary_value = s_b_55_1, dominates: s_b_56_0  */
    emitter.store_local(DV_sym_60301_1_temporary_value, s_b_55_1);
    /* execute.a64:2709 [F] s_b_55_3: Jump b_56 (const) */
    goto fixed_block_b_56;
  }
  /* b_54, b_55,  */
  fixed_block_b_56: 
  {
    /* execute.a64:2709 [D] s_b_56_0 = sym_60301_1_temporary_value uint32_t */
    auto s_b_56_0 = emitter.load_local(DV_sym_60301_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_56_1 = (u64)s_b_56_0 */
    auto s_b_56_1 = emitter.zx(s_b_56_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_56_2: sym_60064_1__R_s_b_26_4 = s_b_56_1, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_60064_1__R_s_b_26_4, s_b_56_1);
    /* execute.a64:2722 [F] s_b_56_3: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_33,  */
  fixed_block_b_57: 
  {
    /* execute.a64:2714 [F] s_b_57_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_57_1: sym_60329_1_temporary_value = s_b_57_0 (const), dominates: s_b_59_0  */
    CV_sym_60329_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_60329_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_57_2: Jump b_59 (const) */
    goto fixed_block_b_59;
  }
  /* b_33,  */
  fixed_block_b_58: 
  {
    /* execute.a64:2714 [F] s_b_58_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_58_1 = ReadRegBank 0:s_b_58_0 (u64) */
    auto s_b_58_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_58_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_58_2: sym_60329_1_temporary_value = s_b_58_1, dominates: s_b_59_0  */
    emitter.store_local(DV_sym_60329_1_temporary_value, s_b_58_1);
    /* execute.a64:2714 [F] s_b_58_3: Jump b_59 (const) */
    goto fixed_block_b_59;
  }
  /* b_57, b_58,  */
  fixed_block_b_59: 
  {
    /* execute.a64:2714 [D] s_b_59_0 = sym_60329_1_temporary_value uint64_t */
    auto s_b_59_0 = emitter.load_local(DV_sym_60329_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_59_1: sym_60089_1__R_s_b_27_4 = s_b_59_0, dominates: s_b_35_0  */
    emitter.store_local(DV_sym_60089_1__R_s_b_27_4, s_b_59_0);
    /* execute.a64:2720 [F] s_b_59_2: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_34,  */
  fixed_block_b_60: 
  {
    /* execute.a64:2709 [F] s_b_60_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_60_1: sym_60357_1_temporary_value = s_b_60_0 (const), dominates: s_b_62_0  */
    CV_sym_60357_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_60357_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_60_2: Jump b_62 (const) */
    goto fixed_block_b_62;
  }
  /* b_34,  */
  fixed_block_b_61: 
  {
    /* execute.a64:2709 [F] s_b_61_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_61_1 = ReadRegBank 1:s_b_61_0 (u32) */
    auto s_b_61_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_61_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_61_2: sym_60357_1_temporary_value = s_b_61_1, dominates: s_b_62_0  */
    emitter.store_local(DV_sym_60357_1_temporary_value, s_b_61_1);
    /* execute.a64:2709 [F] s_b_61_3: Jump b_62 (const) */
    goto fixed_block_b_62;
  }
  /* b_60, b_61,  */
  fixed_block_b_62: 
  {
    /* execute.a64:2709 [D] s_b_62_0 = sym_60357_1_temporary_value uint32_t */
    auto s_b_62_0 = emitter.load_local(DV_sym_60357_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_62_1 = (u64)s_b_62_0 */
    auto s_b_62_1 = emitter.zx(s_b_62_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_62_2: sym_60089_1__R_s_b_27_4 = s_b_62_1, dominates: s_b_35_0  */
    emitter.store_local(DV_sym_60089_1__R_s_b_27_4, s_b_62_1);
    /* execute.a64:2722 [F] s_b_62_3: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_22,  */
  fixed_block_b_63: 
  {
    /* execute.a64:2714 [F] s_b_63_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_63_1: sym_60385_1_temporary_value = s_b_63_0 (const), dominates: s_b_65_0  */
    CV_sym_60385_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_60385_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_63_2: Jump b_65 (const) */
    goto fixed_block_b_65;
  }
  /* b_22,  */
  fixed_block_b_64: 
  {
    /* execute.a64:2714 [F] s_b_64_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_64_1 = ReadRegBank 0:s_b_64_0 (u64) */
    auto s_b_64_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_64_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_64_2: sym_60385_1_temporary_value = s_b_64_1, dominates: s_b_65_0  */
    emitter.store_local(DV_sym_60385_1_temporary_value, s_b_64_1);
    /* execute.a64:2714 [F] s_b_64_3: Jump b_65 (const) */
    goto fixed_block_b_65;
  }
  /* b_63, b_64,  */
  fixed_block_b_65: 
  {
    /* execute.a64:2714 [D] s_b_65_0 = sym_60385_1_temporary_value uint64_t */
    auto s_b_65_0 = emitter.load_local(DV_sym_60385_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2653 [F] s_b_65_1=sym_10159_3_parameter_inst.imm6 (const) */
    /* execute.a64:2653 [F] s_b_65_2 = (u64)s_b_65_1 (const) */
    /* execute.a64:2653 [D] s_b_65_3 = s_b_65_0>>>s_b_65_2 */
    auto s_b_65_3 = emitter.ror(s_b_65_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2653 [D] s_b_65_4: sym_59960_1__R_s_b_6_10 = s_b_65_3, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_59960_1__R_s_b_6_10, s_b_65_3);
    /* execute.a64:2653 [F] s_b_65_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_66: 
  {
    /* execute.a64:2709 [F] s_b_66_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_66_1: sym_60469_1_temporary_value = s_b_66_0 (const), dominates: s_b_68_0  */
    CV_sym_60469_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_60469_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_66_2: Jump b_68 (const) */
    goto fixed_block_b_68;
  }
  /* b_23,  */
  fixed_block_b_67: 
  {
    /* execute.a64:2709 [F] s_b_67_0=sym_10159_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_67_1 = ReadRegBank 1:s_b_67_0 (u32) */
    auto s_b_67_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_67_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_67_2: sym_60469_1_temporary_value = s_b_67_1, dominates: s_b_68_0  */
    emitter.store_local(DV_sym_60469_1_temporary_value, s_b_67_1);
    /* execute.a64:2709 [F] s_b_67_3: Jump b_68 (const) */
    goto fixed_block_b_68;
  }
  /* b_66, b_67,  */
  fixed_block_b_68: 
  {
    /* execute.a64:2709 [D] s_b_68_0 = sym_60469_1_temporary_value uint32_t */
    auto s_b_68_0 = emitter.load_local(DV_sym_60469_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_68_1 = (u64)s_b_68_0 */
    auto s_b_68_1 = emitter.zx(s_b_68_0, emitter.context().types().u64());
    /* execute.a64:2655 [D] s_b_68_2 = (u32)s_b_68_1 */
    auto s_b_68_2 = emitter.truncate(s_b_68_1, emitter.context().types().u32());
    /* execute.a64:2655 [F] s_b_68_3=sym_10159_3_parameter_inst.imm6 (const) */
    /* execute.a64:2655 [F] s_b_68_4 = (u32)s_b_68_3 (const) */
    /* execute.a64:2655 [D] s_b_68_5 = s_b_68_2>>>s_b_68_4 */
    auto s_b_68_5 = emitter.ror(s_b_68_2, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2655 [D] s_b_68_6 = (u64)s_b_68_5 */
    auto s_b_68_6 = emitter.zx(s_b_68_5, emitter.context().types().u64());
    /* execute.a64:2655 [D] s_b_68_7: sym_59960_1__R_s_b_6_10 = s_b_68_6, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_59960_1__R_s_b_6_10, s_b_68_6);
    /* execute.a64:2655 [F] s_b_68_8: Jump b_24 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fccmpe(const arm64_decode_a64_FP_CCMP&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  uint8_t CV_sym_62114_0_state;
  auto DV_sym_62114_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_62157_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4800 [F] s_b_0_0=sym_10629_3_parameter_inst.cond (const) */
    /* execute.a64:2854 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2854 [F] s_b_0_2: sym_62114_0_state = s_b_0_1 (const), dominates: s_b_7_0 s_b_8_0  */
    CV_sym_62114_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_62114_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2856 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_9, b_10, b_6, b_11, b_16, b_15, b_14, b_13, b_12,  */
    switch (s_b_0_5) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_9;
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
    /* execute.a64:2891 [F] s_b_6_0=sym_10629_3_parameter_inst.cond (const) */
    /* execute.a64:2891 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2891 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.a64:2891 [F] s_b_6_3 = s_b_6_1&s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2891 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:2891 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:2891 [F] s_b_6_6 = (u32)s_b_6_0 (const) */
    /* execute.a64:2891 [F] s_b_6_7 = constant u32 f (const) */
    /* execute.a64:2891 [F] s_b_6_8 = s_b_6_6!=s_b_6_7 (const) */
    uint8_t s_b_6_8 = ((uint8_t)(((uint32_t)insn.cond) != (uint32_t)15ULL));
    /* ???:4294967295 [F] s_b_6_9 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_6_10 = s_b_6_5!=s_b_6_9 (const) */
    uint8_t s_b_6_10 = ((uint8_t)(s_b_6_5 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_11 = s_b_6_8!=s_b_6_9 (const) */
    uint8_t s_b_6_11 = ((uint8_t)(s_b_6_8 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_12 = s_b_6_10&s_b_6_11 (const) */
    uint8_t s_b_6_12 = ((uint8_t)(s_b_6_10 & s_b_6_11));
    /* execute.a64:2891 [F] s_b_6_13: If s_b_6_12: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2892 [D] s_b_7_0 = sym_62114_0_state uint8_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_62114_0_state, emitter.context().types().u8());
    /* execute.a64:2892 [D] s_b_7_1 = !s_b_7_0 */
    auto s_b_7_1 = emitter.cmp_eq(s_b_7_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_7_2: sym_62157_0_return_symbol = s_b_7_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_62157_0_return_symbol, s_b_7_1);
    /* ???:4294967295 [F] s_b_7_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2894 [D] s_b_8_0 = sym_62114_0_state uint8_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_62114_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_8_1: sym_62157_0_return_symbol = s_b_8_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_62157_0_return_symbol, s_b_8_0);
    /* ???:4294967295 [F] s_b_8_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2858 [D] s_b_9_0 = ReadReg 2 (u8) */
    auto s_b_9_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_9_0, emitter.const_u8(1));
    }
    /* execute.a64:2858 [D] s_b_9_1: sym_62114_0_state = s_b_9_0, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_62114_0_state, s_b_9_0);
    /* execute.a64:0 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2862 [D] s_b_10_0 = ReadReg 3 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2862 [D] s_b_10_1: sym_62114_0_state = s_b_10_0, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_62114_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2866 [D] s_b_11_0 = ReadReg 1 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2866 [D] s_b_11_1: sym_62114_0_state = s_b_11_0, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_62114_0_state, s_b_11_0);
    /* execute.a64:0 [F] s_b_11_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2870 [D] s_b_12_0 = ReadReg 4 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2870 [D] s_b_12_1: sym_62114_0_state = s_b_12_0, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_62114_0_state, s_b_12_0);
    /* execute.a64:0 [F] s_b_12_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2874 [D] s_b_13_0 = ReadReg 3 (u8) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2874 [D] s_b_13_1 = ReadReg 2 (u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_13_1, emitter.const_u8(1));
    }
    /* execute.a64:2874 [D] s_b_13_2 = !s_b_13_1 */
    auto s_b_13_2 = emitter.cmp_eq(s_b_13_1, emitter.const_u8(0));
    /* execute.a64:2874 [D] s_b_13_3 = s_b_13_0&s_b_13_2 */
    auto s_b_13_3 = emitter.bitwise_and(s_b_13_0, s_b_13_2);
    /* execute.a64:2874 [D] s_b_13_4: sym_62114_0_state = s_b_13_3, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_62114_0_state, s_b_13_3);
    /* execute.a64:0 [F] s_b_13_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2878 [D] s_b_14_0 = ReadReg 1 (u8) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_14_0, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_14_1 = ReadReg 4 (u8) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_1, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_14_2 = s_b_14_0==s_b_14_1 */
    auto s_b_14_2 = emitter.cmp_eq(s_b_14_0, s_b_14_1);
    /* execute.a64:2878 [D] s_b_14_3: sym_62114_0_state = s_b_14_2, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_62114_0_state, s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2882 [D] s_b_15_0 = ReadReg 1 (u8) */
    auto s_b_15_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_15_0, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_15_1 = ReadReg 4 (u8) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_15_1, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_15_2 = s_b_15_0==s_b_15_1 */
    auto s_b_15_2 = emitter.cmp_eq(s_b_15_0, s_b_15_1);
    /* execute.a64:2882 [D] s_b_15_3 = ReadReg 2 (u8) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_15_3, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_15_4 = !s_b_15_3 */
    auto s_b_15_4 = emitter.cmp_eq(s_b_15_3, emitter.const_u8(0));
    /* execute.a64:2882 [D] s_b_15_5 = s_b_15_2&s_b_15_4 */
    auto s_b_15_5 = emitter.bitwise_and(s_b_15_2, s_b_15_4);
    /* execute.a64:2882 [D] s_b_15_6: sym_62114_0_state = s_b_15_5, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_62114_0_state, s_b_15_5);
    /* execute.a64:0 [F] s_b_15_7: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2886 [F] s_b_16_0 = constant u8 1 (const) */
    /* execute.a64:2886 [F] s_b_16_1: sym_62114_0_state = s_b_16_0 (const), dominates: s_b_7_0 s_b_8_0  */
    CV_sym_62114_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_62114_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_16_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_7, b_8,  */
  fixed_block_b_17: 
  {
    /* ???:4294967295 [D] s_b_17_0 = sym_62157_0_return_symbol uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_62157_0_return_symbol, emitter.context().types().u8());
    /* execute.simd:4802 [D] s_b_17_1 = (u32)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u32());
    /* execute.simd:4802 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.simd:4802 [D] s_b_17_3 = s_b_17_1==s_b_17_2 */
    auto s_b_17_3 = emitter.cmp_eq(s_b_17_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:4802 [D] s_b_17_4: If s_b_17_3: Jump b_1 else b_3 */
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
        /* execute.simd:4803 [F] s_b_1_0=sym_10629_3_parameter_inst.nzcv (const) */
        /* execute.simd:4803 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
        /* execute.simd:4803 [F] s_b_1_2 = constant u32 8 (const) */
        /* execute.simd:4803 [F] s_b_1_3 = s_b_1_1&s_b_1_2 (const) */
        uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)8ULL));
        /* execute.simd:4803 [F] s_b_1_4 = constant u32 8 (const) */
        /* execute.simd:4803 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
        uint8_t s_b_1_5 = ((uint8_t)(s_b_1_3 == (uint32_t)8ULL));
        /* execute.simd:4803 [F] s_b_1_6: WriteReg 1 = s_b_1_5 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), emitter.const_u8(s_b_1_5), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1296), emitter.const_u8(s_b_1_5));
        /* execute.simd:4804 [F] s_b_1_7=sym_10629_3_parameter_inst.nzcv (const) */
        /* execute.simd:4804 [F] s_b_1_8 = (u32)s_b_1_7 (const) */
        /* execute.simd:4804 [F] s_b_1_9 = constant u32 4 (const) */
        /* execute.simd:4804 [F] s_b_1_10 = s_b_1_8&s_b_1_9 (const) */
        uint32_t s_b_1_10 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)4ULL));
        /* execute.simd:4804 [F] s_b_1_11 = constant u32 4 (const) */
        /* execute.simd:4804 [F] s_b_1_12 = s_b_1_10==s_b_1_11 (const) */
        uint8_t s_b_1_12 = ((uint8_t)(s_b_1_10 == (uint32_t)4ULL));
        /* execute.simd:4804 [F] s_b_1_13: WriteReg 2 = s_b_1_12 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), emitter.const_u8(s_b_1_12), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1297), emitter.const_u8(s_b_1_12));
        /* execute.simd:4805 [F] s_b_1_14=sym_10629_3_parameter_inst.nzcv (const) */
        /* execute.simd:4805 [F] s_b_1_15 = (u32)s_b_1_14 (const) */
        /* execute.simd:4805 [F] s_b_1_16 = constant u32 2 (const) */
        /* execute.simd:4805 [F] s_b_1_17 = s_b_1_15&s_b_1_16 (const) */
        uint32_t s_b_1_17 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)2ULL));
        /* execute.simd:4805 [F] s_b_1_18 = constant u32 2 (const) */
        /* execute.simd:4805 [F] s_b_1_19 = s_b_1_17==s_b_1_18 (const) */
        uint8_t s_b_1_19 = ((uint8_t)(s_b_1_17 == (uint32_t)2ULL));
        /* execute.simd:4805 [F] s_b_1_20: WriteReg 3 = s_b_1_19 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8(s_b_1_19), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1298), emitter.const_u8(s_b_1_19));
        /* execute.simd:4806 [F] s_b_1_21=sym_10629_3_parameter_inst.nzcv (const) */
        /* execute.simd:4806 [F] s_b_1_22 = (u32)s_b_1_21 (const) */
        /* execute.simd:4806 [F] s_b_1_23 = constant u32 1 (const) */
        /* execute.simd:4806 [F] s_b_1_24 = s_b_1_22&s_b_1_23 (const) */
        uint32_t s_b_1_24 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)1ULL));
        /* execute.simd:4806 [F] s_b_1_25 = constant u32 1 (const) */
        /* execute.simd:4806 [F] s_b_1_26 = s_b_1_24==s_b_1_25 (const) */
        uint8_t s_b_1_26 = ((uint8_t)(s_b_1_24 == (uint32_t)1ULL));
        /* execute.simd:4806 [F] s_b_1_27: WriteReg 4 = s_b_1_26 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8(s_b_1_26), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1299), emitter.const_u8(s_b_1_26));
        /* execute.simd:4803 [F] s_b_1_28: Jump b_2 (const) */
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
        /* execute.simd:4808 [F] s_b_3_0=sym_10629_3_parameter_inst.type (const) */
        /* execute.simd:4808 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.simd:4808 [F] s_b_3_2 = constant u32 0 (const) */
        /* execute.simd:4808 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
        uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
        /* execute.simd:4808 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
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
        /* execute.simd:4810 [F] s_b_4_0=sym_10629_3_parameter_inst.rn (const) */
        /* execute.simd:6280 [D] s_b_4_1 = ReadRegBank 9:s_b_4_0 (f32) */
        auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(4));
        }
        /* execute.simd:4811 [F] s_b_4_2=sym_10629_3_parameter_inst.rm (const) */
        /* execute.simd:6280 [D] s_b_4_3 = ReadRegBank 9:s_b_4_2 (f32) */
        auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(4));
        }
        /* execute.simd:4812 [D] s_b_4_4 = __builtin_cmpf32_flags */
        emitter.call(__captive___builtin_cmpf32_flags, s_b_4_1, s_b_4_3);
        /* execute.simd:4810 [F] s_b_4_5: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:4815 [F] s_b_5_0=sym_10629_3_parameter_inst.rn (const) */
        /* execute.simd:6285 [D] s_b_5_1 = ReadRegBank 11:s_b_5_0 (f64) */
        auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(8));
        }
        /* execute.simd:4816 [F] s_b_5_2=sym_10629_3_parameter_inst.rm (const) */
        /* execute.simd:6285 [D] s_b_5_3 = ReadRegBank 11:s_b_5_2 (f64) */
        auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(8));
        }
        /* execute.simd:4817 [D] s_b_5_4 = __builtin_cmpf64_flags */
        emitter.call(__captive___builtin_cmpf64_flags, s_b_5_1, s_b_5_3);
        /* execute.simd:4815 [F] s_b_5_5: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fcvtz_fxp(const arm64_decode_a64_CVT_FP_FXP&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_63574_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_63732_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63664_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_63597_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_63642_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63710_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63620_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_63687_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_11346_0_mulp;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4557 [F] s_b_0_0 = constant u64 1 (const) */
    /* execute.simd:4557 [F] s_b_0_1=sym_11341_3_parameter_inst.immu64 (const) */
    /* execute.simd:4557 [F] s_b_0_2 = s_b_0_0<<s_b_0_1 (const) */
    uint64_t s_b_0_2 = ((uint64_t)((uint64_t)1ULL << insn.immu64));
    /* execute.simd:4557 [F] s_b_0_3: sym_11346_0_mulp = s_b_0_2 (const), dominates: s_b_6_3 s_b_7_3 s_b_8_3 s_b_9_3 s_b_12_3 s_b_13_3 s_b_14_3 s_b_15_3  */
    CV_sym_11346_0_mulp = s_b_0_2;
    /* execute.simd:4559 [F] s_b_0_4=sym_11341_3_parameter_inst.opcode (const) */
    /* execute.simd:4559 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.simd:4559 [F] s_b_0_6 = constant u32 0 (const) */
    /* execute.simd:4559 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)0ULL));
    /* execute.simd:4559 [F] s_b_0_8: If s_b_0_7: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4561 [F] s_b_1_0=sym_11341_3_parameter_inst.sf (const) */
    /* execute.simd:4561 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4561 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4561 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4561 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4580 [F] s_b_3_0=sym_11341_3_parameter_inst.sf (const) */
    /* execute.simd:4580 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4580 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4580 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4580 [F] s_b_3_4: If s_b_3_3: Jump b_10 else b_11 (const) */
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
    /* execute.simd:4562 [F] s_b_4_0=sym_11341_3_parameter_inst.type (const) */
    /* execute.simd:4562 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4562 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.simd:4562 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4562 [F] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4570 [F] s_b_5_0=sym_11341_3_parameter_inst.type (const) */
    /* execute.simd:4570 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4570 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.simd:4570 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4570 [F] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4564 [F] s_b_6_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.simd:4564 [F] s_b_6_1=sym_11341_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_6_2 = ReadRegBank 9:s_b_6_1 (f32) */
    auto s_b_6_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_2,emitter.const_u8(4));
    }
    /* execute.simd:4564 [F] s_b_6_3 = sym_11346_0_mulp (const) uint64_t */
    uint64_t s_b_6_3 = CV_sym_11346_0_mulp;
    /* execute.simd:4564 [F] s_b_6_4 = (f32)s_b_6_3 (const) */
    /* execute.simd:4564 [D] s_b_6_5 = s_b_6_2*s_b_6_4 */
    auto s_b_6_5 = emitter.mul(s_b_6_2, emitter.const_f32(((float)s_b_6_3)));
    /* execute.simd:4564 [F] s_b_6_6=sym_11341_3_parameter_inst.rmode (const) */
    /* execute.simd:4564 [D] s_b_6_7 = __builtin_fcvt_f32_s32 */
    auto s_b_6_7 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_6_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4564 [D] s_b_6_8 = (u32)s_b_6_7 */
    auto s_b_6_8 = emitter.reinterpret(s_b_6_7, emitter.context().types().u32());
    /* execute.simd:4564 [D] s_b_6_9: sym_63574_3_parameter_value = s_b_6_8, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_63574_3_parameter_value, s_b_6_8);
    /* execute.a64:2737 [F] s_b_6_10 = (u32)s_b_6_0 (const) */
    /* execute.a64:2737 [F] s_b_6_11 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_6_12 = s_b_6_10==s_b_6_11 (const) */
    uint8_t s_b_6_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_6_13: If s_b_6_12: Jump b_2 else b_16 (const) */
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
    /* execute.simd:4567 [F] s_b_7_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.simd:4567 [F] s_b_7_1=sym_11341_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_7_2 = ReadRegBank 11:s_b_7_1 (f64) */
    auto s_b_7_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_2,emitter.const_u8(8));
    }
    /* execute.simd:4567 [F] s_b_7_3 = sym_11346_0_mulp (const) uint64_t */
    uint64_t s_b_7_3 = CV_sym_11346_0_mulp;
    /* execute.simd:4567 [F] s_b_7_4 = (f64)s_b_7_3 (const) */
    /* execute.simd:4567 [D] s_b_7_5 = s_b_7_2*s_b_7_4 */
    auto s_b_7_5 = emitter.mul(s_b_7_2, emitter.const_f64(((double)s_b_7_3)));
    /* execute.simd:4567 [F] s_b_7_6=sym_11341_3_parameter_inst.rmode (const) */
    /* execute.simd:4567 [D] s_b_7_7 = __builtin_fcvt_f64_s32 */
    auto s_b_7_7 = emitter.call(__captive___builtin_fcvt_f64_s32, s_b_7_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4567 [D] s_b_7_8 = (u32)s_b_7_7 */
    auto s_b_7_8 = emitter.reinterpret(s_b_7_7, emitter.context().types().u32());
    /* execute.simd:4567 [D] s_b_7_9: sym_63597_3_parameter_value = s_b_7_8, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_63597_3_parameter_value, s_b_7_8);
    /* execute.a64:2737 [F] s_b_7_10 = (u32)s_b_7_0 (const) */
    /* execute.a64:2737 [F] s_b_7_11 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_7_12 = s_b_7_10==s_b_7_11 (const) */
    uint8_t s_b_7_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_7_13: If s_b_7_12: Jump b_2 else b_17 (const) */
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
    /* execute.simd:4572 [F] s_b_8_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.simd:4572 [F] s_b_8_1=sym_11341_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_8_2 = ReadRegBank 9:s_b_8_1 (f32) */
    auto s_b_8_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_2,emitter.const_u8(4));
    }
    /* execute.simd:4572 [F] s_b_8_3 = sym_11346_0_mulp (const) uint64_t */
    uint64_t s_b_8_3 = CV_sym_11346_0_mulp;
    /* execute.simd:4572 [F] s_b_8_4 = (f32)s_b_8_3 (const) */
    /* execute.simd:4572 [D] s_b_8_5 = s_b_8_2*s_b_8_4 */
    auto s_b_8_5 = emitter.mul(s_b_8_2, emitter.const_f32(((float)s_b_8_3)));
    /* execute.simd:4572 [F] s_b_8_6=sym_11341_3_parameter_inst.rmode (const) */
    /* execute.simd:4572 [D] s_b_8_7 = __builtin_fcvt_f32_s64 */
    auto s_b_8_7 = emitter.call(__captive___builtin_fcvt_f32_s64, s_b_8_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4572 [D] s_b_8_8 = (u64)s_b_8_7 */
    auto s_b_8_8 = emitter.reinterpret(s_b_8_7, emitter.context().types().u64());
    /* execute.simd:4572 [D] s_b_8_9: sym_63620_3_parameter_value = s_b_8_8, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_63620_3_parameter_value, s_b_8_8);
    /* execute.a64:2745 [F] s_b_8_10 = (u32)s_b_8_0 (const) */
    /* execute.a64:2745 [F] s_b_8_11 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_8_12 = s_b_8_10==s_b_8_11 (const) */
    uint8_t s_b_8_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_8_13: If s_b_8_12: Jump b_2 else b_18 (const) */
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
    /* execute.simd:4575 [F] s_b_9_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.simd:4575 [F] s_b_9_1=sym_11341_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_9_2 = ReadRegBank 11:s_b_9_1 (f64) */
    auto s_b_9_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_2,emitter.const_u8(8));
    }
    /* execute.simd:4575 [F] s_b_9_3 = sym_11346_0_mulp (const) uint64_t */
    uint64_t s_b_9_3 = CV_sym_11346_0_mulp;
    /* execute.simd:4575 [F] s_b_9_4 = (f64)s_b_9_3 (const) */
    /* execute.simd:4575 [D] s_b_9_5 = s_b_9_2*s_b_9_4 */
    auto s_b_9_5 = emitter.mul(s_b_9_2, emitter.const_f64(((double)s_b_9_3)));
    /* execute.simd:4575 [F] s_b_9_6=sym_11341_3_parameter_inst.rmode (const) */
    /* execute.simd:4575 [D] s_b_9_7 = __builtin_fcvt_f64_s64 */
    auto s_b_9_7 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_9_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4575 [D] s_b_9_8 = (u64)s_b_9_7 */
    auto s_b_9_8 = emitter.reinterpret(s_b_9_7, emitter.context().types().u64());
    /* execute.simd:4575 [D] s_b_9_9: sym_63642_3_parameter_value = s_b_9_8, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_63642_3_parameter_value, s_b_9_8);
    /* execute.a64:2745 [F] s_b_9_10 = (u32)s_b_9_0 (const) */
    /* execute.a64:2745 [F] s_b_9_11 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_9_12 = s_b_9_10==s_b_9_11 (const) */
    uint8_t s_b_9_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_9_13: If s_b_9_12: Jump b_2 else b_19 (const) */
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
    /* execute.simd:4581 [F] s_b_10_0=sym_11341_3_parameter_inst.type (const) */
    /* execute.simd:4581 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4581 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.simd:4581 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4581 [F] s_b_10_4: If s_b_10_3: Jump b_12 else b_13 (const) */
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
    /* execute.simd:4589 [F] s_b_11_0=sym_11341_3_parameter_inst.type (const) */
    /* execute.simd:4589 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.simd:4589 [F] s_b_11_2 = constant u32 0 (const) */
    /* execute.simd:4589 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4589 [F] s_b_11_4: If s_b_11_3: Jump b_14 else b_15 (const) */
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
    /* execute.simd:4583 [F] s_b_12_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.simd:4583 [F] s_b_12_1=sym_11341_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_12_2 = ReadRegBank 9:s_b_12_1 (f32) */
    auto s_b_12_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_2,emitter.const_u8(4));
    }
    /* execute.simd:4583 [F] s_b_12_3 = sym_11346_0_mulp (const) uint64_t */
    uint64_t s_b_12_3 = CV_sym_11346_0_mulp;
    /* execute.simd:4583 [F] s_b_12_4 = (f32)s_b_12_3 (const) */
    /* execute.simd:4583 [D] s_b_12_5 = s_b_12_2*s_b_12_4 */
    auto s_b_12_5 = emitter.mul(s_b_12_2, emitter.const_f32(((float)s_b_12_3)));
    /* execute.simd:4583 [F] s_b_12_6=sym_11341_3_parameter_inst.rmode (const) */
    /* execute.simd:4583 [D] s_b_12_7 = __builtin_fcvt_f32_u32 */
    auto s_b_12_7 = emitter.call(__captive___builtin_fcvt_f32_u32, s_b_12_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4583 [D] s_b_12_8: sym_63664_3_parameter_value = s_b_12_7, dominates: s_b_20_1  */
    emitter.store_local(DV_sym_63664_3_parameter_value, s_b_12_7);
    /* execute.a64:2737 [F] s_b_12_9 = (u32)s_b_12_0 (const) */
    /* execute.a64:2737 [F] s_b_12_10 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_12_11 = s_b_12_9==s_b_12_10 (const) */
    uint8_t s_b_12_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_12_12: If s_b_12_11: Jump b_2 else b_20 (const) */
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
    /* execute.simd:4586 [F] s_b_13_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.simd:4586 [F] s_b_13_1=sym_11341_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_13_2 = ReadRegBank 11:s_b_13_1 (f64) */
    auto s_b_13_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_13_2,emitter.const_u8(8));
    }
    /* execute.simd:4586 [F] s_b_13_3 = sym_11346_0_mulp (const) uint64_t */
    uint64_t s_b_13_3 = CV_sym_11346_0_mulp;
    /* execute.simd:4586 [F] s_b_13_4 = (f64)s_b_13_3 (const) */
    /* execute.simd:4586 [D] s_b_13_5 = s_b_13_2*s_b_13_4 */
    auto s_b_13_5 = emitter.mul(s_b_13_2, emitter.const_f64(((double)s_b_13_3)));
    /* execute.simd:4586 [F] s_b_13_6=sym_11341_3_parameter_inst.rmode (const) */
    /* execute.simd:4586 [D] s_b_13_7 = __builtin_fcvt_f64_u32 */
    auto s_b_13_7 = emitter.call(__captive___builtin_fcvt_f64_u32, s_b_13_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4586 [D] s_b_13_8: sym_63687_3_parameter_value = s_b_13_7, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_63687_3_parameter_value, s_b_13_7);
    /* execute.a64:2737 [F] s_b_13_9 = (u32)s_b_13_0 (const) */
    /* execute.a64:2737 [F] s_b_13_10 = constant u32 1f (const) */
    /* execute.a64:2737 [F] s_b_13_11 = s_b_13_9==s_b_13_10 (const) */
    uint8_t s_b_13_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2737 [F] s_b_13_12: If s_b_13_11: Jump b_2 else b_21 (const) */
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
    /* execute.simd:4591 [F] s_b_14_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.simd:4591 [F] s_b_14_1=sym_11341_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_14_2 = ReadRegBank 9:s_b_14_1 (f32) */
    auto s_b_14_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_2,emitter.const_u8(4));
    }
    /* execute.simd:4591 [F] s_b_14_3 = sym_11346_0_mulp (const) uint64_t */
    uint64_t s_b_14_3 = CV_sym_11346_0_mulp;
    /* execute.simd:4591 [F] s_b_14_4 = (f32)s_b_14_3 (const) */
    /* execute.simd:4591 [D] s_b_14_5 = s_b_14_2*s_b_14_4 */
    auto s_b_14_5 = emitter.mul(s_b_14_2, emitter.const_f32(((float)s_b_14_3)));
    /* execute.simd:4591 [F] s_b_14_6=sym_11341_3_parameter_inst.rmode (const) */
    /* execute.simd:4591 [D] s_b_14_7 = __builtin_fcvt_f32_u64 */
    auto s_b_14_7 = emitter.call(__captive___builtin_fcvt_f32_u64, s_b_14_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4591 [D] s_b_14_8: sym_63710_3_parameter_value = s_b_14_7, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_63710_3_parameter_value, s_b_14_7);
    /* execute.a64:2745 [F] s_b_14_9 = (u32)s_b_14_0 (const) */
    /* execute.a64:2745 [F] s_b_14_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_14_11 = s_b_14_9==s_b_14_10 (const) */
    uint8_t s_b_14_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_14_12: If s_b_14_11: Jump b_2 else b_22 (const) */
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
    /* execute.simd:4594 [F] s_b_15_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.simd:4594 [F] s_b_15_1=sym_11341_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_15_2 = ReadRegBank 11:s_b_15_1 (f64) */
    auto s_b_15_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_15_2,emitter.const_u8(8));
    }
    /* execute.simd:4594 [F] s_b_15_3 = sym_11346_0_mulp (const) uint64_t */
    uint64_t s_b_15_3 = CV_sym_11346_0_mulp;
    /* execute.simd:4594 [F] s_b_15_4 = (f64)s_b_15_3 (const) */
    /* execute.simd:4594 [D] s_b_15_5 = s_b_15_2*s_b_15_4 */
    auto s_b_15_5 = emitter.mul(s_b_15_2, emitter.const_f64(((double)s_b_15_3)));
    /* execute.simd:4594 [F] s_b_15_6=sym_11341_3_parameter_inst.rmode (const) */
    /* execute.simd:4594 [D] s_b_15_7 = __builtin_fcvt_f64_u64 */
    auto s_b_15_7 = emitter.call(__captive___builtin_fcvt_f64_u64, s_b_15_5, emitter.const_u8(insn.rmode));
    /* execute.simd:4594 [D] s_b_15_8: sym_63732_3_parameter_value = s_b_15_7, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_63732_3_parameter_value, s_b_15_7);
    /* execute.a64:2745 [F] s_b_15_9 = (u32)s_b_15_0 (const) */
    /* execute.a64:2745 [F] s_b_15_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_15_11 = s_b_15_9==s_b_15_10 (const) */
    uint8_t s_b_15_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_15_12: If s_b_15_11: Jump b_2 else b_23 (const) */
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
    /* execute.a64:2739 [F] s_b_16_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_16_1 = sym_63574_3_parameter_value uint32_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_63574_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_16_2 = (u64)s_b_16_1 */
    auto s_b_16_2 = emitter.zx(s_b_16_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_16_3: WriteRegBank 0:s_b_16_0 = s_b_16_2 */
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
    /* execute.a64:2739 [F] s_b_17_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_17_1 = sym_63597_3_parameter_value uint32_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_63597_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_17_2 = (u64)s_b_17_1 */
    auto s_b_17_2 = emitter.zx(s_b_17_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_17_3: WriteRegBank 0:s_b_17_0 = s_b_17_2 */
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
    /* execute.a64:2747 [F] s_b_18_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_18_1 = sym_63620_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_63620_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
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
    /* execute.a64:2747 [F] s_b_19_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_19_1 = sym_63642_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_63642_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
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
    /* execute.a64:2739 [F] s_b_20_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_20_1 = sym_63664_3_parameter_value uint32_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_63664_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_20_2 = (u64)s_b_20_1 */
    auto s_b_20_2 = emitter.zx(s_b_20_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_20_3: WriteRegBank 0:s_b_20_0 = s_b_20_2 */
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
    /* execute.a64:2739 [F] s_b_21_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.a64:2739 [D] s_b_21_1 = sym_63687_3_parameter_value uint32_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_63687_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2739 [D] s_b_21_2 = (u64)s_b_21_1 */
    auto s_b_21_2 = emitter.zx(s_b_21_1, emitter.context().types().u64());
    /* execute.a64:2739 [D] s_b_21_3: WriteRegBank 0:s_b_21_0 = s_b_21_2 */
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
    /* execute.a64:2747 [F] s_b_22_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_22_1 = sym_63710_3_parameter_value uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_63710_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_22_2: WriteRegBank 0:s_b_22_0 = s_b_22_1 */
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
    /* execute.a64:2747 [F] s_b_23_0=sym_11341_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_23_1 = sym_63732_3_parameter_value uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_63732_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_23_2: WriteRegBank 0:s_b_23_0 = s_b_23_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fmov(const arm64_decode_a64_FP_DP_1&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4107 [F] s_b_0_0=sym_11921_3_parameter_inst.type (const) */
    /* execute.simd:4107 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4107 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4107 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4107 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4108 [F] s_b_1_0=sym_11921_3_parameter_inst.rd (const) */
    /* execute.simd:4108 [F] s_b_1_1=sym_11921_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_1_2 = ReadRegBank 9:s_b_1_1 (f32) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(4));
    }
    /* execute.simd:6290 [D] s_b_1_3: WriteRegBank 9:s_b_1_0 = s_b_1_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_2,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_2);
    /* execute.simd:6291 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_1_5: WriteRegBank 10:s_b_1_0 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_1_6 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_1_7: WriteRegBank 3:s_b_1_0 = s_b_1_6 */
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
    /* execute.simd:4110 [F] s_b_3_0=sym_11921_3_parameter_inst.rd (const) */
    /* execute.simd:4110 [F] s_b_3_1=sym_11921_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_3_2 = ReadRegBank 11:s_b_3_1 (f64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:6298 [D] s_b_3_3: WriteRegBank 11:s_b_3_0 = s_b_3_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_2);
    /* execute.simd:6299 [F] s_b_3_4 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_3_5: WriteRegBank 3:s_b_3_0 = s_b_3_4 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fnmul(const arm64_decode_a64_FP_DP_2&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4215 [F] s_b_0_0=sym_12566_3_parameter_inst.type (const) */
    /* execute.simd:4215 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4215 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4215 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4215 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4217 [F] s_b_1_0=sym_12566_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4218 [F] s_b_1_2=sym_12566_3_parameter_inst.rm (const) */
    /* execute.simd:6280 [D] s_b_1_3 = ReadRegBank 9:s_b_1_2 (f32) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(4));
    }
    /* execute.simd:4220 [D] s_b_1_4 = s_b_1_1*s_b_1_3 */
    auto s_b_1_4 = emitter.mul(s_b_1_1, s_b_1_3);
    /* execute.simd:4220 [D] s_b_1_5 = -s_b_1_4 */
    auto s_b_1_5 = emitter.neg(s_b_1_4);
    /* execute.simd:4221 [F] s_b_1_6=sym_12566_3_parameter_inst.rd (const) */
    /* execute.simd:6290 [D] s_b_1_7: WriteRegBank 9:s_b_1_6 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6291 [F] s_b_1_8 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_1_9: WriteRegBank 10:s_b_1_6 = s_b_1_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_1_10 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_1_11: WriteRegBank 3:s_b_1_6 = s_b_1_10 */
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
    /* execute.simd:4224 [F] s_b_3_0=sym_12566_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4225 [F] s_b_3_2=sym_12566_3_parameter_inst.rm (const) */
    /* execute.simd:6285 [D] s_b_3_3 = ReadRegBank 11:s_b_3_2 (f64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:4227 [D] s_b_3_4 = s_b_3_1*s_b_3_3 */
    auto s_b_3_4 = emitter.mul(s_b_3_1, s_b_3_3);
    /* execute.simd:4227 [D] s_b_3_5 = -s_b_3_4 */
    auto s_b_3_5 = emitter.neg(s_b_3_4);
    /* execute.simd:4228 [F] s_b_3_6=sym_12566_3_parameter_inst.rd (const) */
    /* execute.simd:6298 [D] s_b_3_7: WriteRegBank 11:s_b_3_6 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_5);
    /* execute.simd:6299 [F] s_b_3_8 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_3_9: WriteRegBank 3:s_b_3_6 = s_b_3_8 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ld1(const arm64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_66020_3_parameter_rt;
  uint8_t CV_sym_66026_3_parameter_lane;
  auto DV_sym_65966_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66018_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_66088_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_13124_0_lane;
  uint8_t CV_sym_13104_0_rt;
  auto DV_sym_13098_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66105_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_66016_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66179_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66150_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_66147_1_tmp_s_b_5_4;
  auto DV_sym_66122_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66071_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_66054_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_66037_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_13092_3_parameter_inst.rn (const) */
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
    /* execute.simd:2467 [F] s_b_1_0 = sym_13104_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13104_0_rt;
    /* execute.simd:2467 [F] s_b_1_1=sym_13092_3_parameter_inst.regcnt (const) */
    /* execute.simd:2467 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
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
    /* execute.simd:2468 [F] s_b_2_0=sym_13092_3_parameter_inst.rt (const) */
    /* execute.simd:2468 [F] s_b_2_1 = sym_13104_0_rt (const) uint8_t */
    uint8_t s_b_2_1 = CV_sym_13104_0_rt;
    /* execute.simd:2468 [F] s_b_2_2 = s_b_2_0+s_b_2_1 (const) */
    uint8_t s_b_2_2 = ((uint8_t)(insn.rt + s_b_2_1));
    /* execute.simd:2468 [F] s_b_2_3 = constant u64 0 (const) */
    /* execute.simd:2468 [F] s_b_2_4 = constant u64 0 (const) */
    /* execute.simd:6333 [F] s_b_2_5: WriteRegBank 2:s_b_2_2 = s_b_2_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6334 [F] s_b_2_6: WriteRegBank 3:s_b_2_2 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2469 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:2469 [F] s_b_2_8: sym_13124_0_lane = s_b_2_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_13124_0_lane = (uint8_t)0ULL;
    /* execute.simd:2469 [F] s_b_2_9: Jump b_4 (const) */
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
    /* execute.simd:2469 [F] s_b_4_0 = sym_13124_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13124_0_lane;
    /* execute.simd:2469 [F] s_b_4_1=sym_13092_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2469 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2469 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2470 [F] s_b_5_0=sym_13092_3_parameter_inst.arrangement (const) */
    /* execute.simd:2470 [F] s_b_5_1=sym_13092_3_parameter_inst.rt (const) */
    /* execute.simd:2470 [F] s_b_5_2 = sym_13104_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13104_0_rt;
    /* execute.simd:2470 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2470 [F] s_b_5_4 = sym_13124_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13124_0_lane;
    /* execute.simd:2470 [D] s_b_5_5 = sym_13098_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13098_0_address, emitter.context().types().u64());
    /* execute.simd:2470 [F] s_b_5_6: sym_66020_3_parameter_rt = s_b_5_3 (const), dominates: s_b_13_2 s_b_12_2 s_b_11_2 s_b_10_2 s_b_14_2 s_b_15_2 s_b_16_2  */
    CV_sym_66020_3_parameter_rt = s_b_5_3;
    /* execute.simd:2470 [F] s_b_5_7: sym_66026_3_parameter_lane = s_b_5_4 (const), dominates: s_b_13_5 s_b_12_5 s_b_11_5 s_b_10_5 s_b_14_5 s_b_15_5 s_b_16_5  */
    CV_sym_66026_3_parameter_lane = s_b_5_4;
    /* execute.simd:2470 [D] s_b_5_8: sym_66016_3_parameter_addr = s_b_5_5, dominates: s_b_13_0 s_b_12_0 s_b_11_0 s_b_10_0 s_b_14_0 s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_66016_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_66147_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_17_1  */
    CV_sym_66147_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_66150_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_66150_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3857 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3866 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3875 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3884 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3893 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3902 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3911 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3856 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_9 (const) -> b_13, b_12, b_11, b_10, b_9, b_14, b_15, b_16,  */
    switch (insn.arrangement) 
    {
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_15;
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
    case (int32_t)4ULL:
      goto fixed_block_b_14;
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
    /* execute.simd:2467 [F] s_b_6_0 = sym_13104_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13104_0_rt;
    /* execute.simd:2467 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2467 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2467 [F] s_b_6_3: sym_13104_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_13104_0_rt = s_b_6_2;
    /* execute.simd:2467 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2796 [F] s_b_7_0=sym_13092_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_7_1 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_7_2: sym_65966_1__R_s_b_0_5 = s_b_7_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_65966_1__R_s_b_0_5, s_b_7_1);
    /* execute.a64:2796 [F] s_b_7_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_22,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2465 [D] s_b_8_0 = sym_65966_1__R_s_b_0_5 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_65966_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2465 [D] s_b_8_1: sym_13098_0_address = s_b_8_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13098_0_address, s_b_8_0);
    /* execute.simd:2467 [F] s_b_8_2 = constant u8 0 (const) */
    /* execute.simd:2467 [F] s_b_8_3: sym_13104_0_rt = s_b_8_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_13104_0_rt = (uint8_t)0ULL;
    /* execute.simd:2467 [F] s_b_8_4: Jump b_1 (const) */
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
    /* execute.simd:3859 [D] s_b_10_0 = sym_66016_3_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_66016_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 1 s_b_10_0 => sym_66018_0_mem_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66018_0_mem_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(1));
    }
    /* execute.simd:3861 [F] s_b_10_2 = sym_66020_3_parameter_rt (const) uint8_t */
    uint8_t s_b_10_2 = CV_sym_66020_3_parameter_rt;
    /* execute.simd:3861 [D] s_b_10_3 = ReadRegBank 15:s_b_10_2 (v8u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:3862 [D] s_b_10_4 = sym_66018_0_mem_value uint8_t */
    auto s_b_10_4 = emitter.load_local(DV_sym_66018_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3862 [F] s_b_10_5 = sym_66026_3_parameter_lane (const) uint8_t */
    uint8_t s_b_10_5 = CV_sym_66026_3_parameter_lane;
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
    /* execute.simd:3868 [D] s_b_11_0 = sym_66016_3_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_66016_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 1 s_b_11_0 => sym_66037_0_mem_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66037_0_mem_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(1));
    }
    /* execute.simd:3870 [F] s_b_11_2 = sym_66020_3_parameter_rt (const) uint8_t */
    uint8_t s_b_11_2 = CV_sym_66020_3_parameter_rt;
    /* execute.simd:3870 [D] s_b_11_3 = ReadRegBank 16:s_b_11_2 (v16u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:3871 [D] s_b_11_4 = sym_66037_0_mem_value uint8_t */
    auto s_b_11_4 = emitter.load_local(DV_sym_66037_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3871 [F] s_b_11_5 = sym_66026_3_parameter_lane (const) uint8_t */
    uint8_t s_b_11_5 = CV_sym_66026_3_parameter_lane;
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
    /* execute.simd:3877 [D] s_b_12_0 = sym_66016_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_66016_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_66054_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66054_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3879 [F] s_b_12_2 = sym_66020_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_66020_3_parameter_rt;
    /* execute.simd:3879 [D] s_b_12_3 = ReadRegBank 17:s_b_12_2 (v4u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3880 [D] s_b_12_4 = sym_66054_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_66054_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3880 [F] s_b_12_5 = sym_66026_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_66026_3_parameter_lane;
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
    /* execute.simd:3886 [D] s_b_13_0 = sym_66016_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_66016_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 2 s_b_13_0 => sym_66071_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66071_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(2));
    }
    /* execute.simd:3888 [F] s_b_13_2 = sym_66020_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_66020_3_parameter_rt;
    /* execute.simd:3888 [D] s_b_13_3 = ReadRegBank 18:s_b_13_2 (v8u16) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3889 [D] s_b_13_4 = sym_66071_0_mem_value uint16_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_66071_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3889 [F] s_b_13_5 = sym_66026_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_66026_3_parameter_lane;
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
    /* execute.simd:3895 [D] s_b_14_0 = sym_66016_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_66016_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_66088_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_66088_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.simd:3897 [F] s_b_14_2 = sym_66020_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_66020_3_parameter_rt;
    /* execute.simd:3897 [D] s_b_14_3 = ReadRegBank 19:s_b_14_2 (v2u32) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3898 [D] s_b_14_4 = sym_66088_0_mem_value uint32_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_66088_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3898 [F] s_b_14_5 = sym_66026_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_66026_3_parameter_lane;
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
    /* execute.simd:3904 [D] s_b_15_0 = sym_66016_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_66016_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 4 s_b_15_0 => sym_66105_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_66105_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(4));
    }
    /* execute.simd:3906 [F] s_b_15_2 = sym_66020_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_66020_3_parameter_rt;
    /* execute.simd:3906 [D] s_b_15_3 = ReadRegBank 20:s_b_15_2 (v4u32) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3907 [D] s_b_15_4 = sym_66105_0_mem_value uint32_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_66105_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3907 [F] s_b_15_5 = sym_66026_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_66026_3_parameter_lane;
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
    /* execute.simd:3913 [D] s_b_16_0 = sym_66016_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_66016_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_66122_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_66122_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.simd:3915 [F] s_b_16_2 = sym_66020_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_66020_3_parameter_rt;
    /* execute.simd:3915 [D] s_b_16_3 = ReadRegBank 21:s_b_16_2 (v2u64) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3916 [D] s_b_16_4 = sym_66122_0_mem_value uint64_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_66122_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3916 [F] s_b_16_5 = sym_66026_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_66026_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_17_0 = sym_66150_1_tmp_s_b_5_5 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_66150_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1 = sym_66147_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_17_1 = CV_sym_66147_1_tmp_s_b_5_4;
    /* execute.simd:2471 [F] s_b_17_2=sym_13092_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* ???:4294967295 [D] s_b_17_4 = s_b_17_0+s_b_17_3 */
    auto s_b_17_4 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2471 [D] s_b_17_5: sym_13098_0_address = s_b_17_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13098_0_address, s_b_17_4);
    /* execute.simd:2469 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:2469 [F] s_b_17_7 = s_b_17_1+s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(s_b_17_1 + (uint8_t)1ULL));
    /* execute.simd:2469 [F] s_b_17_8: sym_13124_0_lane = s_b_17_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_13124_0_lane = s_b_17_7;
    /* execute.simd:2469 [F] s_b_17_9: Jump b_4 (const) */
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
    /* execute.a64:2765 [D] s_b_19_1: sym_66179_1__R_s_b_10_0 = s_b_19_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_66179_1__R_s_b_10_0, s_b_19_0);
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
    /* execute.a64:2768 [D] s_b_20_1: sym_66179_1__R_s_b_10_0 = s_b_20_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_66179_1__R_s_b_10_0, s_b_20_0);
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
    /* execute.a64:2770 [D] s_b_21_1: sym_66179_1__R_s_b_10_0 = s_b_21_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_66179_1__R_s_b_10_0, s_b_21_0);
    /* execute.a64:2770 [F] s_b_21_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19, b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2794 [D] s_b_22_0 = sym_66179_1__R_s_b_10_0 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_66179_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_22_1: sym_65966_1__R_s_b_0_5 = s_b_22_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_65966_1__R_s_b_0_5, s_b_22_0);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ld4(const arm64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_69319_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69458_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69441_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_69483_1_tmp_s_b_5_2;
  auto DV_sym_69424_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_69352_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69486_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69407_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_69354_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_69390_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_69515_1__R_s_b_10_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69373_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_69362_3_parameter_lane;
  uint8_t CV_sym_69356_3_parameter_rt;
  uint8_t CV_sym_13918_0_rt;
  uint8_t CV_sym_13906_0_lane;
  auto DV_sym_13861_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_13855_3_parameter_inst.rn (const) */
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
    /* execute.simd:2516 [F] s_b_1_0 = sym_13906_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13906_0_lane;
    /* execute.simd:2516 [F] s_b_1_1=sym_13855_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2516 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2516 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2517 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2517 [F] s_b_2_1: sym_13918_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13918_0_rt = (uint8_t)0ULL;
    /* execute.simd:2517 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2517 [F] s_b_4_0 = sym_13918_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13918_0_rt;
    /* execute.simd:2517 [F] s_b_4_1=sym_13855_3_parameter_inst.regcnt (const) */
    /* execute.simd:2517 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2517 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2518 [F] s_b_5_0=sym_13855_3_parameter_inst.arrangement (const) */
    /* execute.simd:2518 [F] s_b_5_1=sym_13855_3_parameter_inst.rt (const) */
    /* execute.simd:2518 [F] s_b_5_2 = sym_13918_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13918_0_rt;
    /* execute.simd:2518 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2518 [F] s_b_5_4 = sym_13906_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13906_0_lane;
    /* execute.simd:2518 [D] s_b_5_5 = sym_13861_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13861_0_address, emitter.context().types().u64());
    /* execute.simd:2518 [F] s_b_5_6: sym_69356_3_parameter_rt = s_b_5_3 (const), dominates: s_b_10_2 s_b_11_2 s_b_16_2 s_b_15_2 s_b_14_2 s_b_13_2 s_b_12_2  */
    CV_sym_69356_3_parameter_rt = s_b_5_3;
    /* execute.simd:2518 [F] s_b_5_7: sym_69362_3_parameter_lane = s_b_5_4 (const), dominates: s_b_10_5 s_b_11_5 s_b_16_5 s_b_15_5 s_b_14_5 s_b_13_5 s_b_12_5  */
    CV_sym_69362_3_parameter_lane = s_b_5_4;
    /* execute.simd:2518 [D] s_b_5_8: sym_69352_3_parameter_addr = s_b_5_5, dominates: s_b_10_0 s_b_11_0 s_b_16_0 s_b_15_0 s_b_14_0 s_b_13_0 s_b_12_0  */
    emitter.store_local(DV_sym_69352_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_69483_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_17_1  */
    CV_sym_69483_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_69486_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_69486_1_tmp_s_b_5_5, s_b_5_5);
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
    case (int32_t)6ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_12;
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
    /* execute.simd:2516 [F] s_b_6_0 = sym_13906_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13906_0_lane;
    /* execute.simd:2516 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2516 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2516 [F] s_b_6_3: sym_13906_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13906_0_lane = s_b_6_2;
    /* execute.simd:2516 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2796 [F] s_b_7_0=sym_13855_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_7_1 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_7_2: sym_69319_1__R_s_b_0_5 = s_b_7_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_69319_1__R_s_b_0_5, s_b_7_1);
    /* execute.a64:2796 [F] s_b_7_3: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7, b_22,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2509 [D] s_b_8_0 = sym_69319_1__R_s_b_0_5 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_69319_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2509 [D] s_b_8_1: sym_13861_0_address = s_b_8_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13861_0_address, s_b_8_0);
    /* execute.simd:2511 [F] s_b_8_2=sym_13855_3_parameter_inst.rt (const) */
    /* execute.simd:2511 [F] s_b_8_3 = constant u64 0 (const) */
    /* execute.simd:2511 [F] s_b_8_4 = constant u64 0 (const) */
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
    /* execute.simd:2512 [F] s_b_8_7=sym_13855_3_parameter_inst.rt (const) */
    /* execute.simd:2512 [F] s_b_8_8 = (u32)s_b_8_7 (const) */
    /* execute.simd:2512 [F] s_b_8_9 = constant u32 1 (const) */
    /* execute.simd:2512 [F] s_b_8_10 = s_b_8_8+s_b_8_9 (const) */
    uint32_t s_b_8_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2512 [F] s_b_8_11 = (u8)s_b_8_10 (const) */
    /* execute.simd:2512 [F] s_b_8_12 = constant u64 0 (const) */
    /* execute.simd:2512 [F] s_b_8_13 = constant u64 0 (const) */
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
    /* execute.simd:2513 [F] s_b_8_16=sym_13855_3_parameter_inst.rt (const) */
    /* execute.simd:2513 [F] s_b_8_17 = (u32)s_b_8_16 (const) */
    /* execute.simd:2513 [F] s_b_8_18 = constant u32 2 (const) */
    /* execute.simd:2513 [F] s_b_8_19 = s_b_8_17+s_b_8_18 (const) */
    uint32_t s_b_8_19 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)2ULL));
    /* execute.simd:2513 [F] s_b_8_20 = (u8)s_b_8_19 (const) */
    /* execute.simd:2513 [F] s_b_8_21 = constant u64 0 (const) */
    /* execute.simd:2513 [F] s_b_8_22 = constant u64 0 (const) */
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
    /* execute.simd:2514 [F] s_b_8_25=sym_13855_3_parameter_inst.rt (const) */
    /* execute.simd:2514 [F] s_b_8_26 = (u32)s_b_8_25 (const) */
    /* execute.simd:2514 [F] s_b_8_27 = constant u32 3 (const) */
    /* execute.simd:2514 [F] s_b_8_28 = s_b_8_26+s_b_8_27 (const) */
    uint32_t s_b_8_28 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)3ULL));
    /* execute.simd:2514 [F] s_b_8_29 = (u8)s_b_8_28 (const) */
    /* execute.simd:2514 [F] s_b_8_30 = constant u64 0 (const) */
    /* execute.simd:2514 [F] s_b_8_31 = constant u64 0 (const) */
    /* execute.simd:6333 [F] s_b_8_32: WriteRegBank 2:s_b_8_29 = s_b_8_30 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6334 [F] s_b_8_33: WriteRegBank 3:s_b_8_29 = s_b_8_31 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_8_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2516 [F] s_b_8_34 = constant u8 0 (const) */
    /* execute.simd:2516 [F] s_b_8_35: sym_13906_0_lane = s_b_8_34 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13906_0_lane = (uint8_t)0ULL;
    /* execute.simd:2516 [F] s_b_8_36: Jump b_1 (const) */
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
    /* execute.simd:3859 [D] s_b_10_0 = sym_69352_3_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_69352_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 1 s_b_10_0 => sym_69354_0_mem_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_69354_0_mem_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(1));
    }
    /* execute.simd:3861 [F] s_b_10_2 = sym_69356_3_parameter_rt (const) uint8_t */
    uint8_t s_b_10_2 = CV_sym_69356_3_parameter_rt;
    /* execute.simd:3861 [D] s_b_10_3 = ReadRegBank 15:s_b_10_2 (v8u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_10_2))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:3862 [D] s_b_10_4 = sym_69354_0_mem_value uint8_t */
    auto s_b_10_4 = emitter.load_local(DV_sym_69354_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3862 [F] s_b_10_5 = sym_69362_3_parameter_lane (const) uint8_t */
    uint8_t s_b_10_5 = CV_sym_69362_3_parameter_lane;
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
    /* execute.simd:3868 [D] s_b_11_0 = sym_69352_3_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_69352_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 1 s_b_11_0 => sym_69373_0_mem_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_69373_0_mem_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(1));
    }
    /* execute.simd:3870 [F] s_b_11_2 = sym_69356_3_parameter_rt (const) uint8_t */
    uint8_t s_b_11_2 = CV_sym_69356_3_parameter_rt;
    /* execute.simd:3870 [D] s_b_11_3 = ReadRegBank 16:s_b_11_2 (v16u8) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_11_2))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:3871 [D] s_b_11_4 = sym_69373_0_mem_value uint8_t */
    auto s_b_11_4 = emitter.load_local(DV_sym_69373_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3871 [F] s_b_11_5 = sym_69362_3_parameter_lane (const) uint8_t */
    uint8_t s_b_11_5 = CV_sym_69362_3_parameter_lane;
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
    /* execute.simd:3877 [D] s_b_12_0 = sym_69352_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_69352_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_69390_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_69390_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3879 [F] s_b_12_2 = sym_69356_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_69356_3_parameter_rt;
    /* execute.simd:3879 [D] s_b_12_3 = ReadRegBank 17:s_b_12_2 (v4u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3880 [D] s_b_12_4 = sym_69390_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_69390_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3880 [F] s_b_12_5 = sym_69362_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_69362_3_parameter_lane;
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
    /* execute.simd:3886 [D] s_b_13_0 = sym_69352_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_69352_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 2 s_b_13_0 => sym_69407_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_69407_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(2));
    }
    /* execute.simd:3888 [F] s_b_13_2 = sym_69356_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_69356_3_parameter_rt;
    /* execute.simd:3888 [D] s_b_13_3 = ReadRegBank 18:s_b_13_2 (v8u16) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3889 [D] s_b_13_4 = sym_69407_0_mem_value uint16_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_69407_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3889 [F] s_b_13_5 = sym_69362_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_69362_3_parameter_lane;
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
    /* execute.simd:3895 [D] s_b_14_0 = sym_69352_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_69352_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_69424_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_69424_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.simd:3897 [F] s_b_14_2 = sym_69356_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_69356_3_parameter_rt;
    /* execute.simd:3897 [D] s_b_14_3 = ReadRegBank 19:s_b_14_2 (v2u32) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3898 [D] s_b_14_4 = sym_69424_0_mem_value uint32_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_69424_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3898 [F] s_b_14_5 = sym_69362_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_69362_3_parameter_lane;
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
    /* execute.simd:3904 [D] s_b_15_0 = sym_69352_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_69352_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 4 s_b_15_0 => sym_69441_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_69441_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(4));
    }
    /* execute.simd:3906 [F] s_b_15_2 = sym_69356_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_69356_3_parameter_rt;
    /* execute.simd:3906 [D] s_b_15_3 = ReadRegBank 20:s_b_15_2 (v4u32) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3907 [D] s_b_15_4 = sym_69441_0_mem_value uint32_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_69441_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3907 [F] s_b_15_5 = sym_69362_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_69362_3_parameter_lane;
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
    /* execute.simd:3913 [D] s_b_16_0 = sym_69352_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_69352_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_69458_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_69458_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.simd:3915 [F] s_b_16_2 = sym_69356_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_69356_3_parameter_rt;
    /* execute.simd:3915 [D] s_b_16_3 = ReadRegBank 21:s_b_16_2 (v2u64) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3916 [D] s_b_16_4 = sym_69458_0_mem_value uint64_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_69458_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3916 [F] s_b_16_5 = sym_69362_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_69362_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_17_0 = sym_69486_1_tmp_s_b_5_5 uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_69486_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1 = sym_69483_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_17_1 = CV_sym_69483_1_tmp_s_b_5_2;
    /* execute.simd:2519 [F] s_b_17_2=sym_13855_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* ???:4294967295 [D] s_b_17_4 = s_b_17_0+s_b_17_3 */
    auto s_b_17_4 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2519 [D] s_b_17_5: sym_13861_0_address = s_b_17_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_13861_0_address, s_b_17_4);
    /* execute.simd:2517 [F] s_b_17_6 = constant u8 1 (const) */
    /* execute.simd:2517 [F] s_b_17_7 = s_b_17_1+s_b_17_6 (const) */
    uint8_t s_b_17_7 = ((uint8_t)(s_b_17_1 + (uint8_t)1ULL));
    /* execute.simd:2517 [F] s_b_17_8: sym_13918_0_rt = s_b_17_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13918_0_rt = s_b_17_7;
    /* execute.simd:2517 [F] s_b_17_9: Jump b_4 (const) */
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
    /* execute.a64:2765 [D] s_b_19_1: sym_69515_1__R_s_b_10_0 = s_b_19_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_69515_1__R_s_b_10_0, s_b_19_0);
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
    /* execute.a64:2768 [D] s_b_20_1: sym_69515_1__R_s_b_10_0 = s_b_20_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_69515_1__R_s_b_10_0, s_b_20_0);
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
    /* execute.a64:2770 [D] s_b_21_1: sym_69515_1__R_s_b_10_0 = s_b_21_0, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_69515_1__R_s_b_10_0, s_b_21_0);
    /* execute.a64:2770 [F] s_b_21_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_19, b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2794 [D] s_b_22_0 = sym_69515_1__R_s_b_10_0 uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_69515_1__R_s_b_10_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_22_1: sym_69319_1__R_s_b_0_5 = s_b_22_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_69319_1__R_s_b_0_5, s_b_22_0);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldaxrh(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_83268_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_83306_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_83369_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_83424_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_84105_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14287_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_1_0=sym_14287_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_1_2: sym_83268_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_83268_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2796 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:750 [D] s_b_2_0 = sym_83268_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_83268_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:751 [D] s_b_2_1: sym_83369_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_83369_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 2 s_b_2_0 => sym_83424_0_data16 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_83424_0_data16, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(2));
    }
    /* execute.a64:1740 [D] s_b_2_3 = sym_83424_0_data16 uint16_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_83424_0_data16, emitter.context().types().u16());
    /* execute.a64:1740 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_2_5=sym_14287_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_2_8: sym_84105_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_84105_3_parameter_value, s_b_2_7);
    /* execute.a64:2745 [F] s_b_2_9 = (u32)s_b_2_5 (const) */
    /* execute.a64:2745 [F] s_b_2_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_2_11 = s_b_2_9==s_b_2_10 (const) */
    uint8_t s_b_2_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_2_12: If s_b_2_11: Jump b_8 else b_10 (const) */
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
    /* execute.a64:2765 [D] s_b_4_1: sym_83306_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_83306_1__R_s_b_4_0, s_b_4_0);
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
    /* execute.a64:2768 [D] s_b_5_1: sym_83306_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_83306_1__R_s_b_4_0, s_b_5_0);
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
    /* execute.a64:2770 [D] s_b_6_1: sym_83306_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_83306_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2770 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2794 [D] s_b_7_0 = sym_83306_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_83306_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_7_1: sym_83268_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_83268_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2794 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1786 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_8_1 = sym_83369_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_83369_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_8_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Return */
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
    /* execute.a64:2747 [F] s_b_10_0=sym_14287_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_10_1 = sym_84105_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_84105_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldr(const arm64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14751_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92522_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_93684_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92107_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92404_0_data128_2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91887_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_91916_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92446_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_92689_1__R_s_b_28_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92235_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_94188_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92633_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_94210_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92300_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_92398_0_data128_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92598_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_92019_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14745_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_28 else b_19 (const) */
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
    /* execute.a64:1011 [D] s_b_1_0 = sym_14751_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* execute.a64:1011 [F] s_b_1_1=sym_14745_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1011 [D] s_b_1_4: sym_14751_0_address = s_b_1_3, dominates: s_b_6_0 s_b_17_0 s_b_18_1 s_b_7_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_14751_0_address, s_b_1_3);
    /* execute.a64:1011 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_20,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1014 [F] s_b_2_0=sym_14745_3_parameter_inst.V (const) */
    /* execute.a64:1014 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:1014 [F] s_b_2_2 = constant u32 0 (const) */
    /* execute.a64:1014 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.V) == (uint32_t)0ULL));
    /* execute.a64:1014 [F] s_b_2_4: If s_b_2_3: Jump b_3 else b_5 (const) */
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
    /* execute.a64:1015 [F] s_b_3_0=sym_14745_3_parameter_inst.size (const) */
    /* execute.a64:1015 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1015 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1015 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:1015 [F] s_b_3_4: If s_b_3_3: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1034 [F] s_b_4_0=sym_14745_3_parameter_inst.P (const) */
    /* execute.a64:1034 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:1034 [F] s_b_4_2: If s_b_4_1: Jump b_17 else b_18 (const) */
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
    /* execute.a64:1021 [F] s_b_5_0=sym_14745_3_parameter_inst.size (const) */
    /* execute.a64:1021 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1021 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:1021 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.a64:1021 [F] s_b_5_4=sym_14745_3_parameter_inst.X (const) */
    /* execute.a64:1021 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1021 [F] s_b_5_6 = constant u32 0 (const) */
    /* execute.a64:1021 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1021 [F] s_b_5_12: If s_b_5_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1016 [D] s_b_6_0 = sym_14751_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* execute.a64:1016 [D] s_b_6_1: sym_91916_3_parameter_address = s_b_6_0, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_91916_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 4 s_b_6_0 => sym_92019_0_data32 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_92019_0_data32, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_6_3 = sym_92019_0_data32 uint32_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_92019_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_6_4 = (u64)s_b_6_3 */
    auto s_b_6_4 = emitter.zx(s_b_6_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_5=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_6_6 = (u32)s_b_6_4 */
    auto s_b_6_6 = emitter.truncate(s_b_6_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_8: sym_94188_3_parameter_value = s_b_6_7, dominates: s_b_37_1  */
    emitter.store_local(DV_sym_94188_3_parameter_value, s_b_6_7);
    /* execute.a64:2745 [F] s_b_6_9 = (u32)s_b_6_5 (const) */
    /* execute.a64:2745 [F] s_b_6_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_6_11 = s_b_6_9==s_b_6_10 (const) */
    uint8_t s_b_6_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_6_12: If s_b_6_11: Jump b_21 else b_37 (const) */
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
    /* execute.a64:1018 [D] s_b_7_0 = sym_14751_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* execute.a64:1018 [D] s_b_7_1: sym_92107_3_parameter_address = s_b_7_0, dominates: s_b_22_1  */
    emitter.store_local(DV_sym_92107_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 8 s_b_7_0 => sym_92235_0_data64 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_92235_0_data64, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_7_3 = sym_92235_0_data64 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_92235_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_7_4=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_7_5: sym_94210_3_parameter_value = s_b_7_3, dominates: s_b_38_1  */
    emitter.store_local(DV_sym_94210_3_parameter_value, s_b_7_3);
    /* execute.a64:2745 [F] s_b_7_6 = (u32)s_b_7_4 (const) */
    /* execute.a64:2745 [F] s_b_7_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_7_8 = s_b_7_6==s_b_7_7 (const) */
    uint8_t s_b_7_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_7_9: If s_b_7_8: Jump b_22 else b_38 (const) */
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
    /* execute.a64:1022 [D] s_b_8_0 = sym_14751_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_8_1 = Load 1 s_b_8_0 => sym_92300_0_data8 */
    auto s_b_8_1 = emitter.load_memory(s_b_8_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_92300_0_data8, s_b_8_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_8_0, s_b_8_1, emitter.const_u8(1));
    }
    /* execute.a64:1796 [F] s_b_8_2=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:1796 [D] s_b_8_3 = sym_92300_0_data8 uint8_t */
    auto s_b_8_3 = emitter.load_local(DV_sym_92300_0_data8, emitter.context().types().u8());
    /* execute.simd:6305 [D] s_b_8_4 = (u64)s_b_8_3 */
    auto s_b_8_4 = emitter.zx(s_b_8_3, emitter.context().types().u64());
    /* execute.simd:6305 [D] s_b_8_5: WriteRegBank 2:s_b_8_2 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_8_4);
    /* execute.simd:6306 [F] s_b_8_6 = constant u64 0 (const) */
    /* execute.simd:6306 [F] s_b_8_7: WriteRegBank 3:s_b_8_2 = s_b_8_6 */
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
    /* execute.a64:1023 [F] s_b_9_0=sym_14745_3_parameter_inst.size (const) */
    /* execute.a64:1023 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:1023 [F] s_b_9_2 = constant u32 0 (const) */
    /* execute.a64:1023 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.a64:1023 [F] s_b_9_4=sym_14745_3_parameter_inst.X (const) */
    /* execute.a64:1023 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.a64:1023 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.a64:1023 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.a64:1023 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
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
    /* execute.a64:1024 [D] s_b_10_0 = sym_14751_0_address uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 8 s_b_10_0 => sym_92398_0_data128_1 */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_92398_0_data128_1, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(8));
    }
    /* execute.a64:1826 [F] s_b_10_2 = constant u64 8 (const) */
    /* execute.a64:1826 [D] s_b_10_3 = s_b_10_0+s_b_10_2 */
    auto s_b_10_3 = emitter.add(s_b_10_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_10_4 = Load 8 s_b_10_3 => sym_92404_0_data128_2 */
    auto s_b_10_4 = emitter.load_memory(s_b_10_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_92404_0_data128_2, s_b_10_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_3, s_b_10_4, emitter.const_u8(8));
    }
    /* execute.a64:1828 [F] s_b_10_5=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:1828 [D] s_b_10_6 = sym_92398_0_data128_1 uint64_t */
    auto s_b_10_6 = emitter.load_local(DV_sym_92398_0_data128_1, emitter.context().types().u64());
    /* execute.a64:1828 [D] s_b_10_7 = sym_92404_0_data128_2 uint64_t */
    auto s_b_10_7 = emitter.load_local(DV_sym_92404_0_data128_2, emitter.context().types().u64());
    /* execute.simd:6333 [D] s_b_10_8: WriteRegBank 2:s_b_10_5 = s_b_10_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_6);
    /* execute.simd:6334 [D] s_b_10_9: WriteRegBank 3:s_b_10_5 = s_b_10_7 */
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
    /* execute.a64:1025 [F] s_b_11_0=sym_14745_3_parameter_inst.size (const) */
    /* execute.a64:1025 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:1025 [F] s_b_11_2 = constant u32 1 (const) */
    /* execute.a64:1025 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.a64:1025 [F] s_b_11_4: If s_b_11_3: Jump b_12 else b_13 (const) */
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
    /* execute.a64:1026 [D] s_b_12_0 = sym_14751_0_address uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_92446_0_data16 */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_92446_0_data16, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.a64:1803 [F] s_b_12_2=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:1803 [D] s_b_12_3 = sym_92446_0_data16 uint16_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_92446_0_data16, emitter.context().types().u16());
    /* execute.simd:6312 [D] s_b_12_4 = (u64)s_b_12_3 */
    auto s_b_12_4 = emitter.zx(s_b_12_3, emitter.context().types().u64());
    /* execute.simd:6312 [D] s_b_12_5: WriteRegBank 2:s_b_12_2 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_4);
    /* execute.simd:6313 [F] s_b_12_6 = constant u64 0 (const) */
    /* execute.simd:6313 [F] s_b_12_7: WriteRegBank 3:s_b_12_2 = s_b_12_6 */
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
    /* execute.a64:1027 [F] s_b_13_0=sym_14745_3_parameter_inst.size (const) */
    /* execute.a64:1027 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:1027 [F] s_b_13_2 = constant u32 2 (const) */
    /* execute.a64:1027 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:1027 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_15 (const) */
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
    /* execute.a64:1028 [D] s_b_14_0 = sym_14751_0_address uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 4 s_b_14_0 => sym_92522_0_data32 */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_92522_0_data32, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(4));
    }
    /* execute.a64:1810 [F] s_b_14_2=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:1810 [D] s_b_14_3 = sym_92522_0_data32 uint32_t */
    auto s_b_14_3 = emitter.load_local(DV_sym_92522_0_data32, emitter.context().types().u32());
    /* execute.simd:6319 [D] s_b_14_4 = (u64)s_b_14_3 */
    auto s_b_14_4 = emitter.zx(s_b_14_3, emitter.context().types().u64());
    /* execute.simd:6319 [D] s_b_14_5: WriteRegBank 2:s_b_14_2 = s_b_14_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_14_4);
    /* execute.simd:6320 [F] s_b_14_6 = constant u64 0 (const) */
    /* execute.simd:6320 [F] s_b_14_7: WriteRegBank 3:s_b_14_2 = s_b_14_6 */
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
    /* execute.a64:1029 [F] s_b_15_0=sym_14745_3_parameter_inst.size (const) */
    /* execute.a64:1029 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.a64:1029 [F] s_b_15_2 = constant u32 3 (const) */
    /* execute.a64:1029 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.a64:1029 [F] s_b_15_4: If s_b_15_3: Jump b_16 else b_4 (const) */
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
    /* execute.a64:1030 [D] s_b_16_0 = sym_14751_0_address uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 8 s_b_16_0 => sym_92598_0_data64 */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_92598_0_data64, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(8));
    }
    /* execute.a64:1817 [F] s_b_16_2=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:1817 [D] s_b_16_3 = sym_92598_0_data64 uint64_t */
    auto s_b_16_3 = emitter.load_local(DV_sym_92598_0_data64, emitter.context().types().u64());
    /* execute.simd:6326 [D] s_b_16_4: WriteRegBank 2:s_b_16_2 = s_b_16_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_16_3);
    /* execute.simd:6327 [F] s_b_16_5 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_16_6: WriteRegBank 3:s_b_16_2 = s_b_16_5 */
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
    /* execute.a64:1035 [D] s_b_17_0 = sym_14751_0_address uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* execute.a64:1035 [F] s_b_17_1=sym_14745_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_17_2 = (u64)s_b_17_1 (const) */
    /* ???:4294967295 [D] s_b_17_3 = s_b_17_0+s_b_17_2 */
    auto s_b_17_3 = emitter.add(s_b_17_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1035 [D] s_b_17_4: sym_14751_0_address = s_b_17_3, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_14751_0_address, s_b_17_3);
    /* execute.a64:1035 [F] s_b_17_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:1038 [F] s_b_18_0 = constant u8 1 (const) */
    /* execute.a64:1038 [D] s_b_18_1 = sym_14751_0_address uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_14751_0_address, emitter.context().types().u64());
    /* execute.a64:1038 [D] s_b_18_2: sym_92633_3_parameter_value = s_b_18_1, dominates: s_b_23_0 s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_92633_3_parameter_value, s_b_18_1);
    /* execute.a64:2809 [F] s_b_18_3 = !s_b_18_0 (const) */
    uint8_t s_b_18_3 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_18_4: If s_b_18_3: Jump b_23 else b_24 (const) */
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
    /* execute.a64:2796 [F] s_b_19_0=sym_14745_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_19_1 = ReadRegBank 0:s_b_19_0 (u64) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_19_2: sym_91887_1__R_s_b_0_5 = s_b_19_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_91887_1__R_s_b_0_5, s_b_19_1);
    /* execute.a64:2796 [F] s_b_19_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_19, b_32,  */
  fixed_block_b_20: 
  {
    /* execute.a64:1008 [D] s_b_20_0 = sym_91887_1__R_s_b_0_5 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_91887_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1008 [D] s_b_20_1: sym_14751_0_address = s_b_20_0, dominates: s_b_1_0 s_b_6_0 s_b_17_0 s_b_18_1 s_b_7_0 s_b_8_0 s_b_10_0 s_b_12_0 s_b_14_0 s_b_16_0  */
    emitter.store_local(DV_sym_14751_0_address, s_b_20_0);
    /* execute.a64:1010 [F] s_b_20_2=sym_14745_3_parameter_inst.P (const) */
    /* execute.a64:1010 [F] s_b_20_3: If s_b_20_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:1786 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_21_1 = sym_91916_3_parameter_address uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_91916_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_21_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_21_1);
    /* execute.a64:0 [F] s_b_21_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_38,  */
  fixed_block_b_22: 
  {
    /* execute.a64:1786 [F] s_b_22_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_22_1 = sym_92107_3_parameter_address uint64_t */
    auto s_b_22_1 = emitter.load_local(DV_sym_92107_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_22_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_22_1);
    /* execute.a64:0 [F] s_b_22_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_18,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2810 [D] s_b_23_0 = sym_92633_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_92633_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_23_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_23_2 = s_b_23_0&s_b_23_1 */
    auto s_b_23_2 = emitter.bitwise_and(s_b_23_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_23_3: sym_92633_3_parameter_value = s_b_23_2, dominates: s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_92633_3_parameter_value, s_b_23_2);
    /* execute.a64:2810 [F] s_b_23_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_18, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2813 [F] s_b_24_0=sym_14745_3_parameter_inst.rn (const) */
    /* execute.a64:2813 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:2813 [F] s_b_24_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_24_4: If s_b_24_3: Jump b_25 else b_26 (const) */
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
    /* execute.a64:2814 [D] s_b_25_0 = sym_92633_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_92633_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_25_1: sym_93684_3_parameter_value = s_b_25_0, dominates: s_b_33_0 s_b_34_0 s_b_35_0  */
    emitter.store_local(DV_sym_93684_3_parameter_value, s_b_25_0);
    /* execute.a64:2777 [F] s_b_25_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_25_3 = __builtin_get_feature */
    uint32_t s_b_25_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_25_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_25_5 = s_b_25_3==s_b_25_4 (const) */
    uint8_t s_b_25_5 = ((uint8_t)(s_b_25_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_25_6: If s_b_25_5: Jump b_33 else b_39 (const) */
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
    /* execute.a64:2816 [F] s_b_26_0=sym_14745_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_26_1 = sym_92633_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_92633_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_26_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_26_1);
    /* execute.a64:2816 [F] s_b_26_3: Jump b_27 (const) */
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
    /* execute.a64:2764 [F] s_b_28_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_28_1 = __builtin_get_feature */
    uint32_t s_b_28_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_28_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(s_b_28_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_28_4: If s_b_28_3: Jump b_29 else b_36 (const) */
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
    /* execute.a64:2765 [D] s_b_29_0 = ReadReg 21 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_29_1: sym_92689_1__R_s_b_28_0 = s_b_29_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_92689_1__R_s_b_28_0, s_b_29_0);
    /* execute.a64:2765 [F] s_b_29_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_36,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2768 [D] s_b_30_0 = ReadReg 21 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_30_1: sym_92689_1__R_s_b_28_0 = s_b_30_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_92689_1__R_s_b_28_0, s_b_30_0);
    /* execute.a64:2768 [F] s_b_30_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_36,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2770 [D] s_b_31_0 = ReadReg 22 (u64) */
    auto s_b_31_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_31_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_31_1: sym_92689_1__R_s_b_28_0 = s_b_31_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_92689_1__R_s_b_28_0, s_b_31_0);
    /* execute.a64:2770 [F] s_b_31_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_29, b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2794 [D] s_b_32_0 = sym_92689_1__R_s_b_28_0 uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_92689_1__R_s_b_28_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_32_1: sym_91887_1__R_s_b_0_5 = s_b_32_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_91887_1__R_s_b_0_5, s_b_32_0);
    /* execute.a64:2794 [F] s_b_32_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_25,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2778 [D] s_b_33_0 = sym_93684_3_parameter_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_93684_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_33_1: WriteReg 21 = s_b_33_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_33_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_33_0);
    /* execute.a64:2778 [F] s_b_33_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_39,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2781 [D] s_b_34_0 = sym_93684_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_93684_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_34_1: WriteReg 21 = s_b_34_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_34_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_34_0);
    /* execute.a64:2781 [F] s_b_34_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_39,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2783 [D] s_b_35_0 = sym_93684_3_parameter_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_93684_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_35_1: WriteReg 22 = s_b_35_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_35_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_35_0);
    /* execute.a64:2783 [F] s_b_35_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_28,  */
  fixed_block_b_36: 
  {
    /* execute.a64:3075 [F] s_b_36_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_36_1 = __builtin_get_feature */
    uint32_t s_b_36_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_36_2 = (u8)s_b_36_1 (const) */
    /* execute.a64:2767 [F] s_b_36_3 = (u32)s_b_36_2 (const) */
    /* execute.a64:2767 [F] s_b_36_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_36_5 = s_b_36_3==s_b_36_4 (const) */
    uint8_t s_b_36_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_36_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_36_6: If s_b_36_5: Jump b_30 else b_31 (const) */
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
    /* execute.a64:2747 [F] s_b_37_0=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_37_1 = sym_94188_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_94188_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_37_2: WriteRegBank 0:s_b_37_0 = s_b_37_1 */
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
    /* execute.a64:2747 [F] s_b_38_0=sym_14745_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_38_1 = sym_94210_3_parameter_value uint64_t */
    auto s_b_38_1 = emitter.load_local(DV_sym_94210_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_38_2: WriteRegBank 0:s_b_38_0 = s_b_38_1 */
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
    /* execute.a64:3075 [F] s_b_39_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_39_1 = __builtin_get_feature */
    uint32_t s_b_39_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_39_2 = (u8)s_b_39_1 (const) */
    /* execute.a64:2780 [F] s_b_39_3 = (u32)s_b_39_2 (const) */
    /* execute.a64:2780 [F] s_b_39_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_39_5 = s_b_39_3==s_b_39_4 (const) */
    uint8_t s_b_39_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_39_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_39_6: If s_b_39_5: Jump b_34 else b_35 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldrh(const arm64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_15748_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_106133_1__R_s_b_14_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_107806_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105705_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105569_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_105485_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_106968_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_106077_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105514_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105760_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_107296_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_108294_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105896_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_105951_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_15742_3_parameter_inst.rn (const) */
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
    /* execute.a64:986 [D] s_b_1_0 = sym_15748_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15748_0_address, emitter.context().types().u64());
    /* execute.a64:986 [F] s_b_1_1=sym_15742_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:986 [D] s_b_1_4: sym_15748_0_address = s_b_1_3, dominates: s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15748_0_address, s_b_1_3);
    /* execute.a64:986 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_11,  */
  fixed_block_b_2: 
  {
    /* execute.a64:989 [F] s_b_2_0=sym_15742_3_parameter_inst.X (const) */
    /* execute.a64:989 [F] s_b_2_1: If s_b_2_0: Jump b_3 else b_5 (const) */
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
    /* execute.a64:990 [F] s_b_3_0=sym_15742_3_parameter_inst.L (const) */
    /* execute.a64:990 [F] s_b_3_1: If s_b_3_0: Jump b_6 else b_7 (const) */
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
    /* execute.a64:999 [F] s_b_4_0=sym_15742_3_parameter_inst.P (const) */
    /* execute.a64:999 [F] s_b_4_1 = !s_b_4_0 (const) */
    uint8_t s_b_4_1 = !insn.P;
    /* execute.a64:999 [F] s_b_4_2: If s_b_4_1: Jump b_8 else b_9 (const) */
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
    /* execute.a64:996 [D] s_b_5_0 = sym_15748_0_address uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_15748_0_address, emitter.context().types().u64());
    /* execute.a64:996 [D] s_b_5_1: sym_105514_3_parameter_address = s_b_5_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_105514_3_parameter_address, s_b_5_0);
    /* ???:4294967295 [D] s_b_5_2 = Load 2 s_b_5_0 => sym_105569_0_data16 */
    auto s_b_5_2 = emitter.load_memory(s_b_5_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_105569_0_data16, s_b_5_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_5_0, s_b_5_2, emitter.const_u8(2));
    }
    /* execute.a64:1740 [D] s_b_5_3 = sym_105569_0_data16 uint16_t */
    auto s_b_5_3 = emitter.load_local(DV_sym_105569_0_data16, emitter.context().types().u16());
    /* execute.a64:1740 [D] s_b_5_4 = (u64)s_b_5_3 */
    auto s_b_5_4 = emitter.zx(s_b_5_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_5_5=sym_15742_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_5_6 = (u32)s_b_5_4 */
    auto s_b_5_6 = emitter.truncate(s_b_5_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_5_7 = (u64)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_5_8: sym_107296_3_parameter_value = s_b_5_7, dominates: s_b_29_1  */
    emitter.store_local(DV_sym_107296_3_parameter_value, s_b_5_7);
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
    /* execute.a64:991 [D] s_b_6_0 = sym_15748_0_address uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_15748_0_address, emitter.context().types().u64());
    /* execute.a64:991 [D] s_b_6_1: sym_105705_3_parameter_address = s_b_6_0, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_105705_3_parameter_address, s_b_6_0);
    /* ???:4294967295 [D] s_b_6_2 = Load 2 s_b_6_0 => sym_105760_0_data16 */
    auto s_b_6_2 = emitter.load_memory(s_b_6_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_105760_0_data16, s_b_6_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_0, s_b_6_2, emitter.const_u8(2));
    }
    /* execute.a64:1742 [D] s_b_6_3 = sym_105760_0_data16 uint16_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_105760_0_data16, emitter.context().types().u16());
    /* execute.a64:1742 [D] s_b_6_4 = (s16)s_b_6_3 */
    auto s_b_6_4 = emitter.reinterpret(s_b_6_3, emitter.context().types().s16());
    /* execute.a64:1742 [D] s_b_6_5 = (s64)s_b_6_4 */
    auto s_b_6_5 = emitter.sx(s_b_6_4, emitter.context().types().s64());
    /* execute.a64:1742 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.reinterpret(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_7=sym_15742_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_6_8 = (u32)s_b_6_6 */
    auto s_b_6_8 = emitter.truncate(s_b_6_6, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_10: sym_107806_3_parameter_value = s_b_6_9, dominates: s_b_30_1  */
    emitter.store_local(DV_sym_107806_3_parameter_value, s_b_6_9);
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
    /* execute.a64:993 [D] s_b_7_0 = sym_15748_0_address uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_15748_0_address, emitter.context().types().u64());
    /* execute.a64:993 [D] s_b_7_1: sym_105896_3_parameter_address = s_b_7_0, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_105896_3_parameter_address, s_b_7_0);
    /* ???:4294967295 [D] s_b_7_2 = Load 2 s_b_7_0 => sym_105951_0_data16 */
    auto s_b_7_2 = emitter.load_memory(s_b_7_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_105951_0_data16, s_b_7_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_0, s_b_7_2, emitter.const_u8(2));
    }
    /* execute.a64:1744 [D] s_b_7_3 = sym_105951_0_data16 uint16_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_105951_0_data16, emitter.context().types().u16());
    /* execute.a64:1744 [D] s_b_7_4 = (s16)s_b_7_3 */
    auto s_b_7_4 = emitter.reinterpret(s_b_7_3, emitter.context().types().s16());
    /* execute.a64:1744 [D] s_b_7_5 = (s64)s_b_7_4 */
    auto s_b_7_5 = emitter.sx(s_b_7_4, emitter.context().types().s64());
    /* execute.a64:1744 [D] s_b_7_6 = (u64)s_b_7_5 */
    auto s_b_7_6 = emitter.reinterpret(s_b_7_5, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_7_7=sym_15742_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_7_8: sym_108294_3_parameter_value = s_b_7_6, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_108294_3_parameter_value, s_b_7_6);
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
    /* execute.a64:1000 [D] s_b_8_0 = sym_15748_0_address uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_15748_0_address, emitter.context().types().u64());
    /* execute.a64:1000 [F] s_b_8_1=sym_15742_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_8_2 = (u64)s_b_8_1 (const) */
    /* ???:4294967295 [D] s_b_8_3 = s_b_8_0+s_b_8_2 */
    auto s_b_8_3 = emitter.add(s_b_8_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1000 [D] s_b_8_4: sym_15748_0_address = s_b_8_3, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_15748_0_address, s_b_8_3);
    /* execute.a64:1000 [F] s_b_8_5: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1003 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:1003 [D] s_b_9_1 = sym_15748_0_address uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_15748_0_address, emitter.context().types().u64());
    /* execute.a64:1003 [D] s_b_9_2: sym_106077_3_parameter_value = s_b_9_1, dominates: s_b_15_0 s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_106077_3_parameter_value, s_b_9_1);
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
    /* execute.a64:2796 [F] s_b_10_0=sym_15742_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_10_2: sym_105485_1__R_s_b_0_5 = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_105485_1__R_s_b_0_5, s_b_10_1);
    /* execute.a64:2796 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_24,  */
  fixed_block_b_11: 
  {
    /* execute.a64:983 [D] s_b_11_0 = sym_105485_1__R_s_b_0_5 uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_105485_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:983 [D] s_b_11_1: sym_15748_0_address = s_b_11_0, dominates: s_b_1_0 s_b_6_0 s_b_8_0 s_b_9_1 s_b_7_0 s_b_5_0  */
    emitter.store_local(DV_sym_15748_0_address, s_b_11_0);
    /* execute.a64:985 [F] s_b_11_2=sym_15742_3_parameter_inst.P (const) */
    /* execute.a64:985 [F] s_b_11_3: If s_b_11_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:1786 [D] s_b_12_1 = sym_105514_3_parameter_address uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_105514_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_12_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_12_1);
    /* execute.a64:0 [F] s_b_12_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_6, b_30,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1786 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_13_1 = sym_105705_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_105705_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7, b_31,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1786 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_14_1 = sym_105896_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_105896_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_14_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_9,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2810 [D] s_b_15_0 = sym_106077_3_parameter_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_106077_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_15_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_15_2 = s_b_15_0&s_b_15_1 */
    auto s_b_15_2 = emitter.bitwise_and(s_b_15_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_15_3: sym_106077_3_parameter_value = s_b_15_2, dominates: s_b_17_0 s_b_18_1  */
    emitter.store_local(DV_sym_106077_3_parameter_value, s_b_15_2);
    /* execute.a64:2810 [F] s_b_15_4: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_9, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2813 [F] s_b_16_0=sym_15742_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_17_0 = sym_106077_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_106077_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_17_1: sym_106968_3_parameter_value = s_b_17_0, dominates: s_b_25_0 s_b_26_0 s_b_27_0  */
    emitter.store_local(DV_sym_106968_3_parameter_value, s_b_17_0);
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
    /* execute.a64:2816 [F] s_b_18_0=sym_15742_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_18_1 = sym_106077_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_106077_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2765 [D] s_b_21_1: sym_106133_1__R_s_b_14_0 = s_b_21_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_106133_1__R_s_b_14_0, s_b_21_0);
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
    /* execute.a64:2768 [D] s_b_22_1: sym_106133_1__R_s_b_14_0 = s_b_22_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_106133_1__R_s_b_14_0, s_b_22_0);
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
    /* execute.a64:2770 [D] s_b_23_1: sym_106133_1__R_s_b_14_0 = s_b_23_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_106133_1__R_s_b_14_0, s_b_23_0);
    /* execute.a64:2770 [F] s_b_23_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_21, b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2794 [D] s_b_24_0 = sym_106133_1__R_s_b_14_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_106133_1__R_s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_24_1: sym_105485_1__R_s_b_0_5 = s_b_24_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_105485_1__R_s_b_0_5, s_b_24_0);
    /* execute.a64:2794 [F] s_b_24_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_17,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2778 [D] s_b_25_0 = sym_106968_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_106968_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_26_0 = sym_106968_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_106968_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_27_0 = sym_106968_3_parameter_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_106968_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_29_0=sym_15742_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_29_1 = sym_107296_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_107296_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_30_0=sym_15742_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_30_1 = sym_107806_3_parameter_value uint64_t */
    auto s_b_30_1 = emitter.load_local(DV_sym_107806_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_31_0=sym_15742_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_31_1 = sym_108294_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_108294_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldtrb(const arm64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldxr(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_118532_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16512_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_118332_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_118460_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_118112_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_119598_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_119576_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_118244_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_118141_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_16506_3_parameter_inst.rn (const) */
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
    /* execute.a64:859 [D] s_b_1_0 = sym_16512_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16512_0_address, emitter.context().types().u64());
    /* execute.a64:859 [D] s_b_1_1: sym_118141_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_118141_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2 = Load 4 s_b_1_0 => sym_118244_0_data32 */
    auto s_b_1_2 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_118244_0_data32, s_b_1_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_2, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_1_3 = sym_118244_0_data32 uint32_t */
    auto s_b_1_3 = emitter.load_local(DV_sym_118244_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_5=sym_16506_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_6 = (u32)s_b_1_4 */
    auto s_b_1_6 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_8: sym_119576_3_parameter_value = s_b_1_7, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_119576_3_parameter_value, s_b_1_7);
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
    /* execute.a64:861 [D] s_b_3_0 = sym_16512_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_16512_0_address, emitter.context().types().u64());
    /* execute.a64:861 [D] s_b_3_1: sym_118332_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_118332_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2 = Load 8 s_b_3_0 => sym_118460_0_data64 */
    auto s_b_3_2 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_118460_0_data64, s_b_3_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_3_3 = sym_118460_0_data64 uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_118460_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_3_4=sym_16506_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_3_5: sym_119598_3_parameter_value = s_b_3_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_119598_3_parameter_value, s_b_3_3);
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
    /* execute.a64:2796 [F] s_b_4_0=sym_16506_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_4_2: sym_118112_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_118112_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2796 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:856 [D] s_b_5_0 = sym_118112_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_118112_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:856 [D] s_b_5_1: sym_16512_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_16512_0_address, s_b_5_0);
    /* execute.a64:858 [F] s_b_5_2=sym_16506_3_parameter_inst.size (const) */
    /* execute.a64:858 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:858 [F] s_b_5_4 = constant u32 2 (const) */
    /* execute.a64:858 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:858 [F] s_b_5_6: If s_b_5_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1786 [D] s_b_6_1 = sym_118141_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_118141_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* execute.a64:0 [F] s_b_6_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3, b_15,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1786 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_7_1 = sym_118332_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_118332_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2765 [D] s_b_9_1: sym_118532_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_118532_1__R_s_b_7_0, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_118532_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_118532_1__R_s_b_7_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_118532_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_118532_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2794 [D] s_b_12_0 = sym_118532_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_118532_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_12_1: sym_118112_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_118112_1__R_s_b_0_5, s_b_12_0);
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
    /* execute.a64:2747 [F] s_b_14_0=sym_16506_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_14_1 = sym_119576_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_119576_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_15_0=sym_16506_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_15_1 = sym_119598_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_119598_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_movi(const arm64_decode_a64_SIMD_MOD_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4998 [F] s_b_0_0=sym_16871_3_parameter_inst.Q (const) */
    /* execute.simd:4998 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4998 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4998 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:4998 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4999 [F] s_b_1_0=sym_16871_3_parameter_inst.rd (const) */
    /* execute.simd:4999 [F] s_b_1_1=sym_16871_3_parameter_inst.immu64 (const) */
    /* execute.simd:6326 [F] s_b_1_2: WriteRegBank 2:s_b_1_0 = s_b_1_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6327 [F] s_b_1_3 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_1_4: WriteRegBank 3:s_b_1_0 = s_b_1_3 */
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
    /* execute.simd:5001 [F] s_b_3_0=sym_16871_3_parameter_inst.rd (const) */
    /* execute.simd:5001 [F] s_b_3_1=sym_16871_3_parameter_inst.immu64 (const) */
    /* execute.simd:5001 [F] s_b_3_2=sym_16871_3_parameter_inst.immu64 (const) */
    /* execute.simd:6333 [F] s_b_3_3: WriteRegBank 2:s_b_3_0 = s_b_3_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6334 [F] s_b_3_4: WriteRegBank 3:s_b_3_0 = s_b_3_2 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_msub(const arm64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_126974_1_temporary_value;
  auto DV_sym_126974_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_126999_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126932_1_tmp_s_b_18_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126845_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127029_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127051_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_126859_1_temporary_value;
  auto DV_sym_126859_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126756_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_126887_1_temporary_value;
  auto DV_sym_126887_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_126775_1_temporary_value;
  auto DV_sym_126775_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_126803_1_temporary_value;
  auto DV_sym_126803_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_126837_1__R_s_b_4_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126929_1_tmp_s_b_18_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_126946_1_temporary_value;
  auto DV_sym_126946_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126921_1__R_s_b_18_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2412 [F] s_b_0_0=sym_19121_3_parameter_inst.sf (const) */
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
    /* execute.a64:2720 [F] s_b_1_0=sym_19121_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2714 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
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
    /* execute.a64:2722 [F] s_b_2_0=sym_19121_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2709 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
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
    /* execute.a64:2412 [D] s_b_3_0 = sym_126756_1__R_s_b_0_4 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_126756_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2413 [F] s_b_3_1=sym_19121_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_126845_1_tmp_s_b_4_0 = s_b_3_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_126845_1_tmp_s_b_4_0, s_b_3_0);
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
    /* execute.a64:2714 [F] s_b_4_1: sym_126775_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_126775_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_126775_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2714 [F] s_b_5_0=sym_19121_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_5_2: sym_126775_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_126775_1_temporary_value, s_b_5_1);
    /* execute.a64:2714 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2714 [D] s_b_6_0 = sym_126775_1_temporary_value uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_126775_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_6_1: sym_126756_1__R_s_b_0_4 = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_126756_1__R_s_b_0_4, s_b_6_0);
    /* execute.a64:2720 [F] s_b_6_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2709 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_7_1: sym_126803_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_126803_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_126803_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2709 [F] s_b_8_0=sym_19121_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_8_1 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_8_2: sym_126803_1_temporary_value = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_126803_1_temporary_value, s_b_8_1);
    /* execute.a64:2709 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2709 [D] s_b_9_0 = sym_126803_1_temporary_value uint32_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_126803_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_9_1 = (u64)s_b_9_0 */
    auto s_b_9_1 = emitter.zx(s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_9_2: sym_126756_1__R_s_b_0_4 = s_b_9_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_126756_1__R_s_b_0_4, s_b_9_1);
    /* execute.a64:2722 [F] s_b_9_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2720 [F] s_b_10_0=sym_19121_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:2714 [F] s_b_10_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
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
    /* execute.a64:2722 [F] s_b_11_0=sym_19121_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.a64:2709 [F] s_b_11_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
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
    /* ???:4294967295 [D] s_b_12_0 = sym_126845_1_tmp_s_b_4_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_126845_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2413 [D] s_b_12_1 = sym_126837_1__R_s_b_4_5 uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_126837_1__R_s_b_4_5, emitter.context().types().u64());
    /* execute.a64:2414 [F] s_b_12_2=sym_19121_3_parameter_inst.sf (const) */
    /* ???:4294967295 [D] s_b_12_3: sym_126929_1_tmp_s_b_18_0 = s_b_12_0, dominates: s_b_21_1  */
    emitter.store_local(DV_sym_126929_1_tmp_s_b_18_0, s_b_12_0);
    /* ???:4294967295 [D] s_b_12_4: sym_126932_1_tmp_s_b_18_1 = s_b_12_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_126932_1_tmp_s_b_18_1, s_b_12_1);
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
    /* execute.a64:2714 [F] s_b_13_1: sym_126859_1_temporary_value = s_b_13_0 (const), dominates: s_b_15_0  */
    CV_sym_126859_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_126859_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2714 [F] s_b_14_0=sym_19121_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_14_2: sym_126859_1_temporary_value = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_126859_1_temporary_value, s_b_14_1);
    /* execute.a64:2714 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2714 [D] s_b_15_0 = sym_126859_1_temporary_value uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_126859_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_15_1: sym_126837_1__R_s_b_4_5 = s_b_15_0, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_126837_1__R_s_b_4_5, s_b_15_0);
    /* execute.a64:2720 [F] s_b_15_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_11,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [F] s_b_16_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_16_1: sym_126887_1_temporary_value = s_b_16_0 (const), dominates: s_b_18_0  */
    CV_sym_126887_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_126887_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_11,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2709 [F] s_b_17_0=sym_19121_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_17_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_17_2: sym_126887_1_temporary_value = s_b_17_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_126887_1_temporary_value, s_b_17_1);
    /* execute.a64:2709 [F] s_b_17_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_16, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2709 [D] s_b_18_0 = sym_126887_1_temporary_value uint32_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_126887_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_18_1 = (u64)s_b_18_0 */
    auto s_b_18_1 = emitter.zx(s_b_18_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_18_2: sym_126837_1__R_s_b_4_5 = s_b_18_1, dominates: s_b_12_1  */
    emitter.store_local(DV_sym_126837_1__R_s_b_4_5, s_b_18_1);
    /* execute.a64:2722 [F] s_b_18_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_12,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2720 [F] s_b_19_0=sym_19121_3_parameter_inst.ra (const) */
    /* execute.a64:2714 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2714 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
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
    /* execute.a64:2722 [F] s_b_20_0=sym_19121_3_parameter_inst.ra (const) */
    /* execute.a64:2709 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
    /* execute.a64:2709 [F] s_b_20_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
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
    /* ???:4294967295 [D] s_b_21_0 = sym_126932_1_tmp_s_b_18_1 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_126932_1_tmp_s_b_18_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_1 = sym_126929_1_tmp_s_b_18_0 uint64_t */
    auto s_b_21_1 = emitter.load_local(DV_sym_126929_1_tmp_s_b_18_0, emitter.context().types().u64());
    /* execute.a64:2414 [D] s_b_21_2 = sym_126921_1__R_s_b_18_6 uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_126921_1__R_s_b_18_6, emitter.context().types().u64());
    /* execute.a64:2416 [D] s_b_21_3 = (u64)s_b_21_1 */
    auto s_b_21_3 = (captive::arch::dbt::el::Value *)s_b_21_1;
    /* execute.a64:2416 [D] s_b_21_4 = s_b_21_3*s_b_21_0 */
    auto s_b_21_4 = emitter.mul(s_b_21_3, s_b_21_0);
    /* execute.a64:2416 [D] s_b_21_5 = s_b_21_2-s_b_21_4 */
    auto s_b_21_5 = emitter.sub(s_b_21_2, s_b_21_4);
    /* execute.a64:2417 [F] s_b_21_6=sym_19121_3_parameter_inst.sf (const) */
    /* execute.a64:2417 [D] s_b_21_7: sym_126999_3_parameter_value = s_b_21_5, dominates: s_b_28_1 s_b_29_1  */
    emitter.store_local(DV_sym_126999_3_parameter_value, s_b_21_5);
    /* execute.a64:2753 [F] s_b_21_8: If s_b_21_6: Jump b_28 else b_29 (const) */
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
    /* execute.a64:2714 [F] s_b_22_1: sym_126946_1_temporary_value = s_b_22_0 (const), dominates: s_b_24_0  */
    CV_sym_126946_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_126946_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_22_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [F] s_b_23_0=sym_19121_3_parameter_inst.ra (const) */
    /* execute.a64:2714 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_23_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_23_2: sym_126946_1_temporary_value = s_b_23_1, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_126946_1_temporary_value, s_b_23_1);
    /* execute.a64:2714 [F] s_b_23_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [D] s_b_24_0 = sym_126946_1_temporary_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_126946_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_24_1: sym_126921_1__R_s_b_18_6 = s_b_24_0, dominates: s_b_21_2  */
    emitter.store_local(DV_sym_126921_1__R_s_b_18_6, s_b_24_0);
    /* execute.a64:2720 [F] s_b_24_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2709 [F] s_b_25_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_25_1: sym_126974_1_temporary_value = s_b_25_0 (const), dominates: s_b_27_0  */
    CV_sym_126974_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_126974_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_25_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_20,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2709 [F] s_b_26_0=sym_19121_3_parameter_inst.ra (const) */
    /* execute.a64:2709 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_26_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_26_2: sym_126974_1_temporary_value = s_b_26_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_126974_1_temporary_value, s_b_26_1);
    /* execute.a64:2709 [F] s_b_26_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_25, b_26,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2709 [D] s_b_27_0 = sym_126974_1_temporary_value uint32_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_126974_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_27_1 = (u64)s_b_27_0 */
    auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_27_2: sym_126921_1__R_s_b_18_6 = s_b_27_1, dominates: s_b_21_2  */
    emitter.store_local(DV_sym_126921_1__R_s_b_18_6, s_b_27_1);
    /* execute.a64:2722 [F] s_b_27_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_21,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2754 [F] s_b_28_0=sym_19121_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_28_1 = sym_126999_3_parameter_value uint64_t */
    auto s_b_28_1 = emitter.load_local(DV_sym_126999_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_28_2: sym_127029_3_parameter_value = s_b_28_1, dominates: s_b_31_1  */
    emitter.store_local(DV_sym_127029_3_parameter_value, s_b_28_1);
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
    /* execute.a64:2756 [F] s_b_29_0=sym_19121_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_29_1 = sym_126999_3_parameter_value uint64_t */
    auto s_b_29_1 = emitter.load_local(DV_sym_126999_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_29_2 = (u32)s_b_29_1 */
    auto s_b_29_2 = emitter.truncate(s_b_29_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_29_3 = (u64)s_b_29_2 */
    auto s_b_29_3 = emitter.zx(s_b_29_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_29_4: sym_127051_3_parameter_value = s_b_29_3, dominates: s_b_32_1  */
    emitter.store_local(DV_sym_127051_3_parameter_value, s_b_29_3);
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
    /* execute.a64:2747 [F] s_b_31_0=sym_19121_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_31_1 = sym_127029_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_127029_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_32_0=sym_19121_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_32_1 = sym_127051_3_parameter_value uint64_t */
    auto s_b_32_1 = emitter.load_local(DV_sym_127051_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_orri(const arm64_decode_a64_LOGICAL_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_127493_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_127534_1_temporary_value;
  auto DV_sym_127534_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_127562_1_temporary_value;
  auto DV_sym_127562_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_127456_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127623_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127588_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19641_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127441_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:215 [F] s_b_0_0=sym_19636_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_0_1: If s_b_0_0: Jump b_4 else b_5 (const) */
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
    /* execute.a64:218 [D] s_b_1_0 = sym_19641_0_op1 uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_19641_0_op1, emitter.context().types().u64());
    /* execute.a64:218 [F] s_b_1_1=sym_19636_3_parameter_inst.immu64 (const) */
    /* execute.a64:218 [D] s_b_1_2 = s_b_1_0|s_b_1_1 */
    auto s_b_1_2 = emitter.bitwise_or(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.a64:219 [F] s_b_1_3 = constant u8 1 (const) */
    /* execute.a64:219 [D] s_b_1_4: sym_127456_3_parameter_value = s_b_1_2, dominates: s_b_7_0 s_b_9_0 s_b_10_1  */
    emitter.store_local(DV_sym_127456_3_parameter_value, s_b_1_2);
    /* execute.a64:2809 [F] s_b_1_5 = !s_b_1_3 (const) */
    uint8_t s_b_1_5 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_1_6: If s_b_1_5: Jump b_7 else b_8 (const) */
    if (s_b_1_5) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_10, b_14, b_21, b_22, b_23, b_24, b_25, b_26,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_6,  */
  fixed_block_b_3: 
  {
    /* execute.a64:221 [D] s_b_3_0 = sym_19641_0_op1 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_19641_0_op1, emitter.context().types().u64());
    /* execute.a64:221 [D] s_b_3_1 = (u32)s_b_3_0 */
    auto s_b_3_1 = emitter.truncate(s_b_3_0, emitter.context().types().u32());
    /* execute.a64:221 [F] s_b_3_2=sym_19636_3_parameter_inst.immu32 (const) */
    /* execute.a64:221 [D] s_b_3_3 = s_b_3_1|s_b_3_2 */
    auto s_b_3_3 = emitter.bitwise_or(s_b_3_1, emitter.const_u32(insn.immu32));
    /* execute.a64:222 [F] s_b_3_4 = constant u8 0 (const) */
    /* execute.a64:222 [D] s_b_3_5 = (u64)s_b_3_3 */
    auto s_b_3_5 = emitter.zx(s_b_3_3, emitter.context().types().u64());
    /* execute.a64:222 [D] s_b_3_6: sym_127493_3_parameter_value = s_b_3_5, dominates: s_b_11_0 s_b_13_0 s_b_14_1  */
    emitter.store_local(DV_sym_127493_3_parameter_value, s_b_3_5);
    /* execute.a64:2809 [F] s_b_3_7 = !s_b_3_4 (const) */
    uint8_t s_b_3_7 = !(uint8_t)0ULL;
    /* execute.a64:2809 [F] s_b_3_8: If s_b_3_7: Jump b_11 else b_12 (const) */
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
    /* execute.a64:2720 [F] s_b_4_0=sym_19636_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2714 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_4_4: If s_b_4_3: Jump b_15 else b_16 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2722 [F] s_b_5_0=sym_19636_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2709 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_5_4: If s_b_5_3: Jump b_18 else b_19 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_17, b_20,  */
  fixed_block_b_6: 
  {
    /* execute.a64:215 [D] s_b_6_0 = sym_127441_1__R_s_b_0_4 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_127441_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:215 [D] s_b_6_1: sym_19641_0_op1 = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_19641_0_op1, s_b_6_0);
    /* execute.a64:217 [F] s_b_6_2=sym_19636_3_parameter_inst.sf (const) */
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
    /* execute.a64:2810 [D] s_b_7_0 = sym_127456_3_parameter_value uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_127456_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_7_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_7_2 = s_b_7_0&s_b_7_1 */
    auto s_b_7_2 = emitter.bitwise_and(s_b_7_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_7_3: sym_127456_3_parameter_value = s_b_7_2, dominates: s_b_9_0 s_b_10_1  */
    emitter.store_local(DV_sym_127456_3_parameter_value, s_b_7_2);
    /* execute.a64:2810 [F] s_b_7_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_1, b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2813 [F] s_b_8_0=sym_19636_3_parameter_inst.rd (const) */
    /* execute.a64:2813 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2813 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_8_4: If s_b_8_3: Jump b_9 else b_10 (const) */
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
    /* execute.a64:2814 [D] s_b_9_0 = sym_127456_3_parameter_value uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_127456_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_9_1: sym_127588_3_parameter_value = s_b_9_0, dominates: s_b_21_0 s_b_22_0 s_b_23_0  */
    emitter.store_local(DV_sym_127588_3_parameter_value, s_b_9_0);
    /* execute.a64:2777 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_9_3 = __builtin_get_feature */
    uint32_t s_b_9_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_9_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
    uint8_t s_b_9_5 = ((uint8_t)(s_b_9_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_9_6: If s_b_9_5: Jump b_21 else b_27 (const) */
    if (s_b_9_5) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2816 [F] s_b_10_0=sym_19636_3_parameter_inst.rd (const) */
    /* execute.a64:2816 [D] s_b_10_1 = sym_127456_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_127456_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_10_1);
    /* execute.a64:2816 [F] s_b_10_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2810 [D] s_b_11_0 = sym_127493_3_parameter_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_127493_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_11_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_11_2 = s_b_11_0&s_b_11_1 */
    auto s_b_11_2 = emitter.bitwise_and(s_b_11_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_11_3: sym_127493_3_parameter_value = s_b_11_2, dominates: s_b_13_0 s_b_14_1  */
    emitter.store_local(DV_sym_127493_3_parameter_value, s_b_11_2);
    /* execute.a64:2810 [F] s_b_11_4: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_3, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2813 [F] s_b_12_0=sym_19636_3_parameter_inst.rd (const) */
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
    /* execute.a64:2814 [D] s_b_13_0 = sym_127493_3_parameter_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_127493_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_13_1: sym_127623_3_parameter_value = s_b_13_0, dominates: s_b_24_0 s_b_25_0 s_b_26_0  */
    emitter.store_local(DV_sym_127623_3_parameter_value, s_b_13_0);
    /* execute.a64:2777 [F] s_b_13_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_13_3 = __builtin_get_feature */
    uint32_t s_b_13_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_13_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_13_5 = s_b_13_3==s_b_13_4 (const) */
    uint8_t s_b_13_5 = ((uint8_t)(s_b_13_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_13_6: If s_b_13_5: Jump b_24 else b_28 (const) */
    if (s_b_13_5) 
    {
      goto fixed_block_b_24;
    }
    else 
    {
      goto fixed_block_b_28;
    }
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2816 [F] s_b_14_0=sym_19636_3_parameter_inst.rd (const) */
    /* execute.a64:2816 [D] s_b_14_1 = sym_127493_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_127493_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1);
    /* execute.a64:2816 [F] s_b_14_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2714 [F] s_b_15_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_15_1: sym_127534_1_temporary_value = s_b_15_0 (const), dominates: s_b_17_0  */
    CV_sym_127534_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_127534_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_4,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2714 [F] s_b_16_0=sym_19636_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_16_1 = ReadRegBank 0:s_b_16_0 (u64) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_16_2: sym_127534_1_temporary_value = s_b_16_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_127534_1_temporary_value, s_b_16_1);
    /* execute.a64:2714 [F] s_b_16_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2714 [D] s_b_17_0 = sym_127534_1_temporary_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_127534_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_17_1: sym_127441_1__R_s_b_0_4 = s_b_17_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_127441_1__R_s_b_0_4, s_b_17_0);
    /* execute.a64:2720 [F] s_b_17_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2709 [F] s_b_18_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_18_1: sym_127562_1_temporary_value = s_b_18_0 (const), dominates: s_b_20_0  */
    CV_sym_127562_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_127562_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_18_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2709 [F] s_b_19_0=sym_19636_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_19_1 = ReadRegBank 1:s_b_19_0 (u32) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_19_2: sym_127562_1_temporary_value = s_b_19_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_127562_1_temporary_value, s_b_19_1);
    /* execute.a64:2709 [F] s_b_19_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_18, b_19,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2709 [D] s_b_20_0 = sym_127562_1_temporary_value uint32_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_127562_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_20_1 = (u64)s_b_20_0 */
    auto s_b_20_1 = emitter.zx(s_b_20_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_20_2: sym_127441_1__R_s_b_0_4 = s_b_20_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_127441_1__R_s_b_0_4, s_b_20_1);
    /* execute.a64:2722 [F] s_b_20_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_9,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2778 [D] s_b_21_0 = sym_127588_3_parameter_value uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_127588_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_21_1: WriteReg 21 = s_b_21_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_21_0);
    /* execute.a64:2778 [F] s_b_21_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_27,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2781 [D] s_b_22_0 = sym_127588_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_127588_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_22_1: WriteReg 21 = s_b_22_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_22_0);
    /* execute.a64:2781 [F] s_b_22_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_27,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2783 [D] s_b_23_0 = sym_127588_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_127588_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_23_1: WriteReg 22 = s_b_23_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_23_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_23_0);
    /* execute.a64:2783 [F] s_b_23_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_13,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2778 [D] s_b_24_0 = sym_127623_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_127623_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_24_1: WriteReg 21 = s_b_24_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_24_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_24_0);
    /* execute.a64:2778 [F] s_b_24_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_28,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2781 [D] s_b_25_0 = sym_127623_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_127623_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_25_1: WriteReg 21 = s_b_25_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_25_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_25_0);
    /* execute.a64:2781 [F] s_b_25_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_28,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2783 [D] s_b_26_0 = sym_127623_3_parameter_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_127623_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_26_1: WriteReg 22 = s_b_26_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_26_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_26_0);
    /* execute.a64:2783 [F] s_b_26_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_27: 
  {
    /* execute.a64:3075 [F] s_b_27_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_27_1 = __builtin_get_feature */
    uint32_t s_b_27_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_27_2 = (u8)s_b_27_1 (const) */
    /* execute.a64:2780 [F] s_b_27_3 = (u32)s_b_27_2 (const) */
    /* execute.a64:2780 [F] s_b_27_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_27_5 = s_b_27_3==s_b_27_4 (const) */
    uint8_t s_b_27_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_27_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_27_6: If s_b_27_5: Jump b_22 else b_23 (const) */
    if (s_b_27_5) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_13,  */
  fixed_block_b_28: 
  {
    /* execute.a64:3075 [F] s_b_28_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_28_1 = __builtin_get_feature */
    uint32_t s_b_28_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_28_2 = (u8)s_b_28_1 (const) */
    /* execute.a64:2780 [F] s_b_28_3 = (u32)s_b_28_2 (const) */
    /* execute.a64:2780 [F] s_b_28_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
    uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_28_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_28_6: If s_b_28_5: Jump b_25 else b_26 (const) */
    if (s_b_28_5) 
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_rbit(const arm64_decode_a64_DP_1S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_128564_1__R_s_b_0_7 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_128615_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_128707_1_temporary_value;
  auto DV_sym_128707_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_128679_1_temporary_value;
  auto DV_sym_128679_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_128736_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_20161_0_output;
  auto DV_sym_20161_0_output = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_20167_0_input = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_128758_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2217 [F] s_b_0_0 = constant u64 0 (const) */
    /* execute.a64:2217 [F] s_b_0_1: sym_20161_0_output = s_b_0_0 (const), dominates:  */
    CV_sym_20161_0_output = (uint64_t)0ULL;
    /* execute.a64:2218 [F] s_b_0_2=sym_20158_3_parameter_inst.sf (const) */
    /* execute.a64:2719 [F] s_b_0_3: If s_b_0_2: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2221 [D] s_b_1_0 = sym_20167_0_input uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_20167_0_input, emitter.context().types().u64());
    /* execute.a64:2221 [D] s_b_1_1 = (u32)s_b_1_0 */
    auto s_b_1_1 = emitter.truncate(s_b_1_0, emitter.context().types().u32());
    /* execute.a64:2612 [F] s_b_1_2 = constant u32 aaaaaaaa (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_1&s_b_1_2 */
    auto s_b_1_3 = emitter.bitwise_and(s_b_1_1, emitter.const_u32((uint32_t)2863311530ULL));
    /* execute.a64:2613 [F] s_b_1_4 = constant u32 2 (const) */
    /* execute.a64:2613 [D] s_b_1_5 = s_b_1_3>>>s_b_1_4 */
    auto s_b_1_5 = emitter.ror(s_b_1_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.a64:2614 [F] s_b_1_6 = constant u32 55555555 (const) */
    /* ???:4294967295 [D] s_b_1_7 = s_b_1_1&s_b_1_6 */
    auto s_b_1_7 = emitter.bitwise_and(s_b_1_1, emitter.const_u32((uint32_t)1431655765ULL));
    /* ???:4294967295 [D] s_b_1_8 = s_b_1_5|s_b_1_7 */
    auto s_b_1_8 = emitter.bitwise_or(s_b_1_5, s_b_1_7);
    /* execute.a64:2618 [F] s_b_1_9 = constant u32 66666666 (const) */
    /* ???:4294967295 [D] s_b_1_10 = s_b_1_8&s_b_1_9 */
    auto s_b_1_10 = emitter.bitwise_and(s_b_1_8, emitter.const_u32((uint32_t)1717986918ULL));
    /* execute.a64:2619 [F] s_b_1_11 = constant u32 4 (const) */
    /* execute.a64:2619 [D] s_b_1_12 = s_b_1_10>>>s_b_1_11 */
    auto s_b_1_12 = emitter.ror(s_b_1_10, emitter.const_u32((uint32_t)4ULL));
    /* execute.a64:2620 [F] s_b_1_13 = constant u32 99999999 (const) */
    /* ???:4294967295 [D] s_b_1_14 = s_b_1_8&s_b_1_13 */
    auto s_b_1_14 = emitter.bitwise_and(s_b_1_8, emitter.const_u32((uint32_t)2576980377ULL));
    /* ???:4294967295 [D] s_b_1_15 = s_b_1_12|s_b_1_14 */
    auto s_b_1_15 = emitter.bitwise_or(s_b_1_12, s_b_1_14);
    /* execute.a64:2624 [F] s_b_1_16 = constant u32 1e1e1e1e (const) */
    /* ???:4294967295 [D] s_b_1_17 = s_b_1_15&s_b_1_16 */
    auto s_b_1_17 = emitter.bitwise_and(s_b_1_15, emitter.const_u32((uint32_t)505290270ULL));
    /* execute.a64:2625 [F] s_b_1_18 = constant u32 8 (const) */
    /* execute.a64:2625 [D] s_b_1_19 = s_b_1_17>>>s_b_1_18 */
    auto s_b_1_19 = emitter.ror(s_b_1_17, emitter.const_u32((uint32_t)8ULL));
    /* execute.a64:2626 [F] s_b_1_20 = constant u32 e1e1e1e1 (const) */
    /* ???:4294967295 [D] s_b_1_21 = s_b_1_15&s_b_1_20 */
    auto s_b_1_21 = emitter.bitwise_and(s_b_1_15, emitter.const_u32((uint32_t)3789677025ULL));
    /* ???:4294967295 [D] s_b_1_22 = s_b_1_19|s_b_1_21 */
    auto s_b_1_22 = emitter.bitwise_or(s_b_1_19, s_b_1_21);
    /* execute.a64:2629 [F] s_b_1_23 = constant u32 7 (const) */
    /* execute.a64:2629 [D] s_b_1_24 = s_b_1_22<<<s_b_1_23 */
    auto s_b_1_24 = emitter.rol(s_b_1_22, emitter.const_u32((uint32_t)7ULL));
    /* execute.a64:2630 [D] s_b_1_25 = __builtin_bswap32 */
    auto s_b_1_25 = emitter.bswap(s_b_1_24);
    /* execute.a64:2221 [D] s_b_1_26 = (u64)s_b_1_25 */
    auto s_b_1_26 = emitter.zx(s_b_1_25, emitter.context().types().u64());
    /* execute.a64:2221 [D] s_b_1_27: sym_20161_0_output = s_b_1_26, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_20161_0_output, s_b_1_26);
    /* execute.a64:2221 [F] s_b_1_28: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2226 [F] s_b_2_0=sym_20158_3_parameter_inst.sf (const) */
    /* execute.a64:2226 [D] s_b_2_1 = sym_20161_0_output uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_20161_0_output, emitter.context().types().u64());
    /* execute.a64:2226 [D] s_b_2_2: sym_128615_3_parameter_value = s_b_2_1, dominates: s_b_7_1 s_b_8_1  */
    emitter.store_local(DV_sym_128615_3_parameter_value, s_b_2_1);
    /* execute.a64:2753 [F] s_b_2_3: If s_b_2_0: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2223 [D] s_b_3_0 = sym_20167_0_input uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_20167_0_input, emitter.context().types().u64());
    /* execute.a64:2587 [F] s_b_3_1 = constant u64 aaaaaaaaaaaaaaaa (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0&s_b_3_1 */
    auto s_b_3_2 = emitter.bitwise_and(s_b_3_0, emitter.const_u64((uint64_t)12297829382473034410ULL));
    /* execute.a64:2588 [F] s_b_3_3 = constant u64 2 (const) */
    /* execute.a64:2588 [D] s_b_3_4 = s_b_3_2>>>s_b_3_3 */
    auto s_b_3_4 = emitter.ror(s_b_3_2, emitter.const_u64((uint64_t)2ULL));
    /* execute.a64:2589 [F] s_b_3_5 = constant u64 5555555555555555 (const) */
    /* ???:4294967295 [D] s_b_3_6 = s_b_3_0&s_b_3_5 */
    auto s_b_3_6 = emitter.bitwise_and(s_b_3_0, emitter.const_u64((uint64_t)6148914691236517205ULL));
    /* ???:4294967295 [D] s_b_3_7 = s_b_3_4|s_b_3_6 */
    auto s_b_3_7 = emitter.bitwise_or(s_b_3_4, s_b_3_6);
    /* execute.a64:2593 [F] s_b_3_8 = constant u64 6666666666666666 (const) */
    /* ???:4294967295 [D] s_b_3_9 = s_b_3_7&s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_and(s_b_3_7, emitter.const_u64((uint64_t)7378697629483820646ULL));
    /* execute.a64:2594 [F] s_b_3_10 = constant u64 4 (const) */
    /* execute.a64:2594 [D] s_b_3_11 = s_b_3_9>>>s_b_3_10 */
    auto s_b_3_11 = emitter.ror(s_b_3_9, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2595 [F] s_b_3_12 = constant u64 9999999999999999 (const) */
    /* ???:4294967295 [D] s_b_3_13 = s_b_3_7&s_b_3_12 */
    auto s_b_3_13 = emitter.bitwise_and(s_b_3_7, emitter.const_u64((uint64_t)11068046444225730969ULL));
    /* ???:4294967295 [D] s_b_3_14 = s_b_3_11|s_b_3_13 */
    auto s_b_3_14 = emitter.bitwise_or(s_b_3_11, s_b_3_13);
    /* execute.a64:2599 [F] s_b_3_15 = constant u64 1e1e1e1e1e1e1e1e (const) */
    /* ???:4294967295 [D] s_b_3_16 = s_b_3_14&s_b_3_15 */
    auto s_b_3_16 = emitter.bitwise_and(s_b_3_14, emitter.const_u64((uint64_t)2170205185142300190ULL));
    /* execute.a64:2600 [F] s_b_3_17 = constant u64 8 (const) */
    /* execute.a64:2600 [D] s_b_3_18 = s_b_3_16>>>s_b_3_17 */
    auto s_b_3_18 = emitter.ror(s_b_3_16, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:2601 [F] s_b_3_19 = constant u64 e1e1e1e1e1e1e1e1 (const) */
    /* ???:4294967295 [D] s_b_3_20 = s_b_3_14&s_b_3_19 */
    auto s_b_3_20 = emitter.bitwise_and(s_b_3_14, emitter.const_u64((uint64_t)16276538888567251425ULL));
    /* ???:4294967295 [D] s_b_3_21 = s_b_3_18|s_b_3_20 */
    auto s_b_3_21 = emitter.bitwise_or(s_b_3_18, s_b_3_20);
    /* execute.a64:2604 [F] s_b_3_22 = constant u64 7 (const) */
    /* execute.a64:2604 [D] s_b_3_23 = s_b_3_21<<<s_b_3_22 */
    auto s_b_3_23 = emitter.rol(s_b_3_21, emitter.const_u64((uint64_t)7ULL));
    /* execute.a64:2605 [D] s_b_3_24 = __builtin_bswap64 */
    auto s_b_3_24 = emitter.bswap(s_b_3_23);
    /* execute.a64:2223 [D] s_b_3_25: sym_20161_0_output = s_b_3_24, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_20161_0_output, s_b_3_24);
    /* execute.a64:2223 [F] s_b_3_26: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2720 [F] s_b_4_0=sym_20158_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.a64:2714 [F] s_b_4_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_4_4: If s_b_4_3: Jump b_10 else b_11 (const) */
    if (s_b_4_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2722 [F] s_b_5_0=sym_20158_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2709 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_5_4: If s_b_5_3: Jump b_13 else b_14 (const) */
    if (s_b_5_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_12, b_15,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2218 [D] s_b_6_0 = sym_128564_1__R_s_b_0_7 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_128564_1__R_s_b_0_7, emitter.context().types().u64());
    /* execute.a64:2218 [D] s_b_6_1: sym_20167_0_input = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_20167_0_input, s_b_6_0);
    /* execute.a64:2220 [F] s_b_6_2=sym_20158_3_parameter_inst.sf (const) */
    /* execute.a64:2220 [F] s_b_6_3 = (u32)s_b_6_2 (const) */
    /* execute.a64:2220 [F] s_b_6_4 = constant u32 0 (const) */
    /* execute.a64:2220 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:2220 [F] s_b_6_6: If s_b_6_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2754 [F] s_b_7_0=sym_20158_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_7_1 = sym_128615_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_128615_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_7_2: sym_128736_3_parameter_value = s_b_7_1, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_128736_3_parameter_value, s_b_7_1);
    /* execute.a64:2745 [F] s_b_7_3 = (u32)s_b_7_0 (const) */
    /* execute.a64:2745 [F] s_b_7_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_7_5 = s_b_7_3==s_b_7_4 (const) */
    uint8_t s_b_7_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_7_6: If s_b_7_5: Jump b_9 else b_16 (const) */
    if (s_b_7_5) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2756 [F] s_b_8_0=sym_20158_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_8_1 = sym_128615_3_parameter_value uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_128615_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_8_2 = (u32)s_b_8_1 */
    auto s_b_8_2 = emitter.truncate(s_b_8_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_8_3 = (u64)s_b_8_2 */
    auto s_b_8_3 = emitter.zx(s_b_8_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_8_4: sym_128758_3_parameter_value = s_b_8_3, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_128758_3_parameter_value, s_b_8_3);
    /* execute.a64:2745 [F] s_b_8_5 = (u32)s_b_8_0 (const) */
    /* execute.a64:2745 [F] s_b_8_6 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_8_7 = s_b_8_5==s_b_8_6 (const) */
    uint8_t s_b_8_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_8_8: If s_b_8_7: Jump b_9 else b_17 (const) */
    if (s_b_8_7) 
    {
      goto fixed_block_b_9;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_7, b_8, b_16, b_17,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [F] s_b_9_0: Return */
    goto fixed_done;
  }
  /* b_4,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2714 [F] s_b_10_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_10_1: sym_128679_1_temporary_value = s_b_10_0 (const), dominates: s_b_12_0  */
    CV_sym_128679_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_128679_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_4,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2714 [F] s_b_11_0=sym_20158_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_11_1 = ReadRegBank 0:s_b_11_0 (u64) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_11_2: sym_128679_1_temporary_value = s_b_11_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_128679_1_temporary_value, s_b_11_1);
    /* execute.a64:2714 [F] s_b_11_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2714 [D] s_b_12_0 = sym_128679_1_temporary_value uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_128679_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_12_1: sym_128564_1__R_s_b_0_7 = s_b_12_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_128564_1__R_s_b_0_7, s_b_12_0);
    /* execute.a64:2720 [F] s_b_12_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_13_1: sym_128707_1_temporary_value = s_b_13_0 (const), dominates: s_b_15_0  */
    CV_sym_128707_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_128707_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_5,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [F] s_b_14_0=sym_20158_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_14_1 = ReadRegBank 1:s_b_14_0 (u32) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_14_2: sym_128707_1_temporary_value = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_128707_1_temporary_value, s_b_14_1);
    /* execute.a64:2709 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2709 [D] s_b_15_0 = sym_128707_1_temporary_value uint32_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_128707_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_15_1 = (u64)s_b_15_0 */
    auto s_b_15_1 = emitter.zx(s_b_15_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_15_2: sym_128564_1__R_s_b_0_7 = s_b_15_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_128564_1__R_s_b_0_7, s_b_15_1);
    /* execute.a64:2722 [F] s_b_15_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_7,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2747 [F] s_b_16_0=sym_20158_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_16_1 = sym_128736_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_128736_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2747 [F] s_b_17_0=sym_20158_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_128758_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_128758_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_1);
    /* execute.a64:0 [F] s_b_17_3: Jump b_9 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_saddl(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5525 [F] s_b_0_0=sym_20761_3_parameter_inst.tb (const) */
    /* execute.simd:5526 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5538 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5550 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5562 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5574 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5586 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5525 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5527 [F] s_b_2_0=sym_20761_3_parameter_inst.rn (const) */
    /* execute.simd:5527 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5527 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:5528 [F] s_b_2_3=sym_20761_3_parameter_inst.rm (const) */
    /* execute.simd:5528 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5528 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5532 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5532 [D] s_b_2_9 = (s16)s_b_2_8 */
    auto s_b_2_9 = emitter.sx(s_b_2_8, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5532 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5532 [D] s_b_2_12 = (s16)s_b_2_11 */
    auto s_b_2_12 = emitter.sx(s_b_2_11, emitter.context().types().s16());
    /* execute.simd:5532 [D] s_b_2_13 = s_b_2_9+s_b_2_12 */
    auto s_b_2_13 = emitter.add(s_b_2_9, s_b_2_12);
    /* execute.simd:5532 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5532 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5532 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5532 [D] s_b_2_18 = (s16)s_b_2_17 */
    auto s_b_2_18 = emitter.sx(s_b_2_17, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5532 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5532 [D] s_b_2_21 = (s16)s_b_2_20 */
    auto s_b_2_21 = emitter.sx(s_b_2_20, emitter.context().types().s16());
    /* execute.simd:5532 [D] s_b_2_22 = s_b_2_18+s_b_2_21 */
    auto s_b_2_22 = emitter.add(s_b_2_18, s_b_2_21);
    /* execute.simd:5532 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5532 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5532 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5532 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5532 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5532 [D] s_b_2_30 = (s16)s_b_2_29 */
    auto s_b_2_30 = emitter.sx(s_b_2_29, emitter.context().types().s16());
    /* execute.simd:5532 [D] s_b_2_31 = s_b_2_27+s_b_2_30 */
    auto s_b_2_31 = emitter.add(s_b_2_27, s_b_2_30);
    /* execute.simd:5532 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5532 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5532 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5532 [D] s_b_2_36 = (s16)s_b_2_35 */
    auto s_b_2_36 = emitter.sx(s_b_2_35, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5532 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5532 [D] s_b_2_39 = (s16)s_b_2_38 */
    auto s_b_2_39 = emitter.sx(s_b_2_38, emitter.context().types().s16());
    /* execute.simd:5532 [D] s_b_2_40 = s_b_2_36+s_b_2_39 */
    auto s_b_2_40 = emitter.add(s_b_2_36, s_b_2_39);
    /* execute.simd:5532 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5532 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5532 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5532 [D] s_b_2_45 = (s16)s_b_2_44 */
    auto s_b_2_45 = emitter.sx(s_b_2_44, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5532 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5532 [D] s_b_2_48 = (s16)s_b_2_47 */
    auto s_b_2_48 = emitter.sx(s_b_2_47, emitter.context().types().s16());
    /* execute.simd:5532 [D] s_b_2_49 = s_b_2_45+s_b_2_48 */
    auto s_b_2_49 = emitter.add(s_b_2_45, s_b_2_48);
    /* execute.simd:5532 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5532 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5532 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5532 [D] s_b_2_54 = (s16)s_b_2_53 */
    auto s_b_2_54 = emitter.sx(s_b_2_53, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5532 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5532 [D] s_b_2_57 = (s16)s_b_2_56 */
    auto s_b_2_57 = emitter.sx(s_b_2_56, emitter.context().types().s16());
    /* execute.simd:5532 [D] s_b_2_58 = s_b_2_54+s_b_2_57 */
    auto s_b_2_58 = emitter.add(s_b_2_54, s_b_2_57);
    /* execute.simd:5532 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5532 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5532 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5532 [D] s_b_2_63 = (s16)s_b_2_62 */
    auto s_b_2_63 = emitter.sx(s_b_2_62, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5532 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5532 [D] s_b_2_66 = (s16)s_b_2_65 */
    auto s_b_2_66 = emitter.sx(s_b_2_65, emitter.context().types().s16());
    /* execute.simd:5532 [D] s_b_2_67 = s_b_2_63+s_b_2_66 */
    auto s_b_2_67 = emitter.add(s_b_2_63, s_b_2_66);
    /* execute.simd:5532 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5532 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5532 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5532 [D] s_b_2_72 = (s16)s_b_2_71 */
    auto s_b_2_72 = emitter.sx(s_b_2_71, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5532 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5532 [D] s_b_2_75 = (s16)s_b_2_74 */
    auto s_b_2_75 = emitter.sx(s_b_2_74, emitter.context().types().s16());
    /* execute.simd:5532 [D] s_b_2_76 = s_b_2_72+s_b_2_75 */
    auto s_b_2_76 = emitter.add(s_b_2_72, s_b_2_75);
    /* execute.simd:5532 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5532 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5535 [F] s_b_2_79=sym_20761_3_parameter_inst.rd (const) */
    /* execute.simd:5535 [D] s_b_2_80 = (v8u16)s_b_2_78 */
    auto s_b_2_80 = emitter.reinterpret(s_b_2_78, emitter.context().types().v8u16());
    /* execute.simd:5535 [D] s_b_2_81: WriteRegBank 18:s_b_2_79 = s_b_2_80 */
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
    /* execute.simd:5539 [F] s_b_3_0=sym_20761_3_parameter_inst.rn (const) */
    /* execute.simd:5539 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5539 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:5540 [F] s_b_3_3=sym_20761_3_parameter_inst.rm (const) */
    /* execute.simd:5540 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5540 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:5544 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5544 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5544 [D] s_b_3_9 = (s16)s_b_3_8 */
    auto s_b_3_9 = emitter.sx(s_b_3_8, emitter.context().types().s16());
    /* execute.simd:5544 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5544 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5544 [D] s_b_3_12 = (s16)s_b_3_11 */
    auto s_b_3_12 = emitter.sx(s_b_3_11, emitter.context().types().s16());
    /* execute.simd:5544 [D] s_b_3_13 = s_b_3_9+s_b_3_12 */
    auto s_b_3_13 = emitter.add(s_b_3_9, s_b_3_12);
    /* execute.simd:5544 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5544 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5544 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5544 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5544 [D] s_b_3_18 = (s16)s_b_3_17 */
    auto s_b_3_18 = emitter.sx(s_b_3_17, emitter.context().types().s16());
    /* execute.simd:5544 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5544 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5544 [D] s_b_3_21 = (s16)s_b_3_20 */
    auto s_b_3_21 = emitter.sx(s_b_3_20, emitter.context().types().s16());
    /* execute.simd:5544 [D] s_b_3_22 = s_b_3_18+s_b_3_21 */
    auto s_b_3_22 = emitter.add(s_b_3_18, s_b_3_21);
    /* execute.simd:5544 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5544 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5544 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5544 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5544 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5544 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5544 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5544 [D] s_b_3_30 = (s16)s_b_3_29 */
    auto s_b_3_30 = emitter.sx(s_b_3_29, emitter.context().types().s16());
    /* execute.simd:5544 [D] s_b_3_31 = s_b_3_27+s_b_3_30 */
    auto s_b_3_31 = emitter.add(s_b_3_27, s_b_3_30);
    /* execute.simd:5544 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5544 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5544 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5544 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5544 [D] s_b_3_36 = (s16)s_b_3_35 */
    auto s_b_3_36 = emitter.sx(s_b_3_35, emitter.context().types().s16());
    /* execute.simd:5544 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5544 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5544 [D] s_b_3_39 = (s16)s_b_3_38 */
    auto s_b_3_39 = emitter.sx(s_b_3_38, emitter.context().types().s16());
    /* execute.simd:5544 [D] s_b_3_40 = s_b_3_36+s_b_3_39 */
    auto s_b_3_40 = emitter.add(s_b_3_36, s_b_3_39);
    /* execute.simd:5544 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5544 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5544 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5544 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5544 [D] s_b_3_45 = (s16)s_b_3_44 */
    auto s_b_3_45 = emitter.sx(s_b_3_44, emitter.context().types().s16());
    /* execute.simd:5544 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5544 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5544 [D] s_b_3_48 = (s16)s_b_3_47 */
    auto s_b_3_48 = emitter.sx(s_b_3_47, emitter.context().types().s16());
    /* execute.simd:5544 [D] s_b_3_49 = s_b_3_45+s_b_3_48 */
    auto s_b_3_49 = emitter.add(s_b_3_45, s_b_3_48);
    /* execute.simd:5544 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5544 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5544 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5544 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5544 [D] s_b_3_54 = (s16)s_b_3_53 */
    auto s_b_3_54 = emitter.sx(s_b_3_53, emitter.context().types().s16());
    /* execute.simd:5544 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5544 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5544 [D] s_b_3_57 = (s16)s_b_3_56 */
    auto s_b_3_57 = emitter.sx(s_b_3_56, emitter.context().types().s16());
    /* execute.simd:5544 [D] s_b_3_58 = s_b_3_54+s_b_3_57 */
    auto s_b_3_58 = emitter.add(s_b_3_54, s_b_3_57);
    /* execute.simd:5544 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5544 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5544 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5544 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5544 [D] s_b_3_63 = (s16)s_b_3_62 */
    auto s_b_3_63 = emitter.sx(s_b_3_62, emitter.context().types().s16());
    /* execute.simd:5544 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5544 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5544 [D] s_b_3_66 = (s16)s_b_3_65 */
    auto s_b_3_66 = emitter.sx(s_b_3_65, emitter.context().types().s16());
    /* execute.simd:5544 [D] s_b_3_67 = s_b_3_63+s_b_3_66 */
    auto s_b_3_67 = emitter.add(s_b_3_63, s_b_3_66);
    /* execute.simd:5544 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5544 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5544 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5544 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5544 [D] s_b_3_72 = (s16)s_b_3_71 */
    auto s_b_3_72 = emitter.sx(s_b_3_71, emitter.context().types().s16());
    /* execute.simd:5544 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5544 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5544 [D] s_b_3_75 = (s16)s_b_3_74 */
    auto s_b_3_75 = emitter.sx(s_b_3_74, emitter.context().types().s16());
    /* execute.simd:5544 [D] s_b_3_76 = s_b_3_72+s_b_3_75 */
    auto s_b_3_76 = emitter.add(s_b_3_72, s_b_3_75);
    /* execute.simd:5544 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5544 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5547 [F] s_b_3_79=sym_20761_3_parameter_inst.rd (const) */
    /* execute.simd:5547 [D] s_b_3_80 = (v8u16)s_b_3_78 */
    auto s_b_3_80 = emitter.reinterpret(s_b_3_78, emitter.context().types().v8u16());
    /* execute.simd:5547 [D] s_b_3_81: WriteRegBank 18:s_b_3_79 = s_b_3_80 */
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
    /* execute.simd:5551 [F] s_b_4_0=sym_20761_3_parameter_inst.rn (const) */
    /* execute.simd:5551 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5551 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:5552 [F] s_b_4_3=sym_20761_3_parameter_inst.rm (const) */
    /* execute.simd:5552 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5552 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5556 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5556 [D] s_b_4_9 = (s32)s_b_4_8 */
    auto s_b_4_9 = emitter.sx(s_b_4_8, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5556 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5556 [D] s_b_4_12 = (s32)s_b_4_11 */
    auto s_b_4_12 = emitter.sx(s_b_4_11, emitter.context().types().s32());
    /* execute.simd:5556 [D] s_b_4_13 = s_b_4_9+s_b_4_12 */
    auto s_b_4_13 = emitter.add(s_b_4_9, s_b_4_12);
    /* execute.simd:5556 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5556 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5556 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5556 [D] s_b_4_18 = (s32)s_b_4_17 */
    auto s_b_4_18 = emitter.sx(s_b_4_17, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5556 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5556 [D] s_b_4_21 = (s32)s_b_4_20 */
    auto s_b_4_21 = emitter.sx(s_b_4_20, emitter.context().types().s32());
    /* execute.simd:5556 [D] s_b_4_22 = s_b_4_18+s_b_4_21 */
    auto s_b_4_22 = emitter.add(s_b_4_18, s_b_4_21);
    /* execute.simd:5556 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5556 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5556 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5556 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5556 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5556 [D] s_b_4_30 = (s32)s_b_4_29 */
    auto s_b_4_30 = emitter.sx(s_b_4_29, emitter.context().types().s32());
    /* execute.simd:5556 [D] s_b_4_31 = s_b_4_27+s_b_4_30 */
    auto s_b_4_31 = emitter.add(s_b_4_27, s_b_4_30);
    /* execute.simd:5556 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5556 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5556 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5556 [D] s_b_4_36 = (s32)s_b_4_35 */
    auto s_b_4_36 = emitter.sx(s_b_4_35, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5556 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5556 [D] s_b_4_39 = (s32)s_b_4_38 */
    auto s_b_4_39 = emitter.sx(s_b_4_38, emitter.context().types().s32());
    /* execute.simd:5556 [D] s_b_4_40 = s_b_4_36+s_b_4_39 */
    auto s_b_4_40 = emitter.add(s_b_4_36, s_b_4_39);
    /* execute.simd:5556 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5556 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5559 [F] s_b_4_43=sym_20761_3_parameter_inst.rd (const) */
    /* execute.simd:5559 [D] s_b_4_44 = (v4u32)s_b_4_42 */
    auto s_b_4_44 = emitter.reinterpret(s_b_4_42, emitter.context().types().v4u32());
    /* execute.simd:5559 [D] s_b_4_45: WriteRegBank 20:s_b_4_43 = s_b_4_44 */
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
    /* execute.simd:5563 [F] s_b_5_0=sym_20761_3_parameter_inst.rn (const) */
    /* execute.simd:5563 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5563 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:5564 [F] s_b_5_3=sym_20761_3_parameter_inst.rm (const) */
    /* execute.simd:5564 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5564 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:5568 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5568 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5568 [D] s_b_5_9 = (s32)s_b_5_8 */
    auto s_b_5_9 = emitter.sx(s_b_5_8, emitter.context().types().s32());
    /* execute.simd:5568 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5568 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5568 [D] s_b_5_12 = (s32)s_b_5_11 */
    auto s_b_5_12 = emitter.sx(s_b_5_11, emitter.context().types().s32());
    /* execute.simd:5568 [D] s_b_5_13 = s_b_5_9+s_b_5_12 */
    auto s_b_5_13 = emitter.add(s_b_5_9, s_b_5_12);
    /* execute.simd:5568 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5568 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5568 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5568 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5568 [D] s_b_5_18 = (s32)s_b_5_17 */
    auto s_b_5_18 = emitter.sx(s_b_5_17, emitter.context().types().s32());
    /* execute.simd:5568 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5568 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5568 [D] s_b_5_21 = (s32)s_b_5_20 */
    auto s_b_5_21 = emitter.sx(s_b_5_20, emitter.context().types().s32());
    /* execute.simd:5568 [D] s_b_5_22 = s_b_5_18+s_b_5_21 */
    auto s_b_5_22 = emitter.add(s_b_5_18, s_b_5_21);
    /* execute.simd:5568 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5568 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5568 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5568 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5568 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5568 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5568 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5568 [D] s_b_5_30 = (s32)s_b_5_29 */
    auto s_b_5_30 = emitter.sx(s_b_5_29, emitter.context().types().s32());
    /* execute.simd:5568 [D] s_b_5_31 = s_b_5_27+s_b_5_30 */
    auto s_b_5_31 = emitter.add(s_b_5_27, s_b_5_30);
    /* execute.simd:5568 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5568 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5568 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5568 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5568 [D] s_b_5_36 = (s32)s_b_5_35 */
    auto s_b_5_36 = emitter.sx(s_b_5_35, emitter.context().types().s32());
    /* execute.simd:5568 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5568 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5568 [D] s_b_5_39 = (s32)s_b_5_38 */
    auto s_b_5_39 = emitter.sx(s_b_5_38, emitter.context().types().s32());
    /* execute.simd:5568 [D] s_b_5_40 = s_b_5_36+s_b_5_39 */
    auto s_b_5_40 = emitter.add(s_b_5_36, s_b_5_39);
    /* execute.simd:5568 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5568 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5571 [F] s_b_5_43=sym_20761_3_parameter_inst.rd (const) */
    /* execute.simd:5571 [D] s_b_5_44 = (v4u32)s_b_5_42 */
    auto s_b_5_44 = emitter.reinterpret(s_b_5_42, emitter.context().types().v4u32());
    /* execute.simd:5571 [D] s_b_5_45: WriteRegBank 20:s_b_5_43 = s_b_5_44 */
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
    /* execute.simd:5575 [F] s_b_6_0=sym_20761_3_parameter_inst.rn (const) */
    /* execute.simd:5575 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5575 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:5576 [F] s_b_6_3=sym_20761_3_parameter_inst.rm (const) */
    /* execute.simd:5576 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5576 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5580 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5580 [D] s_b_6_9 = (s64)s_b_6_8 */
    auto s_b_6_9 = emitter.sx(s_b_6_8, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5580 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5580 [D] s_b_6_12 = (s64)s_b_6_11 */
    auto s_b_6_12 = emitter.sx(s_b_6_11, emitter.context().types().s64());
    /* execute.simd:5580 [D] s_b_6_13 = s_b_6_9+s_b_6_12 */
    auto s_b_6_13 = emitter.add(s_b_6_9, s_b_6_12);
    /* execute.simd:5580 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5580 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5580 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5580 [D] s_b_6_18 = (s64)s_b_6_17 */
    auto s_b_6_18 = emitter.sx(s_b_6_17, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5580 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5580 [D] s_b_6_21 = (s64)s_b_6_20 */
    auto s_b_6_21 = emitter.sx(s_b_6_20, emitter.context().types().s64());
    /* execute.simd:5580 [D] s_b_6_22 = s_b_6_18+s_b_6_21 */
    auto s_b_6_22 = emitter.add(s_b_6_18, s_b_6_21);
    /* execute.simd:5580 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5580 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:5583 [F] s_b_6_25=sym_20761_3_parameter_inst.rd (const) */
    /* execute.simd:5583 [D] s_b_6_26 = (v2u64)s_b_6_24 */
    auto s_b_6_26 = emitter.reinterpret(s_b_6_24, emitter.context().types().v2u64());
    /* execute.simd:5583 [D] s_b_6_27: WriteRegBank 21:s_b_6_25 = s_b_6_26 */
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
    /* execute.simd:5587 [F] s_b_7_0=sym_20761_3_parameter_inst.rn (const) */
    /* execute.simd:5587 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5587 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:5588 [F] s_b_7_3=sym_20761_3_parameter_inst.rm (const) */
    /* execute.simd:5588 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5588 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:5592 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:5592 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5592 [D] s_b_7_9 = (s64)s_b_7_8 */
    auto s_b_7_9 = emitter.sx(s_b_7_8, emitter.context().types().s64());
    /* execute.simd:5592 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:5592 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5592 [D] s_b_7_12 = (s64)s_b_7_11 */
    auto s_b_7_12 = emitter.sx(s_b_7_11, emitter.context().types().s64());
    /* execute.simd:5592 [D] s_b_7_13 = s_b_7_9+s_b_7_12 */
    auto s_b_7_13 = emitter.add(s_b_7_9, s_b_7_12);
    /* execute.simd:5592 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:5592 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:5592 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:5592 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5592 [D] s_b_7_18 = (s64)s_b_7_17 */
    auto s_b_7_18 = emitter.sx(s_b_7_17, emitter.context().types().s64());
    /* execute.simd:5592 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:5592 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5592 [D] s_b_7_21 = (s64)s_b_7_20 */
    auto s_b_7_21 = emitter.sx(s_b_7_20, emitter.context().types().s64());
    /* execute.simd:5592 [D] s_b_7_22 = s_b_7_18+s_b_7_21 */
    auto s_b_7_22 = emitter.add(s_b_7_18, s_b_7_21);
    /* execute.simd:5592 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:5592 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:5595 [F] s_b_7_25=sym_20761_3_parameter_inst.rd (const) */
    /* execute.simd:5595 [D] s_b_7_26 = (v2u64)s_b_7_24 */
    auto s_b_7_26 = emitter.reinterpret(s_b_7_24, emitter.context().types().v2u64());
    /* execute.simd:5595 [D] s_b_7_27: WriteRegBank 21:s_b_7_25 = s_b_7_26 */
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
    /* execute.simd:5599 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5525 [F] s_b_8_1: Jump b_1 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_shl_simd(const arm64_decode_a64_SIMD_SHIFT_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4950 [F] s_b_0_0=sym_22910_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4950 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4951 [F] s_b_1_0=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4951 [F] s_b_1_1=sym_22910_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:4951 [F] s_b_1_3=sym_22910_3_parameter_inst.shift_amount (const) */
    /* execute.simd:4951 [F] s_b_1_4 = (u64)s_b_1_3 (const) */
    /* execute.simd:4951 [D] s_b_1_5 = s_b_1_2<<s_b_1_4 */
    auto s_b_1_5 = emitter.shl(s_b_1_2, emitter.const_u64(((uint64_t)insn.shift_amount)));
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
  /* b_1, b_3, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4953 [F] s_b_3_0=sym_22910_3_parameter_inst.arrangement (const) */
    /* execute.simd:4954 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:4960 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:4965 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:4971 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:4976 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:4982 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:4987 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:4953 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_2 (const) -> b_2, b_4, b_5, b_6, b_7, b_8, b_9, b_10,  */
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
    /* execute.simd:4955 [F] s_b_4_0=sym_22910_3_parameter_inst.rn (const) */
    /* execute.simd:4955 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:4956 [F] s_b_4_2=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4956 [F] s_b_4_3=sym_22910_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_4_4 = (v8u8)s_b_4_3 (const) */
    auto s_b_4_4 = wutils::Vector<uint8_t, 8>(insn.shift_amount);
    /* execute.simd:4956 [D] s_b_4_5 = s_b_4_1<<s_b_4_4 */
    auto s_b_4_5 = emitter.shl(s_b_4_1, emitter.constant_vector_splat(s_b_4_4[0], emitter.context().types().v8u8()));
    /* execute.simd:4956 [D] s_b_4_6: WriteRegBank 15:s_b_4_2 = s_b_4_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_5);
    /* execute.simd:4957 [F] s_b_4_7=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4957 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:4957 [F] s_b_4_9: WriteRegBank 3:s_b_4_7 = s_b_4_8 */
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
    /* execute.simd:4961 [F] s_b_5_0=sym_22910_3_parameter_inst.rn (const) */
    /* execute.simd:4961 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:4962 [F] s_b_5_2=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4962 [F] s_b_5_3=sym_22910_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_5_4 = (v16u8)s_b_5_3 (const) */
    auto s_b_5_4 = wutils::Vector<uint8_t, 16>(insn.shift_amount);
    /* execute.simd:4962 [D] s_b_5_5 = s_b_5_1<<s_b_5_4 */
    auto s_b_5_5 = emitter.shl(s_b_5_1, emitter.constant_vector_splat(s_b_5_4[0], emitter.context().types().v16u8()));
    /* execute.simd:4962 [D] s_b_5_6: WriteRegBank 16:s_b_5_2 = s_b_5_5 */
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
    /* execute.simd:4966 [F] s_b_6_0=sym_22910_3_parameter_inst.rn (const) */
    /* execute.simd:4966 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:4967 [F] s_b_6_2=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4967 [F] s_b_6_3=sym_22910_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_6_4 = (v4u16)s_b_6_3 (const) */
    auto s_b_6_4 = wutils::Vector<uint16_t, 4>(insn.shift_amount);
    /* execute.simd:4967 [D] s_b_6_5 = s_b_6_1<<s_b_6_4 */
    auto s_b_6_5 = emitter.shl(s_b_6_1, emitter.constant_vector_splat(s_b_6_4[0], emitter.context().types().v4u16()));
    /* execute.simd:4967 [D] s_b_6_6: WriteRegBank 17:s_b_6_2 = s_b_6_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_5);
    /* execute.simd:4968 [F] s_b_6_7=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4968 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:4968 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
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
    /* execute.simd:4972 [F] s_b_7_0=sym_22910_3_parameter_inst.rn (const) */
    /* execute.simd:4972 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:4973 [F] s_b_7_2=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4973 [F] s_b_7_3=sym_22910_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_7_4 = (v8u16)s_b_7_3 (const) */
    auto s_b_7_4 = wutils::Vector<uint16_t, 8>(insn.shift_amount);
    /* execute.simd:4973 [D] s_b_7_5 = s_b_7_1<<s_b_7_4 */
    auto s_b_7_5 = emitter.shl(s_b_7_1, emitter.constant_vector_splat(s_b_7_4[0], emitter.context().types().v8u16()));
    /* execute.simd:4973 [D] s_b_7_6: WriteRegBank 18:s_b_7_2 = s_b_7_5 */
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
    /* execute.simd:4977 [F] s_b_8_0=sym_22910_3_parameter_inst.rn (const) */
    /* execute.simd:4977 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:4978 [F] s_b_8_2=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4978 [F] s_b_8_3=sym_22910_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_8_4 = (v2u32)s_b_8_3 (const) */
    auto s_b_8_4 = wutils::Vector<uint32_t, 2>(insn.shift_amount);
    /* execute.simd:4978 [D] s_b_8_5 = s_b_8_1<<s_b_8_4 */
    auto s_b_8_5 = emitter.shl(s_b_8_1, emitter.constant_vector_splat(s_b_8_4[0], emitter.context().types().v2u32()));
    /* execute.simd:4978 [D] s_b_8_6: WriteRegBank 19:s_b_8_2 = s_b_8_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_5);
    /* execute.simd:4979 [F] s_b_8_7=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4979 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:4979 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
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
    /* execute.simd:4983 [F] s_b_9_0=sym_22910_3_parameter_inst.rn (const) */
    /* execute.simd:4983 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:4984 [F] s_b_9_2=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4984 [F] s_b_9_3=sym_22910_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_9_4 = (v4u32)s_b_9_3 (const) */
    auto s_b_9_4 = wutils::Vector<uint32_t, 4>(insn.shift_amount);
    /* execute.simd:4984 [D] s_b_9_5 = s_b_9_1<<s_b_9_4 */
    auto s_b_9_5 = emitter.shl(s_b_9_1, emitter.constant_vector_splat(s_b_9_4[0], emitter.context().types().v4u32()));
    /* execute.simd:4984 [D] s_b_9_6: WriteRegBank 20:s_b_9_2 = s_b_9_5 */
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
    /* execute.simd:4988 [F] s_b_10_0=sym_22910_3_parameter_inst.rn (const) */
    /* execute.simd:4988 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:4989 [F] s_b_10_2=sym_22910_3_parameter_inst.rd (const) */
    /* execute.simd:4989 [F] s_b_10_3=sym_22910_3_parameter_inst.shift_amount (const) */
    /* ???:4294967295 [F] s_b_10_4 = (v2u64)s_b_10_3 (const) */
    auto s_b_10_4 = wutils::Vector<uint64_t, 2>(insn.shift_amount);
    /* execute.simd:4989 [D] s_b_10_5 = s_b_10_1<<s_b_10_4 */
    auto s_b_10_5 = emitter.shl(s_b_10_1, emitter.constant_vector_splat(s_b_10_4[0], emitter.context().types().v2u64()));
    /* execute.simd:4989 [D] s_b_10_6: WriteRegBank 21:s_b_10_2 = s_b_10_5 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_smsubl(const arm64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_133445_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_133305_1_temporary_value;
  auto DV_sym_133305_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_133401_1_tmp_s_b_22_0 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_133404_1_tmp_s_b_22_1 = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_133242_1_temporary_value;
  auto DV_sym_133242_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_133335_1_tmp_s_b_11_0 = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_133356_1_temporary_value;
  auto DV_sym_133356_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2431 [F] s_b_0_0=sym_24915_3_parameter_inst.rn (const) */
    /* execute.a64:2731 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2731 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2731 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2731 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2731 [F] s_b_1_0 = constant s64 0 (const) */
    /* execute.a64:2731 [F] s_b_1_1: sym_133242_1_temporary_value = s_b_1_0 (const), dominates: s_b_3_0  */
    CV_sym_133242_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_133242_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2731 [F] s_b_1_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2731 [F] s_b_2_0=sym_24915_3_parameter_inst.rn (const) */
    /* execute.a64:2731 [D] s_b_2_1 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(4));
    }
    /* execute.a64:2731 [D] s_b_2_2 = (s32)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().s32());
    /* execute.a64:2731 [D] s_b_2_3 = (s64)s_b_2_2 */
    auto s_b_2_3 = emitter.sx(s_b_2_2, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_2_4: sym_133242_1_temporary_value = s_b_2_3, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_133242_1_temporary_value, s_b_2_3);
    /* execute.a64:2731 [F] s_b_2_5: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2731 [D] s_b_3_0 = sym_133242_1_temporary_value int64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_133242_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2432 [F] s_b_3_1=sym_24915_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_133335_1_tmp_s_b_11_0 = s_b_3_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_133335_1_tmp_s_b_11_0, s_b_3_0);
    /* execute.a64:2731 [F] s_b_3_3 = (u32)s_b_3_1 (const) */
    /* execute.a64:2731 [F] s_b_3_4 = constant u32 1f (const) */
    /* execute.a64:2731 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
    uint8_t s_b_3_5 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2731 [F] s_b_3_6: If s_b_3_5: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2731 [F] s_b_4_0 = constant s64 0 (const) */
    /* execute.a64:2731 [F] s_b_4_1: sym_133305_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_133305_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_133305_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2731 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2731 [F] s_b_5_0=sym_24915_3_parameter_inst.rm (const) */
    /* execute.a64:2731 [D] s_b_5_1 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_5_1,emitter.const_u8(4));
    }
    /* execute.a64:2731 [D] s_b_5_2 = (s32)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().s32());
    /* execute.a64:2731 [D] s_b_5_3 = (s64)s_b_5_2 */
    auto s_b_5_3 = emitter.sx(s_b_5_2, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_5_4: sym_133305_1_temporary_value = s_b_5_3, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_133305_1_temporary_value, s_b_5_3);
    /* execute.a64:2731 [F] s_b_5_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2731 [D] s_b_6_0 = sym_133305_1_temporary_value int64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_133305_1_temporary_value, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_6_1 = sym_133335_1_tmp_s_b_11_0 int64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_133335_1_tmp_s_b_11_0, emitter.context().types().s64());
    /* execute.a64:2433 [F] s_b_6_2=sym_24915_3_parameter_inst.ra (const) */
    /* ???:4294967295 [D] s_b_6_3: sym_133401_1_tmp_s_b_22_0 = s_b_6_1, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_133401_1_tmp_s_b_22_0, s_b_6_1);
    /* ???:4294967295 [D] s_b_6_4: sym_133404_1_tmp_s_b_22_1 = s_b_6_0, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_133404_1_tmp_s_b_22_1, s_b_6_0);
    /* execute.a64:2729 [F] s_b_6_5 = (u32)s_b_6_2 (const) */
    /* execute.a64:2729 [F] s_b_6_6 = constant u32 1f (const) */
    /* execute.a64:2729 [F] s_b_6_7 = s_b_6_5==s_b_6_6 (const) */
    uint8_t s_b_6_7 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2729 [F] s_b_6_8: If s_b_6_7: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2729 [F] s_b_7_0 = constant s64 0 (const) */
    /* execute.a64:2729 [F] s_b_7_1: sym_133356_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_133356_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_133356_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2729 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2729 [F] s_b_8_0=sym_24915_3_parameter_inst.ra (const) */
    /* execute.a64:2729 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2729 [D] s_b_8_2 = (s64)s_b_8_1 */
    auto s_b_8_2 = emitter.reinterpret(s_b_8_1, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_8_3: sym_133356_1_temporary_value = s_b_8_2, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_133356_1_temporary_value, s_b_8_2);
    /* execute.a64:2729 [F] s_b_8_4: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2729 [D] s_b_9_0 = sym_133356_1_temporary_value int64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_133356_1_temporary_value, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_9_1 = sym_133404_1_tmp_s_b_22_1 int64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_133404_1_tmp_s_b_22_1, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_9_2 = sym_133401_1_tmp_s_b_22_0 int64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_133401_1_tmp_s_b_22_0, emitter.context().types().s64());
    /* execute.a64:2435 [D] s_b_9_3 = (s64)s_b_9_2 */
    auto s_b_9_3 = (captive::arch::dbt::el::Value *)s_b_9_2;
    /* execute.a64:2435 [D] s_b_9_4 = s_b_9_3*s_b_9_1 */
    auto s_b_9_4 = emitter.mul(s_b_9_3, s_b_9_1);
    /* execute.a64:2435 [D] s_b_9_5 = s_b_9_0-s_b_9_4 */
    auto s_b_9_5 = emitter.sub(s_b_9_0, s_b_9_4);
    /* execute.a64:2435 [D] s_b_9_6 = (u64)s_b_9_5 */
    auto s_b_9_6 = emitter.reinterpret(s_b_9_5, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_9_7=sym_24915_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_9_8: sym_133445_3_parameter_value = s_b_9_6, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_133445_3_parameter_value, s_b_9_6);
    /* execute.a64:2745 [F] s_b_9_9 = (u32)s_b_9_7 (const) */
    /* execute.a64:2745 [F] s_b_9_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_9_11 = s_b_9_9==s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2747 [F] s_b_11_0=sym_24915_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_11_1 = sym_133445_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_133445_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_st1(const arm64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_134714_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_134697_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_134811_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_134814_3_parameter_lane;
  auto DV_sym_134891_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_134888_1_tmp_s_b_5_4;
  uint8_t CV_sym_134806_3_parameter_rt;
  auto DV_sym_30548_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30554_0_rt;
  uint8_t CV_sym_30566_0_lane;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2526 [F] s_b_0_0=sym_30542_3_parameter_inst.rn (const) */
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
    /* execute.simd:2528 [F] s_b_1_0 = sym_30554_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30554_0_rt;
    /* execute.simd:2528 [F] s_b_1_1=sym_30542_3_parameter_inst.regcnt (const) */
    /* execute.simd:2528 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2528 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2529 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2529 [F] s_b_2_1: sym_30566_0_lane = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30566_0_lane = (uint8_t)0ULL;
    /* execute.simd:2529 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2529 [F] s_b_4_0 = sym_30566_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30566_0_lane;
    /* execute.simd:2529 [F] s_b_4_1=sym_30542_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2529 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2529 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2530 [F] s_b_5_0=sym_30542_3_parameter_inst.arrangement (const) */
    /* execute.simd:2530 [F] s_b_5_1=sym_30542_3_parameter_inst.rt (const) */
    /* execute.simd:2530 [F] s_b_5_2 = sym_30554_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30554_0_rt;
    /* execute.simd:2530 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2530 [F] s_b_5_4 = sym_30566_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30566_0_lane;
    /* execute.simd:2530 [D] s_b_5_5 = sym_30548_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30548_0_address, emitter.context().types().u64());
    /* execute.simd:2530 [F] s_b_5_6: sym_134806_3_parameter_rt = s_b_5_3 (const), dominates: s_b_17_0 s_b_16_0 s_b_19_0 s_b_18_0 s_b_22_0 s_b_21_0 s_b_20_0  */
    CV_sym_134806_3_parameter_rt = s_b_5_3;
    /* execute.simd:2530 [F] s_b_5_7: sym_134814_3_parameter_lane = s_b_5_4 (const), dominates: s_b_17_3 s_b_16_3 s_b_19_3 s_b_18_3 s_b_22_3 s_b_21_3 s_b_20_3  */
    CV_sym_134814_3_parameter_lane = s_b_5_4;
    /* execute.simd:2530 [D] s_b_5_8: sym_134811_3_parameter_addr = s_b_5_5, dominates: s_b_17_2 s_b_16_2 s_b_19_2 s_b_18_2 s_b_22_2 s_b_21_2 s_b_20_2  */
    emitter.store_local(DV_sym_134811_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_134888_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_23_1  */
    CV_sym_134888_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_134891_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_134891_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3931 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3936 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3941 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3946 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3951 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3956 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3961 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3930 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_15 (const) -> b_17, b_16, b_19, b_15, b_18, b_22, b_21, b_20,  */
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
    /* execute.simd:2528 [F] s_b_6_0 = sym_30554_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30554_0_rt;
    /* execute.simd:2528 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2528 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2528 [F] s_b_6_3: sym_30554_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30554_0_rt = s_b_6_2;
    /* execute.simd:2528 [F] s_b_6_4: Jump b_1 (const) */
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
    /* execute.a64:2796 [F] s_b_8_0=sym_30542_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_134697_0_return_symbol = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_134697_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_12,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_134697_0_return_symbol uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_134697_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2526 [D] s_b_9_1: sym_30548_0_address = s_b_9_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30548_0_address, s_b_9_0);
    /* execute.simd:2528 [F] s_b_9_2 = constant u8 0 (const) */
    /* execute.simd:2528 [F] s_b_9_3: sym_30554_0_rt = s_b_9_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30554_0_rt = (uint8_t)0ULL;
    /* execute.simd:2528 [F] s_b_9_4: Jump b_1 (const) */
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
    /* execute.a64:2765 [D] s_b_10_1: sym_134714_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_134714_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2794 [D] s_b_12_0 = sym_134714_1__R_s_b_3_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_134714_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1: sym_134697_0_return_symbol = s_b_12_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_134697_0_return_symbol, s_b_12_0);
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
    /* execute.a64:2768 [D] s_b_13_1: sym_134714_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_134714_1__R_s_b_3_0, s_b_13_0);
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
    /* execute.a64:2770 [D] s_b_14_1: sym_134714_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_134714_1__R_s_b_3_0, s_b_14_0);
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
    /* execute.simd:3932 [F] s_b_16_0 = sym_134806_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_0 = CV_sym_134806_3_parameter_rt;
    /* execute.simd:3932 [D] s_b_16_1 = ReadRegBank 15:s_b_16_0 (v8u8) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:3933 [D] s_b_16_2 = sym_134811_3_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_134811_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3933 [F] s_b_16_3 = sym_134814_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_3 = CV_sym_134814_3_parameter_lane;
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
    /* execute.simd:3937 [F] s_b_17_0 = sym_134806_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_0 = CV_sym_134806_3_parameter_rt;
    /* execute.simd:3937 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:3938 [D] s_b_17_2 = sym_134811_3_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_134811_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3938 [F] s_b_17_3 = sym_134814_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_3 = CV_sym_134814_3_parameter_lane;
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
    /* execute.simd:3942 [F] s_b_18_0 = sym_134806_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_134806_3_parameter_rt;
    /* execute.simd:3942 [D] s_b_18_1 = ReadRegBank 17:s_b_18_0 (v4u16) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3943 [D] s_b_18_2 = sym_134811_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_134811_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3943 [F] s_b_18_3 = sym_134814_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_134814_3_parameter_lane;
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
    /* execute.simd:3947 [F] s_b_19_0 = sym_134806_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_134806_3_parameter_rt;
    /* execute.simd:3947 [D] s_b_19_1 = ReadRegBank 18:s_b_19_0 (v8u16) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3948 [D] s_b_19_2 = sym_134811_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_134811_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3948 [F] s_b_19_3 = sym_134814_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_134814_3_parameter_lane;
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
    /* execute.simd:3952 [F] s_b_20_0 = sym_134806_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_134806_3_parameter_rt;
    /* execute.simd:3952 [D] s_b_20_1 = ReadRegBank 19:s_b_20_0 (v2u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3953 [D] s_b_20_2 = sym_134811_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_134811_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3953 [F] s_b_20_3 = sym_134814_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_134814_3_parameter_lane;
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
    /* execute.simd:3957 [F] s_b_21_0 = sym_134806_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_134806_3_parameter_rt;
    /* execute.simd:3957 [D] s_b_21_1 = ReadRegBank 20:s_b_21_0 (v4u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3958 [D] s_b_21_2 = sym_134811_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_134811_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3958 [F] s_b_21_3 = sym_134814_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_134814_3_parameter_lane;
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
    /* execute.simd:3962 [F] s_b_22_0 = sym_134806_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_134806_3_parameter_rt;
    /* execute.simd:3962 [D] s_b_22_1 = ReadRegBank 21:s_b_22_0 (v2u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3963 [D] s_b_22_2 = sym_134811_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_134811_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3963 [F] s_b_22_3 = sym_134814_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_134814_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_23_0 = sym_134891_1_tmp_s_b_5_5 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_134891_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1 = sym_134888_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_23_1 = CV_sym_134888_1_tmp_s_b_5_4;
    /* execute.simd:2531 [F] s_b_23_2=sym_30542_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* ???:4294967295 [D] s_b_23_4 = s_b_23_0+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2531 [D] s_b_23_5: sym_30548_0_address = s_b_23_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_30548_0_address, s_b_23_4);
    /* execute.simd:2529 [F] s_b_23_6 = constant u8 1 (const) */
    /* execute.simd:2529 [F] s_b_23_7 = s_b_23_1+s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(s_b_23_1 + (uint8_t)1ULL));
    /* execute.simd:2529 [F] s_b_23_8: sym_30566_0_lane = s_b_23_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30566_0_lane = s_b_23_7;
    /* execute.simd:2529 [F] s_b_23_9: Jump b_4 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_st4(const arm64_decode_a64_SIMD_LS_MULT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_137297_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137200_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137183_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_137292_3_parameter_rt;
  auto DV_sym_31148_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_31154_0_lane;
  uint8_t CV_sym_31166_0_rt;
  uint8_t CV_sym_137374_1_tmp_s_b_5_2;
  auto DV_sym_137377_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_137300_3_parameter_lane;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2562 [F] s_b_0_0=sym_31142_3_parameter_inst.rn (const) */
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
    /* execute.simd:2564 [F] s_b_1_0 = sym_31154_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_31154_0_lane;
    /* execute.simd:2564 [F] s_b_1_1=sym_31142_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2564 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2564 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2565 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2565 [F] s_b_2_1: sym_31166_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_31166_0_rt = (uint8_t)0ULL;
    /* execute.simd:2565 [F] s_b_2_2: Jump b_4 (const) */
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
    /* execute.simd:2565 [F] s_b_4_0 = sym_31166_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_31166_0_rt;
    /* execute.simd:2565 [F] s_b_4_1=sym_31142_3_parameter_inst.regcnt (const) */
    /* execute.simd:2565 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2565 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2566 [F] s_b_5_0=sym_31142_3_parameter_inst.arrangement (const) */
    /* execute.simd:2566 [F] s_b_5_1=sym_31142_3_parameter_inst.rt (const) */
    /* execute.simd:2566 [F] s_b_5_2 = sym_31166_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_31166_0_rt;
    /* execute.simd:2566 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2566 [F] s_b_5_4 = sym_31154_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_31154_0_lane;
    /* execute.simd:2566 [D] s_b_5_5 = sym_31148_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_31148_0_address, emitter.context().types().u64());
    /* execute.simd:2566 [F] s_b_5_6: sym_137292_3_parameter_rt = s_b_5_3 (const), dominates: s_b_22_0 s_b_21_0 s_b_20_0 s_b_19_0 s_b_18_0 s_b_17_0 s_b_16_0  */
    CV_sym_137292_3_parameter_rt = s_b_5_3;
    /* execute.simd:2566 [F] s_b_5_7: sym_137300_3_parameter_lane = s_b_5_4 (const), dominates: s_b_22_3 s_b_21_3 s_b_20_3 s_b_19_3 s_b_18_3 s_b_17_3 s_b_16_3  */
    CV_sym_137300_3_parameter_lane = s_b_5_4;
    /* execute.simd:2566 [D] s_b_5_8: sym_137297_3_parameter_addr = s_b_5_5, dominates: s_b_22_2 s_b_21_2 s_b_20_2 s_b_19_2 s_b_18_2 s_b_17_2 s_b_16_2  */
    emitter.store_local(DV_sym_137297_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_137374_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_23_1  */
    CV_sym_137374_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_137377_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_137377_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3931 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3936 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3941 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3946 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3951 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3956 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3961 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3930 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_15 (const) -> b_15, b_22, b_21, b_20, b_19, b_18, b_17, b_16,  */
    switch (insn.arrangement) 
    {
    case (int32_t)5ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_19;
      break;
    default:
      goto fixed_block_b_15;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2564 [F] s_b_6_0 = sym_31154_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_31154_0_lane;
    /* execute.simd:2564 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2564 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2564 [F] s_b_6_3: sym_31154_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_31154_0_lane = s_b_6_2;
    /* execute.simd:2564 [F] s_b_6_4: Jump b_1 (const) */
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
    /* execute.a64:2796 [F] s_b_8_0=sym_31142_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_137183_0_return_symbol = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_137183_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_12,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [D] s_b_9_0 = sym_137183_0_return_symbol uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_137183_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2562 [D] s_b_9_1: sym_31148_0_address = s_b_9_0, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_31148_0_address, s_b_9_0);
    /* execute.simd:2564 [F] s_b_9_2 = constant u8 0 (const) */
    /* execute.simd:2564 [F] s_b_9_3: sym_31154_0_lane = s_b_9_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_31154_0_lane = (uint8_t)0ULL;
    /* execute.simd:2564 [F] s_b_9_4: Jump b_1 (const) */
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
    /* execute.a64:2765 [D] s_b_10_1: sym_137200_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_137200_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2794 [D] s_b_12_0 = sym_137200_1__R_s_b_3_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_137200_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1: sym_137183_0_return_symbol = s_b_12_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_137183_0_return_symbol, s_b_12_0);
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
    /* execute.a64:2768 [D] s_b_13_1: sym_137200_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_137200_1__R_s_b_3_0, s_b_13_0);
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
    /* execute.a64:2770 [D] s_b_14_1: sym_137200_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_137200_1__R_s_b_3_0, s_b_14_0);
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
    /* execute.simd:3932 [F] s_b_16_0 = sym_137292_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_0 = CV_sym_137292_3_parameter_rt;
    /* execute.simd:3932 [D] s_b_16_1 = ReadRegBank 15:s_b_16_0 (v8u8) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_0))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:3933 [D] s_b_16_2 = sym_137297_3_parameter_addr uint64_t */
    auto s_b_16_2 = emitter.load_local(DV_sym_137297_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3933 [F] s_b_16_3 = sym_137300_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_3 = CV_sym_137300_3_parameter_lane;
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
    /* execute.simd:3937 [F] s_b_17_0 = sym_137292_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_0 = CV_sym_137292_3_parameter_rt;
    /* execute.simd:3937 [D] s_b_17_1 = ReadRegBank 16:s_b_17_0 (v16u8) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_0))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:3938 [D] s_b_17_2 = sym_137297_3_parameter_addr uint64_t */
    auto s_b_17_2 = emitter.load_local(DV_sym_137297_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3938 [F] s_b_17_3 = sym_137300_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_3 = CV_sym_137300_3_parameter_lane;
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
    /* execute.simd:3942 [F] s_b_18_0 = sym_137292_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_137292_3_parameter_rt;
    /* execute.simd:3942 [D] s_b_18_1 = ReadRegBank 17:s_b_18_0 (v4u16) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3943 [D] s_b_18_2 = sym_137297_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_137297_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3943 [F] s_b_18_3 = sym_137300_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_137300_3_parameter_lane;
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
    /* execute.simd:3947 [F] s_b_19_0 = sym_137292_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_137292_3_parameter_rt;
    /* execute.simd:3947 [D] s_b_19_1 = ReadRegBank 18:s_b_19_0 (v8u16) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3948 [D] s_b_19_2 = sym_137297_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_137297_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3948 [F] s_b_19_3 = sym_137300_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_137300_3_parameter_lane;
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
    /* execute.simd:3952 [F] s_b_20_0 = sym_137292_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_137292_3_parameter_rt;
    /* execute.simd:3952 [D] s_b_20_1 = ReadRegBank 19:s_b_20_0 (v2u32) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3953 [D] s_b_20_2 = sym_137297_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_137297_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3953 [F] s_b_20_3 = sym_137300_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_137300_3_parameter_lane;
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
    /* execute.simd:3957 [F] s_b_21_0 = sym_137292_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_137292_3_parameter_rt;
    /* execute.simd:3957 [D] s_b_21_1 = ReadRegBank 20:s_b_21_0 (v4u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3958 [D] s_b_21_2 = sym_137297_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_137297_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3958 [F] s_b_21_3 = sym_137300_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_137300_3_parameter_lane;
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
    /* execute.simd:3962 [F] s_b_22_0 = sym_137292_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_137292_3_parameter_rt;
    /* execute.simd:3962 [D] s_b_22_1 = ReadRegBank 21:s_b_22_0 (v2u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3963 [D] s_b_22_2 = sym_137297_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_137297_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3963 [F] s_b_22_3 = sym_137300_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_137300_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_23_0 = sym_137377_1_tmp_s_b_5_5 uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_137377_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1 = sym_137374_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_23_1 = CV_sym_137374_1_tmp_s_b_5_2;
    /* execute.simd:2567 [F] s_b_23_2=sym_31142_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_23_3 = (u64)s_b_23_2 (const) */
    /* ???:4294967295 [D] s_b_23_4 = s_b_23_0+s_b_23_3 */
    auto s_b_23_4 = emitter.add(s_b_23_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2567 [D] s_b_23_5: sym_31148_0_address = s_b_23_4, dominates: s_b_5_5  */
    emitter.store_local(DV_sym_31148_0_address, s_b_23_4);
    /* execute.simd:2565 [F] s_b_23_6 = constant u8 1 (const) */
    /* execute.simd:2565 [F] s_b_23_7 = s_b_23_1+s_b_23_6 (const) */
    uint8_t s_b_23_7 = ((uint8_t)(s_b_23_1 + (uint8_t)1ULL));
    /* execute.simd:2565 [F] s_b_23_8: sym_31166_0_rt = s_b_23_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_31166_0_rt = s_b_23_7;
    /* execute.simd:2565 [F] s_b_23_9: Jump b_4 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stlxrh(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto block_b_14 = emitter.context().create_block();
  auto block_b_15 = emitter.context().create_block();
  auto block_b_16 = emitter.context().create_block();
  auto DV_sym_141234_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_141056_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141073_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141164_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_31565_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:732 [F] s_b_0_0=sym_31559_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2764 [F] s_b_4_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(s_b_4_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_4_4: If s_b_4_3: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2796 [F] s_b_5_0=sym_31559_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_141056_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_141056_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_141056_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_141056_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:732 [D] s_b_6_1: sym_31565_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_31565_0_address, s_b_6_0);
    /* execute.a64:734 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:734 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:734 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
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
    /* execute.a64:2765 [D] s_b_7_0 = ReadReg 21 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_7_1: sym_141073_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141073_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2765 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:3075 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_8_2 = (u8)s_b_8_1 (const) */
    /* execute.a64:2767 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:2767 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_8_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_8_6: If s_b_8_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2794 [D] s_b_9_0 = sym_141073_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_141073_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_141056_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_141056_0_return_symbol, s_b_9_0);
    /* ???:4294967295 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2768 [D] s_b_10_0 = ReadReg 21 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_10_1: sym_141073_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141073_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2768 [F] s_b_10_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2770 [D] s_b_11_0 = ReadReg 22 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_11_1: sym_141073_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141073_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  // BLOCK b_12 not fully fixed
  // BLOCK b_13 not fully fixed
  // BLOCK b_14 not fully fixed
  // BLOCK b_15 not fully fixed
  // BLOCK b_16 not fully fixed
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
        /* execute.a64:735 [D] s_b_1_0 = sym_31565_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_31565_0_address, emitter.context().types().u64());
        /* execute.a64:735 [F] s_b_1_1=sym_31559_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_1_2: sym_141164_1_tmp_s_b_3_0 = s_b_1_0, dominates: s_b_14_2  */
        emitter.store_local(DV_sym_141164_1_tmp_s_b_3_0, s_b_1_0);
        /* execute.a64:2709 [F] s_b_1_3 = (u32)s_b_1_1 (const) */
        /* execute.a64:2709 [F] s_b_1_4 = constant u32 1f (const) */
        /* execute.a64:2709 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
        uint8_t s_b_1_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2709 [F] s_b_1_6: If s_b_1_5: Jump b_12 else b_13 (const) */
        if (s_b_1_5) 
        {
          auto block = block_b_12;
          dynamic_block_queue.push(block_b_12);
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
        /* execute.a64:738 [F] s_b_3_0=sym_31559_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.a64:2737 [F] s_b_3_2 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
        uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_3_4: If s_b_3_3: Jump b_2 else b_15 (const) */
        if (s_b_3_3) 
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
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
        /* execute.a64:2709 [D] s_b_12_1: sym_141234_1_temporary_value = s_b_12_0, dominates: s_b_14_0  */
        emitter.store_local(DV_sym_141234_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2709 [F] s_b_12_2: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.a64:2709 [F] s_b_13_0=sym_31559_3_parameter_inst.rt (const) */
        /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
        auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_13_2: sym_141234_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
        emitter.store_local(DV_sym_141234_1_temporary_value, s_b_13_1);
        /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.a64:2709 [D] s_b_14_0 = sym_141234_1_temporary_value uint32_t */
        auto s_b_14_0 = emitter.load_local(DV_sym_141234_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
        auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_14_2 = sym_141164_1_tmp_s_b_3_0 uint64_t */
        auto s_b_14_2 = emitter.load_local(DV_sym_141164_1_tmp_s_b_3_0, emitter.context().types().u64());
        /* execute.a64:1850 [D] s_b_14_3 = (u16)s_b_14_1 */
        auto s_b_14_3 = emitter.truncate(s_b_14_1, emitter.context().types().u16());
        /* ???:4294967295 [D] s_b_14_4: Store 2 s_b_14_2 <= s_b_14_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_14_2, s_b_14_3, emitter.const_u8(2));
        }
        emitter.store_memory(s_b_14_2, s_b_14_3);
        /* execute.a64:736 [F] s_b_14_5=sym_31559_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_14_6 = (u32)s_b_14_5 (const) */
        /* execute.a64:2737 [F] s_b_14_7 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_14_8 = s_b_14_6==s_b_14_7 (const) */
        uint8_t s_b_14_8 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_14_9: If s_b_14_8: Jump b_2 else b_16 (const) */
        if (s_b_14_8) 
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
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.a64:2739 [F] s_b_15_0=sym_31559_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_15_1 = constant u64 1 (const) */
        /* execute.a64:2739 [F] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
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
        /* execute.a64:2739 [F] s_b_16_0=sym_31559_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_16_1 = constant u64 0 (const) */
        /* execute.a64:2739 [F] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_16_3: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_str_reg_simd(const arm64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_146116_1_temporary_value;
  auto DV_sym_146116_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_32269_0_shift;
  uint64_t CV_sym_32296_0_rm;
  auto DV_sym_32296_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32394_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_146165_0_replaced_parameter_shift;
  uint8_t CV_sym_145726_0_replaced_parameter_shift;
  auto DV_sym_145899_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_145999_0_replaced_parameter_shift;
  auto DV_sym_145916_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_145843_1_temporary_value;
  auto DV_sym_145843_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_146436_1_temporary_value;
  auto DV_sym_146436_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_146270_1_temporary_value;
  auto DV_sym_146270_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_146331_0_replaced_parameter_shift;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4067 [F] s_b_0_0=sym_32251_3_parameter_inst.S (const) */
    /* execute.simd:4067 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4067 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4067 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.S) == (uint32_t)0ULL));
    /* execute.simd:4067 [F] s_b_0_4 = constant u8 0 (const) */
    /* execute.simd:4067 [F] s_b_0_5=sym_32251_3_parameter_inst.X (const) */
    /* execute.simd:4067 [F] s_b_0_6 = (u32)s_b_0_5 (const) */
    /* execute.simd:4067 [F] s_b_0_7 = constant u32 1 (const) */
    /* execute.simd:4067 [F] s_b_0_8 = s_b_0_6==s_b_0_7 (const) */
    uint8_t s_b_0_8 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* execute.simd:4067 [F] s_b_0_9 = constant u8 4 (const) */
    /* execute.simd:4067 [F] s_b_0_10=sym_32251_3_parameter_inst.size (const) */
    /* execute.simd:4067 [F] s_b_0_11 = (u8)s_b_0_10 (const) */
    /* execute.simd:4067 [F] s_b_0_12: Select s_b_0_8 ? s_b_0_9 : s_b_0_11 (const) */
    uint8_t s_b_0_12 = ((uint8_t)(s_b_0_8 ? ((uint8_t)4ULL) : (((uint8_t)insn.size))));
    /* execute.simd:4067 [F] s_b_0_13: Select s_b_0_3 ? s_b_0_4 : s_b_0_12 (const) */
    uint8_t s_b_0_13 = ((uint8_t)(s_b_0_3 ? ((uint8_t)0ULL) : (s_b_0_12)));
    /* execute.simd:4067 [F] s_b_0_14: sym_32269_0_shift = s_b_0_13 (const), dominates: s_b_1_1 s_b_4_1 s_b_6_1 s_b_8_1  */
    CV_sym_32269_0_shift = s_b_0_13;
    /* execute.simd:4070 [F] s_b_0_15=sym_32251_3_parameter_inst.option0 (const) */
    /* execute.simd:4070 [F] s_b_0_16 = (u32)s_b_0_15 (const) */
    /* execute.simd:4070 [F] s_b_0_17 = constant u32 0 (const) */
    /* execute.simd:4070 [F] s_b_0_18 = s_b_0_16==s_b_0_17 (const) */
    uint8_t s_b_0_18 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.simd:4070 [F] s_b_0_19=sym_32251_3_parameter_inst.option21 (const) */
    /* execute.simd:4070 [F] s_b_0_20 = (u32)s_b_0_19 (const) */
    /* execute.simd:4070 [F] s_b_0_21 = constant u32 1 (const) */
    /* execute.simd:4070 [F] s_b_0_22 = s_b_0_20==s_b_0_21 (const) */
    uint8_t s_b_0_22 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_23 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_24 = s_b_0_18!=s_b_0_23 (const) */
    uint8_t s_b_0_24 = ((uint8_t)(s_b_0_18 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_25 = s_b_0_22!=s_b_0_23 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(s_b_0_22 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_26 = s_b_0_24&s_b_0_25 (const) */
    uint8_t s_b_0_26 = ((uint8_t)(s_b_0_24 & s_b_0_25));
    /* execute.simd:4070 [F] s_b_0_27: If s_b_0_26: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4071 [F] s_b_1_0=sym_32251_3_parameter_inst.rm (const) */
    /* execute.simd:4071 [F] s_b_1_1 = sym_32269_0_shift (const) uint8_t */
    uint8_t s_b_1_1 = CV_sym_32269_0_shift;
    /* ???:4294967295 [F] s_b_1_2: sym_145726_0_replaced_parameter_shift = s_b_1_1 (const), dominates: s_b_22_4  */
    CV_sym_145726_0_replaced_parameter_shift = s_b_1_1;
    /* execute.a64:2709 [F] s_b_1_3 = (u32)s_b_1_0 (const) */
    /* execute.a64:2709 [F] s_b_1_4 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
    uint8_t s_b_1_5 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_1_6: If s_b_1_5: Jump b_20 else b_21 (const) */
    if (s_b_1_5) 
    {
      goto fixed_block_b_20;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_9, b_22, b_33, b_36, b_39,  */
  fixed_block_b_2: 
  {
    /* execute.simd:4083 [F] s_b_2_0=sym_32251_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2793 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_2_4: If s_b_2_3: Jump b_23 else b_24 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4072 [F] s_b_3_0=sym_32251_3_parameter_inst.option0 (const) */
    /* execute.simd:4072 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4072 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4072 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.simd:4072 [F] s_b_3_4=sym_32251_3_parameter_inst.option21 (const) */
    /* execute.simd:4072 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4072 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.simd:4072 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4072 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4073 [F] s_b_4_0=sym_32251_3_parameter_inst.rm (const) */
    /* execute.simd:4073 [F] s_b_4_1 = sym_32269_0_shift (const) uint8_t */
    uint8_t s_b_4_1 = CV_sym_32269_0_shift;
    /* ???:4294967295 [F] s_b_4_2: sym_145999_0_replaced_parameter_shift = s_b_4_1 (const), dominates: s_b_33_5  */
    CV_sym_145999_0_replaced_parameter_shift = s_b_4_1;
    /* execute.a64:2709 [F] s_b_4_3 = (u32)s_b_4_0 (const) */
    /* execute.a64:2709 [F] s_b_4_4 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_4_5 = s_b_4_3==s_b_4_4 (const) */
    uint8_t s_b_4_5 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_4_6: If s_b_4_5: Jump b_31 else b_32 (const) */
    if (s_b_4_5) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4074 [F] s_b_5_0=sym_32251_3_parameter_inst.option0 (const) */
    /* execute.simd:4074 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4074 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4074 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.simd:4074 [F] s_b_5_4=sym_32251_3_parameter_inst.option21 (const) */
    /* execute.simd:4074 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4074 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.simd:4074 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.simd:4074 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4075 [F] s_b_6_0=sym_32251_3_parameter_inst.rm (const) */
    /* execute.simd:4075 [F] s_b_6_1 = sym_32269_0_shift (const) uint8_t */
    uint8_t s_b_6_1 = CV_sym_32269_0_shift;
    /* ???:4294967295 [F] s_b_6_2: sym_146165_0_replaced_parameter_shift = s_b_6_1 (const), dominates: s_b_36_1  */
    CV_sym_146165_0_replaced_parameter_shift = s_b_6_1;
    /* execute.a64:2714 [F] s_b_6_3 = (u32)s_b_6_0 (const) */
    /* execute.a64:2714 [F] s_b_6_4 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_6_6: If s_b_6_5: Jump b_34 else b_35 (const) */
    if (s_b_6_5) 
    {
      goto fixed_block_b_34;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4076 [F] s_b_7_0=sym_32251_3_parameter_inst.option0 (const) */
    /* execute.simd:4076 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4076 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.simd:4076 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.simd:4076 [F] s_b_7_4=sym_32251_3_parameter_inst.option21 (const) */
    /* execute.simd:4076 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4076 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.simd:4076 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:4076 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4077 [F] s_b_8_0=sym_32251_3_parameter_inst.rm (const) */
    /* execute.simd:4077 [F] s_b_8_1 = sym_32269_0_shift (const) uint8_t */
    uint8_t s_b_8_1 = CV_sym_32269_0_shift;
    /* ???:4294967295 [F] s_b_8_2: sym_146331_0_replaced_parameter_shift = s_b_8_1 (const), dominates: s_b_39_1  */
    CV_sym_146331_0_replaced_parameter_shift = s_b_8_1;
    /* execute.a64:2714 [F] s_b_8_3 = (u32)s_b_8_0 (const) */
    /* execute.a64:2714 [F] s_b_8_4 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_8_6: If s_b_8_5: Jump b_37 else b_38 (const) */
    if (s_b_8_5) 
    {
      goto fixed_block_b_37;
    }
    else 
    {
      goto fixed_block_b_38;
    }
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4079 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.simd:4079 [F] s_b_9_1: sym_32296_0_rm = s_b_9_0 (const), dominates: s_b_25_1  */
    CV_sym_32296_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_32296_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4080 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4079 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_25,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4086 [F] s_b_10_0=sym_32251_3_parameter_inst.X (const) */
    /* execute.simd:4086 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.simd:4086 [F] s_b_10_2 = constant u32 1 (const) */
    /* execute.simd:4086 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.X) == (uint32_t)1ULL));
    /* execute.simd:4086 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
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
  /* b_25,  */
  fixed_block_b_12: 
  {
    /* execute.simd:4093 [F] s_b_12_0=sym_32251_3_parameter_inst.size (const) */
    /* execute.simd:4093 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.simd:4093 [F] s_b_12_2 = constant u32 1 (const) */
    /* execute.simd:4093 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:4093 [F] s_b_12_4: If s_b_12_3: Jump b_15 else b_16 (const) */
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
    /* execute.simd:4088 [F] s_b_13_0=sym_32251_3_parameter_inst.rt (const) */
    /* execute.simd:4088 [D] s_b_13_1 = sym_32394_0_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_32394_0_address, emitter.context().types().u64());
    /* execute.simd:6360 [D] s_b_13_2 = ReadRegBank 2:s_b_13_0 (u64) */
    auto s_b_13_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_2,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_13_3 = ReadRegBank 3:s_b_13_0 (u64) */
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
    /* execute.simd:3753 [F] s_b_13_5 = constant u64 8 (const) */
    /* execute.simd:3753 [D] s_b_13_6 = s_b_13_1+s_b_13_5 */
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
    /* execute.simd:4091 [F] s_b_14_0=sym_32251_3_parameter_inst.rt (const) */
    /* execute.simd:4091 [D] s_b_14_1 = sym_32394_0_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_32394_0_address, emitter.context().types().u64());
    /* execute.simd:6340 [D] s_b_14_2 = ReadRegBank 4:s_b_14_0 (u8) */
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
    /* execute.simd:4095 [F] s_b_15_0=sym_32251_3_parameter_inst.rt (const) */
    /* execute.simd:4095 [D] s_b_15_1 = sym_32394_0_address uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_32394_0_address, emitter.context().types().u64());
    /* execute.simd:6345 [D] s_b_15_2 = ReadRegBank 5:s_b_15_0 (u16) */
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
    /* execute.simd:4096 [F] s_b_16_0=sym_32251_3_parameter_inst.size (const) */
    /* execute.simd:4096 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.simd:4096 [F] s_b_16_2 = constant u32 2 (const) */
    /* execute.simd:4096 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4096 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_18 (const) */
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
    /* execute.simd:4098 [F] s_b_17_0=sym_32251_3_parameter_inst.rt (const) */
    /* execute.simd:4098 [D] s_b_17_1 = sym_32394_0_address uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_32394_0_address, emitter.context().types().u64());
    /* execute.simd:6350 [D] s_b_17_2 = ReadRegBank 6:s_b_17_0 (u32) */
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
    /* execute.simd:4099 [F] s_b_18_0=sym_32251_3_parameter_inst.size (const) */
    /* execute.simd:4099 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
    /* execute.simd:4099 [F] s_b_18_2 = constant u32 3 (const) */
    /* execute.simd:4099 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:4099 [F] s_b_18_4: If s_b_18_3: Jump b_19 else b_11 (const) */
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
    /* execute.simd:4101 [F] s_b_19_0=sym_32251_3_parameter_inst.rt (const) */
    /* execute.simd:4101 [D] s_b_19_1 = sym_32394_0_address uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_32394_0_address, emitter.context().types().u64());
    /* execute.simd:6355 [D] s_b_19_2 = ReadRegBank 7:s_b_19_0 (u64) */
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
  /* b_1,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2709 [F] s_b_20_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_20_1: sym_145843_1_temporary_value = s_b_20_0 (const), dominates: s_b_22_0  */
    CV_sym_145843_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_145843_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_1,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2709 [F] s_b_21_0=sym_32251_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_21_1 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_21_2: sym_145843_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_145843_1_temporary_value, s_b_21_1);
    /* execute.a64:2709 [F] s_b_21_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2709 [D] s_b_22_0 = sym_145843_1_temporary_value uint32_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_145843_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_22_1 = (u64)s_b_22_0 */
    auto s_b_22_1 = emitter.zx(s_b_22_0, emitter.context().types().u64());
    /* execute.a64:2679 [D] s_b_22_2 = (u32)s_b_22_1 */
    auto s_b_22_2 = emitter.truncate(s_b_22_1, emitter.context().types().u32());
    /* execute.a64:2679 [D] s_b_22_3 = (u64)s_b_22_2 */
    auto s_b_22_3 = emitter.zx(s_b_22_2, emitter.context().types().u64());
    /* execute.a64:2679 [F] s_b_22_4 = sym_145726_0_replaced_parameter_shift (const) uint8_t */
    uint8_t s_b_22_4 = CV_sym_145726_0_replaced_parameter_shift;
    /* execute.a64:2679 [F] s_b_22_5 = (u64)s_b_22_4 (const) */
    /* execute.a64:2679 [D] s_b_22_6 = s_b_22_3<<s_b_22_5 */
    auto s_b_22_6 = emitter.shl(s_b_22_3, emitter.const_u64(((uint64_t)s_b_22_4)));
    /* execute.simd:4071 [D] s_b_22_7: sym_32296_0_rm = s_b_22_6, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_32296_0_rm, s_b_22_6);
    /* execute.simd:4071 [F] s_b_22_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2764 [F] s_b_23_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_23_1 = __builtin_get_feature */
    uint32_t s_b_23_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_23_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(s_b_23_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_23_4: If s_b_23_3: Jump b_26 else b_27 (const) */
    if (s_b_23_3) 
    {
      goto fixed_block_b_26;
    }
    else 
    {
      goto fixed_block_b_27;
    }
  }
  /* b_2,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2796 [F] s_b_24_0=sym_32251_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_24_1 = ReadRegBank 0:s_b_24_0 (u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_24_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_24_2: sym_145899_0_return_symbol = s_b_24_1, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_145899_0_return_symbol, s_b_24_1);
    /* ???:4294967295 [F] s_b_24_3: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_24, b_28,  */
  fixed_block_b_25: 
  {
    /* ???:4294967295 [D] s_b_25_0 = sym_145899_0_return_symbol uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_145899_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:4083 [D] s_b_25_1 = sym_32296_0_rm uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_32296_0_rm, emitter.context().types().u64());
    /* execute.simd:4083 [D] s_b_25_2 = s_b_25_0+s_b_25_1 */
    auto s_b_25_2 = emitter.add(s_b_25_0, s_b_25_1);
    /* execute.simd:4083 [D] s_b_25_3: sym_32394_0_address = s_b_25_2, dominates: s_b_13_1 s_b_14_1 s_b_15_1 s_b_17_1 s_b_19_1  */
    emitter.store_local(DV_sym_32394_0_address, s_b_25_2);
    /* execute.simd:4085 [F] s_b_25_4=sym_32251_3_parameter_inst.size (const) */
    /* execute.simd:4085 [F] s_b_25_5 = (u32)s_b_25_4 (const) */
    /* execute.simd:4085 [F] s_b_25_6 = constant u32 0 (const) */
    /* execute.simd:4085 [F] s_b_25_7 = s_b_25_5==s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4085 [F] s_b_25_8: If s_b_25_7: Jump b_10 else b_12 (const) */
    if (s_b_25_7) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_23,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2765 [D] s_b_26_0 = ReadReg 21 (u64) */
    auto s_b_26_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_26_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_26_1: sym_145916_1__R_s_b_3_0 = s_b_26_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_145916_1__R_s_b_3_0, s_b_26_0);
    /* execute.a64:2765 [F] s_b_26_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_23,  */
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
    /* execute.a64:2767 [F] s_b_27_6: If s_b_27_5: Jump b_29 else b_30 (const) */
    if (s_b_27_5) 
    {
      goto fixed_block_b_29;
    }
    else 
    {
      goto fixed_block_b_30;
    }
  }
  /* b_26, b_29, b_30,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2794 [D] s_b_28_0 = sym_145916_1__R_s_b_3_0 uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_145916_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_28_1: sym_145899_0_return_symbol = s_b_28_0, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_145899_0_return_symbol, s_b_28_0);
    /* ???:4294967295 [F] s_b_28_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_27,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2768 [D] s_b_29_0 = ReadReg 21 (u64) */
    auto s_b_29_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_29_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_29_1: sym_145916_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_145916_1__R_s_b_3_0, s_b_29_0);
    /* execute.a64:2768 [F] s_b_29_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2770 [D] s_b_30_0 = ReadReg 22 (u64) */
    auto s_b_30_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_30_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_30_1: sym_145916_1__R_s_b_3_0 = s_b_30_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_145916_1__R_s_b_3_0, s_b_30_0);
    /* execute.a64:2770 [F] s_b_30_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_4,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2709 [F] s_b_31_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_31_1: sym_146116_1_temporary_value = s_b_31_0 (const), dominates: s_b_33_0  */
    CV_sym_146116_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_146116_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_31_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_4,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2709 [F] s_b_32_0=sym_32251_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_32_1 = ReadRegBank 1:s_b_32_0 (u32) */
    auto s_b_32_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_32_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_32_2: sym_146116_1_temporary_value = s_b_32_1, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_146116_1_temporary_value, s_b_32_1);
    /* execute.a64:2709 [F] s_b_32_3: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_31, b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2709 [D] s_b_33_0 = sym_146116_1_temporary_value uint32_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_146116_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_33_1 = (u64)s_b_33_0 */
    auto s_b_33_1 = emitter.zx(s_b_33_0, emitter.context().types().u64());
    /* execute.a64:2695 [D] s_b_33_2 = (s32)s_b_33_1 */
    auto s_b_33_2 = emitter.truncate(s_b_33_1, emitter.context().types().s32());
    /* execute.a64:2695 [D] s_b_33_3 = (s64)s_b_33_2 */
    auto s_b_33_3 = emitter.sx(s_b_33_2, emitter.context().types().s64());
    /* execute.a64:2695 [D] s_b_33_4 = (u64)s_b_33_3 */
    auto s_b_33_4 = emitter.reinterpret(s_b_33_3, emitter.context().types().u64());
    /* execute.a64:2695 [F] s_b_33_5 = sym_145999_0_replaced_parameter_shift (const) uint8_t */
    uint8_t s_b_33_5 = CV_sym_145999_0_replaced_parameter_shift;
    /* execute.a64:2695 [F] s_b_33_6 = (u64)s_b_33_5 (const) */
    /* execute.a64:2695 [D] s_b_33_7 = s_b_33_4<<s_b_33_6 */
    auto s_b_33_7 = emitter.shl(s_b_33_4, emitter.const_u64(((uint64_t)s_b_33_5)));
    /* execute.simd:4073 [D] s_b_33_8: sym_32296_0_rm = s_b_33_7, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_32296_0_rm, s_b_33_7);
    /* execute.simd:4073 [F] s_b_33_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2714 [F] s_b_34_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_34_1: sym_146270_1_temporary_value = s_b_34_0 (const), dominates: s_b_36_0  */
    CV_sym_146270_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_146270_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_34_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_6,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2714 [F] s_b_35_0=sym_32251_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_35_1 = ReadRegBank 0:s_b_35_0 (u64) */
    auto s_b_35_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_35_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_35_2: sym_146270_1_temporary_value = s_b_35_1, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_146270_1_temporary_value, s_b_35_1);
    /* execute.a64:2714 [F] s_b_35_3: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2714 [D] s_b_36_0 = sym_146270_1_temporary_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_146270_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2683 [F] s_b_36_1 = sym_146165_0_replaced_parameter_shift (const) uint8_t */
    uint8_t s_b_36_1 = CV_sym_146165_0_replaced_parameter_shift;
    /* execute.a64:2683 [F] s_b_36_2 = (u64)s_b_36_1 (const) */
    /* execute.a64:2683 [D] s_b_36_3 = s_b_36_0<<s_b_36_2 */
    auto s_b_36_3 = emitter.shl(s_b_36_0, emitter.const_u64(((uint64_t)s_b_36_1)));
    /* execute.simd:4075 [D] s_b_36_4: sym_32296_0_rm = s_b_36_3, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_32296_0_rm, s_b_36_3);
    /* execute.simd:4075 [F] s_b_36_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2714 [F] s_b_37_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_37_1: sym_146436_1_temporary_value = s_b_37_0 (const), dominates: s_b_39_0  */
    CV_sym_146436_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_146436_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_37_2: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_8,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2714 [F] s_b_38_0=sym_32251_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_38_1 = ReadRegBank 0:s_b_38_0 (u64) */
    auto s_b_38_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_38_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_38_2: sym_146436_1_temporary_value = s_b_38_1, dominates: s_b_39_0  */
    emitter.store_local(DV_sym_146436_1_temporary_value, s_b_38_1);
    /* execute.a64:2714 [F] s_b_38_3: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_37, b_38,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2714 [D] s_b_39_0 = sym_146436_1_temporary_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_146436_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2699 [F] s_b_39_1 = sym_146331_0_replaced_parameter_shift (const) uint8_t */
    uint8_t s_b_39_1 = CV_sym_146331_0_replaced_parameter_shift;
    /* execute.a64:2699 [F] s_b_39_2 = (u64)s_b_39_1 (const) */
    /* execute.a64:2699 [D] s_b_39_3 = s_b_39_0<<s_b_39_2 */
    auto s_b_39_3 = emitter.shl(s_b_39_0, emitter.const_u64(((uint64_t)s_b_39_1)));
    /* execute.simd:4077 [D] s_b_39_4: sym_32296_0_rm = s_b_39_3, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_32296_0_rm, s_b_39_3);
    /* execute.simd:4077 [F] s_b_39_5: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sttr(const arm64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stxrb(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto block_b_14 = emitter.context().create_block();
  auto block_b_15 = emitter.context().create_block();
  auto block_b_16 = emitter.context().create_block();
  auto DV_sym_151965_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152060_1_tmp_s_b_2_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_33209_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_151982_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152128_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:672 [F] s_b_0_0=sym_33203_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2764 [F] s_b_4_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(s_b_4_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_4_4: If s_b_4_3: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2796 [F] s_b_5_0=sym_33203_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_151965_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_151965_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_151965_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_151965_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:672 [D] s_b_6_1: sym_33209_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_33209_0_address, s_b_6_0);
    /* execute.a64:674 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:674 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:674 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
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
    /* execute.a64:2765 [D] s_b_7_0 = ReadReg 21 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_7_1: sym_151982_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_151982_1__R_s_b_3_0, s_b_7_0);
    /* execute.a64:2765 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_4,  */
  fixed_block_b_8: 
  {
    /* execute.a64:3075 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_8_1 = __builtin_get_feature */
    uint32_t s_b_8_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_8_2 = (u8)s_b_8_1 (const) */
    /* execute.a64:2767 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:2767 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_8_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_8_6: If s_b_8_5: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2794 [D] s_b_9_0 = sym_151982_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_151982_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_151965_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_151965_0_return_symbol, s_b_9_0);
    /* ???:4294967295 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2768 [D] s_b_10_0 = ReadReg 21 (u64) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_10_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_10_1: sym_151982_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_151982_1__R_s_b_3_0, s_b_10_0);
    /* execute.a64:2768 [F] s_b_10_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2770 [D] s_b_11_0 = ReadReg 22 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_11_1: sym_151982_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_151982_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  // BLOCK b_12 not fully fixed
  // BLOCK b_13 not fully fixed
  // BLOCK b_14 not fully fixed
  // BLOCK b_15 not fully fixed
  // BLOCK b_16 not fully fixed
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
        /* execute.a64:675 [D] s_b_1_0 = sym_33209_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_33209_0_address, emitter.context().types().u64());
        /* execute.a64:675 [F] s_b_1_1=sym_33203_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_1_2: sym_152060_1_tmp_s_b_2_0 = s_b_1_0, dominates: s_b_14_2  */
        emitter.store_local(DV_sym_152060_1_tmp_s_b_2_0, s_b_1_0);
        /* execute.a64:2709 [F] s_b_1_3 = (u32)s_b_1_1 (const) */
        /* execute.a64:2709 [F] s_b_1_4 = constant u32 1f (const) */
        /* execute.a64:2709 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
        uint8_t s_b_1_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2709 [F] s_b_1_6: If s_b_1_5: Jump b_12 else b_13 (const) */
        if (s_b_1_5) 
        {
          auto block = block_b_12;
          dynamic_block_queue.push(block_b_12);
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
        /* execute.a64:678 [F] s_b_3_0=sym_33203_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.a64:2737 [F] s_b_3_2 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
        uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_3_4: If s_b_3_3: Jump b_2 else b_15 (const) */
        if (s_b_3_3) 
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
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
        /* execute.a64:2709 [D] s_b_12_1: sym_152128_1_temporary_value = s_b_12_0, dominates: s_b_14_0  */
        emitter.store_local(DV_sym_152128_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
        /* execute.a64:2709 [F] s_b_12_2: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.a64:2709 [F] s_b_13_0=sym_33203_3_parameter_inst.rt (const) */
        /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
        auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_13_2: sym_152128_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
        emitter.store_local(DV_sym_152128_1_temporary_value, s_b_13_1);
        /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.a64:2709 [D] s_b_14_0 = sym_152128_1_temporary_value uint32_t */
        auto s_b_14_0 = emitter.load_local(DV_sym_152128_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
        auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_14_2 = sym_152060_1_tmp_s_b_2_0 uint64_t */
        auto s_b_14_2 = emitter.load_local(DV_sym_152060_1_tmp_s_b_2_0, emitter.context().types().u64());
        /* execute.a64:1845 [D] s_b_14_3 = (u8)s_b_14_1 */
        auto s_b_14_3 = emitter.truncate(s_b_14_1, emitter.context().types().u8());
        /* ???:4294967295 [D] s_b_14_4: Store 1 s_b_14_2 <= s_b_14_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_14_2, s_b_14_3, emitter.const_u8(1));
        }
        emitter.store_memory(s_b_14_2, s_b_14_3);
        /* execute.a64:676 [F] s_b_14_5=sym_33203_3_parameter_inst.rs (const) */
        /* execute.a64:2737 [F] s_b_14_6 = (u32)s_b_14_5 (const) */
        /* execute.a64:2737 [F] s_b_14_7 = constant u32 1f (const) */
        /* execute.a64:2737 [F] s_b_14_8 = s_b_14_6==s_b_14_7 (const) */
        uint8_t s_b_14_8 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2737 [F] s_b_14_9: If s_b_14_8: Jump b_2 else b_16 (const) */
        if (s_b_14_8) 
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
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.a64:2739 [F] s_b_15_0=sym_33203_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_15_1 = constant u64 1 (const) */
        /* execute.a64:2739 [F] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL));
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
        /* execute.a64:2739 [F] s_b_16_0=sym_33203_3_parameter_inst.rs (const) */
        /* execute.a64:2739 [F] s_b_16_1 = constant u64 0 (const) */
        /* execute.a64:2739 [F] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL));
        /* execute.a64:0 [F] s_b_16_3: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_tbx(const arm64_decode_a64_SIMD_TABLE_LOOKUP&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_35301_0_rm = emitter.alloc_local(emitter.context().types().u8(), true);
  auto DV_sym_35686_0_rm = emitter.alloc_local(emitter.context().types().u8(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3833 [F] s_b_0_0=sym_35278_3_parameter_inst.Q (const) */
    /* execute.simd:3833 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:3833 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:3833 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:3833 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3835 [F] s_b_1_0=sym_35278_3_parameter_inst.rm (const) */
    /* execute.simd:3835 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:3835 [F] s_b_1_2 = constant u32 10 (const) */
    /* execute.simd:3835 [F] s_b_1_3 = s_b_1_1*s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
    /* execute.simd:3835 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.simd:3835 [F] s_b_1_5 = s_b_1_3+s_b_1_4 (const) */
    uint32_t s_b_1_5 = ((uint32_t)(s_b_1_3 + (uint32_t)0ULL));
    /* execute.simd:3835 [D] s_b_1_6 = ReadRegBank 23:s_b_1_5 (u8) */
    auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_1_5))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_1_5))),s_b_1_6,emitter.const_u8(1));
    }
    /* execute.simd:3835 [D] s_b_1_7: sym_35301_0_rm = s_b_1_6, dominates: s_b_4_10  */
    emitter.store_local(DV_sym_35301_0_rm, s_b_1_6);
    /* execute.simd:3837 [F] s_b_1_8=sym_35278_3_parameter_inst.len (const) */
    /* execute.simd:3837 [F] s_b_1_9 = (u32)s_b_1_8 (const) */
    /* execute.simd:3837 [F] s_b_1_10 = constant u32 1 (const) */
    /* execute.simd:3837 [F] s_b_1_11 = s_b_1_9+s_b_1_10 (const) */
    uint32_t s_b_1_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
    /* execute.simd:3837 [F] s_b_1_12 = constant u32 10 (const) */
    /* execute.simd:3837 [F] s_b_1_13 = s_b_1_12*s_b_1_11 (const) */
    uint32_t s_b_1_13 = ((uint32_t)((uint32_t)16ULL * s_b_1_11));
    /* execute.simd:3837 [D] s_b_1_14 = (u32)s_b_1_6 */
    auto s_b_1_14 = emitter.zx(s_b_1_6, emitter.context().types().u32());
    /* execute.simd:3837 [D] s_b_1_15 = s_b_1_14<s_b_1_13 */
    auto s_b_1_15 = emitter.cmp_lt(s_b_1_14, emitter.const_u32(s_b_1_13));
    /* execute.simd:3837 [D] s_b_1_16: If s_b_1_15: Jump b_4 else b_5 */
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
    /* execute.simd:3845 [F] s_b_3_0=sym_35278_3_parameter_inst.rm (const) */
    /* execute.simd:3845 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:3845 [F] s_b_3_2 = constant u32 10 (const) */
    /* execute.simd:3845 [F] s_b_3_3 = s_b_3_1*s_b_3_2 (const) */
    uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
    /* execute.simd:3845 [F] s_b_3_4 = constant u32 0 (const) */
    /* execute.simd:3845 [F] s_b_3_5 = s_b_3_3+s_b_3_4 (const) */
    uint32_t s_b_3_5 = ((uint32_t)(s_b_3_3 + (uint32_t)0ULL));
    /* execute.simd:3845 [D] s_b_3_6 = ReadRegBank 23:s_b_3_5 (u8) */
    auto s_b_3_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_3_5))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_3_5))),s_b_3_6,emitter.const_u8(1));
    }
    /* execute.simd:3845 [D] s_b_3_7: sym_35686_0_rm = s_b_3_6, dominates: s_b_20_10  */
    emitter.store_local(DV_sym_35686_0_rm, s_b_3_6);
    /* execute.simd:3847 [F] s_b_3_8=sym_35278_3_parameter_inst.len (const) */
    /* execute.simd:3847 [F] s_b_3_9 = (u32)s_b_3_8 (const) */
    /* execute.simd:3847 [F] s_b_3_10 = constant u32 1 (const) */
    /* execute.simd:3847 [F] s_b_3_11 = s_b_3_9+s_b_3_10 (const) */
    uint32_t s_b_3_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
    /* execute.simd:3847 [F] s_b_3_12 = constant u32 10 (const) */
    /* execute.simd:3847 [F] s_b_3_13 = s_b_3_12*s_b_3_11 (const) */
    uint32_t s_b_3_13 = ((uint32_t)((uint32_t)16ULL * s_b_3_11));
    /* execute.simd:3847 [D] s_b_3_14 = (u32)s_b_3_6 */
    auto s_b_3_14 = emitter.zx(s_b_3_6, emitter.context().types().u32());
    /* execute.simd:3847 [D] s_b_3_15 = s_b_3_14<s_b_3_13 */
    auto s_b_3_15 = emitter.cmp_lt(s_b_3_14, emitter.const_u32(s_b_3_13));
    /* execute.simd:3847 [D] s_b_3_16: If s_b_3_15: Jump b_20 else b_21 */
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
        /* execute.simd:3838 [F] s_b_4_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3838 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
        /* execute.simd:3838 [F] s_b_4_2 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_4_3 = s_b_4_1*s_b_4_2 (const) */
        uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3838 [F] s_b_4_4 = constant u32 0 (const) */
        /* execute.simd:3838 [F] s_b_4_5 = s_b_4_3+s_b_4_4 (const) */
        uint32_t s_b_4_5 = ((uint32_t)(s_b_4_3 + (uint32_t)0ULL));
        /* execute.simd:3838 [F] s_b_4_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3838 [F] s_b_4_7 = (u32)s_b_4_6 (const) */
        /* execute.simd:3838 [F] s_b_4_8 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_4_9 = s_b_4_7*s_b_4_8 (const) */
        uint32_t s_b_4_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3838 [D] s_b_4_10 = sym_35301_0_rm uint8_t */
        auto s_b_4_10 = emitter.load_local(DV_sym_35301_0_rm, emitter.context().types().u8());
        /* execute.simd:3838 [D] s_b_4_11 = (u32)s_b_4_10 */
        auto s_b_4_11 = emitter.zx(s_b_4_10, emitter.context().types().u32());
        /* execute.simd:3838 [D] s_b_4_12 = s_b_4_9+s_b_4_11 */
        auto s_b_4_12 = emitter.add(emitter.const_u32(s_b_4_9), s_b_4_11);
        /* execute.simd:3838 [D] s_b_4_13 = ReadRegBank 23:s_b_4_12 (u8) */
        captive::arch::dbt::el::Value *s_b_4_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_4_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_4_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3838 [D] s_b_4_14: WriteRegBank 23:s_b_4_5 = s_b_4_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_4_5))),s_b_4_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_4_5))),s_b_4_13);
        /* execute.simd:3838 [F] s_b_4_15: Jump b_5 (const) */
        {
          auto block = block_b_5;
          dynamic_block_queue.push(block_b_5);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:3835 [F] s_b_5_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3835 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
        /* execute.simd:3835 [F] s_b_5_2 = constant u32 10 (const) */
        /* execute.simd:3835 [F] s_b_5_3 = s_b_5_1*s_b_5_2 (const) */
        uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3835 [F] s_b_5_4 = constant u32 1 (const) */
        /* execute.simd:3835 [F] s_b_5_5 = s_b_5_3+s_b_5_4 (const) */
        uint32_t s_b_5_5 = ((uint32_t)(s_b_5_3 + (uint32_t)1ULL));
        /* execute.simd:3835 [D] s_b_5_6 = ReadRegBank 23:s_b_5_5 (u8) */
        auto s_b_5_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_5_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_5_5))),s_b_5_6,emitter.const_u8(1));
        }
        /* execute.simd:3835 [D] s_b_5_7: sym_35301_0_rm = s_b_5_6, dominates: s_b_6_10  */
        emitter.store_local(DV_sym_35301_0_rm, s_b_5_6);
        /* execute.simd:3837 [F] s_b_5_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3837 [F] s_b_5_9 = (u32)s_b_5_8 (const) */
        /* execute.simd:3837 [F] s_b_5_10 = constant u32 1 (const) */
        /* execute.simd:3837 [F] s_b_5_11 = s_b_5_9+s_b_5_10 (const) */
        uint32_t s_b_5_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3837 [F] s_b_5_12 = constant u32 10 (const) */
        /* execute.simd:3837 [F] s_b_5_13 = s_b_5_12*s_b_5_11 (const) */
        uint32_t s_b_5_13 = ((uint32_t)((uint32_t)16ULL * s_b_5_11));
        /* execute.simd:3837 [D] s_b_5_14 = (u32)s_b_5_6 */
        auto s_b_5_14 = emitter.zx(s_b_5_6, emitter.context().types().u32());
        /* execute.simd:3837 [D] s_b_5_15 = s_b_5_14<s_b_5_13 */
        auto s_b_5_15 = emitter.cmp_lt(s_b_5_14, emitter.const_u32(s_b_5_13));
        /* execute.simd:3837 [D] s_b_5_16: If s_b_5_15: Jump b_6 else b_7 */
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
        /* execute.simd:3838 [F] s_b_6_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3838 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
        /* execute.simd:3838 [F] s_b_6_2 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_6_3 = s_b_6_1*s_b_6_2 (const) */
        uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3838 [F] s_b_6_4 = constant u32 1 (const) */
        /* execute.simd:3838 [F] s_b_6_5 = s_b_6_3+s_b_6_4 (const) */
        uint32_t s_b_6_5 = ((uint32_t)(s_b_6_3 + (uint32_t)1ULL));
        /* execute.simd:3838 [F] s_b_6_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3838 [F] s_b_6_7 = (u32)s_b_6_6 (const) */
        /* execute.simd:3838 [F] s_b_6_8 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_6_9 = s_b_6_7*s_b_6_8 (const) */
        uint32_t s_b_6_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3838 [D] s_b_6_10 = sym_35301_0_rm uint8_t */
        auto s_b_6_10 = emitter.load_local(DV_sym_35301_0_rm, emitter.context().types().u8());
        /* execute.simd:3838 [D] s_b_6_11 = (u32)s_b_6_10 */
        auto s_b_6_11 = emitter.zx(s_b_6_10, emitter.context().types().u32());
        /* execute.simd:3838 [D] s_b_6_12 = s_b_6_9+s_b_6_11 */
        auto s_b_6_12 = emitter.add(emitter.const_u32(s_b_6_9), s_b_6_11);
        /* execute.simd:3838 [D] s_b_6_13 = ReadRegBank 23:s_b_6_12 (u8) */
        captive::arch::dbt::el::Value *s_b_6_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_6_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_6_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3838 [D] s_b_6_14: WriteRegBank 23:s_b_6_5 = s_b_6_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_6_5))),s_b_6_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_6_5))),s_b_6_13);
        /* execute.simd:3838 [F] s_b_6_15: Jump b_7 (const) */
        {
          auto block = block_b_7;
          dynamic_block_queue.push(block_b_7);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.simd:3835 [F] s_b_7_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3835 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
        /* execute.simd:3835 [F] s_b_7_2 = constant u32 10 (const) */
        /* execute.simd:3835 [F] s_b_7_3 = s_b_7_1*s_b_7_2 (const) */
        uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3835 [F] s_b_7_4 = constant u32 2 (const) */
        /* execute.simd:3835 [F] s_b_7_5 = s_b_7_3+s_b_7_4 (const) */
        uint32_t s_b_7_5 = ((uint32_t)(s_b_7_3 + (uint32_t)2ULL));
        /* execute.simd:3835 [D] s_b_7_6 = ReadRegBank 23:s_b_7_5 (u8) */
        auto s_b_7_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_7_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_7_5))),s_b_7_6,emitter.const_u8(1));
        }
        /* execute.simd:3835 [D] s_b_7_7: sym_35301_0_rm = s_b_7_6, dominates: s_b_8_10  */
        emitter.store_local(DV_sym_35301_0_rm, s_b_7_6);
        /* execute.simd:3837 [F] s_b_7_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3837 [F] s_b_7_9 = (u32)s_b_7_8 (const) */
        /* execute.simd:3837 [F] s_b_7_10 = constant u32 1 (const) */
        /* execute.simd:3837 [F] s_b_7_11 = s_b_7_9+s_b_7_10 (const) */
        uint32_t s_b_7_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3837 [F] s_b_7_12 = constant u32 10 (const) */
        /* execute.simd:3837 [F] s_b_7_13 = s_b_7_12*s_b_7_11 (const) */
        uint32_t s_b_7_13 = ((uint32_t)((uint32_t)16ULL * s_b_7_11));
        /* execute.simd:3837 [D] s_b_7_14 = (u32)s_b_7_6 */
        auto s_b_7_14 = emitter.zx(s_b_7_6, emitter.context().types().u32());
        /* execute.simd:3837 [D] s_b_7_15 = s_b_7_14<s_b_7_13 */
        auto s_b_7_15 = emitter.cmp_lt(s_b_7_14, emitter.const_u32(s_b_7_13));
        /* execute.simd:3837 [D] s_b_7_16: If s_b_7_15: Jump b_8 else b_9 */
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
        /* execute.simd:3838 [F] s_b_8_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3838 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
        /* execute.simd:3838 [F] s_b_8_2 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_8_3 = s_b_8_1*s_b_8_2 (const) */
        uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3838 [F] s_b_8_4 = constant u32 2 (const) */
        /* execute.simd:3838 [F] s_b_8_5 = s_b_8_3+s_b_8_4 (const) */
        uint32_t s_b_8_5 = ((uint32_t)(s_b_8_3 + (uint32_t)2ULL));
        /* execute.simd:3838 [F] s_b_8_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3838 [F] s_b_8_7 = (u32)s_b_8_6 (const) */
        /* execute.simd:3838 [F] s_b_8_8 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_8_9 = s_b_8_7*s_b_8_8 (const) */
        uint32_t s_b_8_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3838 [D] s_b_8_10 = sym_35301_0_rm uint8_t */
        auto s_b_8_10 = emitter.load_local(DV_sym_35301_0_rm, emitter.context().types().u8());
        /* execute.simd:3838 [D] s_b_8_11 = (u32)s_b_8_10 */
        auto s_b_8_11 = emitter.zx(s_b_8_10, emitter.context().types().u32());
        /* execute.simd:3838 [D] s_b_8_12 = s_b_8_9+s_b_8_11 */
        auto s_b_8_12 = emitter.add(emitter.const_u32(s_b_8_9), s_b_8_11);
        /* execute.simd:3838 [D] s_b_8_13 = ReadRegBank 23:s_b_8_12 (u8) */
        captive::arch::dbt::el::Value *s_b_8_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_8_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_8_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3838 [D] s_b_8_14: WriteRegBank 23:s_b_8_5 = s_b_8_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_8_5))),s_b_8_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_8_5))),s_b_8_13);
        /* execute.simd:3838 [F] s_b_8_15: Jump b_9 (const) */
        {
          auto block = block_b_9;
          dynamic_block_queue.push(block_b_9);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.simd:3835 [F] s_b_9_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3835 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
        /* execute.simd:3835 [F] s_b_9_2 = constant u32 10 (const) */
        /* execute.simd:3835 [F] s_b_9_3 = s_b_9_1*s_b_9_2 (const) */
        uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3835 [F] s_b_9_4 = constant u32 3 (const) */
        /* execute.simd:3835 [F] s_b_9_5 = s_b_9_3+s_b_9_4 (const) */
        uint32_t s_b_9_5 = ((uint32_t)(s_b_9_3 + (uint32_t)3ULL));
        /* execute.simd:3835 [D] s_b_9_6 = ReadRegBank 23:s_b_9_5 (u8) */
        auto s_b_9_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_9_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_9_5))),s_b_9_6,emitter.const_u8(1));
        }
        /* execute.simd:3835 [D] s_b_9_7: sym_35301_0_rm = s_b_9_6, dominates: s_b_10_10  */
        emitter.store_local(DV_sym_35301_0_rm, s_b_9_6);
        /* execute.simd:3837 [F] s_b_9_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3837 [F] s_b_9_9 = (u32)s_b_9_8 (const) */
        /* execute.simd:3837 [F] s_b_9_10 = constant u32 1 (const) */
        /* execute.simd:3837 [F] s_b_9_11 = s_b_9_9+s_b_9_10 (const) */
        uint32_t s_b_9_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3837 [F] s_b_9_12 = constant u32 10 (const) */
        /* execute.simd:3837 [F] s_b_9_13 = s_b_9_12*s_b_9_11 (const) */
        uint32_t s_b_9_13 = ((uint32_t)((uint32_t)16ULL * s_b_9_11));
        /* execute.simd:3837 [D] s_b_9_14 = (u32)s_b_9_6 */
        auto s_b_9_14 = emitter.zx(s_b_9_6, emitter.context().types().u32());
        /* execute.simd:3837 [D] s_b_9_15 = s_b_9_14<s_b_9_13 */
        auto s_b_9_15 = emitter.cmp_lt(s_b_9_14, emitter.const_u32(s_b_9_13));
        /* execute.simd:3837 [D] s_b_9_16: If s_b_9_15: Jump b_10 else b_11 */
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
        /* execute.simd:3838 [F] s_b_10_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3838 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
        /* execute.simd:3838 [F] s_b_10_2 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_10_3 = s_b_10_1*s_b_10_2 (const) */
        uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3838 [F] s_b_10_4 = constant u32 3 (const) */
        /* execute.simd:3838 [F] s_b_10_5 = s_b_10_3+s_b_10_4 (const) */
        uint32_t s_b_10_5 = ((uint32_t)(s_b_10_3 + (uint32_t)3ULL));
        /* execute.simd:3838 [F] s_b_10_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3838 [F] s_b_10_7 = (u32)s_b_10_6 (const) */
        /* execute.simd:3838 [F] s_b_10_8 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_10_9 = s_b_10_7*s_b_10_8 (const) */
        uint32_t s_b_10_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3838 [D] s_b_10_10 = sym_35301_0_rm uint8_t */
        auto s_b_10_10 = emitter.load_local(DV_sym_35301_0_rm, emitter.context().types().u8());
        /* execute.simd:3838 [D] s_b_10_11 = (u32)s_b_10_10 */
        auto s_b_10_11 = emitter.zx(s_b_10_10, emitter.context().types().u32());
        /* execute.simd:3838 [D] s_b_10_12 = s_b_10_9+s_b_10_11 */
        auto s_b_10_12 = emitter.add(emitter.const_u32(s_b_10_9), s_b_10_11);
        /* execute.simd:3838 [D] s_b_10_13 = ReadRegBank 23:s_b_10_12 (u8) */
        captive::arch::dbt::el::Value *s_b_10_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_10_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_10_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3838 [D] s_b_10_14: WriteRegBank 23:s_b_10_5 = s_b_10_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_10_5))),s_b_10_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_10_5))),s_b_10_13);
        /* execute.simd:3838 [F] s_b_10_15: Jump b_11 (const) */
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* execute.simd:3835 [F] s_b_11_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3835 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
        /* execute.simd:3835 [F] s_b_11_2 = constant u32 10 (const) */
        /* execute.simd:3835 [F] s_b_11_3 = s_b_11_1*s_b_11_2 (const) */
        uint32_t s_b_11_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3835 [F] s_b_11_4 = constant u32 4 (const) */
        /* execute.simd:3835 [F] s_b_11_5 = s_b_11_3+s_b_11_4 (const) */
        uint32_t s_b_11_5 = ((uint32_t)(s_b_11_3 + (uint32_t)4ULL));
        /* execute.simd:3835 [D] s_b_11_6 = ReadRegBank 23:s_b_11_5 (u8) */
        auto s_b_11_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_11_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_11_5))),s_b_11_6,emitter.const_u8(1));
        }
        /* execute.simd:3835 [D] s_b_11_7: sym_35301_0_rm = s_b_11_6, dominates: s_b_12_10  */
        emitter.store_local(DV_sym_35301_0_rm, s_b_11_6);
        /* execute.simd:3837 [F] s_b_11_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3837 [F] s_b_11_9 = (u32)s_b_11_8 (const) */
        /* execute.simd:3837 [F] s_b_11_10 = constant u32 1 (const) */
        /* execute.simd:3837 [F] s_b_11_11 = s_b_11_9+s_b_11_10 (const) */
        uint32_t s_b_11_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3837 [F] s_b_11_12 = constant u32 10 (const) */
        /* execute.simd:3837 [F] s_b_11_13 = s_b_11_12*s_b_11_11 (const) */
        uint32_t s_b_11_13 = ((uint32_t)((uint32_t)16ULL * s_b_11_11));
        /* execute.simd:3837 [D] s_b_11_14 = (u32)s_b_11_6 */
        auto s_b_11_14 = emitter.zx(s_b_11_6, emitter.context().types().u32());
        /* execute.simd:3837 [D] s_b_11_15 = s_b_11_14<s_b_11_13 */
        auto s_b_11_15 = emitter.cmp_lt(s_b_11_14, emitter.const_u32(s_b_11_13));
        /* execute.simd:3837 [D] s_b_11_16: If s_b_11_15: Jump b_12 else b_13 */
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
        /* execute.simd:3838 [F] s_b_12_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3838 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
        /* execute.simd:3838 [F] s_b_12_2 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_12_3 = s_b_12_1*s_b_12_2 (const) */
        uint32_t s_b_12_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3838 [F] s_b_12_4 = constant u32 4 (const) */
        /* execute.simd:3838 [F] s_b_12_5 = s_b_12_3+s_b_12_4 (const) */
        uint32_t s_b_12_5 = ((uint32_t)(s_b_12_3 + (uint32_t)4ULL));
        /* execute.simd:3838 [F] s_b_12_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3838 [F] s_b_12_7 = (u32)s_b_12_6 (const) */
        /* execute.simd:3838 [F] s_b_12_8 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_12_9 = s_b_12_7*s_b_12_8 (const) */
        uint32_t s_b_12_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3838 [D] s_b_12_10 = sym_35301_0_rm uint8_t */
        auto s_b_12_10 = emitter.load_local(DV_sym_35301_0_rm, emitter.context().types().u8());
        /* execute.simd:3838 [D] s_b_12_11 = (u32)s_b_12_10 */
        auto s_b_12_11 = emitter.zx(s_b_12_10, emitter.context().types().u32());
        /* execute.simd:3838 [D] s_b_12_12 = s_b_12_9+s_b_12_11 */
        auto s_b_12_12 = emitter.add(emitter.const_u32(s_b_12_9), s_b_12_11);
        /* execute.simd:3838 [D] s_b_12_13 = ReadRegBank 23:s_b_12_12 (u8) */
        captive::arch::dbt::el::Value *s_b_12_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_12_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_12_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3838 [D] s_b_12_14: WriteRegBank 23:s_b_12_5 = s_b_12_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_12_5))),s_b_12_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_12_5))),s_b_12_13);
        /* execute.simd:3838 [F] s_b_12_15: Jump b_13 (const) */
        {
          auto block = block_b_13;
          dynamic_block_queue.push(block_b_13);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.simd:3835 [F] s_b_13_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3835 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
        /* execute.simd:3835 [F] s_b_13_2 = constant u32 10 (const) */
        /* execute.simd:3835 [F] s_b_13_3 = s_b_13_1*s_b_13_2 (const) */
        uint32_t s_b_13_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3835 [F] s_b_13_4 = constant u32 5 (const) */
        /* execute.simd:3835 [F] s_b_13_5 = s_b_13_3+s_b_13_4 (const) */
        uint32_t s_b_13_5 = ((uint32_t)(s_b_13_3 + (uint32_t)5ULL));
        /* execute.simd:3835 [D] s_b_13_6 = ReadRegBank 23:s_b_13_5 (u8) */
        auto s_b_13_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_13_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_13_5))),s_b_13_6,emitter.const_u8(1));
        }
        /* execute.simd:3835 [D] s_b_13_7: sym_35301_0_rm = s_b_13_6, dominates: s_b_14_10  */
        emitter.store_local(DV_sym_35301_0_rm, s_b_13_6);
        /* execute.simd:3837 [F] s_b_13_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3837 [F] s_b_13_9 = (u32)s_b_13_8 (const) */
        /* execute.simd:3837 [F] s_b_13_10 = constant u32 1 (const) */
        /* execute.simd:3837 [F] s_b_13_11 = s_b_13_9+s_b_13_10 (const) */
        uint32_t s_b_13_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3837 [F] s_b_13_12 = constant u32 10 (const) */
        /* execute.simd:3837 [F] s_b_13_13 = s_b_13_12*s_b_13_11 (const) */
        uint32_t s_b_13_13 = ((uint32_t)((uint32_t)16ULL * s_b_13_11));
        /* execute.simd:3837 [D] s_b_13_14 = (u32)s_b_13_6 */
        auto s_b_13_14 = emitter.zx(s_b_13_6, emitter.context().types().u32());
        /* execute.simd:3837 [D] s_b_13_15 = s_b_13_14<s_b_13_13 */
        auto s_b_13_15 = emitter.cmp_lt(s_b_13_14, emitter.const_u32(s_b_13_13));
        /* execute.simd:3837 [D] s_b_13_16: If s_b_13_15: Jump b_14 else b_15 */
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
        /* execute.simd:3838 [F] s_b_14_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3838 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
        /* execute.simd:3838 [F] s_b_14_2 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_14_3 = s_b_14_1*s_b_14_2 (const) */
        uint32_t s_b_14_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3838 [F] s_b_14_4 = constant u32 5 (const) */
        /* execute.simd:3838 [F] s_b_14_5 = s_b_14_3+s_b_14_4 (const) */
        uint32_t s_b_14_5 = ((uint32_t)(s_b_14_3 + (uint32_t)5ULL));
        /* execute.simd:3838 [F] s_b_14_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3838 [F] s_b_14_7 = (u32)s_b_14_6 (const) */
        /* execute.simd:3838 [F] s_b_14_8 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_14_9 = s_b_14_7*s_b_14_8 (const) */
        uint32_t s_b_14_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3838 [D] s_b_14_10 = sym_35301_0_rm uint8_t */
        auto s_b_14_10 = emitter.load_local(DV_sym_35301_0_rm, emitter.context().types().u8());
        /* execute.simd:3838 [D] s_b_14_11 = (u32)s_b_14_10 */
        auto s_b_14_11 = emitter.zx(s_b_14_10, emitter.context().types().u32());
        /* execute.simd:3838 [D] s_b_14_12 = s_b_14_9+s_b_14_11 */
        auto s_b_14_12 = emitter.add(emitter.const_u32(s_b_14_9), s_b_14_11);
        /* execute.simd:3838 [D] s_b_14_13 = ReadRegBank 23:s_b_14_12 (u8) */
        captive::arch::dbt::el::Value *s_b_14_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_14_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_14_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3838 [D] s_b_14_14: WriteRegBank 23:s_b_14_5 = s_b_14_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_14_5))),s_b_14_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_14_5))),s_b_14_13);
        /* execute.simd:3838 [F] s_b_14_15: Jump b_15 (const) */
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.simd:3835 [F] s_b_15_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3835 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
        /* execute.simd:3835 [F] s_b_15_2 = constant u32 10 (const) */
        /* execute.simd:3835 [F] s_b_15_3 = s_b_15_1*s_b_15_2 (const) */
        uint32_t s_b_15_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3835 [F] s_b_15_4 = constant u32 6 (const) */
        /* execute.simd:3835 [F] s_b_15_5 = s_b_15_3+s_b_15_4 (const) */
        uint32_t s_b_15_5 = ((uint32_t)(s_b_15_3 + (uint32_t)6ULL));
        /* execute.simd:3835 [D] s_b_15_6 = ReadRegBank 23:s_b_15_5 (u8) */
        auto s_b_15_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_15_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_15_5))),s_b_15_6,emitter.const_u8(1));
        }
        /* execute.simd:3835 [D] s_b_15_7: sym_35301_0_rm = s_b_15_6, dominates: s_b_16_10  */
        emitter.store_local(DV_sym_35301_0_rm, s_b_15_6);
        /* execute.simd:3837 [F] s_b_15_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3837 [F] s_b_15_9 = (u32)s_b_15_8 (const) */
        /* execute.simd:3837 [F] s_b_15_10 = constant u32 1 (const) */
        /* execute.simd:3837 [F] s_b_15_11 = s_b_15_9+s_b_15_10 (const) */
        uint32_t s_b_15_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3837 [F] s_b_15_12 = constant u32 10 (const) */
        /* execute.simd:3837 [F] s_b_15_13 = s_b_15_12*s_b_15_11 (const) */
        uint32_t s_b_15_13 = ((uint32_t)((uint32_t)16ULL * s_b_15_11));
        /* execute.simd:3837 [D] s_b_15_14 = (u32)s_b_15_6 */
        auto s_b_15_14 = emitter.zx(s_b_15_6, emitter.context().types().u32());
        /* execute.simd:3837 [D] s_b_15_15 = s_b_15_14<s_b_15_13 */
        auto s_b_15_15 = emitter.cmp_lt(s_b_15_14, emitter.const_u32(s_b_15_13));
        /* execute.simd:3837 [D] s_b_15_16: If s_b_15_15: Jump b_16 else b_17 */
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
        /* execute.simd:3838 [F] s_b_16_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3838 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
        /* execute.simd:3838 [F] s_b_16_2 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_16_3 = s_b_16_1*s_b_16_2 (const) */
        uint32_t s_b_16_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3838 [F] s_b_16_4 = constant u32 6 (const) */
        /* execute.simd:3838 [F] s_b_16_5 = s_b_16_3+s_b_16_4 (const) */
        uint32_t s_b_16_5 = ((uint32_t)(s_b_16_3 + (uint32_t)6ULL));
        /* execute.simd:3838 [F] s_b_16_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3838 [F] s_b_16_7 = (u32)s_b_16_6 (const) */
        /* execute.simd:3838 [F] s_b_16_8 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_16_9 = s_b_16_7*s_b_16_8 (const) */
        uint32_t s_b_16_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3838 [D] s_b_16_10 = sym_35301_0_rm uint8_t */
        auto s_b_16_10 = emitter.load_local(DV_sym_35301_0_rm, emitter.context().types().u8());
        /* execute.simd:3838 [D] s_b_16_11 = (u32)s_b_16_10 */
        auto s_b_16_11 = emitter.zx(s_b_16_10, emitter.context().types().u32());
        /* execute.simd:3838 [D] s_b_16_12 = s_b_16_9+s_b_16_11 */
        auto s_b_16_12 = emitter.add(emitter.const_u32(s_b_16_9), s_b_16_11);
        /* execute.simd:3838 [D] s_b_16_13 = ReadRegBank 23:s_b_16_12 (u8) */
        captive::arch::dbt::el::Value *s_b_16_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_16_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_16_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3838 [D] s_b_16_14: WriteRegBank 23:s_b_16_5 = s_b_16_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_16_5))),s_b_16_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_16_5))),s_b_16_13);
        /* execute.simd:3838 [F] s_b_16_15: Jump b_17 (const) */
        {
          auto block = block_b_17;
          dynamic_block_queue.push(block_b_17);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.simd:3835 [F] s_b_17_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3835 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
        /* execute.simd:3835 [F] s_b_17_2 = constant u32 10 (const) */
        /* execute.simd:3835 [F] s_b_17_3 = s_b_17_1*s_b_17_2 (const) */
        uint32_t s_b_17_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3835 [F] s_b_17_4 = constant u32 7 (const) */
        /* execute.simd:3835 [F] s_b_17_5 = s_b_17_3+s_b_17_4 (const) */
        uint32_t s_b_17_5 = ((uint32_t)(s_b_17_3 + (uint32_t)7ULL));
        /* execute.simd:3835 [D] s_b_17_6 = ReadRegBank 23:s_b_17_5 (u8) */
        auto s_b_17_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_17_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_17_5))),s_b_17_6,emitter.const_u8(1));
        }
        /* execute.simd:3835 [D] s_b_17_7: sym_35301_0_rm = s_b_17_6, dominates: s_b_18_10  */
        emitter.store_local(DV_sym_35301_0_rm, s_b_17_6);
        /* execute.simd:3837 [F] s_b_17_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3837 [F] s_b_17_9 = (u32)s_b_17_8 (const) */
        /* execute.simd:3837 [F] s_b_17_10 = constant u32 1 (const) */
        /* execute.simd:3837 [F] s_b_17_11 = s_b_17_9+s_b_17_10 (const) */
        uint32_t s_b_17_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3837 [F] s_b_17_12 = constant u32 10 (const) */
        /* execute.simd:3837 [F] s_b_17_13 = s_b_17_12*s_b_17_11 (const) */
        uint32_t s_b_17_13 = ((uint32_t)((uint32_t)16ULL * s_b_17_11));
        /* execute.simd:3837 [D] s_b_17_14 = (u32)s_b_17_6 */
        auto s_b_17_14 = emitter.zx(s_b_17_6, emitter.context().types().u32());
        /* execute.simd:3837 [D] s_b_17_15 = s_b_17_14<s_b_17_13 */
        auto s_b_17_15 = emitter.cmp_lt(s_b_17_14, emitter.const_u32(s_b_17_13));
        /* execute.simd:3837 [D] s_b_17_16: If s_b_17_15: Jump b_18 else b_19 */
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
        /* execute.simd:3838 [F] s_b_18_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3838 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
        /* execute.simd:3838 [F] s_b_18_2 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_18_3 = s_b_18_1*s_b_18_2 (const) */
        uint32_t s_b_18_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3838 [F] s_b_18_4 = constant u32 7 (const) */
        /* execute.simd:3838 [F] s_b_18_5 = s_b_18_3+s_b_18_4 (const) */
        uint32_t s_b_18_5 = ((uint32_t)(s_b_18_3 + (uint32_t)7ULL));
        /* execute.simd:3838 [F] s_b_18_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3838 [F] s_b_18_7 = (u32)s_b_18_6 (const) */
        /* execute.simd:3838 [F] s_b_18_8 = constant u32 10 (const) */
        /* execute.simd:3838 [F] s_b_18_9 = s_b_18_7*s_b_18_8 (const) */
        uint32_t s_b_18_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3838 [D] s_b_18_10 = sym_35301_0_rm uint8_t */
        auto s_b_18_10 = emitter.load_local(DV_sym_35301_0_rm, emitter.context().types().u8());
        /* execute.simd:3838 [D] s_b_18_11 = (u32)s_b_18_10 */
        auto s_b_18_11 = emitter.zx(s_b_18_10, emitter.context().types().u32());
        /* execute.simd:3838 [D] s_b_18_12 = s_b_18_9+s_b_18_11 */
        auto s_b_18_12 = emitter.add(emitter.const_u32(s_b_18_9), s_b_18_11);
        /* execute.simd:3838 [D] s_b_18_13 = ReadRegBank 23:s_b_18_12 (u8) */
        captive::arch::dbt::el::Value *s_b_18_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_18_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_18_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3838 [D] s_b_18_14: WriteRegBank 23:s_b_18_5 = s_b_18_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_18_5))),s_b_18_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_18_5))),s_b_18_13);
        /* execute.simd:3838 [F] s_b_18_15: Jump b_19 (const) */
        {
          auto block = block_b_19;
          dynamic_block_queue.push(block_b_19);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.simd:3842 [F] s_b_19_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3842 [F] s_b_19_1 = constant u64 0 (const) */
        /* execute.simd:3842 [F] s_b_19_2: WriteRegBank 3:s_b_19_0 = s_b_19_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:3834 [F] s_b_19_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.simd:3848 [F] s_b_20_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
        /* execute.simd:3848 [F] s_b_20_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_20_3 = s_b_20_1*s_b_20_2 (const) */
        uint32_t s_b_20_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_20_4 = constant u32 0 (const) */
        /* execute.simd:3848 [F] s_b_20_5 = s_b_20_3+s_b_20_4 (const) */
        uint32_t s_b_20_5 = ((uint32_t)(s_b_20_3 + (uint32_t)0ULL));
        /* execute.simd:3848 [F] s_b_20_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_20_7 = (u32)s_b_20_6 (const) */
        /* execute.simd:3848 [F] s_b_20_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_20_9 = s_b_20_7*s_b_20_8 (const) */
        uint32_t s_b_20_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_20_10 = sym_35686_0_rm uint8_t */
        auto s_b_20_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_20_11 = (u32)s_b_20_10 */
        auto s_b_20_11 = emitter.zx(s_b_20_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_20_12 = s_b_20_9+s_b_20_11 */
        auto s_b_20_12 = emitter.add(emitter.const_u32(s_b_20_9), s_b_20_11);
        /* execute.simd:3848 [D] s_b_20_13 = ReadRegBank 23:s_b_20_12 (u8) */
        captive::arch::dbt::el::Value *s_b_20_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_20_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_20_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_20_14: WriteRegBank 23:s_b_20_5 = s_b_20_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_20_5))),s_b_20_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_20_5))),s_b_20_13);
        /* execute.simd:3848 [F] s_b_20_15: Jump b_21 (const) */
        {
          auto block = block_b_21;
          dynamic_block_queue.push(block_b_21);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.simd:3845 [F] s_b_21_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
        /* execute.simd:3845 [F] s_b_21_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_21_3 = s_b_21_1*s_b_21_2 (const) */
        uint32_t s_b_21_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_21_4 = constant u32 1 (const) */
        /* execute.simd:3845 [F] s_b_21_5 = s_b_21_3+s_b_21_4 (const) */
        uint32_t s_b_21_5 = ((uint32_t)(s_b_21_3 + (uint32_t)1ULL));
        /* execute.simd:3845 [D] s_b_21_6 = ReadRegBank 23:s_b_21_5 (u8) */
        auto s_b_21_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_21_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_21_5))),s_b_21_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_21_7: sym_35686_0_rm = s_b_21_6, dominates: s_b_22_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_21_6);
        /* execute.simd:3847 [F] s_b_21_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_21_9 = (u32)s_b_21_8 (const) */
        /* execute.simd:3847 [F] s_b_21_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_21_11 = s_b_21_9+s_b_21_10 (const) */
        uint32_t s_b_21_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_21_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_21_13 = s_b_21_12*s_b_21_11 (const) */
        uint32_t s_b_21_13 = ((uint32_t)((uint32_t)16ULL * s_b_21_11));
        /* execute.simd:3847 [D] s_b_21_14 = (u32)s_b_21_6 */
        auto s_b_21_14 = emitter.zx(s_b_21_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_21_15 = s_b_21_14<s_b_21_13 */
        auto s_b_21_15 = emitter.cmp_lt(s_b_21_14, emitter.const_u32(s_b_21_13));
        /* execute.simd:3847 [D] s_b_21_16: If s_b_21_15: Jump b_22 else b_23 */
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
        /* execute.simd:3848 [F] s_b_22_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
        /* execute.simd:3848 [F] s_b_22_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_22_3 = s_b_22_1*s_b_22_2 (const) */
        uint32_t s_b_22_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_22_4 = constant u32 1 (const) */
        /* execute.simd:3848 [F] s_b_22_5 = s_b_22_3+s_b_22_4 (const) */
        uint32_t s_b_22_5 = ((uint32_t)(s_b_22_3 + (uint32_t)1ULL));
        /* execute.simd:3848 [F] s_b_22_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_22_7 = (u32)s_b_22_6 (const) */
        /* execute.simd:3848 [F] s_b_22_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_22_9 = s_b_22_7*s_b_22_8 (const) */
        uint32_t s_b_22_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_22_10 = sym_35686_0_rm uint8_t */
        auto s_b_22_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_22_11 = (u32)s_b_22_10 */
        auto s_b_22_11 = emitter.zx(s_b_22_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_22_12 = s_b_22_9+s_b_22_11 */
        auto s_b_22_12 = emitter.add(emitter.const_u32(s_b_22_9), s_b_22_11);
        /* execute.simd:3848 [D] s_b_22_13 = ReadRegBank 23:s_b_22_12 (u8) */
        captive::arch::dbt::el::Value *s_b_22_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_22_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_22_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_22_14: WriteRegBank 23:s_b_22_5 = s_b_22_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_22_5))),s_b_22_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_22_5))),s_b_22_13);
        /* execute.simd:3848 [F] s_b_22_15: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.simd:3845 [F] s_b_23_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
        /* execute.simd:3845 [F] s_b_23_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_23_3 = s_b_23_1*s_b_23_2 (const) */
        uint32_t s_b_23_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_23_4 = constant u32 2 (const) */
        /* execute.simd:3845 [F] s_b_23_5 = s_b_23_3+s_b_23_4 (const) */
        uint32_t s_b_23_5 = ((uint32_t)(s_b_23_3 + (uint32_t)2ULL));
        /* execute.simd:3845 [D] s_b_23_6 = ReadRegBank 23:s_b_23_5 (u8) */
        auto s_b_23_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_23_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_23_5))),s_b_23_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_23_7: sym_35686_0_rm = s_b_23_6, dominates: s_b_24_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_23_6);
        /* execute.simd:3847 [F] s_b_23_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_23_9 = (u32)s_b_23_8 (const) */
        /* execute.simd:3847 [F] s_b_23_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_23_11 = s_b_23_9+s_b_23_10 (const) */
        uint32_t s_b_23_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_23_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_23_13 = s_b_23_12*s_b_23_11 (const) */
        uint32_t s_b_23_13 = ((uint32_t)((uint32_t)16ULL * s_b_23_11));
        /* execute.simd:3847 [D] s_b_23_14 = (u32)s_b_23_6 */
        auto s_b_23_14 = emitter.zx(s_b_23_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_23_15 = s_b_23_14<s_b_23_13 */
        auto s_b_23_15 = emitter.cmp_lt(s_b_23_14, emitter.const_u32(s_b_23_13));
        /* execute.simd:3847 [D] s_b_23_16: If s_b_23_15: Jump b_24 else b_25 */
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
        /* execute.simd:3848 [F] s_b_24_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
        /* execute.simd:3848 [F] s_b_24_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_24_3 = s_b_24_1*s_b_24_2 (const) */
        uint32_t s_b_24_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_24_4 = constant u32 2 (const) */
        /* execute.simd:3848 [F] s_b_24_5 = s_b_24_3+s_b_24_4 (const) */
        uint32_t s_b_24_5 = ((uint32_t)(s_b_24_3 + (uint32_t)2ULL));
        /* execute.simd:3848 [F] s_b_24_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_24_7 = (u32)s_b_24_6 (const) */
        /* execute.simd:3848 [F] s_b_24_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_24_9 = s_b_24_7*s_b_24_8 (const) */
        uint32_t s_b_24_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_24_10 = sym_35686_0_rm uint8_t */
        auto s_b_24_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_24_11 = (u32)s_b_24_10 */
        auto s_b_24_11 = emitter.zx(s_b_24_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_24_12 = s_b_24_9+s_b_24_11 */
        auto s_b_24_12 = emitter.add(emitter.const_u32(s_b_24_9), s_b_24_11);
        /* execute.simd:3848 [D] s_b_24_13 = ReadRegBank 23:s_b_24_12 (u8) */
        captive::arch::dbt::el::Value *s_b_24_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_24_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_24_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_24_14: WriteRegBank 23:s_b_24_5 = s_b_24_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_24_5))),s_b_24_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_24_5))),s_b_24_13);
        /* execute.simd:3848 [F] s_b_24_15: Jump b_25 (const) */
        {
          auto block = block_b_25;
          dynamic_block_queue.push(block_b_25);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.simd:3845 [F] s_b_25_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
        /* execute.simd:3845 [F] s_b_25_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_25_3 = s_b_25_1*s_b_25_2 (const) */
        uint32_t s_b_25_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_25_4 = constant u32 3 (const) */
        /* execute.simd:3845 [F] s_b_25_5 = s_b_25_3+s_b_25_4 (const) */
        uint32_t s_b_25_5 = ((uint32_t)(s_b_25_3 + (uint32_t)3ULL));
        /* execute.simd:3845 [D] s_b_25_6 = ReadRegBank 23:s_b_25_5 (u8) */
        auto s_b_25_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_25_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_25_5))),s_b_25_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_25_7: sym_35686_0_rm = s_b_25_6, dominates: s_b_26_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_25_6);
        /* execute.simd:3847 [F] s_b_25_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_25_9 = (u32)s_b_25_8 (const) */
        /* execute.simd:3847 [F] s_b_25_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_25_11 = s_b_25_9+s_b_25_10 (const) */
        uint32_t s_b_25_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_25_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_25_13 = s_b_25_12*s_b_25_11 (const) */
        uint32_t s_b_25_13 = ((uint32_t)((uint32_t)16ULL * s_b_25_11));
        /* execute.simd:3847 [D] s_b_25_14 = (u32)s_b_25_6 */
        auto s_b_25_14 = emitter.zx(s_b_25_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_25_15 = s_b_25_14<s_b_25_13 */
        auto s_b_25_15 = emitter.cmp_lt(s_b_25_14, emitter.const_u32(s_b_25_13));
        /* execute.simd:3847 [D] s_b_25_16: If s_b_25_15: Jump b_26 else b_27 */
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
        /* execute.simd:3848 [F] s_b_26_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
        /* execute.simd:3848 [F] s_b_26_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_26_3 = s_b_26_1*s_b_26_2 (const) */
        uint32_t s_b_26_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_26_4 = constant u32 3 (const) */
        /* execute.simd:3848 [F] s_b_26_5 = s_b_26_3+s_b_26_4 (const) */
        uint32_t s_b_26_5 = ((uint32_t)(s_b_26_3 + (uint32_t)3ULL));
        /* execute.simd:3848 [F] s_b_26_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_26_7 = (u32)s_b_26_6 (const) */
        /* execute.simd:3848 [F] s_b_26_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_26_9 = s_b_26_7*s_b_26_8 (const) */
        uint32_t s_b_26_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_26_10 = sym_35686_0_rm uint8_t */
        auto s_b_26_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_26_11 = (u32)s_b_26_10 */
        auto s_b_26_11 = emitter.zx(s_b_26_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_26_12 = s_b_26_9+s_b_26_11 */
        auto s_b_26_12 = emitter.add(emitter.const_u32(s_b_26_9), s_b_26_11);
        /* execute.simd:3848 [D] s_b_26_13 = ReadRegBank 23:s_b_26_12 (u8) */
        captive::arch::dbt::el::Value *s_b_26_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_26_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_26_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_26_14: WriteRegBank 23:s_b_26_5 = s_b_26_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_26_5))),s_b_26_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_26_5))),s_b_26_13);
        /* execute.simd:3848 [F] s_b_26_15: Jump b_27 (const) */
        {
          auto block = block_b_27;
          dynamic_block_queue.push(block_b_27);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.simd:3845 [F] s_b_27_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
        /* execute.simd:3845 [F] s_b_27_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_27_3 = s_b_27_1*s_b_27_2 (const) */
        uint32_t s_b_27_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_27_4 = constant u32 4 (const) */
        /* execute.simd:3845 [F] s_b_27_5 = s_b_27_3+s_b_27_4 (const) */
        uint32_t s_b_27_5 = ((uint32_t)(s_b_27_3 + (uint32_t)4ULL));
        /* execute.simd:3845 [D] s_b_27_6 = ReadRegBank 23:s_b_27_5 (u8) */
        auto s_b_27_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_27_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_27_5))),s_b_27_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_27_7: sym_35686_0_rm = s_b_27_6, dominates: s_b_28_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_27_6);
        /* execute.simd:3847 [F] s_b_27_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_27_9 = (u32)s_b_27_8 (const) */
        /* execute.simd:3847 [F] s_b_27_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_27_11 = s_b_27_9+s_b_27_10 (const) */
        uint32_t s_b_27_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_27_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_27_13 = s_b_27_12*s_b_27_11 (const) */
        uint32_t s_b_27_13 = ((uint32_t)((uint32_t)16ULL * s_b_27_11));
        /* execute.simd:3847 [D] s_b_27_14 = (u32)s_b_27_6 */
        auto s_b_27_14 = emitter.zx(s_b_27_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_27_15 = s_b_27_14<s_b_27_13 */
        auto s_b_27_15 = emitter.cmp_lt(s_b_27_14, emitter.const_u32(s_b_27_13));
        /* execute.simd:3847 [D] s_b_27_16: If s_b_27_15: Jump b_28 else b_29 */
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
        /* execute.simd:3848 [F] s_b_28_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
        /* execute.simd:3848 [F] s_b_28_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_28_3 = s_b_28_1*s_b_28_2 (const) */
        uint32_t s_b_28_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_28_4 = constant u32 4 (const) */
        /* execute.simd:3848 [F] s_b_28_5 = s_b_28_3+s_b_28_4 (const) */
        uint32_t s_b_28_5 = ((uint32_t)(s_b_28_3 + (uint32_t)4ULL));
        /* execute.simd:3848 [F] s_b_28_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_28_7 = (u32)s_b_28_6 (const) */
        /* execute.simd:3848 [F] s_b_28_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_28_9 = s_b_28_7*s_b_28_8 (const) */
        uint32_t s_b_28_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_28_10 = sym_35686_0_rm uint8_t */
        auto s_b_28_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_28_11 = (u32)s_b_28_10 */
        auto s_b_28_11 = emitter.zx(s_b_28_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_28_12 = s_b_28_9+s_b_28_11 */
        auto s_b_28_12 = emitter.add(emitter.const_u32(s_b_28_9), s_b_28_11);
        /* execute.simd:3848 [D] s_b_28_13 = ReadRegBank 23:s_b_28_12 (u8) */
        captive::arch::dbt::el::Value *s_b_28_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_28_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_28_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_28_14: WriteRegBank 23:s_b_28_5 = s_b_28_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_28_5))),s_b_28_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_28_5))),s_b_28_13);
        /* execute.simd:3848 [F] s_b_28_15: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.simd:3845 [F] s_b_29_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
        /* execute.simd:3845 [F] s_b_29_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_29_3 = s_b_29_1*s_b_29_2 (const) */
        uint32_t s_b_29_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_29_4 = constant u32 5 (const) */
        /* execute.simd:3845 [F] s_b_29_5 = s_b_29_3+s_b_29_4 (const) */
        uint32_t s_b_29_5 = ((uint32_t)(s_b_29_3 + (uint32_t)5ULL));
        /* execute.simd:3845 [D] s_b_29_6 = ReadRegBank 23:s_b_29_5 (u8) */
        auto s_b_29_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_29_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_29_5))),s_b_29_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_29_7: sym_35686_0_rm = s_b_29_6, dominates: s_b_30_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_29_6);
        /* execute.simd:3847 [F] s_b_29_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_29_9 = (u32)s_b_29_8 (const) */
        /* execute.simd:3847 [F] s_b_29_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_29_11 = s_b_29_9+s_b_29_10 (const) */
        uint32_t s_b_29_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_29_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_29_13 = s_b_29_12*s_b_29_11 (const) */
        uint32_t s_b_29_13 = ((uint32_t)((uint32_t)16ULL * s_b_29_11));
        /* execute.simd:3847 [D] s_b_29_14 = (u32)s_b_29_6 */
        auto s_b_29_14 = emitter.zx(s_b_29_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_29_15 = s_b_29_14<s_b_29_13 */
        auto s_b_29_15 = emitter.cmp_lt(s_b_29_14, emitter.const_u32(s_b_29_13));
        /* execute.simd:3847 [D] s_b_29_16: If s_b_29_15: Jump b_30 else b_31 */
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
        /* execute.simd:3848 [F] s_b_30_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_30_1 = (u32)s_b_30_0 (const) */
        /* execute.simd:3848 [F] s_b_30_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_30_3 = s_b_30_1*s_b_30_2 (const) */
        uint32_t s_b_30_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_30_4 = constant u32 5 (const) */
        /* execute.simd:3848 [F] s_b_30_5 = s_b_30_3+s_b_30_4 (const) */
        uint32_t s_b_30_5 = ((uint32_t)(s_b_30_3 + (uint32_t)5ULL));
        /* execute.simd:3848 [F] s_b_30_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_30_7 = (u32)s_b_30_6 (const) */
        /* execute.simd:3848 [F] s_b_30_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_30_9 = s_b_30_7*s_b_30_8 (const) */
        uint32_t s_b_30_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_30_10 = sym_35686_0_rm uint8_t */
        auto s_b_30_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_30_11 = (u32)s_b_30_10 */
        auto s_b_30_11 = emitter.zx(s_b_30_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_30_12 = s_b_30_9+s_b_30_11 */
        auto s_b_30_12 = emitter.add(emitter.const_u32(s_b_30_9), s_b_30_11);
        /* execute.simd:3848 [D] s_b_30_13 = ReadRegBank 23:s_b_30_12 (u8) */
        captive::arch::dbt::el::Value *s_b_30_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_30_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_30_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_30_14: WriteRegBank 23:s_b_30_5 = s_b_30_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_30_5))),s_b_30_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_30_5))),s_b_30_13);
        /* execute.simd:3848 [F] s_b_30_15: Jump b_31 (const) */
        {
          auto block = block_b_31;
          dynamic_block_queue.push(block_b_31);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.simd:3845 [F] s_b_31_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
        /* execute.simd:3845 [F] s_b_31_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_31_3 = s_b_31_1*s_b_31_2 (const) */
        uint32_t s_b_31_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_31_4 = constant u32 6 (const) */
        /* execute.simd:3845 [F] s_b_31_5 = s_b_31_3+s_b_31_4 (const) */
        uint32_t s_b_31_5 = ((uint32_t)(s_b_31_3 + (uint32_t)6ULL));
        /* execute.simd:3845 [D] s_b_31_6 = ReadRegBank 23:s_b_31_5 (u8) */
        auto s_b_31_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_31_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_31_5))),s_b_31_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_31_7: sym_35686_0_rm = s_b_31_6, dominates: s_b_32_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_31_6);
        /* execute.simd:3847 [F] s_b_31_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_31_9 = (u32)s_b_31_8 (const) */
        /* execute.simd:3847 [F] s_b_31_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_31_11 = s_b_31_9+s_b_31_10 (const) */
        uint32_t s_b_31_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_31_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_31_13 = s_b_31_12*s_b_31_11 (const) */
        uint32_t s_b_31_13 = ((uint32_t)((uint32_t)16ULL * s_b_31_11));
        /* execute.simd:3847 [D] s_b_31_14 = (u32)s_b_31_6 */
        auto s_b_31_14 = emitter.zx(s_b_31_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_31_15 = s_b_31_14<s_b_31_13 */
        auto s_b_31_15 = emitter.cmp_lt(s_b_31_14, emitter.const_u32(s_b_31_13));
        /* execute.simd:3847 [D] s_b_31_16: If s_b_31_15: Jump b_32 else b_33 */
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
        /* execute.simd:3848 [F] s_b_32_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_32_1 = (u32)s_b_32_0 (const) */
        /* execute.simd:3848 [F] s_b_32_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_32_3 = s_b_32_1*s_b_32_2 (const) */
        uint32_t s_b_32_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_32_4 = constant u32 6 (const) */
        /* execute.simd:3848 [F] s_b_32_5 = s_b_32_3+s_b_32_4 (const) */
        uint32_t s_b_32_5 = ((uint32_t)(s_b_32_3 + (uint32_t)6ULL));
        /* execute.simd:3848 [F] s_b_32_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_32_7 = (u32)s_b_32_6 (const) */
        /* execute.simd:3848 [F] s_b_32_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_32_9 = s_b_32_7*s_b_32_8 (const) */
        uint32_t s_b_32_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_32_10 = sym_35686_0_rm uint8_t */
        auto s_b_32_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_32_11 = (u32)s_b_32_10 */
        auto s_b_32_11 = emitter.zx(s_b_32_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_32_12 = s_b_32_9+s_b_32_11 */
        auto s_b_32_12 = emitter.add(emitter.const_u32(s_b_32_9), s_b_32_11);
        /* execute.simd:3848 [D] s_b_32_13 = ReadRegBank 23:s_b_32_12 (u8) */
        captive::arch::dbt::el::Value *s_b_32_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_32_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_32_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_32_14: WriteRegBank 23:s_b_32_5 = s_b_32_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_32_5))),s_b_32_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_32_5))),s_b_32_13);
        /* execute.simd:3848 [F] s_b_32_15: Jump b_33 (const) */
        {
          auto block = block_b_33;
          dynamic_block_queue.push(block_b_33);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.simd:3845 [F] s_b_33_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_33_1 = (u32)s_b_33_0 (const) */
        /* execute.simd:3845 [F] s_b_33_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_33_3 = s_b_33_1*s_b_33_2 (const) */
        uint32_t s_b_33_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_33_4 = constant u32 7 (const) */
        /* execute.simd:3845 [F] s_b_33_5 = s_b_33_3+s_b_33_4 (const) */
        uint32_t s_b_33_5 = ((uint32_t)(s_b_33_3 + (uint32_t)7ULL));
        /* execute.simd:3845 [D] s_b_33_6 = ReadRegBank 23:s_b_33_5 (u8) */
        auto s_b_33_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_33_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_33_5))),s_b_33_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_33_7: sym_35686_0_rm = s_b_33_6, dominates: s_b_34_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_33_6);
        /* execute.simd:3847 [F] s_b_33_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_33_9 = (u32)s_b_33_8 (const) */
        /* execute.simd:3847 [F] s_b_33_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_33_11 = s_b_33_9+s_b_33_10 (const) */
        uint32_t s_b_33_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_33_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_33_13 = s_b_33_12*s_b_33_11 (const) */
        uint32_t s_b_33_13 = ((uint32_t)((uint32_t)16ULL * s_b_33_11));
        /* execute.simd:3847 [D] s_b_33_14 = (u32)s_b_33_6 */
        auto s_b_33_14 = emitter.zx(s_b_33_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_33_15 = s_b_33_14<s_b_33_13 */
        auto s_b_33_15 = emitter.cmp_lt(s_b_33_14, emitter.const_u32(s_b_33_13));
        /* execute.simd:3847 [D] s_b_33_16: If s_b_33_15: Jump b_34 else b_35 */
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
        /* execute.simd:3848 [F] s_b_34_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
        /* execute.simd:3848 [F] s_b_34_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_34_3 = s_b_34_1*s_b_34_2 (const) */
        uint32_t s_b_34_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_34_4 = constant u32 7 (const) */
        /* execute.simd:3848 [F] s_b_34_5 = s_b_34_3+s_b_34_4 (const) */
        uint32_t s_b_34_5 = ((uint32_t)(s_b_34_3 + (uint32_t)7ULL));
        /* execute.simd:3848 [F] s_b_34_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_34_7 = (u32)s_b_34_6 (const) */
        /* execute.simd:3848 [F] s_b_34_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_34_9 = s_b_34_7*s_b_34_8 (const) */
        uint32_t s_b_34_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_34_10 = sym_35686_0_rm uint8_t */
        auto s_b_34_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_34_11 = (u32)s_b_34_10 */
        auto s_b_34_11 = emitter.zx(s_b_34_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_34_12 = s_b_34_9+s_b_34_11 */
        auto s_b_34_12 = emitter.add(emitter.const_u32(s_b_34_9), s_b_34_11);
        /* execute.simd:3848 [D] s_b_34_13 = ReadRegBank 23:s_b_34_12 (u8) */
        captive::arch::dbt::el::Value *s_b_34_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_34_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_34_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_34_14: WriteRegBank 23:s_b_34_5 = s_b_34_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_34_5))),s_b_34_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_34_5))),s_b_34_13);
        /* execute.simd:3848 [F] s_b_34_15: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.simd:3845 [F] s_b_35_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
        /* execute.simd:3845 [F] s_b_35_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_35_3 = s_b_35_1*s_b_35_2 (const) */
        uint32_t s_b_35_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_35_4 = constant u32 8 (const) */
        /* execute.simd:3845 [F] s_b_35_5 = s_b_35_3+s_b_35_4 (const) */
        uint32_t s_b_35_5 = ((uint32_t)(s_b_35_3 + (uint32_t)8ULL));
        /* execute.simd:3845 [D] s_b_35_6 = ReadRegBank 23:s_b_35_5 (u8) */
        auto s_b_35_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_35_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_35_5))),s_b_35_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_35_7: sym_35686_0_rm = s_b_35_6, dominates: s_b_36_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_35_6);
        /* execute.simd:3847 [F] s_b_35_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_35_9 = (u32)s_b_35_8 (const) */
        /* execute.simd:3847 [F] s_b_35_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_35_11 = s_b_35_9+s_b_35_10 (const) */
        uint32_t s_b_35_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_35_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_35_13 = s_b_35_12*s_b_35_11 (const) */
        uint32_t s_b_35_13 = ((uint32_t)((uint32_t)16ULL * s_b_35_11));
        /* execute.simd:3847 [D] s_b_35_14 = (u32)s_b_35_6 */
        auto s_b_35_14 = emitter.zx(s_b_35_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_35_15 = s_b_35_14<s_b_35_13 */
        auto s_b_35_15 = emitter.cmp_lt(s_b_35_14, emitter.const_u32(s_b_35_13));
        /* execute.simd:3847 [D] s_b_35_16: If s_b_35_15: Jump b_36 else b_37 */
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
        /* execute.simd:3848 [F] s_b_36_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_36_1 = (u32)s_b_36_0 (const) */
        /* execute.simd:3848 [F] s_b_36_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_36_3 = s_b_36_1*s_b_36_2 (const) */
        uint32_t s_b_36_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_36_4 = constant u32 8 (const) */
        /* execute.simd:3848 [F] s_b_36_5 = s_b_36_3+s_b_36_4 (const) */
        uint32_t s_b_36_5 = ((uint32_t)(s_b_36_3 + (uint32_t)8ULL));
        /* execute.simd:3848 [F] s_b_36_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_36_7 = (u32)s_b_36_6 (const) */
        /* execute.simd:3848 [F] s_b_36_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_36_9 = s_b_36_7*s_b_36_8 (const) */
        uint32_t s_b_36_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_36_10 = sym_35686_0_rm uint8_t */
        auto s_b_36_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_36_11 = (u32)s_b_36_10 */
        auto s_b_36_11 = emitter.zx(s_b_36_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_36_12 = s_b_36_9+s_b_36_11 */
        auto s_b_36_12 = emitter.add(emitter.const_u32(s_b_36_9), s_b_36_11);
        /* execute.simd:3848 [D] s_b_36_13 = ReadRegBank 23:s_b_36_12 (u8) */
        captive::arch::dbt::el::Value *s_b_36_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_36_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_36_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_36_14: WriteRegBank 23:s_b_36_5 = s_b_36_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_36_5))),s_b_36_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_36_5))),s_b_36_13);
        /* execute.simd:3848 [F] s_b_36_15: Jump b_37 (const) */
        {
          auto block = block_b_37;
          dynamic_block_queue.push(block_b_37);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.simd:3845 [F] s_b_37_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_37_1 = (u32)s_b_37_0 (const) */
        /* execute.simd:3845 [F] s_b_37_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_37_3 = s_b_37_1*s_b_37_2 (const) */
        uint32_t s_b_37_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_37_4 = constant u32 9 (const) */
        /* execute.simd:3845 [F] s_b_37_5 = s_b_37_3+s_b_37_4 (const) */
        uint32_t s_b_37_5 = ((uint32_t)(s_b_37_3 + (uint32_t)9ULL));
        /* execute.simd:3845 [D] s_b_37_6 = ReadRegBank 23:s_b_37_5 (u8) */
        auto s_b_37_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_37_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_37_5))),s_b_37_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_37_7: sym_35686_0_rm = s_b_37_6, dominates: s_b_38_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_37_6);
        /* execute.simd:3847 [F] s_b_37_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_37_9 = (u32)s_b_37_8 (const) */
        /* execute.simd:3847 [F] s_b_37_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_37_11 = s_b_37_9+s_b_37_10 (const) */
        uint32_t s_b_37_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_37_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_37_13 = s_b_37_12*s_b_37_11 (const) */
        uint32_t s_b_37_13 = ((uint32_t)((uint32_t)16ULL * s_b_37_11));
        /* execute.simd:3847 [D] s_b_37_14 = (u32)s_b_37_6 */
        auto s_b_37_14 = emitter.zx(s_b_37_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_37_15 = s_b_37_14<s_b_37_13 */
        auto s_b_37_15 = emitter.cmp_lt(s_b_37_14, emitter.const_u32(s_b_37_13));
        /* execute.simd:3847 [D] s_b_37_16: If s_b_37_15: Jump b_38 else b_39 */
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
        /* execute.simd:3848 [F] s_b_38_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_38_1 = (u32)s_b_38_0 (const) */
        /* execute.simd:3848 [F] s_b_38_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_38_3 = s_b_38_1*s_b_38_2 (const) */
        uint32_t s_b_38_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_38_4 = constant u32 9 (const) */
        /* execute.simd:3848 [F] s_b_38_5 = s_b_38_3+s_b_38_4 (const) */
        uint32_t s_b_38_5 = ((uint32_t)(s_b_38_3 + (uint32_t)9ULL));
        /* execute.simd:3848 [F] s_b_38_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_38_7 = (u32)s_b_38_6 (const) */
        /* execute.simd:3848 [F] s_b_38_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_38_9 = s_b_38_7*s_b_38_8 (const) */
        uint32_t s_b_38_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_38_10 = sym_35686_0_rm uint8_t */
        auto s_b_38_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_38_11 = (u32)s_b_38_10 */
        auto s_b_38_11 = emitter.zx(s_b_38_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_38_12 = s_b_38_9+s_b_38_11 */
        auto s_b_38_12 = emitter.add(emitter.const_u32(s_b_38_9), s_b_38_11);
        /* execute.simd:3848 [D] s_b_38_13 = ReadRegBank 23:s_b_38_12 (u8) */
        captive::arch::dbt::el::Value *s_b_38_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_38_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_38_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_38_14: WriteRegBank 23:s_b_38_5 = s_b_38_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_38_5))),s_b_38_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_38_5))),s_b_38_13);
        /* execute.simd:3848 [F] s_b_38_15: Jump b_39 (const) */
        {
          auto block = block_b_39;
          dynamic_block_queue.push(block_b_39);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.simd:3845 [F] s_b_39_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_39_1 = (u32)s_b_39_0 (const) */
        /* execute.simd:3845 [F] s_b_39_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_39_3 = s_b_39_1*s_b_39_2 (const) */
        uint32_t s_b_39_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_39_4 = constant u32 a (const) */
        /* execute.simd:3845 [F] s_b_39_5 = s_b_39_3+s_b_39_4 (const) */
        uint32_t s_b_39_5 = ((uint32_t)(s_b_39_3 + (uint32_t)10ULL));
        /* execute.simd:3845 [D] s_b_39_6 = ReadRegBank 23:s_b_39_5 (u8) */
        auto s_b_39_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_39_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_39_5))),s_b_39_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_39_7: sym_35686_0_rm = s_b_39_6, dominates: s_b_40_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_39_6);
        /* execute.simd:3847 [F] s_b_39_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_39_9 = (u32)s_b_39_8 (const) */
        /* execute.simd:3847 [F] s_b_39_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_39_11 = s_b_39_9+s_b_39_10 (const) */
        uint32_t s_b_39_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_39_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_39_13 = s_b_39_12*s_b_39_11 (const) */
        uint32_t s_b_39_13 = ((uint32_t)((uint32_t)16ULL * s_b_39_11));
        /* execute.simd:3847 [D] s_b_39_14 = (u32)s_b_39_6 */
        auto s_b_39_14 = emitter.zx(s_b_39_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_39_15 = s_b_39_14<s_b_39_13 */
        auto s_b_39_15 = emitter.cmp_lt(s_b_39_14, emitter.const_u32(s_b_39_13));
        /* execute.simd:3847 [D] s_b_39_16: If s_b_39_15: Jump b_40 else b_41 */
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
        /* execute.simd:3848 [F] s_b_40_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_40_1 = (u32)s_b_40_0 (const) */
        /* execute.simd:3848 [F] s_b_40_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_40_3 = s_b_40_1*s_b_40_2 (const) */
        uint32_t s_b_40_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_40_4 = constant u32 a (const) */
        /* execute.simd:3848 [F] s_b_40_5 = s_b_40_3+s_b_40_4 (const) */
        uint32_t s_b_40_5 = ((uint32_t)(s_b_40_3 + (uint32_t)10ULL));
        /* execute.simd:3848 [F] s_b_40_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_40_7 = (u32)s_b_40_6 (const) */
        /* execute.simd:3848 [F] s_b_40_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_40_9 = s_b_40_7*s_b_40_8 (const) */
        uint32_t s_b_40_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_40_10 = sym_35686_0_rm uint8_t */
        auto s_b_40_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_40_11 = (u32)s_b_40_10 */
        auto s_b_40_11 = emitter.zx(s_b_40_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_40_12 = s_b_40_9+s_b_40_11 */
        auto s_b_40_12 = emitter.add(emitter.const_u32(s_b_40_9), s_b_40_11);
        /* execute.simd:3848 [D] s_b_40_13 = ReadRegBank 23:s_b_40_12 (u8) */
        captive::arch::dbt::el::Value *s_b_40_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_40_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_40_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_40_14: WriteRegBank 23:s_b_40_5 = s_b_40_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_40_5))),s_b_40_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_40_5))),s_b_40_13);
        /* execute.simd:3848 [F] s_b_40_15: Jump b_41 (const) */
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.simd:3845 [F] s_b_41_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_41_1 = (u32)s_b_41_0 (const) */
        /* execute.simd:3845 [F] s_b_41_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_41_3 = s_b_41_1*s_b_41_2 (const) */
        uint32_t s_b_41_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_41_4 = constant u32 b (const) */
        /* execute.simd:3845 [F] s_b_41_5 = s_b_41_3+s_b_41_4 (const) */
        uint32_t s_b_41_5 = ((uint32_t)(s_b_41_3 + (uint32_t)11ULL));
        /* execute.simd:3845 [D] s_b_41_6 = ReadRegBank 23:s_b_41_5 (u8) */
        auto s_b_41_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_41_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_41_5))),s_b_41_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_41_7: sym_35686_0_rm = s_b_41_6, dominates: s_b_42_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_41_6);
        /* execute.simd:3847 [F] s_b_41_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_41_9 = (u32)s_b_41_8 (const) */
        /* execute.simd:3847 [F] s_b_41_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_41_11 = s_b_41_9+s_b_41_10 (const) */
        uint32_t s_b_41_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_41_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_41_13 = s_b_41_12*s_b_41_11 (const) */
        uint32_t s_b_41_13 = ((uint32_t)((uint32_t)16ULL * s_b_41_11));
        /* execute.simd:3847 [D] s_b_41_14 = (u32)s_b_41_6 */
        auto s_b_41_14 = emitter.zx(s_b_41_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_41_15 = s_b_41_14<s_b_41_13 */
        auto s_b_41_15 = emitter.cmp_lt(s_b_41_14, emitter.const_u32(s_b_41_13));
        /* execute.simd:3847 [D] s_b_41_16: If s_b_41_15: Jump b_42 else b_43 */
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
        /* execute.simd:3848 [F] s_b_42_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_42_1 = (u32)s_b_42_0 (const) */
        /* execute.simd:3848 [F] s_b_42_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_42_3 = s_b_42_1*s_b_42_2 (const) */
        uint32_t s_b_42_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_42_4 = constant u32 b (const) */
        /* execute.simd:3848 [F] s_b_42_5 = s_b_42_3+s_b_42_4 (const) */
        uint32_t s_b_42_5 = ((uint32_t)(s_b_42_3 + (uint32_t)11ULL));
        /* execute.simd:3848 [F] s_b_42_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_42_7 = (u32)s_b_42_6 (const) */
        /* execute.simd:3848 [F] s_b_42_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_42_9 = s_b_42_7*s_b_42_8 (const) */
        uint32_t s_b_42_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_42_10 = sym_35686_0_rm uint8_t */
        auto s_b_42_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_42_11 = (u32)s_b_42_10 */
        auto s_b_42_11 = emitter.zx(s_b_42_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_42_12 = s_b_42_9+s_b_42_11 */
        auto s_b_42_12 = emitter.add(emitter.const_u32(s_b_42_9), s_b_42_11);
        /* execute.simd:3848 [D] s_b_42_13 = ReadRegBank 23:s_b_42_12 (u8) */
        captive::arch::dbt::el::Value *s_b_42_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_42_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_42_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_42_14: WriteRegBank 23:s_b_42_5 = s_b_42_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_42_5))),s_b_42_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_42_5))),s_b_42_13);
        /* execute.simd:3848 [F] s_b_42_15: Jump b_43 (const) */
        {
          auto block = block_b_43;
          dynamic_block_queue.push(block_b_43);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_43) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_43);
        /* execute.simd:3845 [F] s_b_43_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_43_1 = (u32)s_b_43_0 (const) */
        /* execute.simd:3845 [F] s_b_43_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_43_3 = s_b_43_1*s_b_43_2 (const) */
        uint32_t s_b_43_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_43_4 = constant u32 c (const) */
        /* execute.simd:3845 [F] s_b_43_5 = s_b_43_3+s_b_43_4 (const) */
        uint32_t s_b_43_5 = ((uint32_t)(s_b_43_3 + (uint32_t)12ULL));
        /* execute.simd:3845 [D] s_b_43_6 = ReadRegBank 23:s_b_43_5 (u8) */
        auto s_b_43_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_43_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_43_5))),s_b_43_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_43_7: sym_35686_0_rm = s_b_43_6, dominates: s_b_44_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_43_6);
        /* execute.simd:3847 [F] s_b_43_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_43_9 = (u32)s_b_43_8 (const) */
        /* execute.simd:3847 [F] s_b_43_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_43_11 = s_b_43_9+s_b_43_10 (const) */
        uint32_t s_b_43_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_43_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_43_13 = s_b_43_12*s_b_43_11 (const) */
        uint32_t s_b_43_13 = ((uint32_t)((uint32_t)16ULL * s_b_43_11));
        /* execute.simd:3847 [D] s_b_43_14 = (u32)s_b_43_6 */
        auto s_b_43_14 = emitter.zx(s_b_43_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_43_15 = s_b_43_14<s_b_43_13 */
        auto s_b_43_15 = emitter.cmp_lt(s_b_43_14, emitter.const_u32(s_b_43_13));
        /* execute.simd:3847 [D] s_b_43_16: If s_b_43_15: Jump b_44 else b_45 */
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
        /* execute.simd:3848 [F] s_b_44_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_44_1 = (u32)s_b_44_0 (const) */
        /* execute.simd:3848 [F] s_b_44_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_44_3 = s_b_44_1*s_b_44_2 (const) */
        uint32_t s_b_44_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_44_4 = constant u32 c (const) */
        /* execute.simd:3848 [F] s_b_44_5 = s_b_44_3+s_b_44_4 (const) */
        uint32_t s_b_44_5 = ((uint32_t)(s_b_44_3 + (uint32_t)12ULL));
        /* execute.simd:3848 [F] s_b_44_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_44_7 = (u32)s_b_44_6 (const) */
        /* execute.simd:3848 [F] s_b_44_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_44_9 = s_b_44_7*s_b_44_8 (const) */
        uint32_t s_b_44_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_44_10 = sym_35686_0_rm uint8_t */
        auto s_b_44_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_44_11 = (u32)s_b_44_10 */
        auto s_b_44_11 = emitter.zx(s_b_44_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_44_12 = s_b_44_9+s_b_44_11 */
        auto s_b_44_12 = emitter.add(emitter.const_u32(s_b_44_9), s_b_44_11);
        /* execute.simd:3848 [D] s_b_44_13 = ReadRegBank 23:s_b_44_12 (u8) */
        captive::arch::dbt::el::Value *s_b_44_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_44_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_44_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_44_14: WriteRegBank 23:s_b_44_5 = s_b_44_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_44_5))),s_b_44_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_44_5))),s_b_44_13);
        /* execute.simd:3848 [F] s_b_44_15: Jump b_45 (const) */
        {
          auto block = block_b_45;
          dynamic_block_queue.push(block_b_45);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_45) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_45);
        /* execute.simd:3845 [F] s_b_45_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_45_1 = (u32)s_b_45_0 (const) */
        /* execute.simd:3845 [F] s_b_45_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_45_3 = s_b_45_1*s_b_45_2 (const) */
        uint32_t s_b_45_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_45_4 = constant u32 d (const) */
        /* execute.simd:3845 [F] s_b_45_5 = s_b_45_3+s_b_45_4 (const) */
        uint32_t s_b_45_5 = ((uint32_t)(s_b_45_3 + (uint32_t)13ULL));
        /* execute.simd:3845 [D] s_b_45_6 = ReadRegBank 23:s_b_45_5 (u8) */
        auto s_b_45_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_45_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_45_5))),s_b_45_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_45_7: sym_35686_0_rm = s_b_45_6, dominates: s_b_46_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_45_6);
        /* execute.simd:3847 [F] s_b_45_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_45_9 = (u32)s_b_45_8 (const) */
        /* execute.simd:3847 [F] s_b_45_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_45_11 = s_b_45_9+s_b_45_10 (const) */
        uint32_t s_b_45_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_45_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_45_13 = s_b_45_12*s_b_45_11 (const) */
        uint32_t s_b_45_13 = ((uint32_t)((uint32_t)16ULL * s_b_45_11));
        /* execute.simd:3847 [D] s_b_45_14 = (u32)s_b_45_6 */
        auto s_b_45_14 = emitter.zx(s_b_45_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_45_15 = s_b_45_14<s_b_45_13 */
        auto s_b_45_15 = emitter.cmp_lt(s_b_45_14, emitter.const_u32(s_b_45_13));
        /* execute.simd:3847 [D] s_b_45_16: If s_b_45_15: Jump b_46 else b_47 */
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
        /* execute.simd:3848 [F] s_b_46_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_46_1 = (u32)s_b_46_0 (const) */
        /* execute.simd:3848 [F] s_b_46_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_46_3 = s_b_46_1*s_b_46_2 (const) */
        uint32_t s_b_46_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_46_4 = constant u32 d (const) */
        /* execute.simd:3848 [F] s_b_46_5 = s_b_46_3+s_b_46_4 (const) */
        uint32_t s_b_46_5 = ((uint32_t)(s_b_46_3 + (uint32_t)13ULL));
        /* execute.simd:3848 [F] s_b_46_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_46_7 = (u32)s_b_46_6 (const) */
        /* execute.simd:3848 [F] s_b_46_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_46_9 = s_b_46_7*s_b_46_8 (const) */
        uint32_t s_b_46_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_46_10 = sym_35686_0_rm uint8_t */
        auto s_b_46_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_46_11 = (u32)s_b_46_10 */
        auto s_b_46_11 = emitter.zx(s_b_46_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_46_12 = s_b_46_9+s_b_46_11 */
        auto s_b_46_12 = emitter.add(emitter.const_u32(s_b_46_9), s_b_46_11);
        /* execute.simd:3848 [D] s_b_46_13 = ReadRegBank 23:s_b_46_12 (u8) */
        captive::arch::dbt::el::Value *s_b_46_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_46_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_46_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_46_14: WriteRegBank 23:s_b_46_5 = s_b_46_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_46_5))),s_b_46_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_46_5))),s_b_46_13);
        /* execute.simd:3848 [F] s_b_46_15: Jump b_47 (const) */
        {
          auto block = block_b_47;
          dynamic_block_queue.push(block_b_47);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_47) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_47);
        /* execute.simd:3845 [F] s_b_47_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_47_1 = (u32)s_b_47_0 (const) */
        /* execute.simd:3845 [F] s_b_47_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_47_3 = s_b_47_1*s_b_47_2 (const) */
        uint32_t s_b_47_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_47_4 = constant u32 e (const) */
        /* execute.simd:3845 [F] s_b_47_5 = s_b_47_3+s_b_47_4 (const) */
        uint32_t s_b_47_5 = ((uint32_t)(s_b_47_3 + (uint32_t)14ULL));
        /* execute.simd:3845 [D] s_b_47_6 = ReadRegBank 23:s_b_47_5 (u8) */
        auto s_b_47_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_47_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_47_5))),s_b_47_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_47_7: sym_35686_0_rm = s_b_47_6, dominates: s_b_48_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_47_6);
        /* execute.simd:3847 [F] s_b_47_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_47_9 = (u32)s_b_47_8 (const) */
        /* execute.simd:3847 [F] s_b_47_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_47_11 = s_b_47_9+s_b_47_10 (const) */
        uint32_t s_b_47_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_47_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_47_13 = s_b_47_12*s_b_47_11 (const) */
        uint32_t s_b_47_13 = ((uint32_t)((uint32_t)16ULL * s_b_47_11));
        /* execute.simd:3847 [D] s_b_47_14 = (u32)s_b_47_6 */
        auto s_b_47_14 = emitter.zx(s_b_47_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_47_15 = s_b_47_14<s_b_47_13 */
        auto s_b_47_15 = emitter.cmp_lt(s_b_47_14, emitter.const_u32(s_b_47_13));
        /* execute.simd:3847 [D] s_b_47_16: If s_b_47_15: Jump b_48 else b_49 */
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
        /* execute.simd:3848 [F] s_b_48_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_48_1 = (u32)s_b_48_0 (const) */
        /* execute.simd:3848 [F] s_b_48_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_48_3 = s_b_48_1*s_b_48_2 (const) */
        uint32_t s_b_48_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_48_4 = constant u32 e (const) */
        /* execute.simd:3848 [F] s_b_48_5 = s_b_48_3+s_b_48_4 (const) */
        uint32_t s_b_48_5 = ((uint32_t)(s_b_48_3 + (uint32_t)14ULL));
        /* execute.simd:3848 [F] s_b_48_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_48_7 = (u32)s_b_48_6 (const) */
        /* execute.simd:3848 [F] s_b_48_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_48_9 = s_b_48_7*s_b_48_8 (const) */
        uint32_t s_b_48_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_48_10 = sym_35686_0_rm uint8_t */
        auto s_b_48_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_48_11 = (u32)s_b_48_10 */
        auto s_b_48_11 = emitter.zx(s_b_48_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_48_12 = s_b_48_9+s_b_48_11 */
        auto s_b_48_12 = emitter.add(emitter.const_u32(s_b_48_9), s_b_48_11);
        /* execute.simd:3848 [D] s_b_48_13 = ReadRegBank 23:s_b_48_12 (u8) */
        captive::arch::dbt::el::Value *s_b_48_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_48_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_48_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_48_14: WriteRegBank 23:s_b_48_5 = s_b_48_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_48_5))),s_b_48_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_48_5))),s_b_48_13);
        /* execute.simd:3848 [F] s_b_48_15: Jump b_49 (const) */
        {
          auto block = block_b_49;
          dynamic_block_queue.push(block_b_49);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_49) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_49);
        /* execute.simd:3845 [F] s_b_49_0=sym_35278_3_parameter_inst.rm (const) */
        /* execute.simd:3845 [F] s_b_49_1 = (u32)s_b_49_0 (const) */
        /* execute.simd:3845 [F] s_b_49_2 = constant u32 10 (const) */
        /* execute.simd:3845 [F] s_b_49_3 = s_b_49_1*s_b_49_2 (const) */
        uint32_t s_b_49_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3845 [F] s_b_49_4 = constant u32 f (const) */
        /* execute.simd:3845 [F] s_b_49_5 = s_b_49_3+s_b_49_4 (const) */
        uint32_t s_b_49_5 = ((uint32_t)(s_b_49_3 + (uint32_t)15ULL));
        /* execute.simd:3845 [D] s_b_49_6 = ReadRegBank 23:s_b_49_5 (u8) */
        auto s_b_49_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_49_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_49_5))),s_b_49_6,emitter.const_u8(1));
        }
        /* execute.simd:3845 [D] s_b_49_7: sym_35686_0_rm = s_b_49_6, dominates: s_b_50_10  */
        emitter.store_local(DV_sym_35686_0_rm, s_b_49_6);
        /* execute.simd:3847 [F] s_b_49_8=sym_35278_3_parameter_inst.len (const) */
        /* execute.simd:3847 [F] s_b_49_9 = (u32)s_b_49_8 (const) */
        /* execute.simd:3847 [F] s_b_49_10 = constant u32 1 (const) */
        /* execute.simd:3847 [F] s_b_49_11 = s_b_49_9+s_b_49_10 (const) */
        uint32_t s_b_49_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3847 [F] s_b_49_12 = constant u32 10 (const) */
        /* execute.simd:3847 [F] s_b_49_13 = s_b_49_12*s_b_49_11 (const) */
        uint32_t s_b_49_13 = ((uint32_t)((uint32_t)16ULL * s_b_49_11));
        /* execute.simd:3847 [D] s_b_49_14 = (u32)s_b_49_6 */
        auto s_b_49_14 = emitter.zx(s_b_49_6, emitter.context().types().u32());
        /* execute.simd:3847 [D] s_b_49_15 = s_b_49_14<s_b_49_13 */
        auto s_b_49_15 = emitter.cmp_lt(s_b_49_14, emitter.const_u32(s_b_49_13));
        /* execute.simd:3847 [D] s_b_49_16: If s_b_49_15: Jump b_50 else b_2 */
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
        /* execute.simd:3848 [F] s_b_50_0=sym_35278_3_parameter_inst.rd (const) */
        /* execute.simd:3848 [F] s_b_50_1 = (u32)s_b_50_0 (const) */
        /* execute.simd:3848 [F] s_b_50_2 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_50_3 = s_b_50_1*s_b_50_2 (const) */
        uint32_t s_b_50_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3848 [F] s_b_50_4 = constant u32 f (const) */
        /* execute.simd:3848 [F] s_b_50_5 = s_b_50_3+s_b_50_4 (const) */
        uint32_t s_b_50_5 = ((uint32_t)(s_b_50_3 + (uint32_t)15ULL));
        /* execute.simd:3848 [F] s_b_50_6=sym_35278_3_parameter_inst.rn (const) */
        /* execute.simd:3848 [F] s_b_50_7 = (u32)s_b_50_6 (const) */
        /* execute.simd:3848 [F] s_b_50_8 = constant u32 10 (const) */
        /* execute.simd:3848 [F] s_b_50_9 = s_b_50_7*s_b_50_8 (const) */
        uint32_t s_b_50_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3848 [D] s_b_50_10 = sym_35686_0_rm uint8_t */
        auto s_b_50_10 = emitter.load_local(DV_sym_35686_0_rm, emitter.context().types().u8());
        /* execute.simd:3848 [D] s_b_50_11 = (u32)s_b_50_10 */
        auto s_b_50_11 = emitter.zx(s_b_50_10, emitter.context().types().u32());
        /* execute.simd:3848 [D] s_b_50_12 = s_b_50_9+s_b_50_11 */
        auto s_b_50_12 = emitter.add(emitter.const_u32(s_b_50_9), s_b_50_11);
        /* execute.simd:3848 [D] s_b_50_13 = ReadRegBank 23:s_b_50_12 (u8) */
        captive::arch::dbt::el::Value *s_b_50_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_50_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_50_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3848 [D] s_b_50_14: WriteRegBank 23:s_b_50_5 = s_b_50_13 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_50_5))),s_b_50_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_50_5))),s_b_50_13);
        /* execute.simd:3848 [F] s_b_50_15: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ucvtf(const arm64_decode_a64_CVT_FP_I&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_156594_1_temporary_value;
  auto DV_sym_156594_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_156404_1_temporary_value;
  auto DV_sym_156404_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_156526_1_temporary_value;
  auto DV_sym_156526_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_156472_1_temporary_value;
  auto DV_sym_156472_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4425 [F] s_b_0_0=sym_39740_3_parameter_inst.sf (const) */
    /* execute.simd:4425 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4425 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4425 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4425 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4426 [F] s_b_1_0=sym_39740_3_parameter_inst.type (const) */
    /* execute.simd:4426 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4426 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4426 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4426 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4433 [F] s_b_3_0=sym_39740_3_parameter_inst.sf (const) */
    /* execute.simd:4433 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4433 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4433 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4433 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_2 (const) */
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
    /* execute.simd:4428 [F] s_b_4_0=sym_39740_3_parameter_inst.rn (const) */
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
    /* execute.simd:4429 [F] s_b_5_0=sym_39740_3_parameter_inst.type (const) */
    /* execute.simd:4429 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4429 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4429 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4429 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_2 (const) */
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
    /* execute.simd:4431 [F] s_b_6_0=sym_39740_3_parameter_inst.rn (const) */
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
    /* execute.simd:4434 [F] s_b_7_0=sym_39740_3_parameter_inst.type (const) */
    /* execute.simd:4434 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4434 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4434 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4434 [F] s_b_7_4: If s_b_7_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4436 [F] s_b_8_0=sym_39740_3_parameter_inst.rn (const) */
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
    /* execute.simd:4437 [F] s_b_9_0=sym_39740_3_parameter_inst.type (const) */
    /* execute.simd:4437 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4437 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4437 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* execute.simd:4437 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_2 (const) */
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
    /* execute.simd:4439 [F] s_b_10_0=sym_39740_3_parameter_inst.rn (const) */
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
    /* execute.a64:2709 [F] s_b_11_1: sym_156404_1_temporary_value = s_b_11_0 (const), dominates: s_b_13_0  */
    CV_sym_156404_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_156404_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_11_2: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0=sym_39740_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_12_1 = ReadRegBank 1:s_b_12_0 (u32) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_12_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_12_2: sym_156404_1_temporary_value = s_b_12_1, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_156404_1_temporary_value, s_b_12_1);
    /* execute.a64:2709 [F] s_b_12_3: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_11, b_12,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [D] s_b_13_0 = sym_156404_1_temporary_value uint32_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_156404_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_13_1 = (u64)s_b_13_0 */
    auto s_b_13_1 = emitter.zx(s_b_13_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_13_2=sym_39740_3_parameter_inst.rd (const) */
    /* execute.simd:4428 [D] s_b_13_3 = (u32)s_b_13_1 */
    auto s_b_13_3 = emitter.truncate(s_b_13_1, emitter.context().types().u32());
    /* execute.simd:4428 [D] s_b_13_4 = (f32)s_b_13_3 */
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
    /* execute.a64:2709 [F] s_b_14_1: sym_156472_1_temporary_value = s_b_14_0 (const), dominates: s_b_16_0  */
    CV_sym_156472_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_156472_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_14_2: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2709 [F] s_b_15_0=sym_39740_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_15_1 = ReadRegBank 1:s_b_15_0 (u32) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_15_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_15_2: sym_156472_1_temporary_value = s_b_15_1, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_156472_1_temporary_value, s_b_15_1);
    /* execute.a64:2709 [F] s_b_15_3: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_14, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [D] s_b_16_0 = sym_156472_1_temporary_value uint32_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_156472_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_16_1 = (u64)s_b_16_0 */
    auto s_b_16_1 = emitter.zx(s_b_16_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_16_2=sym_39740_3_parameter_inst.rd (const) */
    /* execute.simd:4431 [D] s_b_16_3 = (u32)s_b_16_1 */
    auto s_b_16_3 = emitter.truncate(s_b_16_1, emitter.context().types().u32());
    /* execute.simd:4431 [D] s_b_16_4 = (f64)s_b_16_3 */
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
    /* execute.a64:2714 [F] s_b_17_1: sym_156526_1_temporary_value = s_b_17_0 (const), dominates: s_b_19_0  */
    CV_sym_156526_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_156526_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_17_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_8,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2714 [F] s_b_18_0=sym_39740_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_18_2: sym_156526_1_temporary_value = s_b_18_1, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_156526_1_temporary_value, s_b_18_1);
    /* execute.a64:2714 [F] s_b_18_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_17, b_18,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2714 [D] s_b_19_0 = sym_156526_1_temporary_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_156526_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1=sym_39740_3_parameter_inst.rd (const) */
    /* execute.simd:4436 [D] s_b_19_2 = (u64)s_b_19_0 */
    auto s_b_19_2 = (captive::arch::dbt::el::Value *)s_b_19_0;
    /* execute.simd:4436 [D] s_b_19_3 = (f32)s_b_19_2 */
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
    /* execute.a64:2714 [F] s_b_20_1: sym_156594_1_temporary_value = s_b_20_0 (const), dominates: s_b_22_0  */
    CV_sym_156594_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_156594_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_10,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2714 [F] s_b_21_0=sym_39740_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_21_1 = ReadRegBank 0:s_b_21_0 (u64) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_21_2: sym_156594_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_156594_1_temporary_value, s_b_21_1);
    /* execute.a64:2714 [F] s_b_21_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2714 [D] s_b_22_0 = sym_156594_1_temporary_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_156594_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_22_1=sym_39740_3_parameter_inst.rd (const) */
    /* execute.simd:4439 [D] s_b_22_2 = (u64)s_b_22_0 */
    auto s_b_22_2 = (captive::arch::dbt::el::Value *)s_b_22_0;
    /* execute.simd:4439 [D] s_b_22_3 = (f64)s_b_22_2 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_umsubl(const arm64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint32_t CV_sym_157711_1_temporary_value;
  auto DV_sym_157711_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_157776_1_temporary_value;
  auto DV_sym_157776_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_157830_1_temporary_value;
  auto DV_sym_157830_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_157917_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_157805_1_tmp_s_b_11_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_157876_1_tmp_s_b_22_1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_157873_1_tmp_s_b_22_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2476 [F] s_b_0_0=sym_41090_3_parameter_inst.rn (const) */
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
    /* execute.a64:2709 [F] s_b_1_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_1_1: sym_157711_1_temporary_value = s_b_1_0 (const), dominates: s_b_3_0  */
    CV_sym_157711_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_157711_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_1_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2709 [F] s_b_2_0=sym_41090_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_2_1 = ReadRegBank 1:s_b_2_0 (u32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_2_2: sym_157711_1_temporary_value = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_157711_1_temporary_value, s_b_2_1);
    /* execute.a64:2709 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2709 [D] s_b_3_0 = sym_157711_1_temporary_value uint32_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_157711_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_3_1 = (u64)s_b_3_0 */
    auto s_b_3_1 = emitter.zx(s_b_3_0, emitter.context().types().u64());
    /* execute.a64:2477 [F] s_b_3_2=sym_41090_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_3_3: sym_157805_1_tmp_s_b_11_0 = s_b_3_1, dominates: s_b_6_2  */
    emitter.store_local(DV_sym_157805_1_tmp_s_b_11_0, s_b_3_1);
    /* execute.a64:2709 [F] s_b_3_4 = (u32)s_b_3_2 (const) */
    /* execute.a64:2709 [F] s_b_3_5 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_3_7: If s_b_3_6: Jump b_4 else b_5 (const) */
    if (s_b_3_6) 
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
    /* execute.a64:2709 [F] s_b_4_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_4_1: sym_157776_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_157776_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_157776_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2709 [F] s_b_5_0=sym_41090_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_5_1 = ReadRegBank 1:s_b_5_0 (u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_5_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_5_2: sym_157776_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_157776_1_temporary_value, s_b_5_1);
    /* execute.a64:2709 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2709 [D] s_b_6_0 = sym_157776_1_temporary_value uint32_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_157776_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_6_1 = (u64)s_b_6_0 */
    auto s_b_6_1 = emitter.zx(s_b_6_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_2 = sym_157805_1_tmp_s_b_11_0 uint64_t */
    auto s_b_6_2 = emitter.load_local(DV_sym_157805_1_tmp_s_b_11_0, emitter.context().types().u64());
    /* execute.a64:2478 [F] s_b_6_3=sym_41090_3_parameter_inst.ra (const) */
    /* ???:4294967295 [D] s_b_6_4: sym_157873_1_tmp_s_b_22_0 = s_b_6_2, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_157873_1_tmp_s_b_22_0, s_b_6_2);
    /* ???:4294967295 [D] s_b_6_5: sym_157876_1_tmp_s_b_22_1 = s_b_6_1, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_157876_1_tmp_s_b_22_1, s_b_6_1);
    /* execute.a64:2714 [F] s_b_6_6 = (u32)s_b_6_3 (const) */
    /* execute.a64:2714 [F] s_b_6_7 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_6_8 = s_b_6_6==s_b_6_7 (const) */
    uint8_t s_b_6_8 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_6_9: If s_b_6_8: Jump b_7 else b_8 (const) */
    if (s_b_6_8) 
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
    /* execute.a64:2714 [F] s_b_7_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_7_1: sym_157830_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_157830_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_157830_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2714 [F] s_b_8_0=sym_41090_3_parameter_inst.ra (const) */
    /* execute.a64:2714 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_8_2: sym_157830_1_temporary_value = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_157830_1_temporary_value, s_b_8_1);
    /* execute.a64:2714 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2714 [D] s_b_9_0 = sym_157830_1_temporary_value uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_157830_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1 = sym_157876_1_tmp_s_b_22_1 uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_157876_1_tmp_s_b_22_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_2 = sym_157873_1_tmp_s_b_22_0 uint64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_157873_1_tmp_s_b_22_0, emitter.context().types().u64());
    /* execute.a64:2480 [D] s_b_9_3 = (u64)s_b_9_0 */
    auto s_b_9_3 = (captive::arch::dbt::el::Value *)s_b_9_0;
    /* execute.a64:2480 [D] s_b_9_4 = (u64)s_b_9_2 */
    auto s_b_9_4 = (captive::arch::dbt::el::Value *)s_b_9_2;
    /* execute.a64:2480 [D] s_b_9_5 = (u64)s_b_9_1 */
    auto s_b_9_5 = (captive::arch::dbt::el::Value *)s_b_9_1;
    /* execute.a64:2480 [D] s_b_9_6 = s_b_9_4*s_b_9_5 */
    auto s_b_9_6 = emitter.mul(s_b_9_4, s_b_9_5);
    /* execute.a64:2480 [D] s_b_9_7 = s_b_9_3-s_b_9_6 */
    auto s_b_9_7 = emitter.sub(s_b_9_3, s_b_9_6);
    /* execute.a64:2754 [F] s_b_9_8=sym_41090_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_9_9: sym_157917_3_parameter_value = s_b_9_7, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_157917_3_parameter_value, s_b_9_7);
    /* execute.a64:2745 [F] s_b_9_10 = (u32)s_b_9_8 (const) */
    /* execute.a64:2745 [F] s_b_9_11 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_9_12 = s_b_9_10==s_b_9_11 (const) */
    uint8_t s_b_9_12 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_9_13: If s_b_9_12: Jump b_10 else b_11 (const) */
    if (s_b_9_12) 
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
    /* execute.a64:2747 [F] s_b_11_0=sym_41090_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_11_1 = sym_157917_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_157917_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_uzp1(const arm64_decode_a64_SIMD_PERMUTE&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5046 [F] s_b_0_0=sym_46618_3_parameter_inst.arrangement (const) */
    /* execute.simd:5047 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5064 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5089 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5102 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5119 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5130 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5143 [F] s_b_0_7 = constant s32 6 (const) */
    /* execute.simd:5046 [F] s_b_0_8: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5048 [F] s_b_2_0=sym_46618_3_parameter_inst.rn (const) */
    /* execute.simd:5048 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5049 [F] s_b_2_2=sym_46618_3_parameter_inst.rm (const) */
    /* execute.simd:5049 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:5052 [F] s_b_2_5 = constant s32 0 (const) */
    /* execute.simd:5052 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5052 [F] s_b_2_7 = constant s32 0 (const) */
    /* execute.simd:5052 [D] s_b_2_8 = s_b_2_4[s_b_2_7] <= s_b_2_6 */
    auto s_b_2_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_2_6);
    /* execute.simd:5053 [F] s_b_2_9 = constant s32 2 (const) */
    /* execute.simd:5053 [D] s_b_2_1[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5053 [F] s_b_2_11 = constant s32 1 (const) */
    /* execute.simd:5053 [D] s_b_2_12 = s_b_2_8[s_b_2_11] <= s_b_2_10 */
    auto s_b_2_12 = emitter.vector_insert(s_b_2_8, emitter.const_s32((int32_t)1ULL), s_b_2_10);
    /* execute.simd:5054 [F] s_b_2_13 = constant s32 4 (const) */
    /* execute.simd:5054 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:5054 [F] s_b_2_15 = constant s32 2 (const) */
    /* execute.simd:5054 [D] s_b_2_16 = s_b_2_12[s_b_2_15] <= s_b_2_14 */
    auto s_b_2_16 = emitter.vector_insert(s_b_2_12, emitter.const_s32((int32_t)2ULL), s_b_2_14);
    /* execute.simd:5055 [F] s_b_2_17 = constant s32 6 (const) */
    /* execute.simd:5055 [D] s_b_2_1[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5055 [F] s_b_2_19 = constant s32 3 (const) */
    /* execute.simd:5055 [D] s_b_2_20 = s_b_2_16[s_b_2_19] <= s_b_2_18 */
    auto s_b_2_20 = emitter.vector_insert(s_b_2_16, emitter.const_s32((int32_t)3ULL), s_b_2_18);
    /* execute.simd:5056 [F] s_b_2_21 = constant s32 0 (const) */
    /* execute.simd:5056 [D] s_b_2_3[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5056 [F] s_b_2_23 = constant s32 4 (const) */
    /* execute.simd:5056 [D] s_b_2_24 = s_b_2_20[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_20, emitter.const_s32((int32_t)4ULL), s_b_2_22);
    /* execute.simd:5057 [F] s_b_2_25 = constant s32 2 (const) */
    /* execute.simd:5057 [D] s_b_2_3[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5057 [F] s_b_2_27 = constant s32 5 (const) */
    /* execute.simd:5057 [D] s_b_2_28 = s_b_2_24[s_b_2_27] <= s_b_2_26 */
    auto s_b_2_28 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)5ULL), s_b_2_26);
    /* execute.simd:5058 [F] s_b_2_29 = constant s32 4 (const) */
    /* execute.simd:5058 [D] s_b_2_3[s_b_2_29] */
    auto s_b_2_30 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:5058 [F] s_b_2_31 = constant s32 6 (const) */
    /* execute.simd:5058 [D] s_b_2_32 = s_b_2_28[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_28, emitter.const_s32((int32_t)6ULL), s_b_2_30);
    /* execute.simd:5059 [F] s_b_2_33 = constant s32 6 (const) */
    /* execute.simd:5059 [D] s_b_2_3[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5059 [F] s_b_2_35 = constant s32 7 (const) */
    /* execute.simd:5059 [D] s_b_2_36 = s_b_2_32[s_b_2_35] <= s_b_2_34 */
    auto s_b_2_36 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)7ULL), s_b_2_34);
    /* execute.simd:5061 [F] s_b_2_37=sym_46618_3_parameter_inst.rd (const) */
    /* execute.simd:5061 [D] s_b_2_38: WriteRegBank 16:s_b_2_37 = s_b_2_36 */
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
    /* execute.simd:5065 [F] s_b_3_0=sym_46618_3_parameter_inst.rn (const) */
    /* execute.simd:5065 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5066 [F] s_b_3_2=sym_46618_3_parameter_inst.rm (const) */
    /* execute.simd:5066 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:5069 [F] s_b_3_5 = constant s32 0 (const) */
    /* execute.simd:5069 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5069 [F] s_b_3_7 = constant s32 0 (const) */
    /* execute.simd:5069 [D] s_b_3_8 = s_b_3_4[s_b_3_7] <= s_b_3_6 */
    auto s_b_3_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_3_6);
    /* execute.simd:5070 [F] s_b_3_9 = constant s32 2 (const) */
    /* execute.simd:5070 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5070 [F] s_b_3_11 = constant s32 1 (const) */
    /* execute.simd:5070 [D] s_b_3_12 = s_b_3_8[s_b_3_11] <= s_b_3_10 */
    auto s_b_3_12 = emitter.vector_insert(s_b_3_8, emitter.const_s32((int32_t)1ULL), s_b_3_10);
    /* execute.simd:5071 [F] s_b_3_13 = constant s32 4 (const) */
    /* execute.simd:5071 [D] s_b_3_1[s_b_3_13] */
    auto s_b_3_14 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:5071 [F] s_b_3_15 = constant s32 2 (const) */
    /* execute.simd:5071 [D] s_b_3_16 = s_b_3_12[s_b_3_15] <= s_b_3_14 */
    auto s_b_3_16 = emitter.vector_insert(s_b_3_12, emitter.const_s32((int32_t)2ULL), s_b_3_14);
    /* execute.simd:5072 [F] s_b_3_17 = constant s32 6 (const) */
    /* execute.simd:5072 [D] s_b_3_1[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5072 [F] s_b_3_19 = constant s32 3 (const) */
    /* execute.simd:5072 [D] s_b_3_20 = s_b_3_16[s_b_3_19] <= s_b_3_18 */
    auto s_b_3_20 = emitter.vector_insert(s_b_3_16, emitter.const_s32((int32_t)3ULL), s_b_3_18);
    /* execute.simd:5073 [F] s_b_3_21 = constant s32 8 (const) */
    /* execute.simd:5073 [D] s_b_3_1[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)8ULL));
    /* execute.simd:5073 [F] s_b_3_23 = constant s32 4 (const) */
    /* execute.simd:5073 [D] s_b_3_24 = s_b_3_20[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_20, emitter.const_s32((int32_t)4ULL), s_b_3_22);
    /* execute.simd:5074 [F] s_b_3_25 = constant s32 a (const) */
    /* execute.simd:5074 [D] s_b_3_1[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)10ULL));
    /* execute.simd:5074 [F] s_b_3_27 = constant s32 5 (const) */
    /* execute.simd:5074 [D] s_b_3_28 = s_b_3_24[s_b_3_27] <= s_b_3_26 */
    auto s_b_3_28 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)5ULL), s_b_3_26);
    /* execute.simd:5075 [F] s_b_3_29 = constant s32 c (const) */
    /* execute.simd:5075 [D] s_b_3_1[s_b_3_29] */
    auto s_b_3_30 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)12ULL));
    /* execute.simd:5075 [F] s_b_3_31 = constant s32 6 (const) */
    /* execute.simd:5075 [D] s_b_3_32 = s_b_3_28[s_b_3_31] <= s_b_3_30 */
    auto s_b_3_32 = emitter.vector_insert(s_b_3_28, emitter.const_s32((int32_t)6ULL), s_b_3_30);
    /* execute.simd:5076 [F] s_b_3_33 = constant s32 e (const) */
    /* execute.simd:5076 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)14ULL));
    /* execute.simd:5076 [F] s_b_3_35 = constant s32 7 (const) */
    /* execute.simd:5076 [D] s_b_3_36 = s_b_3_32[s_b_3_35] <= s_b_3_34 */
    auto s_b_3_36 = emitter.vector_insert(s_b_3_32, emitter.const_s32((int32_t)7ULL), s_b_3_34);
    /* execute.simd:5077 [F] s_b_3_37 = constant s32 0 (const) */
    /* execute.simd:5077 [D] s_b_3_3[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5077 [F] s_b_3_39 = constant s32 8 (const) */
    /* execute.simd:5077 [D] s_b_3_40 = s_b_3_36[s_b_3_39] <= s_b_3_38 */
    auto s_b_3_40 = emitter.vector_insert(s_b_3_36, emitter.const_s32((int32_t)8ULL), s_b_3_38);
    /* execute.simd:5078 [F] s_b_3_41 = constant s32 2 (const) */
    /* execute.simd:5078 [D] s_b_3_3[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5078 [F] s_b_3_43 = constant s32 9 (const) */
    /* execute.simd:5078 [D] s_b_3_44 = s_b_3_40[s_b_3_43] <= s_b_3_42 */
    auto s_b_3_44 = emitter.vector_insert(s_b_3_40, emitter.const_s32((int32_t)9ULL), s_b_3_42);
    /* execute.simd:5079 [F] s_b_3_45 = constant s32 4 (const) */
    /* execute.simd:5079 [D] s_b_3_3[s_b_3_45] */
    auto s_b_3_46 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:5079 [F] s_b_3_47 = constant s32 a (const) */
    /* execute.simd:5079 [D] s_b_3_48 = s_b_3_44[s_b_3_47] <= s_b_3_46 */
    auto s_b_3_48 = emitter.vector_insert(s_b_3_44, emitter.const_s32((int32_t)10ULL), s_b_3_46);
    /* execute.simd:5080 [F] s_b_3_49 = constant s32 6 (const) */
    /* execute.simd:5080 [D] s_b_3_3[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5080 [F] s_b_3_51 = constant s32 b (const) */
    /* execute.simd:5080 [D] s_b_3_52 = s_b_3_48[s_b_3_51] <= s_b_3_50 */
    auto s_b_3_52 = emitter.vector_insert(s_b_3_48, emitter.const_s32((int32_t)11ULL), s_b_3_50);
    /* execute.simd:5081 [F] s_b_3_53 = constant s32 8 (const) */
    /* execute.simd:5081 [D] s_b_3_3[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)8ULL));
    /* execute.simd:5081 [F] s_b_3_55 = constant s32 c (const) */
    /* execute.simd:5081 [D] s_b_3_56 = s_b_3_52[s_b_3_55] <= s_b_3_54 */
    auto s_b_3_56 = emitter.vector_insert(s_b_3_52, emitter.const_s32((int32_t)12ULL), s_b_3_54);
    /* execute.simd:5082 [F] s_b_3_57 = constant s32 a (const) */
    /* execute.simd:5082 [D] s_b_3_3[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)10ULL));
    /* execute.simd:5082 [F] s_b_3_59 = constant s32 d (const) */
    /* execute.simd:5082 [D] s_b_3_60 = s_b_3_56[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_56, emitter.const_s32((int32_t)13ULL), s_b_3_58);
    /* execute.simd:5083 [F] s_b_3_61 = constant s32 c (const) */
    /* execute.simd:5083 [D] s_b_3_3[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)12ULL));
    /* execute.simd:5083 [F] s_b_3_63 = constant s32 e (const) */
    /* execute.simd:5083 [D] s_b_3_64 = s_b_3_60[s_b_3_63] <= s_b_3_62 */
    auto s_b_3_64 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)14ULL), s_b_3_62);
    /* execute.simd:5084 [F] s_b_3_65 = constant s32 e (const) */
    /* execute.simd:5084 [D] s_b_3_3[s_b_3_65] */
    auto s_b_3_66 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)14ULL));
    /* execute.simd:5084 [F] s_b_3_67 = constant s32 f (const) */
    /* execute.simd:5084 [D] s_b_3_68 = s_b_3_64[s_b_3_67] <= s_b_3_66 */
    auto s_b_3_68 = emitter.vector_insert(s_b_3_64, emitter.const_s32((int32_t)15ULL), s_b_3_66);
    /* execute.simd:5086 [F] s_b_3_69=sym_46618_3_parameter_inst.rd (const) */
    /* execute.simd:5086 [D] s_b_3_70: WriteRegBank 16:s_b_3_69 = s_b_3_68 */
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
    /* execute.simd:5090 [F] s_b_4_0=sym_46618_3_parameter_inst.rn (const) */
    /* execute.simd:5090 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5091 [F] s_b_4_2=sym_46618_3_parameter_inst.rm (const) */
    /* execute.simd:5091 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5094 [F] s_b_4_5 = constant s32 0 (const) */
    /* execute.simd:5094 [D] s_b_4_1[s_b_4_5] */
    auto s_b_4_6 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5094 [F] s_b_4_7 = constant s32 0 (const) */
    /* execute.simd:5094 [D] s_b_4_8 = s_b_4_4[s_b_4_7] <= s_b_4_6 */
    auto s_b_4_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_4_6);
    /* execute.simd:5095 [F] s_b_4_9 = constant s32 2 (const) */
    /* execute.simd:5095 [D] s_b_4_1[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5095 [F] s_b_4_11 = constant s32 1 (const) */
    /* execute.simd:5095 [D] s_b_4_12 = s_b_4_8[s_b_4_11] <= s_b_4_10 */
    auto s_b_4_12 = emitter.vector_insert(s_b_4_8, emitter.const_s32((int32_t)1ULL), s_b_4_10);
    /* execute.simd:5096 [F] s_b_4_13 = constant s32 0 (const) */
    /* execute.simd:5096 [D] s_b_4_3[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5096 [F] s_b_4_15 = constant s32 2 (const) */
    /* execute.simd:5096 [D] s_b_4_16 = s_b_4_12[s_b_4_15] <= s_b_4_14 */
    auto s_b_4_16 = emitter.vector_insert(s_b_4_12, emitter.const_s32((int32_t)2ULL), s_b_4_14);
    /* execute.simd:5097 [F] s_b_4_17 = constant s32 2 (const) */
    /* execute.simd:5097 [D] s_b_4_3[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5097 [F] s_b_4_19 = constant s32 3 (const) */
    /* execute.simd:5097 [D] s_b_4_20 = s_b_4_16[s_b_4_19] <= s_b_4_18 */
    auto s_b_4_20 = emitter.vector_insert(s_b_4_16, emitter.const_s32((int32_t)3ULL), s_b_4_18);
    /* execute.simd:5099 [F] s_b_4_21=sym_46618_3_parameter_inst.rd (const) */
    /* execute.simd:5099 [D] s_b_4_22: WriteRegBank 18:s_b_4_21 = s_b_4_20 */
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
    /* execute.simd:5103 [F] s_b_5_0=sym_46618_3_parameter_inst.rn (const) */
    /* execute.simd:5103 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5104 [F] s_b_5_2=sym_46618_3_parameter_inst.rm (const) */
    /* execute.simd:5104 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5107 [F] s_b_5_5 = constant s32 0 (const) */
    /* execute.simd:5107 [D] s_b_5_1[s_b_5_5] */
    auto s_b_5_6 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5107 [F] s_b_5_7 = constant s32 0 (const) */
    /* execute.simd:5107 [D] s_b_5_8 = s_b_5_4[s_b_5_7] <= s_b_5_6 */
    auto s_b_5_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_5_6);
    /* execute.simd:5108 [F] s_b_5_9 = constant s32 2 (const) */
    /* execute.simd:5108 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5108 [F] s_b_5_11 = constant s32 1 (const) */
    /* execute.simd:5108 [D] s_b_5_12 = s_b_5_8[s_b_5_11] <= s_b_5_10 */
    auto s_b_5_12 = emitter.vector_insert(s_b_5_8, emitter.const_s32((int32_t)1ULL), s_b_5_10);
    /* execute.simd:5109 [F] s_b_5_13 = constant s32 4 (const) */
    /* execute.simd:5109 [D] s_b_5_1[s_b_5_13] */
    auto s_b_5_14 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:5109 [F] s_b_5_15 = constant s32 2 (const) */
    /* execute.simd:5109 [D] s_b_5_16 = s_b_5_12[s_b_5_15] <= s_b_5_14 */
    auto s_b_5_16 = emitter.vector_insert(s_b_5_12, emitter.const_s32((int32_t)2ULL), s_b_5_14);
    /* execute.simd:5110 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:5110 [D] s_b_5_1[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5110 [F] s_b_5_19 = constant s32 3 (const) */
    /* execute.simd:5110 [D] s_b_5_20 = s_b_5_16[s_b_5_19] <= s_b_5_18 */
    auto s_b_5_20 = emitter.vector_insert(s_b_5_16, emitter.const_s32((int32_t)3ULL), s_b_5_18);
    /* execute.simd:5111 [F] s_b_5_21 = constant s32 0 (const) */
    /* execute.simd:5111 [D] s_b_5_3[s_b_5_21] */
    auto s_b_5_22 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5111 [F] s_b_5_23 = constant s32 4 (const) */
    /* execute.simd:5111 [D] s_b_5_24 = s_b_5_20[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_20, emitter.const_s32((int32_t)4ULL), s_b_5_22);
    /* execute.simd:5112 [F] s_b_5_25 = constant s32 2 (const) */
    /* execute.simd:5112 [D] s_b_5_3[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5112 [F] s_b_5_27 = constant s32 5 (const) */
    /* execute.simd:5112 [D] s_b_5_28 = s_b_5_24[s_b_5_27] <= s_b_5_26 */
    auto s_b_5_28 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)5ULL), s_b_5_26);
    /* execute.simd:5113 [F] s_b_5_29 = constant s32 4 (const) */
    /* execute.simd:5113 [D] s_b_5_3[s_b_5_29] */
    auto s_b_5_30 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:5113 [F] s_b_5_31 = constant s32 6 (const) */
    /* execute.simd:5113 [D] s_b_5_32 = s_b_5_28[s_b_5_31] <= s_b_5_30 */
    auto s_b_5_32 = emitter.vector_insert(s_b_5_28, emitter.const_s32((int32_t)6ULL), s_b_5_30);
    /* execute.simd:5114 [F] s_b_5_33 = constant s32 6 (const) */
    /* execute.simd:5114 [D] s_b_5_3[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5114 [F] s_b_5_35 = constant s32 7 (const) */
    /* execute.simd:5114 [D] s_b_5_36 = s_b_5_32[s_b_5_35] <= s_b_5_34 */
    auto s_b_5_36 = emitter.vector_insert(s_b_5_32, emitter.const_s32((int32_t)7ULL), s_b_5_34);
    /* execute.simd:5116 [F] s_b_5_37=sym_46618_3_parameter_inst.rd (const) */
    /* execute.simd:5116 [D] s_b_5_38: WriteRegBank 18:s_b_5_37 = s_b_5_36 */
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
    /* execute.simd:5120 [F] s_b_6_0=sym_46618_3_parameter_inst.rn (const) */
    /* execute.simd:5120 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5121 [F] s_b_6_2=sym_46618_3_parameter_inst.rm (const) */
    /* execute.simd:5121 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5124 [F] s_b_6_5 = constant s32 0 (const) */
    /* execute.simd:5124 [D] s_b_6_1[s_b_6_5] */
    auto s_b_6_6 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5124 [F] s_b_6_7 = constant s32 0 (const) */
    /* execute.simd:5124 [D] s_b_6_8 = s_b_6_4[s_b_6_7] <= s_b_6_6 */
    auto s_b_6_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_6_6);
    /* execute.simd:5125 [F] s_b_6_9 = constant s32 0 (const) */
    /* execute.simd:5125 [D] s_b_6_3[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5125 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:5125 [D] s_b_6_12 = s_b_6_8[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_8, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:5127 [F] s_b_6_13=sym_46618_3_parameter_inst.rd (const) */
    /* execute.simd:5127 [D] s_b_6_14: WriteRegBank 20:s_b_6_13 = s_b_6_12 */
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
    /* execute.simd:5131 [F] s_b_7_0=sym_46618_3_parameter_inst.rn (const) */
    /* execute.simd:5131 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5132 [F] s_b_7_2=sym_46618_3_parameter_inst.rm (const) */
    /* execute.simd:5132 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5135 [F] s_b_7_5 = constant s32 0 (const) */
    /* execute.simd:5135 [D] s_b_7_1[s_b_7_5] */
    auto s_b_7_6 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5135 [F] s_b_7_7 = constant s32 0 (const) */
    /* execute.simd:5135 [D] s_b_7_8 = s_b_7_4[s_b_7_7] <= s_b_7_6 */
    auto s_b_7_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_7_6);
    /* execute.simd:5136 [F] s_b_7_9 = constant s32 2 (const) */
    /* execute.simd:5136 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5136 [F] s_b_7_11 = constant s32 1 (const) */
    /* execute.simd:5136 [D] s_b_7_12 = s_b_7_8[s_b_7_11] <= s_b_7_10 */
    auto s_b_7_12 = emitter.vector_insert(s_b_7_8, emitter.const_s32((int32_t)1ULL), s_b_7_10);
    /* execute.simd:5137 [F] s_b_7_13 = constant s32 0 (const) */
    /* execute.simd:5137 [D] s_b_7_3[s_b_7_13] */
    auto s_b_7_14 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5137 [F] s_b_7_15 = constant s32 2 (const) */
    /* execute.simd:5137 [D] s_b_7_16 = s_b_7_12[s_b_7_15] <= s_b_7_14 */
    auto s_b_7_16 = emitter.vector_insert(s_b_7_12, emitter.const_s32((int32_t)2ULL), s_b_7_14);
    /* execute.simd:5138 [F] s_b_7_17 = constant s32 2 (const) */
    /* execute.simd:5138 [D] s_b_7_3[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5138 [F] s_b_7_19 = constant s32 3 (const) */
    /* execute.simd:5138 [D] s_b_7_20 = s_b_7_16[s_b_7_19] <= s_b_7_18 */
    auto s_b_7_20 = emitter.vector_insert(s_b_7_16, emitter.const_s32((int32_t)3ULL), s_b_7_18);
    /* execute.simd:5140 [F] s_b_7_21=sym_46618_3_parameter_inst.rd (const) */
    /* execute.simd:5140 [D] s_b_7_22: WriteRegBank 20:s_b_7_21 = s_b_7_20 */
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
    /* execute.simd:5144 [F] s_b_8_0=sym_46618_3_parameter_inst.rn (const) */
    /* execute.simd:5144 [D] s_b_8_1 = ReadRegBank 21:s_b_8_0 (v2u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* execute.simd:5145 [F] s_b_8_2=sym_46618_3_parameter_inst.rm (const) */
    /* execute.simd:5145 [D] s_b_8_3 = ReadRegBank 21:s_b_8_2 (v2u64) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_4 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5148 [F] s_b_8_5 = constant s32 0 (const) */
    /* execute.simd:5148 [D] s_b_8_1[s_b_8_5] */
    auto s_b_8_6 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5148 [F] s_b_8_7 = constant s32 0 (const) */
    /* execute.simd:5148 [D] s_b_8_8 = s_b_8_4[s_b_8_7] <= s_b_8_6 */
    auto s_b_8_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_8_6);
    /* execute.simd:5149 [F] s_b_8_9 = constant s32 0 (const) */
    /* execute.simd:5149 [D] s_b_8_3[s_b_8_9] */
    auto s_b_8_10 = emitter.vector_extract(s_b_8_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5149 [F] s_b_8_11 = constant s32 1 (const) */
    /* execute.simd:5149 [D] s_b_8_12 = s_b_8_8[s_b_8_11] <= s_b_8_10 */
    auto s_b_8_12 = emitter.vector_insert(s_b_8_8, emitter.const_s32((int32_t)1ULL), s_b_8_10);
    /* execute.simd:5151 [F] s_b_8_13=sym_46618_3_parameter_inst.rd (const) */
    /* execute.simd:5151 [D] s_b_8_14: WriteRegBank 21:s_b_8_13 = s_b_8_12 */
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
template class arm64_jit2<true>;
template class arm64_jit2<false>;
