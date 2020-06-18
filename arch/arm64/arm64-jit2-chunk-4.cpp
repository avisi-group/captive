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
    /* execute.simd:6237 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:835 [F] s_b_1_2=sym_3448_3_parameter_inst.rm (const) */
    /* execute.simd:6237 [D] s_b_1_3 = ReadRegBank 7:s_b_1_2 (u64) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(8));
    }
    /* execute.simd:837 [F] s_b_1_4=sym_3448_3_parameter_inst.rd (const) */
    /* execute.simd:837 [D] s_b_1_5 = s_b_1_1+s_b_1_3 */
    auto s_b_1_5 = emitter.add(s_b_1_1, s_b_1_3);
    /* execute.simd:6208 [D] s_b_1_6: WriteRegBank 2:s_b_1_4 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6209 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_1_8: WriteRegBank 3:s_b_1_4 = s_b_1_7 */
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
    case (int32_t)4ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_5;
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
  auto DV_sym_51792_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51770_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_51380_1_temporary_value;
  auto DV_sym_51380_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_51368_1_temporary_value;
  auto DV_sym_51368_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_51394_1__R_s_b_26_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_51335_1__R_s_b_25_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_5882_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51310_1__R_s_b_24_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_51741_1_temporary_value;
  auto DV_sym_51741_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_51265_1_tmp_s_b_9_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51285_1__R_s_b_21_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_51120_1_temporary_value;
  auto DV_sym_51120_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_51247_1__R_s_b_9_9;
  auto DV_sym_51247_1__R_s_b_9_9 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51460_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_51148_1_temporary_value;
  auto DV_sym_51148_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_51489_1_temporary_value;
  auto DV_sym_51489_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_51629_1_temporary_value;
  auto DV_sym_51629_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_51545_1_temporary_value;
  auto DV_sym_51545_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_51657_1_temporary_value;
  auto DV_sym_51657_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51101_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_51601_1_temporary_value;
  auto DV_sym_51601_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_51517_1_temporary_value;
  auto DV_sym_51517_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_51573_1_temporary_value;
  auto DV_sym_51573_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
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
    /* execute.a64:2497 [D] s_b_8_0 = sym_51101_1__R_s_b_0_4 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_51101_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2498 [F] s_b_8_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* ???:4294967295 [D] s_b_8_2: sym_51265_1_tmp_s_b_9_0 = s_b_8_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_51265_1_tmp_s_b_9_0, s_b_8_0);
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
    /* execute.a64:2714 [F] s_b_9_1: sym_51120_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_51120_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51120_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_10_2: sym_51120_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_51120_1_temporary_value, s_b_10_1);
    /* execute.a64:2714 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2714 [D] s_b_11_0 = sym_51120_1_temporary_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_51120_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_11_1: sym_51101_1__R_s_b_0_4 = s_b_11_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_51101_1__R_s_b_0_4, s_b_11_0);
    /* execute.a64:2720 [F] s_b_11_2: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_12_1: sym_51148_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_51148_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51148_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_13_2: sym_51148_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_51148_1_temporary_value, s_b_13_1);
    /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_51148_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_51148_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_14_2: sym_51101_1__R_s_b_0_4 = s_b_14_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_51101_1__R_s_b_0_4, s_b_14_1);
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
    /* execute.a64:2637 [F] s_b_16_5: Switch s_b_16_0: < <todo> > def b_17 (const) -> b_17, b_19, b_21, b_20, b_18,  */
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
    /* execute.a64:2661 [F] s_b_17_2: sym_51247_1__R_s_b_9_9 = s_b_17_1 (const), dominates: s_b_24_1  */
    CV_sym_51247_1__R_s_b_9_9 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51247_1__R_s_b_9_9, emitter.const_u64((uint64_t)0ULL));
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
    /* ???:4294967295 [D] s_b_24_0 = sym_51265_1_tmp_s_b_9_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_51265_1_tmp_s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2498 [D] s_b_24_1 = sym_51247_1__R_s_b_9_9 uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_51247_1__R_s_b_9_9, emitter.context().types().u64());
    /* execute.a64:2500 [D] s_b_24_2 = s_b_24_0&s_b_24_1 */
    auto s_b_24_2 = emitter.bitwise_and(s_b_24_0, s_b_24_1);
    /* execute.a64:2500 [D] s_b_24_3: sym_5882_0_result = s_b_24_2, dominates: s_b_3_0 s_b_5_0  */
    emitter.store_local(DV_sym_5882_0_result, s_b_24_2);
    /* execute.a64:2501 [F] s_b_24_4=sym_5865_3_parameter_inst.sf (const) */
    /* execute.a64:2501 [D] s_b_24_5: sym_51460_3_parameter_value = s_b_24_2, dominates: s_b_43_1 s_b_44_1  */
    emitter.store_local(DV_sym_51460_3_parameter_value, s_b_24_2);
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
    /* execute.a64:2635 [D] s_b_27_0 = sym_51285_1__R_s_b_21_4 uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_51285_1__R_s_b_21_4, emitter.context().types().u64());
    /* execute.a64:2635 [D] s_b_27_1: sym_51247_1__R_s_b_9_9 = s_b_27_0, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51247_1__R_s_b_9_9, s_b_27_0);
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
    /* execute.a64:2640 [D] s_b_30_0 = sym_51310_1__R_s_b_24_4 uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_51310_1__R_s_b_24_4, emitter.context().types().u64());
    /* execute.a64:2640 [F] s_b_30_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2640 [F] s_b_30_2 = (u64)s_b_30_1 (const) */
    /* execute.a64:2640 [D] s_b_30_3 = s_b_30_0<<s_b_30_2 */
    auto s_b_30_3 = emitter.shl(s_b_30_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2640 [D] s_b_30_4: sym_51247_1__R_s_b_9_9 = s_b_30_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51247_1__R_s_b_9_9, s_b_30_3);
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
    /* execute.a64:2644 [D] s_b_33_0 = sym_51335_1__R_s_b_25_4 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_51335_1__R_s_b_25_4, emitter.context().types().u64());
    /* execute.a64:2644 [F] s_b_33_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2644 [F] s_b_33_2 = (u64)s_b_33_1 (const) */
    /* execute.a64:2644 [D] s_b_33_3 = s_b_33_0>>s_b_33_2 */
    auto s_b_33_3 = emitter.shr(s_b_33_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2644 [D] s_b_33_4: sym_51247_1__R_s_b_9_9 = s_b_33_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51247_1__R_s_b_9_9, s_b_33_3);
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
    /* execute.a64:2729 [F] s_b_36_1: sym_51368_1_temporary_value = s_b_36_0 (const), dominates: s_b_40_0  */
    CV_sym_51368_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_51368_1_temporary_value, emitter.const_s64((int64_t)0ULL));
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
    /* execute.a64:2729 [D] s_b_37_3: sym_51368_1_temporary_value = s_b_37_2, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_51368_1_temporary_value, s_b_37_2);
    /* execute.a64:2729 [F] s_b_37_4: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_35,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2731 [F] s_b_38_0 = constant s64 0 (const) */
    /* execute.a64:2731 [F] s_b_38_1: sym_51380_1_temporary_value = s_b_38_0 (const), dominates: s_b_41_0  */
    CV_sym_51380_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_51380_1_temporary_value, emitter.const_s64((int64_t)0ULL));
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
    /* execute.a64:2731 [D] s_b_39_4: sym_51380_1_temporary_value = s_b_39_3, dominates: s_b_41_0  */
    emitter.store_local(DV_sym_51380_1_temporary_value, s_b_39_3);
    /* execute.a64:2731 [F] s_b_39_5: Jump b_41 (const) */
    goto fixed_block_b_41;
  }
  /* b_36, b_37,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2729 [D] s_b_40_0 = sym_51368_1_temporary_value int64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_51368_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_40_1: sym_51394_1__R_s_b_26_4 = s_b_40_0, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_51394_1__R_s_b_26_4, s_b_40_0);
    /* execute.a64:2729 [F] s_b_40_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_38, b_39,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2731 [D] s_b_41_0 = sym_51380_1_temporary_value int64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_51380_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_41_1: sym_51394_1__R_s_b_26_4 = s_b_41_0, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_51394_1__R_s_b_26_4, s_b_41_0);
    /* execute.a64:2731 [F] s_b_41_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_40, b_41,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2648 [D] s_b_42_0 = sym_51394_1__R_s_b_26_4 int64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_51394_1__R_s_b_26_4, emitter.context().types().s64());
    /* execute.a64:2648 [F] s_b_42_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2648 [D] s_b_42_2 = (u64)s_b_42_0 */
    auto s_b_42_2 = emitter.reinterpret(s_b_42_0, emitter.context().types().u64());
    /* execute.a64:2648 [F] s_b_42_3 = (u64)s_b_42_1 (const) */
    /* execute.a64:2648 [D] s_b_42_4 = s_b_42_2->>s_b_42_3 */
    auto s_b_42_4 = emitter.sar(s_b_42_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2648 [D] s_b_42_5 = (u64)s_b_42_4 */
    auto s_b_42_5 = (captive::arch::dbt::el::Value *)s_b_42_4;
    /* execute.a64:2648 [D] s_b_42_6: sym_51247_1__R_s_b_9_9 = s_b_42_5, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51247_1__R_s_b_9_9, s_b_42_5);
    /* execute.a64:2648 [F] s_b_42_7: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_24,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2754 [F] s_b_43_0=sym_5865_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_43_1 = sym_51460_3_parameter_value uint64_t */
    auto s_b_43_1 = emitter.load_local(DV_sym_51460_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_43_2: sym_51770_3_parameter_value = s_b_43_1, dominates: s_b_70_1  */
    emitter.store_local(DV_sym_51770_3_parameter_value, s_b_43_1);
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
    /* execute.a64:2756 [D] s_b_44_1 = sym_51460_3_parameter_value uint64_t */
    auto s_b_44_1 = emitter.load_local(DV_sym_51460_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_44_2 = (u32)s_b_44_1 */
    auto s_b_44_2 = emitter.truncate(s_b_44_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_44_3 = (u64)s_b_44_2 */
    auto s_b_44_3 = emitter.zx(s_b_44_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_44_4: sym_51792_3_parameter_value = s_b_44_3, dominates: s_b_71_1  */
    emitter.store_local(DV_sym_51792_3_parameter_value, s_b_44_3);
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
    /* execute.a64:2714 [F] s_b_46_1: sym_51489_1_temporary_value = s_b_46_0 (const), dominates: s_b_48_0  */
    CV_sym_51489_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51489_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_47_2: sym_51489_1_temporary_value = s_b_47_1, dominates: s_b_48_0  */
    emitter.store_local(DV_sym_51489_1_temporary_value, s_b_47_1);
    /* execute.a64:2714 [F] s_b_47_3: Jump b_48 (const) */
    goto fixed_block_b_48;
  }
  /* b_46, b_47,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2714 [D] s_b_48_0 = sym_51489_1_temporary_value uint64_t */
    auto s_b_48_0 = emitter.load_local(DV_sym_51489_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_48_1: sym_51285_1__R_s_b_21_4 = s_b_48_0, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_51285_1__R_s_b_21_4, s_b_48_0);
    /* execute.a64:2720 [F] s_b_48_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_26,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2709 [F] s_b_49_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_49_1: sym_51517_1_temporary_value = s_b_49_0 (const), dominates: s_b_51_0  */
    CV_sym_51517_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51517_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_50_2: sym_51517_1_temporary_value = s_b_50_1, dominates: s_b_51_0  */
    emitter.store_local(DV_sym_51517_1_temporary_value, s_b_50_1);
    /* execute.a64:2709 [F] s_b_50_3: Jump b_51 (const) */
    goto fixed_block_b_51;
  }
  /* b_49, b_50,  */
  fixed_block_b_51: 
  {
    /* execute.a64:2709 [D] s_b_51_0 = sym_51517_1_temporary_value uint32_t */
    auto s_b_51_0 = emitter.load_local(DV_sym_51517_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_51_1 = (u64)s_b_51_0 */
    auto s_b_51_1 = emitter.zx(s_b_51_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_51_2: sym_51285_1__R_s_b_21_4 = s_b_51_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_51285_1__R_s_b_21_4, s_b_51_1);
    /* execute.a64:2722 [F] s_b_51_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_28,  */
  fixed_block_b_52: 
  {
    /* execute.a64:2714 [F] s_b_52_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_52_1: sym_51545_1_temporary_value = s_b_52_0 (const), dominates: s_b_54_0  */
    CV_sym_51545_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51545_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_53_2: sym_51545_1_temporary_value = s_b_53_1, dominates: s_b_54_0  */
    emitter.store_local(DV_sym_51545_1_temporary_value, s_b_53_1);
    /* execute.a64:2714 [F] s_b_53_3: Jump b_54 (const) */
    goto fixed_block_b_54;
  }
  /* b_52, b_53,  */
  fixed_block_b_54: 
  {
    /* execute.a64:2714 [D] s_b_54_0 = sym_51545_1_temporary_value uint64_t */
    auto s_b_54_0 = emitter.load_local(DV_sym_51545_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_54_1: sym_51310_1__R_s_b_24_4 = s_b_54_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_51310_1__R_s_b_24_4, s_b_54_0);
    /* execute.a64:2720 [F] s_b_54_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_29,  */
  fixed_block_b_55: 
  {
    /* execute.a64:2709 [F] s_b_55_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_55_1: sym_51573_1_temporary_value = s_b_55_0 (const), dominates: s_b_57_0  */
    CV_sym_51573_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51573_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_56_2: sym_51573_1_temporary_value = s_b_56_1, dominates: s_b_57_0  */
    emitter.store_local(DV_sym_51573_1_temporary_value, s_b_56_1);
    /* execute.a64:2709 [F] s_b_56_3: Jump b_57 (const) */
    goto fixed_block_b_57;
  }
  /* b_55, b_56,  */
  fixed_block_b_57: 
  {
    /* execute.a64:2709 [D] s_b_57_0 = sym_51573_1_temporary_value uint32_t */
    auto s_b_57_0 = emitter.load_local(DV_sym_51573_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_57_1 = (u64)s_b_57_0 */
    auto s_b_57_1 = emitter.zx(s_b_57_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_57_2: sym_51310_1__R_s_b_24_4 = s_b_57_1, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_51310_1__R_s_b_24_4, s_b_57_1);
    /* execute.a64:2722 [F] s_b_57_3: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_31,  */
  fixed_block_b_58: 
  {
    /* execute.a64:2714 [F] s_b_58_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_58_1: sym_51601_1_temporary_value = s_b_58_0 (const), dominates: s_b_60_0  */
    CV_sym_51601_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51601_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_59_2: sym_51601_1_temporary_value = s_b_59_1, dominates: s_b_60_0  */
    emitter.store_local(DV_sym_51601_1_temporary_value, s_b_59_1);
    /* execute.a64:2714 [F] s_b_59_3: Jump b_60 (const) */
    goto fixed_block_b_60;
  }
  /* b_58, b_59,  */
  fixed_block_b_60: 
  {
    /* execute.a64:2714 [D] s_b_60_0 = sym_51601_1_temporary_value uint64_t */
    auto s_b_60_0 = emitter.load_local(DV_sym_51601_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_60_1: sym_51335_1__R_s_b_25_4 = s_b_60_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_51335_1__R_s_b_25_4, s_b_60_0);
    /* execute.a64:2720 [F] s_b_60_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_32,  */
  fixed_block_b_61: 
  {
    /* execute.a64:2709 [F] s_b_61_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_61_1: sym_51629_1_temporary_value = s_b_61_0 (const), dominates: s_b_63_0  */
    CV_sym_51629_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51629_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_62_2: sym_51629_1_temporary_value = s_b_62_1, dominates: s_b_63_0  */
    emitter.store_local(DV_sym_51629_1_temporary_value, s_b_62_1);
    /* execute.a64:2709 [F] s_b_62_3: Jump b_63 (const) */
    goto fixed_block_b_63;
  }
  /* b_61, b_62,  */
  fixed_block_b_63: 
  {
    /* execute.a64:2709 [D] s_b_63_0 = sym_51629_1_temporary_value uint32_t */
    auto s_b_63_0 = emitter.load_local(DV_sym_51629_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_63_1 = (u64)s_b_63_0 */
    auto s_b_63_1 = emitter.zx(s_b_63_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_63_2: sym_51335_1__R_s_b_25_4 = s_b_63_1, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_51335_1__R_s_b_25_4, s_b_63_1);
    /* execute.a64:2722 [F] s_b_63_3: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_22,  */
  fixed_block_b_64: 
  {
    /* execute.a64:2714 [F] s_b_64_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_64_1: sym_51657_1_temporary_value = s_b_64_0 (const), dominates: s_b_66_0  */
    CV_sym_51657_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51657_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_65_2: sym_51657_1_temporary_value = s_b_65_1, dominates: s_b_66_0  */
    emitter.store_local(DV_sym_51657_1_temporary_value, s_b_65_1);
    /* execute.a64:2714 [F] s_b_65_3: Jump b_66 (const) */
    goto fixed_block_b_66;
  }
  /* b_64, b_65,  */
  fixed_block_b_66: 
  {
    /* execute.a64:2714 [D] s_b_66_0 = sym_51657_1_temporary_value uint64_t */
    auto s_b_66_0 = emitter.load_local(DV_sym_51657_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2653 [F] s_b_66_1=sym_5865_3_parameter_inst.imm6 (const) */
    /* execute.a64:2653 [F] s_b_66_2 = (u64)s_b_66_1 (const) */
    /* execute.a64:2653 [D] s_b_66_3 = s_b_66_0>>>s_b_66_2 */
    auto s_b_66_3 = emitter.ror(s_b_66_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2653 [D] s_b_66_4: sym_51247_1__R_s_b_9_9 = s_b_66_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51247_1__R_s_b_9_9, s_b_66_3);
    /* execute.a64:2653 [F] s_b_66_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_67: 
  {
    /* execute.a64:2709 [F] s_b_67_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_67_1: sym_51741_1_temporary_value = s_b_67_0 (const), dominates: s_b_69_0  */
    CV_sym_51741_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_51741_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_68_2: sym_51741_1_temporary_value = s_b_68_1, dominates: s_b_69_0  */
    emitter.store_local(DV_sym_51741_1_temporary_value, s_b_68_1);
    /* execute.a64:2709 [F] s_b_68_3: Jump b_69 (const) */
    goto fixed_block_b_69;
  }
  /* b_67, b_68,  */
  fixed_block_b_69: 
  {
    /* execute.a64:2709 [D] s_b_69_0 = sym_51741_1_temporary_value uint32_t */
    auto s_b_69_0 = emitter.load_local(DV_sym_51741_1_temporary_value, emitter.context().types().u32());
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
    /* execute.a64:2655 [D] s_b_69_7: sym_51247_1__R_s_b_9_9 = s_b_69_6, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_51247_1__R_s_b_9_9, s_b_69_6);
    /* execute.a64:2655 [F] s_b_69_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_43,  */
  fixed_block_b_70: 
  {
    /* execute.a64:2747 [F] s_b_70_0=sym_5865_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_70_1 = sym_51770_3_parameter_value uint64_t */
    auto s_b_70_1 = emitter.load_local(DV_sym_51770_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [D] s_b_71_1 = sym_51792_3_parameter_value uint64_t */
    auto s_b_71_1 = emitter.load_local(DV_sym_51792_3_parameter_value, emitter.context().types().u64());
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
  auto DV_sym_53098_1__R_s_b_24_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52889_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_53333_1_temporary_value;
  auto DV_sym_53333_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_53168_1_temporary_value;
  auto DV_sym_53168_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  uint32_t CV_sym_53305_1_temporary_value;
  auto DV_sym_53305_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_53417_1_temporary_value;
  auto DV_sym_53417_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_53558_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_53529_1_temporary_value;
  auto DV_sym_53529_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_53389_1_temporary_value;
  auto DV_sym_53389_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_52908_1_temporary_value;
  auto DV_sym_52908_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53182_1__R_s_b_26_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_53248_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_53361_1_temporary_value;
  auto DV_sym_53361_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_53580_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53123_1__R_s_b_25_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_53277_1_temporary_value;
  auto DV_sym_53277_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_52936_1_temporary_value;
  auto DV_sym_52936_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_53445_1_temporary_value;
  auto DV_sym_53445_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_53156_1_temporary_value;
  auto DV_sym_53156_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_6266_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53053_1_tmp_s_b_9_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_53035_1__R_s_b_9_9;
  auto DV_sym_53035_1__R_s_b_9_9 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_53073_1__R_s_b_21_4 = emitter.alloc_local(emitter.context().types().u64(), false);
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
    /* execute.a64:2517 [D] s_b_8_0 = sym_52889_1__R_s_b_0_4 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_52889_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2518 [F] s_b_8_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* ???:4294967295 [D] s_b_8_2: sym_53053_1_tmp_s_b_9_0 = s_b_8_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_53053_1_tmp_s_b_9_0, s_b_8_0);
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
    /* execute.a64:2714 [F] s_b_9_1: sym_52908_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_52908_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_52908_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_10_2: sym_52908_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_52908_1_temporary_value, s_b_10_1);
    /* execute.a64:2714 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2714 [D] s_b_11_0 = sym_52908_1_temporary_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_52908_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_11_1: sym_52889_1__R_s_b_0_4 = s_b_11_0, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_52889_1__R_s_b_0_4, s_b_11_0);
    /* execute.a64:2720 [F] s_b_11_2: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_7,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_12_1: sym_52936_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_52936_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_52936_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_13_2: sym_52936_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_52936_1_temporary_value, s_b_13_1);
    /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_52936_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_52936_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_14_2: sym_52889_1__R_s_b_0_4 = s_b_14_1, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_52889_1__R_s_b_0_4, s_b_14_1);
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
    /* execute.a64:2637 [F] s_b_16_5: Switch s_b_16_0: < <todo> > def b_17 (const) -> b_18, b_17, b_21, b_20, b_19,  */
    switch (insn.shift) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
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
    /* execute.a64:2661 [F] s_b_17_2: sym_53035_1__R_s_b_9_9 = s_b_17_1 (const), dominates: s_b_24_1  */
    CV_sym_53035_1__R_s_b_9_9 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53035_1__R_s_b_9_9, emitter.const_u64((uint64_t)0ULL));
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
    /* ???:4294967295 [D] s_b_24_0 = sym_53053_1_tmp_s_b_9_0 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_53053_1_tmp_s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2518 [D] s_b_24_1 = sym_53035_1__R_s_b_9_9 uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_53035_1__R_s_b_9_9, emitter.context().types().u64());
    /* execute.a64:2520 [D] s_b_24_2 = ~s_b_24_1 */
    auto s_b_24_2 = emitter.bitwise_not(s_b_24_1);
    /* execute.a64:2520 [D] s_b_24_3 = s_b_24_0&s_b_24_2 */
    auto s_b_24_3 = emitter.bitwise_and(s_b_24_0, s_b_24_2);
    /* execute.a64:2520 [D] s_b_24_4: sym_6266_0_result = s_b_24_3, dominates: s_b_3_0 s_b_5_0  */
    emitter.store_local(DV_sym_6266_0_result, s_b_24_3);
    /* execute.a64:2521 [F] s_b_24_5=sym_6248_3_parameter_inst.sf (const) */
    /* execute.a64:2521 [D] s_b_24_6: sym_53248_3_parameter_value = s_b_24_3, dominates: s_b_43_1 s_b_44_1  */
    emitter.store_local(DV_sym_53248_3_parameter_value, s_b_24_3);
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
    /* execute.a64:2635 [D] s_b_27_0 = sym_53073_1__R_s_b_21_4 uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_53073_1__R_s_b_21_4, emitter.context().types().u64());
    /* execute.a64:2635 [D] s_b_27_1: sym_53035_1__R_s_b_9_9 = s_b_27_0, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53035_1__R_s_b_9_9, s_b_27_0);
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
    /* execute.a64:2640 [D] s_b_30_0 = sym_53098_1__R_s_b_24_4 uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_53098_1__R_s_b_24_4, emitter.context().types().u64());
    /* execute.a64:2640 [F] s_b_30_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2640 [F] s_b_30_2 = (u64)s_b_30_1 (const) */
    /* execute.a64:2640 [D] s_b_30_3 = s_b_30_0<<s_b_30_2 */
    auto s_b_30_3 = emitter.shl(s_b_30_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2640 [D] s_b_30_4: sym_53035_1__R_s_b_9_9 = s_b_30_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53035_1__R_s_b_9_9, s_b_30_3);
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
    /* execute.a64:2644 [D] s_b_33_0 = sym_53123_1__R_s_b_25_4 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_53123_1__R_s_b_25_4, emitter.context().types().u64());
    /* execute.a64:2644 [F] s_b_33_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2644 [F] s_b_33_2 = (u64)s_b_33_1 (const) */
    /* execute.a64:2644 [D] s_b_33_3 = s_b_33_0>>s_b_33_2 */
    auto s_b_33_3 = emitter.shr(s_b_33_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2644 [D] s_b_33_4: sym_53035_1__R_s_b_9_9 = s_b_33_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53035_1__R_s_b_9_9, s_b_33_3);
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
    /* execute.a64:2729 [F] s_b_36_1: sym_53156_1_temporary_value = s_b_36_0 (const), dominates: s_b_40_0  */
    CV_sym_53156_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_53156_1_temporary_value, emitter.const_s64((int64_t)0ULL));
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
    /* execute.a64:2729 [D] s_b_37_3: sym_53156_1_temporary_value = s_b_37_2, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_53156_1_temporary_value, s_b_37_2);
    /* execute.a64:2729 [F] s_b_37_4: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_35,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2731 [F] s_b_38_0 = constant s64 0 (const) */
    /* execute.a64:2731 [F] s_b_38_1: sym_53168_1_temporary_value = s_b_38_0 (const), dominates: s_b_41_0  */
    CV_sym_53168_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_53168_1_temporary_value, emitter.const_s64((int64_t)0ULL));
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
    /* execute.a64:2731 [D] s_b_39_4: sym_53168_1_temporary_value = s_b_39_3, dominates: s_b_41_0  */
    emitter.store_local(DV_sym_53168_1_temporary_value, s_b_39_3);
    /* execute.a64:2731 [F] s_b_39_5: Jump b_41 (const) */
    goto fixed_block_b_41;
  }
  /* b_36, b_37,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2729 [D] s_b_40_0 = sym_53156_1_temporary_value int64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_53156_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_40_1: sym_53182_1__R_s_b_26_4 = s_b_40_0, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_53182_1__R_s_b_26_4, s_b_40_0);
    /* execute.a64:2729 [F] s_b_40_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_38, b_39,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2731 [D] s_b_41_0 = sym_53168_1_temporary_value int64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_53168_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_41_1: sym_53182_1__R_s_b_26_4 = s_b_41_0, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_53182_1__R_s_b_26_4, s_b_41_0);
    /* execute.a64:2731 [F] s_b_41_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_40, b_41,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2648 [D] s_b_42_0 = sym_53182_1__R_s_b_26_4 int64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_53182_1__R_s_b_26_4, emitter.context().types().s64());
    /* execute.a64:2648 [F] s_b_42_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2648 [D] s_b_42_2 = (u64)s_b_42_0 */
    auto s_b_42_2 = emitter.reinterpret(s_b_42_0, emitter.context().types().u64());
    /* execute.a64:2648 [F] s_b_42_3 = (u64)s_b_42_1 (const) */
    /* execute.a64:2648 [D] s_b_42_4 = s_b_42_2->>s_b_42_3 */
    auto s_b_42_4 = emitter.sar(s_b_42_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2648 [D] s_b_42_5 = (u64)s_b_42_4 */
    auto s_b_42_5 = (captive::arch::dbt::el::Value *)s_b_42_4;
    /* execute.a64:2648 [D] s_b_42_6: sym_53035_1__R_s_b_9_9 = s_b_42_5, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53035_1__R_s_b_9_9, s_b_42_5);
    /* execute.a64:2648 [F] s_b_42_7: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_24,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2754 [F] s_b_43_0=sym_6248_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_43_1 = sym_53248_3_parameter_value uint64_t */
    auto s_b_43_1 = emitter.load_local(DV_sym_53248_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_43_2: sym_53558_3_parameter_value = s_b_43_1, dominates: s_b_70_1  */
    emitter.store_local(DV_sym_53558_3_parameter_value, s_b_43_1);
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
    /* execute.a64:2756 [D] s_b_44_1 = sym_53248_3_parameter_value uint64_t */
    auto s_b_44_1 = emitter.load_local(DV_sym_53248_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_44_2 = (u32)s_b_44_1 */
    auto s_b_44_2 = emitter.truncate(s_b_44_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_44_3 = (u64)s_b_44_2 */
    auto s_b_44_3 = emitter.zx(s_b_44_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_44_4: sym_53580_3_parameter_value = s_b_44_3, dominates: s_b_71_1  */
    emitter.store_local(DV_sym_53580_3_parameter_value, s_b_44_3);
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
    /* execute.a64:2714 [F] s_b_46_1: sym_53277_1_temporary_value = s_b_46_0 (const), dominates: s_b_48_0  */
    CV_sym_53277_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53277_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_47_2: sym_53277_1_temporary_value = s_b_47_1, dominates: s_b_48_0  */
    emitter.store_local(DV_sym_53277_1_temporary_value, s_b_47_1);
    /* execute.a64:2714 [F] s_b_47_3: Jump b_48 (const) */
    goto fixed_block_b_48;
  }
  /* b_46, b_47,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2714 [D] s_b_48_0 = sym_53277_1_temporary_value uint64_t */
    auto s_b_48_0 = emitter.load_local(DV_sym_53277_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_48_1: sym_53073_1__R_s_b_21_4 = s_b_48_0, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_53073_1__R_s_b_21_4, s_b_48_0);
    /* execute.a64:2720 [F] s_b_48_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_26,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2709 [F] s_b_49_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_49_1: sym_53305_1_temporary_value = s_b_49_0 (const), dominates: s_b_51_0  */
    CV_sym_53305_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53305_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_50_2: sym_53305_1_temporary_value = s_b_50_1, dominates: s_b_51_0  */
    emitter.store_local(DV_sym_53305_1_temporary_value, s_b_50_1);
    /* execute.a64:2709 [F] s_b_50_3: Jump b_51 (const) */
    goto fixed_block_b_51;
  }
  /* b_49, b_50,  */
  fixed_block_b_51: 
  {
    /* execute.a64:2709 [D] s_b_51_0 = sym_53305_1_temporary_value uint32_t */
    auto s_b_51_0 = emitter.load_local(DV_sym_53305_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_51_1 = (u64)s_b_51_0 */
    auto s_b_51_1 = emitter.zx(s_b_51_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_51_2: sym_53073_1__R_s_b_21_4 = s_b_51_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_53073_1__R_s_b_21_4, s_b_51_1);
    /* execute.a64:2722 [F] s_b_51_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_28,  */
  fixed_block_b_52: 
  {
    /* execute.a64:2714 [F] s_b_52_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_52_1: sym_53333_1_temporary_value = s_b_52_0 (const), dominates: s_b_54_0  */
    CV_sym_53333_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53333_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_53_2: sym_53333_1_temporary_value = s_b_53_1, dominates: s_b_54_0  */
    emitter.store_local(DV_sym_53333_1_temporary_value, s_b_53_1);
    /* execute.a64:2714 [F] s_b_53_3: Jump b_54 (const) */
    goto fixed_block_b_54;
  }
  /* b_52, b_53,  */
  fixed_block_b_54: 
  {
    /* execute.a64:2714 [D] s_b_54_0 = sym_53333_1_temporary_value uint64_t */
    auto s_b_54_0 = emitter.load_local(DV_sym_53333_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_54_1: sym_53098_1__R_s_b_24_4 = s_b_54_0, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_53098_1__R_s_b_24_4, s_b_54_0);
    /* execute.a64:2720 [F] s_b_54_2: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_29,  */
  fixed_block_b_55: 
  {
    /* execute.a64:2709 [F] s_b_55_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_55_1: sym_53361_1_temporary_value = s_b_55_0 (const), dominates: s_b_57_0  */
    CV_sym_53361_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53361_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_56_2: sym_53361_1_temporary_value = s_b_56_1, dominates: s_b_57_0  */
    emitter.store_local(DV_sym_53361_1_temporary_value, s_b_56_1);
    /* execute.a64:2709 [F] s_b_56_3: Jump b_57 (const) */
    goto fixed_block_b_57;
  }
  /* b_55, b_56,  */
  fixed_block_b_57: 
  {
    /* execute.a64:2709 [D] s_b_57_0 = sym_53361_1_temporary_value uint32_t */
    auto s_b_57_0 = emitter.load_local(DV_sym_53361_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_57_1 = (u64)s_b_57_0 */
    auto s_b_57_1 = emitter.zx(s_b_57_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_57_2: sym_53098_1__R_s_b_24_4 = s_b_57_1, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_53098_1__R_s_b_24_4, s_b_57_1);
    /* execute.a64:2722 [F] s_b_57_3: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_31,  */
  fixed_block_b_58: 
  {
    /* execute.a64:2714 [F] s_b_58_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_58_1: sym_53389_1_temporary_value = s_b_58_0 (const), dominates: s_b_60_0  */
    CV_sym_53389_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53389_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_59_2: sym_53389_1_temporary_value = s_b_59_1, dominates: s_b_60_0  */
    emitter.store_local(DV_sym_53389_1_temporary_value, s_b_59_1);
    /* execute.a64:2714 [F] s_b_59_3: Jump b_60 (const) */
    goto fixed_block_b_60;
  }
  /* b_58, b_59,  */
  fixed_block_b_60: 
  {
    /* execute.a64:2714 [D] s_b_60_0 = sym_53389_1_temporary_value uint64_t */
    auto s_b_60_0 = emitter.load_local(DV_sym_53389_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_60_1: sym_53123_1__R_s_b_25_4 = s_b_60_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_53123_1__R_s_b_25_4, s_b_60_0);
    /* execute.a64:2720 [F] s_b_60_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_32,  */
  fixed_block_b_61: 
  {
    /* execute.a64:2709 [F] s_b_61_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_61_1: sym_53417_1_temporary_value = s_b_61_0 (const), dominates: s_b_63_0  */
    CV_sym_53417_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53417_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_62_2: sym_53417_1_temporary_value = s_b_62_1, dominates: s_b_63_0  */
    emitter.store_local(DV_sym_53417_1_temporary_value, s_b_62_1);
    /* execute.a64:2709 [F] s_b_62_3: Jump b_63 (const) */
    goto fixed_block_b_63;
  }
  /* b_61, b_62,  */
  fixed_block_b_63: 
  {
    /* execute.a64:2709 [D] s_b_63_0 = sym_53417_1_temporary_value uint32_t */
    auto s_b_63_0 = emitter.load_local(DV_sym_53417_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_63_1 = (u64)s_b_63_0 */
    auto s_b_63_1 = emitter.zx(s_b_63_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_63_2: sym_53123_1__R_s_b_25_4 = s_b_63_1, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_53123_1__R_s_b_25_4, s_b_63_1);
    /* execute.a64:2722 [F] s_b_63_3: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_22,  */
  fixed_block_b_64: 
  {
    /* execute.a64:2714 [F] s_b_64_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_64_1: sym_53445_1_temporary_value = s_b_64_0 (const), dominates: s_b_66_0  */
    CV_sym_53445_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_53445_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
    /* execute.a64:2714 [D] s_b_65_2: sym_53445_1_temporary_value = s_b_65_1, dominates: s_b_66_0  */
    emitter.store_local(DV_sym_53445_1_temporary_value, s_b_65_1);
    /* execute.a64:2714 [F] s_b_65_3: Jump b_66 (const) */
    goto fixed_block_b_66;
  }
  /* b_64, b_65,  */
  fixed_block_b_66: 
  {
    /* execute.a64:2714 [D] s_b_66_0 = sym_53445_1_temporary_value uint64_t */
    auto s_b_66_0 = emitter.load_local(DV_sym_53445_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2653 [F] s_b_66_1=sym_6248_3_parameter_inst.imm6 (const) */
    /* execute.a64:2653 [F] s_b_66_2 = (u64)s_b_66_1 (const) */
    /* execute.a64:2653 [D] s_b_66_3 = s_b_66_0>>>s_b_66_2 */
    auto s_b_66_3 = emitter.ror(s_b_66_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2653 [D] s_b_66_4: sym_53035_1__R_s_b_9_9 = s_b_66_3, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53035_1__R_s_b_9_9, s_b_66_3);
    /* execute.a64:2653 [F] s_b_66_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_67: 
  {
    /* execute.a64:2709 [F] s_b_67_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_67_1: sym_53529_1_temporary_value = s_b_67_0 (const), dominates: s_b_69_0  */
    CV_sym_53529_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_53529_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
    /* execute.a64:2709 [D] s_b_68_2: sym_53529_1_temporary_value = s_b_68_1, dominates: s_b_69_0  */
    emitter.store_local(DV_sym_53529_1_temporary_value, s_b_68_1);
    /* execute.a64:2709 [F] s_b_68_3: Jump b_69 (const) */
    goto fixed_block_b_69;
  }
  /* b_67, b_68,  */
  fixed_block_b_69: 
  {
    /* execute.a64:2709 [D] s_b_69_0 = sym_53529_1_temporary_value uint32_t */
    auto s_b_69_0 = emitter.load_local(DV_sym_53529_1_temporary_value, emitter.context().types().u32());
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
    /* execute.a64:2655 [D] s_b_69_7: sym_53035_1__R_s_b_9_9 = s_b_69_6, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_53035_1__R_s_b_9_9, s_b_69_6);
    /* execute.a64:2655 [F] s_b_69_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_43,  */
  fixed_block_b_70: 
  {
    /* execute.a64:2747 [F] s_b_70_0=sym_6248_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_70_1 = sym_53558_3_parameter_value uint64_t */
    auto s_b_70_1 = emitter.load_local(DV_sym_53558_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [D] s_b_71_1 = sym_53580_3_parameter_value uint64_t */
    auto s_b_71_1 = emitter.load_local(DV_sym_53580_3_parameter_value, emitter.context().types().u64());
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
  uint8_t CV_sym_55375_0_state;
  auto DV_sym_55375_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55463_1__R_s_b_0_2 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_55488_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55507_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_55535_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_6758_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2083 [F] s_b_0_0=sym_6740_3_parameter_inst.cond (const) */
    /* execute.a64:2854 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2854 [F] s_b_0_2: sym_55375_0_state = s_b_0_1 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_55375_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_55375_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2856 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_7, b_12, b_6, b_8, b_10, b_9, b_11, b_13, b_14,  */
    switch (s_b_0_5) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)7ULL:
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
    /* execute.a64:2858 [D] s_b_7_0 = ReadReg 2 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:2858 [D] s_b_7_1: sym_55375_0_state = s_b_7_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55375_0_state, s_b_7_0);
    /* execute.a64:0 [F] s_b_7_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2866 [D] s_b_8_0 = ReadReg 1 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:2866 [D] s_b_8_1: sym_55375_0_state = s_b_8_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55375_0_state, s_b_8_0);
    /* execute.a64:0 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2886 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:2886 [F] s_b_9_1: sym_55375_0_state = s_b_9_0 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_55375_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_55375_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_9_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2882 [D] s_b_10_0 = ReadReg 1 (u8) */
    auto s_b_10_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_10_0, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_10_1 = ReadReg 4 (u8) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_10_1, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_10_2 = s_b_10_0==s_b_10_1 */
    auto s_b_10_2 = emitter.cmp_eq(s_b_10_0, s_b_10_1);
    /* execute.a64:2882 [D] s_b_10_3 = ReadReg 2 (u8) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_10_3, emitter.const_u8(1));
    }
    /* execute.a64:2882 [D] s_b_10_4 = !s_b_10_3 */
    auto s_b_10_4 = emitter.cmp_eq(s_b_10_3, emitter.const_u8(0));
    /* execute.a64:2882 [D] s_b_10_5 = s_b_10_2&s_b_10_4 */
    auto s_b_10_5 = emitter.bitwise_and(s_b_10_2, s_b_10_4);
    /* execute.a64:2882 [D] s_b_10_6: sym_55375_0_state = s_b_10_5, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55375_0_state, s_b_10_5);
    /* execute.a64:0 [F] s_b_10_7: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2878 [D] s_b_11_0 = ReadReg 1 (u8) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_11_0, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_11_1 = ReadReg 4 (u8) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_11_1, emitter.const_u8(1));
    }
    /* execute.a64:2878 [D] s_b_11_2 = s_b_11_0==s_b_11_1 */
    auto s_b_11_2 = emitter.cmp_eq(s_b_11_0, s_b_11_1);
    /* execute.a64:2878 [D] s_b_11_3: sym_55375_0_state = s_b_11_2, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55375_0_state, s_b_11_2);
    /* execute.a64:0 [F] s_b_11_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2874 [D] s_b_12_0 = ReadReg 3 (u8) */
    auto s_b_12_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_12_0, emitter.const_u8(1));
    }
    /* execute.a64:2874 [D] s_b_12_1 = ReadReg 2 (u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_12_1, emitter.const_u8(1));
    }
    /* execute.a64:2874 [D] s_b_12_2 = !s_b_12_1 */
    auto s_b_12_2 = emitter.cmp_eq(s_b_12_1, emitter.const_u8(0));
    /* execute.a64:2874 [D] s_b_12_3 = s_b_12_0&s_b_12_2 */
    auto s_b_12_3 = emitter.bitwise_and(s_b_12_0, s_b_12_2);
    /* execute.a64:2874 [D] s_b_12_4: sym_55375_0_state = s_b_12_3, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55375_0_state, s_b_12_3);
    /* execute.a64:0 [F] s_b_12_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2870 [D] s_b_13_0 = ReadReg 4 (u8) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_13_0, emitter.const_u8(1));
    }
    /* execute.a64:2870 [D] s_b_13_1: sym_55375_0_state = s_b_13_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55375_0_state, s_b_13_0);
    /* execute.a64:0 [F] s_b_13_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2862 [D] s_b_14_0 = ReadReg 3 (u8) */
    auto s_b_14_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_14_0, emitter.const_u8(1));
    }
    /* execute.a64:2862 [D] s_b_14_1: sym_55375_0_state = s_b_14_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_55375_0_state, s_b_14_0);
    /* execute.a64:0 [F] s_b_14_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2892 [D] s_b_15_0 = sym_55375_0_state uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_55375_0_state, emitter.context().types().u8());
    /* execute.a64:2892 [D] s_b_15_1 = !s_b_15_0 */
    auto s_b_15_1 = emitter.cmp_eq(s_b_15_0, emitter.const_u8(0));
    /* execute.a64:2892 [D] s_b_15_2: sym_55463_1__R_s_b_0_2 = s_b_15_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_55463_1__R_s_b_0_2, s_b_15_1);
    /* execute.a64:2892 [F] s_b_15_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2894 [D] s_b_16_0 = sym_55375_0_state uint8_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_55375_0_state, emitter.context().types().u8());
    /* execute.a64:2894 [D] s_b_16_1: sym_55463_1__R_s_b_0_2 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_55463_1__R_s_b_0_2, s_b_16_0);
    /* execute.a64:2894 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2083 [D] s_b_17_0 = sym_55463_1__R_s_b_0_2 uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_55463_1__R_s_b_0_2, emitter.context().types().u8());
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
        /* execute.a64:2086 [D] s_b_20_0 = sym_55488_1__R_s_b_1_4 uint64_t */
        auto s_b_20_0 = emitter.load_local(DV_sym_55488_1__R_s_b_1_4, emitter.context().types().u64());
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
        /* execute.a64:2714 [D] s_b_21_1: sym_55507_1_temporary_value = s_b_21_0, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_55507_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [D] s_b_22_2: sym_55507_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
        emitter.store_local(DV_sym_55507_1_temporary_value, s_b_22_1);
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
        /* execute.a64:2714 [D] s_b_23_0 = sym_55507_1_temporary_value uint64_t */
        auto s_b_23_0 = emitter.load_local(DV_sym_55507_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_23_1: sym_55488_1__R_s_b_1_4 = s_b_23_0, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_55488_1__R_s_b_1_4, s_b_23_0);
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
        /* execute.a64:2709 [D] s_b_24_1: sym_55535_1_temporary_value = s_b_24_0, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_55535_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [D] s_b_25_2: sym_55535_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
        emitter.store_local(DV_sym_55535_1_temporary_value, s_b_25_1);
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
        /* execute.a64:2709 [D] s_b_26_0 = sym_55535_1_temporary_value uint32_t */
        auto s_b_26_0 = emitter.load_local(DV_sym_55535_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_26_1 = (u64)s_b_26_0 */
        auto s_b_26_1 = emitter.zx(s_b_26_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_26_2: sym_55488_1__R_s_b_1_4 = s_b_26_1, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_55488_1__R_s_b_1_4, s_b_26_1);
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
    /* execute.simd:6237 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:1545 [F] s_b_1_2=sym_7781_3_parameter_inst.rm (const) */
    /* execute.simd:6237 [D] s_b_1_3 = ReadRegBank 7:s_b_1_2 (u64) */
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
        /* execute.simd:6208 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
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
        /* execute.simd:1550 [F] s_b_5_0=sym_7781_3_parameter_inst.rd (const) */
        /* execute.simd:1550 [F] s_b_5_1 = constant u64 0 (const) */
        /* execute.simd:6208 [F] s_b_5_2: WriteRegBank 2:s_b_5_0 = s_b_5_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6209 [F] s_b_5_3 = constant u64 0 (const) */
        /* execute.simd:6209 [F] s_b_5_4: WriteRegBank 3:s_b_5_0 = s_b_5_3 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_csinv(const arm64_decode_a64_COND_SEL&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_58242_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58160_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  uint8_t CV_sym_57957_0_state;
  auto DV_sym_57957_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_58189_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58217_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_58272_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58294_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58316_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58000_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_58107_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58082_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58338_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58135_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_58051_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2191 [F] s_b_0_0=sym_9040_3_parameter_inst.cond (const) */
    /* execute.a64:2854 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2854 [F] s_b_0_2: sym_57957_0_state = s_b_0_1 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_57957_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_57957_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2856 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_4 (const) -> b_4, b_14, b_7, b_9, b_11, b_12, b_13, b_8, b_10,  */
    switch (s_b_0_5) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_9;
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
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_10;
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
    /* execute.a64:2891 [F] s_b_4_0=sym_9040_3_parameter_inst.cond (const) */
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
    /* execute.a64:2892 [D] s_b_5_0 = sym_57957_0_state uint8_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_57957_0_state, emitter.context().types().u8());
    /* execute.a64:2892 [D] s_b_5_1 = !s_b_5_0 */
    auto s_b_5_1 = emitter.cmp_eq(s_b_5_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_5_2: sym_58000_0_return_symbol = s_b_5_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_58000_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2894 [D] s_b_6_0 = sym_57957_0_state uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_57957_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_6_1: sym_58000_0_return_symbol = s_b_6_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_58000_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2858 [D] s_b_7_1: sym_57957_0_state = s_b_7_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57957_0_state, s_b_7_0);
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
    /* execute.a64:2862 [D] s_b_8_1: sym_57957_0_state = s_b_8_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57957_0_state, s_b_8_0);
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
    /* execute.a64:2866 [D] s_b_9_1: sym_57957_0_state = s_b_9_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57957_0_state, s_b_9_0);
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
    /* execute.a64:2870 [D] s_b_10_1: sym_57957_0_state = s_b_10_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57957_0_state, s_b_10_0);
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
    /* execute.a64:2874 [D] s_b_11_4: sym_57957_0_state = s_b_11_3, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57957_0_state, s_b_11_3);
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
    /* execute.a64:2878 [D] s_b_12_3: sym_57957_0_state = s_b_12_2, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57957_0_state, s_b_12_2);
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
    /* execute.a64:2882 [D] s_b_13_6: sym_57957_0_state = s_b_13_5, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_57957_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2886 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2886 [F] s_b_14_1: sym_57957_0_state = s_b_14_0 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_57957_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_57957_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5, b_6,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_58000_0_return_symbol uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_58000_0_return_symbol, emitter.context().types().u8());
    /* execute.a64:2193 [D] s_b_15_1 = (u32)s_b_15_0 */
    auto s_b_15_1 = emitter.zx(s_b_15_0, emitter.context().types().u32());
    /* execute.a64:2193 [F] s_b_15_2 = constant u32 0 (const) */
    /* execute.a64:2193 [D] s_b_15_3 = s_b_15_1==s_b_15_2 */
    auto s_b_15_3 = emitter.cmp_eq(s_b_15_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2193 [D] s_b_15_4: If s_b_15_3: Jump b_1 else b_3 */
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
        /* execute.a64:2194 [F] s_b_1_0=sym_9040_3_parameter_inst.sf (const) */
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
        /* execute.a64:2196 [F] s_b_3_0=sym_9040_3_parameter_inst.sf (const) */
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
        /* execute.a64:2720 [F] s_b_16_0=sym_9040_3_parameter_inst.rm (const) */
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
        /* execute.a64:2722 [F] s_b_17_0=sym_9040_3_parameter_inst.rm (const) */
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
        /* ???:4294967295 [F] s_b_18_0=sym_9040_3_parameter_inst.sf (const) */
        /* execute.a64:2194 [D] s_b_18_1 = sym_58051_1__R_s_b_1_6 uint64_t */
        auto s_b_18_1 = emitter.load_local(DV_sym_58051_1__R_s_b_1_6, emitter.context().types().u64());
        /* execute.a64:2194 [D] s_b_18_2 = ~s_b_18_1 */
        auto s_b_18_2 = emitter.bitwise_not(s_b_18_1);
        /* execute.a64:2194 [D] s_b_18_3: sym_58160_3_parameter_value = s_b_18_2, dominates: s_b_28_1 s_b_29_1  */
        emitter.store_local(DV_sym_58160_3_parameter_value, s_b_18_2);
        /* execute.a64:2753 [F] s_b_18_4: If s_b_18_0: Jump b_28 else b_29 (const) */
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
        /* execute.a64:2720 [F] s_b_19_0=sym_9040_3_parameter_inst.rn (const) */
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
        /* execute.a64:2722 [F] s_b_20_0=sym_9040_3_parameter_inst.rn (const) */
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
        /* ???:4294967295 [F] s_b_21_0=sym_9040_3_parameter_inst.sf (const) */
        /* execute.a64:2196 [D] s_b_21_1 = sym_58082_1__R_s_b_3_6 uint64_t */
        auto s_b_21_1 = emitter.load_local(DV_sym_58082_1__R_s_b_3_6, emitter.context().types().u64());
        /* execute.a64:2196 [D] s_b_21_2: sym_58242_3_parameter_value = s_b_21_1, dominates: s_b_36_1 s_b_37_1  */
        emitter.store_local(DV_sym_58242_3_parameter_value, s_b_21_1);
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
        /* execute.a64:2714 [D] s_b_22_1: sym_58107_1_temporary_value = s_b_22_0, dominates: s_b_24_0  */
        emitter.store_local(DV_sym_58107_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_23_0=sym_9040_3_parameter_inst.rm (const) */
        /* execute.a64:2714 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
        auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_23_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_23_2: sym_58107_1_temporary_value = s_b_23_1, dominates: s_b_24_0  */
        emitter.store_local(DV_sym_58107_1_temporary_value, s_b_23_1);
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
        /* execute.a64:2714 [D] s_b_24_0 = sym_58107_1_temporary_value uint64_t */
        auto s_b_24_0 = emitter.load_local(DV_sym_58107_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_24_1: sym_58051_1__R_s_b_1_6 = s_b_24_0, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_58051_1__R_s_b_1_6, s_b_24_0);
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
        /* execute.a64:2709 [D] s_b_25_1: sym_58135_1_temporary_value = s_b_25_0, dominates: s_b_27_0  */
        emitter.store_local(DV_sym_58135_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_26_0=sym_9040_3_parameter_inst.rm (const) */
        /* execute.a64:2709 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
        auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_26_2: sym_58135_1_temporary_value = s_b_26_1, dominates: s_b_27_0  */
        emitter.store_local(DV_sym_58135_1_temporary_value, s_b_26_1);
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
        /* execute.a64:2709 [D] s_b_27_0 = sym_58135_1_temporary_value uint32_t */
        auto s_b_27_0 = emitter.load_local(DV_sym_58135_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_27_1 = (u64)s_b_27_0 */
        auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_27_2: sym_58051_1__R_s_b_1_6 = s_b_27_1, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_58051_1__R_s_b_1_6, s_b_27_1);
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
        /* execute.a64:2754 [F] s_b_28_0=sym_9040_3_parameter_inst.rd (const) */
        /* execute.a64:2754 [D] s_b_28_1 = sym_58160_3_parameter_value uint64_t */
        auto s_b_28_1 = emitter.load_local(DV_sym_58160_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2754 [D] s_b_28_2: sym_58272_3_parameter_value = s_b_28_1, dominates: s_b_38_1  */
        emitter.store_local(DV_sym_58272_3_parameter_value, s_b_28_1);
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
        /* execute.a64:2756 [F] s_b_29_0=sym_9040_3_parameter_inst.rd (const) */
        /* execute.a64:2756 [D] s_b_29_1 = sym_58160_3_parameter_value uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_58160_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_29_2 = (u32)s_b_29_1 */
        auto s_b_29_2 = emitter.truncate(s_b_29_1, emitter.context().types().u32());
        /* execute.a64:2756 [D] s_b_29_3 = (u64)s_b_29_2 */
        auto s_b_29_3 = emitter.zx(s_b_29_2, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_29_4: sym_58294_3_parameter_value = s_b_29_3, dominates: s_b_39_1  */
        emitter.store_local(DV_sym_58294_3_parameter_value, s_b_29_3);
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
        /* execute.a64:2714 [D] s_b_30_1: sym_58189_1_temporary_value = s_b_30_0, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_58189_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_31_0=sym_9040_3_parameter_inst.rn (const) */
        /* execute.a64:2714 [D] s_b_31_1 = ReadRegBank 0:s_b_31_0 (u64) */
        auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_31_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_31_2: sym_58189_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_58189_1_temporary_value, s_b_31_1);
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
        /* execute.a64:2714 [D] s_b_32_0 = sym_58189_1_temporary_value uint64_t */
        auto s_b_32_0 = emitter.load_local(DV_sym_58189_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_32_1: sym_58082_1__R_s_b_3_6 = s_b_32_0, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_58082_1__R_s_b_3_6, s_b_32_0);
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
        /* execute.a64:2709 [D] s_b_33_1: sym_58217_1_temporary_value = s_b_33_0, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_58217_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_34_0=sym_9040_3_parameter_inst.rn (const) */
        /* execute.a64:2709 [D] s_b_34_1 = ReadRegBank 1:s_b_34_0 (u32) */
        auto s_b_34_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_34_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_34_2: sym_58217_1_temporary_value = s_b_34_1, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_58217_1_temporary_value, s_b_34_1);
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
        /* execute.a64:2709 [D] s_b_35_0 = sym_58217_1_temporary_value uint32_t */
        auto s_b_35_0 = emitter.load_local(DV_sym_58217_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_35_1 = (u64)s_b_35_0 */
        auto s_b_35_1 = emitter.zx(s_b_35_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_35_2: sym_58082_1__R_s_b_3_6 = s_b_35_1, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_58082_1__R_s_b_3_6, s_b_35_1);
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
        /* execute.a64:2754 [F] s_b_36_0=sym_9040_3_parameter_inst.rd (const) */
        /* execute.a64:2754 [D] s_b_36_1 = sym_58242_3_parameter_value uint64_t */
        auto s_b_36_1 = emitter.load_local(DV_sym_58242_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2754 [D] s_b_36_2: sym_58316_3_parameter_value = s_b_36_1, dominates: s_b_40_1  */
        emitter.store_local(DV_sym_58316_3_parameter_value, s_b_36_1);
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
        /* execute.a64:2756 [F] s_b_37_0=sym_9040_3_parameter_inst.rd (const) */
        /* execute.a64:2756 [D] s_b_37_1 = sym_58242_3_parameter_value uint64_t */
        auto s_b_37_1 = emitter.load_local(DV_sym_58242_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_37_2 = (u32)s_b_37_1 */
        auto s_b_37_2 = emitter.truncate(s_b_37_1, emitter.context().types().u32());
        /* execute.a64:2756 [D] s_b_37_3 = (u64)s_b_37_2 */
        auto s_b_37_3 = emitter.zx(s_b_37_2, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_37_4: sym_58338_3_parameter_value = s_b_37_3, dominates: s_b_41_1  */
        emitter.store_local(DV_sym_58338_3_parameter_value, s_b_37_3);
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
        /* execute.a64:2747 [F] s_b_38_0=sym_9040_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_38_1 = sym_58272_3_parameter_value uint64_t */
        auto s_b_38_1 = emitter.load_local(DV_sym_58272_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2747 [F] s_b_39_0=sym_9040_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_39_1 = sym_58294_3_parameter_value uint64_t */
        auto s_b_39_1 = emitter.load_local(DV_sym_58294_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2747 [F] s_b_40_0=sym_9040_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_40_1 = sym_58316_3_parameter_value uint64_t */
        auto s_b_40_1 = emitter.load_local(DV_sym_58316_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2747 [F] s_b_41_0=sym_9040_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_41_1 = sym_58338_3_parameter_value uint64_t */
        auto s_b_41_1 = emitter.load_local(DV_sym_58338_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_eret(const arm64_decode_a64_UB_REG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:631 [D] s_b_0_0 = ReadReg 17 (u64) */
    auto s_b_0_0 = emitter.load_register(emitter.const_u32(1376), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1376), s_b_0_0, emitter.const_u8(8));
    }
    /* execute.a64:631 [D] s_b_0_1 = (u64)s_b_0_0 */
    auto s_b_0_1 = (captive::arch::dbt::el::Value *)s_b_0_0;
    /* execute.a64:631 [D] s_b_0_2 = ReadReg 18 (u32) */
    auto s_b_0_2 = emitter.load_register(emitter.const_u32(1384), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1384), s_b_0_2, emitter.const_u8(4));
    }
    /* execute.a64:631 [D] s_b_0_3 = (u32)s_b_0_2 */
    auto s_b_0_3 = (captive::arch::dbt::el::Value *)s_b_0_2;
    /* execute.a64:2914 [F] s_b_0_4 = constant u32 80000000 (const) */
    /* execute.a64:2914 [D] s_b_0_5 = s_b_0_3&s_b_0_4 */
    auto s_b_0_5 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)2147483648ULL));
    /* execute.a64:2914 [F] s_b_0_6 = constant u32 80000000 (const) */
    /* execute.a64:2914 [D] s_b_0_7 = s_b_0_5==s_b_0_6 */
    auto s_b_0_7 = emitter.cmp_eq(s_b_0_5, emitter.const_u32((uint32_t)2147483648ULL));
    /* execute.a64:2914 [D] s_b_0_8: WriteReg 1 = s_b_0_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), s_b_0_7, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1296), s_b_0_7);
    /* execute.a64:2915 [F] s_b_0_9 = constant u32 40000000 (const) */
    /* execute.a64:2915 [D] s_b_0_10 = s_b_0_3&s_b_0_9 */
    auto s_b_0_10 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)1073741824ULL));
    /* execute.a64:2915 [F] s_b_0_11 = constant u32 40000000 (const) */
    /* execute.a64:2915 [D] s_b_0_12 = s_b_0_10==s_b_0_11 */
    auto s_b_0_12 = emitter.cmp_eq(s_b_0_10, emitter.const_u32((uint32_t)1073741824ULL));
    /* execute.a64:2915 [D] s_b_0_13: WriteReg 2 = s_b_0_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), s_b_0_12, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1297), s_b_0_12);
    /* execute.a64:2916 [F] s_b_0_14 = constant u32 20000000 (const) */
    /* execute.a64:2916 [D] s_b_0_15 = s_b_0_3&s_b_0_14 */
    auto s_b_0_15 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)536870912ULL));
    /* execute.a64:2916 [F] s_b_0_16 = constant u32 20000000 (const) */
    /* execute.a64:2916 [D] s_b_0_17 = s_b_0_15==s_b_0_16 */
    auto s_b_0_17 = emitter.cmp_eq(s_b_0_15, emitter.const_u32((uint32_t)536870912ULL));
    /* execute.a64:2916 [D] s_b_0_18: WriteReg 3 = s_b_0_17 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), s_b_0_17, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), s_b_0_17);
    /* execute.a64:2917 [F] s_b_0_19 = constant u32 10000000 (const) */
    /* execute.a64:2917 [D] s_b_0_20 = s_b_0_3&s_b_0_19 */
    auto s_b_0_20 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)268435456ULL));
    /* execute.a64:2917 [F] s_b_0_21 = constant u32 10000000 (const) */
    /* execute.a64:2917 [D] s_b_0_22 = s_b_0_20==s_b_0_21 */
    auto s_b_0_22 = emitter.cmp_eq(s_b_0_20, emitter.const_u32((uint32_t)268435456ULL));
    /* execute.a64:2917 [D] s_b_0_23: WriteReg 4 = s_b_0_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), s_b_0_22, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), s_b_0_22);
    /* execute.a64:2919 [F] s_b_0_24 = constant u32 200 (const) */
    /* execute.a64:2919 [D] s_b_0_25 = s_b_0_3&s_b_0_24 */
    auto s_b_0_25 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)512ULL));
    /* execute.a64:2919 [F] s_b_0_26 = constant u32 200 (const) */
    /* execute.a64:2919 [D] s_b_0_27 = s_b_0_25==s_b_0_26 */
    auto s_b_0_27 = emitter.cmp_eq(s_b_0_25, emitter.const_u32((uint32_t)512ULL));
    /* execute.a64:2919 [D] s_b_0_28: WriteReg 5 = s_b_0_27 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), s_b_0_27, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), s_b_0_27);
    /* execute.a64:2920 [F] s_b_0_29 = constant u32 100 (const) */
    /* execute.a64:2920 [D] s_b_0_30 = s_b_0_3&s_b_0_29 */
    auto s_b_0_30 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)256ULL));
    /* execute.a64:2920 [F] s_b_0_31 = constant u32 100 (const) */
    /* execute.a64:2920 [D] s_b_0_32 = s_b_0_30==s_b_0_31 */
    auto s_b_0_32 = emitter.cmp_eq(s_b_0_30, emitter.const_u32((uint32_t)256ULL));
    /* execute.a64:2920 [D] s_b_0_33: WriteReg 6 = s_b_0_32 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), s_b_0_32, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), s_b_0_32);
    /* execute.a64:2921 [F] s_b_0_34 = constant u32 80 (const) */
    /* execute.a64:2921 [D] s_b_0_35 = s_b_0_3&s_b_0_34 */
    auto s_b_0_35 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)128ULL));
    /* execute.a64:2921 [F] s_b_0_36 = constant u32 80 (const) */
    /* execute.a64:2921 [D] s_b_0_37 = s_b_0_35==s_b_0_36 */
    auto s_b_0_37 = emitter.cmp_eq(s_b_0_35, emitter.const_u32((uint32_t)128ULL));
    /* execute.a64:2921 [D] s_b_0_38: WriteReg 7 = s_b_0_37 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), s_b_0_37, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), s_b_0_37);
    /* execute.a64:2922 [F] s_b_0_39 = constant u32 40 (const) */
    /* execute.a64:2922 [D] s_b_0_40 = s_b_0_3&s_b_0_39 */
    auto s_b_0_40 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)64ULL));
    /* execute.a64:2922 [F] s_b_0_41 = constant u32 40 (const) */
    /* execute.a64:2922 [D] s_b_0_42 = s_b_0_40==s_b_0_41 */
    auto s_b_0_42 = emitter.cmp_eq(s_b_0_40, emitter.const_u32((uint32_t)64ULL));
    /* execute.a64:2922 [D] s_b_0_43: WriteReg 8 = s_b_0_42 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), s_b_0_42, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), s_b_0_42);
    /* execute.a64:2924 [F] s_b_0_44 = constant u32 2 (const) */
    /* execute.a64:2924 [D] s_b_0_45 = s_b_0_3>>s_b_0_44 */
    auto s_b_0_45 = emitter.shr(s_b_0_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.a64:2924 [D] s_b_0_46 = (u8)s_b_0_45 */
    auto s_b_0_46 = emitter.truncate(s_b_0_45, emitter.context().types().u8());
    /* execute.a64:2924 [F] s_b_0_47 = constant u8 3 (const) */
    /* execute.a64:2924 [D] s_b_0_48 = s_b_0_46&s_b_0_47 */
    auto s_b_0_48 = emitter.bitwise_and(s_b_0_46, emitter.const_u8((uint8_t)3ULL));
    /* execute.a64:3080 [F] s_b_0_49 = constant u32 0 (const) */
    /* execute.a64:3080 [D] s_b_0_50 = (u32)s_b_0_48 */
    auto s_b_0_50 = emitter.zx(s_b_0_48, emitter.context().types().u32());
    /* execute.a64:3080 [D] s_b_0_51 = __builtin_set_feature */
    emitter.set_feature((uint32_t)0ULL, s_b_0_50);
    /* execute.a64:2926 [F] s_b_0_52 = constant u32 1 (const) */
    /* execute.a64:2926 [D] s_b_0_53 = s_b_0_3&s_b_0_52 */
    auto s_b_0_53 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:2926 [D] s_b_0_54 = (u8)s_b_0_53 */
    auto s_b_0_54 = emitter.truncate(s_b_0_53, emitter.context().types().u8());
    /* execute.a64:3016 [F] s_b_0_55 = constant u32 1 (const) */
    /* execute.a64:3016 [D] s_b_0_56 = (u32)s_b_0_54 */
    auto s_b_0_56 = emitter.zx(s_b_0_54, emitter.context().types().u32());
    /* execute.a64:3016 [D] s_b_0_57 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, s_b_0_56);
    /* execute.a64:3068 [D] s_b_0_58 = write_pc */
    emitter.store_pc(s_b_0_1);
    /* ???:4294967295 [F] s_b_0_59: Return */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fcmgt_zero(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2125 [F] s_b_0_0=sym_10531_3_parameter_inst.size (const) */
    /* execute.simd:2125 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:2125 [F] s_b_0_2 = constant u32 2 (const) */
    /* execute.simd:2125 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:2125 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2126 [F] s_b_1_0=sym_10531_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:2127 [F] s_b_1_2 = constant f32 0 (const) */
    float s_b_1_2;
    {
      uint32_t __tmp = 0;
      s_b_1_2 = *(float *)&__tmp;
    }
    /* execute.simd:2127 [D] s_b_1_3 = s_b_1_1>s_b_1_2 */
    auto s_b_1_3 = emitter.cmp_gt(s_b_1_1, emitter.const_f32(s_b_1_2));
    /* execute.simd:2127 [D] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 */
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
    /* execute.simd:2133 [F] s_b_3_0=sym_10531_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:2134 [F] s_b_3_2 = constant f64 0 (const) */
    double s_b_3_2;
    {
      uint64_t __tmp = 0;
      s_b_3_2 = *(double *)&__tmp;
    }
    /* execute.simd:2134 [D] s_b_3_3 = s_b_3_1>s_b_3_2 */
    auto s_b_3_3 = emitter.cmp_gt(s_b_3_1, emitter.const_f64(s_b_3_2));
    /* execute.simd:2134 [D] s_b_3_4: If s_b_3_3: Jump b_6 else b_7 */
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
      emitter.branch(s_b_3_3, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  // BLOCK b_6 not fully fixed
  // BLOCK b_7 not fully fixed
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
        /* execute.simd:2128 [F] s_b_4_0=sym_10531_3_parameter_inst.rd (const) */
        /* execute.simd:6201 [F] s_b_4_1 = constant u64 ffffffff (const) */
        /* execute.simd:6201 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)4294967295ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)4294967295ULL));
        /* execute.simd:6202 [F] s_b_4_3 = constant u64 0 (const) */
        /* execute.simd:6202 [F] s_b_4_4: WriteRegBank 3:s_b_4_0 = s_b_4_3 */
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
        /* execute.simd:2130 [F] s_b_5_0=sym_10531_3_parameter_inst.rd (const) */
        /* execute.simd:6201 [F] s_b_5_1 = constant u64 0 (const) */
        /* execute.simd:6201 [F] s_b_5_2: WriteRegBank 2:s_b_5_0 = s_b_5_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6202 [F] s_b_5_3 = constant u64 0 (const) */
        /* execute.simd:6202 [F] s_b_5_4: WriteRegBank 3:s_b_5_0 = s_b_5_3 */
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
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:2135 [F] s_b_6_0=sym_10531_3_parameter_inst.rd (const) */
        /* execute.simd:2135 [F] s_b_6_1 = constant u64 ffffffffffffffff (const) */
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
        /* execute.simd:2137 [F] s_b_7_0=sym_10531_3_parameter_inst.rd (const) */
        /* execute.simd:2137 [F] s_b_7_1 = constant u64 0 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fcvtzs_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4515 [F] s_b_0_0=sym_11317_3_parameter_inst.U (const) */
    /* execute.simd:4515 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4515 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4515 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)0ULL));
    /* execute.simd:4515 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4516 [F] s_b_1_0=sym_11317_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4516 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4516 [F] s_b_1_2 = constant u32 1 (const) */
    /* execute.simd:4516 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:4516 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_6, b_7, b_8, b_9, b_10, b_12, b_13, b_14, b_16, b_17, b_18,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4561 [F] s_b_3_0=sym_11317_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4561 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4561 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4561 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:4561 [F] s_b_3_4: If s_b_3_3: Jump b_15 else b_16 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_15;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_1,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4517 [F] s_b_4_0=sym_11317_3_parameter_inst.size (const) */
    /* execute.simd:4517 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4517 [F] s_b_4_2 = constant u32 2 (const) */
    /* execute.simd:4517 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4517 [F] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4525 [F] s_b_5_0=sym_11317_3_parameter_inst.Q (const) */
    /* execute.simd:4525 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4525 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.simd:4525 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:4525 [F] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4519 [F] s_b_6_0=sym_11317_3_parameter_inst.rd (const) */
    /* execute.simd:4519 [F] s_b_6_1=sym_11317_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_6_2 = ReadRegBank 9:s_b_6_1 (f32) */
    auto s_b_6_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_2,emitter.const_u8(4));
    }
    /* execute.simd:4519 [F] s_b_6_3 = constant u8 3 (const) */
    /* execute.simd:4519 [D] s_b_6_4 = __builtin_fcvt_f32_s32 */
    auto s_b_6_4 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_6_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4519 [D] s_b_6_5 = (u32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().u32());
    /* execute.simd:6201 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.simd:6201 [D] s_b_6_7: WriteRegBank 2:s_b_6_0 = s_b_6_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6);
    /* execute.simd:6202 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:6202 [F] s_b_6_9: WriteRegBank 3:s_b_6_0 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4522 [F] s_b_7_0=sym_11317_3_parameter_inst.rd (const) */
    /* execute.simd:4522 [F] s_b_7_1=sym_11317_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_7_2 = ReadRegBank 11:s_b_7_1 (f64) */
    auto s_b_7_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_2,emitter.const_u8(8));
    }
    /* execute.simd:4522 [F] s_b_7_3 = constant u8 3 (const) */
    /* execute.simd:4522 [D] s_b_7_4 = __builtin_fcvt_f64_s64 */
    auto s_b_7_4 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_7_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4522 [D] s_b_7_5 = (u64)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().u64());
    /* execute.simd:6208 [D] s_b_7_6: WriteRegBank 2:s_b_7_0 = s_b_7_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5);
    /* execute.simd:6209 [F] s_b_7_7 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_7_8: WriteRegBank 3:s_b_7_0 = s_b_7_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_7_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4526 [F] s_b_8_0=sym_11317_3_parameter_inst.size (const) */
    /* execute.simd:4526 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.simd:4526 [F] s_b_8_2 = constant u32 2 (const) */
    /* execute.simd:4526 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4526 [F] s_b_8_4: If s_b_8_3: Jump b_10 else b_2 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_5,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4536 [F] s_b_9_0=sym_11317_3_parameter_inst.Q (const) */
    /* execute.simd:4536 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4536 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4536 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* execute.simd:4536 [F] s_b_9_4: If s_b_9_3: Jump b_11 else b_2 (const) */
    if (s_b_9_3) 
    {
      goto fixed_block_b_11;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4528 [F] s_b_10_0=sym_11317_3_parameter_inst.rn (const) */
    /* execute.simd:4528 [D] s_b_10_1 = ReadRegBank 12:s_b_10_0 (v2f32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_10_2 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:4531 [F] s_b_10_3 = constant s32 0 (const) */
    /* execute.simd:4531 [D] s_b_10_1[s_b_10_3] */
    auto s_b_10_4 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4531 [F] s_b_10_5 = constant u8 3 (const) */
    /* execute.simd:4531 [D] s_b_10_6 = __builtin_fcvt_f32_s32 */
    auto s_b_10_6 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_10_4, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4531 [F] s_b_10_7 = constant s32 0 (const) */
    /* execute.simd:4531 [D] s_b_10_8 = s_b_10_2[s_b_10_7] <= s_b_10_6 */
    auto s_b_10_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()), emitter.const_s32((int32_t)0ULL), s_b_10_6);
    /* execute.simd:4532 [F] s_b_10_9 = constant s32 1 (const) */
    /* execute.simd:4532 [D] s_b_10_1[s_b_10_9] */
    auto s_b_10_10 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4532 [F] s_b_10_11 = constant u8 3 (const) */
    /* execute.simd:4532 [D] s_b_10_12 = __builtin_fcvt_f32_s32 */
    auto s_b_10_12 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_10_10, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4532 [F] s_b_10_13 = constant s32 1 (const) */
    /* execute.simd:4532 [D] s_b_10_14 = s_b_10_8[s_b_10_13] <= s_b_10_12 */
    auto s_b_10_14 = emitter.vector_insert(s_b_10_8, emitter.const_s32((int32_t)1ULL), s_b_10_12);
    /* execute.simd:4534 [F] s_b_10_15=sym_11317_3_parameter_inst.rd (const) */
    /* execute.simd:4534 [D] s_b_10_16 = (v2u32)s_b_10_14 */
    auto s_b_10_16 = emitter.reinterpret(s_b_10_14, emitter.context().types().v2u32());
    /* execute.simd:4534 [D] s_b_10_17: WriteRegBank 19:s_b_10_15 = s_b_10_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_16);
    /* execute.simd:4528 [F] s_b_10_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4537 [F] s_b_11_0=sym_11317_3_parameter_inst.size (const) */
    /* execute.simd:4537 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.simd:4537 [F] s_b_11_2 = constant u32 2 (const) */
    /* execute.simd:4537 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4537 [F] s_b_11_4: If s_b_11_3: Jump b_12 else b_13 (const) */
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
    /* execute.simd:4539 [F] s_b_12_0=sym_11317_3_parameter_inst.rn (const) */
    /* execute.simd:4539 [D] s_b_12_1 = ReadRegBank 13:s_b_12_0 (v4f32) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_12_2 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:4542 [F] s_b_12_3 = constant s32 0 (const) */
    /* execute.simd:4542 [D] s_b_12_1[s_b_12_3] */
    auto s_b_12_4 = emitter.vector_extract(s_b_12_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4542 [F] s_b_12_5 = constant u8 3 (const) */
    /* execute.simd:4542 [D] s_b_12_6 = __builtin_fcvt_f32_s32 */
    auto s_b_12_6 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_12_4, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4542 [F] s_b_12_7 = constant s32 0 (const) */
    /* execute.simd:4542 [D] s_b_12_8 = s_b_12_2[s_b_12_7] <= s_b_12_6 */
    auto s_b_12_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_12_6);
    /* execute.simd:4543 [F] s_b_12_9 = constant s32 1 (const) */
    /* execute.simd:4543 [D] s_b_12_1[s_b_12_9] */
    auto s_b_12_10 = emitter.vector_extract(s_b_12_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4543 [F] s_b_12_11 = constant u8 3 (const) */
    /* execute.simd:4543 [D] s_b_12_12 = __builtin_fcvt_f32_s32 */
    auto s_b_12_12 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_12_10, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4543 [F] s_b_12_13 = constant s32 1 (const) */
    /* execute.simd:4543 [D] s_b_12_14 = s_b_12_8[s_b_12_13] <= s_b_12_12 */
    auto s_b_12_14 = emitter.vector_insert(s_b_12_8, emitter.const_s32((int32_t)1ULL), s_b_12_12);
    /* execute.simd:4544 [F] s_b_12_15 = constant s32 2 (const) */
    /* execute.simd:4544 [D] s_b_12_1[s_b_12_15] */
    auto s_b_12_16 = emitter.vector_extract(s_b_12_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4544 [F] s_b_12_17 = constant u8 3 (const) */
    /* execute.simd:4544 [D] s_b_12_18 = __builtin_fcvt_f32_s32 */
    auto s_b_12_18 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_12_16, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4544 [F] s_b_12_19 = constant s32 2 (const) */
    /* execute.simd:4544 [D] s_b_12_20 = s_b_12_14[s_b_12_19] <= s_b_12_18 */
    auto s_b_12_20 = emitter.vector_insert(s_b_12_14, emitter.const_s32((int32_t)2ULL), s_b_12_18);
    /* execute.simd:4545 [F] s_b_12_21 = constant s32 3 (const) */
    /* execute.simd:4545 [D] s_b_12_1[s_b_12_21] */
    auto s_b_12_22 = emitter.vector_extract(s_b_12_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4545 [F] s_b_12_23 = constant u8 3 (const) */
    /* execute.simd:4545 [D] s_b_12_24 = __builtin_fcvt_f32_s32 */
    auto s_b_12_24 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_12_22, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4545 [F] s_b_12_25 = constant s32 3 (const) */
    /* execute.simd:4545 [D] s_b_12_26 = s_b_12_20[s_b_12_25] <= s_b_12_24 */
    auto s_b_12_26 = emitter.vector_insert(s_b_12_20, emitter.const_s32((int32_t)3ULL), s_b_12_24);
    /* execute.simd:4547 [F] s_b_12_27=sym_11317_3_parameter_inst.rd (const) */
    /* execute.simd:4547 [D] s_b_12_28 = (v4u32)s_b_12_26 */
    auto s_b_12_28 = emitter.reinterpret(s_b_12_26, emitter.context().types().v4u32());
    /* execute.simd:4547 [D] s_b_12_29: WriteRegBank 20:s_b_12_27 = s_b_12_28 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_28,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_28);
    /* execute.simd:4539 [F] s_b_12_30: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4548 [F] s_b_13_0=sym_11317_3_parameter_inst.size (const) */
    /* execute.simd:4548 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.simd:4548 [F] s_b_13_2 = constant u32 3 (const) */
    /* execute.simd:4548 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:4548 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_2 (const) */
    if (s_b_13_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_13,  */
  fixed_block_b_14: 
  {
    /* execute.simd:4550 [F] s_b_14_0=sym_11317_3_parameter_inst.rn (const) */
    /* execute.simd:4550 [D] s_b_14_1 = ReadRegBank 14:s_b_14_0 (v2f64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_14_2 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:4553 [F] s_b_14_3 = constant s32 0 (const) */
    /* execute.simd:4553 [D] s_b_14_1[s_b_14_3] */
    auto s_b_14_4 = emitter.vector_extract(s_b_14_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4553 [F] s_b_14_5 = constant u8 3 (const) */
    /* execute.simd:4553 [D] s_b_14_6 = __builtin_fcvt_f64_s64 */
    auto s_b_14_6 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_14_4, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4553 [F] s_b_14_7 = constant s32 0 (const) */
    /* execute.simd:4553 [D] s_b_14_8 = s_b_14_2[s_b_14_7] <= s_b_14_6 */
    auto s_b_14_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_14_6);
    /* execute.simd:4554 [F] s_b_14_9 = constant s32 1 (const) */
    /* execute.simd:4554 [D] s_b_14_1[s_b_14_9] */
    auto s_b_14_10 = emitter.vector_extract(s_b_14_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4554 [F] s_b_14_11 = constant u8 3 (const) */
    /* execute.simd:4554 [D] s_b_14_12 = __builtin_fcvt_f64_s64 */
    auto s_b_14_12 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_14_10, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4554 [F] s_b_14_13 = constant s32 1 (const) */
    /* execute.simd:4554 [D] s_b_14_14 = s_b_14_8[s_b_14_13] <= s_b_14_12 */
    auto s_b_14_14 = emitter.vector_insert(s_b_14_8, emitter.const_s32((int32_t)1ULL), s_b_14_12);
    /* execute.simd:4556 [F] s_b_14_15=sym_11317_3_parameter_inst.rd (const) */
    /* execute.simd:4556 [D] s_b_14_16 = (v2u64)s_b_14_14 */
    auto s_b_14_16 = emitter.reinterpret(s_b_14_14, emitter.context().types().v2u64());
    /* execute.simd:4556 [D] s_b_14_17: WriteRegBank 21:s_b_14_15 = s_b_14_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_16,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_16);
    /* execute.simd:4550 [F] s_b_14_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_15: 
  {
    /* execute.simd:4562 [F] s_b_15_0=sym_11317_3_parameter_inst.size (const) */
    /* execute.simd:4562 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.simd:4562 [F] s_b_15_2 = constant u32 2 (const) */
    /* execute.simd:4562 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4562 [F] s_b_15_4: If s_b_15_3: Jump b_17 else b_18 (const) */
    if (s_b_15_3) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_3,  */
  fixed_block_b_16: 
  {
    /* execute.simd:4570 [D] s_b_16_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4570 [F] s_b_16_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_17: 
  {
    /* execute.simd:4564 [F] s_b_17_0=sym_11317_3_parameter_inst.rd (const) */
    /* execute.simd:4564 [F] s_b_17_1=sym_11317_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_17_2 = ReadRegBank 9:s_b_17_1 (f32) */
    auto s_b_17_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_2,emitter.const_u8(4));
    }
    /* execute.simd:4564 [F] s_b_17_3 = constant u8 3 (const) */
    /* execute.simd:4564 [D] s_b_17_4 = __builtin_fcvt_f32_u32 */
    auto s_b_17_4 = emitter.call(__captive___builtin_fcvt_f32_u32, s_b_17_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:6201 [D] s_b_17_5 = (u64)s_b_17_4 */
    auto s_b_17_5 = emitter.zx(s_b_17_4, emitter.context().types().u64());
    /* execute.simd:6201 [D] s_b_17_6: WriteRegBank 2:s_b_17_0 = s_b_17_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_17_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_17_5);
    /* execute.simd:6202 [F] s_b_17_7 = constant u64 0 (const) */
    /* execute.simd:6202 [F] s_b_17_8: WriteRegBank 3:s_b_17_0 = s_b_17_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_17_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_18: 
  {
    /* execute.simd:4567 [F] s_b_18_0=sym_11317_3_parameter_inst.rd (const) */
    /* execute.simd:4567 [F] s_b_18_1=sym_11317_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_18_2 = ReadRegBank 11:s_b_18_1 (f64) */
    auto s_b_18_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_18_2,emitter.const_u8(8));
    }
    /* execute.simd:4567 [F] s_b_18_3 = constant u8 3 (const) */
    /* execute.simd:4567 [D] s_b_18_4 = __builtin_fcvt_f64_u64 */
    auto s_b_18_4 = emitter.call(__captive___builtin_fcvt_f64_u64, s_b_18_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:6208 [D] s_b_18_5: WriteRegBank 2:s_b_18_0 = s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_18_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_18_4);
    /* execute.simd:6209 [F] s_b_18_6 = constant u64 0 (const) */
    /* execute.simd:6209 [F] s_b_18_7: WriteRegBank 3:s_b_18_0 = s_b_18_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_18_8: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_fmov_gen(const arm64_decode_a64_CVT_FP_I&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_64199_1_temporary_value;
  auto DV_sym_64199_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_64127_1_temporary_value;
  auto DV_sym_64127_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_64178_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_64255_1_temporary_value;
  auto DV_sym_64255_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64312_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_64356_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4038 [F] s_b_0_0=sym_11758_3_parameter_inst.sf (const) */
    /* execute.simd:4038 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4038 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4038 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4038 [F] s_b_0_4=sym_11758_3_parameter_inst.type (const) */
    /* execute.simd:4038 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.simd:4038 [F] s_b_0_6 = constant u32 0 (const) */
    /* execute.simd:4038 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.simd:4038 [F] s_b_0_12=sym_11758_3_parameter_inst.rmode (const) */
    /* execute.simd:4038 [F] s_b_0_13 = (u32)s_b_0_12 (const) */
    /* execute.simd:4038 [F] s_b_0_14 = constant u32 0 (const) */
    /* execute.simd:4038 [F] s_b_0_15 = s_b_0_13==s_b_0_14 (const) */
    uint8_t s_b_0_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_0_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_17 = s_b_0_11!=s_b_0_16 (const) */
    uint8_t s_b_0_17 = ((uint8_t)(s_b_0_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_18 = s_b_0_15!=s_b_0_16 (const) */
    uint8_t s_b_0_18 = ((uint8_t)(s_b_0_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_19 = s_b_0_17&s_b_0_18 (const) */
    uint8_t s_b_0_19 = ((uint8_t)(s_b_0_17 & s_b_0_18));
    /* execute.simd:4038 [F] s_b_0_20=sym_11758_3_parameter_inst.opcode (const) */
    /* execute.simd:4038 [F] s_b_0_21 = (u32)s_b_0_20 (const) */
    /* execute.simd:4038 [F] s_b_0_22 = constant u32 7 (const) */
    /* execute.simd:4038 [F] s_b_0_23 = s_b_0_21==s_b_0_22 (const) */
    uint8_t s_b_0_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_0_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_25 = s_b_0_19!=s_b_0_24 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(s_b_0_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_26 = s_b_0_23!=s_b_0_24 (const) */
    uint8_t s_b_0_26 = ((uint8_t)(s_b_0_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_27 = s_b_0_25&s_b_0_26 (const) */
    uint8_t s_b_0_27 = ((uint8_t)(s_b_0_25 & s_b_0_26));
    /* execute.simd:4038 [F] s_b_0_28: If s_b_0_27: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2722 [F] s_b_1_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2709 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_1_4: If s_b_1_3: Jump b_14 else b_15 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_4, b_10, b_12, b_13, b_16, b_17, b_20, b_23, b_24, b_25,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4043 [F] s_b_3_0=sym_11758_3_parameter_inst.sf (const) */
    /* execute.simd:4043 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4043 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4043 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.simd:4043 [F] s_b_3_4=sym_11758_3_parameter_inst.type (const) */
    /* execute.simd:4043 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4043 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:4043 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4043 [F] s_b_3_12=sym_11758_3_parameter_inst.rmode (const) */
    /* execute.simd:4043 [F] s_b_3_13 = (u32)s_b_3_12 (const) */
    /* execute.simd:4043 [F] s_b_3_14 = constant u32 0 (const) */
    /* execute.simd:4043 [F] s_b_3_15 = s_b_3_13==s_b_3_14 (const) */
    uint8_t s_b_3_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_17 = s_b_3_11!=s_b_3_16 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(s_b_3_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_18 = s_b_3_15!=s_b_3_16 (const) */
    uint8_t s_b_3_18 = ((uint8_t)(s_b_3_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_19 = s_b_3_17&s_b_3_18 (const) */
    uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 & s_b_3_18));
    /* execute.simd:4043 [F] s_b_3_20=sym_11758_3_parameter_inst.opcode (const) */
    /* execute.simd:4043 [F] s_b_3_21 = (u32)s_b_3_20 (const) */
    /* execute.simd:4043 [F] s_b_3_22 = constant u32 6 (const) */
    /* execute.simd:4043 [F] s_b_3_23 = s_b_3_21==s_b_3_22 (const) */
    uint8_t s_b_3_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_3_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_25 = s_b_3_19!=s_b_3_24 (const) */
    uint8_t s_b_3_25 = ((uint8_t)(s_b_3_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_26 = s_b_3_23!=s_b_3_24 (const) */
    uint8_t s_b_3_26 = ((uint8_t)(s_b_3_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_27 = s_b_3_25&s_b_3_26 (const) */
    uint8_t s_b_3_27 = ((uint8_t)(s_b_3_25 & s_b_3_26));
    /* execute.simd:4043 [F] s_b_3_28: If s_b_3_27: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4045 [F] s_b_4_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.simd:4045 [D] s_b_4_1 = ReadRegBank 6:s_b_4_0 (u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(4));
    }
    /* execute.simd:4045 [D] s_b_4_2 = (u64)s_b_4_1 */
    auto s_b_4_2 = emitter.zx(s_b_4_1, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_4_3=sym_11758_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_4_4 = (u32)s_b_4_2 */
    auto s_b_4_4 = emitter.truncate(s_b_4_2, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_4_5 = (u64)s_b_4_4 */
    auto s_b_4_5 = emitter.zx(s_b_4_4, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_4_6: sym_64178_3_parameter_value = s_b_4_5, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_64178_3_parameter_value, s_b_4_5);
    /* execute.a64:2745 [F] s_b_4_7 = (u32)s_b_4_3 (const) */
    /* execute.a64:2745 [F] s_b_4_8 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_4_9 = s_b_4_7==s_b_4_8 (const) */
    uint8_t s_b_4_9 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_4_10: If s_b_4_9: Jump b_2 else b_17 (const) */
    if (s_b_4_9) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4046 [F] s_b_5_0=sym_11758_3_parameter_inst.sf (const) */
    /* execute.simd:4046 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4046 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.simd:4046 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4046 [F] s_b_5_4=sym_11758_3_parameter_inst.type (const) */
    /* execute.simd:4046 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.simd:4046 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.simd:4046 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.simd:4046 [F] s_b_5_12=sym_11758_3_parameter_inst.rmode (const) */
    /* execute.simd:4046 [F] s_b_5_13 = (u32)s_b_5_12 (const) */
    /* execute.simd:4046 [F] s_b_5_14 = constant u32 0 (const) */
    /* execute.simd:4046 [F] s_b_5_15 = s_b_5_13==s_b_5_14 (const) */
    uint8_t s_b_5_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_17 = s_b_5_11!=s_b_5_16 (const) */
    uint8_t s_b_5_17 = ((uint8_t)(s_b_5_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_18 = s_b_5_15!=s_b_5_16 (const) */
    uint8_t s_b_5_18 = ((uint8_t)(s_b_5_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_19 = s_b_5_17&s_b_5_18 (const) */
    uint8_t s_b_5_19 = ((uint8_t)(s_b_5_17 & s_b_5_18));
    /* execute.simd:4046 [F] s_b_5_20=sym_11758_3_parameter_inst.opcode (const) */
    /* execute.simd:4046 [F] s_b_5_21 = (u32)s_b_5_20 (const) */
    /* execute.simd:4046 [F] s_b_5_22 = constant u32 7 (const) */
    /* execute.simd:4046 [F] s_b_5_23 = s_b_5_21==s_b_5_22 (const) */
    uint8_t s_b_5_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_5_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_25 = s_b_5_19!=s_b_5_24 (const) */
    uint8_t s_b_5_25 = ((uint8_t)(s_b_5_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_26 = s_b_5_23!=s_b_5_24 (const) */
    uint8_t s_b_5_26 = ((uint8_t)(s_b_5_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_27 = s_b_5_25&s_b_5_26 (const) */
    uint8_t s_b_5_27 = ((uint8_t)(s_b_5_25 & s_b_5_26));
    /* execute.simd:4046 [F] s_b_5_28: If s_b_5_27: Jump b_6 else b_7 (const) */
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
    /* execute.a64:2720 [F] s_b_6_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2714 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_6_4: If s_b_6_3: Jump b_18 else b_19 (const) */
    if (s_b_6_3) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4050 [F] s_b_7_0=sym_11758_3_parameter_inst.sf (const) */
    /* execute.simd:4050 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4050 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.simd:4050 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4050 [F] s_b_7_4=sym_11758_3_parameter_inst.type (const) */
    /* execute.simd:4050 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4050 [F] s_b_7_6 = constant u32 2 (const) */
    /* execute.simd:4050 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:4050 [F] s_b_7_12=sym_11758_3_parameter_inst.rmode (const) */
    /* execute.simd:4050 [F] s_b_7_13 = (u32)s_b_7_12 (const) */
    /* execute.simd:4050 [F] s_b_7_14 = constant u32 1 (const) */
    /* execute.simd:4050 [F] s_b_7_15 = s_b_7_13==s_b_7_14 (const) */
    uint8_t s_b_7_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_7_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_17 = s_b_7_11!=s_b_7_16 (const) */
    uint8_t s_b_7_17 = ((uint8_t)(s_b_7_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_18 = s_b_7_15!=s_b_7_16 (const) */
    uint8_t s_b_7_18 = ((uint8_t)(s_b_7_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_19 = s_b_7_17&s_b_7_18 (const) */
    uint8_t s_b_7_19 = ((uint8_t)(s_b_7_17 & s_b_7_18));
    /* execute.simd:4050 [F] s_b_7_20=sym_11758_3_parameter_inst.opcode (const) */
    /* execute.simd:4050 [F] s_b_7_21 = (u32)s_b_7_20 (const) */
    /* execute.simd:4050 [F] s_b_7_22 = constant u32 7 (const) */
    /* execute.simd:4050 [F] s_b_7_23 = s_b_7_21==s_b_7_22 (const) */
    uint8_t s_b_7_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_7_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_25 = s_b_7_19!=s_b_7_24 (const) */
    uint8_t s_b_7_25 = ((uint8_t)(s_b_7_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_26 = s_b_7_23!=s_b_7_24 (const) */
    uint8_t s_b_7_26 = ((uint8_t)(s_b_7_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_27 = s_b_7_25&s_b_7_26 (const) */
    uint8_t s_b_7_27 = ((uint8_t)(s_b_7_25 & s_b_7_26));
    /* execute.simd:4050 [F] s_b_7_28: If s_b_7_27: Jump b_8 else b_9 (const) */
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
    /* execute.a64:2720 [F] s_b_8_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2714 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_8_4: If s_b_8_3: Jump b_21 else b_22 (const) */
    if (s_b_8_3) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4053 [F] s_b_9_0=sym_11758_3_parameter_inst.sf (const) */
    /* execute.simd:4053 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4053 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4053 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4053 [F] s_b_9_4=sym_11758_3_parameter_inst.type (const) */
    /* execute.simd:4053 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4053 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.simd:4053 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.simd:4053 [F] s_b_9_12=sym_11758_3_parameter_inst.rmode (const) */
    /* execute.simd:4053 [F] s_b_9_13 = (u32)s_b_9_12 (const) */
    /* execute.simd:4053 [F] s_b_9_14 = constant u32 0 (const) */
    /* execute.simd:4053 [F] s_b_9_15 = s_b_9_13==s_b_9_14 (const) */
    uint8_t s_b_9_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_9_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_17 = s_b_9_11!=s_b_9_16 (const) */
    uint8_t s_b_9_17 = ((uint8_t)(s_b_9_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_18 = s_b_9_15!=s_b_9_16 (const) */
    uint8_t s_b_9_18 = ((uint8_t)(s_b_9_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_19 = s_b_9_17&s_b_9_18 (const) */
    uint8_t s_b_9_19 = ((uint8_t)(s_b_9_17 & s_b_9_18));
    /* execute.simd:4053 [F] s_b_9_20=sym_11758_3_parameter_inst.opcode (const) */
    /* execute.simd:4053 [F] s_b_9_21 = (u32)s_b_9_20 (const) */
    /* execute.simd:4053 [F] s_b_9_22 = constant u32 6 (const) */
    /* execute.simd:4053 [F] s_b_9_23 = s_b_9_21==s_b_9_22 (const) */
    uint8_t s_b_9_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_9_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_25 = s_b_9_19!=s_b_9_24 (const) */
    uint8_t s_b_9_25 = ((uint8_t)(s_b_9_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_26 = s_b_9_23!=s_b_9_24 (const) */
    uint8_t s_b_9_26 = ((uint8_t)(s_b_9_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_27 = s_b_9_25&s_b_9_26 (const) */
    uint8_t s_b_9_27 = ((uint8_t)(s_b_9_25 & s_b_9_26));
    /* execute.simd:4053 [F] s_b_9_28: If s_b_9_27: Jump b_10 else b_11 (const) */
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
    /* execute.simd:4055 [F] s_b_10_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.simd:4055 [D] s_b_10_1 = ReadRegBank 7:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2754 [F] s_b_10_2=sym_11758_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_10_3: sym_64312_3_parameter_value = s_b_10_1, dominates: s_b_24_1  */
    emitter.store_local(DV_sym_64312_3_parameter_value, s_b_10_1);
    /* execute.a64:2745 [F] s_b_10_4 = (u32)s_b_10_2 (const) */
    /* execute.a64:2745 [F] s_b_10_5 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_10_6 = s_b_10_4==s_b_10_5 (const) */
    uint8_t s_b_10_6 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_10_7: If s_b_10_6: Jump b_2 else b_24 (const) */
    if (s_b_10_6) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4056 [F] s_b_11_0=sym_11758_3_parameter_inst.sf (const) */
    /* execute.simd:4056 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.simd:4056 [F] s_b_11_2 = constant u32 1 (const) */
    /* execute.simd:4056 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.simd:4056 [F] s_b_11_4=sym_11758_3_parameter_inst.type (const) */
    /* execute.simd:4056 [F] s_b_11_5 = (u32)s_b_11_4 (const) */
    /* execute.simd:4056 [F] s_b_11_6 = constant u32 2 (const) */
    /* execute.simd:4056 [F] s_b_11_7 = s_b_11_5==s_b_11_6 (const) */
    uint8_t s_b_11_7 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)2ULL));
    /* ???:4294967295 [F] s_b_11_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_9 = s_b_11_3!=s_b_11_8 (const) */
    uint8_t s_b_11_9 = ((uint8_t)(s_b_11_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_10 = s_b_11_7!=s_b_11_8 (const) */
    uint8_t s_b_11_10 = ((uint8_t)(s_b_11_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_11 = s_b_11_9&s_b_11_10 (const) */
    uint8_t s_b_11_11 = ((uint8_t)(s_b_11_9 & s_b_11_10));
    /* execute.simd:4056 [F] s_b_11_12=sym_11758_3_parameter_inst.rmode (const) */
    /* execute.simd:4056 [F] s_b_11_13 = (u32)s_b_11_12 (const) */
    /* execute.simd:4056 [F] s_b_11_14 = constant u32 1 (const) */
    /* execute.simd:4056 [F] s_b_11_15 = s_b_11_13==s_b_11_14 (const) */
    uint8_t s_b_11_15 = ((uint8_t)(((uint32_t)insn.rmode) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_11_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_17 = s_b_11_11!=s_b_11_16 (const) */
    uint8_t s_b_11_17 = ((uint8_t)(s_b_11_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_18 = s_b_11_15!=s_b_11_16 (const) */
    uint8_t s_b_11_18 = ((uint8_t)(s_b_11_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_19 = s_b_11_17&s_b_11_18 (const) */
    uint8_t s_b_11_19 = ((uint8_t)(s_b_11_17 & s_b_11_18));
    /* execute.simd:4056 [F] s_b_11_20=sym_11758_3_parameter_inst.opcode (const) */
    /* execute.simd:4056 [F] s_b_11_21 = (u32)s_b_11_20 (const) */
    /* execute.simd:4056 [F] s_b_11_22 = constant u32 6 (const) */
    /* execute.simd:4056 [F] s_b_11_23 = s_b_11_21==s_b_11_22 (const) */
    uint8_t s_b_11_23 = ((uint8_t)(((uint32_t)insn.opcode) == (uint32_t)6ULL));
    /* ???:4294967295 [F] s_b_11_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_11_25 = s_b_11_19!=s_b_11_24 (const) */
    uint8_t s_b_11_25 = ((uint8_t)(s_b_11_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_26 = s_b_11_23!=s_b_11_24 (const) */
    uint8_t s_b_11_26 = ((uint8_t)(s_b_11_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_11_27 = s_b_11_25&s_b_11_26 (const) */
    uint8_t s_b_11_27 = ((uint8_t)(s_b_11_25 & s_b_11_26));
    /* execute.simd:4056 [F] s_b_11_28: If s_b_11_27: Jump b_12 else b_13 (const) */
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
    /* execute.simd:4058 [F] s_b_12_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.simd:4058 [D] s_b_12_1 = ReadRegBank 3:s_b_12_0 (u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.a64:2754 [F] s_b_12_2=sym_11758_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_12_3: sym_64356_3_parameter_value = s_b_12_1, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_64356_3_parameter_value, s_b_12_1);
    /* execute.a64:2745 [F] s_b_12_4 = (u32)s_b_12_2 (const) */
    /* execute.a64:2745 [F] s_b_12_5 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_12_6 = s_b_12_4==s_b_12_5 (const) */
    uint8_t s_b_12_6 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_12_7: If s_b_12_6: Jump b_2 else b_25 (const) */
    if (s_b_12_6) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4060 [D] s_b_13_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4060 [F] s_b_13_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_14_1: sym_64127_1_temporary_value = s_b_14_0 (const), dominates: s_b_16_0  */
    CV_sym_64127_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_64127_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_14_2: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2709 [F] s_b_15_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_15_1 = ReadRegBank 1:s_b_15_0 (u32) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_15_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_15_2: sym_64127_1_temporary_value = s_b_15_1, dominates: s_b_16_0  */
    emitter.store_local(DV_sym_64127_1_temporary_value, s_b_15_1);
    /* execute.a64:2709 [F] s_b_15_3: Jump b_16 (const) */
    goto fixed_block_b_16;
  }
  /* b_14, b_15,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [D] s_b_16_0 = sym_64127_1_temporary_value uint32_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_64127_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_16_1 = (u64)s_b_16_0 */
    auto s_b_16_1 = emitter.zx(s_b_16_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_16_2=sym_11758_3_parameter_inst.rd (const) */
    /* execute.simd:4040 [D] s_b_16_3 = (u32)s_b_16_1 */
    auto s_b_16_3 = emitter.truncate(s_b_16_1, emitter.context().types().u32());
    /* execute.simd:4040 [D] s_b_16_4: WriteRegBank 6:s_b_16_2 = s_b_16_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_3,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_3);
    /* execute.simd:4041 [F] s_b_16_5=sym_11758_3_parameter_inst.rd (const) */
    /* execute.simd:4041 [F] s_b_16_6 = constant u32 0 (const) */
    /* execute.simd:4041 [F] s_b_16_7: WriteRegBank 10:s_b_16_5 = s_b_16_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:4042 [F] s_b_16_8=sym_11758_3_parameter_inst.rd (const) */
    /* execute.simd:4042 [F] s_b_16_9 = constant u64 0 (const) */
    /* execute.simd:4042 [F] s_b_16_10: WriteRegBank 3:s_b_16_8 = s_b_16_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4040 [F] s_b_16_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2747 [F] s_b_17_0=sym_11758_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_64178_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_64178_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_1);
    /* execute.a64:0 [F] s_b_17_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2714 [F] s_b_18_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_18_1: sym_64199_1_temporary_value = s_b_18_0 (const), dominates: s_b_20_0  */
    CV_sym_64199_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_64199_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_18_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_6,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2714 [F] s_b_19_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_19_1 = ReadRegBank 0:s_b_19_0 (u64) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_19_2: sym_64199_1_temporary_value = s_b_19_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_64199_1_temporary_value, s_b_19_1);
    /* execute.a64:2714 [F] s_b_19_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_18, b_19,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2714 [D] s_b_20_0 = sym_64199_1_temporary_value uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_64199_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_20_1=sym_11758_3_parameter_inst.rd (const) */
    /* execute.simd:4048 [D] s_b_20_2: WriteRegBank 7:s_b_20_1 = s_b_20_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_0,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_0);
    /* execute.simd:4049 [F] s_b_20_3=sym_11758_3_parameter_inst.rd (const) */
    /* execute.simd:4049 [F] s_b_20_4 = constant u64 0 (const) */
    /* execute.simd:4049 [F] s_b_20_5: WriteRegBank 3:s_b_20_3 = s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4048 [F] s_b_20_6: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2714 [F] s_b_21_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_21_1: sym_64255_1_temporary_value = s_b_21_0 (const), dominates: s_b_23_0  */
    CV_sym_64255_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_64255_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_21_2: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2714 [F] s_b_22_0=sym_11758_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_22_1 = ReadRegBank 0:s_b_22_0 (u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_22_2: sym_64255_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_64255_1_temporary_value, s_b_22_1);
    /* execute.a64:2714 [F] s_b_22_3: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [D] s_b_23_0 = sym_64255_1_temporary_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_64255_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_23_1=sym_11758_3_parameter_inst.rd (const) */
    /* execute.simd:4052 [D] s_b_23_2: WriteRegBank 3:s_b_23_1 = s_b_23_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_23_0,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_23_0);
    /* execute.simd:4052 [F] s_b_23_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_10,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2747 [F] s_b_24_0=sym_11758_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_24_1 = sym_64312_3_parameter_value uint64_t */
    auto s_b_24_1 = emitter.load_local(DV_sym_64312_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_24_2: WriteRegBank 0:s_b_24_0 = s_b_24_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_24_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_24_1);
    /* execute.a64:0 [F] s_b_24_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2747 [F] s_b_25_0=sym_11758_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_25_1 = sym_64356_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_64356_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_frintx(const arm64_decode_a64_FP_DP_1&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_12436_0_rmode;
  auto DV_sym_12436_0_rmode = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4593 [F] s_b_0_0=sym_12429_3_parameter_inst.opcode (const) */
    /* execute.simd:4594 [F] s_b_0_1 = constant s32 8 (const) */
    /* execute.simd:4598 [F] s_b_0_2 = constant s32 9 (const) */
    /* execute.simd:4602 [F] s_b_0_3 = constant s32 a (const) */
    /* execute.simd:4606 [F] s_b_0_4 = constant s32 b (const) */
    /* execute.simd:4610 [F] s_b_0_5 = constant s32 c (const) */
    /* execute.simd:4614 [F] s_b_0_6 = constant s32 e (const) */
    /* execute.simd:4618 [F] s_b_0_7 = constant s32 f (const) */
    /* execute.simd:4593 [F] s_b_0_8: Switch s_b_0_0: < <todo> > def b_9 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8, b_9,  */
    switch (insn.opcode) 
    {
    case (int32_t)8ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)9ULL:
      goto fixed_block_b_3;
      break;
    case (int32_t)10ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)11ULL:
      goto fixed_block_b_5;
      break;
    case (int32_t)12ULL:
      goto fixed_block_b_6;
      break;
    case (int32_t)14ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)15ULL:
      goto fixed_block_b_8;
      break;
    default:
      goto fixed_block_b_9;
    }
  }
  /* b_2, b_3, b_4, b_5, b_6, b_7, b_8, b_9,  */
  fixed_block_b_1: 
  {
    /* execute.simd:4628 [F] s_b_1_0=sym_12429_3_parameter_inst.type (const) */
    /* execute.simd:4628 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4628 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4628 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4628 [F] s_b_1_4: If s_b_1_3: Jump b_10 else b_12 (const) */
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
    /* execute.simd:4595 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:4595 [F] s_b_2_1: sym_12436_0_rmode = s_b_2_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12436_0_rmode = (uint8_t)0ULL;
    emitter.store_local(DV_sym_12436_0_rmode, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:0 [F] s_b_2_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4599 [F] s_b_3_0 = constant u8 1 (const) */
    /* execute.simd:4599 [F] s_b_3_1: sym_12436_0_rmode = s_b_3_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12436_0_rmode = (uint8_t)1ULL;
    emitter.store_local(DV_sym_12436_0_rmode, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:0 [F] s_b_3_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:4603 [F] s_b_4_0 = constant u8 2 (const) */
    /* execute.simd:4603 [F] s_b_4_1: sym_12436_0_rmode = s_b_4_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12436_0_rmode = (uint8_t)2ULL;
    emitter.store_local(DV_sym_12436_0_rmode, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:0 [F] s_b_4_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4607 [F] s_b_5_0 = constant u8 3 (const) */
    /* execute.simd:4607 [F] s_b_5_1: sym_12436_0_rmode = s_b_5_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12436_0_rmode = (uint8_t)3ULL;
    emitter.store_local(DV_sym_12436_0_rmode, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:0 [F] s_b_5_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4611 [F] s_b_6_0 = constant u8 0 (const) */
    /* execute.simd:4611 [F] s_b_6_1: sym_12436_0_rmode = s_b_6_0 (const), dominates: s_b_10_3 s_b_12_3  */
    CV_sym_12436_0_rmode = (uint8_t)0ULL;
    emitter.store_local(DV_sym_12436_0_rmode, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:0 [F] s_b_6_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4615 [D] s_b_7_0 = __builtin_get_fp_rounding */
    auto s_b_7_0 = emitter.call(__captive___builtin_get_fp_rounding);
    /* execute.simd:4615 [D] s_b_7_1 = (u8)s_b_7_0 */
    auto s_b_7_1 = emitter.truncate(s_b_7_0, emitter.context().types().u8());
    /* execute.simd:4615 [D] s_b_7_2: sym_12436_0_rmode = s_b_7_1, dominates: s_b_10_3 s_b_12_3  */
    emitter.store_local(DV_sym_12436_0_rmode, s_b_7_1);
    /* execute.simd:0 [F] s_b_7_3: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4619 [D] s_b_8_0 = __builtin_get_fp_rounding */
    auto s_b_8_0 = emitter.call(__captive___builtin_get_fp_rounding);
    /* execute.simd:4619 [D] s_b_8_1 = (u8)s_b_8_0 */
    auto s_b_8_1 = emitter.truncate(s_b_8_0, emitter.context().types().u8());
    /* execute.simd:4619 [D] s_b_8_2: sym_12436_0_rmode = s_b_8_1, dominates: s_b_10_3 s_b_12_3  */
    emitter.store_local(DV_sym_12436_0_rmode, s_b_8_1);
    /* execute.simd:0 [F] s_b_8_3: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4623 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_9_1: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4629 [F] s_b_10_0=sym_12429_3_parameter_inst.rn (const) */
    /* execute.simd:6162 [D] s_b_10_1 = ReadRegBank 9:s_b_10_0 (f32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(4));
    }
    /* execute.simd:4630 [F] s_b_10_2=sym_12429_3_parameter_inst.rd (const) */
    /* execute.simd:4630 [D] s_b_10_3 = sym_12436_0_rmode uint8_t */
    auto s_b_10_3 = emitter.load_local(DV_sym_12436_0_rmode, emitter.context().types().u8());
    /* execute.simd:4630 [D] s_b_10_4 = __builtin_f32_round */
    auto s_b_10_4 = emitter.call(__captive___builtin_f32_round, s_b_10_1, s_b_10_3);
    /* execute.simd:6172 [D] s_b_10_5: WriteRegBank 9:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4);
    /* execute.simd:6173 [F] s_b_10_6 = constant u32 0 (const) */
    /* execute.simd:6173 [F] s_b_10_7: WriteRegBank 10:s_b_10_2 = s_b_10_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6174 [F] s_b_10_8 = constant u64 0 (const) */
    /* execute.simd:6174 [F] s_b_10_9: WriteRegBank 3:s_b_10_2 = s_b_10_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:4632 [F] s_b_12_0=sym_12429_3_parameter_inst.rn (const) */
    /* execute.simd:6167 [D] s_b_12_1 = ReadRegBank 11:s_b_12_0 (f64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:4633 [F] s_b_12_2=sym_12429_3_parameter_inst.rd (const) */
    /* execute.simd:4633 [D] s_b_12_3 = sym_12436_0_rmode uint8_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_12436_0_rmode, emitter.context().types().u8());
    /* execute.simd:4633 [D] s_b_12_4 = __builtin_f64_round */
    auto s_b_12_4 = emitter.call(__captive___builtin_f64_round, s_b_12_1, s_b_12_3);
    /* execute.simd:6180 [D] s_b_12_5: WriteRegBank 11:s_b_12_2 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_4);
    /* execute.simd:6181 [F] s_b_12_6 = constant u64 0 (const) */
    /* execute.simd:6181 [F] s_b_12_7: WriteRegBank 3:s_b_12_2 = s_b_12_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ld1pi(const arm64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_66011_3_parameter_lane;
  auto DV_sym_66073_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_12982_0_rt;
  auto DV_sym_66056_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_65951_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66003_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_66005_3_parameter_rt;
  auto DV_sym_66001_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66090_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_66022_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_66107_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66039_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_66328_1__R_s_b_33_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_66132_1_tmp_s_b_5_4;
  auto DV_sym_66135_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66181_1__R_s_b_7_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66200_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_66385_1_temporary_value;
  auto DV_sym_66385_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66256_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66402_1_tmp_s_b_37_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66414_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13002_0_lane;
  auto DV_sym_12976_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_12970_3_parameter_inst.rn (const) */
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
    /* execute.simd:2489 [F] s_b_1_0 = sym_12982_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_12982_0_rt;
    /* execute.simd:2489 [F] s_b_1_1=sym_12970_3_parameter_inst.regcnt (const) */
    /* execute.simd:2489 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2489 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2490 [F] s_b_2_0=sym_12970_3_parameter_inst.rt (const) */
    /* execute.simd:2490 [F] s_b_2_1 = sym_12982_0_rt (const) uint8_t */
    uint8_t s_b_2_1 = CV_sym_12982_0_rt;
    /* execute.simd:2490 [F] s_b_2_2 = s_b_2_0+s_b_2_1 (const) */
    uint8_t s_b_2_2 = ((uint8_t)(insn.rt + s_b_2_1));
    /* execute.simd:2490 [F] s_b_2_3 = constant u64 0 (const) */
    /* execute.simd:2490 [F] s_b_2_4 = constant u64 0 (const) */
    /* execute.simd:6215 [F] s_b_2_5: WriteRegBank 2:s_b_2_2 = s_b_2_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6216 [F] s_b_2_6: WriteRegBank 3:s_b_2_2 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * s_b_2_2))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2491 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:2491 [F] s_b_2_8: sym_13002_0_lane = s_b_2_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_13002_0_lane = (uint8_t)0ULL;
    /* execute.simd:2491 [F] s_b_2_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2497 [F] s_b_3_0=sym_12970_3_parameter_inst.rm (const) */
    /* execute.simd:2497 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2497 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2497 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2497 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2491 [F] s_b_4_0 = sym_13002_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13002_0_lane;
    /* execute.simd:2491 [F] s_b_4_1=sym_12970_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2491 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2491 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2492 [F] s_b_5_0=sym_12970_3_parameter_inst.arrangement (const) */
    /* execute.simd:2492 [F] s_b_5_1=sym_12970_3_parameter_inst.rt (const) */
    /* execute.simd:2492 [F] s_b_5_2 = sym_12982_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_12982_0_rt;
    /* execute.simd:2492 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2492 [F] s_b_5_4 = sym_13002_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13002_0_lane;
    /* execute.simd:2492 [D] s_b_5_5 = sym_12976_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_12976_0_address, emitter.context().types().u64());
    /* execute.simd:2492 [F] s_b_5_6: sym_66005_3_parameter_rt = s_b_5_3 (const), dominates: s_b_17_2 s_b_15_2 s_b_14_2 s_b_13_2 s_b_16_2 s_b_18_2 s_b_12_2  */
    CV_sym_66005_3_parameter_rt = s_b_5_3;
    /* execute.simd:2492 [F] s_b_5_7: sym_66011_3_parameter_lane = s_b_5_4 (const), dominates: s_b_17_5 s_b_15_5 s_b_14_5 s_b_13_5 s_b_16_5 s_b_18_5 s_b_12_5  */
    CV_sym_66011_3_parameter_lane = s_b_5_4;
    /* execute.simd:2492 [D] s_b_5_8: sym_66001_3_parameter_addr = s_b_5_5, dominates: s_b_17_0 s_b_15_0 s_b_14_0 s_b_13_0 s_b_16_0 s_b_18_0 s_b_12_0  */
    emitter.store_local(DV_sym_66001_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_66132_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_19_1  */
    CV_sym_66132_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_66135_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_66135_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3770 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3779 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3788 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3797 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3806 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3815 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3824 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3769 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_11 (const) -> b_17, b_15, b_14, b_13, b_16, b_18, b_12, b_11,  */
    switch (insn.arrangement) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_14;
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
    /* execute.simd:2489 [F] s_b_6_0 = sym_12982_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_12982_0_rt;
    /* execute.simd:2489 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2489 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2489 [F] s_b_6_3: sym_12982_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_12982_0_rt = s_b_6_2;
    /* execute.simd:2489 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2793 [F] s_b_7_0=sym_12970_3_parameter_inst.rn (const) */
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
    /* execute.simd:2501 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2501 [D] s_b_8_1 = sym_12976_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_12976_0_address, emitter.context().types().u64());
    /* execute.simd:2501 [D] s_b_8_2: sym_66200_3_parameter_value = s_b_8_1, dominates: s_b_22_0 s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_66200_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2796 [F] s_b_9_0=sym_12970_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_9_2: sym_65951_1__R_s_b_0_5 = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_65951_1__R_s_b_0_5, s_b_9_1);
    /* execute.a64:2796 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_31,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2487 [D] s_b_10_0 = sym_65951_1__R_s_b_0_5 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_65951_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2487 [D] s_b_10_1: sym_12976_0_address = s_b_10_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_12976_0_address, s_b_10_0);
    /* execute.simd:2489 [F] s_b_10_2 = constant u8 0 (const) */
    /* execute.simd:2489 [F] s_b_10_3: sym_12982_0_rt = s_b_10_2 (const), dominates: s_b_1_0 s_b_2_1 s_b_5_2 s_b_6_0  */
    CV_sym_12982_0_rt = (uint8_t)0ULL;
    /* execute.simd:2489 [F] s_b_10_4: Jump b_1 (const) */
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
    /* execute.simd:3799 [D] s_b_12_0 = sym_66001_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_66001_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_66056_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66056_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3801 [F] s_b_12_2 = sym_66005_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_66005_3_parameter_rt;
    /* execute.simd:3801 [D] s_b_12_3 = ReadRegBank 18:s_b_12_2 (v8u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(16));
    }
    /* execute.simd:3802 [D] s_b_12_4 = sym_66056_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_66056_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3802 [F] s_b_12_5 = sym_66011_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_66011_3_parameter_lane;
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
    /* execute.simd:3781 [D] s_b_13_0 = sym_66001_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_66001_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 1 s_b_13_0 => sym_66022_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66022_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(1));
    }
    /* execute.simd:3783 [F] s_b_13_2 = sym_66005_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_66005_3_parameter_rt;
    /* execute.simd:3783 [D] s_b_13_3 = ReadRegBank 16:s_b_13_2 (v16u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3784 [D] s_b_13_4 = sym_66022_0_mem_value uint8_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_66022_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3784 [F] s_b_13_5 = sym_66011_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_66011_3_parameter_lane;
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
    /* execute.simd:3772 [D] s_b_14_0 = sym_66001_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_66001_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 1 s_b_14_0 => sym_66003_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66003_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(1));
    }
    /* execute.simd:3774 [F] s_b_14_2 = sym_66005_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_66005_3_parameter_rt;
    /* execute.simd:3774 [D] s_b_14_3 = ReadRegBank 15:s_b_14_2 (v8u8) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3775 [D] s_b_14_4 = sym_66003_0_mem_value uint8_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_66003_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3775 [F] s_b_14_5 = sym_66011_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_66011_3_parameter_lane;
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
    /* execute.simd:3790 [D] s_b_15_0 = sym_66001_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_66001_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_66039_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66039_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3792 [F] s_b_15_2 = sym_66005_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_66005_3_parameter_rt;
    /* execute.simd:3792 [D] s_b_15_3 = ReadRegBank 17:s_b_15_2 (v4u16) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(8));
    }
    /* execute.simd:3793 [D] s_b_15_4 = sym_66039_0_mem_value uint16_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_66039_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3793 [F] s_b_15_5 = sym_66011_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_66011_3_parameter_lane;
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
    /* execute.simd:3817 [D] s_b_16_0 = sym_66001_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_66001_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 4 s_b_16_0 => sym_66090_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_66090_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(4));
    }
    /* execute.simd:3819 [F] s_b_16_2 = sym_66005_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_66005_3_parameter_rt;
    /* execute.simd:3819 [D] s_b_16_3 = ReadRegBank 20:s_b_16_2 (v4u32) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3820 [D] s_b_16_4 = sym_66090_0_mem_value uint32_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_66090_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3820 [F] s_b_16_5 = sym_66011_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_66011_3_parameter_lane;
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
    /* execute.simd:3808 [D] s_b_17_0 = sym_66001_3_parameter_addr uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_66001_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_66073_0_mem_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_66073_0_mem_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3810 [F] s_b_17_2 = sym_66005_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_2 = CV_sym_66005_3_parameter_rt;
    /* execute.simd:3810 [D] s_b_17_3 = ReadRegBank 19:s_b_17_2 (v2u32) */
    auto s_b_17_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_3,emitter.const_u8(8));
    }
    /* execute.simd:3811 [D] s_b_17_4 = sym_66073_0_mem_value uint32_t */
    auto s_b_17_4 = emitter.load_local(DV_sym_66073_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3811 [F] s_b_17_5 = sym_66011_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_5 = CV_sym_66011_3_parameter_lane;
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
    /* execute.simd:3826 [D] s_b_18_0 = sym_66001_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_66001_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 8 s_b_18_0 => sym_66107_0_mem_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_66107_0_mem_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(8));
    }
    /* execute.simd:3828 [F] s_b_18_2 = sym_66005_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_2 = CV_sym_66005_3_parameter_rt;
    /* execute.simd:3828 [D] s_b_18_3 = ReadRegBank 21:s_b_18_2 (v2u64) */
    auto s_b_18_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_3,emitter.const_u8(16));
    }
    /* execute.simd:3829 [D] s_b_18_4 = sym_66107_0_mem_value uint64_t */
    auto s_b_18_4 = emitter.load_local(DV_sym_66107_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3829 [F] s_b_18_5 = sym_66011_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_5 = CV_sym_66011_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_19_0 = sym_66135_1_tmp_s_b_5_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_66135_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1 = sym_66132_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_19_1 = CV_sym_66132_1_tmp_s_b_5_4;
    /* execute.simd:2493 [F] s_b_19_2=sym_12970_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_19_3 = (u64)s_b_19_2 (const) */
    /* ???:4294967295 [D] s_b_19_4 = s_b_19_0+s_b_19_3 */
    auto s_b_19_4 = emitter.add(s_b_19_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2493 [D] s_b_19_5: sym_12976_0_address = s_b_19_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_12976_0_address, s_b_19_4);
    /* execute.simd:2491 [F] s_b_19_6 = constant u8 1 (const) */
    /* execute.simd:2491 [F] s_b_19_7 = s_b_19_1+s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(s_b_19_1 + (uint8_t)1ULL));
    /* execute.simd:2491 [F] s_b_19_8: sym_13002_0_lane = s_b_19_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_13002_0_lane = s_b_19_7;
    /* execute.simd:2491 [F] s_b_19_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2796 [F] s_b_20_0=sym_12970_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_20_2: sym_66181_1__R_s_b_7_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_66181_1__R_s_b_7_5, s_b_20_1);
    /* execute.a64:2796 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_36,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2498 [D] s_b_21_0 = sym_66181_1__R_s_b_7_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_66181_1__R_s_b_7_5, emitter.context().types().u64());
    /* execute.simd:2498 [F] s_b_21_1=sym_12970_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_21_2: sym_66402_1_tmp_s_b_37_0 = s_b_21_0, dominates: s_b_39_1  */
    emitter.store_local(DV_sym_66402_1_tmp_s_b_37_0, s_b_21_0);
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
    /* execute.a64:2810 [D] s_b_22_0 = sym_66200_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_66200_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_22_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_22_2 = s_b_22_0&s_b_22_1 */
    auto s_b_22_2 = emitter.bitwise_and(s_b_22_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_22_3: sym_66200_3_parameter_value = s_b_22_2, dominates: s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_66200_3_parameter_value, s_b_22_2);
    /* execute.a64:2810 [F] s_b_22_4: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2813 [F] s_b_23_0=sym_12970_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_24_0 = sym_66200_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_66200_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_24_1: sym_66414_3_parameter_value = s_b_24_0, dominates: s_b_40_0 s_b_41_0 s_b_42_0  */
    emitter.store_local(DV_sym_66414_3_parameter_value, s_b_24_0);
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
    /* execute.a64:2816 [F] s_b_25_0=sym_12970_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_25_1 = sym_66200_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_66200_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2765 [D] s_b_28_1: sym_66256_1__R_s_b_12_0 = s_b_28_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_66256_1__R_s_b_12_0, s_b_28_0);
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
    /* execute.a64:2768 [D] s_b_29_1: sym_66256_1__R_s_b_12_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_66256_1__R_s_b_12_0, s_b_29_0);
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
    /* execute.a64:2770 [D] s_b_30_1: sym_66256_1__R_s_b_12_0 = s_b_30_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_66256_1__R_s_b_12_0, s_b_30_0);
    /* execute.a64:2770 [F] s_b_30_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_28, b_29, b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2794 [D] s_b_31_0 = sym_66256_1__R_s_b_12_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_66256_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_31_1: sym_65951_1__R_s_b_0_5 = s_b_31_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_65951_1__R_s_b_0_5, s_b_31_0);
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
    /* execute.a64:2765 [D] s_b_33_1: sym_66328_1__R_s_b_33_0 = s_b_33_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_66328_1__R_s_b_33_0, s_b_33_0);
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
    /* execute.a64:2768 [D] s_b_34_1: sym_66328_1__R_s_b_33_0 = s_b_34_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_66328_1__R_s_b_33_0, s_b_34_0);
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
    /* execute.a64:2770 [D] s_b_35_1: sym_66328_1__R_s_b_33_0 = s_b_35_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_66328_1__R_s_b_33_0, s_b_35_0);
    /* execute.a64:2770 [F] s_b_35_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_33, b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2794 [D] s_b_36_0 = sym_66328_1__R_s_b_33_0 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_66328_1__R_s_b_33_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_36_1: sym_66181_1__R_s_b_7_5 = s_b_36_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_66181_1__R_s_b_7_5, s_b_36_0);
    /* execute.a64:2794 [F] s_b_36_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_21,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2714 [F] s_b_37_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_37_1: sym_66385_1_temporary_value = s_b_37_0 (const), dominates: s_b_39_0  */
    CV_sym_66385_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_66385_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_37_2: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_21,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2714 [F] s_b_38_0=sym_12970_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_38_1 = ReadRegBank 0:s_b_38_0 (u64) */
    auto s_b_38_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_38_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_38_2: sym_66385_1_temporary_value = s_b_38_1, dominates: s_b_39_0  */
    emitter.store_local(DV_sym_66385_1_temporary_value, s_b_38_1);
    /* execute.a64:2714 [F] s_b_38_3: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_37, b_38,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2714 [D] s_b_39_0 = sym_66385_1_temporary_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_66385_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_39_1 = sym_66402_1_tmp_s_b_37_0 uint64_t */
    auto s_b_39_1 = emitter.load_local(DV_sym_66402_1_tmp_s_b_37_0, emitter.context().types().u64());
    /* execute.simd:2498 [D] s_b_39_2 = s_b_39_1+s_b_39_0 */
    auto s_b_39_2 = emitter.add(s_b_39_1, s_b_39_0);
    /* execute.simd:2498 [D] s_b_39_3: sym_12976_0_address = s_b_39_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_12976_0_address, s_b_39_2);
    /* execute.simd:2498 [F] s_b_39_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_24,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2778 [D] s_b_40_0 = sym_66414_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_66414_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_41_0 = sym_66414_3_parameter_value uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_66414_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_42_0 = sym_66414_3_parameter_value uint64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_66414_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ld4pi(const arm64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_69503_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_69528_1_tmp_s_b_5_2;
  auto DV_sym_69531_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69652_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69577_1__R_s_b_7_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69596_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_69798_1_temporary_value;
  auto DV_sym_69798_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69741_1__R_s_b_31_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69486_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_69469_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_69397_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69815_1_tmp_s_b_35_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_69452_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_69399_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_69401_3_parameter_rt;
  auto DV_sym_69418_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_69407_3_parameter_lane;
  auto DV_sym_69435_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_69364_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13827_0_rt;
  auto DV_sym_13770_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13815_0_lane;
  auto DV_sym_69827_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_13764_3_parameter_inst.rn (const) */
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
    /* execute.simd:2556 [F] s_b_1_0 = sym_13815_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13815_0_lane;
    /* execute.simd:2556 [F] s_b_1_1=sym_13764_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2556 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2556 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2557 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2557 [F] s_b_2_1: sym_13827_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13827_0_rt = (uint8_t)0ULL;
    /* execute.simd:2557 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2563 [F] s_b_3_0=sym_13764_3_parameter_inst.rm (const) */
    /* execute.simd:2563 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2563 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2563 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2563 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2557 [F] s_b_4_0 = sym_13827_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13827_0_rt;
    /* execute.simd:2557 [F] s_b_4_1=sym_13764_3_parameter_inst.regcnt (const) */
    /* execute.simd:2557 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2557 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2558 [F] s_b_5_0=sym_13764_3_parameter_inst.arrangement (const) */
    /* execute.simd:2558 [F] s_b_5_1=sym_13764_3_parameter_inst.rt (const) */
    /* execute.simd:2558 [F] s_b_5_2 = sym_13827_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13827_0_rt;
    /* execute.simd:2558 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2558 [F] s_b_5_4 = sym_13815_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13815_0_lane;
    /* execute.simd:2558 [D] s_b_5_5 = sym_13770_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13770_0_address, emitter.context().types().u64());
    /* execute.simd:2558 [F] s_b_5_6: sym_69401_3_parameter_rt = s_b_5_3 (const), dominates: s_b_17_2 s_b_18_2 s_b_13_2 s_b_14_2 s_b_15_2 s_b_16_2 s_b_12_2  */
    CV_sym_69401_3_parameter_rt = s_b_5_3;
    /* execute.simd:2558 [F] s_b_5_7: sym_69407_3_parameter_lane = s_b_5_4 (const), dominates: s_b_17_5 s_b_18_5 s_b_13_5 s_b_14_5 s_b_15_5 s_b_16_5 s_b_12_5  */
    CV_sym_69407_3_parameter_lane = s_b_5_4;
    /* execute.simd:2558 [D] s_b_5_8: sym_69397_3_parameter_addr = s_b_5_5, dominates: s_b_17_0 s_b_18_0 s_b_13_0 s_b_14_0 s_b_15_0 s_b_16_0 s_b_12_0  */
    emitter.store_local(DV_sym_69397_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_69528_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_19_1  */
    CV_sym_69528_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_69531_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_69531_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3770 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3779 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3788 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3797 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3806 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3815 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3824 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3769 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_11 (const) -> b_11, b_17, b_18, b_13, b_14, b_15, b_16, b_12,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_16;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_17;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_15;
      break;
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2556 [F] s_b_6_0 = sym_13815_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13815_0_lane;
    /* execute.simd:2556 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2556 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2556 [F] s_b_6_3: sym_13815_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13815_0_lane = s_b_6_2;
    /* execute.simd:2556 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2793 [F] s_b_7_0=sym_13764_3_parameter_inst.rn (const) */
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
    /* execute.simd:2567 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2567 [D] s_b_8_1 = sym_13770_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_13770_0_address, emitter.context().types().u64());
    /* execute.simd:2567 [D] s_b_8_2: sym_69596_3_parameter_value = s_b_8_1, dominates: s_b_22_0 s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_69596_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2796 [F] s_b_9_0=sym_13764_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_9_2: sym_69364_1__R_s_b_0_5 = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_69364_1__R_s_b_0_5, s_b_9_1);
    /* execute.a64:2796 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_31,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2549 [D] s_b_10_0 = sym_69364_1__R_s_b_0_5 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_69364_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2549 [D] s_b_10_1: sym_13770_0_address = s_b_10_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13770_0_address, s_b_10_0);
    /* execute.simd:2551 [F] s_b_10_2=sym_13764_3_parameter_inst.rt (const) */
    /* execute.simd:2551 [F] s_b_10_3 = constant u64 0 (const) */
    /* execute.simd:2551 [F] s_b_10_4 = constant u64 0 (const) */
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
    /* execute.simd:2552 [F] s_b_10_7=sym_13764_3_parameter_inst.rt (const) */
    /* execute.simd:2552 [F] s_b_10_8 = (u32)s_b_10_7 (const) */
    /* execute.simd:2552 [F] s_b_10_9 = constant u32 1 (const) */
    /* execute.simd:2552 [F] s_b_10_10 = s_b_10_8+s_b_10_9 (const) */
    uint32_t s_b_10_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2552 [F] s_b_10_11 = (u8)s_b_10_10 (const) */
    /* execute.simd:2552 [F] s_b_10_12 = constant u64 0 (const) */
    /* execute.simd:2552 [F] s_b_10_13 = constant u64 0 (const) */
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
    /* execute.simd:2553 [F] s_b_10_16=sym_13764_3_parameter_inst.rt (const) */
    /* execute.simd:2553 [F] s_b_10_17 = (u32)s_b_10_16 (const) */
    /* execute.simd:2553 [F] s_b_10_18 = constant u32 2 (const) */
    /* execute.simd:2553 [F] s_b_10_19 = s_b_10_17+s_b_10_18 (const) */
    uint32_t s_b_10_19 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)2ULL));
    /* execute.simd:2553 [F] s_b_10_20 = (u8)s_b_10_19 (const) */
    /* execute.simd:2553 [F] s_b_10_21 = constant u64 0 (const) */
    /* execute.simd:2553 [F] s_b_10_22 = constant u64 0 (const) */
    /* execute.simd:6215 [F] s_b_10_23: WriteRegBank 2:s_b_10_20 = s_b_10_21 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6216 [F] s_b_10_24: WriteRegBank 3:s_b_10_20 = s_b_10_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2554 [F] s_b_10_25=sym_13764_3_parameter_inst.rt (const) */
    /* execute.simd:2554 [F] s_b_10_26 = (u32)s_b_10_25 (const) */
    /* execute.simd:2554 [F] s_b_10_27 = constant u32 3 (const) */
    /* execute.simd:2554 [F] s_b_10_28 = s_b_10_26+s_b_10_27 (const) */
    uint32_t s_b_10_28 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)3ULL));
    /* execute.simd:2554 [F] s_b_10_29 = (u8)s_b_10_28 (const) */
    /* execute.simd:2554 [F] s_b_10_30 = constant u64 0 (const) */
    /* execute.simd:2554 [F] s_b_10_31 = constant u64 0 (const) */
    /* execute.simd:6215 [F] s_b_10_32: WriteRegBank 2:s_b_10_29 = s_b_10_30 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6216 [F] s_b_10_33: WriteRegBank 3:s_b_10_29 = s_b_10_31 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_28)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_28)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2556 [F] s_b_10_34 = constant u8 0 (const) */
    /* execute.simd:2556 [F] s_b_10_35: sym_13815_0_lane = s_b_10_34 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13815_0_lane = (uint8_t)0ULL;
    /* execute.simd:2556 [F] s_b_10_36: Jump b_1 (const) */
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
    /* execute.simd:3799 [D] s_b_12_0 = sym_69397_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_69397_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 2 s_b_12_0 => sym_69452_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_69452_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(2));
    }
    /* execute.simd:3801 [F] s_b_12_2 = sym_69401_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_69401_3_parameter_rt;
    /* execute.simd:3801 [D] s_b_12_3 = ReadRegBank 18:s_b_12_2 (v8u16) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(16));
    }
    /* execute.simd:3802 [D] s_b_12_4 = sym_69452_0_mem_value uint16_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_69452_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3802 [F] s_b_12_5 = sym_69407_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_69407_3_parameter_lane;
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
    /* execute.simd:3781 [D] s_b_13_0 = sym_69397_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_69397_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 1 s_b_13_0 => sym_69418_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_69418_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(1));
    }
    /* execute.simd:3783 [F] s_b_13_2 = sym_69401_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_69401_3_parameter_rt;
    /* execute.simd:3783 [D] s_b_13_3 = ReadRegBank 16:s_b_13_2 (v16u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3784 [D] s_b_13_4 = sym_69418_0_mem_value uint8_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_69418_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3784 [F] s_b_13_5 = sym_69407_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_69407_3_parameter_lane;
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
    /* execute.simd:3772 [D] s_b_14_0 = sym_69397_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_69397_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 1 s_b_14_0 => sym_69399_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_69399_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(1));
    }
    /* execute.simd:3774 [F] s_b_14_2 = sym_69401_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_69401_3_parameter_rt;
    /* execute.simd:3774 [D] s_b_14_3 = ReadRegBank 15:s_b_14_2 (v8u8) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3775 [D] s_b_14_4 = sym_69399_0_mem_value uint8_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_69399_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3775 [F] s_b_14_5 = sym_69407_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_69407_3_parameter_lane;
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
    /* execute.simd:3790 [D] s_b_15_0 = sym_69397_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_69397_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_69435_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_69435_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3792 [F] s_b_15_2 = sym_69401_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_69401_3_parameter_rt;
    /* execute.simd:3792 [D] s_b_15_3 = ReadRegBank 17:s_b_15_2 (v4u16) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(8));
    }
    /* execute.simd:3793 [D] s_b_15_4 = sym_69435_0_mem_value uint16_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_69435_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3793 [F] s_b_15_5 = sym_69407_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_69407_3_parameter_lane;
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
    /* execute.simd:3817 [D] s_b_16_0 = sym_69397_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_69397_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 4 s_b_16_0 => sym_69486_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_69486_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(4));
    }
    /* execute.simd:3819 [F] s_b_16_2 = sym_69401_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_69401_3_parameter_rt;
    /* execute.simd:3819 [D] s_b_16_3 = ReadRegBank 20:s_b_16_2 (v4u32) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(16));
    }
    /* execute.simd:3820 [D] s_b_16_4 = sym_69486_0_mem_value uint32_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_69486_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3820 [F] s_b_16_5 = sym_69407_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_69407_3_parameter_lane;
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
    /* execute.simd:3808 [D] s_b_17_0 = sym_69397_3_parameter_addr uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_69397_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_69469_0_mem_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_69469_0_mem_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3810 [F] s_b_17_2 = sym_69401_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_2 = CV_sym_69401_3_parameter_rt;
    /* execute.simd:3810 [D] s_b_17_3 = ReadRegBank 19:s_b_17_2 (v2u32) */
    auto s_b_17_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_3,emitter.const_u8(8));
    }
    /* execute.simd:3811 [D] s_b_17_4 = sym_69469_0_mem_value uint32_t */
    auto s_b_17_4 = emitter.load_local(DV_sym_69469_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3811 [F] s_b_17_5 = sym_69407_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_5 = CV_sym_69407_3_parameter_lane;
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
    /* execute.simd:3826 [D] s_b_18_0 = sym_69397_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_69397_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 8 s_b_18_0 => sym_69503_0_mem_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_69503_0_mem_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(8));
    }
    /* execute.simd:3828 [F] s_b_18_2 = sym_69401_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_2 = CV_sym_69401_3_parameter_rt;
    /* execute.simd:3828 [D] s_b_18_3 = ReadRegBank 21:s_b_18_2 (v2u64) */
    auto s_b_18_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_3,emitter.const_u8(16));
    }
    /* execute.simd:3829 [D] s_b_18_4 = sym_69503_0_mem_value uint64_t */
    auto s_b_18_4 = emitter.load_local(DV_sym_69503_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3829 [F] s_b_18_5 = sym_69407_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_5 = CV_sym_69407_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_19_0 = sym_69531_1_tmp_s_b_5_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_69531_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1 = sym_69528_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_19_1 = CV_sym_69528_1_tmp_s_b_5_2;
    /* execute.simd:2559 [F] s_b_19_2=sym_13764_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_19_3 = (u64)s_b_19_2 (const) */
    /* ???:4294967295 [D] s_b_19_4 = s_b_19_0+s_b_19_3 */
    auto s_b_19_4 = emitter.add(s_b_19_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2559 [D] s_b_19_5: sym_13770_0_address = s_b_19_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13770_0_address, s_b_19_4);
    /* execute.simd:2557 [F] s_b_19_6 = constant u8 1 (const) */
    /* execute.simd:2557 [F] s_b_19_7 = s_b_19_1+s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(s_b_19_1 + (uint8_t)1ULL));
    /* execute.simd:2557 [F] s_b_19_8: sym_13827_0_rt = s_b_19_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13827_0_rt = s_b_19_7;
    /* execute.simd:2557 [F] s_b_19_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2796 [F] s_b_20_0=sym_13764_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_20_2: sym_69577_1__R_s_b_7_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_69577_1__R_s_b_7_5, s_b_20_1);
    /* execute.a64:2796 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_36,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2564 [D] s_b_21_0 = sym_69577_1__R_s_b_7_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_69577_1__R_s_b_7_5, emitter.context().types().u64());
    /* execute.simd:2564 [F] s_b_21_1=sym_13764_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_21_2: sym_69815_1_tmp_s_b_35_0 = s_b_21_0, dominates: s_b_39_1  */
    emitter.store_local(DV_sym_69815_1_tmp_s_b_35_0, s_b_21_0);
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
    /* execute.a64:2810 [D] s_b_22_0 = sym_69596_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_69596_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_22_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_22_2 = s_b_22_0&s_b_22_1 */
    auto s_b_22_2 = emitter.bitwise_and(s_b_22_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_22_3: sym_69596_3_parameter_value = s_b_22_2, dominates: s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_69596_3_parameter_value, s_b_22_2);
    /* execute.a64:2810 [F] s_b_22_4: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2813 [F] s_b_23_0=sym_13764_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_24_0 = sym_69596_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_69596_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_24_1: sym_69827_3_parameter_value = s_b_24_0, dominates: s_b_40_0 s_b_41_0 s_b_42_0  */
    emitter.store_local(DV_sym_69827_3_parameter_value, s_b_24_0);
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
    /* execute.a64:2816 [F] s_b_25_0=sym_13764_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_25_1 = sym_69596_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_69596_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2765 [D] s_b_28_1: sym_69652_1__R_s_b_12_0 = s_b_28_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_69652_1__R_s_b_12_0, s_b_28_0);
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
    /* execute.a64:2768 [D] s_b_29_1: sym_69652_1__R_s_b_12_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_69652_1__R_s_b_12_0, s_b_29_0);
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
    /* execute.a64:2770 [D] s_b_30_1: sym_69652_1__R_s_b_12_0 = s_b_30_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_69652_1__R_s_b_12_0, s_b_30_0);
    /* execute.a64:2770 [F] s_b_30_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_28, b_29, b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2794 [D] s_b_31_0 = sym_69652_1__R_s_b_12_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_69652_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_31_1: sym_69364_1__R_s_b_0_5 = s_b_31_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_69364_1__R_s_b_0_5, s_b_31_0);
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
    /* execute.a64:2765 [D] s_b_33_1: sym_69741_1__R_s_b_31_0 = s_b_33_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_69741_1__R_s_b_31_0, s_b_33_0);
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
    /* execute.a64:2768 [D] s_b_34_1: sym_69741_1__R_s_b_31_0 = s_b_34_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_69741_1__R_s_b_31_0, s_b_34_0);
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
    /* execute.a64:2770 [D] s_b_35_1: sym_69741_1__R_s_b_31_0 = s_b_35_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_69741_1__R_s_b_31_0, s_b_35_0);
    /* execute.a64:2770 [F] s_b_35_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_33, b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2794 [D] s_b_36_0 = sym_69741_1__R_s_b_31_0 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_69741_1__R_s_b_31_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_36_1: sym_69577_1__R_s_b_7_5 = s_b_36_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_69577_1__R_s_b_7_5, s_b_36_0);
    /* execute.a64:2794 [F] s_b_36_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_21,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2714 [F] s_b_37_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_37_1: sym_69798_1_temporary_value = s_b_37_0 (const), dominates: s_b_39_0  */
    CV_sym_69798_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_69798_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_37_2: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_21,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2714 [F] s_b_38_0=sym_13764_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_38_1 = ReadRegBank 0:s_b_38_0 (u64) */
    auto s_b_38_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_38_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_38_2: sym_69798_1_temporary_value = s_b_38_1, dominates: s_b_39_0  */
    emitter.store_local(DV_sym_69798_1_temporary_value, s_b_38_1);
    /* execute.a64:2714 [F] s_b_38_3: Jump b_39 (const) */
    goto fixed_block_b_39;
  }
  /* b_37, b_38,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2714 [D] s_b_39_0 = sym_69798_1_temporary_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_69798_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_39_1 = sym_69815_1_tmp_s_b_35_0 uint64_t */
    auto s_b_39_1 = emitter.load_local(DV_sym_69815_1_tmp_s_b_35_0, emitter.context().types().u64());
    /* execute.simd:2564 [D] s_b_39_2 = s_b_39_1+s_b_39_0 */
    auto s_b_39_2 = emitter.add(s_b_39_1, s_b_39_0);
    /* execute.simd:2564 [D] s_b_39_3: sym_13770_0_address = s_b_39_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_13770_0_address, s_b_39_2);
    /* execute.simd:2564 [F] s_b_39_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_24,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2778 [D] s_b_40_0 = sym_69827_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_69827_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_41_0 = sym_69827_3_parameter_value uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_69827_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_42_0 = sym_69827_3_parameter_value uint64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_69827_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldnp(const arm64_decode_a64_LS_NO_ALLOC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14131_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84169_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84392_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84198_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84520_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87517_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_86021_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_86303_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84595_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84301_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_85021_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_84566_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84918_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_84372_1_tmp_s_b_1_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_85369_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_85497_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_87583_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14122_3_parameter_inst.rn (const) */
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
    /* execute.a64:945 [D] s_b_1_0 = sym_14131_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14131_0_addr, emitter.context().types().u64());
    /* execute.a64:945 [D] s_b_1_1: sym_84198_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_84198_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2: sym_84372_1_tmp_s_b_1_0 = s_b_1_0, dominates: s_b_6_3  */
    emitter.store_local(DV_sym_84372_1_tmp_s_b_1_0, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_3 = Load 4 s_b_1_0 => sym_84301_0_data32 */
    auto s_b_1_3 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_84301_0_data32, s_b_1_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_3, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_1_4 = sym_84301_0_data32 uint32_t */
    auto s_b_1_4 = emitter.load_local(DV_sym_84301_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_1_5 = (u64)s_b_1_4 */
    auto s_b_1_5 = emitter.zx(s_b_1_4, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_6=sym_14122_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_7 = (u32)s_b_1_5 */
    auto s_b_1_7 = emitter.truncate(s_b_1_5, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_8 = (u64)s_b_1_7 */
    auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_9: sym_86021_3_parameter_value = s_b_1_8, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_86021_3_parameter_value, s_b_1_8);
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
    /* execute.a64:948 [D] s_b_3_0 = sym_14131_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14131_0_addr, emitter.context().types().u64());
    /* execute.a64:948 [D] s_b_3_1: sym_84392_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_84392_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2: sym_84566_1_tmp_s_b_3_0 = s_b_3_0, dominates: s_b_7_3  */
    emitter.store_local(DV_sym_84566_1_tmp_s_b_3_0, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_3 = Load 8 s_b_3_0 => sym_84520_0_data64 */
    auto s_b_3_3 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_84520_0_data64, s_b_3_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_3, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_3_4 = sym_84520_0_data64 uint64_t */
    auto s_b_3_4 = emitter.load_local(DV_sym_84520_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_3_5=sym_14122_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_3_6: sym_86303_3_parameter_value = s_b_3_4, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_86303_3_parameter_value, s_b_3_4);
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
    /* execute.a64:2796 [F] s_b_4_0=sym_14122_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_4_2: sym_84169_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_84169_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2796 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:942 [D] s_b_5_0 = sym_84169_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_84169_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:942 [F] s_b_5_1=sym_14122_3_parameter_inst.imms64 (const) */
    /* execute.a64:942 [F] s_b_5_2 = (u64)s_b_5_1 (const) */
    /* execute.a64:942 [D] s_b_5_3 = s_b_5_0+s_b_5_2 */
    auto s_b_5_3 = emitter.add(s_b_5_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:942 [D] s_b_5_4: sym_14131_0_addr = s_b_5_3, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14131_0_addr, s_b_5_3);
    /* execute.a64:944 [F] s_b_5_5=sym_14122_3_parameter_inst.opc (const) */
    /* execute.a64:944 [F] s_b_5_6 = (u32)s_b_5_5 (const) */
    /* execute.a64:944 [F] s_b_5_7 = constant u32 0 (const) */
    /* execute.a64:944 [F] s_b_5_8 = s_b_5_6==s_b_5_7 (const) */
    uint8_t s_b_5_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:944 [F] s_b_5_9: If s_b_5_8: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1786 [F] s_b_6_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_6_1 = sym_84198_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_84198_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* ???:4294967295 [D] s_b_6_3 = sym_84372_1_tmp_s_b_1_0 uint64_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_84372_1_tmp_s_b_1_0, emitter.context().types().u64());
    /* execute.a64:946 [F] s_b_6_4 = constant u64 4 (const) */
    /* execute.a64:946 [D] s_b_6_5 = s_b_6_3+s_b_6_4 */
    auto s_b_6_5 = emitter.add(s_b_6_3, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:946 [D] s_b_6_6: sym_84918_3_parameter_address = s_b_6_5, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_84918_3_parameter_address, s_b_6_5);
    /* ???:4294967295 [D] s_b_6_7 = Load 4 s_b_6_5 => sym_85021_0_data32 */
    auto s_b_6_7 = emitter.load_memory(s_b_6_5, emitter.context().types().u32());
    emitter.store_local(DV_sym_85021_0_data32, s_b_6_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_5, s_b_6_7, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_6_8 = sym_85021_0_data32 uint32_t */
    auto s_b_6_8 = emitter.load_local(DV_sym_85021_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_10=sym_14122_3_parameter_inst.rt2 (const) */
    /* execute.a64:2756 [D] s_b_6_11 = (u32)s_b_6_9 */
    auto s_b_6_11 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_13: sym_87517_3_parameter_value = s_b_6_12, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_87517_3_parameter_value, s_b_6_12);
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
    /* execute.a64:1786 [D] s_b_7_1 = sym_84392_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_84392_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* ???:4294967295 [D] s_b_7_3 = sym_84566_1_tmp_s_b_3_0 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_84566_1_tmp_s_b_3_0, emitter.context().types().u64());
    /* execute.a64:949 [F] s_b_7_4 = constant u64 8 (const) */
    /* execute.a64:949 [D] s_b_7_5 = s_b_7_3+s_b_7_4 */
    auto s_b_7_5 = emitter.add(s_b_7_3, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:949 [D] s_b_7_6: sym_85369_3_parameter_address = s_b_7_5, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_85369_3_parameter_address, s_b_7_5);
    /* ???:4294967295 [D] s_b_7_7 = Load 8 s_b_7_5 => sym_85497_0_data64 */
    auto s_b_7_7 = emitter.load_memory(s_b_7_5, emitter.context().types().u64());
    emitter.store_local(DV_sym_85497_0_data64, s_b_7_7);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_5, s_b_7_7, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_7_8 = sym_85497_0_data64 uint64_t */
    auto s_b_7_8 = emitter.load_local(DV_sym_85497_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_7_9=sym_14122_3_parameter_inst.rt2 (const) */
    /* execute.a64:2754 [D] s_b_7_10: sym_87583_3_parameter_value = s_b_7_8, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_87583_3_parameter_value, s_b_7_8);
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
    /* execute.a64:2765 [D] s_b_9_1: sym_84595_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_84595_1__R_s_b_7_0, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_84595_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_84595_1__R_s_b_7_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_84595_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_84595_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2794 [D] s_b_12_0 = sym_84595_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_84595_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_12_1: sym_84169_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_84169_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2794 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_6, b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1786 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_13_1 = sym_84918_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_84918_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7, b_19,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1786 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_14_1 = sym_85369_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_85369_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_16_0=sym_14122_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_16_1 = sym_86021_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_86021_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_17_0=sym_14122_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_86303_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_86303_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_18_0=sym_14122_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_18_1 = sym_87517_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_87517_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_19_0=sym_14122_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_19_1 = sym_87583_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_87583_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldr_lit(const arm64_decode_a64_LOAD_REG_LIT&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14741_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_94734_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_94837_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_96097_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_96075_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_94925_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_95053_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:648 [D] s_b_0_0 = read_pc */
    auto s_b_0_0 = emitter.load_pc();
    /* execute.a64:648 [F] s_b_0_1=sym_14735_3_parameter_inst.label (const) */
    /* execute.a64:648 [F] s_b_0_2 = (u64)s_b_0_1 (const) */
    /* execute.a64:648 [D] s_b_0_3 = s_b_0_0+s_b_0_2 */
    auto s_b_0_3 = emitter.add(s_b_0_0, emitter.const_u64(((uint64_t)insn.label)));
    /* execute.a64:648 [D] s_b_0_4: sym_14741_0_address = s_b_0_3, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14741_0_address, s_b_0_3);
    /* execute.a64:650 [F] s_b_0_5=sym_14735_3_parameter_inst.opc (const) */
    /* execute.a64:650 [F] s_b_0_6 = (u32)s_b_0_5 (const) */
    /* execute.a64:650 [F] s_b_0_7 = constant u32 0 (const) */
    /* execute.a64:650 [F] s_b_0_8 = s_b_0_6==s_b_0_7 (const) */
    uint8_t s_b_0_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:650 [F] s_b_0_9: If s_b_0_8: Jump b_1 else b_3 (const) */
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
    /* execute.a64:651 [D] s_b_1_0 = sym_14741_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14741_0_address, emitter.context().types().u64());
    /* execute.a64:651 [D] s_b_1_1: sym_94734_3_parameter_address = s_b_1_0, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_94734_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2 = Load 4 s_b_1_0 => sym_94837_0_data32 */
    auto s_b_1_2 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_94837_0_data32, s_b_1_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_2, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_1_3 = sym_94837_0_data32 uint32_t */
    auto s_b_1_3 = emitter.load_local(DV_sym_94837_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_5=sym_14735_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_6 = (u32)s_b_1_4 */
    auto s_b_1_6 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_8: sym_96075_3_parameter_value = s_b_1_7, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_96075_3_parameter_value, s_b_1_7);
    /* execute.a64:2745 [F] s_b_1_9 = (u32)s_b_1_5 (const) */
    /* execute.a64:2745 [F] s_b_1_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_1_11 = s_b_1_9==s_b_1_10 (const) */
    uint8_t s_b_1_11 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_1_12: If s_b_1_11: Jump b_4 else b_6 (const) */
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
    /* execute.a64:653 [D] s_b_3_0 = sym_14741_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14741_0_address, emitter.context().types().u64());
    /* execute.a64:653 [D] s_b_3_1: sym_94925_3_parameter_address = s_b_3_0, dominates: s_b_5_1  */
    emitter.store_local(DV_sym_94925_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2 = Load 8 s_b_3_0 => sym_95053_0_data64 */
    auto s_b_3_2 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_95053_0_data64, s_b_3_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_3_3 = sym_95053_0_data64 uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_95053_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_3_4=sym_14735_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_3_5: sym_96097_3_parameter_value = s_b_3_3, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_96097_3_parameter_value, s_b_3_3);
    /* execute.a64:2745 [F] s_b_3_6 = (u32)s_b_3_4 (const) */
    /* execute.a64:2745 [F] s_b_3_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_3_8 = s_b_3_6==s_b_3_7 (const) */
    uint8_t s_b_3_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_3_9: If s_b_3_8: Jump b_5 else b_7 (const) */
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
    /* execute.a64:1786 [F] s_b_4_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_4_1 = sym_94734_3_parameter_address uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_94734_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_4_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_4_1);
    /* execute.a64:0 [F] s_b_4_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3, b_7,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1786 [F] s_b_5_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_5_1 = sym_94925_3_parameter_address uint64_t */
    auto s_b_5_1 = emitter.load_local(DV_sym_94925_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_5_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_5_1);
    /* execute.a64:0 [F] s_b_5_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2747 [F] s_b_6_0=sym_14735_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_6_1 = sym_96075_3_parameter_value uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_96075_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_6_2: WriteRegBank 0:s_b_6_0 = s_b_6_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_6_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_6_1);
    /* execute.a64:0 [F] s_b_6_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2747 [F] s_b_7_0=sym_14735_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_7_1 = sym_96097_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_96097_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_7_2: WriteRegBank 0:s_b_7_0 = s_b_7_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_7_1,emitter.const_u8(8));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldrh_reg(const arm64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_15666_0_rm;
  auto DV_sym_15666_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_15767_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_109414_1__R_s_b_43_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_109261_1_temporary_value;
  auto DV_sym_109261_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_108720_1_temporary_value;
  auto DV_sym_108720_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_109494_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109516_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_108800_1__R_s_b_2_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_109582_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_108941_1_temporary_value;
  auto DV_sym_108941_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_109095_1_temporary_value;
  auto DV_sym_109095_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1193 [F] s_b_0_0=sym_15639_3_parameter_inst.option0 (const) */
    /* execute.a64:1193 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1193 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1193 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1193 [F] s_b_0_4=sym_15639_3_parameter_inst.option21 (const) */
    /* execute.a64:1193 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:1193 [F] s_b_0_6 = constant u32 1 (const) */
    /* execute.a64:1193 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:1193 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1194 [F] s_b_1_0=sym_15639_3_parameter_inst.rm (const) */
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
    /* execute.a64:2793 [F] s_b_2_0=sym_15639_3_parameter_inst.rn (const) */
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
    /* execute.a64:1195 [F] s_b_3_0=sym_15639_3_parameter_inst.option0 (const) */
    /* execute.a64:1195 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1195 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1195 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1195 [F] s_b_3_4=sym_15639_3_parameter_inst.option21 (const) */
    /* execute.a64:1195 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:1195 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.a64:1195 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:1195 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1196 [F] s_b_4_0=sym_15639_3_parameter_inst.rm (const) */
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
    /* execute.a64:1197 [F] s_b_5_0=sym_15639_3_parameter_inst.option0 (const) */
    /* execute.a64:1197 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1197 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1197 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1197 [F] s_b_5_4=sym_15639_3_parameter_inst.option21 (const) */
    /* execute.a64:1197 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1197 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:1197 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1197 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1198 [F] s_b_6_0=sym_15639_3_parameter_inst.rm (const) */
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
    /* execute.a64:1199 [F] s_b_7_0=sym_15639_3_parameter_inst.option0 (const) */
    /* execute.a64:1199 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1199 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1199 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1199 [F] s_b_7_4=sym_15639_3_parameter_inst.option21 (const) */
    /* execute.a64:1199 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:1199 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.a64:1199 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:1199 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1200 [F] s_b_8_0=sym_15639_3_parameter_inst.rm (const) */
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
    /* execute.a64:1202 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:1202 [F] s_b_9_1: sym_15666_0_rm = s_b_9_0 (const), dominates: s_b_19_1  */
    CV_sym_15666_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_15666_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1203 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1202 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_19,  */
  fixed_block_b_10: 
  {
    /* execute.a64:1212 [F] s_b_10_0=sym_15639_3_parameter_inst.L (const) */
    /* execute.a64:1212 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
    /* execute.a64:1212 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:1212 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(((uint32_t)insn.L) == (uint32_t)0ULL));
    /* execute.a64:1212 [F] s_b_10_4: If s_b_10_3: Jump b_13 else b_14 (const) */
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
    /* execute.a64:1218 [D] s_b_12_0 = sym_15767_0_value uint16_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_15767_0_value, emitter.context().types().u16());
    /* execute.a64:1218 [D] s_b_12_1 = (u64)s_b_12_0 */
    auto s_b_12_1 = emitter.zx(s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_12_2=sym_15639_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_12_3 = (u32)s_b_12_1 */
    auto s_b_12_3 = emitter.truncate(s_b_12_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_12_4 = (u64)s_b_12_3 */
    auto s_b_12_4 = emitter.zx(s_b_12_3, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_12_5: sym_109494_3_parameter_value = s_b_12_4, dominates: s_b_34_1  */
    emitter.store_local(DV_sym_109494_3_parameter_value, s_b_12_4);
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
    /* execute.a64:1213 [D] s_b_13_0 = sym_15767_0_value uint16_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_15767_0_value, emitter.context().types().u16());
    /* execute.a64:1213 [D] s_b_13_1 = (s16)s_b_13_0 */
    auto s_b_13_1 = emitter.reinterpret(s_b_13_0, emitter.context().types().s16());
    /* execute.a64:1213 [D] s_b_13_2 = (s64)s_b_13_1 */
    auto s_b_13_2 = emitter.sx(s_b_13_1, emitter.context().types().s64());
    /* execute.a64:1213 [D] s_b_13_3 = (u64)s_b_13_2 */
    auto s_b_13_3 = emitter.reinterpret(s_b_13_2, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_13_4=sym_15639_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_13_5: sym_109516_3_parameter_value = s_b_13_3, dominates: s_b_35_1  */
    emitter.store_local(DV_sym_109516_3_parameter_value, s_b_13_3);
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
    /* execute.a64:1215 [D] s_b_14_0 = sym_15767_0_value uint16_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_15767_0_value, emitter.context().types().u16());
    /* execute.a64:1215 [D] s_b_14_1 = (s16)s_b_14_0 */
    auto s_b_14_1 = emitter.reinterpret(s_b_14_0, emitter.context().types().s16());
    /* execute.a64:1215 [D] s_b_14_2 = (s64)s_b_14_1 */
    auto s_b_14_2 = emitter.sx(s_b_14_1, emitter.context().types().s64());
    /* execute.a64:1215 [D] s_b_14_3 = (u64)s_b_14_2 */
    auto s_b_14_3 = emitter.reinterpret(s_b_14_2, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_14_4=sym_15639_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_14_5 = (u32)s_b_14_3 */
    auto s_b_14_5 = emitter.truncate(s_b_14_3, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_14_6 = (u64)s_b_14_5 */
    auto s_b_14_6 = emitter.zx(s_b_14_5, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_14_7: sym_109582_3_parameter_value = s_b_14_6, dominates: s_b_36_1  */
    emitter.store_local(DV_sym_109582_3_parameter_value, s_b_14_6);
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
    /* execute.a64:2709 [F] s_b_15_1: sym_108720_1_temporary_value = s_b_15_0 (const), dominates: s_b_17_0  */
    CV_sym_108720_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_108720_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_1,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2709 [F] s_b_16_0=sym_15639_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_16_1 = ReadRegBank 1:s_b_16_0 (u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_16_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_16_2: sym_108720_1_temporary_value = s_b_16_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_108720_1_temporary_value, s_b_16_1);
    /* execute.a64:2709 [F] s_b_16_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2709 [D] s_b_17_0 = sym_108720_1_temporary_value uint32_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_108720_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_17_1 = (u64)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u64());
    /* execute.a64:2679 [D] s_b_17_2 = (u32)s_b_17_1 */
    auto s_b_17_2 = emitter.truncate(s_b_17_1, emitter.context().types().u32());
    /* execute.a64:2679 [D] s_b_17_3 = (u64)s_b_17_2 */
    auto s_b_17_3 = emitter.zx(s_b_17_2, emitter.context().types().u64());
    /* execute.a64:2679 [F] s_b_17_4=sym_15639_3_parameter_inst.S (const) */
    /* execute.a64:2679 [F] s_b_17_5 = (u64)s_b_17_4 (const) */
    /* execute.a64:2679 [D] s_b_17_6 = s_b_17_3<<s_b_17_5 */
    auto s_b_17_6 = emitter.shl(s_b_17_3, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1194 [D] s_b_17_7: sym_15666_0_rm = s_b_17_6, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_15666_0_rm, s_b_17_6);
    /* execute.a64:1194 [F] s_b_17_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2796 [F] s_b_18_0=sym_15639_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_18_1 = ReadRegBank 0:s_b_18_0 (u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_18_2: sym_108800_1__R_s_b_2_5 = s_b_18_1, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_108800_1__R_s_b_2_5, s_b_18_1);
    /* execute.a64:2796 [F] s_b_18_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_18, b_33,  */
  fixed_block_b_19: 
  {
    /* execute.a64:1206 [D] s_b_19_0 = sym_108800_1__R_s_b_2_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_108800_1__R_s_b_2_5, emitter.context().types().u64());
    /* execute.a64:1206 [D] s_b_19_1 = sym_15666_0_rm uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_15666_0_rm, emitter.context().types().u64());
    /* execute.a64:1206 [D] s_b_19_2 = s_b_19_0+s_b_19_1 */
    auto s_b_19_2 = emitter.add(s_b_19_0, s_b_19_1);
    /* ???:4294967295 [D] s_b_19_3 = Load 2 s_b_19_2 => sym_15767_0_value */
    auto s_b_19_3 = emitter.load_memory(s_b_19_2, emitter.context().types().u16());
    emitter.store_local(DV_sym_15767_0_value, s_b_19_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_19_2, s_b_19_3, emitter.const_u8(2));
    }
    /* execute.a64:1211 [F] s_b_19_4=sym_15639_3_parameter_inst.X (const) */
    /* execute.a64:1211 [F] s_b_19_5: If s_b_19_4: Jump b_10 else b_12 (const) */
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
    /* execute.a64:2709 [F] s_b_20_1: sym_108941_1_temporary_value = s_b_20_0 (const), dominates: s_b_22_0  */
    CV_sym_108941_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_108941_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_20_2: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_4,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2709 [F] s_b_21_0=sym_15639_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_21_1 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_21_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_21_2: sym_108941_1_temporary_value = s_b_21_1, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_108941_1_temporary_value, s_b_21_1);
    /* execute.a64:2709 [F] s_b_21_3: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_20, b_21,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2709 [D] s_b_22_0 = sym_108941_1_temporary_value uint32_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_108941_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_22_1 = (u64)s_b_22_0 */
    auto s_b_22_1 = emitter.zx(s_b_22_0, emitter.context().types().u64());
    /* execute.a64:2695 [D] s_b_22_2 = (s32)s_b_22_1 */
    auto s_b_22_2 = emitter.truncate(s_b_22_1, emitter.context().types().s32());
    /* execute.a64:2695 [D] s_b_22_3 = (s64)s_b_22_2 */
    auto s_b_22_3 = emitter.sx(s_b_22_2, emitter.context().types().s64());
    /* execute.a64:2695 [D] s_b_22_4 = (u64)s_b_22_3 */
    auto s_b_22_4 = emitter.reinterpret(s_b_22_3, emitter.context().types().u64());
    /* execute.a64:2695 [F] s_b_22_5=sym_15639_3_parameter_inst.S (const) */
    /* execute.a64:2695 [F] s_b_22_6 = (u64)s_b_22_5 (const) */
    /* execute.a64:2695 [D] s_b_22_7 = s_b_22_4<<s_b_22_6 */
    auto s_b_22_7 = emitter.shl(s_b_22_4, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1196 [D] s_b_22_8: sym_15666_0_rm = s_b_22_7, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_15666_0_rm, s_b_22_7);
    /* execute.a64:1196 [F] s_b_22_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [F] s_b_23_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_23_1: sym_109095_1_temporary_value = s_b_23_0 (const), dominates: s_b_25_0  */
    CV_sym_109095_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_109095_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_23_2: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_6,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [F] s_b_24_0=sym_15639_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_24_1 = ReadRegBank 0:s_b_24_0 (u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_24_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_24_2: sym_109095_1_temporary_value = s_b_24_1, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_109095_1_temporary_value, s_b_24_1);
    /* execute.a64:2714 [F] s_b_24_3: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_23, b_24,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2714 [D] s_b_25_0 = sym_109095_1_temporary_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_109095_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2683 [F] s_b_25_1=sym_15639_3_parameter_inst.S (const) */
    /* execute.a64:2683 [F] s_b_25_2 = (u64)s_b_25_1 (const) */
    /* execute.a64:2683 [D] s_b_25_3 = s_b_25_0<<s_b_25_2 */
    auto s_b_25_3 = emitter.shl(s_b_25_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1198 [D] s_b_25_4: sym_15666_0_rm = s_b_25_3, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_15666_0_rm, s_b_25_3);
    /* execute.a64:1198 [F] s_b_25_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2714 [F] s_b_26_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_26_1: sym_109261_1_temporary_value = s_b_26_0 (const), dominates: s_b_28_0  */
    CV_sym_109261_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_109261_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_26_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_8,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2714 [F] s_b_27_0=sym_15639_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_27_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_27_2: sym_109261_1_temporary_value = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_109261_1_temporary_value, s_b_27_1);
    /* execute.a64:2714 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_26, b_27,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2714 [D] s_b_28_0 = sym_109261_1_temporary_value uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_109261_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2699 [F] s_b_28_1=sym_15639_3_parameter_inst.S (const) */
    /* execute.a64:2699 [F] s_b_28_2 = (u64)s_b_28_1 (const) */
    /* execute.a64:2699 [D] s_b_28_3 = s_b_28_0<<s_b_28_2 */
    auto s_b_28_3 = emitter.shl(s_b_28_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1200 [D] s_b_28_4: sym_15666_0_rm = s_b_28_3, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_15666_0_rm, s_b_28_3);
    /* execute.a64:1200 [F] s_b_28_5: Jump b_2 (const) */
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
    /* execute.a64:2765 [D] s_b_30_1: sym_109414_1__R_s_b_43_0 = s_b_30_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_109414_1__R_s_b_43_0, s_b_30_0);
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
    /* execute.a64:2768 [D] s_b_31_1: sym_109414_1__R_s_b_43_0 = s_b_31_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_109414_1__R_s_b_43_0, s_b_31_0);
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
    /* execute.a64:2770 [D] s_b_32_1: sym_109414_1__R_s_b_43_0 = s_b_32_0, dominates: s_b_33_0  */
    emitter.store_local(DV_sym_109414_1__R_s_b_43_0, s_b_32_0);
    /* execute.a64:2770 [F] s_b_32_2: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_30, b_31, b_32,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2794 [D] s_b_33_0 = sym_109414_1__R_s_b_43_0 uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_109414_1__R_s_b_43_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_33_1: sym_108800_1__R_s_b_2_5 = s_b_33_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_108800_1__R_s_b_2_5, s_b_33_0);
    /* execute.a64:2794 [F] s_b_33_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_12,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2747 [F] s_b_34_0=sym_15639_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_34_1 = sym_109494_3_parameter_value uint64_t */
    auto s_b_34_1 = emitter.load_local(DV_sym_109494_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_35_0=sym_15639_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_35_1 = sym_109516_3_parameter_value uint64_t */
    auto s_b_35_1 = emitter.load_local(DV_sym_109516_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_36_0=sym_15639_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_36_1 = sym_109582_3_parameter_value uint64_t */
    auto s_b_36_1 = emitter.load_local(DV_sym_109582_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldtrh(const arm64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldxrb(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_120073_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120111_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120174_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120778_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_120179_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_16363_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_1_0=sym_16363_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_1_2: sym_120073_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_120073_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2796 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:696 [D] s_b_2_0 = sym_120073_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_120073_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:697 [D] s_b_2_1: sym_120174_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_120174_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 1 s_b_2_0 => sym_120179_0_data8 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_120179_0_data8, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(1));
    }
    /* execute.a64:1726 [D] s_b_2_3 = sym_120179_0_data8 uint8_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_120179_0_data8, emitter.context().types().u8());
    /* execute.a64:1726 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_2_5=sym_16363_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_2_8: sym_120778_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_120778_3_parameter_value, s_b_2_7);
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
    /* execute.a64:2765 [D] s_b_4_1: sym_120111_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_120111_1__R_s_b_4_0, s_b_4_0);
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
    /* execute.a64:2768 [D] s_b_5_1: sym_120111_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_120111_1__R_s_b_4_0, s_b_5_0);
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
    /* execute.a64:2770 [D] s_b_6_1: sym_120111_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_120111_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2770 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2794 [D] s_b_7_0 = sym_120111_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_120111_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_7_1: sym_120073_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_120073_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2794 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1786 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_8_1 = sym_120174_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_120174_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_10_0=sym_16363_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_10_1 = sym_120778_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_120778_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_movk(const arm64_decode_a64_MOVE_WIDE_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_125696_1_temporary_value;
  auto DV_sym_125696_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_125724_1_temporary_value;
  auto DV_sym_125724_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_125801_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_125749_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_125779_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_125677_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:256 [F] s_b_0_0=sym_16707_3_parameter_inst.sf (const) */
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
    /* execute.a64:2720 [F] s_b_1_0=sym_16707_3_parameter_inst.rd (const) */
    /* execute.a64:2714 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:2714 [F] s_b_1_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
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
    /* execute.a64:2722 [F] s_b_2_0=sym_16707_3_parameter_inst.rd (const) */
    /* execute.a64:2709 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2709 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
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
    /* execute.a64:256 [D] s_b_3_0 = sym_125677_1__R_s_b_0_4 uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_125677_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:256 [F] s_b_3_1 = constant u64 ffff (const) */
    /* execute.a64:256 [F] s_b_3_2=sym_16707_3_parameter_inst.shift_amount (const) */
    /* execute.a64:256 [F] s_b_3_3 = (u64)s_b_3_2 (const) */
    /* execute.a64:256 [F] s_b_3_4 = s_b_3_1<<s_b_3_3 (const) */
    uint64_t s_b_3_4 = ((uint64_t)((uint64_t)65535ULL << ((uint64_t)insn.shift_amount)));
    /* execute.a64:256 [F] s_b_3_5 = ~s_b_3_4 (const) */
    uint64_t s_b_3_5 = ~s_b_3_4;
    /* execute.a64:256 [D] s_b_3_6 = s_b_3_0&s_b_3_5 */
    auto s_b_3_6 = emitter.bitwise_and(s_b_3_0, emitter.const_u64(s_b_3_5));
    /* execute.a64:257 [F] s_b_3_7=sym_16707_3_parameter_inst.imm16 (const) */
    /* execute.a64:257 [F] s_b_3_8 = (u64)s_b_3_7 (const) */
    /* execute.a64:257 [F] s_b_3_9=sym_16707_3_parameter_inst.shift_amount (const) */
    /* execute.a64:257 [F] s_b_3_10 = (u64)s_b_3_9 (const) */
    /* execute.a64:257 [F] s_b_3_11 = s_b_3_8<<s_b_3_10 (const) */
    uint64_t s_b_3_11 = ((uint64_t)(((uint64_t)insn.imm16) << ((uint64_t)insn.shift_amount)));
    /* ???:4294967295 [D] s_b_3_12 = s_b_3_6|s_b_3_11 */
    auto s_b_3_12 = emitter.bitwise_or(s_b_3_6, emitter.const_u64(s_b_3_11));
    /* execute.a64:259 [F] s_b_3_13=sym_16707_3_parameter_inst.sf (const) */
    /* execute.a64:259 [D] s_b_3_14: sym_125749_3_parameter_value = s_b_3_12, dominates: s_b_10_1 s_b_11_1  */
    emitter.store_local(DV_sym_125749_3_parameter_value, s_b_3_12);
    /* execute.a64:2753 [F] s_b_3_15: If s_b_3_13: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2714 [F] s_b_4_1: sym_125696_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_125696_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_125696_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2714 [F] s_b_5_0=sym_16707_3_parameter_inst.rd (const) */
    /* execute.a64:2714 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_5_2: sym_125696_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_125696_1_temporary_value, s_b_5_1);
    /* execute.a64:2714 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2714 [D] s_b_6_0 = sym_125696_1_temporary_value uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_125696_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_6_1: sym_125677_1__R_s_b_0_4 = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_125677_1__R_s_b_0_4, s_b_6_0);
    /* execute.a64:2720 [F] s_b_6_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2709 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_7_1: sym_125724_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_125724_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_125724_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_2,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2709 [F] s_b_8_0=sym_16707_3_parameter_inst.rd (const) */
    /* execute.a64:2709 [D] s_b_8_1 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_8_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_8_2: sym_125724_1_temporary_value = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_125724_1_temporary_value, s_b_8_1);
    /* execute.a64:2709 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2709 [D] s_b_9_0 = sym_125724_1_temporary_value uint32_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_125724_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_9_1 = (u64)s_b_9_0 */
    auto s_b_9_1 = emitter.zx(s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_9_2: sym_125677_1__R_s_b_0_4 = s_b_9_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_125677_1__R_s_b_0_4, s_b_9_1);
    /* execute.a64:2722 [F] s_b_9_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2754 [F] s_b_10_0=sym_16707_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_10_1 = sym_125749_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_125749_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_10_2: sym_125779_3_parameter_value = s_b_10_1, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_125779_3_parameter_value, s_b_10_1);
    /* execute.a64:2745 [F] s_b_10_3 = (u32)s_b_10_0 (const) */
    /* execute.a64:2745 [F] s_b_10_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_10_6: If s_b_10_5: Jump b_12 else b_13 (const) */
    if (s_b_10_5) 
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
    /* execute.a64:2756 [F] s_b_11_0=sym_16707_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_11_1 = sym_125749_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_125749_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_11_2 = (u32)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_11_4: sym_125801_3_parameter_value = s_b_11_3, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_125801_3_parameter_value, s_b_11_3);
    /* execute.a64:2745 [F] s_b_11_5 = (u32)s_b_11_0 (const) */
    /* execute.a64:2745 [F] s_b_11_6 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_11_7 = s_b_11_5==s_b_11_6 (const) */
    uint8_t s_b_11_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_11_8: If s_b_11_7: Jump b_12 else b_14 (const) */
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
    /* execute.a64:2747 [F] s_b_13_0=sym_16707_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_13_1 = sym_125779_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_125779_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
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
    /* execute.a64:2747 [F] s_b_14_0=sym_16707_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_14_1 = sym_125801_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_125801_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_mul_idx_vector(const arm64_decode_a64_SIMD_VECTOR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1340 [F] s_b_0_0=sym_18966_3_parameter_inst.arrangement (const) */
    /* execute.simd:1341 [F] s_b_0_1 = constant s32 2 (const) */
    /* execute.simd:1350 [F] s_b_0_2 = constant s32 3 (const) */
    /* execute.simd:1358 [F] s_b_0_3 = constant s32 4 (const) */
    /* execute.simd:1367 [F] s_b_0_4 = constant s32 5 (const) */
    /* execute.simd:1340 [F] s_b_0_5: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4, b_5,  */
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
    /* execute.simd:1342 [F] s_b_2_0=sym_18966_3_parameter_inst.rn (const) */
    /* execute.simd:1342 [D] s_b_2_1 = ReadRegBank 17:s_b_2_0 (v4u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1343 [F] s_b_2_2=sym_18966_3_parameter_inst.rmr (const) */
    /* execute.simd:1343 [D] s_b_2_3 = ReadRegBank 18:s_b_2_2 (v8u16) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))),s_b_2_3,emitter.const_u8(16));
    }
    /* execute.simd:1344 [F] s_b_2_4=sym_18966_3_parameter_inst.eindex (const) */
    /* execute.simd:1344 [D] s_b_2_3[s_b_2_4] */
    auto s_b_2_5 = emitter.vector_extract(s_b_2_3, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_2_6 = (v4u16)s_b_2_5 */
    auto s_b_2_6 = emitter.splat(s_b_2_5, emitter.context().types().v4u16());
    /* execute.simd:1344 [D] s_b_2_7 = s_b_2_1*s_b_2_6 */
    auto s_b_2_7 = emitter.mul(s_b_2_1, s_b_2_6);
    /* execute.simd:1346 [F] s_b_2_8=sym_18966_3_parameter_inst.rd (const) */
    /* execute.simd:1346 [D] s_b_2_9: WriteRegBank 17:s_b_2_8 = s_b_2_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_7);
    /* execute.simd:1347 [F] s_b_2_10=sym_18966_3_parameter_inst.rd (const) */
    /* execute.simd:1347 [F] s_b_2_11 = constant u64 0 (const) */
    /* execute.simd:1347 [F] s_b_2_12: WriteRegBank 3:s_b_2_10 = s_b_2_11 */
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
    /* execute.simd:1351 [F] s_b_3_0=sym_18966_3_parameter_inst.rn (const) */
    /* execute.simd:1351 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:1352 [F] s_b_3_2=sym_18966_3_parameter_inst.rmr (const) */
    /* execute.simd:1352 [D] s_b_3_3 = ReadRegBank 18:s_b_3_2 (v8u16) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:1353 [F] s_b_3_4=sym_18966_3_parameter_inst.eindex (const) */
    /* execute.simd:1353 [D] s_b_3_3[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_3, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_3_6 = (v8u16)s_b_3_5 */
    auto s_b_3_6 = emitter.splat(s_b_3_5, emitter.context().types().v8u16());
    /* execute.simd:1353 [D] s_b_3_7 = s_b_3_1*s_b_3_6 */
    auto s_b_3_7 = emitter.mul(s_b_3_1, s_b_3_6);
    /* execute.simd:1355 [F] s_b_3_8=sym_18966_3_parameter_inst.rd (const) */
    /* execute.simd:1355 [D] s_b_3_9: WriteRegBank 18:s_b_3_8 = s_b_3_7 */
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
    /* execute.simd:1359 [F] s_b_4_0=sym_18966_3_parameter_inst.rn (const) */
    /* execute.simd:1359 [D] s_b_4_1 = ReadRegBank 19:s_b_4_0 (v2u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:1360 [F] s_b_4_2=sym_18966_3_parameter_inst.rmr (const) */
    /* execute.simd:1360 [D] s_b_4_3 = ReadRegBank 20:s_b_4_2 (v4u32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))),s_b_4_3,emitter.const_u8(16));
    }
    /* execute.simd:1361 [F] s_b_4_4=sym_18966_3_parameter_inst.eindex (const) */
    /* execute.simd:1361 [D] s_b_4_3[s_b_4_4] */
    auto s_b_4_5 = emitter.vector_extract(s_b_4_3, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_4_6 = (v2u32)s_b_4_5 */
    auto s_b_4_6 = emitter.splat(s_b_4_5, emitter.context().types().v2u32());
    /* execute.simd:1361 [D] s_b_4_7 = s_b_4_1*s_b_4_6 */
    auto s_b_4_7 = emitter.mul(s_b_4_1, s_b_4_6);
    /* execute.simd:1363 [F] s_b_4_8=sym_18966_3_parameter_inst.rd (const) */
    /* execute.simd:1363 [D] s_b_4_9: WriteRegBank 19:s_b_4_8 = s_b_4_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_7);
    /* execute.simd:1364 [F] s_b_4_10=sym_18966_3_parameter_inst.rd (const) */
    /* execute.simd:1364 [F] s_b_4_11 = constant u64 0 (const) */
    /* execute.simd:1364 [F] s_b_4_12: WriteRegBank 3:s_b_4_10 = s_b_4_11 */
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
    /* execute.simd:1368 [F] s_b_5_0=sym_18966_3_parameter_inst.rn (const) */
    /* execute.simd:1368 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1369 [F] s_b_5_2=sym_18966_3_parameter_inst.rmr (const) */
    /* execute.simd:1369 [D] s_b_5_3 = ReadRegBank 20:s_b_5_2 (v4u32) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rmr))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1370 [F] s_b_5_4=sym_18966_3_parameter_inst.eindex (const) */
    /* execute.simd:1370 [D] s_b_5_3[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_3, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_5_6 = (v4u32)s_b_5_5 */
    auto s_b_5_6 = emitter.splat(s_b_5_5, emitter.context().types().v4u32());
    /* execute.simd:1370 [D] s_b_5_7 = s_b_5_1*s_b_5_6 */
    auto s_b_5_7 = emitter.mul(s_b_5_1, s_b_5_6);
    /* execute.simd:1372 [F] s_b_5_8=sym_18966_3_parameter_inst.rd (const) */
    /* execute.simd:1372 [D] s_b_5_9: WriteRegBank 20:s_b_5_8 = s_b_5_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_7,emitter.const_u8(16));
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_orrsr(const arm64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_127570_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127362_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_127419_1_temporary_value;
  auto DV_sym_127419_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_127346_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19493_0_op1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_19500_0_op2 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_127915_1_temporary_value;
  auto DV_sym_127915_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_127647_1__R_s_b_27_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127597_1__R_s_b_23_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_127692_1_temporary_value;
  auto DV_sym_127692_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  uint64_t CV_sym_127943_1_temporary_value;
  auto DV_sym_127943_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127622_1__R_s_b_26_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_127548_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_128027_1_temporary_value;
  auto DV_sym_128027_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_127706_1__R_s_b_28_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  uint64_t CV_sym_127831_1_temporary_value;
  auto DV_sym_127831_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_127887_1_temporary_value;
  auto DV_sym_127887_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_127518_1__R_s_b_6_10;
  auto DV_sym_127518_1__R_s_b_6_10 = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_127680_1_temporary_value;
  auto DV_sym_127680_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  uint64_t CV_sym_127775_1_temporary_value;
  auto DV_sym_127775_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_127803_1_temporary_value;
  auto DV_sym_127803_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_127859_1_temporary_value;
  auto DV_sym_127859_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_127391_1_temporary_value;
  auto DV_sym_127391_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2537 [F] s_b_0_0=sym_19488_3_parameter_inst.sf (const) */
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
    /* execute.a64:2540 [D] s_b_1_0 = sym_19500_0_op2 uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_19500_0_op2, emitter.context().types().u64());
    /* execute.a64:2540 [D] s_b_1_1 = ~s_b_1_0 */
    auto s_b_1_1 = emitter.bitwise_not(s_b_1_0);
    /* execute.a64:2540 [D] s_b_1_2: sym_19500_0_op2 = s_b_1_1, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_19500_0_op2, s_b_1_1);
    /* execute.a64:2540 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_24,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2542 [D] s_b_2_0 = sym_19493_0_op1 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_19493_0_op1, emitter.context().types().u64());
    /* execute.a64:2542 [D] s_b_2_1 = sym_19500_0_op2 uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_19500_0_op2, emitter.context().types().u64());
    /* execute.a64:2542 [D] s_b_2_2 = s_b_2_0|s_b_2_1 */
    auto s_b_2_2 = emitter.bitwise_or(s_b_2_0, s_b_2_1);
    /* execute.a64:2544 [F] s_b_2_3=sym_19488_3_parameter_inst.sf (const) */
    /* execute.a64:2544 [D] s_b_2_4: sym_127362_3_parameter_value = s_b_2_2, dominates: s_b_6_1 s_b_7_1  */
    emitter.store_local(DV_sym_127362_3_parameter_value, s_b_2_2);
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
    /* execute.a64:2720 [F] s_b_3_0=sym_19488_3_parameter_inst.rn (const) */
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
    /* execute.a64:2722 [F] s_b_4_0=sym_19488_3_parameter_inst.rn (const) */
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
    /* execute.a64:2537 [D] s_b_5_0 = sym_127346_1__R_s_b_0_4 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_127346_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2537 [D] s_b_5_1: sym_19493_0_op1 = s_b_5_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_19493_0_op1, s_b_5_0);
    /* execute.a64:2538 [F] s_b_5_2=sym_19488_3_parameter_inst.imm6 (const) */
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
    /* execute.a64:2754 [F] s_b_6_0=sym_19488_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_6_1 = sym_127362_3_parameter_value uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_127362_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2754 [D] s_b_6_2: sym_127548_3_parameter_value = s_b_6_1, dominates: s_b_25_1  */
    emitter.store_local(DV_sym_127548_3_parameter_value, s_b_6_1);
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
    /* execute.a64:2756 [F] s_b_7_0=sym_19488_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_7_1 = sym_127362_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_127362_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_7_2 = (u32)s_b_7_1 */
    auto s_b_7_2 = emitter.truncate(s_b_7_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_7_3 = (u64)s_b_7_2 */
    auto s_b_7_3 = emitter.zx(s_b_7_2, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_7_4: sym_127570_3_parameter_value = s_b_7_3, dominates: s_b_26_1  */
    emitter.store_local(DV_sym_127570_3_parameter_value, s_b_7_3);
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
    /* execute.a64:2714 [F] s_b_9_1: sym_127391_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_127391_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_127391_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2714 [F] s_b_10_0=sym_19488_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_10_2: sym_127391_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_127391_1_temporary_value, s_b_10_1);
    /* execute.a64:2714 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2714 [D] s_b_11_0 = sym_127391_1_temporary_value uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_127391_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_11_1: sym_127346_1__R_s_b_0_4 = s_b_11_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_127346_1__R_s_b_0_4, s_b_11_0);
    /* execute.a64:2720 [F] s_b_11_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_12_1: sym_127419_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_127419_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_127419_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_4,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [F] s_b_13_0=sym_19488_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_13_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_13_2: sym_127419_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_127419_1_temporary_value, s_b_13_1);
    /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_127419_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_127419_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_14_2: sym_127346_1__R_s_b_0_4 = s_b_14_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_127346_1__R_s_b_0_4, s_b_14_1);
    /* execute.a64:2722 [F] s_b_14_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_5,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2635 [F] s_b_15_0=sym_19488_3_parameter_inst.sf (const) */
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
    /* execute.a64:2637 [F] s_b_16_0=sym_19488_3_parameter_inst.shift (const) */
    /* execute.a64:2638 [F] s_b_16_1 = constant s32 0 (const) */
    /* execute.a64:2642 [F] s_b_16_2 = constant s32 1 (const) */
    /* execute.a64:2646 [F] s_b_16_3 = constant s32 2 (const) */
    /* execute.a64:2650 [F] s_b_16_4 = constant s32 3 (const) */
    /* execute.a64:2637 [F] s_b_16_5: Switch s_b_16_0: < <todo> > def b_17 (const) -> b_18, b_17, b_20, b_21, b_19,  */
    switch (insn.shift) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
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
    /* execute.a64:2661 [F] s_b_17_2: sym_127518_1__R_s_b_6_10 = s_b_17_1 (const), dominates: s_b_24_0  */
    CV_sym_127518_1__R_s_b_6_10 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_127518_1__R_s_b_6_10, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2661 [F] s_b_17_3: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2640 [F] s_b_18_0=sym_19488_3_parameter_inst.sf (const) */
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
    /* execute.a64:2644 [F] s_b_19_0=sym_19488_3_parameter_inst.sf (const) */
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
    /* execute.a64:2648 [F] s_b_20_0=sym_19488_3_parameter_inst.sf (const) */
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
    /* execute.a64:2652 [F] s_b_21_0=sym_19488_3_parameter_inst.sf (const) */
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
    /* execute.a64:2720 [F] s_b_22_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2722 [F] s_b_23_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2538 [D] s_b_24_0 = sym_127518_1__R_s_b_6_10 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_127518_1__R_s_b_6_10, emitter.context().types().u64());
    /* execute.a64:2538 [D] s_b_24_1: sym_19500_0_op2 = s_b_24_0, dominates: s_b_1_0 s_b_2_1  */
    emitter.store_local(DV_sym_19500_0_op2, s_b_24_0);
    /* execute.a64:2540 [F] s_b_24_2=sym_19488_3_parameter_inst.N (const) */
    /* execute.a64:2540 [F] s_b_24_3: If s_b_24_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2747 [F] s_b_25_0=sym_19488_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_25_1 = sym_127548_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_127548_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_26_0=sym_19488_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_26_1 = sym_127570_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_127570_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2720 [F] s_b_27_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2722 [F] s_b_28_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2635 [D] s_b_29_0 = sym_127597_1__R_s_b_23_4 uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_127597_1__R_s_b_23_4, emitter.context().types().u64());
    /* execute.a64:2635 [D] s_b_29_1: sym_127518_1__R_s_b_6_10 = s_b_29_0, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_127518_1__R_s_b_6_10, s_b_29_0);
    /* execute.a64:2635 [F] s_b_29_2: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_18,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2720 [F] s_b_30_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2722 [F] s_b_31_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2640 [D] s_b_32_0 = sym_127622_1__R_s_b_26_4 uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_127622_1__R_s_b_26_4, emitter.context().types().u64());
    /* execute.a64:2640 [F] s_b_32_1=sym_19488_3_parameter_inst.imm6 (const) */
    /* execute.a64:2640 [F] s_b_32_2 = (u64)s_b_32_1 (const) */
    /* execute.a64:2640 [D] s_b_32_3 = s_b_32_0<<s_b_32_2 */
    auto s_b_32_3 = emitter.shl(s_b_32_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2640 [D] s_b_32_4: sym_127518_1__R_s_b_6_10 = s_b_32_3, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_127518_1__R_s_b_6_10, s_b_32_3);
    /* execute.a64:2640 [F] s_b_32_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_19,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2720 [F] s_b_33_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2722 [F] s_b_34_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2644 [D] s_b_35_0 = sym_127647_1__R_s_b_27_4 uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_127647_1__R_s_b_27_4, emitter.context().types().u64());
    /* execute.a64:2644 [F] s_b_35_1=sym_19488_3_parameter_inst.imm6 (const) */
    /* execute.a64:2644 [F] s_b_35_2 = (u64)s_b_35_1 (const) */
    /* execute.a64:2644 [D] s_b_35_3 = s_b_35_0>>s_b_35_2 */
    auto s_b_35_3 = emitter.shr(s_b_35_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2644 [D] s_b_35_4: sym_127518_1__R_s_b_6_10 = s_b_35_3, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_127518_1__R_s_b_6_10, s_b_35_3);
    /* execute.a64:2644 [F] s_b_35_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_20,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2729 [F] s_b_36_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2731 [F] s_b_37_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2729 [F] s_b_38_1: sym_127680_1_temporary_value = s_b_38_0 (const), dominates: s_b_42_0  */
    CV_sym_127680_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_127680_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2729 [F] s_b_38_2: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_36,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2729 [F] s_b_39_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2729 [D] s_b_39_1 = ReadRegBank 0:s_b_39_0 (u64) */
    auto s_b_39_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_39_1,emitter.const_u8(8));
    }
    /* execute.a64:2729 [D] s_b_39_2 = (s64)s_b_39_1 */
    auto s_b_39_2 = emitter.reinterpret(s_b_39_1, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_39_3: sym_127680_1_temporary_value = s_b_39_2, dominates: s_b_42_0  */
    emitter.store_local(DV_sym_127680_1_temporary_value, s_b_39_2);
    /* execute.a64:2729 [F] s_b_39_4: Jump b_42 (const) */
    goto fixed_block_b_42;
  }
  /* b_37,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2731 [F] s_b_40_0 = constant s64 0 (const) */
    /* execute.a64:2731 [F] s_b_40_1: sym_127692_1_temporary_value = s_b_40_0 (const), dominates: s_b_43_0  */
    CV_sym_127692_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_127692_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2731 [F] s_b_40_2: Jump b_43 (const) */
    goto fixed_block_b_43;
  }
  /* b_37,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2731 [F] s_b_41_0=sym_19488_3_parameter_inst.rm (const) */
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
    /* execute.a64:2731 [D] s_b_41_4: sym_127692_1_temporary_value = s_b_41_3, dominates: s_b_43_0  */
    emitter.store_local(DV_sym_127692_1_temporary_value, s_b_41_3);
    /* execute.a64:2731 [F] s_b_41_5: Jump b_43 (const) */
    goto fixed_block_b_43;
  }
  /* b_38, b_39,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2729 [D] s_b_42_0 = sym_127680_1_temporary_value int64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_127680_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_42_1: sym_127706_1__R_s_b_28_4 = s_b_42_0, dominates: s_b_44_0  */
    emitter.store_local(DV_sym_127706_1__R_s_b_28_4, s_b_42_0);
    /* execute.a64:2729 [F] s_b_42_2: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_40, b_41,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2731 [D] s_b_43_0 = sym_127692_1_temporary_value int64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_127692_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2731 [D] s_b_43_1: sym_127706_1__R_s_b_28_4 = s_b_43_0, dominates: s_b_44_0  */
    emitter.store_local(DV_sym_127706_1__R_s_b_28_4, s_b_43_0);
    /* execute.a64:2731 [F] s_b_43_2: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_42, b_43,  */
  fixed_block_b_44: 
  {
    /* execute.a64:2648 [D] s_b_44_0 = sym_127706_1__R_s_b_28_4 int64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_127706_1__R_s_b_28_4, emitter.context().types().s64());
    /* execute.a64:2648 [F] s_b_44_1=sym_19488_3_parameter_inst.imm6 (const) */
    /* execute.a64:2648 [D] s_b_44_2 = (u64)s_b_44_0 */
    auto s_b_44_2 = emitter.reinterpret(s_b_44_0, emitter.context().types().u64());
    /* execute.a64:2648 [F] s_b_44_3 = (u64)s_b_44_1 (const) */
    /* execute.a64:2648 [D] s_b_44_4 = s_b_44_2->>s_b_44_3 */
    auto s_b_44_4 = emitter.sar(s_b_44_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2648 [D] s_b_44_5 = (u64)s_b_44_4 */
    auto s_b_44_5 = (captive::arch::dbt::el::Value *)s_b_44_4;
    /* execute.a64:2648 [D] s_b_44_6: sym_127518_1__R_s_b_6_10 = s_b_44_5, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_127518_1__R_s_b_6_10, s_b_44_5);
    /* execute.a64:2648 [F] s_b_44_7: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_27,  */
  fixed_block_b_45: 
  {
    /* execute.a64:2714 [F] s_b_45_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_45_1: sym_127775_1_temporary_value = s_b_45_0 (const), dominates: s_b_47_0  */
    CV_sym_127775_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_127775_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_45_2: Jump b_47 (const) */
    goto fixed_block_b_47;
  }
  /* b_27,  */
  fixed_block_b_46: 
  {
    /* execute.a64:2714 [F] s_b_46_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_46_1 = ReadRegBank 0:s_b_46_0 (u64) */
    auto s_b_46_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_46_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_46_2: sym_127775_1_temporary_value = s_b_46_1, dominates: s_b_47_0  */
    emitter.store_local(DV_sym_127775_1_temporary_value, s_b_46_1);
    /* execute.a64:2714 [F] s_b_46_3: Jump b_47 (const) */
    goto fixed_block_b_47;
  }
  /* b_45, b_46,  */
  fixed_block_b_47: 
  {
    /* execute.a64:2714 [D] s_b_47_0 = sym_127775_1_temporary_value uint64_t */
    auto s_b_47_0 = emitter.load_local(DV_sym_127775_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_47_1: sym_127597_1__R_s_b_23_4 = s_b_47_0, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_127597_1__R_s_b_23_4, s_b_47_0);
    /* execute.a64:2720 [F] s_b_47_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_28,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2709 [F] s_b_48_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_48_1: sym_127803_1_temporary_value = s_b_48_0 (const), dominates: s_b_50_0  */
    CV_sym_127803_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_127803_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_48_2: Jump b_50 (const) */
    goto fixed_block_b_50;
  }
  /* b_28,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2709 [F] s_b_49_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_49_1 = ReadRegBank 1:s_b_49_0 (u32) */
    auto s_b_49_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_49_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_49_2: sym_127803_1_temporary_value = s_b_49_1, dominates: s_b_50_0  */
    emitter.store_local(DV_sym_127803_1_temporary_value, s_b_49_1);
    /* execute.a64:2709 [F] s_b_49_3: Jump b_50 (const) */
    goto fixed_block_b_50;
  }
  /* b_48, b_49,  */
  fixed_block_b_50: 
  {
    /* execute.a64:2709 [D] s_b_50_0 = sym_127803_1_temporary_value uint32_t */
    auto s_b_50_0 = emitter.load_local(DV_sym_127803_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_50_1 = (u64)s_b_50_0 */
    auto s_b_50_1 = emitter.zx(s_b_50_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_50_2: sym_127597_1__R_s_b_23_4 = s_b_50_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_127597_1__R_s_b_23_4, s_b_50_1);
    /* execute.a64:2722 [F] s_b_50_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_30,  */
  fixed_block_b_51: 
  {
    /* execute.a64:2714 [F] s_b_51_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_51_1: sym_127831_1_temporary_value = s_b_51_0 (const), dominates: s_b_53_0  */
    CV_sym_127831_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_127831_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_51_2: Jump b_53 (const) */
    goto fixed_block_b_53;
  }
  /* b_30,  */
  fixed_block_b_52: 
  {
    /* execute.a64:2714 [F] s_b_52_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_52_1 = ReadRegBank 0:s_b_52_0 (u64) */
    auto s_b_52_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_52_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_52_2: sym_127831_1_temporary_value = s_b_52_1, dominates: s_b_53_0  */
    emitter.store_local(DV_sym_127831_1_temporary_value, s_b_52_1);
    /* execute.a64:2714 [F] s_b_52_3: Jump b_53 (const) */
    goto fixed_block_b_53;
  }
  /* b_51, b_52,  */
  fixed_block_b_53: 
  {
    /* execute.a64:2714 [D] s_b_53_0 = sym_127831_1_temporary_value uint64_t */
    auto s_b_53_0 = emitter.load_local(DV_sym_127831_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_53_1: sym_127622_1__R_s_b_26_4 = s_b_53_0, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_127622_1__R_s_b_26_4, s_b_53_0);
    /* execute.a64:2720 [F] s_b_53_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_31,  */
  fixed_block_b_54: 
  {
    /* execute.a64:2709 [F] s_b_54_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_54_1: sym_127859_1_temporary_value = s_b_54_0 (const), dominates: s_b_56_0  */
    CV_sym_127859_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_127859_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_54_2: Jump b_56 (const) */
    goto fixed_block_b_56;
  }
  /* b_31,  */
  fixed_block_b_55: 
  {
    /* execute.a64:2709 [F] s_b_55_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_55_1 = ReadRegBank 1:s_b_55_0 (u32) */
    auto s_b_55_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_55_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_55_2: sym_127859_1_temporary_value = s_b_55_1, dominates: s_b_56_0  */
    emitter.store_local(DV_sym_127859_1_temporary_value, s_b_55_1);
    /* execute.a64:2709 [F] s_b_55_3: Jump b_56 (const) */
    goto fixed_block_b_56;
  }
  /* b_54, b_55,  */
  fixed_block_b_56: 
  {
    /* execute.a64:2709 [D] s_b_56_0 = sym_127859_1_temporary_value uint32_t */
    auto s_b_56_0 = emitter.load_local(DV_sym_127859_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_56_1 = (u64)s_b_56_0 */
    auto s_b_56_1 = emitter.zx(s_b_56_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_56_2: sym_127622_1__R_s_b_26_4 = s_b_56_1, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_127622_1__R_s_b_26_4, s_b_56_1);
    /* execute.a64:2722 [F] s_b_56_3: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_33,  */
  fixed_block_b_57: 
  {
    /* execute.a64:2714 [F] s_b_57_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_57_1: sym_127887_1_temporary_value = s_b_57_0 (const), dominates: s_b_59_0  */
    CV_sym_127887_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_127887_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_57_2: Jump b_59 (const) */
    goto fixed_block_b_59;
  }
  /* b_33,  */
  fixed_block_b_58: 
  {
    /* execute.a64:2714 [F] s_b_58_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_58_1 = ReadRegBank 0:s_b_58_0 (u64) */
    auto s_b_58_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_58_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_58_2: sym_127887_1_temporary_value = s_b_58_1, dominates: s_b_59_0  */
    emitter.store_local(DV_sym_127887_1_temporary_value, s_b_58_1);
    /* execute.a64:2714 [F] s_b_58_3: Jump b_59 (const) */
    goto fixed_block_b_59;
  }
  /* b_57, b_58,  */
  fixed_block_b_59: 
  {
    /* execute.a64:2714 [D] s_b_59_0 = sym_127887_1_temporary_value uint64_t */
    auto s_b_59_0 = emitter.load_local(DV_sym_127887_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_59_1: sym_127647_1__R_s_b_27_4 = s_b_59_0, dominates: s_b_35_0  */
    emitter.store_local(DV_sym_127647_1__R_s_b_27_4, s_b_59_0);
    /* execute.a64:2720 [F] s_b_59_2: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_34,  */
  fixed_block_b_60: 
  {
    /* execute.a64:2709 [F] s_b_60_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_60_1: sym_127915_1_temporary_value = s_b_60_0 (const), dominates: s_b_62_0  */
    CV_sym_127915_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_127915_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_60_2: Jump b_62 (const) */
    goto fixed_block_b_62;
  }
  /* b_34,  */
  fixed_block_b_61: 
  {
    /* execute.a64:2709 [F] s_b_61_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_61_1 = ReadRegBank 1:s_b_61_0 (u32) */
    auto s_b_61_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_61_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_61_2: sym_127915_1_temporary_value = s_b_61_1, dominates: s_b_62_0  */
    emitter.store_local(DV_sym_127915_1_temporary_value, s_b_61_1);
    /* execute.a64:2709 [F] s_b_61_3: Jump b_62 (const) */
    goto fixed_block_b_62;
  }
  /* b_60, b_61,  */
  fixed_block_b_62: 
  {
    /* execute.a64:2709 [D] s_b_62_0 = sym_127915_1_temporary_value uint32_t */
    auto s_b_62_0 = emitter.load_local(DV_sym_127915_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_62_1 = (u64)s_b_62_0 */
    auto s_b_62_1 = emitter.zx(s_b_62_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_62_2: sym_127647_1__R_s_b_27_4 = s_b_62_1, dominates: s_b_35_0  */
    emitter.store_local(DV_sym_127647_1__R_s_b_27_4, s_b_62_1);
    /* execute.a64:2722 [F] s_b_62_3: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_22,  */
  fixed_block_b_63: 
  {
    /* execute.a64:2714 [F] s_b_63_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_63_1: sym_127943_1_temporary_value = s_b_63_0 (const), dominates: s_b_65_0  */
    CV_sym_127943_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_127943_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_63_2: Jump b_65 (const) */
    goto fixed_block_b_65;
  }
  /* b_22,  */
  fixed_block_b_64: 
  {
    /* execute.a64:2714 [F] s_b_64_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_64_1 = ReadRegBank 0:s_b_64_0 (u64) */
    auto s_b_64_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_64_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_64_2: sym_127943_1_temporary_value = s_b_64_1, dominates: s_b_65_0  */
    emitter.store_local(DV_sym_127943_1_temporary_value, s_b_64_1);
    /* execute.a64:2714 [F] s_b_64_3: Jump b_65 (const) */
    goto fixed_block_b_65;
  }
  /* b_63, b_64,  */
  fixed_block_b_65: 
  {
    /* execute.a64:2714 [D] s_b_65_0 = sym_127943_1_temporary_value uint64_t */
    auto s_b_65_0 = emitter.load_local(DV_sym_127943_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2653 [F] s_b_65_1=sym_19488_3_parameter_inst.imm6 (const) */
    /* execute.a64:2653 [F] s_b_65_2 = (u64)s_b_65_1 (const) */
    /* execute.a64:2653 [D] s_b_65_3 = s_b_65_0>>>s_b_65_2 */
    auto s_b_65_3 = emitter.ror(s_b_65_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2653 [D] s_b_65_4: sym_127518_1__R_s_b_6_10 = s_b_65_3, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_127518_1__R_s_b_6_10, s_b_65_3);
    /* execute.a64:2653 [F] s_b_65_5: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_23,  */
  fixed_block_b_66: 
  {
    /* execute.a64:2709 [F] s_b_66_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_66_1: sym_128027_1_temporary_value = s_b_66_0 (const), dominates: s_b_68_0  */
    CV_sym_128027_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_128027_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_66_2: Jump b_68 (const) */
    goto fixed_block_b_68;
  }
  /* b_23,  */
  fixed_block_b_67: 
  {
    /* execute.a64:2709 [F] s_b_67_0=sym_19488_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_67_1 = ReadRegBank 1:s_b_67_0 (u32) */
    auto s_b_67_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_67_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_67_2: sym_128027_1_temporary_value = s_b_67_1, dominates: s_b_68_0  */
    emitter.store_local(DV_sym_128027_1_temporary_value, s_b_67_1);
    /* execute.a64:2709 [F] s_b_67_3: Jump b_68 (const) */
    goto fixed_block_b_68;
  }
  /* b_66, b_67,  */
  fixed_block_b_68: 
  {
    /* execute.a64:2709 [D] s_b_68_0 = sym_128027_1_temporary_value uint32_t */
    auto s_b_68_0 = emitter.load_local(DV_sym_128027_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_68_1 = (u64)s_b_68_0 */
    auto s_b_68_1 = emitter.zx(s_b_68_0, emitter.context().types().u64());
    /* execute.a64:2655 [D] s_b_68_2 = (u32)s_b_68_1 */
    auto s_b_68_2 = emitter.truncate(s_b_68_1, emitter.context().types().u32());
    /* execute.a64:2655 [F] s_b_68_3=sym_19488_3_parameter_inst.imm6 (const) */
    /* execute.a64:2655 [F] s_b_68_4 = (u32)s_b_68_3 (const) */
    /* execute.a64:2655 [D] s_b_68_5 = s_b_68_2>>>s_b_68_4 */
    auto s_b_68_5 = emitter.ror(s_b_68_2, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2655 [D] s_b_68_6 = (u64)s_b_68_5 */
    auto s_b_68_6 = emitter.zx(s_b_68_5, emitter.context().types().u64());
    /* execute.a64:2655 [D] s_b_68_7: sym_127518_1__R_s_b_6_10 = s_b_68_6, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_127518_1__R_s_b_6_10, s_b_68_6);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ret(const arm64_decode_a64_UB_REG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_128778_1_temporary_value;
  auto DV_sym_128778_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:625 [F] s_b_0_0=sym_20008_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2714 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2714 [F] s_b_1_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_1_1: sym_128778_1_temporary_value = s_b_1_0 (const), dominates: s_b_3_0  */
    CV_sym_128778_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_128778_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_1_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2714 [F] s_b_2_0=sym_20008_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_2_2: sym_128778_1_temporary_value = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_128778_1_temporary_value, s_b_2_1);
    /* execute.a64:2714 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2714 [D] s_b_3_0 = sym_128778_1_temporary_value uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_128778_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:571 [D] s_b_3_1 = write_pc */
    emitter.store_pc(s_b_3_0);
    /* execute.a64:572 [D] s_b_3_2 = __branch_taken */
    emitter.call(__captive___branch_taken);
    /* ???:4294967295 [F] s_b_3_3: Return */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_saddlv(const arm64_decode_a64_SIMD_ACROSS_LANES&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_shll(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3235 [D] s_b_0_0 = trap */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_smulh(const arm64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_133157_1_temporary_value;
  auto DV_sym_133157_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_133222_1_temporary_value;
  auto DV_sym_133222_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_133306_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_133265_1_tmp_s_b_11_1 = emitter.alloc_local(emitter.context().types().s64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2440 [F] s_b_0_0=sym_24762_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2714 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2714 [F] s_b_1_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_1_1: sym_133157_1_temporary_value = s_b_1_0 (const), dominates: s_b_3_0  */
    CV_sym_133157_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_133157_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_1_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2714 [F] s_b_2_0=sym_24762_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_2_2: sym_133157_1_temporary_value = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_133157_1_temporary_value, s_b_2_1);
    /* execute.a64:2714 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2714 [D] s_b_3_0 = sym_133157_1_temporary_value uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_133157_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2440 [D] s_b_3_1 = (s64)s_b_3_0 */
    auto s_b_3_1 = emitter.reinterpret(s_b_3_0, emitter.context().types().s64());
    /* execute.a64:2441 [F] s_b_3_2=sym_24762_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_3_3: sym_133265_1_tmp_s_b_11_1 = s_b_3_1, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_133265_1_tmp_s_b_11_1, s_b_3_1);
    /* execute.a64:2714 [F] s_b_3_4 = (u32)s_b_3_2 (const) */
    /* execute.a64:2714 [F] s_b_3_5 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_3_7: If s_b_3_6: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2714 [F] s_b_4_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_4_1: sym_133222_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_133222_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_133222_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2714 [F] s_b_5_0=sym_24762_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_5_2: sym_133222_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_133222_1_temporary_value, s_b_5_1);
    /* execute.a64:2714 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2714 [D] s_b_6_0 = sym_133222_1_temporary_value uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_133222_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1 = sym_133265_1_tmp_s_b_11_1 int64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_133265_1_tmp_s_b_11_1, emitter.context().types().s64());
    /* execute.a64:2441 [D] s_b_6_2 = (s64)s_b_6_0 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_0, emitter.context().types().s64());
    /* execute.a64:2443 [D] s_b_6_3 = (u64)s_b_6_1 */
    auto s_b_6_3 = emitter.reinterpret(s_b_6_1, emitter.context().types().u64());
    /* execute.a64:2443 [D] s_b_6_4 = (u64)s_b_6_2 */
    auto s_b_6_4 = emitter.reinterpret(s_b_6_2, emitter.context().types().u64());
    /* execute.a64:2443 [D] s_b_6_5 = __builtin_smulh */
    auto s_b_6_5 = emitter.smulh(s_b_6_3, s_b_6_4);
    /* execute.a64:2443 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = (captive::arch::dbt::el::Value *)s_b_6_5;
    /* execute.a64:2754 [F] s_b_6_7=sym_24762_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_6_8: sym_133306_3_parameter_value = s_b_6_6, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_133306_3_parameter_value, s_b_6_6);
    /* execute.a64:2745 [F] s_b_6_9 = (u32)s_b_6_7 (const) */
    /* execute.a64:2745 [F] s_b_6_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_6_11 = s_b_6_9==s_b_6_10 (const) */
    uint8_t s_b_6_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_6_12: If s_b_6_11: Jump b_7 else b_8 (const) */
    if (s_b_6_11) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_6, b_8,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [F] s_b_7_0: Return */
    goto fixed_done;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2747 [F] s_b_8_0=sym_24762_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_8_1 = sym_133306_3_parameter_value uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_133306_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_8_2: WriteRegBank 0:s_b_8_0 = s_b_8_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_8_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_8_1);
    /* execute.a64:0 [F] s_b_8_3: Jump b_7 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_st1pi(const arm64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_134933_1_tmp_s_b_57_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_134945_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_134563_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_134672_3_parameter_rt;
  auto DV_sym_134677_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_134680_3_parameter_lane;
  auto DV_sym_134757_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_134754_1_tmp_s_b_5_4;
  auto DV_sym_134796_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_134779_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_134874_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_134906_1_temporary_value;
  auto DV_sym_134906_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30418_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30424_0_rt;
  uint8_t CV_sym_30436_0_lane;
  auto DV_sym_134580_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2572 [F] s_b_0_0=sym_30412_3_parameter_inst.rn (const) */
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
    /* execute.simd:2574 [F] s_b_1_0 = sym_30424_0_rt (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30424_0_rt;
    /* execute.simd:2574 [F] s_b_1_1=sym_30412_3_parameter_inst.regcnt (const) */
    /* execute.simd:2574 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.regcnt));
    /* execute.simd:2574 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2575 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2575 [F] s_b_2_1: sym_30436_0_lane = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30436_0_lane = (uint8_t)0ULL;
    /* execute.simd:2575 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2581 [F] s_b_3_0=sym_30412_3_parameter_inst.rm (const) */
    /* execute.simd:2581 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2581 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2581 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2581 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2575 [F] s_b_4_0 = sym_30436_0_lane (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30436_0_lane;
    /* execute.simd:2575 [F] s_b_4_1=sym_30412_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2575 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.elemcnt));
    /* execute.simd:2575 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2576 [F] s_b_5_0=sym_30412_3_parameter_inst.arrangement (const) */
    /* execute.simd:2576 [F] s_b_5_1=sym_30412_3_parameter_inst.rt (const) */
    /* execute.simd:2576 [F] s_b_5_2 = sym_30424_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30424_0_rt;
    /* execute.simd:2576 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2576 [F] s_b_5_4 = sym_30436_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30436_0_lane;
    /* execute.simd:2576 [D] s_b_5_5 = sym_30418_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30418_0_address, emitter.context().types().u64());
    /* execute.simd:2576 [F] s_b_5_6: sym_134672_3_parameter_rt = s_b_5_3 (const), dominates: s_b_20_0 s_b_24_0 s_b_19_0 s_b_18_0 s_b_23_0 s_b_22_0 s_b_21_0  */
    CV_sym_134672_3_parameter_rt = s_b_5_3;
    /* execute.simd:2576 [F] s_b_5_7: sym_134680_3_parameter_lane = s_b_5_4 (const), dominates: s_b_20_3 s_b_24_3 s_b_19_3 s_b_18_3 s_b_23_3 s_b_22_3 s_b_21_3  */
    CV_sym_134680_3_parameter_lane = s_b_5_4;
    /* execute.simd:2576 [D] s_b_5_8: sym_134677_3_parameter_addr = s_b_5_5, dominates: s_b_20_2 s_b_24_2 s_b_19_2 s_b_18_2 s_b_23_2 s_b_22_2 s_b_21_2  */
    emitter.store_local(DV_sym_134677_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_134754_1_tmp_s_b_5_4 = s_b_5_4 (const), dominates: s_b_25_1  */
    CV_sym_134754_1_tmp_s_b_5_4 = s_b_5_4;
    /* ???:4294967295 [D] s_b_5_10: sym_134757_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_134757_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3844 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3849 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3854 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3859 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3864 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3869 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3874 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3843 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_17 (const) -> b_20, b_24, b_19, b_18, b_17, b_23, b_22, b_21,  */
    switch (insn.arrangement) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_24;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
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
    /* execute.simd:2574 [F] s_b_6_0 = sym_30424_0_rt (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30424_0_rt;
    /* execute.simd:2574 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2574 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2574 [F] s_b_6_3: sym_30424_0_rt = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30424_0_rt = s_b_6_2;
    /* execute.simd:2574 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2582 [F] s_b_7_0=sym_30412_3_parameter_inst.rn (const) */
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
    /* execute.simd:2585 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2585 [D] s_b_8_1 = sym_30418_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_30418_0_address, emitter.context().types().u64());
    /* execute.simd:2585 [D] s_b_8_2: sym_134874_3_parameter_value = s_b_8_1, dominates: s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_134874_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2796 [F] s_b_10_0=sym_30412_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_134563_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_134563_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_134563_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_134563_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2572 [D] s_b_11_1: sym_30418_0_address = s_b_11_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30418_0_address, s_b_11_0);
    /* execute.simd:2574 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.simd:2574 [F] s_b_11_3: sym_30424_0_rt = s_b_11_2 (const), dominates: s_b_1_0 s_b_5_2 s_b_6_0  */
    CV_sym_30424_0_rt = (uint8_t)0ULL;
    /* execute.simd:2574 [F] s_b_11_4: Jump b_1 (const) */
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
    /* execute.a64:2765 [D] s_b_12_1: sym_134580_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_134580_1__R_s_b_3_0, s_b_12_0);
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
    /* execute.a64:2794 [D] s_b_14_0 = sym_134580_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_134580_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_134563_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_134563_0_return_symbol, s_b_14_0);
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
    /* execute.a64:2768 [D] s_b_15_1: sym_134580_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_134580_1__R_s_b_3_0, s_b_15_0);
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
    /* execute.a64:2770 [D] s_b_16_1: sym_134580_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_134580_1__R_s_b_3_0, s_b_16_0);
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
    /* execute.simd:3845 [F] s_b_18_0 = sym_134672_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_134672_3_parameter_rt;
    /* execute.simd:3845 [D] s_b_18_1 = ReadRegBank 15:s_b_18_0 (v8u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3846 [D] s_b_18_2 = sym_134677_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_134677_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3846 [F] s_b_18_3 = sym_134680_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_134680_3_parameter_lane;
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
    /* execute.simd:3850 [F] s_b_19_0 = sym_134672_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_134672_3_parameter_rt;
    /* execute.simd:3850 [D] s_b_19_1 = ReadRegBank 16:s_b_19_0 (v16u8) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3851 [D] s_b_19_2 = sym_134677_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_134677_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3851 [F] s_b_19_3 = sym_134680_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_134680_3_parameter_lane;
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
    /* execute.simd:3855 [F] s_b_20_0 = sym_134672_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_134672_3_parameter_rt;
    /* execute.simd:3855 [D] s_b_20_1 = ReadRegBank 17:s_b_20_0 (v4u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3856 [D] s_b_20_2 = sym_134677_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_134677_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3856 [F] s_b_20_3 = sym_134680_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_134680_3_parameter_lane;
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
    /* execute.simd:3860 [F] s_b_21_0 = sym_134672_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_134672_3_parameter_rt;
    /* execute.simd:3860 [D] s_b_21_1 = ReadRegBank 18:s_b_21_0 (v8u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3861 [D] s_b_21_2 = sym_134677_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_134677_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3861 [F] s_b_21_3 = sym_134680_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_134680_3_parameter_lane;
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
    /* execute.simd:3865 [F] s_b_22_0 = sym_134672_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_134672_3_parameter_rt;
    /* execute.simd:3865 [D] s_b_22_1 = ReadRegBank 19:s_b_22_0 (v2u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:3866 [D] s_b_22_2 = sym_134677_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_134677_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3866 [F] s_b_22_3 = sym_134680_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_134680_3_parameter_lane;
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
    /* execute.simd:3870 [F] s_b_23_0 = sym_134672_3_parameter_rt (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_134672_3_parameter_rt;
    /* execute.simd:3870 [D] s_b_23_1 = ReadRegBank 20:s_b_23_0 (v4u32) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:3871 [D] s_b_23_2 = sym_134677_3_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_134677_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3871 [F] s_b_23_3 = sym_134680_3_parameter_lane (const) uint8_t */
    uint8_t s_b_23_3 = CV_sym_134680_3_parameter_lane;
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
    /* execute.simd:3875 [F] s_b_24_0 = sym_134672_3_parameter_rt (const) uint8_t */
    uint8_t s_b_24_0 = CV_sym_134672_3_parameter_rt;
    /* execute.simd:3875 [D] s_b_24_1 = ReadRegBank 21:s_b_24_0 (v2u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))),s_b_24_1,emitter.const_u8(16));
    }
    /* execute.simd:3876 [D] s_b_24_2 = sym_134677_3_parameter_addr uint64_t */
    auto s_b_24_2 = emitter.load_local(DV_sym_134677_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3876 [F] s_b_24_3 = sym_134680_3_parameter_lane (const) uint8_t */
    uint8_t s_b_24_3 = CV_sym_134680_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_25_0 = sym_134757_1_tmp_s_b_5_5 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_134757_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_25_1 = sym_134754_1_tmp_s_b_5_4 (const) uint8_t */
    uint8_t s_b_25_1 = CV_sym_134754_1_tmp_s_b_5_4;
    /* execute.simd:2577 [F] s_b_25_2=sym_30412_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_25_3 = (u64)s_b_25_2 (const) */
    /* ???:4294967295 [D] s_b_25_4 = s_b_25_0+s_b_25_3 */
    auto s_b_25_4 = emitter.add(s_b_25_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2577 [D] s_b_25_5: sym_30418_0_address = s_b_25_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30418_0_address, s_b_25_4);
    /* execute.simd:2575 [F] s_b_25_6 = constant u8 1 (const) */
    /* execute.simd:2575 [F] s_b_25_7 = s_b_25_1+s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(s_b_25_1 + (uint8_t)1ULL));
    /* execute.simd:2575 [F] s_b_25_8: sym_30436_0_lane = s_b_25_7 (const), dominates: s_b_4_0 s_b_5_4  */
    CV_sym_30436_0_lane = s_b_25_7;
    /* execute.simd:2575 [F] s_b_25_9: Jump b_4 (const) */
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
    /* execute.a64:2796 [F] s_b_27_0=sym_30412_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_27_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_27_2: sym_134779_0_return_symbol = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_134779_0_return_symbol, s_b_27_1);
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_31,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_134779_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_134779_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2582 [F] s_b_28_1=sym_30412_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_28_2: sym_134933_1_tmp_s_b_57_0 = s_b_28_0, dominates: s_b_40_1  */
    emitter.store_local(DV_sym_134933_1_tmp_s_b_57_0, s_b_28_0);
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
    /* execute.a64:2765 [D] s_b_29_1: sym_134796_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_134796_1__R_s_b_3_0, s_b_29_0);
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
    /* execute.a64:2794 [D] s_b_31_0 = sym_134796_1__R_s_b_3_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_134796_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1: sym_134779_0_return_symbol = s_b_31_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_134779_0_return_symbol, s_b_31_0);
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
    /* execute.a64:2768 [D] s_b_32_1: sym_134796_1__R_s_b_3_0 = s_b_32_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_134796_1__R_s_b_3_0, s_b_32_0);
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
    /* execute.a64:2770 [D] s_b_33_1: sym_134796_1__R_s_b_3_0 = s_b_33_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_134796_1__R_s_b_3_0, s_b_33_0);
    /* execute.a64:2770 [F] s_b_33_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_8,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2810 [D] s_b_34_0 = sym_134874_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_134874_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_34_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_34_2 = s_b_34_0&s_b_34_1 */
    auto s_b_34_2 = emitter.bitwise_and(s_b_34_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_34_3: sym_134874_3_parameter_value = s_b_34_2, dominates: s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_134874_3_parameter_value, s_b_34_2);
    /* execute.a64:2810 [F] s_b_34_4: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_8, b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2813 [F] s_b_35_0=sym_30412_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_36_0 = sym_134874_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_134874_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_36_1: sym_134945_3_parameter_value = s_b_36_0, dominates: s_b_42_0 s_b_43_0 s_b_44_0  */
    emitter.store_local(DV_sym_134945_3_parameter_value, s_b_36_0);
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
    /* execute.a64:2816 [F] s_b_37_0=sym_30412_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_37_1 = sym_134874_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_134874_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2714 [F] s_b_39_1: sym_134906_1_temporary_value = s_b_39_0 (const), dominates: s_b_40_0  */
    CV_sym_134906_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_134906_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_39_2: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_39, b_41,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2714 [D] s_b_40_0 = sym_134906_1_temporary_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_134906_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_40_1 = sym_134933_1_tmp_s_b_57_0 uint64_t */
    auto s_b_40_1 = emitter.load_local(DV_sym_134933_1_tmp_s_b_57_0, emitter.context().types().u64());
    /* execute.simd:2582 [D] s_b_40_2 = s_b_40_1+s_b_40_0 */
    auto s_b_40_2 = emitter.add(s_b_40_1, s_b_40_0);
    /* execute.simd:2582 [D] s_b_40_3: sym_30418_0_address = s_b_40_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_30418_0_address, s_b_40_2);
    /* execute.simd:2582 [F] s_b_40_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_28,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2714 [F] s_b_41_0=sym_30412_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_41_1 = ReadRegBank 0:s_b_41_0 (u64) */
    auto s_b_41_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_41_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_41_2: sym_134906_1_temporary_value = s_b_41_1, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_134906_1_temporary_value, s_b_41_1);
    /* execute.a64:2714 [F] s_b_41_3: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_36,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2778 [D] s_b_42_0 = sym_134945_3_parameter_value uint64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_134945_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_43_0 = sym_134945_3_parameter_value uint64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_134945_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_44_0 = sym_134945_3_parameter_value uint64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_134945_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_st4pi(const arm64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint8_t CV_sym_137166_3_parameter_lane;
  uint64_t CV_sym_137392_1_temporary_value;
  auto DV_sym_137392_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137282_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_137158_3_parameter_rt;
  auto DV_sym_137360_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137049_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137243_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_137240_1_tmp_s_b_5_2;
  auto DV_sym_137265_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137431_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137419_1_tmp_s_b_57_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31018_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_31024_0_lane;
  uint8_t CV_sym_31036_0_rt;
  auto DV_sym_137066_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137163_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2626 [F] s_b_0_0=sym_31012_3_parameter_inst.rn (const) */
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
    /* execute.simd:2628 [F] s_b_1_0 = sym_31024_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_31024_0_lane;
    /* execute.simd:2628 [F] s_b_1_1=sym_31012_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2628 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2628 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2629 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2629 [F] s_b_2_1: sym_31036_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_31036_0_rt = (uint8_t)0ULL;
    /* execute.simd:2629 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2635 [F] s_b_3_0=sym_31012_3_parameter_inst.rm (const) */
    /* execute.simd:2635 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2635 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2635 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2635 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2629 [F] s_b_4_0 = sym_31036_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_31036_0_rt;
    /* execute.simd:2629 [F] s_b_4_1=sym_31012_3_parameter_inst.regcnt (const) */
    /* execute.simd:2629 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2629 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2630 [F] s_b_5_0=sym_31012_3_parameter_inst.arrangement (const) */
    /* execute.simd:2630 [F] s_b_5_1=sym_31012_3_parameter_inst.rt (const) */
    /* execute.simd:2630 [F] s_b_5_2 = sym_31036_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_31036_0_rt;
    /* execute.simd:2630 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2630 [F] s_b_5_4 = sym_31024_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_31024_0_lane;
    /* execute.simd:2630 [D] s_b_5_5 = sym_31018_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_31018_0_address, emitter.context().types().u64());
    /* execute.simd:2630 [F] s_b_5_6: sym_137158_3_parameter_rt = s_b_5_3 (const), dominates: s_b_23_0 s_b_22_0 s_b_24_0 s_b_18_0 s_b_19_0 s_b_20_0 s_b_21_0  */
    CV_sym_137158_3_parameter_rt = s_b_5_3;
    /* execute.simd:2630 [F] s_b_5_7: sym_137166_3_parameter_lane = s_b_5_4 (const), dominates: s_b_23_3 s_b_22_3 s_b_24_3 s_b_18_3 s_b_19_3 s_b_20_3 s_b_21_3  */
    CV_sym_137166_3_parameter_lane = s_b_5_4;
    /* execute.simd:2630 [D] s_b_5_8: sym_137163_3_parameter_addr = s_b_5_5, dominates: s_b_23_2 s_b_22_2 s_b_24_2 s_b_18_2 s_b_19_2 s_b_20_2 s_b_21_2  */
    emitter.store_local(DV_sym_137163_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_137240_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_25_1  */
    CV_sym_137240_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_137243_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_137243_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3844 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3849 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3854 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3859 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3864 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3869 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3874 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3843 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_17 (const) -> b_23, b_22, b_24, b_17, b_18, b_19, b_20, b_21,  */
    switch (insn.arrangement) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_24;
      break;
    default:
      goto fixed_block_b_17;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2628 [F] s_b_6_0 = sym_31024_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_31024_0_lane;
    /* execute.simd:2628 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2628 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2628 [F] s_b_6_3: sym_31024_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_31024_0_lane = s_b_6_2;
    /* execute.simd:2628 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2636 [F] s_b_7_0=sym_31012_3_parameter_inst.rn (const) */
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
    /* execute.simd:2639 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2639 [D] s_b_8_1 = sym_31018_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_31018_0_address, emitter.context().types().u64());
    /* execute.simd:2639 [D] s_b_8_2: sym_137360_3_parameter_value = s_b_8_1, dominates: s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_137360_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2796 [F] s_b_10_0=sym_31012_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_137049_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_137049_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_137049_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_137049_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2626 [D] s_b_11_1: sym_31018_0_address = s_b_11_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_31018_0_address, s_b_11_0);
    /* execute.simd:2628 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.simd:2628 [F] s_b_11_3: sym_31024_0_lane = s_b_11_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_31024_0_lane = (uint8_t)0ULL;
    /* execute.simd:2628 [F] s_b_11_4: Jump b_1 (const) */
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
    /* execute.a64:2765 [D] s_b_12_1: sym_137066_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_137066_1__R_s_b_3_0, s_b_12_0);
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
    /* execute.a64:2794 [D] s_b_14_0 = sym_137066_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_137066_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_137049_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_137049_0_return_symbol, s_b_14_0);
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
    /* execute.a64:2768 [D] s_b_15_1: sym_137066_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_137066_1__R_s_b_3_0, s_b_15_0);
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
    /* execute.a64:2770 [D] s_b_16_1: sym_137066_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_137066_1__R_s_b_3_0, s_b_16_0);
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
    /* execute.simd:3845 [F] s_b_18_0 = sym_137158_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_137158_3_parameter_rt;
    /* execute.simd:3845 [D] s_b_18_1 = ReadRegBank 15:s_b_18_0 (v8u8) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(8));
    }
    /* execute.simd:3846 [D] s_b_18_2 = sym_137163_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_137163_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3846 [F] s_b_18_3 = sym_137166_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_137166_3_parameter_lane;
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
    /* execute.simd:3850 [F] s_b_19_0 = sym_137158_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_137158_3_parameter_rt;
    /* execute.simd:3850 [D] s_b_19_1 = ReadRegBank 16:s_b_19_0 (v16u8) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(16));
    }
    /* execute.simd:3851 [D] s_b_19_2 = sym_137163_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_137163_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3851 [F] s_b_19_3 = sym_137166_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_137166_3_parameter_lane;
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
    /* execute.simd:3855 [F] s_b_20_0 = sym_137158_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_137158_3_parameter_rt;
    /* execute.simd:3855 [D] s_b_20_1 = ReadRegBank 17:s_b_20_0 (v4u16) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:3856 [D] s_b_20_2 = sym_137163_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_137163_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3856 [F] s_b_20_3 = sym_137166_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_137166_3_parameter_lane;
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
    /* execute.simd:3860 [F] s_b_21_0 = sym_137158_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_137158_3_parameter_rt;
    /* execute.simd:3860 [D] s_b_21_1 = ReadRegBank 18:s_b_21_0 (v8u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:3861 [D] s_b_21_2 = sym_137163_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_137163_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3861 [F] s_b_21_3 = sym_137166_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_137166_3_parameter_lane;
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
    /* execute.simd:3865 [F] s_b_22_0 = sym_137158_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_137158_3_parameter_rt;
    /* execute.simd:3865 [D] s_b_22_1 = ReadRegBank 19:s_b_22_0 (v2u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:3866 [D] s_b_22_2 = sym_137163_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_137163_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3866 [F] s_b_22_3 = sym_137166_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_137166_3_parameter_lane;
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
    /* execute.simd:3870 [F] s_b_23_0 = sym_137158_3_parameter_rt (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_137158_3_parameter_rt;
    /* execute.simd:3870 [D] s_b_23_1 = ReadRegBank 20:s_b_23_0 (v4u32) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:3871 [D] s_b_23_2 = sym_137163_3_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_137163_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3871 [F] s_b_23_3 = sym_137166_3_parameter_lane (const) uint8_t */
    uint8_t s_b_23_3 = CV_sym_137166_3_parameter_lane;
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
    /* execute.simd:3875 [F] s_b_24_0 = sym_137158_3_parameter_rt (const) uint8_t */
    uint8_t s_b_24_0 = CV_sym_137158_3_parameter_rt;
    /* execute.simd:3875 [D] s_b_24_1 = ReadRegBank 21:s_b_24_0 (v2u64) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))),s_b_24_1,emitter.const_u8(16));
    }
    /* execute.simd:3876 [D] s_b_24_2 = sym_137163_3_parameter_addr uint64_t */
    auto s_b_24_2 = emitter.load_local(DV_sym_137163_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3876 [F] s_b_24_3 = sym_137166_3_parameter_lane (const) uint8_t */
    uint8_t s_b_24_3 = CV_sym_137166_3_parameter_lane;
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
    /* ???:4294967295 [D] s_b_25_0 = sym_137243_1_tmp_s_b_5_5 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_137243_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_25_1 = sym_137240_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_25_1 = CV_sym_137240_1_tmp_s_b_5_2;
    /* execute.simd:2631 [F] s_b_25_2=sym_31012_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_25_3 = (u64)s_b_25_2 (const) */
    /* ???:4294967295 [D] s_b_25_4 = s_b_25_0+s_b_25_3 */
    auto s_b_25_4 = emitter.add(s_b_25_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2631 [D] s_b_25_5: sym_31018_0_address = s_b_25_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_31018_0_address, s_b_25_4);
    /* execute.simd:2629 [F] s_b_25_6 = constant u8 1 (const) */
    /* execute.simd:2629 [F] s_b_25_7 = s_b_25_1+s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(s_b_25_1 + (uint8_t)1ULL));
    /* execute.simd:2629 [F] s_b_25_8: sym_31036_0_rt = s_b_25_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_31036_0_rt = s_b_25_7;
    /* execute.simd:2629 [F] s_b_25_9: Jump b_4 (const) */
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
    /* execute.a64:2796 [F] s_b_27_0=sym_31012_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_27_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_27_2: sym_137265_0_return_symbol = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_137265_0_return_symbol, s_b_27_1);
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_31,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_137265_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_137265_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2636 [F] s_b_28_1=sym_31012_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_28_2: sym_137419_1_tmp_s_b_57_0 = s_b_28_0, dominates: s_b_40_1  */
    emitter.store_local(DV_sym_137419_1_tmp_s_b_57_0, s_b_28_0);
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
    /* execute.a64:2765 [D] s_b_29_1: sym_137282_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_137282_1__R_s_b_3_0, s_b_29_0);
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
    /* execute.a64:2794 [D] s_b_31_0 = sym_137282_1__R_s_b_3_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_137282_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1: sym_137265_0_return_symbol = s_b_31_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_137265_0_return_symbol, s_b_31_0);
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
    /* execute.a64:2768 [D] s_b_32_1: sym_137282_1__R_s_b_3_0 = s_b_32_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_137282_1__R_s_b_3_0, s_b_32_0);
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
    /* execute.a64:2770 [D] s_b_33_1: sym_137282_1__R_s_b_3_0 = s_b_33_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_137282_1__R_s_b_3_0, s_b_33_0);
    /* execute.a64:2770 [F] s_b_33_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_8,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2810 [D] s_b_34_0 = sym_137360_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_137360_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_34_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_34_2 = s_b_34_0&s_b_34_1 */
    auto s_b_34_2 = emitter.bitwise_and(s_b_34_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_34_3: sym_137360_3_parameter_value = s_b_34_2, dominates: s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_137360_3_parameter_value, s_b_34_2);
    /* execute.a64:2810 [F] s_b_34_4: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_8, b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2813 [F] s_b_35_0=sym_31012_3_parameter_inst.rn (const) */
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
    /* execute.a64:2814 [D] s_b_36_0 = sym_137360_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_137360_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_36_1: sym_137431_3_parameter_value = s_b_36_0, dominates: s_b_42_0 s_b_43_0 s_b_44_0  */
    emitter.store_local(DV_sym_137431_3_parameter_value, s_b_36_0);
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
    /* execute.a64:2816 [F] s_b_37_0=sym_31012_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_37_1 = sym_137360_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_137360_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2714 [F] s_b_39_1: sym_137392_1_temporary_value = s_b_39_0 (const), dominates: s_b_40_0  */
    CV_sym_137392_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_137392_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_39_2: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_39, b_41,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2714 [D] s_b_40_0 = sym_137392_1_temporary_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_137392_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_40_1 = sym_137419_1_tmp_s_b_57_0 uint64_t */
    auto s_b_40_1 = emitter.load_local(DV_sym_137419_1_tmp_s_b_57_0, emitter.context().types().u64());
    /* execute.simd:2636 [D] s_b_40_2 = s_b_40_1+s_b_40_0 */
    auto s_b_40_2 = emitter.add(s_b_40_1, s_b_40_0);
    /* execute.simd:2636 [D] s_b_40_3: sym_31018_0_address = s_b_40_2, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_31018_0_address, s_b_40_2);
    /* execute.simd:2636 [F] s_b_40_4: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_28,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2714 [F] s_b_41_0=sym_31012_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_41_1 = ReadRegBank 0:s_b_41_0 (u64) */
    auto s_b_41_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_41_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_41_2: sym_137392_1_temporary_value = s_b_41_1, dominates: s_b_40_0  */
    emitter.store_local(DV_sym_137392_1_temporary_value, s_b_41_1);
    /* execute.a64:2714 [F] s_b_41_3: Jump b_40 (const) */
    goto fixed_block_b_40;
  }
  /* b_36,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2778 [D] s_b_42_0 = sym_137431_3_parameter_value uint64_t */
    auto s_b_42_0 = emitter.load_local(DV_sym_137431_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2781 [D] s_b_43_0 = sym_137431_3_parameter_value uint64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_137431_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2783 [D] s_b_44_0 = sym_137431_3_parameter_value uint64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_137431_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stnp(const arm64_decode_a64_LS_NO_ALLOC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_141095_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_141488_1_temporary_value;
  auto DV_sym_141488_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141199_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141414_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31418_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141603_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_141889_1_temporary_value;
  auto DV_sym_141889_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141078_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_141675_1_temporary_value;
  auto DV_sym_141675_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_141271_1_temporary_value;
  auto DV_sym_141271_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_141815_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141567_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_141365_1_tmp_s_b_1_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:929 [F] s_b_0_0=sym_31409_3_parameter_inst.rn (const) */
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
  /* b_6,  */
  fixed_block_b_1: 
  {
    /* execute.a64:932 [D] s_b_1_0 = sym_31418_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31418_0_addr, emitter.context().types().u64());
    /* execute.a64:932 [F] s_b_1_1=sym_31409_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_1_2: sym_141365_1_tmp_s_b_1_0 = s_b_1_0, dominates: s_b_14_5  */
    emitter.store_local(DV_sym_141365_1_tmp_s_b_1_0, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_3: sym_141199_1_tmp_s_b_4_0 = s_b_1_0, dominates: s_b_14_2  */
    emitter.store_local(DV_sym_141199_1_tmp_s_b_4_0, s_b_1_0);
    /* execute.a64:2709 [F] s_b_1_4 = (u32)s_b_1_1 (const) */
    /* execute.a64:2709 [F] s_b_1_5 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_1_7: If s_b_1_6: Jump b_12 else b_13 (const) */
    if (s_b_1_6) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_20, b_23,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_6,  */
  fixed_block_b_3: 
  {
    /* execute.a64:935 [D] s_b_3_0 = sym_31418_0_addr uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31418_0_addr, emitter.context().types().u64());
    /* execute.a64:935 [F] s_b_3_1=sym_31409_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_141567_1_tmp_s_b_3_0 = s_b_3_0, dominates: s_b_17_3  */
    emitter.store_local(DV_sym_141567_1_tmp_s_b_3_0, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_3: sym_141414_1_tmp_s_b_5_0 = s_b_3_0, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_141414_1_tmp_s_b_5_0, s_b_3_0);
    /* execute.a64:2714 [F] s_b_3_4 = (u32)s_b_3_1 (const) */
    /* execute.a64:2714 [F] s_b_3_5 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_3_7: If s_b_3_6: Jump b_15 else b_16 (const) */
    if (s_b_3_6) 
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
    /* execute.a64:2796 [F] s_b_5_0=sym_31409_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_141078_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_141078_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_141078_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_141078_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:929 [F] s_b_6_1=sym_31409_3_parameter_inst.imms64 (const) */
    /* execute.a64:929 [F] s_b_6_2 = (u64)s_b_6_1 (const) */
    /* execute.a64:929 [D] s_b_6_3 = s_b_6_0+s_b_6_2 */
    auto s_b_6_3 = emitter.add(s_b_6_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:929 [D] s_b_6_4: sym_31418_0_addr = s_b_6_3, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_31418_0_addr, s_b_6_3);
    /* execute.a64:931 [F] s_b_6_5=sym_31409_3_parameter_inst.opc (const) */
    /* execute.a64:931 [F] s_b_6_6 = (u32)s_b_6_5 (const) */
    /* execute.a64:931 [F] s_b_6_7 = constant u32 0 (const) */
    /* execute.a64:931 [F] s_b_6_8 = s_b_6_6==s_b_6_7 (const) */
    uint8_t s_b_6_8 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:931 [F] s_b_6_9: If s_b_6_8: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2765 [D] s_b_7_0 = ReadReg 21 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_7_1: sym_141095_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141095_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2794 [D] s_b_9_0 = sym_141095_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_141095_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_141078_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_141078_0_return_symbol, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_141095_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141095_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_141095_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_141095_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_12_1: sym_141271_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_141271_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_141271_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_1,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [F] s_b_13_0=sym_31409_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_13_2: sym_141271_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_141271_1_temporary_value, s_b_13_1);
    /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_141271_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_141271_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_2 = sym_141199_1_tmp_s_b_4_0 uint64_t */
    auto s_b_14_2 = emitter.load_local(DV_sym_141199_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:1855 [D] s_b_14_3 = (u32)s_b_14_1 */
    auto s_b_14_3 = emitter.truncate(s_b_14_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_14_4: Store 4 s_b_14_2 <= s_b_14_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_14_2, s_b_14_3, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_14_2, s_b_14_3);
    /* ???:4294967295 [D] s_b_14_5 = sym_141365_1_tmp_s_b_1_0 uint64_t */
    auto s_b_14_5 = emitter.load_local(DV_sym_141365_1_tmp_s_b_1_0, emitter.context().types().u64());
    /* execute.a64:933 [F] s_b_14_6 = constant u64 4 (const) */
    /* execute.a64:933 [D] s_b_14_7 = s_b_14_5+s_b_14_6 */
    auto s_b_14_7 = emitter.add(s_b_14_5, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:933 [F] s_b_14_8=sym_31409_3_parameter_inst.rt2 (const) */
    /* ???:4294967295 [D] s_b_14_9: sym_141603_1_tmp_s_b_4_0 = s_b_14_7, dominates: s_b_20_2  */
    emitter.store_local(DV_sym_141603_1_tmp_s_b_4_0, s_b_14_7);
    /* execute.a64:2709 [F] s_b_14_10 = (u32)s_b_14_8 (const) */
    /* execute.a64:2709 [F] s_b_14_11 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_14_12 = s_b_14_10==s_b_14_11 (const) */
    uint8_t s_b_14_12 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_14_13: If s_b_14_12: Jump b_18 else b_19 (const) */
    if (s_b_14_12) 
    {
      goto fixed_block_b_18;
    }
    else 
    {
      goto fixed_block_b_19;
    }
  }
  /* b_3,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2714 [F] s_b_15_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_15_1: sym_141488_1_temporary_value = s_b_15_0 (const), dominates: s_b_17_0  */
    CV_sym_141488_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_141488_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_3,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2714 [F] s_b_16_0=sym_31409_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_16_1 = ReadRegBank 0:s_b_16_0 (u64) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_16_2: sym_141488_1_temporary_value = s_b_16_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_141488_1_temporary_value, s_b_16_1);
    /* execute.a64:2714 [F] s_b_16_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2714 [D] s_b_17_0 = sym_141488_1_temporary_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_141488_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = sym_141414_1_tmp_s_b_5_0 uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_141414_1_tmp_s_b_5_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_2: Store 8 s_b_17_1 <= s_b_17_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_17_1, s_b_17_0, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_17_1, s_b_17_0);
    /* ???:4294967295 [D] s_b_17_3 = sym_141567_1_tmp_s_b_3_0 uint64_t */
    auto s_b_17_3 = emitter.load_local(DV_sym_141567_1_tmp_s_b_3_0, emitter.context().types().u64());
    /* execute.a64:936 [F] s_b_17_4 = constant u64 8 (const) */
    /* execute.a64:936 [D] s_b_17_5 = s_b_17_3+s_b_17_4 */
    auto s_b_17_5 = emitter.add(s_b_17_3, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:936 [F] s_b_17_6=sym_31409_3_parameter_inst.rt2 (const) */
    /* ???:4294967295 [D] s_b_17_7: sym_141815_1_tmp_s_b_5_0 = s_b_17_5, dominates: s_b_23_1  */
    emitter.store_local(DV_sym_141815_1_tmp_s_b_5_0, s_b_17_5);
    /* execute.a64:2714 [F] s_b_17_8 = (u32)s_b_17_6 (const) */
    /* execute.a64:2714 [F] s_b_17_9 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_17_10 = s_b_17_8==s_b_17_9 (const) */
    uint8_t s_b_17_10 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_17_11: If s_b_17_10: Jump b_21 else b_22 (const) */
    if (s_b_17_10) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_22;
    }
  }
  /* b_14,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2709 [F] s_b_18_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_18_1: sym_141675_1_temporary_value = s_b_18_0 (const), dominates: s_b_20_0  */
    CV_sym_141675_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_141675_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_18_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_14,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2709 [F] s_b_19_0=sym_31409_3_parameter_inst.rt2 (const) */
    /* execute.a64:2709 [D] s_b_19_1 = ReadRegBank 1:s_b_19_0 (u32) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_19_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_19_2: sym_141675_1_temporary_value = s_b_19_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_141675_1_temporary_value, s_b_19_1);
    /* execute.a64:2709 [F] s_b_19_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_18, b_19,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2709 [D] s_b_20_0 = sym_141675_1_temporary_value uint32_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_141675_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_20_1 = (u64)s_b_20_0 */
    auto s_b_20_1 = emitter.zx(s_b_20_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_2 = sym_141603_1_tmp_s_b_4_0 uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_141603_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:1855 [D] s_b_20_3 = (u32)s_b_20_1 */
    auto s_b_20_3 = emitter.truncate(s_b_20_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_20_4: Store 4 s_b_20_2 <= s_b_20_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_3, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_20_2, s_b_20_3);
    /* execute.a64:0 [F] s_b_20_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_17,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2714 [F] s_b_21_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_21_1: sym_141889_1_temporary_value = s_b_21_0 (const), dominates: s_b_23_0  */
    CV_sym_141889_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_141889_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_21_2: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_17,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2714 [F] s_b_22_0=sym_31409_3_parameter_inst.rt2 (const) */
    /* execute.a64:2714 [D] s_b_22_1 = ReadRegBank 0:s_b_22_0 (u64) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_22_2: sym_141889_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_141889_1_temporary_value, s_b_22_1);
    /* execute.a64:2714 [F] s_b_22_3: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [D] s_b_23_0 = sym_141889_1_temporary_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_141889_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_23_1 = sym_141815_1_tmp_s_b_5_0 uint64_t */
    auto s_b_23_1 = emitter.load_local(DV_sym_141815_1_tmp_s_b_5_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_23_2: Store 8 s_b_23_1 <= s_b_23_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_23_1, s_b_23_0, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_23_1, s_b_23_0);
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_strb(const arm64_decode_a64_LS_REG_IMM_POST&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_146467_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_146591_1_temporary_value;
  auto DV_sym_146591_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_32296_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_146484_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_146627_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_146666_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1060 [F] s_b_0_0=sym_32290_3_parameter_inst.rn (const) */
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
    /* execute.a64:1063 [D] s_b_1_0 = sym_32296_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_32296_0_address, emitter.context().types().u64());
    /* execute.a64:1063 [F] s_b_1_1=sym_32290_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_1_2 = (u64)s_b_1_1 (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1063 [D] s_b_1_4: sym_32296_0_address = s_b_1_3, dominates: s_b_15_3 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_32296_0_address, s_b_1_3);
    /* execute.a64:1063 [F] s_b_1_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1066 [F] s_b_2_0=sym_32290_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2709 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_2_4: If s_b_2_3: Jump b_13 else b_14 (const) */
    if (s_b_2_3) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_15,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1070 [D] s_b_3_0 = sym_32296_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_32296_0_address, emitter.context().types().u64());
    /* execute.a64:1070 [F] s_b_3_1=sym_32290_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_3_2 = (u64)s_b_3_1 (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1070 [D] s_b_3_4: sym_32296_0_address = s_b_3_3, dominates: s_b_4_1  */
    emitter.store_local(DV_sym_32296_0_address, s_b_3_3);
    /* execute.a64:1070 [F] s_b_3_5: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_15,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1073 [F] s_b_4_0 = constant u8 1 (const) */
    /* execute.a64:1073 [D] s_b_4_1 = sym_32296_0_address uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_32296_0_address, emitter.context().types().u64());
    /* execute.a64:1073 [D] s_b_4_2: sym_146627_3_parameter_value = s_b_4_1, dominates: s_b_16_0 s_b_18_0 s_b_19_1  */
    emitter.store_local(DV_sym_146627_3_parameter_value, s_b_4_1);
    /* execute.a64:2809 [F] s_b_4_3 = !s_b_4_0 (const) */
    uint8_t s_b_4_3 = !(uint8_t)1ULL;
    /* execute.a64:2809 [F] s_b_4_4: If s_b_4_3: Jump b_16 else b_17 (const) */
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
    /* execute.a64:2796 [F] s_b_6_0=sym_32290_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_6_1 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_6_2: sym_146467_0_return_symbol = s_b_6_1, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_146467_0_return_symbol, s_b_6_1);
    /* ???:4294967295 [F] s_b_6_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_10,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [D] s_b_7_0 = sym_146467_0_return_symbol uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_146467_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1060 [D] s_b_7_1: sym_32296_0_address = s_b_7_0, dominates: s_b_1_0 s_b_15_3 s_b_3_0 s_b_4_1  */
    emitter.store_local(DV_sym_32296_0_address, s_b_7_0);
    /* execute.a64:1062 [F] s_b_7_2=sym_32290_3_parameter_inst.P (const) */
    /* execute.a64:1062 [F] s_b_7_3: If s_b_7_2: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2765 [D] s_b_8_1: sym_146484_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_146484_1__R_s_b_3_0, s_b_8_0);
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
    /* execute.a64:2794 [D] s_b_10_0 = sym_146484_1__R_s_b_3_0 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_146484_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1: sym_146467_0_return_symbol = s_b_10_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_146467_0_return_symbol, s_b_10_0);
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
    /* execute.a64:2768 [D] s_b_11_1: sym_146484_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_146484_1__R_s_b_3_0, s_b_11_0);
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
    /* execute.a64:2770 [D] s_b_12_1: sym_146484_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_146484_1__R_s_b_3_0, s_b_12_0);
    /* execute.a64:2770 [F] s_b_12_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_2,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_13_1: sym_146591_1_temporary_value = s_b_13_0 (const), dominates: s_b_15_0  */
    CV_sym_146591_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_146591_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_2,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [F] s_b_14_0=sym_32290_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_14_1 = ReadRegBank 1:s_b_14_0 (u32) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_14_2: sym_146591_1_temporary_value = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_146591_1_temporary_value, s_b_14_1);
    /* execute.a64:2709 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_13, b_14,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2709 [D] s_b_15_0 = sym_146591_1_temporary_value uint32_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_146591_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_15_1 = (u64)s_b_15_0 */
    auto s_b_15_1 = emitter.zx(s_b_15_0, emitter.context().types().u64());
    /* execute.a64:1066 [D] s_b_15_2 = (u8)s_b_15_1 */
    auto s_b_15_2 = emitter.truncate(s_b_15_1, emitter.context().types().u8());
    /* execute.a64:1067 [D] s_b_15_3 = sym_32296_0_address uint64_t */
    auto s_b_15_3 = emitter.load_local(DV_sym_32296_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_4: Store 1 s_b_15_3 <= s_b_15_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_15_3, s_b_15_2, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_15_3, s_b_15_2);
    /* execute.a64:1069 [F] s_b_15_5=sym_32290_3_parameter_inst.P (const) */
    /* execute.a64:1069 [F] s_b_15_6 = !s_b_15_5 (const) */
    uint8_t s_b_15_6 = !insn.P;
    /* execute.a64:1069 [F] s_b_15_7: If s_b_15_6: Jump b_3 else b_4 (const) */
    if (s_b_15_6) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_4;
    }
  }
  /* b_4,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2810 [D] s_b_16_0 = sym_146627_3_parameter_value uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_146627_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_16_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_16_2 = s_b_16_0&s_b_16_1 */
    auto s_b_16_2 = emitter.bitwise_and(s_b_16_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_16_3: sym_146627_3_parameter_value = s_b_16_2, dominates: s_b_18_0 s_b_19_1  */
    emitter.store_local(DV_sym_146627_3_parameter_value, s_b_16_2);
    /* execute.a64:2810 [F] s_b_16_4: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_4, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2813 [F] s_b_17_0=sym_32290_3_parameter_inst.rn (const) */
    /* execute.a64:2813 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
    /* execute.a64:2813 [F] s_b_17_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_17_3 = s_b_17_1==s_b_17_2 (const) */
    uint8_t s_b_17_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2813 [F] s_b_17_4: If s_b_17_3: Jump b_18 else b_19 (const) */
    if (s_b_17_3) 
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
    /* execute.a64:2814 [D] s_b_18_0 = sym_146627_3_parameter_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_146627_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_18_1: sym_146666_3_parameter_value = s_b_18_0, dominates: s_b_21_0 s_b_22_0 s_b_23_0  */
    emitter.store_local(DV_sym_146666_3_parameter_value, s_b_18_0);
    /* execute.a64:2777 [F] s_b_18_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_18_3 = __builtin_get_feature */
    uint32_t s_b_18_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_18_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_18_5 = s_b_18_3==s_b_18_4 (const) */
    uint8_t s_b_18_5 = ((uint8_t)(s_b_18_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_18_6: If s_b_18_5: Jump b_21 else b_24 (const) */
    if (s_b_18_5) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_17,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2816 [F] s_b_19_0=sym_32290_3_parameter_inst.rn (const) */
    /* execute.a64:2816 [D] s_b_19_1 = sym_146627_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_146627_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_19_1);
    /* execute.a64:2816 [F] s_b_19_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_19, b_21, b_22, b_23,  */
  fixed_block_b_20: 
  {
    /* ???:4294967295 [F] s_b_20_0: Return */
    goto fixed_done;
  }
  /* b_18,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2778 [D] s_b_21_0 = sym_146666_3_parameter_value uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_146666_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_21_1: WriteReg 21 = s_b_21_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_21_0);
    /* execute.a64:2778 [F] s_b_21_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_24,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2781 [D] s_b_22_0 = sym_146666_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_146666_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_22_1: WriteReg 21 = s_b_22_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_22_0);
    /* execute.a64:2781 [F] s_b_22_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_24,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2783 [D] s_b_23_0 = sym_146666_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_146666_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_23_1: WriteReg 22 = s_b_23_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_23_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_23_0);
    /* execute.a64:2783 [F] s_b_23_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_18,  */
  fixed_block_b_24: 
  {
    /* execute.a64:3075 [F] s_b_24_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_24_1 = __builtin_get_feature */
    uint32_t s_b_24_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_24_2 = (u8)s_b_24_1 (const) */
    /* execute.a64:2780 [F] s_b_24_3 = (u32)s_b_24_2 (const) */
    /* execute.a64:2780 [F] s_b_24_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_24_5 = s_b_24_3==s_b_24_4 (const) */
    uint8_t s_b_24_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_24_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_24_6: If s_b_24_5: Jump b_22 else b_23 (const) */
    if (s_b_24_5) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sttrb(const arm64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_stxrh(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_33059_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_152155_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_151994_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152085_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_151977_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:720 [F] s_b_0_0=sym_33053_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_5_0=sym_33053_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_151977_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_151977_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_151977_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_151977_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:720 [D] s_b_6_1: sym_33059_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_33059_0_address, s_b_6_0);
    /* execute.a64:722 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:722 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:722 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
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
    /* execute.a64:2765 [D] s_b_7_1: sym_151994_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_151994_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2794 [D] s_b_9_0 = sym_151994_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_151994_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_151977_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_151977_0_return_symbol, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_151994_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_151994_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_151994_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_151994_1__R_s_b_3_0, s_b_11_0);
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
        /* execute.a64:723 [D] s_b_1_0 = sym_33059_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_33059_0_address, emitter.context().types().u64());
        /* execute.a64:723 [F] s_b_1_1=sym_33053_3_parameter_inst.rt (const) */
        /* ???:4294967295 [D] s_b_1_2: sym_152085_1_tmp_s_b_3_0 = s_b_1_0, dominates: s_b_14_2  */
        emitter.store_local(DV_sym_152085_1_tmp_s_b_3_0, s_b_1_0);
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
        /* execute.a64:726 [F] s_b_3_0=sym_33053_3_parameter_inst.rs (const) */
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
        /* execute.a64:2709 [D] s_b_12_1: sym_152155_1_temporary_value = s_b_12_0, dominates: s_b_14_0  */
        emitter.store_local(DV_sym_152155_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_13_0=sym_33053_3_parameter_inst.rt (const) */
        /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
        auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_13_2: sym_152155_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
        emitter.store_local(DV_sym_152155_1_temporary_value, s_b_13_1);
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
        /* execute.a64:2709 [D] s_b_14_0 = sym_152155_1_temporary_value uint32_t */
        auto s_b_14_0 = emitter.load_local(DV_sym_152155_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
        auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
        /* ???:4294967295 [D] s_b_14_2 = sym_152085_1_tmp_s_b_3_0 uint64_t */
        auto s_b_14_2 = emitter.load_local(DV_sym_152085_1_tmp_s_b_3_0, emitter.context().types().u64());
        /* execute.a64:1850 [D] s_b_14_3 = (u16)s_b_14_1 */
        auto s_b_14_3 = emitter.truncate(s_b_14_1, emitter.context().types().u16());
        /* ???:4294967295 [D] s_b_14_4: Store 2 s_b_14_2 <= s_b_14_3 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_14_2, s_b_14_3, emitter.const_u8(2));
        }
        emitter.store_memory(s_b_14_2, s_b_14_3);
        /* execute.a64:724 [F] s_b_14_5=sym_33053_3_parameter_inst.rs (const) */
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
        /* execute.a64:2739 [F] s_b_15_0=sym_33053_3_parameter_inst.rs (const) */
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
        /* execute.a64:2739 [F] s_b_16_0=sym_33053_3_parameter_inst.rs (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_tbz(const arm64_decode_a64_TEST_B_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_12 = emitter.context().create_block();
  uint64_t CV_sym_154501_1_temporary_value;
  auto DV_sym_154501_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_154510_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_154515_1_temporary_value;
  auto DV_sym_154515_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:588 [F] s_b_0_0=sym_36247_3_parameter_inst.b5 (const) */
    /* execute.a64:2719 [F] s_b_0_1: If s_b_0_0: Jump b_3 else b_6 (const) */
    if (insn.b5) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  // BLOCK b_1 not fully fixed
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2720 [F] s_b_3_0=sym_36247_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:2714 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:2714 [F] s_b_4_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_4_1: sym_154501_1_temporary_value = s_b_4_0 (const), dominates: s_b_9_0  */
    CV_sym_154501_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_154501_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_4_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2714 [F] s_b_5_0=sym_36247_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_5_2: sym_154501_1_temporary_value = s_b_5_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_154501_1_temporary_value, s_b_5_1);
    /* execute.a64:2714 [F] s_b_5_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2722 [F] s_b_6_0=sym_36247_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2709 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_6_4: If s_b_6_3: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2709 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_7_1: sym_154515_1_temporary_value = s_b_7_0 (const), dominates: s_b_11_0  */
    CV_sym_154515_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_154515_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_7_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2709 [F] s_b_8_0=sym_36247_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_8_1 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_8_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_8_2: sym_154515_1_temporary_value = s_b_8_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_154515_1_temporary_value, s_b_8_1);
    /* execute.a64:2709 [F] s_b_8_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_4, b_5,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2714 [D] s_b_9_0 = sym_154501_1_temporary_value uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_154501_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_154510_0_return_symbol = s_b_9_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_154510_0_return_symbol, s_b_9_0);
    /* ???:4294967295 [F] s_b_9_2: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_11,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_154510_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_154510_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:590 [F] s_b_10_1=sym_36247_3_parameter_inst.bit_pos (const) */
    /* execute.a64:590 [F] s_b_10_2 = (u64)s_b_10_1 (const) */
    /* execute.a64:590 [D] s_b_10_3 = s_b_10_0>>s_b_10_2 */
    auto s_b_10_3 = emitter.shr(s_b_10_0, emitter.const_u64(((uint64_t)insn.bit_pos)));
    /* execute.a64:590 [F] s_b_10_4 = constant u64 1 (const) */
    /* execute.a64:590 [D] s_b_10_5 = s_b_10_3&s_b_10_4 */
    auto s_b_10_5 = emitter.bitwise_and(s_b_10_3, emitter.const_u64((uint64_t)1ULL));
    /* execute.a64:590 [F] s_b_10_6=sym_36247_3_parameter_inst.op (const) */
    /* execute.a64:590 [F] s_b_10_7 = (u64)s_b_10_6 (const) */
    /* execute.a64:590 [D] s_b_10_8 = s_b_10_5==s_b_10_7 */
    auto s_b_10_8 = emitter.cmp_eq(s_b_10_5, emitter.const_u64(((uint64_t)insn.op)));
    /* execute.a64:590 [D] s_b_10_9: If s_b_10_8: Jump b_1 else b_12 */
    {
      captive::arch::dbt::el::Block *true_target;
      {
        auto block = block_b_1;
        dynamic_block_queue.push(block_b_1);
        true_target = block;
      }
      captive::arch::dbt::el::Block *false_target;
      {
        auto block = block_b_12;
        dynamic_block_queue.push(block_b_12);
        false_target = block;
      }
      emitter.branch(s_b_10_8, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_7, b_8,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [D] s_b_11_0 = sym_154515_1_temporary_value uint32_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_154515_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_11_1 = (u64)s_b_11_0 */
    auto s_b_11_1 = emitter.zx(s_b_11_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_2: sym_154510_0_return_symbol = s_b_11_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_154510_0_return_symbol, s_b_11_1);
    /* ???:4294967295 [F] s_b_11_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
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
      if (block_index == block_b_1) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_1);
        /* execute.a64:591 [D] s_b_1_0 = read_pc */
        auto s_b_1_0 = emitter.load_pc();
        /* execute.a64:591 [D] s_b_1_1 = (s64)s_b_1_0 */
        auto s_b_1_1 = emitter.reinterpret(s_b_1_0, emitter.context().types().s64());
        /* execute.a64:591 [F] s_b_1_2=sym_36247_3_parameter_inst.imms64 (const) */
        /* execute.a64:591 [D] s_b_1_3 = s_b_1_1+s_b_1_2 */
        auto s_b_1_3 = emitter.add(s_b_1_1, emitter.const_s64(insn.imms64));
        /* execute.a64:591 [D] s_b_1_4 = (u64)s_b_1_3 */
        auto s_b_1_4 = emitter.reinterpret(s_b_1_3, emitter.context().types().u64());
        /* execute.a64:571 [D] s_b_1_5 = write_pc */
        emitter.store_pc(s_b_1_4);
        /* execute.a64:572 [D] s_b_1_6 = __branch_taken */
        emitter.call(__captive___branch_taken);
        /* ???:4294967295 [F] s_b_1_7: Jump b_2 (const) */
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
        /* execute.a64:0 [F] s_b_12_5: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ucvtf_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4294 [F] s_b_0_0=sym_39650_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4294 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4295 [F] s_b_1_0=sym_39650_3_parameter_inst.size (const) */
    /* execute.simd:4295 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4295 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4295 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4295 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4303 [F] s_b_3_0=sym_39650_3_parameter_inst.size (const) */
    /* execute.simd:4303 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4303 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4303 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4303 [F] s_b_3_4=sym_39650_3_parameter_inst.Q (const) */
    /* execute.simd:4303 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4303 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:4303 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4303 [F] s_b_3_12: If s_b_3_11: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4297 [F] s_b_4_0=sym_39650_3_parameter_inst.rd (const) */
    /* execute.simd:4297 [F] s_b_4_1=sym_39650_3_parameter_inst.rn (const) */
    /* execute.simd:6232 [D] s_b_4_2 = ReadRegBank 6:s_b_4_1 (u32) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_2,emitter.const_u8(4));
    }
    /* execute.simd:4297 [D] s_b_4_3 = (u32)s_b_4_2 */
    auto s_b_4_3 = (captive::arch::dbt::el::Value *)s_b_4_2;
    /* execute.simd:4297 [D] s_b_4_4 = (f32)s_b_4_3 */
    auto s_b_4_4 = emitter.convert(s_b_4_3, emitter.context().types().f32());
    /* execute.simd:6172 [D] s_b_4_5: WriteRegBank 9:s_b_4_0 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:6173 [F] s_b_4_6 = constant u32 0 (const) */
    /* execute.simd:6173 [F] s_b_4_7: WriteRegBank 10:s_b_4_0 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6174 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:6174 [F] s_b_4_9: WriteRegBank 3:s_b_4_0 = s_b_4_8 */
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
    /* execute.simd:4300 [F] s_b_5_0=sym_39650_3_parameter_inst.rd (const) */
    /* execute.simd:4300 [F] s_b_5_1=sym_39650_3_parameter_inst.rn (const) */
    /* execute.simd:6237 [D] s_b_5_2 = ReadRegBank 7:s_b_5_1 (u64) */
    auto s_b_5_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_2,emitter.const_u8(8));
    }
    /* execute.simd:4300 [D] s_b_5_3 = (u64)s_b_5_2 */
    auto s_b_5_3 = (captive::arch::dbt::el::Value *)s_b_5_2;
    /* execute.simd:4300 [D] s_b_5_4 = (f64)s_b_5_3 */
    auto s_b_5_4 = emitter.convert(s_b_5_3, emitter.context().types().f64());
    /* execute.simd:6180 [D] s_b_5_5: WriteRegBank 11:s_b_5_0 = s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4);
    /* execute.simd:6181 [F] s_b_5_6 = constant u64 0 (const) */
    /* execute.simd:6181 [F] s_b_5_7: WriteRegBank 3:s_b_5_0 = s_b_5_6 */
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
    /* execute.simd:4304 [F] s_b_6_0=sym_39650_3_parameter_inst.rn (const) */
    /* execute.simd:4304 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v2f32 
    {
    }
    (const) */
    /* execute.simd:4307 [F] s_b_6_3 = constant s32 0 (const) */
    /* execute.simd:4307 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4307 [D] s_b_6_5 = (f32)s_b_6_4 */
    auto s_b_6_5 = emitter.convert(s_b_6_4, emitter.context().types().f32());
    /* execute.simd:4307 [F] s_b_6_6 = constant s32 0 (const) */
    /* execute.simd:4307 [D] s_b_6_7 = s_b_6_2[s_b_6_6] <= s_b_6_5 */
    auto s_b_6_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<float, 2>(0.000000)[0], emitter.context().types().v2f32()), emitter.const_s32((int32_t)0ULL), s_b_6_5);
    /* execute.simd:4308 [F] s_b_6_8 = constant s32 1 (const) */
    /* execute.simd:4308 [D] s_b_6_1[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4308 [D] s_b_6_10 = (f32)s_b_6_9 */
    auto s_b_6_10 = emitter.convert(s_b_6_9, emitter.context().types().f32());
    /* execute.simd:4308 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:4308 [D] s_b_6_12 = s_b_6_7[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_7, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:4310 [F] s_b_6_13=sym_39650_3_parameter_inst.rd (const) */
    /* execute.simd:4310 [D] s_b_6_14: WriteRegBank 12:s_b_6_13 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12);
    /* execute.simd:4311 [F] s_b_6_15=sym_39650_3_parameter_inst.rd (const) */
    /* execute.simd:4311 [F] s_b_6_16 = constant u64 0 (const) */
    /* execute.simd:4311 [F] s_b_6_17: WriteRegBank 3:s_b_6_15 = s_b_6_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4304 [F] s_b_6_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4312 [F] s_b_7_0=sym_39650_3_parameter_inst.size (const) */
    /* execute.simd:4312 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4312 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4312 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4312 [F] s_b_7_4=sym_39650_3_parameter_inst.Q (const) */
    /* execute.simd:4312 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4312 [F] s_b_7_6 = constant u32 1 (const) */
    /* execute.simd:4312 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:4312 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4313 [F] s_b_8_0=sym_39650_3_parameter_inst.rn (const) */
    /* execute.simd:4313 [D] s_b_8_1 = ReadRegBank 20:s_b_8_0 (v4u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_2 = constant v4f32 
    {
    }
    (const) */
    /* execute.simd:4316 [F] s_b_8_3 = constant s32 0 (const) */
    /* execute.simd:4316 [D] s_b_8_1[s_b_8_3] */
    auto s_b_8_4 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4316 [D] s_b_8_5 = (f32)s_b_8_4 */
    auto s_b_8_5 = emitter.convert(s_b_8_4, emitter.context().types().f32());
    /* execute.simd:4316 [F] s_b_8_6 = constant s32 0 (const) */
    /* execute.simd:4316 [D] s_b_8_7 = s_b_8_2[s_b_8_6] <= s_b_8_5 */
    auto s_b_8_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<float, 4>(0.000000)[0], emitter.context().types().v4f32()), emitter.const_s32((int32_t)0ULL), s_b_8_5);
    /* execute.simd:4317 [F] s_b_8_8 = constant s32 1 (const) */
    /* execute.simd:4317 [D] s_b_8_1[s_b_8_8] */
    auto s_b_8_9 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4317 [D] s_b_8_10 = (f32)s_b_8_9 */
    auto s_b_8_10 = emitter.convert(s_b_8_9, emitter.context().types().f32());
    /* execute.simd:4317 [F] s_b_8_11 = constant s32 1 (const) */
    /* execute.simd:4317 [D] s_b_8_12 = s_b_8_7[s_b_8_11] <= s_b_8_10 */
    auto s_b_8_12 = emitter.vector_insert(s_b_8_7, emitter.const_s32((int32_t)1ULL), s_b_8_10);
    /* execute.simd:4318 [F] s_b_8_13 = constant s32 2 (const) */
    /* execute.simd:4318 [D] s_b_8_1[s_b_8_13] */
    auto s_b_8_14 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4318 [D] s_b_8_15 = (f32)s_b_8_14 */
    auto s_b_8_15 = emitter.convert(s_b_8_14, emitter.context().types().f32());
    /* execute.simd:4318 [F] s_b_8_16 = constant s32 2 (const) */
    /* execute.simd:4318 [D] s_b_8_17 = s_b_8_12[s_b_8_16] <= s_b_8_15 */
    auto s_b_8_17 = emitter.vector_insert(s_b_8_12, emitter.const_s32((int32_t)2ULL), s_b_8_15);
    /* execute.simd:4319 [F] s_b_8_18 = constant s32 3 (const) */
    /* execute.simd:4319 [D] s_b_8_1[s_b_8_18] */
    auto s_b_8_19 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4319 [D] s_b_8_20 = (f32)s_b_8_19 */
    auto s_b_8_20 = emitter.convert(s_b_8_19, emitter.context().types().f32());
    /* execute.simd:4319 [F] s_b_8_21 = constant s32 3 (const) */
    /* execute.simd:4319 [D] s_b_8_22 = s_b_8_17[s_b_8_21] <= s_b_8_20 */
    auto s_b_8_22 = emitter.vector_insert(s_b_8_17, emitter.const_s32((int32_t)3ULL), s_b_8_20);
    /* execute.simd:4321 [F] s_b_8_23=sym_39650_3_parameter_inst.rd (const) */
    /* execute.simd:4321 [D] s_b_8_24: WriteRegBank 13:s_b_8_23 = s_b_8_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_22,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_22);
    /* execute.simd:4313 [F] s_b_8_25: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4322 [F] s_b_9_0=sym_39650_3_parameter_inst.size (const) */
    /* execute.simd:4322 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4322 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4322 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:4322 [F] s_b_9_4=sym_39650_3_parameter_inst.Q (const) */
    /* execute.simd:4322 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4322 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.simd:4322 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.simd:4322 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
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
    /* execute.simd:4323 [F] s_b_10_0=sym_39650_3_parameter_inst.rn (const) */
    /* execute.simd:4323 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_10_2 = constant v2f64 
    {
    }
    (const) */
    /* execute.simd:4326 [F] s_b_10_3 = constant s32 0 (const) */
    /* execute.simd:4326 [D] s_b_10_1[s_b_10_3] */
    auto s_b_10_4 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4326 [D] s_b_10_5 = (f64)s_b_10_4 */
    auto s_b_10_5 = emitter.convert(s_b_10_4, emitter.context().types().f64());
    /* execute.simd:4326 [F] s_b_10_6 = constant s32 0 (const) */
    /* execute.simd:4326 [D] s_b_10_7 = s_b_10_2[s_b_10_6] <= s_b_10_5 */
    auto s_b_10_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<double, 2>(0.000000)[0], emitter.context().types().v2f64()), emitter.const_s32((int32_t)0ULL), s_b_10_5);
    /* execute.simd:4327 [F] s_b_10_8 = constant s32 1 (const) */
    /* execute.simd:4327 [D] s_b_10_1[s_b_10_8] */
    auto s_b_10_9 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4327 [D] s_b_10_10 = (f64)s_b_10_9 */
    auto s_b_10_10 = emitter.convert(s_b_10_9, emitter.context().types().f64());
    /* execute.simd:4327 [F] s_b_10_11 = constant s32 1 (const) */
    /* execute.simd:4327 [D] s_b_10_12 = s_b_10_7[s_b_10_11] <= s_b_10_10 */
    auto s_b_10_12 = emitter.vector_insert(s_b_10_7, emitter.const_s32((int32_t)1ULL), s_b_10_10);
    /* execute.simd:4329 [F] s_b_10_13=sym_39650_3_parameter_inst.rd (const) */
    /* execute.simd:4329 [D] s_b_10_14: WriteRegBank 14:s_b_10_13 = s_b_10_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_12);
    /* execute.simd:4323 [F] s_b_10_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4331 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4331 [F] s_b_11_1: Jump b_2 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_umull(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5320 [F] s_b_0_0=sym_40857_3_parameter_inst.tb (const) */
    /* execute.simd:5321 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5334 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5347 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5360 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5373 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5386 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5320 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5322 [F] s_b_2_0=sym_40857_3_parameter_inst.rn (const) */
    /* execute.simd:5322 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5323 [F] s_b_2_2=sym_40857_3_parameter_inst.rm (const) */
    /* execute.simd:5323 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
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
    /* execute.simd:5328 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5328 [D] s_b_2_7 = (u16)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_8 = constant u8 0 (const) */
    /* execute.simd:5328 [D] s_b_2_3[s_b_2_8] */
    auto s_b_2_9 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5328 [D] s_b_2_10 = (u16)s_b_2_9 */
    auto s_b_2_10 = emitter.zx(s_b_2_9, emitter.context().types().u16());
    /* execute.simd:5328 [D] s_b_2_11 = s_b_2_7*s_b_2_10 */
    auto s_b_2_11 = emitter.mul(s_b_2_7, s_b_2_10);
    /* execute.simd:5328 [F] s_b_2_12 = constant s32 0 (const) */
    /* execute.simd:5328 [D] s_b_2_13 = s_b_2_4[s_b_2_12] <= s_b_2_11 */
    auto s_b_2_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_11);
    /* ???:4294967295 [F] s_b_2_14 = constant u8 1 (const) */
    /* execute.simd:5328 [D] s_b_2_1[s_b_2_14] */
    auto s_b_2_15 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5328 [D] s_b_2_16 = (u16)s_b_2_15 */
    auto s_b_2_16 = emitter.zx(s_b_2_15, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_17 = constant u8 1 (const) */
    /* execute.simd:5328 [D] s_b_2_3[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5328 [D] s_b_2_19 = (u16)s_b_2_18 */
    auto s_b_2_19 = emitter.zx(s_b_2_18, emitter.context().types().u16());
    /* execute.simd:5328 [D] s_b_2_20 = s_b_2_16*s_b_2_19 */
    auto s_b_2_20 = emitter.mul(s_b_2_16, s_b_2_19);
    /* execute.simd:5328 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:5328 [D] s_b_2_22 = s_b_2_13[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_13, emitter.const_s32((int32_t)1ULL), s_b_2_20);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 2 (const) */
    /* execute.simd:5328 [D] s_b_2_1[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5328 [D] s_b_2_25 = (u16)s_b_2_24 */
    auto s_b_2_25 = emitter.zx(s_b_2_24, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_26 = constant u8 2 (const) */
    /* execute.simd:5328 [D] s_b_2_3[s_b_2_26] */
    auto s_b_2_27 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5328 [D] s_b_2_28 = (u16)s_b_2_27 */
    auto s_b_2_28 = emitter.zx(s_b_2_27, emitter.context().types().u16());
    /* execute.simd:5328 [D] s_b_2_29 = s_b_2_25*s_b_2_28 */
    auto s_b_2_29 = emitter.mul(s_b_2_25, s_b_2_28);
    /* execute.simd:5328 [F] s_b_2_30 = constant s32 2 (const) */
    /* execute.simd:5328 [D] s_b_2_31 = s_b_2_22[s_b_2_30] <= s_b_2_29 */
    auto s_b_2_31 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)2ULL), s_b_2_29);
    /* ???:4294967295 [F] s_b_2_32 = constant u8 3 (const) */
    /* execute.simd:5328 [D] s_b_2_1[s_b_2_32] */
    auto s_b_2_33 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5328 [D] s_b_2_34 = (u16)s_b_2_33 */
    auto s_b_2_34 = emitter.zx(s_b_2_33, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_35 = constant u8 3 (const) */
    /* execute.simd:5328 [D] s_b_2_3[s_b_2_35] */
    auto s_b_2_36 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5328 [D] s_b_2_37 = (u16)s_b_2_36 */
    auto s_b_2_37 = emitter.zx(s_b_2_36, emitter.context().types().u16());
    /* execute.simd:5328 [D] s_b_2_38 = s_b_2_34*s_b_2_37 */
    auto s_b_2_38 = emitter.mul(s_b_2_34, s_b_2_37);
    /* execute.simd:5328 [F] s_b_2_39 = constant s32 3 (const) */
    /* execute.simd:5328 [D] s_b_2_40 = s_b_2_31[s_b_2_39] <= s_b_2_38 */
    auto s_b_2_40 = emitter.vector_insert(s_b_2_31, emitter.const_s32((int32_t)3ULL), s_b_2_38);
    /* ???:4294967295 [F] s_b_2_41 = constant u8 4 (const) */
    /* execute.simd:5328 [D] s_b_2_1[s_b_2_41] */
    auto s_b_2_42 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5328 [D] s_b_2_43 = (u16)s_b_2_42 */
    auto s_b_2_43 = emitter.zx(s_b_2_42, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_44 = constant u8 4 (const) */
    /* execute.simd:5328 [D] s_b_2_3[s_b_2_44] */
    auto s_b_2_45 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5328 [D] s_b_2_46 = (u16)s_b_2_45 */
    auto s_b_2_46 = emitter.zx(s_b_2_45, emitter.context().types().u16());
    /* execute.simd:5328 [D] s_b_2_47 = s_b_2_43*s_b_2_46 */
    auto s_b_2_47 = emitter.mul(s_b_2_43, s_b_2_46);
    /* execute.simd:5328 [F] s_b_2_48 = constant s32 4 (const) */
    /* execute.simd:5328 [D] s_b_2_49 = s_b_2_40[s_b_2_48] <= s_b_2_47 */
    auto s_b_2_49 = emitter.vector_insert(s_b_2_40, emitter.const_s32((int32_t)4ULL), s_b_2_47);
    /* ???:4294967295 [F] s_b_2_50 = constant u8 5 (const) */
    /* execute.simd:5328 [D] s_b_2_1[s_b_2_50] */
    auto s_b_2_51 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5328 [D] s_b_2_52 = (u16)s_b_2_51 */
    auto s_b_2_52 = emitter.zx(s_b_2_51, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_53 = constant u8 5 (const) */
    /* execute.simd:5328 [D] s_b_2_3[s_b_2_53] */
    auto s_b_2_54 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5328 [D] s_b_2_55 = (u16)s_b_2_54 */
    auto s_b_2_55 = emitter.zx(s_b_2_54, emitter.context().types().u16());
    /* execute.simd:5328 [D] s_b_2_56 = s_b_2_52*s_b_2_55 */
    auto s_b_2_56 = emitter.mul(s_b_2_52, s_b_2_55);
    /* execute.simd:5328 [F] s_b_2_57 = constant s32 5 (const) */
    /* execute.simd:5328 [D] s_b_2_58 = s_b_2_49[s_b_2_57] <= s_b_2_56 */
    auto s_b_2_58 = emitter.vector_insert(s_b_2_49, emitter.const_s32((int32_t)5ULL), s_b_2_56);
    /* ???:4294967295 [F] s_b_2_59 = constant u8 6 (const) */
    /* execute.simd:5328 [D] s_b_2_1[s_b_2_59] */
    auto s_b_2_60 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5328 [D] s_b_2_61 = (u16)s_b_2_60 */
    auto s_b_2_61 = emitter.zx(s_b_2_60, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_62 = constant u8 6 (const) */
    /* execute.simd:5328 [D] s_b_2_3[s_b_2_62] */
    auto s_b_2_63 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5328 [D] s_b_2_64 = (u16)s_b_2_63 */
    auto s_b_2_64 = emitter.zx(s_b_2_63, emitter.context().types().u16());
    /* execute.simd:5328 [D] s_b_2_65 = s_b_2_61*s_b_2_64 */
    auto s_b_2_65 = emitter.mul(s_b_2_61, s_b_2_64);
    /* execute.simd:5328 [F] s_b_2_66 = constant s32 6 (const) */
    /* execute.simd:5328 [D] s_b_2_67 = s_b_2_58[s_b_2_66] <= s_b_2_65 */
    auto s_b_2_67 = emitter.vector_insert(s_b_2_58, emitter.const_s32((int32_t)6ULL), s_b_2_65);
    /* ???:4294967295 [F] s_b_2_68 = constant u8 7 (const) */
    /* execute.simd:5328 [D] s_b_2_1[s_b_2_68] */
    auto s_b_2_69 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5328 [D] s_b_2_70 = (u16)s_b_2_69 */
    auto s_b_2_70 = emitter.zx(s_b_2_69, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_71 = constant u8 7 (const) */
    /* execute.simd:5328 [D] s_b_2_3[s_b_2_71] */
    auto s_b_2_72 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5328 [D] s_b_2_73 = (u16)s_b_2_72 */
    auto s_b_2_73 = emitter.zx(s_b_2_72, emitter.context().types().u16());
    /* execute.simd:5328 [D] s_b_2_74 = s_b_2_70*s_b_2_73 */
    auto s_b_2_74 = emitter.mul(s_b_2_70, s_b_2_73);
    /* execute.simd:5328 [F] s_b_2_75 = constant s32 7 (const) */
    /* execute.simd:5328 [D] s_b_2_76 = s_b_2_67[s_b_2_75] <= s_b_2_74 */
    auto s_b_2_76 = emitter.vector_insert(s_b_2_67, emitter.const_s32((int32_t)7ULL), s_b_2_74);
    /* execute.simd:5331 [F] s_b_2_77=sym_40857_3_parameter_inst.rd (const) */
    /* execute.simd:5331 [D] s_b_2_78: WriteRegBank 18:s_b_2_77 = s_b_2_76 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_76,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_76);
    /* execute.simd:0 [F] s_b_2_79: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5335 [F] s_b_3_0=sym_40857_3_parameter_inst.rn (const) */
    /* execute.simd:5335 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5336 [F] s_b_3_2=sym_40857_3_parameter_inst.rm (const) */
    /* execute.simd:5336 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5341 [F] s_b_3_5 = constant u32 8 (const) */
    /* execute.simd:5341 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5341 [D] s_b_3_7 = (u16)s_b_3_6 */
    auto s_b_3_7 = emitter.zx(s_b_3_6, emitter.context().types().u16());
    /* execute.simd:5341 [F] s_b_3_8 = constant u32 8 (const) */
    /* execute.simd:5341 [D] s_b_3_3[s_b_3_8] */
    auto s_b_3_9 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5341 [D] s_b_3_10 = (u16)s_b_3_9 */
    auto s_b_3_10 = emitter.zx(s_b_3_9, emitter.context().types().u16());
    /* execute.simd:5341 [D] s_b_3_11 = s_b_3_7*s_b_3_10 */
    auto s_b_3_11 = emitter.mul(s_b_3_7, s_b_3_10);
    /* execute.simd:5341 [F] s_b_3_12 = constant s32 0 (const) */
    /* execute.simd:5341 [D] s_b_3_13 = s_b_3_4[s_b_3_12] <= s_b_3_11 */
    auto s_b_3_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_11);
    /* execute.simd:5341 [F] s_b_3_14 = constant u32 9 (const) */
    /* execute.simd:5341 [D] s_b_3_1[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5341 [D] s_b_3_16 = (u16)s_b_3_15 */
    auto s_b_3_16 = emitter.zx(s_b_3_15, emitter.context().types().u16());
    /* execute.simd:5341 [F] s_b_3_17 = constant u32 9 (const) */
    /* execute.simd:5341 [D] s_b_3_3[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5341 [D] s_b_3_19 = (u16)s_b_3_18 */
    auto s_b_3_19 = emitter.zx(s_b_3_18, emitter.context().types().u16());
    /* execute.simd:5341 [D] s_b_3_20 = s_b_3_16*s_b_3_19 */
    auto s_b_3_20 = emitter.mul(s_b_3_16, s_b_3_19);
    /* execute.simd:5341 [F] s_b_3_21 = constant s32 1 (const) */
    /* execute.simd:5341 [D] s_b_3_22 = s_b_3_13[s_b_3_21] <= s_b_3_20 */
    auto s_b_3_22 = emitter.vector_insert(s_b_3_13, emitter.const_s32((int32_t)1ULL), s_b_3_20);
    /* execute.simd:5341 [F] s_b_3_23 = constant u32 a (const) */
    /* execute.simd:5341 [D] s_b_3_1[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5341 [D] s_b_3_25 = (u16)s_b_3_24 */
    auto s_b_3_25 = emitter.zx(s_b_3_24, emitter.context().types().u16());
    /* execute.simd:5341 [F] s_b_3_26 = constant u32 a (const) */
    /* execute.simd:5341 [D] s_b_3_3[s_b_3_26] */
    auto s_b_3_27 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5341 [D] s_b_3_28 = (u16)s_b_3_27 */
    auto s_b_3_28 = emitter.zx(s_b_3_27, emitter.context().types().u16());
    /* execute.simd:5341 [D] s_b_3_29 = s_b_3_25*s_b_3_28 */
    auto s_b_3_29 = emitter.mul(s_b_3_25, s_b_3_28);
    /* execute.simd:5341 [F] s_b_3_30 = constant s32 2 (const) */
    /* execute.simd:5341 [D] s_b_3_31 = s_b_3_22[s_b_3_30] <= s_b_3_29 */
    auto s_b_3_31 = emitter.vector_insert(s_b_3_22, emitter.const_s32((int32_t)2ULL), s_b_3_29);
    /* execute.simd:5341 [F] s_b_3_32 = constant u32 b (const) */
    /* execute.simd:5341 [D] s_b_3_1[s_b_3_32] */
    auto s_b_3_33 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5341 [D] s_b_3_34 = (u16)s_b_3_33 */
    auto s_b_3_34 = emitter.zx(s_b_3_33, emitter.context().types().u16());
    /* execute.simd:5341 [F] s_b_3_35 = constant u32 b (const) */
    /* execute.simd:5341 [D] s_b_3_3[s_b_3_35] */
    auto s_b_3_36 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5341 [D] s_b_3_37 = (u16)s_b_3_36 */
    auto s_b_3_37 = emitter.zx(s_b_3_36, emitter.context().types().u16());
    /* execute.simd:5341 [D] s_b_3_38 = s_b_3_34*s_b_3_37 */
    auto s_b_3_38 = emitter.mul(s_b_3_34, s_b_3_37);
    /* execute.simd:5341 [F] s_b_3_39 = constant s32 3 (const) */
    /* execute.simd:5341 [D] s_b_3_40 = s_b_3_31[s_b_3_39] <= s_b_3_38 */
    auto s_b_3_40 = emitter.vector_insert(s_b_3_31, emitter.const_s32((int32_t)3ULL), s_b_3_38);
    /* execute.simd:5341 [F] s_b_3_41 = constant u32 c (const) */
    /* execute.simd:5341 [D] s_b_3_1[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5341 [D] s_b_3_43 = (u16)s_b_3_42 */
    auto s_b_3_43 = emitter.zx(s_b_3_42, emitter.context().types().u16());
    /* execute.simd:5341 [F] s_b_3_44 = constant u32 c (const) */
    /* execute.simd:5341 [D] s_b_3_3[s_b_3_44] */
    auto s_b_3_45 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5341 [D] s_b_3_46 = (u16)s_b_3_45 */
    auto s_b_3_46 = emitter.zx(s_b_3_45, emitter.context().types().u16());
    /* execute.simd:5341 [D] s_b_3_47 = s_b_3_43*s_b_3_46 */
    auto s_b_3_47 = emitter.mul(s_b_3_43, s_b_3_46);
    /* execute.simd:5341 [F] s_b_3_48 = constant s32 4 (const) */
    /* execute.simd:5341 [D] s_b_3_49 = s_b_3_40[s_b_3_48] <= s_b_3_47 */
    auto s_b_3_49 = emitter.vector_insert(s_b_3_40, emitter.const_s32((int32_t)4ULL), s_b_3_47);
    /* execute.simd:5341 [F] s_b_3_50 = constant u32 d (const) */
    /* execute.simd:5341 [D] s_b_3_1[s_b_3_50] */
    auto s_b_3_51 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5341 [D] s_b_3_52 = (u16)s_b_3_51 */
    auto s_b_3_52 = emitter.zx(s_b_3_51, emitter.context().types().u16());
    /* execute.simd:5341 [F] s_b_3_53 = constant u32 d (const) */
    /* execute.simd:5341 [D] s_b_3_3[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5341 [D] s_b_3_55 = (u16)s_b_3_54 */
    auto s_b_3_55 = emitter.zx(s_b_3_54, emitter.context().types().u16());
    /* execute.simd:5341 [D] s_b_3_56 = s_b_3_52*s_b_3_55 */
    auto s_b_3_56 = emitter.mul(s_b_3_52, s_b_3_55);
    /* execute.simd:5341 [F] s_b_3_57 = constant s32 5 (const) */
    /* execute.simd:5341 [D] s_b_3_58 = s_b_3_49[s_b_3_57] <= s_b_3_56 */
    auto s_b_3_58 = emitter.vector_insert(s_b_3_49, emitter.const_s32((int32_t)5ULL), s_b_3_56);
    /* execute.simd:5341 [F] s_b_3_59 = constant u32 e (const) */
    /* execute.simd:5341 [D] s_b_3_1[s_b_3_59] */
    auto s_b_3_60 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5341 [D] s_b_3_61 = (u16)s_b_3_60 */
    auto s_b_3_61 = emitter.zx(s_b_3_60, emitter.context().types().u16());
    /* execute.simd:5341 [F] s_b_3_62 = constant u32 e (const) */
    /* execute.simd:5341 [D] s_b_3_3[s_b_3_62] */
    auto s_b_3_63 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5341 [D] s_b_3_64 = (u16)s_b_3_63 */
    auto s_b_3_64 = emitter.zx(s_b_3_63, emitter.context().types().u16());
    /* execute.simd:5341 [D] s_b_3_65 = s_b_3_61*s_b_3_64 */
    auto s_b_3_65 = emitter.mul(s_b_3_61, s_b_3_64);
    /* execute.simd:5341 [F] s_b_3_66 = constant s32 6 (const) */
    /* execute.simd:5341 [D] s_b_3_67 = s_b_3_58[s_b_3_66] <= s_b_3_65 */
    auto s_b_3_67 = emitter.vector_insert(s_b_3_58, emitter.const_s32((int32_t)6ULL), s_b_3_65);
    /* execute.simd:5341 [F] s_b_3_68 = constant u32 f (const) */
    /* execute.simd:5341 [D] s_b_3_1[s_b_3_68] */
    auto s_b_3_69 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5341 [D] s_b_3_70 = (u16)s_b_3_69 */
    auto s_b_3_70 = emitter.zx(s_b_3_69, emitter.context().types().u16());
    /* execute.simd:5341 [F] s_b_3_71 = constant u32 f (const) */
    /* execute.simd:5341 [D] s_b_3_3[s_b_3_71] */
    auto s_b_3_72 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5341 [D] s_b_3_73 = (u16)s_b_3_72 */
    auto s_b_3_73 = emitter.zx(s_b_3_72, emitter.context().types().u16());
    /* execute.simd:5341 [D] s_b_3_74 = s_b_3_70*s_b_3_73 */
    auto s_b_3_74 = emitter.mul(s_b_3_70, s_b_3_73);
    /* execute.simd:5341 [F] s_b_3_75 = constant s32 7 (const) */
    /* execute.simd:5341 [D] s_b_3_76 = s_b_3_67[s_b_3_75] <= s_b_3_74 */
    auto s_b_3_76 = emitter.vector_insert(s_b_3_67, emitter.const_s32((int32_t)7ULL), s_b_3_74);
    /* execute.simd:5344 [F] s_b_3_77=sym_40857_3_parameter_inst.rd (const) */
    /* execute.simd:5344 [D] s_b_3_78: WriteRegBank 18:s_b_3_77 = s_b_3_76 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_76,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_76);
    /* execute.simd:0 [F] s_b_3_79: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5348 [F] s_b_4_0=sym_40857_3_parameter_inst.rn (const) */
    /* execute.simd:5348 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5349 [F] s_b_4_2=sym_40857_3_parameter_inst.rm (const) */
    /* execute.simd:5349 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant v4u32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_5 = constant u8 0 (const) */
    /* execute.simd:5354 [D] s_b_4_1[s_b_4_5] */
    auto s_b_4_6 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5354 [D] s_b_4_7 = (u32)s_b_4_6 */
    auto s_b_4_7 = emitter.zx(s_b_4_6, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_8 = constant u8 0 (const) */
    /* execute.simd:5354 [D] s_b_4_3[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5354 [D] s_b_4_10 = (u32)s_b_4_9 */
    auto s_b_4_10 = emitter.zx(s_b_4_9, emitter.context().types().u32());
    /* execute.simd:5354 [D] s_b_4_11 = s_b_4_7*s_b_4_10 */
    auto s_b_4_11 = emitter.mul(s_b_4_7, s_b_4_10);
    /* execute.simd:5354 [F] s_b_4_12 = constant s32 0 (const) */
    /* execute.simd:5354 [D] s_b_4_13 = s_b_4_4[s_b_4_12] <= s_b_4_11 */
    auto s_b_4_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_4_11);
    /* ???:4294967295 [F] s_b_4_14 = constant u8 1 (const) */
    /* execute.simd:5354 [D] s_b_4_1[s_b_4_14] */
    auto s_b_4_15 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5354 [D] s_b_4_16 = (u32)s_b_4_15 */
    auto s_b_4_16 = emitter.zx(s_b_4_15, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_17 = constant u8 1 (const) */
    /* execute.simd:5354 [D] s_b_4_3[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5354 [D] s_b_4_19 = (u32)s_b_4_18 */
    auto s_b_4_19 = emitter.zx(s_b_4_18, emitter.context().types().u32());
    /* execute.simd:5354 [D] s_b_4_20 = s_b_4_16*s_b_4_19 */
    auto s_b_4_20 = emitter.mul(s_b_4_16, s_b_4_19);
    /* execute.simd:5354 [F] s_b_4_21 = constant s32 1 (const) */
    /* execute.simd:5354 [D] s_b_4_22 = s_b_4_13[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_13, emitter.const_s32((int32_t)1ULL), s_b_4_20);
    /* ???:4294967295 [F] s_b_4_23 = constant u8 2 (const) */
    /* execute.simd:5354 [D] s_b_4_1[s_b_4_23] */
    auto s_b_4_24 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5354 [D] s_b_4_25 = (u32)s_b_4_24 */
    auto s_b_4_25 = emitter.zx(s_b_4_24, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_26 = constant u8 2 (const) */
    /* execute.simd:5354 [D] s_b_4_3[s_b_4_26] */
    auto s_b_4_27 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5354 [D] s_b_4_28 = (u32)s_b_4_27 */
    auto s_b_4_28 = emitter.zx(s_b_4_27, emitter.context().types().u32());
    /* execute.simd:5354 [D] s_b_4_29 = s_b_4_25*s_b_4_28 */
    auto s_b_4_29 = emitter.mul(s_b_4_25, s_b_4_28);
    /* execute.simd:5354 [F] s_b_4_30 = constant s32 2 (const) */
    /* execute.simd:5354 [D] s_b_4_31 = s_b_4_22[s_b_4_30] <= s_b_4_29 */
    auto s_b_4_31 = emitter.vector_insert(s_b_4_22, emitter.const_s32((int32_t)2ULL), s_b_4_29);
    /* ???:4294967295 [F] s_b_4_32 = constant u8 3 (const) */
    /* execute.simd:5354 [D] s_b_4_1[s_b_4_32] */
    auto s_b_4_33 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5354 [D] s_b_4_34 = (u32)s_b_4_33 */
    auto s_b_4_34 = emitter.zx(s_b_4_33, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_35 = constant u8 3 (const) */
    /* execute.simd:5354 [D] s_b_4_3[s_b_4_35] */
    auto s_b_4_36 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5354 [D] s_b_4_37 = (u32)s_b_4_36 */
    auto s_b_4_37 = emitter.zx(s_b_4_36, emitter.context().types().u32());
    /* execute.simd:5354 [D] s_b_4_38 = s_b_4_34*s_b_4_37 */
    auto s_b_4_38 = emitter.mul(s_b_4_34, s_b_4_37);
    /* execute.simd:5354 [F] s_b_4_39 = constant s32 3 (const) */
    /* execute.simd:5354 [D] s_b_4_40 = s_b_4_31[s_b_4_39] <= s_b_4_38 */
    auto s_b_4_40 = emitter.vector_insert(s_b_4_31, emitter.const_s32((int32_t)3ULL), s_b_4_38);
    /* execute.simd:5357 [F] s_b_4_41=sym_40857_3_parameter_inst.rd (const) */
    /* execute.simd:5357 [D] s_b_4_42: WriteRegBank 20:s_b_4_41 = s_b_4_40 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_40,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_40);
    /* execute.simd:0 [F] s_b_4_43: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5361 [F] s_b_5_0=sym_40857_3_parameter_inst.rn (const) */
    /* execute.simd:5361 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5362 [F] s_b_5_2=sym_40857_3_parameter_inst.rm (const) */
    /* execute.simd:5362 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5367 [F] s_b_5_5 = constant u32 4 (const) */
    /* execute.simd:5367 [D] s_b_5_1[s_b_5_5] */
    auto s_b_5_6 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5367 [D] s_b_5_7 = (u32)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u32());
    /* execute.simd:5367 [F] s_b_5_8 = constant u32 4 (const) */
    /* execute.simd:5367 [D] s_b_5_3[s_b_5_8] */
    auto s_b_5_9 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5367 [D] s_b_5_10 = (u32)s_b_5_9 */
    auto s_b_5_10 = emitter.zx(s_b_5_9, emitter.context().types().u32());
    /* execute.simd:5367 [D] s_b_5_11 = s_b_5_7*s_b_5_10 */
    auto s_b_5_11 = emitter.mul(s_b_5_7, s_b_5_10);
    /* execute.simd:5367 [F] s_b_5_12 = constant s32 0 (const) */
    /* execute.simd:5367 [D] s_b_5_13 = s_b_5_4[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_5_11);
    /* execute.simd:5367 [F] s_b_5_14 = constant u32 5 (const) */
    /* execute.simd:5367 [D] s_b_5_1[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5367 [D] s_b_5_16 = (u32)s_b_5_15 */
    auto s_b_5_16 = emitter.zx(s_b_5_15, emitter.context().types().u32());
    /* execute.simd:5367 [F] s_b_5_17 = constant u32 5 (const) */
    /* execute.simd:5367 [D] s_b_5_3[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5367 [D] s_b_5_19 = (u32)s_b_5_18 */
    auto s_b_5_19 = emitter.zx(s_b_5_18, emitter.context().types().u32());
    /* execute.simd:5367 [D] s_b_5_20 = s_b_5_16*s_b_5_19 */
    auto s_b_5_20 = emitter.mul(s_b_5_16, s_b_5_19);
    /* execute.simd:5367 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5367 [D] s_b_5_22 = s_b_5_13[s_b_5_21] <= s_b_5_20 */
    auto s_b_5_22 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)1ULL), s_b_5_20);
    /* execute.simd:5367 [F] s_b_5_23 = constant u32 6 (const) */
    /* execute.simd:5367 [D] s_b_5_1[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5367 [D] s_b_5_25 = (u32)s_b_5_24 */
    auto s_b_5_25 = emitter.zx(s_b_5_24, emitter.context().types().u32());
    /* execute.simd:5367 [F] s_b_5_26 = constant u32 6 (const) */
    /* execute.simd:5367 [D] s_b_5_3[s_b_5_26] */
    auto s_b_5_27 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5367 [D] s_b_5_28 = (u32)s_b_5_27 */
    auto s_b_5_28 = emitter.zx(s_b_5_27, emitter.context().types().u32());
    /* execute.simd:5367 [D] s_b_5_29 = s_b_5_25*s_b_5_28 */
    auto s_b_5_29 = emitter.mul(s_b_5_25, s_b_5_28);
    /* execute.simd:5367 [F] s_b_5_30 = constant s32 2 (const) */
    /* execute.simd:5367 [D] s_b_5_31 = s_b_5_22[s_b_5_30] <= s_b_5_29 */
    auto s_b_5_31 = emitter.vector_insert(s_b_5_22, emitter.const_s32((int32_t)2ULL), s_b_5_29);
    /* execute.simd:5367 [F] s_b_5_32 = constant u32 7 (const) */
    /* execute.simd:5367 [D] s_b_5_1[s_b_5_32] */
    auto s_b_5_33 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5367 [D] s_b_5_34 = (u32)s_b_5_33 */
    auto s_b_5_34 = emitter.zx(s_b_5_33, emitter.context().types().u32());
    /* execute.simd:5367 [F] s_b_5_35 = constant u32 7 (const) */
    /* execute.simd:5367 [D] s_b_5_3[s_b_5_35] */
    auto s_b_5_36 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5367 [D] s_b_5_37 = (u32)s_b_5_36 */
    auto s_b_5_37 = emitter.zx(s_b_5_36, emitter.context().types().u32());
    /* execute.simd:5367 [D] s_b_5_38 = s_b_5_34*s_b_5_37 */
    auto s_b_5_38 = emitter.mul(s_b_5_34, s_b_5_37);
    /* execute.simd:5367 [F] s_b_5_39 = constant s32 3 (const) */
    /* execute.simd:5367 [D] s_b_5_40 = s_b_5_31[s_b_5_39] <= s_b_5_38 */
    auto s_b_5_40 = emitter.vector_insert(s_b_5_31, emitter.const_s32((int32_t)3ULL), s_b_5_38);
    /* execute.simd:5370 [F] s_b_5_41=sym_40857_3_parameter_inst.rd (const) */
    /* execute.simd:5370 [D] s_b_5_42: WriteRegBank 20:s_b_5_41 = s_b_5_40 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_40,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_40);
    /* execute.simd:0 [F] s_b_5_43: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5374 [F] s_b_6_0=sym_40857_3_parameter_inst.rn (const) */
    /* execute.simd:5374 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5375 [F] s_b_6_2=sym_40857_3_parameter_inst.rm (const) */
    /* execute.simd:5375 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_4 = constant v2u64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_5 = constant u8 0 (const) */
    /* execute.simd:5380 [D] s_b_6_1[s_b_6_5] */
    auto s_b_6_6 = emitter.vector_extract(s_b_6_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5380 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_8 = constant u8 0 (const) */
    /* execute.simd:5380 [D] s_b_6_3[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5380 [D] s_b_6_10 = (u64)s_b_6_9 */
    auto s_b_6_10 = emitter.zx(s_b_6_9, emitter.context().types().u64());
    /* execute.simd:5380 [D] s_b_6_11 = s_b_6_7*s_b_6_10 */
    auto s_b_6_11 = emitter.mul(s_b_6_7, s_b_6_10);
    /* execute.simd:5380 [F] s_b_6_12 = constant s32 0 (const) */
    /* execute.simd:5380 [D] s_b_6_13 = s_b_6_4[s_b_6_12] <= s_b_6_11 */
    auto s_b_6_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_6_11);
    /* ???:4294967295 [F] s_b_6_14 = constant u8 1 (const) */
    /* execute.simd:5380 [D] s_b_6_1[s_b_6_14] */
    auto s_b_6_15 = emitter.vector_extract(s_b_6_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5380 [D] s_b_6_16 = (u64)s_b_6_15 */
    auto s_b_6_16 = emitter.zx(s_b_6_15, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_17 = constant u8 1 (const) */
    /* execute.simd:5380 [D] s_b_6_3[s_b_6_17] */
    auto s_b_6_18 = emitter.vector_extract(s_b_6_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5380 [D] s_b_6_19 = (u64)s_b_6_18 */
    auto s_b_6_19 = emitter.zx(s_b_6_18, emitter.context().types().u64());
    /* execute.simd:5380 [D] s_b_6_20 = s_b_6_16*s_b_6_19 */
    auto s_b_6_20 = emitter.mul(s_b_6_16, s_b_6_19);
    /* execute.simd:5380 [F] s_b_6_21 = constant s32 1 (const) */
    /* execute.simd:5380 [D] s_b_6_22 = s_b_6_13[s_b_6_21] <= s_b_6_20 */
    auto s_b_6_22 = emitter.vector_insert(s_b_6_13, emitter.const_s32((int32_t)1ULL), s_b_6_20);
    /* execute.simd:5383 [F] s_b_6_23=sym_40857_3_parameter_inst.rd (const) */
    /* execute.simd:5383 [D] s_b_6_24: WriteRegBank 21:s_b_6_23 = s_b_6_22 */
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
    /* execute.simd:5387 [F] s_b_7_0=sym_40857_3_parameter_inst.rn (const) */
    /* execute.simd:5387 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5388 [F] s_b_7_2=sym_40857_3_parameter_inst.rm (const) */
    /* execute.simd:5388 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_4 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5393 [F] s_b_7_5 = constant u32 2 (const) */
    /* execute.simd:5393 [D] s_b_7_1[s_b_7_5] */
    auto s_b_7_6 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5393 [D] s_b_7_7 = (u64)s_b_7_6 */
    auto s_b_7_7 = emitter.zx(s_b_7_6, emitter.context().types().u64());
    /* execute.simd:5393 [F] s_b_7_8 = constant u32 2 (const) */
    /* execute.simd:5393 [D] s_b_7_3[s_b_7_8] */
    auto s_b_7_9 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5393 [D] s_b_7_10 = (u64)s_b_7_9 */
    auto s_b_7_10 = emitter.zx(s_b_7_9, emitter.context().types().u64());
    /* execute.simd:5393 [D] s_b_7_11 = s_b_7_7*s_b_7_10 */
    auto s_b_7_11 = emitter.mul(s_b_7_7, s_b_7_10);
    /* execute.simd:5393 [F] s_b_7_12 = constant s32 0 (const) */
    /* execute.simd:5393 [D] s_b_7_13 = s_b_7_4[s_b_7_12] <= s_b_7_11 */
    auto s_b_7_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_7_11);
    /* execute.simd:5393 [F] s_b_7_14 = constant u32 3 (const) */
    /* execute.simd:5393 [D] s_b_7_1[s_b_7_14] */
    auto s_b_7_15 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5393 [D] s_b_7_16 = (u64)s_b_7_15 */
    auto s_b_7_16 = emitter.zx(s_b_7_15, emitter.context().types().u64());
    /* execute.simd:5393 [F] s_b_7_17 = constant u32 3 (const) */
    /* execute.simd:5393 [D] s_b_7_3[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5393 [D] s_b_7_19 = (u64)s_b_7_18 */
    auto s_b_7_19 = emitter.zx(s_b_7_18, emitter.context().types().u64());
    /* execute.simd:5393 [D] s_b_7_20 = s_b_7_16*s_b_7_19 */
    auto s_b_7_20 = emitter.mul(s_b_7_16, s_b_7_19);
    /* execute.simd:5393 [F] s_b_7_21 = constant s32 1 (const) */
    /* execute.simd:5393 [D] s_b_7_22 = s_b_7_13[s_b_7_21] <= s_b_7_20 */
    auto s_b_7_22 = emitter.vector_insert(s_b_7_13, emitter.const_s32((int32_t)1ULL), s_b_7_20);
    /* execute.simd:5396 [F] s_b_7_23=sym_40857_3_parameter_inst.rd (const) */
    /* execute.simd:5396 [D] s_b_7_24: WriteRegBank 21:s_b_7_23 = s_b_7_22 */
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
    /* execute.simd:5400 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5320 [F] s_b_8_1: Jump b_1 (const) */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_vldr(const arm64_decode_a64_LS_REG_UIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_158700_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158799_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_158824_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158820_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158810_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158788_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_158774_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158683_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_158776_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3895 [F] s_b_0_0=sym_47207_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_2_0=sym_47207_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_158683_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_158683_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_158683_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_158683_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:3895 [F] s_b_3_1=sym_47207_3_parameter_inst.immu64 (const) */
    /* execute.simd:3895 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:3896 [F] s_b_3_3=sym_47207_3_parameter_inst.size (const) */
    /* execute.simd:3896 [F] s_b_3_4 = (u32)s_b_3_3 (const) */
    /* execute.simd:3896 [F] s_b_3_5 = constant u32 0 (const) */
    /* execute.simd:3896 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:3896 [F] s_b_3_7=sym_47207_3_parameter_inst.opc (const) */
    /* execute.simd:3896 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
    /* execute.simd:3896 [F] s_b_3_9 = constant u32 1 (const) */
    /* execute.simd:3896 [F] s_b_3_10 = s_b_3_8==s_b_3_9 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.simd:3896 [F] s_b_3_11 = constant u8 0 (const) */
    /* execute.simd:3896 [F] s_b_3_12 = constant u8 4 (const) */
    /* execute.simd:3896 [F] s_b_3_13: Select s_b_3_10 ? s_b_3_11 : s_b_3_12 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(s_b_3_10 ? ((uint8_t)0ULL) : ((uint8_t)4ULL)));
    /* execute.simd:3896 [F] s_b_3_14=sym_47207_3_parameter_inst.size (const) */
    /* execute.simd:3896 [F] s_b_3_15 = (u8)s_b_3_14 (const) */
    /* execute.simd:3896 [F] s_b_3_16: Select s_b_3_6 ? s_b_3_13 : s_b_3_15 (const) */
    uint8_t s_b_3_16 = ((uint8_t)(s_b_3_6 ? (s_b_3_13) : (((uint8_t)insn.size))));
    /* ???:4294967295 [D] s_b_3_17: sym_158774_0_replaced_parameter_addr = s_b_3_2, dominates: s_b_9_0 s_b_11_0 s_b_10_0 s_b_13_0 s_b_12_0  */
    emitter.store_local(DV_sym_158774_0_replaced_parameter_addr, s_b_3_2);
    /* execute.simd:3676 [F] s_b_3_18 = constant s32 0 (const) */
    /* execute.simd:3683 [F] s_b_3_19 = constant s32 1 (const) */
    /* execute.simd:3690 [F] s_b_3_20 = constant s32 2 (const) */
    /* execute.simd:3697 [F] s_b_3_21 = constant s32 3 (const) */
    /* execute.simd:3704 [F] s_b_3_22 = constant s32 4 (const) */
    /* execute.simd:3675 [F] s_b_3_23: Switch s_b_3_16: < <todo> > def b_14 (const) -> b_14, b_9, b_11, b_10, b_13, b_12,  */
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
    /* execute.a64:2765 [D] s_b_4_0 = ReadReg 21 (u64) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_4_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_4_1: sym_158700_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_158700_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2794 [D] s_b_6_0 = sym_158700_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_158700_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_158683_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_158683_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2768 [D] s_b_7_1: sym_158700_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_158700_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2770 [D] s_b_8_1: sym_158700_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_158700_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2770 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3679 [D] s_b_9_0 = sym_158774_0_replaced_parameter_addr uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_158774_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1 = Load 1 s_b_9_0 => sym_158776_0_value */
    auto s_b_9_1 = emitter.load_memory(s_b_9_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_158776_0_value, s_b_9_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_0, s_b_9_1, emitter.const_u8(1));
    }
    /* execute.simd:3680 [F] s_b_9_2=sym_47207_3_parameter_inst.rt (const) */
    /* execute.simd:3680 [D] s_b_9_3 = sym_158776_0_value uint8_t */
    auto s_b_9_3 = emitter.load_local(DV_sym_158776_0_value, emitter.context().types().u8());
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
    /* execute.simd:3686 [D] s_b_10_0 = sym_158774_0_replaced_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_158774_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 2 s_b_10_0 => sym_158788_0_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_158788_0_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(2));
    }
    /* execute.simd:3687 [F] s_b_10_2=sym_47207_3_parameter_inst.rt (const) */
    /* execute.simd:3687 [D] s_b_10_3 = sym_158788_0_value uint16_t */
    auto s_b_10_3 = emitter.load_local(DV_sym_158788_0_value, emitter.context().types().u16());
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
    /* execute.simd:3693 [D] s_b_11_0 = sym_158774_0_replaced_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_158774_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 4 s_b_11_0 => sym_158799_0_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_158799_0_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(4));
    }
    /* execute.simd:3694 [F] s_b_11_2=sym_47207_3_parameter_inst.rt (const) */
    /* execute.simd:3694 [D] s_b_11_3 = sym_158799_0_value uint32_t */
    auto s_b_11_3 = emitter.load_local(DV_sym_158799_0_value, emitter.context().types().u32());
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
    /* execute.simd:3700 [D] s_b_12_0 = sym_158774_0_replaced_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_158774_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 8 s_b_12_0 => sym_158810_0_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_158810_0_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(8));
    }
    /* execute.simd:3701 [F] s_b_12_2=sym_47207_3_parameter_inst.rt (const) */
    /* execute.simd:3701 [D] s_b_12_3 = sym_158810_0_value uint64_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_158810_0_value, emitter.context().types().u64());
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
    /* execute.simd:3708 [D] s_b_13_0 = sym_158774_0_replaced_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_158774_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 8 s_b_13_0 => sym_158820_0_vl */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_158820_0_vl, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(8));
    }
    /* execute.simd:3709 [F] s_b_13_2 = constant u64 8 (const) */
    /* execute.simd:3709 [D] s_b_13_3 = s_b_13_0+s_b_13_2 */
    auto s_b_13_3 = emitter.add(s_b_13_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_13_4 = Load 8 s_b_13_3 => sym_158824_0_vh */
    auto s_b_13_4 = emitter.load_memory(s_b_13_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_158824_0_vh, s_b_13_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_3, s_b_13_4, emitter.const_u8(8));
    }
    /* execute.simd:3710 [F] s_b_13_5=sym_47207_3_parameter_inst.rt (const) */
    /* execute.simd:3710 [D] s_b_13_6 = sym_158820_0_vl uint64_t */
    auto s_b_13_6 = emitter.load_local(DV_sym_158820_0_vl, emitter.context().types().u64());
    /* execute.simd:3710 [D] s_b_13_7 = sym_158824_0_vh uint64_t */
    auto s_b_13_7 = emitter.load_local(DV_sym_158824_0_vh, emitter.context().types().u64());
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
